#include "csshiftjis.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLSHIFTJISDATA

SB_INLINE TClassHandle TPlShiftJISData::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlShiftJISData_ClassType(&OutResult));
	return OutResult;
}

TPlShiftJISData::TPlShiftJISData(TPlShiftJISDataHandle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlShiftJISData::TPlShiftJISData() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlShiftJISData_Create(&_Handle));
}

TPlShiftJISData TPlShiftJISData::CreateForFinalize()
{
	TPlShiftJISDataHandle _Handle;
	SBCheckError(TPlShiftJISData_CreateForFinalize(&_Handle));
	return TPlShiftJISData(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLSHIFTJISDATA */

};	/* namespace SecureBlackbox */

