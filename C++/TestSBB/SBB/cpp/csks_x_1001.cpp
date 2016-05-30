#include "csks_x_1001.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLKS_X_1001

SB_INLINE TClassHandle TPlKS_X_1001::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlKS_X_1001_ClassType(&OutResult));
	return OutResult;
}

TPlKS_X_1001::TPlKS_X_1001(TPlKS_X_1001Handle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlKS_X_1001::TPlKS_X_1001() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlKS_X_1001_Create(&_Handle));
}

TPlKS_X_1001 TPlKS_X_1001::CreateForFinalize()
{
	TPlKS_X_1001Handle _Handle;
	SBCheckError(TPlKS_X_1001_CreateForFinalize(&_Handle));
	return TPlKS_X_1001(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLKS_X_1001 */

};	/* namespace SecureBlackbox */

