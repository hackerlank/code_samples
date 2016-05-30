#include "sbascommon.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELASRECEIPTREQUEST

SB_INLINE void TElASReceiptRequest::Assign(TPersistent &Source)
{
	SBCheckError(TElASReceiptRequest_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElASReceiptRequest::Assign(TPersistent *Source)
{
	SBCheckError(TElASReceiptRequest_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElASReceiptRequest::GetDigestAlgorithmPriority(TSBASSignatureDigestAlgorithm Algorithm)
{
	int32_t OutResult;
	SBCheckError(TElASReceiptRequest_GetDigestAlgorithmPriority(_Handle, (TSBASSignatureDigestAlgorithmRaw)Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE void TElASReceiptRequest::SetDigestAlgorithmPriority(TSBASSignatureDigestAlgorithm Algorithm, int32_t Priority)
{
	SBCheckError(TElASReceiptRequest_SetDigestAlgorithmPriority(_Handle, (TSBASSignatureDigestAlgorithmRaw)Algorithm, Priority));
}

TElASReceiptRequest::TElASReceiptRequest(TElASReceiptRequestHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElASReceiptRequest::TElASReceiptRequest() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASReceiptRequest_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELASRECEIPTREQUEST */

#ifdef SB_USE_CLASS_TELASMESSAGEDECRYPTOR

TElASMessageDecryptor::TElASMessageDecryptor(TElASMessageDecryptorHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElASMessageDecryptor::TElASMessageDecryptor() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASMessageDecryptor_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELASMESSAGEDECRYPTOR */

#ifdef SB_USE_CLASS_TELASMESSAGEENCRYPTOR

TElASMessageEncryptor::TElASMessageEncryptor(TElASMessageEncryptorHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElASMessageEncryptor::TElASMessageEncryptor() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASMessageEncryptor_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELASMESSAGEENCRYPTOR */

#ifdef SB_USE_CLASS_TELASENCRYPTION

SB_INLINE void TElASEncryption::Assign(TPersistent &Source)
{
	SBCheckError(TElASEncryption_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElASEncryption::Assign(TPersistent *Source)
{
	SBCheckError(TElASEncryption_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElASEncryption::Clear()
{
	SBCheckError(TElASEncryption_Clear(_Handle));
}

TElASEncryption::TElASEncryption(TElASEncryptionHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TCOMPONENT
TElASEncryption::TElASEncryption(TComponent &AOwner) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASEncryption_Create(AOwner.getHandle(), &_Handle));
}

TElASEncryption::TElASEncryption(TComponent *AOwner) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASEncryption_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TCOMPONENT */

#endif /* SB_USE_CLASS_TELASENCRYPTION */

#ifdef SB_USE_CLASS_TELASSMIMEMESSAGEDECRYPTOR

#ifdef SB_USE_CLASS_TELMESSAGEDECRYPTOR
TElMessageDecryptor* TElASSMIMEMessageDecryptor::get_Decryptor()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElASSMIMEMessageDecryptor_get_Decryptor(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Decryptor)
		this->_Inst_Decryptor = new TElMessageDecryptor(hOutResult, ohFalse);
	else
		this->_Inst_Decryptor->updateHandle(hOutResult);
	return this->_Inst_Decryptor;
}
#endif /* SB_USE_CLASS_TELMESSAGEDECRYPTOR */

void TElASSMIMEMessageDecryptor::initInstances()
{
#ifdef SB_USE_CLASS_TELMESSAGEDECRYPTOR
	this->_Inst_Decryptor = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEDECRYPTOR */
}

TElASSMIMEMessageDecryptor::TElASSMIMEMessageDecryptor(TElASSMIMEMessageDecryptorHandle handle, TElOwnHandle ownHandle) : TElASMessageDecryptor(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELMESSAGEDECRYPTOR
TElASSMIMEMessageDecryptor::TElASSMIMEMessageDecryptor(TElMessageDecryptor &ADecryptor) : TElASMessageDecryptor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElASSMIMEMessageDecryptor_Create(ADecryptor.getHandle(), &_Handle));
}

TElASSMIMEMessageDecryptor::TElASSMIMEMessageDecryptor(TElMessageDecryptor *ADecryptor) : TElASMessageDecryptor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElASSMIMEMessageDecryptor_Create((ADecryptor != NULL) ? ADecryptor->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELMESSAGEDECRYPTOR */

TElASSMIMEMessageDecryptor::~TElASSMIMEMessageDecryptor()
{
#ifdef SB_USE_CLASS_TELMESSAGEDECRYPTOR
	delete this->_Inst_Decryptor;
	this->_Inst_Decryptor = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEDECRYPTOR */
}
#endif /* SB_USE_CLASS_TELASSMIMEMESSAGEDECRYPTOR */

#ifdef SB_USE_CLASS_TELASSMIMEMESSAGEENCRYPTOR

#ifdef SB_USE_CLASS_TELMESSAGEENCRYPTOR
TElMessageEncryptor* TElASSMIMEMessageEncryptor::get_Encryptor()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElASSMIMEMessageEncryptor_get_Encryptor(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Encryptor)
		this->_Inst_Encryptor = new TElMessageEncryptor(hOutResult, ohFalse);
	else
		this->_Inst_Encryptor->updateHandle(hOutResult);
	return this->_Inst_Encryptor;
}
#endif /* SB_USE_CLASS_TELMESSAGEENCRYPTOR */

void TElASSMIMEMessageEncryptor::initInstances()
{
#ifdef SB_USE_CLASS_TELMESSAGEENCRYPTOR
	this->_Inst_Encryptor = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEENCRYPTOR */
}

TElASSMIMEMessageEncryptor::TElASSMIMEMessageEncryptor(TElASSMIMEMessageEncryptorHandle handle, TElOwnHandle ownHandle) : TElASMessageEncryptor(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELMESSAGEENCRYPTOR
TElASSMIMEMessageEncryptor::TElASSMIMEMessageEncryptor(TElMessageEncryptor &AEncryptor) : TElASMessageEncryptor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElASSMIMEMessageEncryptor_Create(AEncryptor.getHandle(), &_Handle));
}

TElASSMIMEMessageEncryptor::TElASSMIMEMessageEncryptor(TElMessageEncryptor *AEncryptor) : TElASMessageEncryptor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElASSMIMEMessageEncryptor_Create((AEncryptor != NULL) ? AEncryptor->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELMESSAGEENCRYPTOR */

TElASSMIMEMessageEncryptor::~TElASSMIMEMessageEncryptor()
{
#ifdef SB_USE_CLASS_TELMESSAGEENCRYPTOR
	delete this->_Inst_Encryptor;
	this->_Inst_Encryptor = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEENCRYPTOR */
}
#endif /* SB_USE_CLASS_TELASSMIMEMESSAGEENCRYPTOR */

#ifdef SB_USE_CLASS_TELASSMIMEENCRYPTION

SB_INLINE void TElASSMIMEEncryption::Assign(TPersistent &Source)
{
	SBCheckError(TElASSMIMEEncryption_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElASSMIMEEncryption::Assign(TPersistent *Source)
{
	SBCheckError(TElASSMIMEEncryption_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

TElASSMIMEEncryption::TElASSMIMEEncryption(TElASSMIMEEncryptionHandle handle, TElOwnHandle ownHandle) : TElASEncryption(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TCOMPONENT
TElASSMIMEEncryption::TElASSMIMEEncryption(TComponent &AOwner) : TElASEncryption(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASSMIMEEncryption_Create(AOwner.getHandle(), &_Handle));
}

TElASSMIMEEncryption::TElASSMIMEEncryption(TComponent *AOwner) : TElASEncryption(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASSMIMEEncryption_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TCOMPONENT */

#endif /* SB_USE_CLASS_TELASSMIMEENCRYPTION */

#ifdef SB_USE_CLASS_TELASMESSAGESIGNER

TElASMessageSigner::TElASMessageSigner(TElASMessageSignerHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElASMessageSigner::TElASMessageSigner() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASMessageSigner_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELASMESSAGESIGNER */

#ifdef SB_USE_CLASS_TELASMESSAGEVERIFIER

SB_INLINE int32_t TElASMessageVerifier::get_Result()
{
	int32_t OutResult;
	SBCheckError(TElASMessageVerifier_get_Result(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElASMessageVerifier::set_Result(int32_t Value)
{
	SBCheckError(TElASMessageVerifier_set_Result(_Handle, Value));
}

TElASMessageVerifier::TElASMessageVerifier(TElASMessageVerifierHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElASMessageVerifier::TElASMessageVerifier() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASMessageVerifier_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELASMESSAGEVERIFIER */

#ifdef SB_USE_CLASS_TELASSIGNATURE

SB_INLINE void TElASSignature::Assign(TPersistent &Source)
{
	SBCheckError(TElASSignature_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElASSignature::Assign(TPersistent *Source)
{
	SBCheckError(TElASSignature_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElASSignature::Clear()
{
	SBCheckError(TElASSignature_Clear(_Handle));
}

TElASSignature::TElASSignature(TElASSignatureHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TCOMPONENT
TElASSignature::TElASSignature(TComponent &AOwner) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASSignature_Create(AOwner.getHandle(), &_Handle));
}

TElASSignature::TElASSignature(TComponent *AOwner) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASSignature_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TCOMPONENT */

#endif /* SB_USE_CLASS_TELASSIGNATURE */

#ifdef SB_USE_CLASS_TELASSMIMEMESSAGESIGNER

#ifdef SB_USE_CLASS_TELMESSAGESIGNER
TElMessageSigner* TElASSMIMEMessageSigner::get_Signer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElASSMIMEMessageSigner_get_Signer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signer)
		this->_Inst_Signer = new TElMessageSigner(hOutResult, ohFalse);
	else
		this->_Inst_Signer->updateHandle(hOutResult);
	return this->_Inst_Signer;
}
#endif /* SB_USE_CLASS_TELMESSAGESIGNER */

void TElASSMIMEMessageSigner::initInstances()
{
#ifdef SB_USE_CLASS_TELMESSAGESIGNER
	this->_Inst_Signer = NULL;
#endif /* SB_USE_CLASS_TELMESSAGESIGNER */
}

TElASSMIMEMessageSigner::TElASSMIMEMessageSigner(TElASSMIMEMessageSignerHandle handle, TElOwnHandle ownHandle) : TElASMessageSigner(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELMESSAGESIGNER
TElASSMIMEMessageSigner::TElASSMIMEMessageSigner(TElMessageSigner &ASigner) : TElASMessageSigner(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElASSMIMEMessageSigner_Create(ASigner.getHandle(), &_Handle));
}

TElASSMIMEMessageSigner::TElASSMIMEMessageSigner(TElMessageSigner *ASigner) : TElASMessageSigner(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElASSMIMEMessageSigner_Create((ASigner != NULL) ? ASigner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELMESSAGESIGNER */

TElASSMIMEMessageSigner::~TElASSMIMEMessageSigner()
{
#ifdef SB_USE_CLASS_TELMESSAGESIGNER
	delete this->_Inst_Signer;
	this->_Inst_Signer = NULL;
#endif /* SB_USE_CLASS_TELMESSAGESIGNER */
}
#endif /* SB_USE_CLASS_TELASSMIMEMESSAGESIGNER */

#ifdef SB_USE_CLASS_TELASSMIMEMESSAGEVERIFIER

#ifdef SB_USE_CLASS_TELMESSAGEVERIFIER
TElMessageVerifier* TElASSMIMEMessageVerifier::get_Verifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElASSMIMEMessageVerifier_get_Verifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Verifier)
		this->_Inst_Verifier = new TElMessageVerifier(hOutResult, ohFalse);
	else
		this->_Inst_Verifier->updateHandle(hOutResult);
	return this->_Inst_Verifier;
}
#endif /* SB_USE_CLASS_TELMESSAGEVERIFIER */

void TElASSMIMEMessageVerifier::initInstances()
{
#ifdef SB_USE_CLASS_TELMESSAGEVERIFIER
	this->_Inst_Verifier = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEVERIFIER */
}

TElASSMIMEMessageVerifier::TElASSMIMEMessageVerifier(TElASSMIMEMessageVerifierHandle handle, TElOwnHandle ownHandle) : TElASMessageVerifier(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELMESSAGEVERIFIER
TElASSMIMEMessageVerifier::TElASSMIMEMessageVerifier(int32_t AResult, TElMessageVerifier &AVerifier) : TElASMessageVerifier(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElASSMIMEMessageVerifier_Create(AResult, AVerifier.getHandle(), &_Handle));
}

TElASSMIMEMessageVerifier::TElASSMIMEMessageVerifier(int32_t AResult, TElMessageVerifier *AVerifier) : TElASMessageVerifier(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElASSMIMEMessageVerifier_Create(AResult, (AVerifier != NULL) ? AVerifier->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELMESSAGEVERIFIER */

TElASSMIMEMessageVerifier::~TElASSMIMEMessageVerifier()
{
#ifdef SB_USE_CLASS_TELMESSAGEVERIFIER
	delete this->_Inst_Verifier;
	this->_Inst_Verifier = NULL;
#endif /* SB_USE_CLASS_TELMESSAGEVERIFIER */
}
#endif /* SB_USE_CLASS_TELASSMIMEMESSAGEVERIFIER */

#ifdef SB_USE_CLASS_TELASSMIMESIGNATURE

SB_INLINE void TElASSMIMESignature::Assign(TPersistent &Source)
{
	SBCheckError(TElASSMIMESignature_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElASSMIMESignature::Assign(TPersistent *Source)
{
	SBCheckError(TElASSMIMESignature_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElASSMIMESignature::Clear()
{
	SBCheckError(TElASSMIMESignature_Clear(_Handle));
}

TElASSMIMESignature::TElASSMIMESignature(TElASSMIMESignatureHandle handle, TElOwnHandle ownHandle) : TElASSignature(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TCOMPONENT
TElASSMIMESignature::TElASSMIMESignature(TComponent &AOwner) : TElASSignature(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASSMIMESignature_Create(AOwner.getHandle(), &_Handle));
}

TElASSMIMESignature::TElASSMIMESignature(TComponent *AOwner) : TElASSignature(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASSMIMESignature_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TCOMPONENT */

#endif /* SB_USE_CLASS_TELASSMIMESIGNATURE */

#ifdef SB_USE_CLASS_TELASCOMPRESSION

SB_INLINE void TElASCompression::Assign(TPersistent &Source)
{
	SBCheckError(TElASCompression_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElASCompression::Assign(TPersistent *Source)
{
	SBCheckError(TElASCompression_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElASCompression::Clear()
{
	SBCheckError(TElASCompression_Clear(_Handle));
}

TElASCompression::TElASCompression(TElASCompressionHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TCOMPONENT
TElASCompression::TElASCompression(TComponent &AOwner) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASCompression_Create(AOwner.getHandle(), &_Handle));
}

TElASCompression::TElASCompression(TComponent *AOwner) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASCompression_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TCOMPONENT */

#endif /* SB_USE_CLASS_TELASCOMPRESSION */

#ifdef SB_USE_CLASS_TELASSMIMECOMPRESSION

SB_INLINE void TElASSMIMECompression::Assign(TPersistent &Source)
{
	SBCheckError(TElASSMIMECompression_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElASSMIMECompression::Assign(TPersistent *Source)
{
	SBCheckError(TElASSMIMECompression_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

TElASSMIMECompression::TElASSMIMECompression(TElASSMIMECompressionHandle handle, TElOwnHandle ownHandle) : TElASCompression(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TCOMPONENT
TElASSMIMECompression::TElASSMIMECompression(TComponent &AOwner) : TElASCompression(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASSMIMECompression_Create(AOwner.getHandle(), &_Handle));
}

TElASSMIMECompression::TElASSMIMECompression(TComponent *AOwner) : TElASCompression(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASSMIMECompression_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TCOMPONENT */

#endif /* SB_USE_CLASS_TELASSMIMECOMPRESSION */

#ifdef SB_USE_CLASS_TELASMESSAGEERROR

SB_INLINE void TElASMessageError::Assign(TPersistent &Source)
{
	SBCheckError(TElASMessageError_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElASMessageError::Assign(TPersistent *Source)
{
	SBCheckError(TElASMessageError_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElASMessageError::get_Code()
{
	int32_t OutResult;
	SBCheckError(TElASMessageError_get_Code(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElASMessageError::set_Code(int32_t Value)
{
	SBCheckError(TElASMessageError_set_Code(_Handle, Value));
}

void TElASMessageError::get_Description(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElASMessageError_get_Description(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(815009424, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElASMessageError::set_Description(const std::string &Value)
{
	SBCheckError(TElASMessageError_set_Description(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBASDispositionModifier TElASMessageError::get_Modifier()
{
	TSBASDispositionModifierRaw OutResultRaw = 0;
	SBCheckError(TElASMessageError_get_Modifier(_Handle, &OutResultRaw));
	return (TSBASDispositionModifier)OutResultRaw;
}

void TElASMessageError::get_Summary(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElASMessageError_get_Summary(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1357308635, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElASMessageError::TElASMessageError(TElASMessageErrorHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElASMessageError::TElASMessageError() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASMessageError_Create(&_Handle));
}

TElASMessageError::TElASMessageError(int32_t ACode, const std::string &ASummary, const std::string &ADescription, TSBASDispositionModifier AModifier) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASMessageError_Create_1(ACode, ASummary.data(), (int32_t)ASummary.length(), ADescription.data(), (int32_t)ADescription.length(), (TSBASDispositionModifierRaw)AModifier, &_Handle));
}

#endif /* SB_USE_CLASS_TELASMESSAGEERROR */

#ifdef SB_USE_CLASS_TELASMESSAGEERRORLIST

SB_INLINE int32_t TElASMessageErrorList::Add(int32_t ACode, const std::string &ASummary, const std::string &ADescription, TSBASDispositionModifier AModifier, bool Adjust)
{
	int32_t OutResult;
	SBCheckError(TElASMessageErrorList_Add(_Handle, ACode, ASummary.data(), (int32_t)ASummary.length(), ADescription.data(), (int32_t)ADescription.length(), (TSBASDispositionModifierRaw)AModifier, (int8_t)Adjust, &OutResult));
	return OutResult;
}

SB_INLINE void TElASMessageErrorList::Assign(TPersistent &Source)
{
	SBCheckError(TElASMessageErrorList_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElASMessageErrorList::Assign(TPersistent *Source)
{
	SBCheckError(TElASMessageErrorList_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElASMessageErrorList::Clear()
{
	SBCheckError(TElASMessageErrorList_Clear(_Handle));
}

SB_INLINE void TElASMessageErrorList::Delete(int32_t Index)
{
	SBCheckError(TElASMessageErrorList_Delete(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELASMESSAGEERROR
SB_INLINE TElASMessageErrorHandle TElASMessageErrorList::First()
{
	TElASMessageErrorHandle OutResult;
	SBCheckError(TElASMessageErrorList_First(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELASMESSAGEERROR */

#ifdef SB_USE_CLASS_TELASMESSAGEERROR
SB_INLINE int32_t TElASMessageErrorList::IndexOf(TElASMessageError &Error)
{
	int32_t OutResult;
	SBCheckError(TElASMessageErrorList_IndexOf(_Handle, Error.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElASMessageErrorList::IndexOf(TElASMessageError *Error)
{
	int32_t OutResult;
	SBCheckError(TElASMessageErrorList_IndexOf(_Handle, (Error != NULL) ? Error->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELASMESSAGEERROR */

SB_INLINE int32_t TElASMessageErrorList::IndexOf(int32_t Code)
{
	int32_t OutResult;
	SBCheckError(TElASMessageErrorList_IndexOf_1(_Handle, Code, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELASMESSAGEERROR
SB_INLINE TElASMessageErrorHandle TElASMessageErrorList::Last()
{
	TElASMessageErrorHandle OutResult;
	SBCheckError(TElASMessageErrorList_Last(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELASMESSAGEERROR */

SB_INLINE void TElASMessageErrorList::Sort()
{
	SBCheckError(TElASMessageErrorList_Sort(_Handle));
}

SB_INLINE int32_t TElASMessageErrorList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElASMessageErrorList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELASMESSAGEERROR
TElASMessageError* TElASMessageErrorList::get_Items(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElASMessageErrorList_get_Items(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElASMessageError(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}

SB_INLINE void TElASMessageErrorList::set_Items(int32_t Index, const TElASMessageError &Value)
{
	SBCheckError(TElASMessageErrorList_set_Items(_Handle, Index, Value.getHandle()));
}

SB_INLINE void TElASMessageErrorList::set_Items(int32_t Index, const TElASMessageError *Value)
{
	SBCheckError(TElASMessageErrorList_set_Items(_Handle, Index, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELASMESSAGEERROR */

TSBASDispositionModifier TElASMessageErrorList::get_Modifier()
{
	TSBASDispositionModifierRaw OutResultRaw = 0;
	SBCheckError(TElASMessageErrorList_get_Modifier(_Handle, &OutResultRaw));
	return (TSBASDispositionModifier)OutResultRaw;
}

SB_INLINE void TElASMessageErrorList::set_Modifier(TSBASDispositionModifier Value)
{
	SBCheckError(TElASMessageErrorList_set_Modifier(_Handle, (TSBASDispositionModifierRaw)Value));
}

TSBASDispositionStatus TElASMessageErrorList::get_Status()
{
	TSBASDispositionStatusRaw OutResultRaw = 0;
	SBCheckError(TElASMessageErrorList_get_Status(_Handle, &OutResultRaw));
	return (TSBASDispositionStatus)OutResultRaw;
}

SB_INLINE void TElASMessageErrorList::set_Status(TSBASDispositionStatus Value)
{
	SBCheckError(TElASMessageErrorList_set_Status(_Handle, (TSBASDispositionStatusRaw)Value));
}

void TElASMessageErrorList::initInstances()
{
#ifdef SB_USE_CLASS_TELASMESSAGEERROR
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELASMESSAGEERROR */
}

TElASMessageErrorList::TElASMessageErrorList(TElASMessageErrorListHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElASMessageErrorList::TElASMessageErrorList() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElASMessageErrorList_Create(&_Handle));
}

TElASMessageErrorList::~TElASMessageErrorList()
{
#ifdef SB_USE_CLASS_TELASMESSAGEERROR
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELASMESSAGEERROR */
}
#endif /* SB_USE_CLASS_TELASMESSAGEERRORLIST */

#ifdef SB_USE_CLASS_TELASMESSAGECONTENTDIGESTS

SB_INLINE void TElASMessageContentDigests::Assign(TElASMessageContentDigests &Source)
{
	SBCheckError(TElASMessageContentDigests_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElASMessageContentDigests::Assign(TElASMessageContentDigests *Source)
{
	SBCheckError(TElASMessageContentDigests_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElASMessageContentDigests::Clear()
{
	SBCheckError(TElASMessageContentDigests_Clear(_Handle));
}

SB_INLINE void TElASMessageContentDigests::Finish()
{
	SBCheckError(TElASMessageContentDigests_Finish(_Handle));
}

SB_INLINE void TElASMessageContentDigests::Init()
{
	SBCheckError(TElASMessageContentDigests_Init(_Handle));
}

SB_INLINE void TElASMessageContentDigests::Update(const void * Buffer, int32_t Count)
{
	SBCheckError(TElASMessageContentDigests_Update(_Handle, Buffer, Count));
}

void TElASMessageContentDigests::get_Value(TSBASSignatureDigestAlgorithm Algorithm, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElASMessageContentDigests_get_Value(_Handle, (TSBASSignatureDigestAlgorithmRaw)Algorithm, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(274128804, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElASMessageContentDigests::TElASMessageContentDigests(TElASMessageContentDigestsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElASMessageContentDigests::TElASMessageContentDigests() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASMessageContentDigests_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELASMESSAGECONTENTDIGESTS */

#ifdef SB_USE_CLASS_TELASRECEIPT

SB_INLINE void TElASReceipt::Assign(TPersistent &Source)
{
	SBCheckError(TElASReceipt_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElASReceipt::Assign(TPersistent *Source)
{
	SBCheckError(TElASReceipt_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElASReceipt::Clear()
{
	SBCheckError(TElASReceipt_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
bool TElASReceipt::Load(TStream &Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASReceipt_Load(_Handle, Stream.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElASReceipt::Load(TStream *Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASReceipt_Load(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
bool TElASReceipt::Load(TStream &ReceiptHeaders, TStream &ReceiptBody)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASReceipt_Load_1(_Handle, ReceiptHeaders.getHandle(), ReceiptBody.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElASReceipt::Load(TStream *ReceiptHeaders, TStream *ReceiptBody)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASReceipt_Load_1(_Handle, (ReceiptHeaders != NULL) ? ReceiptHeaders->getHandle() : SB_NULL_HANDLE, (ReceiptBody != NULL) ? ReceiptBody->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElASReceipt::Load(const std::string &FileName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASReceipt_Load_2(_Handle, FileName.data(), (int32_t)FileName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElASReceipt::Save(TStream &Stream)
{
	SBCheckError(TElASReceipt_Save(_Handle, Stream.getHandle()));
}

SB_INLINE void TElASReceipt::Save(TStream *Stream)
{
	SBCheckError(TElASReceipt_Save(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElASReceipt::Save(TStream &HeadersStream, TStream &BodyStream)
{
	SBCheckError(TElASReceipt_Save_1(_Handle, HeadersStream.getHandle(), BodyStream.getHandle()));
}

SB_INLINE void TElASReceipt::Save(TStream *HeadersStream, TStream *BodyStream)
{
	SBCheckError(TElASReceipt_Save_1(_Handle, (HeadersStream != NULL) ? HeadersStream->getHandle() : SB_NULL_HANDLE, (BodyStream != NULL) ? BodyStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElASReceipt::Save(const std::string &FileName)
{
	SBCheckError(TElASReceipt_Save_2(_Handle, FileName.data(), (int32_t)FileName.length()));
}

TElASReceipt::TElASReceipt(TElASReceiptHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElASReceipt::TElASReceipt(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASReceipt_Create(AOwner.getHandle(), &_Handle));
}

TElASReceipt::TElASReceipt(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASReceipt_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELASRECEIPT */

#ifdef SB_USE_CLASS_TELASMESSAGE

void TElASMessage::GetContentDigest(TSBASSignatureDigestAlgorithm Algorithm, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElASMessage_GetContentDigest(_Handle, (TSBASSignatureDigestAlgorithmRaw)Algorithm, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1241842650, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElASMessage::Assign(TPersistent &Source)
{
	SBCheckError(TElASMessage_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElASMessage::Assign(TPersistent *Source)
{
	SBCheckError(TElASMessage_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElASMessage::Clear()
{
	SBCheckError(TElASMessage_Clear(_Handle));
}

SB_INLINE void TElASMessage::GetFileOptions(const std::string &FilePath)
{
	SBCheckError(TElASMessage_GetFileOptions(_Handle, FilePath.data(), (int32_t)FilePath.length()));
}

SB_INLINE void TElASMessage::SetFileOptions(const std::string &FilePath)
{
	SBCheckError(TElASMessage_SetFileOptions(_Handle, FilePath.data(), (int32_t)FilePath.length()));
}

bool TElASMessage::Load(const std::string &FileName, const std::string &DataFile)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASMessage_Load(_Handle, FileName.data(), (int32_t)FileName.length(), DataFile.data(), (int32_t)DataFile.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
bool TElASMessage::Load(TStream &Source, TStream &Data)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASMessage_Load_1(_Handle, Source.getHandle(), Data.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElASMessage::Load(TStream *Source, TStream *Data)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASMessage_Load_1(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElASMessage::Save(const std::string &DataFile, const std::string &FileName)
{
	SBCheckError(TElASMessage_Save(_Handle, DataFile.data(), (int32_t)DataFile.length(), FileName.data(), (int32_t)FileName.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElASMessage::Save(TStream &Data, TStream &Dest)
{
	SBCheckError(TElASMessage_Save_1(_Handle, Data.getHandle(), Dest.getHandle()));
}

SB_INLINE void TElASMessage::Save(TStream *Data, TStream *Dest)
{
	SBCheckError(TElASMessage_Save_1(_Handle, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElASMessage::Save(TStream &Data, TStream &DestHeaders, TStream &DestBody)
{
	SBCheckError(TElASMessage_Save_2(_Handle, Data.getHandle(), DestHeaders.getHandle(), DestBody.getHandle()));
}

SB_INLINE void TElASMessage::Save(TStream *Data, TStream *DestHeaders, TStream *DestBody)
{
	SBCheckError(TElASMessage_Save_2(_Handle, (Data != NULL) ? Data->getHandle() : SB_NULL_HANDLE, (DestHeaders != NULL) ? DestHeaders->getHandle() : SB_NULL_HANDLE, (DestBody != NULL) ? DestBody->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

TElASMessage::TElASMessage(TElASMessageHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElASMessage::TElASMessage(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASMessage_Create(AOwner.getHandle(), &_Handle));
}

TElASMessage::TElASMessage(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASMessage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELASMESSAGE */

};	/* namespace SecureBlackbox */

