#include "sbpdfutils.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPDFPERMISSIONS

SB_INLINE void TElPDFPermissions::Load(uint32_t Value, int32_t Revision)
{
	SBCheckError(TElPDFPermissions_Load(_Handle, Value, Revision));
}

SB_INLINE uint32_t TElPDFPermissions::Save(int32_t Revision, bool PubKeyHandler)
{
	uint32_t OutResult;
	SBCheckError(TElPDFPermissions_Save(_Handle, Revision, (int8_t)PubKeyHandler, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFPermissions::DisableAll()
{
	SBCheckError(TElPDFPermissions_DisableAll(_Handle));
}

SB_INLINE void TElPDFPermissions::EnableAll()
{
	SBCheckError(TElPDFPermissions_EnableAll(_Handle));
}

bool TElPDFPermissions::get_Modify()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFPermissions_get_Modify(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFPermissions::set_Modify(bool Value)
{
	SBCheckError(TElPDFPermissions_set_Modify(_Handle, (int8_t)Value));
}

bool TElPDFPermissions::get_Extract()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFPermissions_get_Extract(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFPermissions::set_Extract(bool Value)
{
	SBCheckError(TElPDFPermissions_set_Extract(_Handle, (int8_t)Value));
}

bool TElPDFPermissions::get_Annotations()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFPermissions_get_Annotations(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFPermissions::set_Annotations(bool Value)
{
	SBCheckError(TElPDFPermissions_set_Annotations(_Handle, (int8_t)Value));
}

bool TElPDFPermissions::get_FillInForms()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFPermissions_get_FillInForms(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFPermissions::set_FillInForms(bool Value)
{
	SBCheckError(TElPDFPermissions_set_FillInForms(_Handle, (int8_t)Value));
}

bool TElPDFPermissions::get_ExtractAcc()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFPermissions_get_ExtractAcc(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFPermissions::set_ExtractAcc(bool Value)
{
	SBCheckError(TElPDFPermissions_set_ExtractAcc(_Handle, (int8_t)Value));
}

bool TElPDFPermissions::get_Assemble()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFPermissions_get_Assemble(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFPermissions::set_Assemble(bool Value)
{
	SBCheckError(TElPDFPermissions_set_Assemble(_Handle, (int8_t)Value));
}

bool TElPDFPermissions::get_LowQualityPrint()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFPermissions_get_LowQualityPrint(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFPermissions::set_LowQualityPrint(bool Value)
{
	SBCheckError(TElPDFPermissions_set_LowQualityPrint(_Handle, (int8_t)Value));
}

bool TElPDFPermissions::get_HighQualityPrint()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFPermissions_get_HighQualityPrint(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFPermissions::set_HighQualityPrint(bool Value)
{
	SBCheckError(TElPDFPermissions_set_HighQualityPrint(_Handle, (int8_t)Value));
}

TElPDFPermissions::TElPDFPermissions(TElPDFPermissionsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPDFPermissions::TElPDFPermissions() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFPermissions_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPDFPERMISSIONS */

#ifdef SB_USE_GLOBAL_PROCS_PDFUTILS

void IntToByteArray(int32_t Value, bool LittleEndian, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBPDFUtils_IntToByteArray(Value, (int8_t)LittleEndian, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(244735852, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void UIntToByteArray(uint32_t Value, bool LittleEndian, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBPDFUtils_UIntToByteArray(Value, (int8_t)LittleEndian, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1288734326, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool IsPNGPredictor(int32_t Value)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPDFUtils_IsPNGPredictor(Value, &OutResultRaw));
	return (OutResultRaw != 0);
}

void DecodePNG(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count, int32_t Cols, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBPDFUtils_DecodePNG(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), StartIndex, Count, Cols, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(46507165, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TrimArray(std::vector<uint8_t> &a)
{
	int32_t sza = (int32_t)a.size();
	uint32_t _err = SBPDFUtils_TrimArray((uint8_t *)SB_STD_VECTOR_FRONT_ADR(a), &sza);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		a.resize(sza);
		SBCheckError(SBGetLastReturnBuffer(1318495411, 0, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(a), &sza));
	}
	else
		SBCheckError(_err);

	a.resize(sza);
}

#endif /* SB_USE_GLOBAL_PROCS_PDFUTILS */

};	/* namespace SecureBlackbox */

