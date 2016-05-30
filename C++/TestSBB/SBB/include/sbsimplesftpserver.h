#ifndef __INC_SBSIMPLESFTPSERVER
#define __INC_SBSIMPLESFTPSERVER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbmath.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbrandom.h"
#include "sbchsconv.h"
#include "sbchsconvcharsets.h"
#include "sbchscjk.h"
#include "sbsshterm.h"
#include "sbsharedresource.h"
#include "sbsshconstants.h"
#include "sbzlib.h"
#include "sbsshkeystorage.h"
#include "sbsshutils.h"
#include "sbcryptoprov.h"
#include "sbsymmetriccrypto.h"
#include "sbcryptoprovmanager.h"
#include "sbhashfunction.h"
#include "sbsocket.h"
#include "sbsshcommon.h"
#include "sbsshpubkeycommon.h"
#include "sbsshhandlers.h"
#include "sbsshpubkeyhandler.h"
#include "sbsshforwardinghandlers.h"
#include "sbsftphandler.h"
#include "sbsshserver.h"
#include "sbsftpcommon.h"
#include "sbcustomfsadapter.h"
#include "sbdiskfsadapter.h"
#include "sbconstants.h"
#include "sbsimplesshserver.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SFileNotFound 	"File not found"
#define SB_SPermissionDenied 	"Permission denied"
#define SB_SOperationFailed 	"Operation failed"
#define SB_SFileWriteOpFailed 	"Write operation failed"

typedef TElClassHandle TElSimpleSFTPServerHandle;

typedef TElClassHandle TElSimpleSSHsftpSearchRecHandle;

typedef TElClassHandle TElSimpleSFTPServerSessionThreadHandle;

#ifdef SB_USE_CLASS_TELSIMPLESFTPSERVER
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_AllowSftp(TElSimpleSFTPServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_AllowSftp(TElSimpleSFTPServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_ReadOnly(TElSimpleSFTPServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_ReadOnly(TElSimpleSFTPServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_SFTPBaseDir(TElSimpleSFTPServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_SFTPBaseDir(TElSimpleSFTPServerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_FilenameCharset(TElSimpleSFTPServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_FilenameCharset(TElSimpleSFTPServerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_FileSystemAdapter(TElSimpleSFTPServerHandle _Handle, TElCustomFileSystemAdapterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_FileSystemAdapter(TElSimpleSFTPServerHandle _Handle, TElCustomFileSystemAdapterHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_Versions(TElSimpleSFTPServerHandle _Handle, TSBSftpVersionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_Versions(TElSimpleSFTPServerHandle _Handle, TSBSftpVersionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_DefaultOwnerUsername(TElSimpleSFTPServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_DefaultOwnerUsername(TElSimpleSFTPServerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_DefaultOwnerGroup(TElSimpleSFTPServerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_DefaultOwnerGroup(TElSimpleSFTPServerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPBlock(TElSimpleSFTPServerHandle _Handle, TElSFTPServerBlockEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPBlock(TElSimpleSFTPServerHandle _Handle, TElSFTPServerBlockEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPUnblock(TElSimpleSFTPServerHandle _Handle, TElSFTPServerUnblockEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPUnblock(TElSimpleSFTPServerHandle _Handle, TElSFTPServerUnblockEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPClose(TElSimpleSFTPServerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPClose(TElSimpleSFTPServerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPCloseHandle(TElSimpleSFTPServerHandle _Handle, TElSFTPServerCloseHandleEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPCloseHandle(TElSimpleSFTPServerHandle _Handle, TElSFTPServerCloseHandleEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPCreateDirectory(TElSimpleSFTPServerHandle _Handle, TElSFTPServerCreateDirectoryEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPCreateDirectory(TElSimpleSFTPServerHandle _Handle, TElSFTPServerCreateDirectoryEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPCreateSymLink(TElSimpleSFTPServerHandle _Handle, TElSFTPServerCreateSymLinkEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPCreateSymLink(TElSimpleSFTPServerHandle _Handle, TElSFTPServerCreateSymLinkEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPCreateHardLink(TElSimpleSFTPServerHandle _Handle, TElSFTPServerCreateHardLinkEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPCreateHardLink(TElSimpleSFTPServerHandle _Handle, TElSFTPServerCreateHardLinkEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPError(TElSimpleSFTPServerHandle _Handle, TSBSftpErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPError(TElSimpleSFTPServerHandle _Handle, TSBSftpErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPFindClose(TElSimpleSFTPServerHandle _Handle, TElSFTPServerFindCloseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPFindClose(TElSimpleSFTPServerHandle _Handle, TElSFTPServerFindCloseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPFindFirst(TElSimpleSFTPServerHandle _Handle, TElSFTPServerFindFirstEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPFindFirst(TElSimpleSFTPServerHandle _Handle, TElSFTPServerFindFirstEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPFindNext(TElSimpleSFTPServerHandle _Handle, TElSFTPServerFindNextEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPFindNext(TElSimpleSFTPServerHandle _Handle, TElSFTPServerFindNextEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPOpen(TElSimpleSFTPServerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPOpen(TElSimpleSFTPServerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPOpenFile(TElSimpleSFTPServerHandle _Handle, TElSFTPServerOpenFileEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPOpenFile(TElSimpleSFTPServerHandle _Handle, TElSFTPServerOpenFileEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPReadFile(TElSimpleSFTPServerHandle _Handle, TElSFTPServerReadEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPReadFile(TElSimpleSFTPServerHandle _Handle, TElSFTPServerReadEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPReadSymLink(TElSimpleSFTPServerHandle _Handle, TElSFTPServerReadSymLinkEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPReadSymLink(TElSimpleSFTPServerHandle _Handle, TElSFTPServerReadSymLinkEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPReceive(TElSimpleSFTPServerHandle _Handle, TElSFTPServerReceiveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPReceive(TElSimpleSFTPServerHandle _Handle, TElSFTPServerReceiveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPRemove(TElSimpleSFTPServerHandle _Handle, TElSFTPServerRemoveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPRemove(TElSimpleSFTPServerHandle _Handle, TElSFTPServerRemoveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPRenameFile(TElSimpleSFTPServerHandle _Handle, TElSFTPServerRenameFileEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPRenameFile(TElSimpleSFTPServerHandle _Handle, TElSFTPServerRenameFileEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPRequestAbsolutePath(TElSimpleSFTPServerHandle _Handle, TElSFTPServerRequestAbsolutePathEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPRequestAbsolutePath(TElSimpleSFTPServerHandle _Handle, TElSFTPServerRequestAbsolutePathEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPRequestAttributes(TElSimpleSFTPServerHandle _Handle, TElSFTPServerRequestAttributesEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPRequestAttributes(TElSimpleSFTPServerHandle _Handle, TElSFTPServerRequestAttributesEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPRequestAttributes2(TElSimpleSFTPServerHandle _Handle, TElSFTPServerRequestAttributes2Event * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPRequestAttributes2(TElSimpleSFTPServerHandle _Handle, TElSFTPServerRequestAttributes2Event pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPSend(TElSimpleSFTPServerHandle _Handle, TElSFTPServerSendEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPSend(TElSimpleSFTPServerHandle _Handle, TElSFTPServerSendEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPSetAttributes(TElSimpleSFTPServerHandle _Handle, TElSFTPServerSetAttributesEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPSetAttributes(TElSimpleSFTPServerHandle _Handle, TElSFTPServerSetAttributesEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPSetAttributes2(TElSimpleSFTPServerHandle _Handle, TElSFTPServerSetAttributes2Event * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPSetAttributes2(TElSimpleSFTPServerHandle _Handle, TElSFTPServerSetAttributes2Event pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPTextSeek(TElSimpleSFTPServerHandle _Handle, TElSFTPServerTextSeekEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPTextSeek(TElSimpleSFTPServerHandle _Handle, TElSFTPServerTextSeekEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPWriteFile(TElSimpleSFTPServerHandle _Handle, TElSFTPServerWriteEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPWriteFile(TElSimpleSFTPServerHandle _Handle, TElSFTPServerWriteEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPExtendedRequest(TElSimpleSFTPServerHandle _Handle, TElSFTPServerExtendedRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPExtendedRequest(TElSimpleSFTPServerHandle _Handle, TElSFTPServerExtendedRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPVersionChange(TElSimpleSFTPServerHandle _Handle, TElSftpServerVersionChangeEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPVersionChange(TElSimpleSFTPServerHandle _Handle, TElSftpServerVersionChangeEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPSendVendorID(TElSimpleSFTPServerHandle _Handle, TElSFTPServerSendVendorIDEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPSendVendorID(TElSimpleSFTPServerHandle _Handle, TElSFTPServerSendVendorIDEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPRequestFileHash(TElSimpleSFTPServerHandle _Handle, TElSFTPServerRequestFileHashEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPRequestFileHash(TElSimpleSFTPServerHandle _Handle, TElSFTPServerRequestFileHashEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPRequestFileHashByHandle(TElSimpleSFTPServerHandle _Handle, TElSFTPServerRequestFileHashByHandleEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPRequestFileHashByHandle(TElSimpleSFTPServerHandle _Handle, TElSFTPServerRequestFileHashByHandleEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPRequestAvailableSpace(TElSimpleSFTPServerHandle _Handle, TElSFTPServerRequestAvailableSpaceEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPRequestAvailableSpace(TElSimpleSFTPServerHandle _Handle, TElSFTPServerRequestAvailableSpaceEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPRequestStatVFS(TElSimpleSFTPServerHandle _Handle, TElSFTPServerRequestStatVFSEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPRequestStatVFS(TElSimpleSFTPServerHandle _Handle, TElSFTPServerRequestStatVFSEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPRequestHomeDirectory(TElSimpleSFTPServerHandle _Handle, TElSFTPServerRequestHomeDirectoryEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPRequestHomeDirectory(TElSimpleSFTPServerHandle _Handle, TElSFTPServerRequestHomeDirectoryEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPCopyRemoteFile(TElSimpleSFTPServerHandle _Handle, TElSFTPServerCopyRemoteFileEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPCopyRemoteFile(TElSimpleSFTPServerHandle _Handle, TElSFTPServerCopyRemoteFileEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPCopyRemoteData(TElSimpleSFTPServerHandle _Handle, TElSFTPServerCopyRemoteDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPCopyRemoteData(TElSimpleSFTPServerHandle _Handle, TElSFTPServerCopyRemoteDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPMakeTempFolder(TElSimpleSFTPServerHandle _Handle, TElSFTPServerReturnPathEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPMakeTempFolder(TElSimpleSFTPServerHandle _Handle, TElSFTPServerReturnPathEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_get_OnSFTPRequestTempFolder(TElSimpleSFTPServerHandle _Handle, TElSFTPServerReturnPathEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_set_OnSFTPRequestTempFolder(TElSimpleSFTPServerHandle _Handle, TElSFTPServerReturnPathEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServer_Create(TComponentHandle AOwner, TElSimpleSFTPServerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIMPLESFTPSERVER */

#ifdef SB_USE_CLASS_TELSIMPLESSHSFTPSEARCHREC
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHsftpSearchRec_get_Current(TElSimpleSSHsftpSearchRecHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHsftpSearchRec_set_Current(TElSimpleSSHsftpSearchRecHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHsftpSearchRec_get_InfoList(TElSimpleSSHsftpSearchRecHandle _Handle, TElVFSEntryInformationListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHsftpSearchRec_set_InfoList(TElSimpleSSHsftpSearchRecHandle _Handle, TElVFSEntryInformationListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSSHsftpSearchRec_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIMPLESSHSFTPSEARCHREC */

#ifdef SB_USE_CLASS_TELSIMPLESFTPSERVERSESSIONTHREAD
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServerSessionThread_get_SFTPServer(TElSimpleSFTPServerSessionThreadHandle _Handle, TElSimpleSFTPServerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServerSessionThread_set_SFTPServer(TElSimpleSFTPServerSessionThreadHandle _Handle, TElSimpleSFTPServerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServerSessionThread_get_FSAdapter(TElSimpleSFTPServerSessionThreadHandle _Handle, TElCustomFileSystemAdapterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSFTPServerSessionThread_Create(TElSimpleSSHServerSessionThreadHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIMPLESFTPSERVERSESSIONTHREAD */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSimpleSFTPServer;
class TElSimpleSSHsftpSearchRec;
class TElSimpleSFTPServerSessionThread;

#ifdef SB_USE_CLASS_TELSIMPLESFTPSERVER
class TElSimpleSFTPServer: public TElSimpleSSHServer
{
	private:
		SB_DISABLE_COPY(TElSimpleSFTPServer)
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		TElCustomFileSystemAdapter* _Inst_FileSystemAdapter;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

		void initInstances();

	public:
		virtual bool get_AllowSftp();

		virtual void set_AllowSftp(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AllowSftp, set_AllowSftp, TElSimpleSFTPServer, AllowSftp);

		virtual bool get_ReadOnly();

		virtual void set_ReadOnly(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ReadOnly, set_ReadOnly, TElSimpleSFTPServer, ReadOnly);

		virtual void get_SFTPBaseDir(std::string &OutResult);

		virtual void set_SFTPBaseDir(const std::string &Value);

		virtual void get_FilenameCharset(std::string &OutResult);

		virtual void set_FilenameCharset(const std::string &Value);

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		virtual TElCustomFileSystemAdapter* get_FileSystemAdapter();

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter &Value);

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter *Value);

		SB_DECLARE_PROPERTY(TElCustomFileSystemAdapter*, get_FileSystemAdapter, set_FileSystemAdapter, TElSimpleSFTPServer, FileSystemAdapter);
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

		virtual TSBSftpVersions get_Versions();

		virtual void set_Versions(TSBSftpVersions Value);

		SB_DECLARE_PROPERTY(TSBSftpVersions, get_Versions, set_Versions, TElSimpleSFTPServer, Versions);

		virtual void get_DefaultOwnerUsername(std::string &OutResult);

		virtual void set_DefaultOwnerUsername(const std::string &Value);

		virtual void get_DefaultOwnerGroup(std::string &OutResult);

		virtual void set_DefaultOwnerGroup(const std::string &Value);

		virtual void get_OnSFTPBlock(TElSFTPServerBlockEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPBlock(TElSFTPServerBlockEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPUnblock(TElSFTPServerUnblockEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPUnblock(TElSFTPServerUnblockEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPClose(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPClose(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPCloseHandle(TElSFTPServerCloseHandleEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPCloseHandle(TElSFTPServerCloseHandleEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPCreateDirectory(TElSFTPServerCreateDirectoryEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPCreateDirectory(TElSFTPServerCreateDirectoryEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPCreateSymLink(TElSFTPServerCreateSymLinkEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPCreateSymLink(TElSFTPServerCreateSymLinkEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPCreateHardLink(TElSFTPServerCreateHardLinkEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPCreateHardLink(TElSFTPServerCreateHardLinkEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPError(TSBSftpErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPError(TSBSftpErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPFindClose(TElSFTPServerFindCloseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPFindClose(TElSFTPServerFindCloseEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPFindFirst(TElSFTPServerFindFirstEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPFindFirst(TElSFTPServerFindFirstEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPFindNext(TElSFTPServerFindNextEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPFindNext(TElSFTPServerFindNextEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPOpen(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPOpen(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPOpenFile(TElSFTPServerOpenFileEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPOpenFile(TElSFTPServerOpenFileEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPReadFile(TElSFTPServerReadEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPReadFile(TElSFTPServerReadEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPReadSymLink(TElSFTPServerReadSymLinkEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPReadSymLink(TElSFTPServerReadSymLinkEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPReceive(TElSFTPServerReceiveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPReceive(TElSFTPServerReceiveEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPRemove(TElSFTPServerRemoveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPRemove(TElSFTPServerRemoveEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPRenameFile(TElSFTPServerRenameFileEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPRenameFile(TElSFTPServerRenameFileEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPRequestAbsolutePath(TElSFTPServerRequestAbsolutePathEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPRequestAbsolutePath(TElSFTPServerRequestAbsolutePathEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPRequestAttributes(TElSFTPServerRequestAttributesEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPRequestAttributes(TElSFTPServerRequestAttributesEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPRequestAttributes2(TElSFTPServerRequestAttributes2Event &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPRequestAttributes2(TElSFTPServerRequestAttributes2Event pMethodValue, void * pDataValue);

		virtual void get_OnSFTPSend(TElSFTPServerSendEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPSend(TElSFTPServerSendEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPSetAttributes(TElSFTPServerSetAttributesEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPSetAttributes(TElSFTPServerSetAttributesEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPSetAttributes2(TElSFTPServerSetAttributes2Event &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPSetAttributes2(TElSFTPServerSetAttributes2Event pMethodValue, void * pDataValue);

		virtual void get_OnSFTPTextSeek(TElSFTPServerTextSeekEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPTextSeek(TElSFTPServerTextSeekEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPWriteFile(TElSFTPServerWriteEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPWriteFile(TElSFTPServerWriteEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPExtendedRequest(TElSFTPServerExtendedRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPExtendedRequest(TElSFTPServerExtendedRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPVersionChange(TElSftpServerVersionChangeEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPVersionChange(TElSftpServerVersionChangeEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPSendVendorID(TElSFTPServerSendVendorIDEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPSendVendorID(TElSFTPServerSendVendorIDEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPRequestFileHash(TElSFTPServerRequestFileHashEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPRequestFileHash(TElSFTPServerRequestFileHashEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPRequestFileHashByHandle(TElSFTPServerRequestFileHashByHandleEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPRequestFileHashByHandle(TElSFTPServerRequestFileHashByHandleEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPRequestAvailableSpace(TElSFTPServerRequestAvailableSpaceEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPRequestAvailableSpace(TElSFTPServerRequestAvailableSpaceEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPRequestStatVFS(TElSFTPServerRequestStatVFSEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPRequestStatVFS(TElSFTPServerRequestStatVFSEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPRequestHomeDirectory(TElSFTPServerRequestHomeDirectoryEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPRequestHomeDirectory(TElSFTPServerRequestHomeDirectoryEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPCopyRemoteFile(TElSFTPServerCopyRemoteFileEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPCopyRemoteFile(TElSFTPServerCopyRemoteFileEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPCopyRemoteData(TElSFTPServerCopyRemoteDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPCopyRemoteData(TElSFTPServerCopyRemoteDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPMakeTempFolder(TElSFTPServerReturnPathEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPMakeTempFolder(TElSFTPServerReturnPathEvent pMethodValue, void * pDataValue);

		virtual void get_OnSFTPRequestTempFolder(TElSFTPServerReturnPathEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSFTPRequestTempFolder(TElSFTPServerReturnPathEvent pMethodValue, void * pDataValue);

		TElSimpleSFTPServer(TElSimpleSFTPServerHandle handle, TElOwnHandle ownHandle);

		explicit TElSimpleSFTPServer(TComponent &AOwner);

		explicit TElSimpleSFTPServer(TComponent *AOwner);

		virtual ~TElSimpleSFTPServer();

};
#endif /* SB_USE_CLASS_TELSIMPLESFTPSERVER */

#ifdef SB_USE_CLASS_TELSIMPLESSHSFTPSEARCHREC
class TElSimpleSSHsftpSearchRec: public TObject
{
	private:
		SB_DISABLE_COPY(TElSimpleSSHsftpSearchRec)
#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATIONLIST
		TElVFSEntryInformationList* _Inst_InfoList;
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATIONLIST */

		void initInstances();

	public:
		virtual int32_t get_Current();

		virtual void set_Current(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Current, set_Current, TElSimpleSSHsftpSearchRec, Current);

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATIONLIST
		virtual TElVFSEntryInformationList* get_InfoList();

		virtual void set_InfoList(TElVFSEntryInformationList &Value);

		virtual void set_InfoList(TElVFSEntryInformationList *Value);

		SB_DECLARE_PROPERTY(TElVFSEntryInformationList*, get_InfoList, set_InfoList, TElSimpleSSHsftpSearchRec, InfoList);
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATIONLIST */

		TElSimpleSSHsftpSearchRec(TElSimpleSSHsftpSearchRecHandle handle, TElOwnHandle ownHandle);

		TElSimpleSSHsftpSearchRec();

		virtual ~TElSimpleSSHsftpSearchRec();

};
#endif /* SB_USE_CLASS_TELSIMPLESSHSFTPSEARCHREC */

#ifdef SB_USE_CLASS_TELSIMPLESFTPSERVERSESSIONTHREAD
class TElSimpleSFTPServerSessionThread: public TElSimpleSSHServerSessionThread
{
	private:
		SB_DISABLE_COPY(TElSimpleSFTPServerSessionThread)
#ifdef SB_USE_CLASS_TELSIMPLESFTPSERVER
		TElSimpleSFTPServer* _Inst_SFTPServer;
#endif /* SB_USE_CLASS_TELSIMPLESFTPSERVER */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		TElCustomFileSystemAdapter* _Inst_FSAdapter;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELSIMPLESFTPSERVER
		virtual TElSimpleSFTPServer* get_SFTPServer();

		virtual void set_SFTPServer(TElSimpleSFTPServer &Value);

		virtual void set_SFTPServer(TElSimpleSFTPServer *Value);

		SB_DECLARE_PROPERTY(TElSimpleSFTPServer*, get_SFTPServer, set_SFTPServer, TElSimpleSFTPServerSessionThread, SFTPServer);
#endif /* SB_USE_CLASS_TELSIMPLESFTPSERVER */

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		virtual TElCustomFileSystemAdapter* get_FSAdapter();

		SB_DECLARE_PROPERTY_GET(TElCustomFileSystemAdapter*, get_FSAdapter, TElSimpleSFTPServerSessionThread, FSAdapter);
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

		TElSimpleSFTPServerSessionThread(TElSimpleSFTPServerSessionThreadHandle handle, TElOwnHandle ownHandle);

		TElSimpleSFTPServerSessionThread();

		virtual ~TElSimpleSFTPServerSessionThread();

};
#endif /* SB_USE_CLASS_TELSIMPLESFTPSERVERSESSIONTHREAD */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSIMPLESFTPSERVER */

