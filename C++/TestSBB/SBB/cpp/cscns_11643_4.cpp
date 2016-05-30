#include "cscns_11643_4.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCNS_11643_4

SB_INLINE TClassHandle TPlCNS_11643_4::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCNS_11643_4_ClassType(&OutResult));
	return OutResult;
}

TPlCNS_11643_4::TPlCNS_11643_4(TPlCNS_11643_4Handle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlCNS_11643_4::TPlCNS_11643_4() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCNS_11643_4_Create(&_Handle));
}

TPlCNS_11643_4 TPlCNS_11643_4::CreateForFinalize()
{
	TPlCNS_11643_4Handle _Handle;
	SBCheckError(TPlCNS_11643_4_CreateForFinalize(&_Handle));
	return TPlCNS_11643_4(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCNS_11643_4 */

};	/* namespace SecureBlackbox */

