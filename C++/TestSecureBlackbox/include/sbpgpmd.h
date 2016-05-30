#ifndef __INC_SBPGPMD
#define __INC_SBPGPMD

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbhashfunction.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElPGPHashingPoolHandle;

#ifdef SB_USE_CLASS_TELPGPHASHINGPOOL
SB_IMPORT uint32_t SB_APIENTRY TElPGPHashingPool_Add(TElPGPHashingPoolHandle _Handle, int32_t Algorithm, int8_t SkipIfExists, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPHashingPool_Clear(TElPGPHashingPoolHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPHashingPool_Remove(TElPGPHashingPoolHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPGPHashingPool_Reset(TElPGPHashingPoolHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPHashingPool_NFinalize(TElPGPHashingPoolHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPHashingPool_Update(TElPGPHashingPoolHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElPGPHashingPool_Update_1(TElPGPHashingPoolHandle _Handle, TStreamHandle Stream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElPGPHashingPool_GetContextByAlgorithm(TElPGPHashingPoolHandle _Handle, int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPHashingPool_get_HashFunctions(TElPGPHashingPoolHandle _Handle, int32_t Index, TElHashFunctionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPHashingPool_get_Count(TElPGPHashingPoolHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPHashingPool_get_DataIsText(TElPGPHashingPoolHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPHashingPool_set_DataIsText(TElPGPHashingPoolHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPHashingPool_get_CompMode(TElPGPHashingPoolHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPHashingPool_set_CompMode(TElPGPHashingPoolHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPHashingPool_Create(TElPGPHashingPoolHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPHASHINGPOOL */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPGPHashingPool;

#ifdef SB_USE_CLASS_TELPGPHASHINGPOOL
class TElPGPHashingPool: public TObject
{
	private:
		SB_DISABLE_COPY(TElPGPHashingPool)
#ifdef SB_USE_CLASS_TELHASHFUNCTION
		TElHashFunction* _Inst_HashFunctions;
#endif /* SB_USE_CLASS_TELHASHFUNCTION */

		void initInstances();

	public:
		int32_t Add(int32_t Algorithm, bool SkipIfExists);

		void Clear();

		void Remove(int32_t Index);

		void Reset();

		void NFinalize();

		void Update(void * Buffer, int32_t Size);

#ifdef SB_USE_CLASS_TSTREAM
		void Update(TStream &Stream, int32_t Count);

		void Update(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		int32_t GetContextByAlgorithm(int32_t Algorithm);

#ifdef SB_USE_CLASS_TELHASHFUNCTION
		virtual TElHashFunction* get_HashFunctions(int32_t Index);
#endif /* SB_USE_CLASS_TELHASHFUNCTION */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElPGPHashingPool, Count);

		virtual bool get_DataIsText();

		virtual void set_DataIsText(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DataIsText, set_DataIsText, TElPGPHashingPool, DataIsText);

		virtual bool get_CompMode();

		virtual void set_CompMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CompMode, set_CompMode, TElPGPHashingPool, CompMode);

		TElPGPHashingPool(TElPGPHashingPoolHandle handle, TElOwnHandle ownHandle);

		TElPGPHashingPool();

		virtual ~TElPGPHashingPool();

};
#endif /* SB_USE_CLASS_TELPGPHASHINGPOOL */

#ifdef SB_USE_GLOBAL_PROCS_PGPMD

int32_t MDGetDigestSize(int32_t Algorithm);

#ifdef SB_USE_CLASS_TELHASHFUNCTION
void MDInitialize(TElHashFunction &HashFunction, int32_t Algorithm);
#endif /* SB_USE_CLASS_TELHASHFUNCTION */

void MDHash(int32_t Algorithm, const std::vector<uint8_t> &Data, int32_t Size, std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELHASHFUNCTION
void MDFinalize(TElHashFunction &HashFunction, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELHASHFUNCTION */

#endif /* SB_USE_GLOBAL_PROCS_PGPMD */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_PGPMD
SB_IMPORT uint32_t SB_APIENTRY SBPGPMD_MDGetDigestSize(int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPMD_MDInitialize(TElHashFunctionHandle * HashFunction, int32_t Algorithm);
SB_IMPORT uint32_t SB_APIENTRY SBPGPMD_MDHash(int32_t Algorithm, const uint8_t pData[], int32_t szData, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPMD_MDFinalize(TElHashFunctionHandle * HashFunction, uint8_t pOutResult[], int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_PGPMD */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPGPMD */

