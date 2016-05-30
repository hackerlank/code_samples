#include "sbtarentities.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELTARFILEHEADER

SB_INLINE void TElTarFileHeader::Assign(TElTarFileHeader &Source)
{
	SBCheckError(TElTarFileHeader_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElTarFileHeader::Assign(TElTarFileHeader *Source)
{
	SBCheckError(TElTarFileHeader_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElTarFileHeader::AssignTo(TElTarFileHeader &Dest)
{
	SBCheckError(TElTarFileHeader_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElTarFileHeader::AssignTo(TElTarFileHeader *Dest)
{
	SBCheckError(TElTarFileHeader_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int64_t TElTarFileHeader::CalculateCheckSum()
{
	int64_t OutResult;
	SBCheckError(TElTarFileHeader_CalculateCheckSum(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELBASETARHEADER
TElBaseTarHeader* TElTarFileHeader::get_Base()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTarFileHeader_get_Base(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Base)
		this->_Inst_Base = new TElBaseTarHeader(hOutResult, ohFalse);
	else
		this->_Inst_Base->updateHandle(hOutResult);
	return this->_Inst_Base;
}

SB_INLINE void TElTarFileHeader::set_Base(TElBaseTarHeader &Value)
{
	SBCheckError(TElTarFileHeader_set_Base(_Handle, Value.getHandle()));
}

SB_INLINE void TElTarFileHeader::set_Base(TElBaseTarHeader *Value)
{
	SBCheckError(TElTarFileHeader_set_Base(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELBASETARHEADER */

bool TElTarFileHeader::get_HasUStar()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarFileHeader_get_HasUStar(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTarFileHeader::set_HasUStar(bool Value)
{
	SBCheckError(TElTarFileHeader_set_HasUStar(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELUSTARTARHEADER
TElUStarTarHeader* TElTarFileHeader::get_UStar()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElTarFileHeader_get_UStar(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_UStar)
		this->_Inst_UStar = new TElUStarTarHeader(hOutResult, ohFalse);
	else
		this->_Inst_UStar->updateHandle(hOutResult);
	return this->_Inst_UStar;
}

SB_INLINE void TElTarFileHeader::set_UStar(TElUStarTarHeader &Value)
{
	SBCheckError(TElTarFileHeader_set_UStar(_Handle, Value.getHandle()));
}

SB_INLINE void TElTarFileHeader::set_UStar(TElUStarTarHeader *Value)
{
	SBCheckError(TElTarFileHeader_set_UStar(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELUSTARTARHEADER */

SB_INLINE int64_t TElTarFileHeader::get_LocalHeaderOffset()
{
	int64_t OutResult;
	SBCheckError(TElTarFileHeader_get_LocalHeaderOffset(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTarFileHeader::set_LocalHeaderOffset(int64_t Value)
{
	SBCheckError(TElTarFileHeader_set_LocalHeaderOffset(_Handle, Value));
}

SB_INLINE int64_t TElTarFileHeader::get_FileSize()
{
	int64_t OutResult;
	SBCheckError(TElTarFileHeader_get_FileSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTarFileHeader::set_FileSize(int64_t Value)
{
	SBCheckError(TElTarFileHeader_set_FileSize(_Handle, Value));
}

void TElTarFileHeader::initInstances()
{
#ifdef SB_USE_CLASS_TELBASETARHEADER
	this->_Inst_Base = NULL;
#endif /* SB_USE_CLASS_TELBASETARHEADER */
#ifdef SB_USE_CLASS_TELUSTARTARHEADER
	this->_Inst_UStar = NULL;
#endif /* SB_USE_CLASS_TELUSTARTARHEADER */
}

TElTarFileHeader::TElTarFileHeader(TElTarFileHeaderHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElTarFileHeader::TElTarFileHeader() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElTarFileHeader_Create(&_Handle));
}

TElTarFileHeader::~TElTarFileHeader()
{
#ifdef SB_USE_CLASS_TELBASETARHEADER
	delete this->_Inst_Base;
	this->_Inst_Base = NULL;
#endif /* SB_USE_CLASS_TELBASETARHEADER */
#ifdef SB_USE_CLASS_TELUSTARTARHEADER
	delete this->_Inst_UStar;
	this->_Inst_UStar = NULL;
#endif /* SB_USE_CLASS_TELUSTARTARHEADER */
}
#endif /* SB_USE_CLASS_TELTARFILEHEADER */

#ifdef SB_USE_CLASS_TELBASETARHEADER

SB_INLINE void TElBaseTarHeader::Assign(TElBaseTarHeader &Source)
{
	SBCheckError(TElBaseTarHeader_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElBaseTarHeader::Assign(TElBaseTarHeader *Source)
{
	SBCheckError(TElBaseTarHeader_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElBaseTarHeader::AssignTo(TElBaseTarHeader &Dest)
{
	SBCheckError(TElBaseTarHeader_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElBaseTarHeader::AssignTo(TElBaseTarHeader *Dest)
{
	SBCheckError(TElBaseTarHeader_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElBaseTarHeader::LoadFromBuffer(const std::vector<uint8_t> &Buf)
{
	SBCheckError(TElBaseTarHeader_LoadFromBuffer(_Handle, SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size()));
}

void TElBaseTarHeader::SaveToBuffer(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBaseTarHeader_SaveToBuffer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1744499206, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElBaseTarHeader::get_Name(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBaseTarHeader_get_Name(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-558571181, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBaseTarHeader::set_Name(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBaseTarHeader_set_Name(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElBaseTarHeader::get_Mode(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBaseTarHeader_get_Mode(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(392026366, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBaseTarHeader::set_Mode(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBaseTarHeader_set_Mode(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElBaseTarHeader::get_UID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBaseTarHeader_get_UID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(14937311, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBaseTarHeader::set_UID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBaseTarHeader_set_UID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElBaseTarHeader::get_GID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBaseTarHeader_get_GID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(524393409, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBaseTarHeader::set_GID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBaseTarHeader_set_GID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElBaseTarHeader::get_Size(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBaseTarHeader_get_Size(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2002238271, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBaseTarHeader::set_Size(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBaseTarHeader_set_Size(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElBaseTarHeader::get_MTime(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBaseTarHeader_get_MTime(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2132708881, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBaseTarHeader::set_MTime(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBaseTarHeader_set_MTime(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElBaseTarHeader::get_CheckSum(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBaseTarHeader_get_CheckSum(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(507697606, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBaseTarHeader::set_CheckSum(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBaseTarHeader_set_CheckSum(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElBaseTarHeader::get_TypeFlag(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBaseTarHeader_get_TypeFlag(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-958727421, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBaseTarHeader::set_TypeFlag(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBaseTarHeader_set_TypeFlag(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElBaseTarHeader::get_LinkName(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElBaseTarHeader_get_LinkName(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(123798853, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElBaseTarHeader::set_LinkName(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElBaseTarHeader_set_LinkName(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElBaseTarHeader::TElBaseTarHeader(TElBaseTarHeaderHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElBaseTarHeader::TElBaseTarHeader() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBaseTarHeader_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELBASETARHEADER */

#ifdef SB_USE_CLASS_TELUSTARTARHEADER

SB_INLINE void TElUStarTarHeader::Assign(TElUStarTarHeader &Source)
{
	SBCheckError(TElUStarTarHeader_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElUStarTarHeader::Assign(TElUStarTarHeader *Source)
{
	SBCheckError(TElUStarTarHeader_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElUStarTarHeader::AssignTo(TElUStarTarHeader &Dest)
{
	SBCheckError(TElUStarTarHeader_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElUStarTarHeader::AssignTo(TElUStarTarHeader *Dest)
{
	SBCheckError(TElUStarTarHeader_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElUStarTarHeader::LoadFromBuffer(const std::vector<uint8_t> &B)
{
	SBCheckError(TElUStarTarHeader_LoadFromBuffer(_Handle, SB_STD_VECTOR_FRONT_ADR(B), (int32_t)B.size()));
}

void TElUStarTarHeader::SaveToBuffer(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElUStarTarHeader_SaveToBuffer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1663295211, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElUStarTarHeader::get_Magic(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElUStarTarHeader_get_Magic(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-668552834, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElUStarTarHeader::set_Magic(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElUStarTarHeader_set_Magic(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElUStarTarHeader::get_UName(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElUStarTarHeader_get_UName(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-110768426, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElUStarTarHeader::set_UName(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElUStarTarHeader_set_UName(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElUStarTarHeader::get_GName(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElUStarTarHeader_get_GName(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-482014668, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElUStarTarHeader::set_GName(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElUStarTarHeader_set_GName(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElUStarTarHeader::get_DevMajor(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElUStarTarHeader_get_DevMajor(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-716121791, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElUStarTarHeader::set_DevMajor(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElUStarTarHeader_set_DevMajor(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElUStarTarHeader::get_DevMinor(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElUStarTarHeader_get_DevMinor(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(401430898, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElUStarTarHeader::set_DevMinor(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElUStarTarHeader_set_DevMinor(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElUStarTarHeader::get_Prefix(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElUStarTarHeader_get_Prefix(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(705239215, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElUStarTarHeader::set_Prefix(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElUStarTarHeader_set_Prefix(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElUStarTarHeader::TElUStarTarHeader(TElUStarTarHeaderHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElUStarTarHeader::TElUStarTarHeader() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElUStarTarHeader_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELUSTARTARHEADER */

#ifdef SB_USE_CLASS_TELTARPROCESSOR

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElTarProcessor::Process(TStream &Stream)
{
	SBCheckError(TElTarProcessor_Process(_Handle, Stream.getHandle()));
}

SB_INLINE void TElTarProcessor::Process(TStream *Stream)
{
	SBCheckError(TElTarProcessor_Process(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElTarProcessor::DataAvailable()
{
	SBCheckError(TElTarProcessor_DataAvailable(_Handle));
}

bool TElTarProcessor::get_Processed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTarProcessor_get_Processed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTarProcessor::get_OnTarFileHeaderLoaded(TSBTarFileHeaderLoadedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTarProcessor_get_OnTarFileHeaderLoaded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTarProcessor::set_OnTarFileHeaderLoaded(TSBTarFileHeaderLoadedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTarProcessor_set_OnTarFileHeaderLoaded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElTarProcessor::get_OnArchiveError(TSBTarArchiveErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTarProcessor_get_OnArchiveError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTarProcessor::set_OnArchiveError(TSBTarArchiveErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTarProcessor_set_OnArchiveError(_Handle, pMethodValue, pDataValue));
}

TElTarProcessor::TElTarProcessor(TElTarProcessorHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElTarProcessor::TElTarProcessor() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTarProcessor_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELTARPROCESSOR */

};	/* namespace SecureBlackbox */

