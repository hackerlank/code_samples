#include "csjis_0201.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLJIS_0201

SB_INLINE TClassHandle TPlJIS_0201::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlJIS_0201_ClassType(&OutResult));
	return OutResult;
}

TPlJIS_0201::TPlJIS_0201(TPlJIS_0201Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlJIS_0201::TPlJIS_0201() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlJIS_0201_Create(&_Handle));
}

TPlJIS_0201 TPlJIS_0201::CreateForFinalize()
{
	TPlJIS_0201Handle _Handle;
	SBCheckError(TPlJIS_0201_CreateForFinalize(&_Handle));
	return TPlJIS_0201(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLJIS_0201 */

};	/* namespace SecureBlackbox */

