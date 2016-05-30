#ifndef __INC_CSMACGAELIC
#define __INC_CSMACGAELIC

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
typedef TElClassHandle TPlMacGaelicHandle;

#ifdef SB_USE_CLASS_TPLMACGAELIC
SB_IMPORT uint32_t SB_APIENTRY TPlMacGaelic_GetCategory(TPlMacGaelicHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacGaelic_GetDescription(TPlMacGaelicHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacGaelic_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacGaelic_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacGaelic_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLMACGAELIC */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlMacGaelic;

#ifdef SB_USE_CLASS_TPLMACGAELIC
class TPlMacGaelic: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlMacGaelic)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlMacGaelic(TPlMacGaelicHandle handle, TElOwnHandle ownHandle);

		TPlMacGaelic();

		static TPlMacGaelic CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLMACGAELIC */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSMACGAELIC */

