#ifndef __INC_CSHPROMAN8
#define __INC_CSHPROMAN8

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
typedef TElClassHandle TPlHPRoman8Handle;

#ifdef SB_USE_CLASS_TPLHPROMAN8
SB_IMPORT uint32_t SB_APIENTRY TPlHPRoman8_GetCategory(TPlHPRoman8Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlHPRoman8_GetDescription(TPlHPRoman8Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlHPRoman8_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlHPRoman8_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlHPRoman8_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLHPROMAN8 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlHPRoman8;

#ifdef SB_USE_CLASS_TPLHPROMAN8
class TPlHPRoman8: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlHPRoman8)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlHPRoman8(TPlHPRoman8Handle handle, TElOwnHandle ownHandle);

		TPlHPRoman8();

		static TPlHPRoman8 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLHPROMAN8 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSHPROMAN8 */

