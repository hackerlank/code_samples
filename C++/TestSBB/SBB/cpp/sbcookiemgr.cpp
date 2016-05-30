#include "sbcookiemgr.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELCOOKIE

void TElCookie::AssembleClientCookie(int32_t Format, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCookie_AssembleClientCookie(_Handle, Format, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2083405678, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElCookie::ParseServerCookie(const std::string &ACookie, int64_t ReceivedAt, bool &DiscardCookie)
{
	int8_t DiscardCookieRaw = (int8_t)DiscardCookie;
	SBCheckError(TElCookie_ParseServerCookie(_Handle, ACookie.data(), (int32_t)ACookie.length(), ReceivedAt, &DiscardCookieRaw));
	DiscardCookie = (DiscardCookieRaw != 0);
}

SB_INLINE int32_t TElCookie::get_Included()
{
	int32_t OutResult;
	SBCheckError(TElCookie_get_Included(_Handle, &OutResult));
	return OutResult;
}

bool TElCookie::get_Persistent()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCookie_get_Persistent(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCookie::set_Persistent(bool Value)
{
	SBCheckError(TElCookie_set_Persistent(_Handle, (int8_t)Value));
}

void TElCookie::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCookie_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1024245402, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCookie::set_Name(const std::string &Value)
{
	SBCheckError(TElCookie_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElCookie::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCookie_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2107963682, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCookie::set_Value(const std::string &Value)
{
	SBCheckError(TElCookie_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElCookie::get_Comment(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCookie_get_Comment(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-34621398, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCookie::set_Comment(const std::string &Value)
{
	SBCheckError(TElCookie_set_Comment(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElCookie::get_CommentURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCookie_get_CommentURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1260140892, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCookie::set_CommentURL(const std::string &Value)
{
	SBCheckError(TElCookie_set_CommentURL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElCookie::get_Domain(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCookie_get_Domain(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(904648382, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCookie::set_Domain(const std::string &Value)
{
	SBCheckError(TElCookie_set_Domain(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElCookie::get_Expires()
{
	int64_t OutResult;
	SBCheckError(TElCookie_get_Expires(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCookie::set_Expires(int64_t Value)
{
	SBCheckError(TElCookie_set_Expires(_Handle, Value));
}

SB_INLINE int32_t TElCookie::get_Format()
{
	int32_t OutResult;
	SBCheckError(TElCookie_get_Format(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCookie::set_Format(int32_t Value)
{
	SBCheckError(TElCookie_set_Format(_Handle, Value));
}

bool TElCookie::get_HostOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCookie_get_HostOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCookie::set_HostOnly(bool Value)
{
	SBCheckError(TElCookie_set_HostOnly(_Handle, (int8_t)Value));
}

bool TElCookie::get_HTTPOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCookie_get_HTTPOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCookie::set_HTTPOnly(bool Value)
{
	SBCheckError(TElCookie_set_HTTPOnly(_Handle, (int8_t)Value));
}

void TElCookie::get_Path(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCookie_get_Path(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1752910737, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCookie::set_Path(const std::string &Value)
{
	SBCheckError(TElCookie_set_Path(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElCookie::get_Port(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCookie_get_Port(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-549363028, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCookie::set_Port(const std::string &Value)
{
	SBCheckError(TElCookie_set_Port(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElCookie::get_Secure()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCookie_get_Secure(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCookie::set_Secure(bool Value)
{
	SBCheckError(TElCookie_set_Secure(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElCookie::get_Version()
{
	int32_t OutResult;
	SBCheckError(TElCookie_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCookie::set_Version(int32_t Value)
{
	SBCheckError(TElCookie_set_Version(_Handle, Value));
}

TElCookie::TElCookie(TElCookieHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElCookie::TElCookie() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCookie_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCOOKIE */

#ifdef SB_USE_CLASS_TELCOOKIEDOMAIN

#ifdef SB_USE_CLASS_TELCOOKIE
SB_INLINE void TElCookieDomain::AddCookie(TElCookie &ACookie)
{
	SBCheckError(TElCookieDomain_AddCookie(_Handle, ACookie.getHandle()));
}

SB_INLINE void TElCookieDomain::AddCookie(TElCookie *ACookie)
{
	SBCheckError(TElCookieDomain_AddCookie(_Handle, (ACookie != NULL) ? ACookie->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCOOKIE */

SB_INLINE void TElCookieDomain::Clear()
{
	SBCheckError(TElCookieDomain_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELCOOKIE
SB_INLINE void TElCookieDomain::RemoveCookie(TElCookie &ACookie)
{
	SBCheckError(TElCookieDomain_RemoveCookie(_Handle, ACookie.getHandle()));
}

SB_INLINE void TElCookieDomain::RemoveCookie(TElCookie *ACookie)
{
	SBCheckError(TElCookieDomain_RemoveCookie(_Handle, (ACookie != NULL) ? ACookie->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCOOKIE */

SB_INLINE void TElCookieDomain::DeleteCookie(int32_t index)
{
	SBCheckError(TElCookieDomain_DeleteCookie(_Handle, index));
}

#ifdef SB_USE_CLASS_TELCOOKIE
SB_INLINE TElCookieHandle TElCookieDomain::FindSameCookie(TElCookie &Cookie)
{
	TElCookieHandle OutResult;
	SBCheckError(TElCookieDomain_FindSameCookie(_Handle, Cookie.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCookieHandle TElCookieDomain::FindSameCookie(TElCookie *Cookie)
{
	TElCookieHandle OutResult;
	SBCheckError(TElCookieDomain_FindSameCookie(_Handle, (Cookie != NULL) ? Cookie->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCOOKIE */

#ifdef SB_USE_CLASS_TELCOOKIE
TElCookie* TElCookieDomain::get_Cookies(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCookieDomain_get_Cookies(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Cookies)
		this->_Inst_Cookies = new TElCookie(hOutResult, ohFalse);
	else
		this->_Inst_Cookies->updateHandle(hOutResult);
	return this->_Inst_Cookies;
}
#endif /* SB_USE_CLASS_TELCOOKIE */

SB_INLINE int32_t TElCookieDomain::get_CookieCount()
{
	int32_t OutResult;
	SBCheckError(TElCookieDomain_get_CookieCount(_Handle, &OutResult));
	return OutResult;
}

void TElCookieDomain::get_Domain(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCookieDomain_get_Domain(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-367614429, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCookieDomain::set_Domain(const std::string &Value)
{
	SBCheckError(TElCookieDomain_set_Domain(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElCookieDomain::initInstances()
{
#ifdef SB_USE_CLASS_TELCOOKIE
	this->_Inst_Cookies = NULL;
#endif /* SB_USE_CLASS_TELCOOKIE */
}

TElCookieDomain::TElCookieDomain(TElCookieDomainHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCookieDomain::TElCookieDomain() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCookieDomain_Create(&_Handle));
}

TElCookieDomain::~TElCookieDomain()
{
#ifdef SB_USE_CLASS_TELCOOKIE
	delete this->_Inst_Cookies;
	this->_Inst_Cookies = NULL;
#endif /* SB_USE_CLASS_TELCOOKIE */
}
#endif /* SB_USE_CLASS_TELCOOKIEDOMAIN */

#ifdef SB_USE_CLASS_TELCOOKIEMANAGER

SB_INLINE void TElCookieManager::Clear()
{
	SBCheckError(TElCookieManager_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELCOOKIEDOMAIN
SB_INLINE void TElCookieManager::AddDomain(TElCookieDomain &Domain)
{
	SBCheckError(TElCookieManager_AddDomain(_Handle, Domain.getHandle()));
}

SB_INLINE void TElCookieManager::AddDomain(TElCookieDomain *Domain)
{
	SBCheckError(TElCookieManager_AddDomain(_Handle, (Domain != NULL) ? Domain->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCOOKIEDOMAIN */

SB_INLINE void TElCookieManager::DeleteDomain(int32_t Index)
{
	SBCheckError(TElCookieManager_DeleteDomain(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELCOOKIEDOMAIN
SB_INLINE void TElCookieManager::RemoveDomain(TElCookieDomain &Domain)
{
	SBCheckError(TElCookieManager_RemoveDomain(_Handle, Domain.getHandle()));
}

SB_INLINE void TElCookieManager::RemoveDomain(TElCookieDomain *Domain)
{
	SBCheckError(TElCookieManager_RemoveDomain(_Handle, (Domain != NULL) ? Domain->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCOOKIEDOMAIN */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElCookieManager::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElCookieManager_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElCookieManager::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElCookieManager_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElCookieManager::SaveToStream(TStream &Stream)
{
	SBCheckError(TElCookieManager_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElCookieManager::SaveToStream(TStream *Stream)
{
	SBCheckError(TElCookieManager_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElCookieManager::GetCookiesForURL(const std::string &URL, bool SecureSession, int32_t &Format, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCookieManager_GetCookiesForURL(_Handle, URL.data(), (int32_t)URL.length(), (int8_t)SecureSession, &Format, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1704515702, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElCookieManager::SetCookiesForURL(const std::string &URL, TStringList &CookieList, int64_t ReceivedAt, int32_t ForceFormat)
{
	SBCheckError(TElCookieManager_SetCookiesForURL(_Handle, URL.data(), (int32_t)URL.length(), CookieList.getHandle(), ReceivedAt, ForceFormat));
}

SB_INLINE void TElCookieManager::SetCookiesForURL(const std::string &URL, TStringList *CookieList, int64_t ReceivedAt, int32_t ForceFormat)
{
	SBCheckError(TElCookieManager_SetCookiesForURL(_Handle, URL.data(), (int32_t)URL.length(), (CookieList != NULL) ? CookieList->getHandle() : SB_NULL_HANDLE, ReceivedAt, ForceFormat));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElCookieManager::SetCookiesForURL(const std::string &URL, TElStringList &CookieList, int64_t ReceivedAt, int32_t ForceFormat)
{
	SBCheckError(TElCookieManager_SetCookiesForURL(_Handle, URL.data(), (int32_t)URL.length(), CookieList.getHandle(), ReceivedAt, ForceFormat));
}

SB_INLINE void TElCookieManager::SetCookiesForURL(const std::string &URL, TElStringList *CookieList, int64_t ReceivedAt, int32_t ForceFormat)
{
	SBCheckError(TElCookieManager_SetCookiesForURL(_Handle, URL.data(), (int32_t)URL.length(), (CookieList != NULL) ? CookieList->getHandle() : SB_NULL_HANDLE, ReceivedAt, ForceFormat));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE int32_t TElCookieManager::get_DomainCount()
{
	int32_t OutResult;
	SBCheckError(TElCookieManager_get_DomainCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCOOKIEDOMAIN
TElCookieDomain* TElCookieManager::get_Domains(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCookieManager_get_Domains(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Domains)
		this->_Inst_Domains = new TElCookieDomain(hOutResult, ohFalse);
	else
		this->_Inst_Domains->updateHandle(hOutResult);
	return this->_Inst_Domains;
}
#endif /* SB_USE_CLASS_TELCOOKIEDOMAIN */

void TElCookieManager::initInstances()
{
#ifdef SB_USE_CLASS_TELCOOKIEDOMAIN
	this->_Inst_Domains = NULL;
#endif /* SB_USE_CLASS_TELCOOKIEDOMAIN */
}

TElCookieManager::TElCookieManager(TElCookieManagerHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElCookieManager::TElCookieManager(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCookieManager_Create(AOwner.getHandle(), &_Handle));
}

TElCookieManager::TElCookieManager(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCookieManager_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCookieManager::~TElCookieManager()
{
#ifdef SB_USE_CLASS_TELCOOKIEDOMAIN
	delete this->_Inst_Domains;
	this->_Inst_Domains = NULL;
#endif /* SB_USE_CLASS_TELCOOKIEDOMAIN */
}
#endif /* SB_USE_CLASS_TELCOOKIEMANAGER */

};	/* namespace SecureBlackbox */
