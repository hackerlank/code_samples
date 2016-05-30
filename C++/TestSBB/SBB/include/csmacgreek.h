#ifndef __INC_CSMACGREEK
#define __INC_CSMACGREEK

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
typedef TElClassHandle TPlMacGreekHandle;

#ifdef SB_USE_CLASS_TPLMACGREEK
SB_IMPORT uint32_t SB_APIENTRY TPlMacGreek_GetCategory(TPlMacGreekHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacGreek_GetDescription(TPlMacGreekHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacGreek_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacGreek_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacGreek_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLMACGREEK */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlMacGreek;

#ifdef SB_USE_CLASS_TPLMACGREEK
class TPlMacGreek: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlMacGreek)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlMacGreek(TPlMacGreekHandle handle, TElOwnHandle ownHandle);

		TPlMacGreek();

		static TPlMacGreek CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLMACGREEK */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSMACGREEK */

