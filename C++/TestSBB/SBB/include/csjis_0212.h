#ifndef __INC_CSJIS_0212
#define __INC_CSJIS_0212

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
typedef TElClassHandle TPlJIS_0212Handle;

#ifdef SB_USE_CLASS_TPLJIS_0212
SB_IMPORT uint32_t SB_APIENTRY TPlJIS_0212_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlJIS_0212_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlJIS_0212_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLJIS_0212 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlJIS_0212;

#ifdef SB_USE_CLASS_TPLJIS_0212
class TPlJIS_0212: public TPlTableCharset
{
	private:
		SB_DISABLE_COPY(TPlJIS_0212)
	public:
		static TClassHandle ClassType();

		TPlJIS_0212(TPlJIS_0212Handle handle, TElOwnHandle ownHandle);

		TPlJIS_0212();

		static TPlJIS_0212 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLJIS_0212 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSJIS_0212 */

