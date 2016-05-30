#include "sbsimplesftpserver.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSIMPLESFTPSERVER

bool TElSimpleSFTPServer::get_AllowSftp()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPServer_get_AllowSftp(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPServer::set_AllowSftp(bool Value)
{
	SBCheckError(TElSimpleSFTPServer_set_AllowSftp(_Handle, (int8_t)Value));
}

bool TElSimpleSFTPServer::get_ReadOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPServer_get_ReadOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSFTPServer::set_ReadOnly(bool Value)
{
	SBCheckError(TElSimpleSFTPServer_set_ReadOnly(_Handle, (int8_t)Value));
}

void TElSimpleSFTPServer::get_SFTPBaseDir(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPServer_get_SFTPBaseDir(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1241708897, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPServer::set_SFTPBaseDir(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPServer_set_SFTPBaseDir(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleSFTPServer::get_FilenameCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPServer_get_FilenameCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-552675492, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPServer::set_FilenameCharset(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPServer_set_FilenameCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
TElCustomFileSystemAdapter* TElSimpleSFTPServer::get_FileSystemAdapter()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSFTPServer_get_FileSystemAdapter(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FileSystemAdapter)
		this->_Inst_FileSystemAdapter = new TElCustomFileSystemAdapter(hOutResult, ohFalse);
	else
		this->_Inst_FileSystemAdapter->updateHandle(hOutResult);
	return this->_Inst_FileSystemAdapter;
}

SB_INLINE void TElSimpleSFTPServer::set_FileSystemAdapter(TElCustomFileSystemAdapter &Value)
{
	SBCheckError(TElSimpleSFTPServer_set_FileSystemAdapter(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSFTPServer::set_FileSystemAdapter(TElCustomFileSystemAdapter *Value)
{
	SBCheckError(TElSimpleSFTPServer_set_FileSystemAdapter(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

TSBSftpVersions TElSimpleSFTPServer::get_Versions()
{
	TSBSftpVersionsRaw OutResultRaw = 0;
	SBCheckError(TElSimpleSFTPServer_get_Versions(_Handle, &OutResultRaw));
	return (TSBSftpVersions)OutResultRaw;
}

SB_INLINE void TElSimpleSFTPServer::set_Versions(TSBSftpVersions Value)
{
	SBCheckError(TElSimpleSFTPServer_set_Versions(_Handle, (TSBSftpVersionsRaw)Value));
}

void TElSimpleSFTPServer::get_DefaultOwnerUsername(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPServer_get_DefaultOwnerUsername(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-109429593, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPServer::set_DefaultOwnerUsername(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPServer_set_DefaultOwnerUsername(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleSFTPServer::get_DefaultOwnerGroup(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSFTPServer_get_DefaultOwnerGroup(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1995622441, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSFTPServer::set_DefaultOwnerGroup(const std::string &Value)
{
	SBCheckError(TElSimpleSFTPServer_set_DefaultOwnerGroup(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPBlock(TElSFTPServerBlockEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPBlock(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPBlock(TElSFTPServerBlockEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPBlock(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPUnblock(TElSFTPServerUnblockEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPUnblock(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPUnblock(TElSFTPServerUnblockEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPUnblock(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPClose(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPClose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPClose(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPClose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPCloseHandle(TElSFTPServerCloseHandleEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPCloseHandle(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPCloseHandle(TElSFTPServerCloseHandleEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPCloseHandle(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPCreateDirectory(TElSFTPServerCreateDirectoryEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPCreateDirectory(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPCreateDirectory(TElSFTPServerCreateDirectoryEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPCreateDirectory(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPCreateSymLink(TElSFTPServerCreateSymLinkEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPCreateSymLink(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPCreateSymLink(TElSFTPServerCreateSymLinkEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPCreateSymLink(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPCreateHardLink(TElSFTPServerCreateHardLinkEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPCreateHardLink(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPCreateHardLink(TElSFTPServerCreateHardLinkEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPCreateHardLink(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPError(TSBSftpErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPError(TSBSftpErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPFindClose(TElSFTPServerFindCloseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPFindClose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPFindClose(TElSFTPServerFindCloseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPFindClose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPFindFirst(TElSFTPServerFindFirstEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPFindFirst(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPFindFirst(TElSFTPServerFindFirstEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPFindFirst(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPFindNext(TElSFTPServerFindNextEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPFindNext(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPFindNext(TElSFTPServerFindNextEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPFindNext(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPOpen(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPOpen(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPOpen(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPOpen(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPOpenFile(TElSFTPServerOpenFileEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPOpenFile(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPOpenFile(TElSFTPServerOpenFileEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPOpenFile(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPReadFile(TElSFTPServerReadEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPReadFile(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPReadFile(TElSFTPServerReadEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPReadFile(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPReadSymLink(TElSFTPServerReadSymLinkEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPReadSymLink(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPReadSymLink(TElSFTPServerReadSymLinkEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPReadSymLink(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPReceive(TElSFTPServerReceiveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPReceive(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPReceive(TElSFTPServerReceiveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPReceive(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPRemove(TElSFTPServerRemoveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPRemove(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPRemove(TElSFTPServerRemoveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPRemove(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPRenameFile(TElSFTPServerRenameFileEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPRenameFile(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPRenameFile(TElSFTPServerRenameFileEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPRenameFile(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPRequestAbsolutePath(TElSFTPServerRequestAbsolutePathEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPRequestAbsolutePath(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPRequestAbsolutePath(TElSFTPServerRequestAbsolutePathEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPRequestAbsolutePath(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPRequestAttributes(TElSFTPServerRequestAttributesEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPRequestAttributes(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPRequestAttributes(TElSFTPServerRequestAttributesEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPRequestAttributes(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPRequestAttributes2(TElSFTPServerRequestAttributes2Event &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPRequestAttributes2(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPRequestAttributes2(TElSFTPServerRequestAttributes2Event pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPRequestAttributes2(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPSend(TElSFTPServerSendEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPSend(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPSend(TElSFTPServerSendEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPSend(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPSetAttributes(TElSFTPServerSetAttributesEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPSetAttributes(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPSetAttributes(TElSFTPServerSetAttributesEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPSetAttributes(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPSetAttributes2(TElSFTPServerSetAttributes2Event &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPSetAttributes2(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPSetAttributes2(TElSFTPServerSetAttributes2Event pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPSetAttributes2(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPTextSeek(TElSFTPServerTextSeekEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPTextSeek(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPTextSeek(TElSFTPServerTextSeekEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPTextSeek(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPWriteFile(TElSFTPServerWriteEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPWriteFile(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPWriteFile(TElSFTPServerWriteEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPWriteFile(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPExtendedRequest(TElSFTPServerExtendedRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPExtendedRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPExtendedRequest(TElSFTPServerExtendedRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPExtendedRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPVersionChange(TElSftpServerVersionChangeEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPVersionChange(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPVersionChange(TElSftpServerVersionChangeEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPVersionChange(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPSendVendorID(TElSFTPServerSendVendorIDEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPSendVendorID(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPSendVendorID(TElSFTPServerSendVendorIDEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPSendVendorID(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPRequestFileHash(TElSFTPServerRequestFileHashEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPRequestFileHash(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPRequestFileHash(TElSFTPServerRequestFileHashEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPRequestFileHash(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPRequestFileHashByHandle(TElSFTPServerRequestFileHashByHandleEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPRequestFileHashByHandle(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPRequestFileHashByHandle(TElSFTPServerRequestFileHashByHandleEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPRequestFileHashByHandle(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPRequestAvailableSpace(TElSFTPServerRequestAvailableSpaceEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPRequestAvailableSpace(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPRequestAvailableSpace(TElSFTPServerRequestAvailableSpaceEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPRequestAvailableSpace(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPRequestStatVFS(TElSFTPServerRequestStatVFSEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPRequestStatVFS(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPRequestStatVFS(TElSFTPServerRequestStatVFSEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPRequestStatVFS(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPRequestHomeDirectory(TElSFTPServerRequestHomeDirectoryEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPRequestHomeDirectory(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPRequestHomeDirectory(TElSFTPServerRequestHomeDirectoryEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPRequestHomeDirectory(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPCopyRemoteFile(TElSFTPServerCopyRemoteFileEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPCopyRemoteFile(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPCopyRemoteFile(TElSFTPServerCopyRemoteFileEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPCopyRemoteFile(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPCopyRemoteData(TElSFTPServerCopyRemoteDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPCopyRemoteData(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPCopyRemoteData(TElSFTPServerCopyRemoteDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPCopyRemoteData(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPMakeTempFolder(TElSFTPServerReturnPathEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPMakeTempFolder(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPMakeTempFolder(TElSFTPServerReturnPathEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPMakeTempFolder(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSFTPServer::get_OnSFTPRequestTempFolder(TElSFTPServerReturnPathEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSFTPServer_get_OnSFTPRequestTempFolder(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSFTPServer::set_OnSFTPRequestTempFolder(TElSFTPServerReturnPathEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSFTPServer_set_OnSFTPRequestTempFolder(_Handle, pMethodValue, pDataValue));
}

void TElSimpleSFTPServer::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
}

TElSimpleSFTPServer::TElSimpleSFTPServer(TElSimpleSFTPServerHandle handle, TElOwnHandle ownHandle) : TElSimpleSSHServer(handle, ownHandle)
{
	initInstances();
}

TElSimpleSFTPServer::TElSimpleSFTPServer(TComponent &AOwner) : TElSimpleSSHServer(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleSFTPServer_Create(AOwner.getHandle(), &_Handle));
}

TElSimpleSFTPServer::TElSimpleSFTPServer(TComponent *AOwner) : TElSimpleSSHServer(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleSFTPServer_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSimpleSFTPServer::~TElSimpleSFTPServer()
{
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	delete this->_Inst_FileSystemAdapter;
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
}
#endif /* SB_USE_CLASS_TELSIMPLESFTPSERVER */

#ifdef SB_USE_CLASS_TELSIMPLESSHSFTPSEARCHREC

SB_INLINE int32_t TElSimpleSSHsftpSearchRec::get_Current()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHsftpSearchRec_get_Current(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHsftpSearchRec::set_Current(int32_t Value)
{
	SBCheckError(TElSimpleSSHsftpSearchRec_set_Current(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATIONLIST
TElVFSEntryInformationList* TElSimpleSSHsftpSearchRec::get_InfoList()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHsftpSearchRec_get_InfoList(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_InfoList)
		this->_Inst_InfoList = new TElVFSEntryInformationList(hOutResult, ohFalse);
	else
		this->_Inst_InfoList->updateHandle(hOutResult);
	return this->_Inst_InfoList;
}

SB_INLINE void TElSimpleSSHsftpSearchRec::set_InfoList(TElVFSEntryInformationList &Value)
{
	SBCheckError(TElSimpleSSHsftpSearchRec_set_InfoList(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSSHsftpSearchRec::set_InfoList(TElVFSEntryInformationList *Value)
{
	SBCheckError(TElSimpleSSHsftpSearchRec_set_InfoList(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATIONLIST */

void TElSimpleSSHsftpSearchRec::initInstances()
{
#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATIONLIST
	this->_Inst_InfoList = NULL;
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATIONLIST */
}

TElSimpleSSHsftpSearchRec::TElSimpleSSHsftpSearchRec(TElSimpleSSHsftpSearchRecHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElSimpleSSHsftpSearchRec::TElSimpleSSHsftpSearchRec() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleSSHsftpSearchRec_Create(&_Handle));
}

TElSimpleSSHsftpSearchRec::~TElSimpleSSHsftpSearchRec()
{
#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATIONLIST
	delete this->_Inst_InfoList;
	this->_Inst_InfoList = NULL;
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATIONLIST */
}
#endif /* SB_USE_CLASS_TELSIMPLESSHSFTPSEARCHREC */

#ifdef SB_USE_CLASS_TELSIMPLESFTPSERVERSESSIONTHREAD

#ifdef SB_USE_CLASS_TELSIMPLESFTPSERVER
TElSimpleSFTPServer* TElSimpleSFTPServerSessionThread::get_SFTPServer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSFTPServerSessionThread_get_SFTPServer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SFTPServer)
		this->_Inst_SFTPServer = new TElSimpleSFTPServer(hOutResult, ohFalse);
	else
		this->_Inst_SFTPServer->updateHandle(hOutResult);
	return this->_Inst_SFTPServer;
}

SB_INLINE void TElSimpleSFTPServerSessionThread::set_SFTPServer(TElSimpleSFTPServer &Value)
{
	SBCheckError(TElSimpleSFTPServerSessionThread_set_SFTPServer(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSFTPServerSessionThread::set_SFTPServer(TElSimpleSFTPServer *Value)
{
	SBCheckError(TElSimpleSFTPServerSessionThread_set_SFTPServer(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSIMPLESFTPSERVER */

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
TElCustomFileSystemAdapter* TElSimpleSFTPServerSessionThread::get_FSAdapter()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSFTPServerSessionThread_get_FSAdapter(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FSAdapter)
		this->_Inst_FSAdapter = new TElCustomFileSystemAdapter(hOutResult, ohFalse);
	else
		this->_Inst_FSAdapter->updateHandle(hOutResult);
	return this->_Inst_FSAdapter;
}
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

void TElSimpleSFTPServerSessionThread::initInstances()
{
#ifdef SB_USE_CLASS_TELSIMPLESFTPSERVER
	this->_Inst_SFTPServer = NULL;
#endif /* SB_USE_CLASS_TELSIMPLESFTPSERVER */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	this->_Inst_FSAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
}

TElSimpleSFTPServerSessionThread::TElSimpleSFTPServerSessionThread(TElSimpleSFTPServerSessionThreadHandle handle, TElOwnHandle ownHandle) : TElSimpleSSHServerSessionThread(handle, ownHandle)
{
	initInstances();
}

TElSimpleSFTPServerSessionThread::TElSimpleSFTPServerSessionThread() : TElSimpleSSHServerSessionThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleSFTPServerSessionThread_Create(&_Handle));
}

TElSimpleSFTPServerSessionThread::~TElSimpleSFTPServerSessionThread()
{
#ifdef SB_USE_CLASS_TELSIMPLESFTPSERVER
	delete this->_Inst_SFTPServer;
	this->_Inst_SFTPServer = NULL;
#endif /* SB_USE_CLASS_TELSIMPLESFTPSERVER */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	delete this->_Inst_FSAdapter;
	this->_Inst_FSAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
}
#endif /* SB_USE_CLASS_TELSIMPLESFTPSERVERSESSIONTHREAD */

};	/* namespace SecureBlackbox */

