#include "sbsmtpclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSMTPCLIENT

SB_INLINE void TElSMTPClient::Close(bool Silent)
{
	SBCheckError(TElSMTPClient_Close(_Handle, (int8_t)Silent));
}

SB_INLINE void TElSMTPClient::Open()
{
	SBCheckError(TElSMTPClient_Open(_Handle));
}

SB_INLINE void TElSMTPClient::EstablishSSLSession()
{
	SBCheckError(TElSMTPClient_EstablishSSLSession(_Handle));
}

SB_INLINE void TElSMTPClient::Login(const std::string &Domain)
{
	SBCheckError(TElSMTPClient_Login(_Handle, Domain.data(), (int32_t)Domain.length()));
}

#ifdef SB_USE_CLASS_TELMESSAGE
SB_INLINE void TElSMTPClient::Send(TElMessage &Message)
{
	SBCheckError(TElSMTPClient_Send(_Handle, Message.getHandle()));
}

SB_INLINE void TElSMTPClient::Send(TElMessage *Message)
{
	SBCheckError(TElSMTPClient_Send(_Handle, (Message != NULL) ? Message->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELMESSAGE */

#ifdef SB_USE_CLASS_TELSIMPLEMIMEMESSAGE
SB_INLINE void TElSMTPClient::Send(TElSimpleMIMEMessage &Message)
{
	SBCheckError(TElSMTPClient_Send_1(_Handle, Message.getHandle()));
}

SB_INLINE void TElSMTPClient::Send(TElSimpleMIMEMessage *Message)
{
	SBCheckError(TElSMTPClient_Send_1(_Handle, (Message != NULL) ? Message->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSIMPLEMIMEMESSAGE */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElSMTPClient::Send(const std::string &MailFrom, TStringList &RcptTo, TStringList &Message)
{
	SBCheckError(TElSMTPClient_Send_2(_Handle, MailFrom.data(), (int32_t)MailFrom.length(), RcptTo.getHandle(), Message.getHandle()));
}

SB_INLINE void TElSMTPClient::Send(const std::string &MailFrom, TStringList *RcptTo, TStringList *Message)
{
	SBCheckError(TElSMTPClient_Send_2(_Handle, MailFrom.data(), (int32_t)MailFrom.length(), (RcptTo != NULL) ? RcptTo->getHandle() : SB_NULL_HANDLE, (Message != NULL) ? Message->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElSMTPClient::Send(const std::string &MailFrom, TElStringList &RcptTo, TElStringList &Message)
{
	SBCheckError(TElSMTPClient_Send_2(_Handle, MailFrom.data(), (int32_t)MailFrom.length(), RcptTo.getHandle(), Message.getHandle()));
}

SB_INLINE void TElSMTPClient::Send(const std::string &MailFrom, TElStringList *RcptTo, TElStringList *Message)
{
	SBCheckError(TElSMTPClient_Send_2(_Handle, MailFrom.data(), (int32_t)MailFrom.length(), (RcptTo != NULL) ? RcptTo->getHandle() : SB_NULL_HANDLE, (Message != NULL) ? Message->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElSMTPClient::Send(const std::string &MailFrom, TStringList &RcptTo, TStream &Message)
{
	SBCheckError(TElSMTPClient_Send_3(_Handle, MailFrom.data(), (int32_t)MailFrom.length(), RcptTo.getHandle(), Message.getHandle()));
}

SB_INLINE void TElSMTPClient::Send(const std::string &MailFrom, TStringList *RcptTo, TStream *Message)
{
	SBCheckError(TElSMTPClient_Send_3(_Handle, MailFrom.data(), (int32_t)MailFrom.length(), (RcptTo != NULL) ? RcptTo->getHandle() : SB_NULL_HANDLE, (Message != NULL) ? Message->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TSTREAM_AND_TSTRINGLIST */
#else
#ifdef SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM
SB_INLINE void TElSMTPClient::Send(const std::string &MailFrom, TElStringList &RcptTo, TStream &Message)
{
	SBCheckError(TElSMTPClient_Send_3(_Handle, MailFrom.data(), (int32_t)MailFrom.length(), RcptTo.getHandle(), Message.getHandle()));
}

SB_INLINE void TElSMTPClient::Send(const std::string &MailFrom, TElStringList *RcptTo, TStream *Message)
{
	SBCheckError(TElSMTPClient_Send_3(_Handle, MailFrom.data(), (int32_t)MailFrom.length(), (RcptTo != NULL) ? RcptTo->getHandle() : SB_NULL_HANDLE, (Message != NULL) ? Message->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELSTRINGLIST_AND_TSTREAM */
#endif

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSMTPClient::Send(TStream &Message)
{
	SBCheckError(TElSMTPClient_Send_4(_Handle, Message.getHandle()));
}

SB_INLINE void TElSMTPClient::Send(TStream *Message)
{
	SBCheckError(TElSMTPClient_Send_4(_Handle, (Message != NULL) ? Message->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElSMTPClient::get_SASLMechanism(const std::string &Name)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSMTPClient_get_SASLMechanism(_Handle, Name.data(), (int32_t)Name.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSMTPClient::set_SASLMechanism(const std::string &Name, bool Value)
{
	SBCheckError(TElSMTPClient_set_SASLMechanism(_Handle, Name.data(), (int32_t)Name.length(), (int8_t)Value));
}

SB_INLINE int32_t TElSMTPClient::get_SASLMechanismPriorities(const std::string &Name)
{
	int32_t OutResult;
	SBCheckError(TElSMTPClient_get_SASLMechanismPriorities(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}

SB_INLINE void TElSMTPClient::set_SASLMechanismPriorities(const std::string &Name, int32_t Value)
{
	SBCheckError(TElSMTPClient_set_SASLMechanismPriorities(_Handle, Name.data(), (int32_t)Name.length(), Value));
}

SB_INLINE void TElSMTPClient::get_ExtSASLMechanisms(TStringList &OutResult)
{
	SBCheckError(TElSMTPClient_get_ExtSASLMechanisms(_Handle, OutResult.getHandle()));
}

bool TElSMTPClient::get_ExtensionChunkingSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSMTPClient_get_ExtensionChunkingSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSMTPClient::get_ExtensionBinarySupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSMTPClient_get_ExtensionBinarySupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSMTPClient::get_ExtensionAuthPlainSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSMTPClient_get_ExtensionAuthPlainSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSMTPClient::get_ExtensionAuthLoginSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSMTPClient_get_ExtensionAuthLoginSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSMTPClient::get_ExtensionSASLLoginSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSMTPClient_get_ExtensionSASLLoginSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSMTPClient::get_ExtensionSizeSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSMTPClient_get_ExtensionSizeSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSMTPClient::get_ExtensionDSNSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSMTPClient_get_ExtensionDSNSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSMTPClient::get_SSLActive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSMTPClient_get_SSLActive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElSMTPClient::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSMTPClient_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-146115816, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSMTPClient::set_Address(const std::string &Value)
{
	SBCheckError(TElSMTPClient_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSMTPClient::get_AllowAuthentication()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSMTPClient_get_AllowAuthentication(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSMTPClient::set_AllowAuthentication(bool Value)
{
	SBCheckError(TElSMTPClient_set_AllowAuthentication(_Handle, (int8_t)Value));
}

bool TElSMTPClient::get_AllowBinaryMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSMTPClient_get_AllowBinaryMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSMTPClient::set_AllowBinaryMode(bool Value)
{
	SBCheckError(TElSMTPClient_set_AllowBinaryMode(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElSMTPClient::get_BinaryChunkSize()
{
	int32_t OutResult;
	SBCheckError(TElSMTPClient_get_BinaryChunkSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSMTPClient::set_BinaryChunkSize(int32_t Value)
{
	SBCheckError(TElSMTPClient_set_BinaryChunkSize(_Handle, Value));
}

void TElSMTPClient::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSMTPClient_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1860798116, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSMTPClient::set_Password(const std::string &Value)
{
	SBCheckError(TElSMTPClient_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSMTPClient::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElSMTPClient_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSMTPClient::set_Port(int32_t Value)
{
	SBCheckError(TElSMTPClient_set_Port(_Handle, Value));
}

bool TElSMTPClient::get_RemoveBCC()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSMTPClient_get_RemoveBCC(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSMTPClient::set_RemoveBCC(bool Value)
{
	SBCheckError(TElSMTPClient_set_RemoveBCC(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElSMTPClient::get_SendBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElSMTPClient_get_SendBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSMTPClient::set_SendBufferSize(int32_t Value)
{
	SBCheckError(TElSMTPClient_set_SendBufferSize(_Handle, Value));
}

TSBSSLMode TElSMTPClient::get_SSLMode()
{
	TSBSSLModeRaw OutResultRaw = 0;
	SBCheckError(TElSMTPClient_get_SSLMode(_Handle, &OutResultRaw));
	return (TSBSSLMode)OutResultRaw;
}

SB_INLINE void TElSMTPClient::set_SSLMode(TSBSSLMode Value)
{
	SBCheckError(TElSMTPClient_set_SSLMode(_Handle, (TSBSSLModeRaw)Value));
}

bool TElSMTPClient::get_UseSSL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSMTPClient_get_UseSSL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSMTPClient::set_UseSSL(bool Value)
{
	SBCheckError(TElSMTPClient_set_UseSSL(_Handle, (int8_t)Value));
}

void TElSMTPClient::get_Username(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSMTPClient_get_Username(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1552562682, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSMTPClient::set_Username(const std::string &Value)
{
	SBCheckError(TElSMTPClient_set_Username(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBSMTPDSNOptions TElSMTPClient::get_DSNOptions()
{
	TSBSMTPDSNOptionsRaw OutResultRaw = 0;
	SBCheckError(TElSMTPClient_get_DSNOptions(_Handle, &OutResultRaw));
	return (TSBSMTPDSNOptions)OutResultRaw;
}

SB_INLINE void TElSMTPClient::set_DSNOptions(TSBSMTPDSNOptions Value)
{
	SBCheckError(TElSMTPClient_set_DSNOptions(_Handle, (TSBSMTPDSNOptionsRaw)Value));
}

TSBSMTPDSNReturnType TElSMTPClient::get_DSNReturnType()
{
	TSBSMTPDSNReturnTypeRaw OutResultRaw = 0;
	SBCheckError(TElSMTPClient_get_DSNReturnType(_Handle, &OutResultRaw));
	return (TSBSMTPDSNReturnType)OutResultRaw;
}

SB_INLINE void TElSMTPClient::set_DSNReturnType(TSBSMTPDSNReturnType Value)
{
	SBCheckError(TElSMTPClient_set_DSNReturnType(_Handle, (TSBSMTPDSNReturnTypeRaw)Value));
}

SB_INLINE void TElSMTPClient::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSMTPClient_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSMTPClient::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSMTPClient_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSMTPClient::get_OnDSNEnvIDGenerate(TSBSMTPDSNEnvIDGenerateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSMTPClient_get_OnDSNEnvIDGenerate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSMTPClient::set_OnDSNEnvIDGenerate(TSBSMTPDSNEnvIDGenerateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSMTPClient_set_OnDSNEnvIDGenerate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSMTPClient::get_OnDSNOptions(TSBSMTPDSNOptionsEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSMTPClient_get_OnDSNOptions(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSMTPClient::set_OnDSNOptions(TSBSMTPDSNOptionsEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSMTPClient_set_OnDSNOptions(_Handle, pMethodValue, pDataValue));
}

TElSMTPClient::TElSMTPClient(TElSMTPClientHandle handle, TElOwnHandle ownHandle) : TElCommandSSLClient(handle, ownHandle)
{
}

TElSMTPClient::TElSMTPClient(TComponent &AOwner) : TElCommandSSLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSMTPClient_Create(AOwner.getHandle(), &_Handle));
}

TElSMTPClient::TElSMTPClient(TComponent *AOwner) : TElCommandSSLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSMTPClient_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSMTPCLIENT */

};	/* namespace SecureBlackbox */
