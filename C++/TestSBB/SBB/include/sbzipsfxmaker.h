#ifndef __INC_SBZIPSFXMAKER
#define __INC_SBZIPSFXMAKER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbstreams.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifdef SB_WINDOWS
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
#define SB_ZIPSFX_ERROR_BASE 	13312
#define SB_ZIPSFX_OK 	0
#define SB_ZIPSFX_USER_ABORT 	1
#define SB_ZIPSFX_INTERNAL_ERROR 	13312
#define SB_ZIPSFX_INVALID_PARAMETER_TARGET 	13313
#define SB_ZIPSFX_INVALID_PARAMETER_CERT 	13314
#define SB_ZIPSFX_INVALID_PARAMETER_CERTPASS 	13315
#define SB_ZIPSFX_INVALID_PARAMETER_PASS 	13316
#define SB_ZIPSFX_INVALID_PARAMETER_EXTRACT 	13317
#define SB_ZIPSFX_TARGET_FOLDER_FAILURE 	13318
#define SB_ZIPSFX_INPUT_STREAM_FAILURE 	13319
#define SB_ZIPSFX_PACKET_FILE_ALREADY_EXISTS 	13320
#define SB_ZIPSFX_PACKET_FILE_FAILURE 	13321
#define SB_ZIPSFX_CERT_NOT_FOUND 	13322
#define SB_ZIPSFX_NO_CERT 	13323
#define SB_ZIPSFX_INVALID_METHOD 	13324
#define SB_ZIPSFX_INVALID_PASSWORD 	13325
#define SB_ZIPSFX_NO_ZIP_DATA 	13326
#define SB_ZIPSFX_NO_SFX_DATA 	13327
#define SB_ZIPSFX_MAKER_ERROR_BASE 	13552
#define SB_ZIPSFX_NO_STUB 	13553
#define SB_ZIPSFX_INVALID_DOS_SIGNATURE 	13554
#define SB_ZIPSFX_INVALID_PE_SIGNATURE 	13555
#define SB_ZIPSFX_INVALID_MACHINE_SPECIFIER 	13556
#define SB_ZIPSFX_INVALID_CHARACTERISTICS 	13557
#define SB_ZIPSFX_INVALID_OPTIONAL_SIGNATURE 	13558
#define SB_ZIPSFX_INVALID_SUBSYSTEM 	13559
#define SB_ZIPSFX_NO_SECTIONS 	13560
#define SB_ZIPSFX_TITLE_TOO_LONG 	13561
#define SB_ZIPSFX_COPYRIGHT_TOO_LONG 	13562
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

typedef TElClassHandle TElZIPSFXMakerHandle;

#pragma pack(4)
typedef struct 
{
	uint32_t VirtualAddress;
	uint32_t Size;
#ifndef WINCE
} SBZIPSFXMaker__IMAGE_DATA_DIRECTORY, * SBZIPSFXMaker_PImageDataDirectory;
#else
} SBZIPSFXMaker__IMAGE_DATA_DIRECTORY, * PImageDataDirectory;
#endif

#ifndef WINCE
typedef SBZIPSFXMaker__IMAGE_DATA_DIRECTORY SBZIPSFXMaker_TImageDataDirectory;
#else
typedef SBZIPSFXMaker__IMAGE_DATA_DIRECTORY TImageDataDirectory;
#endif

typedef SBZIPSFXMaker__IMAGE_DATA_DIRECTORY SBZIPSFXMaker_IMAGE_DATA_DIRECTORY;

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
	SBZIPSFXMaker__IMAGE_DATA_DIRECTORY DataDirectory[16];
#ifndef WINCE
} SBZIPSFXMaker__IMAGE_OPTIONAL_HEADER, * SBZIPSFXMaker_PImageOptionalHeader;
#else
} SBZIPSFXMaker__IMAGE_OPTIONAL_HEADER, * PImageOptionalHeader;
#endif

#ifndef WINCE
typedef SBZIPSFXMaker__IMAGE_OPTIONAL_HEADER SBZIPSFXMaker_TImageOptionalHeader;
#else
typedef SBZIPSFXMaker__IMAGE_OPTIONAL_HEADER TImageOptionalHeader;
#endif

typedef SBZIPSFXMaker__IMAGE_OPTIONAL_HEADER SBZIPSFXMaker_IMAGE_OPTIONAL_HEADER;

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
#ifndef WINCE
} SBZIPSFXMaker__IMAGE_DOS_HEADER, * SBZIPSFXMaker_PImageDosHeader;
#else
} SBZIPSFXMaker__IMAGE_DOS_HEADER, * PImageDosHeader;
#endif

#ifndef WINCE
typedef SBZIPSFXMaker__IMAGE_DOS_HEADER SBZIPSFXMaker_TImageDosHeader;
#else
typedef SBZIPSFXMaker__IMAGE_DOS_HEADER TImageDosHeader;
#endif

