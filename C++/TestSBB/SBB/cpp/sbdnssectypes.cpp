#include "sbdnssectypes.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORD

SB_INLINE void TElDNSResourceRecord::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSResourceRecord_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSResourceRecord::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSResourceRecord_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSResourceRecord::Prepare(const std::string &CanonicalName, uint32_t OriginalTTL)
{
	SBCheckError(TElDNSResourceRecord_Prepare(_Handle, CanonicalName.data(), (int32_t)CanonicalName.length(), OriginalTTL));
}

SB_INLINE void TElDNSResourceRecord::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSResourceRecord_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElDNSResourceRecord::Write(TStream &Stream)
{
	SBCheckError(TElDNSResourceRecord_Write(_Handle, Stream.getHandle()));
}

SB_INLINE void TElDNSResourceRecord::Write(TStream *Stream)
{
	SBCheckError(TElDNSResourceRecord_Write(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElDNSResourceRecord::get_Data(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDNSResourceRecord_get_Data(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1895897343, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElDNSResourceRecord::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSResourceRecord_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2100193892, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSResourceRecord::set_Name(const std::string &Value)
{
	SBCheckError(TElDNSResourceRecord_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE uint16_t TElDNSResourceRecord::get_ResourceClass()
{
	uint16_t OutResult;
	SBCheckError(TElDNSResourceRecord_get_ResourceClass(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSResourceRecord::set_ResourceClass(uint16_t Value)
{
	SBCheckError(TElDNSResourceRecord_set_ResourceClass(_Handle, Value));
}

SB_INLINE uint16_t TElDNSResourceRecord::get_ResourceCode()
{
	uint16_t OutResult;
	SBCheckError(TElDNSResourceRecord_get_ResourceCode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSResourceRecord::set_ResourceCode(uint16_t Value)
{
	SBCheckError(TElDNSResourceRecord_set_ResourceCode(_Handle, Value));
}

TSBDNSResourceType TElDNSResourceRecord::get_ResourceType()
{
	TSBDNSResourceTypeRaw OutResultRaw = 0;
	SBCheckError(TElDNSResourceRecord_get_ResourceType(_Handle, &OutResultRaw));
	return (TSBDNSResourceType)OutResultRaw;
}

SB_INLINE void TElDNSResourceRecord::set_ResourceType(TSBDNSResourceType Value)
{
	SBCheckError(TElDNSResourceRecord_set_ResourceType(_Handle, (TSBDNSResourceTypeRaw)Value));
}

SB_INLINE uint32_t TElDNSResourceRecord::get_TimeToLive()
{
	uint32_t OutResult;
	SBCheckError(TElDNSResourceRecord_get_TimeToLive(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSResourceRecord::set_TimeToLive(uint32_t Value)
{
	SBCheckError(TElDNSResourceRecord_set_TimeToLive(_Handle, Value));
}

TElDNSResourceRecord::TElDNSResourceRecord(TElDNSResourceRecordHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElDNSResourceRecord::TElDNSResourceRecord() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSResourceRecord_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSRESOURCERECORD */

#ifdef SB_USE_CLASS_TELDNSIPV4ADDRESSRECORD

SB_INLINE void TElDNSIPv4AddressRecord::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSIPv4AddressRecord_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSIPv4AddressRecord::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSIPv4AddressRecord_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSIPv4AddressRecord::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSIPv4AddressRecord_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

void TElDNSIPv4AddressRecord::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSIPv4AddressRecord_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-877998105, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSIPv4AddressRecord::set_Address(const std::string &Value)
{
	SBCheckError(TElDNSIPv4AddressRecord_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

TElDNSIPv4AddressRecord::TElDNSIPv4AddressRecord(TElDNSIPv4AddressRecordHandle handle, TElOwnHandle ownHandle) : TElDNSResourceRecord(handle, ownHandle)
{
}

TElDNSIPv4AddressRecord::TElDNSIPv4AddressRecord() : TElDNSResourceRecord(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSIPv4AddressRecord_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSIPV4ADDRESSRECORD */

#ifdef SB_USE_CLASS_TELDNSNAMESERVERRECORD

SB_INLINE void TElDNSNameServerRecord::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSNameServerRecord_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSNameServerRecord::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSNameServerRecord_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSNameServerRecord::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSNameServerRecord_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

void TElDNSNameServerRecord::get_HostName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSNameServerRecord_get_HostName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-621686202, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSNameServerRecord::set_HostName(const std::string &Value)
{
	SBCheckError(TElDNSNameServerRecord_set_HostName(_Handle, Value.data(), (int32_t)Value.length()));
}

TElDNSNameServerRecord::TElDNSNameServerRecord(TElDNSNameServerRecordHandle handle, TElOwnHandle ownHandle) : TElDNSResourceRecord(handle, ownHandle)
{
}

TElDNSNameServerRecord::TElDNSNameServerRecord() : TElDNSResourceRecord(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSNameServerRecord_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSNAMESERVERRECORD */

#ifdef SB_USE_CLASS_TELDNSCANONICALNAMERECORD

SB_INLINE void TElDNSCanonicalNameRecord::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSCanonicalNameRecord_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSCanonicalNameRecord::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSCanonicalNameRecord_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSCanonicalNameRecord::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSCanonicalNameRecord_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

void TElDNSCanonicalNameRecord::get_Domain(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSCanonicalNameRecord_get_Domain(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1058713094, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSCanonicalNameRecord::set_Domain(const std::string &Value)
{
	SBCheckError(TElDNSCanonicalNameRecord_set_Domain(_Handle, Value.data(), (int32_t)Value.length()));
}

TElDNSCanonicalNameRecord::TElDNSCanonicalNameRecord(TElDNSCanonicalNameRecordHandle handle, TElOwnHandle ownHandle) : TElDNSResourceRecord(handle, ownHandle)
{
}

TElDNSCanonicalNameRecord::TElDNSCanonicalNameRecord() : TElDNSResourceRecord(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSCanonicalNameRecord_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSCANONICALNAMERECORD */

#ifdef SB_USE_CLASS_TELDNSSTARTOFAUTHORITYRECORD

SB_INLINE void TElDNSStartOfAuthorityRecord::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSStartOfAuthorityRecord_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSStartOfAuthorityRecord::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSStartOfAuthorityRecord_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSStartOfAuthorityRecord::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSStartOfAuthorityRecord_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

SB_INLINE uint32_t TElDNSStartOfAuthorityRecord::get_Expire()
{
	uint32_t OutResult;
	SBCheckError(TElDNSStartOfAuthorityRecord_get_Expire(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSStartOfAuthorityRecord::set_Expire(uint32_t Value)
{
	SBCheckError(TElDNSStartOfAuthorityRecord_set_Expire(_Handle, Value));
}

SB_INLINE uint32_t TElDNSStartOfAuthorityRecord::get_MinimumTTL()
{
	uint32_t OutResult;
	SBCheckError(TElDNSStartOfAuthorityRecord_get_MinimumTTL(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSStartOfAuthorityRecord::set_MinimumTTL(uint32_t Value)
{
	SBCheckError(TElDNSStartOfAuthorityRecord_set_MinimumTTL(_Handle, Value));
}

void TElDNSStartOfAuthorityRecord::get_Person(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSStartOfAuthorityRecord_get_Person(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-720313996, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSStartOfAuthorityRecord::set_Person(const std::string &Value)
{
	SBCheckError(TElDNSStartOfAuthorityRecord_set_Person(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE uint32_t TElDNSStartOfAuthorityRecord::get_Refresh()
{
	uint32_t OutResult;
	SBCheckError(TElDNSStartOfAuthorityRecord_get_Refresh(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSStartOfAuthorityRecord::set_Refresh(uint32_t Value)
{
	SBCheckError(TElDNSStartOfAuthorityRecord_set_Refresh(_Handle, Value));
}

SB_INLINE uint32_t TElDNSStartOfAuthorityRecord::get_RefreshRetry()
{
	uint32_t OutResult;
	SBCheckError(TElDNSStartOfAuthorityRecord_get_RefreshRetry(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSStartOfAuthorityRecord::set_RefreshRetry(uint32_t Value)
{
	SBCheckError(TElDNSStartOfAuthorityRecord_set_RefreshRetry(_Handle, Value));
}

SB_INLINE uint32_t TElDNSStartOfAuthorityRecord::get_Serial()
{
	uint32_t OutResult;
	SBCheckError(TElDNSStartOfAuthorityRecord_get_Serial(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSStartOfAuthorityRecord::set_Serial(uint32_t Value)
{
	SBCheckError(TElDNSStartOfAuthorityRecord_set_Serial(_Handle, Value));
}

void TElDNSStartOfAuthorityRecord::get_Server(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSStartOfAuthorityRecord_get_Server(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1147017740, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSStartOfAuthorityRecord::set_Server(const std::string &Value)
{
	SBCheckError(TElDNSStartOfAuthorityRecord_set_Server(_Handle, Value.data(), (int32_t)Value.length()));
}

TElDNSStartOfAuthorityRecord::TElDNSStartOfAuthorityRecord(TElDNSStartOfAuthorityRecordHandle handle, TElOwnHandle ownHandle) : TElDNSResourceRecord(handle, ownHandle)
{
}

TElDNSStartOfAuthorityRecord::TElDNSStartOfAuthorityRecord() : TElDNSResourceRecord(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSStartOfAuthorityRecord_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSSTARTOFAUTHORITYRECORD */

#ifdef SB_USE_CLASS_TELDNSWELLKNOWNSERVICERECORD

SB_INLINE void TElDNSWellKnownServiceRecord::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSWellKnownServiceRecord_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSWellKnownServiceRecord::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSWellKnownServiceRecord_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSWellKnownServiceRecord::Clear()
{
	SBCheckError(TElDNSWellKnownServiceRecord_Clear(_Handle));
}

SB_INLINE void TElDNSWellKnownServiceRecord::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSWellKnownServiceRecord_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

void TElDNSWellKnownServiceRecord::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSWellKnownServiceRecord_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(380583622, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSWellKnownServiceRecord::set_Address(const std::string &Value)
{
	SBCheckError(TElDNSWellKnownServiceRecord_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElDNSWellKnownServiceRecord::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElDNSWellKnownServiceRecord_get_Count(_Handle, &OutResult));
	return OutResult;
}

bool TElDNSWellKnownServiceRecord::get_Bits(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSWellKnownServiceRecord_get_Bits(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSWellKnownServiceRecord::set_Bits(int32_t Index, bool Value)
{
	SBCheckError(TElDNSWellKnownServiceRecord_set_Bits(_Handle, Index, (int8_t)Value));
}

SB_INLINE uint8_t TElDNSWellKnownServiceRecord::get_Protocol()
{
	uint8_t OutResult;
	SBCheckError(TElDNSWellKnownServiceRecord_get_Protocol(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSWellKnownServiceRecord::set_Protocol(uint8_t Value)
{
	SBCheckError(TElDNSWellKnownServiceRecord_set_Protocol(_Handle, Value));
}

TElDNSWellKnownServiceRecord::TElDNSWellKnownServiceRecord(TElDNSWellKnownServiceRecordHandle handle, TElOwnHandle ownHandle) : TElDNSResourceRecord(handle, ownHandle)
{
}

TElDNSWellKnownServiceRecord::TElDNSWellKnownServiceRecord() : TElDNSResourceRecord(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSWellKnownServiceRecord_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSWELLKNOWNSERVICERECORD */

#ifdef SB_USE_CLASS_TELDNSDOMAINNAMEPOINTERRECORD

SB_INLINE void TElDNSDomainNamePointerRecord::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSDomainNamePointerRecord_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSDomainNamePointerRecord::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSDomainNamePointerRecord_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSDomainNamePointerRecord::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSDomainNamePointerRecord_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

void TElDNSDomainNamePointerRecord::get_Domain(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSDomainNamePointerRecord_get_Domain(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1607802630, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSDomainNamePointerRecord::set_Domain(const std::string &Value)
{
	SBCheckError(TElDNSDomainNamePointerRecord_set_Domain(_Handle, Value.data(), (int32_t)Value.length()));
}

TElDNSDomainNamePointerRecord::TElDNSDomainNamePointerRecord(TElDNSDomainNamePointerRecordHandle handle, TElOwnHandle ownHandle) : TElDNSResourceRecord(handle, ownHandle)
{
}

TElDNSDomainNamePointerRecord::TElDNSDomainNamePointerRecord() : TElDNSResourceRecord(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSDomainNamePointerRecord_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSDOMAINNAMEPOINTERRECORD */

#ifdef SB_USE_CLASS_TELDNSHOSTINFORECORD

SB_INLINE void TElDNSHostInfoRecord::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSHostInfoRecord_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSHostInfoRecord::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSHostInfoRecord_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSHostInfoRecord::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSHostInfoRecord_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

void TElDNSHostInfoRecord::get_CPU(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSHostInfoRecord_get_CPU(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2031564919, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSHostInfoRecord::set_CPU(const std::string &Value)
{
	SBCheckError(TElDNSHostInfoRecord_set_CPU(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDNSHostInfoRecord::get_OS(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSHostInfoRecord_get_OS(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-29569558, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSHostInfoRecord::set_OS(const std::string &Value)
{
	SBCheckError(TElDNSHostInfoRecord_set_OS(_Handle, Value.data(), (int32_t)Value.length()));
}

TElDNSHostInfoRecord::TElDNSHostInfoRecord(TElDNSHostInfoRecordHandle handle, TElOwnHandle ownHandle) : TElDNSResourceRecord(handle, ownHandle)
{
}

TElDNSHostInfoRecord::TElDNSHostInfoRecord() : TElDNSResourceRecord(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSHostInfoRecord_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSHOSTINFORECORD */

#ifdef SB_USE_CLASS_TELDNSMAILINFORECORD

SB_INLINE void TElDNSMailInfoRecord::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSMailInfoRecord_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSMailInfoRecord::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSMailInfoRecord_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSMailInfoRecord::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSMailInfoRecord_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

void TElDNSMailInfoRecord::get_MailboxForErrors(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSMailInfoRecord_get_MailboxForErrors(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-365231976, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSMailInfoRecord::set_MailboxForErrors(const std::string &Value)
{
	SBCheckError(TElDNSMailInfoRecord_set_MailboxForErrors(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDNSMailInfoRecord::get_ResponsibleMailbox(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSMailInfoRecord_get_ResponsibleMailbox(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(586135272, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSMailInfoRecord::set_ResponsibleMailbox(const std::string &Value)
{
	SBCheckError(TElDNSMailInfoRecord_set_ResponsibleMailbox(_Handle, Value.data(), (int32_t)Value.length()));
}

TElDNSMailInfoRecord::TElDNSMailInfoRecord(TElDNSMailInfoRecordHandle handle, TElOwnHandle ownHandle) : TElDNSResourceRecord(handle, ownHandle)
{
}

TElDNSMailInfoRecord::TElDNSMailInfoRecord() : TElDNSResourceRecord(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSMailInfoRecord_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSMAILINFORECORD */

#ifdef SB_USE_CLASS_TELDNSMAILEXCHANGERECORD

SB_INLINE void TElDNSMailExchangeRecord::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSMailExchangeRecord_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSMailExchangeRecord::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSMailExchangeRecord_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSMailExchangeRecord::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSMailExchangeRecord_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

void TElDNSMailExchangeRecord::get_Exchange(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSMailExchangeRecord_get_Exchange(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-230493452, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSMailExchangeRecord::set_Exchange(const std::string &Value)
{
	SBCheckError(TElDNSMailExchangeRecord_set_Exchange(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE uint16_t TElDNSMailExchangeRecord::get_Preference()
{
	uint16_t OutResult;
	SBCheckError(TElDNSMailExchangeRecord_get_Preference(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSMailExchangeRecord::set_Preference(uint16_t Value)
{
	SBCheckError(TElDNSMailExchangeRecord_set_Preference(_Handle, Value));
}

TElDNSMailExchangeRecord::TElDNSMailExchangeRecord(TElDNSMailExchangeRecordHandle handle, TElOwnHandle ownHandle) : TElDNSResourceRecord(handle, ownHandle)
{
}

TElDNSMailExchangeRecord::TElDNSMailExchangeRecord() : TElDNSResourceRecord(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSMailExchangeRecord_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSMAILEXCHANGERECORD */

#ifdef SB_USE_CLASS_TELDNSTEXTSTRINGSRECORD

SB_INLINE void TElDNSTextStringsRecord::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSTextStringsRecord_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSTextStringsRecord::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSTextStringsRecord_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSTextStringsRecord::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSTextStringsRecord_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

SB_INLINE int32_t TElDNSTextStringsRecord::Add(const std::string &S)
{
	int32_t OutResult;
	SBCheckError(TElDNSTextStringsRecord_Add(_Handle, S.data(), (int32_t)S.length(), &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSTextStringsRecord::Clear()
{
	SBCheckError(TElDNSTextStringsRecord_Clear(_Handle));
}

SB_INLINE void TElDNSTextStringsRecord::Delete(int32_t Index)
{
	SBCheckError(TElDNSTextStringsRecord_Delete(_Handle, Index));
}

SB_INLINE int32_t TElDNSTextStringsRecord::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElDNSTextStringsRecord_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElDNSTextStringsRecord::get_Lines(int32_t Index, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSTextStringsRecord_get_Lines(_Handle, Index, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(149528278, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSTextStringsRecord::set_Lines(int32_t Index, const std::string &Value)
{
	SBCheckError(TElDNSTextStringsRecord_set_Lines(_Handle, Index, Value.data(), (int32_t)Value.length()));
}

TElDNSTextStringsRecord::TElDNSTextStringsRecord(TElDNSTextStringsRecordHandle handle, TElOwnHandle ownHandle) : TElDNSResourceRecord(handle, ownHandle)
{
}

TElDNSTextStringsRecord::TElDNSTextStringsRecord() : TElDNSResourceRecord(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSTextStringsRecord_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSTEXTSTRINGSRECORD */

#ifdef SB_USE_CLASS_TELDNSIPV6ADDRESSRECORD

SB_INLINE void TElDNSIPv6AddressRecord::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSIPv6AddressRecord_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSIPv6AddressRecord::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSIPv6AddressRecord_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSIPv6AddressRecord::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSIPv6AddressRecord_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

void TElDNSIPv6AddressRecord::get_Address(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSIPv6AddressRecord_get_Address(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-555711352, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSIPv6AddressRecord::set_Address(const std::string &Value)
{
	SBCheckError(TElDNSIPv6AddressRecord_set_Address(_Handle, Value.data(), (int32_t)Value.length()));
}

TElDNSIPv6AddressRecord::TElDNSIPv6AddressRecord(TElDNSIPv6AddressRecordHandle handle, TElOwnHandle ownHandle) : TElDNSResourceRecord(handle, ownHandle)
{
}

TElDNSIPv6AddressRecord::TElDNSIPv6AddressRecord() : TElDNSResourceRecord(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSIPv6AddressRecord_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSIPV6ADDRESSRECORD */

#ifdef SB_USE_CLASS_TELDNSSERVICELOCATIONRECORD

SB_INLINE void TElDNSServiceLocationRecord::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSServiceLocationRecord_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSServiceLocationRecord::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSServiceLocationRecord_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSServiceLocationRecord::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSServiceLocationRecord_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

void TElDNSServiceLocationRecord::get_Domain(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSServiceLocationRecord_get_Domain(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1781625351, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSServiceLocationRecord::set_Domain(const std::string &Value)
{
	SBCheckError(TElDNSServiceLocationRecord_set_Domain(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE uint16_t TElDNSServiceLocationRecord::get_Port()
{
	uint16_t OutResult;
	SBCheckError(TElDNSServiceLocationRecord_get_Port(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSServiceLocationRecord::set_Port(uint16_t Value)
{
	SBCheckError(TElDNSServiceLocationRecord_set_Port(_Handle, Value));
}

SB_INLINE uint16_t TElDNSServiceLocationRecord::get_Priority()
{
	uint16_t OutResult;
	SBCheckError(TElDNSServiceLocationRecord_get_Priority(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSServiceLocationRecord::set_Priority(uint16_t Value)
{
	SBCheckError(TElDNSServiceLocationRecord_set_Priority(_Handle, Value));
}

void TElDNSServiceLocationRecord::get_Protocol(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSServiceLocationRecord_get_Protocol(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1638400340, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSServiceLocationRecord::set_Protocol(const std::string &Value)
{
	SBCheckError(TElDNSServiceLocationRecord_set_Protocol(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDNSServiceLocationRecord::get_Service(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSServiceLocationRecord_get_Service(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(988061976, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSServiceLocationRecord::set_Service(const std::string &Value)
{
	SBCheckError(TElDNSServiceLocationRecord_set_Service(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElDNSServiceLocationRecord::get_Target(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSServiceLocationRecord_get_Target(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1946729488, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSServiceLocationRecord::set_Target(const std::string &Value)
{
	SBCheckError(TElDNSServiceLocationRecord_set_Target(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE uint16_t TElDNSServiceLocationRecord::get_Weight()
{
	uint16_t OutResult;
	SBCheckError(TElDNSServiceLocationRecord_get_Weight(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSServiceLocationRecord::set_Weight(uint16_t Value)
{
	SBCheckError(TElDNSServiceLocationRecord_set_Weight(_Handle, Value));
}

TElDNSServiceLocationRecord::TElDNSServiceLocationRecord(TElDNSServiceLocationRecordHandle handle, TElOwnHandle ownHandle) : TElDNSResourceRecord(handle, ownHandle)
{
}

TElDNSServiceLocationRecord::TElDNSServiceLocationRecord() : TElDNSResourceRecord(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSServiceLocationRecord_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSSERVICELOCATIONRECORD */

#ifdef SB_USE_CLASS_TELDNSEXTENSIONSRECORD

SB_INLINE void TElDNSExtensionsRecord::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSExtensionsRecord_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSExtensionsRecord::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSExtensionsRecord_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSExtensionsRecord::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSExtensionsRecord_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElDNSExtensionsRecord::Write(TStream &Stream)
{
	SBCheckError(TElDNSExtensionsRecord_Write(_Handle, Stream.getHandle()));
}

SB_INLINE void TElDNSExtensionsRecord::Write(TStream *Stream)
{
	SBCheckError(TElDNSExtensionsRecord_Write(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElDNSExtensionsRecord::get_DNSSECOK()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSExtensionsRecord_get_DNSSECOK(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSExtensionsRecord::set_DNSSECOK(bool Value)
{
	SBCheckError(TElDNSExtensionsRecord_set_DNSSECOK(_Handle, (int8_t)Value));
}

SB_INLINE uint16_t TElDNSExtensionsRecord::get_Flags()
{
	uint16_t OutResult;
	SBCheckError(TElDNSExtensionsRecord_get_Flags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSExtensionsRecord::set_Flags(uint16_t Value)
{
	SBCheckError(TElDNSExtensionsRecord_set_Flags(_Handle, Value));
}

SB_INLINE uint16_t TElDNSExtensionsRecord::get_PayloadSize()
{
	uint16_t OutResult;
	SBCheckError(TElDNSExtensionsRecord_get_PayloadSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSExtensionsRecord::set_PayloadSize(uint16_t Value)
{
	SBCheckError(TElDNSExtensionsRecord_set_PayloadSize(_Handle, Value));
}

SB_INLINE uint16_t TElDNSExtensionsRecord::get_ResponseCode()
{
	uint16_t OutResult;
	SBCheckError(TElDNSExtensionsRecord_get_ResponseCode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSExtensionsRecord::set_ResponseCode(uint16_t Value)
{
	SBCheckError(TElDNSExtensionsRecord_set_ResponseCode(_Handle, Value));
}

SB_INLINE uint8_t TElDNSExtensionsRecord::get_Version()
{
	uint8_t OutResult;
	SBCheckError(TElDNSExtensionsRecord_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSExtensionsRecord::set_Version(uint8_t Value)
{
	SBCheckError(TElDNSExtensionsRecord_set_Version(_Handle, Value));
}

TElDNSExtensionsRecord::TElDNSExtensionsRecord(TElDNSExtensionsRecordHandle handle, TElOwnHandle ownHandle) : TElDNSResourceRecord(handle, ownHandle)
{
}

TElDNSExtensionsRecord::TElDNSExtensionsRecord() : TElDNSResourceRecord(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSExtensionsRecord_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSEXTENSIONSRECORD */

#ifdef SB_USE_CLASS_TELDNSPUBLICKEYRECORD

SB_INLINE void TElDNSPublicKeyRecord::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSPublicKeyRecord_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSPublicKeyRecord::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSPublicKeyRecord_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSPublicKeyRecord::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSPublicKeyRecord_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

SB_INLINE uint8_t TElDNSPublicKeyRecord::get_Algorithm()
{
	uint8_t OutResult;
	SBCheckError(TElDNSPublicKeyRecord_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSPublicKeyRecord::set_Algorithm(uint8_t Value)
{
	SBCheckError(TElDNSPublicKeyRecord_set_Algorithm(_Handle, Value));
}

SB_INLINE uint16_t TElDNSPublicKeyRecord::get_Flags()
{
	uint16_t OutResult;
	SBCheckError(TElDNSPublicKeyRecord_get_Flags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSPublicKeyRecord::set_Flags(uint16_t Value)
{
	SBCheckError(TElDNSPublicKeyRecord_set_Flags(_Handle, Value));
}

SB_INLINE uint16_t TElDNSPublicKeyRecord::get_KeyTag()
{
	uint16_t OutResult;
	SBCheckError(TElDNSPublicKeyRecord_get_KeyTag(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElDNSPublicKeyRecord::get_Protocol()
{
	uint8_t OutResult;
	SBCheckError(TElDNSPublicKeyRecord_get_Protocol(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSPublicKeyRecord::set_Protocol(uint8_t Value)
{
	SBCheckError(TElDNSPublicKeyRecord_set_Protocol(_Handle, Value));
}

void TElDNSPublicKeyRecord::get_PublicKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDNSPublicKeyRecord_get_PublicKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-674564403, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSPublicKeyRecord::set_PublicKey(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDNSPublicKeyRecord_set_PublicKey(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElDNSPublicKeyRecord::get_SecureEntryPoint()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSPublicKeyRecord_get_SecureEntryPoint(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSPublicKeyRecord::set_SecureEntryPoint(bool Value)
{
	SBCheckError(TElDNSPublicKeyRecord_set_SecureEntryPoint(_Handle, (int8_t)Value));
}

bool TElDNSPublicKeyRecord::get_ZoneKey()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSPublicKeyRecord_get_ZoneKey(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSPublicKeyRecord::set_ZoneKey(bool Value)
{
	SBCheckError(TElDNSPublicKeyRecord_set_ZoneKey(_Handle, (int8_t)Value));
}

TElDNSPublicKeyRecord::TElDNSPublicKeyRecord(TElDNSPublicKeyRecordHandle handle, TElOwnHandle ownHandle) : TElDNSResourceRecord(handle, ownHandle)
{
}

TElDNSPublicKeyRecord::TElDNSPublicKeyRecord() : TElDNSResourceRecord(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSPublicKeyRecord_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSPUBLICKEYRECORD */

#ifdef SB_USE_CLASS_TELDNSDELEGATIONSIGNERRECORD

SB_INLINE void TElDNSDelegationSignerRecord::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSDelegationSignerRecord_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSDelegationSignerRecord::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSDelegationSignerRecord_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSDelegationSignerRecord::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSDelegationSignerRecord_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

#ifdef SB_USE_CLASS_TELDNSPUBLICKEYRECORD
SB_INLINE int32_t TElDNSDelegationSignerRecord::Validate(TElDNSPublicKeyRecord &Key)
{
	int32_t OutResult;
	SBCheckError(TElDNSDelegationSignerRecord_Validate(_Handle, Key.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDNSDelegationSignerRecord::Validate(TElDNSPublicKeyRecord *Key)
{
	int32_t OutResult;
	SBCheckError(TElDNSDelegationSignerRecord_Validate(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDNSPUBLICKEYRECORD */

SB_INLINE uint8_t TElDNSDelegationSignerRecord::get_Algorithm()
{
	uint8_t OutResult;
	SBCheckError(TElDNSDelegationSignerRecord_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSDelegationSignerRecord::set_Algorithm(uint8_t Value)
{
	SBCheckError(TElDNSDelegationSignerRecord_set_Algorithm(_Handle, Value));
}

void TElDNSDelegationSignerRecord::get_Digest(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDNSDelegationSignerRecord_get_Digest(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(332889387, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSDelegationSignerRecord::set_Digest(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDNSDelegationSignerRecord_set_Digest(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE uint8_t TElDNSDelegationSignerRecord::get_DigestType()
{
	uint8_t OutResult;
	SBCheckError(TElDNSDelegationSignerRecord_get_DigestType(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSDelegationSignerRecord::set_DigestType(uint8_t Value)
{
	SBCheckError(TElDNSDelegationSignerRecord_set_DigestType(_Handle, Value));
}

SB_INLINE uint16_t TElDNSDelegationSignerRecord::get_KeyTag()
{
	uint16_t OutResult;
	SBCheckError(TElDNSDelegationSignerRecord_get_KeyTag(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSDelegationSignerRecord::set_KeyTag(uint16_t Value)
{
	SBCheckError(TElDNSDelegationSignerRecord_set_KeyTag(_Handle, Value));
}

TElDNSDelegationSignerRecord::TElDNSDelegationSignerRecord(TElDNSDelegationSignerRecordHandle handle, TElOwnHandle ownHandle) : TElDNSResourceRecord(handle, ownHandle)
{
}

TElDNSDelegationSignerRecord::TElDNSDelegationSignerRecord() : TElDNSResourceRecord(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSDelegationSignerRecord_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSDELEGATIONSIGNERRECORD */

#ifdef SB_USE_CLASS_TELDNSSIGNATURERECORD

SB_INLINE void TElDNSSignatureRecord::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSSignatureRecord_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSSignatureRecord::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSSignatureRecord_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSSignatureRecord::Prepare(const std::string &CanonicalName, uint32_t AOriginalTTL)
{
	SBCheckError(TElDNSSignatureRecord_Prepare(_Handle, CanonicalName.data(), (int32_t)CanonicalName.length(), AOriginalTTL));
}

SB_INLINE void TElDNSSignatureRecord::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSSignatureRecord_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

SB_INLINE int32_t TElDNSSignatureRecord::Validate()
{
	int32_t OutResult;
	SBCheckError(TElDNSSignatureRecord_Validate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t TElDNSSignatureRecord::get_Algorithm()
{
	uint8_t OutResult;
	SBCheckError(TElDNSSignatureRecord_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSSignatureRecord::set_Algorithm(uint8_t Value)
{
	SBCheckError(TElDNSSignatureRecord_set_Algorithm(_Handle, Value));
}

SB_INLINE uint16_t TElDNSSignatureRecord::get_CoveredCode()
{
	uint16_t OutResult;
	SBCheckError(TElDNSSignatureRecord_get_CoveredCode(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSSignatureRecord::set_CoveredCode(uint16_t Value)
{
	SBCheckError(TElDNSSignatureRecord_set_CoveredCode(_Handle, Value));
}

TSBDNSResourceType TElDNSSignatureRecord::get_CoveredType()
{
	TSBDNSResourceTypeRaw OutResultRaw = 0;
	SBCheckError(TElDNSSignatureRecord_get_CoveredType(_Handle, &OutResultRaw));
	return (TSBDNSResourceType)OutResultRaw;
}

SB_INLINE void TElDNSSignatureRecord::set_CoveredType(TSBDNSResourceType Value)
{
	SBCheckError(TElDNSSignatureRecord_set_CoveredType(_Handle, (TSBDNSResourceTypeRaw)Value));
}

SB_INLINE int64_t TElDNSSignatureRecord::get_Expiration()
{
	int64_t OutResult;
	SBCheckError(TElDNSSignatureRecord_get_Expiration(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSSignatureRecord::set_Expiration(int64_t Value)
{
	SBCheckError(TElDNSSignatureRecord_set_Expiration(_Handle, Value));
}

SB_INLINE int64_t TElDNSSignatureRecord::get_Inception()
{
	int64_t OutResult;
	SBCheckError(TElDNSSignatureRecord_get_Inception(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSSignatureRecord::set_Inception(int64_t Value)
{
	SBCheckError(TElDNSSignatureRecord_set_Inception(_Handle, Value));
}

SB_INLINE uint16_t TElDNSSignatureRecord::get_KeyTag()
{
	uint16_t OutResult;
	SBCheckError(TElDNSSignatureRecord_get_KeyTag(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSSignatureRecord::set_KeyTag(uint16_t Value)
{
	SBCheckError(TElDNSSignatureRecord_set_KeyTag(_Handle, Value));
}

SB_INLINE uint8_t TElDNSSignatureRecord::get_Labels()
{
	uint8_t OutResult;
	SBCheckError(TElDNSSignatureRecord_get_Labels(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSSignatureRecord::set_Labels(uint8_t Value)
{
	SBCheckError(TElDNSSignatureRecord_set_Labels(_Handle, Value));
}

SB_INLINE uint32_t TElDNSSignatureRecord::get_OriginalTTL()
{
	uint32_t OutResult;
	SBCheckError(TElDNSSignatureRecord_get_OriginalTTL(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSSignatureRecord::set_OriginalTTL(uint32_t Value)
{
	SBCheckError(TElDNSSignatureRecord_set_OriginalTTL(_Handle, Value));
}

void TElDNSSignatureRecord::get_Signature(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDNSSignatureRecord_get_Signature(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1952464262, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSSignatureRecord::set_Signature(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDNSSignatureRecord_set_Signature(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElDNSSignatureRecord::get_Signer(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSSignatureRecord_get_Signer(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2006861517, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSSignatureRecord::set_Signer(const std::string &Value)
{
	SBCheckError(TElDNSSignatureRecord_set_Signer(_Handle, Value.data(), (int32_t)Value.length()));
}

TElDNSSignatureRecord::TElDNSSignatureRecord(TElDNSSignatureRecordHandle handle, TElOwnHandle ownHandle) : TElDNSResourceRecord(handle, ownHandle)
{
}

TElDNSSignatureRecord::TElDNSSignatureRecord() : TElDNSResourceRecord(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSSignatureRecord_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSSIGNATURERECORD */

#ifdef SB_USE_CLASS_TELDNSNEXTSECURERECORD

SB_INLINE void TElDNSNextSecureRecord::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSNextSecureRecord_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSNextSecureRecord::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSNextSecureRecord_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSNextSecureRecord::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSNextSecureRecord_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

void TElDNSNextSecureRecord::get_NextDomainName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElDNSNextSecureRecord_get_NextDomainName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1985733955, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSNextSecureRecord::set_NextDomainName(const std::string &Value)
{
	SBCheckError(TElDNSNextSecureRecord_set_NextDomainName(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElDNSNextSecureRecord::get_ResourceByCode(uint16_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSNextSecureRecord_get_ResourceByCode(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSNextSecureRecord::set_ResourceByCode(uint16_t Index, bool Value)
{
	SBCheckError(TElDNSNextSecureRecord_set_ResourceByCode(_Handle, Index, (int8_t)Value));
}

bool TElDNSNextSecureRecord::get_ResourceByType(TSBDNSResourceType Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSNextSecureRecord_get_ResourceByType(_Handle, (TSBDNSResourceTypeRaw)Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSNextSecureRecord::set_ResourceByType(TSBDNSResourceType Index, bool Value)
{
	SBCheckError(TElDNSNextSecureRecord_set_ResourceByType(_Handle, (TSBDNSResourceTypeRaw)Index, (int8_t)Value));
}

TElDNSNextSecureRecord::TElDNSNextSecureRecord(TElDNSNextSecureRecordHandle handle, TElOwnHandle ownHandle) : TElDNSResourceRecord(handle, ownHandle)
{
}

TElDNSNextSecureRecord::TElDNSNextSecureRecord() : TElDNSResourceRecord(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSNextSecureRecord_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSNEXTSECURERECORD */

#ifdef SB_USE_CLASS_TELDNSNEXTSECURE3RECORD

SB_INLINE void TElDNSNextSecure3Record::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSNextSecure3Record_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSNextSecure3Record::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSNextSecure3Record_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSNextSecure3Record::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSNextSecure3Record_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

SB_INLINE uint8_t TElDNSNextSecure3Record::get_Algorithm()
{
	uint8_t OutResult;
	SBCheckError(TElDNSNextSecure3Record_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSNextSecure3Record::set_Algorithm(uint8_t Value)
{
	SBCheckError(TElDNSNextSecure3Record_set_Algorithm(_Handle, Value));
}

SB_INLINE uint8_t TElDNSNextSecure3Record::get_Flags()
{
	uint8_t OutResult;
	SBCheckError(TElDNSNextSecure3Record_get_Flags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSNextSecure3Record::set_Flags(uint8_t Value)
{
	SBCheckError(TElDNSNextSecure3Record_set_Flags(_Handle, Value));
}

SB_INLINE uint16_t TElDNSNextSecure3Record::get_Iterations()
{
	uint16_t OutResult;
	SBCheckError(TElDNSNextSecure3Record_get_Iterations(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSNextSecure3Record::set_Iterations(uint16_t Value)
{
	SBCheckError(TElDNSNextSecure3Record_set_Iterations(_Handle, Value));
}

void TElDNSNextSecure3Record::get_NextOwnerName(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDNSNextSecure3Record_get_NextOwnerName(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1260123110, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSNextSecure3Record::set_NextOwnerName(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDNSNextSecure3Record_set_NextOwnerName(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElDNSNextSecure3Record::get_OptOut()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSNextSecure3Record_get_OptOut(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSNextSecure3Record::set_OptOut(bool Value)
{
	SBCheckError(TElDNSNextSecure3Record_set_OptOut(_Handle, (int8_t)Value));
}

bool TElDNSNextSecure3Record::get_ResourceByCode(uint16_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSNextSecure3Record_get_ResourceByCode(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSNextSecure3Record::set_ResourceByCode(uint16_t Index, bool Value)
{
	SBCheckError(TElDNSNextSecure3Record_set_ResourceByCode(_Handle, Index, (int8_t)Value));
}

bool TElDNSNextSecure3Record::get_ResourceByType(TSBDNSResourceType Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSNextSecure3Record_get_ResourceByType(_Handle, (TSBDNSResourceTypeRaw)Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSNextSecure3Record::set_ResourceByType(TSBDNSResourceType Index, bool Value)
{
	SBCheckError(TElDNSNextSecure3Record_set_ResourceByType(_Handle, (TSBDNSResourceTypeRaw)Index, (int8_t)Value));
}

void TElDNSNextSecure3Record::get_Salt(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDNSNextSecure3Record_get_Salt(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1503250812, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSNextSecure3Record::set_Salt(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDNSNextSecure3Record_set_Salt(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElDNSNextSecure3Record::TElDNSNextSecure3Record(TElDNSNextSecure3RecordHandle handle, TElOwnHandle ownHandle) : TElDNSResourceRecord(handle, ownHandle)
{
}

TElDNSNextSecure3Record::TElDNSNextSecure3Record() : TElDNSResourceRecord(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSNextSecure3Record_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSNEXTSECURE3RECORD */

#ifdef SB_USE_CLASS_TELDNSNEXTSECURE3PARAMRECORD

SB_INLINE void TElDNSNextSecure3ParamRecord::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSNextSecure3ParamRecord_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSNextSecure3ParamRecord::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSNextSecure3ParamRecord_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSNextSecure3ParamRecord::Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset)
{
	SBCheckError(TElDNSNextSecure3ParamRecord_Read(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset));
}

SB_INLINE uint8_t TElDNSNextSecure3ParamRecord::get_Algorithm()
{
	uint8_t OutResult;
	SBCheckError(TElDNSNextSecure3ParamRecord_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSNextSecure3ParamRecord::set_Algorithm(uint8_t Value)
{
	SBCheckError(TElDNSNextSecure3ParamRecord_set_Algorithm(_Handle, Value));
}

SB_INLINE uint8_t TElDNSNextSecure3ParamRecord::get_Flags()
{
	uint8_t OutResult;
	SBCheckError(TElDNSNextSecure3ParamRecord_get_Flags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSNextSecure3ParamRecord::set_Flags(uint8_t Value)
{
	SBCheckError(TElDNSNextSecure3ParamRecord_set_Flags(_Handle, Value));
}

SB_INLINE uint16_t TElDNSNextSecure3ParamRecord::get_Iterations()
{
	uint16_t OutResult;
	SBCheckError(TElDNSNextSecure3ParamRecord_get_Iterations(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDNSNextSecure3ParamRecord::set_Iterations(uint16_t Value)
{
	SBCheckError(TElDNSNextSecure3ParamRecord_set_Iterations(_Handle, Value));
}

bool TElDNSNextSecure3ParamRecord::get_OptOut()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSNextSecure3ParamRecord_get_OptOut(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSNextSecure3ParamRecord::set_OptOut(bool Value)
{
	SBCheckError(TElDNSNextSecure3ParamRecord_set_OptOut(_Handle, (int8_t)Value));
}

void TElDNSNextSecure3ParamRecord::get_Salt(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDNSNextSecure3ParamRecord_get_Salt(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(826528216, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDNSNextSecure3ParamRecord::set_Salt(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDNSNextSecure3ParamRecord_set_Salt(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElDNSNextSecure3ParamRecord::TElDNSNextSecure3ParamRecord(TElDNSNextSecure3ParamRecordHandle handle, TElOwnHandle ownHandle) : TElDNSResourceRecord(handle, ownHandle)
{
}

TElDNSNextSecure3ParamRecord::TElDNSNextSecure3ParamRecord() : TElDNSResourceRecord(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDNSNextSecure3ParamRecord_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDNSNEXTSECURE3PARAMRECORD */

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORDSET

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORD
SB_INLINE TElDNSResourceRecordHandle TElDNSResourceRecordSet::Add(TSBDNSResourceType ResourceType)
{
	TElDNSResourceRecordHandle OutResult;
	SBCheckError(TElDNSResourceRecordSet_Add(_Handle, (TSBDNSResourceTypeRaw)ResourceType, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORD */

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORD
SB_INLINE int32_t TElDNSResourceRecordSet::Add(TElDNSResourceRecord &ResourceRecord)
{
	int32_t OutResult;
	SBCheckError(TElDNSResourceRecordSet_Add_1(_Handle, ResourceRecord.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDNSResourceRecordSet::Add(TElDNSResourceRecord *ResourceRecord)
{
	int32_t OutResult;
	SBCheckError(TElDNSResourceRecordSet_Add_1(_Handle, (ResourceRecord != NULL) ? ResourceRecord->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORD */

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORD
SB_INLINE int32_t TElDNSResourceRecordSet::AddCopy(TElDNSResourceRecord &ResourceRecord)
{
	int32_t OutResult;
	SBCheckError(TElDNSResourceRecordSet_AddCopy(_Handle, ResourceRecord.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDNSResourceRecordSet::AddCopy(TElDNSResourceRecord *ResourceRecord)
{
	int32_t OutResult;
	SBCheckError(TElDNSResourceRecordSet_AddCopy(_Handle, (ResourceRecord != NULL) ? ResourceRecord->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORD */

SB_INLINE void TElDNSResourceRecordSet::Assign(TPersistent &Source)
{
	SBCheckError(TElDNSResourceRecordSet_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElDNSResourceRecordSet::Assign(TPersistent *Source)
{
	SBCheckError(TElDNSResourceRecordSet_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElDNSResourceRecordSet::Clear()
{
	SBCheckError(TElDNSResourceRecordSet_Clear(_Handle));
}

SB_INLINE void TElDNSResourceRecordSet::Delete(int32_t Index)
{
	SBCheckError(TElDNSResourceRecordSet_Delete(_Handle, Index));
}

SB_INLINE int32_t TElDNSResourceRecordSet::Find(const std::string &Criteria, TSBDNSResourceType ResourceType, int32_t Start)
{
	int32_t OutResult;
	SBCheckError(TElDNSResourceRecordSet_Find(_Handle, Criteria.data(), (int32_t)Criteria.length(), (TSBDNSResourceTypeRaw)ResourceType, Start, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDNSResourceRecordSet::FindAny(TSBDNSResourceType ResourceType, int32_t Start)
{
	int32_t OutResult;
	SBCheckError(TElDNSResourceRecordSet_FindAny(_Handle, (TSBDNSResourceTypeRaw)ResourceType, Start, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDNSResourceRecordSet::FindKey(const std::string &Owner, uint16_t KeyTag, uint8_t Algorithm, int32_t Start)
{
	int32_t OutResult;
	SBCheckError(TElDNSResourceRecordSet_FindKey(_Handle, Owner.data(), (int32_t)Owner.length(), KeyTag, Algorithm, Start, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDNSResourceRecordSet::FindSelfSignedSignature(const std::string &Criteria, TSBDNSResourceType CoveredType, int32_t Start)
{
	int32_t OutResult;
	SBCheckError(TElDNSResourceRecordSet_FindSelfSignedSignature(_Handle, Criteria.data(), (int32_t)Criteria.length(), (TSBDNSResourceTypeRaw)CoveredType, Start, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDNSResourceRecordSet::FindSignature(const std::string &Criteria, TSBDNSResourceType CoveredType, int32_t Start)
{
	int32_t OutResult;
	SBCheckError(TElDNSResourceRecordSet_FindSignature(_Handle, Criteria.data(), (int32_t)Criteria.length(), (TSBDNSResourceTypeRaw)CoveredType, Start, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELDNSPUBLICKEYRECORD
SB_INLINE int32_t TElDNSResourceRecordSet::FindSignature(const std::string &Criteria, TSBDNSResourceType CoveredType, TElDNSPublicKeyRecord &Key, int32_t Start)
{
	int32_t OutResult;
	SBCheckError(TElDNSResourceRecordSet_FindSignature_1(_Handle, Criteria.data(), (int32_t)Criteria.length(), (TSBDNSResourceTypeRaw)CoveredType, Key.getHandle(), Start, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDNSResourceRecordSet::FindSignature(const std::string &Criteria, TSBDNSResourceType CoveredType, TElDNSPublicKeyRecord *Key, int32_t Start)
{
	int32_t OutResult;
	SBCheckError(TElDNSResourceRecordSet_FindSignature_1(_Handle, Criteria.data(), (int32_t)Criteria.length(), (TSBDNSResourceTypeRaw)CoveredType, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, Start, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDNSPUBLICKEYRECORD */

SB_INLINE int32_t TElDNSResourceRecordSet::FindSignatureByUpperLevel(const std::string &Criteria, TSBDNSResourceType CoveredType, int32_t Start)
{
	int32_t OutResult;
	SBCheckError(TElDNSResourceRecordSet_FindSignatureByUpperLevel(_Handle, Criteria.data(), (int32_t)Criteria.length(), (TSBDNSResourceTypeRaw)CoveredType, Start, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORD
SB_INLINE int32_t TElDNSResourceRecordSet::IndexOf(TElDNSResourceRecord &Resource)
{
	int32_t OutResult;
	SBCheckError(TElDNSResourceRecordSet_IndexOf(_Handle, Resource.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDNSResourceRecordSet::IndexOf(TElDNSResourceRecord *Resource)
{
	int32_t OutResult;
	SBCheckError(TElDNSResourceRecordSet_IndexOf(_Handle, (Resource != NULL) ? Resource->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORD */

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORD
SB_INLINE TElDNSResourceRecordHandle TElDNSResourceRecordSet::Insert(int32_t Index, TSBDNSResourceType ResourceType)
{
	TElDNSResourceRecordHandle OutResult;
	SBCheckError(TElDNSResourceRecordSet_Insert(_Handle, Index, (TSBDNSResourceTypeRaw)ResourceType, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORD */

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORD
SB_INLINE int32_t TElDNSResourceRecordSet::Remove(TElDNSResourceRecord &Resource)
{
	int32_t OutResult;
	SBCheckError(TElDNSResourceRecordSet_Remove(_Handle, Resource.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDNSResourceRecordSet::Remove(TElDNSResourceRecord *Resource)
{
	int32_t OutResult;
	SBCheckError(TElDNSResourceRecordSet_Remove(_Handle, (Resource != NULL) ? Resource->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORD */

SB_INLINE void TElDNSResourceRecordSet::Sort()
{
	SBCheckError(TElDNSResourceRecordSet_Sort(_Handle));
}

#ifdef SB_USE_CLASSES_TELDNSPUBLICKEYRECORD_AND_TELDNSSIGNATURERECORD
SB_INLINE int32_t TElDNSResourceRecordSet::Verify(TElDNSSignatureRecord &Signature, TElDNSPublicKeyRecord &Key)
{
	int32_t OutResult;
	SBCheckError(TElDNSResourceRecordSet_Verify(_Handle, Signature.getHandle(), Key.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElDNSResourceRecordSet::Verify(TElDNSSignatureRecord *Signature, TElDNSPublicKeyRecord *Key)
{
	int32_t OutResult;
	SBCheckError(TElDNSResourceRecordSet_Verify(_Handle, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDNSPUBLICKEYRECORD_AND_TELDNSSIGNATURERECORD */

SB_INLINE int32_t TElDNSResourceRecordSet::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElDNSResourceRecordSet_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORD
TElDNSResourceRecord* TElDNSResourceRecordSet::get_Items(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDNSResourceRecordSet_get_Items(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElDNSResourceRecord(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORD */

bool TElDNSResourceRecordSet::get_OwnRecords()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElDNSResourceRecordSet_get_OwnRecords(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElDNSResourceRecordSet::set_OwnRecords(bool Value)
{
	SBCheckError(TElDNSResourceRecordSet_set_OwnRecords(_Handle, (int8_t)Value));
}

void TElDNSResourceRecordSet::initInstances()
{
#ifdef SB_USE_CLASS_TELDNSRESOURCERECORD
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORD */
}

TElDNSResourceRecordSet::TElDNSResourceRecordSet(TElDNSResourceRecordSetHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElDNSResourceRecordSet::TElDNSResourceRecordSet() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDNSResourceRecordSet_Create(&_Handle));
}

TElDNSResourceRecordSet::~TElDNSResourceRecordSet()
{
#ifdef SB_USE_CLASS_TELDNSRESOURCERECORD
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORD */
}
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORDSET */

};	/* namespace SecureBlackbox */

