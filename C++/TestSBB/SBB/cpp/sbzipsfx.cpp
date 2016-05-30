#include "sbdefs.h"
#ifndef SB_WINCE_OR_NOT_WINDOWS
#include "sbzipsfx.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELZIPSFXSTUB

SB_INLINE int32_t TElZIPSFXStub::Execute()
{
	int32_t OutResult;
	SBCheckError(TElZIPSFXStub_Execute(_Handle, &OutResult));
	return OutResult;
}

void TElZIPSFXStub::get_Copyright(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZIPSFXStub_get_Copyright(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1890020117, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElZIPSFXStub::get_Copyright(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElZIPSFXStub_get_Copyright(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1890020117, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
bool TElZIPSFXStub::get_Evaluation()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZIPSFXStub_get_Evaluation(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElZIPSFXStub::get_Title(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZIPSFXStub_get_Title(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1833463158, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElZIPSFXStub::get_Title(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElZIPSFXStub_get_Title(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1833463158, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
TSBZIPSFXCommandLineSwitches TElZIPSFXStub::get_UsedSwitches()
{
	TSBZIPSFXCommandLineSwitchesRaw OutResultRaw = 0;
	SBCheckError(TElZIPSFXStub_get_UsedSwitches(_Handle, &OutResultRaw));
	return (TSBZIPSFXCommandLineSwitches)OutResultRaw;
}

void TElZIPSFXStub::get_Extract(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZIPSFXStub_get_Extract(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-315429464, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZIPSFXStub::set_Extract(const std::string &Value)
{
	SBCheckError(TElZIPSFXStub_set_Extract(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElZIPSFXStub::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZIPSFXStub_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1584731533, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZIPSFXStub::set_Password(const std::string &Value)
{
	SBCheckError(TElZIPSFXStub_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElZIPSFXStub::get_CertFile(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZIPSFXStub_get_CertFile(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-835787556, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZIPSFXStub::set_CertFile(const std::string &Value)
{
	SBCheckError(TElZIPSFXStub_set_CertFile(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElZIPSFXStub::get_CertPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZIPSFXStub_get_CertPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1021536660, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZIPSFXStub::set_CertPassword(const std::string &Value)
{
	SBCheckError(TElZIPSFXStub_set_CertPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElZIPSFXStub::get_Silent()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZIPSFXStub_get_Silent(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZIPSFXStub::set_Silent(bool Value)
{
	SBCheckError(TElZIPSFXStub_set_Silent(_Handle, (int8_t)Value));
}

TSBZIPSFXCommandLineSwitches TElZIPSFXStub::get_SupportedSwitches()
{
	TSBZIPSFXCommandLineSwitchesRaw OutResultRaw = 0;
	SBCheckError(TElZIPSFXStub_get_SupportedSwitches(_Handle, &OutResultRaw));
	return (TSBZIPSFXCommandLineSwitches)OutResultRaw;
}

SB_INLINE void TElZIPSFXStub::set_SupportedSwitches(TSBZIPSFXCommandLineSwitches Value)
{
	SBCheckError(TElZIPSFXStub_set_SupportedSwitches(_Handle, (TSBZIPSFXCommandLineSwitchesRaw)Value));
}

void TElZIPSFXStub::get_Target(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZIPSFXStub_get_Target(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-147991875, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZIPSFXStub::set_Target(const std::string &Value)
{
	SBCheckError(TElZIPSFXStub_set_Target(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElZIPSFXStub::get_UseCommandLine()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZIPSFXStub_get_UseCommandLine(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZIPSFXStub::set_UseCommandLine(bool Value)
{
	SBCheckError(TElZIPSFXStub_set_UseCommandLine(_Handle, (int8_t)Value));
}

SB_INLINE void TElZIPSFXStub::get_OnAbort(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZIPSFXStub_get_OnAbort(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZIPSFXStub::set_OnAbort(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZIPSFXStub_set_OnAbort(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZIPSFXStub::get_OnCommandLine(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZIPSFXStub_get_OnCommandLine(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZIPSFXStub::set_OnCommandLine(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZIPSFXStub_set_OnCommandLine(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZIPSFXStub::get_OnError(TSBZIPSFXErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZIPSFXStub_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZIPSFXStub::set_OnError(TSBZIPSFXErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZIPSFXStub_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZIPSFXStub::get_OnExtracting(TSBZIPSFXExtractingEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZIPSFXStub_get_OnExtracting(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZIPSFXStub::set_OnExtracting(TSBZIPSFXExtractingEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZIPSFXStub_set_OnExtracting(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZIPSFXStub::get_OnFinish(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZIPSFXStub_get_OnFinish(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZIPSFXStub::set_OnFinish(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZIPSFXStub_set_OnFinish(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZIPSFXStub::get_OnPasswordNeeded(TSBZipPasswordNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZIPSFXStub_get_OnPasswordNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZIPSFXStub::set_OnPasswordNeeded(TSBZipPasswordNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZIPSFXStub_set_OnPasswordNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZIPSFXStub::get_OnProgress(TSBZipProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZIPSFXStub_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZIPSFXStub::set_OnProgress(TSBZipProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZIPSFXStub_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZIPSFXStub::get_OnFileStart(TSBZipExtractionStartEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZIPSFXStub_get_OnFileStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZIPSFXStub::set_OnFileStart(TSBZipExtractionStartEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZIPSFXStub_set_OnFileStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZIPSFXStub::get_OnFileFinish(TSBZipExtractionFinishedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZIPSFXStub_get_OnFileFinish(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZIPSFXStub::set_OnFileFinish(TSBZipExtractionFinishedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZIPSFXStub_set_OnFileFinish(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZIPSFXStub::get_OnUserActionNeeded(TSBZipUserActionNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZIPSFXStub_get_OnUserActionNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZIPSFXStub::set_OnUserActionNeeded(TSBZipUserActionNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZIPSFXStub_set_OnUserActionNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZIPSFXStub::get_OnStart(TSBZIPSFXStartEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZIPSFXStub_get_OnStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZIPSFXStub::set_OnStart(TSBZIPSFXStartEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZIPSFXStub_set_OnStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZIPSFXStub::get_OnTargetFolder(TSBZIPSFXTargetFolderEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZIPSFXStub_get_OnTargetFolder(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZIPSFXStub::set_OnTargetFolder(TSBZIPSFXTargetFolderEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZIPSFXStub_set_OnTargetFolder(_Handle, pMethodValue, pDataValue));
}

TElZIPSFXStub::TElZIPSFXStub(TElZIPSFXStubHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElZIPSFXStub::TElZIPSFXStub(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZIPSFXStub_Create(AOwner.getHandle(), &_Handle));
}

TElZIPSFXStub::TElZIPSFXStub(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZIPSFXStub_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELZIPSFXSTUB */

};	/* namespace SecureBlackbox */
#endif
