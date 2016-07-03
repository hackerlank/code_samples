﻿#include <cstring>
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
#include "sbx509ext.h"
#include "sbcertvalidator.h"
#include "sbpdfsecurity.h"
#include "sbhttptspclient.h"
#include "sbhttpsclient.h"
#include "sbhttpcrl.h"
#include "sbhttpocspclient.h"
#include "sbhttpcertretriever.h"
#include "sbcrl.h"

#include "EventHandlers.h"

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
#define OCSP_1_CERT "../../tests/OCSP-1.crt"
#define OCSP_3_CERT "../../tests/OCSP-3.crt"
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

int main(int argc, char **argv)
{
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

    std::string helpMessage = "TestSBB [params]\n" \
        "params:\n" \
        "-tsa <op> : 1 - SafeCreative; 2 - FreeTSA; 2 - TimeCertum\n" \
        "-h : help;\n";

    std::string pdfFilename, certFilename, certPassword, tsaURL, tsaCertFile, tsaCACertFile, trustedCertsFilename;
    //bool ltv = false;

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

    try
    {
        //
        RegisterHTTPCRLRetrieverFactory();
        RegisterHTTPOCSPClientFactory();
        RegisterHTTPCertificateRetrieverFactory();

        //Carregando os certificados
        std::cout << "Carregando certificados..." << std::endl;
        //Repositório de certificados confiáveis
        TElMemoryCertStorage trustedCertificateStorage(NULL);
        //Repositório de certificados conhecidos
        TElMemoryCertStorage knownCertificateStorage(NULL);
        //Repositório de certificados para assinatura
        TElMemoryCertStorage signerCertificateStorage(NULL);
        TElX509Certificate rootCertificate_(NULL);
        TElX509Certificate signerCertificate_(NULL);
        try 
        {
            //Certificado raiz
            rootCertificate_.LoadFromFileAuto(CA_CERT, "");
            //Raiz é confiável e necessário para assinar
            trustedCertificateStorage.Add(rootCertificate_, false);
            signerCertificateStorage.Add(rootCertificate_, false);
            //Certificado intermediário
            TElX509Certificate intCertificate_(NULL);
            intCertificate_.LoadFromFileAuto(INT_CERT, "");
            knownCertificateStorage.Add(intCertificate_, false);
            signerCertificateStorage.Add(intCertificate_, false);
            //Certificados do ocsp
            TElX509Certificate ocsp1Certificate_(NULL);
            ocsp1Certificate_.LoadFromFileAuto(OCSP_1_CERT, "");
            knownCertificateStorage.Add(ocsp1Certificate_, false);

            TElX509Certificate ocsp3Certificate_(NULL);
            ocsp3Certificate_.LoadFromFileAuto(OCSP_3_CERT, "");
            knownCertificateStorage.Add(ocsp3Certificate_, false);
            //Certificado do assinante
            signerCertificate_.LoadFromFileAuto(DEFAULT_CERT, DEFAULT_CERT_PASS);
            signerCertificateStorage.Add(signerCertificate_, true);
            //Se usar TSA, adiciona os certificados dos servidores de tempo
            if (tsaURL != "")
            {
                if (tsaCertFile != "")
                {
                    TElX509Certificate tsaCert(NULL);
                    tsaCert.LoadFromFileAuto(tsaCertFile, "");
                    knownCertificateStorage.Add(tsaCert, false);

                    if (tsaCACertFile == "")
                    {
                        trustedCertificateStorage.Add(tsaCert, false);
                    }
                }
                if (tsaCACertFile != "")
                {
                    TElX509Certificate tsaCACert(NULL);
                    tsaCACert.LoadFromFileAuto(tsaCACertFile, "");
                    knownCertificateStorage.Add(tsaCACert, false);
                    trustedCertificateStorage.Add(tsaCACert, false);
                }
            }
        } 
        catch (SBException E)
        {
            std::cout << "Erro ao carregar certificados: " << E.what() << std::endl;
        }
        std::cout << "Certificados carregados." << std::endl;
        std::cout << "Validando..." << std::endl;
        //Validação do certificado
        try 
        {
            //Dados de revogação
            /*
            TElHTTPCRLRetriever httpRetriever(NULL);
            TElClassHandleValue * handle;
            handle = httpRetriever.GetCRL(signerCertificate_, rootCertificate_, TSBGeneralName::gnUniformResourceIdentifier, "http://crl.cacert.org/revoke.crl");
            TElCertificateRevocationList crl(handle, false);
            std::string issuerDN;
            crl.get_Issuer()->SaveToDNString(issuerDN);
            std::cout << "LCR recebida com tamanho " << crl.get_CRLSize() << " de " << issuerDN << std::endl;
            int32_t crl_validity = crl.Validate(rootCertificate_);
            std::cout << "Validade: " << crl_validity << std::endl;
            */

            //Validador
            TElX509CertificateValidator certValidator_(NULL);
            //Atribuindo os certificados confiáveis e conhecidos
            certValidator_.AddTrustedCertificates(&trustedCertificateStorage);
            certValidator_.AddKnownCertificates(&knownCertificateStorage);
            //Definindo event handlers
            certValidator_.set_OnBeforeCertificateValidation(&CertValidator_OnBeforeCertificateValidation, NULL);
            certValidator_.set_OnBeforeCertificateRetrieverUse(&CertValidator_OnBeforeCertificateRetrieverUse, NULL);
            certValidator_.set_OnCACertificateNeeded(&CertValidator_OnCACertificateNeeded, NULL);
            certValidator_.set_OnCACertificateRetrieved(&CertValidator_OnCACertificateRetrieved, NULL);
            certValidator_.set_OnCRLNeeded(&CertValidator_OnCRLNeeded, NULL);
            certValidator_.set_OnBeforeCRLRetrieverUse(&CertValidator_OnBeforeCRLRetrieverUse, NULL);
            certValidator_.set_OnCRLRetrieved(&CertValidator_OnCRLRetrieved, NULL);
            certValidator_.set_OnCRLError(&CertValidator_OnCRLError, NULL);
            certValidator_.set_OnAfterCRLUse(&CertValidator_OnAfterCRLUse, NULL);
            certValidator_.set_OnBeforeOCSPClientUse(&CertValidator_OnBeforeOCSPClientUse, NULL);
            certValidator_.set_OnOCSPResponseSignerValid(&CertValidator_OnOCSPResponseSignerValid, NULL);
            certValidator_.set_OnOCSPError(&CertValidator_OnOCSPError, NULL);
            certValidator_.set_OnAfterOCSPResponseUse(&CertValidator_OnAfterOCSPResponseUse, NULL);
            //Definindo opções do validador
            certValidator_.set_CheckCRL(true); // default = true
            certValidator_.set_CheckOCSP(true); // default = true
            certValidator_.set_CheckValidityPeriodForTrusted(true); // default = true
            certValidator_.set_ForceCompleteChainValidationForTrusted(true); // default = true
            certValidator_.set_ForceRevocationCheckForRoot(true); // default = true
            certValidator_.set_IgnoreBadOCSPChains(false); // default = false
            certValidator_.set_IgnoreCAKeyUsage(true); // default = true
            certValidator_.set_IgnoreRevocationKeyUsage(true); // default = true
            certValidator_.set_IgnoreSSLKeyUsage(false); // default = false
            //certValidator_.set_IgnoreSystemTrust(true); // default = true
            certValidator_.set_ImplicitlyTrustSelfSignedCertificates(false); // default = false
            certValidator_.set_MandatoryCRLCheck(true); // default = true
            certValidator_.set_MandatoryOCSPCheck(true); // default = true
            certValidator_.set_MandatoryRevocationCheck(true); // default = true
            certValidator_.set_OfflineMode(false); // default = false
            certValidator_.set_PromoteLongOCSPResponses(false); // default = false
            certValidator_.set_RevocationCheckPreference(rcpPreferOCSP); // rcpPreferCRL = 0, rcpPreferOCSP = 1, rcpCheckBoth = 2
            certValidator_.set_RevocationMomentGracePeriod(60); // default = 60s = 1min
            certValidator_.set_SkipSubjectNameIfAltNameExists(true); // default = true
            //certValidator_.set_UseSystemStorages(false); // default = true
            certValidator_.set_ValidateInvalidCertificates(true); // default = true
            //Validando
            TSBCertificateValidity validity;
            TSBCertificateValidityReason reason;
            certValidator_.Validate(signerCertificate_, validity, reason);
            std::cout << "Resultado da validação: " << std::endl;
            std::cout << "Validity: " << validity << std::endl;
            std::cout << "Reason: " << reason << std::endl;
        }
        catch (SBException E)
        {
            std::cout << "Erro ao validar certificado: " << E.what() << std::endl;
        }


        std::cout << "Assinando..." << std::endl;

        try
        {
            //Carregando documento
            TElPDFDocument pdf(NULL);
            TFileStream pdfStream(pdfFilename, filemodeOpenReadWrite);
            pdf.Open(pdfStream);

            std::cout << "Arquivo:\t\t" << pdfFilename << std::endl;
            std::cout << "Paginas:\t\t" << pdf.get_PageInfoCount() << std::endl;
            if (pdf.get_Signed())
                std::cout << "Assinado:\t\tsim" << std::endl;
            else
                std::cout << "Assinado:\t\tnão" << std::endl;
            //Configurando handler de assinatura
            TElPDFAdvancedPublicKeySecurityHandler signSecHandler(NULL);
            //Opções
            signSecHandler.set_CertStorage(signerCertificateStorage);
            signSecHandler.set_PAdESSignatureType(pastBasic); // PADES_BASIC = pastBasic / PADES_BES | PADES_EPES | PADES_LTV = pastEnhanced
            signSecHandler.set_CustomName("Adobe.PPKLite");
            //LTV
            signSecHandler.set_AutoCollectRevocationInfo(true);
            signSecHandler.set_DeepValidation(false);
            signSecHandler.set_ForceCompleteChainValidation(false);
            signSecHandler.set_IncludeRevocationInfoToAdbeAttribute(false);
            //Eventos
            signSecHandler.set_OnCertValidatorPrepared(&signSecHandler_OnCertValidatorPrepared, NULL);
            signSecHandler.set_OnBeforeSign(&signSecHandler_OnBeforeSign, NULL);
            signSecHandler.set_OnAfterSign(&signSecHandler_OnAfterSign, NULL);
            signSecHandler.set_OnRemoteSign(&signSecHandler_OnRemoteSign, NULL);
            signSecHandler.set_OnCertValidatorFinished(&signSecHandler_OnCertValidatorFinished, NULL);
            //TSA
            if (tsaURL != "")
            {
                //Configurando cliente HTTP
                TElHTTPSClient httpsClient(NULL);
                httpsClient.set_OnBeforeWebSocketClientUsed(&httpsClient_OnBeforeWebSocketClientUsed, NULL);
                httpsClient.set_OnCookie(&httpsClient_OnCookie, NULL);
                httpsClient.set_OnData(&httpsClient_OnData, NULL);
                httpsClient.set_OnDocumentBegin(&httpsClient_OnDocumentBegin, NULL);
                httpsClient.set_OnDocumentEnd(&httpsClient_OnDocumentEnd, NULL);
                httpsClient.set_OnDynamicDataNeeded(&httpsClient_OnDynamicDataNeeded, NULL);
                httpsClient.set_OnOAuth2Browse(&httpsClient_OnOAuth2Browse, NULL);
                httpsClient.set_OnPreparedHeaders(&httpsClient_OnPreparedHeaders, NULL);
                httpsClient.set_OnProgress(&httpsClient_OnProgress, NULL);
                httpsClient.set_OnReceivingHeaders(&httpsClient_OnReceivingHeaders, NULL);
                httpsClient.set_OnRedirection(&httpsClient_OnRedirection, NULL);
                httpsClient.set_OnSendData(&httpsClient_OnSendData, NULL);
                httpsClient.set_OnWebSocketConnectionEstablished(&httpsClient_OnWebSocketConnectionEstablished, NULL);
                //Configurando cliente TSP
                TElHTTPTSPClient tspClient(NULL);
                tspClient.set_OnTSPError(&tspClient_OnTSPError, NULL);
                tspClient.set_OnBeforeSign(&tspClient_OnBeforeSign, NULL);
                //tspClient.set_OnCertificateValidate(&tspClient_OnCertificateValidate, NULL);
                tspClient.set_HTTPClient(httpsClient);
                tspClient.set_URL(tsaURL);
                tspClient.set_HashAlgorithm(SB_ALGORITHM_DGST_SHA512);
                signSecHandler.set_TSPClient(tspClient);
            }
            //Configurando assinatura
            int idx = pdf.AddSignature();
            TElPDFSignature* sig = pdf.get_Signatures(idx);
            sig->set_Handler(signSecHandler);
            sig->set_Invisible(true);
            sig->set_Reason("Assinatura de documento");
            sig->set_ContactInfo("leovan.tavares@doc.space");
            sig->set_SignatureType(stDocument);
            sig->set_Location("Porto Alegre");

            std::time_t t;
            std::time(&t);
            sig->set_SigningTime(t);
            std::cout << "Tudo preparado para assinar..." << std::endl;
            pdf.Close(true);
            std::cout << "Acabou." << std::endl;
        }
        catch (SBException E)
        {
            std::cout << "Erro ao assinar: " << E.what() << std::endl;
        }
    }
    catch (SBException E)
    {
        std::cout << "Error: " << E.what() << std::endl;
    }
}