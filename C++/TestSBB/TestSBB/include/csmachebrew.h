#ifndef __INC_CSMACHEBREW
#define __INC_CSMACHEBREW

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
typedef TElClassHandle TPlMacHebrewHandle;

#ifdef SB_USE_CLASS_TPLMACHEBREW
SB_IMPORT uint32_t SB_APIENTRY TPlMacHebrew_GetCategory(TPlMacHebrewHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacHebrew_GetDescription(TPlMacHebrewHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacHebrew_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacHebrew_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacHebrew_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLMACHEBREW */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlMacHebrew;

#ifdef SB_USE_CLASS_TPLMACHEBREW
class TPlMacHebrew: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlMacHebrew)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlMacHebrew(TPlMacHebrewHandle handle, TElOwnHandle ownHandle);

		TPlMacHebrew();

		static TPlMacHebrew CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLMACHEBREW */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSMACHEBREW */

