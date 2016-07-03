#include <iostream>
#include <cstring>
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
#include "sbpkcs11base.h"
#include "sbpkcs11certstorage.h"
#include "sbpkcs11common.h"

#define SAFECREATIVE_CERT "../../tests/SafeCreative_TSA.cer"
#define FREETSA_CERT "../../tests/freetsa.crt"
#define FREETSA_CA_CERT "../../tests/freetsaca.pem"
#define CA_CERT "../../tests/cacert.crt"
#define INT_CERT "../../tests/cacertint.crt"
#define OCSP_1_CERT "../../tests/OCSP-1.crt"
#define OCSP_3_CERT "../../tests/OCSP-3.crt"

using namespace SecureBlackbox;

#include "EventHandlers.h"

void SB_CALLBACK httpsClient_OnBeforeWebSocketClientUsed(void * _ObjectData, TObjectHandle hSender, TElWebSocketClientHandle hWSClient, TElHTTPSClientHandle hHTTPClient)
{
	try
	{
		std::cout << "TElHTTPSClient.OnBeforeWebSocketClientUsed: " << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElHTTPSClient.OnBeforeWebSocketClientUsed event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK httpsClient_OnWebSocketConnectionEstablished(void * _ObjectData, TObjectHandle hSender, TElWebSocketClientHandle hWSClient)
{
	try
	{
		std::cout << "TElHTTPSClient.OnWebSocketConnectionEstablished: " << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElHTTPSClient.OnWebSocketConnectionEstablished event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK httpsClient_OnPreparedHeaders(void * _ObjectData, TObjectHandle hSender, TStringListHandle hHeaders)
{
	try
	{
		std::cout << "TElHTTPSClient.OnPreparedHeaders: " << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElHTTPSClient.OnPreparedHeaders event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK httpsClient_OnReceivingHeaders(void * _ObjectData, TObjectHandle hSender, TStringListHandle hHeaders)
{
	try
	{
		std::cout << "TElHTTPSClient.OnReceivingHeaders: " << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElHTTPSClient.OnReceivingHeaders event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK httpsClient_OnDynamicDataNeeded(void * _ObjectData, TObjectHandle hSender, const uint8_t pBuffer[], int32_t szBuffer, int32_t ToRead, int32_t * Read)
{
	try
	{
		std::cout << "TElHTTPSClient.OnDynamicDataNeeded: " << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElHTTPSClient.OnDynamicDataNeeded event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK httpsClient_OnData(void * _ObjectData, TObjectHandle hSender, void * Buffer, int32_t Size)
{
	try
	{
		std::cout << "TElHTTPSClient.OnData: Received " << std::to_string(Size) << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElHTTPSClient.OnData event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK httpsClient_OnProgress(void * _ObjectData, TObjectHandle hSender, int64_t Total, int64_t Current, int8_t * Cancel)
{
	try
	{
		std::cout << "TElHTTPSClient.OnProgress: " << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElHTTPSClient.OnProgress event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK httpsClient_OnDocumentBegin(void * _ObjectData, TObjectHandle hSender)
{
	try
	{
		std::cout << "TElHTTPSClient.OnDocumentBegin: " << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElHTTPSClient.OnDocumentBegin event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK httpsClient_OnDocumentEnd(void * _ObjectData, TObjectHandle hSender)
{
	try
	{
		std::cout << "TElHTTPSClient.OnDocumentEnd: " << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElHTTPSClient.OnDocumentEnd event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK httpsClient_OnOAuth2Browse(void * _ObjectData, TObjectHandle hSender, const char *pcURL, int32_t szURL, TStringListHandle hResponseHeaders)
{
	try
	{
		std::cout << "TElHTTPSClient.OnOAuth2Browse: " << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElHTTPSClient.OnOAuth2Browse event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK httpsClient_OnCookie(void * _ObjectData, TObjectHandle hSender, const char *pcCookieText, int32_t szCookieText)
{
	try
	{
		std::cout << "TElHTTPSClient.OnCookie: " << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElHTTPSClient.OnCookie event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK httpsClient_OnSendData(void * _ObjectData, TObjectHandle hSender, void * Buffer, int32_t Size)
{
	try
	{
		std::cout << "TElHTTPSClient.OnSendData: " << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElHTTPSClient.OnSendData event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK httpsClient_OnRedirection(void * _ObjectData, TObjectHandle hSender, const char *pcOldURL, int32_t szOldURL, char *pcNewURL, int32_t * szNewURL, int8_t * AllowRedirection)
{
	try
	{
		std::cout << "TElHTTPSClient.OnRedirection: " << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElHTTPSClient.OnRedirection event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK signSecHandler_OnBeforeSign(void * _ObjectData, TObjectHandle hSender, TElSignedCMSMessageHandle hCMS)
{
	try
	{
		TElSignedCMSMessage CMS(hCMS, false);
		std::cout << "TElPDFAdvancedPublicKeySecurityHandler.OnBeforeSign" << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElPDFAdvancedPublicKeySecurityHandler.OnBeforeSign event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK signSecHandler_OnAfterSign(void * _ObjectData, TObjectHandle hSender, TElSignedCMSMessageHandle hCMS)
{
	try
	{
		TElSignedCMSMessage CMS(hCMS, false);
		std::cout << "TElPDFAdvancedPublicKeySecurityHandler.OnBeforeSign" << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElPDFAdvancedPublicKeySecurityHandler.OnBeforeSign event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK signSecHandler_OnRemoteSign(void * _ObjectData, TObjectHandle hSender, const uint8_t pHash[], int32_t szHash, uint8_t pSignedHash[], int32_t * szSignedHash)
{
	try
	{
		std::cout << "TElPDFAdvancedPublicKeySecurityHandler.OnBeforeSign" << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElPDFAdvancedPublicKeySecurityHandler.OnBeforeSign event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK signSecHandler_OnCertValidatorPrepared(void *, TObjectHandle, TElX509CertificateValidatorHandle * hCertValidator, TElX509CertificateHandle hCertificate)
{
	try
	{
		//Repositório de certificados confiáveis
        TElMemoryCertStorage trustedCertificateStorage(NULL);
        //Repositório de certificados conhecidos
        TElMemoryCertStorage knownCertificateStorage(NULL);
        //Certificado raiz
        TElX509Certificate rootCertificate_(NULL);
        rootCertificate_.LoadFromFileAuto(CA_CERT, "");
        trustedCertificateStorage.Add(rootCertificate_, false);
        //Certificado intermediário
        TElX509Certificate intCertificate_(NULL);
        intCertificate_.LoadFromFileAuto(INT_CERT, "");
        knownCertificateStorage.Add(intCertificate_, false);
        //Certificados do ocsp
        TElX509Certificate ocsp1Certificate_(NULL);
        ocsp1Certificate_.LoadFromFileAuto(OCSP_1_CERT, "");
        knownCertificateStorage.Add(ocsp1Certificate_, false);

        TElX509Certificate ocsp3Certificate_(NULL);
        ocsp3Certificate_.LoadFromFileAuto(OCSP_3_CERT, "");
        knownCertificateStorage.Add(ocsp3Certificate_, false);
        //trustedCertificateStorage.Add(intCertificate_, false);
        //Certificado raiz do freetsa.org
        TElX509Certificate freeTSACACertificate_(NULL);
        freeTSACACertificate_.LoadFromFileAuto(FREETSA_CA_CERT, "");
        trustedCertificateStorage.Add(freeTSACACertificate_, false);
        //Certificado intermediário do freetsa.org
        TElX509Certificate freeTSAIntCertificate_(NULL);
        freeTSAIntCertificate_.LoadFromFileAuto(FREETSA_CERT, "");
        knownCertificateStorage.Add(freeTSAIntCertificate_, false);
        
        TElX509Certificate Certificate(hCertificate, false);
		TName subject, issuer;
		Certificate.get_SubjectName(subject);
		Certificate.get_IssuerName(issuer);
		std::cout << "TElPDFAdvancedPublicKeySecurityHandler.OnCertValidatorPrepared: " << (char *)subject.CommonName << " [" << (char *)issuer.CommonName << "]" << std::endl;

        TElX509CertificateValidator certValidator_(* hCertValidator, false);
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
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElPDFAdvancedPublicKeySecurityHandler.OnCertValidatorPrepared event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK signSecHandler_OnCertValidatorFinished(void * _ObjectData, TObjectHandle hSender, TElX509CertificateValidatorHandle hCertValidator, TElX509CertificateHandle hCertificate, TSBCertificateValidityRaw Validity, TSBCertificateValidityReasonRaw Reason)
{
	try
	{
		TElX509Certificate Certificate(hCertificate, false);
		TName subject, issuer;
		std::string validState, reasonList;
		Certificate.get_SubjectName(subject);
		Certificate.get_IssuerName(issuer);
		switch (Validity)
		{
		case cvOk:
			validState = "ok";
		case cvSelfSigned:
			validState = "self signed";
		case cvInvalid:
			validState = "invalid";
		case cvStorageError:
			validState = "storage error";
		case cvChainUnvalidated:
			validState = "chain unvalidated";
		}
		if (Reason & f_vrBadData) reasonList += "+BadData";
		if (Reason & f_vrRevoked) reasonList += "+Revoked";
		if (Reason & f_vrNotYetValid) reasonList += "+NotYetValid";
		if (Reason & f_vrExpired) reasonList += "+Expired";
		if (Reason & f_vrInvalidSignature) reasonList += "+InvalidSignature";
		if (Reason & f_vrUnknownCA) reasonList += "+UnknownCA";
		if (Reason & f_vrCAUnauthorized) reasonList += "+CAUnauthorized";
		if (Reason & f_vrCRLNotVerified) reasonList += "+CRLNotVerified";
		if (Reason & f_vrOCSPNotVerified) reasonList += "+OCSPNotVerified";
		if (Reason & f_vrIdentityMismatch) reasonList += "+IdentityMismatch";
		if (Reason & f_vrNoKeyUsage) reasonList += "+NoKeyUsage";
		if (Reason & f_vrBlocked) reasonList += "+Blocked";
		std::cout << "TElPDFAdvancedPublicKeySecurityHandler.OnCertValidatorFinished: " << (char *)subject.CommonName << " [" << (char *)issuer.CommonName << ", validity: " << validState << ", reason: " << reasonList << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElPDFAdvancedPublicKeySecurityHandler.OnCertValidatorFinished event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK tspClient_OnBeforeSign(void * _ObjectData, TObjectHandle hSender, TObjectHandle hSigner)
{
	try
	{
		TObject signer(hSigner, false);
		std::cout << "TElCustomTSPClient.OnBeforeSign: signer component " << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElCustomTSPClient.OnBeforeSign event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK tspClient_OnTSPError(void * _ObjectData, TObjectHandle hSender, int32_t ResponseCode)
{
	try
	{
		std::cout << "TElCustomTSPClient.OnHTTPError: error code " << std::to_string(ResponseCode) << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElCustomTSPClient.OnHTTPError event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK CertValidator_OnBeforeCertificateValidation(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate)
{
	try
	{
		TElX509Certificate Certificate(hCertificate, false);
		TName subject, issuer;
		Certificate.get_SubjectName(subject);
		Certificate.get_IssuerName(issuer);
        std::vector<uint8_t> SerialNumber;
        Certificate.get_SerialNumber(SerialNumber);
		std::cout << "TElX509CertificateValidator.OnBeforeCertificateValidation: " << (char *)subject.CommonName << " [" << (char *)issuer.CommonName << "]" << std::endl;
        std::string SubjectDN, IssuerDN;
        Certificate.get_SubjectRDN()->SaveToDNString(SubjectDN);
        Certificate.get_IssuerRDN()->SaveToDNString(IssuerDN);
        std::cout << "Subject: " << SubjectDN << std::endl;
        std::cout << "Issuer: " << IssuerDN << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElX509CertificateValidator.OnBeforeCertificateValidation event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK CertValidator_OnBeforeCertificateRetrieverUse(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TSBGeneralNameRaw NameType, const char *pcLocation, int32_t szLocation, TElCustomCertificateRetrieverHandle * hRetriever)
{
	try
	{
		TElX509Certificate Certificate(hCertificate, false);
		TName subject, issuer;
		Certificate.get_SubjectName(subject);
		Certificate.get_IssuerName(issuer);
		std::cout << "TElX509CertificateValidator.OnBeforeCertificateRetrieverUse: " << (char *)subject.CommonName << " [" << (char *)issuer.CommonName << "]" << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElX509CertificateValidator.OnBeforeCertificateRetrieverUse event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK CertValidator_OnCACertificateNeeded(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TElX509CertificateHandle * hCACertificate)
{
	try
	{
		TElX509Certificate Certificate(hCertificate, false);
		TName subject, issuer;
		Certificate.get_SubjectName(subject);
		Certificate.get_IssuerName(issuer);
		std::cout << "TElX509CertificateValidator.OnCACertificateNeeded: " << (char *)subject.CommonName << " [" << (char *)issuer.CommonName << "]" << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElX509CertificateValidator.OnCACertificateNeeded event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

//Not available in C++
//void SB_CALLBACK CertValidator_OnCACertificateNotFound(...)

void SB_CALLBACK CertValidator_OnCACertificateRetrieved(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TSBGeneralNameRaw NameType, const char *pcLocation, int32_t szLocation, TElX509CertificateHandle hCACertificate)
{
	try
	{
		TElX509Certificate Certificate(hCertificate, false);
		TName subject, issuer;
		Certificate.get_SubjectName(subject);
		Certificate.get_IssuerName(issuer);
		std::cout << "TElX509CertificateValidator.OnCACertificateRetrieved: " << (char *)subject.CommonName << " [" << (char *)issuer.CommonName << "]" << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElX509CertificateValidator.OnCACertificateRetrieved event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK CertValidator_OnCRLNeeded(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TElX509CertificateHandle hCACertificate, TElCustomCRLStorageHandle * hCRLs)
{
	try
	{
		TElX509Certificate Certificate(hCertificate, false);
		TName subject, issuer;
		Certificate.get_SubjectName(subject);
		Certificate.get_IssuerName(issuer);
		std::cout << "TElX509CertificateValidator.OnCRLNeeded: " << (char *)subject.CommonName << " [" << (char *)issuer.CommonName << "]" << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElX509CertificateValidator.OnCRLNeeded event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK CertValidator_OnBeforeCRLRetrieverUse(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TElX509CertificateHandle hCACertificate, TSBGeneralNameRaw NameType, const char *pcLocation, int32_t szLocation, TElCustomCRLRetrieverHandle * hRetriever)
{
	try
	{
		TElX509Certificate Certificate(hCertificate, false);
		TName subject, issuer;
		Certificate.get_SubjectName(subject);
		Certificate.get_IssuerName(issuer);
		std::cout << "TElX509CertificateValidator.OnBeforeCRLRetrieverUse: " << (char *)subject.CommonName << " [" << (char *)issuer.CommonName << "]" << std::endl;
		std::cout << "CRL: " << pcLocation << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElX509CertificateValidator.OnBeforeCRLRetrieverUse event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK CertValidator_OnCRLRetrieved(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TElX509CertificateHandle hCACertificate, TSBGeneralNameRaw NameType, const char *pcLocation, int32_t szLocation, TElCertificateRevocationListHandle hCRL)
{
	try
	{
		TElX509Certificate Certificate(hCertificate, false);
		TName subject, issuer;
		Certificate.get_SubjectName(subject);
		Certificate.get_IssuerName(issuer);
		std::cout << "TElX509CertificateValidator.OnCRLRetrieved: " << (char *)subject.CommonName << " [" << (char *)issuer.CommonName << "]" << std::endl;
        std::cout << "CRL: " << pcLocation << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElX509CertificateValidator.OnCRLRetrieved event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK CertValidator_OnCRLError(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, const char *pcLocation, int32_t szLocation, TElCustomCRLRetrieverHandle hRetriever, int32_t ErrorCode)
{
	try
	{
		TElX509Certificate Certificate(hCertificate, false);
		TName subject, issuer;
		Certificate.get_SubjectName(subject);
		Certificate.get_IssuerName(issuer);
        std::cout << "TElX509CertificateValidator.OnCRLError: " << (char *)subject.CommonName << " [" << (char *)issuer.CommonName << "]" << std::endl;
        std::cout << "Error: " << ErrorCode << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElX509CertificateValidator.OnCRLError event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK CertValidator_OnAfterCRLUse(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TElX509CertificateHandle hCACertificate, TElCertificateRevocationListHandle hCRL)
{
	try
	{
		TElX509Certificate Certificate(hCertificate, false);
		TName subject, issuer;
		Certificate.get_SubjectName(subject);
		Certificate.get_IssuerName(issuer);
		std::cout << "TElX509CertificateValidator.OnAfterCRLUse: " << (char *)subject.CommonName << " [" << (char *)issuer.CommonName << "]" << std::endl;
		TElCertificateRevocationList CRL(hCRL, false);
		std::string CRLLocation;
		CRL.get_Location(CRLLocation);
		std::cout << "CRL: " << CRLLocation << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElX509CertificateValidator.OnAfterCRLUse event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK CertValidator_OnBeforeOCSPClientUse(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TElX509CertificateHandle hCACertificate, const char *pcOCSPLocation, int32_t szOCSPLocation, TElOCSPClientHandle * hOCSPClient)
{
	try
	{
		TElX509Certificate Certificate(hCertificate, false);
		TName subject, issuer;
		Certificate.get_SubjectName(subject);
		Certificate.get_IssuerName(issuer);
		std::cout << "TElX509CertificateValidator.OnBeforeOCSPClientUse: " << (char *)subject.CommonName << " [" << (char *)issuer.CommonName << "]" << std::endl;
        std::cout << "OCSP: " << pcOCSPLocation << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElX509CertificateValidator.OnBeforeOCSPClientUse event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK CertValidator_OnOCSPResponseSignerValid(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TElX509CertificateHandle hCACertificate, TElOCSPResponseHandle hResponse, TElX509CertificateHandle hSignerCertificate, int8_t * SignerValid)
{
	try
	{
		TElX509Certificate Certificate(hCertificate, false);
		TName subject, issuer;
		Certificate.get_SubjectName(subject);
		Certificate.get_IssuerName(issuer);
		std::cout << "TElX509CertificateValidator.OnOCSPResponseSignerValid: " << (char *)subject.CommonName << " [" << (char *)issuer.CommonName << "]" << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElX509CertificateValidator.OnOCSPResponseSignerValid event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK CertValidator_OnOCSPError(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, const char *pcLocation, int32_t szLocation, TElOCSPClientHandle hClient, int32_t ErrorCode)
{
	try
	{
		TElX509Certificate Certificate(hCertificate, false);
		TName subject, issuer;
		Certificate.get_SubjectName(subject);
		Certificate.get_IssuerName(issuer);
		std::cout << "TElX509CertificateValidator.OnOCSPError: " << (char *)subject.CommonName << " [" << (char *)issuer.CommonName << "]" << std::endl;
        std::cout << "Error: " << ErrorCode << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElX509CertificateValidator.OnOCSPError event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK CertValidator_OnAfterOCSPResponseUse(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TElX509CertificateHandle hCACertificate, TElOCSPResponseHandle hResponse)
{
	try
	{
		TElX509Certificate Certificate(hCertificate, false);
		TName subject, issuer;
		Certificate.get_SubjectName(subject);
		Certificate.get_IssuerName(issuer);
		std::cout << "TElX509CertificateValidator.OnAfterOCSPResponseUse: " << (char *)subject.CommonName << " [" << (char *)issuer.CommonName << "]" << std::endl;
        TElOCSPResponse response(hResponse, false);
        int sigAlgorithm = response.get_SignatureAlgorithm();
        int respCount = response.get_ResponseCount();
        int producedAt = response.get_ProducedAt();
        TElOCSPResponderID * responder = response.get_ResponderID();
        std::string responderName;
        responder->get_Name()->SaveToDNString(responderName);
        TElOCSPSingleResponse * singleResponse = response.get_Responses((respCount - 1));
        std::cout << "Responder: " << responderName << std::endl;
        std::cout << "Algoritmo de assinatura: " << sigAlgorithm << std::endl;
        std::cout << "Número de respostas: " << respCount << std::endl;
        std::cout << "Timestamp: " << producedAt << std::endl;
        std::cout << "Status: " << singleResponse->get_CertStatus() << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElX509CertificateValidator.OnAfterOCSPResponseUse event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}

void SB_CALLBACK CertValidator_OnAfterCertificateValidation(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TElX509CertificateHandle hCACertificate, TSBCertificateValidityRaw &Validity, TSBCertificateValidityReasonRaw &Reason, int8_t &DoContinue)
{
	try
	{
		TElX509Certificate Certificate(hCertificate, false);
		TName subject, issuer;
		Certificate.get_SubjectName(subject);
		Certificate.get_IssuerName(issuer);
		std::cout << "TElX509CertificateValidator.OnAfterCertificateValidation: " << (char *)subject.CommonName << " [" << (char *)issuer.CommonName << "]" << std::endl;
	}
	catch (SBException E)
	{
		std::cout << "Unexpected error in TElX509CertificateValidator.OnAfterCertificateValidation event handler!" << std::endl;
		std::cout << E.what() << std::endl;
		std::cout << "Stack trace: " << E.getErrorStackTrace().c_str() << std::endl;
	}
}