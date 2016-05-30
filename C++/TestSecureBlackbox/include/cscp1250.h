#ifndef __INC_CSCP1250
#define __INC_CSCP1250

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
typedef TElClassHandle TPlCP1250Handle;

#ifdef SB_USE_CLASS_TPLCP1250
SB_IMPORT uint32_t SB_APIENTRY TPlCP1250_GetCategory(TPlCP1250Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1250_GetDescription(TPlCP1250Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1250_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1250_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1250_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP1250 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCP1250;

#ifdef SB_USE_CLASS_TPLCP1250
class TPlCP1250: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlCP1250)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP1250(TPlCP1250Handle handle, TElOwnHandle ownHandle);

		TPlCP1250();

		static TPlCP1250 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCP1250 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCP1250 */

