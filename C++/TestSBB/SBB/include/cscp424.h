#ifndef __INC_CSCP424
#define __INC_CSCP424

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
typedef TElClassHandle TPlCP424Handle;

#ifdef SB_USE_CLASS_TPLCP424
SB_IMPORT uint32_t SB_APIENTRY TPlCP424_GetCategory(TPlCP424Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP424_GetDescription(TPlCP424Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP424_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP424_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP424_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP424 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCP424;

#ifdef SB_USE_CLASS_TPLCP424
class TPlCP424: public TPlTableCharset
{
	private:
		SB_DISABLE_COPY(TPlCP424)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP424(TPlCP424Handle handle, TElOwnHandle ownHandle);

		TPlCP424();

		static TPlCP424 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCP424 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCP424 */

