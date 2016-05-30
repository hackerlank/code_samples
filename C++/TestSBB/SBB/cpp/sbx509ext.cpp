#include "sbx509ext.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELEDIPARTYNAME

void TElEDIPartyName::get_NameAssigner(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElEDIPartyName_get_NameAssigner(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1849599128, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElEDIPartyName::set_NameAssigner(const std::string &Value)
{
	SBCheckError(TElEDIPartyName_set_NameAssigner(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElEDIPartyName::get_PartyName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElEDIPartyName_get_PartyName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(86120317, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElEDIPartyName::set_PartyName(const std::string &Value)
{
	SBCheckError(TElEDIPartyName_set_PartyName(_Handle, Value.data(), (int32_t)Value.length()));
}

TElEDIPartyName::TElEDIPartyName(TElEDIPartyNameHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElEDIPartyName::TElEDIPartyName() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElEDIPartyName_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELEDIPARTYNAME */

#ifdef SB_USE_CLASS_TELOTHERNAME

void TElOtherName::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOtherName_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1659330235, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOtherName::set_OID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOtherName_set_OID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElOtherName::get_Value(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOtherName_get_Value(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2103953464, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOtherName::set_Value(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOtherName_set_Value(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElOtherName::TElOtherName(TElOtherNameHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElOtherName::TElOtherName() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOtherName_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOTHERNAME */

#ifdef SB_USE_CLASS_TELPERMANENTIDENTIFIER

void TElPermanentIdentifier::get_PermanentIdentifier(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPermanentIdentifier_get_PermanentIdentifier(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1871500111, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPermanentIdentifier::set_PermanentIdentifier(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPermanentIdentifier_set_PermanentIdentifier(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPermanentIdentifier::get_Assigner(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPermanentIdentifier_get_Assigner(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-476900801, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPermanentIdentifier::set_Assigner(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPermanentIdentifier_set_Assigner(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPermanentIdentifier::TElPermanentIdentifier(TElPermanentIdentifierHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElPermanentIdentifier::TElPermanentIdentifier() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPermanentIdentifier_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPERMANENTIDENTIFIER */

#ifdef SB_USE_CLASS_TELGENERALNAME

SB_INLINE void TElGeneralName::Assign(TPersistent &Source)
{
	SBCheckError(TElGeneralName_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElGeneralName::Assign(TPersistent *Source)
{
	SBCheckError(TElGeneralName_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElGeneralName::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElGeneralName_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElGeneralName::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElGeneralName_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELASN1CUSTOMTAG
bool TElGeneralName::LoadFromTag(TElASN1CustomTag &Tag)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGeneralName_LoadFromTag(_Handle, Tag.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGeneralName::LoadFromTag(TElASN1CustomTag *Tag)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGeneralName_LoadFromTag(_Handle, (Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELASN1CUSTOMTAG */

#ifdef SB_USE_CLASS_TELASN1SIMPLETAG
bool TElGeneralName::SaveToTag(TElASN1SimpleTag &Tag)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGeneralName_SaveToTag(_Handle, Tag.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGeneralName::SaveToTag(TElASN1SimpleTag *Tag)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGeneralName_SaveToTag(_Handle, (Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELASN1SIMPLETAG */

void TElGeneralName::get_RFC822Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGeneralName_get_RFC822Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1819599917, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGeneralName::set_RFC822Name(const std::string &Value)
{
	SBCheckError(TElGeneralName_set_RFC822Name(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElGeneralName::get_DNSName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGeneralName_get_DNSName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-531138871, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGeneralName::set_DNSName(const std::string &Value)
{
	SBCheckError(TElGeneralName_set_DNSName(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElGeneralName::get_DirectoryName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGeneralName_get_DirectoryName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DirectoryName)
		this->_Inst_DirectoryName = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_DirectoryName->updateHandle(hOutResult);
	return this->_Inst_DirectoryName;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELEDIPARTYNAME
TElEDIPartyName* TElGeneralName::get_EdiPartyName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGeneralName_get_EdiPartyName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EdiPartyName)
		this->_Inst_EdiPartyName = new TElEDIPartyName(hOutResult, ohFalse);
	else
		this->_Inst_EdiPartyName->updateHandle(hOutResult);
	return this->_Inst_EdiPartyName;
}
#endif /* SB_USE_CLASS_TELEDIPARTYNAME */

void TElGeneralName::get_UniformResourceIdentifier(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGeneralName_get_UniformResourceIdentifier(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1797151368, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGeneralName::set_UniformResourceIdentifier(const std::string &Value)
{
	SBCheckError(TElGeneralName_set_UniformResourceIdentifier(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElGeneralName::get_IpAddress(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElGeneralName_get_IpAddress(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1717266436, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGeneralName::set_IpAddress(const std::string &Value)
{
	SBCheckError(TElGeneralName_set_IpAddress(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElGeneralName::get_IpAddressBytes(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGeneralName_get_IpAddressBytes(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1708866425, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGeneralName::set_IpAddressBytes(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGeneralName_set_IpAddressBytes(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElGeneralName::get_RegisteredID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElGeneralName_get_RegisteredID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2783864, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElGeneralName::set_RegisteredID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElGeneralName_set_RegisteredID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELOTHERNAME
TElOtherName* TElGeneralName::get_OtherName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGeneralName_get_OtherName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OtherName)
		this->_Inst_OtherName = new TElOtherName(hOutResult, ohFalse);
	else
		this->_Inst_OtherName->updateHandle(hOutResult);
	return this->_Inst_OtherName;
}
#endif /* SB_USE_CLASS_TELOTHERNAME */

#ifdef SB_USE_CLASS_TELPERMANENTIDENTIFIER
TElPermanentIdentifier* TElGeneralName::get_PermanentIdentifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGeneralName_get_PermanentIdentifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PermanentIdentifier)
		this->_Inst_PermanentIdentifier = new TElPermanentIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_PermanentIdentifier->updateHandle(hOutResult);
	return this->_Inst_PermanentIdentifier;
}
#endif /* SB_USE_CLASS_TELPERMANENTIDENTIFIER */

TSBGeneralName TElGeneralName::get_NameType()
{
	TSBGeneralNameRaw OutResultRaw = 0;
	SBCheckError(TElGeneralName_get_NameType(_Handle, &OutResultRaw));
	return (TSBGeneralName)OutResultRaw;
}

SB_INLINE void TElGeneralName::set_NameType(TSBGeneralName Value)
{
	SBCheckError(TElGeneralName_set_NameType(_Handle, (TSBGeneralNameRaw)Value));
}

bool TElGeneralName::get_IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGeneralName_get_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElGeneralName::initInstances()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_DirectoryName = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELEDIPARTYNAME
	this->_Inst_EdiPartyName = NULL;
#endif /* SB_USE_CLASS_TELEDIPARTYNAME */
#ifdef SB_USE_CLASS_TELOTHERNAME
	this->_Inst_OtherName = NULL;
#endif /* SB_USE_CLASS_TELOTHERNAME */
#ifdef SB_USE_CLASS_TELPERMANENTIDENTIFIER
	this->_Inst_PermanentIdentifier = NULL;
#endif /* SB_USE_CLASS_TELPERMANENTIDENTIFIER */
}

TElGeneralName::TElGeneralName(TElGeneralNameHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElGeneralName::TElGeneralName() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGeneralName_Create(&_Handle));
}

TElGeneralName::~TElGeneralName()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_DirectoryName;
	this->_Inst_DirectoryName = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELEDIPARTYNAME
	delete this->_Inst_EdiPartyName;
	this->_Inst_EdiPartyName = NULL;
#endif /* SB_USE_CLASS_TELEDIPARTYNAME */
#ifdef SB_USE_CLASS_TELOTHERNAME
	delete this->_Inst_OtherName;
	this->_Inst_OtherName = NULL;
#endif /* SB_USE_CLASS_TELOTHERNAME */
#ifdef SB_USE_CLASS_TELPERMANENTIDENTIFIER
	delete this->_Inst_PermanentIdentifier;
	this->_Inst_PermanentIdentifier = NULL;
#endif /* SB_USE_CLASS_TELPERMANENTIDENTIFIER */
}
#endif /* SB_USE_CLASS_TELGENERALNAME */

#ifdef SB_USE_CLASS_TELGENERALNAMES

SB_INLINE void TElGeneralNames::Assign(TPersistent &Source)
{
	SBCheckError(TElGeneralNames_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElGeneralNames::Assign(TPersistent *Source)
{
	SBCheckError(TElGeneralNames_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElGeneralNames::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElGeneralNames_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElGeneralNames::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElGeneralNames_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

bool TElGeneralNames::Equals(TElGeneralNames &Other)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGeneralNames_Equals(_Handle, Other.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGeneralNames::Equals(TElGeneralNames *Other)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGeneralNames_Equals(_Handle, (Other != NULL) ? Other->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGeneralNames::HasCommon(TElGeneralNames &Other)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGeneralNames_HasCommon(_Handle, Other.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGeneralNames::HasCommon(TElGeneralNames *Other)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGeneralNames_HasCommon(_Handle, (Other != NULL) ? Other->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElGeneralNames::Add()
{
	int32_t OutResult;
	SBCheckError(TElGeneralNames_Add(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElGeneralNames::Remove(int32_t Index)
{
	SBCheckError(TElGeneralNames_Remove(_Handle, Index));
}

SB_INLINE void TElGeneralNames::Clear()
{
	SBCheckError(TElGeneralNames_Clear(_Handle));
}

bool TElGeneralNames::ContainsEmailAddress(const std::string &Addr)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGeneralNames_ContainsEmailAddress(_Handle, Addr.data(), (int32_t)Addr.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElGeneralNames::FindNameByType(TSBGeneralName NameType, int32_t StartIndex)
{
	int32_t OutResult;
	SBCheckError(TElGeneralNames_FindNameByType(_Handle, (TSBGeneralNameRaw)NameType, StartIndex, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
bool TElGeneralNames::LoadFromTag(TElASN1ConstrainedTag &Tag, bool AllowRDN)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGeneralNames_LoadFromTag(_Handle, Tag.getHandle(), (int8_t)AllowRDN, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGeneralNames::LoadFromTag(TElASN1ConstrainedTag *Tag, bool AllowRDN)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGeneralNames_LoadFromTag(_Handle, (Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, (int8_t)AllowRDN, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
bool TElGeneralNames::SaveToTag(TElASN1ConstrainedTag &Tag)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGeneralNames_SaveToTag(_Handle, Tag.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElGeneralNames::SaveToTag(TElASN1ConstrainedTag *Tag)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElGeneralNames_SaveToTag(_Handle, (Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASS_TELGENERALNAME
TElGeneralName* TElGeneralNames::get_Names(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElGeneralNames_get_Names(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Names)
		this->_Inst_Names = new TElGeneralName(hOutResult, ohFalse);
	else
		this->_Inst_Names->updateHandle(hOutResult);
	return this->_Inst_Names;
}
#endif /* SB_USE_CLASS_TELGENERALNAME */

SB_INLINE int32_t TElGeneralNames::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElGeneralNames_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElGeneralNames::initInstances()
{
#ifdef SB_USE_CLASS_TELGENERALNAME
	this->_Inst_Names = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
}

TElGeneralNames::TElGeneralNames(TElGeneralNamesHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElGeneralNames::TElGeneralNames() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElGeneralNames_Create(&_Handle));
}

TElGeneralNames::~TElGeneralNames()
{
#ifdef SB_USE_CLASS_TELGENERALNAME
	delete this->_Inst_Names;
	this->_Inst_Names = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
}
#endif /* SB_USE_CLASS_TELGENERALNAMES */

#ifdef SB_USE_CLASS_TELCUSTOMEXTENSION

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
SB_INLINE void TElCustomExtension::SaveToTag(TElASN1ConstrainedTag &Tag)
{
	SBCheckError(TElCustomExtension_SaveToTag(_Handle, Tag.getHandle()));
}

SB_INLINE void TElCustomExtension::SaveToTag(TElASN1ConstrainedTag *Tag)
{
	SBCheckError(TElCustomExtension_SaveToTag(_Handle, (Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

bool TElCustomExtension::get_Critical()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomExtension_get_Critical(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomExtension::set_Critical(bool Value)
{
	SBCheckError(TElCustomExtension_set_Critical(_Handle, (int8_t)Value));
}

void TElCustomExtension::get_OID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomExtension_get_OID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1621978957, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomExtension::set_OID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCustomExtension_set_OID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElCustomExtension::get_Value(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomExtension_get_Value(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-916303822, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomExtension::set_Value(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCustomExtension_set_Value(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElCustomExtension::get_SaveDefaultASN1Tags()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomExtension_get_SaveDefaultASN1Tags(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomExtension::set_SaveDefaultASN1Tags(bool Value)
{
	SBCheckError(TElCustomExtension_set_SaveDefaultASN1Tags(_Handle, (int8_t)Value));
}

TElCustomExtension::TElCustomExtension(TElCustomExtensionHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElCustomExtension::TElCustomExtension() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMEXTENSION */

#ifdef SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIEREXTENSION

void TElAuthorityKeyIdentifierExtension::get_KeyIdentifier(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElAuthorityKeyIdentifierExtension_get_KeyIdentifier(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1448104879, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAuthorityKeyIdentifierExtension::set_KeyIdentifier(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElAuthorityKeyIdentifierExtension_set_KeyIdentifier(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELGENERALNAMES
TElGeneralNames* TElAuthorityKeyIdentifierExtension::get_AuthorityCertIssuer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAuthorityKeyIdentifierExtension_get_AuthorityCertIssuer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AuthorityCertIssuer)
		this->_Inst_AuthorityCertIssuer = new TElGeneralNames(hOutResult, ohFalse);
	else
		this->_Inst_AuthorityCertIssuer->updateHandle(hOutResult);
	return this->_Inst_AuthorityCertIssuer;
}
#endif /* SB_USE_CLASS_TELGENERALNAMES */

void TElAuthorityKeyIdentifierExtension::get_AuthorityCertSerial(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElAuthorityKeyIdentifierExtension_get_AuthorityCertSerial(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2013356523, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAuthorityKeyIdentifierExtension::set_AuthorityCertSerial(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElAuthorityKeyIdentifierExtension_set_AuthorityCertSerial(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElAuthorityKeyIdentifierExtension::initInstances()
{
#ifdef SB_USE_CLASS_TELGENERALNAMES
	this->_Inst_AuthorityCertIssuer = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAMES */
}

TElAuthorityKeyIdentifierExtension::TElAuthorityKeyIdentifierExtension(TElAuthorityKeyIdentifierExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
	initInstances();
}

TElAuthorityKeyIdentifierExtension::TElAuthorityKeyIdentifierExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAuthorityKeyIdentifierExtension_Create(&_Handle));
}

TElAuthorityKeyIdentifierExtension::~TElAuthorityKeyIdentifierExtension()
{
#ifdef SB_USE_CLASS_TELGENERALNAMES
	delete this->_Inst_AuthorityCertIssuer;
	this->_Inst_AuthorityCertIssuer = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAMES */
}
#endif /* SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIEREXTENSION */

#ifdef SB_USE_CLASS_TELSUBJECTKEYIDENTIFIEREXTENSION

void TElSubjectKeyIdentifierExtension::get_KeyIdentifier(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSubjectKeyIdentifierExtension_get_KeyIdentifier(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(554399861, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSubjectKeyIdentifierExtension::set_KeyIdentifier(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSubjectKeyIdentifierExtension_set_KeyIdentifier(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElSubjectKeyIdentifierExtension::TElSubjectKeyIdentifierExtension(TElSubjectKeyIdentifierExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
}

TElSubjectKeyIdentifierExtension::TElSubjectKeyIdentifierExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSubjectKeyIdentifierExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSUBJECTKEYIDENTIFIEREXTENSION */

#ifdef SB_USE_CLASS_TELKEYUSAGEEXTENSION

bool TElKeyUsageExtension::get_DigitalSignature()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElKeyUsageExtension_get_DigitalSignature(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElKeyUsageExtension::set_DigitalSignature(bool Value)
{
	SBCheckError(TElKeyUsageExtension_set_DigitalSignature(_Handle, (int8_t)Value));
}

bool TElKeyUsageExtension::get_NonRepudiation()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElKeyUsageExtension_get_NonRepudiation(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElKeyUsageExtension::set_NonRepudiation(bool Value)
{
	SBCheckError(TElKeyUsageExtension_set_NonRepudiation(_Handle, (int8_t)Value));
}

bool TElKeyUsageExtension::get_KeyEncipherment()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElKeyUsageExtension_get_KeyEncipherment(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElKeyUsageExtension::set_KeyEncipherment(bool Value)
{
	SBCheckError(TElKeyUsageExtension_set_KeyEncipherment(_Handle, (int8_t)Value));
}

bool TElKeyUsageExtension::get_DataEncipherment()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElKeyUsageExtension_get_DataEncipherment(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElKeyUsageExtension::set_DataEncipherment(bool Value)
{
	SBCheckError(TElKeyUsageExtension_set_DataEncipherment(_Handle, (int8_t)Value));
}

bool TElKeyUsageExtension::get_KeyAgreement()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElKeyUsageExtension_get_KeyAgreement(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElKeyUsageExtension::set_KeyAgreement(bool Value)
{
	SBCheckError(TElKeyUsageExtension_set_KeyAgreement(_Handle, (int8_t)Value));
}

bool TElKeyUsageExtension::get_KeyCertSign()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElKeyUsageExtension_get_KeyCertSign(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElKeyUsageExtension::set_KeyCertSign(bool Value)
{
	SBCheckError(TElKeyUsageExtension_set_KeyCertSign(_Handle, (int8_t)Value));
}

bool TElKeyUsageExtension::get_CRLSign()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElKeyUsageExtension_get_CRLSign(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElKeyUsageExtension::set_CRLSign(bool Value)
{
	SBCheckError(TElKeyUsageExtension_set_CRLSign(_Handle, (int8_t)Value));
}

bool TElKeyUsageExtension::get_EncipherOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElKeyUsageExtension_get_EncipherOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElKeyUsageExtension::set_EncipherOnly(bool Value)
{
	SBCheckError(TElKeyUsageExtension_set_EncipherOnly(_Handle, (int8_t)Value));
}

bool TElKeyUsageExtension::get_DecipherOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElKeyUsageExtension_get_DecipherOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElKeyUsageExtension::set_DecipherOnly(bool Value)
{
	SBCheckError(TElKeyUsageExtension_set_DecipherOnly(_Handle, (int8_t)Value));
}

TElKeyUsageExtension::TElKeyUsageExtension(TElKeyUsageExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
}

TElKeyUsageExtension::TElKeyUsageExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElKeyUsageExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELKEYUSAGEEXTENSION */

#ifdef SB_USE_CLASS_TELPRIVATEKEYUSAGEPERIODEXTENSION

SB_INLINE int64_t TElPrivateKeyUsagePeriodExtension::get_NotBefore()
{
	int64_t OutResult;
	SBCheckError(TElPrivateKeyUsagePeriodExtension_get_NotBefore(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPrivateKeyUsagePeriodExtension::set_NotBefore(int64_t Value)
{
	SBCheckError(TElPrivateKeyUsagePeriodExtension_set_NotBefore(_Handle, Value));
}

SB_INLINE int64_t TElPrivateKeyUsagePeriodExtension::get_NotAfter()
{
	int64_t OutResult;
	SBCheckError(TElPrivateKeyUsagePeriodExtension_get_NotAfter(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPrivateKeyUsagePeriodExtension::set_NotAfter(int64_t Value)
{
	SBCheckError(TElPrivateKeyUsagePeriodExtension_set_NotAfter(_Handle, Value));
}

TElPrivateKeyUsagePeriodExtension::TElPrivateKeyUsagePeriodExtension(TElPrivateKeyUsagePeriodExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
}

TElPrivateKeyUsagePeriodExtension::TElPrivateKeyUsagePeriodExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPrivateKeyUsagePeriodExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPRIVATEKEYUSAGEPERIODEXTENSION */

#ifdef SB_USE_CLASS_TELNETSCAPECERTTYPEEXTENSION

TElNetscapeCertType TElNetscapeCertTypeExtension::get_CertType()
{
	TElNetscapeCertTypeRaw OutResultRaw = 0;
	SBCheckError(TElNetscapeCertTypeExtension_get_CertType(_Handle, &OutResultRaw));
	return (TElNetscapeCertType)OutResultRaw;
}

SB_INLINE void TElNetscapeCertTypeExtension::set_CertType(TElNetscapeCertType Value)
{
	SBCheckError(TElNetscapeCertTypeExtension_set_CertType(_Handle, (TElNetscapeCertTypeRaw)Value));
}

TElNetscapeCertTypeExtension::TElNetscapeCertTypeExtension(TElNetscapeCertTypeExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
}

TElNetscapeCertTypeExtension::TElNetscapeCertTypeExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElNetscapeCertTypeExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELNETSCAPECERTTYPEEXTENSION */

#ifdef SB_USE_CLASS_TELNETSCAPESTRING

void TElNetscapeString::get_Content(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElNetscapeString_get_Content(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1552291866, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElNetscapeString::set_Content(const std::string &Value)
{
	SBCheckError(TElNetscapeString_set_Content(_Handle, Value.data(), (int32_t)Value.length()));
}

TElNetscapeString::TElNetscapeString(TElNetscapeStringHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
}

TElNetscapeString::TElNetscapeString() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElNetscapeString_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELNETSCAPESTRING */

#ifdef SB_USE_CLASS_TELNETSCAPEBASEURL

TElNetscapeBaseURL::TElNetscapeBaseURL(TElNetscapeBaseURLHandle handle, TElOwnHandle ownHandle) : TElNetscapeString(handle, ownHandle)
{
}

TElNetscapeBaseURL::TElNetscapeBaseURL() : TElNetscapeString(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElNetscapeBaseURL_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELNETSCAPEBASEURL */

#ifdef SB_USE_CLASS_TELNETSCAPEREVOKEURL

TElNetscapeRevokeURL::TElNetscapeRevokeURL(TElNetscapeRevokeURLHandle handle, TElOwnHandle ownHandle) : TElNetscapeString(handle, ownHandle)
{
}

TElNetscapeRevokeURL::TElNetscapeRevokeURL() : TElNetscapeString(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElNetscapeRevokeURL_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELNETSCAPEREVOKEURL */

#ifdef SB_USE_CLASS_TELNETSCAPECAREVOKEURL

TElNetscapeCARevokeURL::TElNetscapeCARevokeURL(TElNetscapeCARevokeURLHandle handle, TElOwnHandle ownHandle) : TElNetscapeString(handle, ownHandle)
{
}

TElNetscapeCARevokeURL::TElNetscapeCARevokeURL() : TElNetscapeString(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElNetscapeCARevokeURL_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELNETSCAPECAREVOKEURL */

#ifdef SB_USE_CLASS_TELNETSCAPERENEWALURL

TElNetscapeRenewalURL::TElNetscapeRenewalURL(TElNetscapeRenewalURLHandle handle, TElOwnHandle ownHandle) : TElNetscapeString(handle, ownHandle)
{
}

TElNetscapeRenewalURL::TElNetscapeRenewalURL() : TElNetscapeString(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElNetscapeRenewalURL_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELNETSCAPERENEWALURL */

#ifdef SB_USE_CLASS_TELNETSCAPECAPOLICY

TElNetscapeCAPolicy::TElNetscapeCAPolicy(TElNetscapeCAPolicyHandle handle, TElOwnHandle ownHandle) : TElNetscapeString(handle, ownHandle)
{
}

TElNetscapeCAPolicy::TElNetscapeCAPolicy() : TElNetscapeString(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElNetscapeCAPolicy_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELNETSCAPECAPOLICY */

#ifdef SB_USE_CLASS_TELNETSCAPESERVERNAME

TElNetscapeServerName::TElNetscapeServerName(TElNetscapeServerNameHandle handle, TElOwnHandle ownHandle) : TElNetscapeString(handle, ownHandle)
{
}

TElNetscapeServerName::TElNetscapeServerName() : TElNetscapeString(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElNetscapeServerName_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELNETSCAPESERVERNAME */

#ifdef SB_USE_CLASS_TELNETSCAPECOMMENT

TElNetscapeComment::TElNetscapeComment(TElNetscapeCommentHandle handle, TElOwnHandle ownHandle) : TElNetscapeString(handle, ownHandle)
{
}

TElNetscapeComment::TElNetscapeComment() : TElNetscapeString(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElNetscapeComment_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELNETSCAPECOMMENT */

#ifdef SB_USE_CLASS_TELCOMMONNAME

TElCommonName::TElCommonName(TElCommonNameHandle handle, TElOwnHandle ownHandle) : TElNetscapeString(handle, ownHandle)
{
}

TElCommonName::TElCommonName() : TElNetscapeString(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCommonName_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCOMMONNAME */

#ifdef SB_USE_CLASS_TELUSERNOTICE

void TElUserNotice::get_Organization(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElUserNotice_get_Organization(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-658226608, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElUserNotice::set_Organization(const std::string &Value)
{
	SBCheckError(TElUserNotice_set_Organization(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TElUserNotice::get_NoticeNumbers(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TElUserNotice_get_NoticeNumbers(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElUserNotice::set_NoticeNumbers(int32_t Index, int32_t Value)
{
	SBCheckError(TElUserNotice_set_NoticeNumbers(_Handle, Index, Value));
}

SB_INLINE int32_t TElUserNotice::get_NoticeNumbersCount()
{
	int32_t OutResult;
	SBCheckError(TElUserNotice_get_NoticeNumbersCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElUserNotice::set_NoticeNumbersCount(int32_t Value)
{
	SBCheckError(TElUserNotice_set_NoticeNumbersCount(_Handle, Value));
}

void TElUserNotice::get_ExplicitText(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElUserNotice_get_ExplicitText(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(912235093, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElUserNotice::set_ExplicitText(const std::string &Value)
{
	SBCheckError(TElUserNotice_set_ExplicitText(_Handle, Value.data(), (int32_t)Value.length()));
}

TElUserNotice::TElUserNotice(TElUserNoticeHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElUserNotice::TElUserNotice() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElUserNotice_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELUSERNOTICE */

#ifdef SB_USE_CLASS_TELSINGLEPOLICYQUALIFIER

void TElSinglePolicyQualifier::get_CPSURI(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSinglePolicyQualifier_get_CPSURI(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(751872919, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSinglePolicyQualifier::set_CPSURI(const std::string &Value)
{
	SBCheckError(TElSinglePolicyQualifier_set_CPSURI(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELUSERNOTICE
TElUserNotice* TElSinglePolicyQualifier::get_UserNotice()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSinglePolicyQualifier_get_UserNotice(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_UserNotice)
		this->_Inst_UserNotice = new TElUserNotice(hOutResult, ohFalse);
	else
		this->_Inst_UserNotice->updateHandle(hOutResult);
	return this->_Inst_UserNotice;
}
#endif /* SB_USE_CLASS_TELUSERNOTICE */

void TElSinglePolicyQualifier::initInstances()
{
#ifdef SB_USE_CLASS_TELUSERNOTICE
	this->_Inst_UserNotice = NULL;
#endif /* SB_USE_CLASS_TELUSERNOTICE */
}

TElSinglePolicyQualifier::TElSinglePolicyQualifier(TElSinglePolicyQualifierHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElSinglePolicyQualifier::TElSinglePolicyQualifier() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSinglePolicyQualifier_Create(&_Handle));
}

TElSinglePolicyQualifier::~TElSinglePolicyQualifier()
{
#ifdef SB_USE_CLASS_TELUSERNOTICE
	delete this->_Inst_UserNotice;
	this->_Inst_UserNotice = NULL;
#endif /* SB_USE_CLASS_TELUSERNOTICE */
}
#endif /* SB_USE_CLASS_TELSINGLEPOLICYQUALIFIER */

#ifdef SB_USE_CLASS_TELSINGLEPOLICYINFORMATION

void TElSinglePolicyInformation::get_PolicyIdentifier(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSinglePolicyInformation_get_PolicyIdentifier(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(873948584, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSinglePolicyInformation::set_PolicyIdentifier(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSinglePolicyInformation_set_PolicyIdentifier(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElSinglePolicyInformation::get_QualifierCount()
{
	int32_t OutResult;
	SBCheckError(TElSinglePolicyInformation_get_QualifierCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSinglePolicyInformation::set_QualifierCount(int32_t Value)
{
	SBCheckError(TElSinglePolicyInformation_set_QualifierCount(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELSINGLEPOLICYQUALIFIER
TElSinglePolicyQualifier* TElSinglePolicyInformation::get_Qualifiers(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSinglePolicyInformation_get_Qualifiers(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Qualifiers)
		this->_Inst_Qualifiers = new TElSinglePolicyQualifier(hOutResult, ohFalse);
	else
		this->_Inst_Qualifiers->updateHandle(hOutResult);
	return this->_Inst_Qualifiers;
}
#endif /* SB_USE_CLASS_TELSINGLEPOLICYQUALIFIER */

void TElSinglePolicyInformation::initInstances()
{
#ifdef SB_USE_CLASS_TELSINGLEPOLICYQUALIFIER
	this->_Inst_Qualifiers = NULL;
#endif /* SB_USE_CLASS_TELSINGLEPOLICYQUALIFIER */
}

TElSinglePolicyInformation::TElSinglePolicyInformation(TElSinglePolicyInformationHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElSinglePolicyInformation::TElSinglePolicyInformation() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSinglePolicyInformation_Create(&_Handle));
}

TElSinglePolicyInformation::~TElSinglePolicyInformation()
{
#ifdef SB_USE_CLASS_TELSINGLEPOLICYQUALIFIER
	delete this->_Inst_Qualifiers;
	this->_Inst_Qualifiers = NULL;
#endif /* SB_USE_CLASS_TELSINGLEPOLICYQUALIFIER */
}
#endif /* SB_USE_CLASS_TELSINGLEPOLICYINFORMATION */

#ifdef SB_USE_CLASS_TELCERTIFICATEPOLICIESEXTENSION

SB_INLINE void TElCertificatePoliciesExtension::Remove(int32_t Index)
{
	SBCheckError(TElCertificatePoliciesExtension_Remove(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELSINGLEPOLICYINFORMATION
TElSinglePolicyInformation* TElCertificatePoliciesExtension::get_PolicyInformation(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificatePoliciesExtension_get_PolicyInformation(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PolicyInformation)
		this->_Inst_PolicyInformation = new TElSinglePolicyInformation(hOutResult, ohFalse);
	else
		this->_Inst_PolicyInformation->updateHandle(hOutResult);
	return this->_Inst_PolicyInformation;
}
#endif /* SB_USE_CLASS_TELSINGLEPOLICYINFORMATION */

SB_INLINE int32_t TElCertificatePoliciesExtension::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElCertificatePoliciesExtension_get_Count(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCertificatePoliciesExtension::set_Count(int32_t Value)
{
	SBCheckError(TElCertificatePoliciesExtension_set_Count(_Handle, Value));
}

void TElCertificatePoliciesExtension::initInstances()
{
#ifdef SB_USE_CLASS_TELSINGLEPOLICYINFORMATION
	this->_Inst_PolicyInformation = NULL;
#endif /* SB_USE_CLASS_TELSINGLEPOLICYINFORMATION */
}

TElCertificatePoliciesExtension::TElCertificatePoliciesExtension(TElCertificatePoliciesExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
	initInstances();
}

TElCertificatePoliciesExtension::TElCertificatePoliciesExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCertificatePoliciesExtension_Create(&_Handle));
}

TElCertificatePoliciesExtension::~TElCertificatePoliciesExtension()
{
#ifdef SB_USE_CLASS_TELSINGLEPOLICYINFORMATION
	delete this->_Inst_PolicyInformation;
	this->_Inst_PolicyInformation = NULL;
#endif /* SB_USE_CLASS_TELSINGLEPOLICYINFORMATION */
}
#endif /* SB_USE_CLASS_TELCERTIFICATEPOLICIESEXTENSION */

#ifdef SB_USE_CLASS_TELPOLICYMAPPING

void TElPolicyMapping::get_IssuerDomainPolicy(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPolicyMapping_get_IssuerDomainPolicy(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1081069972, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPolicyMapping::set_IssuerDomainPolicy(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPolicyMapping_set_IssuerDomainPolicy(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPolicyMapping::get_SubjectDomainPolicy(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPolicyMapping_get_SubjectDomainPolicy(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1408090289, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPolicyMapping::set_SubjectDomainPolicy(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPolicyMapping_set_SubjectDomainPolicy(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPolicyMapping::TElPolicyMapping(TElPolicyMappingHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElPolicyMapping::TElPolicyMapping() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPolicyMapping_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPOLICYMAPPING */

#ifdef SB_USE_CLASS_TELPOLICYMAPPINGSEXTENSION

SB_INLINE void TElPolicyMappingsExtension::Remove(int32_t Index)
{
	SBCheckError(TElPolicyMappingsExtension_Remove(_Handle, Index));
}

SB_INLINE int32_t TElPolicyMappingsExtension::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElPolicyMappingsExtension_get_Count(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPolicyMappingsExtension::set_Count(int32_t Value)
{
	SBCheckError(TElPolicyMappingsExtension_set_Count(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELPOLICYMAPPING
TElPolicyMapping* TElPolicyMappingsExtension::get_Policies(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPolicyMappingsExtension_get_Policies(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Policies)
		this->_Inst_Policies = new TElPolicyMapping(hOutResult, ohFalse);
	else
		this->_Inst_Policies->updateHandle(hOutResult);
	return this->_Inst_Policies;
}
#endif /* SB_USE_CLASS_TELPOLICYMAPPING */

void TElPolicyMappingsExtension::initInstances()
{
#ifdef SB_USE_CLASS_TELPOLICYMAPPING
	this->_Inst_Policies = NULL;
#endif /* SB_USE_CLASS_TELPOLICYMAPPING */
}

TElPolicyMappingsExtension::TElPolicyMappingsExtension(TElPolicyMappingsExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
	initInstances();
}

TElPolicyMappingsExtension::TElPolicyMappingsExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPolicyMappingsExtension_Create(&_Handle));
}

TElPolicyMappingsExtension::~TElPolicyMappingsExtension()
{
#ifdef SB_USE_CLASS_TELPOLICYMAPPING
	delete this->_Inst_Policies;
	this->_Inst_Policies = NULL;
#endif /* SB_USE_CLASS_TELPOLICYMAPPING */
}
#endif /* SB_USE_CLASS_TELPOLICYMAPPINGSEXTENSION */

#ifdef SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION

#ifdef SB_USE_CLASS_TELGENERALNAMES
TElGeneralNames* TElAlternativeNameExtension::get_Content()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAlternativeNameExtension_get_Content(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Content)
		this->_Inst_Content = new TElGeneralNames(hOutResult, ohFalse);
	else
		this->_Inst_Content->updateHandle(hOutResult);
	return this->_Inst_Content;
}
#endif /* SB_USE_CLASS_TELGENERALNAMES */

void TElAlternativeNameExtension::initInstances()
{
#ifdef SB_USE_CLASS_TELGENERALNAMES
	this->_Inst_Content = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAMES */
}

TElAlternativeNameExtension::TElAlternativeNameExtension(TElAlternativeNameExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
	initInstances();
}

TElAlternativeNameExtension::TElAlternativeNameExtension(bool IssuerAltName) : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAlternativeNameExtension_Create((int8_t)IssuerAltName, &_Handle));
}

TElAlternativeNameExtension::~TElAlternativeNameExtension()
{
#ifdef SB_USE_CLASS_TELGENERALNAMES
	delete this->_Inst_Content;
	this->_Inst_Content = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAMES */
}
#endif /* SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION */

#ifdef SB_USE_CLASS_TELBASICCONSTRAINTSEXTENSION

bool TElBasicConstraintsExtension::get_CA()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElBasicConstraintsExtension_get_CA(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElBasicConstraintsExtension::set_CA(bool Value)
{
	SBCheckError(TElBasicConstraintsExtension_set_CA(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElBasicConstraintsExtension::get_PathLenConstraint()
{
	int32_t OutResult;
	SBCheckError(TElBasicConstraintsExtension_get_PathLenConstraint(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElBasicConstraintsExtension::set_PathLenConstraint(int32_t Value)
{
	SBCheckError(TElBasicConstraintsExtension_set_PathLenConstraint(_Handle, Value));
}

TElBasicConstraintsExtension::TElBasicConstraintsExtension(TElBasicConstraintsExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
}

TElBasicConstraintsExtension::TElBasicConstraintsExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElBasicConstraintsExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELBASICCONSTRAINTSEXTENSION */

#ifdef SB_USE_CLASS_TELNAMECONSTRAINT

#ifdef SB_USE_CLASS_TELGENERALNAME
TElGeneralName* TElNameConstraint::get_Base()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElNameConstraint_get_Base(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Base)
		this->_Inst_Base = new TElGeneralName(hOutResult, ohFalse);
	else
		this->_Inst_Base->updateHandle(hOutResult);
	return this->_Inst_Base;
}
#endif /* SB_USE_CLASS_TELGENERALNAME */

SB_INLINE int32_t TElNameConstraint::get_Minimum()
{
	int32_t OutResult;
	SBCheckError(TElNameConstraint_get_Minimum(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElNameConstraint::set_Minimum(int32_t Value)
{
	SBCheckError(TElNameConstraint_set_Minimum(_Handle, Value));
}

SB_INLINE int32_t TElNameConstraint::get_Maximum()
{
	int32_t OutResult;
	SBCheckError(TElNameConstraint_get_Maximum(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElNameConstraint::set_Maximum(int32_t Value)
{
	SBCheckError(TElNameConstraint_set_Maximum(_Handle, Value));
}

void TElNameConstraint::initInstances()
{
#ifdef SB_USE_CLASS_TELGENERALNAME
	this->_Inst_Base = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
}

TElNameConstraint::TElNameConstraint(TElNameConstraintHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElNameConstraint::TElNameConstraint() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElNameConstraint_Create(&_Handle));
}

TElNameConstraint::~TElNameConstraint()
{
#ifdef SB_USE_CLASS_TELGENERALNAME
	delete this->_Inst_Base;
	this->_Inst_Base = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
}
#endif /* SB_USE_CLASS_TELNAMECONSTRAINT */

#ifdef SB_USE_CLASS_TELNAMECONSTRAINTSEXTENSION

#ifdef SB_USE_CLASSES_TELGENERALNAMES_AND_TELRELATIVEDISTINGUISHEDNAME
bool TElNameConstraintsExtension::AreNamesAcceptable(TElRelativeDistinguishedName &Subj, TElGeneralNames &SubjAltName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElNameConstraintsExtension_AreNamesAcceptable(_Handle, Subj.getHandle(), SubjAltName.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElNameConstraintsExtension::AreNamesAcceptable(TElRelativeDistinguishedName *Subj, TElGeneralNames *SubjAltName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElNameConstraintsExtension_AreNamesAcceptable(_Handle, (Subj != NULL) ? Subj->getHandle() : SB_NULL_HANDLE, (SubjAltName != NULL) ? SubjAltName->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELGENERALNAMES_AND_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE void TElNameConstraintsExtension::RemovePermitted(int32_t Index)
{
	SBCheckError(TElNameConstraintsExtension_RemovePermitted(_Handle, Index));
}

SB_INLINE void TElNameConstraintsExtension::RemoveExcluded(int32_t Index)
{
	SBCheckError(TElNameConstraintsExtension_RemoveExcluded(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELNAMECONSTRAINT
TElNameConstraint* TElNameConstraintsExtension::get_PermittedSubtrees(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElNameConstraintsExtension_get_PermittedSubtrees(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PermittedSubtrees)
		this->_Inst_PermittedSubtrees = new TElNameConstraint(hOutResult, ohFalse);
	else
		this->_Inst_PermittedSubtrees->updateHandle(hOutResult);
	return this->_Inst_PermittedSubtrees;
}
#endif /* SB_USE_CLASS_TELNAMECONSTRAINT */

#ifdef SB_USE_CLASS_TELNAMECONSTRAINT
TElNameConstraint* TElNameConstraintsExtension::get_ExcludedSubtrees(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElNameConstraintsExtension_get_ExcludedSubtrees(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ExcludedSubtrees)
		this->_Inst_ExcludedSubtrees = new TElNameConstraint(hOutResult, ohFalse);
	else
		this->_Inst_ExcludedSubtrees->updateHandle(hOutResult);
	return this->_Inst_ExcludedSubtrees;
}
#endif /* SB_USE_CLASS_TELNAMECONSTRAINT */

SB_INLINE int32_t TElNameConstraintsExtension::get_PermittedCount()
{
	int32_t OutResult;
	SBCheckError(TElNameConstraintsExtension_get_PermittedCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElNameConstraintsExtension::set_PermittedCount(int32_t Value)
{
	SBCheckError(TElNameConstraintsExtension_set_PermittedCount(_Handle, Value));
}

SB_INLINE int32_t TElNameConstraintsExtension::get_ExcludedCount()
{
	int32_t OutResult;
	SBCheckError(TElNameConstraintsExtension_get_ExcludedCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElNameConstraintsExtension::set_ExcludedCount(int32_t Value)
{
	SBCheckError(TElNameConstraintsExtension_set_ExcludedCount(_Handle, Value));
}

void TElNameConstraintsExtension::initInstances()
{
#ifdef SB_USE_CLASS_TELNAMECONSTRAINT
	this->_Inst_PermittedSubtrees = NULL;
#endif /* SB_USE_CLASS_TELNAMECONSTRAINT */
#ifdef SB_USE_CLASS_TELNAMECONSTRAINT
	this->_Inst_ExcludedSubtrees = NULL;
#endif /* SB_USE_CLASS_TELNAMECONSTRAINT */
}

TElNameConstraintsExtension::TElNameConstraintsExtension(TElNameConstraintsExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
	initInstances();
}

TElNameConstraintsExtension::TElNameConstraintsExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElNameConstraintsExtension_Create(&_Handle));
}

TElNameConstraintsExtension::~TElNameConstraintsExtension()
{
#ifdef SB_USE_CLASS_TELNAMECONSTRAINT
	delete this->_Inst_PermittedSubtrees;
	this->_Inst_PermittedSubtrees = NULL;
#endif /* SB_USE_CLASS_TELNAMECONSTRAINT */
#ifdef SB_USE_CLASS_TELNAMECONSTRAINT
	delete this->_Inst_ExcludedSubtrees;
	this->_Inst_ExcludedSubtrees = NULL;
#endif /* SB_USE_CLASS_TELNAMECONSTRAINT */
}
#endif /* SB_USE_CLASS_TELNAMECONSTRAINTSEXTENSION */

#ifdef SB_USE_CLASS_TELPOLICYCONSTRAINTSEXTENSION

SB_INLINE int32_t TElPolicyConstraintsExtension::get_RequireExplicitPolicy()
{
	int32_t OutResult;
	SBCheckError(TElPolicyConstraintsExtension_get_RequireExplicitPolicy(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPolicyConstraintsExtension::set_RequireExplicitPolicy(int32_t Value)
{
	SBCheckError(TElPolicyConstraintsExtension_set_RequireExplicitPolicy(_Handle, Value));
}

SB_INLINE int32_t TElPolicyConstraintsExtension::get_InhibitPolicyMapping()
{
	int32_t OutResult;
	SBCheckError(TElPolicyConstraintsExtension_get_InhibitPolicyMapping(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPolicyConstraintsExtension::set_InhibitPolicyMapping(int32_t Value)
{
	SBCheckError(TElPolicyConstraintsExtension_set_InhibitPolicyMapping(_Handle, Value));
}

TElPolicyConstraintsExtension::TElPolicyConstraintsExtension(TElPolicyConstraintsExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
}

TElPolicyConstraintsExtension::TElPolicyConstraintsExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPolicyConstraintsExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPOLICYCONSTRAINTSEXTENSION */

#ifdef SB_USE_CLASS_TELEXTENDEDKEYUSAGEEXTENSION

SB_INLINE int32_t TElExtendedKeyUsageExtension::AddCustomUsage(const std::vector<uint8_t> &UsageOID)
{
	int32_t OutResult;
	SBCheckError(TElExtendedKeyUsageExtension_AddCustomUsage(_Handle, SB_STD_VECTOR_FRONT_ADR(UsageOID), (int32_t)UsageOID.size(), &OutResult));
	return OutResult;
}

SB_INLINE void TElExtendedKeyUsageExtension::RemoveCustomUsage(int32_t Index)
{
	SBCheckError(TElExtendedKeyUsageExtension_RemoveCustomUsage(_Handle, Index));
}

SB_INLINE void TElExtendedKeyUsageExtension::ClearCustomUsages()
{
	SBCheckError(TElExtendedKeyUsageExtension_ClearCustomUsages(_Handle));
}

SB_INLINE int32_t TElExtendedKeyUsageExtension::get_TotalUsageCount()
{
	int32_t OutResult;
	SBCheckError(TElExtendedKeyUsageExtension_get_TotalUsageCount(_Handle, &OutResult));
	return OutResult;
}

bool TElExtendedKeyUsageExtension::get_ServerAuthentication()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElExtendedKeyUsageExtension_get_ServerAuthentication(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElExtendedKeyUsageExtension::set_ServerAuthentication(bool Value)
{
	SBCheckError(TElExtendedKeyUsageExtension_set_ServerAuthentication(_Handle, (int8_t)Value));
}

bool TElExtendedKeyUsageExtension::get_ClientAuthentication()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElExtendedKeyUsageExtension_get_ClientAuthentication(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElExtendedKeyUsageExtension::set_ClientAuthentication(bool Value)
{
	SBCheckError(TElExtendedKeyUsageExtension_set_ClientAuthentication(_Handle, (int8_t)Value));
}

bool TElExtendedKeyUsageExtension::get_CodeSigning()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElExtendedKeyUsageExtension_get_CodeSigning(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElExtendedKeyUsageExtension::set_CodeSigning(bool Value)
{
	SBCheckError(TElExtendedKeyUsageExtension_set_CodeSigning(_Handle, (int8_t)Value));
}

bool TElExtendedKeyUsageExtension::get_EmailProtection()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElExtendedKeyUsageExtension_get_EmailProtection(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElExtendedKeyUsageExtension::set_EmailProtection(bool Value)
{
	SBCheckError(TElExtendedKeyUsageExtension_set_EmailProtection(_Handle, (int8_t)Value));
}

bool TElExtendedKeyUsageExtension::get_TimeStamping()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElExtendedKeyUsageExtension_get_TimeStamping(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElExtendedKeyUsageExtension::set_TimeStamping(bool Value)
{
	SBCheckError(TElExtendedKeyUsageExtension_set_TimeStamping(_Handle, (int8_t)Value));
}

bool TElExtendedKeyUsageExtension::get_OCSPSigning()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElExtendedKeyUsageExtension_get_OCSPSigning(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElExtendedKeyUsageExtension::set_OCSPSigning(bool Value)
{
	SBCheckError(TElExtendedKeyUsageExtension_set_OCSPSigning(_Handle, (int8_t)Value));
}

bool TElExtendedKeyUsageExtension::get_SmartCardLogon()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElExtendedKeyUsageExtension_get_SmartCardLogon(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElExtendedKeyUsageExtension::set_SmartCardLogon(bool Value)
{
	SBCheckError(TElExtendedKeyUsageExtension_set_SmartCardLogon(_Handle, (int8_t)Value));
}

bool TElExtendedKeyUsageExtension::get_KeyPurposeClientAuth()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElExtendedKeyUsageExtension_get_KeyPurposeClientAuth(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElExtendedKeyUsageExtension::set_KeyPurposeClientAuth(bool Value)
{
	SBCheckError(TElExtendedKeyUsageExtension_set_KeyPurposeClientAuth(_Handle, (int8_t)Value));
}

bool TElExtendedKeyUsageExtension::get_KeyPurposeKDC()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElExtendedKeyUsageExtension_get_KeyPurposeKDC(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElExtendedKeyUsageExtension::set_KeyPurposeKDC(bool Value)
{
	SBCheckError(TElExtendedKeyUsageExtension_set_KeyPurposeKDC(_Handle, (int8_t)Value));
}

void TElExtendedKeyUsageExtension::get_CustomUsages(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtendedKeyUsageExtension_get_CustomUsages(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1802305556, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElExtendedKeyUsageExtension::set_CustomUsages(int32_t Index, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElExtendedKeyUsageExtension_set_CustomUsages(_Handle, Index, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElExtendedKeyUsageExtension::get_CustomUsageCount()
{
	int32_t OutResult;
	SBCheckError(TElExtendedKeyUsageExtension_get_CustomUsageCount(_Handle, &OutResult));
	return OutResult;
}

TElExtendedKeyUsageExtension::TElExtendedKeyUsageExtension(TElExtendedKeyUsageExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
}

TElExtendedKeyUsageExtension::TElExtendedKeyUsageExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElExtendedKeyUsageExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELEXTENDEDKEYUSAGEEXTENSION */

#ifdef SB_USE_CLASS_TELDISTRIBUTIONPOINT

#ifdef SB_USE_CLASS_TELGENERALNAMES
TElGeneralNames* TElDistributionPoint::get_Name()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDistributionPoint_get_Name(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Name)
		this->_Inst_Name = new TElGeneralNames(hOutResult, ohFalse);
	else
		this->_Inst_Name->updateHandle(hOutResult);
	return this->_Inst_Name;
}
#endif /* SB_USE_CLASS_TELGENERALNAMES */

TSBCRLReasonFlags TElDistributionPoint::get_ReasonFlags()
{
	TSBCRLReasonFlagsRaw OutResultRaw = 0;
	SBCheckError(TElDistributionPoint_get_ReasonFlags(_Handle, &OutResultRaw));
	return (TSBCRLReasonFlags)OutResultRaw;
}

SB_INLINE void TElDistributionPoint::set_ReasonFlags(TSBCRLReasonFlags Value)
{
	SBCheckError(TElDistributionPoint_set_ReasonFlags(_Handle, (TSBCRLReasonFlagsRaw)Value));
}

#ifdef SB_USE_CLASS_TELGENERALNAMES
TElGeneralNames* TElDistributionPoint::get_CRLIssuer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElDistributionPoint_get_CRLIssuer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLIssuer)
		this->_Inst_CRLIssuer = new TElGeneralNames(hOutResult, ohFalse);
	else
		this->_Inst_CRLIssuer->updateHandle(hOutResult);
	return this->_Inst_CRLIssuer;
}
#endif /* SB_USE_CLASS_TELGENERALNAMES */

TElDistributionPointParameters TElDistributionPoint::get_Included()
{
	TElDistributionPointParametersRaw OutResultRaw = 0;
	SBCheckError(TElDistributionPoint_get_Included(_Handle, &OutResultRaw));
	return (TElDistributionPointParameters)OutResultRaw;
}

SB_INLINE void TElDistributionPoint::set_Included(TElDistributionPointParameters Value)
{
	SBCheckError(TElDistributionPoint_set_Included(_Handle, (TElDistributionPointParametersRaw)Value));
}

void TElDistributionPoint::initInstances()
{
#ifdef SB_USE_CLASS_TELGENERALNAMES
	this->_Inst_Name = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAMES */
#ifdef SB_USE_CLASS_TELGENERALNAMES
	this->_Inst_CRLIssuer = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAMES */
}

TElDistributionPoint::TElDistributionPoint(TElDistributionPointHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElDistributionPoint::TElDistributionPoint() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElDistributionPoint_Create(&_Handle));
}

TElDistributionPoint::~TElDistributionPoint()
{
#ifdef SB_USE_CLASS_TELGENERALNAMES
	delete this->_Inst_Name;
	this->_Inst_Name = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAMES */
#ifdef SB_USE_CLASS_TELGENERALNAMES
	delete this->_Inst_CRLIssuer;
	this->_Inst_CRLIssuer = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAMES */
}
#endif /* SB_USE_CLASS_TELDISTRIBUTIONPOINT */

#ifdef SB_USE_CLASS_TELCRLDISTRIBUTIONPOINTSEXTENSION

SB_INLINE void TElCRLDistributionPointsExtension::Remove(int32_t Index)
{
	SBCheckError(TElCRLDistributionPointsExtension_Remove(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELDISTRIBUTIONPOINT
TElDistributionPoint* TElCRLDistributionPointsExtension::get_DistributionPoints(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCRLDistributionPointsExtension_get_DistributionPoints(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DistributionPoints)
		this->_Inst_DistributionPoints = new TElDistributionPoint(hOutResult, ohFalse);
	else
		this->_Inst_DistributionPoints->updateHandle(hOutResult);
	return this->_Inst_DistributionPoints;
}
#endif /* SB_USE_CLASS_TELDISTRIBUTIONPOINT */

SB_INLINE int32_t TElCRLDistributionPointsExtension::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElCRLDistributionPointsExtension_get_Count(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCRLDistributionPointsExtension::set_Count(int32_t Value)
{
	SBCheckError(TElCRLDistributionPointsExtension_set_Count(_Handle, Value));
}

void TElCRLDistributionPointsExtension::initInstances()
{
#ifdef SB_USE_CLASS_TELDISTRIBUTIONPOINT
	this->_Inst_DistributionPoints = NULL;
#endif /* SB_USE_CLASS_TELDISTRIBUTIONPOINT */
}

TElCRLDistributionPointsExtension::TElCRLDistributionPointsExtension(TElCRLDistributionPointsExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
	initInstances();
}

TElCRLDistributionPointsExtension::TElCRLDistributionPointsExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCRLDistributionPointsExtension_Create(&_Handle));
}

TElCRLDistributionPointsExtension::~TElCRLDistributionPointsExtension()
{
#ifdef SB_USE_CLASS_TELDISTRIBUTIONPOINT
	delete this->_Inst_DistributionPoints;
	this->_Inst_DistributionPoints = NULL;
#endif /* SB_USE_CLASS_TELDISTRIBUTIONPOINT */
}
#endif /* SB_USE_CLASS_TELCRLDISTRIBUTIONPOINTSEXTENSION */

#ifdef SB_USE_CLASS_TELACCESSDESCRIPTION

void TElAccessDescription::get_AccessMethod(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElAccessDescription_get_AccessMethod(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1380958047, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAccessDescription::set_AccessMethod(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElAccessDescription_set_AccessMethod(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELGENERALNAME
TElGeneralName* TElAccessDescription::get_AccessLocation()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAccessDescription_get_AccessLocation(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AccessLocation)
		this->_Inst_AccessLocation = new TElGeneralName(hOutResult, ohFalse);
	else
		this->_Inst_AccessLocation->updateHandle(hOutResult);
	return this->_Inst_AccessLocation;
}
#endif /* SB_USE_CLASS_TELGENERALNAME */

void TElAccessDescription::initInstances()
{
#ifdef SB_USE_CLASS_TELGENERALNAME
	this->_Inst_AccessLocation = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
}

TElAccessDescription::TElAccessDescription(TElAccessDescriptionHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElAccessDescription::TElAccessDescription() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAccessDescription_Create(&_Handle));
}

TElAccessDescription::~TElAccessDescription()
{
#ifdef SB_USE_CLASS_TELGENERALNAME
	delete this->_Inst_AccessLocation;
	this->_Inst_AccessLocation = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
}
#endif /* SB_USE_CLASS_TELACCESSDESCRIPTION */

#ifdef SB_USE_CLASS_TELAUTHORITYINFORMATIONACCESSEXTENSION

SB_INLINE void TElAuthorityInformationAccessExtension::Remove(int32_t Index)
{
	SBCheckError(TElAuthorityInformationAccessExtension_Remove(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELACCESSDESCRIPTION
TElAccessDescription* TElAuthorityInformationAccessExtension::get_AccessDescriptions(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAuthorityInformationAccessExtension_get_AccessDescriptions(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AccessDescriptions)
		this->_Inst_AccessDescriptions = new TElAccessDescription(hOutResult, ohFalse);
	else
		this->_Inst_AccessDescriptions->updateHandle(hOutResult);
	return this->_Inst_AccessDescriptions;
}
#endif /* SB_USE_CLASS_TELACCESSDESCRIPTION */

SB_INLINE int32_t TElAuthorityInformationAccessExtension::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElAuthorityInformationAccessExtension_get_Count(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElAuthorityInformationAccessExtension::set_Count(int32_t Value)
{
	SBCheckError(TElAuthorityInformationAccessExtension_set_Count(_Handle, Value));
}

void TElAuthorityInformationAccessExtension::initInstances()
{
#ifdef SB_USE_CLASS_TELACCESSDESCRIPTION
	this->_Inst_AccessDescriptions = NULL;
#endif /* SB_USE_CLASS_TELACCESSDESCRIPTION */
}

TElAuthorityInformationAccessExtension::TElAuthorityInformationAccessExtension(TElAuthorityInformationAccessExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
	initInstances();
}

TElAuthorityInformationAccessExtension::TElAuthorityInformationAccessExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAuthorityInformationAccessExtension_Create(&_Handle));
}

TElAuthorityInformationAccessExtension::~TElAuthorityInformationAccessExtension()
{
#ifdef SB_USE_CLASS_TELACCESSDESCRIPTION
	delete this->_Inst_AccessDescriptions;
	this->_Inst_AccessDescriptions = NULL;
#endif /* SB_USE_CLASS_TELACCESSDESCRIPTION */
}
#endif /* SB_USE_CLASS_TELAUTHORITYINFORMATIONACCESSEXTENSION */

#ifdef SB_USE_CLASS_TELSUBJECTDIRECTORYATTRIBUTESEXTENSION

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
TElPKCS7Attributes* TElSubjectDirectoryAttributesExtension::get_Attributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSubjectDirectoryAttributesExtension_get_Attributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Attributes)
		this->_Inst_Attributes = new TElPKCS7Attributes(hOutResult, ohFalse);
	else
		this->_Inst_Attributes->updateHandle(hOutResult);
	return this->_Inst_Attributes;
}
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

void TElSubjectDirectoryAttributesExtension::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
}

TElSubjectDirectoryAttributesExtension::TElSubjectDirectoryAttributesExtension(TElSubjectDirectoryAttributesExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
	initInstances();
}

TElSubjectDirectoryAttributesExtension::TElSubjectDirectoryAttributesExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSubjectDirectoryAttributesExtension_Create(&_Handle));
}

TElSubjectDirectoryAttributesExtension::~TElSubjectDirectoryAttributesExtension()
{
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	delete this->_Inst_Attributes;
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
}
#endif /* SB_USE_CLASS_TELSUBJECTDIRECTORYATTRIBUTESEXTENSION */

#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS

bool TElCertificateExtensions::RemoveOther(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertificateExtensions_RemoveOther(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCertificateExtensions::ClearExtensions()
{
	SBCheckError(TElCertificateExtensions_ClearExtensions(_Handle));
}

#ifdef SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIEREXTENSION
TElAuthorityKeyIdentifierExtension* TElCertificateExtensions::get_AuthorityKeyIdentifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_AuthorityKeyIdentifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AuthorityKeyIdentifier)
		this->_Inst_AuthorityKeyIdentifier = new TElAuthorityKeyIdentifierExtension(hOutResult, ohFalse);
	else
		this->_Inst_AuthorityKeyIdentifier->updateHandle(hOutResult);
	return this->_Inst_AuthorityKeyIdentifier;
}
#endif /* SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIEREXTENSION */

#ifdef SB_USE_CLASS_TELSUBJECTKEYIDENTIFIEREXTENSION
TElSubjectKeyIdentifierExtension* TElCertificateExtensions::get_SubjectKeyIdentifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_SubjectKeyIdentifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SubjectKeyIdentifier)
		this->_Inst_SubjectKeyIdentifier = new TElSubjectKeyIdentifierExtension(hOutResult, ohFalse);
	else
		this->_Inst_SubjectKeyIdentifier->updateHandle(hOutResult);
	return this->_Inst_SubjectKeyIdentifier;
}
#endif /* SB_USE_CLASS_TELSUBJECTKEYIDENTIFIEREXTENSION */

#ifdef SB_USE_CLASS_TELKEYUSAGEEXTENSION
TElKeyUsageExtension* TElCertificateExtensions::get_KeyUsage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_KeyUsage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyUsage)
		this->_Inst_KeyUsage = new TElKeyUsageExtension(hOutResult, ohFalse);
	else
		this->_Inst_KeyUsage->updateHandle(hOutResult);
	return this->_Inst_KeyUsage;
}

SB_INLINE void TElCertificateExtensions::set_KeyUsage(TElKeyUsageExtension &Value)
{
	SBCheckError(TElCertificateExtensions_set_KeyUsage(_Handle, Value.getHandle()));
}

SB_INLINE void TElCertificateExtensions::set_KeyUsage(TElKeyUsageExtension *Value)
{
	SBCheckError(TElCertificateExtensions_set_KeyUsage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELKEYUSAGEEXTENSION */

#ifdef SB_USE_CLASS_TELPRIVATEKEYUSAGEPERIODEXTENSION
TElPrivateKeyUsagePeriodExtension* TElCertificateExtensions::get_PrivateKeyUsagePeriod()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_PrivateKeyUsagePeriod(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PrivateKeyUsagePeriod)
		this->_Inst_PrivateKeyUsagePeriod = new TElPrivateKeyUsagePeriodExtension(hOutResult, ohFalse);
	else
		this->_Inst_PrivateKeyUsagePeriod->updateHandle(hOutResult);
	return this->_Inst_PrivateKeyUsagePeriod;
}

SB_INLINE void TElCertificateExtensions::set_PrivateKeyUsagePeriod(TElPrivateKeyUsagePeriodExtension &Value)
{
	SBCheckError(TElCertificateExtensions_set_PrivateKeyUsagePeriod(_Handle, Value.getHandle()));
}

SB_INLINE void TElCertificateExtensions::set_PrivateKeyUsagePeriod(TElPrivateKeyUsagePeriodExtension *Value)
{
	SBCheckError(TElCertificateExtensions_set_PrivateKeyUsagePeriod(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPRIVATEKEYUSAGEPERIODEXTENSION */

#ifdef SB_USE_CLASS_TELCERTIFICATEPOLICIESEXTENSION
TElCertificatePoliciesExtension* TElCertificateExtensions::get_CertificatePolicies()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_CertificatePolicies(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertificatePolicies)
		this->_Inst_CertificatePolicies = new TElCertificatePoliciesExtension(hOutResult, ohFalse);
	else
		this->_Inst_CertificatePolicies->updateHandle(hOutResult);
	return this->_Inst_CertificatePolicies;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEPOLICIESEXTENSION */

#ifdef SB_USE_CLASS_TELPOLICYMAPPINGSEXTENSION
TElPolicyMappingsExtension* TElCertificateExtensions::get_PolicyMappings()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_PolicyMappings(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PolicyMappings)
		this->_Inst_PolicyMappings = new TElPolicyMappingsExtension(hOutResult, ohFalse);
	else
		this->_Inst_PolicyMappings->updateHandle(hOutResult);
	return this->_Inst_PolicyMappings;
}

SB_INLINE void TElCertificateExtensions::set_PolicyMappings(TElPolicyMappingsExtension &Value)
{
	SBCheckError(TElCertificateExtensions_set_PolicyMappings(_Handle, Value.getHandle()));
}

SB_INLINE void TElCertificateExtensions::set_PolicyMappings(TElPolicyMappingsExtension *Value)
{
	SBCheckError(TElCertificateExtensions_set_PolicyMappings(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPOLICYMAPPINGSEXTENSION */

#ifdef SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION
TElAlternativeNameExtension* TElCertificateExtensions::get_SubjectAlternativeName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_SubjectAlternativeName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SubjectAlternativeName)
		this->_Inst_SubjectAlternativeName = new TElAlternativeNameExtension(hOutResult, ohFalse);
	else
		this->_Inst_SubjectAlternativeName->updateHandle(hOutResult);
	return this->_Inst_SubjectAlternativeName;
}

SB_INLINE void TElCertificateExtensions::set_SubjectAlternativeName(TElAlternativeNameExtension &Value)
{
	SBCheckError(TElCertificateExtensions_set_SubjectAlternativeName(_Handle, Value.getHandle()));
}

SB_INLINE void TElCertificateExtensions::set_SubjectAlternativeName(TElAlternativeNameExtension *Value)
{
	SBCheckError(TElCertificateExtensions_set_SubjectAlternativeName(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION */

#ifdef SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION
TElAlternativeNameExtension* TElCertificateExtensions::get_IssuerAlternativeName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_IssuerAlternativeName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IssuerAlternativeName)
		this->_Inst_IssuerAlternativeName = new TElAlternativeNameExtension(hOutResult, ohFalse);
	else
		this->_Inst_IssuerAlternativeName->updateHandle(hOutResult);
	return this->_Inst_IssuerAlternativeName;
}

SB_INLINE void TElCertificateExtensions::set_IssuerAlternativeName(TElAlternativeNameExtension &Value)
{
	SBCheckError(TElCertificateExtensions_set_IssuerAlternativeName(_Handle, Value.getHandle()));
}

SB_INLINE void TElCertificateExtensions::set_IssuerAlternativeName(TElAlternativeNameExtension *Value)
{
	SBCheckError(TElCertificateExtensions_set_IssuerAlternativeName(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION */

#ifdef SB_USE_CLASS_TELBASICCONSTRAINTSEXTENSION
TElBasicConstraintsExtension* TElCertificateExtensions::get_BasicConstraints()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_BasicConstraints(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_BasicConstraints)
		this->_Inst_BasicConstraints = new TElBasicConstraintsExtension(hOutResult, ohFalse);
	else
		this->_Inst_BasicConstraints->updateHandle(hOutResult);
	return this->_Inst_BasicConstraints;
}

SB_INLINE void TElCertificateExtensions::set_BasicConstraints(TElBasicConstraintsExtension &Value)
{
	SBCheckError(TElCertificateExtensions_set_BasicConstraints(_Handle, Value.getHandle()));
}

SB_INLINE void TElCertificateExtensions::set_BasicConstraints(TElBasicConstraintsExtension *Value)
{
	SBCheckError(TElCertificateExtensions_set_BasicConstraints(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELBASICCONSTRAINTSEXTENSION */

#ifdef SB_USE_CLASS_TELNAMECONSTRAINTSEXTENSION
TElNameConstraintsExtension* TElCertificateExtensions::get_NameConstraints()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_NameConstraints(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NameConstraints)
		this->_Inst_NameConstraints = new TElNameConstraintsExtension(hOutResult, ohFalse);
	else
		this->_Inst_NameConstraints->updateHandle(hOutResult);
	return this->_Inst_NameConstraints;
}
#endif /* SB_USE_CLASS_TELNAMECONSTRAINTSEXTENSION */

#ifdef SB_USE_CLASS_TELPOLICYCONSTRAINTSEXTENSION
TElPolicyConstraintsExtension* TElCertificateExtensions::get_PolicyConstraints()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_PolicyConstraints(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PolicyConstraints)
		this->_Inst_PolicyConstraints = new TElPolicyConstraintsExtension(hOutResult, ohFalse);
	else
		this->_Inst_PolicyConstraints->updateHandle(hOutResult);
	return this->_Inst_PolicyConstraints;
}

SB_INLINE void TElCertificateExtensions::set_PolicyConstraints(TElPolicyConstraintsExtension &Value)
{
	SBCheckError(TElCertificateExtensions_set_PolicyConstraints(_Handle, Value.getHandle()));
}

SB_INLINE void TElCertificateExtensions::set_PolicyConstraints(TElPolicyConstraintsExtension *Value)
{
	SBCheckError(TElCertificateExtensions_set_PolicyConstraints(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPOLICYCONSTRAINTSEXTENSION */

#ifdef SB_USE_CLASS_TELEXTENDEDKEYUSAGEEXTENSION
TElExtendedKeyUsageExtension* TElCertificateExtensions::get_ExtendedKeyUsage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_ExtendedKeyUsage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ExtendedKeyUsage)
		this->_Inst_ExtendedKeyUsage = new TElExtendedKeyUsageExtension(hOutResult, ohFalse);
	else
		this->_Inst_ExtendedKeyUsage->updateHandle(hOutResult);
	return this->_Inst_ExtendedKeyUsage;
}
#endif /* SB_USE_CLASS_TELEXTENDEDKEYUSAGEEXTENSION */

#ifdef SB_USE_CLASS_TELCRLDISTRIBUTIONPOINTSEXTENSION
TElCRLDistributionPointsExtension* TElCertificateExtensions::get_CRLDistributionPoints()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_CRLDistributionPoints(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLDistributionPoints)
		this->_Inst_CRLDistributionPoints = new TElCRLDistributionPointsExtension(hOutResult, ohFalse);
	else
		this->_Inst_CRLDistributionPoints->updateHandle(hOutResult);
	return this->_Inst_CRLDistributionPoints;
}
#endif /* SB_USE_CLASS_TELCRLDISTRIBUTIONPOINTSEXTENSION */

#ifdef SB_USE_CLASS_TELAUTHORITYINFORMATIONACCESSEXTENSION
TElAuthorityInformationAccessExtension* TElCertificateExtensions::get_AuthorityInformationAccess()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_AuthorityInformationAccess(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AuthorityInformationAccess)
		this->_Inst_AuthorityInformationAccess = new TElAuthorityInformationAccessExtension(hOutResult, ohFalse);
	else
		this->_Inst_AuthorityInformationAccess->updateHandle(hOutResult);
	return this->_Inst_AuthorityInformationAccess;
}
#endif /* SB_USE_CLASS_TELAUTHORITYINFORMATIONACCESSEXTENSION */

#ifdef SB_USE_CLASS_TELNETSCAPECERTTYPEEXTENSION
TElNetscapeCertTypeExtension* TElCertificateExtensions::get_NetscapeCertType()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_NetscapeCertType(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NetscapeCertType)
		this->_Inst_NetscapeCertType = new TElNetscapeCertTypeExtension(hOutResult, ohFalse);
	else
		this->_Inst_NetscapeCertType->updateHandle(hOutResult);
	return this->_Inst_NetscapeCertType;
}

SB_INLINE void TElCertificateExtensions::set_NetscapeCertType(TElNetscapeCertTypeExtension &Value)
{
	SBCheckError(TElCertificateExtensions_set_NetscapeCertType(_Handle, Value.getHandle()));
}

SB_INLINE void TElCertificateExtensions::set_NetscapeCertType(TElNetscapeCertTypeExtension *Value)
{
	SBCheckError(TElCertificateExtensions_set_NetscapeCertType(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELNETSCAPECERTTYPEEXTENSION */

#ifdef SB_USE_CLASS_TELNETSCAPECOMMENT
TElNetscapeComment* TElCertificateExtensions::get_NetscapeComment()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_NetscapeComment(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NetscapeComment)
		this->_Inst_NetscapeComment = new TElNetscapeComment(hOutResult, ohFalse);
	else
		this->_Inst_NetscapeComment->updateHandle(hOutResult);
	return this->_Inst_NetscapeComment;
}

SB_INLINE void TElCertificateExtensions::set_NetscapeComment(TElNetscapeComment &Value)
{
	SBCheckError(TElCertificateExtensions_set_NetscapeComment(_Handle, Value.getHandle()));
}

SB_INLINE void TElCertificateExtensions::set_NetscapeComment(TElNetscapeComment *Value)
{
	SBCheckError(TElCertificateExtensions_set_NetscapeComment(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELNETSCAPECOMMENT */

#ifdef SB_USE_CLASS_TELNETSCAPEBASEURL
TElNetscapeBaseURL* TElCertificateExtensions::get_NetscapeBaseURL()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_NetscapeBaseURL(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NetscapeBaseURL)
		this->_Inst_NetscapeBaseURL = new TElNetscapeBaseURL(hOutResult, ohFalse);
	else
		this->_Inst_NetscapeBaseURL->updateHandle(hOutResult);
	return this->_Inst_NetscapeBaseURL;
}

SB_INLINE void TElCertificateExtensions::set_NetscapeBaseURL(TElNetscapeBaseURL &Value)
{
	SBCheckError(TElCertificateExtensions_set_NetscapeBaseURL(_Handle, Value.getHandle()));
}

SB_INLINE void TElCertificateExtensions::set_NetscapeBaseURL(TElNetscapeBaseURL *Value)
{
	SBCheckError(TElCertificateExtensions_set_NetscapeBaseURL(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELNETSCAPEBASEURL */

#ifdef SB_USE_CLASS_TELNETSCAPEREVOKEURL
TElNetscapeRevokeURL* TElCertificateExtensions::get_NetscapeRevokeURL()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_NetscapeRevokeURL(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NetscapeRevokeURL)
		this->_Inst_NetscapeRevokeURL = new TElNetscapeRevokeURL(hOutResult, ohFalse);
	else
		this->_Inst_NetscapeRevokeURL->updateHandle(hOutResult);
	return this->_Inst_NetscapeRevokeURL;
}

SB_INLINE void TElCertificateExtensions::set_NetscapeRevokeURL(TElNetscapeRevokeURL &Value)
{
	SBCheckError(TElCertificateExtensions_set_NetscapeRevokeURL(_Handle, Value.getHandle()));
}

SB_INLINE void TElCertificateExtensions::set_NetscapeRevokeURL(TElNetscapeRevokeURL *Value)
{
	SBCheckError(TElCertificateExtensions_set_NetscapeRevokeURL(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELNETSCAPEREVOKEURL */

#ifdef SB_USE_CLASS_TELNETSCAPECAREVOKEURL
TElNetscapeCARevokeURL* TElCertificateExtensions::get_NetscapeCARevokeURL()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_NetscapeCARevokeURL(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NetscapeCARevokeURL)
		this->_Inst_NetscapeCARevokeURL = new TElNetscapeCARevokeURL(hOutResult, ohFalse);
	else
		this->_Inst_NetscapeCARevokeURL->updateHandle(hOutResult);
	return this->_Inst_NetscapeCARevokeURL;
}

SB_INLINE void TElCertificateExtensions::set_NetscapeCARevokeURL(TElNetscapeCARevokeURL &Value)
{
	SBCheckError(TElCertificateExtensions_set_NetscapeCARevokeURL(_Handle, Value.getHandle()));
}

SB_INLINE void TElCertificateExtensions::set_NetscapeCARevokeURL(TElNetscapeCARevokeURL *Value)
{
	SBCheckError(TElCertificateExtensions_set_NetscapeCARevokeURL(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELNETSCAPECAREVOKEURL */

#ifdef SB_USE_CLASS_TELNETSCAPERENEWALURL
TElNetscapeRenewalURL* TElCertificateExtensions::get_NetscapeRenewalURL()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_NetscapeRenewalURL(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NetscapeRenewalURL)
		this->_Inst_NetscapeRenewalURL = new TElNetscapeRenewalURL(hOutResult, ohFalse);
	else
		this->_Inst_NetscapeRenewalURL->updateHandle(hOutResult);
	return this->_Inst_NetscapeRenewalURL;
}

SB_INLINE void TElCertificateExtensions::set_NetscapeRenewalURL(TElNetscapeRenewalURL &Value)
{
	SBCheckError(TElCertificateExtensions_set_NetscapeRenewalURL(_Handle, Value.getHandle()));
}

SB_INLINE void TElCertificateExtensions::set_NetscapeRenewalURL(TElNetscapeRenewalURL *Value)
{
	SBCheckError(TElCertificateExtensions_set_NetscapeRenewalURL(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELNETSCAPERENEWALURL */

#ifdef SB_USE_CLASS_TELNETSCAPECAPOLICY
TElNetscapeCAPolicy* TElCertificateExtensions::get_NetscapeCAPolicy()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_NetscapeCAPolicy(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NetscapeCAPolicy)
		this->_Inst_NetscapeCAPolicy = new TElNetscapeCAPolicy(hOutResult, ohFalse);
	else
		this->_Inst_NetscapeCAPolicy->updateHandle(hOutResult);
	return this->_Inst_NetscapeCAPolicy;
}

SB_INLINE void TElCertificateExtensions::set_NetscapeCAPolicy(TElNetscapeCAPolicy &Value)
{
	SBCheckError(TElCertificateExtensions_set_NetscapeCAPolicy(_Handle, Value.getHandle()));
}

SB_INLINE void TElCertificateExtensions::set_NetscapeCAPolicy(TElNetscapeCAPolicy *Value)
{
	SBCheckError(TElCertificateExtensions_set_NetscapeCAPolicy(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELNETSCAPECAPOLICY */

#ifdef SB_USE_CLASS_TELNETSCAPESERVERNAME
TElNetscapeServerName* TElCertificateExtensions::get_NetscapeServerName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_NetscapeServerName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NetscapeServerName)
		this->_Inst_NetscapeServerName = new TElNetscapeServerName(hOutResult, ohFalse);
	else
		this->_Inst_NetscapeServerName->updateHandle(hOutResult);
	return this->_Inst_NetscapeServerName;
}

SB_INLINE void TElCertificateExtensions::set_NetscapeServerName(TElNetscapeServerName &Value)
{
	SBCheckError(TElCertificateExtensions_set_NetscapeServerName(_Handle, Value.getHandle()));
}

SB_INLINE void TElCertificateExtensions::set_NetscapeServerName(TElNetscapeServerName *Value)
{
	SBCheckError(TElCertificateExtensions_set_NetscapeServerName(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELNETSCAPESERVERNAME */

#ifdef SB_USE_CLASS_TELCOMMONNAME
TElCommonName* TElCertificateExtensions::get_CommonName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_CommonName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CommonName)
		this->_Inst_CommonName = new TElCommonName(hOutResult, ohFalse);
	else
		this->_Inst_CommonName->updateHandle(hOutResult);
	return this->_Inst_CommonName;
}

SB_INLINE void TElCertificateExtensions::set_CommonName(TElCommonName &Value)
{
	SBCheckError(TElCertificateExtensions_set_CommonName(_Handle, Value.getHandle()));
}

SB_INLINE void TElCertificateExtensions::set_CommonName(TElCommonName *Value)
{
	SBCheckError(TElCertificateExtensions_set_CommonName(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCOMMONNAME */

#ifdef SB_USE_CLASS_TELSUBJECTDIRECTORYATTRIBUTESEXTENSION
TElSubjectDirectoryAttributesExtension* TElCertificateExtensions::get_SubjectDirectoryAttributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_SubjectDirectoryAttributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SubjectDirectoryAttributes)
		this->_Inst_SubjectDirectoryAttributes = new TElSubjectDirectoryAttributesExtension(hOutResult, ohFalse);
	else
		this->_Inst_SubjectDirectoryAttributes->updateHandle(hOutResult);
	return this->_Inst_SubjectDirectoryAttributes;
}
#endif /* SB_USE_CLASS_TELSUBJECTDIRECTORYATTRIBUTESEXTENSION */

#ifdef SB_USE_CLASS_TELCUSTOMEXTENSION
TElCustomExtension* TElCertificateExtensions::get_OtherExtensions(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateExtensions_get_OtherExtensions(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OtherExtensions)
		this->_Inst_OtherExtensions = new TElCustomExtension(hOutResult, ohFalse);
	else
		this->_Inst_OtherExtensions->updateHandle(hOutResult);
	return this->_Inst_OtherExtensions;
}
#endif /* SB_USE_CLASS_TELCUSTOMEXTENSION */

SB_INLINE int32_t TElCertificateExtensions::get_OtherCount()
{
	int32_t OutResult;
	SBCheckError(TElCertificateExtensions_get_OtherCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCertificateExtensions::set_OtherCount(int32_t Value)
{
	SBCheckError(TElCertificateExtensions_set_OtherCount(_Handle, Value));
}

TSBCertificateExtensions TElCertificateExtensions::get_Included()
{
	TSBCertificateExtensionsRaw OutResultRaw = 0;
	SBCheckError(TElCertificateExtensions_get_Included(_Handle, &OutResultRaw));
	return (TSBCertificateExtensions)OutResultRaw;
}

SB_INLINE void TElCertificateExtensions::set_Included(TSBCertificateExtensions Value)
{
	SBCheckError(TElCertificateExtensions_set_Included(_Handle, (TSBCertificateExtensionsRaw)Value));
}

void TElCertificateExtensions::initInstances()
{
#ifdef SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIEREXTENSION
	this->_Inst_AuthorityKeyIdentifier = NULL;
#endif /* SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIEREXTENSION */
#ifdef SB_USE_CLASS_TELSUBJECTKEYIDENTIFIEREXTENSION
	this->_Inst_SubjectKeyIdentifier = NULL;
#endif /* SB_USE_CLASS_TELSUBJECTKEYIDENTIFIEREXTENSION */
#ifdef SB_USE_CLASS_TELKEYUSAGEEXTENSION
	this->_Inst_KeyUsage = NULL;
#endif /* SB_USE_CLASS_TELKEYUSAGEEXTENSION */
#ifdef SB_USE_CLASS_TELPRIVATEKEYUSAGEPERIODEXTENSION
	this->_Inst_PrivateKeyUsagePeriod = NULL;
#endif /* SB_USE_CLASS_TELPRIVATEKEYUSAGEPERIODEXTENSION */
#ifdef SB_USE_CLASS_TELCERTIFICATEPOLICIESEXTENSION
	this->_Inst_CertificatePolicies = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEPOLICIESEXTENSION */
#ifdef SB_USE_CLASS_TELPOLICYMAPPINGSEXTENSION
	this->_Inst_PolicyMappings = NULL;
#endif /* SB_USE_CLASS_TELPOLICYMAPPINGSEXTENSION */
#ifdef SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION
	this->_Inst_SubjectAlternativeName = NULL;
#endif /* SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION */
#ifdef SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION
	this->_Inst_IssuerAlternativeName = NULL;
#endif /* SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION */
#ifdef SB_USE_CLASS_TELBASICCONSTRAINTSEXTENSION
	this->_Inst_BasicConstraints = NULL;
#endif /* SB_USE_CLASS_TELBASICCONSTRAINTSEXTENSION */
#ifdef SB_USE_CLASS_TELNAMECONSTRAINTSEXTENSION
	this->_Inst_NameConstraints = NULL;
#endif /* SB_USE_CLASS_TELNAMECONSTRAINTSEXTENSION */
#ifdef SB_USE_CLASS_TELPOLICYCONSTRAINTSEXTENSION
	this->_Inst_PolicyConstraints = NULL;
#endif /* SB_USE_CLASS_TELPOLICYCONSTRAINTSEXTENSION */
#ifdef SB_USE_CLASS_TELEXTENDEDKEYUSAGEEXTENSION
	this->_Inst_ExtendedKeyUsage = NULL;
#endif /* SB_USE_CLASS_TELEXTENDEDKEYUSAGEEXTENSION */
#ifdef SB_USE_CLASS_TELCRLDISTRIBUTIONPOINTSEXTENSION
	this->_Inst_CRLDistributionPoints = NULL;
#endif /* SB_USE_CLASS_TELCRLDISTRIBUTIONPOINTSEXTENSION */
#ifdef SB_USE_CLASS_TELAUTHORITYINFORMATIONACCESSEXTENSION
	this->_Inst_AuthorityInformationAccess = NULL;
#endif /* SB_USE_CLASS_TELAUTHORITYINFORMATIONACCESSEXTENSION */
#ifdef SB_USE_CLASS_TELNETSCAPECERTTYPEEXTENSION
	this->_Inst_NetscapeCertType = NULL;
#endif /* SB_USE_CLASS_TELNETSCAPECERTTYPEEXTENSION */
#ifdef SB_USE_CLASS_TELNETSCAPECOMMENT
	this->_Inst_NetscapeComment = NULL;
#endif /* SB_USE_CLASS_TELNETSCAPECOMMENT */
#ifdef SB_USE_CLASS_TELNETSCAPEBASEURL
	this->_Inst_NetscapeBaseURL = NULL;
#endif /* SB_USE_CLASS_TELNETSCAPEBASEURL */
#ifdef SB_USE_CLASS_TELNETSCAPEREVOKEURL
	this->_Inst_NetscapeRevokeURL = NULL;
#endif /* SB_USE_CLASS_TELNETSCAPEREVOKEURL */
#ifdef SB_USE_CLASS_TELNETSCAPECAREVOKEURL
	this->_Inst_NetscapeCARevokeURL = NULL;
#endif /* SB_USE_CLASS_TELNETSCAPECAREVOKEURL */
#ifdef SB_USE_CLASS_TELNETSCAPERENEWALURL
	this->_Inst_NetscapeRenewalURL = NULL;
#endif /* SB_USE_CLASS_TELNETSCAPERENEWALURL */
#ifdef SB_USE_CLASS_TELNETSCAPECAPOLICY
	this->_Inst_NetscapeCAPolicy = NULL;
#endif /* SB_USE_CLASS_TELNETSCAPECAPOLICY */
#ifdef SB_USE_CLASS_TELNETSCAPESERVERNAME
	this->_Inst_NetscapeServerName = NULL;
#endif /* SB_USE_CLASS_TELNETSCAPESERVERNAME */
#ifdef SB_USE_CLASS_TELCOMMONNAME
	this->_Inst_CommonName = NULL;
#endif /* SB_USE_CLASS_TELCOMMONNAME */
#ifdef SB_USE_CLASS_TELSUBJECTDIRECTORYATTRIBUTESEXTENSION
	this->_Inst_SubjectDirectoryAttributes = NULL;
#endif /* SB_USE_CLASS_TELSUBJECTDIRECTORYATTRIBUTESEXTENSION */
#ifdef SB_USE_CLASS_TELCUSTOMEXTENSION
	this->_Inst_OtherExtensions = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMEXTENSION */
}

TElCertificateExtensions::TElCertificateExtensions(TElCertificateExtensionsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCertificateExtensions::TElCertificateExtensions() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCertificateExtensions_Create(&_Handle));
}

TElCertificateExtensions::~TElCertificateExtensions()
{
#ifdef SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIEREXTENSION
	delete this->_Inst_AuthorityKeyIdentifier;
	this->_Inst_AuthorityKeyIdentifier = NULL;
#endif /* SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIEREXTENSION */
#ifdef SB_USE_CLASS_TELSUBJECTKEYIDENTIFIEREXTENSION
	delete this->_Inst_SubjectKeyIdentifier;
	this->_Inst_SubjectKeyIdentifier = NULL;
#endif /* SB_USE_CLASS_TELSUBJECTKEYIDENTIFIEREXTENSION */
#ifdef SB_USE_CLASS_TELKEYUSAGEEXTENSION
	delete this->_Inst_KeyUsage;
	this->_Inst_KeyUsage = NULL;
#endif /* SB_USE_CLASS_TELKEYUSAGEEXTENSION */
#ifdef SB_USE_CLASS_TELPRIVATEKEYUSAGEPERIODEXTENSION
	delete this->_Inst_PrivateKeyUsagePeriod;
	this->_Inst_PrivateKeyUsagePeriod = NULL;
#endif /* SB_USE_CLASS_TELPRIVATEKEYUSAGEPERIODEXTENSION */
#ifdef SB_USE_CLASS_TELCERTIFICATEPOLICIESEXTENSION
	delete this->_Inst_CertificatePolicies;
	this->_Inst_CertificatePolicies = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEPOLICIESEXTENSION */
#ifdef SB_USE_CLASS_TELPOLICYMAPPINGSEXTENSION
	delete this->_Inst_PolicyMappings;
	this->_Inst_PolicyMappings = NULL;
#endif /* SB_USE_CLASS_TELPOLICYMAPPINGSEXTENSION */
#ifdef SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION
	delete this->_Inst_SubjectAlternativeName;
	this->_Inst_SubjectAlternativeName = NULL;
#endif /* SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION */
#ifdef SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION
	delete this->_Inst_IssuerAlternativeName;
	this->_Inst_IssuerAlternativeName = NULL;
#endif /* SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION */
#ifdef SB_USE_CLASS_TELBASICCONSTRAINTSEXTENSION
	delete this->_Inst_BasicConstraints;
	this->_Inst_BasicConstraints = NULL;
#endif /* SB_USE_CLASS_TELBASICCONSTRAINTSEXTENSION */
#ifdef SB_USE_CLASS_TELNAMECONSTRAINTSEXTENSION
	delete this->_Inst_NameConstraints;
	this->_Inst_NameConstraints = NULL;
#endif /* SB_USE_CLASS_TELNAMECONSTRAINTSEXTENSION */
#ifdef SB_USE_CLASS_TELPOLICYCONSTRAINTSEXTENSION
	delete this->_Inst_PolicyConstraints;
	this->_Inst_PolicyConstraints = NULL;
#endif /* SB_USE_CLASS_TELPOLICYCONSTRAINTSEXTENSION */
#ifdef SB_USE_CLASS_TELEXTENDEDKEYUSAGEEXTENSION
	delete this->_Inst_ExtendedKeyUsage;
	this->_Inst_ExtendedKeyUsage = NULL;
#endif /* SB_USE_CLASS_TELEXTENDEDKEYUSAGEEXTENSION */
#ifdef SB_USE_CLASS_TELCRLDISTRIBUTIONPOINTSEXTENSION
	delete this->_Inst_CRLDistributionPoints;
	this->_Inst_CRLDistributionPoints = NULL;
#endif /* SB_USE_CLASS_TELCRLDISTRIBUTIONPOINTSEXTENSION */
#ifdef SB_USE_CLASS_TELAUTHORITYINFORMATIONACCESSEXTENSION
	delete this->_Inst_AuthorityInformationAccess;
	this->_Inst_AuthorityInformationAccess = NULL;
#endif /* SB_USE_CLASS_TELAUTHORITYINFORMATIONACCESSEXTENSION */
#ifdef SB_USE_CLASS_TELNETSCAPECERTTYPEEXTENSION
	delete this->_Inst_NetscapeCertType;
	this->_Inst_NetscapeCertType = NULL;
#endif /* SB_USE_CLASS_TELNETSCAPECERTTYPEEXTENSION */
#ifdef SB_USE_CLASS_TELNETSCAPECOMMENT
	delete this->_Inst_NetscapeComment;
	this->_Inst_NetscapeComment = NULL;
#endif /* SB_USE_CLASS_TELNETSCAPECOMMENT */
#ifdef SB_USE_CLASS_TELNETSCAPEBASEURL
	delete this->_Inst_NetscapeBaseURL;
	this->_Inst_NetscapeBaseURL = NULL;
#endif /* SB_USE_CLASS_TELNETSCAPEBASEURL */
#ifdef SB_USE_CLASS_TELNETSCAPEREVOKEURL
	delete this->_Inst_NetscapeRevokeURL;
	this->_Inst_NetscapeRevokeURL = NULL;
#endif /* SB_USE_CLASS_TELNETSCAPEREVOKEURL */
#ifdef SB_USE_CLASS_TELNETSCAPECAREVOKEURL
	delete this->_Inst_NetscapeCARevokeURL;
	this->_Inst_NetscapeCARevokeURL = NULL;
#endif /* SB_USE_CLASS_TELNETSCAPECAREVOKEURL */
#ifdef SB_USE_CLASS_TELNETSCAPERENEWALURL
	delete this->_Inst_NetscapeRenewalURL;
	this->_Inst_NetscapeRenewalURL = NULL;
#endif /* SB_USE_CLASS_TELNETSCAPERENEWALURL */
#ifdef SB_USE_CLASS_TELNETSCAPECAPOLICY
	delete this->_Inst_NetscapeCAPolicy;
	this->_Inst_NetscapeCAPolicy = NULL;
#endif /* SB_USE_CLASS_TELNETSCAPECAPOLICY */
#ifdef SB_USE_CLASS_TELNETSCAPESERVERNAME
	delete this->_Inst_NetscapeServerName;
	this->_Inst_NetscapeServerName = NULL;
#endif /* SB_USE_CLASS_TELNETSCAPESERVERNAME */
#ifdef SB_USE_CLASS_TELCOMMONNAME
	delete this->_Inst_CommonName;
	this->_Inst_CommonName = NULL;
#endif /* SB_USE_CLASS_TELCOMMONNAME */
#ifdef SB_USE_CLASS_TELSUBJECTDIRECTORYATTRIBUTESEXTENSION
	delete this->_Inst_SubjectDirectoryAttributes;
	this->_Inst_SubjectDirectoryAttributes = NULL;
#endif /* SB_USE_CLASS_TELSUBJECTDIRECTORYATTRIBUTESEXTENSION */
#ifdef SB_USE_CLASS_TELCUSTOMEXTENSION
	delete this->_Inst_OtherExtensions;
	this->_Inst_OtherExtensions = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMEXTENSION */
}
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

#ifdef SB_USE_CLASS_TELEXTENSIONWRITER

void TElExtensionWriter::WriteExtensions(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteExtensions(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-144693517, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElExtensionWriter::WriteExtension(const std::vector<uint8_t> &OID, bool Critical, const std::vector<uint8_t> &Value, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteExtension(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (int8_t)Critical, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-27807939, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElExtensionWriter::WriteExtensionBasicConstraints(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteExtensionBasicConstraints(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(152013425, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElExtensionWriter::WriteExtensionKeyUsage(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteExtensionKeyUsage(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1739618898, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElExtensionWriter::WriteExtensionPrivateKeyUsagePeriod(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteExtensionPrivateKeyUsagePeriod(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1389830203, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElExtensionWriter::WriteExtensionSubjectAltName(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteExtensionSubjectAltName(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-334461408, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElExtensionWriter::WriteExtensionIssuerAltName(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteExtensionIssuerAltName(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1438052204, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElExtensionWriter::WriteExtensionExtendedKeyUsage(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteExtensionExtendedKeyUsage(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2007074196, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElExtensionWriter::WriteExtensionPolicyMappings(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteExtensionPolicyMappings(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1584470639, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElExtensionWriter::WriteExtensionNameConstraints(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteExtensionNameConstraints(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1308625497, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElExtensionWriter::WriteExtensionPolicyConstraints(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteExtensionPolicyConstraints(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2007193073, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElExtensionWriter::WriteExtensionCertificatePolicies(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteExtensionCertificatePolicies(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1554710930, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElExtensionWriter::WriteExtensionAuthorityKeyIdentifier(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteExtensionAuthorityKeyIdentifier(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(749800196, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElExtensionWriter::WriteExtensionCRLDistributionPoints(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteExtensionCRLDistributionPoints(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2103197934, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElExtensionWriter::WriteExtensionAuthorityInformationAccess(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteExtensionAuthorityInformationAccess(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2097448495, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElExtensionWriter::WriteExtensionNetscapeCertType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteExtensionNetscapeCertType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1878083983, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElExtensionWriter::WriteExtensionNetscapeString(const std::vector<uint8_t> &AOID, const std::string &ANetStr, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteExtensionNetscapeString(_Handle, SB_STD_VECTOR_FRONT_ADR(AOID), (int32_t)AOID.size(), ANetStr.data(), (int32_t)ANetStr.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(540736839, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElExtensionWriter::WriteExtensionNetscapeString(const std::vector<uint8_t> &AOID, const std::vector<uint8_t> &ANetStr, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteExtensionNetscapeString_1(_Handle, SB_STD_VECTOR_FRONT_ADR(AOID), (int32_t)AOID.size(), SB_STD_VECTOR_FRONT_ADR(ANetStr), (int32_t)ANetStr.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-940584895, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElExtensionWriter::WriteExtensionSubjectKeyIdentifier(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteExtensionSubjectKeyIdentifier(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(659569336, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELSINGLEPOLICYINFORMATION
void TElExtensionWriter::WritePolicyInformation(TElSinglePolicyInformation &P, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WritePolicyInformation(_Handle, P.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1970990079, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElExtensionWriter::WritePolicyInformation(TElSinglePolicyInformation *P, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WritePolicyInformation(_Handle, (P != NULL) ? P->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1970990079, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELSINGLEPOLICYINFORMATION */

#ifdef SB_USE_CLASS_TELDISTRIBUTIONPOINT
void TElExtensionWriter::WriteDistributionPoint(TElDistributionPoint &P, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteDistributionPoint(_Handle, P.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-48489755, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElExtensionWriter::WriteDistributionPoint(TElDistributionPoint *P, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteDistributionPoint(_Handle, (P != NULL) ? P->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-48489755, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELDISTRIBUTIONPOINT */

void TElExtensionWriter::WriteExtensionSubjectDirectoryAttributes(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElExtensionWriter_WriteExtensionSubjectDirectoryAttributes(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1200804254, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
TElCertificateExtensions* TElExtensionWriter::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElExtensionWriter_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElCertificateExtensions(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

bool TElExtensionWriter::get_UseA3Prefix()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElExtensionWriter_get_UseA3Prefix(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElExtensionWriter::set_UseA3Prefix(bool Value)
{
	SBCheckError(TElExtensionWriter_set_UseA3Prefix(_Handle, (int8_t)Value));
}

bool TElExtensionWriter::get_SaveDefaultASN1Tags()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElExtensionWriter_get_SaveDefaultASN1Tags(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElExtensionWriter::set_SaveDefaultASN1Tags(bool Value)
{
	SBCheckError(TElExtensionWriter_set_SaveDefaultASN1Tags(_Handle, (int8_t)Value));
}

void TElExtensionWriter::initInstances()
{
#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */
}

TElExtensionWriter::TElExtensionWriter(TElExtensionWriterHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
TElExtensionWriter::TElExtensionWriter(TElCertificateExtensions &Exts, bool CertExtensions) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElExtensionWriter_Create(Exts.getHandle(), (int8_t)CertExtensions, &_Handle));
}

TElExtensionWriter::TElExtensionWriter(TElCertificateExtensions *Exts, bool CertExtensions) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElExtensionWriter_Create((Exts != NULL) ? Exts->getHandle() : SB_NULL_HANDLE, (int8_t)CertExtensions, &_Handle));
}
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

TElExtensionWriter::~TElExtensionWriter()
{
#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */
}
#endif /* SB_USE_CLASS_TELEXTENSIONWRITER */

#ifdef SB_USE_CLASS_TELEXTENSIONREADER

SB_INLINE void TElExtensionReader::ParseExtension(const std::vector<uint8_t> &OID, bool Critical, const std::vector<uint8_t> &Content)
{
	SBCheckError(TElExtensionReader_ParseExtension(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (int8_t)Critical, SB_STD_VECTOR_FRONT_ADR(Content), (int32_t)Content.size()));
}

#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
TElCertificateExtensions* TElExtensionReader::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElExtensionReader_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElCertificateExtensions(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

void TElExtensionReader::initInstances()
{
#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */
}

TElExtensionReader::TElExtensionReader(TElExtensionReaderHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
TElExtensionReader::TElExtensionReader(TElCertificateExtensions &Exts, bool StrictMode) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElExtensionReader_Create(Exts.getHandle(), (int8_t)StrictMode, &_Handle));
}

TElExtensionReader::TElExtensionReader(TElCertificateExtensions *Exts, bool StrictMode) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElExtensionReader_Create((Exts != NULL) ? Exts->getHandle() : SB_NULL_HANDLE, (int8_t)StrictMode, &_Handle));
}
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

TElExtensionReader::~TElExtensionReader()
{
#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */
}
#endif /* SB_USE_CLASS_TELEXTENSIONREADER */

#ifdef SB_USE_GLOBAL_PROCS_X509EXT

void OctetsToIPAddress(const std::vector<uint8_t> &Octets, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBX509Ext_OctetsToIPAddress(SB_STD_VECTOR_FRONT_ADR(Octets), (int32_t)Octets.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-784648571, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void IPAddressToOctets(const std::string &IPAddrStr, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBX509Ext_IPAddressToOctets(IPAddrStr.data(), (int32_t)IPAddrStr.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(767294001, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#endif /* SB_USE_GLOBAL_PROCS_X509EXT */

};	/* namespace SecureBlackbox */

