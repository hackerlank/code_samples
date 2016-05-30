#ifndef __INC_SBCHSCONVBASE
#define __INC_SBCHSCONVBASE

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

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_UCS_Count 	1114112
#define SB_UCSCharByteOrderLE32 	65279
#define SB_UCSCharByteOrderBE32 	4294836224
#define SB_UCSCharByteOrderLE16 	65279
#define SB_UCSCharByteOrderBE16 	65534
#define SB_UCSCharIgnore 	65535
#define SB_UCSCharIllegal 	65533
#define SB_MAX_CHARACTER_LENGTH 	16
#define SB_cNilPrefixes 	NULL
#define SB_cNilHiBytes 	NULL
#define SB_cNilConvTable 	NULL

typedef TStreamHandle SBChSConvBase_TElNativeStreamHandle;

typedef TElClassHandle TPlCharsetHandle;

typedef TElClassHandle TPlTableCharsetHandle;

typedef TElClassHandle TPlMixedCharsetHandle;

typedef TElClassHandle TPlConvertingCharsetHandle;

typedef TElClassHandle TPlASCIIHandle;

typedef TElClassHandle TPlISO_8859_1Handle;

typedef TElClassHandle IPlConvBufferHandle;

typedef TElClassHandle IPlCharsetHandle;

typedef TElClassHandle TPlCharsetClassHandle;

typedef uint8_t * SBChSConvBase_PByte;

typedef uint16_t * SBChSConvBase_PWord;

typedef uint32_t * PLong;

typedef uint32_t TPlPrefixes[8];

typedef TPlPrefixes * PPlPrefixes;

typedef uint8_t TPlHiBytes[256];

typedef TPlHiBytes * PPlHiBytes;

typedef uint16_t TPlChars[256];

typedef TPlChars * PPlChars;

#pragma pack(1)
typedef struct 
{
	PPlChars Chars;
	PPlHiBytes HiBytes;
	TPlPrefixes * Prefixes;
	uint8_t CharsLoIndex;
	uint8_t CharsHiIndex;
	uint8_t PriorPageIndex;
	uint8_t PriorPageChar;
} TPlConversionPage, * PPlConversionPage;

typedef TPlConversionPage TPlConversionPages[256];

typedef TPlConversionPages * PPlConversionPages;

#pragma pack(1)
typedef struct 
{
	uint8_t Page;
	uint8_t Char;
} TPlUCSToMultiByteItem;

#pragma pack(4)
typedef struct 
{
	int32_t MaxDirectMapped;
	int32_t PagesCount;
	PPlConversionPages Pages;
	uint32_t BackItemsCount;
	union
	{
		struct
		{
			int64_t _dummy0;
			int64_t _dummy1;
			uint8_t * (* ToSingleByte);
		} S1;
		struct
		{
			int64_t _dummy0;
			int64_t _dummy1;
			TPlUCSToMultiByteItem * (* ToMultiByte);
		} S2;
	};
} TPlConversionTable, * PPlConversionTable;

typedef Pointer TPlCharsetClassPtr;

typedef void (SB_CALLBACK *TCharsetCreateProc)(void * Handle, IPlCharsetHandle * OutResult);

typedef void (SB_CALLBACK *TCharsetLibraryRegProc)(char * Category, char * Description, char * Aliases, void * Handle, void * CreateProc);

#ifdef SB_USE_CLASS_TPLCHARSET
SB_IMPORT uint32_t SB_APIENTRY TPlCharset_CanConvert(TPlCharsetHandle _Handle, uint32_t Char, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCharset_ConvertFromUCS(TPlCharsetHandle _Handle, uint32_t Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCharset_ConvertToUCS(TPlCharsetHandle _Handle, TStreamHandle Stream, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCharset_ConvertBufferToUCS(TPlCharsetHandle _Handle, const void * Buf, int32_t Count, int8_t IsLastChunk, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCharset_ConvertBufferToUTF16(TPlCharsetHandle _Handle, const void * SrcBuf, int32_t SrcCount, int8_t IsLastChunk, void * DstBuf, int32_t * DstCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCharset_GetCategory(TPlCharsetHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCharset_GetDescription(TPlCharsetHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCharset_GetName(TPlCharsetHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCharset_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCharset_Create(TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCharset_CreateShift(int32_t Shift, TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCharset_CreateNoInit(TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCharset_CreateForFinalize(TPlCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCHARSET */

#ifdef SB_USE_CLASS_TPLTABLECHARSET
SB_IMPORT uint32_t SB_APIENTRY TPlTableCharset_CanConvert(TPlTableCharsetHandle _Handle, uint32_t Char, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlTableCharset_ConvertFromUCS(TPlTableCharsetHandle _Handle, uint32_t Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlTableCharset_ConvertToUCS(TPlTableCharsetHandle _Handle, TStreamHandle Stream, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlTableCharset_ConvertBufferToUCS(TPlTableCharsetHandle _Handle, const void * Buf, int32_t Count, int8_t IsLastChunk, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlTableCharset_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlTableCharset_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlTableCharset_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLTABLECHARSET */

#ifdef SB_USE_CLASS_TPLMIXEDCHARSET
SB_IMPORT uint32_t SB_APIENTRY TPlMixedCharset_CanConvert(TPlMixedCharsetHandle _Handle, uint32_t Char, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMixedCharset_ConvertFromUCS(TPlMixedCharsetHandle _Handle, uint32_t Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMixedCharset_ConvertToUCS(TPlMixedCharsetHandle _Handle, TStreamHandle Stream, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMixedCharset_ConvertBufferToUCS(TPlMixedCharsetHandle _Handle, const void * Buf, int32_t Count, int8_t IsLastChunk, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMixedCharset_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMixedCharset_Create(TPlMixedCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMixedCharset_CreateShift(int32_t Shift, TPlMixedCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLMIXEDCHARSET */

#ifdef SB_USE_CLASS_TPLCONVERTINGCHARSET
SB_IMPORT uint32_t SB_APIENTRY TPlConvertingCharset_CanConvert(TPlConvertingCharsetHandle _Handle, uint32_t Char, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlConvertingCharset_ConvertFromUCS(TPlConvertingCharsetHandle _Handle, uint32_t Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlConvertingCharset_ConvertToUCS(TPlConvertingCharsetHandle _Handle, TStreamHandle Stream, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlConvertingCharset_ConvertBufferToUCS(TPlConvertingCharsetHandle _Handle, const void * Buf, int32_t Count, int8_t IsLastChunk, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlConvertingCharset_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlConvertingCharset_Create(TPlConvertingCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCONVERTINGCHARSET */

#ifdef SB_USE_CLASS_TPLASCII
SB_IMPORT uint32_t SB_APIENTRY TPlASCII_GetCategory(TPlASCIIHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlASCII_GetDescription(TPlASCIIHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlASCII_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlASCII_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlASCII_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLASCII */

#ifdef SB_USE_CLASS_TPLISO_8859_1
SB_IMPORT uint32_t SB_APIENTRY TPlISO_8859_1_GetCategory(TPlISO_8859_1Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_8859_1_GetDescription(TPlISO_8859_1Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_8859_1_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_8859_1_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_8859_1_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLISO_8859_1 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
typedef TStream SBChSConvBase_TElNativeStream;
class TPlCharset;
class TPlTableCharset;
class TPlMixedCharset;
class TPlConvertingCharset;
class TPlASCII;
class TPlISO_8859_1;

#ifdef SB_USE_CLASS_TPLCHARSET
class TPlCharset: public TInterfacedObject
{
	private:
		SB_DISABLE_COPY(TPlCharset)
	public:
		virtual bool CanConvert(uint32_t Char);

		virtual int32_t ConvertFromUCS(uint32_t Char);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t ConvertToUCS(TStream &Stream, uint32_t &Char);

		virtual int32_t ConvertToUCS(TStream *Stream, uint32_t &Char);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char);

		int32_t ConvertBufferToUTF16(const void * SrcBuf, int32_t SrcCount, bool IsLastChunk, void * DstBuf, int32_t &DstCount);

		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		virtual void GetName(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCharset(TPlCharsetHandle handle, TElOwnHandle ownHandle);

		TPlCharset();

		static TPlCharset CreateShift(int32_t Shift);

		static TPlCharset CreateNoInit();

		static TPlCharset CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCHARSET */

#ifdef SB_USE_CLASS_TPLTABLECHARSET
class TPlTableCharset: public TPlCharset
{
	private:
		SB_DISABLE_COPY(TPlTableCharset)
	public:
		virtual bool CanConvert(uint32_t Char);

		virtual int32_t ConvertFromUCS(uint32_t Char);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t ConvertToUCS(TStream &Stream, uint32_t &Char);

		virtual int32_t ConvertToUCS(TStream *Stream, uint32_t &Char);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char);

		static TClassHandle ClassType();

		TPlTableCharset(TPlTableCharsetHandle handle, TElOwnHandle ownHandle);

		TPlTableCharset();

		static TPlTableCharset CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLTABLECHARSET */

#ifdef SB_USE_CLASS_TPLMIXEDCHARSET
class TPlMixedCharset: public TPlCharset
{
	private:
		SB_DISABLE_COPY(TPlMixedCharset)
	public:
		virtual bool CanConvert(uint32_t Char);

		virtual int32_t ConvertFromUCS(uint32_t Char);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t ConvertToUCS(TStream &Stream, uint32_t &Char);

		virtual int32_t ConvertToUCS(TStream *Stream, uint32_t &Char);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char);

		static TClassHandle ClassType();

		TPlMixedCharset(TPlMixedCharsetHandle handle, TElOwnHandle ownHandle);

		TPlMixedCharset();

		static TPlMixedCharset CreateShift(int32_t Shift);

};
#endif /* SB_USE_CLASS_TPLMIXEDCHARSET */

#ifdef SB_USE_CLASS_TPLCONVERTINGCHARSET
class TPlConvertingCharset: public TPlCharset
{
	private:
		SB_DISABLE_COPY(TPlConvertingCharset)
	public:
		virtual bool CanConvert(uint32_t Char);

		virtual int32_t ConvertFromUCS(uint32_t Char);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t ConvertToUCS(TStream &Stream, uint32_t &Char);

		virtual int32_t ConvertToUCS(TStream *Stream, uint32_t &Char);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char);

		static TClassHandle ClassType();

		TPlConvertingCharset(TPlConvertingCharsetHandle handle, TElOwnHandle ownHandle);

		TPlConvertingCharset();

};
#endif /* SB_USE_CLASS_TPLCONVERTINGCHARSET */

#ifdef SB_USE_CLASS_TPLASCII
class TPlASCII: public TPlTableCharset
{
	private:
		SB_DISABLE_COPY(TPlASCII)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlASCII(TPlASCIIHandle handle, TElOwnHandle ownHandle);

		TPlASCII();

		static TPlASCII CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLASCII */

#ifdef SB_USE_CLASS_TPLISO_8859_1
class TPlISO_8859_1: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlISO_8859_1)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlISO_8859_1(TPlISO_8859_1Handle handle, TElOwnHandle ownHandle);

		TPlISO_8859_1();

		static TPlISO_8859_1 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLISO_8859_1 */

#ifdef SB_USE_GLOBAL_PROCS_CHSCONVBASE

void RegisterCharset(TPlCharsetClassHandle CharsetClass);

void UnregisterCharset(TPlCharsetClassHandle CharsetClass);

void RegisterCharsetLibrary(void * RegistrationProc);

void AbstractError(const std::string &ClassName, const std::string &Method);

#endif /* SB_USE_GLOBAL_PROCS_CHSCONVBASE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_CHSCONVBASE
SB_IMPORT uint32_t SB_APIENTRY SBChSConvBase_RegisterCharset(TPlCharsetClassHandle CharsetClass);
SB_IMPORT uint32_t SB_APIENTRY SBChSConvBase_UnregisterCharset(TPlCharsetClassHandle CharsetClass);
SB_IMPORT uint32_t SB_APIENTRY SBChSConvBase_RegisterCharsetLibrary(void * RegistrationProc);
SB_IMPORT uint32_t SB_APIENTRY SBChSConvBase_AbstractError(const char * pcClassName, int32_t szClassName, const char * pcMethod, int32_t szMethod);
SB_IMPORT uint32_t SB_APIENTRY SBChSConvBase_Initialize(void);
#endif /* SB_USE_GLOBAL_PROCS_CHSCONVBASE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCHSCONVBASE */

