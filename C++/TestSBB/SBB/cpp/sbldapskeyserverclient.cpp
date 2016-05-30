#include "sbldapskeyserverclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELLDAPSKEYSERVERSEARCHFILTER

SB_INLINE void TElLDAPSKeyserverSearchFilter::AddCondition(TSBLDAPSLogicalOperator LogicalOperator, TSBLDAPSKeyserverAttribute Attribute, TSBLDAPSEquality Equality, const std::string &Value)
{
	SBCheckError(TElLDAPSKeyserverSearchFilter_AddCondition(_Handle, (TSBLDAPSLogicalOperatorRaw)LogicalOperator, (TSBLDAPSKeyserverAttributeRaw)Attribute, (TSBLDAPSEqualityRaw)Equality, Value.data(), (int32_t)Value.length()));
}

TElLDAPSKeyserverSearchFilter::TElLDAPSKeyserverSearchFilter(TElLDAPSKeyserverSearchFilterHandle handle, TElOwnHandle ownHandle) : TElLDAPSSearchFilter(handle, ownHandle)
{
}

TElLDAPSKeyserverSearchFilter::TElLDAPSKeyserverSearchFilter() : TElLDAPSSearchFilter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLDAPSKeyserverSearchFilter_Create(&_Handle));
}

TElLDAPSKeyserverSearchFilter::TElLDAPSKeyserverSearchFilter(TSBLDAPSLogicalOperator LogicalOperator, TSBLDAPSKeyserverAttribute Attribute, TSBLDAPSEquality Equality, const std::string &Value) : TElLDAPSSearchFilter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLDAPSKeyserverSearchFilter_Create_1((TSBLDAPSLogicalOperatorRaw)LogicalOperator, (TSBLDAPSKeyserverAttributeRaw)Attribute, (TSBLDAPSEqualityRaw)Equality, Value.data(), (int32_t)Value.length(), &_Handle));
}

#endif /* SB_USE_CLASS_TELLDAPSKEYSERVERSEARCHFILTER */

#ifdef SB_USE_CLASS_TELLDAPSKEYSERVERCLIENT

