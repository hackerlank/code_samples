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

#define TSA_CERT "/tmp/SafeCreative_TSA.cer"
#define CA_CERT_ROOT "/tmp/CACert-root.crt"
#define CA_CERT_INT "/tmp/CACert-int.crt"

using namespace SecureBlackbox;

std::string UnQuote(std::string s)
{
    if (s.length() < 1)
        return s;

    s.erase(remove(s.begin(), s.end(), '\"'), s.end());
    return s;
}

TElMemoryCertStorage *pTrustedCertStorage;

void SB_CALLBACK PDF_OnCertValidatorPrepared(void * /* _ObjectData */, TObjectHandle /* hSender */, TElX509CertificateValidatorHandle * hCertValidator, TElX509CertificateHandle hCert)
{
    std::cout << "Trying to set validator's properties." << std::endl;
    try
    {
        TElX509CertificateValidator CertValidator(*hCertValidator, false);
        CertValidator.AddTrustedCertificates(pTrustedCertStorage);
        CertValidator.set_MandatoryCRLCheck(false);
        CertValidator.set_MandatoryOCSPCheck(false);
        CertValidator.set_MandatoryRevocationCheck(false);
        std::cout << "Validator prepared." << std::endl;
        TElX509Certificate Cert(hCert, false);
        std::string SubjectName;
        Cert.get_SubjectRDN()->SaveToDNString(SubjectName);
        std::cout << "Ready to validate: " << SubjectName << std::endl;
    }
    catch (SBException E)
    {
        std::cout << "Unexpected error in OnCertValidatorPrepared event handler" << std::endl;
        std::cout << E.what() << std::endl;
        std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
    }
}

void SB_CALLBACK PDF_OnCertValidatorFinished(void * _ObjectData, TObjectHandle Sender, TElX509CertificateValidatorHandle CertValidator, TElX509CertificateHandle Cert, TSBCertificateValidityRaw Validity, TSBCertificateValidityReasonRaw Reason)
{
    std::cout << "Certificate validity: " << Validity << std::endl;
    std::cout << "Reason: " << Reason << std::endl;
}

void SB_CALLBACK TSP_OnCertificateValidate(void * /* _ObjectData */, TObjectHandle /* Sender */, TElX509CertificateHandle /*Certificate*/, TElCustomCertStorageHandle /* AdditionalCertificates */, TSBCertificateValidityRaw * Validity, TSBCertificateValidityReasonRaw * Reason, int8_t * DoContinue)
{
    std::cout << "TSA certificate validity: " << Validity << std::endl;
    std::cout << "Reason: " << Reason << std::endl;
}

void SB_CALLBACK HTTP_OnError(void * _ObjectData, TObjectHandle Sender, int32_t ErrorCode, int8_t Fatal, int8_t Remote)
{
    std::cout << "HTTP Error: " << ErrorCode << std::endl;
}

void SB_CALLBACK TSP_OnHTTPError(void * _ObjectData, TObjectHandle Sender, int32_t ResponseCode)
{
    std::cout << "HTTP Error: " << ResponseCode << std::endl;
}

void SB_CALLBACK TSP_OnTSPError(void * _ObjectData, TObjectHandle hSender, int32_t ResponseCode)
{
    std::cout << "TSP Error: " << ResponseCode << std::endl;
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
        "-ltv : enable LTV;\n" \
        "-h : help;\n";

    std::string pdfFilename, certFilename, certPassword, tsaURL, trustedCertsFilename;
    bool invisibleSignature = false;
    bool autoRev = false;
    bool ignoreErrors = false;
    bool ltv = false;

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
            else if (param == "-ltv")
            {
                ltv = true;
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
        TElX509Certificate trustedCert(NULL);
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

            TElX509Certificate CACert(NULL);
            TElX509Certificate CACertInt(NULL);
            CACert.LoadFromFileAuto(CA_CERT_ROOT, "");
            CACertInt.LoadFromFileAuto(CA_CERT_INT, "");
            certStorage.Add(CACert, false);
            certStorage.Add(CACertInt, false);

            handler.set_CertStorage(certStorage);
            handler.set_PAdESSignatureType(pastEnhanced);
            handler.set_CustomName("Adobe.PPKMS");
            handler.set_AutoCollectRevocationInfo(autoRev);
            handler.set_IgnoreChainValidationErrors(ignoreErrors);
            handler.set_OnCertValidatorPrepared(&PDF_OnCertValidatorPrepared, NULL);
            handler.set_OnCertValidatorFinished(&PDF_OnCertValidatorFinished, NULL);

            if (ltv)
            {
                handler.set_DeepValidation(true);
                handler.set_ForceCompleteChainValidation(true);
                handler.set_AutoCollectRevocationInfo(true);
            }

            if (trustedCertsFilename != "")
            {
                trustedCert.LoadFromFileAuto(trustedCertsFilename, "");
                trustedCertStorage.Add(trustedCert, false);
                //TFileStream fs(trustedCertsFilename, filemodeOpenRead);
                //trustedCertStorage.LoadFromStreamPFX(fs, "", 0);
                pTrustedCertStorage = &trustedCertStorage;
                std::cout << "Loaded trusted certificates from " << trustedCertsFilename << std::endl;
            }
            else
                pTrustedCertStorage = &certStorage;

            if (tsaURL != "")
            {
                httpClient.set_SocketTimeout(600000);
                httpClient.set_OnError(&HTTP_OnError, NULL);
                tspClient.set_HTTPClient(httpClient);
                tspClient.set_URL(tsaURL);
                tspClient.set_HashAlgorithm(SB_ALGORITHM_DGST_SHA512);
                tspClient.set_OnCertificateValidate(&TSP_OnCertificateValidate, NULL);
                tspClient.set_OnHTTPError(&TSP_OnHTTPError, NULL);
                tspClient.set_OnTSPError(&TSP_OnTSPError, NULL);
                TElX509Certificate tsaCert(NULL);
                tsaCert.LoadFromFileAuto(TSA_CERT, "");
                certStorage.Add(tsaCert, false);
                handler.set_TSPClient(tspClient);
                //handler.set_IgnoreTimestampFailure(true);
                std::cout << "Timestamp server: " << tsaURL << std::endl;

            }
            else
            {
                std::time_t t;
                std::time(&t);
                sig->set_SigningTime(t);
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