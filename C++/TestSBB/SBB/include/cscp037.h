#ifndef __INC_CSCP037
#define __INC_CSCP037

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
typedef TElClassHandle TPlCP037Handle;

#ifdef SB_USE_CLASS_TPLCP037
SB_IMPORT uint32_t SB_APIENTRY TPlCP037_GetCategory(TPlCP037Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP037_GetDescription(TPlCP037Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP037_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP037_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP037_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP037 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCP037;

#ifdef SB_USE_CLASS_TPLCP037
class TPlCP037: public TPlTableCharset
{
	private:
		SB_DISABLE_COPY(TPlCP037)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP037(TPlCP037Handle handle, TElOwnHandle ownHandle);

		TPlCP037();

		static TPlCP037 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCP037 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCP037 */

