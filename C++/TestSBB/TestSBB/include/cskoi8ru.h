#ifndef __INC_CSKOI8RU
#define __INC_CSKOI8RU

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
typedef TElClassHandle TPlKOI8RUHandle;

#ifdef SB_USE_CLASS_TPLKOI8RU
SB_IMPORT uint32_t SB_APIENTRY TPlKOI8RU_GetCategory(TPlKOI8RUHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlKOI8RU_GetDescription(TPlKOI8RUHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlKOI8RU_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlKOI8RU_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlKOI8RU_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLKOI8RU */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlKOI8RU;

#ifdef SB_USE_CLASS_TPLKOI8RU
class TPlKOI8RU: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlKOI8RU)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlKOI8RU(TPlKOI8RUHandle handle, TElOwnHandle ownHandle);

		TPlKOI8RU();

		static TPlKOI8RU CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLKOI8RU */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSKOI8RU */

