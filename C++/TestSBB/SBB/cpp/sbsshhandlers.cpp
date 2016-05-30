#include "sbsshhandlers.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELCUSTOMSSHSUBSYSTEMHANDLER

TSBSSHSubsystemHandlerType TElCustomSSHSubsystemHandler::HandlerType()
{
	TSBSSHSubsystemHandlerTypeRaw OutResultRaw = 0;
	SBCheckError(TElCustomSSHSubsystemHandler_HandlerType(_Handle, &OutResultRaw));
	return (TSBSSHSubsystemHandlerType)OutResultRaw;
}

SB_INLINE void TElCustomSSHSubsystemHandler::Run()
{
	SBCheckError(TElCustomSSHSubsystemHandler_Run(_Handle));
}

SB_INLINE void TElCustomSSHSubsystemHandler::Terminate()
{
	SBCheckError(TElCustomSSHSubsystemHandler_Terminate(_Handle));
}

bool TElCustomSSHSubsystemHandler::WaitForInputData(int32_t Time)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomSSHSubsystemHandler_WaitForInputData(_Handle, Time, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TClassHandle TElCustomSSHSubsystemHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElCustomSSHSubsystemHandler_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElSSHTunnelConnection* TElCustomSSHSubsystemHandler::get_Connection()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomSSHSubsystemHandler_get_Connection(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Connection)
		this->_Inst_Connection = new TElSSHTunnelConnection(hOutResult, ohFalse);
	else
		this->_Inst_Connection->updateHandle(hOutResult);
	return this->_Inst_Connection;
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

bool TElCustomSSHSubsystemHandler::get_FlushCachedData()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomSSHSubsystemHandler_get_FlushCachedData(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomSSHSubsystemHandler::set_FlushCachedData(bool Value)
{
	SBCheckError(TElCustomSSHSubsystemHandler_set_FlushCachedData(_Handle, (int8_t)Value));
}

SB_INLINE void TElCustomSSHSubsystemHandler::get_OnTerminateRequest(TSBSSHSubsystemHandlerTerminateRequest &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomSSHSubsystemHandler_get_OnTerminateRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomSSHSubsystemHandler::set_OnTerminateRequest(TSBSSHSubsystemHandlerTerminateRequest pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomSSHSubsystemHandler_set_OnTerminateRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCustomSSHSubsystemHandler::get_OnDisconnect(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomSSHSubsystemHandler_get_OnDisconnect(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomSSHSubsystemHandler::set_OnDisconnect(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomSSHSubsystemHandler_set_OnDisconnect(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCustomSSHSubsystemHandler::get_OnUnsafeOperationStart(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomSSHSubsystemHandler_get_OnUnsafeOperationStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomSSHSubsystemHandler::set_OnUnsafeOperationStart(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomSSHSubsystemHandler_set_OnUnsafeOperationStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCustomSSHSubsystemHandler::get_OnUnsafeOperationEnd(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomSSHSubsystemHandler_get_OnUnsafeOperationEnd(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomSSHSubsystemHandler::set_OnUnsafeOperationEnd(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomSSHSubsystemHandler_set_OnUnsafeOperationEnd(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCustomSSHSubsystemHandler::get_OnEOF(TSSHEOFEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomSSHSubsystemHandler_get_OnEOF(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomSSHSubsystemHandler::set_OnEOF(TSSHEOFEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomSSHSubsystemHandler_set_OnEOF(_Handle, pMethodValue, pDataValue));
}

void TElCustomSSHSubsystemHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
	this->_Inst_Connection = NULL;
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */
}

TElCustomSSHSubsystemHandler::TElCustomSSHSubsystemHandler(TElCustomSSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElCustomSSHSubsystemHandler::TElCustomSSHSubsystemHandler(TElSSHTunnelConnection &Connection) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomSSHSubsystemHandler_Create(Connection.getHandle(), &_Handle));
}

TElCustomSSHSubsystemHandler::TElCustomSSHSubsystemHandler(TElSSHTunnelConnection *Connection) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomSSHSubsystemHandler_Create((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElCustomSSHSubsystemHandler TElCustomSSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection &Connection)
{
	TElCustomSSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElCustomSSHSubsystemHandler_CreateDelayed(Connection.getHandle(), &_Handle));
	return TElCustomSSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}

TElCustomSSHSubsystemHandler TElCustomSSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection *Connection)
{
	TElCustomSSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElCustomSSHSubsystemHandler_CreateDelayed((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
	return TElCustomSSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

TElCustomSSHSubsystemHandler::~TElCustomSSHSubsystemHandler()
{
#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
	delete this->_Inst_Connection;
	this->_Inst_Connection = NULL;
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */
}
#endif /* SB_USE_CLASS_TELCUSTOMSSHSUBSYSTEMHANDLER */

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELSHELLSSHSUBSYSTEMHANDLER

TSBSSHSubsystemHandlerType TElShellSSHSubsystemHandler::HandlerType()
{
	TSBSSHSubsystemHandlerTypeRaw OutResultRaw = 0;
	SBCheckError(TElShellSSHSubsystemHandler_HandlerType(_Handle, &OutResultRaw));
	return (TSBSSHSubsystemHandlerType)OutResultRaw;
}

SB_INLINE TClassHandle TElShellSSHSubsystemHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElShellSSHSubsystemHandler_ClassType(&OutResult));
	return OutResult;
}

void TElShellSSHSubsystemHandler::get_Command(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElShellSSHSubsystemHandler_get_Command(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1248347555, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElShellSSHSubsystemHandler::set_Command(const std::string &Value)
{
	SBCheckError(TElShellSSHSubsystemHandler_set_Command(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElShellSSHSubsystemHandler::get_RawCommandLine(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElShellSSHSubsystemHandler_get_RawCommandLine(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1734105515, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElShellSSHSubsystemHandler::set_RawCommandLine(const std::string &Value)
{
	SBCheckError(TElShellSSHSubsystemHandler_set_RawCommandLine(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElShellSSHSubsystemHandler::get_CurrentDirectory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElShellSSHSubsystemHandler_get_CurrentDirectory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(576182102, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElShellSSHSubsystemHandler::set_CurrentDirectory(const std::string &Value)
{
	SBCheckError(TElShellSSHSubsystemHandler_set_CurrentDirectory(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElShellSSHSubsystemHandler::get_NoCharacterEncoding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElShellSSHSubsystemHandler_get_NoCharacterEncoding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElShellSSHSubsystemHandler::set_NoCharacterEncoding(bool Value)
{
	SBCheckError(TElShellSSHSubsystemHandler_set_NoCharacterEncoding(_Handle, (int8_t)Value));
}

bool TElShellSSHSubsystemHandler::get_UseUTF8()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElShellSSHSubsystemHandler_get_UseUTF8(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElShellSSHSubsystemHandler::set_UseUTF8(bool Value)
{
	SBCheckError(TElShellSSHSubsystemHandler_set_UseUTF8(_Handle, (int8_t)Value));
}

bool TElShellSSHSubsystemHandler::get_OutputLines()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElShellSSHSubsystemHandler_get_OutputLines(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElShellSSHSubsystemHandler::set_OutputLines(bool Value)
{
	SBCheckError(TElShellSSHSubsystemHandler_set_OutputLines(_Handle, (int8_t)Value));
}

bool TElShellSSHSubsystemHandler::get_SendCharactersBack()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElShellSSHSubsystemHandler_get_SendCharactersBack(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElShellSSHSubsystemHandler::set_SendCharactersBack(bool Value)
{
	SBCheckError(TElShellSSHSubsystemHandler_set_SendCharactersBack(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElShellSSHSubsystemHandler::get_MaxCacheSize()
{
	int32_t OutResult;
	SBCheckError(TElShellSSHSubsystemHandler_get_MaxCacheSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElShellSSHSubsystemHandler::set_MaxCacheSize(int32_t Value)
{
	SBCheckError(TElShellSSHSubsystemHandler_set_MaxCacheSize(_Handle, Value));
}

SB_INLINE void TElShellSSHSubsystemHandler::get_OnBeforeDecoding(TSBSSHEncodedStringEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElShellSSHSubsystemHandler_get_OnBeforeDecoding(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElShellSSHSubsystemHandler::set_OnBeforeDecoding(TSBSSHEncodedStringEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElShellSSHSubsystemHandler_set_OnBeforeDecoding(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElShellSSHSubsystemHandler::get_OnAfterEncoding(TSBSSHEncodedStringEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElShellSSHSubsystemHandler_get_OnAfterEncoding(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElShellSSHSubsystemHandler::set_OnAfterEncoding(TSBSSHEncodedStringEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElShellSSHSubsystemHandler_set_OnAfterEncoding(_Handle, pMethodValue, pDataValue));
}

TElShellSSHSubsystemHandler::TElShellSSHSubsystemHandler(TElShellSSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle) : TElCustomSSHSubsystemHandler(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElShellSSHSubsystemHandler::TElShellSSHSubsystemHandler(TElSSHTunnelConnection &Connection) : TElCustomSSHSubsystemHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElShellSSHSubsystemHandler_Create(Connection.getHandle(), &_Handle));
}

TElShellSSHSubsystemHandler::TElShellSSHSubsystemHandler(TElSSHTunnelConnection *Connection) : TElCustomSSHSubsystemHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElShellSSHSubsystemHandler_Create((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElShellSSHSubsystemHandler TElShellSSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection &Connection)
{
	TElShellSSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElShellSSHSubsystemHandler_CreateDelayed(Connection.getHandle(), &_Handle));
	return TElShellSSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}

TElShellSSHSubsystemHandler TElShellSSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection *Connection)
{
	TElShellSSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElShellSSHSubsystemHandler_CreateDelayed((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
	return TElShellSSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#endif /* SB_USE_CLASS_TELSHELLSSHSUBSYSTEMHANDLER */
#endif

#ifdef SB_USE_CLASS_TELCUSTOMSOCKETFORWARDINGSSHSUBSYSTEMHANDLER

TSBSSHSubsystemHandlerType TElCustomSocketForwardingSSHSubsystemHandler::HandlerType()
{
	TSBSSHSubsystemHandlerTypeRaw OutResultRaw = 0;
	SBCheckError(TElCustomSocketForwardingSSHSubsystemHandler_HandlerType(_Handle, &OutResultRaw));
	return (TSBSSHSubsystemHandlerType)OutResultRaw;
}

SB_INLINE TClassHandle TElCustomSocketForwardingSSHSubsystemHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElCustomSocketForwardingSSHSubsystemHandler_ClassType(&OutResult));
	return OutResult;
}

void TElCustomSocketForwardingSSHSubsystemHandler::get_Host(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomSocketForwardingSSHSubsystemHandler_get_Host(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-676748603, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomSocketForwardingSSHSubsystemHandler::set_Host(const std::string &Value)
{
	SBCheckError(TElCustomSocketForwardingSSHSubsystemHandler_set_Host(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElCustomSocketForwardingSSHSubsystemHandler::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElCustomSocketForwardingSSHSubsystemHandler_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomSocketForwardingSSHSubsystemHandler::set_Port(int32_t Value)
{
	SBCheckError(TElCustomSocketForwardingSSHSubsystemHandler_set_Port(_Handle, Value));
}

SB_INLINE int32_t TElCustomSocketForwardingSSHSubsystemHandler::get_Timeout()
{
	int32_t OutResult;
	SBCheckError(TElCustomSocketForwardingSSHSubsystemHandler_get_Timeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomSocketForwardingSSHSubsystemHandler::set_Timeout(int32_t Value)
{
	SBCheckError(TElCustomSocketForwardingSSHSubsystemHandler_set_Timeout(_Handle, Value));
}

TElCustomSocketForwardingSSHSubsystemHandler::TElCustomSocketForwardingSSHSubsystemHandler(TElCustomSocketForwardingSSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle) : TElCustomSSHSubsystemHandler(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElCustomSocketForwardingSSHSubsystemHandler::TElCustomSocketForwardingSSHSubsystemHandler(TElSSHTunnelConnection &Connection) : TElCustomSSHSubsystemHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomSocketForwardingSSHSubsystemHandler_Create(Connection.getHandle(), &_Handle));
}

TElCustomSocketForwardingSSHSubsystemHandler::TElCustomSocketForwardingSSHSubsystemHandler(TElSSHTunnelConnection *Connection) : TElCustomSSHSubsystemHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomSocketForwardingSSHSubsystemHandler_Create((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElCustomSocketForwardingSSHSubsystemHandler TElCustomSocketForwardingSSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection &Connection)
{
	TElCustomSocketForwardingSSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElCustomSocketForwardingSSHSubsystemHandler_CreateDelayed(Connection.getHandle(), &_Handle));
	return TElCustomSocketForwardingSSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}

TElCustomSocketForwardingSSHSubsystemHandler TElCustomSocketForwardingSSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection *Connection)
{
	TElCustomSocketForwardingSSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElCustomSocketForwardingSSHSubsystemHandler_CreateDelayed((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
	return TElCustomSocketForwardingSSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#endif /* SB_USE_CLASS_TELCUSTOMSOCKETFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef SB_USE_CLASS_TELSSHSUBSYSTEMTHREAD

#ifdef SB_USE_CLASS_TELCUSTOMSSHSUBSYSTEMHANDLER
TElCustomSSHSubsystemHandler* TElSSHSubsystemThread::get_Handler()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHSubsystemThread_get_Handler(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Handler)
		this->_Inst_Handler = new TElCustomSSHSubsystemHandler(hOutResult, ohFalse);
	else
		this->_Inst_Handler->updateHandle(hOutResult);
	return this->_Inst_Handler;
}
#endif /* SB_USE_CLASS_TELCUSTOMSSHSUBSYSTEMHANDLER */

SB_INLINE void TElSSHSubsystemThread::get_OnTerminateSubsystem(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHSubsystemThread_get_OnTerminateSubsystem(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHSubsystemThread::set_OnTerminateSubsystem(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHSubsystemThread_set_OnTerminateSubsystem(_Handle, pMethodValue, pDataValue));
}

void TElSSHSubsystemThread::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMSSHSUBSYSTEMHANDLER
	this->_Inst_Handler = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSSHSUBSYSTEMHANDLER */
}

TElSSHSubsystemThread::TElSSHSubsystemThread(TElSSHSubsystemThreadHandle handle, TElOwnHandle ownHandle) : TThread(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElSSHSubsystemThread::TElSSHSubsystemThread(TElSSHSubsystemHandlerClassHandle Cls, TElSSHTunnelConnection &Connection, bool CreateSuspended) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHSubsystemThread_Create(Cls, Connection.getHandle(), (int8_t)CreateSuspended, &_Handle));
}

TElSSHSubsystemThread::TElSSHSubsystemThread(TElSSHSubsystemHandlerClassHandle Cls, TElSSHTunnelConnection *Connection, bool CreateSuspended) : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHSubsystemThread_Create(Cls, (Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, (int8_t)CreateSuspended, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

TElSSHSubsystemThread::~TElSSHSubsystemThread()
{
#ifdef SB_USE_CLASS_TELCUSTOMSSHSUBSYSTEMHANDLER
	delete this->_Inst_Handler;
	this->_Inst_Handler = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSSHSUBSYSTEMHANDLER */
}
#endif /* SB_USE_CLASS_TELSSHSUBSYSTEMTHREAD */

};	/* namespace SecureBlackbox */
