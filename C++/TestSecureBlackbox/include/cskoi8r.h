#ifndef __INC_CSKOI8R
#define __INC_CSKOI8R

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
typedef TElClassHandle TPlKOI8RHandle;

#ifdef SB_USE_CLASS_TPLKOI8R
SB_IMPORT uint32_t SB_APIENTRY TPlKOI8R_GetCategory(TPlKOI8RHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlKOI8R_GetDescription(TPlKOI8RHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlKOI8R_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlKOI8R_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlKOI8R_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLKOI8R */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlKOI8R;

#ifdef SB_USE_CLASS_TPLKOI8R
class TPlKOI8R: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlKOI8R)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlKOI8R(TPlKOI8RHandle handle, TElOwnHandle ownHandle);

		TPlKOI8R();

		static TPlKOI8R CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLKOI8R */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSKOI8R */

