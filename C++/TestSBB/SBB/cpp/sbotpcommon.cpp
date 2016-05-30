#include "sbotpcommon.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELOTPCLASS

TElOTPClass::TElOTPClass(TElOTPClassHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElOTPClass::TElOTPClass(TComponent &Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOTPClass_Create(Owner.getHandle(), &_Handle));
}

TElOTPClass::TElOTPClass(TComponent *Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOTPClass_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELOTPCLASS */

#ifdef SB_USE_CLASS_TELHOTPPASSWORDGENERATOR

void TElHOTPPasswordGenerator::GeneratePassword(const std::vector<uint8_t> &HashedData, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHOTPPasswordGenerator_GeneratePassword(_Handle, SB_STD_VECTOR_FRONT_ADR(HashedData), (int32_t)HashedData.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-618202767, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElHOTPPasswordGenerator::GeneratePassword(int32_t Counter, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHOTPPasswordGenerator_GeneratePassword_1(_Handle, Counter, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(252697245, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElHOTPPasswordGenerator::get_KeySecret(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElHOTPPasswordGenerator_get_KeySecret(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1042395144, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHOTPPasswordGenerator::set_KeySecret(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElHOTPPasswordGenerator_set_KeySecret(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElHOTPPasswordGenerator::get_PasswordLen()
{
	int32_t OutResult;
	SBCheckError(TElHOTPPasswordGenerator_get_PasswordLen(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHOTPPasswordGenerator::set_PasswordLen(int32_t Value)
{
	SBCheckError(TElHOTPPasswordGenerator_set_PasswordLen(_Handle, Value));
}

TElHOTPPasswordGenerator::TElHOTPPasswordGenerator(TElHOTPPasswordGeneratorHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElHOTPPasswordGenerator::TElHOTPPasswordGenerator(const std::vector<uint8_t> &KeySecret, int32_t PasswordLength) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElHOTPPasswordGenerator_Create(SB_STD_VECTOR_FRONT_ADR(KeySecret), (int32_t)KeySecret.size(), PasswordLength, &_Handle));
}

#endif /* SB_USE_CLASS_TELHOTPPASSWORDGENERATOR */

#ifdef SB_USE_CLASS_TELTOTPPASSWORDGENERATOR

void TElTOTPPasswordGenerator::GeneratePassword(int64_t Time, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElTOTPPasswordGenerator_GeneratePassword(_Handle, Time, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1775725731, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElTOTPPasswordGenerator::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElTOTPPasswordGenerator_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTOTPPasswordGenerator::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElTOTPPasswordGenerator_set_HashAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElTOTPPasswordGenerator::get_TimeInterval()
{
	int32_t OutResult;
	SBCheckError(TElTOTPPasswordGenerator_get_TimeInterval(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTOTPPasswordGenerator::set_TimeInterval(int32_t Value)
{
	SBCheckError(TElTOTPPasswordGenerator_set_TimeInterval(_Handle, Value));
}

TElTOTPPasswordGenerator::TElTOTPPasswordGenerator(TElTOTPPasswordGeneratorHandle handle, TElOwnHandle ownHandle) : TElHOTPPasswordGenerator(handle, ownHandle)
{
}

TElTOTPPasswordGenerator::TElTOTPPasswordGenerator(const std::vector<uint8_t> &KeySecret, int32_t PasswordLength) : TElHOTPPasswordGenerator(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTOTPPasswordGenerator_Create(SB_STD_VECTOR_FRONT_ADR(KeySecret), (int32_t)KeySecret.size(), PasswordLength, &_Handle));
}

#endif /* SB_USE_CLASS_TELTOTPPASSWORDGENERATOR */

};	/* namespace SecureBlackbox */

