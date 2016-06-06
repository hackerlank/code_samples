#include <cstring>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <ctime>

#include "sbmisc.h"
#include "sbutils.h"
#include "sbpdf.h"
#include "sbpades.h"
#include "sbx509.h"
#include "sbcertvalidator.h"
#include "sbpdfsecurity.h"
#include "sbhttptspclient.h"
#include "sbhttpsclient.h"
#include "sbhttpcrl.h"
#include "sbhttpocspclient.h"
#include "sbhttpcertretriever.h"

using namespace SecureBlackbox;

std::string UnQuote(std::string s)
{
	if (s.length() < 1)
		return s;

	s.erase(remove(s.begin(), s.end(), '\"'), s.end());
	return s;
}

TElMemoryCertStorage *pTrustedCertStorage;

void SB_CALLBACK PDF_OnCertValidatorPrepared(void * /* _ObjectData */, TObjectHandle /* hSender */, TElX509CertificateValidatorHandle * hCertValidator, TElX509CertificateHandle /* hCert */)
{
	try
	{
		TElX509CertificateValidator CertValidator(*hCertValidator, false);
		CertValidator.AddTrustedCertificates(pTrustedCertStorage);
		CertValidator.set_ForceCompleteChainValidationForTrusted(true);
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in OnCertValidatorPrepared event handler" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

int main(int argc, char **argv)
{
	std::string helpMessage = "ConsolePAdES.exe [params]\n" \
		"params:\n" \
		"-f <filename> : path to .pdf file;\n" \
		"-c <filename> <password> : certificate filename and password if needed;\n" \
		"-inv : invisible signature;\n" \
		"-tsa <url> : timestamp server;\n" \
		"-trustedcerts <filename> : trusted certificate storage;\n" \
		"-autorev : auto collect revocation info;\n" \
		"-ignoreerrors : ignore chain validation errors;\n" \
		"-h : help;\n";

	std::string pdfFilename, certFilename, certPassword, tsaURL, trustedCertsFilename;
	bool invisibleSignature = false;
	bool autoRev = false;
	bool ignoreErrors = false;

	try
	{
		SetLicenseKey("61E05BF5CA4631B12F8BABFB92367BC36C7264BC67086ECB308682402A5676E924B812056C97BB8CE23A97E4F612E6B29B80702F60E903DEDB5DE0A60C901A2CB1FFBEDAA96C2779C3008A61884F410D9B838FA0452743604D4330B27F160030EE92FDD9EE04F292EE18CABB45757F3675972C6DCCFDA3EF3569873F85F3AFFFF91024957277FF458FF4D66CDBA64DDE6F81425D0767762393666DAABCE2FE7E5CBBF4FBBDBACEDDD77794BC14AAB728A9B82AC3F8342B6EA661F0F108397134D881E56863762ABDF344AD78029564B4F2BF1BF0295971767B12BE9057B99E3A25A04EF2AAD0019063EBBBC920A6F206F51BC20F0E2B72E3B0BD1919B8BC8BC3");
	}
	catch (SBException E)
	{
		std::cout << "Failed to set license key:" << std::endl;
		std::cout << E.what() << std::endl;
		return 0;
	}

	try
	{
		int i = 1;
		while (i < argc)
		{
			std::string param;
			param.assign(argv[i]);

			if (param == "-f")
			{
				if (++i < argc)
					pdfFilename = UnQuote(argv[i]);
			}
			else if (param == "-c")
			{
				if (++i < argc)
					certFilename = UnQuote(argv[i]);

				if ((i + 1 < argc) && (argv[i + 1][0] != '-'))
				{
					i++;
					certPassword = UnQuote(argv[i]);
				}
			}
			else if (param == "-tsa")
			{
				if (++i < argc)
					tsaURL = UnQuote(argv[i]);
			}
			else if (param == "-trustedcerts")
			{
				if (++i < argc)
					trustedCertsFilename = UnQuote(argv[i]);
			}
			else if (param == "-inv")
			{
				invisibleSignature = true;
			}
			else if (param == "-autorev")
			{
				autoRev = true;
			}
			else if (param == "-ignoreerrors")
			{
				ignoreErrors = true;
			}
			else if (param == "-h")
			{
				std::cout << helpMessage << std::endl;
			}

			i++;
		}
	}
	catch (...)
	{
		std::cout << "Failed to parse parameters" << std::endl;
		std::cout << helpMessage << std::endl;
		return 0;
	}

	if ((pdfFilename == "") || (certFilename == ""))
	{
		std::cout << helpMessage << std::endl;
		return 0;
	}

	try
	{
		RegisterHTTPCRLRetrieverFactory();
		RegisterHTTPOCSPClientFactory();
		RegisterHTTPCertificateRetrieverFactory();

		TElPDFDocument pdf(NULL);
		TElPDFAdvancedPublicKeySecurityHandler handler(NULL);
		TElMemoryCertStorage certStorage(NULL);
		TElMemoryCertStorage trustedCertStorage(NULL);
		TElX509Certificate cert(NULL);
		TElHTTPTSPClient tspClient(NULL);
		TElHTTPSClient httpClient(NULL);

		TFileStream pdfStream(pdfFilename, filemodeOpenReadWrite);
		pdf.Open(pdfStream);

		std::cout << "Filename:\t\t" << pdfFilename << std::endl;
		std::cout << "Pages:\t\t\t" << pdf.get_PageInfoCount() << std::endl;
		std::cout << "Attachments:\t\t" << pdf.get_AttachedFileCount() << std::endl;
		if (pdf.get_Signed())
			std::cout << "Signed:\t\t\tyes" << std::endl;
		else
			std::cout << "Signed:\t\t\tno" << std::endl;
		std::cout << "Empty signature fields:\t" << pdf.get_EmptySignatureFieldCount() << std::endl;

		try
		{
			int idx = pdf.AddSignature();
			TElPDFSignature* sig = pdf.get_Signatures(idx);
			sig->set_Handler(handler);
			sig->set_Invisible(invisibleSignature);

			int k = cert.LoadFromFileAuto(certFilename, certPassword);
			if (k != 0)
			{
				std::cout << std::hex << "Failed to load certificate: 0x" << k << std::endl;
				return 1;
			}

			certStorage.Add(cert, true);
			handler.set_CertStorage(certStorage);
			handler.set_PAdESSignatureType(pastEnhanced);
			handler.set_CustomName("Adobe.PPKMS");
			handler.set_AutoCollectRevocationInfo(autoRev);
			handler.set_IgnoreChainValidationErrors(ignoreErrors);
			std::time_t t;
			std::time(&t);
			sig->set_SigningTime(t);

			if (trustedCertsFilename != "")
			{
				TFileStream fs(trustedCertsFilename, filemodeOpenRead);
				trustedCertStorage.LoadFromStreamPFX(fs, "", 0);
				pTrustedCertStorage = &trustedCertStorage;
				handler.set_OnCertValidatorPrepared(&PDF_OnCertValidatorPrepared, NULL);
				std::cout << "Loaded trusted certificates from " << trustedCertsFilename << std::endl;
			}
			else
				pTrustedCertStorage = NULL;

			if (tsaURL != "")
			{
				httpClient.set_SocketTimeout(600000);
                tspClient.set_HTTPClient(httpClient);
				tspClient.set_URL(tsaURL);
				tspClient.set_HashAlgorithm(SB_ALGORITHM_DGST_SHA1);
				handler.set_TSPClient(tspClient);
				std::cout << "Timestamp server: " << tsaURL << std::endl;
			}

			std::cout << "Everything has been prepared for signing.\nSign and write changes to the document?: Y or N" << std::endl;
			std::string input;
			std::getline(std::cin, input);
			std::transform(input.begin(), input.end(), input.begin(), ::toupper);

			if (input == "Y")
			{
				pdf.Close(true);
				std::cout << "Signing succeeded" << std::endl;
			}
			else
			{
				pdf.Close(false);
				std::cout << "Signing cancelled" << std::endl;
			}
		}
		catch (SBException E)
		{
			std::cout << "Signing failed: " << E.what() << std::endl;
		}
	}
	catch (SBException E)
	{
		std::cout << "Error: " << E.what() << std::endl;
	}
}