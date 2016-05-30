#ifndef __INC_CSCP875
#define __INC_CSCP875

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
typedef TElClassHandle TPlCP875Handle;

#ifdef SB_USE_CLASS_TPLCP875
SB_IMPORT uint32_t SB_APIENTRY TPlCP875_GetCategory(TPlCP875Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP875_GetDescription(TPlCP875Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP875_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP875_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP875_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP875 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCP875;

#ifdef SB_USE_CLASS_TPLCP875
class TPlCP875: public TPlTableCharset
{
	private:
		SB_DISABLE_COPY(TPlCP875)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP875(TPlCP875Handle handle, TElOwnHandle ownHandle);

		TPlCP875();

		static TPlCP875 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCP875 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCP875 */

