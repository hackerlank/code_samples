#include "cshkscs.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLHKSCSDATA

SB_INLINE TClassHandle TPlHKSCSData::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlHKSCSData_ClassType(&OutResult));
	return OutResult;
}

TPlHKSCSData::TPlHKSCSData(TPlHKSCSDataHandle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlHKSCSData::TPlHKSCSData() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlHKSCSData_Create(&_Handle));
}

TPlHKSCSData TPlHKSCSData::CreateForFinalize()
{
	TPlHKSCSDataHandle _Handle;
	SBCheckError(TPlHKSCSData_CreateForFinalize(&_Handle));
	return TPlHKSCSData(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLHKSCSDATA */

};	/* namespace SecureBlackbox */

