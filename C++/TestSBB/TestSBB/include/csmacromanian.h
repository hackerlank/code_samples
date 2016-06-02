#ifndef __INC_CSMACROMANIAN
#define __INC_CSMACROMANIAN

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
typedef TElClassHandle TPlMacRomanianHandle;

#ifdef SB_USE_CLASS_TPLMACROMANIAN
SB_IMPORT uint32_t SB_APIENTRY TPlMacRomanian_GetCategory(TPlMacRomanianHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacRomanian_GetDescription(TPlMacRomanianHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacRomanian_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacRomanian_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacRomanian_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLMACROMANIAN */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlMacRomanian;

#ifdef SB_USE_CLASS_TPLMACROMANIAN
class TPlMacRomanian: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlMacRomanian)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlMacRomanian(TPlMacRomanianHandle handle, TElOwnHandle ownHandle);

		TPlMacRomanian();

		static TPlMacRomanian CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLMACROMANIAN */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSMACROMANIAN */

