#ifndef __INC_CSCP862
#define __INC_CSCP862

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
typedef TElClassHandle TPlCP862Handle;

#ifdef SB_USE_CLASS_TPLCP862
SB_IMPORT uint32_t SB_APIENTRY TPlCP862_GetCategory(TPlCP862Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP862_GetDescription(TPlCP862Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP862_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP862_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP862_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP862 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCP862;

#ifdef SB_USE_CLASS_TPLCP862
class TPlCP862: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlCP862)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP862(TPlCP862Handle handle, TElOwnHandle ownHandle);

		TPlCP862();

		static TPlCP862 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCP862 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCP862 */

