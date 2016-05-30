#include "sbgost341094.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELGOSTSIGNERBASE

SB_INLINE void TElGOSTSignerBase::AssignSecretKey(const std::string &HexStr)
{
	SBCheckError(TElGOSTSignerBase_AssignSecretKey(_Handle, HexStr.data(), (int32_t)HexStr.length()));
}

SB_INLINE void TElGOSTSignerBase::AssignPublicKey(const std::string &HexStr)
{
	SBCheckError(TElGOSTSignerBase_AssignPublicKey(_Handle, HexStr.data(), (int32_t)HexStr.length()));
}

void TElGOSTSignerBase::Sign(const std::vector<uint8_t> &Digest, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOSTSignerBase_Sign(_Handle, SB_STD_VECTOR_FRONT_ADR(Digest), (int32_t)Digest.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-232074057, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElGOSTSignerBase::Verify(const std::vector<uint8_t> &Digest, const std::vector<uint8_t> &Sign)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGOSTSignerBase_Verify(_Handle, SB_STD_VECTOR_FRONT_ADR(Digest), (int32_t)Digest.size(), SB_STD_VECTOR_FRONT_ADR(Sign), (int32_t)Sign.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGOSTSignerBase::Generate_Keys()
{
	SBCheckError(TElGOSTSignerBase_Generate_Keys(_Handle));
}

SB_INLINE PLInt TElGOSTSignerBase::get_SecretKey()
{
	PLInt OutResult;
	SBCheckError(TElGOSTSignerBase_get_SecretKey(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGOSTSignerBase::set_SecretKey(PLInt Value)
{
	SBCheckError(TElGOSTSignerBase_set_SecretKey(_Handle, Value));
}

SB_INLINE PLInt TElGOSTSignerBase::get_PublicKey()
{
	PLInt OutResult;
	SBCheckError(TElGOSTSignerBase_get_PublicKey(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGOSTSignerBase::set_PublicKey(PLInt Value)
{
	SBCheckError(TElGOSTSignerBase_set_PublicKey(_Handle, Value));
}

TElGOSTSignerBase::TElGOSTSignerBase(TElGOSTSignerBaseHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElGOSTSignerBase::TElGOSTSignerBase() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOSTSignerBase_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGOSTSIGNERBASE */

#ifdef SB_USE_CLASS_TELGOSTSIGNER

SB_INLINE void TElGOSTSigner::AssignP(const std::string &HexStr)
{
	SBCheckError(TElGOSTSigner_AssignP(_Handle, HexStr.data(), (int32_t)HexStr.length()));
}

SB_INLINE void TElGOSTSigner::AssignQ(const std::string &HexStr)
{
	SBCheckError(TElGOSTSigner_AssignQ(_Handle, HexStr.data(), (int32_t)HexStr.length()));
}

SB_INLINE void TElGOSTSigner::AssignA(const std::string &HexStr)
{
	SBCheckError(TElGOSTSigner_AssignA(_Handle, HexStr.data(), (int32_t)HexStr.length()));
}

bool TElGOSTSigner::Check_Params(int32_t Bits, const PLInt P, const PLInt Q, const PLInt A, int64_t x0, int64_t c)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGOSTSigner_Check_Params(Bits, P, Q, A, x0, c, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGOSTSigner::Check_Params_Inst(int32_t Bits, const PLInt P, const PLInt Q, const PLInt A, int64_t x0, int64_t c)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGOSTSigner_Check_Params_1(_Handle, Bits, P, Q, A, x0, c, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGOSTSigner::Generate_PQA(int32_t Bits, int32_t TypeProc, int64_t &x0, int64_t &c)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGOSTSigner_Generate_PQA(_Handle, Bits, TypeProc, &x0, &c, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGOSTSigner::Generate_PQA(int32_t Bits, int32_t TypeProc, int64_t &x0, int64_t &c, PLInt &P, PLInt &Q, PLInt &A)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGOSTSigner_Generate_PQA_1(Bits, TypeProc, &x0, &c, &P, &Q, &A, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGOSTSigner::Generate_PQA_Inst(int32_t Bits, int32_t TypeProc, int64_t &x0, int64_t &c, PLInt &P, PLInt &Q, PLInt &A)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGOSTSigner_Generate_PQA_2(_Handle, Bits, TypeProc, &x0, &c, &P, &Q, &A, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGOSTSigner::Generate_All(int32_t Bits, int32_t TypeProc, int64_t &x0, int64_t &c)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGOSTSigner_Generate_All(_Handle, Bits, TypeProc, &x0, &c, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElGOSTSigner::Generate_Keys()
{
	SBCheckError(TElGOSTSigner_Generate_Keys(_Handle));
}

SB_INLINE void TElGOSTSigner::Generate_Keys(const PLInt P, const PLInt Q, const PLInt A, PLInt &SecretKey, PLInt &PublicKey)
{
	SBCheckError(TElGOSTSigner_Generate_Keys_1(P, Q, A, &SecretKey, &PublicKey));
}

SB_INLINE void TElGOSTSigner::Generate_Keys_Inst(const PLInt P, const PLInt Q, const PLInt A, PLInt &SecretKey, PLInt &PublicKey)
{
	SBCheckError(TElGOSTSigner_Generate_Keys_2(_Handle, P, Q, A, &SecretKey, &PublicKey));
}

void TElGOSTSigner::Sign(const std::vector<uint8_t> &Digest, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOSTSigner_Sign(_Handle, SB_STD_VECTOR_FRONT_ADR(Digest), (int32_t)Digest.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1791132830, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGOSTSigner::Sign(const std::vector<uint8_t> &Digest, const std::string &P, const std::string &Q, const std::string &A, const std::string &Key, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOSTSigner_Sign_1(SB_STD_VECTOR_FRONT_ADR(Digest), (int32_t)Digest.size(), P.data(), (int32_t)P.length(), Q.data(), (int32_t)Q.length(), A.data(), (int32_t)A.length(), Key.data(), (int32_t)Key.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-874401495, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGOSTSigner::Sign_Inst(const std::vector<uint8_t> &Digest, const std::string &P, const std::string &Q, const std::string &A, const std::string &Key, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOSTSigner_Sign_2(_Handle, SB_STD_VECTOR_FRONT_ADR(Digest), (int32_t)Digest.size(), P.data(), (int32_t)P.length(), Q.data(), (int32_t)Q.length(), A.data(), (int32_t)A.length(), Key.data(), (int32_t)Key.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-874401495, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGOSTSigner::Sign(const std::vector<uint8_t> &Digest, const PLInt P, const PLInt Q, const PLInt A, const PLInt Key, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOSTSigner_Sign_3(SB_STD_VECTOR_FRONT_ADR(Digest), (int32_t)Digest.size(), P, Q, A, Key, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1620962134, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElGOSTSigner::Sign_Inst(const std::vector<uint8_t> &Digest, const PLInt P, const PLInt Q, const PLInt A, const PLInt Key, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGOSTSigner_Sign_4(_Handle, SB_STD_VECTOR_FRONT_ADR(Digest), (int32_t)Digest.size(), P, Q, A, Key, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1620962134, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElGOSTSigner::Verify(const std::vector<uint8_t> &Digest, const std::vector<uint8_t> &Sign)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGOSTSigner_Verify(_Handle, SB_STD_VECTOR_FRONT_ADR(Digest), (int32_t)Digest.size(), SB_STD_VECTOR_FRONT_ADR(Sign), (int32_t)Sign.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGOSTSigner::Verify(const std::vector<uint8_t> &Digest, const std::vector<uint8_t> &Sign, const PLInt P, const PLInt Q, const PLInt A, const PLInt Key)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGOSTSigner_Verify_1(SB_STD_VECTOR_FRONT_ADR(Digest), (int32_t)Digest.size(), SB_STD_VECTOR_FRONT_ADR(Sign), (int32_t)Sign.size(), P, Q, A, Key, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGOSTSigner::Verify_Inst(const std::vector<uint8_t> &Digest, const std::vector<uint8_t> &Sign, const PLInt P, const PLInt Q, const PLInt A, const PLInt Key)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGOSTSigner_Verify_2(_Handle, SB_STD_VECTOR_FRONT_ADR(Digest), (int32_t)Digest.size(), SB_STD_VECTOR_FRONT_ADR(Sign), (int32_t)Sign.size(), P, Q, A, Key, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE PLInt TElGOSTSigner::get_P()
{
	PLInt OutResult;
	SBCheckError(TElGOSTSigner_get_P(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGOSTSigner::set_P(PLInt Value)
{
	SBCheckError(TElGOSTSigner_set_P(_Handle, Value));
}

SB_INLINE PLInt TElGOSTSigner::get_Q()
{
	PLInt OutResult;
	SBCheckError(TElGOSTSigner_get_Q(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGOSTSigner::set_Q(PLInt Value)
{
	SBCheckError(TElGOSTSigner_set_Q(_Handle, Value));
}

SB_INLINE PLInt TElGOSTSigner::get_A()
{
	PLInt OutResult;
	SBCheckError(TElGOSTSigner_get_A(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGOSTSigner::set_A(PLInt Value)
{
	SBCheckError(TElGOSTSigner_set_A(_Handle, Value));
}

TElGOSTSigner::TElGOSTSigner(TElGOSTSignerHandle handle, TElOwnHandle ownHandle) : TElGOSTSignerBase(handle, ownHandle)
{
}

TElGOSTSigner::TElGOSTSigner() : TElGOSTSignerBase(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOSTSigner_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGOSTSIGNER */

};	/* namespace SecureBlackbox */

