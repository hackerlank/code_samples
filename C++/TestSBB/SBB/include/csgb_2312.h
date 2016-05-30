#ifndef __INC_CSGB_2312
#define __INC_CSGB_2312

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
typedef TElClassHandle TPlGB_2312Handle;

#ifdef SB_USE_CLASS_TPLGB_2312
SB_IMPORT uint32_t SB_APIENTRY TPlGB_2312_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGB_2312_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGB_2312_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLGB_2312 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlGB_2312;

#ifdef SB_USE_CLASS_TPLGB_2312
class TPlGB_2312: public TPlTableCharset
{
	private:
		SB_DISABLE_COPY(TPlGB_2312)
	public:
		static TClassHandle ClassType();

		TPlGB_2312(TPlGB_2312Handle handle, TElOwnHandle ownHandle);

		TPlGB_2312();

		static TPlGB_2312 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLGB_2312 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSGB_2312 */

