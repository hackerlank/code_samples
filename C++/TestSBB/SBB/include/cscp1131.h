#ifndef __INC_CSCP1131
#define __INC_CSCP1131

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
typedef TElClassHandle TPlCP1131Handle;

#ifdef SB_USE_CLASS_TPLCP1131
SB_IMPORT uint32_t SB_APIENTRY TPlCP1131_GetCategory(TPlCP1131Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1131_GetDescription(TPlCP1131Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1131_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1131_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1131_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP1131 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCP1131;

#ifdef SB_USE_CLASS_TPLCP1131
class TPlCP1131: public TPlTableCharset
{
	private:
		SB_DISABLE_COPY(TPlCP1131)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP1131(TPlCP1131Handle handle, TElOwnHandle ownHandle);

		TPlCP1131();

		static TPlCP1131 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCP1131 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCP1131 */

