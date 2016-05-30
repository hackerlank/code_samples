#ifndef __INC_CSCP1257
#define __INC_CSCP1257

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
typedef TElClassHandle TPlCP1257Handle;

#ifdef SB_USE_CLASS_TPLCP1257
SB_IMPORT uint32_t SB_APIENTRY TPlCP1257_GetCategory(TPlCP1257Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1257_GetDescription(TPlCP1257Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1257_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1257_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1257_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP1257 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCP1257;

#ifdef SB_USE_CLASS_TPLCP1257
class TPlCP1257: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlCP1257)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP1257(TPlCP1257Handle handle, TElOwnHandle ownHandle);

		TPlCP1257();

		static TPlCP1257 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCP1257 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCP1257 */

