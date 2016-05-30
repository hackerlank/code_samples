#include "sbdcxmlenc.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELDCXMLENCODING

#ifdef SB_USE_CLASSES_TELDCNODE_AND_TSTREAM
SB_INLINE void TElDCXMLEncoding::Encode(TElDCNode &Root, TStream &Stream)
{
	SBCheckError(TElDCXMLEncoding_Encode(_Handle, Root.getHandle(), Stream.getHandle()));
}

SB_INLINE void TElDCXMLEncoding::Encode(TElDCNode *Root, TStream *Stream)
{
	SBCheckError(TElDCXMLEncoding_Encode(_Handle, (Root != NULL) ? Root->getHandle() : SB_NULL_HANDLE, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELDCNODE_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELDCNODE_AND_TSTREAM
SB_INLINE void TElDCXMLEncoding::Decode(TElDCNode &Root, TStream &Stream, int32_t Count)
{
	SBCheckError(TElDCXMLEncoding_Decode(_Handle, Root.getHandle(), Stream.getHandle(), Count));
}

SB_INLINE void TElDCXMLEncoding::Decode(TElDCNode *Root, TStream *Stream, int32_t Count)
{
	SBCheckError(TElDCXMLEncoding_Decode(_Handle, (Root != NULL) ? Root->getHandle() : SB_NULL_HANDLE, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASSES_TELDCNODE_AND_TSTREAM */

void TElDCXMLEncoding::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDCXMLEncoding_GetName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(4086254, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDCXMLEncoding::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDCXMLEncoding_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(550083170, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElDCXMLEncoding::TElDCXMLEncoding(TElDCXMLEncodingHandle handle, TElOwnHandle ownHandle) : TElDCEncoding(handle, ownHandle)
{
}

TElDCXMLEncoding::TElDCXMLEncoding() : TElDCEncoding(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDCXMLEncoding_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDCXMLENCODING */

#ifdef SB_USE_GLOBAL_PROCS_DCXMLENC

#ifdef SB_USE_CLASS_TELDCENCODING
SB_INLINE TElDCEncodingHandle DCXMLEncoding()
{
	TElDCEncodingHandle OutResult;
	SBCheckError(SBDCXMLEnc_DCXMLEncoding(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDCENCODING */

#endif /* SB_USE_GLOBAL_PROCS_DCXMLENC */

};	/* namespace SecureBlackbox */

