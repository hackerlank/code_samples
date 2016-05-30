#ifndef __INC_CSJIS_0201
#define __INC_CSJIS_0201

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
typedef TElClassHandle TPlJIS_0201Handle;

#ifdef SB_USE_CLASS_TPLJIS_0201
SB_IMPORT uint32_t SB_APIENTRY TPlJIS_0201_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlJIS_0201_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlJIS_0201_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLJIS_0201 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlJIS_0201;

#ifdef SB_USE_CLASS_TPLJIS_0201
class TPlJIS_0201: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlJIS_0201)
	public:
		static TClassHandle ClassType();

		TPlJIS_0201(TPlJIS_0201Handle handle, TElOwnHandle ownHandle);

		TPlJIS_0201();

		static TPlJIS_0201 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLJIS_0201 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSJIS_0201 */

