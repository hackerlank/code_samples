#include "sbsmimesignatures.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSMIMEMESSAGESIGNER

SB_INLINE int32_t TElSMIMEMessageSigner::Sign(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, bool Detached)
{
	int32_t OutResult;
	SBCheckError(TElSMIMEMessageSigner_Sign(_Handle, InBuffer, InSize, OutBuffer, &OutSize, (int8_t)Detached, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElSMIMEMessageSigner::Sign(TStream &InStream, TStream &OutStream, bool Detached, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElSMIMEMessageSigner_Sign_1(_Handle, InStream.getHandle(), OutStream.getHandle(), (int8_t)Detached, InCount, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSMIMEMessageSigner::Sign(TStream *InStream, TStream *OutStream, bool Detached, int64_t InCount)
{
	int32_t OutResult;
	SBCheckError(TElSMIMEMessageSigner_Sign_1(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, (int8_t)Detached, InCount, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

TElSMIMEMessageSigner::TElSMIMEMessageSigner(TElSMIMEMessageSignerHandle handle, TElOwnHandle ownHandle) : TElMessageSigner(handle, ownHandle)
{
}

TElSMIMEMessageSigner::TElSMIMEMessageSigner(TComponent &AOwner) : TElMessageSigner(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSMIMEMessageSigner_Create(AOwner.getHandle(), &_Handle));
}

TElSMIMEMessageSigner::TElSMIMEMessageSigner(TComponent *AOwner) : TElMessageSigner(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSMIMEMessageSigner_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSMIMEMESSAGESIGNER */

#ifdef SB_USE_CLASS_TELSMIMEMESSAGEVERIFIER

SB_INLINE int32_t TElSMIMEMessageVerifier::Verify(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	int32_t OutResult;
	SBCheckError(TElSMIMEMessageVerifier_Verify(_Handle, InBuffer, InSize, OutBuffer, &OutSize, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSMIMEMessageVerifier::VerifyDetached(void * Buffer, int32_t Size, void * Signature, int32_t SignatureSize)
{
	int32_t OutResult;
	SBCheckError(TElSMIMEMessageVerifier_VerifyDetached(_Handle, Buffer, Size, Signature, SignatureSize, &OutResult));
	return OutResult;
}

TElSMIMEMessageVerifier::TElSMIMEMessageVerifier(TElSMIMEMessageVerifierHandle handle, TElOwnHandle ownHandle) : TElMessageVerifier(handle, ownHandle)
{
}

TElSMIMEMessageVerifier::TElSMIMEMessageVerifier(TComponent &AOwner) : TElMessageVerifier(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSMIMEMessageVerifier_Create(AOwner.getHandle(), &_Handle));
}

TElSMIMEMessageVerifier::TElSMIMEMessageVerifier(TComponent *AOwner) : TElMessageVerifier(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSMIMEMessageVerifier_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSMIMEMESSAGEVERIFIER */

};	/* namespace SecureBlackbox */

