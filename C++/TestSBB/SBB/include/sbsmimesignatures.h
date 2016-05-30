#ifndef __INC_SBSMIMESIGNATURES
#define __INC_SBSMIMESIGNATURES

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbmessages.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbstreams.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_MESSAGE_ERROR_INVALID_MESSAGE_DIGEST 	8272
#define SB_MESSAGE_WARNING_OMITTED_MESSAGE_DIGEST 	8273

typedef TElClassHandle TElSMIMEMessageSignerHandle;

typedef TElSMIMEMessageSignerHandle ElSMIMEMessageSignerHandle;

typedef TElClassHandle TElSMIMEMessageVerifierHandle;

typedef TElSMIMEMessageVerifierHandle ElSMIMEMessageVerifierHandle;

#ifdef SB_USE_CLASS_TELSMIMEMESSAGESIGNER
SB_IMPORT uint32_t SB_APIENTRY TElSMIMEMessageSigner_Sign(TElSMIMEMessageSignerHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int8_t Detached, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMIMEMessageSigner_Sign_1(TElSMIMEMessageSignerHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int8_t Detached, int64_t InCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMIMEMessageSigner_Create(TComponentHandle AOwner, TElMessageSignerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSMIMEMESSAGESIGNER */

#ifdef SB_USE_CLASS_TELSMIMEMESSAGEVERIFIER
SB_IMPORT uint32_t SB_APIENTRY TElSMIMEMessageVerifier_Verify(TElSMIMEMessageVerifierHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMIMEMessageVerifier_VerifyDetached(TElSMIMEMessageVerifierHandle _Handle, void * Buffer, int32_t Size, void * Signature, int32_t SignatureSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSMIMEMessageVerifier_Create(TComponentHandle AOwner, TElMessageVerifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELSMIMEMESSAGEVERIFIER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSMIMEMessageSigner;
typedef TElSMIMEMessageSigner ElSMIMEMessageSigner;
class TElSMIMEMessageVerifier;
typedef TElSMIMEMessageVerifier ElSMIMEMessageVerifier;

#ifdef SB_USE_CLASS_TELSMIMEMESSAGESIGNER
class TElSMIMEMessageSigner: public TElMessageSigner
{
	private:
		SB_DISABLE_COPY(TElSMIMEMessageSigner)
	public:
		virtual int32_t Sign(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, bool Detached);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t Sign(TStream &InStream, TStream &OutStream, bool Detached, int64_t InCount);

		virtual int32_t Sign(TStream *InStream, TStream *OutStream, bool Detached, int64_t InCount);
#endif /* SB_USE_CLASS_TSTREAM */

		TElSMIMEMessageSigner(TElSMIMEMessageSignerHandle handle, TElOwnHandle ownHandle);

		explicit TElSMIMEMessageSigner(TComponent &AOwner);

		explicit TElSMIMEMessageSigner(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELSMIMEMESSAGESIGNER */

#ifdef SB_USE_CLASS_TELSMIMEMESSAGEVERIFIER
class TElSMIMEMessageVerifier: public TElMessageVerifier
{
	private:
		SB_DISABLE_COPY(TElSMIMEMessageVerifier)
	public:
		virtual int32_t Verify(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

		virtual int32_t VerifyDetached(void * Buffer, int32_t Size, void * Signature, int32_t SignatureSize);

		TElSMIMEMessageVerifier(TElSMIMEMessageVerifierHandle handle, TElOwnHandle ownHandle);

		explicit TElSMIMEMessageVerifier(TComponent &AOwner);

		explicit TElSMIMEMessageVerifier(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELSMIMEMESSAGEVERIFIER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSMIMESIGNATURES */

