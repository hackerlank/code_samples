#ifndef __INC_CSKOI8U
#define __INC_CSKOI8U

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
typedef TElClassHandle TPlKOI8UHandle;

#ifdef SB_USE_CLASS_TPLKOI8U
SB_IMPORT uint32_t SB_APIENTRY TPlKOI8U_GetCategory(TPlKOI8UHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlKOI8U_GetDescription(TPlKOI8UHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlKOI8U_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlKOI8U_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlKOI8U_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLKOI8U */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlKOI8U;

#ifdef SB_USE_CLASS_TPLKOI8U
class TPlKOI8U: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlKOI8U)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlKOI8U(TPlKOI8UHandle handle, TElOwnHandle ownHandle);

		TPlKOI8U();

		static TPlKOI8U CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLKOI8U */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSKOI8U */

