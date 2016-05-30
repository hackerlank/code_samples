#include "cscns_11643_3.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCNS_11643_3

SB_INLINE TClassHandle TPlCNS_11643_3::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCNS_11643_3_ClassType(&OutResult));
	return OutResult;
}

TPlCNS_11643_3::TPlCNS_11643_3(TPlCNS_11643_3Handle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlCNS_11643_3::TPlCNS_11643_3() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCNS_11643_3_Create(&_Handle));
}

TPlCNS_11643_3 TPlCNS_11643_3::CreateForFinalize()
{
	TPlCNS_11643_3Handle _Handle;
	SBCheckError(TPlCNS_11643_3_CreateForFinalize(&_Handle));
	return TPlCNS_11643_3(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCNS_11643_3 */

};	/* namespace SecureBlackbox */

