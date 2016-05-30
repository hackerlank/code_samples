#ifndef __INC_SBSFTPCOMMON
#define __INC_SBSFTPCOMMON

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbconstants.h"
#include "sbstrutils.h"
#include "sbsshconstants.h"
#include "sbsshcommon.h"
#include "sbchsconv.h"
#include "sbchsconvcharsets.h"
#include "sbchscjk.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ERROR_FACILITY_SFTP 	118784
#define SB_ERROR_SFTP_PROTOCOL_ERROR_FLAG 	1024
#define SB_ERROR_SFTP_CUSTOM_ERROR_FLAG 	2048
#define SB_SSH_ERROR_OK 	0
#define SB_SSH_ERROR_BASE 	0
#define SB_SSH_ERROR_WRONG_MODE 	-1
#define SB_SSH_ERROR_EOF 	1
#define SB_SSH_ERROR_NO_SUCH_FILE 	2
#define SB_SSH_ERROR_PERMISSION_DENIED 	3
#define SB_SSH_ERROR_FAILURE 	4
#define SB_SSH_ERROR_BAD_MESSAGE 	5
#define SB_SSH_ERROR_NO_CONNECTION 	6
#define SB_SSH_ERROR_CONNECTION_LOST 	7
#define SB_SSH_ERROR_OP_UNSUPPORTED 	8
#define SB_SSH_ERROR_INVALID_HANDLE 	9
#define SB_SSH_ERROR_NO_SUCH_PATH 	10
#define SB_SSH_ERROR_FILE_ALREADY_EXISTS 	11
#define SB_SSH_ERROR_WRITE_PROTECT 	12
#define SB_SSH_ERROR_NO_MEDIA 	13
#define SB_SSH_ERROR_NO_SPACE_ON_FILESYSTEM 	14
#define SB_SSH_ERROR_QUOTA_EXCEEDED 	15
#define SB_SSH_ERROR_UNKNOWN_PRINCIPAL 	16
#define SB_SSH_ERROR_LOCK_CONFLICT 	17
#define SB_SSH_ERROR_DIR_NOT_EMPTY 	18
#define SB_SSH_ERROR_NOT_A_DIRECTORY 	19
#define SB_SSH_ERROR_INVALID_FILENAME 	20
#define SB_SSH_ERROR_LINK_LOOP 	21
#define SB_SSH_ERROR_CANNOT_DELETE 	22
#define SB_SSH_ERROR_INVALID_PARAMETER 	23
#define SB_SSH_ERROR_FILE_IS_A_DIRECTORY 	24
#define SB_SSH_ERROR_BYTE_RANGE_LOCK_CONFLICT 	25
#define SB_SSH_ERROR_BYTE_RANGE_LOCK_REFUSED 	26
#define SB_SSH_ERROR_DELETE_PENDING 	27
#define SB_SSH_ERROR_FILE_CORRUPT 	28
#define SB_SSH_ERROR_OWNER_INVALID 	29
#define SB_SSH_ERROR_GROUP_INVALID 	30
#define SB_SSH_ERROR_UNSUPPORTED_VERSION 	100
#define SB_SSH_ERROR_INVALID_PACKET 	101
#define SB_SSH_ERROR_TUNNEL_ERROR 	102
#define SB_SSH_ERROR_CONNECTION_CLOSED 	103
#define SB_SSH_ERROR_UNSUPPORTED_ACTION 	104
#define SB_SSH_ERROR_NOT_A_TEXT_HANDLE 	105
#define SB_SSH_ERROR_CANCELLED_BY_USER 	106
#define SB_SFTP_ERROR_CUSTOM_BASE 	120832
#define SB_SFTP_ERROR_OFFSET_TOO_LARGE 	120833
#define SB_SFTP_ERROR_TIMES_NOT_SET 	120834
#define SB_SFTP_ERROR_LOCAL_SOURCE_NOT_FILE 	120835
#define SB_SFTP_ERROR_LOCAL_TARGET_NOT_FILE 	120836
#define SB_SFTP_ERROR_OPERATION_CRITERIA_NOT_MET 	120837
#define SB_SFTP_ERROR_INTERRUPTED_BY_USER 	120838
#define SB_ACE4_ACCESS_ALLOWED_ACE_TYPE 	0
#define SB_ACE4_ACCESS_DENIED_ACE_TYPE 	1
#define SB_ACE4_SYSTEM_AUDIT_ACE_TYPE 	2
#define SB_ACE4_SYSTEM_ALARM_ACE_TYPE 	3
#define SB_ACE4_FILE_INHERIT_ACE 	1
#define SB_ACE4_DIRECTORY_INHERIT_ACE 	2
#define SB_ACE4_NO_PROPAGATE_INHERIT_ACE 	4
#define SB_ACE4_INHERIT_ONLY_ACE 	8
#define SB_ACE4_SUCCESSFUL_ACCESS_ACE_FLAG 	16
#define SB_ACE4_FAILED_ACCESS_ACE_FLAG 	32
#define SB_ACE4_IDENTIFIER_GROUP 	64
#define SB_ACE4_READ_DATA 	1
#define SB_ACE4_LIST_DIRECTORY 	1
#define SB_ACE4_WRITE_DATA 	2
#define SB_ACE4_ADD_FILE 	2
#define SB_ACE4_APPEND_DATA 	4
#define SB_ACE4_ADD_SUBDIRECTORY 	4
#define SB_ACE4_READ_NAMED_ATTRS 	8
#define SB_ACE4_WRITE_NAMED_ATTRS 	16
#define SB_ACE4_EXECUTE 	32
#define SB_ACE4_DELETE_CHILD 	64
#define SB_ACE4_READ_ATTRIBUTES 	128
#define SB_ACE4_WRITE_ATTRIBUTES 	256
#define SB_ACE4_DELETE 	65536
#define SB_ACE4_READ_ACL 	131072
#define SB_ACE4_WRITE_ACL 	262144
#define SB_ACE4_WRITE_OWNER 	524288
#define SB_ACE4_SYNCHRONIZE 	1048576
#define SB_SSH_FILEXFER_ATTR_FLAGS_READONLY 	1
#define SB_SSH_FILEXFER_ATTR_FLAGS_SYSTEM 	2
#define SB_SSH_FILEXFER_ATTR_FLAGS_HIDDEN 	4
#define SB_SSH_FILEXFER_ATTR_FLAGS_CASE_INSENSITIVE 	8
#define SB_SSH_FILEXFER_ATTR_FLAGS_ARCHIVE 	16
#define SB_SSH_FILEXFER_ATTR_FLAGS_ENCRYPTED 	32
#define SB_SSH_FILEXFER_ATTR_FLAGS_COMPRESSED 	64
#define SB_SSH_FILEXFER_ATTR_FLAGS_SPARSE 	128
#define SB_SSH_FILEXFER_ATTR_FLAGS_APPEND_ONLY 	256
#define SB_SSH_FILEXFER_ATTR_FLAGS_IMMUTABLE 	512
#define SB_SSH_FILEXFER_ATTR_FLAGS_SYNC 	1024
#define SB_SSH_FILEXFER_ATTR_FLAGS_TRANSLATION_ERR 	2048
#define SB_S_IRUSR 	256
#define SB_S_IWUSR 	128
#define SB_S_IXUSR 	64
#define SB_S_IRGRP 	32
#define SB_S_IWGRP 	16
#define SB_S_IXGRP 	8
#define SB_S_IROTH 	4
#define SB_S_IWOTH 	2
#define SB_S_IXOTH 	1
#define SB_S_ISUID 	2048
#define SB_S_ISGID 	1024
#define SB_S_ISVTX 	512
#ifndef SB_BUFFER_SIZE
#define SB_BUFFER_SIZE 	131072
#endif
#define SB_DATA_BUFFER_SIZE 	130048
#define SB_SSH_FXP_INIT 	1
#define SB_SSH_FXP_VERSION 	2
#define SB_SSH_FXP_OPEN 	3
#define SB_SSH_FXP_CLOSE 	4
#define SB_SSH_FXP_READ 	5
#define SB_SSH_FXP_WRITE 	6
#define SB_SSH_FXP_LSTAT 	7
#define SB_SSH_FXP_FSTAT 	8
#define SB_SSH_FXP_SETSTAT 	9
#define SB_SSH_FXP_FSETSTAT 	10
#define SB_SSH_FXP_OPENDIR 	11
#define SB_SSH_FXP_READDIR 	12
#define SB_SSH_FXP_REMOVE 	13
#define SB_SSH_FXP_MKDIR 	14
#define SB_SSH_FXP_RMDIR 	15
#define SB_SSH_FXP_REALPATH 	16
#define SB_SSH_FXP_STAT 	17
#define SB_SSH_FXP_RENAME 	18
#define SB_SSH_FXP_READLINK 	19
#define SB_SSH_FXP_SYMLINK 	20
#define SB_SSH_FXP_LINK 	21
#define SB_SSH_FXP_BLOCK 	22
#define SB_SSH_FXP_UNBLOCK 	23
#define SB_SSH_FXP_STATUS 	101
#define SB_SSH_FXP_HANDLE 	102
#define SB_SSH_FXP_DATA 	103
#define SB_SSH_FXP_NAME 	104
#define SB_SSH_FXP_ATTRS 	105
#define SB_SSH_FXP_EXTENDED 	200
#define SB_SSH_FXP_EXTENDED_REPLY 	201
#define SB_SSH_FILEXFER_ATTR_SIZE 	1
#define SB_SSH_FILEXFER_ATTR_UIDGID 	2
#define SB_SSH_FILEXFER_ATTR_PERMISSIONS 	4
#define SB_SSH_FILEXFER_ATTR_ACCESSTIME 	8
#define SB_SSH_FILEXFER_ATTR_ACMODTIME 	8
#define SB_SSH_FILEXFER_ATTR_CREATETIME 	16
#define SB_SSH_FILEXFER_ATTR_MODIFYTIME 	32
#define SB_SSH_FILEXFER_ATTR_ACL 	64
#define SB_SSH_FILEXFER_ATTR_OWNERGROUP 	128
#define SB_SSH_FILEXFER_ATTR_SUBSECOND_TIMES 	256
#define SB_SSH_FILEXFER_ATTR_BITS 	512
#define SB_SSH_FILEXFER_ATTR_ALLOCATION_SIZE 	1024
#define SB_SSH_FILEXFER_ATTR_TEXT_HINT 	2048
#define SB_SSH_FILEXFER_ATTR_MIME_TYPE 	4096
#define SB_SSH_FILEXFER_ATTR_LINK_COUNT 	8192
#define SB_SSH_FILEXFER_ATTR_UNTRANSLATED_NAME 	16384
#define SB_SSH_FILEXFER_ATTR_CTIME 	32768
#define SB_SSH_FILEXFER_ATTR_EXTENDED 	2147483648
#define SB_SSH_FILEXFER_ATTR_V3 	2147483663
#define SB_SSH_FILEXFER_ATTR_V4 	2147484157
#define SB_SSH_FILEXFER_ATTR_V5 	2147484669
#define SB_SSH_FILEXFER_ATTR_V6 	2147549181
#define SB_SSH_FILEXFER_TYPE_ERRONEOUS 	0
#define SB_SSH_FILEXFER_TYPE_REGULAR 	1
#define SB_SSH_FILEXFER_TYPE_DIRECTORY 	2
#define SB_SSH_FILEXFER_TYPE_SYMLINK 	3
#define SB_SSH_FILEXFER_TYPE_SPECIAL 	4
#define SB_SSH_FILEXFER_TYPE_UNKNOWN 	5
#define SB_SSH_FILEXFER_TYPE_SOCKET 	6
#define SB_SSH_FILEXFER_TYPE_CHAR_DEVICE 	7
#define SB_SSH_FILEXFER_TYPE_BLOCK_DEVICE 	8
#define SB_SSH_FILEXFER_TYPE_FIFO 	9
#define SB_SSH_FXF_READ 	1
#define SB_SSH_FXF_WRITE 	2
#define SB_SSH_FXF_APPEND 	4
#define SB_SSH_FXF_CREAT 	8
#define SB_SSH_FXF_TRUNC 	16
#define SB_SSH_FXF_EXCL 	32
#define SB_SSH_FXF_TEXT 	64
#define SB_SSH_FXF_ACCESS_DISPOSITION 	7
#define SB_SSH_FXF_CREATE_NEW 	0
#define SB_SSH_FXF_CREATE_TRUNCATE 	1
#define SB_SSH_FXF_OPEN_EXISTING 	2
#define SB_SSH_FXF_OPEN_OR_CREATE 	3
#define SB_SSH_FXF_TRUNCATE_EXISTING 	4
#define SB_SSH_FXF_ACCESS_APPEND_DATA 	8
#define SB_SSH_FXF_ACCESS_APPEND_DATA_ATOMIC 	16
#define SB_SSH_FXF_ACCESS_TEXT_MODE 	32
#define SB_SSH_FXF_ACCESS_READ_LOCK 	64
#define SB_SSH_FXF_ACCESS_WRITE_LOCK 	128
#define SB_SSH_FXF_ACCESS_DELETE_LOCK 	256
#define SB_SSH_FXF_ACCESS_BLOCK_READ 	64
#define SB_SSH_FXF_ACCESS_BLOCK_WRITE 	128
#define SB_SSH_FXF_ACCESS_BLOCK_DELETE 	256
#define SB_SSH_FXF_ACCESS_BLOCK_ADVISORY 	512
#define SB_SSH_FXF_ACCESS_NOFOLLOW 	1024
#define SB_SSH_FXF_ACCESS_DELETE_ON_CLOSE 	2048
#define SB_SSH_FX_OK 	0
#define SB_SSH_FX_EOF 	1
#define SB_SSH_FX_NO_SUCH_FILE 	2
#define SB_SSH_FX_PERMISSION_DENIED 	3
#define SB_SSH_FX_FAILURE 	4
#define SB_SSH_FX_BAD_MESSAGE 	5
#define SB_SSH_FX_NO_CONNECTION 	6
#define SB_SSH_FX_CONNECTION_LOST 	7
#define SB_SSH_FX_OP_UNSUPPORTED 	8
#define SB_SSH_FX_INVALID_HANDLE 	9
#define SB_SSH_FX_NO_SUCH_PATH 	10
#define SB_SSH_FX_FILE_ALREADY_EXISTS 	11
#define SB_SSH_FX_WRITE_PROTECT 	12
#define SB_SSH_FX_NO_MEDIA 	13
#define SB_SSH_FX_NO_SPACE_ON_FILESYSTEM 	14
#define SB_SSH_FX_QUOTA_EXCEEDED 	15
#define SB_SSH_FX_UNKNOWN_PRINCIPLE 	16
#define SB_SSH_FX_LOCK_CONFlICT 	17
#define SB_SSH_FX_DIR_NOT_EMPTY 	18
#define SB_SSH_FX_NOT_A_DIRECTORY 	19
#define SB_SSH_FX_INVALID_FILENAME 	20
#define SB_SSH_FX_LINK_LOOP 	21
#define SB_SSH_FX_CANNOT_DELETE 	22
#define SB_SSH_FX_INVALID_PARAMETER 	23
#define SB_SSH_FX_FILE_IS_A_DIRECTORY 	24
#define SB_SSH_FX_BYTE_RANGE_LOCK_CONFLICT 	25
#define SB_SSH_FX_BYTE_RANGE_LOCK_REFUSED 	26
#define SB_SSH_FX_DELETE_PENDING 	27
#define SB_SSH_FX_FILE_CORRUPT 	28
#define SB_SSH_FX_OWNER_INVALID 	29
#define SB_SSH_FX_GROUP_INVALID 	30
#define SB_SSH_FXP_REALPATH_NO_CHECK 	1
#define SB_SSH_ATTR_REQUEST4 	509
#define SB_SSH_ATTR_REQUEST5 	1021
#define SB_SSH_ATTR_REQUEST6 	33789
#define SB_SSH_EXT_NEWLINE 	"newline"
#define SB_SSH_EXT_NEWLINE_VANDYKE 	"newline@vandyke.com"
#define SB_SSH_EXT_SUPPORTED 	"supported"
#define SB_SSH_EXT_SUPPORTED2 	"supported2"
#define SB_SSH_EXT_VERSIONS 	"versions"
#define SB_SSH_EXT_VERSION_SELECT 	"version-select"
#define SB_SSH_EXT_FILENAME_CHARSET 	"filename-charset"
#define SB_SSH_EXT_FILENAME_TRANSLATION_CONTROL 	"filename-translation-control"
#define SB_SSH_EXT_TEXTSEEK 	"text-seek"
#define SB_SSH_EXT_VENDOR_ID 	"vendor-id"
#define SB_SSH_EXT_CHECK_FILE 	"check-file"
#define SB_SSH_EXT_CHECK_FILE_HANDLE 	"check-file-handle"
#define SB_SSH_EXT_CHECK_FILE_NAME 	"check-file-name"
#define SB_SSH_EXT_SPACE_AVAILABLE 	"space-available"
#define SB_SSH_EXT_HOME_DIRECTORY 	"home-directory"
#define SB_SSH_EXT_COPY_FILE 	"copy-file"
#define SB_SSH_EXT_COPY_DATA 	"copy-data"
#define SB_SSH_EXT_GET_TEMP_FOLDER 	"get-temp-folder"
#define SB_SSH_EXT_MAKE_TEMP_FOLDER 	"make-temp-folder"
#define SB_SSH_EXT_STATVFS 	"statvfs@openssh.com"

typedef TElClassHandle TSBSftpExtendedAttributeHandle;

typedef TElClassHandle TElSftpExtendedReplyHandle;

typedef TElSftpExtendedReplyHandle ElSftpExtendedReplyHandle;

typedef TElClassHandle TElSftpNewlineExtensionHandle;

typedef TElSftpNewlineExtensionHandle ElSftpNewlineExtensionHandle;

typedef TElClassHandle TElSftpVersionsExtensionHandle;

typedef TElSftpVersionsExtensionHandle ElSftpVersionsExtensionHandle;

typedef TElClassHandle TElSftpFilenameTranslationExtensionHandle;

typedef TElSftpFilenameTranslationExtensionHandle ElSftpFilenameTranslationExtensionHandle;

typedef TElClassHandle TElSftpFilenameCharsetExtensionHandle;

typedef TElSftpFilenameCharsetExtensionHandle ElSftpFilenameCharsetExtensionHandle;

typedef TElClassHandle TElSftpVersionSelectExtensionHandle;

typedef TElSftpVersionSelectExtensionHandle ElSftpVersionSelectExtensionHandle;

typedef TElClassHandle TElSftpSupportedExtensionHandle;

typedef TElSftpSupportedExtensionHandle ElSftpSupportedExtensionHandle;

typedef TElClassHandle TElSftpVendorIDExtensionHandle;

typedef TElSftpVendorIDExtensionHandle ElSftpVendorIDExtensionHandle;

typedef TElClassHandle TElSftpCheckFileExtensionHandle;

typedef TElSftpCheckFileExtensionHandle ElSftpCheckFileExtensionHandle;

typedef TElClassHandle TElSftpStatvfsExtensionHandle;

typedef TElSftpStatvfsExtensionHandle ElSftpStatvfsExtensionHandle;

typedef TElClassHandle TElSftpSpaceAvailableExtensionHandle;

typedef TElSftpSpaceAvailableExtensionHandle ElSftpSpaceAvailableExtensionHandle;

typedef TElClassHandle TElSftpHomeDirectoryExtensionHandle;

typedef TElSftpHomeDirectoryExtensionHandle ElSftpHomeDirectoryExtensionHandle;

typedef TElClassHandle TElSftpCopyFileExtensionHandle;

typedef TElSftpCopyFileExtensionHandle ElSftpCopyFileExtensionHandle;

typedef TElClassHandle TElSftpCopyDataExtensionHandle;

typedef TElSftpCopyDataExtensionHandle ElSftpCopyDataExtensionHandle;

typedef TElClassHandle TElSftpCheckFileReplyHandle;

typedef TElSftpCheckFileReplyHandle ElSftpCheckFileReplyHandle;

typedef TElClassHandle TElSftpSpaceAvailableReplyHandle;

typedef TElSftpSpaceAvailableReplyHandle ElSftpSpaceAvailableReplyHandle;

typedef TElClassHandle TElSftpStatVFSReplyHandle;

typedef TElSftpStatVFSReplyHandle ElSftpStatVFSReplyHandle;

typedef TElClassHandle TSBSftpACEHandle;

typedef TElClassHandle TElSftpExtendedPropertiesHandle;

typedef TElSftpExtendedPropertiesHandle ElSftpExtendedPropertiesHandle;

typedef TElClassHandle TElSftpFileAttributesHandle;

typedef TElSftpFileAttributesHandle ElSftpFileAttributesHandle;

typedef TElClassHandle TElSftpFileInfoHandle;

typedef TElSftpFileInfoHandle ElSftpFileInfoHandle;

typedef TElClassHandle TSBSftpOpenRequestInfoHandle;

typedef TElClassHandle TSBSftpTextHandleInfoHandle;

typedef TElClassHandle TElSftpTransferBlockHandle;

typedef TElSftpTransferBlockHandle ElSftpTransferBlockHandle;

typedef TElClassHandle TElSftpTransferManagerHandle;

typedef TElSftpTransferManagerHandle ElSftpTransferManagerHandle;

typedef TElClassHandle TElSftpRemovalTargetHandle;

typedef TElClassHandle TElSftpRemovalManagerHandle;

typedef uint8_t TSBSftpFileOpenModeRaw;

typedef enum
{
	fmRead = 0,
	fmWrite = 1,
	fmAppend = 2,
	sfmCreate = 3,
	fmTruncate = 4,
	fmExcl = 5,
	fmText = 6,
	fmOpenOrCreate = 7,
	fmAppendAtomic = 8,
	fmNoFollow = 9,
	fmDeleteOnClose = 10
} TSBSftpFileOpenMode;

typedef uint32_t TSBSftpFileOpenModesRaw;

typedef enum 
{
	f_fmRead = 1,
	f_fmWrite = 2,
	f_fmAppend = 4,
	f_sfmCreate = 8,
	f_fmTruncate = 16,
	f_fmExcl = 32,
	f_fmText = 64,
	f_fmOpenOrCreate = 128,
	f_fmAppendAtomic = 256,
	f_fmNoFollow = 512,
	f_fmDeleteOnClose = 1024
} TSBSftpFileOpenModes;

typedef uint8_t TSBSftpFileOpenAccessItemRaw;

typedef enum
{
	faReadLock = 0,
	faWriteLock = 1,
	faDeleteLock = 2,
	faBlockAdvisory = 3
} TSBSftpFileOpenAccessItem;

typedef uint32_t TSBSftpFileOpenAccessRaw;

typedef enum 
{
	f_faReadLock = 1,
	f_faWriteLock = 2,
	f_faDeleteLock = 4,
	f_faBlockAdvisory = 8
} TSBSftpFileOpenAccess;

typedef uint8_t TSBSftpVersionRaw;

typedef enum
{
	sbSFTP0 = 0,
	sbSFTP1 = 1,
	sbSFTP2 = 2,
	sbSFTP3 = 3,
	sbSFTP4 = 4,
	sbSFTP5 = 5,
	sbSFTP6 = 6
} TSBSftpVersion;

typedef uint32_t TSBSftpVersionsRaw;

typedef enum 
{
	f_sbSFTP0 = 1,
	f_sbSFTP1 = 2,
	f_sbSFTP2 = 4,
	f_sbSFTP3 = 8,
	f_sbSFTP4 = 16,
	f_sbSFTP5 = 32,
	f_sbSFTP6 = 64
} TSBSftpVersions;

typedef uint8_t TSBSftpAttributeRaw;

typedef enum
{
	saSize = 0,
	saOwner = 1,
	saGroup = 2,
	saUID = 3,
	saGID = 4,
	saPermissions = 5,
	saATime = 6,
	saMTime = 7,
	saCTime = 8,
	saSubSeconds = 9,
	saAttribBits = 10,
	saACL = 11,
	saExtended = 12,
	saCATime = 13,
	saASize = 14,
	saTextHint = 15,
	saMimeType = 16,
	saLinkCount = 17,
	saUName = 18
} TSBSftpAttribute;

typedef uint32_t TSBSftpAttributesRaw;

typedef enum 
{
	f_saSize = 1,
	f_saOwner = 2,
	f_saGroup = 4,
	f_saUID = 8,
	f_saGID = 16,
	f_saPermissions = 32,
	f_saATime = 64,
	f_saMTime = 128,
	f_saCTime = 256,
	f_saSubSeconds = 512,
	f_saAttribBits = 1024,
	f_saACL = 2048,
	f_saExtended = 4096,
	f_saCATime = 8192,
	f_saASize = 16384,
	f_saTextHint = 32768,
	f_saMimeType = 65536,
	f_saLinkCount = 131072,
	f_saUName = 262144
} TSBSftpAttributes;

typedef uint8_t TSBSftpRenameFlagRaw;

typedef enum
{
	rfOverwrite = 0,
	rfAtomic = 1,
	rfNative = 2
} TSBSftpRenameFlag;

typedef uint32_t TSBSftpRenameFlagsRaw;

typedef enum 
{
	f_rfOverwrite = 1,
	f_rfAtomic = 2,
	f_rfNative = 4
} TSBSftpRenameFlags;

typedef uint8_t TSBSftpTextHintRaw;

typedef enum
{
	thKnownText = 0,
	thGuessedText = 1,
	thKnownBinary = 2,
	thGuessedBinary = 3
} TSBSftpTextHint;

typedef uint8_t TSBSftpRealpathControlRaw;

typedef enum
{
	rcNoCheck = 0,
	rcStatIf = 1,
	rcStatAlways = 2
} TSBSftpRealpathControl;

typedef uint8_t TSBSftpFileOperationRaw;

typedef enum
{
	sfoDownloadFile = 0,
	sfoUploadFile = 1,
	sfoDeleteFile = 2,
	sfoMakeDir = 3
} TSBSftpFileOperation;

typedef uint8_t TSBSftpFileTypeRaw;

typedef enum
{
	ftFile = 0,
	ftDirectory = 1,
	ftSymblink = 2,
	ftSpecial = 3,
	ftUnknown = 4,
	ftSocket = 5,
	ftCharDevice = 6,
	ftBlockDevice = 7,
	ftFIFO = 8
} TSBSftpFileType;

typedef uint8_t TSBSftpTransferDirectionRaw;

typedef enum
{
	tdDownload = 0,
	tdUpload = 1
} TSBSftpTransferDirection;

typedef void (SB_CALLBACK *TSBSftpFileOpenEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pHandle[], int32_t szHandle);

typedef void (SB_CALLBACK *TSBSftpErrorEvent)(void * _ObjectData, TObjectHandle Sender, int32_t ErrorCode, const char * pcComment, int32_t szComment);

typedef void (SB_CALLBACK *TSBSftpSuccessEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcComment, int32_t szComment);

typedef void (SB_CALLBACK *TSBSftpDirectoryListingEvent)(void * _ObjectData, TObjectHandle Sender, const TElSftpFileInfoHandle pListing[], int32_t szListing);

typedef void (SB_CALLBACK *TSBSftpFileAttributesEvent)(void * _ObjectData, TObjectHandle Sender, TElSftpFileAttributesHandle Attributes);

typedef void (SB_CALLBACK *TSBSftpDataEvent)(void * _ObjectData, TObjectHandle Sender, void * Buffer, int32_t Size);

typedef void (SB_CALLBACK *TSBSftpAbsolutePathEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcPath, int32_t szPath);

typedef void (SB_CALLBACK *TSBSftpVersionSelectEvent)(void * _ObjectData, TObjectHandle Sender, TSBSftpVersionsRaw Versions, TSBSftpVersionRaw * Version);

typedef void (SB_CALLBACK *TSBSftpAvailableSpaceEvent)(void * _ObjectData, TObjectHandle Sender, TElSftpSpaceAvailableReplyHandle AvailSpace);

typedef void (SB_CALLBACK *TSBSftpFileHashEvent)(void * _ObjectData, TObjectHandle Sender, TElSftpCheckFileReplyHandle Reply, int8_t * Cont);

typedef void (SB_CALLBACK *TSBSftpNameEvent)(void * _ObjectData, TObjectHandle Sender, TElSftpFileInfoHandle FileInfo);

typedef void (SB_CALLBACK *TSBSftpTransferCompletedEvent)(void * _ObjectData, TObjectHandle Sender, int32_t Count);

typedef void (SB_CALLBACK *TSBSftpBlockTransferPreparedEvent)(void * _ObjectData, TObjectHandle Sender, int64_t Offset, int64_t Size, TSBSftpTransferDirectionRaw Direction, int8_t TextMode, int32_t * BlockSize, int32_t * PipelineLength);

typedef void (SB_CALLBACK *TSBSftpMessageLoopEvent)(void * _ObjectData, int8_t * OutResult);

typedef void (SB_CALLBACK *TSBSftpTunnelOpenFailedEvent)(void * _ObjectData, TObjectHandle Sender, TElCustomSSHTunnelHandle Tunnel, int8_t * AbortConnection);

typedef void (SB_CALLBACK *TSBSftpSecondaryChannelEvent)(void * _ObjectData, TObjectHandle Sender, TElCustomSSHTunnelHandle Tunnel);

typedef void (SB_CALLBACK *TSBSftpSecondaryChannelErrorEvent)(void * _ObjectData, TObjectHandle Sender, TElCustomSSHTunnelHandle Tunnel, int32_t ErrorCode);

typedef void (SB_CALLBACK *TSBSftpStatvfsEvent)(void * _ObjectData, TObjectHandle Sender, TElSftpStatVFSReplyHandle Statvfs);

typedef void (SB_CALLBACK *TElSFTPServerBlockEvent)(void * _ObjectData, TObjectHandle Sender, void * Data, int64_t Offset, int64_t Length, TSBSftpFileOpenAccessRaw LockMask, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerUnblockEvent)(void * _ObjectData, TObjectHandle Sender, void * Data, int64_t Offset, int64_t Length, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerCreateDirectoryEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcPath, int32_t szPath, TElSftpFileAttributesHandle Attributes, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerCreateSymLinkEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcLinkPath, int32_t szLinkPath, const char * pcTargetPath, int32_t szTargetPath, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerCreateHardLinkEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcNewLinkPath, int32_t szNewLinkPath, const char * pcExistingPath, int32_t szExistingPath, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerOpenFileEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcPath, int32_t szPath, TSBSftpFileOpenModesRaw Modes, TSBSftpFileOpenAccessRaw Access, uint32_t DesiredAccess, TElSftpFileAttributesHandle Attributes, void * (* Data), int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerRemoveEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcPath, int32_t szPath, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerRenameFileEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcOldPath, int32_t szOldPath, const char * pcNewPath, int32_t szNewPath, TSBSftpRenameFlagsRaw Flags, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerReadSymLinkEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcPath, int32_t szPath, TElSftpFileInfoHandle Info, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerSetAttributesEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcPath, int32_t szPath, TElSftpFileAttributesHandle Attributes, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerSetAttributes2Event)(void * _ObjectData, TObjectHandle Sender, void * Data, TElSftpFileAttributesHandle Attributes, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerRequestAttributesEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcPath, int32_t szPath, int8_t FollowSymLinks, TElSftpFileAttributesHandle Attributes, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerRequestAbsolutePathEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcPath, int32_t szPath, char * pcAbsolutePath, int32_t * szAbsolutePath, TSBSftpRealpathControlRaw Control, TStringListHandle ComposePath, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerRequestAttributes2Event)(void * _ObjectData, TObjectHandle Sender, void * Data, TElSftpFileAttributesHandle Attributes, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerFindFirstEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcPath, int32_t szPath, void * (* Data), TElSftpFileInfoHandle Info, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerFindNextEvent)(void * _ObjectData, TObjectHandle Sender, void * Data, TElSftpFileInfoHandle Info, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerFindCloseEvent)(void * _ObjectData, TObjectHandle Sender, void * SearchRec, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerReadEvent)(void * _ObjectData, TObjectHandle Sender, void * Data, int64_t Offset, void * Buffer, int32_t Count, int32_t * Read, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerWriteEvent)(void * _ObjectData, TObjectHandle Sender, void * Data, int64_t Offset, void * Buffer, int32_t Count, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerTextSeekEvent)(void * _ObjectData, TObjectHandle Sender, void * Data, int64_t LineNumber, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerCloseHandleEvent)(void * _ObjectData, TObjectHandle Sender, void * Data, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSFTPServerSendEvent)(void * _ObjectData, TObjectHandle Sender, void * Buffer, int32_t Size);

typedef void (SB_CALLBACK *TElSFTPServerReceiveEvent)(void * _ObjectData, TObjectHandle Sender, void * Buffer, int32_t MaxSize, int32_t * Written);

typedef void (SB_CALLBACK *TElSFTPServerExtendedRequestEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcRequest, int32_t szRequest, void * Buffer, int32_t Size, TStreamHandle Response, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TElSftpServerVersionChangeEvent)(void * _ObjectData, TObjectHandle Sender, TSBSftpVersionRaw Version);

typedef void (SB_CALLBACK *TElSFTPServerSendVendorIDEvent)(void * _ObjectData, TObjectHandle Sender, TElSftpVendorIDExtensionHandle VendorID, int8_t * Send);

typedef void (SB_CALLBACK *TElSFTPServerRequestFileHashEvent)(void * _ObjectData, TObjectHandle Sender, TElSftpCheckFileExtensionHandle Extension, TElSftpCheckFileReplyHandle Reply, int32_t * ErrCode, char * pcErrComment, int32_t * szErrComment);

typedef void (SB_CALLBACK *TElSFTPServerRequestFileHashByHandleEvent)(void * _ObjectData, TObjectHandle Sender, void * Data, TElSftpCheckFileExtensionHandle Extension, TElSftpCheckFileReplyHandle Reply, int32_t * ErrCode, char * pcErrComment, int32_t * szErrComment);

typedef void (SB_CALLBACK *TElSFTPServerRequestAvailableSpaceEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcPath, int32_t szPath, TElSftpSpaceAvailableReplyHandle Reply, int32_t * ErrCode, char * pcErrComment, int32_t * szErrComment);

typedef void (SB_CALLBACK *TElSFTPServerRequestStatVFSEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcPath, int32_t szPath, TElSftpStatVFSReplyHandle Reply, int32_t * ErrCode, char * pcErrComment, int32_t * szErrComment);

typedef void (SB_CALLBACK *TElSFTPServerRequestHomeDirectoryEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcUsername, int32_t szUsername, char * pcHomeDir, int32_t * szHomeDir, int32_t * ErrCode, char * pcErrComment, int32_t * szErrComment);

typedef void (SB_CALLBACK *TElSFTPServerCopyRemoteFileEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcSource, int32_t szSource, const char * pcDestination, int32_t szDestination, int8_t Overwrite, int32_t * ErrCode, char * pcErrComment, int32_t * szErrComment);

typedef void (SB_CALLBACK *TElSFTPServerCopyRemoteDataEvent)(void * _ObjectData, TObjectHandle Sender, void * ReadFromData, int64_t ReadFromOffset, void * WriteToData, int64_t WriteToOffset, int64_t DataLength, int32_t * ErrCode, char * pcErrComment, int32_t * szErrComment);

typedef void (SB_CALLBACK *TElSFTPServerReturnPathEvent)(void * _ObjectData, TObjectHandle Sender, char * pcPath, int32_t * szPath, int32_t * ErrCode, char * pcErrComment, int32_t * szErrComment);

typedef void (SB_CALLBACK *TElSftpFileOperationEvent)(void * _ObjectData, TObjectHandle Sender, TSBSftpFileOperationRaw Operation, const char * pcRemotePath, int32_t szRemotePath, const char * pcLocalPath, int32_t szLocalPath, int8_t * Skip, int8_t * Cancel);

typedef void (SB_CALLBACK *TElSftpFileOperationResultEvent)(void * _ObjectData, TObjectHandle Sender, TSBSftpFileOperationRaw Operation, const char * pcRemotePath, int32_t szRemotePath, const char * pcLocalPath, int32_t szLocalPath, int32_t ErrorCode, const char * pcComment, int32_t szComment, int8_t * Cancel);

typedef void (SB_CALLBACK *TSBSftpFileNameChangeNeededEvent)(void * _ObjectData, TObjectHandle Sender, char * pcFileName, int32_t * szFileName, int8_t * Force);

typedef uint8_t TElSftpOperationRaw;

typedef enum
{
	soNone = 0,
	soCreateFile = 1,
	soCreateSymLink = 2,
	soMakeDirectory = 3,
	soOpenDirectory = 4,
	soOpenFile = 5,
	soRead = 6,
	soReadDirectory = 7,
	soReadSymLink = 8,
	soRemoveDirectory = 9,
	soRemoveFile = 10,
	soRenameFile = 11,
	soRequestAbsolutePath = 12,
	soRequestAttributes = 13,
	soSetAttributes = 14,
	soWrite = 15,
	soCloseHandle = 16,
	soVersion = 17,
	soExtension = 18,
	soCreateHardLink = 19,
	soBlock = 20,
	soUnblock = 21
} TElSftpOperation;

typedef TElSftpOperation ElSftpOperation;

#pragma pack(4)
typedef struct 
{
	uint32_t Id;
	uint32_t Request;
	void * ExtType;
} TSBSftpRequestInfo, * PSBSftpRequestInfo;

#pragma pack(4)
typedef struct 
{
	uint32_t Id;
	uint32_t DataID;
	void * FileHandle;
	int64_t FileOffset;
	int64_t ChunkOffset;
	int64_t Size;
} TSBSftpDataRequestInfo, * PSBSftpDataRequestInfo;

typedef uint8_t TSBSftpTransferBlockStateRaw;

typedef enum
{
	bsRequested = 0,
	bsPostponed = 1,
	bsFinished = 2
} TSBSftpTransferBlockState;

typedef void (SB_CALLBACK *TSBSftpReadRequestEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pHandle[], int32_t szHandle, int64_t Offset, int32_t Size, uint32_t * Id);

typedef void (SB_CALLBACK *TSBSftpWriteRequestEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pHandle[], int32_t szHandle, void * Buffer, int64_t Offset, int32_t Size, uint32_t * Id, int8_t Last);

typedef void (SB_CALLBACK *TSBSftpRemovalRequestEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcName, int32_t szName, uint32_t * Id);

#ifdef SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TSBSftpExtendedAttribute_Assign(TSBSftpExtendedAttributeHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpExtendedAttribute_AssignTo(TSBSftpExtendedAttributeHandle _Handle, TPersistentHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpExtendedAttribute_LoadFromBuffer(TSBSftpExtendedAttributeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpExtendedAttribute_SaveToBuffer(TSBSftpExtendedAttributeHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpExtendedAttribute_Write(TSBSftpExtendedAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpExtendedAttribute_get_ExtType(TSBSftpExtendedAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpExtendedAttribute_set_ExtType(TSBSftpExtendedAttributeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpExtendedAttribute_get_ExtData(TSBSftpExtendedAttributeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpExtendedAttribute_set_ExtData(TSBSftpExtendedAttributeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpExtendedAttribute_get_UseUTF8(TSBSftpExtendedAttributeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpExtendedAttribute_set_UseUTF8(TSBSftpExtendedAttributeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpExtendedAttribute_get_NoCharacterEncoding(TSBSftpExtendedAttributeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpExtendedAttribute_set_NoCharacterEncoding(TSBSftpExtendedAttributeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpExtendedAttribute_get_LocalCharset(TSBSftpExtendedAttributeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpExtendedAttribute_set_LocalCharset(TSBSftpExtendedAttributeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpExtendedAttribute_get_RemoteCharset(TSBSftpExtendedAttributeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpExtendedAttribute_set_RemoteCharset(TSBSftpExtendedAttributeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpExtendedAttribute_Create(TSBSftpExtendedAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE */

