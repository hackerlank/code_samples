#ifndef __INC_CSGEOSTD8
#define __INC_CSGEOSTD8

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
typedef TElClassHandle TPlGEOSTD8Handle;

#ifdef SB_USE_CLASS_TPLGEOSTD8
SB_IMPORT uint32_t SB_APIENTRY TPlGEOSTD8_GetCategory(TPlGEOSTD8Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGEOSTD8_GetDescription(TPlGEOSTD8Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGEOSTD8_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGEOSTD8_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGEOSTD8_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLGEOSTD8 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlGEOSTD8;

#ifdef SB_USE_CLASS_TPLGEOSTD8
class TPlGEOSTD8: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlGEOSTD8)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlGEOSTD8(TPlGEOSTD8Handle handle, TElOwnHandle ownHandle);

		TPlGEOSTD8();

		static TPlGEOSTD8 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLGEOSTD8 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSGEOSTD8 */

