#ifndef __INC_SBGOST2814789
#define __INC_SBGOST2814789

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
#include "sbgostcommon.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElGOSTHandle;

typedef uint8_t TElGOSTModeRaw;

typedef enum
{
	GOSTMode_ECB = 0,
	GOSTMode_OFB = 1,
	GOSTMode_CFB = 2,
	GOSTMode_CBC = 3
} TElGOSTMode;

#ifdef SB_USE_CLASS_TELGOST
SB_IMPORT uint32_t SB_APIENTRY TElGOST_BlockSize(int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_BlockSize_1(TElGOSTHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_KeySize(int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_KeySize_1(TElGOSTHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_Reset(TElGOSTHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_Clone(TElGOSTHandle _Handle, TElGOSTBaseHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_Encrypt_Block(TElGOSTHandle _Handle, const uint8_t pInBuf[], int32_t szInBuf, int32_t In_StartIdx, int32_t In_Len, uint8_t pOutBuf[], int32_t * szOutBuf, int32_t * Out_Len, int32_t Out_StartIdx);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_Decrypt_Block(TElGOSTHandle _Handle, const uint8_t pInBuf[], int32_t szInBuf, int32_t In_StartIdx, int32_t In_Len, uint8_t pOutBuf[], int32_t * szOutBuf, int32_t * Out_Len, int32_t Out_StartIdx);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_Encrypt_Finalize(TElGOSTHandle _Handle, uint8_t pOutBuf[], int32_t * szOutBuf, int32_t * Out_Len, int32_t Out_StartIdx);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_Decrypt_Finalize(TElGOSTHandle _Handle, uint8_t pOutBuf[], int32_t * szOutBuf, int32_t * Out_Len, int32_t Out_StartIdx);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_EncryptBuf(TElGOSTHandle _Handle, const uint8_t pInBuf[], int32_t szInBuf, int32_t In_StartIdx, int32_t In_Len, uint8_t pOutBuf[], int32_t * szOutBuf, int32_t * Out_Len, int32_t Out_StartIdx);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_EncryptBuf_1(TElGOSTHandle _Handle, const uint8_t pInBuf[], int32_t szInBuf, uint8_t pOutBuf[], int32_t * szOutBuf);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_DecryptBuf(TElGOSTHandle _Handle, const uint8_t pInBuf[], int32_t szInBuf, int32_t In_StartIdx, int32_t In_Len, uint8_t pOutBuf[], int32_t * szOutBuf, int32_t * Out_Len, int32_t Out_StartIdx);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_DecryptBuf_1(TElGOSTHandle _Handle, const uint8_t pInBuf[], int32_t szInBuf, uint8_t pOutBuf[], int32_t * szOutBuf);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_EncryptStream(TElGOSTHandle _Handle, TStreamHandle Source, uint32_t Count, TStreamHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_DecryptStream(TElGOSTHandle _Handle, TStreamHandle Source, uint32_t Count, TStreamHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_MAC_Block(TElGOSTHandle _Handle, void * InBuf, int32_t In_Len);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_MAC_Block_1(TElGOSTHandle _Handle, const uint8_t pInBuf[], int32_t szInBuf, int32_t In_StartIdx, int32_t In_Len);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_MAC_Finalize(TElGOSTHandle _Handle, int32_t Qnt_Bits, uint8_t pMAC[], int32_t * szMAC);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_MAC_Stream(TElGOSTHandle _Handle, TStreamHandle Source, uint32_t Count, int32_t Qnt_Bits, uint8_t pMAC[], int32_t * szMAC);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_get_Key(TElGOSTHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_set_Key(TElGOSTHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_get_IV(TElGOSTHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_set_IV(TElGOSTHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_get_Mode(TElGOSTHandle _Handle, TElGOSTModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_set_Mode(TElGOSTHandle _Handle, TElGOSTModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_Create(TElGOSTHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST_Create_1(const TElGostSubstBlock * SubstBlock, TElGOSTHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOST */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElGOST;

#ifdef SB_USE_CLASS_TELGOST
class TElGOST: public TElGOSTBase
{
	private:
		SB_DISABLE_COPY(TElGOST)
	public:
		static int32_t BlockSize();

		int32_t BlockSize_Inst();

		static int32_t KeySize();

		int32_t KeySize_Inst();

		virtual void Reset();

		virtual void Clone(TElGOSTBase &Source);

		virtual void Clone(TElGOSTBase *Source);

		void Encrypt_Block(const std::vector<uint8_t> &InBuf, int32_t In_StartIdx, int32_t In_Len, std::vector<uint8_t> &OutBuf, int32_t &Out_Len, int32_t Out_StartIdx);

		void Decrypt_Block(const std::vector<uint8_t> &InBuf, int32_t In_StartIdx, int32_t In_Len, std::vector<uint8_t> &OutBuf, int32_t &Out_Len, int32_t Out_StartIdx);

		void Encrypt_Finalize(std::vector<uint8_t> &OutBuf, int32_t &Out_Len, int32_t Out_StartIdx);

		void Decrypt_Finalize(std::vector<uint8_t> &OutBuf, int32_t &Out_Len, int32_t Out_StartIdx);

		void EncryptBuf(const std::vector<uint8_t> &InBuf, int32_t In_StartIdx, int32_t In_Len, std::vector<uint8_t> &OutBuf, int32_t &Out_Len, int32_t Out_StartIdx);

		void EncryptBuf(const std::vector<uint8_t> &InBuf, std::vector<uint8_t> &OutBuf);

		void DecryptBuf(const std::vector<uint8_t> &InBuf, int32_t In_StartIdx, int32_t In_Len, std::vector<uint8_t> &OutBuf, int32_t &Out_Len, int32_t Out_StartIdx);

		void DecryptBuf(const std::vector<uint8_t> &InBuf, std::vector<uint8_t> &OutBuf);

#ifdef SB_USE_CLASS_TSTREAM
		void EncryptStream(TStream &Source, uint32_t Count, TStream &Dest);

		void EncryptStream(TStream *Source, uint32_t Count, TStream *Dest);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void DecryptStream(TStream &Source, uint32_t Count, TStream &Dest);

		void DecryptStream(TStream *Source, uint32_t Count, TStream *Dest);
#endif /* SB_USE_CLASS_TSTREAM */

		void MAC_Block(void * InBuf, int32_t In_Len);

		void MAC_Block(const std::vector<uint8_t> &InBuf, int32_t In_StartIdx, int32_t In_Len);

		void MAC_Finalize(int32_t Qnt_Bits, std::vector<uint8_t> &MAC);

#ifdef SB_USE_CLASS_TSTREAM
		void MAC_Stream(TStream &Source, uint32_t Count, int32_t Qnt_Bits, std::vector<uint8_t> &MAC);

		void MAC_Stream(TStream *Source, uint32_t Count, int32_t Qnt_Bits, std::vector<uint8_t> &MAC);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void get_Key(std::vector<uint8_t> &OutResult);

		virtual void set_Key(const std::vector<uint8_t> &Value);

		virtual void get_IV(std::vector<uint8_t> &OutResult);

		virtual void set_IV(const std::vector<uint8_t> &Value);

		virtual TElGOSTMode get_Mode();

		virtual void set_Mode(TElGOSTMode Value);

		SB_DECLARE_PROPERTY(TElGOSTMode, get_Mode, set_Mode, TElGOST, Mode);

		TElGOST(TElGOSTHandle handle, TElOwnHandle ownHandle);

		TElGOST();

		explicit TElGOST(const TElGostSubstBlock &SubstBlock);

};
#endif /* SB_USE_CLASS_TELGOST */

#ifdef SB_USE_GLOBAL_PROCS_GOST2814789

bool KeyWrap28147(const std::vector<uint8_t> &UKM, const std::vector<uint8_t> &CEK, const std::vector<uint8_t> &KEK, std::vector<uint8_t> &WCEK, int32_t &WCEKSize, std::vector<uint8_t> &CEK_MAC, int32_t &CEKMACSize);

bool KeyUnwrap28147(const std::vector<uint8_t> &UKM, const std::vector<uint8_t> &WCEK, const std::vector<uint8_t> &KEK, const std::vector<uint8_t> &CEK_MAC, std::vector<uint8_t> &CEK, int32_t &CEKSize);

bool KeyWrapCryptoPro(const std::vector<uint8_t> &UKM, const std::vector<uint8_t> &CEK, const std::vector<uint8_t> &KEK, std::vector<uint8_t> &WCEK, int32_t &WCEKSize, std::vector<uint8_t> &CEK_MAC, int32_t &CEKMACSize);

bool KeyUnwrapCryptoPro(const std::vector<uint8_t> &UKM, const std::vector<uint8_t> &WCEK, const std::vector<uint8_t> &KEK, const std::vector<uint8_t> &CEK_MAC, std::vector<uint8_t> &CEK, int32_t &CEKSize);

void gost28147IMIT(const std::vector<uint8_t> &IV, const std::vector<uint8_t> &K, const std::vector<uint8_t> &D, std::vector<uint8_t> &OutResult);

bool KeyDiversifyCryptoPro(const std::vector<uint8_t> &UKM, const std::vector<uint8_t> &KEK, std::vector<uint8_t> &DKEK, int32_t &DKEKSize);

#endif /* SB_USE_GLOBAL_PROCS_GOST2814789 */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_GOST2814789
SB_IMPORT uint32_t SB_APIENTRY SBGOST2814789_KeyWrap28147(const uint8_t pUKM[], int32_t szUKM, const uint8_t pCEK[], int32_t szCEK, const uint8_t pKEK[], int32_t szKEK, uint8_t pWCEK[], int32_t * szWCEK, int32_t * WCEKSize, uint8_t pCEK_MAC[], int32_t * szCEK_MAC, int32_t * CEKMACSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBGOST2814789_KeyUnwrap28147(const uint8_t pUKM[], int32_t szUKM, const uint8_t pWCEK[], int32_t szWCEK, const uint8_t pKEK[], int32_t szKEK, const uint8_t pCEK_MAC[], int32_t szCEK_MAC, uint8_t pCEK[], int32_t * szCEK, int32_t * CEKSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBGOST2814789_KeyWrapCryptoPro(const uint8_t pUKM[], int32_t szUKM, const uint8_t pCEK[], int32_t szCEK, const uint8_t pKEK[], int32_t szKEK, uint8_t pWCEK[], int32_t * szWCEK, int32_t * WCEKSize, uint8_t pCEK_MAC[], int32_t * szCEK_MAC, int32_t * CEKMACSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBGOST2814789_KeyUnwrapCryptoPro(const uint8_t pUKM[], int32_t szUKM, const uint8_t pWCEK[], int32_t szWCEK, const uint8_t pKEK[], int32_t szKEK, const uint8_t pCEK_MAC[], int32_t szCEK_MAC, uint8_t pCEK[], int32_t * szCEK, int32_t * CEKSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBGOST2814789_gost28147IMIT(const uint8_t pIV[], int32_t szIV, const uint8_t pK[], int32_t szK, const uint8_t pD[], int32_t szD, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBGOST2814789_KeyDiversifyCryptoPro(const uint8_t pUKM[], int32_t szUKM, const uint8_t pKEK[], int32_t szKEK, uint8_t pDKEK[], int32_t * szDKEK, int32_t * DKEKSize, int8_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_GOST2814789 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBGOST2814789 */

