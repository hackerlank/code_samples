#ifndef __INC_CSCP1006
#define __INC_CSCP1006

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
typedef TElClassHandle TPlCP1006Handle;

#ifdef SB_USE_CLASS_TPLCP1006
SB_IMPORT uint32_t SB_APIENTRY TPlCP1006_GetCategory(TPlCP1006Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1006_GetDescription(TPlCP1006Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1006_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1006_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1006_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP1006 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCP1006;

#ifdef SB_USE_CLASS_TPLCP1006
class TPlCP1006: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlCP1006)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP1006(TPlCP1006Handle handle, TElOwnHandle ownHandle);

		TPlCP1006();

		static TPlCP1006 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCP1006 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCP1006 */

