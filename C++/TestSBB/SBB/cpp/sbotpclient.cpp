#include "sbotpclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELOTPCLIENT

void TElOTPClient::get_KeySecret(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOTPClient_get_KeySecret(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-167926331, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOTPClient::set_KeySecret(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOTPClient_set_KeySecret(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElOTPClient::get_PasswordLen()
{
	int32_t OutResult;
	SBCheckError(TElOTPClient_get_PasswordLen(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOTPClient::set_PasswordLen(int32_t Value)
{
	SBCheckError(TElOTPClient_set_PasswordLen(_Handle, Value));
}

TElOTPClient::TElOTPClient(TElOTPClientHandle handle, TElOwnHandle ownHandle) : TElOTPClass(handle, ownHandle)
{
}

TElOTPClient::TElOTPClient(const std::vector<uint8_t> &KeySecret, int32_t PasswordLength) : TElOTPClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOTPClient_Create(SB_STD_VECTOR_FRONT_ADR(KeySecret), (int32_t)KeySecret.size(), PasswordLength, &_Handle));
}

#endif /* SB_USE_CLASS_TELOTPCLIENT */

#ifdef SB_USE_CLASS_TELHOTPCLIENT

void TElHOTPClient::GetPassword(int32_t Counter, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElHOTPClient_GetPassword(_Handle, Counter, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(663750392, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElHOTPClient::TElHOTPClient(TElHOTPClientHandle handle, TElOwnHandle ownHandle) : TElOTPClient(handle, ownHandle)
{
}

TElHOTPClient::TElHOTPClient(const std::vector<uint8_t> &KeySecret, int32_t PasswordLength) : TElOTPClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElHOTPClient_Create(SB_STD_VECTOR_FRONT_ADR(KeySecret), (int32_t)KeySecret.size(), PasswordLength, &_Handle));
}

#endif /* SB_USE_CLASS_TELHOTPCLIENT */

#ifdef SB_USE_CLASS_TELTOTPCLIENT

void TElTOTPClient::GetPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElTOTPClient_GetPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(466775757, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElTOTPClient::GetPassword(int64_t Time, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElTOTPClient_GetPassword_1(_Handle, Time, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-142408417, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElTOTPClient::get_TimeInterval()
{
	int32_t OutResult;
	SBCheckError(TElTOTPClient_get_TimeInterval(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTOTPClient::set_TimeInterval(int32_t Value)
{
	SBCheckError(TElTOTPClient_set_TimeInterval(_Handle, Value));
}

SB_INLINE int32_t TElTOTPClient::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElTOTPClient_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTOTPClient::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElTOTPClient_set_HashAlgorithm(_Handle, Value));
}

TElTOTPClient::TElTOTPClient(TElTOTPClientHandle handle, TElOwnHandle ownHandle) : TElOTPClient(handle, ownHandle)
{
}

TElTOTPClient::TElTOTPClient(const std::vector<uint8_t> &KeySecret, int32_t PasswordLength) : TElOTPClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTOTPClient_Create(SB_STD_VECTOR_FRONT_ADR(KeySecret), (int32_t)KeySecret.size(), PasswordLength, &_Handle));
}

#endif /* SB_USE_CLASS_TELTOTPCLIENT */

};	/* namespace SecureBlackbox */

