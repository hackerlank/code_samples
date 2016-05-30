#include "sbftpsserver.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELFTPSSERVERFILEINFO

bool TElFTPSServerFileInfo::AttributeIncluded(TSBFTPSServerFileAttribute Attribute)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFTPSServerFileInfo_AttributeIncluded(_Handle, (TSBFTPSServerFileAttributeRaw)Attribute, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElFTPSServerFileInfo::IncludeAttribute(TSBFTPSServerFileAttribute Attribute)
{
	SBCheckError(TElFTPSServerFileInfo_IncludeAttribute(_Handle, (TSBFTPSServerFileAttributeRaw)Attribute));
}

SB_INLINE void TElFTPSServerFileInfo::ExcludeAttribute(TSBFTPSServerFileAttribute Attribute)
{
	SBCheckError(TElFTPSServerFileInfo_ExcludeAttribute(_Handle, (TSBFTPSServerFileAttributeRaw)Attribute));
}

SB_INLINE int64_t TElFTPSServerFileInfo::get_Size()
{
	int64_t OutResult;
	SBCheckError(TElFTPSServerFileInfo_get_Size(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElFTPSServerFileInfo::set_Size(int64_t Value)
{
	SBCheckError(TElFTPSServerFileInfo_set_Size(_Handle, Value));
}

void TElFTPSServerFileInfo::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElFTPSServerFileInfo_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1853098116, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElFTPSServerFileInfo::set_Name(const std::string &Value)
{
	SBCheckError(TElFTPSServerFileInfo_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElFTPSServerFileInfo::get_UnixPermissions()
{
	int32_t OutResult;
	SBCheckError(TElFTPSServerFileInfo_get_UnixPermissions(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElFTPSServerFileInfo::set_UnixPermissions(int32_t Value)
{
	SBCheckError(TElFTPSServerFileInfo_set_UnixPermissions(_Handle, Value));
}

TSBFTPSServerFileType TElFTPSServerFileInfo::get_FileType()
{
	TSBFTPSServerFileTypeRaw OutResultRaw = 0;
	SBCheckError(TElFTPSServerFileInfo_get_FileType(_Handle, &OutResultRaw));
	return (TSBFTPSServerFileType)OutResultRaw;
}

SB_INLINE void TElFTPSServerFileInfo::set_FileType(TSBFTPSServerFileType Value)
{
	SBCheckError(TElFTPSServerFileInfo_set_FileType(_Handle, (TSBFTPSServerFileTypeRaw)Value));
}

SB_INLINE int64_t TElFTPSServerFileInfo::get_CreationDate()
{
	int64_t OutResult;
	SBCheckError(TElFTPSServerFileInfo_get_CreationDate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElFTPSServerFileInfo::set_CreationDate(int64_t Value)
{
	SBCheckError(TElFTPSServerFileInfo_set_CreationDate(_Handle, Value));
}

SB_INLINE int64_t TElFTPSServerFileInfo::get_ModificationDate()
{
	int64_t OutResult;
	SBCheckError(TElFTPSServerFileInfo_get_ModificationDate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElFTPSServerFileInfo::set_ModificationDate(int64_t Value)
{
	SBCheckError(TElFTPSServerFileInfo_set_ModificationDate(_Handle, Value));
}

void TElFTPSServerFileInfo::get_Owner(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElFTPSServerFileInfo_get_Owner(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(518306955, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElFTPSServerFileInfo::set_Owner(const std::string &Value)
{
	SBCheckError(TElFTPSServerFileInfo_set_Owner(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElFTPSServerFileInfo::get_Group(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElFTPSServerFileInfo_get_Group(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1136386510, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElFTPSServerFileInfo::set_Group(const std::string &Value)
{
	SBCheckError(TElFTPSServerFileInfo_set_Group(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBFTPSServerFileAttributes TElFTPSServerFileInfo::get_IncludedAttributes()
{
	TSBFTPSServerFileAttributesRaw OutResultRaw = 0;
	SBCheckError(TElFTPSServerFileInfo_get_IncludedAttributes(_Handle, &OutResultRaw));
	return (TSBFTPSServerFileAttributes)OutResultRaw;
}

SB_INLINE void TElFTPSServerFileInfo::set_IncludedAttributes(TSBFTPSServerFileAttributes Value)
{
	SBCheckError(TElFTPSServerFileInfo_set_IncludedAttributes(_Handle, (TSBFTPSServerFileAttributesRaw)Value));
}

TElFTPSServerFileInfo::TElFTPSServerFileInfo(TElFTPSServerFileInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElFTPSServerFileInfo::TElFTPSServerFileInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFTPSServerFileInfo_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELFTPSSERVERFILEINFO */

#ifdef SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE

SB_INLINE void TElFTPSServerMessageTable::SetDefaults()
{
	SBCheckError(TElFTPSServerMessageTable_SetDefaults(_Handle));
}

SB_INLINE void TElFTPSServerMessageTable::Clear()
{
	SBCheckError(TElFTPSServerMessageTable_Clear(_Handle));
}

void TElFTPSServerMessageTable::GetMessage(int32_t Code, const std::string &Command, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElFTPSServerMessageTable_GetMessage(_Handle, Code, Command.data(), (int32_t)Command.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1724084479, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElFTPSServerMessageTable::SetMessage(int32_t Code, const std::string &Msg)
{
	SBCheckError(TElFTPSServerMessageTable_SetMessage(_Handle, Code, Msg.data(), (int32_t)Msg.length()));
}

SB_INLINE void TElFTPSServerMessageTable::SetMessage(int32_t Code, const std::string &Msg, const std::string &Command)
{
	SBCheckError(TElFTPSServerMessageTable_SetMessage_1(_Handle, Code, Msg.data(), (int32_t)Msg.length(), Command.data(), (int32_t)Command.length()));
}

void TElFTPSServerMessageTable::get_Greeting(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElFTPSServerMessageTable_get_Greeting(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1086925221, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElFTPSServerMessageTable::set_Greeting(const std::string &Value)
{
	SBCheckError(TElFTPSServerMessageTable_set_Greeting(_Handle, Value.data(), (int32_t)Value.length()));
}

TElFTPSServerMessageTable::TElFTPSServerMessageTable(TElFTPSServerMessageTableHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElFTPSServerMessageTable::TElFTPSServerMessageTable() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFTPSServerMessageTable_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE */

#ifdef SB_USE_CLASS_TELFTPSUSER

void TElFTPSUser::GetData(std::vector<uint8_t> &Buffer, int32_t &Size)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = TElFTPSUser_GetData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, &Size);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-956505007, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

SB_INLINE void TElFTPSUser::SetData(const std::vector<uint8_t> &Value, int32_t Size)
{
	SBCheckError(TElFTPSUser_SetData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), Size));
}

SB_INLINE void TElFTPSUser::SetBasePath(const std::string &Value)
{
	SBCheckError(TElFTPSUser_SetBasePath(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElFTPSUser::SetOutgoingSpeedLimit(int32_t Value)
{
	SBCheckError(TElFTPSUser_SetOutgoingSpeedLimit(_Handle, Value));
}

SB_INLINE void TElFTPSUser::SetIncomingSpeedLimit(int32_t Value)
{
	SBCheckError(TElFTPSUser_SetIncomingSpeedLimit(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELUSERS
SB_INLINE void TElFTPSUser::AddUser(TElUsers &Users, const std::string &UserName, const std::string &Password)
{
	SBCheckError(TElFTPSUser_AddUser(Users.getHandle(), UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length()));
}

SB_INLINE void TElFTPSUser::AddUser(TElUsers *Users, const std::string &UserName, const std::string &Password)
{
	SBCheckError(TElFTPSUser_AddUser((Users != NULL) ? Users->getHandle() : SB_NULL_HANDLE, UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length()));
}
#endif /* SB_USE_CLASS_TELUSERS */

#ifdef SB_USE_CLASS_TELUSERS
SB_INLINE void TElFTPSUser::AddUser_Inst(TElUsers &Users, const std::string &UserName, const std::string &Password)
{
	SBCheckError(TElFTPSUser_AddUser_1(_Handle, Users.getHandle(), UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length()));
}

SB_INLINE void TElFTPSUser::AddUser_Inst(TElUsers *Users, const std::string &UserName, const std::string &Password)
{
	SBCheckError(TElFTPSUser_AddUser_1(_Handle, (Users != NULL) ? Users->getHandle() : SB_NULL_HANDLE, UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length()));
}
#endif /* SB_USE_CLASS_TELUSERS */

#ifdef SB_USE_CLASS_TELUSERS
SB_INLINE void TElFTPSUser::AddUser(TElUsers &Users, const std::string &UserName, const std::string &Password, const std::string &BasePath)
{
	SBCheckError(TElFTPSUser_AddUser_2(Users.getHandle(), UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), BasePath.data(), (int32_t)BasePath.length()));
}

SB_INLINE void TElFTPSUser::AddUser(TElUsers *Users, const std::string &UserName, const std::string &Password, const std::string &BasePath)
{
	SBCheckError(TElFTPSUser_AddUser_2((Users != NULL) ? Users->getHandle() : SB_NULL_HANDLE, UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), BasePath.data(), (int32_t)BasePath.length()));
}
#endif /* SB_USE_CLASS_TELUSERS */

#ifdef SB_USE_CLASS_TELUSERS
SB_INLINE void TElFTPSUser::AddUser_Inst(TElUsers &Users, const std::string &UserName, const std::string &Password, const std::string &BasePath)
{
	SBCheckError(TElFTPSUser_AddUser_3(_Handle, Users.getHandle(), UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), BasePath.data(), (int32_t)BasePath.length()));
}

SB_INLINE void TElFTPSUser::AddUser_Inst(TElUsers *Users, const std::string &UserName, const std::string &Password, const std::string &BasePath)
{
	SBCheckError(TElFTPSUser_AddUser_3(_Handle, (Users != NULL) ? Users->getHandle() : SB_NULL_HANDLE, UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), BasePath.data(), (int32_t)BasePath.length()));
}
#endif /* SB_USE_CLASS_TELUSERS */

#ifdef SB_USE_CLASS_TELUSERS
SB_INLINE void TElFTPSUser::AddUser(TElUsers &Users, const std::string &UserName, const std::string &Password, const std::string &BasePath, int32_t OutgoingSpeedLimit, int32_t IncomingSpeedLimit)
{
	SBCheckError(TElFTPSUser_AddUser_4(Users.getHandle(), UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), BasePath.data(), (int32_t)BasePath.length(), OutgoingSpeedLimit, IncomingSpeedLimit));
}

SB_INLINE void TElFTPSUser::AddUser(TElUsers *Users, const std::string &UserName, const std::string &Password, const std::string &BasePath, int32_t OutgoingSpeedLimit, int32_t IncomingSpeedLimit)
{
	SBCheckError(TElFTPSUser_AddUser_4((Users != NULL) ? Users->getHandle() : SB_NULL_HANDLE, UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), BasePath.data(), (int32_t)BasePath.length(), OutgoingSpeedLimit, IncomingSpeedLimit));
}
#endif /* SB_USE_CLASS_TELUSERS */

#ifdef SB_USE_CLASS_TELUSERS
SB_INLINE void TElFTPSUser::AddUser_Inst(TElUsers &Users, const std::string &UserName, const std::string &Password, const std::string &BasePath, int32_t OutgoingSpeedLimit, int32_t IncomingSpeedLimit)
{
	SBCheckError(TElFTPSUser_AddUser_5(_Handle, Users.getHandle(), UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), BasePath.data(), (int32_t)BasePath.length(), OutgoingSpeedLimit, IncomingSpeedLimit));
}

SB_INLINE void TElFTPSUser::AddUser_Inst(TElUsers *Users, const std::string &UserName, const std::string &Password, const std::string &BasePath, int32_t OutgoingSpeedLimit, int32_t IncomingSpeedLimit)
{
	SBCheckError(TElFTPSUser_AddUser_5(_Handle, (Users != NULL) ? Users->getHandle() : SB_NULL_HANDLE, UserName.data(), (int32_t)UserName.length(), Password.data(), (int32_t)Password.length(), BasePath.data(), (int32_t)BasePath.length(), OutgoingSpeedLimit, IncomingSpeedLimit));
}
#endif /* SB_USE_CLASS_TELUSERS */

SB_INLINE TClassHandle TElFTPSUser::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElFTPSUser_ClassType(&OutResult));
	return OutResult;
}

void TElFTPSUser::get_BasePath(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElFTPSUser_get_BasePath(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1941310874, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElFTPSUser::set_BasePath(const std::string &Value)
{
	SBCheckError(TElFTPSUser_set_BasePath(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElFTPSUser::get_OutgoingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElFTPSUser_get_OutgoingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElFTPSUser::set_OutgoingSpeedLimit(int32_t Value)
{
	SBCheckError(TElFTPSUser_set_OutgoingSpeedLimit(_Handle, Value));
}

SB_INLINE int32_t TElFTPSUser::get_IncomingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElFTPSUser_get_IncomingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElFTPSUser::set_IncomingSpeedLimit(int32_t Value)
{
	SBCheckError(TElFTPSUser_set_IncomingSpeedLimit(_Handle, Value));
}

TElFTPSUser::TElFTPSUser(TElFTPSUserHandle handle, TElOwnHandle ownHandle) : TElCustomUser(handle, ownHandle)
{
}

TElFTPSUser::TElFTPSUser(const std::string &UserName) : TElCustomUser(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFTPSUser_Create(UserName.data(), (int32_t)UserName.length(), &_Handle));
}

#endif /* SB_USE_CLASS_TELFTPSUSER */

#ifdef SB_USE_CLASS_TELFTPSSERVER

SB_INLINE void TElFTPSServer::Open()
{
	SBCheckError(TElFTPSServer_Open(_Handle));
}

SB_INLINE void TElFTPSServer::Close()
{
	SBCheckError(TElFTPSServer_Close(_Handle));
}

SB_INLINE void TElFTPSServer::CloseDataConnection()
{
	SBCheckError(TElFTPSServer_CloseDataConnection(_Handle));
}

SB_INLINE void TElFTPSServer::TransferDataFinished()
{
	SBCheckError(TElFTPSServer_TransferDataFinished(_Handle));
}

SB_INLINE void TElFTPSServer::DataAvailable()
{
	SBCheckError(TElFTPSServer_DataAvailable(_Handle));
}

SB_INLINE void TElFTPSServer::SendCustomReply(int32_t Code, const std::string &Reply)
{
	SBCheckError(TElFTPSServer_SendCustomReply(_Handle, Code, Reply.data(), (int32_t)Reply.length()));
}

#ifdef SB_USE_CLASS_TELSSLSERVER
SB_INLINE void TElFTPSServer::AssignTLSParamsFromTemplate(TElSSLServer &Tpl)
{
	SBCheckError(TElFTPSServer_AssignTLSParamsFromTemplate(_Handle, Tpl.getHandle()));
}

SB_INLINE void TElFTPSServer::AssignTLSParamsFromTemplate(TElSSLServer *Tpl)
{
	SBCheckError(TElFTPSServer_AssignTLSParamsFromTemplate(_Handle, (Tpl != NULL) ? Tpl->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSLSERVER */

SB_INLINE void TElFTPSServer::ConfigureTLS(TSBServerSSLPredefinedConfiguration Configuration)
{
	SBCheckError(TElFTPSServer_ConfigureTLS(_Handle, (TSBServerSSLPredefinedConfigurationRaw)Configuration));
}

bool TElFTPSServer::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFTPSServer_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElFTPSServer::get_ASCIIMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFTPSServer_get_ASCIIMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElFTPSServer::get_Authenticated()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFTPSServer_get_Authenticated(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElFTPSServer::set_Authenticated(bool Value)
{
	SBCheckError(TElFTPSServer_set_Authenticated(_Handle, (int8_t)Value));
}

bool TElFTPSServer::get_PassiveMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFTPSServer_get_PassiveMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElFTPSServer::get_ExtPassiveOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFTPSServer_get_ExtPassiveOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE
TElFTPSServerMessageTable* TElFTPSServer::get_MessageTable()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFTPSServer_get_MessageTable(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_MessageTable)
		this->_Inst_MessageTable = new TElFTPSServerMessageTable(hOutResult, ohFalse);
	else
		this->_Inst_MessageTable->updateHandle(hOutResult);
	return this->_Inst_MessageTable;
}

SB_INLINE void TElFTPSServer::set_MessageTable(TElFTPSServerMessageTable &Value)
{
	SBCheckError(TElFTPSServer_set_MessageTable(_Handle, Value.getHandle()));
}

SB_INLINE void TElFTPSServer::set_MessageTable(TElFTPSServerMessageTable *Value)
{
	SBCheckError(TElFTPSServer_set_MessageTable(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE */

void TElFTPSServer::get_LastCommand(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElFTPSServer_get_LastCommand(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1310559438, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElFTPSServer::get_LastTransferCommand(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElFTPSServer_get_LastTransferCommand(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1531324129, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElFTPSServer::get_TransferInProgress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFTPSServer_get_TransferInProgress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElFTPSServer::get_ControlChannelEncrypted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFTPSServer_get_ControlChannelEncrypted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElFTPSServer::get_DataChannelEncrypted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFTPSServer_get_DataChannelEncrypted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElFTPSServer::get_CipherSuites(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFTPSServer_get_CipherSuites(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElFTPSServer::set_CipherSuites(uint8_t Index, bool Value)
{
	SBCheckError(TElFTPSServer_set_CipherSuites(_Handle, Index, (int8_t)Value));
}

SB_INLINE int32_t TElFTPSServer::get_CipherSuitePriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElFTPSServer_get_CipherSuitePriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElFTPSServer::set_CipherSuitePriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElFTPSServer_set_CipherSuitePriorities(_Handle, Index, Value));
}

bool TElFTPSServer::get_CompressionAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFTPSServer_get_CompressionAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElFTPSServer::set_CompressionAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElFTPSServer_set_CompressionAlgorithms(_Handle, Index, (int8_t)Value));
}

TSBVersions TElFTPSServer::get_Versions()
{
	TSBVersionsRaw OutResultRaw = 0;
	SBCheckError(TElFTPSServer_get_Versions(_Handle, &OutResultRaw));
	return (TSBVersions)OutResultRaw;
}

SB_INLINE void TElFTPSServer::set_Versions(TSBVersions Value)
{
	SBCheckError(TElFTPSServer_set_Versions(_Handle, (TSBVersionsRaw)Value));
}

bool TElFTPSServer::get_ClientAuthentication()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFTPSServer_get_ClientAuthentication(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElFTPSServer::set_ClientAuthentication(bool Value)
{
	SBCheckError(TElFTPSServer_set_ClientAuthentication(_Handle, (int8_t)Value));
}

TSBAuthenticationLevel TElFTPSServer::get_AuthenticationLevel()
{
	TSBAuthenticationLevelRaw OutResultRaw = 0;
	SBCheckError(TElFTPSServer_get_AuthenticationLevel(_Handle, &OutResultRaw));
	return (TSBAuthenticationLevel)OutResultRaw;
}

SB_INLINE void TElFTPSServer::set_AuthenticationLevel(TSBAuthenticationLevel Value)
{
	SBCheckError(TElFTPSServer_set_AuthenticationLevel(_Handle, (TSBAuthenticationLevelRaw)Value));
}

bool TElFTPSServer::get_ForceCertificateChain()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFTPSServer_get_ForceCertificateChain(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElFTPSServer::set_ForceCertificateChain(bool Value)
{
	SBCheckError(TElFTPSServer_set_ForceCertificateChain(_Handle, (int8_t)Value));
}

SB_INLINE uint8_t TElFTPSServer::get_ControlChannelCipherSuite()
{
	uint8_t OutResult;
	SBCheckError(TElFTPSServer_get_ControlChannelCipherSuite(_Handle, &OutResult));
	return OutResult;
}

TSBVersion TElFTPSServer::get_ControlChannelSSLVersion()
{
	TSBVersionRaw OutResultRaw = 0;
	SBCheckError(TElFTPSServer_get_ControlChannelSSLVersion(_Handle, &OutResultRaw));
	return (TSBVersion)OutResultRaw;
}

SB_INLINE uint8_t TElFTPSServer::get_ControlChannelSSLCompressionAlgorithm()
{
	uint8_t OutResult;
	SBCheckError(TElFTPSServer_get_ControlChannelSSLCompressionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
TElSSLConnectionInfo* TElFTPSServer::get_ControlChannelSSLConnectionInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFTPSServer_get_ControlChannelSSLConnectionInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ControlChannelSSLConnectionInfo)
		this->_Inst_ControlChannelSSLConnectionInfo = new TElSSLConnectionInfo(hOutResult, ohFalse);
	else
		this->_Inst_ControlChannelSSLConnectionInfo->updateHandle(hOutResult);
	return this->_Inst_ControlChannelSSLConnectionInfo;
}
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */

SB_INLINE uint8_t TElFTPSServer::get_DataChannelCipherSuite()
{
	uint8_t OutResult;
	SBCheckError(TElFTPSServer_get_DataChannelCipherSuite(_Handle, &OutResult));
	return OutResult;
}

TSBVersion TElFTPSServer::get_DataChannelSSLVersion()
{
	TSBVersionRaw OutResultRaw = 0;
	SBCheckError(TElFTPSServer_get_DataChannelSSLVersion(_Handle, &OutResultRaw));
	return (TSBVersion)OutResultRaw;
}

SB_INLINE uint8_t TElFTPSServer::get_DataChannelSSLCompressionAlgorithm()
{
	uint8_t OutResult;
	SBCheckError(TElFTPSServer_get_DataChannelSSLCompressionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
TElSSLConnectionInfo* TElFTPSServer::get_DataChannelSSLConnectionInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFTPSServer_get_DataChannelSSLConnectionInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DataChannelSSLConnectionInfo)
		this->_Inst_DataChannelSSLConnectionInfo = new TElSSLConnectionInfo(hOutResult, ohFalse);
	else
		this->_Inst_DataChannelSSLConnectionInfo->updateHandle(hOutResult);
	return this->_Inst_DataChannelSSLConnectionInfo;
}
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElFTPSServer::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFTPSServer_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElFTPSServer::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElFTPSServer_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElFTPSServer::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElFTPSServer_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELSESSIONPOOL
TElSessionPool* TElFTPSServer::get_SessionPool()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFTPSServer_get_SessionPool(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SessionPool)
		this->_Inst_SessionPool = new TElSessionPool(hOutResult, ohFalse);
	else
		this->_Inst_SessionPool->updateHandle(hOutResult);
	return this->_Inst_SessionPool;
}

SB_INLINE void TElFTPSServer::set_SessionPool(TElSessionPool &Value)
{
	SBCheckError(TElFTPSServer_set_SessionPool(_Handle, Value.getHandle()));
}

SB_INLINE void TElFTPSServer::set_SessionPool(TElSessionPool *Value)
{
	SBCheckError(TElFTPSServer_set_SessionPool(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSESSIONPOOL */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElFTPSServer::get_ClientCertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFTPSServer_get_ClientCertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ClientCertStorage)
		this->_Inst_ClientCertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_ClientCertStorage->updateHandle(hOutResult);
	return this->_Inst_ClientCertStorage;
}

SB_INLINE void TElFTPSServer::set_ClientCertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElFTPSServer_set_ClientCertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElFTPSServer::set_ClientCertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElFTPSServer_set_ClientCertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

void TElFTPSServer::get_SystemType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElFTPSServer_get_SystemType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(562058206, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElFTPSServer::set_SystemType(const std::string &Value)
{
	SBCheckError(TElFTPSServer_set_SystemType(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElFTPSServer::get_ImplicitSSL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFTPSServer_get_ImplicitSSL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElFTPSServer::set_ImplicitSSL(bool Value)
{
	SBCheckError(TElFTPSServer_set_ImplicitSSL(_Handle, (int8_t)Value));
}

TSBFTPSSecurityOptions TElFTPSServer::get_SecurityOptions()
{
	TSBFTPSSecurityOptionsRaw OutResultRaw = 0;
	SBCheckError(TElFTPSServer_get_SecurityOptions(_Handle, &OutResultRaw));
	return (TSBFTPSSecurityOptions)OutResultRaw;
}

SB_INLINE void TElFTPSServer::set_SecurityOptions(TSBFTPSSecurityOptions Value)
{
	SBCheckError(TElFTPSServer_set_SecurityOptions(_Handle, (TSBFTPSSecurityOptionsRaw)Value));
}

bool TElFTPSServer::get_UseUTF8()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFTPSServer_get_UseUTF8(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElFTPSServer::set_UseUTF8(bool Value)
{
	SBCheckError(TElFTPSServer_set_UseUTF8(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElFTPSServer::get_TransferBlockSize()
{
	int32_t OutResult;
	SBCheckError(TElFTPSServer_get_TransferBlockSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElFTPSServer::set_TransferBlockSize(int32_t Value)
{
	SBCheckError(TElFTPSServer_set_TransferBlockSize(_Handle, Value));
}

SB_INLINE void TElFTPSServer::get_OnOpen(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnOpen(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnOpen(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnOpen(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnCmdReceive(TSBReceiveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnCmdReceive(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnCmdReceive(TSBReceiveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnCmdReceive(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnCmdSend(TSBSendEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnCmdSend(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnCmdSend(TSBSendEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnCmdSend(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnDataReceive(TSBReceiveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnDataReceive(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnDataReceive(TSBReceiveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnDataReceive(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnDataSend(TSBSendEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnDataSend(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnDataSend(TSBSendEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnDataSend(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnTransferDataNeeded(TSBReceiveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnTransferDataNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnTransferDataNeeded(TSBReceiveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnTransferDataNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnTransferDataAvailable(TSBSendEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnTransferDataAvailable(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnTransferDataAvailable(TSBSendEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnTransferDataAvailable(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnTransferProgress(TSBFTPSServerTransferProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnTransferProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnTransferProgress(TSBFTPSServerTransferProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnTransferProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnTransferCompleted(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnTransferCompleted(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnTransferCompleted(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnTransferCompleted(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnAbortTransfer(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnAbortTransfer(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnAbortTransfer(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnAbortTransfer(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnClose(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnClose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnClose(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnClose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnCommandReceived(TSBFTPSServerCommandReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnCommandReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnCommandReceived(TSBFTPSServerCommandReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnCommandReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnCommandUnhandled(TSBFTPSServerCommandUnhandledEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnCommandUnhandled(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnCommandUnhandled(TSBFTPSServerCommandUnhandledEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnCommandUnhandled(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnCommandProcessed(TSBFTPSServerCommandProcessedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnCommandProcessed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnCommandProcessed(TSBFTPSServerCommandProcessedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnCommandProcessed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnBeforeSendReply(TSBFTPSServerBeforeSendReplyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnBeforeSendReply(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnBeforeSendReply(TSBFTPSServerBeforeSendReplyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnBeforeSendReply(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnUsernameReceived(TSBFTPSServerUsernameReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnUsernameReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnUsernameReceived(TSBFTPSServerUsernameReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnUsernameReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnPasswordAuth(TSBFTPSServerPasswordAuthEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnPasswordAuth(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnPasswordAuth(TSBFTPSServerPasswordAuthEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnPasswordAuth(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnWorkingDirectoryRequest(TSBFTPSServerDirectoryRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnWorkingDirectoryRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnWorkingDirectoryRequest(TSBFTPSServerDirectoryRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnWorkingDirectoryRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnMakeDirectoryRequest(TSBFTPSServerDirectoryRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnMakeDirectoryRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnMakeDirectoryRequest(TSBFTPSServerDirectoryRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnMakeDirectoryRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnRemoveDirectoryRequest(TSBFTPSServerDirectoryRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnRemoveDirectoryRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnRemoveDirectoryRequest(TSBFTPSServerDirectoryRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnRemoveDirectoryRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnRestartTransferRequest(TSBFTPSServerRestartTransferRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnRestartTransferRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnRestartTransferRequest(TSBFTPSServerRestartTransferRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnRestartTransferRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnChangeDirectoryRequest(TSBFTPSServerDirectoryRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnChangeDirectoryRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnChangeDirectoryRequest(TSBFTPSServerDirectoryRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnChangeDirectoryRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnDataPortChange(TSBFTPSServerDataPortChangeEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnDataPortChange(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnDataPortChange(TSBFTPSServerDataPortChangeEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnDataPortChange(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnPassiveModeRequest(TSBFTPSServerPassiveModeRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnPassiveModeRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnPassiveModeRequest(TSBFTPSServerPassiveModeRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnPassiveModeRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnDataConnectionNeeded(TSBFTPSServerDataConnectionNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnDataConnectionNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnDataConnectionNeeded(TSBFTPSServerDataConnectionNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnDataConnectionNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnDataConnectionClose(TSBFTPSServerDataConnectionCloseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnDataConnectionClose(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnDataConnectionClose(TSBFTPSServerDataConnectionCloseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnDataConnectionClose(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnFileListRequest(TSBFTPSServerDirectoryRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnFileListRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnFileListRequest(TSBFTPSServerDirectoryRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnFileListRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnFileListItemRequest(TSBFTPSServerFileListItemRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnFileListItemRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnFileListItemRequest(TSBFTPSServerFileListItemRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnFileListItemRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnFileListCompleted(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnFileListCompleted(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnFileListCompleted(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnFileListCompleted(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnFileRetrieveRequest(TSBFTPSServerFileRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnFileRetrieveRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnFileRetrieveRequest(TSBFTPSServerFileRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnFileRetrieveRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnFileAllocate(TSBFTPSServerFileAllocateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnFileAllocate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnFileAllocate(TSBFTPSServerFileAllocateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnFileAllocate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnFileStoreRequest(TSBFTPSServerFileRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnFileStoreRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnFileStoreRequest(TSBFTPSServerFileRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnFileStoreRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnFileAppendRequest(TSBFTPSServerFileRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnFileAppendRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnFileAppendRequest(TSBFTPSServerFileRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnFileAppendRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnFileInfoNeeded(TSBFTPSServerFileInfoNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnFileInfoNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnFileInfoNeeded(TSBFTPSServerFileInfoNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnFileInfoNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnFileRemoveRequest(TSBFTPSServerFileRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnFileRemoveRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnFileRemoveRequest(TSBFTPSServerFileRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnFileRemoveRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnFileRenameRequest(TSBFTPSServerFileRenameRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnFileRenameRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnFileRenameRequest(TSBFTPSServerFileRenameRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnFileRenameRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnStatusRequest(TSBFTPSServerInformationRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnStatusRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnStatusRequest(TSBFTPSServerInformationRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnStatusRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnVirtualHostRequest(TSBFTPSServerHostRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnVirtualHostRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnVirtualHostRequest(TSBFTPSServerHostRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnVirtualHostRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnEstablishSecureConnection(TSBFTPSServerEstablishSecureConnectionEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnEstablishSecureConnection(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnEstablishSecureConnection(TSBFTPSServerEstablishSecureConnectionEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnEstablishSecureConnection(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnExtPassiveModeRequest(TSBFTPSServerExtPassiveModeRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnExtPassiveModeRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnExtPassiveModeRequest(TSBFTPSServerExtPassiveModeRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnExtPassiveModeRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElFTPSServer::get_OnSiteCommand(TSBFTPSServerSiteCommandEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFTPSServer_get_OnSiteCommand(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFTPSServer::set_OnSiteCommand(TSBFTPSServerSiteCommandEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFTPSServer_set_OnSiteCommand(_Handle, pMethodValue, pDataValue));
}

void TElFTPSServer::initInstances()
{
#ifdef SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE
	this->_Inst_MessageTable = NULL;
#endif /* SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE */
#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
	this->_Inst_ControlChannelSSLConnectionInfo = NULL;
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */
#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
	this->_Inst_DataChannelSSLConnectionInfo = NULL;
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELSESSIONPOOL
	this->_Inst_SessionPool = NULL;
#endif /* SB_USE_CLASS_TELSESSIONPOOL */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_ClientCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElFTPSServer::TElFTPSServer(TElFTPSServerHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElFTPSServer::TElFTPSServer(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElFTPSServer_Create(AOwner.getHandle(), &_Handle));
}

TElFTPSServer::TElFTPSServer(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElFTPSServer_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElFTPSServer::~TElFTPSServer()
{
#ifdef SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE
	delete this->_Inst_MessageTable;
	this->_Inst_MessageTable = NULL;
#endif /* SB_USE_CLASS_TELFTPSSERVERMESSAGETABLE */
#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
	delete this->_Inst_ControlChannelSSLConnectionInfo;
	this->_Inst_ControlChannelSSLConnectionInfo = NULL;
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */
#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
	delete this->_Inst_DataChannelSSLConnectionInfo;
	this->_Inst_DataChannelSSLConnectionInfo = NULL;
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELSESSIONPOOL
	delete this->_Inst_SessionPool;
	this->_Inst_SessionPool = NULL;
#endif /* SB_USE_CLASS_TELSESSIONPOOL */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_ClientCertStorage;
	this->_Inst_ClientCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELFTPSSERVER */

};	/* namespace SecureBlackbox */

