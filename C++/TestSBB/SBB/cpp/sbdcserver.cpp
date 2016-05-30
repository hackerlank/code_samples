#include "sbdcserver.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELDCOPERATIONHANDLER

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElDCOperationHandler::get_AcceptedOperationIDs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDCOperationHandler_get_AcceptedOperationIDs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AcceptedOperationIDs)
		this->_Inst_AcceptedOperationIDs = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_AcceptedOperationIDs->updateHandle(hOutResult);
	return this->_Inst_AcceptedOperationIDs;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElDCOperationHandler::get_AcceptedOperationIDs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDCOperationHandler_get_AcceptedOperationIDs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AcceptedOperationIDs)
		this->_Inst_AcceptedOperationIDs = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_AcceptedOperationIDs->updateHandle(hOutResult);
	return this->_Inst_AcceptedOperationIDs;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElDCOperationHandler::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_AcceptedOperationIDs = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_AcceptedOperationIDs = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElDCOperationHandler::TElDCOperationHandler(TElDCOperationHandlerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElDCOperationHandler::TElDCOperationHandler() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDCOperationHandler_Create(&_Handle));
}

TElDCOperationHandler::~TElDCOperationHandler()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_AcceptedOperationIDs;
	this->_Inst_AcceptedOperationIDs = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_AcceptedOperationIDs;
	this->_Inst_AcceptedOperationIDs = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELDCOPERATIONHANDLER */

#ifdef SB_USE_CLASS_TELDCSIGNOPERATIONHANDLER

SB_INLINE void TElDCSignOperationHandler::get_OnSignRequest(TSBDCSignRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElDCSignOperationHandler_get_OnSignRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElDCSignOperationHandler::set_OnSignRequest(TSBDCSignRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElDCSignOperationHandler_set_OnSignRequest(_Handle, pMethodValue, pDataValue));
}

TElDCSignOperationHandler::TElDCSignOperationHandler(TElDCSignOperationHandlerHandle handle, TElOwnHandle ownHandle) : TElDCOperationHandler(handle, ownHandle)
{
}

TElDCSignOperationHandler::TElDCSignOperationHandler() : TElDCOperationHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDCSignOperationHandler_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDCSIGNOPERATIONHANDLER */

#ifdef SB_USE_CLASS_TELDCGENERICSIGNOPERATIONHANDLER

TElDCGenericSignOperationHandler::TElDCGenericSignOperationHandler(TElDCGenericSignOperationHandlerHandle handle, TElOwnHandle ownHandle) : TElDCSignOperationHandler(handle, ownHandle)
{
}

TElDCGenericSignOperationHandler::TElDCGenericSignOperationHandler() : TElDCSignOperationHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDCGenericSignOperationHandler_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDCGENERICSIGNOPERATIONHANDLER */

#ifdef SB_USE_CLASS_TELDCSTANDARDSERVER

#ifdef SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM
SB_INLINE void TElDCStandardServer::Process(TStream &InStream, TStream &OutStream, TElDCEncoding &InEncoding, TElDCEncoding &OutEncoding)
{
	SBCheckError(TElDCStandardServer_Process(_Handle, InStream.getHandle(), OutStream.getHandle(), InEncoding.getHandle(), OutEncoding.getHandle()));
}

SB_INLINE void TElDCStandardServer::Process(TStream *InStream, TStream *OutStream, TElDCEncoding *InEncoding, TElDCEncoding *OutEncoding)
{
	SBCheckError(TElDCStandardServer_Process(_Handle, (InStream != NULL) ? InStream->getHandle() : SB_NULL_HANDLE, (OutStream != NULL) ? OutStream->getHandle() : SB_NULL_HANDLE, (InEncoding != NULL) ? InEncoding->getHandle() : SB_NULL_HANDLE, (OutEncoding != NULL) ? OutEncoding->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELDCOPERATIONHANDLER
SB_INLINE int32_t TElDCStandardServer::AddOperationHandler(TElDCOperationHandler &Handler)
{
	int32_t OutResult;
	SBCheckError(TElDCStandardServer_AddOperationHandler(_Handle, Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDCStandardServer::AddOperationHandler(TElDCOperationHandler *Handler)
{
	int32_t OutResult;
	SBCheckError(TElDCStandardServer_AddOperationHandler(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDCOPERATIONHANDLER */

SB_INLINE void TElDCStandardServer::RemoveOperationHandler(int32_t Index)
{
	SBCheckError(TElDCStandardServer_RemoveOperationHandler(_Handle, Index));
}

SB_INLINE void TElDCStandardServer::ClearOperationHandlers()
{
	SBCheckError(TElDCStandardServer_ClearOperationHandlers(_Handle));
}

#ifdef SB_USE_CLASS_TELDCOPERATIONHANDLER
TElDCOperationHandler* TElDCStandardServer::get_OperationHandlers(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDCStandardServer_get_OperationHandlers(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OperationHandlers)
		this->_Inst_OperationHandlers = new TElDCOperationHandler(hOutResult, ohFalse);
	else
		this->_Inst_OperationHandlers->updateHandle(hOutResult);
	return this->_Inst_OperationHandlers;
}
#endif /* SB_USE_CLASS_TELDCOPERATIONHANDLER */

SB_INLINE int32_t TElDCStandardServer::get_OperationHandlerCount()
{
	int32_t OutResult;
	SBCheckError(TElDCStandardServer_get_OperationHandlerCount(_Handle, &OutResult));
	return OutResult;
}

void TElDCStandardServer::initInstances()
{
#ifdef SB_USE_CLASS_TELDCOPERATIONHANDLER
	this->_Inst_OperationHandlers = NULL;
#endif /* SB_USE_CLASS_TELDCOPERATIONHANDLER */
}

TElDCStandardServer::TElDCStandardServer(TElDCStandardServerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElDCStandardServer::TElDCStandardServer() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDCStandardServer_Create(&_Handle));
}

TElDCStandardServer::~TElDCStandardServer()
{
#ifdef SB_USE_CLASS_TELDCOPERATIONHANDLER
	delete this->_Inst_OperationHandlers;
	this->_Inst_OperationHandlers = NULL;
#endif /* SB_USE_CLASS_TELDCOPERATIONHANDLER */
}
#endif /* SB_USE_CLASS_TELDCSTANDARDSERVER */

};	/* namespace SecureBlackbox */
