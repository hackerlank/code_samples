#include "cscns_11643_1.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCNS_11643_1

SB_INLINE TClassHandle TPlCNS_11643_1::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCNS_11643_1_ClassType(&OutResult));
	return OutResult;
}

TPlCNS_11643_1::TPlCNS_11643_1(TPlCNS_11643_1Handle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlCNS_11643_1::TPlCNS_11643_1() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCNS_11643_1_Create(&_Handle));
}

TPlCNS_11643_1 TPlCNS_11643_1::CreateForFinalize()
{
	TPlCNS_11643_1Handle _Handle;
	SBCheckError(TPlCNS_11643_1_CreateForFinalize(&_Handle));
	return TPlCNS_11643_1(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCNS_11643_1 */

};	/* namespace SecureBlackbox */

