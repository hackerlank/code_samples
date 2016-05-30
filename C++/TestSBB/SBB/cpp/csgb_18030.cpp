#include "csgb_18030.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLGB_18030DATA

SB_INLINE TClassHandle TPlGB_18030Data::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlGB_18030Data_ClassType(&OutResult));
	return OutResult;
}

TPlGB_18030Data::TPlGB_18030Data(TPlGB_18030DataHandle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlGB_18030Data::TPlGB_18030Data() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlGB_18030Data_Create(&_Handle));
}

TPlGB_18030Data TPlGB_18030Data::CreateForFinalize()
{
	TPlGB_18030DataHandle _Handle;
	SBCheckError(TPlGB_18030Data_CreateForFinalize(&_Handle));
	return TPlGB_18030Data(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLGB_18030DATA */

};	/* namespace SecureBlackbox */

