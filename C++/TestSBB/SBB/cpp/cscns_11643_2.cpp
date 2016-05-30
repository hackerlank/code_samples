#include "cscns_11643_2.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCNS_11643_2

SB_INLINE TClassHandle TPlCNS_11643_2::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCNS_11643_2_ClassType(&OutResult));
	return OutResult;
}

TPlCNS_11643_2::TPlCNS_11643_2(TPlCNS_11643_2Handle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlCNS_11643_2::TPlCNS_11643_2() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCNS_11643_2_Create(&_Handle));
}

TPlCNS_11643_2 TPlCNS_11643_2::CreateForFinalize()
{
	TPlCNS_11643_2Handle _Handle;
	SBCheckError(TPlCNS_11643_2_CreateForFinalize(&_Handle));
	return TPlCNS_11643_2(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCNS_11643_2 */

};	/* namespace SecureBlackbox */

