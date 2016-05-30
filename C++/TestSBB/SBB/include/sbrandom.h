#ifndef __INC_SBRANDOM
#define __INC_SBRANDOM

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbmath.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstreams.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElRandomHandle;

typedef TElRandomHandle ElRandomHandle;

#ifdef SB_USE_CLASS_TELRANDOM
SB_IMPORT uint32_t SB_APIENTRY TElRandom_Randomize(TElRandomHandle _Handle, const uint8_t pSeed[], int32_t szSeed);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElRandom_Randomize_1(TElRandomHandle _Handle, TStreamHandle Stream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElRandom_Randomize_2(TElRandomHandle _Handle, void * Buffer, int32_t Count);
#else
SB_IMPORT uint32_t SB_APIENTRY TElRandom_Randomize_1(TElRandomHandle _Handle, void * Buffer, int32_t Count);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElRandom_Generate(TElRandomHandle _Handle, int32_t Count, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRandom_Generate_1(TElRandomHandle _Handle, void * Buffer, int32_t Count);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElRandom_Generate_2(TElRandomHandle _Handle, TStreamHandle Stream, int32_t Count);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElRandom_Seed(TElRandomHandle _Handle, void * Buffer, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElRandom_Create(TElRandomHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRandom_Create_1(uint32_t TimeSeed, TElRandomHandle * OutResult);
#endif /* SB_USE_CLASS_TELRANDOM */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElRandom;
typedef TElRandom ElRandom;

#ifdef SB_USE_CLASS_TELRANDOM
class TElRandom: public TObject
{
	private:
		SB_DISABLE_COPY(TElRandom)
	public:
		void Randomize(const std::vector<uint8_t> &Seed);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTREAM
		void Randomize(TStream &Stream, int32_t Count);

		void Randomize(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */
#endif

		void Randomize(void * Buffer, int32_t Count);

		void Generate(int32_t Count, std::vector<uint8_t> &OutResult);

		void Generate(void * Buffer, int32_t Count);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTREAM
		void Generate(TStream &Stream, int32_t Count);

		void Generate(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */
#endif

		void Seed(void * Buffer, int32_t Count);

		TElRandom(TElRandomHandle handle, TElOwnHandle ownHandle);

		TElRandom();

		explicit TElRandom(uint32_t TimeSeed);

};
#endif /* SB_USE_CLASS_TELRANDOM */

#ifdef SB_USE_GLOBAL_PROCS_RANDOM

int32_t SBRndTimeSeed();

void SBRndInit();

void SBRndInitOnDemand();

void SBRndCreate();

void SBRndDestroy();

void SBRndSeed(const std::string &Salt);

void SBRndSeed(void * Buffer, int32_t Size);

void SBRndSeedTime();

void SBRndGenerate(void * Buffer, int32_t Size);

uint32_t SBRndGenerate(uint32_t UpperBound);

void SBRndGenerateLInt(PLInt A, int32_t Bytes);

void SBRndRandomize(const std::vector<uint8_t> &Seed);

void SBRndString(int32_t Len, std::string &OutResult);

void SBRndString(int32_t Len, const std::string &Alphabet, std::string &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_RANDOM */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_RANDOM
SB_IMPORT uint32_t SB_APIENTRY SBRandom_SBRndTimeSeed(int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRandom_SBRndInit(void);
SB_IMPORT uint32_t SB_APIENTRY SBRandom_SBRndInitOnDemand(void);
SB_IMPORT uint32_t SB_APIENTRY SBRandom_SBRndCreate(void);
SB_IMPORT uint32_t SB_APIENTRY SBRandom_SBRndDestroy(void);
SB_IMPORT uint32_t SB_APIENTRY SBRandom_SBRndSeed(const char * pcSalt, int32_t szSalt);
SB_IMPORT uint32_t SB_APIENTRY SBRandom_SBRndSeed_1(void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBRandom_SBRndSeedTime(void);
SB_IMPORT uint32_t SB_APIENTRY SBRandom_SBRndGenerate(void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBRandom_SBRndGenerate_1(uint32_t UpperBound, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRandom_SBRndGenerateLInt(PLInt A, int32_t Bytes);
SB_IMPORT uint32_t SB_APIENTRY SBRandom_SBRndRandomize(const uint8_t pSeed[], int32_t szSeed);
SB_IMPORT uint32_t SB_APIENTRY SBRandom_SBRndString(int32_t Len, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRandom_SBRndString_1(int32_t Len, const char * pcAlphabet, int32_t szAlphabet, char * pcOutResult, int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_RANDOM */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBRANDOM */
