#ifndef __INC_SBDATASTORAGEENCODINGS
#define __INC_SBDATASTORAGEENCODINGS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstreams.h"
#include "sbdatastorage.h"
#include "sbcomprstream.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElZlibDataStorageEncodingHandlerHandle;

#ifdef SB_USE_CLASS_TELZLIBDATASTORAGEENCODINGHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElZlibDataStorageEncodingHandler_Reset(TElZlibDataStorageEncodingHandlerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZlibDataStorageEncodingHandler_GetOID(TElZlibDataStorageEncodingHandlerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZlibDataStorageEncodingHandler_GetDescription(TElZlibDataStorageEncodingHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZlibDataStorageEncodingHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZlibDataStorageEncodingHandler_get_CompressionLevel(TElZlibDataStorageEncodingHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZlibDataStorageEncodingHandler_set_CompressionLevel(TElZlibDataStorageEncodingHandlerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZlibDataStorageEncodingHandler_Create(TComponentHandle AOwner, TElCustomDataStorageEncodingHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELZLIBDATASTORAGEENCODINGHANDLER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElZlibDataStorageEncodingHandler;

#ifdef SB_USE_CLASS_TELZLIBDATASTORAGEENCODINGHANDLER
class TElZlibDataStorageEncodingHandler: public TElCustomDataStorageEncodingHandler
{
	private:
		SB_DISABLE_COPY(TElZlibDataStorageEncodingHandler)
	public:
		virtual void Reset();

		virtual void GetOID(std::vector<uint8_t> &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		virtual int32_t get_CompressionLevel();

		virtual void set_CompressionLevel(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CompressionLevel, set_CompressionLevel, TElZlibDataStorageEncodingHandler, CompressionLevel);

		TElZlibDataStorageEncodingHandler(TElZlibDataStorageEncodingHandlerHandle handle, TElOwnHandle ownHandle);

		explicit TElZlibDataStorageEncodingHandler(TComponent &AOwner);

		explicit TElZlibDataStorageEncodingHandler(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELZLIBDATASTORAGEENCODINGHANDLER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDATASTORAGEENCODINGS */

