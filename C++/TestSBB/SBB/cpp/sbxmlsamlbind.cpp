#include "sbxmlsamlbind.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSAMLBINDING

void TElSAMLBinding::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLBinding_GetName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1104305105, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBSAMLBindingType TElSAMLBinding::StrToBinding(const std::string &S)
{
	TSBSAMLBindingTypeRaw OutResultRaw = 0;
	SBCheckError(TElSAMLBinding_StrToBinding(S.data(), (int32_t)S.length(), &OutResultRaw));
	return (TSBSAMLBindingType)OutResultRaw;
}

TSBSAMLBindingType TElSAMLBinding::StrToBinding_Inst(const std::string &S)
{
	TSBSAMLBindingTypeRaw OutResultRaw = 0;
	SBCheckError(TElSAMLBinding_StrToBinding_1(_Handle, S.data(), (int32_t)S.length(), &OutResultRaw));
	return (TSBSAMLBindingType)OutResultRaw;
}

void TElSAMLBinding::BindingToStr(TSBSAMLBindingType V, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLBinding_BindingToStr((TSBSAMLBindingTypeRaw)V, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1083446915, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLBinding::BindingToStr_Inst(TSBSAMLBindingType V, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLBinding_BindingToStr_1(_Handle, (TSBSAMLBindingTypeRaw)V, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1083446915, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
void TElSAMLBinding::SaveRequest(TElXMLDOMDocument &Doc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLBinding_SaveRequest(_Handle, Doc.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1570792837, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLBinding::SaveRequest(TElXMLDOMDocument *Doc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLBinding_SaveRequest(_Handle, (Doc != NULL) ? Doc->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1570792837, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
void TElSAMLBinding::SaveResponse(TElXMLDOMDocument &Doc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLBinding_SaveResponse(_Handle, Doc.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2116410461, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLBinding::SaveResponse(TElXMLDOMDocument *Doc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLBinding_SaveResponse(_Handle, (Doc != NULL) ? Doc->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2116410461, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

void TElSAMLBinding::SaveArtifact(const std::vector<uint8_t> &Artifact, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLBinding_SaveArtifact(_Handle, SB_STD_VECTOR_FRONT_ADR(Artifact), (int32_t)Artifact.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(527490829, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLBinding::LoadRequest(const std::string &Request, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLBinding_LoadRequest(_Handle, Request.data(), (int32_t)Request.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-546517470, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLBinding::LoadResponse(const std::string &Response, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLBinding_LoadResponse(_Handle, Response.data(), (int32_t)Response.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1445840230, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLBinding::LoadArtifact(const std::string &Artifact, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSAMLBinding_LoadArtifact(_Handle, Artifact.data(), (int32_t)Artifact.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-450806483, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLBinding::get_OnXMLPrepared(TSBSAMLBindingXMLPreparedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLBinding_get_OnXMLPrepared(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLBinding::set_OnXMLPrepared(TSBSAMLBindingXMLPreparedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLBinding_set_OnXMLPrepared(_Handle, pMethodValue, pDataValue));
}

TElSAMLBinding::TElSAMLBinding(TElSAMLBindingHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSAMLBinding::TElSAMLBinding() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLBinding_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLBINDING */

#ifdef SB_USE_CLASS_TELSAMLSOAPBINDING

void TElSAMLSOAPBinding::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSOAPBinding_GetName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1110683299, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBSAMLDataType TElSAMLSOAPBinding::Detect(const std::string &Buf, std::string &Proto)
{
	int32_t szProto = (int32_t)Proto.length();
	TSBSAMLDataTypeRaw OutResultRaw = 0;
	uint32_t _err = TElSAMLSOAPBinding_Detect(Buf.data(), (int32_t)Buf.length(), (char *)Proto.data(), &szProto, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Proto.resize(szProto);
		SBCheckError(SBGetLastReturnStringA(231619823, 1, (char *)Proto.data(), &szProto));
	}
	else
		SBCheckError(_err);

	Proto.resize(szProto);
	return (TSBSAMLDataType)OutResultRaw;
}

TSBSAMLDataType TElSAMLSOAPBinding::Detect_Inst(const std::string &Buf, std::string &Proto)
{
	int32_t szProto = (int32_t)Proto.length();
	TSBSAMLDataTypeRaw OutResultRaw = 0;
	uint32_t _err = TElSAMLSOAPBinding_Detect_1(_Handle, Buf.data(), (int32_t)Buf.length(), (char *)Proto.data(), &szProto, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Proto.resize(szProto);
		SBCheckError(SBGetLastReturnStringA(231619823, 2, (char *)Proto.data(), &szProto));
	}
	else
		SBCheckError(_err);

	Proto.resize(szProto);
	return (TSBSAMLDataType)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
void TElSAMLSOAPBinding::SaveRequest(TElXMLDOMDocument &Doc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSOAPBinding_SaveRequest(_Handle, Doc.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(780124036, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLSOAPBinding::SaveRequest(TElXMLDOMDocument *Doc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSOAPBinding_SaveRequest(_Handle, (Doc != NULL) ? Doc->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(780124036, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
void TElSAMLSOAPBinding::SaveResponse(TElXMLDOMDocument &Doc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSOAPBinding_SaveResponse(_Handle, Doc.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1786079610, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLSOAPBinding::SaveResponse(TElXMLDOMDocument *Doc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSOAPBinding_SaveResponse(_Handle, (Doc != NULL) ? Doc->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1786079610, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

void TElSAMLSOAPBinding::LoadRequest(const std::string &Request, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSOAPBinding_LoadRequest(_Handle, Request.data(), (int32_t)Request.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1840551457, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLSOAPBinding::LoadResponse(const std::string &Response, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLSOAPBinding_LoadResponse(_Handle, Response.data(), (int32_t)Response.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(580573702, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBXMLSOAPVersion TElSAMLSOAPBinding::get_Version()
{
	TSBXMLSOAPVersionRaw OutResultRaw = 0;
	SBCheckError(TElSAMLSOAPBinding_get_Version(_Handle, &OutResultRaw));
	return (TSBXMLSOAPVersion)OutResultRaw;
}

SB_INLINE void TElSAMLSOAPBinding::set_Version(TSBXMLSOAPVersion Value)
{
	SBCheckError(TElSAMLSOAPBinding_set_Version(_Handle, (TSBXMLSOAPVersionRaw)Value));
}

SB_INLINE void TElSAMLSOAPBinding::get_OnBeforeEnvelope(TSBSAMLBeforeSOAPEnvelope &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLSOAPBinding_get_OnBeforeEnvelope(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLSOAPBinding::set_OnBeforeEnvelope(TSBSAMLBeforeSOAPEnvelope pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLSOAPBinding_set_OnBeforeEnvelope(_Handle, pMethodValue, pDataValue));
}

TElSAMLSOAPBinding::TElSAMLSOAPBinding(TElSAMLSOAPBindingHandle handle, TElOwnHandle ownHandle) : TElSAMLBinding(handle, ownHandle)
{
}

TElSAMLSOAPBinding::TElSAMLSOAPBinding() : TElSAMLBinding(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLSOAPBinding_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLSOAPBINDING */

#ifdef SB_USE_CLASS_TELSAMLCOMPRESSEDPROCESSOR

SB_INLINE void TElSAMLCompressedProcessor::Initialize(bool AsEncoder)
{
	SBCheckError(TElSAMLCompressedProcessor_Initialize(_Handle, (int8_t)AsEncoder));
}

SB_INLINE void TElSAMLCompressedProcessor::Reset()
{
	SBCheckError(TElSAMLCompressedProcessor_Reset(_Handle));
}

void TElSAMLCompressedProcessor::DecodeData(const std::vector<uint8_t> &Buffer, int32_t Position, int32_t Size, int32_t &Processed, bool &EndReached, std::vector<uint8_t> &OutResult)
{
	int8_t EndReachedRaw = (int8_t)EndReached;
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSAMLCompressedProcessor_DecodeData(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Position, Size, &Processed, &EndReachedRaw, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(183638031, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	EndReached = (EndReachedRaw != 0);
	OutResult.resize(szOutResult);
}

void TElSAMLCompressedProcessor::EncodeData(const std::vector<uint8_t> &Buffer, int32_t Position, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSAMLCompressedProcessor_EncodeData(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Position, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-669979419, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElSAMLCompressedProcessor::get_BytesEncoded()
{
	int64_t OutResult;
	SBCheckError(TElSAMLCompressedProcessor_get_BytesEncoded(_Handle, &OutResult));
	return OutResult;
}

bool TElSAMLCompressedProcessor::get_Deflated()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLCompressedProcessor_get_Deflated(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLCompressedProcessor::set_Deflated(bool Value)
{
	SBCheckError(TElSAMLCompressedProcessor_set_Deflated(_Handle, (int8_t)Value));
}

bool TElSAMLCompressedProcessor::get_Gzipped()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLCompressedProcessor_get_Gzipped(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLCompressedProcessor::set_Gzipped(bool Value)
{
	SBCheckError(TElSAMLCompressedProcessor_set_Gzipped(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElSAMLCompressedProcessor::get_CompressionLevel()
{
	int32_t OutResult;
	SBCheckError(TElSAMLCompressedProcessor_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLCompressedProcessor::set_CompressionLevel(int32_t Value)
{
	SBCheckError(TElSAMLCompressedProcessor_set_CompressionLevel(_Handle, Value));
}

TElSAMLCompressedProcessor::TElSAMLCompressedProcessor(TElSAMLCompressedProcessorHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSAMLCompressedProcessor::TElSAMLCompressedProcessor() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLCompressedProcessor_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLCOMPRESSEDPROCESSOR */

#ifdef SB_USE_CLASS_TELSAMLREDIRECTBINDING

TSBSAMLDataType TElSAMLRedirectBinding::Detect(const std::string &Buf, std::string &Proto)
{
	int32_t szProto = (int32_t)Proto.length();
	TSBSAMLDataTypeRaw OutResultRaw = 0;
	uint32_t _err = TElSAMLRedirectBinding_Detect(Buf.data(), (int32_t)Buf.length(), (char *)Proto.data(), &szProto, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Proto.resize(szProto);
		SBCheckError(SBGetLastReturnStringA(144278676, 1, (char *)Proto.data(), &szProto));
	}
	else
		SBCheckError(_err);

	Proto.resize(szProto);
	return (TSBSAMLDataType)OutResultRaw;
}

TSBSAMLDataType TElSAMLRedirectBinding::Detect_Inst(const std::string &Buf, std::string &Proto)
{
	int32_t szProto = (int32_t)Proto.length();
	TSBSAMLDataTypeRaw OutResultRaw = 0;
	uint32_t _err = TElSAMLRedirectBinding_Detect_1(_Handle, Buf.data(), (int32_t)Buf.length(), (char *)Proto.data(), &szProto, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Proto.resize(szProto);
		SBCheckError(SBGetLastReturnStringA(144278676, 2, (char *)Proto.data(), &szProto));
	}
	else
		SBCheckError(_err);

	Proto.resize(szProto);
	return (TSBSAMLDataType)OutResultRaw;
}

void TElSAMLRedirectBinding::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLRedirectBinding_GetName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-59453703, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
void TElSAMLRedirectBinding::SaveRequest(TElXMLDOMDocument &Doc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLRedirectBinding_SaveRequest(_Handle, Doc.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1628884802, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLRedirectBinding::SaveRequest(TElXMLDOMDocument *Doc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLRedirectBinding_SaveRequest(_Handle, (Doc != NULL) ? Doc->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1628884802, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
void TElSAMLRedirectBinding::SaveResponse(TElXMLDOMDocument &Doc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLRedirectBinding_SaveResponse(_Handle, Doc.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-464079914, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLRedirectBinding::SaveResponse(TElXMLDOMDocument *Doc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLRedirectBinding_SaveResponse(_Handle, (Doc != NULL) ? Doc->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-464079914, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

void TElSAMLRedirectBinding::SaveArtifact(const std::vector<uint8_t> &Artifact, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLRedirectBinding_SaveArtifact(_Handle, SB_STD_VECTOR_FRONT_ADR(Artifact), (int32_t)Artifact.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-164022155, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLRedirectBinding::LoadRequest(const std::string &Request, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLRedirectBinding_LoadRequest(_Handle, Request.data(), (int32_t)Request.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(117426539, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLRedirectBinding::LoadResponse(const std::string &Response, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLRedirectBinding_LoadResponse(_Handle, Response.data(), (int32_t)Response.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-263867009, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLRedirectBinding::LoadArtifact(const std::string &Artifact, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSAMLRedirectBinding_LoadArtifact(_Handle, Artifact.data(), (int32_t)Artifact.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-116898055, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLRedirectBinding::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLRedirectBinding_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1332028142, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLRedirectBinding::set_URL(const std::string &Value)
{
	SBCheckError(TElSAMLRedirectBinding_set_URL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLRedirectBinding::get_Encoding(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLRedirectBinding_get_Encoding(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2128031919, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLRedirectBinding::set_Encoding(const std::string &Value)
{
	SBCheckError(TElSAMLRedirectBinding_set_Encoding(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLRedirectBinding::get_RelayState(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLRedirectBinding_get_RelayState(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2134379695, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLRedirectBinding::set_RelayState(const std::string &Value)
{
	SBCheckError(TElSAMLRedirectBinding_set_RelayState(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLRedirectBinding::get_SignatureAlg(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLRedirectBinding_get_SignatureAlg(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(317219926, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLRedirectBinding::set_SignatureAlg(const std::string &Value)
{
	SBCheckError(TElSAMLRedirectBinding_set_SignatureAlg(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElSAMLRedirectBinding::get_ForceSign()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLRedirectBinding_get_ForceSign(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLRedirectBinding::set_ForceSign(bool Value)
{
	SBCheckError(TElSAMLRedirectBinding_set_ForceSign(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
TElPublicKeyMaterial* TElSAMLRedirectBinding::get_KeyMaterial()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSAMLRedirectBinding_get_KeyMaterial(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyMaterial)
		this->_Inst_KeyMaterial = new TElPublicKeyMaterial(hOutResult, ohFalse);
	else
		this->_Inst_KeyMaterial->updateHandle(hOutResult);
	return this->_Inst_KeyMaterial;
}

SB_INLINE void TElSAMLRedirectBinding::set_KeyMaterial(TElPublicKeyMaterial &Value)
{
	SBCheckError(TElSAMLRedirectBinding_set_KeyMaterial(_Handle, Value.getHandle()));
}

SB_INLINE void TElSAMLRedirectBinding::set_KeyMaterial(TElPublicKeyMaterial *Value)
{
	SBCheckError(TElSAMLRedirectBinding_set_KeyMaterial(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

bool TElSAMLRedirectBinding::get_VerifySignatures()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSAMLRedirectBinding_get_VerifySignatures(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSAMLRedirectBinding::set_VerifySignatures(bool Value)
{
	SBCheckError(TElSAMLRedirectBinding_set_VerifySignatures(_Handle, (int8_t)Value));
}

SB_INLINE void TElSAMLRedirectBinding::get_OnRedirectBinderSign(TSBSAMLRedirectBinderSign &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLRedirectBinding_get_OnRedirectBinderSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLRedirectBinding::set_OnRedirectBinderSign(TSBSAMLRedirectBinderSign pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLRedirectBinding_set_OnRedirectBinderSign(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSAMLRedirectBinding::get_OnRedirectBinderVerify(TSBSAMLRedirectBinderVerify &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLRedirectBinding_get_OnRedirectBinderVerify(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLRedirectBinding::set_OnRedirectBinderVerify(TSBSAMLRedirectBinderVerify pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLRedirectBinding_set_OnRedirectBinderVerify(_Handle, pMethodValue, pDataValue));
}

void TElSAMLRedirectBinding::initInstances()
{
#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */
}

TElSAMLRedirectBinding::TElSAMLRedirectBinding(TElSAMLRedirectBindingHandle handle, TElOwnHandle ownHandle) : TElSAMLBinding(handle, ownHandle)
{
	initInstances();
}

TElSAMLRedirectBinding::TElSAMLRedirectBinding() : TElSAMLBinding(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSAMLRedirectBinding_Create(&_Handle));
}

TElSAMLRedirectBinding::~TElSAMLRedirectBinding()
{
#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
	delete this->_Inst_KeyMaterial;
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */
}
#endif /* SB_USE_CLASS_TELSAMLREDIRECTBINDING */

#ifdef SB_USE_CLASS_TELSAMLPOSTBINDING

TSBSAMLDataType TElSAMLPOSTBinding::Detect(const std::vector<uint8_t> &Buf, std::string &Proto)
{
	int32_t szProto = (int32_t)Proto.length();
	TSBSAMLDataTypeRaw OutResultRaw = 0;
	uint32_t _err = TElSAMLPOSTBinding_Detect(SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), (char *)Proto.data(), &szProto, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Proto.resize(szProto);
		SBCheckError(SBGetLastReturnStringA(2113827569, 1, (char *)Proto.data(), &szProto));
	}
	else
		SBCheckError(_err);

	Proto.resize(szProto);
	return (TSBSAMLDataType)OutResultRaw;
}

TSBSAMLDataType TElSAMLPOSTBinding::Detect_Inst(const std::vector<uint8_t> &Buf, std::string &Proto)
{
	int32_t szProto = (int32_t)Proto.length();
	TSBSAMLDataTypeRaw OutResultRaw = 0;
	uint32_t _err = TElSAMLPOSTBinding_Detect_1(_Handle, SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), (char *)Proto.data(), &szProto, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Proto.resize(szProto);
		SBCheckError(SBGetLastReturnStringA(2113827569, 2, (char *)Proto.data(), &szProto));
	}
	else
		SBCheckError(_err);

	Proto.resize(szProto);
	return (TSBSAMLDataType)OutResultRaw;
}

void TElSAMLPOSTBinding::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLPOSTBinding_GetName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(624063246, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
void TElSAMLPOSTBinding::SaveRequest(TElXMLDOMDocument &Doc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLPOSTBinding_SaveRequest(_Handle, Doc.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1447537896, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLPOSTBinding::SaveRequest(TElXMLDOMDocument *Doc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLPOSTBinding_SaveRequest(_Handle, (Doc != NULL) ? Doc->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1447537896, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
void TElSAMLPOSTBinding::SaveResponse(TElXMLDOMDocument &Doc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLPOSTBinding_SaveResponse(_Handle, Doc.getHandle(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1272222839, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLPOSTBinding::SaveResponse(TElXMLDOMDocument *Doc, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLPOSTBinding_SaveResponse(_Handle, (Doc != NULL) ? Doc->getHandle() : SB_NULL_HANDLE, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1272222839, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

void TElSAMLPOSTBinding::LoadRequest(const std::string &Request, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLPOSTBinding_LoadRequest(_Handle, Request.data(), (int32_t)Request.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1608275339, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLPOSTBinding::LoadResponse(const std::string &Response, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLPOSTBinding_LoadResponse(_Handle, Response.data(), (int32_t)Response.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1040951894, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLPOSTBinding::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLPOSTBinding_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-100508425, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLPOSTBinding::set_URL(const std::string &Value)
{
	SBCheckError(TElSAMLPOSTBinding_set_URL(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLPOSTBinding::get_RelayState(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLPOSTBinding_get_RelayState(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1108824842, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLPOSTBinding::set_RelayState(const std::string &Value)
{
	SBCheckError(TElSAMLPOSTBinding_set_RelayState(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLPOSTBinding::get_FormTemplate(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLPOSTBinding_get_FormTemplate(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1680724897, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLPOSTBinding::set_FormTemplate(const std::string &Value)
{
	SBCheckError(TElSAMLPOSTBinding_set_FormTemplate(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSAMLPOSTBinding::get_Body(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSAMLPOSTBinding_get_Body(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1227220172, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLPOSTBinding::set_Body(const std::string &Value)
{
	SBCheckError(TElSAMLPOSTBinding_set_Body(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBSAMLPOSTBindingMode TElSAMLPOSTBinding::get_Mode()
{
	TSBSAMLPOSTBindingModeRaw OutResultRaw = 0;
	SBCheckError(TElSAMLPOSTBinding_get_Mode(_Handle, &OutResultRaw));
	return (TSBSAMLPOSTBindingMode)OutResultRaw;
}

SB_INLINE void TElSAMLPOSTBinding::set_Mode(TSBSAMLPOSTBindingMode Value)
{
	SBCheckError(TElSAMLPOSTBinding_set_Mode(_Handle, (TSBSAMLPOSTBindingModeRaw)Value));
}

SB_INLINE void TElSAMLPOSTBinding::get_OnParseForm(TSBSAMLPOSTBindingParseForm &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSAMLPOSTBinding_get_OnParseForm(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSAMLPOSTBinding::set_OnParseForm(TSBSAMLPOSTBindingParseForm pMethodValue, void * pDataValue)
{
	SBCheckError(TElSAMLPOSTBinding_set_OnParseForm(_Handle, pMethodValue, pDataValue));
}

TElSAMLPOSTBinding::TElSAMLPOSTBinding(TElSAMLPOSTBindingHandle handle, TElOwnHandle ownHandle) : TElSAMLBinding(handle, ownHandle)
{
}

TElSAMLPOSTBinding::TElSAMLPOSTBinding() : TElSAMLBinding(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLPOSTBinding_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLPOSTBINDING */

#ifdef SB_USE_CLASS_TELSAMLARTIFACT

void TElSAMLArtifact::SaveToBuffer(std::vector<uint8_t> &Buf, int32_t &Size)
{
	int32_t szBuf = (int32_t)Buf.size();
	uint32_t _err = TElSAMLArtifact_SaveToBuffer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buf), &szBuf, &Size);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buf.resize(szBuf);
		SBCheckError(SBGetLastReturnBuffer(777458146, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buf), &szBuf));
	}
	else
		SBCheckError(_err);

	Buf.resize(szBuf);
}

SB_INLINE void TElSAMLArtifact::LoadFromBuffer(const std::vector<uint8_t> &Buffer)
{
	SBCheckError(TElSAMLArtifact_LoadFromBuffer(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size()));
}

SB_INLINE void TElSAMLArtifact::Initialize(const std::string &URI)
{
	SBCheckError(TElSAMLArtifact_Initialize(_Handle, URI.data(), (int32_t)URI.length()));
}

SB_INLINE uint16_t TElSAMLArtifact::get_TypeCode()
{
	uint16_t OutResult;
	SBCheckError(TElSAMLArtifact_get_TypeCode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint16_t TElSAMLArtifact::get_EndPointIndex()
{
	uint16_t OutResult;
	SBCheckError(TElSAMLArtifact_get_EndPointIndex(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSAMLArtifact::set_EndPointIndex(uint16_t Value)
{
	SBCheckError(TElSAMLArtifact_set_EndPointIndex(_Handle, Value));
}

void TElSAMLArtifact::get_RamainingArtifact(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSAMLArtifact_get_RamainingArtifact(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1114650305, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSAMLArtifact::get_SourceID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSAMLArtifact_get_SourceID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(466442972, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLArtifact::set_SourceID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSAMLArtifact_set_SourceID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElSAMLArtifact::get_MessageHandle(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSAMLArtifact_get_MessageHandle(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1396907964, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSAMLArtifact::set_MessageHandle(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSAMLArtifact_set_MessageHandle(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElSAMLArtifact::TElSAMLArtifact(TElSAMLArtifactHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSAMLArtifact::TElSAMLArtifact() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSAMLArtifact_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSAMLARTIFACT */

#ifdef SB_USE_GLOBAL_PROCS_XMLSAMLBIND

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void ParseHTTPParameters(const std::string &S, TStringList &Output)
{
	SBCheckError(SBXMLSAMLBind_ParseHTTPParameters(S.data(), (int32_t)S.length(), Output.getHandle()));
}
SB_INLINE void ParseHTTPParameters(const std::string &S, TStringList *Output)
{
	SBCheckError(SBXMLSAMLBind_ParseHTTPParameters(S.data(), (int32_t)S.length(), (Output != NULL) ? Output->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void ParseHTTPParameters(const std::string &S, TElStringList &Output)
{
	SBCheckError(SBXMLSAMLBind_ParseHTTPParameters(S.data(), (int32_t)S.length(), Output.getHandle()));
}
SB_INLINE void ParseHTTPParameters(const std::string &S, TElStringList *Output)
{
	SBCheckError(SBXMLSAMLBind_ParseHTTPParameters(S.data(), (int32_t)S.length(), (Output != NULL) ? Output->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#endif /* SB_USE_GLOBAL_PROCS_XMLSAMLBIND */

};	/* namespace SecureBlackbox */
