#include "sbgssapi.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT

TElGSSCustomContext::TElGSSCustomContext(TElGSSCustomContextHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElGSSCustomContext::TElGSSCustomContext() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGSSCustomContext_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMNAME

TElGSSCustomName::TElGSSCustomName(TElGSSCustomNameHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElGSSCustomName::TElGSSCustomName() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGSSCustomName_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM

bool TElGSSBaseMechanism::Initialize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGSSBaseMechanism_Initialize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE uint32_t TElGSSBaseMechanism::GetLastMajorStatus()
{
	uint32_t OutResult;
	SBCheckError(TElGSSBaseMechanism_GetLastMajorStatus(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElGSSBaseMechanism::GetLastMinorStatus()
{
	uint32_t OutResult;
	SBCheckError(TElGSSBaseMechanism_GetLastMinorStatus(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
uint32_t TElGSSBaseMechanism::AcquireCred(const std::vector<uint8_t> &MechOID, TElGSSCustomContext &Ctx)
{
	uint32_t OutResult;
	TElClassHandle hCtx = Ctx.getHandle();
	SBCheckError(TElGSSBaseMechanism_AcquireCred(_Handle, SB_STD_VECTOR_FRONT_ADR(MechOID), (int32_t)MechOID.size(), &hCtx, &OutResult));
	Ctx.updateHandle(hCtx);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME
uint32_t TElGSSBaseMechanism::AcceptSecContext(TElGSSCustomContext &Ctx, TElGSSCustomName &SourceName, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken)
{
	uint32_t OutResult;
	int32_t szOutputToken = (int32_t)OutputToken.size();
	uint32_t _err = TElGSSBaseMechanism_AcceptSecContext(_Handle, Ctx.getHandle(), SourceName.getHandle(), SB_STD_VECTOR_FRONT_ADR(InputToken), (int32_t)InputToken.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutputToken.resize(szOutputToken);
		SBCheckError(SBGetLastReturnBuffer(436118123, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken));
	}
	else
		SBCheckError(_err);

	OutputToken.resize(szOutputToken);
	return OutResult;
}

uint32_t TElGSSBaseMechanism::AcceptSecContext(TElGSSCustomContext *Ctx, TElGSSCustomName *SourceName, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken)
{
	uint32_t OutResult;
	int32_t szOutputToken = (int32_t)OutputToken.size();
	uint32_t _err = TElGSSBaseMechanism_AcceptSecContext(_Handle, (Ctx != NULL) ? Ctx->getHandle() : SB_NULL_HANDLE, (SourceName != NULL) ? SourceName->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(InputToken), (int32_t)InputToken.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutputToken.resize(szOutputToken);
		SBCheckError(SBGetLastReturnBuffer(436118123, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken));
	}
	else
		SBCheckError(_err);

	OutputToken.resize(szOutputToken);
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME
uint32_t TElGSSBaseMechanism::InitSecContext(TElGSSCustomContext &Ctx, TElGSSCustomName &TargetName, bool DelegateCred, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken)
{
	uint32_t OutResult;
	int32_t szOutputToken = (int32_t)OutputToken.size();
	uint32_t _err = TElGSSBaseMechanism_InitSecContext(_Handle, Ctx.getHandle(), TargetName.getHandle(), (int8_t)DelegateCred, SB_STD_VECTOR_FRONT_ADR(InputToken), (int32_t)InputToken.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutputToken.resize(szOutputToken);
		SBCheckError(SBGetLastReturnBuffer(-906180115, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken));
	}
	else
		SBCheckError(_err);

	OutputToken.resize(szOutputToken);
	return OutResult;
}

uint32_t TElGSSBaseMechanism::InitSecContext(TElGSSCustomContext *Ctx, TElGSSCustomName *TargetName, bool DelegateCred, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken)
{
	uint32_t OutResult;
	int32_t szOutputToken = (int32_t)OutputToken.size();
	uint32_t _err = TElGSSBaseMechanism_InitSecContext(_Handle, (Ctx != NULL) ? Ctx->getHandle() : SB_NULL_HANDLE, (TargetName != NULL) ? TargetName->getHandle() : SB_NULL_HANDLE, (int8_t)DelegateCred, SB_STD_VECTOR_FRONT_ADR(InputToken), (int32_t)InputToken.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutputToken.resize(szOutputToken);
		SBCheckError(SBGetLastReturnBuffer(-906180115, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken));
	}
	else
		SBCheckError(_err);

	OutputToken.resize(szOutputToken);
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
uint32_t TElGSSBaseMechanism::ReleaseContext(TElGSSCustomContext &Ctx)
{
	uint32_t OutResult;
	TElClassHandle hCtx = Ctx.getHandle();
	SBCheckError(TElGSSBaseMechanism_ReleaseContext(_Handle, &hCtx, &OutResult));
	Ctx.updateHandle(hCtx);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMNAME
uint32_t TElGSSBaseMechanism::ImportName(const std::vector<uint8_t> &MechOID, const std::string &InputName, TElGSSCustomName &OutputName)
{
	uint32_t OutResult;
	TElClassHandle hOutputName = OutputName.getHandle();
	SBCheckError(TElGSSBaseMechanism_ImportName(_Handle, SB_STD_VECTOR_FRONT_ADR(MechOID), (int32_t)MechOID.size(), InputName.data(), (int32_t)InputName.length(), &hOutputName, &OutResult));
	OutputName.updateHandle(hOutputName);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMNAME
uint32_t TElGSSBaseMechanism::ReleaseName(TElGSSCustomName &Name)
{
	uint32_t OutResult;
	TElClassHandle hName = Name.getHandle();
	SBCheckError(TElGSSBaseMechanism_ReleaseName(_Handle, &hName, &OutResult));
	Name.updateHandle(hName);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
uint32_t TElGSSBaseMechanism::GetMIC(TElGSSCustomContext &Ctx, const std::vector<uint8_t> &MessageBuffer, std::vector<uint8_t> &MessageToken)
{
	uint32_t OutResult;
	int32_t szMessageToken = (int32_t)MessageToken.size();
	uint32_t _err = TElGSSBaseMechanism_GetMIC(_Handle, Ctx.getHandle(), SB_STD_VECTOR_FRONT_ADR(MessageBuffer), (int32_t)MessageBuffer.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MessageToken), &szMessageToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		MessageToken.resize(szMessageToken);
		SBCheckError(SBGetLastReturnBuffer(1248629905, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MessageToken), &szMessageToken));
	}
	else
		SBCheckError(_err);

	MessageToken.resize(szMessageToken);
	return OutResult;
}

uint32_t TElGSSBaseMechanism::GetMIC(TElGSSCustomContext *Ctx, const std::vector<uint8_t> &MessageBuffer, std::vector<uint8_t> &MessageToken)
{
	uint32_t OutResult;
	int32_t szMessageToken = (int32_t)MessageToken.size();
	uint32_t _err = TElGSSBaseMechanism_GetMIC(_Handle, (Ctx != NULL) ? Ctx->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(MessageBuffer), (int32_t)MessageBuffer.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MessageToken), &szMessageToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		MessageToken.resize(szMessageToken);
		SBCheckError(SBGetLastReturnBuffer(1248629905, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MessageToken), &szMessageToken));
	}
	else
		SBCheckError(_err);

	MessageToken.resize(szMessageToken);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
SB_INLINE uint32_t TElGSSBaseMechanism::VerifyMIC(TElGSSCustomContext &Ctx, const std::vector<uint8_t> &MessageBuffer, const std::vector<uint8_t> &MessageToken)
{
	uint32_t OutResult;
	SBCheckError(TElGSSBaseMechanism_VerifyMIC(_Handle, Ctx.getHandle(), SB_STD_VECTOR_FRONT_ADR(MessageBuffer), (int32_t)MessageBuffer.size(), SB_STD_VECTOR_FRONT_ADR(MessageToken), (int32_t)MessageToken.size(), &OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElGSSBaseMechanism::VerifyMIC(TElGSSCustomContext *Ctx, const std::vector<uint8_t> &MessageBuffer, const std::vector<uint8_t> &MessageToken)
{
	uint32_t OutResult;
	SBCheckError(TElGSSBaseMechanism_VerifyMIC(_Handle, (Ctx != NULL) ? Ctx->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(MessageBuffer), (int32_t)MessageBuffer.size(), SB_STD_VECTOR_FRONT_ADR(MessageToken), (int32_t)MessageToken.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

bool TElGSSBaseMechanism::IsMechSupported(const std::vector<uint8_t> &OID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGSSBaseMechanism_IsMechSupported(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
bool TElGSSBaseMechanism::IsIntegrityAvailable(TElGSSCustomContext &Ctx)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGSSBaseMechanism_IsIntegrityAvailable(_Handle, Ctx.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGSSBaseMechanism::IsIntegrityAvailable(TElGSSCustomContext *Ctx)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGSSBaseMechanism_IsIntegrityAvailable(_Handle, (Ctx != NULL) ? Ctx->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
bool TElGSSBaseMechanism::IsMutualAvailable(TElGSSCustomContext &Ctx)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGSSBaseMechanism_IsMutualAvailable(_Handle, Ctx.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGSSBaseMechanism::IsMutualAvailable(TElGSSCustomContext *Ctx)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGSSBaseMechanism_IsMutualAvailable(_Handle, (Ctx != NULL) ? Ctx->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

void TElGSSBaseMechanism::GetMechOIDByHash(const std::vector<uint8_t> &Hash, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGSSBaseMechanism_GetMechOIDByHash(_Handle, SB_STD_VECTOR_FRONT_ADR(Hash), (int32_t)Hash.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(709836803, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElGSSBaseMechanism::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElGSSBaseMechanism_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElGSSBaseMechanism::get_Mechs(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGSSBaseMechanism_get_Mechs(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(400171714, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGSSBaseMechanism::get_OnError(TSBGSSErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElGSSBaseMechanism_get_OnError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElGSSBaseMechanism::set_OnError(TSBGSSErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElGSSBaseMechanism_set_OnError(_Handle, pMethodValue, pDataValue));
}

TElGSSBaseMechanism::TElGSSBaseMechanism(TElGSSBaseMechanismHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElGSSBaseMechanism::TElGSSBaseMechanism() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGSSBaseMechanism_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */

#ifdef SB_USE_CLASS_TELGSSAPICONTEXT

TElGSSAPIContext::TElGSSAPIContext(TElGSSAPIContextHandle handle, TElOwnHandle ownHandle) : TElGSSCustomContext(handle, ownHandle)
{
}

TElGSSAPIContext::TElGSSAPIContext() : TElGSSCustomContext(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGSSAPIContext_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGSSAPICONTEXT */

#ifdef SB_USE_CLASS_TELGSSAPINAME

TElGSSAPIName::TElGSSAPIName(TElGSSAPINameHandle handle, TElOwnHandle ownHandle) : TElGSSCustomName(handle, ownHandle)
{
}

TElGSSAPIName::TElGSSAPIName() : TElGSSCustomName(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGSSAPIName_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGSSAPINAME */

#ifdef SB_USE_CLASS_TELGSSAPIMECHANISM

bool TElGSSAPIMechanism::Initialize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGSSAPIMechanism_Initialize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
uint32_t TElGSSAPIMechanism::AcquireCred(const std::vector<uint8_t> &MechOID, TElGSSCustomContext &Ctx)
{
	uint32_t OutResult;
	TElClassHandle hCtx = Ctx.getHandle();
	SBCheckError(TElGSSAPIMechanism_AcquireCred(_Handle, SB_STD_VECTOR_FRONT_ADR(MechOID), (int32_t)MechOID.size(), &hCtx, &OutResult));
	Ctx.updateHandle(hCtx);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME
uint32_t TElGSSAPIMechanism::AcceptSecContext(TElGSSCustomContext &Ctx, TElGSSCustomName &SourceName, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken)
{
	uint32_t OutResult;
	int32_t szOutputToken = (int32_t)OutputToken.size();
	uint32_t _err = TElGSSAPIMechanism_AcceptSecContext(_Handle, Ctx.getHandle(), SourceName.getHandle(), SB_STD_VECTOR_FRONT_ADR(InputToken), (int32_t)InputToken.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutputToken.resize(szOutputToken);
		SBCheckError(SBGetLastReturnBuffer(-314634640, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken));
	}
	else
		SBCheckError(_err);

	OutputToken.resize(szOutputToken);
	return OutResult;
}

uint32_t TElGSSAPIMechanism::AcceptSecContext(TElGSSCustomContext *Ctx, TElGSSCustomName *SourceName, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken)
{
	uint32_t OutResult;
	int32_t szOutputToken = (int32_t)OutputToken.size();
	uint32_t _err = TElGSSAPIMechanism_AcceptSecContext(_Handle, (Ctx != NULL) ? Ctx->getHandle() : SB_NULL_HANDLE, (SourceName != NULL) ? SourceName->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(InputToken), (int32_t)InputToken.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutputToken.resize(szOutputToken);
		SBCheckError(SBGetLastReturnBuffer(-314634640, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken));
	}
	else
		SBCheckError(_err);

	OutputToken.resize(szOutputToken);
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME
uint32_t TElGSSAPIMechanism::InitSecContext(TElGSSCustomContext &Ctx, TElGSSCustomName &TargetName, bool DelegateCred, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken)
{
	uint32_t OutResult;
	int32_t szOutputToken = (int32_t)OutputToken.size();
	uint32_t _err = TElGSSAPIMechanism_InitSecContext(_Handle, Ctx.getHandle(), TargetName.getHandle(), (int8_t)DelegateCred, SB_STD_VECTOR_FRONT_ADR(InputToken), (int32_t)InputToken.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutputToken.resize(szOutputToken);
		SBCheckError(SBGetLastReturnBuffer(1286171553, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken));
	}
	else
		SBCheckError(_err);

	OutputToken.resize(szOutputToken);
	return OutResult;
}

uint32_t TElGSSAPIMechanism::InitSecContext(TElGSSCustomContext *Ctx, TElGSSCustomName *TargetName, bool DelegateCred, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken)
{
	uint32_t OutResult;
	int32_t szOutputToken = (int32_t)OutputToken.size();
	uint32_t _err = TElGSSAPIMechanism_InitSecContext(_Handle, (Ctx != NULL) ? Ctx->getHandle() : SB_NULL_HANDLE, (TargetName != NULL) ? TargetName->getHandle() : SB_NULL_HANDLE, (int8_t)DelegateCred, SB_STD_VECTOR_FRONT_ADR(InputToken), (int32_t)InputToken.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutputToken.resize(szOutputToken);
		SBCheckError(SBGetLastReturnBuffer(1286171553, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken));
	}
	else
		SBCheckError(_err);

	OutputToken.resize(szOutputToken);
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
uint32_t TElGSSAPIMechanism::ReleaseContext(TElGSSCustomContext &Ctx)
{
	uint32_t OutResult;
	TElClassHandle hCtx = Ctx.getHandle();
	SBCheckError(TElGSSAPIMechanism_ReleaseContext(_Handle, &hCtx, &OutResult));
	Ctx.updateHandle(hCtx);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMNAME
uint32_t TElGSSAPIMechanism::ImportName(const std::vector<uint8_t> &MechOID, const std::string &InputName, TElGSSCustomName &OutputName)
{
	uint32_t OutResult;
	TElClassHandle hOutputName = OutputName.getHandle();
	SBCheckError(TElGSSAPIMechanism_ImportName(_Handle, SB_STD_VECTOR_FRONT_ADR(MechOID), (int32_t)MechOID.size(), InputName.data(), (int32_t)InputName.length(), &hOutputName, &OutResult));
	OutputName.updateHandle(hOutputName);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMNAME
uint32_t TElGSSAPIMechanism::ReleaseName(TElGSSCustomName &Name)
{
	uint32_t OutResult;
	TElClassHandle hName = Name.getHandle();
	SBCheckError(TElGSSAPIMechanism_ReleaseName(_Handle, &hName, &OutResult));
	Name.updateHandle(hName);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
uint32_t TElGSSAPIMechanism::GetMIC(TElGSSCustomContext &Ctx, const std::vector<uint8_t> &MessageBuffer, std::vector<uint8_t> &MessageToken)
{
	uint32_t OutResult;
	int32_t szMessageToken = (int32_t)MessageToken.size();
	uint32_t _err = TElGSSAPIMechanism_GetMIC(_Handle, Ctx.getHandle(), SB_STD_VECTOR_FRONT_ADR(MessageBuffer), (int32_t)MessageBuffer.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MessageToken), &szMessageToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		MessageToken.resize(szMessageToken);
		SBCheckError(SBGetLastReturnBuffer(45356553, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MessageToken), &szMessageToken));
	}
	else
		SBCheckError(_err);

	MessageToken.resize(szMessageToken);
	return OutResult;
}

uint32_t TElGSSAPIMechanism::GetMIC(TElGSSCustomContext *Ctx, const std::vector<uint8_t> &MessageBuffer, std::vector<uint8_t> &MessageToken)
{
	uint32_t OutResult;
	int32_t szMessageToken = (int32_t)MessageToken.size();
	uint32_t _err = TElGSSAPIMechanism_GetMIC(_Handle, (Ctx != NULL) ? Ctx->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(MessageBuffer), (int32_t)MessageBuffer.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MessageToken), &szMessageToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		MessageToken.resize(szMessageToken);
		SBCheckError(SBGetLastReturnBuffer(45356553, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MessageToken), &szMessageToken));
	}
	else
		SBCheckError(_err);

	MessageToken.resize(szMessageToken);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
SB_INLINE uint32_t TElGSSAPIMechanism::VerifyMIC(TElGSSCustomContext &Ctx, const std::vector<uint8_t> &MessageBuffer, const std::vector<uint8_t> &MessageToken)
{
	uint32_t OutResult;
	SBCheckError(TElGSSAPIMechanism_VerifyMIC(_Handle, Ctx.getHandle(), SB_STD_VECTOR_FRONT_ADR(MessageBuffer), (int32_t)MessageBuffer.size(), SB_STD_VECTOR_FRONT_ADR(MessageToken), (int32_t)MessageToken.size(), &OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElGSSAPIMechanism::VerifyMIC(TElGSSCustomContext *Ctx, const std::vector<uint8_t> &MessageBuffer, const std::vector<uint8_t> &MessageToken)
{
	uint32_t OutResult;
	SBCheckError(TElGSSAPIMechanism_VerifyMIC(_Handle, (Ctx != NULL) ? Ctx->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(MessageBuffer), (int32_t)MessageBuffer.size(), SB_STD_VECTOR_FRONT_ADR(MessageToken), (int32_t)MessageToken.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

void TElGSSAPIMechanism::get_LibraryName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGSSAPIMechanism_get_LibraryName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(576732245, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGSSAPIMechanism::set_LibraryName(const std::string &Value)
{
	SBCheckError(TElGSSAPIMechanism_set_LibraryName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElGSSAPIMechanism::get_KRB5CredentialCacheName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGSSAPIMechanism_get_KRB5CredentialCacheName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(133530866, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGSSAPIMechanism::set_KRB5CredentialCacheName(const std::string &Value)
{
	SBCheckError(TElGSSAPIMechanism_set_KRB5CredentialCacheName(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE uint32_t TElGSSAPIMechanism::get_RequestFlags()
{
	uint32_t OutResult;
	SBCheckError(TElGSSAPIMechanism_get_RequestFlags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGSSAPIMechanism::set_RequestFlags(uint32_t Value)
{
	SBCheckError(TElGSSAPIMechanism_set_RequestFlags(_Handle, Value));
}

SB_INLINE gss_accept_sec_context TElGSSAPIMechanism::get_accept_sec_context()
{
	gss_accept_sec_context OutResult;
	SBCheckError(TElGSSAPIMechanism_get_accept_sec_context(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGSSAPIMechanism::set_accept_sec_context(gss_accept_sec_context Value)
{
	SBCheckError(TElGSSAPIMechanism_set_accept_sec_context(_Handle, Value));
}

SB_INLINE gss_acquire_cred TElGSSAPIMechanism::get_acquire_cred()
{
	gss_acquire_cred OutResult;
	SBCheckError(TElGSSAPIMechanism_get_acquire_cred(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGSSAPIMechanism::set_acquire_cred(gss_acquire_cred Value)
{
	SBCheckError(TElGSSAPIMechanism_set_acquire_cred(_Handle, Value));
}

SB_INLINE gss_delete_sec_context TElGSSAPIMechanism::get_delete_sec_context()
{
	gss_delete_sec_context OutResult;
	SBCheckError(TElGSSAPIMechanism_get_delete_sec_context(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGSSAPIMechanism::set_delete_sec_context(gss_delete_sec_context Value)
{
	SBCheckError(TElGSSAPIMechanism_set_delete_sec_context(_Handle, Value));
}

SB_INLINE gss_display_status TElGSSAPIMechanism::get_display_status()
{
	gss_display_status OutResult;
	SBCheckError(TElGSSAPIMechanism_get_display_status(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGSSAPIMechanism::set_display_status(gss_display_status Value)
{
	SBCheckError(TElGSSAPIMechanism_set_display_status(_Handle, Value));
}

SB_INLINE gss_get_mic TElGSSAPIMechanism::get_get_mic()
{
	gss_get_mic OutResult;
	SBCheckError(TElGSSAPIMechanism_get_get_mic(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGSSAPIMechanism::set_get_mic(gss_get_mic Value)
{
	SBCheckError(TElGSSAPIMechanism_set_get_mic(_Handle, Value));
}

SB_INLINE gss_indicate_mechs TElGSSAPIMechanism::get_indicate_mechs()
{
	gss_indicate_mechs OutResult;
	SBCheckError(TElGSSAPIMechanism_get_indicate_mechs(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGSSAPIMechanism::set_indicate_mechs(gss_indicate_mechs Value)
{
	SBCheckError(TElGSSAPIMechanism_set_indicate_mechs(_Handle, Value));
}

SB_INLINE gss_init_sec_context TElGSSAPIMechanism::get_init_sec_context()
{
	gss_init_sec_context OutResult;
	SBCheckError(TElGSSAPIMechanism_get_init_sec_context(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGSSAPIMechanism::set_init_sec_context(gss_init_sec_context Value)
{
	SBCheckError(TElGSSAPIMechanism_set_init_sec_context(_Handle, Value));
}

SB_INLINE gss_import_name TElGSSAPIMechanism::get_import_name()
{
	gss_import_name OutResult;
	SBCheckError(TElGSSAPIMechanism_get_import_name(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGSSAPIMechanism::set_import_name(gss_import_name Value)
{
	SBCheckError(TElGSSAPIMechanism_set_import_name(_Handle, Value));
}

SB_INLINE gss_krb5_ccache_name TElGSSAPIMechanism::get_krb5_ccache_name()
{
	gss_krb5_ccache_name OutResult;
	SBCheckError(TElGSSAPIMechanism_get_krb5_ccache_name(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGSSAPIMechanism::set_krb5_ccache_name(gss_krb5_ccache_name Value)
{
	SBCheckError(TElGSSAPIMechanism_set_krb5_ccache_name(_Handle, Value));
}

SB_INLINE gss_release_buffer TElGSSAPIMechanism::get_release_buffer()
{
	gss_release_buffer OutResult;
	SBCheckError(TElGSSAPIMechanism_get_release_buffer(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGSSAPIMechanism::set_release_buffer(gss_release_buffer Value)
{
	SBCheckError(TElGSSAPIMechanism_set_release_buffer(_Handle, Value));
}

SB_INLINE gss_release_cred TElGSSAPIMechanism::get_release_cred()
{
	gss_release_cred OutResult;
	SBCheckError(TElGSSAPIMechanism_get_release_cred(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGSSAPIMechanism::set_release_cred(gss_release_cred Value)
{
	SBCheckError(TElGSSAPIMechanism_set_release_cred(_Handle, Value));
}

SB_INLINE gss_release_name TElGSSAPIMechanism::get_release_name()
{
	gss_release_name OutResult;
	SBCheckError(TElGSSAPIMechanism_get_release_name(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGSSAPIMechanism::set_release_name(gss_release_name Value)
{
	SBCheckError(TElGSSAPIMechanism_set_release_name(_Handle, Value));
}

SB_INLINE gss_release_oid_set TElGSSAPIMechanism::get_release_oid_set()
{
	gss_release_oid_set OutResult;
	SBCheckError(TElGSSAPIMechanism_get_release_oid_set(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGSSAPIMechanism::set_release_oid_set(gss_release_oid_set Value)
{
	SBCheckError(TElGSSAPIMechanism_set_release_oid_set(_Handle, Value));
}

SB_INLINE gss_verify_mic TElGSSAPIMechanism::get_verify_mic()
{
	gss_verify_mic OutResult;
	SBCheckError(TElGSSAPIMechanism_get_verify_mic(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGSSAPIMechanism::set_verify_mic(gss_verify_mic Value)
{
	SBCheckError(TElGSSAPIMechanism_set_verify_mic(_Handle, Value));
}

TElGSSAPIMechanism::TElGSSAPIMechanism(TElGSSAPIMechanismHandle handle, TElOwnHandle ownHandle) : TElGSSBaseMechanism(handle, ownHandle)
{
}

TElGSSAPIMechanism::TElGSSAPIMechanism() : TElGSSBaseMechanism(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGSSAPIMechanism_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGSSAPIMECHANISM */

#ifdef SB_USE_CLASS_TELGSSMECHANISMCOLLECTION

bool TElGSSMechanismCollection::Initialize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGSSMechanismCollection_Initialize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TElGSSBaseMechanismHandle TElGSSMechanismCollection::GetMechByOID(const std::vector<uint8_t> &OID)
{
	TElGSSBaseMechanismHandle OutResult;
	SBCheckError(TElGSSMechanismCollection_GetMechByOID(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResult));
	return OutResult;
}

SB_INLINE void TElGSSMechanismCollection::RegisterMechanism(TElGSSBaseMechanism &Mech)
{
	SBCheckError(TElGSSMechanismCollection_RegisterMechanism(_Handle, Mech.getHandle()));
}

SB_INLINE void TElGSSMechanismCollection::RegisterMechanism(TElGSSBaseMechanism *Mech)
{
	SBCheckError(TElGSSMechanismCollection_RegisterMechanism(_Handle, (Mech != NULL) ? Mech->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElGSSMechanismCollection::UnregisterMechanism(TElGSSBaseMechanism &Mech)
{
	SBCheckError(TElGSSMechanismCollection_UnregisterMechanism(_Handle, Mech.getHandle()));
}

SB_INLINE void TElGSSMechanismCollection::UnregisterMechanism(TElGSSBaseMechanism *Mech)
{
	SBCheckError(TElGSSMechanismCollection_UnregisterMechanism(_Handle, (Mech != NULL) ? Mech->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
uint32_t TElGSSMechanismCollection::AcquireCred(const std::vector<uint8_t> &MechOID, TElGSSCustomContext &Ctx)
{
	uint32_t OutResult;
	TElClassHandle hCtx = Ctx.getHandle();
	SBCheckError(TElGSSMechanismCollection_AcquireCred(_Handle, SB_STD_VECTOR_FRONT_ADR(MechOID), (int32_t)MechOID.size(), &hCtx, &OutResult));
	Ctx.updateHandle(hCtx);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME
uint32_t TElGSSMechanismCollection::AcceptSecContext(TElGSSCustomContext &Ctx, TElGSSCustomName &SourceName, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken)
{
	uint32_t OutResult;
	int32_t szOutputToken = (int32_t)OutputToken.size();
	uint32_t _err = TElGSSMechanismCollection_AcceptSecContext(_Handle, Ctx.getHandle(), SourceName.getHandle(), SB_STD_VECTOR_FRONT_ADR(InputToken), (int32_t)InputToken.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutputToken.resize(szOutputToken);
		SBCheckError(SBGetLastReturnBuffer(697383276, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken));
	}
	else
		SBCheckError(_err);

	OutputToken.resize(szOutputToken);
	return OutResult;
}

uint32_t TElGSSMechanismCollection::AcceptSecContext(TElGSSCustomContext *Ctx, TElGSSCustomName *SourceName, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken)
{
	uint32_t OutResult;
	int32_t szOutputToken = (int32_t)OutputToken.size();
	uint32_t _err = TElGSSMechanismCollection_AcceptSecContext(_Handle, (Ctx != NULL) ? Ctx->getHandle() : SB_NULL_HANDLE, (SourceName != NULL) ? SourceName->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(InputToken), (int32_t)InputToken.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutputToken.resize(szOutputToken);
		SBCheckError(SBGetLastReturnBuffer(697383276, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken));
	}
	else
		SBCheckError(_err);

	OutputToken.resize(szOutputToken);
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME
uint32_t TElGSSMechanismCollection::InitSecContext(TElGSSCustomContext &Ctx, TElGSSCustomName &TargetName, bool DelegateCred, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken)
{
	uint32_t OutResult;
	int32_t szOutputToken = (int32_t)OutputToken.size();
	uint32_t _err = TElGSSMechanismCollection_InitSecContext(_Handle, Ctx.getHandle(), TargetName.getHandle(), (int8_t)DelegateCred, SB_STD_VECTOR_FRONT_ADR(InputToken), (int32_t)InputToken.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutputToken.resize(szOutputToken);
		SBCheckError(SBGetLastReturnBuffer(1876605781, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken));
	}
	else
		SBCheckError(_err);

	OutputToken.resize(szOutputToken);
	return OutResult;
}

uint32_t TElGSSMechanismCollection::InitSecContext(TElGSSCustomContext *Ctx, TElGSSCustomName *TargetName, bool DelegateCred, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken)
{
	uint32_t OutResult;
	int32_t szOutputToken = (int32_t)OutputToken.size();
	uint32_t _err = TElGSSMechanismCollection_InitSecContext(_Handle, (Ctx != NULL) ? Ctx->getHandle() : SB_NULL_HANDLE, (TargetName != NULL) ? TargetName->getHandle() : SB_NULL_HANDLE, (int8_t)DelegateCred, SB_STD_VECTOR_FRONT_ADR(InputToken), (int32_t)InputToken.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutputToken.resize(szOutputToken);
		SBCheckError(SBGetLastReturnBuffer(1876605781, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutputToken), &szOutputToken));
	}
	else
		SBCheckError(_err);

	OutputToken.resize(szOutputToken);
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
uint32_t TElGSSMechanismCollection::ReleaseContext(TElGSSCustomContext &Ctx)
{
	uint32_t OutResult;
	TElClassHandle hCtx = Ctx.getHandle();
	SBCheckError(TElGSSMechanismCollection_ReleaseContext(_Handle, &hCtx, &OutResult));
	Ctx.updateHandle(hCtx);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMNAME
uint32_t TElGSSMechanismCollection::ImportName(const std::vector<uint8_t> &MechOID, const std::string &InputName, TElGSSCustomName &OutputName)
{
	uint32_t OutResult;
	TElClassHandle hOutputName = OutputName.getHandle();
	SBCheckError(TElGSSMechanismCollection_ImportName(_Handle, SB_STD_VECTOR_FRONT_ADR(MechOID), (int32_t)MechOID.size(), InputName.data(), (int32_t)InputName.length(), &hOutputName, &OutResult));
	OutputName.updateHandle(hOutputName);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMNAME
uint32_t TElGSSMechanismCollection::ReleaseName(TElGSSCustomName &Name)
{
	uint32_t OutResult;
	TElClassHandle hName = Name.getHandle();
	SBCheckError(TElGSSMechanismCollection_ReleaseName(_Handle, &hName, &OutResult));
	Name.updateHandle(hName);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
uint32_t TElGSSMechanismCollection::GetMIC(TElGSSCustomContext &Ctx, const std::vector<uint8_t> &MessageBuffer, std::vector<uint8_t> &MessageToken)
{
	uint32_t OutResult;
	int32_t szMessageToken = (int32_t)MessageToken.size();
	uint32_t _err = TElGSSMechanismCollection_GetMIC(_Handle, Ctx.getHandle(), SB_STD_VECTOR_FRONT_ADR(MessageBuffer), (int32_t)MessageBuffer.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MessageToken), &szMessageToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		MessageToken.resize(szMessageToken);
		SBCheckError(SBGetLastReturnBuffer(806168295, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MessageToken), &szMessageToken));
	}
	else
		SBCheckError(_err);

	MessageToken.resize(szMessageToken);
	return OutResult;
}

uint32_t TElGSSMechanismCollection::GetMIC(TElGSSCustomContext *Ctx, const std::vector<uint8_t> &MessageBuffer, std::vector<uint8_t> &MessageToken)
{
	uint32_t OutResult;
	int32_t szMessageToken = (int32_t)MessageToken.size();
	uint32_t _err = TElGSSMechanismCollection_GetMIC(_Handle, (Ctx != NULL) ? Ctx->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(MessageBuffer), (int32_t)MessageBuffer.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MessageToken), &szMessageToken, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		MessageToken.resize(szMessageToken);
		SBCheckError(SBGetLastReturnBuffer(806168295, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(MessageToken), &szMessageToken));
	}
	else
		SBCheckError(_err);

	MessageToken.resize(szMessageToken);
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
SB_INLINE uint32_t TElGSSMechanismCollection::VerifyMIC(TElGSSCustomContext &Ctx, const std::vector<uint8_t> &MessageBuffer, const std::vector<uint8_t> &MessageToken)
{
	uint32_t OutResult;
	SBCheckError(TElGSSMechanismCollection_VerifyMIC(_Handle, Ctx.getHandle(), SB_STD_VECTOR_FRONT_ADR(MessageBuffer), (int32_t)MessageBuffer.size(), SB_STD_VECTOR_FRONT_ADR(MessageToken), (int32_t)MessageToken.size(), &OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElGSSMechanismCollection::VerifyMIC(TElGSSCustomContext *Ctx, const std::vector<uint8_t> &MessageBuffer, const std::vector<uint8_t> &MessageToken)
{
	uint32_t OutResult;
	SBCheckError(TElGSSMechanismCollection_VerifyMIC(_Handle, (Ctx != NULL) ? Ctx->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(MessageBuffer), (int32_t)MessageBuffer.size(), SB_STD_VECTOR_FRONT_ADR(MessageToken), (int32_t)MessageToken.size(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

bool TElGSSMechanismCollection::IsMechSupported(const std::vector<uint8_t> &OID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGSSMechanismCollection_IsMechSupported(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
bool TElGSSMechanismCollection::IsIntegrityAvailable(TElGSSCustomContext &Ctx)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGSSMechanismCollection_IsIntegrityAvailable(_Handle, Ctx.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGSSMechanismCollection::IsIntegrityAvailable(TElGSSCustomContext *Ctx)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGSSMechanismCollection_IsIntegrityAvailable(_Handle, (Ctx != NULL) ? Ctx->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

TElGSSMechanismCollection::TElGSSMechanismCollection(TElGSSMechanismCollectionHandle handle, TElOwnHandle ownHandle) : TElGSSBaseMechanism(handle, ownHandle)
{
}

TElGSSMechanismCollection::TElGSSMechanismCollection() : TElGSSBaseMechanism(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGSSMechanismCollection_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELGSSMECHANISMCOLLECTION */

};	/* namespace SecureBlackbox */

