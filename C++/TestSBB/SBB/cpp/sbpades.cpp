#include "sbpades.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPDFADVANCEDPUBLICKEYSECURITYHANDLER

void TElPDFAdvancedPublicKeySecurityHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFAdvancedPublicKeySecurityHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-668996102, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPDFAdvancedPublicKeySecurityHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFAdvancedPublicKeySecurityHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-668996102, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPDFAdvancedPublicKeySecurityHandler::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFAdvancedPublicKeySecurityHandler_GetDescription((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1776527630, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPDFAdvancedPublicKeySecurityHandler::GetDescription_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFAdvancedPublicKeySecurityHandler_GetDescription_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1776527630, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE TElX509CertificateHandle TElPDFAdvancedPublicKeySecurityHandler::GetSignerCertificate()
{
	TElX509CertificateHandle OutResult;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_GetSignerCertificate(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::Reset()
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_Reset(_Handle));
}

SB_INLINE TClassHandle TElPDFAdvancedPublicKeySecurityHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO
TElPDFPublicKeyRevocationInfo* TElPDFAdvancedPublicKeySecurityHandler::get_DSSRevocationInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_DSSRevocationInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DSSRevocationInfo)
		this->_Inst_DSSRevocationInfo = new TElPDFPublicKeyRevocationInfo(hOutResult, ohFalse);
	else
		this->_Inst_DSSRevocationInfo->updateHandle(hOutResult);
	return this->_Inst_DSSRevocationInfo;
}
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO */

#ifdef SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO
TElPDFPublicKeyRevocationInfo* TElPDFAdvancedPublicKeySecurityHandler::get_CustomRevocationInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_CustomRevocationInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CustomRevocationInfo)
		this->_Inst_CustomRevocationInfo = new TElPDFPublicKeyRevocationInfo(hOutResult, ohFalse);
	else
		this->_Inst_CustomRevocationInfo->updateHandle(hOutResult);
	return this->_Inst_CustomRevocationInfo;
}
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO */

#ifdef SB_USE_CLASS_TELSIGNEDCMSMESSAGE
TElSignedCMSMessage* TElPDFAdvancedPublicKeySecurityHandler::get_CMS()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_CMS(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CMS)
		this->_Inst_CMS = new TElSignedCMSMessage(hOutResult, ohFalse);
	else
		this->_Inst_CMS->updateHandle(hOutResult);
	return this->_Inst_CMS;
}
#endif /* SB_USE_CLASS_TELSIGNEDCMSMESSAGE */

TSBCMSAdvancedSignatureValidity TElPDFAdvancedPublicKeySecurityHandler::get_ValidationDetails()
{
	TSBCMSAdvancedSignatureValidityRaw OutResultRaw = 0;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_ValidationDetails(_Handle, &OutResultRaw));
	return (TSBCMSAdvancedSignatureValidity)OutResultRaw;
}

void TElPDFAdvancedPublicKeySecurityHandler::get_ValidationMessage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFAdvancedPublicKeySecurityHandler_get_ValidationMessage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(320871271, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
TElClientTSPInfo* TElPDFAdvancedPublicKeySecurityHandler::get_DocumentTimestamp()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_DocumentTimestamp(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DocumentTimestamp)
		this->_Inst_DocumentTimestamp = new TElClientTSPInfo(hOutResult, ohFalse);
	else
		this->_Inst_DocumentTimestamp->updateHandle(hOutResult);
	return this->_Inst_DocumentTimestamp;
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

TSBPAdESSignatureType TElPDFAdvancedPublicKeySecurityHandler::get_PAdESSignatureType()
{
	TSBPAdESSignatureTypeRaw OutResultRaw = 0;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_PAdESSignatureType(_Handle, &OutResultRaw));
	return (TSBPAdESSignatureType)OutResultRaw;
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::set_PAdESSignatureType(TSBPAdESSignatureType Value)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_set_PAdESSignatureType(_Handle, (TSBPAdESSignatureTypeRaw)Value));
}

bool TElPDFAdvancedPublicKeySecurityHandler::get_DeepValidation()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_DeepValidation(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::set_DeepValidation(bool Value)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_set_DeepValidation(_Handle, (int8_t)Value));
}

bool TElPDFAdvancedPublicKeySecurityHandler::get_AutoCollectRevocationInfo()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_AutoCollectRevocationInfo(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::set_AutoCollectRevocationInfo(bool Value)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_set_AutoCollectRevocationInfo(_Handle, (int8_t)Value));
}

bool TElPDFAdvancedPublicKeySecurityHandler::get_IgnoreChainValidationErrors()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_IgnoreChainValidationErrors(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::set_IgnoreChainValidationErrors(bool Value)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_set_IgnoreChainValidationErrors(_Handle, (int8_t)Value));
}

bool TElPDFAdvancedPublicKeySecurityHandler::get_ForceCompleteChainValidation()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_ForceCompleteChainValidation(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::set_ForceCompleteChainValidation(bool Value)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_set_ForceCompleteChainValidation(_Handle, (int8_t)Value));
}

bool TElPDFAdvancedPublicKeySecurityHandler::get_IncludeRevocationInfoToAdbeAttribute()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_IncludeRevocationInfoToAdbeAttribute(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::set_IncludeRevocationInfoToAdbeAttribute(bool Value)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_set_IncludeRevocationInfoToAdbeAttribute(_Handle, (int8_t)Value));
}

SB_INLINE int64_t TElPDFAdvancedPublicKeySecurityHandler::get_ValidationMoment()
{
	int64_t OutResult;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_ValidationMoment(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::set_ValidationMoment(int64_t Value)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_set_ValidationMoment(_Handle, Value));
}

TSBPAdESOptions TElPDFAdvancedPublicKeySecurityHandler::get_PAdESOptions()
{
	TSBPAdESOptionsRaw OutResultRaw = 0;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_PAdESOptions(_Handle, &OutResultRaw));
	return (TSBPAdESOptions)OutResultRaw;
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::set_PAdESOptions(TSBPAdESOptions Value)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_set_PAdESOptions(_Handle, (TSBPAdESOptionsRaw)Value));
}

TSBPAdESSignatureSizeEstimationStrategy TElPDFAdvancedPublicKeySecurityHandler::get_SignatureSizeEstimationStrategy()
{
	TSBPAdESSignatureSizeEstimationStrategyRaw OutResultRaw = 0;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_SignatureSizeEstimationStrategy(_Handle, &OutResultRaw));
	return (TSBPAdESSignatureSizeEstimationStrategy)OutResultRaw;
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::set_SignatureSizeEstimationStrategy(TSBPAdESSignatureSizeEstimationStrategy Value)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_set_SignatureSizeEstimationStrategy(_Handle, (TSBPAdESSignatureSizeEstimationStrategyRaw)Value));
}

SB_INLINE int32_t TElPDFAdvancedPublicKeySecurityHandler::get_PredefinedSignatureSize()
{
	int32_t OutResult;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_PredefinedSignatureSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::set_PredefinedSignatureSize(int32_t Value)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_set_PredefinedSignatureSize(_Handle, Value));
}

bool TElPDFAdvancedPublicKeySecurityHandler::get_RemoteSigningMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_RemoteSigningMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::set_RemoteSigningMode(bool Value)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_set_RemoteSigningMode(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELREMOTESIGNINGPARAMS
TElRemoteSigningParams* TElPDFAdvancedPublicKeySecurityHandler::get_RemoteSigningParams()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_RemoteSigningParams(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RemoteSigningParams)
		this->_Inst_RemoteSigningParams = new TElRemoteSigningParams(hOutResult, ohFalse);
	else
		this->_Inst_RemoteSigningParams->updateHandle(hOutResult);
	return this->_Inst_RemoteSigningParams;
}
#endif /* SB_USE_CLASS_TELREMOTESIGNINGPARAMS */

SB_INLINE int32_t TElPDFAdvancedPublicKeySecurityHandler::get_RemoteSigningCertIndex()
{
	int32_t OutResult;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_RemoteSigningCertIndex(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::set_RemoteSigningCertIndex(int32_t Value)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_set_RemoteSigningCertIndex(_Handle, Value));
}

TSBPAdESExtensionIdentifierMode TElPDFAdvancedPublicKeySecurityHandler::get_ExtensionIdentifierMode()
{
	TSBPAdESExtensionIdentifierModeRaw OutResultRaw = 0;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_ExtensionIdentifierMode(_Handle, &OutResultRaw));
	return (TSBPAdESExtensionIdentifierMode)OutResultRaw;
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::set_ExtensionIdentifierMode(TSBPAdESExtensionIdentifierMode Value)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_set_ExtensionIdentifierMode(_Handle, (TSBPAdESExtensionIdentifierModeRaw)Value));
}

bool TElPDFAdvancedPublicKeySecurityHandler::get_ReuseCollectedRevocationInfo()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_ReuseCollectedRevocationInfo(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::set_ReuseCollectedRevocationInfo(bool Value)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_set_ReuseCollectedRevocationInfo(_Handle, (int8_t)Value));
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::get_OnBeforeSign(TSBPDFSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_OnBeforeSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::set_OnBeforeSign(TSBPDFSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_set_OnBeforeSign(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::get_OnAfterSign(TSBPDFSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_OnAfterSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::set_OnAfterSign(TSBPDFSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_set_OnAfterSign(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::get_OnCertValidatorPrepared(TSBPDFCertValidatorPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_OnCertValidatorPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::set_OnCertValidatorPrepared(TSBPDFCertValidatorPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_set_OnCertValidatorPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::get_OnCertValidatorFinished(TSBPDFCertValidatorFinishedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_OnCertValidatorFinished(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::set_OnCertValidatorFinished(TSBPDFCertValidatorFinishedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_set_OnCertValidatorFinished(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::get_OnRemoteSign(TSBPDFRemoteSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_get_OnRemoteSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPDFAdvancedPublicKeySecurityHandler::set_OnRemoteSign(TSBPDFRemoteSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_set_OnRemoteSign(_Handle, pMethodValue, pDataValue));
}

void TElPDFAdvancedPublicKeySecurityHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO
	this->_Inst_DSSRevocationInfo = NULL;
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO */
#ifdef SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO
	this->_Inst_CustomRevocationInfo = NULL;
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO */
#ifdef SB_USE_CLASS_TELSIGNEDCMSMESSAGE
	this->_Inst_CMS = NULL;
#endif /* SB_USE_CLASS_TELSIGNEDCMSMESSAGE */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	this->_Inst_DocumentTimestamp = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELREMOTESIGNINGPARAMS
	this->_Inst_RemoteSigningParams = NULL;
#endif /* SB_USE_CLASS_TELREMOTESIGNINGPARAMS */
}

TElPDFAdvancedPublicKeySecurityHandler::TElPDFAdvancedPublicKeySecurityHandler(TElPDFAdvancedPublicKeySecurityHandlerHandle handle, TElOwnHandle ownHandle) : TElPDFPublicKeySecurityHandler(handle, ownHandle)
{
	initInstances();
}

TElPDFAdvancedPublicKeySecurityHandler::TElPDFAdvancedPublicKeySecurityHandler(TComponent &Owner) : TElPDFPublicKeySecurityHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_Create(Owner.getHandle(), &_Handle));
}

TElPDFAdvancedPublicKeySecurityHandler::TElPDFAdvancedPublicKeySecurityHandler(TComponent *Owner) : TElPDFPublicKeySecurityHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFAdvancedPublicKeySecurityHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElPDFAdvancedPublicKeySecurityHandler::~TElPDFAdvancedPublicKeySecurityHandler()
{
#ifdef SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO
	delete this->_Inst_DSSRevocationInfo;
	this->_Inst_DSSRevocationInfo = NULL;
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO */
#ifdef SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO
	delete this->_Inst_CustomRevocationInfo;
	this->_Inst_CustomRevocationInfo = NULL;
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO */
#ifdef SB_USE_CLASS_TELSIGNEDCMSMESSAGE
	delete this->_Inst_CMS;
	this->_Inst_CMS = NULL;
#endif /* SB_USE_CLASS_TELSIGNEDCMSMESSAGE */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	delete this->_Inst_DocumentTimestamp;
	this->_Inst_DocumentTimestamp = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELREMOTESIGNINGPARAMS
	delete this->_Inst_RemoteSigningParams;
	this->_Inst_RemoteSigningParams = NULL;
#endif /* SB_USE_CLASS_TELREMOTESIGNINGPARAMS */
}
#endif /* SB_USE_CLASS_TELPDFADVANCEDPUBLICKEYSECURITYHANDLER */

};	/* namespace SecureBlackbox */

