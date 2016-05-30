#include "sbtspcommon.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELTSPINFO

SB_INLINE void TElTSPInfo::Assign(TPersistent &Source)
{
	SBCheckError(TElTSPInfo_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElTSPInfo::Assign(TPersistent *Source)
{
	SBCheckError(TElTSPInfo_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElTSPInfo::Reset()
{
	SBCheckError(TElTSPInfo_Reset(_Handle));
}

void TElTSPInfo::get_SerialNumber(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElTSPInfo_get_SerialNumber(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-469869359, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElTSPInfo::set_SerialNumber(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElTSPInfo_set_SerialNumber(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElTSPInfo::get_Nonce(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElTSPInfo_get_Nonce(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(48250253, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElTSPInfo::set_Nonce(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElTSPInfo_set_Nonce(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int64_t TElTSPInfo::get_Time()
{
	int64_t OutResult;
	SBCheckError(TElTSPInfo_get_Time(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTSPInfo::set_Time(int64_t Value)
{
	SBCheckError(TElTSPInfo_set_Time(_Handle, Value));
}

SB_INLINE int32_t TElTSPInfo::get_AccuracySec()
{
	int32_t OutResult;
	SBCheckError(TElTSPInfo_get_AccuracySec(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTSPInfo::set_AccuracySec(int32_t Value)
{
	SBCheckError(TElTSPInfo_set_AccuracySec(_Handle, Value));
}

SB_INLINE int32_t TElTSPInfo::get_AccuracyMilli()
{
	int32_t OutResult;
	SBCheckError(TElTSPInfo_get_AccuracyMilli(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTSPInfo::set_AccuracyMilli(int32_t Value)
{
	SBCheckError(TElTSPInfo_set_AccuracyMilli(_Handle, Value));
}

SB_INLINE int32_t TElTSPInfo::get_AccuracyMicro()
{
	int32_t OutResult;
	SBCheckError(TElTSPInfo_get_AccuracyMicro(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTSPInfo::set_AccuracyMicro(int32_t Value)
{
	SBCheckError(TElTSPInfo_set_AccuracyMicro(_Handle, Value));
}

bool TElTSPInfo::get_AccuracySet()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTSPInfo_get_AccuracySet(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTSPInfo::set_AccuracySet(bool Value)
{
	SBCheckError(TElTSPInfo_set_AccuracySet(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELGENERALNAME
TElGeneralName* TElTSPInfo::get_TSAName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTSPInfo_get_TSAName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TSAName)
		this->_Inst_TSAName = new TElGeneralName(hOutResult, ohFalse);
	else
		this->_Inst_TSAName->updateHandle(hOutResult);
	return this->_Inst_TSAName;
}
#endif /* SB_USE_CLASS_TELGENERALNAME */

bool TElTSPInfo::get_TSANameSet()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTSPInfo_get_TSANameSet(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTSPInfo::set_TSANameSet(bool Value)
{
	SBCheckError(TElTSPInfo_set_TSANameSet(_Handle, (int8_t)Value));
}

void TElTSPInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELGENERALNAME
	this->_Inst_TSAName = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
}

TElTSPInfo::TElTSPInfo(TElTSPInfoHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElTSPInfo::TElTSPInfo() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElTSPInfo_Create(&_Handle));
}

TElTSPInfo::~TElTSPInfo()
{
#ifdef SB_USE_CLASS_TELGENERALNAME
	delete this->_Inst_TSAName;
	this->_Inst_TSAName = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
}
#endif /* SB_USE_CLASS_TELTSPINFO */

#ifdef SB_USE_CLASS_TELTSPCLASS

bool TElTSPClass::ValidateImprint(int32_t Algorithm, const std::vector<uint8_t> &HashedData, const std::vector<uint8_t> &Imprint)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTSPClass_ValidateImprint(_Handle, Algorithm, SB_STD_VECTOR_FRONT_ADR(HashedData), (int32_t)HashedData.size(), SB_STD_VECTOR_FRONT_ADR(Imprint), (int32_t)Imprint.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

TElTSPClass::TElTSPClass(TElTSPClassHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElTSPClass::TElTSPClass(TComponent &Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTSPClass_Create(Owner.getHandle(), &_Handle));
}

TElTSPClass::TElTSPClass(TComponent *Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTSPClass_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELTSPCLASS */

};	/* namespace SecureBlackbox */

