#include "csgbk.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLGBKDATA

SB_INLINE TClassHandle TPlGBKData::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlGBKData_ClassType(&OutResult));
	return OutResult;
}

TPlGBKData::TPlGBKData(TPlGBKDataHandle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlGBKData::TPlGBKData() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlGBKData_Create(&_Handle));
}

TPlGBKData TPlGBKData::CreateForFinalize()
{
	TPlGBKDataHandle _Handle;
	SBCheckError(TPlGBKData_CreateForFinalize(&_Handle));
	return TPlGBKData(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLGBKDATA */

};	/* namespace SecureBlackbox */

