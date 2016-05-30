#include "sbcrl.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIERCRLEXTENSION

void TElAuthorityKeyIdentifierCRLExtension::get_KeyIdentifier(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElAuthorityKeyIdentifierCRLExtension_get_KeyIdentifier(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-587054883, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAuthorityKeyIdentifierCRLExtension::set_KeyIdentifier(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElAuthorityKeyIdentifierCRLExtension_set_KeyIdentifier(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELGENERALNAMES
TElGeneralNames* TElAuthorityKeyIdentifierCRLExtension::get_AuthorityCertIssuer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAuthorityKeyIdentifierCRLExtension_get_AuthorityCertIssuer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AuthorityCertIssuer)
		this->_Inst_AuthorityCertIssuer = new TElGeneralNames(hOutResult, ohFalse);
	else
		this->_Inst_AuthorityCertIssuer->updateHandle(hOutResult);
	return this->_Inst_AuthorityCertIssuer;
}
#endif /* SB_USE_CLASS_TELGENERALNAMES */

void TElAuthorityKeyIdentifierCRLExtension::get_AuthorityCertSerial(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElAuthorityKeyIdentifierCRLExtension_get_AuthorityCertSerial(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(279879362, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElAuthorityKeyIdentifierCRLExtension::set_AuthorityCertSerial(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElAuthorityKeyIdentifierCRLExtension_set_AuthorityCertSerial(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElAuthorityKeyIdentifierCRLExtension::get_IssuerSet()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAuthorityKeyIdentifierCRLExtension_get_IssuerSet(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAuthorityKeyIdentifierCRLExtension::set_IssuerSet(bool Value)
{
	SBCheckError(TElAuthorityKeyIdentifierCRLExtension_set_IssuerSet(_Handle, (int8_t)Value));
}

void TElAuthorityKeyIdentifierCRLExtension::initInstances()
{
#ifdef SB_USE_CLASS_TELGENERALNAMES
	this->_Inst_AuthorityCertIssuer = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAMES */
}

TElAuthorityKeyIdentifierCRLExtension::TElAuthorityKeyIdentifierCRLExtension(TElAuthorityKeyIdentifierCRLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
	initInstances();
}

TElAuthorityKeyIdentifierCRLExtension::TElAuthorityKeyIdentifierCRLExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAuthorityKeyIdentifierCRLExtension_Create(&_Handle));
}

TElAuthorityKeyIdentifierCRLExtension::~TElAuthorityKeyIdentifierCRLExtension()
{
#ifdef SB_USE_CLASS_TELGENERALNAMES
	delete this->_Inst_AuthorityCertIssuer;
	this->_Inst_AuthorityCertIssuer = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAMES */
}
#endif /* SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIERCRLEXTENSION */

#ifdef SB_USE_CLASS_TELCRLNUMBERCRLEXTENSION

SB_INLINE int32_t TElCRLNumberCRLExtension::get_Number()
{
	int32_t OutResult;
	SBCheckError(TElCRLNumberCRLExtension_get_Number(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCRLNumberCRLExtension::set_Number(int32_t Value)
{
	SBCheckError(TElCRLNumberCRLExtension_set_Number(_Handle, Value));
}

void TElCRLNumberCRLExtension::get_BinaryNumber(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCRLNumberCRLExtension_get_BinaryNumber(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1831432506, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCRLNumberCRLExtension::set_BinaryNumber(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCRLNumberCRLExtension_set_BinaryNumber(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElCRLNumberCRLExtension::TElCRLNumberCRLExtension(TElCRLNumberCRLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
}

TElCRLNumberCRLExtension::TElCRLNumberCRLExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCRLNumberCRLExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCRLNUMBERCRLEXTENSION */

#ifdef SB_USE_CLASS_TELDELTACRLINDICATORCRLEXTENSION

SB_INLINE int32_t TElDeltaCRLIndicatorCRLExtension::get_Number()
{
	int32_t OutResult;
	SBCheckError(TElDeltaCRLIndicatorCRLExtension_get_Number(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElDeltaCRLIndicatorCRLExtension::set_Number(int32_t Value)
{
	SBCheckError(TElDeltaCRLIndicatorCRLExtension_set_Number(_Handle, Value));
}

void TElDeltaCRLIndicatorCRLExtension::get_BinaryNumber(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElDeltaCRLIndicatorCRLExtension_get_BinaryNumber(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1954288120, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElDeltaCRLIndicatorCRLExtension::set_BinaryNumber(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElDeltaCRLIndicatorCRLExtension_set_BinaryNumber(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElDeltaCRLIndicatorCRLExtension::TElDeltaCRLIndicatorCRLExtension(TElDeltaCRLIndicatorCRLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
}

TElDeltaCRLIndicatorCRLExtension::TElDeltaCRLIndicatorCRLExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDeltaCRLIndicatorCRLExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDELTACRLINDICATORCRLEXTENSION */

#ifdef SB_USE_CLASS_TELREASONCODECRLEXTENSION

TSBCRLReasonFlag TElReasonCodeCRLExtension::get_Reason()
{
	TSBCRLReasonFlagRaw OutResultRaw = 0;
	SBCheckError(TElReasonCodeCRLExtension_get_Reason(_Handle, &OutResultRaw));
	return (TSBCRLReasonFlag)OutResultRaw;
}

SB_INLINE void TElReasonCodeCRLExtension::set_Reason(TSBCRLReasonFlag Value)
{
	SBCheckError(TElReasonCodeCRLExtension_set_Reason(_Handle, (TSBCRLReasonFlagRaw)Value));
}

bool TElReasonCodeCRLExtension::get_RemoveFromCRL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElReasonCodeCRLExtension_get_RemoveFromCRL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElReasonCodeCRLExtension::set_RemoveFromCRL(bool Value)
{
	SBCheckError(TElReasonCodeCRLExtension_set_RemoveFromCRL(_Handle, (int8_t)Value));
}

TElReasonCodeCRLExtension::TElReasonCodeCRLExtension(TElReasonCodeCRLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
}

TElReasonCodeCRLExtension::TElReasonCodeCRLExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElReasonCodeCRLExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELREASONCODECRLEXTENSION */

#ifdef SB_USE_CLASS_TELHOLDINSTRUCTIONCODECRLEXTENSION

TElInstructionCode TElHoldInstructionCodeCRLExtension::get_Code()
{
	TElInstructionCodeRaw OutResultRaw = 0;
	SBCheckError(TElHoldInstructionCodeCRLExtension_get_Code(_Handle, &OutResultRaw));
	return (TElInstructionCode)OutResultRaw;
}

SB_INLINE void TElHoldInstructionCodeCRLExtension::set_Code(TElInstructionCode Value)
{
	SBCheckError(TElHoldInstructionCodeCRLExtension_set_Code(_Handle, (TElInstructionCodeRaw)Value));
}

TElHoldInstructionCodeCRLExtension::TElHoldInstructionCodeCRLExtension(TElHoldInstructionCodeCRLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
}

TElHoldInstructionCodeCRLExtension::TElHoldInstructionCodeCRLExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElHoldInstructionCodeCRLExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELHOLDINSTRUCTIONCODECRLEXTENSION */

#ifdef SB_USE_CLASS_TELINVALIDITYDATECRLEXTENSION

SB_INLINE int64_t TElInvalidityDateCRLExtension::get_InvalidityDate()
{
	int64_t OutResult;
	SBCheckError(TElInvalidityDateCRLExtension_get_InvalidityDate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElInvalidityDateCRLExtension::set_InvalidityDate(int64_t Value)
{
	SBCheckError(TElInvalidityDateCRLExtension_set_InvalidityDate(_Handle, Value));
}

TElInvalidityDateCRLExtension::TElInvalidityDateCRLExtension(TElInvalidityDateCRLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
}

TElInvalidityDateCRLExtension::TElInvalidityDateCRLExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElInvalidityDateCRLExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELINVALIDITYDATECRLEXTENSION */

#ifdef SB_USE_CLASS_TELCERTIFICATEISSUERCRLEXTENSION

#ifdef SB_USE_CLASS_TELGENERALNAMES
TElGeneralNames* TElCertificateIssuerCRLExtension::get_Issuer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateIssuerCRLExtension_get_Issuer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Issuer)
		this->_Inst_Issuer = new TElGeneralNames(hOutResult, ohFalse);
	else
		this->_Inst_Issuer->updateHandle(hOutResult);
	return this->_Inst_Issuer;
}
#endif /* SB_USE_CLASS_TELGENERALNAMES */

void TElCertificateIssuerCRLExtension::initInstances()
{
#ifdef SB_USE_CLASS_TELGENERALNAMES
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAMES */
}

TElCertificateIssuerCRLExtension::TElCertificateIssuerCRLExtension(TElCertificateIssuerCRLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
	initInstances();
}

TElCertificateIssuerCRLExtension::TElCertificateIssuerCRLExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCertificateIssuerCRLExtension_Create(&_Handle));
}

TElCertificateIssuerCRLExtension::~TElCertificateIssuerCRLExtension()
{
#ifdef SB_USE_CLASS_TELGENERALNAMES
	delete this->_Inst_Issuer;
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAMES */
}
#endif /* SB_USE_CLASS_TELCERTIFICATEISSUERCRLEXTENSION */

#ifdef SB_USE_CLASS_TELISSUINGDISTRIBUTIONPOINTCRLEXTENSION

#ifdef SB_USE_CLASS_TELGENERALNAMES
TElGeneralNames* TElIssuingDistributionPointCRLExtension::get_DistributionPoint()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElIssuingDistributionPointCRLExtension_get_DistributionPoint(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DistributionPoint)
		this->_Inst_DistributionPoint = new TElGeneralNames(hOutResult, ohFalse);
	else
		this->_Inst_DistributionPoint->updateHandle(hOutResult);
	return this->_Inst_DistributionPoint;
}
#endif /* SB_USE_CLASS_TELGENERALNAMES */

TSBCRLReasonFlags TElIssuingDistributionPointCRLExtension::get_OnlySomeReasons()
{
	TSBCRLReasonFlagsRaw OutResultRaw = 0;
	SBCheckError(TElIssuingDistributionPointCRLExtension_get_OnlySomeReasons(_Handle, &OutResultRaw));
	return (TSBCRLReasonFlags)OutResultRaw;
}

SB_INLINE void TElIssuingDistributionPointCRLExtension::set_OnlySomeReasons(TSBCRLReasonFlags Value)
{
	SBCheckError(TElIssuingDistributionPointCRLExtension_set_OnlySomeReasons(_Handle, (TSBCRLReasonFlagsRaw)Value));
}

bool TElIssuingDistributionPointCRLExtension::get_OnlyContainsUserCerts()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIssuingDistributionPointCRLExtension_get_OnlyContainsUserCerts(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElIssuingDistributionPointCRLExtension::set_OnlyContainsUserCerts(bool Value)
{
	SBCheckError(TElIssuingDistributionPointCRLExtension_set_OnlyContainsUserCerts(_Handle, (int8_t)Value));
}

bool TElIssuingDistributionPointCRLExtension::get_OnlyContainsCACerts()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIssuingDistributionPointCRLExtension_get_OnlyContainsCACerts(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElIssuingDistributionPointCRLExtension::set_OnlyContainsCACerts(bool Value)
{
	SBCheckError(TElIssuingDistributionPointCRLExtension_set_OnlyContainsCACerts(_Handle, (int8_t)Value));
}

bool TElIssuingDistributionPointCRLExtension::get_OnlyContainsAttributeCerts()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIssuingDistributionPointCRLExtension_get_OnlyContainsAttributeCerts(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElIssuingDistributionPointCRLExtension::set_OnlyContainsAttributeCerts(bool Value)
{
	SBCheckError(TElIssuingDistributionPointCRLExtension_set_OnlyContainsAttributeCerts(_Handle, (int8_t)Value));
}

bool TElIssuingDistributionPointCRLExtension::get_IndirectCRL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIssuingDistributionPointCRLExtension_get_IndirectCRL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElIssuingDistributionPointCRLExtension::set_IndirectCRL(bool Value)
{
	SBCheckError(TElIssuingDistributionPointCRLExtension_set_IndirectCRL(_Handle, (int8_t)Value));
}

bool TElIssuingDistributionPointCRLExtension::get_ReasonFlagsIncluded()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIssuingDistributionPointCRLExtension_get_ReasonFlagsIncluded(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElIssuingDistributionPointCRLExtension::set_ReasonFlagsIncluded(bool Value)
{
	SBCheckError(TElIssuingDistributionPointCRLExtension_set_ReasonFlagsIncluded(_Handle, (int8_t)Value));
}

void TElIssuingDistributionPointCRLExtension::initInstances()
{
#ifdef SB_USE_CLASS_TELGENERALNAMES
	this->_Inst_DistributionPoint = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAMES */
}

TElIssuingDistributionPointCRLExtension::TElIssuingDistributionPointCRLExtension(TElIssuingDistributionPointCRLExtensionHandle handle, TElOwnHandle ownHandle) : TElCustomExtension(handle, ownHandle)
{
	initInstances();
}

TElIssuingDistributionPointCRLExtension::TElIssuingDistributionPointCRLExtension() : TElCustomExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElIssuingDistributionPointCRLExtension_Create(&_Handle));
}

TElIssuingDistributionPointCRLExtension::~TElIssuingDistributionPointCRLExtension()
{
#ifdef SB_USE_CLASS_TELGENERALNAMES
	delete this->_Inst_DistributionPoint;
	this->_Inst_DistributionPoint = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAMES */
}
#endif /* SB_USE_CLASS_TELISSUINGDISTRIBUTIONPOINTCRLEXTENSION */

#ifdef SB_USE_CLASS_TELCRLEXTENSIONS

#ifdef SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIERCRLEXTENSION
TElAuthorityKeyIdentifierCRLExtension* TElCRLExtensions::get_AuthorityKeyIdentifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCRLExtensions_get_AuthorityKeyIdentifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AuthorityKeyIdentifier)
		this->_Inst_AuthorityKeyIdentifier = new TElAuthorityKeyIdentifierCRLExtension(hOutResult, ohFalse);
	else
		this->_Inst_AuthorityKeyIdentifier->updateHandle(hOutResult);
	return this->_Inst_AuthorityKeyIdentifier;
}
#endif /* SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIERCRLEXTENSION */

#ifdef SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION
TElAlternativeNameExtension* TElCRLExtensions::get_IssuerAlternativeName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCRLExtensions_get_IssuerAlternativeName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IssuerAlternativeName)
		this->_Inst_IssuerAlternativeName = new TElAlternativeNameExtension(hOutResult, ohFalse);
	else
		this->_Inst_IssuerAlternativeName->updateHandle(hOutResult);
	return this->_Inst_IssuerAlternativeName;
}
#endif /* SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION */

#ifdef SB_USE_CLASS_TELCRLNUMBERCRLEXTENSION
TElCRLNumberCRLExtension* TElCRLExtensions::get_CRLNumber()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCRLExtensions_get_CRLNumber(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLNumber)
		this->_Inst_CRLNumber = new TElCRLNumberCRLExtension(hOutResult, ohFalse);
	else
		this->_Inst_CRLNumber->updateHandle(hOutResult);
	return this->_Inst_CRLNumber;
}
#endif /* SB_USE_CLASS_TELCRLNUMBERCRLEXTENSION */

#ifdef SB_USE_CLASS_TELDELTACRLINDICATORCRLEXTENSION
TElDeltaCRLIndicatorCRLExtension* TElCRLExtensions::get_DeltaCRLIndicator()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCRLExtensions_get_DeltaCRLIndicator(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DeltaCRLIndicator)
		this->_Inst_DeltaCRLIndicator = new TElDeltaCRLIndicatorCRLExtension(hOutResult, ohFalse);
	else
		this->_Inst_DeltaCRLIndicator->updateHandle(hOutResult);
	return this->_Inst_DeltaCRLIndicator;
}
#endif /* SB_USE_CLASS_TELDELTACRLINDICATORCRLEXTENSION */

#ifdef SB_USE_CLASS_TELISSUINGDISTRIBUTIONPOINTCRLEXTENSION
TElIssuingDistributionPointCRLExtension* TElCRLExtensions::get_IssuingDistributionPoint()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCRLExtensions_get_IssuingDistributionPoint(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IssuingDistributionPoint)
		this->_Inst_IssuingDistributionPoint = new TElIssuingDistributionPointCRLExtension(hOutResult, ohFalse);
	else
		this->_Inst_IssuingDistributionPoint->updateHandle(hOutResult);
	return this->_Inst_IssuingDistributionPoint;
}
#endif /* SB_USE_CLASS_TELISSUINGDISTRIBUTIONPOINTCRLEXTENSION */

#ifdef SB_USE_CLASS_TELCUSTOMEXTENSION
TElCustomExtension* TElCRLExtensions::get_OtherExtensions(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCRLExtensions_get_OtherExtensions(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OtherExtensions)
		this->_Inst_OtherExtensions = new TElCustomExtension(hOutResult, ohFalse);
	else
		this->_Inst_OtherExtensions->updateHandle(hOutResult);
	return this->_Inst_OtherExtensions;
}
#endif /* SB_USE_CLASS_TELCUSTOMEXTENSION */

SB_INLINE int32_t TElCRLExtensions::get_OtherCount()
{
	int32_t OutResult;
	SBCheckError(TElCRLExtensions_get_OtherCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCRLExtensions::set_OtherCount(int32_t Value)
{
	SBCheckError(TElCRLExtensions_set_OtherCount(_Handle, Value));
}

TSBCRLExtensions TElCRLExtensions::get_Included()
{
	TSBCRLExtensionsRaw OutResultRaw = 0;
	SBCheckError(TElCRLExtensions_get_Included(_Handle, &OutResultRaw));
	return (TSBCRLExtensions)OutResultRaw;
}

SB_INLINE void TElCRLExtensions::set_Included(TSBCRLExtensions Value)
{
	SBCheckError(TElCRLExtensions_set_Included(_Handle, (TSBCRLExtensionsRaw)Value));
}

bool TElCRLExtensions::get_SaveDefaultASN1Tags()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCRLExtensions_get_SaveDefaultASN1Tags(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCRLExtensions::set_SaveDefaultASN1Tags(bool Value)
{
	SBCheckError(TElCRLExtensions_set_SaveDefaultASN1Tags(_Handle, (int8_t)Value));
}

void TElCRLExtensions::initInstances()
{
#ifdef SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIERCRLEXTENSION
	this->_Inst_AuthorityKeyIdentifier = NULL;
#endif /* SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIERCRLEXTENSION */
#ifdef SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION
	this->_Inst_IssuerAlternativeName = NULL;
#endif /* SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION */
#ifdef SB_USE_CLASS_TELCRLNUMBERCRLEXTENSION
	this->_Inst_CRLNumber = NULL;
#endif /* SB_USE_CLASS_TELCRLNUMBERCRLEXTENSION */
#ifdef SB_USE_CLASS_TELDELTACRLINDICATORCRLEXTENSION
	this->_Inst_DeltaCRLIndicator = NULL;
#endif /* SB_USE_CLASS_TELDELTACRLINDICATORCRLEXTENSION */
#ifdef SB_USE_CLASS_TELISSUINGDISTRIBUTIONPOINTCRLEXTENSION
	this->_Inst_IssuingDistributionPoint = NULL;
#endif /* SB_USE_CLASS_TELISSUINGDISTRIBUTIONPOINTCRLEXTENSION */
#ifdef SB_USE_CLASS_TELCUSTOMEXTENSION
	this->_Inst_OtherExtensions = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMEXTENSION */
}

TElCRLExtensions::TElCRLExtensions(TElCRLExtensionsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCRLExtensions::TElCRLExtensions() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCRLExtensions_Create(&_Handle));
}

TElCRLExtensions::~TElCRLExtensions()
{
#ifdef SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIERCRLEXTENSION
	delete this->_Inst_AuthorityKeyIdentifier;
	this->_Inst_AuthorityKeyIdentifier = NULL;
#endif /* SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIERCRLEXTENSION */
#ifdef SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION
	delete this->_Inst_IssuerAlternativeName;
	this->_Inst_IssuerAlternativeName = NULL;
#endif /* SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION */
#ifdef SB_USE_CLASS_TELCRLNUMBERCRLEXTENSION
	delete this->_Inst_CRLNumber;
	this->_Inst_CRLNumber = NULL;
#endif /* SB_USE_CLASS_TELCRLNUMBERCRLEXTENSION */
#ifdef SB_USE_CLASS_TELDELTACRLINDICATORCRLEXTENSION
	delete this->_Inst_DeltaCRLIndicator;
	this->_Inst_DeltaCRLIndicator = NULL;
#endif /* SB_USE_CLASS_TELDELTACRLINDICATORCRLEXTENSION */
#ifdef SB_USE_CLASS_TELISSUINGDISTRIBUTIONPOINTCRLEXTENSION
	delete this->_Inst_IssuingDistributionPoint;
	this->_Inst_IssuingDistributionPoint = NULL;
#endif /* SB_USE_CLASS_TELISSUINGDISTRIBUTIONPOINTCRLEXTENSION */
#ifdef SB_USE_CLASS_TELCUSTOMEXTENSION
	delete this->_Inst_OtherExtensions;
	this->_Inst_OtherExtensions = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMEXTENSION */
}
#endif /* SB_USE_CLASS_TELCRLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCRLENTRYEXTENSIONS

#ifdef SB_USE_CLASS_TELREASONCODECRLEXTENSION
TElReasonCodeCRLExtension* TElCRLEntryExtensions::get_ReasonCode()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCRLEntryExtensions_get_ReasonCode(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ReasonCode)
		this->_Inst_ReasonCode = new TElReasonCodeCRLExtension(hOutResult, ohFalse);
	else
		this->_Inst_ReasonCode->updateHandle(hOutResult);
	return this->_Inst_ReasonCode;
}
#endif /* SB_USE_CLASS_TELREASONCODECRLEXTENSION */

#ifdef SB_USE_CLASS_TELHOLDINSTRUCTIONCODECRLEXTENSION
TElHoldInstructionCodeCRLExtension* TElCRLEntryExtensions::get_HoldInstructionCode()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCRLEntryExtensions_get_HoldInstructionCode(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HoldInstructionCode)
		this->_Inst_HoldInstructionCode = new TElHoldInstructionCodeCRLExtension(hOutResult, ohFalse);
	else
		this->_Inst_HoldInstructionCode->updateHandle(hOutResult);
	return this->_Inst_HoldInstructionCode;
}
#endif /* SB_USE_CLASS_TELHOLDINSTRUCTIONCODECRLEXTENSION */

#ifdef SB_USE_CLASS_TELINVALIDITYDATECRLEXTENSION
TElInvalidityDateCRLExtension* TElCRLEntryExtensions::get_InvalidityDate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCRLEntryExtensions_get_InvalidityDate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_InvalidityDate)
		this->_Inst_InvalidityDate = new TElInvalidityDateCRLExtension(hOutResult, ohFalse);
	else
		this->_Inst_InvalidityDate->updateHandle(hOutResult);
	return this->_Inst_InvalidityDate;
}
#endif /* SB_USE_CLASS_TELINVALIDITYDATECRLEXTENSION */

#ifdef SB_USE_CLASS_TELCERTIFICATEISSUERCRLEXTENSION
TElCertificateIssuerCRLExtension* TElCRLEntryExtensions::get_CertificateIssuer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCRLEntryExtensions_get_CertificateIssuer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertificateIssuer)
		this->_Inst_CertificateIssuer = new TElCertificateIssuerCRLExtension(hOutResult, ohFalse);
	else
		this->_Inst_CertificateIssuer->updateHandle(hOutResult);
	return this->_Inst_CertificateIssuer;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEISSUERCRLEXTENSION */

#ifdef SB_USE_CLASS_TELCUSTOMEXTENSION
TElCustomExtension* TElCRLEntryExtensions::get_OtherExtensions(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCRLEntryExtensions_get_OtherExtensions(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OtherExtensions)
		this->_Inst_OtherExtensions = new TElCustomExtension(hOutResult, ohFalse);
	else
		this->_Inst_OtherExtensions->updateHandle(hOutResult);
	return this->_Inst_OtherExtensions;
}
#endif /* SB_USE_CLASS_TELCUSTOMEXTENSION */

SB_INLINE int32_t TElCRLEntryExtensions::get_OtherCount()
{
	int32_t OutResult;
	SBCheckError(TElCRLEntryExtensions_get_OtherCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCRLEntryExtensions::set_OtherCount(int32_t Value)
{
	SBCheckError(TElCRLEntryExtensions_set_OtherCount(_Handle, Value));
}

TSBCRLEntryExtensions TElCRLEntryExtensions::get_Included()
{
	TSBCRLEntryExtensionsRaw OutResultRaw = 0;
	SBCheckError(TElCRLEntryExtensions_get_Included(_Handle, &OutResultRaw));
	return (TSBCRLEntryExtensions)OutResultRaw;
}

SB_INLINE void TElCRLEntryExtensions::set_Included(TSBCRLEntryExtensions Value)
{
	SBCheckError(TElCRLEntryExtensions_set_Included(_Handle, (TSBCRLEntryExtensionsRaw)Value));
}

bool TElCRLEntryExtensions::get_SaveDefaultASN1Tags()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCRLEntryExtensions_get_SaveDefaultASN1Tags(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCRLEntryExtensions::set_SaveDefaultASN1Tags(bool Value)
{
	SBCheckError(TElCRLEntryExtensions_set_SaveDefaultASN1Tags(_Handle, (int8_t)Value));
}

void TElCRLEntryExtensions::initInstances()
{
#ifdef SB_USE_CLASS_TELREASONCODECRLEXTENSION
	this->_Inst_ReasonCode = NULL;
#endif /* SB_USE_CLASS_TELREASONCODECRLEXTENSION */
#ifdef SB_USE_CLASS_TELHOLDINSTRUCTIONCODECRLEXTENSION
	this->_Inst_HoldInstructionCode = NULL;
#endif /* SB_USE_CLASS_TELHOLDINSTRUCTIONCODECRLEXTENSION */
#ifdef SB_USE_CLASS_TELINVALIDITYDATECRLEXTENSION
	this->_Inst_InvalidityDate = NULL;
#endif /* SB_USE_CLASS_TELINVALIDITYDATECRLEXTENSION */
#ifdef SB_USE_CLASS_TELCERTIFICATEISSUERCRLEXTENSION
	this->_Inst_CertificateIssuer = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEISSUERCRLEXTENSION */
#ifdef SB_USE_CLASS_TELCUSTOMEXTENSION
	this->_Inst_OtherExtensions = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMEXTENSION */
}

TElCRLEntryExtensions::TElCRLEntryExtensions(TElCRLEntryExtensionsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElCRLEntryExtensions::TElCRLEntryExtensions() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCRLEntryExtensions_Create(&_Handle));
}

TElCRLEntryExtensions::~TElCRLEntryExtensions()
{
#ifdef SB_USE_CLASS_TELREASONCODECRLEXTENSION
	delete this->_Inst_ReasonCode;
	this->_Inst_ReasonCode = NULL;
#endif /* SB_USE_CLASS_TELREASONCODECRLEXTENSION */
#ifdef SB_USE_CLASS_TELHOLDINSTRUCTIONCODECRLEXTENSION
	delete this->_Inst_HoldInstructionCode;
	this->_Inst_HoldInstructionCode = NULL;
#endif /* SB_USE_CLASS_TELHOLDINSTRUCTIONCODECRLEXTENSION */
#ifdef SB_USE_CLASS_TELINVALIDITYDATECRLEXTENSION
	delete this->_Inst_InvalidityDate;
	this->_Inst_InvalidityDate = NULL;
#endif /* SB_USE_CLASS_TELINVALIDITYDATECRLEXTENSION */
#ifdef SB_USE_CLASS_TELCERTIFICATEISSUERCRLEXTENSION
	delete this->_Inst_CertificateIssuer;
	this->_Inst_CertificateIssuer = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEISSUERCRLEXTENSION */
#ifdef SB_USE_CLASS_TELCUSTOMEXTENSION
	delete this->_Inst_OtherExtensions;
	this->_Inst_OtherExtensions = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMEXTENSION */
}
#endif /* SB_USE_CLASS_TELCRLENTRYEXTENSIONS */

#ifdef SB_USE_CLASS_TELREVOCATIONITEM

void TElRevocationItem::get_SerialNumber(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElRevocationItem_get_SerialNumber(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1315761355, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElRevocationItem::set_SerialNumber(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElRevocationItem_set_SerialNumber(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int64_t TElRevocationItem::get_RevocationDate()
{
	int64_t OutResult;
	SBCheckError(TElRevocationItem_get_RevocationDate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElRevocationItem::set_RevocationDate(int64_t Value)
{
	SBCheckError(TElRevocationItem_set_RevocationDate(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELCRLENTRYEXTENSIONS
TElCRLEntryExtensions* TElRevocationItem::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElRevocationItem_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElCRLEntryExtensions(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TELCRLENTRYEXTENSIONS */

void TElRevocationItem::initInstances()
{
#ifdef SB_USE_CLASS_TELCRLENTRYEXTENSIONS
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCRLENTRYEXTENSIONS */
}

TElRevocationItem::TElRevocationItem(TElRevocationItemHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElRevocationItem::TElRevocationItem() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElRevocationItem_Create(&_Handle));
}

TElRevocationItem::~TElRevocationItem()
{
#ifdef SB_USE_CLASS_TELCRLENTRYEXTENSIONS
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCRLENTRYEXTENSIONS */
}
#endif /* SB_USE_CLASS_TELREVOCATIONITEM */

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST

TSBCRLFileFormat TElCertificateRevocationList::DetectCRLFileFormat(const std::string &FileName)
{
	TSBCRLFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElCertificateRevocationList_DetectCRLFileFormat(FileName.data(), (int32_t)FileName.length(), &OutResultRaw));
	return (TSBCRLFileFormat)OutResultRaw;
}

TSBCRLFileFormat TElCertificateRevocationList::DetectCRLFileFormat_Inst(const std::string &FileName)
{
	TSBCRLFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElCertificateRevocationList_DetectCRLFileFormat_1(_Handle, FileName.data(), (int32_t)FileName.length(), &OutResultRaw));
	return (TSBCRLFileFormat)OutResultRaw;
}

#ifdef SB_USE_CLASS_TSTREAM
TSBCRLFileFormat TElCertificateRevocationList::DetectCRLFileFormat(TStream &Stream)
{
	TSBCRLFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElCertificateRevocationList_DetectCRLFileFormat_2(Stream.getHandle(), &OutResultRaw));
	return (TSBCRLFileFormat)OutResultRaw;
}

TSBCRLFileFormat TElCertificateRevocationList::DetectCRLFileFormat(TStream *Stream)
{
	TSBCRLFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElCertificateRevocationList_DetectCRLFileFormat_2((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBCRLFileFormat)OutResultRaw;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
TSBCRLFileFormat TElCertificateRevocationList::DetectCRLFileFormat_Inst(TStream &Stream)
{
	TSBCRLFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElCertificateRevocationList_DetectCRLFileFormat_3(_Handle, Stream.getHandle(), &OutResultRaw));
	return (TSBCRLFileFormat)OutResultRaw;
}

TSBCRLFileFormat TElCertificateRevocationList::DetectCRLFileFormat_Inst(TStream *Stream)
{
	TSBCRLFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElCertificateRevocationList_DetectCRLFileFormat_3(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBCRLFileFormat)OutResultRaw;
}
#endif /* SB_USE_CLASS_TSTREAM */

TSBCRLFileFormat TElCertificateRevocationList::DetectCRLFileFormat(void * Buffer, int32_t Size)
{
	TSBCRLFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElCertificateRevocationList_DetectCRLFileFormat_4(Buffer, Size, &OutResultRaw));
	return (TSBCRLFileFormat)OutResultRaw;
}

TSBCRLFileFormat TElCertificateRevocationList::DetectCRLFileFormat_Inst(void * Buffer, int32_t Size)
{
	TSBCRLFileFormatRaw OutResultRaw = 0;
	SBCheckError(TElCertificateRevocationList_DetectCRLFileFormat_5(_Handle, Buffer, Size, &OutResultRaw));
	return (TSBCRLFileFormat)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE int32_t TElCertificateRevocationList::Add(TElX509Certificate &Certificate)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationList_Add(_Handle, Certificate.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCertificateRevocationList::Add(TElX509Certificate *Certificate)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationList_Add(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE int32_t TElCertificateRevocationList::Add(const std::vector<uint8_t> &SerialNumber)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationList_Add_1(_Handle, SB_STD_VECTOR_FRONT_ADR(SerialNumber), (int32_t)SerialNumber.size(), &OutResult));
	return OutResult;
}

SB_INLINE void TElCertificateRevocationList::Assign(TPersistent &Source)
{
	SBCheckError(TElCertificateRevocationList_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElCertificateRevocationList::Assign(TPersistent *Source)
{
	SBCheckError(TElCertificateRevocationList_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
bool TElCertificateRevocationList::Remove(TElX509Certificate &Certificate)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertificateRevocationList_Remove(_Handle, Certificate.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCertificateRevocationList::Remove(TElX509Certificate *Certificate)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertificateRevocationList_Remove(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

bool TElCertificateRevocationList::Remove(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertificateRevocationList_Remove_1(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
bool TElCertificateRevocationList::IsPresent(TElX509Certificate &Certificate)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertificateRevocationList_IsPresent(_Handle, Certificate.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCertificateRevocationList::IsPresent(TElX509Certificate *Certificate)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertificateRevocationList_IsPresent(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE int32_t TElCertificateRevocationList::IndexOf(TElX509Certificate &Certificate)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationList_IndexOf(_Handle, Certificate.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCertificateRevocationList::IndexOf(TElX509Certificate *Certificate)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationList_IndexOf(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE void TElCertificateRevocationList::Clear()
{
	SBCheckError(TElCertificateRevocationList_Clear(_Handle));
}

SB_INLINE int32_t TElCertificateRevocationList::LoadFromBuffer(void * Buffer, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationList_LoadFromBuffer(_Handle, Buffer, Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCertificateRevocationList::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationList_SaveToBuffer(_Handle, Buffer, &Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCertificateRevocationList::LoadFromBufferPEM(void * Buffer, int32_t Size, const std::string &Passphrase)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationList_LoadFromBufferPEM(_Handle, Buffer, Size, Passphrase.data(), (int32_t)Passphrase.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCertificateRevocationList::SaveToBufferPEM(void * Buffer, int32_t &Size, const std::string &Passphrase)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationList_SaveToBufferPEM(_Handle, Buffer, &Size, Passphrase.data(), (int32_t)Passphrase.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElCertificateRevocationList::LoadFromStream(TStream &Stream, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationList_LoadFromStream(_Handle, Stream.getHandle(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCertificateRevocationList::LoadFromStream(TStream *Stream, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationList_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElCertificateRevocationList::LoadFromStreamPEM(TStream &Stream, const std::string &Passphrase, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationList_LoadFromStreamPEM(_Handle, Stream.getHandle(), Passphrase.data(), (int32_t)Passphrase.length(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCertificateRevocationList::LoadFromStreamPEM(TStream *Stream, const std::string &Passphrase, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationList_LoadFromStreamPEM(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Passphrase.data(), (int32_t)Passphrase.length(), Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

bool TElCertificateRevocationList::SameCRL(TElCertificateRevocationList &CRL, bool CheckUpdateTime)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertificateRevocationList_SameCRL(_Handle, CRL.getHandle(), (int8_t)CheckUpdateTime, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElCertificateRevocationList::SameCRL(TElCertificateRevocationList *CRL, bool CheckUpdateTime)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCertificateRevocationList_SameCRL(_Handle, (CRL != NULL) ? CRL->getHandle() : SB_NULL_HANDLE, (int8_t)CheckUpdateTime, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE int32_t TElCertificateRevocationList::Validate(TElX509Certificate &Certificate)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationList_Validate(_Handle, Certificate.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElCertificateRevocationList::Validate(TElX509Certificate *Certificate)
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationList_Validate(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

void TElCertificateRevocationList::GetCRLHash(int32_t Alg, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCertificateRevocationList_GetCRLHash(_Handle, Alg, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-45266315, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElCertificateRevocationList::get_Location(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCertificateRevocationList_get_Location(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-963183332, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCertificateRevocationList::set_Location(const std::string &Value)
{
	SBCheckError(TElCertificateRevocationList_set_Location(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElCertificateRevocationList::get_Issuer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateRevocationList_get_Issuer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Issuer)
		this->_Inst_Issuer = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_Issuer->updateHandle(hOutResult);
	return this->_Inst_Issuer;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE int64_t TElCertificateRevocationList::get_ThisUpdate()
{
	int64_t OutResult;
	SBCheckError(TElCertificateRevocationList_get_ThisUpdate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCertificateRevocationList::set_ThisUpdate(int64_t Value)
{
	SBCheckError(TElCertificateRevocationList_set_ThisUpdate(_Handle, Value));
}

SB_INLINE int64_t TElCertificateRevocationList::get_NextUpdate()
{
	int64_t OutResult;
	SBCheckError(TElCertificateRevocationList_get_NextUpdate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCertificateRevocationList::set_NextUpdate(int64_t Value)
{
	SBCheckError(TElCertificateRevocationList_set_NextUpdate(_Handle, Value));
}

SB_INLINE int32_t TElCertificateRevocationList::get_SignatureAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationList_get_SignatureAlgorithm(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
TElAlgorithmIdentifier* TElCertificateRevocationList::get_SignatureAlgorithmIdentifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateRevocationList_get_SignatureAlgorithmIdentifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureAlgorithmIdentifier)
		this->_Inst_SignatureAlgorithmIdentifier = new TElAlgorithmIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_SignatureAlgorithmIdentifier->updateHandle(hOutResult);
	return this->_Inst_SignatureAlgorithmIdentifier;
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

void TElCertificateRevocationList::get_Signature(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCertificateRevocationList_get_Signature(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1688576463, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElCertificateRevocationList::get_TBS(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCertificateRevocationList_get_TBS(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1262721457, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELREVOCATIONITEM
TElRevocationItem* TElCertificateRevocationList::get_Items(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateRevocationList_get_Items(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElRevocationItem(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}
#endif /* SB_USE_CLASS_TELREVOCATIONITEM */

SB_INLINE int32_t TElCertificateRevocationList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationList_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCRLEXTENSIONS
TElCRLExtensions* TElCertificateRevocationList::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCertificateRevocationList_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElCRLExtensions(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TELCRLEXTENSIONS */

SB_INLINE int32_t TElCertificateRevocationList::get_CRLSize()
{
	int32_t OutResult;
	SBCheckError(TElCertificateRevocationList_get_CRLSize(_Handle, &OutResult));
	return OutResult;
}

void TElCertificateRevocationList::initInstances()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	this->_Inst_SignatureAlgorithmIdentifier = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELREVOCATIONITEM
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELREVOCATIONITEM */
#ifdef SB_USE_CLASS_TELCRLEXTENSIONS
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCRLEXTENSIONS */
}

TElCertificateRevocationList::TElCertificateRevocationList(TElCertificateRevocationListHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElCertificateRevocationList::TElCertificateRevocationList(TComponent &Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCertificateRevocationList_Create(Owner.getHandle(), &_Handle));
}

TElCertificateRevocationList::TElCertificateRevocationList(TComponent *Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCertificateRevocationList_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCertificateRevocationList::~TElCertificateRevocationList()
{
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_Issuer;
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	delete this->_Inst_SignatureAlgorithmIdentifier;
	this->_Inst_SignatureAlgorithmIdentifier = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELREVOCATIONITEM
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
#endif /* SB_USE_CLASS_TELREVOCATIONITEM */
#ifdef SB_USE_CLASS_TELCRLEXTENSIONS
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELCRLEXTENSIONS */
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

};	/* namespace SecureBlackbox */

