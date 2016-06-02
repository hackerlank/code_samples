#ifndef __INC_SBSRP
#define __INC_SBSRP

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbhashfunction.h"
#include "sbstreams.h"
#include "sbmath.h"
#include "sbstrutils.h"
#include "sbencoding.h"
#include "sbconstants.h"
#include "sbmd.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_TSRPPrimesGen_1536 	2
#define SB_TSRPPrimesGen_2048 	2
#define SB_TSRPPrimesGen_3072 	5
#define SB_TSRPPrimesGen_4096 	5
#define SB_TSRPPrimesGen_6144 	5
#define SB_TSRPPrimesGen_8192 	19

typedef TElClassHandle TElSRPCredentialHandle;

typedef TElClassHandle TElSRPCredentialStoreHandle;

#pragma pack(4)
typedef struct 
{
	void * Salt;
	PLInt A;
	PLInt A_Small;
	PLInt B;
	PLInt B_Small;
	PLInt V;
	PLInt U;
	PLInt N;
	PLInt K;
	PLInt G;
	PLInt X;
	PLInt S;
	int8_t Initialized;
} TSRPContext;

typedef uint8_t TSSRPPrimeLenRaw;

typedef enum
{
	sr1024 = 0,
	sr1536 = 1,
	sr2048 = 2,
	sr3072 = 3,
	sr4096 = 4,
	sr6144 = 5,
	sr8192 = 6
} TSSRPPrimeLen;

typedef uint8_t TSBSRPCredentialPrimeLenRaw;

typedef enum
{
	srppl1024 = 0,
	srpp1536 = 1,
	srpp2048 = 2,
	srpp3072 = 3,
	srpp4096 = 4,
	srpp6144 = 5,
	srpp8192 = 6
} TSBSRPCredentialPrimeLen;

#ifdef SB_USE_CLASS_TELSRPCREDENTIAL
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredential_Generate(TElSRPCredentialHandle _Handle, const char * pcUsername, int32_t szUsername, const char * pcPassword, int32_t szPassword, TSBSRPCredentialPrimeLenRaw PrimeLen);
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredential_Generate_1(TElSRPCredentialHandle _Handle, const char * pcUsername, int32_t szUsername, const char * pcPassword, int32_t szPassword, const uint8_t pPrime[], int32_t szPrime, const uint8_t pGenerator[], int32_t szGenerator);
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredential_Load(TElSRPCredentialHandle _Handle, const char * pcData, int32_t szData);
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredential_Load_1(TElSRPCredentialHandle _Handle, const char * pcUsername, int32_t szUsername, const uint8_t pSalt[], int32_t szSalt, const uint8_t pPrime[], int32_t szPrime, const uint8_t pGenerator[], int32_t szGenerator, const uint8_t pVerifier[], int32_t szVerifier);
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredential_Save(TElSRPCredentialHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredential_get_Username(TElSRPCredentialHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredential_get_Prime(TElSRPCredentialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredential_get_Generator(TElSRPCredentialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredential_set_Generator(TElSRPCredentialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredential_get_Salt(TElSRPCredentialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredential_get_Verifier(TElSRPCredentialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredential_Create(TElSRPCredentialHandle * OutResult);
#endif /* SB_USE_CLASS_TELSRPCREDENTIAL */

#ifdef SB_USE_CLASS_TELSRPCREDENTIALSTORE
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredentialStore_Add(TElSRPCredentialStoreHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredentialStore_Add_1(TElSRPCredentialStoreHandle _Handle, const char * pcUsername, int32_t szUsername, const char * pcPassword, int32_t szPassword, TSBSRPCredentialPrimeLenRaw PrimeLen, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredentialStore_Remove(TElSRPCredentialStoreHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredentialStore_Clear(TElSRPCredentialStoreHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredentialStore_LoadFromStream(TElSRPCredentialStoreHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredentialStore_SaveToStream(TElSRPCredentialStoreHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredentialStore_get_Credentials(TElSRPCredentialStoreHandle _Handle, int32_t Index, TElSRPCredentialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredentialStore_get_Count(TElSRPCredentialStoreHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPCredentialStore_Create(TComponentHandle AOwner, TElSRPCredentialStoreHandle * OutResult);
#endif /* SB_USE_CLASS_TELSRPCREDENTIALSTORE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSRPCredential;
class TElSRPCredentialStore;

#ifdef SB_USE_CLASS_TELSRPCREDENTIAL
class TElSRPCredential: public TObject
{
	private:
		SB_DISABLE_COPY(TElSRPCredential)
	public:
		void Generate(const std::string &Username, const std::string &Password, TSBSRPCredentialPrimeLen PrimeLen);

		void Generate(const std::string &Username, const std::string &Password, const std::vector<uint8_t> &Prime, const std::vector<uint8_t> &Generator);

		void Load(const std::string &Data);

		void Load(const std::string &Username, const std::vector<uint8_t> &Salt, const std::vector<uint8_t> &Prime, const std::vector<uint8_t> &Generator, const std::vector<uint8_t> &Verifier);

		void Save(std::string &OutResult);

		virtual void get_Username(std::string &OutResult);

		virtual void get_Prime(std::vector<uint8_t> &OutResult);

		virtual void get_Generator(std::vector<uint8_t> &OutResult);

		virtual void set_Generator(const std::vector<uint8_t> &Value);

		virtual void get_Salt(std::vector<uint8_t> &OutResult);

		virtual void get_Verifier(std::vector<uint8_t> &OutResult);

		TElSRPCredential(TElSRPCredentialHandle handle, TElOwnHandle ownHandle);

		TElSRPCredential();

};
#endif /* SB_USE_CLASS_TELSRPCREDENTIAL */

#ifdef SB_USE_CLASS_TELSRPCREDENTIALSTORE
class TElSRPCredentialStore: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSRPCredentialStore)
#ifdef SB_USE_CLASS_TELSRPCREDENTIAL
		TElSRPCredential* _Inst_Credentials;
#endif /* SB_USE_CLASS_TELSRPCREDENTIAL */

		void initInstances();

	public:
		int32_t Add();

		int32_t Add(const std::string &Username, const std::string &Password, TSBSRPCredentialPrimeLen PrimeLen);

		void Remove(int32_t Index);

		void Clear();

#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromStream(TStream &Stream);

		void LoadFromStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToStream(TStream &Stream);

		void SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELSRPCREDENTIAL
		virtual TElSRPCredential* get_Credentials(int32_t Index);
#endif /* SB_USE_CLASS_TELSRPCREDENTIAL */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElSRPCredentialStore, Count);

		TElSRPCredentialStore(TElSRPCredentialStoreHandle handle, TElOwnHandle ownHandle);

		explicit TElSRPCredentialStore(TComponent &AOwner);

		explicit TElSRPCredentialStore(TComponent *AOwner);

		virtual ~TElSRPCredentialStore();

};
#endif /* SB_USE_CLASS_TELSRPCREDENTIALSTORE */

#ifdef SB_USE_GLOBAL_PROCS_SRP

void SrpInitContext(TSRPContext &SRP);

void SrpDestroyContext(TSRPContext &SRP);

void SrpServerInit(TSRPContext &SRP);

void SrpGetU(PLInt N, PLInt A, PLInt B, const std::string &Proto, PLInt &U);

void SrpGetUTLS(PLInt A, PLInt B, PLInt N, PLInt &U);

void SrpGetA(TSRPContext &SRP);

void SrpGetB(TSRPContext &SRP);

void SrpGetK(TSRPContext &SRP);

void SrpPrepareClientX(const std::string &Username, const std::string &Password, const std::vector<uint8_t> &Salt, PLInt &ClX);

void SrpGetClientKey(TSRPContext &SRP);

void SrpPrepareClientKeyTLS(TSRPContext &SRP);

void SrpPrepareServerPreKeyTLS(TSRPContext &SRP);

void SrpPrepareServerKeyTLS(TSRPContext &SRP);

void SrpGetServerKey(TSRPContext &SRP);

void SrpGetNewServerData(const std::string &UserName, const std::string &UserPassword, TSSRPPrimeLen PrimeLen, std::vector<uint8_t> &N, std::vector<uint8_t> &G, std::vector<uint8_t> &Salt, std::vector<uint8_t> &V);

void SrpLIntToBytesImplicit(PLInt X, std::vector<uint8_t> &OutResult);

void SrpLIntToBytesPAD(PLInt X, int32_t Len, std::vector<uint8_t> &OutResult);

void LIntToBytes(PLInt I, std::vector<uint8_t> &OutResult);

void LInitBytes(PLInt I, const std::vector<uint8_t> &BA);

void SrpGenerateVerifier(const std::string &Username, const std::string &Password, const std::vector<uint8_t> &Prime, const std::vector<uint8_t> &Generator, const std::vector<uint8_t> &Salt, std::vector<uint8_t> &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_SRP */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_SRP
SB_IMPORT uint32_t SB_APIENTRY SBSRP_SrpInitContext(TSRPContext * SRP);
SB_IMPORT uint32_t SB_APIENTRY SBSRP_SrpDestroyContext(TSRPContext * SRP);
SB_IMPORT uint32_t SB_APIENTRY SBSRP_SrpServerInit(TSRPContext * SRP);
SB_IMPORT uint32_t SB_APIENTRY SBSRP_SrpGetU(PLInt N, PLInt A, PLInt B, const char * pcProto, int32_t szProto, PLInt * U);
SB_IMPORT uint32_t SB_APIENTRY SBSRP_SrpGetUTLS(PLInt A, PLInt B, PLInt N, PLInt * U);
SB_IMPORT uint32_t SB_APIENTRY SBSRP_SrpGetA(TSRPContext * SRP);
SB_IMPORT uint32_t SB_APIENTRY SBSRP_SrpGetB(TSRPContext * SRP);
SB_IMPORT uint32_t SB_APIENTRY SBSRP_SrpGetK(TSRPContext * SRP);
SB_IMPORT uint32_t SB_APIENTRY SBSRP_SrpPrepareClientX(const char * pcUsername, int32_t szUsername, const char * pcPassword, int32_t szPassword, const uint8_t pSalt[], int32_t szSalt, PLInt * ClX);
SB_IMPORT uint32_t SB_APIENTRY SBSRP_SrpGetClientKey(TSRPContext * SRP);
SB_IMPORT uint32_t SB_APIENTRY SBSRP_SrpPrepareClientKeyTLS(TSRPContext * SRP);
SB_IMPORT uint32_t SB_APIENTRY SBSRP_SrpPrepareServerPreKeyTLS(TSRPContext * SRP);
SB_IMPORT uint32_t SB_APIENTRY SBSRP_SrpPrepareServerKeyTLS(TSRPContext * SRP);
SB_IMPORT uint32_t SB_APIENTRY SBSRP_SrpGetServerKey(TSRPContext * SRP);
SB_IMPORT uint32_t SB_APIENTRY SBSRP_SrpGetNewServerData(const char * pcUserName, int32_t szUserName, const char * pcUserPassword, int32_t szUserPassword, TSSRPPrimeLenRaw PrimeLen, uint8_t pN[], int32_t * szN, uint8_t pG[], int32_t * szG, uint8_t pSalt[], int32_t * szSalt, uint8_t pV[], int32_t * szV);
SB_IMPORT uint32_t SB_APIENTRY SBSRP_SrpLIntToBytesImplicit(PLInt X, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSRP_SrpLIntToBytesPAD(PLInt X, int32_t Len, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSRP_LIntToBytes(PLInt I, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSRP_LInitBytes(PLInt I, const uint8_t pBA[], int32_t szBA);
SB_IMPORT uint32_t SB_APIENTRY SBSRP_SrpGenerateVerifier(const char * pcUsername, int32_t szUsername, const char * pcPassword, int32_t szPassword, const uint8_t pPrime[], int32_t szPrime, const uint8_t pGenerator[], int32_t szGenerator, const uint8_t pSalt[], int32_t szSalt, uint8_t pOutResult[], int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_SRP */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSRP */

