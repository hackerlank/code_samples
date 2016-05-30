#include "sbx509ex.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELX509CERTIFICATEEX

void TElX509CertificateEx::WriteIssuer(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElX509CertificateEx_WriteIssuer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1055420259, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElX509CertificateEx::WriteSubject(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElX509CertificateEx_WriteSubject(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-119655019, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElX509CertificateEx::SetIssuer(const TName &Issuer)
{
	SBCheckError(TElX509CertificateEx_SetIssuer(_Handle, &Issuer));
}

SB_INLINE void TElX509CertificateEx::SetSubject(const TName &Subject)
{
	SBCheckError(TElX509CertificateEx_SetSubject(_Handle, &Subject));
}

SB_INLINE void TElX509CertificateEx::SetLongSerialNumber(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElX509CertificateEx_SetLongSerialNumber(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE void TElX509CertificateEx::Generate(int32_t Algorithm, int32_t DWordsInEncryptKey)
{
	SBCheckError(TElX509CertificateEx_Generate(_Handle, Algorithm, DWordsInEncryptKey));
}

#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST
SB_INLINE void TElX509CertificateEx::Generate(TElCertificateRequest &Request, TElX509CertificateEx &Certificate)
{
	SBCheckError(TElX509CertificateEx_Generate_1(_Handle, Request.getHandle(), Certificate.getHandle()));
}

SB_INLINE void TElX509CertificateEx::Generate(TElCertificateRequest *Request, TElX509CertificateEx *Certificate)
{
	SBCheckError(TElX509CertificateEx_Generate_1(_Handle, (Request != NULL) ? Request->getHandle() : SB_NULL_HANDLE, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */

#ifdef SB_USE_CLASSES_TELALGORITHMIDENTIFIER_AND_TELCERTIFICATEREQUEST
SB_INLINE void TElX509CertificateEx::Generate(TElCertificateRequest &Request, TElX509CertificateEx &Certificate, TElAlgorithmIdentifier &SignatureAlgorithm)
{
	SBCheckError(TElX509CertificateEx_Generate_2(_Handle, Request.getHandle(), Certificate.getHandle(), SignatureAlgorithm.getHandle()));
}

SB_INLINE void TElX509CertificateEx::Generate(TElCertificateRequest *Request, TElX509CertificateEx *Certificate, TElAlgorithmIdentifier *SignatureAlgorithm)
{
	SBCheckError(TElX509CertificateEx_Generate_2(_Handle, (Request != NULL) ? Request->getHandle() : SB_NULL_HANDLE, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (SignatureAlgorithm != NULL) ? SignatureAlgorithm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELALGORITHMIDENTIFIER_AND_TELCERTIFICATEREQUEST */

SB_INLINE void TElX509CertificateEx::Generate(TElX509Certificate &Parent, int32_t Algorithm, int32_t DWordsInEncryptKey)
{
	SBCheckError(TElX509CertificateEx_Generate_3(_Handle, Parent.getHandle(), Algorithm, DWordsInEncryptKey));
}

SB_INLINE void TElX509CertificateEx::Generate(TElX509Certificate *Parent, int32_t Algorithm, int32_t DWordsInEncryptKey)
{
	SBCheckError(TElX509CertificateEx_Generate_3(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, Algorithm, DWordsInEncryptKey));
}

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElX509CertificateEx::Generate(TElAlgorithmIdentifier &KeyAlgorithm, TElAlgorithmIdentifier &SignatureAlgorithm, int32_t Bits)
{
	SBCheckError(TElX509CertificateEx_Generate_4(_Handle, KeyAlgorithm.getHandle(), SignatureAlgorithm.getHandle(), Bits));
}

SB_INLINE void TElX509CertificateEx::Generate(TElAlgorithmIdentifier *KeyAlgorithm, TElAlgorithmIdentifier *SignatureAlgorithm, int32_t Bits)
{
	SBCheckError(TElX509CertificateEx_Generate_4(_Handle, (KeyAlgorithm != NULL) ? KeyAlgorithm->getHandle() : SB_NULL_HANDLE, (SignatureAlgorithm != NULL) ? SignatureAlgorithm->getHandle() : SB_NULL_HANDLE, Bits));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_INLINE void TElX509CertificateEx::Generate(TElX509Certificate &Parent, TElAlgorithmIdentifier &KeyAlgorithm, TElAlgorithmIdentifier &SignatureAlgorithm, int32_t Bits)
{
	SBCheckError(TElX509CertificateEx_Generate_5(_Handle, Parent.getHandle(), KeyAlgorithm.getHandle(), SignatureAlgorithm.getHandle(), Bits));
}

SB_INLINE void TElX509CertificateEx::Generate(TElX509Certificate *Parent, TElAlgorithmIdentifier *KeyAlgorithm, TElAlgorithmIdentifier *SignatureAlgorithm, int32_t Bits)
{
	SBCheckError(TElX509CertificateEx_Generate_5(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, (KeyAlgorithm != NULL) ? KeyAlgorithm->getHandle() : SB_NULL_HANDLE, (SignatureAlgorithm != NULL) ? SignatureAlgorithm->getHandle() : SB_NULL_HANDLE, Bits));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

SB_INLINE void TElX509CertificateEx::CAGenerate(int32_t Algorithm, int32_t DWordsInEncryptKey)
{
	SBCheckError(TElX509CertificateEx_CAGenerate(_Handle, Algorithm, DWordsInEncryptKey));
}

SB_INLINE void TElX509CertificateEx::BeginGenerate(int32_t Algorithm, int32_t DWordsInEncryptKey)
{
	SBCheckError(TElX509CertificateEx_BeginGenerate(_Handle, Algorithm, DWordsInEncryptKey));
}

SB_INLINE void TElX509CertificateEx::BeginGenerate(TElX509Certificate &Parent, int32_t Algorithm, int32_t DWordsInEncryptKey)
{
	SBCheckError(TElX509CertificateEx_BeginGenerate_1(_Handle, Parent.getHandle(), Algorithm, DWordsInEncryptKey));
}

SB_INLINE void TElX509CertificateEx::BeginGenerate(TElX509Certificate *Parent, int32_t Algorithm, int32_t DWordsInEncryptKey)
{
	SBCheckError(TElX509CertificateEx_BeginGenerate_1(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, Algorithm, DWordsInEncryptKey));
}

SB_INLINE void TElX509CertificateEx::EndGenerate()
{
	SBCheckError(TElX509CertificateEx_EndGenerate(_Handle));
}

SB_INLINE void TElX509CertificateEx::CancelGeneration()
{
	SBCheckError(TElX509CertificateEx_CancelGeneration(_Handle));
}

bool TElX509CertificateEx::AsyncOperationFinished()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateEx_AsyncOperationFinished(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateEx::SetCACertificate(void * Buffer, int32_t Size)
{
	SBCheckError(TElX509CertificateEx_SetCACertificate(_Handle, Buffer, Size));
}

SB_INLINE void TElX509CertificateEx::SetCACertificate(TElX509Certificate &Cert)
{
	SBCheckError(TElX509CertificateEx_SetCACertificate_1(_Handle, Cert.getHandle()));
}

SB_INLINE void TElX509CertificateEx::SetCACertificate(TElX509Certificate *Cert)
{
	SBCheckError(TElX509CertificateEx_SetCACertificate_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElX509CertificateEx::SetCAPrivateKey(void * Buffer, int32_t Size)
{
	SBCheckError(TElX509CertificateEx_SetCAPrivateKey(_Handle, Buffer, Size));
}

bool TElX509CertificateEx::Sign(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, bool Detached, bool IncludeCertificates)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateEx_Sign(_Handle, InBuffer, InSize, OutBuffer, &OutSize, (int8_t)Detached, (int8_t)IncludeCertificates, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElX509CertificateEx::Verify(void * InBuffer, int32_t InSize, void * Signature, int32_t SignatureSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateEx_Verify(_Handle, InBuffer, InSize, Signature, SignatureSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TClassHandle TElX509CertificateEx::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElX509CertificateEx_ClassType(&OutResult));
	return OutResult;
}

bool TElX509CertificateEx::get_PreserveKeyMaterial()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateEx_get_PreserveKeyMaterial(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateEx::set_PreserveKeyMaterial(bool Value)
{
	SBCheckError(TElX509CertificateEx_set_PreserveKeyMaterial(_Handle, (int8_t)Value));
}

void TElX509CertificateEx::get_AltKeyID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElX509CertificateEx_get_AltKeyID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2138353442, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElX509CertificateEx::set_AltKeyID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElX509CertificateEx_set_AltKeyID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElX509CertificateEx::get_PreferredHashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElX509CertificateEx_get_PreferredHashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElX509CertificateEx::set_PreferredHashAlgorithm(int32_t Value)
{
	SBCheckError(TElX509CertificateEx_set_PreferredHashAlgorithm(_Handle, Value));
}

bool TElX509CertificateEx::get_SaveDefaultASN1Tags()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElX509CertificateEx_get_SaveDefaultASN1Tags(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElX509CertificateEx::set_SaveDefaultASN1Tags(bool Value)
{
	SBCheckError(TElX509CertificateEx_set_SaveDefaultASN1Tags(_Handle, (int8_t)Value));
}

TElX509CertificateEx::TElX509CertificateEx(TElX509CertificateExHandle handle, TElOwnHandle ownHandle) : TElX509Certificate(handle, ownHandle)
{
}

TElX509CertificateEx::TElX509CertificateEx(TComponent &Owner) : TElX509Certificate(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElX509CertificateEx_Create(Owner.getHandle(), &_Handle));
}

TElX509CertificateEx::TElX509CertificateEx(TComponent *Owner) : TElX509Certificate(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElX509CertificateEx_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELX509CERTIFICATEEX */

};	/* namespace SecureBlackbox */

