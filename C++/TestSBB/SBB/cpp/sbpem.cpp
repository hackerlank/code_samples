#include "sbpem.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPEMPROCESSOR

bool TElPEMProcessor::PEMEncode(const std::vector<uint8_t> &InBuffer, std::vector<uint8_t> &OutBuffer, bool Encrypt)
{
	int32_t szOutBuffer = (int32_t)OutBuffer.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElPEMProcessor_PEMEncode(_Handle, SB_STD_VECTOR_FRONT_ADR(InBuffer), (int32_t)InBuffer.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer, (int8_t)Encrypt, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuffer.resize(szOutBuffer);
		SBCheckError(SBGetLastReturnBuffer(-297683313, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer));
	}
	else
		SBCheckError(_err);

	OutBuffer.resize(szOutBuffer);
	return (OutResultRaw != 0);
}

bool TElPEMProcessor::PEMEncode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, bool Encrypt)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPEMProcessor_PEMEncode_1(_Handle, InBuffer, InSize, OutBuffer, &OutSize, (int8_t)Encrypt, &OutResultRaw));
	return (OutResultRaw != 0);
}

int32_t TElPEMProcessor::PEMDecode(const std::vector<uint8_t> &InBuffer, std::vector<uint8_t> &OutBuffer)
{
	int32_t OutResult;
	int32_t szOutBuffer = (int32_t)OutBuffer.size();
	uint32_t _err = TElPEMProcessor_PEMDecode(_Handle, SB_STD_VECTOR_FRONT_ADR(InBuffer), (int32_t)InBuffer.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuffer.resize(szOutBuffer);
		SBCheckError(SBGetLastReturnBuffer(751372596, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer));
	}
	else
		SBCheckError(_err);

	OutBuffer.resize(szOutBuffer);
	return OutResult;
}

SB_INLINE int32_t TElPEMProcessor::PEMDecode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	int32_t OutResult;
	SBCheckError(TElPEMProcessor_PEMDecode_1(_Handle, InBuffer, InSize, OutBuffer, &OutSize, &OutResult));
	return OutResult;
}

void TElPEMProcessor::get_Header(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPEMProcessor_get_Header(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(943463020, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPEMProcessor::set_Header(const std::string &Value)
{
	SBCheckError(TElPEMProcessor_set_Header(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPEMProcessor::get_Passphrase(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPEMProcessor_get_Passphrase(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(107004307, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPEMProcessor::set_Passphrase(const std::string &Value)
{
	SBCheckError(TElPEMProcessor_set_Passphrase(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElPEMProcessor::get_EncryptionAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPEMProcessor_get_EncryptionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPEMProcessor::set_EncryptionAlgorithm(int32_t Value)
{
	SBCheckError(TElPEMProcessor_set_EncryptionAlgorithm(_Handle, Value));
}

TSBSymmetricCryptoMode TElPEMProcessor::get_EncryptionMode()
{
	TSBSymmetricCryptoModeRaw OutResultRaw = 0;
	SBCheckError(TElPEMProcessor_get_EncryptionMode(_Handle, &OutResultRaw));
	return (TSBSymmetricCryptoMode)OutResultRaw;
}

SB_INLINE void TElPEMProcessor::set_EncryptionMode(TSBSymmetricCryptoMode Value)
{
	SBCheckError(TElPEMProcessor_set_EncryptionMode(_Handle, (TSBSymmetricCryptoModeRaw)Value));
}

TElPEMProcessor::TElPEMProcessor(TElPEMProcessorHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElPEMProcessor::TElPEMProcessor(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPEMProcessor_Create(AOwner.getHandle(), &_Handle));
}

TElPEMProcessor::TElPEMProcessor(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPEMProcessor_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELPEMPROCESSOR */

#ifdef SB_USE_GLOBAL_PROCS_PEM

bool Encode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, const std::string &Header, bool Encrypt, const std::string &PassPhrase)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPEM_Encode(InBuffer, InSize, OutBuffer, &OutSize, Header.data(), (int32_t)Header.length(), (int8_t)Encrypt, PassPhrase.data(), (int32_t)PassPhrase.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool EncodeEx(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, const std::string &Header, int32_t EncryptionAlgorithm, const std::string &PassPhrase)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPEM_EncodeEx(InBuffer, InSize, OutBuffer, &OutSize, Header.data(), (int32_t)Header.length(), EncryptionAlgorithm, PassPhrase.data(), (int32_t)PassPhrase.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool EncodeEx(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, const std::string &Header, int32_t EncryptionAlgorithm, TSBSymmetricCryptoMode EncryptionMode, const std::string &PassPhrase)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPEM_EncodeEx_1(InBuffer, InSize, OutBuffer, &OutSize, Header.data(), (int32_t)Header.length(), EncryptionAlgorithm, (TSBSymmetricCryptoModeRaw)EncryptionMode, PassPhrase.data(), (int32_t)PassPhrase.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

int32_t Decode(void * InBuffer, int32_t InSize, void * OutBuffer, const std::string &PassPhrase, int32_t &OutSize, std::string &Header)
{
	int32_t OutResult;
	int32_t szHeader = (int32_t)Header.length();
	uint32_t _err = SBPEM_Decode(InBuffer, InSize, OutBuffer, PassPhrase.data(), (int32_t)PassPhrase.length(), &OutSize, (char *)Header.data(), &szHeader, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Header.resize(szHeader);
		SBCheckError(SBGetLastReturnStringA(-988907671, 5, (char *)Header.data(), &szHeader));
	}
	else
		SBCheckError(_err);

	Header.resize(szHeader);
	return OutResult;
}

bool IsBase64UnicodeSequence(void * Buffer, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPEM_IsBase64UnicodeSequence(Buffer, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsBase64Sequence(void * Buffer, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPEM_IsBase64Sequence(Buffer, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsPEMSequence(void * Buffer, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPEM_IsPEMSequence(Buffer, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void RaisePEMError(int32_t ErrorCode)
{
	SBCheckError(SBPEM_RaisePEMError(ErrorCode));
}

#endif /* SB_USE_GLOBAL_PROCS_PEM */

};	/* namespace SecureBlackbox */

