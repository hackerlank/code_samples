#ifndef __INC_CSCP1256
#define __INC_CSCP1256

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
typedef TElClassHandle TPlCP1256Handle;

#ifdef SB_USE_CLASS_TPLCP1256
SB_IMPORT uint32_t SB_APIENTRY TPlCP1256_GetCategory(TPlCP1256Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1256_GetDescription(TPlCP1256Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1256_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1256_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1256_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP1256 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCP1256;

#ifdef SB_USE_CLASS_TPLCP1256
class TPlCP1256: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlCP1256)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP1256(TPlCP1256Handle handle, TElOwnHandle ownHandle);

		TPlCP1256();

		static TPlCP1256 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCP1256 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCP1256 */

