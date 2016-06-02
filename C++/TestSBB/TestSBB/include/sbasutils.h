#ifndef __INC_SBASUTILS
#define __INC_SBASUTILS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstreams.h"
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

#ifdef SB_USE_GLOBAL_PROCS_ASUTILS

#ifdef SB_USE_CLASS_TSTREAM
int64_t SBASUtils_CopyStream(TStream &Source, TStream &Dest, int64_t Offset, int64_t Count, bool PreservePosition, TSBProgressEvent pMethodProgressEvent, void * pDataProgressEvent);
int64_t SBASUtils_CopyStream(TStream *Source, TStream *Dest, int64_t Offset, int64_t Count, bool PreservePosition, TSBProgressEvent pMethodProgressEvent, void * pDataProgressEvent);
#endif /* SB_USE_CLASS_TSTREAM */

void QuoteMessageID(const std::string &MessageID, std::string &OutResult);

#ifdef SB_USE_CLASS_TSTREAM
void WriteField(TStream &Stream, const std::string &Name, const std::string &Value);
void WriteField(TStream *Stream, const std::string &Name, const std::string &Value);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
void WriteLineA(TStream &Stream, const std::string &Line);
void WriteLineA(TStream *Stream, const std::string &Line);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
void WriteLine(TStream &Stream, const sb_u16string &Line);
void WriteLine(TStream *Stream, const sb_u16string &Line);
#ifdef SB_U16STRING_USED
void WriteLine(TStream &Stream, const std::wstring &Line);
void WriteLine(TStream *Stream, const std::wstring &Line);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TSTREAM */

#endif /* SB_USE_GLOBAL_PROCS_ASUTILS */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_ASUTILS
SB_IMPORT uint32_t SB_APIENTRY SBASUtils_CopyStream(TStreamHandle Source, TStreamHandle Dest, int64_t Offset, int64_t Count, int8_t PreservePosition, TSBProgressEvent pMethodProgressEvent, void * pDataProgressEvent, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASUtils_QuoteMessageID(const char * pcMessageID, int32_t szMessageID, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASUtils_WriteField(TStreamHandle Stream, const char * pcName, int32_t szName, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY SBASUtils_WriteLineA(TStreamHandle Stream, const char * pcLine, int32_t szLine);
SB_IMPORT uint32_t SB_APIENTRY SBASUtils_WriteLine(TStreamHandle Stream, const sb_char16_t * pcLine, int32_t szLine);
#endif /* SB_USE_GLOBAL_PROCS_ASUTILS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBASUTILS */

