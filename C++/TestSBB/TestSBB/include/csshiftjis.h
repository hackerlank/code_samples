#ifndef __INC_CSSHIFTJIS
#define __INC_CSSHIFTJIS

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
typedef TElClassHandle TPlShiftJISDataHandle;

#ifdef SB_USE_CLASS_TPLSHIFTJISDATA
SB_IMPORT uint32_t SB_APIENTRY TPlShiftJISData_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlShiftJISData_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlShiftJISData_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLSHIFTJISDATA */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlShiftJISData;

#ifdef SB_USE_CLASS_TPLSHIFTJISDATA
class TPlShiftJISData: public TPlTableCharset
{
	private:
		SB_DISABLE_COPY(TPlShiftJISData)
	public:
		static TClassHandle ClassType();

		TPlShiftJISData(TPlShiftJISDataHandle handle, TElOwnHandle ownHandle);

		TPlShiftJISData();

		static TPlShiftJISData CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLSHIFTJISDATA */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSSHIFTJIS */

