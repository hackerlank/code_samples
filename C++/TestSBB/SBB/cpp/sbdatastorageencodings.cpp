#include "sbdatastorageencodings.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELZLIBDATASTORAGEENCODINGHANDLER

SB_INLINE void TElZlibDataStorageEncodingHandler::Reset()
{
	SBCheckError(TElZlibDataStorageEncodingHandler_Reset(_Handle));
}

void TElZlibDataStorageEncodingHandler::GetOID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZlibDataStorageEncodingHandler_GetOID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1343821601, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElZlibDataStorageEncodingHandler::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZlibDataStorageEncodingHandler_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1839675731, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TElZlibDataStorageEncodingHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElZlibDataStorageEncodingHandler_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElZlibDataStorageEncodingHandler::get_CompressionLevel()
{
	int32_t OutResult;
	SBCheckError(TElZlibDataStorageEncodingHandler_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZlibDataStorageEncodingHandler::set_CompressionLevel(int32_t Value)
{
	SBCheckError(TElZlibDataStorageEncodingHandler_set_CompressionLevel(_Handle, Value));
}

TElZlibDataStorageEncodingHandler::TElZlibDataStorageEncodingHandler(TElZlibDataStorageEncodingHandlerHandle handle, TElOwnHandle ownHandle) : TElCustomDataStorageEncodingHandler(handle, ownHandle)
{
}

TElZlibDataStorageEncodingHandler::TElZlibDataStorageEncodingHandler(TComponent &AOwner) : TElCustomDataStorageEncodingHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZlibDataStorageEncodingHandler_Create(AOwner.getHandle(), &_Handle));
}

TElZlibDataStorageEncodingHandler::TElZlibDataStorageEncodingHandler(TComponent *AOwner) : TElCustomDataStorageEncodingHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZlibDataStorageEncodingHandler_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELZLIBDATASTORAGEENCODINGHANDLER */

};	/* namespace SecureBlackbox */

