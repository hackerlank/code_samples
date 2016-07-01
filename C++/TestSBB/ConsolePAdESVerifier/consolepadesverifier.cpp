#include <cstring>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <ctime>
#include <time.h>

#include "sbsystem.h"
#include "sbcore.h"
#include "sbutils.h"
#include "sbmisc.h"
#include "sbpdf.h"
#include "sbpdfsecurity.h"
#include "sbpades.h"
#include "sbx509.h"
#include "sbcustomcertstorage.h"
#include "sbcrl.h"
#include "sbcrlstorage.h"
#include "sbtspcommon.h"
#include "sbhttpsclient.h"
#include "sbcertvalidator.h"
#include "sbhttptspclient.h"

using namespace SecureBlackbox;

TElPDFDocument pdf (NULL);
//TElMemoryCertStorage trustedCerts ();


std::string UnQuote(std::string s)
{
    if (s.length() < 1)
        return s;

	s.erase(remove( s.begin(), s.end(), '\"' ), s.end());

    return s;
}
/*
void PrepareValidation(TElPDFAdvancedPublicKeySecurityHandler handler)
{
    trustedCerts.Clear();
    for (int i = 0; i < lvRevInfo.Items.Count; i++)
    {
        if ((lvRevInfo.Items[i].Tag is TElX509Certificate) && (lvRevInfo.Items[i].Checked))
        {
            m_TrustedCerts.Add((TElX509Certificate)lvRevInfo.Items[i].Tag, false);
        }
        else if (lvRevInfo.Items[i].Tag is TElCertificateRevocationList)
        {
            m_KnownCRLs.Add((TElCertificateRevocationList)lvRevInfo.Items[i].Tag);
        }
    }
    handler.OnCertValidatorPrepared += new TSBPDFCertValidatorPreparedEvent(handler_OnCertValidatorPrepared);
}
*/

void Revalidate(TElPDFSignature* sig)
{
    try
    {
        sig->Validate();
    }
    catch (SBException E)
    {
		std::cout << "Validate error: " << E.what() << std::endl;
    }
}

void Update(TElPDFSignature* sig, std::string url)
{
    TElPDFSecurityHandler* handler = sig->get_Handler();
    if (handler->ClassNameIs_Inst("TElPDFAdvancedPublicKeySecurityHandler"))
    {
        TElPDFAdvancedPublicKeySecurityHandler PAdESHandler (handler->getHandle(), false);
		TSBPAdESSignatureType sigType = PAdESHandler.get_PAdESSignatureType();
		if ((sigType == pastEnhanced) || (sigType == pastDocumentTimestamp))
		{
            try
            {
				PAdESHandler.set_AutoCollectRevocationInfo(false);
				PAdESHandler.set_IgnoreChainValidationErrors(false);
                try
                {
                    sig->Update();
                }
                catch (SBException E)
                {
                    std::cout << "Signature updating failed" << std::endl;
                    return;
                }
                // adding document timestamp
                int idx = pdf.AddSignature();
                sig = pdf.get_Signatures(idx);
                TElPDFAdvancedPublicKeySecurityHandler m_Handler (NULL);
				m_Handler.set_PAdESSignatureType(pastDocumentTimestamp);
                sig->set_Handler(m_Handler);
				TElHTTPTSPClient m_TspClient (NULL);
				TElHTTPSClient m_HttpClient (NULL);

                m_TspClient.set_HTTPClient(m_HttpClient);
                m_TspClient.set_URL(url);
                m_Handler.set_TSPClient(m_TspClient);
                // saving the document
                sig->set_SigningTime(std::time(0));
                pdf.Close(true);
                std::cout << "Signature updating succeeded" << std::endl;
            }
            catch (SBException E)
            {
                std::cout << "Signature updating failed: " << E.what()  << std::endl;
            }
        }
    }

	std::cout << "The selected signature cannot be updated" << std::endl;
}

