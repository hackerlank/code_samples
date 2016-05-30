#include "sbdatastorage.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELDSCUSTOMKEYPROTECTIONHANDLER

void TElDSCustomKeyProtectionHandler::GetOID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSCustomKeyProtectionHandler_GetOID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1227672378, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDSCustomKeyProtectionHandler::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDSCustomKeyProtectionHandler_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1046809960, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDSCustomKeyProtectionHandler::Load(const std::vector<uint8_t> &Buffer)
{
	SBCheckError(TElDSCustomKeyProtectionHandler_Load(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size()));
}

void TElDSCustomKeyProtectionHandler::Save(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSCustomKeyProtectionHandler_Save(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1241977083, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TElDSCustomKeyProtectionHandlerHandle TElDSCustomKeyProtectionHandler::CreateInstance()
{
	TElDSCustomKeyProtectionHandlerHandle OutResult;
	SBCheckError(TElDSCustomKeyProtectionHandler_CreateInstance(_Handle, &OutResult));
	return OutResult;
}

void TElDSCustomKeyProtectionHandler::GetKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSCustomKeyProtectionHandler_GetKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1029457345, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDSCustomKeyProtectionHandler::SetKey(const std::vector<uint8_t> &Key)
{
	SBCheckError(TElDSCustomKeyProtectionHandler_SetKey(_Handle, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size()));
}

SB_INLINE void TElDSCustomKeyProtectionHandler::Reset()
{
	SBCheckError(TElDSCustomKeyProtectionHandler_Reset(_Handle));
}

bool TElDSCustomKeyProtectionHandler::KeyAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDSCustomKeyProtectionHandler_KeyAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDSCustomKeyProtectionHandler::ClearCache()
{
	SBCheckError(TElDSCustomKeyProtectionHandler_ClearCache(_Handle));
}

SB_INLINE TClassHandle TElDSCustomKeyProtectionHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElDSCustomKeyProtectionHandler_ClassType(&OutResult));
	return OutResult;
}

TElDSCustomKeyProtectionHandler::TElDSCustomKeyProtectionHandler(TElDSCustomKeyProtectionHandlerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElDSCustomKeyProtectionHandler::TElDSCustomKeyProtectionHandler() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDSCustomKeyProtectionHandler_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDSCUSTOMKEYPROTECTIONHANDLER */

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGEENCODINGHANDLER

SB_INLINE void TElCustomDataStorageEncodingHandler::Reset()
{
	SBCheckError(TElCustomDataStorageEncodingHandler_Reset(_Handle));
}

void TElCustomDataStorageEncodingHandler::GetOID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomDataStorageEncodingHandler_GetOID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1769623172, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElCustomDataStorageEncodingHandler::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomDataStorageEncodingHandler_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1076407532, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TElCustomDataStorageEncodingHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElCustomDataStorageEncodingHandler_ClassType(&OutResult));
	return OutResult;
}

TElCustomDataStorageEncodingHandler::TElCustomDataStorageEncodingHandler(TElCustomDataStorageEncodingHandlerHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElCustomDataStorageEncodingHandler::TElCustomDataStorageEncodingHandler(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomDataStorageEncodingHandler_Create(AOwner.getHandle(), &_Handle));
}

