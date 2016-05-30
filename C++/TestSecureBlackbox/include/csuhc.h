#ifndef __INC_CSUHC
#define __INC_CSUHC

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
typedef TElClassHandle TPlUHCHandle;

#ifdef SB_USE_CLASS_TPLUHC
SB_IMPORT uint32_t SB_APIENTRY TPlUHC_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUHC_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUHC_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLUHC */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlUHC;

#ifdef SB_USE_CLASS_TPLUHC
class TPlUHC: public TPlTableCharset
{
	private:
		SB_DISABLE_COPY(TPlUHC)
	public:
		static TClassHandle ClassType();

		TPlUHC(TPlUHCHandle handle, TElOwnHandle ownHandle);

		TPlUHC();

		static TPlUHC CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLUHC */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSUHC */

