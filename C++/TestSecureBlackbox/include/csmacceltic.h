#ifndef __INC_CSMACCELTIC
#define __INC_CSMACCELTIC

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
typedef TElClassHandle TPlMacCelticHandle;

#ifdef SB_USE_CLASS_TPLMACCELTIC
SB_IMPORT uint32_t SB_APIENTRY TPlMacCeltic_GetCategory(TPlMacCelticHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacCeltic_GetDescription(TPlMacCelticHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacCeltic_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacCeltic_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacCeltic_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLMACCELTIC */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlMacCeltic;

#ifdef SB_USE_CLASS_TPLMACCELTIC
class TPlMacCeltic: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlMacCeltic)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlMacCeltic(TPlMacCelticHandle handle, TElOwnHandle ownHandle);

		TPlMacCeltic();

		static TPlMacCeltic CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLMACCELTIC */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSMACCELTIC */

