#include "csjis_0208.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLJIS_0208

SB_INLINE TClassHandle TPlJIS_0208::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlJIS_0208_ClassType(&OutResult));
	return OutResult;
}

TPlJIS_0208::TPlJIS_0208(TPlJIS_0208Handle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlJIS_0208::TPlJIS_0208() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlJIS_0208_Create(&_Handle));
}

TPlJIS_0208 TPlJIS_0208::CreateForFinalize()
{
	TPlJIS_0208Handle _Handle;
	SBCheckError(TPlJIS_0208_CreateForFinalize(&_Handle));
	return TPlJIS_0208(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLJIS_0208 */

};	/* namespace SecureBlackbox */

