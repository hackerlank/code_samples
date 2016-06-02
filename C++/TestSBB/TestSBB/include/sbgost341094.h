#ifndef __INC_SBGOST341094
#define __INC_SBGOST341094

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbmath.h"
#include "sbgostcommon.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElGOSTSignerBaseHandle;

typedef TElClassHandle TElGOSTSignerHandle;

#ifdef SB_USE_CLASS_TELGOSTSIGNERBASE
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSignerBase_AssignSecretKey(TElGOSTSignerBaseHandle _Handle, const char * pcHexStr, int32_t szHexStr);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSignerBase_AssignPublicKey(TElGOSTSignerBaseHandle _Handle, const char * pcHexStr, int32_t szHexStr);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSignerBase_Sign(TElGOSTSignerBaseHandle _Handle, const uint8_t pDigest[], int32_t szDigest, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSignerBase_Verify(TElGOSTSignerBaseHandle _Handle, const uint8_t pDigest[], int32_t szDigest, const uint8_t pSign[], int32_t szSign, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSignerBase_Generate_Keys(TElGOSTSignerBaseHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSignerBase_get_SecretKey(TElGOSTSignerBaseHandle _Handle, PLInt * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSignerBase_set_SecretKey(TElGOSTSignerBaseHandle _Handle, PLInt Value);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSignerBase_get_PublicKey(TElGOSTSignerBaseHandle _Handle, PLInt * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSignerBase_set_PublicKey(TElGOSTSignerBaseHandle _Handle, PLInt Value);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSignerBase_Create(TElGOSTSignerBaseHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOSTSIGNERBASE */

#ifdef SB_USE_CLASS_TELGOSTSIGNER
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_AssignP(TElGOSTSignerHandle _Handle, const char * pcHexStr, int32_t szHexStr);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_AssignQ(TElGOSTSignerHandle _Handle, const char * pcHexStr, int32_t szHexStr);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_AssignA(TElGOSTSignerHandle _Handle, const char * pcHexStr, int32_t szHexStr);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_Check_Params(int32_t Bits, const PLInt P, const PLInt Q, const PLInt A, int64_t x0, int64_t c, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_Check_Params_1(TElGOSTSignerHandle _Handle, int32_t Bits, const PLInt P, const PLInt Q, const PLInt A, int64_t x0, int64_t c, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_Generate_PQA(TElGOSTSignerHandle _Handle, int32_t Bits, int32_t TypeProc, int64_t * x0, int64_t * c, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_Generate_PQA_1(int32_t Bits, int32_t TypeProc, int64_t * x0, int64_t * c, PLInt * P, PLInt * Q, PLInt * A, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_Generate_PQA_2(TElGOSTSignerHandle _Handle, int32_t Bits, int32_t TypeProc, int64_t * x0, int64_t * c, PLInt * P, PLInt * Q, PLInt * A, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_Generate_All(TElGOSTSignerHandle _Handle, int32_t Bits, int32_t TypeProc, int64_t * x0, int64_t * c, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_Generate_Keys(TElGOSTSignerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_Generate_Keys_1(const PLInt P, const PLInt Q, const PLInt A, PLInt * SecretKey, PLInt * PublicKey);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_Generate_Keys_2(TElGOSTSignerHandle _Handle, const PLInt P, const PLInt Q, const PLInt A, PLInt * SecretKey, PLInt * PublicKey);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_Sign(TElGOSTSignerHandle _Handle, const uint8_t pDigest[], int32_t szDigest, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_Sign_1(const uint8_t pDigest[], int32_t szDigest, const char * pcP, int32_t szP, const char * pcQ, int32_t szQ, const char * pcA, int32_t szA, const char * pcKey, int32_t szKey, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_Sign_2(TElGOSTSignerHandle _Handle, const uint8_t pDigest[], int32_t szDigest, const char * pcP, int32_t szP, const char * pcQ, int32_t szQ, const char * pcA, int32_t szA, const char * pcKey, int32_t szKey, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_Sign_3(const uint8_t pDigest[], int32_t szDigest, const PLInt P, const PLInt Q, const PLInt A, const PLInt Key, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_Sign_4(TElGOSTSignerHandle _Handle, const uint8_t pDigest[], int32_t szDigest, const PLInt P, const PLInt Q, const PLInt A, const PLInt Key, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_Verify(TElGOSTSignerHandle _Handle, const uint8_t pDigest[], int32_t szDigest, const uint8_t pSign[], int32_t szSign, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_Verify_1(const uint8_t pDigest[], int32_t szDigest, const uint8_t pSign[], int32_t szSign, const PLInt P, const PLInt Q, const PLInt A, const PLInt Key, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_Verify_2(TElGOSTSignerHandle _Handle, const uint8_t pDigest[], int32_t szDigest, const uint8_t pSign[], int32_t szSign, const PLInt P, const PLInt Q, const PLInt A, const PLInt Key, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_get_P(TElGOSTSignerHandle _Handle, PLInt * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_set_P(TElGOSTSignerHandle _Handle, PLInt Value);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_get_Q(TElGOSTSignerHandle _Handle, PLInt * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_set_Q(TElGOSTSignerHandle _Handle, PLInt Value);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_get_A(TElGOSTSignerHandle _Handle, PLInt * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_set_A(TElGOSTSignerHandle _Handle, PLInt Value);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTSigner_Create(TElGOSTSignerHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOSTSIGNER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElGOSTSignerBase;
class TElGOSTSigner;

#ifdef SB_USE_CLASS_TELGOSTSIGNERBASE
class TElGOSTSignerBase: public TObject
{
	private:
		SB_DISABLE_COPY(TElGOSTSignerBase)
	public:
		void AssignSecretKey(const std::string &HexStr);

		void AssignPublicKey(const std::string &HexStr);

		virtual void Sign(const std::vector<uint8_t> &Digest, std::vector<uint8_t> &OutResult);

		virtual bool Verify(const std::vector<uint8_t> &Digest, const std::vector<uint8_t> &Sign);

		virtual void Generate_Keys();

		virtual PLInt get_SecretKey();

		virtual void set_SecretKey(PLInt Value);

		SB_DECLARE_PROPERTY(PLInt, get_SecretKey, set_SecretKey, TElGOSTSignerBase, SecretKey);

		virtual PLInt get_PublicKey();

		virtual void set_PublicKey(PLInt Value);

		SB_DECLARE_PROPERTY(PLInt, get_PublicKey, set_PublicKey, TElGOSTSignerBase, PublicKey);

		TElGOSTSignerBase(TElGOSTSignerBaseHandle handle, TElOwnHandle ownHandle);

		TElGOSTSignerBase();

};
#endif /* SB_USE_CLASS_TELGOSTSIGNERBASE */

#ifdef SB_USE_CLASS_TELGOSTSIGNER
class TElGOSTSigner: public TElGOSTSignerBase
{
	private:
		SB_DISABLE_COPY(TElGOSTSigner)
	public:
		void AssignP(const std::string &HexStr);

		void AssignQ(const std::string &HexStr);

		void AssignA(const std::string &HexStr);

		static bool Check_Params(int32_t Bits, const PLInt P, const PLInt Q, const PLInt A, int64_t x0, int64_t c);

		bool Check_Params_Inst(int32_t Bits, const PLInt P, const PLInt Q, const PLInt A, int64_t x0, int64_t c);

		bool Generate_PQA(int32_t Bits, int32_t TypeProc, int64_t &x0, int64_t &c);

		static bool Generate_PQA(int32_t Bits, int32_t TypeProc, int64_t &x0, int64_t &c, PLInt &P, PLInt &Q, PLInt &A);

		bool Generate_PQA_Inst(int32_t Bits, int32_t TypeProc, int64_t &x0, int64_t &c, PLInt &P, PLInt &Q, PLInt &A);

		bool Generate_All(int32_t Bits, int32_t TypeProc, int64_t &x0, int64_t &c);

		virtual void Generate_Keys();

		static void Generate_Keys(const PLInt P, const PLInt Q, const PLInt A, PLInt &SecretKey, PLInt &PublicKey);

		void Generate_Keys_Inst(const PLInt P, const PLInt Q, const PLInt A, PLInt &SecretKey, PLInt &PublicKey);

		virtual void Sign(const std::vector<uint8_t> &Digest, std::vector<uint8_t> &OutResult);

		static void Sign(const std::vector<uint8_t> &Digest, const std::string &P, const std::string &Q, const std::string &A, const std::string &Key, std::vector<uint8_t> &OutResult);

		void Sign_Inst(const std::vector<uint8_t> &Digest, const std::string &P, const std::string &Q, const std::string &A, const std::string &Key, std::vector<uint8_t> &OutResult);

		static void Sign(const std::vector<uint8_t> &Digest, const PLInt P, const PLInt Q, const PLInt A, const PLInt Key, std::vector<uint8_t> &OutResult);

		void Sign_Inst(const std::vector<uint8_t> &Digest, const PLInt P, const PLInt Q, const PLInt A, const PLInt Key, std::vector<uint8_t> &OutResult);

		virtual bool Verify(const std::vector<uint8_t> &Digest, const std::vector<uint8_t> &Sign);

		static bool Verify(const std::vector<uint8_t> &Digest, const std::vector<uint8_t> &Sign, const PLInt P, const PLInt Q, const PLInt A, const PLInt Key);

		bool Verify_Inst(const std::vector<uint8_t> &Digest, const std::vector<uint8_t> &Sign, const PLInt P, const PLInt Q, const PLInt A, const PLInt Key);

		virtual PLInt get_P();

		virtual void set_P(PLInt Value);

		SB_DECLARE_PROPERTY(PLInt, get_P, set_P, TElGOSTSigner, P);

		virtual PLInt get_Q();

		virtual void set_Q(PLInt Value);

		SB_DECLARE_PROPERTY(PLInt, get_Q, set_Q, TElGOSTSigner, Q);

		virtual PLInt get_A();

		virtual void set_A(PLInt Value);

		SB_DECLARE_PROPERTY(PLInt, get_A, set_A, TElGOSTSigner, A);

		TElGOSTSigner(TElGOSTSignerHandle handle, TElOwnHandle ownHandle);

		TElGOSTSigner();

};
#endif /* SB_USE_CLASS_TELGOSTSIGNER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBGOST341094 */

