#include "sbxmldefs.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELVERSIONURI

bool TElVersionURI::IsEqual(const std::string &URI)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElVersionURI_IsEqual(_Handle, URI.data(), (int32_t)URI.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElVersionURI::get_DefaultVersion(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElVersionURI_get_DefaultVersion(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-274675844, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElVersionURI::set_DefaultVersion(const std::string &Value)
{
	SBCheckError(TElVersionURI_set_DefaultVersion(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElVersionURI::get_LatestVersion(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElVersionURI_get_LatestVersion(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1883508564, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElVersionURI::TElVersionURI(TElVersionURIHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TSTRINGLIST
TElVersionURI::TElVersionURI(const std::string &ADefaultVersion, const std::string &ALatestVersion, const TStringList &AVersions) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElVersionURI_Create(ADefaultVersion.data(), (int32_t)ADefaultVersion.length(), ALatestVersion.data(), (int32_t)ALatestVersion.length(), AVersions.getHandle(), &_Handle));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

TElVersionURI::TElVersionURI(const TElVersionURI &ABaseURI, const std::string &AAnchor) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElVersionURI_Create_1(ABaseURI.getHandle(), AAnchor.data(), (int32_t)AAnchor.length(), &_Handle));
}

TElVersionURI::TElVersionURI(const TElVersionURI *ABaseURI, const std::string &AAnchor) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElVersionURI_Create_1((ABaseURI != NULL) ? ABaseURI->getHandle() : SB_NULL_HANDLE, AAnchor.data(), (int32_t)AAnchor.length(), &_Handle));
}

#endif /* SB_USE_CLASS_TELVERSIONURI */

};	/* namespace SecureBlackbox */

