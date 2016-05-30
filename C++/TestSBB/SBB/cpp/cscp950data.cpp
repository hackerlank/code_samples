#include "cscp950data.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCP950DATA

SB_INLINE TClassHandle TPlCP950Data::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP950Data_ClassType(&OutResult));
	return OutResult;
}

TPlCP950Data::TPlCP950Data(TPlCP950DataHandle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlCP950Data::TPlCP950Data() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP950Data_Create(&_Handle));
}

TPlCP950Data TPlCP950Data::CreateForFinalize()
{
	TPlCP950DataHandle _Handle;
	SBCheckError(TPlCP950Data_CreateForFinalize(&_Handle));
	return TPlCP950Data(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP950DATA */

};	/* namespace SecureBlackbox */