TElCustomDataStorageEncodingHandler::TElCustomDataStorageEncodingHandler(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomDataStorageEncodingHandler_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGEENCODINGHANDLER */

#ifdef SB_USE_CLASS_TELDSENVELOPEDDATAKEYPROTECTIONHANDLER

void TElDSEnvelopedDataKeyProtectionHandler::GetOID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSEnvelopedDataKeyProtectionHandler_GetOID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1416456398, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDSEnvelopedDataKeyProtectionHandler::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDSEnvelopedDataKeyProtectionHandler_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(93320110, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TElDSCustomKeyProtectionHandlerHandle TElDSEnvelopedDataKeyProtectionHandler::CreateInstance()
{
	TElDSCustomKeyProtectionHandlerHandle OutResult;
	SBCheckError(TElDSEnvelopedDataKeyProtectionHandler_CreateInstance(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDSEnvelopedDataKeyProtectionHandler::Load(const std::vector<uint8_t> &Buffer)
{
	SBCheckError(TElDSEnvelopedDataKeyProtectionHandler_Load(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size()));
}

void TElDSEnvelopedDataKeyProtectionHandler::Save(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSEnvelopedDataKeyProtectionHandler_Save(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-238052159, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDSEnvelopedDataKeyProtectionHandler::GetKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSEnvelopedDataKeyProtectionHandler_GetKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(186754113, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDSEnvelopedDataKeyProtectionHandler::SetKey(const std::vector<uint8_t> &Key)
{
	SBCheckError(TElDSEnvelopedDataKeyProtectionHandler_SetKey(_Handle, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size()));
}

SB_INLINE void TElDSEnvelopedDataKeyProtectionHandler::Reset()
{
	SBCheckError(TElDSEnvelopedDataKeyProtectionHandler_Reset(_Handle));
}

bool TElDSEnvelopedDataKeyProtectionHandler::KeyAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDSEnvelopedDataKeyProtectionHandler_KeyAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDSEnvelopedDataKeyProtectionHandler::ClearCache()
{
	SBCheckError(TElDSEnvelopedDataKeyProtectionHandler_ClearCache(_Handle));
}

SB_INLINE TClassHandle TElDSEnvelopedDataKeyProtectionHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElDSEnvelopedDataKeyProtectionHandler_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS7ISSUER
TElPKCS7Issuer* TElDSEnvelopedDataKeyProtectionHandler::get_CertIDs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDSEnvelopedDataKeyProtectionHandler_get_CertIDs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertIDs)
		this->_Inst_CertIDs = new TElPKCS7Issuer(hOutResult, ohFalse);
	else
		this->_Inst_CertIDs->updateHandle(hOutResult);
	return this->_Inst_CertIDs;
}
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

SB_INLINE int32_t TElDSEnvelopedDataKeyProtectionHandler::get_CertIDCount()
{
	int32_t OutResult;
	SBCheckError(TElDSEnvelopedDataKeyProtectionHandler_get_CertIDCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElDSEnvelopedDataKeyProtectionHandler::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDSEnvelopedDataKeyProtectionHandler_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElDSEnvelopedDataKeyProtectionHandler::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElDSEnvelopedDataKeyProtectionHandler_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElDSEnvelopedDataKeyProtectionHandler::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElDSEnvelopedDataKeyProtectionHandler_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

SB_INLINE int32_t TElDSEnvelopedDataKeyProtectionHandler::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElDSEnvelopedDataKeyProtectionHandler_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDSEnvelopedDataKeyProtectionHandler::set_Algorithm(int32_t Value)
{
	SBCheckError(TElDSEnvelopedDataKeyProtectionHandler_set_Algorithm(_Handle, Value));
}

SB_INLINE int32_t TElDSEnvelopedDataKeyProtectionHandler::get_BitsInKey()
{
	int32_t OutResult;
	SBCheckError(TElDSEnvelopedDataKeyProtectionHandler_get_BitsInKey(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDSEnvelopedDataKeyProtectionHandler::set_BitsInKey(int32_t Value)
{
	SBCheckError(TElDSEnvelopedDataKeyProtectionHandler_set_BitsInKey(_Handle, Value));
}

bool TElDSEnvelopedDataKeyProtectionHandler::get_UseOAEP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDSEnvelopedDataKeyProtectionHandler_get_UseOAEP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDSEnvelopedDataKeyProtectionHandler::set_UseOAEP(bool Value)
{
	SBCheckError(TElDSEnvelopedDataKeyProtectionHandler_set_UseOAEP(_Handle, (int8_t)Value));
}

void TElDSEnvelopedDataKeyProtectionHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
	this->_Inst_CertIDs = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElDSEnvelopedDataKeyProtectionHandler::TElDSEnvelopedDataKeyProtectionHandler(TElDSEnvelopedDataKeyProtectionHandlerHandle handle, TElOwnHandle ownHandle) : TElDSCustomKeyProtectionHandler(handle, ownHandle)
{
	initInstances();
}

TElDSEnvelopedDataKeyProtectionHandler::TElDSEnvelopedDataKeyProtectionHandler() : TElDSCustomKeyProtectionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDSEnvelopedDataKeyProtectionHandler_Create(&_Handle));
}

TElDSEnvelopedDataKeyProtectionHandler::~TElDSEnvelopedDataKeyProtectionHandler()
{
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
	delete this->_Inst_CertIDs;
	this->_Inst_CertIDs = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELDSENVELOPEDDATAKEYPROTECTIONHANDLER */

#ifdef SB_USE_CLASS_TELDSENCRYPTEDDATAKEYPROTECTIONHANDLER

void TElDSEncryptedDataKeyProtectionHandler::GetOID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSEncryptedDataKeyProtectionHandler_GetOID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(447065014, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDSEncryptedDataKeyProtectionHandler::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDSEncryptedDataKeyProtectionHandler_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2107548763, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TElDSCustomKeyProtectionHandlerHandle TElDSEncryptedDataKeyProtectionHandler::CreateInstance()
{
	TElDSCustomKeyProtectionHandlerHandle OutResult;
	SBCheckError(TElDSEncryptedDataKeyProtectionHandler_CreateInstance(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDSEncryptedDataKeyProtectionHandler::Load(const std::vector<uint8_t> &Buffer)
{
	SBCheckError(TElDSEncryptedDataKeyProtectionHandler_Load(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size()));
}

void TElDSEncryptedDataKeyProtectionHandler::Save(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSEncryptedDataKeyProtectionHandler_Save(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(124973038, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDSEncryptedDataKeyProtectionHandler::GetKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSEncryptedDataKeyProtectionHandler_GetKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1172924217, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDSEncryptedDataKeyProtectionHandler::SetKey(const std::vector<uint8_t> &Key)
{
	SBCheckError(TElDSEncryptedDataKeyProtectionHandler_SetKey(_Handle, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size()));
}

SB_INLINE void TElDSEncryptedDataKeyProtectionHandler::Reset()
{
	SBCheckError(TElDSEncryptedDataKeyProtectionHandler_Reset(_Handle));
}

bool TElDSEncryptedDataKeyProtectionHandler::KeyAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDSEncryptedDataKeyProtectionHandler_KeyAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDSEncryptedDataKeyProtectionHandler::ClearCache()
{
	SBCheckError(TElDSEncryptedDataKeyProtectionHandler_ClearCache(_Handle));
}

SB_INLINE TClassHandle TElDSEncryptedDataKeyProtectionHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElDSEncryptedDataKeyProtectionHandler_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDSEncryptedDataKeyProtectionHandler::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElDSEncryptedDataKeyProtectionHandler_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDSEncryptedDataKeyProtectionHandler::set_Algorithm(int32_t Value)
{
	SBCheckError(TElDSEncryptedDataKeyProtectionHandler_set_Algorithm(_Handle, Value));
}

SB_INLINE int32_t TElDSEncryptedDataKeyProtectionHandler::get_BitsInKey()
{
	int32_t OutResult;
	SBCheckError(TElDSEncryptedDataKeyProtectionHandler_get_BitsInKey(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDSEncryptedDataKeyProtectionHandler::set_BitsInKey(int32_t Value)
{
	SBCheckError(TElDSEncryptedDataKeyProtectionHandler_set_BitsInKey(_Handle, Value));
}

void TElDSEncryptedDataKeyProtectionHandler::get_EncryptionKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSEncryptedDataKeyProtectionHandler_get_EncryptionKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-368228187, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDSEncryptedDataKeyProtectionHandler::set_EncryptionKey(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDSEncryptedDataKeyProtectionHandler_set_EncryptionKey(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
TElByteArrayList* TElDSEncryptedDataKeyProtectionHandler::get_GenericKeys()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDSEncryptedDataKeyProtectionHandler_get_GenericKeys(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_GenericKeys)
		this->_Inst_GenericKeys = new TElByteArrayList(hOutResult, ohFalse);
	else
		this->_Inst_GenericKeys->updateHandle(hOutResult);
	return this->_Inst_GenericKeys;
}
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

void TElDSEncryptedDataKeyProtectionHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
	this->_Inst_GenericKeys = NULL;
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */
}

TElDSEncryptedDataKeyProtectionHandler::TElDSEncryptedDataKeyProtectionHandler(TElDSEncryptedDataKeyProtectionHandlerHandle handle, TElOwnHandle ownHandle) : TElDSCustomKeyProtectionHandler(handle, ownHandle)
{
	initInstances();
}

TElDSEncryptedDataKeyProtectionHandler::TElDSEncryptedDataKeyProtectionHandler() : TElDSCustomKeyProtectionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDSEncryptedDataKeyProtectionHandler_Create(&_Handle));
}

TElDSEncryptedDataKeyProtectionHandler::~TElDSEncryptedDataKeyProtectionHandler()
{
#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
	delete this->_Inst_GenericKeys;
	this->_Inst_GenericKeys = NULL;
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */
}
#endif /* SB_USE_CLASS_TELDSENCRYPTEDDATAKEYPROTECTIONHANDLER */

#ifdef SB_USE_CLASS_TELDSPLAINKEYPROTECTIONHANDLER

void TElDSPlainKeyProtectionHandler::GetOID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSPlainKeyProtectionHandler_GetOID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-901855, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDSPlainKeyProtectionHandler::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDSPlainKeyProtectionHandler_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1823701371, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TElDSCustomKeyProtectionHandlerHandle TElDSPlainKeyProtectionHandler::CreateInstance()
{
	TElDSCustomKeyProtectionHandlerHandle OutResult;
	SBCheckError(TElDSPlainKeyProtectionHandler_CreateInstance(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDSPlainKeyProtectionHandler::Load(const std::vector<uint8_t> &Buffer)
{
	SBCheckError(TElDSPlainKeyProtectionHandler_Load(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size()));
}

void TElDSPlainKeyProtectionHandler::Save(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSPlainKeyProtectionHandler_Save(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-408649744, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDSPlainKeyProtectionHandler::GetKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDSPlainKeyProtectionHandler_GetKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1051614370, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDSPlainKeyProtectionHandler::SetKey(const std::vector<uint8_t> &Key)
{
	SBCheckError(TElDSPlainKeyProtectionHandler_SetKey(_Handle, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size()));
}

SB_INLINE void TElDSPlainKeyProtectionHandler::Reset()
{
	SBCheckError(TElDSPlainKeyProtectionHandler_Reset(_Handle));
}

bool TElDSPlainKeyProtectionHandler::KeyAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDSPlainKeyProtectionHandler_KeyAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDSPlainKeyProtectionHandler::ClearCache()
{
	SBCheckError(TElDSPlainKeyProtectionHandler_ClearCache(_Handle));
}

SB_INLINE TClassHandle TElDSPlainKeyProtectionHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElDSPlainKeyProtectionHandler_ClassType(&OutResult));
	return OutResult;
}

TElDSPlainKeyProtectionHandler::TElDSPlainKeyProtectionHandler(TElDSPlainKeyProtectionHandlerHandle handle, TElOwnHandle ownHandle) : TElDSCustomKeyProtectionHandler(handle, ownHandle)
{
}

TElDSPlainKeyProtectionHandler::TElDSPlainKeyProtectionHandler() : TElDSCustomKeyProtectionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDSPlainKeyProtectionHandler_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDSPLAINKEYPROTECTIONHANDLER */

#ifdef SB_USE_CLASS_TELDSKEYPROTECTIONHANDLERSFACTORY

SB_INLINE void TElDSKeyProtectionHandlersFactory::RegisterHandler(TElDSKeyProtectionHandlerClassHandle Cls)
{
	SBCheckError(TElDSKeyProtectionHandlersFactory_RegisterHandler(_Handle, Cls));
}

SB_INLINE void TElDSKeyProtectionHandlersFactory::UnregisterHandler(int32_t Index)
{
	SBCheckError(TElDSKeyProtectionHandlersFactory_UnregisterHandler(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELDSCUSTOMKEYPROTECTIONHANDLER
SB_INLINE TElDSCustomKeyProtectionHandlerHandle TElDSKeyProtectionHandlersFactory::CreateInstance(const std::vector<uint8_t> &OID)
{
	TElDSCustomKeyProtectionHandlerHandle OutResult;
	SBCheckError(TElDSKeyProtectionHandlersFactory_CreateInstance(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDSCUSTOMKEYPROTECTIONHANDLER */

#ifdef SB_USE_CLASS_TELDSCUSTOMKEYPROTECTIONHANDLER
TElDSCustomKeyProtectionHandler* TElDSKeyProtectionHandlersFactory::get_RegisteredHandlers(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDSKeyProtectionHandlersFactory_get_RegisteredHandlers(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RegisteredHandlers)
		this->_Inst_RegisteredHandlers = new TElDSCustomKeyProtectionHandler(hOutResult, ohFalse);
	else
		this->_Inst_RegisteredHandlers->updateHandle(hOutResult);
	return this->_Inst_RegisteredHandlers;
}
#endif /* SB_USE_CLASS_TELDSCUSTOMKEYPROTECTIONHANDLER */

SB_INLINE int32_t TElDSKeyProtectionHandlersFactory::get_RegisteredHandlerCount()
{
	int32_t OutResult;
	SBCheckError(TElDSKeyProtectionHandlersFactory_get_RegisteredHandlerCount(_Handle, &OutResult));
	return OutResult;
}

void TElDSKeyProtectionHandlersFactory::initInstances()
{
#ifdef SB_USE_CLASS_TELDSCUSTOMKEYPROTECTIONHANDLER
	this->_Inst_RegisteredHandlers = NULL;
#endif /* SB_USE_CLASS_TELDSCUSTOMKEYPROTECTIONHANDLER */
}

TElDSKeyProtectionHandlersFactory::TElDSKeyProtectionHandlersFactory(TElDSKeyProtectionHandlersFactoryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElDSKeyProtectionHandlersFactory::TElDSKeyProtectionHandlersFactory() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDSKeyProtectionHandlersFactory_Create(&_Handle));
}

TElDSKeyProtectionHandlersFactory::~TElDSKeyProtectionHandlersFactory()
{
#ifdef SB_USE_CLASS_TELDSCUSTOMKEYPROTECTIONHANDLER
	delete this->_Inst_RegisteredHandlers;
	this->_Inst_RegisteredHandlers = NULL;
#endif /* SB_USE_CLASS_TELDSCUSTOMKEYPROTECTIONHANDLER */
}
#endif /* SB_USE_CLASS_TELDSKEYPROTECTIONHANDLERSFACTORY */

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER

SB_INLINE void TElCustomDataStorageSecurityHandler::Reset()
{
	SBCheckError(TElCustomDataStorageSecurityHandler_Reset(_Handle));
}

void TElCustomDataStorageSecurityHandler::GetOID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomDataStorageSecurityHandler_GetOID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2077776458, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElCustomDataStorageSecurityHandler::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomDataStorageSecurityHandler_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1551296791, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElCustomDataStorageSecurityHandler::CanEncrypt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomDataStorageSecurityHandler_CanEncrypt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomDataStorageSecurityHandler::CanDecrypt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomDataStorageSecurityHandler_CanDecrypt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomDataStorageSecurityHandler::ClearCache()
{
	SBCheckError(TElCustomDataStorageSecurityHandler_ClearCache(_Handle));
}

SB_INLINE TClassHandle TElCustomDataStorageSecurityHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElCustomDataStorageSecurityHandler_ClassType(&OutResult));
	return OutResult;
}

TElCustomDataStorageSecurityHandler::TElCustomDataStorageSecurityHandler(TElCustomDataStorageSecurityHandlerHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElCustomDataStorageSecurityHandler::TElCustomDataStorageSecurityHandler(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomDataStorageSecurityHandler_Create(AOwner.getHandle(), &_Handle));
}

TElCustomDataStorageSecurityHandler::TElCustomDataStorageSecurityHandler(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomDataStorageSecurityHandler_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST

SB_INLINE void TElDataStorageObjectList::Clear()
{
	SBCheckError(TElDataStorageObjectList_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGEOBJECT
TElCustomDataStorageObject* TElDataStorageObjectList::get_Objects(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDataStorageObjectList_get_Objects(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Objects)
		this->_Inst_Objects = new TElCustomDataStorageObject(hOutResult, ohFalse);
	else
		this->_Inst_Objects->updateHandle(hOutResult);
	return this->_Inst_Objects;
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGEOBJECT */

SB_INLINE int32_t TElDataStorageObjectList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElDataStorageObjectList_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElDataStorageObjectList::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGEOBJECT
	this->_Inst_Objects = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGEOBJECT */
}

TElDataStorageObjectList::TElDataStorageObjectList(TElDataStorageObjectListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElDataStorageObjectList::TElDataStorageObjectList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDataStorageObjectList_Create(&_Handle));
}

TElDataStorageObjectList::~TElDataStorageObjectList()
{
#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGEOBJECT
	delete this->_Inst_Objects;
	this->_Inst_Objects = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGEOBJECT */
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGEOBJECT

SB_INLINE void TElCustomDataStorageObject::Assign(TElCustomDataStorageObject &Source)
{
	SBCheckError(TElCustomDataStorageObject_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElCustomDataStorageObject::Assign(TElCustomDataStorageObject *Source)
{
	SBCheckError(TElCustomDataStorageObject_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElCustomDataStorageObjectHandle TElCustomDataStorageObject::Clone()
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElCustomDataStorageObject_Clone(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
TElCustomDataStorageSecurityHandler* TElCustomDataStorageObject::get_Handler()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomDataStorageObject_get_Handler(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Handler)
		this->_Inst_Handler = new TElCustomDataStorageSecurityHandler(hOutResult, ohFalse);
	else
		this->_Inst_Handler->updateHandle(hOutResult);
	return this->_Inst_Handler;
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

void TElCustomDataStorageObject::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomDataStorageObject_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1280591424, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElCustomDataStorageObject::get_Secured()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomDataStorageObject_get_Secured(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t TElCustomDataStorageObject::get_RawSize()
{
	int64_t OutResult;
	SBCheckError(TElCustomDataStorageObject_get_RawSize(_Handle, &OutResult));
	return OutResult;
}

void TElCustomDataStorageObject::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
	this->_Inst_Handler = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */
}

TElCustomDataStorageObject::TElCustomDataStorageObject(TElCustomDataStorageObjectHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCustomDataStorageObject::TElCustomDataStorageObject() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomDataStorageObject_Create(&_Handle));
}

TElCustomDataStorageObject::~TElCustomDataStorageObject()
{
#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
	delete this->_Inst_Handler;
	this->_Inst_Handler = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGE

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGEOBJECT
SB_INLINE TElCustomDataStorageObjectHandle TElCustomDataStorage::AcquireObject()
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElCustomDataStorage_AcquireObject(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGEOBJECT
void TElCustomDataStorage::ReleaseObject(TElCustomDataStorageObject &Obj)
{
	TElClassHandle hObj = Obj.getHandle();
	SBCheckError(TElCustomDataStorage_ReleaseObject(_Handle, &hObj));
	Obj.updateHandle(hObj);
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElCustomDataStorage::ReadObject(TElCustomDataStorageObject &Obj, TStream &Strm)
{
	SBCheckError(TElCustomDataStorage_ReadObject(_Handle, Obj.getHandle(), Strm.getHandle()));
}

SB_INLINE void TElCustomDataStorage::ReadObject(TElCustomDataStorageObject *Obj, TStream *Strm)
{
	SBCheckError(TElCustomDataStorage_ReadObject(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElCustomDataStorage::WriteObject(TElCustomDataStorageObject &Obj, TStream &Strm, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElCustomDataStorage_WriteObject(_Handle, Obj.getHandle(), Strm.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElCustomDataStorage::WriteObject(TElCustomDataStorageObject *Obj, TStream *Strm, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElCustomDataStorage_WriteObject(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElCustomDataStorage::ReadBlock(TElCustomDataStorageObject &Obj, TStream &Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElCustomDataStorage_ReadBlock(_Handle, Obj.getHandle(), Strm.getHandle(), Offset, Size, &Read));
}

SB_INLINE void TElCustomDataStorage::ReadBlock(TElCustomDataStorageObject *Obj, TStream *Strm, int64_t Offset, int64_t Size, int64_t &Read)
{
	SBCheckError(TElCustomDataStorage_ReadBlock(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, Offset, Size, &Read));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElCustomDataStorage::WriteBlock(TElCustomDataStorageObject &Obj, TStream &Strm, TElCustomDataStorageSecurityHandler &Handler, int64_t Offset, int64_t &Written)
{
	SBCheckError(TElCustomDataStorage_WriteBlock(_Handle, Obj.getHandle(), Strm.getHandle(), Handler.getHandle(), Offset, &Written));
}

SB_INLINE void TElCustomDataStorage::WriteBlock(TElCustomDataStorageObject *Obj, TStream *Strm, TElCustomDataStorageSecurityHandler *Handler, int64_t Offset, int64_t &Written)
{
	SBCheckError(TElCustomDataStorage_WriteBlock(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, Offset, &Written));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGEOBJECT
void TElCustomDataStorage::DeleteObject(TElCustomDataStorageObject &Obj)
{
	TElClassHandle hObj = Obj.getHandle();
	SBCheckError(TElCustomDataStorage_DeleteObject(_Handle, &hObj));
	Obj.updateHandle(hObj);
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGEOBJECT */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElCustomDataStorageSecurityHandlerHandle TElCustomDataStorage::GetProtectionInfo(TElCustomDataStorageObject &Obj)
{
	TElCustomDataStorageSecurityHandlerHandle OutResult;
	SBCheckError(TElCustomDataStorage_GetProtectionInfo(_Handle, Obj.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageSecurityHandlerHandle TElCustomDataStorage::GetProtectionInfo(TElCustomDataStorageObject *Obj)
{
	TElCustomDataStorageSecurityHandlerHandle OutResult;
	SBCheckError(TElCustomDataStorage_GetProtectionInfo(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASS_TELDATASTORAGEOBJECTLIST
SB_INLINE void TElCustomDataStorage::List(TElDataStorageObjectList &Objs)
{
	SBCheckError(TElCustomDataStorage_List(_Handle, Objs.getHandle()));
}

SB_INLINE void TElCustomDataStorage::List(TElDataStorageObjectList *Objs)
{
	SBCheckError(TElCustomDataStorage_List(_Handle, (Objs != NULL) ? Objs->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDATASTORAGEOBJECTLIST */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElCustomDataStorageObjectHandle TElCustomDataStorage::CopyObject(TElCustomDataStorageObject &Obj, TElCustomDataStorageSecurityHandler &NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElCustomDataStorage_CopyObject(_Handle, Obj.getHandle(), NewHandler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElCustomDataStorageObjectHandle TElCustomDataStorage::CopyObject(TElCustomDataStorageObject *Obj, TElCustomDataStorageSecurityHandler *NewHandler)
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElCustomDataStorage_CopyObject(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (NewHandler != NULL) ? NewHandler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGEOBJECT_AND_TELCUSTOMDATASTORAGESECURITYHANDLER */

bool TElCustomDataStorage::get_PassthroughMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomDataStorage_get_PassthroughMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomDataStorage::set_PassthroughMode(bool Value)
{
	SBCheckError(TElCustomDataStorage_set_PassthroughMode(_Handle, (int8_t)Value));
}

bool TElCustomDataStorage::get_Overwrite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomDataStorage_get_Overwrite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomDataStorage::set_Overwrite(bool Value)
{
	SBCheckError(TElCustomDataStorage_set_Overwrite(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
TElCustomDataStorageSecurityHandler* TElCustomDataStorage::get_SecurityHandler()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomDataStorage_get_SecurityHandler(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SecurityHandler)
		this->_Inst_SecurityHandler = new TElCustomDataStorageSecurityHandler(hOutResult, ohFalse);
	else
		this->_Inst_SecurityHandler->updateHandle(hOutResult);
	return this->_Inst_SecurityHandler;
}

SB_INLINE void TElCustomDataStorage::set_SecurityHandler(TElCustomDataStorageSecurityHandler &Value)
{
	SBCheckError(TElCustomDataStorage_set_SecurityHandler(_Handle, Value.getHandle()));
}

SB_INLINE void TElCustomDataStorage::set_SecurityHandler(TElCustomDataStorageSecurityHandler *Value)
{
	SBCheckError(TElCustomDataStorage_set_SecurityHandler(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

TSBProtectedObjectReadStrategy TElCustomDataStorage::get_ObjectInfoReadStrategy()
{
	TSBProtectedObjectReadStrategyRaw OutResultRaw = 0;
	SBCheckError(TElCustomDataStorage_get_ObjectInfoReadStrategy(_Handle, &OutResultRaw));
	return (TSBProtectedObjectReadStrategy)OutResultRaw;
}

SB_INLINE void TElCustomDataStorage::set_ObjectInfoReadStrategy(TSBProtectedObjectReadStrategy Value)
{
	SBCheckError(TElCustomDataStorage_set_ObjectInfoReadStrategy(_Handle, (TSBProtectedObjectReadStrategyRaw)Value));
}

SB_INLINE void TElCustomDataStorage::get_OnProgress(TSBDataStorageProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomDataStorage_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomDataStorage::set_OnProgress(TSBDataStorageProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomDataStorage_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCustomDataStorage::get_OnOperationStart(TSBDataStorageOperationStartEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomDataStorage_get_OnOperationStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomDataStorage::set_OnOperationStart(TSBDataStorageOperationStartEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomDataStorage_set_OnOperationStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCustomDataStorage::get_OnOperationFinish(TSBDataStorageOperationFinishEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomDataStorage_get_OnOperationFinish(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomDataStorage::set_OnOperationFinish(TSBDataStorageOperationFinishEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomDataStorage_set_OnOperationFinish(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCustomDataStorage::get_OnSecurityHandlerNeeded(TSBFDSSecurityHandlerNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomDataStorage_get_OnSecurityHandlerNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomDataStorage::set_OnSecurityHandlerNeeded(TSBFDSSecurityHandlerNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomDataStorage_set_OnSecurityHandlerNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCustomDataStorage::get_OnSecurityHandlerCreated(TSBFDSSecurityHandlerCreatedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomDataStorage_get_OnSecurityHandlerCreated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomDataStorage::set_OnSecurityHandlerCreated(TSBFDSSecurityHandlerCreatedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomDataStorage_set_OnSecurityHandlerCreated(_Handle, pMethodValue, pDataValue));
}

void TElCustomDataStorage::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
	this->_Inst_SecurityHandler = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */
}

TElCustomDataStorage::TElCustomDataStorage(TElCustomDataStorageHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElCustomDataStorage::TElCustomDataStorage(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomDataStorage_Create(AOwner.getHandle(), &_Handle));
}

TElCustomDataStorage::TElCustomDataStorage(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomDataStorage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCustomDataStorage::~TElCustomDataStorage()
{
#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
	delete this->_Inst_SecurityHandler;
	this->_Inst_SecurityHandler = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGE */

#ifdef SB_USE_CLASS_TELDEFAULTDATASTORAGESECURITYHANDLER

bool TElDefaultDataStorageSecurityHandler::CanEncrypt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDefaultDataStorageSecurityHandler_CanEncrypt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDefaultDataStorageSecurityHandler::CanDecrypt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDefaultDataStorageSecurityHandler_CanDecrypt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::ClearCache()
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_ClearCache(_Handle));
}

void TElDefaultDataStorageSecurityHandler::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDefaultDataStorageSecurityHandler_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-420404516, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDefaultDataStorageSecurityHandler::GetOID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDefaultDataStorageSecurityHandler_GetOID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1362081200, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::Reset()
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_Reset(_Handle));
}

SB_INLINE TClassHandle TElDefaultDataStorageSecurityHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElDefaultDataStorageSecurityHandler_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS7ISSUER
TElPKCS7Issuer* TElDefaultDataStorageSecurityHandler::get_CertIDs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_CertIDs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertIDs)
		this->_Inst_CertIDs = new TElPKCS7Issuer(hOutResult, ohFalse);
	else
		this->_Inst_CertIDs->updateHandle(hOutResult);
	return this->_Inst_CertIDs;
}
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

SB_INLINE int32_t TElDefaultDataStorageSecurityHandler::get_CertIDCount()
{
	int32_t OutResult;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_CertIDCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElDefaultDataStorageSecurityHandler::get_DataSize()
{
	int64_t OutResult;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_DataSize(_Handle, &OutResult));
	return OutResult;
}

void TElDefaultDataStorageSecurityHandler::get_GenericEncryptionKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDefaultDataStorageSecurityHandler_get_GenericEncryptionKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(908931814, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_GenericEncryptionKey(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_GenericEncryptionKey(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
TElByteArrayList* TElDefaultDataStorageSecurityHandler::get_GenericEncryptionKeys()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_GenericEncryptionKeys(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_GenericEncryptionKeys)
		this->_Inst_GenericEncryptionKeys = new TElByteArrayList(hOutResult, ohFalse);
	else
		this->_Inst_GenericEncryptionKeys->updateHandle(hOutResult);
	return this->_Inst_GenericEncryptionKeys;
}
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

bool TElDefaultDataStorageSecurityHandler::get_GenericEncryptionKeyUsed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_GenericEncryptionKeyUsed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElDefaultDataStorageSecurityHandler::get_ProtectedUserData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDefaultDataStorageSecurityHandler_get_ProtectedUserData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(758319081, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_ProtectedUserData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_ProtectedUserData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElDefaultDataStorageSecurityHandler::get_UnprotectedUserData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDefaultDataStorageSecurityHandler_get_UnprotectedUserData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(989181194, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_UnprotectedUserData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_UnprotectedUserData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElDefaultDataStorageSecurityHandler::get_SignatureFound()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_SignatureFound(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELMESSAGEVERIFIER
TElMessageVerifier* TElDefaultDataStorageSecurityHandler::get_SignatureVerifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_SignatureVerifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureVerifier)
		this->_Inst_SignatureVerifier = new TElMessageVerifier(hOutResult, ohFalse);
	else
		this->_Inst_SignatureVerifier->updateHandle(hOutResult);
	return this->_Inst_SignatureVerifier;
}
#endif /* SB_USE_CLASS_TELMESSAGEVERIFIER */

SB_INLINE int32_t TElDefaultDataStorageSecurityHandler::get_SignatureVerificationResult()
{
	int32_t OutResult;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_SignatureVerificationResult(_Handle, &OutResult));
	return OutResult;
}

bool TElDefaultDataStorageSecurityHandler::get_ObjectIntegrityRecordAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_ObjectIntegrityRecordAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElDefaultDataStorageSecurityHandler::get_MetadataIntegrityRecordAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_MetadataIntegrityRecordAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t TElDefaultDataStorageSecurityHandler::get_AuthBlockSize()
{
	int64_t OutResult;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_AuthBlockSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_AuthBlockSize(int64_t Value)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_AuthBlockSize(_Handle, Value));
}

SB_INLINE int32_t TElDefaultDataStorageSecurityHandler::get_AuthDigestAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_AuthDigestAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_AuthDigestAlgorithm(int32_t Value)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_AuthDigestAlgorithm(_Handle, Value));
}

TSBDSDigestLocation TElDefaultDataStorageSecurityHandler::get_AuthDigestLocation()
{
	TSBDSDigestLocationRaw OutResultRaw = 0;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_AuthDigestLocation(_Handle, &OutResultRaw));
	return (TSBDSDigestLocation)OutResultRaw;
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_AuthDigestLocation(TSBDSDigestLocation Value)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_AuthDigestLocation(_Handle, (TSBDSDigestLocationRaw)Value));
}

SB_INLINE int32_t TElDefaultDataStorageSecurityHandler::get_AuthHashSize()
{
	int32_t OutResult;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_AuthHashSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_AuthHashSize(int32_t Value)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_AuthHashSize(_Handle, Value));
}

TSBDSDataAuthInfoType TElDefaultDataStorageSecurityHandler::get_AuthInfoType()
{
	TSBDSDataAuthInfoTypeRaw OutResultRaw = 0;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_AuthInfoType(_Handle, &OutResultRaw));
	return (TSBDSDataAuthInfoType)OutResultRaw;
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_AuthInfoType(TSBDSDataAuthInfoType Value)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_AuthInfoType(_Handle, (TSBDSDataAuthInfoTypeRaw)Value));
}

SB_INLINE int32_t TElDefaultDataStorageSecurityHandler::get_AuthKeyLen()
{
	int32_t OutResult;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_AuthKeyLen(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_AuthKeyLen(int32_t Value)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_AuthKeyLen(_Handle, Value));
}

bool TElDefaultDataStorageSecurityHandler::get_CacheEncryptionKey()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_CacheEncryptionKey(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_CacheEncryptionKey(bool Value)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_CacheEncryptionKey(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElDefaultDataStorageSecurityHandler::get_DataEncryptionAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_DataEncryptionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_DataEncryptionAlgorithm(int32_t Value)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_DataEncryptionAlgorithm(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGEENCODINGHANDLER
TElCustomDataStorageEncodingHandler* TElDefaultDataStorageSecurityHandler::get_EncodingHandler()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_EncodingHandler(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncodingHandler)
		this->_Inst_EncodingHandler = new TElCustomDataStorageEncodingHandler(hOutResult, ohFalse);
	else
		this->_Inst_EncodingHandler->updateHandle(hOutResult);
	return this->_Inst_EncodingHandler;
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_EncodingHandler(TElCustomDataStorageEncodingHandler &Value)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_EncodingHandler(_Handle, Value.getHandle()));
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_EncodingHandler(TElCustomDataStorageEncodingHandler *Value)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_EncodingHandler(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGEENCODINGHANDLER */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElDefaultDataStorageSecurityHandler::get_EncryptionCertificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_EncryptionCertificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptionCertificates)
		this->_Inst_EncryptionCertificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_EncryptionCertificates->updateHandle(hOutResult);
	return this->_Inst_EncryptionCertificates;
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_EncryptionCertificates(TElCustomCertStorage &Value)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_EncryptionCertificates(_Handle, Value.getHandle()));
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_EncryptionCertificates(TElCustomCertStorage *Value)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_EncryptionCertificates(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

SB_INLINE int32_t TElDefaultDataStorageSecurityHandler::get_KeyEncryptionAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_KeyEncryptionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_KeyEncryptionAlgorithm(int32_t Value)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_KeyEncryptionAlgorithm(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElDefaultDataStorageSecurityHandler::get_SigningCertificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_SigningCertificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigningCertificates)
		this->_Inst_SigningCertificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_SigningCertificates->updateHandle(hOutResult);
	return this->_Inst_SigningCertificates;
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_SigningCertificates(TElCustomCertStorage &Value)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_SigningCertificates(_Handle, Value.getHandle()));
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_SigningCertificates(TElCustomCertStorage *Value)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_SigningCertificates(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

SB_INLINE int32_t TElDefaultDataStorageSecurityHandler::get_SignatureHashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_SignatureHashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_SignatureHashAlgorithm(int32_t Value)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_SignatureHashAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElDefaultDataStorageSecurityHandler::get_ExtraTrailerSpace()
{
	int32_t OutResult;
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_ExtraTrailerSpace(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_ExtraTrailerSpace(int32_t Value)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_ExtraTrailerSpace(_Handle, Value));
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::get_OnSigningPrepared(TSBDataStorageSecHandlerSigningPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_OnSigningPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_OnSigningPrepared(TSBDataStorageSecHandlerSigningPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_OnSigningPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::get_OnSignatureFound(TSBDataStorageSecHandlerSignatureFoundEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_get_OnSignatureFound(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElDefaultDataStorageSecurityHandler::set_OnSignatureFound(TSBDataStorageSecHandlerSignatureFoundEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElDefaultDataStorageSecurityHandler_set_OnSignatureFound(_Handle, pMethodValue, pDataValue));
}

void TElDefaultDataStorageSecurityHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
	this->_Inst_CertIDs = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
	this->_Inst_GenericEncryptionKeys = NULL;
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */
#ifdef SB_USE_CLASS_TELMESSAGEVERIFIER
	this->_Inst_SignatureVerifier = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEVERIFIER */
#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGEENCODINGHANDLER
	this->_Inst_EncodingHandler = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGEENCODINGHANDLER */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_EncryptionCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_SigningCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElDefaultDataStorageSecurityHandler::TElDefaultDataStorageSecurityHandler(TElDefaultDataStorageSecurityHandlerHandle handle, TElOwnHandle ownHandle) : TElCustomDataStorageSecurityHandler(handle, ownHandle)
{
	initInstances();
}

TElDefaultDataStorageSecurityHandler::TElDefaultDataStorageSecurityHandler(TComponent &AOwner) : TElCustomDataStorageSecurityHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDefaultDataStorageSecurityHandler_Create(AOwner.getHandle(), &_Handle));
}

TElDefaultDataStorageSecurityHandler::TElDefaultDataStorageSecurityHandler(TComponent *AOwner) : TElCustomDataStorageSecurityHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDefaultDataStorageSecurityHandler_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElDefaultDataStorageSecurityHandler::~TElDefaultDataStorageSecurityHandler()
{
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
	delete this->_Inst_CertIDs;
	this->_Inst_CertIDs = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
	delete this->_Inst_GenericEncryptionKeys;
	this->_Inst_GenericEncryptionKeys = NULL;
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */
#ifdef SB_USE_CLASS_TELMESSAGEVERIFIER
	delete this->_Inst_SignatureVerifier;
	this->_Inst_SignatureVerifier = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEVERIFIER */
#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGEENCODINGHANDLER
	delete this->_Inst_EncodingHandler;
	this->_Inst_EncodingHandler = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGEENCODINGHANDLER */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_EncryptionCertificates;
	this->_Inst_EncryptionCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_SigningCertificates;
	this->_Inst_SigningCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELDEFAULTDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASS_TELDATASTORAGESECURITYHANDLERSFACTORY

SB_INLINE void TElDataStorageSecurityHandlersFactory::RegisterHandler(TElDataStorageSecurityHandlerClassHandle Cls)
{
	SBCheckError(TElDataStorageSecurityHandlersFactory_RegisterHandler(_Handle, Cls));
}

SB_INLINE void TElDataStorageSecurityHandlersFactory::UnregisterHandler(int32_t Index)
{
	SBCheckError(TElDataStorageSecurityHandlersFactory_UnregisterHandler(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElCustomDataStorageSecurityHandlerHandle TElDataStorageSecurityHandlersFactory::CreateInstance(const std::vector<uint8_t> &OID)
{
	TElCustomDataStorageSecurityHandlerHandle OutResult;
	SBCheckError(TElDataStorageSecurityHandlersFactory_CreateInstance(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElCustomDataStorageSecurityHandlerHandle TElDataStorageSecurityHandlersFactory::CreateInstanceFromMetadata(const std::vector<uint8_t> &SecMetadata)
{
	TElCustomDataStorageSecurityHandlerHandle OutResult;
	SBCheckError(TElDataStorageSecurityHandlersFactory_CreateInstanceFromMetadata(_Handle, SB_STD_VECTOR_FRONT_ADR(SecMetadata), (int32_t)SecMetadata.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
TElCustomDataStorageSecurityHandler* TElDataStorageSecurityHandlersFactory::get_RegisteredHandlers(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDataStorageSecurityHandlersFactory_get_RegisteredHandlers(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RegisteredHandlers)
		this->_Inst_RegisteredHandlers = new TElCustomDataStorageSecurityHandler(hOutResult, ohFalse);
	else
		this->_Inst_RegisteredHandlers->updateHandle(hOutResult);
	return this->_Inst_RegisteredHandlers;
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

SB_INLINE int32_t TElDataStorageSecurityHandlersFactory::get_RegisteredHandlerCount()
{
	int32_t OutResult;
	SBCheckError(TElDataStorageSecurityHandlersFactory_get_RegisteredHandlerCount(_Handle, &OutResult));
	return OutResult;
}

void TElDataStorageSecurityHandlersFactory::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
	this->_Inst_RegisteredHandlers = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */
}

TElDataStorageSecurityHandlersFactory::TElDataStorageSecurityHandlersFactory(TElDataStorageSecurityHandlersFactoryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElDataStorageSecurityHandlersFactory::TElDataStorageSecurityHandlersFactory() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDataStorageSecurityHandlersFactory_Create(&_Handle));
}

TElDataStorageSecurityHandlersFactory::~TElDataStorageSecurityHandlersFactory()
{
#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
	delete this->_Inst_RegisteredHandlers;
	this->_Inst_RegisteredHandlers = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */
}
#endif /* SB_USE_CLASS_TELDATASTORAGESECURITYHANDLERSFACTORY */

#ifdef SB_USE_CLASS_TELDATASTORAGEENCODINGHANDLERSFACTORY

SB_INLINE void TElDataStorageEncodingHandlersFactory::RegisterHandler(TElDataStorageEncodingHandlerClassHandle Cls)
{
	SBCheckError(TElDataStorageEncodingHandlersFactory_RegisterHandler(_Handle, Cls));
}

SB_INLINE void TElDataStorageEncodingHandlersFactory::UnregisterHandler(int32_t Index)
{
	SBCheckError(TElDataStorageEncodingHandlersFactory_UnregisterHandler(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGEENCODINGHANDLER
SB_INLINE TElCustomDataStorageEncodingHandlerHandle TElDataStorageEncodingHandlersFactory::CreateInstance(const std::vector<uint8_t> &OID)
{
	TElCustomDataStorageEncodingHandlerHandle OutResult;
	SBCheckError(TElDataStorageEncodingHandlersFactory_CreateInstance(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGEENCODINGHANDLER */

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGEENCODINGHANDLER
SB_INLINE TElCustomDataStorageEncodingHandlerHandle TElDataStorageEncodingHandlersFactory::CreateInstance(const std::vector<uint8_t> &OID, const std::vector<uint8_t> &Params)
{
	TElCustomDataStorageEncodingHandlerHandle OutResult;
	SBCheckError(TElDataStorageEncodingHandlersFactory_CreateInstance_1(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), SB_STD_VECTOR_FRONT_ADR(Params), (int32_t)Params.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGEENCODINGHANDLER */

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGEENCODINGHANDLER
TElCustomDataStorageEncodingHandler* TElDataStorageEncodingHandlersFactory::get_RegisteredHandlers(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDataStorageEncodingHandlersFactory_get_RegisteredHandlers(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RegisteredHandlers)
		this->_Inst_RegisteredHandlers = new TElCustomDataStorageEncodingHandler(hOutResult, ohFalse);
	else
		this->_Inst_RegisteredHandlers->updateHandle(hOutResult);
	return this->_Inst_RegisteredHandlers;
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGEENCODINGHANDLER */

SB_INLINE int32_t TElDataStorageEncodingHandlersFactory::get_RegisteredHandlerCount()
{
	int32_t OutResult;
	SBCheckError(TElDataStorageEncodingHandlersFactory_get_RegisteredHandlerCount(_Handle, &OutResult));
	return OutResult;
}

void TElDataStorageEncodingHandlersFactory::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGEENCODINGHANDLER
	this->_Inst_RegisteredHandlers = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGEENCODINGHANDLER */
}

TElDataStorageEncodingHandlersFactory::TElDataStorageEncodingHandlersFactory(TElDataStorageEncodingHandlersFactoryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElDataStorageEncodingHandlersFactory::TElDataStorageEncodingHandlersFactory() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDataStorageEncodingHandlersFactory_Create(&_Handle));
}

TElDataStorageEncodingHandlersFactory::~TElDataStorageEncodingHandlersFactory()
{
#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGEENCODINGHANDLER
	delete this->_Inst_RegisteredHandlers;
	this->_Inst_RegisteredHandlers = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGEENCODINGHANDLER */
}
#endif /* SB_USE_CLASS_TELDATASTORAGEENCODINGHANDLERSFACTORY */

#ifdef SB_USE_GLOBAL_PROCS_DATASTORAGE

#ifdef SB_USE_CLASS_TELDATASTORAGESECURITYHANDLERSFACTORY
SB_INLINE TElDataStorageSecurityHandlersFactoryHandle DataStorageSecurityHandlersFactory()
{
	TElDataStorageSecurityHandlersFactoryHandle OutResult;
	SBCheckError(SBDataStorage_DataStorageSecurityHandlersFactory(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDATASTORAGESECURITYHANDLERSFACTORY */

#ifdef SB_USE_CLASS_TELDATASTORAGEENCODINGHANDLERSFACTORY
SB_INLINE TElDataStorageEncodingHandlersFactoryHandle DataStorageEncodingHandlersFactory()
{
	TElDataStorageEncodingHandlersFactoryHandle OutResult;
	SBCheckError(SBDataStorage_DataStorageEncodingHandlersFactory(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDATASTORAGEENCODINGHANDLERSFACTORY */

#endif /* SB_USE_GLOBAL_PROCS_DATASTORAGE */

};	/* namespace SecureBlackbox */