#ifdef SB_USE_CLASS_TELPGPKEYRING
SB_INLINE TElPGPKeyringHandle TElLDAPSKeyserverClient::Search(const std::string &ID)
{
	TElPGPKeyringHandle OutResult;
	SBCheckError(TElLDAPSKeyserverClient_Search(_Handle, ID.data(), (int32_t)ID.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TELPGPKEYRING
void TElLDAPSKeyserverClient::Search(TElPGPKeyring &KeyRing, const std::string &ID)
{
	TElClassHandle hKeyRing = KeyRing.getHandle();
	SBCheckError(TElLDAPSKeyserverClient_Search_1(_Handle, &hKeyRing, ID.data(), (int32_t)ID.length()));
	KeyRing.updateHandle(hKeyRing);
}
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASSES_TELLDAPSKEYSERVERSEARCHFILTER_AND_TELPGPKEYRING
SB_INLINE TElPGPKeyringHandle TElLDAPSKeyserverClient::Search(const TElLDAPSKeyserverSearchFilter &Filter)
{
	TElPGPKeyringHandle OutResult;
	SBCheckError(TElLDAPSKeyserverClient_Search_2(_Handle, Filter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElPGPKeyringHandle TElLDAPSKeyserverClient::Search(const TElLDAPSKeyserverSearchFilter *Filter)
{
	TElPGPKeyringHandle OutResult;
	SBCheckError(TElLDAPSKeyserverClient_Search_2(_Handle, (Filter != NULL) ? Filter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELLDAPSKEYSERVERSEARCHFILTER_AND_TELPGPKEYRING */

#ifdef SB_USE_CLASSES_TELLDAPSKEYSERVERSEARCHFILTER_AND_TELPGPKEYRING
void TElLDAPSKeyserverClient::Search(TElPGPKeyring &KeyRing, const TElLDAPSKeyserverSearchFilter &Filter)
{
	TElClassHandle hKeyRing = KeyRing.getHandle();
	SBCheckError(TElLDAPSKeyserverClient_Search_3(_Handle, &hKeyRing, Filter.getHandle()));
	KeyRing.updateHandle(hKeyRing);
}

void TElLDAPSKeyserverClient::Search(TElPGPKeyring &KeyRing, const TElLDAPSKeyserverSearchFilter *Filter)
{
	TElClassHandle hKeyRing = KeyRing.getHandle();
	SBCheckError(TElLDAPSKeyserverClient_Search_3(_Handle, &hKeyRing, (Filter != NULL) ? Filter->getHandle() : SB_NULL_HANDLE));
	KeyRing.updateHandle(hKeyRing);
}
#endif /* SB_USE_CLASSES_TELLDAPSKEYSERVERSEARCHFILTER_AND_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
SB_INLINE void TElLDAPSKeyserverClient::Remove(const TElPGPPublicKey &Key)
{
	SBCheckError(TElLDAPSKeyserverClient_Remove(_Handle, Key.getHandle()));
}

SB_INLINE void TElLDAPSKeyserverClient::Remove(const TElPGPPublicKey *Key)
{
	SBCheckError(TElLDAPSKeyserverClient_Remove(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

SB_INLINE void TElLDAPSKeyserverClient::Remove(const std::string &KeyID)
{
	SBCheckError(TElLDAPSKeyserverClient_Remove_1(_Handle, KeyID.data(), (int32_t)KeyID.length()));
}

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
SB_INLINE void TElLDAPSKeyserverClient::Add(const TElPGPPublicKey &Key)
{
	SBCheckError(TElLDAPSKeyserverClient_Add(_Handle, Key.getHandle()));
}

SB_INLINE void TElLDAPSKeyserverClient::Add(const TElPGPPublicKey *Key)
{
	SBCheckError(TElLDAPSKeyserverClient_Add(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

void TElLDAPSKeyserverClient::get_ServerSoftwareName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPSKeyserverClient_get_ServerSoftwareName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1281649303, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElLDAPSKeyserverClient::get_ServerSoftwareVersion(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElLDAPSKeyserverClient_get_ServerSoftwareVersion(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2056969058, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElLDAPSKeyserverClient::get_KeySearchRetryCount()
{
	int32_t OutResult;
	SBCheckError(TElLDAPSKeyserverClient_get_KeySearchRetryCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElLDAPSKeyserverClient::set_KeySearchRetryCount(int32_t Value)
{
	SBCheckError(TElLDAPSKeyserverClient_set_KeySearchRetryCount(_Handle, Value));
}

bool TElLDAPSKeyserverClient::get_IncludeSubkeys()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElLDAPSKeyserverClient_get_IncludeSubkeys(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElLDAPSKeyserverClient::set_IncludeSubkeys(bool Value)
{
	SBCheckError(TElLDAPSKeyserverClient_set_IncludeSubkeys(_Handle, (int8_t)Value));
}

bool TElLDAPSKeyserverClient::get_IncludeDisabledKeys()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElLDAPSKeyserverClient_get_IncludeDisabledKeys(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElLDAPSKeyserverClient::set_IncludeDisabledKeys(bool Value)
{
	SBCheckError(TElLDAPSKeyserverClient_set_IncludeDisabledKeys(_Handle, (int8_t)Value));
}

bool TElLDAPSKeyserverClient::get_IncludeRevokedKeys()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElLDAPSKeyserverClient_get_IncludeRevokedKeys(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElLDAPSKeyserverClient::set_IncludeRevokedKeys(bool Value)
{
	SBCheckError(TElLDAPSKeyserverClient_set_IncludeRevokedKeys(_Handle, (int8_t)Value));
}

TElLDAPSKeyserverClient::TElLDAPSKeyserverClient(TElLDAPSKeyserverClientHandle handle, TElOwnHandle ownHandle) : TElLDAPSClient(handle, ownHandle)
{
}

TElLDAPSKeyserverClient::TElLDAPSKeyserverClient(TComponent &AOwner) : TElLDAPSClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLDAPSKeyserverClient_Create(AOwner.getHandle(), &_Handle));
}

TElLDAPSKeyserverClient::TElLDAPSKeyserverClient(TComponent *AOwner) : TElLDAPSClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElLDAPSKeyserverClient_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELLDAPSKEYSERVERCLIENT */

};	/* namespace SecureBlackbox */

