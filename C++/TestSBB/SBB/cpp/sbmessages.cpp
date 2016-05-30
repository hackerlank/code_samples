#include "sbmessages.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELMESSAGEPROCESSOR

void TElMessageProcessor::get_ErrorInfo(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessageProcessor_get_ErrorInfo(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(66943194, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElMessageProcessor::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageProcessor_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElMessageProcessor::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElMessageProcessor_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessageProcessor::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElMessageProcessor_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

bool TElMessageProcessor::get_AlignEncryptedKey()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageProcessor_get_AlignEncryptedKey(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessageProcessor::set_AlignEncryptedKey(bool Value)
{
	SBCheckError(TElMessageProcessor_set_AlignEncryptedKey(_Handle, (int8_t)Value));
}

SB_INLINE void TElMessageProcessor::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElMessageProcessor_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElMessageProcessor::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElMessageProcessor_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

void TElMessageProcessor::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}

TElMessageProcessor::TElMessageProcessor(TElMessageProcessorHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElMessageProcessor::TElMessageProcessor(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessageProcessor_Create(AOwner.getHandle(), &_Handle));
}

TElMessageProcessor::TElMessageProcessor(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessageProcessor_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElMessageProcessor::~TElMessageProcessor()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}
#endif /* SB_USE_CLASS_TELMESSAGEPROCESSOR */

#ifdef SB_USE_CLASS_TELMESSAGEENCRYPTOR

SB_INLINE int32_t TElMessageEncryptor::Encrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	int32_t OutResult;
	SBCheckError(TElMessageEncryptor_Encrypt(_Handle, InBuffer, InSize, OutBuffer, &OutSize, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageEncryptor::Encrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, void * Key, int32_t KeySize)
{
	int32_t OutResult;
	SBCheckError(TElMessageEncryptor_Encrypt_1(_Handle, InBuffer, InSize, OutBuffer, &OutSize, Key, KeySize, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMessageEncryptor::Encrypt(TStream &InStream, TStream &OutStream, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageEncryptor_Encrypt_2(_Handle, InStream.getHandle(), OutStream.getHandle(), InCount, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageEncryptor::Encrypt(TStream *InStream, TStream *OutStream, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageEncryptor_Encrypt_2(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, InCount, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMessageEncryptor::Encrypt(TStream &InStream, TStream &OutStream, void * Key, int32_t KeySize, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageEncryptor_Encrypt_3(_Handle, InStream.getHandle(), OutStream.getHandle(), Key, KeySize, InCount, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageEncryptor::Encrypt(TStream *InStream, TStream *OutStream, void * Key, int32_t KeySize, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageEncryptor_Encrypt_3(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, Key, KeySize, InCount, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElMessageEncryptor::get_GOSTParamSet(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElMessageEncryptor_get_GOSTParamSet(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1294885631, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElMessageEncryptor::set_GOSTParamSet(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElMessageEncryptor_set_GOSTParamSet(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElMessageEncryptor::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageEncryptor_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElMessageEncryptor::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElMessageEncryptor_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessageEncryptor::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElMessageEncryptor_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

SB_INLINE int32_t TElMessageEncryptor::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElMessageEncryptor_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMessageEncryptor::set_Algorithm(int32_t Value)
{
	SBCheckError(TElMessageEncryptor_set_Algorithm(_Handle, Value));
}

SB_INLINE int32_t TElMessageEncryptor::get_BitsInKey()
{
	int32_t OutResult;
	SBCheckError(TElMessageEncryptor_get_BitsInKey(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMessageEncryptor::set_BitsInKey(int32_t Value)
{
	SBCheckError(TElMessageEncryptor_set_BitsInKey(_Handle, Value));
}

bool TElMessageEncryptor::get_UseUndefSize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageEncryptor_get_UseUndefSize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessageEncryptor::set_UseUndefSize(bool Value)
{
	SBCheckError(TElMessageEncryptor_set_UseUndefSize(_Handle, (int8_t)Value));
}

bool TElMessageEncryptor::get_UseOAEP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageEncryptor_get_UseOAEP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessageEncryptor::set_UseOAEP(bool Value)
{
	SBCheckError(TElMessageEncryptor_set_UseOAEP(_Handle, (int8_t)Value));
}

TSBEncryptionOptions TElMessageEncryptor::get_EncryptionOptions()
{
	TSBEncryptionOptionsRaw OutResultRaw = 0;
	SBCheckError(TElMessageEncryptor_get_EncryptionOptions(_Handle, &OutResultRaw));
	return (TSBEncryptionOptions)OutResultRaw;
}

SB_INLINE void TElMessageEncryptor::set_EncryptionOptions(TSBEncryptionOptions Value)
{
	SBCheckError(TElMessageEncryptor_set_EncryptionOptions(_Handle, (TSBEncryptionOptionsRaw)Value));
}

bool TElMessageEncryptor::get_UseImplicitContentEncoding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageEncryptor_get_UseImplicitContentEncoding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessageEncryptor::set_UseImplicitContentEncoding(bool Value)
{
	SBCheckError(TElMessageEncryptor_set_UseImplicitContentEncoding(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElMessageEncryptor::get_OriginatorCertificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageEncryptor_get_OriginatorCertificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OriginatorCertificates)
		this->_Inst_OriginatorCertificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_OriginatorCertificates->updateHandle(hOutResult);
	return this->_Inst_OriginatorCertificates;
}

SB_INLINE void TElMessageEncryptor::set_OriginatorCertificates(TElCustomCertStorage &Value)
{
	SBCheckError(TElMessageEncryptor_set_OriginatorCertificates(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessageEncryptor::set_OriginatorCertificates(TElCustomCertStorage *Value)
{
	SBCheckError(TElMessageEncryptor_set_OriginatorCertificates(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRLSTORAGE
TElCustomCRLStorage* TElMessageEncryptor::get_OriginatorCRLs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageEncryptor_get_OriginatorCRLs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OriginatorCRLs)
		this->_Inst_OriginatorCRLs = new TElCustomCRLStorage(hOutResult, ohFalse);
	else
		this->_Inst_OriginatorCRLs->updateHandle(hOutResult);
	return this->_Inst_OriginatorCRLs;
}

SB_INLINE void TElMessageEncryptor::set_OriginatorCRLs(TElCustomCRLStorage &Value)
{
	SBCheckError(TElMessageEncryptor_set_OriginatorCRLs(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessageEncryptor::set_OriginatorCRLs(TElCustomCRLStorage *Value)
{
	SBCheckError(TElMessageEncryptor_set_OriginatorCRLs(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRLSTORAGE */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
TElPKCS7Attributes* TElMessageEncryptor::get_UnprotectedAttributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageEncryptor_get_UnprotectedAttributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_UnprotectedAttributes)
		this->_Inst_UnprotectedAttributes = new TElPKCS7Attributes(hOutResult, ohFalse);
	else
		this->_Inst_UnprotectedAttributes->updateHandle(hOutResult);
	return this->_Inst_UnprotectedAttributes;
}
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

void TElMessageEncryptor::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_OriginatorCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRLSTORAGE
	this->_Inst_OriginatorCRLs = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRLSTORAGE */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	this->_Inst_UnprotectedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
}

TElMessageEncryptor::TElMessageEncryptor(TElMessageEncryptorHandle handle, TElOwnHandle ownHandle) : TElMessageProcessor(handle, ownHandle)
{
	initInstances();
}

TElMessageEncryptor::TElMessageEncryptor(TComponent &AOwner) : TElMessageProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessageEncryptor_Create(AOwner.getHandle(), &_Handle));
}

TElMessageEncryptor::TElMessageEncryptor(TComponent *AOwner) : TElMessageProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessageEncryptor_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElMessageEncryptor::~TElMessageEncryptor()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_OriginatorCertificates;
	this->_Inst_OriginatorCertificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRLSTORAGE
	delete this->_Inst_OriginatorCRLs;
	this->_Inst_OriginatorCRLs = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRLSTORAGE */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	delete this->_Inst_UnprotectedAttributes;
	this->_Inst_UnprotectedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
}
#endif /* SB_USE_CLASS_TELMESSAGEENCRYPTOR */

#ifdef SB_USE_CLASS_TELMESSAGEDECRYPTOR

SB_INLINE int32_t TElMessageDecryptor::Decrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	int32_t OutResult;
	SBCheckError(TElMessageDecryptor_Decrypt(_Handle, InBuffer, InSize, OutBuffer, &OutSize, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageDecryptor::Decrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, void * Key, int32_t KeySize)
{
	int32_t OutResult;
	SBCheckError(TElMessageDecryptor_Decrypt_1(_Handle, InBuffer, InSize, OutBuffer, &OutSize, Key, KeySize, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMessageDecryptor::Decrypt(TStream &InStream, TStream &OutStream, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageDecryptor_Decrypt_2(_Handle, InStream.getHandle(), OutStream.getHandle(), InCount, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageDecryptor::Decrypt(TStream *InStream, TStream *OutStream, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageDecryptor_Decrypt_2(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, InCount, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMessageDecryptor::Decrypt(TStream &InStream, TStream &OutStream, void * Key, int32_t KeySize, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageDecryptor_Decrypt_3(_Handle, InStream.getHandle(), OutStream.getHandle(), Key, KeySize, InCount, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageDecryptor::Decrypt(TStream *InStream, TStream *OutStream, void * Key, int32_t KeySize, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageDecryptor_Decrypt_3(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, Key, KeySize, InCount, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElMessageDecryptor::IsConventionallyEncrypted(void * Buffer, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageDecryptor_IsConventionallyEncrypted(Buffer, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMessageDecryptor::IsConventionallyEncrypted_Inst(void * Buffer, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageDecryptor_IsConventionallyEncrypted_1(_Handle, Buffer, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElMessageDecryptor::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElMessageDecryptor_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageDecryptor::get_BitsInKey()
{
	int32_t OutResult;
	SBCheckError(TElMessageDecryptor_get_BitsInKey(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS7ISSUER
TElPKCS7Issuer* TElMessageDecryptor::get_CertIDs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageDecryptor_get_CertIDs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertIDs)
		this->_Inst_CertIDs = new TElPKCS7Issuer(hOutResult, ohFalse);
	else
		this->_Inst_CertIDs->updateHandle(hOutResult);
	return this->_Inst_CertIDs;
}
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

SB_INLINE int32_t TElMessageDecryptor::get_CertIDCount()
{
	int32_t OutResult;
	SBCheckError(TElMessageDecryptor_get_CertIDCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageDecryptor::get_UsedCertificate()
{
	int32_t OutResult;
	SBCheckError(TElMessageDecryptor_get_UsedCertificate(_Handle, &OutResult));
	return OutResult;
}

bool TElMessageDecryptor::get_UseOAEP()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageDecryptor_get_UseOAEP(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
TElMemoryCertStorage* TElMessageDecryptor::get_OriginatorCertificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageDecryptor_get_OriginatorCertificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OriginatorCertificates)
		this->_Inst_OriginatorCertificates = new TElMemoryCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_OriginatorCertificates->updateHandle(hOutResult);
	return this->_Inst_OriginatorCertificates;
}
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
TElMemoryCRLStorage* TElMessageDecryptor::get_OriginatorCRLs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageDecryptor_get_OriginatorCRLs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OriginatorCRLs)
		this->_Inst_OriginatorCRLs = new TElMemoryCRLStorage(hOutResult, ohFalse);
	else
		this->_Inst_OriginatorCRLs->updateHandle(hOutResult);
	return this->_Inst_OriginatorCRLs;
}
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
TElPKCS7Attributes* TElMessageDecryptor::get_UnprotectedAttributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageDecryptor_get_UnprotectedAttributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_UnprotectedAttributes)
		this->_Inst_UnprotectedAttributes = new TElPKCS7Attributes(hOutResult, ohFalse);
	else
		this->_Inst_UnprotectedAttributes->updateHandle(hOutResult);
	return this->_Inst_UnprotectedAttributes;
}
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElMessageDecryptor::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageDecryptor_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElMessageDecryptor::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElMessageDecryptor_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessageDecryptor::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElMessageDecryptor_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

TSBDecryptionOptions TElMessageDecryptor::get_DecryptionOptions()
{
	TSBDecryptionOptionsRaw OutResultRaw = 0;
	SBCheckError(TElMessageDecryptor_get_DecryptionOptions(_Handle, &OutResultRaw));
	return (TSBDecryptionOptions)OutResultRaw;
}

SB_INLINE void TElMessageDecryptor::set_DecryptionOptions(TSBDecryptionOptions Value)
{
	SBCheckError(TElMessageDecryptor_set_DecryptionOptions(_Handle, (TSBDecryptionOptionsRaw)Value));
}

SB_INLINE void TElMessageDecryptor::get_OnCertIDs(TSBCertIDsEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElMessageDecryptor_get_OnCertIDs(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElMessageDecryptor::set_OnCertIDs(TSBCertIDsEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElMessageDecryptor_set_OnCertIDs(_Handle, pMethodValue, pDataValue));
}

void TElMessageDecryptor::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
	this->_Inst_CertIDs = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	this->_Inst_OriginatorCertificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
	this->_Inst_OriginatorCRLs = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	this->_Inst_UnprotectedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElMessageDecryptor::TElMessageDecryptor(TElMessageDecryptorHandle handle, TElOwnHandle ownHandle) : TElMessageProcessor(handle, ownHandle)
{
	initInstances();
}

TElMessageDecryptor::TElMessageDecryptor(TComponent &AOwner) : TElMessageProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessageDecryptor_Create(AOwner.getHandle(), &_Handle));
}

TElMessageDecryptor::TElMessageDecryptor(TComponent *AOwner) : TElMessageProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessageDecryptor_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElMessageDecryptor::~TElMessageDecryptor()
{
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
	delete this->_Inst_CertIDs;
	this->_Inst_CertIDs = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	delete this->_Inst_OriginatorCertificates;
	this->_Inst_OriginatorCertificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
	delete this->_Inst_OriginatorCRLs;
	this->_Inst_OriginatorCRLs = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	delete this->_Inst_UnprotectedAttributes;
	this->_Inst_UnprotectedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELMESSAGEDECRYPTOR */

#ifdef SB_USE_CLASS_TELMESSAGEVERIFIER

SB_INLINE int32_t TElMessageVerifier::Verify(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	int32_t OutResult;
	SBCheckError(TElMessageVerifier_Verify(_Handle, InBuffer, InSize, OutBuffer, &OutSize, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMessageVerifier::Verify(TStream &InStream, TStream &OutStream, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageVerifier_Verify_1(_Handle, InStream.getHandle(), OutStream.getHandle(), InCount, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageVerifier::Verify(TStream *InStream, TStream *OutStream, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageVerifier_Verify_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, InCount, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElMessageVerifier::VerifyDetached(void * Buffer, int32_t Size, void * Signature, int32_t SignatureSize)
{
	int32_t OutResult;
	SBCheckError(TElMessageVerifier_VerifyDetached(_Handle, Buffer, Size, Signature, SignatureSize, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMessageVerifier::VerifyDetached(TStream &InStream, TStream &SigStream, int64_t InCount, int64_t SigCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageVerifier_VerifyDetached_1(_Handle, InStream.getHandle(), SigStream.getHandle(), InCount, SigCount, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageVerifier::VerifyDetached(TStream *InStream, TStream *SigStream, int64_t InCount, int64_t SigCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageVerifier_VerifyDetached_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (SigStream != NULL) ? SigStream->getHandle() : SB_NULL_HANDLE, InCount, SigCount, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElMessageVerifier::IsSignatureDetached(void * Signature, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageVerifier_IsSignatureDetached(Signature, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMessageVerifier::IsSignatureDetached_Inst(void * Signature, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageVerifier_IsSignatureDetached_1(_Handle, Signature, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
bool TElMessageVerifier::IsSignatureDetached(TStream &Signature, int64_t Count)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageVerifier_IsSignatureDetached_2(Signature.getHandle(), Count, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMessageVerifier::IsSignatureDetached(TStream *Signature, int64_t Count)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageVerifier_IsSignatureDetached_2((Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, Count, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
bool TElMessageVerifier::IsSignatureDetached_Inst(TStream &Signature, int64_t Count)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageVerifier_IsSignatureDetached_3(_Handle, Signature.getHandle(), Count, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMessageVerifier::IsSignatureDetached_Inst(TStream *Signature, int64_t Count)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageVerifier_IsSignatureDetached_3(_Handle, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, Count, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
TElMemoryCertStorage* TElMessageVerifier::get_Certificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageVerifier_get_Certificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElMemoryCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
TElPKCS7Attributes* TElMessageVerifier::get_Attributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageVerifier_get_Attributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Attributes)
		this->_Inst_Attributes = new TElPKCS7Attributes(hOutResult, ohFalse);
	else
		this->_Inst_Attributes->updateHandle(hOutResult);
	return this->_Inst_Attributes;
}
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

SB_INLINE int32_t TElMessageVerifier::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElMessageVerifier_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageVerifier::get_MacAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElMessageVerifier_get_MacAlgorithm(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS7ISSUER
TElPKCS7Issuer* TElMessageVerifier::get_CertIDs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageVerifier_get_CertIDs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertIDs)
		this->_Inst_CertIDs = new TElPKCS7Issuer(hOutResult, ohFalse);
	else
		this->_Inst_CertIDs->updateHandle(hOutResult);
	return this->_Inst_CertIDs;
}
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

#ifdef SB_USE_CLASS_TELPKCS7ISSUER
TElPKCS7Issuer* TElMessageVerifier::get_CountersignatureCertIDs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageVerifier_get_CountersignatureCertIDs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CountersignatureCertIDs)
		this->_Inst_CountersignatureCertIDs = new TElPKCS7Issuer(hOutResult, ohFalse);
	else
		this->_Inst_CountersignatureCertIDs->updateHandle(hOutResult);
	return this->_Inst_CountersignatureCertIDs;
}
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

SB_INLINE int32_t TElMessageVerifier::get_CountersignatureVerificationResults(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TElMessageVerifier_get_CountersignatureVerificationResults(_Handle, Index, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
TElPKCS7Attributes* TElMessageVerifier::get_CountersignatureAttributes(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageVerifier_get_CountersignatureAttributes(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CountersignatureAttributes)
		this->_Inst_CountersignatureAttributes = new TElPKCS7Attributes(hOutResult, ohFalse);
	else
		this->_Inst_CountersignatureAttributes->updateHandle(hOutResult);
	return this->_Inst_CountersignatureAttributes;
}
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

SB_INLINE int32_t TElMessageVerifier::get_CertIDCount()
{
	int32_t OutResult;
	SBCheckError(TElMessageVerifier_get_CertIDCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageVerifier::get_CountersignatureCertIDCount()
{
	int32_t OutResult;
	SBCheckError(TElMessageVerifier_get_CountersignatureCertIDCount(_Handle, &OutResult));
	return OutResult;
}

TSBMessageSignatureType TElMessageVerifier::get_SignatureType()
{
	TSBMessageSignatureTypeRaw OutResultRaw = 0;
	SBCheckError(TElMessageVerifier_get_SignatureType(_Handle, &OutResultRaw));
	return (TSBMessageSignatureType)OutResultRaw;
}

bool TElMessageVerifier::get_UsePSS()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageVerifier_get_UsePSS(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElMessageVerifier::get_InputIsDigest()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageVerifier_get_InputIsDigest(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessageVerifier::set_InputIsDigest(bool Value)
{
	SBCheckError(TElMessageVerifier_set_InputIsDigest(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
TElClientTSPInfo* TElMessageVerifier::get_Timestamps(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageVerifier_get_Timestamps(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Timestamps)
		this->_Inst_Timestamps = new TElClientTSPInfo(hOutResult, ohFalse);
	else
		this->_Inst_Timestamps->updateHandle(hOutResult);
	return this->_Inst_Timestamps;
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

SB_INLINE int32_t TElMessageVerifier::get_TimestampCount()
{
	int32_t OutResult;
	SBCheckError(TElMessageVerifier_get_TimestampCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElMessageVerifier::get_SigningTime()
{
	int64_t OutResult;
	SBCheckError(TElMessageVerifier_get_SigningTime(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElMessageVerifier::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageVerifier_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElMessageVerifier::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElMessageVerifier_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessageVerifier::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElMessageVerifier_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

bool TElMessageVerifier::get_VerifyCountersignatures()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageVerifier_get_VerifyCountersignatures(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessageVerifier::set_VerifyCountersignatures(bool Value)
{
	SBCheckError(TElMessageVerifier_set_VerifyCountersignatures(_Handle, (int8_t)Value));
}

TSBVerificationOptions TElMessageVerifier::get_VerificationOptions()
{
	TSBVerificationOptionsRaw OutResultRaw = 0;
	SBCheckError(TElMessageVerifier_get_VerificationOptions(_Handle, &OutResultRaw));
	return (TSBVerificationOptions)OutResultRaw;
}

SB_INLINE void TElMessageVerifier::set_VerificationOptions(TSBVerificationOptions Value)
{
	SBCheckError(TElMessageVerifier_set_VerificationOptions(_Handle, (TSBVerificationOptionsRaw)Value));
}

SB_INLINE void TElMessageVerifier::get_OnCertIDs(TSBCertIDsEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElMessageVerifier_get_OnCertIDs(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElMessageVerifier::set_OnCertIDs(TSBCertIDsEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElMessageVerifier_set_OnCertIDs(_Handle, pMethodValue, pDataValue));
}

void TElMessageVerifier::initInstances()
{
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
	this->_Inst_CertIDs = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
	this->_Inst_CountersignatureCertIDs = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	this->_Inst_CountersignatureAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	this->_Inst_Timestamps = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElMessageVerifier::TElMessageVerifier(TElMessageVerifierHandle handle, TElOwnHandle ownHandle) : TElMessageProcessor(handle, ownHandle)
{
	initInstances();
}

TElMessageVerifier::TElMessageVerifier(TComponent &AOwner) : TElMessageProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessageVerifier_Create(AOwner.getHandle(), &_Handle));
}

TElMessageVerifier::TElMessageVerifier(TComponent *AOwner) : TElMessageProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessageVerifier_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElMessageVerifier::~TElMessageVerifier()
{
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	delete this->_Inst_Attributes;
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
	delete this->_Inst_CertIDs;
	this->_Inst_CertIDs = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
	delete this->_Inst_CountersignatureCertIDs;
	this->_Inst_CountersignatureCertIDs = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	delete this->_Inst_CountersignatureAttributes;
	this->_Inst_CountersignatureAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	delete this->_Inst_Timestamps;
	this->_Inst_Timestamps = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELMESSAGEVERIFIER */

#ifdef SB_USE_CLASS_TELMESSAGESIGNER

SB_INLINE int32_t TElMessageSigner::Sign(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, bool Detached)
{
	int32_t OutResult;
	SBCheckError(TElMessageSigner_Sign(_Handle, InBuffer, InSize, OutBuffer, &OutSize, (int8_t)Detached, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMessageSigner::Sign(TStream &InStream, TStream &OutStream, bool Detached, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageSigner_Sign_1(_Handle, InStream.getHandle(), OutStream.getHandle(), (int8_t)Detached, InCount, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageSigner::Sign(TStream *InStream, TStream *OutStream, bool Detached, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageSigner_Sign_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, (int8_t)Detached, InCount, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
int32_t TElMessageSigner::InitiateAsyncSign(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, bool Detached, TElDCAsyncState &State)
{
	int32_t OutResult;
	TElClassHandle hState = State.getHandle();
	SBCheckError(TElMessageSigner_InitiateAsyncSign(_Handle, InBuffer, InSize, OutBuffer, &OutSize, (int8_t)Detached, &hState, &OutResult));
	State.updateHandle(hState);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
int32_t TElMessageSigner::InitiateAsyncSign(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, bool Detached, TSBDCAsyncSignMethod AsyncSignMethod, TElDCAsyncState &State)
{
	int32_t OutResult;
	TElClassHandle hState = State.getHandle();
	SBCheckError(TElMessageSigner_InitiateAsyncSign_1(_Handle, InBuffer, InSize, OutBuffer, &OutSize, (int8_t)Detached, (TSBDCAsyncSignMethodRaw)AsyncSignMethod, &hState, &OutResult));
	State.updateHandle(hState);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TSTREAM
int32_t TElMessageSigner::InitiateAsyncSign(TStream &InStream, TStream &OutStream, bool Detached, TElDCAsyncState &State, int64_t InCount)
{
	int32_t OutResult;
	TElClassHandle hState = State.getHandle();
	SBCheckError(TElMessageSigner_InitiateAsyncSign_2(_Handle, InStream.getHandle(), OutStream.getHandle(), (int8_t)Detached, &hState, InCount, &OutResult));
	State.updateHandle(hState);
	return OutResult;
}

int32_t TElMessageSigner::InitiateAsyncSign(TStream *InStream, TStream *OutStream, bool Detached, TElDCAsyncState &State, int64_t InCount)
{
	int32_t OutResult;
	TElClassHandle hState = State.getHandle();
	SBCheckError(TElMessageSigner_InitiateAsyncSign_2(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, (int8_t)Detached, &hState, InCount, &OutResult));
	State.updateHandle(hState);
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TSTREAM
int32_t TElMessageSigner::InitiateAsyncSign(TStream &InStream, TStream &OutStream, bool Detached, TSBDCAsyncSignMethod AsyncSignMethod, TElDCAsyncState &State, int64_t InCount)
{
	int32_t OutResult;
	TElClassHandle hState = State.getHandle();
	SBCheckError(TElMessageSigner_InitiateAsyncSign_3(_Handle, InStream.getHandle(), OutStream.getHandle(), (int8_t)Detached, (TSBDCAsyncSignMethodRaw)AsyncSignMethod, &hState, InCount, &OutResult));
	State.updateHandle(hState);
	return OutResult;
}

int32_t TElMessageSigner::InitiateAsyncSign(TStream *InStream, TStream *OutStream, bool Detached, TSBDCAsyncSignMethod AsyncSignMethod, TElDCAsyncState &State, int64_t InCount)
{
	int32_t OutResult;
	TElClassHandle hState = State.getHandle();
	SBCheckError(TElMessageSigner_InitiateAsyncSign_3(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, (int8_t)Detached, (TSBDCAsyncSignMethodRaw)AsyncSignMethod, &hState, InCount, &OutResult));
	State.updateHandle(hState);
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
SB_INLINE int32_t TElMessageSigner::CompleteAsyncSign(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElDCAsyncState &AsyncState)
{
	int32_t OutResult;
	SBCheckError(TElMessageSigner_CompleteAsyncSign(_Handle, InBuffer, InSize, OutBuffer, &OutSize, AsyncState.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageSigner::CompleteAsyncSign(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElDCAsyncState *AsyncState)
{
	int32_t OutResult;
	SBCheckError(TElMessageSigner_CompleteAsyncSign(_Handle, InBuffer, InSize, OutBuffer, &OutSize, (AsyncState != NULL) ? AsyncState->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TSTREAM
SB_INLINE int32_t TElMessageSigner::CompleteAsyncSign(TStream &InStream, TStream &OutStream, TElDCAsyncState &AsyncState, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageSigner_CompleteAsyncSign_1(_Handle, InStream.getHandle(), OutStream.getHandle(), AsyncState.getHandle(), InCount, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageSigner::CompleteAsyncSign(TStream *InStream, TStream *OutStream, TElDCAsyncState *AsyncState, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageSigner_CompleteAsyncSign_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, (AsyncState != NULL) ? AsyncState->getHandle() : SB_NULL_HANDLE, InCount, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TSTREAM */

SB_INLINE int32_t TElMessageSigner::Countersign(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	int32_t OutResult;
	SBCheckError(TElMessageSigner_Countersign(_Handle, InBuffer, InSize, OutBuffer, &OutSize, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMessageSigner::Countersign(TStream &InStream, TStream &OutStream, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageSigner_Countersign_1(_Handle, InStream.getHandle(), OutStream.getHandle(), InCount, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageSigner::Countersign(TStream *InStream, TStream *OutStream, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageSigner_Countersign_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, InCount, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElMessageSigner::Timestamp(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	int32_t OutResult;
	SBCheckError(TElMessageSigner_Timestamp(_Handle, InBuffer, InSize, OutBuffer, &OutSize, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMessageSigner::Timestamp(TStream &InStream, TStream &OutStream, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageSigner_Timestamp_1(_Handle, InStream.getHandle(), OutStream.getHandle(), InCount, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageSigner::Timestamp(TStream *InStream, TStream *OutStream, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageSigner_Timestamp_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, InCount, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElMessageSigner::TimestampCountersignature(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, int32_t SigIndex)
{
	int32_t OutResult;
	SBCheckError(TElMessageSigner_TimestampCountersignature(_Handle, InBuffer, InSize, OutBuffer, &OutSize, SigIndex, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMessageSigner::TimestampCountersignature(TStream &InStream, TStream &OutStream, int32_t SigIndex, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageSigner_TimestampCountersignature_1(_Handle, InStream.getHandle(), OutStream.getHandle(), SigIndex, InCount, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageSigner::TimestampCountersignature(TStream *InStream, TStream *OutStream, int32_t SigIndex, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageSigner_TimestampCountersignature_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, SigIndex, InCount, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
TElPKCS7Attributes* TElMessageSigner::get_AuthenticatedAttributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageSigner_get_AuthenticatedAttributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AuthenticatedAttributes)
		this->_Inst_AuthenticatedAttributes = new TElPKCS7Attributes(hOutResult, ohFalse);
	else
		this->_Inst_AuthenticatedAttributes->updateHandle(hOutResult);
	return this->_Inst_AuthenticatedAttributes;
}
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
TElPKCS7Attributes* TElMessageSigner::get_UnauthenticatedAttributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageSigner_get_UnauthenticatedAttributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_UnauthenticatedAttributes)
		this->_Inst_UnauthenticatedAttributes = new TElPKCS7Attributes(hOutResult, ohFalse);
	else
		this->_Inst_UnauthenticatedAttributes->updateHandle(hOutResult);
	return this->_Inst_UnauthenticatedAttributes;
}
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

SB_INLINE int32_t TElMessageSigner::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElMessageSigner_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMessageSigner::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElMessageSigner_set_HashAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElMessageSigner::get_MacAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElMessageSigner_get_MacAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMessageSigner::set_MacAlgorithm(int32_t Value)
{
	SBCheckError(TElMessageSigner_set_MacAlgorithm(_Handle, Value));
}

void TElMessageSigner::get_ContentType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElMessageSigner_get_ContentType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1966822532, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElMessageSigner::set_ContentType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElMessageSigner_set_ContentType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElMessageSigner::get_DataHash(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElMessageSigner_get_DataHash(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(216493652, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElMessageSigner::get_DigestEncryptionAlgorithm(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElMessageSigner_get_DigestEncryptionAlgorithm(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1542524589, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElMessageSigner::set_DigestEncryptionAlgorithm(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElMessageSigner_set_DigestEncryptionAlgorithm(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int64_t TElMessageSigner::get_SigningTime()
{
	int64_t OutResult;
	SBCheckError(TElMessageSigner_get_SigningTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMessageSigner::set_SigningTime(int64_t Value)
{
	SBCheckError(TElMessageSigner_set_SigningTime(_Handle, Value));
}

TSBMessageSignatureType TElMessageSigner::get_SignatureType()
{
	TSBMessageSignatureTypeRaw OutResultRaw = 0;
	SBCheckError(TElMessageSigner_get_SignatureType(_Handle, &OutResultRaw));
	return (TSBMessageSignatureType)OutResultRaw;
}

SB_INLINE void TElMessageSigner::set_SignatureType(TSBMessageSignatureType Value)
{
	SBCheckError(TElMessageSigner_set_SignatureType(_Handle, (TSBMessageSignatureTypeRaw)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElMessageSigner::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageSigner_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElMessageSigner::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElMessageSigner_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessageSigner::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElMessageSigner_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

bool TElMessageSigner::get_IncludeCertificates()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageSigner_get_IncludeCertificates(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessageSigner::set_IncludeCertificates(bool Value)
{
	SBCheckError(TElMessageSigner_set_IncludeCertificates(_Handle, (int8_t)Value));
}

bool TElMessageSigner::get_IncludeChain()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageSigner_get_IncludeChain(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessageSigner::set_IncludeChain(bool Value)
{
	SBCheckError(TElMessageSigner_set_IncludeChain(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElMessageSigner::get_RecipientCerts()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageSigner_get_RecipientCerts(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RecipientCerts)
		this->_Inst_RecipientCerts = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_RecipientCerts->updateHandle(hOutResult);
	return this->_Inst_RecipientCerts;
}

SB_INLINE void TElMessageSigner::set_RecipientCerts(TElCustomCertStorage &Value)
{
	SBCheckError(TElMessageSigner_set_RecipientCerts(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessageSigner::set_RecipientCerts(TElCustomCertStorage *Value)
{
	SBCheckError(TElMessageSigner_set_RecipientCerts(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

bool TElMessageSigner::get_UseUndefSize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageSigner_get_UseUndefSize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessageSigner::set_UseUndefSize(bool Value)
{
	SBCheckError(TElMessageSigner_set_UseUndefSize(_Handle, (int8_t)Value));
}

bool TElMessageSigner::get_UsePSS()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageSigner_get_UsePSS(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessageSigner::set_UsePSS(bool Value)
{
	SBCheckError(TElMessageSigner_set_UsePSS(_Handle, (int8_t)Value));
}

TSBSigningOptions TElMessageSigner::get_SigningOptions()
{
	TSBSigningOptionsRaw OutResultRaw = 0;
	SBCheckError(TElMessageSigner_get_SigningOptions(_Handle, &OutResultRaw));
	return (TSBSigningOptions)OutResultRaw;
}

SB_INLINE void TElMessageSigner::set_SigningOptions(TSBSigningOptions Value)
{
	SBCheckError(TElMessageSigner_set_SigningOptions(_Handle, (TSBSigningOptionsRaw)Value));
}

SB_INLINE int32_t TElMessageSigner::get_ExtraSpace()
{
	int32_t OutResult;
	SBCheckError(TElMessageSigner_get_ExtraSpace(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMessageSigner::set_ExtraSpace(int32_t Value)
{
	SBCheckError(TElMessageSigner_set_ExtraSpace(_Handle, Value));
}

bool TElMessageSigner::get_InputIsHash()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageSigner_get_InputIsHash(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessageSigner::set_InputIsHash(bool Value)
{
	SBCheckError(TElMessageSigner_set_InputIsHash(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
TElCustomTSPClient* TElMessageSigner::get_TSPClient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageSigner_get_TSPClient(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TSPClient)
		this->_Inst_TSPClient = new TElCustomTSPClient(hOutResult, ohFalse);
	else
		this->_Inst_TSPClient->updateHandle(hOutResult);
	return this->_Inst_TSPClient;
}

SB_INLINE void TElMessageSigner::set_TSPClient(TElCustomTSPClient &Value)
{
	SBCheckError(TElMessageSigner_set_TSPClient(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessageSigner::set_TSPClient(TElCustomTSPClient *Value)
{
	SBCheckError(TElMessageSigner_set_TSPClient(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

void TElMessageSigner::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	this->_Inst_AuthenticatedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	this->_Inst_UnauthenticatedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_RecipientCerts = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
	this->_Inst_TSPClient = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */
}

TElMessageSigner::TElMessageSigner(TElMessageSignerHandle handle, TElOwnHandle ownHandle) : TElMessageProcessor(handle, ownHandle)
{
	initInstances();
}

TElMessageSigner::TElMessageSigner(TComponent &AOwner) : TElMessageProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessageSigner_Create(AOwner.getHandle(), &_Handle));
}

TElMessageSigner::TElMessageSigner(TComponent *AOwner) : TElMessageProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessageSigner_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElMessageSigner::~TElMessageSigner()
{
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	delete this->_Inst_AuthenticatedAttributes;
	this->_Inst_AuthenticatedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	delete this->_Inst_UnauthenticatedAttributes;
	this->_Inst_UnauthenticatedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_RecipientCerts;
	this->_Inst_RecipientCerts = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
	delete this->_Inst_TSPClient;
	this->_Inst_TSPClient = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */
}
#endif /* SB_USE_CLASS_TELMESSAGESIGNER */

#ifdef SB_USE_CLASS_TELMESSAGEDECOMPRESSOR

SB_INLINE int32_t TElMessageDecompressor::Decompress(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	int32_t OutResult;
	SBCheckError(TElMessageDecompressor_Decompress(_Handle, InBuffer, InSize, OutBuffer, &OutSize, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMessageDecompressor::Decompress(TStream &InStream, TStream &OutStream, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageDecompressor_Decompress_1(_Handle, InStream.getHandle(), OutStream.getHandle(), InCount, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageDecompressor::Decompress(TStream *InStream, TStream *OutStream, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageDecompressor_Decompress_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, InCount, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElMessageDecompressor::get_ContentType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElMessageDecompressor_get_ContentType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-434653365, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElMessageDecompressor::TElMessageDecompressor(TElMessageDecompressorHandle handle, TElOwnHandle ownHandle) : TElMessageProcessor(handle, ownHandle)
{
}

TElMessageDecompressor::TElMessageDecompressor(TComponent &AOwner) : TElMessageProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMessageDecompressor_Create(AOwner.getHandle(), &_Handle));
}

TElMessageDecompressor::TElMessageDecompressor(TComponent *AOwner) : TElMessageProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMessageDecompressor_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELMESSAGEDECOMPRESSOR */

#ifdef SB_USE_CLASS_TELMESSAGECOMPRESSOR

SB_INLINE int32_t TElMessageCompressor::Compress(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	int32_t OutResult;
	SBCheckError(TElMessageCompressor_Compress(_Handle, InBuffer, InSize, OutBuffer, &OutSize, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMessageCompressor::Compress(TStream &InStream, TStream &OutStream, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageCompressor_Compress_1(_Handle, InStream.getHandle(), OutStream.getHandle(), InCount, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageCompressor::Compress(TStream *InStream, TStream *OutStream, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageCompressor_Compress_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, InCount, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElMessageCompressor::get_ContentType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElMessageCompressor_get_ContentType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2094700661, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElMessageCompressor::set_ContentType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElMessageCompressor_set_ContentType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElMessageCompressor::get_CompressionLevel()
{
	int32_t OutResult;
	SBCheckError(TElMessageCompressor_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMessageCompressor::set_CompressionLevel(int32_t Value)
{
	SBCheckError(TElMessageCompressor_set_CompressionLevel(_Handle, Value));
}

SB_INLINE int32_t TElMessageCompressor::get_FragmentSize()
{
	int32_t OutResult;
	SBCheckError(TElMessageCompressor_get_FragmentSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElMessageCompressor::set_FragmentSize(int32_t Value)
{
	SBCheckError(TElMessageCompressor_set_FragmentSize(_Handle, Value));
}

bool TElMessageCompressor::get_UseUndefSize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageCompressor_get_UseUndefSize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessageCompressor::set_UseUndefSize(bool Value)
{
	SBCheckError(TElMessageCompressor_set_UseUndefSize(_Handle, (int8_t)Value));
}

TElMessageCompressor::TElMessageCompressor(TElMessageCompressorHandle handle, TElOwnHandle ownHandle) : TElMessageProcessor(handle, ownHandle)
{
}

TElMessageCompressor::TElMessageCompressor(TComponent &AOwner) : TElMessageProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMessageCompressor_Create(AOwner.getHandle(), &_Handle));
}

TElMessageCompressor::TElMessageCompressor(TComponent *AOwner) : TElMessageProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMessageCompressor_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELMESSAGECOMPRESSOR */

#ifdef SB_USE_CLASS_TELMESSAGETIMESTAMPER

SB_INLINE int32_t TElMessageTimestamper::Timestamp(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	int32_t OutResult;
	SBCheckError(TElMessageTimestamper_Timestamp(_Handle, InBuffer, InSize, OutBuffer, &OutSize, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMessageTimestamper::Timestamp(TStream &InStream, TStream &OutStream, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageTimestamper_Timestamp_1(_Handle, InStream.getHandle(), OutStream.getHandle(), InCount, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageTimestamper::Timestamp(TStream *InStream, TStream *OutStream, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageTimestamper_Timestamp_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, InCount, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE int32_t TElMessageTimestamper::AddTSPClient(TElCustomTSPClient &Client)
{
	int32_t OutResult;
	SBCheckError(TElMessageTimestamper_AddTSPClient(_Handle, Client.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageTimestamper::AddTSPClient(TElCustomTSPClient *Client)
{
	int32_t OutResult;
	SBCheckError(TElMessageTimestamper_AddTSPClient(_Handle, (Client != NULL) ? Client->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

SB_INLINE void TElMessageTimestamper::RemoveTSPClient(int32_t Index)
{
	SBCheckError(TElMessageTimestamper_RemoveTSPClient(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_INLINE void TElMessageTimestamper::RemoveTSPClient(TElCustomTSPClient &Client)
{
	SBCheckError(TElMessageTimestamper_RemoveTSPClient_1(_Handle, Client.getHandle()));
}

SB_INLINE void TElMessageTimestamper::RemoveTSPClient(TElCustomTSPClient *Client)
{
	SBCheckError(TElMessageTimestamper_RemoveTSPClient_1(_Handle, (Client != NULL) ? Client->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
TElCustomTSPClient* TElMessageTimestamper::get_TSPClients(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageTimestamper_get_TSPClients(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TSPClients)
		this->_Inst_TSPClients = new TElCustomTSPClient(hOutResult, ohFalse);
	else
		this->_Inst_TSPClients->updateHandle(hOutResult);
	return this->_Inst_TSPClients;
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

SB_INLINE int32_t TElMessageTimestamper::get_TSPClientsCount()
{
	int32_t OutResult;
	SBCheckError(TElMessageTimestamper_get_TSPClientsCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
TElCustomTSPClient* TElMessageTimestamper::get_TSPClient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageTimestamper_get_TSPClient(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TSPClient)
		this->_Inst_TSPClient = new TElCustomTSPClient(hOutResult, ohFalse);
	else
		this->_Inst_TSPClient->updateHandle(hOutResult);
	return this->_Inst_TSPClient;
}

SB_INLINE void TElMessageTimestamper::set_TSPClient(TElCustomTSPClient &Value)
{
	SBCheckError(TElMessageTimestamper_set_TSPClient(_Handle, Value.getHandle()));
}

SB_INLINE void TElMessageTimestamper::set_TSPClient(TElCustomTSPClient *Value)
{
	SBCheckError(TElMessageTimestamper_set_TSPClient(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

bool TElMessageTimestamper::get_IncludeContent()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageTimestamper_get_IncludeContent(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessageTimestamper::set_IncludeContent(bool Value)
{
	SBCheckError(TElMessageTimestamper_set_IncludeContent(_Handle, (int8_t)Value));
}

bool TElMessageTimestamper::get_ProtectMetadata()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageTimestamper_get_ProtectMetadata(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessageTimestamper::set_ProtectMetadata(bool Value)
{
	SBCheckError(TElMessageTimestamper_set_ProtectMetadata(_Handle, (int8_t)Value));
}

void TElMessageTimestamper::get_DataURI(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessageTimestamper_get_DataURI(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1723008449, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElMessageTimestamper::set_DataURI(const std::string &Value)
{
	SBCheckError(TElMessageTimestamper_set_DataURI(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElMessageTimestamper::get_FileName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessageTimestamper_get_FileName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-355479255, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElMessageTimestamper::set_FileName(const std::string &Value)
{
	SBCheckError(TElMessageTimestamper_set_FileName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElMessageTimestamper::get_MediaType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessageTimestamper_get_MediaType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1185520154, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElMessageTimestamper::set_MediaType(const std::string &Value)
{
	SBCheckError(TElMessageTimestamper_set_MediaType(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElMessageTimestamper::get_UseUndefSize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElMessageTimestamper_get_UseUndefSize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElMessageTimestamper::set_UseUndefSize(bool Value)
{
	SBCheckError(TElMessageTimestamper_set_UseUndefSize(_Handle, (int8_t)Value));
}

void TElMessageTimestamper::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
	this->_Inst_TSPClients = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
	this->_Inst_TSPClient = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */
}

TElMessageTimestamper::TElMessageTimestamper(TElMessageTimestamperHandle handle, TElOwnHandle ownHandle) : TElMessageProcessor(handle, ownHandle)
{
	initInstances();
}

TElMessageTimestamper::TElMessageTimestamper(TComponent &AOwner) : TElMessageProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessageTimestamper_Create(AOwner.getHandle(), &_Handle));
}

TElMessageTimestamper::TElMessageTimestamper(TComponent *AOwner) : TElMessageProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessageTimestamper_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElMessageTimestamper::~TElMessageTimestamper()
{
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
	delete this->_Inst_TSPClients;
	this->_Inst_TSPClients = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
	delete this->_Inst_TSPClient;
	this->_Inst_TSPClient = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */
}
#endif /* SB_USE_CLASS_TELMESSAGETIMESTAMPER */

#ifdef SB_USE_CLASS_TELMESSAGETIMESTAMPVERIFIER

SB_INLINE int32_t TElMessageTimestampVerifier::Verify(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	int32_t OutResult;
	SBCheckError(TElMessageTimestampVerifier_Verify(_Handle, InBuffer, InSize, OutBuffer, &OutSize, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMessageTimestampVerifier::Verify(TStream &InStream, TStream &OutStream, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageTimestampVerifier_Verify_1(_Handle, InStream.getHandle(), OutStream.getHandle(), InCount, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageTimestampVerifier::Verify(TStream *InStream, TStream *OutStream, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageTimestampVerifier_Verify_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, InCount, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElMessageTimestampVerifier::VerifyDetached(void * Buffer, int32_t Size, void * Data, int32_t DataSize)
{
	int32_t OutResult;
	SBCheckError(TElMessageTimestampVerifier_VerifyDetached(_Handle, Buffer, Size, Data, DataSize, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElMessageTimestampVerifier::VerifyDetached(TStream &InStream, TStream &DataStream, int64_t InCount, int64_t DataCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageTimestampVerifier_VerifyDetached_1(_Handle, InStream.getHandle(), DataStream.getHandle(), InCount, DataCount, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMessageTimestampVerifier::VerifyDetached(TStream *InStream, TStream *DataStream, int64_t InCount, int64_t DataCount)
{
	int32_t OutResult;
	SBCheckError(TElMessageTimestampVerifier_VerifyDetached_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (DataStream != NULL) ? DataStream->getHandle() : SB_NULL_HANDLE, InCount, DataCount, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElMessageTimestampVerifier::IsTimestampDetached(void * Timestamp, int32_t Size, std::string &DataURI, std::string &FileName)
{
	int32_t szDataURI = (int32_t)DataURI.length();
	int32_t szFileName = (int32_t)FileName.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElMessageTimestampVerifier_IsTimestampDetached(Timestamp, Size, (char *)DataURI.data(), &szDataURI, (char *)FileName.data(), &szFileName, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		DataURI.resize(szDataURI);
		SBCheckError(SBGetLastReturnStringA(901351290, 2, (char *)DataURI.data(), &szDataURI));
		FileName.resize(szFileName);
		SBCheckError(SBGetLastReturnStringA(901351290, 3, (char *)FileName.data(), &szFileName));
	}
	else
		SBCheckError(_err);

	DataURI.resize(szDataURI);
	FileName.resize(szFileName);
	return (OutResultRaw != 0);
}

bool TElMessageTimestampVerifier::IsTimestampDetached_Inst(void * Timestamp, int32_t Size, std::string &DataURI, std::string &FileName)
{
	int32_t szDataURI = (int32_t)DataURI.length();
	int32_t szFileName = (int32_t)FileName.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElMessageTimestampVerifier_IsTimestampDetached_1(_Handle, Timestamp, Size, (char *)DataURI.data(), &szDataURI, (char *)FileName.data(), &szFileName, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		DataURI.resize(szDataURI);
		SBCheckError(SBGetLastReturnStringA(901351290, 3, (char *)DataURI.data(), &szDataURI));
		FileName.resize(szFileName);
		SBCheckError(SBGetLastReturnStringA(901351290, 4, (char *)FileName.data(), &szFileName));
	}
	else
		SBCheckError(_err);

	DataURI.resize(szDataURI);
	FileName.resize(szFileName);
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
bool TElMessageTimestampVerifier::IsTimestampDetached(TStream &Timestamp, std::string &DataURI, std::string &FileName, int64_t Count)
{
	int32_t szDataURI = (int32_t)DataURI.length();
	int32_t szFileName = (int32_t)FileName.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElMessageTimestampVerifier_IsTimestampDetached_2(Timestamp.getHandle(), (char *)DataURI.data(), &szDataURI, (char *)FileName.data(), &szFileName, Count, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		DataURI.resize(szDataURI);
		SBCheckError(SBGetLastReturnStringA(248864784, 1, (char *)DataURI.data(), &szDataURI));
		FileName.resize(szFileName);
		SBCheckError(SBGetLastReturnStringA(248864784, 2, (char *)FileName.data(), &szFileName));
	}
	else
		SBCheckError(_err);

	DataURI.resize(szDataURI);
	FileName.resize(szFileName);
	return (OutResultRaw != 0);
}

bool TElMessageTimestampVerifier::IsTimestampDetached(TStream *Timestamp, std::string &DataURI, std::string &FileName, int64_t Count)
{
	int32_t szDataURI = (int32_t)DataURI.length();
	int32_t szFileName = (int32_t)FileName.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElMessageTimestampVerifier_IsTimestampDetached_2((Timestamp != NULL) ? Timestamp->getHandle() : SB_NULL_HANDLE, (char *)DataURI.data(), &szDataURI, (char *)FileName.data(), &szFileName, Count, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		DataURI.resize(szDataURI);
		SBCheckError(SBGetLastReturnStringA(248864784, 1, (char *)DataURI.data(), &szDataURI));
		FileName.resize(szFileName);
		SBCheckError(SBGetLastReturnStringA(248864784, 2, (char *)FileName.data(), &szFileName));
	}
	else
		SBCheckError(_err);

	DataURI.resize(szDataURI);
	FileName.resize(szFileName);
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
bool TElMessageTimestampVerifier::IsTimestampDetached_Inst(TStream &Timestamp, std::string &DataURI, std::string &FileName, int64_t Count)
{
	int32_t szDataURI = (int32_t)DataURI.length();
	int32_t szFileName = (int32_t)FileName.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElMessageTimestampVerifier_IsTimestampDetached_3(_Handle, Timestamp.getHandle(), (char *)DataURI.data(), &szDataURI, (char *)FileName.data(), &szFileName, Count, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		DataURI.resize(szDataURI);
		SBCheckError(SBGetLastReturnStringA(248864784, 2, (char *)DataURI.data(), &szDataURI));
		FileName.resize(szFileName);
		SBCheckError(SBGetLastReturnStringA(248864784, 3, (char *)FileName.data(), &szFileName));
	}
	else
		SBCheckError(_err);

	DataURI.resize(szDataURI);
	FileName.resize(szFileName);
	return (OutResultRaw != 0);
}

bool TElMessageTimestampVerifier::IsTimestampDetached_Inst(TStream *Timestamp, std::string &DataURI, std::string &FileName, int64_t Count)
{
	int32_t szDataURI = (int32_t)DataURI.length();
	int32_t szFileName = (int32_t)FileName.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElMessageTimestampVerifier_IsTimestampDetached_3(_Handle, (Timestamp != NULL) ? Timestamp->getHandle() : SB_NULL_HANDLE, (char *)DataURI.data(), &szDataURI, (char *)FileName.data(), &szFileName, Count, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		DataURI.resize(szDataURI);
		SBCheckError(SBGetLastReturnStringA(248864784, 2, (char *)DataURI.data(), &szDataURI));
		FileName.resize(szFileName);
		SBCheckError(SBGetLastReturnStringA(248864784, 3, (char *)FileName.data(), &szFileName));
	}
	else
		SBCheckError(_err);

	DataURI.resize(szDataURI);
	FileName.resize(szFileName);
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
TElClientTSPInfo* TElMessageTimestampVerifier::get_Timestamps(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMessageTimestampVerifier_get_Timestamps(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Timestamps)
		this->_Inst_Timestamps = new TElClientTSPInfo(hOutResult, ohFalse);
	else
		this->_Inst_Timestamps->updateHandle(hOutResult);
	return this->_Inst_Timestamps;
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

SB_INLINE int32_t TElMessageTimestampVerifier::get_TimestampCount()
{
	int32_t OutResult;
	SBCheckError(TElMessageTimestampVerifier_get_TimestampCount(_Handle, &OutResult));
	return OutResult;
}

void TElMessageTimestampVerifier::get_DataURI(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessageTimestampVerifier_get_DataURI(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1774625349, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElMessageTimestampVerifier::get_FileName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessageTimestampVerifier_get_FileName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1434551, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElMessageTimestampVerifier::get_MediaType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElMessageTimestampVerifier_get_MediaType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1375010411, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElMessageTimestampVerifier::initInstances()
{
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	this->_Inst_Timestamps = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
}

TElMessageTimestampVerifier::TElMessageTimestampVerifier(TElMessageTimestampVerifierHandle handle, TElOwnHandle ownHandle) : TElMessageProcessor(handle, ownHandle)
{
	initInstances();
}

TElMessageTimestampVerifier::TElMessageTimestampVerifier(TComponent &AOwner) : TElMessageProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessageTimestampVerifier_Create(AOwner.getHandle(), &_Handle));
}

TElMessageTimestampVerifier::TElMessageTimestampVerifier(TComponent *AOwner) : TElMessageProcessor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMessageTimestampVerifier_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElMessageTimestampVerifier::~TElMessageTimestampVerifier()
{
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	delete this->_Inst_Timestamps;
	this->_Inst_Timestamps = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
}
#endif /* SB_USE_CLASS_TELMESSAGETIMESTAMPVERIFIER */

};	/* namespace SecureBlackbox */

