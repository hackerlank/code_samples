#ifndef __INC_SBDCXMLENC
#define __INC_SBDCXMLENC

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbstreams.h"
#include "sbxmlcore.h"
#include "sbdcenc.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElDCXMLEncodingHandle;

#ifdef SB_USE_CLASS_TELDCXMLENCODING
SB_IMPORT uint32_t SB_APIENTRY TElDCXMLEncoding_Encode(TElDCXMLEncodingHandle _Handle, TElDCNodeHandle Root, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElDCXMLEncoding_Decode(TElDCXMLEncodingHandle _Handle, TElDCNodeHandle Root, TStreamHandle Stream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElDCXMLEncoding_GetName(TElDCXMLEncodingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCXMLEncoding_GetDescription(TElDCXMLEncodingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCXMLEncoding_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELDCXMLENCODING */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElDCXMLEncoding;

#ifdef SB_USE_CLASS_TELDCXMLENCODING
class TElDCXMLEncoding: public TElDCEncoding
{
	private:
		SB_DISABLE_COPY(TElDCXMLEncoding)
	public:
#ifdef SB_USE_CLASSES_TELDCNODE_AND_TSTREAM
		virtual void Encode(TElDCNode &Root, TStream &Stream);

		virtual void Encode(TElDCNode *Root, TStream *Stream);
#endif /* SB_USE_CLASSES_TELDCNODE_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELDCNODE_AND_TSTREAM
		virtual void Decode(TElDCNode &Root, TStream &Stream, int32_t Count);

		virtual void Decode(TElDCNode *Root, TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASSES_TELDCNODE_AND_TSTREAM */

		virtual void GetName(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		TElDCXMLEncoding(TElDCXMLEncodingHandle handle, TElOwnHandle ownHandle);

		TElDCXMLEncoding();

};
#endif /* SB_USE_CLASS_TELDCXMLENCODING */

#ifdef SB_USE_GLOBAL_PROCS_DCXMLENC

#ifdef SB_USE_CLASS_TELDCENCODING
TElDCEncodingHandle DCXMLEncoding();
#endif /* SB_USE_CLASS_TELDCENCODING */

#endif /* SB_USE_GLOBAL_PROCS_DCXMLENC */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_DCXMLENC
SB_IMPORT uint32_t SB_APIENTRY SBDCXMLEnc_DCXMLEncoding(TElDCEncodingHandle * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_DCXMLENC */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDCXMLENC */

