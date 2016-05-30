#include "sbeciescrypto.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELECIESCRYPTO

bool TElECIESCrypto::IsEncAlgorithmSupported(int32_t AlgID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECIESCrypto_IsEncAlgorithmSupported(AlgID, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElECIESCrypto::IsEncAlgorithmSupported_Inst(int32_t AlgID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECIESCrypto_IsEncAlgorithmSupported_1(_Handle, AlgID, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElECIESCrypto::IsHashAlgorithmSupported(int32_t AlgID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECIESCrypto_IsHashAlgorithmSupported(AlgID, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElECIESCrypto::IsHashAlgorithmSupported_Inst(int32_t AlgID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECIESCrypto_IsHashAlgorithmSupported_1(_Handle, AlgID, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElECIESCrypto::IsMACAlgorithmSupported(int32_t AlgID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECIESCrypto_IsMACAlgorithmSupported(AlgID, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElECIESCrypto::IsMACAlgorithmSupported_Inst(int32_t AlgID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECIESCrypto_IsMACAlgorithmSupported_1(_Handle, AlgID, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElECIESCrypto::InitializeEncryption()
{
	SBCheckError(TElECIESCrypto_InitializeEncryption(_Handle));
}

SB_INLINE void TElECIESCrypto::Encrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElECIESCrypto_Encrypt(_Handle, InBuffer, InSize, OutBuffer, &OutSize));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElECIESCrypto::Encrypt(TStream &InStream, TStream &OutStream)
{
	SBCheckError(TElECIESCrypto_Encrypt_1(_Handle, InStream.getHandle(), OutStream.getHandle()));
}

SB_INLINE void TElECIESCrypto::Encrypt(TStream *InStream, TStream *OutStream)
{
	SBCheckError(TElECIESCrypto_Encrypt_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElECIESCrypto::EncryptUpdate(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElECIESCrypto_EncryptUpdate(_Handle, InBuffer, InSize, OutBuffer, &OutSize));
}

SB_INLINE void TElECIESCrypto::FinalizeEncryption(void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElECIESCrypto_FinalizeEncryption(_Handle, OutBuffer, &OutSize));
}

SB_INLINE void TElECIESCrypto::InitializeDecryption()
{
	SBCheckError(TElECIESCrypto_InitializeDecryption(_Handle));
}

bool TElECIESCrypto::Decrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECIESCrypto_Decrypt(_Handle, InBuffer, InSize, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
bool TElECIESCrypto::Decrypt(TStream &InStream, TStream &OutStream, int32_t InCount)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECIESCrypto_Decrypt_1(_Handle, InStream.getHandle(), OutStream.getHandle(), InCount, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElECIESCrypto::Decrypt(TStream *InStream, TStream *OutStream, int32_t InCount)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECIESCrypto_Decrypt_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, InCount, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElECIESCrypto::DecryptUpdate(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	SBCheckError(TElECIESCrypto_DecryptUpdate(_Handle, InBuffer, InSize, OutBuffer, &OutSize));
}

bool TElECIESCrypto::FinalizeDecryption(void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECIESCrypto_FinalizeDecryption(_Handle, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TClassHandle TElECIESCrypto::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElECIESCrypto_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElECIESCrypto::get_EncryptionAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElECIESCrypto_get_EncryptionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElECIESCrypto::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElECIESCrypto_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElECIESCrypto::get_MACAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElECIESCrypto_get_MACAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElECIESCrypto::get_TagSize()
{
	int32_t OutResult;
	SBCheckError(TElECIESCrypto_get_TagSize(_Handle, &OutResult));
	return OutResult;
}

TSBSymmetricCipherPadding TElECIESCrypto::get_Padding()
{
	TSBSymmetricCipherPaddingRaw OutResultRaw = 0;
	SBCheckError(TElECIESCrypto_get_Padding(_Handle, &OutResultRaw));
	return (TSBSymmetricCipherPadding)OutResultRaw;
}

SB_INLINE void TElECIESCrypto::set_Padding(TSBSymmetricCipherPadding Value)
{
	SBCheckError(TElECIESCrypto_set_Padding(_Handle, (TSBSymmetricCipherPaddingRaw)Value));
}

SB_INLINE int32_t TElECIESCrypto::get_MACKeySize()
{
	int32_t OutResult;
	SBCheckError(TElECIESCrypto_get_MACKeySize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECIESCrypto::set_MACKeySize(int32_t Value)
{
	SBCheckError(TElECIESCrypto_set_MACKeySize(_Handle, Value));
}

TSBECIESKAType TElECIESCrypto::get_KeyAgreementType()
{
	TSBECIESKATypeRaw OutResultRaw = 0;
	SBCheckError(TElECIESCrypto_get_KeyAgreementType(_Handle, &OutResultRaw));
	return (TSBECIESKAType)OutResultRaw;
}

SB_INLINE void TElECIESCrypto::set_KeyAgreementType(TSBECIESKAType Value)
{
	SBCheckError(TElECIESCrypto_set_KeyAgreementType(_Handle, (TSBECIESKATypeRaw)Value));
}

TSBECIESKDFType TElECIESCrypto::get_KDFType()
{
	TSBECIESKDFTypeRaw OutResultRaw = 0;
	SBCheckError(TElECIESCrypto_get_KDFType(_Handle, &OutResultRaw));
	return (TSBECIESKDFType)OutResultRaw;
}

SB_INLINE void TElECIESCrypto::set_KDFType(TSBECIESKDFType Value)
{
	SBCheckError(TElECIESCrypto_set_KDFType(_Handle, (TSBECIESKDFTypeRaw)Value));
}

TSBECIESKDFInterpretation TElECIESCrypto::get_KDFInterpretation()
{
	TSBECIESKDFInterpretationRaw OutResultRaw = 0;
	SBCheckError(TElECIESCrypto_get_KDFInterpretation(_Handle, &OutResultRaw));
	return (TSBECIESKDFInterpretation)OutResultRaw;
}

SB_INLINE void TElECIESCrypto::set_KDFInterpretation(TSBECIESKDFInterpretation Value)
{
	SBCheckError(TElECIESCrypto_set_KDFInterpretation(_Handle, (TSBECIESKDFInterpretationRaw)Value));
}

void TElECIESCrypto::get_KDFOptionalInfo(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECIESCrypto_get_KDFOptionalInfo(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2103332111, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECIESCrypto::set_KDFOptionalInfo(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECIESCrypto_set_KDFOptionalInfo(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECIESCrypto::get_MACOptionalInfo(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECIESCrypto_get_MACOptionalInfo(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(970439549, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECIESCrypto::set_MACOptionalInfo(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECIESCrypto_set_MACOptionalInfo(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELECKEYMATERIAL
TElECKeyMaterial* TElECIESCrypto::get_KeyMaterial()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElECIESCrypto_get_KeyMaterial(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyMaterial)
		this->_Inst_KeyMaterial = new TElECKeyMaterial(hOutResult, ohFalse);
	else
		this->_Inst_KeyMaterial->updateHandle(hOutResult);
	return this->_Inst_KeyMaterial;
}

SB_INLINE void TElECIESCrypto::set_KeyMaterial(TElECKeyMaterial &Value)
{
	SBCheckError(TElECIESCrypto_set_KeyMaterial(_Handle, Value.getHandle()));
}

SB_INLINE void TElECIESCrypto::set_KeyMaterial(TElECKeyMaterial *Value)
{
	SBCheckError(TElECIESCrypto_set_KeyMaterial(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELECKEYMATERIAL */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProvider* TElECIESCrypto::get_CryptoProvider()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElECIESCrypto_get_CryptoProvider(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProvider)
		this->_Inst_CryptoProvider = new TElCustomCryptoProvider(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProvider->updateHandle(hOutResult);
	return this->_Inst_CryptoProvider;
}

SB_INLINE void TElECIESCrypto::set_CryptoProvider(TElCustomCryptoProvider &Value)
{
	SBCheckError(TElECIESCrypto_set_CryptoProvider(_Handle, Value.getHandle()));
}

SB_INLINE void TElECIESCrypto::set_CryptoProvider(TElCustomCryptoProvider *Value)
{
	SBCheckError(TElECIESCrypto_set_CryptoProvider(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElECIESCrypto::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElECIESCrypto_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElECIESCrypto::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElECIESCrypto_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElECIESCrypto::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElECIESCrypto_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

bool TElECIESCrypto::get_UseCofactor()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECIESCrypto_get_UseCofactor(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElECIESCrypto::set_UseCofactor(bool Value)
{
	SBCheckError(TElECIESCrypto_set_UseCofactor(_Handle, (int8_t)Value));
}

SB_INLINE void TElECIESCrypto::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElECIESCrypto_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElECIESCrypto::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElECIESCrypto_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

void TElECIESCrypto::initInstances()
{
#ifdef SB_USE_CLASS_TELECKEYMATERIAL
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELECKEYMATERIAL */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}

TElECIESCrypto::TElECIESCrypto(TElECIESCryptoHandle handle, TElOwnHandle ownHandle) : TElCustomCrypto(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElECIESCrypto::TElECIESCrypto(int32_t EncAlgID, int32_t HashAlgID, int32_t MACAlgID, TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElECIESCrypto_Create(EncAlgID, HashAlgID, MACAlgID, CryptoProvider.getHandle(), &_Handle));
}

TElECIESCrypto::TElECIESCrypto(int32_t EncAlgID, int32_t HashAlgID, int32_t MACAlgID, TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElECIESCrypto_Create(EncAlgID, HashAlgID, MACAlgID, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElECIESCrypto::TElECIESCrypto(int32_t EncAlgID, int32_t HashAlgID, TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElECIESCrypto_Create_1(EncAlgID, HashAlgID, CryptoProvider.getHandle(), &_Handle));
}

TElECIESCrypto::TElECIESCrypto(int32_t EncAlgID, int32_t HashAlgID, TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElECIESCrypto_Create_1(EncAlgID, HashAlgID, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElECIESCrypto::TElECIESCrypto(int32_t EncAlgID, TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElECIESCrypto_Create_2(EncAlgID, CryptoProvider.getHandle(), &_Handle));
}

TElECIESCrypto::TElECIESCrypto(int32_t EncAlgID, TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElECIESCrypto_Create_2(EncAlgID, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElECIESCrypto::TElECIESCrypto(TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElECIESCrypto_Create_3(CryptoProvider.getHandle(), &_Handle));
}

TElECIESCrypto::TElECIESCrypto(TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElECIESCrypto_Create_3((CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElECIESCrypto::TElECIESCrypto(int32_t EncAlgID, int32_t HashAlgID, int32_t MACAlgID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElECIESCrypto_Create_4(EncAlgID, HashAlgID, MACAlgID, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElECIESCrypto::TElECIESCrypto(int32_t EncAlgID, int32_t HashAlgID, int32_t MACAlgID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElECIESCrypto_Create_4(EncAlgID, HashAlgID, MACAlgID, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElECIESCrypto::TElECIESCrypto(int32_t EncAlgID, int32_t HashAlgID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElECIESCrypto_Create_5(EncAlgID, HashAlgID, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElECIESCrypto::TElECIESCrypto(int32_t EncAlgID, int32_t HashAlgID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElECIESCrypto_Create_5(EncAlgID, HashAlgID, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElECIESCrypto::TElECIESCrypto(int32_t EncAlgID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElECIESCrypto_Create_6(EncAlgID, Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElECIESCrypto::TElECIESCrypto(int32_t EncAlgID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElECIESCrypto_Create_6(EncAlgID, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
TElECIESCrypto::TElECIESCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElECIESCrypto_Create_7(Manager.getHandle(), CryptoProvider.getHandle(), &_Handle));
}

TElECIESCrypto::TElECIESCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider) : TElCustomCrypto(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElECIESCrypto_Create_7((Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (CryptoProvider != NULL) ? CryptoProvider->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

TElECIESCrypto::~TElECIESCrypto()
{
#ifdef SB_USE_CLASS_TELECKEYMATERIAL
	delete this->_Inst_KeyMaterial;
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELECKEYMATERIAL */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	delete this->_Inst_CryptoProvider;
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}
#endif /* SB_USE_CLASS_TELECIESCRYPTO */

};	/* namespace SecureBlackbox */

