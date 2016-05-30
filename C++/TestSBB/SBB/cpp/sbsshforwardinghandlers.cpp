#include "sbsshforwardinghandlers.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELTCPFORWARDINGSSHSUBSYSTEMHANDLER

SB_INLINE TClassHandle TElTCPForwardingSSHSubsystemHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElTCPForwardingSSHSubsystemHandler_ClassType(&OutResult));
	return OutResult;
}

TElTCPForwardingSSHSubsystemHandler::TElTCPForwardingSSHSubsystemHandler(TElTCPForwardingSSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle) : TElCustomSocketForwardingSSHSubsystemHandler(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElTCPForwardingSSHSubsystemHandler::TElTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection &Connection) : TElCustomSocketForwardingSSHSubsystemHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTCPForwardingSSHSubsystemHandler_Create(Connection.getHandle(), &_Handle));
}

TElTCPForwardingSSHSubsystemHandler::TElTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection *Connection) : TElCustomSocketForwardingSSHSubsystemHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTCPForwardingSSHSubsystemHandler_Create((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElTCPForwardingSSHSubsystemHandler TElTCPForwardingSSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection &Connection)
{
	TElTCPForwardingSSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElTCPForwardingSSHSubsystemHandler_CreateDelayed(Connection.getHandle(), &_Handle));
	return TElTCPForwardingSSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}

TElTCPForwardingSSHSubsystemHandler TElTCPForwardingSSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection *Connection)
{
	TElTCPForwardingSSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElTCPForwardingSSHSubsystemHandler_CreateDelayed((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
	return TElTCPForwardingSSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#endif /* SB_USE_CLASS_TELTCPFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef SB_USE_CLASS_TELCLIENTTCPFORWARDINGSSHSUBSYSTEMHANDLER

SB_INLINE TClassHandle TElClientTCPForwardingSSHSubsystemHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElClientTCPForwardingSSHSubsystemHandler_ClassType(&OutResult));
	return OutResult;
}

TElClientTCPForwardingSSHSubsystemHandler::TElClientTCPForwardingSSHSubsystemHandler(TElClientTCPForwardingSSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle) : TElTCPForwardingSSHSubsystemHandler(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElClientTCPForwardingSSHSubsystemHandler::TElClientTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection &Connection) : TElTCPForwardingSSHSubsystemHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElClientTCPForwardingSSHSubsystemHandler_Create(Connection.getHandle(), &_Handle));
}

TElClientTCPForwardingSSHSubsystemHandler::TElClientTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection *Connection) : TElTCPForwardingSSHSubsystemHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElClientTCPForwardingSSHSubsystemHandler_Create((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElClientTCPForwardingSSHSubsystemHandler TElClientTCPForwardingSSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection &Connection)
{
	TElClientTCPForwardingSSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElClientTCPForwardingSSHSubsystemHandler_CreateDelayed(Connection.getHandle(), &_Handle));
	return TElClientTCPForwardingSSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}

TElClientTCPForwardingSSHSubsystemHandler TElClientTCPForwardingSSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection *Connection)
{
	TElClientTCPForwardingSSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElClientTCPForwardingSSHSubsystemHandler_CreateDelayed((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
	return TElClientTCPForwardingSSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#endif /* SB_USE_CLASS_TELCLIENTTCPFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef SB_USE_CLASS_TELSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER

SB_INLINE TClassHandle TElServerTCPForwardingSSHSubsystemHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElServerTCPForwardingSSHSubsystemHandler_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSOCKET
TElSocket* TElServerTCPForwardingSSHSubsystemHandler::get_Socket()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElServerTCPForwardingSSHSubsystemHandler_get_Socket(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Socket)
		this->_Inst_Socket = new TElSocket(hOutResult, ohFalse);
	else
		this->_Inst_Socket->updateHandle(hOutResult);
	return this->_Inst_Socket;
}

SB_INLINE void TElServerTCPForwardingSSHSubsystemHandler::set_Socket(TElSocket &Value)
{
	SBCheckError(TElServerTCPForwardingSSHSubsystemHandler_set_Socket(_Handle, Value.getHandle()));
}

SB_INLINE void TElServerTCPForwardingSSHSubsystemHandler::set_Socket(TElSocket *Value)
{
	SBCheckError(TElServerTCPForwardingSSHSubsystemHandler_set_Socket(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSOCKET */

void TElServerTCPForwardingSSHSubsystemHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELSOCKET
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
}

TElServerTCPForwardingSSHSubsystemHandler::TElServerTCPForwardingSSHSubsystemHandler(TElServerTCPForwardingSSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle) : TElTCPForwardingSSHSubsystemHandler(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElServerTCPForwardingSSHSubsystemHandler::TElServerTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection &Connection) : TElTCPForwardingSSHSubsystemHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElServerTCPForwardingSSHSubsystemHandler_Create(Connection.getHandle(), &_Handle));
}

TElServerTCPForwardingSSHSubsystemHandler::TElServerTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection *Connection) : TElTCPForwardingSSHSubsystemHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElServerTCPForwardingSSHSubsystemHandler_Create((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElServerTCPForwardingSSHSubsystemHandler TElServerTCPForwardingSSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection &Connection)
{
	TElServerTCPForwardingSSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElServerTCPForwardingSSHSubsystemHandler_CreateDelayed(Connection.getHandle(), &_Handle));
	return TElServerTCPForwardingSSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}

TElServerTCPForwardingSSHSubsystemHandler TElServerTCPForwardingSSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection *Connection)
{
	TElServerTCPForwardingSSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElServerTCPForwardingSSHSubsystemHandler_CreateDelayed((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
	return TElServerTCPForwardingSSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

TElServerTCPForwardingSSHSubsystemHandler::~TElServerTCPForwardingSSHSubsystemHandler()
{
#ifdef SB_USE_CLASS_TELSOCKET
	delete this->_Inst_Socket;
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
}
#endif /* SB_USE_CLASS_TELSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef SB_USE_CLASS_TELBUILTINTCPFORWARDINGSSHSUBSYSTEMHANDLER

SB_INLINE TClassHandle TElBuiltinTCPForwardingSSHSubsystemHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltinTCPForwardingSSHSubsystemHandler_ClassType(&OutResult));
	return OutResult;
}

TElBuiltinTCPForwardingSSHSubsystemHandler::TElBuiltinTCPForwardingSSHSubsystemHandler(TElBuiltinTCPForwardingSSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle) : TElCustomSocketForwardingSSHSubsystemHandler(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElBuiltinTCPForwardingSSHSubsystemHandler::TElBuiltinTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection &Connection) : TElCustomSocketForwardingSSHSubsystemHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltinTCPForwardingSSHSubsystemHandler_Create(Connection.getHandle(), &_Handle));
}

TElBuiltinTCPForwardingSSHSubsystemHandler::TElBuiltinTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection *Connection) : TElCustomSocketForwardingSSHSubsystemHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltinTCPForwardingSSHSubsystemHandler_Create((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElBuiltinTCPForwardingSSHSubsystemHandler TElBuiltinTCPForwardingSSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection &Connection)
{
	TElBuiltinTCPForwardingSSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElBuiltinTCPForwardingSSHSubsystemHandler_CreateDelayed(Connection.getHandle(), &_Handle));
	return TElBuiltinTCPForwardingSSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}

TElBuiltinTCPForwardingSSHSubsystemHandler TElBuiltinTCPForwardingSSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection *Connection)
{
	TElBuiltinTCPForwardingSSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElBuiltinTCPForwardingSSHSubsystemHandler_CreateDelayed((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
	return TElBuiltinTCPForwardingSSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#endif /* SB_USE_CLASS_TELBUILTINTCPFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef SB_USE_CLASS_TELBUILTINCLIENTTCPFORWARDINGSSHSUBSYSTEMHANDLER

SB_INLINE TClassHandle TElBuiltinClientTCPForwardingSSHSubsystemHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltinClientTCPForwardingSSHSubsystemHandler_ClassType(&OutResult));
	return OutResult;
}

TElBuiltinClientTCPForwardingSSHSubsystemHandler::TElBuiltinClientTCPForwardingSSHSubsystemHandler(TElBuiltinClientTCPForwardingSSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle) : TElBuiltinTCPForwardingSSHSubsystemHandler(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElBuiltinClientTCPForwardingSSHSubsystemHandler::TElBuiltinClientTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection &Connection) : TElBuiltinTCPForwardingSSHSubsystemHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltinClientTCPForwardingSSHSubsystemHandler_Create(Connection.getHandle(), &_Handle));
}

TElBuiltinClientTCPForwardingSSHSubsystemHandler::TElBuiltinClientTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection *Connection) : TElBuiltinTCPForwardingSSHSubsystemHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBuiltinClientTCPForwardingSSHSubsystemHandler_Create((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElBuiltinClientTCPForwardingSSHSubsystemHandler TElBuiltinClientTCPForwardingSSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection &Connection)
{
	TElBuiltinClientTCPForwardingSSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElBuiltinClientTCPForwardingSSHSubsystemHandler_CreateDelayed(Connection.getHandle(), &_Handle));
	return TElBuiltinClientTCPForwardingSSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}

TElBuiltinClientTCPForwardingSSHSubsystemHandler TElBuiltinClientTCPForwardingSSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection *Connection)
{
	TElBuiltinClientTCPForwardingSSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElBuiltinClientTCPForwardingSSHSubsystemHandler_CreateDelayed((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
	return TElBuiltinClientTCPForwardingSSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#endif /* SB_USE_CLASS_TELBUILTINCLIENTTCPFORWARDINGSSHSUBSYSTEMHANDLER */

#ifdef SB_USE_CLASS_TELBUILTINSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER

SB_INLINE TClassHandle TElBuiltinServerTCPForwardingSSHSubsystemHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElBuiltinServerTCPForwardingSSHSubsystemHandler_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSOCKET
TElSocket* TElBuiltinServerTCPForwardingSSHSubsystemHandler::get_Socket()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElBuiltinServerTCPForwardingSSHSubsystemHandler_get_Socket(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Socket)
		this->_Inst_Socket = new TElSocket(hOutResult, ohFalse);
	else
		this->_Inst_Socket->updateHandle(hOutResult);
	return this->_Inst_Socket;
}

SB_INLINE void TElBuiltinServerTCPForwardingSSHSubsystemHandler::set_Socket(TElSocket &Value)
{
	SBCheckError(TElBuiltinServerTCPForwardingSSHSubsystemHandler_set_Socket(_Handle, Value.getHandle()));
}

SB_INLINE void TElBuiltinServerTCPForwardingSSHSubsystemHandler::set_Socket(TElSocket *Value)
{
	SBCheckError(TElBuiltinServerTCPForwardingSSHSubsystemHandler_set_Socket(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSOCKET */

void TElBuiltinServerTCPForwardingSSHSubsystemHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELSOCKET
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
}

TElBuiltinServerTCPForwardingSSHSubsystemHandler::TElBuiltinServerTCPForwardingSSHSubsystemHandler(TElBuiltinServerTCPForwardingSSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle) : TElBuiltinTCPForwardingSSHSubsystemHandler(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElBuiltinServerTCPForwardingSSHSubsystemHandler::TElBuiltinServerTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection &Connection) : TElBuiltinTCPForwardingSSHSubsystemHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBuiltinServerTCPForwardingSSHSubsystemHandler_Create(Connection.getHandle(), &_Handle));
}

TElBuiltinServerTCPForwardingSSHSubsystemHandler::TElBuiltinServerTCPForwardingSSHSubsystemHandler(TElSSHTunnelConnection *Connection) : TElBuiltinTCPForwardingSSHSubsystemHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElBuiltinServerTCPForwardingSSHSubsystemHandler_Create((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElBuiltinServerTCPForwardingSSHSubsystemHandler TElBuiltinServerTCPForwardingSSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection &Connection)
{
	TElBuiltinServerTCPForwardingSSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElBuiltinServerTCPForwardingSSHSubsystemHandler_CreateDelayed(Connection.getHandle(), &_Handle));
	return TElBuiltinServerTCPForwardingSSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}

TElBuiltinServerTCPForwardingSSHSubsystemHandler TElBuiltinServerTCPForwardingSSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection *Connection)
{
	TElBuiltinServerTCPForwardingSSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElBuiltinServerTCPForwardingSSHSubsystemHandler_CreateDelayed((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
	return TElBuiltinServerTCPForwardingSSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

TElBuiltinServerTCPForwardingSSHSubsystemHandler::~TElBuiltinServerTCPForwardingSSHSubsystemHandler()
{
#ifdef SB_USE_CLASS_TELSOCKET
	delete this->_Inst_Socket;
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
}
#endif /* SB_USE_CLASS_TELBUILTINSERVERTCPFORWARDINGSSHSUBSYSTEMHANDLER */

};	/* namespace SecureBlackbox */

