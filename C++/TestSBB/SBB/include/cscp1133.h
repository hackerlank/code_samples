#ifndef __INC_CSCP1133
#define __INC_CSCP1133

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
typedef TElClassHandle TPlCP1133Handle;

#ifdef SB_USE_CLASS_TPLCP1133
SB_IMPORT uint32_t SB_APIENTRY TPlCP1133_GetCategory(TPlCP1133Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1133_GetDescription(TPlCP1133Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1133_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1133_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1133_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP1133 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCP1133;

#ifdef SB_USE_CLASS_TPLCP1133
class TPlCP1133: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlCP1133)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP1133(TPlCP1133Handle handle, TElOwnHandle ownHandle);

		TPlCP1133();

		static TPlCP1133 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCP1133 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCP1133 */

