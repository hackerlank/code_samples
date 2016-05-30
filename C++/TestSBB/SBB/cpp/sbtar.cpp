#include "sbtar.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELTARREADERLOW

#ifdef SB_USE_CLASS_TSTREAM
bool TElTarReaderLow::ExtractToStream(int32_t Index, TStream &Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarReaderLow_ExtractToStream(_Handle, Index, Stream.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElTarReaderLow::ExtractToStream(int32_t Index, TStream *Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarReaderLow_ExtractToStream(_Handle, Index, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElTarReaderLow::LoadLibrary()
{
	SBCheckError(TElTarReaderLow_LoadLibrary(_Handle));
}

SB_INLINE void TElTarReaderLow::get_Files(int32_t FileIndex, TElFileTarHeaderLow &OutResult)
{
	SBCheckError(TElTarReaderLow_get_Files(_Handle, FileIndex, &OutResult));
}

SB_INLINE int32_t TElTarReaderLow::get_FilesCount()
{
	int32_t OutResult;
	SBCheckError(TElTarReaderLow_get_FilesCount(_Handle, &OutResult));
	return OutResult;
}

TElTarReaderLow::TElTarReaderLow(TElTarReaderLowHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TSTREAM
TElTarReaderLow::TElTarReaderLow(const TStream &TarStream) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTarReaderLow_Create(TarStream.getHandle(), &_Handle));
}

TElTarReaderLow::TElTarReaderLow(const TStream *TarStream) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTarReaderLow_Create((TarStream != NULL) ? TarStream->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TSTREAM */

#endif /* SB_USE_CLASS_TELTARREADERLOW */

#ifdef SB_USE_CLASS_TELTARWRITERLOW

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElTarWriterLow::AddFile(TStream &Stream, const std::string &FileName, int64_t Date, int32_t Mode)
{
	SBCheckError(TElTarWriterLow_AddFile(_Handle, Stream.getHandle(), FileName.data(), (int32_t)FileName.length(), Date, Mode));
}

SB_INLINE void TElTarWriterLow::AddFile(TStream *Stream, const std::string &FileName, int64_t Date, int32_t Mode)
{
	SBCheckError(TElTarWriterLow_AddFile(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, FileName.data(), (int32_t)FileName.length(), Date, Mode));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElTarWriterLow::Flush()
{
	SBCheckError(TElTarWriterLow_Flush(_Handle));
}

SB_INLINE int32_t TElTarWriterLow::get_UID()
{
	int32_t OutResult;
	SBCheckError(TElTarWriterLow_get_UID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTarWriterLow::set_UID(int32_t Value)
{
	SBCheckError(TElTarWriterLow_set_UID(_Handle, Value));
}

SB_INLINE int32_t TElTarWriterLow::get_GID()
{
	int32_t OutResult;
	SBCheckError(TElTarWriterLow_get_GID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTarWriterLow::set_GID(int32_t Value)
{
	SBCheckError(TElTarWriterLow_set_GID(_Handle, Value));
}

TElTarWriterLow::TElTarWriterLow(TElTarWriterLowHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TSTREAM
TElTarWriterLow::TElTarWriterLow(const TStream &TarStream) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTarWriterLow_Create(TarStream.getHandle(), &_Handle));
}

TElTarWriterLow::TElTarWriterLow(const TStream *TarStream) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTarWriterLow_Create((TarStream != NULL) ? TarStream->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TSTREAM */

#endif /* SB_USE_CLASS_TELTARWRITERLOW */

};	/* namespace SecureBlackbox */

