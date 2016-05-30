#ifndef __INC_SBPGPSFX
#define __INC_SBPGPSFX

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#ifndef WINCE
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbstreams.h"
#include "sbpgp.h"
#include "sbpgpkeys.h"
#include "sbpgputils.h"
#include "sbpgpstreams.h"
#include "sbpgpentities.h"
#endif

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifndef SB_WINCE_OR_NOT_WINDOWS
#define SB_IMAGE_SIZEOF_SHORT_NAME 	8
#define SB_IMAGE_NUMBEROF_DIRECTORY_ENTRIES 	16
#define SB_IMAGE_SIZEOF_FILE_HEADER 	20
#define SB_IMAGE_FILE_RELOCS_STRIPPED 	1
#define SB_IMAGE_FILE_EXECUTABLE_IMAGE 	2
#define SB_IMAGE_FILE_LINE_NUMS_STRIPPED 	4
#define SB_IMAGE_FILE_LOCAL_SYMS_STRIPPED 	8
#define SB_IMAGE_FILE_AGGRESIVE_WS_TRIM 	16
#define SB_IMAGE_FILE_BYTES_REVERSED_LO 	128
#define SB_IMAGE_FILE_32BIT_MACHINE 	256
#define SB_IMAGE_FILE_DEBUG_STRIPPED 	512
#define SB_IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP 	1024
#define SB_IMAGE_FILE_NET_RUN_FROM_SWAP 	2048
#define SB_IMAGE_FILE_SYSTEM 	4096
#define SB_IMAGE_FILE_DLL 	8192
#define SB_IMAGE_FILE_UP_SYSTEM_ONLY 	16384
#define SB_IMAGE_FILE_BYTES_REVERSED_HI 	32768
#define SB_IMAGE_FILE_MACHINE_UNKNOWN 	0
#define SB_IMAGE_FILE_MACHINE_I386 	332
#define SB_IMAGE_FILE_MACHINE_R3000 	354
#define SB_IMAGE_FILE_MACHINE_R4000 	358
#define SB_IMAGE_FILE_MACHINE_R10000 	360
#define SB_IMAGE_FILE_MACHINE_ALPHA 	388
#define SB_IMAGE_FILE_MACHINE_POWERPC 	496
#define SB_IMAGE_SIZEOF_SECTION_HEADER 	40
#define SB_IMAGE_SCN_TYPE_NO_PAD 	8
#define SB_IMAGE_SCN_CNT_CODE 	32
#define SB_IMAGE_SCN_CNT_INITIALIZED_DATA 	64
#define SB_IMAGE_SCN_CNT_UNINITIALIZED_DATA 	128
#define SB_IMAGE_SCN_LNK_OTHER 	256
#define SB_IMAGE_SCN_LNK_INFO 	512
#define SB_IMAGE_SCN_LNK_REMOVE 	2048
#define SB_IMAGE_SCN_LNK_COMDAT 	4096
#define SB_IMAGE_SCN_MEM_FARDATA 	32768
#define SB_IMAGE_SCN_MEM_PURGEABLE 	131072
#define SB_IMAGE_SCN_MEM_16BIT 	131072
#define SB_IMAGE_SCN_MEM_LOCKED 	262144
#define SB_IMAGE_SCN_MEM_PRELOAD 	524288
#define SB_IMAGE_SCN_ALIGN_1BYTES 	1048576
#define SB_IMAGE_SCN_ALIGN_2BYTES 	2097152
#define SB_IMAGE_SCN_ALIGN_4BYTES 	3145728
#define SB_IMAGE_SCN_ALIGN_8BYTES 	4194304
#define SB_IMAGE_SCN_ALIGN_16BYTES 	5242880
#define SB_IMAGE_SCN_ALIGN_32BYTES 	6291456
#define SB_IMAGE_SCN_ALIGN_64BYTES 	7340032
#define SB_IMAGE_SCN_LNK_NRELOC_OVFL 	16777216
#define SB_IMAGE_SCN_MEM_DISCARDABLE 	33554432
#define SB_IMAGE_SCN_MEM_NOT_CACHED 	67108864
#define SB_IMAGE_SCN_MEM_NOT_PAGED 	134217728
#define SB_IMAGE_SCN_MEM_SHARED 	268435456
#define SB_IMAGE_SCN_MEM_EXECUTE 	536870912
#define SB_IMAGE_SCN_MEM_READ 	1073741824
#define SB_IMAGE_SCN_MEM_WRITE 	2147483648
#define SB_IMAGE_NT_OPTIONAL_HDR_MAGIC 	267
#define SB_IMAGE_SUBSYSTEM_WINDOWS_GUI 	2
#define SB_IMAGE_SUBSYSTEM_WINDOWS_CUI 	3
#define SB_PGPSFXStubAllSwitches 	{0,1,2,3,4,5,6,7,8,9}
#define SB_PGPSFX_ERROR_BASE 	13312
#define SB_PGPSFX_OK 	0
#define SB_PGPSFX_USER_ABORT 	1
#define SB_PGPSFX_INTERNAL_ERROR 	13312
#define SB_PGPSFX_INVALID_PARAMETER_TARGET 	13313
#define SB_PGPSFX_INVALID_PARAMETER_PUBLIC 	13314
#define SB_PGPSFX_INVALID_PARAMETER_SECRET 	13315
#define SB_PGPSFX_INVALID_PARAMETER_KEYPASS 	13316
#define SB_PGPSFX_INVALID_PARAMETER_PASS 	13317
#define SB_PGPSFX_INVALID_PARAMETER_EXTRACT 	13318
#define SB_PGPSFX_INVALID_PARAMETER_TEMP 	13319
#define SB_PGPSFX_TARGET_FOLDER_FAILURE 	13320
#define SB_PGPSFX_INPUT_STREAM_FAILURE 	13321
#define SB_PGPSFX_PACKET_FILE_ALREADY_EXISTS 	13322
#define SB_PGPSFX_PACKET_FILE_FAILURE 	13323
#define SB_PGPSFX_PUBLIC_KEY_NOT_FOUND 	13323
#define SB_PGPSFX_NO_PUBLIC_KEYS 	13324
#define SB_PGPSFX_SECRET_KEY_NOT_FOUND 	13324
#define SB_PGPSFX_NO_SECRET_KEYS 	13325
#define SB_PGPSFX_INVALID_METHOD 	13326
#define SB_PGPSFX_INVALID_PASSPHRASE 	13327
#define SB_PGPSFX_NO_PGP_DATA 	13328
#define SB_PGPSFX_MAKER_ERROR_BASE 	13552
#define SB_PGPSFX_NO_STUB 	13553
#define SB_PGPSFX_INVALID_DOS_SIGNATURE 	13554
#define SB_PGPSFX_INVALID_PE_SIGNATURE 	13555
#define SB_PGPSFX_INVALID_MACHINE_SPECIFIER 	13556
#define SB_PGPSFX_INVALID_CHARACTERISTICS 	13557
#define SB_PGPSFX_INVALID_OPTIONAL_SIGNATURE 	13558
#define SB_PGPSFX_INVALID_SUBSYSTEM 	13559
#define SB_PGPSFX_NO_SECTIONS 	13560
#define SB_PGPSFX_TITLE_TOO_LONG 	13561
#define SB_PGPSFX_COPYRIGHT_TOO_LONG 	13562
#define SB_SErrUserAbort 	"Cancelled by the user"
#define SB_SErrInternalError 	"Internal error"
#define SB_SErrInvalidParamTarget 	"No target folder specified"
#define SB_SErrInvalidParamPublic 	"No public keyring file specified"
#define SB_SErrInvalidParamSecret 	"No secret keyring file specified"
#define SB_SErrInvalidParamKeyPass 	"No secret key passphrase specified"
#define SB_SErrInvalidParamPass 	"No decryption passphrase specified"
#ifndef SB_SErrInvalidParamExtract
#define SB_SErrInvalidParamExtract 	"No pgp-packet file name specified"
#endif
#define SB_SErrInvalidParamTemp 	"No or invalid temporary file location specified"
#define SB_SErrTargetFolderFailure 	"Failed to create target folder %s"
#define SB_SErrInputStreamFailure 	"Failed to open input stream"
#define SB_SErrNoPGPData 	"No PGP data found"
#define SB_SErrPacketFileAlreadyExists 	"File %s already exists"
#define SB_SErrPacketFileFailure 	"Failed to create or open the output file %s"
#define SB_SErrNoStubStreamSpecified 	"No stub stream specified"
#define SB_SErrInvalidDOSSignature 	"Invalid DOS signature value: $%.4X (expected \'MZ\' - $5A4D)"
#define SB_SErrInvalidPESignature 	"Invalid PE signature value: $%.8X (expected \'PE\\0\\0\' - $00004550)"
#define SB_SErrInvalidMachineSpecifier 	"Invalid machine specifier: $%.4X (expected x86 - $014C)"
#define SB_SErrInvalidCharacteristics 	"Invalid characteristics: $%.4X (either EXE bit is not set or DLL or driver bits are set)"
#define SB_SErrInvalidOptionalSignature 	"Invalid optional signature value: $%.4X (expected PE32 - $010B)"
#define SB_SErrInvalidSubsystem 	"Invalid subsystem specifier: $%.4X (expected Win32 GUI = 2 or Win32 Console = 3)"
#define SB_SErrNoSections 	"There must be at least one section defined"
#define SB_SErrTitleTooLong 	"Title could not be more than 255 characters length"
#define SB_SErrCopyrightTooLong 	"Copyright could not be more than 255 characters length"

typedef TElClassHandle TElPGPSFXStubHandle;

typedef TElClassHandle TElPGPSFXMakerHandle;

#pragma pack(4)
typedef struct 
{
	uint32_t VirtualAddress;
	uint32_t Size;
} SBPGPSFX__IMAGE_DATA_DIRECTORY, * SBPGPSFX_PImageDataDirectory;

typedef SBPGPSFX__IMAGE_DATA_DIRECTORY SBPGPSFX_TImageDataDirectory;

typedef SBPGPSFX__IMAGE_DATA_DIRECTORY SBPGPSFX_IMAGE_DATA_DIRECTORY;

#pragma pack(1)
typedef struct 
{
	uint16_t Magic;
	uint8_t MajorLinkerVersion;
	uint8_t MinorLinkerVersion;
	uint32_t SizeOfCode;
	uint32_t SizeOfInitializedData;
	uint32_t SizeOfUninitializedData;
	uint32_t AddressOfEntryPoint;
	uint32_t BaseOfCode;
	uint32_t BaseOfData;
	uint32_t ImageBase;
	uint32_t SectionAlignment;
	uint32_t FileAlignment;
	uint16_t MajorOperatingSystemVersion;
	uint16_t MinorOperatingSystemVersion;
	uint16_t MajorImageVersion;
	uint16_t MinorImageVersion;
	uint16_t MajorSubsystemVersion;
	uint16_t MinorSubsystemVersion;
	uint32_t Win32VersionValue;
	uint32_t SizeOfImage;
	uint32_t SizeOfHeaders;
	uint32_t CheckSum;
	uint16_t Subsystem;
	uint16_t DllCharacteristics;
	uint32_t SizeOfStackReserve;
	uint32_t SizeOfStackCommit;
	uint32_t SizeOfHeapReserve;
	uint32_t SizeOfHeapCommit;
	uint32_t LoaderFlags;
	uint32_t NumberOfRvaAndSizes;
	SBPGPSFX__IMAGE_DATA_DIRECTORY DataDirectory[16];
} SBPGPSFX__IMAGE_OPTIONAL_HEADER, * SBPGPSFX_PImageOptionalHeader;

typedef SBPGPSFX__IMAGE_OPTIONAL_HEADER SBPGPSFX_TImageOptionalHeader;

typedef SBPGPSFX__IMAGE_OPTIONAL_HEADER SBPGPSFX_IMAGE_OPTIONAL_HEADER;

#pragma pack(1)
typedef struct 
{
	uint16_t e_magic;
	uint16_t e_cblp;
	uint16_t e_cp;
	uint16_t e_crlc;
	uint16_t e_cparhdr;
	uint16_t e_minalloc;
	uint16_t e_maxalloc;
	uint16_t e_ss;
	uint16_t e_sp;
	uint16_t e_csum;
	uint16_t e_ip;
	uint16_t e_cs;
	uint16_t e_lfarlc;
	uint16_t e_ovno;
	uint16_t e_res[4];
	uint16_t e_oemid;
	uint16_t e_oeminfo;
	uint16_t e_res2[10];
	int32_t _lfanew;
} SBPGPSFX__IMAGE_DOS_HEADER, * SBPGPSFX_PImageDosHeader;

typedef SBPGPSFX__IMAGE_DOS_HEADER SBPGPSFX_TImageDosHeader;

typedef SBPGPSFX__IMAGE_DOS_HEADER SBPGPSFX_IMAGE_DOS_HEADER;

#pragma pack(1)
typedef struct 
{
	uint16_t Machine;
	uint16_t NumberOfSections;
	uint32_t TimeDateStamp;
	uint32_t PointerToSymbolTable;
	uint32_t NumberOfSymbols;
	uint16_t SizeOfOptionalHeader;
	uint16_t Characteristics;
} SBPGPSFX__IMAGE_FILE_HEADER, * SBPGPSFX_PImageFileHeader;

typedef SBPGPSFX__IMAGE_FILE_HEADER SBPGPSFX_TImageFileHeader;

typedef SBPGPSFX__IMAGE_FILE_HEADER SBPGPSFX_IMAGE_FILE_HEADER;

#pragma pack(1)
typedef struct 
{
	uint32_t Signature;
	SBPGPSFX__IMAGE_FILE_HEADER FileHeader;
	SBPGPSFX__IMAGE_OPTIONAL_HEADER OptionalHeader;
} SBPGPSFX__IMAGE_NT_HEADERS, * SBPGPSFX_PImageNtHeaders;

typedef SBPGPSFX__IMAGE_NT_HEADERS SBPGPSFX_TImageNtHeaders;

typedef SBPGPSFX__IMAGE_NT_HEADERS SBPGPSFX_IMAGE_NT_HEADERS;

#pragma pack(4)
typedef struct 
{
	union
	{
		struct
		{
			uint32_t PhysicalAddress;
		} S1;
		struct
		{
			uint32_t VirtualSize;
		} S2;
	};
} SBPGPSFX_TISHMisc;

#pragma pack(1)
typedef struct 
{
	uint8_t Name[8];
	SBPGPSFX_TISHMisc Misc;
	uint32_t VirtualAddress;
	uint32_t SizeOfRawData;
	uint32_t PointerToRawData;
	uint32_t PointerToRelocations;
	uint32_t PointerToLinenumbers;
	uint16_t NumberOfRelocations;
	uint16_t NumberOfLinenumbers;
	uint32_t Characteristics;
} SBPGPSFX__IMAGE_SECTION_HEADER, * SBPGPSFX_PImageSectionHeader;

typedef SBPGPSFX__IMAGE_SECTION_HEADER SBPGPSFX_TImageSectionHeader;

typedef SBPGPSFX__IMAGE_SECTION_HEADER SBPGPSFX_IMAGE_SECTION_HEADER;

typedef uint8_t TSBPGPSFXCommandLineSwitchRaw;

typedef enum
{
	clsHelp = 0,
	clsSilent = 1,
	clsOverwrite = 2,
	clsTarget = 3,
	clsPublic = 4,
	clsSecret = 5,
	clsKeyPass = 6,
	clsPass = 7,
	clsExtract = 8,
	clsTempFile = 9
} TSBPGPSFXCommandLineSwitch;

typedef uint32_t TSBPGPSFXCommandLineSwitchesRaw;

typedef enum 
{
	f_clsHelp = 1,
	f_clsSilent = 2,
	f_clsOverwrite = 4,
	f_clsTarget = 8,
	f_clsPublic = 16,
	f_clsSecret = 32,
	f_clsKeyPass = 64,
	f_clsPass = 128,
	f_clsExtract = 256,
	f_clsTempFile = 512
} TSBPGPSFXCommandLineSwitches;

typedef uint8_t TSBPGPSFXTempFileLocationRaw;

typedef enum
{
	tflNone = 0,
	tflSystem = 1,
	tflTarget = 2
} TSBPGPSFXTempFileLocation;

typedef uint8_t TSBPGPSFXFileActionRaw;

typedef enum
{
	faNewFile = 0,
	faOverwrite = 1,
	faRename = 2,
	faSkip = 3,
	faRetry = 4
} TSBPGPSFXFileAction;

typedef void (SB_CALLBACK *TSBPGPSFXExtractingEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcFolder, int32_t szFolder, const char * pcFileName, int32_t szFileName);

typedef void (SB_CALLBACK *TSBPGPSFXErrorEvent)(void * _ObjectData, TObjectHandle Sender, TElClassHandle Error);

typedef void (SB_CALLBACK *TSBPGPSFXFileErrorEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcOriginalFileName, int32_t szOriginalFileName, TElClassHandle Error, char * pcActualFileName, int32_t * szActualFileName, TSBPGPSFXFileActionRaw * Action);

typedef void (SB_CALLBACK *TSBPGPSFXFileExistsEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcOriginalFileName, int32_t szOriginalFileName, int64_t OriginalTimeStamp, char * pcActualFileName, int32_t * szActualFileName, int64_t ActualTimeStamp, TSBPGPSFXFileActionRaw * Action);

typedef void (SB_CALLBACK *TSBPGPSFXFileEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcOriginalFileName, int32_t szOriginalFileName, TSBPGPSFXFileActionRaw OriginalFileAction, const char * pcActualFileName, int32_t szActualFileName, TSBPGPSFXFileActionRaw ActualFileAction, int64_t TimeStamp);

typedef void (SB_CALLBACK *TSBPGPSFXKeyPassphraseEvent)(void * _ObjectData, TObjectHandle Sender, TElPGPCustomSecretKeyHandle Key, int32_t Attempt, char * pcPassphrase, int32_t * szPassphrase, int8_t * Cancel);

typedef void (SB_CALLBACK *TSBPGPSFXPassphraseEvent)(void * _ObjectData, TObjectHandle Sender, int32_t Attempt, char * pcPassphrase, int32_t * szPassphrase, int8_t * Cancel);

typedef void (SB_CALLBACK *TSBPGPSFXStartEvent)(void * _ObjectData, TObjectHandle Sender, int8_t HelpRequested, int8_t * Abort);

typedef void (SB_CALLBACK *TSBPGPSFXTargetFolderEvent)(void * _ObjectData, TObjectHandle Sender, char * pcFolder, int32_t * szFolder, int8_t * Abort);

#ifdef SB_USE_CLASS_TELPGPSFXSTUB
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_Execute(TElPGPSFXStubHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_Copyright(TElPGPSFXStubHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_Evaluation(TElPGPSFXStubHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_Title(TElPGPSFXStubHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_UsedSwitches(TElPGPSFXStubHandle _Handle, TSBPGPSFXCommandLineSwitchesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_Extract(TElPGPSFXStubHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_Extract(TElPGPSFXStubHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_KeyPassphrase(TElPGPSFXStubHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_KeyPassphrase(TElPGPSFXStubHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_Overwrite(TElPGPSFXStubHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_Overwrite(TElPGPSFXStubHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_Passphrase(TElPGPSFXStubHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_Passphrase(TElPGPSFXStubHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_PublicKeys(TElPGPSFXStubHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_PublicKeys(TElPGPSFXStubHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_SecretKeys(TElPGPSFXStubHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_SecretKeys(TElPGPSFXStubHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_Silent(TElPGPSFXStubHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_Silent(TElPGPSFXStubHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_SupportedSwitches(TElPGPSFXStubHandle _Handle, TSBPGPSFXCommandLineSwitchesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_SupportedSwitches(TElPGPSFXStubHandle _Handle, TSBPGPSFXCommandLineSwitchesRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_Target(TElPGPSFXStubHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_Target(TElPGPSFXStubHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_TempFileLocation(TElPGPSFXStubHandle _Handle, TSBPGPSFXTempFileLocationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_TempFileLocation(TElPGPSFXStubHandle _Handle, TSBPGPSFXTempFileLocationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_UseCommandLine(TElPGPSFXStubHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_UseCommandLine(TElPGPSFXStubHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_OnAbort(TElPGPSFXStubHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_OnAbort(TElPGPSFXStubHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_OnCommandLine(TElPGPSFXStubHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_OnCommandLine(TElPGPSFXStubHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_OnEncrypted(TElPGPSFXStubHandle _Handle, TSBPGPEncryptedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_OnEncrypted(TElPGPSFXStubHandle _Handle, TSBPGPEncryptedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_OnError(TElPGPSFXStubHandle _Handle, TSBPGPSFXErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_OnError(TElPGPSFXStubHandle _Handle, TSBPGPSFXErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_OnExtracting(TElPGPSFXStubHandle _Handle, TSBPGPSFXExtractingEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_OnExtracting(TElPGPSFXStubHandle _Handle, TSBPGPSFXExtractingEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_OnFileError(TElPGPSFXStubHandle _Handle, TSBPGPSFXFileErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_OnFileError(TElPGPSFXStubHandle _Handle, TSBPGPSFXFileErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_OnFileExists(TElPGPSFXStubHandle _Handle, TSBPGPSFXFileExistsEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_OnFileExists(TElPGPSFXStubHandle _Handle, TSBPGPSFXFileExistsEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_OnFileFinish(TElPGPSFXStubHandle _Handle, TSBPGPSFXFileEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_OnFileFinish(TElPGPSFXStubHandle _Handle, TSBPGPSFXFileEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_OnFileProgress(TElPGPSFXStubHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_OnFileProgress(TElPGPSFXStubHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_OnFileStart(TElPGPSFXStubHandle _Handle, TSBPGPSFXFileEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_OnFileStart(TElPGPSFXStubHandle _Handle, TSBPGPSFXFileEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_OnFinish(TElPGPSFXStubHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_OnFinish(TElPGPSFXStubHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_OnKeyPassphrase(TElPGPSFXStubHandle _Handle, TSBPGPSFXKeyPassphraseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_OnKeyPassphrase(TElPGPSFXStubHandle _Handle, TSBPGPSFXKeyPassphraseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_OnOutputStream(TElPGPSFXStubHandle _Handle, TSBPGPCreateOutputStreamEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_OnOutputStream(TElPGPSFXStubHandle _Handle, TSBPGPCreateOutputStreamEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_OnPassphrase(TElPGPSFXStubHandle _Handle, TSBPGPSFXPassphraseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_OnPassphrase(TElPGPSFXStubHandle _Handle, TSBPGPSFXPassphraseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_OnProgress(TElPGPSFXStubHandle _Handle, TSBPGPProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_OnProgress(TElPGPSFXStubHandle _Handle, TSBPGPProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_OnSigned(TElPGPSFXStubHandle _Handle, TSBPGPSignedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_OnSigned(TElPGPSFXStubHandle _Handle, TSBPGPSignedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_OnStart(TElPGPSFXStubHandle _Handle, TSBPGPSFXStartEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_OnStart(TElPGPSFXStubHandle _Handle, TSBPGPSFXStartEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_get_OnTargetFolder(TElPGPSFXStubHandle _Handle, TSBPGPSFXTargetFolderEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_set_OnTargetFolder(TElPGPSFXStubHandle _Handle, TSBPGPSFXTargetFolderEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXStub_Create(TComponentHandle AOwner, TElPGPSFXStubHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPSFXSTUB */

#ifdef SB_USE_CLASS_TELPGPSFXMAKER
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXMaker_Execute(TElPGPSFXMakerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXMaker_Update(TElPGPSFXMakerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXMaker_get_Copyright(TElPGPSFXMakerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXMaker_set_Copyright(TElPGPSFXMakerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXMaker_get_Title(TElPGPSFXMakerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXMaker_set_Title(TElPGPSFXMakerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXMaker_get_OnProgress(TElPGPSFXMakerHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXMaker_set_OnProgress(TElPGPSFXMakerHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSFXMaker_Create(TStreamHandle AStub, TStreamHandle AOutput, TElPGPSFXMakerHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPSFXMAKER */
#endif

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef __cplusplus

// Class forward declaration
class TElPGPSFXStub;
class TElPGPSFXMaker;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBPGPSFXCommandLineSwitches)

#ifdef SB_USE_CLASS_TELPGPSFXSTUB
class TElPGPSFXStub: public TComponent
{
	private:
		SB_DISABLE_COPY(TElPGPSFXStub)
	public:
		int32_t Execute();

		virtual void get_Copyright(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Copyright(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual bool get_Evaluation();

		SB_DECLARE_PROPERTY_GET(bool, get_Evaluation, TElPGPSFXStub, Evaluation);

		virtual void get_Title(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Title(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual TSBPGPSFXCommandLineSwitches get_UsedSwitches();

		SB_DECLARE_PROPERTY_GET(TSBPGPSFXCommandLineSwitches, get_UsedSwitches, TElPGPSFXStub, UsedSwitches);

		virtual void get_Extract(std::string &OutResult);

		virtual void set_Extract(const std::string &Value);

		virtual void get_KeyPassphrase(std::string &OutResult);

		virtual void set_KeyPassphrase(const std::string &Value);

		virtual bool get_Overwrite();

		virtual void set_Overwrite(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Overwrite, set_Overwrite, TElPGPSFXStub, Overwrite);

		virtual void get_Passphrase(std::string &OutResult);

		virtual void set_Passphrase(const std::string &Value);

		virtual void get_PublicKeys(std::string &OutResult);

		virtual void set_PublicKeys(const std::string &Value);

		virtual void get_SecretKeys(std::string &OutResult);

		virtual void set_SecretKeys(const std::string &Value);

		virtual bool get_Silent();

		virtual void set_Silent(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Silent, set_Silent, TElPGPSFXStub, Silent);

		virtual TSBPGPSFXCommandLineSwitches get_SupportedSwitches();

		virtual void set_SupportedSwitches(TSBPGPSFXCommandLineSwitches Value);

		SB_DECLARE_PROPERTY(TSBPGPSFXCommandLineSwitches, get_SupportedSwitches, set_SupportedSwitches, TElPGPSFXStub, SupportedSwitches);

		virtual void get_Target(std::string &OutResult);

		virtual void set_Target(const std::string &Value);

		virtual TSBPGPSFXTempFileLocation get_TempFileLocation();

		virtual void set_TempFileLocation(TSBPGPSFXTempFileLocation Value);

		SB_DECLARE_PROPERTY(TSBPGPSFXTempFileLocation, get_TempFileLocation, set_TempFileLocation, TElPGPSFXStub, TempFileLocation);

		virtual bool get_UseCommandLine();

		virtual void set_UseCommandLine(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseCommandLine, set_UseCommandLine, TElPGPSFXStub, UseCommandLine);

		virtual void get_OnAbort(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAbort(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnCommandLine(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCommandLine(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnEncrypted(TSBPGPEncryptedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnEncrypted(TSBPGPEncryptedEvent pMethodValue, void * pDataValue);

		virtual void get_OnError(TSBPGPSFXErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSBPGPSFXErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtracting(TSBPGPSFXExtractingEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtracting(TSBPGPSFXExtractingEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileError(TSBPGPSFXFileErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileError(TSBPGPSFXFileErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileExists(TSBPGPSFXFileExistsEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileExists(TSBPGPSFXFileExistsEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileFinish(TSBPGPSFXFileEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileFinish(TSBPGPSFXFileEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileStart(TSBPGPSFXFileEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileStart(TSBPGPSFXFileEvent pMethodValue, void * pDataValue);

		virtual void get_OnFinish(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFinish(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyPassphrase(TSBPGPSFXKeyPassphraseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyPassphrase(TSBPGPSFXKeyPassphraseEvent pMethodValue, void * pDataValue);

		virtual void get_OnOutputStream(TSBPGPCreateOutputStreamEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOutputStream(TSBPGPCreateOutputStreamEvent pMethodValue, void * pDataValue);

		virtual void get_OnPassphrase(TSBPGPSFXPassphraseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPassphrase(TSBPGPSFXPassphraseEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBPGPProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBPGPProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnSigned(TSBPGPSignedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSigned(TSBPGPSignedEvent pMethodValue, void * pDataValue);

		virtual void get_OnStart(TSBPGPSFXStartEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnStart(TSBPGPSFXStartEvent pMethodValue, void * pDataValue);

		virtual void get_OnTargetFolder(TSBPGPSFXTargetFolderEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTargetFolder(TSBPGPSFXTargetFolderEvent pMethodValue, void * pDataValue);

		TElPGPSFXStub(TElPGPSFXStubHandle handle, TElOwnHandle ownHandle);

		explicit TElPGPSFXStub(TComponent &AOwner);

		explicit TElPGPSFXStub(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELPGPSFXSTUB */

#ifdef SB_USE_CLASS_TELPGPSFXMAKER
class TElPGPSFXMaker: public TObject
{
	private:
		SB_DISABLE_COPY(TElPGPSFXMaker)
	public:
		bool Execute();

		void Update();

		virtual void get_Copyright(std::string &OutResult);

		virtual void set_Copyright(const std::string &Value);

		virtual void get_Title(std::string &OutResult);

		virtual void set_Title(const std::string &Value);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		TElPGPSFXMaker(TElPGPSFXMakerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TSTREAM
		TElPGPSFXMaker(TStream &AStub, TStream &AOutput);

		TElPGPSFXMaker(TStream *AStub, TStream *AOutput);
#endif /* SB_USE_CLASS_TSTREAM */

};
#endif /* SB_USE_CLASS_TELPGPSFXMAKER */

#endif  /* __cplusplus */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPGPSFX */
