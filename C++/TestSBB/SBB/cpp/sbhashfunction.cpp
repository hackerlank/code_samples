#include "sbhashfunction.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL

void TElHMACKeyMaterial::get_Key_ByteArray(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElHMACKeyMaterial_get_Key_ByteArray(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(95393699, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHMACKeyMaterial::set_Key_ByteArray(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElHMACKeyMaterial_set_Key_ByteArray(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElHMACKeyMaterial::get_Nonce(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElHMACKeyMaterial_get_Nonce(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1252546576, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElHMACKeyMaterial::set_Nonce(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElHMACKeyMaterial_set_Nonce(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProvider* TElHMACKeyMaterial::get_CryptoProvider()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHMACKeyMaterial_get_CryptoProvider(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProvider)
		this->_Inst_CryptoProvider = new TElCustomCryptoProvider(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProvider->updateHandle(hOutResult);
	return this->_Inst_CryptoProvider;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

void TElHMACKeyMaterial::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
}

TElHMACKeyMaterial::TElHMACKeyMaterial(TElHMACKeyMaterialHandle handle, TElOwnHandle ownHandle) : TElKeyMaterial(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElHMACKeyMaterial::TElHMACKeyMaterial(TElCustomCryptoProvider &Prov) : TElKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHMACKeyMaterial_Create(Prov.getHandle(), &_Handle));
}

TElHMACKeyMaterial::TElHMACKeyMaterial(TElCustomCryptoProvider *Prov) : TElKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHMACKeyMaterial_Create((Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER
TElHMACKeyMaterial::TElHMACKeyMaterial(TElCustomCryptoKey &Key, TElCustomCryptoProvider &Prov) : TElKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHMACKeyMaterial_Create_1(Key.getHandle(), Prov.getHandle(), &_Handle));
}

TElHMACKeyMaterial::TElHMACKeyMaterial(TElCustomCryptoKey *Key, TElCustomCryptoProvider *Prov) : TElKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHMACKeyMaterial_Create_1((Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElHMACKeyMaterial::TElHMACKeyMaterial(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHMACKeyMaterial_Create_2(Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElHMACKeyMaterial::TElHMACKeyMaterial(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHMACKeyMaterial_Create_2((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElHMACKeyMaterial::TElHMACKeyMaterial(TElCustomCryptoKey &Key, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov) : TElKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHMACKeyMaterial_Create_3(Key.getHandle(), Manager.getHandle(), Prov.getHandle(), &_Handle));
}

TElHMACKeyMaterial::TElHMACKeyMaterial(TElCustomCryptoKey *Key, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov) : TElKeyMaterial(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHMACKeyMaterial_Create_3((Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (Prov != NULL) ? Prov->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOKEY_AND_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

TElHMACKeyMaterial::~TElHMACKeyMaterial()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	delete this->_Inst_CryptoProvider;
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
}
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */

#ifdef SB_USE_CLASS_TELHASHFUNCTION

SB_INLINE void TElHashFunction::Reset()
{
	SBCheckError(TElHashFunction_Reset(_Handle));
}

SB_INLINE void TElHashFunction::Update(void * Buffer, int32_t Size)
{
	SBCheckError(TElHashFunction_Update(_Handle, Buffer, Size));
}

SB_INLINE void TElHashFunction::Update(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count)
{
	SBCheckError(TElHashFunction_Update_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), StartIndex, Count));
}

SB_INLINE void TElHashFunction::Update(const std::vector<uint8_t> &Buffer)
{
	SBCheckError(TElHashFunction_Update_2(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElHashFunction::UpdateStream(TStream &Stream, int64_t Count)
{
	SBCheckError(TElHashFunction_UpdateStream(_Handle, Stream.getHandle(), Count));
}

SB_INLINE void TElHashFunction::UpdateStream(TStream *Stream, int64_t Count)
{
	SBCheckError(TElHashFunction_UpdateStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElHashFunction::Finish(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElHashFunction_Finish(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-100778215, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TElHashFunctionHandle TElHashFunction::Clone()
{
	TElHashFunctionHandle OutResult;
	SBCheckError(TElHashFunction_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
bool TElHashFunction::IsAlgorithmSupported(int32_t Algorithm, TElCustomCryptoProvider &CryptoProvider)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHashFunction_IsAlgorithmSupported(Algorithm, CryptoProvider.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElHashFunction::IsAlgorithmSupported(int32_t Algorithm, TElCustomCryptoProvider *CryptoProvider)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHashFunction_IsAlgorithmSupported(Algorithm, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
bool TElHashFunction::IsAlgorithmSupported_Inst(int32_t Algorithm, TElCustomCryptoProvider &CryptoProvider)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHashFunction_IsAlgorithmSupported_1(_Handle, Algorithm, CryptoProvider.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElHashFunction::IsAlgorithmSupported_Inst(int32_t Algorithm, TElCustomCryptoProvider *CryptoProvider)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHashFunction_IsAlgorithmSupported_1(_Handle, Algorithm, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
bool TElHashFunction::IsAlgorithmSupported(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHashFunction_IsAlgorithmSupported_2(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), CryptoProvider.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElHashFunction::IsAlgorithmSupported(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHashFunction_IsAlgorithmSupported_2(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
bool TElHashFunction::IsAlgorithmSupported_Inst(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHashFunction_IsAlgorithmSupported_3(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), CryptoProvider.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElHashFunction::IsAlgorithmSupported_Inst(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHashFunction_IsAlgorithmSupported_3(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
bool TElHashFunction::IsAlgorithmSupported(int32_t Algorithm, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHashFunction_IsAlgorithmSupported_4(Algorithm, Manager.getHandle(), CryptoProvider.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElHashFunction::IsAlgorithmSupported(int32_t Algorithm, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHashFunction_IsAlgorithmSupported_4(Algorithm, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
bool TElHashFunction::IsAlgorithmSupported_Inst(int32_t Algorithm, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHashFunction_IsAlgorithmSupported_5(_Handle, Algorithm, Manager.getHandle(), CryptoProvider.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElHashFunction::IsAlgorithmSupported_Inst(int32_t Algorithm, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHashFunction_IsAlgorithmSupported_5(_Handle, Algorithm, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
bool TElHashFunction::IsAlgorithmSupported(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHashFunction_IsAlgorithmSupported_6(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Manager.getHandle(), CryptoProvider.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElHashFunction::IsAlgorithmSupported(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHashFunction_IsAlgorithmSupported_6(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
bool TElHashFunction::IsAlgorithmSupported_Inst(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHashFunction_IsAlgorithmSupported_7(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Manager.getHandle(), CryptoProvider.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElHashFunction::IsAlgorithmSupported_Inst(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHashFunction_IsAlgorithmSupported_7(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
SB_INLINE int32_t TElHashFunction::GetDigestSizeBits(int32_t Algorithm, TElCustomCryptoProvider &CryptoProvider)
{
	int32_t OutResult;
	SBCheckError(TElHashFunction_GetDigestSizeBits(Algorithm, CryptoProvider.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHashFunction::GetDigestSizeBits(int32_t Algorithm, TElCustomCryptoProvider *CryptoProvider)
{
	int32_t OutResult;
	SBCheckError(TElHashFunction_GetDigestSizeBits(Algorithm, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
SB_INLINE int32_t TElHashFunction::GetDigestSizeBits_Inst(int32_t Algorithm, TElCustomCryptoProvider &CryptoProvider)
{
	int32_t OutResult;
	SBCheckError(TElHashFunction_GetDigestSizeBits_1(_Handle, Algorithm, CryptoProvider.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHashFunction::GetDigestSizeBits_Inst(int32_t Algorithm, TElCustomCryptoProvider *CryptoProvider)
{
	int32_t OutResult;
	SBCheckError(TElHashFunction_GetDigestSizeBits_1(_Handle, Algorithm, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
SB_INLINE int32_t TElHashFunction::GetDigestSizeBits(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider)
{
	int32_t OutResult;
	SBCheckError(TElHashFunction_GetDigestSizeBits_2(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), CryptoProvider.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHashFunction::GetDigestSizeBits(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider)
{
	int32_t OutResult;
	SBCheckError(TElHashFunction_GetDigestSizeBits_2(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
SB_INLINE int32_t TElHashFunction::GetDigestSizeBits_Inst(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider)
{
	int32_t OutResult;
	SBCheckError(TElHashFunction_GetDigestSizeBits_3(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), CryptoProvider.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHashFunction::GetDigestSizeBits_Inst(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider)
{
	int32_t OutResult;
	SBCheckError(TElHashFunction_GetDigestSizeBits_3(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
SB_INLINE int32_t TElHashFunction::GetDigestSizeBits(int32_t Algorithm, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider)
{
	int32_t OutResult;
	SBCheckError(TElHashFunction_GetDigestSizeBits_4(Algorithm, Manager.getHandle(), CryptoProvider.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHashFunction::GetDigestSizeBits(int32_t Algorithm, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider)
{
	int32_t OutResult;
	SBCheckError(TElHashFunction_GetDigestSizeBits_4(Algorithm, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
SB_INLINE int32_t TElHashFunction::GetDigestSizeBits_Inst(int32_t Algorithm, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider)
{
	int32_t OutResult;
	SBCheckError(TElHashFunction_GetDigestSizeBits_5(_Handle, Algorithm, Manager.getHandle(), CryptoProvider.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHashFunction::GetDigestSizeBits_Inst(int32_t Algorithm, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider)
{
	int32_t OutResult;
	SBCheckError(TElHashFunction_GetDigestSizeBits_5(_Handle, Algorithm, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
SB_INLINE int32_t TElHashFunction::GetDigestSizeBits(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider)
{
	int32_t OutResult;
	SBCheckError(TElHashFunction_GetDigestSizeBits_6(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Manager.getHandle(), CryptoProvider.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHashFunction::GetDigestSizeBits(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider)
{
	int32_t OutResult;
	SBCheckError(TElHashFunction_GetDigestSizeBits_6(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
SB_INLINE int32_t TElHashFunction::GetDigestSizeBits_Inst(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider)
{
	int32_t OutResult;
	SBCheckError(TElHashFunction_GetDigestSizeBits_7(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Manager.getHandle(), CryptoProvider.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHashFunction::GetDigestSizeBits_Inst(const std::vector<uint8_t> &OID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider)
{
	int32_t OutResult;
	SBCheckError(TElHashFunction_GetDigestSizeBits_7(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

void TElHashFunction::Hash(int32_t Algorithm, void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElHashFunction_Hash(Algorithm, Buffer, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-571314624, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElHashFunction::Hash_Inst(int32_t Algorithm, void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElHashFunction_Hash_1(_Handle, Algorithm, Buffer, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-571314624, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL
void TElHashFunction::Hash(int32_t Algorithm, TElHMACKeyMaterial &Key, void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElHashFunction_Hash_2(Algorithm, Key.getHandle(), Buffer, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1076733756, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElHashFunction::Hash(int32_t Algorithm, TElHMACKeyMaterial *Key, void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElHashFunction_Hash_2(Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, Buffer, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1076733756, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */

#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL
void TElHashFunction::Hash_Inst(int32_t Algorithm, TElHMACKeyMaterial &Key, void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElHashFunction_Hash_3(_Handle, Algorithm, Key.getHandle(), Buffer, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1076733756, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElHashFunction::Hash_Inst(int32_t Algorithm, TElHMACKeyMaterial *Key, void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElHashFunction_Hash_3(_Handle, Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, Buffer, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1076733756, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */

SB_INLINE int32_t TElHashFunction::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElHashFunction_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProvider* TElHashFunction::get_CryptoProvider()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHashFunction_get_CryptoProvider(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProvider)
		this->_Inst_CryptoProvider = new TElCustomCryptoProvider(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProvider->updateHandle(hOutResult);
	return this->_Inst_CryptoProvider;
}

SB_INLINE void TElHashFunction::set_CryptoProvider(TElCustomCryptoProvider &Value)
{
	SBCheckError(TElHashFunction_set_CryptoProvider(_Handle, Value.getHandle()));
}

SB_INLINE void TElHashFunction::set_CryptoProvider(TElCustomCryptoProvider *Value)
{
	SBCheckError(TElHashFunction_set_CryptoProvider(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL
TElHMACKeyMaterial* TElHashFunction::get_Key()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElHashFunction_get_Key(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Key)
		this->_Inst_Key = new TElHMACKeyMaterial(hOutResult, ohFalse);
	else
		this->_Inst_Key->updateHandle(hOutResult);
	return this->_Inst_Key;
}

SB_INLINE void TElHashFunction::set_Key(TElHMACKeyMaterial &Value)
{
	SBCheckError(TElHashFunction_set_Key(_Handle, Value.getHandle()));
}

SB_INLINE void TElHashFunction::set_Key(TElHMACKeyMaterial *Value)
{
	SBCheckError(TElHashFunction_set_Key(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */

void TElHashFunction::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL
	this->_Inst_Key = NULL;
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */
}

TElHashFunction::TElHashFunction(TElHashFunctionHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElHashFunction::TElHashFunction(int32_t Algorithm, TElCustomCryptoProvider &CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create(Algorithm, CryptoProvider.getHandle(), &_Handle));
}

TElHashFunction::TElHashFunction(int32_t Algorithm, TElCustomCryptoProvider *CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create(Algorithm, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElHashFunction::TElHashFunction(const std::vector<uint8_t> &OID, TElCustomCryptoProvider &CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_1(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), CryptoProvider.getHandle(), &_Handle));
}

TElHashFunction::TElHashFunction(const std::vector<uint8_t> &OID, TElCustomCryptoProvider *CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_1(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME
TElHashFunction::TElHashFunction(int32_t Algorithm, TElRelativeDistinguishedName &Parameters, TElCustomCryptoProvider &CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_2(Algorithm, Parameters.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElHashFunction::TElHashFunction(int32_t Algorithm, TElRelativeDistinguishedName *Parameters, TElCustomCryptoProvider *CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_2(Algorithm, (Parameters != NULL) ? Parameters->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME
TElHashFunction::TElHashFunction(const std::vector<uint8_t> &OID, TElRelativeDistinguishedName &Parameters, TElCustomCryptoProvider &CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Parameters.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElHashFunction::TElHashFunction(const std::vector<uint8_t> &OID, TElRelativeDistinguishedName *Parameters, TElCustomCryptoProvider *CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_3(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Parameters != NULL) ? Parameters->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElHashFunction::TElHashFunction(TElCustomCryptoProvider &CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_4(CryptoProvider.getHandle(), &_Handle));
}

TElHashFunction::TElHashFunction(TElCustomCryptoProvider *CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_4((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL
TElHashFunction::TElHashFunction(int32_t Algorithm, TElHMACKeyMaterial &Key) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_5(Algorithm, Key.getHandle(), &_Handle));
}

TElHashFunction::TElHashFunction(int32_t Algorithm, TElHMACKeyMaterial *Key) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_5(Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */

#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL
TElHashFunction::TElHashFunction(const std::vector<uint8_t> &OID, TElHMACKeyMaterial &Key) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_6(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Key.getHandle(), &_Handle));
}

TElHashFunction::TElHashFunction(const std::vector<uint8_t> &OID, TElHMACKeyMaterial *Key) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_6(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELHMACKEYMATERIAL
TElHashFunction::TElHashFunction(int32_t Algorithm, TElHMACKeyMaterial &Key, TElCustomCryptoProvider &CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_7(Algorithm, Key.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElHashFunction::TElHashFunction(int32_t Algorithm, TElHMACKeyMaterial *Key, TElCustomCryptoProvider *CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_7(Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELHMACKEYMATERIAL */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELHMACKEYMATERIAL
TElHashFunction::TElHashFunction(const std::vector<uint8_t> &OID, TElHMACKeyMaterial &Key, TElCustomCryptoProvider &CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_8(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Key.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElHashFunction::TElHashFunction(const std::vector<uint8_t> &OID, TElHMACKeyMaterial *Key, TElCustomCryptoProvider *CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_8(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELHMACKEYMATERIAL */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElHashFunction::TElHashFunction(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_9(Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElHashFunction::TElHashFunction(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_9((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELRELATIVEDISTINGUISHEDNAME
TElHashFunction::TElHashFunction(int32_t Algorithm, TElRelativeDistinguishedName &Parameters, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_10(Algorithm, Parameters.getHandle(), Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElHashFunction::TElHashFunction(int32_t Algorithm, TElRelativeDistinguishedName *Parameters, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_10(Algorithm, (Parameters != NULL) ? Parameters->getHandle() : SB_NULL_HANDLE, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELRELATIVEDISTINGUISHEDNAME
TElHashFunction::TElHashFunction(const std::vector<uint8_t> &OID, TElRelativeDistinguishedName &Parameters, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_11(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Parameters.getHandle(), Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElHashFunction::TElHashFunction(const std::vector<uint8_t> &OID, TElRelativeDistinguishedName *Parameters, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_11(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Parameters != NULL) ? Parameters->getHandle() : SB_NULL_HANDLE, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELHMACKEYMATERIAL
TElHashFunction::TElHashFunction(int32_t Algorithm, TElHMACKeyMaterial &Key, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_12(Algorithm, Key.getHandle(), Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElHashFunction::TElHashFunction(int32_t Algorithm, TElHMACKeyMaterial *Key, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_12(Algorithm, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELHMACKEYMATERIAL */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELHMACKEYMATERIAL
TElHashFunction::TElHashFunction(const std::vector<uint8_t> &OID, TElHMACKeyMaterial &Key, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_13(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), Key.getHandle(), Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElHashFunction::TElHashFunction(const std::vector<uint8_t> &OID, TElHMACKeyMaterial *Key, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElHashFunction_Create_13(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELHMACKEYMATERIAL */

TElHashFunction::~TElHashFunction()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	delete this->_Inst_CryptoProvider;
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL
	delete this->_Inst_Key;
	this->_Inst_Key = NULL;
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */
}
#endif /* SB_USE_CLASS_TELHASHFUNCTION */

};	/* namespace SecureBlackbox */

