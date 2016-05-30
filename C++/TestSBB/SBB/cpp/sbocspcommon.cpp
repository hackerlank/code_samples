#include "sbocspcommon.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELOCSPCLASS

#ifdef SB_USE_CLASS_TELGENERALNAME
TElGeneralName* TElOCSPClass::get_RequestorName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOCSPClass_get_RequestorName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RequestorName)
		this->_Inst_RequestorName = new TElGeneralName(hOutResult, ohFalse);
	else
		this->_Inst_RequestorName->updateHandle(hOutResult);
	return this->_Inst_RequestorName;
}
#endif /* SB_USE_CLASS_TELGENERALNAME */

bool TElOCSPClass::get_IncludeCertificates()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOCSPClass_get_IncludeCertificates(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOCSPClass::set_IncludeCertificates(bool Value)
{
	SBCheckError(TElOCSPClass_set_IncludeCertificates(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElOCSPClass::get_SigningCertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOCSPClass_get_SigningCertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigningCertStorage)
		this->_Inst_SigningCertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_SigningCertStorage->updateHandle(hOutResult);
	return this->_Inst_SigningCertStorage;
}

SB_INLINE void TElOCSPClass::set_SigningCertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElOCSPClass_set_SigningCertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElOCSPClass::set_SigningCertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElOCSPClass_set_SigningCertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

SB_INLINE void TElOCSPClass::get_OnCertificateNeeded(TSBOCSPCertificateNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOCSPClass_get_OnCertificateNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOCSPClass::set_OnCertificateNeeded(TSBOCSPCertificateNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOCSPClass_set_OnCertificateNeeded(_Handle, pMethodValue, pDataValue));
}

void TElOCSPClass::initInstances()
{
#ifdef SB_USE_CLASS_TELGENERALNAME
	this->_Inst_RequestorName = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_SigningCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElOCSPClass::TElOCSPClass(TElOCSPClassHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElOCSPClass::TElOCSPClass(TComponent &Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOCSPClass_Create(Owner.getHandle(), &_Handle));
}

TElOCSPClass::TElOCSPClass(TComponent *Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOCSPClass_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElOCSPClass::~TElOCSPClass()
{
#ifdef SB_USE_CLASS_TELGENERALNAME
	delete this->_Inst_RequestorName;
	this->_Inst_RequestorName = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_SigningCertStorage;
	this->_Inst_SigningCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELOCSPCLASS */

#ifdef SB_USE_GLOBAL_PROCS_OCSPCOMMON

SB_INLINE int32_t ReasonFlagToEnum(TSBCRLReasonFlag Value)
{
	int32_t OutResult;
	SBCheckError(SBOCSPCommon_ReasonFlagToEnum((TSBCRLReasonFlagRaw)Value, &OutResult));
	return OutResult;
}

TSBCRLReasonFlag EnumToReasonFlag(int32_t Value)
{
	TSBCRLReasonFlagRaw OutResultRaw = 0;
	SBCheckError(SBOCSPCommon_EnumToReasonFlag(Value, &OutResultRaw));
	return (TSBCRLReasonFlag)OutResultRaw;
}

void ReadAsnInteger(const std::vector<uint8_t> &IntBuf, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBOCSPCommon_ReadAsnInteger(SB_STD_VECTOR_FRONT_ADR(IntBuf), (int32_t)IntBuf.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(773542451, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#endif /* SB_USE_GLOBAL_PROCS_OCSPCOMMON */

};	/* namespace SecureBlackbox */

