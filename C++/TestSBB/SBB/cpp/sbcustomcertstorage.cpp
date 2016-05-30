#include "sbcustomcertstorage.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TSBCertificateValidity TElCustomCertStorage::Validate(TElX509Certificate &Certificate, TSBCertificateValidityReason &Reason, int64_t ValidityMoment)
{
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	TSBCertificateValidityRaw OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_Validate(_Handle, Certificate.getHandle(), &ReasonRaw, ValidityMoment, &OutResultRaw));
	Reason = (TSBCertificateValidityReason)ReasonRaw;
	return (TSBCertificateValidity)OutResultRaw;
}

TSBCertificateValidity TElCustomCertStorage::Validate(TElX509Certificate *Certificate, TSBCertificateValidityReason &Reason, int64_t ValidityMoment)
{
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	TSBCertificateValidityRaw OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_Validate(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &ReasonRaw, ValidityMoment, &OutResultRaw));
	Reason = (TSBCertificateValidityReason)ReasonRaw;
	return (TSBCertificateValidity)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TSBCertificateValidity TElCustomCertStorage::Validate(TElX509Certificate &Certificate, TSBCertificateValidityReason &Reason, bool CheckCACertDates, int64_t ValidityMoment)
{
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	TSBCertificateValidityRaw OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_Validate_1(_Handle, Certificate.getHandle(), &ReasonRaw, (int8_t)CheckCACertDates, ValidityMoment, &OutResultRaw));
	Reason = (TSBCertificateValidityReason)ReasonRaw;
	return (TSBCertificateValidity)OutResultRaw;
}

TSBCertificateValidity TElCustomCertStorage::Validate(TElX509Certificate *Certificate, TSBCertificateValidityReason &Reason, bool CheckCACertDates, int64_t ValidityMoment)
{
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	TSBCertificateValidityRaw OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_Validate_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &ReasonRaw, (int8_t)CheckCACertDates, ValidityMoment, &OutResultRaw));
	Reason = (TSBCertificateValidityReason)ReasonRaw;
	return (TSBCertificateValidity)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElCustomCertStorage::Add(TElX509Certificate &Certificate, bool CopyPrivateKey)
{
	SBCheckError(TElCustomCertStorage_Add(_Handle, Certificate.getHandle(), (int8_t)CopyPrivateKey));
}

SB_INLINE void TElCustomCertStorage::Add(TElX509Certificate *Certificate, bool CopyPrivateKey)
{
	SBCheckError(TElCustomCertStorage_Add(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)CopyPrivateKey));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE void TElCustomCertStorage::Remove(int32_t Index)
{
	SBCheckError(TElCustomCertStorage_Remove(_Handle, Index));
}

SB_INLINE void TElCustomCertStorage::ExportTo(TElCustomCertStorage &Storage)
{
	SBCheckError(TElCustomCertStorage_ExportTo(_Handle, Storage.getHandle()));
}

