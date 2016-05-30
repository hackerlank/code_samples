#ifndef __INC_SBSFTPSERVER
#define __INC_SBSFTPSERVER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbchsconv.h"
#include "sbchsconvcharsets.h"
#include "sbchscjk.h"
#include "sbsshutils.h"
#include "sbsshhandlers.h"
#include "sbsshcommon.h"
#include "sbsftpcommon.h"
#include "sbsharedresource.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TSBSftpHandleHandle;

typedef TElClassHandle TElSFTPServerHandle;

typedef TElSFTPServerHandle ElSFTPServerHandle;

#ifdef SB_USE_CLASS_TSBSFTPHANDLE
SB_IMPORT uint32_t SB_APIENTRY TSBSftpHandle_get_Allocated(TSBSftpHandleHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpHandle_set_Allocated(TSBSftpHandleHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpHandle_get_Name(TSBSftpHandleHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpHandle_set_Name(TSBSftpHandleHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpHandle_get_Info(TSBSftpHandleHandle _Handle, TElSftpFileInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpHandle_set_Info(TSBSftpHandleHandle _Handle, TElSftpFileInfoHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpHandle_get_InfoUsed(TSBSftpHandleHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpHandle_set_InfoUsed(TSBSftpHandleHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpHandle_get_Eof(TSBSftpHandleHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpHandle_set_Eof(TSBSftpHandleHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpHandle_get_Data(TSBSftpHandleHandle _Handle, void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpHandle_set_Data(TSBSftpHandleHandle _Handle, void * Value);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpHandle_get_Directory(TSBSftpHandleHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpHandle_set_Directory(TSBSftpHandleHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpHandle_Create(TSBSftpHandleHandle * OutResult);
#endif /* SB_USE_CLASS_TSBSFTPHANDLE */

#ifdef SB_USE_CLASS_TELSFTPSERVER
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_Close(TElSFTPServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_DataAvailable(TElSFTPServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_Open(TElSFTPServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_Active(TElSFTPServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_ServerVersion(TElSFTPServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_ServerVersion(TElSFTPServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_NewLineConvention(TElSFTPServerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_NewLineConvention(TElSFTPServerHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_NegotiatedCharset(TElSFTPServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_Version(TElSFTPServerHandle _Handle, TSBSftpVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_UseUTF8(TElSFTPServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_UseUTF8(TElSFTPServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_UseUTF8OnSFTP3(TElSFTPServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_UseUTF8OnSFTP3(TElSFTPServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_RemoteCharset(TElSFTPServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_RemoteCharset(TElSFTPServerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_LocalCharset(TElSFTPServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_LocalCharset(TElSFTPServerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_NoCharacterEncoding(TElSFTPServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_NoCharacterEncoding(TElSFTPServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_Supported(TElSFTPServerHandle _Handle, TElSftpSupportedExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_ClientVendorID(TElSFTPServerHandle _Handle, TElSftpVendorIDExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_FilenameCharset(TElSFTPServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_FilenameCharset(TElSFTPServerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_Versions(TElSFTPServerHandle _Handle, TSBSftpVersionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_Versions(TElSFTPServerHandle _Handle, TSBSftpVersionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnBlock(TElSFTPServerHandle _Handle, TElSFTPServerBlockEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnBlock(TElSFTPServerHandle _Handle, TElSFTPServerBlockEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnUnblock(TElSFTPServerHandle _Handle, TElSFTPServerUnblockEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnUnblock(TElSFTPServerHandle _Handle, TElSFTPServerUnblockEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnClose(TElSFTPServerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnClose(TElSFTPServerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnCloseHandle(TElSFTPServerHandle _Handle, TElSFTPServerCloseHandleEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnCloseHandle(TElSFTPServerHandle _Handle, TElSFTPServerCloseHandleEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnCreateDirectory(TElSFTPServerHandle _Handle, TElSFTPServerCreateDirectoryEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnCreateDirectory(TElSFTPServerHandle _Handle, TElSFTPServerCreateDirectoryEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnCreateSymLink(TElSFTPServerHandle _Handle, TElSFTPServerCreateSymLinkEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnCreateSymLink(TElSFTPServerHandle _Handle, TElSFTPServerCreateSymLinkEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnCreateHardLink(TElSFTPServerHandle _Handle, TElSFTPServerCreateHardLinkEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnCreateHardLink(TElSFTPServerHandle _Handle, TElSFTPServerCreateHardLinkEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnError(TElSFTPServerHandle _Handle, TSBSftpErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnError(TElSFTPServerHandle _Handle, TSBSftpErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnFindClose(TElSFTPServerHandle _Handle, TElSFTPServerFindCloseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnFindClose(TElSFTPServerHandle _Handle, TElSFTPServerFindCloseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnFindFirst(TElSFTPServerHandle _Handle, TElSFTPServerFindFirstEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnFindFirst(TElSFTPServerHandle _Handle, TElSFTPServerFindFirstEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnFindNext(TElSFTPServerHandle _Handle, TElSFTPServerFindNextEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnFindNext(TElSFTPServerHandle _Handle, TElSFTPServerFindNextEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnOpen(TElSFTPServerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnOpen(TElSFTPServerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnOpenFile(TElSFTPServerHandle _Handle, TElSFTPServerOpenFileEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnOpenFile(TElSFTPServerHandle _Handle, TElSFTPServerOpenFileEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnReadFile(TElSFTPServerHandle _Handle, TElSFTPServerReadEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnReadFile(TElSFTPServerHandle _Handle, TElSFTPServerReadEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnReadSymLink(TElSFTPServerHandle _Handle, TElSFTPServerReadSymLinkEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnReadSymLink(TElSFTPServerHandle _Handle, TElSFTPServerReadSymLinkEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnReceive(TElSFTPServerHandle _Handle, TElSFTPServerReceiveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnReceive(TElSFTPServerHandle _Handle, TElSFTPServerReceiveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnRemove(TElSFTPServerHandle _Handle, TElSFTPServerRemoveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnRemove(TElSFTPServerHandle _Handle, TElSFTPServerRemoveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnRenameFile(TElSFTPServerHandle _Handle, TElSFTPServerRenameFileEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnRenameFile(TElSFTPServerHandle _Handle, TElSFTPServerRenameFileEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnRequestAbsolutePath(TElSFTPServerHandle _Handle, TElSFTPServerRequestAbsolutePathEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnRequestAbsolutePath(TElSFTPServerHandle _Handle, TElSFTPServerRequestAbsolutePathEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnRequestAttributes(TElSFTPServerHandle _Handle, TElSFTPServerRequestAttributesEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnRequestAttributes(TElSFTPServerHandle _Handle, TElSFTPServerRequestAttributesEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnRequestAttributes2(TElSFTPServerHandle _Handle, TElSFTPServerRequestAttributes2Event * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnRequestAttributes2(TElSFTPServerHandle _Handle, TElSFTPServerRequestAttributes2Event pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnSend(TElSFTPServerHandle _Handle, TElSFTPServerSendEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnSend(TElSFTPServerHandle _Handle, TElSFTPServerSendEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnSetAttributes(TElSFTPServerHandle _Handle, TElSFTPServerSetAttributesEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnSetAttributes(TElSFTPServerHandle _Handle, TElSFTPServerSetAttributesEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnSetAttributes2(TElSFTPServerHandle _Handle, TElSFTPServerSetAttributes2Event * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnSetAttributes2(TElSFTPServerHandle _Handle, TElSFTPServerSetAttributes2Event pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnTextSeek(TElSFTPServerHandle _Handle, TElSFTPServerTextSeekEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnTextSeek(TElSFTPServerHandle _Handle, TElSFTPServerTextSeekEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnWriteFile(TElSFTPServerHandle _Handle, TElSFTPServerWriteEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnWriteFile(TElSFTPServerHandle _Handle, TElSFTPServerWriteEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnExtendedRequest(TElSFTPServerHandle _Handle, TElSFTPServerExtendedRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnExtendedRequest(TElSFTPServerHandle _Handle, TElSFTPServerExtendedRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnVersionChange(TElSFTPServerHandle _Handle, TElSftpServerVersionChangeEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnVersionChange(TElSFTPServerHandle _Handle, TElSftpServerVersionChangeEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnSendVendorID(TElSFTPServerHandle _Handle, TElSFTPServerSendVendorIDEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnSendVendorID(TElSFTPServerHandle _Handle, TElSFTPServerSendVendorIDEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnRequestFileHash(TElSFTPServerHandle _Handle, TElSFTPServerRequestFileHashEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnRequestFileHash(TElSFTPServerHandle _Handle, TElSFTPServerRequestFileHashEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnRequestFileHashByHandle(TElSFTPServerHandle _Handle, TElSFTPServerRequestFileHashByHandleEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnRequestFileHashByHandle(TElSFTPServerHandle _Handle, TElSFTPServerRequestFileHashByHandleEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnRequestAvailableSpace(TElSFTPServerHandle _Handle, TElSFTPServerRequestAvailableSpaceEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnRequestAvailableSpace(TElSFTPServerHandle _Handle, TElSFTPServerRequestAvailableSpaceEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnRequestStatVFS(TElSFTPServerHandle _Handle, TElSFTPServerRequestStatVFSEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnRequestStatVFS(TElSFTPServerHandle _Handle, TElSFTPServerRequestStatVFSEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnRequestHomeDirectory(TElSFTPServerHandle _Handle, TElSFTPServerRequestHomeDirectoryEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnRequestHomeDirectory(TElSFTPServerHandle _Handle, TElSFTPServerRequestHomeDirectoryEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnCopyRemoteFile(TElSFTPServerHandle _Handle, TElSFTPServerCopyRemoteFileEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnCopyRemoteFile(TElSFTPServerHandle _Handle, TElSFTPServerCopyRemoteFileEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnCopyRemoteData(TElSFTPServerHandle _Handle, TElSFTPServerCopyRemoteDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnCopyRemoteData(TElSFTPServerHandle _Handle, TElSFTPServerCopyRemoteDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnMakeTempFolder(TElSFTPServerHandle _Handle, TElSFTPServerReturnPathEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnMakeTempFolder(TElSFTPServerHandle _Handle, TElSFTPServerReturnPathEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_get_OnRequestTempFolder(TElSFTPServerHandle _Handle, TElSFTPServerReturnPathEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_set_OnRequestTempFolder(TElSFTPServerHandle _Handle, TElSFTPServerReturnPathEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSFTPServer_Create(TComponentHandle AOwner, TElSFTPServerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPSERVER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TSBSftpHandle;
class TElSFTPServer;
typedef TElSFTPServer ElSFTPServer;

#ifdef SB_USE_CLASS_TSBSFTPHANDLE
class TSBSftpHandle: public TObject
{
	private:
		SB_DISABLE_COPY(TSBSftpHandle)
#ifdef SB_USE_CLASS_TELSFTPFILEINFO
		TElSftpFileInfo* _Inst_Info;
#endif /* SB_USE_CLASS_TELSFTPFILEINFO */

		void initInstances();

	public:
		virtual bool get_Allocated();

		virtual void set_Allocated(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Allocated, set_Allocated, TSBSftpHandle, Allocated);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

#ifdef SB_USE_CLASS_TELSFTPFILEINFO
		virtual TElSftpFileInfo* get_Info();

		virtual void set_Info(TElSftpFileInfo &Value);

		virtual void set_Info(TElSftpFileInfo *Value);

		SB_DECLARE_PROPERTY(TElSftpFileInfo*, get_Info, set_Info, TSBSftpHandle, Info);
#endif /* SB_USE_CLASS_TELSFTPFILEINFO */

		virtual bool get_InfoUsed();

		virtual void set_InfoUsed(bool Value);

		SB_DECLARE_PROPERTY(bool, get_InfoUsed, set_InfoUsed, TSBSftpHandle, InfoUsed);

		virtual bool get_Eof();

		virtual void set_Eof(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Eof, set_Eof, TSBSftpHandle, Eof);

		virtual void * get_Data();

		virtual void set_Data(void * Value);

		SB_DECLARE_PROPERTY(void *, get_Data, set_Data, TSBSftpHandle, Data);

		virtual bool get_Directory();

		virtual void set_Directory(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Directory, set_Directory, TSBSftpHandle, Directory);

		TSBSftpHandle(TSBSftpHandleHandle handle, TElOwnHandle ownHandle);

		TSBSftpHandle();

		virtual ~TSBSftpHandle();

};
#endif /* SB_USE_CLASS_TSBSFTPHANDLE */

#ifdef SB_USE_CLASS_TELSFTPSERVER
class TElSFTPServer: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSFTPServer)
#ifdef SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION
		TElSftpSupportedExtension* _Inst_Supported;
#endif /* SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION */
#ifdef SB_USE_CLASS_TELSFTPVENDORIDEXTENSION
		TElSftpVendorIDExtension* _Inst_ClientVendorID;
#endif /* SB_USE_CLASS_TELSFTPVENDORIDEXTENSION */

		void initInstances();

	public:
		void Close();

		void DataAvailable();

		void Open();

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElSFTPServer, Active);

		virtual int32_t get_ServerVersion();

		virtual void set_ServerVersion(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ServerVersion, set_ServerVersion, TElSFTPServer, ServerVersion);

		virtual void get_NewLineConvention(std::vector<uint8_t> &OutResult);

		virtual void set_NewLineConvention(const std::vector<uint8_t> &Value);

		virtual void get_NegotiatedCharset(std::string &OutResult);

		virtual TSBSftpVersion get_Version();

		SB_DECLARE_PROPERTY_GET(TSBSftpVersion, get_Version, TElSFTPServer, Version);

		virtual bool get_UseUTF8();

		virtual void set_UseUTF8(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUTF8, set_UseUTF8, TElSFTPServer, UseUTF8);

		virtual bool get_UseUTF8OnSFTP3();

		virtual void set_UseUTF8OnSFTP3(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUTF8OnSFTP3, set_UseUTF8OnSFTP3, TElSFTPServer, UseUTF8OnSFTP3);

		virtual void get_RemoteCharset(std::string &OutResult);

		virtual void set_RemoteCharset(const std::string &Value);

		virtual void get_LocalCharset(std::string &OutResult);

		virtual void set_LocalCharset(const std::string &Value);

		virtual bool get_NoCharacterEncoding();

		virtual void set_NoCharacterEncoding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_NoCharacterEncoding, set_NoCharacterEncoding, TElSFTPServer, NoCharacterEncoding);

#ifdef SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION
		virtual TElSftpSupportedExtension* get_Supported();

		SB_DECLARE_PROPERTY_GET(TElSftpSupportedExtension*, get_Supported, TElSFTPServer, Supported);
#endif /* SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPVENDORIDEXTENSION
		virtual TElSftpVendorIDExtension* get_ClientVendorID();

		SB_DECLARE_PROPERTY_GET(TElSftpVendorIDExtension*, get_ClientVendorID, TElSFTPServer, ClientVendorID);
#endif /* SB_USE_CLASS_TELSFTPVENDORIDEXTENSION */

		virtual void get_FilenameCharset(std::string &OutResult);

		virtual void set_FilenameCharset(const std::string &Value);

		virtual TSBSftpVersions get_Versions();

		virtual void set_Versions(TSBSftpVersions Value);

		SB_DECLARE_PROPERTY(TSBSftpVersions, get_Versions, set_Versions, TElSFTPServer, Versions);

		virtual void get_OnBlock(TElSFTPServerBlockEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBlock(TElSFTPServerBlockEvent pMethodValue, void * pDataValue);

		virtual void get_OnUnblock(TElSFTPServerUnblockEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnUnblock(TElSFTPServerUnblockEvent pMethodValue, void * pDataValue);

		virtual void get_OnClose(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnClose(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnCloseHandle(TElSFTPServerCloseHandleEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseHandle(TElSFTPServerCloseHandleEvent pMethodValue, void * pDataValue);

		virtual void get_OnCreateDirectory(TElSFTPServerCreateDirectoryEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCreateDirectory(TElSFTPServerCreateDirectoryEvent pMethodValue, void * pDataValue);

		virtual void get_OnCreateSymLink(TElSFTPServerCreateSymLinkEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCreateSymLink(TElSFTPServerCreateSymLinkEvent pMethodValue, void * pDataValue);

		virtual void get_OnCreateHardLink(TElSFTPServerCreateHardLinkEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCreateHardLink(TElSFTPServerCreateHardLinkEvent pMethodValue, void * pDataValue);

		virtual void get_OnError(TSBSftpErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSBSftpErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnFindClose(TElSFTPServerFindCloseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFindClose(TElSFTPServerFindCloseEvent pMethodValue, void * pDataValue);

		virtual void get_OnFindFirst(TElSFTPServerFindFirstEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFindFirst(TElSFTPServerFindFirstEvent pMethodValue, void * pDataValue);

		virtual void get_OnFindNext(TElSFTPServerFindNextEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFindNext(TElSFTPServerFindNextEvent pMethodValue, void * pDataValue);

		virtual void get_OnOpen(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpen(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnOpenFile(TElSFTPServerOpenFileEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpenFile(TElSFTPServerOpenFileEvent pMethodValue, void * pDataValue);

		virtual void get_OnReadFile(TElSFTPServerReadEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReadFile(TElSFTPServerReadEvent pMethodValue, void * pDataValue);

		virtual void get_OnReadSymLink(TElSFTPServerReadSymLinkEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReadSymLink(TElSFTPServerReadSymLinkEvent pMethodValue, void * pDataValue);

		virtual void get_OnReceive(TElSFTPServerReceiveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReceive(TElSFTPServerReceiveEvent pMethodValue, void * pDataValue);

		virtual void get_OnRemove(TElSFTPServerRemoveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRemove(TElSFTPServerRemoveEvent pMethodValue, void * pDataValue);

		virtual void get_OnRenameFile(TElSFTPServerRenameFileEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRenameFile(TElSFTPServerRenameFileEvent pMethodValue, void * pDataValue);

		virtual void get_OnRequestAbsolutePath(TElSFTPServerRequestAbsolutePathEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRequestAbsolutePath(TElSFTPServerRequestAbsolutePathEvent pMethodValue, void * pDataValue);

		virtual void get_OnRequestAttributes(TElSFTPServerRequestAttributesEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRequestAttributes(TElSFTPServerRequestAttributesEvent pMethodValue, void * pDataValue);

		virtual void get_OnRequestAttributes2(TElSFTPServerRequestAttributes2Event &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRequestAttributes2(TElSFTPServerRequestAttributes2Event pMethodValue, void * pDataValue);

		virtual void get_OnSend(TElSFTPServerSendEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSend(TElSFTPServerSendEvent pMethodValue, void * pDataValue);

		virtual void get_OnSetAttributes(TElSFTPServerSetAttributesEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSetAttributes(TElSFTPServerSetAttributesEvent pMethodValue, void * pDataValue);

		virtual void get_OnSetAttributes2(TElSFTPServerSetAttributes2Event &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSetAttributes2(TElSFTPServerSetAttributes2Event pMethodValue, void * pDataValue);

		virtual void get_OnTextSeek(TElSFTPServerTextSeekEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTextSeek(TElSFTPServerTextSeekEvent pMethodValue, void * pDataValue);

		virtual void get_OnWriteFile(TElSFTPServerWriteEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnWriteFile(TElSFTPServerWriteEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtendedRequest(TElSFTPServerExtendedRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtendedRequest(TElSFTPServerExtendedRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnVersionChange(TElSftpServerVersionChangeEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnVersionChange(TElSftpServerVersionChangeEvent pMethodValue, void * pDataValue);

		virtual void get_OnSendVendorID(TElSFTPServerSendVendorIDEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSendVendorID(TElSFTPServerSendVendorIDEvent pMethodValue, void * pDataValue);

		virtual void get_OnRequestFileHash(TElSFTPServerRequestFileHashEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRequestFileHash(TElSFTPServerRequestFileHashEvent pMethodValue, void * pDataValue);

		virtual void get_OnRequestFileHashByHandle(TElSFTPServerRequestFileHashByHandleEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRequestFileHashByHandle(TElSFTPServerRequestFileHashByHandleEvent pMethodValue, void * pDataValue);

		virtual void get_OnRequestAvailableSpace(TElSFTPServerRequestAvailableSpaceEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRequestAvailableSpace(TElSFTPServerRequestAvailableSpaceEvent pMethodValue, void * pDataValue);

		virtual void get_OnRequestStatVFS(TElSFTPServerRequestStatVFSEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRequestStatVFS(TElSFTPServerRequestStatVFSEvent pMethodValue, void * pDataValue);

		virtual void get_OnRequestHomeDirectory(TElSFTPServerRequestHomeDirectoryEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRequestHomeDirectory(TElSFTPServerRequestHomeDirectoryEvent pMethodValue, void * pDataValue);

		virtual void get_OnCopyRemoteFile(TElSFTPServerCopyRemoteFileEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCopyRemoteFile(TElSFTPServerCopyRemoteFileEvent pMethodValue, void * pDataValue);

		virtual void get_OnCopyRemoteData(TElSFTPServerCopyRemoteDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCopyRemoteData(TElSFTPServerCopyRemoteDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnMakeTempFolder(TElSFTPServerReturnPathEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnMakeTempFolder(TElSFTPServerReturnPathEvent pMethodValue, void * pDataValue);

		virtual void get_OnRequestTempFolder(TElSFTPServerReturnPathEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRequestTempFolder(TElSFTPServerReturnPathEvent pMethodValue, void * pDataValue);

		TElSFTPServer(TElSFTPServerHandle handle, TElOwnHandle ownHandle);

		explicit TElSFTPServer(TComponent &AOwner);

		explicit TElSFTPServer(TComponent *AOwner);

		virtual ~TElSFTPServer();

};
#endif /* SB_USE_CLASS_TELSFTPSERVER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSFTPSERVER */

