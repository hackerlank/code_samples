#include "sbsftpcommon.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE

SB_INLINE void TSBSftpExtendedAttribute::Assign(TPersistent &Source)
{
	SBCheckError(TSBSftpExtendedAttribute_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TSBSftpExtendedAttribute::Assign(TPersistent *Source)
{
	SBCheckError(TSBSftpExtendedAttribute_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TSBSftpExtendedAttribute::AssignTo(TPersistent &Dest)
{
	SBCheckError(TSBSftpExtendedAttribute_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TSBSftpExtendedAttribute::AssignTo(TPersistent *Dest)
{
	SBCheckError(TSBSftpExtendedAttribute_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

bool TSBSftpExtendedAttribute::LoadFromBuffer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TSBSftpExtendedAttribute_LoadFromBuffer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TSBSftpExtendedAttribute::SaveToBuffer()
{
	SBCheckError(TSBSftpExtendedAttribute_SaveToBuffer(_Handle));
}

void TSBSftpExtendedAttribute::Write(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TSBSftpExtendedAttribute_Write(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-193916653, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TSBSftpExtendedAttribute::get_ExtType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TSBSftpExtendedAttribute_get_ExtType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1063142528, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TSBSftpExtendedAttribute::set_ExtType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TSBSftpExtendedAttribute_set_ExtType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TSBSftpExtendedAttribute::get_ExtData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TSBSftpExtendedAttribute_get_ExtData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-510910518, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TSBSftpExtendedAttribute::set_ExtData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TSBSftpExtendedAttribute_set_ExtData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TSBSftpExtendedAttribute::get_UseUTF8()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TSBSftpExtendedAttribute_get_UseUTF8(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TSBSftpExtendedAttribute::set_UseUTF8(bool Value)
{
	SBCheckError(TSBSftpExtendedAttribute_set_UseUTF8(_Handle, (int8_t)Value));
}

bool TSBSftpExtendedAttribute::get_NoCharacterEncoding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TSBSftpExtendedAttribute_get_NoCharacterEncoding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TSBSftpExtendedAttribute::set_NoCharacterEncoding(bool Value)
{
	SBCheckError(TSBSftpExtendedAttribute_set_NoCharacterEncoding(_Handle, (int8_t)Value));
}

void TSBSftpExtendedAttribute::get_LocalCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TSBSftpExtendedAttribute_get_LocalCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1105578817, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TSBSftpExtendedAttribute::set_LocalCharset(const std::string &Value)
{
	SBCheckError(TSBSftpExtendedAttribute_set_LocalCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

void TSBSftpExtendedAttribute::get_RemoteCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TSBSftpExtendedAttribute_get_RemoteCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-228878015, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TSBSftpExtendedAttribute::set_RemoteCharset(const std::string &Value)
{
	SBCheckError(TSBSftpExtendedAttribute_set_RemoteCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBSftpExtendedAttribute::TSBSftpExtendedAttribute(TSBSftpExtendedAttributeHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TSBSftpExtendedAttribute::TSBSftpExtendedAttribute() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBSftpExtendedAttribute_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE */

#ifdef SB_USE_CLASS_TELSFTPEXTENDEDREPLY

SB_INLINE void TElSftpExtendedReply::Assign(TPersistent &Source)
{
	SBCheckError(TElSftpExtendedReply_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSftpExtendedReply::Assign(TPersistent *Source)
{
	SBCheckError(TElSftpExtendedReply_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElSftpExtendedReply::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElSftpExtendedReply_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElSftpExtendedReply::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElSftpExtendedReply_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

bool TElSftpExtendedReply::LoadFromBuffer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpExtendedReply_LoadFromBuffer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpExtendedReply::SaveToBuffer()
{
	SBCheckError(TElSftpExtendedReply_SaveToBuffer(_Handle));
}

void TElSftpExtendedReply::Write(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSftpExtendedReply_Write(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-863790581, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElSftpExtendedReply::get_UseUTF8()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpExtendedReply_get_UseUTF8(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpExtendedReply::set_UseUTF8(bool Value)
{
	SBCheckError(TElSftpExtendedReply_set_UseUTF8(_Handle, (int8_t)Value));
}

bool TElSftpExtendedReply::get_NoCharacterEncoding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpExtendedReply_get_NoCharacterEncoding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpExtendedReply::set_NoCharacterEncoding(bool Value)
{
	SBCheckError(TElSftpExtendedReply_set_NoCharacterEncoding(_Handle, (int8_t)Value));
}

void TElSftpExtendedReply::get_LocalCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpExtendedReply_get_LocalCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1290433932, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpExtendedReply::set_LocalCharset(const std::string &Value)
{
	SBCheckError(TElSftpExtendedReply_set_LocalCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSftpExtendedReply::get_RemoteCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpExtendedReply_get_RemoteCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1299777558, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpExtendedReply::set_RemoteCharset(const std::string &Value)
{
	SBCheckError(TElSftpExtendedReply_set_RemoteCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSftpExtendedReply::get_ReplyData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSftpExtendedReply_get_ReplyData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1478958108, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpExtendedReply::set_ReplyData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSftpExtendedReply_set_ReplyData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElSftpExtendedReply::TElSftpExtendedReply(TElSftpExtendedReplyHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElSftpExtendedReply::TElSftpExtendedReply() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSftpExtendedReply_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSFTPEXTENDEDREPLY */

#ifdef SB_USE_CLASS_TELSFTPNEWLINEEXTENSION

SB_INLINE void TElSftpNewlineExtension::Assign(TPersistent &Source)
{
	SBCheckError(TElSftpNewlineExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSftpNewlineExtension::Assign(TPersistent *Source)
{
	SBCheckError(TElSftpNewlineExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElSftpNewlineExtension::LoadFromBuffer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpNewlineExtension_LoadFromBuffer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpNewlineExtension::SaveToBuffer()
{
	SBCheckError(TElSftpNewlineExtension_SaveToBuffer(_Handle));
}

void TElSftpNewlineExtension::get_Newline(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSftpNewlineExtension_get_Newline(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1312189200, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpNewlineExtension::set_Newline(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSftpNewlineExtension_set_Newline(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElSftpNewlineExtension::TElSftpNewlineExtension(TElSftpNewlineExtensionHandle handle, TElOwnHandle ownHandle) : TSBSftpExtendedAttribute(handle, ownHandle)
{
}

TElSftpNewlineExtension::TElSftpNewlineExtension() : TSBSftpExtendedAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSftpNewlineExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSFTPNEWLINEEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPVERSIONSEXTENSION

SB_INLINE void TElSftpVersionsExtension::Assign(TPersistent &Source)
{
	SBCheckError(TElSftpVersionsExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSftpVersionsExtension::Assign(TPersistent *Source)
{
	SBCheckError(TElSftpVersionsExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElSftpVersionsExtension::LoadFromBuffer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpVersionsExtension_LoadFromBuffer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpVersionsExtension::SaveToBuffer()
{
	SBCheckError(TElSftpVersionsExtension_SaveToBuffer(_Handle));
}

TSBSftpVersions TElSftpVersionsExtension::get_Versions()
{
	TSBSftpVersionsRaw OutResultRaw = 0;
	SBCheckError(TElSftpVersionsExtension_get_Versions(_Handle, &OutResultRaw));
	return (TSBSftpVersions)OutResultRaw;
}

SB_INLINE void TElSftpVersionsExtension::set_Versions(TSBSftpVersions Value)
{
	SBCheckError(TElSftpVersionsExtension_set_Versions(_Handle, (TSBSftpVersionsRaw)Value));
}

void TElSftpVersionsExtension::get_VersionsStr(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpVersionsExtension_get_VersionsStr(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1775132155, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElSftpVersionsExtension::TElSftpVersionsExtension(TElSftpVersionsExtensionHandle handle, TElOwnHandle ownHandle) : TSBSftpExtendedAttribute(handle, ownHandle)
{
}

TElSftpVersionsExtension::TElSftpVersionsExtension() : TSBSftpExtendedAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSftpVersionsExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSFTPVERSIONSEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPFILENAMETRANSLATIONEXTENSION

SB_INLINE void TElSftpFilenameTranslationExtension::Assign(TPersistent &Source)
{
	SBCheckError(TElSftpFilenameTranslationExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSftpFilenameTranslationExtension::Assign(TPersistent *Source)
{
	SBCheckError(TElSftpFilenameTranslationExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElSftpFilenameTranslationExtension::LoadFromBuffer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpFilenameTranslationExtension_LoadFromBuffer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpFilenameTranslationExtension::SaveToBuffer()
{
	SBCheckError(TElSftpFilenameTranslationExtension_SaveToBuffer(_Handle));
}

bool TElSftpFilenameTranslationExtension::get_DoTranslate()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpFilenameTranslationExtension_get_DoTranslate(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpFilenameTranslationExtension::set_DoTranslate(bool Value)
{
	SBCheckError(TElSftpFilenameTranslationExtension_set_DoTranslate(_Handle, (int8_t)Value));
}

TElSftpFilenameTranslationExtension::TElSftpFilenameTranslationExtension(TElSftpFilenameTranslationExtensionHandle handle, TElOwnHandle ownHandle) : TSBSftpExtendedAttribute(handle, ownHandle)
{
}

TElSftpFilenameTranslationExtension::TElSftpFilenameTranslationExtension() : TSBSftpExtendedAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSftpFilenameTranslationExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSFTPFILENAMETRANSLATIONEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPFILENAMECHARSETEXTENSION

SB_INLINE void TElSftpFilenameCharsetExtension::Assign(TPersistent &Source)
{
	SBCheckError(TElSftpFilenameCharsetExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSftpFilenameCharsetExtension::Assign(TPersistent *Source)
{
	SBCheckError(TElSftpFilenameCharsetExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElSftpFilenameCharsetExtension::LoadFromBuffer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpFilenameCharsetExtension_LoadFromBuffer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpFilenameCharsetExtension::SaveToBuffer()
{
	SBCheckError(TElSftpFilenameCharsetExtension_SaveToBuffer(_Handle));
}

void TElSftpFilenameCharsetExtension::get_Charset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpFilenameCharsetExtension_get_Charset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1727243874, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpFilenameCharsetExtension::set_Charset(const std::string &Value)
{
	SBCheckError(TElSftpFilenameCharsetExtension_set_Charset(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSftpFilenameCharsetExtension::TElSftpFilenameCharsetExtension(TElSftpFilenameCharsetExtensionHandle handle, TElOwnHandle ownHandle) : TSBSftpExtendedAttribute(handle, ownHandle)
{
}

TElSftpFilenameCharsetExtension::TElSftpFilenameCharsetExtension() : TSBSftpExtendedAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSftpFilenameCharsetExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSFTPFILENAMECHARSETEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPVERSIONSELECTEXTENSION

SB_INLINE void TElSftpVersionSelectExtension::Assign(TPersistent &Source)
{
	SBCheckError(TElSftpVersionSelectExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSftpVersionSelectExtension::Assign(TPersistent *Source)
{
	SBCheckError(TElSftpVersionSelectExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElSftpVersionSelectExtension::LoadFromBuffer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpVersionSelectExtension_LoadFromBuffer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpVersionSelectExtension::SaveToBuffer()
{
	SBCheckError(TElSftpVersionSelectExtension_SaveToBuffer(_Handle));
}

TSBSftpVersion TElSftpVersionSelectExtension::get_Version()
{
	TSBSftpVersionRaw OutResultRaw = 0;
	SBCheckError(TElSftpVersionSelectExtension_get_Version(_Handle, &OutResultRaw));
	return (TSBSftpVersion)OutResultRaw;
}

SB_INLINE void TElSftpVersionSelectExtension::set_Version(TSBSftpVersion Value)
{
	SBCheckError(TElSftpVersionSelectExtension_set_Version(_Handle, (TSBSftpVersionRaw)Value));
}

SB_INLINE int32_t TElSftpVersionSelectExtension::get_VersionInt()
{
	int32_t OutResult;
	SBCheckError(TElSftpVersionSelectExtension_get_VersionInt(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpVersionSelectExtension::set_VersionInt(int32_t Value)
{
	SBCheckError(TElSftpVersionSelectExtension_set_VersionInt(_Handle, Value));
}

void TElSftpVersionSelectExtension::get_VersionStr(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpVersionSelectExtension_get_VersionStr(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(647061371, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpVersionSelectExtension::set_VersionStr(const std::string &Value)
{
	SBCheckError(TElSftpVersionSelectExtension_set_VersionStr(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSftpVersionSelectExtension::TElSftpVersionSelectExtension(TElSftpVersionSelectExtensionHandle handle, TElOwnHandle ownHandle) : TSBSftpExtendedAttribute(handle, ownHandle)
{
}

TElSftpVersionSelectExtension::TElSftpVersionSelectExtension() : TSBSftpExtendedAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSftpVersionSelectExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSFTPVERSIONSELECTEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION

SB_INLINE void TElSftpSupportedExtension::Assign(TPersistent &Source)
{
	SBCheckError(TElSftpSupportedExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSftpSupportedExtension::Assign(TPersistent *Source)
{
	SBCheckError(TElSftpSupportedExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElSftpSupportedExtension::Clear()
{
	SBCheckError(TElSftpSupportedExtension_Clear(_Handle));
}

SB_INLINE void TElSftpSupportedExtension::FillDefault()
{
	SBCheckError(TElSftpSupportedExtension_FillDefault(_Handle));
}

bool TElSftpSupportedExtension::LoadFromBuffer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpSupportedExtension_LoadFromBuffer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpSupportedExtension::SaveToBuffer()
{
	SBCheckError(TElSftpSupportedExtension_SaveToBuffer(_Handle));
}

bool TElSftpSupportedExtension::IsSupportedOpenBlockMode(TSBSftpFileOpenAccess Mode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpSupportedExtension_IsSupportedOpenBlockMode(_Handle, (TSBSftpFileOpenAccessRaw)Mode, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpSupportedExtension::SetSupportedOpenBlockMode(TSBSftpFileOpenAccess Mode, bool Supported)
{
	SBCheckError(TElSftpSupportedExtension_SetSupportedOpenBlockMode(_Handle, (TSBSftpFileOpenAccessRaw)Mode, (int8_t)Supported));
}

bool TElSftpSupportedExtension::IsSupportedBlockMode(TSBSftpFileOpenAccess Mode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpSupportedExtension_IsSupportedBlockMode(_Handle, (TSBSftpFileOpenAccessRaw)Mode, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpSupportedExtension::SetSupportedBlockMode(TSBSftpFileOpenAccess Mode, bool Supported)
{
	SBCheckError(TElSftpSupportedExtension_SetSupportedBlockMode(_Handle, (TSBSftpFileOpenAccessRaw)Mode, (int8_t)Supported));
}

bool TElSftpSupportedExtension::IsSupportedExtension(const std::string &ExtName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpSupportedExtension_IsSupportedExtension(_Handle, ExtName.data(), (int32_t)ExtName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpSupportedExtension::SetSupportedExtension(const std::string &ExtName, bool Support)
{
	SBCheckError(TElSftpSupportedExtension_SetSupportedExtension(_Handle, ExtName.data(), (int32_t)ExtName.length(), (int8_t)Support));
}

bool TElSftpSupportedExtension::IsSupportedAttrExtension(const std::string &ExtName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpSupportedExtension_IsSupportedAttrExtension(_Handle, ExtName.data(), (int32_t)ExtName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpSupportedExtension::SetSupportedAttrExtension(const std::string &ExtName, bool Support)
{
	SBCheckError(TElSftpSupportedExtension_SetSupportedAttrExtension(_Handle, ExtName.data(), (int32_t)ExtName.length(), (int8_t)Support));
}

TSBSftpAttributes TElSftpSupportedExtension::get_SupportedAttributes()
{
	TSBSftpAttributesRaw OutResultRaw = 0;
	SBCheckError(TElSftpSupportedExtension_get_SupportedAttributes(_Handle, &OutResultRaw));
	return (TSBSftpAttributes)OutResultRaw;
}

SB_INLINE void TElSftpSupportedExtension::set_SupportedAttributes(TSBSftpAttributes Value)
{
	SBCheckError(TElSftpSupportedExtension_set_SupportedAttributes(_Handle, (TSBSftpAttributesRaw)Value));
}

SB_INLINE uint32_t TElSftpSupportedExtension::get_SupportedAttribBits()
{
	uint32_t OutResult;
	SBCheckError(TElSftpSupportedExtension_get_SupportedAttribBits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpSupportedExtension::set_SupportedAttribBits(uint32_t Value)
{
	SBCheckError(TElSftpSupportedExtension_set_SupportedAttribBits(_Handle, Value));
}

TSBSftpFileOpenModes TElSftpSupportedExtension::get_SupportedOpenModes()
{
	TSBSftpFileOpenModesRaw OutResultRaw = 0;
	SBCheckError(TElSftpSupportedExtension_get_SupportedOpenModes(_Handle, &OutResultRaw));
	return (TSBSftpFileOpenModes)OutResultRaw;
}

SB_INLINE void TElSftpSupportedExtension::set_SupportedOpenModes(TSBSftpFileOpenModes Value)
{
	SBCheckError(TElSftpSupportedExtension_set_SupportedOpenModes(_Handle, (TSBSftpFileOpenModesRaw)Value));
}

TSBSftpFileOpenAccess TElSftpSupportedExtension::get_SupportedAccessModes()
{
	TSBSftpFileOpenAccessRaw OutResultRaw = 0;
	SBCheckError(TElSftpSupportedExtension_get_SupportedAccessModes(_Handle, &OutResultRaw));
	return (TSBSftpFileOpenAccess)OutResultRaw;
}

SB_INLINE void TElSftpSupportedExtension::set_SupportedAccessModes(TSBSftpFileOpenAccess Value)
{
	SBCheckError(TElSftpSupportedExtension_set_SupportedAccessModes(_Handle, (TSBSftpFileOpenAccessRaw)Value));
}

SB_INLINE uint32_t TElSftpSupportedExtension::get_SupportedAccessMask()
{
	uint32_t OutResult;
	SBCheckError(TElSftpSupportedExtension_get_SupportedAccessMask(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpSupportedExtension::set_SupportedAccessMask(uint32_t Value)
{
	SBCheckError(TElSftpSupportedExtension_set_SupportedAccessMask(_Handle, Value));
}

SB_INLINE uint32_t TElSftpSupportedExtension::get_MaxReadSize()
{
	uint32_t OutResult;
	SBCheckError(TElSftpSupportedExtension_get_MaxReadSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpSupportedExtension::set_MaxReadSize(uint32_t Value)
{
	SBCheckError(TElSftpSupportedExtension_set_MaxReadSize(_Handle, Value));
}

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSftpSupportedExtension::get_SupportedAttrExtensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSftpSupportedExtension_get_SupportedAttrExtensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SupportedAttrExtensions)
		this->_Inst_SupportedAttrExtensions = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_SupportedAttrExtensions->updateHandle(hOutResult);
	return this->_Inst_SupportedAttrExtensions;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSftpSupportedExtension::get_SupportedExtensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSftpSupportedExtension_get_SupportedExtensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SupportedExtensions)
		this->_Inst_SupportedExtensions = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_SupportedExtensions->updateHandle(hOutResult);
	return this->_Inst_SupportedExtensions;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

SB_INLINE int32_t TElSftpSupportedExtension::get_Version()
{
	int32_t OutResult;
	SBCheckError(TElSftpSupportedExtension_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpSupportedExtension::set_Version(int32_t Value)
{
	SBCheckError(TElSftpSupportedExtension_set_Version(_Handle, Value));
}

void TElSftpSupportedExtension::initInstances()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_SupportedAttrExtensions = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_SupportedExtensions = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}

TElSftpSupportedExtension::TElSftpSupportedExtension(TElSftpSupportedExtensionHandle handle, TElOwnHandle ownHandle) : TSBSftpExtendedAttribute(handle, ownHandle)
{
	initInstances();
}

TElSftpSupportedExtension::TElSftpSupportedExtension() : TSBSftpExtendedAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSftpSupportedExtension_Create(&_Handle));
}

TElSftpSupportedExtension::~TElSftpSupportedExtension()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_SupportedAttrExtensions;
	this->_Inst_SupportedAttrExtensions = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_SupportedExtensions;
	this->_Inst_SupportedExtensions = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}
#endif /* SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPVENDORIDEXTENSION

SB_INLINE void TElSftpVendorIDExtension::Assign(TPersistent &Source)
{
	SBCheckError(TElSftpVendorIDExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSftpVendorIDExtension::Assign(TPersistent *Source)
{
	SBCheckError(TElSftpVendorIDExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElSftpVendorIDExtension::LoadFromBuffer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpVendorIDExtension_LoadFromBuffer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpVendorIDExtension::SaveToBuffer()
{
	SBCheckError(TElSftpVendorIDExtension_SaveToBuffer(_Handle));
}

void TElSftpVendorIDExtension::get_VendorName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpVendorIDExtension_get_VendorName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1105471774, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpVendorIDExtension::set_VendorName(const std::string &Value)
{
	SBCheckError(TElSftpVendorIDExtension_set_VendorName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSftpVendorIDExtension::get_ProductName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpVendorIDExtension_get_ProductName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(604862097, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpVendorIDExtension::set_ProductName(const std::string &Value)
{
	SBCheckError(TElSftpVendorIDExtension_set_ProductName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSftpVendorIDExtension::get_ProductVersion(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpVendorIDExtension_get_ProductVersion(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1408359655, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpVendorIDExtension::set_ProductVersion(const std::string &Value)
{
	SBCheckError(TElSftpVendorIDExtension_set_ProductVersion(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElSftpVendorIDExtension::get_BuildNumber()
{
	int64_t OutResult;
	SBCheckError(TElSftpVendorIDExtension_get_BuildNumber(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpVendorIDExtension::set_BuildNumber(int64_t Value)
{
	SBCheckError(TElSftpVendorIDExtension_set_BuildNumber(_Handle, Value));
}

TElSftpVendorIDExtension::TElSftpVendorIDExtension(TElSftpVendorIDExtensionHandle handle, TElOwnHandle ownHandle) : TSBSftpExtendedAttribute(handle, ownHandle)
{
}

TElSftpVendorIDExtension::TElSftpVendorIDExtension() : TSBSftpExtendedAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSftpVendorIDExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSFTPVENDORIDEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPCHECKFILEEXTENSION

SB_INLINE void TElSftpCheckFileExtension::Assign(TPersistent &Source)
{
	SBCheckError(TElSftpCheckFileExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSftpCheckFileExtension::Assign(TPersistent *Source)
{
	SBCheckError(TElSftpCheckFileExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElSftpCheckFileExtension::LoadFromBuffer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpCheckFileExtension_LoadFromBuffer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpCheckFileExtension::SaveToBuffer()
{
	SBCheckError(TElSftpCheckFileExtension_SaveToBuffer(_Handle));
}

void TElSftpCheckFileExtension::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpCheckFileExtension_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(841278150, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpCheckFileExtension::set_Name(const std::string &Value)
{
	SBCheckError(TElSftpCheckFileExtension_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSftpCheckFileExtension::get_Handle(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSftpCheckFileExtension_get_Handle(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-501590528, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpCheckFileExtension::set_Handle(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSftpCheckFileExtension_set_Handle(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElSftpCheckFileExtension::get_HashAlgorithms(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpCheckFileExtension_get_HashAlgorithms(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-265315002, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpCheckFileExtension::set_HashAlgorithms(const std::string &Value)
{
	SBCheckError(TElSftpCheckFileExtension_set_HashAlgorithms(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElSftpCheckFileExtension::get_StartOffset()
{
	int64_t OutResult;
	SBCheckError(TElSftpCheckFileExtension_get_StartOffset(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpCheckFileExtension::set_StartOffset(int64_t Value)
{
	SBCheckError(TElSftpCheckFileExtension_set_StartOffset(_Handle, Value));
}

SB_INLINE int64_t TElSftpCheckFileExtension::get_DataLength()
{
	int64_t OutResult;
	SBCheckError(TElSftpCheckFileExtension_get_DataLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpCheckFileExtension::set_DataLength(int64_t Value)
{
	SBCheckError(TElSftpCheckFileExtension_set_DataLength(_Handle, Value));
}

SB_INLINE uint32_t TElSftpCheckFileExtension::get_BlockSize()
{
	uint32_t OutResult;
	SBCheckError(TElSftpCheckFileExtension_get_BlockSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpCheckFileExtension::set_BlockSize(uint32_t Value)
{
	SBCheckError(TElSftpCheckFileExtension_set_BlockSize(_Handle, Value));
}

TElSftpCheckFileExtension::TElSftpCheckFileExtension(TElSftpCheckFileExtensionHandle handle, TElOwnHandle ownHandle) : TSBSftpExtendedAttribute(handle, ownHandle)
{
}

TElSftpCheckFileExtension::TElSftpCheckFileExtension() : TSBSftpExtendedAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSftpCheckFileExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSFTPCHECKFILEEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPSTATVFSEXTENSION

SB_INLINE void TElSftpStatvfsExtension::Assign(TPersistent &Source)
{
	SBCheckError(TElSftpStatvfsExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSftpStatvfsExtension::Assign(TPersistent *Source)
{
	SBCheckError(TElSftpStatvfsExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElSftpStatvfsExtension::LoadFromBuffer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpStatvfsExtension_LoadFromBuffer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpStatvfsExtension::SaveToBuffer()
{
	SBCheckError(TElSftpStatvfsExtension_SaveToBuffer(_Handle));
}

void TElSftpStatvfsExtension::get_Path(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpStatvfsExtension_get_Path(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2031745659, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpStatvfsExtension::set_Path(const std::string &Value)
{
	SBCheckError(TElSftpStatvfsExtension_set_Path(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSftpStatvfsExtension::TElSftpStatvfsExtension(TElSftpStatvfsExtensionHandle handle, TElOwnHandle ownHandle) : TSBSftpExtendedAttribute(handle, ownHandle)
{
}

TElSftpStatvfsExtension::TElSftpStatvfsExtension() : TSBSftpExtendedAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSftpStatvfsExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSFTPSTATVFSEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPSPACEAVAILABLEEXTENSION

SB_INLINE void TElSftpSpaceAvailableExtension::Assign(TPersistent &Source)
{
	SBCheckError(TElSftpSpaceAvailableExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSftpSpaceAvailableExtension::Assign(TPersistent *Source)
{
	SBCheckError(TElSftpSpaceAvailableExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElSftpSpaceAvailableExtension::LoadFromBuffer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpSpaceAvailableExtension_LoadFromBuffer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpSpaceAvailableExtension::SaveToBuffer()
{
	SBCheckError(TElSftpSpaceAvailableExtension_SaveToBuffer(_Handle));
}

void TElSftpSpaceAvailableExtension::get_Path(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpSpaceAvailableExtension_get_Path(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(476077082, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpSpaceAvailableExtension::set_Path(const std::string &Value)
{
	SBCheckError(TElSftpSpaceAvailableExtension_set_Path(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSftpSpaceAvailableExtension::TElSftpSpaceAvailableExtension(TElSftpSpaceAvailableExtensionHandle handle, TElOwnHandle ownHandle) : TSBSftpExtendedAttribute(handle, ownHandle)
{
}

TElSftpSpaceAvailableExtension::TElSftpSpaceAvailableExtension() : TSBSftpExtendedAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSftpSpaceAvailableExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSFTPSPACEAVAILABLEEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPHOMEDIRECTORYEXTENSION

SB_INLINE void TElSftpHomeDirectoryExtension::Assign(TPersistent &Source)
{
	SBCheckError(TElSftpHomeDirectoryExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSftpHomeDirectoryExtension::Assign(TPersistent *Source)
{
	SBCheckError(TElSftpHomeDirectoryExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElSftpHomeDirectoryExtension::LoadFromBuffer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpHomeDirectoryExtension_LoadFromBuffer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpHomeDirectoryExtension::SaveToBuffer()
{
	SBCheckError(TElSftpHomeDirectoryExtension_SaveToBuffer(_Handle));
}

void TElSftpHomeDirectoryExtension::get_Username(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpHomeDirectoryExtension_get_Username(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1730193940, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpHomeDirectoryExtension::set_Username(const std::string &Value)
{
	SBCheckError(TElSftpHomeDirectoryExtension_set_Username(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSftpHomeDirectoryExtension::TElSftpHomeDirectoryExtension(TElSftpHomeDirectoryExtensionHandle handle, TElOwnHandle ownHandle) : TSBSftpExtendedAttribute(handle, ownHandle)
{
}

TElSftpHomeDirectoryExtension::TElSftpHomeDirectoryExtension() : TSBSftpExtendedAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSftpHomeDirectoryExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSFTPHOMEDIRECTORYEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPCOPYFILEEXTENSION

SB_INLINE void TElSftpCopyFileExtension::Assign(TPersistent &Source)
{
	SBCheckError(TElSftpCopyFileExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSftpCopyFileExtension::Assign(TPersistent *Source)
{
	SBCheckError(TElSftpCopyFileExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElSftpCopyFileExtension::LoadFromBuffer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpCopyFileExtension_LoadFromBuffer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpCopyFileExtension::SaveToBuffer()
{
	SBCheckError(TElSftpCopyFileExtension_SaveToBuffer(_Handle));
}

void TElSftpCopyFileExtension::get_Source(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpCopyFileExtension_get_Source(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1422584766, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpCopyFileExtension::set_Source(const std::string &Value)
{
	SBCheckError(TElSftpCopyFileExtension_set_Source(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSftpCopyFileExtension::get_Destination(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpCopyFileExtension_get_Destination(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1210959653, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpCopyFileExtension::set_Destination(const std::string &Value)
{
	SBCheckError(TElSftpCopyFileExtension_set_Destination(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSftpCopyFileExtension::get_Overwrite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpCopyFileExtension_get_Overwrite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpCopyFileExtension::set_Overwrite(bool Value)
{
	SBCheckError(TElSftpCopyFileExtension_set_Overwrite(_Handle, (int8_t)Value));
}

TElSftpCopyFileExtension::TElSftpCopyFileExtension(TElSftpCopyFileExtensionHandle handle, TElOwnHandle ownHandle) : TSBSftpExtendedAttribute(handle, ownHandle)
{
}

TElSftpCopyFileExtension::TElSftpCopyFileExtension() : TSBSftpExtendedAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSftpCopyFileExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSFTPCOPYFILEEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPCOPYDATAEXTENSION

SB_INLINE void TElSftpCopyDataExtension::Assign(TPersistent &Source)
{
	SBCheckError(TElSftpCopyDataExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSftpCopyDataExtension::Assign(TPersistent *Source)
{
	SBCheckError(TElSftpCopyDataExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

bool TElSftpCopyDataExtension::LoadFromBuffer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpCopyDataExtension_LoadFromBuffer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpCopyDataExtension::SaveToBuffer()
{
	SBCheckError(TElSftpCopyDataExtension_SaveToBuffer(_Handle));
}

void TElSftpCopyDataExtension::get_ReadHandle(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSftpCopyDataExtension_get_ReadHandle(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1100363186, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpCopyDataExtension::set_ReadHandle(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSftpCopyDataExtension_set_ReadHandle(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int64_t TElSftpCopyDataExtension::get_ReadOffset()
{
	int64_t OutResult;
	SBCheckError(TElSftpCopyDataExtension_get_ReadOffset(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpCopyDataExtension::set_ReadOffset(int64_t Value)
{
	SBCheckError(TElSftpCopyDataExtension_set_ReadOffset(_Handle, Value));
}

void TElSftpCopyDataExtension::get_WriteHandle(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSftpCopyDataExtension_get_WriteHandle(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1672586380, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpCopyDataExtension::set_WriteHandle(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSftpCopyDataExtension_set_WriteHandle(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int64_t TElSftpCopyDataExtension::get_WriteOffset()
{
	int64_t OutResult;
	SBCheckError(TElSftpCopyDataExtension_get_WriteOffset(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpCopyDataExtension::set_WriteOffset(int64_t Value)
{
	SBCheckError(TElSftpCopyDataExtension_set_WriteOffset(_Handle, Value));
}

SB_INLINE int64_t TElSftpCopyDataExtension::get_DataLength()
{
	int64_t OutResult;
	SBCheckError(TElSftpCopyDataExtension_get_DataLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpCopyDataExtension::set_DataLength(int64_t Value)
{
	SBCheckError(TElSftpCopyDataExtension_set_DataLength(_Handle, Value));
}

TElSftpCopyDataExtension::TElSftpCopyDataExtension(TElSftpCopyDataExtensionHandle handle, TElOwnHandle ownHandle) : TSBSftpExtendedAttribute(handle, ownHandle)
{
}

TElSftpCopyDataExtension::TElSftpCopyDataExtension() : TSBSftpExtendedAttribute(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSftpCopyDataExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSFTPCOPYDATAEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPCHECKFILEREPLY

SB_INLINE void TElSftpCheckFileReply::Assign(TPersistent &Source)
{
	SBCheckError(TElSftpCheckFileReply_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSftpCheckFileReply::Assign(TPersistent *Source)
{
	SBCheckError(TElSftpCheckFileReply_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElSftpCheckFileReply::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElSftpCheckFileReply_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElSftpCheckFileReply::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElSftpCheckFileReply_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

bool TElSftpCheckFileReply::LoadFromBuffer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpCheckFileReply_LoadFromBuffer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpCheckFileReply::SaveToBuffer()
{
	SBCheckError(TElSftpCheckFileReply_SaveToBuffer(_Handle));
}

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
TElByteArrayList* TElSftpCheckFileReply::get_Hashes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSftpCheckFileReply_get_Hashes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Hashes)
		this->_Inst_Hashes = new TElByteArrayList(hOutResult, ohFalse);
	else
		this->_Inst_Hashes->updateHandle(hOutResult);
	return this->_Inst_Hashes;
}
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

SB_INLINE int32_t TElSftpCheckFileReply::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElSftpCheckFileReply_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpCheckFileReply::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElSftpCheckFileReply_set_HashAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElSftpCheckFileReply::get_HashSize()
{
	int32_t OutResult;
	SBCheckError(TElSftpCheckFileReply_get_HashSize(_Handle, &OutResult));
	return OutResult;
}

void TElSftpCheckFileReply::initInstances()
{
#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
	this->_Inst_Hashes = NULL;
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */
}

TElSftpCheckFileReply::TElSftpCheckFileReply(TElSftpCheckFileReplyHandle handle, TElOwnHandle ownHandle) : TElSftpExtendedReply(handle, ownHandle)
{
	initInstances();
}

TElSftpCheckFileReply::TElSftpCheckFileReply() : TElSftpExtendedReply(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSftpCheckFileReply_Create(&_Handle));
}

TElSftpCheckFileReply::~TElSftpCheckFileReply()
{
#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
	delete this->_Inst_Hashes;
	this->_Inst_Hashes = NULL;
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */
}
#endif /* SB_USE_CLASS_TELSFTPCHECKFILEREPLY */

#ifdef SB_USE_CLASS_TELSFTPSPACEAVAILABLEREPLY

SB_INLINE void TElSftpSpaceAvailableReply::Assign(TPersistent &Source)
{
	SBCheckError(TElSftpSpaceAvailableReply_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSftpSpaceAvailableReply::Assign(TPersistent *Source)
{
	SBCheckError(TElSftpSpaceAvailableReply_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElSftpSpaceAvailableReply::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElSftpSpaceAvailableReply_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElSftpSpaceAvailableReply::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElSftpSpaceAvailableReply_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

bool TElSftpSpaceAvailableReply::LoadFromBuffer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpSpaceAvailableReply_LoadFromBuffer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpSpaceAvailableReply::SaveToBuffer()
{
	SBCheckError(TElSftpSpaceAvailableReply_SaveToBuffer(_Handle));
}

SB_INLINE int64_t TElSftpSpaceAvailableReply::get_BytesOnDevice()
{
	int64_t OutResult;
	SBCheckError(TElSftpSpaceAvailableReply_get_BytesOnDevice(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpSpaceAvailableReply::set_BytesOnDevice(int64_t Value)
{
	SBCheckError(TElSftpSpaceAvailableReply_set_BytesOnDevice(_Handle, Value));
}

SB_INLINE int64_t TElSftpSpaceAvailableReply::get_UnusedBytesOnDevice()
{
	int64_t OutResult;
	SBCheckError(TElSftpSpaceAvailableReply_get_UnusedBytesOnDevice(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpSpaceAvailableReply::set_UnusedBytesOnDevice(int64_t Value)
{
	SBCheckError(TElSftpSpaceAvailableReply_set_UnusedBytesOnDevice(_Handle, Value));
}

SB_INLINE int64_t TElSftpSpaceAvailableReply::get_BytesAvailableToUser()
{
	int64_t OutResult;
	SBCheckError(TElSftpSpaceAvailableReply_get_BytesAvailableToUser(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpSpaceAvailableReply::set_BytesAvailableToUser(int64_t Value)
{
	SBCheckError(TElSftpSpaceAvailableReply_set_BytesAvailableToUser(_Handle, Value));
}

SB_INLINE int64_t TElSftpSpaceAvailableReply::get_UnusedBytesAvailableToUser()
{
	int64_t OutResult;
	SBCheckError(TElSftpSpaceAvailableReply_get_UnusedBytesAvailableToUser(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpSpaceAvailableReply::set_UnusedBytesAvailableToUser(int64_t Value)
{
	SBCheckError(TElSftpSpaceAvailableReply_set_UnusedBytesAvailableToUser(_Handle, Value));
}

SB_INLINE uint32_t TElSftpSpaceAvailableReply::get_BytesPerAllocationUnit()
{
	uint32_t OutResult;
	SBCheckError(TElSftpSpaceAvailableReply_get_BytesPerAllocationUnit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpSpaceAvailableReply::set_BytesPerAllocationUnit(uint32_t Value)
{
	SBCheckError(TElSftpSpaceAvailableReply_set_BytesPerAllocationUnit(_Handle, Value));
}

TElSftpSpaceAvailableReply::TElSftpSpaceAvailableReply(TElSftpSpaceAvailableReplyHandle handle, TElOwnHandle ownHandle) : TElSftpExtendedReply(handle, ownHandle)
{
}

TElSftpSpaceAvailableReply::TElSftpSpaceAvailableReply() : TElSftpExtendedReply(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSftpSpaceAvailableReply_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSFTPSPACEAVAILABLEREPLY */

#ifdef SB_USE_CLASS_TELSFTPSTATVFSREPLY

SB_INLINE void TElSftpStatVFSReply::Assign(TPersistent &Source)
{
	SBCheckError(TElSftpStatVFSReply_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSftpStatVFSReply::Assign(TPersistent *Source)
{
	SBCheckError(TElSftpStatVFSReply_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElSftpStatVFSReply::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElSftpStatVFSReply_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElSftpStatVFSReply::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElSftpStatVFSReply_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

bool TElSftpStatVFSReply::LoadFromBuffer()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpStatVFSReply_LoadFromBuffer(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpStatVFSReply::SaveToBuffer()
{
	SBCheckError(TElSftpStatVFSReply_SaveToBuffer(_Handle));
}

SB_INLINE int64_t TElSftpStatVFSReply::get_BSize()
{
	int64_t OutResult;
	SBCheckError(TElSftpStatVFSReply_get_BSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpStatVFSReply::set_BSize(int64_t Value)
{
	SBCheckError(TElSftpStatVFSReply_set_BSize(_Handle, Value));
}

SB_INLINE int64_t TElSftpStatVFSReply::get_FRSize()
{
	int64_t OutResult;
	SBCheckError(TElSftpStatVFSReply_get_FRSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpStatVFSReply::set_FRSize(int64_t Value)
{
	SBCheckError(TElSftpStatVFSReply_set_FRSize(_Handle, Value));
}

SB_INLINE int64_t TElSftpStatVFSReply::get_Blocks()
{
	int64_t OutResult;
	SBCheckError(TElSftpStatVFSReply_get_Blocks(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpStatVFSReply::set_Blocks(int64_t Value)
{
	SBCheckError(TElSftpStatVFSReply_set_Blocks(_Handle, Value));
}

SB_INLINE int64_t TElSftpStatVFSReply::get_BFree()
{
	int64_t OutResult;
	SBCheckError(TElSftpStatVFSReply_get_BFree(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpStatVFSReply::set_BFree(int64_t Value)
{
	SBCheckError(TElSftpStatVFSReply_set_BFree(_Handle, Value));
}

SB_INLINE int64_t TElSftpStatVFSReply::get_BAvail()
{
	int64_t OutResult;
	SBCheckError(TElSftpStatVFSReply_get_BAvail(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpStatVFSReply::set_BAvail(int64_t Value)
{
	SBCheckError(TElSftpStatVFSReply_set_BAvail(_Handle, Value));
}

SB_INLINE int64_t TElSftpStatVFSReply::get_Files()
{
	int64_t OutResult;
	SBCheckError(TElSftpStatVFSReply_get_Files(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpStatVFSReply::set_Files(int64_t Value)
{
	SBCheckError(TElSftpStatVFSReply_set_Files(_Handle, Value));
}

SB_INLINE int64_t TElSftpStatVFSReply::get_FFree()
{
	int64_t OutResult;
	SBCheckError(TElSftpStatVFSReply_get_FFree(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpStatVFSReply::set_FFree(int64_t Value)
{
	SBCheckError(TElSftpStatVFSReply_set_FFree(_Handle, Value));
}

SB_INLINE int64_t TElSftpStatVFSReply::get_FAvail()
{
	int64_t OutResult;
	SBCheckError(TElSftpStatVFSReply_get_FAvail(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpStatVFSReply::set_FAvail(int64_t Value)
{
	SBCheckError(TElSftpStatVFSReply_set_FAvail(_Handle, Value));
}

SB_INLINE int64_t TElSftpStatVFSReply::get_FSid()
{
	int64_t OutResult;
	SBCheckError(TElSftpStatVFSReply_get_FSid(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpStatVFSReply::set_FSid(int64_t Value)
{
	SBCheckError(TElSftpStatVFSReply_set_FSid(_Handle, Value));
}

SB_INLINE int64_t TElSftpStatVFSReply::get_Flag()
{
	int64_t OutResult;
	SBCheckError(TElSftpStatVFSReply_get_Flag(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpStatVFSReply::set_Flag(int64_t Value)
{
	SBCheckError(TElSftpStatVFSReply_set_Flag(_Handle, Value));
}

SB_INLINE int64_t TElSftpStatVFSReply::get_Namemax()
{
	int64_t OutResult;
	SBCheckError(TElSftpStatVFSReply_get_Namemax(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpStatVFSReply::set_Namemax(int64_t Value)
{
	SBCheckError(TElSftpStatVFSReply_set_Namemax(_Handle, Value));
}

TElSftpStatVFSReply::TElSftpStatVFSReply(TElSftpStatVFSReplyHandle handle, TElOwnHandle ownHandle) : TElSftpExtendedReply(handle, ownHandle)
{
}

TElSftpStatVFSReply::TElSftpStatVFSReply() : TElSftpExtendedReply(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSftpStatVFSReply_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSFTPSTATVFSREPLY */

#ifdef SB_USE_CLASS_TSBSFTPACE

SB_INLINE int32_t TSBSftpACE::get_ACEType()
{
	int32_t OutResult;
	SBCheckError(TSBSftpACE_get_ACEType(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TSBSftpACE::set_ACEType(int32_t Value)
{
	SBCheckError(TSBSftpACE_set_ACEType(_Handle, Value));
}

SB_INLINE int32_t TSBSftpACE::get_ACEFlags()
{
	int32_t OutResult;
	SBCheckError(TSBSftpACE_get_ACEFlags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TSBSftpACE::set_ACEFlags(int32_t Value)
{
	SBCheckError(TSBSftpACE_set_ACEFlags(_Handle, Value));
}

SB_INLINE int32_t TSBSftpACE::get_ACEMask()
{
	int32_t OutResult;
	SBCheckError(TSBSftpACE_get_ACEMask(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TSBSftpACE::set_ACEMask(int32_t Value)
{
	SBCheckError(TSBSftpACE_set_ACEMask(_Handle, Value));
}

void TSBSftpACE::get_Who(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TSBSftpACE_get_Who(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2070958753, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TSBSftpACE::set_Who(const std::vector<uint8_t> &Value)
{
	SBCheckError(TSBSftpACE_set_Who(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TSBSftpACE::TSBSftpACE(TSBSftpACEHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TSBSftpACE::TSBSftpACE() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBSftpACE_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TSBSFTPACE */

#ifdef SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES

SB_INLINE void TElSftpExtendedProperties::Assign(TPersistent &Source)
{
	SBCheckError(TElSftpExtendedProperties_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSftpExtendedProperties::Assign(TPersistent *Source)
{
	SBCheckError(TElSftpExtendedProperties_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElSftpExtendedProperties::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElSftpExtendedProperties_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElSftpExtendedProperties::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElSftpExtendedProperties_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE uint32_t TElSftpExtendedProperties::RequestAttributesByVersion(int32_t Version)
{
	uint32_t OutResult;
	SBCheckError(TElSftpExtendedProperties_RequestAttributesByVersion(_Handle, Version, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElSftpExtendedProperties::get_DesiredAccess()
{
	uint32_t OutResult;
	SBCheckError(TElSftpExtendedProperties_get_DesiredAccess(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpExtendedProperties::set_DesiredAccess(uint32_t Value)
{
	SBCheckError(TElSftpExtendedProperties_set_DesiredAccess(_Handle, Value));
}

bool TElSftpExtendedProperties::get_AutoAdjustDesiredAccess()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpExtendedProperties_get_AutoAdjustDesiredAccess(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpExtendedProperties::set_AutoAdjustDesiredAccess(bool Value)
{
	SBCheckError(TElSftpExtendedProperties_set_AutoAdjustDesiredAccess(_Handle, (int8_t)Value));
}

TSBSftpRenameFlags TElSftpExtendedProperties::get_RenameFlags()
{
	TSBSftpRenameFlagsRaw OutResultRaw = 0;
	SBCheckError(TElSftpExtendedProperties_get_RenameFlags(_Handle, &OutResultRaw));
	return (TSBSftpRenameFlags)OutResultRaw;
}

SB_INLINE void TElSftpExtendedProperties::set_RenameFlags(TSBSftpRenameFlags Value)
{
	SBCheckError(TElSftpExtendedProperties_set_RenameFlags(_Handle, (TSBSftpRenameFlagsRaw)Value));
}

SB_INLINE uint32_t TElSftpExtendedProperties::get_RenameFlagsUInt32()
{
	uint32_t OutResult;
	SBCheckError(TElSftpExtendedProperties_get_RenameFlagsUInt32(_Handle, &OutResult));
	return OutResult;
}

TSBSftpAttributes TElSftpExtendedProperties::get_RequestAttributes()
{
	TSBSftpAttributesRaw OutResultRaw = 0;
	SBCheckError(TElSftpExtendedProperties_get_RequestAttributes(_Handle, &OutResultRaw));
	return (TSBSftpAttributes)OutResultRaw;
}

SB_INLINE void TElSftpExtendedProperties::set_RequestAttributes(TSBSftpAttributes Value)
{
	SBCheckError(TElSftpExtendedProperties_set_RequestAttributes(_Handle, (TSBSftpAttributesRaw)Value));
}

SB_INLINE uint32_t TElSftpExtendedProperties::get_RequestAttributesUInt32()
{
	uint32_t OutResult;
	SBCheckError(TElSftpExtendedProperties_get_RequestAttributesUInt32(_Handle, &OutResult));
	return OutResult;
}

bool TElSftpExtendedProperties::get_AutoAdjustRequestAttributes()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpExtendedProperties_get_AutoAdjustRequestAttributes(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpExtendedProperties::set_AutoAdjustRequestAttributes(bool Value)
{
	SBCheckError(TElSftpExtendedProperties_set_AutoAdjustRequestAttributes(_Handle, (int8_t)Value));
}

bool TElSftpExtendedProperties::get_SupportedAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpExtendedProperties_get_SupportedAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpExtendedProperties::set_SupportedAvailable(bool Value)
{
	SBCheckError(TElSftpExtendedProperties_set_SupportedAvailable(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION
TElSftpSupportedExtension* TElSftpExtendedProperties::get_SupportedExtension()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSftpExtendedProperties_get_SupportedExtension(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SupportedExtension)
		this->_Inst_SupportedExtension = new TElSftpSupportedExtension(hOutResult, ohFalse);
	else
		this->_Inst_SupportedExtension->updateHandle(hOutResult);
	return this->_Inst_SupportedExtension;
}

SB_INLINE void TElSftpExtendedProperties::set_SupportedExtension(TElSftpSupportedExtension &Value)
{
	SBCheckError(TElSftpExtendedProperties_set_SupportedExtension(_Handle, Value.getHandle()));
}

SB_INLINE void TElSftpExtendedProperties::set_SupportedExtension(TElSftpSupportedExtension *Value)
{
	SBCheckError(TElSftpExtendedProperties_set_SupportedExtension(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION */

bool TElSftpExtendedProperties::get_NewlineAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpExtendedProperties_get_NewlineAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpExtendedProperties::set_NewlineAvailable(bool Value)
{
	SBCheckError(TElSftpExtendedProperties_set_NewlineAvailable(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELSFTPNEWLINEEXTENSION
TElSftpNewlineExtension* TElSftpExtendedProperties::get_NewlineExtension()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSftpExtendedProperties_get_NewlineExtension(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NewlineExtension)
		this->_Inst_NewlineExtension = new TElSftpNewlineExtension(hOutResult, ohFalse);
	else
		this->_Inst_NewlineExtension->updateHandle(hOutResult);
	return this->_Inst_NewlineExtension;
}

SB_INLINE void TElSftpExtendedProperties::set_NewlineExtension(TElSftpNewlineExtension &Value)
{
	SBCheckError(TElSftpExtendedProperties_set_NewlineExtension(_Handle, Value.getHandle()));
}

SB_INLINE void TElSftpExtendedProperties::set_NewlineExtension(TElSftpNewlineExtension *Value)
{
	SBCheckError(TElSftpExtendedProperties_set_NewlineExtension(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPNEWLINEEXTENSION */

bool TElSftpExtendedProperties::get_VersionsAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpExtendedProperties_get_VersionsAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpExtendedProperties::set_VersionsAvailable(bool Value)
{
	SBCheckError(TElSftpExtendedProperties_set_VersionsAvailable(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELSFTPVERSIONSEXTENSION
TElSftpVersionsExtension* TElSftpExtendedProperties::get_VersionsExtension()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSftpExtendedProperties_get_VersionsExtension(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_VersionsExtension)
		this->_Inst_VersionsExtension = new TElSftpVersionsExtension(hOutResult, ohFalse);
	else
		this->_Inst_VersionsExtension->updateHandle(hOutResult);
	return this->_Inst_VersionsExtension;
}

SB_INLINE void TElSftpExtendedProperties::set_VersionsExtension(TElSftpVersionsExtension &Value)
{
	SBCheckError(TElSftpExtendedProperties_set_VersionsExtension(_Handle, Value.getHandle()));
}

SB_INLINE void TElSftpExtendedProperties::set_VersionsExtension(TElSftpVersionsExtension *Value)
{
	SBCheckError(TElSftpExtendedProperties_set_VersionsExtension(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPVERSIONSEXTENSION */

bool TElSftpExtendedProperties::get_VendorIDAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpExtendedProperties_get_VendorIDAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpExtendedProperties::set_VendorIDAvailable(bool Value)
{
	SBCheckError(TElSftpExtendedProperties_set_VendorIDAvailable(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELSFTPVENDORIDEXTENSION
TElSftpVendorIDExtension* TElSftpExtendedProperties::get_VendorIDExtension()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSftpExtendedProperties_get_VendorIDExtension(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_VendorIDExtension)
		this->_Inst_VendorIDExtension = new TElSftpVendorIDExtension(hOutResult, ohFalse);
	else
		this->_Inst_VendorIDExtension->updateHandle(hOutResult);
	return this->_Inst_VendorIDExtension;
}

SB_INLINE void TElSftpExtendedProperties::set_VendorIDExtension(TElSftpVendorIDExtension &Value)
{
	SBCheckError(TElSftpExtendedProperties_set_VendorIDExtension(_Handle, Value.getHandle()));
}

SB_INLINE void TElSftpExtendedProperties::set_VendorIDExtension(TElSftpVendorIDExtension *Value)
{
	SBCheckError(TElSftpExtendedProperties_set_VendorIDExtension(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSFTPVENDORIDEXTENSION */

void TElSftpExtendedProperties::get_FilenameCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpExtendedProperties_get_FilenameCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-94500820, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpExtendedProperties::set_FilenameCharset(const std::string &Value)
{
	SBCheckError(TElSftpExtendedProperties_set_FilenameCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSftpExtendedProperties::initInstances()
{
#ifdef SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION
	this->_Inst_SupportedExtension = NULL;
#endif /* SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION */
#ifdef SB_USE_CLASS_TELSFTPNEWLINEEXTENSION
	this->_Inst_NewlineExtension = NULL;
#endif /* SB_USE_CLASS_TELSFTPNEWLINEEXTENSION */
#ifdef SB_USE_CLASS_TELSFTPVERSIONSEXTENSION
	this->_Inst_VersionsExtension = NULL;
#endif /* SB_USE_CLASS_TELSFTPVERSIONSEXTENSION */
#ifdef SB_USE_CLASS_TELSFTPVENDORIDEXTENSION
	this->_Inst_VendorIDExtension = NULL;
#endif /* SB_USE_CLASS_TELSFTPVENDORIDEXTENSION */
}

TElSftpExtendedProperties::TElSftpExtendedProperties(TElSftpExtendedPropertiesHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElSftpExtendedProperties::TElSftpExtendedProperties() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSftpExtendedProperties_Create(&_Handle));
}

TElSftpExtendedProperties::~TElSftpExtendedProperties()
{
#ifdef SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION
	delete this->_Inst_SupportedExtension;
	this->_Inst_SupportedExtension = NULL;
#endif /* SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION */
#ifdef SB_USE_CLASS_TELSFTPNEWLINEEXTENSION
	delete this->_Inst_NewlineExtension;
	this->_Inst_NewlineExtension = NULL;
#endif /* SB_USE_CLASS_TELSFTPNEWLINEEXTENSION */
#ifdef SB_USE_CLASS_TELSFTPVERSIONSEXTENSION
	delete this->_Inst_VersionsExtension;
	this->_Inst_VersionsExtension = NULL;
#endif /* SB_USE_CLASS_TELSFTPVERSIONSEXTENSION */
#ifdef SB_USE_CLASS_TELSFTPVENDORIDEXTENSION
	delete this->_Inst_VendorIDExtension;
	this->_Inst_VendorIDExtension = NULL;
#endif /* SB_USE_CLASS_TELSFTPVENDORIDEXTENSION */
}
#endif /* SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES

SB_INLINE void TElSftpFileAttributes::CopyTo(TElSftpFileAttributes &dst)
{
	SBCheckError(TElSftpFileAttributes_CopyTo(_Handle, dst.getHandle()));
}

SB_INLINE void TElSftpFileAttributes::CopyTo(TElSftpFileAttributes *dst)
{
	SBCheckError(TElSftpFileAttributes_CopyTo(_Handle, (dst != NULL) ? dst->getHandle() : SB_NULL_HANDLE));
}

void TElSftpFileAttributes::SaveToBuffer(int32_t Ver, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSftpFileAttributes_SaveToBuffer(_Handle, Ver, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-913241863, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElSftpFileAttributes::LoadFromBuffer(void * Buffer, int32_t Size, int32_t Ver)
{
	int32_t OutResult;
	SBCheckError(TElSftpFileAttributes_LoadFromBuffer(_Handle, Buffer, Size, Ver, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSftpFileAttributes::AddACE()
{
	int32_t OutResult;
	SBCheckError(TElSftpFileAttributes_AddACE(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::RemoveACE(int32_t Index)
{
	SBCheckError(TElSftpFileAttributes_RemoveACE(_Handle, Index));
}

SB_INLINE void TElSftpFileAttributes::ClearACEs()
{
	SBCheckError(TElSftpFileAttributes_ClearACEs(_Handle));
}

SB_INLINE int32_t TElSftpFileAttributes::AddExtendedAttribute()
{
	int32_t OutResult;
	SBCheckError(TElSftpFileAttributes_AddExtendedAttribute(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::RemoveExtendedAttribute(int32_t Index)
{
	SBCheckError(TElSftpFileAttributes_RemoveExtendedAttribute(_Handle, Index));
}

SB_INLINE void TElSftpFileAttributes::ClearExtendedAttributes()
{
	SBCheckError(TElSftpFileAttributes_ClearExtendedAttributes(_Handle));
}

bool TElSftpFileAttributes::IsAttributeIncluded(TSBSftpAttribute Attribute)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpFileAttributes_IsAttributeIncluded(_Handle, (TSBSftpAttributeRaw)Attribute, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t TElSftpFileAttributes::get_Size()
{
	int64_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_Size(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_Size(int64_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_Size(_Handle, Value));
}

SB_INLINE int64_t TElSftpFileAttributes::get_AllocationSize()
{
	int64_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_AllocationSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_AllocationSize(int64_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_AllocationSize(_Handle, Value));
}

SB_INLINE int32_t TElSftpFileAttributes::get_UID()
{
	int32_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_UID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_UID(int32_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_UID(_Handle, Value));
}

SB_INLINE int32_t TElSftpFileAttributes::get_GID()
{
	int32_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_GID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_GID(int32_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_GID(_Handle, Value));
}

void TElSftpFileAttributes::get_Owner(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSftpFileAttributes_get_Owner(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1182897418, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpFileAttributes::set_Owner(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSftpFileAttributes_set_Owner(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElSftpFileAttributes::get_Group(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSftpFileAttributes_get_Group(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(467585103, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpFileAttributes::set_Group(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSftpFileAttributes_set_Group(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int64_t TElSftpFileAttributes::get_CTime()
{
	int64_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_CTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_CTime(int64_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_CTime(_Handle, Value));
}

SB_INLINE int64_t TElSftpFileAttributes::get_CATime()
{
	int64_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_CATime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_CATime(int64_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_CATime(_Handle, Value));
}

TSBSftpFileType TElSftpFileAttributes::get_FileType()
{
	TSBSftpFileTypeRaw OutResultRaw = 0;
	SBCheckError(TElSftpFileAttributes_get_FileType(_Handle, &OutResultRaw));
	return (TSBSftpFileType)OutResultRaw;
}

SB_INLINE void TElSftpFileAttributes::set_FileType(TSBSftpFileType Value)
{
	SBCheckError(TElSftpFileAttributes_set_FileType(_Handle, (TSBSftpFileTypeRaw)Value));
}

SB_INLINE int64_t TElSftpFileAttributes::get_ATime()
{
	int64_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_ATime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_ATime(int64_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_ATime(_Handle, Value));
}

SB_INLINE int64_t TElSftpFileAttributes::get_MTime()
{
	int64_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_MTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_MTime(int64_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_MTime(_Handle, Value));
}

SB_INLINE int32_t TElSftpFileAttributes::get_ExtendedAttributeCount()
{
	int32_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_ExtendedAttributeCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE
TSBSftpExtendedAttribute* TElSftpFileAttributes::get_ExtendedAttributes(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSftpFileAttributes_get_ExtendedAttributes(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ExtendedAttributes)
		this->_Inst_ExtendedAttributes = new TSBSftpExtendedAttribute(hOutResult, ohFalse);
	else
		this->_Inst_ExtendedAttributes->updateHandle(hOutResult);
	return this->_Inst_ExtendedAttributes;
}
#endif /* SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE */

TSBSftpAttributes TElSftpFileAttributes::get_IncludedAttributes()
{
	TSBSftpAttributesRaw OutResultRaw = 0;
	SBCheckError(TElSftpFileAttributes_get_IncludedAttributes(_Handle, &OutResultRaw));
	return (TSBSftpAttributes)OutResultRaw;
}

SB_INLINE void TElSftpFileAttributes::set_IncludedAttributes(TSBSftpAttributes Value)
{
	SBCheckError(TElSftpFileAttributes_set_IncludedAttributes(_Handle, (TSBSftpAttributesRaw)Value));
}

bool TElSftpFileAttributes::get_UserRead()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpFileAttributes_get_UserRead(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpFileAttributes::set_UserRead(bool Value)
{
	SBCheckError(TElSftpFileAttributes_set_UserRead(_Handle, (int8_t)Value));
}

bool TElSftpFileAttributes::get_UserWrite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpFileAttributes_get_UserWrite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpFileAttributes::set_UserWrite(bool Value)
{
	SBCheckError(TElSftpFileAttributes_set_UserWrite(_Handle, (int8_t)Value));
}

bool TElSftpFileAttributes::get_UserExecute()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpFileAttributes_get_UserExecute(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpFileAttributes::set_UserExecute(bool Value)
{
	SBCheckError(TElSftpFileAttributes_set_UserExecute(_Handle, (int8_t)Value));
}

bool TElSftpFileAttributes::get_GroupRead()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpFileAttributes_get_GroupRead(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpFileAttributes::set_GroupRead(bool Value)
{
	SBCheckError(TElSftpFileAttributes_set_GroupRead(_Handle, (int8_t)Value));
}

bool TElSftpFileAttributes::get_GroupWrite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpFileAttributes_get_GroupWrite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpFileAttributes::set_GroupWrite(bool Value)
{
	SBCheckError(TElSftpFileAttributes_set_GroupWrite(_Handle, (int8_t)Value));
}

bool TElSftpFileAttributes::get_GroupExecute()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpFileAttributes_get_GroupExecute(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpFileAttributes::set_GroupExecute(bool Value)
{
	SBCheckError(TElSftpFileAttributes_set_GroupExecute(_Handle, (int8_t)Value));
}

bool TElSftpFileAttributes::get_OtherRead()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpFileAttributes_get_OtherRead(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpFileAttributes::set_OtherRead(bool Value)
{
	SBCheckError(TElSftpFileAttributes_set_OtherRead(_Handle, (int8_t)Value));
}

bool TElSftpFileAttributes::get_OtherWrite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpFileAttributes_get_OtherWrite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpFileAttributes::set_OtherWrite(bool Value)
{
	SBCheckError(TElSftpFileAttributes_set_OtherWrite(_Handle, (int8_t)Value));
}

bool TElSftpFileAttributes::get_OtherExecute()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpFileAttributes_get_OtherExecute(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpFileAttributes::set_OtherExecute(bool Value)
{
	SBCheckError(TElSftpFileAttributes_set_OtherExecute(_Handle, (int8_t)Value));
}

bool TElSftpFileAttributes::get_UIDBit()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpFileAttributes_get_UIDBit(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpFileAttributes::set_UIDBit(bool Value)
{
	SBCheckError(TElSftpFileAttributes_set_UIDBit(_Handle, (int8_t)Value));
}

bool TElSftpFileAttributes::get_GIDBit()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpFileAttributes_get_GIDBit(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpFileAttributes::set_GIDBit(bool Value)
{
	SBCheckError(TElSftpFileAttributes_set_GIDBit(_Handle, (int8_t)Value));
}

bool TElSftpFileAttributes::get_StickyBit()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpFileAttributes_get_StickyBit(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpFileAttributes::set_StickyBit(bool Value)
{
	SBCheckError(TElSftpFileAttributes_set_StickyBit(_Handle, (int8_t)Value));
}

bool TElSftpFileAttributes::get_Directory()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpFileAttributes_get_Directory(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpFileAttributes::set_Directory(bool Value)
{
	SBCheckError(TElSftpFileAttributes_set_Directory(_Handle, (int8_t)Value));
}

SB_INLINE uint32_t TElSftpFileAttributes::get_ACLFlags()
{
	uint32_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_ACLFlags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_ACLFlags(uint32_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_ACLFlags(_Handle, Value));
}

SB_INLINE int32_t TElSftpFileAttributes::get_ACECount()
{
	int32_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_ACECount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSBSFTPACE
TSBSftpACE* TElSftpFileAttributes::get_ACEs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSftpFileAttributes_get_ACEs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ACEs)
		this->_Inst_ACEs = new TSBSftpACE(hOutResult, ohFalse);
	else
		this->_Inst_ACEs->updateHandle(hOutResult);
	return this->_Inst_ACEs;
}
#endif /* SB_USE_CLASS_TSBSFTPACE */

SB_INLINE int64_t TElSftpFileAttributes::get_ATimeInt64()
{
	int64_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_ATimeInt64(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_ATimeInt64(int64_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_ATimeInt64(_Handle, Value));
}

SB_INLINE int64_t TElSftpFileAttributes::get_MTimeInt64()
{
	int64_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_MTimeInt64(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_MTimeInt64(int64_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_MTimeInt64(_Handle, Value));
}

SB_INLINE int64_t TElSftpFileAttributes::get_CTimeInt64()
{
	int64_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_CTimeInt64(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_CTimeInt64(int64_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_CTimeInt64(_Handle, Value));
}

SB_INLINE int64_t TElSftpFileAttributes::get_CATimeInt64()
{
	int64_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_CATimeInt64(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_CATimeInt64(int64_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_CATimeInt64(_Handle, Value));
}

SB_INLINE uint32_t TElSftpFileAttributes::get_ATimeCardinal()
{
	uint32_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_ATimeCardinal(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_ATimeCardinal(uint32_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_ATimeCardinal(_Handle, Value));
}

SB_INLINE uint32_t TElSftpFileAttributes::get_MTimeCardinal()
{
	uint32_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_MTimeCardinal(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_MTimeCardinal(uint32_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_MTimeCardinal(_Handle, Value));
}

SB_INLINE uint32_t TElSftpFileAttributes::get_CTimeCardinal()
{
	uint32_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_CTimeCardinal(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_CTimeCardinal(uint32_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_CTimeCardinal(_Handle, Value));
}

SB_INLINE uint32_t TElSftpFileAttributes::get_CATimeCardinal()
{
	uint32_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_CATimeCardinal(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_CATimeCardinal(uint32_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_CATimeCardinal(_Handle, Value));
}

SB_INLINE int64_t TElSftpFileAttributes::get_ATimeSeconds()
{
	int64_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_ATimeSeconds(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElSftpFileAttributes::get_MTimeSeconds()
{
	int64_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_MTimeSeconds(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElSftpFileAttributes::get_CTimeSeconds()
{
	int64_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_CTimeSeconds(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElSftpFileAttributes::get_CATimeSeconds()
{
	int64_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_CATimeSeconds(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElSftpFileAttributes::get_ATimeMS()
{
	uint32_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_ATimeMS(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_ATimeMS(uint32_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_ATimeMS(_Handle, Value));
}

SB_INLINE uint32_t TElSftpFileAttributes::get_CTimeMS()
{
	uint32_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_CTimeMS(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_CTimeMS(uint32_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_CTimeMS(_Handle, Value));
}

SB_INLINE uint32_t TElSftpFileAttributes::get_CATimeMS()
{
	uint32_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_CATimeMS(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_CATimeMS(uint32_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_CATimeMS(_Handle, Value));
}

SB_INLINE uint32_t TElSftpFileAttributes::get_MTimeMS()
{
	uint32_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_MTimeMS(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_MTimeMS(uint32_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_MTimeMS(_Handle, Value));
}

SB_INLINE uint32_t TElSftpFileAttributes::get_AttribBits()
{
	uint32_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_AttribBits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_AttribBits(uint32_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_AttribBits(_Handle, Value));
}

SB_INLINE uint32_t TElSftpFileAttributes::get_AttribBitsValid()
{
	uint32_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_AttribBitsValid(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_AttribBitsValid(uint32_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_AttribBitsValid(_Handle, Value));
}

SB_INLINE uint8_t TElSftpFileAttributes::get_FileTypeByte()
{
	uint8_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_FileTypeByte(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_FileTypeByte(uint8_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_FileTypeByte(_Handle, Value));
}

SB_INLINE uint32_t TElSftpFileAttributes::get_Permissions()
{
	uint32_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_Permissions(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_Permissions(uint32_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_Permissions(_Handle, Value));
}

TSBSftpTextHint TElSftpFileAttributes::get_TextHint()
{
	TSBSftpTextHintRaw OutResultRaw = 0;
	SBCheckError(TElSftpFileAttributes_get_TextHint(_Handle, &OutResultRaw));
	return (TSBSftpTextHint)OutResultRaw;
}

SB_INLINE void TElSftpFileAttributes::set_TextHint(TSBSftpTextHint Value)
{
	SBCheckError(TElSftpFileAttributes_set_TextHint(_Handle, (TSBSftpTextHintRaw)Value));
}

void TElSftpFileAttributes::get_MimeType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpFileAttributes_get_MimeType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1507324527, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpFileAttributes::set_MimeType(const std::string &Value)
{
	SBCheckError(TElSftpFileAttributes_set_MimeType(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE uint32_t TElSftpFileAttributes::get_LinkCount()
{
	uint32_t OutResult;
	SBCheckError(TElSftpFileAttributes_get_LinkCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSftpFileAttributes::set_LinkCount(uint32_t Value)
{
	SBCheckError(TElSftpFileAttributes_set_LinkCount(_Handle, Value));
}

void TElSftpFileAttributes::get_UntranslatedName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpFileAttributes_get_UntranslatedName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(984317438, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpFileAttributes::set_UntranslatedName(const std::string &Value)
{
	SBCheckError(TElSftpFileAttributes_set_UntranslatedName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSftpFileAttributes::initInstances()
{
#ifdef SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE
	this->_Inst_ExtendedAttributes = NULL;
#endif /* SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE */
#ifdef SB_USE_CLASS_TSBSFTPACE
	this->_Inst_ACEs = NULL;
#endif /* SB_USE_CLASS_TSBSFTPACE */
}

TElSftpFileAttributes::TElSftpFileAttributes(TElSftpFileAttributesHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElSftpFileAttributes::TElSftpFileAttributes() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSftpFileAttributes_Create(&_Handle));
}

TElSftpFileAttributes::~TElSftpFileAttributes()
{
#ifdef SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE
	delete this->_Inst_ExtendedAttributes;
	this->_Inst_ExtendedAttributes = NULL;
#endif /* SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE */
#ifdef SB_USE_CLASS_TSBSFTPACE
	delete this->_Inst_ACEs;
	this->_Inst_ACEs = NULL;
#endif /* SB_USE_CLASS_TSBSFTPACE */
}
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEINFO

SB_INLINE void TElSftpFileInfo::CopyTo(TElSftpFileInfo &FileInfo)
{
	SBCheckError(TElSftpFileInfo_CopyTo(_Handle, FileInfo.getHandle()));
}

SB_INLINE void TElSftpFileInfo::CopyTo(TElSftpFileInfo *FileInfo)
{
	SBCheckError(TElSftpFileInfo_CopyTo(_Handle, (FileInfo != NULL) ? FileInfo->getHandle() : SB_NULL_HANDLE));
}

void TElSftpFileInfo::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpFileInfo_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1294141107, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpFileInfo::set_Name(const std::string &Value)
{
	SBCheckError(TElSftpFileInfo_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSftpFileInfo::get_LongName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpFileInfo_get_LongName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1936358336, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpFileInfo::set_LongName(const std::string &Value)
{
	SBCheckError(TElSftpFileInfo_set_LongName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSftpFileInfo::get_Path(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpFileInfo_get_Path(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(408220602, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpFileInfo::set_Path(const std::string &Value)
{
	SBCheckError(TElSftpFileInfo_set_Path(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
TElSftpFileAttributes* TElSftpFileInfo::get_Attributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSftpFileInfo_get_Attributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Attributes)
		this->_Inst_Attributes = new TElSftpFileAttributes(hOutResult, ohFalse);
	else
		this->_Inst_Attributes->updateHandle(hOutResult);
	return this->_Inst_Attributes;
}
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

void TElSftpFileInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */
}

TElSftpFileInfo::TElSftpFileInfo(TElSftpFileInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElSftpFileInfo::TElSftpFileInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSftpFileInfo_Create(&_Handle));
}

TElSftpFileInfo::~TElSftpFileInfo()
{
#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
	delete this->_Inst_Attributes;
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */
}
#endif /* SB_USE_CLASS_TELSFTPFILEINFO */

#ifdef SB_USE_CLASS_TSBSFTPOPENREQUESTINFO

TSBSftpOpenRequestInfo::TSBSftpOpenRequestInfo(TSBSftpOpenRequestInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TSBSftpOpenRequestInfo::TSBSftpOpenRequestInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBSftpOpenRequestInfo_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TSBSFTPOPENREQUESTINFO */

#ifdef SB_USE_CLASS_TSBSFTPTEXTHANDLEINFO

TSBSftpTextHandleInfo::TSBSftpTextHandleInfo(TSBSftpTextHandleInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TSBSftpTextHandleInfo::TSBSftpTextHandleInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBSftpTextHandleInfo_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TSBSFTPTEXTHANDLEINFO */

#ifdef SB_USE_CLASS_TELSFTPTRANSFERBLOCK

TElSftpTransferBlock::TElSftpTransferBlock(TElSftpTransferBlockHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSftpTransferBlock::TElSftpTransferBlock() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSftpTransferBlock_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSFTPTRANSFERBLOCK */

#ifdef SB_USE_CLASS_TELSFTPTRANSFERMANAGER

SB_INLINE void TElSftpTransferManager::Run()
{
	SBCheckError(TElSftpTransferManager_Run(_Handle));
}

bool TElSftpTransferManager::ProcessData(uint32_t Id, void * Buffer, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpTransferManager_ProcessData(_Handle, Id, Buffer, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSftpTransferManager::ProcessStatus(uint32_t Id, int32_t StatusCode, const std::string &Comment)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpTransferManager_ProcessStatus(_Handle, Id, StatusCode, Comment.data(), (int32_t)Comment.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSftpTransferManager::OperationFinished()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpTransferManager_OperationFinished(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpTransferManager::Terminate()
{
	SBCheckError(TElSftpTransferManager_Terminate(_Handle));
}

TSBSftpTransferDirection TElSftpTransferManager::get_Direction()
{
	TSBSftpTransferDirectionRaw OutResultRaw = 0;
	SBCheckError(TElSftpTransferManager_get_Direction(_Handle, &OutResultRaw));
	return (TSBSftpTransferDirection)OutResultRaw;
}

SB_INLINE int64_t TElSftpTransferManager::get_Received()
{
	int64_t OutResult;
	SBCheckError(TElSftpTransferManager_get_Received(_Handle, &OutResult));
	return OutResult;
}

void TElSftpTransferManager::get_Handle(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSftpTransferManager_get_Handle(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-402888580, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElSftpTransferManager::get_TextMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpTransferManager_get_TextMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElSftpTransferManager::get_LastError()
{
	int32_t OutResult;
	SBCheckError(TElSftpTransferManager_get_LastError(_Handle, &OutResult));
	return OutResult;
}

void TElSftpTransferManager::get_LastComment(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSftpTransferManager_get_LastComment(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(741791428, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSftpTransferManager::get_OnData(TSBSftpDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpTransferManager_get_OnData(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpTransferManager::set_OnData(TSBSftpDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpTransferManager_set_OnData(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpTransferManager::get_OnASCIIData(TSBSftpDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpTransferManager_get_OnASCIIData(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpTransferManager::set_OnASCIIData(TSBSftpDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpTransferManager_set_OnASCIIData(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpTransferManager::get_OnReadRequest(TSBSftpReadRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpTransferManager_get_OnReadRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpTransferManager::set_OnReadRequest(TSBSftpReadRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpTransferManager_set_OnReadRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpTransferManager::get_OnWriteRequest(TSBSftpWriteRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpTransferManager_get_OnWriteRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpTransferManager::set_OnWriteRequest(TSBSftpWriteRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpTransferManager_set_OnWriteRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpTransferManager::get_OnFinish(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpTransferManager_get_OnFinish(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpTransferManager::set_OnFinish(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpTransferManager_set_OnFinish(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpTransferManager::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpTransferManager_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpTransferManager::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpTransferManager_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

TElSftpTransferManager::TElSftpTransferManager(TElSftpTransferManagerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSftpTransferManager::TElSftpTransferManager(const std::vector<uint8_t> &Handle, int64_t Offset, void * Buffer, int32_t Size, int32_t ChunkSize, int32_t MaxActiveCount, TSBSftpTransferDirection Direction, bool TextMode) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSftpTransferManager_Create(SB_STD_VECTOR_FRONT_ADR(Handle), (int32_t)Handle.size(), Offset, Buffer, Size, ChunkSize, MaxActiveCount, (TSBSftpTransferDirectionRaw)Direction, (int8_t)TextMode, &_Handle));
}

#endif /* SB_USE_CLASS_TELSFTPTRANSFERMANAGER */

#ifdef SB_USE_CLASS_TELSFTPREMOVALTARGET

TElSftpRemovalTarget::TElSftpRemovalTarget(TElSftpRemovalTargetHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSftpRemovalTarget::TElSftpRemovalTarget() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSftpRemovalTarget_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSFTPREMOVALTARGET */

#ifdef SB_USE_CLASS_TELSFTPREMOVALMANAGER

SB_INLINE void TElSftpRemovalManager::Run()
{
	SBCheckError(TElSftpRemovalManager_Run(_Handle));
}

bool TElSftpRemovalManager::ProcessStatus(uint32_t Id, int32_t StatusCode, const std::string &ErrorMsg)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpRemovalManager_ProcessStatus(_Handle, Id, StatusCode, ErrorMsg.data(), (int32_t)ErrorMsg.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSftpRemovalManager::OperationFinished()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSftpRemovalManager_OperationFinished(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSftpRemovalManager::Terminate()
{
	SBCheckError(TElSftpRemovalManager_Terminate(_Handle));
}

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSftpRemovalManager::get_ErrorList()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSftpRemovalManager_get_ErrorList(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ErrorList)
		this->_Inst_ErrorList = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_ErrorList->updateHandle(hOutResult);
	return this->_Inst_ErrorList;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSftpRemovalManager::get_ErrorFilenames()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSftpRemovalManager_get_ErrorFilenames(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ErrorFilenames)
		this->_Inst_ErrorFilenames = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_ErrorFilenames->updateHandle(hOutResult);
	return this->_Inst_ErrorFilenames;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

SB_INLINE void TElSftpRemovalManager::get_OnFinish(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpRemovalManager_get_OnFinish(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpRemovalManager::set_OnFinish(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpRemovalManager_set_OnFinish(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpRemovalManager::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpRemovalManager_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpRemovalManager::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpRemovalManager_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSftpRemovalManager::get_OnRemovalRequest(TSBSftpRemovalRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSftpRemovalManager_get_OnRemovalRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSftpRemovalManager::set_OnRemovalRequest(TSBSftpRemovalRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSftpRemovalManager_set_OnRemovalRequest(_Handle, pMethodValue, pDataValue));
}

void TElSftpRemovalManager::initInstances()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_ErrorList = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_ErrorFilenames = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}

TElSftpRemovalManager::TElSftpRemovalManager(TElSftpRemovalManagerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TSTRINGS
TElSftpRemovalManager::TElSftpRemovalManager(TStrings &Filenames, int32_t MaxActiveCount) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSftpRemovalManager_Create(Filenames.getHandle(), MaxActiveCount, &_Handle));
}

TElSftpRemovalManager::TElSftpRemovalManager(TStrings *Filenames, int32_t MaxActiveCount) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSftpRemovalManager_Create((Filenames != NULL) ? Filenames->getHandle() : SB_NULL_HANDLE, MaxActiveCount, &_Handle));
}
#endif /* SB_USE_CLASS_TSTRINGS */

TElSftpRemovalManager::~TElSftpRemovalManager()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_ErrorList;
	this->_Inst_ErrorList = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_ErrorFilenames;
	this->_Inst_ErrorFilenames = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}
#endif /* SB_USE_CLASS_TELSFTPREMOVALMANAGER */

#ifdef SB_USE_GLOBAL_PROCS_SFTPCOMMON

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
void WriteDefaultAttributes(TElSftpFileAttributes &Attributes)
{
	TElClassHandle hAttributes = Attributes.getHandle();
	SBCheckError(SBSftpCommon_WriteDefaultAttributes(&hAttributes));
	Attributes.updateHandle(hAttributes);
}
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

SB_INLINE uint8_t RealPathControlToByte(TSBSftpRealpathControl Value)
{
	uint8_t OutResult;
	SBCheckError(SBSftpCommon_RealPathControlToByte((TSBSftpRealpathControlRaw)Value, &OutResult));
	return OutResult;
}

TSBSftpRealpathControl ByteToRealPathControl(uint8_t Value)
{
	TSBSftpRealpathControlRaw OutResultRaw = 0;
	SBCheckError(SBSftpCommon_ByteToRealPathControl(Value, &OutResultRaw));
	return (TSBSftpRealpathControl)OutResultRaw;
}

SB_INLINE uint32_t FileOpenAccessToUInt32(TSBSftpFileOpenAccess Value)
{
	uint32_t OutResult;
	SBCheckError(SBSftpCommon_FileOpenAccessToUInt32((TSBSftpFileOpenAccessRaw)Value, &OutResult));
	return OutResult;
}

TSBSftpFileOpenAccess UInt32ToFileOpenAccess(uint32_t Value)
{
	TSBSftpFileOpenAccessRaw OutResultRaw = 0;
	SBCheckError(SBSftpCommon_UInt32ToFileOpenAccess(Value, &OutResultRaw));
	return (TSBSftpFileOpenAccess)OutResultRaw;
}

TSBSftpRenameFlags UInt32ToRenameFlags(uint32_t Value)
{
	TSBSftpRenameFlagsRaw OutResultRaw = 0;
	SBCheckError(SBSftpCommon_UInt32ToRenameFlags(Value, &OutResultRaw));
	return (TSBSftpRenameFlags)OutResultRaw;
}

#endif /* SB_USE_GLOBAL_PROCS_SFTPCOMMON */

};	/* namespace SecureBlackbox */

