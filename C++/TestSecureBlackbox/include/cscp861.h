#ifndef __INC_CSCP861
#define __INC_CSCP861

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
typedef TElClassHandle TPlCP861Handle;

#ifdef SB_USE_CLASS_TPLCP861
SB_IMPORT uint32_t SB_APIENTRY TPlCP861_GetCategory(TPlCP861Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP861_GetDescription(TPlCP861Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP861_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP861_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP861_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP861 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCP861;

#ifdef SB_USE_CLASS_TPLCP861
class TPlCP861: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlCP861)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP861(TPlCP861Handle handle, TElOwnHandle ownHandle);

		TPlCP861();

		static TPlCP861 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCP861 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCP861 */

