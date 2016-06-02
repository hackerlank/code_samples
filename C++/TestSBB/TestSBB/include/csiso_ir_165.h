#ifndef __INC_CSISO_IR_165
#define __INC_CSISO_IR_165

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
typedef TElClassHandle TPlISO_IR_165DataHandle;

#ifdef SB_USE_CLASS_TPLISO_IR_165DATA
SB_IMPORT uint32_t SB_APIENTRY TPlISO_IR_165Data_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_IR_165Data_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_IR_165Data_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLISO_IR_165DATA */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlISO_IR_165Data;

#ifdef SB_USE_CLASS_TPLISO_IR_165DATA
class TPlISO_IR_165Data: public TPlTableCharset
{
	private:
		SB_DISABLE_COPY(TPlISO_IR_165Data)
	public:
		static TClassHandle ClassType();

		TPlISO_IR_165Data(TPlISO_IR_165DataHandle handle, TElOwnHandle ownHandle);

		TPlISO_IR_165Data();

		static TPlISO_IR_165Data CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLISO_IR_165DATA */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSISO_IR_165 */

