#include "sbxmladesintf.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELXADESPROCESSOR

TSBXAdESValidity TElXAdESProcessor::AddTimestampValidationData()
{
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_AddTimestampValidationData(_Handle, &OutResultRaw));
	return (TSBXAdESValidity)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELXMLCUSTOMFORMATTER
TSBXAdESValidity TElXAdESProcessor::AddTimestampValidationData(TElXMLCustomFormatter &Formatter)
{
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_AddTimestampValidationData_1(_Handle, Formatter.getHandle(), &OutResultRaw));
	return (TSBXAdESValidity)OutResultRaw;
}

TSBXAdESValidity TElXAdESProcessor::AddTimestampValidationData(TElXMLCustomFormatter *Formatter)
{
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_AddTimestampValidationData_1(_Handle, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBXAdESValidity)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELCLIENTTSPINFO_AND_TELXMLCUSTOMFORMATTER
TSBXAdESValidity TElXAdESProcessor::AddTimestampValidationData(TElClientTSPInfo &TSPInfo, const sb_u16string &URI, TElXMLCustomFormatter &Formatter)
{
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_AddTimestampValidationData_2(_Handle, TSPInfo.getHandle(), URI.data(), (int32_t)URI.length(), Formatter.getHandle(), &OutResultRaw));
	return (TSBXAdESValidity)OutResultRaw;
}

TSBXAdESValidity TElXAdESProcessor::AddTimestampValidationData(TElClientTSPInfo *TSPInfo, const sb_u16string &URI, TElXMLCustomFormatter *Formatter)
{
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_AddTimestampValidationData_2(_Handle, (TSPInfo != NULL) ? TSPInfo->getHandle() : SB_NULL_HANDLE, URI.data(), (int32_t)URI.length(), (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBXAdESValidity)OutResultRaw;
}
#ifdef SB_U16STRING_USED
TSBXAdESValidity TElXAdESProcessor::AddTimestampValidationData(TElClientTSPInfo &TSPInfo, const std::wstring &URI, TElXMLCustomFormatter &Formatter)
{
	std::string u16URI;
	sb_to_u16string(URI, u16URI);
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_AddTimestampValidationData_2(_Handle, TSPInfo.getHandle(), reinterpret_cast<const sb_char16_t*>(u16URI.data()), (int32_t)u16URI.length() >> 1, Formatter.getHandle(), &OutResultRaw));
	return (TSBXAdESValidity)OutResultRaw;
}

TSBXAdESValidity TElXAdESProcessor::AddTimestampValidationData(TElClientTSPInfo *TSPInfo, const std::wstring &URI, TElXMLCustomFormatter *Formatter)
{
	std::string u16URI;
	sb_to_u16string(URI, u16URI);
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_AddTimestampValidationData_2(_Handle, (TSPInfo != NULL) ? TSPInfo->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16URI.data()), (int32_t)u16URI.length() >> 1, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBXAdESValidity)OutResultRaw;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELCLIENTTSPINFO_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST
SB_INLINE void TElXAdESProcessor::AddTimestampValidationData(TElCustomCertStorage &Certs, TElCustomCRLStorage &CRLs, TList &OCSPResponses, TElXMLCustomFormatter &Formatter)
{
	SBCheckError(TElXAdESProcessor_AddTimestampValidationData_3(_Handle, Certs.getHandle(), CRLs.getHandle(), OCSPResponses.getHandle(), Formatter.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddTimestampValidationData(TElCustomCertStorage *Certs, TElCustomCRLStorage *CRLs, TList *OCSPResponses, TElXMLCustomFormatter *Formatter)
{
	SBCheckError(TElXAdESProcessor_AddTimestampValidationData_3(_Handle, (Certs != NULL) ? Certs->getHandle() : SB_NULL_HANDLE, (CRLs != NULL) ? CRLs->getHandle() : SB_NULL_HANDLE, (OCSPResponses != NULL) ? OCSPResponses->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST
SB_INLINE void TElXAdESProcessor::AddTimestampValidationData(TElCustomCertStorage &Certs, TElCustomCRLStorage &CRLs, TList &OCSPResponses, const sb_u16string &URI, TElXMLCustomFormatter &Formatter)
{
	SBCheckError(TElXAdESProcessor_AddTimestampValidationData_4(_Handle, Certs.getHandle(), CRLs.getHandle(), OCSPResponses.getHandle(), URI.data(), (int32_t)URI.length(), Formatter.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddTimestampValidationData(TElCustomCertStorage *Certs, TElCustomCRLStorage *CRLs, TList *OCSPResponses, const sb_u16string &URI, TElXMLCustomFormatter *Formatter)
{
	SBCheckError(TElXAdESProcessor_AddTimestampValidationData_4(_Handle, (Certs != NULL) ? Certs->getHandle() : SB_NULL_HANDLE, (CRLs != NULL) ? CRLs->getHandle() : SB_NULL_HANDLE, (OCSPResponses != NULL) ? OCSPResponses->getHandle() : SB_NULL_HANDLE, URI.data(), (int32_t)URI.length(), (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXAdESProcessor::AddTimestampValidationData(TElCustomCertStorage &Certs, TElCustomCRLStorage &CRLs, TList &OCSPResponses, const std::wstring &URI, TElXMLCustomFormatter &Formatter)
{
	std::string u16URI;
	sb_to_u16string(URI, u16URI);
	SBCheckError(TElXAdESProcessor_AddTimestampValidationData_4(_Handle, Certs.getHandle(), CRLs.getHandle(), OCSPResponses.getHandle(), reinterpret_cast<const sb_char16_t*>(u16URI.data()), (int32_t)u16URI.length() >> 1, Formatter.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddTimestampValidationData(TElCustomCertStorage *Certs, TElCustomCRLStorage *CRLs, TList *OCSPResponses, const std::wstring &URI, TElXMLCustomFormatter *Formatter)
{
	std::string u16URI;
	sb_to_u16string(URI, u16URI);
	SBCheckError(TElXAdESProcessor_AddTimestampValidationData_4(_Handle, (Certs != NULL) ? Certs->getHandle() : SB_NULL_HANDLE, (CRLs != NULL) ? CRLs->getHandle() : SB_NULL_HANDLE, (OCSPResponses != NULL) ? OCSPResponses->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16URI.data()), (int32_t)u16URI.length() >> 1, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST */

#ifdef SB_USE_CLASS_TELXMLPROCESSOR
SB_INLINE void TElXAdESProcessor::AddCounterSignature(TElXMLProcessor &Signer)
{
	SBCheckError(TElXAdESProcessor_AddCounterSignature(_Handle, Signer.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddCounterSignature(TElXMLProcessor *Signer)
{
	SBCheckError(TElXAdESProcessor_AddCounterSignature(_Handle, (Signer != NULL) ? Signer->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLPROCESSOR */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLPROCESSOR
SB_INLINE void TElXAdESProcessor::AddCounterSignature(TElXMLProcessor &Signer, TElXMLCustomFormatter &Formatter)
{
	SBCheckError(TElXAdESProcessor_AddCounterSignature_1(_Handle, Signer.getHandle(), Formatter.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddCounterSignature(TElXMLProcessor *Signer, TElXMLCustomFormatter *Formatter)
{
	SBCheckError(TElXAdESProcessor_AddCounterSignature_1(_Handle, (Signer != NULL) ? Signer->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLPROCESSOR */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE int32_t TElXAdESProcessor::AddSignatureTimestamp(TElCustomTSPClient &ATSPClient)
{
	int32_t OutResult;
	SBCheckError(TElXAdESProcessor_AddSignatureTimestamp(_Handle, ATSPClient.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXAdESProcessor::AddSignatureTimestamp(TElCustomTSPClient *ATSPClient)
{
	int32_t OutResult;
	SBCheckError(TElXAdESProcessor_AddSignatureTimestamp(_Handle, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
SB_INLINE int32_t TElXAdESProcessor::AddSignatureTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESProcessor_AddSignatureTimestamp_1(_Handle, ATSPClient.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXAdESProcessor::AddSignatureTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESProcessor_AddSignatureTimestamp_1(_Handle, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE int32_t TElXAdESProcessor::AddRefsOnlyTimestamp(TElCustomTSPClient &ATSPClient)
{
	int32_t OutResult;
	SBCheckError(TElXAdESProcessor_AddRefsOnlyTimestamp(_Handle, ATSPClient.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXAdESProcessor::AddRefsOnlyTimestamp(TElCustomTSPClient *ATSPClient)
{
	int32_t OutResult;
	SBCheckError(TElXAdESProcessor_AddRefsOnlyTimestamp(_Handle, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
SB_INLINE int32_t TElXAdESProcessor::AddRefsOnlyTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESProcessor_AddRefsOnlyTimestamp_1(_Handle, ATSPClient.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXAdESProcessor::AddRefsOnlyTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESProcessor_AddRefsOnlyTimestamp_1(_Handle, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE int32_t TElXAdESProcessor::AddSigAndRefsTimestamp(TElCustomTSPClient &ATSPClient)
{
	int32_t OutResult;
	SBCheckError(TElXAdESProcessor_AddSigAndRefsTimestamp(_Handle, ATSPClient.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXAdESProcessor::AddSigAndRefsTimestamp(TElCustomTSPClient *ATSPClient)
{
	int32_t OutResult;
	SBCheckError(TElXAdESProcessor_AddSigAndRefsTimestamp(_Handle, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
SB_INLINE int32_t TElXAdESProcessor::AddSigAndRefsTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESProcessor_AddSigAndRefsTimestamp_1(_Handle, ATSPClient.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXAdESProcessor::AddSigAndRefsTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESProcessor_AddSigAndRefsTimestamp_1(_Handle, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE int32_t TElXAdESProcessor::AddArchiveTimestamp(TElCustomTSPClient &ATSPClient)
{
	int32_t OutResult;
	SBCheckError(TElXAdESProcessor_AddArchiveTimestamp(_Handle, ATSPClient.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXAdESProcessor::AddArchiveTimestamp(TElCustomTSPClient *ATSPClient)
{
	int32_t OutResult;
	SBCheckError(TElXAdESProcessor_AddArchiveTimestamp(_Handle, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
SB_INLINE int32_t TElXAdESProcessor::AddArchiveTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESProcessor_AddArchiveTimestamp_1(_Handle, ATSPClient.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXAdESProcessor::AddArchiveTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESProcessor_AddArchiveTimestamp_1(_Handle, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElXAdESProcessor::AddAttributeCertificateRefs(TElCustomCertStorage &Certs)
{
	SBCheckError(TElXAdESProcessor_AddAttributeCertificateRefs(_Handle, Certs.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddAttributeCertificateRefs(TElCustomCertStorage *Certs)
{
	SBCheckError(TElXAdESProcessor_AddAttributeCertificateRefs(_Handle, (Certs != NULL) ? Certs->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLCUSTOMFORMATTER
SB_INLINE void TElXAdESProcessor::AddAttributeCertificateRefs(TElCustomCertStorage &Certs, TElXMLDigestMethod DigestMethod, TElXMLCustomFormatter &Formatter)
{
	SBCheckError(TElXAdESProcessor_AddAttributeCertificateRefs_1(_Handle, Certs.getHandle(), (TElXMLDigestMethodRaw)DigestMethod, Formatter.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddAttributeCertificateRefs(TElCustomCertStorage *Certs, TElXMLDigestMethod DigestMethod, TElXMLCustomFormatter *Formatter)
{
	SBCheckError(TElXAdESProcessor_AddAttributeCertificateRefs_1(_Handle, (Certs != NULL) ? Certs->getHandle() : SB_NULL_HANDLE, (TElXMLDigestMethodRaw)DigestMethod, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElXAdESProcessor::AddCompleteCertificateRefs(TElCustomCertStorage &Certs)
{
	SBCheckError(TElXAdESProcessor_AddCompleteCertificateRefs(_Handle, Certs.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddCompleteCertificateRefs(TElCustomCertStorage *Certs)
{
	SBCheckError(TElXAdESProcessor_AddCompleteCertificateRefs(_Handle, (Certs != NULL) ? Certs->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLCUSTOMFORMATTER
SB_INLINE void TElXAdESProcessor::AddCompleteCertificateRefs(TElCustomCertStorage &Certs, TElXMLDigestMethod DigestMethod, TElXMLCustomFormatter &Formatter)
{
	SBCheckError(TElXAdESProcessor_AddCompleteCertificateRefs_1(_Handle, Certs.getHandle(), (TElXMLDigestMethodRaw)DigestMethod, Formatter.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddCompleteCertificateRefs(TElCustomCertStorage *Certs, TElXMLDigestMethod DigestMethod, TElXMLCustomFormatter *Formatter)
{
	SBCheckError(TElXAdESProcessor_AddCompleteCertificateRefs_1(_Handle, (Certs != NULL) ? Certs->getHandle() : SB_NULL_HANDLE, (TElXMLDigestMethodRaw)DigestMethod, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TLIST
SB_INLINE void TElXAdESProcessor::AddAttributeRevocationRefs(TElCustomCRLStorage &CRLs, TList &OCSPResponses)
{
	SBCheckError(TElXAdESProcessor_AddAttributeRevocationRefs(_Handle, CRLs.getHandle(), OCSPResponses.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddAttributeRevocationRefs(TElCustomCRLStorage *CRLs, TList *OCSPResponses)
{
	SBCheckError(TElXAdESProcessor_AddAttributeRevocationRefs(_Handle, (CRLs != NULL) ? CRLs->getHandle() : SB_NULL_HANDLE, (OCSPResponses != NULL) ? OCSPResponses->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TLIST */

#ifdef SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST
SB_INLINE void TElXAdESProcessor::AddAttributeRevocationRefs(TElCustomCRLStorage &CRLs, TList &OCSPResponses, TElXMLDigestMethod DigestMethod, bool ResponderIdByKey, TElXMLCustomFormatter &Formatter)
{
	SBCheckError(TElXAdESProcessor_AddAttributeRevocationRefs_1(_Handle, CRLs.getHandle(), OCSPResponses.getHandle(), (TElXMLDigestMethodRaw)DigestMethod, (int8_t)ResponderIdByKey, Formatter.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddAttributeRevocationRefs(TElCustomCRLStorage *CRLs, TList *OCSPResponses, TElXMLDigestMethod DigestMethod, bool ResponderIdByKey, TElXMLCustomFormatter *Formatter)
{
	SBCheckError(TElXAdESProcessor_AddAttributeRevocationRefs_1(_Handle, (CRLs != NULL) ? CRLs->getHandle() : SB_NULL_HANDLE, (OCSPResponses != NULL) ? OCSPResponses->getHandle() : SB_NULL_HANDLE, (TElXMLDigestMethodRaw)DigestMethod, (int8_t)ResponderIdByKey, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST */

#ifdef SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TLIST
SB_INLINE void TElXAdESProcessor::AddCompleteRevocationRefs(TElCustomCRLStorage &CRLs, TList &OCSPResponses)
{
	SBCheckError(TElXAdESProcessor_AddCompleteRevocationRefs(_Handle, CRLs.getHandle(), OCSPResponses.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddCompleteRevocationRefs(TElCustomCRLStorage *CRLs, TList *OCSPResponses)
{
	SBCheckError(TElXAdESProcessor_AddCompleteRevocationRefs(_Handle, (CRLs != NULL) ? CRLs->getHandle() : SB_NULL_HANDLE, (OCSPResponses != NULL) ? OCSPResponses->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TLIST */

#ifdef SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST
SB_INLINE void TElXAdESProcessor::AddCompleteRevocationRefs(TElCustomCRLStorage &CRLs, TList &OCSPResponses, TElXMLDigestMethod DigestMethod, bool ResponderIdByKey, TElXMLCustomFormatter &Formatter)
{
	SBCheckError(TElXAdESProcessor_AddCompleteRevocationRefs_1(_Handle, CRLs.getHandle(), OCSPResponses.getHandle(), (TElXMLDigestMethodRaw)DigestMethod, (int8_t)ResponderIdByKey, Formatter.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddCompleteRevocationRefs(TElCustomCRLStorage *CRLs, TList *OCSPResponses, TElXMLDigestMethod DigestMethod, bool ResponderIdByKey, TElXMLCustomFormatter *Formatter)
{
	SBCheckError(TElXAdESProcessor_AddCompleteRevocationRefs_1(_Handle, (CRLs != NULL) ? CRLs->getHandle() : SB_NULL_HANDLE, (OCSPResponses != NULL) ? OCSPResponses->getHandle() : SB_NULL_HANDLE, (TElXMLDigestMethodRaw)DigestMethod, (int8_t)ResponderIdByKey, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST */

TSBXAdESValidity TElXAdESProcessor::AddValidationDataRefs()
{
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_AddValidationDataRefs(_Handle, &OutResultRaw));
	return (TSBXAdESValidity)OutResultRaw;
}

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLCUSTOMFORMATTER
TSBXAdESValidity TElXAdESProcessor::AddValidationDataRefs(TElX509Certificate &SigningCertificate, TElXMLDigestMethod DigestMethod, bool ResponderIdByKey, TElXMLCustomFormatter &Formatter)
{
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_AddValidationDataRefs_1(_Handle, SigningCertificate.getHandle(), (TElXMLDigestMethodRaw)DigestMethod, (int8_t)ResponderIdByKey, Formatter.getHandle(), &OutResultRaw));
	return (TSBXAdESValidity)OutResultRaw;
}

TSBXAdESValidity TElXAdESProcessor::AddValidationDataRefs(TElX509Certificate *SigningCertificate, TElXMLDigestMethod DigestMethod, bool ResponderIdByKey, TElXMLCustomFormatter *Formatter)
{
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_AddValidationDataRefs_1(_Handle, (SigningCertificate != NULL) ? SigningCertificate->getHandle() : SB_NULL_HANDLE, (TElXMLDigestMethodRaw)DigestMethod, (int8_t)ResponderIdByKey, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBXAdESValidity)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLCUSTOMFORMATTER
TSBXAdESValidity TElXAdESProcessor::AddValidationDataRefs(TElX509Certificate &SigningCertificate, bool IncludeCRL, bool IncludeOCSP, TElXMLDigestMethod DigestMethod, bool ResponderIdByKey, TElXMLCustomFormatter &Formatter)
{
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_AddValidationDataRefs_2(_Handle, SigningCertificate.getHandle(), (int8_t)IncludeCRL, (int8_t)IncludeOCSP, (TElXMLDigestMethodRaw)DigestMethod, (int8_t)ResponderIdByKey, Formatter.getHandle(), &OutResultRaw));
	return (TSBXAdESValidity)OutResultRaw;
}

TSBXAdESValidity TElXAdESProcessor::AddValidationDataRefs(TElX509Certificate *SigningCertificate, bool IncludeCRL, bool IncludeOCSP, TElXMLDigestMethod DigestMethod, bool ResponderIdByKey, TElXMLCustomFormatter *Formatter)
{
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_AddValidationDataRefs_2(_Handle, (SigningCertificate != NULL) ? SigningCertificate->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeCRL, (int8_t)IncludeOCSP, (TElXMLDigestMethodRaw)DigestMethod, (int8_t)ResponderIdByKey, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBXAdESValidity)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElXAdESProcessor::AddAttrAuthoritiesCertValues(TElCustomCertStorage &Certs)
{
	SBCheckError(TElXAdESProcessor_AddAttrAuthoritiesCertValues(_Handle, Certs.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddAttrAuthoritiesCertValues(TElCustomCertStorage *Certs)
{
	SBCheckError(TElXAdESProcessor_AddAttrAuthoritiesCertValues(_Handle, (Certs != NULL) ? Certs->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLCUSTOMFORMATTER
SB_INLINE void TElXAdESProcessor::AddAttrAuthoritiesCertValues(TElCustomCertStorage &Certs, TElXMLCustomFormatter &Formatter)
{
	SBCheckError(TElXAdESProcessor_AddAttrAuthoritiesCertValues_1(_Handle, Certs.getHandle(), Formatter.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddAttrAuthoritiesCertValues(TElCustomCertStorage *Certs, TElXMLCustomFormatter *Formatter)
{
	SBCheckError(TElXAdESProcessor_AddAttrAuthoritiesCertValues_1(_Handle, (Certs != NULL) ? Certs->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElXAdESProcessor::AddCertificateValues(TElCustomCertStorage &Certs)
{
	SBCheckError(TElXAdESProcessor_AddCertificateValues(_Handle, Certs.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddCertificateValues(TElCustomCertStorage *Certs)
{
	SBCheckError(TElXAdESProcessor_AddCertificateValues(_Handle, (Certs != NULL) ? Certs->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLCUSTOMFORMATTER
SB_INLINE void TElXAdESProcessor::AddCertificateValues(TElCustomCertStorage &Certs, TElXMLCustomFormatter &Formatter)
{
	SBCheckError(TElXAdESProcessor_AddCertificateValues_1(_Handle, Certs.getHandle(), Formatter.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddCertificateValues(TElCustomCertStorage *Certs, TElXMLCustomFormatter *Formatter)
{
	SBCheckError(TElXAdESProcessor_AddCertificateValues_1(_Handle, (Certs != NULL) ? Certs->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TLIST
SB_INLINE void TElXAdESProcessor::AddAttributeRevocationValues(TElCustomCRLStorage &CRLs, TList &OCSPResponses)
{
	SBCheckError(TElXAdESProcessor_AddAttributeRevocationValues(_Handle, CRLs.getHandle(), OCSPResponses.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddAttributeRevocationValues(TElCustomCRLStorage *CRLs, TList *OCSPResponses)
{
	SBCheckError(TElXAdESProcessor_AddAttributeRevocationValues(_Handle, (CRLs != NULL) ? CRLs->getHandle() : SB_NULL_HANDLE, (OCSPResponses != NULL) ? OCSPResponses->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TLIST */

#ifdef SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST
SB_INLINE void TElXAdESProcessor::AddAttributeRevocationValues(TElCustomCRLStorage &CRLs, TList &OCSPResponses, TElXMLCustomFormatter &Formatter)
{
	SBCheckError(TElXAdESProcessor_AddAttributeRevocationValues_1(_Handle, CRLs.getHandle(), OCSPResponses.getHandle(), Formatter.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddAttributeRevocationValues(TElCustomCRLStorage *CRLs, TList *OCSPResponses, TElXMLCustomFormatter *Formatter)
{
	SBCheckError(TElXAdESProcessor_AddAttributeRevocationValues_1(_Handle, (CRLs != NULL) ? CRLs->getHandle() : SB_NULL_HANDLE, (OCSPResponses != NULL) ? OCSPResponses->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST */

#ifdef SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TLIST
SB_INLINE void TElXAdESProcessor::AddRevocationValues(TElCustomCRLStorage &CRLs, TList &OCSPResponses)
{
	SBCheckError(TElXAdESProcessor_AddRevocationValues(_Handle, CRLs.getHandle(), OCSPResponses.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddRevocationValues(TElCustomCRLStorage *CRLs, TList *OCSPResponses)
{
	SBCheckError(TElXAdESProcessor_AddRevocationValues(_Handle, (CRLs != NULL) ? CRLs->getHandle() : SB_NULL_HANDLE, (OCSPResponses != NULL) ? OCSPResponses->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TLIST */

#ifdef SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST
SB_INLINE void TElXAdESProcessor::AddRevocationValues(TElCustomCRLStorage &CRLs, TList &OCSPResponses, TElXMLCustomFormatter &Formatter)
{
	SBCheckError(TElXAdESProcessor_AddRevocationValues_1(_Handle, CRLs.getHandle(), OCSPResponses.getHandle(), Formatter.getHandle()));
}

SB_INLINE void TElXAdESProcessor::AddRevocationValues(TElCustomCRLStorage *CRLs, TList *OCSPResponses, TElXMLCustomFormatter *Formatter)
{
	SBCheckError(TElXAdESProcessor_AddRevocationValues_1(_Handle, (CRLs != NULL) ? CRLs->getHandle() : SB_NULL_HANDLE, (OCSPResponses != NULL) ? OCSPResponses->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRLSTORAGE_AND_TELXMLCUSTOMFORMATTER_AND_TLIST */

TSBXAdESValidity TElXAdESProcessor::AddValidationDataValues()
{
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_AddValidationDataValues(_Handle, &OutResultRaw));
	return (TSBXAdESValidity)OutResultRaw;
}

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLCUSTOMFORMATTER
TSBXAdESValidity TElXAdESProcessor::AddValidationDataValues(TElX509Certificate &SigningCertificate, TElXMLCustomFormatter &Formatter)
{
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_AddValidationDataValues_1(_Handle, SigningCertificate.getHandle(), Formatter.getHandle(), &OutResultRaw));
	return (TSBXAdESValidity)OutResultRaw;
}

TSBXAdESValidity TElXAdESProcessor::AddValidationDataValues(TElX509Certificate *SigningCertificate, TElXMLCustomFormatter *Formatter)
{
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_AddValidationDataValues_1(_Handle, (SigningCertificate != NULL) ? SigningCertificate->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBXAdESValidity)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLCUSTOMFORMATTER
TSBXAdESValidity TElXAdESProcessor::AddValidationDataValues(TElX509Certificate &SigningCertificate, bool IncludeCRL, bool IncludeOCSP, TElXMLCustomFormatter &Formatter)
{
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_AddValidationDataValues_2(_Handle, SigningCertificate.getHandle(), (int8_t)IncludeCRL, (int8_t)IncludeOCSP, Formatter.getHandle(), &OutResultRaw));
	return (TSBXAdESValidity)OutResultRaw;
}

TSBXAdESValidity TElXAdESProcessor::AddValidationDataValues(TElX509Certificate *SigningCertificate, bool IncludeCRL, bool IncludeOCSP, TElXMLCustomFormatter *Formatter)
{
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_AddValidationDataValues_2(_Handle, (SigningCertificate != NULL) ? SigningCertificate->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeCRL, (int8_t)IncludeOCSP, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBXAdESValidity)OutResultRaw;
}
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE TElX509CertificateHandle TElXAdESProcessor::GetSignerCertificate()
{
	TElX509CertificateHandle OutResult;
	SBCheckError(TElXAdESProcessor_GetSignerCertificate(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE void TElXAdESProcessor::ClearPKICache()
{
	SBCheckError(TElXAdESProcessor_ClearPKICache(_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElXAdESProcessor::ExtractAllCertificates(TElCustomCertStorage &Certs)
{
	SBCheckError(TElXAdESProcessor_ExtractAllCertificates(_Handle, Certs.getHandle()));
}

SB_INLINE void TElXAdESProcessor::ExtractAllCertificates(TElCustomCertStorage *Certs)
{
	SBCheckError(TElXAdESProcessor_ExtractAllCertificates(_Handle, (Certs != NULL) ? Certs->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRLSTORAGE
SB_INLINE void TElXAdESProcessor::ExtractAllCRLs(TElCustomCRLStorage &CRLs)
{
	SBCheckError(TElXAdESProcessor_ExtractAllCRLs(_Handle, CRLs.getHandle()));
}

SB_INLINE void TElXAdESProcessor::ExtractAllCRLs(TElCustomCRLStorage *CRLs)
{
	SBCheckError(TElXAdESProcessor_ExtractAllCRLs(_Handle, (CRLs != NULL) ? CRLs->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRLSTORAGE */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE void TElXAdESProcessor::ExtractAllOCSPResponses(TList &OCSPResponses)
{
	SBCheckError(TElXAdESProcessor_ExtractAllOCSPResponses(_Handle, OCSPResponses.getHandle()));
}

SB_INLINE void TElXAdESProcessor::ExtractAllOCSPResponses(TList *OCSPResponses)
{
	SBCheckError(TElXAdESProcessor_ExtractAllOCSPResponses(_Handle, (OCSPResponses != NULL) ? OCSPResponses->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TLIST */

SB_INLINE int32_t TElXAdESProcessor::get_GracePeriod()
{
	int32_t OutResult;
	SBCheckError(TElXAdESProcessor_get_GracePeriod(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXAdESProcessor::set_GracePeriod(int32_t Value)
{
	SBCheckError(TElXAdESProcessor_set_GracePeriod(_Handle, Value));
}

bool TElXAdESProcessor::get_OfflineMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_get_OfflineMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXAdESProcessor::set_OfflineMode(bool Value)
{
	SBCheckError(TElXAdESProcessor_set_OfflineMode(_Handle, (int8_t)Value));
}

TElXMLCanonicalizationMethod TElXAdESProcessor::get_TimestampCanonicalizationMethod()
{
	TElXMLCanonicalizationMethodRaw OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_get_TimestampCanonicalizationMethod(_Handle, &OutResultRaw));
	return (TElXMLCanonicalizationMethod)OutResultRaw;
}

SB_INLINE void TElXAdESProcessor::set_TimestampCanonicalizationMethod(TElXMLCanonicalizationMethod Value)
{
	SBCheckError(TElXAdESProcessor_set_TimestampCanonicalizationMethod(_Handle, (TElXMLCanonicalizationMethodRaw)Value));
}

TSBXAdESOptions TElXAdESProcessor::get_XAdESOptions()
{
	TSBXAdESOptionsRaw OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_get_XAdESOptions(_Handle, &OutResultRaw));
	return (TSBXAdESOptions)OutResultRaw;
}

SB_INLINE void TElXAdESProcessor::set_XAdESOptions(TSBXAdESOptions Value)
{
	SBCheckError(TElXAdESProcessor_set_XAdESOptions(_Handle, (TSBXAdESOptionsRaw)Value));
}

SB_INLINE int64_t TElXAdESProcessor::get_ValidationMoment()
{
	int64_t OutResult;
	SBCheckError(TElXAdESProcessor_get_ValidationMoment(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXAdESProcessor::set_ValidationMoment(int64_t Value)
{
	SBCheckError(TElXAdESProcessor_set_ValidationMoment(_Handle, Value));
}

bool TElXAdESProcessor::get_ForceCompleteChainValidation()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_get_ForceCompleteChainValidation(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXAdESProcessor::set_ForceCompleteChainValidation(bool Value)
{
	SBCheckError(TElXAdESProcessor_set_ForceCompleteChainValidation(_Handle, (int8_t)Value));
}

bool TElXAdESProcessor::get_IgnoreChainValidationErrors()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXAdESProcessor_get_IgnoreChainValidationErrors(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXAdESProcessor::set_IgnoreChainValidationErrors(bool Value)
{
	SBCheckError(TElXAdESProcessor_set_IgnoreChainValidationErrors(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElXAdESProcessor::get_TrustedCertificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESProcessor_get_TrustedCertificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TrustedCertificates)
		this->_Inst_TrustedCertificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_TrustedCertificates->updateHandle(hOutResult);
	return this->_Inst_TrustedCertificates;
}

SB_INLINE void TElXAdESProcessor::set_TrustedCertificates(TElCustomCertStorage &Value)
{
	SBCheckError(TElXAdESProcessor_set_TrustedCertificates(_Handle, Value.getHandle()));
}

SB_INLINE void TElXAdESProcessor::set_TrustedCertificates(TElCustomCertStorage *Value)
{
	SBCheckError(TElXAdESProcessor_set_TrustedCertificates(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElXAdESProcessor::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESProcessor_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElXAdESProcessor::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElXAdESProcessor_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElXAdESProcessor::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElXAdESProcessor_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATOR
TElX509CertificateValidator* TElXAdESProcessor::get_CertificateValidator()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESProcessor_get_CertificateValidator(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertificateValidator)
		this->_Inst_CertificateValidator = new TElX509CertificateValidator(hOutResult, ohFalse);
	else
		this->_Inst_CertificateValidator->updateHandle(hOutResult);
	return this->_Inst_CertificateValidator;
}

SB_INLINE void TElXAdESProcessor::set_CertificateValidator(TElX509CertificateValidator &Value)
{
	SBCheckError(TElXAdESProcessor_set_CertificateValidator(_Handle, Value.getHandle()));
}

SB_INLINE void TElXAdESProcessor::set_CertificateValidator(TElX509CertificateValidator *Value)
{
	SBCheckError(TElXAdESProcessor_set_CertificateValidator(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATOR */

SB_INLINE void TElXAdESProcessor::get_OnBeforeSaveUnsignedProperty(TSBXAdESBeforeSaveUnsignedPropertyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXAdESProcessor_get_OnBeforeSaveUnsignedProperty(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXAdESProcessor::set_OnBeforeSaveUnsignedProperty(TSBXAdESBeforeSaveUnsignedPropertyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXAdESProcessor_set_OnBeforeSaveUnsignedProperty(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElXAdESProcessor::get_OnBeforeCertificateValidate(TSBXAdESBeforeCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXAdESProcessor_get_OnBeforeCertificateValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXAdESProcessor::set_OnBeforeCertificateValidate(TSBXAdESBeforeCertificateValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXAdESProcessor_set_OnBeforeCertificateValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElXAdESProcessor::get_OnAfterCertificateValidate(TSBXAdESAfterCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXAdESProcessor_get_OnAfterCertificateValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXAdESProcessor::set_OnAfterCertificateValidate(TSBXAdESAfterCertificateValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXAdESProcessor_set_OnAfterCertificateValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElXAdESProcessor::get_OnCertificateNeeded(TSBXAdESCertificateNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXAdESProcessor_get_OnCertificateNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXAdESProcessor::set_OnCertificateNeeded(TSBXAdESCertificateNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXAdESProcessor_set_OnCertificateNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElXAdESProcessor::get_OnStoreCertificate(TSBXAdESStoreCertificateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXAdESProcessor_get_OnStoreCertificate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXAdESProcessor::set_OnStoreCertificate(TSBXAdESStoreCertificateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXAdESProcessor_set_OnStoreCertificate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElXAdESProcessor::get_OnStoreCRL(TSBXAdESStoreCRLEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXAdESProcessor_get_OnStoreCRL(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXAdESProcessor::set_OnStoreCRL(TSBXAdESStoreCRLEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXAdESProcessor_set_OnStoreCRL(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElXAdESProcessor::get_OnStoreOCSPResponse(TSBXAdESStoreOCSPResponseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXAdESProcessor_get_OnStoreOCSPResponse(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXAdESProcessor::set_OnStoreOCSPResponse(TSBXAdESStoreOCSPResponseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXAdESProcessor_set_OnStoreOCSPResponse(_Handle, pMethodValue, pDataValue));
}

void TElXAdESProcessor::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_TrustedCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATOR
	this->_Inst_CertificateValidator = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATOR */
}

TElXAdESProcessor::TElXAdESProcessor(TElXAdESProcessorHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElXAdESProcessor::TElXAdESProcessor(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXAdESProcessor_Create(AOwner.getHandle(), &_Handle));
}

TElXAdESProcessor::TElXAdESProcessor(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXAdESProcessor_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElXAdESProcessor::~TElXAdESProcessor()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_TrustedCertificates;
	this->_Inst_TrustedCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATOR
	delete this->_Inst_CertificateValidator;
	this->_Inst_CertificateValidator = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATOR */
}
#endif /* SB_USE_CLASS_TELXADESPROCESSOR */

#ifdef SB_USE_CLASS_TELXADESSIGNER

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLREFERENCELIST
SB_INLINE int32_t TElXAdESSigner::TimestampDataObjects(TElXMLReferenceList &AReferences, TElXMLCustomFormatter &Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESSigner_TimestampDataObjects(_Handle, AReferences.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXAdESSigner::TimestampDataObjects(TElXMLReferenceList *AReferences, TElXMLCustomFormatter *Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESSigner_TimestampDataObjects(_Handle, (AReferences != NULL) ? AReferences->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLREFERENCELIST */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMELEMENT_AND_TELXMLKEYINFO_AND_TELXMLREFERENCELIST
SB_INLINE int32_t TElXAdESSigner::AddUnsignedObjects(TElXMLDOMElement &SignedInfo, TElXMLDOMElement &SignatureValue, TElXMLKeyInfo &KeyInfo, TElXMLReferenceList &AReferences, TObject &AObjects, TElXMLCustomFormatter &Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESSigner_AddUnsignedObjects(_Handle, SignedInfo.getHandle(), SignatureValue.getHandle(), KeyInfo.getHandle(), AReferences.getHandle(), AObjects.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXAdESSigner::AddUnsignedObjects(TElXMLDOMElement *SignedInfo, TElXMLDOMElement *SignatureValue, TElXMLKeyInfo *KeyInfo, TElXMLReferenceList *AReferences, TObject *AObjects, TElXMLCustomFormatter *Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESSigner_AddUnsignedObjects(_Handle, (SignedInfo != NULL) ? SignedInfo->getHandle() : SB_NULL_HANDLE, (SignatureValue != NULL) ? SignatureValue->getHandle() : SB_NULL_HANDLE, (KeyInfo != NULL) ? KeyInfo->getHandle() : SB_NULL_HANDLE, (AReferences != NULL) ? AReferences->getHandle() : SB_NULL_HANDLE, (AObjects != NULL) ? AObjects->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMELEMENT_AND_TELXMLKEYINFO_AND_TELXMLREFERENCELIST */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElXAdESSigner::SetSigningCertificates(TElCustomCertStorage &Value)
{
	SBCheckError(TElXAdESSigner_SetSigningCertificates(_Handle, Value.getHandle()));
}

SB_INLINE void TElXAdESSigner::SetSigningCertificates(TElCustomCertStorage *Value)
{
	SBCheckError(TElXAdESSigner_SetSigningCertificates(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElXAdESSigner::SetTSPClient(TElCustomTSPClient &Value)
{
	SBCheckError(TElXAdESSigner_SetTSPClient(_Handle, Value.getHandle()));
}

SB_INLINE void TElXAdESSigner::SetTSPClient(TElCustomTSPClient *Value)
{
	SBCheckError(TElXAdESSigner_SetTSPClient(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

SB_INLINE void TElXAdESSigner::SetXAdESForm(TSBXAdESForm Value)
{
	SBCheckError(TElXAdESSigner_SetXAdESForm(_Handle, (TSBXAdESFormRaw)Value));
}

SB_INLINE void TElXAdESSigner::SetXAdESVersion(TSBXAdESVersion Value)
{
	SBCheckError(TElXAdESSigner_SetXAdESVersion(_Handle, (TSBXAdESVersionRaw)Value));
}

SB_INLINE void TElXAdESSigner::Clear()
{
	SBCheckError(TElXAdESSigner_Clear(_Handle));
}

SB_INLINE void TElXAdESSigner::Generate()
{
	SBCheckError(TElXAdESSigner_Generate(_Handle));
}

SB_INLINE void TElXAdESSigner::Generate(TSBXAdESForm AXAdESForm)
{
	SBCheckError(TElXAdESSigner_Generate_1(_Handle, (TSBXAdESFormRaw)AXAdESForm));
}

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLPROCESSOR
SB_INLINE void TElXAdESSigner::AddCounterSignature(TElXMLProcessor &Signer, TElXMLCustomFormatter &Formatter)
{
	SBCheckError(TElXAdESSigner_AddCounterSignature(_Handle, Signer.getHandle(), Formatter.getHandle()));
}

SB_INLINE void TElXAdESSigner::AddCounterSignature(TElXMLProcessor *Signer, TElXMLCustomFormatter *Formatter)
{
	SBCheckError(TElXAdESSigner_AddCounterSignature(_Handle, (Signer != NULL) ? Signer->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLPROCESSOR */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElXAdESSigner::AddAllDataObjectsTimestamp(TElCustomTSPClient &ATSPClient)
{
	SBCheckError(TElXAdESSigner_AddAllDataObjectsTimestamp(_Handle, ATSPClient.getHandle()));
}

SB_INLINE void TElXAdESSigner::AddAllDataObjectsTimestamp(TElCustomTSPClient *ATSPClient)
{
	SBCheckError(TElXAdESSigner_AddAllDataObjectsTimestamp(_Handle, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
SB_INLINE int32_t TElXAdESSigner::AddSignatureTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESSigner_AddSignatureTimestamp(_Handle, ATSPClient.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXAdESSigner::AddSignatureTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESSigner_AddSignatureTimestamp(_Handle, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
SB_INLINE int32_t TElXAdESSigner::AddRefsOnlyTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESSigner_AddRefsOnlyTimestamp(_Handle, ATSPClient.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXAdESSigner::AddRefsOnlyTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESSigner_AddRefsOnlyTimestamp(_Handle, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
SB_INLINE int32_t TElXAdESSigner::AddSigAndRefsTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESSigner_AddSigAndRefsTimestamp(_Handle, ATSPClient.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXAdESSigner::AddSigAndRefsTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESSigner_AddSigAndRefsTimestamp(_Handle, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
SB_INLINE int32_t TElXAdESSigner::AddArchiveTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESSigner_AddArchiveTimestamp(_Handle, ATSPClient.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXAdESSigner::AddArchiveTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESSigner_AddArchiveTimestamp(_Handle, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYID
TElXMLSignaturePolicyId* TElXAdESSigner::get_PolicyId()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESSigner_get_PolicyId(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PolicyId)
		this->_Inst_PolicyId = new TElXMLSignaturePolicyId(hOutResult, ohFalse);
	else
		this->_Inst_PolicyId->updateHandle(hOutResult);
	return this->_Inst_PolicyId;
}

SB_INLINE void TElXAdESSigner::set_PolicyId(TElXMLSignaturePolicyId &Value)
{
	SBCheckError(TElXAdESSigner_set_PolicyId(_Handle, Value.getHandle()));
}

SB_INLINE void TElXAdESSigner::set_PolicyId(TElXMLSignaturePolicyId *Value)
{
	SBCheckError(TElXAdESSigner_set_PolicyId(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYID */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE
TElXMLSignatureProductionPlace* TElXAdESSigner::get_ProductionPlace()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESSigner_get_ProductionPlace(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ProductionPlace)
		this->_Inst_ProductionPlace = new TElXMLSignatureProductionPlace(hOutResult, ohFalse);
	else
		this->_Inst_ProductionPlace->updateHandle(hOutResult);
	return this->_Inst_ProductionPlace;
}

SB_INLINE void TElXAdESSigner::set_ProductionPlace(TElXMLSignatureProductionPlace &Value)
{
	SBCheckError(TElXAdESSigner_set_ProductionPlace(_Handle, Value.getHandle()));
}

SB_INLINE void TElXAdESSigner::set_ProductionPlace(TElXMLSignatureProductionPlace *Value)
{
	SBCheckError(TElXAdESSigner_set_ProductionPlace(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE */

#ifdef SB_USE_CLASS_TELXMLSIGNERROLE
TElXMLSignerRole* TElXAdESSigner::get_SignerRole()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESSigner_get_SignerRole(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignerRole)
		this->_Inst_SignerRole = new TElXMLSignerRole(hOutResult, ohFalse);
	else
		this->_Inst_SignerRole->updateHandle(hOutResult);
	return this->_Inst_SignerRole;
}

SB_INLINE void TElXAdESSigner::set_SignerRole(TElXMLSignerRole &Value)
{
	SBCheckError(TElXAdESSigner_set_SignerRole(_Handle, Value.getHandle()));
}

SB_INLINE void TElXAdESSigner::set_SignerRole(TElXMLSignerRole *Value)
{
	SBCheckError(TElXAdESSigner_set_SignerRole(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLSIGNERROLE */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES
TElXMLQualifyingProperties* TElXAdESSigner::get_QualifyingProperties()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESSigner_get_QualifyingProperties(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_QualifyingProperties)
		this->_Inst_QualifyingProperties = new TElXMLQualifyingProperties(hOutResult, ohFalse);
	else
		this->_Inst_QualifyingProperties->updateHandle(hOutResult);
	return this->_Inst_QualifyingProperties;
}

SB_INLINE void TElXAdESSigner::set_QualifyingProperties(TElXMLQualifyingProperties &Value)
{
	SBCheckError(TElXAdESSigner_set_QualifyingProperties(_Handle, Value.getHandle()));
}

SB_INLINE void TElXAdESSigner::set_QualifyingProperties(TElXMLQualifyingProperties *Value)
{
	SBCheckError(TElXAdESSigner_set_QualifyingProperties(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST
TElXMLQualifyingPropertiesReferenceList* TElXAdESSigner::get_QualifyingPropertiesReferences()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESSigner_get_QualifyingPropertiesReferences(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_QualifyingPropertiesReferences)
		this->_Inst_QualifyingPropertiesReferences = new TElXMLQualifyingPropertiesReferenceList(hOutResult, ohFalse);
	else
		this->_Inst_QualifyingPropertiesReferences->updateHandle(hOutResult);
	return this->_Inst_QualifyingPropertiesReferences;
}
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST */

bool TElXAdESSigner::get_OwnSigningCertificates()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXAdESSigner_get_OwnSigningCertificates(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXAdESSigner::set_OwnSigningCertificates(bool Value)
{
	SBCheckError(TElXAdESSigner_set_OwnSigningCertificates(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElXAdESSigner::get_SigningCertificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESSigner_get_SigningCertificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigningCertificates)
		this->_Inst_SigningCertificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_SigningCertificates->updateHandle(hOutResult);
	return this->_Inst_SigningCertificates;
}

SB_INLINE void TElXAdESSigner::set_SigningCertificates(TElCustomCertStorage &Value)
{
	SBCheckError(TElXAdESSigner_set_SigningCertificates(_Handle, Value.getHandle()));
}

SB_INLINE void TElXAdESSigner::set_SigningCertificates(TElCustomCertStorage *Value)
{
	SBCheckError(TElXAdESSigner_set_SigningCertificates(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

SB_INLINE int64_t TElXAdESSigner::get_SigningTime()
{
	int64_t OutResult;
	SBCheckError(TElXAdESSigner_get_SigningTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXAdESSigner::set_SigningTime(int64_t Value)
{
	SBCheckError(TElXAdESSigner_set_SigningTime(_Handle, Value));
}

TElXMLDigestMethod TElXAdESSigner::get_SigningCertificatesDigestMethod()
{
	TElXMLDigestMethodRaw OutResultRaw = 0;
	SBCheckError(TElXAdESSigner_get_SigningCertificatesDigestMethod(_Handle, &OutResultRaw));
	return (TElXMLDigestMethod)OutResultRaw;
}

SB_INLINE void TElXAdESSigner::set_SigningCertificatesDigestMethod(TElXMLDigestMethod Value)
{
	SBCheckError(TElXAdESSigner_set_SigningCertificatesDigestMethod(_Handle, (TElXMLDigestMethodRaw)Value));
}

TElXAdESIncludedProperties TElXAdESSigner::get_Included()
{
	TElXAdESIncludedPropertiesRaw OutResultRaw = 0;
	SBCheckError(TElXAdESSigner_get_Included(_Handle, &OutResultRaw));
	return (TElXAdESIncludedProperties)OutResultRaw;
}

SB_INLINE void TElXAdESSigner::set_Included(TElXAdESIncludedProperties Value)
{
	SBCheckError(TElXAdESSigner_set_Included(_Handle, (TElXAdESIncludedPropertiesRaw)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
TElCustomTSPClient* TElXAdESSigner::get_TSPClient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESSigner_get_TSPClient(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TSPClient)
		this->_Inst_TSPClient = new TElCustomTSPClient(hOutResult, ohFalse);
	else
		this->_Inst_TSPClient->updateHandle(hOutResult);
	return this->_Inst_TSPClient;
}

SB_INLINE void TElXAdESSigner::set_TSPClient(TElCustomTSPClient &Value)
{
	SBCheckError(TElXAdESSigner_set_TSPClient(_Handle, Value.getHandle()));
}

SB_INLINE void TElXAdESSigner::set_TSPClient(TElCustomTSPClient *Value)
{
	SBCheckError(TElXAdESSigner_set_TSPClient(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

bool TElXAdESSigner::get_IgnoreTimestampFailure()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXAdESSigner_get_IgnoreTimestampFailure(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXAdESSigner::set_IgnoreTimestampFailure(bool Value)
{
	SBCheckError(TElXAdESSigner_set_IgnoreTimestampFailure(_Handle, (int8_t)Value));
}

TSBXAdESForm TElXAdESSigner::get_XAdESForm()
{
	TSBXAdESFormRaw OutResultRaw = 0;
	SBCheckError(TElXAdESSigner_get_XAdESForm(_Handle, &OutResultRaw));
	return (TSBXAdESForm)OutResultRaw;
}

SB_INLINE void TElXAdESSigner::set_XAdESForm(TSBXAdESForm Value)
{
	SBCheckError(TElXAdESSigner_set_XAdESForm(_Handle, (TSBXAdESFormRaw)Value));
}

TSBXAdESVersion TElXAdESSigner::get_XAdESVersion()
{
	TSBXAdESVersionRaw OutResultRaw = 0;
	SBCheckError(TElXAdESSigner_get_XAdESVersion(_Handle, &OutResultRaw));
	return (TSBXAdESVersion)OutResultRaw;
}

SB_INLINE void TElXAdESSigner::set_XAdESVersion(TSBXAdESVersion Value)
{
	SBCheckError(TElXAdESSigner_set_XAdESVersion(_Handle, (TSBXAdESVersionRaw)Value));
}

void TElXAdESSigner::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYID
	this->_Inst_PolicyId = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYID */
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE
	this->_Inst_ProductionPlace = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE */
#ifdef SB_USE_CLASS_TELXMLSIGNERROLE
	this->_Inst_SignerRole = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNERROLE */
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES
	this->_Inst_QualifyingProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES */
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST
	this->_Inst_QualifyingPropertiesReferences = NULL;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_SigningCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
	this->_Inst_TSPClient = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */
}

TElXAdESSigner::TElXAdESSigner(TElXAdESSignerHandle handle, TElOwnHandle ownHandle) : TElXAdESProcessor(handle, ownHandle)
{
	initInstances();
}

TElXAdESSigner::TElXAdESSigner(TComponent &AOwner) : TElXAdESProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXAdESSigner_Create(AOwner.getHandle(), &_Handle));
}

TElXAdESSigner::TElXAdESSigner(TComponent *AOwner) : TElXAdESProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXAdESSigner_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElXAdESSigner::~TElXAdESSigner()
{
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYID
	delete this->_Inst_PolicyId;
	this->_Inst_PolicyId = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYID */
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE
	delete this->_Inst_ProductionPlace;
	this->_Inst_ProductionPlace = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE */
#ifdef SB_USE_CLASS_TELXMLSIGNERROLE
	delete this->_Inst_SignerRole;
	this->_Inst_SignerRole = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNERROLE */
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES
	delete this->_Inst_QualifyingProperties;
	this->_Inst_QualifyingProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES */
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST
	delete this->_Inst_QualifyingPropertiesReferences;
	this->_Inst_QualifyingPropertiesReferences = NULL;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_SigningCertificates;
	this->_Inst_SigningCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
	delete this->_Inst_TSPClient;
	this->_Inst_TSPClient = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */
}
#endif /* SB_USE_CLASS_TELXADESSIGNER */

#ifdef SB_USE_CLASS_TELXADESVERIFIER

#ifdef SB_USE_CLASS_TELXMLPROCESSOR
SB_INLINE void TElXAdESVerifier::Load(TElXMLProcessor &Verifier)
{
	SBCheckError(TElXAdESVerifier_Load(_Handle, Verifier.getHandle()));
}

SB_INLINE void TElXAdESVerifier::Load(TElXMLProcessor *Verifier)
{
	SBCheckError(TElXAdESVerifier_Load(_Handle, (Verifier != NULL) ? Verifier->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLPROCESSOR */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLPROCESSOR
SB_INLINE void TElXAdESVerifier::AddCounterSignature(TElXMLProcessor &Signer, TElXMLCustomFormatter &Formatter)
{
	SBCheckError(TElXAdESVerifier_AddCounterSignature(_Handle, Signer.getHandle(), Formatter.getHandle()));
}

SB_INLINE void TElXAdESVerifier::AddCounterSignature(TElXMLProcessor *Signer, TElXMLCustomFormatter *Formatter)
{
	SBCheckError(TElXAdESVerifier_AddCounterSignature(_Handle, (Signer != NULL) ? Signer->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLPROCESSOR */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
SB_INLINE int32_t TElXAdESVerifier::AddSignatureTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESVerifier_AddSignatureTimestamp(_Handle, ATSPClient.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXAdESVerifier::AddSignatureTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESVerifier_AddSignatureTimestamp(_Handle, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
SB_INLINE int32_t TElXAdESVerifier::AddRefsOnlyTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESVerifier_AddRefsOnlyTimestamp(_Handle, ATSPClient.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXAdESVerifier::AddRefsOnlyTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESVerifier_AddRefsOnlyTimestamp(_Handle, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
SB_INLINE int32_t TElXAdESVerifier::AddSigAndRefsTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESVerifier_AddSigAndRefsTimestamp(_Handle, ATSPClient.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXAdESVerifier::AddSigAndRefsTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESVerifier_AddSigAndRefsTimestamp(_Handle, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
SB_INLINE int32_t TElXAdESVerifier::AddArchiveTimestamp(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESVerifier_AddArchiveTimestamp(_Handle, ATSPClient.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXAdESVerifier::AddArchiveTimestamp(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESVerifier_AddArchiveTimestamp(_Handle, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE int32_t TElXAdESVerifier::AddArchiveTimestampV141(TElCustomTSPClient &ATSPClient)
{
	int32_t OutResult;
	SBCheckError(TElXAdESVerifier_AddArchiveTimestampV141(_Handle, ATSPClient.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXAdESVerifier::AddArchiveTimestampV141(TElCustomTSPClient *ATSPClient)
{
	int32_t OutResult;
	SBCheckError(TElXAdESVerifier_AddArchiveTimestampV141(_Handle, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER
SB_INLINE int32_t TElXAdESVerifier::AddArchiveTimestampV141(TElCustomTSPClient &ATSPClient, TElXMLCustomFormatter &Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESVerifier_AddArchiveTimestampV141_1(_Handle, ATSPClient.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXAdESVerifier::AddArchiveTimestampV141(TElCustomTSPClient *ATSPClient, TElXMLCustomFormatter *Formatter)
{
	int32_t OutResult;
	SBCheckError(TElXAdESVerifier_AddArchiveTimestampV141_1(_Handle, (ATSPClient != NULL) ? ATSPClient->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELXMLCUSTOMFORMATTER
TSBXAdESValidity TElXAdESVerifier::AddTimestampValidationData(TElXMLCustomFormatter &Formatter)
{
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESVerifier_AddTimestampValidationData(_Handle, Formatter.getHandle(), &OutResultRaw));
	return (TSBXAdESValidity)OutResultRaw;
}

TSBXAdESValidity TElXAdESVerifier::AddTimestampValidationData(TElXMLCustomFormatter *Formatter)
{
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESVerifier_AddTimestampValidationData(_Handle, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBXAdESValidity)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
bool TElXAdESVerifier::CheckTimestamp(TElClientTSPInfo &Info)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXAdESVerifier_CheckTimestamp(_Handle, Info.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXAdESVerifier::CheckTimestamp(TElClientTSPInfo *Info)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXAdESVerifier_CheckTimestamp(_Handle, (Info != NULL) ? Info->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElXAdESVerifier::ExtractAllCertificates(TElCustomCertStorage &Certs)
{
	SBCheckError(TElXAdESVerifier_ExtractAllCertificates(_Handle, Certs.getHandle()));
}

SB_INLINE void TElXAdESVerifier::ExtractAllCertificates(TElCustomCertStorage *Certs)
{
	SBCheckError(TElXAdESVerifier_ExtractAllCertificates(_Handle, (Certs != NULL) ? Certs->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

SB_INLINE void TElXAdESVerifier::UpgradeToXAdESv141()
{
	SBCheckError(TElXAdESVerifier_UpgradeToXAdESv141(_Handle));
}

TSBXAdESValidity TElXAdESVerifier::Validate(TSBXAdESValidityReasons &Reasons)
{
	TSBXAdESValidityReasonsRaw ReasonsRaw = (TSBXAdESValidityReasonsRaw)Reasons;
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESVerifier_Validate(_Handle, &ReasonsRaw, &OutResultRaw));
	Reasons = (TSBXAdESValidityReasons)ReasonsRaw;
	return (TSBXAdESValidity)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TSBXAdESValidity TElXAdESVerifier::Validate(TElX509Certificate &SigningCertificate, TSBXAdESValidityReasons &Reasons)
{
	TSBXAdESValidityReasonsRaw ReasonsRaw = (TSBXAdESValidityReasonsRaw)Reasons;
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESVerifier_Validate_1(_Handle, SigningCertificate.getHandle(), &ReasonsRaw, &OutResultRaw));
	Reasons = (TSBXAdESValidityReasons)ReasonsRaw;
	return (TSBXAdESValidity)OutResultRaw;
}

TSBXAdESValidity TElXAdESVerifier::Validate(TElX509Certificate *SigningCertificate, TSBXAdESValidityReasons &Reasons)
{
	TSBXAdESValidityReasonsRaw ReasonsRaw = (TSBXAdESValidityReasonsRaw)Reasons;
	TSBXAdESValidityRaw OutResultRaw = 0;
	SBCheckError(TElXAdESVerifier_Validate_1(_Handle, (SigningCertificate != NULL) ? SigningCertificate->getHandle() : SB_NULL_HANDLE, &ReasonsRaw, &OutResultRaw));
	Reasons = (TSBXAdESValidityReasons)ReasonsRaw;
	return (TSBXAdESValidity)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

bool TElXAdESVerifier::get_IsEnabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXAdESVerifier_get_IsEnabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElXAdESIncludedProperties TElXAdESVerifier::get_Included()
{
	TElXAdESIncludedPropertiesRaw OutResultRaw = 0;
	SBCheckError(TElXAdESVerifier_get_Included(_Handle, &OutResultRaw));
	return (TElXAdESIncludedProperties)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELXMLCERTID
TElXMLCertID* TElXAdESVerifier::get_CertIDs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESVerifier_get_CertIDs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertIDs)
		this->_Inst_CertIDs = new TElXMLCertID(hOutResult, ohFalse);
	else
		this->_Inst_CertIDs->updateHandle(hOutResult);
	return this->_Inst_CertIDs;
}
#endif /* SB_USE_CLASS_TELXMLCERTID */

SB_INLINE int32_t TElXAdESVerifier::get_CertIDCount()
{
	int32_t OutResult;
	SBCheckError(TElXAdESVerifier_get_CertIDCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYID
TElXMLSignaturePolicyId* TElXAdESVerifier::get_PolicyId()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESVerifier_get_PolicyId(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PolicyId)
		this->_Inst_PolicyId = new TElXMLSignaturePolicyId(hOutResult, ohFalse);
	else
		this->_Inst_PolicyId->updateHandle(hOutResult);
	return this->_Inst_PolicyId;
}
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYID */

#ifdef SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE
TElXMLSignatureProductionPlace* TElXAdESVerifier::get_ProductionPlace()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESVerifier_get_ProductionPlace(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ProductionPlace)
		this->_Inst_ProductionPlace = new TElXMLSignatureProductionPlace(hOutResult, ohFalse);
	else
		this->_Inst_ProductionPlace->updateHandle(hOutResult);
	return this->_Inst_ProductionPlace;
}
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE */

#ifdef SB_USE_CLASS_TELXMLSIGNERROLE
TElXMLSignerRole* TElXAdESVerifier::get_SignerRole()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESVerifier_get_SignerRole(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignerRole)
		this->_Inst_SignerRole = new TElXMLSignerRole(hOutResult, ohFalse);
	else
		this->_Inst_SignerRole->updateHandle(hOutResult);
	return this->_Inst_SignerRole;
}
#endif /* SB_USE_CLASS_TELXMLSIGNERROLE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElXAdESVerifier::get_SigningCertificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESVerifier_get_SigningCertificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigningCertificates)
		this->_Inst_SigningCertificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_SigningCertificates->updateHandle(hOutResult);
	return this->_Inst_SigningCertificates;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

SB_INLINE int64_t TElXAdESVerifier::get_SigningTime()
{
	int64_t OutResult;
	SBCheckError(TElXAdESVerifier_get_SigningTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElXAdESVerifier::get_CertifiedSigningTime()
{
	int64_t OutResult;
	SBCheckError(TElXAdESVerifier_get_CertifiedSigningTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElXAdESVerifier::get_LastArchivalTime()
{
	int64_t OutResult;
	SBCheckError(TElXAdESVerifier_get_LastArchivalTime(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
TElClientTSPInfo* TElXAdESVerifier::get_Timestamp()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESVerifier_get_Timestamp(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Timestamp)
		this->_Inst_Timestamp = new TElClientTSPInfo(hOutResult, ohFalse);
	else
		this->_Inst_Timestamp->updateHandle(hOutResult);
	return this->_Inst_Timestamp;
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

SB_INLINE int32_t TElXAdESVerifier::get_IndividualDataObjectsTimestampCount()
{
	int32_t OutResult;
	SBCheckError(TElXAdESVerifier_get_IndividualDataObjectsTimestampCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
TElClientTSPInfo* TElXAdESVerifier::get_IndividualDataObjectsTimestamps(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESVerifier_get_IndividualDataObjectsTimestamps(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IndividualDataObjectsTimestamps)
		this->_Inst_IndividualDataObjectsTimestamps = new TElClientTSPInfo(hOutResult, ohFalse);
	else
		this->_Inst_IndividualDataObjectsTimestamps->updateHandle(hOutResult);
	return this->_Inst_IndividualDataObjectsTimestamps;
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

SB_INLINE int32_t TElXAdESVerifier::get_AllDataObjectsTimestampCount()
{
	int32_t OutResult;
	SBCheckError(TElXAdESVerifier_get_AllDataObjectsTimestampCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
TElClientTSPInfo* TElXAdESVerifier::get_AllDataObjectsTimestamps(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESVerifier_get_AllDataObjectsTimestamps(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AllDataObjectsTimestamps)
		this->_Inst_AllDataObjectsTimestamps = new TElClientTSPInfo(hOutResult, ohFalse);
	else
		this->_Inst_AllDataObjectsTimestamps->updateHandle(hOutResult);
	return this->_Inst_AllDataObjectsTimestamps;
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

SB_INLINE int32_t TElXAdESVerifier::get_SignatureTimestampCount()
{
	int32_t OutResult;
	SBCheckError(TElXAdESVerifier_get_SignatureTimestampCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
TElClientTSPInfo* TElXAdESVerifier::get_SignatureTimestamps(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESVerifier_get_SignatureTimestamps(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureTimestamps)
		this->_Inst_SignatureTimestamps = new TElClientTSPInfo(hOutResult, ohFalse);
	else
		this->_Inst_SignatureTimestamps->updateHandle(hOutResult);
	return this->_Inst_SignatureTimestamps;
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

SB_INLINE int32_t TElXAdESVerifier::get_RefsOnlyTimestampCount()
{
	int32_t OutResult;
	SBCheckError(TElXAdESVerifier_get_RefsOnlyTimestampCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
TElClientTSPInfo* TElXAdESVerifier::get_RefsOnlyTimestamps(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESVerifier_get_RefsOnlyTimestamps(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RefsOnlyTimestamps)
		this->_Inst_RefsOnlyTimestamps = new TElClientTSPInfo(hOutResult, ohFalse);
	else
		this->_Inst_RefsOnlyTimestamps->updateHandle(hOutResult);
	return this->_Inst_RefsOnlyTimestamps;
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

SB_INLINE int32_t TElXAdESVerifier::get_SigAndRefsTimestampCount()
{
	int32_t OutResult;
	SBCheckError(TElXAdESVerifier_get_SigAndRefsTimestampCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
TElClientTSPInfo* TElXAdESVerifier::get_SigAndRefsTimestamps(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESVerifier_get_SigAndRefsTimestamps(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigAndRefsTimestamps)
		this->_Inst_SigAndRefsTimestamps = new TElClientTSPInfo(hOutResult, ohFalse);
	else
		this->_Inst_SigAndRefsTimestamps->updateHandle(hOutResult);
	return this->_Inst_SigAndRefsTimestamps;
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

SB_INLINE int32_t TElXAdESVerifier::get_ArchiveTimestampCount()
{
	int32_t OutResult;
	SBCheckError(TElXAdESVerifier_get_ArchiveTimestampCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
TElClientTSPInfo* TElXAdESVerifier::get_ArchiveTimestamps(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESVerifier_get_ArchiveTimestamps(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ArchiveTimestamps)
		this->_Inst_ArchiveTimestamps = new TElClientTSPInfo(hOutResult, ohFalse);
	else
		this->_Inst_ArchiveTimestamps->updateHandle(hOutResult);
	return this->_Inst_ArchiveTimestamps;
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST
TElXMLTimeStampValidationDataList* TElXAdESVerifier::get_TimeStampValidationDataList()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESVerifier_get_TimeStampValidationDataList(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TimeStampValidationDataList)
		this->_Inst_TimeStampValidationDataList = new TElXMLTimeStampValidationDataList(hOutResult, ohFalse);
	else
		this->_Inst_TimeStampValidationDataList->updateHandle(hOutResult);
	return this->_Inst_TimeStampValidationDataList;
}
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES
TElXMLQualifyingProperties* TElXAdESVerifier::get_QualifyingProperties()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESVerifier_get_QualifyingProperties(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_QualifyingProperties)
		this->_Inst_QualifyingProperties = new TElXMLQualifyingProperties(hOutResult, ohFalse);
	else
		this->_Inst_QualifyingProperties->updateHandle(hOutResult);
	return this->_Inst_QualifyingProperties;
}
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST
TElXMLQualifyingPropertiesReferenceList* TElXAdESVerifier::get_QualifyingPropertiesReferences()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESVerifier_get_QualifyingPropertiesReferences(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_QualifyingPropertiesReferences)
		this->_Inst_QualifyingPropertiesReferences = new TElXMLQualifyingPropertiesReferenceList(hOutResult, ohFalse);
	else
		this->_Inst_QualifyingPropertiesReferences->updateHandle(hOutResult);
	return this->_Inst_QualifyingPropertiesReferences;
}
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST */

TSBXAdESForm TElXAdESVerifier::get_XAdESForm()
{
	TSBXAdESFormRaw OutResultRaw = 0;
	SBCheckError(TElXAdESVerifier_get_XAdESForm(_Handle, &OutResultRaw));
	return (TSBXAdESForm)OutResultRaw;
}

TSBXAdESVersion TElXAdESVerifier::get_XAdESVersion()
{
	TSBXAdESVersionRaw OutResultRaw = 0;
	SBCheckError(TElXAdESVerifier_get_XAdESVersion(_Handle, &OutResultRaw));
	return (TSBXAdESVersion)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElXAdESVerifier::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXAdESVerifier_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElXAdESVerifier::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElXAdESVerifier_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElXAdESVerifier::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElXAdESVerifier_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

SB_INLINE void TElXAdESVerifier::get_OnRetrieveCertificate(TSBXAdESRetrieveCertificateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXAdESVerifier_get_OnRetrieveCertificate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXAdESVerifier::set_OnRetrieveCertificate(TSBXAdESRetrieveCertificateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXAdESVerifier_set_OnRetrieveCertificate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElXAdESVerifier::get_OnRetrieveCRL(TSBXAdESRetrieveCRLEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXAdESVerifier_get_OnRetrieveCRL(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXAdESVerifier::set_OnRetrieveCRL(TSBXAdESRetrieveCRLEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXAdESVerifier_set_OnRetrieveCRL(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElXAdESVerifier::get_OnRetrieveOCSPResponse(TSBXAdESRetrieveOCSPResponseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElXAdESVerifier_get_OnRetrieveOCSPResponse(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElXAdESVerifier::set_OnRetrieveOCSPResponse(TSBXAdESRetrieveOCSPResponseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElXAdESVerifier_set_OnRetrieveOCSPResponse(_Handle, pMethodValue, pDataValue));
}

void TElXAdESVerifier::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLCERTID
	this->_Inst_CertIDs = NULL;
#endif /* SB_USE_CLASS_TELXMLCERTID */
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYID
	this->_Inst_PolicyId = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYID */
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE
	this->_Inst_ProductionPlace = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE */
#ifdef SB_USE_CLASS_TELXMLSIGNERROLE
	this->_Inst_SignerRole = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNERROLE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_SigningCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	this->_Inst_Timestamp = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	this->_Inst_IndividualDataObjectsTimestamps = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	this->_Inst_AllDataObjectsTimestamps = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	this->_Inst_SignatureTimestamps = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	this->_Inst_RefsOnlyTimestamps = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	this->_Inst_SigAndRefsTimestamps = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	this->_Inst_ArchiveTimestamps = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST
	this->_Inst_TimeStampValidationDataList = NULL;
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST */
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES
	this->_Inst_QualifyingProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES */
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST
	this->_Inst_QualifyingPropertiesReferences = NULL;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElXAdESVerifier::TElXAdESVerifier(TElXAdESVerifierHandle handle, TElOwnHandle ownHandle) : TElXAdESProcessor(handle, ownHandle)
{
	initInstances();
}

TElXAdESVerifier::TElXAdESVerifier(TComponent &AOwner) : TElXAdESProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXAdESVerifier_Create(AOwner.getHandle(), &_Handle));
}

TElXAdESVerifier::TElXAdESVerifier(TComponent *AOwner) : TElXAdESProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXAdESVerifier_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElXAdESVerifier::~TElXAdESVerifier()
{
#ifdef SB_USE_CLASS_TELXMLCERTID
	delete this->_Inst_CertIDs;
	this->_Inst_CertIDs = NULL;
#endif /* SB_USE_CLASS_TELXMLCERTID */
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPOLICYID
	delete this->_Inst_PolicyId;
	this->_Inst_PolicyId = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPOLICYID */
#ifdef SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE
	delete this->_Inst_ProductionPlace;
	this->_Inst_ProductionPlace = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNATUREPRODUCTIONPLACE */
#ifdef SB_USE_CLASS_TELXMLSIGNERROLE
	delete this->_Inst_SignerRole;
	this->_Inst_SignerRole = NULL;
#endif /* SB_USE_CLASS_TELXMLSIGNERROLE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_SigningCertificates;
	this->_Inst_SigningCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	delete this->_Inst_Timestamp;
	this->_Inst_Timestamp = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	delete this->_Inst_IndividualDataObjectsTimestamps;
	this->_Inst_IndividualDataObjectsTimestamps = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	delete this->_Inst_AllDataObjectsTimestamps;
	this->_Inst_AllDataObjectsTimestamps = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	delete this->_Inst_SignatureTimestamps;
	this->_Inst_SignatureTimestamps = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	delete this->_Inst_RefsOnlyTimestamps;
	this->_Inst_RefsOnlyTimestamps = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	delete this->_Inst_SigAndRefsTimestamps;
	this->_Inst_SigAndRefsTimestamps = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	delete this->_Inst_ArchiveTimestamps;
	this->_Inst_ArchiveTimestamps = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST
	delete this->_Inst_TimeStampValidationDataList;
	this->_Inst_TimeStampValidationDataList = NULL;
#endif /* SB_USE_CLASS_TELXMLTIMESTAMPVALIDATIONDATALIST */
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES
	delete this->_Inst_QualifyingProperties;
	this->_Inst_QualifyingProperties = NULL;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIES */
#ifdef SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST
	delete this->_Inst_QualifyingPropertiesReferences;
	this->_Inst_QualifyingPropertiesReferences = NULL;
#endif /* SB_USE_CLASS_TELXMLQUALIFYINGPROPERTIESREFERENCELIST */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELXADESVERIFIER */

};	/* namespace SecureBlackbox */

