#include "sbcrlex.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLISTEX

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE int32_t TElCertificateRevocationListEx::SaveToBuffer(void * Buffer, int32_t &Size, TElX509Certificate &Certificate)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationListEx_SaveToBuffer(_Handle, Buffer, &Size, Certificate.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCertificateRevocationListEx::SaveToBuffer(void * Buffer, int32_t &Size, TElX509Certificate *Certificate)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationListEx_SaveToBuffer(_Handle, Buffer, &Size, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE int32_t TElCertificateRevocationListEx::SaveToBufferPEM(void * Buffer, int32_t &Size, TElX509Certificate &Certificate, const std::string &Passphrase)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationListEx_SaveToBufferPEM(_Handle, Buffer, &Size, Certificate.getHandle(), Passphrase.data(), (int32_t)Passphrase.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCertificateRevocationListEx::SaveToBufferPEM(void * Buffer, int32_t &Size, TElX509Certificate *Certificate, const std::string &Passphrase)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationListEx_SaveToBufferPEM(_Handle, Buffer, &Size, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, Passphrase.data(), (int32_t)Passphrase.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
int32_t TElCertificateRevocationListEx::SaveToBufferPEM(std::vector<uint8_t> &Buffer, TElX509Certificate &Certificate, const std::string &Passphrase)
{
	int32_t OutResult;
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = TElCertificateRevocationListEx_SaveToBufferPEM_1(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Certificate.getHandle(), Passphrase.data(), (int32_t)Passphrase.length(), &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-597021365, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return OutResult;
}

int32_t TElCertificateRevocationListEx::SaveToBufferPEM(std::vector<uint8_t> &Buffer, TElX509Certificate *Certificate, const std::string &Passphrase)
{
	int32_t OutResult;
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = TElCertificateRevocationListEx_SaveToBufferPEM_1(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, Passphrase.data(), (int32_t)Passphrase.length(), &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-597021365, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TSTREAM
SB_INLINE int32_t TElCertificateRevocationListEx::SaveToStream(TStream &Stream, TElX509Certificate &Certificate)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationListEx_SaveToStream(_Handle, Stream.getHandle(), Certificate.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCertificateRevocationListEx::SaveToStream(TStream *Stream, TElX509Certificate *Certificate)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationListEx_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TSTREAM
SB_INLINE int32_t TElCertificateRevocationListEx::SaveToStreamPEM(TStream &Stream, TElX509Certificate &Certificate, const std::string &Passphrase)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationListEx_SaveToStreamPEM(_Handle, Stream.getHandle(), Certificate.getHandle(), Passphrase.data(), (int32_t)Passphrase.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCertificateRevocationListEx::SaveToStreamPEM(TStream *Stream, TElX509Certificate *Certificate, const std::string &Passphrase)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationListEx_SaveToStreamPEM(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, Passphrase.data(), (int32_t)Passphrase.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TSTREAM */

SB_INLINE int32_t TElCertificateRevocationListEx::get_PreferredHashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationListEx_get_PreferredHashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCertificateRevocationListEx::set_PreferredHashAlgorithm(int32_t Value)
{
	SBCheckError(TElCertificateRevocationListEx_set_PreferredHashAlgorithm(_Handle, Value));
}

TElCertificateRevocationListEx::TElCertificateRevocationListEx(TElCertificateRevocationListExHandle handle, TElOwnHandle ownHandle) : TElCertificateRevocationList(handle, ownHandle)
{
}

TElCertificateRevocationListEx::TElCertificateRevocationListEx(TComponent &Owner) : TElCertificateRevocationList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCertificateRevocationListEx_Create(Owner.getHandle(), &_Handle));
}

TElCertificateRevocationListEx::TElCertificateRevocationListEx(TComponent *Owner) : TElCertificateRevocationList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCertificateRevocationListEx_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLISTEX */

};	/* namespace SecureBlackbox */

