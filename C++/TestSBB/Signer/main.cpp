#include <cstring>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <ctime>

#include "sbcertvalidator.h"
#include "sbcustomcertstorage.h"
#include "sbhttpsclient.h"
#include "sbhttptspclient.h"
#include "sbmisc.h"
#include "sbpdf.h"
#include "sbpades.h"
#include "sbpdfsecurity.h"
#include "sbutils.h"
#include "sbx509.h"

/*
#include "sbhttpcrl.h"
#include "sbhttpocspclient.h"
#include "sbhttpcertretriever.h"
*/
#include "EventHandlers.h"

#define TSA_CERT "../../certs/freetsa-tsa.cer"
#define TSA_ROOT_CERT "../../certs/freetsa-root.cer"
#define TSA_URL "http://freetsa.org/tsr"
#define ROOT_CERT "../../certs/cacert-root.cer"
#define INT_CERT "../../certs/cacert-intermediate.cer"
#define SIGNER_CERT "../../certs/cacert-leovan.p12"
#define SIGNER_CERT_PASS "12345"
#define PDF_FILE "../../docs/escritura.pdf"

namespace docspace 
{
    using namespace SecureBlackbox;

    class CertificateValidator
    {
        private:
            //Class private attributes
            TElCustomCertStorage * knownCertStorage_;
            TElCustomCertStorage * trustedCertStorage_;
        public:
            //Constructors and destructor
            CertificateValidator() { }
            CertificateValidator(TElCustomCertStorage * trustedCertStorage)
            {
                trustedCertStorage_ = trustedCertStorage;
            }
            CertificateValidator(TElCustomCertStorage * trustedCertStorage, TElCustomCertStorage * knownCertStorage)
            {
                trustedCertStorage_ = trustedCertStorage;
                knownCertStorage_ = knownCertStorage;
            }
            ~CertificateValidator() { }
            //Class public methods
            /*
             * Getters / setters
             */
            TElCustomCertStorage &getKnownCertStorage()
            {
                return *knownCertStorage_;
            }
            void setKnownCertStorage(TElCustomCertStorage * knownCertStorage)
            {
                knownCertStorage_ = knownCertStorage;
            }
            TElCustomCertStorage &getTrustedCertStorage()
            {
                return *trustedCertStorage_;
            }
            void setTrustedCertStorage(TElCustomCertStorage * trustedCertStorage)
            {
                trustedCertStorage_ = trustedCertStorage;
            }
    };
}
using namespace SecureBlackbox;

void SB_CALLBACK signSecHandler_OnCertValidatorPrepared(void *objCert, TObjectHandle, TElX509CertificateValidatorHandle *hCertValidator, TElX509CertificateHandle hCertificate)
{
    try
    {
        TElX509Certificate eventCertificate(hCertificate, false);
        TName subject, issuer;
        eventCertificate.get_SubjectName(subject);
        eventCertificate.get_IssuerName(issuer);
        std::cout << "TElPDFAdvancedPublicKeySecurityHandler.OnCertValidatorPrepared: " << (char *)subject.CommonName << " [" << (char *)issuer.CommonName << "]" << std::endl;

        docspace::CertificateValidator * uCertValidator = (docspace::CertificateValidator *) objCert;

        TElX509CertificateValidator certValidator_(*hCertValidator, false);

        certValidator_.AddTrustedCertificates(uCertValidator->getTrustedCertStorage());
        certValidator_.AddKnownCertificates(uCertValidator->getKnownCertStorage());

        certValidator_.set_CheckCRL(false); // default = true
        certValidator_.set_CheckOCSP(true); // default = true
        certValidator_.set_CheckValidityPeriodForTrusted(true); // default = true
        certValidator_.set_ForceCompleteChainValidationForTrusted(true); // default = true
        certValidator_.set_ForceRevocationCheckForRoot(true); // default = true
        certValidator_.set_IgnoreBadOCSPChains(false); // default = false
        certValidator_.set_IgnoreCAKeyUsage(true); // default = true
        certValidator_.set_IgnoreRevocationKeyUsage(true); // default = true
        certValidator_.set_IgnoreSSLKeyUsage(false); // default = false
        //certValidator_->set_IgnoreSystemTrust(true); // default = true
        certValidator_.set_ImplicitlyTrustSelfSignedCertificates(false); // default = false
        certValidator_.set_MandatoryCRLCheck(true); // default = true
        certValidator_.set_MandatoryOCSPCheck(true); // default = true
        certValidator_.set_MandatoryRevocationCheck(true); // default = true
        certValidator_.set_OfflineMode(false); // default = false
        certValidator_.set_PromoteLongOCSPResponses(false); // default = false
        certValidator_.set_RevocationCheckPreference(rcpPreferOCSP); // rcpPreferCRL = 0, rcpPreferOCSP = 1, rcpCheckBoth = 2
        certValidator_.set_RevocationMomentGracePeriod(60); // default = 60s = 1min
        certValidator_.set_SkipSubjectNameIfAltNameExists(true); // default = true
        //certValidator_->set_UseSystemStorages(false); // default = true
        certValidator_.set_ValidateInvalidCertificates(true); // default = true
        /*
         * Sets validator event handlers
         */
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
    }
    catch (SBException E)
    {
        std::cout << "Unexpected error in TElPDFAdvancedPublicKeySecurityHandler.OnCertValidatorPrepared event handler!" << std::endl;
        std::cout << E.what() << std::endl;
        std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
    }
}

