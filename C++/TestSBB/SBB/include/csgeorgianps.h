#ifndef __INC_CSGEORGIANPS
#define __INC_CSGEORGIANPS

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
typedef TElClassHandle TPlGeorgianPSHandle;

#ifdef SB_USE_CLASS_TPLGEORGIANPS
SB_IMPORT uint32_t SB_APIENTRY TPlGeorgianPS_GetCategory(TPlGeorgianPSHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGeorgianPS_GetDescription(TPlGeorgianPSHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGeorgianPS_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGeorgianPS_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGeorgianPS_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLGEORGIANPS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlGeorgianPS;

#ifdef SB_USE_CLASS_TPLGEORGIANPS
class TPlGeorgianPS: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlGeorgianPS)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlGeorgianPS(TPlGeorgianPSHandle handle, TElOwnHandle ownHandle);

		TPlGeorgianPS();

		static TPlGeorgianPS CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLGEORGIANPS */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSGEORGIANPS */

