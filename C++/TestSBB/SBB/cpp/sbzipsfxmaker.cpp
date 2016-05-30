#include "sbdefs.h"
#ifdef SB_WINDOWS
#include "sbzipsfxmaker.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELZIPSFXMAKER

bool TElZIPSFXMaker::Execute()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZIPSFXMaker_Execute(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElZIPSFXMaker::get_Copyright(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZIPSFXMaker_get_Copyright(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-722722857, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZIPSFXMaker::set_Copyright(const std::string &Value)
{
	SBCheckError(TElZIPSFXMaker_set_Copyright(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElZIPSFXMaker::get_Title(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElZIPSFXMaker_get_Title(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1640740100, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZIPSFXMaker::set_Title(const std::string &Value)
{
	SBCheckError(TElZIPSFXMaker_set_Title(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElZIPSFXMaker::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZIPSFXMaker_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZIPSFXMaker::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZIPSFXMaker_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

TElZIPSFXMaker::TElZIPSFXMaker(TElZIPSFXMakerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TSTREAM
TElZIPSFXMaker::TElZIPSFXMaker(TStream &AStub, TStream &AOutput) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZIPSFXMaker_Create(AStub.getHandle(), AOutput.getHandle(), &_Handle));
}

TElZIPSFXMaker::TElZIPSFXMaker(TStream *AStub, TStream *AOutput) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZIPSFXMaker_Create((AStub != NULL) ? AStub->getHandle() : SB_NULL_HANDLE, (AOutput != NULL) ? AOutput->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TSTREAM */

#endif /* SB_USE_CLASS_TELZIPSFXMAKER */

};	/* namespace SecureBlackbox */
#endif