typedef SBZIPSFXMaker__IMAGE_DOS_HEADER SBZIPSFXMaker_IMAGE_DOS_HEADER;

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
#ifndef WINCE
} SBZIPSFXMaker__IMAGE_FILE_HEADER, * SBZIPSFXMaker_PImageFileHeader;
#else
} SBZIPSFXMaker__IMAGE_FILE_HEADER, * PImageFileHeader;
#endif

#ifndef WINCE
typedef SBZIPSFXMaker__IMAGE_FILE_HEADER SBZIPSFXMaker_TImageFileHeader;
#else
typedef SBZIPSFXMaker__IMAGE_FILE_HEADER TImageFileHeader;
#endif

typedef SBZIPSFXMaker__IMAGE_FILE_HEADER SBZIPSFXMaker_IMAGE_FILE_HEADER;

#pragma pack(1)
typedef struct 
{
	uint32_t Signature;
	SBZIPSFXMaker__IMAGE_FILE_HEADER FileHeader;
	SBZIPSFXMaker__IMAGE_OPTIONAL_HEADER OptionalHeader;
#ifndef WINCE
} SBZIPSFXMaker__IMAGE_NT_HEADERS, * SBZIPSFXMaker_PImageNtHeaders;
#else
} SBZIPSFXMaker__IMAGE_NT_HEADERS, * PImageNtHeaders;
#endif

#ifndef WINCE
typedef SBZIPSFXMaker__IMAGE_NT_HEADERS SBZIPSFXMaker_TImageNtHeaders;
#else
typedef SBZIPSFXMaker__IMAGE_NT_HEADERS TImageNtHeaders;
#endif

typedef SBZIPSFXMaker__IMAGE_NT_HEADERS SBZIPSFXMaker_IMAGE_NT_HEADERS;

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
#ifndef WINCE
} SBZIPSFXMaker_TISHMisc;
#else
} TISHMisc;
#endif

#pragma pack(1)
typedef struct 
{
	uint8_t Name[8];
#ifndef WINCE
	SBZIPSFXMaker_TISHMisc Misc;
#else
	TISHMisc Misc;
#endif
	uint32_t VirtualAddress;
	uint32_t SizeOfRawData;
	uint32_t PointerToRawData;
	uint32_t PointerToRelocations;
	uint32_t PointerToLinenumbers;
	uint16_t NumberOfRelocations;
	uint16_t NumberOfLinenumbers;
	uint32_t Characteristics;
#ifndef WINCE
} SBZIPSFXMaker__IMAGE_SECTION_HEADER, * SBZIPSFXMaker_PImageSectionHeader;
#else
} SBZIPSFXMaker__IMAGE_SECTION_HEADER, * PImageSectionHeader;
#endif

#ifndef WINCE
typedef SBZIPSFXMaker__IMAGE_SECTION_HEADER SBZIPSFXMaker_TImageSectionHeader;
#else
typedef SBZIPSFXMaker__IMAGE_SECTION_HEADER TImageSectionHeader;
#endif

typedef SBZIPSFXMaker__IMAGE_SECTION_HEADER SBZIPSFXMaker_IMAGE_SECTION_HEADER;

#ifdef SB_USE_CLASS_TELZIPSFXMAKER
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXMaker_Execute(TElZIPSFXMakerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXMaker_get_Copyright(TElZIPSFXMakerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXMaker_set_Copyright(TElZIPSFXMakerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXMaker_get_Title(TElZIPSFXMakerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXMaker_set_Title(TElZIPSFXMakerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXMaker_get_OnProgress(TElZIPSFXMakerHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXMaker_set_OnProgress(TElZIPSFXMakerHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXMaker_Create(TStreamHandle AStub, TStreamHandle AOutput, TElZIPSFXMakerHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPSFXMAKER */
#endif

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef SB_WINDOWS
#ifdef __cplusplus

// Class forward declaration
class TElZIPSFXMaker;

#ifdef SB_USE_CLASS_TELZIPSFXMAKER
class TElZIPSFXMaker: public TObject
{
	private:
		SB_DISABLE_COPY(TElZIPSFXMaker)
	public:
		bool Execute();

		virtual void get_Copyright(std::string &OutResult);

		virtual void set_Copyright(const std::string &Value);

		virtual void get_Title(std::string &OutResult);

		virtual void set_Title(const std::string &Value);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		TElZIPSFXMaker(TElZIPSFXMakerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TSTREAM
		TElZIPSFXMaker(TStream &AStub, TStream &AOutput);

		TElZIPSFXMaker(TStream *AStub, TStream *AOutput);
#endif /* SB_USE_CLASS_TSTREAM */

};
#endif /* SB_USE_CLASS_TELZIPSFXMAKER */

#endif  /* __cplusplus */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBZIPSFXMAKER */
