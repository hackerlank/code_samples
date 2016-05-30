#ifndef __INC_CSCP500
#define __INC_CSCP500

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
typedef TElClassHandle TPlCP500Handle;

#ifdef SB_USE_CLASS_TPLCP500
SB_IMPORT uint32_t SB_APIENTRY TPlCP500_GetCategory(TPlCP500Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP500_GetDescription(TPlCP500Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP500_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP500_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP500_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP500 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCP500;

#ifdef SB_USE_CLASS_TPLCP500
class TPlCP500: public TPlTableCharset
{
	private:
		SB_DISABLE_COPY(TPlCP500)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP500(TPlCP500Handle handle, TElOwnHandle ownHandle);

		TPlCP500();

		static TPlCP500 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCP500 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCP500 */

