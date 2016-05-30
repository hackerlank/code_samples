#ifndef __INC_CSCNS_11643_F
#define __INC_CSCNS_11643_F

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
typedef TElClassHandle TPlCNS_11643_FHandle;

#ifdef SB_USE_CLASS_TPLCNS_11643_F
SB_IMPORT uint32_t SB_APIENTRY TPlCNS_11643_F_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCNS_11643_F_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCNS_11643_F_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCNS_11643_F */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCNS_11643_F;

#ifdef SB_USE_CLASS_TPLCNS_11643_F
class TPlCNS_11643_F: public TPlTableCharset
{
	private:
		SB_DISABLE_COPY(TPlCNS_11643_F)
	public:
		static TClassHandle ClassType();

		TPlCNS_11643_F(TPlCNS_11643_FHandle handle, TElOwnHandle ownHandle);

		TPlCNS_11643_F();

		static TPlCNS_11643_F CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCNS_11643_F */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSCNS_11643_F */

