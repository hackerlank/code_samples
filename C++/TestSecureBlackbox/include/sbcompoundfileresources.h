#ifndef __INC_SBCOMPOUNDFILERESOURCES
#define __INC_SBCOMPOUNDFILERESOURCES

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SFCFBFailedToReadDIFAT 	"Failed to read DIFAT sector (%d)"
#define SB_SFCFBFailedToWriteDIFAT 	"Failed to write DIFAT sector (%d)"
#define SB_SFCFBFailedToReadFAT 	"Failed to read FAT (%d)"
#define SB_SFCFBFailedToReadFATSector 	"Failed to read FAT sector (%d)"
#define SB_SFCFBFailedToWriteFATSector 	"Failed to write FAT sector (%d)"
#define SB_SFCFBFailedToWriteFAT 	"Failed to write FAT (%d)"
#define SB_SFCFBFailedToReadMiniFAT 	"Failed to read Mini FAT (%d)"
#define SB_SFCFBFailedToReadMiniFATSector 	"Failed to read Mini FAT sector (%d)"
#define SB_SFCFBFailedToWriteMiniFATSector 	"Failed to write Mini FAT sector (%d)"
#define SB_SFCFBFailedToWriteMiniFAT 	"Failed to write Mini FAT (%d)"
#define SB_SFCFBFailedToWriteSector 	"Failed to write sector (%d)"
#define SB_SFCFBFailedToReadDirEntry 	"Failed to read directory entry (%d)"
#define SB_SFCFBFailedToWriteDirEntry 	"Failed to write directory entry (%d)"
#define SB_SFCFBInvalidObjectTypeForDirEntry 	"Invalid object type for the directory entry (%d)"
#define SB_SFCFBSIDExceedsMax 	"SID exceeds maximum limits (%d)"
#define SB_SFCFBSIDAlreadyInUse 	"SID already in use (%d)"
#define SB_SFCFBSectorExceedsMax 	"Sector exceeds maximum limits (%d)"
#define SB_SFCFBCyclicSector 	"Cyclic sector (%d)"
#define SB_SCFBUnsupportedByteOrder 	"Unsupported byte order"
#define SB_SCFBUnsupportedFileVersion 	"Unsupported file version"
#define SB_SCFBInvalidDirEntryName 	"Invalid directory entry name"
#define SB_SCFBDirEntryNameExists 	"A directory entry with this name already exists"
#define SB_SCFBCannotResizeFATStream 	"Cannot allocate sectors for the FAT stream"
#define SB_SCFBFailedToReadHeader 	"Failed to read header"
#define SB_SCFBFailedToWriteHeader 	"Failed to write header"
#define SB_SCFBNoStreamAvailable 	"No Stream Available"
#define SB_SCFBFailedToWriteFirstSector 	"Failed to write first sector"
#define SB_SCFBFailedToReadRootEntry 	"Failed to read root entry"
#define SB_SCFBFailedToWriteRootEntry 	"Failed to write root entry"
#define SB_SCFBInvalidObjectTypeForRootEntry 	"Invalid object type for root entry"
#define SB_SCFBInvalidFileSignature 	"Invalid file signature"
#define SB_SCFBInvalidSectorSize 	"Invalid sector size"
#define SB_SCFBInvalidMiniSectorSize 	"Invalid mini sector size"
#define SB_SCFBInvalidNumberOfDIFATSectors 	"Invalid number of DIFAT sectors"
#define SB_SCFBInvalidNumberOfFATSectors 	"Invalid number of FAT sectors"
#define SB_SCFBInvalidNumberOfMiniFATSectors 	"Invalid number of Mini FAT sectors"
#define SB_SCFBInvalidNumberOfDirEntrySectors 	"Invalid number of directory entry sectors"
#define SB_SCFBFileTooSmall 	"File too small for compound file header"
#define SB_SCFBRootEntryHasSiblings 	"Root entry has sibling entries"
#define SB_SCFBInvalidStreamSize 	"Invalid stream size"
#define SB_SCFBStreamSizeMismatch 	"Stream size mismatch"
#define SB_SCFBFailedToReadDataFromMiniStream 	"Failed to read data from mini stream"
#define SB_SCFBFailedToWriteDataToMiniStream 	"Failed to write data to mini stream"
#define SB_SCFBFailedToReadDataFromStream 	"Failed to read data from standard stream"
#define SB_SCFBFailedToWriteDataToStream 	"Failed to write data to standard stream"
#define SB_SCFBCannotChangeNameForRootEntry 	"Cannot change name for root entry"
#define SB_SCFBCannotChangeCreationTimeForRootEntry 	"Cannot change creation time for root entry"
#define SB_SCFBCannotChangeModifiedTimeForRootEntry 	"Cannot change modified time for root entry"
#define SB_SCFBCannotDeleteStreamNotFound 	"Cannot delete stream, not found"
#define SB_SCFBCannotDeleteSubStorageNotFound 	"Cannot delete sub-storage, not found"
#define SB_SCFBCannotDeleteSubStorageNonEmpty 	"Cannot delete non-empty sub-storage"
#define SB_SCFBCannotWriteReadOnly 	"Cannot write data (storage is read-only)"
#define SB_SCFBInputBufferTooSmall 	"Input buffer too small"
#define SB_SCFBOutputBufferTooSmall 	"Output buffer too small"

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCOMPOUNDFILERESOURCES */

