#ifndef __INC_SBTARUTILS
#define __INC_SBTARUTILS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbstrutils.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SInvalidClassOwner 	"Invalid class owner"
#define SB_SInvalidTypeCast 	"Invalid type cast"
#ifndef SB_SInternalError
#define SB_SInternalError 	"Internal error"
#endif
#define SB_SInvalidHeaderSize 	"Invalid size of tar header"
#ifndef SB_SInvalidHeader
#define SB_SInvalidHeader 	"Invalid tar header"
#endif
#define SB_SInvalidCheckSum 	"Invalid tar checksum"
#define SB_SInvalidUStarSize 	"Invalid size of UStar"
#define SB_SInvalidParameter 	"Invalid parameter"
#define SB_SInvalidFileData 	"Invalid file data"
#define SB_SInvalidFileDataOffset 	"Invalid file data position"
#define SB_SInvalidPath 	"Invalid path"
#define SB_SInvalidMethodSequence 	"Invalid method sequence"
#define SB_SArchiveNotOpened 	"Archive is not opened"
#define SB_SArchiveNotAssign 	"For the new archive must be specified file or stream"
#define SB_SFileAlreadyExists 	"File already exists"
#define SB_SDirectoryAlreadyExists 	"Directory already exists"
#define SB_SCannotCreateFile 	"Cannot create file"
#define SB_SInvalidActionRequested 	"Invalid action requested"
#define SB_SNoOutputStream 	"No output stream"
#define SB_SCRCMismatch 	"CRC mismatch"
#define SB_SParentIsNotDirectory 	"Parent is not a directory"
#define SB_SFileAlreadyInArchive 	"File is already in archive"
#define SB_SErrorWriteStream 	"Error write to stream"
#define SB_SNoInputForCompression 	"No input for compression"
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
#define SB_TarMagic 	"ustar  \x00"
#endif
#define SB_HeaderSize 	512
#define SB_BaseSize 	257
#ifndef SB_UStarSize
#define SB_UStarSize 	243
#endif
#define SB_TAR_BUFFER_SIZE 	10240

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_TARUTILS

int64_t Oct2Dec(const std::string &Oct);

void Dec2Oct(int64_t Dec, int32_t Len, std::string &OutResult);

void TruncArray(const std::vector<uint8_t> &B, std::vector<uint8_t> &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_TARUTILS */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_TARUTILS
SB_IMPORT uint32_t SB_APIENTRY SBTarUtils_Oct2Dec(const char * pcOct, int32_t szOct, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBTarUtils_Dec2Oct(int64_t Dec, int32_t Len, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBTarUtils_TruncArray(const uint8_t pB[], int32_t szB, uint8_t pOutResult[], int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_TARUTILS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBTARUTILS */

