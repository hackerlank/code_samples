#ifndef __INC_SBGOST341194
#define __INC_SBGOST341194

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
#define SB_c_GOST_DigestSize 	32

typedef TElClassHandle TElGOSTMDHandle;

#ifdef SB_USE_CLASS_TELGOSTMD
SB_IMPORT uint32_t SB_APIENTRY TElGOSTMD_DigestSize(int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTMD_DigestSize_1(TElGOSTMDHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTMD_Reset(TElGOSTMDHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTMD_Clone(TElGOSTMDHandle _Handle, TElGOSTBaseHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTMD_Update(TElGOSTMDHandle _Handle, void * In_Buf, uint32_t Len);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTMD_Update_1(TElGOSTMDHandle _Handle, const uint8_t pIn_Buf[], int32_t szIn_Buf, uint32_t StartIndex, uint32_t Len);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTMD_Final(TElGOSTMDHandle _Handle, uint8_t pDigest[], int32_t * szDigest);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTMD_Calculate(TElGOSTMDHandle _Handle, const uint8_t pIn_Buf[], int32_t szIn_Buf, uint32_t StartIndex, uint32_t Len, uint8_t pDigest[], int32_t * szDigest);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTMD_Calculate_1(TElGOSTMDHandle _Handle, TStreamHandle Source, uint32_t Count, uint8_t pDigest[], int32_t * szDigest);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTMD_Create(TElGOSTMDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOSTMD_Create_1(const TElGostSubstBlock * SubstBlock, TElGOSTMDHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOSTMD */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElGOSTMD;

#ifdef SB_USE_CLASS_TELGOSTMD
class TElGOSTMD: public TElGOSTBase
{
	private:
		SB_DISABLE_COPY(TElGOSTMD)
	public:
		static int32_t DigestSize();

		int32_t DigestSize_Inst();

		virtual void Reset();

		virtual void Clone(TElGOSTBase &Source);

		virtual void Clone(TElGOSTBase *Source);

		void Update(void * In_Buf, uint32_t Len);

		void Update(const std::vector<uint8_t> &In_Buf, uint32_t StartIndex, uint32_t Len);

		void Final(std::vector<uint8_t> &Digest);

		void Calculate(const std::vector<uint8_t> &In_Buf, uint32_t StartIndex, uint32_t Len, std::vector<uint8_t> &Digest);

#ifdef SB_USE_CLASS_TSTREAM
		void Calculate(TStream &Source, uint32_t Count, std::vector<uint8_t> &Digest);

		void Calculate(TStream *Source, uint32_t Count, std::vector<uint8_t> &Digest);
#endif /* SB_USE_CLASS_TSTREAM */

		TElGOSTMD(TElGOSTMDHandle handle, TElOwnHandle ownHandle);

		TElGOSTMD();

		explicit TElGOSTMD(const TElGostSubstBlock &SubstBlock);

};
#endif /* SB_USE_CLASS_TELGOSTMD */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBGOST341194 */

