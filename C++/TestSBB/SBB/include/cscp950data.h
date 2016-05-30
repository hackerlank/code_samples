#ifndef __INC_CSCP950DATA
#define __INC_CSCP950DATA

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
typedef TElClassHandle TPlCP950DataHandle;

#ifdef SB_USE_CLASS_TPLCP950DATA
SB_IMPORT uint32_t SB_APIENTRY TPlCP950Data_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP950Data_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP950Data_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP950DATA */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCP950Data;

#ifdef SB_USE_CLASS_TPLCP950DATA
class TPlCP950Data: public TPlTableCharset
{
	private:
		SB_DISABLE_COPY(TPlCP950Data)
	public:
		static TClassHandle ClassType();

		TPlCP950Data(TPlCP950DataHandle handle, TElOwnHandle ownHandle);

		TPlCP950Data();

		static TPlCP950Data CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCP950DATA */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCP950DATA */

