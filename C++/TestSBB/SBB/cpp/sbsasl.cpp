#include "sbsasl.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSASLCLIENT

void TElSASLClient::ProcessChallenge(const std::vector<uint8_t> &Challenge, std::vector<uint8_t> &Response)
{
	int32_t szResponse = (int32_t)Response.size();
	uint32_t _err = TElSASLClient_ProcessChallenge(_Handle, SB_STD_VECTOR_FRONT_ADR(Challenge), (int32_t)Challenge.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Response), &szResponse);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Response.resize(szResponse);
		SBCheckError(SBGetLastReturnBuffer(1384566645, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Response), &szResponse));
	}
	else
		SBCheckError(_err);

	Response.resize(szResponse);
}

bool TElSASLClient::ValueExists(const std::string &Name)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSASLClient_ValueExists(_Handle, Name.data(), (int32_t)Name.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSASLClient::WrapData(void * InData, int32_t InSize, void * OutData, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSASLClient_WrapData(_Handle, InData, InSize, OutData, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSASLClient::WrapData(const std::vector<uint8_t> &InData, int32_t InStartIndex, int32_t InSize, std::vector<uint8_t> &OutData, int32_t OutStartIndex, int32_t &OutSize)
{
	int32_t szOutData = (int32_t)OutData.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElSASLClient_WrapData_1(_Handle, SB_STD_VECTOR_FRONT_ADR(InData), (int32_t)InData.size(), InStartIndex, InSize, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutData), &szOutData, OutStartIndex, &OutSize, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutData.resize(szOutData);
		SBCheckError(SBGetLastReturnBuffer(431124727, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutData), &szOutData));
	}
	else
		SBCheckError(_err);

	OutData.resize(szOutData);
	return (OutResultRaw != 0);
}

bool TElSASLClient::UnwrapData(void * InData, int32_t InSize, void * OutData, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSASLClient_UnwrapData(_Handle, InData, InSize, OutData, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSASLClient::UnwrapData(const std::vector<uint8_t> &InData, int32_t InStartIndex, int32_t InSize, std::vector<uint8_t> &OutData, int32_t OutStartIndex, int32_t &OutSize)
{
	int32_t szOutData = (int32_t)OutData.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElSASLClient_UnwrapData_1(_Handle, SB_STD_VECTOR_FRONT_ADR(InData), (int32_t)InData.size(), InStartIndex, InSize, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutData), &szOutData, OutStartIndex, &OutSize, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutData.resize(szOutData);
		SBCheckError(SBGetLastReturnBuffer(183852564, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutData), &szOutData));
	}
	else
		SBCheckError(_err);

	OutData.resize(szOutData);
	return (OutResultRaw != 0);
}

bool TElSASLClient::get_Complete()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSASLClient_get_Complete(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElSASLClient::get_MechanismName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSASLClient_get_MechanismName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-167251316, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBSASLSecurityLevel TElSASLClient::get_SecurityLevel()
{
	TSBSASLSecurityLevelRaw OutResultRaw = 0;
	SBCheckError(TElSASLClient_get_SecurityLevel(_Handle, &OutResultRaw));
	return (TSBSASLSecurityLevel)OutResultRaw;
}

void TElSASLClient::get_Value(const std::string &Name, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSASLClient_get_Value(_Handle, Name.data(), (int32_t)Name.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1020384672, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSASLClient::set_Value(const std::string &Name, const std::string &NewValue)
{
	SBCheckError(TElSASLClient_set_Value(_Handle, Name.data(), (int32_t)Name.length(), NewValue.data(), (int32_t)NewValue.length()));
}

SB_INLINE void TElSASLClient::get_OnChallenge(TSBSASLChallengeEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSASLClient_get_OnChallenge(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSASLClient::set_OnChallenge(TSBSASLChallengeEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSASLClient_set_OnChallenge(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSASLClient::get_OnGetValue(TSBSASLGetValueEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSASLClient_get_OnGetValue(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSASLClient::set_OnGetValue(TSBSASLGetValueEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSASLClient_set_OnGetValue(_Handle, pMethodValue, pDataValue));
}

TElSASLClient::TElSASLClient(TElSASLClientHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSASLClient::TElSASLClient() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSASLClient_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSASLCLIENT */

#ifdef SB_USE_CLASS_TELSASLPLAINCLIENT

void TElSASLPlainClient::ProcessChallenge(const std::vector<uint8_t> &Challenge, std::vector<uint8_t> &Response)
{
	int32_t szResponse = (int32_t)Response.size();
	uint32_t _err = TElSASLPlainClient_ProcessChallenge(_Handle, SB_STD_VECTOR_FRONT_ADR(Challenge), (int32_t)Challenge.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Response), &szResponse);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Response.resize(szResponse);
		SBCheckError(SBGetLastReturnBuffer(2119569682, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Response), &szResponse));
	}
	else
		SBCheckError(_err);

	Response.resize(szResponse);
}

void TElSASLPlainClient::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSASLPlainClient_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1388351888, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSASLPlainClient::set_Password(const std::string &Value)
{
	SBCheckError(TElSASLPlainClient_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSASLPlainClient::get_UserName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSASLPlainClient_get_UserName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1064205836, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSASLPlainClient::set_UserName(const std::string &Value)
{
	SBCheckError(TElSASLPlainClient_set_UserName(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSASLPlainClient::TElSASLPlainClient(TElSASLPlainClientHandle handle, TElOwnHandle ownHandle) : TElSASLClient(handle, ownHandle)
{
}

TElSASLPlainClient::TElSASLPlainClient() : TElSASLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSASLPlainClient_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSASLPLAINCLIENT */

#ifdef SB_USE_CLASS_TELSASLLOGINCLIENT

void TElSASLLoginClient::ProcessChallenge(const std::vector<uint8_t> &Challenge, std::vector<uint8_t> &Response)
{
	int32_t szResponse = (int32_t)Response.size();
	uint32_t _err = TElSASLLoginClient_ProcessChallenge(_Handle, SB_STD_VECTOR_FRONT_ADR(Challenge), (int32_t)Challenge.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Response), &szResponse);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Response.resize(szResponse);
		SBCheckError(SBGetLastReturnBuffer(930307472, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Response), &szResponse));
	}
	else
		SBCheckError(_err);

	Response.resize(szResponse);
}

void TElSASLLoginClient::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSASLLoginClient_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1833685007, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSASLLoginClient::set_Password(const std::string &Value)
{
	SBCheckError(TElSASLLoginClient_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSASLLoginClient::get_UserName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSASLLoginClient_get_UserName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-15024019, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSASLLoginClient::set_UserName(const std::string &Value)
{
	SBCheckError(TElSASLLoginClient_set_UserName(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSASLLoginClient::TElSASLLoginClient(TElSASLLoginClientHandle handle, TElOwnHandle ownHandle) : TElSASLClient(handle, ownHandle)
{
}

TElSASLLoginClient::TElSASLLoginClient() : TElSASLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSASLLoginClient_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSASLLOGINCLIENT */

#ifdef SB_USE_CLASS_TELSASLCRAMMD5CLIENT

void TElSASLCRAMMD5Client::ProcessChallenge(const std::vector<uint8_t> &Challenge, std::vector<uint8_t> &Response)
{
	int32_t szResponse = (int32_t)Response.size();
	uint32_t _err = TElSASLCRAMMD5Client_ProcessChallenge(_Handle, SB_STD_VECTOR_FRONT_ADR(Challenge), (int32_t)Challenge.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Response), &szResponse);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Response.resize(szResponse);
		SBCheckError(SBGetLastReturnBuffer(-47758895, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Response), &szResponse));
	}
	else
		SBCheckError(_err);

	Response.resize(szResponse);
}

void TElSASLCRAMMD5Client::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSASLCRAMMD5Client_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1928767470, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSASLCRAMMD5Client::set_Password(const std::string &Value)
{
	SBCheckError(TElSASLCRAMMD5Client_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSASLCRAMMD5Client::get_UserName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSASLCRAMMD5Client_get_UserName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-525879410, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSASLCRAMMD5Client::set_UserName(const std::string &Value)
{
	SBCheckError(TElSASLCRAMMD5Client_set_UserName(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSASLCRAMMD5Client::TElSASLCRAMMD5Client(TElSASLCRAMMD5ClientHandle handle, TElOwnHandle ownHandle) : TElSASLClient(handle, ownHandle)
{
}

TElSASLCRAMMD5Client::TElSASLCRAMMD5Client() : TElSASLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSASLCRAMMD5Client_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSASLCRAMMD5CLIENT */

#ifdef SB_USE_CLASS_TELSASLANONYMOUSCLIENT

void TElSASLAnonymousClient::ProcessChallenge(const std::vector<uint8_t> &Challenge, std::vector<uint8_t> &Response)
{
	int32_t szResponse = (int32_t)Response.size();
	uint32_t _err = TElSASLAnonymousClient_ProcessChallenge(_Handle, SB_STD_VECTOR_FRONT_ADR(Challenge), (int32_t)Challenge.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Response), &szResponse);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Response.resize(szResponse);
		SBCheckError(SBGetLastReturnBuffer(786201360, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Response), &szResponse));
	}
	else
		SBCheckError(_err);

	Response.resize(szResponse);
}

void TElSASLAnonymousClient::get_AuthID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSASLAnonymousClient_get_AuthID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1542853016, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSASLAnonymousClient::set_AuthID(const std::string &Value)
{
	SBCheckError(TElSASLAnonymousClient_set_AuthID(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSASLAnonymousClient::TElSASLAnonymousClient(TElSASLAnonymousClientHandle handle, TElOwnHandle ownHandle) : TElSASLClient(handle, ownHandle)
{
}

TElSASLAnonymousClient::TElSASLAnonymousClient() : TElSASLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSASLAnonymousClient_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSASLANONYMOUSCLIENT */

#ifdef SB_USE_CLASS_TELSASLEXTERNALCLIENT

void TElSASLExternalClient::ProcessChallenge(const std::vector<uint8_t> &Challenge, std::vector<uint8_t> &Response)
{
	int32_t szResponse = (int32_t)Response.size();
	uint32_t _err = TElSASLExternalClient_ProcessChallenge(_Handle, SB_STD_VECTOR_FRONT_ADR(Challenge), (int32_t)Challenge.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Response), &szResponse);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Response.resize(szResponse);
		SBCheckError(SBGetLastReturnBuffer(-1566527046, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Response), &szResponse));
	}
	else
		SBCheckError(_err);

	Response.resize(szResponse);
}

void TElSASLExternalClient::get_AuthID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSASLExternalClient_get_AuthID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2035996419, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSASLExternalClient::set_AuthID(const std::string &Value)
{
	SBCheckError(TElSASLExternalClient_set_AuthID(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSASLExternalClient::TElSASLExternalClient(TElSASLExternalClientHandle handle, TElOwnHandle ownHandle) : TElSASLClient(handle, ownHandle)
{
}

TElSASLExternalClient::TElSASLExternalClient() : TElSASLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSASLExternalClient_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSASLEXTERNALCLIENT */

#ifdef SB_USE_CLASS_TELSASLDIGESTMD5CLIENT

void TElSASLDigestMD5Client::ProcessChallenge(const std::vector<uint8_t> &Challenge, std::vector<uint8_t> &Response)
{
	int32_t szResponse = (int32_t)Response.size();
	uint32_t _err = TElSASLDigestMD5Client_ProcessChallenge(_Handle, SB_STD_VECTOR_FRONT_ADR(Challenge), (int32_t)Challenge.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Response), &szResponse);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Response.resize(szResponse);
		SBCheckError(SBGetLastReturnBuffer(-276318265, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Response), &szResponse));
	}
	else
		SBCheckError(_err);

	Response.resize(szResponse);
}

void TElSASLDigestMD5Client::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSASLDigestMD5Client_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-709642655, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSASLDigestMD5Client::set_Password(const std::string &Value)
{
	SBCheckError(TElSASLDigestMD5Client_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSASLDigestMD5Client::get_UserName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSASLDigestMD5Client_get_UserName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1206035971, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSASLDigestMD5Client::set_UserName(const std::string &Value)
{
	SBCheckError(TElSASLDigestMD5Client_set_UserName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSASLDigestMD5Client::get_RequestURI(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSASLDigestMD5Client_get_RequestURI(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1246356752, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSASLDigestMD5Client::set_RequestURI(const std::string &Value)
{
	SBCheckError(TElSASLDigestMD5Client_set_RequestURI(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSASLDigestMD5Client::get_RequestMethod()
{
	int32_t OutResult;
	SBCheckError(TElSASLDigestMD5Client_get_RequestMethod(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSASLDigestMD5Client::set_RequestMethod(int32_t Value)
{
	SBCheckError(TElSASLDigestMD5Client_set_RequestMethod(_Handle, Value));
}

void TElSASLDigestMD5Client::get_CustomRequestMethod(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSASLDigestMD5Client_get_CustomRequestMethod(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-320236757, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSASLDigestMD5Client::set_CustomRequestMethod(const std::string &Value)
{
	SBCheckError(TElSASLDigestMD5Client_set_CustomRequestMethod(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSASLDigestMD5Client::get_HTTPAuth()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSASLDigestMD5Client_get_HTTPAuth(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSASLDigestMD5Client::set_HTTPAuth(bool Value)
{
	SBCheckError(TElSASLDigestMD5Client_set_HTTPAuth(_Handle, (int8_t)Value));
}

TElSASLDigestMD5Client::TElSASLDigestMD5Client(TElSASLDigestMD5ClientHandle handle, TElOwnHandle ownHandle) : TElSASLClient(handle, ownHandle)
{
}

TElSASLDigestMD5Client::TElSASLDigestMD5Client() : TElSASLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSASLDigestMD5Client_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSASLDIGESTMD5CLIENT */

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELSASLNTLMCLIENT

void TElSASLNTLMClient::ProcessChallenge(const std::vector<uint8_t> &Challenge, std::vector<uint8_t> &Response)
{
	int32_t szResponse = (int32_t)Response.size();
	uint32_t _err = TElSASLNTLMClient_ProcessChallenge(_Handle, SB_STD_VECTOR_FRONT_ADR(Challenge), (int32_t)Challenge.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Response), &szResponse);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Response.resize(szResponse);
		SBCheckError(SBGetLastReturnBuffer(1685498732, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Response), &szResponse));
	}
	else
		SBCheckError(_err);

	Response.resize(szResponse);
}

void TElSASLNTLMClient::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSASLNTLMClient_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(893668085, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSASLNTLMClient::set_Password(const std::string &Value)
{
	SBCheckError(TElSASLNTLMClient_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSASLNTLMClient::get_UserName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSASLNTLMClient_get_UserName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1491772777, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSASLNTLMClient::set_UserName(const std::string &Value)
{
	SBCheckError(TElSASLNTLMClient_set_UserName(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSASLNTLMClient::TElSASLNTLMClient(TElSASLNTLMClientHandle handle, TElOwnHandle ownHandle) : TElSASLClient(handle, ownHandle)
{
}

TElSASLNTLMClient::TElSASLNTLMClient() : TElSASLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSASLNTLMClient_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSASLNTLMCLIENT */
#endif

#ifdef SB_USE_CLASS_TELSASLXOAUTH2CLIENT

void TElSASLXOAuth2Client::ProcessChallenge(const std::vector<uint8_t> &Challenge, std::vector<uint8_t> &Response)
{
	int32_t szResponse = (int32_t)Response.size();
	uint32_t _err = TElSASLXOAuth2Client_ProcessChallenge(_Handle, SB_STD_VECTOR_FRONT_ADR(Challenge), (int32_t)Challenge.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Response), &szResponse);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Response.resize(szResponse);
		SBCheckError(SBGetLastReturnBuffer(1539125077, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Response), &szResponse));
	}
	else
		SBCheckError(_err);

	Response.resize(szResponse);
}

void TElSASLXOAuth2Client::get_AccessToken(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSASLXOAuth2Client_get_AccessToken(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(950115963, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSASLXOAuth2Client::set_AccessToken(const std::string &Value)
{
	SBCheckError(TElSASLXOAuth2Client_set_AccessToken(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSASLXOAuth2Client::get_UserName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSASLXOAuth2Client_get_UserName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(168533928, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSASLXOAuth2Client::set_UserName(const std::string &Value)
{
	SBCheckError(TElSASLXOAuth2Client_set_UserName(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSASLXOAuth2Client::TElSASLXOAuth2Client(TElSASLXOAuth2ClientHandle handle, TElOwnHandle ownHandle) : TElSASLClient(handle, ownHandle)
{
}

TElSASLXOAuth2Client::TElSASLXOAuth2Client() : TElSASLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSASLXOAuth2Client_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSASLXOAUTH2CLIENT */

#ifdef SB_USE_GLOBAL_PROCS_SASL

#ifdef SB_USE_CLASS_TELSASLCLIENT
SB_INLINE TElSASLClientHandle CreateSASLClient(const std::string &Mechanism)
{
	TElSASLClientHandle OutResult;
	SBCheckError(SBSASL_CreateSASLClient(Mechanism.data(), (int32_t)Mechanism.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSASLCLIENT */

#ifdef SB_USE_CLASSES_TELSASLCLIENT_AND_TSTRINGLIST
SB_INLINE TElSASLClientHandle CreateSASLClient(const TStringList &Mechanisms)
{
	TElSASLClientHandle OutResult;
	SBCheckError(SBSASL_CreateSASLClient_1(Mechanisms.getHandle(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELSASLCLIENT_AND_TSTRINGLIST */

#endif /* SB_USE_GLOBAL_PROCS_SASL */

};	/* namespace SecureBlackbox */
