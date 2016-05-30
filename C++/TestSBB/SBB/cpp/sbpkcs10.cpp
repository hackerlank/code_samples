#include "sbpkcs10.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST

TSBCertReqFileFormat TElCertificateRequest::DetectCertReqFileFormat(const std::string &FileName)
{
	TSBCertReqFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElCertificateRequest_DetectCertReqFileFormat(FileName.data(), (int32_t)FileName.length(), &OutResultRaw));
	return (TSBCertReqFileFormat)OutResultRaw;
}

TSBCertReqFileFormat TElCertificateRequest::DetectCertReqFileFormat_Inst(const std::string &FileName)
{
	TSBCertReqFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElCertificateRequest_DetectCertReqFileFormat_1(_Handle, FileName.data(), (int32_t)FileName.length(), &OutResultRaw));
	return (TSBCertReqFileFormat)OutResultRaw;
}

#ifdef SB_USE_CLASS_TSTREAM
TSBCertReqFileFormat TElCertificateRequest::DetectCertReqFileFormat(TStream &Stream)
{
	TSBCertReqFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElCertificateRequest_DetectCertReqFileFormat_2(Stream.getHandle(), &OutResultRaw));
	return (TSBCertReqFileFormat)OutResultRaw;
}

TSBCertReqFileFormat TElCertificateRequest::DetectCertReqFileFormat(TStream *Stream)
{
	TSBCertReqFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElCertificateRequest_DetectCertReqFileFormat_2((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBCertReqFileFormat)OutResultRaw;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
TSBCertReqFileFormat TElCertificateRequest::DetectCertReqFileFormat_Inst(TStream &Stream)
{
	TSBCertReqFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElCertificateRequest_DetectCertReqFileFormat_3(_Handle, Stream.getHandle(), &OutResultRaw));
	return (TSBCertReqFileFormat)OutResultRaw;
}

TSBCertReqFileFormat TElCertificateRequest::DetectCertReqFileFormat_Inst(TStream *Stream)
{
	TSBCertReqFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElCertificateRequest_DetectCertReqFileFormat_3(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBCertReqFileFormat)OutResultRaw;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElCertificateRequest::LoadFromBuffer(void * Buffer, int32_t Size)
{
	SBCheckError(TElCertificateRequest_LoadFromBuffer(_Handle, Buffer, Size));
}

SB_INLINE void TElCertificateRequest::LoadFromBufferPEM(void * Buffer, int32_t Size)
{
	SBCheckError(TElCertificateRequest_LoadFromBufferPEM(_Handle, Buffer, Size));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElCertificateRequest::LoadFromStream(TStream &Stream, int32_t Count)
{
	SBCheckError(TElCertificateRequest_LoadFromStream(_Handle, Stream.getHandle(), Count));
}

SB_INLINE void TElCertificateRequest::LoadFromStream(TStream *Stream, int32_t Count)
{
	SBCheckError(TElCertificateRequest_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElCertificateRequest::LoadFromStreamPEM(TStream &Stream, int32_t Count)
{
	SBCheckError(TElCertificateRequest_LoadFromStreamPEM(_Handle, Stream.getHandle(), Count));
}

SB_INLINE void TElCertificateRequest::LoadFromStreamPEM(TStream *Stream, int32_t Count)
{
	SBCheckError(TElCertificateRequest_LoadFromStreamPEM(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElCertificateRequest::Generate(int32_t PublicKeyAlgorithm, int32_t Bits, int32_t SignatureAlgorithm)
{
	SBCheckError(TElCertificateRequest_Generate(_Handle, PublicKeyAlgorithm, Bits, SignatureAlgorithm));
}

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElCertificateRequest::Generate(TElAlgorithmIdentifier &PublicKeyAlgorithm, int32_t Bits, TElAlgorithmIdentifier &SignatureAlgorithm)
{
	SBCheckError(TElCertificateRequest_Generate_1(_Handle, PublicKeyAlgorithm.getHandle(), Bits, SignatureAlgorithm.getHandle()));
}

SB_INLINE void TElCertificateRequest::Generate(TElAlgorithmIdentifier *PublicKeyAlgorithm, int32_t Bits, TElAlgorithmIdentifier *SignatureAlgorithm)
{
	SBCheckError(TElCertificateRequest_Generate_1(_Handle, (PublicKeyAlgorithm != NULL) ? PublicKeyAlgorithm->getHandle() : SB_NULL_HANDLE, Bits, (SignatureAlgorithm != NULL) ? SignatureAlgorithm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElCertificateRequest::SaveToStream(TStream &Stream)
{
	SBCheckError(TElCertificateRequest_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElCertificateRequest::SaveToStream(TStream *Stream)
{
	SBCheckError(TElCertificateRequest_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElCertificateRequest::SaveKeyToStream(TStream &Stream)
{
	SBCheckError(TElCertificateRequest_SaveKeyToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElCertificateRequest::SaveKeyToStream(TStream *Stream)
{
	SBCheckError(TElCertificateRequest_SaveKeyToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElCertificateRequest::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertificateRequest_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCertificateRequest::SaveToBufferPEM(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertificateRequest_SaveToBufferPEM(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElCertificateRequest::SaveToStreamPEM(TStream &Stream)
{
	SBCheckError(TElCertificateRequest_SaveToStreamPEM(_Handle, Stream.getHandle()));
}

SB_INLINE void TElCertificateRequest::SaveToStreamPEM(TStream *Stream)
{
	SBCheckError(TElCertificateRequest_SaveToStreamPEM(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElCertificateRequest::SaveKeyToStreamPEM(TStream &Stream, const std::string &Passphrase)
{
	SBCheckError(TElCertificateRequest_SaveKeyToStreamPEM(_Handle, Stream.getHandle(), Passphrase.data(), (int32_t)Passphrase.length()));
}

SB_INLINE void TElCertificateRequest::SaveKeyToStreamPEM(TStream *Stream, const std::string &Passphrase)
{
	SBCheckError(TElCertificateRequest_SaveKeyToStreamPEM(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Passphrase.data(), (int32_t)Passphrase.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElCertificateRequest::SaveKeyToStreamPEM(TStream &Stream, int32_t EncryptionAlgorithm, TSBSymmetricCryptoMode EncryptionMode, const std::string &Passphrase)
{
	SBCheckError(TElCertificateRequest_SaveKeyToStreamPEM_1(_Handle, Stream.getHandle(), EncryptionAlgorithm, (TSBSymmetricCryptoModeRaw)EncryptionMode, Passphrase.data(), (int32_t)Passphrase.length()));
}

SB_INLINE void TElCertificateRequest::SaveKeyToStreamPEM(TStream *Stream, int32_t EncryptionAlgorithm, TSBSymmetricCryptoMode EncryptionMode, const std::string &Passphrase)
{
	SBCheckError(TElCertificateRequest_SaveKeyToStreamPEM_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, EncryptionAlgorithm, (TSBSymmetricCryptoModeRaw)EncryptionMode, Passphrase.data(), (int32_t)Passphrase.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElCertificateRequest::SaveKeyToBufferPEM(void * Buffer, int32_t &Size, const std::string &Passphrase)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertificateRequest_SaveKeyToBufferPEM(_Handle, Buffer, &Size, Passphrase.data(), (int32_t)Passphrase.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCertificateRequest::SaveKeyToBufferPEM(void * Buffer, int32_t EncryptionAlgorithm, TSBSymmetricCryptoMode EncryptionMode, int32_t &Size, const std::string &Passphrase)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertificateRequest_SaveKeyToBufferPEM_1(_Handle, Buffer, EncryptionAlgorithm, (TSBSymmetricCryptoModeRaw)EncryptionMode, &Size, Passphrase.data(), (int32_t)Passphrase.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElCertificateRequest::SaveKeyToBufferPVK(void * Buffer, int32_t &Size, const std::string &Password, bool UseStrongEncryption)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRequest_SaveKeyToBufferPVK(_Handle, Buffer, &Size, Password.data(), (int32_t)Password.length(), (int8_t)UseStrongEncryption, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElCertificateRequest::SaveKeyToStreamPVK(TStream &Stream, const std::string &Password, bool UseStrongEncryption)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRequest_SaveKeyToStreamPVK(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), (int8_t)UseStrongEncryption, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCertificateRequest::SaveKeyToStreamPVK(TStream *Stream, const std::string &Password, bool UseStrongEncryption)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRequest_SaveKeyToStreamPVK(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), (int8_t)UseStrongEncryption, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElCertificateRequest::LoadKeyFromBuffer(void * Buffer, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRequest_LoadKeyFromBuffer(_Handle, Buffer, Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCertificateRequest::LoadKeyFromBufferPEM(void * Buffer, int32_t Size, const std::string &Passphrase)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRequest_LoadKeyFromBufferPEM(_Handle, Buffer, Size, Passphrase.data(), (int32_t)Passphrase.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElCertificateRequest::LoadKeyFromStream(TStream &Stream, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRequest_LoadKeyFromStream(_Handle, Stream.getHandle(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCertificateRequest::LoadKeyFromStream(TStream *Stream, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRequest_LoadKeyFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElCertificateRequest::LoadKeyFromStreamPEM(TStream &Stream, const std::string &Passphrase, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRequest_LoadKeyFromStreamPEM(_Handle, Stream.getHandle(), Passphrase.data(), (int32_t)Passphrase.length(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCertificateRequest::LoadKeyFromStreamPEM(TStream *Stream, const std::string &Passphrase, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRequest_LoadKeyFromStreamPEM(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Passphrase.data(), (int32_t)Passphrase.length(), Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElCertificateRequest::ValidateSignature()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertificateRequest_ValidateSignature(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCertificateRequest::GetRSAParams(void * PublicModulus, int32_t &PublicModulusSize, void * PublicExponent, int32_t &PublicExponentSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertificateRequest_GetRSAParams(_Handle, PublicModulus, &PublicModulusSize, PublicExponent, &PublicExponentSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCertificateRequest::GetDSAParams(void * P, int32_t &PSize, void * Q, int32_t &QSize, void * G, int32_t &GSize, void * Y, int32_t &YSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertificateRequest_GetDSAParams(_Handle, P, &PSize, Q, &QSize, G, &GSize, Y, &YSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCertificateRequest::SaveKeyToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertificateRequest_SaveKeyToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCertificateRequest::GetPrivateKey(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertificateRequest_GetPrivateKey(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
SB_INLINE void TElCertificateRequest::SetKeyMaterial(TElPublicKeyMaterial &KeyMaterial)
{
	SBCheckError(TElCertificateRequest_SetKeyMaterial(_Handle, KeyMaterial.getHandle()));
}

SB_INLINE void TElCertificateRequest::SetKeyMaterial(TElPublicKeyMaterial *KeyMaterial)
{
	SBCheckError(TElCertificateRequest_SetKeyMaterial(_Handle, (KeyMaterial != NULL) ? KeyMaterial->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElCertificateRequest::get_Subject()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateRequest_get_Subject(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Subject)
		this->_Inst_Subject = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_Subject->updateHandle(hOutResult);
	return this->_Inst_Subject;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
TElPKCS7Attributes* TElCertificateRequest::get_Attributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateRequest_get_Attributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Attributes)
		this->_Inst_Attributes = new TElPKCS7Attributes(hOutResult, ohFalse);
	else
		this->_Inst_Attributes->updateHandle(hOutResult);
	return this->_Inst_Attributes;
}
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

SB_INLINE int32_t TElCertificateRequest::get_Version()
{
	int32_t OutResult;
	SBCheckError(TElCertificateRequest_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCertificateRequest::set_Version(int32_t Value)
{
	SBCheckError(TElCertificateRequest_set_Version(_Handle, Value));
}

SB_INLINE int32_t TElCertificateRequest::get_PublicKeyAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElCertificateRequest_get_PublicKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCertificateRequest::get_SignatureAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElCertificateRequest_get_SignatureAlgorithm(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
TElAlgorithmIdentifier* TElCertificateRequest::get_PublicKeyAlgorithmIdentifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateRequest_get_PublicKeyAlgorithmIdentifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PublicKeyAlgorithmIdentifier)
		this->_Inst_PublicKeyAlgorithmIdentifier = new TElAlgorithmIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_PublicKeyAlgorithmIdentifier->updateHandle(hOutResult);
	return this->_Inst_PublicKeyAlgorithmIdentifier;
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
TElAlgorithmIdentifier* TElCertificateRequest::get_SignatureAlgorithmIdentifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateRequest_get_SignatureAlgorithmIdentifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureAlgorithmIdentifier)
		this->_Inst_SignatureAlgorithmIdentifier = new TElAlgorithmIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_SignatureAlgorithmIdentifier->updateHandle(hOutResult);
	return this->_Inst_SignatureAlgorithmIdentifier;
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
TElCertificateExtensions* TElCertificateRequest::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateRequest_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElCertificateExtensions(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

SB_INLINE int32_t TElCertificateRequest::get_PublicKeySize()
{
	int32_t OutResult;
	SBCheckError(TElCertificateRequest_get_PublicKeySize(_Handle, &OutResult));
	return OutResult;
}

TSBCertificateRequestOptions TElCertificateRequest::get_Options()
{
	TSBCertificateRequestOptionsRaw OutResultRaw = 0;
	SBCheckError(TElCertificateRequest_get_Options(_Handle, &OutResultRaw));
	return (TSBCertificateRequestOptions)OutResultRaw;
}

SB_INLINE void TElCertificateRequest::set_Options(TSBCertificateRequestOptions Value)
{
	SBCheckError(TElCertificateRequest_set_Options(_Handle, (TSBCertificateRequestOptionsRaw)Value));
}

bool TElCertificateRequest::get_PreserveKeyMaterial()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertificateRequest_get_PreserveKeyMaterial(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCertificateRequest::set_PreserveKeyMaterial(bool Value)
{
	SBCheckError(TElCertificateRequest_set_PreserveKeyMaterial(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
TElPublicKeyMaterial* TElCertificateRequest::get_KeyMaterial()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateRequest_get_KeyMaterial(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyMaterial)
		this->_Inst_KeyMaterial = new TElPublicKeyMaterial(hOutResult, ohFalse);
	else
		this->_Inst_KeyMaterial->updateHandle(hOutResult);
	return this->_Inst_KeyMaterial;
}
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

void TElCertificateRequest::initInstances()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_Subject = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	this->_Inst_PublicKeyAlgorithmIdentifier = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	this->_Inst_SignatureAlgorithmIdentifier = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */
#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */
}

TElCertificateRequest::TElCertificateRequest(TElCertificateRequestHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElCertificateRequest::TElCertificateRequest(TComponent &Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCertificateRequest_Create(Owner.getHandle(), &_Handle));
}

TElCertificateRequest::TElCertificateRequest(TComponent *Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCertificateRequest_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCertificateRequest::~TElCertificateRequest()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_Subject;
	this->_Inst_Subject = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	delete this->_Inst_Attributes;
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	delete this->_Inst_PublicKeyAlgorithmIdentifier;
	this->_Inst_PublicKeyAlgorithmIdentifier = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	delete this->_Inst_SignatureAlgorithmIdentifier;
	this->_Inst_SignatureAlgorithmIdentifier = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */
#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
	delete this->_Inst_KeyMaterial;
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */

};	/* namespace SecureBlackbox */

