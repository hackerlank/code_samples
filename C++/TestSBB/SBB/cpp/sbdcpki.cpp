#include "sbdcpki.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELDCX509SIGNOPERATIONHANDLER

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElDCX509SignOperationHandler::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDCX509SignOperationHandler_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElDCX509SignOperationHandler::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElDCX509SignOperationHandler_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElDCX509SignOperationHandler::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElDCX509SignOperationHandler_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

void TElDCX509SignOperationHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElDCX509SignOperationHandler::TElDCX509SignOperationHandler(TElDCX509SignOperationHandlerHandle handle, TElOwnHandle ownHandle) : TElDCSignOperationHandler(handle, ownHandle)
{
	initInstances();
}

TElDCX509SignOperationHandler::TElDCX509SignOperationHandler() : TElDCSignOperationHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDCX509SignOperationHandler_Create(&_Handle));
}

TElDCX509SignOperationHandler::~TElDCX509SignOperationHandler()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELDCX509SIGNOPERATIONHANDLER */

};	/* namespace SecureBlackbox */

