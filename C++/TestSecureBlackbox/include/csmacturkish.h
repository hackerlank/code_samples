#ifndef __INC_CSMACTURKISH
#define __INC_CSMACTURKISH

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
typedef TElClassHandle TPlMacTurkishHandle;

#ifdef SB_USE_CLASS_TPLMACTURKISH
SB_IMPORT uint32_t SB_APIENTRY TPlMacTurkish_GetCategory(TPlMacTurkishHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacTurkish_GetDescription(TPlMacTurkishHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacTurkish_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacTurkish_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacTurkish_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLMACTURKISH */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlMacTurkish;

#ifdef SB_USE_CLASS_TPLMACTURKISH
class TPlMacTurkish: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlMacTurkish)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlMacTurkish(TPlMacTurkishHandle handle, TElOwnHandle ownHandle);

		TPlMacTurkish();

		static TPlMacTurkish CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLMACTURKISH */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSMACTURKISH */

