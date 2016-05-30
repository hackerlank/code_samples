#ifndef __INC_CSISO_8859_8
#define __INC_CSISO_8859_8

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
typedef TElClassHandle TPlISO_8859_8Handle;

#ifdef SB_USE_CLASS_TPLISO_8859_8
SB_IMPORT uint32_t SB_APIENTRY TPlISO_8859_8_GetCategory(TPlISO_8859_8Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_8859_8_GetDescription(TPlISO_8859_8Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_8859_8_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_8859_8_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_8859_8_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLISO_8859_8 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlISO_8859_8;

#ifdef SB_USE_CLASS_TPLISO_8859_8
class TPlISO_8859_8: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlISO_8859_8)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlISO_8859_8(TPlISO_8859_8Handle handle, TElOwnHandle ownHandle);

		TPlISO_8859_8();

		static TPlISO_8859_8 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLISO_8859_8 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSISO_8859_8 */

