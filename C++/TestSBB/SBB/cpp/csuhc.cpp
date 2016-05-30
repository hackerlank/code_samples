#include "csuhc.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLUHC

SB_INLINE TClassHandle TPlUHC::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlUHC_ClassType(&OutResult));
	return OutResult;
}

TPlUHC::TPlUHC(TPlUHCHandle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlUHC::TPlUHC() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlUHC_Create(&_Handle));
}

TPlUHC TPlUHC::CreateForFinalize()
{
	TPlUHCHandle _Handle;
	SBCheckError(TPlUHC_CreateForFinalize(&_Handle));
	return TPlUHC(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLUHC */

};	/* namespace SecureBlackbox */

