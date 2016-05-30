#include "sbxmlsoapsecurity.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELXMLSOAPSIGNATUREHANDLER

void TElXMLSOAPSignatureHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPSignatureHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-59246065, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLSOAPSignatureHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPSignatureHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-59246065, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLSOAPMESSAGE
SB_INLINE void TElXMLSOAPSignatureHandler::LoadFromXML(TElXMLDOMElement &SignatureElement, TElXMLSOAPMessage &Msg)
{
	SBCheckError(TElXMLSOAPSignatureHandler_LoadFromXML(_Handle, SignatureElement.getHandle(), Msg.getHandle()));
}

SB_INLINE void TElXMLSOAPSignatureHandler::LoadFromXML(TElXMLDOMElement *SignatureElement, TElXMLSOAPMessage *Msg)
{
	SBCheckError(TElXMLSOAPSignatureHandler_LoadFromXML(_Handle, (SignatureElement != NULL) ? SignatureElement->getHandle() : SB_NULL_HANDLE, (Msg != NULL) ? Msg->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLSOAPMESSAGE */

SB_INLINE void TElXMLSOAPSignatureHandler::Reset()
{
	SBCheckError(TElXMLSOAPSignatureHandler_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign()
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign(TElX509Certificate &Certificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign_1(_Handle, Certificate.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign(TElX509Certificate *Certificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign(TElX509Certificate &Certificate, bool IncludeKey)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign_2(_Handle, Certificate.getHandle(), (int8_t)IncludeKey, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign(TElX509Certificate *Certificate, bool IncludeKey)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign_2(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign(TElX509Certificate &Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign_3(_Handle, Certificate.getHandle(), (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign(TElX509Certificate *Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign_3(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE
SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign(TElCustomCertStorage &CertStorage)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign_4(_Handle, CertStorage.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign(TElCustomCertStorage *CertStorage)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign_4(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE
SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign(TElCustomCertStorage &CertStorage, bool IncludeKey)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign_5(_Handle, CertStorage.getHandle(), (int8_t)IncludeKey, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign(TElCustomCertStorage *CertStorage, bool IncludeKey)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign_5(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE
SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign(TElCustomCertStorage &CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign_6(_Handle, CertStorage.getHandle(), (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign(TElCustomCertStorage *CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign_6(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLKEYINFODATA
SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign(TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign_7(_Handle, KeyData.getHandle(), (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)IncludeKey, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign(TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign_7(_Handle, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE, (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)IncludeKey, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT
SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElX509Certificate &Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign_8(_Handle, ParentElement.getHandle(), Certificate.getHandle(), (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElX509Certificate *Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign_8(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT
SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElCustomCertStorage &CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign_9(_Handle, ParentElement.getHandle(), CertStorage.getHandle(), (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElCustomCertStorage *CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign_9(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA
SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign_10(_Handle, ParentElement.getHandle(), KeyData.getHandle(), (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)IncludeKey, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLSOAPSignatureHandler::InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_InitiateAsyncSign_10(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE, (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)IncludeKey, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElXMLSOAPSignatureHandler::Sign(TElX509Certificate &Certificate)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Sign(_Handle, Certificate.getHandle()));
}

SB_INLINE void TElXMLSOAPSignatureHandler::Sign(TElX509Certificate *Certificate)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Sign(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElXMLSOAPSignatureHandler::Sign(TElX509Certificate &Certificate, bool IncludeKey)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Sign_1(_Handle, Certificate.getHandle(), (int8_t)IncludeKey));
}

SB_INLINE void TElXMLSOAPSignatureHandler::Sign(TElX509Certificate *Certificate, bool IncludeKey)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Sign_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElXMLSOAPSignatureHandler::Sign(TElX509Certificate &Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Sign_2(_Handle, Certificate.getHandle(), (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams));
}

SB_INLINE void TElXMLSOAPSignatureHandler::Sign(TElX509Certificate *Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Sign_2(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElXMLSOAPSignatureHandler::Sign(TElCustomCertStorage &CertStorage)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Sign_3(_Handle, CertStorage.getHandle()));
}

SB_INLINE void TElXMLSOAPSignatureHandler::Sign(TElCustomCertStorage *CertStorage)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Sign_3(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElXMLSOAPSignatureHandler::Sign(TElCustomCertStorage &CertStorage, bool IncludeKey)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Sign_4(_Handle, CertStorage.getHandle(), (int8_t)IncludeKey));
}

SB_INLINE void TElXMLSOAPSignatureHandler::Sign(TElCustomCertStorage *CertStorage, bool IncludeKey)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Sign_4(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElXMLSOAPSignatureHandler::Sign(TElCustomCertStorage &CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Sign_5(_Handle, CertStorage.getHandle(), (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams));
}

SB_INLINE void TElXMLSOAPSignatureHandler::Sign(TElCustomCertStorage *CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Sign_5(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
SB_INLINE void TElXMLSOAPSignatureHandler::Sign(TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Sign_6(_Handle, KeyData.getHandle(), (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)IncludeKey));
}

SB_INLINE void TElXMLSOAPSignatureHandler::Sign(TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Sign_6(_Handle, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE, (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)IncludeKey));
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPSignatureHandler::Sign(TElXMLDOMElement &ParentElement, TElX509Certificate &Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Sign_7(_Handle, ParentElement.getHandle(), Certificate.getHandle(), (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams));
}

SB_INLINE void TElXMLSOAPSignatureHandler::Sign(TElXMLDOMElement *ParentElement, TElX509Certificate *Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Sign_7(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams));
}
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLDOMELEMENT
SB_INLINE void TElXMLSOAPSignatureHandler::Sign(TElXMLDOMElement &ParentElement, TElCustomCertStorage &CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Sign_8(_Handle, ParentElement.getHandle(), CertStorage.getHandle(), (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams));
}

SB_INLINE void TElXMLSOAPSignatureHandler::Sign(TElXMLDOMElement *ParentElement, TElCustomCertStorage *CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Sign_8(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA
SB_INLINE void TElXMLSOAPSignatureHandler::Sign(TElXMLDOMElement &ParentElement, TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Sign_9(_Handle, ParentElement.getHandle(), KeyData.getHandle(), (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)IncludeKey));
}

SB_INLINE void TElXMLSOAPSignatureHandler::Sign(TElXMLDOMElement *ParentElement, TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Sign_9(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE, (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)IncludeKey));
}
#endif /* SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA */

SB_INLINE TClassHandle TElXMLSOAPSignatureHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLSOAPSignatureHandler_ClassType(&OutResult));
	return OutResult;
}

void TElXMLSOAPSignatureHandler::get_ID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPSignatureHandler_get_ID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(911135219, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPSignatureHandler::get_ID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPSignatureHandler_get_ID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(911135219, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPSignatureHandler::set_ID(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPSignatureHandler_set_ID(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPSignatureHandler::set_ID(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPSignatureHandler_set_ID(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPSignatureHandler::get_Actor(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPSignatureHandler_get_Actor(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1127862588, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPSignatureHandler::get_Actor(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPSignatureHandler_get_Actor(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1127862588, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPSignatureHandler::set_Actor(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPSignatureHandler_set_Actor(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPSignatureHandler::set_Actor(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPSignatureHandler_set_Actor(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLSOAPSignatureHandler::get_MustUnderstand(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLSOAPSignatureHandler_get_MustUnderstand(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1546966344, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLSOAPSignatureHandler::get_MustUnderstand(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLSOAPSignatureHandler_get_MustUnderstand(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1546966344, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLSOAPSignatureHandler::set_MustUnderstand(const sb_u16string &Value)
{
	SBCheckError(TElXMLSOAPSignatureHandler_set_MustUnderstand(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLSOAPSignatureHandler::set_MustUnderstand(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLSOAPSignatureHandler_set_MustUnderstand(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLSOAPSignatureHandler::TElXMLSOAPSignatureHandler(TElXMLSOAPSignatureHandlerHandle handle, TElOwnHandle ownHandle) : TElXMLSOAPBaseSignatureHandler(handle, ownHandle)
{
}

TElXMLSOAPSignatureHandler::TElXMLSOAPSignatureHandler(TComponent &Owner) : TElXMLSOAPBaseSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Create(Owner.getHandle(), &_Handle));
}

TElXMLSOAPSignatureHandler::TElXMLSOAPSignatureHandler(TComponent *Owner) : TElXMLSOAPBaseSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLSOAPSignatureHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELXMLSOAPSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELXMLWSSSIGNATUREHANDLER

void TElXMLWSSSignatureHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLWSSSignatureHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2138498265, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLWSSSignatureHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLWSSSignatureHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2138498265, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElXMLWSSSignatureHandler::Reset()
{
	SBCheckError(TElXMLWSSSignatureHandler_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign()
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElX509Certificate &Certificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_1(_Handle, Certificate.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElX509Certificate *Certificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElX509Certificate &Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_2(_Handle, Certificate.getHandle(), (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElX509Certificate *Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_2(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElX509Certificate &Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, const sb_u16string &TokenID)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_3(_Handle, Certificate.getHandle(), (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, TokenID.data(), (int32_t)TokenID.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElX509Certificate *Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, const sb_u16string &TokenID)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_3(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, TokenID.data(), (int32_t)TokenID.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElX509Certificate &Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, const std::wstring &TokenID)
{
	TElDCAsyncStateHandle OutResult;
	std::string u16TokenID;
	sb_to_u16string(TokenID, u16TokenID);
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_3(_Handle, Certificate.getHandle(), (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, reinterpret_cast<const sb_char16_t*>(u16TokenID.data()), (int32_t)u16TokenID.length() >> 1, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElX509Certificate *Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, const std::wstring &TokenID)
{
	TElDCAsyncStateHandle OutResult;
	std::string u16TokenID;
	sb_to_u16string(TokenID, u16TokenID);
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_3(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, reinterpret_cast<const sb_char16_t*>(u16TokenID.data()), (int32_t)u16TokenID.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElX509Certificate &Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const sb_u16string &TokenID)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_4(_Handle, Certificate.getHandle(), (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, (TSBXMLWSSETokenTypeRaw)TokenType, TokenID.data(), (int32_t)TokenID.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElX509Certificate *Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const sb_u16string &TokenID)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_4(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, (TSBXMLWSSETokenTypeRaw)TokenType, TokenID.data(), (int32_t)TokenID.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElX509Certificate &Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const std::wstring &TokenID)
{
	TElDCAsyncStateHandle OutResult;
	std::string u16TokenID;
	sb_to_u16string(TokenID, u16TokenID);
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_4(_Handle, Certificate.getHandle(), (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, (TSBXMLWSSETokenTypeRaw)TokenType, reinterpret_cast<const sb_char16_t*>(u16TokenID.data()), (int32_t)u16TokenID.length() >> 1, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElX509Certificate *Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const std::wstring &TokenID)
{
	TElDCAsyncStateHandle OutResult;
	std::string u16TokenID;
	sb_to_u16string(TokenID, u16TokenID);
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_4(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, (TSBXMLWSSETokenTypeRaw)TokenType, reinterpret_cast<const sb_char16_t*>(u16TokenID.data()), (int32_t)u16TokenID.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE
SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElCustomCertStorage &CertStorage)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_5(_Handle, CertStorage.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElCustomCertStorage *CertStorage)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_5(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE
SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElCustomCertStorage &CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_6(_Handle, CertStorage.getHandle(), (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElCustomCertStorage *CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_6(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE
SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElCustomCertStorage &CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, const sb_u16string &TokenID)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_7(_Handle, CertStorage.getHandle(), (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, TokenID.data(), (int32_t)TokenID.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElCustomCertStorage *CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, const sb_u16string &TokenID)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_7(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, TokenID.data(), (int32_t)TokenID.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElCustomCertStorage &CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, const std::wstring &TokenID)
{
	TElDCAsyncStateHandle OutResult;
	std::string u16TokenID;
	sb_to_u16string(TokenID, u16TokenID);
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_7(_Handle, CertStorage.getHandle(), (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, reinterpret_cast<const sb_char16_t*>(u16TokenID.data()), (int32_t)u16TokenID.length() >> 1, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElCustomCertStorage *CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, const std::wstring &TokenID)
{
	TElDCAsyncStateHandle OutResult;
	std::string u16TokenID;
	sb_to_u16string(TokenID, u16TokenID);
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_7(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, reinterpret_cast<const sb_char16_t*>(u16TokenID.data()), (int32_t)u16TokenID.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE
SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElCustomCertStorage &CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const sb_u16string &TokenID)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_8(_Handle, CertStorage.getHandle(), (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, (TSBXMLWSSETokenTypeRaw)TokenType, TokenID.data(), (int32_t)TokenID.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElCustomCertStorage *CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const sb_u16string &TokenID)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_8(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, (TSBXMLWSSETokenTypeRaw)TokenType, TokenID.data(), (int32_t)TokenID.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElCustomCertStorage &CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const std::wstring &TokenID)
{
	TElDCAsyncStateHandle OutResult;
	std::string u16TokenID;
	sb_to_u16string(TokenID, u16TokenID);
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_8(_Handle, CertStorage.getHandle(), (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, (TSBXMLWSSETokenTypeRaw)TokenType, reinterpret_cast<const sb_char16_t*>(u16TokenID.data()), (int32_t)u16TokenID.length() >> 1, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElCustomCertStorage *CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const std::wstring &TokenID)
{
	TElDCAsyncStateHandle OutResult;
	std::string u16TokenID;
	sb_to_u16string(TokenID, u16TokenID);
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_8(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, (TSBXMLWSSETokenTypeRaw)TokenType, reinterpret_cast<const sb_char16_t*>(u16TokenID.data()), (int32_t)u16TokenID.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLKEYINFODATA
SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool EmbedKeyInSignature)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_9(_Handle, KeyData.getHandle(), (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)EmbedKeyInSignature, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool EmbedKeyInSignature)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_9(_Handle, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE, (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)EmbedKeyInSignature, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT
SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElX509Certificate &Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_10(_Handle, ParentElement.getHandle(), Certificate.getHandle(), (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElX509Certificate *Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_10(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT
SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElCustomCertStorage &CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_11(_Handle, ParentElement.getHandle(), CertStorage.getHandle(), (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElCustomCertStorage *CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_11(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA
SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElXMLDOMElement &ParentElement, TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_12(_Handle, ParentElement.getHandle(), KeyData.getHandle(), (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)IncludeKey, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElXMLWSSSignatureHandler::InitiateAsyncSign(TElXMLDOMElement *ParentElement, TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_InitiateAsyncSign_12(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE, (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)IncludeKey, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElX509Certificate &Certificate)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign(_Handle, Certificate.getHandle()));
}

SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElX509Certificate *Certificate)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElX509Certificate &Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_1(_Handle, Certificate.getHandle(), (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate));
}

SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElX509Certificate *Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElX509Certificate &Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, const sb_u16string &TokenID)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_2(_Handle, Certificate.getHandle(), (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, TokenID.data(), (int32_t)TokenID.length()));
}

SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElX509Certificate *Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, const sb_u16string &TokenID)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_2(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, TokenID.data(), (int32_t)TokenID.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElX509Certificate &Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, const std::wstring &TokenID)
{
	std::string u16TokenID;
	sb_to_u16string(TokenID, u16TokenID);
	SBCheckError(TElXMLWSSSignatureHandler_Sign_2(_Handle, Certificate.getHandle(), (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, reinterpret_cast<const sb_char16_t*>(u16TokenID.data()), (int32_t)u16TokenID.length() >> 1));
}

SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElX509Certificate *Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, const std::wstring &TokenID)
{
	std::string u16TokenID;
	sb_to_u16string(TokenID, u16TokenID);
	SBCheckError(TElXMLWSSSignatureHandler_Sign_2(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, reinterpret_cast<const sb_char16_t*>(u16TokenID.data()), (int32_t)u16TokenID.length() >> 1));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElX509Certificate &Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const sb_u16string &TokenID)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_3(_Handle, Certificate.getHandle(), (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, (TSBXMLWSSETokenTypeRaw)TokenType, TokenID.data(), (int32_t)TokenID.length()));
}

SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElX509Certificate *Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const sb_u16string &TokenID)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_3(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, (TSBXMLWSSETokenTypeRaw)TokenType, TokenID.data(), (int32_t)TokenID.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElX509Certificate &Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const std::wstring &TokenID)
{
	std::string u16TokenID;
	sb_to_u16string(TokenID, u16TokenID);
	SBCheckError(TElXMLWSSSignatureHandler_Sign_3(_Handle, Certificate.getHandle(), (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, (TSBXMLWSSETokenTypeRaw)TokenType, reinterpret_cast<const sb_char16_t*>(u16TokenID.data()), (int32_t)u16TokenID.length() >> 1));
}

SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElX509Certificate *Certificate, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const std::wstring &TokenID)
{
	std::string u16TokenID;
	sb_to_u16string(TokenID, u16TokenID);
	SBCheckError(TElXMLWSSSignatureHandler_Sign_3(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, (TSBXMLWSSETokenTypeRaw)TokenType, reinterpret_cast<const sb_char16_t*>(u16TokenID.data()), (int32_t)u16TokenID.length() >> 1));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElCustomCertStorage &CertStorage)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_4(_Handle, CertStorage.getHandle()));
}

SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElCustomCertStorage *CertStorage)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_4(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElCustomCertStorage &CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_5(_Handle, CertStorage.getHandle(), (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate));
}

SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElCustomCertStorage *CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_5(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElCustomCertStorage &CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, const sb_u16string &TokenID)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_6(_Handle, CertStorage.getHandle(), (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, TokenID.data(), (int32_t)TokenID.length()));
}

SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElCustomCertStorage *CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, const sb_u16string &TokenID)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_6(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, TokenID.data(), (int32_t)TokenID.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElCustomCertStorage &CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, const std::wstring &TokenID)
{
	std::string u16TokenID;
	sb_to_u16string(TokenID, u16TokenID);
	SBCheckError(TElXMLWSSSignatureHandler_Sign_6(_Handle, CertStorage.getHandle(), (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, reinterpret_cast<const sb_char16_t*>(u16TokenID.data()), (int32_t)u16TokenID.length() >> 1));
}

SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElCustomCertStorage *CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, const std::wstring &TokenID)
{
	std::string u16TokenID;
	sb_to_u16string(TokenID, u16TokenID);
	SBCheckError(TElXMLWSSSignatureHandler_Sign_6(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, reinterpret_cast<const sb_char16_t*>(u16TokenID.data()), (int32_t)u16TokenID.length() >> 1));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElCustomCertStorage &CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const sb_u16string &TokenID)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_7(_Handle, CertStorage.getHandle(), (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, (TSBXMLWSSETokenTypeRaw)TokenType, TokenID.data(), (int32_t)TokenID.length()));
}

SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElCustomCertStorage *CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const sb_u16string &TokenID)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_7(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, (TSBXMLWSSETokenTypeRaw)TokenType, TokenID.data(), (int32_t)TokenID.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElCustomCertStorage &CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const std::wstring &TokenID)
{
	std::string u16TokenID;
	sb_to_u16string(TokenID, u16TokenID);
	SBCheckError(TElXMLWSSSignatureHandler_Sign_7(_Handle, CertStorage.getHandle(), (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, (TSBXMLWSSETokenTypeRaw)TokenType, reinterpret_cast<const sb_char16_t*>(u16TokenID.data()), (int32_t)u16TokenID.length() >> 1));
}

SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElCustomCertStorage *CertStorage, TSBXMLWSSEmbedCertificate EmbedCertificate, TSBXMLWSSETokenType TokenType, const std::wstring &TokenID)
{
	std::string u16TokenID;
	sb_to_u16string(TokenID, u16TokenID);
	SBCheckError(TElXMLWSSSignatureHandler_Sign_7(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (TSBXMLWSSEmbedCertificateRaw)EmbedCertificate, (TSBXMLWSSETokenTypeRaw)TokenType, reinterpret_cast<const sb_char16_t*>(u16TokenID.data()), (int32_t)u16TokenID.length() >> 1));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool EmbedKeyInSignature)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_8(_Handle, KeyData.getHandle(), (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)EmbedKeyInSignature));
}

SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool EmbedKeyInSignature)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_8(_Handle, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE, (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)EmbedKeyInSignature));
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT
SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElXMLDOMElement &ParentElement, TElX509Certificate &Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_9(_Handle, ParentElement.getHandle(), Certificate.getHandle(), (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams));
}

SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElXMLDOMElement *ParentElement, TElX509Certificate *Certificate, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_9(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams));
}
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLDOMELEMENT
SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElXMLDOMElement &ParentElement, TElCustomCertStorage &CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_10(_Handle, ParentElement.getHandle(), CertStorage.getHandle(), (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams));
}

SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElXMLDOMElement *ParentElement, TElCustomCertStorage *CertStorage, bool IncludeKey, bool IncludeKeyValue, TElXMLKeyInfoX509DataParams IncludeDataParams)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_10(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (int8_t)IncludeKey, (int8_t)IncludeKeyValue, (TElXMLKeyInfoX509DataParamsRaw)IncludeDataParams));
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA
SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElXMLDOMElement &ParentElement, TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_11(_Handle, ParentElement.getHandle(), KeyData.getHandle(), (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)IncludeKey));
}

SB_INLINE void TElXMLWSSSignatureHandler::Sign(TElXMLDOMElement *ParentElement, TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey)
{
	SBCheckError(TElXMLWSSSignatureHandler_Sign_11(_Handle, (ParentElement != NULL) ? ParentElement->getHandle() : SB_NULL_HANDLE, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE, (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)IncludeKey));
}
#endif /* SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLKEYINFODATA */

SB_INLINE TClassHandle TElXMLWSSSignatureHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElXMLWSSSignatureHandler_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLWSSESECURITY
TElXMLWSSESecurity* TElXMLWSSSignatureHandler::get_SecurityHeader()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLWSSSignatureHandler_get_SecurityHeader(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SecurityHeader)
		this->_Inst_SecurityHeader = new TElXMLWSSESecurity(hOutResult, ohFalse);
	else
		this->_Inst_SecurityHeader->updateHandle(hOutResult);
	return this->_Inst_SecurityHeader;
}

SB_INLINE void TElXMLWSSSignatureHandler::set_SecurityHeader(TElXMLWSSESecurity &Value)
{
	SBCheckError(TElXMLWSSSignatureHandler_set_SecurityHeader(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLWSSSignatureHandler::set_SecurityHeader(TElXMLWSSESecurity *Value)
{
	SBCheckError(TElXMLWSSSignatureHandler_set_SecurityHeader(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLWSSESECURITY */

void TElXMLWSSSignatureHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLWSSESECURITY
	this->_Inst_SecurityHeader = NULL;
#endif /* SB_USE_CLASS_TELXMLWSSESECURITY */
}

TElXMLWSSSignatureHandler::TElXMLWSSSignatureHandler(TElXMLWSSSignatureHandlerHandle handle, TElOwnHandle ownHandle) : TElXMLSOAPBaseSignatureHandler(handle, ownHandle)
{
	initInstances();
}

TElXMLWSSSignatureHandler::TElXMLWSSSignatureHandler(TComponent &Owner) : TElXMLSOAPBaseSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSSSignatureHandler_Create(Owner.getHandle(), &_Handle));
}

TElXMLWSSSignatureHandler::TElXMLWSSSignatureHandler(TComponent *Owner) : TElXMLSOAPBaseSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLWSSSignatureHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElXMLWSSSignatureHandler::~TElXMLWSSSignatureHandler()
{
#ifdef SB_USE_CLASS_TELXMLWSSESECURITY
	delete this->_Inst_SecurityHeader;
	this->_Inst_SecurityHeader = NULL;
#endif /* SB_USE_CLASS_TELXMLWSSESECURITY */
}
#endif /* SB_USE_CLASS_TELXMLWSSSIGNATUREHANDLER */

};	/* namespace SecureBlackbox */

