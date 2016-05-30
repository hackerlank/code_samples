#ifndef __INC_CSCP1253
#define __INC_CSCP1253

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
typedef TElClassHandle TPlCP1253Handle;

#ifdef SB_USE_CLASS_TPLCP1253
SB_IMPORT uint32_t SB_APIENTRY TPlCP1253_GetCategory(TPlCP1253Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1253_GetDescription(TPlCP1253Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1253_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1253_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1253_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP1253 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCP1253;

#ifdef SB_USE_CLASS_TPLCP1253
class TPlCP1253: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlCP1253)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP1253(TPlCP1253Handle handle, TElOwnHandle ownHandle);

		TPlCP1253();

		static TPlCP1253 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCP1253 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCP1253 */

