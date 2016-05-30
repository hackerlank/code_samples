#include "sbpdfsecurity.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPDFPASSWORDSECURITYHANDLER

SB_INLINE void TElPDFPasswordSecurityHandler::Reset()
{
	SBCheckError(TElPDFPasswordSecurityHandler_Reset(_Handle));
}

bool TElPDFPasswordSecurityHandler::IsUserPasswordValid()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFPasswordSecurityHandler_IsUserPasswordValid(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPDFPasswordSecurityHandler::IsOwnerPasswordValid()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFPasswordSecurityHandler_IsOwnerPasswordValid(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPDFPasswordSecurityHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFPasswordSecurityHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1218976724, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPDFPasswordSecurityHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFPasswordSecurityHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1218976724, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPDFPasswordSecurityHandler::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFPasswordSecurityHandler_GetDescription((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(705504363, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPDFPasswordSecurityHandler::GetDescription_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFPasswordSecurityHandler_GetDescription_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(705504363, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TElPDFPasswordSecurityHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPDFPasswordSecurityHandler_ClassType(&OutResult));
	return OutResult;
}

void TElPDFPasswordSecurityHandler::get_UserPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFPasswordSecurityHandler_get_UserPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1791202380, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFPasswordSecurityHandler::set_UserPassword(const std::string &Value)
{
	SBCheckError(TElPDFPasswordSecurityHandler_set_UserPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFPasswordSecurityHandler::get_OwnerPassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFPasswordSecurityHandler_get_OwnerPassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1876877172, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFPasswordSecurityHandler::set_OwnerPassword(const std::string &Value)
{
	SBCheckError(TElPDFPasswordSecurityHandler_set_OwnerPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELPDFPERMISSIONS
TElPDFPermissions* TElPDFPasswordSecurityHandler::get_Permissions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFPasswordSecurityHandler_get_Permissions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Permissions)
		this->_Inst_Permissions = new TElPDFPermissions(hOutResult, ohFalse);
	else
		this->_Inst_Permissions->updateHandle(hOutResult);
	return this->_Inst_Permissions;
}
#endif /* SB_USE_CLASS_TELPDFPERMISSIONS */

SB_INLINE int32_t TElPDFPasswordSecurityHandler::get_RevisionNumber()
{
	int32_t OutResult;
	SBCheckError(TElPDFPasswordSecurityHandler_get_RevisionNumber(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFPasswordSecurityHandler::set_RevisionNumber(int32_t Value)
{
	SBCheckError(TElPDFPasswordSecurityHandler_set_RevisionNumber(_Handle, Value));
}

void TElPDFPasswordSecurityHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELPDFPERMISSIONS
	this->_Inst_Permissions = NULL;
#endif /* SB_USE_CLASS_TELPDFPERMISSIONS */
}

TElPDFPasswordSecurityHandler::TElPDFPasswordSecurityHandler(TElPDFPasswordSecurityHandlerHandle handle, TElOwnHandle ownHandle) : TElPDFSecurityHandler(handle, ownHandle)
{
	initInstances();
}

TElPDFPasswordSecurityHandler::TElPDFPasswordSecurityHandler(TComponent &Owner) : TElPDFSecurityHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFPasswordSecurityHandler_Create(Owner.getHandle(), &_Handle));
}

TElPDFPasswordSecurityHandler::TElPDFPasswordSecurityHandler(TComponent *Owner) : TElPDFSecurityHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFPasswordSecurityHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElPDFPasswordSecurityHandler::~TElPDFPasswordSecurityHandler()
{
#ifdef SB_USE_CLASS_TELPDFPERMISSIONS
	delete this->_Inst_Permissions;
	this->_Inst_Permissions = NULL;
#endif /* SB_USE_CLASS_TELPDFPERMISSIONS */
}
#endif /* SB_USE_CLASS_TELPDFPASSWORDSECURITYHANDLER */

#ifdef SB_USE_CLASS_TELPDFPUBLICKEYSECURITYHANDLER

SB_INLINE void TElPDFPublicKeySecurityHandler::Reset()
{
	SBCheckError(TElPDFPublicKeySecurityHandler_Reset(_Handle));
}

SB_INLINE int32_t TElPDFPublicKeySecurityHandler::AddRecipientGroup()
{
	int32_t OutResult;
	SBCheckError(TElPDFPublicKeySecurityHandler_AddRecipientGroup(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFPublicKeySecurityHandler::RemoveRecipientGroup(int32_t Index)
{
	SBCheckError(TElPDFPublicKeySecurityHandler_RemoveRecipientGroup(_Handle, Index));
}

SB_INLINE void TElPDFPublicKeySecurityHandler::ClearRecipientGroups()
{
	SBCheckError(TElPDFPublicKeySecurityHandler_ClearRecipientGroups(_Handle));
}

void TElPDFPublicKeySecurityHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFPublicKeySecurityHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(986111446, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPDFPublicKeySecurityHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFPublicKeySecurityHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(986111446, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPDFPublicKeySecurityHandler::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFPublicKeySecurityHandler_GetDescription((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1659409968, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPDFPublicKeySecurityHandler::GetDescription_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFPublicKeySecurityHandler_GetDescription_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1659409968, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE TElX509CertificateHandle TElPDFPublicKeySecurityHandler::GetSignerCertificate()
{
	TElX509CertificateHandle OutResult;
	SBCheckError(TElPDFPublicKeySecurityHandler_GetSignerCertificate(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE TClassHandle TElPDFPublicKeySecurityHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPDFPublicKeySecurityHandler_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPDFPUBLICKEYRECIPIENTGROUP
TElPDFPublicKeyRecipientGroup* TElPDFPublicKeySecurityHandler::get_RecipientGroups(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFPublicKeySecurityHandler_get_RecipientGroups(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RecipientGroups)
		this->_Inst_RecipientGroups = new TElPDFPublicKeyRecipientGroup(hOutResult, ohFalse);
	else
		this->_Inst_RecipientGroups->updateHandle(hOutResult);
	return this->_Inst_RecipientGroups;
}
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYRECIPIENTGROUP */

#ifdef SB_USE_CLASS_TELPKCS7ISSUER
TElPKCS7Issuer* TElPDFPublicKeySecurityHandler::get_CertIDs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFPublicKeySecurityHandler_get_CertIDs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertIDs)
		this->_Inst_CertIDs = new TElPKCS7Issuer(hOutResult, ohFalse);
	else
		this->_Inst_CertIDs->updateHandle(hOutResult);
	return this->_Inst_CertIDs;
}
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
TElClientTSPInfo* TElPDFPublicKeySecurityHandler::get_Timestamps(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFPublicKeySecurityHandler_get_Timestamps(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Timestamps)
		this->_Inst_Timestamps = new TElClientTSPInfo(hOutResult, ohFalse);
	else
		this->_Inst_Timestamps->updateHandle(hOutResult);
	return this->_Inst_Timestamps;
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

SB_INLINE int32_t TElPDFPublicKeySecurityHandler::get_RecipientGroupCount()
{
	int32_t OutResult;
	SBCheckError(TElPDFPublicKeySecurityHandler_get_RecipientGroupCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElPDFPublicKeySecurityHandler::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFPublicKeySecurityHandler_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElPDFPublicKeySecurityHandler::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElPDFPublicKeySecurityHandler_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFPublicKeySecurityHandler::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElPDFPublicKeySecurityHandler_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
TElMemoryCertStorage* TElPDFPublicKeySecurityHandler::get_Certificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFPublicKeySecurityHandler_get_Certificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElMemoryCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

TSBPDFPublicKeySignatureType TElPDFPublicKeySecurityHandler::get_SignatureType()
{
	TSBPDFPublicKeySignatureTypeRaw OutResultRaw = 0;
	SBCheckError(TElPDFPublicKeySecurityHandler_get_SignatureType(_Handle, &OutResultRaw));
	return (TSBPDFPublicKeySignatureType)OutResultRaw;
}

SB_INLINE void TElPDFPublicKeySecurityHandler::set_SignatureType(TSBPDFPublicKeySignatureType Value)
{
	SBCheckError(TElPDFPublicKeySecurityHandler_set_SignatureType(_Handle, (TSBPDFPublicKeySignatureTypeRaw)Value));
}

SB_INLINE int32_t TElPDFPublicKeySecurityHandler::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPDFPublicKeySecurityHandler_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFPublicKeySecurityHandler::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElPDFPublicKeySecurityHandler_set_HashAlgorithm(_Handle, Value));
}

bool TElPDFPublicKeySecurityHandler::get_Detached()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFPublicKeySecurityHandler_get_Detached(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFPublicKeySecurityHandler::set_Detached(bool Value)
{
	SBCheckError(TElPDFPublicKeySecurityHandler_set_Detached(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElPDFPublicKeySecurityHandler::get_CertIDCount()
{
	int32_t OutResult;
	SBCheckError(TElPDFPublicKeySecurityHandler_get_CertIDCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFPublicKeySecurityHandler::get_TimestampCount()
{
	int32_t OutResult;
	SBCheckError(TElPDFPublicKeySecurityHandler_get_TimestampCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO
TElPDFPublicKeyRevocationInfo* TElPDFPublicKeySecurityHandler::get_RevocationInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFPublicKeySecurityHandler_get_RevocationInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RevocationInfo)
		this->_Inst_RevocationInfo = new TElPDFPublicKeyRevocationInfo(hOutResult, ohFalse);
	else
		this->_Inst_RevocationInfo->updateHandle(hOutResult);
	return this->_Inst_RevocationInfo;
}
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO */

SB_INLINE int32_t TElPDFPublicKeySecurityHandler::get_LastValidationResult()
{
	int32_t OutResult;
	SBCheckError(TElPDFPublicKeySecurityHandler_get_LastValidationResult(_Handle, &OutResult));
	return OutResult;
}

void TElPDFPublicKeySecurityHandler::get_SignatureContents(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFPublicKeySecurityHandler_get_SignatureContents(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(999625635, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
TElCustomTSPClient* TElPDFPublicKeySecurityHandler::get_TSPClient()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFPublicKeySecurityHandler_get_TSPClient(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TSPClient)
		this->_Inst_TSPClient = new TElCustomTSPClient(hOutResult, ohFalse);
	else
		this->_Inst_TSPClient->updateHandle(hOutResult);
	return this->_Inst_TSPClient;
}

SB_INLINE void TElPDFPublicKeySecurityHandler::set_TSPClient(TElCustomTSPClient &Value)
{
	SBCheckError(TElPDFPublicKeySecurityHandler_set_TSPClient(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFPublicKeySecurityHandler::set_TSPClient(TElCustomTSPClient *Value)
{
	SBCheckError(TElPDFPublicKeySecurityHandler_set_TSPClient(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

bool TElPDFPublicKeySecurityHandler::get_IgnoreTimestampFailure()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFPublicKeySecurityHandler_get_IgnoreTimestampFailure(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFPublicKeySecurityHandler::set_IgnoreTimestampFailure(bool Value)
{
	SBCheckError(TElPDFPublicKeySecurityHandler_set_IgnoreTimestampFailure(_Handle, (int8_t)Value));
}

void TElPDFPublicKeySecurityHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELPDFPUBLICKEYRECIPIENTGROUP
	this->_Inst_RecipientGroups = NULL;
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYRECIPIENTGROUP */
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
	this->_Inst_CertIDs = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	this->_Inst_Timestamps = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO
	this->_Inst_RevocationInfo = NULL;
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO */
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
	this->_Inst_TSPClient = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */
}

TElPDFPublicKeySecurityHandler::TElPDFPublicKeySecurityHandler(TElPDFPublicKeySecurityHandlerHandle handle, TElOwnHandle ownHandle) : TElPDFSecurityHandler(handle, ownHandle)
{
	initInstances();
}

TElPDFPublicKeySecurityHandler::TElPDFPublicKeySecurityHandler(TComponent &Owner) : TElPDFSecurityHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFPublicKeySecurityHandler_Create(Owner.getHandle(), &_Handle));
}

TElPDFPublicKeySecurityHandler::TElPDFPublicKeySecurityHandler(TComponent *Owner) : TElPDFSecurityHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFPublicKeySecurityHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElPDFPublicKeySecurityHandler::~TElPDFPublicKeySecurityHandler()
{
#ifdef SB_USE_CLASS_TELPDFPUBLICKEYRECIPIENTGROUP
	delete this->_Inst_RecipientGroups;
	this->_Inst_RecipientGroups = NULL;
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYRECIPIENTGROUP */
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
	delete this->_Inst_CertIDs;
	this->_Inst_CertIDs = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	delete this->_Inst_Timestamps;
	this->_Inst_Timestamps = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO
	delete this->_Inst_RevocationInfo;
	this->_Inst_RevocationInfo = NULL;
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO */
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
	delete this->_Inst_TSPClient;
	this->_Inst_TSPClient = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */
}
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYSECURITYHANDLER */

#ifdef SB_USE_CLASS_TELPDFPUBLICKEYRECIPIENTGROUP

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE int32_t TElPDFPublicKeyRecipientGroup::AddRecipient(TElX509Certificate &Cert)
{
	int32_t OutResult;
	SBCheckError(TElPDFPublicKeyRecipientGroup_AddRecipient(_Handle, Cert.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFPublicKeyRecipientGroup::AddRecipient(TElX509Certificate *Cert)
{
	int32_t OutResult;
	SBCheckError(TElPDFPublicKeyRecipientGroup_AddRecipient(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE void TElPDFPublicKeyRecipientGroup::RemoveRecipient(int32_t Index)
{
	SBCheckError(TElPDFPublicKeyRecipientGroup_RemoveRecipient(_Handle, Index));
}

SB_INLINE void TElPDFPublicKeyRecipientGroup::ClearRecipients()
{
	SBCheckError(TElPDFPublicKeyRecipientGroup_ClearRecipients(_Handle));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElPDFPublicKeyRecipientGroup::get_Recipients(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFPublicKeyRecipientGroup_get_Recipients(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Recipients)
		this->_Inst_Recipients = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_Recipients->updateHandle(hOutResult);
	return this->_Inst_Recipients;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELPKCS7ISSUER
TElPKCS7Issuer* TElPDFPublicKeyRecipientGroup::get_RecipientInfos(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFPublicKeyRecipientGroup_get_RecipientInfos(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RecipientInfos)
		this->_Inst_RecipientInfos = new TElPKCS7Issuer(hOutResult, ohFalse);
	else
		this->_Inst_RecipientInfos->updateHandle(hOutResult);
	return this->_Inst_RecipientInfos;
}
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

SB_INLINE int32_t TElPDFPublicKeyRecipientGroup::get_RecipientCount()
{
	int32_t OutResult;
	SBCheckError(TElPDFPublicKeyRecipientGroup_get_RecipientCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFPublicKeyRecipientGroup::get_RecipientInfoCount()
{
	int32_t OutResult;
	SBCheckError(TElPDFPublicKeyRecipientGroup_get_RecipientInfoCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFPublicKeyRecipientGroup::get_KeyEncryptionAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPDFPublicKeyRecipientGroup_get_KeyEncryptionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFPublicKeyRecipientGroup::set_KeyEncryptionAlgorithm(int32_t Value)
{
	SBCheckError(TElPDFPublicKeyRecipientGroup_set_KeyEncryptionAlgorithm(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELPDFPERMISSIONS
TElPDFPermissions* TElPDFPublicKeyRecipientGroup::get_Permissions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFPublicKeyRecipientGroup_get_Permissions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Permissions)
		this->_Inst_Permissions = new TElPDFPermissions(hOutResult, ohFalse);
	else
		this->_Inst_Permissions->updateHandle(hOutResult);
	return this->_Inst_Permissions;
}
#endif /* SB_USE_CLASS_TELPDFPERMISSIONS */

void TElPDFPublicKeyRecipientGroup::initInstances()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_Recipients = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
	this->_Inst_RecipientInfos = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELPDFPERMISSIONS
	this->_Inst_Permissions = NULL;
#endif /* SB_USE_CLASS_TELPDFPERMISSIONS */
}

TElPDFPublicKeyRecipientGroup::TElPDFPublicKeyRecipientGroup(TElPDFPublicKeyRecipientGroupHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPDFPublicKeyRecipientGroup::TElPDFPublicKeyRecipientGroup() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFPublicKeyRecipientGroup_Create(&_Handle));
}

#ifdef SB_USE_CLASSES_TELPDFPUBLICKEYSECURITYHANDLER_AND_TELPKCS7MESSAGE
TElPDFPublicKeyRecipientGroup::TElPDFPublicKeyRecipientGroup(TElPKCS7Message &Msg, TElPDFPublicKeySecurityHandler &Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFPublicKeyRecipientGroup_Create_1(Msg.getHandle(), Owner.getHandle(), &_Handle));
}

TElPDFPublicKeyRecipientGroup::TElPDFPublicKeyRecipientGroup(TElPKCS7Message *Msg, TElPDFPublicKeySecurityHandler *Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFPublicKeyRecipientGroup_Create_1((Msg != NULL) ? Msg->getHandle() : SB_NULL_HANDLE, (Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASSES_TELPDFPUBLICKEYSECURITYHANDLER_AND_TELPKCS7MESSAGE */

TElPDFPublicKeyRecipientGroup::~TElPDFPublicKeyRecipientGroup()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_Recipients;
	this->_Inst_Recipients = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
	delete this->_Inst_RecipientInfos;
	this->_Inst_RecipientInfos = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELPDFPERMISSIONS
	delete this->_Inst_Permissions;
	this->_Inst_Permissions = NULL;
#endif /* SB_USE_CLASS_TELPDFPERMISSIONS */
}
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYRECIPIENTGROUP */

#ifdef SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO

SB_INLINE void TElPDFPublicKeyRevocationInfo::Assign(TElPDFPublicKeyRevocationInfo &Source)
{
	SBCheckError(TElPDFPublicKeyRevocationInfo_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPDFPublicKeyRevocationInfo::Assign(TElPDFPublicKeyRevocationInfo *Source)
{
	SBCheckError(TElPDFPublicKeyRevocationInfo_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPDFPublicKeyRevocationInfo::Assign(TElPDFPublicKeyRevocationInfo &Source, bool Clear)
{
	SBCheckError(TElPDFPublicKeyRevocationInfo_Assign_1(_Handle, Source.getHandle(), (int8_t)Clear));
}

SB_INLINE void TElPDFPublicKeyRevocationInfo::Assign(TElPDFPublicKeyRevocationInfo *Source, bool Clear)
{
	SBCheckError(TElPDFPublicKeyRevocationInfo_Assign_1(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (int8_t)Clear));
}

SB_INLINE int32_t TElPDFPublicKeyRevocationInfo::AddCRL()
{
	int32_t OutResult;
	SBCheckError(TElPDFPublicKeyRevocationInfo_AddCRL(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFPublicKeyRevocationInfo::RemoveCRL(int32_t Index)
{
	SBCheckError(TElPDFPublicKeyRevocationInfo_RemoveCRL(_Handle, Index));
}

SB_INLINE void TElPDFPublicKeyRevocationInfo::ClearCRLs()
{
	SBCheckError(TElPDFPublicKeyRevocationInfo_ClearCRLs(_Handle));
}

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
bool TElPDFPublicKeyRevocationInfo::ContainsCRL(TElCertificateRevocationList &Crl)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFPublicKeyRevocationInfo_ContainsCRL(_Handle, Crl.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPDFPublicKeyRevocationInfo::ContainsCRL(TElCertificateRevocationList *Crl)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFPublicKeyRevocationInfo_ContainsCRL(_Handle, (Crl != NULL) ? Crl->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

SB_INLINE int32_t TElPDFPublicKeyRevocationInfo::AddOCSPResponse()
{
	int32_t OutResult;
	SBCheckError(TElPDFPublicKeyRevocationInfo_AddOCSPResponse(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFPublicKeyRevocationInfo::RemoveOCSPRespose(int32_t Index)
{
	SBCheckError(TElPDFPublicKeyRevocationInfo_RemoveOCSPRespose(_Handle, Index));
}

SB_INLINE void TElPDFPublicKeyRevocationInfo::ClearOCSPResponses()
{
	SBCheckError(TElPDFPublicKeyRevocationInfo_ClearOCSPResponses(_Handle));
}

bool TElPDFPublicKeyRevocationInfo::ContainsOCSPResponse(const std::vector<uint8_t> &Response)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFPublicKeyRevocationInfo_ContainsOCSPResponse(_Handle, SB_STD_VECTOR_FRONT_ADR(Response), (int32_t)Response.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFPublicKeyRevocationInfo::Clear()
{
	SBCheckError(TElPDFPublicKeyRevocationInfo_Clear(_Handle));
}

bool TElPDFPublicKeyRevocationInfo::IsEmpty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFPublicKeyRevocationInfo_IsEmpty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
TElCertificateRevocationList* TElPDFPublicKeyRevocationInfo::get_CRLs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFPublicKeyRevocationInfo_get_CRLs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLs)
		this->_Inst_CRLs = new TElCertificateRevocationList(hOutResult, ohFalse);
	else
		this->_Inst_CRLs->updateHandle(hOutResult);
	return this->_Inst_CRLs;
}
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

void TElPDFPublicKeyRevocationInfo::get_OCSPResponses(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFPublicKeyRevocationInfo_get_OCSPResponses(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1444521565, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFPublicKeyRevocationInfo::set_OCSPResponses(int32_t Index, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPDFPublicKeyRevocationInfo_set_OCSPResponses(_Handle, Index, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElPDFPublicKeyRevocationInfo::get_CRLCount()
{
	int32_t OutResult;
	SBCheckError(TElPDFPublicKeyRevocationInfo_get_CRLCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFPublicKeyRevocationInfo::get_OCSPResponseCount()
{
	int32_t OutResult;
	SBCheckError(TElPDFPublicKeyRevocationInfo_get_OCSPResponseCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
TElMemoryCertStorage* TElPDFPublicKeyRevocationInfo::get_Certificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFPublicKeyRevocationInfo_get_Certificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElMemoryCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedName* TElPDFPublicKeyRevocationInfo::get_OtherInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFPublicKeyRevocationInfo_get_OtherInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OtherInfo)
		this->_Inst_OtherInfo = new TElRelativeDistinguishedName(hOutResult, ohFalse);
	else
		this->_Inst_OtherInfo->updateHandle(hOutResult);
	return this->_Inst_OtherInfo;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

void TElPDFPublicKeyRevocationInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
	this->_Inst_CRLs = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	this->_Inst_OtherInfo = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
}

TElPDFPublicKeyRevocationInfo::TElPDFPublicKeyRevocationInfo(TElPDFPublicKeyRevocationInfoHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPDFPublicKeyRevocationInfo::TElPDFPublicKeyRevocationInfo() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFPublicKeyRevocationInfo_Create(&_Handle));
}

TElPDFPublicKeyRevocationInfo::~TElPDFPublicKeyRevocationInfo()
{
#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
	delete this->_Inst_CRLs;
	this->_Inst_CRLs = NULL;
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
	delete this->_Inst_OtherInfo;
	this->_Inst_OtherInfo = NULL;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
}
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO */

};	/* namespace SecureBlackbox */

