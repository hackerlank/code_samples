#include "sbsshpubkeyhandler.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPUBLICKEYSSHSUBSYSTEMHANDLER

TSBSSHSubsystemHandlerType TElPublicKeySSHSubsystemHandler::HandlerType()
{
	TSBSSHSubsystemHandlerTypeRaw OutResultRaw = 0;
	SBCheckError(TElPublicKeySSHSubsystemHandler_HandlerType(_Handle, &OutResultRaw));
	return (TSBSSHSubsystemHandlerType)OutResultRaw;
}

SB_INLINE TClassHandle TElPublicKeySSHSubsystemHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPublicKeySSHSubsystemHandler_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSSHPUBLICKEYSERVER
TElSSHPublicKeyServer* TElPublicKeySSHSubsystemHandler::get_Server()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPublicKeySSHSubsystemHandler_get_Server(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Server)
		this->_Inst_Server = new TElSSHPublicKeyServer(hOutResult, ohFalse);
	else
		this->_Inst_Server->updateHandle(hOutResult);
	return this->_Inst_Server;
}

SB_INLINE void TElPublicKeySSHSubsystemHandler::set_Server(TElSSHPublicKeyServer &Value)
{
	SBCheckError(TElPublicKeySSHSubsystemHandler_set_Server(_Handle, Value.getHandle()));
}

SB_INLINE void TElPublicKeySSHSubsystemHandler::set_Server(TElSSHPublicKeyServer *Value)
{
	SBCheckError(TElPublicKeySSHSubsystemHandler_set_Server(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHPUBLICKEYSERVER */

void TElPublicKeySSHSubsystemHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELSSHPUBLICKEYSERVER
	this->_Inst_Server = NULL;
#endif /* SB_USE_CLASS_TELSSHPUBLICKEYSERVER */
}

TElPublicKeySSHSubsystemHandler::TElPublicKeySSHSubsystemHandler(TElPublicKeySSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle) : TElCustomSSHSubsystemHandler(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElPublicKeySSHSubsystemHandler::TElPublicKeySSHSubsystemHandler(TElSSHTunnelConnection &Connection) : TElCustomSSHSubsystemHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPublicKeySSHSubsystemHandler_Create(Connection.getHandle(), &_Handle));
}

TElPublicKeySSHSubsystemHandler::TElPublicKeySSHSubsystemHandler(TElSSHTunnelConnection *Connection) : TElCustomSSHSubsystemHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPublicKeySSHSubsystemHandler_Create((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASSES_TELSSHPUBLICKEYSERVER_AND_TELSSHTUNNELCONNECTION
TElPublicKeySSHSubsystemHandler TElPublicKeySSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection &Connection, TElSSHPublicKeyServer &Server)
{
	TElPublicKeySSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElPublicKeySSHSubsystemHandler_CreateDelayed(Connection.getHandle(), Server.getHandle(), &_Handle));
	return TElPublicKeySSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}

TElPublicKeySSHSubsystemHandler TElPublicKeySSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection *Connection, TElSSHPublicKeyServer *Server)
{
	TElPublicKeySSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElPublicKeySSHSubsystemHandler_CreateDelayed((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, (Server != NULL) ? Server->getHandle() : SB_NULL_HANDLE, &_Handle));
	return TElPublicKeySSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}
#endif /* SB_USE_CLASSES_TELSSHPUBLICKEYSERVER_AND_TELSSHTUNNELCONNECTION */

TElPublicKeySSHSubsystemHandler::~TElPublicKeySSHSubsystemHandler()
{
#ifdef SB_USE_CLASS_TELSSHPUBLICKEYSERVER
	delete this->_Inst_Server;
	this->_Inst_Server = NULL;
#endif /* SB_USE_CLASS_TELSSHPUBLICKEYSERVER */
}
#endif /* SB_USE_CLASS_TELPUBLICKEYSSHSUBSYSTEMHANDLER */

};	/* namespace SecureBlackbox */

