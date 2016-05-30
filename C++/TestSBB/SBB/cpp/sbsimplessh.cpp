#include "sbsimplessh.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSIMPLESSHCLIENT

SB_INLINE void TElSimpleSSHClient::Interrupt()
{
	SBCheckError(TElSimpleSSHClient_Interrupt(_Handle));
}

SB_INLINE void TElSimpleSSHClient::Close()
{
	SBCheckError(TElSimpleSSHClient_Close(_Handle));
}

SB_INLINE void TElSimpleSSHClient::Close(bool FlushPendingData)
{
	SBCheckError(TElSimpleSSHClient_Close_1(_Handle, (int8_t)FlushPendingData));
}

SB_INLINE void TElSimpleSSHClient::Open()
{
	SBCheckError(TElSimpleSSHClient_Open(_Handle));
}

SB_INLINE void TElSimpleSSHClient::RenegotiateCiphers()
{
	SBCheckError(TElSimpleSSHClient_RenegotiateCiphers(_Handle));
}

SB_INLINE void TElSimpleSSHClient::SendData(void * Buffer, int32_t Size)
{
	SBCheckError(TElSimpleSSHClient_SendData(_Handle, Buffer, Size));
}

SB_INLINE void TElSimpleSSHClient::ReceiveData(void * Buffer, int32_t &Size, void * StdErrBuffer, int32_t &StdErrSize)
{
	SBCheckError(TElSimpleSSHClient_ReceiveData(_Handle, Buffer, &Size, StdErrBuffer, &StdErrSize));
}

SB_INLINE void TElSimpleSSHClient::SendText(const std::string &S)
{
	SBCheckError(TElSimpleSSHClient_SendText(_Handle, S.data(), (int32_t)S.length()));
}

void TElSimpleSSHClient::ReceiveText(std::string &Text, std::string &StdErrText)
{
	int32_t szText = (int32_t)Text.length();
	int32_t szStdErrText = (int32_t)StdErrText.length();
	uint32_t _err = TElSimpleSSHClient_ReceiveText(_Handle, (char *)Text.data(), &szText, (char *)StdErrText.data(), &szStdErrText);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Text.resize(szText);
		SBCheckError(SBGetLastReturnStringA(1607337176, 1, (char *)Text.data(), &szText));
		StdErrText.resize(szStdErrText);
		SBCheckError(SBGetLastReturnStringA(1607337176, 2, (char *)StdErrText.data(), &szStdErrText));
	}
	else
		SBCheckError(_err);

	Text.resize(szText);
	StdErrText.resize(szStdErrText);
}

void TElSimpleSSHClient::ReceiveText(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_ReceiveText_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1147857215, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElSimpleSSHClient::CanReceive(int32_t Timeout)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_CanReceive(_Handle, Timeout, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::SendKeepAlive()
{
	SBCheckError(TElSimpleSSHClient_SendKeepAlive(_Handle));
}

void TElSimpleSSHClient::ExecuteCommand(const std::string &Cmd, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSimpleSSHClient_ExecuteCommand(_Handle, Cmd.data(), (int32_t)Cmd.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-470151775, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSimpleSSHClient::ExecuteCommand(const std::string &Cmd, bool RedirectStdErr, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSimpleSSHClient_ExecuteCommand_1(_Handle, Cmd.data(), (int32_t)Cmd.length(), (int8_t)RedirectStdErr, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1315075745, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSimpleSSHClient::ExecuteCommand(const std::string &Cmd, std::vector<uint8_t> &StdErrData, std::vector<uint8_t> &OutResult)
{
	int32_t szStdErrData = (int32_t)StdErrData.size();
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSimpleSSHClient_ExecuteCommand_2(_Handle, Cmd.data(), (int32_t)Cmd.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(StdErrData), &szStdErrData, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		StdErrData.resize(szStdErrData);
		SBCheckError(SBGetLastReturnBuffer(2012717520, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(StdErrData), &szStdErrData));
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2012717520, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	StdErrData.resize(szStdErrData);
	OutResult.resize(szOutResult);
}

void TElSimpleSSHClient::ExecuteCommand(const std::string &Cmd, bool RedirectStdErr, bool KeepConnectionOpen, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSimpleSSHClient_ExecuteCommand_3(_Handle, Cmd.data(), (int32_t)Cmd.length(), (int8_t)RedirectStdErr, (int8_t)KeepConnectionOpen, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-644924039, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSimpleSSHClient::ExecuteCommand(const std::string &Cmd, std::vector<uint8_t> &StdErrData, bool KeepConnectionOpen, std::vector<uint8_t> &OutResult)
{
	int32_t szStdErrData = (int32_t)StdErrData.size();
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSimpleSSHClient_ExecuteCommand_4(_Handle, Cmd.data(), (int32_t)Cmd.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(StdErrData), &szStdErrData, (int8_t)KeepConnectionOpen, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		StdErrData.resize(szStdErrData);
		SBCheckError(SBGetLastReturnBuffer(915131579, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(StdErrData), &szStdErrData));
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(915131579, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	StdErrData.resize(szStdErrData);
	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHClient::SendEOF()
{
	SBCheckError(TElSimpleSSHClient_SendEOF(_Handle));
}

bool TElSimpleSSHClient::get_EncryptionAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_EncryptionAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_EncryptionAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_EncryptionAlgorithms(_Handle, Index, (int8_t)Value));
}

bool TElSimpleSSHClient::get_CompressionAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_CompressionAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_CompressionAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_CompressionAlgorithms(_Handle, Index, (int8_t)Value));
}

bool TElSimpleSSHClient::get_MacAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_MacAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_MacAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_MacAlgorithms(_Handle, Index, (int8_t)Value));
}

bool TElSimpleSSHClient::get_KexAlgorithms(int8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_KexAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_KexAlgorithms(int8_t Index, bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_KexAlgorithms(_Handle, Index, (int8_t)Value));
}

bool TElSimpleSSHClient::get_PublicKeyAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_PublicKeyAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_PublicKeyAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_PublicKeyAlgorithms(_Handle, Index, (int8_t)Value));
}

SB_INLINE int32_t TElSimpleSSHClient::get_EncryptionAlgorithmPriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_EncryptionAlgorithmPriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHClient::set_EncryptionAlgorithmPriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElSimpleSSHClient_set_EncryptionAlgorithmPriorities(_Handle, Index, Value));
}

SB_INLINE int32_t TElSimpleSSHClient::get_CompressionAlgorithmPriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_CompressionAlgorithmPriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHClient::set_CompressionAlgorithmPriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElSimpleSSHClient_set_CompressionAlgorithmPriorities(_Handle, Index, Value));
}

SB_INLINE int32_t TElSimpleSSHClient::get_MacAlgorithmPriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_MacAlgorithmPriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHClient::set_MacAlgorithmPriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElSimpleSSHClient_set_MacAlgorithmPriorities(_Handle, Index, Value));
}

SB_INLINE int32_t TElSimpleSSHClient::get_KexAlgorithmPriorities(int8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_KexAlgorithmPriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHClient::set_KexAlgorithmPriorities(int8_t Index, int32_t Value)
{
	SBCheckError(TElSimpleSSHClient_set_KexAlgorithmPriorities(_Handle, Index, Value));
}

SB_INLINE int32_t TElSimpleSSHClient::get_PublicKeyAlgorithmPriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_PublicKeyAlgorithmPriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHClient::set_PublicKeyAlgorithmPriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElSimpleSSHClient_set_PublicKeyAlgorithmPriorities(_Handle, Index, Value));
}

SB_INLINE int32_t TElSimpleSSHClient::get_AuthTypePriorities(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_AuthTypePriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHClient::set_AuthTypePriorities(int32_t Index, int32_t Value)
{
	SBCheckError(TElSimpleSSHClient_set_AuthTypePriorities(_Handle, Index, Value));
}

bool TElSimpleSSHClient::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElSimpleSSHClient::get_ServerSoftwareName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_ServerSoftwareName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-626053166, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSSHVersion TElSimpleSSHClient::get_Version()
{
	TSSHVersionRaw OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_Version(_Handle, &OutResultRaw));
	return (TSSHVersion)OutResultRaw;
}

void TElSimpleSSHClient::get_ServerCloseReason(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_ServerCloseReason(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(671411282, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE uint8_t TElSimpleSSHClient::get_EncryptionAlgorithmServerToClient()
{
	uint8_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_EncryptionAlgorithmServerToClient(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSimpleSSHClient::get_EncryptionAlgorithmClientToServer()
{
	uint8_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_EncryptionAlgorithmClientToServer(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSimpleSSHClient::get_CompressionAlgorithmServerToClient()
{
	uint8_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_CompressionAlgorithmServerToClient(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSimpleSSHClient::get_CompressionAlgorithmClientToServer()
{
	uint8_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_CompressionAlgorithmClientToServer(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSimpleSSHClient::get_MacAlgorithmServerToClient()
{
	uint8_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_MacAlgorithmServerToClient(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSimpleSSHClient::get_MacAlgorithmClientToServer()
{
	uint8_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_MacAlgorithmClientToServer(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int8_t TElSimpleSSHClient::get_KexAlgorithm()
{
	int8_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_KexAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSimpleSSHClient::get_PublicKeyAlgorithm()
{
	uint8_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_PublicKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
TElSSHCustomKeyStorage* TElSimpleSSHClient::get_KeyStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHClient_get_KeyStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyStorage)
		this->_Inst_KeyStorage = new TElSSHCustomKeyStorage(hOutResult, ohFalse);
	else
		this->_Inst_KeyStorage->updateHandle(hOutResult);
	return this->_Inst_KeyStorage;
}

SB_INLINE void TElSimpleSSHClient::set_KeyStorage(TElSSHCustomKeyStorage &Value)
{
	SBCheckError(TElSimpleSSHClient_set_KeyStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSSHClient::set_KeyStorage(TElSSHCustomKeyStorage *Value)
{
	SBCheckError(TElSimpleSSHClient_set_KeyStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

#ifdef SB_USE_CLASS_TELTERMINALINFO
TElTerminalInfo* TElSimpleSSHClient::get_TerminalInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHClient_get_TerminalInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TerminalInfo)
		this->_Inst_TerminalInfo = new TElTerminalInfo(hOutResult, ohFalse);
	else
		this->_Inst_TerminalInfo->updateHandle(hOutResult);
	return this->_Inst_TerminalInfo;
}

SB_INLINE void TElSimpleSSHClient::set_TerminalInfo(TElTerminalInfo &Value)
{
	SBCheckError(TElSimpleSSHClient_set_TerminalInfo(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSSHClient::set_TerminalInfo(TElTerminalInfo *Value)
{
	SBCheckError(TElSimpleSSHClient_set_TerminalInfo(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELTERMINALINFO */

SB_INLINE int32_t TElSimpleSSHClient::get_ExitStatus()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_ExitStatus(_Handle, &OutResult));
	return OutResult;
}

void TElSimpleSSHClient::get_ExitSignal(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_ExitSignal(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-453260173, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSimpleSSHClient::get_ExitMessage(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_ExitMessage(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1626607294, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSimpleSSHClient::get_KbdIntName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_KbdIntName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1292439027, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSimpleSSHClient::get_KbdIntInstruction(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_KbdIntInstruction(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1344254168, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElSimpleSSHClient::get_ExtendedDataType()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_ExtendedDataType(_Handle, &OutResult));
	return OutResult;
}

bool TElSimpleSSHClient::get_RequestPasswordChange()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_RequestPasswordChange(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_RequestPasswordChange(bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_RequestPasswordChange(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELSSHKEY
TElSSHKey* TElSimpleSSHClient::get_ServerKey()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHClient_get_ServerKey(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ServerKey)
		this->_Inst_ServerKey = new TElSSHKey(hOutResult, ohFalse);
	else
		this->_Inst_ServerKey->updateHandle(hOutResult);
	return this->_Inst_ServerKey;
}
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_WINDOWS
bool TElSimpleSSHClient::get_UsingIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_UsingIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif

SB_INLINE int64_t TElSimpleSSHClient::get_TotalBytesSent()
{
	int64_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_TotalBytesSent(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElSimpleSSHClient::get_TotalBytesReceived()
{
	int64_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_TotalBytesReceived(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
TElGSSBaseMechanism* TElSimpleSSHClient::get_GSSMechanism()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHClient_get_GSSMechanism(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_GSSMechanism)
		this->_Inst_GSSMechanism = new TElGSSBaseMechanism(hOutResult, ohFalse);
	else
		this->_Inst_GSSMechanism->updateHandle(hOutResult);
	return this->_Inst_GSSMechanism;
}

SB_INLINE void TElSimpleSSHClient::set_GSSMechanism(TElGSSBaseMechanism &Value)
{
	SBCheckError(TElSimpleSSHClient_set_GSSMechanism(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSSHClient::set_GSSMechanism(TElGSSBaseMechanism *Value)
{
	SBCheckError(TElSimpleSSHClient_set_GSSMechanism(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */

void TElSimpleSSHClient::get_GSSHostName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_GSSHostName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(561749747, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHClient::set_GSSHostName(const std::string &Value)
{
	SBCheckError(TElSimpleSSHClient_set_GSSHostName(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSimpleSSHClient::get_GSSDelegateCredentials()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_GSSDelegateCredentials(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_GSSDelegateCredentials(bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_GSSDelegateCredentials(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELSOCKET
TElSocket* TElSimpleSSHClient::get_InternalSocket()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHClient_get_InternalSocket(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_InternalSocket)
		this->_Inst_InternalSocket = new TElSocket(hOutResult, ohFalse);
	else
		this->_Inst_InternalSocket->updateHandle(hOutResult);
	return this->_Inst_InternalSocket;
}
#endif /* SB_USE_CLASS_TELSOCKET */

void TElSimpleSSHClient::get_Command(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_Command(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1587102186, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHClient::set_Command(const std::string &Value)
{
	SBCheckError(TElSimpleSSHClient_set_Command(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSimpleSSHClient::get_Commands()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHClient_get_Commands(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Commands)
		this->_Inst_Commands = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Commands->updateHandle(hOutResult);
	return this->_Inst_Commands;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSimpleSSHClient::get_Commands()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHClient_get_Commands(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Commands)
		this->_Inst_Commands = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Commands->updateHandle(hOutResult);
	return this->_Inst_Commands;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElSimpleSSHClient::get_Subsystem(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_Subsystem(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-299288033, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHClient::set_Subsystem(const std::string &Value)
{
	SBCheckError(TElSimpleSSHClient_set_Subsystem(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSimpleSSHClient::get_AuthenticationTypes()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_AuthenticationTypes(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHClient::set_AuthenticationTypes(int32_t Value)
{
	SBCheckError(TElSimpleSSHClient_set_AuthenticationTypes(_Handle, Value));
}

void TElSimpleSSHClient::get_ClientHostname(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_ClientHostname(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1969154969, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHClient::set_ClientHostname(const std::string &Value)
{
	SBCheckError(TElSimpleSSHClient_set_ClientHostname(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleSSHClient::get_ClientUsername(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_ClientUsername(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1750150655, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHClient::set_ClientUsername(const std::string &Value)
{
	SBCheckError(TElSimpleSSHClient_set_ClientUsername(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSimpleSSHClient::get_CompressionLevel()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHClient::set_CompressionLevel(int32_t Value)
{
	SBCheckError(TElSimpleSSHClient_set_CompressionLevel(_Handle, Value));
}

bool TElSimpleSSHClient::get_ForceCompression()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_ForceCompression(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_ForceCompression(bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_ForceCompression(_Handle, (int8_t)Value));
}

bool TElSimpleSSHClient::get_SendCommandEOF()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_SendCommandEOF(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_SendCommandEOF(bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_SendCommandEOF(_Handle, (int8_t)Value));
}

void TElSimpleSSHClient::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(644999000, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHClient::set_Password(const std::string &Value)
{
	SBCheckError(TElSimpleSSHClient_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleSSHClient::get_SoftwareName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_SoftwareName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1949937272, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHClient::set_SoftwareName(const std::string &Value)
{
	SBCheckError(TElSimpleSSHClient_set_SoftwareName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleSSHClient::get_Username(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_Username(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-336746502, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHClient::set_Username(const std::string &Value)
{
	SBCheckError(TElSimpleSSHClient_set_Username(_Handle, Value.data(), (int32_t)Value.length()));
}

TSSHVersions TElSimpleSSHClient::get_Versions()
{
	TSSHVersionsRaw OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_Versions(_Handle, &OutResultRaw));
	return (TSSHVersions)OutResultRaw;
}

SB_INLINE void TElSimpleSSHClient::set_Versions(TSSHVersions Value)
{
	SBCheckError(TElSimpleSSHClient_set_Versions(_Handle, (TSSHVersionsRaw)Value));
}

void TElSimpleSSHClient::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-585251649, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHClient::set_Address(const std::string &Value)
{
	SBCheckError(TElSimpleSSHClient_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSimpleSSHClient::get_Environment()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHClient_get_Environment(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Environment)
		this->_Inst_Environment = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Environment->updateHandle(hOutResult);
	return this->_Inst_Environment;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

bool TElSimpleSSHClient::get_RequestTerminal()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_RequestTerminal(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_RequestTerminal(bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_RequestTerminal(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
TElSSHCustomKeyStorage* TElSimpleSSHClient::get_TrustedKeys()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHClient_get_TrustedKeys(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TrustedKeys)
		this->_Inst_TrustedKeys = new TElSSHCustomKeyStorage(hOutResult, ohFalse);
	else
		this->_Inst_TrustedKeys->updateHandle(hOutResult);
	return this->_Inst_TrustedKeys;
}

SB_INLINE void TElSimpleSSHClient::set_TrustedKeys(TElSSHCustomKeyStorage &Value)
{
	SBCheckError(TElSimpleSSHClient_set_TrustedKeys(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSSHClient::set_TrustedKeys(TElSSHCustomKeyStorage *Value)
{
	SBCheckError(TElSimpleSSHClient_set_TrustedKeys(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElSimpleSSHClient::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHClient_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElSimpleSSHClient::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElSimpleSSHClient_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSSHClient::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElSimpleSSHClient_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

SB_INLINE int32_t TElSimpleSSHClient::get_DefaultWindowSize()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_DefaultWindowSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHClient::set_DefaultWindowSize(int32_t Value)
{
	SBCheckError(TElSimpleSSHClient_set_DefaultWindowSize(_Handle, Value));
}

SB_INLINE int32_t TElSimpleSSHClient::get_MinWindowSize()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_MinWindowSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHClient::set_MinWindowSize(int32_t Value)
{
	SBCheckError(TElSimpleSSHClient_set_MinWindowSize(_Handle, Value));
}

SB_INLINE int32_t TElSimpleSSHClient::get_MaxSSHPacketSize()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_MaxSSHPacketSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHClient::set_MaxSSHPacketSize(int32_t Value)
{
	SBCheckError(TElSimpleSSHClient_set_MaxSSHPacketSize(_Handle, Value));
}

bool TElSimpleSSHClient::get_ThrottleControl()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_ThrottleControl(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_ThrottleControl(bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_ThrottleControl(_Handle, (int8_t)Value));
}

bool TElSimpleSSHClient::get_RaiseExceptionOnCommandTimeout()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_RaiseExceptionOnCommandTimeout(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_RaiseExceptionOnCommandTimeout(bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_RaiseExceptionOnCommandTimeout(_Handle, (int8_t)Value));
}

bool TElSimpleSSHClient::get_RaiseExceptionOnTunnelFailure()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_RaiseExceptionOnTunnelFailure(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_RaiseExceptionOnTunnelFailure(bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_RaiseExceptionOnTunnelFailure(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
TElClientSocketBinding* TElSimpleSSHClient::get_SocketBinding()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHClient_get_SocketBinding(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SocketBinding)
		this->_Inst_SocketBinding = new TElClientSocketBinding(hOutResult, ohFalse);
	else
		this->_Inst_SocketBinding->updateHandle(hOutResult);
	return this->_Inst_SocketBinding;
}

SB_INLINE void TElSimpleSSHClient::set_SocketBinding(TElClientSocketBinding &Value)
{
	SBCheckError(TElSimpleSSHClient_set_SocketBinding(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSSHClient::set_SocketBinding(TElClientSocketBinding *Value)
{
	SBCheckError(TElSimpleSSHClient_set_SocketBinding(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
TElDNSSettings* TElSimpleSSHClient::get_DNS()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHClient_get_DNS(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DNS)
		this->_Inst_DNS = new TElDNSSettings(hOutResult, ohFalse);
	else
		this->_Inst_DNS->updateHandle(hOutResult);
	return this->_Inst_DNS;
}

SB_INLINE void TElSimpleSSHClient::set_DNS(TElDNSSettings &Value)
{
	SBCheckError(TElSimpleSSHClient_set_DNS(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSSHClient::set_DNS(TElDNSSettings *Value)
{
	SBCheckError(TElSimpleSSHClient_set_DNS(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif

#ifdef SB_USE_CLASS_TELPORTKNOCK
TElPortKnock* TElSimpleSSHClient::get_PortKnock()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHClient_get_PortKnock(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PortKnock)
		this->_Inst_PortKnock = new TElPortKnock(hOutResult, ohFalse);
	else
		this->_Inst_PortKnock->updateHandle(hOutResult);
	return this->_Inst_PortKnock;
}

SB_INLINE void TElSimpleSSHClient::set_PortKnock(TElPortKnock &Value)
{
	SBCheckError(TElSimpleSSHClient_set_PortKnock(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleSSHClient::set_PortKnock(TElPortKnock *Value)
{
	SBCheckError(TElSimpleSSHClient_set_PortKnock(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPORTKNOCK */

#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
TElSocketSettings* TElSimpleSSHClient::get_SocketSettings()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHClient_get_SocketSettings(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SocketSettings)
		this->_Inst_SocketSettings = new TElSocketSettings(hOutResult, ohFalse);
	else
		this->_Inst_SocketSettings->updateHandle(hOutResult);
	return this->_Inst_SocketSettings;
}
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */

SB_INLINE int32_t TElSimpleSSHClient::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHClient::set_Port(int32_t Value)
{
	SBCheckError(TElSimpleSSHClient_set_Port(_Handle, Value));
}

SB_INLINE int32_t TElSimpleSSHClient::get_SocketTimeout()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_SocketTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHClient::set_SocketTimeout(int32_t Value)
{
	SBCheckError(TElSimpleSSHClient_set_SocketTimeout(_Handle, Value));
}

SB_INLINE int32_t TElSimpleSSHClient::get_CommandTimeout()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_CommandTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHClient::set_CommandTimeout(int32_t Value)
{
	SBCheckError(TElSimpleSSHClient_set_CommandTimeout(_Handle, Value));
}

TElSocksAuthentication TElSimpleSSHClient::get_SocksAuthentication()
{
	TElSocksAuthenticationRaw OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_SocksAuthentication(_Handle, &OutResultRaw));
	return (TElSocksAuthentication)OutResultRaw;
}

SB_INLINE void TElSimpleSSHClient::set_SocksAuthentication(TElSocksAuthentication Value)
{
	SBCheckError(TElSimpleSSHClient_set_SocksAuthentication(_Handle, (TElSocksAuthenticationRaw)Value));
}

void TElSimpleSSHClient::get_SocksPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_SocksPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(242307696, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHClient::set_SocksPassword(const std::string &Value)
{
	SBCheckError(TElSimpleSSHClient_set_SocksPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSimpleSSHClient::get_SocksPort()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_SocksPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHClient::set_SocksPort(int32_t Value)
{
	SBCheckError(TElSimpleSSHClient_set_SocksPort(_Handle, Value));
}

bool TElSimpleSSHClient::get_SocksResolveAddress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_SocksResolveAddress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_SocksResolveAddress(bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_SocksResolveAddress(_Handle, (int8_t)Value));
}

void TElSimpleSSHClient::get_SocksServer(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_SocksServer(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(111107830, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHClient::set_SocksServer(const std::string &Value)
{
	SBCheckError(TElSimpleSSHClient_set_SocksServer(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleSSHClient::get_SocksUserCode(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_SocksUserCode(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1256846194, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHClient::set_SocksUserCode(const std::string &Value)
{
	SBCheckError(TElSimpleSSHClient_set_SocksUserCode(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSocksVersion TElSimpleSSHClient::get_SocksVersion()
{
	TElSocksVersionRaw OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_SocksVersion(_Handle, &OutResultRaw));
	return (TElSocksVersion)OutResultRaw;
}

SB_INLINE void TElSimpleSSHClient::set_SocksVersion(TElSocksVersion Value)
{
	SBCheckError(TElSimpleSSHClient_set_SocksVersion(_Handle, (TElSocksVersionRaw)Value));
}

#ifdef SB_WINDOWS
bool TElSimpleSSHClient::get_SocksUseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_SocksUseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_SocksUseIPv6(bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_SocksUseIPv6(_Handle, (int8_t)Value));
}
#endif

bool TElSimpleSSHClient::get_UseInternalSocket()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_UseInternalSocket(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_UseInternalSocket(bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_UseInternalSocket(_Handle, (int8_t)Value));
}

bool TElSimpleSSHClient::get_UseSocks()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_UseSocks(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_UseSocks(bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_UseSocks(_Handle, (int8_t)Value));
}

#ifdef SB_WINDOWS
bool TElSimpleSSHClient::get_UseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_UseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_UseIPv6(bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_UseIPv6(_Handle, (int8_t)Value));
}
#endif

bool TElSimpleSSHClient::get_UseWebTunneling()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_UseWebTunneling(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_UseWebTunneling(bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_UseWebTunneling(_Handle, (int8_t)Value));
}

void TElSimpleSSHClient::get_WebTunnelAddress(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_WebTunnelAddress(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1401516390, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHClient::set_WebTunnelAddress(const std::string &Value)
{
	SBCheckError(TElSimpleSSHClient_set_WebTunnelAddress(_Handle, Value.data(), (int32_t)Value.length()));
}

TElWebTunnelAuthentication TElSimpleSSHClient::get_WebTunnelAuthentication()
{
	TElWebTunnelAuthenticationRaw OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_WebTunnelAuthentication(_Handle, &OutResultRaw));
	return (TElWebTunnelAuthentication)OutResultRaw;
}

SB_INLINE void TElSimpleSSHClient::set_WebTunnelAuthentication(TElWebTunnelAuthentication Value)
{
	SBCheckError(TElSimpleSSHClient_set_WebTunnelAuthentication(_Handle, (TElWebTunnelAuthenticationRaw)Value));
}

void TElSimpleSSHClient::get_WebTunnelPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_WebTunnelPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-638576227, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHClient::set_WebTunnelPassword(const std::string &Value)
{
	SBCheckError(TElSimpleSSHClient_set_WebTunnelPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSimpleSSHClient::get_WebTunnelPort()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_WebTunnelPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHClient::set_WebTunnelPort(int32_t Value)
{
	SBCheckError(TElSimpleSSHClient_set_WebTunnelPort(_Handle, Value));
}

void TElSimpleSSHClient::get_WebTunnelUserId(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_WebTunnelUserId(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1916523666, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHClient::set_WebTunnelUserId(const std::string &Value)
{
	SBCheckError(TElSimpleSSHClient_set_WebTunnelUserId(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSimpleSSHClient::get_WebTunnelRequestHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHClient_get_WebTunnelRequestHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WebTunnelRequestHeaders)
		this->_Inst_WebTunnelRequestHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_WebTunnelRequestHeaders->updateHandle(hOutResult);
	return this->_Inst_WebTunnelRequestHeaders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSimpleSSHClient::get_WebTunnelRequestHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHClient_get_WebTunnelRequestHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WebTunnelRequestHeaders)
		this->_Inst_WebTunnelRequestHeaders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_WebTunnelRequestHeaders->updateHandle(hOutResult);
	return this->_Inst_WebTunnelRequestHeaders;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSimpleSSHClient::get_WebTunnelResponseHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHClient_get_WebTunnelResponseHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WebTunnelResponseHeaders)
		this->_Inst_WebTunnelResponseHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_WebTunnelResponseHeaders->updateHandle(hOutResult);
	return this->_Inst_WebTunnelResponseHeaders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSimpleSSHClient::get_WebTunnelResponseHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleSSHClient_get_WebTunnelResponseHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WebTunnelResponseHeaders)
		this->_Inst_WebTunnelResponseHeaders = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_WebTunnelResponseHeaders->updateHandle(hOutResult);
	return this->_Inst_WebTunnelResponseHeaders;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

void TElSimpleSSHClient::get_WebTunnelResponseBody(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_WebTunnelResponseBody(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2009750332, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElSimpleSSHClient::get_ProxyResult()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_ProxyResult(_Handle, &OutResult));
	return OutResult;
}

void TElSimpleSSHClient::get_ErrorString(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_ErrorString(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-807834107, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSimpleSSHClient::get_LocalAddress(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleSSHClient_get_LocalAddress(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1859540717, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleSSHClient::set_LocalAddress(const std::string &Value)
{
	SBCheckError(TElSimpleSSHClient_set_LocalAddress(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSimpleSSHClient::get_LocalPort()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_LocalPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHClient::set_LocalPort(int32_t Value)
{
	SBCheckError(TElSimpleSSHClient_set_LocalPort(_Handle, Value));
}

TSBSSHAuthOrder TElSimpleSSHClient::get_SSHAuthOrder()
{
	TSBSSHAuthOrderRaw OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_SSHAuthOrder(_Handle, &OutResultRaw));
	return (TSBSSHAuthOrder)OutResultRaw;
}

SB_INLINE void TElSimpleSSHClient::set_SSHAuthOrder(TSBSSHAuthOrder Value)
{
	SBCheckError(TElSimpleSSHClient_set_SSHAuthOrder(_Handle, (TSBSSHAuthOrderRaw)Value));
}

TSBSSHCertAuthMode TElSimpleSSHClient::get_CertAuthMode()
{
	TSBSSHCertAuthModeRaw OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_CertAuthMode(_Handle, &OutResultRaw));
	return (TSBSSHCertAuthMode)OutResultRaw;
}

SB_INLINE void TElSimpleSSHClient::set_CertAuthMode(TSBSSHCertAuthMode Value)
{
	SBCheckError(TElSimpleSSHClient_set_CertAuthMode(_Handle, (TSBSSHCertAuthModeRaw)Value));
}

bool TElSimpleSSHClient::get_AutoAdjustCiphers()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_AutoAdjustCiphers(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_AutoAdjustCiphers(bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_AutoAdjustCiphers(_Handle, (int8_t)Value));
}

bool TElSimpleSSHClient::get_UseUTF8()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_UseUTF8(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_UseUTF8(bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_UseUTF8(_Handle, (int8_t)Value));
}

bool TElSimpleSSHClient::get_NoCharacterEncoding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleSSHClient_get_NoCharacterEncoding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleSSHClient::set_NoCharacterEncoding(bool Value)
{
	SBCheckError(TElSimpleSSHClient_set_NoCharacterEncoding(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElSimpleSSHClient::get_AuthAttempts()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_AuthAttempts(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHClient::set_AuthAttempts(int32_t Value)
{
	SBCheckError(TElSimpleSSHClient_set_AuthAttempts(_Handle, Value));
}

SB_INLINE int32_t TElSimpleSSHClient::get_IncomingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_IncomingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHClient::set_IncomingSpeedLimit(int32_t Value)
{
	SBCheckError(TElSimpleSSHClient_set_IncomingSpeedLimit(_Handle, Value));
}

SB_INLINE int32_t TElSimpleSSHClient::get_OutgoingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElSimpleSSHClient_get_OutgoingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleSSHClient::set_OutgoingSpeedLimit(int32_t Value)
{
	SBCheckError(TElSimpleSSHClient_set_OutgoingSpeedLimit(_Handle, Value));
}

SB_INLINE void TElSimpleSSHClient::get_OnAuthenticationKeyboard(TSSHAuthenticationKeyboardEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_OnAuthenticationKeyboard(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_OnAuthenticationKeyboard(TSSHAuthenticationKeyboardEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_OnAuthenticationKeyboard(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHClient::get_OnAuthenticationFailed(TSSHAuthenticationFailedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_OnAuthenticationFailed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_OnAuthenticationFailed(TSSHAuthenticationFailedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_OnAuthenticationFailed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHClient::get_OnAuthenticationSuccess(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_OnAuthenticationSuccess(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_OnAuthenticationSuccess(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_OnAuthenticationSuccess(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHClient::get_OnAuthenticationStart(TSSHAuthenticationStartEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_OnAuthenticationStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_OnAuthenticationStart(TSSHAuthenticationStartEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_OnAuthenticationStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHClient::get_OnAuthenticationAttempt(TSSHAuthenticationAttemptEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_OnAuthenticationAttempt(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_OnAuthenticationAttempt(TSSHAuthenticationAttemptEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_OnAuthenticationAttempt(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHClient::get_OnBanner(TSSHBannerEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_OnBanner(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_OnBanner(TSSHBannerEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_OnBanner(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHClient::get_OnCloseConnection(TSSHCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_OnCloseConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_OnCloseConnection(TSSHCloseConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_OnCloseConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHClient::get_OnError(TSSHErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_OnError(TSSHErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHClient::get_OnTunnelError(TSSHErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_OnTunnelError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_OnTunnelError(TSSHErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_OnTunnelError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHClient::get_OnKeyValidate(TSSHKeyValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_OnKeyValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_OnKeyValidate(TSSHKeyValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_OnKeyValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHClient::get_OnReceive(TSSHReceiveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_OnReceive(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_OnReceive(TSSHReceiveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_OnReceive(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHClient::get_OnSend(TSSHSendEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_OnSend(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_OnSend(TSSHSendEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_OnSend(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHClient::get_OnPrivateKeyNeeded(TSSHPrivateKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_OnPrivateKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_OnPrivateKeyNeeded(TSSHPrivateKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_OnPrivateKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHClient::get_OnSendCommandRequest(TSSHCommandExecutionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_OnSendCommandRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_OnSendCommandRequest(TSSHCommandExecutionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_OnSendCommandRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHClient::get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_OnCiphersNegotiated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_OnCiphersNegotiated(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHClient::get_OnPasswordChangeRequest(TSSHPasswordChangeRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_OnPasswordChangeRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_OnPasswordChangeRequest(TSSHPasswordChangeRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_OnPasswordChangeRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHClient::get_OnKexInitReceived(TSSHKexInitReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_OnKexInitReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_OnKexInitReceived(TSSHKexInitReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_OnKexInitReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHClient::get_MessageLoop(TSSHMessageLoopEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_MessageLoop(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_MessageLoop(TSSHMessageLoopEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_MessageLoop(_Handle, pMethodValue, pDataValue));
}

#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_INLINE void TElSimpleSSHClient::get_OnDNSKeyNeeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_OnDNSKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_OnDNSKeyNeeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_OnDNSKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHClient::get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_OnDNSKeyValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_OnDNSKeyValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleSSHClient::get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleSSHClient_get_OnDNSResolve(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleSSHClient::set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleSSHClient_set_OnDNSResolve(_Handle, pMethodValue, pDataValue));
}
#endif

void TElSimpleSSHClient::initInstances()
{
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
	this->_Inst_KeyStorage = NULL;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifdef SB_USE_CLASS_TELTERMINALINFO
	this->_Inst_TerminalInfo = NULL;
#endif /* SB_USE_CLASS_TELTERMINALINFO */
#ifdef SB_USE_CLASS_TELSSHKEY
	this->_Inst_ServerKey = NULL;
#endif /* SB_USE_CLASS_TELSSHKEY */
#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
	this->_Inst_GSSMechanism = NULL;
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */
#ifdef SB_USE_CLASS_TELSOCKET
	this->_Inst_InternalSocket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Commands = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Commands = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Environment = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
	this->_Inst_TrustedKeys = NULL;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	this->_Inst_SocketBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
	this->_Inst_DNS = NULL;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
#ifdef SB_USE_CLASS_TELPORTKNOCK
	this->_Inst_PortKnock = NULL;
#endif /* SB_USE_CLASS_TELPORTKNOCK */
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
	this->_Inst_SocketSettings = NULL;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_WebTunnelRequestHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_WebTunnelRequestHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_WebTunnelResponseHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_WebTunnelResponseHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}

TElSimpleSSHClient::TElSimpleSSHClient(TElSimpleSSHClientHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElSimpleSSHClient::TElSimpleSSHClient(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleSSHClient_Create(AOwner.getHandle(), &_Handle));
}

TElSimpleSSHClient::TElSimpleSSHClient(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleSSHClient_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSimpleSSHClient::~TElSimpleSSHClient()
{
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
	delete this->_Inst_KeyStorage;
	this->_Inst_KeyStorage = NULL;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifdef SB_USE_CLASS_TELTERMINALINFO
	delete this->_Inst_TerminalInfo;
	this->_Inst_TerminalInfo = NULL;
#endif /* SB_USE_CLASS_TELTERMINALINFO */
#ifdef SB_USE_CLASS_TELSSHKEY
	delete this->_Inst_ServerKey;
	this->_Inst_ServerKey = NULL;
#endif /* SB_USE_CLASS_TELSSHKEY */
#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
	delete this->_Inst_GSSMechanism;
	this->_Inst_GSSMechanism = NULL;
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */
#ifdef SB_USE_CLASS_TELSOCKET
	delete this->_Inst_InternalSocket;
	this->_Inst_InternalSocket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Commands;
	this->_Inst_Commands = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Commands;
	this->_Inst_Commands = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Environment;
	this->_Inst_Environment = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
	delete this->_Inst_TrustedKeys;
	this->_Inst_TrustedKeys = NULL;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	delete this->_Inst_SocketBinding;
	this->_Inst_SocketBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
	delete this->_Inst_DNS;
	this->_Inst_DNS = NULL;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
#ifdef SB_USE_CLASS_TELPORTKNOCK
	delete this->_Inst_PortKnock;
	this->_Inst_PortKnock = NULL;
#endif /* SB_USE_CLASS_TELPORTKNOCK */
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
	delete this->_Inst_SocketSettings;
	this->_Inst_SocketSettings = NULL;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_WebTunnelRequestHeaders;
	this->_Inst_WebTunnelRequestHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_WebTunnelRequestHeaders;
	this->_Inst_WebTunnelRequestHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_WebTunnelResponseHeaders;
	this->_Inst_WebTunnelResponseHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_WebTunnelResponseHeaders;
	this->_Inst_WebTunnelResponseHeaders = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
}
#endif /* SB_USE_CLASS_TELSIMPLESSHCLIENT */

};	/* namespace SecureBlackbox */
