#ifndef __INC_CSCP775
#define __INC_CSCP775

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
typedef TElClassHandle TPlCP775Handle;

#ifdef SB_USE_CLASS_TPLCP775
SB_IMPORT uint32_t SB_APIENTRY TPlCP775_GetCategory(TPlCP775Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP775_GetDescription(TPlCP775Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP775_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP775_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP775_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP775 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCP775;

#ifdef SB_USE_CLASS_TPLCP775
class TPlCP775: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlCP775)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP775(TPlCP775Handle handle, TElOwnHandle ownHandle);

		TPlCP775();

		static TPlCP775 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCP775 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCP775 */

