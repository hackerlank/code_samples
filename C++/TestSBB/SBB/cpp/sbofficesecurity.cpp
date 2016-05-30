#include "sbofficesecurity.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLSTANDARDENCRYPTIONHANDLER

void TElOfficeOpenXMLStandardEncryptionHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLStandardEncryptionHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1494064363, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOfficeOpenXMLStandardEncryptionHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLStandardEncryptionHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1494064363, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeOpenXMLStandardEncryptionHandler::Reset()
{
	SBCheckError(TElOfficeOpenXMLStandardEncryptionHandler_Reset(_Handle));
}

bool TElOfficeOpenXMLStandardEncryptionHandler::IsPasswordValid()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLStandardEncryptionHandler_IsPasswordValid(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TClassHandle TElOfficeOpenXMLStandardEncryptionHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeOpenXMLStandardEncryptionHandler_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeOpenXMLStandardEncryptionHandler::get_EncryptionAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLStandardEncryptionHandler_get_EncryptionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeOpenXMLStandardEncryptionHandler::set_EncryptionAlgorithm(int32_t Value)
{
	SBCheckError(TElOfficeOpenXMLStandardEncryptionHandler_set_EncryptionAlgorithm(_Handle, Value));
}

void TElOfficeOpenXMLStandardEncryptionHandler::get_Password(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLStandardEncryptionHandler_get_Password(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1804785670, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLStandardEncryptionHandler::get_Password(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLStandardEncryptionHandler_get_Password(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1804785670, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeOpenXMLStandardEncryptionHandler::set_Password(const sb_u16string &Value)
{
	SBCheckError(TElOfficeOpenXMLStandardEncryptionHandler_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeOpenXMLStandardEncryptionHandler::set_Password(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeOpenXMLStandardEncryptionHandler_set_Password(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElOfficeOpenXMLStandardEncryptionHandler::TElOfficeOpenXMLStandardEncryptionHandler(TElOfficeOpenXMLStandardEncryptionHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLCustomEncryptionHandler(handle, ownHandle)
{
}

TElOfficeOpenXMLStandardEncryptionHandler::TElOfficeOpenXMLStandardEncryptionHandler(TComponent &Owner) : TElOfficeOpenXMLCustomEncryptionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLStandardEncryptionHandler_Create(Owner.getHandle(), &_Handle));
}

TElOfficeOpenXMLStandardEncryptionHandler::TElOfficeOpenXMLStandardEncryptionHandler(TComponent *Owner) : TElOfficeOpenXMLCustomEncryptionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLStandardEncryptionHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEOPENXMLSTANDARDENCRYPTIONHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLAGILEENCRYPTIONHANDLER

void TElOfficeOpenXMLAgileEncryptionHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLAgileEncryptionHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2008936263, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOfficeOpenXMLAgileEncryptionHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLAgileEncryptionHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2008936263, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeOpenXMLAgileEncryptionHandler::Reset()
{
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_Reset(_Handle));
}

SB_INLINE int32_t TElOfficeOpenXMLAgileEncryptionHandler::AddPasswordKeyEncryptor(const sb_u16string &Password)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_AddPasswordKeyEncryptor(_Handle, Password.data(), (int32_t)Password.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElOfficeOpenXMLAgileEncryptionHandler::AddPasswordKeyEncryptor(const std::wstring &Password)
{
	int32_t OutResult;
	std::string u16Password;
	sb_to_u16string(Password, u16Password);
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_AddPasswordKeyEncryptor(_Handle, reinterpret_cast<const sb_char16_t*>(u16Password.data()), (int32_t)u16Password.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLKEYENCRYPTOR
SB_INLINE int32_t TElOfficeOpenXMLAgileEncryptionHandler::AddKeyEncryptor(TElOfficeOpenXMLKeyEncryptor &KeyEncryptor)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_AddKeyEncryptor(_Handle, KeyEncryptor.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeOpenXMLAgileEncryptionHandler::AddKeyEncryptor(TElOfficeOpenXMLKeyEncryptor *KeyEncryptor)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_AddKeyEncryptor(_Handle, (KeyEncryptor != NULL) ? KeyEncryptor->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLKEYENCRYPTOR */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLKEYENCRYPTOR
SB_INLINE void TElOfficeOpenXMLAgileEncryptionHandler::InsertKeyEncryptor(int32_t Index, TElOfficeOpenXMLKeyEncryptor &KeyEncryptor)
{
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_InsertKeyEncryptor(_Handle, Index, KeyEncryptor.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLAgileEncryptionHandler::InsertKeyEncryptor(int32_t Index, TElOfficeOpenXMLKeyEncryptor *KeyEncryptor)
{
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_InsertKeyEncryptor(_Handle, Index, (KeyEncryptor != NULL) ? KeyEncryptor->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLKEYENCRYPTOR */

SB_INLINE void TElOfficeOpenXMLAgileEncryptionHandler::DeleteKeyEncryptor(int32_t Index)
{
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_DeleteKeyEncryptor(_Handle, Index));
}

SB_INLINE TClassHandle TElOfficeOpenXMLAgileEncryptionHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeOpenXMLAgileEncryptionHandler::get_KeyEncryptorCount()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_get_KeyEncryptorCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLKEYENCRYPTOR
TElOfficeOpenXMLKeyEncryptor* TElOfficeOpenXMLAgileEncryptionHandler::get_KeyEncryptors(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_get_KeyEncryptors(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyEncryptors)
		this->_Inst_KeyEncryptors = new TElOfficeOpenXMLKeyEncryptor(hOutResult, ohFalse);
	else
		this->_Inst_KeyEncryptors->updateHandle(hOutResult);
	return this->_Inst_KeyEncryptors;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLKEYENCRYPTOR */

SB_INLINE int32_t TElOfficeOpenXMLAgileEncryptionHandler::get_CipherAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_get_CipherAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeOpenXMLAgileEncryptionHandler::set_CipherAlgorithm(int32_t Value)
{
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_set_CipherAlgorithm(_Handle, Value));
}

TSBSymmetricCryptoMode TElOfficeOpenXMLAgileEncryptionHandler::get_CipherChaining()
{
	TSBSymmetricCryptoModeRaw OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_get_CipherChaining(_Handle, &OutResultRaw));
	return (TSBSymmetricCryptoMode)OutResultRaw;
}

SB_INLINE void TElOfficeOpenXMLAgileEncryptionHandler::set_CipherChaining(TSBSymmetricCryptoMode Value)
{
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_set_CipherChaining(_Handle, (TSBSymmetricCryptoModeRaw)Value));
}

SB_INLINE int32_t TElOfficeOpenXMLAgileEncryptionHandler::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeOpenXMLAgileEncryptionHandler::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_set_HashAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElOfficeOpenXMLAgileEncryptionHandler::get_SaltSize()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_get_SaltSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeOpenXMLAgileEncryptionHandler::set_SaltSize(int32_t Value)
{
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_set_SaltSize(_Handle, Value));
}

void TElOfficeOpenXMLAgileEncryptionHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLKEYENCRYPTOR
	this->_Inst_KeyEncryptors = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLKEYENCRYPTOR */
}

TElOfficeOpenXMLAgileEncryptionHandler::TElOfficeOpenXMLAgileEncryptionHandler(TElOfficeOpenXMLAgileEncryptionHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLCustomEncryptionHandler(handle, ownHandle)
{
	initInstances();
}

TElOfficeOpenXMLAgileEncryptionHandler::TElOfficeOpenXMLAgileEncryptionHandler(TComponent &Owner) : TElOfficeOpenXMLCustomEncryptionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_Create(Owner.getHandle(), &_Handle));
}

TElOfficeOpenXMLAgileEncryptionHandler::TElOfficeOpenXMLAgileEncryptionHandler(TComponent *Owner) : TElOfficeOpenXMLCustomEncryptionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXMLAgileEncryptionHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElOfficeOpenXMLAgileEncryptionHandler::~TElOfficeOpenXMLAgileEncryptionHandler()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLKEYENCRYPTOR
	delete this->_Inst_KeyEncryptors;
	this->_Inst_KeyEncryptors = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLKEYENCRYPTOR */
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLAGILEENCRYPTIONHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLKEYENCRYPTOR

TElOfficeOpenXMLKeyEncryptor::TElOfficeOpenXMLKeyEncryptor(TElOfficeOpenXMLKeyEncryptorHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElOfficeOpenXMLKeyEncryptor::TElOfficeOpenXMLKeyEncryptor() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLKeyEncryptor_Create(&_Handle));
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLAGILEENCRYPTIONHANDLER
TElOfficeOpenXMLKeyEncryptor::TElOfficeOpenXMLKeyEncryptor(TElOfficeOpenXMLAgileEncryptionHandler &Handler) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLKeyEncryptor_Create_1(Handler.getHandle(), &_Handle));
}

TElOfficeOpenXMLKeyEncryptor::TElOfficeOpenXMLKeyEncryptor(TElOfficeOpenXMLAgileEncryptionHandler *Handler) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLKeyEncryptor_Create_1((Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLAGILEENCRYPTIONHANDLER */

#endif /* SB_USE_CLASS_TELOFFICEOPENXMLKEYENCRYPTOR */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLPASSWORDKEYENCRYPTOR

bool TElOfficeOpenXMLPasswordKeyEncryptor::IsPasswordValid()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLPasswordKeyEncryptor_IsPasswordValid(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElOfficeOpenXMLPasswordKeyEncryptor::get_CipherAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLPasswordKeyEncryptor_get_CipherAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeOpenXMLPasswordKeyEncryptor::set_CipherAlgorithm(int32_t Value)
{
	SBCheckError(TElOfficeOpenXMLPasswordKeyEncryptor_set_CipherAlgorithm(_Handle, Value));
}

TSBSymmetricCryptoMode TElOfficeOpenXMLPasswordKeyEncryptor::get_CipherChaining()
{
	TSBSymmetricCryptoModeRaw OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLPasswordKeyEncryptor_get_CipherChaining(_Handle, &OutResultRaw));
	return (TSBSymmetricCryptoMode)OutResultRaw;
}

SB_INLINE void TElOfficeOpenXMLPasswordKeyEncryptor::set_CipherChaining(TSBSymmetricCryptoMode Value)
{
	SBCheckError(TElOfficeOpenXMLPasswordKeyEncryptor_set_CipherChaining(_Handle, (TSBSymmetricCryptoModeRaw)Value));
}

SB_INLINE int32_t TElOfficeOpenXMLPasswordKeyEncryptor::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLPasswordKeyEncryptor_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeOpenXMLPasswordKeyEncryptor::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElOfficeOpenXMLPasswordKeyEncryptor_set_HashAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElOfficeOpenXMLPasswordKeyEncryptor::get_SaltSize()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLPasswordKeyEncryptor_get_SaltSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeOpenXMLPasswordKeyEncryptor::set_SaltSize(int32_t Value)
{
	SBCheckError(TElOfficeOpenXMLPasswordKeyEncryptor_set_SaltSize(_Handle, Value));
}

SB_INLINE int32_t TElOfficeOpenXMLPasswordKeyEncryptor::get_SpinCount()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLPasswordKeyEncryptor_get_SpinCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeOpenXMLPasswordKeyEncryptor::set_SpinCount(int32_t Value)
{
	SBCheckError(TElOfficeOpenXMLPasswordKeyEncryptor_set_SpinCount(_Handle, Value));
}

void TElOfficeOpenXMLPasswordKeyEncryptor::get_Password(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLPasswordKeyEncryptor_get_Password(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(2129269646, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLPasswordKeyEncryptor::get_Password(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLPasswordKeyEncryptor_get_Password(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(2129269646, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeOpenXMLPasswordKeyEncryptor::set_Password(const sb_u16string &Value)
{
	SBCheckError(TElOfficeOpenXMLPasswordKeyEncryptor_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeOpenXMLPasswordKeyEncryptor::set_Password(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeOpenXMLPasswordKeyEncryptor_set_Password(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElOfficeOpenXMLPasswordKeyEncryptor::TElOfficeOpenXMLPasswordKeyEncryptor(TElOfficeOpenXMLPasswordKeyEncryptorHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLKeyEncryptor(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLAGILEENCRYPTIONHANDLER
TElOfficeOpenXMLPasswordKeyEncryptor::TElOfficeOpenXMLPasswordKeyEncryptor(TElOfficeOpenXMLAgileEncryptionHandler &Handler) : TElOfficeOpenXMLKeyEncryptor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLPasswordKeyEncryptor_Create(Handler.getHandle(), &_Handle));
}

TElOfficeOpenXMLPasswordKeyEncryptor::TElOfficeOpenXMLPasswordKeyEncryptor(TElOfficeOpenXMLAgileEncryptionHandler *Handler) : TElOfficeOpenXMLKeyEncryptor(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLPasswordKeyEncryptor_Create((Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLAGILEENCRYPTIONHANDLER */

#endif /* SB_USE_CLASS_TELOFFICEOPENXMLPASSWORDKEYENCRYPTOR */

#ifdef SB_USE_CLASS_TELOPENOFFICEENCRYPTIONHANDLER

void TElOpenOfficeEncryptionHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficeEncryptionHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-398570518, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOpenOfficeEncryptionHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficeEncryptionHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-398570518, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOpenOfficeEncryptionHandler::Reset()
{
	SBCheckError(TElOpenOfficeEncryptionHandler_Reset(_Handle));
}

bool TElOpenOfficeEncryptionHandler::IsPasswordValid()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOpenOfficeEncryptionHandler_IsPasswordValid(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TClassHandle TElOpenOfficeEncryptionHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOpenOfficeEncryptionHandler_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOpenOfficeEncryptionHandler::get_EncryptionAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElOpenOfficeEncryptionHandler_get_EncryptionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOpenOfficeEncryptionHandler::set_EncryptionAlgorithm(int32_t Value)
{
	SBCheckError(TElOpenOfficeEncryptionHandler_set_EncryptionAlgorithm(_Handle, Value));
}

void TElOpenOfficeEncryptionHandler::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficeEncryptionHandler_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(43415938, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOpenOfficeEncryptionHandler::set_Password(const std::string &Value)
{
	SBCheckError(TElOpenOfficeEncryptionHandler_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

TElOpenOfficeEncryptionHandler::TElOpenOfficeEncryptionHandler(TElOpenOfficeEncryptionHandlerHandle handle, TElOwnHandle ownHandle) : TElOpenOfficeCustomEncryptionHandler(handle, ownHandle)
{
}

TElOpenOfficeEncryptionHandler::TElOpenOfficeEncryptionHandler(TComponent &Owner) : TElOpenOfficeCustomEncryptionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOpenOfficeEncryptionHandler_Create(Owner.getHandle(), &_Handle));
}

TElOpenOfficeEncryptionHandler::TElOpenOfficeEncryptionHandler(TComponent *Owner) : TElOpenOfficeCustomEncryptionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOpenOfficeEncryptionHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELOPENOFFICEENCRYPTIONHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEBINARYRC4ENCRYPTIONHANDLER

void TElOfficeBinaryRC4EncryptionHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeBinaryRC4EncryptionHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1235806124, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOfficeBinaryRC4EncryptionHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeBinaryRC4EncryptionHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1235806124, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeBinaryRC4EncryptionHandler::Reset()
{
	SBCheckError(TElOfficeBinaryRC4EncryptionHandler_Reset(_Handle));
}

bool TElOfficeBinaryRC4EncryptionHandler::IsPasswordValid()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeBinaryRC4EncryptionHandler_IsPasswordValid(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TClassHandle TElOfficeBinaryRC4EncryptionHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeBinaryRC4EncryptionHandler_ClassType(&OutResult));
	return OutResult;
}

void TElOfficeBinaryRC4EncryptionHandler::get_Password(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeBinaryRC4EncryptionHandler_get_Password(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-922692190, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeBinaryRC4EncryptionHandler::get_Password(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeBinaryRC4EncryptionHandler_get_Password(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-922692190, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeBinaryRC4EncryptionHandler::set_Password(const sb_u16string &Value)
{
	SBCheckError(TElOfficeBinaryRC4EncryptionHandler_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeBinaryRC4EncryptionHandler::set_Password(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeBinaryRC4EncryptionHandler_set_Password(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElOfficeBinaryRC4EncryptionHandler::TElOfficeBinaryRC4EncryptionHandler(TElOfficeBinaryRC4EncryptionHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryCustomEncryptionHandler(handle, ownHandle)
{
}

TElOfficeBinaryRC4EncryptionHandler::TElOfficeBinaryRC4EncryptionHandler(TComponent &Owner) : TElOfficeBinaryCustomEncryptionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeBinaryRC4EncryptionHandler_Create(Owner.getHandle(), &_Handle));
}

TElOfficeBinaryRC4EncryptionHandler::TElOfficeBinaryRC4EncryptionHandler(TComponent *Owner) : TElOfficeBinaryCustomEncryptionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeBinaryRC4EncryptionHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEBINARYRC4ENCRYPTIONHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEBINARYRC4CRYPTOAPIENCRYPTIONHANDLER

void TElOfficeBinaryRC4CryptoAPIEncryptionHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeBinaryRC4CryptoAPIEncryptionHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2042272767, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOfficeBinaryRC4CryptoAPIEncryptionHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeBinaryRC4CryptoAPIEncryptionHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2042272767, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeBinaryRC4CryptoAPIEncryptionHandler::Reset()
{
	SBCheckError(TElOfficeBinaryRC4CryptoAPIEncryptionHandler_Reset(_Handle));
}

bool TElOfficeBinaryRC4CryptoAPIEncryptionHandler::IsPasswordValid()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeBinaryRC4CryptoAPIEncryptionHandler_IsPasswordValid(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TClassHandle TElOfficeBinaryRC4CryptoAPIEncryptionHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeBinaryRC4CryptoAPIEncryptionHandler_ClassType(&OutResult));
	return OutResult;
}

bool TElOfficeBinaryRC4CryptoAPIEncryptionHandler::get_EncryptDocumentProperties()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeBinaryRC4CryptoAPIEncryptionHandler_get_EncryptDocumentProperties(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOfficeBinaryRC4CryptoAPIEncryptionHandler::set_EncryptDocumentProperties(bool Value)
{
	SBCheckError(TElOfficeBinaryRC4CryptoAPIEncryptionHandler_set_EncryptDocumentProperties(_Handle, (int8_t)Value));
}

bool TElOfficeBinaryRC4CryptoAPIEncryptionHandler::get_HardenedKeyGeneration()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeBinaryRC4CryptoAPIEncryptionHandler_get_HardenedKeyGeneration(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOfficeBinaryRC4CryptoAPIEncryptionHandler::set_HardenedKeyGeneration(bool Value)
{
	SBCheckError(TElOfficeBinaryRC4CryptoAPIEncryptionHandler_set_HardenedKeyGeneration(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElOfficeBinaryRC4CryptoAPIEncryptionHandler::get_KeyLength()
{
	int32_t OutResult;
	SBCheckError(TElOfficeBinaryRC4CryptoAPIEncryptionHandler_get_KeyLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeBinaryRC4CryptoAPIEncryptionHandler::set_KeyLength(int32_t Value)
{
	SBCheckError(TElOfficeBinaryRC4CryptoAPIEncryptionHandler_set_KeyLength(_Handle, Value));
}

void TElOfficeBinaryRC4CryptoAPIEncryptionHandler::get_Password(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeBinaryRC4CryptoAPIEncryptionHandler_get_Password(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(483823878, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeBinaryRC4CryptoAPIEncryptionHandler::get_Password(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeBinaryRC4CryptoAPIEncryptionHandler_get_Password(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(483823878, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElOfficeBinaryRC4CryptoAPIEncryptionHandler::set_Password(const sb_u16string &Value)
{
	SBCheckError(TElOfficeBinaryRC4CryptoAPIEncryptionHandler_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElOfficeBinaryRC4CryptoAPIEncryptionHandler::set_Password(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElOfficeBinaryRC4CryptoAPIEncryptionHandler_set_Password(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElOfficeBinaryRC4CryptoAPIEncryptionHandler::TElOfficeBinaryRC4CryptoAPIEncryptionHandler(TElOfficeBinaryRC4CryptoAPIEncryptionHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryCustomEncryptionHandler(handle, ownHandle)
{
}

TElOfficeBinaryRC4CryptoAPIEncryptionHandler::TElOfficeBinaryRC4CryptoAPIEncryptionHandler(TComponent &Owner) : TElOfficeBinaryCustomEncryptionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeBinaryRC4CryptoAPIEncryptionHandler_Create(Owner.getHandle(), &_Handle));
}

TElOfficeBinaryRC4CryptoAPIEncryptionHandler::TElOfficeBinaryRC4CryptoAPIEncryptionHandler(TComponent *Owner) : TElOfficeBinaryCustomEncryptionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeBinaryRC4CryptoAPIEncryptionHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELOFFICEBINARYRC4CRYPTOAPIENCRYPTIONHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEBINARYCRYPTOAPISIGNATUREHANDLER

void TElOfficeBinaryCryptoAPISignatureHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeBinaryCryptoAPISignatureHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1671016153, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOfficeBinaryCryptoAPISignatureHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeBinaryCryptoAPISignatureHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1671016153, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeBinaryCryptoAPISignatureHandler::Reset()
{
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_Reset(_Handle));
}

SB_INLINE void TElOfficeBinaryCryptoAPISignatureHandler::Sign()
{
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_Sign(_Handle));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElOfficeBinaryCryptoAPISignatureHandler::Sign(TElX509Certificate &Cert)
{
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_Sign_1(_Handle, Cert.getHandle()));
}

SB_INLINE void TElOfficeBinaryCryptoAPISignatureHandler::Sign(TElX509Certificate *Cert)
{
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_Sign_1(_Handle, (Cert != NULL) ? Cert->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

TSBOfficeBinarySignatureValidationStatus TElOfficeBinaryCryptoAPISignatureHandler::Validate()
{
	TSBOfficeBinarySignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_Validate(_Handle, &OutResultRaw));
	return (TSBOfficeBinarySignatureValidationStatus)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
SB_INLINE TElDCAsyncStateHandle TElOfficeBinaryCryptoAPISignatureHandler::InitiateAsyncSign()
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_InitiateAsyncSign(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
SB_INLINE TElDCAsyncStateHandle TElOfficeBinaryCryptoAPISignatureHandler::InitiateAsyncSign(TElX509Certificate &Certificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_InitiateAsyncSign_1(_Handle, Certificate.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElOfficeBinaryCryptoAPISignatureHandler::InitiateAsyncSign(TElX509Certificate *Certificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_InitiateAsyncSign_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
SB_INLINE void TElOfficeBinaryCryptoAPISignatureHandler::CompleteAsyncSign(TElDCAsyncState &State)
{
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_CompleteAsyncSign(_Handle, State.getHandle()));
}

SB_INLINE void TElOfficeBinaryCryptoAPISignatureHandler::CompleteAsyncSign(TElDCAsyncState *State)
{
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_CompleteAsyncSign(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

SB_INLINE TClassHandle TElOfficeBinaryCryptoAPISignatureHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int64_t TElOfficeBinaryCryptoAPISignatureHandler::get_ExpireTime()
{
	int64_t OutResult;
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_get_ExpireTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeBinaryCryptoAPISignatureHandler::set_ExpireTime(int64_t Value)
{
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_set_ExpireTime(_Handle, Value));
}

SB_INLINE int64_t TElOfficeBinaryCryptoAPISignatureHandler::get_SignTime()
{
	int64_t OutResult;
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_get_SignTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeBinaryCryptoAPISignatureHandler::set_SignTime(int64_t Value)
{
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_set_SignTime(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElOfficeBinaryCryptoAPISignatureHandler::get_Certificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_get_Certificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificate)
		this->_Inst_Certificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_Certificate->updateHandle(hOutResult);
	return this->_Inst_Certificate;
}

SB_INLINE void TElOfficeBinaryCryptoAPISignatureHandler::set_Certificate(TElX509Certificate &Value)
{
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_set_Certificate(_Handle, Value.getHandle()));
}

SB_INLINE void TElOfficeBinaryCryptoAPISignatureHandler::set_Certificate(TElX509Certificate *Value)
{
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_set_Certificate(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElOfficeBinaryCryptoAPISignatureHandler::get_IntermediateCertificatesStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_get_IntermediateCertificatesStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_IntermediateCertificatesStorage)
		this->_Inst_IntermediateCertificatesStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_IntermediateCertificatesStorage->updateHandle(hOutResult);
	return this->_Inst_IntermediateCertificatesStorage;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

void TElOfficeBinaryCryptoAPISignatureHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_Certificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_IntermediateCertificatesStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElOfficeBinaryCryptoAPISignatureHandler::TElOfficeBinaryCryptoAPISignatureHandler(TElOfficeBinaryCryptoAPISignatureHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryCustomSignatureHandler(handle, ownHandle)
{
	initInstances();
}

TElOfficeBinaryCryptoAPISignatureHandler::TElOfficeBinaryCryptoAPISignatureHandler(TComponent &Owner) : TElOfficeBinaryCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_Create(Owner.getHandle(), &_Handle));
}

TElOfficeBinaryCryptoAPISignatureHandler::TElOfficeBinaryCryptoAPISignatureHandler(TComponent *Owner) : TElOfficeBinaryCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeBinaryCryptoAPISignatureHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElOfficeBinaryCryptoAPISignatureHandler::~TElOfficeBinaryCryptoAPISignatureHandler()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_Certificate;
	this->_Inst_Certificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_IntermediateCertificatesStorage;
	this->_Inst_IntermediateCertificatesStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELOFFICEBINARYCRYPTOAPISIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEBINARYSIGNEDENTRY

TElXMLDigestMethod TElOfficeBinarySignedEntry::get_DigestMethod()
{
	TElXMLDigestMethodRaw OutResultRaw = 0;
	SBCheckError(TElOfficeBinarySignedEntry_get_DigestMethod(_Handle, &OutResultRaw));
	return (TElXMLDigestMethod)OutResultRaw;
}

SB_INLINE void TElOfficeBinarySignedEntry::set_DigestMethod(TElXMLDigestMethod Value)
{
	SBCheckError(TElOfficeBinarySignedEntry_set_DigestMethod(_Handle, (TElXMLDigestMethodRaw)Value));
}

void TElOfficeBinarySignedEntry::get_DigestValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeBinarySignedEntry_get_DigestValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-919081504, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeBinarySignedEntry::set_DigestValue(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeBinarySignedEntry_set_DigestValue(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElOfficeBinarySignedEntry::get_Path(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeBinarySignedEntry_get_Path(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1153312967, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeBinarySignedEntry::get_Path(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeBinarySignedEntry_get_Path(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1153312967, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElOfficeBinarySignedEntry::get_ContentType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeBinarySignedEntry_get_ContentType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1284335338, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBOfficeBinaryEntryValidationStatus TElOfficeBinarySignedEntry::get_ValidationStatus()
{
	TSBOfficeBinaryEntryValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElOfficeBinarySignedEntry_get_ValidationStatus(_Handle, &OutResultRaw));
	return (TSBOfficeBinaryEntryValidationStatus)OutResultRaw;
}

TElOfficeBinarySignedEntry::TElOfficeBinarySignedEntry(TElOfficeBinarySignedEntryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELOFFICEBINARYCUSTOMSIGNATUREHANDLER
TElOfficeBinarySignedEntry::TElOfficeBinarySignedEntry(TElOfficeBinaryCustomSignatureHandler &Handler) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeBinarySignedEntry_Create(Handler.getHandle(), &_Handle));
}

TElOfficeBinarySignedEntry::TElOfficeBinarySignedEntry(TElOfficeBinaryCustomSignatureHandler *Handler) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeBinarySignedEntry_Create((Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELOFFICEBINARYCUSTOMSIGNATUREHANDLER */

#endif /* SB_USE_CLASS_TELOFFICEBINARYSIGNEDENTRY */

#ifdef SB_USE_CLASS_TELOFFICEBINARYXMLSIGNATUREHANDLER

void TElOfficeBinaryXMLSignatureHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeBinaryXMLSignatureHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(928968054, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOfficeBinaryXMLSignatureHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeBinaryXMLSignatureHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(928968054, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::Reset()
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_Reset(_Handle));
}

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::PrepareForSigning()
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_PrepareForSigning(_Handle));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElOfficeBinaryXMLSignatureHandler::Sign(TElX509Certificate &Certificate)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_Sign(_Handle, Certificate.getHandle()));
}

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::Sign(TElX509Certificate *Certificate)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_Sign(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElOfficeBinaryXMLSignatureHandler::Sign(TElX509Certificate &Certificate, bool EmbedCertificate)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_Sign_1(_Handle, Certificate.getHandle(), (int8_t)EmbedCertificate));
}

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::Sign(TElX509Certificate *Certificate, bool EmbedCertificate)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_Sign_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)EmbedCertificate));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElOfficeBinaryXMLSignatureHandler::Sign(TElCustomCertStorage &CertStorage)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_Sign_2(_Handle, CertStorage.getHandle()));
}

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::Sign(TElCustomCertStorage *CertStorage)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_Sign_2(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
SB_INLINE void TElOfficeBinaryXMLSignatureHandler::Sign(TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool EmbedKeyInSignature)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_Sign_3(_Handle, KeyData.getHandle(), (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)EmbedKeyInSignature));
}

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::Sign(TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool EmbedKeyInSignature)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_Sign_3(_Handle, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE, (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)EmbedKeyInSignature));
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

TSBOfficeBinarySignatureValidationStatus TElOfficeBinaryXMLSignatureHandler::Validate()
{
	TSBOfficeBinarySignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_Validate(_Handle, &OutResultRaw));
	return (TSBOfficeBinarySignatureValidationStatus)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TSBOfficeBinarySignatureValidationStatus TElOfficeBinaryXMLSignatureHandler::Validate(TElX509Certificate &Certificate)
{
	TSBOfficeBinarySignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_Validate_1(_Handle, Certificate.getHandle(), &OutResultRaw));
	return (TSBOfficeBinarySignatureValidationStatus)OutResultRaw;
}

TSBOfficeBinarySignatureValidationStatus TElOfficeBinaryXMLSignatureHandler::Validate(TElX509Certificate *Certificate)
{
	TSBOfficeBinarySignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_Validate_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBOfficeBinarySignatureValidationStatus)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
TSBOfficeBinarySignatureValidationStatus TElOfficeBinaryXMLSignatureHandler::Validate(TElXMLKeyInfoData &KeyData)
{
	TSBOfficeBinarySignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_Validate_2(_Handle, KeyData.getHandle(), &OutResultRaw));
	return (TSBOfficeBinarySignatureValidationStatus)OutResultRaw;
}

TSBOfficeBinarySignatureValidationStatus TElOfficeBinaryXMLSignatureHandler::Validate(TElXMLKeyInfoData *KeyData)
{
	TSBOfficeBinarySignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_Validate_2(_Handle, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBOfficeBinarySignatureValidationStatus)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElOfficeBinaryXMLSignatureHandler::GenerateXAdES(TSBXAdESForm XAdESForm, TElX509Certificate &SigningCertificate)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_GenerateXAdES(_Handle, (TSBXAdESFormRaw)XAdESForm, SigningCertificate.getHandle()));
}

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::GenerateXAdES(TSBXAdESForm XAdESForm, TElX509Certificate *SigningCertificate)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_GenerateXAdES(_Handle, (TSBXAdESFormRaw)XAdESForm, (SigningCertificate != NULL) ? SigningCertificate->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElOfficeBinaryXMLSignatureHandler::GenerateXAdES(TSBXAdESForm XAdESForm, TElX509Certificate &SigningCertificate, TElCustomTSPClient &TSPClient)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_GenerateXAdES_1(_Handle, (TSBXAdESFormRaw)XAdESForm, SigningCertificate.getHandle(), TSPClient.getHandle()));
}

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::GenerateXAdES(TSBXAdESForm XAdESForm, TElX509Certificate *SigningCertificate, TElCustomTSPClient *TSPClient)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_GenerateXAdES_1(_Handle, (TSBXAdESFormRaw)XAdESForm, (SigningCertificate != NULL) ? SigningCertificate->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
SB_INLINE TElDCAsyncStateHandle TElOfficeBinaryXMLSignatureHandler::InitiateAsyncSign()
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_InitiateAsyncSign(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
SB_INLINE TElDCAsyncStateHandle TElOfficeBinaryXMLSignatureHandler::InitiateAsyncSign(TElX509Certificate &Certificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_InitiateAsyncSign_1(_Handle, Certificate.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElOfficeBinaryXMLSignatureHandler::InitiateAsyncSign(TElX509Certificate *Certificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_InitiateAsyncSign_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
SB_INLINE TElDCAsyncStateHandle TElOfficeBinaryXMLSignatureHandler::InitiateAsyncSign(TElX509Certificate &Certificate, bool EmbedCertificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_InitiateAsyncSign_2(_Handle, Certificate.getHandle(), (int8_t)EmbedCertificate, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElOfficeBinaryXMLSignatureHandler::InitiateAsyncSign(TElX509Certificate *Certificate, bool EmbedCertificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_InitiateAsyncSign_2(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)EmbedCertificate, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE
SB_INLINE TElDCAsyncStateHandle TElOfficeBinaryXMLSignatureHandler::InitiateAsyncSign(TElCustomCertStorage &CertStorage)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_InitiateAsyncSign_3(_Handle, CertStorage.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElOfficeBinaryXMLSignatureHandler::InitiateAsyncSign(TElCustomCertStorage *CertStorage)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_InitiateAsyncSign_3(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLKEYINFODATA
SB_INLINE TElDCAsyncStateHandle TElOfficeBinaryXMLSignatureHandler::InitiateAsyncSign(TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool EmbedKeyInSignature)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_InitiateAsyncSign_4(_Handle, KeyData.getHandle(), (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)EmbedKeyInSignature, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElOfficeBinaryXMLSignatureHandler::InitiateAsyncSign(TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool EmbedKeyInSignature)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_InitiateAsyncSign_4(_Handle, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE, (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)EmbedKeyInSignature, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
SB_INLINE void TElOfficeBinaryXMLSignatureHandler::CompleteAsyncSign(TElDCAsyncState &State)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_CompleteAsyncSign(_Handle, State.getHandle()));
}

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::CompleteAsyncSign(TElDCAsyncState *State)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_CompleteAsyncSign(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
SB_INLINE void TElOfficeBinaryXMLSignatureHandler::CompleteAsyncSign(TElDCAsyncState &State, TElX509Certificate &Certificate, bool EmbedCertificate)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_CompleteAsyncSign_1(_Handle, State.getHandle(), Certificate.getHandle(), (int8_t)EmbedCertificate));
}

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::CompleteAsyncSign(TElDCAsyncState *State, TElX509Certificate *Certificate, bool EmbedCertificate)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_CompleteAsyncSign_1(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)EmbedCertificate));
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::UpdateSignature()
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_UpdateSignature(_Handle));
}

SB_INLINE TClassHandle TElOfficeBinaryXMLSignatureHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_ClassType(&OutResult));
	return OutResult;
}

TElXMLDigestMethod TElOfficeBinaryXMLSignatureHandler::get_DigestMethod()
{
	TElXMLDigestMethodRaw OutResultRaw = 0;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_get_DigestMethod(_Handle, &OutResultRaw));
	return (TElXMLDigestMethod)OutResultRaw;
}

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::set_DigestMethod(TElXMLDigestMethod Value)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_set_DigestMethod(_Handle, (TElXMLDigestMethodRaw)Value));
}

SB_INLINE int32_t TElOfficeBinaryXMLSignatureHandler::get_SignedEntryCount()
{
	int32_t OutResult;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_get_SignedEntryCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICEBINARYSIGNEDENTRY
TElOfficeBinarySignedEntry* TElOfficeBinaryXMLSignatureHandler::get_SignedEntries(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_get_SignedEntries(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignedEntries)
		this->_Inst_SignedEntries = new TElOfficeBinarySignedEntry(hOutResult, ohFalse);
	else
		this->_Inst_SignedEntries->updateHandle(hOutResult);
	return this->_Inst_SignedEntries;
}
#endif /* SB_USE_CLASS_TELOFFICEBINARYSIGNEDENTRY */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElOfficeBinaryXMLSignatureHandler::get_Certificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_get_Certificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElOfficeBinaryXMLSignatureHandler::get_SignerCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_get_SignerCertificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignerCertificate)
		this->_Inst_SignerCertificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_SignerCertificate->updateHandle(hOutResult);
	return this->_Inst_SignerCertificate;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
TElXMLKeyInfoData* TElOfficeBinaryXMLSignatureHandler::get_SignerKeyData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_get_SignerKeyData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignerKeyData)
		this->_Inst_SignerKeyData = new TElXMLKeyInfoData(hOutResult, ohFalse);
	else
		this->_Inst_SignerKeyData->updateHandle(hOutResult);
	return this->_Inst_SignerKeyData;
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATURETIME
TElOfficeXMLSignatureTime* TElOfficeBinaryXMLSignatureHandler::get_SignatureTime()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_get_SignatureTime(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureTime)
		this->_Inst_SignatureTime = new TElOfficeXMLSignatureTime(hOutResult, ohFalse);
	else
		this->_Inst_SignatureTime->updateHandle(hOutResult);
	return this->_Inst_SignatureTime;
}
#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATURETIME */

#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATUREINFOV1
TElOfficeXMLSignatureInfoV1* TElOfficeBinaryXMLSignatureHandler::get_SignatureInfoV1()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_get_SignatureInfoV1(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureInfoV1)
		this->_Inst_SignatureInfoV1 = new TElOfficeXMLSignatureInfoV1(hOutResult, ohFalse);
	else
		this->_Inst_SignatureInfoV1->updateHandle(hOutResult);
	return this->_Inst_SignatureInfoV1;
}
#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATUREINFOV1 */

#ifdef SB_USE_CLASS_TELXADESPROCESSOR
TElXAdESProcessor* TElOfficeBinaryXMLSignatureHandler::get_XAdESProcessor()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_get_XAdESProcessor(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_XAdESProcessor)
		this->_Inst_XAdESProcessor = new TElXAdESProcessor(hOutResult, ohFalse);
	else
		this->_Inst_XAdESProcessor->updateHandle(hOutResult);
	return this->_Inst_XAdESProcessor;
}

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::set_XAdESProcessor(TElXAdESProcessor &Value)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_set_XAdESProcessor(_Handle, Value.getHandle()));
}

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::set_XAdESProcessor(TElXAdESProcessor *Value)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_set_XAdESProcessor(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXADESPROCESSOR */

bool TElOfficeBinaryXMLSignatureHandler::get_OwnXAdESProcessor()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_get_OwnXAdESProcessor(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::set_OwnXAdESProcessor(bool Value)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_set_OwnXAdESProcessor(_Handle, (int8_t)Value));
}

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::get_OnPrepareSignature(TSBOfficeXMLSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_get_OnPrepareSignature(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::set_OnPrepareSignature(TSBOfficeXMLSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_set_OnPrepareSignature(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::get_OnBeforeSign(TSBOfficeXMLSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_get_OnBeforeSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::set_OnBeforeSign(TSBOfficeXMLSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_set_OnBeforeSign(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::get_OnAfterSign(TSBOfficeXMLSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_get_OnAfterSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOfficeBinaryXMLSignatureHandler::set_OnAfterSign(TSBOfficeXMLSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_set_OnAfterSign(_Handle, pMethodValue, pDataValue));
}

void TElOfficeBinaryXMLSignatureHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEBINARYSIGNEDENTRY
	this->_Inst_SignedEntries = NULL;
#endif /* SB_USE_CLASS_TELOFFICEBINARYSIGNEDENTRY */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_SignerCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
	this->_Inst_SignerKeyData = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATURETIME
	this->_Inst_SignatureTime = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATURETIME */
#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATUREINFOV1
	this->_Inst_SignatureInfoV1 = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATUREINFOV1 */
#ifdef SB_USE_CLASS_TELXADESPROCESSOR
	this->_Inst_XAdESProcessor = NULL;
#endif /* SB_USE_CLASS_TELXADESPROCESSOR */
}

TElOfficeBinaryXMLSignatureHandler::TElOfficeBinaryXMLSignatureHandler(TElOfficeBinaryXMLSignatureHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeBinaryCustomSignatureHandler(handle, ownHandle)
{
	initInstances();
}

TElOfficeBinaryXMLSignatureHandler::TElOfficeBinaryXMLSignatureHandler(TComponent &Owner) : TElOfficeBinaryCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_Create(Owner.getHandle(), &_Handle));
}

TElOfficeBinaryXMLSignatureHandler::TElOfficeBinaryXMLSignatureHandler(TComponent *Owner) : TElOfficeBinaryCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeBinaryXMLSignatureHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElOfficeBinaryXMLSignatureHandler::~TElOfficeBinaryXMLSignatureHandler()
{
#ifdef SB_USE_CLASS_TELOFFICEBINARYSIGNEDENTRY
	delete this->_Inst_SignedEntries;
	this->_Inst_SignedEntries = NULL;
#endif /* SB_USE_CLASS_TELOFFICEBINARYSIGNEDENTRY */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_SignerCertificate;
	this->_Inst_SignerCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
	delete this->_Inst_SignerKeyData;
	this->_Inst_SignerKeyData = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATURETIME
	delete this->_Inst_SignatureTime;
	this->_Inst_SignatureTime = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATURETIME */
#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATUREINFOV1
	delete this->_Inst_SignatureInfoV1;
	this->_Inst_SignatureInfoV1 = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATUREINFOV1 */
#ifdef SB_USE_CLASS_TELXADESPROCESSOR
	delete this->_Inst_XAdESProcessor;
	this->_Inst_XAdESProcessor = NULL;
#endif /* SB_USE_CLASS_TELXADESPROCESSOR */
}
#endif /* SB_USE_CLASS_TELOFFICEBINARYXMLSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLSIGNEDPART

TElXMLCanonicalizationMethod TElOfficeOpenXMLSignedPart::get_CanonicalizationMethod()
{
	TElXMLCanonicalizationMethodRaw OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLSignedPart_get_CanonicalizationMethod(_Handle, &OutResultRaw));
	return (TElXMLCanonicalizationMethod)OutResultRaw;
}

SB_INLINE void TElOfficeOpenXMLSignedPart::set_CanonicalizationMethod(TElXMLCanonicalizationMethod Value)
{
	SBCheckError(TElOfficeOpenXMLSignedPart_set_CanonicalizationMethod(_Handle, (TElXMLCanonicalizationMethodRaw)Value));
}

TElXMLDigestMethod TElOfficeOpenXMLSignedPart::get_DigestMethod()
{
	TElXMLDigestMethodRaw OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLSignedPart_get_DigestMethod(_Handle, &OutResultRaw));
	return (TElXMLDigestMethod)OutResultRaw;
}

SB_INLINE void TElOfficeOpenXMLSignedPart::set_DigestMethod(TElXMLDigestMethod Value)
{
	SBCheckError(TElOfficeOpenXMLSignedPart_set_DigestMethod(_Handle, (TElXMLDigestMethodRaw)Value));
}

void TElOfficeOpenXMLSignedPart::get_DigestValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOfficeOpenXMLSignedPart_get_DigestValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1311258421, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeOpenXMLSignedPart::set_DigestValue(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOfficeOpenXMLSignedPart_set_DigestValue(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElOfficeOpenXMLSignedPart::get_URI(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLSignedPart_get_URI(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1513216999, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOfficeOpenXMLSignedPart::get_ContentType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLSignedPart_get_ContentType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(879576001, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElOfficeOpenXMLSignedPart::get_IsRelationshipPart()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLSignedPart_get_IsRelationshipPart(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TSBOfficeOpenXMLPartValidationStatus TElOfficeOpenXMLSignedPart::get_ValidationStatus()
{
	TSBOfficeOpenXMLPartValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLSignedPart_get_ValidationStatus(_Handle, &OutResultRaw));
	return (TSBOfficeOpenXMLPartValidationStatus)OutResultRaw;
}

TElOfficeOpenXMLSignedPart::TElOfficeOpenXMLSignedPart(TElOfficeOpenXMLSignedPartHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER
TElOfficeOpenXMLSignedPart::TElOfficeOpenXMLSignedPart(TElOfficeOpenXMLCustomSignatureHandler &Handler) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLSignedPart_Create(Handler.getHandle(), &_Handle));
}

TElOfficeOpenXMLSignedPart::TElOfficeOpenXMLSignedPart(TElOfficeOpenXMLCustomSignatureHandler *Handler) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLSignedPart_Create((Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER
TElOfficeOpenXMLSignedPart::TElOfficeOpenXMLSignedPart(TElOfficeOpenXMLCustomSignatureHandler &Handler, const std::string &AURI, const std::string &AContentType) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLSignedPart_Create_1(Handler.getHandle(), AURI.data(), (int32_t)AURI.length(), AContentType.data(), (int32_t)AContentType.length(), &_Handle));
}

TElOfficeOpenXMLSignedPart::TElOfficeOpenXMLSignedPart(TElOfficeOpenXMLCustomSignatureHandler *Handler, const std::string &AURI, const std::string &AContentType) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLSignedPart_Create_1((Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, AURI.data(), (int32_t)AURI.length(), AContentType.data(), (int32_t)AContentType.length(), &_Handle));
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER */

#endif /* SB_USE_CLASS_TELOFFICEOPENXMLSIGNEDPART */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLSIGNEDRELATIONSHIPPART

SB_INLINE int32_t TElOfficeOpenXMLSignedRelationshipPart::AddSourceId(const sb_u16string &SourceId)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLSignedRelationshipPart_AddSourceId(_Handle, SourceId.data(), (int32_t)SourceId.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElOfficeOpenXMLSignedRelationshipPart::AddSourceId(const std::wstring &SourceId)
{
	int32_t OutResult;
	std::string u16SourceId;
	sb_to_u16string(SourceId, u16SourceId);
	SBCheckError(TElOfficeOpenXMLSignedRelationshipPart_AddSourceId(_Handle, reinterpret_cast<const sb_char16_t*>(u16SourceId.data()), (int32_t)u16SourceId.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElOfficeOpenXMLSignedRelationshipPart::AddSourceType(const sb_u16string &SourceType)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLSignedRelationshipPart_AddSourceType(_Handle, SourceType.data(), (int32_t)SourceType.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE int32_t TElOfficeOpenXMLSignedRelationshipPart::AddSourceType(const std::wstring &SourceType)
{
	int32_t OutResult;
	std::string u16SourceType;
	sb_to_u16string(SourceType, u16SourceType);
	SBCheckError(TElOfficeOpenXMLSignedRelationshipPart_AddSourceType(_Handle, reinterpret_cast<const sb_char16_t*>(u16SourceType.data()), (int32_t)u16SourceType.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElOfficeOpenXMLSignedRelationshipPart::DeleteSourceId(int32_t Index)
{
	SBCheckError(TElOfficeOpenXMLSignedRelationshipPart_DeleteSourceId(_Handle, Index));
}

SB_INLINE void TElOfficeOpenXMLSignedRelationshipPart::DeleteSourceType(int32_t Index)
{
	SBCheckError(TElOfficeOpenXMLSignedRelationshipPart_DeleteSourceType(_Handle, Index));
}

bool TElOfficeOpenXMLSignedRelationshipPart::HasSourceId(const sb_u16string &SourceId)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLSignedRelationshipPart_HasSourceId(_Handle, SourceId.data(), (int32_t)SourceId.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElOfficeOpenXMLSignedRelationshipPart::HasSourceId(const std::wstring &SourceId)
{
	std::string u16SourceId;
	sb_to_u16string(SourceId, u16SourceId);
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLSignedRelationshipPart_HasSourceId(_Handle, reinterpret_cast<const sb_char16_t*>(u16SourceId.data()), (int32_t)u16SourceId.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

bool TElOfficeOpenXMLSignedRelationshipPart::HasSourceType(const sb_u16string &SourceType)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLSignedRelationshipPart_HasSourceType(_Handle, SourceType.data(), (int32_t)SourceType.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElOfficeOpenXMLSignedRelationshipPart::HasSourceType(const std::wstring &SourceType)
{
	std::string u16SourceType;
	sb_to_u16string(SourceType, u16SourceType);
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLSignedRelationshipPart_HasSourceType(_Handle, reinterpret_cast<const sb_char16_t*>(u16SourceType.data()), (int32_t)u16SourceType.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

void TElOfficeOpenXMLSignedRelationshipPart::get_SourceIds(int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLSignedRelationshipPart_get_SourceIds(_Handle, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-550483727, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLSignedRelationshipPart::get_SourceIds(int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLSignedRelationshipPart_get_SourceIds(_Handle, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-550483727, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElOfficeOpenXMLSignedRelationshipPart::get_SourceTypes(int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLSignedRelationshipPart_get_SourceTypes(_Handle, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-808854427, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElOfficeOpenXMLSignedRelationshipPart::get_SourceTypes(int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElOfficeOpenXMLSignedRelationshipPart_get_SourceTypes(_Handle, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-808854427, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE int32_t TElOfficeOpenXMLSignedRelationshipPart::get_SourceTypeCount()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLSignedRelationshipPart_get_SourceTypeCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeOpenXMLSignedRelationshipPart::get_SourceIdCount()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLSignedRelationshipPart_get_SourceIdCount(_Handle, &OutResult));
	return OutResult;
}

void TElOfficeOpenXMLSignedRelationshipPart::get_PartURI(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLSignedRelationshipPart_get_PartURI(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1825366453, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElOfficeOpenXMLSignedRelationshipPart::TElOfficeOpenXMLSignedRelationshipPart(TElOfficeOpenXMLSignedRelationshipPartHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLSignedPart(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER
TElOfficeOpenXMLSignedRelationshipPart::TElOfficeOpenXMLSignedRelationshipPart(TElOfficeOpenXMLCustomSignatureHandler &Handler) : TElOfficeOpenXMLSignedPart(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLSignedRelationshipPart_Create(Handler.getHandle(), &_Handle));
}

TElOfficeOpenXMLSignedRelationshipPart::TElOfficeOpenXMLSignedRelationshipPart(TElOfficeOpenXMLCustomSignatureHandler *Handler) : TElOfficeOpenXMLSignedPart(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLSignedRelationshipPart_Create((Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER
TElOfficeOpenXMLSignedRelationshipPart::TElOfficeOpenXMLSignedRelationshipPart(TElOfficeOpenXMLCustomSignatureHandler &Handler, const std::string &AURI, const std::string &AContentType, const std::string &APartURI) : TElOfficeOpenXMLSignedPart(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLSignedRelationshipPart_Create_1(Handler.getHandle(), AURI.data(), (int32_t)AURI.length(), AContentType.data(), (int32_t)AContentType.length(), APartURI.data(), (int32_t)APartURI.length(), &_Handle));
}

TElOfficeOpenXMLSignedRelationshipPart::TElOfficeOpenXMLSignedRelationshipPart(TElOfficeOpenXMLCustomSignatureHandler *Handler, const std::string &AURI, const std::string &AContentType, const std::string &APartURI) : TElOfficeOpenXMLSignedPart(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOfficeOpenXMLSignedRelationshipPart_Create_1((Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, AURI.data(), (int32_t)AURI.length(), AContentType.data(), (int32_t)AContentType.length(), APartURI.data(), (int32_t)APartURI.length(), &_Handle));
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCUSTOMSIGNATUREHANDLER */

#endif /* SB_USE_CLASS_TELOFFICEOPENXMLSIGNEDRELATIONSHIPPART */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLBASESIGNATUREHANDLER

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::Reset()
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::Sign(TElX509Certificate &Certificate)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_Sign(_Handle, Certificate.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::Sign(TElX509Certificate *Certificate)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_Sign(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::Sign(TElX509Certificate &Certificate, TSBOfficeOpenXMLEmbedCertificate EmbedCertificate)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_Sign_1(_Handle, Certificate.getHandle(), (TSBOfficeOpenXMLEmbedCertificateRaw)EmbedCertificate));
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::Sign(TElX509Certificate *Certificate, TSBOfficeOpenXMLEmbedCertificate EmbedCertificate)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_Sign_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (TSBOfficeOpenXMLEmbedCertificateRaw)EmbedCertificate));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::Sign(TElCustomCertStorage &CertStorage)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_Sign_2(_Handle, CertStorage.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::Sign(TElCustomCertStorage *CertStorage)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_Sign_2(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::Sign(TElCustomCertStorage &CertStorage, TSBOfficeOpenXMLEmbedCertificate EmbedCertificate)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_Sign_3(_Handle, CertStorage.getHandle(), (TSBOfficeOpenXMLEmbedCertificateRaw)EmbedCertificate));
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::Sign(TElCustomCertStorage *CertStorage, TSBOfficeOpenXMLEmbedCertificate EmbedCertificate)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_Sign_3(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (TSBOfficeOpenXMLEmbedCertificateRaw)EmbedCertificate));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::Sign(TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool EmbedKeyInSignature)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_Sign_4(_Handle, KeyData.getHandle(), (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)EmbedKeyInSignature));
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::Sign(TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool EmbedKeyInSignature)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_Sign_4(_Handle, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE, (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)EmbedKeyInSignature));
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

TSBOfficeOpenXMLSignatureValidationStatus TElOfficeOpenXMLBaseSignatureHandler::Validate()
{
	TSBOfficeOpenXMLSignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_Validate(_Handle, &OutResultRaw));
	return (TSBOfficeOpenXMLSignatureValidationStatus)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TSBOfficeOpenXMLSignatureValidationStatus TElOfficeOpenXMLBaseSignatureHandler::Validate(TElX509Certificate &Certificate)
{
	TSBOfficeOpenXMLSignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_Validate_1(_Handle, Certificate.getHandle(), &OutResultRaw));
	return (TSBOfficeOpenXMLSignatureValidationStatus)OutResultRaw;
}

TSBOfficeOpenXMLSignatureValidationStatus TElOfficeOpenXMLBaseSignatureHandler::Validate(TElX509Certificate *Certificate)
{
	TSBOfficeOpenXMLSignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_Validate_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBOfficeOpenXMLSignatureValidationStatus)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
TSBOfficeOpenXMLSignatureValidationStatus TElOfficeOpenXMLBaseSignatureHandler::Validate(TElXMLKeyInfoData &KeyData)
{
	TSBOfficeOpenXMLSignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_Validate_2(_Handle, KeyData.getHandle(), &OutResultRaw));
	return (TSBOfficeOpenXMLSignatureValidationStatus)OutResultRaw;
}

TSBOfficeOpenXMLSignatureValidationStatus TElOfficeOpenXMLBaseSignatureHandler::Validate(TElXMLKeyInfoData *KeyData)
{
	TSBOfficeOpenXMLSignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_Validate_2(_Handle, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBOfficeOpenXMLSignatureValidationStatus)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::GenerateXAdES(TSBXAdESForm XAdESForm, TElX509Certificate &SigningCertificate)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_GenerateXAdES(_Handle, (TSBXAdESFormRaw)XAdESForm, SigningCertificate.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::GenerateXAdES(TSBXAdESForm XAdESForm, TElX509Certificate *SigningCertificate)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_GenerateXAdES(_Handle, (TSBXAdESFormRaw)XAdESForm, (SigningCertificate != NULL) ? SigningCertificate->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::GenerateXAdES(TSBXAdESForm XAdESForm, TElX509Certificate &SigningCertificate, TElCustomTSPClient &TSPClient)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_GenerateXAdES_1(_Handle, (TSBXAdESFormRaw)XAdESForm, SigningCertificate.getHandle(), TSPClient.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::GenerateXAdES(TSBXAdESForm XAdESForm, TElX509Certificate *SigningCertificate, TElCustomTSPClient *TSPClient)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_GenerateXAdES_1(_Handle, (TSBXAdESFormRaw)XAdESForm, (SigningCertificate != NULL) ? SigningCertificate->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
SB_INLINE TElDCAsyncStateHandle TElOfficeOpenXMLBaseSignatureHandler::InitiateAsyncSign()
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_InitiateAsyncSign(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
SB_INLINE TElDCAsyncStateHandle TElOfficeOpenXMLBaseSignatureHandler::InitiateAsyncSign(TElX509Certificate &Certificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_InitiateAsyncSign_1(_Handle, Certificate.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElOfficeOpenXMLBaseSignatureHandler::InitiateAsyncSign(TElX509Certificate *Certificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_InitiateAsyncSign_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
SB_INLINE TElDCAsyncStateHandle TElOfficeOpenXMLBaseSignatureHandler::InitiateAsyncSign(TElX509Certificate &Certificate, TSBOfficeOpenXMLEmbedCertificate EmbedCertificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_InitiateAsyncSign_2(_Handle, Certificate.getHandle(), (TSBOfficeOpenXMLEmbedCertificateRaw)EmbedCertificate, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElOfficeOpenXMLBaseSignatureHandler::InitiateAsyncSign(TElX509Certificate *Certificate, TSBOfficeOpenXMLEmbedCertificate EmbedCertificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_InitiateAsyncSign_2(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (TSBOfficeOpenXMLEmbedCertificateRaw)EmbedCertificate, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE
SB_INLINE TElDCAsyncStateHandle TElOfficeOpenXMLBaseSignatureHandler::InitiateAsyncSign(TElCustomCertStorage &CertStorage)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_InitiateAsyncSign_3(_Handle, CertStorage.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElOfficeOpenXMLBaseSignatureHandler::InitiateAsyncSign(TElCustomCertStorage *CertStorage)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_InitiateAsyncSign_3(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE
SB_INLINE TElDCAsyncStateHandle TElOfficeOpenXMLBaseSignatureHandler::InitiateAsyncSign(TElCustomCertStorage &CertStorage, TSBOfficeOpenXMLEmbedCertificate EmbedCertificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_InitiateAsyncSign_4(_Handle, CertStorage.getHandle(), (TSBOfficeOpenXMLEmbedCertificateRaw)EmbedCertificate, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElOfficeOpenXMLBaseSignatureHandler::InitiateAsyncSign(TElCustomCertStorage *CertStorage, TSBOfficeOpenXMLEmbedCertificate EmbedCertificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_InitiateAsyncSign_4(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, (TSBOfficeOpenXMLEmbedCertificateRaw)EmbedCertificate, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLKEYINFODATA
SB_INLINE TElDCAsyncStateHandle TElOfficeOpenXMLBaseSignatureHandler::InitiateAsyncSign(TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool EmbedKeyInSignature)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_InitiateAsyncSign_5(_Handle, KeyData.getHandle(), (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)EmbedKeyInSignature, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElOfficeOpenXMLBaseSignatureHandler::InitiateAsyncSign(TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool EmbedKeyInSignature)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_InitiateAsyncSign_5(_Handle, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE, (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)EmbedKeyInSignature, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::CompleteAsyncSign(TElDCAsyncState &State)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_CompleteAsyncSign(_Handle, State.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::CompleteAsyncSign(TElDCAsyncState *State)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_CompleteAsyncSign(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::CompleteAsyncSign(TElDCAsyncState &State, TElX509Certificate &Certificate, TSBOfficeOpenXMLEmbedCertificate EmbedCertificate)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_CompleteAsyncSign_1(_Handle, State.getHandle(), Certificate.getHandle(), (TSBOfficeOpenXMLEmbedCertificateRaw)EmbedCertificate));
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::CompleteAsyncSign(TElDCAsyncState *State, TElX509Certificate *Certificate, TSBOfficeOpenXMLEmbedCertificate EmbedCertificate)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_CompleteAsyncSign_1(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (TSBOfficeOpenXMLEmbedCertificateRaw)EmbedCertificate));
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::UpdateSignature()
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_UpdateSignature(_Handle));
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLSIGNEDPART
SB_INLINE int32_t TElOfficeOpenXMLBaseSignatureHandler::AddSignedPart(TElOfficeOpenXMLSignedPart &Part)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_AddSignedPart(_Handle, Part.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeOpenXMLBaseSignatureHandler::AddSignedPart(TElOfficeOpenXMLSignedPart *Part)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_AddSignedPart(_Handle, (Part != NULL) ? Part->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLSIGNEDPART */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLSIGNEDPART
SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::InsertSignedPart(int32_t Index, TElOfficeOpenXMLSignedPart &Part)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_InsertSignedPart(_Handle, Index, Part.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::InsertSignedPart(int32_t Index, TElOfficeOpenXMLSignedPart *Part)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_InsertSignedPart(_Handle, Index, (Part != NULL) ? Part->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLSIGNEDPART */

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::DeleteSignedPart(int32_t Index)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_DeleteSignedPart(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLSIGNEDPART
SB_INLINE TElOfficeOpenXMLSignedPartHandle TElOfficeOpenXMLBaseSignatureHandler::GetSignedPartByURI(const std::string &URI)
{
	TElOfficeOpenXMLSignedPartHandle OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_GetSignedPartByURI(_Handle, URI.data(), (int32_t)URI.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLSIGNEDPART */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLSIGNEDRELATIONSHIPPART
SB_INLINE TElOfficeOpenXMLSignedRelationshipPartHandle TElOfficeOpenXMLBaseSignatureHandler::GetSignedRelationshipPartByPartURI(const std::string &PartURI)
{
	TElOfficeOpenXMLSignedRelationshipPartHandle OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_GetSignedRelationshipPartByPartURI(_Handle, PartURI.data(), (int32_t)PartURI.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLSIGNEDRELATIONSHIPPART */

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::AddCoreProperties()
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_AddCoreProperties(_Handle));
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::AddDocument()
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_AddDocument(_Handle));
}

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::AddCounterSignature(TElOfficePackagePart &ASignaturePart)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_AddCounterSignature(_Handle, ASignaturePart.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::AddCounterSignature(TElOfficePackagePart *ASignaturePart)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_AddCounterSignature(_Handle, (ASignaturePart != NULL) ? ASignaturePart->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
SB_INLINE int32_t TElOfficeOpenXMLBaseSignatureHandler::AddPart(TElOfficePackagePart &Part)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_AddPart(_Handle, Part.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeOpenXMLBaseSignatureHandler::AddPart(TElOfficePackagePart *Part)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_AddPart(_Handle, (Part != NULL) ? Part->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

SB_INLINE int32_t TElOfficeOpenXMLBaseSignatureHandler::AddPart(const std::string &URI)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_AddPart_1(_Handle, URI.data(), (int32_t)URI.length(), &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::AddPartRelationshipSourceType(const std::string &PartURI, const std::string &SourceType)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_AddPartRelationshipSourceType(_Handle, PartURI.data(), (int32_t)PartURI.length(), SourceType.data(), (int32_t)SourceType.length()));
}

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
SB_INLINE int32_t TElOfficeOpenXMLBaseSignatureHandler::AddPartRelationships(TElOfficePackagePart &Part)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_AddPartRelationships(_Handle, Part.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOfficeOpenXMLBaseSignatureHandler::AddPartRelationships(TElOfficePackagePart *Part)
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_AddPartRelationships(_Handle, (Part != NULL) ? Part->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

bool TElOfficeOpenXMLBaseSignatureHandler::IsCorePropertiesSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_IsCorePropertiesSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOfficeOpenXMLBaseSignatureHandler::IsDocumentSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_IsDocumentSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
bool TElOfficeOpenXMLBaseSignatureHandler::IsPartSigned(TElOfficePackagePart &Part)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_IsPartSigned(_Handle, Part.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOfficeOpenXMLBaseSignatureHandler::IsPartSigned(TElOfficePackagePart *Part)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_IsPartSigned(_Handle, (Part != NULL) ? Part->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

bool TElOfficeOpenXMLBaseSignatureHandler::IsPartSigned(const std::string &URI)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_IsPartSigned_1(_Handle, URI.data(), (int32_t)URI.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TClassHandle TElOfficeOpenXMLBaseSignatureHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_ClassType(&OutResult));
	return OutResult;
}

TElXMLDigestMethod TElOfficeOpenXMLBaseSignatureHandler::get_DigestMethod()
{
	TElXMLDigestMethodRaw OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_get_DigestMethod(_Handle, &OutResultRaw));
	return (TElXMLDigestMethod)OutResultRaw;
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::set_DigestMethod(TElXMLDigestMethod Value)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_set_DigestMethod(_Handle, (TElXMLDigestMethodRaw)Value));
}

SB_INLINE int32_t TElOfficeOpenXMLBaseSignatureHandler::get_SignedPartCount()
{
	int32_t OutResult;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_get_SignedPartCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLSIGNEDPART
TElOfficeOpenXMLSignedPart* TElOfficeOpenXMLBaseSignatureHandler::get_SignedParts(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_get_SignedParts(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignedParts)
		this->_Inst_SignedParts = new TElOfficeOpenXMLSignedPart(hOutResult, ohFalse);
	else
		this->_Inst_SignedParts->updateHandle(hOutResult);
	return this->_Inst_SignedParts;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLSIGNEDPART */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElOfficeOpenXMLBaseSignatureHandler::get_Certificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_get_Certificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElOfficeOpenXMLBaseSignatureHandler::get_SignerCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_get_SignerCertificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignerCertificate)
		this->_Inst_SignerCertificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_SignerCertificate->updateHandle(hOutResult);
	return this->_Inst_SignerCertificate;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
TElXMLKeyInfoData* TElOfficeOpenXMLBaseSignatureHandler::get_SignerKeyData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_get_SignerKeyData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignerKeyData)
		this->_Inst_SignerKeyData = new TElXMLKeyInfoData(hOutResult, ohFalse);
	else
		this->_Inst_SignerKeyData->updateHandle(hOutResult);
	return this->_Inst_SignerKeyData;
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATURETIME
TElOfficeXMLSignatureTime* TElOfficeOpenXMLBaseSignatureHandler::get_SignatureTime()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_get_SignatureTime(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureTime)
		this->_Inst_SignatureTime = new TElOfficeXMLSignatureTime(hOutResult, ohFalse);
	else
		this->_Inst_SignatureTime->updateHandle(hOutResult);
	return this->_Inst_SignatureTime;
}
#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATURETIME */

#ifdef SB_USE_CLASS_TELXADESPROCESSOR
TElXAdESProcessor* TElOfficeOpenXMLBaseSignatureHandler::get_XAdESProcessor()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_get_XAdESProcessor(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_XAdESProcessor)
		this->_Inst_XAdESProcessor = new TElXAdESProcessor(hOutResult, ohFalse);
	else
		this->_Inst_XAdESProcessor->updateHandle(hOutResult);
	return this->_Inst_XAdESProcessor;
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::set_XAdESProcessor(TElXAdESProcessor &Value)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_set_XAdESProcessor(_Handle, Value.getHandle()));
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::set_XAdESProcessor(TElXAdESProcessor *Value)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_set_XAdESProcessor(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXADESPROCESSOR */

bool TElOfficeOpenXMLBaseSignatureHandler::get_OwnXAdESProcessor()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_get_OwnXAdESProcessor(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::set_OwnXAdESProcessor(bool Value)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_set_OwnXAdESProcessor(_Handle, (int8_t)Value));
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::get_OnPrepareSignature(TSBOfficeXMLSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_get_OnPrepareSignature(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::set_OnPrepareSignature(TSBOfficeXMLSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_set_OnPrepareSignature(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::get_OnBeforeSign(TSBOfficeXMLSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_get_OnBeforeSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::set_OnBeforeSign(TSBOfficeXMLSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_set_OnBeforeSign(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::get_OnAfterSign(TSBOfficeXMLSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_get_OnAfterSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOfficeOpenXMLBaseSignatureHandler::set_OnAfterSign(TSBOfficeXMLSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_set_OnAfterSign(_Handle, pMethodValue, pDataValue));
}

void TElOfficeOpenXMLBaseSignatureHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLSIGNEDPART
	this->_Inst_SignedParts = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLSIGNEDPART */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_SignerCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
	this->_Inst_SignerKeyData = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATURETIME
	this->_Inst_SignatureTime = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATURETIME */
#ifdef SB_USE_CLASS_TELXADESPROCESSOR
	this->_Inst_XAdESProcessor = NULL;
#endif /* SB_USE_CLASS_TELXADESPROCESSOR */
}

TElOfficeOpenXMLBaseSignatureHandler::TElOfficeOpenXMLBaseSignatureHandler(TElOfficeOpenXMLBaseSignatureHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLCustomSignatureHandler(handle, ownHandle)
{
	initInstances();
}

TElOfficeOpenXMLBaseSignatureHandler::TElOfficeOpenXMLBaseSignatureHandler(TComponent &Owner) : TElOfficeOpenXMLCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_Create(Owner.getHandle(), &_Handle));
}

TElOfficeOpenXMLBaseSignatureHandler::TElOfficeOpenXMLBaseSignatureHandler(TComponent *Owner) : TElOfficeOpenXMLCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXMLBaseSignatureHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElOfficeOpenXMLBaseSignatureHandler::~TElOfficeOpenXMLBaseSignatureHandler()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLSIGNEDPART
	delete this->_Inst_SignedParts;
	this->_Inst_SignedParts = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLSIGNEDPART */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_SignerCertificate;
	this->_Inst_SignerCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
	delete this->_Inst_SignerKeyData;
	this->_Inst_SignerKeyData = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATURETIME
	delete this->_Inst_SignatureTime;
	this->_Inst_SignatureTime = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATURETIME */
#ifdef SB_USE_CLASS_TELXADESPROCESSOR
	delete this->_Inst_XAdESProcessor;
	this->_Inst_XAdESProcessor = NULL;
#endif /* SB_USE_CLASS_TELXADESPROCESSOR */
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLBASESIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLSIGNATUREHANDLER

void TElOfficeOpenXMLSignatureHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLSignatureHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1887156877, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOfficeOpenXMLSignatureHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXMLSignatureHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1887156877, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeOpenXMLSignatureHandler::Reset()
{
	SBCheckError(TElOfficeOpenXMLSignatureHandler_Reset(_Handle));
}

SB_INLINE void TElOfficeOpenXMLSignatureHandler::AddCoreProperties()
{
	SBCheckError(TElOfficeOpenXMLSignatureHandler_AddCoreProperties(_Handle));
}

SB_INLINE void TElOfficeOpenXMLSignatureHandler::AddDocument()
{
	SBCheckError(TElOfficeOpenXMLSignatureHandler_AddDocument(_Handle));
}

bool TElOfficeOpenXMLSignatureHandler::IsCorePropertiesSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLSignatureHandler_IsCorePropertiesSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOfficeOpenXMLSignatureHandler::IsDocumentSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXMLSignatureHandler_IsDocumentSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TClassHandle TElOfficeOpenXMLSignatureHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeOpenXMLSignatureHandler_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATUREINFOV1
TElOfficeXMLSignatureInfoV1* TElOfficeOpenXMLSignatureHandler::get_SignatureInfoV1()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLSignatureHandler_get_SignatureInfoV1(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureInfoV1)
		this->_Inst_SignatureInfoV1 = new TElOfficeXMLSignatureInfoV1(hOutResult, ohFalse);
	else
		this->_Inst_SignatureInfoV1->updateHandle(hOutResult);
	return this->_Inst_SignatureInfoV1;
}
#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATUREINFOV1 */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLSIGNATURELINE
TElOfficeOpenXMLSignatureLine* TElOfficeOpenXMLSignatureHandler::get_SignatureLine()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXMLSignatureHandler_get_SignatureLine(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureLine)
		this->_Inst_SignatureLine = new TElOfficeOpenXMLSignatureLine(hOutResult, ohFalse);
	else
		this->_Inst_SignatureLine->updateHandle(hOutResult);
	return this->_Inst_SignatureLine;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLSIGNATURELINE */

void TElOfficeOpenXMLSignatureHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATUREINFOV1
	this->_Inst_SignatureInfoV1 = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATUREINFOV1 */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLSIGNATURELINE
	this->_Inst_SignatureLine = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLSIGNATURELINE */
}

TElOfficeOpenXMLSignatureHandler::TElOfficeOpenXMLSignatureHandler(TElOfficeOpenXMLSignatureHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLBaseSignatureHandler(handle, ownHandle)
{
	initInstances();
}

TElOfficeOpenXMLSignatureHandler::TElOfficeOpenXMLSignatureHandler(TComponent &Owner) : TElOfficeOpenXMLBaseSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXMLSignatureHandler_Create(Owner.getHandle(), &_Handle));
}

TElOfficeOpenXMLSignatureHandler::TElOfficeOpenXMLSignatureHandler(TComponent *Owner) : TElOfficeOpenXMLBaseSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXMLSignatureHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElOfficeOpenXMLSignatureHandler::~TElOfficeOpenXMLSignatureHandler()
{
#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATUREINFOV1
	delete this->_Inst_SignatureInfoV1;
	this->_Inst_SignatureInfoV1 = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATUREINFOV1 */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLSIGNATURELINE
	delete this->_Inst_SignatureLine;
	this->_Inst_SignatureLine = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLSIGNATURELINE */
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOFFICEOPENXPSSIGNATUREHANDLER

void TElOfficeOpenXPSSignatureHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXPSSignatureHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-775433155, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOfficeOpenXPSSignatureHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficeOpenXPSSignatureHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-775433155, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOfficeOpenXPSSignatureHandler::AddCoreProperties()
{
	SBCheckError(TElOfficeOpenXPSSignatureHandler_AddCoreProperties(_Handle));
}

SB_INLINE void TElOfficeOpenXPSSignatureHandler::AddDocument()
{
	SBCheckError(TElOfficeOpenXPSSignatureHandler_AddDocument(_Handle));
}

SB_INLINE void TElOfficeOpenXPSSignatureHandler::AddSignatureOrigin()
{
	SBCheckError(TElOfficeOpenXPSSignatureHandler_AddSignatureOrigin(_Handle));
}

bool TElOfficeOpenXPSSignatureHandler::IsCorePropertiesSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXPSSignatureHandler_IsCorePropertiesSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOfficeOpenXPSSignatureHandler::IsDocumentSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXPSSignatureHandler_IsDocumentSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOfficeOpenXPSSignatureHandler::IsSignatureOriginSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficeOpenXPSSignatureHandler_IsSignatureOriginSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TClassHandle TElOfficeOpenXPSSignatureHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOfficeOpenXPSSignatureHandler_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXPSSIGNATUREDEFINITION
TElOfficeOpenXPSSignatureDefinition* TElOfficeOpenXPSSignatureHandler::get_SignatureDefinition()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeOpenXPSSignatureHandler_get_SignatureDefinition(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureDefinition)
		this->_Inst_SignatureDefinition = new TElOfficeOpenXPSSignatureDefinition(hOutResult, ohFalse);
	else
		this->_Inst_SignatureDefinition->updateHandle(hOutResult);
	return this->_Inst_SignatureDefinition;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXPSSIGNATUREDEFINITION */

void TElOfficeOpenXPSSignatureHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXPSSIGNATUREDEFINITION
	this->_Inst_SignatureDefinition = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXPSSIGNATUREDEFINITION */
}

TElOfficeOpenXPSSignatureHandler::TElOfficeOpenXPSSignatureHandler(TElOfficeOpenXPSSignatureHandlerHandle handle, TElOwnHandle ownHandle) : TElOfficeOpenXMLBaseSignatureHandler(handle, ownHandle)
{
	initInstances();
}

TElOfficeOpenXPSSignatureHandler::TElOfficeOpenXPSSignatureHandler(TComponent &Owner) : TElOfficeOpenXMLBaseSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXPSSignatureHandler_Create(Owner.getHandle(), &_Handle));
}

TElOfficeOpenXPSSignatureHandler::TElOfficeOpenXPSSignatureHandler(TComponent *Owner) : TElOfficeOpenXMLBaseSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeOpenXPSSignatureHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElOfficeOpenXPSSignatureHandler::~TElOfficeOpenXPSSignatureHandler()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXPSSIGNATUREDEFINITION
	delete this->_Inst_SignatureDefinition;
	this->_Inst_SignatureDefinition = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXPSSIGNATUREDEFINITION */
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXPSSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOPENOFFICESIGNEDENTRY

TElXMLDigestMethod TElOpenOfficeSignedEntry::get_DigestMethod()
{
	TElXMLDigestMethodRaw OutResultRaw = 0;
	SBCheckError(TElOpenOfficeSignedEntry_get_DigestMethod(_Handle, &OutResultRaw));
	return (TElXMLDigestMethod)OutResultRaw;
}

SB_INLINE void TElOpenOfficeSignedEntry::set_DigestMethod(TElXMLDigestMethod Value)
{
	SBCheckError(TElOpenOfficeSignedEntry_set_DigestMethod(_Handle, (TElXMLDigestMethodRaw)Value));
}

void TElOpenOfficeSignedEntry::get_DigestValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOpenOfficeSignedEntry_get_DigestValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1106117697, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOpenOfficeSignedEntry::set_DigestValue(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOpenOfficeSignedEntry_set_DigestValue(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElOpenOfficeSignedEntry::get_Path(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficeSignedEntry_get_Path(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1689337962, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBOpenOfficeEntryValidationStatus TElOpenOfficeSignedEntry::get_ValidationStatus()
{
	TSBOpenOfficeEntryValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElOpenOfficeSignedEntry_get_ValidationStatus(_Handle, &OutResultRaw));
	return (TSBOpenOfficeEntryValidationStatus)OutResultRaw;
}

TElOpenOfficeSignedEntry::TElOpenOfficeSignedEntry(TElOpenOfficeSignedEntryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELOPENOFFICECUSTOMSIGNATUREHANDLER
TElOpenOfficeSignedEntry::TElOpenOfficeSignedEntry(TElOpenOfficeCustomSignatureHandler &Handler) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOpenOfficeSignedEntry_Create(Handler.getHandle(), &_Handle));
}

TElOpenOfficeSignedEntry::TElOpenOfficeSignedEntry(TElOpenOfficeCustomSignatureHandler *Handler) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOpenOfficeSignedEntry_Create((Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELOPENOFFICECUSTOMSIGNATUREHANDLER */

#ifdef SB_USE_CLASS_TELOPENOFFICECUSTOMSIGNATUREHANDLER
TElOpenOfficeSignedEntry::TElOpenOfficeSignedEntry(TElOpenOfficeCustomSignatureHandler &Handler, const std::string &APath) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOpenOfficeSignedEntry_Create_1(Handler.getHandle(), APath.data(), (int32_t)APath.length(), &_Handle));
}

TElOpenOfficeSignedEntry::TElOpenOfficeSignedEntry(TElOpenOfficeCustomSignatureHandler *Handler, const std::string &APath) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOpenOfficeSignedEntry_Create_1((Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, APath.data(), (int32_t)APath.length(), &_Handle));
}
#endif /* SB_USE_CLASS_TELOPENOFFICECUSTOMSIGNATUREHANDLER */

#endif /* SB_USE_CLASS_TELOPENOFFICESIGNEDENTRY */

#ifdef SB_USE_CLASS_TELOPENOFFICESIGNATUREHANDLER

void TElOpenOfficeSignatureHandler::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficeSignatureHandler_GetName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(32430979, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOpenOfficeSignatureHandler::GetName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficeSignatureHandler_GetName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(32430979, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOpenOfficeSignatureHandler::Reset()
{
	SBCheckError(TElOpenOfficeSignatureHandler_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElOpenOfficeSignatureHandler::Sign(TElX509Certificate &Certificate)
{
	SBCheckError(TElOpenOfficeSignatureHandler_Sign(_Handle, Certificate.getHandle()));
}

SB_INLINE void TElOpenOfficeSignatureHandler::Sign(TElX509Certificate *Certificate)
{
	SBCheckError(TElOpenOfficeSignatureHandler_Sign(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_INLINE void TElOpenOfficeSignatureHandler::Sign(TElCustomCertStorage &CertStorage)
{
	SBCheckError(TElOpenOfficeSignatureHandler_Sign_1(_Handle, CertStorage.getHandle()));
}

SB_INLINE void TElOpenOfficeSignatureHandler::Sign(TElCustomCertStorage *CertStorage)
{
	SBCheckError(TElOpenOfficeSignatureHandler_Sign_1(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
SB_INLINE void TElOpenOfficeSignatureHandler::Sign(TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey)
{
	SBCheckError(TElOpenOfficeSignatureHandler_Sign_2(_Handle, KeyData.getHandle(), (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)IncludeKey));
}

SB_INLINE void TElOpenOfficeSignatureHandler::Sign(TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey)
{
	SBCheckError(TElOpenOfficeSignatureHandler_Sign_2(_Handle, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE, (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)IncludeKey));
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

TSBOpenOfficeSignatureValidationStatus TElOpenOfficeSignatureHandler::Validate()
{
	TSBOpenOfficeSignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElOpenOfficeSignatureHandler_Validate(_Handle, &OutResultRaw));
	return (TSBOpenOfficeSignatureValidationStatus)OutResultRaw;
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TSBOpenOfficeSignatureValidationStatus TElOpenOfficeSignatureHandler::Validate(TElX509Certificate &Certificate)
{
	TSBOpenOfficeSignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElOpenOfficeSignatureHandler_Validate_1(_Handle, Certificate.getHandle(), &OutResultRaw));
	return (TSBOpenOfficeSignatureValidationStatus)OutResultRaw;
}

TSBOpenOfficeSignatureValidationStatus TElOpenOfficeSignatureHandler::Validate(TElX509Certificate *Certificate)
{
	TSBOpenOfficeSignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElOpenOfficeSignatureHandler_Validate_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBOpenOfficeSignatureValidationStatus)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
TSBOpenOfficeSignatureValidationStatus TElOpenOfficeSignatureHandler::Validate(TElXMLKeyInfoData &KeyData)
{
	TSBOpenOfficeSignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElOpenOfficeSignatureHandler_Validate_2(_Handle, KeyData.getHandle(), &OutResultRaw));
	return (TSBOpenOfficeSignatureValidationStatus)OutResultRaw;
}

TSBOpenOfficeSignatureValidationStatus TElOpenOfficeSignatureHandler::Validate(TElXMLKeyInfoData *KeyData)
{
	TSBOpenOfficeSignatureValidationStatusRaw OutResultRaw = 0;
	SBCheckError(TElOpenOfficeSignatureHandler_Validate_2(_Handle, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (TSBOpenOfficeSignatureValidationStatus)OutResultRaw;
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElOpenOfficeSignatureHandler::GenerateXAdES(TSBXAdESForm XAdESForm, TElX509Certificate &SigningCertificate)
{
	SBCheckError(TElOpenOfficeSignatureHandler_GenerateXAdES(_Handle, (TSBXAdESFormRaw)XAdESForm, SigningCertificate.getHandle()));
}

SB_INLINE void TElOpenOfficeSignatureHandler::GenerateXAdES(TSBXAdESForm XAdESForm, TElX509Certificate *SigningCertificate)
{
	SBCheckError(TElOpenOfficeSignatureHandler_GenerateXAdES(_Handle, (TSBXAdESFormRaw)XAdESForm, (SigningCertificate != NULL) ? SigningCertificate->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE
SB_INLINE void TElOpenOfficeSignatureHandler::GenerateXAdES(TSBXAdESForm XAdESForm, TElX509Certificate &SigningCertificate, TElCustomTSPClient &TSPClient)
{
	SBCheckError(TElOpenOfficeSignatureHandler_GenerateXAdES_1(_Handle, (TSBXAdESFormRaw)XAdESForm, SigningCertificate.getHandle(), TSPClient.getHandle()));
}

SB_INLINE void TElOpenOfficeSignatureHandler::GenerateXAdES(TSBXAdESForm XAdESForm, TElX509Certificate *SigningCertificate, TElCustomTSPClient *TSPClient)
{
	SBCheckError(TElOpenOfficeSignatureHandler_GenerateXAdES_1(_Handle, (TSBXAdESFormRaw)XAdESForm, (SigningCertificate != NULL) ? SigningCertificate->getHandle() : SB_NULL_HANDLE, (TSPClient != NULL) ? TSPClient->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMTSPCLIENT_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
SB_INLINE TElDCAsyncStateHandle TElOpenOfficeSignatureHandler::InitiateAsyncSign()
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOpenOfficeSignatureHandler_InitiateAsyncSign(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
SB_INLINE TElDCAsyncStateHandle TElOpenOfficeSignatureHandler::InitiateAsyncSign(TElX509Certificate &Certificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOpenOfficeSignatureHandler_InitiateAsyncSign_1(_Handle, Certificate.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElOpenOfficeSignatureHandler::InitiateAsyncSign(TElX509Certificate *Certificate)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOpenOfficeSignatureHandler_InitiateAsyncSign_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE
SB_INLINE TElDCAsyncStateHandle TElOpenOfficeSignatureHandler::InitiateAsyncSign(TElCustomCertStorage &CertStorage)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOpenOfficeSignatureHandler_InitiateAsyncSign_2(_Handle, CertStorage.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElOpenOfficeSignatureHandler::InitiateAsyncSign(TElCustomCertStorage *CertStorage)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOpenOfficeSignatureHandler_InitiateAsyncSign_2(_Handle, (CertStorage != NULL) ? CertStorage->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLKEYINFODATA
SB_INLINE TElDCAsyncStateHandle TElOpenOfficeSignatureHandler::InitiateAsyncSign(TElXMLKeyInfoData &KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOpenOfficeSignatureHandler_InitiateAsyncSign_3(_Handle, KeyData.getHandle(), (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)IncludeKey, &OutResult));
	return OutResult;
}

SB_INLINE TElDCAsyncStateHandle TElOpenOfficeSignatureHandler::InitiateAsyncSign(TElXMLKeyInfoData *KeyData, TElXMLSignatureMethod SignatureMethod, bool IncludeKey)
{
	TElDCAsyncStateHandle OutResult;
	SBCheckError(TElOpenOfficeSignatureHandler_InitiateAsyncSign_3(_Handle, (KeyData != NULL) ? KeyData->getHandle() : SB_NULL_HANDLE, (TElXMLSignatureMethodRaw)SignatureMethod, (int8_t)IncludeKey, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
SB_INLINE void TElOpenOfficeSignatureHandler::CompleteAsyncSign(TElDCAsyncState &State)
{
	SBCheckError(TElOpenOfficeSignatureHandler_CompleteAsyncSign(_Handle, State.getHandle()));
}

SB_INLINE void TElOpenOfficeSignatureHandler::CompleteAsyncSign(TElDCAsyncState *State)
{
	SBCheckError(TElOpenOfficeSignatureHandler_CompleteAsyncSign(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
SB_INLINE void TElOpenOfficeSignatureHandler::CompleteAsyncSign(TElDCAsyncState &State, TElX509Certificate &Certificate, bool EmbedCertificate)
{
	SBCheckError(TElOpenOfficeSignatureHandler_CompleteAsyncSign_1(_Handle, State.getHandle(), Certificate.getHandle(), (int8_t)EmbedCertificate));
}

SB_INLINE void TElOpenOfficeSignatureHandler::CompleteAsyncSign(TElDCAsyncState *State, TElX509Certificate *Certificate, bool EmbedCertificate)
{
	SBCheckError(TElOpenOfficeSignatureHandler_CompleteAsyncSign_1(_Handle, (State != NULL) ? State->getHandle() : SB_NULL_HANDLE, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)EmbedCertificate));
}
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

SB_INLINE void TElOpenOfficeSignatureHandler::UpdateSignature()
{
	SBCheckError(TElOpenOfficeSignatureHandler_UpdateSignature(_Handle));
}

#ifdef SB_USE_CLASS_TELOPENOFFICESIGNEDENTRY
SB_INLINE int32_t TElOpenOfficeSignatureHandler::AddSignedEntry(TElOpenOfficeSignedEntry &Entry)
{
	int32_t OutResult;
	SBCheckError(TElOpenOfficeSignatureHandler_AddSignedEntry(_Handle, Entry.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOpenOfficeSignatureHandler::AddSignedEntry(TElOpenOfficeSignedEntry *Entry)
{
	int32_t OutResult;
	SBCheckError(TElOpenOfficeSignatureHandler_AddSignedEntry(_Handle, (Entry != NULL) ? Entry->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOPENOFFICESIGNEDENTRY */

SB_INLINE int32_t TElOpenOfficeSignatureHandler::AddSignedEntry(const std::string &Path)
{
	int32_t OutResult;
	SBCheckError(TElOpenOfficeSignatureHandler_AddSignedEntry_1(_Handle, Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOPENOFFICESIGNEDENTRY
SB_INLINE void TElOpenOfficeSignatureHandler::InsertSignedEntry(int32_t Index, TElOpenOfficeSignedEntry &Entry)
{
	SBCheckError(TElOpenOfficeSignatureHandler_InsertSignedEntry(_Handle, Index, Entry.getHandle()));
}

SB_INLINE void TElOpenOfficeSignatureHandler::InsertSignedEntry(int32_t Index, TElOpenOfficeSignedEntry *Entry)
{
	SBCheckError(TElOpenOfficeSignatureHandler_InsertSignedEntry(_Handle, Index, (Entry != NULL) ? Entry->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOPENOFFICESIGNEDENTRY */

SB_INLINE void TElOpenOfficeSignatureHandler::DeleteSignedEntry(int32_t Index)
{
	SBCheckError(TElOpenOfficeSignatureHandler_DeleteSignedEntry(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELOPENOFFICESIGNEDENTRY
SB_INLINE TElOpenOfficeSignedEntryHandle TElOpenOfficeSignatureHandler::GetSignedEntryByPath(const std::string &Path)
{
	TElOpenOfficeSignedEntryHandle OutResult;
	SBCheckError(TElOpenOfficeSignatureHandler_GetSignedEntryByPath(_Handle, Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOPENOFFICESIGNEDENTRY */

SB_INLINE void TElOpenOfficeSignatureHandler::AddDocument()
{
	SBCheckError(TElOpenOfficeSignatureHandler_AddDocument(_Handle));
}

bool TElOpenOfficeSignatureHandler::IsDocumentSigned()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOpenOfficeSignatureHandler_IsDocumentSigned(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TClassHandle TElOpenOfficeSignatureHandler::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOpenOfficeSignatureHandler_ClassType(&OutResult));
	return OutResult;
}

TElXMLDigestMethod TElOpenOfficeSignatureHandler::get_DigestMethod()
{
	TElXMLDigestMethodRaw OutResultRaw = 0;
	SBCheckError(TElOpenOfficeSignatureHandler_get_DigestMethod(_Handle, &OutResultRaw));
	return (TElXMLDigestMethod)OutResultRaw;
}

SB_INLINE void TElOpenOfficeSignatureHandler::set_DigestMethod(TElXMLDigestMethod Value)
{
	SBCheckError(TElOpenOfficeSignatureHandler_set_DigestMethod(_Handle, (TElXMLDigestMethodRaw)Value));
}

SB_INLINE int32_t TElOpenOfficeSignatureHandler::get_SignedEntryCount()
{
	int32_t OutResult;
	SBCheckError(TElOpenOfficeSignatureHandler_get_SignedEntryCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOPENOFFICESIGNEDENTRY
TElOpenOfficeSignedEntry* TElOpenOfficeSignatureHandler::get_SignedEntries(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOpenOfficeSignatureHandler_get_SignedEntries(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignedEntries)
		this->_Inst_SignedEntries = new TElOpenOfficeSignedEntry(hOutResult, ohFalse);
	else
		this->_Inst_SignedEntries->updateHandle(hOutResult);
	return this->_Inst_SignedEntries;
}
#endif /* SB_USE_CLASS_TELOPENOFFICESIGNEDENTRY */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElOpenOfficeSignatureHandler::get_Certificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOpenOfficeSignatureHandler_get_Certificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElOpenOfficeSignatureHandler::get_SignerCertificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOpenOfficeSignatureHandler_get_SignerCertificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignerCertificate)
		this->_Inst_SignerCertificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_SignerCertificate->updateHandle(hOutResult);
	return this->_Inst_SignerCertificate;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
TElXMLKeyInfoData* TElOpenOfficeSignatureHandler::get_SignerKeyData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOpenOfficeSignatureHandler_get_SignerKeyData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignerKeyData)
		this->_Inst_SignerKeyData = new TElXMLKeyInfoData(hOutResult, ohFalse);
	else
		this->_Inst_SignerKeyData->updateHandle(hOutResult);
	return this->_Inst_SignerKeyData;
}
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELOFFICEXMLDCDATE
TElOfficeXMLDCDate* TElOpenOfficeSignatureHandler::get_SignatureTime()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOpenOfficeSignatureHandler_get_SignatureTime(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SignatureTime)
		this->_Inst_SignatureTime = new TElOfficeXMLDCDate(hOutResult, ohFalse);
	else
		this->_Inst_SignatureTime->updateHandle(hOutResult);
	return this->_Inst_SignatureTime;
}
#endif /* SB_USE_CLASS_TELOFFICEXMLDCDATE */

#ifdef SB_USE_CLASS_TELXADESPROCESSOR
TElXAdESProcessor* TElOpenOfficeSignatureHandler::get_XAdESProcessor()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOpenOfficeSignatureHandler_get_XAdESProcessor(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_XAdESProcessor)
		this->_Inst_XAdESProcessor = new TElXAdESProcessor(hOutResult, ohFalse);
	else
		this->_Inst_XAdESProcessor->updateHandle(hOutResult);
	return this->_Inst_XAdESProcessor;
}

SB_INLINE void TElOpenOfficeSignatureHandler::set_XAdESProcessor(TElXAdESProcessor &Value)
{
	SBCheckError(TElOpenOfficeSignatureHandler_set_XAdESProcessor(_Handle, Value.getHandle()));
}

SB_INLINE void TElOpenOfficeSignatureHandler::set_XAdESProcessor(TElXAdESProcessor *Value)
{
	SBCheckError(TElOpenOfficeSignatureHandler_set_XAdESProcessor(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXADESPROCESSOR */

bool TElOpenOfficeSignatureHandler::get_OwnXAdESProcessor()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOpenOfficeSignatureHandler_get_OwnXAdESProcessor(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElOpenOfficeSignatureHandler::set_OwnXAdESProcessor(bool Value)
{
	SBCheckError(TElOpenOfficeSignatureHandler_set_OwnXAdESProcessor(_Handle, (int8_t)Value));
}

SB_INLINE void TElOpenOfficeSignatureHandler::get_OnPrepareSignature(TSBOfficeXMLSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOpenOfficeSignatureHandler_get_OnPrepareSignature(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOpenOfficeSignatureHandler::set_OnPrepareSignature(TSBOfficeXMLSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOpenOfficeSignatureHandler_set_OnPrepareSignature(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElOpenOfficeSignatureHandler::get_OnBeforeSign(TSBOfficeXMLSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOpenOfficeSignatureHandler_get_OnBeforeSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOpenOfficeSignatureHandler::set_OnBeforeSign(TSBOfficeXMLSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOpenOfficeSignatureHandler_set_OnBeforeSign(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElOpenOfficeSignatureHandler::get_OnAfterSign(TSBOfficeXMLSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOpenOfficeSignatureHandler_get_OnAfterSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOpenOfficeSignatureHandler::set_OnAfterSign(TSBOfficeXMLSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOpenOfficeSignatureHandler_set_OnAfterSign(_Handle, pMethodValue, pDataValue));
}

void TElOpenOfficeSignatureHandler::initInstances()
{
#ifdef SB_USE_CLASS_TELOPENOFFICESIGNEDENTRY
	this->_Inst_SignedEntries = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICESIGNEDENTRY */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_SignerCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
	this->_Inst_SignerKeyData = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCDATE
	this->_Inst_SignatureTime = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLDCDATE */
#ifdef SB_USE_CLASS_TELXADESPROCESSOR
	this->_Inst_XAdESProcessor = NULL;
#endif /* SB_USE_CLASS_TELXADESPROCESSOR */
}

TElOpenOfficeSignatureHandler::TElOpenOfficeSignatureHandler(TElOpenOfficeSignatureHandlerHandle handle, TElOwnHandle ownHandle) : TElOpenOfficeCustomSignatureHandler(handle, ownHandle)
{
	initInstances();
}

TElOpenOfficeSignatureHandler::TElOpenOfficeSignatureHandler(TComponent &Owner) : TElOpenOfficeCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOpenOfficeSignatureHandler_Create(Owner.getHandle(), &_Handle));
}

TElOpenOfficeSignatureHandler::TElOpenOfficeSignatureHandler(TComponent *Owner) : TElOpenOfficeCustomSignatureHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOpenOfficeSignatureHandler_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElOpenOfficeSignatureHandler::~TElOpenOfficeSignatureHandler()
{
#ifdef SB_USE_CLASS_TELOPENOFFICESIGNEDENTRY
	delete this->_Inst_SignedEntries;
	this->_Inst_SignedEntries = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICESIGNEDENTRY */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_SignerCertificate;
	this->_Inst_SignerCertificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
	delete this->_Inst_SignerKeyData;
	this->_Inst_SignerKeyData = NULL;
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCDATE
	delete this->_Inst_SignatureTime;
	this->_Inst_SignatureTime = NULL;
#endif /* SB_USE_CLASS_TELOFFICEXMLDCDATE */
#ifdef SB_USE_CLASS_TELXADESPROCESSOR
	delete this->_Inst_XAdESProcessor;
	this->_Inst_XAdESProcessor = NULL;
#endif /* SB_USE_CLASS_TELXADESPROCESSOR */
}
#endif /* SB_USE_CLASS_TELOPENOFFICESIGNATUREHANDLER */

};	/* namespace SecureBlackbox */

