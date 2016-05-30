#include "sbdefs.h"
#ifdef SB_WINDOWS
#include "sbgsswinauth.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELGSSWINCONTEXT

TElGSSWinContext::TElGSSWinContext(TElGSSWinContextHandle handle, TElOwnHandle ownHandle) : TElGSSCustomContext(handle, ownHandle)
{
}

TElGSSWinContext::TElGSSWinContext() : TElGSSCustomContext(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGSSWinContext_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGSSWINCONTEXT */

#ifdef SB_USE_CLASS_TELGSSWINNAME

TElGSSWinName::TElGSSWinName(TElGSSWinNameHandle handle, TElOwnHandle ownHandle) : TElGSSCustomName(handle, ownHandle)
{
}

TElGSSWinName::TElGSSWinName() : TElGSSCustomName(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGSSWinName_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGSSWINNAME */

#ifdef SB_USE_CLASS_TELGSSWINAUTHMECHANISM

bool TElGSSWinAuthMechanism::Initialize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGSSWinAuthMechanism_Initialize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
uint32_t TElGSSWinAuthMechanism::AcquireCred(const std::vector<uint8_t> &MechOID, TElGSSCustomContext &Ctx)
{
	uint32_t OutResult;
	TElClassHandle hCtx = Ctx.getHandle();
	SBCheckError(TElGSSWinAuthMechanism_AcquireCred(_Handle, SB_STD_VECTOR_FRONT_ADR(MechOID), (int32_t)MechOID.size(), &hCtx, &OutResult));
	Ctx.updateHandle(hCtx);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME
uint32_t TElGSSWinAuthMechanism::AcceptSecContext(TElGSSCustomContext &Ctx, TElGSSCustomName &SourceName, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken)
{
	uint32_t OutResult;
	int32_t szOutputToken = (int32_t)OutputToken.size();
	uint32_t _err = TElGSSWinAuthMechanism_AcceptSecContext(_Handle, Ctx.getHandle(), SourceName.getHandle(), SB_STD_VECTOR_FRONT_ADR(InputToken), (int32_t)InputToken.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutputToken.resize(szOutputToken);
		SBCheckError(SBGetLastReturnBuffer(-1048824200, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken));
	}
	else
		SBCheckError(_err);

	OutputToken.resize(szOutputToken);
	return OutResult;
}

uint32_t TElGSSWinAuthMechanism::AcceptSecContext(TElGSSCustomContext *Ctx, TElGSSCustomName *SourceName, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken)
{
	uint32_t OutResult;
	int32_t szOutputToken = (int32_t)OutputToken.size();
	uint32_t _err = TElGSSWinAuthMechanism_AcceptSecContext(_Handle, (Ctx != NULL) ? Ctx->getHandle() : SB_NULL_HANDLE, (SourceName != NULL) ? SourceName->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(InputToken), (int32_t)InputToken.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutputToken.resize(szOutputToken);
		SBCheckError(SBGetLastReturnBuffer(-1048824200, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken));
	}
	else
		SBCheckError(_err);

	OutputToken.resize(szOutputToken);
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME
uint32_t TElGSSWinAuthMechanism::InitSecContext(TElGSSCustomContext &Ctx, TElGSSCustomName &TargetName, bool DelegateCred, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken)
{
	uint32_t OutResult;
	int32_t szOutputToken = (int32_t)OutputToken.size();
	uint32_t _err = TElGSSWinAuthMechanism_InitSecContext(_Handle, Ctx.getHandle(), TargetName.getHandle(), (int8_t)DelegateCred, SB_STD_VECTOR_FRONT_ADR(InputToken), (int32_t)InputToken.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutputToken.resize(szOutputToken);
		SBCheckError(SBGetLastReturnBuffer(-384277698, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken));
	}
	else
		SBCheckError(_err);

	OutputToken.resize(szOutputToken);
	return OutResult;
}

uint32_t TElGSSWinAuthMechanism::InitSecContext(TElGSSCustomContext *Ctx, TElGSSCustomName *TargetName, bool DelegateCred, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken)
{
	uint32_t OutResult;
	int32_t szOutputToken = (int32_t)OutputToken.size();
	uint32_t _err = TElGSSWinAuthMechanism_InitSecContext(_Handle, (Ctx != NULL) ? Ctx->getHandle() : SB_NULL_HANDLE, (TargetName != NULL) ? TargetName->getHandle() : SB_NULL_HANDLE, (int8_t)DelegateCred, SB_STD_VECTOR_FRONT_ADR(InputToken), (int32_t)InputToken.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutputToken.resize(szOutputToken);
		SBCheckError(SBGetLastReturnBuffer(-384277698, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken));
	}
	else
		SBCheckError(_err);

	OutputToken.resize(szOutputToken);
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
uint32_t TElGSSWinAuthMechanism::ReleaseContext(TElGSSCustomContext &Ctx)
{
	uint32_t OutResult;
	TElClassHandle hCtx = Ctx.getHandle();
	SBCheckError(TElGSSWinAuthMechanism_ReleaseContext(_Handle, &hCtx, &OutResult));
	Ctx.updateHandle(hCtx);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMNAME
uint32_t TElGSSWinAuthMechanism::ImportName(const std::vector<uint8_t> &MechOID, const std::string &InputName, TElGSSCustomName &OutputName)
{
	uint32_t OutResult;
	TElClassHandle hOutputName = OutputName.getHandle();
	SBCheckError(TElGSSWinAuthMechanism_ImportName(_Handle, SB_STD_VECTOR_FRONT_ADR(MechOID), (int32_t)MechOID.size(), InputName.data(), (int32_t)InputName.length(), &hOutputName, &OutResult));
	OutputName.updateHandle(hOutputName);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMNAME
uint32_t TElGSSWinAuthMechanism::ReleaseName(TElGSSCustomName &Name)
{
	uint32_t OutResult;
	TElClassHandle hName = Name.getHandle();
	SBCheckError(TElGSSWinAuthMechanism_ReleaseName(_Handle, &hName, &OutResult));
	Name.updateHandle(hName);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
uint32_t TElGSSWinAuthMechanism::GetMIC(TElGSSCustomContext &Ctx, const std::vector<uint8_t> &MessageBuffer, std::vector<uint8_t> &MessageToken)
{
	uint32_t OutResult;
	int32_t szMessageToken = (int32_t)MessageToken.size();
	uint32_t _err = TElGSSWinAuthMechanism_GetMIC(_Handle, Ctx.getHandle(), SB_STD_VECTOR_FRONT_ADR(MessageBuffer), (int32_t)MessageBuffer.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MessageToken), &szMessageToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		MessageToken.resize(szMessageToken);
		SBCheckError(SBGetLastReturnBuffer(-601380314, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MessageToken), &szMessageToken));
	}
	else
		SBCheckError(_err);

	MessageToken.resize(szMessageToken);
	return OutResult;
}

uint32_t TElGSSWinAuthMechanism::GetMIC(TElGSSCustomContext *Ctx, const std::vector<uint8_t> &MessageBuffer, std::vector<uint8_t> &MessageToken)
{
	uint32_t OutResult;
	int32_t szMessageToken = (int32_t)MessageToken.size();
	uint32_t _err = TElGSSWinAuthMechanism_GetMIC(_Handle, (Ctx != NULL) ? Ctx->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(MessageBuffer), (int32_t)MessageBuffer.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MessageToken), &szMessageToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		MessageToken.resize(szMessageToken);
		SBCheckError(SBGetLastReturnBuffer(-601380314, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MessageToken), &szMessageToken));
	}
	else
		SBCheckError(_err);

	MessageToken.resize(szMessageToken);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
SB_INLINE uint32_t TElGSSWinAuthMechanism::VerifyMIC(TElGSSCustomContext &Ctx, const std::vector<uint8_t> &MessageBuffer, const std::vector<uint8_t> &MessageToken)
{
	uint32_t OutResult;
	SBCheckError(TElGSSWinAuthMechanism_VerifyMIC(_Handle, Ctx.getHandle(), SB_STD_VECTOR_FRONT_ADR(MessageBuffer), (int32_t)MessageBuffer.size(), SB_STD_VECTOR_FRONT_ADR(MessageToken), (int32_t)MessageToken.size(), &OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElGSSWinAuthMechanism::VerifyMIC(TElGSSCustomContext *Ctx, const std::vector<uint8_t> &MessageBuffer, const std::vector<uint8_t> &MessageToken)
{
	uint32_t OutResult;
	SBCheckError(TElGSSWinAuthMechanism_VerifyMIC(_Handle, (Ctx != NULL) ? Ctx->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(MessageBuffer), (int32_t)MessageBuffer.size(), SB_STD_VECTOR_FRONT_ADR(MessageToken), (int32_t)MessageToken.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

TElGSSWinAuthProtocols TElGSSWinAuthMechanism::get_AuthProtocols()
{
	TElGSSWinAuthProtocolsRaw OutResultRaw = 0;
	SBCheckError(TElGSSWinAuthMechanism_get_AuthProtocols(_Handle, &OutResultRaw));
	return (TElGSSWinAuthProtocols)OutResultRaw;
}

SB_INLINE void TElGSSWinAuthMechanism::set_AuthProtocols(TElGSSWinAuthProtocols Value)
{
	SBCheckError(TElGSSWinAuthMechanism_set_AuthProtocols(_Handle, (TElGSSWinAuthProtocolsRaw)Value));
}

TElGSSWinAuthMechanism::TElGSSWinAuthMechanism(TElGSSWinAuthMechanismHandle handle, TElOwnHandle ownHandle) : TElGSSBaseMechanism(handle, ownHandle)
{
}

TElGSSWinAuthMechanism::TElGSSWinAuthMechanism() : TElGSSBaseMechanism(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGSSWinAuthMechanism_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGSSWINAUTHMECHANISM */

};	/* namespace SecureBlackbox */
#endif
