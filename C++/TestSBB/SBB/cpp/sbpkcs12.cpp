#include "sbpkcs12.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPKCS12MESSAGE

SB_INLINE int32_t TElPKCS12Message::LoadFromBuffer(void * Buffer, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElPKCS12Message_LoadFromBuffer(_Handle, Buffer, Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS12Message::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int32_t OutResult;
	SBCheckError(TElPKCS12Message_SaveToBuffer(_Handle, Buffer, &Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS12Message::get_Iterations()
{
	int32_t OutResult;
	SBCheckError(TElPKCS12Message_get_Iterations(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS12Message::set_Iterations(int32_t Value)
{
	SBCheckError(TElPKCS12Message_set_Iterations(_Handle, Value));
}

void TElPKCS12Message::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPKCS12Message_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1830180685, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS12Message::set_Password(const std::string &Value)
{
	SBCheckError(TElPKCS12Message_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
TElMemoryCertStorage* TElPKCS12Message::get_Certificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS12Message_get_Certificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElMemoryCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
TElMemoryCRLStorage* TElPKCS12Message::get_CRLs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS12Message_get_CRLs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLs)
		this->_Inst_CRLs = new TElMemoryCRLStorage(hOutResult, ohFalse);
	else
		this->_Inst_CRLs->updateHandle(hOutResult);
	return this->_Inst_CRLs;
}
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

SB_INLINE int32_t TElPKCS12Message::get_KeyEncryptionAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPKCS12Message_get_KeyEncryptionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS12Message::set_KeyEncryptionAlgorithm(int32_t Value)
{
	SBCheckError(TElPKCS12Message_set_KeyEncryptionAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElPKCS12Message::get_CertEncryptionAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPKCS12Message_get_CertEncryptionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS12Message::set_CertEncryptionAlgorithm(int32_t Value)
{
	SBCheckError(TElPKCS12Message_set_CertEncryptionAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElPKCS12Message::get_CRLEncryptionAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPKCS12Message_get_CRLEncryptionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS12Message::set_CRLEncryptionAlgorithm(int32_t Value)
{
	SBCheckError(TElPKCS12Message_set_CRLEncryptionAlgorithm(_Handle, Value));
}

bool TElPKCS12Message::get_UseEmptyPasswordWorkaround()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS12Message_get_UseEmptyPasswordWorkaround(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS12Message::set_UseEmptyPasswordWorkaround(bool Value)
{
	SBCheckError(TElPKCS12Message_set_UseEmptyPasswordWorkaround(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElPKCS12Message::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS12Message_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElPKCS12Message::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElPKCS12Message_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElPKCS12Message::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElPKCS12Message_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

void TElPKCS12Message::initInstances()
{
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
	this->_Inst_CRLs = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}

TElPKCS12Message::TElPKCS12Message(TElPKCS12MessageHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS12Message::TElPKCS12Message() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS12Message_Create(&_Handle));
}

TElPKCS12Message::~TElPKCS12Message()
{
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
	delete this->_Inst_CRLs;
	this->_Inst_CRLs = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}
#endif /* SB_USE_CLASS_TELPKCS12MESSAGE */

#ifdef SB_USE_GLOBAL_PROCS_PKCS12

SB_INLINE int32_t BufToInt(void * Buffer, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(SBPKCS12_BufToInt(Buffer, Size, &OutResult));
	return OutResult;
}

void IntToBuf(int32_t Number, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBPKCS12_IntToBuf(Number, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1000526241, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void RaisePKCS12Error(int32_t ErrorCode)
{
	SBCheckError(SBPKCS12_RaisePKCS12Error(ErrorCode));
}

#endif /* SB_USE_GLOBAL_PROCS_PKCS12 */

};	/* namespace SecureBlackbox */

