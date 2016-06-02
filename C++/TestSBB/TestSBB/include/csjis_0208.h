#ifndef __INC_CSJIS_0208
#define __INC_CSJIS_0208

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
typedef TElClassHandle TPlJIS_0208Handle;

#ifdef SB_USE_CLASS_TPLJIS_0208
SB_IMPORT uint32_t SB_APIENTRY TPlJIS_0208_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlJIS_0208_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlJIS_0208_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLJIS_0208 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlJIS_0208;

#ifdef SB_USE_CLASS_TPLJIS_0208
class TPlJIS_0208: public TPlTableCharset
{
	private:
		SB_DISABLE_COPY(TPlJIS_0208)
	public:
		static TClassHandle ClassType();

		TPlJIS_0208(TPlJIS_0208Handle handle, TElOwnHandle ownHandle);

		TPlJIS_0208();

		static TPlJIS_0208 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLJIS_0208 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSJIS_0208 */

