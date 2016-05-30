#include "cscns_11643_f.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCNS_11643_F

SB_INLINE TClassHandle TPlCNS_11643_F::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCNS_11643_F_ClassType(&OutResult));
	return OutResult;
}

TPlCNS_11643_F::TPlCNS_11643_F(TPlCNS_11643_FHandle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlCNS_11643_F::TPlCNS_11643_F() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCNS_11643_F_Create(&_Handle));
}

TPlCNS_11643_F TPlCNS_11643_F::CreateForFinalize()
{
	TPlCNS_11643_FHandle _Handle;
	SBCheckError(TPlCNS_11643_F_CreateForFinalize(&_Handle));
	return TPlCNS_11643_F(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCNS_11643_F */

};	/* namespace SecureBlackbox */

