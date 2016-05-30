#ifndef __INC_SBDCCMS
#define __INC_SBDCCMS

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
#include "sbdcdef.h"
#include "sbdcserver.h"
#include "sbdcpkiconstants.h"
#include "sbrdn.h"
#include "sbx509.h"
#include "sbasn1tree.h"
#include "sbtspclient.h"
#include "sbtspcommon.h"
#include "sbcms.h"
#include "sbstreams.h"
#include "sbcustomcertstorage.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElDCCMSSignOperationHandlerHandle;

typedef void (SB_CALLBACK *TSBDCCMSPreparedEvent)(void * _ObjectData, TObjectHandle Sender, TElSignedCMSMessageHandle Msg);

typedef void (SB_CALLBACK *TSBDCCMSTSPClientNeededEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pTSPServiceID[], int32_t szTSPServiceID, TElCustomTSPClientHandle * TSPClient, int8_t * Success);

#ifdef SB_USE_CLASS_TELDCCMSSIGNOPERATIONHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElDCCMSSignOperationHandler_get_CertStorage(TElDCCMSSignOperationHandlerHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCCMSSignOperationHandler_set_CertStorage(TElDCCMSSignOperationHandlerHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCCMSSignOperationHandler_get_OnTSPClientNeeded(TElDCCMSSignOperationHandlerHandle _Handle, TSBDCCMSTSPClientNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCCMSSignOperationHandler_set_OnTSPClientNeeded(TElDCCMSSignOperationHandlerHandle _Handle, TSBDCCMSTSPClientNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElDCCMSSignOperationHandler_get_OnCMSPrepared(TElDCCMSSignOperationHandlerHandle _Handle, TSBDCCMSPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCCMSSignOperationHandler_set_OnCMSPrepared(TElDCCMSSignOperationHandlerHandle _Handle, TSBDCCMSPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElDCCMSSignOperationHandler_Create(TElDCCMSSignOperationHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELDCCMSSIGNOPERATIONHANDLER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElDCCMSSignOperationHandler;

#ifdef SB_USE_CLASS_TELDCCMSSIGNOPERATIONHANDLER
class TElDCCMSSignOperationHandler: public TElDCSignOperationHandler
{
	private:
		SB_DISABLE_COPY(TElDCCMSSignOperationHandler)
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElDCCMSSignOperationHandler, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual void get_OnTSPClientNeeded(TSBDCCMSTSPClientNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTSPClientNeeded(TSBDCCMSTSPClientNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnCMSPrepared(TSBDCCMSPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCMSPrepared(TSBDCCMSPreparedEvent pMethodValue, void * pDataValue);

		TElDCCMSSignOperationHandler(TElDCCMSSignOperationHandlerHandle handle, TElOwnHandle ownHandle);

		TElDCCMSSignOperationHandler();

		virtual ~TElDCCMSSignOperationHandler();

};
#endif /* SB_USE_CLASS_TELDCCMSSIGNOPERATIONHANDLER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDCCMS */

