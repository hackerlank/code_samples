#include "sbcustomcrypto.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELKEYMATERIAL

SB_INLINE void TElKeyMaterial::Generate(int32_t Bits)
{
	SBCheckError(TElKeyMaterial_Generate(_Handle, Bits));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElKeyMaterial::Save(TStream &Stream)
{
	SBCheckError(TElKeyMaterial_Save(_Handle, Stream.getHandle()));
}

SB_INLINE void TElKeyMaterial::Save(TStream *Stream)
{
	SBCheckError(TElKeyMaterial_Save(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElKeyMaterial::Load(TStream &Stream, int32_t Count)
{
	SBCheckError(TElKeyMaterial_Load(_Handle, Stream.getHandle(), Count));
}

SB_INLINE void TElKeyMaterial::Load(TStream *Stream, int32_t Count)
{
	SBCheckError(TElKeyMaterial_Load(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElKeyMaterial::Assign(TElKeyMaterial &Source)
{
	SBCheckError(TElKeyMaterial_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElKeyMaterial::Assign(TElKeyMaterial *Source)
{
	SBCheckError(TElKeyMaterial_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElKeyMaterial::Equals(TElKeyMaterial &Source, bool PublicOnly)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElKeyMaterial_Equals(_Handle, Source.getHandle(), (int8_t)PublicOnly, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElKeyMaterial::Equals(TElKeyMaterial *Source, bool PublicOnly)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElKeyMaterial_Equals(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)PublicOnly, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TElKeyMaterialHandle TElKeyMaterial::Clone()
{
	TElKeyMaterialHandle OutResult;
	SBCheckError(TElKeyMaterial_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
SB_INLINE void TElKeyMaterial::AssignCryptoKey(TElCustomCryptoKey &Key)
{
	SBCheckError(TElKeyMaterial_AssignCryptoKey(_Handle, Key.getHandle()));
}

SB_INLINE void TElKeyMaterial::AssignCryptoKey(TElCustomCryptoKey *Key)
{
	SBCheckError(TElKeyMaterial_AssignCryptoKey(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

SB_INLINE void TElKeyMaterial::Persistentiate()
{
	SBCheckError(TElKeyMaterial_Persistentiate(_Handle));
}

bool TElKeyMaterial::get_Exportable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElKeyMaterial_get_Exportable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElKeyMaterial::get_Valid()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElKeyMaterial_get_Valid(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElKeyMaterial::get_Bits()
{
	int32_t OutResult;
	SBCheckError(TElKeyMaterial_get_Bits(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
TElCustomCryptoKey* TElKeyMaterial::get_Key()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElKeyMaterial_get_Key(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Key)
		this->_Inst_Key = new TElCustomCryptoKey(hOutResult, ohFalse);
	else
		this->_Inst_Key->updateHandle(hOutResult);
	return this->_Inst_Key;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

SB_INLINE int32_t TElKeyMaterial::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElKeyMaterial_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

void TElKeyMaterial::get_KeyID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElKeyMaterial_get_KeyID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1359329758, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElKeyMaterial::set_KeyID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElKeyMaterial_set_KeyID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElKeyMaterial::get_KeySubject(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElKeyMaterial_get_KeySubject(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(529649310, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElKeyMaterial::set_KeySubject(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElKeyMaterial_set_KeySubject(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_WINDOWS
void TElKeyMaterial::get_ProviderName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElKeyMaterial_get_ProviderName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1172539159, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElKeyMaterial::set_ProviderName(const std::string &Value)
{
	SBCheckError(TElKeyMaterial_set_ProviderName(_Handle, Value.data(), (int32_t)Value.length()));
}
#endif

void TElKeyMaterial::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
	this->_Inst_Key = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */
}

TElKeyMaterial::TElKeyMaterial(TElKeyMaterialHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElKeyMaterial::TElKeyMaterial() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElKeyMaterial_Create(&_Handle));
}

TElKeyMaterial::~TElKeyMaterial()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
	delete this->_Inst_Key;
	this->_Inst_Key = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */
}
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTO

TElCustomCrypto::TElCustomCrypto(TElCustomCryptoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCustomCrypto::TElCustomCrypto() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomCrypto_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMCRYPTO */

#ifdef SB_USE_CLASS_TELKEYMATERIALSTORAGE

SB_INLINE void TElKeyMaterialStorage::Clear()
{
	SBCheckError(TElKeyMaterialStorage_Clear(_Handle));
}

SB_INLINE void TElKeyMaterialStorage::ImportFrom(TElKeyMaterialStorage &KeyStorage)
{
	SBCheckError(TElKeyMaterialStorage_ImportFrom(_Handle, KeyStorage.getHandle()));
}

SB_INLINE void TElKeyMaterialStorage::ImportFrom(TElKeyMaterialStorage *KeyStorage)
{
	SBCheckError(TElKeyMaterialStorage_ImportFrom(_Handle, (KeyStorage != NULL) ? KeyStorage->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELKEYMATERIAL
SB_INLINE void TElKeyMaterialStorage::Add(TElKeyMaterial &Key)
{
	SBCheckError(TElKeyMaterialStorage_Add(_Handle, Key.getHandle()));
}

SB_INLINE void TElKeyMaterialStorage::Add(TElKeyMaterial *Key)
{
	SBCheckError(TElKeyMaterialStorage_Add(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

SB_INLINE void TElKeyMaterialStorage::Remove(int32_t Index)
{
	SBCheckError(TElKeyMaterialStorage_Remove(_Handle, Index));
}

#ifdef SB_USE_CLASS_TSBOBJECTLIST
TSBObjectList* TElKeyMaterialStorage::get_KeyList()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElKeyMaterialStorage_get_KeyList(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyList)
		this->_Inst_KeyList = new TSBObjectList(hOutResult, ohFalse);
	else
		this->_Inst_KeyList->updateHandle(hOutResult);
	return this->_Inst_KeyList;
}
#endif /* SB_USE_CLASS_TSBOBJECTLIST */

SB_INLINE int32_t TElKeyMaterialStorage::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElKeyMaterialStorage_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELKEYMATERIAL
TElKeyMaterial* TElKeyMaterialStorage::get_Keys(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElKeyMaterialStorage_get_Keys(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Keys)
		this->_Inst_Keys = new TElKeyMaterial(hOutResult, ohFalse);
	else
		this->_Inst_Keys->updateHandle(hOutResult);
	return this->_Inst_Keys;
}
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

void TElKeyMaterialStorage::initInstances()
{
#ifdef SB_USE_CLASS_TSBOBJECTLIST
	this->_Inst_KeyList = NULL;
#endif /* SB_USE_CLASS_TSBOBJECTLIST */
#ifdef SB_USE_CLASS_TELKEYMATERIAL
	this->_Inst_Keys = NULL;
#endif /* SB_USE_CLASS_TELKEYMATERIAL */
}

TElKeyMaterialStorage::TElKeyMaterialStorage(TElKeyMaterialStorageHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElKeyMaterialStorage::TElKeyMaterialStorage(TComponent &Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElKeyMaterialStorage_Create(Owner.getHandle(), &_Handle));
}

TElKeyMaterialStorage::TElKeyMaterialStorage(TComponent *Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElKeyMaterialStorage_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElKeyMaterialStorage::~TElKeyMaterialStorage()
{
#ifdef SB_USE_CLASS_TSBOBJECTLIST
	delete this->_Inst_KeyList;
	this->_Inst_KeyList = NULL;
#endif /* SB_USE_CLASS_TSBOBJECTLIST */
#ifdef SB_USE_CLASS_TELKEYMATERIAL
	delete this->_Inst_Keys;
	this->_Inst_Keys = NULL;
#endif /* SB_USE_CLASS_TELKEYMATERIAL */
}
#endif /* SB_USE_CLASS_TELKEYMATERIALSTORAGE */

};	/* namespace SecureBlackbox */