SB_INLINE void TElCustomCertStorage::ExportTo(TElCustomCertStorage *Storage)
{
	SBCheckError(TElCustomCertStorage_ExportTo(_Handle, (Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElCustomCertStorage::LoadFromBufferPKCS7(void * Buffer, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_LoadFromBufferPKCS7(_Handle, Buffer, Size, &OutResult));
	return OutResult;
}

bool TElCustomCertStorage::SaveToBufferPKCS7(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_SaveToBufferPKCS7(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElCustomCertStorage::LoadFromStreamPKCS7(TStream &Stream, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_LoadFromStreamPKCS7(_Handle, Stream.getHandle(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCertStorage::LoadFromStreamPKCS7(TStream *Stream, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_LoadFromStreamPKCS7(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
bool TElCustomCertStorage::SaveToStreamPKCS7(TStream &Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_SaveToStreamPKCS7(_Handle, Stream.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCertStorage::SaveToStreamPKCS7(TStream *Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_SaveToStreamPKCS7(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElCustomCertStorage::LoadFromBufferPEM(void * Buffer, int32_t Size, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_LoadFromBufferPEM(_Handle, Buffer, Size, Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}

bool TElCustomCertStorage::SaveToBufferPEM(void * Buffer, int32_t &Size, const std::string &Password)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_SaveToBufferPEM(_Handle, Buffer, &Size, Password.data(), (int32_t)Password.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCertStorage::SaveToBufferPEM(void * Buffer, int32_t &Size, const std::string &Password, int32_t EncryptionAlgorithm, TSBSymmetricCryptoMode EncryptionMode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_SaveToBufferPEM_1(_Handle, Buffer, &Size, Password.data(), (int32_t)Password.length(), EncryptionAlgorithm, (TSBSymmetricCryptoModeRaw)EncryptionMode, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElCustomCertStorage::LoadFromStreamPEM(TStream &Stream, const std::string &Password, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_LoadFromStreamPEM(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCertStorage::LoadFromStreamPEM(TStream *Stream, const std::string &Password, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_LoadFromStreamPEM(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
bool TElCustomCertStorage::SaveToStreamPEM(TStream &Stream, const std::string &Password)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_SaveToStreamPEM(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCertStorage::SaveToStreamPEM(TStream *Stream, const std::string &Password)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_SaveToStreamPEM(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
bool TElCustomCertStorage::SaveToStreamPEM(TStream &Stream, const std::string &Password, int32_t EncryptionAlgorithm, TSBSymmetricCryptoMode EncryptionMode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_SaveToStreamPEM_1(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), EncryptionAlgorithm, (TSBSymmetricCryptoModeRaw)EncryptionMode, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCertStorage::SaveToStreamPEM(TStream *Stream, const std::string &Password, int32_t EncryptionAlgorithm, TSBSymmetricCryptoMode EncryptionMode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_SaveToStreamPEM_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), EncryptionAlgorithm, (TSBSymmetricCryptoModeRaw)EncryptionMode, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElCustomCertStorage::LoadFromBufferJKS(void * Buffer, const std::string &Pass, int32_t Size, TElJKSPasswordEvent pMethodOnPasswordNeeded, void * pDataOnPasswordNeeded)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_LoadFromBufferJKS(_Handle, Buffer, Pass.data(), (int32_t)Pass.length(), Size, pMethodOnPasswordNeeded, pDataOnPasswordNeeded, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCertStorage::SaveToBufferJKS(void * Buffer, const std::string &Pass, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_SaveToBufferJKS(_Handle, Buffer, Pass.data(), (int32_t)Pass.length(), &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCertStorage::SaveToBufferJKSEx(void * Buffer, const std::string &Pass, int32_t &Size, TElJKSAliasNeededEvent pMethodOnAliasNeeded, void * pDataOnAliasNeeded)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_SaveToBufferJKSEx(_Handle, Buffer, Pass.data(), (int32_t)Pass.length(), &Size, pMethodOnAliasNeeded, pDataOnAliasNeeded, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
bool TElCustomCertStorage::LoadFromStreamJKS(TStream &Stream, const std::string &Pass, int32_t Count, TElJKSPasswordEvent pMethodOnPasswordNeeded, void * pDataOnPasswordNeeded)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_LoadFromStreamJKS(_Handle, Stream.getHandle(), Pass.data(), (int32_t)Pass.length(), Count, pMethodOnPasswordNeeded, pDataOnPasswordNeeded, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCertStorage::LoadFromStreamJKS(TStream *Stream, const std::string &Pass, int32_t Count, TElJKSPasswordEvent pMethodOnPasswordNeeded, void * pDataOnPasswordNeeded)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_LoadFromStreamJKS(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Pass.data(), (int32_t)Pass.length(), Count, pMethodOnPasswordNeeded, pDataOnPasswordNeeded, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
bool TElCustomCertStorage::SaveToStreamJKS(TStream &Stream, const std::string &Pass)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_SaveToStreamJKS(_Handle, Stream.getHandle(), Pass.data(), (int32_t)Pass.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCertStorage::SaveToStreamJKS(TStream *Stream, const std::string &Pass)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_SaveToStreamJKS(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Pass.data(), (int32_t)Pass.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
bool TElCustomCertStorage::SaveToStreamJKSEx(TStream &Stream, const std::string &Pass, TElJKSAliasNeededEvent pMethodOnAliasNeeded, void * pDataOnAliasNeeded)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_SaveToStreamJKSEx(_Handle, Stream.getHandle(), Pass.data(), (int32_t)Pass.length(), pMethodOnAliasNeeded, pDataOnAliasNeeded, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCertStorage::SaveToStreamJKSEx(TStream *Stream, const std::string &Pass, TElJKSAliasNeededEvent pMethodOnAliasNeeded, void * pDataOnAliasNeeded)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_SaveToStreamJKSEx(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Pass.data(), (int32_t)Pass.length(), pMethodOnAliasNeeded, pDataOnAliasNeeded, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElCustomCertStorage::LoadFromBufferPFX(void * Buffer, int32_t Size, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_LoadFromBufferPFX(_Handle, Buffer, Size, Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCertStorage::SaveToBufferPFX(void * Buffer, int32_t &Size, const std::string &Password, int32_t KeyEncryptionAlgorithm, int32_t CertEncryptionAlgorithm)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_SaveToBufferPFX(_Handle, Buffer, &Size, Password.data(), (int32_t)Password.length(), KeyEncryptionAlgorithm, CertEncryptionAlgorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCertStorage::SaveToBufferPFX(void * Buffer, int32_t &Size, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_SaveToBufferPFX_1(_Handle, Buffer, &Size, Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElCustomCertStorage::LoadFromStreamPFX(TStream &Stream, const std::string &Password, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_LoadFromStreamPFX(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCertStorage::LoadFromStreamPFX(TStream *Stream, const std::string &Password, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_LoadFromStreamPFX(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElCustomCertStorage::SaveToStreamPFX(TStream &Stream, const std::string &Password, int32_t KeyEncryptionAlgorithm, int32_t CertEncryptionAlgorithm)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_SaveToStreamPFX(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), KeyEncryptionAlgorithm, CertEncryptionAlgorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCertStorage::SaveToStreamPFX(TStream *Stream, const std::string &Password, int32_t KeyEncryptionAlgorithm, int32_t CertEncryptionAlgorithm)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_SaveToStreamPFX(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), KeyEncryptionAlgorithm, CertEncryptionAlgorithm, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElCustomCertStorage::SaveToStreamPFX(TStream &Stream, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_SaveToStreamPFX_1(_Handle, Stream.getHandle(), Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCertStorage::SaveToStreamPFX(TStream *Stream, const std::string &Password)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_SaveToStreamPFX_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElCustomCertStorage::LoadFromBufferPkiPath(void * Buffer, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_LoadFromBufferPkiPath(_Handle, Buffer, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCertStorage::SaveToBufferPkiPath(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_SaveToBufferPkiPath(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
bool TElCustomCertStorage::LoadFromStreamPkiPath(TStream &Stream, int32_t Count)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_LoadFromStreamPkiPath(_Handle, Stream.getHandle(), Count, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCertStorage::LoadFromStreamPkiPath(TStream *Stream, int32_t Count)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_LoadFromStreamPkiPath(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
bool TElCustomCertStorage::SaveToStreamPkiPath(TStream &Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_SaveToStreamPkiPath(_Handle, Stream.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCertStorage::SaveToStreamPkiPath(TStream *Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_SaveToStreamPkiPath(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELX509CERTIFICATECHAIN
SB_INLINE TElX509CertificateChainHandle TElCustomCertStorage::BuildChain(TElX509Certificate &Certificate)
{
	TElX509CertificateChainHandle OutResult;
	SBCheckError(TElCustomCertStorage_BuildChain(_Handle, Certificate.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElX509CertificateChainHandle TElCustomCertStorage::BuildChain(TElX509Certificate *Certificate)
{
	TElX509CertificateChainHandle OutResult;
	SBCheckError(TElCustomCertStorage_BuildChain(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELX509CERTIFICATECHAIN */

#ifdef SB_USE_CLASS_TELX509CERTIFICATECHAIN
SB_INLINE TElX509CertificateChainHandle TElCustomCertStorage::BuildChain(int32_t ChainIndex)
{
	TElX509CertificateChainHandle OutResult;
	SBCheckError(TElCustomCertStorage_BuildChain_1(_Handle, ChainIndex, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATECHAIN */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE int32_t TElCustomCertStorage::IndexOf(TElX509Certificate &Certificate)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_IndexOf(_Handle, Certificate.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCertStorage::IndexOf(TElX509Certificate *Certificate)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_IndexOf(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
bool TElCustomCertStorage::IsPresent(TElX509Certificate &Certificate)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_IsPresent(_Handle, Certificate.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCertStorage::IsPresent(TElX509Certificate *Certificate)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_IsPresent(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE void TElCustomCertStorage::Clear()
{
	SBCheckError(TElCustomCertStorage_Clear(_Handle));
}

SB_INLINE int32_t TElCustomCertStorage::FindByHash(const TMessageDigest160 &Digest)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_FindByHash(_Handle, &Digest, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCertStorage::FindByHash(const TMessageDigest128 &Digest)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_FindByHash_1(_Handle, &Digest, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE int32_t TElCustomCertStorage::GetIssuerCertificate(TElX509Certificate &Certificate)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_GetIssuerCertificate(_Handle, Certificate.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCertStorage::GetIssuerCertificate(TElX509Certificate *Certificate)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_GetIssuerCertificate(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

bool TElCustomCertStorage::IsReadOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_IsReadOnly(&OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCertStorage::IsReadOnly_Inst()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_IsReadOnly_1(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCERTIFICATELOOKUP
SB_INLINE int32_t TElCustomCertStorage::FindFirst(TElCertificateLookup &Lookup)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_FindFirst(_Handle, Lookup.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCertStorage::FindFirst(TElCertificateLookup *Lookup)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_FindFirst(_Handle, (Lookup != NULL) ? Lookup->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCERTIFICATELOOKUP */

#ifdef SB_USE_CLASS_TELCERTIFICATELOOKUP
SB_INLINE int32_t TElCustomCertStorage::FindNext(TElCertificateLookup &Lookup)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_FindNext(_Handle, Lookup.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCertStorage::FindNext(TElCertificateLookup *Lookup)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_FindNext(_Handle, (Lookup != NULL) ? Lookup->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCERTIFICATELOOKUP */

#ifdef SB_USE_CLASS_TELX509CERTIFICATECHAIN
SB_INLINE void TElCustomCertStorage::ImportFrom(TElX509CertificateChain &Chain)
{
	SBCheckError(TElCustomCertStorage_ImportFrom(_Handle, Chain.getHandle()));
}

SB_INLINE void TElCustomCertStorage::ImportFrom(TElX509CertificateChain *Chain)
{
	SBCheckError(TElCustomCertStorage_ImportFrom(_Handle, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATECHAIN */

#ifdef SB_USE_CLASS_TELX509CERTIFICATECHAIN
SB_INLINE void TElCustomCertStorage::ImportFrom(TElX509CertificateChain &Chain, bool ImportEndEntity)
{
	SBCheckError(TElCustomCertStorage_ImportFrom_1(_Handle, Chain.getHandle(), (int8_t)ImportEndEntity));
}

SB_INLINE void TElCustomCertStorage::ImportFrom(TElX509CertificateChain *Chain, bool ImportEndEntity)
{
	SBCheckError(TElCustomCertStorage_ImportFrom_1(_Handle, (Chain != NULL) ? Chain->getHandle() : SB_NULL_HANDLE, (int8_t)ImportEndEntity));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATECHAIN */

SB_INLINE void TElCustomCertStorage::BeginRead()
{
	SBCheckError(TElCustomCertStorage_BeginRead(_Handle));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
bool TElCustomCertStorage::Contains(TElX509Certificate &Certificate)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_Contains(_Handle, Certificate.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCustomCertStorage::Contains(TElX509Certificate *Certificate)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_Contains(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE void TElCustomCertStorage::EndRead()
{
	SBCheckError(TElCustomCertStorage_EndRead(_Handle));
}

SB_INLINE int32_t TElCustomCertStorage::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_get_Count(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCustomCertStorage::get_ChainCount()
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_get_ChainCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElCustomCertStorage::get_Certificates(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomCertStorage_get_Certificates(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE int32_t TElCustomCertStorage::get_Chains(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TElCustomCertStorage_get_Chains(_Handle, Index, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
TElCertificateRevocationList* TElCustomCertStorage::get_CRL()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomCertStorage_get_CRL(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRL)
		this->_Inst_CRL = new TElCertificateRevocationList(hOutResult, ohFalse);
	else
		this->_Inst_CRL->updateHandle(hOutResult);
	return this->_Inst_CRL;
}

SB_INLINE void TElCustomCertStorage::set_CRL(TElCertificateRevocationList &Value)
{
	SBCheckError(TElCustomCertStorage_set_CRL(_Handle, Value.getHandle()));
}

SB_INLINE void TElCustomCertStorage::set_CRL(TElCertificateRevocationList *Value)
{
	SBCheckError(TElCustomCertStorage_set_CRL(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElCustomCertStorage::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomCertStorage_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElCustomCertStorage::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElCustomCertStorage_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElCustomCertStorage::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElCustomCertStorage_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

TSBCertStorageOptions TElCustomCertStorage::get_Options()
{
	TSBCertStorageOptionsRaw OutResultRaw = 0;
	SBCheckError(TElCustomCertStorage_get_Options(_Handle, &OutResultRaw));
	return (TSBCertStorageOptions)OutResultRaw;
}

SB_INLINE void TElCustomCertStorage::set_Options(TSBCertStorageOptions Value)
{
	SBCheckError(TElCustomCertStorage_set_Options(_Handle, (TSBCertStorageOptionsRaw)Value));
}

void TElCustomCertStorage::initInstances()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
	this->_Inst_CRL = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}

TElCustomCertStorage::TElCustomCertStorage(TElCustomCertStorageHandle handle, TElOwnHandle ownHandle) : TElBaseCertStorage(handle, ownHandle)
{
	initInstances();
}

TElCustomCertStorage::TElCustomCertStorage(TComponent &Owner) : TElBaseCertStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomCertStorage_Create(Owner.getHandle(), &_Handle));
}

TElCustomCertStorage::TElCustomCertStorage(TComponent *Owner) : TElBaseCertStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomCertStorage_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCustomCertStorage::~TElCustomCertStorage()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
	delete this->_Inst_CRL;
	this->_Inst_CRL = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCERTIFICATELOOKUP

void TElCertificateLookup::get_AuthorityKeyIdentifier(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCertificateLookup_get_AuthorityKeyIdentifier(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1186836801, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCertificateLookup::set_AuthorityKeyIdentifier(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCertificateLookup_set_AuthorityKeyIdentifier(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElCertificateLookup::get_SubjectKeyIdentifier(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCertificateLookup_get_SubjectKeyIdentifier(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1379184985, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCertificateLookup::set_SubjectKeyIdentifier(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCertificateLookup_set_SubjectKeyIdentifier(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElCertificateLookup::get_SerialNumber(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCertificateLookup_get_SerialNumber(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1250502559, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCertificateLookup::set_SerialNumber(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCertificateLookup_set_SerialNumber(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElCertificateLookup::get_PublicKeyHash(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCertificateLookup_get_PublicKeyHash(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-141608244, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCertificateLookup::set_PublicKeyHash(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCertificateLookup_set_PublicKeyHash(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElCertificateLookup::get_CertificateHash(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCertificateLookup_get_CertificateHash(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(490020564, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCertificateLookup::set_CertificateHash(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCertificateLookup_set_CertificateHash(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TSBLookupCriteria TElCertificateLookup::get_Criteria()
{
	TSBLookupCriteriaRaw OutResultRaw = 0;
	SBCheckError(TElCertificateLookup_get_Criteria(_Handle, &OutResultRaw));
	return (TSBLookupCriteria)OutResultRaw;
}

SB_INLINE void TElCertificateLookup::set_Criteria(TSBLookupCriteria Value)
{
	SBCheckError(TElCertificateLookup_set_Criteria(_Handle, (TSBLookupCriteriaRaw)Value));
}

TSBLookupOptions TElCertificateLookup::get_Options()
{
	TSBLookupOptionsRaw OutResultRaw = 0;
	SBCheckError(TElCertificateLookup_get_Options(_Handle, &OutResultRaw));
	return (TSBLookupOptions)OutResultRaw;
}

SB_INLINE void TElCertificateLookup::set_Options(TSBLookupOptions Value)
{
	SBCheckError(TElCertificateLookup_set_Options(_Handle, (TSBLookupOptionsRaw)Value));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElCertificateLookup::get_IssuerRDN()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateLookup_get_IssuerRDN(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IssuerRDN)
		this->_Inst_IssuerRDN = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_IssuerRDN->updateHandle(hOutResult);
	return this->_Inst_IssuerRDN;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElCertificateLookup::get_SubjectRDN()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateLookup_get_SubjectRDN(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SubjectRDN)
		this->_Inst_SubjectRDN = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_SubjectRDN->updateHandle(hOutResult);
	return this->_Inst_SubjectRDN;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE int64_t TElCertificateLookup::get_ValidFrom()
{
	int64_t OutResult;
	SBCheckError(TElCertificateLookup_get_ValidFrom(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCertificateLookup::set_ValidFrom(int64_t Value)
{
	SBCheckError(TElCertificateLookup_set_ValidFrom(_Handle, Value));
}

SB_INLINE int64_t TElCertificateLookup::get_ValidTo()
{
	int64_t OutResult;
	SBCheckError(TElCertificateLookup_get_ValidTo(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCertificateLookup::set_ValidTo(int64_t Value)
{
	SBCheckError(TElCertificateLookup_set_ValidTo(_Handle, Value));
}

SB_INLINE int32_t TElCertificateLookup::get_PublicKeyAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElCertificateLookup_get_PublicKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCertificateLookup::set_PublicKeyAlgorithm(int32_t Value)
{
	SBCheckError(TElCertificateLookup_set_PublicKeyAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElCertificateLookup::get_SignatureAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElCertificateLookup_get_SignatureAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCertificateLookup::set_SignatureAlgorithm(int32_t Value)
{
	SBCheckError(TElCertificateLookup_set_SignatureAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElCertificateLookup::get_PublicKeySizeMin()
{
	int32_t OutResult;
	SBCheckError(TElCertificateLookup_get_PublicKeySizeMin(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCertificateLookup::set_PublicKeySizeMin(int32_t Value)
{
	SBCheckError(TElCertificateLookup_set_PublicKeySizeMin(_Handle, Value));
}

SB_INLINE int32_t TElCertificateLookup::get_PublicKeySizeMax()
{
	int32_t OutResult;
	SBCheckError(TElCertificateLookup_get_PublicKeySizeMax(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCertificateLookup::set_PublicKeySizeMax(int32_t Value)
{
	SBCheckError(TElCertificateLookup_set_PublicKeySizeMax(_Handle, Value));
}

TSBKeyUsage TElCertificateLookup::get_KeyUsage()
{
	TSBKeyUsageRaw OutResultRaw = 0;
	SBCheckError(TElCertificateLookup_get_KeyUsage(_Handle, &OutResultRaw));
	return (TSBKeyUsage)OutResultRaw;
}

SB_INLINE void TElCertificateLookup::set_KeyUsage(TSBKeyUsage Value)
{
	SBCheckError(TElCertificateLookup_set_KeyUsage(_Handle, (TSBKeyUsageRaw)Value));
}

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElCertificateLookup::get_EmailAddresses()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateLookup_get_EmailAddresses(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EmailAddresses)
		this->_Inst_EmailAddresses = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_EmailAddresses->updateHandle(hOutResult);
	return this->_Inst_EmailAddresses;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

SB_INLINE int32_t TElCertificateLookup::get_PublicKeyHashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElCertificateLookup_get_PublicKeyHashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCertificateLookup::set_PublicKeyHashAlgorithm(int32_t Value)
{
	SBCheckError(TElCertificateLookup_set_PublicKeyHashAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElCertificateLookup::get_CertificateHashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElCertificateLookup_get_CertificateHashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCertificateLookup::set_CertificateHashAlgorithm(int32_t Value)
{
	SBCheckError(TElCertificateLookup_set_CertificateHashAlgorithm(_Handle, Value));
}

TSBDateLookupOptions TElCertificateLookup::get_DateLookupOptions()
{
	TSBDateLookupOptionsRaw OutResultRaw = 0;
	SBCheckError(TElCertificateLookup_get_DateLookupOptions(_Handle, &OutResultRaw));
	return (TSBDateLookupOptions)OutResultRaw;
}

SB_INLINE void TElCertificateLookup::set_DateLookupOptions(TSBDateLookupOptions Value)
{
	SBCheckError(TElCertificateLookup_set_DateLookupOptions(_Handle, (TSBDateLookupOptionsRaw)Value));
}

TSBKeySizeLookupOption TElCertificateLookup::get_KeySizeLookupOption()
{
	TSBKeySizeLookupOptionRaw OutResultRaw = 0;
	SBCheckError(TElCertificateLookup_get_KeySizeLookupOption(_Handle, &OutResultRaw));
	return (TSBKeySizeLookupOption)OutResultRaw;
}

SB_INLINE void TElCertificateLookup::set_KeySizeLookupOption(TSBKeySizeLookupOption Value)
{
	SBCheckError(TElCertificateLookup_set_KeySizeLookupOption(_Handle, (TSBKeySizeLookupOptionRaw)Value));
}

TSBKeyUsageLookupOptions TElCertificateLookup::get_KeyUsageLookupOptions()
{
	TSBKeyUsageLookupOptionsRaw OutResultRaw = 0;
	SBCheckError(TElCertificateLookup_get_KeyUsageLookupOptions(_Handle, &OutResultRaw));
	return (TSBKeyUsageLookupOptions)OutResultRaw;
}

SB_INLINE void TElCertificateLookup::set_KeyUsageLookupOptions(TSBKeyUsageLookupOptions Value)
{
	SBCheckError(TElCertificateLookup_set_KeyUsageLookupOptions(_Handle, (TSBKeyUsageLookupOptionsRaw)Value));
}

void TElCertificateLookup::initInstances()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_IssuerRDN = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_SubjectRDN = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_EmailAddresses = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}

TElCertificateLookup::TElCertificateLookup(TElCertificateLookupHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElCertificateLookup::TElCertificateLookup(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCertificateLookup_Create(AOwner.getHandle(), &_Handle));
}

TElCertificateLookup::TElCertificateLookup(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCertificateLookup_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCertificateLookup::~TElCertificateLookup()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_IssuerRDN;
	this->_Inst_IssuerRDN = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_SubjectRDN;
	this->_Inst_SubjectRDN = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_EmailAddresses;
	this->_Inst_EmailAddresses = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}
#endif /* SB_USE_CLASS_TELCERTIFICATELOOKUP */

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElMemoryCertStorage::Add(TElX509Certificate &X509Certificate, bool CopyPrivateKey)
{
	SBCheckError(TElMemoryCertStorage_Add(_Handle, X509Certificate.getHandle(), (int8_t)CopyPrivateKey));
}

SB_INLINE void TElMemoryCertStorage::Add(TElX509Certificate *X509Certificate, bool CopyPrivateKey)
{
	SBCheckError(TElMemoryCertStorage_Add(_Handle, (X509Certificate != NULL) ? X509Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)CopyPrivateKey));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE void TElMemoryCertStorage::Remove(int32_t Index)
{
	SBCheckError(TElMemoryCertStorage_Remove(_Handle, Index));
}

#ifdef SB_USE_CLASS_TSBOBJECTLIST
TSBObjectList* TElMemoryCertStorage::get_CertificateList()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElMemoryCertStorage_get_CertificateList(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertificateList)
		this->_Inst_CertificateList = new TSBObjectList(hOutResult, ohFalse);
	else
		this->_Inst_CertificateList->updateHandle(hOutResult);
	return this->_Inst_CertificateList;
}
#endif /* SB_USE_CLASS_TSBOBJECTLIST */

void TElMemoryCertStorage::initInstances()
{
#ifdef SB_USE_CLASS_TSBOBJECTLIST
	this->_Inst_CertificateList = NULL;
#endif /* SB_USE_CLASS_TSBOBJECTLIST */
}

TElMemoryCertStorage::TElMemoryCertStorage(TElMemoryCertStorageHandle handle, TElOwnHandle ownHandle) : TElCustomCertStorage(handle, ownHandle)
{
	initInstances();
}

TElMemoryCertStorage::TElMemoryCertStorage(TComponent &Owner) : TElCustomCertStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMemoryCertStorage_Create(Owner.getHandle(), &_Handle));
}

TElMemoryCertStorage::TElMemoryCertStorage(TComponent *Owner) : TElCustomCertStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElMemoryCertStorage_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElMemoryCertStorage::~TElMemoryCertStorage()
{
#ifdef SB_USE_CLASS_TSBOBJECTLIST
	delete this->_Inst_CertificateList;
	this->_Inst_CertificateList = NULL;
#endif /* SB_USE_CLASS_TSBOBJECTLIST */
}
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELFILECERTSTORAGE

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TSBCertificateValidity TElFileCertStorage::Validate(TElX509Certificate &Certificate, TSBCertificateValidityReason &Reason, bool CheckCACertDates, int64_t ValidityMoment)
{
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	TSBCertificateValidityRaw OutResultRaw = 0;
	SBCheckError(TElFileCertStorage_Validate(_Handle, Certificate.getHandle(), &ReasonRaw, (int8_t)CheckCACertDates, ValidityMoment, &OutResultRaw));
	Reason = (TSBCertificateValidityReason)ReasonRaw;
	return (TSBCertificateValidity)OutResultRaw;
}

TSBCertificateValidity TElFileCertStorage::Validate(TElX509Certificate *Certificate, TSBCertificateValidityReason &Reason, bool CheckCACertDates, int64_t ValidityMoment)
{
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	TSBCertificateValidityRaw OutResultRaw = 0;
	SBCheckError(TElFileCertStorage_Validate(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &ReasonRaw, (int8_t)CheckCACertDates, ValidityMoment, &OutResultRaw));
	Reason = (TSBCertificateValidityReason)ReasonRaw;
	return (TSBCertificateValidity)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElFileCertStorage::Add(TElX509Certificate &X509Certificate, bool CopyPrivateKey)
{
	SBCheckError(TElFileCertStorage_Add(_Handle, X509Certificate.getHandle(), (int8_t)CopyPrivateKey));
}

SB_INLINE void TElFileCertStorage::Add(TElX509Certificate *X509Certificate, bool CopyPrivateKey)
{
	SBCheckError(TElFileCertStorage_Add(_Handle, (X509Certificate != NULL) ? X509Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)CopyPrivateKey));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE void TElFileCertStorage::Remove(int32_t Index)
{
	SBCheckError(TElFileCertStorage_Remove(_Handle, Index));
}

SB_INLINE void TElFileCertStorage::Clear()
{
	SBCheckError(TElFileCertStorage_Clear(_Handle));
}

SB_INLINE void TElFileCertStorage::SaveToFile(const std::string &FileName)
{
	SBCheckError(TElFileCertStorage_SaveToFile(_Handle, FileName.data(), (int32_t)FileName.length()));
}

SB_INLINE void TElFileCertStorage::Reload()
{
	SBCheckError(TElFileCertStorage_Reload(_Handle));
}

SB_INLINE void TElFileCertStorage::Save()
{
	SBCheckError(TElFileCertStorage_Save(_Handle));
}

void TElFileCertStorage::get_FileName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElFileCertStorage_get_FileName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(479027560, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElFileCertStorage::set_FileName(const std::string &Value)
{
	SBCheckError(TElFileCertStorage_set_FileName(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBFileCertStorageAccessType TElFileCertStorage::get_AccessType()
{
	TSBFileCertStorageAccessTypeRaw OutResultRaw = 0;
	SBCheckError(TElFileCertStorage_get_AccessType(_Handle, &OutResultRaw));
	return (TSBFileCertStorageAccessType)OutResultRaw;
}

SB_INLINE void TElFileCertStorage::set_AccessType(TSBFileCertStorageAccessType Value)
{
	SBCheckError(TElFileCertStorage_set_AccessType(_Handle, (TSBFileCertStorageAccessTypeRaw)Value));
}

TSBFileCertStorageSaveOptions TElFileCertStorage::get_SaveOptions()
{
	TSBFileCertStorageSaveOptionsRaw OutResultRaw = 0;
	SBCheckError(TElFileCertStorage_get_SaveOptions(_Handle, &OutResultRaw));
	return (TSBFileCertStorageSaveOptions)OutResultRaw;
}

SB_INLINE void TElFileCertStorage::set_SaveOptions(TSBFileCertStorageSaveOptions Value)
{
	SBCheckError(TElFileCertStorage_set_SaveOptions(_Handle, (TSBFileCertStorageSaveOptionsRaw)Value));
}

TElFileCertStorage::TElFileCertStorage(TElFileCertStorageHandle handle, TElOwnHandle ownHandle) : TElCustomCertStorage(handle, ownHandle)
{
}

TElFileCertStorage::TElFileCertStorage(TComponent &Owner) : TElCustomCertStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFileCertStorage_Create(Owner.getHandle(), &_Handle));
}

TElFileCertStorage::TElFileCertStorage(TComponent *Owner) : TElCustomCertStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFileCertStorage_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELFILECERTSTORAGE */

};	/* namespace SecureBlackbox */

