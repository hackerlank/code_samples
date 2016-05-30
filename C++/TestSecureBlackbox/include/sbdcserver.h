#ifndef __INC_SBDCSERVER
#define __INC_SBDCSERVER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstringlist.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbstreams.h"
#include "sbrdn.h"
#include "sbdc.h"
#include "sbdcenc.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElDCOperationHandlerHandle;

typedef TElClassHandle TElDCSignOperationHandlerHandle;

typedef TElClassHandle TElDCGenericSignOperationHandlerHandle;

typedef TElClassHandle TElDCStandardServerHandle;

typedef void (SB_CALLBACK *TSBDCSignRequestEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pData[], int32_t szData, const uint8_t pHashAlg[], int32_t szHashAlg, int8_t IncludeKeys, TElRelativeDistinguishedNameHandle InputPars, TElRelativeDistinguishedNameHandle Keys, TElRelativeDistinguishedNameHandle OutputPars, uint8_t pSignResult[], int32_t * szSignResult);

#ifdef SB_USE_CLASS_TELDCOPERATIONHANDLER
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationHandler_get_AcceptedOperationIDs(TElDCOperationHandlerHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationHandler_get_AcceptedOperationIDs(TElDCOperationHandlerHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElDCOperationHandler_Create(TElDCOperationHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELDCOPERATIONHANDLER */

#ifdef SB_USE_CLASS_TELDCSIGNOPERATIONHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElDCSignOperationHandler_get_OnSignRequest(TElDCSignOperationHandlerHandle _Handle, TSBDCSignRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCSignOperationHandler_set_OnSignRequest(TElDCSignOperationHandlerHandle _Handle, TSBDCSignRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElDCSignOperationHandler_Create(TElDCOperationHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELDCSIGNOPERATIONHANDLER */

#ifdef SB_USE_CLASS_TELDCGENERICSIGNOPERATIONHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElDCGenericSignOperationHandler_Create(TElDCOperationHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELDCGENERICSIGNOPERATIONHANDLER */

#ifdef SB_USE_CLASS_TELDCSTANDARDSERVER
SB_IMPORT uint32_t SB_APIENTRY TElDCStandardServer_Process(TElDCStandardServerHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, TElDCEncodingHandle InEncoding, TElDCEncodingHandle OutEncoding);
SB_IMPORT uint32_t SB_APIENTRY TElDCStandardServer_AddOperationHandler(TElDCStandardServerHandle _Handle, TElDCOperationHandlerHandle Handler, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCStandardServer_RemoveOperationHandler(TElDCStandardServerHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElDCStandardServer_ClearOperationHandlers(TElDCStandardServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDCStandardServer_get_OperationHandlers(TElDCStandardServerHandle _Handle, int32_t Index, TElDCOperationHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCStandardServer_get_OperationHandlerCount(TElDCStandardServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCStandardServer_Create(TElDCStandardServerHandle * OutResult);
#endif /* SB_USE_CLASS_TELDCSTANDARDSERVER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElDCOperationHandler;
class TElDCSignOperationHandler;
class TElDCGenericSignOperationHandler;
class TElDCStandardServer;

#ifdef SB_USE_CLASS_TELDCOPERATIONHANDLER
class TElDCOperationHandler: public TObject
{
	private:
		SB_DISABLE_COPY(TElDCOperationHandler)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_AcceptedOperationIDs;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_AcceptedOperationIDs;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_AcceptedOperationIDs();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_AcceptedOperationIDs, TElDCOperationHandler, AcceptedOperationIDs);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_AcceptedOperationIDs();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_AcceptedOperationIDs, TElDCOperationHandler, AcceptedOperationIDs);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		TElDCOperationHandler(TElDCOperationHandlerHandle handle, TElOwnHandle ownHandle);

		TElDCOperationHandler();

		virtual ~TElDCOperationHandler();

};
#endif /* SB_USE_CLASS_TELDCOPERATIONHANDLER */

#ifdef SB_USE_CLASS_TELDCSIGNOPERATIONHANDLER
class TElDCSignOperationHandler: public TElDCOperationHandler
{
	private:
		SB_DISABLE_COPY(TElDCSignOperationHandler)
	public:
		virtual void get_OnSignRequest(TSBDCSignRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSignRequest(TSBDCSignRequestEvent pMethodValue, void * pDataValue);

		TElDCSignOperationHandler(TElDCSignOperationHandlerHandle handle, TElOwnHandle ownHandle);

		TElDCSignOperationHandler();

};
#endif /* SB_USE_CLASS_TELDCSIGNOPERATIONHANDLER */

#ifdef SB_USE_CLASS_TELDCGENERICSIGNOPERATIONHANDLER
class TElDCGenericSignOperationHandler: public TElDCSignOperationHandler
{
	private:
		SB_DISABLE_COPY(TElDCGenericSignOperationHandler)
	public:
		TElDCGenericSignOperationHandler(TElDCGenericSignOperationHandlerHandle handle, TElOwnHandle ownHandle);

		TElDCGenericSignOperationHandler();

};
#endif /* SB_USE_CLASS_TELDCGENERICSIGNOPERATIONHANDLER */

#ifdef SB_USE_CLASS_TELDCSTANDARDSERVER
class TElDCStandardServer: public TObject
{
	private:
		SB_DISABLE_COPY(TElDCStandardServer)
#ifdef SB_USE_CLASS_TELDCOPERATIONHANDLER
		TElDCOperationHandler* _Inst_OperationHandlers;
#endif /* SB_USE_CLASS_TELDCOPERATIONHANDLER */

		void initInstances();

	public:
#ifdef SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM
		void Process(TStream &InStream, TStream &OutStream, TElDCEncoding &InEncoding, TElDCEncoding &OutEncoding);

		void Process(TStream *InStream, TStream *OutStream, TElDCEncoding *InEncoding, TElDCEncoding *OutEncoding);
#endif /* SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELDCOPERATIONHANDLER
		int32_t AddOperationHandler(TElDCOperationHandler &Handler);

		int32_t AddOperationHandler(TElDCOperationHandler *Handler);
#endif /* SB_USE_CLASS_TELDCOPERATIONHANDLER */

		void RemoveOperationHandler(int32_t Index);

		void ClearOperationHandlers();

#ifdef SB_USE_CLASS_TELDCOPERATIONHANDLER
		virtual TElDCOperationHandler* get_OperationHandlers(int32_t Index);
#endif /* SB_USE_CLASS_TELDCOPERATIONHANDLER */

		virtual int32_t get_OperationHandlerCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_OperationHandlerCount, TElDCStandardServer, OperationHandlerCount);

		TElDCStandardServer(TElDCStandardServerHandle handle, TElOwnHandle ownHandle);

		TElDCStandardServer();

		virtual ~TElDCStandardServer();

};
#endif /* SB_USE_CLASS_TELDCSTANDARDSERVER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDCSERVER */
