#include "sbutils.h"

namespace SecureBlackbox {

#ifndef SB_WINDOWS
#ifdef SB_USE_CLASS_TELSTRINGLIST

TElStringList::TElStringList(TElStringListHandle handle, TElOwnHandle ownHandle) : TStringList(handle, ownHandle)
{
}

TElStringList::TElStringList() : TStringList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElStringList_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST

SB_INLINE int32_t TElByteArrayList::Add(const std::vector<uint8_t> &S)
{
	int32_t OutResult;
	SBCheckError(TElByteArrayList_Add(_Handle, SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size(), &OutResult));
	return OutResult;
}

SB_INLINE void TElByteArrayList::AddRange(TElByteArrayList &List)
{
	SBCheckError(TElByteArrayList_AddRange(_Handle, List.getHandle()));
}

SB_INLINE void TElByteArrayList::AddRange(TElByteArrayList *List)
{
	SBCheckError(TElByteArrayList_AddRange(_Handle, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElByteArrayList::Assign(TElByteArrayList &Source)
{
	SBCheckError(TElByteArrayList_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElByteArrayList::Assign(TElByteArrayList *Source)
{
	SBCheckError(TElByteArrayList_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElByteArrayList::Clear()
{
	SBCheckError(TElByteArrayList_Clear(_Handle));
}

SB_INLINE void TElByteArrayList::Delete(int32_t Index)
{
	SBCheckError(TElByteArrayList_Delete(_Handle, Index));
}

SB_INLINE int32_t TElByteArrayList::IndexOf(const std::vector<uint8_t> &S)
{
	int32_t OutResult;
	SBCheckError(TElByteArrayList_IndexOf(_Handle, SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size(), &OutResult));
	return OutResult;
}

SB_INLINE void TElByteArrayList::Insert(int32_t Index, const std::vector<uint8_t> &S)
{
	SBCheckError(TElByteArrayList_Insert(_Handle, Index, SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size()));
}

SB_INLINE int32_t TElByteArrayList::get_Capacity()
{
	int32_t OutResult;
	SBCheckError(TElByteArrayList_get_Capacity(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElByteArrayList::set_Capacity(int32_t Value)
{
	SBCheckError(TElByteArrayList_set_Capacity(_Handle, Value));
}

SB_INLINE int32_t TElByteArrayList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElByteArrayList_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElByteArrayList::get_Item(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElByteArrayList_get_Item(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1774379813, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElByteArrayList::set_Item(int32_t Index, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElByteArrayList_set_Item(_Handle, Index, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElByteArrayList::TElByteArrayList(TElByteArrayListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElByteArrayList::TElByteArrayList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElByteArrayList_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

#ifdef SB_USE_CLASS_TSBOBJECTLIST

SB_INLINE int32_t TSBObjectList::Add(TObject &AObject)
{
	int32_t OutResult;
	SBCheckError(TSBObjectList_Add(_Handle, AObject.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TSBObjectList::Add(TObject *AObject)
{
	int32_t OutResult;
	SBCheckError(TSBObjectList_Add(_Handle, (AObject != NULL) ? AObject->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TSBObjectList::Remove(TObject &AObject)
{
	int32_t OutResult;
	SBCheckError(TSBObjectList_Remove(_Handle, AObject.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TSBObjectList::Remove(TObject *AObject)
{
	int32_t OutResult;
	SBCheckError(TSBObjectList_Remove(_Handle, (AObject != NULL) ? AObject->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TSBObjectList::IndexOf(TObject &AObject)
{
	int32_t OutResult;
	SBCheckError(TSBObjectList_IndexOf(_Handle, AObject.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TSBObjectList::IndexOf(TObject *AObject)
{
	int32_t OutResult;
	SBCheckError(TSBObjectList_IndexOf(_Handle, (AObject != NULL) ? AObject->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

SB_INLINE void TSBObjectList::Insert(int32_t Index, TObject &AObject)
{
	SBCheckError(TSBObjectList_Insert(_Handle, Index, AObject.getHandle()));
}

SB_INLINE void TSBObjectList::Insert(int32_t Index, TObject *AObject)
{
	SBCheckError(TSBObjectList_Insert(_Handle, Index, (AObject != NULL) ? AObject->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TSBObjectList::FindInstanceOf(TClassHandle AClass, bool AExact, int32_t AStartAt)
{
	int32_t OutResult;
	SBCheckError(TSBObjectList_FindInstanceOf(_Handle, AClass, (int8_t)AExact, AStartAt, &OutResult));
	return OutResult;
}

SB_INLINE TObjectHandle TSBObjectList::Extract(TObject &Item)
{
	TObjectHandle OutResult;
	SBCheckError(TSBObjectList_Extract(_Handle, Item.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TObjectHandle TSBObjectList::Extract(TObject *Item)
{
	TObjectHandle OutResult;
	SBCheckError(TSBObjectList_Extract(_Handle, (Item != NULL) ? Item->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

bool TSBObjectList::get_OwnsObjects()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TSBObjectList_get_OwnsObjects(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TSBObjectList::set_OwnsObjects(bool Value)
{
	SBCheckError(TSBObjectList_set_OwnsObjects(_Handle, (int8_t)Value));
}

TObject* TSBObjectList::get_Items_TObject(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TSBObjectList_get_Items_TObject(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TObject(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}

SB_INLINE void TSBObjectList::set_Items_TObject(int32_t Index, TObject &AObject)
{
	SBCheckError(TSBObjectList_set_Items_TObject(_Handle, Index, AObject.getHandle()));
}

SB_INLINE void TSBObjectList::set_Items_TObject(int32_t Index, TObject *AObject)
{
	SBCheckError(TSBObjectList_set_Items_TObject(_Handle, Index, (AObject != NULL) ? AObject->getHandle() : SB_NULL_HANDLE));
}

void TSBObjectList::initInstances()
{
	this->_Inst_Items = NULL;
}

TSBObjectList::TSBObjectList(TSBObjectListHandle handle, TElOwnHandle ownHandle) : TList(handle, ownHandle)
{
	initInstances();
}

TSBObjectList::TSBObjectList() : TList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TSBObjectList_Create(&_Handle));
}

TSBObjectList::TSBObjectList(bool AOwnsObjects) : TList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TSBObjectList_Create_1((int8_t)AOwnsObjects, &_Handle));
}

TSBObjectList::~TSBObjectList()
{
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
}
#endif /* SB_USE_CLASS_TSBOBJECTLIST */

#ifdef SB_USE_CLASS_TELCUSTOMEXCEPTIONHANDLER

TElCustomExceptionHandler::TElCustomExceptionHandler(TElCustomExceptionHandlerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCustomExceptionHandler::TElCustomExceptionHandler() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomExceptionHandler_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMEXCEPTIONHANDLER */

#ifdef SB_USE_CLASS_TELSTANDARDEXCEPTIONHANDLER

TElStandardExceptionHandler::TElStandardExceptionHandler(TElStandardExceptionHandlerHandle handle, TElOwnHandle ownHandle) : TElCustomExceptionHandler(handle, ownHandle)
{
}

TElStandardExceptionHandler::TElStandardExceptionHandler() : TElCustomExceptionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElStandardExceptionHandler_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSTANDARDEXCEPTIONHANDLER */

#ifdef SB_USE_CLASS_TELDEBUGEXCEPTIONHANDLER

TSBExceptionHandlerDestination TElDebugExceptionHandler::get_Destination()
{
	TSBExceptionHandlerDestinationRaw OutResultRaw = 0;
	SBCheckError(TElDebugExceptionHandler_get_Destination(_Handle, &OutResultRaw));
	return (TSBExceptionHandlerDestination)OutResultRaw;
}

SB_INLINE void TElDebugExceptionHandler::set_Destination(TSBExceptionHandlerDestination Value)
{
	SBCheckError(TElDebugExceptionHandler_set_Destination(_Handle, (TSBExceptionHandlerDestinationRaw)Value));
}

TElDebugExceptionHandler::TElDebugExceptionHandler(TElDebugExceptionHandlerHandle handle, TElOwnHandle ownHandle) : TElStandardExceptionHandler(handle, ownHandle)
{
}

TElDebugExceptionHandler::TElDebugExceptionHandler() : TElStandardExceptionHandler(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElDebugExceptionHandler_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELDEBUGEXCEPTIONHANDLER */

#ifdef SB_USE_GLOBAL_PROCS_UTILS

void DigestToStr(const TMessageDigest128 &Digest, bool LowerCase, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_DigestToStr(&Digest, (int8_t)LowerCase, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(349878938, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void DigestToStr(const TMessageDigest160 &Digest, bool LowerCase, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_DigestToStr_1(&Digest, (int8_t)LowerCase, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1678219117, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void DigestToStr(const TMessageDigest224 &Digest, bool LowerCase, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_DigestToStr_2(&Digest, (int8_t)LowerCase, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-23844303, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void DigestToStr(const TMessageDigest256 &Digest, bool LowerCase, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_DigestToStr_3(&Digest, (int8_t)LowerCase, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1572723429, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void DigestToStr(const TMessageDigest320 &Digest, bool LowerCase, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_DigestToStr_4(&Digest, (int8_t)LowerCase, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1487821400, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void DigestToStr(const TMessageDigest384 &Digest, bool LowerCase, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_DigestToStr_5(&Digest, (int8_t)LowerCase, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(680150778, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void DigestToStr(const TMessageDigest512 &Digest, bool LowerCase, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_DigestToStr_6(&Digest, (int8_t)LowerCase, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1685064519, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool StrToDigest(const std::string &DigestStr, TMessageDigest128 &Digest)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_StrToDigest(DigestStr.data(), (int32_t)DigestStr.length(), &Digest, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool StrToDigest(const std::string &DigestStr, TMessageDigest160 &Digest)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_StrToDigest_1(DigestStr.data(), (int32_t)DigestStr.length(), &Digest, &OutResultRaw));
	return (OutResultRaw != 0);
}

void DigestToBinary(const TMessageDigest128 &Digest, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_DigestToBinary(&Digest, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1094320686, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void DigestToBinary(const TMessageDigest160 &Digest, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_DigestToBinary_1(&Digest, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(117450728, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool BinaryToDigest(const std::vector<uint8_t> &Binary, TMessageDigest128 &Digest)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_BinaryToDigest(SB_STD_VECTOR_FRONT_ADR(Binary), (int32_t)Binary.size(), &Digest, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool BinaryToDigest(const std::vector<uint8_t> &Binary, TMessageDigest160 &Digest)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_BinaryToDigest_1(SB_STD_VECTOR_FRONT_ADR(Binary), (int32_t)Binary.size(), &Digest, &OutResultRaw));
	return (OutResultRaw != 0);
}

void DigestToByteArray128(const TMessageDigest128 &Digest, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_DigestToByteArray128(&Digest, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1019061952, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void DigestToByteArray160(const TMessageDigest160 &Digest, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_DigestToByteArray160(&Digest, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(634964728, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void DigestToByteArray224(const TMessageDigest224 &Digest, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_DigestToByteArray224(&Digest, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1643628215, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void DigestToByteArray256(const TMessageDigest256 &Digest, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_DigestToByteArray256(&Digest, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1043238281, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void DigestToByteArray320(const TMessageDigest320 &Digest, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_DigestToByteArray320(&Digest, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1429333682, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void DigestToByteArray384(const TMessageDigest384 &Digest, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_DigestToByteArray384(&Digest, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-403097491, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void DigestToByteArray512(const TMessageDigest512 &Digest, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_DigestToByteArray512(&Digest, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2128132076, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool ByteArrayToDigest128(const std::vector<uint8_t> &Binary, int32_t Position, TMessageDigest128 &Digest)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_ByteArrayToDigest128(SB_STD_VECTOR_FRONT_ADR(Binary), (int32_t)Binary.size(), Position, &Digest, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ByteArrayToDigest160(const std::vector<uint8_t> &Binary, int32_t Position, TMessageDigest160 &Digest)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_ByteArrayToDigest160(SB_STD_VECTOR_FRONT_ADR(Binary), (int32_t)Binary.size(), Position, &Digest, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ByteArrayToDigest224(const std::vector<uint8_t> &Binary, int32_t Position, TMessageDigest224 &Digest)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_ByteArrayToDigest224(SB_STD_VECTOR_FRONT_ADR(Binary), (int32_t)Binary.size(), Position, &Digest, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ByteArrayToDigest256(const std::vector<uint8_t> &Binary, int32_t Position, TMessageDigest256 &Digest)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_ByteArrayToDigest256(SB_STD_VECTOR_FRONT_ADR(Binary), (int32_t)Binary.size(), Position, &Digest, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ByteArrayToDigest320(const std::vector<uint8_t> &Binary, int32_t Position, TMessageDigest320 &Digest)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_ByteArrayToDigest320(SB_STD_VECTOR_FRONT_ADR(Binary), (int32_t)Binary.size(), Position, &Digest, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ByteArrayToDigest384(const std::vector<uint8_t> &Binary, int32_t Position, TMessageDigest384 &Digest)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_ByteArrayToDigest384(SB_STD_VECTOR_FRONT_ADR(Binary), (int32_t)Binary.size(), Position, &Digest, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ByteArrayToDigest512(const std::vector<uint8_t> &Binary, int32_t Position, TMessageDigest512 &Digest)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_ByteArrayToDigest512(SB_STD_VECTOR_FRONT_ADR(Binary), (int32_t)Binary.size(), Position, &Digest, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void PointerToLIntP(PLInt &B, void * P, int32_t Size)
{
	SBCheckError(SBUtils_PointerToLIntP(&B, P, Size));
}

SB_INLINE void PointerToLInt(PLInt &B, const std::vector<uint8_t> &P, int32_t Size)
{
	SBCheckError(SBUtils_PointerToLInt(&B, SB_STD_VECTOR_FRONT_ADR(P), (int32_t)P.size(), Size));
}

SB_INLINE void LIntToPointerP(PLInt B, void * P, int32_t &Size)
{
	SBCheckError(SBUtils_LIntToPointerP(B, P, &Size));
}

SB_INLINE void LIntToPointer(PLInt B, const std::vector<uint8_t> &P, int32_t &Size)
{
	SBCheckError(SBUtils_LIntToPointer(B, SB_STD_VECTOR_FRONT_ADR(P), (int32_t)P.size(), &Size));
}

SB_INLINE void LIntToPointerTrunc(PLInt B, void * P, int32_t &Size)
{
	SBCheckError(SBUtils_LIntToPointerTrunc(B, P, &Size));
}

SB_INLINE int32_t BufferBitCount(void * Buffer, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(SBUtils_BufferBitCount(Buffer, Size, &OutResult));
	return OutResult;
}

void BeautifyBinaryString(const std::string &Str, char Separator, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_BeautifyBinaryString(Str.data(), (int32_t)Str.length(), Separator, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1377148697, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SwapUInt16(uint16_t Value, std::vector<uint8_t> &Buffer)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBUtils_SwapUInt16(Value, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-2143185226, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

void SwapUInt16(uint16_t Value, std::vector<uint8_t> &Buffer, int32_t &Index)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBUtils_SwapUInt16_1(Value, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, &Index);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(1847419699, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

SB_INLINE uint16_t SwapUInt16(const std::vector<uint8_t> &Buffer, uint32_t Offset)
{
	uint16_t OutResult;
	SBCheckError(SBUtils_SwapUInt16_2(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Offset, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SwapInt32(int32_t value)
{
	int32_t OutResult;
	SBCheckError(SBUtils_SwapInt32(value, &OutResult));
	return OutResult;
}

void SwapUInt32(uint32_t Value, std::vector<uint8_t> &Buffer)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBUtils_SwapUInt32(Value, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-834836930, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

void SwapUInt32(uint32_t Value, std::vector<uint8_t> &Buffer, int32_t &Index)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBUtils_SwapUInt32_1(Value, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, &Index);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(295627799, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

SB_INLINE uint32_t SwapUInt32(const std::vector<uint8_t> &Buffer, uint32_t Offset)
{
	uint32_t OutResult;
	SBCheckError(SBUtils_SwapUInt32_2(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Offset, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t SwapUInt32(uint32_t value)
{
	uint32_t OutResult;
	SBCheckError(SBUtils_SwapUInt32_3(value, &OutResult));
	return OutResult;
}

SB_INLINE int64_t SwapInt64(int64_t value)
{
	int64_t OutResult;
	SBCheckError(SBUtils_SwapInt64(value, &OutResult));
	return OutResult;
}

void SwapSomeInt(int32_t Value, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_SwapSomeInt(Value, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1256271529, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void RotateInteger(const std::vector<uint8_t> &Value, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_RotateInteger(SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-36907580, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TrimZeros(const std::vector<uint8_t> &Value, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_TrimZeros(SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-437078919, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ZeroArray(int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_ZeroArray(Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(855703600, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SubArray(const std::vector<uint8_t> &Arr, int32_t Index, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_SubArray(SB_STD_VECTOR_FRONT_ADR(Arr), (int32_t)Arr.size(), Index, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1643769167, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void SwapBigEndianWords(void * P, int32_t Size)
{
	SBCheckError(SBUtils_SwapBigEndianWords(P, Size));
}

SB_INLINE void SwapBigEndianDWords(void * P, int32_t Size)
{
	SBCheckError(SBUtils_SwapBigEndianDWords(P, Size));
}

bool IsEmptyDateTime(int64_t DT)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_IsEmptyDateTime(DT, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t EmptyDateTime()
{
	int64_t OutResult;
	SBCheckError(SBUtils_EmptyDateTime(&OutResult));
	return OutResult;
}

SB_INLINE void SBMove(const void * SourcePointer, void * DestinationPointer, int32_t CopyCount)
{
	SBCheckError(SBUtils_SBMove(SourcePointer, DestinationPointer, CopyCount));
}

SB_INLINE void SBMove(const std::vector<uint8_t> &Src, int32_t SrcOffset, const std::vector<uint8_t> &Dst, int32_t DstOffset, int32_t Size)
{
	SBCheckError(SBUtils_SBMove_1(SB_STD_VECTOR_FRONT_ADR(Src), (int32_t)Src.size(), SrcOffset, SB_STD_VECTOR_FRONT_ADR(Dst), (int32_t)Dst.size(), DstOffset, Size));
}

void TrimLeadingZeros(const std::vector<uint8_t> &V, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_TrimLeadingZeros(SB_STD_VECTOR_FRONT_ADR(V), (int32_t)V.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1638168559, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TrimTrailingZeros(const std::vector<uint8_t> &V, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_TrimTrailingZeros(SB_STD_VECTOR_FRONT_ADR(V), (int32_t)V.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1291610793, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void PrefixByteArray(const std::vector<uint8_t> &Buffer, int32_t Count, uint8_t Value, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_PrefixByteArray(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Count, Value, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(179891833, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SuffixByteArray(const std::vector<uint8_t> &Buffer, int32_t Count, uint8_t Value, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_SuffixByteArray(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Count, Value, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(154026450, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void FillByteArray(const std::vector<uint8_t> &Buffer, int32_t SrcOffset, int32_t Count, uint8_t Value)
{
	SBCheckError(SBUtils_FillByteArray(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), SrcOffset, Count, Value));
}

SB_INLINE void FillByteArray(const std::vector<uint8_t> &Buffer, uint8_t Value)
{
	SBCheckError(SBUtils_FillByteArray_1(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Value));
}

void GetBytes64(int64_t X, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_GetBytes64(X, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1489022411, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void GetBytes64(int64_t X, std::vector<uint8_t> &Buffer, int32_t Index)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBUtils_GetBytes64_1(X, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(191613255, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

void GetBytes32(uint32_t X, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_GetBytes32(X, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(272747253, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void GetBytes32(uint32_t X, std::vector<uint8_t> &Buffer, int32_t Index)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBUtils_GetBytes32_1(X, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(1750216342, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

void GetBytes16(uint16_t X, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_GetBytes16(X, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(247158414, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void GetBytes16(uint16_t X, std::vector<uint8_t> &Buffer, int32_t Index)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBUtils_GetBytes16_1(X, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-623268732, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

void GetBytes8(uint8_t X, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_GetBytes8(X, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-990947127, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void GetBytes8(uint8_t X, std::vector<uint8_t> &Buffer, int32_t Index)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBUtils_GetBytes8_1(X, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-1660639562, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

SB_INLINE int64_t LocalDateTimeToSystemDateTime(int64_t ADateTime)
{
	int64_t OutResult;
	SBCheckError(SBUtils_LocalDateTimeToSystemDateTime(ADateTime, &OutResult));
	return OutResult;
}

SB_INLINE int64_t SystemDateTimeToLocalDateTime(int64_t ADateTime)
{
	int64_t OutResult;
	SBCheckError(SBUtils_SystemDateTimeToLocalDateTime(ADateTime, &OutResult));
	return OutResult;
}

SB_INLINE int64_t DateTimeAddMillis(int64_t DateTime, int32_t Millis)
{
	int64_t OutResult;
	SBCheckError(SBUtils_DateTimeAddMillis(DateTime, Millis, &OutResult));
	return OutResult;
}

SB_INLINE int64_t DateTimeAddDays(int64_t DateTime, int32_t Days)
{
	int64_t OutResult;
	SBCheckError(SBUtils_DateTimeAddDays(DateTime, Days, &OutResult));
	return OutResult;
}

SB_INLINE int64_t DateTimeAddHours(int64_t DateTime, int32_t Hours)
{
	int64_t OutResult;
	SBCheckError(SBUtils_DateTimeAddHours(DateTime, Hours, &OutResult));
	return OutResult;
}

SB_INLINE int64_t DateTimeAddMinutes(int64_t DateTime, int32_t Minutes)
{
	int64_t OutResult;
	SBCheckError(SBUtils_DateTimeAddMinutes(DateTime, Minutes, &OutResult));
	return OutResult;
}

SB_INLINE int64_t DateTimeAddSeconds(int64_t DateTime, int32_t Seconds)
{
	int64_t OutResult;
	SBCheckError(SBUtils_DateTimeAddSeconds(DateTime, Seconds, &OutResult));
	return OutResult;
}

SB_INLINE int64_t DateTimeAddYears(int64_t DateTime, int32_t Years)
{
	int64_t OutResult;
	SBCheckError(SBUtils_DateTimeAddYears(DateTime, Years, &OutResult));
	return OutResult;
}

bool DateTimeAfter(int64_t DT1, int64_t DT2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_DateTimeAfter(DT1, DT2, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool DateTimeBefore(int64_t DT1, int64_t DT2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_DateTimeBefore(DT1, DT2, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t DateTimeClone(int64_t DateTime)
{
	int64_t OutResult;
	SBCheckError(SBUtils_DateTimeClone(DateTime, &OutResult));
	return OutResult;
}

SB_INLINE int32_t DateTimeCompare(int64_t DT1, int64_t DT2)
{
	int32_t OutResult;
	SBCheckError(SBUtils_DateTimeCompare(DT1, DT2, &OutResult));
	return OutResult;
}

bool DateTimeEquals(int64_t DT1, int64_t DT2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_DateTimeEquals(DT1, DT2, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t DateTimeGetMonth(int64_t DT)
{
	int32_t OutResult;
	SBCheckError(SBUtils_DateTimeGetMonth(DT, &OutResult));
	return OutResult;
}

SB_INLINE int32_t DateTimeGetYear(int64_t DT)
{
	int32_t OutResult;
	SBCheckError(SBUtils_DateTimeGetYear(DT, &OutResult));
	return OutResult;
}

bool DateTimeIsLeapYear(int32_t Year)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_DateTimeIsLeapYear(Year, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool DateTimeIsLeapYear(int64_t DT)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_DateTimeIsLeapYear_1(DT, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t DateTimeNow()
{
	int64_t OutResult;
	SBCheckError(SBUtils_DateTimeNow(&OutResult));
	return OutResult;
}

void DateTimeToString(int64_t DateTime, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_DateTimeToString(DateTime, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1602861865, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t DateTimeUtcNow()
{
	int64_t OutResult;
	SBCheckError(SBUtils_DateTimeUtcNow(&OutResult));
	return OutResult;
}

bool CompareMem(const std::vector<uint8_t> &Mem1, const std::vector<uint8_t> &Mem2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_CompareMem(SB_STD_VECTOR_FRONT_ADR(Mem1), (int32_t)Mem1.size(), SB_STD_VECTOR_FRONT_ADR(Mem2), (int32_t)Mem2.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CompareMem(const std::vector<uint8_t> &Mem1, int32_t Offset1, const std::vector<uint8_t> &Mem2, int32_t Offset2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_CompareMem_1(SB_STD_VECTOR_FRONT_ADR(Mem1), (int32_t)Mem1.size(), Offset1, SB_STD_VECTOR_FRONT_ADR(Mem2), (int32_t)Mem2.size(), Offset2, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CompareMem(const std::vector<uint8_t> &Mem1, int32_t Offset1, const std::vector<uint8_t> &Mem2, int32_t Offset2, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_CompareMem_2(SB_STD_VECTOR_FRONT_ADR(Mem1), (int32_t)Mem1.size(), Offset1, SB_STD_VECTOR_FRONT_ADR(Mem2), (int32_t)Mem2.size(), Offset2, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CompareMem(const void * Mem1, const void * Mem2, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_CompareMem_3(Mem1, Mem2, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t CompareBuffers(const std::vector<uint8_t> &Buf1, const std::vector<uint8_t> &Buf2)
{
	int32_t OutResult;
	SBCheckError(SBUtils_CompareBuffers(SB_STD_VECTOR_FRONT_ADR(Buf1), (int32_t)Buf1.size(), SB_STD_VECTOR_FRONT_ADR(Buf2), (int32_t)Buf2.size(), &OutResult));
	return OutResult;
}

bool CompareMD128(const TMessageDigest128 &M1, const TMessageDigest128 &M2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_CompareMD128(&M1, &M2, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CompareMD160(const TMessageDigest160 &M1, const TMessageDigest160 &M2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_CompareMD160(&M1, &M2, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CompareMD224(const TMessageDigest224 &M1, const TMessageDigest224 &M2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_CompareMD224(&M1, &M2, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CompareMD256(const TMessageDigest256 &M1, const TMessageDigest256 &M2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_CompareMD256(&M1, &M2, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CompareMD320(const TMessageDigest320 &M1, const TMessageDigest320 &M2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_CompareMD320(&M1, &M2, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CompareMD384(const TMessageDigest384 &M1, const TMessageDigest384 &M2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_CompareMD384(&M1, &M2, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CompareMD512(const TMessageDigest512 &M1, const TMessageDigest512 &M2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_CompareMD512(&M1, &M2, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CompareHashes(const std::vector<uint8_t> &Hash1, const std::vector<uint8_t> &Hash2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_CompareHashes(SB_STD_VECTOR_FRONT_ADR(Hash1), (int32_t)Hash1.size(), SB_STD_VECTOR_FRONT_ADR(Hash2), (int32_t)Hash2.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CompareHashes(const std::vector<uint8_t> &Hash1, int32_t StartIndex1, int32_t Count1, const std::vector<uint8_t> &Hash2, int32_t StartIndex2, int32_t Count2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_CompareHashes_1(SB_STD_VECTOR_FRONT_ADR(Hash1), (int32_t)Hash1.size(), StartIndex1, Count1, SB_STD_VECTOR_FRONT_ADR(Hash2), (int32_t)Hash2.size(), StartIndex2, Count2, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void FreeAndNil(void * Obj)
{
	SBCheckError(SBUtils_FreeAndNil(Obj));
}

SB_INLINE int32_t GetDigestSizeBits(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(SBUtils_GetDigestSizeBits(Algorithm, &OutResult));
	return OutResult;
}

bool EncodeDSASignature(void * R, int32_t RSize, void * S, int32_t SSize, void * Blob, int32_t &BlobSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_EncodeDSASignature(R, RSize, S, SSize, Blob, &BlobSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool DecodeDSASignature(void * Blob, int32_t Size, void * R, int32_t &RSize, void * S, int32_t &SSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_DecodeDSASignature(Blob, Size, R, &RSize, S, &SSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CompareAnsiStr(const std::string &Content, const std::string &OID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_CompareAnsiStr(Content.data(), (int32_t)Content.length(), OID.data(), (int32_t)OID.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void ChangeByteOrder(const std::vector<uint8_t> &Buffer, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_ChangeByteOrder(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(311519772, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void BinaryToString(const std::vector<uint8_t> &Buffer, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_BinaryToString(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1305723702, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void BinaryToString(const std::vector<uint8_t> &Buffer, int32_t Start, int32_t Count, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_BinaryToString_1(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Start, Count, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1122618405, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void BinaryToString(void * Buffer, int32_t BufSize, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_BinaryToString_2(Buffer, BufSize, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-470870463, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool StringToBinary(const std::string &S, void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_StringToBinary(S.data(), (int32_t)S.length(), Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CompareGUID(const TGuid &Guid1, const TGuid &Guid2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_CompareGUID(&Guid1, &Guid2, &OutResultRaw));
	return (OutResultRaw != 0);
}

void AnsiStringOfBytes(const std::vector<uint8_t> &Src, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_AnsiStringOfBytes(SB_STD_VECTOR_FRONT_ADR(Src), (int32_t)Src.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1378782394, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool ArrayStartsWith(const std::vector<uint8_t> &SubP, const std::vector<uint8_t> &P)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_ArrayStartsWith(SB_STD_VECTOR_FRONT_ADR(SubP), (int32_t)SubP.size(), SB_STD_VECTOR_FRONT_ADR(P), (int32_t)P.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t CompareArrays(const std::vector<uint8_t> &Buf1, const std::vector<uint8_t> &Buf2)
{
	int32_t OutResult;
	SBCheckError(SBUtils_CompareArrays(SB_STD_VECTOR_FRONT_ADR(Buf1), (int32_t)Buf1.size(), SB_STD_VECTOR_FRONT_ADR(Buf2), (int32_t)Buf2.size(), &OutResult));
	return OutResult;
}

void StringOfBytes(const std::vector<uint8_t> &Src, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_StringOfBytes(SB_STD_VECTOR_FRONT_ADR(Src), (int32_t)Src.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(186355104, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void StringOfBytes(const std::vector<uint8_t> &Src, int32_t ALow, int32_t ALen, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_StringOfBytes_1(SB_STD_VECTOR_FRONT_ADR(Src), (int32_t)Src.size(), ALow, ALen, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1516068264, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void BytesOfString(const std::string &Str, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_BytesOfString(Str.data(), (int32_t)Str.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1215290925, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void CreateByteArrayConst(const std::string &Src, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_CreateByteArrayConst(Src.data(), (int32_t)Src.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(700284479, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void AnsiStringOfString(const std::string &Str, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_AnsiStringOfString(Str.data(), (int32_t)Str.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2059271177, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void StringOfAnsiString(const std::string &Str, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_StringOfAnsiString(Str.data(), (int32_t)Str.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-131376200, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void BytesOfAnsiString(const std::string &Str, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_BytesOfAnsiString(Str.data(), (int32_t)Str.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1698864356, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void GetByteArrayFromByte(uint8_t Value, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_GetByteArrayFromByte(Value, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(40203230, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void GetByteArrayFromByte(uint8_t Value, const std::vector<uint8_t> &Dest, int32_t Position)
{
	SBCheckError(SBUtils_GetByteArrayFromByte_1(Value, SB_STD_VECTOR_FRONT_ADR(Dest), (int32_t)Dest.size(), Position));
}

void GetByteArrayFromWordLE(uint16_t Value, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_GetByteArrayFromWordLE(Value, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1946958969, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void GetByteArrayFromWordLE(uint16_t Value, const std::vector<uint8_t> &Dest, int32_t Position)
{
	SBCheckError(SBUtils_GetByteArrayFromWordLE_1(Value, SB_STD_VECTOR_FRONT_ADR(Dest), (int32_t)Dest.size(), Position));
}

void GetByteArrayFromWordBE(uint16_t Value, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_GetByteArrayFromWordBE(Value, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(891864303, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void GetByteArrayFromWordBE(uint16_t Value, const std::vector<uint8_t> &Dest, int32_t Position)
{
	SBCheckError(SBUtils_GetByteArrayFromWordBE_1(Value, SB_STD_VECTOR_FRONT_ADR(Dest), (int32_t)Dest.size(), Position));
}

void GetByteArrayFromDWordLE(uint32_t Value, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_GetByteArrayFromDWordLE(Value, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(834427421, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void GetByteArrayFromDWordLE(uint32_t Value, const std::vector<uint8_t> &Dest, int32_t Position)
{
	SBCheckError(SBUtils_GetByteArrayFromDWordLE_1(Value, SB_STD_VECTOR_FRONT_ADR(Dest), (int32_t)Dest.size(), Position));
}

void GetByteArrayFromDWordBE(uint32_t Value, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_GetByteArrayFromDWordBE(Value, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-495757651, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void GetByteArrayFromDWordBE(uint32_t Value, const std::vector<uint8_t> &Dest, int32_t Position)
{
	SBCheckError(SBUtils_GetByteArrayFromDWordBE_1(Value, SB_STD_VECTOR_FRONT_ADR(Dest), (int32_t)Dest.size(), Position));
}

void GetByteArrayFromInt64LE(int64_t Value, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_GetByteArrayFromInt64LE(Value, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1222587545, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void GetByteArrayFromInt64LE(int64_t Value, const std::vector<uint8_t> &Dest, int32_t Position)
{
	SBCheckError(SBUtils_GetByteArrayFromInt64LE_1(Value, SB_STD_VECTOR_FRONT_ADR(Dest), (int32_t)Dest.size(), Position));
}

void GetByteArrayFromInt64BE(int64_t Value, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_GetByteArrayFromInt64BE(Value, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1374823952, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void GetByteArrayFromInt64BE(int64_t Value, const std::vector<uint8_t> &Dest, int32_t Position)
{
	SBCheckError(SBUtils_GetByteArrayFromInt64BE_1(Value, SB_STD_VECTOR_FRONT_ADR(Dest), (int32_t)Dest.size(), Position));
}

SB_INLINE uint16_t GetWordLEFromByteArray(const std::vector<uint8_t> &Source, int32_t Position)
{
	uint16_t OutResult;
	SBCheckError(SBUtils_GetWordLEFromByteArray(SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), Position, &OutResult));
	return OutResult;
}

SB_INLINE uint16_t GetWordBEFromByteArray(const std::vector<uint8_t> &Source, int32_t Position)
{
	uint16_t OutResult;
	SBCheckError(SBUtils_GetWordBEFromByteArray(SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), Position, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t GetDWordLEFromByteArray(const std::vector<uint8_t> &Source, int32_t Position)
{
	uint32_t OutResult;
	SBCheckError(SBUtils_GetDWordLEFromByteArray(SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), Position, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t GetDWordBEFromByteArray(const std::vector<uint8_t> &Source, int32_t Position)
{
	uint32_t OutResult;
	SBCheckError(SBUtils_GetDWordBEFromByteArray(SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), Position, &OutResult));
	return OutResult;
}

SB_INLINE int64_t GetInt64LEFromByteArray(const std::vector<uint8_t> &Source, int32_t Position)
{
	int64_t OutResult;
	SBCheckError(SBUtils_GetInt64LEFromByteArray(SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), Position, &OutResult));
	return OutResult;
}

SB_INLINE int64_t GetInt64BEFromByteArray(const std::vector<uint8_t> &Source, int32_t Position)
{
	int64_t OutResult;
	SBCheckError(SBUtils_GetInt64BEFromByteArray(SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), Position, &OutResult));
	return OutResult;
}

void WideStringOf(const std::vector<uint8_t> &Value, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_WideStringOf(SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-768215152, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void WideStringOf(const std::vector<uint8_t> &Value, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBUtils_WideStringOf(SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-768215152, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void WideBytesOf(const sb_u16string &Value, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_WideBytesOf(Value.data(), (int32_t)Value.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(209870186, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void WideBytesOf(const std::wstring &Value, std::vector<uint8_t> &OutResult)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_WideBytesOf(reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(209870186, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_U16STRING_USED */

void EmptyAnsiString(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_EmptyAnsiString((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(370153900, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SBConcatArrays(const std::vector<uint8_t> &Buf1, const std::vector<uint8_t> &Buf2, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_SBConcatArrays(SB_STD_VECTOR_FRONT_ADR(Buf1), (int32_t)Buf1.size(), SB_STD_VECTOR_FRONT_ADR(Buf2), (int32_t)Buf2.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-834541946, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SBConcatArrays(const std::vector<uint8_t> &Buf1, const std::vector<uint8_t> &Buf2, const std::vector<uint8_t> &Buf3, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_SBConcatArrays_1(SB_STD_VECTOR_FRONT_ADR(Buf1), (int32_t)Buf1.size(), SB_STD_VECTOR_FRONT_ADR(Buf2), (int32_t)Buf2.size(), SB_STD_VECTOR_FRONT_ADR(Buf3), (int32_t)Buf3.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1206072546, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SBConcatArrays(const std::vector<uint8_t> &Buf1, uint8_t Buf2, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_SBConcatArrays_2(SB_STD_VECTOR_FRONT_ADR(Buf1), (int32_t)Buf1.size(), Buf2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-993808878, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SBConcatArrays(uint8_t Buf1, const std::vector<uint8_t> &Buf2, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_SBConcatArrays_3(Buf1, SB_STD_VECTOR_FRONT_ADR(Buf2), (int32_t)Buf2.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-184156563, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SBConcatArrays(uint8_t Buf1, uint8_t Buf2, const std::vector<uint8_t> &Buf3, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_SBConcatArrays_4(Buf1, Buf2, SB_STD_VECTOR_FRONT_ADR(Buf3), (int32_t)Buf3.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-569433315, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SBConcatArrays(uint8_t Buf1, const std::vector<uint8_t> &Buf2, const std::vector<uint8_t> &Buf3, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBUtils_SBConcatArrays_5(Buf1, SB_STD_VECTOR_FRONT_ADR(Buf2), (int32_t)Buf2.size(), SB_STD_VECTOR_FRONT_ADR(Buf3), (int32_t)Buf3.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1739972686, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool ArrayEndsWith(const std::vector<uint8_t> &Buffer, const std::vector<uint8_t> &Substr)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_ArrayEndsWith(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), SB_STD_VECTOR_FRONT_ADR(Substr), (int32_t)Substr.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool DateStrToDate(const std::string &Time, int64_t &ADateTime)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_DateStrToDate(Time.data(), (int32_t)Time.length(), &ADateTime, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ParseRFC822TimeString(const std::string &RFC822TimeString, int64_t &ADateTime)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_ParseRFC822TimeString(RFC822TimeString.data(), (int32_t)RFC822TimeString.length(), &ADateTime, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t RFC822TimeToDateTime(const std::string &RFC822Time)
{
	int64_t OutResult;
	SBCheckError(SBUtils_RFC822TimeToDateTime(RFC822Time.data(), (int32_t)RFC822Time.length(), &OutResult));
	return OutResult;
}

SB_INLINE int64_t UTCTimeToDate(const std::string &UTCTime, bool FourDigitYear)
{
	int64_t OutResult;
	SBCheckError(SBUtils_UTCTimeToDate(UTCTime.data(), (int32_t)UTCTime.length(), (int8_t)FourDigitYear, &OutResult));
	return OutResult;
}

SB_INLINE int64_t UTCTimeToTime(const std::string &UTCTime, bool FourDigitYear)
{
	int64_t OutResult;
	SBCheckError(SBUtils_UTCTimeToTime(UTCTime.data(), (int32_t)UTCTime.length(), (int8_t)FourDigitYear, &OutResult));
	return OutResult;
}

SB_INLINE int64_t UTCTimeToDateTime(const std::string &UTCTime, bool FourDigitYear)
{
	int64_t OutResult;
	SBCheckError(SBUtils_UTCTimeToDateTime(UTCTime.data(), (int32_t)UTCTime.length(), (int8_t)FourDigitYear, &OutResult));
	return OutResult;
}

SB_INLINE int64_t GeneralizedTimeToDate(const std::string &GenTime)
{
	int64_t OutResult;
	SBCheckError(SBUtils_GeneralizedTimeToDate(GenTime.data(), (int32_t)GenTime.length(), &OutResult));
	return OutResult;
}

SB_INLINE int64_t GeneralizedTimeToTime(const std::string &GenTime)
{
	int64_t OutResult;
	SBCheckError(SBUtils_GeneralizedTimeToTime(GenTime.data(), (int32_t)GenTime.length(), &OutResult));
	return OutResult;
}

SB_INLINE int64_t GeneralizedTimeToDateTime(const std::string &GenTime)
{
	int64_t OutResult;
	SBCheckError(SBUtils_GeneralizedTimeToDateTime(GenTime.data(), (int32_t)GenTime.length(), &OutResult));
	return OutResult;
}

void DateTimeToUTCTime(int64_t ADateTime, bool FourDigitYear, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_DateTimeToUTCTime(ADateTime, (int8_t)FourDigitYear, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1703632596, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void DateTimeToGeneralizedTime(int64_t ADateTime, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_DateTimeToGeneralizedTime(ADateTime, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2132420721, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void DateTimeToGeneralizedTime(int64_t ADateTime, const std::string &DateTimeSplitPtn, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_DateTimeToGeneralizedTime_1(ADateTime, DateTimeSplitPtn.data(), (int32_t)DateTimeSplitPtn.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(473367156, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void UniversalDateTimeToRFC822DateTimeString(int64_t DT, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_UniversalDateTimeToRFC822DateTimeString(DT, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(319177019, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool RFC822TimeStringToUniversalTime(const std::string &TS, int64_t &DT)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_RFC822TimeStringToUniversalTime(TS.data(), (int32_t)TS.length(), &DT, &OutResultRaw));
	return (OutResultRaw != 0);
}

void LocalDateTimeToRFC822DateTimeString(int64_t ADateTime, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_LocalDateTimeToRFC822DateTimeString(ADateTime, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-823938919, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SystemDateTimeToRFC822DateTimeString(int64_t ADateTime, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_SystemDateTimeToRFC822DateTimeString(ADateTime, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(671805795, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_WINDOWS
SB_INLINE int64_t FileTimeToDateTime(windows_FILETIME &Value)
#else
SB_INLINE int64_t FileTimeToUnixTime(_FILETIME &Value)
#endif
{
	int64_t OutResult;
#ifndef SB_WINDOWS
	SBCheckError(SBUtils_FileTimeToUnixTime(&Value, &OutResult));
	return OutResult;
}

SB_INLINE void UnixTimeToFileTime(int64_t Value, _FILETIME &OutResult)
{
	SBCheckError(SBUtils_UnixTimeToFileTime(Value, &OutResult));
}

SB_INLINE int64_t FileTimeToDateTime(_FILETIME &Value)
{
	int64_t OutResult;
#endif
	SBCheckError(SBUtils_FileTimeToDateTime(&Value, &OutResult));
	return OutResult;
}

#ifdef SB_WINDOWS
SB_INLINE void DateTimeToFileTime(int64_t Value, windows_FILETIME &OutResult)
#else
SB_INLINE void DateTimeToFileTime(int64_t Value, _FILETIME &OutResult)
#endif
{
	SBCheckError(SBUtils_DateTimeToFileTime(Value, &OutResult));
}

SB_INLINE int64_t UnixTimeToDateTime(int64_t Value)
{
	int64_t OutResult;
	SBCheckError(SBUtils_UnixTimeToDateTime(Value, &OutResult));
	return OutResult;
}

SB_INLINE int64_t DateTimeToUnixTime(int64_t Value)
{
	int64_t OutResult;
	SBCheckError(SBUtils_DateTimeToUnixTime(Value, &OutResult));
	return OutResult;
}

SB_INLINE int32_t ConstLength(const std::vector<uint8_t> &Arr)
{
	int32_t OutResult;
	SBCheckError(SBUtils_ConstLength(SB_STD_VECTOR_FRONT_ADR(Arr), (int32_t)Arr.size(), &OutResult));
	return OutResult;
}

SB_INLINE uint32_t TickDiff(uint32_t Previous, uint32_t Current)
{
	uint32_t OutResult;
	SBCheckError(SBUtils_TickDiff(Previous, Current, &OutResult));
	return OutResult;
}

void GenerateGUID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_GenerateGUID((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1578346608, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool IsTextualOID(const std::string &S)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_IsTextualOID(S.data(), (int32_t)S.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_WINDOWS
SB_INLINE uint32_t WaitFor(uint32_t Handle)
#else
SB_INLINE uint32_t GetTickCount()
#endif
{
	uint32_t OutResult;
#ifdef SB_WINDOWS
	SBCheckError(SBUtils_WaitFor(Handle, &OutResult));
#else
	SBCheckError(SBUtils_GetTickCount(&OutResult));
#endif
	return OutResult;
}

#ifndef SB_WINDOWS
#ifdef SB_USE_CLASS_TTHREAD
SB_INLINE uint32_t WaitFor(TThread &Thread)
{
	uint32_t OutResult;
	SBCheckError(SBUtils_WaitFor(Thread.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE uint32_t WaitFor(TThread *Thread)
{
	uint32_t OutResult;
	SBCheckError(SBUtils_WaitFor((Thread != NULL) ? Thread->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TTHREAD */
#endif

SB_INLINE int64_t LocalTimeToUTCTime(int64_t LocalTime)
{
	int64_t OutResult;
	SBCheckError(SBUtils_LocalTimeToUTCTime(LocalTime, &OutResult));
	return OutResult;
}

SB_INLINE int64_t UTCTimeToLocalTime(int64_t UtcTime)
{
	int64_t OutResult;
	SBCheckError(SBUtils_UTCTimeToLocalTime(UtcTime, &OutResult));
	return OutResult;
}

SB_INLINE int64_t UTCNow()
{
	int64_t OutResult;
	SBCheckError(SBUtils_UTCNow(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TOBJECT
SB_INLINE void RegisterGlobalObject(TObject &O)
{
	SBCheckError(SBUtils_RegisterGlobalObject(O.getHandle()));
}
SB_INLINE void RegisterGlobalObject(TObject *O)
{
	SBCheckError(SBUtils_RegisterGlobalObject((O != NULL) ? O->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TOBJECT */

#ifdef SB_USE_CLASS_TOBJECT
SB_INLINE void UnregisterGlobalObject(TObject &O)
{
	SBCheckError(SBUtils_UnregisterGlobalObject(O.getHandle()));
}
SB_INLINE void UnregisterGlobalObject(TObject *O)
{
	SBCheckError(SBUtils_UnregisterGlobalObject((O != NULL) ? O->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TOBJECT */

SB_INLINE void CleanupRegisteredGlobalObjects()
{
	SBCheckError(SBUtils_CleanupRegisteredGlobalObjects());
}

SB_INLINE void AcquireGlobalLock()
{
	SBCheckError(SBUtils_AcquireGlobalLock());
}

SB_INLINE void ReleaseGlobalLock()
{
	SBCheckError(SBUtils_ReleaseGlobalLock());
}

void HexDump(const std::vector<uint8_t> &Buffer, uint32_t Offset, uint32_t Len, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_HexDump(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Offset, Len, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1874064255, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void HexDump(const std::vector<uint8_t> &Buffer, uint32_t Offset, uint32_t Len, bool AddChars, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_HexDump_1(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Offset, Len, (int8_t)AddChars, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-865532511, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool SBSameDateTime(int64_t A, int64_t B)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_SBSameDateTime(A, B, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool SBSameDate(int64_t A, int64_t B)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_SBSameDate(A, B, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool SBSameTime(int64_t A, int64_t B)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_SBSameTime(A, B, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t SBEncodeDateTime(int32_t Year, int32_t Month, int32_t Day, int32_t Hour, int32_t Minute, int32_t Second, int32_t Millisecond)
{
	int64_t OutResult;
	SBCheckError(SBUtils_SBEncodeDateTime(Year, Month, Day, Hour, Minute, Second, Millisecond, &OutResult));
	return OutResult;
}

SB_INLINE int64_t GetUTCOffsetDateTime()
{
	int64_t OutResult;
	SBCheckError(SBUtils_GetUTCOffsetDateTime(&OutResult));
	return OutResult;
}

SB_INLINE int64_t GetUTCOffsetDateTime(int64_t ADateTime)
{
	int64_t OutResult;
	SBCheckError(SBUtils_GetUTCOffsetDateTime_1(ADateTime, &OutResult));
	return OutResult;
}

bool CompareContent(const std::vector<uint8_t> &Content, const std::vector<uint8_t> &OID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_CompareContent(SB_STD_VECTOR_FRONT_ADR(Content), (int32_t)Content.size(), SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void DateTimeToISO8601Time(int64_t Time, bool EncodeMilliseconds, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_DateTimeToISO8601Time(Time, (int8_t)EncodeMilliseconds, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(474562419, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t ISO8601TimeToDateTime(const std::string &EncodedTime)
{
	int64_t OutResult;
	SBCheckError(SBUtils_ISO8601TimeToDateTime(EncodedTime.data(), (int32_t)EncodedTime.length(), &OutResult));
	return OutResult;
}

void DateTimeToRFC3339(int64_t Value, bool EncodeMilliseconds, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_DateTimeToRFC3339(Value, (int8_t)EncodeMilliseconds, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1455106995, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void SetLicenseKey(const std::string &Key)
{
	SBCheckError(SBUtils_SetLicenseKey(Key.data(), (int32_t)Key.length()));
}

SB_INLINE void CheckLicenseKey()
{
	SBCheckError(SBUtils_CheckLicenseKey());
}

void GetCompanyName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_GetCompanyName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1550285523, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void GetUserName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_GetUserName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1127740658, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TSBLicenseTypes GetLicense()
{
	TSBLicenseTypesRaw OutResultRaw = 0;
	SBCheckError(SBUtils_GetLicense(&OutResultRaw));
	return (TSBLicenseTypes)OutResultRaw;
}

SB_INLINE int32_t GetVersion()
{
	int32_t OutResult;
	SBCheckError(SBUtils_GetVersion(&OutResult));
	return OutResult;
}

SB_INLINE uint32_t GetTimeLen()
{
	uint32_t OutResult;
	SBCheckError(SBUtils_GetTimeLen(&OutResult));
	return OutResult;
}

SB_INLINE int32_t GetRemainingDays()
{
	int32_t OutResult;
	SBCheckError(SBUtils_GetRemainingDays(&OutResult));
	return OutResult;
}

SB_INLINE void IntCheckA()
{
	SBCheckError(SBUtils_IntCheckA());
}

SB_INLINE void IntCheckB()
{
	SBCheckError(SBUtils_IntCheckB());
}

SB_INLINE void ShowNagScreen()
{
	SBCheckError(SBUtils_ShowNagScreen());
}

void AppendSlash(const std::string &Path, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBUtils_AppendSlash(Path.data(), (int32_t)Path.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(192340390, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool EnsureDirectoryExists(const std::string &DirName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_EnsureDirectoryExists(DirName.data(), (int32_t)DirName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool DirectoryExists(const std::string &DirName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBUtils_DirectoryExists(DirName.data(), (int32_t)DirName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
#ifndef SB_WINDOWS
}

SB_INLINE uint32_t GetCurrentThreadID()
{
	uint32_t OutResult;
	SBCheckError(SBUtils_GetCurrentThreadID(&OutResult));
	return OutResult;
#endif
}

#ifdef SB_USE_CLASS_TELCUSTOMEXCEPTIONHANDLER
SB_INLINE void SetDefaultExceptionHandler(TElCustomExceptionHandler &Handler)
{
	SBCheckError(SBUtils_SetDefaultExceptionHandler(Handler.getHandle()));
}
SB_INLINE void SetDefaultExceptionHandler(TElCustomExceptionHandler *Handler)
{
	SBCheckError(SBUtils_SetDefaultExceptionHandler((Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMEXCEPTIONHANDLER */

#ifdef SB_USE_CLASS_TELCUSTOMEXCEPTIONHANDLER
SB_INLINE TElCustomExceptionHandlerHandle GetDefaultExceptionHandler()
{
	TElCustomExceptionHandlerHandle OutResult;
	SBCheckError(SBUtils_GetDefaultExceptionHandler(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMEXCEPTIONHANDLER */

#endif /* SB_USE_GLOBAL_PROCS_UTILS */

};	/* namespace SecureBlackbox */
