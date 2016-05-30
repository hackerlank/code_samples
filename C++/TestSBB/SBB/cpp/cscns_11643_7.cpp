#include "cscns_11643_7.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCNS_11643_7

SB_INLINE TClassHandle TPlCNS_11643_7::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCNS_11643_7_ClassType(&OutResult));
	return OutResult;
}

TPlCNS_11643_7::TPlCNS_11643_7(TPlCNS_11643_7Handle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlCNS_11643_7::TPlCNS_11643_7() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCNS_11643_7_Create(&_Handle));
}

TPlCNS_11643_7 TPlCNS_11643_7::CreateForFinalize()
{
	TPlCNS_11643_7Handle _Handle;
	SBCheckError(TPlCNS_11643_7_CreateForFinalize(&_Handle));
	return TPlCNS_11643_7(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCNS_11643_7 */

};	/* namespace SecureBlackbox */

