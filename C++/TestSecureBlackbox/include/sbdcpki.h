#ifndef __INC_SBDCPKI
#define __INC_SBDCPKI

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbdc.h"
#include "sbdcserver.h"
#include "sbdcpkiconstants.h"
#include "sbrdn.h"
#include "sbx509.h"
#include "sbasn1tree.h"
#include "sbcustomcrypto.h"
#include "sbpublickeycrypto.h"
#include "sbcustomcertstorage.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElDCX509SignOperationHandlerHandle;

#ifdef SB_USE_CLASS_TELDCX509SIGNOPERATIONHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElDCX509SignOperationHandler_get_CertStorage(TElDCX509SignOperationHandlerHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCX509SignOperationHandler_set_CertStorage(TElDCX509SignOperationHandlerHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCX509SignOperationHandler_Create(TElDCX509SignOperationHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELDCX509SIGNOPERATIONHANDLER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElDCX509SignOperationHandler;

#ifdef SB_USE_CLASS_TELDCX509SIGNOPERATIONHANDLER
class TElDCX509SignOperationHandler: public TElDCSignOperationHandler
{
	private:
		SB_DISABLE_COPY(TElDCX509SignOperationHandler)
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElDCX509SignOperationHandler, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		TElDCX509SignOperationHandler(TElDCX509SignOperationHandlerHandle handle, TElOwnHandle ownHandle);

		TElDCX509SignOperationHandler();

		virtual ~TElDCX509SignOperationHandler();

};
#endif /* SB_USE_CLASS_TELDCX509SIGNOPERATIONHANDLER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDCPKI */

