#include "sbpkcs7utils.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES

bool TElPKCS7Attributes::Remove(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7Attributes_Remove(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS7Attributes::Copy(TElPKCS7Attributes &Dest)
{
	SBCheckError(TElPKCS7Attributes_Copy(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPKCS7Attributes::Copy(TElPKCS7Attributes *Dest)
{
	SBCheckError(TElPKCS7Attributes_Copy(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

bool TElPKCS7Attributes::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7Attributes_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS7Attributes::LoadFromBuffer(void * Buffer, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7Attributes_LoadFromBuffer(_Handle, Buffer, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElPKCS7Attributes::FindAttribute(const std::vector<uint8_t> &Name)
{
	int32_t OutResult;
	SBCheckError(TElPKCS7Attributes_FindAttribute(_Handle, SB_STD_VECTOR_FRONT_ADR(Name), (int32_t)Name.size(), &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS7Attributes::SortLexicographically()
{
	SBCheckError(TElPKCS7Attributes_SortLexicographically(_Handle));
}

SB_INLINE void TElPKCS7Attributes::RecalculateRawAttributeSequences()
{
	SBCheckError(TElPKCS7Attributes_RecalculateRawAttributeSequences(_Handle));
}

SB_INLINE void TElPKCS7Attributes::Clear()
{
	SBCheckError(TElPKCS7Attributes_Clear(_Handle));
}

void TElPKCS7Attributes::get_Attributes(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7Attributes_get_Attributes(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1395840250, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7Attributes::set_Attributes(int32_t Index, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7Attributes_set_Attributes(_Handle, Index, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
TElByteArrayList* TElPKCS7Attributes::get_Values(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7Attributes_get_Values(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Values)
		this->_Inst_Values = new TElByteArrayList(hOutResult, ohFalse);
	else
		this->_Inst_Values->updateHandle(hOutResult);
	return this->_Inst_Values;
}
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

void TElPKCS7Attributes::get_RawAttributeSequences(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7Attributes_get_RawAttributeSequences(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(70360388, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7Attributes::set_RawAttributeSequences(int32_t Index, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7Attributes_set_RawAttributeSequences(_Handle, Index, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElPKCS7Attributes::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7Attributes_get_Count(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS7Attributes::set_Count(int32_t Value)
{
	SBCheckError(TElPKCS7Attributes_set_Count(_Handle, Value));
}

void TElPKCS7Attributes::initInstances()
{
#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
	this->_Inst_Values = NULL;
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */
}

TElPKCS7Attributes::TElPKCS7Attributes(TElPKCS7AttributesHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS7Attributes::TElPKCS7Attributes() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS7Attributes_Create(&_Handle));
}

TElPKCS7Attributes::~TElPKCS7Attributes()
{
#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
	delete this->_Inst_Values;
	this->_Inst_Values = NULL;
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */
}
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

#ifdef SB_USE_CLASS_TELPKCS7ISSUER

SB_INLINE void TElPKCS7Issuer::Assign(TElPKCS7Issuer &Source)
{
	SBCheckError(TElPKCS7Issuer_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPKCS7Issuer::Assign(TElPKCS7Issuer *Source)
{
	SBCheckError(TElPKCS7Issuer_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPKCS7Issuer::Reset()
{
	SBCheckError(TElPKCS7Issuer_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElPKCS7Issuer::get_Issuer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7Issuer_get_Issuer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Issuer)
		this->_Inst_Issuer = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_Issuer->updateHandle(hOutResult);
	return this->_Inst_Issuer;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

void TElPKCS7Issuer::get_SerialNumber(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7Issuer_get_SerialNumber(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1258832997, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7Issuer::set_SerialNumber(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7Issuer_set_SerialNumber(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7Issuer::get_SubjectKeyIdentifier(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7Issuer_get_SubjectKeyIdentifier(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1850540398, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7Issuer::set_SubjectKeyIdentifier(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7Issuer_set_SubjectKeyIdentifier(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TSBPKCS7IssuerType TElPKCS7Issuer::get_IssuerType()
{
	TSBPKCS7IssuerTypeRaw OutResultRaw = 0;
	SBCheckError(TElPKCS7Issuer_get_IssuerType(_Handle, &OutResultRaw));
	return (TSBPKCS7IssuerType)OutResultRaw;
}

SB_INLINE void TElPKCS7Issuer::set_IssuerType(TSBPKCS7IssuerType Value)
{
	SBCheckError(TElPKCS7Issuer_set_IssuerType(_Handle, (TSBPKCS7IssuerTypeRaw)Value));
}

void TElPKCS7Issuer::initInstances()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
}

TElPKCS7Issuer::TElPKCS7Issuer(TElPKCS7IssuerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS7Issuer::TElPKCS7Issuer() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS7Issuer_Create(&_Handle));
}

TElPKCS7Issuer::~TElPKCS7Issuer()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_Issuer;
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
}
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

#ifdef SB_USE_GLOBAL_PROCS_PKCS7UTILS

#ifdef SB_USE_CLASSES_TELASN1CONSTRAINEDTAG_AND_TELPKCS7ATTRIBUTES
SB_INLINE void SaveAttributes(TElASN1ConstrainedTag &Tag, TElPKCS7Attributes &Attributes, uint8_t TagID)
{
	SBCheckError(SBPKCS7Utils_SaveAttributes(Tag.getHandle(), Attributes.getHandle(), TagID));
}
SB_INLINE void SaveAttributes(TElASN1ConstrainedTag *Tag, TElPKCS7Attributes *Attributes, uint8_t TagID)
{
	SBCheckError(SBPKCS7Utils_SaveAttributes((Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, TagID));
}
#endif /* SB_USE_CLASSES_TELASN1CONSTRAINEDTAG_AND_TELPKCS7ATTRIBUTES */

#ifdef SB_USE_CLASSES_TELASN1CUSTOMTAG_AND_TELPKCS7ATTRIBUTES
SB_INLINE int32_t ProcessAttributes(TElASN1CustomTag &Tag, TElPKCS7Attributes &Attributes)
{
	int32_t OutResult;
	SBCheckError(SBPKCS7Utils_ProcessAttributes(Tag.getHandle(), Attributes.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE int32_t ProcessAttributes(TElASN1CustomTag *Tag, TElPKCS7Attributes *Attributes)
{
	int32_t OutResult;
	SBCheckError(SBPKCS7Utils_ProcessAttributes((Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, (Attributes != NULL) ? Attributes->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELASN1CUSTOMTAG_AND_TELPKCS7ATTRIBUTES */

#ifdef SB_USE_CLASS_TELASN1CUSTOMTAG
int32_t ProcessAlgorithmIdentifier(TElASN1CustomTag &Tag, std::vector<uint8_t> &Algorithm, std::vector<uint8_t> &Params, bool ImplicitTagging)
{
	int32_t OutResult;
	int32_t szAlgorithm = (int32_t)Algorithm.size();
	int32_t szParams = (int32_t)Params.size();
	uint32_t _err = SBPKCS7Utils_ProcessAlgorithmIdentifier(Tag.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Algorithm), &szAlgorithm, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Params), &szParams, (int8_t)ImplicitTagging, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Algorithm.resize(szAlgorithm);
		SBCheckError(SBGetLastReturnBuffer(1020150581, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Algorithm), &szAlgorithm));
		Params.resize(szParams);
		SBCheckError(SBGetLastReturnBuffer(1020150581, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Params), &szParams));
	}
	else
		SBCheckError(_err);

	Algorithm.resize(szAlgorithm);
	Params.resize(szParams);
	return OutResult;
}
int32_t ProcessAlgorithmIdentifier(TElASN1CustomTag *Tag, std::vector<uint8_t> &Algorithm, std::vector<uint8_t> &Params, bool ImplicitTagging)
{
	int32_t OutResult;
	int32_t szAlgorithm = (int32_t)Algorithm.size();
	int32_t szParams = (int32_t)Params.size();
	uint32_t _err = SBPKCS7Utils_ProcessAlgorithmIdentifier((Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Algorithm), &szAlgorithm, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Params), &szParams, (int8_t)ImplicitTagging, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Algorithm.resize(szAlgorithm);
		SBCheckError(SBGetLastReturnBuffer(1020150581, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Algorithm), &szAlgorithm));
		Params.resize(szParams);
		SBCheckError(SBGetLastReturnBuffer(1020150581, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Params), &szParams));
	}
	else
		SBCheckError(_err);

	Algorithm.resize(szAlgorithm);
	Params.resize(szParams);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELASN1CUSTOMTAG */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
SB_INLINE void SaveAlgorithmIdentifier(TElASN1ConstrainedTag &Tag, const std::vector<uint8_t> &Algorithm, const std::vector<uint8_t> &Params, uint8_t ImplicitTag, bool WriteNullIfParamsAreEmpty)
{
	SBCheckError(SBPKCS7Utils_SaveAlgorithmIdentifier(Tag.getHandle(), SB_STD_VECTOR_FRONT_ADR(Algorithm), (int32_t)Algorithm.size(), SB_STD_VECTOR_FRONT_ADR(Params), (int32_t)Params.size(), ImplicitTag, (int8_t)WriteNullIfParamsAreEmpty));
}
SB_INLINE void SaveAlgorithmIdentifier(TElASN1ConstrainedTag *Tag, const std::vector<uint8_t> &Algorithm, const std::vector<uint8_t> &Params, uint8_t ImplicitTag, bool WriteNullIfParamsAreEmpty)
{
	SBCheckError(SBPKCS7Utils_SaveAlgorithmIdentifier((Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Algorithm), (int32_t)Algorithm.size(), SB_STD_VECTOR_FRONT_ADR(Params), (int32_t)Params.size(), ImplicitTag, (int8_t)WriteNullIfParamsAreEmpty));
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#endif /* SB_USE_GLOBAL_PROCS_PKCS7UTILS */

};	/* namespace SecureBlackbox */

