#include "cscns_11643_6.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCNS_11643_6

SB_INLINE TClassHandle TPlCNS_11643_6::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCNS_11643_6_ClassType(&OutResult));
	return OutResult;
}

TPlCNS_11643_6::TPlCNS_11643_6(TPlCNS_11643_6Handle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlCNS_11643_6::TPlCNS_11643_6() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCNS_11643_6_Create(&_Handle));
}

TPlCNS_11643_6 TPlCNS_11643_6::CreateForFinalize()
{
	TPlCNS_11643_6Handle _Handle;
	SBCheckError(TPlCNS_11643_6_CreateForFinalize(&_Handle));
	return TPlCNS_11643_6(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCNS_11643_6 */

};	/* namespace SecureBlackbox */

