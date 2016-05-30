#ifndef __INC_SBUMAC
#define __INC_SBUMAC

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcrc.h"
#include "sbaes.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_AES_BLOCK_LEN 	16
#define SB_UMAC_KEY_LEN 	16
#define SB_L1_KEY_LEN 	1024
#define SB_L1_KEY_SHIFT 	16
#define SB_L1_PAD_BOUNDARY 	32
#define SB_HASH_BUF_BYTES 	64

typedef TElClassHandle TElUMACHandle;

typedef uint32_t * SBUMAC_pUINT32;

typedef int64_t * pUINT64;

#pragma pack(4)
typedef struct 
{
	void * NH_Key;
	void * Data;
	int32_t Next_Data_Empty;
	int32_t Bytes_Hashed;
	void * State;
} TNHContext;

#pragma pack(1)
typedef struct 
{
	TNHContext Hash;
	void * Poly_Key_8;
	void * Poly_Accum;
	void * IP_Keys;
	void * IP_Trans;
	uint32_t Msg_Len;
} TUHASHContext;

#pragma pack(1)
typedef struct 
{
	uint8_t Cache[16];
	uint8_t Nonce[16];
	uint32_t PRF_Key[44];
} TPDFContext;

#ifdef SB_USE_CLASS_TELUMAC
SB_IMPORT uint32_t SB_APIENTRY TElUMAC_Clone(TElUMACHandle _Handle, TElUMACHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUMAC_Reset(TElUMACHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElUMAC_Update(TElUMACHandle _Handle, const uint8_t pIn_Buf[], int32_t szIn_Buf, uint32_t StartIndex, uint32_t Len);
SB_IMPORT uint32_t SB_APIENTRY TElUMAC_Update_1(TElUMACHandle _Handle, void * In_Buf, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElUMAC_Final_(TElUMACHandle _Handle, const uint8_t pNonce[], int32_t szNonce, uint8_t pTag[], int32_t * szTag);
SB_IMPORT uint32_t SB_APIENTRY TElUMAC_Calculate(TElUMACHandle _Handle, const uint8_t pIn_Buf[], int32_t szIn_Buf, uint32_t StartIndex, uint32_t Len, const uint8_t pNonce[], int32_t szNonce, uint8_t pTag[], int32_t * szTag);
SB_IMPORT uint32_t SB_APIENTRY TElUMAC_Calculate_1(TElUMACHandle _Handle, void * In_Buf, uint32_t Len, const uint8_t pNonce[], int32_t szNonce, uint8_t pTag[], int32_t * szTag);
SB_IMPORT uint32_t SB_APIENTRY TElUMAC_Create(const uint8_t pKey[], int32_t szKey, int32_t TagLen, TElUMACHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUMAC_Create_1(const char * pcKey, int32_t szKey, int32_t TagLen, TElUMACHandle * OutResult);
#endif /* SB_USE_CLASS_TELUMAC */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElUMAC;

#ifdef SB_USE_CLASS_TELUMAC
class TElUMAC: public TObject
{
	private:
		SB_DISABLE_COPY(TElUMAC)
	public:
		TElUMACHandle Clone();

		void Reset();

		void Update(const std::vector<uint8_t> &In_Buf, uint32_t StartIndex, uint32_t Len);

		void Update(void * In_Buf, int32_t Size);

		void Final_(const std::vector<uint8_t> &Nonce, std::vector<uint8_t> &Tag);

		void Calculate(const std::vector<uint8_t> &In_Buf, uint32_t StartIndex, uint32_t Len, const std::vector<uint8_t> &Nonce, std::vector<uint8_t> &Tag);

		void Calculate(void * In_Buf, uint32_t Len, const std::vector<uint8_t> &Nonce, std::vector<uint8_t> &Tag);

		TElUMAC(TElUMACHandle handle, TElOwnHandle ownHandle);

		TElUMAC(const std::vector<uint8_t> &Key, int32_t TagLen);

		TElUMAC(const std::string &Key, int32_t TagLen);

};
#endif /* SB_USE_CLASS_TELUMAC */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBUMAC */

