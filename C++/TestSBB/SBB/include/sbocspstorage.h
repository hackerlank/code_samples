#ifndef __INC_SBOCSPSTORAGE
#define __INC_SBOCSPSTORAGE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbocspcommon.h"
#include "sbocspclient.h"
#include "sbpkicommon.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElOCSPResponseStorageHandle;

#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponseStorage_Add(TElOCSPResponseStorageHandle _Handle, TElOCSPResponseHandle Resp, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponseStorage_Add_1(TElOCSPResponseStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponseStorage_Remove(TElOCSPResponseStorageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponseStorage_IndexOf(TElOCSPResponseStorageHandle _Handle, TElOCSPResponseHandle Resp, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponseStorage_Clear(TElOCSPResponseStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponseStorage_ExportTo(TElOCSPResponseStorageHandle _Handle, TElOCSPResponseStorageHandle Storage);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponseStorage_get_Responses(TElOCSPResponseStorageHandle _Handle, int32_t Index, TElOCSPResponseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponseStorage_get_Count(TElOCSPResponseStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponseStorage_Create(TElOCSPResponseStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElOCSPResponseStorage;

#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
class TElOCSPResponseStorage: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElOCSPResponseStorage)
#ifdef SB_USE_CLASS_TELOCSPRESPONSE
		TElOCSPResponse* _Inst_Responses;
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELOCSPRESPONSE
		int32_t Add(TElOCSPResponse &Resp);

		int32_t Add(TElOCSPResponse *Resp);
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

		int32_t Add();

		void Remove(int32_t Index);

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
		int32_t IndexOf(TElOCSPResponse &Resp);

		int32_t IndexOf(TElOCSPResponse *Resp);
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

		void Clear();

		void ExportTo(TElOCSPResponseStorage &Storage);

		void ExportTo(TElOCSPResponseStorage *Storage);

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
		virtual TElOCSPResponse* get_Responses(int32_t Index);
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElOCSPResponseStorage, Count);

		TElOCSPResponseStorage(TElOCSPResponseStorageHandle handle, TElOwnHandle ownHandle);

		TElOCSPResponseStorage();

		virtual ~TElOCSPResponseStorage();

};
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBOCSPSTORAGE */

