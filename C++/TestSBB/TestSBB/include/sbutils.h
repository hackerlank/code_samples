#ifndef __INC_SBUTILS
#define __INC_SBUTILS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbconstants.h"
#include "sbmath.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SBB_VERSION_NUMBER 	"14.0.292.0"
#define SBB_VERSION_RELEASE_NUMBER 	"14"
#define SBB_HOMEPAGE 	"https://www.eldos.com/SecureBlackbox/"
#define SB_ERROR_FACILITY_INTERNAL 	256
#define SB_ERROR_FACILITY_CRYPTO_BASE 	512
#define SB_ERROR_FACILITY_PDF 	720896
#define SB_ERROR_FACILITY_XML 	724992
#define SB_ERROR_FACILITY_SOAP 	729088
#define SB_ERROR_FACILITY_OFFICE 	733184
#define SB_ERROR_LICENSE_TRIAL_RESTRICTION 	257
#define SB_ERROR_LICENSE_FUNCTION_NOT_LICENSED 	258
#define SB_ERROR_LICENSE_KEY_EXPIRED 	259
#define SB_ERROR_LICENSE_KEY_NOT_SET 	260
#define SB_ERROR_LICENSE_KEY_INVALID 	261
#define SB_ERROR_LICENSE_KEY_BIZCRYPTO 	262
#define SB_ERROR_LICENSE_KEY_NOT_BIZCRYPTO 	263
#define SB_ERROR_LICENSE_KEY_CANNOT_BE_USED_WITH_APP 	264
#define SB_ERROR_CRYPTO_NOT_IMPLEMENTED 	513
#define SB_ERROR_CRYPTO_RSA_ANTITIMING_NOT_INIT 	514
#define SB_ERROR_CRYPTO_DSA_KEY_NOT_LOADED 	515
#define SB_ERROR_CRYPTO_DSA_KEY_FORMAT_INVALID 	516
#define SB_COREDLL 	"coredll.dll"
#define SB_OLE32 	"ole32.dll"
#define SB_KERNEL32 	"kernel32.dll"
#define SB_NTDLL 	"ntdll.dll"
#define SB_SRegexUnsupported 	"Regular expressions in masks are not supported in this version of compiler / platform"
#define SB_SInvalidInputSize 	"Invalid input block size"
#define SB_SInvalidKeySize 	"Invalid key size [%d bits]"
#define SB_SInvalidUInt16BufferOffset 	"Cannot get 2 bytes at offset %d (buffer size is %d)"
#define SB_SInvalidUInt32BufferOffset 	"Cannot get 4 bytes at offset %d (buffer size is %d)"
#define SB_SInvalidOID 	"Invalid object identifier"
#define SB_sOutputBufferTooSmall 	"Output buffer too small"
#define SB_SUnicodeNotInitialized 	"Unicode module is not initialized. Please execute a SBUnicode.Unit.Initialize() call at the very start of your project."
#define SB_SUnsupportedCharset 	"Unsupported charset"
#define SB_SOperationCancelled 	"Synchronous operation has been cancelled"
#define SB_SArrayIndexOutOfBounds 	"Array index is out of bounds"
#define SB_SStringIndexOutOfBounds 	"String index is out of bounds"
#define SB_SArrayLengthOutOfBounds 	"Array length is out of bounds"
#define SB_SBufferCannotBeNull 	"Buffer cannot be empty"
#define SB_SStringCannotBeNull 	"String cannot be empty"
#define SB_SLicenseKeyNotSet 	"SecureBlackbox license key is not set. Please pass production or evaluation license key to SBUtils.SetLicenseKey function in initialization section of your application.\r\nIf this message appears in design-time, place TElSBLicenseManager component on the form and put the key to LicenseKey property.\r\nEvaluation license key can be found in <SecureBlackbox folder>\\LicenseKey.txt file"
#define SB_SInvalidDateToken 	"Invalid date token (%s)"
#define SB_SInvalidTimeToken 	"Invalid time token (%s)"
#define SB_SOldLicenseKey 	"Provided license key is valid for old version of SecureBlackbox and not the current one. Please upgrade your license."
#define SB_SUnknownLicenseKey 	"Provided license key is valid for version of SecureBlackbox, other than current one. Please check the version of SecureBlackbox and your license."
#define SB_SLicenseKeyExpired 	"Time-limited SecureBlackbox license key has expired. Please use evaluation license key to continue evaluation."
#define SB_SLicenseTypeNotEnabled 	"Your SecureBlackbox license key doesn\'t enable the requested functionality. Please check if you have a license for the components that you are trying to use."
#define SB_SBadOrOldLicenseKey 	"Provided license key is invalid or is valid for version of SecureBlackbox, other than current one. Please check that the license key is pasted correctly and your license covers current SecureBlackbox version."
#define SB_SAutomaticKeyExpired 	"Your time-limited SecureBlackbox license key has expired. Please use evaluation license key to continue evaluation or request license prolongation via the HelpDesk system."
#define SB_SBadLicenseKeyFormat 	"Bad SecureBlackbox license key format. Please re-check that you\'ve copied and pasted your (or evaluation) license key correctly to your application code. A correct license key is a very long line of letters and numbers (512 characters altogether), which should be passed to the SetLicenseKey() call unchanged and in its entirety."
#define SB_SLicenseKeyCannotBeUsedWithApp 	"Provided license key cannot be used with this application. Please re-check that all your license conditions are met."
#define SB_SSeekOffsetRangeError 	"Seek offset is out of Int32 range"
#define SB_SBase32InvalidDataSize 	"Input data size must be multiple of 8"
#define SB_SBase32InvalidData 	"Input buffer contains invalid data that is not base32 encoded"

typedef TComponentHandle TSBComponentBaseHandle;

typedef TComponentHandle TSBControlBaseHandle;

typedef TObjectHandle TSBDisposableBaseHandle;

typedef TListHandle TElListHandle;

typedef TListHandle TElIntegerListHandle;

#ifdef SB_WINDOWS
typedef TStringListHandle TElStringListHandle;
#else
typedef TElClassHandle TElStringListHandle;
#endif

typedef TElClassHandle TElByteArrayListHandle;

typedef TElClassHandle TSBObjectListHandle;

typedef TElClassHandle TElCustomExceptionHandlerHandle;

typedef TElClassHandle TElStandardExceptionHandlerHandle;

typedef TElClassHandle TElDebugExceptionHandlerHandle;

typedef void (SB_CALLBACK *TSBTextDataEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pTextLine[], int32_t szTextLine);

typedef void (SB_CALLBACK *TSBProgressEvent)(void * _ObjectData, TObjectHandle Sender, int64_t Total, int64_t Current, int8_t * Cancel);

typedef void (SB_CALLBACK *TSBProgressFunc)(void * _ObjectData, int64_t Total, int64_t Current, void * Data, int8_t * Cancel);

typedef void (SB_CALLBACK *TElMessageLoopEvent)(void * _ObjectData, int8_t * OutResult);

typedef uint8_t TSBLicenseTypeRaw;

