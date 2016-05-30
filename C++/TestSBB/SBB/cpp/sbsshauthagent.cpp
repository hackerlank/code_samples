#include "sbdefs.h"
#ifndef WINCE
#include "sbsshauthagent.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSSHAUTHAGENT

void TElSSHAuthAgent::CalculateSignature(int32_t AKeyIndex, const std::vector<uint8_t> &ASessionID, const std::vector<uint8_t> &APacket, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHAuthAgent_CalculateSignature(_Handle, AKeyIndex, SB_STD_VECTOR_FRONT_ADR(ASessionID), (int32_t)ASessionID.size(), SB_STD_VECTOR_FRONT_ADR(APacket), (int32_t)APacket.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(423864573, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElSSHAuthAgent::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElSSHAuthAgent_get_Count(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHAuthAgent::get_SSH2Keys(int32_t AIndex, TElSSHAuthAgentSSH2Key &OutResult)
{
	SBCheckError(TElSSHAuthAgent_get_SSH2Keys(_Handle, AIndex, &OutResult));
}

TElSSHAuthAgent::TElSSHAuthAgent(TElSSHAuthAgentHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSSHAuthAgent::TElSSHAuthAgent() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHAuthAgent_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSSHAUTHAGENT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TELPAGEANTAUTHAGENT

TElPageantAuthAgent::TElPageantAuthAgent(TElPageantAuthAgentHandle handle, TElOwnHandle ownHandle) : TElSSHAuthAgent(handle, ownHandle)
{
}

TElPageantAuthAgent::TElPageantAuthAgent() : TElSSHAuthAgent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPageantAuthAgent_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPAGEANTAUTHAGENT */

#endif
#ifdef SB_USE_CLASS_TELOPENSSHAUTHAGENT

TElOpenSSHAuthAgent::TElOpenSSHAuthAgent(TElOpenSSHAuthAgentHandle handle, TElOwnHandle ownHandle) : TElSSHAuthAgent(handle, ownHandle)
{
}

TElOpenSSHAuthAgent::TElOpenSSHAuthAgent() : TElSSHAuthAgent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOpenSSHAuthAgent_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOPENSSHAUTHAGENT */
#ifdef SB_WINDOWS

#ifdef SB_USE_GLOBAL_PROCS_SSHAUTHAGENT

bool PageantAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBSSHAuthAgent_PageantAvailable(&OutResultRaw));
	return (OutResultRaw != 0);
}

bool ParseAccessInfo(const std::string &AInfo, int32_t &Port, std::vector<uint8_t> &Magic)
{
	int32_t szMagic = (int32_t)Magic.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBSSHAuthAgent_ParseAccessInfo(AInfo.data(), (int32_t)AInfo.length(), &Port, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Magic), &szMagic, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Magic.resize(szMagic);
		SBCheckError(SBGetLastReturnBuffer(2113152331, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Magic), &szMagic));
	}
	else
		SBCheckError(_err);

	Magic.resize(szMagic);
	return (OutResultRaw != 0);
}

#endif /* SB_USE_GLOBAL_PROCS_SSHAUTHAGENT */
#endif

};	/* namespace SecureBlackbox */
#endif
