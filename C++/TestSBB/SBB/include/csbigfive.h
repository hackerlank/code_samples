#ifndef __INC_CSBIGFIVE
#define __INC_CSBIGFIVE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbchsconvbase.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TPlBigFiveHandle;

#ifdef SB_USE_CLASS_TPLBIGFIVE
SB_IMPORT uint32_t SB_APIENTRY TPlBigFive_GetCategory(TPlBigFiveHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlBigFive_GetDescription(TPlBigFiveHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlBigFive_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlBigFive_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlBigFive_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLBIGFIVE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlBigFive;

#ifdef SB_USE_CLASS_TPLBIGFIVE
class TPlBigFive: public TPlTableCharset
{
	private:
		SB_DISABLE_COPY(TPlBigFive)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlBigFive(TPlBigFiveHandle handle, TElOwnHandle ownHandle);

		TPlBigFive();

		static TPlBigFive CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLBIGFIVE */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSBIGFIVE */

