#include "sbsshconnectionhandler.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSSHCONNECTIONHANDLER

SB_INLINE void TElSSHConnectionHandler::Disconnect()
{
	SBCheckError(TElSSHConnectionHandler_Disconnect(_Handle));
}

SB_INLINE void TElSSHConnectionHandler::SendData(void * Buffer, int32_t Size)
{
	SBCheckError(TElSSHConnectionHandler_SendData(_Handle, Buffer, Size));
}

SB_INLINE void TElSSHConnectionHandler::SendExtendedData(void * Buffer, int32_t Size)
{
	SBCheckError(TElSSHConnectionHandler_SendExtendedData(_Handle, Buffer, Size));
}

SB_INLINE int32_t TElSSHConnectionHandler::ReceiveData(void * Buffer, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElSSHConnectionHandler_ReceiveData(_Handle, Buffer, Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHConnectionHandler::ReceiveLength()
{
	int32_t OutResult;
	SBCheckError(TElSSHConnectionHandler_ReceiveLength(_Handle, &OutResult));
	return OutResult;
}

bool TElSSHConnectionHandler::get_Connected()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHConnectionHandler_get_Connected(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElSSHTunnelConnection* TElSSHConnectionHandler::get_Connection()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHConnectionHandler_get_Connection(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Connection)
		this->_Inst_Connection = new TElSSHTunnelConnection(hOutResult, ohFalse);
	else
		this->_Inst_Connection->updateHandle(hOutResult);
	return this->_Inst_Connection;
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

SB_INLINE void TElSSHConnectionHandler::get_OnDisconnect(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSSHConnectionHandler_get_OnDisconnect(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSSHConnectionHandler::set_OnDisconnect(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSSHConnectionHandler_set_OnDisconnect(_Handle, pMethodValue, pDataValue));
}

void TElSSHConnectionHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
	this->_Inst_Connection = NULL;
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */
}

TElSSHConnectionHandler::TElSSHConnectionHandler(TElSSHConnectionHandlerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
TElSSHConnectionHandler::TElSSHConnectionHandler(TElSSHTunnelConnection &Connection) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHConnectionHandler_Create(Connection.getHandle(), &_Handle));
}

TElSSHConnectionHandler::TElSSHConnectionHandler(TElSSHTunnelConnection *Connection) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHConnectionHandler_Create((Connection != NULL) ? Connection->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

TElSSHConnectionHandler::~TElSSHConnectionHandler()
{
#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
	delete this->_Inst_Connection;
	this->_Inst_Connection = NULL;
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */
}
#endif /* SB_USE_CLASS_TELSSHCONNECTIONHANDLER */

};	/* namespace SecureBlackbox */

