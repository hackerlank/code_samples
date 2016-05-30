#ifndef __INC_CSCP1258
#define __INC_CSCP1258

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
typedef TElClassHandle TPlCP1258Handle;

#ifdef SB_USE_CLASS_TPLCP1258
SB_IMPORT uint32_t SB_APIENTRY TPlCP1258_GetCategory(TPlCP1258Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1258_GetDescription(TPlCP1258Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1258_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1258_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1258_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP1258 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCP1258;

#ifdef SB_USE_CLASS_TPLCP1258
class TPlCP1258: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlCP1258)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP1258(TPlCP1258Handle handle, TElOwnHandle ownHandle);

		TPlCP1258();

		static TPlCP1258 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCP1258 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCP1258 */

