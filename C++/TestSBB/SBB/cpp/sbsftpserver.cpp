#include "sbsftpserver.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TSBSFTPHANDLE

bool TSBSftpHandle::get_Allocated()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TSBSftpHandle_get_Allocated(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TSBSftpHandle::set_Allocated(bool Value)
{
	SBCheckError(TSBSftpHandle_set_Allocated(_Handle, (int8_t)Value));
}

void TSBSftpHandle::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TSBSftpHandle_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1300510984, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TSBSftpHandle::set_Name(const std::string &Value)
{
	SBCheckError(TSBSftpHandle_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELSFTPFILEINFO
TElSftpFileInfo* TSBSftpHandle::get_Info()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TSBSftpHandle_get_Info(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Info)
		this->_Inst_Info = new TElSftpFileInfo(hOutResult, ohFalse);
	else
		this->_Inst_Info->updateHandle(hOutResult);
	return this->_Inst_Info;
}

SB_INLINE void TSBSftpHandle::set_Info(TElSftpFileInfo &Value)
{
	SBCheckError(TSBSftpHandle_set_Info(_Handle, Value.getHandle()));
}

SB_INLINE void TSBSftpHandle::set_Info(TElSftpFileInfo *Value)
{
	SBCheckError(TSBSftpHandle_set_Info(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPFILEINFO */

bool TSBSftpHandle::get_InfoUsed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TSBSftpHandle_get_InfoUsed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TSBSftpHandle::set_InfoUsed(bool Value)
{
	SBCheckError(TSBSftpHandle_set_InfoUsed(_Handle, (int8_t)Value));
}

bool TSBSftpHandle::get_Eof()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TSBSftpHandle_get_Eof(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TSBSftpHandle::set_Eof(bool Value)
{
	SBCheckError(TSBSftpHandle_set_Eof(_Handle, (int8_t)Value));
}

SB_INLINE void * TSBSftpHandle::get_Data()
{
	void * OutResult;
	SBCheckError(TSBSftpHandle_get_Data(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TSBSftpHandle::set_Data(void * Value)
{
	SBCheckError(TSBSftpHandle_set_Data(_Handle, Value));
}

bool TSBSftpHandle::get_Directory()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TSBSftpHandle_get_Directory(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TSBSftpHandle::set_Directory(bool Value)
{
	SBCheckError(TSBSftpHandle_set_Directory(_Handle, (int8_t)Value));
}

void TSBSftpHandle::initInstances()
{
#ifdef SB_USE_CLASS_TELSFTPFILEINFO
	this->_Inst_Info = NULL;
#endif /* SB_USE_CLASS_TELSFTPFILEINFO */
}

TSBSftpHandle::TSBSftpHandle(TSBSftpHandleHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TSBSftpHandle::TSBSftpHandle() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TSBSftpHandle_Create(&_Handle));
}

TSBSftpHandle::~TSBSftpHandle()
{
#ifdef SB_USE_CLASS_TELSFTPFILEINFO
	delete this->_Inst_Info;
	this->_Inst_Info = NULL;
#endif /* SB_USE_CLASS_TELSFTPFILEINFO */
}
#endif /* SB_USE_CLASS_TSBSFTPHANDLE */

#ifdef SB_USE_CLASS_TELSFTPSERVER

SB_INLINE void TElSFTPServer::Close()
{
	SBCheckError(TElSFTPServer_Close(_Handle));
}

SB_INLINE void TElSFTPServer::DataAvailable()
{
	SBCheckError(TElSFTPServer_DataAvailable(_Handle));
}

SB_INLINE void TElSFTPServer::Open()
{
	SBCheckError(TElSFTPServer_Open(_Handle));
}

bool TElSFTPServer::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSFTPServer_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElSFTPServer::get_ServerVersion()
{
	int32_t OutResult;
	SBCheckError(TElSFTPServer_get_ServerVersion(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSFTPServer::set_ServerVersion(int32_t Value)
{
	SBCheckError(TElSFTPServer_set_ServerVersion(_Handle, Value));
}

void TElSFTPServer::get_NewLineConvention(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSFTPServer_get_NewLineConvention(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1281203486, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSFTPServer::set_NewLineConvention(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSFTPServer_set_NewLineConvention(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElSFTPServer::get_NegotiatedCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSFTPServer_get_NegotiatedCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-145528164, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBSftpVersion TElSFTPServer::get_Version()
{
	TSBSftpVersionRaw OutResultRaw = 0;
	SBCheckError(TElSFTPServer_get_Version(_Handle, &OutResultRaw));
	return (TSBSftpVersion)OutResultRaw;
}

bool TElSFTPServer::get_UseUTF8()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSFTPServer_get_UseUTF8(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSFTPServer::set_UseUTF8(bool Value)
{
	SBCheckError(TElSFTPServer_set_UseUTF8(_Handle, (int8_t)Value));
}

bool TElSFTPServer::get_UseUTF8OnSFTP3()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSFTPServer_get_UseUTF8OnSFTP3(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSFTPServer::set_UseUTF8OnSFTP3(bool Value)
{
	SBCheckError(TElSFTPServer_set_UseUTF8OnSFTP3(_Handle, (int8_t)Value));
}

void TElSFTPServer::get_RemoteCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSFTPServer_get_RemoteCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-300772317, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSFTPServer::set_RemoteCharset(const std::string &Value)
{
	SBCheckError(TElSFTPServer_set_RemoteCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSFTPServer::get_LocalCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSFTPServer_get_LocalCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1686752018, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSFTPServer::set_LocalCharset(const std::string &Value)
{
	SBCheckError(TElSFTPServer_set_LocalCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSFTPServer::get_NoCharacterEncoding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSFTPServer_get_NoCharacterEncoding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSFTPServer::set_NoCharacterEncoding(bool Value)
{
	SBCheckError(TElSFTPServer_set_NoCharacterEncoding(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION
TElSftpSupportedExtension* TElSFTPServer::get_Supported()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSFTPServer_get_Supported(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Supported)
		this->_Inst_Supported = new TElSftpSupportedExtension(hOutResult, ohFalse);
	else
		this->_Inst_Supported->updateHandle(hOutResult);
	return this->_Inst_Supported;
}
#endif /* SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPVENDORIDEXTENSION
TElSftpVendorIDExtension* TElSFTPServer::get_ClientVendorID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSFTPServer_get_ClientVendorID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ClientVendorID)
		this->_Inst_ClientVendorID = new TElSftpVendorIDExtension(hOutResult, ohFalse);
	else
		this->_Inst_ClientVendorID->updateHandle(hOutResult);
	return this->_Inst_ClientVendorID;
}
#endif /* SB_USE_CLASS_TELSFTPVENDORIDEXTENSION */

void TElSFTPServer::get_FilenameCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSFTPServer_get_FilenameCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1764326096, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSFTPServer::set_FilenameCharset(const std::string &Value)
{
	SBCheckError(TElSFTPServer_set_FilenameCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBSftpVersions TElSFTPServer::get_Versions()
{
	TSBSftpVersionsRaw OutResultRaw = 0;
	SBCheckError(TElSFTPServer_get_Versions(_Handle, &OutResultRaw));
	return (TSBSftpVersions)OutResultRaw;
}

SB_INLINE void TElSFTPServer::set_Versions(TSBSftpVersions Value)
{
	SBCheckError(TElSFTPServer_set_Versions(_Handle, (TSBSftpVersionsRaw)Value));
}

SB_INLINE void TElSFTPServer::get_OnBlock(TElSFTPServerBlockEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnBlock(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnBlock(TElSFTPServerBlockEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnBlock(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnUnblock(TElSFTPServerUnblockEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnUnblock(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnUnblock(TElSFTPServerUnblockEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnUnblock(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnClose(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnClose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnClose(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnClose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnCloseHandle(TElSFTPServerCloseHandleEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnCloseHandle(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnCloseHandle(TElSFTPServerCloseHandleEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnCloseHandle(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnCreateDirectory(TElSFTPServerCreateDirectoryEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnCreateDirectory(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnCreateDirectory(TElSFTPServerCreateDirectoryEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnCreateDirectory(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnCreateSymLink(TElSFTPServerCreateSymLinkEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnCreateSymLink(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnCreateSymLink(TElSFTPServerCreateSymLinkEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnCreateSymLink(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnCreateHardLink(TElSFTPServerCreateHardLinkEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnCreateHardLink(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnCreateHardLink(TElSFTPServerCreateHardLinkEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnCreateHardLink(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnError(TSBSftpErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnError(TSBSftpErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnFindClose(TElSFTPServerFindCloseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnFindClose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnFindClose(TElSFTPServerFindCloseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnFindClose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnFindFirst(TElSFTPServerFindFirstEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnFindFirst(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnFindFirst(TElSFTPServerFindFirstEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnFindFirst(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnFindNext(TElSFTPServerFindNextEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnFindNext(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnFindNext(TElSFTPServerFindNextEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnFindNext(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnOpen(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnOpen(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnOpen(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnOpen(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnOpenFile(TElSFTPServerOpenFileEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnOpenFile(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnOpenFile(TElSFTPServerOpenFileEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnOpenFile(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnReadFile(TElSFTPServerReadEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnReadFile(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnReadFile(TElSFTPServerReadEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnReadFile(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnReadSymLink(TElSFTPServerReadSymLinkEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnReadSymLink(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnReadSymLink(TElSFTPServerReadSymLinkEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnReadSymLink(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnReceive(TElSFTPServerReceiveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnReceive(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnReceive(TElSFTPServerReceiveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnReceive(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnRemove(TElSFTPServerRemoveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnRemove(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnRemove(TElSFTPServerRemoveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnRemove(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnRenameFile(TElSFTPServerRenameFileEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnRenameFile(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnRenameFile(TElSFTPServerRenameFileEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnRenameFile(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnRequestAbsolutePath(TElSFTPServerRequestAbsolutePathEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnRequestAbsolutePath(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnRequestAbsolutePath(TElSFTPServerRequestAbsolutePathEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnRequestAbsolutePath(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnRequestAttributes(TElSFTPServerRequestAttributesEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnRequestAttributes(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnRequestAttributes(TElSFTPServerRequestAttributesEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnRequestAttributes(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnRequestAttributes2(TElSFTPServerRequestAttributes2Event &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnRequestAttributes2(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnRequestAttributes2(TElSFTPServerRequestAttributes2Event pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnRequestAttributes2(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnSend(TElSFTPServerSendEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnSend(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnSend(TElSFTPServerSendEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnSend(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnSetAttributes(TElSFTPServerSetAttributesEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnSetAttributes(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnSetAttributes(TElSFTPServerSetAttributesEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnSetAttributes(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnSetAttributes2(TElSFTPServerSetAttributes2Event &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnSetAttributes2(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnSetAttributes2(TElSFTPServerSetAttributes2Event pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnSetAttributes2(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnTextSeek(TElSFTPServerTextSeekEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnTextSeek(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnTextSeek(TElSFTPServerTextSeekEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnTextSeek(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnWriteFile(TElSFTPServerWriteEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnWriteFile(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnWriteFile(TElSFTPServerWriteEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnWriteFile(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnExtendedRequest(TElSFTPServerExtendedRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnExtendedRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnExtendedRequest(TElSFTPServerExtendedRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnExtendedRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnVersionChange(TElSftpServerVersionChangeEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnVersionChange(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnVersionChange(TElSftpServerVersionChangeEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnVersionChange(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnSendVendorID(TElSFTPServerSendVendorIDEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnSendVendorID(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnSendVendorID(TElSFTPServerSendVendorIDEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnSendVendorID(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnRequestFileHash(TElSFTPServerRequestFileHashEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnRequestFileHash(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnRequestFileHash(TElSFTPServerRequestFileHashEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnRequestFileHash(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnRequestFileHashByHandle(TElSFTPServerRequestFileHashByHandleEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnRequestFileHashByHandle(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnRequestFileHashByHandle(TElSFTPServerRequestFileHashByHandleEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnRequestFileHashByHandle(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnRequestAvailableSpace(TElSFTPServerRequestAvailableSpaceEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnRequestAvailableSpace(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnRequestAvailableSpace(TElSFTPServerRequestAvailableSpaceEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnRequestAvailableSpace(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnRequestStatVFS(TElSFTPServerRequestStatVFSEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnRequestStatVFS(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnRequestStatVFS(TElSFTPServerRequestStatVFSEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnRequestStatVFS(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnRequestHomeDirectory(TElSFTPServerRequestHomeDirectoryEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnRequestHomeDirectory(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnRequestHomeDirectory(TElSFTPServerRequestHomeDirectoryEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnRequestHomeDirectory(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnCopyRemoteFile(TElSFTPServerCopyRemoteFileEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnCopyRemoteFile(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnCopyRemoteFile(TElSFTPServerCopyRemoteFileEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnCopyRemoteFile(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnCopyRemoteData(TElSFTPServerCopyRemoteDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnCopyRemoteData(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnCopyRemoteData(TElSFTPServerCopyRemoteDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnCopyRemoteData(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnMakeTempFolder(TElSFTPServerReturnPathEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnMakeTempFolder(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnMakeTempFolder(TElSFTPServerReturnPathEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnMakeTempFolder(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSFTPServer::get_OnRequestTempFolder(TElSFTPServerReturnPathEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSFTPServer_get_OnRequestTempFolder(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSFTPServer::set_OnRequestTempFolder(TElSFTPServerReturnPathEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSFTPServer_set_OnRequestTempFolder(_Handle, pMethodValue, pDataValue));
}

void TElSFTPServer::initInstances()
{
#ifdef SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION
	this->_Inst_Supported = NULL;
#endif /* SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION */
#ifdef SB_USE_CLASS_TELSFTPVENDORIDEXTENSION
	this->_Inst_ClientVendorID = NULL;
#endif /* SB_USE_CLASS_TELSFTPVENDORIDEXTENSION */
}

TElSFTPServer::TElSFTPServer(TElSFTPServerHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElSFTPServer::TElSFTPServer(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSFTPServer_Create(AOwner.getHandle(), &_Handle));
}

TElSFTPServer::TElSFTPServer(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSFTPServer_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSFTPServer::~TElSFTPServer()
{
#ifdef SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION
	delete this->_Inst_Supported;
	this->_Inst_Supported = NULL;
#endif /* SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION */
#ifdef SB_USE_CLASS_TELSFTPVENDORIDEXTENSION
	delete this->_Inst_ClientVendorID;
	this->_Inst_ClientVendorID = NULL;
#endif /* SB_USE_CLASS_TELSFTPVENDORIDEXTENSION */
}
#endif /* SB_USE_CLASS_TELSFTPSERVER */

};	/* namespace SecureBlackbox */

