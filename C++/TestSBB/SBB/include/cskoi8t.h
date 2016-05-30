#ifndef __INC_CSKOI8T
#define __INC_CSKOI8T

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
typedef TElClassHandle TPlKOI8THandle;

#ifdef SB_USE_CLASS_TPLKOI8T
SB_IMPORT uint32_t SB_APIENTRY TPlKOI8T_GetCategory(TPlKOI8THandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlKOI8T_GetDescription(TPlKOI8THandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlKOI8T_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlKOI8T_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlKOI8T_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLKOI8T */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlKOI8T;

#ifdef SB_USE_CLASS_TPLKOI8T
class TPlKOI8T: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlKOI8T)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlKOI8T(TPlKOI8THandle handle, TElOwnHandle ownHandle);

		TPlKOI8T();

		static TPlKOI8T CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLKOI8T */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSKOI8T */

