#include "sbpdf.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPDFDOCUMENT

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPDFDocument::Open(TStream &Stream)
{
	SBCheckError(TElPDFDocument_Open(_Handle, Stream.getHandle()));
}

SB_INLINE void TElPDFDocument::Open(TStream *Stream)
{
	SBCheckError(TElPDFDocument_Open(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPDFDocument::Close(bool Save)
{
	SBCheckError(TElPDFDocument_Close(_Handle, (int8_t)Save));
}

SB_INLINE void TElPDFDocument::Encrypt()
{
	SBCheckError(TElPDFDocument_Encrypt(_Handle));
}

SB_INLINE void TElPDFDocument::SignAndEncrypt()
{
	SBCheckError(TElPDFDocument_SignAndEncrypt(_Handle));
}

SB_INLINE void TElPDFDocument::Decrypt()
{
	SBCheckError(TElPDFDocument_Decrypt(_Handle));
}

SB_INLINE int32_t TElPDFDocument::AddSignature()
{
	int32_t OutResult;
	SBCheckError(TElPDFDocument_AddSignature(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFDocument::AddSignature(int32_t EmptySignatureField)
{
	int32_t OutResult;
	SBCheckError(TElPDFDocument_AddSignature_1(_Handle, EmptySignatureField, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPDFSIGNATURE
SB_INLINE TElPDFSignatureHandle TElPDFDocument::InsertSignature(int32_t Index)
{
	TElPDFSignatureHandle OutResult;
	SBCheckError(TElPDFDocument_InsertSignature(_Handle, Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPDFSIGNATURE */

SB_INLINE void TElPDFDocument::ClearSignatures()
{
	SBCheckError(TElPDFDocument_ClearSignatures(_Handle));
}

SB_INLINE void TElPDFDocument::RemoveSignature(int32_t Index)
{
	SBCheckError(TElPDFDocument_RemoveSignature(_Handle, Index));
}

SB_INLINE void TElPDFDocument::RemoveSignature(int32_t Index, TSBPDFSignatureRemoveOption SigRemoveOption)
{
	SBCheckError(TElPDFDocument_RemoveSignature_1(_Handle, Index, (TSBPDFSignatureRemoveOptionRaw)SigRemoveOption));
}

SB_INLINE void TElPDFDocument::RemoveEmptySignatureField(int32_t Index)
{
	SBCheckError(TElPDFDocument_RemoveEmptySignatureField(_Handle, Index));
}

SB_INLINE void TElPDFDocument::RemoveEmptySignatureField(int32_t Index, TSBPDFSignatureRemoveOption SigRemoveOption)
{
	SBCheckError(TElPDFDocument_RemoveEmptySignatureField_1(_Handle, Index, (TSBPDFSignatureRemoveOptionRaw)SigRemoveOption));
}

SB_INLINE int32_t TElPDFDocument::AddAttachedFile()
{
	int32_t OutResult;
	SBCheckError(TElPDFDocument_AddAttachedFile(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFDocument::RemoveAttachedFile(int32_t Index)
{
	SBCheckError(TElPDFDocument_RemoveAttachedFile(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
SB_INLINE TElDCAsyncStateHandle TElPDFDocument::InitiateAsyncOperation()
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElPDFDocument_InitiateAsyncOperation(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
SB_INLINE TElDCAsyncStateHandle TElPDFDocument::InitiateAsyncOperation(TSBDCAsyncSignMethod AsyncSignMethod)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElPDFDocument_InitiateAsyncOperation_1(_Handle, (TSBDCAsyncSignMethodRaw)AsyncSignMethod, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELPDFSECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElPDFDocument::CompleteAsyncOperation(TStream &Stream, TElDCAsyncState &AsyncState, TElPDFSecurityHandler &Handler)
{
	SBCheckError(TElPDFDocument_CompleteAsyncOperation(_Handle, Stream.getHandle(), AsyncState.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElPDFDocument::CompleteAsyncOperation(TStream *Stream, TElDCAsyncState *AsyncState, TElPDFSecurityHandler *Handler)
{
	SBCheckError(TElPDFDocument_CompleteAsyncOperation(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (AsyncState != NULL) ? AsyncState->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELPDFSECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELPDFPAGEINFO
TElPDFPageInfo* TElPDFDocument::get_PageInfos(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFDocument_get_PageInfos(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PageInfos)
		this->_Inst_PageInfos = new TElPDFPageInfo(hOutResult, ohFalse);
	else
		this->_Inst_PageInfos->updateHandle(hOutResult);
	return this->_Inst_PageInfos;
}
#endif /* SB_USE_CLASS_TELPDFPAGEINFO */

#ifdef SB_USE_CLASS_TELPDFSIGNATURE
TElPDFSignature* TElPDFDocument::get_Signatures(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFDocument_get_Signatures(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signatures)
		this->_Inst_Signatures = new TElPDFSignature(hOutResult, ohFalse);
	else
		this->_Inst_Signatures->updateHandle(hOutResult);
	return this->_Inst_Signatures;
}
#endif /* SB_USE_CLASS_TELPDFSIGNATURE */

#ifdef SB_USE_CLASS_TELPDFFILEATTACHMENT
TElPDFFileAttachment* TElPDFDocument::get_AttachedFiles(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFDocument_get_AttachedFiles(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AttachedFiles)
		this->_Inst_AttachedFiles = new TElPDFFileAttachment(hOutResult, ohFalse);
	else
		this->_Inst_AttachedFiles->updateHandle(hOutResult);
	return this->_Inst_AttachedFiles;
}
#endif /* SB_USE_CLASS_TELPDFFILEATTACHMENT */

#ifdef SB_USE_CLASS_TELPDFSIGNATUREINFO
TElPDFSignatureInfo* TElPDFDocument::get_EmptySignatureFields(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFDocument_get_EmptySignatureFields(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EmptySignatureFields)
		this->_Inst_EmptySignatureFields = new TElPDFSignatureInfo(hOutResult, ohFalse);
	else
		this->_Inst_EmptySignatureFields->updateHandle(hOutResult);
	return this->_Inst_EmptySignatureFields;
}
#endif /* SB_USE_CLASS_TELPDFSIGNATUREINFO */

#ifdef SB_USE_CLASS_TELPDFREQUIREMENT
TElPDFRequirement* TElPDFDocument::get_DocumentRequirements(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFDocument_get_DocumentRequirements(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DocumentRequirements)
		this->_Inst_DocumentRequirements = new TElPDFRequirement(hOutResult, ohFalse);
	else
		this->_Inst_DocumentRequirements->updateHandle(hOutResult);
	return this->_Inst_DocumentRequirements;
}
#endif /* SB_USE_CLASS_TELPDFREQUIREMENT */

#ifdef SB_USE_CLASS_TELPDFARRAY
TElPDFArray* TElPDFDocument::get_DocumentID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFDocument_get_DocumentID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DocumentID)
		this->_Inst_DocumentID = new TElPDFArray(hOutResult, ohFalse);
	else
		this->_Inst_DocumentID->updateHandle(hOutResult);
	return this->_Inst_DocumentID;
}
#endif /* SB_USE_CLASS_TELPDFARRAY */

SB_INLINE int32_t TElPDFDocument::get_DocumentVersion()
{
	int32_t OutResult;
	SBCheckError(TElPDFDocument_get_DocumentVersion(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFDocument::set_DocumentVersion(int32_t Value)
{
	SBCheckError(TElPDFDocument_set_DocumentVersion(_Handle, Value));
}

SB_INLINE int32_t TElPDFDocument::get_EmptySignatureFieldCount()
{
	int32_t OutResult;
	SBCheckError(TElPDFDocument_get_EmptySignatureFieldCount(_Handle, &OutResult));
	return OutResult;
}

bool TElPDFDocument::get_Decrypted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFDocument_get_Decrypted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPDFDocument::get_Encrypted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFDocument_get_Encrypted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELPDFSECURITYHANDLER
TElPDFSecurityHandler* TElPDFDocument::get_EncryptionHandler()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFDocument_get_EncryptionHandler(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptionHandler)
		this->_Inst_EncryptionHandler = new TElPDFSecurityHandler(hOutResult, ohFalse);
	else
		this->_Inst_EncryptionHandler->updateHandle(hOutResult);
	return this->_Inst_EncryptionHandler;
}

SB_INLINE void TElPDFDocument::set_EncryptionHandler(TElPDFSecurityHandler &Value)
{
	SBCheckError(TElPDFDocument_set_EncryptionHandler(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFDocument::set_EncryptionHandler(TElPDFSecurityHandler *Value)
{
	SBCheckError(TElPDFDocument_set_EncryptionHandler(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPDFSECURITYHANDLER */

bool TElPDFDocument::get_Opened()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFDocument_get_Opened(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElPDFDocument::get_DocumentRequirementCount()
{
	int32_t OutResult;
	SBCheckError(TElPDFDocument_get_DocumentRequirementCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFDocument::get_PageInfoCount()
{
	int32_t OutResult;
	SBCheckError(TElPDFDocument_get_PageInfoCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFDocument::get_SignatureCount()
{
	int32_t OutResult;
	SBCheckError(TElPDFDocument_get_SignatureCount(_Handle, &OutResult));
	return OutResult;
}

bool TElPDFDocument::get_Signed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFDocument_get_Signed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElPDFDocument::get_AttachedFileCount()
{
	int32_t OutResult;
	SBCheckError(TElPDFDocument_get_AttachedFileCount(_Handle, &OutResult));
	return OutResult;
}

TSBPDFAssemblyOptions TElPDFDocument::get_AssemblyOptions()
{
	TSBPDFAssemblyOptionsRaw OutResultRaw = 0;
	SBCheckError(TElPDFDocument_get_AssemblyOptions(_Handle, &OutResultRaw));
	return (TSBPDFAssemblyOptions)OutResultRaw;
}

SB_INLINE void TElPDFDocument::set_AssemblyOptions(TSBPDFAssemblyOptions Value)
{
	SBCheckError(TElPDFDocument_set_AssemblyOptions(_Handle, (TSBPDFAssemblyOptionsRaw)Value));
}

#ifdef SB_USE_CLASS_TELPDFARRAY
TElPDFArray* TElPDFDocument::get_DocumentRoot()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFDocument_get_DocumentRoot(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DocumentRoot)
		this->_Inst_DocumentRoot = new TElPDFArray(hOutResult, ohFalse);
	else
		this->_Inst_DocumentRoot->updateHandle(hOutResult);
	return this->_Inst_DocumentRoot;
}
#endif /* SB_USE_CLASS_TELPDFARRAY */

#ifdef SB_USE_CLASS_TELPDFFILE
TElPDFFile* TElPDFDocument::get_PDFFile()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFDocument_get_PDFFile(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PDFFile)
		this->_Inst_PDFFile = new TElPDFFile(hOutResult, ohFalse);
	else
		this->_Inst_PDFFile->updateHandle(hOutResult);
	return this->_Inst_PDFFile;
}
#endif /* SB_USE_CLASS_TELPDFFILE */

TSBPDFDecryptionMode TElPDFDocument::get_DecryptionMode()
{
	TSBPDFDecryptionModeRaw OutResultRaw = 0;
	SBCheckError(TElPDFDocument_get_DecryptionMode(_Handle, &OutResultRaw));
	return (TSBPDFDecryptionMode)OutResultRaw;
}

SB_INLINE void TElPDFDocument::set_DecryptionMode(TSBPDFDecryptionMode Value)
{
	SBCheckError(TElPDFDocument_set_DecryptionMode(_Handle, (TSBPDFDecryptionModeRaw)Value));
}

bool TElPDFDocument::get_Adobe8Compatibility()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFDocument_get_Adobe8Compatibility(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFDocument::set_Adobe8Compatibility(bool Value)
{
	SBCheckError(TElPDFDocument_set_Adobe8Compatibility(_Handle, (int8_t)Value));
}

bool TElPDFDocument::get_ExtractSignaturesFromPages()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFDocument_get_ExtractSignaturesFromPages(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFDocument::set_ExtractSignaturesFromPages(bool Value)
{
	SBCheckError(TElPDFDocument_set_ExtractSignaturesFromPages(_Handle, (int8_t)Value));
}

void TElPDFDocument::get_SignatureCustomDataName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFDocument_get_SignatureCustomDataName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2022351833, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFDocument::set_SignatureCustomDataName(const std::string &Value)
{
	SBCheckError(TElPDFDocument_set_SignatureCustomDataName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELPDFLEGALCONTENTATTESTATION
TElPDFLegalContentAttestation* TElPDFDocument::get_LegalContentAttestation()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFDocument_get_LegalContentAttestation(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_LegalContentAttestation)
		this->_Inst_LegalContentAttestation = new TElPDFLegalContentAttestation(hOutResult, ohFalse);
	else
		this->_Inst_LegalContentAttestation->updateHandle(hOutResult);
	return this->_Inst_LegalContentAttestation;
}
#endif /* SB_USE_CLASS_TELPDFLEGALCONTENTATTESTATION */

bool TElPDFDocument::get_ActivateSecurityHandlers()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFDocument_get_ActivateSecurityHandlers(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFDocument::set_ActivateSecurityHandlers(bool Value)
{
	SBCheckError(TElPDFDocument_set_ActivateSecurityHandlers(_Handle, (int8_t)Value));
}

bool TElPDFDocument::get_OwnActivatedSecurityHandlers()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFDocument_get_OwnActivatedSecurityHandlers(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFDocument::set_OwnActivatedSecurityHandlers(bool Value)
{
	SBCheckError(TElPDFDocument_set_OwnActivatedSecurityHandlers(_Handle, (int8_t)Value));
}

bool TElPDFDocument::get_Compress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFDocument_get_Compress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFDocument::set_Compress(bool Value)
{
	SBCheckError(TElPDFDocument_set_Compress(_Handle, (int8_t)Value));
}

SB_INLINE void TElPDFDocument::get_OnProgress(TSBPDFProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPDFDocument_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPDFDocument::set_OnProgress(TSBPDFProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPDFDocument_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPDFDocument::get_OnCreateTemporaryStream(TSBPDFCreateTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPDFDocument_get_OnCreateTemporaryStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPDFDocument::set_OnCreateTemporaryStream(TSBPDFCreateTemporaryStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPDFDocument_set_OnCreateTemporaryStream(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPDFDocument::get_OnDecryptionInfoNeeded(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPDFDocument_get_OnDecryptionInfoNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPDFDocument::set_OnDecryptionInfoNeeded(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPDFDocument_set_OnDecryptionInfoNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPDFDocument::get_OnBeforeSign(TSBPDFBeforeSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPDFDocument_get_OnBeforeSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPDFDocument::set_OnBeforeSign(TSBPDFBeforeSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPDFDocument_set_OnBeforeSign(_Handle, pMethodValue, pDataValue));
}

void TElPDFDocument::initInstances()
{
#ifdef SB_USE_CLASS_TELPDFPAGEINFO
	this->_Inst_PageInfos = NULL;
#endif /* SB_USE_CLASS_TELPDFPAGEINFO */
#ifdef SB_USE_CLASS_TELPDFSIGNATURE
	this->_Inst_Signatures = NULL;
#endif /* SB_USE_CLASS_TELPDFSIGNATURE */
#ifdef SB_USE_CLASS_TELPDFFILEATTACHMENT
	this->_Inst_AttachedFiles = NULL;
#endif /* SB_USE_CLASS_TELPDFFILEATTACHMENT */
#ifdef SB_USE_CLASS_TELPDFSIGNATUREINFO
	this->_Inst_EmptySignatureFields = NULL;
#endif /* SB_USE_CLASS_TELPDFSIGNATUREINFO */
#ifdef SB_USE_CLASS_TELPDFREQUIREMENT
	this->_Inst_DocumentRequirements = NULL;
#endif /* SB_USE_CLASS_TELPDFREQUIREMENT */
#ifdef SB_USE_CLASS_TELPDFARRAY
	this->_Inst_DocumentID = NULL;
#endif /* SB_USE_CLASS_TELPDFARRAY */
#ifdef SB_USE_CLASS_TELPDFSECURITYHANDLER
	this->_Inst_EncryptionHandler = NULL;
#endif /* SB_USE_CLASS_TELPDFSECURITYHANDLER */
#ifdef SB_USE_CLASS_TELPDFARRAY
	this->_Inst_DocumentRoot = NULL;
#endif /* SB_USE_CLASS_TELPDFARRAY */
#ifdef SB_USE_CLASS_TELPDFFILE
	this->_Inst_PDFFile = NULL;
#endif /* SB_USE_CLASS_TELPDFFILE */
#ifdef SB_USE_CLASS_TELPDFLEGALCONTENTATTESTATION
	this->_Inst_LegalContentAttestation = NULL;
#endif /* SB_USE_CLASS_TELPDFLEGALCONTENTATTESTATION */
}

TElPDFDocument::TElPDFDocument(TElPDFDocumentHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElPDFDocument::TElPDFDocument(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFDocument_Create(AOwner.getHandle(), &_Handle));
}

TElPDFDocument::TElPDFDocument(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFDocument_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElPDFDocument::~TElPDFDocument()
{
#ifdef SB_USE_CLASS_TELPDFPAGEINFO
	delete this->_Inst_PageInfos;
	this->_Inst_PageInfos = NULL;
#endif /* SB_USE_CLASS_TELPDFPAGEINFO */
#ifdef SB_USE_CLASS_TELPDFSIGNATURE
	delete this->_Inst_Signatures;
	this->_Inst_Signatures = NULL;
#endif /* SB_USE_CLASS_TELPDFSIGNATURE */
#ifdef SB_USE_CLASS_TELPDFFILEATTACHMENT
	delete this->_Inst_AttachedFiles;
	this->_Inst_AttachedFiles = NULL;
#endif /* SB_USE_CLASS_TELPDFFILEATTACHMENT */
#ifdef SB_USE_CLASS_TELPDFSIGNATUREINFO
	delete this->_Inst_EmptySignatureFields;
	this->_Inst_EmptySignatureFields = NULL;
#endif /* SB_USE_CLASS_TELPDFSIGNATUREINFO */
#ifdef SB_USE_CLASS_TELPDFREQUIREMENT
	delete this->_Inst_DocumentRequirements;
	this->_Inst_DocumentRequirements = NULL;
#endif /* SB_USE_CLASS_TELPDFREQUIREMENT */
#ifdef SB_USE_CLASS_TELPDFARRAY
	delete this->_Inst_DocumentID;
	this->_Inst_DocumentID = NULL;
#endif /* SB_USE_CLASS_TELPDFARRAY */
#ifdef SB_USE_CLASS_TELPDFSECURITYHANDLER
	delete this->_Inst_EncryptionHandler;
	this->_Inst_EncryptionHandler = NULL;
#endif /* SB_USE_CLASS_TELPDFSECURITYHANDLER */
#ifdef SB_USE_CLASS_TELPDFARRAY
	delete this->_Inst_DocumentRoot;
	this->_Inst_DocumentRoot = NULL;
#endif /* SB_USE_CLASS_TELPDFARRAY */
#ifdef SB_USE_CLASS_TELPDFFILE
	delete this->_Inst_PDFFile;
	this->_Inst_PDFFile = NULL;
#endif /* SB_USE_CLASS_TELPDFFILE */
#ifdef SB_USE_CLASS_TELPDFLEGALCONTENTATTESTATION
	delete this->_Inst_LegalContentAttestation;
	this->_Inst_LegalContentAttestation = NULL;
#endif /* SB_USE_CLASS_TELPDFLEGALCONTENTATTESTATION */
}
#endif /* SB_USE_CLASS_TELPDFDOCUMENT */

#ifdef SB_USE_CLASS_TELPDFURPROPERTIES

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPDFURProperties::get_AnnotationRights()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFURProperties_get_AnnotationRights(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AnnotationRights)
		this->_Inst_AnnotationRights = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_AnnotationRights->updateHandle(hOutResult);
	return this->_Inst_AnnotationRights;
}

SB_INLINE void TElPDFURProperties::set_AnnotationRights(TStringList &Value)
{
	SBCheckError(TElPDFURProperties_set_AnnotationRights(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFURProperties::set_AnnotationRights(TStringList *Value)
{
	SBCheckError(TElPDFURProperties_set_AnnotationRights(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElPDFURProperties::get_AnnotationRights()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFURProperties_get_AnnotationRights(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AnnotationRights)
		this->_Inst_AnnotationRights = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_AnnotationRights->updateHandle(hOutResult);
	return this->_Inst_AnnotationRights;
}

SB_INLINE void TElPDFURProperties::set_AnnotationRights(TElStringList &Value)
{
	SBCheckError(TElPDFURProperties_set_AnnotationRights(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFURProperties::set_AnnotationRights(TElStringList *Value)
{
	SBCheckError(TElPDFURProperties_set_AnnotationRights(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPDFURProperties::get_DocumentRights()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFURProperties_get_DocumentRights(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DocumentRights)
		this->_Inst_DocumentRights = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_DocumentRights->updateHandle(hOutResult);
	return this->_Inst_DocumentRights;
}

SB_INLINE void TElPDFURProperties::set_DocumentRights(TStringList &Value)
{
	SBCheckError(TElPDFURProperties_set_DocumentRights(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFURProperties::set_DocumentRights(TStringList *Value)
{
	SBCheckError(TElPDFURProperties_set_DocumentRights(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElPDFURProperties::get_DocumentRights()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFURProperties_get_DocumentRights(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DocumentRights)
		this->_Inst_DocumentRights = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_DocumentRights->updateHandle(hOutResult);
	return this->_Inst_DocumentRights;
}

SB_INLINE void TElPDFURProperties::set_DocumentRights(TElStringList &Value)
{
	SBCheckError(TElPDFURProperties_set_DocumentRights(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFURProperties::set_DocumentRights(TElStringList *Value)
{
	SBCheckError(TElPDFURProperties_set_DocumentRights(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPDFURProperties::get_EmbeddedFileRights()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFURProperties_get_EmbeddedFileRights(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EmbeddedFileRights)
		this->_Inst_EmbeddedFileRights = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_EmbeddedFileRights->updateHandle(hOutResult);
	return this->_Inst_EmbeddedFileRights;
}

SB_INLINE void TElPDFURProperties::set_EmbeddedFileRights(TStringList &Value)
{
	SBCheckError(TElPDFURProperties_set_EmbeddedFileRights(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFURProperties::set_EmbeddedFileRights(TStringList *Value)
{
	SBCheckError(TElPDFURProperties_set_EmbeddedFileRights(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElPDFURProperties::get_EmbeddedFileRights()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFURProperties_get_EmbeddedFileRights(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EmbeddedFileRights)
		this->_Inst_EmbeddedFileRights = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_EmbeddedFileRights->updateHandle(hOutResult);
	return this->_Inst_EmbeddedFileRights;
}

SB_INLINE void TElPDFURProperties::set_EmbeddedFileRights(TElStringList &Value)
{
	SBCheckError(TElPDFURProperties_set_EmbeddedFileRights(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFURProperties::set_EmbeddedFileRights(TElStringList *Value)
{
	SBCheckError(TElPDFURProperties_set_EmbeddedFileRights(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPDFURProperties::get_FormExRights()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFURProperties_get_FormExRights(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FormExRights)
		this->_Inst_FormExRights = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_FormExRights->updateHandle(hOutResult);
	return this->_Inst_FormExRights;
}

SB_INLINE void TElPDFURProperties::set_FormExRights(TStringList &Value)
{
	SBCheckError(TElPDFURProperties_set_FormExRights(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFURProperties::set_FormExRights(TStringList *Value)
{
	SBCheckError(TElPDFURProperties_set_FormExRights(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElPDFURProperties::get_FormExRights()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFURProperties_get_FormExRights(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FormExRights)
		this->_Inst_FormExRights = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_FormExRights->updateHandle(hOutResult);
	return this->_Inst_FormExRights;
}

SB_INLINE void TElPDFURProperties::set_FormExRights(TElStringList &Value)
{
	SBCheckError(TElPDFURProperties_set_FormExRights(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFURProperties::set_FormExRights(TElStringList *Value)
{
	SBCheckError(TElPDFURProperties_set_FormExRights(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPDFURProperties::get_FormRights()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFURProperties_get_FormRights(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FormRights)
		this->_Inst_FormRights = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_FormRights->updateHandle(hOutResult);
	return this->_Inst_FormRights;
}

SB_INLINE void TElPDFURProperties::set_FormRights(TStringList &Value)
{
	SBCheckError(TElPDFURProperties_set_FormRights(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFURProperties::set_FormRights(TStringList *Value)
{
	SBCheckError(TElPDFURProperties_set_FormRights(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElPDFURProperties::get_FormRights()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFURProperties_get_FormRights(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FormRights)
		this->_Inst_FormRights = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_FormRights->updateHandle(hOutResult);
	return this->_Inst_FormRights;
}

SB_INLINE void TElPDFURProperties::set_FormRights(TElStringList &Value)
{
	SBCheckError(TElPDFURProperties_set_FormRights(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFURProperties::set_FormRights(TElStringList *Value)
{
	SBCheckError(TElPDFURProperties_set_FormRights(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElPDFURProperties::get_Message(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFURProperties_get_Message(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1456968177, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFURProperties::set_Message(const std::string &Value)
{
	SBCheckError(TElPDFURProperties_set_Message(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElPDFURProperties::get_P()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFURProperties_get_P(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFURProperties::set_P(bool Value)
{
	SBCheckError(TElPDFURProperties_set_P(_Handle, (int8_t)Value));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPDFURProperties::get_SignatureRights()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFURProperties_get_SignatureRights(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureRights)
		this->_Inst_SignatureRights = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_SignatureRights->updateHandle(hOutResult);
	return this->_Inst_SignatureRights;
}

SB_INLINE void TElPDFURProperties::set_SignatureRights(TStringList &Value)
{
	SBCheckError(TElPDFURProperties_set_SignatureRights(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFURProperties::set_SignatureRights(TStringList *Value)
{
	SBCheckError(TElPDFURProperties_set_SignatureRights(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElPDFURProperties::get_SignatureRights()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFURProperties_get_SignatureRights(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureRights)
		this->_Inst_SignatureRights = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_SignatureRights->updateHandle(hOutResult);
	return this->_Inst_SignatureRights;
}

SB_INLINE void TElPDFURProperties::set_SignatureRights(TElStringList &Value)
{
	SBCheckError(TElPDFURProperties_set_SignatureRights(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFURProperties::set_SignatureRights(TElStringList *Value)
{
	SBCheckError(TElPDFURProperties_set_SignatureRights(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElPDFURProperties::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_AnnotationRights = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_AnnotationRights = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_DocumentRights = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_DocumentRights = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_EmbeddedFileRights = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_EmbeddedFileRights = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_FormExRights = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_FormExRights = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_FormRights = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_FormRights = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_SignatureRights = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_SignatureRights = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElPDFURProperties::TElPDFURProperties(TElPDFURPropertiesHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPDFURProperties::TElPDFURProperties() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFURProperties_Create(&_Handle));
}

TElPDFURProperties::~TElPDFURProperties()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_AnnotationRights;
	this->_Inst_AnnotationRights = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_AnnotationRights;
	this->_Inst_AnnotationRights = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_DocumentRights;
	this->_Inst_DocumentRights = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_DocumentRights;
	this->_Inst_DocumentRights = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_EmbeddedFileRights;
	this->_Inst_EmbeddedFileRights = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_EmbeddedFileRights;
	this->_Inst_EmbeddedFileRights = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_FormExRights;
	this->_Inst_FormExRights = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_FormExRights;
	this->_Inst_FormExRights = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_FormRights;
	this->_Inst_FormRights = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_FormRights;
	this->_Inst_FormRights = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_SignatureRights;
	this->_Inst_SignatureRights = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_SignatureRights;
	this->_Inst_SignatureRights = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELPDFURPROPERTIES */

#ifdef SB_USE_CLASS_TELPDFSIGREFENTRY

bool TElPDFSigRefEntry::get_Valid()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSigRefEntry_get_Valid(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int16_t TElPDFSigRefEntry::get_DocMDPAccessPermissions()
{
	int16_t OutResult;
	SBCheckError(TElPDFSigRefEntry_get_DocMDPAccessPermissions(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSigRefEntry::set_DocMDPAccessPermissions(int16_t Value)
{
	SBCheckError(TElPDFSigRefEntry_set_DocMDPAccessPermissions(_Handle, Value));
}

TSBPDFFieldMDPAction TElPDFSigRefEntry::get_FieldMDPAction()
{
	TSBPDFFieldMDPActionRaw OutResultRaw = 0;
	SBCheckError(TElPDFSigRefEntry_get_FieldMDPAction(_Handle, &OutResultRaw));
	return (TSBPDFFieldMDPAction)OutResultRaw;
}

SB_INLINE void TElPDFSigRefEntry::set_FieldMDPAction(TSBPDFFieldMDPAction Value)
{
	SBCheckError(TElPDFSigRefEntry_set_FieldMDPAction(_Handle, (TSBPDFFieldMDPActionRaw)Value));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPDFSigRefEntry::get_FieldMDPFields()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSigRefEntry_get_FieldMDPFields(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FieldMDPFields)
		this->_Inst_FieldMDPFields = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_FieldMDPFields->updateHandle(hOutResult);
	return this->_Inst_FieldMDPFields;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElPDFSigRefEntry::get_FieldMDPFields()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSigRefEntry_get_FieldMDPFields(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FieldMDPFields)
		this->_Inst_FieldMDPFields = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_FieldMDPFields->updateHandle(hOutResult);
	return this->_Inst_FieldMDPFields;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

TSBPDFDigestMethod TElPDFSigRefEntry::get_DigestMethod()
{
	TSBPDFDigestMethodRaw OutResultRaw = 0;
	SBCheckError(TElPDFSigRefEntry_get_DigestMethod(_Handle, &OutResultRaw));
	return (TSBPDFDigestMethod)OutResultRaw;
}

SB_INLINE void TElPDFSigRefEntry::set_DigestMethod(TSBPDFDigestMethod Value)
{
	SBCheckError(TElPDFSigRefEntry_set_DigestMethod(_Handle, (TSBPDFDigestMethodRaw)Value));
}

TSBPDFTransformMethod TElPDFSigRefEntry::get_TransformMethod()
{
	TSBPDFTransformMethodRaw OutResultRaw = 0;
	SBCheckError(TElPDFSigRefEntry_get_TransformMethod(_Handle, &OutResultRaw));
	return (TSBPDFTransformMethod)OutResultRaw;
}

SB_INLINE void TElPDFSigRefEntry::set_TransformMethod(TSBPDFTransformMethod Value)
{
	SBCheckError(TElPDFSigRefEntry_set_TransformMethod(_Handle, (TSBPDFTransformMethodRaw)Value));
}

#ifdef SB_USE_CLASS_TELPDFURPROPERTIES
TElPDFURProperties* TElPDFSigRefEntry::get_URProperties()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSigRefEntry_get_URProperties(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_URProperties)
		this->_Inst_URProperties = new TElPDFURProperties(hOutResult, ohFalse);
	else
		this->_Inst_URProperties->updateHandle(hOutResult);
	return this->_Inst_URProperties;
}
#endif /* SB_USE_CLASS_TELPDFURPROPERTIES */

void TElPDFSigRefEntry::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_FieldMDPFields = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_FieldMDPFields = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELPDFURPROPERTIES
	this->_Inst_URProperties = NULL;
#endif /* SB_USE_CLASS_TELPDFURPROPERTIES */
}

TElPDFSigRefEntry::TElPDFSigRefEntry(TElPDFSigRefEntryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPDFSigRefEntry::TElPDFSigRefEntry() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFSigRefEntry_Create(&_Handle));
}

TElPDFSigRefEntry::~TElPDFSigRefEntry()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_FieldMDPFields;
	this->_Inst_FieldMDPFields = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_FieldMDPFields;
	this->_Inst_FieldMDPFields = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELPDFURPROPERTIES
	delete this->_Inst_URProperties;
	this->_Inst_URProperties = NULL;
#endif /* SB_USE_CLASS_TELPDFURPROPERTIES */
}
#endif /* SB_USE_CLASS_TELPDFSIGREFENTRY */

#ifdef SB_USE_CLASS_TELPDFSECURITYHANDLER

SB_INLINE void TElPDFSecurityHandler::Reset()
{
	SBCheckError(TElPDFSecurityHandler_Reset(_Handle));
}

void TElPDFSecurityHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSecurityHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1039705289, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPDFSecurityHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSecurityHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1039705289, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPDFSecurityHandler::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSecurityHandler_GetDescription((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1737411733, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPDFSecurityHandler::GetDescription_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSecurityHandler_GetDescription_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1737411733, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TElPDFSecurityHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPDFSecurityHandler_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFSecurityHandler::get_StreamEncryptionAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPDFSecurityHandler_get_StreamEncryptionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSecurityHandler::set_StreamEncryptionAlgorithm(int32_t Value)
{
	SBCheckError(TElPDFSecurityHandler_set_StreamEncryptionAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElPDFSecurityHandler::get_StringEncryptionAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPDFSecurityHandler_get_StringEncryptionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSecurityHandler::set_StringEncryptionAlgorithm(int32_t Value)
{
	SBCheckError(TElPDFSecurityHandler_set_StringEncryptionAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElPDFSecurityHandler::get_StreamEncryptionKeyBits()
{
	int32_t OutResult;
	SBCheckError(TElPDFSecurityHandler_get_StreamEncryptionKeyBits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSecurityHandler::set_StreamEncryptionKeyBits(int32_t Value)
{
	SBCheckError(TElPDFSecurityHandler_set_StreamEncryptionKeyBits(_Handle, Value));
}

SB_INLINE int32_t TElPDFSecurityHandler::get_StringEncryptionKeyBits()
{
	int32_t OutResult;
	SBCheckError(TElPDFSecurityHandler_get_StringEncryptionKeyBits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSecurityHandler::set_StringEncryptionKeyBits(int32_t Value)
{
	SBCheckError(TElPDFSecurityHandler_set_StringEncryptionKeyBits(_Handle, Value));
}

bool TElPDFSecurityHandler::get_EncryptMetadata()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSecurityHandler_get_EncryptMetadata(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSecurityHandler::set_EncryptMetadata(bool Value)
{
	SBCheckError(TElPDFSecurityHandler_set_EncryptMetadata(_Handle, (int8_t)Value));
}

void TElPDFSecurityHandler::get_CustomName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSecurityHandler_get_CustomName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1202431368, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSecurityHandler::set_CustomName(const std::string &Value)
{
	SBCheckError(TElPDFSecurityHandler_set_CustomName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElPDFSecurityHandler::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSecurityHandler_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElPDFSecurityHandler::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElPDFSecurityHandler_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFSecurityHandler::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElPDFSecurityHandler_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

void TElPDFSecurityHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}

TElPDFSecurityHandler::TElPDFSecurityHandler(TElPDFSecurityHandlerHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElPDFSecurityHandler::TElPDFSecurityHandler(TComponent &Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFSecurityHandler_Create(Owner.getHandle(), &_Handle));
}

TElPDFSecurityHandler::TElPDFSecurityHandler(TComponent *Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFSecurityHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElPDFSecurityHandler::~TElPDFSecurityHandler()
{
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}
#endif /* SB_USE_CLASS_TELPDFSECURITYHANDLER */

#ifdef SB_USE_CLASS_TELPDFBYTERANGE

SB_INLINE int32_t TElPDFByteRange::get_StartOffset()
{
	int32_t OutResult;
	SBCheckError(TElPDFByteRange_get_StartOffset(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFByteRange::set_StartOffset(int32_t Value)
{
	SBCheckError(TElPDFByteRange_set_StartOffset(_Handle, Value));
}

SB_INLINE int32_t TElPDFByteRange::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElPDFByteRange_get_Count(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFByteRange::set_Count(int32_t Value)
{
	SBCheckError(TElPDFByteRange_set_Count(_Handle, Value));
}

TElPDFByteRange::TElPDFByteRange(TElPDFByteRangeHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPDFByteRange::TElPDFByteRange() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFByteRange_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPDFBYTERANGE */

#ifdef SB_USE_CLASS_TELPDFIMAGE

SB_INLINE int32_t TElPDFImage::AddMaskColorComponent(int32_t MinCC, int32_t MaxCC)
{
	int32_t OutResult;
	SBCheckError(TElPDFImage_AddMaskColorComponent(_Handle, MinCC, MaxCC, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFImage::DeleteMaskColorComponent(int32_t Index)
{
	SBCheckError(TElPDFImage_DeleteMaskColorComponent(_Handle, Index));
}

TSBPDFImageType TElPDFImage::get_ImageType()
{
	TSBPDFImageTypeRaw OutResultRaw = 0;
	SBCheckError(TElPDFImage_get_ImageType(_Handle, &OutResultRaw));
	return (TSBPDFImageType)OutResultRaw;
}

SB_INLINE void TElPDFImage::set_ImageType(TSBPDFImageType Value)
{
	SBCheckError(TElPDFImage_set_ImageType(_Handle, (TSBPDFImageTypeRaw)Value));
}

void TElPDFImage::get_Data(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFImage_get_Data(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1211564542, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFImage::set_Data(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPDFImage_set_Data(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElPDFImage::get_Width()
{
	int32_t OutResult;
	SBCheckError(TElPDFImage_get_Width(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFImage::set_Width(int32_t Value)
{
	SBCheckError(TElPDFImage_set_Width(_Handle, Value));
}

SB_INLINE int32_t TElPDFImage::get_Height()
{
	int32_t OutResult;
	SBCheckError(TElPDFImage_get_Height(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFImage::set_Height(int32_t Value)
{
	SBCheckError(TElPDFImage_set_Height(_Handle, Value));
}

TElPDFImage* TElPDFImage::get_MaskImage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFImage_get_MaskImage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_MaskImage)
		this->_Inst_MaskImage = new TElPDFImage(hOutResult, ohFalse);
	else
		this->_Inst_MaskImage->updateHandle(hOutResult);
	return this->_Inst_MaskImage;
}

SB_INLINE int32_t TElPDFImage::get_MaskColorComponentCount()
{
	int32_t OutResult;
	SBCheckError(TElPDFImage_get_MaskColorComponentCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFImage::get_MaskColorComponentsMin(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TElPDFImage_get_MaskColorComponentsMin(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFImage::get_MaskColorComponentsMax(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TElPDFImage_get_MaskColorComponentsMax(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFImage::get_BitsPerComponent()
{
	int32_t OutResult;
	SBCheckError(TElPDFImage_get_BitsPerComponent(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFImage::set_BitsPerComponent(int32_t Value)
{
	SBCheckError(TElPDFImage_set_BitsPerComponent(_Handle, Value));
}

TSBPDFColorSpaceType TElPDFImage::get_ColorSpaceType()
{
	TSBPDFColorSpaceTypeRaw OutResultRaw = 0;
	SBCheckError(TElPDFImage_get_ColorSpaceType(_Handle, &OutResultRaw));
	return (TSBPDFColorSpaceType)OutResultRaw;
}

SB_INLINE void TElPDFImage::set_ColorSpaceType(TSBPDFColorSpaceType Value)
{
	SBCheckError(TElPDFImage_set_ColorSpaceType(_Handle, (TSBPDFColorSpaceTypeRaw)Value));
}

bool TElPDFImage::get_Interpolate()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFImage_get_Interpolate(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFImage::set_Interpolate(bool Value)
{
	SBCheckError(TElPDFImage_set_Interpolate(_Handle, (int8_t)Value));
}

void TElPDFImage::get_ResourceName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFImage_get_ResourceName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-618133697, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFImage::set_ResourceName(const std::string &Value)
{
	SBCheckError(TElPDFImage_set_ResourceName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFImage::initInstances()
{
	this->_Inst_MaskImage = NULL;
}

TElPDFImage::TElPDFImage(TElPDFImageHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPDFImage::TElPDFImage() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFImage_Create(&_Handle));
}

TElPDFImage::~TElPDFImage()
{
	delete this->_Inst_MaskImage;
	this->_Inst_MaskImage = NULL;
}
#endif /* SB_USE_CLASS_TELPDFIMAGE */

#ifdef SB_USE_CLASS_TELPDFCUSTOMFONTOBJECT

TElPDFCustomFontObject::TElPDFCustomFontObject(TElPDFCustomFontObjectHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPDFCustomFontObject::TElPDFCustomFontObject() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFCustomFontObject_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPDFCUSTOMFONTOBJECT */

#ifdef SB_USE_CLASS_TELPDFENCODING

void TElPDFEncoding::get_BaseEncoding(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFEncoding_get_BaseEncoding(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1290215054, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFEncoding::set_BaseEncoding(const std::string &Value)
{
	SBCheckError(TElPDFEncoding_set_BaseEncoding(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFEncoding::get_Differences(int32_t Index, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFEncoding_get_Differences(_Handle, Index, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1559324114, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFEncoding::set_Differences(int32_t Index, const std::string &Name)
{
	SBCheckError(TElPDFEncoding_set_Differences(_Handle, Index, Name.data(), (int32_t)Name.length()));
}

TElPDFEncoding::TElPDFEncoding(TElPDFEncodingHandle handle, TElOwnHandle ownHandle) : TElPDFCustomFontObject(handle, ownHandle)
{
}

TElPDFEncoding::TElPDFEncoding() : TElPDFCustomFontObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFEncoding_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPDFENCODING */

#ifdef SB_USE_CLASS_TELPDFFONTDESCRIPTOR

void TElPDFFontDescriptor::get_FontName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFFontDescriptor_get_FontName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1696188091, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFFontDescriptor::set_FontName(const std::string &Value)
{
	SBCheckError(TElPDFFontDescriptor_set_FontName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFFontDescriptor::get_FontFamily(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFFontDescriptor_get_FontFamily(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-674021484, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFFontDescriptor::set_FontFamily(const std::string &Value)
{
	SBCheckError(TElPDFFontDescriptor_set_FontFamily(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFFontDescriptor::get_FontStretch(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFFontDescriptor_get_FontStretch(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-664798543, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFFontDescriptor::set_FontStretch(const std::string &Value)
{
	SBCheckError(TElPDFFontDescriptor_set_FontStretch(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElPDFFontDescriptor::get_FontWeight()
{
	int32_t OutResult;
	SBCheckError(TElPDFFontDescriptor_get_FontWeight(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFFontDescriptor::set_FontWeight(int32_t Value)
{
	SBCheckError(TElPDFFontDescriptor_set_FontWeight(_Handle, Value));
}

SB_INLINE int32_t TElPDFFontDescriptor::get_Flags()
{
	int32_t OutResult;
	SBCheckError(TElPDFFontDescriptor_get_Flags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFFontDescriptor::set_Flags(int32_t Value)
{
	SBCheckError(TElPDFFontDescriptor_set_Flags(_Handle, Value));
}

SB_INLINE int32_t TElPDFFontDescriptor::get_FontBBoxX1()
{
	int32_t OutResult;
	SBCheckError(TElPDFFontDescriptor_get_FontBBoxX1(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFFontDescriptor::set_FontBBoxX1(int32_t Value)
{
	SBCheckError(TElPDFFontDescriptor_set_FontBBoxX1(_Handle, Value));
}

SB_INLINE int32_t TElPDFFontDescriptor::get_FontBBoxX2()
{
	int32_t OutResult;
	SBCheckError(TElPDFFontDescriptor_get_FontBBoxX2(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFFontDescriptor::set_FontBBoxX2(int32_t Value)
{
	SBCheckError(TElPDFFontDescriptor_set_FontBBoxX2(_Handle, Value));
}

SB_INLINE int32_t TElPDFFontDescriptor::get_FontBBoxY1()
{
	int32_t OutResult;
	SBCheckError(TElPDFFontDescriptor_get_FontBBoxY1(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFFontDescriptor::set_FontBBoxY1(int32_t Value)
{
	SBCheckError(TElPDFFontDescriptor_set_FontBBoxY1(_Handle, Value));
}

SB_INLINE int32_t TElPDFFontDescriptor::get_FontBBoxY2()
{
	int32_t OutResult;
	SBCheckError(TElPDFFontDescriptor_get_FontBBoxY2(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFFontDescriptor::set_FontBBoxY2(int32_t Value)
{
	SBCheckError(TElPDFFontDescriptor_set_FontBBoxY2(_Handle, Value));
}

SB_INLINE double TElPDFFontDescriptor::get_ItalicAngle()
{
	double OutResult;
	SBCheckError(TElPDFFontDescriptor_get_ItalicAngle(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFFontDescriptor::set_ItalicAngle(double Value)
{
	SBCheckError(TElPDFFontDescriptor_set_ItalicAngle(_Handle, Value));
}

SB_INLINE int32_t TElPDFFontDescriptor::get_Ascent()
{
	int32_t OutResult;
	SBCheckError(TElPDFFontDescriptor_get_Ascent(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFFontDescriptor::set_Ascent(int32_t Value)
{
	SBCheckError(TElPDFFontDescriptor_set_Ascent(_Handle, Value));
}

SB_INLINE int32_t TElPDFFontDescriptor::get_Descent()
{
	int32_t OutResult;
	SBCheckError(TElPDFFontDescriptor_get_Descent(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFFontDescriptor::set_Descent(int32_t Value)
{
	SBCheckError(TElPDFFontDescriptor_set_Descent(_Handle, Value));
}

SB_INLINE int32_t TElPDFFontDescriptor::get_Leading()
{
	int32_t OutResult;
	SBCheckError(TElPDFFontDescriptor_get_Leading(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFFontDescriptor::set_Leading(int32_t Value)
{
	SBCheckError(TElPDFFontDescriptor_set_Leading(_Handle, Value));
}

SB_INLINE int32_t TElPDFFontDescriptor::get_CapHeight()
{
	int32_t OutResult;
	SBCheckError(TElPDFFontDescriptor_get_CapHeight(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFFontDescriptor::set_CapHeight(int32_t Value)
{
	SBCheckError(TElPDFFontDescriptor_set_CapHeight(_Handle, Value));
}

SB_INLINE int32_t TElPDFFontDescriptor::get_XHeight()
{
	int32_t OutResult;
	SBCheckError(TElPDFFontDescriptor_get_XHeight(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFFontDescriptor::set_XHeight(int32_t Value)
{
	SBCheckError(TElPDFFontDescriptor_set_XHeight(_Handle, Value));
}

SB_INLINE int32_t TElPDFFontDescriptor::get_StemV()
{
	int32_t OutResult;
	SBCheckError(TElPDFFontDescriptor_get_StemV(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFFontDescriptor::set_StemV(int32_t Value)
{
	SBCheckError(TElPDFFontDescriptor_set_StemV(_Handle, Value));
}

SB_INLINE int32_t TElPDFFontDescriptor::get_StemH()
{
	int32_t OutResult;
	SBCheckError(TElPDFFontDescriptor_get_StemH(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFFontDescriptor::set_StemH(int32_t Value)
{
	SBCheckError(TElPDFFontDescriptor_set_StemH(_Handle, Value));
}

SB_INLINE int32_t TElPDFFontDescriptor::get_AvgWidth()
{
	int32_t OutResult;
	SBCheckError(TElPDFFontDescriptor_get_AvgWidth(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFFontDescriptor::set_AvgWidth(int32_t Value)
{
	SBCheckError(TElPDFFontDescriptor_set_AvgWidth(_Handle, Value));
}

SB_INLINE int32_t TElPDFFontDescriptor::get_MaxWidth()
{
	int32_t OutResult;
	SBCheckError(TElPDFFontDescriptor_get_MaxWidth(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFFontDescriptor::set_MaxWidth(int32_t Value)
{
	SBCheckError(TElPDFFontDescriptor_set_MaxWidth(_Handle, Value));
}

SB_INLINE int32_t TElPDFFontDescriptor::get_MissingWidth()
{
	int32_t OutResult;
	SBCheckError(TElPDFFontDescriptor_get_MissingWidth(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFFontDescriptor::set_MissingWidth(int32_t Value)
{
	SBCheckError(TElPDFFontDescriptor_set_MissingWidth(_Handle, Value));
}

void TElPDFFontDescriptor::get_FontFile(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFFontDescriptor_get_FontFile(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1213886803, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFFontDescriptor::set_FontFile(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPDFFontDescriptor_set_FontFile(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPDFFontDescriptor::get_FontFile2(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFFontDescriptor_get_FontFile2(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(989662143, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFFontDescriptor::set_FontFile2(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPDFFontDescriptor_set_FontFile2(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPDFFontDescriptor::get_FontFile3(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFFontDescriptor_get_FontFile3(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1308244777, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFFontDescriptor::set_FontFile3(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPDFFontDescriptor_set_FontFile3(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPDFFontDescriptor::get_CharSet(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFFontDescriptor_get_CharSet(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1519027951, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFFontDescriptor::set_CharSet(const std::string &Value)
{
	SBCheckError(TElPDFFontDescriptor_set_CharSet(_Handle, Value.data(), (int32_t)Value.length()));
}

TElPDFFontDescriptor::TElPDFFontDescriptor(TElPDFFontDescriptorHandle handle, TElOwnHandle ownHandle) : TElPDFCustomFontObject(handle, ownHandle)
{
}

TElPDFFontDescriptor::TElPDFFontDescriptor() : TElPDFCustomFontObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFFontDescriptor_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPDFFONTDESCRIPTOR */

#ifdef SB_USE_CLASS_TELPDFCIDFONTDESCRIPTOR

void TElPDFCIDFontDescriptor::get_Lang(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFCIDFontDescriptor_get_Lang(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1656086900, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFCIDFontDescriptor::set_Lang(const std::string &Value)
{
	SBCheckError(TElPDFCIDFontDescriptor_set_Lang(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFCIDFontDescriptor::get_CIDSet(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFCIDFontDescriptor_get_CIDSet(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1068954216, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFCIDFontDescriptor::set_CIDSet(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPDFCIDFontDescriptor_set_CIDSet(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPDFCIDFontDescriptor::TElPDFCIDFontDescriptor(TElPDFCIDFontDescriptorHandle handle, TElOwnHandle ownHandle) : TElPDFFontDescriptor(handle, ownHandle)
{
}

TElPDFCIDFontDescriptor::TElPDFCIDFontDescriptor() : TElPDFFontDescriptor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFCIDFontDescriptor_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPDFCIDFONTDESCRIPTOR */

#ifdef SB_USE_CLASS_TELPDFCIDSYSTEMINFO

void TElPDFCIDSystemInfo::get_Registry(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFCIDSystemInfo_get_Registry(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1525943708, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFCIDSystemInfo::set_Registry(const std::string &Value)
{
	SBCheckError(TElPDFCIDSystemInfo_set_Registry(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFCIDSystemInfo::get_Ordering(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFCIDSystemInfo_get_Ordering(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-328391695, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFCIDSystemInfo::set_Ordering(const std::string &Value)
{
	SBCheckError(TElPDFCIDSystemInfo_set_Ordering(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElPDFCIDSystemInfo::get_Supplement()
{
	int32_t OutResult;
	SBCheckError(TElPDFCIDSystemInfo_get_Supplement(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFCIDSystemInfo::set_Supplement(int32_t Value)
{
	SBCheckError(TElPDFCIDSystemInfo_set_Supplement(_Handle, Value));
}

TElPDFCIDSystemInfo::TElPDFCIDSystemInfo(TElPDFCIDSystemInfoHandle handle, TElOwnHandle ownHandle) : TElPDFCustomFontObject(handle, ownHandle)
{
}

TElPDFCIDSystemInfo::TElPDFCIDSystemInfo() : TElPDFCustomFontObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFCIDSystemInfo_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPDFCIDSYSTEMINFO */

#ifdef SB_USE_CLASS_TELPDFCUSTOMFONT

void TElPDFCustomFont::get_Subtype(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFCustomFont_get_Subtype(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-216579571, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFCustomFont::set_Subtype(const std::string &Value)
{
	SBCheckError(TElPDFCustomFont_set_Subtype(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFCustomFont::get_BaseFont(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFCustomFont_get_BaseFont(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1016664625, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFCustomFont::set_BaseFont(const std::string &Value)
{
	SBCheckError(TElPDFCustomFont_set_BaseFont(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFCustomFont::get_ResourceName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFCustomFont_get_ResourceName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1540228048, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFCustomFont::set_ResourceName(const std::string &Value)
{
	SBCheckError(TElPDFCustomFont_set_ResourceName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFCustomFont::get_ToUnicode(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFCustomFont_get_ToUnicode(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2021492412, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFCustomFont::set_ToUnicode(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPDFCustomFont_set_ToUnicode(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPDFCustomFont::TElPDFCustomFont(TElPDFCustomFontHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPDFCustomFont::TElPDFCustomFont() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFCustomFont_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPDFCUSTOMFONT */

#ifdef SB_USE_CLASS_TELPDFSIMPLEFONT

void TElPDFSimpleFont::get_Encoding(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSimpleFont_get_Encoding(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-752652175, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSimpleFont::set_Encoding(const std::string &Value)
{
	SBCheckError(TElPDFSimpleFont_set_Encoding(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELPDFENCODING
TElPDFEncoding* TElPDFSimpleFont::get_EncodingObject()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSimpleFont_get_EncodingObject(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncodingObject)
		this->_Inst_EncodingObject = new TElPDFEncoding(hOutResult, ohFalse);
	else
		this->_Inst_EncodingObject->updateHandle(hOutResult);
	return this->_Inst_EncodingObject;
}

SB_INLINE void TElPDFSimpleFont::set_EncodingObject(TElPDFEncoding &Value)
{
	SBCheckError(TElPDFSimpleFont_set_EncodingObject(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFSimpleFont::set_EncodingObject(TElPDFEncoding *Value)
{
	SBCheckError(TElPDFSimpleFont_set_EncodingObject(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPDFENCODING */

#ifdef SB_USE_CLASS_TELPDFFONTDESCRIPTOR
TElPDFFontDescriptor* TElPDFSimpleFont::get_FontDescriptor()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSimpleFont_get_FontDescriptor(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FontDescriptor)
		this->_Inst_FontDescriptor = new TElPDFFontDescriptor(hOutResult, ohFalse);
	else
		this->_Inst_FontDescriptor->updateHandle(hOutResult);
	return this->_Inst_FontDescriptor;
}

SB_INLINE void TElPDFSimpleFont::set_FontDescriptor(TElPDFFontDescriptor &Value)
{
	SBCheckError(TElPDFSimpleFont_set_FontDescriptor(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFSimpleFont::set_FontDescriptor(TElPDFFontDescriptor *Value)
{
	SBCheckError(TElPDFSimpleFont_set_FontDescriptor(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPDFFONTDESCRIPTOR */

void TElPDFSimpleFont::get_FontName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSimpleFont_get_FontName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1422583142, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSimpleFont::set_FontName(const std::string &Value)
{
	SBCheckError(TElPDFSimpleFont_set_FontName(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElPDFSimpleFont::get_FirstChar()
{
	int32_t OutResult;
	SBCheckError(TElPDFSimpleFont_get_FirstChar(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSimpleFont::set_FirstChar(int32_t Value)
{
	SBCheckError(TElPDFSimpleFont_set_FirstChar(_Handle, Value));
}

SB_INLINE int32_t TElPDFSimpleFont::get_LastChar()
{
	int32_t OutResult;
	SBCheckError(TElPDFSimpleFont_get_LastChar(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSimpleFont::set_LastChar(int32_t Value)
{
	SBCheckError(TElPDFSimpleFont_set_LastChar(_Handle, Value));
}

void TElPDFSimpleFont::get_Widths(std::vector<int32_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size() * 4;
	uint32_t _err = TElPDFSimpleFont_get_Widths(_Handle, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult / 4);
		SBCheckError(SBGetLastReturnBuffer(-1425806617, 1, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult / 4);
}

SB_INLINE void TElPDFSimpleFont::set_Widths(const std::vector<int32_t> &Value)
{
	SBCheckError(TElPDFSimpleFont_set_Widths(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPDFSimpleFont::initInstances()
{
#ifdef SB_USE_CLASS_TELPDFENCODING
	this->_Inst_EncodingObject = NULL;
#endif /* SB_USE_CLASS_TELPDFENCODING */
#ifdef SB_USE_CLASS_TELPDFFONTDESCRIPTOR
	this->_Inst_FontDescriptor = NULL;
#endif /* SB_USE_CLASS_TELPDFFONTDESCRIPTOR */
}

TElPDFSimpleFont::TElPDFSimpleFont(TElPDFSimpleFontHandle handle, TElOwnHandle ownHandle) : TElPDFCustomFont(handle, ownHandle)
{
	initInstances();
}

TElPDFSimpleFont::TElPDFSimpleFont() : TElPDFCustomFont(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFSimpleFont_Create(&_Handle));
}

TElPDFSimpleFont::~TElPDFSimpleFont()
{
#ifdef SB_USE_CLASS_TELPDFENCODING
	delete this->_Inst_EncodingObject;
	this->_Inst_EncodingObject = NULL;
#endif /* SB_USE_CLASS_TELPDFENCODING */
#ifdef SB_USE_CLASS_TELPDFFONTDESCRIPTOR
	delete this->_Inst_FontDescriptor;
	this->_Inst_FontDescriptor = NULL;
#endif /* SB_USE_CLASS_TELPDFFONTDESCRIPTOR */
}
#endif /* SB_USE_CLASS_TELPDFSIMPLEFONT */

#ifdef SB_USE_CLASS_TELPDFCOMPOSITEFONT

TElPDFCustomFont* TElPDFCompositeFont::get_DescendantFonts()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFCompositeFont_get_DescendantFonts(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DescendantFonts)
		this->_Inst_DescendantFonts = new TElPDFCustomFont(hOutResult, ohFalse);
	else
		this->_Inst_DescendantFonts->updateHandle(hOutResult);
	return this->_Inst_DescendantFonts;
}

SB_INLINE void TElPDFCompositeFont::set_DescendantFonts(TElPDFCustomFont &Value)
{
	SBCheckError(TElPDFCompositeFont_set_DescendantFonts(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFCompositeFont::set_DescendantFonts(TElPDFCustomFont *Value)
{
	SBCheckError(TElPDFCompositeFont_set_DescendantFonts(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

void TElPDFCompositeFont::get_Encoding(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFCompositeFont_get_Encoding(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(764844208, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFCompositeFont::set_Encoding(const std::string &Value)
{
	SBCheckError(TElPDFCompositeFont_set_Encoding(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFCompositeFont::get_EncodingData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFCompositeFont_get_EncodingData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1607248518, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFCompositeFont::set_EncodingData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPDFCompositeFont_set_EncodingData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPDFCompositeFont::initInstances()
{
	this->_Inst_DescendantFonts = NULL;
}

TElPDFCompositeFont::TElPDFCompositeFont(TElPDFCompositeFontHandle handle, TElOwnHandle ownHandle) : TElPDFCustomFont(handle, ownHandle)
{
	initInstances();
}

TElPDFCompositeFont::TElPDFCompositeFont() : TElPDFCustomFont(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFCompositeFont_Create(&_Handle));
}

TElPDFCompositeFont::~TElPDFCompositeFont()
{
	delete this->_Inst_DescendantFonts;
	this->_Inst_DescendantFonts = NULL;
}
#endif /* SB_USE_CLASS_TELPDFCOMPOSITEFONT */

#ifdef SB_USE_CLASS_TELPDFMETRICW

SB_INLINE void TElPDFMetricW::Add(int32_t CID, int32_t Width)
{
	SBCheckError(TElPDFMetricW_Add(_Handle, CID, Width));
}

SB_INLINE void TElPDFMetricW::AddRange(int32_t First, int32_t Last, int32_t Width)
{
	SBCheckError(TElPDFMetricW_AddRange(_Handle, First, Last, Width));
}

TElPDFMetricW::TElPDFMetricW(TElPDFMetricWHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPDFMetricW::TElPDFMetricW() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFMetricW_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPDFMETRICW */

#ifdef SB_USE_CLASS_TELPDFMETRICW2

SB_INLINE void TElPDFMetricW2::Add(int32_t CID, int32_t Width, int32_t VX, int32_t VY)
{
	SBCheckError(TElPDFMetricW2_Add(_Handle, CID, Width, VX, VY));
}

SB_INLINE void TElPDFMetricW2::AddRange(int32_t First, int32_t Last, int32_t Width, int32_t VX, int32_t VY)
{
	SBCheckError(TElPDFMetricW2_AddRange(_Handle, First, Last, Width, VX, VY));
}

TElPDFMetricW2::TElPDFMetricW2(TElPDFMetricW2Handle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPDFMetricW2::TElPDFMetricW2() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFMetricW2_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPDFMETRICW2 */

#ifdef SB_USE_CLASS_TELPDFCIDFONT

#ifdef SB_USE_CLASS_TELPDFCIDSYSTEMINFO
TElPDFCIDSystemInfo* TElPDFCIDFont::get_CIDSystemInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFCIDFont_get_CIDSystemInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CIDSystemInfo)
		this->_Inst_CIDSystemInfo = new TElPDFCIDSystemInfo(hOutResult, ohFalse);
	else
		this->_Inst_CIDSystemInfo->updateHandle(hOutResult);
	return this->_Inst_CIDSystemInfo;
}

SB_INLINE void TElPDFCIDFont::set_CIDSystemInfo(TElPDFCIDSystemInfo &Value)
{
	SBCheckError(TElPDFCIDFont_set_CIDSystemInfo(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFCIDFont::set_CIDSystemInfo(TElPDFCIDSystemInfo *Value)
{
	SBCheckError(TElPDFCIDFont_set_CIDSystemInfo(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPDFCIDSYSTEMINFO */

#ifdef SB_USE_CLASS_TELPDFCIDFONTDESCRIPTOR
TElPDFCIDFontDescriptor* TElPDFCIDFont::get_FontDescriptor()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFCIDFont_get_FontDescriptor(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FontDescriptor)
		this->_Inst_FontDescriptor = new TElPDFCIDFontDescriptor(hOutResult, ohFalse);
	else
		this->_Inst_FontDescriptor->updateHandle(hOutResult);
	return this->_Inst_FontDescriptor;
}

SB_INLINE void TElPDFCIDFont::set_FontDescriptor(TElPDFCIDFontDescriptor &Value)
{
	SBCheckError(TElPDFCIDFont_set_FontDescriptor(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFCIDFont::set_FontDescriptor(TElPDFCIDFontDescriptor *Value)
{
	SBCheckError(TElPDFCIDFont_set_FontDescriptor(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPDFCIDFONTDESCRIPTOR */

SB_INLINE int32_t TElPDFCIDFont::get_DW()
{
	int32_t OutResult;
	SBCheckError(TElPDFCIDFont_get_DW(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFCIDFont::set_DW(int32_t Value)
{
	SBCheckError(TElPDFCIDFont_set_DW(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELPDFMETRICW
TElPDFMetricW* TElPDFCIDFont::get_W()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFCIDFont_get_W(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_W)
		this->_Inst_W = new TElPDFMetricW(hOutResult, ohFalse);
	else
		this->_Inst_W->updateHandle(hOutResult);
	return this->_Inst_W;
}
#endif /* SB_USE_CLASS_TELPDFMETRICW */

void TElPDFCIDFont::get_DW2(std::vector<int32_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size() * 4;
	uint32_t _err = TElPDFCIDFont_get_DW2(_Handle, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult / 4);
		SBCheckError(SBGetLastReturnBuffer(2118271612, 1, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult / 4);
}

SB_INLINE void TElPDFCIDFont::set_DW2(const std::vector<int32_t> &Value)
{
	SBCheckError(TElPDFCIDFont_set_DW2(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELPDFMETRICW2
TElPDFMetricW2* TElPDFCIDFont::get_W2()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFCIDFont_get_W2(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_W2)
		this->_Inst_W2 = new TElPDFMetricW2(hOutResult, ohFalse);
	else
		this->_Inst_W2->updateHandle(hOutResult);
	return this->_Inst_W2;
}

SB_INLINE void TElPDFCIDFont::set_W2(TElPDFMetricW2 &Value)
{
	SBCheckError(TElPDFCIDFont_set_W2(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFCIDFont::set_W2(TElPDFMetricW2 *Value)
{
	SBCheckError(TElPDFCIDFont_set_W2(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPDFMETRICW2 */

void TElPDFCIDFont::get_CIDToGIDMap(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFCIDFont_get_CIDToGIDMap(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(336015422, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFCIDFont::set_CIDToGIDMap(const std::string &Value)
{
	SBCheckError(TElPDFCIDFont_set_CIDToGIDMap(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFCIDFont::get_CIDToGIDMapData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFCIDFont_get_CIDToGIDMapData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1300343801, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFCIDFont::set_CIDToGIDMapData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPDFCIDFont_set_CIDToGIDMapData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPDFCIDFont::initInstances()
{
#ifdef SB_USE_CLASS_TELPDFCIDSYSTEMINFO
	this->_Inst_CIDSystemInfo = NULL;
#endif /* SB_USE_CLASS_TELPDFCIDSYSTEMINFO */
#ifdef SB_USE_CLASS_TELPDFCIDFONTDESCRIPTOR
	this->_Inst_FontDescriptor = NULL;
#endif /* SB_USE_CLASS_TELPDFCIDFONTDESCRIPTOR */
#ifdef SB_USE_CLASS_TELPDFMETRICW
	this->_Inst_W = NULL;
#endif /* SB_USE_CLASS_TELPDFMETRICW */
#ifdef SB_USE_CLASS_TELPDFMETRICW2
	this->_Inst_W2 = NULL;
#endif /* SB_USE_CLASS_TELPDFMETRICW2 */
}

TElPDFCIDFont::TElPDFCIDFont(TElPDFCIDFontHandle handle, TElOwnHandle ownHandle) : TElPDFCustomFont(handle, ownHandle)
{
	initInstances();
}

TElPDFCIDFont::TElPDFCIDFont() : TElPDFCustomFont(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFCIDFont_Create(&_Handle));
}

TElPDFCIDFont::~TElPDFCIDFont()
{
#ifdef SB_USE_CLASS_TELPDFCIDSYSTEMINFO
	delete this->_Inst_CIDSystemInfo;
	this->_Inst_CIDSystemInfo = NULL;
#endif /* SB_USE_CLASS_TELPDFCIDSYSTEMINFO */
#ifdef SB_USE_CLASS_TELPDFCIDFONTDESCRIPTOR
	delete this->_Inst_FontDescriptor;
	this->_Inst_FontDescriptor = NULL;
#endif /* SB_USE_CLASS_TELPDFCIDFONTDESCRIPTOR */
#ifdef SB_USE_CLASS_TELPDFMETRICW
	delete this->_Inst_W;
	this->_Inst_W = NULL;
#endif /* SB_USE_CLASS_TELPDFMETRICW */
#ifdef SB_USE_CLASS_TELPDFMETRICW2
	delete this->_Inst_W2;
	this->_Inst_W2 = NULL;
#endif /* SB_USE_CLASS_TELPDFMETRICW2 */
}
#endif /* SB_USE_CLASS_TELPDFCIDFONT */

#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXT

void TElPDFSignatureWidgetText::get_Text(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignatureWidgetText_get_Text(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-275365401, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSignatureWidgetText::set_Text(const std::string &Value)
{
	SBCheckError(TElPDFSignatureWidgetText_set_Text(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE double TElPDFSignatureWidgetText::get_FontSizeX()
{
	double OutResult;
	SBCheckError(TElPDFSignatureWidgetText_get_FontSizeX(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSignatureWidgetText::set_FontSizeX(double Value)
{
	SBCheckError(TElPDFSignatureWidgetText_set_FontSizeX(_Handle, Value));
}

SB_INLINE double TElPDFSignatureWidgetText::get_FontSizeY()
{
	double OutResult;
	SBCheckError(TElPDFSignatureWidgetText_get_FontSizeY(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSignatureWidgetText::set_FontSizeY(double Value)
{
	SBCheckError(TElPDFSignatureWidgetText_set_FontSizeY(_Handle, Value));
}

SB_INLINE double TElPDFSignatureWidgetText::get_X()
{
	double OutResult;
	SBCheckError(TElPDFSignatureWidgetText_get_X(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSignatureWidgetText::set_X(double Value)
{
	SBCheckError(TElPDFSignatureWidgetText_set_X(_Handle, Value));
}

SB_INLINE double TElPDFSignatureWidgetText::get_Y()
{
	double OutResult;
	SBCheckError(TElPDFSignatureWidgetText_get_Y(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSignatureWidgetText::set_Y(double Value)
{
	SBCheckError(TElPDFSignatureWidgetText_set_Y(_Handle, Value));
}

void TElPDFSignatureWidgetText::get_FontResourceName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignatureWidgetText_get_FontResourceName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1791938801, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSignatureWidgetText::set_FontResourceName(const std::string &Value)
{
	SBCheckError(TElPDFSignatureWidgetText_set_FontResourceName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFSignatureWidgetText::get_CustomData(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignatureWidgetText_get_CustomData(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-736478558, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSignatureWidgetText::set_CustomData(const std::string &Value)
{
	SBCheckError(TElPDFSignatureWidgetText_set_CustomData(_Handle, Value.data(), (int32_t)Value.length()));
}

TElPDFSignatureWidgetText::TElPDFSignatureWidgetText(TElPDFSignatureWidgetTextHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPDFSignatureWidgetText::TElPDFSignatureWidgetText() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFSignatureWidgetText_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXT */

#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXTLIST

SB_INLINE int32_t TElPDFSignatureWidgetTextList::Add(const std::string &Text, double X, double Y, double FontSize)
{
	int32_t OutResult;
	SBCheckError(TElPDFSignatureWidgetTextList_Add(_Handle, Text.data(), (int32_t)Text.length(), X, Y, FontSize, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFSignatureWidgetTextList::Add(const std::string &Text, double X, double Y, double FontSizeX, double FontSizeY)
{
	int32_t OutResult;
	SBCheckError(TElPDFSignatureWidgetTextList_Add_1(_Handle, Text.data(), (int32_t)Text.length(), X, Y, FontSizeX, FontSizeY, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXT
SB_INLINE int32_t TElPDFSignatureWidgetTextList::Add(TElPDFSignatureWidgetText &ATextData)
{
	int32_t OutResult;
	SBCheckError(TElPDFSignatureWidgetTextList_Add_2(_Handle, ATextData.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFSignatureWidgetTextList::Add(TElPDFSignatureWidgetText *ATextData)
{
	int32_t OutResult;
	SBCheckError(TElPDFSignatureWidgetTextList_Add_2(_Handle, (ATextData != NULL) ? ATextData->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXT */

SB_INLINE int32_t TElPDFSignatureWidgetTextList::Add()
{
	int32_t OutResult;
	SBCheckError(TElPDFSignatureWidgetTextList_Add_3(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSignatureWidgetTextList::Delete(int32_t Index)
{
	SBCheckError(TElPDFSignatureWidgetTextList_Delete(_Handle, Index));
}

SB_INLINE void TElPDFSignatureWidgetTextList::Clear()
{
	SBCheckError(TElPDFSignatureWidgetTextList_Clear(_Handle));
}

SB_INLINE int32_t TElPDFSignatureWidgetTextList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElPDFSignatureWidgetTextList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXT
TElPDFSignatureWidgetText* TElPDFSignatureWidgetTextList::get_TextData(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSignatureWidgetTextList_get_TextData(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TextData)
		this->_Inst_TextData = new TElPDFSignatureWidgetText(hOutResult, ohFalse);
	else
		this->_Inst_TextData->updateHandle(hOutResult);
	return this->_Inst_TextData;
}
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXT */

void TElPDFSignatureWidgetTextList::initInstances()
{
#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXT
	this->_Inst_TextData = NULL;
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXT */
}

TElPDFSignatureWidgetTextList::TElPDFSignatureWidgetTextList(TElPDFSignatureWidgetTextListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPDFSignatureWidgetTextList::TElPDFSignatureWidgetTextList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFSignatureWidgetTextList_Create(&_Handle));
}

TElPDFSignatureWidgetTextList::~TElPDFSignatureWidgetTextList()
{
#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXT
	delete this->_Inst_TextData;
	this->_Inst_TextData = NULL;
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXT */
}
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXTLIST */

#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETPROPS

#ifdef SB_USE_CLASS_TELPDFCUSTOMFONT
SB_INLINE void TElPDFSignatureWidgetProps::AddFont(TElPDFCustomFont &Font)
{
	SBCheckError(TElPDFSignatureWidgetProps_AddFont(_Handle, Font.getHandle()));
}

SB_INLINE void TElPDFSignatureWidgetProps::AddFont(TElPDFCustomFont *Font)
{
	SBCheckError(TElPDFSignatureWidgetProps_AddFont(_Handle, (Font != NULL) ? Font->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPDFCUSTOMFONT */

#ifdef SB_USE_CLASS_TELPDFCUSTOMFONTOBJECT
SB_INLINE void TElPDFSignatureWidgetProps::AddFontObject(TElPDFCustomFontObject &FontObject)
{
	SBCheckError(TElPDFSignatureWidgetProps_AddFontObject(_Handle, FontObject.getHandle()));
}

SB_INLINE void TElPDFSignatureWidgetProps::AddFontObject(TElPDFCustomFontObject *FontObject)
{
	SBCheckError(TElPDFSignatureWidgetProps_AddFontObject(_Handle, (FontObject != NULL) ? FontObject->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPDFCUSTOMFONTOBJECT */

#ifdef SB_USE_CLASS_TELPDFIMAGE
SB_INLINE void TElPDFSignatureWidgetProps::AddImage(TElPDFImage &Image)
{
	SBCheckError(TElPDFSignatureWidgetProps_AddImage(_Handle, Image.getHandle()));
}

SB_INLINE void TElPDFSignatureWidgetProps::AddImage(TElPDFImage *Image)
{
	SBCheckError(TElPDFSignatureWidgetProps_AddImage(_Handle, (Image != NULL) ? Image->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPDFIMAGE */

#ifdef SB_USE_CLASS_TELPDFIMAGE
SB_INLINE void TElPDFSignatureWidgetProps::AddImage(TElPDFImage &Image, double X, double Y, double SizeX, double SizeY)
{
	SBCheckError(TElPDFSignatureWidgetProps_AddImage_1(_Handle, Image.getHandle(), X, Y, SizeX, SizeY));
}

SB_INLINE void TElPDFSignatureWidgetProps::AddImage(TElPDFImage *Image, double X, double Y, double SizeX, double SizeY)
{
	SBCheckError(TElPDFSignatureWidgetProps_AddImage_1(_Handle, (Image != NULL) ? Image->getHandle() : SB_NULL_HANDLE, X, Y, SizeX, SizeY));
}
#endif /* SB_USE_CLASS_TELPDFIMAGE */

SB_INLINE void TElPDFSignatureWidgetProps::ClearFonts()
{
	SBCheckError(TElPDFSignatureWidgetProps_ClearFonts(_Handle));
}

SB_INLINE void TElPDFSignatureWidgetProps::ClearFontObjects()
{
	SBCheckError(TElPDFSignatureWidgetProps_ClearFontObjects(_Handle));
}

SB_INLINE void TElPDFSignatureWidgetProps::ClearImages()
{
	SBCheckError(TElPDFSignatureWidgetProps_ClearImages(_Handle));
}

void TElPDFSignatureWidgetProps::get_AlgorithmInfo(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignatureWidgetProps_get_AlgorithmInfo(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1546345732, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_AlgorithmInfo(const std::string &Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_AlgorithmInfo(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElPDFSignatureWidgetProps::get_AutoAdjustEncoding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_AutoAdjustEncoding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_AutoAdjustEncoding(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_AutoAdjustEncoding(_Handle, (int8_t)Value));
}

bool TElPDFSignatureWidgetProps::get_AutoText()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_AutoText(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_AutoText(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_AutoText(_Handle, (int8_t)Value));
}

bool TElPDFSignatureWidgetProps::get_AutoFontSize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_AutoFontSize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_AutoFontSize(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_AutoFontSize(_Handle, (int8_t)Value));
}

bool TElPDFSignatureWidgetProps::get_AutoSize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_AutoSize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_AutoSize(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_AutoSize(_Handle, (int8_t)Value));
}

bool TElPDFSignatureWidgetProps::get_AutoPos()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_AutoPos(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_AutoPos(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_AutoPos(_Handle, (int8_t)Value));
}

bool TElPDFSignatureWidgetProps::get_AutoStretchBackground()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_AutoStretchBackground(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_AutoStretchBackground(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_AutoStretchBackground(_Handle, (int8_t)Value));
}

void TElPDFSignatureWidgetProps::get_Header(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignatureWidgetProps_get_Header(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(795439122, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_Header(const std::string &Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_Header(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElPDFSignatureWidgetProps::get_Height()
{
	int32_t OutResult;
	SBCheckError(TElPDFSignatureWidgetProps_get_Height(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSignatureWidgetProps::set_Height(int32_t Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_Height(_Handle, Value));
}

bool TElPDFSignatureWidgetProps::get_Locked()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_Locked(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_Locked(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_Locked(_Handle, (int8_t)Value));
}

bool TElPDFSignatureWidgetProps::get_LockedContents()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_LockedContents(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_LockedContents(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_LockedContents(_Handle, (int8_t)Value));
}

bool TElPDFSignatureWidgetProps::get_NoRotate()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_NoRotate(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_NoRotate(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_NoRotate(_Handle, (int8_t)Value));
}

bool TElPDFSignatureWidgetProps::get_NoView()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_NoView(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_NoView(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_NoView(_Handle, (int8_t)Value));
}

bool TElPDFSignatureWidgetProps::get_NoZoom()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_NoZoom(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_NoZoom(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_NoZoom(_Handle, (int8_t)Value));
}

bool TElPDFSignatureWidgetProps::get_Print()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_Print(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_Print(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_Print(_Handle, (int8_t)Value));
}

bool TElPDFSignatureWidgetProps::get_ReadOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_ReadOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_ReadOnly(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_ReadOnly(_Handle, (int8_t)Value));
}

bool TElPDFSignatureWidgetProps::get_ToggleNoView()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_ToggleNoView(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_ToggleNoView(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_ToggleNoView(_Handle, (int8_t)Value));
}

bool TElPDFSignatureWidgetProps::get_ShowTimestamp()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_ShowTimestamp(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_ShowTimestamp(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_ShowTimestamp(_Handle, (int8_t)Value));
}

void TElPDFSignatureWidgetProps::get_SignerInfo(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignatureWidgetProps_get_SignerInfo(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1600814012, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_SignerInfo(const std::string &Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_SignerInfo(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElPDFSignatureWidgetProps::get_Width()
{
	int32_t OutResult;
	SBCheckError(TElPDFSignatureWidgetProps_get_Width(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSignatureWidgetProps::set_Width(int32_t Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_Width(_Handle, Value));
}

SB_INLINE int32_t TElPDFSignatureWidgetProps::get_OffsetX()
{
	int32_t OutResult;
	SBCheckError(TElPDFSignatureWidgetProps_get_OffsetX(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSignatureWidgetProps::set_OffsetX(int32_t Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_OffsetX(_Handle, Value));
}

SB_INLINE int32_t TElPDFSignatureWidgetProps::get_OffsetY()
{
	int32_t OutResult;
	SBCheckError(TElPDFSignatureWidgetProps_get_OffsetY(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSignatureWidgetProps::set_OffsetY(int32_t Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_OffsetY(_Handle, Value));
}

SB_INLINE double TElPDFSignatureWidgetProps::get_TitleFontSize()
{
	double OutResult;
	SBCheckError(TElPDFSignatureWidgetProps_get_TitleFontSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSignatureWidgetProps::set_TitleFontSize(double Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_TitleFontSize(_Handle, Value));
}

SB_INLINE double TElPDFSignatureWidgetProps::get_TimestampFontSize()
{
	double OutResult;
	SBCheckError(TElPDFSignatureWidgetProps_get_TimestampFontSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSignatureWidgetProps::set_TimestampFontSize(double Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_TimestampFontSize(_Handle, Value));
}

SB_INLINE double TElPDFSignatureWidgetProps::get_SectionTitleFontSize()
{
	double OutResult;
	SBCheckError(TElPDFSignatureWidgetProps_get_SectionTitleFontSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSignatureWidgetProps::set_SectionTitleFontSize(double Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_SectionTitleFontSize(_Handle, Value));
}

SB_INLINE double TElPDFSignatureWidgetProps::get_SectionTextFontSize()
{
	double OutResult;
	SBCheckError(TElPDFSignatureWidgetProps_get_SectionTextFontSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSignatureWidgetProps::set_SectionTextFontSize(double Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_SectionTextFontSize(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELPDFIMAGE
TElPDFImage* TElPDFSignatureWidgetProps::get_Background()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSignatureWidgetProps_get_Background(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Background)
		this->_Inst_Background = new TElPDFImage(hOutResult, ohFalse);
	else
		this->_Inst_Background->updateHandle(hOutResult);
	return this->_Inst_Background;
}
#endif /* SB_USE_CLASS_TELPDFIMAGE */

TSBPDFWidgetBackgroundStyle TElPDFSignatureWidgetProps::get_BackgroundStyle()
{
	TSBPDFWidgetBackgroundStyleRaw OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_BackgroundStyle(_Handle, &OutResultRaw));
	return (TSBPDFWidgetBackgroundStyle)OutResultRaw;
}

SB_INLINE void TElPDFSignatureWidgetProps::set_BackgroundStyle(TSBPDFWidgetBackgroundStyle Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_BackgroundStyle(_Handle, (TSBPDFWidgetBackgroundStyleRaw)Value));
}

SB_INLINE double TElPDFSignatureWidgetProps::get_StretchX()
{
	double OutResult;
	SBCheckError(TElPDFSignatureWidgetProps_get_StretchX(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSignatureWidgetProps::set_StretchX(double Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_StretchX(_Handle, Value));
}

SB_INLINE double TElPDFSignatureWidgetProps::get_StretchY()
{
	double OutResult;
	SBCheckError(TElPDFSignatureWidgetProps_get_StretchY(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSignatureWidgetProps::set_StretchY(double Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_StretchY(_Handle, Value));
}

SB_INLINE int32_t TElPDFSignatureWidgetProps::get_Rotate()
{
	int32_t OutResult;
	SBCheckError(TElPDFSignatureWidgetProps_get_Rotate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSignatureWidgetProps::set_Rotate(int32_t Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_Rotate(_Handle, Value));
}

void TElPDFSignatureWidgetProps::get_SignerCaption(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignatureWidgetProps_get_SignerCaption(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1695642745, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_SignerCaption(const std::string &Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_SignerCaption(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFSignatureWidgetProps::get_AlgorithmCaption(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignatureWidgetProps_get_AlgorithmCaption(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1817782770, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_AlgorithmCaption(const std::string &Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_AlgorithmCaption(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFSignatureWidgetProps::get_DateCaptionFormat(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignatureWidgetProps_get_DateCaptionFormat(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1481499612, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_DateCaptionFormat(const std::string &Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_DateCaptionFormat(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFSignatureWidgetProps::get_CustomAppearance(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFSignatureWidgetProps_get_CustomAppearance(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-644433066, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_CustomAppearance(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_CustomAppearance(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXTLIST
TElPDFSignatureWidgetTextList* TElPDFSignatureWidgetProps::get_CustomText()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSignatureWidgetProps_get_CustomText(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CustomText)
		this->_Inst_CustomText = new TElPDFSignatureWidgetTextList(hOutResult, ohFalse);
	else
		this->_Inst_CustomText->updateHandle(hOutResult);
	return this->_Inst_CustomText;
}
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXTLIST */

bool TElPDFSignatureWidgetProps::get_HideDefaultText()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_HideDefaultText(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_HideDefaultText(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_HideDefaultText(_Handle, (int8_t)Value));
}

bool TElPDFSignatureWidgetProps::get_CompressWidgetData()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_CompressWidgetData(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_CompressWidgetData(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_CompressWidgetData(_Handle, (int8_t)Value));
}

void TElPDFSignatureWidgetProps::get_CustomBackgroundContentStream(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignatureWidgetProps_get_CustomBackgroundContentStream(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-197378615, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_CustomBackgroundContentStream(const std::string &Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_CustomBackgroundContentStream(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElPDFSignatureWidgetProps::get_ShowVisualStatus()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_ShowVisualStatus(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_ShowVisualStatus(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_ShowVisualStatus(_Handle, (int8_t)Value));
}

void TElPDFSignatureWidgetProps::get_CustomVisualStatusMatrix(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignatureWidgetProps_get_CustomVisualStatusMatrix(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(413712805, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_CustomVisualStatusMatrix(const std::string &Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_CustomVisualStatusMatrix(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElPDFSignatureWidgetProps::get_SigningTime()
{
	int64_t OutResult;
	SBCheckError(TElPDFSignatureWidgetProps_get_SigningTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSignatureWidgetProps::set_SigningTime(int64_t Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_SigningTime(_Handle, Value));
}

bool TElPDFSignatureWidgetProps::get_IgnoreExistingAppearance()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_IgnoreExistingAppearance(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_IgnoreExistingAppearance(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_IgnoreExistingAppearance(_Handle, (int8_t)Value));
}

bool TElPDFSignatureWidgetProps::get_ShowOnAllPages()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_ShowOnAllPages(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_ShowOnAllPages(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_ShowOnAllPages(_Handle, (int8_t)Value));
}

bool TElPDFSignatureWidgetProps::get_SaveStringsInUnicodeEncoding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureWidgetProps_get_SaveStringsInUnicodeEncoding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignatureWidgetProps::set_SaveStringsInUnicodeEncoding(bool Value)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_SaveStringsInUnicodeEncoding(_Handle, (int8_t)Value));
}

SB_INLINE void TElPDFSignatureWidgetProps::get_OnConvertStringToAnsi(TSBPDFConvertStringToAnsiEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPDFSignatureWidgetProps_get_OnConvertStringToAnsi(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPDFSignatureWidgetProps::set_OnConvertStringToAnsi(TSBPDFConvertStringToAnsiEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_OnConvertStringToAnsi(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPDFSignatureWidgetProps::get_OnLookupGlyphName(TSBPDFLookupGlyphNameEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPDFSignatureWidgetProps_get_OnLookupGlyphName(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPDFSignatureWidgetProps::set_OnLookupGlyphName(TSBPDFLookupGlyphNameEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_OnLookupGlyphName(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPDFSignatureWidgetProps::get_OnLookupGlyphWidth(TSBPDFLookupGlyphWidthEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPDFSignatureWidgetProps_get_OnLookupGlyphWidth(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPDFSignatureWidgetProps::set_OnLookupGlyphWidth(TSBPDFLookupGlyphWidthEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPDFSignatureWidgetProps_set_OnLookupGlyphWidth(_Handle, pMethodValue, pDataValue));
}

void TElPDFSignatureWidgetProps::initInstances()
{
#ifdef SB_USE_CLASS_TELPDFIMAGE
	this->_Inst_Background = NULL;
#endif /* SB_USE_CLASS_TELPDFIMAGE */
#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXTLIST
	this->_Inst_CustomText = NULL;
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXTLIST */
}

TElPDFSignatureWidgetProps::TElPDFSignatureWidgetProps(TElPDFSignatureWidgetPropsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPDFSignatureWidgetProps::TElPDFSignatureWidgetProps() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFSignatureWidgetProps_Create(&_Handle));
}

TElPDFSignatureWidgetProps::~TElPDFSignatureWidgetProps()
{
#ifdef SB_USE_CLASS_TELPDFIMAGE
	delete this->_Inst_Background;
	this->_Inst_Background = NULL;
#endif /* SB_USE_CLASS_TELPDFIMAGE */
#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXTLIST
	delete this->_Inst_CustomText;
	this->_Inst_CustomText = NULL;
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXTLIST */
}
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETPROPS */

#ifdef SB_USE_CLASS_TELPDFSIGNATURE

bool TElPDFSignature::Validate()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignature_Validate(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPDFSignature::Validate(bool MDPLiberalMode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignature_Validate_1(_Handle, (int8_t)MDPLiberalMode, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPDFSignature::GetSignedVersion(TStream &Stream)
{
	SBCheckError(TElPDFSignature_GetSignedVersion(_Handle, Stream.getHandle()));
}

SB_INLINE void TElPDFSignature::GetSignedVersion(TStream *Stream)
{
	SBCheckError(TElPDFSignature_GetSignedVersion(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElPDFSignature::IsDocumentSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignature_IsDocumentSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignature::Update()
{
	SBCheckError(TElPDFSignature_Update(_Handle));
}

SB_INLINE void TElPDFSignature::Timestamp()
{
	SBCheckError(TElPDFSignature_Timestamp(_Handle));
}

TSBPDFSignatureType TElPDFSignature::get_SignatureType()
{
	TSBPDFSignatureTypeRaw OutResultRaw = 0;
	SBCheckError(TElPDFSignature_get_SignatureType(_Handle, &OutResultRaw));
	return (TSBPDFSignatureType)OutResultRaw;
}

SB_INLINE void TElPDFSignature::set_SignatureType(TSBPDFSignatureType Value)
{
	SBCheckError(TElPDFSignature_set_SignatureType(_Handle, (TSBPDFSignatureTypeRaw)Value));
}

TSBPDFSignatureAllowedChanges TElPDFSignature::get_AllowedChanges()
{
	TSBPDFSignatureAllowedChangesRaw OutResultRaw = 0;
	SBCheckError(TElPDFSignature_get_AllowedChanges(_Handle, &OutResultRaw));
	return (TSBPDFSignatureAllowedChanges)OutResultRaw;
}

SB_INLINE void TElPDFSignature::set_AllowedChanges(TSBPDFSignatureAllowedChanges Value)
{
	SBCheckError(TElPDFSignature_set_AllowedChanges(_Handle, (TSBPDFSignatureAllowedChangesRaw)Value));
}

#ifdef SB_USE_CLASS_TELPDFSECURITYHANDLER
TElPDFSecurityHandler* TElPDFSignature::get_Handler()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSignature_get_Handler(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Handler)
		this->_Inst_Handler = new TElPDFSecurityHandler(hOutResult, ohFalse);
	else
		this->_Inst_Handler->updateHandle(hOutResult);
	return this->_Inst_Handler;
}

SB_INLINE void TElPDFSignature::set_Handler(TElPDFSecurityHandler &Value)
{
	SBCheckError(TElPDFSignature_set_Handler(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFSignature::set_Handler(TElPDFSecurityHandler *Value)
{
	SBCheckError(TElPDFSignature_set_Handler(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPDFSECURITYHANDLER */

void TElPDFSignature::get_SignatureName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignature_get_SignatureName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2007394611, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSignature::set_SignatureName(const std::string &Value)
{
	SBCheckError(TElPDFSignature_set_SignatureName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFSignature::get_AuthorName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignature_get_AuthorName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(778980586, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSignature::set_AuthorName(const std::string &Value)
{
	SBCheckError(TElPDFSignature_set_AuthorName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFSignature::get_ContactInfo(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignature_get_ContactInfo(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-667992697, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSignature::set_ContactInfo(const std::string &Value)
{
	SBCheckError(TElPDFSignature_set_ContactInfo(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFSignature::get_Location(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignature_get_Location(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-504309128, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSignature::set_Location(const std::string &Value)
{
	SBCheckError(TElPDFSignature_set_Location(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFSignature::get_Reason(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignature_get_Reason(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1743702289, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSignature::set_Reason(const std::string &Value)
{
	SBCheckError(TElPDFSignature_set_Reason(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElPDFSignature::get_SigningTime()
{
	int64_t OutResult;
	SBCheckError(TElPDFSignature_get_SigningTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSignature::set_SigningTime(int64_t Value)
{
	SBCheckError(TElPDFSignature_set_SigningTime(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETPROPS
TElPDFSignatureWidgetProps* TElPDFSignature::get_WidgetProps()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSignature_get_WidgetProps(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WidgetProps)
		this->_Inst_WidgetProps = new TElPDFSignatureWidgetProps(hOutResult, ohFalse);
	else
		this->_Inst_WidgetProps->updateHandle(hOutResult);
	return this->_Inst_WidgetProps;
}
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETPROPS */

bool TElPDFSignature::get_Invisible()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignature_get_Invisible(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignature::set_Invisible(bool Value)
{
	SBCheckError(TElPDFSignature_set_Invisible(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElPDFSignature::get_Page()
{
	int32_t OutResult;
	SBCheckError(TElPDFSignature_get_Page(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSignature::set_Page(int32_t Value)
{
	SBCheckError(TElPDFSignature_set_Page(_Handle, Value));
}

bool TElPDFSignature::get_UseHexEncoding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignature_get_UseHexEncoding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignature::set_UseHexEncoding(bool Value)
{
	SBCheckError(TElPDFSignature_set_UseHexEncoding(_Handle, (int8_t)Value));
}

TSBPDFDigestMethod TElPDFSignature::get_MDPHashAlgorithm()
{
	TSBPDFDigestMethodRaw OutResultRaw = 0;
	SBCheckError(TElPDFSignature_get_MDPHashAlgorithm(_Handle, &OutResultRaw));
	return (TSBPDFDigestMethod)OutResultRaw;
}

SB_INLINE void TElPDFSignature::set_MDPHashAlgorithm(TSBPDFDigestMethod Value)
{
	SBCheckError(TElPDFSignature_set_MDPHashAlgorithm(_Handle, (TSBPDFDigestMethodRaw)Value));
}

bool TElPDFSignature::get_DisableDocMDPTransformDigestValue()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignature_get_DisableDocMDPTransformDigestValue(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignature::set_DisableDocMDPTransformDigestValue(bool Value)
{
	SBCheckError(TElPDFSignature_set_DisableDocMDPTransformDigestValue(_Handle, (int8_t)Value));
}

bool TElPDFSignature::get_DisableFieldMDPTransformDigestValue()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignature_get_DisableFieldMDPTransformDigestValue(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignature::set_DisableFieldMDPTransformDigestValue(bool Value)
{
	SBCheckError(TElPDFSignature_set_DisableFieldMDPTransformDigestValue(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElPDFSignature::get_ExtraSpace()
{
	int32_t OutResult;
	SBCheckError(TElPDFSignature_get_ExtraSpace(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFSignature::set_ExtraSpace(int32_t Value)
{
	SBCheckError(TElPDFSignature_set_ExtraSpace(_Handle, Value));
}

bool TElPDFSignature::get_EmptyField()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignature_get_EmptyField(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignature::set_EmptyField(bool Value)
{
	SBCheckError(TElPDFSignature_set_EmptyField(_Handle, (int8_t)Value));
}

bool TElPDFSignature::get_ExplicitElementSignature()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignature_get_ExplicitElementSignature(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFSignature::set_ExplicitElementSignature(bool Value)
{
	SBCheckError(TElPDFSignature_set_ExplicitElementSignature(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELPDFOBJECT
TElPDFObject* TElPDFSignature::get_ExplicitElement()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSignature_get_ExplicitElement(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ExplicitElement)
		this->_Inst_ExplicitElement = new TElPDFObject(hOutResult, ohFalse);
	else
		this->_Inst_ExplicitElement->updateHandle(hOutResult);
	return this->_Inst_ExplicitElement;
}

SB_INLINE void TElPDFSignature::set_ExplicitElement(TElPDFObject &Value)
{
	SBCheckError(TElPDFSignature_set_ExplicitElement(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFSignature::set_ExplicitElement(TElPDFObject *Value)
{
	SBCheckError(TElPDFSignature_set_ExplicitElement(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPDFOBJECT */

void TElPDFSignature::get_CustomData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFSignature_get_CustomData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1858015678, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFSignature::set_CustomData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPDFSignature_set_CustomData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TPDFStringEncoding TElPDFSignature::get_CustomDataEncoding()
{
	TPDFStringEncodingRaw OutResultRaw = 0;
	SBCheckError(TElPDFSignature_get_CustomDataEncoding(_Handle, &OutResultRaw));
	return (TPDFStringEncoding)OutResultRaw;
}

SB_INLINE void TElPDFSignature::set_CustomDataEncoding(TPDFStringEncoding Value)
{
	SBCheckError(TElPDFSignature_set_CustomDataEncoding(_Handle, (TPDFStringEncodingRaw)Value));
}

TSBPDFSignatureOptions TElPDFSignature::get_Options()
{
	TSBPDFSignatureOptionsRaw OutResultRaw = 0;
	SBCheckError(TElPDFSignature_get_Options(_Handle, &OutResultRaw));
	return (TSBPDFSignatureOptions)OutResultRaw;
}

SB_INLINE void TElPDFSignature::set_Options(TSBPDFSignatureOptions Value)
{
	SBCheckError(TElPDFSignature_set_Options(_Handle, (TSBPDFSignatureOptionsRaw)Value));
}

#ifdef SB_USE_CLASS_TELPDFOBJECT
TElPDFObject* TElPDFSignature::get_PDFObject()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSignature_get_PDFObject(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PDFObject)
		this->_Inst_PDFObject = new TElPDFObject(hOutResult, ohFalse);
	else
		this->_Inst_PDFObject->updateHandle(hOutResult);
	return this->_Inst_PDFObject;
}
#endif /* SB_USE_CLASS_TELPDFOBJECT */

TSBPDFFieldMDPAction TElPDFSignature::get_LockAction()
{
	TSBPDFFieldMDPActionRaw OutResultRaw = 0;
	SBCheckError(TElPDFSignature_get_LockAction(_Handle, &OutResultRaw));
	return (TSBPDFFieldMDPAction)OutResultRaw;
}

SB_INLINE void TElPDFSignature::set_LockAction(TSBPDFFieldMDPAction Value)
{
	SBCheckError(TElPDFSignature_set_LockAction(_Handle, (TSBPDFFieldMDPActionRaw)Value));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPDFSignature::get_LockFields()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSignature_get_LockFields(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_LockFields)
		this->_Inst_LockFields = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_LockFields->updateHandle(hOutResult);
	return this->_Inst_LockFields;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElPDFSignature::get_LockFields()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSignature_get_LockFields(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_LockFields)
		this->_Inst_LockFields = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_LockFields->updateHandle(hOutResult);
	return this->_Inst_LockFields;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElPDFSignature::initInstances()
{
#ifdef SB_USE_CLASS_TELPDFSECURITYHANDLER
	this->_Inst_Handler = NULL;
#endif /* SB_USE_CLASS_TELPDFSECURITYHANDLER */
#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETPROPS
	this->_Inst_WidgetProps = NULL;
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETPROPS */
#ifdef SB_USE_CLASS_TELPDFOBJECT
	this->_Inst_ExplicitElement = NULL;
#endif /* SB_USE_CLASS_TELPDFOBJECT */
#ifdef SB_USE_CLASS_TELPDFOBJECT
	this->_Inst_PDFObject = NULL;
#endif /* SB_USE_CLASS_TELPDFOBJECT */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_LockFields = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_LockFields = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElPDFSignature::TElPDFSignature(TElPDFSignatureHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELPDFDOCUMENT
TElPDFSignature::TElPDFSignature(TElPDFDocument &Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFSignature_Create(Owner.getHandle(), &_Handle));
}

TElPDFSignature::TElPDFSignature(TElPDFDocument *Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFSignature_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPDFDOCUMENT */

TElPDFSignature::~TElPDFSignature()
{
#ifdef SB_USE_CLASS_TELPDFSECURITYHANDLER
	delete this->_Inst_Handler;
	this->_Inst_Handler = NULL;
#endif /* SB_USE_CLASS_TELPDFSECURITYHANDLER */
#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETPROPS
	delete this->_Inst_WidgetProps;
	this->_Inst_WidgetProps = NULL;
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETPROPS */
#ifdef SB_USE_CLASS_TELPDFOBJECT
	delete this->_Inst_ExplicitElement;
	this->_Inst_ExplicitElement = NULL;
#endif /* SB_USE_CLASS_TELPDFOBJECT */
#ifdef SB_USE_CLASS_TELPDFOBJECT
	delete this->_Inst_PDFObject;
	this->_Inst_PDFObject = NULL;
#endif /* SB_USE_CLASS_TELPDFOBJECT */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_LockFields;
	this->_Inst_LockFields = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_LockFields;
	this->_Inst_LockFields = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELPDFSIGNATURE */

#ifdef SB_USE_CLASS_TELPDFSIGNATUREINFO

void TElPDFSignatureInfo::get_FieldName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignatureInfo_get_FieldName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-999789477, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBPDFFieldFlags TElPDFSignatureInfo::get_FieldFlags()
{
	TSBPDFFieldFlagsRaw OutResultRaw = 0;
	SBCheckError(TElPDFSignatureInfo_get_FieldFlags(_Handle, &OutResultRaw));
	return (TSBPDFFieldFlags)OutResultRaw;
}

void TElPDFSignatureInfo::get_MappingName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignatureInfo_get_MappingName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1371549705, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPDFSignatureInfo::get_AlternateName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignatureInfo_get_AlternateName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-948889422, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBSVDConstraints TElPDFSignatureInfo::get_RequiredConstraints()
{
	TSBSVDConstraintsRaw OutResultRaw = 0;
	SBCheckError(TElPDFSignatureInfo_get_RequiredConstraints(_Handle, &OutResultRaw));
	return (TSBSVDConstraints)OutResultRaw;
}

void TElPDFSignatureInfo::get_RequiredFilter(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignatureInfo_get_RequiredFilter(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1440386764, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPDFSignatureInfo::get_RequiredSubfilters()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSignatureInfo_get_RequiredSubfilters(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RequiredSubfilters)
		this->_Inst_RequiredSubfilters = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_RequiredSubfilters->updateHandle(hOutResult);
	return this->_Inst_RequiredSubfilters;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElPDFSignatureInfo::get_RequiredSubfilters()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSignatureInfo_get_RequiredSubfilters(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RequiredSubfilters)
		this->_Inst_RequiredSubfilters = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_RequiredSubfilters->updateHandle(hOutResult);
	return this->_Inst_RequiredSubfilters;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElPDFSignatureInfo::get_RequiredDigestAlgorithms(std::vector<int32_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size() * 4;
	uint32_t _err = TElPDFSignatureInfo_get_RequiredDigestAlgorithms(_Handle, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult / 4);
		SBCheckError(SBGetLastReturnBuffer(-2058563343, 1, (int32_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult / 4);
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPDFSignatureInfo::get_RequiredReasons()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSignatureInfo_get_RequiredReasons(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RequiredReasons)
		this->_Inst_RequiredReasons = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_RequiredReasons->updateHandle(hOutResult);
	return this->_Inst_RequiredReasons;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElPDFSignatureInfo::get_RequiredReasons()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSignatureInfo_get_RequiredReasons(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RequiredReasons)
		this->_Inst_RequiredReasons = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_RequiredReasons->updateHandle(hOutResult);
	return this->_Inst_RequiredReasons;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

TSBPDFFieldMDPAction TElPDFSignatureInfo::get_RequiredLockAction()
{
	TSBPDFFieldMDPActionRaw OutResultRaw = 0;
	SBCheckError(TElPDFSignatureInfo_get_RequiredLockAction(_Handle, &OutResultRaw));
	return (TSBPDFFieldMDPAction)OutResultRaw;
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPDFSignatureInfo::get_RequiredLockFields()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSignatureInfo_get_RequiredLockFields(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RequiredLockFields)
		this->_Inst_RequiredLockFields = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_RequiredLockFields->updateHandle(hOutResult);
	return this->_Inst_RequiredLockFields;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElPDFSignatureInfo::get_RequiredLockFields()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSignatureInfo_get_RequiredLockFields(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RequiredLockFields)
		this->_Inst_RequiredLockFields = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_RequiredLockFields->updateHandle(hOutResult);
	return this->_Inst_RequiredLockFields;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

TSBPDFSignatureAllowedChanges TElPDFSignatureInfo::get_RequiredAllowedChanges()
{
	TSBPDFSignatureAllowedChangesRaw OutResultRaw = 0;
	SBCheckError(TElPDFSignatureInfo_get_RequiredAllowedChanges(_Handle, &OutResultRaw));
	return (TSBPDFSignatureAllowedChanges)OutResultRaw;
}

void TElPDFSignatureInfo::get_TSPURL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFSignatureInfo_get_TSPURL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1048106252, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElPDFSignatureInfo::get_TimestampRequired()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureInfo_get_TimestampRequired(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPDFSignatureInfo::get_LegalAttestations()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSignatureInfo_get_LegalAttestations(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_LegalAttestations)
		this->_Inst_LegalAttestations = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_LegalAttestations->updateHandle(hOutResult);
	return this->_Inst_LegalAttestations;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElPDFSignatureInfo::get_LegalAttestations()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFSignatureInfo_get_LegalAttestations(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_LegalAttestations)
		this->_Inst_LegalAttestations = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_LegalAttestations->updateHandle(hOutResult);
	return this->_Inst_LegalAttestations;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

bool TElPDFSignatureInfo::get_AddRevInfo()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureInfo_get_AddRevInfo(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElPDFSignatureInfo::get_Height()
{
	int32_t OutResult;
	SBCheckError(TElPDFSignatureInfo_get_Height(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFSignatureInfo::get_Width()
{
	int32_t OutResult;
	SBCheckError(TElPDFSignatureInfo_get_Width(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFSignatureInfo::get_OffsetX()
{
	int32_t OutResult;
	SBCheckError(TElPDFSignatureInfo_get_OffsetX(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFSignatureInfo::get_OffsetY()
{
	int32_t OutResult;
	SBCheckError(TElPDFSignatureInfo_get_OffsetY(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFSignatureInfo::get_Page()
{
	int32_t OutResult;
	SBCheckError(TElPDFSignatureInfo_get_Page(_Handle, &OutResult));
	return OutResult;
}

bool TElPDFSignatureInfo::get_Invisible()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFSignatureInfo_get_Invisible(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPDFSignatureInfo::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_RequiredSubfilters = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_RequiredSubfilters = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_RequiredReasons = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_RequiredReasons = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_RequiredLockFields = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_RequiredLockFields = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_LegalAttestations = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_LegalAttestations = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElPDFSignatureInfo::TElPDFSignatureInfo(TElPDFSignatureInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPDFSignatureInfo::TElPDFSignatureInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFSignatureInfo_Create(&_Handle));
}

TElPDFSignatureInfo::~TElPDFSignatureInfo()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_RequiredSubfilters;
	this->_Inst_RequiredSubfilters = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_RequiredSubfilters;
	this->_Inst_RequiredSubfilters = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_RequiredReasons;
	this->_Inst_RequiredReasons = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_RequiredReasons;
	this->_Inst_RequiredReasons = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_RequiredLockFields;
	this->_Inst_RequiredLockFields = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_RequiredLockFields;
	this->_Inst_RequiredLockFields = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_LegalAttestations;
	this->_Inst_LegalAttestations = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_LegalAttestations;
	this->_Inst_LegalAttestations = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELPDFSIGNATUREINFO */

#ifdef SB_USE_CLASS_TELPDFENCODINGHANDLER

void TElPDFEncodingHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFEncodingHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(540965987, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPDFEncodingHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFEncodingHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(540965987, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPDFEncodingHandler::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFEncodingHandler_GetDescription((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2063230971, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPDFEncodingHandler::GetDescription_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFEncodingHandler_GetDescription_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2063230971, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TElPDFEncodingHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPDFEncodingHandler_ClassType(&OutResult));
	return OutResult;
}

TElPDFEncodingHandler::TElPDFEncodingHandler(TElPDFEncodingHandlerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPDFEncodingHandler::TElPDFEncodingHandler() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFEncodingHandler_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPDFENCODINGHANDLER */

#ifdef SB_USE_CLASS_TELPDFREQUIREMENTHANDLER

void TElPDFRequirementHandler::get_HandlerType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFRequirementHandler_get_HandlerType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1112122929, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPDFRequirementHandler::get_ScriptName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFRequirementHandler_get_ScriptName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1291885185, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElPDFRequirementHandler::TElPDFRequirementHandler(TElPDFRequirementHandlerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPDFRequirementHandler::TElPDFRequirementHandler() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFRequirementHandler_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPDFREQUIREMENTHANDLER */

#ifdef SB_USE_CLASS_TELPDFREQUIREMENT

void TElPDFRequirement::get_RequirementType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFRequirement_get_RequirementType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2136318487, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElPDFRequirement::get_HandlerCount()
{
	int32_t OutResult;
	SBCheckError(TElPDFRequirement_get_HandlerCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPDFREQUIREMENTHANDLER
TElPDFRequirementHandler* TElPDFRequirement::get_Handlers(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFRequirement_get_Handlers(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Handlers)
		this->_Inst_Handlers = new TElPDFRequirementHandler(hOutResult, ohFalse);
	else
		this->_Inst_Handlers->updateHandle(hOutResult);
	return this->_Inst_Handlers;
}
#endif /* SB_USE_CLASS_TELPDFREQUIREMENTHANDLER */

void TElPDFRequirement::initInstances()
{
#ifdef SB_USE_CLASS_TELPDFREQUIREMENTHANDLER
	this->_Inst_Handlers = NULL;
#endif /* SB_USE_CLASS_TELPDFREQUIREMENTHANDLER */
}

TElPDFRequirement::TElPDFRequirement(TElPDFRequirementHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPDFRequirement::TElPDFRequirement() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFRequirement_Create(&_Handle));
}

TElPDFRequirement::~TElPDFRequirement()
{
#ifdef SB_USE_CLASS_TELPDFREQUIREMENTHANDLER
	delete this->_Inst_Handlers;
	this->_Inst_Handlers = NULL;
#endif /* SB_USE_CLASS_TELPDFREQUIREMENTHANDLER */
}
#endif /* SB_USE_CLASS_TELPDFREQUIREMENT */

#ifdef SB_USE_CLASS_TELPDFPAGEINFO

bool TElPDFPageInfo::CropBoxEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFPageInfo_CropBoxEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElPDFPageInfo::get_Width()
{
	int32_t OutResult;
	SBCheckError(TElPDFPageInfo_get_Width(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFPageInfo::get_Height()
{
	int32_t OutResult;
	SBCheckError(TElPDFPageInfo_get_Height(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFPageInfo::get_Rotate()
{
	int32_t OutResult;
	SBCheckError(TElPDFPageInfo_get_Rotate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE double TElPDFPageInfo::get_CropLLX()
{
	double OutResult;
	SBCheckError(TElPDFPageInfo_get_CropLLX(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE double TElPDFPageInfo::get_CropLLY()
{
	double OutResult;
	SBCheckError(TElPDFPageInfo_get_CropLLY(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE double TElPDFPageInfo::get_CropURX()
{
	double OutResult;
	SBCheckError(TElPDFPageInfo_get_CropURX(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE double TElPDFPageInfo::get_CropURY()
{
	double OutResult;
	SBCheckError(TElPDFPageInfo_get_CropURY(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE double TElPDFPageInfo::get_MediaLLX()
{
	double OutResult;
	SBCheckError(TElPDFPageInfo_get_MediaLLX(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE double TElPDFPageInfo::get_MediaLLY()
{
	double OutResult;
	SBCheckError(TElPDFPageInfo_get_MediaLLY(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE double TElPDFPageInfo::get_MediaURX()
{
	double OutResult;
	SBCheckError(TElPDFPageInfo_get_MediaURX(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE double TElPDFPageInfo::get_MediaURY()
{
	double OutResult;
	SBCheckError(TElPDFPageInfo_get_MediaURY(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
TElPDFDictionary* TElPDFPageInfo::get_PageObject()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFPageInfo_get_PageObject(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PageObject)
		this->_Inst_PageObject = new TElPDFDictionary(hOutResult, ohFalse);
	else
		this->_Inst_PageObject->updateHandle(hOutResult);
	return this->_Inst_PageObject;
}
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

void TElPDFPageInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELPDFDICTIONARY
	this->_Inst_PageObject = NULL;
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */
}

TElPDFPageInfo::TElPDFPageInfo(TElPDFPageInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPDFPageInfo::TElPDFPageInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFPageInfo_Create(&_Handle));
}

TElPDFPageInfo::~TElPDFPageInfo()
{
#ifdef SB_USE_CLASS_TELPDFDICTIONARY
	delete this->_Inst_PageObject;
	this->_Inst_PageObject = NULL;
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */
}
#endif /* SB_USE_CLASS_TELPDFPAGEINFO */

#ifdef SB_USE_CLASS_TELPDFFILEATTACHMENT

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPDFFileAttachment::Init(TStream &Stream)
{
	SBCheckError(TElPDFFileAttachment_Init(_Handle, Stream.getHandle()));
}

SB_INLINE void TElPDFFileAttachment::Init(TStream *Stream)
{
	SBCheckError(TElPDFFileAttachment_Init(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPDFFileAttachment::Save(TStream &Stream)
{
	SBCheckError(TElPDFFileAttachment_Save(_Handle, Stream.getHandle()));
}

SB_INLINE void TElPDFFileAttachment::Save(TStream *Stream)
{
	SBCheckError(TElPDFFileAttachment_Save(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElPDFFileAttachment::get_ObjectName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFFileAttachment_get_ObjectName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1007273765, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFFileAttachment::set_ObjectName(const std::string &Value)
{
	SBCheckError(TElPDFFileAttachment_set_ObjectName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFFileAttachment::get_Filename(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFFileAttachment_get_Filename(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1190608879, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFFileAttachment::set_Filename(const std::string &Value)
{
	SBCheckError(TElPDFFileAttachment_set_Filename(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFFileAttachment::get_UnicodeFilename(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFFileAttachment_get_UnicodeFilename(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-425671165, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFFileAttachment::set_UnicodeFilename(const std::string &Value)
{
	SBCheckError(TElPDFFileAttachment_set_UnicodeFilename(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFFileAttachment::get_Description(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFFileAttachment_get_Description(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(470980460, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFFileAttachment::set_Description(const std::string &Value)
{
	SBCheckError(TElPDFFileAttachment_set_Description(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFFileAttachment::get_SubType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFFileAttachment_get_SubType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1674946840, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFFileAttachment::set_SubType(const std::string &Value)
{
	SBCheckError(TElPDFFileAttachment_set_SubType(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElPDFFileAttachment::get_Size()
{
	int64_t OutResult;
	SBCheckError(TElPDFFileAttachment_get_Size(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElPDFFileAttachment::get_CreationDate()
{
	int64_t OutResult;
	SBCheckError(TElPDFFileAttachment_get_CreationDate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFFileAttachment::set_CreationDate(int64_t Value)
{
	SBCheckError(TElPDFFileAttachment_set_CreationDate(_Handle, Value));
}

SB_INLINE int64_t TElPDFFileAttachment::get_ModificationDate()
{
	int64_t OutResult;
	SBCheckError(TElPDFFileAttachment_get_ModificationDate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFFileAttachment::set_ModificationDate(int64_t Value)
{
	SBCheckError(TElPDFFileAttachment_set_ModificationDate(_Handle, Value));
}

void TElPDFFileAttachment::get_MD5Checksum(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFFileAttachment_get_MD5Checksum(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(821951867, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElPDFFileAttachment::TElPDFFileAttachment(TElPDFFileAttachmentHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPDFFileAttachment::TElPDFFileAttachment() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFFileAttachment_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPDFFILEATTACHMENT */

#ifdef SB_USE_CLASS_TELPDFLEGALCONTENTATTESTATION

SB_INLINE int32_t TElPDFLegalContentAttestation::get_JavascriptActions()
{
	int32_t OutResult;
	SBCheckError(TElPDFLegalContentAttestation_get_JavascriptActions(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFLegalContentAttestation::set_JavascriptActions(int32_t Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_JavascriptActions(_Handle, Value));
}

SB_INLINE int32_t TElPDFLegalContentAttestation::get_LaunchActions()
{
	int32_t OutResult;
	SBCheckError(TElPDFLegalContentAttestation_get_LaunchActions(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFLegalContentAttestation::set_LaunchActions(int32_t Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_LaunchActions(_Handle, Value));
}

SB_INLINE int32_t TElPDFLegalContentAttestation::get_URIActions()
{
	int32_t OutResult;
	SBCheckError(TElPDFLegalContentAttestation_get_URIActions(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFLegalContentAttestation::set_URIActions(int32_t Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_URIActions(_Handle, Value));
}

SB_INLINE int32_t TElPDFLegalContentAttestation::get_MovieActions()
{
	int32_t OutResult;
	SBCheckError(TElPDFLegalContentAttestation_get_MovieActions(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFLegalContentAttestation::set_MovieActions(int32_t Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_MovieActions(_Handle, Value));
}

SB_INLINE int32_t TElPDFLegalContentAttestation::get_SoundActions()
{
	int32_t OutResult;
	SBCheckError(TElPDFLegalContentAttestation_get_SoundActions(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFLegalContentAttestation::set_SoundActions(int32_t Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_SoundActions(_Handle, Value));
}

SB_INLINE int32_t TElPDFLegalContentAttestation::get_HideAnnotationActions()
{
	int32_t OutResult;
	SBCheckError(TElPDFLegalContentAttestation_get_HideAnnotationActions(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFLegalContentAttestation::set_HideAnnotationActions(int32_t Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_HideAnnotationActions(_Handle, Value));
}

SB_INLINE int32_t TElPDFLegalContentAttestation::get_GoToRemoteActions()
{
	int32_t OutResult;
	SBCheckError(TElPDFLegalContentAttestation_get_GoToRemoteActions(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFLegalContentAttestation::set_GoToRemoteActions(int32_t Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_GoToRemoteActions(_Handle, Value));
}

SB_INLINE int32_t TElPDFLegalContentAttestation::get_AlternateImages()
{
	int32_t OutResult;
	SBCheckError(TElPDFLegalContentAttestation_get_AlternateImages(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFLegalContentAttestation::set_AlternateImages(int32_t Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_AlternateImages(_Handle, Value));
}

SB_INLINE int32_t TElPDFLegalContentAttestation::get_ExternalStreams()
{
	int32_t OutResult;
	SBCheckError(TElPDFLegalContentAttestation_get_ExternalStreams(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFLegalContentAttestation::set_ExternalStreams(int32_t Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_ExternalStreams(_Handle, Value));
}

SB_INLINE int32_t TElPDFLegalContentAttestation::get_TrueTypeFonts()
{
	int32_t OutResult;
	SBCheckError(TElPDFLegalContentAttestation_get_TrueTypeFonts(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFLegalContentAttestation::set_TrueTypeFonts(int32_t Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_TrueTypeFonts(_Handle, Value));
}

SB_INLINE int32_t TElPDFLegalContentAttestation::get_ExternalRefXObjects()
{
	int32_t OutResult;
	SBCheckError(TElPDFLegalContentAttestation_get_ExternalRefXObjects(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFLegalContentAttestation::set_ExternalRefXObjects(int32_t Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_ExternalRefXObjects(_Handle, Value));
}

SB_INLINE int32_t TElPDFLegalContentAttestation::get_ExternalOPIDicts()
{
	int32_t OutResult;
	SBCheckError(TElPDFLegalContentAttestation_get_ExternalOPIDicts(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFLegalContentAttestation::set_ExternalOPIDicts(int32_t Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_ExternalOPIDicts(_Handle, Value));
}

SB_INLINE int32_t TElPDFLegalContentAttestation::get_NonEmbeddedFonts()
{
	int32_t OutResult;
	SBCheckError(TElPDFLegalContentAttestation_get_NonEmbeddedFonts(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFLegalContentAttestation::set_NonEmbeddedFonts(int32_t Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_NonEmbeddedFonts(_Handle, Value));
}

SB_INLINE int32_t TElPDFLegalContentAttestation::get_DevDepGSOP()
{
	int32_t OutResult;
	SBCheckError(TElPDFLegalContentAttestation_get_DevDepGSOP(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFLegalContentAttestation::set_DevDepGSOP(int32_t Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_DevDepGSOP(_Handle, Value));
}

SB_INLINE int32_t TElPDFLegalContentAttestation::get_DevDepGSHT()
{
	int32_t OutResult;
	SBCheckError(TElPDFLegalContentAttestation_get_DevDepGSHT(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFLegalContentAttestation::set_DevDepGSHT(int32_t Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_DevDepGSHT(_Handle, Value));
}

SB_INLINE int32_t TElPDFLegalContentAttestation::get_DevDepGSTR()
{
	int32_t OutResult;
	SBCheckError(TElPDFLegalContentAttestation_get_DevDepGSTR(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFLegalContentAttestation::set_DevDepGSTR(int32_t Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_DevDepGSTR(_Handle, Value));
}

SB_INLINE int32_t TElPDFLegalContentAttestation::get_DevDepGSUCR()
{
	int32_t OutResult;
	SBCheckError(TElPDFLegalContentAttestation_get_DevDepGSUCR(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFLegalContentAttestation::set_DevDepGSUCR(int32_t Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_DevDepGSUCR(_Handle, Value));
}

SB_INLINE int32_t TElPDFLegalContentAttestation::get_DevDepGSBG()
{
	int32_t OutResult;
	SBCheckError(TElPDFLegalContentAttestation_get_DevDepGSBG(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFLegalContentAttestation::set_DevDepGSBG(int32_t Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_DevDepGSBG(_Handle, Value));
}

SB_INLINE int32_t TElPDFLegalContentAttestation::get_DevDepGSFL()
{
	int32_t OutResult;
	SBCheckError(TElPDFLegalContentAttestation_get_DevDepGSFL(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFLegalContentAttestation::set_DevDepGSFL(int32_t Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_DevDepGSFL(_Handle, Value));
}

SB_INLINE int32_t TElPDFLegalContentAttestation::get_Annotations()
{
	int32_t OutResult;
	SBCheckError(TElPDFLegalContentAttestation_get_Annotations(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFLegalContentAttestation::set_Annotations(int32_t Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_Annotations(_Handle, Value));
}

bool TElPDFLegalContentAttestation::get_OptionalContent()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFLegalContentAttestation_get_OptionalContent(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFLegalContentAttestation::set_OptionalContent(bool Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_OptionalContent(_Handle, (int8_t)Value));
}

void TElPDFLegalContentAttestation::get_Attestation(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFLegalContentAttestation_get_Attestation(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-859175818, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFLegalContentAttestation::set_Attestation(const std::string &Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_Attestation(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElPDFLegalContentAttestation::get_Include()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFLegalContentAttestation_get_Include(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFLegalContentAttestation::set_Include(bool Value)
{
	SBCheckError(TElPDFLegalContentAttestation_set_Include(_Handle, (int8_t)Value));
}

TElPDFLegalContentAttestation::TElPDFLegalContentAttestation(TElPDFLegalContentAttestationHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPDFLegalContentAttestation::TElPDFLegalContentAttestation() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFLegalContentAttestation_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPDFLEGALCONTENTATTESTATION */

#ifdef SB_USE_GLOBAL_PROCS_PDF

void GetPDFStandardType1FontName(TSBPDFStandardType1Font Font, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBPDF_GetPDFStandardType1FontName((TSBPDFStandardType1FontRaw)Font, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(482896354, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#endif /* SB_USE_GLOBAL_PROCS_PDF */

};	/* namespace SecureBlackbox */
