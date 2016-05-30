#ifndef __INC_SBSSHUTILS
#define __INC_SBSSHUTILS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_SSHUTILS

void WriteString(const std::vector<uint8_t> &S, bool AddZero, std::vector<uint8_t> &OutResult);

void WriteBitCount(void * P, int32_t Size, std::vector<uint8_t> &OutResult);

void ReadSSH2MPInt(void * P, int32_t Size, int32_t &HeaderSz, std::vector<uint8_t> &OutResult);

bool ReadBoolean(void * P, int32_t Size);

void ReadString(void * Buffer, int32_t Size, std::string &OutResult);

void ReadBuffer(void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult);

void ReadBuffer(const std::vector<uint8_t> &Buffer, int32_t AIndex, int32_t Size, std::vector<uint8_t> &OutResult);

void ReadSSH1MPInt(void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult);

uint32_t ReadLength(void * Buffer, int32_t Size);

uint32_t ReadLength(const std::vector<uint8_t> &Buffer, int32_t AIndex, int32_t Size);

uint16_t ReadUINT16(void * Buffer, int32_t Size);

int64_t ReadUINT64(void * Buffer, int32_t Size);

void WriteSSH2MPInt(const std::vector<uint8_t> &P, int32_t Size, std::vector<uint8_t> &OutResult);

void SBSSHUtils_WriteBoolean(bool B, std::vector<uint8_t> &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_SSHUTILS */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_SSHUTILS
SB_IMPORT uint32_t SB_APIENTRY SBSSHUtils_WriteString(const uint8_t pS[], int32_t szS, int8_t AddZero, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSHUtils_WriteBitCount(void * P, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSHUtils_ReadSSH2MPInt(void * P, int32_t Size, int32_t * HeaderSz, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSHUtils_ReadBoolean(void * P, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSHUtils_ReadString(void * Buffer, int32_t Size, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSHUtils_ReadBuffer(void * Buffer, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSHUtils_ReadBuffer_1(const uint8_t pBuffer[], int32_t szBuffer, int32_t AIndex, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSHUtils_ReadSSH1MPInt(void * Buffer, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSHUtils_ReadLength(void * Buffer, int32_t Size, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSHUtils_ReadLength_1(const uint8_t pBuffer[], int32_t szBuffer, int32_t AIndex, int32_t Size, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSHUtils_ReadUINT16(void * Buffer, int32_t Size, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSHUtils_ReadUINT64(void * Buffer, int32_t Size, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSHUtils_WriteSSH2MPInt(const uint8_t pP[], int32_t szP, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSHUtils_WriteBoolean(int8_t B, uint8_t pOutResult[], int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_SSHUTILS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSSHUTILS */

