#ifndef __INC_SBSSHAUTHAGENT
#define __INC_SBSSHAUTHAGENT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#ifndef WINCE
#include "sbsocket.h"
#include "sbstrutils.h"
#include "sbtypes.h"
#include "sbstreams.h"
#include "sbutils.h"
#include "sbconstants.h"
#endif

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifndef WINCE
typedef TElClassHandle TElSSHAuthAgentHandle;

#ifdef SB_WINDOWS
typedef TElClassHandle TElPageantAuthAgentHandle;

#endif
typedef TElClassHandle TElOpenSSHAuthAgentHandle;

#pragma pack(4)
typedef struct 
{
	void * AlgName;
	void * KeyBlob;
	void * Comment;
} TElSSHAuthAgentSSH2Key;

#ifdef SB_USE_CLASS_TELSSHAUTHAGENT
SB_IMPORT uint32_t SB_APIENTRY TElSSHAuthAgent_CalculateSignature(TElSSHAuthAgentHandle _Handle, int32_t AKeyIndex, const uint8_t pASessionID[], int32_t szASessionID, const uint8_t pAPacket[], int32_t szAPacket, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHAuthAgent_get_Count(TElSSHAuthAgentHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHAuthAgent_get_SSH2Keys(TElSSHAuthAgentHandle _Handle, int32_t AIndex, TElSSHAuthAgentSSH2Key * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHAuthAgent_Create(TElSSHAuthAgentHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHAUTHAGENT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TELPAGEANTAUTHAGENT
SB_IMPORT uint32_t SB_APIENTRY TElPageantAuthAgent_Create(TElSSHAuthAgentHandle * OutResult);
#endif /* SB_USE_CLASS_TELPAGEANTAUTHAGENT */

#endif
#ifdef SB_USE_CLASS_TELOPENSSHAUTHAGENT
SB_IMPORT uint32_t SB_APIENTRY TElOpenSSHAuthAgent_Create(TElSSHAuthAgentHandle * OutResult);
#endif /* SB_USE_CLASS_TELOPENSSHAUTHAGENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSSHAuthAgent;
#ifdef SB_WINDOWS
class TElPageantAuthAgent;
#endif
class TElOpenSSHAuthAgent;

#ifdef SB_USE_CLASS_TELSSHAUTHAGENT
class TElSSHAuthAgent: public TObject
{
	private:
		SB_DISABLE_COPY(TElSSHAuthAgent)
	public:
		void CalculateSignature(int32_t AKeyIndex, const std::vector<uint8_t> &ASessionID, const std::vector<uint8_t> &APacket, std::vector<uint8_t> &OutResult);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElSSHAuthAgent, Count);

		virtual void get_SSH2Keys(int32_t AIndex, TElSSHAuthAgentSSH2Key &OutResult);

		TElSSHAuthAgent(TElSSHAuthAgentHandle handle, TElOwnHandle ownHandle);

		TElSSHAuthAgent();

};
#endif /* SB_USE_CLASS_TELSSHAUTHAGENT */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TELPAGEANTAUTHAGENT
class TElPageantAuthAgent: public TElSSHAuthAgent
{
	private:
		SB_DISABLE_COPY(TElPageantAuthAgent)
	public:
		TElPageantAuthAgent(TElPageantAuthAgentHandle handle, TElOwnHandle ownHandle);

		TElPageantAuthAgent();

};
#endif /* SB_USE_CLASS_TELPAGEANTAUTHAGENT */

#endif
#ifdef SB_USE_CLASS_TELOPENSSHAUTHAGENT
class TElOpenSSHAuthAgent: public TElSSHAuthAgent
{
	private:
		SB_DISABLE_COPY(TElOpenSSHAuthAgent)
	public:
		TElOpenSSHAuthAgent(TElOpenSSHAuthAgentHandle handle, TElOwnHandle ownHandle);

		TElOpenSSHAuthAgent();

};
#endif /* SB_USE_CLASS_TELOPENSSHAUTHAGENT */

#ifdef SB_WINDOWS
#ifdef SB_USE_GLOBAL_PROCS_SSHAUTHAGENT

bool PageantAvailable();

bool ParseAccessInfo(const std::string &AInfo, int32_t &Port, std::vector<uint8_t> &Magic);

#endif /* SB_USE_GLOBAL_PROCS_SSHAUTHAGENT */

#endif
#endif  /* __cplusplus */
#ifdef SB_WINDOWS

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_SSHAUTHAGENT
SB_IMPORT uint32_t SB_APIENTRY SBSSHAuthAgent_PageantAvailable(int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSHAuthAgent_ParseAccessInfo(const char * pcAInfo, int32_t szAInfo, int32_t * Port, uint8_t pMagic[], int32_t * szMagic, int8_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_SSHAUTHAGENT */

#endif
#endif
#ifdef SB_WINDOWS
#ifdef __cplusplus
};	/* extern "C" */
#endif
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSSHAUTHAGENT */
