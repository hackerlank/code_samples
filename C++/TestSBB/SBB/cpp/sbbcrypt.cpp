#include "sbbcrypt.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELBCRYPT

void TElBCrypt::GenerateSalt(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBCrypt_GenerateSalt((uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1543422591, 0, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBCrypt::GenerateSalt_Inst(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBCrypt_GenerateSalt_1(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1543422591, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBCrypt::EncryptPassword(const std::string &Password, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBCrypt_EncryptPassword(Password.data(), (int32_t)Password.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(621264648, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBCrypt::EncryptPassword_Inst(const std::string &Password, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBCrypt_EncryptPassword_1(_Handle, Password.data(), (int32_t)Password.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(621264648, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBCrypt::EncryptPassword(const std::string &Password, const std::vector<uint8_t> &Salt, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBCrypt_EncryptPassword_2(Password.data(), (int32_t)Password.length(), SB_STD_VECTOR_FRONT_ADR(Salt), (int32_t)Salt.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(863859830, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBCrypt::EncryptPassword_Inst(const std::string &Password, const std::vector<uint8_t> &Salt, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBCrypt_EncryptPassword_3(_Handle, Password.data(), (int32_t)Password.length(), SB_STD_VECTOR_FRONT_ADR(Salt), (int32_t)Salt.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(863859830, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBCrypt::EncryptPassword(const std::string &Password, const std::vector<uint8_t> &Salt, int32_t Rounds, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBCrypt_EncryptPassword_4(Password.data(), (int32_t)Password.length(), SB_STD_VECTOR_FRONT_ADR(Salt), (int32_t)Salt.size(), Rounds, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(132746051, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBCrypt::EncryptPassword_Inst(const std::string &Password, const std::vector<uint8_t> &Salt, int32_t Rounds, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElBCrypt_EncryptPassword_5(_Handle, Password.data(), (int32_t)Password.length(), SB_STD_VECTOR_FRONT_ADR(Salt), (int32_t)Salt.size(), Rounds, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(132746051, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElBCrypt::CheckPassword(const std::string &Password, const std::string &EncryptedPassword)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBCrypt_CheckPassword(Password.data(), (int32_t)Password.length(), EncryptedPassword.data(), (int32_t)EncryptedPassword.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElBCrypt::CheckPassword_Inst(const std::string &Password, const std::string &EncryptedPassword)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBCrypt_CheckPassword_1(_Handle, Password.data(), (int32_t)Password.length(), EncryptedPassword.data(), (int32_t)EncryptedPassword.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

TElBCrypt::TElBCrypt(TElBCryptHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElBCrypt::TElBCrypt() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBCrypt_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELBCRYPT */

};	/* namespace SecureBlackbox */

