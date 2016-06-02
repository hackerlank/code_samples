#ifndef __INC_CSGB_18030
#define __INC_CSGB_18030

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
typedef TElClassHandle TPlGB_18030DataHandle;

#ifdef SB_USE_CLASS_TPLGB_18030DATA
SB_IMPORT uint32_t SB_APIENTRY TPlGB_18030Data_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGB_18030Data_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGB_18030Data_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLGB_18030DATA */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlGB_18030Data;

#ifdef SB_USE_CLASS_TPLGB_18030DATA
class TPlGB_18030Data: public TPlTableCharset
{
	private:
		SB_DISABLE_COPY(TPlGB_18030Data)
	public:
		static TClassHandle ClassType();

		TPlGB_18030Data(TPlGB_18030DataHandle handle, TElOwnHandle ownHandle);

		TPlGB_18030Data();

		static TPlGB_18030Data CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLGB_18030DATA */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSGB_18030 */

