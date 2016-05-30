#ifndef __INC_CSCP1254
#define __INC_CSCP1254

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
typedef TElClassHandle TPlCP1254Handle;

#ifdef SB_USE_CLASS_TPLCP1254
SB_IMPORT uint32_t SB_APIENTRY TPlCP1254_GetCategory(TPlCP1254Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1254_GetDescription(TPlCP1254Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1254_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1254_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1254_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP1254 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCP1254;

#ifdef SB_USE_CLASS_TPLCP1254
class TPlCP1254: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlCP1254)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP1254(TPlCP1254Handle handle, TElOwnHandle ownHandle);

		TPlCP1254();

		static TPlCP1254 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCP1254 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCP1254 */