int main(int argc, char **argv)
{
    std::cout << "Doc.Space PDF Signer" << std::endl;

    // Sets SecureBlackbox license key
    try
    {
        SetLicenseKey("61E05BF5CA4631B12F8BABFB92367BC36C7264BC67086ECB308682402A5676E924B812056C97BB8CE23A97E4F612E6B29B80702F60E903DEDB5DE0A60C901A2CB1FFBEDAA96C2779C3008A61884F410D9B838FA0452743604D4330B27F160030EE92FDD9EE04F292EE18CABB45757F3675972C6DCCFDA3EF3569873F85F3AFFFF91024957277FF458FF4D66CDBA64DDE6F81425D0767762393666DAABCE2FE7E5CBBF4FBBDBACEDDD77794BC14AAB728A9B82AC3F8342B6EA661F0F108397134D881E56863762ABDF344AD78029564B4F2BF1BF0295971767B12BE9057B99E3A25A04EF2AAD0019063EBBBC920A6F206F51BC20F0E2B72E3B0BD1919B8BC8BC3");
    }
    catch (SBException E)
    {
        std::cout << "Failed to set license key: " << std::endl;
        std::cout << E.what() << std::endl;
        return 1;
    }

    try
    {
        /* 
         * Loading certificates
         */
        //Storages to known, signer and trusted certificates
        TElMemoryCertStorage knownCertificateStorage(NULL);
        TElMemoryCertStorage signerCertificateStorage(NULL);
        TElMemoryCertStorage trustedCertificateStorage(NULL);
        //Signer certificates
        //Root certificate
        TElX509Certificate rootCertificate(NULL);
        rootCertificate.LoadFromFileAuto(ROOT_CERT, "");
        //Root is trusted
        trustedCertificateStorage.Add(rootCertificate, false);
        signerCertificateStorage.Add(rootCertificate, false);
        //Intermediate certificate
        TElX509Certificate intCertificate(NULL);
        intCertificate.LoadFromFileAuto(INT_CERT, "");
        //Intermediate is known
        knownCertificateStorage.Add(intCertificate, false);
        //Signer certificate
        TElX509Certificate signerCertificate(NULL);
        signerCertificate.LoadFromFileAuto(SIGNER_CERT, SIGNER_CERT_PASS);
        signerCertificateStorage.Add(signerCertificate, true);
        //TSA certificates
        //Root
        TElX509Certificate tsaRootCertificate(NULL);
        tsaRootCertificate.LoadFromFileAuto(TSA_ROOT_CERT, "");
        //Root is trusted
        trustedCertificateStorage.Add(tsaRootCertificate, false);
        //Server
        TElX509Certificate tsaCertificate(NULL);
        tsaCertificate.LoadFromFileAuto(TSA_CERT, "");
        knownCertificateStorage.Add(tsaCertificate, false);
        /*
         * Our validator
         */
        docspace::CertificateValidator cert(&trustedCertificateStorage, &knownCertificateStorage);
        /*
         * TSA settings
         */
        TElHTTPSClient httpsClient(NULL);
        TElHTTPTSPClient tspClient(NULL);
        tspClient.set_OnTSPError(&tspClient_OnTSPError, NULL);
        tspClient.set_HTTPClient(httpsClient);
        tspClient.set_URL(TSA_URL);
        tspClient.set_HashAlgorithm(SB_ALGORITHM_DGST_SHA256);
        /*
         * Signature handler settings
         */
        TElPDFAdvancedPublicKeySecurityHandler signSecHandler(NULL);
        signSecHandler.set_CertStorage(signerCertificateStorage);
        signSecHandler.set_PAdESSignatureType(pastBasic); // PADES_BASIC = pastBasic / PADES_BES | PADES_EPES | PADES_LTV = pastEnhanced
        signSecHandler.set_OnCertValidatorPrepared(&signSecHandler_OnCertValidatorPrepared, &cert);
        signSecHandler.set_TSPClient(tspClient);
        signSecHandler.set_CustomName("Adobe.PPKLite");
        //LTV
        signSecHandler.set_AutoCollectRevocationInfo(true);
        signSecHandler.set_DeepValidation(false);
        signSecHandler.set_ForceCompleteChainValidation(false);
        signSecHandler.set_IncludeRevocationInfoToAdbeAttribute(false);
        /*
         * Copy and loads document
         */
        std::string pdfFilename = "/tmp/signed.pdf";
        std::ifstream source(PDF_FILE, std::ios::binary);
        std::ofstream dest(pdfFilename, std::ios::binary);
        dest << source.rdbuf();

        source.close();
        dest.close();

        TFileStream inputStream(pdfFilename, filemodeOpenReadWrite);
        TElPDFDocument pdf(NULL);
        pdf.Open(inputStream);

        //Adds new signature
        int signIndex = pdf.AddSignature();
        TElPDFSignature *sign = pdf.get_Signatures(signIndex);
        sign->set_Handler(signSecHandler);
        sign->set_Invisible(true);
        sign->set_Reason("Assinatura de documento");
        sign->set_SignatureType(stDocument);
        time_t t;
        time(&t);
        sign->set_SigningTime(t);
        //Saves PDF (this call triggers the signature process)
        pdf.Close(true);
        std::cout << "Done! :-)" << std::endl;
    }
    catch (SBException E)
    {
        std::cout << "Error: " << E.what() << std::endl;
    }
    return 0;
}
