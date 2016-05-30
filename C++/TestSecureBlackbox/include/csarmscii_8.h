#ifndef __INC_CSARMSCII_8
#define __INC_CSARMSCII_8

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
typedef TElClassHandle TPlARMSCII_8Handle;

#ifdef SB_USE_CLASS_TPLARMSCII_8
SB_IMPORT uint32_t SB_APIENTRY TPlARMSCII_8_GetCategory(TPlARMSCII_8Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlARMSCII_8_GetDescription(TPlARMSCII_8Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlARMSCII_8_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlARMSCII_8_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlARMSCII_8_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLARMSCII_8 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlARMSCII_8;

#ifdef SB_USE_CLASS_TPLARMSCII_8
class TPlARMSCII_8: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlARMSCII_8)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlARMSCII_8(TPlARMSCII_8Handle handle, TElOwnHandle ownHandle);

		TPlARMSCII_8();

		static TPlARMSCII_8 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLARMSCII_8 */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSARMSCII_8 */

