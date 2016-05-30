#include "sbcades.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELCADESREVOCATIONINFO

SB_INLINE void TElCAdESRevocationInfo::Assign(TElCAdESRevocationInfo &Source, bool Clear)
{
	SBCheckError(TElCAdESRevocationInfo_Assign(_Handle, Source.getHandle(), (int8_t)Clear));
}

SB_INLINE void TElCAdESRevocationInfo::Assign(TElCAdESRevocationInfo *Source, bool Clear)
{
	SBCheckError(TElCAdESRevocationInfo_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)Clear));
}

SB_INLINE void TElCAdESRevocationInfo::Clear()
{
	SBCheckError(TElCAdESRevocationInfo_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
SB_INLINE int32_t TElCAdESRevocationInfo::AddOCSPResponse(TElOCSPResponse &Resp)
{
	int32_t OutResult;
	SBCheckError(TElCAdESRevocationInfo_AddOCSPResponse(_Handle, Resp.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCAdESRevocationInfo::AddOCSPResponse(TElOCSPResponse *Resp)
{
	int32_t OutResult;
	SBCheckError(TElCAdESRevocationInfo_AddOCSPResponse(_Handle, (Resp != NULL) ? Resp->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

SB_INLINE void TElCAdESRevocationInfo::RemoveOCSPResponse(int32_t Index)
{
	SBCheckError(TElCAdESRevocationInfo_RemoveOCSPResponse(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
TElMemoryCertStorage* TElCAdESRevocationInfo::get_Certificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCAdESRevocationInfo_get_Certificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElMemoryCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
TElMemoryCRLStorage* TElCAdESRevocationInfo::get_CRLs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCAdESRevocationInfo_get_CRLs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLs)
		this->_Inst_CRLs = new TElMemoryCRLStorage(hOutResult, ohFalse);
	else
		this->_Inst_CRLs->updateHandle(hOutResult);
	return this->_Inst_CRLs;
}
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
TElOCSPResponse* TElCAdESRevocationInfo::get_OCSPResponses(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCAdESRevocationInfo_get_OCSPResponses(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OCSPResponses)
		this->_Inst_OCSPResponses = new TElOCSPResponse(hOutResult, ohFalse);
	else
		this->_Inst_OCSPResponses->updateHandle(hOutResult);
	return this->_Inst_OCSPResponses;
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

SB_INLINE int32_t TElCAdESRevocationInfo::get_OCSPResponseCount()
{
	int32_t OutResult;
	SBCheckError(TElCAdESRevocationInfo_get_OCSPResponseCount(_Handle, &OutResult));
	return OutResult;
}

void TElCAdESRevocationInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
	this->_Inst_CRLs = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELOCSPRESPONSE
	this->_Inst_OCSPResponses = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */
}

TElCAdESRevocationInfo::TElCAdESRevocationInfo(TElCAdESRevocationInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCAdESRevocationInfo::TElCAdESRevocationInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCAdESRevocationInfo_Create(&_Handle));
}

TElCAdESRevocationInfo::~TElCAdESRevocationInfo()
{
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
	delete this->_Inst_CRLs;
	this->_Inst_CRLs = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELOCSPRESPONSE
	delete this->_Inst_OCSPResponses;
	this->_Inst_OCSPResponses = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */
}
#endif /* SB_USE_CLASS_TELCADESREVOCATIONINFO */

#ifdef SB_USE_CLASS_TELCADESSIGNATUREPROCESSOR

TSBCAdESSignatureValidity TElCAdESSignatureProcessor::Validate()
{
	TSBCAdESSignatureValidityRaw OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_Validate(_Handle, &OutResultRaw));
	return (TSBCAdESSignatureValidity)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELCMSTIMESTAMP
TSBCAdESSignatureValidity TElCAdESSignatureProcessor::Validate(TElCMSTimestamp &ArchivalTimestamp)
{
	TSBCAdESSignatureValidityRaw OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_Validate_1(_Handle, ArchivalTimestamp.getHandle(), &OutResultRaw));
	return (TSBCAdESSignatureValidity)OutResultRaw;
}

TSBCAdESSignatureValidity TElCAdESSignatureProcessor::Validate(TElCMSTimestamp *ArchivalTimestamp)
{
	TSBCAdESSignatureValidityRaw OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_Validate_1(_Handle, (ArchivalTimestamp != NULL) ? ArchivalTimestamp->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBCAdESSignatureValidity)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELCMSTIMESTAMP */

SB_INLINE void TElCAdESSignatureProcessor::UpdateValidationInformation(bool UpdateRefs, bool UpdateValues)
{
	SBCheckError(TElCAdESSignatureProcessor_UpdateValidationInformation(_Handle, (int8_t)UpdateRefs, (int8_t)UpdateValues));
}

SB_INLINE void TElCAdESSignatureProcessor::UpdateValidationInformation(bool UpdateRefs, bool UpdateValues, bool BaselineProfileMode)
{
	SBCheckError(TElCAdESSignatureProcessor_UpdateValidationInformation_1(_Handle, (int8_t)UpdateRefs, (int8_t)UpdateValues, (int8_t)BaselineProfileMode));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateBES(TElX509Certificate &Cert)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBES(_Handle, Cert.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateBES(TElX509Certificate *Cert)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBES(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateBES(TElX509Certificate &Cert, TElCustomCertStorage &Chain)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBES_1(_Handle, Cert.getHandle(), Chain.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateBES(TElX509Certificate *Cert, TElCustomCertStorage *Chain)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBES_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateBES(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBES_2(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateBES(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBES_2(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size()));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateEPES(TElX509Certificate &Cert, const std::vector<uint8_t> &PolicyID, int32_t PolicyHashAlg, const std::vector<uint8_t> &PolicyHash)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateEPES(_Handle, Cert.getHandle(), SB_STD_VECTOR_FRONT_ADR(PolicyID), (int32_t)PolicyID.size(), PolicyHashAlg, SB_STD_VECTOR_FRONT_ADR(PolicyHash), (int32_t)PolicyHash.size()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateEPES(TElX509Certificate *Cert, const std::vector<uint8_t> &PolicyID, int32_t PolicyHashAlg, const std::vector<uint8_t> &PolicyHash)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateEPES(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(PolicyID), (int32_t)PolicyID.size(), PolicyHashAlg, SB_STD_VECTOR_FRONT_ADR(PolicyHash), (int32_t)PolicyHash.size()));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateEPES(TElX509Certificate &Cert, const std::vector<uint8_t> &ContentType, const std::vector<uint8_t> &PolicyID, int32_t PolicyHashAlg, const std::vector<uint8_t> &PolicyHash)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateEPES_1(_Handle, Cert.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), SB_STD_VECTOR_FRONT_ADR(PolicyID), (int32_t)PolicyID.size(), PolicyHashAlg, SB_STD_VECTOR_FRONT_ADR(PolicyHash), (int32_t)PolicyHash.size()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateEPES(TElX509Certificate *Cert, const std::vector<uint8_t> &ContentType, const std::vector<uint8_t> &PolicyID, int32_t PolicyHashAlg, const std::vector<uint8_t> &PolicyHash)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateEPES_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), SB_STD_VECTOR_FRONT_ADR(PolicyID), (int32_t)PolicyID.size(), PolicyHashAlg, SB_STD_VECTOR_FRONT_ADR(PolicyHash), (int32_t)PolicyHash.size()));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateEPES(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, const std::vector<uint8_t> &PolicyID, int32_t PolicyHashAlg, const std::vector<uint8_t> &PolicyHash, const std::string &URI, const std::string &UNOrganization, const std::vector<int32_t> &UNNumbers, const std::string &ExplicitText)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateEPES_2(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), SB_STD_VECTOR_FRONT_ADR(PolicyID), (int32_t)PolicyID.size(), PolicyHashAlg, SB_STD_VECTOR_FRONT_ADR(PolicyHash), (int32_t)PolicyHash.size(), URI.data(), (int32_t)URI.length(), UNOrganization.data(), (int32_t)UNOrganization.length(), SB_STD_VECTOR_FRONT_ADR(UNNumbers), (int32_t)UNNumbers.size(), ExplicitText.data(), (int32_t)ExplicitText.length()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateEPES(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, const std::vector<uint8_t> &PolicyID, int32_t PolicyHashAlg, const std::vector<uint8_t> &PolicyHash, const std::string &URI, const std::string &UNOrganization, const std::vector<int32_t> &UNNumbers, const std::string &ExplicitText)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateEPES_2(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), SB_STD_VECTOR_FRONT_ADR(PolicyID), (int32_t)PolicyID.size(), PolicyHashAlg, SB_STD_VECTOR_FRONT_ADR(PolicyHash), (int32_t)PolicyHash.size(), URI.data(), (int32_t)URI.length(), UNOrganization.data(), (int32_t)UNOrganization.length(), SB_STD_VECTOR_FRONT_ADR(UNNumbers), (int32_t)UNNumbers.size(), ExplicitText.data(), (int32_t)ExplicitText.length()));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateT(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateT(_Handle, Cert.getHandle(), TSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateT(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateT(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateT(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient &TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateT_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), TSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateT(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient *TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateT_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateC(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateC(_Handle, Cert.getHandle(), TSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateC(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateC(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateC(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient &TSPClient, bool InsertCertAndRevValues)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateC_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), TSPClient.getHandle(), (int8_t)InsertCertAndRevValues));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateC(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient *TSPClient, bool InsertCertAndRevValues)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateC_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (int8_t)InsertCertAndRevValues));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateXType1(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXType1(_Handle, Cert.getHandle(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateXType1(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXType1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateXType1(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXType1_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateXType1(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXType1_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateXType2(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXType2(_Handle, Cert.getHandle(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateXType2(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXType2(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateXType2(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXType2_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateXType2(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXType2_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateX(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateX(_Handle, Cert.getHandle(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateX(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateX(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateX(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateX_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateX(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateX_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateXLType1(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXLType1(_Handle, Cert.getHandle(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateXLType1(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXLType1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateXLType1(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXLType1_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateXLType1(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXLType1_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateXLType2(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXLType2(_Handle, Cert.getHandle(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateXLType2(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXLType2(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateXLType2(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXLType2_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateXLType2(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXLType2_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateXL(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXL(_Handle, Cert.getHandle(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateXL(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXL(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateXL(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXL_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateXL(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXL_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateXLBase(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXLBase(_Handle, Cert.getHandle(), TSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateXLBase(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXLBase(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateXLBase(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient &TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXLBase_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), TSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateXLBase(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient *TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateXLBase_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateBaselineB(TElX509Certificate &Cert)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBaselineB(_Handle, Cert.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateBaselineB(TElX509Certificate *Cert)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBaselineB(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateBaselineB(TElX509Certificate &Cert, TElCustomCertStorage &Chain)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBaselineB_1(_Handle, Cert.getHandle(), Chain.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateBaselineB(TElX509Certificate *Cert, TElCustomCertStorage *Chain)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBaselineB_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateBaselineB(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBaselineB_2(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateBaselineB(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBaselineB_2(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size()));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateBaselineT(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBaselineT(_Handle, Cert.getHandle(), TSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateBaselineT(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBaselineT(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateBaselineT(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient &TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBaselineT_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), TSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateBaselineT(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient *TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBaselineT_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateBaselineLT(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBaselineLT(_Handle, Cert.getHandle(), TSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateBaselineLT(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBaselineLT(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateBaselineLT(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient &TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBaselineLT_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), TSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateBaselineLT(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient *TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBaselineLT_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateBaselineLTA(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBaselineLTA(_Handle, Cert.getHandle(), TSPClient.getHandle(), ArchivalTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateBaselineLTA(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBaselineLTA(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ArchivalTSPClient != NULL) ? ArchivalTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateBaselineLTA(TElX509Certificate &Cert, TElCustomCertStorage &Chain, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBaselineLTA_1(_Handle, Cert.getHandle(), Chain.getHandle(), TSPClient.getHandle(), ArchivalTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateBaselineLTA(TElX509Certificate *Cert, TElCustomCertStorage *Chain, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateBaselineLTA_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ArchivalTSPClient != NULL) ? ArchivalTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedBES(TElX509Certificate &Cert)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedBES(_Handle, Cert.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedBES(TElX509Certificate *Cert)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedBES(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedBES(TElX509Certificate &Cert, TElCustomCertStorage &Chain)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedBES_1(_Handle, Cert.getHandle(), Chain.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedBES(TElX509Certificate *Cert, TElCustomCertStorage *Chain)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedBES_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedBES(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedBES_2(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedBES(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedBES_2(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size()));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedEPES(TElX509Certificate &Cert, const std::vector<uint8_t> &PolicyID, int32_t PolicyHashAlg, const std::vector<uint8_t> &PolicyHash)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedEPES(_Handle, Cert.getHandle(), SB_STD_VECTOR_FRONT_ADR(PolicyID), (int32_t)PolicyID.size(), PolicyHashAlg, SB_STD_VECTOR_FRONT_ADR(PolicyHash), (int32_t)PolicyHash.size()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedEPES(TElX509Certificate *Cert, const std::vector<uint8_t> &PolicyID, int32_t PolicyHashAlg, const std::vector<uint8_t> &PolicyHash)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedEPES(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(PolicyID), (int32_t)PolicyID.size(), PolicyHashAlg, SB_STD_VECTOR_FRONT_ADR(PolicyHash), (int32_t)PolicyHash.size()));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedEPES(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, const std::vector<uint8_t> &PolicyID, int32_t PolicyHashAlg, const std::vector<uint8_t> &PolicyHash, const std::string &URI, const std::string &UNOrganization, const std::vector<int32_t> &UNNumbers, const std::string &ExplicitText)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedEPES_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), SB_STD_VECTOR_FRONT_ADR(PolicyID), (int32_t)PolicyID.size(), PolicyHashAlg, SB_STD_VECTOR_FRONT_ADR(PolicyHash), (int32_t)PolicyHash.size(), URI.data(), (int32_t)URI.length(), UNOrganization.data(), (int32_t)UNOrganization.length(), SB_STD_VECTOR_FRONT_ADR(UNNumbers), (int32_t)UNNumbers.size(), ExplicitText.data(), (int32_t)ExplicitText.length()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedEPES(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, const std::vector<uint8_t> &PolicyID, int32_t PolicyHashAlg, const std::vector<uint8_t> &PolicyHash, const std::string &URI, const std::string &UNOrganization, const std::vector<int32_t> &UNNumbers, const std::string &ExplicitText)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedEPES_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), SB_STD_VECTOR_FRONT_ADR(PolicyID), (int32_t)PolicyID.size(), PolicyHashAlg, SB_STD_VECTOR_FRONT_ADR(PolicyHash), (int32_t)PolicyHash.size(), URI.data(), (int32_t)URI.length(), UNOrganization.data(), (int32_t)UNOrganization.length(), SB_STD_VECTOR_FRONT_ADR(UNNumbers), (int32_t)UNNumbers.size(), ExplicitText.data(), (int32_t)ExplicitText.length()));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedT(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedT(_Handle, Cert.getHandle(), TSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedT(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedT(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedT(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient &TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedT_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), TSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedT(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient *TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedT_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedC(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedC(_Handle, Cert.getHandle(), TSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedC(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedC(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedC(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient &TSPClient, bool InsertCertAndRevValues)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedC_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), TSPClient.getHandle(), (int8_t)InsertCertAndRevValues));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedC(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient *TSPClient, bool InsertCertAndRevValues)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedC_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (int8_t)InsertCertAndRevValues));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXType1(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXType1(_Handle, Cert.getHandle(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXType1(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXType1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXType1(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXType1_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXType1(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXType1_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXType2(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXType2(_Handle, Cert.getHandle(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXType2(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXType2(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXType2(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXType2_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXType2(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXType2_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedX(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedX(_Handle, Cert.getHandle(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedX(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedX(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedX(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedX_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedX(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedX_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXLType1(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXLType1(_Handle, Cert.getHandle(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXLType1(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXLType1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXLType1(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXLType1_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXLType1(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXLType1_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXLType2(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXLType2(_Handle, Cert.getHandle(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXLType2(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXLType2(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXLType2(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXLType2_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXLType2(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXLType2_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXL(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXL(_Handle, Cert.getHandle(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXL(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXL(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXL(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXL_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXL(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXL_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXLBase(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXLBase(_Handle, Cert.getHandle(), TSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXLBase(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXLBase(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXLBase(TElX509Certificate &Cert, TElCustomCertStorage &Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient &TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXLBase_1(_Handle, Cert.getHandle(), Chain.getHandle(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), TSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedXLBase(TElX509Certificate *Cert, TElCustomCertStorage *Chain, const std::vector<uint8_t> &ContentType, TElCustomTSPClient *TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedXLBase_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedA(TElX509Certificate &Cert, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedA(_Handle, Cert.getHandle(), TSPClient.getHandle(), ArchivalTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedA(TElX509Certificate *Cert, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedA(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ArchivalTSPClient != NULL) ? ArchivalTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedA(TElX509Certificate &Cert, TElCustomCertStorage &Chain, TElCustomTSPClient &TSPClient, TElCustomTSPClient &ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedA_1(_Handle, Cert.getHandle(), Chain.getHandle(), TSPClient.getHandle(), ArchivalTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::CreateExtendedA(TElX509Certificate *Cert, TElCustomCertStorage *Chain, TElCustomTSPClient *TSPClient, TElCustomTSPClient *ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_CreateExtendedA_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ArchivalTSPClient != NULL) ? ArchivalTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

bool TElCAdESSignatureProcessor::CanUpgradeToT()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_CanUpgradeToT(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::CanUpgradeToC()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_CanUpgradeToC(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::CanUpgradeToX()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_CanUpgradeToX(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::CanUpgradeToXType1()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_CanUpgradeToXType1(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::CanUpgradeToXType2()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_CanUpgradeToXType2(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::CanUpgradeToXL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_CanUpgradeToXL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::CanUpgradeToXLType1()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_CanUpgradeToXLType1(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::CanUpgradeToXLType2()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_CanUpgradeToXLType2(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::CanUpgradeToA()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_CanUpgradeToA(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::CanUpgradeToBaselineLTA()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_CanUpgradeToBaselineLTA(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::CanUpgradeToExtendedT()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_CanUpgradeToExtendedT(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::CanUpgradeToExtendedC()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_CanUpgradeToExtendedC(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::CanUpgradeToExtendedX()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_CanUpgradeToExtendedX(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::CanUpgradeToExtendedXType1()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_CanUpgradeToExtendedXType1(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::CanUpgradeToExtendedXType2()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_CanUpgradeToExtendedXType2(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::CanUpgradeToExtendedXL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_CanUpgradeToExtendedXL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::CanUpgradeToExtendedXLType1()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_CanUpgradeToExtendedXLType1(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::CanUpgradeToExtendedXLType2()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_CanUpgradeToExtendedXLType2(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::CanUpgradeToExtendedA()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_CanUpgradeToExtendedA(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToT(TElCustomTSPClient &TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToT(_Handle, TSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToT(TElCustomTSPClient *TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToT(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToC()
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToC(_Handle));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToC(bool InsertCertAndRevValues)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToC_1(_Handle, (int8_t)InsertCertAndRevValues));
}

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToC(TElCustomTSPClient &TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToC_2(_Handle, TSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToC(TElCustomTSPClient *TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToC_2(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToC(TElCustomTSPClient &TSPClient, bool InsertCertAndRevValues)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToC_3(_Handle, TSPClient.getHandle(), (int8_t)InsertCertAndRevValues));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToC(TElCustomTSPClient *TSPClient, bool InsertCertAndRevValues)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToC_3(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (int8_t)InsertCertAndRevValues));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToX(TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToX(_Handle, ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToX(TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToX(_Handle, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToX(TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToX_1(_Handle, TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToX(TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToX_1(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXType1(TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXType1(_Handle, ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXType1(TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXType1(_Handle, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXType1(TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXType1_1(_Handle, TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXType1(TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXType1_1(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXType2(TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXType2(_Handle, ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXType2(TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXType2(_Handle, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXType2(TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXType2_1(_Handle, TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXType2(TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXType2_1(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXL(TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXL(_Handle, ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXL(TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXL(_Handle, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXL(TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXL_1(_Handle, TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXL(TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXL_1(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXLBase()
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXLBase(_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXLBase(TElCustomTSPClient &TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXLBase_1(_Handle, TSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXLBase(TElCustomTSPClient *TSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXLBase_1(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXLType1(TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXLType1(_Handle, ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXLType1(TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXLType1(_Handle, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXLType1(TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXLType1_1(_Handle, TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXLType1(TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXLType1_1(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXLType2(TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXLType2(_Handle, ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXLType2(TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXLType2(_Handle, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXLType2(TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXLType2_1(_Handle, TSPClient.getHandle(), ValidationTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToXLType2(TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToXLType2_1(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToA(TElCustomTSPClient &ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToA(_Handle, ArchivalTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToA(TElCustomTSPClient *ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToA(_Handle, (ArchivalTSPClient != NULL) ? ArchivalTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToA(TElCustomTSPClient &ValidationTSPClient, TElCustomTSPClient &ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToA_1(_Handle, ValidationTSPClient.getHandle(), ArchivalTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToA(TElCustomTSPClient *ValidationTSPClient, TElCustomTSPClient *ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToA_1(_Handle, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE, (ArchivalTSPClient != NULL) ? ArchivalTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToA(TElCustomTSPClient &TSPClient, TElCustomTSPClient &ValidationTSPClient, TElCustomTSPClient &ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToA_2(_Handle, TSPClient.getHandle(), ValidationTSPClient.getHandle(), ArchivalTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToA(TElCustomTSPClient *TSPClient, TElCustomTSPClient *ValidationTSPClient, TElCustomTSPClient *ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToA_2(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ValidationTSPClient != NULL) ? ValidationTSPClient->getHandle() : SB_NULL_HANDLE, (ArchivalTSPClient != NULL) ? ArchivalTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToBaselineLTA(TElCustomTSPClient &ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToBaselineLTA(_Handle, ArchivalTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToBaselineLTA(TElCustomTSPClient *ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToBaselineLTA(_Handle, (ArchivalTSPClient != NULL) ? ArchivalTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToBaselineLTA(TElCustomTSPClient &TSPClient, TElCustomTSPClient &ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToBaselineLTA_1(_Handle, TSPClient.getHandle(), ArchivalTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToBaselineLTA(TElCustomTSPClient *TSPClient, TElCustomTSPClient *ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToBaselineLTA_1(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ArchivalTSPClient != NULL) ? ArchivalTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToExtendedA(TElCustomTSPClient &ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToExtendedA(_Handle, ArchivalTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToExtendedA(TElCustomTSPClient *ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToExtendedA(_Handle, (ArchivalTSPClient != NULL) ? ArchivalTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::UpgradeToExtendedA(TElCustomTSPClient &TSPClient, TElCustomTSPClient &ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToExtendedA_1(_Handle, TSPClient.getHandle(), ArchivalTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::UpgradeToExtendedA(TElCustomTSPClient *TSPClient, TElCustomTSPClient *ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_UpgradeToExtendedA_1(_Handle, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE, (ArchivalTSPClient != NULL) ? ArchivalTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::Archive(TElCustomTSPClient &ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_Archive(_Handle, ArchivalTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::Archive(TElCustomTSPClient *ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_Archive(_Handle, (ArchivalTSPClient != NULL) ? ArchivalTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::ArchiveBaseline(TElCustomTSPClient &ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_ArchiveBaseline(_Handle, ArchivalTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::ArchiveBaseline(TElCustomTSPClient *ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_ArchiveBaseline(_Handle, (ArchivalTSPClient != NULL) ? ArchivalTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElCAdESSignatureProcessor::ArchiveExtended(TElCustomTSPClient &ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_ArchiveExtended(_Handle, ArchivalTSPClient.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::ArchiveExtended(TElCustomTSPClient *ArchivalTSPClient)
{
	SBCheckError(TElCAdESSignatureProcessor_ArchiveExtended(_Handle, (ArchivalTSPClient != NULL) ? ArchivalTSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

bool TElCAdESSignatureProcessor::IsBES()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsBES(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsEPES()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsEPES(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsT()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsT(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsC()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsC(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsC(bool DeepCheck)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsC_1(_Handle, (int8_t)DeepCheck, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsX()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsX(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsX(bool DeepCheck)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsX_1(_Handle, (int8_t)DeepCheck, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsXType1()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsXType1(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsXType1(bool DeepCheck)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsXType1_1(_Handle, (int8_t)DeepCheck, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsXType2()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsXType2(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsXType2(bool DeepCheck)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsXType2_1(_Handle, (int8_t)DeepCheck, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsXL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsXL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsXL(bool DeepCheck)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsXL_1(_Handle, (int8_t)DeepCheck, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsXLType1()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsXLType1(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsXLType1(bool DeepCheck)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsXLType1_1(_Handle, (int8_t)DeepCheck, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsXLType2()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsXLType2(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsXLType2(bool DeepCheck)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsXLType2_1(_Handle, (int8_t)DeepCheck, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsTimestampedXL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsTimestampedXL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsTimestampedXL(bool DeepCheck)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsTimestampedXL_1(_Handle, (int8_t)DeepCheck, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsA()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsA(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsA(bool DeepCheck)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsA_1(_Handle, (int8_t)DeepCheck, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsBaselineB()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsBaselineB(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsBaselineT()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsBaselineT(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsBaselineLT()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsBaselineLT(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsBaselineLT(bool DeepCheck)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsBaselineLT_1(_Handle, (int8_t)DeepCheck, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsBaselineLTA()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsBaselineLTA(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsBaselineLTA(bool DeepCheck)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsBaselineLTA_1(_Handle, (int8_t)DeepCheck, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsExtendedBES()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsExtendedBES(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsExtendedEPES()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsExtendedEPES(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsExtendedT()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsExtendedT(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsExtendedC()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsExtendedC(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsExtendedC(bool DeepCheck)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsExtendedC_1(_Handle, (int8_t)DeepCheck, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsExtendedX()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsExtendedX(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsExtendedX(bool DeepCheck)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsExtendedX_1(_Handle, (int8_t)DeepCheck, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsExtendedXType1()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsExtendedXType1(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsExtendedXType1(bool DeepCheck)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsExtendedXType1_1(_Handle, (int8_t)DeepCheck, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsExtendedXType2()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsExtendedXType2(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsExtendedXType2(bool DeepCheck)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsExtendedXType2_1(_Handle, (int8_t)DeepCheck, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsExtendedXL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsExtendedXL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsExtendedXL(bool DeepCheck)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsExtendedXL_1(_Handle, (int8_t)DeepCheck, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsExtendedXLType1()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsExtendedXLType1(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsExtendedXLType1(bool DeepCheck)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsExtendedXLType1_1(_Handle, (int8_t)DeepCheck, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsExtendedXLType2()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsExtendedXLType2(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsExtendedXLType2(bool DeepCheck)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsExtendedXLType2_1(_Handle, (int8_t)DeepCheck, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsTimestampedExtendedXL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsTimestampedExtendedXL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsTimestampedExtendedXL(bool DeepCheck)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsTimestampedExtendedXL_1(_Handle, (int8_t)DeepCheck, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsExtendedA()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsExtendedA(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCAdESSignatureProcessor::IsExtendedA(bool DeepCheck)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_IsExtendedA_1(_Handle, (int8_t)DeepCheck, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCMSSIGNATURE
TElCMSSignature* TElCAdESSignatureProcessor::get_Signature()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCAdESSignatureProcessor_get_Signature(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signature)
		this->_Inst_Signature = new TElCMSSignature(hOutResult, ohFalse);
	else
		this->_Inst_Signature->updateHandle(hOutResult);
	return this->_Inst_Signature;
}

SB_INLINE void TElCAdESSignatureProcessor::set_Signature(TElCMSSignature &Value)
{
	SBCheckError(TElCAdESSignatureProcessor_set_Signature(_Handle, Value.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::set_Signature(TElCMSSignature *Value)
{
	SBCheckError(TElCAdESSignatureProcessor_set_Signature(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCMSSIGNATURE */

TSBCAdESCompatibilityErrors TElCAdESSignatureProcessor::get_CompatibilityErrors()
{
	TSBCAdESCompatibilityErrorsRaw OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_get_CompatibilityErrors(_Handle, &OutResultRaw));
	return (TSBCAdESCompatibilityErrors)OutResultRaw;
}

bool TElCAdESSignatureProcessor::get_ForceSigningCertificateV2()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_get_ForceSigningCertificateV2(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCAdESSignatureProcessor::set_ForceSigningCertificateV2(bool Value)
{
	SBCheckError(TElCAdESSignatureProcessor_set_ForceSigningCertificateV2(_Handle, (int8_t)Value));
}

SB_INLINE int64_t TElCAdESSignatureProcessor::get_ValidationMoment()
{
	int64_t OutResult;
	SBCheckError(TElCAdESSignatureProcessor_get_ValidationMoment(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCAdESSignatureProcessor::set_ValidationMoment(int64_t Value)
{
	SBCheckError(TElCAdESSignatureProcessor_set_ValidationMoment(_Handle, Value));
}

bool TElCAdESSignatureProcessor::get_ForceCompleteChainValidation()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_get_ForceCompleteChainValidation(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCAdESSignatureProcessor::set_ForceCompleteChainValidation(bool Value)
{
	SBCheckError(TElCAdESSignatureProcessor_set_ForceCompleteChainValidation(_Handle, (int8_t)Value));
}

bool TElCAdESSignatureProcessor::get_IgnoreChainValidationErrors()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_get_IgnoreChainValidationErrors(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCAdESSignatureProcessor::set_IgnoreChainValidationErrors(bool Value)
{
	SBCheckError(TElCAdESSignatureProcessor_set_IgnoreChainValidationErrors(_Handle, (int8_t)Value));
}

bool TElCAdESSignatureProcessor::get_PerformRevocationCheck()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_get_PerformRevocationCheck(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCAdESSignatureProcessor::set_PerformRevocationCheck(bool Value)
{
	SBCheckError(TElCAdESSignatureProcessor_set_PerformRevocationCheck(_Handle, (int8_t)Value));
}

bool TElCAdESSignatureProcessor::get_OfflineMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_get_OfflineMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCAdESSignatureProcessor::set_OfflineMode(bool Value)
{
	SBCheckError(TElCAdESSignatureProcessor_set_OfflineMode(_Handle, (int8_t)Value));
}

SB_INLINE int64_t TElCAdESSignatureProcessor::get_ClaimedSigningTime()
{
	int64_t OutResult;
	SBCheckError(TElCAdESSignatureProcessor_get_ClaimedSigningTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElCAdESSignatureProcessor::get_CertifiedSigningTime()
{
	int64_t OutResult;
	SBCheckError(TElCAdESSignatureProcessor_get_CertifiedSigningTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElCAdESSignatureProcessor::get_LastArchivalTime()
{
	int64_t OutResult;
	SBCheckError(TElCAdESSignatureProcessor_get_LastArchivalTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElCAdESSignatureProcessor::get_CertifiedValidationTime()
{
	int64_t OutResult;
	SBCheckError(TElCAdESSignatureProcessor_get_CertifiedValidationTime(_Handle, &OutResult));
	return OutResult;
}

bool TElCAdESSignatureProcessor::get_DeepTimestampValidation()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_get_DeepTimestampValidation(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCAdESSignatureProcessor::set_DeepTimestampValidation(bool Value)
{
	SBCheckError(TElCAdESSignatureProcessor_set_DeepTimestampValidation(_Handle, (int8_t)Value));
}

bool TElCAdESSignatureProcessor::get_DeepCountersignatureValidation()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_get_DeepCountersignatureValidation(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCAdESSignatureProcessor::set_DeepCountersignatureValidation(bool Value)
{
	SBCheckError(TElCAdESSignatureProcessor_set_DeepCountersignatureValidation(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCADESREVOCATIONINFO
TElCAdESRevocationInfo* TElCAdESSignatureProcessor::get_CustomRevocationInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCAdESSignatureProcessor_get_CustomRevocationInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CustomRevocationInfo)
		this->_Inst_CustomRevocationInfo = new TElCAdESRevocationInfo(hOutResult, ohFalse);
	else
		this->_Inst_CustomRevocationInfo->updateHandle(hOutResult);
	return this->_Inst_CustomRevocationInfo;
}
#endif /* SB_USE_CLASS_TELCADESREVOCATIONINFO */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElCAdESSignatureProcessor::get_TrustedCertificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCAdESSignatureProcessor_get_TrustedCertificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TrustedCertificates)
		this->_Inst_TrustedCertificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_TrustedCertificates->updateHandle(hOutResult);
	return this->_Inst_TrustedCertificates;
}

SB_INLINE void TElCAdESSignatureProcessor::set_TrustedCertificates(TElCustomCertStorage &Value)
{
	SBCheckError(TElCAdESSignatureProcessor_set_TrustedCertificates(_Handle, Value.getHandle()));
}

SB_INLINE void TElCAdESSignatureProcessor::set_TrustedCertificates(TElCustomCertStorage *Value)
{
	SBCheckError(TElCAdESSignatureProcessor_set_TrustedCertificates(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

bool TElCAdESSignatureProcessor::get_AllowPartialValidationInfo()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_get_AllowPartialValidationInfo(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCAdESSignatureProcessor::set_AllowPartialValidationInfo(bool Value)
{
	SBCheckError(TElCAdESSignatureProcessor_set_AllowPartialValidationInfo(_Handle, (int8_t)Value));
}

bool TElCAdESSignatureProcessor::get_SkipValidationTimestampedSignatures()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_get_SkipValidationTimestampedSignatures(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCAdESSignatureProcessor::set_SkipValidationTimestampedSignatures(bool Value)
{
	SBCheckError(TElCAdESSignatureProcessor_set_SkipValidationTimestampedSignatures(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElCAdESSignatureProcessor::get_GracePeriod()
{
	int32_t OutResult;
	SBCheckError(TElCAdESSignatureProcessor_get_GracePeriod(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCAdESSignatureProcessor::set_GracePeriod(int32_t Value)
{
	SBCheckError(TElCAdESSignatureProcessor_set_GracePeriod(_Handle, Value));
}

bool TElCAdESSignatureProcessor::get_ReportInvalidTimestamps()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_get_ReportInvalidTimestamps(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCAdESSignatureProcessor::set_ReportInvalidTimestamps(bool Value)
{
	SBCheckError(TElCAdESSignatureProcessor_set_ReportInvalidTimestamps(_Handle, (int8_t)Value));
}

bool TElCAdESSignatureProcessor::get_AddReferenceToSigningCert()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_get_AddReferenceToSigningCert(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCAdESSignatureProcessor::set_AddReferenceToSigningCert(bool Value)
{
	SBCheckError(TElCAdESSignatureProcessor_set_AddReferenceToSigningCert(_Handle, (int8_t)Value));
}

bool TElCAdESSignatureProcessor::get_AddReferencesToIrrevocableCerts()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_get_AddReferencesToIrrevocableCerts(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCAdESSignatureProcessor::set_AddReferencesToIrrevocableCerts(bool Value)
{
	SBCheckError(TElCAdESSignatureProcessor_set_AddReferencesToIrrevocableCerts(_Handle, (int8_t)Value));
}

bool TElCAdESSignatureProcessor::get_AddReferencesToAllUsedCertsAndRevInfo()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_get_AddReferencesToAllUsedCertsAndRevInfo(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCAdESSignatureProcessor::set_AddReferencesToAllUsedCertsAndRevInfo(bool Value)
{
	SBCheckError(TElCAdESSignatureProcessor_set_AddReferencesToAllUsedCertsAndRevInfo(_Handle, (int8_t)Value));
}

TSBCMSAdvancedSignatureValidity TElCAdESSignatureProcessor::get_LastValidationResult()
{
	TSBCMSAdvancedSignatureValidityRaw OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_get_LastValidationResult(_Handle, &OutResultRaw));
	return (TSBCMSAdvancedSignatureValidity)OutResultRaw;
}

bool TElCAdESSignatureProcessor::get_UseArchivalTimestampV3()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCAdESSignatureProcessor_get_UseArchivalTimestampV3(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCAdESSignatureProcessor::set_UseArchivalTimestampV3(bool Value)
{
	SBCheckError(TElCAdESSignatureProcessor_set_UseArchivalTimestampV3(_Handle, (int8_t)Value));
}

SB_INLINE void TElCAdESSignatureProcessor::get_OnCertValidatorPrepared(TSBCAdESCertValidatorPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCAdESSignatureProcessor_get_OnCertValidatorPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCAdESSignatureProcessor::set_OnCertValidatorPrepared(TSBCAdESCertValidatorPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCAdESSignatureProcessor_set_OnCertValidatorPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCAdESSignatureProcessor::get_OnCertValidatorFinished(TSBCAdESCertValidatorFinishedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCAdESSignatureProcessor_get_OnCertValidatorFinished(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCAdESSignatureProcessor::set_OnCertValidatorFinished(TSBCAdESCertValidatorFinishedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCAdESSignatureProcessor_set_OnCertValidatorFinished(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCAdESSignatureProcessor::get_OnBeforeSign(TSBCAdESBeforeSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCAdESSignatureProcessor_get_OnBeforeSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCAdESSignatureProcessor::set_OnBeforeSign(TSBCAdESBeforeSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCAdESSignatureProcessor_set_OnBeforeSign(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCAdESSignatureProcessor::get_OnBeforeAddTimestamp(TSBCAdESBeforeAddTimestampEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCAdESSignatureProcessor_get_OnBeforeAddTimestamp(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCAdESSignatureProcessor::set_OnBeforeAddTimestamp(TSBCAdESBeforeAddTimestampEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCAdESSignatureProcessor_set_OnBeforeAddTimestamp(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCAdESSignatureProcessor::get_OnBeforeAddValidationTimestamp(TSBCAdESBeforeAddValidationTimestampEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCAdESSignatureProcessor_get_OnBeforeAddValidationTimestamp(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCAdESSignatureProcessor::set_OnBeforeAddValidationTimestamp(TSBCAdESBeforeAddValidationTimestampEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCAdESSignatureProcessor_set_OnBeforeAddValidationTimestamp(_Handle, pMethodValue, pDataValue));
}

void TElCAdESSignatureProcessor::initInstances()
{
#ifdef SB_USE_CLASS_TELCMSSIGNATURE
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGNATURE */
#ifdef SB_USE_CLASS_TELCADESREVOCATIONINFO
	this->_Inst_CustomRevocationInfo = NULL;
#endif /* SB_USE_CLASS_TELCADESREVOCATIONINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_TrustedCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElCAdESSignatureProcessor::TElCAdESSignatureProcessor(TElCAdESSignatureProcessorHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELCMSSIGNATURE
TElCAdESSignatureProcessor::TElCAdESSignatureProcessor(TElCMSSignature &Sig) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCAdESSignatureProcessor_Create(Sig.getHandle(), &_Handle));
}

TElCAdESSignatureProcessor::TElCAdESSignatureProcessor(TElCMSSignature *Sig) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCAdESSignatureProcessor_Create((Sig != NULL) ? Sig->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCMSSIGNATURE */

TElCAdESSignatureProcessor::TElCAdESSignatureProcessor() : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCAdESSignatureProcessor_Create_1(&_Handle));
}

TElCAdESSignatureProcessor::~TElCAdESSignatureProcessor()
{
#ifdef SB_USE_CLASS_TELCMSSIGNATURE
	delete this->_Inst_Signature;
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELCMSSIGNATURE */
#ifdef SB_USE_CLASS_TELCADESREVOCATIONINFO
	delete this->_Inst_CustomRevocationInfo;
	this->_Inst_CustomRevocationInfo = NULL;
#endif /* SB_USE_CLASS_TELCADESREVOCATIONINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_TrustedCertificates;
	this->_Inst_TrustedCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELCADESSIGNATUREPROCESSOR */

};	/* namespace SecureBlackbox */

