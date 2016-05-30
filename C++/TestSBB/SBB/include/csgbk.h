#ifndef __INC_CSGBK
#define __INC_CSGBK

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
typedef TElClassHandle TPlGBKDataHandle;

#ifdef SB_USE_CLASS_TPLGBKDATA
SB_IMPORT uint32_t SB_APIENTRY TPlGBKData_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGBKData_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGBKData_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLGBKDATA */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlGBKData;

#ifdef SB_USE_CLASS_TPLGBKDATA
class TPlGBKData: public TPlTableCharset
{
	private:
		SB_DISABLE_COPY(TPlGBKData)
	public:
		static TClassHandle ClassType();

		TPlGBKData(TPlGBKDataHandle handle, TElOwnHandle ownHandle);

		TPlGBKData();

		static TPlGBKData CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLGBKDATA */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSGBK */

