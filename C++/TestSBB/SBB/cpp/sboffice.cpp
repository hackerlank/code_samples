#include "sboffice.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLSIGNATUREVIEW

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER
TElOfficeOpenXMLCustomSignatureHandler* TElOfficeOpenXMLSignatureView::get_SignatureHandler()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLSignatureView_get_SignatureHandler(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureHandler)
		this->_Inst_SignatureHandler = new TElOfficeOpenXMLCustomSignatureHandler(hOutResult, ohFalse);
	else
		this->_Inst_SignatureHandler->updateHandle(hOutResult);
	return this->_Inst_SignatureHandler;
}

SB_INLINE void TElOfficeOpenXMLSignatureView::set_SignatureHandler(TElOfficeOpenXMLCustomSignatureHandler &Value)
{
	SBCheckError(TElOfficeOpenXMLSignatureView_set_SignatureHandler(_Handle, Value.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLSignatureView::set_SignatureHandler(TElOfficeOpenXMLCustomSignatureHandler *Value)
{
	SBCheckError(TElOfficeOpenXMLSignatureView_set_SignatureHandler(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE
TElOfficeOpenXMLPackage* TElOfficeOpenXMLSignatureView::get_Package()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLSignatureView_get_Package(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Package)
		this->_Inst_Package = new TElOfficeOpenXMLPackage(hOutResult, ohFalse);
	else
		this->_Inst_Package->updateHandle(hOutResult);
	return this->_Inst_Package;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE */

void TElOfficeOpenXMLSignatureView::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER
	this->_Inst_SignatureHandler = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE
	this->_Inst_Package = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE */
}

TElOfficeOpenXMLSignatureView::TElOfficeOpenXMLSignatureView(TElOfficeOpenXMLSignatureViewHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE
TElOfficeOpenXMLSignatureView::TElOfficeOpenXMLSignatureView(TElOfficeOpenXMLPackage &APackage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXMLSignatureView_Create(APackage.getHandle(), &_Handle));
}

TElOfficeOpenXMLSignatureView::TElOfficeOpenXMLSignatureView(TElOfficeOpenXMLPackage *APackage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXMLSignatureView_Create((APackage != NULL) ? APackage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE */

TElOfficeOpenXMLSignatureView::~TElOfficeOpenXMLSignatureView()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER
	delete this->_Inst_SignatureHandler;
	this->_Inst_SignatureHandler = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE
	delete this->_Inst_Package;
	this->_Inst_Package = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE */
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLSIGNATUREVIEW */

#ifdef SB_USE_CLASS_TELOFFICECUSTOMSECURITYHANDLER

void TElOfficeCustomSecurityHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeCustomSecurityHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-728522190, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOfficeCustomSecurityHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeCustomSecurityHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-728522190, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeCustomSecurityHandler::Reset()
{
	SBCheckError(TElOfficeCustomSecurityHandler_Reset(_Handle));
}

SB_INLINE TClassHandle TElOfficeCustomSecurityHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeCustomSecurityHandler_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElOfficeCustomSecurityHandler::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeCustomSecurityHandler_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElOfficeCustomSecurityHandler::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElOfficeCustomSecurityHandler_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElOfficeCustomSecurityHandler::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElOfficeCustomSecurityHandler_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

void TElOfficeCustomSecurityHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}

TElOfficeCustomSecurityHandler::TElOfficeCustomSecurityHandler(TElOfficeCustomSecurityHandlerHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElOfficeCustomSecurityHandler::TElOfficeCustomSecurityHandler(TComponent &Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeCustomSecurityHandler_Create(Owner.getHandle(), &_Handle));
}

TElOfficeCustomSecurityHandler::TElOfficeCustomSecurityHandler(TComponent *Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeCustomSecurityHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElOfficeCustomSecurityHandler::~TElOfficeCustomSecurityHandler()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}
#endif /* SB_USE_CLASS_TELOFFICECUSTOMSECURITYHANDLER */

#ifdef SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER

SB_INLINE TClassHandle TElOfficeCustomEncryptionHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeCustomEncryptionHandler_ClassType(&OutResult));
	return OutResult;
}

TElOfficeCustomEncryptionHandler::TElOfficeCustomEncryptionHandler(TElOfficeCustomEncryptionHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeCustomSecurityHandler(handle, ownHandle)
{
}

TElOfficeCustomEncryptionHandler::TElOfficeCustomEncryptionHandler(TComponent &Owner) : TElOfficeCustomSecurityHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeCustomEncryptionHandler_Create(Owner.getHandle(), &_Handle));
}

TElOfficeCustomEncryptionHandler::TElOfficeCustomEncryptionHandler(TComponent *Owner) : TElOfficeCustomSecurityHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeCustomEncryptionHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEBINARYCUSTOMENCRYPTIONHANDLER

SB_INLINE TClassHandle TElOfficeBinaryCustomEncryptionHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeBinaryCustomEncryptionHandler_ClassType(&OutResult));
	return OutResult;
}

TElOfficeBinaryCustomEncryptionHandler::TElOfficeBinaryCustomEncryptionHandler(TElOfficeBinaryCustomEncryptionHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeCustomEncryptionHandler(handle, ownHandle)
{
}

TElOfficeBinaryCustomEncryptionHandler::TElOfficeBinaryCustomEncryptionHandler(TComponent &Owner) : TElOfficeCustomEncryptionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeBinaryCustomEncryptionHandler_Create(Owner.getHandle(), &_Handle));
}

TElOfficeBinaryCustomEncryptionHandler::TElOfficeBinaryCustomEncryptionHandler(TComponent *Owner) : TElOfficeCustomEncryptionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeBinaryCustomEncryptionHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEBINARYCUSTOMENCRYPTIONHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMENCRYPTIONHANDLER

SB_INLINE TClassHandle TElOfficeOpenXMLCustomEncryptionHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeOpenXMLCustomEncryptionHandler_ClassType(&OutResult));
	return OutResult;
}

TElOfficeOpenXMLCustomEncryptionHandler::TElOfficeOpenXMLCustomEncryptionHandler(TElOfficeOpenXMLCustomEncryptionHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeCustomEncryptionHandler(handle, ownHandle)
{
}

TElOfficeOpenXMLCustomEncryptionHandler::TElOfficeOpenXMLCustomEncryptionHandler(TComponent &Owner) : TElOfficeCustomEncryptionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLCustomEncryptionHandler_Create(Owner.getHandle(), &_Handle));
}

TElOfficeOpenXMLCustomEncryptionHandler::TElOfficeOpenXMLCustomEncryptionHandler(TComponent *Owner) : TElOfficeCustomEncryptionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLCustomEncryptionHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMENCRYPTIONHANDLER */

#ifdef SB_USE_CLASS_TELOPENOFFICECUSTOMENCRYPTIONHANDLER

SB_INLINE TClassHandle TElOpenOfficeCustomEncryptionHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOpenOfficeCustomEncryptionHandler_ClassType(&OutResult));
	return OutResult;
}

TElOpenOfficeCustomEncryptionHandler::TElOpenOfficeCustomEncryptionHandler(TElOpenOfficeCustomEncryptionHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeCustomEncryptionHandler(handle, ownHandle)
{
}

TElOpenOfficeCustomEncryptionHandler::TElOpenOfficeCustomEncryptionHandler(TComponent &Owner) : TElOfficeCustomEncryptionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOpenOfficeCustomEncryptionHandler_Create(Owner.getHandle(), &_Handle));
}

TElOpenOfficeCustomEncryptionHandler::TElOpenOfficeCustomEncryptionHandler(TComponent *Owner) : TElOfficeCustomEncryptionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOpenOfficeCustomEncryptionHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELOPENOFFICECUSTOMENCRYPTIONHANDLER */

#ifdef SB_USE_CLASS_TELOFFICECUSTOMSIGNATUREHANDLER

SB_INLINE void TElOfficeCustomSignatureHandler::Reset()
{
	SBCheckError(TElOfficeCustomSignatureHandler_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
SB_INLINE void TElOfficeCustomSignatureHandler::CompleteAsyncSign(TElDCAsyncState &State)
{
	SBCheckError(TElOfficeCustomSignatureHandler_CompleteAsyncSign(_Handle, State.getHandle()));
}

SB_INLINE void TElOfficeCustomSignatureHandler::CompleteAsyncSign(TElDCAsyncState *State)
{
	SBCheckError(TElOfficeCustomSignatureHandler_CompleteAsyncSign(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

SB_INLINE TClassHandle TElOfficeCustomSignatureHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeCustomSignatureHandler_ClassType(&OutResult));
	return OutResult;
}

bool TElOfficeCustomSignatureHandler::get_IsCalculated()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeCustomSignatureHandler_get_IsCalculated(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElOfficeCustomSignatureHandler::TElOfficeCustomSignatureHandler(TElOfficeCustomSignatureHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeCustomSecurityHandler(handle, ownHandle)
{
}

TElOfficeCustomSignatureHandler::TElOfficeCustomSignatureHandler(TComponent &Owner) : TElOfficeCustomSecurityHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeCustomSignatureHandler_Create(Owner.getHandle(), &_Handle));
}

TElOfficeCustomSignatureHandler::TElOfficeCustomSignatureHandler(TComponent *Owner) : TElOfficeCustomSecurityHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeCustomSignatureHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICECUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEBINARYCUSTOMSIGNATUREHANDLER

SB_INLINE void TElOfficeBinaryCustomSignatureHandler::Reset()
{
	SBCheckError(TElOfficeBinaryCustomSignatureHandler_Reset(_Handle));
}

SB_INLINE TClassHandle TElOfficeBinaryCustomSignatureHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeBinaryCustomSignatureHandler_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE
TElCompoundFileStorage* TElOfficeBinaryCustomSignatureHandler::get_Storage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeBinaryCustomSignatureHandler_get_Storage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Storage)
		this->_Inst_Storage = new TElCompoundFileStorage(hOutResult, ohFalse);
	else
		this->_Inst_Storage->updateHandle(hOutResult);
	return this->_Inst_Storage;
}
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTREAMENTRY
TElCompoundFileStreamEntry* TElOfficeBinaryCustomSignatureHandler::get_SignatureStreamEntry()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeBinaryCustomSignatureHandler_get_SignatureStreamEntry(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureStreamEntry)
		this->_Inst_SignatureStreamEntry = new TElCompoundFileStreamEntry(hOutResult, ohFalse);
	else
		this->_Inst_SignatureStreamEntry->updateHandle(hOutResult);
	return this->_Inst_SignatureStreamEntry;
}
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTREAMENTRY */

void TElOfficeBinaryCustomSignatureHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE
	this->_Inst_Storage = NULL;
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */
#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTREAMENTRY
	this->_Inst_SignatureStreamEntry = NULL;
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTREAMENTRY */
}

TElOfficeBinaryCustomSignatureHandler::TElOfficeBinaryCustomSignatureHandler(TElOfficeBinaryCustomSignatureHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeCustomSignatureHandler(handle, ownHandle)
{
	initInstances();
}

TElOfficeBinaryCustomSignatureHandler::TElOfficeBinaryCustomSignatureHandler(TComponent &Owner) : TElOfficeCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeBinaryCustomSignatureHandler_Create(Owner.getHandle(), &_Handle));
}

TElOfficeBinaryCustomSignatureHandler::TElOfficeBinaryCustomSignatureHandler(TComponent *Owner) : TElOfficeCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeBinaryCustomSignatureHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElOfficeBinaryCustomSignatureHandler::~TElOfficeBinaryCustomSignatureHandler()
{
#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE
	delete this->_Inst_Storage;
	this->_Inst_Storage = NULL;
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */
#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTREAMENTRY
	delete this->_Inst_SignatureStreamEntry;
	this->_Inst_SignatureStreamEntry = NULL;
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTREAMENTRY */
}
#endif /* SB_USE_CLASS_TELOFFICEBINARYCUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEBINARYUNSUPPORTEDSIGNATUREHANDLER

void TElOfficeBinaryUnsupportedSignatureHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeBinaryUnsupportedSignatureHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(80769874, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOfficeBinaryUnsupportedSignatureHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeBinaryUnsupportedSignatureHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(80769874, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TElOfficeBinaryUnsupportedSignatureHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeBinaryUnsupportedSignatureHandler_ClassType(&OutResult));
	return OutResult;
}

TElOfficeBinaryUnsupportedSignatureHandler::TElOfficeBinaryUnsupportedSignatureHandler(TElOfficeBinaryUnsupportedSignatureHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryCustomSignatureHandler(handle, ownHandle)
{
}

TElOfficeBinaryUnsupportedSignatureHandler::TElOfficeBinaryUnsupportedSignatureHandler(TComponent &Owner) : TElOfficeBinaryCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeBinaryUnsupportedSignatureHandler_Create(Owner.getHandle(), &_Handle));
}

TElOfficeBinaryUnsupportedSignatureHandler::TElOfficeBinaryUnsupportedSignatureHandler(TComponent *Owner) : TElOfficeBinaryCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeBinaryUnsupportedSignatureHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEBINARYUNSUPPORTEDSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEBINARYINVALIDSIGNATUREHANDLER

SB_INLINE void TElOfficeBinaryInvalidSignatureHandler::Reset()
{
	SBCheckError(TElOfficeBinaryInvalidSignatureHandler_Reset(_Handle));
}

void TElOfficeBinaryInvalidSignatureHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeBinaryInvalidSignatureHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-347074153, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOfficeBinaryInvalidSignatureHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeBinaryInvalidSignatureHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-347074153, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TElOfficeBinaryInvalidSignatureHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeBinaryInvalidSignatureHandler_ClassType(&OutResult));
	return OutResult;
}

void TElOfficeBinaryInvalidSignatureHandler::get_ErrorMessage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeBinaryInvalidSignatureHandler_get_ErrorMessage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1572764755, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElOfficeBinaryInvalidSignatureHandler::TElOfficeBinaryInvalidSignatureHandler(TElOfficeBinaryInvalidSignatureHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryCustomSignatureHandler(handle, ownHandle)
{
}

TElOfficeBinaryInvalidSignatureHandler::TElOfficeBinaryInvalidSignatureHandler(TComponent &Owner) : TElOfficeBinaryCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeBinaryInvalidSignatureHandler_Create(Owner.getHandle(), &_Handle));
}

TElOfficeBinaryInvalidSignatureHandler::TElOfficeBinaryInvalidSignatureHandler(TComponent *Owner) : TElOfficeBinaryCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeBinaryInvalidSignatureHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEBINARYINVALIDSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER

SB_INLINE void TElOfficeOpenXMLCustomSignatureHandler::Reset()
{
	SBCheckError(TElOfficeOpenXMLCustomSignatureHandler_Reset(_Handle));
}

SB_INLINE TClassHandle TElOfficeOpenXMLCustomSignatureHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeOpenXMLCustomSignatureHandler_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICEPACKAGE
TElOfficePackage* TElOfficeOpenXMLCustomSignatureHandler::get_Package()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLCustomSignatureHandler_get_Package(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Package)
		this->_Inst_Package = new TElOfficePackage(hOutResult, ohFalse);
	else
		this->_Inst_Package->updateHandle(hOutResult);
	return this->_Inst_Package;
}
#endif /* SB_USE_CLASS_TELOFFICEPACKAGE */

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
TElOfficePackagePart* TElOfficeOpenXMLCustomSignatureHandler::get_SignaturePart()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLCustomSignatureHandler_get_SignaturePart(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignaturePart)
		this->_Inst_SignaturePart = new TElOfficePackagePart(hOutResult, ohFalse);
	else
		this->_Inst_SignaturePart->updateHandle(hOutResult);
	return this->_Inst_SignaturePart;
}
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

void TElOfficeOpenXMLCustomSignatureHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEPACKAGE
	this->_Inst_Package = NULL;
#endif /* SB_USE_CLASS_TELOFFICEPACKAGE */
#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
	this->_Inst_SignaturePart = NULL;
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */
}

TElOfficeOpenXMLCustomSignatureHandler::TElOfficeOpenXMLCustomSignatureHandler(TElOfficeOpenXMLCustomSignatureHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeCustomSignatureHandler(handle, ownHandle)
{
	initInstances();
}

TElOfficeOpenXMLCustomSignatureHandler::TElOfficeOpenXMLCustomSignatureHandler(TComponent &Owner) : TElOfficeCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXMLCustomSignatureHandler_Create(Owner.getHandle(), &_Handle));
}

TElOfficeOpenXMLCustomSignatureHandler::TElOfficeOpenXMLCustomSignatureHandler(TComponent *Owner) : TElOfficeCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXMLCustomSignatureHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElOfficeOpenXMLCustomSignatureHandler::~TElOfficeOpenXMLCustomSignatureHandler()
{
#ifdef SB_USE_CLASS_TELOFFICEPACKAGE
	delete this->_Inst_Package;
	this->_Inst_Package = NULL;
#endif /* SB_USE_CLASS_TELOFFICEPACKAGE */
#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
	delete this->_Inst_SignaturePart;
	this->_Inst_SignaturePart = NULL;
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLUNSUPPORTEDSIGNATUREHANDLER

void TElOfficeOpenXMLUnsupportedSignatureHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLUnsupportedSignatureHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-61776900, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOfficeOpenXMLUnsupportedSignatureHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLUnsupportedSignatureHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-61776900, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TElOfficeOpenXMLUnsupportedSignatureHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeOpenXMLUnsupportedSignatureHandler_ClassType(&OutResult));
	return OutResult;
}

TElOfficeOpenXMLUnsupportedSignatureHandler::TElOfficeOpenXMLUnsupportedSignatureHandler(TElOfficeOpenXMLUnsupportedSignatureHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLCustomSignatureHandler(handle, ownHandle)
{
}

TElOfficeOpenXMLUnsupportedSignatureHandler::TElOfficeOpenXMLUnsupportedSignatureHandler(TComponent &Owner) : TElOfficeOpenXMLCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLUnsupportedSignatureHandler_Create(Owner.getHandle(), &_Handle));
}

TElOfficeOpenXMLUnsupportedSignatureHandler::TElOfficeOpenXMLUnsupportedSignatureHandler(TComponent *Owner) : TElOfficeOpenXMLCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLUnsupportedSignatureHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEOPENXMLUNSUPPORTEDSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLINVALIDSIGNATUREHANDLER

SB_INLINE void TElOfficeOpenXMLInvalidSignatureHandler::Reset()
{
	SBCheckError(TElOfficeOpenXMLInvalidSignatureHandler_Reset(_Handle));
}

void TElOfficeOpenXMLInvalidSignatureHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLInvalidSignatureHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-152851199, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOfficeOpenXMLInvalidSignatureHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLInvalidSignatureHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-152851199, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TElOfficeOpenXMLInvalidSignatureHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeOpenXMLInvalidSignatureHandler_ClassType(&OutResult));
	return OutResult;
}

void TElOfficeOpenXMLInvalidSignatureHandler::get_ErrorMessage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLInvalidSignatureHandler_get_ErrorMessage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1903465388, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElOfficeOpenXMLInvalidSignatureHandler::TElOfficeOpenXMLInvalidSignatureHandler(TElOfficeOpenXMLInvalidSignatureHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLCustomSignatureHandler(handle, ownHandle)
{
}

TElOfficeOpenXMLInvalidSignatureHandler::TElOfficeOpenXMLInvalidSignatureHandler(TComponent &Owner) : TElOfficeOpenXMLCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLInvalidSignatureHandler_Create(Owner.getHandle(), &_Handle));
}

TElOfficeOpenXMLInvalidSignatureHandler::TElOfficeOpenXMLInvalidSignatureHandler(TComponent *Owner) : TElOfficeOpenXMLCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLInvalidSignatureHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEOPENXMLINVALIDSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOPENOFFICECUSTOMSIGNATUREHANDLER

SB_INLINE void TElOpenOfficeCustomSignatureHandler::Reset()
{
	SBCheckError(TElOpenOfficeCustomSignatureHandler_Reset(_Handle));
}

SB_INLINE TClassHandle TElOpenOfficeCustomSignatureHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOpenOfficeCustomSignatureHandler_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOPENOFFICEPACKAGE
TElOpenOfficePackage* TElOpenOfficeCustomSignatureHandler::get_Package()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOpenOfficeCustomSignatureHandler_get_Package(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Package)
		this->_Inst_Package = new TElOpenOfficePackage(hOutResult, ohFalse);
	else
		this->_Inst_Package->updateHandle(hOutResult);
	return this->_Inst_Package;
}
#endif /* SB_USE_CLASS_TELOPENOFFICEPACKAGE */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElement* TElOpenOfficeCustomSignatureHandler::get_XMLElement()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOpenOfficeCustomSignatureHandler_get_XMLElement(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_XMLElement)
		this->_Inst_XMLElement = new TElXMLDOMElement(hOutResult, ohFalse);
	else
		this->_Inst_XMLElement->updateHandle(hOutResult);
	return this->_Inst_XMLElement;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void TElOpenOfficeCustomSignatureHandler::get_SignaturePath(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficeCustomSignatureHandler_get_SignaturePath(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-82730236, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOpenOfficeCustomSignatureHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELOPENOFFICEPACKAGE
	this->_Inst_Package = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICEPACKAGE */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	this->_Inst_XMLElement = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
}

TElOpenOfficeCustomSignatureHandler::TElOpenOfficeCustomSignatureHandler(TElOpenOfficeCustomSignatureHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeCustomSignatureHandler(handle, ownHandle)
{
	initInstances();
}

TElOpenOfficeCustomSignatureHandler::TElOpenOfficeCustomSignatureHandler(TComponent &Owner) : TElOfficeCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOpenOfficeCustomSignatureHandler_Create(Owner.getHandle(), &_Handle));
}

TElOpenOfficeCustomSignatureHandler::TElOpenOfficeCustomSignatureHandler(TComponent *Owner) : TElOfficeCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOpenOfficeCustomSignatureHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElOpenOfficeCustomSignatureHandler::~TElOpenOfficeCustomSignatureHandler()
{
#ifdef SB_USE_CLASS_TELOPENOFFICEPACKAGE
	delete this->_Inst_Package;
	this->_Inst_Package = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICEPACKAGE */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	delete this->_Inst_XMLElement;
	this->_Inst_XMLElement = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
}
#endif /* SB_USE_CLASS_TELOPENOFFICECUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOPENOFFICEUNSUPPORTEDSIGNATUREHANDLER

void TElOpenOfficeUnsupportedSignatureHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficeUnsupportedSignatureHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2082098281, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOpenOfficeUnsupportedSignatureHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficeUnsupportedSignatureHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2082098281, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TElOpenOfficeUnsupportedSignatureHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOpenOfficeUnsupportedSignatureHandler_ClassType(&OutResult));
	return OutResult;
}

TElOpenOfficeUnsupportedSignatureHandler::TElOpenOfficeUnsupportedSignatureHandler(TElOpenOfficeUnsupportedSignatureHandlerHandle handle, TElOwnHandle ownHandle) : TElOpenOfficeCustomSignatureHandler(handle, ownHandle)
{
}

TElOpenOfficeUnsupportedSignatureHandler::TElOpenOfficeUnsupportedSignatureHandler(TComponent &Owner) : TElOpenOfficeCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOpenOfficeUnsupportedSignatureHandler_Create(Owner.getHandle(), &_Handle));
}

TElOpenOfficeUnsupportedSignatureHandler::TElOpenOfficeUnsupportedSignatureHandler(TComponent *Owner) : TElOpenOfficeCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOpenOfficeUnsupportedSignatureHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELOPENOFFICEUNSUPPORTEDSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOPENOFFICEINVALIDSIGNATUREHANDLER

SB_INLINE void TElOpenOfficeInvalidSignatureHandler::Reset()
{
	SBCheckError(TElOpenOfficeInvalidSignatureHandler_Reset(_Handle));
}

void TElOpenOfficeInvalidSignatureHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficeInvalidSignatureHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(958219278, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOpenOfficeInvalidSignatureHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficeInvalidSignatureHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(958219278, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TElOpenOfficeInvalidSignatureHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOpenOfficeInvalidSignatureHandler_ClassType(&OutResult));
	return OutResult;
}

void TElOpenOfficeInvalidSignatureHandler::get_ErrorMessage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficeInvalidSignatureHandler_get_ErrorMessage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-839361052, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElOpenOfficeInvalidSignatureHandler::TElOpenOfficeInvalidSignatureHandler(TElOpenOfficeInvalidSignatureHandlerHandle handle, TElOwnHandle ownHandle) : TElOpenOfficeCustomSignatureHandler(handle, ownHandle)
{
}

TElOpenOfficeInvalidSignatureHandler::TElOpenOfficeInvalidSignatureHandler(TComponent &Owner) : TElOpenOfficeCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOpenOfficeInvalidSignatureHandler_Create(Owner.getHandle(), &_Handle));
}

TElOpenOfficeInvalidSignatureHandler::TElOpenOfficeInvalidSignatureHandler(TComponent *Owner) : TElOpenOfficeCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOpenOfficeInvalidSignatureHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELOPENOFFICEINVALIDSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEBINARYDOCUMENT

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeBinaryDocument::Open(TStream &Stream)
{
	SBCheckError(TElOfficeBinaryDocument_Open(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeBinaryDocument::Open(TStream *Stream)
{
	SBCheckError(TElOfficeBinaryDocument_Open(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeBinaryDocument::Open(TStream &Stream, bool OwnStream)
{
	SBCheckError(TElOfficeBinaryDocument_Open_1(_Handle, Stream.getHandle(), (int8_t)OwnStream));
}

SB_INLINE void TElOfficeBinaryDocument::Open(TStream *Stream, bool OwnStream)
{
	SBCheckError(TElOfficeBinaryDocument_Open_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)OwnStream));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeBinaryDocument::Open(TStream &Stream, bool OwnStream, bool ReadOnly)
{
	SBCheckError(TElOfficeBinaryDocument_Open_2(_Handle, Stream.getHandle(), (int8_t)OwnStream, (int8_t)ReadOnly));
}

SB_INLINE void TElOfficeBinaryDocument::Open(TStream *Stream, bool OwnStream, bool ReadOnly)
{
	SBCheckError(TElOfficeBinaryDocument_Open_2(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)OwnStream, (int8_t)ReadOnly));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElOfficeBinaryDocument::Close()
{
	SBCheckError(TElOfficeBinaryDocument_Close(_Handle));
}

SB_INLINE void TElOfficeBinaryDocument::Flush()
{
	SBCheckError(TElOfficeBinaryDocument_Flush(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeBinaryDocument::DecryptTo(TStream &NewStream)
{
	SBCheckError(TElOfficeBinaryDocument_DecryptTo(_Handle, NewStream.getHandle()));
}

SB_INLINE void TElOfficeBinaryDocument::DecryptTo(TStream *NewStream)
{
	SBCheckError(TElOfficeBinaryDocument_DecryptTo(_Handle, (NewStream != NULL) ? NewStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeBinaryDocument::EncryptTo(TStream &NewStream)
{
	SBCheckError(TElOfficeBinaryDocument_EncryptTo(_Handle, NewStream.getHandle()));
}

SB_INLINE void TElOfficeBinaryDocument::EncryptTo(TStream *NewStream)
{
	SBCheckError(TElOfficeBinaryDocument_EncryptTo(_Handle, (NewStream != NULL) ? NewStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELOFFICEBINARYCUSTOMSIGNATUREHANDLER
SB_INLINE int32_t TElOfficeBinaryDocument::AddSignature(TElOfficeBinaryCustomSignatureHandler &Handler)
{
	int32_t OutResult;
	SBCheckError(TElOfficeBinaryDocument_AddSignature(_Handle, Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeBinaryDocument::AddSignature(TElOfficeBinaryCustomSignatureHandler *Handler)
{
	int32_t OutResult;
	SBCheckError(TElOfficeBinaryDocument_AddSignature(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEBINARYCUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEBINARYCUSTOMSIGNATUREHANDLER
SB_INLINE int32_t TElOfficeBinaryDocument::AddSignature(TElOfficeBinaryCustomSignatureHandler &Handler, bool OwnHandler)
{
	int32_t OutResult;
	SBCheckError(TElOfficeBinaryDocument_AddSignature_1(_Handle, Handler.getHandle(), (int8_t)OwnHandler, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeBinaryDocument::AddSignature(TElOfficeBinaryCustomSignatureHandler *Handler, bool OwnHandler)
{
	int32_t OutResult;
	SBCheckError(TElOfficeBinaryDocument_AddSignature_1(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, (int8_t)OwnHandler, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEBINARYCUSTOMSIGNATUREHANDLER */

SB_INLINE void TElOfficeBinaryDocument::RemoveSignature(int32_t Index)
{
	SBCheckError(TElOfficeBinaryDocument_RemoveSignature(_Handle, Index));
}

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELOFFICEBINARYCUSTOMSIGNATUREHANDLER
SB_INLINE void TElOfficeBinaryDocument::CompleteAsyncSign(TElOfficeBinaryCustomSignatureHandler &Handler, TElDCAsyncState &State)
{
	SBCheckError(TElOfficeBinaryDocument_CompleteAsyncSign(_Handle, Handler.getHandle(), State.getHandle()));
}

SB_INLINE void TElOfficeBinaryDocument::CompleteAsyncSign(TElOfficeBinaryCustomSignatureHandler *Handler, TElDCAsyncState *State)
{
	SBCheckError(TElOfficeBinaryDocument_CompleteAsyncSign(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELOFFICEBINARYCUSTOMSIGNATUREHANDLER */

bool TElOfficeBinaryDocument::get_Encryptable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeBinaryDocument_get_Encryptable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOfficeBinaryDocument::get_Signable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeBinaryDocument_get_Signable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOfficeBinaryDocument::get_IsEncrypted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeBinaryDocument_get_IsEncrypted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOfficeBinaryDocument::get_IsSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeBinaryDocument_get_IsSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TSBOfficeDocumentFormat TElOfficeBinaryDocument::get_DocumentFormat()
{
	TSBOfficeDocumentFormatRaw OutResultRaw = 0;
	SBCheckError(TElOfficeBinaryDocument_get_DocumentFormat(_Handle, &OutResultRaw));
	return (TSBOfficeDocumentFormat)OutResultRaw;
}

TSBOfficeBinaryDocumentType TElOfficeBinaryDocument::get_DocumentType()
{
	TSBOfficeBinaryDocumentTypeRaw OutResultRaw = 0;
	SBCheckError(TElOfficeBinaryDocument_get_DocumentType(_Handle, &OutResultRaw));
	return (TSBOfficeBinaryDocumentType)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER
TElOfficeCustomEncryptionHandler* TElOfficeBinaryDocument::get_EncryptionHandler()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeBinaryDocument_get_EncryptionHandler(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptionHandler)
		this->_Inst_EncryptionHandler = new TElOfficeCustomEncryptionHandler(hOutResult, ohFalse);
	else
		this->_Inst_EncryptionHandler->updateHandle(hOutResult);
	return this->_Inst_EncryptionHandler;
}

SB_INLINE void TElOfficeBinaryDocument::set_EncryptionHandler(TElOfficeCustomEncryptionHandler &Value)
{
	SBCheckError(TElOfficeBinaryDocument_set_EncryptionHandler(_Handle, Value.getHandle()));
}

SB_INLINE void TElOfficeBinaryDocument::set_EncryptionHandler(TElOfficeCustomEncryptionHandler *Value)
{
	SBCheckError(TElOfficeBinaryDocument_set_EncryptionHandler(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER */

bool TElOfficeBinaryDocument::get_OwnEncryptionHandler()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeBinaryDocument_get_OwnEncryptionHandler(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOfficeBinaryDocument::set_OwnEncryptionHandler(bool Value)
{
	SBCheckError(TElOfficeBinaryDocument_set_OwnEncryptionHandler(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElOfficeBinaryDocument::get_SignatureHandlerCount()
{
	int32_t OutResult;
	SBCheckError(TElOfficeBinaryDocument_get_SignatureHandlerCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICEBINARYCUSTOMSIGNATUREHANDLER
TElOfficeBinaryCustomSignatureHandler* TElOfficeBinaryDocument::get_SignatureHandlers(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeBinaryDocument_get_SignatureHandlers(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureHandlers)
		this->_Inst_SignatureHandlers = new TElOfficeBinaryCustomSignatureHandler(hOutResult, ohFalse);
	else
		this->_Inst_SignatureHandlers->updateHandle(hOutResult);
	return this->_Inst_SignatureHandlers;
}
#endif /* SB_USE_CLASS_TELOFFICEBINARYCUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE
TElCompoundFileStorage* TElOfficeBinaryDocument::get_Storage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeBinaryDocument_get_Storage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Storage)
		this->_Inst_Storage = new TElCompoundFileStorage(hOutResult, ohFalse);
	else
		this->_Inst_Storage->updateHandle(hOutResult);
	return this->_Inst_Storage;
}
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */

void TElOfficeBinaryDocument::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER
	this->_Inst_EncryptionHandler = NULL;
#endif /* SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER */
#ifdef SB_USE_CLASS_TELOFFICEBINARYCUSTOMSIGNATUREHANDLER
	this->_Inst_SignatureHandlers = NULL;
#endif /* SB_USE_CLASS_TELOFFICEBINARYCUSTOMSIGNATUREHANDLER */
#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE
	this->_Inst_Storage = NULL;
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */
}

TElOfficeBinaryDocument::TElOfficeBinaryDocument(TElOfficeBinaryDocumentHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElOfficeBinaryDocument::TElOfficeBinaryDocument() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeBinaryDocument_Create(&_Handle));
}

TElOfficeBinaryDocument::~TElOfficeBinaryDocument()
{
#ifdef SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER
	delete this->_Inst_EncryptionHandler;
	this->_Inst_EncryptionHandler = NULL;
#endif /* SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER */
#ifdef SB_USE_CLASS_TELOFFICEBINARYCUSTOMSIGNATUREHANDLER
	delete this->_Inst_SignatureHandlers;
	this->_Inst_SignatureHandlers = NULL;
#endif /* SB_USE_CLASS_TELOFFICEBINARYCUSTOMSIGNATUREHANDLER */
#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE
	delete this->_Inst_Storage;
	this->_Inst_Storage = NULL;
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */
}
#endif /* SB_USE_CLASS_TELOFFICEBINARYDOCUMENT */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE

#ifdef SB_USE_CLASS_TELOFFICEPACKAGE
SB_INLINE void TElOfficeOpenXMLPackage::Open(TElOfficePackage &APackage)
{
	SBCheckError(TElOfficeOpenXMLPackage_Open(_Handle, APackage.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLPackage::Open(TElOfficePackage *APackage)
{
	SBCheckError(TElOfficeOpenXMLPackage_Open(_Handle, (APackage != NULL) ? APackage->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICEPACKAGE */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeOpenXMLPackage::Open(TStream &Stream)
{
	SBCheckError(TElOfficeOpenXMLPackage_Open_1(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLPackage::Open(TStream *Stream)
{
	SBCheckError(TElOfficeOpenXMLPackage_Open_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeOpenXMLPackage::Open(TStream &Stream, bool OwnStream)
{
	SBCheckError(TElOfficeOpenXMLPackage_Open_2(_Handle, Stream.getHandle(), (int8_t)OwnStream));
}

SB_INLINE void TElOfficeOpenXMLPackage::Open(TStream *Stream, bool OwnStream)
{
	SBCheckError(TElOfficeOpenXMLPackage_Open_2(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)OwnStream));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeOpenXMLPackage::Open(TStream &Stream, bool OwnStream, bool ReadOnly)
{
	SBCheckError(TElOfficeOpenXMLPackage_Open_3(_Handle, Stream.getHandle(), (int8_t)OwnStream, (int8_t)ReadOnly));
}

SB_INLINE void TElOfficeOpenXMLPackage::Open(TStream *Stream, bool OwnStream, bool ReadOnly)
{
	SBCheckError(TElOfficeOpenXMLPackage_Open_3(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)OwnStream, (int8_t)ReadOnly));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElOfficeOpenXMLPackage::Close()
{
	SBCheckError(TElOfficeOpenXMLPackage_Close(_Handle));
}

SB_INLINE void TElOfficeOpenXMLPackage::Flush()
{
	SBCheckError(TElOfficeOpenXMLPackage_Flush(_Handle));
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER
SB_INLINE int32_t TElOfficeOpenXMLPackage::AddSignature(TElOfficeOpenXMLCustomSignatureHandler &Handler)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLPackage_AddSignature(_Handle, Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeOpenXMLPackage::AddSignature(TElOfficeOpenXMLCustomSignatureHandler *Handler)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLPackage_AddSignature(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER
SB_INLINE int32_t TElOfficeOpenXMLPackage::AddSignature(TElOfficeOpenXMLCustomSignatureHandler &Handler, bool OwnHandler)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLPackage_AddSignature_1(_Handle, Handler.getHandle(), (int8_t)OwnHandler, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeOpenXMLPackage::AddSignature(TElOfficeOpenXMLCustomSignatureHandler *Handler, bool OwnHandler)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLPackage_AddSignature_1(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, (int8_t)OwnHandler, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER */

SB_INLINE void TElOfficeOpenXMLPackage::RemoveSignature(int32_t Index)
{
	SBCheckError(TElOfficeOpenXMLPackage_RemoveSignature(_Handle, Index));
}

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER
SB_INLINE void TElOfficeOpenXMLPackage::CompleteAsyncSign(TElOfficeOpenXMLCustomSignatureHandler &Handler, TElDCAsyncState &State)
{
	SBCheckError(TElOfficeOpenXMLPackage_CompleteAsyncSign(_Handle, Handler.getHandle(), State.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLPackage::CompleteAsyncSign(TElOfficeOpenXMLCustomSignatureHandler *Handler, TElDCAsyncState *State)
{
	SBCheckError(TElOfficeOpenXMLPackage_CompleteAsyncSign(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER */

SB_INLINE int32_t TElOfficeOpenXMLPackage::get_SignatureHandlerCount()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLPackage_get_SignatureHandlerCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER
TElOfficeOpenXMLCustomSignatureHandler* TElOfficeOpenXMLPackage::get_SignatureHandlers(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLPackage_get_SignatureHandlers(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureHandlers)
		this->_Inst_SignatureHandlers = new TElOfficeOpenXMLCustomSignatureHandler(hOutResult, ohFalse);
	else
		this->_Inst_SignatureHandlers->updateHandle(hOutResult);
	return this->_Inst_SignatureHandlers;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER */

bool TElOfficeOpenXMLPackage::get_Encryptable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLPackage_get_Encryptable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOfficeOpenXMLPackage::get_Signable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLPackage_get_Signable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOfficeOpenXMLPackage::get_IsSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLPackage_get_IsSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELOFFICEPACKAGE
TElOfficePackage* TElOfficeOpenXMLPackage::get_Package()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLPackage_get_Package(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Package)
		this->_Inst_Package = new TElOfficePackage(hOutResult, ohFalse);
	else
		this->_Inst_Package->updateHandle(hOutResult);
	return this->_Inst_Package;
}
#endif /* SB_USE_CLASS_TELOFFICEPACKAGE */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES
TElOfficeOpenXMLCoreProperties* TElOfficeOpenXMLPackage::get_CoreProperties()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLPackage_get_CoreProperties(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CoreProperties)
		this->_Inst_CoreProperties = new TElOfficeOpenXMLCoreProperties(hOutResult, ohFalse);
	else
		this->_Inst_CoreProperties->updateHandle(hOutResult);
	return this->_Inst_CoreProperties;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES */

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
TElOfficePackagePart* TElOfficeOpenXMLPackage::get_ThumbnailPart()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLPackage_get_ThumbnailPart(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ThumbnailPart)
		this->_Inst_ThumbnailPart = new TElOfficePackagePart(hOutResult, ohFalse);
	else
		this->_Inst_ThumbnailPart->updateHandle(hOutResult);
	return this->_Inst_ThumbnailPart;
}
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

SB_INLINE void TElOfficeOpenXMLPackage::get_OnCreateTemporaryStream(TSBOfficeCreateTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOfficeOpenXMLPackage_get_OnCreateTemporaryStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOfficeOpenXMLPackage::set_OnCreateTemporaryStream(TSBOfficeCreateTemporaryStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOfficeOpenXMLPackage_set_OnCreateTemporaryStream(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElOfficeOpenXMLPackage::get_OnCloseTemporaryStream(TSBOfficeCloseTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOfficeOpenXMLPackage_get_OnCloseTemporaryStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOfficeOpenXMLPackage::set_OnCloseTemporaryStream(TSBOfficeCloseTemporaryStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOfficeOpenXMLPackage_set_OnCloseTemporaryStream(_Handle, pMethodValue, pDataValue));
}

void TElOfficeOpenXMLPackage::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER
	this->_Inst_SignatureHandlers = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER */
#ifdef SB_USE_CLASS_TELOFFICEPACKAGE
	this->_Inst_Package = NULL;
#endif /* SB_USE_CLASS_TELOFFICEPACKAGE */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES
	this->_Inst_CoreProperties = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES */
#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
	this->_Inst_ThumbnailPart = NULL;
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */
}

TElOfficeOpenXMLPackage::TElOfficeOpenXMLPackage(TElOfficeOpenXMLPackageHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElOfficeOpenXMLPackage::TElOfficeOpenXMLPackage() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXMLPackage_Create(&_Handle));
}

TElOfficeOpenXMLPackage::~TElOfficeOpenXMLPackage()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER
	delete this->_Inst_SignatureHandlers;
	this->_Inst_SignatureHandlers = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER */
#ifdef SB_USE_CLASS_TELOFFICEPACKAGE
	delete this->_Inst_Package;
	this->_Inst_Package = NULL;
#endif /* SB_USE_CLASS_TELOFFICEPACKAGE */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES
	delete this->_Inst_CoreProperties;
	this->_Inst_CoreProperties = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES */
#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
	delete this->_Inst_ThumbnailPart;
	this->_Inst_ThumbnailPart = NULL;
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLSIGNATURELINE

void TElOfficeOpenXMLSignatureLine::get_AdditionalSignatureInfo(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLSignatureLine_get_AdditionalSignatureInfo(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1498062659, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLSignatureLine::get_AdditionalSignatureInfo(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLSignatureLine_get_AdditionalSignatureInfo(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1498062659, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
bool TElOfficeOpenXMLSignatureLine::get_AllowComments()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLSignatureLine_get_AllowComments(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElOfficeOpenXMLSignatureLine::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLSignatureLine_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(808423391, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLSignatureLine::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLSignatureLine_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(808423391, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElOfficeOpenXMLSignatureLine::get_ImageData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeOpenXMLSignatureLine_get_ImageData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1568018585, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOfficeOpenXMLSignatureLine::get_SignatureProviderId(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLSignatureLine_get_SignatureProviderId(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-853137454, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLSignatureLine::get_SignatureProviderId(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLSignatureLine_get_SignatureProviderId(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-853137454, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElOfficeOpenXMLSignatureLine::get_SignatureProviderUrl(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLSignatureLine_get_SignatureProviderUrl(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(632313711, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLSignatureLine::get_SignatureProviderUrl(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLSignatureLine_get_SignatureProviderUrl(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(632313711, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
bool TElOfficeOpenXMLSignatureLine::get_ShowSignDate()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLSignatureLine_get_ShowSignDate(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElOfficeOpenXMLSignatureLine::get_SigningInstructions(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLSignatureLine_get_SigningInstructions(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-477562722, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLSignatureLine::get_SigningInstructions(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLSignatureLine_get_SigningInstructions(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-477562722, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElOfficeOpenXMLSignatureLine::get_SuggestedSigner(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLSignatureLine_get_SuggestedSigner(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-236238361, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLSignatureLine::get_SuggestedSigner(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLSignatureLine_get_SuggestedSigner(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-236238361, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElOfficeOpenXMLSignatureLine::get_SuggestedSigner2(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLSignatureLine_get_SuggestedSigner2(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-163001070, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLSignatureLine::get_SuggestedSigner2(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLSignatureLine_get_SuggestedSigner2(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-163001070, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElOfficeOpenXMLSignatureLine::get_SuggestedSignerEmail(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLSignatureLine_get_SuggestedSignerEmail(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(881412008, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLSignatureLine::get_SuggestedSignerEmail(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLSignatureLine_get_SuggestedSignerEmail(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(881412008, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
TElOfficeOpenXMLSignatureLine::TElOfficeOpenXMLSignatureLine(TElOfficeOpenXMLSignatureLineHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLSignatureView(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE
TElOfficeOpenXMLSignatureLine::TElOfficeOpenXMLSignatureLine(TElOfficeOpenXMLPackage &APackage) : TElOfficeOpenXMLSignatureView(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLSignatureLine_Create(APackage.getHandle(), &_Handle));
}

TElOfficeOpenXMLSignatureLine::TElOfficeOpenXMLSignatureLine(TElOfficeOpenXMLPackage *APackage) : TElOfficeOpenXMLSignatureView(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLSignatureLine_Create((APackage != NULL) ? APackage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE */

#endif /* SB_USE_CLASS_TELOFFICEOPENXMLSIGNATURELINE */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDOCUMENT

SB_INLINE void TElOfficeOpenXMLDocument::Close()
{
	SBCheckError(TElOfficeOpenXMLDocument_Close(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeOpenXMLDocument::EncryptTo(TStream &NewStream)
{
	SBCheckError(TElOfficeOpenXMLDocument_EncryptTo(_Handle, NewStream.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLDocument::EncryptTo(TStream *NewStream)
{
	SBCheckError(TElOfficeOpenXMLDocument_EncryptTo(_Handle, (NewStream != NULL) ? NewStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

TSBOfficeOpenXMLDocumentType TElOfficeOpenXMLDocument::get_DocumentType()
{
	TSBOfficeOpenXMLDocumentTypeRaw OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLDocument_get_DocumentType(_Handle, &OutResultRaw));
	return (TSBOfficeOpenXMLDocumentType)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
TElOfficePackagePart* TElOfficeOpenXMLDocument::get_OfficeDocumentPart()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLDocument_get_OfficeDocumentPart(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OfficeDocumentPart)
		this->_Inst_OfficeDocumentPart = new TElOfficePackagePart(hOutResult, ohFalse);
	else
		this->_Inst_OfficeDocumentPart->updateHandle(hOutResult);
	return this->_Inst_OfficeDocumentPart;
}
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

#ifdef SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER
TElOfficeCustomEncryptionHandler* TElOfficeOpenXMLDocument::get_EncryptionHandler()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLDocument_get_EncryptionHandler(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptionHandler)
		this->_Inst_EncryptionHandler = new TElOfficeCustomEncryptionHandler(hOutResult, ohFalse);
	else
		this->_Inst_EncryptionHandler->updateHandle(hOutResult);
	return this->_Inst_EncryptionHandler;
}

SB_INLINE void TElOfficeOpenXMLDocument::set_EncryptionHandler(TElOfficeCustomEncryptionHandler &Value)
{
	SBCheckError(TElOfficeOpenXMLDocument_set_EncryptionHandler(_Handle, Value.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLDocument::set_EncryptionHandler(TElOfficeCustomEncryptionHandler *Value)
{
	SBCheckError(TElOfficeOpenXMLDocument_set_EncryptionHandler(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER */

bool TElOfficeOpenXMLDocument::get_OwnEncryptionHandler()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLDocument_get_OwnEncryptionHandler(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOfficeOpenXMLDocument::set_OwnEncryptionHandler(bool Value)
{
	SBCheckError(TElOfficeOpenXMLDocument_set_OwnEncryptionHandler(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElOfficeOpenXMLDocument::get_SignatureLineCount()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLDocument_get_SignatureLineCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLSIGNATURELINE
TElOfficeOpenXMLSignatureLine* TElOfficeOpenXMLDocument::get_SignatureLines(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLDocument_get_SignatureLines(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureLines)
		this->_Inst_SignatureLines = new TElOfficeOpenXMLSignatureLine(hOutResult, ohFalse);
	else
		this->_Inst_SignatureLines->updateHandle(hOutResult);
	return this->_Inst_SignatureLines;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLSIGNATURELINE */

void TElOfficeOpenXMLDocument::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
	this->_Inst_OfficeDocumentPart = NULL;
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */
#ifdef SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER
	this->_Inst_EncryptionHandler = NULL;
#endif /* SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLSIGNATURELINE
	this->_Inst_SignatureLines = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLSIGNATURELINE */
}

TElOfficeOpenXMLDocument::TElOfficeOpenXMLDocument(TElOfficeOpenXMLDocumentHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLPackage(handle, ownHandle)
{
	initInstances();
}

TElOfficeOpenXMLDocument::TElOfficeOpenXMLDocument() : TElOfficeOpenXMLPackage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXMLDocument_Create(&_Handle));
}

TElOfficeOpenXMLDocument::~TElOfficeOpenXMLDocument()
{
#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
	delete this->_Inst_OfficeDocumentPart;
	this->_Inst_OfficeDocumentPart = NULL;
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */
#ifdef SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER
	delete this->_Inst_EncryptionHandler;
	this->_Inst_EncryptionHandler = NULL;
#endif /* SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLSIGNATURELINE
	delete this->_Inst_SignatureLines;
	this->_Inst_SignatureLines = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLSIGNATURELINE */
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDOCUMENT */

#ifdef SB_USE_CLASS_TELOFFICEOPENXPSSIGNATUREDEFINITION

void TElOfficeOpenXPSSignatureDefinition::get_Intent(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXPSSignatureDefinition_get_Intent(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-348093941, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXPSSignatureDefinition::get_Intent(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXPSSignatureDefinition_get_Intent(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-348093941, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeOpenXPSSignatureDefinition::set_Intent(const sb_u16string &Value)
{
	SBCheckError(TElOfficeOpenXPSSignatureDefinition_set_Intent(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeOpenXPSSignatureDefinition::set_Intent(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeOpenXPSSignatureDefinition_set_Intent(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeOpenXPSSignatureDefinition::get_PageURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXPSSignatureDefinition_get_PageURI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1468624881, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXPSSignatureDefinition::get_PageURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXPSSignatureDefinition_get_PageURI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1468624881, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeOpenXPSSignatureDefinition::set_PageURI(const sb_u16string &Value)
{
	SBCheckError(TElOfficeOpenXPSSignatureDefinition_set_PageURI(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeOpenXPSSignatureDefinition::set_PageURI(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeOpenXPSSignatureDefinition_set_PageURI(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeOpenXPSSignatureDefinition::get_SignBy(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXPSSignatureDefinition_get_SignBy(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-229343387, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXPSSignatureDefinition::get_SignBy(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXPSSignatureDefinition_get_SignBy(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-229343387, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE int64_t TElOfficeOpenXPSSignatureDefinition::get_SignByUTC()
{
	int64_t OutResult;
	SBCheckError(TElOfficeOpenXPSSignatureDefinition_get_SignByUTC(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeOpenXPSSignatureDefinition::set_SignByUTC(int64_t Value)
{
	SBCheckError(TElOfficeOpenXPSSignatureDefinition_set_SignByUTC(_Handle, Value));
}

void TElOfficeOpenXPSSignatureDefinition::get_SigningLocation(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXPSSignatureDefinition_get_SigningLocation(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1984133370, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXPSSignatureDefinition::get_SigningLocation(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXPSSignatureDefinition_get_SigningLocation(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1984133370, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeOpenXPSSignatureDefinition::set_SigningLocation(const sb_u16string &Value)
{
	SBCheckError(TElOfficeOpenXPSSignatureDefinition_set_SigningLocation(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeOpenXPSSignatureDefinition::set_SigningLocation(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeOpenXPSSignatureDefinition_set_SigningLocation(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeOpenXPSSignatureDefinition::get_SignerName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXPSSignatureDefinition_get_SignerName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1813850503, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXPSSignatureDefinition::get_SignerName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXPSSignatureDefinition_get_SignerName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1813850503, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeOpenXPSSignatureDefinition::set_SignerName(const sb_u16string &Value)
{
	SBCheckError(TElOfficeOpenXPSSignatureDefinition_set_SignerName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeOpenXPSSignatureDefinition::set_SignerName(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeOpenXPSSignatureDefinition_set_SignerName(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElOfficeOpenXPSSignatureDefinition::get_SpotID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXPSSignatureDefinition_get_SpotID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-264433403, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXPSSignatureDefinition::get_SpotID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXPSSignatureDefinition_get_SpotID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-264433403, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeOpenXPSSignatureDefinition::set_SpotID(const sb_u16string &Value)
{
	SBCheckError(TElOfficeOpenXPSSignatureDefinition_set_SpotID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeOpenXPSSignatureDefinition::set_SpotID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeOpenXPSSignatureDefinition_set_SpotID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeOpenXPSSignatureDefinition::get_SpotIDGUID(TGuid &OutResult)
{
	SBCheckError(TElOfficeOpenXPSSignatureDefinition_get_SpotIDGUID(_Handle, &OutResult));
}

SB_INLINE void TElOfficeOpenXPSSignatureDefinition::set_SpotIDGUID(TGuid &Value)
{
	SBCheckError(TElOfficeOpenXPSSignatureDefinition_set_SpotIDGUID(_Handle, &Value));
}

SB_INLINE double TElOfficeOpenXPSSignatureDefinition::get_StartX()
{
	double OutResult;
	SBCheckError(TElOfficeOpenXPSSignatureDefinition_get_StartX(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeOpenXPSSignatureDefinition::set_StartX(double Value)
{
	SBCheckError(TElOfficeOpenXPSSignatureDefinition_set_StartX(_Handle, Value));
}

SB_INLINE double TElOfficeOpenXPSSignatureDefinition::get_StartY()
{
	double OutResult;
	SBCheckError(TElOfficeOpenXPSSignatureDefinition_get_StartY(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeOpenXPSSignatureDefinition::set_StartY(double Value)
{
	SBCheckError(TElOfficeOpenXPSSignatureDefinition_set_StartY(_Handle, Value));
}

TElOfficeOpenXPSSignatureDefinition::TElOfficeOpenXPSSignatureDefinition(TElOfficeOpenXPSSignatureDefinitionHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLSignatureView(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE
TElOfficeOpenXPSSignatureDefinition::TElOfficeOpenXPSSignatureDefinition(TElOfficeOpenXMLPackage &APackage) : TElOfficeOpenXMLSignatureView(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXPSSignatureDefinition_Create(APackage.getHandle(), &_Handle));
}

TElOfficeOpenXPSSignatureDefinition::TElOfficeOpenXPSSignatureDefinition(TElOfficeOpenXMLPackage *APackage) : TElOfficeOpenXMLSignatureView(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXPSSignatureDefinition_Create((APackage != NULL) ? APackage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE */

#endif /* SB_USE_CLASS_TELOFFICEOPENXPSSIGNATUREDEFINITION */

#ifdef SB_USE_CLASS_TELOFFICEOPENXPSPAGECONTENT

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE
TElOfficeOpenXMLPackage* TElOfficeOpenXPSPageContent::get_Package()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXPSPageContent_get_Package(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Package)
		this->_Inst_Package = new TElOfficeOpenXMLPackage(hOutResult, ohFalse);
	else
		this->_Inst_Package->updateHandle(hOutResult);
	return this->_Inst_Package;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE */

void TElOfficeOpenXPSPageContent::get_Source(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXPSPageContent_get_Source(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-118405474, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElOfficeOpenXPSPageContent::get_Width()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXPSPageContent_get_Width(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeOpenXPSPageContent::get_Height()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXPSPageContent_get_Height(_Handle, &OutResult));
	return OutResult;
}

void TElOfficeOpenXPSPageContent::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE
	this->_Inst_Package = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE */
}

TElOfficeOpenXPSPageContent::TElOfficeOpenXPSPageContent(TElOfficeOpenXPSPageContentHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE
TElOfficeOpenXPSPageContent::TElOfficeOpenXPSPageContent(TElOfficeOpenXMLPackage &APackage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXPSPageContent_Create(APackage.getHandle(), &_Handle));
}

TElOfficeOpenXPSPageContent::TElOfficeOpenXPSPageContent(TElOfficeOpenXMLPackage *APackage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXPSPageContent_Create((APackage != NULL) ? APackage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE */

TElOfficeOpenXPSPageContent::~TElOfficeOpenXPSPageContent()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE
	delete this->_Inst_Package;
	this->_Inst_Package = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE */
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXPSPAGECONTENT */

#ifdef SB_USE_CLASS_TELOFFICEOPENXPSFIXEDDOCUMENT

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE
TElOfficeOpenXMLPackage* TElOfficeOpenXPSFixedDocument::get_Package()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXPSFixedDocument_get_Package(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Package)
		this->_Inst_Package = new TElOfficeOpenXMLPackage(hOutResult, ohFalse);
	else
		this->_Inst_Package->updateHandle(hOutResult);
	return this->_Inst_Package;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE */

void TElOfficeOpenXPSFixedDocument::get_URI(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXPSFixedDocument_get_URI(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-806878490, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElOfficeOpenXPSFixedDocument::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXPSFixedDocument_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXPSPAGECONTENT
TElOfficeOpenXPSPageContent* TElOfficeOpenXPSFixedDocument::get_PageContents(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXPSFixedDocument_get_PageContents(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PageContents)
		this->_Inst_PageContents = new TElOfficeOpenXPSPageContent(hOutResult, ohFalse);
	else
		this->_Inst_PageContents->updateHandle(hOutResult);
	return this->_Inst_PageContents;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXPSPAGECONTENT */

void TElOfficeOpenXPSFixedDocument::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE
	this->_Inst_Package = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE */
#ifdef SB_USE_CLASS_TELOFFICEOPENXPSPAGECONTENT
	this->_Inst_PageContents = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXPSPAGECONTENT */
}

TElOfficeOpenXPSFixedDocument::TElOfficeOpenXPSFixedDocument(TElOfficeOpenXPSFixedDocumentHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE
TElOfficeOpenXPSFixedDocument::TElOfficeOpenXPSFixedDocument(TElOfficeOpenXMLPackage &APackage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXPSFixedDocument_Create(APackage.getHandle(), &_Handle));
}

TElOfficeOpenXPSFixedDocument::TElOfficeOpenXPSFixedDocument(TElOfficeOpenXMLPackage *APackage) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXPSFixedDocument_Create((APackage != NULL) ? APackage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE */

TElOfficeOpenXPSFixedDocument::~TElOfficeOpenXPSFixedDocument()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE
	delete this->_Inst_Package;
	this->_Inst_Package = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLPACKAGE */
#ifdef SB_USE_CLASS_TELOFFICEOPENXPSPAGECONTENT
	delete this->_Inst_PageContents;
	this->_Inst_PageContents = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXPSPAGECONTENT */
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXPSFIXEDDOCUMENT */

#ifdef SB_USE_CLASS_TELOFFICEOPENXPSDOCUMENT

SB_INLINE int32_t TElOfficeOpenXPSDocument::AddSignatureDefinition(const sb_u16string &Intent, const sb_u16string &SignerName, const sb_u16string &SignerLocation, int64_t SignBy)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXPSDocument_AddSignatureDefinition(_Handle, Intent.data(), (int32_t)Intent.length(), SignerName.data(), (int32_t)SignerName.length(), SignerLocation.data(), (int32_t)SignerLocation.length(), SignBy, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElOfficeOpenXPSDocument::AddSignatureDefinition(const std::wstring &Intent, const std::wstring &SignerName, const std::wstring &SignerLocation, int64_t SignBy)
{
	int32_t OutResult;
	std::string u16Intent;
	sb_to_u16string(Intent, u16Intent);
	std::string u16SignerName;
	sb_to_u16string(SignerName, u16SignerName);
	std::string u16SignerLocation;
	sb_to_u16string(SignerLocation, u16SignerLocation);
	SBCheckError(TElOfficeOpenXPSDocument_AddSignatureDefinition(_Handle, reinterpret_cast<const sb_char16_t*>(u16Intent.data()), (int32_t)u16Intent.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16SignerName.data()), (int32_t)u16SignerName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16SignerLocation.data()), (int32_t)u16SignerLocation.length() >> 1, SignBy, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElOfficeOpenXPSDocument::AddSignatureDefinition(const sb_u16string &Intent, const sb_u16string &SignerName, const sb_u16string &SignerLocation, int64_t SignBy, const std::string &PageURI, double StartX, double StartY)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXPSDocument_AddSignatureDefinition_1(_Handle, Intent.data(), (int32_t)Intent.length(), SignerName.data(), (int32_t)SignerName.length(), SignerLocation.data(), (int32_t)SignerLocation.length(), SignBy, PageURI.data(), (int32_t)PageURI.length(), StartX, StartY, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElOfficeOpenXPSDocument::AddSignatureDefinition(const std::wstring &Intent, const std::wstring &SignerName, const std::wstring &SignerLocation, int64_t SignBy, const std::string &PageURI, double StartX, double StartY)
{
	int32_t OutResult;
	std::string u16Intent;
	sb_to_u16string(Intent, u16Intent);
	std::string u16SignerName;
	sb_to_u16string(SignerName, u16SignerName);
	std::string u16SignerLocation;
	sb_to_u16string(SignerLocation, u16SignerLocation);
	SBCheckError(TElOfficeOpenXPSDocument_AddSignatureDefinition_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16Intent.data()), (int32_t)u16Intent.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16SignerName.data()), (int32_t)u16SignerName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16SignerLocation.data()), (int32_t)u16SignerLocation.length() >> 1, SignBy, PageURI.data(), (int32_t)PageURI.length(), StartX, StartY, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELOFFICEOPENXPSSIGNATUREDEFINITION
SB_INLINE int32_t TElOfficeOpenXPSDocument::AddSignatureDefinition(TElOfficeOpenXPSSignatureDefinition &SigDef)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXPSDocument_AddSignatureDefinition_2(_Handle, SigDef.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeOpenXPSDocument::AddSignatureDefinition(TElOfficeOpenXPSSignatureDefinition *SigDef)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXPSDocument_AddSignatureDefinition_2(_Handle, (SigDef != NULL) ? SigDef->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXPSSIGNATUREDEFINITION */

SB_INLINE void TElOfficeOpenXPSDocument::Close()
{
	SBCheckError(TElOfficeOpenXPSDocument_Close(_Handle));
}

SB_INLINE int32_t TElOfficeOpenXPSDocument::get_FixedDocumentCount()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXPSDocument_get_FixedDocumentCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeOpenXPSDocument::get_SignatureDefinitionCount()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXPSDocument_get_SignatureDefinitionCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXPSFIXEDDOCUMENT
TElOfficeOpenXPSFixedDocument* TElOfficeOpenXPSDocument::get_FixedDocuments(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXPSDocument_get_FixedDocuments(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FixedDocuments)
		this->_Inst_FixedDocuments = new TElOfficeOpenXPSFixedDocument(hOutResult, ohFalse);
	else
		this->_Inst_FixedDocuments->updateHandle(hOutResult);
	return this->_Inst_FixedDocuments;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXPSFIXEDDOCUMENT */

#ifdef SB_USE_CLASS_TELOFFICEOPENXPSSIGNATUREDEFINITION
TElOfficeOpenXPSSignatureDefinition* TElOfficeOpenXPSDocument::get_SignatureDefinitions(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXPSDocument_get_SignatureDefinitions(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureDefinitions)
		this->_Inst_SignatureDefinitions = new TElOfficeOpenXPSSignatureDefinition(hOutResult, ohFalse);
	else
		this->_Inst_SignatureDefinitions->updateHandle(hOutResult);
	return this->_Inst_SignatureDefinitions;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXPSSIGNATUREDEFINITION */

void TElOfficeOpenXPSDocument::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXPSFIXEDDOCUMENT
	this->_Inst_FixedDocuments = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXPSFIXEDDOCUMENT */
#ifdef SB_USE_CLASS_TELOFFICEOPENXPSSIGNATUREDEFINITION
	this->_Inst_SignatureDefinitions = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXPSSIGNATUREDEFINITION */
}

TElOfficeOpenXPSDocument::TElOfficeOpenXPSDocument(TElOfficeOpenXPSDocumentHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLPackage(handle, ownHandle)
{
	initInstances();
}

TElOfficeOpenXPSDocument::TElOfficeOpenXPSDocument() : TElOfficeOpenXMLPackage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXPSDocument_Create(&_Handle));
}

TElOfficeOpenXPSDocument::~TElOfficeOpenXPSDocument()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXPSFIXEDDOCUMENT
	delete this->_Inst_FixedDocuments;
	this->_Inst_FixedDocuments = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXPSFIXEDDOCUMENT */
#ifdef SB_USE_CLASS_TELOFFICEOPENXPSSIGNATUREDEFINITION
	delete this->_Inst_SignatureDefinitions;
	this->_Inst_SignatureDefinitions = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXPSSIGNATUREDEFINITION */
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXPSDOCUMENT */

#ifdef SB_USE_CLASS_TELOPENOFFICEDOCUMENT

#ifdef SB_USE_CLASS_TELOPENOFFICEPACKAGE
SB_INLINE void TElOpenOfficeDocument::Open(TElOpenOfficePackage &APackage)
{
	SBCheckError(TElOpenOfficeDocument_Open(_Handle, APackage.getHandle()));
}

SB_INLINE void TElOpenOfficeDocument::Open(TElOpenOfficePackage *APackage)
{
	SBCheckError(TElOpenOfficeDocument_Open(_Handle, (APackage != NULL) ? APackage->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOPENOFFICEPACKAGE */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOpenOfficeDocument::Open(TStream &Stream)
{
	SBCheckError(TElOpenOfficeDocument_Open_1(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOpenOfficeDocument::Open(TStream *Stream)
{
	SBCheckError(TElOpenOfficeDocument_Open_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOpenOfficeDocument::Open(TStream &Stream, bool OwnStream)
{
	SBCheckError(TElOpenOfficeDocument_Open_2(_Handle, Stream.getHandle(), (int8_t)OwnStream));
}

SB_INLINE void TElOpenOfficeDocument::Open(TStream *Stream, bool OwnStream)
{
	SBCheckError(TElOpenOfficeDocument_Open_2(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)OwnStream));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOpenOfficeDocument::Open(TStream &Stream, bool OwnStream, bool ReadOnly)
{
	SBCheckError(TElOpenOfficeDocument_Open_3(_Handle, Stream.getHandle(), (int8_t)OwnStream, (int8_t)ReadOnly));
}

SB_INLINE void TElOpenOfficeDocument::Open(TStream *Stream, bool OwnStream, bool ReadOnly)
{
	SBCheckError(TElOpenOfficeDocument_Open_3(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)OwnStream, (int8_t)ReadOnly));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELZIPREADER_AND_TSTREAM
SB_INLINE void TElOpenOfficeDocument::Open(TStream &Stream, int64_t StreamOffset, bool OwnStream, bool ReadOnly, TElZipReader &ZipReader)
{
	SBCheckError(TElOpenOfficeDocument_Open_4(_Handle, Stream.getHandle(), StreamOffset, (int8_t)OwnStream, (int8_t)ReadOnly, ZipReader.getHandle()));
}

SB_INLINE void TElOpenOfficeDocument::Open(TStream *Stream, int64_t StreamOffset, bool OwnStream, bool ReadOnly, TElZipReader *ZipReader)
{
	SBCheckError(TElOpenOfficeDocument_Open_4(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, StreamOffset, (int8_t)OwnStream, (int8_t)ReadOnly, (ZipReader != NULL) ? ZipReader->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELZIPREADER_AND_TSTREAM */

SB_INLINE void TElOpenOfficeDocument::Close()
{
	SBCheckError(TElOpenOfficeDocument_Close(_Handle));
}

SB_INLINE void TElOpenOfficeDocument::Flush()
{
	SBCheckError(TElOpenOfficeDocument_Flush(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOpenOfficeDocument::DecryptTo(TStream &NewStream)
{
	SBCheckError(TElOpenOfficeDocument_DecryptTo(_Handle, NewStream.getHandle()));
}

SB_INLINE void TElOpenOfficeDocument::DecryptTo(TStream *NewStream)
{
	SBCheckError(TElOpenOfficeDocument_DecryptTo(_Handle, (NewStream != NULL) ? NewStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOpenOfficeDocument::EncryptTo(TStream &NewStream)
{
	SBCheckError(TElOpenOfficeDocument_EncryptTo(_Handle, NewStream.getHandle()));
}

SB_INLINE void TElOpenOfficeDocument::EncryptTo(TStream *NewStream)
{
	SBCheckError(TElOpenOfficeDocument_EncryptTo(_Handle, (NewStream != NULL) ? NewStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELOPENOFFICECUSTOMSIGNATUREHANDLER
SB_INLINE int32_t TElOpenOfficeDocument::AddSignature(TElOpenOfficeCustomSignatureHandler &Handler)
{
	int32_t OutResult;
	SBCheckError(TElOpenOfficeDocument_AddSignature(_Handle, Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOpenOfficeDocument::AddSignature(TElOpenOfficeCustomSignatureHandler *Handler)
{
	int32_t OutResult;
	SBCheckError(TElOpenOfficeDocument_AddSignature(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOPENOFFICECUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOPENOFFICECUSTOMSIGNATUREHANDLER
SB_INLINE int32_t TElOpenOfficeDocument::AddSignature(TElOpenOfficeCustomSignatureHandler &Handler, bool OwnHandler)
{
	int32_t OutResult;
	SBCheckError(TElOpenOfficeDocument_AddSignature_1(_Handle, Handler.getHandle(), (int8_t)OwnHandler, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOpenOfficeDocument::AddSignature(TElOpenOfficeCustomSignatureHandler *Handler, bool OwnHandler)
{
	int32_t OutResult;
	SBCheckError(TElOpenOfficeDocument_AddSignature_1(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, (int8_t)OwnHandler, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOPENOFFICECUSTOMSIGNATUREHANDLER */

SB_INLINE void TElOpenOfficeDocument::RemoveSignature(int32_t Index)
{
	SBCheckError(TElOpenOfficeDocument_RemoveSignature(_Handle, Index));
}

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELOPENOFFICECUSTOMSIGNATUREHANDLER
SB_INLINE void TElOpenOfficeDocument::CompleteAsyncSign(TElOpenOfficeCustomSignatureHandler &Handler, TElDCAsyncState &State)
{
	SBCheckError(TElOpenOfficeDocument_CompleteAsyncSign(_Handle, Handler.getHandle(), State.getHandle()));
}

SB_INLINE void TElOpenOfficeDocument::CompleteAsyncSign(TElOpenOfficeCustomSignatureHandler *Handler, TElDCAsyncState *State)
{
	SBCheckError(TElOpenOfficeDocument_CompleteAsyncSign(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELOPENOFFICECUSTOMSIGNATUREHANDLER */

TSBOpenOfficeDocumentType TElOpenOfficeDocument::get_DocumentType()
{
	TSBOpenOfficeDocumentTypeRaw OutResultRaw = 0;
	SBCheckError(TElOpenOfficeDocument_get_DocumentType(_Handle, &OutResultRaw));
	return (TSBOpenOfficeDocumentType)OutResultRaw;
}

bool TElOpenOfficeDocument::get_Encryptable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOpenOfficeDocument_get_Encryptable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOpenOfficeDocument::get_Signable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOpenOfficeDocument_get_Signable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOpenOfficeDocument::get_IsEncrypted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOpenOfficeDocument_get_IsEncrypted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOpenOfficeDocument::get_IsSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOpenOfficeDocument_get_IsSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER
TElOfficeCustomEncryptionHandler* TElOpenOfficeDocument::get_EncryptionHandler()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOpenOfficeDocument_get_EncryptionHandler(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptionHandler)
		this->_Inst_EncryptionHandler = new TElOfficeCustomEncryptionHandler(hOutResult, ohFalse);
	else
		this->_Inst_EncryptionHandler->updateHandle(hOutResult);
	return this->_Inst_EncryptionHandler;
}

SB_INLINE void TElOpenOfficeDocument::set_EncryptionHandler(TElOfficeCustomEncryptionHandler &Value)
{
	SBCheckError(TElOpenOfficeDocument_set_EncryptionHandler(_Handle, Value.getHandle()));
}

SB_INLINE void TElOpenOfficeDocument::set_EncryptionHandler(TElOfficeCustomEncryptionHandler *Value)
{
	SBCheckError(TElOpenOfficeDocument_set_EncryptionHandler(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER */

bool TElOpenOfficeDocument::get_OwnEncryptionHandler()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOpenOfficeDocument_get_OwnEncryptionHandler(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOpenOfficeDocument::set_OwnEncryptionHandler(bool Value)
{
	SBCheckError(TElOpenOfficeDocument_set_OwnEncryptionHandler(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElOpenOfficeDocument::get_SignatureHandlerCount()
{
	int32_t OutResult;
	SBCheckError(TElOpenOfficeDocument_get_SignatureHandlerCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOPENOFFICECUSTOMSIGNATUREHANDLER
TElOpenOfficeCustomSignatureHandler* TElOpenOfficeDocument::get_SignatureHandlers(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOpenOfficeDocument_get_SignatureHandlers(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureHandlers)
		this->_Inst_SignatureHandlers = new TElOpenOfficeCustomSignatureHandler(hOutResult, ohFalse);
	else
		this->_Inst_SignatureHandlers->updateHandle(hOutResult);
	return this->_Inst_SignatureHandlers;
}
#endif /* SB_USE_CLASS_TELOPENOFFICECUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOPENOFFICEPACKAGE
TElOpenOfficePackage* TElOpenOfficeDocument::get_Package()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOpenOfficeDocument_get_Package(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Package)
		this->_Inst_Package = new TElOpenOfficePackage(hOutResult, ohFalse);
	else
		this->_Inst_Package->updateHandle(hOutResult);
	return this->_Inst_Package;
}
#endif /* SB_USE_CLASS_TELOPENOFFICEPACKAGE */

SB_INLINE void TElOpenOfficeDocument::get_OnCreateTemporaryStream(TSBOfficeCreateTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOpenOfficeDocument_get_OnCreateTemporaryStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOpenOfficeDocument::set_OnCreateTemporaryStream(TSBOfficeCreateTemporaryStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOpenOfficeDocument_set_OnCreateTemporaryStream(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElOpenOfficeDocument::get_OnCloseTemporaryStream(TSBOfficeCloseTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOpenOfficeDocument_get_OnCloseTemporaryStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOpenOfficeDocument::set_OnCloseTemporaryStream(TSBOfficeCloseTemporaryStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOpenOfficeDocument_set_OnCloseTemporaryStream(_Handle, pMethodValue, pDataValue));
}

void TElOpenOfficeDocument::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER
	this->_Inst_EncryptionHandler = NULL;
#endif /* SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER */
#ifdef SB_USE_CLASS_TELOPENOFFICECUSTOMSIGNATUREHANDLER
	this->_Inst_SignatureHandlers = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICECUSTOMSIGNATUREHANDLER */
#ifdef SB_USE_CLASS_TELOPENOFFICEPACKAGE
	this->_Inst_Package = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICEPACKAGE */
}

TElOpenOfficeDocument::TElOpenOfficeDocument(TElOpenOfficeDocumentHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElOpenOfficeDocument::TElOpenOfficeDocument() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOpenOfficeDocument_Create(&_Handle));
}

TElOpenOfficeDocument::~TElOpenOfficeDocument()
{
#ifdef SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER
	delete this->_Inst_EncryptionHandler;
	this->_Inst_EncryptionHandler = NULL;
#endif /* SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER */
#ifdef SB_USE_CLASS_TELOPENOFFICECUSTOMSIGNATUREHANDLER
	delete this->_Inst_SignatureHandlers;
	this->_Inst_SignatureHandlers = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICECUSTOMSIGNATUREHANDLER */
#ifdef SB_USE_CLASS_TELOPENOFFICEPACKAGE
	delete this->_Inst_Package;
	this->_Inst_Package = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICEPACKAGE */
}
#endif /* SB_USE_CLASS_TELOPENOFFICEDOCUMENT */

#ifdef SB_USE_CLASS_TELOFFICEDOCUMENT

SB_INLINE void TElOfficeDocument::Open(const std::string &FileName)
{
	SBCheckError(TElOfficeDocument_Open(_Handle, FileName.data(), (int32_t)FileName.length()));
}

SB_INLINE void TElOfficeDocument::Open(const std::string &FileName, bool ReadOnly)
{
	SBCheckError(TElOfficeDocument_Open_1(_Handle, FileName.data(), (int32_t)FileName.length(), (int8_t)ReadOnly));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeDocument::Open(TStream &Stream)
{
	SBCheckError(TElOfficeDocument_Open_2(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeDocument::Open(TStream *Stream)
{
	SBCheckError(TElOfficeDocument_Open_2(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeDocument::Open(TStream &Stream, bool OwnStream)
{
	SBCheckError(TElOfficeDocument_Open_3(_Handle, Stream.getHandle(), (int8_t)OwnStream));
}

SB_INLINE void TElOfficeDocument::Open(TStream *Stream, bool OwnStream)
{
	SBCheckError(TElOfficeDocument_Open_3(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)OwnStream));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeDocument::Open(TStream &Stream, bool OwnStream, bool ReadOnly)
{
	SBCheckError(TElOfficeDocument_Open_4(_Handle, Stream.getHandle(), (int8_t)OwnStream, (int8_t)ReadOnly));
}

SB_INLINE void TElOfficeDocument::Open(TStream *Stream, bool OwnStream, bool ReadOnly)
{
	SBCheckError(TElOfficeDocument_Open_4(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)OwnStream, (int8_t)ReadOnly));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElOfficeDocument::Close()
{
	SBCheckError(TElOfficeDocument_Close(_Handle));
}

SB_INLINE void TElOfficeDocument::Flush()
{
	SBCheckError(TElOfficeDocument_Flush(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeDocument::DecryptTo(TStream &NewStream)
{
	SBCheckError(TElOfficeDocument_DecryptTo(_Handle, NewStream.getHandle()));
}

SB_INLINE void TElOfficeDocument::DecryptTo(TStream *NewStream)
{
	SBCheckError(TElOfficeDocument_DecryptTo(_Handle, (NewStream != NULL) ? NewStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeDocument::EncryptTo(TStream &NewStream)
{
	SBCheckError(TElOfficeDocument_EncryptTo(_Handle, NewStream.getHandle()));
}

SB_INLINE void TElOfficeDocument::EncryptTo(TStream *NewStream)
{
	SBCheckError(TElOfficeDocument_EncryptTo(_Handle, (NewStream != NULL) ? NewStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELOFFICECUSTOMSIGNATUREHANDLER
SB_INLINE int32_t TElOfficeDocument::AddSignature(TElOfficeCustomSignatureHandler &Handler)
{
	int32_t OutResult;
	SBCheckError(TElOfficeDocument_AddSignature(_Handle, Handler.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeDocument::AddSignature(TElOfficeCustomSignatureHandler *Handler)
{
	int32_t OutResult;
	SBCheckError(TElOfficeDocument_AddSignature(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICECUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOFFICECUSTOMSIGNATUREHANDLER
SB_INLINE int32_t TElOfficeDocument::AddSignature(TElOfficeCustomSignatureHandler &Handler, bool OwnHandler)
{
	int32_t OutResult;
	SBCheckError(TElOfficeDocument_AddSignature_1(_Handle, Handler.getHandle(), (int8_t)OwnHandler, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeDocument::AddSignature(TElOfficeCustomSignatureHandler *Handler, bool OwnHandler)
{
	int32_t OutResult;
	SBCheckError(TElOfficeDocument_AddSignature_1(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, (int8_t)OwnHandler, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICECUSTOMSIGNATUREHANDLER */

SB_INLINE void TElOfficeDocument::RemoveSignature(int32_t Index)
{
	SBCheckError(TElOfficeDocument_RemoveSignature(_Handle, Index));
}

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELOFFICECUSTOMSIGNATUREHANDLER
SB_INLINE void TElOfficeDocument::CompleteAsyncSign(TElOfficeCustomSignatureHandler &Handler, TElDCAsyncState &State)
{
	SBCheckError(TElOfficeDocument_CompleteAsyncSign(_Handle, Handler.getHandle(), State.getHandle()));
}

SB_INLINE void TElOfficeDocument::CompleteAsyncSign(TElOfficeCustomSignatureHandler *Handler, TElDCAsyncState *State)
{
	SBCheckError(TElOfficeDocument_CompleteAsyncSign(_Handle, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELOFFICECUSTOMSIGNATUREHANDLER */

TSBOfficeDocumentFormat TElOfficeDocument::get_DocumentFormat()
{
	TSBOfficeDocumentFormatRaw OutResultRaw = 0;
	SBCheckError(TElOfficeDocument_get_DocumentFormat(_Handle, &OutResultRaw));
	return (TSBOfficeDocumentFormat)OutResultRaw;
}

bool TElOfficeDocument::get_IsEncrypted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeDocument_get_IsEncrypted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOfficeDocument::get_IsSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeDocument_get_IsSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOfficeDocument::get_Encryptable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeDocument_get_Encryptable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOfficeDocument::get_Signable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeDocument_get_Signable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElOfficeDocument::get_SignatureHandlerCount()
{
	int32_t OutResult;
	SBCheckError(TElOfficeDocument_get_SignatureHandlerCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICECUSTOMSIGNATUREHANDLER
TElOfficeCustomSignatureHandler* TElOfficeDocument::get_SignatureHandlers(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeDocument_get_SignatureHandlers(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureHandlers)
		this->_Inst_SignatureHandlers = new TElOfficeCustomSignatureHandler(hOutResult, ohFalse);
	else
		this->_Inst_SignatureHandlers->updateHandle(hOutResult);
	return this->_Inst_SignatureHandlers;
}
#endif /* SB_USE_CLASS_TELOFFICECUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEBINARYDOCUMENT
TElOfficeBinaryDocument* TElOfficeDocument::get_BinaryDocument()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeDocument_get_BinaryDocument(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_BinaryDocument)
		this->_Inst_BinaryDocument = new TElOfficeBinaryDocument(hOutResult, ohFalse);
	else
		this->_Inst_BinaryDocument->updateHandle(hOutResult);
	return this->_Inst_BinaryDocument;
}
#endif /* SB_USE_CLASS_TELOFFICEBINARYDOCUMENT */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDOCUMENT
TElOfficeOpenXMLDocument* TElOfficeDocument::get_OpenXMLDocument()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeDocument_get_OpenXMLDocument(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OpenXMLDocument)
		this->_Inst_OpenXMLDocument = new TElOfficeOpenXMLDocument(hOutResult, ohFalse);
	else
		this->_Inst_OpenXMLDocument->updateHandle(hOutResult);
	return this->_Inst_OpenXMLDocument;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDOCUMENT */

#ifdef SB_USE_CLASS_TELOFFICEOPENXPSDOCUMENT
TElOfficeOpenXPSDocument* TElOfficeDocument::get_OpenXPSDocument()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeDocument_get_OpenXPSDocument(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OpenXPSDocument)
		this->_Inst_OpenXPSDocument = new TElOfficeOpenXPSDocument(hOutResult, ohFalse);
	else
		this->_Inst_OpenXPSDocument->updateHandle(hOutResult);
	return this->_Inst_OpenXPSDocument;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXPSDOCUMENT */

#ifdef SB_USE_CLASS_TELOPENOFFICEDOCUMENT
TElOpenOfficeDocument* TElOfficeDocument::get_OpenDocument()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeDocument_get_OpenDocument(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OpenDocument)
		this->_Inst_OpenDocument = new TElOpenOfficeDocument(hOutResult, ohFalse);
	else
		this->_Inst_OpenDocument->updateHandle(hOutResult);
	return this->_Inst_OpenDocument;
}
#endif /* SB_USE_CLASS_TELOPENOFFICEDOCUMENT */

#ifdef SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER
TElOfficeCustomEncryptionHandler* TElOfficeDocument::get_EncryptionHandler()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeDocument_get_EncryptionHandler(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptionHandler)
		this->_Inst_EncryptionHandler = new TElOfficeCustomEncryptionHandler(hOutResult, ohFalse);
	else
		this->_Inst_EncryptionHandler->updateHandle(hOutResult);
	return this->_Inst_EncryptionHandler;
}

SB_INLINE void TElOfficeDocument::set_EncryptionHandler(TElOfficeCustomEncryptionHandler &Value)
{
	SBCheckError(TElOfficeDocument_set_EncryptionHandler(_Handle, Value.getHandle()));
}

SB_INLINE void TElOfficeDocument::set_EncryptionHandler(TElOfficeCustomEncryptionHandler *Value)
{
	SBCheckError(TElOfficeDocument_set_EncryptionHandler(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER */

SB_INLINE void TElOfficeDocument::get_OnCreateTemporaryStream(TSBOfficeCreateTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOfficeDocument_get_OnCreateTemporaryStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOfficeDocument::set_OnCreateTemporaryStream(TSBOfficeCreateTemporaryStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOfficeDocument_set_OnCreateTemporaryStream(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElOfficeDocument::get_OnCloseTemporaryStream(TSBOfficeCloseTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOfficeDocument_get_OnCloseTemporaryStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOfficeDocument::set_OnCloseTemporaryStream(TSBOfficeCloseTemporaryStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOfficeDocument_set_OnCloseTemporaryStream(_Handle, pMethodValue, pDataValue));
}

void TElOfficeDocument::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICECUSTOMSIGNATUREHANDLER
	this->_Inst_SignatureHandlers = NULL;
#endif /* SB_USE_CLASS_TELOFFICECUSTOMSIGNATUREHANDLER */
#ifdef SB_USE_CLASS_TELOFFICEBINARYDOCUMENT
	this->_Inst_BinaryDocument = NULL;
#endif /* SB_USE_CLASS_TELOFFICEBINARYDOCUMENT */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDOCUMENT
	this->_Inst_OpenXMLDocument = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDOCUMENT */
#ifdef SB_USE_CLASS_TELOFFICEOPENXPSDOCUMENT
	this->_Inst_OpenXPSDocument = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXPSDOCUMENT */
#ifdef SB_USE_CLASS_TELOPENOFFICEDOCUMENT
	this->_Inst_OpenDocument = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICEDOCUMENT */
#ifdef SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER
	this->_Inst_EncryptionHandler = NULL;
#endif /* SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER */
}

TElOfficeDocument::TElOfficeDocument(TElOfficeDocumentHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElOfficeDocument::TElOfficeDocument(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeDocument_Create(AOwner.getHandle(), &_Handle));
}

TElOfficeDocument::TElOfficeDocument(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeDocument_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElOfficeDocument::~TElOfficeDocument()
{
#ifdef SB_USE_CLASS_TELOFFICECUSTOMSIGNATUREHANDLER
	delete this->_Inst_SignatureHandlers;
	this->_Inst_SignatureHandlers = NULL;
#endif /* SB_USE_CLASS_TELOFFICECUSTOMSIGNATUREHANDLER */
#ifdef SB_USE_CLASS_TELOFFICEBINARYDOCUMENT
	delete this->_Inst_BinaryDocument;
	this->_Inst_BinaryDocument = NULL;
#endif /* SB_USE_CLASS_TELOFFICEBINARYDOCUMENT */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDOCUMENT
	delete this->_Inst_OpenXMLDocument;
	this->_Inst_OpenXMLDocument = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDOCUMENT */
#ifdef SB_USE_CLASS_TELOFFICEOPENXPSDOCUMENT
	delete this->_Inst_OpenXPSDocument;
	this->_Inst_OpenXPSDocument = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXPSDOCUMENT */
#ifdef SB_USE_CLASS_TELOPENOFFICEDOCUMENT
	delete this->_Inst_OpenDocument;
	this->_Inst_OpenDocument = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICEDOCUMENT */
#ifdef SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER
	delete this->_Inst_EncryptionHandler;
	this->_Inst_EncryptionHandler = NULL;
#endif /* SB_USE_CLASS_TELOFFICECUSTOMENCRYPTIONHANDLER */
}
#endif /* SB_USE_CLASS_TELOFFICEDOCUMENT */

#ifdef SB_USE_GLOBAL_PROCS_OFFICE

void DocumentFormatToString(TSBOfficeDocumentFormat DocumentFormat, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOffice_DocumentFormatToString((TSBOfficeDocumentFormatRaw)DocumentFormat, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(810234296, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void BinaryDocumentTypeToString(TSBOfficeBinaryDocumentType DocumentType, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOffice_BinaryDocumentTypeToString((TSBOfficeBinaryDocumentTypeRaw)DocumentType, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1115096248, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void OpenXMLDocumentTypeToString(TSBOfficeOpenXMLDocumentType DocumentType, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOffice_OpenXMLDocumentTypeToString((TSBOfficeOpenXMLDocumentTypeRaw)DocumentType, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1764667792, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void OpenDocumentTypeToString(TSBOpenOfficeDocumentType DocumentType, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBOffice_OpenDocumentTypeToString((TSBOpenOfficeDocumentTypeRaw)DocumentType, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1904181607, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE
bool IsSharedWorkbook(TElCompoundFileStorage &Storage)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBOffice_IsSharedWorkbook(Storage.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}
bool IsSharedWorkbook(TElCompoundFileStorage *Storage)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBOffice_IsSharedWorkbook((Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */

#endif /* SB_USE_GLOBAL_PROCS_OFFICE */

};	/* namespace SecureBlackbox */

