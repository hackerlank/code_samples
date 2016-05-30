#include "sbdefs.h"
#ifndef SB_WINCE_OR_NOT_WINDOWS
#include "sbpgpsfx.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPGPSFXSTUB

SB_INLINE int32_t TElPGPSFXStub::Execute()
{
	int32_t OutResult;
	SBCheckError(TElPGPSFXStub_Execute(_Handle, &OutResult));
	return OutResult;
}

void TElPGPSFXStub::get_Copyright(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPSFXStub_get_Copyright(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(95460200, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElPGPSFXStub::get_Copyright(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElPGPSFXStub_get_Copyright(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(95460200, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
bool TElPGPSFXStub::get_Evaluation()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSFXStub_get_Evaluation(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPGPSFXStub::get_Title(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPSFXStub_get_Title(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-785770764, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElPGPSFXStub::get_Title(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElPGPSFXStub_get_Title(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-785770764, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
TSBPGPSFXCommandLineSwitches TElPGPSFXStub::get_UsedSwitches()
{
	TSBPGPSFXCommandLineSwitchesRaw OutResultRaw = 0;
	SBCheckError(TElPGPSFXStub_get_UsedSwitches(_Handle, &OutResultRaw));
	return (TSBPGPSFXCommandLineSwitches)OutResultRaw;
}

void TElPGPSFXStub::get_Extract(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPSFXStub_get_Extract(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(592446391, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPSFXStub::set_Extract(const std::string &Value)
{
	SBCheckError(TElPGPSFXStub_set_Extract(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPGPSFXStub::get_KeyPassphrase(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPSFXStub_get_KeyPassphrase(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-208562108, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPSFXStub::set_KeyPassphrase(const std::string &Value)
{
	SBCheckError(TElPGPSFXStub_set_KeyPassphrase(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElPGPSFXStub::get_Overwrite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSFXStub_get_Overwrite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPSFXStub::set_Overwrite(bool Value)
{
	SBCheckError(TElPGPSFXStub_set_Overwrite(_Handle, (int8_t)Value));
}

void TElPGPSFXStub::get_Passphrase(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPSFXStub_get_Passphrase(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(133167020, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPSFXStub::set_Passphrase(const std::string &Value)
{
	SBCheckError(TElPGPSFXStub_set_Passphrase(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPGPSFXStub::get_PublicKeys(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPSFXStub_get_PublicKeys(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(6035757, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPSFXStub::set_PublicKeys(const std::string &Value)
{
	SBCheckError(TElPGPSFXStub_set_PublicKeys(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPGPSFXStub::get_SecretKeys(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPSFXStub_get_SecretKeys(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(434277563, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPSFXStub::set_SecretKeys(const std::string &Value)
{
	SBCheckError(TElPGPSFXStub_set_SecretKeys(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElPGPSFXStub::get_Silent()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSFXStub_get_Silent(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPSFXStub::set_Silent(bool Value)
{
	SBCheckError(TElPGPSFXStub_set_Silent(_Handle, (int8_t)Value));
}

TSBPGPSFXCommandLineSwitches TElPGPSFXStub::get_SupportedSwitches()
{
	TSBPGPSFXCommandLineSwitchesRaw OutResultRaw = 0;
	SBCheckError(TElPGPSFXStub_get_SupportedSwitches(_Handle, &OutResultRaw));
	return (TSBPGPSFXCommandLineSwitches)OutResultRaw;
}

SB_INLINE void TElPGPSFXStub::set_SupportedSwitches(TSBPGPSFXCommandLineSwitches Value)
{
	SBCheckError(TElPGPSFXStub_set_SupportedSwitches(_Handle, (TSBPGPSFXCommandLineSwitchesRaw)Value));
}

void TElPGPSFXStub::get_Target(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPSFXStub_get_Target(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-198749494, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPSFXStub::set_Target(const std::string &Value)
{
	SBCheckError(TElPGPSFXStub_set_Target(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBPGPSFXTempFileLocation TElPGPSFXStub::get_TempFileLocation()
{
	TSBPGPSFXTempFileLocationRaw OutResultRaw = 0;
	SBCheckError(TElPGPSFXStub_get_TempFileLocation(_Handle, &OutResultRaw));
	return (TSBPGPSFXTempFileLocation)OutResultRaw;
}

SB_INLINE void TElPGPSFXStub::set_TempFileLocation(TSBPGPSFXTempFileLocation Value)
{
	SBCheckError(TElPGPSFXStub_set_TempFileLocation(_Handle, (TSBPGPSFXTempFileLocationRaw)Value));
}

bool TElPGPSFXStub::get_UseCommandLine()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSFXStub_get_UseCommandLine(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPSFXStub::set_UseCommandLine(bool Value)
{
	SBCheckError(TElPGPSFXStub_set_UseCommandLine(_Handle, (int8_t)Value));
}

SB_INLINE void TElPGPSFXStub::get_OnAbort(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSFXStub_get_OnAbort(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSFXStub::set_OnAbort(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSFXStub_set_OnAbort(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPSFXStub::get_OnCommandLine(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSFXStub_get_OnCommandLine(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSFXStub::set_OnCommandLine(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSFXStub_set_OnCommandLine(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPSFXStub::get_OnEncrypted(TSBPGPEncryptedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSFXStub_get_OnEncrypted(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSFXStub::set_OnEncrypted(TSBPGPEncryptedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSFXStub_set_OnEncrypted(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPSFXStub::get_OnError(TSBPGPSFXErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSFXStub_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSFXStub::set_OnError(TSBPGPSFXErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSFXStub_set_OnError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPSFXStub::get_OnExtracting(TSBPGPSFXExtractingEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSFXStub_get_OnExtracting(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSFXStub::set_OnExtracting(TSBPGPSFXExtractingEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSFXStub_set_OnExtracting(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPSFXStub::get_OnFileError(TSBPGPSFXFileErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSFXStub_get_OnFileError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSFXStub::set_OnFileError(TSBPGPSFXFileErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSFXStub_set_OnFileError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPSFXStub::get_OnFileExists(TSBPGPSFXFileExistsEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSFXStub_get_OnFileExists(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSFXStub::set_OnFileExists(TSBPGPSFXFileExistsEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSFXStub_set_OnFileExists(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPSFXStub::get_OnFileFinish(TSBPGPSFXFileEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSFXStub_get_OnFileFinish(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSFXStub::set_OnFileFinish(TSBPGPSFXFileEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSFXStub_set_OnFileFinish(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPSFXStub::get_OnFileProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSFXStub_get_OnFileProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSFXStub::set_OnFileProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSFXStub_set_OnFileProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPSFXStub::get_OnFileStart(TSBPGPSFXFileEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSFXStub_get_OnFileStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSFXStub::set_OnFileStart(TSBPGPSFXFileEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSFXStub_set_OnFileStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPSFXStub::get_OnFinish(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSFXStub_get_OnFinish(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSFXStub::set_OnFinish(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSFXStub_set_OnFinish(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPSFXStub::get_OnKeyPassphrase(TSBPGPSFXKeyPassphraseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSFXStub_get_OnKeyPassphrase(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSFXStub::set_OnKeyPassphrase(TSBPGPSFXKeyPassphraseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSFXStub_set_OnKeyPassphrase(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPSFXStub::get_OnOutputStream(TSBPGPCreateOutputStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSFXStub_get_OnOutputStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSFXStub::set_OnOutputStream(TSBPGPCreateOutputStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSFXStub_set_OnOutputStream(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPSFXStub::get_OnPassphrase(TSBPGPSFXPassphraseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSFXStub_get_OnPassphrase(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSFXStub::set_OnPassphrase(TSBPGPSFXPassphraseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSFXStub_set_OnPassphrase(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPSFXStub::get_OnProgress(TSBPGPProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSFXStub_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSFXStub::set_OnProgress(TSBPGPProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSFXStub_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPSFXStub::get_OnSigned(TSBPGPSignedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSFXStub_get_OnSigned(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSFXStub::set_OnSigned(TSBPGPSignedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSFXStub_set_OnSigned(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPSFXStub::get_OnStart(TSBPGPSFXStartEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSFXStub_get_OnStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSFXStub::set_OnStart(TSBPGPSFXStartEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSFXStub_set_OnStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPSFXStub::get_OnTargetFolder(TSBPGPSFXTargetFolderEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSFXStub_get_OnTargetFolder(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSFXStub::set_OnTargetFolder(TSBPGPSFXTargetFolderEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSFXStub_set_OnTargetFolder(_Handle, pMethodValue, pDataValue));
}

TElPGPSFXStub::TElPGPSFXStub(TElPGPSFXStubHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElPGPSFXStub::TElPGPSFXStub(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPSFXStub_Create(AOwner.getHandle(), &_Handle));
}

TElPGPSFXStub::TElPGPSFXStub(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPSFXStub_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELPGPSFXSTUB */

#ifdef SB_USE_CLASS_TELPGPSFXMAKER

bool TElPGPSFXMaker::Execute()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSFXMaker_Execute(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPSFXMaker::Update()
{
	SBCheckError(TElPGPSFXMaker_Update(_Handle));
}

void TElPGPSFXMaker::get_Copyright(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPSFXMaker_get_Copyright(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1654230653, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPSFXMaker::set_Copyright(const std::string &Value)
{
	SBCheckError(TElPGPSFXMaker_set_Copyright(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPGPSFXMaker::get_Title(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPSFXMaker_get_Title(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-419151119, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPSFXMaker::set_Title(const std::string &Value)
{
	SBCheckError(TElPGPSFXMaker_set_Title(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElPGPSFXMaker::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSFXMaker_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSFXMaker::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSFXMaker_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

TElPGPSFXMaker::TElPGPSFXMaker(TElPGPSFXMakerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TSTREAM
TElPGPSFXMaker::TElPGPSFXMaker(TStream &AStub, TStream &AOutput) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPSFXMaker_Create(AStub.getHandle(), AOutput.getHandle(), &_Handle));
}

TElPGPSFXMaker::TElPGPSFXMaker(TStream *AStub, TStream *AOutput) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPSFXMaker_Create((AStub != NULL) ? AStub->getHandle() : SB_NULL_HANDLE, (AOutput != NULL) ? AOutput->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TSTREAM */

#endif /* SB_USE_CLASS_TELPGPSFXMAKER */

};	/* namespace SecureBlackbox */
#endif
