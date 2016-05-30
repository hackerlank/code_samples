#ifndef __INC_CSGEORGIANACADEMY
#define __INC_CSGEORGIANACADEMY

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
typedef TElClassHandle TPlGeorgianAcademyHandle;

#ifdef SB_USE_CLASS_TPLGEORGIANACADEMY
SB_IMPORT uint32_t SB_APIENTRY TPlGeorgianAcademy_GetCategory(TPlGeorgianAcademyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGeorgianAcademy_GetDescription(TPlGeorgianAcademyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGeorgianAcademy_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGeorgianAcademy_Create(TPlTableCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGeorgianAcademy_CreateForFinalize(TPlTableCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLGEORGIANACADEMY */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlGeorgianAcademy;

#ifdef SB_USE_CLASS_TPLGEORGIANACADEMY
class TPlGeorgianAcademy: public TPlASCII
{
	private:
		SB_DISABLE_COPY(TPlGeorgianAcademy)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlGeorgianAcademy(TPlGeorgianAcademyHandle handle, TElOwnHandle ownHandle);

		TPlGeorgianAcademy();

		static TPlGeorgianAcademy CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLGEORGIANACADEMY */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_CSGEORGIANACADEMY */

