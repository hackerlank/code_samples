#ifndef __INC_CSMACICELANDIC
#define __INC_CSMACICELANDIC

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
typedef TElClassHandle TPlMacIcelandicHandle;

#ifdef SB_USE_CLASS_TPLMACICELANDIC
SB_IMPORT uint32_t SB_APIENTRY TPlMacIcelandic_GetCategory(TPlMacIcelandicHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacIcelandic_GetDescription(TPlMacIcelandicHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacIcelandic_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacIcelandic_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlMacIcelandic_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLMACICELANDIC */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlMacIcelandic;

#ifdef SB_USE_CLASS_TPLMACICELANDIC
class TPlMacIcelandic: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlMacIcelandic)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlMacIcelandic(TPlMacIcelandicHandle handle, TElOwnHandle ownHandle);

		TPlMacIcelandic();

		static TPlMacIcelandic CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLMACICELANDIC */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSMACICELANDIC */

