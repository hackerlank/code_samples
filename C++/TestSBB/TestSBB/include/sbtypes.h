#ifndef __INC_SBTYPES
#define __INC_SBTYPES

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
#define SB_MaxArrSize 	2147483647

typedef TStreamHandle TElInputStreamHandle;

typedef TStreamHandle TElOutputStreamHandle;

typedef TObjectHandle TSBObjectHandle;

typedef TElClassHandle TElStringHolderHandle;

typedef TElClassHandle TElByteArrayHolderHandle;

typedef PWideString PUnicodeString;

typedef uint32_t * pUTF32;

typedef uint16_t * pUTF16;

typedef uint8_t * pUTF8;

typedef uint8_t TSBHostRoleRaw;

typedef enum
{
	hrNone = 0,
	hrServer = 1,
	hrClient = 2,
	hrBoth = 3
} TSBHostRole;

#ifndef SB_WINDOWS
#pragma pack(4)
typedef struct 
{
	uint32_t dwLowDateTime;
	uint32_t dwHighDateTime;
} _FILETIME, * PFileTime;

typedef _FILETIME SBTypes_FILETIME;

typedef _FILETIME TFileTime;

#pragma pack(8)
typedef struct 
{
	union
	{
		struct
		{
			uint32_t LowPart;
			int32_t HighPart;
		} S1;
		struct
		{
			int64_t QuadPart;
		} S2;
	};
} _LARGE_INTEGER;

typedef _LARGE_INTEGER SBTypes_LARGE_INTEGER;

#pragma pack(8)
typedef struct 
{
	union
	{
		struct
		{
			uint32_t LowPart;
			uint32_t HighPart;
		} S1;
		struct
		{
			int64_t QuadPart;
		} S2;
	};
} _ULARGE_INTEGER;

typedef _ULARGE_INTEGER ULARGE_INTEGER;
#endif

typedef uint16_t * SBTypes_PWord;

typedef int32_t * PInt;

typedef uint32_t * PLongWord;

typedef int32_t * PLongint;

#ifndef SB_WINCE_OR_NOT_WINDOWS
typedef int64_t * SBTypes_PInt64;
#else
typedef int64_t * PInt64;
#endif

typedef uint32_t * PCardinal;

typedef uint32_t * SBTypes_PUInt32;

typedef int32_t * PInt32;

typedef uint8_t TSBFileTransferModeRaw;

typedef enum
{
	ftmOverwrite = 0,
	ftmSkip = 1,
	ftmAppendToEnd = 2,
	ftmResume = 3,
	ftmOverwriteIfDiffSize = 4,
	ftmSaveWithNewName = 5,
	ftmRenameExistingTarget = 6
} TSBFileTransferMode;

typedef uint8_t TSBFileCopyModeRaw;

typedef enum
{
	fcmCopy = 0,
	fcmCopyAndDeleteImmediate = 1,
	fcmCopyAndDeleteOnCompletion = 2
} TSBFileCopyMode;

typedef uint8_t TSBParamQuoteModeRaw;

typedef enum
{
	pqmNone = 0,
	pqmWithSpace = 1,
	pqmAll = 2
} TSBParamQuoteMode;

typedef uint8_t TSBEOLMarkerRaw;

typedef enum
{
	emCRLF = 0,
	emCR = 1,
	emLF = 2,
	emNone = 3
} TSBEOLMarker;

typedef uint8_t TSBCaseConversionRaw;

typedef enum
{
	sccNone = 0,
	sccLower = 1,
	sccUpper = 2
} TSBCaseConversion;

typedef uint8_t TSBOperationErrorHandlingRaw;

typedef enum
{
	oehTryAllItems = 0,
	oehStopOnFailure = 1,
	oehIgnoreErrors = 2
} TSBOperationErrorHandling;

#pragma pack(1)
typedef struct 
{
	uint32_t A;
	uint32_t B;
	uint32_t C;
	uint32_t D;
} TMessageDigest128;

#pragma pack(1)
typedef struct 
{
	uint32_t A;
	uint32_t B;
	uint32_t C;
	uint32_t D;
	uint32_t E;
} TMessageDigest160;

#pragma pack(1)
typedef struct 
{
	uint32_t A1;
	uint32_t B1;
	uint32_t C1;
	uint32_t D1;
	uint32_t A2;
	uint32_t B2;
	uint32_t C2;
} TMessageDigest224;

#pragma pack(1)
typedef struct 
{
	uint32_t A1;
	uint32_t B1;
	uint32_t C1;
	uint32_t D1;
	uint32_t A2;
	uint32_t B2;
	uint32_t C2;
	uint32_t D2;
} TMessageDigest256;

#pragma pack(1)
typedef struct 
{
	uint32_t A1;
	uint32_t B1;
	uint32_t C1;
	uint32_t D1;
	uint32_t E1;
	uint32_t A2;
	uint32_t B2;
	uint32_t C2;
	uint32_t D2;
	uint32_t E2;
} TMessageDigest320;

#pragma pack(1)
typedef struct 
{
	int64_t A;
	int64_t B;
	int64_t C;
	int64_t D;
	int64_t E;
	int64_t F;
} TMessageDigest384;

#pragma pack(1)
typedef struct 
{
	int64_t A1;
	int64_t B1;
	int64_t C1;
	int64_t D1;
	int64_t A2;
	int64_t B2;
	int64_t C2;
	int64_t D2;
} TMessageDigest512;

#pragma pack(4)
typedef struct 
{
	uint32_t A;
	uint32_t B;
} TSBUInt32Pair;

typedef uint8_t ConversionResultRaw;

typedef enum
{
	conversionOK = 0,
	sourceExhausted = 1,
	targetExhausted = 2,
	sourceIllegal = 3
} ConversionResult;

typedef uint8_t ConversionFlagsRaw;

typedef enum
{
	strictConversion = 0,
	lenientConversion = 1
} ConversionFlags;

typedef void * (* SBTypes_PPointer);

#ifdef SB_USE_CLASS_TELSTRINGHOLDER
SB_IMPORT uint32_t SB_APIENTRY TElStringHolder_get_Value(TElStringHolderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStringHolder_set_Value(TElStringHolderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElStringHolder_Create(const char * pcData, int32_t szData, TElStringHolderHandle * OutResult);
#endif /* SB_USE_CLASS_TELSTRINGHOLDER */

#ifdef SB_USE_CLASS_TELBYTEARRAYHOLDER
SB_IMPORT uint32_t SB_APIENTRY TElByteArrayHolder_get_Value(TElByteArrayHolderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElByteArrayHolder_set_Value(TElByteArrayHolderHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElByteArrayHolder_Create(const uint8_t pData[], int32_t szData, TElByteArrayHolderHandle * OutResult);
#endif /* SB_USE_CLASS_TELBYTEARRAYHOLDER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
typedef TStream TElInputStream;
typedef TStream TElOutputStream;
typedef TObject TSBObject;
class TElStringHolder;
class TElByteArrayHolder;

#ifdef SB_USE_CLASS_TELSTRINGHOLDER
class TElStringHolder: public TObject
{
	private:
		SB_DISABLE_COPY(TElStringHolder)
	public:
		virtual void get_Value(std::string &OutResult);

		virtual void set_Value(const std::string &Value);

		TElStringHolder(TElStringHolderHandle handle, TElOwnHandle ownHandle);

		explicit TElStringHolder(const std::string &Data);

};
#endif /* SB_USE_CLASS_TELSTRINGHOLDER */

#ifdef SB_USE_CLASS_TELBYTEARRAYHOLDER
class TElByteArrayHolder: public TObject
{
	private:
		SB_DISABLE_COPY(TElByteArrayHolder)
	public:
		virtual void get_Value(std::vector<uint8_t> &OutResult);

		virtual void set_Value(const std::vector<uint8_t> &Value);

		TElByteArrayHolder(TElByteArrayHolderHandle handle, TElOwnHandle ownHandle);

		explicit TElByteArrayHolder(const std::vector<uint8_t> &Data);

};
#endif /* SB_USE_CLASS_TELBYTEARRAYHOLDER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBTYPES */
