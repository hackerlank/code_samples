#include "sbalgorithmidentifier.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER

SB_INLINE void TElAlgorithmIdentifier::Assign(TElAlgorithmIdentifier &Source)
{
	SBCheckError(TElAlgorithmIdentifier_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElAlgorithmIdentifier::Assign(TElAlgorithmIdentifier *Source)
{
	SBCheckError(TElAlgorithmIdentifier_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElAlgorithmIdentifierHandle TElAlgorithmIdentifier::Clone()
{
	TElAlgorithmIdentifierHandle OutResult;
	SBCheckError(TElAlgorithmIdentifier_Clone(_Handle, &OutResult));
	return OutResult;
}

bool TElAlgorithmIdentifier::Equals(TElAlgorithmIdentifier &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAlgorithmIdentifier_Equals(_Handle, Algorithm.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElAlgorithmIdentifier::Equals(TElAlgorithmIdentifier *Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAlgorithmIdentifier_Equals(_Handle, (Algorithm != NULL) ? Algorithm->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TElAlgorithmIdentifierHandle TElAlgorithmIdentifier::CreateFromBuffer(void * Buffer, int32_t Size)
{
	TElAlgorithmIdentifierHandle OutResult;
	SBCheckError(TElAlgorithmIdentifier_CreateFromBuffer(Buffer, Size, &OutResult));
	return OutResult;
}

SB_INLINE TElAlgorithmIdentifierHandle TElAlgorithmIdentifier::CreateFromBuffer_Inst(void * Buffer, int32_t Size)
{
	TElAlgorithmIdentifierHandle OutResult;
	SBCheckError(TElAlgorithmIdentifier_CreateFromBuffer_1(_Handle, Buffer, Size, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
SB_INLINE TElAlgorithmIdentifierHandle TElAlgorithmIdentifier::CreateFromTag(TElASN1ConstrainedTag &Tag)
{
	TElAlgorithmIdentifierHandle OutResult;
	SBCheckError(TElAlgorithmIdentifier_CreateFromTag(Tag.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAlgorithmIdentifierHandle TElAlgorithmIdentifier::CreateFromTag(TElASN1ConstrainedTag *Tag)
{
	TElAlgorithmIdentifierHandle OutResult;
	SBCheckError(TElAlgorithmIdentifier_CreateFromTag((Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
SB_INLINE TElAlgorithmIdentifierHandle TElAlgorithmIdentifier::CreateFromTag_Inst(TElASN1ConstrainedTag &Tag)
{
	TElAlgorithmIdentifierHandle OutResult;
	SBCheckError(TElAlgorithmIdentifier_CreateFromTag_1(_Handle, Tag.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElAlgorithmIdentifierHandle TElAlgorithmIdentifier::CreateFromTag_Inst(TElASN1ConstrainedTag *Tag)
{
	TElAlgorithmIdentifierHandle OutResult;
	SBCheckError(TElAlgorithmIdentifier_CreateFromTag_1(_Handle, (Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

SB_INLINE TElAlgorithmIdentifierHandle TElAlgorithmIdentifier::CreateByAlgorithm(int32_t Algorithm)
{
	TElAlgorithmIdentifierHandle OutResult;
	SBCheckError(TElAlgorithmIdentifier_CreateByAlgorithm(Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE TElAlgorithmIdentifierHandle TElAlgorithmIdentifier::CreateByAlgorithm_Inst(int32_t Algorithm)
{
	TElAlgorithmIdentifierHandle OutResult;
	SBCheckError(TElAlgorithmIdentifier_CreateByAlgorithm_1(_Handle, Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE TElAlgorithmIdentifierHandle TElAlgorithmIdentifier::CreateByAlgorithmOID(const std::vector<uint8_t> &OID)
{
	TElAlgorithmIdentifierHandle OutResult;
	SBCheckError(TElAlgorithmIdentifier_CreateByAlgorithmOID(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResult));
	return OutResult;
}

SB_INLINE TElAlgorithmIdentifierHandle TElAlgorithmIdentifier::CreateByAlgorithmOID_Inst(const std::vector<uint8_t> &OID)
{
	TElAlgorithmIdentifierHandle OutResult;
	SBCheckError(TElAlgorithmIdentifier_CreateByAlgorithmOID_1(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResult));
	return OutResult;
}

bool TElAlgorithmIdentifier::IsAlgorithmSupported(int32_t Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAlgorithmIdentifier_IsAlgorithmSupported(_Handle, Algorithm, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAlgorithmIdentifier::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElAlgorithmIdentifier_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE void TElAlgorithmIdentifier::SaveToBuffer(void * Buffer, int32_t &Size)
{
	SBCheckError(TElAlgorithmIdentifier_SaveToBuffer(_Handle, Buffer, &Size));
}

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
SB_INLINE void TElAlgorithmIdentifier::LoadFromTag(TElASN1ConstrainedTag &Tag)
{
	SBCheckError(TElAlgorithmIdentifier_LoadFromTag(_Handle, Tag.getHandle()));
}

SB_INLINE void TElAlgorithmIdentifier::LoadFromTag(TElASN1ConstrainedTag *Tag)
{
	SBCheckError(TElAlgorithmIdentifier_LoadFromTag(_Handle, (Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
SB_INLINE void TElAlgorithmIdentifier::SaveToTag(TElASN1ConstrainedTag &Tag)
{
	SBCheckError(TElAlgorithmIdentifier_SaveToTag(_Handle, Tag.getHandle()));
}

SB_INLINE void TElAlgorithmIdentifier::SaveToTag(TElASN1ConstrainedTag *Tag)
{
	SBCheckError(TElAlgorithmIdentifier_SaveToTag(_Handle, (Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

void TElAlgorithmIdentifier::WriteParameters(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElAlgorithmIdentifier_WriteParameters(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-329172269, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElAlgorithmIdentifier::get_AlgorithmOID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElAlgorithmIdentifier_get_AlgorithmOID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1017562010, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAlgorithmIdentifier::set_AlgorithmOID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElAlgorithmIdentifier_set_AlgorithmOID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElAlgorithmIdentifier::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElAlgorithmIdentifier_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAlgorithmIdentifier::set_Algorithm(int32_t Value)
{
	SBCheckError(TElAlgorithmIdentifier_set_Algorithm(_Handle, Value));
}

SB_INLINE int32_t TElAlgorithmIdentifier::get_SignatureHashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElAlgorithmIdentifier_get_SignatureHashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

bool TElAlgorithmIdentifier::get_IsSignatureAlgorithm()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAlgorithmIdentifier_get_IsSignatureAlgorithm(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElAlgorithmIdentifier::get_IsPublicKeyAlgorithm()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAlgorithmIdentifier_get_IsPublicKeyAlgorithm(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElAlgorithmIdentifier::get_IsEncryptionAlgorithm()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAlgorithmIdentifier_get_IsEncryptionAlgorithm(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElAlgorithmIdentifier::get_IsHashAlgorithm()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAlgorithmIdentifier_get_IsHashAlgorithm(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElAlgorithmIdentifier::TElAlgorithmIdentifier(TElAlgorithmIdentifierHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElAlgorithmIdentifier::TElAlgorithmIdentifier() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElAlgorithmIdentifier_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELRSAALGORITHMIDENTIFIER

SB_INLINE void TElRSAAlgorithmIdentifier::Assign(TElAlgorithmIdentifier &Source)
{
	SBCheckError(TElRSAAlgorithmIdentifier_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElRSAAlgorithmIdentifier::Assign(TElAlgorithmIdentifier *Source)
{
	SBCheckError(TElRSAAlgorithmIdentifier_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElRSAAlgorithmIdentifier::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElRSAAlgorithmIdentifier_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRSAAlgorithmIdentifier::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElRSAAlgorithmIdentifier_set_HashAlgorithm(_Handle, Value));
}

TElRSAAlgorithmIdentifier::TElRSAAlgorithmIdentifier(TElRSAAlgorithmIdentifierHandle handle, TElOwnHandle ownHandle) : TElAlgorithmIdentifier(handle, ownHandle)
{
}

TElRSAAlgorithmIdentifier::TElRSAAlgorithmIdentifier() : TElAlgorithmIdentifier(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRSAAlgorithmIdentifier_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELRSAALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELRSAPSSALGORITHMIDENTIFIER

SB_INLINE void TElRSAPSSAlgorithmIdentifier::Assign(TElAlgorithmIdentifier &Source)
{
	SBCheckError(TElRSAPSSAlgorithmIdentifier_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElRSAPSSAlgorithmIdentifier::Assign(TElAlgorithmIdentifier *Source)
{
	SBCheckError(TElRSAPSSAlgorithmIdentifier_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElRSAPSSAlgorithmIdentifier::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElRSAPSSAlgorithmIdentifier_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRSAPSSAlgorithmIdentifier::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElRSAPSSAlgorithmIdentifier_set_HashAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElRSAPSSAlgorithmIdentifier::get_SaltSize()
{
	int32_t OutResult;
	SBCheckError(TElRSAPSSAlgorithmIdentifier_get_SaltSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRSAPSSAlgorithmIdentifier::set_SaltSize(int32_t Value)
{
	SBCheckError(TElRSAPSSAlgorithmIdentifier_set_SaltSize(_Handle, Value));
}

SB_INLINE int32_t TElRSAPSSAlgorithmIdentifier::get_TrailerField()
{
	int32_t OutResult;
	SBCheckError(TElRSAPSSAlgorithmIdentifier_get_TrailerField(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRSAPSSAlgorithmIdentifier::set_TrailerField(int32_t Value)
{
	SBCheckError(TElRSAPSSAlgorithmIdentifier_set_TrailerField(_Handle, Value));
}

SB_INLINE int32_t TElRSAPSSAlgorithmIdentifier::get_MGF()
{
	int32_t OutResult;
	SBCheckError(TElRSAPSSAlgorithmIdentifier_get_MGF(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRSAPSSAlgorithmIdentifier::set_MGF(int32_t Value)
{
	SBCheckError(TElRSAPSSAlgorithmIdentifier_set_MGF(_Handle, Value));
}

SB_INLINE int32_t TElRSAPSSAlgorithmIdentifier::get_MGFHashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElRSAPSSAlgorithmIdentifier_get_MGFHashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRSAPSSAlgorithmIdentifier::set_MGFHashAlgorithm(int32_t Value)
{
	SBCheckError(TElRSAPSSAlgorithmIdentifier_set_MGFHashAlgorithm(_Handle, Value));
}

TElRSAPSSAlgorithmIdentifier::TElRSAPSSAlgorithmIdentifier(TElRSAPSSAlgorithmIdentifierHandle handle, TElOwnHandle ownHandle) : TElAlgorithmIdentifier(handle, ownHandle)
{
}

TElRSAPSSAlgorithmIdentifier::TElRSAPSSAlgorithmIdentifier() : TElAlgorithmIdentifier(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRSAPSSAlgorithmIdentifier_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELRSAPSSALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELRSAOAEPALGORITHMIDENTIFIER

SB_INLINE void TElRSAOAEPAlgorithmIdentifier::Assign(TElAlgorithmIdentifier &Source)
{
	SBCheckError(TElRSAOAEPAlgorithmIdentifier_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElRSAOAEPAlgorithmIdentifier::Assign(TElAlgorithmIdentifier *Source)
{
	SBCheckError(TElRSAOAEPAlgorithmIdentifier_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElRSAOAEPAlgorithmIdentifier::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElRSAOAEPAlgorithmIdentifier_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRSAOAEPAlgorithmIdentifier::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElRSAOAEPAlgorithmIdentifier_set_HashAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElRSAOAEPAlgorithmIdentifier::get_MGF()
{
	int32_t OutResult;
	SBCheckError(TElRSAOAEPAlgorithmIdentifier_get_MGF(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRSAOAEPAlgorithmIdentifier::set_MGF(int32_t Value)
{
	SBCheckError(TElRSAOAEPAlgorithmIdentifier_set_MGF(_Handle, Value));
}

SB_INLINE int32_t TElRSAOAEPAlgorithmIdentifier::get_MGFHashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElRSAOAEPAlgorithmIdentifier_get_MGFHashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRSAOAEPAlgorithmIdentifier::set_MGFHashAlgorithm(int32_t Value)
{
	SBCheckError(TElRSAOAEPAlgorithmIdentifier_set_MGFHashAlgorithm(_Handle, Value));
}

void TElRSAOAEPAlgorithmIdentifier::get_StrLabel(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElRSAOAEPAlgorithmIdentifier_get_StrLabel(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2097319921, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElRSAOAEPAlgorithmIdentifier::set_StrLabel(const std::string &Value)
{
	SBCheckError(TElRSAOAEPAlgorithmIdentifier_set_StrLabel(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElRSAOAEPAlgorithmIdentifier::get_WriteDefaults()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRSAOAEPAlgorithmIdentifier_get_WriteDefaults(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElRSAOAEPAlgorithmIdentifier::set_WriteDefaults(bool Value)
{
	SBCheckError(TElRSAOAEPAlgorithmIdentifier_set_WriteDefaults(_Handle, (int8_t)Value));
}

TElRSAOAEPAlgorithmIdentifier::TElRSAOAEPAlgorithmIdentifier(TElRSAOAEPAlgorithmIdentifierHandle handle, TElOwnHandle ownHandle) : TElAlgorithmIdentifier(handle, ownHandle)
{
}

TElRSAOAEPAlgorithmIdentifier::TElRSAOAEPAlgorithmIdentifier() : TElAlgorithmIdentifier(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRSAOAEPAlgorithmIdentifier_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELRSAOAEPALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELDSAALGORITHMIDENTIFIER

SB_INLINE void TElDSAAlgorithmIdentifier::Assign(TElAlgorithmIdentifier &Source)
{
	SBCheckError(TElDSAAlgorithmIdentifier_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDSAAlgorithmIdentifier::Assign(TElAlgorithmIdentifier *Source)
{
	SBCheckError(TElDSAAlgorithmIdentifier_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

void TElDSAAlgorithmIdentifier::get_P(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSAAlgorithmIdentifier_get_P(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-139438250, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDSAAlgorithmIdentifier::set_P(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDSAAlgorithmIdentifier_set_P(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElDSAAlgorithmIdentifier::get_Q(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSAAlgorithmIdentifier_get_Q(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2135464000, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDSAAlgorithmIdentifier::set_Q(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDSAAlgorithmIdentifier_set_Q(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElDSAAlgorithmIdentifier::get_G(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSAAlgorithmIdentifier_get_G(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1952699025, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDSAAlgorithmIdentifier::set_G(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDSAAlgorithmIdentifier_set_G(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElDSAAlgorithmIdentifier::TElDSAAlgorithmIdentifier(TElDSAAlgorithmIdentifierHandle handle, TElOwnHandle ownHandle) : TElAlgorithmIdentifier(handle, ownHandle)
{
}

TElDSAAlgorithmIdentifier::TElDSAAlgorithmIdentifier() : TElAlgorithmIdentifier(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDSAAlgorithmIdentifier_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDSAALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELDHALGORITHMIDENTIFIER

SB_INLINE void TElDHAlgorithmIdentifier::Assign(TElAlgorithmIdentifier &Source)
{
	SBCheckError(TElDHAlgorithmIdentifier_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDHAlgorithmIdentifier::Assign(TElAlgorithmIdentifier *Source)
{
	SBCheckError(TElDHAlgorithmIdentifier_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

void TElDHAlgorithmIdentifier::get_P(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDHAlgorithmIdentifier_get_P(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-311385559, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDHAlgorithmIdentifier::set_P(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDHAlgorithmIdentifier_set_P(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElDHAlgorithmIdentifier::get_Q(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDHAlgorithmIdentifier_get_Q(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1703439681, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDHAlgorithmIdentifier::set_Q(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDHAlgorithmIdentifier_set_Q(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElDHAlgorithmIdentifier::get_G(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDHAlgorithmIdentifier_get_G(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1856186350, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDHAlgorithmIdentifier::set_G(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDHAlgorithmIdentifier_set_G(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElDHAlgorithmIdentifier::TElDHAlgorithmIdentifier(TElDHAlgorithmIdentifierHandle handle, TElOwnHandle ownHandle) : TElAlgorithmIdentifier(handle, ownHandle)
{
}

TElDHAlgorithmIdentifier::TElDHAlgorithmIdentifier() : TElAlgorithmIdentifier(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDHAlgorithmIdentifier_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDHALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELECALGORITHMIDENTIFIER

SB_INLINE void TElECAlgorithmIdentifier::Assign(TElAlgorithmIdentifier &Source)
{
	SBCheckError(TElECAlgorithmIdentifier_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElECAlgorithmIdentifier::Assign(TElAlgorithmIdentifier *Source)
{
	SBCheckError(TElECAlgorithmIdentifier_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElECAlgorithmIdentifier::get_Version()
{
	int32_t OutResult;
	SBCheckError(TElECAlgorithmIdentifier_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECAlgorithmIdentifier::set_Version(int32_t Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_Version(_Handle, Value));
}

void TElECAlgorithmIdentifier::get_Curve(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECAlgorithmIdentifier_get_Curve(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-333768924, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECAlgorithmIdentifier::set_Curve(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_Curve(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECAlgorithmIdentifier::get_FieldID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECAlgorithmIdentifier_get_FieldID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-390364506, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECAlgorithmIdentifier::set_FieldID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_FieldID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElECAlgorithmIdentifier::get_FieldType()
{
	int32_t OutResult;
	SBCheckError(TElECAlgorithmIdentifier_get_FieldType(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECAlgorithmIdentifier::set_FieldType(int32_t Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_FieldType(_Handle, Value));
}

void TElECAlgorithmIdentifier::get_Basis(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECAlgorithmIdentifier_get_Basis(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(910962596, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECAlgorithmIdentifier::set_Basis(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_Basis(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElECAlgorithmIdentifier::get_M()
{
	int32_t OutResult;
	SBCheckError(TElECAlgorithmIdentifier_get_M(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECAlgorithmIdentifier::set_M(int32_t Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_M(_Handle, Value));
}

SB_INLINE int32_t TElECAlgorithmIdentifier::get_K1()
{
	int32_t OutResult;
	SBCheckError(TElECAlgorithmIdentifier_get_K1(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECAlgorithmIdentifier::set_K1(int32_t Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_K1(_Handle, Value));
}

SB_INLINE int32_t TElECAlgorithmIdentifier::get_K2()
{
	int32_t OutResult;
	SBCheckError(TElECAlgorithmIdentifier_get_K2(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECAlgorithmIdentifier::set_K2(int32_t Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_K2(_Handle, Value));
}

SB_INLINE int32_t TElECAlgorithmIdentifier::get_K3()
{
	int32_t OutResult;
	SBCheckError(TElECAlgorithmIdentifier_get_K3(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECAlgorithmIdentifier::set_K3(int32_t Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_K3(_Handle, Value));
}

SB_INLINE int32_t TElECAlgorithmIdentifier::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElECAlgorithmIdentifier_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECAlgorithmIdentifier::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_HashAlgorithm(_Handle, Value));
}

bool TElECAlgorithmIdentifier::get_SpecifiedCurve()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECAlgorithmIdentifier_get_SpecifiedCurve(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElECAlgorithmIdentifier::set_SpecifiedCurve(bool Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_SpecifiedCurve(_Handle, (int8_t)Value));
}

bool TElECAlgorithmIdentifier::get_CompressPoints()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECAlgorithmIdentifier_get_CompressPoints(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElECAlgorithmIdentifier::set_CompressPoints(bool Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_CompressPoints(_Handle, (int8_t)Value));
}

bool TElECAlgorithmIdentifier::get_HybridPoints()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECAlgorithmIdentifier_get_HybridPoints(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElECAlgorithmIdentifier::set_HybridPoints(bool Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_HybridPoints(_Handle, (int8_t)Value));
}

bool TElECAlgorithmIdentifier::get_ImplicitCurve()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECAlgorithmIdentifier_get_ImplicitCurve(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElECAlgorithmIdentifier::set_ImplicitCurve(bool Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_ImplicitCurve(_Handle, (int8_t)Value));
}

void TElECAlgorithmIdentifier::get_Seed(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECAlgorithmIdentifier_get_Seed(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1025506411, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECAlgorithmIdentifier::set_Seed(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_Seed(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECAlgorithmIdentifier::get_P(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECAlgorithmIdentifier_get_P(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(612530476, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECAlgorithmIdentifier::set_P(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_P(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECAlgorithmIdentifier::get_N(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECAlgorithmIdentifier_get_N(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-561167281, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECAlgorithmIdentifier::set_N(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_N(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElECAlgorithmIdentifier::get_H()
{
	int32_t OutResult;
	SBCheckError(TElECAlgorithmIdentifier_get_H(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECAlgorithmIdentifier::set_H(int32_t Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_H(_Handle, Value));
}

void TElECAlgorithmIdentifier::get_A(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECAlgorithmIdentifier_get_A(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1311922654, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECAlgorithmIdentifier::set_A(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_A(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECAlgorithmIdentifier::get_B(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECAlgorithmIdentifier_get_B(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-683997084, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECAlgorithmIdentifier::set_B(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_B(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECAlgorithmIdentifier::get_X(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECAlgorithmIdentifier_get_X(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(710537502, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECAlgorithmIdentifier::set_X(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_X(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECAlgorithmIdentifier::get_Y(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECAlgorithmIdentifier_get_Y(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1566491016, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECAlgorithmIdentifier::set_Y(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_Y(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECAlgorithmIdentifier::get_Base(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECAlgorithmIdentifier_get_Base(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1188241138, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECAlgorithmIdentifier::set_Base(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECAlgorithmIdentifier_set_Base(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElECAlgorithmIdentifier::TElECAlgorithmIdentifier(TElECAlgorithmIdentifierHandle handle, TElOwnHandle ownHandle) : TElAlgorithmIdentifier(handle, ownHandle)
{
}

TElECAlgorithmIdentifier::TElECAlgorithmIdentifier() : TElAlgorithmIdentifier(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECAlgorithmIdentifier_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELECALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELECDSAALGORITHMIDENTIFIER

SB_INLINE void TElECDSAAlgorithmIdentifier::Assign(TElAlgorithmIdentifier &Source)
{
	SBCheckError(TElECDSAAlgorithmIdentifier_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElECDSAAlgorithmIdentifier::Assign(TElAlgorithmIdentifier *Source)
{
	SBCheckError(TElECDSAAlgorithmIdentifier_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElECDSAAlgorithmIdentifier::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElECDSAAlgorithmIdentifier_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECDSAAlgorithmIdentifier::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElECDSAAlgorithmIdentifier_set_HashAlgorithm(_Handle, Value));
}

TElECDSAAlgorithmIdentifier::TElECDSAAlgorithmIdentifier(TElECDSAAlgorithmIdentifierHandle handle, TElOwnHandle ownHandle) : TElAlgorithmIdentifier(handle, ownHandle)
{
}

TElECDSAAlgorithmIdentifier::TElECDSAAlgorithmIdentifier() : TElAlgorithmIdentifier(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDSAAlgorithmIdentifier_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELECDSAALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELGOST3411ALGORITHMIDENTIFIER

SB_INLINE void TElGOST3411AlgorithmIdentifier::Assign(TElAlgorithmIdentifier &Source)
{
	SBCheckError(TElGOST3411AlgorithmIdentifier_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElGOST3411AlgorithmIdentifier::Assign(TElAlgorithmIdentifier *Source)
{
	SBCheckError(TElGOST3411AlgorithmIdentifier_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

TElGOST3411AlgorithmIdentifier::TElGOST3411AlgorithmIdentifier(TElGOST3411AlgorithmIdentifierHandle handle, TElOwnHandle ownHandle) : TElAlgorithmIdentifier(handle, ownHandle)
{
}

TElGOST3411AlgorithmIdentifier::TElGOST3411AlgorithmIdentifier() : TElAlgorithmIdentifier(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST3411AlgorithmIdentifier_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGOST3411ALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELGOST3410ALGORITHMIDENTIFIER

SB_INLINE void TElGOST3410AlgorithmIdentifier::Assign(TElAlgorithmIdentifier &Source)
{
	SBCheckError(TElGOST3410AlgorithmIdentifier_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElGOST3410AlgorithmIdentifier::Assign(TElAlgorithmIdentifier *Source)
{
	SBCheckError(TElGOST3410AlgorithmIdentifier_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

void TElGOST3410AlgorithmIdentifier::get_PublicKeyParamSet(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST3410AlgorithmIdentifier_get_PublicKeyParamSet(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1381064254, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGOST3410AlgorithmIdentifier::set_PublicKeyParamSet(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGOST3410AlgorithmIdentifier_set_PublicKeyParamSet(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElGOST3410AlgorithmIdentifier::get_DigestParamSet(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST3410AlgorithmIdentifier_get_DigestParamSet(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1900207370, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGOST3410AlgorithmIdentifier::set_DigestParamSet(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGOST3410AlgorithmIdentifier_set_DigestParamSet(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElGOST3410AlgorithmIdentifier::get_EncryptionParamSet(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOST3410AlgorithmIdentifier_get_EncryptionParamSet(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(169018850, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGOST3410AlgorithmIdentifier::set_EncryptionParamSet(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGOST3410AlgorithmIdentifier_set_EncryptionParamSet(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElGOST3410AlgorithmIdentifier::TElGOST3410AlgorithmIdentifier(TElGOST3410AlgorithmIdentifierHandle handle, TElOwnHandle ownHandle) : TElAlgorithmIdentifier(handle, ownHandle)
{
}

TElGOST3410AlgorithmIdentifier::TElGOST3410AlgorithmIdentifier() : TElAlgorithmIdentifier(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST3410AlgorithmIdentifier_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGOST3410ALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELGOST3411WITHGOST3410ALGORITHMIDENTIFIER

SB_INLINE void TElGOST3411WithGOST3410AlgorithmIdentifier::Assign(TElAlgorithmIdentifier &Source)
{
	SBCheckError(TElGOST3411WithGOST3410AlgorithmIdentifier_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElGOST3411WithGOST3410AlgorithmIdentifier::Assign(TElAlgorithmIdentifier *Source)
{
	SBCheckError(TElGOST3411WithGOST3410AlgorithmIdentifier_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

TElGOST3411WithGOST3410AlgorithmIdentifier::TElGOST3411WithGOST3410AlgorithmIdentifier(TElGOST3411WithGOST3410AlgorithmIdentifierHandle handle, TElOwnHandle ownHandle) : TElAlgorithmIdentifier(handle, ownHandle)
{
}

TElGOST3411WithGOST3410AlgorithmIdentifier::TElGOST3411WithGOST3410AlgorithmIdentifier() : TElAlgorithmIdentifier(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOST3411WithGOST3410AlgorithmIdentifier_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGOST3411WITHGOST3410ALGORITHMIDENTIFIER */

};	/* namespace SecureBlackbox */

