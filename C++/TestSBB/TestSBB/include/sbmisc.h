#define SB_WINDOWS

#ifdef LINUX
#  undef SB_WINDOWS
#endif

#ifdef MACOS
#  undef SB_WINDOWS
#endif

#ifndef __INC_SBMISC
#define __INC_SBMISC

#if _MSC_VER > 1000
#  pragma once
#endif

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstreams.h"

#ifdef __cplusplus

#include <iostream>

namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif

// File mode
#if defined(LINUX) || defined(MACOS) || defined(SB_IOS) || defined(CPU64)
// build with FPC
#  define filemodeCreate	0xff00
#else
// build with Delphi
#  define filemodeCreate	0xffff
#endif

#define filemodeOpenRead	0
#define filemodeOpenWrite	1
#define filemodeOpenReadWrite 	2

#define filemodeShareDenyNone   0x0040
#define filemodeShareDenyRead	0x0030
#define filemodeShareDenyWrite	0x0020
#define filemodeShareExclusive	0x0010

#define fmOpenRead		filemodeOpenRead
#define fmOpenWrite		filemodeOpenWrite
#define fmOpenReadWrite 	filemodeOpenReadWrite

#define fmShareDenyNone		filemodeShareDenyNone
#define fmShareDenyRead	 	filemodeShareDenyRead
#define fmShareDenyWrite	filemodeShareDenyWrite
#define fmShareExclusive	filemodeShareExclusive

// Seek origin
#define soFromBeginning	0
#define soFromCurrent	1
#define soFromEnd	2

#ifdef __cplusplus
}	/* extern "C" */
#endif

#ifdef __cplusplus

int32_t SB_APIENTRY CallbackIStreamReadFunc(void * buffer, int32_t count, std::istream &stream);

int32_t SB_APIENTRY CallbackOStreamWriteFunc(void * buffer, int32_t count, std::ostream &stream);

int64_t SB_APIENTRY CallbackIStreamSeekFunc(int64_t offset, uint16_t origin, std::istream &stream);
 
int64_t SB_APIENTRY CallbackOStreamSeekFunc(int64_t offset, uint16_t origin, std::ostream &stream);

int64_t SB_APIENTRY CallbackIOStreamSeekFunc(int64_t offset, uint16_t origin, std::iostream &stream);

#ifdef SB_USE_CLASS_TSTREAM
class TElCallbackStream : public TStream
{
	public:
		TElCallbackStream(TElCallbackStreamHandle handle, TElOwnHandle ownHandle);

		TElCallbackStream(std::iostream &stream);

		TElCallbackStream(std::ostream &stream);

		TElCallbackStream(std::istream &stream);

		TElCallbackStream(void * data, TSBCallbackStreamReadFunc readFunc, TSBCallbackStreamWriteFunc writeFunc, TSBCallbackStreamSeekFunc seekFunc);
};
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
typedef TStringList TElStringList;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#endif

#endif	/* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#endif  /* __INC_SBMISC */
