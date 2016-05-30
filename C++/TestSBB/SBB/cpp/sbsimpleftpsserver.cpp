#include "sbsimpleftpsserver.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSIMPLEFTPSSERVERSESSIONTHREAD

#ifdef SB_USE_CLASS_TELSOCKET
TElSocket* TElSimpleFTPSServerSessionThread::get_Socket()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSServerSessionThread_get_Socket(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Socket)
		this->_Inst_Socket = new TElSocket(hOutResult, ohFalse);
	else
		this->_Inst_Socket->updateHandle(hOutResult);
	return this->_Inst_Socket;
}
#endif /* SB_USE_CLASS_TELSOCKET */

#ifdef SB_USE_CLASS_TELFTPSSERVER
TElFTPSServer* TElSimpleFTPSServerSessionThread::get_FTPSServer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSServerSessionThread_get_FTPSServer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FTPSServer)
		this->_Inst_FTPSServer = new TElFTPSServer(hOutResult, ohFalse);
	else
		this->_Inst_FTPSServer->updateHandle(hOutResult);
	return this->_Inst_FTPSServer;
}
#endif /* SB_USE_CLASS_TELFTPSSERVER */

void TElSimpleFTPSServerSessionThread::get_ListenAddress(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSServerSessionThread_get_ListenAddress(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(874621573, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_ListenAddress(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_ListenAddress(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleFTPSServerSessionThread::get_PassiveModeAddress(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSServerSessionThread_get_PassiveModeAddress(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1665518132, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_PassiveModeAddress(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_PassiveModeAddress(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE uint32_t TElSimpleFTPSServerSessionThread::get_SessionTimeout()
{
	uint32_t OutResult;
	SBCheckError(TElSimpleFTPSServerSessionThread_get_SessionTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_SessionTimeout(uint32_t Value)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_SessionTimeout(_Handle, Value));
}

SB_INLINE uint32_t TElSimpleFTPSServerSessionThread::get_SocketTimeout()
{
	uint32_t OutResult;
	SBCheckError(TElSimpleFTPSServerSessionThread_get_SocketTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_SocketTimeout(uint32_t Value)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_SocketTimeout(_Handle, Value));
}

SB_INLINE int32_t TElSimpleFTPSServerSessionThread::get_IncomingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSServerSessionThread_get_IncomingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_IncomingSpeedLimit(int32_t Value)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_IncomingSpeedLimit(_Handle, Value));
}

SB_INLINE int32_t TElSimpleFTPSServerSessionThread::get_OutgoingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSServerSessionThread_get_OutgoingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_OutgoingSpeedLimit(int32_t Value)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_OutgoingSpeedLimit(_Handle, Value));
}

SB_INLINE int32_t TElSimpleFTPSServerSessionThread::get_DataPortRangeFrom()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSServerSessionThread_get_DataPortRangeFrom(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_DataPortRangeFrom(int32_t Value)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_DataPortRangeFrom(_Handle, Value));
}

SB_INLINE int32_t TElSimpleFTPSServerSessionThread::get_DataPortRangeTo()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSServerSessionThread_get_DataPortRangeTo(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_DataPortRangeTo(int32_t Value)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_DataPortRangeTo(_Handle, Value));
}

bool TElSimpleFTPSServerSessionThread::get_AllowAnonymous()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSServerSessionThread_get_AllowAnonymous(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_AllowAnonymous(bool Value)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_AllowAnonymous(_Handle, (int8_t)Value));
}

void TElSimpleFTPSServerSessionThread::get_RootDirectory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSServerSessionThread_get_RootDirectory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1617174827, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_RootDirectory(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_RootDirectory(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleFTPSServerSessionThread::get_CurrentDirectory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSServerSessionThread_get_CurrentDirectory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1353375132, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_CurrentDirectory(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_CurrentDirectory(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSimpleFTPSServerSessionThread::get_AnonymousLogin()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSServerSessionThread_get_AnonymousLogin(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSimpleFTPSServerSessionThread::get_DataConnectionOpened()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSServerSessionThread_get_DataConnectionOpened(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
TElCustomFileSystemAdapter* TElSimpleFTPSServerSessionThread::get_FileSystemAdapter()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSServerSessionThread_get_FileSystemAdapter(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FileSystemAdapter)
		this->_Inst_FileSystemAdapter = new TElCustomFileSystemAdapter(hOutResult, ohFalse);
	else
		this->_Inst_FileSystemAdapter->updateHandle(hOutResult);
	return this->_Inst_FileSystemAdapter;
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_FileSystemAdapter(TElCustomFileSystemAdapter &Value)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_FileSystemAdapter(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_FileSystemAdapter(TElCustomFileSystemAdapter *Value)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_FileSystemAdapter(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

bool TElSimpleFTPSServerSessionThread::get_ReleaseFileSystemAdapter()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSServerSessionThread_get_ReleaseFileSystemAdapter(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_ReleaseFileSystemAdapter(bool Value)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_ReleaseFileSystemAdapter(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
TElClientSocketBinding* TElSimpleFTPSServerSessionThread::get_OutgoingLocalBinding()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSServerSessionThread_get_OutgoingLocalBinding(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OutgoingLocalBinding)
		this->_Inst_OutgoingLocalBinding = new TElClientSocketBinding(hOutResult, ohFalse);
	else
		this->_Inst_OutgoingLocalBinding->updateHandle(hOutResult);
	return this->_Inst_OutgoingLocalBinding;
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_OutgoingLocalBinding(TElClientSocketBinding &Value)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_OutgoingLocalBinding(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_OutgoingLocalBinding(TElClientSocketBinding *Value)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_OutgoingLocalBinding(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

SB_INLINE void TElSimpleFTPSServerSessionThread::get_OnAuthAttempt(TSBSimpleFTPSServerAuthAttemptEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_get_OnAuthAttempt(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_OnAuthAttempt(TSBSimpleFTPSServerAuthAttemptEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_OnAuthAttempt(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::get_OnCommandReceived(TSBFTPSServerCommandReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_get_OnCommandReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_OnCommandReceived(TSBFTPSServerCommandReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_OnCommandReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::get_OnBeforeSendReply(TSBFTPSServerBeforeSendReplyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_get_OnBeforeSendReply(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_OnBeforeSendReply(TSBFTPSServerBeforeSendReplyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_OnBeforeSendReply(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::get_OnCommandProcessed(TSBFTPSServerCommandProcessedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_get_OnCommandProcessed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_OnCommandProcessed(TSBFTPSServerCommandProcessedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_OnCommandProcessed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::get_OnTransferProgress(TSBFTPSServerTransferProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_get_OnTransferProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_OnTransferProgress(TSBFTPSServerTransferProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_OnTransferProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::get_OnTransferCompleted(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_get_OnTransferCompleted(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_OnTransferCompleted(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_OnTransferCompleted(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::get_OnClose(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_get_OnClose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_OnClose(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_OnClose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::get_OnException(TSBFTPSServerExceptionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_get_OnException(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_OnException(TSBFTPSServerExceptionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_OnException(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::get_OnCommandUnhandled(TSBFTPSServerCommandUnhandledEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_get_OnCommandUnhandled(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_OnCommandUnhandled(TSBFTPSServerCommandUnhandledEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_OnCommandUnhandled(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::get_OnSiteCommand(TSBFTPSServerSiteCommandEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_get_OnSiteCommand(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_OnSiteCommand(TSBFTPSServerSiteCommandEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_OnSiteCommand(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::get_OnFileAllocate(TSBFTPSServerFileAllocateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_get_OnFileAllocate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServerSessionThread::set_OnFileAllocate(TSBFTPSServerFileAllocateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServerSessionThread_set_OnFileAllocate(_Handle, pMethodValue, pDataValue));
}

void TElSimpleFTPSServerSessionThread::initInstances()
{
#ifdef SB_USE_CLASS_TELSOCKET
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELFTPSSERVER
	this->_Inst_FTPSServer = NULL;
#endif /* SB_USE_CLASS_TELFTPSSERVER */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	this->_Inst_OutgoingLocalBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
}

TElSimpleFTPSServerSessionThread::TElSimpleFTPSServerSessionThread(TElSimpleFTPSServerSessionThreadHandle handle, TElOwnHandle ownHandle) : TThread(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELSOCKET
TElSimpleFTPSServerSessionThread::TElSimpleFTPSServerSessionThread(TElSocket &Socket) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleFTPSServerSessionThread_Create(Socket.getHandle(), &_Handle));
}

TElSimpleFTPSServerSessionThread::TElSimpleFTPSServerSessionThread(TElSocket *Socket) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleFTPSServerSessionThread_Create((Socket != NULL) ? Socket->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSOCKET */

TElSimpleFTPSServerSessionThread::~TElSimpleFTPSServerSessionThread()
{
#ifdef SB_USE_CLASS_TELSOCKET
	delete this->_Inst_Socket;
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELFTPSSERVER
	delete this->_Inst_FTPSServer;
	this->_Inst_FTPSServer = NULL;
#endif /* SB_USE_CLASS_TELFTPSSERVER */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	delete this->_Inst_FileSystemAdapter;
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	delete this->_Inst_OutgoingLocalBinding;
	this->_Inst_OutgoingLocalBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
}
#endif /* SB_USE_CLASS_TELSIMPLEFTPSSERVERSESSIONTHREAD */

#ifdef SB_USE_CLASS_TELSIMPLEFTPSSERVER

SB_INLINE void TElSimpleFTPSServer::Start()
{
	SBCheckError(TElSimpleFTPSServer_Start(_Handle));
}

SB_INLINE void TElSimpleFTPSServer::Stop()
{
	SBCheckError(TElSimpleFTPSServer_Stop(_Handle));
}

#ifdef SB_USE_CLASS_TELSSLSERVER
SB_INLINE void TElSimpleFTPSServer::AssignTLSParamsFromTemplate(TElSSLServer &Tpl)
{
	SBCheckError(TElSimpleFTPSServer_AssignTLSParamsFromTemplate(_Handle, Tpl.getHandle()));
}

SB_INLINE void TElSimpleFTPSServer::AssignTLSParamsFromTemplate(TElSSLServer *Tpl)
{
	SBCheckError(TElSimpleFTPSServer_AssignTLSParamsFromTemplate(_Handle, (Tpl != NULL) ? Tpl->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSLSERVER */

SB_INLINE void TElSimpleFTPSServer::ConfigureTLS(TSBServerSSLPredefinedConfiguration Configuration)
{
	SBCheckError(TElSimpleFTPSServer_ConfigureTLS(_Handle, (TSBServerSSLPredefinedConfigurationRaw)Configuration));
}

bool TElSimpleFTPSServer::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSServer_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE
TElFTPSServerMessageTable* TElSimpleFTPSServer::get_MessageTable()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSServer_get_MessageTable(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_MessageTable)
		this->_Inst_MessageTable = new TElFTPSServerMessageTable(hOutResult, ohFalse);
	else
		this->_Inst_MessageTable->updateHandle(hOutResult);
	return this->_Inst_MessageTable;
}
#endif /* SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE */

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
TElClientSocketBinding* TElSimpleFTPSServer::get_OutgoingLocalBinding()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSServer_get_OutgoingLocalBinding(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OutgoingLocalBinding)
		this->_Inst_OutgoingLocalBinding = new TElClientSocketBinding(hOutResult, ohFalse);
	else
		this->_Inst_OutgoingLocalBinding->updateHandle(hOutResult);
	return this->_Inst_OutgoingLocalBinding;
}

SB_INLINE void TElSimpleFTPSServer::set_OutgoingLocalBinding(TElClientSocketBinding &Value)
{
	SBCheckError(TElSimpleFTPSServer_set_OutgoingLocalBinding(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleFTPSServer::set_OutgoingLocalBinding(TElClientSocketBinding *Value)
{
	SBCheckError(TElSimpleFTPSServer_set_OutgoingLocalBinding(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
TElSocketSettings* TElSimpleFTPSServer::get_SocketSettings()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSServer_get_SocketSettings(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SocketSettings)
		this->_Inst_SocketSettings = new TElSocketSettings(hOutResult, ohFalse);
	else
		this->_Inst_SocketSettings->updateHandle(hOutResult);
	return this->_Inst_SocketSettings;
}
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */

bool TElSimpleFTPSServer::get_CipherSuites(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSServer_get_CipherSuites(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSServer::set_CipherSuites(uint8_t Index, bool Value)
{
	SBCheckError(TElSimpleFTPSServer_set_CipherSuites(_Handle, Index, (int8_t)Value));
}

SB_INLINE int32_t TElSimpleFTPSServer::get_CipherSuitePriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSServer_get_CipherSuitePriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSServer::set_CipherSuitePriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElSimpleFTPSServer_set_CipherSuitePriorities(_Handle, Index, Value));
}

bool TElSimpleFTPSServer::get_CompressionAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSServer_get_CompressionAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSServer::set_CompressionAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElSimpleFTPSServer_set_CompressionAlgorithms(_Handle, Index, (int8_t)Value));
}

TSBVersions TElSimpleFTPSServer::get_Versions()
{
	TSBVersionsRaw OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSServer_get_Versions(_Handle, &OutResultRaw));
	return (TSBVersions)OutResultRaw;
}

SB_INLINE void TElSimpleFTPSServer::set_Versions(TSBVersions Value)
{
	SBCheckError(TElSimpleFTPSServer_set_Versions(_Handle, (TSBVersionsRaw)Value));
}

bool TElSimpleFTPSServer::get_ClientAuthentication()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSServer_get_ClientAuthentication(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSServer::set_ClientAuthentication(bool Value)
{
	SBCheckError(TElSimpleFTPSServer_set_ClientAuthentication(_Handle, (int8_t)Value));
}

TSBAuthenticationLevel TElSimpleFTPSServer::get_AuthenticationLevel()
{
	TSBAuthenticationLevelRaw OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSServer_get_AuthenticationLevel(_Handle, &OutResultRaw));
	return (TSBAuthenticationLevel)OutResultRaw;
}

SB_INLINE void TElSimpleFTPSServer::set_AuthenticationLevel(TSBAuthenticationLevel Value)
{
	SBCheckError(TElSimpleFTPSServer_set_AuthenticationLevel(_Handle, (TSBAuthenticationLevelRaw)Value));
}

bool TElSimpleFTPSServer::get_ForceCertificateChain()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSServer_get_ForceCertificateChain(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSServer::set_ForceCertificateChain(bool Value)
{
	SBCheckError(TElSimpleFTPSServer_set_ForceCertificateChain(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElSimpleFTPSServer::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSServer_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElSimpleFTPSServer::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElSimpleFTPSServer_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleFTPSServer::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElSimpleFTPSServer_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELSESSIONPOOL
TElSessionPool* TElSimpleFTPSServer::get_SessionPool()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSServer_get_SessionPool(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SessionPool)
		this->_Inst_SessionPool = new TElSessionPool(hOutResult, ohFalse);
	else
		this->_Inst_SessionPool->updateHandle(hOutResult);
	return this->_Inst_SessionPool;
}

SB_INLINE void TElSimpleFTPSServer::set_SessionPool(TElSessionPool &Value)
{
	SBCheckError(TElSimpleFTPSServer_set_SessionPool(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleFTPSServer::set_SessionPool(TElSessionPool *Value)
{
	SBCheckError(TElSimpleFTPSServer_set_SessionPool(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSESSIONPOOL */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElSimpleFTPSServer::get_ClientCertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSServer_get_ClientCertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ClientCertStorage)
		this->_Inst_ClientCertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_ClientCertStorage->updateHandle(hOutResult);
	return this->_Inst_ClientCertStorage;
}

SB_INLINE void TElSimpleFTPSServer::set_ClientCertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElSimpleFTPSServer_set_ClientCertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleFTPSServer::set_ClientCertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElSimpleFTPSServer_set_ClientCertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

void TElSimpleFTPSServer::get_Host(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSServer_get_Host(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1601017945, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSServer::set_Host(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSServer_set_Host(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleFTPSServer::get_PassiveModeHost(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSServer_get_PassiveModeHost(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(335640102, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSServer::set_PassiveModeHost(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSServer_set_PassiveModeHost(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleFTPSServer::get_DataHost(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSServer_get_DataHost(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-197029138, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSServer::set_DataHost(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSServer_set_DataHost(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSimpleFTPSServer::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSServer_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSServer::set_Port(int32_t Value)
{
	SBCheckError(TElSimpleFTPSServer_set_Port(_Handle, Value));
}

SB_INLINE int32_t TElSimpleFTPSServer::get_DataPortRangeFrom()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSServer_get_DataPortRangeFrom(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSServer::set_DataPortRangeFrom(int32_t Value)
{
	SBCheckError(TElSimpleFTPSServer_set_DataPortRangeFrom(_Handle, Value));
}

SB_INLINE int32_t TElSimpleFTPSServer::get_DataPortRangeTo()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSServer_get_DataPortRangeTo(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSServer::set_DataPortRangeTo(int32_t Value)
{
	SBCheckError(TElSimpleFTPSServer_set_DataPortRangeTo(_Handle, Value));
}

#ifdef SB_WINDOWS
bool TElSimpleFTPSServer::get_UseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSServer_get_UseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSServer::set_UseIPv6(bool Value)
{
	SBCheckError(TElSimpleFTPSServer_set_UseIPv6(_Handle, (int8_t)Value));
}
#endif

SB_INLINE int32_t TElSimpleFTPSServer::get_SessionTimeout()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSServer_get_SessionTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSServer::set_SessionTimeout(int32_t Value)
{
	SBCheckError(TElSimpleFTPSServer_set_SessionTimeout(_Handle, Value));
}

void TElSimpleFTPSServer::get_RootDirectory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSServer_get_RootDirectory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(865367131, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSServer::set_RootDirectory(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSServer_set_RootDirectory(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSimpleFTPSServer::get_ReadOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSServer_get_ReadOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSServer::set_ReadOnly(bool Value)
{
	SBCheckError(TElSimpleFTPSServer_set_ReadOnly(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElSimpleFTPSServer::get_IncomingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSServer_get_IncomingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSServer::set_IncomingSpeedLimit(int32_t Value)
{
	SBCheckError(TElSimpleFTPSServer_set_IncomingSpeedLimit(_Handle, Value));
}

SB_INLINE int32_t TElSimpleFTPSServer::get_OutgoingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSServer_get_OutgoingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSServer::set_OutgoingSpeedLimit(int32_t Value)
{
	SBCheckError(TElSimpleFTPSServer_set_OutgoingSpeedLimit(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
TElCustomFileSystemAdapter* TElSimpleFTPSServer::get_FileSystemAdapter()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSServer_get_FileSystemAdapter(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FileSystemAdapter)
		this->_Inst_FileSystemAdapter = new TElCustomFileSystemAdapter(hOutResult, ohFalse);
	else
		this->_Inst_FileSystemAdapter->updateHandle(hOutResult);
	return this->_Inst_FileSystemAdapter;
}

SB_INLINE void TElSimpleFTPSServer::set_FileSystemAdapter(TElCustomFileSystemAdapter &Value)
{
	SBCheckError(TElSimpleFTPSServer_set_FileSystemAdapter(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleFTPSServer::set_FileSystemAdapter(TElCustomFileSystemAdapter *Value)
{
	SBCheckError(TElSimpleFTPSServer_set_FileSystemAdapter(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

bool TElSimpleFTPSServer::get_AllowAnonymous()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSServer_get_AllowAnonymous(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSServer::set_AllowAnonymous(bool Value)
{
	SBCheckError(TElSimpleFTPSServer_set_AllowAnonymous(_Handle, (int8_t)Value));
}

bool TElSimpleFTPSServer::get_ImplicitSSL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSServer_get_ImplicitSSL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSServer::set_ImplicitSSL(bool Value)
{
	SBCheckError(TElSimpleFTPSServer_set_ImplicitSSL(_Handle, (int8_t)Value));
}

bool TElSimpleFTPSServer::get_UseUTF8()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSServer_get_UseUTF8(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSServer::set_UseUTF8(bool Value)
{
	SBCheckError(TElSimpleFTPSServer_set_UseUTF8(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELFTPSUSERS
TElFTPSUsers* TElSimpleFTPSServer::get_Users()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSServer_get_Users(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Users)
		this->_Inst_Users = new TElFTPSUsers(hOutResult, ohFalse);
	else
		this->_Inst_Users->updateHandle(hOutResult);
	return this->_Inst_Users;
}
#endif /* SB_USE_CLASS_TELFTPSUSERS */

SB_INLINE void TElSimpleFTPSServer::get_OnBeforeNewConnection(TSBSimpleFTPSServerBeforeNewConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServer_get_OnBeforeNewConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServer::set_OnBeforeNewConnection(TSBSimpleFTPSServerBeforeNewConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServer_set_OnBeforeNewConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServer::get_OnNewConnection(TSBSimpleFTPSServerNewConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServer_get_OnNewConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServer::set_OnNewConnection(TSBSimpleFTPSServerNewConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServer_set_OnNewConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServer::get_OnCloseConnection(TSBSimpleFTPSServerCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServer_get_OnCloseConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServer::set_OnCloseConnection(TSBSimpleFTPSServerCloseConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServer_set_OnCloseConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServer::get_OnAuthAttempt(TSBSimpleFTPSServerAuthAttemptEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServer_get_OnAuthAttempt(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServer::set_OnAuthAttempt(TSBSimpleFTPSServerAuthAttemptEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServer_set_OnAuthAttempt(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServer::get_OnCommandReceived(TSBFTPSServerCommandReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServer_get_OnCommandReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServer::set_OnCommandReceived(TSBFTPSServerCommandReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServer_set_OnCommandReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServer::get_OnBeforeSendReply(TSBFTPSServerBeforeSendReplyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServer_get_OnBeforeSendReply(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServer::set_OnBeforeSendReply(TSBFTPSServerBeforeSendReplyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServer_set_OnBeforeSendReply(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServer::get_OnCommandProcessed(TSBFTPSServerCommandProcessedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServer_get_OnCommandProcessed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServer::set_OnCommandProcessed(TSBFTPSServerCommandProcessedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServer_set_OnCommandProcessed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServer::get_OnTransferProgress(TSBFTPSServerTransferProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServer_get_OnTransferProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServer::set_OnTransferProgress(TSBFTPSServerTransferProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServer_set_OnTransferProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServer::get_OnTransferCompleted(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServer_get_OnTransferCompleted(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServer::set_OnTransferCompleted(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServer_set_OnTransferCompleted(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServer::get_OnSessionException(TSBFTPSServerExceptionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServer_get_OnSessionException(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServer::set_OnSessionException(TSBFTPSServerExceptionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServer_set_OnSessionException(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServer::get_OnCommandUnhandled(TSBFTPSServerCommandUnhandledEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServer_get_OnCommandUnhandled(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServer::set_OnCommandUnhandled(TSBFTPSServerCommandUnhandledEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServer_set_OnCommandUnhandled(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServer::get_OnSiteCommand(TSBFTPSServerSiteCommandEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServer_get_OnSiteCommand(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServer::set_OnSiteCommand(TSBFTPSServerSiteCommandEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServer_set_OnSiteCommand(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServer::get_OnFileAllocate(TSBFTPSServerFileAllocateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServer_get_OnFileAllocate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServer::set_OnFileAllocate(TSBFTPSServerFileAllocateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServer_set_OnFileAllocate(_Handle, pMethodValue, pDataValue));
}

void TElSimpleFTPSServer::initInstances()
{
#ifdef SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE
	this->_Inst_MessageTable = NULL;
#endif /* SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	this->_Inst_OutgoingLocalBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
	this->_Inst_SocketSettings = NULL;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELSESSIONPOOL
	this->_Inst_SessionPool = NULL;
#endif /* SB_USE_CLASS_TELSESSIONPOOL */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_ClientCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
#ifdef SB_USE_CLASS_TELFTPSUSERS
	this->_Inst_Users = NULL;
#endif /* SB_USE_CLASS_TELFTPSUSERS */
}

TElSimpleFTPSServer::TElSimpleFTPSServer(TElSimpleFTPSServerHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElSimpleFTPSServer::TElSimpleFTPSServer(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleFTPSServer_Create(AOwner.getHandle(), &_Handle));
}

TElSimpleFTPSServer::TElSimpleFTPSServer(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleFTPSServer_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSimpleFTPSServer::~TElSimpleFTPSServer()
{
#ifdef SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE
	delete this->_Inst_MessageTable;
	this->_Inst_MessageTable = NULL;
#endif /* SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	delete this->_Inst_OutgoingLocalBinding;
	this->_Inst_OutgoingLocalBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
	delete this->_Inst_SocketSettings;
	this->_Inst_SocketSettings = NULL;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELSESSIONPOOL
	delete this->_Inst_SessionPool;
	this->_Inst_SessionPool = NULL;
#endif /* SB_USE_CLASS_TELSESSIONPOOL */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_ClientCertStorage;
	this->_Inst_ClientCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	delete this->_Inst_FileSystemAdapter;
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
#ifdef SB_USE_CLASS_TELFTPSUSERS
	delete this->_Inst_Users;
	this->_Inst_Users = NULL;
#endif /* SB_USE_CLASS_TELFTPSUSERS */
}
#endif /* SB_USE_CLASS_TELSIMPLEFTPSSERVER */

#ifdef SB_USE_CLASS_TELSIMPLEFTPSSERVERLISTENINGTHREAD

#ifdef SB_USE_CLASS_TELSOCKET
TElSocket* TElSimpleFTPSServerListeningThread::get_Socket()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSServerListeningThread_get_Socket(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Socket)
		this->_Inst_Socket = new TElSocket(hOutResult, ohFalse);
	else
		this->_Inst_Socket->updateHandle(hOutResult);
	return this->_Inst_Socket;
}

SB_INLINE void TElSimpleFTPSServerListeningThread::set_Socket(TElSocket &Value)
{
	SBCheckError(TElSimpleFTPSServerListeningThread_set_Socket(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleFTPSServerListeningThread::set_Socket(TElSocket *Value)
{
	SBCheckError(TElSimpleFTPSServerListeningThread_set_Socket(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSOCKET */

SB_INLINE void TElSimpleFTPSServerListeningThread::get_OnNewConnection(TSBSimpleFTPSListenerNewConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServerListeningThread_get_OnNewConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServerListeningThread::set_OnNewConnection(TSBSimpleFTPSListenerNewConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServerListeningThread_set_OnNewConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSServerListeningThread::get_OnClose(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSServerListeningThread_get_OnClose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSServerListeningThread::set_OnClose(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSServerListeningThread_set_OnClose(_Handle, pMethodValue, pDataValue));
}

void TElSimpleFTPSServerListeningThread::initInstances()
{
#ifdef SB_USE_CLASS_TELSOCKET
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
}

TElSimpleFTPSServerListeningThread::TElSimpleFTPSServerListeningThread(TElSimpleFTPSServerListeningThreadHandle handle, TElOwnHandle ownHandle) : TThread(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELSIMPLEFTPSSERVER
TElSimpleFTPSServerListeningThread::TElSimpleFTPSServerListeningThread(TElSimpleFTPSServer &Owner) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleFTPSServerListeningThread_Create(Owner.getHandle(), &_Handle));
}

TElSimpleFTPSServerListeningThread::TElSimpleFTPSServerListeningThread(TElSimpleFTPSServer *Owner) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleFTPSServerListeningThread_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSIMPLEFTPSSERVER */

TElSimpleFTPSServerListeningThread::~TElSimpleFTPSServerListeningThread()
{
#ifdef SB_USE_CLASS_TELSOCKET
	delete this->_Inst_Socket;
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
}
#endif /* SB_USE_CLASS_TELSIMPLEFTPSSERVERLISTENINGTHREAD */

#ifdef SB_USE_CLASS_TELFTPSUSERS

SB_INLINE void TElFTPSUsers::AddFTPSUser(const std::string &UserName, const std::string &Password)
{
	SBCheckError(TElFTPSUsers_AddFTPSUser(_Handle, UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length()));
}

SB_INLINE void TElFTPSUsers::AddFTPSUser(const std::string &UserName, const std::string &Password, const std::string &BasePath)
{
	SBCheckError(TElFTPSUsers_AddFTPSUser_1(_Handle, UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), BasePath.data(), (int32_t)BasePath.length()));
}

SB_INLINE void TElFTPSUsers::AddFTPSUser(const std::string &UserName, const std::string &Password, const std::string &BasePath, int32_t OutgoingSpeedLimit, int32_t IncomingSpeedLimit)
{
	SBCheckError(TElFTPSUsers_AddFTPSUser_2(_Handle, UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), BasePath.data(), (int32_t)BasePath.length(), OutgoingSpeedLimit, IncomingSpeedLimit));
}

SB_INLINE void TElFTPSUsers::UpdateFTPSUser(const std::string &UserName, const std::string &Password)
{
	SBCheckError(TElFTPSUsers_UpdateFTPSUser(_Handle, UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length()));
}

#ifdef SB_USE_CLASS_TELFTPSUSER
SB_INLINE TElFTPSUserHandle TElFTPSUsers::FindFTPSUser(const std::string &UserName)
{
	TElFTPSUserHandle OutResult;
	SBCheckError(TElFTPSUsers_FindFTPSUser(_Handle, UserName.data(), (int32_t)UserName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELFTPSUSER */

#ifdef SB_USE_CLASS_TELFTPSUSER
TElFTPSUser* TElFTPSUsers::get_FTPSUsers(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFTPSUsers_get_FTPSUsers(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FTPSUsers)
		this->_Inst_FTPSUsers = new TElFTPSUser(hOutResult, ohFalse);
	else
		this->_Inst_FTPSUsers->updateHandle(hOutResult);
	return this->_Inst_FTPSUsers;
}
#endif /* SB_USE_CLASS_TELFTPSUSER */

void TElFTPSUsers::initInstances()
{
#ifdef SB_USE_CLASS_TELFTPSUSER
	this->_Inst_FTPSUsers = NULL;
#endif /* SB_USE_CLASS_TELFTPSUSER */
}

TElFTPSUsers::TElFTPSUsers(TElFTPSUsersHandle handle, TElOwnHandle ownHandle) : TElUsers(handle, ownHandle)
{
	initInstances();
}

TElFTPSUsers::TElFTPSUsers(TComponent &AOwner) : TElUsers(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElFTPSUsers_Create(AOwner.getHandle(), &_Handle));
}

TElFTPSUsers::TElFTPSUsers(TComponent *AOwner) : TElUsers(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElFTPSUsers_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElFTPSUsers::~TElFTPSUsers()
{
#ifdef SB_USE_CLASS_TELFTPSUSER
	delete this->_Inst_FTPSUsers;
	this->_Inst_FTPSUsers = NULL;
#endif /* SB_USE_CLASS_TELFTPSUSER */
}
#endif /* SB_USE_CLASS_TELFTPSUSERS */

};	/* namespace SecureBlackbox */
