#ifndef __INC_CSCP856
#define __INC_CSCP856

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
typedef TElClassHandle TPlCP856Handle;

#ifdef SB_USE_CLASS_TPLCP856
SB_IMPORT uint32_t SB_APIENTRY TPlCP856_GetCategory(TPlCP856Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP856_GetDescription(TPlCP856Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP856_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP856_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP856_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP856 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCP856;

#ifdef SB_USE_CLASS_TPLCP856
class TPlCP856: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlCP856)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP856(TPlCP856Handle handle, TElOwnHandle ownHandle);

		TPlCP856();

		static TPlCP856 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCP856 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCP856 */