void ShowSignatures(std::string pdfFilename)
{
	TElPDFPublicKeyRevocationInfo revInfo;

	for (int i = 0; i < pdf.get_SignatureCount(); i++)
    {
        TElPDFSecurityHandler* handler = pdf.get_Signatures(i)->get_Handler();
        if (handler->ClassNameIs_Inst("TElPDFAdvancedPublicKeySecurityHandler"))
        {
            TElPDFAdvancedPublicKeySecurityHandler PAdESHandler (handler->getHandle(), false);
            PAdESHandler.get_CMS()->ExtractAllCertificates(revInfo.get_Certificates());
            for (int k = 0; k < PAdESHandler.get_CMS()->get_CRLs()->get_Count(); k++)
            {
                int idx = revInfo.AddCRL();
                revInfo.get_CRLs(idx)->Assign(PAdESHandler.get_CMS()->get_CRLs()->get_CRLs(k));
            }
            revInfo.Assign(PAdESHandler.get_DSSRevocationInfo(), false);
            revInfo.Assign(PAdESHandler.get_RevocationInfo(), false);
        }
    }

	std::cout << "Document properties:" << std::endl;

	std::cout << "Filename:\t\t" << pdfFilename << std::endl;
	std::cout << "Pages:\t\t\t" << pdf.get_PageInfoCount() << std::endl;
	std::cout << "Attachments:\t\t" << pdf.get_AttachedFileCount() << std::endl;
	if (pdf.get_Signed())
		std::cout << "Signed:\t\t\tyes" << std::endl;
	else
		std::cout << "Pages:\t\t\tno" << std::endl;
	std::cout << "Empty signature fields:\t" << pdf.get_EmptySignatureFieldCount() << std::endl;

	std::cout << "Signatures:" << std::endl;

	for (int i = 0; i < pdf.get_SignatureCount(); i++)
	{
		TElPDFSignature* sig = pdf.get_Signatures(i);

		TElPDFSecurityHandler* handler = sig->get_Handler();
        TElPDFAdvancedPublicKeySecurityHandler* PAdESHandler = NULL;
        if (handler->ClassNameIs_Inst("TElPDFAdvancedPublicKeySecurityHandler"))
        {
            PAdESHandler = new TElPDFAdvancedPublicKeySecurityHandler(handler->getHandle(), false);
		    TSBPAdESSignatureType sigType = PAdESHandler->get_PAdESSignatureType();
            std::cout << "Type: ";
			if (sigType == pastBasic)
                std::cout << "Basic";
            else if (sigType == pastEnhanced)
                std::cout << "Enhanced (long-term)";
            else if (sigType == pastDocumentTimestamp)
                std::cout << "Document timestamp";
            else
                std::cout << "Unknown";

            std::cout << std::endl;
        }
	    else if (handler->ClassNameIs_Inst("TElPDFPublicKeySecurityHandler"))
        {
            std::cout << "Type: Standard" << std::endl;
        }
        else
        {
            std::cout << "Type: Unknown" << std::endl;
        }

		std::string sigName;
		sig->get_SignatureName(sigName);
        std::cout << "Signature Name: " << sigName << std::endl;

		std::string authorName;
		sig->get_AuthorName(authorName);
		std::cout << "Author: " << authorName << std::endl;

        if (PAdESHandler != NULL)
        {
			std::string DNSName;
			std::vector<uint8_t> SerialNumber;
			PAdESHandler->get_CMS()->get_Signatures(0)->get_Signer()->get_SerialNumber(SerialNumber);
			PAdESHandler->get_CMS()->get_Signatures(0)->get_Signer()->get_Issuer()->SaveToDNString(DNSName);
			std::string sSerialNumber;
			BinaryToString(SerialNumber, sSerialNumber);

			std::cout << "Issuer: " << DNSName << ", S/N: " << sSerialNumber << std::endl;

            Revalidate(sig);
            if (PAdESHandler->get_TimestampCount() > 0)
            {
                time_t timer = (time_t)PAdESHandler->get_Timestamps(0)->get_Time();
                char* dt = ctime(&timer);
                std::cout << "Signing time: " << dt << std::endl;
                std::cout << "Timestamped: " << "Yes" << std::endl;
            }
            else
            {
			    time_t timer = (time_t)sig->get_SigningTime();
			    char* dt = ctime(&timer);
			    std::cout << "Signing time: " << dt << std::endl;
                std::cout << "Timestamped: " << "No" << std::endl;
            }

			std::string s;
			TSBCMSAdvancedSignatureValidity sigValidity = PAdESHandler->get_ValidationDetails();
			switch (sigValidity)
            {
                case casvValid : 
                    s = "Valid";
                    break;
                case casvSignatureCorrupted : 
                    s = "Signature corrupted";
                    break;
                case casvSignerNotFound: 
                    s = "Signer not found";
                    break;
                case casvIncompleteChain: 
                    s = "Incomplete chain";
                    break;
                case casvBadCountersignature: 
                    s = "Bad countersignature";
                    break;
                case casvBadTimestamp: 
                    s = "Bad timestamp";
                    break;
                case casvCertificateExpired: 
                    s = "Certificate expired";
                    break;
                case casvCertificateRevoked: 
                    s = "Certificate revoked";
                    break;
                case casvCertificateCorrupted: 
                    s = "Certificate corrupted";
                    break;
                case casvUntrustedCA: 
                    s = "Untrusted CA";
                    break;
                case casvRevInfoNotFound: 
                    s = "Revocation information not found";
                    break;
                case casvTimestampInfoNotFound:
                    s = "Timestamp information not found";
                    break;
                case casvFailure: 
                    s = "General failure";
                    break;
                case casvCertificateMalformed: 
                    s = "Certificate malformed";
                    break;
                case casvUnknown: 
                    s = "Unknown";
                    break;
                case casvChainValidationFailed:
                    s = "Chain validation failed";
                    break;
                default:
                    s = "";
                    break;
            }

            std::cout << s << std::endl;

            delete PAdESHandler;
        }
        else
        {
			time_t timer = (time_t)sig->get_SigningTime();
			char* dt = ctime(&timer);
			std::cout << "Signing time: " << dt << std::endl;
            std::cout << "Timestamped: " << "N/A" << std::endl;
            std::cout << "Validity: " << "N/A" << std::endl;
        }
	}

    std::cout << std::endl;
}

