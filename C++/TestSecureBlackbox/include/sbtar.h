#ifndef __INC_SBTAR
#define __INC_SBTAR

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbstrutils.h"
#include "sbstreams.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SErrorCreateTarFile 	"TAR file can\'t be created"
#define SB_SErrorCreateFile 	"File can\'t be created"
#define SB_SErrorOpenFile 	"TAR file can\'t be open"
#define SB_SErrorIndexFile 	"Out of TAR library index"
#define SB_SErrorRepos 	"Out of TAR"
#define SB_SErrorCorrupted 	"Corrupted data"
#define SB_SErrorRead 	"Error while reading file"
#define SB_SErrorWrite 	"Error while writing file"
#define SB_SErrorAttr 	"Error while setting file attributes"
#ifndef SB_TarMagic
#define SB_TarMagic 	"ustar   "
#endif
#define SB_BaseSize 	257
#ifndef SB_UStarSize
#define SB_UStarSize 	88
#endif

typedef TElClassHandle TElTarReaderLowHandle;

typedef TElClassHandle TElTarWriterLowHandle;

#pragma pack(1)
typedef struct 
{
	void * Name;
	void * Mode;
	void * UID;
	void * GID;
	void * Size;
	void * MTime;
	void * CheckSum;
	void * Link;
	void * LinkName;
} TElBaseTarHeaderLow;

#pragma pack(1)
typedef struct 
{
	void * Name;
	int64_t Size;
	double MTime;
	uint8_t Link;
	void * LinkName;
} TElFileTarHeaderLow;

#pragma pack(1)
typedef struct 
{
	void * Magic;
	void * UName;
	void * GName;
	void * DevMajor;
	void * DevMinor;
} TElUStarTarHeaderLow;

#pragma pack(1)
typedef struct 
{
	TElBaseTarHeaderLow Base;
	int8_t HasUStar;
	TElUStarTarHeaderLow UStar;
	int64_t FilePos;
	int64_t FileSize;
} TElTarEntryLow;

#ifdef SB_USE_CLASS_TELTARREADERLOW
SB_IMPORT uint32_t SB_APIENTRY TElTarReaderLow_ExtractToStream(TElTarReaderLowHandle _Handle, int32_t Index, TStreamHandle Stream, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReaderLow_LoadLibrary(TElTarReaderLowHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTarReaderLow_get_Files(TElTarReaderLowHandle _Handle, int32_t FileIndex, TElFileTarHeaderLow * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReaderLow_get_FilesCount(TElTarReaderLowHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReaderLow_Create(const TStreamHandle TarStream, TElTarReaderLowHandle * OutResult);
#endif /* SB_USE_CLASS_TELTARREADERLOW */

#ifdef SB_USE_CLASS_TELTARWRITERLOW
SB_IMPORT uint32_t SB_APIENTRY TElTarWriterLow_AddFile(TElTarWriterLowHandle _Handle, TStreamHandle Stream, const char * pcFileName, int32_t szFileName, int64_t Date, int32_t Mode);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriterLow_Flush(TElTarWriterLowHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriterLow_get_UID(TElTarWriterLowHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriterLow_set_UID(TElTarWriterLowHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriterLow_get_GID(TElTarWriterLowHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriterLow_set_GID(TElTarWriterLowHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriterLow_Create(const TStreamHandle TarStream, TElTarWriterLowHandle * OutResult);
#endif /* SB_USE_CLASS_TELTARWRITERLOW */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElTarReaderLow;
class TElTarWriterLow;

#ifdef SB_USE_CLASS_TELTARREADERLOW
class TElTarReaderLow: public TObject
{
	private:
		SB_DISABLE_COPY(TElTarReaderLow)
	public:
#ifdef SB_USE_CLASS_TSTREAM
		bool ExtractToStream(int32_t Index, TStream &Stream);

		bool ExtractToStream(int32_t Index, TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		void LoadLibrary();

		virtual void get_Files(int32_t FileIndex, TElFileTarHeaderLow &OutResult);

		virtual int32_t get_FilesCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_FilesCount, TElTarReaderLow, FilesCount);

		TElTarReaderLow(TElTarReaderLowHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TSTREAM
		explicit TElTarReaderLow(const TStream &TarStream);

		explicit TElTarReaderLow(const TStream *TarStream);
#endif /* SB_USE_CLASS_TSTREAM */

};
#endif /* SB_USE_CLASS_TELTARREADERLOW */

#ifdef SB_USE_CLASS_TELTARWRITERLOW
class TElTarWriterLow: public TObject
{
	private:
		SB_DISABLE_COPY(TElTarWriterLow)
	public:
#ifdef SB_USE_CLASS_TSTREAM
		void AddFile(TStream &Stream, const std::string &FileName, int64_t Date, int32_t Mode);

		void AddFile(TStream *Stream, const std::string &FileName, int64_t Date, int32_t Mode);
#endif /* SB_USE_CLASS_TSTREAM */

		void Flush();

		virtual int32_t get_UID();

		virtual void set_UID(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_UID, set_UID, TElTarWriterLow, UID);

		virtual int32_t get_GID();

		virtual void set_GID(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_GID, set_GID, TElTarWriterLow, GID);

		TElTarWriterLow(TElTarWriterLowHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TSTREAM
		explicit TElTarWriterLow(const TStream &TarStream);

		explicit TElTarWriterLow(const TStream *TarStream);
#endif /* SB_USE_CLASS_TSTREAM */

};
#endif /* SB_USE_CLASS_TELTARWRITERLOW */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBTAR */

