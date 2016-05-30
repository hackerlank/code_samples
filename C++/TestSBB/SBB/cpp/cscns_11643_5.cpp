#include "cscns_11643_5.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCNS_11643_5

SB_INLINE TClassHandle TPlCNS_11643_5::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCNS_11643_5_ClassType(&OutResult));
	return OutResult;
}

TPlCNS_11643_5::TPlCNS_11643_5(TPlCNS_11643_5Handle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlCNS_11643_5::TPlCNS_11643_5() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCNS_11643_5_Create(&_Handle));
}

TPlCNS_11643_5 TPlCNS_11643_5::CreateForFinalize()
{
	TPlCNS_11643_5Handle _Handle;
	SBCheckError(TPlCNS_11643_5_CreateForFinalize(&_Handle));
	return TPlCNS_11643_5(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCNS_11643_5 */

};	/* namespace SecureBlackbox */