typedef enum
{
	ltPKI = 0,
	ltSSLC = 1,
	ltSSLS = 2,
	ltSSHC = 3,
	ltSSHS = 4,
	ltSFTP = 5,
	ltSFTPS = 6,
	ltPGP = 7,
	ltMIME = 8,
	ltTrial = 9,
	ltPDF = 10,
	ltXML = 11,
	ltFTPSC = 12,
	ltHTTPC = 13,
	ltBizTalk = 14,
	ltZIP = 15,
	ltEDI = 16,
	ltOffice = 17,
	ltEmpty = 18,
	ltDummy1 = 19,
	ltDummy2 = 20,
	ltCloud = 21,
	ltXMPP = 22,
	ltFTPSS = 23,
	ltHTTPS = 24,
	ltWebDAVCli = 25,
	ltDC = 26,
	ltMail = 27,
	ltWebDAVSrv = 28,
	ltLDAP = 29,
	ltSAML = 30
} TSBLicenseType;

typedef uint32_t TSBLicenseTypesRaw;

typedef enum 
{
	f_ltPKI = 1,
	f_ltSSLC = 2,
	f_ltSSLS = 4,
	f_ltSSHC = 8,
	f_ltSSHS = 16,
	f_ltSFTP = 32,
	f_ltSFTPS = 64,
	f_ltPGP = 128,
	f_ltMIME = 256,
	f_ltTrial = 512,
	f_ltPDF = 1024,
	f_ltXML = 2048,
	f_ltFTPSC = 4096,
	f_ltHTTPC = 8192,
	f_ltBizTalk = 16384,
	f_ltZIP = 32768,
	f_ltEDI = 65536,
	f_ltOffice = 131072,
	f_ltEmpty = 262144,
	f_ltDummy1 = 524288,
	f_ltDummy2 = 1048576,
	f_ltCloud = 2097152,
	f_ltXMPP = 4194304,
	f_ltFTPSS = 8388608,
	f_ltHTTPS = 16777216,
	f_ltWebDAVCli = 33554432,
	f_ltDC = 67108864,
	f_ltMail = 134217728,
	f_ltWebDAVSrv = 268435456,
	f_ltLDAP = 536870912,
	f_ltSAML = 1073741824
} TSBLicenseTypes;

typedef uint8_t TSBExceptionHandlerDestinationRaw;

typedef enum
{
	ehdDefault = 0,
	ehdDebug = 1,
	ehdTrace = 2,
	ehdStdErr = 3,
	ehdStdOut = 4
} TSBExceptionHandlerDestination;

#ifndef SB_WINDOWS
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_IMPORT uint32_t SB_APIENTRY TElStringList_Create(TElStringListHandle * OutResult);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
SB_IMPORT uint32_t SB_APIENTRY TElByteArrayList_Add(TElByteArrayListHandle _Handle, const uint8_t pS[], int32_t szS, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElByteArrayList_AddRange(TElByteArrayListHandle _Handle, TElByteArrayListHandle List);
SB_IMPORT uint32_t SB_APIENTRY TElByteArrayList_Assign(TElByteArrayListHandle _Handle, TElByteArrayListHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElByteArrayList_Clear(TElByteArrayListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElByteArrayList_Delete(TElByteArrayListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElByteArrayList_IndexOf(TElByteArrayListHandle _Handle, const uint8_t pS[], int32_t szS, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElByteArrayList_Insert(TElByteArrayListHandle _Handle, int32_t Index, const uint8_t pS[], int32_t szS);
SB_IMPORT uint32_t SB_APIENTRY TElByteArrayList_get_Capacity(TElByteArrayListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElByteArrayList_set_Capacity(TElByteArrayListHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElByteArrayList_get_Count(TElByteArrayListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElByteArrayList_get_Item(TElByteArrayListHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElByteArrayList_set_Item(TElByteArrayListHandle _Handle, int32_t Index, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElByteArrayList_Create(TElByteArrayListHandle * OutResult);
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

#ifdef SB_USE_CLASS_TSBOBJECTLIST
SB_IMPORT uint32_t SB_APIENTRY TSBObjectList_Add(TSBObjectListHandle _Handle, TObjectHandle AObject, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBObjectList_Remove(TSBObjectListHandle _Handle, TObjectHandle AObject, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBObjectList_IndexOf(TSBObjectListHandle _Handle, TObjectHandle AObject, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBObjectList_Insert(TSBObjectListHandle _Handle, int32_t Index, TObjectHandle AObject);
SB_IMPORT uint32_t SB_APIENTRY TSBObjectList_FindInstanceOf(TSBObjectListHandle _Handle, TClassHandle AClass, int8_t AExact, int32_t AStartAt, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBObjectList_Extract(TSBObjectListHandle _Handle, TObjectHandle Item, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBObjectList_get_OwnsObjects(TSBObjectListHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBObjectList_set_OwnsObjects(TSBObjectListHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TSBObjectList_get_Items_TObject(TSBObjectListHandle _Handle, int32_t Index, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBObjectList_set_Items_TObject(TSBObjectListHandle _Handle, int32_t Index, TObjectHandle AObject);
SB_IMPORT uint32_t SB_APIENTRY TSBObjectList_Create(TSBObjectListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBObjectList_Create_1(int8_t AOwnsObjects, TSBObjectListHandle * OutResult);
#endif /* SB_USE_CLASS_TSBOBJECTLIST */

#ifdef SB_USE_CLASS_TELCUSTOMEXCEPTIONHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElCustomExceptionHandler_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMEXCEPTIONHANDLER */

#ifdef SB_USE_CLASS_TELSTANDARDEXCEPTIONHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElStandardExceptionHandler_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELSTANDARDEXCEPTIONHANDLER */

#ifdef SB_USE_CLASS_TELDEBUGEXCEPTIONHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElDebugExceptionHandler_get_Destination(TElDebugExceptionHandlerHandle _Handle, TSBExceptionHandlerDestinationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDebugExceptionHandler_set_Destination(TElDebugExceptionHandlerHandle _Handle, TSBExceptionHandlerDestinationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElDebugExceptionHandler_Create(TElDebugExceptionHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELDEBUGEXCEPTIONHANDLER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
typedef TComponent TSBComponentBase;
typedef TComponent TSBControlBase;
typedef TObject TSBDisposableBase;
typedef TList TElList;
typedef TList TElIntegerList;
#ifdef SB_WINDOWS
typedef TStringList TElStringList;
#else
class TElStringList;
#endif
class TElByteArrayList;
class TSBObjectList;
class TElCustomExceptionHandler;
class TElStandardExceptionHandler;
class TElDebugExceptionHandler;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBLicenseTypes)

#ifndef SB_WINDOWS
#ifdef SB_USE_CLASS_TELSTRINGLIST
class TElStringList: public TStringList
{
	private:
		SB_DISABLE_COPY(TElStringList)
	public:
		TElStringList(TElStringListHandle handle, TElOwnHandle ownHandle);

		TElStringList();

};
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
class TElByteArrayList: public TObject
{
	private:
		SB_DISABLE_COPY(TElByteArrayList)
	public:
		int32_t Add(const std::vector<uint8_t> &S);

		void AddRange(TElByteArrayList &List);

		void AddRange(TElByteArrayList *List);

		void Assign(TElByteArrayList &Source);

		void Assign(TElByteArrayList *Source);

		void Clear();

		void Delete(int32_t Index);

		int32_t IndexOf(const std::vector<uint8_t> &S);

		void Insert(int32_t Index, const std::vector<uint8_t> &S);

		virtual int32_t get_Capacity();

		virtual void set_Capacity(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Capacity, set_Capacity, TElByteArrayList, Capacity);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElByteArrayList, Count);

		virtual void get_Item(int32_t Index, std::vector<uint8_t> &OutResult);

		virtual void set_Item(int32_t Index, const std::vector<uint8_t> &Value);

		TElByteArrayList(TElByteArrayListHandle handle, TElOwnHandle ownHandle);

		TElByteArrayList();

};
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

#ifdef SB_USE_CLASS_TSBOBJECTLIST
class TSBObjectList: public TList
{
	private:
		SB_DISABLE_COPY(TSBObjectList)
		TObject* _Inst_Items;

		void initInstances();

	public:
		int32_t Add(TObject &AObject);

		int32_t Add(TObject *AObject);

		int32_t Remove(TObject &AObject);

		int32_t Remove(TObject *AObject);

		int32_t IndexOf(TObject &AObject);

		int32_t IndexOf(TObject *AObject);

		void Insert(int32_t Index, TObject &AObject);

		void Insert(int32_t Index, TObject *AObject);

		int32_t FindInstanceOf(TClassHandle AClass, bool AExact, int32_t AStartAt);

		TObjectHandle Extract(TObject &Item);

		TObjectHandle Extract(TObject *Item);

		virtual bool get_OwnsObjects();

		virtual void set_OwnsObjects(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OwnsObjects, set_OwnsObjects, TSBObjectList, OwnsObjects);

		virtual TObject* get_Items_TObject(int32_t Index);

		virtual void set_Items_TObject(int32_t Index, TObject &AObject);

		virtual void set_Items_TObject(int32_t Index, TObject *AObject);

		TSBObjectList(TSBObjectListHandle handle, TElOwnHandle ownHandle);

		TSBObjectList();

		explicit TSBObjectList(bool AOwnsObjects);

		virtual ~TSBObjectList();

};
#endif /* SB_USE_CLASS_TSBOBJECTLIST */

#ifdef SB_USE_CLASS_TELCUSTOMEXCEPTIONHANDLER
class TElCustomExceptionHandler: public TObject
{
	private:
		SB_DISABLE_COPY(TElCustomExceptionHandler)
	public:
		TElCustomExceptionHandler(TElCustomExceptionHandlerHandle handle, TElOwnHandle ownHandle);

		TElCustomExceptionHandler();

};
#endif /* SB_USE_CLASS_TELCUSTOMEXCEPTIONHANDLER */

#ifdef SB_USE_CLASS_TELSTANDARDEXCEPTIONHANDLER
class TElStandardExceptionHandler: public TElCustomExceptionHandler
{
	private:
		SB_DISABLE_COPY(TElStandardExceptionHandler)
	public:
		TElStandardExceptionHandler(TElStandardExceptionHandlerHandle handle, TElOwnHandle ownHandle);

		TElStandardExceptionHandler();

};
#endif /* SB_USE_CLASS_TELSTANDARDEXCEPTIONHANDLER */

#ifdef SB_USE_CLASS_TELDEBUGEXCEPTIONHANDLER
class TElDebugExceptionHandler: public TElStandardExceptionHandler
{
	private:
		SB_DISABLE_COPY(TElDebugExceptionHandler)
	public:
		virtual TSBExceptionHandlerDestination get_Destination();

		virtual void set_Destination(TSBExceptionHandlerDestination Value);

		SB_DECLARE_PROPERTY(TSBExceptionHandlerDestination, get_Destination, set_Destination, TElDebugExceptionHandler, Destination);

		TElDebugExceptionHandler(TElDebugExceptionHandlerHandle handle, TElOwnHandle ownHandle);

		TElDebugExceptionHandler();

};
#endif /* SB_USE_CLASS_TELDEBUGEXCEPTIONHANDLER */

#ifdef SB_USE_GLOBAL_PROCS_UTILS

void DigestToStr(const TMessageDigest128 &Digest, bool LowerCase, std::string &OutResult);

void DigestToStr(const TMessageDigest160 &Digest, bool LowerCase, std::string &OutResult);

void DigestToStr(const TMessageDigest224 &Digest, bool LowerCase, std::string &OutResult);

void DigestToStr(const TMessageDigest256 &Digest, bool LowerCase, std::string &OutResult);

void DigestToStr(const TMessageDigest320 &Digest, bool LowerCase, std::string &OutResult);

void DigestToStr(const TMessageDigest384 &Digest, bool LowerCase, std::string &OutResult);

void DigestToStr(const TMessageDigest512 &Digest, bool LowerCase, std::string &OutResult);

bool StrToDigest(const std::string &DigestStr, TMessageDigest128 &Digest);

bool StrToDigest(const std::string &DigestStr, TMessageDigest160 &Digest);

void DigestToBinary(const TMessageDigest128 &Digest, std::vector<uint8_t> &OutResult);

void DigestToBinary(const TMessageDigest160 &Digest, std::vector<uint8_t> &OutResult);

bool BinaryToDigest(const std::vector<uint8_t> &Binary, TMessageDigest128 &Digest);

bool BinaryToDigest(const std::vector<uint8_t> &Binary, TMessageDigest160 &Digest);

void DigestToByteArray128(const TMessageDigest128 &Digest, std::vector<uint8_t> &OutResult);

void DigestToByteArray160(const TMessageDigest160 &Digest, std::vector<uint8_t> &OutResult);

void DigestToByteArray224(const TMessageDigest224 &Digest, std::vector<uint8_t> &OutResult);

void DigestToByteArray256(const TMessageDigest256 &Digest, std::vector<uint8_t> &OutResult);

void DigestToByteArray320(const TMessageDigest320 &Digest, std::vector<uint8_t> &OutResult);

void DigestToByteArray384(const TMessageDigest384 &Digest, std::vector<uint8_t> &OutResult);

void DigestToByteArray512(const TMessageDigest512 &Digest, std::vector<uint8_t> &OutResult);

bool ByteArrayToDigest128(const std::vector<uint8_t> &Binary, int32_t Position, TMessageDigest128 &Digest);

bool ByteArrayToDigest160(const std::vector<uint8_t> &Binary, int32_t Position, TMessageDigest160 &Digest);

bool ByteArrayToDigest224(const std::vector<uint8_t> &Binary, int32_t Position, TMessageDigest224 &Digest);

bool ByteArrayToDigest256(const std::vector<uint8_t> &Binary, int32_t Position, TMessageDigest256 &Digest);

bool ByteArrayToDigest320(const std::vector<uint8_t> &Binary, int32_t Position, TMessageDigest320 &Digest);

bool ByteArrayToDigest384(const std::vector<uint8_t> &Binary, int32_t Position, TMessageDigest384 &Digest);

bool ByteArrayToDigest512(const std::vector<uint8_t> &Binary, int32_t Position, TMessageDigest512 &Digest);

void PointerToLIntP(PLInt &B, void * P, int32_t Size);

void PointerToLInt(PLInt &B, const std::vector<uint8_t> &P, int32_t Size);

void LIntToPointerP(PLInt B, void * P, int32_t &Size);

void LIntToPointer(PLInt B, const std::vector<uint8_t> &P, int32_t &Size);

void LIntToPointerTrunc(PLInt B, void * P, int32_t &Size);

int32_t BufferBitCount(void * Buffer, int32_t Size);

void BeautifyBinaryString(const std::string &Str, char Separator, std::string &OutResult);

void SwapUInt16(uint16_t Value, std::vector<uint8_t> &Buffer);

void SwapUInt16(uint16_t Value, std::vector<uint8_t> &Buffer, int32_t &Index);

uint16_t SwapUInt16(const std::vector<uint8_t> &Buffer, uint32_t Offset);

int32_t SwapInt32(int32_t value);

void SwapUInt32(uint32_t Value, std::vector<uint8_t> &Buffer);

void SwapUInt32(uint32_t Value, std::vector<uint8_t> &Buffer, int32_t &Index);

uint32_t SwapUInt32(const std::vector<uint8_t> &Buffer, uint32_t Offset);

uint32_t SwapUInt32(uint32_t value);

int64_t SwapInt64(int64_t value);

void SwapSomeInt(int32_t Value, std::vector<uint8_t> &OutResult);

void RotateInteger(const std::vector<uint8_t> &Value, std::vector<uint8_t> &OutResult);

void TrimZeros(const std::vector<uint8_t> &Value, std::vector<uint8_t> &OutResult);

void ZeroArray(int32_t Size, std::vector<uint8_t> &OutResult);

void SubArray(const std::vector<uint8_t> &Arr, int32_t Index, int32_t Size, std::vector<uint8_t> &OutResult);

void SwapBigEndianWords(void * P, int32_t Size);

void SwapBigEndianDWords(void * P, int32_t Size);

bool IsEmptyDateTime(int64_t DT);

int64_t EmptyDateTime();

void SBMove(const void * SourcePointer, void * DestinationPointer, int32_t CopyCount);

void SBMove(const std::vector<uint8_t> &Src, int32_t SrcOffset, const std::vector<uint8_t> &Dst, int32_t DstOffset, int32_t Size);

void TrimLeadingZeros(const std::vector<uint8_t> &V, std::vector<uint8_t> &OutResult);

void TrimTrailingZeros(const std::vector<uint8_t> &V, std::vector<uint8_t> &OutResult);

void PrefixByteArray(const std::vector<uint8_t> &Buffer, int32_t Count, uint8_t Value, std::vector<uint8_t> &OutResult);

void SuffixByteArray(const std::vector<uint8_t> &Buffer, int32_t Count, uint8_t Value, std::vector<uint8_t> &OutResult);

void FillByteArray(const std::vector<uint8_t> &Buffer, int32_t SrcOffset, int32_t Count, uint8_t Value);

void FillByteArray(const std::vector<uint8_t> &Buffer, uint8_t Value);

void GetBytes64(int64_t X, std::vector<uint8_t> &OutResult);

void GetBytes64(int64_t X, std::vector<uint8_t> &Buffer, int32_t Index);

void GetBytes32(uint32_t X, std::vector<uint8_t> &OutResult);

void GetBytes32(uint32_t X, std::vector<uint8_t> &Buffer, int32_t Index);

void GetBytes16(uint16_t X, std::vector<uint8_t> &OutResult);

void GetBytes16(uint16_t X, std::vector<uint8_t> &Buffer, int32_t Index);

void GetBytes8(uint8_t X, std::vector<uint8_t> &OutResult);

void GetBytes8(uint8_t X, std::vector<uint8_t> &Buffer, int32_t Index);

int64_t LocalDateTimeToSystemDateTime(int64_t ADateTime);

int64_t SystemDateTimeToLocalDateTime(int64_t ADateTime);

int64_t DateTimeAddMillis(int64_t DateTime, int32_t Millis);

int64_t DateTimeAddDays(int64_t DateTime, int32_t Days);

int64_t DateTimeAddHours(int64_t DateTime, int32_t Hours);

int64_t DateTimeAddMinutes(int64_t DateTime, int32_t Minutes);

int64_t DateTimeAddSeconds(int64_t DateTime, int32_t Seconds);

int64_t DateTimeAddYears(int64_t DateTime, int32_t Years);

bool DateTimeAfter(int64_t DT1, int64_t DT2);

bool DateTimeBefore(int64_t DT1, int64_t DT2);

int64_t DateTimeClone(int64_t DateTime);

int32_t DateTimeCompare(int64_t DT1, int64_t DT2);

bool DateTimeEquals(int64_t DT1, int64_t DT2);

int32_t DateTimeGetMonth(int64_t DT);

int32_t DateTimeGetYear(int64_t DT);

bool DateTimeIsLeapYear(int32_t Year);

bool DateTimeIsLeapYear(int64_t DT);

int64_t DateTimeNow();

void DateTimeToString(int64_t DateTime, std::string &OutResult);

int64_t DateTimeUtcNow();

bool CompareMem(const std::vector<uint8_t> &Mem1, const std::vector<uint8_t> &Mem2);

bool CompareMem(const std::vector<uint8_t> &Mem1, int32_t Offset1, const std::vector<uint8_t> &Mem2, int32_t Offset2);

bool CompareMem(const std::vector<uint8_t> &Mem1, int32_t Offset1, const std::vector<uint8_t> &Mem2, int32_t Offset2, int32_t Size);

bool CompareMem(const void * Mem1, const void * Mem2, int32_t Size);

int32_t CompareBuffers(const std::vector<uint8_t> &Buf1, const std::vector<uint8_t> &Buf2);

bool CompareMD128(const TMessageDigest128 &M1, const TMessageDigest128 &M2);

bool CompareMD160(const TMessageDigest160 &M1, const TMessageDigest160 &M2);

bool CompareMD224(const TMessageDigest224 &M1, const TMessageDigest224 &M2);

bool CompareMD256(const TMessageDigest256 &M1, const TMessageDigest256 &M2);

bool CompareMD320(const TMessageDigest320 &M1, const TMessageDigest320 &M2);

bool CompareMD384(const TMessageDigest384 &M1, const TMessageDigest384 &M2);

bool CompareMD512(const TMessageDigest512 &M1, const TMessageDigest512 &M2);

bool CompareHashes(const std::vector<uint8_t> &Hash1, const std::vector<uint8_t> &Hash2);

bool CompareHashes(const std::vector<uint8_t> &Hash1, int32_t StartIndex1, int32_t Count1, const std::vector<uint8_t> &Hash2, int32_t StartIndex2, int32_t Count2);

void FreeAndNil(void * Obj);

int32_t GetDigestSizeBits(int32_t Algorithm);

bool EncodeDSASignature(void * R, int32_t RSize, void * S, int32_t SSize, void * Blob, int32_t &BlobSize);

bool DecodeDSASignature(void * Blob, int32_t Size, void * R, int32_t &RSize, void * S, int32_t &SSize);

bool CompareAnsiStr(const std::string &Content, const std::string &OID);

void ChangeByteOrder(const std::vector<uint8_t> &Buffer, std::vector<uint8_t> &OutResult);

void BinaryToString(const std::vector<uint8_t> &Buffer, std::string &OutResult);

void BinaryToString(const std::vector<uint8_t> &Buffer, int32_t Start, int32_t Count, std::string &OutResult);

void BinaryToString(void * Buffer, int32_t BufSize, std::string &OutResult);

bool StringToBinary(const std::string &S, void * Buffer, int32_t &Size);

bool CompareGUID(const TGuid &Guid1, const TGuid &Guid2);

void AnsiStringOfBytes(const std::vector<uint8_t> &Src, std::string &OutResult);

bool ArrayStartsWith(const std::vector<uint8_t> &SubP, const std::vector<uint8_t> &P);

int32_t CompareArrays(const std::vector<uint8_t> &Buf1, const std::vector<uint8_t> &Buf2);

void StringOfBytes(const std::vector<uint8_t> &Src, std::string &OutResult);

void StringOfBytes(const std::vector<uint8_t> &Src, int32_t ALow, int32_t ALen, std::string &OutResult);

void BytesOfString(const std::string &Str, std::vector<uint8_t> &OutResult);

void CreateByteArrayConst(const std::string &Src, std::vector<uint8_t> &OutResult);

void AnsiStringOfString(const std::string &Str, std::string &OutResult);

void StringOfAnsiString(const std::string &Str, std::string &OutResult);

void BytesOfAnsiString(const std::string &Str, std::vector<uint8_t> &OutResult);

void GetByteArrayFromByte(uint8_t Value, std::vector<uint8_t> &OutResult);

void GetByteArrayFromByte(uint8_t Value, const std::vector<uint8_t> &Dest, int32_t Position);

void GetByteArrayFromWordLE(uint16_t Value, std::vector<uint8_t> &OutResult);

void GetByteArrayFromWordLE(uint16_t Value, const std::vector<uint8_t> &Dest, int32_t Position);

void GetByteArrayFromWordBE(uint16_t Value, std::vector<uint8_t> &OutResult);

void GetByteArrayFromWordBE(uint16_t Value, const std::vector<uint8_t> &Dest, int32_t Position);

void GetByteArrayFromDWordLE(uint32_t Value, std::vector<uint8_t> &OutResult);

void GetByteArrayFromDWordLE(uint32_t Value, const std::vector<uint8_t> &Dest, int32_t Position);

void GetByteArrayFromDWordBE(uint32_t Value, std::vector<uint8_t> &OutResult);

void GetByteArrayFromDWordBE(uint32_t Value, const std::vector<uint8_t> &Dest, int32_t Position);

void GetByteArrayFromInt64LE(int64_t Value, std::vector<uint8_t> &OutResult);

void GetByteArrayFromInt64LE(int64_t Value, const std::vector<uint8_t> &Dest, int32_t Position);

void GetByteArrayFromInt64BE(int64_t Value, std::vector<uint8_t> &OutResult);

void GetByteArrayFromInt64BE(int64_t Value, const std::vector<uint8_t> &Dest, int32_t Position);

uint16_t GetWordLEFromByteArray(const std::vector<uint8_t> &Source, int32_t Position);

uint16_t GetWordBEFromByteArray(const std::vector<uint8_t> &Source, int32_t Position);

uint32_t GetDWordLEFromByteArray(const std::vector<uint8_t> &Source, int32_t Position);

uint32_t GetDWordBEFromByteArray(const std::vector<uint8_t> &Source, int32_t Position);

int64_t GetInt64LEFromByteArray(const std::vector<uint8_t> &Source, int32_t Position);

int64_t GetInt64BEFromByteArray(const std::vector<uint8_t> &Source, int32_t Position);

void WideStringOf(const std::vector<uint8_t> &Value, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void WideStringOf(const std::vector<uint8_t> &Value, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void WideBytesOf(const sb_u16string &Value, std::vector<uint8_t> &OutResult);
#ifdef SB_U16STRING_USED
void WideBytesOf(const std::wstring &Value, std::vector<uint8_t> &OutResult);
#endif /* SB_U16STRING_USED */

void EmptyAnsiString(std::string &OutResult);

void SBConcatArrays(const std::vector<uint8_t> &Buf1, const std::vector<uint8_t> &Buf2, std::vector<uint8_t> &OutResult);

void SBConcatArrays(const std::vector<uint8_t> &Buf1, const std::vector<uint8_t> &Buf2, const std::vector<uint8_t> &Buf3, std::vector<uint8_t> &OutResult);

void SBConcatArrays(const std::vector<uint8_t> &Buf1, uint8_t Buf2, std::vector<uint8_t> &OutResult);

void SBConcatArrays(uint8_t Buf1, const std::vector<uint8_t> &Buf2, std::vector<uint8_t> &OutResult);

void SBConcatArrays(uint8_t Buf1, uint8_t Buf2, const std::vector<uint8_t> &Buf3, std::vector<uint8_t> &OutResult);

void SBConcatArrays(uint8_t Buf1, const std::vector<uint8_t> &Buf2, const std::vector<uint8_t> &Buf3, std::vector<uint8_t> &OutResult);

bool ArrayEndsWith(const std::vector<uint8_t> &Buffer, const std::vector<uint8_t> &Substr);

bool DateStrToDate(const std::string &Time, int64_t &ADateTime);

bool ParseRFC822TimeString(const std::string &RFC822TimeString, int64_t &ADateTime);

int64_t RFC822TimeToDateTime(const std::string &RFC822Time);

int64_t UTCTimeToDate(const std::string &UTCTime, bool FourDigitYear);

int64_t UTCTimeToTime(const std::string &UTCTime, bool FourDigitYear);

int64_t UTCTimeToDateTime(const std::string &UTCTime, bool FourDigitYear);

int64_t GeneralizedTimeToDate(const std::string &GenTime);

int64_t GeneralizedTimeToTime(const std::string &GenTime);

int64_t GeneralizedTimeToDateTime(const std::string &GenTime);

void DateTimeToUTCTime(int64_t ADateTime, bool FourDigitYear, std::string &OutResult);

void DateTimeToGeneralizedTime(int64_t ADateTime, std::string &OutResult);

void DateTimeToGeneralizedTime(int64_t ADateTime, const std::string &DateTimeSplitPtn, std::string &OutResult);

void UniversalDateTimeToRFC822DateTimeString(int64_t DT, std::string &OutResult);

bool RFC822TimeStringToUniversalTime(const std::string &TS, int64_t &DT);

void LocalDateTimeToRFC822DateTimeString(int64_t ADateTime, std::string &OutResult);

void SystemDateTimeToRFC822DateTimeString(int64_t ADateTime, std::string &OutResult);

#ifdef SB_WINDOWS
int64_t FileTimeToDateTime(windows_FILETIME &Value);
#else
int64_t FileTimeToUnixTime(_FILETIME &Value);
#endif

#ifdef SB_WINDOWS
void DateTimeToFileTime(int64_t Value, windows_FILETIME &OutResult);
#else
void UnixTimeToFileTime(int64_t Value, _FILETIME &OutResult);
#endif

#ifndef SB_WINDOWS
int64_t FileTimeToDateTime(_FILETIME &Value);

void DateTimeToFileTime(int64_t Value, _FILETIME &OutResult);
#endif

int64_t UnixTimeToDateTime(int64_t Value);

int64_t DateTimeToUnixTime(int64_t Value);

int32_t ConstLength(const std::vector<uint8_t> &Arr);

uint32_t TickDiff(uint32_t Previous, uint32_t Current);

void GenerateGUID(std::string &OutResult);

bool IsTextualOID(const std::string &S);

#ifdef SB_WINDOWS
uint32_t WaitFor(uint32_t Handle);
#else
uint32_t GetTickCount();
#endif

#ifndef SB_WINDOWS
#ifdef SB_USE_CLASS_TTHREAD
uint32_t WaitFor(TThread &Thread);
uint32_t WaitFor(TThread *Thread);
#endif /* SB_USE_CLASS_TTHREAD */
#endif

int64_t LocalTimeToUTCTime(int64_t LocalTime);

int64_t UTCTimeToLocalTime(int64_t UtcTime);

int64_t UTCNow();

#ifdef SB_USE_CLASS_TOBJECT
void RegisterGlobalObject(TObject &O);
void RegisterGlobalObject(TObject *O);
#endif /* SB_USE_CLASS_TOBJECT */

#ifdef SB_USE_CLASS_TOBJECT
void UnregisterGlobalObject(TObject &O);
void UnregisterGlobalObject(TObject *O);
#endif /* SB_USE_CLASS_TOBJECT */

void CleanupRegisteredGlobalObjects();

void AcquireGlobalLock();

void ReleaseGlobalLock();

void HexDump(const std::vector<uint8_t> &Buffer, uint32_t Offset, uint32_t Len, std::string &OutResult);

void HexDump(const std::vector<uint8_t> &Buffer, uint32_t Offset, uint32_t Len, bool AddChars, std::string &OutResult);

bool SBSameDateTime(int64_t A, int64_t B);

bool SBSameDate(int64_t A, int64_t B);

bool SBSameTime(int64_t A, int64_t B);

int64_t SBEncodeDateTime(int32_t Year, int32_t Month, int32_t Day, int32_t Hour, int32_t Minute, int32_t Second, int32_t Millisecond);

int64_t GetUTCOffsetDateTime();

int64_t GetUTCOffsetDateTime(int64_t ADateTime);

bool CompareContent(const std::vector<uint8_t> &Content, const std::vector<uint8_t> &OID);

void DateTimeToISO8601Time(int64_t Time, bool EncodeMilliseconds, std::string &OutResult);

int64_t ISO8601TimeToDateTime(const std::string &EncodedTime);

void DateTimeToRFC3339(int64_t Value, bool EncodeMilliseconds, std::string &OutResult);

void SetLicenseKey(const std::string &Key);

void CheckLicenseKey();

void GetCompanyName(std::string &OutResult);

void GetUserName(std::string &OutResult);

TSBLicenseTypes GetLicense();

int32_t GetVersion();

uint32_t GetTimeLen();

int32_t GetRemainingDays();

void IntCheckA();

void IntCheckB();

void ShowNagScreen();

void AppendSlash(const std::string &Path, std::string &OutResult);

bool EnsureDirectoryExists(const std::string &DirName);

bool DirectoryExists(const std::string &DirName);

#ifndef SB_WINDOWS
uint32_t GetCurrentThreadID();
#endif

#ifdef SB_USE_CLASS_TELCUSTOMEXCEPTIONHANDLER
void SetDefaultExceptionHandler(TElCustomExceptionHandler &Handler);
void SetDefaultExceptionHandler(TElCustomExceptionHandler *Handler);
#endif /* SB_USE_CLASS_TELCUSTOMEXCEPTIONHANDLER */

#ifdef SB_USE_CLASS_TELCUSTOMEXCEPTIONHANDLER
TElCustomExceptionHandlerHandle GetDefaultExceptionHandler();
#endif /* SB_USE_CLASS_TELCUSTOMEXCEPTIONHANDLER */

#endif /* SB_USE_GLOBAL_PROCS_UTILS */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_UTILS
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DigestToStr(const TMessageDigest128 * Digest, int8_t LowerCase, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DigestToStr_1(const TMessageDigest160 * Digest, int8_t LowerCase, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DigestToStr_2(const TMessageDigest224 * Digest, int8_t LowerCase, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DigestToStr_3(const TMessageDigest256 * Digest, int8_t LowerCase, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DigestToStr_4(const TMessageDigest320 * Digest, int8_t LowerCase, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DigestToStr_5(const TMessageDigest384 * Digest, int8_t LowerCase, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DigestToStr_6(const TMessageDigest512 * Digest, int8_t LowerCase, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_StrToDigest(const char * pcDigestStr, int32_t szDigestStr, TMessageDigest128 * Digest, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_StrToDigest_1(const char * pcDigestStr, int32_t szDigestStr, TMessageDigest160 * Digest, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DigestToBinary(const TMessageDigest128 * Digest, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DigestToBinary_1(const TMessageDigest160 * Digest, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_BinaryToDigest(const uint8_t pBinary[], int32_t szBinary, TMessageDigest128 * Digest, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_BinaryToDigest_1(const uint8_t pBinary[], int32_t szBinary, TMessageDigest160 * Digest, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DigestToByteArray128(const TMessageDigest128 * Digest, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DigestToByteArray160(const TMessageDigest160 * Digest, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DigestToByteArray224(const TMessageDigest224 * Digest, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DigestToByteArray256(const TMessageDigest256 * Digest, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DigestToByteArray320(const TMessageDigest320 * Digest, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DigestToByteArray384(const TMessageDigest384 * Digest, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DigestToByteArray512(const TMessageDigest512 * Digest, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_ByteArrayToDigest128(const uint8_t pBinary[], int32_t szBinary, int32_t Position, TMessageDigest128 * Digest, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_ByteArrayToDigest160(const uint8_t pBinary[], int32_t szBinary, int32_t Position, TMessageDigest160 * Digest, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_ByteArrayToDigest224(const uint8_t pBinary[], int32_t szBinary, int32_t Position, TMessageDigest224 * Digest, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_ByteArrayToDigest256(const uint8_t pBinary[], int32_t szBinary, int32_t Position, TMessageDigest256 * Digest, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_ByteArrayToDigest320(const uint8_t pBinary[], int32_t szBinary, int32_t Position, TMessageDigest320 * Digest, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_ByteArrayToDigest384(const uint8_t pBinary[], int32_t szBinary, int32_t Position, TMessageDigest384 * Digest, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_ByteArrayToDigest512(const uint8_t pBinary[], int32_t szBinary, int32_t Position, TMessageDigest512 * Digest, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_PointerToLIntP(PLInt * B, void * P, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_PointerToLInt(PLInt * B, const uint8_t pP[], int32_t szP, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_LIntToPointerP(PLInt B, void * P, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_LIntToPointer(PLInt B, const uint8_t pP[], int32_t szP, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_LIntToPointerTrunc(PLInt B, void * P, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_BufferBitCount(void * Buffer, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_BeautifyBinaryString(const char * pcStr, int32_t szStr, char Separator, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SwapUInt16(uint16_t Value, uint8_t pBuffer[], int32_t * szBuffer);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SwapUInt16_1(uint16_t Value, uint8_t pBuffer[], int32_t * szBuffer, int32_t * Index);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SwapUInt16_2(const uint8_t pBuffer[], int32_t szBuffer, uint32_t Offset, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SwapInt32(int32_t value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SwapUInt32(uint32_t Value, uint8_t pBuffer[], int32_t * szBuffer);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SwapUInt32_1(uint32_t Value, uint8_t pBuffer[], int32_t * szBuffer, int32_t * Index);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SwapUInt32_2(const uint8_t pBuffer[], int32_t szBuffer, uint32_t Offset, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SwapUInt32_3(uint32_t value, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SwapInt64(int64_t value, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SwapSomeInt(int32_t Value, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_RotateInteger(const uint8_t pValue[], int32_t szValue, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_TrimZeros(const uint8_t pValue[], int32_t szValue, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_ZeroArray(int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SubArray(const uint8_t pArr[], int32_t szArr, int32_t Index, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SwapBigEndianWords(void * P, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SwapBigEndianDWords(void * P, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_IsEmptyDateTime(int64_t DT, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_EmptyDateTime(int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SBMove(const void * SourcePointer, void * DestinationPointer, int32_t CopyCount);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SBMove_1(const uint8_t pSrc[], int32_t szSrc, int32_t SrcOffset, const uint8_t pDst[], int32_t szDst, int32_t DstOffset, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_TrimLeadingZeros(const uint8_t pV[], int32_t szV, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_TrimTrailingZeros(const uint8_t pV[], int32_t szV, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_PrefixByteArray(const uint8_t pBuffer[], int32_t szBuffer, int32_t Count, uint8_t Value, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SuffixByteArray(const uint8_t pBuffer[], int32_t szBuffer, int32_t Count, uint8_t Value, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_FillByteArray(const uint8_t pBuffer[], int32_t szBuffer, int32_t SrcOffset, int32_t Count, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_FillByteArray_1(const uint8_t pBuffer[], int32_t szBuffer, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetBytes64(int64_t X, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetBytes64_1(int64_t X, uint8_t pBuffer[], int32_t * szBuffer, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetBytes32(uint32_t X, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetBytes32_1(uint32_t X, uint8_t pBuffer[], int32_t * szBuffer, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetBytes16(uint16_t X, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetBytes16_1(uint16_t X, uint8_t pBuffer[], int32_t * szBuffer, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetBytes8(uint8_t X, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetBytes8_1(uint8_t X, uint8_t pBuffer[], int32_t * szBuffer, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_LocalDateTimeToSystemDateTime(int64_t ADateTime, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SystemDateTimeToLocalDateTime(int64_t ADateTime, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeAddMillis(int64_t DateTime, int32_t Millis, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeAddDays(int64_t DateTime, int32_t Days, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeAddHours(int64_t DateTime, int32_t Hours, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeAddMinutes(int64_t DateTime, int32_t Minutes, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeAddSeconds(int64_t DateTime, int32_t Seconds, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeAddYears(int64_t DateTime, int32_t Years, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeAfter(int64_t DT1, int64_t DT2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeBefore(int64_t DT1, int64_t DT2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeClone(int64_t DateTime, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeCompare(int64_t DT1, int64_t DT2, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeEquals(int64_t DT1, int64_t DT2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeGetMonth(int64_t DT, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeGetYear(int64_t DT, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeIsLeapYear(int32_t Year, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeIsLeapYear_1(int64_t DT, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeNow(int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeToString(int64_t DateTime, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeUtcNow(int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CompareMem(const uint8_t pMem1[], int32_t szMem1, const uint8_t pMem2[], int32_t szMem2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CompareMem_1(const uint8_t pMem1[], int32_t szMem1, int32_t Offset1, const uint8_t pMem2[], int32_t szMem2, int32_t Offset2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CompareMem_2(const uint8_t pMem1[], int32_t szMem1, int32_t Offset1, const uint8_t pMem2[], int32_t szMem2, int32_t Offset2, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CompareMem_3(const void * Mem1, const void * Mem2, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CompareBuffers(const uint8_t pBuf1[], int32_t szBuf1, const uint8_t pBuf2[], int32_t szBuf2, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CompareMD128(const TMessageDigest128 * M1, const TMessageDigest128 * M2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CompareMD160(const TMessageDigest160 * M1, const TMessageDigest160 * M2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CompareMD224(const TMessageDigest224 * M1, const TMessageDigest224 * M2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CompareMD256(const TMessageDigest256 * M1, const TMessageDigest256 * M2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CompareMD320(const TMessageDigest320 * M1, const TMessageDigest320 * M2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CompareMD384(const TMessageDigest384 * M1, const TMessageDigest384 * M2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CompareMD512(const TMessageDigest512 * M1, const TMessageDigest512 * M2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CompareHashes(const uint8_t pHash1[], int32_t szHash1, const uint8_t pHash2[], int32_t szHash2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CompareHashes_1(const uint8_t pHash1[], int32_t szHash1, int32_t StartIndex1, int32_t Count1, const uint8_t pHash2[], int32_t szHash2, int32_t StartIndex2, int32_t Count2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_FreeAndNil(void * Obj);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetDigestSizeBits(int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_EncodeDSASignature(void * R, int32_t RSize, void * S, int32_t SSize, void * Blob, int32_t * BlobSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DecodeDSASignature(void * Blob, int32_t Size, void * R, int32_t * RSize, void * S, int32_t * SSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CompareAnsiStr(const char * pcContent, int32_t szContent, const char * pcOID, int32_t szOID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_ChangeByteOrder(const uint8_t pBuffer[], int32_t szBuffer, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_BinaryToString(const uint8_t pBuffer[], int32_t szBuffer, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_BinaryToString_1(const uint8_t pBuffer[], int32_t szBuffer, int32_t Start, int32_t Count, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_BinaryToString_2(void * Buffer, int32_t BufSize, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_StringToBinary(const char * pcS, int32_t szS, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CompareGUID(const TGuid * Guid1, const TGuid * Guid2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_AnsiStringOfBytes(const uint8_t pSrc[], int32_t szSrc, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_ArrayStartsWith(const uint8_t pSubP[], int32_t szSubP, const uint8_t pP[], int32_t szP, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CompareArrays(const uint8_t pBuf1[], int32_t szBuf1, const uint8_t pBuf2[], int32_t szBuf2, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_StringOfBytes(const uint8_t pSrc[], int32_t szSrc, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_StringOfBytes_1(const uint8_t pSrc[], int32_t szSrc, int32_t ALow, int32_t ALen, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_BytesOfString(const char * pcStr, int32_t szStr, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CreateByteArrayConst(const char * pcSrc, int32_t szSrc, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_AnsiStringOfString(const char * pcStr, int32_t szStr, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_StringOfAnsiString(const char * pcStr, int32_t szStr, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_BytesOfAnsiString(const char * pcStr, int32_t szStr, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetByteArrayFromByte(uint8_t Value, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetByteArrayFromByte_1(uint8_t Value, const uint8_t pDest[], int32_t szDest, int32_t Position);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetByteArrayFromWordLE(uint16_t Value, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetByteArrayFromWordLE_1(uint16_t Value, const uint8_t pDest[], int32_t szDest, int32_t Position);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetByteArrayFromWordBE(uint16_t Value, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetByteArrayFromWordBE_1(uint16_t Value, const uint8_t pDest[], int32_t szDest, int32_t Position);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetByteArrayFromDWordLE(uint32_t Value, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetByteArrayFromDWordLE_1(uint32_t Value, const uint8_t pDest[], int32_t szDest, int32_t Position);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetByteArrayFromDWordBE(uint32_t Value, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetByteArrayFromDWordBE_1(uint32_t Value, const uint8_t pDest[], int32_t szDest, int32_t Position);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetByteArrayFromInt64LE(int64_t Value, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetByteArrayFromInt64LE_1(int64_t Value, const uint8_t pDest[], int32_t szDest, int32_t Position);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetByteArrayFromInt64BE(int64_t Value, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetByteArrayFromInt64BE_1(int64_t Value, const uint8_t pDest[], int32_t szDest, int32_t Position);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetWordLEFromByteArray(const uint8_t pSource[], int32_t szSource, int32_t Position, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetWordBEFromByteArray(const uint8_t pSource[], int32_t szSource, int32_t Position, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetDWordLEFromByteArray(const uint8_t pSource[], int32_t szSource, int32_t Position, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetDWordBEFromByteArray(const uint8_t pSource[], int32_t szSource, int32_t Position, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetInt64LEFromByteArray(const uint8_t pSource[], int32_t szSource, int32_t Position, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetInt64BEFromByteArray(const uint8_t pSource[], int32_t szSource, int32_t Position, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_WideStringOf(const uint8_t pValue[], int32_t szValue, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_WideBytesOf(const sb_char16_t * pcValue, int32_t szValue, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_EmptyAnsiString(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SBConcatArrays(const uint8_t pBuf1[], int32_t szBuf1, const uint8_t pBuf2[], int32_t szBuf2, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SBConcatArrays_1(const uint8_t pBuf1[], int32_t szBuf1, const uint8_t pBuf2[], int32_t szBuf2, const uint8_t pBuf3[], int32_t szBuf3, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SBConcatArrays_2(const uint8_t pBuf1[], int32_t szBuf1, uint8_t Buf2, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SBConcatArrays_3(uint8_t Buf1, const uint8_t pBuf2[], int32_t szBuf2, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SBConcatArrays_4(uint8_t Buf1, uint8_t Buf2, const uint8_t pBuf3[], int32_t szBuf3, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SBConcatArrays_5(uint8_t Buf1, const uint8_t pBuf2[], int32_t szBuf2, const uint8_t pBuf3[], int32_t szBuf3, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_ArrayEndsWith(const uint8_t pBuffer[], int32_t szBuffer, const uint8_t pSubstr[], int32_t szSubstr, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateStrToDate(const char * pcTime, int32_t szTime, int64_t * ADateTime, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_ParseRFC822TimeString(const char * pcRFC822TimeString, int32_t szRFC822TimeString, int64_t * ADateTime, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_RFC822TimeToDateTime(const char * pcRFC822Time, int32_t szRFC822Time, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_UTCTimeToDate(const char * pcUTCTime, int32_t szUTCTime, int8_t FourDigitYear, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_UTCTimeToTime(const char * pcUTCTime, int32_t szUTCTime, int8_t FourDigitYear, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_UTCTimeToDateTime(const char * pcUTCTime, int32_t szUTCTime, int8_t FourDigitYear, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GeneralizedTimeToDate(const char * pcGenTime, int32_t szGenTime, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GeneralizedTimeToTime(const char * pcGenTime, int32_t szGenTime, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GeneralizedTimeToDateTime(const char * pcGenTime, int32_t szGenTime, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeToUTCTime(int64_t ADateTime, int8_t FourDigitYear, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeToGeneralizedTime(int64_t ADateTime, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeToGeneralizedTime_1(int64_t ADateTime, const char * pcDateTimeSplitPtn, int32_t szDateTimeSplitPtn, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_UniversalDateTimeToRFC822DateTimeString(int64_t DT, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_RFC822TimeStringToUniversalTime(const char * pcTS, int32_t szTS, int64_t * DT, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_LocalDateTimeToRFC822DateTimeString(int64_t ADateTime, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SystemDateTimeToRFC822DateTimeString(int64_t ADateTime, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY SBUtils_FileTimeToDateTime(windows_FILETIME * Value, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeToFileTime(int64_t Value, windows_FILETIME * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY SBUtils_FileTimeToUnixTime(_FILETIME * Value, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_UnixTimeToFileTime(int64_t Value, _FILETIME * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_FileTimeToDateTime(_FILETIME * Value, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeToFileTime(int64_t Value, _FILETIME * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY SBUtils_UnixTimeToDateTime(int64_t Value, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeToUnixTime(int64_t Value, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_ConstLength(const uint8_t pArr[], int32_t szArr, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_TickDiff(uint32_t Previous, uint32_t Current, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GenerateGUID(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_IsTextualOID(const char * pcS, int32_t szS, int8_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY SBUtils_WaitFor(uint32_t Handle, uint32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetTickCount(uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_WaitFor(TThreadHandle Thread, uint32_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY SBUtils_LocalTimeToUTCTime(int64_t LocalTime, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_UTCTimeToLocalTime(int64_t UtcTime, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_UTCNow(int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_RegisterGlobalObject(TObjectHandle O);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_UnregisterGlobalObject(TObjectHandle O);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CleanupRegisteredGlobalObjects(void);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_AcquireGlobalLock(void);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_ReleaseGlobalLock(void);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_HexDump(const uint8_t pBuffer[], int32_t szBuffer, uint32_t Offset, uint32_t Len, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_HexDump_1(const uint8_t pBuffer[], int32_t szBuffer, uint32_t Offset, uint32_t Len, int8_t AddChars, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SBSameDateTime(int64_t A, int64_t B, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SBSameDate(int64_t A, int64_t B, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SBSameTime(int64_t A, int64_t B, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SBEncodeDateTime(int32_t Year, int32_t Month, int32_t Day, int32_t Hour, int32_t Minute, int32_t Second, int32_t Millisecond, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetUTCOffsetDateTime(int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetUTCOffsetDateTime_1(int64_t ADateTime, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CompareContent(const uint8_t pContent[], int32_t szContent, const uint8_t pOID[], int32_t szOID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeToISO8601Time(int64_t Time, int8_t EncodeMilliseconds, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_ISO8601TimeToDateTime(const char * pcEncodedTime, int32_t szEncodedTime, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DateTimeToRFC3339(int64_t Value, int8_t EncodeMilliseconds, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SetLicenseKey(const char * pcKey, int32_t szKey);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_CheckLicenseKey(void);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetCompanyName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetUserName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetLicense(TSBLicenseTypesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetVersion(int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetTimeLen(uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetRemainingDays(int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_IntCheckA(void);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_IntCheckB(void);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_ShowNagScreen(void);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_AppendSlash(const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_EnsureDirectoryExists(const char * pcDirName, int32_t szDirName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_DirectoryExists(const char * pcDirName, int32_t szDirName, int8_t * OutResult);
#ifndef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetCurrentThreadID(uint32_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY SBUtils_SetDefaultExceptionHandler(TElCustomExceptionHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY SBUtils_GetDefaultExceptionHandler(TElCustomExceptionHandlerHandle * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_UTILS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBUTILS */
