#ifndef __INC_CSMACCYRILLIC
#define __INC_CSMACCYRILLIC

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
typedef TElClassHandle TPlMacCyrillicHandle;

#ifdef SB_USE_CLASS_TPLMACCYRILLIC
SB_IMPORT uint32_t SB_APIENTRY TPlMacCyrillic_GetCategory(TPlMacCyrillicHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacCyrillic_GetDescription(TPlMacCyrillicHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacCyrillic_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacCyrillic_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacCyrillic_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLMACCYRILLIC */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlMacCyrillic;

#ifdef SB_USE_CLASS_TPLMACCYRILLIC
class TPlMacCyrillic: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlMacCyrillic)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlMacCyrillic(TPlMacCyrillicHandle handle, TElOwnHandle ownHandle);

		TPlMacCyrillic();

		static TPlMacCyrillic CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLMACCYRILLIC */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSMACCYRILLIC */

