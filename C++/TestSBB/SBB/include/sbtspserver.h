#ifndef __INC_SBTSPSERVER
#define __INC_SBTSPSERVER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbencoding.h"
#include "sbstreams.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbpem.h"
#include "sbx509ext.h"
#include "sbpkcs7.h"
#include "sbmessages.h"
#include "sbpkicommon.h"
#include "sbtspcommon.h"
#include "sbconstants.h"
#include "sbcustomcertstorage.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElServerTSPInfoHandle;

typedef TElServerTSPInfoHandle ElServerTSPInfoHandle;

typedef TElClassHandle TElCustomTSPServerHandle;

typedef TElCustomTSPServerHandle ElCustomTSPServerHandle;

typedef TElClassHandle TElFileTSPServerHandle;

typedef TElFileTSPServerHandle ElFileTSPServerHandle;

#ifdef SB_USE_CLASS_TELSERVERTSPINFO
SB_IMPORT uint32_t SB_APIENTRY TElServerTSPInfo_get_Nonce(TElServerTSPInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElServerTSPInfo_get_HashAlgorithm(TElServerTSPInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElServerTSPInfo_get_Time(TElServerTSPInfoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElServerTSPInfo_set_Time(TElServerTSPInfoHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElServerTSPInfo_get_AccuracySec(TElServerTSPInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElServerTSPInfo_set_AccuracySec(TElServerTSPInfoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElServerTSPInfo_get_AccuracyMilli(TElServerTSPInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElServerTSPInfo_set_AccuracyMilli(TElServerTSPInfoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElServerTSPInfo_get_AccuracyMicro(TElServerTSPInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElServerTSPInfo_set_AccuracyMicro(TElServerTSPInfoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElServerTSPInfo_get_TSAName(TElServerTSPInfoHandle _Handle, TElGeneralNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElServerTSPInfo_Create(TElTSPInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELSERVERTSPINFO */

#ifdef SB_USE_CLASS_TELCUSTOMTSPSERVER
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPServer_get_TSPInfo(TElCustomTSPServerHandle _Handle, TElServerTSPInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPServer_get_DefaultPolicy(TElCustomTSPServerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPServer_set_DefaultPolicy(TElCustomTSPServerHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPServer_get_IsAuthenticode(TElCustomTSPServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPServer_get_Certificates(TElCustomTSPServerHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPServer_set_Certificates(TElCustomTSPServerHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPServer_Create(TComponentHandle Owner, TElCustomTSPServerHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMTSPSERVER */

#ifdef SB_USE_CLASS_TELFILETSPSERVER
SB_IMPORT uint32_t SB_APIENTRY TElFileTSPServer_SaveReplyToStream(TElFileTSPServerHandle _Handle, TSBPKIStatusRaw ServerResult, int32_t FailureInfo, TStreamHandle Stream, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileTSPServer_LoadRequestFromStream(TElFileTSPServerHandle _Handle, TStreamHandle Stream, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileTSPServer_Create(TComponentHandle Owner, TElCustomTSPServerHandle * OutResult);
#endif /* SB_USE_CLASS_TELFILETSPSERVER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElServerTSPInfo;
typedef TElServerTSPInfo ElServerTSPInfo;
class TElCustomTSPServer;
typedef TElCustomTSPServer ElCustomTSPServer;
class TElFileTSPServer;
typedef TElFileTSPServer ElFileTSPServer;

#ifdef SB_USE_CLASS_TELSERVERTSPINFO
class TElServerTSPInfo: public TElTSPInfo
{
	private:
		SB_DISABLE_COPY(TElServerTSPInfo)
#ifdef SB_USE_CLASS_TELGENERALNAME
		TElGeneralName* _Inst_TSAName;
#endif /* SB_USE_CLASS_TELGENERALNAME */

		void initInstances();

	public:
		virtual void get_Nonce(std::vector<uint8_t> &OutResult);

		virtual int32_t get_HashAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_HashAlgorithm, TElServerTSPInfo, HashAlgorithm);

		virtual int64_t get_Time();

		virtual void set_Time(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Time, set_Time, TElServerTSPInfo, Time);

		virtual int32_t get_AccuracySec();

		virtual void set_AccuracySec(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AccuracySec, set_AccuracySec, TElServerTSPInfo, AccuracySec);

		virtual int32_t get_AccuracyMilli();

		virtual void set_AccuracyMilli(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AccuracyMilli, set_AccuracyMilli, TElServerTSPInfo, AccuracyMilli);

		virtual int32_t get_AccuracyMicro();

		virtual void set_AccuracyMicro(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AccuracyMicro, set_AccuracyMicro, TElServerTSPInfo, AccuracyMicro);

#ifdef SB_USE_CLASS_TELGENERALNAME
		virtual TElGeneralName* get_TSAName();

		SB_DECLARE_PROPERTY_GET(TElGeneralName*, get_TSAName, TElServerTSPInfo, TSAName);
#endif /* SB_USE_CLASS_TELGENERALNAME */

		TElServerTSPInfo(TElServerTSPInfoHandle handle, TElOwnHandle ownHandle);

		TElServerTSPInfo();

		virtual ~TElServerTSPInfo();

};
#endif /* SB_USE_CLASS_TELSERVERTSPINFO */

#ifdef SB_USE_CLASS_TELCUSTOMTSPSERVER
class TElCustomTSPServer: public TElTSPClass
{
	private:
		SB_DISABLE_COPY(TElCustomTSPServer)
#ifdef SB_USE_CLASS_TELSERVERTSPINFO
		TElServerTSPInfo* _Inst_TSPInfo;
#endif /* SB_USE_CLASS_TELSERVERTSPINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_Certificates;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELSERVERTSPINFO
		virtual TElServerTSPInfo* get_TSPInfo();

		SB_DECLARE_PROPERTY_GET(TElServerTSPInfo*, get_TSPInfo, TElCustomTSPServer, TSPInfo);
#endif /* SB_USE_CLASS_TELSERVERTSPINFO */

		virtual void get_DefaultPolicy(std::vector<uint8_t> &OutResult);

		virtual void set_DefaultPolicy(const std::vector<uint8_t> &Value);

		virtual bool get_IsAuthenticode();

		SB_DECLARE_PROPERTY_GET(bool, get_IsAuthenticode, TElCustomTSPServer, IsAuthenticode);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_Certificates();

		virtual void set_Certificates(TElCustomCertStorage &Value);

		virtual void set_Certificates(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_Certificates, set_Certificates, TElCustomTSPServer, Certificates);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		TElCustomTSPServer(TElCustomTSPServerHandle handle, TElOwnHandle ownHandle);

		explicit TElCustomTSPServer(TComponent &Owner);

		explicit TElCustomTSPServer(TComponent *Owner);

		virtual ~TElCustomTSPServer();

};
#endif /* SB_USE_CLASS_TELCUSTOMTSPSERVER */

#ifdef SB_USE_CLASS_TELFILETSPSERVER
class TElFileTSPServer: public TElCustomTSPServer
{
	private:
		SB_DISABLE_COPY(TElFileTSPServer)
	public:
#ifdef SB_USE_CLASS_TSTREAM
		bool SaveReplyToStream(TSBPKIStatus ServerResult, int32_t FailureInfo, TStream &Stream);

		bool SaveReplyToStream(TSBPKIStatus ServerResult, int32_t FailureInfo, TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadRequestFromStream(TStream &Stream);

		int32_t LoadRequestFromStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		TElFileTSPServer(TElFileTSPServerHandle handle, TElOwnHandle ownHandle);

		explicit TElFileTSPServer(TComponent &Owner);

		explicit TElFileTSPServer(TComponent *Owner);

};
#endif /* SB_USE_CLASS_TELFILETSPSERVER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBTSPSERVER */

