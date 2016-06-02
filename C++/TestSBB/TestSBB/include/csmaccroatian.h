#ifndef __INC_CSMACCROATIAN
#define __INC_CSMACCROATIAN

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
typedef TElClassHandle TPlMacCroatianHandle;

#ifdef SB_USE_CLASS_TPLMACCROATIAN
SB_IMPORT uint32_t SB_APIENTRY TPlMacCroatian_GetCategory(TPlMacCroatianHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacCroatian_GetDescription(TPlMacCroatianHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacCroatian_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacCroatian_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacCroatian_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLMACCROATIAN */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlMacCroatian;

#ifdef SB_USE_CLASS_TPLMACCROATIAN
class TPlMacCroatian: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlMacCroatian)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlMacCroatian(TPlMacCroatianHandle handle, TElOwnHandle ownHandle);

		TPlMacCroatian();

		static TPlMacCroatian CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLMACCROATIAN */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSMACCROATIAN */

