#include "sbocspserver.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELOCSPSERVER

int32_t TElOCSPServer::ProcessRequest(const std::vector<uint8_t> &Request, std::vector<uint8_t> &Reply)
{
	int32_t OutResult;
	int32_t szReply = (int32_t)Reply.size();
	uint32_t _err = TElOCSPServer_ProcessRequest(_Handle, SB_STD_VECTOR_FRONT_ADR(Request), (int32_t)Request.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Reply), &szReply, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Reply.resize(szReply);
		SBCheckError(SBGetLastReturnBuffer(-1727265080, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Reply), &szReply));
	}
	else
		SBCheckError(_err);

	Reply.resize(szReply);
	return OutResult;
}

TElResponderIDType TElOCSPServer::get_ResponderIdType()
{
	TElResponderIDTypeRaw OutResultRaw = 0;
	SBCheckError(TElOCSPServer_get_ResponderIdType(_Handle, &OutResultRaw));
	return (TElResponderIDType)OutResultRaw;
}

SB_INLINE void TElOCSPServer::set_ResponderIdType(TElResponderIDType Value)
{
	SBCheckError(TElOCSPServer_set_ResponderIdType(_Handle, (TElResponderIDTypeRaw)Value));
}

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
TElMemoryCertStorage* TElOCSPServer::get_RequestCertificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOCSPServer_get_RequestCertificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_RequestCertificates)
		this->_Inst_RequestCertificates = new TElMemoryCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_RequestCertificates->updateHandle(hOutResult);
	return this->_Inst_RequestCertificates;
}
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

SB_INLINE int32_t TElOCSPServer::get_SignatureAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElOCSPServer_get_SignatureAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOCSPServer::set_SignatureAlgorithm(int32_t Value)
{
	SBCheckError(TElOCSPServer_set_SignatureAlgorithm(_Handle, Value));
}

SB_INLINE int64_t TElOCSPServer::get_ProducedAt()
{
	int64_t OutResult;
	SBCheckError(TElOCSPServer_get_ProducedAt(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOCSPServer::set_ProducedAt(int64_t Value)
{
	SBCheckError(TElOCSPServer_set_ProducedAt(_Handle, Value));
}

bool TElOCSPServer::get_SignatureRequired()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOCSPServer_get_SignatureRequired(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOCSPServer::set_SignatureRequired(bool Value)
{
	SBCheckError(TElOCSPServer_set_SignatureRequired(_Handle, (int8_t)Value));
}

TSBOCSPServerOptions TElOCSPServer::get_Options()
{
	TSBOCSPServerOptionsRaw OutResultRaw = 0;
	SBCheckError(TElOCSPServer_get_Options(_Handle, &OutResultRaw));
	return (TSBOCSPServerOptions)OutResultRaw;
}

SB_INLINE void TElOCSPServer::set_Options(TSBOCSPServerOptions Value)
{
	SBCheckError(TElOCSPServer_set_Options(_Handle, (TSBOCSPServerOptionsRaw)Value));
}

SB_INLINE int32_t TElOCSPServer::get_IssuerHashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElOCSPServer_get_IssuerHashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOCSPServer::set_IssuerHashAlgorithm(int32_t Value)
{
	SBCheckError(TElOCSPServer_set_IssuerHashAlgorithm(_Handle, Value));
}

SB_INLINE void TElOCSPServer::get_OnCertificateCheck(TSBCertificateOCSPCheckEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOCSPServer_get_OnCertificateCheck(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOCSPServer::set_OnCertificateCheck(TSBCertificateOCSPCheckEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOCSPServer_set_OnCertificateCheck(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElOCSPServer::get_OnSignatureValidate(TSBOCSPSignatureValidateEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOCSPServer_get_OnSignatureValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOCSPServer::set_OnSignatureValidate(TSBOCSPSignatureValidateEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOCSPServer_set_OnSignatureValidate(_Handle, pMethodValue, pDataValue));
}

void TElOCSPServer::initInstances()
{
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	this->_Inst_RequestCertificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
}

TElOCSPServer::TElOCSPServer(TElOCSPServerHandle handle, TElOwnHandle ownHandle) : TElOCSPClass(handle, ownHandle)
{
	initInstances();
}

TElOCSPServer::TElOCSPServer(TComponent &Owner) : TElOCSPClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOCSPServer_Create(Owner.getHandle(), &_Handle));
}

TElOCSPServer::TElOCSPServer(TComponent *Owner) : TElOCSPClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOCSPServer_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElOCSPServer::~TElOCSPServer()
{
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	delete this->_Inst_RequestCertificates;
	this->_Inst_RequestCertificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELOCSPSERVER */

};	/* namespace SecureBlackbox */

