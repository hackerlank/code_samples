#ifndef __INC_CSMACCENTRALEUROPEAN
#define __INC_CSMACCENTRALEUROPEAN

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
typedef TElClassHandle TPlMacCentralEuropeanHandle;

#ifdef SB_USE_CLASS_TPLMACCENTRALEUROPEAN
SB_IMPORT uint32_t SB_APIENTRY TPlMacCentralEuropean_GetCategory(TPlMacCentralEuropeanHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacCentralEuropean_GetDescription(TPlMacCentralEuropeanHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacCentralEuropean_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacCentralEuropean_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacCentralEuropean_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLMACCENTRALEUROPEAN */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlMacCentralEuropean;

#ifdef SB_USE_CLASS_TPLMACCENTRALEUROPEAN
class TPlMacCentralEuropean: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlMacCentralEuropean)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlMacCentralEuropean(TPlMacCentralEuropeanHandle handle, TElOwnHandle ownHandle);

		TPlMacCentralEuropean();

		static TPlMacCentralEuropean CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLMACCENTRALEUROPEAN */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSMACCENTRALEUROPEAN */

