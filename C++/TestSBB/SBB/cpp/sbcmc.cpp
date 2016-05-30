#include "sbcmc.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELATTRIBUTEVALUE

void TElAttributeValue::get_Value(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElAttributeValue_get_Value(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1692951094, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAttributeValue::set_Value(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElAttributeValue_set_Value(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElAttributeValue::TElAttributeValue(TElAttributeValueHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElAttributeValue::TElAttributeValue() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAttributeValue_Create(&_Handle));
}

TElAttributeValue::TElAttributeValue(const std::vector<uint8_t> &Value) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAttributeValue_Create_1(SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), &_Handle));
}

#endif /* SB_USE_CLASS_TELATTRIBUTEVALUE */

#ifdef SB_USE_CLASS_TELTAGGEDATTRIBUTE

SB_INLINE uint32_t TElTaggedAttribute::get_BodyPartId()
{
	uint32_t OutResult;
	SBCheckError(TElTaggedAttribute_get_BodyPartId(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTaggedAttribute::set_BodyPartId(uint32_t Value)
{
	SBCheckError(TElTaggedAttribute_set_BodyPartId(_Handle, Value));
}

void TElTaggedAttribute::get_AttrType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElTaggedAttribute_get_AttrType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1121669805, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElTaggedAttribute::set_AttrType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElTaggedAttribute_set_AttrType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TLIST
TList* TElTaggedAttribute::get_AttrValues()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTaggedAttribute_get_AttrValues(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AttrValues)
		this->_Inst_AttrValues = new TList(hOutResult, ohFalse);
	else
		this->_Inst_AttrValues->updateHandle(hOutResult);
	return this->_Inst_AttrValues;
}
#endif /* SB_USE_CLASS_TLIST */

void TElTaggedAttribute::initInstances()
{
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_AttrValues = NULL;
#endif /* SB_USE_CLASS_TLIST */
}

TElTaggedAttribute::TElTaggedAttribute(TElTaggedAttributeHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElTaggedAttribute::TElTaggedAttribute() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElTaggedAttribute_Create(&_Handle));
}

TElTaggedAttribute::~TElTaggedAttribute()
{
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_AttrValues;
	this->_Inst_AttrValues = NULL;
#endif /* SB_USE_CLASS_TLIST */
}
#endif /* SB_USE_CLASS_TELTAGGEDATTRIBUTE */

#ifdef SB_USE_CLASS_TELTAGGEDCERTIFICATIONREQUEST

SB_INLINE uint32_t TElTaggedCertificationRequest::get_BodyPartId()
{
	uint32_t OutResult;
	SBCheckError(TElTaggedCertificationRequest_get_BodyPartId(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTaggedCertificationRequest::set_BodyPartId(uint32_t Value)
{
	SBCheckError(TElTaggedCertificationRequest_set_BodyPartId(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST
TElCertificateRequest* TElTaggedCertificationRequest::get_CertificationRequest()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTaggedCertificationRequest_get_CertificationRequest(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertificationRequest)
		this->_Inst_CertificationRequest = new TElCertificateRequest(hOutResult, ohFalse);
	else
		this->_Inst_CertificationRequest->updateHandle(hOutResult);
	return this->_Inst_CertificationRequest;
}

SB_INLINE void TElTaggedCertificationRequest::set_CertificationRequest(TElCertificateRequest &Value)
{
	SBCheckError(TElTaggedCertificationRequest_set_CertificationRequest(_Handle, Value.getHandle()));
}

SB_INLINE void TElTaggedCertificationRequest::set_CertificationRequest(TElCertificateRequest *Value)
{
	SBCheckError(TElTaggedCertificationRequest_set_CertificationRequest(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */

void TElTaggedCertificationRequest::initInstances()
{
#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST
	this->_Inst_CertificationRequest = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */
}

TElTaggedCertificationRequest::TElTaggedCertificationRequest(TElTaggedCertificationRequestHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElTaggedCertificationRequest::TElTaggedCertificationRequest() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElTaggedCertificationRequest_Create(&_Handle));
}

TElTaggedCertificationRequest::~TElTaggedCertificationRequest()
{
#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST
	delete this->_Inst_CertificationRequest;
	this->_Inst_CertificationRequest = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */
}
#endif /* SB_USE_CLASS_TELTAGGEDCERTIFICATIONREQUEST */

#ifdef SB_USE_CLASS_TELEXTERNALLYDEFINEDCERTIFICATIONREQUEST

SB_INLINE uint32_t TElExternallyDefinedCertificationRequest::get_BodyPartId()
{
	uint32_t OutResult;
	SBCheckError(TElExternallyDefinedCertificationRequest_get_BodyPartId(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElExternallyDefinedCertificationRequest::set_BodyPartId(uint32_t Value)
{
	SBCheckError(TElExternallyDefinedCertificationRequest_set_BodyPartId(_Handle, Value));
}

void TElExternallyDefinedCertificationRequest::get_MessageType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExternallyDefinedCertificationRequest_get_MessageType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(821514798, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElExternallyDefinedCertificationRequest::set_MessageType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElExternallyDefinedCertificationRequest_set_MessageType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElExternallyDefinedCertificationRequest::get_MessageValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExternallyDefinedCertificationRequest_get_MessageValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1370295071, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElExternallyDefinedCertificationRequest::set_MessageValue(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElExternallyDefinedCertificationRequest_set_MessageValue(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElExternallyDefinedCertificationRequest::TElExternallyDefinedCertificationRequest(TElExternallyDefinedCertificationRequestHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElExternallyDefinedCertificationRequest::TElExternallyDefinedCertificationRequest() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElExternallyDefinedCertificationRequest_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELEXTERNALLYDEFINEDCERTIFICATIONREQUEST */

#ifdef SB_USE_CLASS_TELTAGGEDREQUEST

TSBTaggedRequestType TElTaggedRequest::get_RequestType()
{
	TSBTaggedRequestTypeRaw OutResultRaw = 0;
	SBCheckError(TElTaggedRequest_get_RequestType(_Handle, &OutResultRaw));
	return (TSBTaggedRequestType)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELTAGGEDCERTIFICATIONREQUEST
TElTaggedCertificationRequest* TElTaggedRequest::get_TaggedCertificationRequest()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTaggedRequest_get_TaggedCertificationRequest(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TaggedCertificationRequest)
		this->_Inst_TaggedCertificationRequest = new TElTaggedCertificationRequest(hOutResult, ohFalse);
	else
		this->_Inst_TaggedCertificationRequest->updateHandle(hOutResult);
	return this->_Inst_TaggedCertificationRequest;
}

SB_INLINE void TElTaggedRequest::set_TaggedCertificationRequest(TElTaggedCertificationRequest &Value)
{
	SBCheckError(TElTaggedRequest_set_TaggedCertificationRequest(_Handle, Value.getHandle()));
}

SB_INLINE void TElTaggedRequest::set_TaggedCertificationRequest(TElTaggedCertificationRequest *Value)
{
	SBCheckError(TElTaggedRequest_set_TaggedCertificationRequest(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELTAGGEDCERTIFICATIONREQUEST */

void TElTaggedRequest::get_CertReqMsg(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElTaggedRequest_get_CertReqMsg(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-290615105, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElTaggedRequest::set_CertReqMsg(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElTaggedRequest_set_CertReqMsg(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELEXTERNALLYDEFINEDCERTIFICATIONREQUEST
TElExternallyDefinedCertificationRequest* TElTaggedRequest::get_ExternallyDefinedCertificationRequest()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTaggedRequest_get_ExternallyDefinedCertificationRequest(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ExternallyDefinedCertificationRequest)
		this->_Inst_ExternallyDefinedCertificationRequest = new TElExternallyDefinedCertificationRequest(hOutResult, ohFalse);
	else
		this->_Inst_ExternallyDefinedCertificationRequest->updateHandle(hOutResult);
	return this->_Inst_ExternallyDefinedCertificationRequest;
}

SB_INLINE void TElTaggedRequest::set_ExternallyDefinedCertificationRequest(TElExternallyDefinedCertificationRequest &Value)
{
	SBCheckError(TElTaggedRequest_set_ExternallyDefinedCertificationRequest(_Handle, Value.getHandle()));
}

SB_INLINE void TElTaggedRequest::set_ExternallyDefinedCertificationRequest(TElExternallyDefinedCertificationRequest *Value)
{
	SBCheckError(TElTaggedRequest_set_ExternallyDefinedCertificationRequest(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELEXTERNALLYDEFINEDCERTIFICATIONREQUEST */

void TElTaggedRequest::initInstances()
{
#ifdef SB_USE_CLASS_TELTAGGEDCERTIFICATIONREQUEST
	this->_Inst_TaggedCertificationRequest = NULL;
#endif /* SB_USE_CLASS_TELTAGGEDCERTIFICATIONREQUEST */
#ifdef SB_USE_CLASS_TELEXTERNALLYDEFINEDCERTIFICATIONREQUEST
	this->_Inst_ExternallyDefinedCertificationRequest = NULL;
#endif /* SB_USE_CLASS_TELEXTERNALLYDEFINEDCERTIFICATIONREQUEST */
}

TElTaggedRequest::TElTaggedRequest(TElTaggedRequestHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElTaggedRequest::TElTaggedRequest() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElTaggedRequest_Create(&_Handle));
}

TElTaggedRequest::~TElTaggedRequest()
{
#ifdef SB_USE_CLASS_TELTAGGEDCERTIFICATIONREQUEST
	delete this->_Inst_TaggedCertificationRequest;
	this->_Inst_TaggedCertificationRequest = NULL;
#endif /* SB_USE_CLASS_TELTAGGEDCERTIFICATIONREQUEST */
#ifdef SB_USE_CLASS_TELEXTERNALLYDEFINEDCERTIFICATIONREQUEST
	delete this->_Inst_ExternallyDefinedCertificationRequest;
	this->_Inst_ExternallyDefinedCertificationRequest = NULL;
#endif /* SB_USE_CLASS_TELEXTERNALLYDEFINEDCERTIFICATIONREQUEST */
}
#endif /* SB_USE_CLASS_TELTAGGEDREQUEST */

#ifdef SB_USE_CLASS_TELCONTENTINFO

void TElContentInfo::get_ContentType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElContentInfo_get_ContentType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(603213700, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElContentInfo::set_ContentType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElContentInfo_set_ContentType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElContentInfo::get_Content(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElContentInfo_get_Content(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1063027169, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElContentInfo::set_Content(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElContentInfo_set_Content(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElContentInfo::TElContentInfo(TElContentInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElContentInfo::TElContentInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElContentInfo_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCONTENTINFO */

#ifdef SB_USE_CLASS_TELTAGGEDCONTENTINFO

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
SB_INLINE void TElTaggedContentInfo::LoadFromTag(TElASN1ConstrainedTag &Tag)
{
	SBCheckError(TElTaggedContentInfo_LoadFromTag(_Handle, Tag.getHandle()));
}

SB_INLINE void TElTaggedContentInfo::LoadFromTag(TElASN1ConstrainedTag *Tag)
{
	SBCheckError(TElTaggedContentInfo_LoadFromTag(_Handle, (Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
SB_INLINE void TElTaggedContentInfo::SaveToTag(TElASN1ConstrainedTag &Tag)
{
	SBCheckError(TElTaggedContentInfo_SaveToTag(_Handle, Tag.getHandle()));
}

SB_INLINE void TElTaggedContentInfo::SaveToTag(TElASN1ConstrainedTag *Tag)
{
	SBCheckError(TElTaggedContentInfo_SaveToTag(_Handle, (Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

SB_INLINE uint32_t TElTaggedContentInfo::get_BodyPartId()
{
	uint32_t OutResult;
	SBCheckError(TElTaggedContentInfo_get_BodyPartId(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTaggedContentInfo::set_BodyPartId(uint32_t Value)
{
	SBCheckError(TElTaggedContentInfo_set_BodyPartId(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELCONTENTINFO
TElContentInfo* TElTaggedContentInfo::get_ContentInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTaggedContentInfo_get_ContentInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ContentInfo)
		this->_Inst_ContentInfo = new TElContentInfo(hOutResult, ohFalse);
	else
		this->_Inst_ContentInfo->updateHandle(hOutResult);
	return this->_Inst_ContentInfo;
}

SB_INLINE void TElTaggedContentInfo::set_ContentInfo(TElContentInfo &Value)
{
	SBCheckError(TElTaggedContentInfo_set_ContentInfo(_Handle, Value.getHandle()));
}

SB_INLINE void TElTaggedContentInfo::set_ContentInfo(TElContentInfo *Value)
{
	SBCheckError(TElTaggedContentInfo_set_ContentInfo(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCONTENTINFO */

void TElTaggedContentInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELCONTENTINFO
	this->_Inst_ContentInfo = NULL;
#endif /* SB_USE_CLASS_TELCONTENTINFO */
}

TElTaggedContentInfo::TElTaggedContentInfo(TElTaggedContentInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElTaggedContentInfo::TElTaggedContentInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElTaggedContentInfo_Create(&_Handle));
}

TElTaggedContentInfo::~TElTaggedContentInfo()
{
#ifdef SB_USE_CLASS_TELCONTENTINFO
	delete this->_Inst_ContentInfo;
	this->_Inst_ContentInfo = NULL;
#endif /* SB_USE_CLASS_TELCONTENTINFO */
}
#endif /* SB_USE_CLASS_TELTAGGEDCONTENTINFO */

#ifdef SB_USE_CLASS_TELOTHERMSG

void TElOtherMsg::get_MsgType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOtherMsg_get_MsgType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2128998654, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOtherMsg::set_MsgType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOtherMsg_set_MsgType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElOtherMsg::get_MsgValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOtherMsg_get_MsgValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1673824929, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOtherMsg::set_MsgValue(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOtherMsg_set_MsgValue(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElOtherMsg::TElOtherMsg(TElOtherMsgHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElOtherMsg::TElOtherMsg() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOtherMsg_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOTHERMSG */

#ifdef SB_USE_CLASS_TELPKIDATA

bool TElPKIData::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKIData_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKIData::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElPKIData_LoadFromBuffer(_Handle, Buffer, Size));
}

#ifdef SB_USE_CLASS_TLIST
TList* TElPKIData::get_ControlSequence()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKIData_get_ControlSequence(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ControlSequence)
		this->_Inst_ControlSequence = new TList(hOutResult, ohFalse);
	else
		this->_Inst_ControlSequence->updateHandle(hOutResult);
	return this->_Inst_ControlSequence;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
TList* TElPKIData::get_ReqSequence()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKIData_get_ReqSequence(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ReqSequence)
		this->_Inst_ReqSequence = new TList(hOutResult, ohFalse);
	else
		this->_Inst_ReqSequence->updateHandle(hOutResult);
	return this->_Inst_ReqSequence;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
TList* TElPKIData::get_CMSSequence()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKIData_get_CMSSequence(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CMSSequence)
		this->_Inst_CMSSequence = new TList(hOutResult, ohFalse);
	else
		this->_Inst_CMSSequence->updateHandle(hOutResult);
	return this->_Inst_CMSSequence;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
TList* TElPKIData::get_OtherMsgSequence()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKIData_get_OtherMsgSequence(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OtherMsgSequence)
		this->_Inst_OtherMsgSequence = new TList(hOutResult, ohFalse);
	else
		this->_Inst_OtherMsgSequence->updateHandle(hOutResult);
	return this->_Inst_OtherMsgSequence;
}
#endif /* SB_USE_CLASS_TLIST */

void TElPKIData::initInstances()
{
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_ControlSequence = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_ReqSequence = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_CMSSequence = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_OtherMsgSequence = NULL;
#endif /* SB_USE_CLASS_TLIST */
}

TElPKIData::TElPKIData(TElPKIDataHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKIData::TElPKIData() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKIData_Create(&_Handle));
}

TElPKIData::~TElPKIData()
{
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_ControlSequence;
	this->_Inst_ControlSequence = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_ReqSequence;
	this->_Inst_ReqSequence = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_CMSSequence;
	this->_Inst_CMSSequence = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_OtherMsgSequence;
	this->_Inst_OtherMsgSequence = NULL;
#endif /* SB_USE_CLASS_TLIST */
}
#endif /* SB_USE_CLASS_TELPKIDATA */

#ifdef SB_USE_CLASS_TELPKIRESPONSE

bool TElPKIResponse::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKIResponse_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKIResponse::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElPKIResponse_LoadFromBuffer(_Handle, Buffer, Size));
}

#ifdef SB_USE_CLASS_TLIST
TList* TElPKIResponse::get_ControlSequence()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKIResponse_get_ControlSequence(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ControlSequence)
		this->_Inst_ControlSequence = new TList(hOutResult, ohFalse);
	else
		this->_Inst_ControlSequence->updateHandle(hOutResult);
	return this->_Inst_ControlSequence;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
TList* TElPKIResponse::get_CMSSequence()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKIResponse_get_CMSSequence(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CMSSequence)
		this->_Inst_CMSSequence = new TList(hOutResult, ohFalse);
	else
		this->_Inst_CMSSequence->updateHandle(hOutResult);
	return this->_Inst_CMSSequence;
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
TList* TElPKIResponse::get_OtherMsgSequence()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKIResponse_get_OtherMsgSequence(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OtherMsgSequence)
		this->_Inst_OtherMsgSequence = new TList(hOutResult, ohFalse);
	else
		this->_Inst_OtherMsgSequence->updateHandle(hOutResult);
	return this->_Inst_OtherMsgSequence;
}
#endif /* SB_USE_CLASS_TLIST */

void TElPKIResponse::initInstances()
{
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_ControlSequence = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_CMSSequence = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_OtherMsgSequence = NULL;
#endif /* SB_USE_CLASS_TLIST */
}

TElPKIResponse::TElPKIResponse(TElPKIResponseHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKIResponse::TElPKIResponse() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKIResponse_Create(&_Handle));
}

TElPKIResponse::~TElPKIResponse()
{
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_ControlSequence;
	this->_Inst_ControlSequence = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_CMSSequence;
	this->_Inst_CMSSequence = NULL;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_OtherMsgSequence;
	this->_Inst_OtherMsgSequence = NULL;
#endif /* SB_USE_CLASS_TLIST */
}
#endif /* SB_USE_CLASS_TELPKIRESPONSE */

#ifdef SB_USE_CLASS_TELCONTROLATTRIBUTE

#ifdef SB_USE_CLASS_TELTAGGEDATTRIBUTE
SB_INLINE TElControlAttributeHandle TElControlAttribute::CreateInstance(TElTaggedAttribute &Tagged)
{
	TElControlAttributeHandle OutResult;
	SBCheckError(TElControlAttribute_CreateInstance(Tagged.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElControlAttributeHandle TElControlAttribute::CreateInstance(TElTaggedAttribute *Tagged)
{
	TElControlAttributeHandle OutResult;
	SBCheckError(TElControlAttribute_CreateInstance((Tagged != NULL) ? Tagged->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELTAGGEDATTRIBUTE */

#ifdef SB_USE_CLASS_TELTAGGEDATTRIBUTE
SB_INLINE TElControlAttributeHandle TElControlAttribute::CreateInstance_Inst(TElTaggedAttribute &Tagged)
{
	TElControlAttributeHandle OutResult;
	SBCheckError(TElControlAttribute_CreateInstance_1(_Handle, Tagged.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElControlAttributeHandle TElControlAttribute::CreateInstance_Inst(TElTaggedAttribute *Tagged)
{
	TElControlAttributeHandle OutResult;
	SBCheckError(TElControlAttribute_CreateInstance_1(_Handle, (Tagged != NULL) ? Tagged->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELTAGGEDATTRIBUTE */

#ifdef SB_USE_CLASS_TELTAGGEDATTRIBUTE
SB_INLINE void TElControlAttribute::LoadFromTagged(TElTaggedAttribute &Tagged)
{
	SBCheckError(TElControlAttribute_LoadFromTagged(_Handle, Tagged.getHandle()));
}

SB_INLINE void TElControlAttribute::LoadFromTagged(TElTaggedAttribute *Tagged)
{
	SBCheckError(TElControlAttribute_LoadFromTagged(_Handle, (Tagged != NULL) ? Tagged->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELTAGGEDATTRIBUTE */

bool TElControlAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElControlAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElControlAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElControlAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElControlAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElControlAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElControlAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElControlAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(331007199, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElControlAttribute::get_Values(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElControlAttribute_get_Values(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1992611924, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElControlAttribute::get_ValueCount()
{
	int32_t OutResult;
	SBCheckError(TElControlAttribute_get_ValueCount(_Handle, &OutResult));
	return OutResult;
}

TElControlAttribute::TElControlAttribute(TElControlAttributeHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElControlAttribute::TElControlAttribute() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElControlAttribute_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCONTROLATTRIBUTE */

#ifdef SB_USE_CLASS_TELIDENTIFICATIONATTRIBUTE

bool TElIdentificationAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIdentificationAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElIdentificationAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElIdentificationAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElIdentificationAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElIdentificationAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElIdentificationAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElIdentificationAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-675653794, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElIdentificationAttribute::get_Content(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElIdentificationAttribute_get_Content(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-540068073, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElIdentificationAttribute::set_Content(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElIdentificationAttribute_set_Content(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElIdentificationAttribute::TElIdentificationAttribute(TElIdentificationAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
}

TElIdentificationAttribute::TElIdentificationAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIdentificationAttribute_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELIDENTIFICATIONATTRIBUTE */

#ifdef SB_USE_CLASS_TELPENDINFO

void TElPendInfo::get_PendToken(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPendInfo_get_PendToken(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(258702591, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPendInfo::set_PendToken(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPendInfo_set_PendToken(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int64_t TElPendInfo::get_PendTime()
{
	int64_t OutResult;
	SBCheckError(TElPendInfo_get_PendTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPendInfo::set_PendTime(int64_t Value)
{
	SBCheckError(TElPendInfo_set_PendTime(_Handle, Value));
}

TElPendInfo::TElPendInfo(TElPendInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPendInfo::TElPendInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPendInfo_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPENDINFO */

#ifdef SB_USE_CLASS_TELCMCSTATUSINFOATTRIBUTE

bool TElCMCStatusInfoAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMCStatusInfoAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMCStatusInfoAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElCMCStatusInfoAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElCMCStatusInfoAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElCMCStatusInfoAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElCMCStatusInfoAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMCStatusInfoAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(135070627, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElCMCStatusInfoAttribute::get_CMCStatus()
{
	int32_t OutResult;
	SBCheckError(TElCMCStatusInfoAttribute_get_CMCStatus(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMCStatusInfoAttribute::set_CMCStatus(int32_t Value)
{
	SBCheckError(TElCMCStatusInfoAttribute_set_CMCStatus(_Handle, Value));
}

void TElCMCStatusInfoAttribute::get_BodyList(std::vector<int32_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size() * 4;
	uint32_t _err = TElCMCStatusInfoAttribute_get_BodyList(_Handle, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult / 4);
		SBCheckError(SBGetLastReturnBuffer(-460634826, 1, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult / 4);
}

SB_INLINE void TElCMCStatusInfoAttribute::set_BodyList(const std::vector<int32_t> &Value)
{
	SBCheckError(TElCMCStatusInfoAttribute_set_BodyList(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElCMCStatusInfoAttribute::get_StatusString(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCMCStatusInfoAttribute_get_StatusString(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(555083058, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMCStatusInfoAttribute::set_StatusString(const std::string &Value)
{
	SBCheckError(TElCMCStatusInfoAttribute_set_StatusString(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElCMCStatusInfoAttribute::get_HasPendInfo()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMCStatusInfoAttribute_get_HasPendInfo(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMCStatusInfoAttribute::set_HasPendInfo(bool Value)
{
	SBCheckError(TElCMCStatusInfoAttribute_set_HasPendInfo(_Handle, (int8_t)Value));
}

bool TElCMCStatusInfoAttribute::get_HasFailInfo()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMCStatusInfoAttribute_get_HasFailInfo(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMCStatusInfoAttribute::set_HasFailInfo(bool Value)
{
	SBCheckError(TElCMCStatusInfoAttribute_set_HasFailInfo(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElCMCStatusInfoAttribute::get_FailInfo()
{
	int32_t OutResult;
	SBCheckError(TElCMCStatusInfoAttribute_get_FailInfo(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMCStatusInfoAttribute::set_FailInfo(int32_t Value)
{
	SBCheckError(TElCMCStatusInfoAttribute_set_FailInfo(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELPENDINFO
TElPendInfo* TElCMCStatusInfoAttribute::get_PendInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMCStatusInfoAttribute_get_PendInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PendInfo)
		this->_Inst_PendInfo = new TElPendInfo(hOutResult, ohFalse);
	else
		this->_Inst_PendInfo->updateHandle(hOutResult);
	return this->_Inst_PendInfo;
}

SB_INLINE void TElCMCStatusInfoAttribute::set_PendInfo(TElPendInfo &Value)
{
	SBCheckError(TElCMCStatusInfoAttribute_set_PendInfo(_Handle, Value.getHandle()));
}

SB_INLINE void TElCMCStatusInfoAttribute::set_PendInfo(TElPendInfo *Value)
{
	SBCheckError(TElCMCStatusInfoAttribute_set_PendInfo(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPENDINFO */

void TElCMCStatusInfoAttribute::initInstances()
{
#ifdef SB_USE_CLASS_TELPENDINFO
	this->_Inst_PendInfo = NULL;
#endif /* SB_USE_CLASS_TELPENDINFO */
}

TElCMCStatusInfoAttribute::TElCMCStatusInfoAttribute(TElCMCStatusInfoAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
	initInstances();
}

TElCMCStatusInfoAttribute::TElCMCStatusInfoAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMCStatusInfoAttribute_Create(&_Handle));
}

TElCMCStatusInfoAttribute::~TElCMCStatusInfoAttribute()
{
#ifdef SB_USE_CLASS_TELPENDINFO
	delete this->_Inst_PendInfo;
	this->_Inst_PendInfo = NULL;
#endif /* SB_USE_CLASS_TELPENDINFO */
}
#endif /* SB_USE_CLASS_TELCMCSTATUSINFOATTRIBUTE */

#ifdef SB_USE_CLASS_TELBODYPARTREFERENCE

TElBodyPartReference::TElBodyPartReference(TElBodyPartReferenceHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElBodyPartReference::TElBodyPartReference() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBodyPartReference_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELBODYPARTREFERENCE */

#ifdef SB_USE_CLASS_TELBODYPARTID

SB_INLINE int32_t TElBodyPartID::get_BodyPartID()
{
	int32_t OutResult;
	SBCheckError(TElBodyPartID_get_BodyPartID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBodyPartID::set_BodyPartID(int32_t Value)
{
	SBCheckError(TElBodyPartID_set_BodyPartID(_Handle, Value));
}

TElBodyPartID::TElBodyPartID(TElBodyPartIDHandle handle, TElOwnHandle ownHandle) : TElBodyPartReference(handle, ownHandle)
{
}

TElBodyPartID::TElBodyPartID() : TElBodyPartReference(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBodyPartID_Create(&_Handle));
}

TElBodyPartID::TElBodyPartID(int32_t Value) : TElBodyPartReference(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBodyPartID_Create_1(Value, &_Handle));
}

#endif /* SB_USE_CLASS_TELBODYPARTID */

#ifdef SB_USE_CLASS_TELBODYPARTPATH

void TElBodyPartPath::get_BodyPartPath(std::vector<int32_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size() * 4;
	uint32_t _err = TElBodyPartPath_get_BodyPartPath(_Handle, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult / 4);
		SBCheckError(SBGetLastReturnBuffer(914841445, 1, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult / 4);
}

SB_INLINE void TElBodyPartPath::set_BodyPartPath(const std::vector<int32_t> &Value)
{
	SBCheckError(TElBodyPartPath_set_BodyPartPath(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElBodyPartPath::TElBodyPartPath(TElBodyPartPathHandle handle, TElOwnHandle ownHandle) : TElBodyPartReference(handle, ownHandle)
{
}

TElBodyPartPath::TElBodyPartPath() : TElBodyPartReference(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBodyPartPath_Create(&_Handle));
}

TElBodyPartPath::TElBodyPartPath(const std::vector<int32_t> &Value) : TElBodyPartReference(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBodyPartPath_Create_1(SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), &_Handle));
}

#endif /* SB_USE_CLASS_TELBODYPARTPATH */

#ifdef SB_USE_CLASS_TELEXTENDEDFAILINFO

void TElExtendedFailInfo::get_FailInfoOID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtendedFailInfo_get_FailInfoOID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1668353259, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElExtendedFailInfo::set_FailInfoOID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElExtendedFailInfo_set_FailInfoOID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElExtendedFailInfo::get_FailInfoValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtendedFailInfo_get_FailInfoValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1119462434, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElExtendedFailInfo::set_FailInfoValue(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElExtendedFailInfo_set_FailInfoValue(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElExtendedFailInfo::TElExtendedFailInfo(TElExtendedFailInfoHandle handle, TElOwnHandle ownHandle) : TElBodyPartReference(handle, ownHandle)
{
}

TElExtendedFailInfo::TElExtendedFailInfo() : TElBodyPartReference(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElExtendedFailInfo_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELEXTENDEDFAILINFO */

#ifdef SB_USE_CLASS_TELCMCSTATUSINFOV2ATTRIBUTE

bool TElCMCStatusInfoV2Attribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMCStatusInfoV2Attribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMCStatusInfoV2Attribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElCMCStatusInfoV2Attribute_LoadFromBuffer(_Handle, Buffer, Size));
}

#ifdef SB_USE_CLASS_TELBODYPARTREFERENCE
SB_INLINE int32_t TElCMCStatusInfoV2Attribute::AddBodyPartReference(TElBodyPartReference &Ref)
{
	int32_t OutResult;
	SBCheckError(TElCMCStatusInfoV2Attribute_AddBodyPartReference(_Handle, Ref.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCMCStatusInfoV2Attribute::AddBodyPartReference(TElBodyPartReference *Ref)
{
	int32_t OutResult;
	SBCheckError(TElCMCStatusInfoV2Attribute_AddBodyPartReference(_Handle, (Ref != NULL) ? Ref->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBODYPARTREFERENCE */

SB_INLINE void TElCMCStatusInfoV2Attribute::RemoveBodyPartReferece(int32_t Idx)
{
	SBCheckError(TElCMCStatusInfoV2Attribute_RemoveBodyPartReferece(_Handle, Idx));
}

SB_INLINE TClassHandle TElCMCStatusInfoV2Attribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElCMCStatusInfoV2Attribute_ClassType(&OutResult));
	return OutResult;
}

void TElCMCStatusInfoV2Attribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCMCStatusInfoV2Attribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(720370651, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElCMCStatusInfoV2Attribute::get_CMCStatus()
{
	int32_t OutResult;
	SBCheckError(TElCMCStatusInfoV2Attribute_get_CMCStatus(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMCStatusInfoV2Attribute::set_CMCStatus(int32_t Value)
{
	SBCheckError(TElCMCStatusInfoV2Attribute_set_CMCStatus(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELBODYPARTREFERENCE
TElBodyPartReference* TElCMCStatusInfoV2Attribute::get_BodyList(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMCStatusInfoV2Attribute_get_BodyList(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_BodyList)
		this->_Inst_BodyList = new TElBodyPartReference(hOutResult, ohFalse);
	else
		this->_Inst_BodyList->updateHandle(hOutResult);
	return this->_Inst_BodyList;
}
#endif /* SB_USE_CLASS_TELBODYPARTREFERENCE */

SB_INLINE int32_t TElCMCStatusInfoV2Attribute::get_BodyListCount()
{
	int32_t OutResult;
	SBCheckError(TElCMCStatusInfoV2Attribute_get_BodyListCount(_Handle, &OutResult));
	return OutResult;
}

void TElCMCStatusInfoV2Attribute::get_StatusString(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCMCStatusInfoV2Attribute_get_StatusString(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1732536317, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCMCStatusInfoV2Attribute::set_StatusString(const std::string &Value)
{
	SBCheckError(TElCMCStatusInfoV2Attribute_set_StatusString(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElCMCStatusInfoV2Attribute::get_HasPendInfo()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMCStatusInfoV2Attribute_get_HasPendInfo(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMCStatusInfoV2Attribute::set_HasPendInfo(bool Value)
{
	SBCheckError(TElCMCStatusInfoV2Attribute_set_HasPendInfo(_Handle, (int8_t)Value));
}

bool TElCMCStatusInfoV2Attribute::get_HasFailInfo()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMCStatusInfoV2Attribute_get_HasFailInfo(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMCStatusInfoV2Attribute::set_HasFailInfo(bool Value)
{
	SBCheckError(TElCMCStatusInfoV2Attribute_set_HasFailInfo(_Handle, (int8_t)Value));
}

bool TElCMCStatusInfoV2Attribute::get_HasExtendedFailInfo()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCMCStatusInfoV2Attribute_get_HasExtendedFailInfo(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCMCStatusInfoV2Attribute::set_HasExtendedFailInfo(bool Value)
{
	SBCheckError(TElCMCStatusInfoV2Attribute_set_HasExtendedFailInfo(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElCMCStatusInfoV2Attribute::get_FailInfo()
{
	int32_t OutResult;
	SBCheckError(TElCMCStatusInfoV2Attribute_get_FailInfo(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCMCStatusInfoV2Attribute::set_FailInfo(int32_t Value)
{
	SBCheckError(TElCMCStatusInfoV2Attribute_set_FailInfo(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELPENDINFO
TElPendInfo* TElCMCStatusInfoV2Attribute::get_PendInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMCStatusInfoV2Attribute_get_PendInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PendInfo)
		this->_Inst_PendInfo = new TElPendInfo(hOutResult, ohFalse);
	else
		this->_Inst_PendInfo->updateHandle(hOutResult);
	return this->_Inst_PendInfo;
}

SB_INLINE void TElCMCStatusInfoV2Attribute::set_PendInfo(TElPendInfo &Value)
{
	SBCheckError(TElCMCStatusInfoV2Attribute_set_PendInfo(_Handle, Value.getHandle()));
}

SB_INLINE void TElCMCStatusInfoV2Attribute::set_PendInfo(TElPendInfo *Value)
{
	SBCheckError(TElCMCStatusInfoV2Attribute_set_PendInfo(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPENDINFO */

#ifdef SB_USE_CLASS_TELEXTENDEDFAILINFO
TElExtendedFailInfo* TElCMCStatusInfoV2Attribute::get_ExtendedFailInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCMCStatusInfoV2Attribute_get_ExtendedFailInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ExtendedFailInfo)
		this->_Inst_ExtendedFailInfo = new TElExtendedFailInfo(hOutResult, ohFalse);
	else
		this->_Inst_ExtendedFailInfo->updateHandle(hOutResult);
	return this->_Inst_ExtendedFailInfo;
}

SB_INLINE void TElCMCStatusInfoV2Attribute::set_ExtendedFailInfo(TElExtendedFailInfo &Value)
{
	SBCheckError(TElCMCStatusInfoV2Attribute_set_ExtendedFailInfo(_Handle, Value.getHandle()));
}

SB_INLINE void TElCMCStatusInfoV2Attribute::set_ExtendedFailInfo(TElExtendedFailInfo *Value)
{
	SBCheckError(TElCMCStatusInfoV2Attribute_set_ExtendedFailInfo(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELEXTENDEDFAILINFO */

void TElCMCStatusInfoV2Attribute::initInstances()
{
#ifdef SB_USE_CLASS_TELBODYPARTREFERENCE
	this->_Inst_BodyList = NULL;
#endif /* SB_USE_CLASS_TELBODYPARTREFERENCE */
#ifdef SB_USE_CLASS_TELPENDINFO
	this->_Inst_PendInfo = NULL;
#endif /* SB_USE_CLASS_TELPENDINFO */
#ifdef SB_USE_CLASS_TELEXTENDEDFAILINFO
	this->_Inst_ExtendedFailInfo = NULL;
#endif /* SB_USE_CLASS_TELEXTENDEDFAILINFO */
}

TElCMCStatusInfoV2Attribute::TElCMCStatusInfoV2Attribute(TElCMCStatusInfoV2AttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
	initInstances();
}

TElCMCStatusInfoV2Attribute::TElCMCStatusInfoV2Attribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCMCStatusInfoV2Attribute_Create(&_Handle));
}

TElCMCStatusInfoV2Attribute::~TElCMCStatusInfoV2Attribute()
{
#ifdef SB_USE_CLASS_TELBODYPARTREFERENCE
	delete this->_Inst_BodyList;
	this->_Inst_BodyList = NULL;
#endif /* SB_USE_CLASS_TELBODYPARTREFERENCE */
#ifdef SB_USE_CLASS_TELPENDINFO
	delete this->_Inst_PendInfo;
	this->_Inst_PendInfo = NULL;
#endif /* SB_USE_CLASS_TELPENDINFO */
#ifdef SB_USE_CLASS_TELEXTENDEDFAILINFO
	delete this->_Inst_ExtendedFailInfo;
	this->_Inst_ExtendedFailInfo = NULL;
#endif /* SB_USE_CLASS_TELEXTENDEDFAILINFO */
}
#endif /* SB_USE_CLASS_TELCMCSTATUSINFOV2ATTRIBUTE */

#ifdef SB_USE_CLASS_TELADDEXTENSIONSATTRIBUTE

bool TElAddExtensionsAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAddExtensionsAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAddExtensionsAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElAddExtensionsAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElAddExtensionsAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElAddExtensionsAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElAddExtensionsAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElAddExtensionsAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2101025374, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElAddExtensionsAttribute::get_PKIDataReference()
{
	int32_t OutResult;
	SBCheckError(TElAddExtensionsAttribute_get_PKIDataReference(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAddExtensionsAttribute::set_PKIDataReference(int32_t Value)
{
	SBCheckError(TElAddExtensionsAttribute_set_PKIDataReference(_Handle, Value));
}

void TElAddExtensionsAttribute::get_CertReferences(std::vector<int32_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size() * 4;
	uint32_t _err = TElAddExtensionsAttribute_get_CertReferences(_Handle, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult / 4);
		SBCheckError(SBGetLastReturnBuffer(167281363, 1, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult / 4);
}

SB_INLINE void TElAddExtensionsAttribute::set_CertReferences(const std::vector<int32_t> &Value)
{
	SBCheckError(TElAddExtensionsAttribute_set_CertReferences(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
TElCertificateExtensions* TElAddExtensionsAttribute::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAddExtensionsAttribute_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElCertificateExtensions(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

void TElAddExtensionsAttribute::initInstances()
{
#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */
}

TElAddExtensionsAttribute::TElAddExtensionsAttribute(TElAddExtensionsAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
	initInstances();
}

TElAddExtensionsAttribute::TElAddExtensionsAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAddExtensionsAttribute_Create(&_Handle));
}

TElAddExtensionsAttribute::~TElAddExtensionsAttribute()
{
#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */
}
#endif /* SB_USE_CLASS_TELADDEXTENSIONSATTRIBUTE */

#ifdef SB_USE_CLASS_TELIDENTITYPROOFV2ATTRIBUTE

bool TElIdentityProofV2Attribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIdentityProofV2Attribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElIdentityProofV2Attribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElIdentityProofV2Attribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElIdentityProofV2Attribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElIdentityProofV2Attribute_ClassType(&OutResult));
	return OutResult;
}

void TElIdentityProofV2Attribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElIdentityProofV2Attribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1092221432, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
TElAlgorithmIdentifier* TElIdentityProofV2Attribute::get_HashAlgID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElIdentityProofV2Attribute_get_HashAlgID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HashAlgID)
		this->_Inst_HashAlgID = new TElAlgorithmIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_HashAlgID->updateHandle(hOutResult);
	return this->_Inst_HashAlgID;
}

SB_INLINE void TElIdentityProofV2Attribute::set_HashAlgID(TElAlgorithmIdentifier &Value)
{
	SBCheckError(TElIdentityProofV2Attribute_set_HashAlgID(_Handle, Value.getHandle()));
}

SB_INLINE void TElIdentityProofV2Attribute::set_HashAlgID(TElAlgorithmIdentifier *Value)
{
	SBCheckError(TElIdentityProofV2Attribute_set_HashAlgID(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
TElAlgorithmIdentifier* TElIdentityProofV2Attribute::get_MacAlgID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElIdentityProofV2Attribute_get_MacAlgID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_MacAlgID)
		this->_Inst_MacAlgID = new TElAlgorithmIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_MacAlgID->updateHandle(hOutResult);
	return this->_Inst_MacAlgID;
}

SB_INLINE void TElIdentityProofV2Attribute::set_MacAlgID(TElAlgorithmIdentifier &Value)
{
	SBCheckError(TElIdentityProofV2Attribute_set_MacAlgID(_Handle, Value.getHandle()));
}

SB_INLINE void TElIdentityProofV2Attribute::set_MacAlgID(TElAlgorithmIdentifier *Value)
{
	SBCheckError(TElIdentityProofV2Attribute_set_MacAlgID(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

void TElIdentityProofV2Attribute::get_Witness(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElIdentityProofV2Attribute_get_Witness(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1334014701, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElIdentityProofV2Attribute::set_Witness(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElIdentityProofV2Attribute_set_Witness(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElIdentityProofV2Attribute::initInstances()
{
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	this->_Inst_HashAlgID = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	this->_Inst_MacAlgID = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
}

TElIdentityProofV2Attribute::TElIdentityProofV2Attribute(TElIdentityProofV2AttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
	initInstances();
}

TElIdentityProofV2Attribute::TElIdentityProofV2Attribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElIdentityProofV2Attribute_Create(&_Handle));
}

TElIdentityProofV2Attribute::~TElIdentityProofV2Attribute()
{
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	delete this->_Inst_HashAlgID;
	this->_Inst_HashAlgID = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	delete this->_Inst_MacAlgID;
	this->_Inst_MacAlgID = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
}
#endif /* SB_USE_CLASS_TELIDENTITYPROOFV2ATTRIBUTE */

#ifdef SB_USE_CLASS_TELIDENTITYPROOFATTRIBUTE

bool TElIdentityProofAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIdentityProofAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElIdentityProofAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElIdentityProofAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElIdentityProofAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElIdentityProofAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElIdentityProofAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElIdentityProofAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(331243958, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElIdentityProofAttribute::get_IdentifyProof(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElIdentityProofAttribute_get_IdentifyProof(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1454909157, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElIdentityProofAttribute::set_IdentifyProof(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElIdentityProofAttribute_set_IdentifyProof(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElIdentityProofAttribute::TElIdentityProofAttribute(TElIdentityProofAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
}

TElIdentityProofAttribute::TElIdentityProofAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIdentityProofAttribute_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELIDENTITYPROOFATTRIBUTE */

#ifdef SB_USE_CLASS_TELPOPLINKWITNESSV2ATTRIBUTE

bool TElPopLinkWitnessV2Attribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPopLinkWitnessV2Attribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPopLinkWitnessV2Attribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElPopLinkWitnessV2Attribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElPopLinkWitnessV2Attribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPopLinkWitnessV2Attribute_ClassType(&OutResult));
	return OutResult;
}

void TElPopLinkWitnessV2Attribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPopLinkWitnessV2Attribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1634015907, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
TElAlgorithmIdentifier* TElPopLinkWitnessV2Attribute::get_KeyGenAlgID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPopLinkWitnessV2Attribute_get_KeyGenAlgID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyGenAlgID)
		this->_Inst_KeyGenAlgID = new TElAlgorithmIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_KeyGenAlgID->updateHandle(hOutResult);
	return this->_Inst_KeyGenAlgID;
}

SB_INLINE void TElPopLinkWitnessV2Attribute::set_KeyGenAlgID(TElAlgorithmIdentifier &Value)
{
	SBCheckError(TElPopLinkWitnessV2Attribute_set_KeyGenAlgID(_Handle, Value.getHandle()));
}

SB_INLINE void TElPopLinkWitnessV2Attribute::set_KeyGenAlgID(TElAlgorithmIdentifier *Value)
{
	SBCheckError(TElPopLinkWitnessV2Attribute_set_KeyGenAlgID(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
TElAlgorithmIdentifier* TElPopLinkWitnessV2Attribute::get_MacAlgID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPopLinkWitnessV2Attribute_get_MacAlgID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_MacAlgID)
		this->_Inst_MacAlgID = new TElAlgorithmIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_MacAlgID->updateHandle(hOutResult);
	return this->_Inst_MacAlgID;
}

SB_INLINE void TElPopLinkWitnessV2Attribute::set_MacAlgID(TElAlgorithmIdentifier &Value)
{
	SBCheckError(TElPopLinkWitnessV2Attribute_set_MacAlgID(_Handle, Value.getHandle()));
}

SB_INLINE void TElPopLinkWitnessV2Attribute::set_MacAlgID(TElAlgorithmIdentifier *Value)
{
	SBCheckError(TElPopLinkWitnessV2Attribute_set_MacAlgID(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

void TElPopLinkWitnessV2Attribute::get_Witness(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPopLinkWitnessV2Attribute_get_Witness(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1609501258, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPopLinkWitnessV2Attribute::set_Witness(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPopLinkWitnessV2Attribute_set_Witness(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPopLinkWitnessV2Attribute::initInstances()
{
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	this->_Inst_KeyGenAlgID = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	this->_Inst_MacAlgID = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
}

TElPopLinkWitnessV2Attribute::TElPopLinkWitnessV2Attribute(TElPopLinkWitnessV2AttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
	initInstances();
}

TElPopLinkWitnessV2Attribute::TElPopLinkWitnessV2Attribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPopLinkWitnessV2Attribute_Create(&_Handle));
}

TElPopLinkWitnessV2Attribute::~TElPopLinkWitnessV2Attribute()
{
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	delete this->_Inst_KeyGenAlgID;
	this->_Inst_KeyGenAlgID = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	delete this->_Inst_MacAlgID;
	this->_Inst_MacAlgID = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
}
#endif /* SB_USE_CLASS_TELPOPLINKWITNESSV2ATTRIBUTE */

#ifdef SB_USE_CLASS_TELPOPLINKWITNESSATTRIBUTE

bool TElPopLinkWitnessAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPopLinkWitnessAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPopLinkWitnessAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElPopLinkWitnessAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElPopLinkWitnessAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPopLinkWitnessAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElPopLinkWitnessAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPopLinkWitnessAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(432030382, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPopLinkWitnessAttribute::get_PopLinkWitness(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPopLinkWitnessAttribute_get_PopLinkWitness(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1555730185, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPopLinkWitnessAttribute::set_PopLinkWitness(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPopLinkWitnessAttribute_set_PopLinkWitness(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPopLinkWitnessAttribute::TElPopLinkWitnessAttribute(TElPopLinkWitnessAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
}

TElPopLinkWitnessAttribute::TElPopLinkWitnessAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPopLinkWitnessAttribute_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPOPLINKWITNESSATTRIBUTE */

#ifdef SB_USE_CLASS_TELDATARETURNATTRIBUTE

bool TElDataReturnAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDataReturnAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDataReturnAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElDataReturnAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElDataReturnAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElDataReturnAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElDataReturnAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDataReturnAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1107822818, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDataReturnAttribute::get_DataReturn(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDataReturnAttribute_get_DataReturn(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1380942018, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDataReturnAttribute::set_DataReturn(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDataReturnAttribute_set_DataReturn(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElDataReturnAttribute::TElDataReturnAttribute(TElDataReturnAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
}

TElDataReturnAttribute::TElDataReturnAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDataReturnAttribute_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDATARETURNATTRIBUTE */

#ifdef SB_USE_CLASS_TELTRANSACTIONIDENTIFIERATTRIBUTE

bool TElTransactionIdentifierAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTransactionIdentifierAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTransactionIdentifierAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElTransactionIdentifierAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElTransactionIdentifierAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElTransactionIdentifierAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElTransactionIdentifierAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElTransactionIdentifierAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1591548649, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElTransactionIdentifierAttribute::get_TransactionId()
{
	int32_t OutResult;
	SBCheckError(TElTransactionIdentifierAttribute_get_TransactionId(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTransactionIdentifierAttribute::set_TransactionId(int32_t Value)
{
	SBCheckError(TElTransactionIdentifierAttribute_set_TransactionId(_Handle, Value));
}

TElTransactionIdentifierAttribute::TElTransactionIdentifierAttribute(TElTransactionIdentifierAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
}

TElTransactionIdentifierAttribute::TElTransactionIdentifierAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTransactionIdentifierAttribute_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELTRANSACTIONIDENTIFIERATTRIBUTE */

#ifdef SB_USE_CLASS_TELSENDERNONCEATTRIBUTE

bool TElSenderNonceAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSenderNonceAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSenderNonceAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElSenderNonceAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElSenderNonceAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElSenderNonceAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElSenderNonceAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSenderNonceAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-632432459, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSenderNonceAttribute::get_Nonce(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSenderNonceAttribute_get_Nonce(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-279876223, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSenderNonceAttribute::set_Nonce(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSenderNonceAttribute_set_Nonce(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElSenderNonceAttribute::TElSenderNonceAttribute(TElSenderNonceAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
}

TElSenderNonceAttribute::TElSenderNonceAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSenderNonceAttribute_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSENDERNONCEATTRIBUTE */

#ifdef SB_USE_CLASS_TELRECIPIENTNONCEATTRIBUTE

bool TElRecipientNonceAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRecipientNonceAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElRecipientNonceAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElRecipientNonceAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElRecipientNonceAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElRecipientNonceAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElRecipientNonceAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRecipientNonceAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1542670228, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElRecipientNonceAttribute::get_Nonce(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRecipientNonceAttribute_get_Nonce(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(58619657, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElRecipientNonceAttribute::set_Nonce(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElRecipientNonceAttribute_set_Nonce(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElRecipientNonceAttribute::TElRecipientNonceAttribute(TElRecipientNonceAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
}

TElRecipientNonceAttribute::TElRecipientNonceAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRecipientNonceAttribute_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELRECIPIENTNONCEATTRIBUTE */

#ifdef SB_USE_CLASS_TELENCRYPTEDPOPATTRIBUTE

bool TElEncryptedPopAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElEncryptedPopAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElEncryptedPopAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElEncryptedPopAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElEncryptedPopAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElEncryptedPopAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElEncryptedPopAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElEncryptedPopAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-488507294, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELTAGGEDREQUEST
TElTaggedRequest* TElEncryptedPopAttribute::get_Request()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElEncryptedPopAttribute_get_Request(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Request)
		this->_Inst_Request = new TElTaggedRequest(hOutResult, ohFalse);
	else
		this->_Inst_Request->updateHandle(hOutResult);
	return this->_Inst_Request;
}

SB_INLINE void TElEncryptedPopAttribute::set_Request(TElTaggedRequest &Value)
{
	SBCheckError(TElEncryptedPopAttribute_set_Request(_Handle, Value.getHandle()));
}

SB_INLINE void TElEncryptedPopAttribute::set_Request(TElTaggedRequest *Value)
{
	SBCheckError(TElEncryptedPopAttribute_set_Request(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELTAGGEDREQUEST */

#ifdef SB_USE_CLASS_TELCONTENTINFO
TElContentInfo* TElEncryptedPopAttribute::get_CMS()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElEncryptedPopAttribute_get_CMS(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CMS)
		this->_Inst_CMS = new TElContentInfo(hOutResult, ohFalse);
	else
		this->_Inst_CMS->updateHandle(hOutResult);
	return this->_Inst_CMS;
}

SB_INLINE void TElEncryptedPopAttribute::set_CMS(TElContentInfo &Value)
{
	SBCheckError(TElEncryptedPopAttribute_set_CMS(_Handle, Value.getHandle()));
}

SB_INLINE void TElEncryptedPopAttribute::set_CMS(TElContentInfo *Value)
{
	SBCheckError(TElEncryptedPopAttribute_set_CMS(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCONTENTINFO */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
TElAlgorithmIdentifier* TElEncryptedPopAttribute::get_POPAlgID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElEncryptedPopAttribute_get_POPAlgID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_POPAlgID)
		this->_Inst_POPAlgID = new TElAlgorithmIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_POPAlgID->updateHandle(hOutResult);
	return this->_Inst_POPAlgID;
}

SB_INLINE void TElEncryptedPopAttribute::set_POPAlgID(TElAlgorithmIdentifier &Value)
{
	SBCheckError(TElEncryptedPopAttribute_set_POPAlgID(_Handle, Value.getHandle()));
}

SB_INLINE void TElEncryptedPopAttribute::set_POPAlgID(TElAlgorithmIdentifier *Value)
{
	SBCheckError(TElEncryptedPopAttribute_set_POPAlgID(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
TElAlgorithmIdentifier* TElEncryptedPopAttribute::get_WitnessAlgID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElEncryptedPopAttribute_get_WitnessAlgID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WitnessAlgID)
		this->_Inst_WitnessAlgID = new TElAlgorithmIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_WitnessAlgID->updateHandle(hOutResult);
	return this->_Inst_WitnessAlgID;
}

SB_INLINE void TElEncryptedPopAttribute::set_WitnessAlgID(TElAlgorithmIdentifier &Value)
{
	SBCheckError(TElEncryptedPopAttribute_set_WitnessAlgID(_Handle, Value.getHandle()));
}

SB_INLINE void TElEncryptedPopAttribute::set_WitnessAlgID(TElAlgorithmIdentifier *Value)
{
	SBCheckError(TElEncryptedPopAttribute_set_WitnessAlgID(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

void TElEncryptedPopAttribute::get_Witness(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElEncryptedPopAttribute_get_Witness(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1981894584, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElEncryptedPopAttribute::set_Witness(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElEncryptedPopAttribute_set_Witness(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElEncryptedPopAttribute::initInstances()
{
#ifdef SB_USE_CLASS_TELTAGGEDREQUEST
	this->_Inst_Request = NULL;
#endif /* SB_USE_CLASS_TELTAGGEDREQUEST */
#ifdef SB_USE_CLASS_TELCONTENTINFO
	this->_Inst_CMS = NULL;
#endif /* SB_USE_CLASS_TELCONTENTINFO */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	this->_Inst_POPAlgID = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	this->_Inst_WitnessAlgID = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
}

TElEncryptedPopAttribute::TElEncryptedPopAttribute(TElEncryptedPopAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
	initInstances();
}

TElEncryptedPopAttribute::TElEncryptedPopAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElEncryptedPopAttribute_Create(&_Handle));
}

TElEncryptedPopAttribute::~TElEncryptedPopAttribute()
{
#ifdef SB_USE_CLASS_TELTAGGEDREQUEST
	delete this->_Inst_Request;
	this->_Inst_Request = NULL;
#endif /* SB_USE_CLASS_TELTAGGEDREQUEST */
#ifdef SB_USE_CLASS_TELCONTENTINFO
	delete this->_Inst_CMS;
	this->_Inst_CMS = NULL;
#endif /* SB_USE_CLASS_TELCONTENTINFO */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	delete this->_Inst_POPAlgID;
	this->_Inst_POPAlgID = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	delete this->_Inst_WitnessAlgID;
	this->_Inst_WitnessAlgID = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
}
#endif /* SB_USE_CLASS_TELENCRYPTEDPOPATTRIBUTE */

#ifdef SB_USE_CLASS_TELDECRYPTEDPOPATTRIBUTE

bool TElDecryptedPopAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDecryptedPopAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDecryptedPopAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElDecryptedPopAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElDecryptedPopAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElDecryptedPopAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElDecryptedPopAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDecryptedPopAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1902653815, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElDecryptedPopAttribute::get_BodyPartId()
{
	int32_t OutResult;
	SBCheckError(TElDecryptedPopAttribute_get_BodyPartId(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDecryptedPopAttribute::set_BodyPartId(int32_t Value)
{
	SBCheckError(TElDecryptedPopAttribute_set_BodyPartId(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
TElAlgorithmIdentifier* TElDecryptedPopAttribute::get_POPAlgID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDecryptedPopAttribute_get_POPAlgID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_POPAlgID)
		this->_Inst_POPAlgID = new TElAlgorithmIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_POPAlgID->updateHandle(hOutResult);
	return this->_Inst_POPAlgID;
}

SB_INLINE void TElDecryptedPopAttribute::set_POPAlgID(TElAlgorithmIdentifier &Value)
{
	SBCheckError(TElDecryptedPopAttribute_set_POPAlgID(_Handle, Value.getHandle()));
}

SB_INLINE void TElDecryptedPopAttribute::set_POPAlgID(TElAlgorithmIdentifier *Value)
{
	SBCheckError(TElDecryptedPopAttribute_set_POPAlgID(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

void TElDecryptedPopAttribute::get_POP(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDecryptedPopAttribute_get_POP(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-714254017, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDecryptedPopAttribute::set_POP(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDecryptedPopAttribute_set_POP(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElDecryptedPopAttribute::initInstances()
{
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	this->_Inst_POPAlgID = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
}

TElDecryptedPopAttribute::TElDecryptedPopAttribute(TElDecryptedPopAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
	initInstances();
}

TElDecryptedPopAttribute::TElDecryptedPopAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDecryptedPopAttribute_Create(&_Handle));
}

TElDecryptedPopAttribute::~TElDecryptedPopAttribute()
{
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	delete this->_Inst_POPAlgID;
	this->_Inst_POPAlgID = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
}
#endif /* SB_USE_CLASS_TELDECRYPTEDPOPATTRIBUTE */

#ifdef SB_USE_CLASS_TELLRAPOPWITNESSATTRIBUTE

bool TElLraPopWitnessAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElLraPopWitnessAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElLraPopWitnessAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElLraPopWitnessAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElLraPopWitnessAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElLraPopWitnessAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElLraPopWitnessAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElLraPopWitnessAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-294512769, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElLraPopWitnessAttribute::get_BodyPartId()
{
	int32_t OutResult;
	SBCheckError(TElLraPopWitnessAttribute_get_BodyPartId(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElLraPopWitnessAttribute::set_BodyPartId(int32_t Value)
{
	SBCheckError(TElLraPopWitnessAttribute_set_BodyPartId(_Handle, Value));
}

void TElLraPopWitnessAttribute::get_BodyIds(std::vector<int32_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size() * 4;
	uint32_t _err = TElLraPopWitnessAttribute_get_BodyIds(_Handle, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult / 4);
		SBCheckError(SBGetLastReturnBuffer(-1601392985, 1, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult / 4);
}

SB_INLINE void TElLraPopWitnessAttribute::set_BodyIds(const std::vector<int32_t> &Value)
{
	SBCheckError(TElLraPopWitnessAttribute_set_BodyIds(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElLraPopWitnessAttribute::TElLraPopWitnessAttribute(TElLraPopWitnessAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
}

TElLraPopWitnessAttribute::TElLraPopWitnessAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLraPopWitnessAttribute_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELLRAPOPWITNESSATTRIBUTE */

#ifdef SB_USE_CLASS_TELGETCERTIFICATEATTRIBUTE

bool TElGetCertificateAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGetCertificateAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGetCertificateAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElGetCertificateAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElGetCertificateAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElGetCertificateAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElGetCertificateAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGetCertificateAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1333477418, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELGENERALNAME
TElGeneralName* TElGetCertificateAttribute::get_IssuerName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGetCertificateAttribute_get_IssuerName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IssuerName)
		this->_Inst_IssuerName = new TElGeneralName(hOutResult, ohFalse);
	else
		this->_Inst_IssuerName->updateHandle(hOutResult);
	return this->_Inst_IssuerName;
}

SB_INLINE void TElGetCertificateAttribute::set_IssuerName(TElGeneralName &Value)
{
	SBCheckError(TElGetCertificateAttribute_set_IssuerName(_Handle, Value.getHandle()));
}

SB_INLINE void TElGetCertificateAttribute::set_IssuerName(TElGeneralName *Value)
{
	SBCheckError(TElGetCertificateAttribute_set_IssuerName(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELGENERALNAME */

SB_INLINE int32_t TElGetCertificateAttribute::get_SerialNumber()
{
	int32_t OutResult;
	SBCheckError(TElGetCertificateAttribute_get_SerialNumber(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGetCertificateAttribute::set_SerialNumber(int32_t Value)
{
	SBCheckError(TElGetCertificateAttribute_set_SerialNumber(_Handle, Value));
}

void TElGetCertificateAttribute::initInstances()
{
#ifdef SB_USE_CLASS_TELGENERALNAME
	this->_Inst_IssuerName = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
}

TElGetCertificateAttribute::TElGetCertificateAttribute(TElGetCertificateAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
	initInstances();
}

TElGetCertificateAttribute::TElGetCertificateAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGetCertificateAttribute_Create(&_Handle));
}

TElGetCertificateAttribute::~TElGetCertificateAttribute()
{
#ifdef SB_USE_CLASS_TELGENERALNAME
	delete this->_Inst_IssuerName;
	this->_Inst_IssuerName = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
}
#endif /* SB_USE_CLASS_TELGETCERTIFICATEATTRIBUTE */

#ifdef SB_USE_CLASS_TELGETCRLATTRIBUTE

bool TElGetCRLAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGetCRLAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGetCRLAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElGetCRLAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElGetCRLAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElGetCRLAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElGetCRLAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGetCRLAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(157229463, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElGetCRLAttribute::get_IssuerName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGetCRLAttribute_get_IssuerName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IssuerName)
		this->_Inst_IssuerName = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_IssuerName->updateHandle(hOutResult);
	return this->_Inst_IssuerName;
}

SB_INLINE void TElGetCRLAttribute::set_IssuerName(TElRelativeDistinguishedName &Value)
{
	SBCheckError(TElGetCRLAttribute_set_IssuerName(_Handle, Value.getHandle()));
}

SB_INLINE void TElGetCRLAttribute::set_IssuerName(TElRelativeDistinguishedName *Value)
{
	SBCheckError(TElGetCRLAttribute_set_IssuerName(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELGENERALNAME
TElGeneralName* TElGetCRLAttribute::get_CRLName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGetCRLAttribute_get_CRLName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLName)
		this->_Inst_CRLName = new TElGeneralName(hOutResult, ohFalse);
	else
		this->_Inst_CRLName->updateHandle(hOutResult);
	return this->_Inst_CRLName;
}

SB_INLINE void TElGetCRLAttribute::set_CRLName(TElGeneralName &Value)
{
	SBCheckError(TElGetCRLAttribute_set_CRLName(_Handle, Value.getHandle()));
}

SB_INLINE void TElGetCRLAttribute::set_CRLName(TElGeneralName *Value)
{
	SBCheckError(TElGetCRLAttribute_set_CRLName(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELGENERALNAME */

SB_INLINE int64_t TElGetCRLAttribute::get_Time()
{
	int64_t OutResult;
	SBCheckError(TElGetCRLAttribute_get_Time(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGetCRLAttribute::set_Time(int64_t Value)
{
	SBCheckError(TElGetCRLAttribute_set_Time(_Handle, Value));
}

TSBCRLReasonFlags TElGetCRLAttribute::get_Reasons()
{
	TSBCRLReasonFlagsRaw OutResultRaw = 0;
	SBCheckError(TElGetCRLAttribute_get_Reasons(_Handle, &OutResultRaw));
	return (TSBCRLReasonFlags)OutResultRaw;
}

SB_INLINE void TElGetCRLAttribute::set_Reasons(TSBCRLReasonFlags Value)
{
	SBCheckError(TElGetCRLAttribute_set_Reasons(_Handle, (TSBCRLReasonFlagsRaw)Value));
}

void TElGetCRLAttribute::initInstances()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_IssuerName = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELGENERALNAME
	this->_Inst_CRLName = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
}

TElGetCRLAttribute::TElGetCRLAttribute(TElGetCRLAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
	initInstances();
}

TElGetCRLAttribute::TElGetCRLAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGetCRLAttribute_Create(&_Handle));
}

TElGetCRLAttribute::~TElGetCRLAttribute()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_IssuerName;
	this->_Inst_IssuerName = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELGENERALNAME
	delete this->_Inst_CRLName;
	this->_Inst_CRLName = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
}
#endif /* SB_USE_CLASS_TELGETCRLATTRIBUTE */

#ifdef SB_USE_CLASS_TELREVOCATIONREQUESTATTRIBUTE

bool TElRevocationRequestAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRevocationRequestAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElRevocationRequestAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElRevocationRequestAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElRevocationRequestAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElRevocationRequestAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElRevocationRequestAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRevocationRequestAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1340243774, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElRevocationRequestAttribute::get_IssuerName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElRevocationRequestAttribute_get_IssuerName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IssuerName)
		this->_Inst_IssuerName = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_IssuerName->updateHandle(hOutResult);
	return this->_Inst_IssuerName;
}

SB_INLINE void TElRevocationRequestAttribute::set_IssuerName(TElRelativeDistinguishedName &Value)
{
	SBCheckError(TElRevocationRequestAttribute_set_IssuerName(_Handle, Value.getHandle()));
}

SB_INLINE void TElRevocationRequestAttribute::set_IssuerName(TElRelativeDistinguishedName *Value)
{
	SBCheckError(TElRevocationRequestAttribute_set_IssuerName(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE int32_t TElRevocationRequestAttribute::get_SerialNumber()
{
	int32_t OutResult;
	SBCheckError(TElRevocationRequestAttribute_get_SerialNumber(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRevocationRequestAttribute::set_SerialNumber(int32_t Value)
{
	SBCheckError(TElRevocationRequestAttribute_set_SerialNumber(_Handle, Value));
}

TSBCRLReasonFlag TElRevocationRequestAttribute::get_Reason()
{
	TSBCRLReasonFlagRaw OutResultRaw = 0;
	SBCheckError(TElRevocationRequestAttribute_get_Reason(_Handle, &OutResultRaw));
	return (TSBCRLReasonFlag)OutResultRaw;
}

SB_INLINE void TElRevocationRequestAttribute::set_Reason(TSBCRLReasonFlag Value)
{
	SBCheckError(TElRevocationRequestAttribute_set_Reason(_Handle, (TSBCRLReasonFlagRaw)Value));
}

SB_INLINE int64_t TElRevocationRequestAttribute::get_InvalidityDate()
{
	int64_t OutResult;
	SBCheckError(TElRevocationRequestAttribute_get_InvalidityDate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRevocationRequestAttribute::set_InvalidityDate(int64_t Value)
{
	SBCheckError(TElRevocationRequestAttribute_set_InvalidityDate(_Handle, Value));
}

void TElRevocationRequestAttribute::get_SharedSecret(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRevocationRequestAttribute_get_SharedSecret(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-304735845, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElRevocationRequestAttribute::set_SharedSecret(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElRevocationRequestAttribute_set_SharedSecret(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElRevocationRequestAttribute::get_Comment(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElRevocationRequestAttribute_get_Comment(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-121702738, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElRevocationRequestAttribute::set_Comment(const std::string &Value)
{
	SBCheckError(TElRevocationRequestAttribute_set_Comment(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElRevocationRequestAttribute::initInstances()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_IssuerName = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
}

TElRevocationRequestAttribute::TElRevocationRequestAttribute(TElRevocationRequestAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
	initInstances();
}

TElRevocationRequestAttribute::TElRevocationRequestAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElRevocationRequestAttribute_Create(&_Handle));
}

TElRevocationRequestAttribute::~TElRevocationRequestAttribute()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_IssuerName;
	this->_Inst_IssuerName = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
}
#endif /* SB_USE_CLASS_TELREVOCATIONREQUESTATTRIBUTE */

#ifdef SB_USE_CLASS_TELREGISTRATIONINFORMATIONATTRIBUTE

bool TElRegistrationInformationAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRegistrationInformationAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElRegistrationInformationAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElRegistrationInformationAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElRegistrationInformationAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElRegistrationInformationAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElRegistrationInformationAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRegistrationInformationAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1000313823, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElRegistrationInformationAttribute::get_RegInfo(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRegistrationInformationAttribute_get_RegInfo(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(441367539, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElRegistrationInformationAttribute::set_RegInfo(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElRegistrationInformationAttribute_set_RegInfo(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElRegistrationInformationAttribute::TElRegistrationInformationAttribute(TElRegistrationInformationAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
}

TElRegistrationInformationAttribute::TElRegistrationInformationAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRegistrationInformationAttribute_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELREGISTRATIONINFORMATIONATTRIBUTE */

#ifdef SB_USE_CLASS_TELRESPONSEINFORMATIONATTRIBUTE

bool TElResponseInformationAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElResponseInformationAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElResponseInformationAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElResponseInformationAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElResponseInformationAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElResponseInformationAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElResponseInformationAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElResponseInformationAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-110270895, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElResponseInformationAttribute::get_ResponseInfo(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElResponseInformationAttribute_get_ResponseInfo(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1959431709, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElResponseInformationAttribute::set_ResponseInfo(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElResponseInformationAttribute_set_ResponseInfo(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElResponseInformationAttribute::TElResponseInformationAttribute(TElResponseInformationAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
}

TElResponseInformationAttribute::TElResponseInformationAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElResponseInformationAttribute_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELRESPONSEINFORMATIONATTRIBUTE */

#ifdef SB_USE_CLASS_TELQUERYPENDINGATTRIBUTE

bool TElQueryPendingAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElQueryPendingAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElQueryPendingAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElQueryPendingAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElQueryPendingAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElQueryPendingAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElQueryPendingAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElQueryPendingAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1698016562, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElQueryPendingAttribute::get_QueryPending(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElQueryPendingAttribute_get_QueryPending(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(526744689, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElQueryPendingAttribute::set_QueryPending(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElQueryPendingAttribute_set_QueryPending(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElQueryPendingAttribute::TElQueryPendingAttribute(TElQueryPendingAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
}

TElQueryPendingAttribute::TElQueryPendingAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElQueryPendingAttribute_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELQUERYPENDINGATTRIBUTE */

#ifdef SB_USE_CLASS_TELCONFIRMCERTACCEPTANCEATTRIBUTE

bool TElConfirmCertAcceptanceAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElConfirmCertAcceptanceAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElConfirmCertAcceptanceAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElConfirmCertAcceptanceAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElConfirmCertAcceptanceAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElConfirmCertAcceptanceAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElConfirmCertAcceptanceAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElConfirmCertAcceptanceAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1958639514, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELGENERALNAME
TElGeneralName* TElConfirmCertAcceptanceAttribute::get_IssuerName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElConfirmCertAcceptanceAttribute_get_IssuerName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IssuerName)
		this->_Inst_IssuerName = new TElGeneralName(hOutResult, ohFalse);
	else
		this->_Inst_IssuerName->updateHandle(hOutResult);
	return this->_Inst_IssuerName;
}

SB_INLINE void TElConfirmCertAcceptanceAttribute::set_IssuerName(TElGeneralName &Value)
{
	SBCheckError(TElConfirmCertAcceptanceAttribute_set_IssuerName(_Handle, Value.getHandle()));
}

SB_INLINE void TElConfirmCertAcceptanceAttribute::set_IssuerName(TElGeneralName *Value)
{
	SBCheckError(TElConfirmCertAcceptanceAttribute_set_IssuerName(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELGENERALNAME */

SB_INLINE int32_t TElConfirmCertAcceptanceAttribute::get_SerialNumber()
{
	int32_t OutResult;
	SBCheckError(TElConfirmCertAcceptanceAttribute_get_SerialNumber(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElConfirmCertAcceptanceAttribute::set_SerialNumber(int32_t Value)
{
	SBCheckError(TElConfirmCertAcceptanceAttribute_set_SerialNumber(_Handle, Value));
}

void TElConfirmCertAcceptanceAttribute::initInstances()
{
#ifdef SB_USE_CLASS_TELGENERALNAME
	this->_Inst_IssuerName = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
}

TElConfirmCertAcceptanceAttribute::TElConfirmCertAcceptanceAttribute(TElConfirmCertAcceptanceAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
	initInstances();
}

TElConfirmCertAcceptanceAttribute::TElConfirmCertAcceptanceAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElConfirmCertAcceptanceAttribute_Create(&_Handle));
}

TElConfirmCertAcceptanceAttribute::~TElConfirmCertAcceptanceAttribute()
{
#ifdef SB_USE_CLASS_TELGENERALNAME
	delete this->_Inst_IssuerName;
	this->_Inst_IssuerName = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
}
#endif /* SB_USE_CLASS_TELCONFIRMCERTACCEPTANCEATTRIBUTE */

#ifdef SB_USE_CLASS_TELPUBLISHTRUSTANCHORSATTRIBUTE

bool TElPublishTrustAnchorsAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublishTrustAnchorsAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPublishTrustAnchorsAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElPublishTrustAnchorsAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElPublishTrustAnchorsAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPublishTrustAnchorsAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElPublishTrustAnchorsAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPublishTrustAnchorsAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1507269368, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElPublishTrustAnchorsAttribute::get_SeqNumber()
{
	int32_t OutResult;
	SBCheckError(TElPublishTrustAnchorsAttribute_get_SeqNumber(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPublishTrustAnchorsAttribute::set_SeqNumber(int32_t Value)
{
	SBCheckError(TElPublishTrustAnchorsAttribute_set_SeqNumber(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
TElAlgorithmIdentifier* TElPublishTrustAnchorsAttribute::get_HashAlgorithm()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPublishTrustAnchorsAttribute_get_HashAlgorithm(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HashAlgorithm)
		this->_Inst_HashAlgorithm = new TElAlgorithmIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_HashAlgorithm->updateHandle(hOutResult);
	return this->_Inst_HashAlgorithm;
}

SB_INLINE void TElPublishTrustAnchorsAttribute::set_HashAlgorithm(TElAlgorithmIdentifier &Value)
{
	SBCheckError(TElPublishTrustAnchorsAttribute_set_HashAlgorithm(_Handle, Value.getHandle()));
}

SB_INLINE void TElPublishTrustAnchorsAttribute::set_HashAlgorithm(TElAlgorithmIdentifier *Value)
{
	SBCheckError(TElPublishTrustAnchorsAttribute_set_HashAlgorithm(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

void TElPublishTrustAnchorsAttribute::initInstances()
{
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	this->_Inst_HashAlgorithm = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
}

TElPublishTrustAnchorsAttribute::TElPublishTrustAnchorsAttribute(TElPublishTrustAnchorsAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
	initInstances();
}

TElPublishTrustAnchorsAttribute::TElPublishTrustAnchorsAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPublishTrustAnchorsAttribute_Create(&_Handle));
}

TElPublishTrustAnchorsAttribute::~TElPublishTrustAnchorsAttribute()
{
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	delete this->_Inst_HashAlgorithm;
	this->_Inst_HashAlgorithm = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
}
#endif /* SB_USE_CLASS_TELPUBLISHTRUSTANCHORSATTRIBUTE */

#ifdef SB_USE_CLASS_TELAUTHENTICATEDDATAATTRIBUTE

bool TElAuthenticatedDataAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAuthenticatedDataAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAuthenticatedDataAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElAuthenticatedDataAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElAuthenticatedDataAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElAuthenticatedDataAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElAuthenticatedDataAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElAuthenticatedDataAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1482904597, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElAuthenticatedDataAttribute::get_AuthPublish()
{
	int32_t OutResult;
	SBCheckError(TElAuthenticatedDataAttribute_get_AuthPublish(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAuthenticatedDataAttribute::set_AuthPublish(int32_t Value)
{
	SBCheckError(TElAuthenticatedDataAttribute_set_AuthPublish(_Handle, Value));
}

TElAuthenticatedDataAttribute::TElAuthenticatedDataAttribute(TElAuthenticatedDataAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
}

TElAuthenticatedDataAttribute::TElAuthenticatedDataAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAuthenticatedDataAttribute_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELAUTHENTICATEDDATAATTRIBUTE */

#ifdef SB_USE_CLASS_TELBATCHREQUESTSATTRIBUTE

bool TElBatchRequestsAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBatchRequestsAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBatchRequestsAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElBatchRequestsAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElBatchRequestsAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBatchRequestsAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElBatchRequestsAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBatchRequestsAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-143956791, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBatchRequestsAttribute::get_BodyPartList(std::vector<int32_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size() * 4;
	uint32_t _err = TElBatchRequestsAttribute_get_BodyPartList(_Handle, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult / 4);
		SBCheckError(SBGetLastReturnBuffer(-707146080, 1, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult / 4);
}

SB_INLINE void TElBatchRequestsAttribute::set_BodyPartList(const std::vector<int32_t> &Value)
{
	SBCheckError(TElBatchRequestsAttribute_set_BodyPartList(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElBatchRequestsAttribute::TElBatchRequestsAttribute(TElBatchRequestsAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
}

TElBatchRequestsAttribute::TElBatchRequestsAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBatchRequestsAttribute_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELBATCHREQUESTSATTRIBUTE */

#ifdef SB_USE_CLASS_TELBATCHRESPONSESATTRIBUTE

bool TElBatchResponsesAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBatchResponsesAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBatchResponsesAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElBatchResponsesAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElBatchResponsesAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBatchResponsesAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElBatchResponsesAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBatchResponsesAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1903448977, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBatchResponsesAttribute::get_BodyPartList(std::vector<int32_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size() * 4;
	uint32_t _err = TElBatchResponsesAttribute_get_BodyPartList(_Handle, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult / 4);
		SBCheckError(SBGetLastReturnBuffer(-995519654, 1, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult / 4);
}

SB_INLINE void TElBatchResponsesAttribute::set_BodyPartList(const std::vector<int32_t> &Value)
{
	SBCheckError(TElBatchResponsesAttribute_set_BodyPartList(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElBatchResponsesAttribute::TElBatchResponsesAttribute(TElBatchResponsesAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
}

TElBatchResponsesAttribute::TElBatchResponsesAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBatchResponsesAttribute_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELBATCHRESPONSESATTRIBUTE */

#ifdef SB_USE_CLASS_TELPOPLINKRANDOMATTRIBUTE

bool TElPopLinkRandomAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPopLinkRandomAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPopLinkRandomAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElPopLinkRandomAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElPopLinkRandomAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPopLinkRandomAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElPopLinkRandomAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPopLinkRandomAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2144123451, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPopLinkRandomAttribute::get_PopLinkRandom(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPopLinkRandomAttribute_get_PopLinkRandom(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-305394513, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPopLinkRandomAttribute::set_PopLinkRandom(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPopLinkRandomAttribute_set_PopLinkRandom(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPopLinkRandomAttribute::TElPopLinkRandomAttribute(TElPopLinkRandomAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
}

TElPopLinkRandomAttribute::TElPopLinkRandomAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPopLinkRandomAttribute_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPOPLINKRANDOMATTRIBUTE */

#ifdef SB_USE_CLASS_TELSINGLEPUBINFO

TSBPKIPublishMethod TElSinglePubInfo::get_PubMethod()
{
	TSBPKIPublishMethodRaw OutResultRaw = 0;
	SBCheckError(TElSinglePubInfo_get_PubMethod(_Handle, &OutResultRaw));
	return (TSBPKIPublishMethod)OutResultRaw;
}

SB_INLINE void TElSinglePubInfo::set_PubMethod(TSBPKIPublishMethod Value)
{
	SBCheckError(TElSinglePubInfo_set_PubMethod(_Handle, (TSBPKIPublishMethodRaw)Value));
}

#ifdef SB_USE_CLASS_TELGENERALNAME
TElGeneralName* TElSinglePubInfo::get_PubLocation()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSinglePubInfo_get_PubLocation(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PubLocation)
		this->_Inst_PubLocation = new TElGeneralName(hOutResult, ohFalse);
	else
		this->_Inst_PubLocation->updateHandle(hOutResult);
	return this->_Inst_PubLocation;
}

SB_INLINE void TElSinglePubInfo::set_PubLocation(TElGeneralName &Value)
{
	SBCheckError(TElSinglePubInfo_set_PubLocation(_Handle, Value.getHandle()));
}

SB_INLINE void TElSinglePubInfo::set_PubLocation(TElGeneralName *Value)
{
	SBCheckError(TElSinglePubInfo_set_PubLocation(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELGENERALNAME */

void TElSinglePubInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELGENERALNAME
	this->_Inst_PubLocation = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
}

TElSinglePubInfo::TElSinglePubInfo(TElSinglePubInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElSinglePubInfo::TElSinglePubInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSinglePubInfo_Create(&_Handle));
}

TElSinglePubInfo::~TElSinglePubInfo()
{
#ifdef SB_USE_CLASS_TELGENERALNAME
	delete this->_Inst_PubLocation;
	this->_Inst_PubLocation = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
}
#endif /* SB_USE_CLASS_TELSINGLEPUBINFO */

#ifdef SB_USE_CLASS_TELPKIPUBLICATIONINFO

SB_INLINE int32_t TElPKIPublicationInfo::AddInfo()
{
	int32_t OutResult;
	SBCheckError(TElPKIPublicationInfo_AddInfo(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKIPublicationInfo::RemoveInfo(int32_t Idx)
{
	SBCheckError(TElPKIPublicationInfo_RemoveInfo(_Handle, Idx));
}

TSBPKIPublicationAction TElPKIPublicationInfo::get_Action()
{
	TSBPKIPublicationActionRaw OutResultRaw = 0;
	SBCheckError(TElPKIPublicationInfo_get_Action(_Handle, &OutResultRaw));
	return (TSBPKIPublicationAction)OutResultRaw;
}

SB_INLINE void TElPKIPublicationInfo::set_Action(TSBPKIPublicationAction Value)
{
	SBCheckError(TElPKIPublicationInfo_set_Action(_Handle, (TSBPKIPublicationActionRaw)Value));
}

#ifdef SB_USE_CLASS_TELSINGLEPUBINFO
TElSinglePubInfo* TElPKIPublicationInfo::get_Infos(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKIPublicationInfo_get_Infos(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Infos)
		this->_Inst_Infos = new TElSinglePubInfo(hOutResult, ohFalse);
	else
		this->_Inst_Infos->updateHandle(hOutResult);
	return this->_Inst_Infos;
}
#endif /* SB_USE_CLASS_TELSINGLEPUBINFO */

SB_INLINE int32_t TElPKIPublicationInfo::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElPKIPublicationInfo_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElPKIPublicationInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELSINGLEPUBINFO
	this->_Inst_Infos = NULL;
#endif /* SB_USE_CLASS_TELSINGLEPUBINFO */
}

TElPKIPublicationInfo::TElPKIPublicationInfo(TElPKIPublicationInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKIPublicationInfo::TElPKIPublicationInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKIPublicationInfo_Create(&_Handle));
}

TElPKIPublicationInfo::~TElPKIPublicationInfo()
{
#ifdef SB_USE_CLASS_TELSINGLEPUBINFO
	delete this->_Inst_Infos;
	this->_Inst_Infos = NULL;
#endif /* SB_USE_CLASS_TELSINGLEPUBINFO */
}
#endif /* SB_USE_CLASS_TELPKIPUBLICATIONINFO */

#ifdef SB_USE_CLASS_TELPUBLICATIONINFORMATIONATTRIBUTE

bool TElPublicationInformationAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPublicationInformationAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPublicationInformationAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElPublicationInformationAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElPublicationInformationAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPublicationInformationAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElPublicationInformationAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPublicationInformationAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(30907164, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
TElAlgorithmIdentifier* TElPublicationInformationAttribute::get_HashAlgorithm()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPublicationInformationAttribute_get_HashAlgorithm(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HashAlgorithm)
		this->_Inst_HashAlgorithm = new TElAlgorithmIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_HashAlgorithm->updateHandle(hOutResult);
	return this->_Inst_HashAlgorithm;
}

SB_INLINE void TElPublicationInformationAttribute::set_HashAlgorithm(TElAlgorithmIdentifier &Value)
{
	SBCheckError(TElPublicationInformationAttribute_set_HashAlgorithm(_Handle, Value.getHandle()));
}

SB_INLINE void TElPublicationInformationAttribute::set_HashAlgorithm(TElAlgorithmIdentifier *Value)
{
	SBCheckError(TElPublicationInformationAttribute_set_HashAlgorithm(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELPKIPUBLICATIONINFO
TElPKIPublicationInfo* TElPublicationInformationAttribute::get_PubInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPublicationInformationAttribute_get_PubInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PubInfo)
		this->_Inst_PubInfo = new TElPKIPublicationInfo(hOutResult, ohFalse);
	else
		this->_Inst_PubInfo->updateHandle(hOutResult);
	return this->_Inst_PubInfo;
}
#endif /* SB_USE_CLASS_TELPKIPUBLICATIONINFO */

void TElPublicationInformationAttribute::initInstances()
{
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	this->_Inst_HashAlgorithm = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELPKIPUBLICATIONINFO
	this->_Inst_PubInfo = NULL;
#endif /* SB_USE_CLASS_TELPKIPUBLICATIONINFO */
}

TElPublicationInformationAttribute::TElPublicationInformationAttribute(TElPublicationInformationAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
	initInstances();
}

TElPublicationInformationAttribute::TElPublicationInformationAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPublicationInformationAttribute_Create(&_Handle));
}

TElPublicationInformationAttribute::~TElPublicationInformationAttribute()
{
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	delete this->_Inst_HashAlgorithm;
	this->_Inst_HashAlgorithm = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELPKIPUBLICATIONINFO
	delete this->_Inst_PubInfo;
	this->_Inst_PubInfo = NULL;
#endif /* SB_USE_CLASS_TELPKIPUBLICATIONINFO */
}
#endif /* SB_USE_CLASS_TELPUBLICATIONINFORMATIONATTRIBUTE */

#ifdef SB_USE_CLASS_TELCONTROLPROCESSEDATTRIBUTE

#ifdef SB_USE_CLASS_TELBODYPARTREFERENCE
SB_INLINE int32_t TElControlProcessedAttribute::AddBodyPartReference(TElBodyPartReference &Ref)
{
	int32_t OutResult;
	SBCheckError(TElControlProcessedAttribute_AddBodyPartReference(_Handle, Ref.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElControlProcessedAttribute::AddBodyPartReference(TElBodyPartReference *Ref)
{
	int32_t OutResult;
	SBCheckError(TElControlProcessedAttribute_AddBodyPartReference(_Handle, (Ref != NULL) ? Ref->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELBODYPARTREFERENCE */

SB_INLINE void TElControlProcessedAttribute::RemoveBodyPartReferece(int32_t Idx)
{
	SBCheckError(TElControlProcessedAttribute_RemoveBodyPartReferece(_Handle, Idx));
}

bool TElControlProcessedAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElControlProcessedAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElControlProcessedAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElControlProcessedAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElControlProcessedAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElControlProcessedAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElControlProcessedAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElControlProcessedAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1351095041, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELBODYPARTREFERENCE
TElBodyPartReference* TElControlProcessedAttribute::get_BodyList(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElControlProcessedAttribute_get_BodyList(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_BodyList)
		this->_Inst_BodyList = new TElBodyPartReference(hOutResult, ohFalse);
	else
		this->_Inst_BodyList->updateHandle(hOutResult);
	return this->_Inst_BodyList;
}
#endif /* SB_USE_CLASS_TELBODYPARTREFERENCE */

SB_INLINE int32_t TElControlProcessedAttribute::get_BodyListCount()
{
	int32_t OutResult;
	SBCheckError(TElControlProcessedAttribute_get_BodyListCount(_Handle, &OutResult));
	return OutResult;
}

void TElControlProcessedAttribute::initInstances()
{
#ifdef SB_USE_CLASS_TELBODYPARTREFERENCE
	this->_Inst_BodyList = NULL;
#endif /* SB_USE_CLASS_TELBODYPARTREFERENCE */
}

TElControlProcessedAttribute::TElControlProcessedAttribute(TElControlProcessedAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
	initInstances();
}

TElControlProcessedAttribute::TElControlProcessedAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElControlProcessedAttribute_Create(&_Handle));
}

TElControlProcessedAttribute::~TElControlProcessedAttribute()
{
#ifdef SB_USE_CLASS_TELBODYPARTREFERENCE
	delete this->_Inst_BodyList;
	this->_Inst_BodyList = NULL;
#endif /* SB_USE_CLASS_TELBODYPARTREFERENCE */
}
#endif /* SB_USE_CLASS_TELCONTROLPROCESSEDATTRIBUTE */

#ifdef SB_USE_CLASS_TELOPTIONALVALIDITY

SB_INLINE int64_t TElOptionalValidity::get_NotBefore()
{
	int64_t OutResult;
	SBCheckError(TElOptionalValidity_get_NotBefore(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOptionalValidity::set_NotBefore(int64_t Value)
{
	SBCheckError(TElOptionalValidity_set_NotBefore(_Handle, Value));
}

SB_INLINE int64_t TElOptionalValidity::get_NotAfter()
{
	int64_t OutResult;
	SBCheckError(TElOptionalValidity_get_NotAfter(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOptionalValidity::set_NotAfter(int64_t Value)
{
	SBCheckError(TElOptionalValidity_set_NotAfter(_Handle, Value));
}

TElOptionalValidity::TElOptionalValidity(TElOptionalValidityHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElOptionalValidity::TElOptionalValidity() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOptionalValidity_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOPTIONALVALIDITY */

#ifdef SB_USE_CLASS_TELPUBLICKEYINFO

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
TElAlgorithmIdentifier* TElPublicKeyInfo::get_Algorithm()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPublicKeyInfo_get_Algorithm(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Algorithm)
		this->_Inst_Algorithm = new TElAlgorithmIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_Algorithm->updateHandle(hOutResult);
	return this->_Inst_Algorithm;
}

SB_INLINE void TElPublicKeyInfo::set_Algorithm(TElAlgorithmIdentifier &Value)
{
	SBCheckError(TElPublicKeyInfo_set_Algorithm(_Handle, Value.getHandle()));
}

SB_INLINE void TElPublicKeyInfo::set_Algorithm(TElAlgorithmIdentifier *Value)
{
	SBCheckError(TElPublicKeyInfo_set_Algorithm(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

void TElPublicKeyInfo::get_PublicKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPublicKeyInfo_get_PublicKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-784346482, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPublicKeyInfo::set_PublicKey(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPublicKeyInfo_set_PublicKey(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPublicKeyInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	this->_Inst_Algorithm = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
}

TElPublicKeyInfo::TElPublicKeyInfo(TElPublicKeyInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPublicKeyInfo::TElPublicKeyInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPublicKeyInfo_Create(&_Handle));
}

TElPublicKeyInfo::~TElPublicKeyInfo()
{
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	delete this->_Inst_Algorithm;
	this->_Inst_Algorithm = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
}
#endif /* SB_USE_CLASS_TELPUBLICKEYINFO */

#ifdef SB_USE_CLASS_TELCERTTEMPLATE

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
SB_INLINE void TElCertTemplate::SaveToTag(TElASN1ConstrainedTag &Tag)
{
	SBCheckError(TElCertTemplate_SaveToTag(_Handle, Tag.getHandle()));
}

SB_INLINE void TElCertTemplate::SaveToTag(TElASN1ConstrainedTag *Tag)
{
	SBCheckError(TElCertTemplate_SaveToTag(_Handle, (Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
SB_INLINE void TElCertTemplate::LoadFromTag(TElASN1ConstrainedTag &Tag)
{
	SBCheckError(TElCertTemplate_LoadFromTag(_Handle, Tag.getHandle()));
}

SB_INLINE void TElCertTemplate::LoadFromTag(TElASN1ConstrainedTag *Tag)
{
	SBCheckError(TElCertTemplate_LoadFromTag(_Handle, (Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElCertTemplate::get_Subject()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertTemplate_get_Subject(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Subject)
		this->_Inst_Subject = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_Subject->updateHandle(hOutResult);
	return this->_Inst_Subject;
}

SB_INLINE void TElCertTemplate::set_Subject(TElRelativeDistinguishedName &Value)
{
	SBCheckError(TElCertTemplate_set_Subject(_Handle, Value.getHandle()));
}

SB_INLINE void TElCertTemplate::set_Subject(TElRelativeDistinguishedName *Value)
{
	SBCheckError(TElCertTemplate_set_Subject(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELPUBLICKEYINFO
TElPublicKeyInfo* TElCertTemplate::get_SubjectPublicKeyInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertTemplate_get_SubjectPublicKeyInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SubjectPublicKeyInfo)
		this->_Inst_SubjectPublicKeyInfo = new TElPublicKeyInfo(hOutResult, ohFalse);
	else
		this->_Inst_SubjectPublicKeyInfo->updateHandle(hOutResult);
	return this->_Inst_SubjectPublicKeyInfo;
}
#endif /* SB_USE_CLASS_TELPUBLICKEYINFO */

#ifdef SB_USE_CLASS_TELOPTIONALVALIDITY
TElOptionalValidity* TElCertTemplate::get_Validity()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertTemplate_get_Validity(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Validity)
		this->_Inst_Validity = new TElOptionalValidity(hOutResult, ohFalse);
	else
		this->_Inst_Validity->updateHandle(hOutResult);
	return this->_Inst_Validity;
}

SB_INLINE void TElCertTemplate::set_Validity(TElOptionalValidity &Value)
{
	SBCheckError(TElCertTemplate_set_Validity(_Handle, Value.getHandle()));
}

SB_INLINE void TElCertTemplate::set_Validity(TElOptionalValidity *Value)
{
	SBCheckError(TElCertTemplate_set_Validity(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOPTIONALVALIDITY */

#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
TElCertificateExtensions* TElCertTemplate::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertTemplate_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElCertificateExtensions(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

void TElCertTemplate::initInstances()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_Subject = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELPUBLICKEYINFO
	this->_Inst_SubjectPublicKeyInfo = NULL;
#endif /* SB_USE_CLASS_TELPUBLICKEYINFO */
#ifdef SB_USE_CLASS_TELOPTIONALVALIDITY
	this->_Inst_Validity = NULL;
#endif /* SB_USE_CLASS_TELOPTIONALVALIDITY */
#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */
}

TElCertTemplate::TElCertTemplate(TElCertTemplateHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCertTemplate::TElCertTemplate() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCertTemplate_Create(&_Handle));
}

TElCertTemplate::~TElCertTemplate()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_Subject;
	this->_Inst_Subject = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELPUBLICKEYINFO
	delete this->_Inst_SubjectPublicKeyInfo;
	this->_Inst_SubjectPublicKeyInfo = NULL;
#endif /* SB_USE_CLASS_TELPUBLICKEYINFO */
#ifdef SB_USE_CLASS_TELOPTIONALVALIDITY
	delete this->_Inst_Validity;
	this->_Inst_Validity = NULL;
#endif /* SB_USE_CLASS_TELOPTIONALVALIDITY */
#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */
}
#endif /* SB_USE_CLASS_TELCERTTEMPLATE */

#ifdef SB_USE_CLASS_TELMODCERTIFICATIONREQUESTATTRIBUTE

bool TElModCertificationRequestAttribute::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElModCertificationRequestAttribute_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElModCertificationRequestAttribute::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElModCertificationRequestAttribute_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE TClassHandle TElModCertificationRequestAttribute::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElModCertificationRequestAttribute_ClassType(&OutResult));
	return OutResult;
}

void TElModCertificationRequestAttribute::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElModCertificationRequestAttribute_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1851056398, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELBODYPARTPATH
TElBodyPartPath* TElModCertificationRequestAttribute::get_PKIDataReference()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElModCertificationRequestAttribute_get_PKIDataReference(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PKIDataReference)
		this->_Inst_PKIDataReference = new TElBodyPartPath(hOutResult, ohFalse);
	else
		this->_Inst_PKIDataReference->updateHandle(hOutResult);
	return this->_Inst_PKIDataReference;
}
#endif /* SB_USE_CLASS_TELBODYPARTPATH */

void TElModCertificationRequestAttribute::get_CertReferences(std::vector<int32_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size() * 4;
	uint32_t _err = TElModCertificationRequestAttribute_get_CertReferences(_Handle, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult / 4);
		SBCheckError(SBGetLastReturnBuffer(-442599370, 1, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult / 4);
}

SB_INLINE void TElModCertificationRequestAttribute::set_CertReferences(const std::vector<int32_t> &Value)
{
	SBCheckError(TElModCertificationRequestAttribute_set_CertReferences(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElModCertificationRequestAttribute::get_Replace()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElModCertificationRequestAttribute_get_Replace(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElModCertificationRequestAttribute::set_Replace(bool Value)
{
	SBCheckError(TElModCertificationRequestAttribute_set_Replace(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCERTTEMPLATE
TElCertTemplate* TElModCertificationRequestAttribute::get_CertTemplate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElModCertificationRequestAttribute_get_CertTemplate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertTemplate)
		this->_Inst_CertTemplate = new TElCertTemplate(hOutResult, ohFalse);
	else
		this->_Inst_CertTemplate->updateHandle(hOutResult);
	return this->_Inst_CertTemplate;
}
#endif /* SB_USE_CLASS_TELCERTTEMPLATE */

void TElModCertificationRequestAttribute::initInstances()
{
#ifdef SB_USE_CLASS_TELBODYPARTPATH
	this->_Inst_PKIDataReference = NULL;
#endif /* SB_USE_CLASS_TELBODYPARTPATH */
#ifdef SB_USE_CLASS_TELCERTTEMPLATE
	this->_Inst_CertTemplate = NULL;
#endif /* SB_USE_CLASS_TELCERTTEMPLATE */
}

TElModCertificationRequestAttribute::TElModCertificationRequestAttribute(TElModCertificationRequestAttributeHandle handle, TElOwnHandle ownHandle) : TElControlAttribute(handle, ownHandle)
{
	initInstances();
}

TElModCertificationRequestAttribute::TElModCertificationRequestAttribute() : TElControlAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElModCertificationRequestAttribute_Create(&_Handle));
}

TElModCertificationRequestAttribute::~TElModCertificationRequestAttribute()
{
#ifdef SB_USE_CLASS_TELBODYPARTPATH
	delete this->_Inst_PKIDataReference;
	this->_Inst_PKIDataReference = NULL;
#endif /* SB_USE_CLASS_TELBODYPARTPATH */
#ifdef SB_USE_CLASS_TELCERTTEMPLATE
	delete this->_Inst_CertTemplate;
	this->_Inst_CertTemplate = NULL;
#endif /* SB_USE_CLASS_TELCERTTEMPLATE */
}
#endif /* SB_USE_CLASS_TELMODCERTIFICATIONREQUESTATTRIBUTE */

#ifdef SB_USE_CLASS_TELFULLPKIREQUEST

#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST
SB_INLINE TElFullPKIRequestHandle TElFullPKIRequest::CreateSimpleRequest(TElCertificateRequest &Request)
{
	TElFullPKIRequestHandle OutResult;
	SBCheckError(TElFullPKIRequest_CreateSimpleRequest(Request.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElFullPKIRequestHandle TElFullPKIRequest::CreateSimpleRequest(TElCertificateRequest *Request)
{
	TElFullPKIRequestHandle OutResult;
	SBCheckError(TElFullPKIRequest_CreateSimpleRequest((Request != NULL) ? Request->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */

#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST
SB_INLINE TElFullPKIRequestHandle TElFullPKIRequest::CreateSimpleRequest_Inst(TElCertificateRequest &Request)
{
	TElFullPKIRequestHandle OutResult;
	SBCheckError(TElFullPKIRequest_CreateSimpleRequest_1(_Handle, Request.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElFullPKIRequestHandle TElFullPKIRequest::CreateSimpleRequest_Inst(TElCertificateRequest *Request)
{
	TElFullPKIRequestHandle OutResult;
	SBCheckError(TElFullPKIRequest_CreateSimpleRequest_1(_Handle, (Request != NULL) ? Request->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */

#ifdef SB_USE_CLASSES_TELCERTIFICATEREQUEST_AND_TELCUSTOMCERTSTORAGE
SB_INLINE TElFullPKIRequestHandle TElFullPKIRequest::CreateSimpleRequest(TElCertificateRequest &Request, TElCustomCertStorage &EncryptionCertificates)
{
	TElFullPKIRequestHandle OutResult;
	SBCheckError(TElFullPKIRequest_CreateSimpleRequest_2(Request.getHandle(), EncryptionCertificates.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElFullPKIRequestHandle TElFullPKIRequest::CreateSimpleRequest(TElCertificateRequest *Request, TElCustomCertStorage *EncryptionCertificates)
{
	TElFullPKIRequestHandle OutResult;
	SBCheckError(TElFullPKIRequest_CreateSimpleRequest_2((Request != NULL) ? Request->getHandle() : SB_NULL_HANDLE, (EncryptionCertificates != NULL) ? EncryptionCertificates->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCERTIFICATEREQUEST_AND_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASSES_TELCERTIFICATEREQUEST_AND_TELCUSTOMCERTSTORAGE
SB_INLINE TElFullPKIRequestHandle TElFullPKIRequest::CreateSimpleRequest_Inst(TElCertificateRequest &Request, TElCustomCertStorage &EncryptionCertificates)
{
	TElFullPKIRequestHandle OutResult;
	SBCheckError(TElFullPKIRequest_CreateSimpleRequest_3(_Handle, Request.getHandle(), EncryptionCertificates.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElFullPKIRequestHandle TElFullPKIRequest::CreateSimpleRequest_Inst(TElCertificateRequest *Request, TElCustomCertStorage *EncryptionCertificates)
{
	TElFullPKIRequestHandle OutResult;
	SBCheckError(TElFullPKIRequest_CreateSimpleRequest_3(_Handle, (Request != NULL) ? Request->getHandle() : SB_NULL_HANDLE, (EncryptionCertificates != NULL) ? EncryptionCertificates->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCERTIFICATEREQUEST_AND_TELCUSTOMCERTSTORAGE */

bool TElFullPKIRequest::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFullPKIRequest_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElFullPKIRequest::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElFullPKIRequest_LoadFromBuffer(_Handle, Buffer, Size));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElFullPKIRequest::LoadFromStream(TStream &Strm)
{
	SBCheckError(TElFullPKIRequest_LoadFromStream(_Handle, Strm.getHandle()));
}

SB_INLINE void TElFullPKIRequest::LoadFromStream(TStream *Strm)
{
	SBCheckError(TElFullPKIRequest_LoadFromStream(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElFullPKIRequest::SaveToStream(TStream &Strm)
{
	SBCheckError(TElFullPKIRequest_SaveToStream(_Handle, Strm.getHandle()));
}

SB_INLINE void TElFullPKIRequest::SaveToStream(TStream *Strm)
{
	SBCheckError(TElFullPKIRequest_SaveToStream(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElFullPKIRequest::SaveToFile(const std::string &FileName)
{
	SBCheckError(TElFullPKIRequest_SaveToFile(_Handle, FileName.data(), (int32_t)FileName.length()));
}

SB_INLINE void TElFullPKIRequest::LoadFromFile(const std::string &FileName)
{
	SBCheckError(TElFullPKIRequest_LoadFromFile(_Handle, FileName.data(), (int32_t)FileName.length()));
}

#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST
SB_INLINE int32_t TElFullPKIRequest::AddRequest(TElCertificateRequest &Req)
{
	int32_t OutResult;
	SBCheckError(TElFullPKIRequest_AddRequest(_Handle, Req.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElFullPKIRequest::AddRequest(TElCertificateRequest *Req)
{
	int32_t OutResult;
	SBCheckError(TElFullPKIRequest_AddRequest(_Handle, (Req != NULL) ? Req->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */

SB_INLINE void TElFullPKIRequest::RemoveRequest(int32_t Index)
{
	SBCheckError(TElFullPKIRequest_RemoveRequest(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELCONTROLATTRIBUTE
SB_INLINE int32_t TElFullPKIRequest::AddControlAttribute(TElControlAttribute &Attr)
{
	int32_t OutResult;
	SBCheckError(TElFullPKIRequest_AddControlAttribute(_Handle, Attr.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElFullPKIRequest::AddControlAttribute(TElControlAttribute *Attr)
{
	int32_t OutResult;
	SBCheckError(TElFullPKIRequest_AddControlAttribute(_Handle, (Attr != NULL) ? Attr->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCONTROLATTRIBUTE */

SB_INLINE void TElFullPKIRequest::RemoveControlAttribute(int32_t Index)
{
	SBCheckError(TElFullPKIRequest_RemoveControlAttribute(_Handle, Index));
}

SB_INLINE int32_t TElFullPKIRequest::AddCMS(const std::vector<uint8_t> &CMS, const std::vector<uint8_t> &ContentType)
{
	int32_t OutResult;
	SBCheckError(TElFullPKIRequest_AddCMS(_Handle, SB_STD_VECTOR_FRONT_ADR(CMS), (int32_t)CMS.size(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElFullPKIRequest::AddCMS(TElFullPKIRequest &CMS)
{
	int32_t OutResult;
	SBCheckError(TElFullPKIRequest_AddCMS_1(_Handle, CMS.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElFullPKIRequest::AddCMS(TElFullPKIRequest *CMS)
{
	int32_t OutResult;
	SBCheckError(TElFullPKIRequest_AddCMS_1(_Handle, (CMS != NULL) ? CMS->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

SB_INLINE void TElFullPKIRequest::RemoveCMS(int32_t Index)
{
	SBCheckError(TElFullPKIRequest_RemoveCMS(_Handle, Index));
}

SB_INLINE int32_t TElFullPKIRequest::AddOtherMsg(const std::vector<uint8_t> &Msg, const std::vector<uint8_t> &ContentType)
{
	int32_t OutResult;
	SBCheckError(TElFullPKIRequest_AddOtherMsg(_Handle, SB_STD_VECTOR_FRONT_ADR(Msg), (int32_t)Msg.size(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), &OutResult));
	return OutResult;
}

SB_INLINE void TElFullPKIRequest::RemoveOtherMsg(int32_t Index)
{
	SBCheckError(TElFullPKIRequest_RemoveOtherMsg(_Handle, Index));
}

SB_INLINE int32_t TElFullPKIRequest::GetBodyPartID(TObject &Part)
{
	int32_t OutResult;
	SBCheckError(TElFullPKIRequest_GetBodyPartID(_Handle, Part.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElFullPKIRequest::GetBodyPartID(TObject *Part)
{
	int32_t OutResult;
	SBCheckError(TElFullPKIRequest_GetBodyPartID(_Handle, (Part != NULL) ? Part->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST
TElCertificateRequest* TElFullPKIRequest::get_Requests(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFullPKIRequest_get_Requests(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Requests)
		this->_Inst_Requests = new TElCertificateRequest(hOutResult, ohFalse);
	else
		this->_Inst_Requests->updateHandle(hOutResult);
	return this->_Inst_Requests;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */

#ifdef SB_USE_CLASS_TELCONTROLATTRIBUTE
TElControlAttribute* TElFullPKIRequest::get_ControlAttributes(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFullPKIRequest_get_ControlAttributes(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ControlAttributes)
		this->_Inst_ControlAttributes = new TElControlAttribute(hOutResult, ohFalse);
	else
		this->_Inst_ControlAttributes->updateHandle(hOutResult);
	return this->_Inst_ControlAttributes;
}
#endif /* SB_USE_CLASS_TELCONTROLATTRIBUTE */

#ifdef SB_USE_CLASS_TELCONTENTINFO
TElContentInfo* TElFullPKIRequest::get_CMSs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFullPKIRequest_get_CMSs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CMSs)
		this->_Inst_CMSs = new TElContentInfo(hOutResult, ohFalse);
	else
		this->_Inst_CMSs->updateHandle(hOutResult);
	return this->_Inst_CMSs;
}
#endif /* SB_USE_CLASS_TELCONTENTINFO */

#ifdef SB_USE_CLASS_TELOTHERMSG
TElOtherMsg* TElFullPKIRequest::get_OtherMessages(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFullPKIRequest_get_OtherMessages(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OtherMessages)
		this->_Inst_OtherMessages = new TElOtherMsg(hOutResult, ohFalse);
	else
		this->_Inst_OtherMessages->updateHandle(hOutResult);
	return this->_Inst_OtherMessages;
}
#endif /* SB_USE_CLASS_TELOTHERMSG */

SB_INLINE int32_t TElFullPKIRequest::get_RequestCount()
{
	int32_t OutResult;
	SBCheckError(TElFullPKIRequest_get_RequestCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElFullPKIRequest::get_ControlAttributeCount()
{
	int32_t OutResult;
	SBCheckError(TElFullPKIRequest_get_ControlAttributeCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElFullPKIRequest::get_CMSCount()
{
	int32_t OutResult;
	SBCheckError(TElFullPKIRequest_get_CMSCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElFullPKIRequest::get_OtherMessageCount()
{
	int32_t OutResult;
	SBCheckError(TElFullPKIRequest_get_OtherMessageCount(_Handle, &OutResult));
	return OutResult;
}

TSBFullPKIFormat TElFullPKIRequest::get_StoreFormat()
{
	TSBFullPKIFormatRaw OutResultRaw = 0;
	SBCheckError(TElFullPKIRequest_get_StoreFormat(_Handle, &OutResultRaw));
	return (TSBFullPKIFormat)OutResultRaw;
}

SB_INLINE void TElFullPKIRequest::set_StoreFormat(TSBFullPKIFormat Value)
{
	SBCheckError(TElFullPKIRequest_set_StoreFormat(_Handle, (TSBFullPKIFormatRaw)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElFullPKIRequest::get_SigningCertificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFullPKIRequest_get_SigningCertificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigningCertificates)
		this->_Inst_SigningCertificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_SigningCertificates->updateHandle(hOutResult);
	return this->_Inst_SigningCertificates;
}

SB_INLINE void TElFullPKIRequest::set_SigningCertificates(TElCustomCertStorage &Value)
{
	SBCheckError(TElFullPKIRequest_set_SigningCertificates(_Handle, Value.getHandle()));
}

SB_INLINE void TElFullPKIRequest::set_SigningCertificates(TElCustomCertStorage *Value)
{
	SBCheckError(TElFullPKIRequest_set_SigningCertificates(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElFullPKIRequest::get_EncryptionCertificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFullPKIRequest_get_EncryptionCertificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptionCertificates)
		this->_Inst_EncryptionCertificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_EncryptionCertificates->updateHandle(hOutResult);
	return this->_Inst_EncryptionCertificates;
}

SB_INLINE void TElFullPKIRequest::set_EncryptionCertificates(TElCustomCertStorage &Value)
{
	SBCheckError(TElFullPKIRequest_set_EncryptionCertificates(_Handle, Value.getHandle()));
}

SB_INLINE void TElFullPKIRequest::set_EncryptionCertificates(TElCustomCertStorage *Value)
{
	SBCheckError(TElFullPKIRequest_set_EncryptionCertificates(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

SB_INLINE int32_t TElFullPKIRequest::get_MainRequestIndex()
{
	int32_t OutResult;
	SBCheckError(TElFullPKIRequest_get_MainRequestIndex(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElFullPKIRequest::set_MainRequestIndex(int32_t Value)
{
	SBCheckError(TElFullPKIRequest_set_MainRequestIndex(_Handle, Value));
}

SB_INLINE void TElFullPKIRequest::get_OnSignature(TSBFullPKISignatureEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFullPKIRequest_get_OnSignature(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFullPKIRequest::set_OnSignature(TSBFullPKISignatureEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFullPKIRequest_set_OnSignature(_Handle, pMethodValue, pDataValue));
}

void TElFullPKIRequest::initInstances()
{
#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST
	this->_Inst_Requests = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */
#ifdef SB_USE_CLASS_TELCONTROLATTRIBUTE
	this->_Inst_ControlAttributes = NULL;
#endif /* SB_USE_CLASS_TELCONTROLATTRIBUTE */
#ifdef SB_USE_CLASS_TELCONTENTINFO
	this->_Inst_CMSs = NULL;
#endif /* SB_USE_CLASS_TELCONTENTINFO */
#ifdef SB_USE_CLASS_TELOTHERMSG
	this->_Inst_OtherMessages = NULL;
#endif /* SB_USE_CLASS_TELOTHERMSG */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_SigningCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_EncryptionCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElFullPKIRequest::TElFullPKIRequest(TElFullPKIRequestHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElFullPKIRequest::TElFullPKIRequest() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElFullPKIRequest_Create(&_Handle));
}

TElFullPKIRequest::~TElFullPKIRequest()
{
#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST
	delete this->_Inst_Requests;
	this->_Inst_Requests = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */
#ifdef SB_USE_CLASS_TELCONTROLATTRIBUTE
	delete this->_Inst_ControlAttributes;
	this->_Inst_ControlAttributes = NULL;
#endif /* SB_USE_CLASS_TELCONTROLATTRIBUTE */
#ifdef SB_USE_CLASS_TELCONTENTINFO
	delete this->_Inst_CMSs;
	this->_Inst_CMSs = NULL;
#endif /* SB_USE_CLASS_TELCONTENTINFO */
#ifdef SB_USE_CLASS_TELOTHERMSG
	delete this->_Inst_OtherMessages;
	this->_Inst_OtherMessages = NULL;
#endif /* SB_USE_CLASS_TELOTHERMSG */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_SigningCertificates;
	this->_Inst_SigningCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_EncryptionCertificates;
	this->_Inst_EncryptionCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELFULLPKIREQUEST */

#ifdef SB_USE_CLASS_TELFULLPKIRESPONSE

bool TElFullPKIResponse::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFullPKIResponse_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElFullPKIResponse::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElFullPKIResponse_LoadFromBuffer(_Handle, Buffer, Size));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElFullPKIResponse::LoadFromStream(TStream &Strm)
{
	SBCheckError(TElFullPKIResponse_LoadFromStream(_Handle, Strm.getHandle()));
}

SB_INLINE void TElFullPKIResponse::LoadFromStream(TStream *Strm)
{
	SBCheckError(TElFullPKIResponse_LoadFromStream(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElFullPKIResponse::SaveToStream(TStream &Strm)
{
	SBCheckError(TElFullPKIResponse_SaveToStream(_Handle, Strm.getHandle()));
}

SB_INLINE void TElFullPKIResponse::SaveToStream(TStream *Strm)
{
	SBCheckError(TElFullPKIResponse_SaveToStream(_Handle, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElFullPKIResponse::SaveToFile(const std::string &FileName)
{
	SBCheckError(TElFullPKIResponse_SaveToFile(_Handle, FileName.data(), (int32_t)FileName.length()));
}

SB_INLINE void TElFullPKIResponse::LoadFromFile(const std::string &FileName)
{
	SBCheckError(TElFullPKIResponse_LoadFromFile(_Handle, FileName.data(), (int32_t)FileName.length()));
}

#ifdef SB_USE_CLASS_TELCONTROLATTRIBUTE
SB_INLINE int32_t TElFullPKIResponse::AddControlAttribute(TElControlAttribute &Attr)
{
	int32_t OutResult;
	SBCheckError(TElFullPKIResponse_AddControlAttribute(_Handle, Attr.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElFullPKIResponse::AddControlAttribute(TElControlAttribute *Attr)
{
	int32_t OutResult;
	SBCheckError(TElFullPKIResponse_AddControlAttribute(_Handle, (Attr != NULL) ? Attr->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCONTROLATTRIBUTE */

SB_INLINE void TElFullPKIResponse::RemoveControlAttribute(int32_t Index)
{
	SBCheckError(TElFullPKIResponse_RemoveControlAttribute(_Handle, Index));
}

SB_INLINE int32_t TElFullPKIResponse::AddCMS(const std::vector<uint8_t> &CMS, const std::vector<uint8_t> &ContentType)
{
	int32_t OutResult;
	SBCheckError(TElFullPKIResponse_AddCMS(_Handle, SB_STD_VECTOR_FRONT_ADR(CMS), (int32_t)CMS.size(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), &OutResult));
	return OutResult;
}

SB_INLINE void TElFullPKIResponse::RemoveCMS(int32_t Index)
{
	SBCheckError(TElFullPKIResponse_RemoveCMS(_Handle, Index));
}

SB_INLINE int32_t TElFullPKIResponse::AddOtherMsg(const std::vector<uint8_t> &Msg, const std::vector<uint8_t> &ContentType)
{
	int32_t OutResult;
	SBCheckError(TElFullPKIResponse_AddOtherMsg(_Handle, SB_STD_VECTOR_FRONT_ADR(Msg), (int32_t)Msg.size(), SB_STD_VECTOR_FRONT_ADR(ContentType), (int32_t)ContentType.size(), &OutResult));
	return OutResult;
}

SB_INLINE void TElFullPKIResponse::RemoveOtherMsg(int32_t Index)
{
	SBCheckError(TElFullPKIResponse_RemoveOtherMsg(_Handle, Index));
}

SB_INLINE int32_t TElFullPKIResponse::GetBodyPartID(TObject &Part)
{
	int32_t OutResult;
	SBCheckError(TElFullPKIResponse_GetBodyPartID(_Handle, Part.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElFullPKIResponse::GetBodyPartID(TObject *Part)
{
	int32_t OutResult;
	SBCheckError(TElFullPKIResponse_GetBodyPartID(_Handle, (Part != NULL) ? Part->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCONTROLATTRIBUTE
TElControlAttribute* TElFullPKIResponse::get_ControlAttributes(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFullPKIResponse_get_ControlAttributes(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ControlAttributes)
		this->_Inst_ControlAttributes = new TElControlAttribute(hOutResult, ohFalse);
	else
		this->_Inst_ControlAttributes->updateHandle(hOutResult);
	return this->_Inst_ControlAttributes;
}
#endif /* SB_USE_CLASS_TELCONTROLATTRIBUTE */

#ifdef SB_USE_CLASS_TELCONTENTINFO
TElContentInfo* TElFullPKIResponse::get_CMSs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFullPKIResponse_get_CMSs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CMSs)
		this->_Inst_CMSs = new TElContentInfo(hOutResult, ohFalse);
	else
		this->_Inst_CMSs->updateHandle(hOutResult);
	return this->_Inst_CMSs;
}
#endif /* SB_USE_CLASS_TELCONTENTINFO */

#ifdef SB_USE_CLASS_TELOTHERMSG
TElOtherMsg* TElFullPKIResponse::get_OtherMessages(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFullPKIResponse_get_OtherMessages(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OtherMessages)
		this->_Inst_OtherMessages = new TElOtherMsg(hOutResult, ohFalse);
	else
		this->_Inst_OtherMessages->updateHandle(hOutResult);
	return this->_Inst_OtherMessages;
}
#endif /* SB_USE_CLASS_TELOTHERMSG */

SB_INLINE int32_t TElFullPKIResponse::get_ControlAttributeCount()
{
	int32_t OutResult;
	SBCheckError(TElFullPKIResponse_get_ControlAttributeCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElFullPKIResponse::get_CMSCount()
{
	int32_t OutResult;
	SBCheckError(TElFullPKIResponse_get_CMSCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElFullPKIResponse::get_OtherMessageCount()
{
	int32_t OutResult;
	SBCheckError(TElFullPKIResponse_get_OtherMessageCount(_Handle, &OutResult));
	return OutResult;
}

TSBFullPKIFormat TElFullPKIResponse::get_StoreFormat()
{
	TSBFullPKIFormatRaw OutResultRaw = 0;
	SBCheckError(TElFullPKIResponse_get_StoreFormat(_Handle, &OutResultRaw));
	return (TSBFullPKIFormat)OutResultRaw;
}

SB_INLINE void TElFullPKIResponse::set_StoreFormat(TSBFullPKIFormat Value)
{
	SBCheckError(TElFullPKIResponse_set_StoreFormat(_Handle, (TSBFullPKIFormatRaw)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElFullPKIResponse::get_SigningCertificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFullPKIResponse_get_SigningCertificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigningCertificates)
		this->_Inst_SigningCertificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_SigningCertificates->updateHandle(hOutResult);
	return this->_Inst_SigningCertificates;
}

SB_INLINE void TElFullPKIResponse::set_SigningCertificates(TElCustomCertStorage &Value)
{
	SBCheckError(TElFullPKIResponse_set_SigningCertificates(_Handle, Value.getHandle()));
}

SB_INLINE void TElFullPKIResponse::set_SigningCertificates(TElCustomCertStorage *Value)
{
	SBCheckError(TElFullPKIResponse_set_SigningCertificates(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElFullPKIResponse::get_EncryptionCertificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFullPKIResponse_get_EncryptionCertificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptionCertificates)
		this->_Inst_EncryptionCertificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_EncryptionCertificates->updateHandle(hOutResult);
	return this->_Inst_EncryptionCertificates;
}

SB_INLINE void TElFullPKIResponse::set_EncryptionCertificates(TElCustomCertStorage &Value)
{
	SBCheckError(TElFullPKIResponse_set_EncryptionCertificates(_Handle, Value.getHandle()));
}

SB_INLINE void TElFullPKIResponse::set_EncryptionCertificates(TElCustomCertStorage *Value)
{
	SBCheckError(TElFullPKIResponse_set_EncryptionCertificates(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElFullPKIResponse::get_IssuedCertificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFullPKIResponse_get_IssuedCertificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IssuedCertificates)
		this->_Inst_IssuedCertificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_IssuedCertificates->updateHandle(hOutResult);
	return this->_Inst_IssuedCertificates;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
TElMemoryCRLStorage* TElFullPKIResponse::get_IssuerCRLs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFullPKIResponse_get_IssuerCRLs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IssuerCRLs)
		this->_Inst_IssuerCRLs = new TElMemoryCRLStorage(hOutResult, ohFalse);
	else
		this->_Inst_IssuerCRLs->updateHandle(hOutResult);
	return this->_Inst_IssuerCRLs;
}
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

SB_INLINE void TElFullPKIResponse::get_OnSignature(TSBFullPKISignatureEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFullPKIResponse_get_OnSignature(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFullPKIResponse::set_OnSignature(TSBFullPKISignatureEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFullPKIResponse_set_OnSignature(_Handle, pMethodValue, pDataValue));
}

void TElFullPKIResponse::initInstances()
{
#ifdef SB_USE_CLASS_TELCONTROLATTRIBUTE
	this->_Inst_ControlAttributes = NULL;
#endif /* SB_USE_CLASS_TELCONTROLATTRIBUTE */
#ifdef SB_USE_CLASS_TELCONTENTINFO
	this->_Inst_CMSs = NULL;
#endif /* SB_USE_CLASS_TELCONTENTINFO */
#ifdef SB_USE_CLASS_TELOTHERMSG
	this->_Inst_OtherMessages = NULL;
#endif /* SB_USE_CLASS_TELOTHERMSG */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_SigningCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_EncryptionCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_IssuedCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
	this->_Inst_IssuerCRLs = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
}

TElFullPKIResponse::TElFullPKIResponse(TElFullPKIResponseHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElFullPKIResponse::TElFullPKIResponse() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElFullPKIResponse_Create(&_Handle));
}

TElFullPKIResponse::~TElFullPKIResponse()
{
#ifdef SB_USE_CLASS_TELCONTROLATTRIBUTE
	delete this->_Inst_ControlAttributes;
	this->_Inst_ControlAttributes = NULL;
#endif /* SB_USE_CLASS_TELCONTROLATTRIBUTE */
#ifdef SB_USE_CLASS_TELCONTENTINFO
	delete this->_Inst_CMSs;
	this->_Inst_CMSs = NULL;
#endif /* SB_USE_CLASS_TELCONTENTINFO */
#ifdef SB_USE_CLASS_TELOTHERMSG
	delete this->_Inst_OtherMessages;
	this->_Inst_OtherMessages = NULL;
#endif /* SB_USE_CLASS_TELOTHERMSG */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_SigningCertificates;
	this->_Inst_SigningCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_EncryptionCertificates;
	this->_Inst_EncryptionCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_IssuedCertificates;
	this->_Inst_IssuedCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
	delete this->_Inst_IssuerCRLs;
	this->_Inst_IssuerCRLs = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
}
#endif /* SB_USE_CLASS_TELFULLPKIRESPONSE */

};	/* namespace SecureBlackbox */

