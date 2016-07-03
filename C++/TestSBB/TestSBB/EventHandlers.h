#pragma once

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

using namespace SecureBlackbox;

void SB_CALLBACK httpsClient_OnBeforeWebSocketClientUsed(void * _ObjectData, TObjectHandle hSender, TElWebSocketClientHandle hWSClient, TElHTTPSClientHandle hHTTPClient);
void SB_CALLBACK httpsClient_OnWebSocketConnectionEstablished(void * _ObjectData, TObjectHandle hSender, TElWebSocketClientHandle hWSClient);
void SB_CALLBACK httpsClient_OnPreparedHeaders(void * _ObjectData, TObjectHandle hSender, TStringListHandle hHeaders);
void SB_CALLBACK httpsClient_OnReceivingHeaders(void * _ObjectData, TObjectHandle hSender, TStringListHandle hHeaders);
void SB_CALLBACK httpsClient_OnDynamicDataNeeded(void * _ObjectData, TObjectHandle hSender, const uint8_t pBuffer[], int32_t szBuffer, int32_t ToRead, int32_t * Read);
void SB_CALLBACK httpsClient_OnData(void * _ObjectData, TObjectHandle hSender, void * Buffer, int32_t Size);
void SB_CALLBACK httpsClient_OnProgress(void * _ObjectData, TObjectHandle hSender, int64_t Total, int64_t Current, int8_t * Cancel);
void SB_CALLBACK httpsClient_OnDocumentBegin(void * _ObjectData, TObjectHandle hSender);
void SB_CALLBACK httpsClient_OnDocumentEnd(void * _ObjectData, TObjectHandle hSender);
void SB_CALLBACK httpsClient_OnOAuth2Browse(void * _ObjectData, TObjectHandle hSender, const char *pcURL, int32_t szURL, TStringListHandle hResponseHeaders);
void SB_CALLBACK httpsClient_OnCookie(void * _ObjectData, TObjectHandle hSender, const char *pcCookieText, int32_t szCookieText);
void SB_CALLBACK httpsClient_OnSendData(void * _ObjectData, TObjectHandle hSender, void * Buffer, int32_t Size);
void SB_CALLBACK httpsClient_OnRedirection(void * _ObjectData, TObjectHandle hSender, const char *pcOldURL, int32_t szOldURL, char *pcNewURL, int32_t * szNewURL, int8_t * AllowRedirection);
void SB_CALLBACK signSecHandler_OnBeforeSign(void * _ObjectData, TObjectHandle hSender, TElSignedCMSMessageHandle hCMS);
void SB_CALLBACK signSecHandler_OnAfterSign(void * _ObjectData, TObjectHandle hSender, TElSignedCMSMessageHandle hCMS);
void SB_CALLBACK signSecHandler_OnRemoteSign(void * _ObjectData, TObjectHandle hSender, const uint8_t pHash[], int32_t szHash, uint8_t pSignedHash[], int32_t * szSignedHash);
void SB_CALLBACK signSecHandler_OnCertValidatorPrepared(void *, TObjectHandle, TElX509CertificateValidatorHandle * hCertValidator, TElX509CertificateHandle hCertificate);
void SB_CALLBACK signSecHandler_OnCertValidatorFinished(void * _ObjectData, TObjectHandle hSender, TElX509CertificateValidatorHandle CertValidator, TElX509CertificateHandle hCertificate, TSBCertificateValidityRaw Validity, TSBCertificateValidityReasonRaw Reason);
void SB_CALLBACK tspClient_OnBeforeSign(void * _ObjectData, TObjectHandle hSender, TObjectHandle hSigner);
void SB_CALLBACK tspClient_OnTSPError(void * _ObjectData, TObjectHandle hSender, int32_t ResponseCode);
void SB_CALLBACK CertValidator_OnBeforeCertificateValidation(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate);
void SB_CALLBACK CertValidator_OnBeforeCertificateRetrieverUse(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TSBGeneralNameRaw NameType, const char *pcLocation, int32_t szLocation, TElCustomCertificateRetrieverHandle * hRetriever);
void SB_CALLBACK CertValidator_OnCACertificateNeeded(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TElX509CertificateHandle * hCACertificate);
//void SB_CALLBACK CertValidator_OnCACertificateNotFound(...) - Not available in C++;
void SB_CALLBACK CertValidator_OnCACertificateRetrieved(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TSBGeneralNameRaw NameType, const char *pcLocation, int32_t szLocation, TElX509CertificateHandle hCACertificate);
void SB_CALLBACK CertValidator_OnCRLNeeded(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TElX509CertificateHandle hCACertificate, TElCustomCRLStorageHandle * hCRLs);
void SB_CALLBACK CertValidator_OnBeforeCRLRetrieverUse(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TElX509CertificateHandle hCACertificate, TSBGeneralNameRaw NameType, const char *pcLocation, int32_t szLocation, TElCustomCRLRetrieverHandle * hRetriever);
void SB_CALLBACK CertValidator_OnCRLRetrieved(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TElX509CertificateHandle hCACertificate, TSBGeneralNameRaw NameType, const char *pcLocation, int32_t szLocation, TElCertificateRevocationListHandle hCRL);
void SB_CALLBACK CertValidator_OnCRLError(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, const char *pcLocation, int32_t szLocation, TElCustomCRLRetrieverHandle hRetriever, int32_t ErrorCode);
void SB_CALLBACK CertValidator_OnAfterCRLUse(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TElX509CertificateHandle hCACertificate, TElCertificateRevocationListHandle hCRL);
void SB_CALLBACK CertValidator_OnBeforeOCSPClientUse(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TElX509CertificateHandle hCACertificate, const char *pcOCSPLocation, int32_t szOCSPLocation, TElOCSPClientHandle * hOCSPClient);
void SB_CALLBACK CertValidator_OnOCSPResponseSignerValid(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TElX509CertificateHandle hCACertificate, TElOCSPResponseHandle hResponse, TElX509CertificateHandle hSignerCertificate, int8_t * SignerValid);
void SB_CALLBACK CertValidator_OnOCSPError(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, const char *pcLocation, int32_t szLocation, TElOCSPClientHandle hClient, int32_t ErrorCode);
void SB_CALLBACK CertValidator_OnAfterOCSPResponseUse(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TElX509CertificateHandle hCACertificate, TElOCSPResponseHandle hResponse);
void SB_CALLBACK CertValidator_OnAfterCertificateValidation(void * _ObjectData, TObjectHandle hSender, TElX509CertificateHandle hCertificate, TElX509CertificateHandle hCACertificate, TSBCertificateValidityRaw &Validity, TSBCertificateValidityReasonRaw &Reason, int8_t &DoContinue);