int main(int argc, char **argv)
{
	std::string helpMessage = "consolePAdESVerifier.exe [params]" \
		"params:" \
		"-f <filename> : path to .pdf file;" \
		"-url <url> : timestamping server (default : empty);" \
		"-mode <revalidate|update> <signatureIndex> : number of signature;" \
		"-h : help;";
	std::string pdfFilename, certFilename, certPassword;
	std::string url = "http://";
	bool revalidate = false;
	bool update = false;
	int revalidateIdx = 0, updateIdx = -1;

	try
	{
		SetLicenseKey("61E05BF5CA4631B12F8BABFB92367BC36C7264BC67086ECB308682402A5676E924B812056C97BB8CE23A97E4F612E6B29B80702F60E903DEDB5DE0A60C901A2CB1FFBEDAA96C2779C3008A61884F410D9B838FA0452743604D4330B27F160030EE92FDD9EE04F292EE18CABB45757F3675972C6DCCFDA3EF3569873F85F3AFFFF91024957277FF458FF4D66CDBA64DDE6F81425D0767762393666DAABCE2FE7E5CBBF4FBBDBACEDDD77794BC14AAB728A9B82AC3F8342B6EA661F0F108397134D881E56863762ABDF344AD78029564B4F2BF1BF0295971767B12BE9057B99E3A25A04EF2AAD0019063EBBBC920A6F206F51BC20F0E2B72E3B0BD1919B8BC8BC3");
	}
	catch (SBException E)
	{
		std::cout << "Failed to set license key: " << E.what() << std::endl;
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
			else if (param == "-url")
			{
				if (++i < argc)
					url = UnQuote(argv[i]);
			}
			else if (param == "-mode")
			{
				if (++i < argc)
				{
					std::string mode = UnQuote(argv[i]);
					if (mode == "revalidate")
					{
						if (++i < argc)
						{
							std::string value = UnQuote(argv[i]);
							revalidateIdx = atoi(value.c_str());
							revalidate = true;
						}
					} else if (mode == "-update")
					{
						if (++i < argc)
						{
							std::string value = UnQuote(argv[i]);
							updateIdx = atoi(value.c_str());
							update = true;
						}
					}
				}
			}
			else if (param == "-h")
			{
				std::cout << helpMessage << std::endl;
			}

			i++;
		}
	}
	catch (SBException E)
	{
		std::cout << "Parameters parsing error:" << E.what() << std::endl;
		std::cout << helpMessage << std::endl;
		return 0;
	}

	try
	{
		TElPDFPublicKeyRevocationInfo revInfo;
		TElPDFAdvancedPublicKeySecurityHandler handler (NULL);
		TElMemoryCertStorage certStorage (NULL);
		TElX509Certificate cert(NULL);

		TFileStream pdfStream (pdfFilename, filemodeOpenReadWrite);
		pdf.Open(pdfStream);

		ShowSignatures(pdfFilename);

		if (revalidate)
		{
			std::cout << "Revalidate" << std::endl;
			Revalidate(pdf.get_Signatures(revalidateIdx));
		}

		if (update)
		{
			std::cout << "Revalidate" << std::endl;
			Update(pdf.get_Signatures(updateIdx), url);
		}

		ShowSignatures(pdfFilename);

	}
	catch (SBException E)
	{
		std::cout << "Error: " << E.what() << std::endl;
	}
}