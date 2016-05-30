#include "csjis_0212.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLJIS_0212

SB_INLINE TClassHandle TPlJIS_0212::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlJIS_0212_ClassType(&OutResult));
	return OutResult;
}

TPlJIS_0212::TPlJIS_0212(TPlJIS_0212Handle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlJIS_0212::TPlJIS_0212() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlJIS_0212_Create(&_Handle));
}

TPlJIS_0212 TPlJIS_0212::CreateForFinalize()
{
	TPlJIS_0212Handle _Handle;
	SBCheckError(TPlJIS_0212_CreateForFinalize(&_Handle));
	return TPlJIS_0212(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLJIS_0212 */

};	/* namespace SecureBlackbox */

