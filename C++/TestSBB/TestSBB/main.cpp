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

#define SAFECREATIVE_CERT "../../tests/SafeCreative_TSA.cer"
#define SAFECREATIVE_URL "http://tsa.safecreative.org/"
#define FREETSA_CERT "../../tests/freetsa.crt"
#define FREETSA_CA_CERT "../../tests/freetsaca.pem"
#define FREETSA_URL "http://freetsa.org/tsr"
#define TIMECERTUM_URL "http://time.certum.pl"
#define TSA_SAFECREATIVE "1"
#define TSA_FREETSA "2"
#define TSA_TIMECERTUM "3"
#define CA_CERT "../../tests/cacert.crt"
#define INT_CERT "../../tests/cacertint.crt"
#define DEFAULT_CERT "../../tests/leovant@gmail.com.p12"
#define DEFAULT_CERT_PASS "12345"
#define PDF_FILE "../../tests/unsigned.pdf"

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
        CertValidator.set_CheckCRL(false);
        CertValidator.set_MandatoryCRLCheck(false);
        CertValidator.set_MandatoryOCSPCheck(false);
        CertValidator.set_MandatoryRevocationCheck(false);
        //CertValidator.set_OfflineMode(true); //LTV
        //CertValidator.set_OnAfterCertificateValidation(&PDF_OnAfterCertificateValidation, NULL);
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

void SB_CALLBACK PDF_OnAfterCertificateValidation(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TElX509CertificateHandle hCACertificate, TSBCertificateValidityRaw &Validity, TSBCertificateValidityReasonRaw &Reason, int8_t &DoContinue)
{
    try
    {
        TElX509Certificate certificate(hCertificate, false);
        TName subject, issuer;
        certificate.get_SubjectName(subject);
        certificate.get_IssuerName(issuer);
        std::cout << "TElX509CertificateValidator.OnAfterCertificateValidation: " << (char *)subject.CommonName << "[" << (char *)issuer.CommonName << "]" << std::endl;
    }
    catch (SBException E)
    {
        std::cout << "Unexpected error in TElX509CertificateValidator.OnAfterCertificateValidation event handler!" << std::endl;
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

void SB_CALLBACK HTTP_OnData(void * _ObjectData, TObjectHandle hSender, void * Buffer, int32_t Size)
{
    try
    {
        std::cout << "TElHTTPSClient.OnData: Received " << std::to_string(Size) << std::endl;

        for (int32_t i = 0; i != Size; i++)
        {
            //std::cout << std::hex << static_cast<unsigned char>(Buffer[i]) << ' ';
            printf("%c", ((char*) Buffer)[i]);
        }
        std::cout << std::endl;
    }
    catch (SBException E)
    {
        std::cout << "Unexpected error in TElHTTPSClient.OnData event handler!" << std::endl;
        std::cout << E.what() << std::endl;
        std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
    }
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
    std::string helpMessage = "TestSBB [params]\n" \
        "params:\n" \
        "-tsa <op> : 1 - SafeCreative; 2 - FreeTSA; 2 - TimeCertum\n" \
/*
        "-c <filename> <password> : certificate filename and password if needed;\n" \
        "-inv : invisible signature;\n" \
        "-tsa <url> : timestamp server;\n" \
        "-trustedcerts <filename> : trusted certificate storage;\n" \
        "-autorev : auto collect revocation info;\n" \
        "-ignoreerrors : ignore chain validation errors;\n" \
        "-ltv : enable LTV;\n" \
*/
        "-h : help;\n";

    std::string pdfFilename, certFilename, certPassword, tsaURL, tsaCertFile, tsaCACertFile, trustedCertsFilename;
    bool invisibleSignature = true;
    bool autoRev = true;
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

            if  (param == "-tsa")
            {
                if (++i < argc) 
                {
                    std::string opt;
                    opt.assign(argv[i]);
                    if (opt == TSA_SAFECREATIVE) 
                    {
                        tsaURL = SAFECREATIVE_URL;
                        tsaCertFile = SAFECREATIVE_CERT;
                    } 
                    else if (opt == TSA_FREETSA) 
                    {
                        tsaURL = FREETSA_URL;
                        tsaCertFile = FREETSA_CERT;
                        tsaCACertFile = FREETSA_CA_CERT;
                    }
                    else if (opt == TSA_TIMECERTUM)
                    {
                        tsaURL = TIMECERTUM_URL;
                    }
                    else 
                    {
                        std::cout << helpMessage << std::endl;
                        return 0;
                    }
                }
                else
                {
                    std::cout << helpMessage << std::endl;
                    return 0;
                }
            }
            else if (param == "-h")
            {
                std::cout << helpMessage << std::endl;
                return 0;
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
    pdfFilename = "/tmp/signed.pdf";
    //Copiando arquivo, para manter o original

    std::ifstream source(PDF_FILE, std::ios::binary);
    std::ofstream dest(pdfFilename, std::ios::binary);
    dest << source.rdbuf();

    source.close();
    dest.close();

    certFilename = DEFAULT_CERT;
    certPassword = DEFAULT_CERT_PASS;
    //pdfFilename = PDF_FILE;

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
            sig->set_Reason("Teste de assinatura");
            sig->set_ContactInfo("leovan.tavares@doc.space");
            sig->set_SignatureType(stDocument);

            std::time_t t;
            std::time(&t);
            sig->set_SigningTime(t);

            int k = cert.LoadFromFileAuto(certFilename, certPassword);
            if (k != 0)
            {
                std::cout << std::hex << "Failed to load certificate: 0x" << k << std::endl;
                return 1;
            }
            TElRelativeDistinguishedName* subject;
            subject = cert.get_SubjectRDN();
            std::string DNString;
            subject->SaveToDNString(DNString);
            sig->set_AuthorName(DNString);

            certStorage.Add(cert, true);
            //Certificado raiz
            TElX509Certificate CACert(NULL);
            TElX509Certificate CACertInt(NULL);
            CACert.LoadFromFileAuto(CA_CERT_ROOT, "");
            CACertInt.LoadFromFileAuto(CA_CERT_INT, "");
            certStorage.Add(CACert, false);
            trustedCertStorage.Add(CACert, false);
            //Certificado intermediario
            TElX509Certificate IntCert(NULL);
            IntCert.LoadFromFileAuto(INT_CERT, "");
            certStorage.Add(IntCert, false);

            handler.set_CertStorage(certStorage);
            handler.set_PAdESSignatureType(pastBasic);
            handler.set_CustomName("Adobe.PPKLite");
            handler.set_AutoCollectRevocationInfo(autoRev);
            handler.set_IgnoreChainValidationErrors(ignoreErrors);
            handler.set_OnCertValidatorPrepared(&PDF_OnCertValidatorPrepared, NULL);
            handler.set_OnCertValidatorFinished(&PDF_OnCertValidatorFinished, NULL);

            if (ltv)
            {
                std::cout << "Enabling LTV" << std::endl;
                handler.set_DeepValidation(true);
                handler.set_ForceCompleteChainValidation(true);
                handler.set_AutoCollectRevocationInfo(true);
                handler.set_IncludeRevocationInfoToAdbeAttribute(true);
            }

            if (tsaURL != "")
            {
                httpClient.set_SocketTimeout(600000);
                httpClient.set_OnError(&HTTP_OnError, NULL);
                httpClient.set_OnData(&HTTP_OnData, NULL);
                tspClient.set_HTTPClient(httpClient);
                tspClient.set_URL(tsaURL);
                tspClient.set_HashAlgorithm(SB_ALGORITHM_DGST_SHA1);
                tspClient.set_OnCertificateValidate(&TSP_OnCertificateValidate, NULL);
                tspClient.set_OnHTTPError(&TSP_OnHTTPError, NULL);

                if (tsaCertFile != "")
                {
                    TElX509Certificate tsaCert(NULL);
                    tsaCert.LoadFromFileAuto(tsaCertFile, "");
                    certStorage.Add(tsaCert, false);

                    if (tsaCACertFile == "")
                    {
                        trustedCertStorage.Add(tsaCert, false);
                    }
                }
                if (tsaCACertFile != "")
                {
                    TElX509Certificate tsaCACert(NULL);
                    tsaCACert.LoadFromFileAuto(tsaCACertFile, "");
                    certStorage.Add(tsaCACert, false);
                    trustedCertStorage.Add(tsaCACert, false);
                }
                pTrustedCertStorage = &trustedCertStorage;

                handler.set_TSPClient(tspClient);
                //handler.set_IgnoreTimestampFailure(true);
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