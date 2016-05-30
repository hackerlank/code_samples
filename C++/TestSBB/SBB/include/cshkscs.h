#ifndef __INC_CSHKSCS
#define __INC_CSHKSCS

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
typedef TElClassHandle TPlHKSCSDataHandle;

#ifdef SB_USE_CLASS_TPLHKSCSDATA
SB_IMPORT uint32_t SB_APIENTRY TPlHKSCSData_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlHKSCSData_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlHKSCSData_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLHKSCSDATA */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlHKSCSData;

#ifdef SB_USE_CLASS_TPLHKSCSDATA
class TPlHKSCSData: public TPlTableCharset
{
	private:
		SB_DISABLE_COPY(TPlHKSCSData)
	public:
		static TClassHandle ClassType();

		TPlHKSCSData(TPlHKSCSDataHandle handle, TElOwnHandle ownHandle);

		TPlHKSCSData();

		static TPlHKSCSData CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLHKSCSDATA */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSHKSCS */

