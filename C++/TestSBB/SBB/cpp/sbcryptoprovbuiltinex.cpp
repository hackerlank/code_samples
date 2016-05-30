#include "sbcryptoprovbuiltinex.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELBUILTINEXTENDEDCRYPTOPROVIDER

SB_INLINE TElCustomCryptoProviderHandle TElBuiltInExtendedCryptoProvider::GetDefaultInstance()
{
	TElCustomCryptoProviderHandle OutResult;
	SBCheckError(TElBuiltInExtendedCryptoProvider_GetDefaultInstance(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBuiltInExtendedCryptoProvider::SetAsDefault()
{
	SBCheckError(TElBuiltInExtendedCryptoProvider_SetAsDefault());
}

SB_INLINE void TElBuiltInExtendedCryptoProvider::SetAsDefault_Inst()
{
	SBCheckError(TElBuiltInExtendedCryptoProvider_SetAsDefault_1(_Handle));
}

SB_INLINE TClassHandle TElBuiltInExtendedCryptoProvider::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltInExtendedCryptoProvider_ClassType(&OutResult));
	return OutResult;
}

TElBuiltInExtendedCryptoProvider::TElBuiltInExtendedCryptoProvider(TElBuiltInExtendedCryptoProviderHandle handle, TElOwnHandle ownHandle) : TElBuiltInCryptoProvider(handle, ownHandle)
{
}

TElBuiltInExtendedCryptoProvider::TElBuiltInExtendedCryptoProvider(TComponent &AOwner) : TElBuiltInCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInExtendedCryptoProvider_Create(AOwner.getHandle(), &_Handle));
}

TElBuiltInExtendedCryptoProvider::TElBuiltInExtendedCryptoProvider(TComponent *AOwner) : TElBuiltInCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInExtendedCryptoProvider_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS
TElBuiltInExtendedCryptoProvider::TElBuiltInExtendedCryptoProvider(TElCustomCryptoProviderOptions &Options, TComponent &AOwner) : TElBuiltInCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInExtendedCryptoProvider_Create_1(Options.getHandle(), AOwner.getHandle(), &_Handle));
}

TElBuiltInExtendedCryptoProvider::TElBuiltInExtendedCryptoProvider(TElCustomCryptoProviderOptions *Options, TComponent *AOwner) : TElBuiltInCryptoProvider(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInExtendedCryptoProvider_Create_1((Options != NULL) ? Options->getHandle() : SB_NULL_HANDLE, (AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDEROPTIONS */

#endif /* SB_USE_CLASS_TELBUILTINEXTENDEDCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELBUILTINEXTENDEDSYMMETRICCRYPTOFACTORY

TElBuiltInExtendedSymmetricCryptoFactory::TElBuiltInExtendedSymmetricCryptoFactory(TElBuiltInExtendedSymmetricCryptoFactoryHandle handle, TElOwnHandle ownHandle) : TElBuiltInSymmetricCryptoFactory(handle, ownHandle)
{
}

TElBuiltInExtendedSymmetricCryptoFactory::TElBuiltInExtendedSymmetricCryptoFactory() : TElBuiltInSymmetricCryptoFactory(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInExtendedSymmetricCryptoFactory_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELBUILTINEXTENDEDSYMMETRICCRYPTOFACTORY */

#ifdef SB_USE_CLASS_TELBUILTINIDEASYMMETRICCRYPTO

SB_INLINE void TElBuiltInIDEASymmetricCrypto::InitializeEncryption()
{
	SBCheckError(TElBuiltInIDEASymmetricCrypto_InitializeEncryption(_Handle));
}

SB_INLINE void TElBuiltInIDEASymmetricCrypto::InitializeDecryption()
{
	SBCheckError(TElBuiltInIDEASymmetricCrypto_InitializeDecryption(_Handle));
}

SB_INLINE TClassHandle TElBuiltInIDEASymmetricCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltInIDEASymmetricCrypto_ClassType(&OutResult));
	return OutResult;
}

TElBuiltInIDEASymmetricCrypto::TElBuiltInIDEASymmetricCrypto(TElBuiltInIDEASymmetricCryptoHandle handle, TElOwnHandle ownHandle) : TElBuiltInSymmetricCrypto(handle, ownHandle)
{
}

TElBuiltInIDEASymmetricCrypto::TElBuiltInIDEASymmetricCrypto(int32_t AlgID, TSBBuiltInSymmetricCryptoMode Mode) : TElBuiltInSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInIDEASymmetricCrypto_Create(AlgID, (TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

TElBuiltInIDEASymmetricCrypto::TElBuiltInIDEASymmetricCrypto(const std::vector<uint8_t> &AlgOID, TSBBuiltInSymmetricCryptoMode Mode) : TElBuiltInSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInIDEASymmetricCrypto_Create_1(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), (TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

TElBuiltInIDEASymmetricCrypto::TElBuiltInIDEASymmetricCrypto(TSBBuiltInSymmetricCryptoMode Mode) : TElBuiltInSymmetricCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltInIDEASymmetricCrypto_Create_2((TSBBuiltInSymmetricCryptoModeRaw)Mode, &_Handle));
}

#endif /* SB_USE_CLASS_TELBUILTINIDEASYMMETRICCRYPTO */

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVBUILTINEX

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
SB_INLINE TElCustomCryptoProviderHandle BuiltInCryptoProviderEx()
{
	TElCustomCryptoProviderHandle OutResult;
	SBCheckError(SBCryptoProvBuiltInEx_BuiltInCryptoProviderEx(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVBUILTINEX */

};	/* namespace SecureBlackbox */

