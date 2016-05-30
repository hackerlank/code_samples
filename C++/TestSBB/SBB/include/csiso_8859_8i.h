#ifndef __INC_CSISO_8859_8I
#define __INC_CSISO_8859_8I

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbchsconvbase.h"
#include "csiso_8859_8.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TPlISO_8859_8iHandle;

#ifdef SB_USE_CLASS_TPLISO_8859_8I
SB_IMPORT uint32_t SB_APIENTRY TPlISO_8859_8i_GetCategory(TPlISO_8859_8iHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_8859_8i_GetDescription(TPlISO_8859_8iHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_8859_8i_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_8859_8i_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_8859_8i_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLISO_8859_8I */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlISO_8859_8i;

#ifdef SB_USE_CLASS_TPLISO_8859_8I
class TPlISO_8859_8i: public TPlISO_8859_8
{
	private:
		SB_DISABLE_COPY(TPlISO_8859_8i)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlISO_8859_8i(TPlISO_8859_8iHandle handle, TElOwnHandle ownHandle);

		TPlISO_8859_8i();

		static TPlISO_8859_8i CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLISO_8859_8I */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSISO_8859_8I */

