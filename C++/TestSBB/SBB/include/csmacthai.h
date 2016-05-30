#ifndef __INC_CSMACTHAI
#define __INC_CSMACTHAI

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
typedef TElClassHandle TPlMacThaiHandle;

#ifdef SB_USE_CLASS_TPLMACTHAI
SB_IMPORT uint32_t SB_APIENTRY TPlMacThai_GetCategory(TPlMacThaiHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacThai_GetDescription(TPlMacThaiHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacThai_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacThai_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacThai_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLMACTHAI */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlMacThai;

#ifdef SB_USE_CLASS_TPLMACTHAI
class TPlMacThai: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlMacThai)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlMacThai(TPlMacThaiHandle handle, TElOwnHandle ownHandle);

		TPlMacThai();

		static TPlMacThai CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLMACTHAI */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSMACTHAI */

