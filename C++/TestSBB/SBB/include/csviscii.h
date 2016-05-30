#ifndef __INC_CSVISCII
#define __INC_CSVISCII

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
typedef TElClassHandle TPlVISCIIHandle;

#ifdef SB_USE_CLASS_TPLVISCII
SB_IMPORT uint32_t SB_APIENTRY TPlVISCII_GetCategory(TPlVISCIIHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlVISCII_GetDescription(TPlVISCIIHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlVISCII_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlVISCII_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlVISCII_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLVISCII */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlVISCII;

#ifdef SB_USE_CLASS_TPLVISCII
class TPlVISCII: public TPlTableCharset
{
	private:
		SB_DISABLE_COPY(TPlVISCII)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlVISCII(TPlVISCIIHandle handle, TElOwnHandle ownHandle);

		TPlVISCII();

		static TPlVISCII CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLVISCII */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSVISCII */

