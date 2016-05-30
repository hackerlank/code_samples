#ifndef __INC_CSATARIST
#define __INC_CSATARIST

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
typedef TElClassHandle TPlAtariSTHandle;

#ifdef SB_USE_CLASS_TPLATARIST
SB_IMPORT uint32_t SB_APIENTRY TPlAtariST_GetCategory(TPlAtariSTHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlAtariST_GetDescription(TPlAtariSTHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlAtariST_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlAtariST_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlAtariST_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLATARIST */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlAtariST;

#ifdef SB_USE_CLASS_TPLATARIST
class TPlAtariST: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlAtariST)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlAtariST(TPlAtariSTHandle handle, TElOwnHandle ownHandle);

		TPlAtariST();

		static TPlAtariST CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLATARIST */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSATARIST */

