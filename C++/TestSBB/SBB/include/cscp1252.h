#ifndef __INC_CSCP1252
#define __INC_CSCP1252

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
typedef TElClassHandle TPlCP1252Handle;

#ifdef SB_USE_CLASS_TPLCP1252
SB_IMPORT uint32_t SB_APIENTRY TPlCP1252_GetCategory(TPlCP1252Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1252_GetDescription(TPlCP1252Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1252_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1252_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP1252_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP1252 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCP1252;

#ifdef SB_USE_CLASS_TPLCP1252
class TPlCP1252: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlCP1252)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP1252(TPlCP1252Handle handle, TElOwnHandle ownHandle);

		TPlCP1252();

		static TPlCP1252 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCP1252 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCP1252 */