#ifdef SB_USE_CLASS_TELSFTPEXTENDEDREPLY
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedReply_Assign(TElSftpExtendedReplyHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedReply_AssignTo(TElSftpExtendedReplyHandle _Handle, TPersistentHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedReply_LoadFromBuffer(TElSftpExtendedReplyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedReply_SaveToBuffer(TElSftpExtendedReplyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedReply_Write(TElSftpExtendedReplyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedReply_get_UseUTF8(TElSftpExtendedReplyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedReply_set_UseUTF8(TElSftpExtendedReplyHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedReply_get_NoCharacterEncoding(TElSftpExtendedReplyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedReply_set_NoCharacterEncoding(TElSftpExtendedReplyHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedReply_get_LocalCharset(TElSftpExtendedReplyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedReply_set_LocalCharset(TElSftpExtendedReplyHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedReply_get_RemoteCharset(TElSftpExtendedReplyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedReply_set_RemoteCharset(TElSftpExtendedReplyHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedReply_get_ReplyData(TElSftpExtendedReplyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedReply_set_ReplyData(TElSftpExtendedReplyHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedReply_Create(TElSftpExtendedReplyHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPEXTENDEDREPLY */

#ifdef SB_USE_CLASS_TELSFTPNEWLINEEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElSftpNewlineExtension_Assign(TElSftpNewlineExtensionHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSftpNewlineExtension_LoadFromBuffer(TElSftpNewlineExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpNewlineExtension_SaveToBuffer(TElSftpNewlineExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpNewlineExtension_get_Newline(TElSftpNewlineExtensionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpNewlineExtension_set_Newline(TElSftpNewlineExtensionHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpNewlineExtension_Create(TSBSftpExtendedAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPNEWLINEEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPVERSIONSEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElSftpVersionsExtension_Assign(TElSftpVersionsExtensionHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVersionsExtension_LoadFromBuffer(TElSftpVersionsExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVersionsExtension_SaveToBuffer(TElSftpVersionsExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVersionsExtension_get_Versions(TElSftpVersionsExtensionHandle _Handle, TSBSftpVersionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVersionsExtension_set_Versions(TElSftpVersionsExtensionHandle _Handle, TSBSftpVersionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVersionsExtension_get_VersionsStr(TElSftpVersionsExtensionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVersionsExtension_Create(TSBSftpExtendedAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPVERSIONSEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPFILENAMETRANSLATIONEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElSftpFilenameTranslationExtension_Assign(TElSftpFilenameTranslationExtensionHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFilenameTranslationExtension_LoadFromBuffer(TElSftpFilenameTranslationExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFilenameTranslationExtension_SaveToBuffer(TElSftpFilenameTranslationExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFilenameTranslationExtension_get_DoTranslate(TElSftpFilenameTranslationExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFilenameTranslationExtension_set_DoTranslate(TElSftpFilenameTranslationExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFilenameTranslationExtension_Create(TSBSftpExtendedAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPFILENAMETRANSLATIONEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPFILENAMECHARSETEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElSftpFilenameCharsetExtension_Assign(TElSftpFilenameCharsetExtensionHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFilenameCharsetExtension_LoadFromBuffer(TElSftpFilenameCharsetExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFilenameCharsetExtension_SaveToBuffer(TElSftpFilenameCharsetExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFilenameCharsetExtension_get_Charset(TElSftpFilenameCharsetExtensionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFilenameCharsetExtension_set_Charset(TElSftpFilenameCharsetExtensionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFilenameCharsetExtension_Create(TSBSftpExtendedAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPFILENAMECHARSETEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPVERSIONSELECTEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElSftpVersionSelectExtension_Assign(TElSftpVersionSelectExtensionHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVersionSelectExtension_LoadFromBuffer(TElSftpVersionSelectExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVersionSelectExtension_SaveToBuffer(TElSftpVersionSelectExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVersionSelectExtension_get_Version(TElSftpVersionSelectExtensionHandle _Handle, TSBSftpVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVersionSelectExtension_set_Version(TElSftpVersionSelectExtensionHandle _Handle, TSBSftpVersionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVersionSelectExtension_get_VersionInt(TElSftpVersionSelectExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVersionSelectExtension_set_VersionInt(TElSftpVersionSelectExtensionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVersionSelectExtension_get_VersionStr(TElSftpVersionSelectExtensionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVersionSelectExtension_set_VersionStr(TElSftpVersionSelectExtensionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVersionSelectExtension_Create(TSBSftpExtendedAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPVERSIONSELECTEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_Assign(TElSftpSupportedExtensionHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_Clear(TElSftpSupportedExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_FillDefault(TElSftpSupportedExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_LoadFromBuffer(TElSftpSupportedExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_SaveToBuffer(TElSftpSupportedExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_IsSupportedOpenBlockMode(TElSftpSupportedExtensionHandle _Handle, TSBSftpFileOpenAccessRaw Mode, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_SetSupportedOpenBlockMode(TElSftpSupportedExtensionHandle _Handle, TSBSftpFileOpenAccessRaw Mode, int8_t Supported);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_IsSupportedBlockMode(TElSftpSupportedExtensionHandle _Handle, TSBSftpFileOpenAccessRaw Mode, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_SetSupportedBlockMode(TElSftpSupportedExtensionHandle _Handle, TSBSftpFileOpenAccessRaw Mode, int8_t Supported);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_IsSupportedExtension(TElSftpSupportedExtensionHandle _Handle, const char * pcExtName, int32_t szExtName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_SetSupportedExtension(TElSftpSupportedExtensionHandle _Handle, const char * pcExtName, int32_t szExtName, int8_t Support);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_IsSupportedAttrExtension(TElSftpSupportedExtensionHandle _Handle, const char * pcExtName, int32_t szExtName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_SetSupportedAttrExtension(TElSftpSupportedExtensionHandle _Handle, const char * pcExtName, int32_t szExtName, int8_t Support);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_get_SupportedAttributes(TElSftpSupportedExtensionHandle _Handle, TSBSftpAttributesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_set_SupportedAttributes(TElSftpSupportedExtensionHandle _Handle, TSBSftpAttributesRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_get_SupportedAttribBits(TElSftpSupportedExtensionHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_set_SupportedAttribBits(TElSftpSupportedExtensionHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_get_SupportedOpenModes(TElSftpSupportedExtensionHandle _Handle, TSBSftpFileOpenModesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_set_SupportedOpenModes(TElSftpSupportedExtensionHandle _Handle, TSBSftpFileOpenModesRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_get_SupportedAccessModes(TElSftpSupportedExtensionHandle _Handle, TSBSftpFileOpenAccessRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_set_SupportedAccessModes(TElSftpSupportedExtensionHandle _Handle, TSBSftpFileOpenAccessRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_get_SupportedAccessMask(TElSftpSupportedExtensionHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_set_SupportedAccessMask(TElSftpSupportedExtensionHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_get_MaxReadSize(TElSftpSupportedExtensionHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_set_MaxReadSize(TElSftpSupportedExtensionHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_get_SupportedAttrExtensions(TElSftpSupportedExtensionHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_get_SupportedExtensions(TElSftpSupportedExtensionHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_get_Version(TElSftpSupportedExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_set_Version(TElSftpSupportedExtensionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSupportedExtension_Create(TElSftpSupportedExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPVENDORIDEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElSftpVendorIDExtension_Assign(TElSftpVendorIDExtensionHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVendorIDExtension_LoadFromBuffer(TElSftpVendorIDExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVendorIDExtension_SaveToBuffer(TElSftpVendorIDExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVendorIDExtension_get_VendorName(TElSftpVendorIDExtensionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVendorIDExtension_set_VendorName(TElSftpVendorIDExtensionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVendorIDExtension_get_ProductName(TElSftpVendorIDExtensionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVendorIDExtension_set_ProductName(TElSftpVendorIDExtensionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVendorIDExtension_get_ProductVersion(TElSftpVendorIDExtensionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVendorIDExtension_set_ProductVersion(TElSftpVendorIDExtensionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVendorIDExtension_get_BuildNumber(TElSftpVendorIDExtensionHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVendorIDExtension_set_BuildNumber(TElSftpVendorIDExtensionHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpVendorIDExtension_Create(TElSftpVendorIDExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPVENDORIDEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPCHECKFILEEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileExtension_Assign(TElSftpCheckFileExtensionHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileExtension_LoadFromBuffer(TElSftpCheckFileExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileExtension_SaveToBuffer(TElSftpCheckFileExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileExtension_get_Name(TElSftpCheckFileExtensionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileExtension_set_Name(TElSftpCheckFileExtensionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileExtension_get_Handle(TElSftpCheckFileExtensionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileExtension_set_Handle(TElSftpCheckFileExtensionHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileExtension_get_HashAlgorithms(TElSftpCheckFileExtensionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileExtension_set_HashAlgorithms(TElSftpCheckFileExtensionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileExtension_get_StartOffset(TElSftpCheckFileExtensionHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileExtension_set_StartOffset(TElSftpCheckFileExtensionHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileExtension_get_DataLength(TElSftpCheckFileExtensionHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileExtension_set_DataLength(TElSftpCheckFileExtensionHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileExtension_get_BlockSize(TElSftpCheckFileExtensionHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileExtension_set_BlockSize(TElSftpCheckFileExtensionHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileExtension_Create(TElSftpCheckFileExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPCHECKFILEEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPSTATVFSEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatvfsExtension_Assign(TElSftpStatvfsExtensionHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatvfsExtension_LoadFromBuffer(TElSftpStatvfsExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatvfsExtension_SaveToBuffer(TElSftpStatvfsExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatvfsExtension_get_Path(TElSftpStatvfsExtensionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatvfsExtension_set_Path(TElSftpStatvfsExtensionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatvfsExtension_Create(TSBSftpExtendedAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPSTATVFSEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPSPACEAVAILABLEEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableExtension_Assign(TElSftpSpaceAvailableExtensionHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableExtension_LoadFromBuffer(TElSftpSpaceAvailableExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableExtension_SaveToBuffer(TElSftpSpaceAvailableExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableExtension_get_Path(TElSftpSpaceAvailableExtensionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableExtension_set_Path(TElSftpSpaceAvailableExtensionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableExtension_Create(TSBSftpExtendedAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPSPACEAVAILABLEEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPHOMEDIRECTORYEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElSftpHomeDirectoryExtension_Assign(TElSftpHomeDirectoryExtensionHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSftpHomeDirectoryExtension_LoadFromBuffer(TElSftpHomeDirectoryExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpHomeDirectoryExtension_SaveToBuffer(TElSftpHomeDirectoryExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpHomeDirectoryExtension_get_Username(TElSftpHomeDirectoryExtensionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpHomeDirectoryExtension_set_Username(TElSftpHomeDirectoryExtensionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpHomeDirectoryExtension_Create(TSBSftpExtendedAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPHOMEDIRECTORYEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPCOPYFILEEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyFileExtension_Assign(TElSftpCopyFileExtensionHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyFileExtension_LoadFromBuffer(TElSftpCopyFileExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyFileExtension_SaveToBuffer(TElSftpCopyFileExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyFileExtension_get_Source(TElSftpCopyFileExtensionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyFileExtension_set_Source(TElSftpCopyFileExtensionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyFileExtension_get_Destination(TElSftpCopyFileExtensionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyFileExtension_set_Destination(TElSftpCopyFileExtensionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyFileExtension_get_Overwrite(TElSftpCopyFileExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyFileExtension_set_Overwrite(TElSftpCopyFileExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyFileExtension_Create(TSBSftpExtendedAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPCOPYFILEEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPCOPYDATAEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyDataExtension_Assign(TElSftpCopyDataExtensionHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyDataExtension_LoadFromBuffer(TElSftpCopyDataExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyDataExtension_SaveToBuffer(TElSftpCopyDataExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyDataExtension_get_ReadHandle(TElSftpCopyDataExtensionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyDataExtension_set_ReadHandle(TElSftpCopyDataExtensionHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyDataExtension_get_ReadOffset(TElSftpCopyDataExtensionHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyDataExtension_set_ReadOffset(TElSftpCopyDataExtensionHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyDataExtension_get_WriteHandle(TElSftpCopyDataExtensionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyDataExtension_set_WriteHandle(TElSftpCopyDataExtensionHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyDataExtension_get_WriteOffset(TElSftpCopyDataExtensionHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyDataExtension_set_WriteOffset(TElSftpCopyDataExtensionHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyDataExtension_get_DataLength(TElSftpCopyDataExtensionHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyDataExtension_set_DataLength(TElSftpCopyDataExtensionHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCopyDataExtension_Create(TSBSftpExtendedAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPCOPYDATAEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPCHECKFILEREPLY
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileReply_Assign(TElSftpCheckFileReplyHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileReply_AssignTo(TElSftpCheckFileReplyHandle _Handle, TPersistentHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileReply_LoadFromBuffer(TElSftpCheckFileReplyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileReply_SaveToBuffer(TElSftpCheckFileReplyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileReply_get_Hashes(TElSftpCheckFileReplyHandle _Handle, TElByteArrayListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileReply_get_HashAlgorithm(TElSftpCheckFileReplyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileReply_set_HashAlgorithm(TElSftpCheckFileReplyHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileReply_get_HashSize(TElSftpCheckFileReplyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpCheckFileReply_Create(TElSftpCheckFileReplyHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPCHECKFILEREPLY */

#ifdef SB_USE_CLASS_TELSFTPSPACEAVAILABLEREPLY
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableReply_Assign(TElSftpSpaceAvailableReplyHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableReply_AssignTo(TElSftpSpaceAvailableReplyHandle _Handle, TPersistentHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableReply_LoadFromBuffer(TElSftpSpaceAvailableReplyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableReply_SaveToBuffer(TElSftpSpaceAvailableReplyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableReply_get_BytesOnDevice(TElSftpSpaceAvailableReplyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableReply_set_BytesOnDevice(TElSftpSpaceAvailableReplyHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableReply_get_UnusedBytesOnDevice(TElSftpSpaceAvailableReplyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableReply_set_UnusedBytesOnDevice(TElSftpSpaceAvailableReplyHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableReply_get_BytesAvailableToUser(TElSftpSpaceAvailableReplyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableReply_set_BytesAvailableToUser(TElSftpSpaceAvailableReplyHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableReply_get_UnusedBytesAvailableToUser(TElSftpSpaceAvailableReplyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableReply_set_UnusedBytesAvailableToUser(TElSftpSpaceAvailableReplyHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableReply_get_BytesPerAllocationUnit(TElSftpSpaceAvailableReplyHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableReply_set_BytesPerAllocationUnit(TElSftpSpaceAvailableReplyHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpSpaceAvailableReply_Create(TElSftpExtendedReplyHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPSPACEAVAILABLEREPLY */

#ifdef SB_USE_CLASS_TELSFTPSTATVFSREPLY
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_Assign(TElSftpStatVFSReplyHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_AssignTo(TElSftpStatVFSReplyHandle _Handle, TPersistentHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_LoadFromBuffer(TElSftpStatVFSReplyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_SaveToBuffer(TElSftpStatVFSReplyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_get_BSize(TElSftpStatVFSReplyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_set_BSize(TElSftpStatVFSReplyHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_get_FRSize(TElSftpStatVFSReplyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_set_FRSize(TElSftpStatVFSReplyHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_get_Blocks(TElSftpStatVFSReplyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_set_Blocks(TElSftpStatVFSReplyHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_get_BFree(TElSftpStatVFSReplyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_set_BFree(TElSftpStatVFSReplyHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_get_BAvail(TElSftpStatVFSReplyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_set_BAvail(TElSftpStatVFSReplyHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_get_Files(TElSftpStatVFSReplyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_set_Files(TElSftpStatVFSReplyHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_get_FFree(TElSftpStatVFSReplyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_set_FFree(TElSftpStatVFSReplyHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_get_FAvail(TElSftpStatVFSReplyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_set_FAvail(TElSftpStatVFSReplyHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_get_FSid(TElSftpStatVFSReplyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_set_FSid(TElSftpStatVFSReplyHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_get_Flag(TElSftpStatVFSReplyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_set_Flag(TElSftpStatVFSReplyHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_get_Namemax(TElSftpStatVFSReplyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_set_Namemax(TElSftpStatVFSReplyHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpStatVFSReply_Create(TElSftpExtendedReplyHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPSTATVFSREPLY */

#ifdef SB_USE_CLASS_TSBSFTPACE
SB_IMPORT uint32_t SB_APIENTRY TSBSftpACE_get_ACEType(TSBSftpACEHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpACE_set_ACEType(TSBSftpACEHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpACE_get_ACEFlags(TSBSftpACEHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpACE_set_ACEFlags(TSBSftpACEHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpACE_get_ACEMask(TSBSftpACEHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpACE_set_ACEMask(TSBSftpACEHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpACE_get_Who(TSBSftpACEHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpACE_set_Who(TSBSftpACEHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TSBSftpACE_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TSBSFTPACE */

#ifdef SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_Assign(TElSftpExtendedPropertiesHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_AssignTo(TElSftpExtendedPropertiesHandle _Handle, TPersistentHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_RequestAttributesByVersion(TElSftpExtendedPropertiesHandle _Handle, int32_t Version, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_get_DesiredAccess(TElSftpExtendedPropertiesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_set_DesiredAccess(TElSftpExtendedPropertiesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_get_AutoAdjustDesiredAccess(TElSftpExtendedPropertiesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_set_AutoAdjustDesiredAccess(TElSftpExtendedPropertiesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_get_RenameFlags(TElSftpExtendedPropertiesHandle _Handle, TSBSftpRenameFlagsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_set_RenameFlags(TElSftpExtendedPropertiesHandle _Handle, TSBSftpRenameFlagsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_get_RenameFlagsUInt32(TElSftpExtendedPropertiesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_get_RequestAttributes(TElSftpExtendedPropertiesHandle _Handle, TSBSftpAttributesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_set_RequestAttributes(TElSftpExtendedPropertiesHandle _Handle, TSBSftpAttributesRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_get_RequestAttributesUInt32(TElSftpExtendedPropertiesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_get_AutoAdjustRequestAttributes(TElSftpExtendedPropertiesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_set_AutoAdjustRequestAttributes(TElSftpExtendedPropertiesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_get_SupportedAvailable(TElSftpExtendedPropertiesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_set_SupportedAvailable(TElSftpExtendedPropertiesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_get_SupportedExtension(TElSftpExtendedPropertiesHandle _Handle, TElSftpSupportedExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_set_SupportedExtension(TElSftpExtendedPropertiesHandle _Handle, TElSftpSupportedExtensionHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_get_NewlineAvailable(TElSftpExtendedPropertiesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_set_NewlineAvailable(TElSftpExtendedPropertiesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_get_NewlineExtension(TElSftpExtendedPropertiesHandle _Handle, TElSftpNewlineExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_set_NewlineExtension(TElSftpExtendedPropertiesHandle _Handle, TElSftpNewlineExtensionHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_get_VersionsAvailable(TElSftpExtendedPropertiesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_set_VersionsAvailable(TElSftpExtendedPropertiesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_get_VersionsExtension(TElSftpExtendedPropertiesHandle _Handle, TElSftpVersionsExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_set_VersionsExtension(TElSftpExtendedPropertiesHandle _Handle, TElSftpVersionsExtensionHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_get_VendorIDAvailable(TElSftpExtendedPropertiesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_set_VendorIDAvailable(TElSftpExtendedPropertiesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_get_VendorIDExtension(TElSftpExtendedPropertiesHandle _Handle, TElSftpVendorIDExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_set_VendorIDExtension(TElSftpExtendedPropertiesHandle _Handle, TElSftpVendorIDExtensionHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_get_FilenameCharset(TElSftpExtendedPropertiesHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_set_FilenameCharset(TElSftpExtendedPropertiesHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpExtendedProperties_Create(TElSftpExtendedPropertiesHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_CopyTo(TElSftpFileAttributesHandle _Handle, TElSftpFileAttributesHandle dst);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_SaveToBuffer(TElSftpFileAttributesHandle _Handle, int32_t Ver, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_LoadFromBuffer(TElSftpFileAttributesHandle _Handle, void * Buffer, int32_t Size, int32_t Ver, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_AddACE(TElSftpFileAttributesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_RemoveACE(TElSftpFileAttributesHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_ClearACEs(TElSftpFileAttributesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_AddExtendedAttribute(TElSftpFileAttributesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_RemoveExtendedAttribute(TElSftpFileAttributesHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_ClearExtendedAttributes(TElSftpFileAttributesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_IsAttributeIncluded(TElSftpFileAttributesHandle _Handle, TSBSftpAttributeRaw Attribute, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_Size(TElSftpFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_Size(TElSftpFileAttributesHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_AllocationSize(TElSftpFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_AllocationSize(TElSftpFileAttributesHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_UID(TElSftpFileAttributesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_UID(TElSftpFileAttributesHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_GID(TElSftpFileAttributesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_GID(TElSftpFileAttributesHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_Owner(TElSftpFileAttributesHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_Owner(TElSftpFileAttributesHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_Group(TElSftpFileAttributesHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_Group(TElSftpFileAttributesHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_CTime(TElSftpFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_CTime(TElSftpFileAttributesHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_CATime(TElSftpFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_CATime(TElSftpFileAttributesHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_FileType(TElSftpFileAttributesHandle _Handle, TSBSftpFileTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_FileType(TElSftpFileAttributesHandle _Handle, TSBSftpFileTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_ATime(TElSftpFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_ATime(TElSftpFileAttributesHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_MTime(TElSftpFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_MTime(TElSftpFileAttributesHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_ExtendedAttributeCount(TElSftpFileAttributesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_ExtendedAttributes(TElSftpFileAttributesHandle _Handle, int32_t Index, TSBSftpExtendedAttributeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_IncludedAttributes(TElSftpFileAttributesHandle _Handle, TSBSftpAttributesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_IncludedAttributes(TElSftpFileAttributesHandle _Handle, TSBSftpAttributesRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_UserRead(TElSftpFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_UserRead(TElSftpFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_UserWrite(TElSftpFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_UserWrite(TElSftpFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_UserExecute(TElSftpFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_UserExecute(TElSftpFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_GroupRead(TElSftpFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_GroupRead(TElSftpFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_GroupWrite(TElSftpFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_GroupWrite(TElSftpFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_GroupExecute(TElSftpFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_GroupExecute(TElSftpFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_OtherRead(TElSftpFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_OtherRead(TElSftpFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_OtherWrite(TElSftpFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_OtherWrite(TElSftpFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_OtherExecute(TElSftpFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_OtherExecute(TElSftpFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_UIDBit(TElSftpFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_UIDBit(TElSftpFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_GIDBit(TElSftpFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_GIDBit(TElSftpFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_StickyBit(TElSftpFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_StickyBit(TElSftpFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_Directory(TElSftpFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_Directory(TElSftpFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_ACLFlags(TElSftpFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_ACLFlags(TElSftpFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_ACECount(TElSftpFileAttributesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_ACEs(TElSftpFileAttributesHandle _Handle, int32_t Index, TSBSftpACEHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_ATimeInt64(TElSftpFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_ATimeInt64(TElSftpFileAttributesHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_MTimeInt64(TElSftpFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_MTimeInt64(TElSftpFileAttributesHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_CTimeInt64(TElSftpFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_CTimeInt64(TElSftpFileAttributesHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_CATimeInt64(TElSftpFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_CATimeInt64(TElSftpFileAttributesHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_ATimeCardinal(TElSftpFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_ATimeCardinal(TElSftpFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_MTimeCardinal(TElSftpFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_MTimeCardinal(TElSftpFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_CTimeCardinal(TElSftpFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_CTimeCardinal(TElSftpFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_CATimeCardinal(TElSftpFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_CATimeCardinal(TElSftpFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_ATimeSeconds(TElSftpFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_MTimeSeconds(TElSftpFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_CTimeSeconds(TElSftpFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_CATimeSeconds(TElSftpFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_ATimeMS(TElSftpFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_ATimeMS(TElSftpFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_CTimeMS(TElSftpFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_CTimeMS(TElSftpFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_CATimeMS(TElSftpFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_CATimeMS(TElSftpFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_MTimeMS(TElSftpFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_MTimeMS(TElSftpFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_AttribBits(TElSftpFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_AttribBits(TElSftpFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_AttribBitsValid(TElSftpFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_AttribBitsValid(TElSftpFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_FileTypeByte(TElSftpFileAttributesHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_FileTypeByte(TElSftpFileAttributesHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_Permissions(TElSftpFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_Permissions(TElSftpFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_TextHint(TElSftpFileAttributesHandle _Handle, TSBSftpTextHintRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_TextHint(TElSftpFileAttributesHandle _Handle, TSBSftpTextHintRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_MimeType(TElSftpFileAttributesHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_MimeType(TElSftpFileAttributesHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_LinkCount(TElSftpFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_LinkCount(TElSftpFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_get_UntranslatedName(TElSftpFileAttributesHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_set_UntranslatedName(TElSftpFileAttributesHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileAttributes_Create(TElSftpFileAttributesHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEINFO
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileInfo_CopyTo(TElSftpFileInfoHandle _Handle, TElSftpFileInfoHandle FileInfo);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileInfo_get_Name(TElSftpFileInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileInfo_set_Name(TElSftpFileInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileInfo_get_LongName(TElSftpFileInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileInfo_set_LongName(TElSftpFileInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileInfo_get_Path(TElSftpFileInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileInfo_set_Path(TElSftpFileInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileInfo_get_Attributes(TElSftpFileInfoHandle _Handle, TElSftpFileAttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpFileInfo_Create(TElSftpFileInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPFILEINFO */

#ifdef SB_USE_CLASS_TSBSFTPOPENREQUESTINFO
SB_IMPORT uint32_t SB_APIENTRY TSBSftpOpenRequestInfo_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TSBSFTPOPENREQUESTINFO */

#ifdef SB_USE_CLASS_TSBSFTPTEXTHANDLEINFO
SB_IMPORT uint32_t SB_APIENTRY TSBSftpTextHandleInfo_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TSBSFTPTEXTHANDLEINFO */

#ifdef SB_USE_CLASS_TELSFTPTRANSFERBLOCK
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferBlock_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPTRANSFERBLOCK */

#ifdef SB_USE_CLASS_TELSFTPTRANSFERMANAGER
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_Run(TElSftpTransferManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_ProcessData(TElSftpTransferManagerHandle _Handle, uint32_t Id, void * Buffer, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_ProcessStatus(TElSftpTransferManagerHandle _Handle, uint32_t Id, int32_t StatusCode, const char * pcComment, int32_t szComment, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_OperationFinished(TElSftpTransferManagerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_Terminate(TElSftpTransferManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_get_Direction(TElSftpTransferManagerHandle _Handle, TSBSftpTransferDirectionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_get_Received(TElSftpTransferManagerHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_get_Handle(TElSftpTransferManagerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_get_TextMode(TElSftpTransferManagerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_get_LastError(TElSftpTransferManagerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_get_LastComment(TElSftpTransferManagerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_get_OnData(TElSftpTransferManagerHandle _Handle, TSBSftpDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_set_OnData(TElSftpTransferManagerHandle _Handle, TSBSftpDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_get_OnASCIIData(TElSftpTransferManagerHandle _Handle, TSBSftpDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_set_OnASCIIData(TElSftpTransferManagerHandle _Handle, TSBSftpDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_get_OnReadRequest(TElSftpTransferManagerHandle _Handle, TSBSftpReadRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_set_OnReadRequest(TElSftpTransferManagerHandle _Handle, TSBSftpReadRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_get_OnWriteRequest(TElSftpTransferManagerHandle _Handle, TSBSftpWriteRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_set_OnWriteRequest(TElSftpTransferManagerHandle _Handle, TSBSftpWriteRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_get_OnFinish(TElSftpTransferManagerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_set_OnFinish(TElSftpTransferManagerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_get_OnProgress(TElSftpTransferManagerHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_set_OnProgress(TElSftpTransferManagerHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpTransferManager_Create(const uint8_t pHandle[], int32_t szHandle, int64_t Offset, void * Buffer, int32_t Size, int32_t ChunkSize, int32_t MaxActiveCount, TSBSftpTransferDirectionRaw Direction, int8_t TextMode, TElSftpTransferManagerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPTRANSFERMANAGER */

#ifdef SB_USE_CLASS_TELSFTPREMOVALTARGET
SB_IMPORT uint32_t SB_APIENTRY TElSftpRemovalTarget_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPREMOVALTARGET */

#ifdef SB_USE_CLASS_TELSFTPREMOVALMANAGER
SB_IMPORT uint32_t SB_APIENTRY TElSftpRemovalManager_Run(TElSftpRemovalManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpRemovalManager_ProcessStatus(TElSftpRemovalManagerHandle _Handle, uint32_t Id, int32_t StatusCode, const char * pcErrorMsg, int32_t szErrorMsg, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpRemovalManager_OperationFinished(TElSftpRemovalManagerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpRemovalManager_Terminate(TElSftpRemovalManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSftpRemovalManager_get_ErrorList(TElSftpRemovalManagerHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpRemovalManager_get_ErrorFilenames(TElSftpRemovalManagerHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpRemovalManager_get_OnFinish(TElSftpRemovalManagerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpRemovalManager_set_OnFinish(TElSftpRemovalManagerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpRemovalManager_get_OnProgress(TElSftpRemovalManagerHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpRemovalManager_set_OnProgress(TElSftpRemovalManagerHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpRemovalManager_get_OnRemovalRequest(TElSftpRemovalManagerHandle _Handle, TSBSftpRemovalRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSftpRemovalManager_set_OnRemovalRequest(TElSftpRemovalManagerHandle _Handle, TSBSftpRemovalRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSftpRemovalManager_Create(TStringsHandle Filenames, int32_t MaxActiveCount, TElSftpRemovalManagerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSFTPREMOVALMANAGER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TSBSftpExtendedAttribute;
class TElSftpExtendedReply;
typedef TElSftpExtendedReply ElSftpExtendedReply;
class TElSftpNewlineExtension;
typedef TElSftpNewlineExtension ElSftpNewlineExtension;
class TElSftpVersionsExtension;
typedef TElSftpVersionsExtension ElSftpVersionsExtension;
class TElSftpFilenameTranslationExtension;
typedef TElSftpFilenameTranslationExtension ElSftpFilenameTranslationExtension;
class TElSftpFilenameCharsetExtension;
typedef TElSftpFilenameCharsetExtension ElSftpFilenameCharsetExtension;
class TElSftpVersionSelectExtension;
typedef TElSftpVersionSelectExtension ElSftpVersionSelectExtension;
class TElSftpSupportedExtension;
typedef TElSftpSupportedExtension ElSftpSupportedExtension;
class TElSftpVendorIDExtension;
typedef TElSftpVendorIDExtension ElSftpVendorIDExtension;
class TElSftpCheckFileExtension;
typedef TElSftpCheckFileExtension ElSftpCheckFileExtension;
class TElSftpStatvfsExtension;
typedef TElSftpStatvfsExtension ElSftpStatvfsExtension;
class TElSftpSpaceAvailableExtension;
typedef TElSftpSpaceAvailableExtension ElSftpSpaceAvailableExtension;
class TElSftpHomeDirectoryExtension;
typedef TElSftpHomeDirectoryExtension ElSftpHomeDirectoryExtension;
class TElSftpCopyFileExtension;
typedef TElSftpCopyFileExtension ElSftpCopyFileExtension;
class TElSftpCopyDataExtension;
typedef TElSftpCopyDataExtension ElSftpCopyDataExtension;
class TElSftpCheckFileReply;
typedef TElSftpCheckFileReply ElSftpCheckFileReply;
class TElSftpSpaceAvailableReply;
typedef TElSftpSpaceAvailableReply ElSftpSpaceAvailableReply;
class TElSftpStatVFSReply;
typedef TElSftpStatVFSReply ElSftpStatVFSReply;
class TSBSftpACE;
class TElSftpExtendedProperties;
typedef TElSftpExtendedProperties ElSftpExtendedProperties;
class TElSftpFileAttributes;
typedef TElSftpFileAttributes ElSftpFileAttributes;
class TElSftpFileInfo;
typedef TElSftpFileInfo ElSftpFileInfo;
class TSBSftpOpenRequestInfo;
class TSBSftpTextHandleInfo;
class TElSftpTransferBlock;
typedef TElSftpTransferBlock ElSftpTransferBlock;
class TElSftpTransferManager;
typedef TElSftpTransferManager ElSftpTransferManager;
class TElSftpRemovalTarget;
class TElSftpRemovalManager;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBSftpFileOpenModes)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBSftpFileOpenAccess)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBSftpVersions)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBSftpAttributes)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBSftpRenameFlags)

#ifdef SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE
class TSBSftpExtendedAttribute: public TPersistent
{
	private:
		SB_DISABLE_COPY(TSBSftpExtendedAttribute)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void AssignTo(TPersistent &Dest);

		virtual void AssignTo(TPersistent *Dest);

		virtual bool LoadFromBuffer();

		virtual void SaveToBuffer();

		void Write(std::vector<uint8_t> &OutResult);

		virtual void get_ExtType(std::vector<uint8_t> &OutResult);

		virtual void set_ExtType(const std::vector<uint8_t> &Value);

		virtual void get_ExtData(std::vector<uint8_t> &OutResult);

		virtual void set_ExtData(const std::vector<uint8_t> &Value);

		virtual bool get_UseUTF8();

		virtual void set_UseUTF8(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUTF8, set_UseUTF8, TSBSftpExtendedAttribute, UseUTF8);

		virtual bool get_NoCharacterEncoding();

		virtual void set_NoCharacterEncoding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_NoCharacterEncoding, set_NoCharacterEncoding, TSBSftpExtendedAttribute, NoCharacterEncoding);

		virtual void get_LocalCharset(std::string &OutResult);

		virtual void set_LocalCharset(const std::string &Value);

		virtual void get_RemoteCharset(std::string &OutResult);

		virtual void set_RemoteCharset(const std::string &Value);

		TSBSftpExtendedAttribute(TSBSftpExtendedAttributeHandle handle, TElOwnHandle ownHandle);

		TSBSftpExtendedAttribute();

};
#endif /* SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE */

#ifdef SB_USE_CLASS_TELSFTPEXTENDEDREPLY
class TElSftpExtendedReply: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElSftpExtendedReply)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void AssignTo(TPersistent &Dest);

		virtual void AssignTo(TPersistent *Dest);

		virtual bool LoadFromBuffer();

		virtual void SaveToBuffer();

		void Write(std::vector<uint8_t> &OutResult);

		virtual bool get_UseUTF8();

		virtual void set_UseUTF8(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUTF8, set_UseUTF8, TElSftpExtendedReply, UseUTF8);

		virtual bool get_NoCharacterEncoding();

		virtual void set_NoCharacterEncoding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_NoCharacterEncoding, set_NoCharacterEncoding, TElSftpExtendedReply, NoCharacterEncoding);

		virtual void get_LocalCharset(std::string &OutResult);

		virtual void set_LocalCharset(const std::string &Value);

		virtual void get_RemoteCharset(std::string &OutResult);

		virtual void set_RemoteCharset(const std::string &Value);

		virtual void get_ReplyData(std::vector<uint8_t> &OutResult);

		virtual void set_ReplyData(const std::vector<uint8_t> &Value);

		TElSftpExtendedReply(TElSftpExtendedReplyHandle handle, TElOwnHandle ownHandle);

		TElSftpExtendedReply();

};
#endif /* SB_USE_CLASS_TELSFTPEXTENDEDREPLY */

#ifdef SB_USE_CLASS_TELSFTPNEWLINEEXTENSION
class TElSftpNewlineExtension: public TSBSftpExtendedAttribute
{
	private:
		SB_DISABLE_COPY(TElSftpNewlineExtension)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual bool LoadFromBuffer();

		virtual void SaveToBuffer();

		virtual void get_Newline(std::vector<uint8_t> &OutResult);

		virtual void set_Newline(const std::vector<uint8_t> &Value);

		TElSftpNewlineExtension(TElSftpNewlineExtensionHandle handle, TElOwnHandle ownHandle);

		TElSftpNewlineExtension();

};
#endif /* SB_USE_CLASS_TELSFTPNEWLINEEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPVERSIONSEXTENSION
class TElSftpVersionsExtension: public TSBSftpExtendedAttribute
{
	private:
		SB_DISABLE_COPY(TElSftpVersionsExtension)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual bool LoadFromBuffer();

		virtual void SaveToBuffer();

		virtual TSBSftpVersions get_Versions();

		virtual void set_Versions(TSBSftpVersions Value);

		SB_DECLARE_PROPERTY(TSBSftpVersions, get_Versions, set_Versions, TElSftpVersionsExtension, Versions);

		virtual void get_VersionsStr(std::string &OutResult);

		TElSftpVersionsExtension(TElSftpVersionsExtensionHandle handle, TElOwnHandle ownHandle);

		TElSftpVersionsExtension();

};
#endif /* SB_USE_CLASS_TELSFTPVERSIONSEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPFILENAMETRANSLATIONEXTENSION
class TElSftpFilenameTranslationExtension: public TSBSftpExtendedAttribute
{
	private:
		SB_DISABLE_COPY(TElSftpFilenameTranslationExtension)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual bool LoadFromBuffer();

		virtual void SaveToBuffer();

		virtual bool get_DoTranslate();

		virtual void set_DoTranslate(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DoTranslate, set_DoTranslate, TElSftpFilenameTranslationExtension, DoTranslate);

		TElSftpFilenameTranslationExtension(TElSftpFilenameTranslationExtensionHandle handle, TElOwnHandle ownHandle);

		TElSftpFilenameTranslationExtension();

};
#endif /* SB_USE_CLASS_TELSFTPFILENAMETRANSLATIONEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPFILENAMECHARSETEXTENSION
class TElSftpFilenameCharsetExtension: public TSBSftpExtendedAttribute
{
	private:
		SB_DISABLE_COPY(TElSftpFilenameCharsetExtension)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual bool LoadFromBuffer();

		virtual void SaveToBuffer();

		virtual void get_Charset(std::string &OutResult);

		virtual void set_Charset(const std::string &Value);

		TElSftpFilenameCharsetExtension(TElSftpFilenameCharsetExtensionHandle handle, TElOwnHandle ownHandle);

		TElSftpFilenameCharsetExtension();

};
#endif /* SB_USE_CLASS_TELSFTPFILENAMECHARSETEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPVERSIONSELECTEXTENSION
class TElSftpVersionSelectExtension: public TSBSftpExtendedAttribute
{
	private:
		SB_DISABLE_COPY(TElSftpVersionSelectExtension)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual bool LoadFromBuffer();

		virtual void SaveToBuffer();

		virtual TSBSftpVersion get_Version();

		virtual void set_Version(TSBSftpVersion Value);

		SB_DECLARE_PROPERTY(TSBSftpVersion, get_Version, set_Version, TElSftpVersionSelectExtension, Version);

		virtual int32_t get_VersionInt();

		virtual void set_VersionInt(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_VersionInt, set_VersionInt, TElSftpVersionSelectExtension, VersionInt);

		virtual void get_VersionStr(std::string &OutResult);

		virtual void set_VersionStr(const std::string &Value);

		TElSftpVersionSelectExtension(TElSftpVersionSelectExtensionHandle handle, TElOwnHandle ownHandle);

		TElSftpVersionSelectExtension();

};
#endif /* SB_USE_CLASS_TELSFTPVERSIONSELECTEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION
class TElSftpSupportedExtension: public TSBSftpExtendedAttribute
{
	private:
		SB_DISABLE_COPY(TElSftpSupportedExtension)
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_SupportedAttrExtensions;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_SupportedExtensions;
#endif /* SB_USE_CLASS_TSTRINGLIST */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		void Clear();

		void FillDefault();

		virtual bool LoadFromBuffer();

		virtual void SaveToBuffer();

		bool IsSupportedOpenBlockMode(TSBSftpFileOpenAccess Mode);

		void SetSupportedOpenBlockMode(TSBSftpFileOpenAccess Mode, bool Supported);

		bool IsSupportedBlockMode(TSBSftpFileOpenAccess Mode);

		void SetSupportedBlockMode(TSBSftpFileOpenAccess Mode, bool Supported);

		bool IsSupportedExtension(const std::string &ExtName);

		void SetSupportedExtension(const std::string &ExtName, bool Support);

		bool IsSupportedAttrExtension(const std::string &ExtName);

		void SetSupportedAttrExtension(const std::string &ExtName, bool Support);

		virtual TSBSftpAttributes get_SupportedAttributes();

		virtual void set_SupportedAttributes(TSBSftpAttributes Value);

		SB_DECLARE_PROPERTY(TSBSftpAttributes, get_SupportedAttributes, set_SupportedAttributes, TElSftpSupportedExtension, SupportedAttributes);

		virtual uint32_t get_SupportedAttribBits();

		virtual void set_SupportedAttribBits(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_SupportedAttribBits, set_SupportedAttribBits, TElSftpSupportedExtension, SupportedAttribBits);

		virtual TSBSftpFileOpenModes get_SupportedOpenModes();

		virtual void set_SupportedOpenModes(TSBSftpFileOpenModes Value);

		SB_DECLARE_PROPERTY(TSBSftpFileOpenModes, get_SupportedOpenModes, set_SupportedOpenModes, TElSftpSupportedExtension, SupportedOpenModes);

		virtual TSBSftpFileOpenAccess get_SupportedAccessModes();

		virtual void set_SupportedAccessModes(TSBSftpFileOpenAccess Value);

		SB_DECLARE_PROPERTY(TSBSftpFileOpenAccess, get_SupportedAccessModes, set_SupportedAccessModes, TElSftpSupportedExtension, SupportedAccessModes);

		virtual uint32_t get_SupportedAccessMask();

		virtual void set_SupportedAccessMask(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_SupportedAccessMask, set_SupportedAccessMask, TElSftpSupportedExtension, SupportedAccessMask);

		virtual uint32_t get_MaxReadSize();

		virtual void set_MaxReadSize(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_MaxReadSize, set_MaxReadSize, TElSftpSupportedExtension, MaxReadSize);

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_SupportedAttrExtensions();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_SupportedAttrExtensions, TElSftpSupportedExtension, SupportedAttrExtensions);
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_SupportedExtensions();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_SupportedExtensions, TElSftpSupportedExtension, SupportedExtensions);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		virtual int32_t get_Version();

		virtual void set_Version(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Version, set_Version, TElSftpSupportedExtension, Version);

		TElSftpSupportedExtension(TElSftpSupportedExtensionHandle handle, TElOwnHandle ownHandle);

		TElSftpSupportedExtension();

		virtual ~TElSftpSupportedExtension();

};
#endif /* SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPVENDORIDEXTENSION
class TElSftpVendorIDExtension: public TSBSftpExtendedAttribute
{
	private:
		SB_DISABLE_COPY(TElSftpVendorIDExtension)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual bool LoadFromBuffer();

		virtual void SaveToBuffer();

		virtual void get_VendorName(std::string &OutResult);

		virtual void set_VendorName(const std::string &Value);

		virtual void get_ProductName(std::string &OutResult);

		virtual void set_ProductName(const std::string &Value);

		virtual void get_ProductVersion(std::string &OutResult);

		virtual void set_ProductVersion(const std::string &Value);

		virtual int64_t get_BuildNumber();

		virtual void set_BuildNumber(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_BuildNumber, set_BuildNumber, TElSftpVendorIDExtension, BuildNumber);

		TElSftpVendorIDExtension(TElSftpVendorIDExtensionHandle handle, TElOwnHandle ownHandle);

		TElSftpVendorIDExtension();

};
#endif /* SB_USE_CLASS_TELSFTPVENDORIDEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPCHECKFILEEXTENSION
class TElSftpCheckFileExtension: public TSBSftpExtendedAttribute
{
	private:
		SB_DISABLE_COPY(TElSftpCheckFileExtension)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual bool LoadFromBuffer();

		virtual void SaveToBuffer();

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual void get_Handle(std::vector<uint8_t> &OutResult);

		virtual void set_Handle(const std::vector<uint8_t> &Value);

		virtual void get_HashAlgorithms(std::string &OutResult);

		virtual void set_HashAlgorithms(const std::string &Value);

		virtual int64_t get_StartOffset();

		virtual void set_StartOffset(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_StartOffset, set_StartOffset, TElSftpCheckFileExtension, StartOffset);

		virtual int64_t get_DataLength();

		virtual void set_DataLength(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_DataLength, set_DataLength, TElSftpCheckFileExtension, DataLength);

		virtual uint32_t get_BlockSize();

		virtual void set_BlockSize(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_BlockSize, set_BlockSize, TElSftpCheckFileExtension, BlockSize);

		TElSftpCheckFileExtension(TElSftpCheckFileExtensionHandle handle, TElOwnHandle ownHandle);

		TElSftpCheckFileExtension();

};
#endif /* SB_USE_CLASS_TELSFTPCHECKFILEEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPSTATVFSEXTENSION
class TElSftpStatvfsExtension: public TSBSftpExtendedAttribute
{
	private:
		SB_DISABLE_COPY(TElSftpStatvfsExtension)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual bool LoadFromBuffer();

		virtual void SaveToBuffer();

		virtual void get_Path(std::string &OutResult);

		virtual void set_Path(const std::string &Value);

		TElSftpStatvfsExtension(TElSftpStatvfsExtensionHandle handle, TElOwnHandle ownHandle);

		TElSftpStatvfsExtension();

};
#endif /* SB_USE_CLASS_TELSFTPSTATVFSEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPSPACEAVAILABLEEXTENSION
class TElSftpSpaceAvailableExtension: public TSBSftpExtendedAttribute
{
	private:
		SB_DISABLE_COPY(TElSftpSpaceAvailableExtension)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual bool LoadFromBuffer();

		virtual void SaveToBuffer();

		virtual void get_Path(std::string &OutResult);

		virtual void set_Path(const std::string &Value);

		TElSftpSpaceAvailableExtension(TElSftpSpaceAvailableExtensionHandle handle, TElOwnHandle ownHandle);

		TElSftpSpaceAvailableExtension();

};
#endif /* SB_USE_CLASS_TELSFTPSPACEAVAILABLEEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPHOMEDIRECTORYEXTENSION
class TElSftpHomeDirectoryExtension: public TSBSftpExtendedAttribute
{
	private:
		SB_DISABLE_COPY(TElSftpHomeDirectoryExtension)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual bool LoadFromBuffer();

		virtual void SaveToBuffer();

		virtual void get_Username(std::string &OutResult);

		virtual void set_Username(const std::string &Value);

		TElSftpHomeDirectoryExtension(TElSftpHomeDirectoryExtensionHandle handle, TElOwnHandle ownHandle);

		TElSftpHomeDirectoryExtension();

};
#endif /* SB_USE_CLASS_TELSFTPHOMEDIRECTORYEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPCOPYFILEEXTENSION
class TElSftpCopyFileExtension: public TSBSftpExtendedAttribute
{
	private:
		SB_DISABLE_COPY(TElSftpCopyFileExtension)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual bool LoadFromBuffer();

		virtual void SaveToBuffer();

		virtual void get_Source(std::string &OutResult);

		virtual void set_Source(const std::string &Value);

		virtual void get_Destination(std::string &OutResult);

		virtual void set_Destination(const std::string &Value);

		virtual bool get_Overwrite();

		virtual void set_Overwrite(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Overwrite, set_Overwrite, TElSftpCopyFileExtension, Overwrite);

		TElSftpCopyFileExtension(TElSftpCopyFileExtensionHandle handle, TElOwnHandle ownHandle);

		TElSftpCopyFileExtension();

};
#endif /* SB_USE_CLASS_TELSFTPCOPYFILEEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPCOPYDATAEXTENSION
class TElSftpCopyDataExtension: public TSBSftpExtendedAttribute
{
	private:
		SB_DISABLE_COPY(TElSftpCopyDataExtension)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual bool LoadFromBuffer();

		virtual void SaveToBuffer();

		virtual void get_ReadHandle(std::vector<uint8_t> &OutResult);

		virtual void set_ReadHandle(const std::vector<uint8_t> &Value);

		virtual int64_t get_ReadOffset();

		virtual void set_ReadOffset(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ReadOffset, set_ReadOffset, TElSftpCopyDataExtension, ReadOffset);

		virtual void get_WriteHandle(std::vector<uint8_t> &OutResult);

		virtual void set_WriteHandle(const std::vector<uint8_t> &Value);

		virtual int64_t get_WriteOffset();

		virtual void set_WriteOffset(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_WriteOffset, set_WriteOffset, TElSftpCopyDataExtension, WriteOffset);

		virtual int64_t get_DataLength();

		virtual void set_DataLength(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_DataLength, set_DataLength, TElSftpCopyDataExtension, DataLength);

		TElSftpCopyDataExtension(TElSftpCopyDataExtensionHandle handle, TElOwnHandle ownHandle);

		TElSftpCopyDataExtension();

};
#endif /* SB_USE_CLASS_TELSFTPCOPYDATAEXTENSION */

#ifdef SB_USE_CLASS_TELSFTPCHECKFILEREPLY
class TElSftpCheckFileReply: public TElSftpExtendedReply
{
	private:
		SB_DISABLE_COPY(TElSftpCheckFileReply)
#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
		TElByteArrayList* _Inst_Hashes;
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void AssignTo(TPersistent &Dest);

		virtual void AssignTo(TPersistent *Dest);

		virtual bool LoadFromBuffer();

		virtual void SaveToBuffer();

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
		virtual TElByteArrayList* get_Hashes();

		SB_DECLARE_PROPERTY_GET(TElByteArrayList*, get_Hashes, TElSftpCheckFileReply, Hashes);
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElSftpCheckFileReply, HashAlgorithm);

		virtual int32_t get_HashSize();

		SB_DECLARE_PROPERTY_GET(int32_t, get_HashSize, TElSftpCheckFileReply, HashSize);

		TElSftpCheckFileReply(TElSftpCheckFileReplyHandle handle, TElOwnHandle ownHandle);

		TElSftpCheckFileReply();

		virtual ~TElSftpCheckFileReply();

};
#endif /* SB_USE_CLASS_TELSFTPCHECKFILEREPLY */

#ifdef SB_USE_CLASS_TELSFTPSPACEAVAILABLEREPLY
class TElSftpSpaceAvailableReply: public TElSftpExtendedReply
{
	private:
		SB_DISABLE_COPY(TElSftpSpaceAvailableReply)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void AssignTo(TPersistent &Dest);

		virtual void AssignTo(TPersistent *Dest);

		virtual bool LoadFromBuffer();

		virtual void SaveToBuffer();

		virtual int64_t get_BytesOnDevice();

		virtual void set_BytesOnDevice(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_BytesOnDevice, set_BytesOnDevice, TElSftpSpaceAvailableReply, BytesOnDevice);

		virtual int64_t get_UnusedBytesOnDevice();

		virtual void set_UnusedBytesOnDevice(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_UnusedBytesOnDevice, set_UnusedBytesOnDevice, TElSftpSpaceAvailableReply, UnusedBytesOnDevice);

		virtual int64_t get_BytesAvailableToUser();

		virtual void set_BytesAvailableToUser(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_BytesAvailableToUser, set_BytesAvailableToUser, TElSftpSpaceAvailableReply, BytesAvailableToUser);

		virtual int64_t get_UnusedBytesAvailableToUser();

		virtual void set_UnusedBytesAvailableToUser(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_UnusedBytesAvailableToUser, set_UnusedBytesAvailableToUser, TElSftpSpaceAvailableReply, UnusedBytesAvailableToUser);

		virtual uint32_t get_BytesPerAllocationUnit();

		virtual void set_BytesPerAllocationUnit(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_BytesPerAllocationUnit, set_BytesPerAllocationUnit, TElSftpSpaceAvailableReply, BytesPerAllocationUnit);

		TElSftpSpaceAvailableReply(TElSftpSpaceAvailableReplyHandle handle, TElOwnHandle ownHandle);

		TElSftpSpaceAvailableReply();

};
#endif /* SB_USE_CLASS_TELSFTPSPACEAVAILABLEREPLY */

#ifdef SB_USE_CLASS_TELSFTPSTATVFSREPLY
class TElSftpStatVFSReply: public TElSftpExtendedReply
{
	private:
		SB_DISABLE_COPY(TElSftpStatVFSReply)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void AssignTo(TPersistent &Dest);

		virtual void AssignTo(TPersistent *Dest);

		virtual bool LoadFromBuffer();

		virtual void SaveToBuffer();

		virtual int64_t get_BSize();

		virtual void set_BSize(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_BSize, set_BSize, TElSftpStatVFSReply, BSize);

		virtual int64_t get_FRSize();

		virtual void set_FRSize(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_FRSize, set_FRSize, TElSftpStatVFSReply, FRSize);

		virtual int64_t get_Blocks();

		virtual void set_Blocks(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Blocks, set_Blocks, TElSftpStatVFSReply, Blocks);

		virtual int64_t get_BFree();

		virtual void set_BFree(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_BFree, set_BFree, TElSftpStatVFSReply, BFree);

		virtual int64_t get_BAvail();

		virtual void set_BAvail(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_BAvail, set_BAvail, TElSftpStatVFSReply, BAvail);

		virtual int64_t get_Files();

		virtual void set_Files(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Files, set_Files, TElSftpStatVFSReply, Files);

		virtual int64_t get_FFree();

		virtual void set_FFree(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_FFree, set_FFree, TElSftpStatVFSReply, FFree);

		virtual int64_t get_FAvail();

		virtual void set_FAvail(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_FAvail, set_FAvail, TElSftpStatVFSReply, FAvail);

		virtual int64_t get_FSid();

		virtual void set_FSid(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_FSid, set_FSid, TElSftpStatVFSReply, FSid);

		virtual int64_t get_Flag();

		virtual void set_Flag(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Flag, set_Flag, TElSftpStatVFSReply, Flag);

		virtual int64_t get_Namemax();

		virtual void set_Namemax(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Namemax, set_Namemax, TElSftpStatVFSReply, Namemax);

		TElSftpStatVFSReply(TElSftpStatVFSReplyHandle handle, TElOwnHandle ownHandle);

		TElSftpStatVFSReply();

};
#endif /* SB_USE_CLASS_TELSFTPSTATVFSREPLY */

#ifdef SB_USE_CLASS_TSBSFTPACE
class TSBSftpACE: public TObject
{
	private:
		SB_DISABLE_COPY(TSBSftpACE)
	public:
		virtual int32_t get_ACEType();

		virtual void set_ACEType(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ACEType, set_ACEType, TSBSftpACE, ACEType);

		virtual int32_t get_ACEFlags();

		virtual void set_ACEFlags(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ACEFlags, set_ACEFlags, TSBSftpACE, ACEFlags);

		virtual int32_t get_ACEMask();

		virtual void set_ACEMask(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ACEMask, set_ACEMask, TSBSftpACE, ACEMask);

		virtual void get_Who(std::vector<uint8_t> &OutResult);

		virtual void set_Who(const std::vector<uint8_t> &Value);

		TSBSftpACE(TSBSftpACEHandle handle, TElOwnHandle ownHandle);

		TSBSftpACE();

};
#endif /* SB_USE_CLASS_TSBSFTPACE */

#ifdef SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES
class TElSftpExtendedProperties: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElSftpExtendedProperties)
#ifdef SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION
		TElSftpSupportedExtension* _Inst_SupportedExtension;
#endif /* SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION */
#ifdef SB_USE_CLASS_TELSFTPNEWLINEEXTENSION
		TElSftpNewlineExtension* _Inst_NewlineExtension;
#endif /* SB_USE_CLASS_TELSFTPNEWLINEEXTENSION */
#ifdef SB_USE_CLASS_TELSFTPVERSIONSEXTENSION
		TElSftpVersionsExtension* _Inst_VersionsExtension;
#endif /* SB_USE_CLASS_TELSFTPVERSIONSEXTENSION */
#ifdef SB_USE_CLASS_TELSFTPVENDORIDEXTENSION
		TElSftpVendorIDExtension* _Inst_VendorIDExtension;
#endif /* SB_USE_CLASS_TELSFTPVENDORIDEXTENSION */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void AssignTo(TPersistent &Dest);

		virtual void AssignTo(TPersistent *Dest);

		uint32_t RequestAttributesByVersion(int32_t Version);

		virtual uint32_t get_DesiredAccess();

		virtual void set_DesiredAccess(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_DesiredAccess, set_DesiredAccess, TElSftpExtendedProperties, DesiredAccess);

		virtual bool get_AutoAdjustDesiredAccess();

		virtual void set_AutoAdjustDesiredAccess(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoAdjustDesiredAccess, set_AutoAdjustDesiredAccess, TElSftpExtendedProperties, AutoAdjustDesiredAccess);

		virtual TSBSftpRenameFlags get_RenameFlags();

		virtual void set_RenameFlags(TSBSftpRenameFlags Value);

		SB_DECLARE_PROPERTY(TSBSftpRenameFlags, get_RenameFlags, set_RenameFlags, TElSftpExtendedProperties, RenameFlags);

		virtual uint32_t get_RenameFlagsUInt32();

		SB_DECLARE_PROPERTY_GET(uint32_t, get_RenameFlagsUInt32, TElSftpExtendedProperties, RenameFlagsUInt32);

		virtual TSBSftpAttributes get_RequestAttributes();

		virtual void set_RequestAttributes(TSBSftpAttributes Value);

		SB_DECLARE_PROPERTY(TSBSftpAttributes, get_RequestAttributes, set_RequestAttributes, TElSftpExtendedProperties, RequestAttributes);

		virtual uint32_t get_RequestAttributesUInt32();

		SB_DECLARE_PROPERTY_GET(uint32_t, get_RequestAttributesUInt32, TElSftpExtendedProperties, RequestAttributesUInt32);

		virtual bool get_AutoAdjustRequestAttributes();

		virtual void set_AutoAdjustRequestAttributes(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoAdjustRequestAttributes, set_AutoAdjustRequestAttributes, TElSftpExtendedProperties, AutoAdjustRequestAttributes);

		virtual bool get_SupportedAvailable();

		virtual void set_SupportedAvailable(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SupportedAvailable, set_SupportedAvailable, TElSftpExtendedProperties, SupportedAvailable);

#ifdef SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION
		virtual TElSftpSupportedExtension* get_SupportedExtension();

		virtual void set_SupportedExtension(TElSftpSupportedExtension &Value);

		virtual void set_SupportedExtension(TElSftpSupportedExtension *Value);

		SB_DECLARE_PROPERTY(TElSftpSupportedExtension*, get_SupportedExtension, set_SupportedExtension, TElSftpExtendedProperties, SupportedExtension);
#endif /* SB_USE_CLASS_TELSFTPSUPPORTEDEXTENSION */

		virtual bool get_NewlineAvailable();

		virtual void set_NewlineAvailable(bool Value);

		SB_DECLARE_PROPERTY(bool, get_NewlineAvailable, set_NewlineAvailable, TElSftpExtendedProperties, NewlineAvailable);

#ifdef SB_USE_CLASS_TELSFTPNEWLINEEXTENSION
		virtual TElSftpNewlineExtension* get_NewlineExtension();

		virtual void set_NewlineExtension(TElSftpNewlineExtension &Value);

		virtual void set_NewlineExtension(TElSftpNewlineExtension *Value);

		SB_DECLARE_PROPERTY(TElSftpNewlineExtension*, get_NewlineExtension, set_NewlineExtension, TElSftpExtendedProperties, NewlineExtension);
#endif /* SB_USE_CLASS_TELSFTPNEWLINEEXTENSION */

		virtual bool get_VersionsAvailable();

		virtual void set_VersionsAvailable(bool Value);

		SB_DECLARE_PROPERTY(bool, get_VersionsAvailable, set_VersionsAvailable, TElSftpExtendedProperties, VersionsAvailable);

#ifdef SB_USE_CLASS_TELSFTPVERSIONSEXTENSION
		virtual TElSftpVersionsExtension* get_VersionsExtension();

		virtual void set_VersionsExtension(TElSftpVersionsExtension &Value);

		virtual void set_VersionsExtension(TElSftpVersionsExtension *Value);

		SB_DECLARE_PROPERTY(TElSftpVersionsExtension*, get_VersionsExtension, set_VersionsExtension, TElSftpExtendedProperties, VersionsExtension);
#endif /* SB_USE_CLASS_TELSFTPVERSIONSEXTENSION */

		virtual bool get_VendorIDAvailable();

		virtual void set_VendorIDAvailable(bool Value);

		SB_DECLARE_PROPERTY(bool, get_VendorIDAvailable, set_VendorIDAvailable, TElSftpExtendedProperties, VendorIDAvailable);

#ifdef SB_USE_CLASS_TELSFTPVENDORIDEXTENSION
		virtual TElSftpVendorIDExtension* get_VendorIDExtension();

		virtual void set_VendorIDExtension(TElSftpVendorIDExtension &Value);

		virtual void set_VendorIDExtension(TElSftpVendorIDExtension *Value);

		SB_DECLARE_PROPERTY(TElSftpVendorIDExtension*, get_VendorIDExtension, set_VendorIDExtension, TElSftpExtendedProperties, VendorIDExtension);
#endif /* SB_USE_CLASS_TELSFTPVENDORIDEXTENSION */

		virtual void get_FilenameCharset(std::string &OutResult);

		virtual void set_FilenameCharset(const std::string &Value);

		TElSftpExtendedProperties(TElSftpExtendedPropertiesHandle handle, TElOwnHandle ownHandle);

		TElSftpExtendedProperties();

		virtual ~TElSftpExtendedProperties();

};
#endif /* SB_USE_CLASS_TELSFTPEXTENDEDPROPERTIES */

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
class TElSftpFileAttributes: public TObject
{
	private:
		SB_DISABLE_COPY(TElSftpFileAttributes)
#ifdef SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE
		TSBSftpExtendedAttribute* _Inst_ExtendedAttributes;
#endif /* SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE */
#ifdef SB_USE_CLASS_TSBSFTPACE
		TSBSftpACE* _Inst_ACEs;
#endif /* SB_USE_CLASS_TSBSFTPACE */

		void initInstances();

	public:
		void CopyTo(TElSftpFileAttributes &dst);

		void CopyTo(TElSftpFileAttributes *dst);

		void SaveToBuffer(int32_t Ver, std::vector<uint8_t> &OutResult);

		int32_t LoadFromBuffer(void * Buffer, int32_t Size, int32_t Ver);

		int32_t AddACE();

		void RemoveACE(int32_t Index);

		void ClearACEs();

		int32_t AddExtendedAttribute();

		void RemoveExtendedAttribute(int32_t Index);

		void ClearExtendedAttributes();

		bool IsAttributeIncluded(TSBSftpAttribute Attribute);

		virtual int64_t get_Size();

		virtual void set_Size(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Size, set_Size, TElSftpFileAttributes, Size);

		virtual int64_t get_AllocationSize();

		virtual void set_AllocationSize(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_AllocationSize, set_AllocationSize, TElSftpFileAttributes, AllocationSize);

		virtual int32_t get_UID();

		virtual void set_UID(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_UID, set_UID, TElSftpFileAttributes, UID);

		virtual int32_t get_GID();

		virtual void set_GID(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_GID, set_GID, TElSftpFileAttributes, GID);

		virtual void get_Owner(std::vector<uint8_t> &OutResult);

		virtual void set_Owner(const std::vector<uint8_t> &Value);

		virtual void get_Group(std::vector<uint8_t> &OutResult);

		virtual void set_Group(const std::vector<uint8_t> &Value);

		virtual int64_t get_CTime();

		virtual void set_CTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_CTime, set_CTime, TElSftpFileAttributes, CTime);

		virtual int64_t get_CATime();

		virtual void set_CATime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_CATime, set_CATime, TElSftpFileAttributes, CATime);

		virtual TSBSftpFileType get_FileType();

		virtual void set_FileType(TSBSftpFileType Value);

		SB_DECLARE_PROPERTY(TSBSftpFileType, get_FileType, set_FileType, TElSftpFileAttributes, FileType);

		virtual int64_t get_ATime();

		virtual void set_ATime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ATime, set_ATime, TElSftpFileAttributes, ATime);

		virtual int64_t get_MTime();

		virtual void set_MTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_MTime, set_MTime, TElSftpFileAttributes, MTime);

		virtual int32_t get_ExtendedAttributeCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ExtendedAttributeCount, TElSftpFileAttributes, ExtendedAttributeCount);

#ifdef SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE
		virtual TSBSftpExtendedAttribute* get_ExtendedAttributes(int32_t Index);
#endif /* SB_USE_CLASS_TSBSFTPEXTENDEDATTRIBUTE */

		virtual TSBSftpAttributes get_IncludedAttributes();

		virtual void set_IncludedAttributes(TSBSftpAttributes Value);

		SB_DECLARE_PROPERTY(TSBSftpAttributes, get_IncludedAttributes, set_IncludedAttributes, TElSftpFileAttributes, IncludedAttributes);

		virtual bool get_UserRead();

		virtual void set_UserRead(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UserRead, set_UserRead, TElSftpFileAttributes, UserRead);

		virtual bool get_UserWrite();

		virtual void set_UserWrite(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UserWrite, set_UserWrite, TElSftpFileAttributes, UserWrite);

		virtual bool get_UserExecute();

		virtual void set_UserExecute(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UserExecute, set_UserExecute, TElSftpFileAttributes, UserExecute);

		virtual bool get_GroupRead();

		virtual void set_GroupRead(bool Value);

		SB_DECLARE_PROPERTY(bool, get_GroupRead, set_GroupRead, TElSftpFileAttributes, GroupRead);

		virtual bool get_GroupWrite();

		virtual void set_GroupWrite(bool Value);

		SB_DECLARE_PROPERTY(bool, get_GroupWrite, set_GroupWrite, TElSftpFileAttributes, GroupWrite);

		virtual bool get_GroupExecute();

		virtual void set_GroupExecute(bool Value);

		SB_DECLARE_PROPERTY(bool, get_GroupExecute, set_GroupExecute, TElSftpFileAttributes, GroupExecute);

		virtual bool get_OtherRead();

		virtual void set_OtherRead(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OtherRead, set_OtherRead, TElSftpFileAttributes, OtherRead);

		virtual bool get_OtherWrite();

		virtual void set_OtherWrite(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OtherWrite, set_OtherWrite, TElSftpFileAttributes, OtherWrite);

		virtual bool get_OtherExecute();

		virtual void set_OtherExecute(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OtherExecute, set_OtherExecute, TElSftpFileAttributes, OtherExecute);

		virtual bool get_UIDBit();

		virtual void set_UIDBit(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UIDBit, set_UIDBit, TElSftpFileAttributes, UIDBit);

		virtual bool get_GIDBit();

		virtual void set_GIDBit(bool Value);

		SB_DECLARE_PROPERTY(bool, get_GIDBit, set_GIDBit, TElSftpFileAttributes, GIDBit);

		virtual bool get_StickyBit();

		virtual void set_StickyBit(bool Value);

		SB_DECLARE_PROPERTY(bool, get_StickyBit, set_StickyBit, TElSftpFileAttributes, StickyBit);

		virtual bool get_Directory();

		virtual void set_Directory(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Directory, set_Directory, TElSftpFileAttributes, Directory);

		virtual uint32_t get_ACLFlags();

		virtual void set_ACLFlags(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_ACLFlags, set_ACLFlags, TElSftpFileAttributes, ACLFlags);

		virtual int32_t get_ACECount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ACECount, TElSftpFileAttributes, ACECount);

#ifdef SB_USE_CLASS_TSBSFTPACE
		virtual TSBSftpACE* get_ACEs(int32_t Index);
#endif /* SB_USE_CLASS_TSBSFTPACE */

		virtual int64_t get_ATimeInt64();

		virtual void set_ATimeInt64(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ATimeInt64, set_ATimeInt64, TElSftpFileAttributes, ATimeInt64);

		virtual int64_t get_MTimeInt64();

		virtual void set_MTimeInt64(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_MTimeInt64, set_MTimeInt64, TElSftpFileAttributes, MTimeInt64);

		virtual int64_t get_CTimeInt64();

		virtual void set_CTimeInt64(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_CTimeInt64, set_CTimeInt64, TElSftpFileAttributes, CTimeInt64);

		virtual int64_t get_CATimeInt64();

		virtual void set_CATimeInt64(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_CATimeInt64, set_CATimeInt64, TElSftpFileAttributes, CATimeInt64);

		virtual uint32_t get_ATimeCardinal();

		virtual void set_ATimeCardinal(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_ATimeCardinal, set_ATimeCardinal, TElSftpFileAttributes, ATimeCardinal);

		virtual uint32_t get_MTimeCardinal();

		virtual void set_MTimeCardinal(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_MTimeCardinal, set_MTimeCardinal, TElSftpFileAttributes, MTimeCardinal);

		virtual uint32_t get_CTimeCardinal();

		virtual void set_CTimeCardinal(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_CTimeCardinal, set_CTimeCardinal, TElSftpFileAttributes, CTimeCardinal);

		virtual uint32_t get_CATimeCardinal();

		virtual void set_CATimeCardinal(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_CATimeCardinal, set_CATimeCardinal, TElSftpFileAttributes, CATimeCardinal);

		virtual int64_t get_ATimeSeconds();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ATimeSeconds, TElSftpFileAttributes, ATimeSeconds);

		virtual int64_t get_MTimeSeconds();

		SB_DECLARE_PROPERTY_GET(int64_t, get_MTimeSeconds, TElSftpFileAttributes, MTimeSeconds);

		virtual int64_t get_CTimeSeconds();

		SB_DECLARE_PROPERTY_GET(int64_t, get_CTimeSeconds, TElSftpFileAttributes, CTimeSeconds);

		virtual int64_t get_CATimeSeconds();

		SB_DECLARE_PROPERTY_GET(int64_t, get_CATimeSeconds, TElSftpFileAttributes, CATimeSeconds);

		virtual uint32_t get_ATimeMS();

		virtual void set_ATimeMS(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_ATimeMS, set_ATimeMS, TElSftpFileAttributes, ATimeMS);

		virtual uint32_t get_CTimeMS();

		virtual void set_CTimeMS(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_CTimeMS, set_CTimeMS, TElSftpFileAttributes, CTimeMS);

		virtual uint32_t get_CATimeMS();

		virtual void set_CATimeMS(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_CATimeMS, set_CATimeMS, TElSftpFileAttributes, CATimeMS);

		virtual uint32_t get_MTimeMS();

		virtual void set_MTimeMS(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_MTimeMS, set_MTimeMS, TElSftpFileAttributes, MTimeMS);

		virtual uint32_t get_AttribBits();

		virtual void set_AttribBits(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_AttribBits, set_AttribBits, TElSftpFileAttributes, AttribBits);

		virtual uint32_t get_AttribBitsValid();

		virtual void set_AttribBitsValid(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_AttribBitsValid, set_AttribBitsValid, TElSftpFileAttributes, AttribBitsValid);

		virtual uint8_t get_FileTypeByte();

		virtual void set_FileTypeByte(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_FileTypeByte, set_FileTypeByte, TElSftpFileAttributes, FileTypeByte);

		virtual uint32_t get_Permissions();

		virtual void set_Permissions(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_Permissions, set_Permissions, TElSftpFileAttributes, Permissions);

		virtual TSBSftpTextHint get_TextHint();

		virtual void set_TextHint(TSBSftpTextHint Value);

		SB_DECLARE_PROPERTY(TSBSftpTextHint, get_TextHint, set_TextHint, TElSftpFileAttributes, TextHint);

		virtual void get_MimeType(std::string &OutResult);

		virtual void set_MimeType(const std::string &Value);

		virtual uint32_t get_LinkCount();

		virtual void set_LinkCount(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_LinkCount, set_LinkCount, TElSftpFileAttributes, LinkCount);

		virtual void get_UntranslatedName(std::string &OutResult);

		virtual void set_UntranslatedName(const std::string &Value);

		TElSftpFileAttributes(TElSftpFileAttributesHandle handle, TElOwnHandle ownHandle);

		TElSftpFileAttributes();

		virtual ~TElSftpFileAttributes();

};
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELSFTPFILEINFO
class TElSftpFileInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElSftpFileInfo)
#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
		TElSftpFileAttributes* _Inst_Attributes;
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

		void initInstances();

	public:
		void CopyTo(TElSftpFileInfo &FileInfo);

		void CopyTo(TElSftpFileInfo *FileInfo);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual void get_LongName(std::string &OutResult);

		virtual void set_LongName(const std::string &Value);

		virtual void get_Path(std::string &OutResult);

		virtual void set_Path(const std::string &Value);

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
		virtual TElSftpFileAttributes* get_Attributes();

		SB_DECLARE_PROPERTY_GET(TElSftpFileAttributes*, get_Attributes, TElSftpFileInfo, Attributes);
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

		TElSftpFileInfo(TElSftpFileInfoHandle handle, TElOwnHandle ownHandle);

		TElSftpFileInfo();

		virtual ~TElSftpFileInfo();

};
#endif /* SB_USE_CLASS_TELSFTPFILEINFO */

#ifdef SB_USE_CLASS_TSBSFTPOPENREQUESTINFO
class TSBSftpOpenRequestInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TSBSftpOpenRequestInfo)
	public:
		TSBSftpOpenRequestInfo(TSBSftpOpenRequestInfoHandle handle, TElOwnHandle ownHandle);

		TSBSftpOpenRequestInfo();

};
#endif /* SB_USE_CLASS_TSBSFTPOPENREQUESTINFO */

#ifdef SB_USE_CLASS_TSBSFTPTEXTHANDLEINFO
class TSBSftpTextHandleInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TSBSftpTextHandleInfo)
	public:
		TSBSftpTextHandleInfo(TSBSftpTextHandleInfoHandle handle, TElOwnHandle ownHandle);

		TSBSftpTextHandleInfo();

};
#endif /* SB_USE_CLASS_TSBSFTPTEXTHANDLEINFO */

#ifdef SB_USE_CLASS_TELSFTPTRANSFERBLOCK
class TElSftpTransferBlock: public TObject
{
	private:
		SB_DISABLE_COPY(TElSftpTransferBlock)
	public:
		TElSftpTransferBlock(TElSftpTransferBlockHandle handle, TElOwnHandle ownHandle);

		TElSftpTransferBlock();

};
#endif /* SB_USE_CLASS_TELSFTPTRANSFERBLOCK */

#ifdef SB_USE_CLASS_TELSFTPTRANSFERMANAGER
class TElSftpTransferManager: public TObject
{
	private:
		SB_DISABLE_COPY(TElSftpTransferManager)
	public:
		void Run();

		bool ProcessData(uint32_t Id, void * Buffer, int32_t Size);

		bool ProcessStatus(uint32_t Id, int32_t StatusCode, const std::string &Comment);

		bool OperationFinished();

		void Terminate();

		virtual TSBSftpTransferDirection get_Direction();

		SB_DECLARE_PROPERTY_GET(TSBSftpTransferDirection, get_Direction, TElSftpTransferManager, Direction);

		virtual int64_t get_Received();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Received, TElSftpTransferManager, Received);

		virtual void get_Handle(std::vector<uint8_t> &OutResult);

		virtual bool get_TextMode();

		SB_DECLARE_PROPERTY_GET(bool, get_TextMode, TElSftpTransferManager, TextMode);

		virtual int32_t get_LastError();

		SB_DECLARE_PROPERTY_GET(int32_t, get_LastError, TElSftpTransferManager, LastError);

		virtual void get_LastComment(std::string &OutResult);

		virtual void get_OnData(TSBSftpDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnData(TSBSftpDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnASCIIData(TSBSftpDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnASCIIData(TSBSftpDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnReadRequest(TSBSftpReadRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReadRequest(TSBSftpReadRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnWriteRequest(TSBSftpWriteRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnWriteRequest(TSBSftpWriteRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnFinish(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFinish(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		TElSftpTransferManager(TElSftpTransferManagerHandle handle, TElOwnHandle ownHandle);

		TElSftpTransferManager(const std::vector<uint8_t> &Handle, int64_t Offset, void * Buffer, int32_t Size, int32_t ChunkSize, int32_t MaxActiveCount, TSBSftpTransferDirection Direction, bool TextMode);

};
#endif /* SB_USE_CLASS_TELSFTPTRANSFERMANAGER */

#ifdef SB_USE_CLASS_TELSFTPREMOVALTARGET
class TElSftpRemovalTarget: public TObject
{
	private:
		SB_DISABLE_COPY(TElSftpRemovalTarget)
	public:
		TElSftpRemovalTarget(TElSftpRemovalTargetHandle handle, TElOwnHandle ownHandle);

		TElSftpRemovalTarget();

};
#endif /* SB_USE_CLASS_TELSFTPREMOVALTARGET */

#ifdef SB_USE_CLASS_TELSFTPREMOVALMANAGER
class TElSftpRemovalManager: public TObject
{
	private:
		SB_DISABLE_COPY(TElSftpRemovalManager)
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_ErrorList;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_ErrorFilenames;
#endif /* SB_USE_CLASS_TSTRINGLIST */

		void initInstances();

	public:
		void Run();

		bool ProcessStatus(uint32_t Id, int32_t StatusCode, const std::string &ErrorMsg);

		bool OperationFinished();

		void Terminate();

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_ErrorList();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_ErrorList, TElSftpRemovalManager, ErrorList);
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_ErrorFilenames();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_ErrorFilenames, TElSftpRemovalManager, ErrorFilenames);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		virtual void get_OnFinish(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFinish(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnRemovalRequest(TSBSftpRemovalRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRemovalRequest(TSBSftpRemovalRequestEvent pMethodValue, void * pDataValue);

		TElSftpRemovalManager(TElSftpRemovalManagerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TSTRINGS
		TElSftpRemovalManager(TStrings &Filenames, int32_t MaxActiveCount);

		TElSftpRemovalManager(TStrings *Filenames, int32_t MaxActiveCount);
#endif /* SB_USE_CLASS_TSTRINGS */

		virtual ~TElSftpRemovalManager();

};
#endif /* SB_USE_CLASS_TELSFTPREMOVALMANAGER */

#ifdef SB_USE_GLOBAL_PROCS_SFTPCOMMON

#ifdef SB_USE_CLASS_TELSFTPFILEATTRIBUTES
void WriteDefaultAttributes(TElSftpFileAttributes &Attributes);
#endif /* SB_USE_CLASS_TELSFTPFILEATTRIBUTES */

uint8_t RealPathControlToByte(TSBSftpRealpathControl Value);

TSBSftpRealpathControl ByteToRealPathControl(uint8_t Value);

uint32_t FileOpenAccessToUInt32(TSBSftpFileOpenAccess Value);

TSBSftpFileOpenAccess UInt32ToFileOpenAccess(uint32_t Value);

TSBSftpRenameFlags UInt32ToRenameFlags(uint32_t Value);

#endif /* SB_USE_GLOBAL_PROCS_SFTPCOMMON */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_SFTPCOMMON
SB_IMPORT uint32_t SB_APIENTRY SBSftpCommon_WriteDefaultAttributes(TElSftpFileAttributesHandle * Attributes);
SB_IMPORT uint32_t SB_APIENTRY SBSftpCommon_RealPathControlToByte(TSBSftpRealpathControlRaw Value, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSftpCommon_ByteToRealPathControl(uint8_t Value, TSBSftpRealpathControlRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSftpCommon_FileOpenAccessToUInt32(TSBSftpFileOpenAccessRaw Value, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSftpCommon_UInt32ToFileOpenAccess(uint32_t Value, TSBSftpFileOpenAccessRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSftpCommon_UInt32ToRenameFlags(uint32_t Value, TSBSftpRenameFlagsRaw * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_SFTPCOMMON */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSFTPCOMMON */

