#ifndef __INC_SBGOSTCOMMON
#define __INC_SBGOSTCOMMON

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
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
#define SB_c_GOST_BlockSize 	8
#define SB_c_GOST_KeySize 	32

typedef TElClassHandle TElGOSTBaseHandle;

typedef uint8_t TElGostSubstBlock[8][16];

typedef void (SB_CALLBACK *TElBlockConvert_proc)(void * _ObjectData, const uint8_t pInBuf[], int32_t szInBuf, int32_t In_StartIdx, uint8_t pOutBuf[], int32_t * szOutBuf, int32_t Out_StartIdx, int8_t Flag);

typedef void (SB_CALLBACK *TElBlockProcess_proc)(void * _ObjectData, const uint8_t pInBuf[], int32_t szInBuf, int32_t StartIdx);

#ifdef SB_USE_CLASS_TELGOSTBASE
SB_IMPORT uint32_t SB_APIENTRY TElGOSTBase_Init(TElGOSTBaseHandle _Handle, const TElGostSubstBlock * SubstBlock);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTBase_Reset(TElGOSTBaseHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTBase_Clone(TElGOSTBaseHandle _Handle, TElGOSTBaseHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTBase_EncryptBlock(TElGOSTBaseHandle _Handle, uint32_t * B0, uint32_t * B1);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTBase_DecryptBlock(TElGOSTBaseHandle _Handle, uint32_t * B0, uint32_t * B1);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTBase_MakeSubstBlock(const char * pcGostSubstBlockHex, int32_t szGostSubstBlockHex, TElGostSubstBlock * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTBase_MakeSubstBlock_1(TElGOSTBaseHandle _Handle, const char * pcGostSubstBlockHex, int32_t szGostSubstBlockHex, TElGostSubstBlock * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTBase_Create(TElGOSTBaseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTBase_Create_1(const TElGostSubstBlock * SubstBlock, TElGOSTBaseHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOSTBASE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElGOSTBase;

#ifdef SB_USE_CLASS_TELGOSTBASE
class TElGOSTBase: public TObject
{
	private:
		SB_DISABLE_COPY(TElGOSTBase)
	public:
		void Init(const TElGostSubstBlock &SubstBlock);

		virtual void Reset();

		virtual void Clone(TElGOSTBase &Source);

		virtual void Clone(TElGOSTBase *Source);

		void EncryptBlock(uint32_t &B0, uint32_t &B1);

		void DecryptBlock(uint32_t &B0, uint32_t &B1);

		static void MakeSubstBlock(const std::string &GostSubstBlockHex, TElGostSubstBlock &OutResult);

		void MakeSubstBlock_Inst(const std::string &GostSubstBlockHex, TElGostSubstBlock &OutResult);

		TElGOSTBase(TElGOSTBaseHandle handle, TElOwnHandle ownHandle);

		TElGOSTBase();

		explicit TElGOSTBase(const TElGostSubstBlock &SubstBlock);

};
#endif /* SB_USE_CLASS_TELGOSTBASE */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBGOSTCOMMON */

