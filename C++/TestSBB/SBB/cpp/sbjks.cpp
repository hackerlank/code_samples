#include "sbjks.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELJKS

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElJKS::LoadFromStream(TStream &Stream, const std::string &JKS_Pass)
{
	int32_t OutResult;
	SBCheckError(TElJKS_LoadFromStream(_Handle, Stream.getHandle(), JKS_Pass.data(), (int32_t)JKS_Pass.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElJKS::LoadFromStream(TStream *Stream, const std::string &JKS_Pass)
{
	int32_t OutResult;
	SBCheckError(TElJKS_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, JKS_Pass.data(), (int32_t)JKS_Pass.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElJKS::LoadFromBuffer(void * Src_Ptr, int32_t BufferSize, int32_t &BufferPos, const std::string &JKS_Pass)
{
	int32_t OutResult;
	SBCheckError(TElJKS_LoadFromBuffer(_Handle, Src_Ptr, BufferSize, &BufferPos, JKS_Pass.data(), (int32_t)JKS_Pass.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElJKS::GetSaveBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElJKS_GetSaveBufferSize(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElJKS::SaveToStream(TStream &Stream, const std::string &JKS_Pass)
{
	int32_t OutResult;
	SBCheckError(TElJKS_SaveToStream(_Handle, Stream.getHandle(), JKS_Pass.data(), (int32_t)JKS_Pass.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElJKS::SaveToStream(TStream *Stream, const std::string &JKS_Pass)
{
	int32_t OutResult;
	SBCheckError(TElJKS_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, JKS_Pass.data(), (int32_t)JKS_Pass.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

int32_t TElJKS::SaveToBuffer(std::vector<uint8_t> &DstBuffer, int32_t BufferSize, int32_t &BufferPos, const std::string &JKS_Pass)
{
	int32_t OutResult;
	int32_t szDstBuffer = (int32_t)DstBuffer.size();
	uint32_t _err = TElJKS_SaveToBuffer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(DstBuffer), &szDstBuffer, BufferSize, &BufferPos, JKS_Pass.data(), (int32_t)JKS_Pass.length(), &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		DstBuffer.resize(szDstBuffer);
		SBCheckError(SBGetLastReturnBuffer(-1956113573, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(DstBuffer), &szDstBuffer));
	}
	else
		SBCheckError(_err);

	DstBuffer.resize(szDstBuffer);
	return OutResult;
}

bool TElJKS::GetPrivateKey(int32_t Index, const std::string &Pass, std::vector<uint8_t> &Key)
{
	int32_t szKey = (int32_t)Key.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElJKS_GetPrivateKey(_Handle, Index, Pass.data(), (int32_t)Pass.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Key), &szKey, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Key.resize(szKey);
		SBCheckError(SBGetLastReturnBuffer(1872655427, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Key), &szKey));
	}
	else
		SBCheckError(_err);

	Key.resize(szKey);
	return (OutResultRaw != 0);
}

bool TElJKS::SetPrivateKey(int32_t Index, const std::string &Pass, const std::vector<uint8_t> &Key)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElJKS_SetPrivateKey(_Handle, Index, Pass.data(), (int32_t)Pass.length(), SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElJKS::AddPrivateKey(const std::string &Pass, const std::vector<uint8_t> &Key)
{
	int32_t OutResult;
	SBCheckError(TElJKS_AddPrivateKey(_Handle, Pass.data(), (int32_t)Pass.length(), SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE TElX509CertificateHandle TElJKS::GetKeyCertificate(int32_t Index, int32_t Cert_Index)
{
	TElX509CertificateHandle OutResult;
	SBCheckError(TElJKS_GetKeyCertificate(_Handle, Index, Cert_Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE int32_t TElJKS::AddKeyCertificate(int32_t Index, TElX509Certificate &Cert)
{
	int32_t OutResult;
	SBCheckError(TElJKS_AddKeyCertificate(_Handle, Index, Cert.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElJKS::AddKeyCertificate(int32_t Index, TElX509Certificate *Cert)
{
	int32_t OutResult;
	SBCheckError(TElJKS_AddKeyCertificate(_Handle, Index, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE void TElJKS::DelKeyCertificate(int32_t Index, int32_t Cert_Index)
{
	SBCheckError(TElJKS_DelKeyCertificate(_Handle, Index, Cert_Index));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE TElX509CertificateHandle TElJKS::GetTrustedCertificate(int32_t Index)
{
	TElX509CertificateHandle OutResult;
	SBCheckError(TElJKS_GetTrustedCertificate(_Handle, Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE int32_t TElJKS::AddTrustedCertificate(TElX509Certificate &Cert)
{
	int32_t OutResult;
	SBCheckError(TElJKS_AddTrustedCertificate(_Handle, Cert.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElJKS::AddTrustedCertificate(TElX509Certificate *Cert)
{
	int32_t OutResult;
	SBCheckError(TElJKS_AddTrustedCertificate(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE void TElJKS::DelTrustedCertificate(int32_t Index)
{
	SBCheckError(TElJKS_DelTrustedCertificate(_Handle, Index));
}

void TElJKS::GetAlias(int32_t Index, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElJKS_GetAlias(_Handle, Index, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1384838685, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElJKS::SetAlias(int32_t Index, const std::string &Alias)
{
	SBCheckError(TElJKS_SetAlias(_Handle, Index, Alias.data(), (int32_t)Alias.length()));
}

SB_INLINE int32_t TElJKS::get_Entries_Count()
{
	int32_t OutResult;
	SBCheckError(TElJKS_get_Entries_Count(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElJKS::get_PrivateKeyCert_Count(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TElJKS_get_PrivateKeyCert_Count(_Handle, Index, &OutResult));
	return OutResult;
}

bool TElJKS::get_IsPrivateKey(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElJKS_get_IsPrivateKey(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElJKS::get_IgnoreBadStorageSignature()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElJKS_get_IgnoreBadStorageSignature(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElJKS::set_IgnoreBadStorageSignature(bool Value)
{
	SBCheckError(TElJKS_set_IgnoreBadStorageSignature(_Handle, (int8_t)Value));
}

TElJKS::TElJKS(TElJKSHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElJKS::TElJKS() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElJKS_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELJKS */

};	/* namespace SecureBlackbox */

