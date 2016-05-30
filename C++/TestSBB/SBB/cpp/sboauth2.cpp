#include "sboauth2.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELOAUTH2SETTINGS

SB_INLINE void TElOAuth2Settings::Assign(TPersistent &Source)
{
	SBCheckError(TElOAuth2Settings_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElOAuth2Settings::Assign(TPersistent *Source)
{
	SBCheckError(TElOAuth2Settings_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElOAuth2Settings::Clear()
{
	SBCheckError(TElOAuth2Settings_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELOAUTH2CLIENT
SB_INLINE void TElOAuth2Settings::CopyParams(TElOAuth2Client &Client)
{
	SBCheckError(TElOAuth2Settings_CopyParams(_Handle, Client.getHandle()));
}

SB_INLINE void TElOAuth2Settings::CopyParams(TElOAuth2Client *Client)
{
	SBCheckError(TElOAuth2Settings_CopyParams(_Handle, (Client != NULL) ? Client->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOAUTH2CLIENT */

SB_INLINE void TElOAuth2Settings::SetParams(const std::string &ARefreshToken, const std::string &AAccessToken, const std::string &ATokenType, int64_t AExpiresAt)
{
	SBCheckError(TElOAuth2Settings_SetParams(_Handle, ARefreshToken.data(), (int32_t)ARefreshToken.length(), AAccessToken.data(), (int32_t)AAccessToken.length(), ATokenType.data(), (int32_t)ATokenType.length(), AExpiresAt));
}

void TElOAuth2Settings::get_AccessToken(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Settings_get_AccessToken(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(171564617, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Settings::set_AccessToken(const std::string &Value)
{
	SBCheckError(TElOAuth2Settings_set_AccessToken(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElOAuth2Settings::get_Complete()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOAuth2Settings_get_Complete(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t TElOAuth2Settings::get_ExpiresAt()
{
	int64_t OutResult;
	SBCheckError(TElOAuth2Settings_get_ExpiresAt(_Handle, &OutResult));
	return OutResult;
}

void TElOAuth2Settings::get_RefreshToken(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Settings_get_RefreshToken(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1630439549, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Settings::set_RefreshToken(const std::string &Value)
{
	SBCheckError(TElOAuth2Settings_set_RefreshToken(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOAuth2Settings::get_TargetHost(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Settings_get_TargetHost(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1682194764, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Settings::set_TargetHost(const std::string &Value)
{
	SBCheckError(TElOAuth2Settings_set_TargetHost(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOAuth2Settings::get_TokenType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Settings_get_TokenType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1311263758, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Settings::set_TokenType(const std::string &Value)
{
	SBCheckError(TElOAuth2Settings_set_TokenType(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOAuth2Settings::get_AuthURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Settings_get_AuthURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1184747776, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Settings::set_AuthURL(const std::string &Value)
{
	SBCheckError(TElOAuth2Settings_set_AuthURL(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElOAuth2Settings::get_CheckTargetHost()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOAuth2Settings_get_CheckTargetHost(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOAuth2Settings::set_CheckTargetHost(bool Value)
{
	SBCheckError(TElOAuth2Settings_set_CheckTargetHost(_Handle, (int8_t)Value));
}

void TElOAuth2Settings::get_ClientID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Settings_get_ClientID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-533832315, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Settings::set_ClientID(const std::string &Value)
{
	SBCheckError(TElOAuth2Settings_set_ClientID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOAuth2Settings::get_ClientSecret(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Settings_get_ClientSecret(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2047277539, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Settings::set_ClientSecret(const std::string &Value)
{
	SBCheckError(TElOAuth2Settings_set_ClientSecret(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElOAuth2Settings::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOAuth2Settings_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOAuth2Settings::set_Enabled(bool Value)
{
	SBCheckError(TElOAuth2Settings_set_Enabled(_Handle, (int8_t)Value));
}

TSBOAuth2GrantType TElOAuth2Settings::get_GrantType()
{
	TSBOAuth2GrantTypeRaw OutResultRaw = 0;
	SBCheckError(TElOAuth2Settings_get_GrantType(_Handle, &OutResultRaw));
	return (TSBOAuth2GrantType)OutResultRaw;
}

SB_INLINE void TElOAuth2Settings::set_GrantType(TSBOAuth2GrantType Value)
{
	SBCheckError(TElOAuth2Settings_set_GrantType(_Handle, (TSBOAuth2GrantTypeRaw)Value));
}

void TElOAuth2Settings::get_RedirectURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Settings_get_RedirectURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1886518478, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Settings::set_RedirectURL(const std::string &Value)
{
	SBCheckError(TElOAuth2Settings_set_RedirectURL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOAuth2Settings::get_Scope(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Settings_get_Scope(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-70514927, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Settings::set_Scope(const std::string &Value)
{
	SBCheckError(TElOAuth2Settings_set_Scope(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOAuth2Settings::get_State(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Settings_get_State(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1492156473, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Settings::set_State(const std::string &Value)
{
	SBCheckError(TElOAuth2Settings_set_State(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOAuth2Settings::get_TokenURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Settings_get_TokenURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1947382110, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Settings::set_TokenURL(const std::string &Value)
{
	SBCheckError(TElOAuth2Settings_set_TokenURL(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElOAuth2Settings::get_UseURLParams()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOAuth2Settings_get_UseURLParams(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOAuth2Settings::set_UseURLParams(bool Value)
{
	SBCheckError(TElOAuth2Settings_set_UseURLParams(_Handle, (int8_t)Value));
}

TElOAuth2Settings::TElOAuth2Settings(TElOAuth2SettingsHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElOAuth2Settings::TElOAuth2Settings() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOAuth2Settings_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOAUTH2SETTINGS */

#ifdef SB_USE_CLASS_TELOAUTH2REQUEST

SB_INLINE void TElOAuth2Request::Assign(TPersistent &Source)
{
	SBCheckError(TElOAuth2Request_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElOAuth2Request::Assign(TPersistent *Source)
{
	SBCheckError(TElOAuth2Request_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElOAuth2Request::Clear()
{
	SBCheckError(TElOAuth2Request_Clear(_Handle));
}

void TElOAuth2Request::get_Body(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOAuth2Request_get_Body(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-809270083, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElOAuth2Request::get_Header()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOAuth2Request_get_Header(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Header)
		this->_Inst_Header = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Header->updateHandle(hOutResult);
	return this->_Inst_Header;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElOAuth2Request::get_Header()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOAuth2Request_get_Header(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Header)
		this->_Inst_Header = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Header->updateHandle(hOutResult);
	return this->_Inst_Header;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE int32_t TElOAuth2Request::get_Method()
{
	int32_t OutResult;
	SBCheckError(TElOAuth2Request_get_Method(_Handle, &OutResult));
	return OutResult;
}

void TElOAuth2Request::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Request_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1059418622, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOAuth2Request::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Header = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Header = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElOAuth2Request::TElOAuth2Request(TElOAuth2RequestHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElOAuth2Request::TElOAuth2Request() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOAuth2Request_Create(&_Handle));
}

TElOAuth2Request::~TElOAuth2Request()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Header;
	this->_Inst_Header = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Header;
	this->_Inst_Header = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELOAUTH2REQUEST */

#ifdef SB_USE_CLASS_TELOAUTH2CLIENT

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
bool TElOAuth2Client::Process(TStringList &ResponseHeader, const std::vector<uint8_t> &ResponseBody, int32_t &Method, std::string &URL, TStringList &RequestHeader, std::vector<uint8_t> &RequestBody)
{
	int32_t szURL = (int32_t)URL.length();
	int32_t szRequestBody = (int32_t)RequestBody.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElOAuth2Client_Process(_Handle, ResponseHeader.getHandle(), SB_STD_VECTOR_FRONT_ADR(ResponseBody), (int32_t)ResponseBody.size(), &Method, (char *)URL.data(), &szURL, RequestHeader.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		URL.resize(szURL);
		SBCheckError(SBGetLastReturnStringA(-132518316, 4, (char *)URL.data(), &szURL));
		RequestBody.resize(szRequestBody);
		SBCheckError(SBGetLastReturnBuffer(-132518316, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody));
	}
	else
		SBCheckError(_err);

	URL.resize(szURL);
	RequestBody.resize(szRequestBody);
	return (OutResultRaw != 0);
}

bool TElOAuth2Client::Process(TStringList *ResponseHeader, const std::vector<uint8_t> &ResponseBody, int32_t &Method, std::string &URL, TStringList *RequestHeader, std::vector<uint8_t> &RequestBody)
{
	int32_t szURL = (int32_t)URL.length();
	int32_t szRequestBody = (int32_t)RequestBody.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElOAuth2Client_Process(_Handle, (ResponseHeader != NULL) ? ResponseHeader->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ResponseBody), (int32_t)ResponseBody.size(), &Method, (char *)URL.data(), &szURL, (RequestHeader != NULL) ? RequestHeader->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		URL.resize(szURL);
		SBCheckError(SBGetLastReturnStringA(-132518316, 4, (char *)URL.data(), &szURL));
		RequestBody.resize(szRequestBody);
		SBCheckError(SBGetLastReturnBuffer(-132518316, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody));
	}
	else
		SBCheckError(_err);

	URL.resize(szURL);
	RequestBody.resize(szRequestBody);
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
bool TElOAuth2Client::Process(TElStringList &ResponseHeader, const std::vector<uint8_t> &ResponseBody, int32_t &Method, std::string &URL, TElStringList &RequestHeader, std::vector<uint8_t> &RequestBody)
{
	int32_t szURL = (int32_t)URL.length();
	int32_t szRequestBody = (int32_t)RequestBody.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElOAuth2Client_Process(_Handle, ResponseHeader.getHandle(), SB_STD_VECTOR_FRONT_ADR(ResponseBody), (int32_t)ResponseBody.size(), &Method, (char *)URL.data(), &szURL, RequestHeader.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		URL.resize(szURL);
		SBCheckError(SBGetLastReturnStringA(2123190349, 4, (char *)URL.data(), &szURL));
		RequestBody.resize(szRequestBody);
		SBCheckError(SBGetLastReturnBuffer(2123190349, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody));
	}
	else
		SBCheckError(_err);

	URL.resize(szURL);
	RequestBody.resize(szRequestBody);
	return (OutResultRaw != 0);
}

bool TElOAuth2Client::Process(TElStringList *ResponseHeader, const std::vector<uint8_t> &ResponseBody, int32_t &Method, std::string &URL, TElStringList *RequestHeader, std::vector<uint8_t> &RequestBody)
{
	int32_t szURL = (int32_t)URL.length();
	int32_t szRequestBody = (int32_t)RequestBody.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElOAuth2Client_Process(_Handle, (ResponseHeader != NULL) ? ResponseHeader->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ResponseBody), (int32_t)ResponseBody.size(), &Method, (char *)URL.data(), &szURL, (RequestHeader != NULL) ? RequestHeader->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		URL.resize(szURL);
		SBCheckError(SBGetLastReturnStringA(2123190349, 4, (char *)URL.data(), &szURL));
		RequestBody.resize(szRequestBody);
		SBCheckError(SBGetLastReturnBuffer(2123190349, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody));
	}
	else
		SBCheckError(_err);

	URL.resize(szURL);
	RequestBody.resize(szRequestBody);
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TELOAUTH2REQUEST_AND_TSTRINGLIST
bool TElOAuth2Client::Process(TStringList &ResponseHeader, const std::vector<uint8_t> &ResponseBody, TElOAuth2Request &NewRequest)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOAuth2Client_Process_1(_Handle, ResponseHeader.getHandle(), SB_STD_VECTOR_FRONT_ADR(ResponseBody), (int32_t)ResponseBody.size(), NewRequest.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOAuth2Client::Process(TStringList *ResponseHeader, const std::vector<uint8_t> &ResponseBody, TElOAuth2Request *NewRequest)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOAuth2Client_Process_1(_Handle, (ResponseHeader != NULL) ? ResponseHeader->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ResponseBody), (int32_t)ResponseBody.size(), (NewRequest != NULL) ? NewRequest->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELOAUTH2REQUEST_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELOAUTH2REQUEST_AND_TELSTRINGLIST
bool TElOAuth2Client::Process(TElStringList &ResponseHeader, const std::vector<uint8_t> &ResponseBody, TElOAuth2Request &NewRequest)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOAuth2Client_Process_1(_Handle, ResponseHeader.getHandle(), SB_STD_VECTOR_FRONT_ADR(ResponseBody), (int32_t)ResponseBody.size(), NewRequest.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOAuth2Client::Process(TElStringList *ResponseHeader, const std::vector<uint8_t> &ResponseBody, TElOAuth2Request *NewRequest)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOAuth2Client_Process_1(_Handle, (ResponseHeader != NULL) ? ResponseHeader->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ResponseBody), (int32_t)ResponseBody.size(), (NewRequest != NULL) ? NewRequest->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELOAUTH2REQUEST_AND_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
void TElOAuth2Client::Refresh(int32_t &Method, std::string &URL, TStringList &RequestHeader, std::vector<uint8_t> &RequestBody)
{
	int32_t szURL = (int32_t)URL.length();
	int32_t szRequestBody = (int32_t)RequestBody.size();
	uint32_t _err = TElOAuth2Client_Refresh(_Handle, &Method, (char *)URL.data(), &szURL, RequestHeader.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		URL.resize(szURL);
		SBCheckError(SBGetLastReturnStringA(1480244660, 2, (char *)URL.data(), &szURL));
		RequestBody.resize(szRequestBody);
		SBCheckError(SBGetLastReturnBuffer(1480244660, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody));
	}
	else
		SBCheckError(_err);

	URL.resize(szURL);
	RequestBody.resize(szRequestBody);
}

void TElOAuth2Client::Refresh(int32_t &Method, std::string &URL, TStringList *RequestHeader, std::vector<uint8_t> &RequestBody)
{
	int32_t szURL = (int32_t)URL.length();
	int32_t szRequestBody = (int32_t)RequestBody.size();
	uint32_t _err = TElOAuth2Client_Refresh(_Handle, &Method, (char *)URL.data(), &szURL, (RequestHeader != NULL) ? RequestHeader->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		URL.resize(szURL);
		SBCheckError(SBGetLastReturnStringA(1480244660, 2, (char *)URL.data(), &szURL));
		RequestBody.resize(szRequestBody);
		SBCheckError(SBGetLastReturnBuffer(1480244660, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody));
	}
	else
		SBCheckError(_err);

	URL.resize(szURL);
	RequestBody.resize(szRequestBody);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
void TElOAuth2Client::Refresh(int32_t &Method, std::string &URL, TElStringList &RequestHeader, std::vector<uint8_t> &RequestBody)
{
	int32_t szURL = (int32_t)URL.length();
	int32_t szRequestBody = (int32_t)RequestBody.size();
	uint32_t _err = TElOAuth2Client_Refresh(_Handle, &Method, (char *)URL.data(), &szURL, RequestHeader.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		URL.resize(szURL);
		SBCheckError(SBGetLastReturnStringA(1704849633, 2, (char *)URL.data(), &szURL));
		RequestBody.resize(szRequestBody);
		SBCheckError(SBGetLastReturnBuffer(1704849633, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody));
	}
	else
		SBCheckError(_err);

	URL.resize(szURL);
	RequestBody.resize(szRequestBody);
}

void TElOAuth2Client::Refresh(int32_t &Method, std::string &URL, TElStringList *RequestHeader, std::vector<uint8_t> &RequestBody)
{
	int32_t szURL = (int32_t)URL.length();
	int32_t szRequestBody = (int32_t)RequestBody.size();
	uint32_t _err = TElOAuth2Client_Refresh(_Handle, &Method, (char *)URL.data(), &szURL, (RequestHeader != NULL) ? RequestHeader->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		URL.resize(szURL);
		SBCheckError(SBGetLastReturnStringA(1704849633, 2, (char *)URL.data(), &szURL));
		RequestBody.resize(szRequestBody);
		SBCheckError(SBGetLastReturnBuffer(1704849633, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody));
	}
	else
		SBCheckError(_err);

	URL.resize(szURL);
	RequestBody.resize(szRequestBody);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELOAUTH2REQUEST
SB_INLINE void TElOAuth2Client::Refresh(TElOAuth2Request &Request)
{
	SBCheckError(TElOAuth2Client_Refresh_1(_Handle, Request.getHandle()));
}

SB_INLINE void TElOAuth2Client::Refresh(TElOAuth2Request *Request)
{
	SBCheckError(TElOAuth2Client_Refresh_1(_Handle, (Request != NULL) ? Request->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOAUTH2REQUEST */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
void TElOAuth2Client::Start(int32_t &Method, std::string &URL, TStringList &RequestHeader, std::vector<uint8_t> &RequestBody)
{
	int32_t szURL = (int32_t)URL.length();
	int32_t szRequestBody = (int32_t)RequestBody.size();
	uint32_t _err = TElOAuth2Client_Start(_Handle, &Method, (char *)URL.data(), &szURL, RequestHeader.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		URL.resize(szURL);
		SBCheckError(SBGetLastReturnStringA(-1060070478, 2, (char *)URL.data(), &szURL));
		RequestBody.resize(szRequestBody);
		SBCheckError(SBGetLastReturnBuffer(-1060070478, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody));
	}
	else
		SBCheckError(_err);

	URL.resize(szURL);
	RequestBody.resize(szRequestBody);
}

void TElOAuth2Client::Start(int32_t &Method, std::string &URL, TStringList *RequestHeader, std::vector<uint8_t> &RequestBody)
{
	int32_t szURL = (int32_t)URL.length();
	int32_t szRequestBody = (int32_t)RequestBody.size();
	uint32_t _err = TElOAuth2Client_Start(_Handle, &Method, (char *)URL.data(), &szURL, (RequestHeader != NULL) ? RequestHeader->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		URL.resize(szURL);
		SBCheckError(SBGetLastReturnStringA(-1060070478, 2, (char *)URL.data(), &szURL));
		RequestBody.resize(szRequestBody);
		SBCheckError(SBGetLastReturnBuffer(-1060070478, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody));
	}
	else
		SBCheckError(_err);

	URL.resize(szURL);
	RequestBody.resize(szRequestBody);
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
void TElOAuth2Client::Start(int32_t &Method, std::string &URL, TElStringList &RequestHeader, std::vector<uint8_t> &RequestBody)
{
	int32_t szURL = (int32_t)URL.length();
	int32_t szRequestBody = (int32_t)RequestBody.size();
	uint32_t _err = TElOAuth2Client_Start(_Handle, &Method, (char *)URL.data(), &szURL, RequestHeader.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		URL.resize(szURL);
		SBCheckError(SBGetLastReturnStringA(-506836368, 2, (char *)URL.data(), &szURL));
		RequestBody.resize(szRequestBody);
		SBCheckError(SBGetLastReturnBuffer(-506836368, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody));
	}
	else
		SBCheckError(_err);

	URL.resize(szURL);
	RequestBody.resize(szRequestBody);
}

void TElOAuth2Client::Start(int32_t &Method, std::string &URL, TElStringList *RequestHeader, std::vector<uint8_t> &RequestBody)
{
	int32_t szURL = (int32_t)URL.length();
	int32_t szRequestBody = (int32_t)RequestBody.size();
	uint32_t _err = TElOAuth2Client_Start(_Handle, &Method, (char *)URL.data(), &szURL, (RequestHeader != NULL) ? RequestHeader->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		URL.resize(szURL);
		SBCheckError(SBGetLastReturnStringA(-506836368, 2, (char *)URL.data(), &szURL));
		RequestBody.resize(szRequestBody);
		SBCheckError(SBGetLastReturnBuffer(-506836368, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(RequestBody), &szRequestBody));
	}
	else
		SBCheckError(_err);

	URL.resize(szURL);
	RequestBody.resize(szRequestBody);
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELOAUTH2REQUEST
SB_INLINE void TElOAuth2Client::Start(TElOAuth2Request &Request)
{
	SBCheckError(TElOAuth2Client_Start_1(_Handle, Request.getHandle()));
}

SB_INLINE void TElOAuth2Client::Start(TElOAuth2Request *Request)
{
	SBCheckError(TElOAuth2Client_Start_1(_Handle, (Request != NULL) ? Request->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOAUTH2REQUEST */

#ifdef SB_USE_CLASS_TELOAUTH2SETTINGS
SB_INLINE void TElOAuth2Client::Apply(TElOAuth2Settings &Settings)
{
	SBCheckError(TElOAuth2Client_Apply(_Handle, Settings.getHandle()));
}

SB_INLINE void TElOAuth2Client::Apply(TElOAuth2Settings *Settings)
{
	SBCheckError(TElOAuth2Client_Apply(_Handle, (Settings != NULL) ? Settings->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOAUTH2SETTINGS */

void TElOAuth2Client::get_AccessToken(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Client_get_AccessToken(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-847733687, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOAuth2Client::get_AuthURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Client_get_AuthURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(758586444, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Client::set_AuthURL(const std::string &Value)
{
	SBCheckError(TElOAuth2Client_set_AuthURL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOAuth2Client::get_ClientID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Client_get_ClientID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1613757171, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Client::set_ClientID(const std::string &Value)
{
	SBCheckError(TElOAuth2Client_set_ClientID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOAuth2Client::get_ClientSecret(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Client_get_ClientSecret(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2059516065, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Client::set_ClientSecret(const std::string &Value)
{
	SBCheckError(TElOAuth2Client_set_ClientSecret(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElOAuth2Client::get_Complete()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOAuth2Client_get_Complete(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t TElOAuth2Client::get_ExpiresAt()
{
	int64_t OutResult;
	SBCheckError(TElOAuth2Client_get_ExpiresAt(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOAuth2Client::get_ExpiresIn()
{
	int32_t OutResult;
	SBCheckError(TElOAuth2Client_get_ExpiresIn(_Handle, &OutResult));
	return OutResult;
}

TSBOAuth2GrantType TElOAuth2Client::get_GrantType()
{
	TSBOAuth2GrantTypeRaw OutResultRaw = 0;
	SBCheckError(TElOAuth2Client_get_GrantType(_Handle, &OutResultRaw));
	return (TSBOAuth2GrantType)OutResultRaw;
}

SB_INLINE void TElOAuth2Client::set_GrantType(TSBOAuth2GrantType Value)
{
	SBCheckError(TElOAuth2Client_set_GrantType(_Handle, (TSBOAuth2GrantTypeRaw)Value));
}

void TElOAuth2Client::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Client_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2069924526, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Client::set_Password(const std::string &Value)
{
	SBCheckError(TElOAuth2Client_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOAuth2Client::get_RedirectURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Client_get_RedirectURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1221542194, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Client::set_RedirectURL(const std::string &Value)
{
	SBCheckError(TElOAuth2Client_set_RedirectURL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOAuth2Client::get_RefreshToken(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Client_get_RefreshToken(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1642711359, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Client::set_RefreshToken(const std::string &Value)
{
	SBCheckError(TElOAuth2Client_set_RefreshToken(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOAuth2Client::get_Scope(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Client_get_Scope(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1651875393, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Client::set_Scope(const std::string &Value)
{
	SBCheckError(TElOAuth2Client_set_Scope(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOAuth2Client::get_State(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Client_get_State(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1052173975, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Client::set_State(const std::string &Value)
{
	SBCheckError(TElOAuth2Client_set_State(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOAuth2Client::get_TokenType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Client_get_TokenType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1389053628, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOAuth2Client::get_TokenURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Client_get_TokenURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(200075734, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Client::set_TokenURL(const std::string &Value)
{
	SBCheckError(TElOAuth2Client_set_TokenURL(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElOAuth2Client::get_UseURLParams()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOAuth2Client_get_UseURLParams(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOAuth2Client::set_UseURLParams(bool Value)
{
	SBCheckError(TElOAuth2Client_set_UseURLParams(_Handle, (int8_t)Value));
}

void TElOAuth2Client::get_UserName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2Client_get_UserName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(382625074, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOAuth2Client::set_UserName(const std::string &Value)
{
	SBCheckError(TElOAuth2Client_set_UserName(_Handle, Value.data(), (int32_t)Value.length()));
}

TElOAuth2Client::TElOAuth2Client(TElOAuth2ClientHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElOAuth2Client::TElOAuth2Client() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOAuth2Client_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOAUTH2CLIENT */

#ifdef SB_USE_CLASS_TELOAUTH2REDIRECTRECEIVER

SB_INLINE void TElOAuth2RedirectReceiver::Activate(const std::string &URL)
{
	SBCheckError(TElOAuth2RedirectReceiver_Activate(_Handle, URL.data(), (int32_t)URL.length()));
}

SB_INLINE void TElOAuth2RedirectReceiver::Activate(const std::string &LocalAddress, uint16_t LocalPort)
{
	SBCheckError(TElOAuth2RedirectReceiver_Activate_1(_Handle, LocalAddress.data(), (int32_t)LocalAddress.length(), LocalPort));
}

SB_INLINE void TElOAuth2RedirectReceiver::Deactivate()
{
	SBCheckError(TElOAuth2RedirectReceiver_Deactivate(_Handle));
}

bool TElOAuth2RedirectReceiver::Receive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOAuth2RedirectReceiver_Receive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOAuth2RedirectReceiver::Reset()
{
	SBCheckError(TElOAuth2RedirectReceiver_Reset(_Handle));
}

bool TElOAuth2RedirectReceiver::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOAuth2RedirectReceiver_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElOAuth2RedirectReceiver::get_AuthorizationCode(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOAuth2RedirectReceiver_get_AuthorizationCode(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1043151050, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElOAuth2RedirectReceiver::get_Done()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOAuth2RedirectReceiver_get_Done(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElOAuth2RedirectReceiver::get_ReceivedHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOAuth2RedirectReceiver_get_ReceivedHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ReceivedHeaders)
		this->_Inst_ReceivedHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_ReceivedHeaders->updateHandle(hOutResult);
	return this->_Inst_ReceivedHeaders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElOAuth2RedirectReceiver::get_ReceivedHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOAuth2RedirectReceiver_get_ReceivedHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ReceivedHeaders)
		this->_Inst_ReceivedHeaders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_ReceivedHeaders->updateHandle(hOutResult);
	return this->_Inst_ReceivedHeaders;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE int32_t TElOAuth2RedirectReceiver::get_BufferSize()
{
	int32_t OutResult;
	SBCheckError(TElOAuth2RedirectReceiver_get_BufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOAuth2RedirectReceiver::set_BufferSize(int32_t Value)
{
	SBCheckError(TElOAuth2RedirectReceiver_set_BufferSize(_Handle, Value));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElOAuth2RedirectReceiver::get_ResponsePage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOAuth2RedirectReceiver_get_ResponsePage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResponsePage)
		this->_Inst_ResponsePage = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_ResponsePage->updateHandle(hOutResult);
	return this->_Inst_ResponsePage;
}

SB_INLINE void TElOAuth2RedirectReceiver::set_ResponsePage(TStringList &Value)
{
	SBCheckError(TElOAuth2RedirectReceiver_set_ResponsePage(_Handle, Value.getHandle()));
}

SB_INLINE void TElOAuth2RedirectReceiver::set_ResponsePage(TStringList *Value)
{
	SBCheckError(TElOAuth2RedirectReceiver_set_ResponsePage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElOAuth2RedirectReceiver::get_ResponsePage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOAuth2RedirectReceiver_get_ResponsePage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ResponsePage)
		this->_Inst_ResponsePage = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_ResponsePage->updateHandle(hOutResult);
	return this->_Inst_ResponsePage;
}

SB_INLINE void TElOAuth2RedirectReceiver::set_ResponsePage(TElStringList &Value)
{
	SBCheckError(TElOAuth2RedirectReceiver_set_ResponsePage(_Handle, Value.getHandle()));
}

SB_INLINE void TElOAuth2RedirectReceiver::set_ResponsePage(TElStringList *Value)
{
	SBCheckError(TElOAuth2RedirectReceiver_set_ResponsePage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
bool TElOAuth2RedirectReceiver::get_UseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOAuth2RedirectReceiver_get_UseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOAuth2RedirectReceiver::set_UseIPv6(bool Value)
{
	SBCheckError(TElOAuth2RedirectReceiver_set_UseIPv6(_Handle, (int8_t)Value));
}
#endif

SB_INLINE void TElOAuth2RedirectReceiver::get_OnComplete(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOAuth2RedirectReceiver_get_OnComplete(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOAuth2RedirectReceiver::set_OnComplete(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOAuth2RedirectReceiver_set_OnComplete(_Handle, pMethodValue, pDataValue));
}

void TElOAuth2RedirectReceiver::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_ReceivedHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_ReceivedHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_ResponsePage = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_ResponsePage = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElOAuth2RedirectReceiver::TElOAuth2RedirectReceiver(TElOAuth2RedirectReceiverHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElOAuth2RedirectReceiver::TElOAuth2RedirectReceiver(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOAuth2RedirectReceiver_Create(AOwner.getHandle(), &_Handle));
}

TElOAuth2RedirectReceiver::TElOAuth2RedirectReceiver(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOAuth2RedirectReceiver_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElOAuth2RedirectReceiver::~TElOAuth2RedirectReceiver()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_ReceivedHeaders;
	this->_Inst_ReceivedHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_ReceivedHeaders;
	this->_Inst_ReceivedHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_ResponsePage;
	this->_Inst_ResponsePage = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_ResponsePage;
	this->_Inst_ResponsePage = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELOAUTH2REDIRECTRECEIVER */

};	/* namespace SecureBlackbox */
