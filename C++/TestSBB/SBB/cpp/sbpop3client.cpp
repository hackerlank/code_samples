#include "sbpop3client.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPOP3CLIENT

SB_INLINE void TElPOP3Client::Close(bool Silent)
{
	SBCheckError(TElPOP3Client_Close(_Handle, (int8_t)Silent));
}

SB_INLINE void TElPOP3Client::DeleteMessage(int32_t Index)
{
	SBCheckError(TElPOP3Client_DeleteMessage(_Handle, Index));
}

SB_INLINE void TElPOP3Client::GetCapabilities()
{
	SBCheckError(TElPOP3Client_GetCapabilities(_Handle));
}

SB_INLINE void TElPOP3Client::GetMailboxInfo(int32_t &Messages, int64_t &TotalSize)
{
	SBCheckError(TElPOP3Client_GetMailboxInfo(_Handle, &Messages, &TotalSize));
}

SB_INLINE int64_t TElPOP3Client::GetMailboxSize()
{
	int64_t OutResult;
	SBCheckError(TElPOP3Client_GetMailboxSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPOP3Client::GetMessageCount()
{
	int32_t OutResult;
	SBCheckError(TElPOP3Client_GetMessageCount(_Handle, &OutResult));
	return OutResult;
}

void TElPOP3Client::GetMessageID(int32_t Index, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPOP3Client_GetMessageID(_Handle, Index, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1842305015, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPOP3Client::GetMessageIDList(std::vector<TSBPOP3MessageID> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size() * 8;
	uint32_t _err = TElPOP3Client_GetMessageIDList(_Handle, (TSBPOP3MessageID *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult / 8);
		SBCheckError(SBGetLastReturnBuffer(488126859, 1, (TSBPOP3MessageID *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult / 8);
}

void TElPOP3Client::GetMessageList(std::vector<TSBPOP3MessageSize> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size() * 12;
	uint32_t _err = TElPOP3Client_GetMessageList(_Handle, (TSBPOP3MessageSize *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult / 12);
		SBCheckError(SBGetLastReturnBuffer(302750217, 1, (TSBPOP3MessageSize *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult / 12);
}

SB_INLINE int64_t TElPOP3Client::GetMessageSize(int32_t Index)
{
	int64_t OutResult;
	SBCheckError(TElPOP3Client_GetMessageSize(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElPOP3Client::Login()
{
	SBCheckError(TElPOP3Client_Login(_Handle));
}

SB_INLINE void TElPOP3Client::Open()
{
	SBCheckError(TElPOP3Client_Open(_Handle));
}

SB_INLINE void TElPOP3Client::Noop()
{
	SBCheckError(TElPOP3Client_Noop(_Handle));
}

SB_INLINE void TElPOP3Client::Ping()
{
	SBCheckError(TElPOP3Client_Ping(_Handle));
}

SB_INLINE void TElPOP3Client::ReceiveMessage(int32_t Index)
{
	SBCheckError(TElPOP3Client_ReceiveMessage(_Handle, Index));
}

SB_INLINE int32_t TElPOP3Client::ReceiveMessage(int32_t Index, const std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElPOP3Client_ReceiveMessage_1(_Handle, Index, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Offset, Count, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPOP3Client::ReceiveMessage(int32_t Index, TStream &Stream)
{
	SBCheckError(TElPOP3Client_ReceiveMessage_2(_Handle, Index, Stream.getHandle()));
}

SB_INLINE void TElPOP3Client::ReceiveMessage(int32_t Index, TStream *Stream)
{
	SBCheckError(TElPOP3Client_ReceiveMessage_2(_Handle, Index, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELMESSAGE
int32_t TElPOP3Client::ReceiveMessage(int32_t Index, const std::string &HeaderCharset, const std::string &BodyCharset, TElMessageParsingOptions Options, bool IgnoreHeaderNativeCharset, bool IgnoreBodyNativeCharset, bool ActivatePartHandlers, TElMessage &Message)
{
	int32_t OutResult;
	TElClassHandle hMessage = SB_NULL_HANDLE;
	SBCheckError(TElPOP3Client_ReceiveMessage_3(_Handle, Index, HeaderCharset.data(), (int32_t)HeaderCharset.length(), BodyCharset.data(), (int32_t)BodyCharset.length(), (TElMessageParsingOptionsRaw)Options, (int8_t)IgnoreHeaderNativeCharset, (int8_t)IgnoreBodyNativeCharset, (int8_t)ActivatePartHandlers, &hMessage, &OutResult));
	Message.updateHandle(hMessage);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELMESSAGE */

#ifdef SB_USE_CLASS_TELMESSAGEHEADER
int32_t TElPOP3Client::ReceiveMessageHeader(int32_t Index, std::string &Charset, bool IgnoreNativeCharset, TElMessageHeader &Header)
{
	int32_t OutResult;
	int32_t szCharset = (int32_t)Charset.length();
	TElClassHandle hHeader = SB_NULL_HANDLE;
	uint32_t _err = TElPOP3Client_ReceiveMessageHeader(_Handle, Index, (char *)Charset.data(), &szCharset, (int8_t)IgnoreNativeCharset, &hHeader, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Charset.resize(szCharset);
		SBCheckError(SBGetLastReturnStringA(311591661, 2, (char *)Charset.data(), &szCharset));
	}
	else
		SBCheckError(_err);

	Charset.resize(szCharset);
	Header.updateHandle(hHeader);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELMESSAGEHEADER */

SB_INLINE void TElPOP3Client::ReceiveMessageIDList()
{
	SBCheckError(TElPOP3Client_ReceiveMessageIDList(_Handle));
}

SB_INLINE void TElPOP3Client::ReceiveMessageLines(int32_t Index, int32_t LineCount)
{
	SBCheckError(TElPOP3Client_ReceiveMessageLines(_Handle, Index, LineCount));
}

SB_INLINE int32_t TElPOP3Client::ReceiveMessageLines(int32_t Index, int32_t LineCount, const std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElPOP3Client_ReceiveMessageLines_1(_Handle, Index, LineCount, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Offset, Count, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPOP3Client::ReceiveMessageLines(int32_t Index, int32_t LineCount, TStream &Stream)
{
	SBCheckError(TElPOP3Client_ReceiveMessageLines_2(_Handle, Index, LineCount, Stream.getHandle()));
}

SB_INLINE void TElPOP3Client::ReceiveMessageLines(int32_t Index, int32_t LineCount, TStream *Stream)
{
	SBCheckError(TElPOP3Client_ReceiveMessageLines_2(_Handle, Index, LineCount, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPOP3Client::ReceiveMessageList()
{
	SBCheckError(TElPOP3Client_ReceiveMessageList(_Handle));
}

SB_INLINE void TElPOP3Client::Reset()
{
	SBCheckError(TElPOP3Client_Reset(_Handle));
}

SB_INLINE void TElPOP3Client::Undelete()
{
	SBCheckError(TElPOP3Client_Undelete(_Handle));
}

bool TElPOP3Client::get_SASLMechanism(const std::string &Name)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPOP3Client_get_SASLMechanism(_Handle, Name.data(), (int32_t)Name.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPOP3Client::set_SASLMechanism(const std::string &Name, bool Value)
{
	SBCheckError(TElPOP3Client_set_SASLMechanism(_Handle, Name.data(), (int32_t)Name.length(), (int8_t)Value));
}

SB_INLINE int32_t TElPOP3Client::get_SASLMechanismPriorities(const std::string &Name)
{
	int32_t OutResult;
	SBCheckError(TElPOP3Client_get_SASLMechanismPriorities(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}

SB_INLINE void TElPOP3Client::set_SASLMechanismPriorities(const std::string &Name, int32_t Value)
{
	SBCheckError(TElPOP3Client_set_SASLMechanismPriorities(_Handle, Name.data(), (int32_t)Name.length(), Value));
}

SB_INLINE int32_t TElPOP3Client::get_AuthorizationPriorities(TSBPOP3Authorization Auth)
{
	int32_t OutResult;
	SBCheckError(TElPOP3Client_get_AuthorizationPriorities(_Handle, (TSBPOP3AuthorizationRaw)Auth, &OutResult));
	return OutResult;
}

SB_INLINE void TElPOP3Client::set_AuthorizationPriorities(TSBPOP3Authorization Auth, int32_t Value)
{
	SBCheckError(TElPOP3Client_set_AuthorizationPriorities(_Handle, (TSBPOP3AuthorizationRaw)Auth, Value));
}

bool TElPOP3Client::get_Authorization(TSBPOP3Authorization Auth)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPOP3Client_get_Authorization(_Handle, (TSBPOP3AuthorizationRaw)Auth, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPOP3Client::set_Authorization(TSBPOP3Authorization Auth, bool Value)
{
	SBCheckError(TElPOP3Client_set_Authorization(_Handle, (TSBPOP3AuthorizationRaw)Auth, (int8_t)Value));
}

bool TElPOP3Client::get_ExtAPOPSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPOP3Client_get_ExtAPOPSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPOP3Client::get_ExtUIDLSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPOP3Client_get_ExtUIDLSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPOP3Client::get_ExtUSERSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPOP3Client_get_ExtUSERSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPOP3Client::get_ExtTOPSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPOP3Client_get_ExtTOPSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPOP3Client::get_ExtRESP_CODESSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPOP3Client_get_ExtRESP_CODESSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPOP3Client::get_ExtLOGIN_DELAYSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPOP3Client_get_ExtLOGIN_DELAYSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPOP3Client::get_ExtEXPIRESupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPOP3Client_get_ExtEXPIRESupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPOP3Client::get_ExtIMPLEMENTATIONSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPOP3Client_get_ExtIMPLEMENTATIONSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPOP3Client::get_ExtSASLSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPOP3Client_get_ExtSASLSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPOP3Client::get_ExtSASLMechanisms(TStringList &OutResult)
{
	SBCheckError(TElPOP3Client_get_ExtSASLMechanisms(_Handle, OutResult.getHandle()));
}

SB_INLINE int32_t TElPOP3Client::get_ExtExpire()
{
	int32_t OutResult;
	SBCheckError(TElPOP3Client_get_ExtExpire(_Handle, &OutResult));
	return OutResult;
}

bool TElPOP3Client::get_ExtExpireUserChangeable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPOP3Client_get_ExtExpireUserChangeable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElPOP3Client::get_ExtLoginDelay()
{
	int32_t OutResult;
	SBCheckError(TElPOP3Client_get_ExtLoginDelay(_Handle, &OutResult));
	return OutResult;
}

void TElPOP3Client::get_ExtImplementation(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPOP3Client_get_ExtImplementation(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2002267818, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElPOP3Client::get_SSLActive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPOP3Client_get_SSLActive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPOP3Client::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPOP3Client_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-61109148, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPOP3Client::set_Address(const std::string &Value)
{
	SBCheckError(TElPOP3Client_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBPOP3AutoCAPAMode TElPOP3Client::get_AutoCAPA()
{
	TSBPOP3AutoCAPAModeRaw OutResultRaw = 0;
	SBCheckError(TElPOP3Client_get_AutoCAPA(_Handle, &OutResultRaw));
	return (TSBPOP3AutoCAPAMode)OutResultRaw;
}

SB_INLINE void TElPOP3Client::set_AutoCAPA(TSBPOP3AutoCAPAMode Value)
{
	SBCheckError(TElPOP3Client_set_AutoCAPA(_Handle, (TSBPOP3AutoCAPAModeRaw)Value));
}

SB_INLINE int32_t TElPOP3Client::get_MaxLineLength()
{
	int32_t OutResult;
	SBCheckError(TElPOP3Client_get_MaxLineLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPOP3Client::set_MaxLineLength(int32_t Value)
{
	SBCheckError(TElPOP3Client_set_MaxLineLength(_Handle, Value));
}

SB_INLINE int32_t TElPOP3Client::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElPOP3Client_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPOP3Client::set_Port(int32_t Value)
{
	SBCheckError(TElPOP3Client_set_Port(_Handle, Value));
}

TSBSSLMode TElPOP3Client::get_SSLMode()
{
	TSBSSLModeRaw OutResultRaw = 0;
	SBCheckError(TElPOP3Client_get_SSLMode(_Handle, &OutResultRaw));
	return (TSBSSLMode)OutResultRaw;
}

SB_INLINE void TElPOP3Client::set_SSLMode(TSBSSLMode Value)
{
	SBCheckError(TElPOP3Client_set_SSLMode(_Handle, (TSBSSLModeRaw)Value));
}

#ifdef SB_WINDOWS
bool TElPOP3Client::get_UseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPOP3Client_get_UseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPOP3Client::set_UseIPv6(bool Value)
{
	SBCheckError(TElPOP3Client_set_UseIPv6(_Handle, (int8_t)Value));
}
#endif

bool TElPOP3Client::get_UseSSL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPOP3Client_get_UseSSL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPOP3Client::set_UseSSL(bool Value)
{
	SBCheckError(TElPOP3Client_set_UseSSL(_Handle, (int8_t)Value));
}

void TElPOP3Client::get_Username(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPOP3Client_get_Username(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-87168274, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPOP3Client::set_Username(const std::string &Value)
{
	SBCheckError(TElPOP3Client_set_Username(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPOP3Client::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPOP3Client_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(928098892, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPOP3Client::set_Password(const std::string &Value)
{
	SBCheckError(TElPOP3Client_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElPOP3Client::get_OnCapability(TSBPOP3TextLineEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPOP3Client_get_OnCapability(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPOP3Client::set_OnCapability(TSBPOP3TextLineEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPOP3Client_set_OnCapability(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPOP3Client::get_OnLog(TSBPOP3LogEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPOP3Client_get_OnLog(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPOP3Client::set_OnLog(TSBPOP3LogEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPOP3Client_set_OnLog(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPOP3Client::get_OnMessageLine(TSBPOP3TextLineEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPOP3Client_get_OnMessageLine(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPOP3Client::set_OnMessageLine(TSBPOP3TextLineEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPOP3Client_set_OnMessageLine(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPOP3Client::get_OnMessageID(TSBPOP3MessageIdEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPOP3Client_get_OnMessageID(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPOP3Client::set_OnMessageID(TSBPOP3MessageIdEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPOP3Client_set_OnMessageID(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPOP3Client::get_OnMessageSize(TSBPOP3MessageSizeEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPOP3Client_get_OnMessageSize(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPOP3Client::set_OnMessageSize(TSBPOP3MessageSizeEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPOP3Client_set_OnMessageSize(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPOP3Client::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPOP3Client_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPOP3Client::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPOP3Client_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPOP3Client::get_OnCertificateChoose(TSBChooseCertificateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPOP3Client_get_OnCertificateChoose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPOP3Client::set_OnCertificateChoose(TSBChooseCertificateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPOP3Client_set_OnCertificateChoose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPOP3Client::get_OnCertificateNeededEx(TSBCertificateNeededExEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPOP3Client_get_OnCertificateNeededEx(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPOP3Client::set_OnCertificateNeededEx(TSBCertificateNeededExEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPOP3Client_set_OnCertificateNeededEx(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPOP3Client::get_OnCertificateValidate(TSBCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPOP3Client_get_OnCertificateValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPOP3Client::set_OnCertificateValidate(TSBCertificateValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPOP3Client_set_OnCertificateValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPOP3Client::get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPOP3Client_get_OnCiphersNegotiated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPOP3Client::set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPOP3Client_set_OnCiphersNegotiated(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPOP3Client::get_OnCloseConnection(TSBCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPOP3Client_get_OnCloseConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPOP3Client::set_OnCloseConnection(TSBCloseConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPOP3Client_set_OnCloseConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPOP3Client::get_OnError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPOP3Client_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPOP3Client::set_OnError(TSBErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPOP3Client_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPOP3Client::get_OnExtensionsReceived(TSBExtensionsReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPOP3Client_get_OnExtensionsReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPOP3Client::set_OnExtensionsReceived(TSBExtensionsReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPOP3Client_set_OnExtensionsReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPOP3Client::get_OnExtensionsPrepared(TSBExtensionsPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPOP3Client_get_OnExtensionsPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPOP3Client::set_OnExtensionsPrepared(TSBExtensionsPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPOP3Client_set_OnExtensionsPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPOP3Client::get_OnCertificateStatus(TSBCertificateStatusEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPOP3Client_get_OnCertificateStatus(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPOP3Client::set_OnCertificateStatus(TSBCertificateStatusEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPOP3Client_set_OnCertificateStatus(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPOP3Client::get_OnKeyNeeded(TSBClientKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPOP3Client_get_OnKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPOP3Client::set_OnKeyNeeded(TSBClientKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPOP3Client_set_OnKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPOP3Client::get_OnRenegotiationRequest(TSBRenegotiationRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPOP3Client_get_OnRenegotiationRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPOP3Client::set_OnRenegotiationRequest(TSBRenegotiationRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPOP3Client_set_OnRenegotiationRequest(_Handle, pMethodValue, pDataValue));
}

#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_INLINE void TElPOP3Client::get_OnDNSKeyNeeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPOP3Client_get_OnDNSKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPOP3Client::set_OnDNSKeyNeeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPOP3Client_set_OnDNSKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPOP3Client::get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPOP3Client_get_OnDNSKeyValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPOP3Client::set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPOP3Client_set_OnDNSKeyValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPOP3Client::get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPOP3Client_get_OnDNSResolve(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPOP3Client::set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPOP3Client_set_OnDNSResolve(_Handle, pMethodValue, pDataValue));
}
#endif

TElPOP3Client::TElPOP3Client(TElPOP3ClientHandle handle, TElOwnHandle ownHandle) : TElCustomSimpleSSLClient(handle, ownHandle)
{
}

TElPOP3Client::TElPOP3Client(TComponent &AOwner) : TElCustomSimpleSSLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPOP3Client_Create(AOwner.getHandle(), &_Handle));
}

TElPOP3Client::TElPOP3Client(TComponent *AOwner) : TElCustomSimpleSSLClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPOP3Client_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELPOP3CLIENT */

};	/* namespace SecureBlackbox */
