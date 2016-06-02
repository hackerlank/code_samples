#ifndef __INC_CSCP1251
#define __INC_CSCP1251

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
typedef TElClassHandle TPlCP1251Handle;

#ifdef SB_USE_CLASS_TPLCP1251
SB_IMPORT uint32_t SB_APIENTRY TPlCP1251_GetCategory(TPlCP1251Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1251_GetDescription(TPlCP1251Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1251_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1251_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1251_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP1251 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCP1251;

#ifdef SB_USE_CLASS_TPLCP1251
class TPlCP1251: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlCP1251)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP1251(TPlCP1251Handle handle, TElOwnHandle ownHandle);

		TPlCP1251();

		static TPlCP1251 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCP1251 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCP1251 */

