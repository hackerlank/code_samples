#ifndef __INC_CSCNS_11643_2
#define __INC_CSCNS_11643_2

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
typedef TElClassHandle TPlCNS_11643_2Handle;

#ifdef SB_USE_CLASS_TPLCNS_11643_2
SB_IMPORT uint32_t SB_APIENTRY TPlCNS_11643_2_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCNS_11643_2_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCNS_11643_2_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCNS_11643_2 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCNS_11643_2;

#ifdef SB_USE_CLASS_TPLCNS_11643_2
class TPlCNS_11643_2: public TPlTableCharset
{
	private:
		SB_DISABLE_COPY(TPlCNS_11643_2)
	public:
		static TClassHandle ClassType();

		TPlCNS_11643_2(TPlCNS_11643_2Handle handle, TElOwnHandle ownHandle);

		TPlCNS_11643_2();

		static TPlCNS_11643_2 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCNS_11643_2 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCNS_11643_2 */

