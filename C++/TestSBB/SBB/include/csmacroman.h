#ifndef __INC_CSMACROMAN
#define __INC_CSMACROMAN

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
typedef TElClassHandle TPlMacRomanHandle;

#ifdef SB_USE_CLASS_TPLMACROMAN
SB_IMPORT uint32_t SB_APIENTRY TPlMacRoman_GetCategory(TPlMacRomanHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacRoman_GetDescription(TPlMacRomanHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacRoman_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacRoman_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacRoman_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLMACROMAN */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlMacRoman;

#ifdef SB_USE_CLASS_TPLMACROMAN
class TPlMacRoman: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlMacRoman)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlMacRoman(TPlMacRomanHandle handle, TElOwnHandle ownHandle);

		TPlMacRoman();

		static TPlMacRoman CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLMACROMAN */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSMACROMAN */

