#include "sbsftphandler.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSFTPSSHSUBSYSTEMHANDLER

TSBSSHSubsystemHandlerType TElSFTPSSHSubsystemHandler::HandlerType()
{
	TSBSSHSubsystemHandlerTypeRaw OutResultRaw = 0;
	SBCheckError(TElSFTPSSHSubsystemHandler_HandlerType(_Handle, &OutResultRaw));
	return (TSBSSHSubsystemHandlerType)OutResultRaw;
}

SB_INLINE TClassHandle TElSFTPSSHSubsystemHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElSFTPSSHSubsystemHandler_ClassType(&OutResult));
	return OutResult;
}

TSBSftpVersion TElSFTPSSHSubsystemHandler::get_Version()
{
	TSBSftpVersionRaw OutResultRaw = 0;
	SBCheckError(TElSFTPSSHSubsystemHandler_get_Version(_Handle, &OutResultRaw));
	return (TSBSftpVersion)OutResultRaw;
}

TSBSftpVersions TElSFTPSSHSubsystemHandler::get_Versions()
{
	TSBSftpVersionsRaw OutResultRaw = 0;
	SBCheckError(TElSFTPSSHSubsystemHandler_get_Versions(_Handle, &OutResultRaw));
	return (TSBSftpVersions)OutResultRaw;
}

SB_INLINE void TElSFTPSSHSubsystemHandler::set_Versions(TSBSftpVersions Value)
{
	SBCheckError(TElSFTPSSHSubsystemHandler_set_Versions(_Handle, (TSBSftpVersionsRaw)Value));
}

void TElSFTPSSHSubsystemHandler::get_NewLineConvention(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSFTPSSHSubsystemHandler_get_NewLineConvention(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(602595569, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSFTPSSHSubsystemHandler::set_NewLineConvention(const std::string &Value)
{
	SBCheckError(TElSFTPSSHSubsystemHandler_set_NewLineConvention(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELSFTPSERVER
TElSFTPServer* TElSFTPSSHSubsystemHandler::get_Server()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSFTPSSHSubsystemHandler_get_Server(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Server)
		this->_Inst_Server = new TElSFTPServer(hOutResult, ohFalse);
	else
		this->_Inst_Server->updateHandle(hOutResult);
	return this->_Inst_Server;
}

SB_INLINE void TElSFTPSSHSubsystemHandler::set_Server(TElSFTPServer &Value)
{
	SBCheckError(TElSFTPSSHSubsystemHandler_set_Server(_Handle, Value.getHandle()));
}

SB_INLINE void TElSFTPSSHSubsystemHandler::set_Server(TElSFTPServer *Value)
{
	SBCheckError(TElSFTPSSHSubsystemHandler_set_Server(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPSERVER */

void TElSFTPSSHSubsystemHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELSFTPSERVER
	this->_Inst_Server = NULL;
#endif /* SB_USE_CLASS_TELSFTPSERVER */
}

TElSFTPSSHSubsystemHandler::TElSFTPSSHSubsystemHandler(TElSFTPSSHSubsystemHandlerHandle handle, TElOwnHandle ownHandle) : TElCustomSSHSubsystemHandler(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElSFTPSSHSubsystemHandler::TElSFTPSSHSubsystemHandler(TElSSHTunnelConnection &Connection) : TElCustomSSHSubsystemHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSFTPSSHSubsystemHandler_Create(Connection.getHandle(), &_Handle));
}

TElSFTPSSHSubsystemHandler::TElSFTPSSHSubsystemHandler(TElSSHTunnelConnection *Connection) : TElCustomSSHSubsystemHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSFTPSSHSubsystemHandler_Create((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASSES_TELSFTPSERVER_AND_TELSSHTUNNELCONNECTION
TElSFTPSSHSubsystemHandler TElSFTPSSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection &Connection, TElSFTPServer &Server)
{
	TElSFTPSSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElSFTPSSHSubsystemHandler_CreateDelayed(Connection.getHandle(), Server.getHandle(), &_Handle));
	return TElSFTPSSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}

TElSFTPSSHSubsystemHandler TElSFTPSSHSubsystemHandler::CreateDelayed(TElSSHTunnelConnection *Connection, TElSFTPServer *Server)
{
	TElSFTPSSHSubsystemHandlerHandle _Handle;
	SBCheckError(TElSFTPSSHSubsystemHandler_CreateDelayed((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, (Server != NULL) ? Server->getHandle() : SB_NULL_HANDLE, &_Handle));
	return TElSFTPSSHSubsystemHandler(_Handle, SB_OWN_HANDLE);
}
#endif /* SB_USE_CLASSES_TELSFTPSERVER_AND_TELSSHTUNNELCONNECTION */

TElSFTPSSHSubsystemHandler::~TElSFTPSSHSubsystemHandler()
{
#ifdef SB_USE_CLASS_TELSFTPSERVER
	delete this->_Inst_Server;
	this->_Inst_Server = NULL;
#endif /* SB_USE_CLASS_TELSFTPSERVER */
}
#endif /* SB_USE_CLASS_TELSFTPSSHSUBSYSTEMHANDLER */

};	/* namespace SecureBlackbox */

