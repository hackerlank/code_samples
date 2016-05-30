#include "sbsimpleftps.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSIMPLEFTPSCLIENT

SB_INLINE void TElSimpleFTPSClient::ParseFileListEntry(const std::string &Entry, TSBFTPFileInfo &FileInfo)
{
	SBCheckError(TElSimpleFTPSClient_ParseFileListEntry(Entry.data(), (int32_t)Entry.length(), &FileInfo));
}

SB_INLINE void TElSimpleFTPSClient::ParseFileListEntry_Inst(const std::string &Entry, TSBFTPFileInfo &FileInfo)
{
	SBCheckError(TElSimpleFTPSClient_ParseFileListEntry_1(_Handle, Entry.data(), (int32_t)Entry.length(), &FileInfo));
}

#ifdef SB_USE_CLASS_TELFTPFILEINFO
SB_INLINE void TElSimpleFTPSClient::ParseFileListEntry(const std::string &Entry, TElFTPFileInfo &FileInfo)
{
	SBCheckError(TElSimpleFTPSClient_ParseFileListEntry_2(Entry.data(), (int32_t)Entry.length(), FileInfo.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::ParseFileListEntry(const std::string &Entry, TElFTPFileInfo *FileInfo)
{
	SBCheckError(TElSimpleFTPSClient_ParseFileListEntry_2(Entry.data(), (int32_t)Entry.length(), (FileInfo != NULL) ? FileInfo->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELFTPFILEINFO */

#ifdef SB_USE_CLASS_TELFTPFILEINFO
SB_INLINE void TElSimpleFTPSClient::ParseFileListEntry_Inst(const std::string &Entry, TElFTPFileInfo &FileInfo)
{
	SBCheckError(TElSimpleFTPSClient_ParseFileListEntry_3(_Handle, Entry.data(), (int32_t)Entry.length(), FileInfo.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::ParseFileListEntry_Inst(const std::string &Entry, TElFTPFileInfo *FileInfo)
{
	SBCheckError(TElSimpleFTPSClient_ParseFileListEntry_3(_Handle, Entry.data(), (int32_t)Entry.length(), (FileInfo != NULL) ? FileInfo->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELFTPFILEINFO */

SB_INLINE void TElSimpleFTPSClient::ParseMLSDEntry(const std::string &Entry, TSBFTPFileInfo &FileInfo)
{
	SBCheckError(TElSimpleFTPSClient_ParseMLSDEntry(Entry.data(), (int32_t)Entry.length(), &FileInfo));
}

SB_INLINE void TElSimpleFTPSClient::ParseMLSDEntry_Inst(const std::string &Entry, TSBFTPFileInfo &FileInfo)
{
	SBCheckError(TElSimpleFTPSClient_ParseMLSDEntry_1(_Handle, Entry.data(), (int32_t)Entry.length(), &FileInfo));
}

#ifdef SB_USE_CLASS_TELFTPFILEINFO
SB_INLINE void TElSimpleFTPSClient::ParseMLSDEntry(const std::string &Entry, TElFTPFileInfo &FileInfo)
{
	SBCheckError(TElSimpleFTPSClient_ParseMLSDEntry_2(Entry.data(), (int32_t)Entry.length(), FileInfo.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::ParseMLSDEntry(const std::string &Entry, TElFTPFileInfo *FileInfo)
{
	SBCheckError(TElSimpleFTPSClient_ParseMLSDEntry_2(Entry.data(), (int32_t)Entry.length(), (FileInfo != NULL) ? FileInfo->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELFTPFILEINFO */

#ifdef SB_USE_CLASS_TELFTPFILEINFO
SB_INLINE void TElSimpleFTPSClient::ParseMLSDEntry_Inst(const std::string &Entry, TElFTPFileInfo &FileInfo)
{
	SBCheckError(TElSimpleFTPSClient_ParseMLSDEntry_3(_Handle, Entry.data(), (int32_t)Entry.length(), FileInfo.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::ParseMLSDEntry_Inst(const std::string &Entry, TElFTPFileInfo *FileInfo)
{
	SBCheckError(TElSimpleFTPSClient_ParseMLSDEntry_3(_Handle, Entry.data(), (int32_t)Entry.length(), (FileInfo != NULL) ? FileInfo->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELFTPFILEINFO */

SB_INLINE void TElSimpleFTPSClient::Abort()
{
	SBCheckError(TElSimpleFTPSClient_Abort(_Handle));
}

SB_INLINE void TElSimpleFTPSClient::Acct(const std::string &AcctInfo)
{
	SBCheckError(TElSimpleFTPSClient_Acct(_Handle, AcctInfo.data(), (int32_t)AcctInfo.length()));
}

SB_INLINE void TElSimpleFTPSClient::Allocate(int32_t Size)
{
	SBCheckError(TElSimpleFTPSClient_Allocate(_Handle, Size));
}

SB_INLINE void TElSimpleFTPSClient::Assign(TPersistent &Source)
{
	SBCheckError(TElSimpleFTPSClient_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::Assign(TPersistent *Source)
{
	SBCheckError(TElSimpleFTPSClient_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElSimpleFTPSClient::CDUp()
{
	SBCheckError(TElSimpleFTPSClient_CDUp(_Handle));
}

SB_INLINE void TElSimpleFTPSClient::ClearCommandChannel()
{
	SBCheckError(TElSimpleFTPSClient_ClearCommandChannel(_Handle));
}

SB_INLINE void TElSimpleFTPSClient::ClearCommandChannel(bool GracefulSSLClosure)
{
	SBCheckError(TElSimpleFTPSClient_ClearCommandChannel_1(_Handle, (int8_t)GracefulSSLClosure));
}

SB_INLINE void TElSimpleFTPSClient::Interrupt()
{
	SBCheckError(TElSimpleFTPSClient_Interrupt(_Handle));
}

SB_INLINE void TElSimpleFTPSClient::Close(bool Silent)
{
	SBCheckError(TElSimpleFTPSClient_Close(_Handle, (int8_t)Silent));
}

SB_INLINE void TElSimpleFTPSClient::Cwd(const std::string &APath)
{
	SBCheckError(TElSimpleFTPSClient_Cwd(_Handle, APath.data(), (int32_t)APath.length()));
}

SB_INLINE void TElSimpleFTPSClient::Delete(const std::string &AFilename)
{
	SBCheckError(TElSimpleFTPSClient_Delete(_Handle, AFilename.data(), (int32_t)AFilename.length()));
}

void TElSimpleFTPSClient::GetCurrentDir(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_GetCurrentDir(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2032383009, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSimpleFTPSClient::GetServerSystem(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_GetServerSystem(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1298404546, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSClient::MLSD()
{
	SBCheckError(TElSimpleFTPSClient_MLSD(_Handle));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElSimpleFTPSClient::MLSD(TStringList &ResultList)
{
	SBCheckError(TElSimpleFTPSClient_MLSD_1(_Handle, ResultList.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::MLSD(TStringList *ResultList)
{
	SBCheckError(TElSimpleFTPSClient_MLSD_1(_Handle, (ResultList != NULL) ? ResultList->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElSimpleFTPSClient::MLSD(TElStringList &ResultList)
{
	SBCheckError(TElSimpleFTPSClient_MLSD_1(_Handle, ResultList.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::MLSD(TElStringList *ResultList)
{
	SBCheckError(TElSimpleFTPSClient_MLSD_1(_Handle, (ResultList != NULL) ? ResultList->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TLIST
SB_INLINE void TElSimpleFTPSClient::MLSD(TList &ResultList)
{
	SBCheckError(TElSimpleFTPSClient_MLSD_2(_Handle, ResultList.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::MLSD(TList *ResultList)
{
	SBCheckError(TElSimpleFTPSClient_MLSD_2(_Handle, (ResultList != NULL) ? ResultList->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TLIST */

SB_INLINE void TElSimpleFTPSClient::MLSD(const std::string &Path)
{
	SBCheckError(TElSimpleFTPSClient_MLSD_3(_Handle, Path.data(), (int32_t)Path.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElSimpleFTPSClient::MLSD(const std::string &Path, TStringList &ResultList)
{
	SBCheckError(TElSimpleFTPSClient_MLSD_4(_Handle, Path.data(), (int32_t)Path.length(), ResultList.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::MLSD(const std::string &Path, TStringList *ResultList)
{
	SBCheckError(TElSimpleFTPSClient_MLSD_4(_Handle, Path.data(), (int32_t)Path.length(), (ResultList != NULL) ? ResultList->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElSimpleFTPSClient::MLSD(const std::string &Path, TElStringList &ResultList)
{
	SBCheckError(TElSimpleFTPSClient_MLSD_4(_Handle, Path.data(), (int32_t)Path.length(), ResultList.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::MLSD(const std::string &Path, TElStringList *ResultList)
{
	SBCheckError(TElSimpleFTPSClient_MLSD_4(_Handle, Path.data(), (int32_t)Path.length(), (ResultList != NULL) ? ResultList->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TLIST
SB_INLINE void TElSimpleFTPSClient::MLSD(const std::string &Path, TList &ResultList)
{
	SBCheckError(TElSimpleFTPSClient_MLSD_5(_Handle, Path.data(), (int32_t)Path.length(), ResultList.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::MLSD(const std::string &Path, TList *ResultList)
{
	SBCheckError(TElSimpleFTPSClient_MLSD_5(_Handle, Path.data(), (int32_t)Path.length(), (ResultList != NULL) ? ResultList->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TELFTPFILEINFO
bool TElSimpleFTPSClient::MLST(const std::string &Path, TElFTPFileInfo &FileInfo)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_MLST(_Handle, Path.data(), (int32_t)Path.length(), FileInfo.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSimpleFTPSClient::MLST(const std::string &Path, TElFTPFileInfo *FileInfo)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_MLST(_Handle, Path.data(), (int32_t)Path.length(), (FileInfo != NULL) ? FileInfo->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELFTPFILEINFO */

SB_INLINE void TElSimpleFTPSClient::CreateCompletePath(const std::string &Path)
{
	SBCheckError(TElSimpleFTPSClient_CreateCompletePath(_Handle, Path.data(), (int32_t)Path.length()));
}

SB_INLINE void TElSimpleFTPSClient::NOOP()
{
	SBCheckError(TElSimpleFTPSClient_NOOP(_Handle));
}

bool TElSimpleFTPSClient::DirectoryExists(const std::string &Path)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_DirectoryExists(_Handle, Path.data(), (int32_t)Path.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSimpleFTPSClient::FileExists(const std::string &AFilename)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_FileExists(_Handle, AFilename.data(), (int32_t)AFilename.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t TElSimpleFTPSClient::GetFileSize(const std::string &AFilename)
{
	int64_t OutResult;
	SBCheckError(TElSimpleFTPSClient_GetFileSize(_Handle, AFilename.data(), (int32_t)AFilename.length(), &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElSimpleFTPSClient::GetFileTime(const std::string &AFilename)
{
	int64_t OutResult;
	SBCheckError(TElSimpleFTPSClient_GetFileTime(_Handle, AFilename.data(), (int32_t)AFilename.length(), &OutResult));
	return OutResult;
}

bool TElSimpleFTPSClient::SetFileTime(const std::string &AFilename, int64_t NewDate)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_SetFileTime(_Handle, AFilename.data(), (int32_t)AFilename.length(), NewDate, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElSimpleFTPSClient::GetRemoteChecksum(const std::string &AFileName, TSBFTPCheckMethod CheckMethod, int64_t StartPoint, int64_t EndPoint, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_GetRemoteChecksum(_Handle, AFileName.data(), (int32_t)AFileName.length(), (TSBFTPCheckMethodRaw)CheckMethod, StartPoint, EndPoint, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-247591981, 5, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSimpleFTPSClient::GetLocalChecksum(const std::string &AFileName, TSBFTPCheckMethod CheckMethod, int64_t StartPoint, int64_t EndPoint, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_GetLocalChecksum(_Handle, AFileName.data(), (int32_t)AFileName.length(), (TSBFTPCheckMethodRaw)CheckMethod, StartPoint, EndPoint, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1747557107, 5, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSClient::GetNameList()
{
	SBCheckError(TElSimpleFTPSClient_GetNameList(_Handle));
}

SB_INLINE void TElSimpleFTPSClient::GetNameList(const std::string &Parameters)
{
	SBCheckError(TElSimpleFTPSClient_GetNameList_1(_Handle, Parameters.data(), (int32_t)Parameters.length()));
}

SB_INLINE void TElSimpleFTPSClient::GetFileList()
{
	SBCheckError(TElSimpleFTPSClient_GetFileList(_Handle));
}

SB_INLINE void TElSimpleFTPSClient::GetFileList(const std::string &Parameters)
{
	SBCheckError(TElSimpleFTPSClient_GetFileList_1(_Handle, Parameters.data(), (int32_t)Parameters.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElSimpleFTPSClient::GetFileList(const std::string &Parameters, TStringList &ResultList)
{
	SBCheckError(TElSimpleFTPSClient_GetFileList_2(_Handle, Parameters.data(), (int32_t)Parameters.length(), ResultList.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::GetFileList(const std::string &Parameters, TStringList *ResultList)
{
	SBCheckError(TElSimpleFTPSClient_GetFileList_2(_Handle, Parameters.data(), (int32_t)Parameters.length(), (ResultList != NULL) ? ResultList->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElSimpleFTPSClient::GetFileList(const std::string &Parameters, TElStringList &ResultList)
{
	SBCheckError(TElSimpleFTPSClient_GetFileList_2(_Handle, Parameters.data(), (int32_t)Parameters.length(), ResultList.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::GetFileList(const std::string &Parameters, TElStringList *ResultList)
{
	SBCheckError(TElSimpleFTPSClient_GetFileList_2(_Handle, Parameters.data(), (int32_t)Parameters.length(), (ResultList != NULL) ? ResultList->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TLIST
SB_INLINE void TElSimpleFTPSClient::GetFileList(const std::string &Parameters, TList &ResultList)
{
	SBCheckError(TElSimpleFTPSClient_GetFileList_3(_Handle, Parameters.data(), (int32_t)Parameters.length(), ResultList.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::GetFileList(const std::string &Parameters, TList *ResultList)
{
	SBCheckError(TElSimpleFTPSClient_GetFileList_3(_Handle, Parameters.data(), (int32_t)Parameters.length(), (ResultList != NULL) ? ResultList->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE void TElSimpleFTPSClient::ListDirectory(const std::string &Path, TList &Listing, const std::string &Mask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories)
{
	SBCheckError(TElSimpleFTPSClient_ListDirectory(_Handle, Path.data(), (int32_t)Path.length(), Listing.getHandle(), Mask.data(), (int32_t)Mask.length(), (int8_t)CaseSensitive, (int8_t)IncludeFiles, (int8_t)IncludeDirectories));
}

SB_INLINE void TElSimpleFTPSClient::ListDirectory(const std::string &Path, TList *Listing, const std::string &Mask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories)
{
	SBCheckError(TElSimpleFTPSClient_ListDirectory(_Handle, Path.data(), (int32_t)Path.length(), (Listing != NULL) ? Listing->getHandle() : SB_NULL_HANDLE, Mask.data(), (int32_t)Mask.length(), (int8_t)CaseSensitive, (int8_t)IncludeFiles, (int8_t)IncludeDirectories));
}
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
SB_INLINE void TElSimpleFTPSClient::ListDirectory(const std::string &Path, TList &Listing, const std::string &Mask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories, bool Recursive)
{
	SBCheckError(TElSimpleFTPSClient_ListDirectory_1(_Handle, Path.data(), (int32_t)Path.length(), Listing.getHandle(), Mask.data(), (int32_t)Mask.length(), (int8_t)CaseSensitive, (int8_t)IncludeFiles, (int8_t)IncludeDirectories, (int8_t)Recursive));
}

SB_INLINE void TElSimpleFTPSClient::ListDirectory(const std::string &Path, TList *Listing, const std::string &Mask, bool CaseSensitive, bool IncludeFiles, bool IncludeDirectories, bool Recursive)
{
	SBCheckError(TElSimpleFTPSClient_ListDirectory_1(_Handle, Path.data(), (int32_t)Path.length(), (Listing != NULL) ? Listing->getHandle() : SB_NULL_HANDLE, Mask.data(), (int32_t)Mask.length(), (int8_t)CaseSensitive, (int8_t)IncludeFiles, (int8_t)IncludeDirectories, (int8_t)Recursive));
}
#endif /* SB_USE_CLASS_TLIST */

SB_INLINE void TElSimpleFTPSClient::Open()
{
	SBCheckError(TElSimpleFTPSClient_Open(_Handle));
}

void TElSimpleFTPSClient::InternalValidate(TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason)
{
	TSBCertificateValidityRaw ValidityRaw = (TSBCertificateValidityRaw)Validity;
	TSBCertificateValidityReasonRaw ReasonRaw = (TSBCertificateValidityReasonRaw)Reason;
	SBCheckError(TElSimpleFTPSClient_InternalValidate(_Handle, &ValidityRaw, &ReasonRaw));
	Validity = (TSBCertificateValidity)ValidityRaw;
	Reason = (TSBCertificateValidityReason)ReasonRaw;
}

SB_INLINE void TElSimpleFTPSClient::EstablishSSLSession()
{
	SBCheckError(TElSimpleFTPSClient_EstablishSSLSession(_Handle));
}

void TElSimpleFTPSClient::Login(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_Login(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(255713546, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSClient::MakeDir(const std::string &Path)
{
	SBCheckError(TElSimpleFTPSClient_MakeDir(_Handle, Path.data(), (int32_t)Path.length()));
}

SB_INLINE void TElSimpleFTPSClient::MountStruct(const std::string &Path)
{
	SBCheckError(TElSimpleFTPSClient_MountStruct(_Handle, Path.data(), (int32_t)Path.length()));
}

SB_INLINE void TElSimpleFTPSClient::Receive(const std::string &Filename, int64_t StartPos, int64_t EndPos)
{
	SBCheckError(TElSimpleFTPSClient_Receive(_Handle, Filename.data(), (int32_t)Filename.length(), StartPos, EndPos));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSimpleFTPSClient::Receive(const std::string &Filename, TStream &Stream, int64_t StartPos, int64_t EndPos)
{
	SBCheckError(TElSimpleFTPSClient_Receive_1(_Handle, Filename.data(), (int32_t)Filename.length(), Stream.getHandle(), StartPos, EndPos));
}

SB_INLINE void TElSimpleFTPSClient::Receive(const std::string &Filename, TStream *Stream, int64_t StartPos, int64_t EndPos)
{
	SBCheckError(TElSimpleFTPSClient_Receive_1(_Handle, Filename.data(), (int32_t)Filename.length(), (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, StartPos, EndPos));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElSimpleFTPSClient::Reinitialize()
{
	SBCheckError(TElSimpleFTPSClient_Reinitialize(_Handle));
}

SB_INLINE void TElSimpleFTPSClient::RemoveDir(const std::string &Path)
{
	SBCheckError(TElSimpleFTPSClient_RemoveDir(_Handle, Path.data(), (int32_t)Path.length()));
}

SB_INLINE void TElSimpleFTPSClient::Rename(const std::string &SourceFile, const std::string &DestFile)
{
	SBCheckError(TElSimpleFTPSClient_Rename(_Handle, SourceFile.data(), (int32_t)SourceFile.length(), DestFile.data(), (int32_t)DestFile.length()));
}

SB_INLINE void TElSimpleFTPSClient::RenegotiateCiphers()
{
	SBCheckError(TElSimpleFTPSClient_RenegotiateCiphers(_Handle));
}

SB_INLINE int16_t TElSimpleFTPSClient::SendCmd(const std::string &Command, const std::vector<int16_t> &AcceptCodes)
{
	int16_t OutResult;
	SBCheckError(TElSimpleFTPSClient_SendCmd(_Handle, Command.data(), (int32_t)Command.length(), SB_STD_VECTOR_FRONT_ADR(AcceptCodes), (int32_t)AcceptCodes.size(), &OutResult));
	return OutResult;
}

SB_INLINE int16_t TElSimpleFTPSClient::SendCmd(const std::string &Command, const std::vector<int16_t> &AcceptCodes, const std::vector<int16_t> &IntermediateAcceptCodes)
{
	int16_t OutResult;
	SBCheckError(TElSimpleFTPSClient_SendCmd_1(_Handle, Command.data(), (int32_t)Command.length(), SB_STD_VECTOR_FRONT_ADR(AcceptCodes), (int32_t)AcceptCodes.size(), SB_STD_VECTOR_FRONT_ADR(IntermediateAcceptCodes), (int32_t)IntermediateAcceptCodes.size(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSimpleFTPSClient::Send(TStream &Stream, const std::string &FileName, int64_t StartPos, int64_t EndPos, bool Append, int64_t RestartFrom)
{
	SBCheckError(TElSimpleFTPSClient_Send(_Handle, Stream.getHandle(), FileName.data(), (int32_t)FileName.length(), StartPos, EndPos, (int8_t)Append, RestartFrom));
}

SB_INLINE void TElSimpleFTPSClient::Send(TStream *Stream, const std::string &FileName, int64_t StartPos, int64_t EndPos, bool Append, int64_t RestartFrom)
{
	SBCheckError(TElSimpleFTPSClient_Send(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, FileName.data(), (int32_t)FileName.length(), StartPos, EndPos, (int8_t)Append, RestartFrom));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSimpleFTPSClient::Send(TStream &Stream, const std::string &FileName, int64_t RestartFrom)
{
	SBCheckError(TElSimpleFTPSClient_Send_1(_Handle, Stream.getHandle(), FileName.data(), (int32_t)FileName.length(), RestartFrom));
}

SB_INLINE void TElSimpleFTPSClient::Send(TStream *Stream, const std::string &FileName, int64_t RestartFrom)
{
	SBCheckError(TElSimpleFTPSClient_Send_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, FileName.data(), (int32_t)FileName.length(), RestartFrom));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSimpleFTPSClient::Send(TStream &Stream, const std::string &FileName)
{
	SBCheckError(TElSimpleFTPSClient_Send_2(_Handle, Stream.getHandle(), FileName.data(), (int32_t)FileName.length()));
}

SB_INLINE void TElSimpleFTPSClient::Send(TStream *Stream, const std::string &FileName)
{
	SBCheckError(TElSimpleFTPSClient_Send_2(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, FileName.data(), (int32_t)FileName.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElSimpleFTPSClient::DownloadFile(const std::string &RemoteFileName, const std::string &LocalFileName)
{
	SBCheckError(TElSimpleFTPSClient_DownloadFile(_Handle, RemoteFileName.data(), (int32_t)RemoteFileName.length(), LocalFileName.data(), (int32_t)LocalFileName.length()));
}

SB_INLINE void TElSimpleFTPSClient::DownloadFile(const std::string &RemoteFileName, const std::string &LocalFileName, TSBFileTransferMode Mode)
{
	SBCheckError(TElSimpleFTPSClient_DownloadFile_1(_Handle, RemoteFileName.data(), (int32_t)RemoteFileName.length(), LocalFileName.data(), (int32_t)LocalFileName.length(), (TSBFileTransferModeRaw)Mode));
}

SB_INLINE void TElSimpleFTPSClient::DownloadFile(const std::string &RemoteFileName, const std::string &LocalFileName, TSBFileTransferMode Mode, int64_t RestartFrom)
{
	SBCheckError(TElSimpleFTPSClient_DownloadFile_2(_Handle, RemoteFileName.data(), (int32_t)RemoteFileName.length(), LocalFileName.data(), (int32_t)LocalFileName.length(), (TSBFileTransferModeRaw)Mode, RestartFrom));
}

SB_INLINE void TElSimpleFTPSClient::UploadFile(const std::string &LocalFileName, const std::string &RemoteFileName)
{
	SBCheckError(TElSimpleFTPSClient_UploadFile(_Handle, LocalFileName.data(), (int32_t)LocalFileName.length(), RemoteFileName.data(), (int32_t)RemoteFileName.length()));
}

SB_INLINE void TElSimpleFTPSClient::UploadFile(const std::string &LocalFileName, const std::string &RemoteFileName, TSBFileTransferMode Mode)
{
	SBCheckError(TElSimpleFTPSClient_UploadFile_1(_Handle, LocalFileName.data(), (int32_t)LocalFileName.length(), RemoteFileName.data(), (int32_t)RemoteFileName.length(), (TSBFileTransferModeRaw)Mode));
}

SB_INLINE void TElSimpleFTPSClient::UploadFile(const std::string &LocalFileName, const std::string &RemoteFileName, TSBFileTransferMode Mode, int64_t RestartFrom)
{
	SBCheckError(TElSimpleFTPSClient_UploadFile_2(_Handle, LocalFileName.data(), (int32_t)LocalFileName.length(), RemoteFileName.data(), (int32_t)RemoteFileName.length(), (TSBFileTransferModeRaw)Mode, RestartFrom));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSimpleFTPSClient::DownloadStream(const std::string &RemoteFileName, TStream &LocalStream, TSBFileTransferMode Mode, int64_t RestartFrom)
{
	SBCheckError(TElSimpleFTPSClient_DownloadStream(_Handle, RemoteFileName.data(), (int32_t)RemoteFileName.length(), LocalStream.getHandle(), (TSBFileTransferModeRaw)Mode, RestartFrom));
}

SB_INLINE void TElSimpleFTPSClient::DownloadStream(const std::string &RemoteFileName, TStream *LocalStream, TSBFileTransferMode Mode, int64_t RestartFrom)
{
	SBCheckError(TElSimpleFTPSClient_DownloadStream(_Handle, RemoteFileName.data(), (int32_t)RemoteFileName.length(), (LocalStream != NULL) ? LocalStream->getHandle() : SB_NULL_HANDLE, (TSBFileTransferModeRaw)Mode, RestartFrom));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSimpleFTPSClient::UploadStream(TStream &LocalStream, const std::string &RemoteFileName, TSBFileTransferMode Mode, int64_t RestartFrom)
{
	SBCheckError(TElSimpleFTPSClient_UploadStream(_Handle, LocalStream.getHandle(), RemoteFileName.data(), (int32_t)RemoteFileName.length(), (TSBFileTransferModeRaw)Mode, RestartFrom));
}

SB_INLINE void TElSimpleFTPSClient::UploadStream(TStream *LocalStream, const std::string &RemoteFileName, TSBFileTransferMode Mode, int64_t RestartFrom)
{
	SBCheckError(TElSimpleFTPSClient_UploadStream(_Handle, (LocalStream != NULL) ? LocalStream->getHandle() : SB_NULL_HANDLE, RemoteFileName.data(), (int32_t)RemoteFileName.length(), (TSBFileTransferModeRaw)Mode, RestartFrom));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElSimpleFTPSClient::DownloadFiles(const std::string &RemotePath, const std::string &RemoteMask, const std::string &LocalPath, TSBFileTransferMode Mode, bool CaseSensitive, TSBCaseConversion CaseConversion, bool Recursive)
{
	SBCheckError(TElSimpleFTPSClient_DownloadFiles(_Handle, RemotePath.data(), (int32_t)RemotePath.length(), RemoteMask.data(), (int32_t)RemoteMask.length(), LocalPath.data(), (int32_t)LocalPath.length(), (TSBFileTransferModeRaw)Mode, (int8_t)CaseSensitive, (TSBCaseConversionRaw)CaseConversion, (int8_t)Recursive));
}

SB_INLINE void TElSimpleFTPSClient::DownloadFiles(const std::string &RemotePath, const std::string &RemoteMask, const std::string &LocalPath, TSBFileTransferMode Mode, TSBFileCopyMode CopyMode, bool CaseSensitive, TSBCaseConversion CaseConversion, bool Recursive)
{
	SBCheckError(TElSimpleFTPSClient_DownloadFiles_1(_Handle, RemotePath.data(), (int32_t)RemotePath.length(), RemoteMask.data(), (int32_t)RemoteMask.length(), LocalPath.data(), (int32_t)LocalPath.length(), (TSBFileTransferModeRaw)Mode, (TSBFileCopyModeRaw)CopyMode, (int8_t)CaseSensitive, (TSBCaseConversionRaw)CaseConversion, (int8_t)Recursive));
}

SB_INLINE void TElSimpleFTPSClient::UploadFiles(const std::string &LocalPath, const std::string &LocalMask, const std::string &RemotePath, TSBFileTransferMode Mode, bool CaseSensitive, TSBCaseConversion CaseConversion, bool Recursive)
{
	SBCheckError(TElSimpleFTPSClient_UploadFiles(_Handle, LocalPath.data(), (int32_t)LocalPath.length(), LocalMask.data(), (int32_t)LocalMask.length(), RemotePath.data(), (int32_t)RemotePath.length(), (TSBFileTransferModeRaw)Mode, (int8_t)CaseSensitive, (TSBCaseConversionRaw)CaseConversion, (int8_t)Recursive));
}

SB_INLINE void TElSimpleFTPSClient::UploadFiles(const std::string &LocalPath, const std::string &LocalMask, const std::string &RemotePath, TSBFileTransferMode Mode, TSBFileCopyMode CopyMode, bool CaseSensitive, TSBCaseConversion CaseConversion, bool Recursive)
{
	SBCheckError(TElSimpleFTPSClient_UploadFiles_1(_Handle, LocalPath.data(), (int32_t)LocalPath.length(), LocalMask.data(), (int32_t)LocalMask.length(), RemotePath.data(), (int32_t)RemotePath.length(), (TSBFileTransferModeRaw)Mode, (TSBFileCopyModeRaw)CopyMode, (int8_t)CaseSensitive, (TSBCaseConversionRaw)CaseConversion, (int8_t)Recursive));
}

SB_INLINE void TElSimpleFTPSClient::RemoveFile(const std::string &Filename)
{
	SBCheckError(TElSimpleFTPSClient_RemoveFile(_Handle, Filename.data(), (int32_t)Filename.length()));
}

SB_INLINE void TElSimpleFTPSClient::RemoveFiles(const std::string &Path, const std::string &Mask, bool CaseSensitive, bool Recursive)
{
	SBCheckError(TElSimpleFTPSClient_RemoveFiles(_Handle, Path.data(), (int32_t)Path.length(), Mask.data(), (int32_t)Mask.length(), (int8_t)CaseSensitive, (int8_t)Recursive));
}

#ifdef SB_USE_CLASS_TSTRINGS
SB_INLINE void TElSimpleFTPSClient::RemoveFiles(TStrings &List)
{
	SBCheckError(TElSimpleFTPSClient_RemoveFiles_1(_Handle, List.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::RemoveFiles(TStrings *List)
{
	SBCheckError(TElSimpleFTPSClient_RemoveFiles_1(_Handle, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGS */

SB_INLINE uint8_t TElSimpleFTPSClient::get_CipherSuite()
{
	uint8_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_CipherSuite(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElSimpleFTPSClient::get_CompressionAlgorithm()
{
	uint8_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_CompressionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

bool TElSimpleFTPSClient::get_CipherSuites(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_CipherSuites(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSClient::set_CipherSuites(uint8_t Index, bool Value)
{
	SBCheckError(TElSimpleFTPSClient_set_CipherSuites(_Handle, Index, (int8_t)Value));
}

SB_INLINE int32_t TElSimpleFTPSClient::get_CipherSuitePriorities(uint8_t Index)
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_CipherSuitePriorities(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSClient::set_CipherSuitePriorities(uint8_t Index, int32_t Value)
{
	SBCheckError(TElSimpleFTPSClient_set_CipherSuitePriorities(_Handle, Index, Value));
}

bool TElSimpleFTPSClient::get_CompressionAlgorithms(uint8_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_CompressionAlgorithms(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSClient::set_CompressionAlgorithms(uint8_t Index, bool Value)
{
	SBCheckError(TElSimpleFTPSClient_set_CompressionAlgorithms(_Handle, Index, (int8_t)Value));
}

TSBVersion TElSimpleFTPSClient::get_Version()
{
	TSBVersionRaw OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_Version(_Handle, &OutResultRaw));
	return (TSBVersion)OutResultRaw;
}

bool TElSimpleFTPSClient::get_Active()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_Active(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElSimpleFTPSClient::get_LastReceivedReply(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_get_LastReceivedReply(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-818627235, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElSimpleFTPSClient::get_ModeZSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_ModeZSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSimpleFTPSClient::get_ExtMLSTSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_ExtMLSTSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSimpleFTPSClient::get_ExtMDTMSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_ExtMDTMSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSimpleFTPSClient::get_ExtMFMTSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_ExtMFMTSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSimpleFTPSClient::get_ExtSIZESupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_ExtSIZESupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSimpleFTPSClient::get_ExtRESTSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_ExtRESTSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSimpleFTPSClient::get_ExtXCRCSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_ExtXCRCSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSimpleFTPSClient::get_ExtXMD5Supported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_ExtXMD5Supported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSimpleFTPSClient::get_ExtXSHA1Supported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_ExtXSHA1Supported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSimpleFTPSClient::get_ExtOPTSUTF8Supported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_ExtOPTSUTF8Supported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSimpleFTPSClient::get_ExtHOSTSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_ExtHOSTSupported(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElSimpleFTPSClient::get_LocalNewLineConvention(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSimpleFTPSClient_get_LocalNewLineConvention(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(882766964, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSClient::set_LocalNewLineConvention(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_LocalNewLineConvention(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_WINDOWS
bool TElSimpleFTPSClient::get_UsingIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_UsingIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif

SB_INLINE int32_t TElSimpleFTPSClient::get_WebTunnelResult()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_WebTunnelResult(_Handle, &OutResult));
	return OutResult;
}

void TElSimpleFTPSClient::get_RemoteHost(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_get_RemoteHost(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1015321373, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSimpleFTPSClient::get_RemoteIP(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_get_RemoteIP(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1242497806, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElSimpleFTPSClient::get_TotalBytesSent()
{
	int64_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_TotalBytesSent(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElSimpleFTPSClient::get_TotalBytesReceived()
{
	int64_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_TotalBytesReceived(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElSimpleFTPSClient::get_TotalDataBytesSent()
{
	int64_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_TotalDataBytesSent(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElSimpleFTPSClient::get_TotalDataBytesReceived()
{
	int64_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_TotalDataBytesReceived(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSOCKET
TElSocket* TElSimpleFTPSClient::get_Socket()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSClient_get_Socket(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Socket)
		this->_Inst_Socket = new TElSocket(hOutResult, ohFalse);
	else
		this->_Inst_Socket->updateHandle(hOutResult);
	return this->_Inst_Socket;
}
#endif /* SB_USE_CLASS_TELSOCKET */

#ifdef SB_USE_CLASS_TELSOCKET
TElSocket* TElSimpleFTPSClient::get_DataSocket()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSClient_get_DataSocket(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DataSocket)
		this->_Inst_DataSocket = new TElSocket(hOutResult, ohFalse);
	else
		this->_Inst_DataSocket->updateHandle(hOutResult);
	return this->_Inst_DataSocket;
}
#endif /* SB_USE_CLASS_TELSOCKET */

#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
TElSocketSettings* TElSimpleFTPSClient::get_SocketSettings()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSClient_get_SocketSettings(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SocketSettings)
		this->_Inst_SocketSettings = new TElSocketSettings(hOutResult, ohFalse);
	else
		this->_Inst_SocketSettings->updateHandle(hOutResult);
	return this->_Inst_SocketSettings;
}
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */

void TElSimpleFTPSClient::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(635392723, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSClient::set_Address(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBFTPAuthCmd TElSimpleFTPSClient::get_AuthCmd()
{
	TSBFTPAuthCmdRaw OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_AuthCmd(_Handle, &OutResultRaw));
	return (TSBFTPAuthCmd)OutResultRaw;
}

SB_INLINE void TElSimpleFTPSClient::set_AuthCmd(TSBFTPAuthCmd Value)
{
	SBCheckError(TElSimpleFTPSClient_set_AuthCmd(_Handle, (TSBFTPAuthCmdRaw)Value));
}

SB_INLINE int32_t TElSimpleFTPSClient::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSClient::set_Port(int32_t Value)
{
	SBCheckError(TElSimpleFTPSClient_set_Port(_Handle, Value));
}

void TElSimpleFTPSClient::get_Username(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_get_Username(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1357821921, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSClient::set_Username(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_Username(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleFTPSClient::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1653409981, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSClient::set_Password(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleFTPSClient::get_VirtualHostName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_get_VirtualHostName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1647604136, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSClient::set_VirtualHostName(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_VirtualHostName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleFTPSClient::get_AccountInfo(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_get_AccountInfo(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1463264154, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSClient::set_AccountInfo(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_AccountInfo(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSimpleFTPSClient::get_PassiveMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_PassiveMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSClient::set_PassiveMode(bool Value)
{
	SBCheckError(TElSimpleFTPSClient_set_PassiveMode(_Handle, (int8_t)Value));
}

void TElSimpleFTPSClient::get_SRPUsername(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_get_SRPUsername(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1763552254, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSClient::set_SRPUsername(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_SRPUsername(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleFTPSClient::get_SRPPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_get_SRPPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1534989472, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSClient::set_SRPPassword(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_SRPPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBFTPTransferType TElSimpleFTPSClient::get_TransferType()
{
	TSBFTPTransferTypeRaw OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_TransferType(_Handle, &OutResultRaw));
	return (TSBFTPTransferType)OutResultRaw;
}

SB_INLINE void TElSimpleFTPSClient::set_TransferType(TSBFTPTransferType Value)
{
	SBCheckError(TElSimpleFTPSClient_set_TransferType(_Handle, (TSBFTPTransferTypeRaw)Value));
}

#ifdef SB_WINDOWS
bool TElSimpleFTPSClient::get_UseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_UseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSClient::set_UseIPv6(bool Value)
{
	SBCheckError(TElSimpleFTPSClient_set_UseIPv6(_Handle, (int8_t)Value));
}
#endif

bool TElSimpleFTPSClient::get_UseSSL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_UseSSL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSClient::set_UseSSL(bool Value)
{
	SBCheckError(TElSimpleFTPSClient_set_UseSSL(_Handle, (int8_t)Value));
}

bool TElSimpleFTPSClient::get_ModeZ()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_ModeZ(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSClient::set_ModeZ(bool Value)
{
	SBCheckError(TElSimpleFTPSClient_set_ModeZ(_Handle, (int8_t)Value));
}

SB_INLINE uint8_t TElSimpleFTPSClient::get_ModeZLevel()
{
	uint8_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_ModeZLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSClient::set_ModeZLevel(uint8_t Value)
{
	SBCheckError(TElSimpleFTPSClient_set_ModeZLevel(_Handle, Value));
}

TSBVersions TElSimpleFTPSClient::get_Versions()
{
	TSBVersionsRaw OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_Versions(_Handle, &OutResultRaw));
	return (TSBVersions)OutResultRaw;
}

SB_INLINE void TElSimpleFTPSClient::set_Versions(TSBVersions Value)
{
	SBCheckError(TElSimpleFTPSClient_set_Versions(_Handle, (TSBVersionsRaw)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElSimpleFTPSClient::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSClient_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElSimpleFTPSClient::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElSimpleFTPSClient_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElSimpleFTPSClient::get_ClientCertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSClient_get_ClientCertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ClientCertStorage)
		this->_Inst_ClientCertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_ClientCertStorage->updateHandle(hOutResult);
	return this->_Inst_ClientCertStorage;
}

SB_INLINE void TElSimpleFTPSClient::set_ClientCertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_ClientCertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::set_ClientCertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElSimpleFTPSClient_set_ClientCertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

TSBSSLMode TElSimpleFTPSClient::get_SSLMode()
{
	TSBSSLModeRaw OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_SSLMode(_Handle, &OutResultRaw));
	return (TSBSSLMode)OutResultRaw;
}

SB_INLINE void TElSimpleFTPSClient::set_SSLMode(TSBSSLMode Value)
{
	SBCheckError(TElSimpleFTPSClient_set_SSLMode(_Handle, (TSBSSLModeRaw)Value));
}

bool TElSimpleFTPSClient::get_EncryptDataChannel()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_EncryptDataChannel(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSClient::set_EncryptDataChannel(bool Value)
{
	SBCheckError(TElSimpleFTPSClient_set_EncryptDataChannel(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElSimpleFTPSClient::get_FTPBufferSize()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_FTPBufferSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSClient::set_FTPBufferSize(int32_t Value)
{
	SBCheckError(TElSimpleFTPSClient_set_FTPBufferSize(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELFTPPROXYSETTINGS
TElFTPProxySettings* TElSimpleFTPSClient::get_ProxySettings()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSClient_get_ProxySettings(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ProxySettings)
		this->_Inst_ProxySettings = new TElFTPProxySettings(hOutResult, ohFalse);
	else
		this->_Inst_ProxySettings->updateHandle(hOutResult);
	return this->_Inst_ProxySettings;
}

SB_INLINE void TElSimpleFTPSClient::set_ProxySettings(TElFTPProxySettings &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_ProxySettings(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::set_ProxySettings(TElFTPProxySettings *Value)
{
	SBCheckError(TElSimpleFTPSClient_set_ProxySettings(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELFTPPROXYSETTINGS */

SB_INLINE int32_t TElSimpleFTPSClient::get_TransferTimeout()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_TransferTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSClient::set_TransferTimeout(int32_t Value)
{
	SBCheckError(TElSimpleFTPSClient_set_TransferTimeout(_Handle, Value));
}

SB_INLINE int32_t TElSimpleFTPSClient::get_SocketTimeout()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_SocketTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSClient::set_SocketTimeout(int32_t Value)
{
	SBCheckError(TElSimpleFTPSClient_set_SocketTimeout(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
TElClientSSLExtensions* TElSimpleFTPSClient::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSClient_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElClientSSLExtensions(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
TElCustomSSLExtensions* TElSimpleFTPSClient::get_PeerExtensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSClient_get_PeerExtensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PeerExtensions)
		this->_Inst_PeerExtensions = new TElCustomSSLExtensions(hOutResult, ohFalse);
	else
		this->_Inst_PeerExtensions->updateHandle(hOutResult);
	return this->_Inst_PeerExtensions;
}
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
TElClientSocketBinding* TElSimpleFTPSClient::get_CommandSocketBinding()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSClient_get_CommandSocketBinding(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CommandSocketBinding)
		this->_Inst_CommandSocketBinding = new TElClientSocketBinding(hOutResult, ohFalse);
	else
		this->_Inst_CommandSocketBinding->updateHandle(hOutResult);
	return this->_Inst_CommandSocketBinding;
}

SB_INLINE void TElSimpleFTPSClient::set_CommandSocketBinding(TElClientSocketBinding &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_CommandSocketBinding(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::set_CommandSocketBinding(TElClientSocketBinding *Value)
{
	SBCheckError(TElSimpleFTPSClient_set_CommandSocketBinding(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
TElClientSocketBinding* TElSimpleFTPSClient::get_DataSocketBinding()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSClient_get_DataSocketBinding(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DataSocketBinding)
		this->_Inst_DataSocketBinding = new TElClientSocketBinding(hOutResult, ohFalse);
	else
		this->_Inst_DataSocketBinding->updateHandle(hOutResult);
	return this->_Inst_DataSocketBinding;
}

SB_INLINE void TElSimpleFTPSClient::set_DataSocketBinding(TElClientSocketBinding &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_DataSocketBinding(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::set_DataSocketBinding(TElClientSocketBinding *Value)
{
	SBCheckError(TElSimpleFTPSClient_set_DataSocketBinding(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
TElCustomFileSystemAdapter* TElSimpleFTPSClient::get_FileSystemAdapter()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSClient_get_FileSystemAdapter(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FileSystemAdapter)
		this->_Inst_FileSystemAdapter = new TElCustomFileSystemAdapter(hOutResult, ohFalse);
	else
		this->_Inst_FileSystemAdapter->updateHandle(hOutResult);
	return this->_Inst_FileSystemAdapter;
}

SB_INLINE void TElSimpleFTPSClient::set_FileSystemAdapter(TElCustomFileSystemAdapter &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_FileSystemAdapter(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::set_FileSystemAdapter(TElCustomFileSystemAdapter *Value)
{
	SBCheckError(TElSimpleFTPSClient_set_FileSystemAdapter(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

#ifdef SB_USE_CLASS_TELPORTKNOCK
TElPortKnock* TElSimpleFTPSClient::get_PortKnock()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSClient_get_PortKnock(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PortKnock)
		this->_Inst_PortKnock = new TElPortKnock(hOutResult, ohFalse);
	else
		this->_Inst_PortKnock->updateHandle(hOutResult);
	return this->_Inst_PortKnock;
}

SB_INLINE void TElSimpleFTPSClient::set_PortKnock(TElPortKnock &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_PortKnock(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::set_PortKnock(TElPortKnock *Value)
{
	SBCheckError(TElSimpleFTPSClient_set_PortKnock(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPORTKNOCK */

SB_INLINE int32_t TElSimpleFTPSClient::get_TransferKeepAliveInterval()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_TransferKeepAliveInterval(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSClient::set_TransferKeepAliveInterval(int32_t Value)
{
	SBCheckError(TElSimpleFTPSClient_set_TransferKeepAliveInterval(_Handle, Value));
}

SB_INLINE int32_t TElSimpleFTPSClient::get_ListenTimeout()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_ListenTimeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSClient::set_ListenTimeout(int32_t Value)
{
	SBCheckError(TElSimpleFTPSClient_set_ListenTimeout(_Handle, Value));
}

bool TElSimpleFTPSClient::get_UseSIZECmd()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_UseSIZECmd(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSClient::set_UseSIZECmd(bool Value)
{
	SBCheckError(TElSimpleFTPSClient_set_UseSIZECmd(_Handle, (int8_t)Value));
}

bool TElSimpleFTPSClient::get_UseFEATCmd()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_UseFEATCmd(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSClient::set_UseFEATCmd(bool Value)
{
	SBCheckError(TElSimpleFTPSClient_set_UseFEATCmd(_Handle, (int8_t)Value));
}

bool TElSimpleFTPSClient::get_AdjustPasvAddress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_AdjustPasvAddress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSClient::set_AdjustPasvAddress(bool Value)
{
	SBCheckError(TElSimpleFTPSClient_set_AdjustPasvAddress(_Handle, (int8_t)Value));
}

bool TElSimpleFTPSClient::get_UseSSLSessionResumption()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_UseSSLSessionResumption(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSClient::set_UseSSLSessionResumption(bool Value)
{
	SBCheckError(TElSimpleFTPSClient_set_UseSSLSessionResumption(_Handle, (int8_t)Value));
}

TSBRenegotiationAttackPreventionMode TElSimpleFTPSClient::get_RenegotiationAttackPreventionMode()
{
	TSBRenegotiationAttackPreventionModeRaw OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_RenegotiationAttackPreventionMode(_Handle, &OutResultRaw));
	return (TSBRenegotiationAttackPreventionMode)OutResultRaw;
}

SB_INLINE void TElSimpleFTPSClient::set_RenegotiationAttackPreventionMode(TSBRenegotiationAttackPreventionMode Value)
{
	SBCheckError(TElSimpleFTPSClient_set_RenegotiationAttackPreventionMode(_Handle, (TSBRenegotiationAttackPreventionModeRaw)Value));
}

SB_INLINE int32_t TElSimpleFTPSClient::get_IncomingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_IncomingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSClient::set_IncomingSpeedLimit(int32_t Value)
{
	SBCheckError(TElSimpleFTPSClient_set_IncomingSpeedLimit(_Handle, Value));
}

SB_INLINE int32_t TElSimpleFTPSClient::get_OutgoingSpeedLimit()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_OutgoingSpeedLimit(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSClient::set_OutgoingSpeedLimit(int32_t Value)
{
	SBCheckError(TElSimpleFTPSClient_set_OutgoingSpeedLimit(_Handle, Value));
}

SB_INLINE int32_t TElSimpleFTPSClient::get_ConcurrentConnections()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_ConcurrentConnections(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSClient::set_ConcurrentConnections(int32_t Value)
{
	SBCheckError(TElSimpleFTPSClient_set_ConcurrentConnections(_Handle, Value));
}

SB_INLINE int64_t TElSimpleFTPSClient::get_MinSizeForConcurrentDownload()
{
	int64_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_MinSizeForConcurrentDownload(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSClient::set_MinSizeForConcurrentDownload(int64_t Value)
{
	SBCheckError(TElSimpleFTPSClient_set_MinSizeForConcurrentDownload(_Handle, Value));
}

TSBFTPOptions TElSimpleFTPSClient::get_Options()
{
	TSBFTPOptionsRaw OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_Options(_Handle, &OutResultRaw));
	return (TSBFTPOptions)OutResultRaw;
}

SB_INLINE void TElSimpleFTPSClient::set_Options(TSBFTPOptions Value)
{
	SBCheckError(TElSimpleFTPSClient_set_Options(_Handle, (TSBFTPOptionsRaw)Value));
}

TSBSSLOptions TElSimpleFTPSClient::get_SSLOptions()
{
	TSBSSLOptionsRaw OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_SSLOptions(_Handle, &OutResultRaw));
	return (TSBSSLOptions)OutResultRaw;
}

SB_INLINE void TElSimpleFTPSClient::set_SSLOptions(TSBSSLOptions Value)
{
	SBCheckError(TElSimpleFTPSClient_set_SSLOptions(_Handle, (TSBSSLOptionsRaw)Value));
}

TSBParamQuoteMode TElSimpleFTPSClient::get_QuoteParameters()
{
	TSBParamQuoteModeRaw OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_QuoteParameters(_Handle, &OutResultRaw));
	return (TSBParamQuoteMode)OutResultRaw;
}

SB_INLINE void TElSimpleFTPSClient::set_QuoteParameters(TSBParamQuoteMode Value)
{
	SBCheckError(TElSimpleFTPSClient_set_QuoteParameters(_Handle, (TSBParamQuoteModeRaw)Value));
}

SB_INLINE char TElSimpleFTPSClient::get_QuoteParamChar()
{
	char OutResult;
	SBCheckError(TElSimpleFTPSClient_get_QuoteParamChar(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSClient::set_QuoteParamChar(char Value)
{
	SBCheckError(TElSimpleFTPSClient_set_QuoteParamChar(_Handle, Value));
}

TElSocksAuthentication TElSimpleFTPSClient::get_SocksAuthentication()
{
	TElSocksAuthenticationRaw OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_SocksAuthentication(_Handle, &OutResultRaw));
	return (TElSocksAuthentication)OutResultRaw;
}

SB_INLINE void TElSimpleFTPSClient::set_SocksAuthentication(TElSocksAuthentication Value)
{
	SBCheckError(TElSimpleFTPSClient_set_SocksAuthentication(_Handle, (TElSocksAuthenticationRaw)Value));
}

void TElSimpleFTPSClient::get_SocksPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_get_SocksPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1217547012, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSClient::set_SocksPassword(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_SocksPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSimpleFTPSClient::get_SocksPort()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_SocksPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSClient::set_SocksPort(int32_t Value)
{
	SBCheckError(TElSimpleFTPSClient_set_SocksPort(_Handle, Value));
}

bool TElSimpleFTPSClient::get_SocksResolveAddress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_SocksResolveAddress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSClient::set_SocksResolveAddress(bool Value)
{
	SBCheckError(TElSimpleFTPSClient_set_SocksResolveAddress(_Handle, (int8_t)Value));
}

void TElSimpleFTPSClient::get_SocksServer(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_get_SocksServer(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1000661523, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSClient::set_SocksServer(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_SocksServer(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleFTPSClient::get_SocksUserCode(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_get_SocksUserCode(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(202041862, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSClient::set_SocksUserCode(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_SocksUserCode(_Handle, Value.data(), (int32_t)Value.length()));
}

TElSocksVersion TElSimpleFTPSClient::get_SocksVersion()
{
	TElSocksVersionRaw OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_SocksVersion(_Handle, &OutResultRaw));
	return (TElSocksVersion)OutResultRaw;
}

SB_INLINE void TElSimpleFTPSClient::set_SocksVersion(TElSocksVersion Value)
{
	SBCheckError(TElSimpleFTPSClient_set_SocksVersion(_Handle, (TElSocksVersionRaw)Value));
}

#ifdef SB_WINDOWS
bool TElSimpleFTPSClient::get_SocksUseIPv6()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_SocksUseIPv6(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSClient::set_SocksUseIPv6(bool Value)
{
	SBCheckError(TElSimpleFTPSClient_set_SocksUseIPv6(_Handle, (int8_t)Value));
}
#endif

bool TElSimpleFTPSClient::get_UseSocks()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_UseSocks(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSClient::set_UseSocks(bool Value)
{
	SBCheckError(TElSimpleFTPSClient_set_UseSocks(_Handle, (int8_t)Value));
}

bool TElSimpleFTPSClient::get_UseWebTunneling()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_UseWebTunneling(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSClient::set_UseWebTunneling(bool Value)
{
	SBCheckError(TElSimpleFTPSClient_set_UseWebTunneling(_Handle, (int8_t)Value));
}

void TElSimpleFTPSClient::get_WebTunnelAddress(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_get_WebTunnelAddress(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1569543306, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSClient::set_WebTunnelAddress(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_WebTunnelAddress(_Handle, Value.data(), (int32_t)Value.length()));
}

TElWebTunnelAuthentication TElSimpleFTPSClient::get_WebTunnelAuthentication()
{
	TElWebTunnelAuthenticationRaw OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_WebTunnelAuthentication(_Handle, &OutResultRaw));
	return (TElWebTunnelAuthentication)OutResultRaw;
}

SB_INLINE void TElSimpleFTPSClient::set_WebTunnelAuthentication(TElWebTunnelAuthentication Value)
{
	SBCheckError(TElSimpleFTPSClient_set_WebTunnelAuthentication(_Handle, (TElWebTunnelAuthenticationRaw)Value));
}

void TElSimpleFTPSClient::get_WebTunnelPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_get_WebTunnelPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-994643421, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSClient::set_WebTunnelPassword(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_WebTunnelPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElSimpleFTPSClient::get_WebTunnelPort()
{
	int32_t OutResult;
	SBCheckError(TElSimpleFTPSClient_get_WebTunnelPort(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSimpleFTPSClient::set_WebTunnelPort(int32_t Value)
{
	SBCheckError(TElSimpleFTPSClient_set_WebTunnelPort(_Handle, Value));
}

void TElSimpleFTPSClient::get_WebTunnelUserId(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_get_WebTunnelUserId(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1560512067, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSClient::set_WebTunnelUserId(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_WebTunnelUserId(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSimpleFTPSClient::get_WebTunnelRequestHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSClient_get_WebTunnelRequestHeaders(_Handle, &hOutResult));
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
TElStringList* TElSimpleFTPSClient::get_WebTunnelRequestHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSClient_get_WebTunnelRequestHeaders(_Handle, &hOutResult));
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
TStringList* TElSimpleFTPSClient::get_WebTunnelResponseHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSClient_get_WebTunnelResponseHeaders(_Handle, &hOutResult));
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
TElStringList* TElSimpleFTPSClient::get_WebTunnelResponseHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSClient_get_WebTunnelResponseHeaders(_Handle, &hOutResult));
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

void TElSimpleFTPSClient::get_WebTunnelResponseBody(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_get_WebTunnelResponseBody(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-352986738, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElSimpleFTPSClient::get_UseProxySettingsForDataChannel()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_UseProxySettingsForDataChannel(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSClient::set_UseProxySettingsForDataChannel(bool Value)
{
	SBCheckError(TElSimpleFTPSClient_set_UseProxySettingsForDataChannel(_Handle, (int8_t)Value));
}

bool TElSimpleFTPSClient::get_PreserveExistingFileTimes()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_PreserveExistingFileTimes(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSClient::set_PreserveExistingFileTimes(bool Value)
{
	SBCheckError(TElSimpleFTPSClient_set_PreserveExistingFileTimes(_Handle, (int8_t)Value));
}

bool TElSimpleFTPSClient::get_CopyEmptyDirs()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_CopyEmptyDirs(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSClient::set_CopyEmptyDirs(bool Value)
{
	SBCheckError(TElSimpleFTPSClient_set_CopyEmptyDirs(_Handle, (int8_t)Value));
}

bool TElSimpleFTPSClient::get_DeleteFailedDownloads()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_DeleteFailedDownloads(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSimpleFTPSClient::set_DeleteFailedDownloads(bool Value)
{
	SBCheckError(TElSimpleFTPSClient_set_DeleteFailedDownloads(_Handle, (int8_t)Value));
}

void TElSimpleFTPSClient::get_RemoteCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_get_RemoteCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1675107945, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSClient::set_RemoteCharset(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_RemoteCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSimpleFTPSClient::get_LocalCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSimpleFTPSClient_get_LocalCharset(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1453062872, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSimpleFTPSClient::set_LocalCharset(const std::string &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_LocalCharset(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
TElDNSSettings* TElSimpleFTPSClient::get_DNS()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSimpleFTPSClient_get_DNS(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DNS)
		this->_Inst_DNS = new TElDNSSettings(hOutResult, ohFalse);
	else
		this->_Inst_DNS->updateHandle(hOutResult);
	return this->_Inst_DNS;
}

SB_INLINE void TElSimpleFTPSClient::set_DNS(TElDNSSettings &Value)
{
	SBCheckError(TElSimpleFTPSClient_set_DNS(_Handle, Value.getHandle()));
}

SB_INLINE void TElSimpleFTPSClient::set_DNS(TElDNSSettings *Value)
{
	SBCheckError(TElSimpleFTPSClient_set_DNS(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif

TSBOperationErrorHandling TElSimpleFTPSClient::get_OperationErrorHandling()
{
	TSBOperationErrorHandlingRaw OutResultRaw = 0;
	SBCheckError(TElSimpleFTPSClient_get_OperationErrorHandling(_Handle, &OutResultRaw));
	return (TSBOperationErrorHandling)OutResultRaw;
}

SB_INLINE void TElSimpleFTPSClient::set_OperationErrorHandling(TSBOperationErrorHandling Value)
{
	SBCheckError(TElSimpleFTPSClient_set_OperationErrorHandling(_Handle, (TSBOperationErrorHandlingRaw)Value));
}

SB_INLINE void TElSimpleFTPSClient::get_OnTextDataLine(TSBFTPSTextDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnTextDataLine(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnTextDataLine(TSBFTPSTextDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnTextDataLine(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSClient::get_OnBinaryData(TSBFTPSBinaryDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnBinaryData(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnBinaryData(TSBFTPSBinaryDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnBinaryData(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSClient::get_OnCertificateValidate(TSBCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnCertificateValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnCertificateValidate(TSBCertificateValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnCertificateValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSClient::get_OnCertificateNeededEx(TSBCertificateNeededExEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnCertificateNeededEx(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnCertificateNeededEx(TSBCertificateNeededExEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnCertificateNeededEx(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSClient::get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnCiphersNegotiated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnCiphersNegotiated(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSClient::get_OnSSLError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnSSLError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnSSLError(TSBErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnSSLError(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSClient::get_OnCertificateStatus(TSBCertificateStatusEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnCertificateStatus(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnCertificateStatus(TSBCertificateStatusEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnCertificateStatus(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSClient::get_OnExtensionsReceived(TSBExtensionsReceivedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnExtensionsReceived(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnExtensionsReceived(TSBExtensionsReceivedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnExtensionsReceived(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSClient::get_OnExtensionsPrepared(TSBExtensionsPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnExtensionsPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnExtensionsPrepared(TSBExtensionsPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnExtensionsPrepared(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSClient::get_OnKeyNeeded(TSBClientKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnKeyNeeded(TSBClientKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSClient::get_OnRenegotiationRequest(TSBFTPSRenegotiationRequestEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnRenegotiationRequest(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnRenegotiationRequest(TSBFTPSRenegotiationRequestEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnRenegotiationRequest(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSClient::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSClient::get_OnControlSend(TSBFTPSTextDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnControlSend(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnControlSend(TSBFTPSTextDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnControlSend(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSClient::get_OnControlReceive(TSBFTPSTextDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnControlReceive(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnControlReceive(TSBFTPSTextDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnControlReceive(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSClient::get_OnInnerClientCreated(TSBFTPSInnerClientEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnInnerClientCreated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnInnerClientCreated(TSBFTPSInnerClientEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnInnerClientCreated(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSClient::get_OnInnerClientLoggedIn(TSBFTPSInnerClientEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnInnerClientLoggedIn(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnInnerClientLoggedIn(TSBFTPSInnerClientEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnInnerClientLoggedIn(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSClient::get_OnInnerClientDestroyed(TSBFTPSInnerClientEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnInnerClientDestroyed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnInnerClientDestroyed(TSBFTPSInnerClientEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnInnerClientDestroyed(_Handle, pMethodValue, pDataValue));
}

#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_INLINE void TElSimpleFTPSClient::get_OnDNSKeyNeeded(TSBDNSKeyNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnDNSKeyNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnDNSKeyNeeded(TSBDNSKeyNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnDNSKeyNeeded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSClient::get_OnDNSKeyValidate(TSBDNSKeyValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnDNSKeyValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnDNSKeyValidate(TSBDNSKeyValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnDNSKeyValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSClient::get_OnDNSResolve(TSBDNSResolveEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnDNSResolve(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnDNSResolve(TSBDNSResolveEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnDNSResolve(_Handle, pMethodValue, pDataValue));
}
#endif

SB_INLINE void TElSimpleFTPSClient::get_OnFileOperation(TElFTPFileOperationEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnFileOperation(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnFileOperation(TElFTPFileOperationEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnFileOperation(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSClient::get_OnFileOperationResult(TElFTPFileOperationResultEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnFileOperationResult(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnFileOperationResult(TElFTPFileOperationResultEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnFileOperationResult(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSimpleFTPSClient::get_OnFileNameChangeNeeded(TSBFTPSFileNameChangeNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSimpleFTPSClient_get_OnFileNameChangeNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSimpleFTPSClient::set_OnFileNameChangeNeeded(TSBFTPSFileNameChangeNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSimpleFTPSClient_set_OnFileNameChangeNeeded(_Handle, pMethodValue, pDataValue));
}

void TElSimpleFTPSClient::initInstances()
{
#ifdef SB_USE_CLASS_TELSOCKET
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELSOCKET
	this->_Inst_DataSocket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
	this->_Inst_SocketSettings = NULL;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_ClientCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELFTPPROXYSETTINGS
	this->_Inst_ProxySettings = NULL;
#endif /* SB_USE_CLASS_TELFTPPROXYSETTINGS */
#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
	this->_Inst_PeerExtensions = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	this->_Inst_CommandSocketBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	this->_Inst_DataSocketBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
#ifdef SB_USE_CLASS_TELPORTKNOCK
	this->_Inst_PortKnock = NULL;
#endif /* SB_USE_CLASS_TELPORTKNOCK */
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
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
	this->_Inst_DNS = NULL;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
}

TElSimpleFTPSClient::TElSimpleFTPSClient(TElSimpleFTPSClientHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElSimpleFTPSClient::TElSimpleFTPSClient(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleFTPSClient_Create(AOwner.getHandle(), &_Handle));
}

TElSimpleFTPSClient::TElSimpleFTPSClient(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSimpleFTPSClient_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSimpleFTPSClient::~TElSimpleFTPSClient()
{
#ifdef SB_USE_CLASS_TELSOCKET
	delete this->_Inst_Socket;
	this->_Inst_Socket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELSOCKET
	delete this->_Inst_DataSocket;
	this->_Inst_DataSocket = NULL;
#endif /* SB_USE_CLASS_TELSOCKET */
#ifdef SB_USE_CLASS_TELSOCKETSETTINGS
	delete this->_Inst_SocketSettings;
	this->_Inst_SocketSettings = NULL;
#endif /* SB_USE_CLASS_TELSOCKETSETTINGS */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_ClientCertStorage;
	this->_Inst_ClientCertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELFTPPROXYSETTINGS
	delete this->_Inst_ProxySettings;
	this->_Inst_ProxySettings = NULL;
#endif /* SB_USE_CLASS_TELFTPPROXYSETTINGS */
#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
	delete this->_Inst_PeerExtensions;
	this->_Inst_PeerExtensions = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	delete this->_Inst_CommandSocketBinding;
	this->_Inst_CommandSocketBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_USE_CLASS_TELCLIENTSOCKETBINDING
	delete this->_Inst_DataSocketBinding;
	this->_Inst_DataSocketBinding = NULL;
#endif /* SB_USE_CLASS_TELCLIENTSOCKETBINDING */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	delete this->_Inst_FileSystemAdapter;
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
#ifdef SB_USE_CLASS_TELPORTKNOCK
	delete this->_Inst_PortKnock;
	this->_Inst_PortKnock = NULL;
#endif /* SB_USE_CLASS_TELPORTKNOCK */
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
#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELDNSSETTINGS
	delete this->_Inst_DNS;
	this->_Inst_DNS = NULL;
#endif /* SB_USE_CLASS_TELDNSSETTINGS */
#endif
}
#endif /* SB_USE_CLASS_TELSIMPLEFTPSCLIENT */

#ifdef SB_USE_CLASS_TELFTPFILEINFO

SB_INLINE void TElFTPFileInfo::Assign(TElFTPFileInfo &Source)
{
	SBCheckError(TElFTPFileInfo_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElFTPFileInfo::Assign(TElFTPFileInfo *Source)
{
	SBCheckError(TElFTPFileInfo_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElFTPFileInfo::Assign(TSBFTPFileInfo &Source)
{
	SBCheckError(TElFTPFileInfo_Assign_1(_Handle, &Source));
}

SB_INLINE int64_t TElFTPFileInfo::get_FileDate()
{
	int64_t OutResult;
	SBCheckError(TElFTPFileInfo_get_FileDate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElFTPFileInfo::set_FileDate(int64_t Value)
{
	SBCheckError(TElFTPFileInfo_set_FileDate(_Handle, Value));
}

TSBFileEntryType TElFTPFileInfo::get_FileType()
{
	TSBFileEntryTypeRaw OutResultRaw = 0;
	SBCheckError(TElFTPFileInfo_get_FileType(_Handle, &OutResultRaw));
	return (TSBFileEntryType)OutResultRaw;
}

SB_INLINE void TElFTPFileInfo::set_FileType(TSBFileEntryType Value)
{
	SBCheckError(TElFTPFileInfo_set_FileType(_Handle, (TSBFileEntryTypeRaw)Value));
}

void TElFTPFileInfo::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElFTPFileInfo_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(435121330, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElFTPFileInfo::set_Name(const std::string &Value)
{
	SBCheckError(TElFTPFileInfo_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElFTPFileInfo::get_Path(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElFTPFileInfo_get_Path(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1285069243, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElFTPFileInfo::set_Path(const std::string &Value)
{
	SBCheckError(TElFTPFileInfo_set_Path(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElFTPFileInfo::get_Size()
{
	int64_t OutResult;
	SBCheckError(TElFTPFileInfo_get_Size(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElFTPFileInfo::set_Size(int64_t Value)
{
	SBCheckError(TElFTPFileInfo_set_Size(_Handle, Value));
}

TSBFileEntryFormat TElFTPFileInfo::get_EntryFormat()
{
	TSBFileEntryFormatRaw OutResultRaw = 0;
	SBCheckError(TElFTPFileInfo_get_EntryFormat(_Handle, &OutResultRaw));
	return (TSBFileEntryFormat)OutResultRaw;
}

SB_INLINE void TElFTPFileInfo::set_EntryFormat(TSBFileEntryFormat Value)
{
	SBCheckError(TElFTPFileInfo_set_EntryFormat(_Handle, (TSBFileEntryFormatRaw)Value));
}

void TElFTPFileInfo::get_RawData(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElFTPFileInfo_get_RawData(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1787556660, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElFTPFileInfo::set_RawData(const std::string &Value)
{
	SBCheckError(TElFTPFileInfo_set_RawData(_Handle, Value.data(), (int32_t)Value.length()));
}

TElFTPFileInfo::TElFTPFileInfo(TElFTPFileInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElFTPFileInfo::TElFTPFileInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFTPFileInfo_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELFTPFILEINFO */

#ifdef SB_USE_CLASS_TELFTPPROXYSETTINGS

SB_INLINE void TElFTPProxySettings::Assign(TPersistent &Source)
{
	SBCheckError(TElFTPProxySettings_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElFTPProxySettings::Assign(TPersistent *Source)
{
	SBCheckError(TElFTPProxySettings_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

void TElFTPProxySettings::get_Host(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElFTPProxySettings_get_Host(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(87488352, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElFTPProxySettings::set_Host(const std::string &Value)
{
	SBCheckError(TElFTPProxySettings_set_Host(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElFTPProxySettings::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElFTPProxySettings_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-584069006, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElFTPProxySettings::set_Password(const std::string &Value)
{
	SBCheckError(TElFTPProxySettings_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElFTPProxySettings::get_Port()
{
	int32_t OutResult;
	SBCheckError(TElFTPProxySettings_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElFTPProxySettings::set_Port(int32_t Value)
{
	SBCheckError(TElFTPProxySettings_set_Port(_Handle, Value));
}

TSBFTPProxyType TElFTPProxySettings::get_ProxyType()
{
	TSBFTPProxyTypeRaw OutResultRaw = 0;
	SBCheckError(TElFTPProxySettings_get_ProxyType(_Handle, &OutResultRaw));
	return (TSBFTPProxyType)OutResultRaw;
}

SB_INLINE void TElFTPProxySettings::set_ProxyType(TSBFTPProxyType Value)
{
	SBCheckError(TElFTPProxySettings_set_ProxyType(_Handle, (TSBFTPProxyTypeRaw)Value));
}

void TElFTPProxySettings::get_Username(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElFTPProxySettings_get_Username(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(280203472, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElFTPProxySettings::set_Username(const std::string &Value)
{
	SBCheckError(TElFTPProxySettings_set_Username(_Handle, Value.data(), (int32_t)Value.length()));
}

TElFTPProxySettings::TElFTPProxySettings(TElFTPProxySettingsHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElFTPProxySettings::TElFTPProxySettings() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFTPProxySettings_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELFTPPROXYSETTINGS */

#ifdef SB_USE_CLASS_TELFTPSTRANSFERMANAGER

SB_INLINE void TElFTPSTransferManager::Execute()
{
	SBCheckError(TElFTPSTransferManager_Execute(_Handle));
}

TElFTPSTransferManager::TElFTPSTransferManager(TElFTPSTransferManagerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASSES_TELSIMPLEFTPSCLIENT_AND_TSTREAM
TElFTPSTransferManager::TElFTPSTransferManager(TElSimpleFTPSClient &Owner, const std::string &Filename, const std::string &Dir, TStream &Stream, int64_t StartPos, int64_t EndPos) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFTPSTransferManager_Create(Owner.getHandle(), Filename.data(), (int32_t)Filename.length(), Dir.data(), (int32_t)Dir.length(), Stream.getHandle(), StartPos, EndPos, &_Handle));
}

TElFTPSTransferManager::TElFTPSTransferManager(TElSimpleFTPSClient *Owner, const std::string &Filename, const std::string &Dir, TStream *Stream, int64_t StartPos, int64_t EndPos) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFTPSTransferManager_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, Filename.data(), (int32_t)Filename.length(), Dir.data(), (int32_t)Dir.length(), (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, StartPos, EndPos, &_Handle));
}
#endif /* SB_USE_CLASSES_TELSIMPLEFTPSCLIENT_AND_TSTREAM */

#endif /* SB_USE_CLASS_TELFTPSTRANSFERMANAGER */

#ifdef SB_USE_CLASS_TELMULTIPARTSTREAMACCESS

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE TStreamHandle TElMultipartStreamAccess::AcquirePart(int64_t StartPos, int64_t Size)
{
	TStreamHandle OutResult;
	SBCheckError(TElMultipartStreamAccess_AcquirePart(_Handle, StartPos, Size, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElMultipartStreamAccess::ReleasePart(TStream &Stream)
{
	SBCheckError(TElMultipartStreamAccess_ReleasePart(_Handle, Stream.getHandle()));
}

SB_INLINE void TElMultipartStreamAccess::ReleasePart(TStream *Stream)
{
	SBCheckError(TElMultipartStreamAccess_ReleasePart(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

TElMultipartStreamAccess::TElMultipartStreamAccess(TElMultipartStreamAccessHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TSTREAM
TElMultipartStreamAccess::TElMultipartStreamAccess(TStream &Stream, int64_t Size) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMultipartStreamAccess_Create(Stream.getHandle(), Size, &_Handle));
}

TElMultipartStreamAccess::TElMultipartStreamAccess(TStream *Stream, int64_t Size) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMultipartStreamAccess_Create((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Size, &_Handle));
}
#endif /* SB_USE_CLASS_TSTREAM */

#endif /* SB_USE_CLASS_TELMULTIPARTSTREAMACCESS */

#ifdef SB_USE_CLASS_TELFTPSTRANSFERCHUNK

SB_INLINE void TElFTPSTransferChunk::Run()
{
	SBCheckError(TElFTPSTransferChunk_Run(_Handle));
}

TElFTPSTransferChunk::TElFTPSTransferChunk(TElFTPSTransferChunkHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASSES_TELMULTIPARTSTREAMACCESS_AND_TELSIMPLEFTPSCLIENT
TElFTPSTransferChunk::TElFTPSTransferChunk(const std::string &Filename, const std::string &Dir, int64_t StartPos, int64_t EndPos, TElSimpleFTPSClient &Client, bool CreateCopy, TElMultipartStreamAccess &StreamAccess) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFTPSTransferChunk_Create(Filename.data(), (int32_t)Filename.length(), Dir.data(), (int32_t)Dir.length(), StartPos, EndPos, Client.getHandle(), (int8_t)CreateCopy, StreamAccess.getHandle(), &_Handle));
}

TElFTPSTransferChunk::TElFTPSTransferChunk(const std::string &Filename, const std::string &Dir, int64_t StartPos, int64_t EndPos, TElSimpleFTPSClient *Client, bool CreateCopy, TElMultipartStreamAccess *StreamAccess) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFTPSTransferChunk_Create(Filename.data(), (int32_t)Filename.length(), Dir.data(), (int32_t)Dir.length(), StartPos, EndPos, (Client != NULL) ? Client->getHandle() : SB_NULL_HANDLE, (int8_t)CreateCopy, (StreamAccess != NULL) ? StreamAccess->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELMULTIPARTSTREAMACCESS_AND_TELSIMPLEFTPSCLIENT */

#endif /* SB_USE_CLASS_TELFTPSTRANSFERCHUNK */

#ifdef SB_USE_CLASS_TELMULTIPARTSTREAMPART

SB_INLINE int32_t TElMultipartStreamPart::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElMultipartStreamPart_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMultipartStreamPart::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElMultipartStreamPart_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElMultipartStreamPart::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElMultipartStreamPart_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElMultipartStreamPart::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElMultipartStreamPart_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

TElMultipartStreamPart::TElMultipartStreamPart(TElMultipartStreamPartHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELMULTIPARTSTREAMACCESS
TElMultipartStreamPart::TElMultipartStreamPart(TElMultipartStreamAccess &Owner, TStream &BaseStream, int64_t BaseSize, int64_t StartPos, int64_t Size) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMultipartStreamPart_Create(Owner.getHandle(), BaseStream.getHandle(), BaseSize, StartPos, Size, &_Handle));
}

TElMultipartStreamPart::TElMultipartStreamPart(TElMultipartStreamAccess *Owner, TStream *BaseStream, int64_t BaseSize, int64_t StartPos, int64_t Size) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElMultipartStreamPart_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, (BaseStream != NULL) ? BaseStream->getHandle() : SB_NULL_HANDLE, BaseSize, StartPos, Size, &_Handle));
}
#endif /* SB_USE_CLASS_TELMULTIPARTSTREAMACCESS */

#endif /* SB_USE_CLASS_TELMULTIPARTSTREAMPART */

};	/* namespace SecureBlackbox */
