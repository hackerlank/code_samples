#include "sbhttpauth.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_HTTPAUTH

SB_INLINE void AuthInit(PAUTH_SEQ pAS)
{
	SBCheckError(SBHTTPAuth_AuthInit(pAS));
}

SB_INLINE void AuthTerm(PAUTH_SEQ pAS)
{
	SBCheckError(SBHTTPAuth_AuthTerm(pAS));
}

bool AuthConverse(PAUTH_SEQ pAS, const std::vector<uint8_t> &BuffIn, std::vector<uint8_t> &BuffOut, bool &NeedMoreData, const std::string &Package, const std::string &User, const std::string &Password)
{
	int32_t szBuffOut = (int32_t)BuffOut.size();
	int8_t NeedMoreDataRaw = (int8_t)NeedMoreData;
	int8_t OutResultRaw = 0;
	uint32_t _err = SBHTTPAuth_AuthConverse(pAS, SB_STD_VECTOR_FRONT_ADR(BuffIn), (int32_t)BuffIn.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(BuffOut), &szBuffOut, &NeedMoreDataRaw, Package.data(), (int32_t)Package.length(), User.data(), (int32_t)User.length(), Password.data(), (int32_t)Password.length(), &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		BuffOut.resize(szBuffOut);
		SBCheckError(SBGetLastReturnBuffer(-813209678, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(BuffOut), &szBuffOut));
	}
	else
		SBCheckError(_err);

	BuffOut.resize(szBuffOut);
	NeedMoreData = (NeedMoreDataRaw != 0);
	return (OutResultRaw != 0);
}

bool AddAuthorizationHeader(std::string &Str, const std::string &Scheme, const std::string &AuthData, const std::string &UserName, const std::string &Password, bool &NeedMoreData, bool ForProxy, PAUTH_SEQ aSeq)
{
	int32_t szStr = (int32_t)Str.length();
	int8_t NeedMoreDataRaw = (int8_t)NeedMoreData;
	int8_t OutResultRaw = 0;
	uint32_t _err = SBHTTPAuth_AddAuthorizationHeader((char *)Str.data(), &szStr, Scheme.data(), (int32_t)Scheme.length(), AuthData.data(), (int32_t)AuthData.length(), UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), &NeedMoreDataRaw, (int8_t)ForProxy, aSeq, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Str.resize(szStr);
		SBCheckError(SBGetLastReturnStringA(703882796, 0, (char *)Str.data(), &szStr));
	}
	else
		SBCheckError(_err);

	Str.resize(szStr);
	NeedMoreData = (NeedMoreDataRaw != 0);
	return (OutResultRaw != 0);
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void ValidateSecPacks(TStringList &ls)
{
	SBCheckError(SBHTTPAuth_ValidateSecPacks(ls.getHandle()));
}
SB_INLINE void ValidateSecPacks(TStringList *ls)
{
	SBCheckError(SBHTTPAuth_ValidateSecPacks((ls != NULL) ? ls->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void ValidateSecPacks(TElStringList &ls)
{
	SBCheckError(SBHTTPAuth_ValidateSecPacks(ls.getHandle()));
}
SB_INLINE void ValidateSecPacks(TElStringList *ls)
{
	SBCheckError(SBHTTPAuth_ValidateSecPacks((ls != NULL) ? ls->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

SB_INLINE void InitAuthLib()
{
	SBCheckError(SBHTTPAuth_InitAuthLib());
}

#endif /* SB_USE_GLOBAL_PROCS_HTTPAUTH */

};	/* namespace SecureBlackbox */
