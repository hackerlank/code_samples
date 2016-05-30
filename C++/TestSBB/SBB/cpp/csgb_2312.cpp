#include "csgb_2312.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLGB_2312

SB_INLINE TClassHandle TPlGB_2312::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlGB_2312_ClassType(&OutResult));
	return OutResult;
}

TPlGB_2312::TPlGB_2312(TPlGB_2312Handle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlGB_2312::TPlGB_2312() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlGB_2312_Create(&_Handle));
}

TPlGB_2312 TPlGB_2312::CreateForFinalize()
{
	TPlGB_2312Handle _Handle;
	SBCheckError(TPlGB_2312_CreateForFinalize(&_Handle));
	return TPlGB_2312(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLGB_2312 */

};	/* namespace SecureBlackbox */

