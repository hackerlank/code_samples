#include "sbdccms.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELDCCMSSIGNOPERATIONHANDLER

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElDCCMSSignOperationHandler::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDCCMSSignOperationHandler_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElDCCMSSignOperationHandler::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElDCCMSSignOperationHandler_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElDCCMSSignOperationHandler::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElDCCMSSignOperationHandler_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

SB_INLINE void TElDCCMSSignOperationHandler::get_OnTSPClientNeeded(TSBDCCMSTSPClientNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElDCCMSSignOperationHandler_get_OnTSPClientNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElDCCMSSignOperationHandler::set_OnTSPClientNeeded(TSBDCCMSTSPClientNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElDCCMSSignOperationHandler_set_OnTSPClientNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElDCCMSSignOperationHandler::get_OnCMSPrepared(TSBDCCMSPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElDCCMSSignOperationHandler_get_OnCMSPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElDCCMSSignOperationHandler::set_OnCMSPrepared(TSBDCCMSPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElDCCMSSignOperationHandler_set_OnCMSPrepared(_Handle, pMethodValue, pDataValue));
}

void TElDCCMSSignOperationHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElDCCMSSignOperationHandler::TElDCCMSSignOperationHandler(TElDCCMSSignOperationHandlerHandle handle, TElOwnHandle ownHandle) : TElDCSignOperationHandler(handle, ownHandle)
{
	initInstances();
}

TElDCCMSSignOperationHandler::TElDCCMSSignOperationHandler() : TElDCSignOperationHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDCCMSSignOperationHandler_Create(&_Handle));
}

TElDCCMSSignOperationHandler::~TElDCCMSSignOperationHandler()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELDCCMSSIGNOPERATIONHANDLER */

};	/* namespace SecureBlackbox */

