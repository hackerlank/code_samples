#ifndef __INC_SBZIPUTILS
#define __INC_SBZIPUTILS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbstreams.h"
#include "sbhashfunction.h"
#include "sbcrc.h"
#include "sbarcbase.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ZIP_COMPRESSION_STORED 	0
#define SB_ZIP_COMPRESSION_SHRUNK 	1
#define SB_ZIP_COMPRESSION_REDUCE_1 	2
#define SB_ZIP_COMPRESSION_REDUCE_2 	3
#define SB_ZIP_COMPRESSION_REDUCE_3 	4
#define SB_ZIP_COMPRESSION_REDUCE_4 	5
#define SB_ZIP_COMPRESSION_IMPLODE 	6
#define SB_ZIP_COMPRESSION_TOKENIZING 	7
#define SB_ZIP_COMPRESSION_DEFLATE 	8
#define SB_ZIP_COMPRESSION_DEFLATE64 	9
#define SB_ZIP_COMPRESSION_TERSE_OLD 	10
#define SB_ZIP_COMPRESSION_BZIP2 	12
#define SB_ZIP_COMPRESSION_LZMA 	14
#define SB_ZIP_COMPRESSION_TERSE_NEW 	18
#define SB_ZIP_COMPRESSION_LZ77 	19
#define SB_ZIP_COMPRESSION_WAVPACK 	97
#define SB_ZIP_COMPRESSION_PPMD_V1 	98
#define SB_ZIP_COMPRESSION_WINZIP_AES 	99
#define SB_ZIP_COMPRESSION_UNKNOWN 	65535
#define SB_ZIP_FILEATTR_MSDOS 	0
#define SB_ZIP_FILEATTR_AMIGA 	1
#define SB_ZIP_FILEATTR_OpenVMS 	2
#define SB_ZIP_FILEATTR_UNIX 	3
#define SB_ZIP_FILEATTR_VM_CMS 	4
#define SB_ZIP_FILEATTR_ATARI_ST 	5
#define SB_ZIP_FILEATTR_OS2_HPFS 	6
#define SB_ZIP_FILEATTR_MACINTOSH 	7
#define SB_ZIP_FILEATTR_ZSYSTEM 	8
#define SB_ZIP_FILEATTR_CP_M 	9
#define SB_ZIP_FILEATTR_WIN_NTFS 	10
#define SB_ZIP_FILEATTR_MVS 	11
#define SB_ZIP_FILEATTR_VSE 	12
#define SB_ZIP_FILEATTR_ACORN_RISC 	13
#define SB_ZIP_FILEATTR_VFAT 	14
#define SB_ZIP_FILEATTR_ALT_MVS 	15
#define SB_ZIP_FILEATTR_BEOS 	16
#define SB_ZIP_FILEATTR_TANDEM 	17
#define SB_ZIP_FILEATTR_OS400 	18
#define SB_ZIP_FILEATTR_OSX 	19
#define SB_ZIP_VERSION_1_0 	10
#define SB_ZIP_VERSION_1_1 	11
#define SB_ZIP_VERSION_2_0 	20
#define SB_ZIP_VERSION_2_1 	21
#define SB_ZIP_VERSION_2_5 	25
#define SB_ZIP_VERSION_2_7 	27
#define SB_ZIP_VERSION_4_5 	45
#define SB_ZIP_VERSION_4_6 	46
#define SB_ZIP_VERSION_5_0 	50
#define SB_ZIP_VERSION_5_1 	51
#define SB_ZIP_VERSION_5_2 	52
#define SB_ZIP_VERSION_6_1 	61
#define SB_ZIP_VERSION_6_2 	62
#define SB_ZIP_VERSION_6_3 	63
#define SB_ZIP_EXTENSION_ZIP64 	1
#define SB_ZIP_EXTENSION_AV_INFO 	7
#define SB_ZIP_EXTENSION_PFS 	8
#define SB_ZIP_EXTENSION_OS2 	9
#define SB_ZIP_EXTENSION_NTFS 	10
#define SB_ZIP_EXTENSION_OPENVMS 	12
#define SB_ZIP_EXTENSION_UNIX 	13
#define SB_ZIP_EXTENSION_DESCRIPTORS 	14
#define SB_ZIP_EXTENSION_PATCH 	15
#define SB_ZIP_EXTENSION_PKCS7_STORE 	20
#define SB_ZIP_EXTENSION_FILE_SIGNATURE 	21
#define SB_ZIP_EXTENSION_CDIR_SIGNATURE 	22
#define SB_ZIP_EXTENSION_STRONG_ENCRYPTION 	23
#define SB_ZIP_EXTENSION_RECORD_MANAGEMENT 	24
#define SB_ZIP_EXTENSION_PKCS7_RECIPIENTS 	25
#define SB_ZIP_EXTENSION_IBM_ATTRIBUTES 	101
#define SB_ZIP_EXTENSION_IBM_ATTRIBUTES_CMP 	102
#define SB_ZIP_EXTENSION_POSZIP_4690 	18064
#define SB_ZIP_EXTENSION_EXTENDED_TIMESTAMP 	21589
#define SB_ZIP_EXTENSION_UNIX1 	22613
#define SB_ZIP_EXTENSION_UNIX2 	30805
#define SB_ZIP_EXTENSION_UID_GID 	30837
#define SB_ZIP_EXTENSION_WINZIP_AES 	39169
#define SB_ZIP_HASH_NONE 	0
#define SB_ZIP_HASH_CRC32 	1
#define SB_ZIP_HASH_MD5 	32771
#define SB_ZIP_HASH_SHA1 	32772
#define SB_ZIP_HASH_RIPEMD160 	32775
#define SB_ZIP_HASH_SHA256 	32780
#define SB_ZIP_HASH_SHA384 	32781
#define SB_ZIP_HASH_SHA512 	32782
#define SB_ZIP_ENCRYPTION_NONE 	0
#define SB_ZIP_ENCRYPTION_DES 	26113
#define SB_ZIP_ENCRYPTION_RC2_OLD 	26114
#define SB_ZIP_ENCRYPTION_3DES168 	26115
#define SB_ZIP_ENCRYPTION_3DES112 	26121
#define SB_ZIP_ENCRYPTION_AES128 	26126
#define SB_ZIP_ENCRYPTION_AES192 	26127
#define SB_ZIP_ENCRYPTION_AES256 	26128
#define SB_ZIP_ENCRYPTION_RC2_NEW 	26370
#define SB_ZIP_ENCRYPTION_BLOWFISH 	26400
#define SB_ZIP_ENCRYPTION_TWOFISH 	26401
#define SB_ZIP_ENCRYPTION_RC4 	26625
#define SB_ZIP_ENCRYPTION_UNKNOWN 	65535
#define SB_ZIP_STRONG_ENCR_PASSWORD_NEEDED 	1
#define SB_ZIP_STRONG_ENCR_CERTIFICATE_NEEDED 	2
#define SB_ZIP_STRONG_ENCR_NO_OAEP 	256
#define SB_ZIP_STRONG_ENCR_USE_3DES 	16384

#pragma pack(1)
typedef struct 
{
	uint32_t K0;
	uint32_t K1;
	uint32_t K2;
} TSBZIPEncryptionContext;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_ZIPUTILS

uint32_t BufferToUINT16(const std::vector<uint8_t> &Buffer, int32_t Index);

void UINT16ToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, uint32_t Value);

uint32_t BufferToUINT32(const std::vector<uint8_t> &Buffer, int32_t Index);

void SBZipUtils_UINT32ToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, uint32_t Value);

int64_t BufferToUINT64(const std::vector<uint8_t> &Buffer, int32_t Index);

void UINT64ToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, int64_t Value);

void ReverseBuffer(const std::vector<uint8_t> &Buffer, std::vector<uint8_t> &OutResult);

void ZipInitializeEncryption(TSBZIPEncryptionContext &Context);

void ZipUpdateKeys(TSBZIPEncryptionContext &Context, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

void ZipEncrypt(TSBZIPEncryptionContext &Context, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size, std::vector<uint8_t> &OutBuffer, int32_t OutIndex);

void ZipDecrypt(TSBZIPEncryptionContext &Context, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size, std::vector<uint8_t> &OutBuffer, int32_t OutIndex);

int32_t ZipHashAlgorithmToSBB(int32_t Algorithm);

int32_t SBBHashAlgorithmToZip(int32_t Algorithm);

int32_t ZipSymmetricAlgorithmToSBB(int32_t Algorithm);

int32_t ZipCipherDefaultKeySize(int32_t Algorithm);

int32_t ZipCipherIVSize(int32_t Algorithm);

void ZipCompressionMethodName(uint32_t CompressionMethod, std::string &OutResult);

void ZipEncryptionAlgorithmName(uint32_t EncryptionAlgorithm, std::string &OutResult);

void ZipVersionStr(uint32_t Version, std::string &OutResult);

void OEMEncodingName(std::string &OutResult);

void ANSIEncodingName(std::string &OutResult);

#ifdef SB_USE_CLASS_TSTREAM
void CopyStreamPart(TStream &Source, int64_t SourcePosition, TStream &Dest, int64_t DestPosition, int64_t Size);
void CopyStreamPart(TStream *Source, int64_t SourcePosition, TStream *Dest, int64_t DestPosition, int64_t Size);
#endif /* SB_USE_CLASS_TSTREAM */

#endif /* SB_USE_GLOBAL_PROCS_ZIPUTILS */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_ZIPUTILS
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_BufferToUINT16(const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_UINT16ToBuffer(uint8_t pBuffer[], int32_t * szBuffer, int32_t Index, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_BufferToUINT32(const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_UINT32ToBuffer(uint8_t pBuffer[], int32_t * szBuffer, int32_t Index, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_BufferToUINT64(const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_UINT64ToBuffer(uint8_t pBuffer[], int32_t * szBuffer, int32_t Index, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_ReverseBuffer(const uint8_t pBuffer[], int32_t szBuffer, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_ZipInitializeEncryption(TSBZIPEncryptionContext * Context);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_ZipUpdateKeys(TSBZIPEncryptionContext * Context, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_ZipEncrypt(TSBZIPEncryptionContext * Context, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size, uint8_t pOutBuffer[], int32_t * szOutBuffer, int32_t OutIndex);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_ZipDecrypt(TSBZIPEncryptionContext * Context, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size, uint8_t pOutBuffer[], int32_t * szOutBuffer, int32_t OutIndex);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_ZipHashAlgorithmToSBB(int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_SBBHashAlgorithmToZip(int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_ZipSymmetricAlgorithmToSBB(int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_ZipCipherDefaultKeySize(int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_ZipCipherIVSize(int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_ZipCompressionMethodName(uint32_t CompressionMethod, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_ZipEncryptionAlgorithmName(uint32_t EncryptionAlgorithm, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_ZipVersionStr(uint32_t Version, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_OEMEncodingName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_ANSIEncodingName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBZipUtils_CopyStreamPart(TStreamHandle Source, int64_t SourcePosition, TStreamHandle Dest, int64_t DestPosition, int64_t Size);
#endif /* SB_USE_GLOBAL_PROCS_ZIPUTILS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBZIPUTILS */

