#include "csiso_ir_165.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLISO_IR_165DATA

SB_INLINE TClassHandle TPlISO_IR_165Data::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlISO_IR_165Data_ClassType(&OutResult));
	return OutResult;
}

TPlISO_IR_165Data::TPlISO_IR_165Data(TPlISO_IR_165DataHandle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlISO_IR_165Data::TPlISO_IR_165Data() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlISO_IR_165Data_Create(&_Handle));
}

TPlISO_IR_165Data TPlISO_IR_165Data::CreateForFinalize()
{
	TPlISO_IR_165DataHandle _Handle;
	SBCheckError(TPlISO_IR_165Data_CreateForFinalize(&_Handle));
	return TPlISO_IR_165Data(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLISO_IR_165DATA */

};	/* namespace SecureBlackbox */

