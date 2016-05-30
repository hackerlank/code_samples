#include "sbpgp.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPGPWRITER

SB_INLINE void TElPGPWriter::EncryptFile(const std::string &ASourceFile, const std::string &ADestFile)
{
	SBCheckError(TElPGPWriter_EncryptFile(_Handle, ASourceFile.data(), (int32_t)ASourceFile.length(), ADestFile.data(), (int32_t)ADestFile.length()));
}

SB_INLINE void TElPGPWriter::SignFile(const std::string &ASourceFile, const std::string &ADestFile, bool Detached)
{
	SBCheckError(TElPGPWriter_SignFile(_Handle, ASourceFile.data(), (int32_t)ASourceFile.length(), ADestFile.data(), (int32_t)ADestFile.length(), (int8_t)Detached));
}

SB_INLINE void TElPGPWriter::EncryptAndSignFile(const std::string &ASourceFile, const std::string &ADestFile)
{
	SBCheckError(TElPGPWriter_EncryptAndSignFile(_Handle, ASourceFile.data(), (int32_t)ASourceFile.length(), ADestFile.data(), (int32_t)ADestFile.length()));
}

SB_INLINE void TElPGPWriter::ClearTextSignFile(const std::string &ASourceFile, const std::string &ADestFile)
{
	SBCheckError(TElPGPWriter_ClearTextSignFile(_Handle, ASourceFile.data(), (int32_t)ASourceFile.length(), ADestFile.data(), (int32_t)ADestFile.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPWriter::Encrypt(TStream &ASourceStream, TStream &ADestStream, int64_t Count)
{
	SBCheckError(TElPGPWriter_Encrypt(_Handle, ASourceStream.getHandle(), ADestStream.getHandle(), Count));
}

SB_INLINE void TElPGPWriter::Encrypt(TStream *ASourceStream, TStream *ADestStream, int64_t Count)
{
	SBCheckError(TElPGPWriter_Encrypt(_Handle, (ASourceStream != NULL) ? ASourceStream->getHandle() : SB_NULL_HANDLE, (ADestStream != NULL) ? ADestStream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPWriter::Sign(TStream &ASourceStream, TStream &ADestStream, bool Detached, int64_t Count)
{
	SBCheckError(TElPGPWriter_Sign(_Handle, ASourceStream.getHandle(), ADestStream.getHandle(), (int8_t)Detached, Count));
}

SB_INLINE void TElPGPWriter::Sign(TStream *ASourceStream, TStream *ADestStream, bool Detached, int64_t Count)
{
	SBCheckError(TElPGPWriter_Sign(_Handle, (ASourceStream != NULL) ? ASourceStream->getHandle() : SB_NULL_HANDLE, (ADestStream != NULL) ? ADestStream->getHandle() : SB_NULL_HANDLE, (int8_t)Detached, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPWriter::EncryptAndSign(TStream &ASourceStream, TStream &ADestStream, int64_t Count)
{
	SBCheckError(TElPGPWriter_EncryptAndSign(_Handle, ASourceStream.getHandle(), ADestStream.getHandle(), Count));
}

SB_INLINE void TElPGPWriter::EncryptAndSign(TStream *ASourceStream, TStream *ADestStream, int64_t Count)
{
	SBCheckError(TElPGPWriter_EncryptAndSign(_Handle, (ASourceStream != NULL) ? ASourceStream->getHandle() : SB_NULL_HANDLE, (ADestStream != NULL) ? ADestStream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPWriter::ClearTextSign(TStream &ASourceStream, TStream &ADestStream, int64_t Count)
{
	SBCheckError(TElPGPWriter_ClearTextSign(_Handle, ASourceStream.getHandle(), ADestStream.getHandle(), Count));
}

SB_INLINE void TElPGPWriter::ClearTextSign(TStream *ASourceStream, TStream *ADestStream, int64_t Count)
{
	SBCheckError(TElPGPWriter_ClearTextSign(_Handle, (ASourceStream != NULL) ? ASourceStream->getHandle() : SB_NULL_HANDLE, (ADestStream != NULL) ? ADestStream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TLIST_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElPGPWriter::EncryptFiles(TStringList &SourceFileNames, TList &SourceStreams, const std::string &ADestFileName, TStream &ADestStream)
{
	SBCheckError(TElPGPWriter_EncryptFiles(_Handle, SourceFileNames.getHandle(), SourceStreams.getHandle(), ADestFileName.data(), (int32_t)ADestFileName.length(), ADestStream.getHandle()));
}

SB_INLINE void TElPGPWriter::EncryptFiles(TStringList *SourceFileNames, TList *SourceStreams, const std::string &ADestFileName, TStream *ADestStream)
{
	SBCheckError(TElPGPWriter_EncryptFiles(_Handle, (SourceFileNames != NULL) ? SourceFileNames->getHandle() : SB_NULL_HANDLE, (SourceStreams != NULL) ? SourceStreams->getHandle() : SB_NULL_HANDLE, ADestFileName.data(), (int32_t)ADestFileName.length(), (ADestStream != NULL) ? ADestStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TLIST_AND_TSTREAM_AND_TSTRINGLIST */

#ifdef SB_USE_CLASSES_TLIST_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElPGPWriter::SignFiles(TStringList &SourceFileNames, TList &SourceStreams, const std::string &ADestFileName, TStream &ADestStream)
{
	SBCheckError(TElPGPWriter_SignFiles(_Handle, SourceFileNames.getHandle(), SourceStreams.getHandle(), ADestFileName.data(), (int32_t)ADestFileName.length(), ADestStream.getHandle()));
}

SB_INLINE void TElPGPWriter::SignFiles(TStringList *SourceFileNames, TList *SourceStreams, const std::string &ADestFileName, TStream *ADestStream)
{
	SBCheckError(TElPGPWriter_SignFiles(_Handle, (SourceFileNames != NULL) ? SourceFileNames->getHandle() : SB_NULL_HANDLE, (SourceStreams != NULL) ? SourceStreams->getHandle() : SB_NULL_HANDLE, ADestFileName.data(), (int32_t)ADestFileName.length(), (ADestStream != NULL) ? ADestStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TLIST_AND_TSTREAM_AND_TSTRINGLIST */

#ifdef SB_USE_CLASSES_TLIST_AND_TSTREAM_AND_TSTRINGLIST
SB_INLINE void TElPGPWriter::EncryptAndSignFiles(TStringList &SourceFileNames, TList &SourceStreams, const std::string &ADestFileName, TStream &ADestStream)
{
	SBCheckError(TElPGPWriter_EncryptAndSignFiles(_Handle, SourceFileNames.getHandle(), SourceStreams.getHandle(), ADestFileName.data(), (int32_t)ADestFileName.length(), ADestStream.getHandle()));
}

SB_INLINE void TElPGPWriter::EncryptAndSignFiles(TStringList *SourceFileNames, TList *SourceStreams, const std::string &ADestFileName, TStream *ADestStream)
{
	SBCheckError(TElPGPWriter_EncryptAndSignFiles(_Handle, (SourceFileNames != NULL) ? SourceFileNames->getHandle() : SB_NULL_HANDLE, (SourceStreams != NULL) ? SourceStreams->getHandle() : SB_NULL_HANDLE, ADestFileName.data(), (int32_t)ADestFileName.length(), (ADestStream != NULL) ? ADestStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TLIST_AND_TSTREAM_AND_TSTRINGLIST */

SB_INLINE int64_t TElPGPWriter::get_Timestamp()
{
	int64_t OutResult;
	SBCheckError(TElPGPWriter_get_Timestamp(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPWriter::set_Timestamp(int64_t Value)
{
	SBCheckError(TElPGPWriter_set_Timestamp(_Handle, Value));
}

bool TElPGPWriter::get_Armor()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPWriter_get_Armor(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPWriter::set_Armor(bool Value)
{
	SBCheckError(TElPGPWriter_set_Armor(_Handle, (int8_t)Value));
}

TSBPGPEncryptionType TElPGPWriter::get_EncryptionType()
{
	TSBPGPEncryptionTypeRaw OutResultRaw = 0;
	SBCheckError(TElPGPWriter_get_EncryptionType(_Handle, &OutResultRaw));
	return (TSBPGPEncryptionType)OutResultRaw;
}

SB_INLINE void TElPGPWriter::set_EncryptionType(TSBPGPEncryptionType Value)
{
	SBCheckError(TElPGPWriter_set_EncryptionType(_Handle, (TSBPGPEncryptionTypeRaw)Value));
}

bool TElPGPWriter::get_Compress()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPWriter_get_Compress(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPWriter::set_Compress(bool Value)
{
	SBCheckError(TElPGPWriter_set_Compress(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElPGPWriter::get_CompressionAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPWriter_get_CompressionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPWriter::set_CompressionAlgorithm(int32_t Value)
{
	SBCheckError(TElPGPWriter_set_CompressionAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElPGPWriter::get_CompressionLevel()
{
	int32_t OutResult;
	SBCheckError(TElPGPWriter_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPWriter::set_CompressionLevel(int32_t Value)
{
	SBCheckError(TElPGPWriter_set_CompressionLevel(_Handle, Value));
}

void TElPGPWriter::get_ArmorBoundary(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPWriter_get_ArmorBoundary(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-652794616, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPWriter::set_ArmorBoundary(const std::string &Value)
{
	SBCheckError(TElPGPWriter_set_ArmorBoundary(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPGPWriter::get_ArmorHeaders()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPWriter_get_ArmorHeaders(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ArmorHeaders)
		this->_Inst_ArmorHeaders = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_ArmorHeaders->updateHandle(hOutResult);
	return this->_Inst_ArmorHeaders;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

void TElPGPWriter::get_Filename(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPWriter_get_Filename(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1791732051, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPWriter::set_Filename(const std::string &Value)
{
	SBCheckError(TElPGPWriter_set_Filename(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELPGPKEYRING
TElPGPKeyring* TElPGPWriter::get_SigningKeys()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPWriter_get_SigningKeys(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SigningKeys)
		this->_Inst_SigningKeys = new TElPGPKeyring(hOutResult, ohFalse);
	else
		this->_Inst_SigningKeys->updateHandle(hOutResult);
	return this->_Inst_SigningKeys;
}

SB_INLINE void TElPGPWriter::set_SigningKeys(TElPGPKeyring &Value)
{
	SBCheckError(TElPGPWriter_set_SigningKeys(_Handle, Value.getHandle()));
}

SB_INLINE void TElPGPWriter::set_SigningKeys(TElPGPKeyring *Value)
{
	SBCheckError(TElPGPWriter_set_SigningKeys(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TELPGPKEYRING
TElPGPKeyring* TElPGPWriter::get_EncryptingKeys()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPWriter_get_EncryptingKeys(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptingKeys)
		this->_Inst_EncryptingKeys = new TElPGPKeyring(hOutResult, ohFalse);
	else
		this->_Inst_EncryptingKeys->updateHandle(hOutResult);
	return this->_Inst_EncryptingKeys;
}

SB_INLINE void TElPGPWriter::set_EncryptingKeys(TElPGPKeyring &Value)
{
	SBCheckError(TElPGPWriter_set_EncryptingKeys(_Handle, Value.getHandle()));
}

SB_INLINE void TElPGPWriter::set_EncryptingKeys(TElPGPKeyring *Value)
{
	SBCheckError(TElPGPWriter_set_EncryptingKeys(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPKEYRING */

SB_INLINE int32_t TElPGPWriter::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPWriter_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPWriter::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElPGPWriter_set_HashAlgorithm(_Handle, Value));
}

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPGPWriter::get_Passphrases()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPWriter_get_Passphrases(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Passphrases)
		this->_Inst_Passphrases = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Passphrases->updateHandle(hOutResult);
	return this->_Inst_Passphrases;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

TSBPGPProtectionType TElPGPWriter::get_Protection()
{
	TSBPGPProtectionTypeRaw OutResultRaw = 0;
	SBCheckError(TElPGPWriter_get_Protection(_Handle, &OutResultRaw));
	return (TSBPGPProtectionType)OutResultRaw;
}

SB_INLINE void TElPGPWriter::set_Protection(TSBPGPProtectionType Value)
{
	SBCheckError(TElPGPWriter_set_Protection(_Handle, (TSBPGPProtectionTypeRaw)Value));
}

SB_INLINE int32_t TElPGPWriter::get_SymmetricKeyAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPWriter_get_SymmetricKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPWriter::set_SymmetricKeyAlgorithm(int32_t Value)
{
	SBCheckError(TElPGPWriter_set_SymmetricKeyAlgorithm(_Handle, Value));
}

TSBPGPSignBufferingMethod TElPGPWriter::get_SignBufferingMethod()
{
	TSBPGPSignBufferingMethodRaw OutResultRaw = 0;
	SBCheckError(TElPGPWriter_get_SignBufferingMethod(_Handle, &OutResultRaw));
	return (TSBPGPSignBufferingMethod)OutResultRaw;
}

SB_INLINE void TElPGPWriter::set_SignBufferingMethod(TSBPGPSignBufferingMethod Value)
{
	SBCheckError(TElPGPWriter_set_SignBufferingMethod(_Handle, (TSBPGPSignBufferingMethodRaw)Value));
}

bool TElPGPWriter::get_UseOldPackets()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPWriter_get_UseOldPackets(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPWriter::set_UseOldPackets(bool Value)
{
	SBCheckError(TElPGPWriter_set_UseOldPackets(_Handle, (int8_t)Value));
}

bool TElPGPWriter::get_UseNewFeatures()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPWriter_get_UseNewFeatures(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPWriter::set_UseNewFeatures(bool Value)
{
	SBCheckError(TElPGPWriter_set_UseNewFeatures(_Handle, (int8_t)Value));
}

bool TElPGPWriter::get_InputIsText()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPWriter_get_InputIsText(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPWriter::set_InputIsText(bool Value)
{
	SBCheckError(TElPGPWriter_set_InputIsText(_Handle, (int8_t)Value));
}

bool TElPGPWriter::get_TextCompatibilityMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPWriter_get_TextCompatibilityMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPWriter::set_TextCompatibilityMode(bool Value)
{
	SBCheckError(TElPGPWriter_set_TextCompatibilityMode(_Handle, (int8_t)Value));
}

bool TElPGPWriter::get_UndefInputLength()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPWriter_get_UndefInputLength(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPWriter::set_UndefInputLength(bool Value)
{
	SBCheckError(TElPGPWriter_set_UndefInputLength(_Handle, (int8_t)Value));
}

#ifndef SB_WINCE_OR_NOT_WINDOWS
void TElPGPWriter::get_SFXCopyright(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPWriter_get_SFXCopyright(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1261277741, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPWriter::set_SFXCopyright(const std::string &Value)
{
	SBCheckError(TElPGPWriter_set_SFXCopyright(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElPGPWriter::get_SFXEnabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPWriter_get_SFXEnabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPWriter::set_SFXEnabled(bool Value)
{
	SBCheckError(TElPGPWriter_set_SFXEnabled(_Handle, (int8_t)Value));
}

void TElPGPWriter::get_SFXTitle(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPWriter_get_SFXTitle(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(85040249, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPWriter::set_SFXTitle(const std::string &Value)
{
	SBCheckError(TElPGPWriter_set_SFXTitle(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPGPWriter::get_StubName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPWriter_get_StubName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1850887023, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPWriter::set_StubName(const std::string &Value)
{
	SBCheckError(TElPGPWriter_set_StubName(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBPGPStubSource TElPGPWriter::get_StubSource()
{
	TSBPGPStubSourceRaw OutResultRaw = 0;
	SBCheckError(TElPGPWriter_get_StubSource(_Handle, &OutResultRaw));
	return (TSBPGPStubSource)OutResultRaw;
}

SB_INLINE void TElPGPWriter::set_StubSource(TSBPGPStubSource Value)
{
	SBCheckError(TElPGPWriter_set_StubSource(_Handle, (TSBPGPStubSourceRaw)Value));
}
#endif

bool TElPGPWriter::get_PreserveFilePaths()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPWriter_get_PreserveFilePaths(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPWriter::set_PreserveFilePaths(bool Value)
{
	SBCheckError(TElPGPWriter_set_PreserveFilePaths(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
TElCustomFileSystemAdapter* TElPGPWriter::get_FileSystemAdapter()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPWriter_get_FileSystemAdapter(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FileSystemAdapter)
		this->_Inst_FileSystemAdapter = new TElCustomFileSystemAdapter(hOutResult, ohFalse);
	else
		this->_Inst_FileSystemAdapter->updateHandle(hOutResult);
	return this->_Inst_FileSystemAdapter;
}

SB_INLINE void TElPGPWriter::set_FileSystemAdapter(TElCustomFileSystemAdapter &Value)
{
	SBCheckError(TElPGPWriter_set_FileSystemAdapter(_Handle, Value.getHandle()));
}

SB_INLINE void TElPGPWriter::set_FileSystemAdapter(TElCustomFileSystemAdapter *Value)
{
	SBCheckError(TElPGPWriter_set_FileSystemAdapter(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_INLINE void TElPGPWriter::get_OnGetStubStream(TSBPGPGetStubStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPWriter_get_OnGetStubStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPWriter::set_OnGetStubStream(TSBPGPGetStubStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPWriter_set_OnGetStubStream(_Handle, pMethodValue, pDataValue));
}
#endif

SB_INLINE void TElPGPWriter::get_OnKeyPassphrase(TSBPGPKeyPassphraseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPWriter_get_OnKeyPassphrase(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPWriter::set_OnKeyPassphrase(TSBPGPKeyPassphraseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPWriter_set_OnKeyPassphrase(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPWriter::get_OnProgress(TSBPGPProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPWriter_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPWriter::set_OnProgress(TSBPGPProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPWriter_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPWriter::get_OnTemporaryStream(TSBPGPTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPWriter_get_OnTemporaryStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPWriter::set_OnTemporaryStream(TSBPGPTemporaryStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPWriter_set_OnTemporaryStream(_Handle, pMethodValue, pDataValue));
}

void TElPGPWriter::initInstances()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_ArmorHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELPGPKEYRING
	this->_Inst_SigningKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELPGPKEYRING
	this->_Inst_EncryptingKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Passphrases = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
}

TElPGPWriter::TElPGPWriter(TElPGPWriterHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElPGPWriter::TElPGPWriter(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPWriter_Create(AOwner.getHandle(), &_Handle));
}

TElPGPWriter::TElPGPWriter(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPWriter_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElPGPWriter::~TElPGPWriter()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_ArmorHeaders;
	this->_Inst_ArmorHeaders = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELPGPKEYRING
	delete this->_Inst_SigningKeys;
	this->_Inst_SigningKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELPGPKEYRING
	delete this->_Inst_EncryptingKeys;
	this->_Inst_EncryptingKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Passphrases;
	this->_Inst_Passphrases = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	delete this->_Inst_FileSystemAdapter;
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
}
#endif /* SB_USE_CLASS_TELPGPWRITER */

#ifdef SB_USE_CLASS_TELPGPPROCESSINGUNIT

SB_INLINE int32_t TElPGPProcessingUnit::Read(void * Buffer, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElPGPProcessingUnit_Read(_Handle, Buffer, Size, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPProcessingUnit::Write(void * Buffer, int32_t Size)
{
	SBCheckError(TElPGPProcessingUnit_Write(_Handle, Buffer, Size));
}

SB_INLINE void TElPGPProcessingUnit::NFinalize()
{
	SBCheckError(TElPGPProcessingUnit_NFinalize(_Handle));
}

bool TElPGPProcessingUnit::get_Atomic()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPProcessingUnit_get_Atomic(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPProcessingUnit::get_Finished()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPProcessingUnit_get_Finished(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELPGPSTREAM
TElPGPStream* TElPGPProcessingUnit::get_Stream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPProcessingUnit_get_Stream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Stream)
		this->_Inst_Stream = new TElPGPStream(hOutResult, ohFalse);
	else
		this->_Inst_Stream->updateHandle(hOutResult);
	return this->_Inst_Stream;
}
#endif /* SB_USE_CLASS_TELPGPSTREAM */

TElPGPProcessingUnit* TElPGPProcessingUnit::get_Prev()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPProcessingUnit_get_Prev(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Prev)
		this->_Inst_Prev = new TElPGPProcessingUnit(hOutResult, ohFalse);
	else
		this->_Inst_Prev->updateHandle(hOutResult);
	return this->_Inst_Prev;
}

SB_INLINE int64_t TElPGPProcessingUnit::get_SkippedLength()
{
	int64_t OutResult;
	SBCheckError(TElPGPProcessingUnit_get_SkippedLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElPGPProcessingUnit::get_ProcessedLength()
{
	int64_t OutResult;
	SBCheckError(TElPGPProcessingUnit_get_ProcessedLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPProcessingUnit::get_InputEncoding()
{
	int32_t OutResult;
	SBCheckError(TElPGPProcessingUnit_get_InputEncoding(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPProcessingUnit::set_InputEncoding(int32_t Value)
{
	SBCheckError(TElPGPProcessingUnit_set_InputEncoding(_Handle, Value));
}

bool TElPGPProcessingUnit::get_IgnoreDataPacketLengths()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPProcessingUnit_get_IgnoreDataPacketLengths(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPProcessingUnit::set_IgnoreDataPacketLengths(bool Value)
{
	SBCheckError(TElPGPProcessingUnit_set_IgnoreDataPacketLengths(_Handle, (int8_t)Value));
}

SB_INLINE void TElPGPProcessingUnit::get_OnNewStream(TSBPGPNewStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPProcessingUnit_get_OnNewStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPProcessingUnit::set_OnNewStream(TSBPGPNewStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPProcessingUnit_set_OnNewStream(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPProcessingUnit::get_OnFinish(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPProcessingUnit_get_OnFinish(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPProcessingUnit::set_OnFinish(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPProcessingUnit_set_OnFinish(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPProcessingUnit::get_OnSignature(TSBPGPSignatureEntityEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPProcessingUnit_get_OnSignature(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPProcessingUnit::set_OnSignature(TSBPGPSignatureEntityEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPProcessingUnit_set_OnSignature(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPProcessingUnit::get_OnHashAlgorithm(TSBPGPHashAlgorithmEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPProcessingUnit_get_OnHashAlgorithm(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPProcessingUnit::set_OnHashAlgorithm(TSBPGPHashAlgorithmEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPProcessingUnit_set_OnHashAlgorithm(_Handle, pMethodValue, pDataValue));
}

void TElPGPProcessingUnit::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPSTREAM
	this->_Inst_Stream = NULL;
#endif /* SB_USE_CLASS_TELPGPSTREAM */
	this->_Inst_Prev = NULL;
}

TElPGPProcessingUnit::TElPGPProcessingUnit(TElPGPProcessingUnitHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPGPProcessingUnit::TElPGPProcessingUnit() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPProcessingUnit_Create(&_Handle));
}

TElPGPProcessingUnit::~TElPGPProcessingUnit()
{
#ifdef SB_USE_CLASS_TELPGPSTREAM
	delete this->_Inst_Stream;
	this->_Inst_Stream = NULL;
#endif /* SB_USE_CLASS_TELPGPSTREAM */
	delete this->_Inst_Prev;
	this->_Inst_Prev = NULL;
}
#endif /* SB_USE_CLASS_TELPGPPROCESSINGUNIT */

#ifdef SB_USE_CLASS_TELPGPREADER

SB_INLINE void TElPGPReader::DecryptAndVerifyFile(const std::string &ASourceFile)
{
	SBCheckError(TElPGPReader_DecryptAndVerifyFile(_Handle, ASourceFile.data(), (int32_t)ASourceFile.length()));
}

SB_INLINE void TElPGPReader::VerifyDetachedFile(const std::string &ASourceFile, const std::string &ASignatureFile)
{
	SBCheckError(TElPGPReader_VerifyDetachedFile(_Handle, ASourceFile.data(), (int32_t)ASourceFile.length(), ASignatureFile.data(), (int32_t)ASignatureFile.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPReader::DecryptAndVerify(TStream &ASourceStream, int64_t Count)
{
	SBCheckError(TElPGPReader_DecryptAndVerify(_Handle, ASourceStream.getHandle(), Count));
}

SB_INLINE void TElPGPReader::DecryptAndVerify(TStream *ASourceStream, int64_t Count)
{
	SBCheckError(TElPGPReader_DecryptAndVerify(_Handle, (ASourceStream != NULL) ? ASourceStream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPReader::VerifyDetached(TStream &ASourceStream, TStream &ASignatureStream, int64_t SourceStreamCount, int64_t SignatureStreamCount)
{
	SBCheckError(TElPGPReader_VerifyDetached(_Handle, ASourceStream.getHandle(), ASignatureStream.getHandle(), SourceStreamCount, SignatureStreamCount));
}

SB_INLINE void TElPGPReader::VerifyDetached(TStream *ASourceStream, TStream *ASignatureStream, int64_t SourceStreamCount, int64_t SignatureStreamCount)
{
	SBCheckError(TElPGPReader_VerifyDetached(_Handle, (ASourceStream != NULL) ? ASourceStream->getHandle() : SB_NULL_HANDLE, (ASignatureStream != NULL) ? ASignatureStream->getHandle() : SB_NULL_HANDLE, SourceStreamCount, SignatureStreamCount));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElPGPReader::get_EncryptionAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPReader_get_EncryptionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPReader::get_CompressionAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPReader_get_CompressionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

TSBPGPProtectionType TElPGPReader::get_Protection()
{
	TSBPGPProtectionTypeRaw OutResultRaw = 0;
	SBCheckError(TElPGPReader_get_Protection(_Handle, &OutResultRaw));
	return (TSBPGPProtectionType)OutResultRaw;
}

SB_INLINE int64_t TElPGPReader::get_ProcessedLength()
{
	int64_t OutResult;
	SBCheckError(TElPGPReader_get_ProcessedLength(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
TStream* TElPGPReader::get_OutputStream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPReader_get_OutputStream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OutputStream)
		this->_Inst_OutputStream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_OutputStream->updateHandle(hOutResult);
	return this->_Inst_OutputStream;
}

SB_INLINE void TElPGPReader::set_OutputStream(TStream &Value)
{
	SBCheckError(TElPGPReader_set_OutputStream(_Handle, Value.getHandle()));
}

SB_INLINE void TElPGPReader::set_OutputStream(TStream *Value)
{
	SBCheckError(TElPGPReader_set_OutputStream(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELPGPKEYRING
TElPGPKeyring* TElPGPReader::get_DecryptingKeys()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPReader_get_DecryptingKeys(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DecryptingKeys)
		this->_Inst_DecryptingKeys = new TElPGPKeyring(hOutResult, ohFalse);
	else
		this->_Inst_DecryptingKeys->updateHandle(hOutResult);
	return this->_Inst_DecryptingKeys;
}

SB_INLINE void TElPGPReader::set_DecryptingKeys(TElPGPKeyring &Value)
{
	SBCheckError(TElPGPReader_set_DecryptingKeys(_Handle, Value.getHandle()));
}

SB_INLINE void TElPGPReader::set_DecryptingKeys(TElPGPKeyring *Value)
{
	SBCheckError(TElPGPReader_set_DecryptingKeys(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TELPGPKEYRING
TElPGPKeyring* TElPGPReader::get_VerifyingKeys()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPReader_get_VerifyingKeys(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_VerifyingKeys)
		this->_Inst_VerifyingKeys = new TElPGPKeyring(hOutResult, ohFalse);
	else
		this->_Inst_VerifyingKeys->updateHandle(hOutResult);
	return this->_Inst_VerifyingKeys;
}

SB_INLINE void TElPGPReader::set_VerifyingKeys(TElPGPKeyring &Value)
{
	SBCheckError(TElPGPReader_set_VerifyingKeys(_Handle, Value.getHandle()));
}

SB_INLINE void TElPGPReader::set_VerifyingKeys(TElPGPKeyring *Value)
{
	SBCheckError(TElPGPReader_set_VerifyingKeys(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPKEYRING */

void TElPGPReader::get_OutputFile(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPReader_get_OutputFile(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1442046346, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPReader::set_OutputFile(const std::string &Value)
{
	SBCheckError(TElPGPReader_set_OutputFile(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPGPReader::get_Passphrase(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPReader_get_Passphrase(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(9101558, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPReader::set_Passphrase(const std::string &Value)
{
	SBCheckError(TElPGPReader_set_Passphrase(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPGPReader::get_KeyPassphrase(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPReader_get_KeyPassphrase(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1428086172, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPReader::set_KeyPassphrase(const std::string &Value)
{
	SBCheckError(TElPGPReader_set_KeyPassphrase(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBPGPMemoryConsumptionStrategy TElPGPReader::get_MemoryConsumptionStrategy()
{
	TSBPGPMemoryConsumptionStrategyRaw OutResultRaw = 0;
	SBCheckError(TElPGPReader_get_MemoryConsumptionStrategy(_Handle, &OutResultRaw));
	return (TSBPGPMemoryConsumptionStrategy)OutResultRaw;
}

SB_INLINE void TElPGPReader::set_MemoryConsumptionStrategy(TSBPGPMemoryConsumptionStrategy Value)
{
	SBCheckError(TElPGPReader_set_MemoryConsumptionStrategy(_Handle, (TSBPGPMemoryConsumptionStrategyRaw)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
TElCustomFileSystemAdapter* TElPGPReader::get_FileSystemAdapter()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPReader_get_FileSystemAdapter(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FileSystemAdapter)
		this->_Inst_FileSystemAdapter = new TElCustomFileSystemAdapter(hOutResult, ohFalse);
	else
		this->_Inst_FileSystemAdapter->updateHandle(hOutResult);
	return this->_Inst_FileSystemAdapter;
}

SB_INLINE void TElPGPReader::set_FileSystemAdapter(TElCustomFileSystemAdapter &Value)
{
	SBCheckError(TElPGPReader_set_FileSystemAdapter(_Handle, Value.getHandle()));
}

SB_INLINE void TElPGPReader::set_FileSystemAdapter(TElCustomFileSystemAdapter *Value)
{
	SBCheckError(TElPGPReader_set_FileSystemAdapter(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

bool TElPGPReader::get_IgnoreDataPacketLengths()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPReader_get_IgnoreDataPacketLengths(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPReader::set_IgnoreDataPacketLengths(bool Value)
{
	SBCheckError(TElPGPReader_set_IgnoreDataPacketLengths(_Handle, (int8_t)Value));
}

bool TElPGPReader::get_UndefInputLength()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPReader_get_UndefInputLength(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPReader::set_UndefInputLength(bool Value)
{
	SBCheckError(TElPGPReader_set_UndefInputLength(_Handle, (int8_t)Value));
}

SB_INLINE void TElPGPReader::get_OnArmored(TSBPGPArmoredEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPReader_get_OnArmored(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPReader::set_OnArmored(TSBPGPArmoredEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPReader_set_OnArmored(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPReader::get_OnCompressed(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPReader_get_OnCompressed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPReader::set_OnCompressed(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPReader_set_OnCompressed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPReader::get_OnEncrypted(TSBPGPEncryptedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPReader_get_OnEncrypted(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPReader::set_OnEncrypted(TSBPGPEncryptedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPReader_set_OnEncrypted(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPReader::get_OnCreateOutputStream(TSBPGPCreateOutputStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPReader_get_OnCreateOutputStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPReader::set_OnCreateOutputStream(TSBPGPCreateOutputStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPReader_set_OnCreateOutputStream(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPReader::get_OnRequestOutputFile(TSBPGPRequestOutputFileEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPReader_get_OnRequestOutputFile(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPReader::set_OnRequestOutputFile(TSBPGPRequestOutputFileEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPReader_set_OnRequestOutputFile(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPReader::get_OnKeyPassphrase(TSBPGPKeyPassphraseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPReader_get_OnKeyPassphrase(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPReader::set_OnKeyPassphrase(TSBPGPKeyPassphraseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPReader_set_OnKeyPassphrase(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPReader::get_OnPassphrase(TSBPGPPassphraseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPReader_get_OnPassphrase(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPReader::set_OnPassphrase(TSBPGPPassphraseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPReader_set_OnPassphrase(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPReader::get_OnProgress(TSBPGPProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPReader_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPReader::set_OnProgress(TSBPGPProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPReader_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPReader::get_OnSigned(TSBPGPSignedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPReader_get_OnSigned(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPReader::set_OnSigned(TSBPGPSignedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPReader_set_OnSigned(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPReader::get_OnSignatures(TSBPGPSignaturesEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPReader_get_OnSignatures(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPReader::set_OnSignatures(TSBPGPSignaturesEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPReader_set_OnSignatures(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPReader::get_OnFileExtractionStart(TSBPGPFileExtractionStartEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPReader_get_OnFileExtractionStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPReader::set_OnFileExtractionStart(TSBPGPFileExtractionStartEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPReader_set_OnFileExtractionStart(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPReader::get_OnMultipleFilesFound(TSBPGPMultipleFilesFoundEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPReader_get_OnMultipleFilesFound(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPReader::set_OnMultipleFilesFound(TSBPGPMultipleFilesFoundEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPReader_set_OnMultipleFilesFound(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPReader::get_OnTemporaryStream(TSBPGPTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPReader_get_OnTemporaryStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPReader::set_OnTemporaryStream(TSBPGPTemporaryStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPReader_set_OnTemporaryStream(_Handle, pMethodValue, pDataValue));
}

void TElPGPReader::initInstances()
{
#ifdef SB_USE_CLASS_TSTREAM
	this->_Inst_OutputStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TELPGPKEYRING
	this->_Inst_DecryptingKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELPGPKEYRING
	this->_Inst_VerifyingKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
}

TElPGPReader::TElPGPReader(TElPGPReaderHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElPGPReader::TElPGPReader(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPReader_Create(AOwner.getHandle(), &_Handle));
}

TElPGPReader::TElPGPReader(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPReader_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElPGPReader::~TElPGPReader()
{
#ifdef SB_USE_CLASS_TSTREAM
	delete this->_Inst_OutputStream;
	this->_Inst_OutputStream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TELPGPKEYRING
	delete this->_Inst_DecryptingKeys;
	this->_Inst_DecryptingKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELPGPKEYRING
	delete this->_Inst_VerifyingKeys;
	this->_Inst_VerifyingKeys = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	delete this->_Inst_FileSystemAdapter;
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
}
#endif /* SB_USE_CLASS_TELPGPREADER */

};	/* namespace SecureBlackbox */
