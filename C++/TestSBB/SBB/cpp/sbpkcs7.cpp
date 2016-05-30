#include "sbpkcs7.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPKCS7RECIPIENT

SB_INLINE int32_t TElPKCS7Recipient::get_Version()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7Recipient_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS7Recipient::set_Version(int32_t Value)
{
	SBCheckError(TElPKCS7Recipient_set_Version(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELPKCS7ISSUER
TElPKCS7Issuer* TElPKCS7Recipient::get_Issuer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7Recipient_get_Issuer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Issuer)
		this->_Inst_Issuer = new TElPKCS7Issuer(hOutResult, ohFalse);
	else
		this->_Inst_Issuer->updateHandle(hOutResult);
	return this->_Inst_Issuer;
}
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

void TElPKCS7Recipient::get_KeyEncryptionAlgorithm(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7Recipient_get_KeyEncryptionAlgorithm(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2127629804, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7Recipient::set_KeyEncryptionAlgorithm(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7Recipient_set_KeyEncryptionAlgorithm(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7Recipient::get_KeyEncryptionAlgorithmParams(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7Recipient_get_KeyEncryptionAlgorithmParams(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1613835912, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7Recipient::set_KeyEncryptionAlgorithmParams(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7Recipient_set_KeyEncryptionAlgorithmParams(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
TElAlgorithmIdentifier* TElPKCS7Recipient::get_KeyEncryptionAlgorithmIdentifier()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7Recipient_get_KeyEncryptionAlgorithmIdentifier(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyEncryptionAlgorithmIdentifier)
		this->_Inst_KeyEncryptionAlgorithmIdentifier = new TElAlgorithmIdentifier(hOutResult, ohFalse);
	else
		this->_Inst_KeyEncryptionAlgorithmIdentifier->updateHandle(hOutResult);
	return this->_Inst_KeyEncryptionAlgorithmIdentifier;
}

SB_INLINE void TElPKCS7Recipient::set_KeyEncryptionAlgorithmIdentifier(TElAlgorithmIdentifier &Value)
{
	SBCheckError(TElPKCS7Recipient_set_KeyEncryptionAlgorithmIdentifier(_Handle, Value.getHandle()));
}

SB_INLINE void TElPKCS7Recipient::set_KeyEncryptionAlgorithmIdentifier(TElAlgorithmIdentifier *Value)
{
	SBCheckError(TElPKCS7Recipient_set_KeyEncryptionAlgorithmIdentifier(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

void TElPKCS7Recipient::get_EncryptedKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7Recipient_get_EncryptedKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(748306782, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7Recipient::set_EncryptedKey(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7Recipient_set_EncryptedKey(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7Recipient::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	this->_Inst_KeyEncryptionAlgorithmIdentifier = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
}

TElPKCS7Recipient::TElPKCS7Recipient(TElPKCS7RecipientHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS7Recipient::TElPKCS7Recipient() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS7Recipient_Create(&_Handle));
}

TElPKCS7Recipient::~TElPKCS7Recipient()
{
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
	delete this->_Inst_Issuer;
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
	delete this->_Inst_KeyEncryptionAlgorithmIdentifier;
	this->_Inst_KeyEncryptionAlgorithmIdentifier = NULL;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
}
#endif /* SB_USE_CLASS_TELPKCS7RECIPIENT */

#ifdef SB_USE_CLASS_TELPKCS7CONTENTPART

SB_INLINE int32_t TElPKCS7ContentPart::Read(void * Buffer, int32_t Size, int32_t StartOffset)
{
	int32_t OutResult;
	SBCheckError(TElPKCS7ContentPart_Read(_Handle, Buffer, Size, StartOffset, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS7ContentPart::get_Size()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7ContentPart_get_Size(_Handle, &OutResult));
	return OutResult;
}

TElPKCS7ContentPart::TElPKCS7ContentPart(TElPKCS7ContentPartHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPKCS7ContentPart::TElPKCS7ContentPart() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS7ContentPart_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPKCS7CONTENTPART */

#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT

SB_INLINE int32_t TElPKCS7EncryptedContent::AddContentPart()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7EncryptedContent_AddContentPart(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS7EncryptedContent::ClearContentParts()
{
	SBCheckError(TElPKCS7EncryptedContent_ClearContentParts(_Handle));
}

void TElPKCS7EncryptedContent::get_ContentType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7EncryptedContent_get_ContentType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1471784335, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7EncryptedContent::set_ContentType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7EncryptedContent_set_ContentType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7EncryptedContent::get_ContentEncryptionAlgorithm(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7EncryptedContent_get_ContentEncryptionAlgorithm(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1156472986, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7EncryptedContent::set_ContentEncryptionAlgorithm(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7EncryptedContent_set_ContentEncryptionAlgorithm(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7EncryptedContent::get_ContentEncryptionAlgorithmParams(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7EncryptedContent_get_ContentEncryptionAlgorithmParams(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1566374681, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7EncryptedContent::set_ContentEncryptionAlgorithmParams(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7EncryptedContent_set_ContentEncryptionAlgorithmParams(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7EncryptedContent::get_EncryptedContent(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7EncryptedContent_get_EncryptedContent(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1205798240, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7EncryptedContent::set_EncryptedContent(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7EncryptedContent_set_EncryptedContent(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
TElASN1DataSource* TElPKCS7EncryptedContent::get_EncryptedContentParts(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7EncryptedContent_get_EncryptedContentParts(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptedContentParts)
		this->_Inst_EncryptedContentParts = new TElASN1DataSource(hOutResult, ohFalse);
	else
		this->_Inst_EncryptedContentParts->updateHandle(hOutResult);
	return this->_Inst_EncryptedContentParts;
}
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

SB_INLINE int32_t TElPKCS7EncryptedContent::get_EncryptedContentPartCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7EncryptedContent_get_EncryptedContentPartCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
TElASN1DataSource* TElPKCS7EncryptedContent::get_DataSource()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7EncryptedContent_get_DataSource(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DataSource)
		this->_Inst_DataSource = new TElASN1DataSource(hOutResult, ohFalse);
	else
		this->_Inst_DataSource->updateHandle(hOutResult);
	return this->_Inst_DataSource;
}
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

bool TElPKCS7EncryptedContent::get_UseImplicitContentEncoding()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7EncryptedContent_get_UseImplicitContentEncoding(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS7EncryptedContent::set_UseImplicitContentEncoding(bool Value)
{
	SBCheckError(TElPKCS7EncryptedContent_set_UseImplicitContentEncoding(_Handle, (int8_t)Value));
}

void TElPKCS7EncryptedContent::initInstances()
{
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	this->_Inst_EncryptedContentParts = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	this->_Inst_DataSource = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
}

TElPKCS7EncryptedContent::TElPKCS7EncryptedContent(TElPKCS7EncryptedContentHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS7EncryptedContent::TElPKCS7EncryptedContent() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS7EncryptedContent_Create(&_Handle));
}

TElPKCS7EncryptedContent::~TElPKCS7EncryptedContent()
{
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	delete this->_Inst_EncryptedContentParts;
	this->_Inst_EncryptedContentParts = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	delete this->_Inst_DataSource;
	this->_Inst_DataSource = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
}
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT */

#ifdef SB_USE_CLASS_TELPKCS7MESSAGE

SB_INLINE void TElPKCS7Message::Reset()
{
	SBCheckError(TElPKCS7Message_Reset(_Handle));
}

SB_INLINE int32_t TElPKCS7Message::LoadFromBuffer(void * Buffer, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElPKCS7Message_LoadFromBuffer(_Handle, Buffer, Size, &OutResult));
	return OutResult;
}

bool TElPKCS7Message::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7Message_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElPKCS7Message::LoadFromStream(TStream &Stream, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElPKCS7Message_LoadFromStream(_Handle, Stream.getHandle(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS7Message::LoadFromStream(TStream *Stream, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElPKCS7Message_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPKCS7Message::SaveToStream(TStream &Stream)
{
	SBCheckError(TElPKCS7Message_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElPKCS7Message::SaveToStream(TStream *Stream)
{
	SBCheckError(TElPKCS7Message_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

TSBPKCS7ContentType TElPKCS7Message::get_ContentType()
{
	TSBPKCS7ContentTypeRaw OutResultRaw = 0;
	SBCheckError(TElPKCS7Message_get_ContentType(_Handle, &OutResultRaw));
	return (TSBPKCS7ContentType)OutResultRaw;
}

SB_INLINE void TElPKCS7Message::set_ContentType(TSBPKCS7ContentType Value)
{
	SBCheckError(TElPKCS7Message_set_ContentType(_Handle, (TSBPKCS7ContentTypeRaw)Value));
}

void TElPKCS7Message::get_Data(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7Message_get_Data(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1055398612, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7Message::set_Data(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7Message_set_Data(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELPKCS7ENVELOPEDDATA
TElPKCS7EnvelopedData* TElPKCS7Message::get_EnvelopedData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7Message_get_EnvelopedData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EnvelopedData)
		this->_Inst_EnvelopedData = new TElPKCS7EnvelopedData(hOutResult, ohFalse);
	else
		this->_Inst_EnvelopedData->updateHandle(hOutResult);
	return this->_Inst_EnvelopedData;
}
#endif /* SB_USE_CLASS_TELPKCS7ENVELOPEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7COMPRESSEDDATA
TElPKCS7CompressedData* TElPKCS7Message::get_CompressedData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7Message_get_CompressedData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CompressedData)
		this->_Inst_CompressedData = new TElPKCS7CompressedData(hOutResult, ohFalse);
	else
		this->_Inst_CompressedData->updateHandle(hOutResult);
	return this->_Inst_CompressedData;
}
#endif /* SB_USE_CLASS_TELPKCS7COMPRESSEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7SIGNEDDATA
TElPKCS7SignedData* TElPKCS7Message::get_SignedData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7Message_get_SignedData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignedData)
		this->_Inst_SignedData = new TElPKCS7SignedData(hOutResult, ohFalse);
	else
		this->_Inst_SignedData->updateHandle(hOutResult);
	return this->_Inst_SignedData;
}
#endif /* SB_USE_CLASS_TELPKCS7SIGNEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7DIGESTEDDATA
TElPKCS7DigestedData* TElPKCS7Message::get_DigestedData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7Message_get_DigestedData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DigestedData)
		this->_Inst_DigestedData = new TElPKCS7DigestedData(hOutResult, ohFalse);
	else
		this->_Inst_DigestedData->updateHandle(hOutResult);
	return this->_Inst_DigestedData;
}
#endif /* SB_USE_CLASS_TELPKCS7DIGESTEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDDATA
TElPKCS7EncryptedData* TElPKCS7Message::get_EncryptedData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7Message_get_EncryptedData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptedData)
		this->_Inst_EncryptedData = new TElPKCS7EncryptedData(hOutResult, ohFalse);
	else
		this->_Inst_EncryptedData->updateHandle(hOutResult);
	return this->_Inst_EncryptedData;
}
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7SIGNEDANDENVELOPEDDATA
TElPKCS7SignedAndEnvelopedData* TElPKCS7Message::get_SignedAndEnvelopedData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7Message_get_SignedAndEnvelopedData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignedAndEnvelopedData)
		this->_Inst_SignedAndEnvelopedData = new TElPKCS7SignedAndEnvelopedData(hOutResult, ohFalse);
	else
		this->_Inst_SignedAndEnvelopedData->updateHandle(hOutResult);
	return this->_Inst_SignedAndEnvelopedData;
}
#endif /* SB_USE_CLASS_TELPKCS7SIGNEDANDENVELOPEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7AUTHENTICATEDDATA
TElPKCS7AuthenticatedData* TElPKCS7Message::get_AuthenticatedData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7Message_get_AuthenticatedData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AuthenticatedData)
		this->_Inst_AuthenticatedData = new TElPKCS7AuthenticatedData(hOutResult, ohFalse);
	else
		this->_Inst_AuthenticatedData->updateHandle(hOutResult);
	return this->_Inst_AuthenticatedData;
}
#endif /* SB_USE_CLASS_TELPKCS7AUTHENTICATEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7TIMESTAMPEDDATA
TElPKCS7TimestampedData* TElPKCS7Message::get_TimestampedData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7Message_get_TimestampedData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TimestampedData)
		this->_Inst_TimestampedData = new TElPKCS7TimestampedData(hOutResult, ohFalse);
	else
		this->_Inst_TimestampedData->updateHandle(hOutResult);
	return this->_Inst_TimestampedData;
}
#endif /* SB_USE_CLASS_TELPKCS7TIMESTAMPEDDATA */

bool TElPKCS7Message::get_UseImplicitContent()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7Message_get_UseImplicitContent(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS7Message::set_UseImplicitContent(bool Value)
{
	SBCheckError(TElPKCS7Message_set_UseImplicitContent(_Handle, (int8_t)Value));
}

bool TElPKCS7Message::get_UseUndefSize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7Message_get_UseUndefSize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS7Message::set_UseUndefSize(bool Value)
{
	SBCheckError(TElPKCS7Message_set_UseUndefSize(_Handle, (int8_t)Value));
}

bool TElPKCS7Message::get_NoOuterContentInfo()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7Message_get_NoOuterContentInfo(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS7Message::set_NoOuterContentInfo(bool Value)
{
	SBCheckError(TElPKCS7Message_set_NoOuterContentInfo(_Handle, (int8_t)Value));
}

bool TElPKCS7Message::get_AllowUnknownContentTypes()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7Message_get_AllowUnknownContentTypes(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS7Message::set_AllowUnknownContentTypes(bool Value)
{
	SBCheckError(TElPKCS7Message_set_AllowUnknownContentTypes(_Handle, (int8_t)Value));
}

void TElPKCS7Message::get_CustomContentType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7Message_get_CustomContentType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(618629830, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7Message::set_CustomContentType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7Message_set_CustomContentType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7Message::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS7ENVELOPEDDATA
	this->_Inst_EnvelopedData = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ENVELOPEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7COMPRESSEDDATA
	this->_Inst_CompressedData = NULL;
#endif /* SB_USE_CLASS_TELPKCS7COMPRESSEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7SIGNEDDATA
	this->_Inst_SignedData = NULL;
#endif /* SB_USE_CLASS_TELPKCS7SIGNEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7DIGESTEDDATA
	this->_Inst_DigestedData = NULL;
#endif /* SB_USE_CLASS_TELPKCS7DIGESTEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDDATA
	this->_Inst_EncryptedData = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7SIGNEDANDENVELOPEDDATA
	this->_Inst_SignedAndEnvelopedData = NULL;
#endif /* SB_USE_CLASS_TELPKCS7SIGNEDANDENVELOPEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7AUTHENTICATEDDATA
	this->_Inst_AuthenticatedData = NULL;
#endif /* SB_USE_CLASS_TELPKCS7AUTHENTICATEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7TIMESTAMPEDDATA
	this->_Inst_TimestampedData = NULL;
#endif /* SB_USE_CLASS_TELPKCS7TIMESTAMPEDDATA */
}

TElPKCS7Message::TElPKCS7Message(TElPKCS7MessageHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS7Message::TElPKCS7Message() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS7Message_Create(&_Handle));
}

TElPKCS7Message::~TElPKCS7Message()
{
#ifdef SB_USE_CLASS_TELPKCS7ENVELOPEDDATA
	delete this->_Inst_EnvelopedData;
	this->_Inst_EnvelopedData = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ENVELOPEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7COMPRESSEDDATA
	delete this->_Inst_CompressedData;
	this->_Inst_CompressedData = NULL;
#endif /* SB_USE_CLASS_TELPKCS7COMPRESSEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7SIGNEDDATA
	delete this->_Inst_SignedData;
	this->_Inst_SignedData = NULL;
#endif /* SB_USE_CLASS_TELPKCS7SIGNEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7DIGESTEDDATA
	delete this->_Inst_DigestedData;
	this->_Inst_DigestedData = NULL;
#endif /* SB_USE_CLASS_TELPKCS7DIGESTEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDDATA
	delete this->_Inst_EncryptedData;
	this->_Inst_EncryptedData = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7SIGNEDANDENVELOPEDDATA
	delete this->_Inst_SignedAndEnvelopedData;
	this->_Inst_SignedAndEnvelopedData = NULL;
#endif /* SB_USE_CLASS_TELPKCS7SIGNEDANDENVELOPEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7AUTHENTICATEDDATA
	delete this->_Inst_AuthenticatedData;
	this->_Inst_AuthenticatedData = NULL;
#endif /* SB_USE_CLASS_TELPKCS7AUTHENTICATEDDATA */
#ifdef SB_USE_CLASS_TELPKCS7TIMESTAMPEDDATA
	delete this->_Inst_TimestampedData;
	this->_Inst_TimestampedData = NULL;
#endif /* SB_USE_CLASS_TELPKCS7TIMESTAMPEDDATA */
}
#endif /* SB_USE_CLASS_TELPKCS7MESSAGE */

#ifdef SB_USE_CLASS_TELPKCS7ENVELOPEDDATA

SB_INLINE int32_t TElPKCS7EnvelopedData::AddRecipient()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7EnvelopedData_AddRecipient(_Handle, &OutResult));
	return OutResult;
}

bool TElPKCS7EnvelopedData::RemoveRecipient(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7EnvelopedData_RemoveRecipient(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS7EnvelopedData::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7EnvelopedData_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElPKCS7EnvelopedData::get_Version()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7EnvelopedData_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS7EnvelopedData::set_Version(int32_t Value)
{
	SBCheckError(TElPKCS7EnvelopedData_set_Version(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELPKCS7RECIPIENT
TElPKCS7Recipient* TElPKCS7EnvelopedData::get_Recipients(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7EnvelopedData_get_Recipients(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Recipients)
		this->_Inst_Recipients = new TElPKCS7Recipient(hOutResult, ohFalse);
	else
		this->_Inst_Recipients->updateHandle(hOutResult);
	return this->_Inst_Recipients;
}
#endif /* SB_USE_CLASS_TELPKCS7RECIPIENT */

SB_INLINE int32_t TElPKCS7EnvelopedData::get_RecipientCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7EnvelopedData_get_RecipientCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT
TElPKCS7EncryptedContent* TElPKCS7EnvelopedData::get_EncryptedContent()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7EnvelopedData_get_EncryptedContent(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptedContent)
		this->_Inst_EncryptedContent = new TElPKCS7EncryptedContent(hOutResult, ohFalse);
	else
		this->_Inst_EncryptedContent->updateHandle(hOutResult);
	return this->_Inst_EncryptedContent;
}

SB_INLINE void TElPKCS7EnvelopedData::set_EncryptedContent(TElPKCS7EncryptedContent &Value)
{
	SBCheckError(TElPKCS7EnvelopedData_set_EncryptedContent(_Handle, Value.getHandle()));
}

SB_INLINE void TElPKCS7EnvelopedData::set_EncryptedContent(TElPKCS7EncryptedContent *Value)
{
	SBCheckError(TElPKCS7EnvelopedData_set_EncryptedContent(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT */

SB_INLINE int32_t TElPKCS7EnvelopedData::get_ContentEncryptionAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7EnvelopedData_get_ContentEncryptionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS7EnvelopedData::set_ContentEncryptionAlgorithm(int32_t Value)
{
	SBCheckError(TElPKCS7EnvelopedData_set_ContentEncryptionAlgorithm(_Handle, Value));
}

bool TElPKCS7EnvelopedData::get_CMSFormat()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7EnvelopedData_get_CMSFormat(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS7EnvelopedData::set_CMSFormat(bool Value)
{
	SBCheckError(TElPKCS7EnvelopedData_set_CMSFormat(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
TElMemoryCertStorage* TElPKCS7EnvelopedData::get_OriginatorCertificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7EnvelopedData_get_OriginatorCertificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OriginatorCertificates)
		this->_Inst_OriginatorCertificates = new TElMemoryCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_OriginatorCertificates->updateHandle(hOutResult);
	return this->_Inst_OriginatorCertificates;
}
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
TElMemoryCRLStorage* TElPKCS7EnvelopedData::get_OriginatorCRLs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7EnvelopedData_get_OriginatorCRLs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OriginatorCRLs)
		this->_Inst_OriginatorCRLs = new TElMemoryCRLStorage(hOutResult, ohFalse);
	else
		this->_Inst_OriginatorCRLs->updateHandle(hOutResult);
	return this->_Inst_OriginatorCRLs;
}
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
TElPKCS7Attributes* TElPKCS7EnvelopedData::get_UnprotectedAttributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7EnvelopedData_get_UnprotectedAttributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_UnprotectedAttributes)
		this->_Inst_UnprotectedAttributes = new TElPKCS7Attributes(hOutResult, ohFalse);
	else
		this->_Inst_UnprotectedAttributes->updateHandle(hOutResult);
	return this->_Inst_UnprotectedAttributes;
}
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

void TElPKCS7EnvelopedData::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS7RECIPIENT
	this->_Inst_Recipients = NULL;
#endif /* SB_USE_CLASS_TELPKCS7RECIPIENT */
#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT
	this->_Inst_EncryptedContent = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT */
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	this->_Inst_OriginatorCertificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
	this->_Inst_OriginatorCRLs = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	this->_Inst_UnprotectedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
}

TElPKCS7EnvelopedData::TElPKCS7EnvelopedData(TElPKCS7EnvelopedDataHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS7EnvelopedData::TElPKCS7EnvelopedData() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS7EnvelopedData_Create(&_Handle));
}

TElPKCS7EnvelopedData::~TElPKCS7EnvelopedData()
{
#ifdef SB_USE_CLASS_TELPKCS7RECIPIENT
	delete this->_Inst_Recipients;
	this->_Inst_Recipients = NULL;
#endif /* SB_USE_CLASS_TELPKCS7RECIPIENT */
#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT
	delete this->_Inst_EncryptedContent;
	this->_Inst_EncryptedContent = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT */
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	delete this->_Inst_OriginatorCertificates;
	this->_Inst_OriginatorCertificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
	delete this->_Inst_OriginatorCRLs;
	this->_Inst_OriginatorCRLs = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	delete this->_Inst_UnprotectedAttributes;
	this->_Inst_UnprotectedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
}
#endif /* SB_USE_CLASS_TELPKCS7ENVELOPEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7COMPRESSEDDATA

bool TElPKCS7CompressedData::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7CompressedData_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElPKCS7CompressedData::get_Version()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7CompressedData_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS7CompressedData::set_Version(int32_t Value)
{
	SBCheckError(TElPKCS7CompressedData_set_Version(_Handle, Value));
}

void TElPKCS7CompressedData::get_ContentType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7CompressedData_get_ContentType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(804344461, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7CompressedData::set_ContentType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7CompressedData_set_ContentType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7CompressedData::get_CompressedContent(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7CompressedData_get_CompressedContent(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(505691339, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7CompressedData::set_CompressedContent(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7CompressedData_set_CompressedContent(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
TElASN1DataSource* TElPKCS7CompressedData::get_CompressedContentParts(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7CompressedData_get_CompressedContentParts(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CompressedContentParts)
		this->_Inst_CompressedContentParts = new TElASN1DataSource(hOutResult, ohFalse);
	else
		this->_Inst_CompressedContentParts->updateHandle(hOutResult);
	return this->_Inst_CompressedContentParts;
}
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

SB_INLINE int32_t TElPKCS7CompressedData::get_CompressedContentPartCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7CompressedData_get_CompressedContentPartCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS7CompressedData::get_FragmentSize()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7CompressedData_get_FragmentSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS7CompressedData::set_FragmentSize(int32_t Value)
{
	SBCheckError(TElPKCS7CompressedData_set_FragmentSize(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
TElASN1DataSource* TElPKCS7CompressedData::get_DataSource()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7CompressedData_get_DataSource(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DataSource)
		this->_Inst_DataSource = new TElASN1DataSource(hOutResult, ohFalse);
	else
		this->_Inst_DataSource->updateHandle(hOutResult);
	return this->_Inst_DataSource;
}
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

void TElPKCS7CompressedData::initInstances()
{
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	this->_Inst_CompressedContentParts = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	this->_Inst_DataSource = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
}

TElPKCS7CompressedData::TElPKCS7CompressedData(TElPKCS7CompressedDataHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS7CompressedData::TElPKCS7CompressedData() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS7CompressedData_Create(&_Handle));
}

TElPKCS7CompressedData::~TElPKCS7CompressedData()
{
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	delete this->_Inst_CompressedContentParts;
	this->_Inst_CompressedContentParts = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	delete this->_Inst_DataSource;
	this->_Inst_DataSource = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
}
#endif /* SB_USE_CLASS_TELPKCS7COMPRESSEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7SIGNER

SB_INLINE void TElPKCS7Signer::RecalculateAuthenticatedAttributes()
{
	SBCheckError(TElPKCS7Signer_RecalculateAuthenticatedAttributes(_Handle));
}

SB_INLINE void TElPKCS7Signer::RecalculateAuthenticatedAttributes(bool Reorder)
{
	SBCheckError(TElPKCS7Signer_RecalculateAuthenticatedAttributes_1(_Handle, (int8_t)Reorder));
}

SB_INLINE void TElPKCS7Signer::Recalculate()
{
	SBCheckError(TElPKCS7Signer_Recalculate(_Handle));
}

SB_INLINE void TElPKCS7Signer::Reset()
{
	SBCheckError(TElPKCS7Signer_Reset(_Handle));
}

SB_INLINE void TElPKCS7Signer::Assign(TElPKCS7Signer &Source)
{
	SBCheckError(TElPKCS7Signer_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPKCS7Signer::Assign(TElPKCS7Signer *Source)
{
	SBCheckError(TElPKCS7Signer_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElPKCS7Signer::get_Version()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7Signer_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS7Signer::set_Version(int32_t Value)
{
	SBCheckError(TElPKCS7Signer_set_Version(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELPKCS7ISSUER
TElPKCS7Issuer* TElPKCS7Signer::get_Issuer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7Signer_get_Issuer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Issuer)
		this->_Inst_Issuer = new TElPKCS7Issuer(hOutResult, ohFalse);
	else
		this->_Inst_Issuer->updateHandle(hOutResult);
	return this->_Inst_Issuer;
}
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

void TElPKCS7Signer::get_DigestAlgorithm(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7Signer_get_DigestAlgorithm(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1539047054, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7Signer::set_DigestAlgorithm(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7Signer_set_DigestAlgorithm(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7Signer::get_DigestAlgorithmParams(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7Signer_get_DigestAlgorithmParams(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1082407224, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7Signer::set_DigestAlgorithmParams(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7Signer_set_DigestAlgorithmParams(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7Signer::get_DigestEncryptionAlgorithm(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7Signer_get_DigestEncryptionAlgorithm(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1754950300, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7Signer::set_DigestEncryptionAlgorithm(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7Signer_set_DigestEncryptionAlgorithm(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7Signer::get_DigestEncryptionAlgorithmParams(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7Signer_get_DigestEncryptionAlgorithmParams(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1200088590, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7Signer::set_DigestEncryptionAlgorithmParams(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7Signer_set_DigestEncryptionAlgorithmParams(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
TElPKCS7Attributes* TElPKCS7Signer::get_AuthenticatedAttributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7Signer_get_AuthenticatedAttributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AuthenticatedAttributes)
		this->_Inst_AuthenticatedAttributes = new TElPKCS7Attributes(hOutResult, ohFalse);
	else
		this->_Inst_AuthenticatedAttributes->updateHandle(hOutResult);
	return this->_Inst_AuthenticatedAttributes;
}
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
TElPKCS7Attributes* TElPKCS7Signer::get_UnauthenticatedAttributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7Signer_get_UnauthenticatedAttributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_UnauthenticatedAttributes)
		this->_Inst_UnauthenticatedAttributes = new TElPKCS7Attributes(hOutResult, ohFalse);
	else
		this->_Inst_UnauthenticatedAttributes->updateHandle(hOutResult);
	return this->_Inst_UnauthenticatedAttributes;
}
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

void TElPKCS7Signer::get_EncryptedDigest(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7Signer_get_EncryptedDigest(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-724823074, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7Signer::set_EncryptedDigest(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7Signer_set_EncryptedDigest(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7Signer::get_AuthenticatedAttributesPlain(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7Signer_get_AuthenticatedAttributesPlain(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-609692489, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS7Signer::get_Content(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7Signer_get_Content(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1657117907, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS7Signer::get_EncodedValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7Signer_get_EncodedValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-614728203, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS7Signer::get_ArchivalEncodedValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7Signer_get_ArchivalEncodedValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1435419862, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS7Signer::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	this->_Inst_AuthenticatedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	this->_Inst_UnauthenticatedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
}

TElPKCS7Signer::TElPKCS7Signer(TElPKCS7SignerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS7Signer::TElPKCS7Signer() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS7Signer_Create(&_Handle));
}

TElPKCS7Signer::~TElPKCS7Signer()
{
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
	delete this->_Inst_Issuer;
	this->_Inst_Issuer = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	delete this->_Inst_AuthenticatedAttributes;
	this->_Inst_AuthenticatedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	delete this->_Inst_UnauthenticatedAttributes;
	this->_Inst_UnauthenticatedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
}
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */

#ifdef SB_USE_CLASS_TELPKCS7SIGNEDDATA

SB_INLINE int32_t TElPKCS7SignedData::AddContentPart()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7SignedData_AddContentPart(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS7SignedData::ClearContentParts()
{
	SBCheckError(TElPKCS7SignedData_ClearContentParts(_Handle));
}

SB_INLINE int32_t TElPKCS7SignedData::AddSigner()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7SignedData_AddSigner(_Handle, &OutResult));
	return OutResult;
}

bool TElPKCS7SignedData::RemoveSigner(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7SignedData_RemoveSigner(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS7SignedData::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7SignedData_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPKCS7SignedData::SaveToStream(TStream &Stream)
{
	SBCheckError(TElPKCS7SignedData_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElPKCS7SignedData::SaveToStream(TStream *Stream)
{
	SBCheckError(TElPKCS7SignedData_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPKCS7SignedData::PreSerialize(bool SerializeContent, bool SerializeCertsAndCrls)
{
	SBCheckError(TElPKCS7SignedData_PreSerialize(_Handle, (int8_t)SerializeContent, (int8_t)SerializeCertsAndCrls));
}

SB_INLINE int32_t TElPKCS7SignedData::get_Version()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7SignedData_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS7SignedData::set_Version(int32_t Value)
{
	SBCheckError(TElPKCS7SignedData_set_Version(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELPKCS7SIGNER
TElPKCS7Signer* TElPKCS7SignedData::get_Signers(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7SignedData_get_Signers(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signers)
		this->_Inst_Signers = new TElPKCS7Signer(hOutResult, ohFalse);
	else
		this->_Inst_Signers->updateHandle(hOutResult);
	return this->_Inst_Signers;
}
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
TElASN1DataSource* TElPKCS7SignedData::get_ContentParts(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7SignedData_get_ContentParts(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ContentParts)
		this->_Inst_ContentParts = new TElASN1DataSource(hOutResult, ohFalse);
	else
		this->_Inst_ContentParts->updateHandle(hOutResult);
	return this->_Inst_ContentParts;
}
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

SB_INLINE int32_t TElPKCS7SignedData::get_SignerCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7SignedData_get_SignerCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
TElMemoryCertStorage* TElPKCS7SignedData::get_Certificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7SignedData_get_Certificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElMemoryCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
TElMemoryCRLStorage* TElPKCS7SignedData::get_CRLs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7SignedData_get_CRLs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLs)
		this->_Inst_CRLs = new TElMemoryCRLStorage(hOutResult, ohFalse);
	else
		this->_Inst_CRLs->updateHandle(hOutResult);
	return this->_Inst_CRLs;
}
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
TElOCSPResponseStorage* TElPKCS7SignedData::get_OCSPs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7SignedData_get_OCSPs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OCSPs)
		this->_Inst_OCSPs = new TElOCSPResponseStorage(hOutResult, ohFalse);
	else
		this->_Inst_OCSPs->updateHandle(hOutResult);
	return this->_Inst_OCSPs;
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */

void TElPKCS7SignedData::get_Content(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7SignedData_get_Content(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1871840345, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7SignedData::set_Content(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7SignedData_set_Content(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7SignedData::get_ContentType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7SignedData_get_ContentType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1155079208, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7SignedData::set_ContentType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7SignedData_set_ContentType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElPKCS7SignedData::get_ContentPartCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7SignedData_get_ContentPartCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
TElASN1DataSource* TElPKCS7SignedData::get_DataSource()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7SignedData_get_DataSource(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DataSource)
		this->_Inst_DataSource = new TElASN1DataSource(hOutResult, ohFalse);
	else
		this->_Inst_DataSource->updateHandle(hOutResult);
	return this->_Inst_DataSource;
}
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

void TElPKCS7SignedData::get_EncodedCertificates(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7SignedData_get_EncodedCertificates(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(952818581, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS7SignedData::get_EncodedCRLs(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7SignedData_get_EncodedCRLs(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1100026115, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS7SignedData::get_EnvelopedContentPrefix(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7SignedData_get_EnvelopedContentPrefix(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(205640544, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS7SignedData::get_EnvelopedContentPostfix(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7SignedData_get_EnvelopedContentPostfix(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-518172197, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElPKCS7SignedData::get_IsMultipart()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7SignedData_get_IsMultipart(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPKCS7SignedData::get_RawMultipartContent(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7SignedData_get_RawMultipartContent(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1168252339, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElPKCS7SignedData::get_PreserveCachedContent()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7SignedData_get_PreserveCachedContent(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS7SignedData::set_PreserveCachedContent(bool Value)
{
	SBCheckError(TElPKCS7SignedData_set_PreserveCachedContent(_Handle, (int8_t)Value));
}

bool TElPKCS7SignedData::get_PreserveCachedElements()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7SignedData_get_PreserveCachedElements(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS7SignedData::set_PreserveCachedElements(bool Value)
{
	SBCheckError(TElPKCS7SignedData_set_PreserveCachedElements(_Handle, (int8_t)Value));
}

void TElPKCS7SignedData::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS7SIGNER
	this->_Inst_Signers = NULL;
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	this->_Inst_ContentParts = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
	this->_Inst_CRLs = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
	this->_Inst_OCSPs = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	this->_Inst_DataSource = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
}

TElPKCS7SignedData::TElPKCS7SignedData(TElPKCS7SignedDataHandle handle, TElOwnHandle ownHandle) : TInterfacedPersistent(handle, ownHandle)
{
	initInstances();
}

TElPKCS7SignedData::TElPKCS7SignedData() : TInterfacedPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS7SignedData_Create(&_Handle));
}

TElPKCS7SignedData::~TElPKCS7SignedData()
{
#ifdef SB_USE_CLASS_TELPKCS7SIGNER
	delete this->_Inst_Signers;
	this->_Inst_Signers = NULL;
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	delete this->_Inst_ContentParts;
	this->_Inst_ContentParts = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
	delete this->_Inst_CRLs;
	this->_Inst_CRLs = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
	delete this->_Inst_OCSPs;
	this->_Inst_OCSPs = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	delete this->_Inst_DataSource;
	this->_Inst_DataSource = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
}
#endif /* SB_USE_CLASS_TELPKCS7SIGNEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7DIGESTEDDATA

void TElPKCS7DigestedData::get_DigestAlgorithm(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7DigestedData_get_DigestAlgorithm(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1762351362, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7DigestedData::set_DigestAlgorithm(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7DigestedData_set_DigestAlgorithm(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7DigestedData::get_DigestAlgorithmParams(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7DigestedData_get_DigestAlgorithmParams(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(432405899, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7DigestedData::set_DigestAlgorithmParams(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7DigestedData_set_DigestAlgorithmParams(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7DigestedData::get_Content(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7DigestedData_get_Content(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1237418607, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7DigestedData::set_Content(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7DigestedData_set_Content(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7DigestedData::get_Digest(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7DigestedData_get_Digest(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1258529587, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7DigestedData::set_Digest(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7DigestedData_set_Digest(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElPKCS7DigestedData::get_Version()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7DigestedData_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS7DigestedData::set_Version(int32_t Value)
{
	SBCheckError(TElPKCS7DigestedData_set_Version(_Handle, Value));
}

TElPKCS7DigestedData::TElPKCS7DigestedData(TElPKCS7DigestedDataHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPKCS7DigestedData::TElPKCS7DigestedData() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS7DigestedData_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPKCS7DIGESTEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDDATA

bool TElPKCS7EncryptedData::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7EncryptedData_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElPKCS7EncryptedData::get_Version()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7EncryptedData_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS7EncryptedData::set_Version(int32_t Value)
{
	SBCheckError(TElPKCS7EncryptedData_set_Version(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT
TElPKCS7EncryptedContent* TElPKCS7EncryptedData::get_EncryptedContent()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7EncryptedData_get_EncryptedContent(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptedContent)
		this->_Inst_EncryptedContent = new TElPKCS7EncryptedContent(hOutResult, ohFalse);
	else
		this->_Inst_EncryptedContent->updateHandle(hOutResult);
	return this->_Inst_EncryptedContent;
}
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT */

void TElPKCS7EncryptedData::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT
	this->_Inst_EncryptedContent = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT */
}

TElPKCS7EncryptedData::TElPKCS7EncryptedData(TElPKCS7EncryptedDataHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS7EncryptedData::TElPKCS7EncryptedData() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS7EncryptedData_Create(&_Handle));
}

TElPKCS7EncryptedData::~TElPKCS7EncryptedData()
{
#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT
	delete this->_Inst_EncryptedContent;
	this->_Inst_EncryptedContent = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT */
}
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7SIGNEDANDENVELOPEDDATA

#ifdef SB_USE_CLASS_TELPKCS7RECIPIENT
SB_INLINE TElPKCS7RecipientHandle TElPKCS7SignedAndEnvelopedData::GetRecipient(int32_t Index)
{
	TElPKCS7RecipientHandle OutResult;
	SBCheckError(TElPKCS7SignedAndEnvelopedData_GetRecipient(_Handle, Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS7RECIPIENT */

#ifdef SB_USE_CLASS_TELPKCS7SIGNER
SB_INLINE TElPKCS7SignerHandle TElPKCS7SignedAndEnvelopedData::GetSigner(int32_t Index)
{
	TElPKCS7SignerHandle OutResult;
	SBCheckError(TElPKCS7SignedAndEnvelopedData_GetSigner(_Handle, Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */

SB_INLINE int32_t TElPKCS7SignedAndEnvelopedData::AddRecipient()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7SignedAndEnvelopedData_AddRecipient(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS7SignedAndEnvelopedData::AddSigner()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7SignedAndEnvelopedData_AddSigner(_Handle, &OutResult));
	return OutResult;
}

bool TElPKCS7SignedAndEnvelopedData::RemoveRecipient(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7SignedAndEnvelopedData_RemoveRecipient(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS7SignedAndEnvelopedData::RemoveSigner(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7SignedAndEnvelopedData_RemoveSigner(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS7SignedAndEnvelopedData::PreSerialize(bool SerializeContent, bool SerializeCertsAndCrls)
{
	SBCheckError(TElPKCS7SignedAndEnvelopedData_PreSerialize(_Handle, (int8_t)SerializeContent, (int8_t)SerializeCertsAndCrls));
}

SB_INLINE int32_t TElPKCS7SignedAndEnvelopedData::get_Version()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7SignedAndEnvelopedData_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS7SignedAndEnvelopedData::set_Version(int32_t Value)
{
	SBCheckError(TElPKCS7SignedAndEnvelopedData_set_Version(_Handle, Value));
}

void TElPKCS7SignedAndEnvelopedData::get_ContentType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7SignedAndEnvelopedData_get_ContentType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1925714136, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7SignedAndEnvelopedData::set_ContentType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7SignedAndEnvelopedData_set_ContentType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELPKCS7RECIPIENT
TElPKCS7Recipient* TElPKCS7SignedAndEnvelopedData::get_Recipients(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7SignedAndEnvelopedData_get_Recipients(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Recipients)
		this->_Inst_Recipients = new TElPKCS7Recipient(hOutResult, ohFalse);
	else
		this->_Inst_Recipients->updateHandle(hOutResult);
	return this->_Inst_Recipients;
}
#endif /* SB_USE_CLASS_TELPKCS7RECIPIENT */

#ifdef SB_USE_CLASS_TELPKCS7SIGNER
TElPKCS7Signer* TElPKCS7SignedAndEnvelopedData::get_Signers(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7SignedAndEnvelopedData_get_Signers(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signers)
		this->_Inst_Signers = new TElPKCS7Signer(hOutResult, ohFalse);
	else
		this->_Inst_Signers->updateHandle(hOutResult);
	return this->_Inst_Signers;
}
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */

SB_INLINE int32_t TElPKCS7SignedAndEnvelopedData::get_RecipientCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7SignedAndEnvelopedData_get_RecipientCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT
TElPKCS7EncryptedContent* TElPKCS7SignedAndEnvelopedData::get_EncryptedContent()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7SignedAndEnvelopedData_get_EncryptedContent(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EncryptedContent)
		this->_Inst_EncryptedContent = new TElPKCS7EncryptedContent(hOutResult, ohFalse);
	else
		this->_Inst_EncryptedContent->updateHandle(hOutResult);
	return this->_Inst_EncryptedContent;
}
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT */

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
TElMemoryCertStorage* TElPKCS7SignedAndEnvelopedData::get_Certificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7SignedAndEnvelopedData_get_Certificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElMemoryCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
TElMemoryCRLStorage* TElPKCS7SignedAndEnvelopedData::get_CRLs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7SignedAndEnvelopedData_get_CRLs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CRLs)
		this->_Inst_CRLs = new TElMemoryCRLStorage(hOutResult, ohFalse);
	else
		this->_Inst_CRLs->updateHandle(hOutResult);
	return this->_Inst_CRLs;
}
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
TElOCSPResponseStorage* TElPKCS7SignedAndEnvelopedData::get_OCSPs()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7SignedAndEnvelopedData_get_OCSPs(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OCSPs)
		this->_Inst_OCSPs = new TElOCSPResponseStorage(hOutResult, ohFalse);
	else
		this->_Inst_OCSPs->updateHandle(hOutResult);
	return this->_Inst_OCSPs;
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */

void TElPKCS7SignedAndEnvelopedData::get_EncodedCertificates(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7SignedAndEnvelopedData_get_EncodedCertificates(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1525216375, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS7SignedAndEnvelopedData::get_EncodedCRLs(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7SignedAndEnvelopedData_get_EncodedCRLs(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2004884989, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS7SignedAndEnvelopedData::get_EnvelopedContentPrefix(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7SignedAndEnvelopedData_get_EnvelopedContentPrefix(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1613226655, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS7SignedAndEnvelopedData::get_EnvelopedContentPostfix(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7SignedAndEnvelopedData_get_EnvelopedContentPostfix(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-864823193, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElPKCS7SignedAndEnvelopedData::get_SignerCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7SignedAndEnvelopedData_get_SignerCount(_Handle, &OutResult));
	return OutResult;
}

bool TElPKCS7SignedAndEnvelopedData::get_PreserveCachedElements()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7SignedAndEnvelopedData_get_PreserveCachedElements(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS7SignedAndEnvelopedData::set_PreserveCachedElements(bool Value)
{
	SBCheckError(TElPKCS7SignedAndEnvelopedData_set_PreserveCachedElements(_Handle, (int8_t)Value));
}

void TElPKCS7SignedAndEnvelopedData::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS7RECIPIENT
	this->_Inst_Recipients = NULL;
#endif /* SB_USE_CLASS_TELPKCS7RECIPIENT */
#ifdef SB_USE_CLASS_TELPKCS7SIGNER
	this->_Inst_Signers = NULL;
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */
#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT
	this->_Inst_EncryptedContent = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT */
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
	this->_Inst_CRLs = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
	this->_Inst_OCSPs = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */
}

TElPKCS7SignedAndEnvelopedData::TElPKCS7SignedAndEnvelopedData(TElPKCS7SignedAndEnvelopedDataHandle handle, TElOwnHandle ownHandle) : TInterfacedPersistent(handle, ownHandle)
{
	initInstances();
}

TElPKCS7SignedAndEnvelopedData::TElPKCS7SignedAndEnvelopedData() : TInterfacedPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS7SignedAndEnvelopedData_Create(&_Handle));
}

TElPKCS7SignedAndEnvelopedData::~TElPKCS7SignedAndEnvelopedData()
{
#ifdef SB_USE_CLASS_TELPKCS7RECIPIENT
	delete this->_Inst_Recipients;
	this->_Inst_Recipients = NULL;
#endif /* SB_USE_CLASS_TELPKCS7RECIPIENT */
#ifdef SB_USE_CLASS_TELPKCS7SIGNER
	delete this->_Inst_Signers;
	this->_Inst_Signers = NULL;
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */
#ifdef SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT
	delete this->_Inst_EncryptedContent;
	this->_Inst_EncryptedContent = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ENCRYPTEDCONTENT */
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
	delete this->_Inst_CRLs;
	this->_Inst_CRLs = NULL;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
	delete this->_Inst_OCSPs;
	this->_Inst_OCSPs = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */
}
#endif /* SB_USE_CLASS_TELPKCS7SIGNEDANDENVELOPEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7AUTHENTICATEDDATA

SB_INLINE int32_t TElPKCS7AuthenticatedData::AddRecipient()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7AuthenticatedData_AddRecipient(_Handle, &OutResult));
	return OutResult;
}

bool TElPKCS7AuthenticatedData::RemoveRecipient(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7AuthenticatedData_RemoveRecipient(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS7AuthenticatedData::RecalculateAuthenticatedAttributes()
{
	SBCheckError(TElPKCS7AuthenticatedData_RecalculateAuthenticatedAttributes(_Handle));
}

SB_INLINE int32_t TElPKCS7AuthenticatedData::get_Version()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7AuthenticatedData_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS7AuthenticatedData::set_Version(int32_t Value)
{
	SBCheckError(TElPKCS7AuthenticatedData_set_Version(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElPKCS7AuthenticatedData::get_OriginatorCerts()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7AuthenticatedData_get_OriginatorCerts(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OriginatorCerts)
		this->_Inst_OriginatorCerts = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_OriginatorCerts->updateHandle(hOutResult);
	return this->_Inst_OriginatorCerts;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELPKCS7RECIPIENT
TElPKCS7Recipient* TElPKCS7AuthenticatedData::get_Recipients(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7AuthenticatedData_get_Recipients(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Recipients)
		this->_Inst_Recipients = new TElPKCS7Recipient(hOutResult, ohFalse);
	else
		this->_Inst_Recipients->updateHandle(hOutResult);
	return this->_Inst_Recipients;
}
#endif /* SB_USE_CLASS_TELPKCS7RECIPIENT */

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
TElASN1DataSource* TElPKCS7AuthenticatedData::get_ContentParts(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7AuthenticatedData_get_ContentParts(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ContentParts)
		this->_Inst_ContentParts = new TElASN1DataSource(hOutResult, ohFalse);
	else
		this->_Inst_ContentParts->updateHandle(hOutResult);
	return this->_Inst_ContentParts;
}
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

SB_INLINE int32_t TElPKCS7AuthenticatedData::get_RecipientCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7AuthenticatedData_get_RecipientCount(_Handle, &OutResult));
	return OutResult;
}

void TElPKCS7AuthenticatedData::get_MacAlgorithm(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7AuthenticatedData_get_MacAlgorithm(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(977574782, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7AuthenticatedData::set_MacAlgorithm(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7AuthenticatedData_set_MacAlgorithm(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7AuthenticatedData::get_DigestAlgorithm(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7AuthenticatedData_get_DigestAlgorithm(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1600598775, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7AuthenticatedData::set_DigestAlgorithm(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7AuthenticatedData_set_DigestAlgorithm(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7AuthenticatedData::get_ContentType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7AuthenticatedData_get_ContentType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1491973804, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7AuthenticatedData::set_ContentType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7AuthenticatedData_set_ContentType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7AuthenticatedData::get_Content(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7AuthenticatedData_get_Content(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1124675614, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7AuthenticatedData::set_Content(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7AuthenticatedData_set_Content(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
TElPKCS7Attributes* TElPKCS7AuthenticatedData::get_AuthenticatedAttributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7AuthenticatedData_get_AuthenticatedAttributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_AuthenticatedAttributes)
		this->_Inst_AuthenticatedAttributes = new TElPKCS7Attributes(hOutResult, ohFalse);
	else
		this->_Inst_AuthenticatedAttributes->updateHandle(hOutResult);
	return this->_Inst_AuthenticatedAttributes;
}
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
TElPKCS7Attributes* TElPKCS7AuthenticatedData::get_UnauthenticatedAttributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7AuthenticatedData_get_UnauthenticatedAttributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_UnauthenticatedAttributes)
		this->_Inst_UnauthenticatedAttributes = new TElPKCS7Attributes(hOutResult, ohFalse);
	else
		this->_Inst_UnauthenticatedAttributes->updateHandle(hOutResult);
	return this->_Inst_UnauthenticatedAttributes;
}
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

void TElPKCS7AuthenticatedData::get_Mac(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7AuthenticatedData_get_Mac(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1479276054, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7AuthenticatedData::set_Mac(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7AuthenticatedData_set_Mac(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7AuthenticatedData::get_AuthenticatedAttributesPlain(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7AuthenticatedData_get_AuthenticatedAttributesPlain(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1831563852, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElPKCS7AuthenticatedData::get_ContentPartCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7AuthenticatedData_get_ContentPartCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
TElASN1DataSource* TElPKCS7AuthenticatedData::get_DataSource()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7AuthenticatedData_get_DataSource(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DataSource)
		this->_Inst_DataSource = new TElASN1DataSource(hOutResult, ohFalse);
	else
		this->_Inst_DataSource->updateHandle(hOutResult);
	return this->_Inst_DataSource;
}
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

void TElPKCS7AuthenticatedData::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_OriginatorCerts = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELPKCS7RECIPIENT
	this->_Inst_Recipients = NULL;
#endif /* SB_USE_CLASS_TELPKCS7RECIPIENT */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	this->_Inst_ContentParts = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	this->_Inst_AuthenticatedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	this->_Inst_UnauthenticatedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	this->_Inst_DataSource = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
}

TElPKCS7AuthenticatedData::TElPKCS7AuthenticatedData(TElPKCS7AuthenticatedDataHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS7AuthenticatedData::TElPKCS7AuthenticatedData() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS7AuthenticatedData_Create(&_Handle));
}

TElPKCS7AuthenticatedData::~TElPKCS7AuthenticatedData()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_OriginatorCerts;
	this->_Inst_OriginatorCerts = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELPKCS7RECIPIENT
	delete this->_Inst_Recipients;
	this->_Inst_Recipients = NULL;
#endif /* SB_USE_CLASS_TELPKCS7RECIPIENT */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	delete this->_Inst_ContentParts;
	this->_Inst_ContentParts = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	delete this->_Inst_AuthenticatedAttributes;
	this->_Inst_AuthenticatedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
	delete this->_Inst_UnauthenticatedAttributes;
	this->_Inst_UnauthenticatedAttributes = NULL;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	delete this->_Inst_DataSource;
	this->_Inst_DataSource = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
}
#endif /* SB_USE_CLASS_TELPKCS7AUTHENTICATEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7TIMESTAMPANDCRL

SB_INLINE void TElPKCS7TimestampAndCRL::SetEncodedTimestamp(const std::vector<uint8_t> &V)
{
	SBCheckError(TElPKCS7TimestampAndCRL_SetEncodedTimestamp(_Handle, SB_STD_VECTOR_FRONT_ADR(V), (int32_t)V.size()));
}

SB_INLINE void TElPKCS7TimestampAndCRL::SetEncodedCRL(const std::vector<uint8_t> &V)
{
	SBCheckError(TElPKCS7TimestampAndCRL_SetEncodedCRL(_Handle, SB_STD_VECTOR_FRONT_ADR(V), (int32_t)V.size()));
}

SB_INLINE void TElPKCS7TimestampAndCRL::SetEncodedValue(const std::vector<uint8_t> &V)
{
	SBCheckError(TElPKCS7TimestampAndCRL_SetEncodedValue(_Handle, SB_STD_VECTOR_FRONT_ADR(V), (int32_t)V.size()));
}

void TElPKCS7TimestampAndCRL::get_EncodedTimestamp(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7TimestampAndCRL_get_EncodedTimestamp(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(581438128, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7TimestampAndCRL::set_EncodedTimestamp(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7TimestampAndCRL_set_EncodedTimestamp(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7TimestampAndCRL::get_EncodedCRL(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7TimestampAndCRL_get_EncodedCRL(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(67624050, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7TimestampAndCRL::set_EncodedCRL(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7TimestampAndCRL_set_EncodedCRL(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7TimestampAndCRL::get_EncodedValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7TimestampAndCRL_get_EncodedValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1892708171, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7TimestampAndCRL::set_EncodedValue(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7TimestampAndCRL_set_EncodedValue(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPKCS7TimestampAndCRL::TElPKCS7TimestampAndCRL(TElPKCS7TimestampAndCRLHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPKCS7TimestampAndCRL::TElPKCS7TimestampAndCRL() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS7TimestampAndCRL_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPKCS7TIMESTAMPANDCRL */

#ifdef SB_USE_CLASS_TELPKCS7TIMESTAMPEDDATA

SB_INLINE int32_t TElPKCS7TimestampedData::AddTimestamp()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7TimestampedData_AddTimestamp(_Handle, &OutResult));
	return OutResult;
}

bool TElPKCS7TimestampedData::RemoveTimestamp(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7TimestampedData_RemoveTimestamp(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS7TimestampedData::ClearTimestamps()
{
	SBCheckError(TElPKCS7TimestampedData_ClearTimestamps(_Handle));
}

void TElPKCS7TimestampedData::WriteMetadata(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7TimestampedData_WriteMetadata(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1489162919, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELPKCS7TIMESTAMPANDCRL
void TElPKCS7TimestampedData::WriteTimestampAndCRL(TElPKCS7TimestampAndCRL &Ts, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7TimestampedData_WriteTimestampAndCRL(_Handle, Ts.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1755923722, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS7TimestampedData::WriteTimestampAndCRL(TElPKCS7TimestampAndCRL *Ts, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7TimestampedData_WriteTimestampAndCRL(_Handle, (Ts != NULL) ? Ts->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1755923722, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELPKCS7TIMESTAMPANDCRL */

void TElPKCS7TimestampedData::get_DataURI(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7TimestampedData_get_DataURI(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1264689885, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7TimestampedData::set_DataURI(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7TimestampedData_set_DataURI(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElPKCS7TimestampedData::get_HashProtected()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7TimestampedData_get_HashProtected(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS7TimestampedData::set_HashProtected(bool Value)
{
	SBCheckError(TElPKCS7TimestampedData_set_HashProtected(_Handle, (int8_t)Value));
}

void TElPKCS7TimestampedData::get_FileName(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7TimestampedData_get_FileName(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1541832923, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7TimestampedData::set_FileName(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7TimestampedData_set_FileName(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPKCS7TimestampedData::get_MediaType(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7TimestampedData_get_MediaType(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1330708639, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7TimestampedData::set_MediaType(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7TimestampedData_set_MediaType(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElPKCS7TimestampedData::get_MetaDataAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS7TimestampedData_get_MetaDataAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPKCS7TimestampedData::set_MetaDataAvailable(bool Value)
{
	SBCheckError(TElPKCS7TimestampedData_set_MetaDataAvailable(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELPKCS7TIMESTAMPANDCRL
TElPKCS7TimestampAndCRL* TElPKCS7TimestampedData::get_Timestamps(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7TimestampedData_get_Timestamps(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Timestamps)
		this->_Inst_Timestamps = new TElPKCS7TimestampAndCRL(hOutResult, ohFalse);
	else
		this->_Inst_Timestamps->updateHandle(hOutResult);
	return this->_Inst_Timestamps;
}
#endif /* SB_USE_CLASS_TELPKCS7TIMESTAMPANDCRL */

SB_INLINE int32_t TElPKCS7TimestampedData::get_TimestampCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7TimestampedData_get_TimestampCount(_Handle, &OutResult));
	return OutResult;
}

void TElPKCS7TimestampedData::get_Content(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS7TimestampedData_get_Content(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(156564013, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS7TimestampedData::set_Content(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS7TimestampedData_set_Content(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
TElASN1DataSource* TElPKCS7TimestampedData::get_ContentParts(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7TimestampedData_get_ContentParts(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ContentParts)
		this->_Inst_ContentParts = new TElASN1DataSource(hOutResult, ohFalse);
	else
		this->_Inst_ContentParts->updateHandle(hOutResult);
	return this->_Inst_ContentParts;
}
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

SB_INLINE int32_t TElPKCS7TimestampedData::get_ContentPartCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS7TimestampedData_get_ContentPartCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
TElASN1DataSource* TElPKCS7TimestampedData::get_DataSource()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPKCS7TimestampedData_get_DataSource(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DataSource)
		this->_Inst_DataSource = new TElASN1DataSource(hOutResult, ohFalse);
	else
		this->_Inst_DataSource->updateHandle(hOutResult);
	return this->_Inst_DataSource;
}
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

void TElPKCS7TimestampedData::initInstances()
{
#ifdef SB_USE_CLASS_TELPKCS7TIMESTAMPANDCRL
	this->_Inst_Timestamps = NULL;
#endif /* SB_USE_CLASS_TELPKCS7TIMESTAMPANDCRL */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	this->_Inst_ContentParts = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	this->_Inst_DataSource = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
}

TElPKCS7TimestampedData::TElPKCS7TimestampedData(TElPKCS7TimestampedDataHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPKCS7TimestampedData::TElPKCS7TimestampedData() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPKCS7TimestampedData_Create(&_Handle));
}

TElPKCS7TimestampedData::~TElPKCS7TimestampedData()
{
#ifdef SB_USE_CLASS_TELPKCS7TIMESTAMPANDCRL
	delete this->_Inst_Timestamps;
	this->_Inst_Timestamps = NULL;
#endif /* SB_USE_CLASS_TELPKCS7TIMESTAMPANDCRL */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	delete this->_Inst_ContentParts;
	this->_Inst_ContentParts = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	delete this->_Inst_DataSource;
	this->_Inst_DataSource = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
}
#endif /* SB_USE_CLASS_TELPKCS7TIMESTAMPEDDATA */

#ifdef SB_USE_GLOBAL_PROCS_PKCS7

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
bool ProcessContentInfo(TElASN1ConstrainedTag &Tag, void * Buffer, int32_t &Size, std::vector<uint8_t> &ContentType)
{
	int32_t szContentType = (int32_t)ContentType.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBPKCS7_ProcessContentInfo(Tag.getHandle(), Buffer, &Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(ContentType), &szContentType, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ContentType.resize(szContentType);
		SBCheckError(SBGetLastReturnBuffer(605980541, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(ContentType), &szContentType));
	}
	else
		SBCheckError(_err);

	ContentType.resize(szContentType);
	return (OutResultRaw != 0);
}
bool ProcessContentInfo(TElASN1ConstrainedTag *Tag, void * Buffer, int32_t &Size, std::vector<uint8_t> &ContentType)
{
	int32_t szContentType = (int32_t)ContentType.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBPKCS7_ProcessContentInfo((Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, Buffer, &Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(ContentType), &szContentType, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ContentType.resize(szContentType);
		SBCheckError(SBGetLastReturnBuffer(605980541, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(ContentType), &szContentType));
	}
	else
		SBCheckError(_err);

	ContentType.resize(szContentType);
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASSES_TELASN1CONSTRAINEDTAG_AND_TOBJECT
bool ProcessContentInfo(TElASN1ConstrainedTag &Tag, TObject &PKCS7Data, std::vector<uint8_t> &ContentType)
{
	int32_t szContentType = (int32_t)ContentType.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBPKCS7_ProcessContentInfo_1(Tag.getHandle(), PKCS7Data.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(ContentType), &szContentType, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ContentType.resize(szContentType);
		SBCheckError(SBGetLastReturnBuffer(260148096, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(ContentType), &szContentType));
	}
	else
		SBCheckError(_err);

	ContentType.resize(szContentType);
	return (OutResultRaw != 0);
}
bool ProcessContentInfo(TElASN1ConstrainedTag *Tag, TObject *PKCS7Data, std::vector<uint8_t> &ContentType)
{
	int32_t szContentType = (int32_t)ContentType.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBPKCS7_ProcessContentInfo_1((Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, (PKCS7Data != NULL) ? PKCS7Data->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(ContentType), &szContentType, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ContentType.resize(szContentType);
		SBCheckError(SBGetLastReturnBuffer(260148096, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(ContentType), &szContentType));
	}
	else
		SBCheckError(_err);

	ContentType.resize(szContentType);
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELASN1CONSTRAINEDTAG_AND_TOBJECT */

#ifdef SB_USE_CLASSES_TELASN1CONSTRAINEDTAG_AND_TELPKCS7SIGNER
SB_INLINE void SaveSignerInfo(TElASN1ConstrainedTag &Tag, TElPKCS7Signer &Signer)
{
	SBCheckError(SBPKCS7_SaveSignerInfo(Tag.getHandle(), Signer.getHandle()));
}
SB_INLINE void SaveSignerInfo(TElASN1ConstrainedTag *Tag, TElPKCS7Signer *Signer)
{
	SBCheckError(SBPKCS7_SaveSignerInfo((Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, (Signer != NULL) ? Signer->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELASN1CONSTRAINEDTAG_AND_TELPKCS7SIGNER */

#ifdef SB_USE_CLASSES_TELASN1CUSTOMTAG_AND_TELPKCS7SIGNER
SB_INLINE int32_t ProcessSignerInfo(TElASN1CustomTag &Tag, TElPKCS7Signer &SignerInfo)
{
	int32_t OutResult;
	SBCheckError(SBPKCS7_ProcessSignerInfo(Tag.getHandle(), SignerInfo.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE int32_t ProcessSignerInfo(TElASN1CustomTag *Tag, TElPKCS7Signer *SignerInfo)
{
	int32_t OutResult;
	SBCheckError(SBPKCS7_ProcessSignerInfo((Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, (SignerInfo != NULL) ? SignerInfo->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELASN1CUSTOMTAG_AND_TELPKCS7SIGNER */

SB_INLINE void RaisePKCS7Error(int32_t ErrorCode)
{
	SBCheckError(SBPKCS7_RaisePKCS7Error(ErrorCode));
}

#endif /* SB_USE_GLOBAL_PROCS_PKCS7 */

};	/* namespace SecureBlackbox */

