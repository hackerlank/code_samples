#include "sbpgpentities.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPGPENTITY

SB_INLINE void TElPGPEntity::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPEntity_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPEntity::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPEntity_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPEntity::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPEntity_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPEntity::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPEntity_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPEntity::Load(void * AReadUserData, void * AWriteUserData)
{
	SBCheckError(TElPGPEntity_Load(_Handle, AReadUserData, AWriteUserData));
}

SB_INLINE void TElPGPEntity::Save(void * AReadUserData, void * AWriteUserData)
{
	SBCheckError(TElPGPEntity_Save(_Handle, AReadUserData, AWriteUserData));
}

SB_INLINE void TElPGPEntity::DataAvailable()
{
	SBCheckError(TElPGPEntity_DataAvailable(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPEntity::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElPGPEntity_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElPGPEntity::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElPGPEntity_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPEntity::SaveToStream(TStream &Stream)
{
	SBCheckError(TElPGPEntity_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElPGPEntity::SaveToStream(TStream *Stream)
{
	SBCheckError(TElPGPEntity_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE uint32_t TElPGPEntity::get_WriteFlags()
{
	uint32_t OutResult;
	SBCheckError(TElPGPEntity_get_WriteFlags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPEntity::set_WriteFlags(uint32_t Value)
{
	SBCheckError(TElPGPEntity_set_WriteFlags(_Handle, Value));
}

bool TElPGPEntity::get_AsyncMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPEntity_get_AsyncMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPEntity::set_AsyncMode(bool Value)
{
	SBCheckError(TElPGPEntity_set_AsyncMode(_Handle, (int8_t)Value));
}

SB_INLINE uint8_t TElPGPEntity::get_PacketType()
{
	uint8_t OutResult;
	SBCheckError(TElPGPEntity_get_PacketType(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElPGPEntity::get_BytesLeft()
{
	uint32_t OutResult;
	SBCheckError(TElPGPEntity_get_BytesLeft(_Handle, &OutResult));
	return OutResult;
}

bool TElPGPEntity::get_OldPacket()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPEntity_get_OldPacket(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPEntity::set_OldPacket(bool Value)
{
	SBCheckError(TElPGPEntity_set_OldPacket(_Handle, (int8_t)Value));
}

bool TElPGPEntity::get_ForceUndefLenProcessing()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPEntity_get_ForceUndefLenProcessing(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPEntity::set_ForceUndefLenProcessing(bool Value)
{
	SBCheckError(TElPGPEntity_set_ForceUndefLenProcessing(_Handle, (int8_t)Value));
}

SB_INLINE void TElPGPEntity::get_OnRead(TSBPGPReadEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPEntity_get_OnRead(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPEntity::set_OnRead(TSBPGPReadEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPEntity_set_OnRead(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPEntity::get_OnWrite(TSBPGPWriteEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPEntity_get_OnWrite(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPEntity::set_OnWrite(TSBPGPWriteEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPEntity_set_OnWrite(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPEntity::get_OnFinish(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPEntity_get_OnFinish(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPEntity::set_OnFinish(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPEntity_set_OnFinish(_Handle, pMethodValue, pDataValue));
}

TElPGPEntity::TElPGPEntity(TElPGPEntityHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElPGPEntity::TElPGPEntity() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPEntity_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPENTITY */

#ifdef SB_USE_CLASS_TELPGPPUBLICKEYENTITY

SB_INLINE void TElPGPPublicKeyEntity::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPPublicKeyEntity_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPPublicKeyEntity::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPPublicKeyEntity_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPPublicKeyEntity::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPPublicKeyEntity_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPPublicKeyEntity::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPPublicKeyEntity_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELPGPSECRETKEYENTITY
SB_INLINE void TElPGPPublicKeyEntity::AssignFromSecret(TElPGPSecretKeyEntity &Source)
{
	SBCheckError(TElPGPPublicKeyEntity_AssignFromSecret(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPPublicKeyEntity::AssignFromSecret(TElPGPSecretKeyEntity *Source)
{
	SBCheckError(TElPGPPublicKeyEntity_AssignFromSecret(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPSECRETKEYENTITY */

SB_INLINE int64_t TElPGPPublicKeyEntity::get_Timestamp()
{
	int64_t OutResult;
	SBCheckError(TElPGPPublicKeyEntity_get_Timestamp(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPPublicKeyEntity::set_Timestamp(int64_t Value)
{
	SBCheckError(TElPGPPublicKeyEntity_set_Timestamp(_Handle, Value));
}

SB_INLINE int32_t TElPGPPublicKeyEntity::get_Expires()
{
	int32_t OutResult;
	SBCheckError(TElPGPPublicKeyEntity_get_Expires(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPPublicKeyEntity::set_Expires(int32_t Value)
{
	SBCheckError(TElPGPPublicKeyEntity_set_Expires(_Handle, Value));
}

SB_INLINE uint8_t TElPGPPublicKeyEntity::get_PublicKeyAlgorithm()
{
	uint8_t OutResult;
	SBCheckError(TElPGPPublicKeyEntity_get_PublicKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPPublicKeyEntity::set_PublicKeyAlgorithm(uint8_t Value)
{
	SBCheckError(TElPGPPublicKeyEntity_set_PublicKeyAlgorithm(_Handle, Value));
}

void TElPGPPublicKeyEntity::get_KeyMaterial(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPPublicKeyEntity_get_KeyMaterial(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2143582661, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPPublicKeyEntity::set_KeyMaterial(int32_t Index, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPGPPublicKeyEntity_set_KeyMaterial(_Handle, Index, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElPGPPublicKeyEntity::get_Version()
{
	int32_t OutResult;
	SBCheckError(TElPGPPublicKeyEntity_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPPublicKeyEntity::set_Version(int32_t Value)
{
	SBCheckError(TElPGPPublicKeyEntity_set_Version(_Handle, Value));
}

void TElPGPPublicKeyEntity::get_CurveOID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPPublicKeyEntity_get_CurveOID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1046886518, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPPublicKeyEntity::set_CurveOID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPGPPublicKeyEntity_set_CurveOID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE uint8_t TElPGPPublicKeyEntity::get_KDFHashAlgorithm()
{
	uint8_t OutResult;
	SBCheckError(TElPGPPublicKeyEntity_get_KDFHashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPPublicKeyEntity::set_KDFHashAlgorithm(uint8_t Value)
{
	SBCheckError(TElPGPPublicKeyEntity_set_KDFHashAlgorithm(_Handle, Value));
}

SB_INLINE uint8_t TElPGPPublicKeyEntity::get_KEKSymmetricAlgorithm()
{
	uint8_t OutResult;
	SBCheckError(TElPGPPublicKeyEntity_get_KEKSymmetricAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPPublicKeyEntity::set_KEKSymmetricAlgorithm(uint8_t Value)
{
	SBCheckError(TElPGPPublicKeyEntity_set_KEKSymmetricAlgorithm(_Handle, Value));
}

void TElPGPPublicKeyEntity::get_RSAPublicModulus(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPPublicKeyEntity_get_RSAPublicModulus(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-464929834, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPPublicKeyEntity::set_RSAPublicModulus(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPGPPublicKeyEntity_set_RSAPublicModulus(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPGPPublicKeyEntity::get_RSAPublicExponent(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPPublicKeyEntity_get_RSAPublicExponent(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1292567869, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPPublicKeyEntity::set_RSAPublicExponent(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPGPPublicKeyEntity_set_RSAPublicExponent(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPGPPublicKeyEntity::get_DSAPublicPrime(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPPublicKeyEntity_get_DSAPublicPrime(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1853974370, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPPublicKeyEntity::set_DSAPublicPrime(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPGPPublicKeyEntity_set_DSAPublicPrime(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPGPPublicKeyEntity::get_DSAPublicGroupOrder(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPPublicKeyEntity_get_DSAPublicGroupOrder(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-703973587, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPPublicKeyEntity::set_DSAPublicGroupOrder(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPGPPublicKeyEntity_set_DSAPublicGroupOrder(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPGPPublicKeyEntity::get_DSAPublicGroupGenerator(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPPublicKeyEntity_get_DSAPublicGroupGenerator(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(66709867, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPPublicKeyEntity::set_DSAPublicGroupGenerator(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPGPPublicKeyEntity_set_DSAPublicGroupGenerator(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPGPPublicKeyEntity::get_DSAPublicKeyValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPPublicKeyEntity_get_DSAPublicKeyValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(236482564, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPPublicKeyEntity::set_DSAPublicKeyValue(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPGPPublicKeyEntity_set_DSAPublicKeyValue(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPGPPublicKeyEntity::get_ElGamalPrime(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPPublicKeyEntity_get_ElGamalPrime(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(264914878, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPPublicKeyEntity::set_ElGamalPrime(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPGPPublicKeyEntity_set_ElGamalPrime(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPGPPublicKeyEntity::get_ElGamalGroupGenerator(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPPublicKeyEntity_get_ElGamalGroupGenerator(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1386015752, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPPublicKeyEntity::set_ElGamalGroupGenerator(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPGPPublicKeyEntity_set_ElGamalGroupGenerator(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPGPPublicKeyEntity::get_ElGamalPublicKeyValue(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPPublicKeyEntity_get_ElGamalPublicKeyValue(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(330883919, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPPublicKeyEntity::set_ElGamalPublicKeyValue(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPGPPublicKeyEntity_set_ElGamalPublicKeyValue(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPGPPublicKeyEntity::get_ECPublicKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPPublicKeyEntity_get_ECPublicKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1178256258, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPPublicKeyEntity::set_ECPublicKey(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPGPPublicKeyEntity_set_ECPublicKey(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPGPPublicKeyEntity::TElPGPPublicKeyEntity(TElPGPPublicKeyEntityHandle handle, TElOwnHandle ownHandle) : TElPGPEntity(handle, ownHandle)
{
}

TElPGPPublicKeyEntity::TElPGPPublicKeyEntity() : TElPGPEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPPublicKeyEntity_Create(&_Handle));
}

TElPGPPublicKeyEntity::TElPGPPublicKeyEntity(bool Subkey) : TElPGPEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPPublicKeyEntity_Create_1((int8_t)Subkey, &_Handle));
}

#endif /* SB_USE_CLASS_TELPGPPUBLICKEYENTITY */

#ifdef SB_USE_CLASS_TELPGPS2K

SB_INLINE void TElPGPS2K::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPS2K_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPS2K::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPS2K_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPS2K::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPS2K_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPS2K::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPS2K_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElPGPS2K::Load(const std::vector<uint8_t> &Buffer, int32_t Offset)
{
	int32_t OutResult;
	SBCheckError(TElPGPS2K_Load(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Offset, &OutResult));
	return OutResult;
}

void TElPGPS2K::Save(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPS2K_Save(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1526208339, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPGPS2K::GetSymmetricKey(const std::string &Passphrase, int32_t Needed, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPS2K_GetSymmetricKey(_Handle, Passphrase.data(), (int32_t)Passphrase.length(), Needed, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1473138360, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE uint8_t TElPGPS2K::get_S2KType()
{
	uint8_t OutResult;
	SBCheckError(TElPGPS2K_get_S2KType(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPS2K::set_S2KType(uint8_t Value)
{
	SBCheckError(TElPGPS2K_set_S2KType(_Handle, Value));
}

void TElPGPS2K::get_Salt(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPS2K_get_Salt(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1798123008, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPS2K::set_Salt(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPGPS2K_set_Salt(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE uint8_t TElPGPS2K::get_Count()
{
	uint8_t OutResult;
	SBCheckError(TElPGPS2K_get_Count(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPS2K::set_Count(uint8_t Value)
{
	SBCheckError(TElPGPS2K_set_Count(_Handle, Value));
}

SB_INLINE int32_t TElPGPS2K::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPS2K_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPS2K::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElPGPS2K_set_HashAlgorithm(_Handle, Value));
}

TElPGPS2K::TElPGPS2K(TElPGPS2KHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElPGPS2K::TElPGPS2K() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPS2K_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPS2K */

#ifdef SB_USE_CLASS_TELPGPUSERIDENTITY

SB_INLINE void TElPGPUserIDEntity::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPUserIDEntity_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPUserIDEntity::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPUserIDEntity_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPUserIDEntity::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPUserIDEntity_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPUserIDEntity::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPUserIDEntity_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

void TElPGPUserIDEntity::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPUserIDEntity_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1132421911, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPUserIDEntity::set_Name(const std::string &Value)
{
	SBCheckError(TElPGPUserIDEntity_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

TElPGPUserIDEntity::TElPGPUserIDEntity(TElPGPUserIDEntityHandle handle, TElOwnHandle ownHandle) : TElPGPEntity(handle, ownHandle)
{
}

TElPGPUserIDEntity::TElPGPUserIDEntity() : TElPGPEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPUserIDEntity_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPUSERIDENTITY */

#ifdef SB_USE_CLASS_TELPGPUSERATTRSUBPACKET

SB_INLINE void TElPGPUserAttrSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPUserAttrSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPUserAttrSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPUserAttrSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPUserAttrSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPUserAttrSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPUserAttrSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPUserAttrSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

bool TElPGPUserAttrSubpacket::Compare(TElPGPUserAttrSubpacket &Source)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPUserAttrSubpacket_Compare(_Handle, Source.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPUserAttrSubpacket::Compare(TElPGPUserAttrSubpacket *Source)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPUserAttrSubpacket_Compare(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE uint8_t TElPGPUserAttrSubpacket::get_SubpacketType()
{
	uint8_t OutResult;
	SBCheckError(TElPGPUserAttrSubpacket_get_SubpacketType(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPUserAttrSubpacket::set_SubpacketType(uint8_t Value)
{
	SBCheckError(TElPGPUserAttrSubpacket_set_SubpacketType(_Handle, Value));
}

TElPGPUserAttrSubpacket::TElPGPUserAttrSubpacket(TElPGPUserAttrSubpacketHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElPGPUserAttrSubpacket::TElPGPUserAttrSubpacket() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPUserAttrSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPUSERATTRSUBPACKET */

#ifdef SB_USE_CLASS_TELPGPUSERATTRIMAGESUBPACKET

SB_INLINE void TElPGPUserAttrImageSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPUserAttrImageSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPUserAttrImageSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPUserAttrImageSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPUserAttrImageSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPUserAttrImageSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPUserAttrImageSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPUserAttrImageSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

bool TElPGPUserAttrImageSubpacket::Compare(TElPGPUserAttrSubpacket &Source)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPUserAttrImageSubpacket_Compare(_Handle, Source.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPUserAttrImageSubpacket::Compare(TElPGPUserAttrSubpacket *Source)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPUserAttrImageSubpacket_Compare(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE uint8_t TElPGPUserAttrImageSubpacket::get_HeaderVersion()
{
	uint8_t OutResult;
	SBCheckError(TElPGPUserAttrImageSubpacket_get_HeaderVersion(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPUserAttrImageSubpacket::set_HeaderVersion(uint8_t Value)
{
	SBCheckError(TElPGPUserAttrImageSubpacket_set_HeaderVersion(_Handle, Value));
}

SB_INLINE uint8_t TElPGPUserAttrImageSubpacket::get_ImageFormat()
{
	uint8_t OutResult;
	SBCheckError(TElPGPUserAttrImageSubpacket_get_ImageFormat(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPUserAttrImageSubpacket::set_ImageFormat(uint8_t Value)
{
	SBCheckError(TElPGPUserAttrImageSubpacket_set_ImageFormat(_Handle, Value));
}

void TElPGPUserAttrImageSubpacket::get_ImageData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPUserAttrImageSubpacket_get_ImageData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1417077263, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPUserAttrImageSubpacket::set_ImageData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPGPUserAttrImageSubpacket_set_ImageData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPGPUserAttrImageSubpacket::TElPGPUserAttrImageSubpacket(TElPGPUserAttrImageSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPUserAttrSubpacket(handle, ownHandle)
{
}

TElPGPUserAttrImageSubpacket::TElPGPUserAttrImageSubpacket() : TElPGPUserAttrSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPUserAttrImageSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPUSERATTRIMAGESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPUSERATTRENTITY

SB_INLINE void TElPGPUserAttrEntity::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPUserAttrEntity_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPUserAttrEntity::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPUserAttrEntity_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPUserAttrEntity::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPUserAttrEntity_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPUserAttrEntity::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPUserAttrEntity_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TLIST
TList* TElPGPUserAttrEntity::get_Subpackets()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPUserAttrEntity_get_Subpackets(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Subpackets)
		this->_Inst_Subpackets = new TList(hOutResult, ohFalse);
	else
		this->_Inst_Subpackets->updateHandle(hOutResult);
	return this->_Inst_Subpackets;
}
#endif /* SB_USE_CLASS_TLIST */

void TElPGPUserAttrEntity::initInstances()
{
#ifdef SB_USE_CLASS_TLIST
	this->_Inst_Subpackets = NULL;
#endif /* SB_USE_CLASS_TLIST */
}

TElPGPUserAttrEntity::TElPGPUserAttrEntity(TElPGPUserAttrEntityHandle handle, TElOwnHandle ownHandle) : TElPGPEntity(handle, ownHandle)
{
	initInstances();
}

TElPGPUserAttrEntity::TElPGPUserAttrEntity() : TElPGPEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPUserAttrEntity_Create(&_Handle));
}

TElPGPUserAttrEntity::~TElPGPUserAttrEntity()
{
#ifdef SB_USE_CLASS_TLIST
	delete this->_Inst_Subpackets;
	this->_Inst_Subpackets = NULL;
#endif /* SB_USE_CLASS_TLIST */
}
#endif /* SB_USE_CLASS_TELPGPUSERATTRENTITY */

#ifdef SB_USE_CLASS_TELPGPSIGNATUREENTITY

SB_INLINE void TElPGPSignatureEntity::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPSignatureEntity_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPSignatureEntity::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPSignatureEntity_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPSignatureEntity::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPSignatureEntity_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPSignatureEntity::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPSignatureEntity_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE uint8_t TElPGPSignatureEntity::get_Version()
{
	uint8_t OutResult;
	SBCheckError(TElPGPSignatureEntity_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSignatureEntity::set_Version(uint8_t Value)
{
	SBCheckError(TElPGPSignatureEntity_set_Version(_Handle, Value));
}

SB_INLINE uint8_t TElPGPSignatureEntity::get_SignatureClass()
{
	uint8_t OutResult;
	SBCheckError(TElPGPSignatureEntity_get_SignatureClass(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSignatureEntity::set_SignatureClass(uint8_t Value)
{
	SBCheckError(TElPGPSignatureEntity_set_SignatureClass(_Handle, Value));
}

SB_INLINE int64_t TElPGPSignatureEntity::get_CreationTime()
{
	int64_t OutResult;
	SBCheckError(TElPGPSignatureEntity_get_CreationTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSignatureEntity::set_CreationTime(int64_t Value)
{
	SBCheckError(TElPGPSignatureEntity_set_CreationTime(_Handle, Value));
}

SB_INLINE void TElPGPSignatureEntity::get_KeyID(TSBKeyID &OutResult)
{
	SBCheckError(TElPGPSignatureEntity_get_KeyID(_Handle, &OutResult));
}

SB_INLINE void TElPGPSignatureEntity::set_KeyID(TSBKeyID &Value)
{
	SBCheckError(TElPGPSignatureEntity_set_KeyID(_Handle, &Value));
}

SB_INLINE int32_t TElPGPSignatureEntity::get_PublicKeyAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPSignatureEntity_get_PublicKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSignatureEntity::set_PublicKeyAlgorithm(int32_t Value)
{
	SBCheckError(TElPGPSignatureEntity_set_PublicKeyAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElPGPSignatureEntity::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPSignatureEntity_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSignatureEntity::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElPGPSignatureEntity_set_HashAlgorithm(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELPGPSIGNATURESUBPACKETS
TElPGPSignatureSubpackets* TElPGPSignatureEntity::get_Subpackets()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPSignatureEntity_get_Subpackets(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Subpackets)
		this->_Inst_Subpackets = new TElPGPSignatureSubpackets(hOutResult, ohFalse);
	else
		this->_Inst_Subpackets->updateHandle(hOutResult);
	return this->_Inst_Subpackets;
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURESUBPACKETS */

SB_INLINE void TElPGPSignatureEntity::get_SignatureMaterial(TSBPGPSignatureMaterial &OutResult)
{
	SBCheckError(TElPGPSignatureEntity_get_SignatureMaterial(_Handle, &OutResult));
}

SB_INLINE void TElPGPSignatureEntity::set_SignatureMaterial(TSBPGPSignatureMaterial &Value)
{
	SBCheckError(TElPGPSignatureEntity_set_SignatureMaterial(_Handle, &Value));
}

SB_INLINE uint16_t TElPGPSignatureEntity::get_LeftBits()
{
	uint16_t OutResult;
	SBCheckError(TElPGPSignatureEntity_get_LeftBits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSignatureEntity::set_LeftBits(uint16_t Value)
{
	SBCheckError(TElPGPSignatureEntity_set_LeftBits(_Handle, Value));
}

void TElPGPSignatureEntity::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPSIGNATURESUBPACKETS
	this->_Inst_Subpackets = NULL;
#endif /* SB_USE_CLASS_TELPGPSIGNATURESUBPACKETS */
}

TElPGPSignatureEntity::TElPGPSignatureEntity(TElPGPSignatureEntityHandle handle, TElOwnHandle ownHandle) : TElPGPEntity(handle, ownHandle)
{
	initInstances();
}

TElPGPSignatureEntity::TElPGPSignatureEntity() : TElPGPEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPSignatureEntity_Create(&_Handle));
}

TElPGPSignatureEntity::~TElPGPSignatureEntity()
{
#ifdef SB_USE_CLASS_TELPGPSIGNATURESUBPACKETS
	delete this->_Inst_Subpackets;
	this->_Inst_Subpackets = NULL;
#endif /* SB_USE_CLASS_TELPGPSIGNATURESUBPACKETS */
}
#endif /* SB_USE_CLASS_TELPGPSIGNATUREENTITY */

#ifdef SB_USE_CLASS_TELPGPSIGNATURESUBPACKET

SB_INLINE void TElPGPSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

bool TElPGPSignatureSubpacket::get_Hashed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignatureSubpacket_get_Hashed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPSignatureSubpacket::set_Hashed(bool Value)
{
	SBCheckError(TElPGPSignatureSubpacket_set_Hashed(_Handle, (int8_t)Value));
}

bool TElPGPSignatureSubpacket::get_Critical()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignatureSubpacket_get_Critical(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPSignatureSubpacket::set_Critical(bool Value)
{
	SBCheckError(TElPGPSignatureSubpacket_set_Critical(_Handle, (int8_t)Value));
}

SB_INLINE uint8_t TElPGPSignatureSubpacket::get_SubpacketType()
{
	uint8_t OutResult;
	SBCheckError(TElPGPSignatureSubpacket_get_SubpacketType(_Handle, &OutResult));
	return OutResult;
}

TElPGPSignatureSubpacket::TElPGPSignatureSubpacket(TElPGPSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TElPGPSignatureSubpacket::TElPGPSignatureSubpacket() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPSIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPCREATIONTIMESIGNATURESUBPACKET

SB_INLINE void TElPGPCreationTimeSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPCreationTimeSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPCreationTimeSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPCreationTimeSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPCreationTimeSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPCreationTimeSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPCreationTimeSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPCreationTimeSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int64_t TElPGPCreationTimeSignatureSubpacket::get_CreationTime()
{
	int64_t OutResult;
	SBCheckError(TElPGPCreationTimeSignatureSubpacket_get_CreationTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPCreationTimeSignatureSubpacket::set_CreationTime(int64_t Value)
{
	SBCheckError(TElPGPCreationTimeSignatureSubpacket_set_CreationTime(_Handle, Value));
}

TElPGPCreationTimeSignatureSubpacket::TElPGPCreationTimeSignatureSubpacket(TElPGPCreationTimeSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPCreationTimeSignatureSubpacket::TElPGPCreationTimeSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPCreationTimeSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPCREATIONTIMESIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPEXPIRATIONTIMESIGNATURESUBPACKET

SB_INLINE void TElPGPExpirationTimeSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPExpirationTimeSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPExpirationTimeSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPExpirationTimeSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPExpirationTimeSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPExpirationTimeSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPExpirationTimeSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPExpirationTimeSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElPGPExpirationTimeSignatureSubpacket::get_ExpirationTime()
{
	int32_t OutResult;
	SBCheckError(TElPGPExpirationTimeSignatureSubpacket_get_ExpirationTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPExpirationTimeSignatureSubpacket::set_ExpirationTime(int32_t Value)
{
	SBCheckError(TElPGPExpirationTimeSignatureSubpacket_set_ExpirationTime(_Handle, Value));
}

TElPGPExpirationTimeSignatureSubpacket::TElPGPExpirationTimeSignatureSubpacket(TElPGPExpirationTimeSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPExpirationTimeSignatureSubpacket::TElPGPExpirationTimeSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPExpirationTimeSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPEXPIRATIONTIMESIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPEMBEDDEDSIGNATURESIGNATURESUBPACKET

SB_INLINE void TElPGPEmbeddedSignatureSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPEmbeddedSignatureSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPEmbeddedSignatureSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPEmbeddedSignatureSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPEmbeddedSignatureSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPEmbeddedSignatureSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPEmbeddedSignatureSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPEmbeddedSignatureSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELPGPSIGNATUREENTITY
TElPGPSignatureEntity* TElPGPEmbeddedSignatureSignatureSubpacket::get_Signature()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPEmbeddedSignatureSignatureSubpacket_get_Signature(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signature)
		this->_Inst_Signature = new TElPGPSignatureEntity(hOutResult, ohFalse);
	else
		this->_Inst_Signature->updateHandle(hOutResult);
	return this->_Inst_Signature;
}

SB_INLINE void TElPGPEmbeddedSignatureSignatureSubpacket::set_Signature(TElPGPSignatureEntity &Value)
{
	SBCheckError(TElPGPEmbeddedSignatureSignatureSubpacket_set_Signature(_Handle, Value.getHandle()));
}

SB_INLINE void TElPGPEmbeddedSignatureSignatureSubpacket::set_Signature(TElPGPSignatureEntity *Value)
{
	SBCheckError(TElPGPEmbeddedSignatureSignatureSubpacket_set_Signature(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPSIGNATUREENTITY */

void TElPGPEmbeddedSignatureSignatureSubpacket::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPSIGNATUREENTITY
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELPGPSIGNATUREENTITY */
}

TElPGPEmbeddedSignatureSignatureSubpacket::TElPGPEmbeddedSignatureSignatureSubpacket(TElPGPEmbeddedSignatureSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
	initInstances();
}

TElPGPEmbeddedSignatureSignatureSubpacket::TElPGPEmbeddedSignatureSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPEmbeddedSignatureSignatureSubpacket_Create(&_Handle));
}

TElPGPEmbeddedSignatureSignatureSubpacket::~TElPGPEmbeddedSignatureSignatureSubpacket()
{
#ifdef SB_USE_CLASS_TELPGPSIGNATUREENTITY
	delete this->_Inst_Signature;
	this->_Inst_Signature = NULL;
#endif /* SB_USE_CLASS_TELPGPSIGNATUREENTITY */
}
#endif /* SB_USE_CLASS_TELPGPEMBEDDEDSIGNATURESIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPEXPORTABLECERTIFICATIONSIGNATURESUBPACKET

SB_INLINE void TElPGPExportableCertificationSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPExportableCertificationSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPExportableCertificationSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPExportableCertificationSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPExportableCertificationSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPExportableCertificationSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPExportableCertificationSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPExportableCertificationSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

bool TElPGPExportableCertificationSignatureSubpacket::get_Exportable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPExportableCertificationSignatureSubpacket_get_Exportable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPExportableCertificationSignatureSubpacket::set_Exportable(bool Value)
{
	SBCheckError(TElPGPExportableCertificationSignatureSubpacket_set_Exportable(_Handle, (int8_t)Value));
}

TElPGPExportableCertificationSignatureSubpacket::TElPGPExportableCertificationSignatureSubpacket(TElPGPExportableCertificationSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPExportableCertificationSignatureSubpacket::TElPGPExportableCertificationSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPExportableCertificationSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPEXPORTABLECERTIFICATIONSIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPTRUSTSIGNATURESUBPACKET

SB_INLINE void TElPGPTrustSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPTrustSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPTrustSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPTrustSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPTrustSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPTrustSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPTrustSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPTrustSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE uint8_t TElPGPTrustSignatureSubpacket::get_Level()
{
	uint8_t OutResult;
	SBCheckError(TElPGPTrustSignatureSubpacket_get_Level(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPTrustSignatureSubpacket::set_Level(uint8_t Value)
{
	SBCheckError(TElPGPTrustSignatureSubpacket_set_Level(_Handle, Value));
}

SB_INLINE uint8_t TElPGPTrustSignatureSubpacket::get_Amount()
{
	uint8_t OutResult;
	SBCheckError(TElPGPTrustSignatureSubpacket_get_Amount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPTrustSignatureSubpacket::set_Amount(uint8_t Value)
{
	SBCheckError(TElPGPTrustSignatureSubpacket_set_Amount(_Handle, Value));
}

TElPGPTrustSignatureSubpacket::TElPGPTrustSignatureSubpacket(TElPGPTrustSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPTrustSignatureSubpacket::TElPGPTrustSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPTrustSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPTRUSTSIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPREGULAREXPRESSIONSIGNATURESUBPACKET

SB_INLINE void TElPGPRegularExpressionSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPRegularExpressionSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPRegularExpressionSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPRegularExpressionSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPRegularExpressionSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPRegularExpressionSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPRegularExpressionSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPRegularExpressionSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

void TElPGPRegularExpressionSignatureSubpacket::get_Expression(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPRegularExpressionSignatureSubpacket_get_Expression(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(947152904, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPRegularExpressionSignatureSubpacket::set_Expression(const std::string &Value)
{
	SBCheckError(TElPGPRegularExpressionSignatureSubpacket_set_Expression(_Handle, Value.data(), (int32_t)Value.length()));
}

TElPGPRegularExpressionSignatureSubpacket::TElPGPRegularExpressionSignatureSubpacket(TElPGPRegularExpressionSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPRegularExpressionSignatureSubpacket::TElPGPRegularExpressionSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPRegularExpressionSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPREGULAREXPRESSIONSIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPREVOCABLESIGNATURESUBPACKET

SB_INLINE void TElPGPRevocableSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPRevocableSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPRevocableSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPRevocableSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPRevocableSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPRevocableSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPRevocableSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPRevocableSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

bool TElPGPRevocableSignatureSubpacket::get_Revocable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPRevocableSignatureSubpacket_get_Revocable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPRevocableSignatureSubpacket::set_Revocable(bool Value)
{
	SBCheckError(TElPGPRevocableSignatureSubpacket_set_Revocable(_Handle, (int8_t)Value));
}

TElPGPRevocableSignatureSubpacket::TElPGPRevocableSignatureSubpacket(TElPGPRevocableSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPRevocableSignatureSubpacket::TElPGPRevocableSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPRevocableSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPREVOCABLESIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPKEYEXPIRATIONTIMESIGNATURESUBPACKET

SB_INLINE void TElPGPKeyExpirationTimeSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPKeyExpirationTimeSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPKeyExpirationTimeSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPKeyExpirationTimeSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPKeyExpirationTimeSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPKeyExpirationTimeSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPKeyExpirationTimeSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPKeyExpirationTimeSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElPGPKeyExpirationTimeSignatureSubpacket::get_Expires()
{
	int32_t OutResult;
	SBCheckError(TElPGPKeyExpirationTimeSignatureSubpacket_get_Expires(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPKeyExpirationTimeSignatureSubpacket::set_Expires(int32_t Value)
{
	SBCheckError(TElPGPKeyExpirationTimeSignatureSubpacket_set_Expires(_Handle, Value));
}

TElPGPKeyExpirationTimeSignatureSubpacket::TElPGPKeyExpirationTimeSignatureSubpacket(TElPGPKeyExpirationTimeSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPKeyExpirationTimeSignatureSubpacket::TElPGPKeyExpirationTimeSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPKeyExpirationTimeSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPKEYEXPIRATIONTIMESIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPPREFERREDSYMMETRICALGORITHMSSIGNATURESUBPACKET

SB_INLINE void TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE uint8_t TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket::get_Preferred(int32_t Index)
{
	uint8_t OutResult;
	SBCheckError(TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket_get_Preferred(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket::set_Preferred(int32_t Index, uint8_t Value)
{
	SBCheckError(TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket_set_Preferred(_Handle, Index, Value));
}

SB_INLINE int32_t TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket::get_PreferredCount()
{
	int32_t OutResult;
	SBCheckError(TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket_get_PreferredCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket::set_PreferredCount(int32_t Value)
{
	SBCheckError(TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket_set_PreferredCount(_Handle, Value));
}

TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket::TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket(TElPGPPreferredSymmetricAlgorithmsSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket::TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPPreferredSymmetricAlgorithmsSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPPREFERREDSYMMETRICALGORITHMSSIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPREVOCATIONKEYSIGNATURESUBPACKET

SB_INLINE void TElPGPRevocationKeySignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPRevocationKeySignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPRevocationKeySignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPRevocationKeySignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPRevocationKeySignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPRevocationKeySignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPRevocationKeySignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPRevocationKeySignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE uint8_t TElPGPRevocationKeySignatureSubpacket::get_RevClass()
{
	uint8_t OutResult;
	SBCheckError(TElPGPRevocationKeySignatureSubpacket_get_RevClass(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPRevocationKeySignatureSubpacket::set_RevClass(uint8_t Value)
{
	SBCheckError(TElPGPRevocationKeySignatureSubpacket_set_RevClass(_Handle, Value));
}

SB_INLINE uint8_t TElPGPRevocationKeySignatureSubpacket::get_AlgID()
{
	uint8_t OutResult;
	SBCheckError(TElPGPRevocationKeySignatureSubpacket_get_AlgID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPRevocationKeySignatureSubpacket::set_AlgID(uint8_t Value)
{
	SBCheckError(TElPGPRevocationKeySignatureSubpacket_set_AlgID(_Handle, Value));
}

void TElPGPRevocationKeySignatureSubpacket::get_Fingerprint(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPRevocationKeySignatureSubpacket_get_Fingerprint(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1389470522, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPRevocationKeySignatureSubpacket::set_Fingerprint(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPGPRevocationKeySignatureSubpacket_set_Fingerprint(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPGPRevocationKeySignatureSubpacket::TElPGPRevocationKeySignatureSubpacket(TElPGPRevocationKeySignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPRevocationKeySignatureSubpacket::TElPGPRevocationKeySignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPRevocationKeySignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPREVOCATIONKEYSIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPISSUERKEYIDSIGNATURESUBPACKET

SB_INLINE void TElPGPIssuerKeyIDSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPIssuerKeyIDSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPIssuerKeyIDSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPIssuerKeyIDSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPIssuerKeyIDSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPIssuerKeyIDSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPIssuerKeyIDSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPIssuerKeyIDSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPIssuerKeyIDSignatureSubpacket::get_KeyID(TSBKeyID &OutResult)
{
	SBCheckError(TElPGPIssuerKeyIDSignatureSubpacket_get_KeyID(_Handle, &OutResult));
}

SB_INLINE void TElPGPIssuerKeyIDSignatureSubpacket::set_KeyID(TSBKeyID &Value)
{
	SBCheckError(TElPGPIssuerKeyIDSignatureSubpacket_set_KeyID(_Handle, &Value));
}

TElPGPIssuerKeyIDSignatureSubpacket::TElPGPIssuerKeyIDSignatureSubpacket(TElPGPIssuerKeyIDSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPIssuerKeyIDSignatureSubpacket::TElPGPIssuerKeyIDSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPIssuerKeyIDSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPISSUERKEYIDSIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPNOTATIONDATASIGNATURESUBPACKET

SB_INLINE void TElPGPNotationDataSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPNotationDataSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPNotationDataSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPNotationDataSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPNotationDataSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPNotationDataSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPNotationDataSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPNotationDataSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

bool TElPGPNotationDataSignatureSubpacket::get_HumanReadable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPNotationDataSignatureSubpacket_get_HumanReadable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPNotationDataSignatureSubpacket::set_HumanReadable(bool Value)
{
	SBCheckError(TElPGPNotationDataSignatureSubpacket_set_HumanReadable(_Handle, (int8_t)Value));
}

void TElPGPNotationDataSignatureSubpacket::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPNotationDataSignatureSubpacket_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1975189576, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPNotationDataSignatureSubpacket::set_Name(const std::string &Value)
{
	SBCheckError(TElPGPNotationDataSignatureSubpacket_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPGPNotationDataSignatureSubpacket::get_Value(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPNotationDataSignatureSubpacket_get_Value(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1580876624, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPNotationDataSignatureSubpacket::set_Value(const std::string &Value)
{
	SBCheckError(TElPGPNotationDataSignatureSubpacket_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

TElPGPNotationDataSignatureSubpacket::TElPGPNotationDataSignatureSubpacket(TElPGPNotationDataSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPNotationDataSignatureSubpacket::TElPGPNotationDataSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPNotationDataSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPNOTATIONDATASIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPPREFERREDHASHALGORITHMSSIGNATURESUBPACKET

SB_INLINE void TElPGPPreferredHashAlgorithmsSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPPreferredHashAlgorithmsSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPPreferredHashAlgorithmsSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPPreferredHashAlgorithmsSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPPreferredHashAlgorithmsSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPPreferredHashAlgorithmsSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPPreferredHashAlgorithmsSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPPreferredHashAlgorithmsSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE uint8_t TElPGPPreferredHashAlgorithmsSignatureSubpacket::get_Preferred(int32_t Index)
{
	uint8_t OutResult;
	SBCheckError(TElPGPPreferredHashAlgorithmsSignatureSubpacket_get_Preferred(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPPreferredHashAlgorithmsSignatureSubpacket::set_Preferred(int32_t Index, uint8_t Value)
{
	SBCheckError(TElPGPPreferredHashAlgorithmsSignatureSubpacket_set_Preferred(_Handle, Index, Value));
}

SB_INLINE int32_t TElPGPPreferredHashAlgorithmsSignatureSubpacket::get_PreferredCount()
{
	int32_t OutResult;
	SBCheckError(TElPGPPreferredHashAlgorithmsSignatureSubpacket_get_PreferredCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPPreferredHashAlgorithmsSignatureSubpacket::set_PreferredCount(int32_t Value)
{
	SBCheckError(TElPGPPreferredHashAlgorithmsSignatureSubpacket_set_PreferredCount(_Handle, Value));
}

TElPGPPreferredHashAlgorithmsSignatureSubpacket::TElPGPPreferredHashAlgorithmsSignatureSubpacket(TElPGPPreferredHashAlgorithmsSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPPreferredHashAlgorithmsSignatureSubpacket::TElPGPPreferredHashAlgorithmsSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPPreferredHashAlgorithmsSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPPREFERREDHASHALGORITHMSSIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPPREFERREDCOMPRESSIONALGORITHMSSIGNATURESUBPACKET

SB_INLINE void TElPGPPreferredCompressionAlgorithmsSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPPreferredCompressionAlgorithmsSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPPreferredCompressionAlgorithmsSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPPreferredCompressionAlgorithmsSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPPreferredCompressionAlgorithmsSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPPreferredCompressionAlgorithmsSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPPreferredCompressionAlgorithmsSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPPreferredCompressionAlgorithmsSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE uint8_t TElPGPPreferredCompressionAlgorithmsSignatureSubpacket::get_Preferred(int32_t Index)
{
	uint8_t OutResult;
	SBCheckError(TElPGPPreferredCompressionAlgorithmsSignatureSubpacket_get_Preferred(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPPreferredCompressionAlgorithmsSignatureSubpacket::set_Preferred(int32_t Index, uint8_t Value)
{
	SBCheckError(TElPGPPreferredCompressionAlgorithmsSignatureSubpacket_set_Preferred(_Handle, Index, Value));
}

SB_INLINE int32_t TElPGPPreferredCompressionAlgorithmsSignatureSubpacket::get_PreferredCount()
{
	int32_t OutResult;
	SBCheckError(TElPGPPreferredCompressionAlgorithmsSignatureSubpacket_get_PreferredCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPPreferredCompressionAlgorithmsSignatureSubpacket::set_PreferredCount(int32_t Value)
{
	SBCheckError(TElPGPPreferredCompressionAlgorithmsSignatureSubpacket_set_PreferredCount(_Handle, Value));
}

TElPGPPreferredCompressionAlgorithmsSignatureSubpacket::TElPGPPreferredCompressionAlgorithmsSignatureSubpacket(TElPGPPreferredCompressionAlgorithmsSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPPreferredCompressionAlgorithmsSignatureSubpacket::TElPGPPreferredCompressionAlgorithmsSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPPreferredCompressionAlgorithmsSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPPREFERREDCOMPRESSIONALGORITHMSSIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPKEYSERVERPREFERENCESSIGNATURESUBPACKET

SB_INLINE void TElPGPKeyServerPreferencesSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPKeyServerPreferencesSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPKeyServerPreferencesSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPKeyServerPreferencesSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPKeyServerPreferencesSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPKeyServerPreferencesSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPKeyServerPreferencesSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPKeyServerPreferencesSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

bool TElPGPKeyServerPreferencesSignatureSubpacket::get_NoModify()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPKeyServerPreferencesSignatureSubpacket_get_NoModify(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPKeyServerPreferencesSignatureSubpacket::set_NoModify(bool Value)
{
	SBCheckError(TElPGPKeyServerPreferencesSignatureSubpacket_set_NoModify(_Handle, (int8_t)Value));
}

TElPGPKeyServerPreferencesSignatureSubpacket::TElPGPKeyServerPreferencesSignatureSubpacket(TElPGPKeyServerPreferencesSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPKeyServerPreferencesSignatureSubpacket::TElPGPKeyServerPreferencesSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPKeyServerPreferencesSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPKEYSERVERPREFERENCESSIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPPREFERREDKEYSERVERSIGNATURESUBPACKET

SB_INLINE void TElPGPPreferredKeyServerSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPPreferredKeyServerSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPPreferredKeyServerSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPPreferredKeyServerSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPPreferredKeyServerSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPPreferredKeyServerSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPPreferredKeyServerSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPPreferredKeyServerSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

void TElPGPPreferredKeyServerSignatureSubpacket::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPPreferredKeyServerSignatureSubpacket_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1670526277, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPPreferredKeyServerSignatureSubpacket::set_URL(const std::string &Value)
{
	SBCheckError(TElPGPPreferredKeyServerSignatureSubpacket_set_URL(_Handle, Value.data(), (int32_t)Value.length()));
}

TElPGPPreferredKeyServerSignatureSubpacket::TElPGPPreferredKeyServerSignatureSubpacket(TElPGPPreferredKeyServerSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPPreferredKeyServerSignatureSubpacket::TElPGPPreferredKeyServerSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPPreferredKeyServerSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPPREFERREDKEYSERVERSIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPPRIMARYUSERIDSIGNATURESUBPACKET

SB_INLINE void TElPGPPrimaryUserIDSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPPrimaryUserIDSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPPrimaryUserIDSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPPrimaryUserIDSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPPrimaryUserIDSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPPrimaryUserIDSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPPrimaryUserIDSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPPrimaryUserIDSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

bool TElPGPPrimaryUserIDSignatureSubpacket::get_Primary()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPPrimaryUserIDSignatureSubpacket_get_Primary(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPPrimaryUserIDSignatureSubpacket::set_Primary(bool Value)
{
	SBCheckError(TElPGPPrimaryUserIDSignatureSubpacket_set_Primary(_Handle, (int8_t)Value));
}

TElPGPPrimaryUserIDSignatureSubpacket::TElPGPPrimaryUserIDSignatureSubpacket(TElPGPPrimaryUserIDSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPPrimaryUserIDSignatureSubpacket::TElPGPPrimaryUserIDSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPPrimaryUserIDSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPPRIMARYUSERIDSIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPPOLICYURLSIGNATURESUBPACKET

SB_INLINE void TElPGPPolicyURLSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPPolicyURLSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPPolicyURLSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPPolicyURLSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPPolicyURLSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPPolicyURLSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPPolicyURLSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPPolicyURLSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

void TElPGPPolicyURLSignatureSubpacket::get_URL(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPPolicyURLSignatureSubpacket_get_URL(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1083080554, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPPolicyURLSignatureSubpacket::set_URL(const std::string &Value)
{
	SBCheckError(TElPGPPolicyURLSignatureSubpacket_set_URL(_Handle, Value.data(), (int32_t)Value.length()));
}

TElPGPPolicyURLSignatureSubpacket::TElPGPPolicyURLSignatureSubpacket(TElPGPPolicyURLSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPPolicyURLSignatureSubpacket::TElPGPPolicyURLSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPPolicyURLSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPPOLICYURLSIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPKEYFLAGSSIGNATURESUBPACKET

SB_INLINE void TElPGPKeyFlagsSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPKeyFlagsSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPKeyFlagsSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPKeyFlagsSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPKeyFlagsSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPKeyFlagsSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPKeyFlagsSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPKeyFlagsSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

bool TElPGPKeyFlagsSignatureSubpacket::get_CertifyOtherKeys()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPKeyFlagsSignatureSubpacket_get_CertifyOtherKeys(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPKeyFlagsSignatureSubpacket::set_CertifyOtherKeys(bool Value)
{
	SBCheckError(TElPGPKeyFlagsSignatureSubpacket_set_CertifyOtherKeys(_Handle, (int8_t)Value));
}

bool TElPGPKeyFlagsSignatureSubpacket::get_SignData()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPKeyFlagsSignatureSubpacket_get_SignData(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPKeyFlagsSignatureSubpacket::set_SignData(bool Value)
{
	SBCheckError(TElPGPKeyFlagsSignatureSubpacket_set_SignData(_Handle, (int8_t)Value));
}

bool TElPGPKeyFlagsSignatureSubpacket::get_EncryptData()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPKeyFlagsSignatureSubpacket_get_EncryptData(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPKeyFlagsSignatureSubpacket::set_EncryptData(bool Value)
{
	SBCheckError(TElPGPKeyFlagsSignatureSubpacket_set_EncryptData(_Handle, (int8_t)Value));
}

bool TElPGPKeyFlagsSignatureSubpacket::get_EncryptStorage()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPKeyFlagsSignatureSubpacket_get_EncryptStorage(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPKeyFlagsSignatureSubpacket::set_EncryptStorage(bool Value)
{
	SBCheckError(TElPGPKeyFlagsSignatureSubpacket_set_EncryptStorage(_Handle, (int8_t)Value));
}

bool TElPGPKeyFlagsSignatureSubpacket::get_SplitKey()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPKeyFlagsSignatureSubpacket_get_SplitKey(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPKeyFlagsSignatureSubpacket::set_SplitKey(bool Value)
{
	SBCheckError(TElPGPKeyFlagsSignatureSubpacket_set_SplitKey(_Handle, (int8_t)Value));
}

bool TElPGPKeyFlagsSignatureSubpacket::get_GroupKey()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPKeyFlagsSignatureSubpacket_get_GroupKey(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPKeyFlagsSignatureSubpacket::set_GroupKey(bool Value)
{
	SBCheckError(TElPGPKeyFlagsSignatureSubpacket_set_GroupKey(_Handle, (int8_t)Value));
}

TElPGPKeyFlagsSignatureSubpacket::TElPGPKeyFlagsSignatureSubpacket(TElPGPKeyFlagsSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPKeyFlagsSignatureSubpacket::TElPGPKeyFlagsSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPKeyFlagsSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPKEYFLAGSSIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPSIGNERSUSERIDSIGNATURESUBPACKET

SB_INLINE void TElPGPSignersUserIDSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPSignersUserIDSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPSignersUserIDSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPSignersUserIDSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPSignersUserIDSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPSignersUserIDSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPSignersUserIDSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPSignersUserIDSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

void TElPGPSignersUserIDSignatureSubpacket::get_UserID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPSignersUserIDSignatureSubpacket_get_UserID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1135965042, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPSignersUserIDSignatureSubpacket::set_UserID(const std::string &Value)
{
	SBCheckError(TElPGPSignersUserIDSignatureSubpacket_set_UserID(_Handle, Value.data(), (int32_t)Value.length()));
}

TElPGPSignersUserIDSignatureSubpacket::TElPGPSignersUserIDSignatureSubpacket(TElPGPSignersUserIDSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPSignersUserIDSignatureSubpacket::TElPGPSignersUserIDSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPSignersUserIDSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPSIGNERSUSERIDSIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPREASONFORREVOCATIONSIGNATURESUBPACKET

SB_INLINE void TElPGPReasonForRevocationSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPReasonForRevocationSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPReasonForRevocationSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPReasonForRevocationSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPReasonForRevocationSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPReasonForRevocationSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPReasonForRevocationSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPReasonForRevocationSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

TSBPGPReasonForRevocation TElPGPReasonForRevocationSignatureSubpacket::get_Reason()
{
	TSBPGPReasonForRevocationRaw OutResultRaw = 0;
	SBCheckError(TElPGPReasonForRevocationSignatureSubpacket_get_Reason(_Handle, &OutResultRaw));
	return (TSBPGPReasonForRevocation)OutResultRaw;
}

SB_INLINE void TElPGPReasonForRevocationSignatureSubpacket::set_Reason(TSBPGPReasonForRevocation Value)
{
	SBCheckError(TElPGPReasonForRevocationSignatureSubpacket_set_Reason(_Handle, (TSBPGPReasonForRevocationRaw)Value));
}

void TElPGPReasonForRevocationSignatureSubpacket::get_Comment(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPReasonForRevocationSignatureSubpacket_get_Comment(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1724785671, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPReasonForRevocationSignatureSubpacket::set_Comment(const std::string &Value)
{
	SBCheckError(TElPGPReasonForRevocationSignatureSubpacket_set_Comment(_Handle, Value.data(), (int32_t)Value.length()));
}

TElPGPReasonForRevocationSignatureSubpacket::TElPGPReasonForRevocationSignatureSubpacket(TElPGPReasonForRevocationSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPReasonForRevocationSignatureSubpacket::TElPGPReasonForRevocationSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPReasonForRevocationSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPREASONFORREVOCATIONSIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPFEATURESSIGNATURESUBPACKET

SB_INLINE void TElPGPFeaturesSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPFeaturesSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPFeaturesSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPFeaturesSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPFeaturesSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPFeaturesSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPFeaturesSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPFeaturesSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

bool TElPGPFeaturesSignatureSubpacket::get_ModificationDetection()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPFeaturesSignatureSubpacket_get_ModificationDetection(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPFeaturesSignatureSubpacket::set_ModificationDetection(bool Value)
{
	SBCheckError(TElPGPFeaturesSignatureSubpacket_set_ModificationDetection(_Handle, (int8_t)Value));
}

TElPGPFeaturesSignatureSubpacket::TElPGPFeaturesSignatureSubpacket(TElPGPFeaturesSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPFeaturesSignatureSubpacket::TElPGPFeaturesSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPFeaturesSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPFEATURESSIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPTARGETSIGNATURESUBPACKET

SB_INLINE void TElPGPTargetSignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPTargetSignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPTargetSignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPTargetSignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPTargetSignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPTargetSignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPTargetSignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPTargetSignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

void TElPGPTargetSignatureSubpacket::get_Hash(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPTargetSignatureSubpacket_get_Hash(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-746636638, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPTargetSignatureSubpacket::set_Hash(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPGPTargetSignatureSubpacket_set_Hash(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE uint8_t TElPGPTargetSignatureSubpacket::get_PublicKeyAlgorithm()
{
	uint8_t OutResult;
	SBCheckError(TElPGPTargetSignatureSubpacket_get_PublicKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPTargetSignatureSubpacket::set_PublicKeyAlgorithm(uint8_t Value)
{
	SBCheckError(TElPGPTargetSignatureSubpacket_set_PublicKeyAlgorithm(_Handle, Value));
}

SB_INLINE uint8_t TElPGPTargetSignatureSubpacket::get_HashAlgorithm()
{
	uint8_t OutResult;
	SBCheckError(TElPGPTargetSignatureSubpacket_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPTargetSignatureSubpacket::set_HashAlgorithm(uint8_t Value)
{
	SBCheckError(TElPGPTargetSignatureSubpacket_set_HashAlgorithm(_Handle, Value));
}

TElPGPTargetSignatureSubpacket::TElPGPTargetSignatureSubpacket(TElPGPTargetSignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
}

TElPGPTargetSignatureSubpacket::TElPGPTargetSignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPTargetSignatureSubpacket_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPTARGETSIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPX509SIGNATURESUBPACKET

SB_INLINE void TElPGPX509SignatureSubpacket::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPX509SignatureSubpacket_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPX509SignatureSubpacket::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPX509SignatureSubpacket_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPX509SignatureSubpacket::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPX509SignatureSubpacket_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPX509SignatureSubpacket::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPX509SignatureSubpacket_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElPGPX509SignatureSubpacket::get_Certificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPX509SignatureSubpacket_get_Certificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificate)
		this->_Inst_Certificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_Certificate->updateHandle(hOutResult);
	return this->_Inst_Certificate;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

void TElPGPX509SignatureSubpacket::initInstances()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_Certificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
}

TElPGPX509SignatureSubpacket::TElPGPX509SignatureSubpacket(TElPGPX509SignatureSubpacketHandle handle, TElOwnHandle ownHandle) : TElPGPSignatureSubpacket(handle, ownHandle)
{
	initInstances();
}

TElPGPX509SignatureSubpacket::TElPGPX509SignatureSubpacket() : TElPGPSignatureSubpacket(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPX509SignatureSubpacket_Create(&_Handle));
}

TElPGPX509SignatureSubpacket::~TElPGPX509SignatureSubpacket()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_Certificate;
	this->_Inst_Certificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
}
#endif /* SB_USE_CLASS_TELPGPX509SIGNATURESUBPACKET */

#ifdef SB_USE_CLASS_TELPGPSIGNATURESUBPACKETS

#ifdef SB_USE_CLASS_TELPGPSIGNATURESUBPACKET
SB_INLINE TElPGPSignatureSubpacketHandle TElPGPSignatureSubpackets::GetSubpacket(uint8_t SubpacketType, int32_t StartFrom)
{
	TElPGPSignatureSubpacketHandle OutResult;
	SBCheckError(TElPGPSignatureSubpackets_GetSubpacket(_Handle, SubpacketType, StartFrom, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURESUBPACKET */

SB_INLINE int32_t TElPGPSignatureSubpackets::GetSubpacketCount(uint8_t SubpacketType)
{
	int32_t OutResult;
	SBCheckError(TElPGPSignatureSubpackets_GetSubpacketCount(_Handle, SubpacketType, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPGPSIGNATURESUBPACKET
SB_INLINE int32_t TElPGPSignatureSubpackets::Add(TElPGPSignatureSubpacket &Item)
{
	int32_t OutResult;
	SBCheckError(TElPGPSignatureSubpackets_Add(_Handle, Item.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPSignatureSubpackets::Add(TElPGPSignatureSubpacket *Item)
{
	int32_t OutResult;
	SBCheckError(TElPGPSignatureSubpackets_Add(_Handle, (Item != NULL) ? Item->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURESUBPACKET */

bool TElPGPSignatureSubpackets::RemoveSubpacket(uint8_t SubpacketType, int32_t StartIndex)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignatureSubpackets_RemoveSubpacket(_Handle, SubpacketType, StartIndex, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPGPSignatureSubpackets::RemoveSubpacketByIndex(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSignatureSubpackets_RemoveSubpacketByIndex(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPSignatureSubpackets::Clear()
{
	SBCheckError(TElPGPSignatureSubpackets_Clear(_Handle));
}

TElPGPSignatureSubpackets::TElPGPSignatureSubpackets(TElPGPSignatureSubpacketsHandle handle, TElOwnHandle ownHandle) : TList(handle, ownHandle)
{
}

TElPGPSignatureSubpackets::TElPGPSignatureSubpackets() : TList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPSignatureSubpackets_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPSIGNATURESUBPACKETS */

#ifdef SB_USE_CLASS_TELPGPTRUSTENTITY

SB_INLINE void TElPGPTrustEntity::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPTrustEntity_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPTrustEntity::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPTrustEntity_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPTrustEntity::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPTrustEntity_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPTrustEntity::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPTrustEntity_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE uint8_t TElPGPTrustEntity::get_Flags()
{
	uint8_t OutResult;
	SBCheckError(TElPGPTrustEntity_get_Flags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPTrustEntity::set_Flags(uint8_t Value)
{
	SBCheckError(TElPGPTrustEntity_set_Flags(_Handle, Value));
}

TElPGPTrustEntity::TElPGPTrustEntity(TElPGPTrustEntityHandle handle, TElOwnHandle ownHandle) : TElPGPEntity(handle, ownHandle)
{
}

TElPGPTrustEntity::TElPGPTrustEntity() : TElPGPEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPTrustEntity_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPTRUSTENTITY */

#ifdef SB_USE_CLASS_TELPGPPUBLICKEYENCRYPTEDSESSIONKEYENTITY

SB_INLINE void TElPGPPublicKeyEncryptedSessionKeyEntity::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPPublicKeyEncryptedSessionKeyEntity_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPPublicKeyEncryptedSessionKeyEntity::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPPublicKeyEncryptedSessionKeyEntity_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPPublicKeyEncryptedSessionKeyEntity::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPPublicKeyEncryptedSessionKeyEntity_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPPublicKeyEncryptedSessionKeyEntity::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPPublicKeyEncryptedSessionKeyEntity_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPPublicKeyEncryptedSessionKeyEntity::get_KeyID(TSBKeyID &OutResult)
{
	SBCheckError(TElPGPPublicKeyEncryptedSessionKeyEntity_get_KeyID(_Handle, &OutResult));
}

SB_INLINE void TElPGPPublicKeyEncryptedSessionKeyEntity::set_KeyID(TSBKeyID &Value)
{
	SBCheckError(TElPGPPublicKeyEncryptedSessionKeyEntity_set_KeyID(_Handle, &Value));
}

SB_INLINE int32_t TElPGPPublicKeyEncryptedSessionKeyEntity::get_PublicKeyAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPPublicKeyEncryptedSessionKeyEntity_get_PublicKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPPublicKeyEncryptedSessionKeyEntity::set_PublicKeyAlgorithm(int32_t Value)
{
	SBCheckError(TElPGPPublicKeyEncryptedSessionKeyEntity_set_PublicKeyAlgorithm(_Handle, Value));
}

SB_INLINE void TElPGPPublicKeyEncryptedSessionKeyEntity::get_EncryptedKey(TSBPGPEncryptedSymmetricKey &OutResult)
{
	SBCheckError(TElPGPPublicKeyEncryptedSessionKeyEntity_get_EncryptedKey(_Handle, &OutResult));
}

SB_INLINE void TElPGPPublicKeyEncryptedSessionKeyEntity::set_EncryptedKey(TSBPGPEncryptedSymmetricKey &Value)
{
	SBCheckError(TElPGPPublicKeyEncryptedSessionKeyEntity_set_EncryptedKey(_Handle, &Value));
}

TElPGPPublicKeyEncryptedSessionKeyEntity::TElPGPPublicKeyEncryptedSessionKeyEntity(TElPGPPublicKeyEncryptedSessionKeyEntityHandle handle, TElOwnHandle ownHandle) : TElPGPEntity(handle, ownHandle)
{
}

TElPGPPublicKeyEncryptedSessionKeyEntity::TElPGPPublicKeyEncryptedSessionKeyEntity() : TElPGPEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPPublicKeyEncryptedSessionKeyEntity_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPPUBLICKEYENCRYPTEDSESSIONKEYENTITY */

#ifdef SB_USE_CLASS_TELPGPSYMMETRICKEYENCRYPTEDSESSIONKEYENTITY

SB_INLINE void TElPGPSymmetricKeyEncryptedSessionKeyEntity::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPSymmetricKeyEncryptedSessionKeyEntity_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPSymmetricKeyEncryptedSessionKeyEntity::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPSymmetricKeyEncryptedSessionKeyEntity_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPSymmetricKeyEncryptedSessionKeyEntity::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPSymmetricKeyEncryptedSessionKeyEntity_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPSymmetricKeyEncryptedSessionKeyEntity::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPSymmetricKeyEncryptedSessionKeyEntity_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TElPGPSymmetricKeyEncryptedSessionKeyEntity::get_SymmetricAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPSymmetricKeyEncryptedSessionKeyEntity_get_SymmetricAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSymmetricKeyEncryptedSessionKeyEntity::set_SymmetricAlgorithm(int32_t Value)
{
	SBCheckError(TElPGPSymmetricKeyEncryptedSessionKeyEntity_set_SymmetricAlgorithm(_Handle, Value));
}

void TElPGPSymmetricKeyEncryptedSessionKeyEntity::get_EncryptedKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPSymmetricKeyEncryptedSessionKeyEntity_get_EncryptedKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-927187749, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPSymmetricKeyEncryptedSessionKeyEntity::set_EncryptedKey(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPGPSymmetricKeyEncryptedSessionKeyEntity_set_EncryptedKey(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELPGPS2K
TElPGPS2K* TElPGPSymmetricKeyEncryptedSessionKeyEntity::get_S2K()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPSymmetricKeyEncryptedSessionKeyEntity_get_S2K(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_S2K)
		this->_Inst_S2K = new TElPGPS2K(hOutResult, ohFalse);
	else
		this->_Inst_S2K->updateHandle(hOutResult);
	return this->_Inst_S2K;
}
#endif /* SB_USE_CLASS_TELPGPS2K */

void TElPGPSymmetricKeyEncryptedSessionKeyEntity::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPS2K
	this->_Inst_S2K = NULL;
#endif /* SB_USE_CLASS_TELPGPS2K */
}

TElPGPSymmetricKeyEncryptedSessionKeyEntity::TElPGPSymmetricKeyEncryptedSessionKeyEntity(TElPGPSymmetricKeyEncryptedSessionKeyEntityHandle handle, TElOwnHandle ownHandle) : TElPGPEntity(handle, ownHandle)
{
	initInstances();
}

TElPGPSymmetricKeyEncryptedSessionKeyEntity::TElPGPSymmetricKeyEncryptedSessionKeyEntity() : TElPGPEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPSymmetricKeyEncryptedSessionKeyEntity_Create(&_Handle));
}

TElPGPSymmetricKeyEncryptedSessionKeyEntity::~TElPGPSymmetricKeyEncryptedSessionKeyEntity()
{
#ifdef SB_USE_CLASS_TELPGPS2K
	delete this->_Inst_S2K;
	this->_Inst_S2K = NULL;
#endif /* SB_USE_CLASS_TELPGPS2K */
}
#endif /* SB_USE_CLASS_TELPGPSYMMETRICKEYENCRYPTEDSESSIONKEYENTITY */

#ifdef SB_USE_CLASS_TELPGPONEPASSSIGNATUREENTITY

SB_INLINE void TElPGPOnePassSignatureEntity::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPOnePassSignatureEntity_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPOnePassSignatureEntity::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPOnePassSignatureEntity_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPOnePassSignatureEntity::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPOnePassSignatureEntity_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPOnePassSignatureEntity::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPOnePassSignatureEntity_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE uint8_t TElPGPOnePassSignatureEntity::get_SignatureClass()
{
	uint8_t OutResult;
	SBCheckError(TElPGPOnePassSignatureEntity_get_SignatureClass(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPOnePassSignatureEntity::set_SignatureClass(uint8_t Value)
{
	SBCheckError(TElPGPOnePassSignatureEntity_set_SignatureClass(_Handle, Value));
}

SB_INLINE int32_t TElPGPOnePassSignatureEntity::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPOnePassSignatureEntity_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPOnePassSignatureEntity::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElPGPOnePassSignatureEntity_set_HashAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElPGPOnePassSignatureEntity::get_PublicKeyAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPOnePassSignatureEntity_get_PublicKeyAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPOnePassSignatureEntity::set_PublicKeyAlgorithm(int32_t Value)
{
	SBCheckError(TElPGPOnePassSignatureEntity_set_PublicKeyAlgorithm(_Handle, Value));
}

SB_INLINE void TElPGPOnePassSignatureEntity::get_KeyID(TSBKeyID &OutResult)
{
	SBCheckError(TElPGPOnePassSignatureEntity_get_KeyID(_Handle, &OutResult));
}

SB_INLINE void TElPGPOnePassSignatureEntity::set_KeyID(TSBKeyID &Value)
{
	SBCheckError(TElPGPOnePassSignatureEntity_set_KeyID(_Handle, &Value));
}

SB_INLINE uint8_t TElPGPOnePassSignatureEntity::get_Version()
{
	uint8_t OutResult;
	SBCheckError(TElPGPOnePassSignatureEntity_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPOnePassSignatureEntity::set_Version(uint8_t Value)
{
	SBCheckError(TElPGPOnePassSignatureEntity_set_Version(_Handle, Value));
}

SB_INLINE uint8_t TElPGPOnePassSignatureEntity::get_Nested()
{
	uint8_t OutResult;
	SBCheckError(TElPGPOnePassSignatureEntity_get_Nested(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPOnePassSignatureEntity::set_Nested(uint8_t Value)
{
	SBCheckError(TElPGPOnePassSignatureEntity_set_Nested(_Handle, Value));
}

TElPGPOnePassSignatureEntity::TElPGPOnePassSignatureEntity(TElPGPOnePassSignatureEntityHandle handle, TElOwnHandle ownHandle) : TElPGPEntity(handle, ownHandle)
{
}

TElPGPOnePassSignatureEntity::TElPGPOnePassSignatureEntity() : TElPGPEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPOnePassSignatureEntity_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPONEPASSSIGNATUREENTITY */

#ifdef SB_USE_CLASS_TELPGPSECRETKEYENTITY

SB_INLINE void TElPGPSecretKeyEntity::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPSecretKeyEntity_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPSecretKeyEntity::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPSecretKeyEntity_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPSecretKeyEntity::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPSecretKeyEntity_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPSecretKeyEntity::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPSecretKeyEntity_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE uint8_t TElPGPSecretKeyEntity::get_SymmetricAlgorithm()
{
	uint8_t OutResult;
	SBCheckError(TElPGPSecretKeyEntity_get_SymmetricAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSecretKeyEntity::set_SymmetricAlgorithm(uint8_t Value)
{
	SBCheckError(TElPGPSecretKeyEntity_set_SymmetricAlgorithm(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELPGPS2K
TElPGPS2K* TElPGPSecretKeyEntity::get_S2K()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPSecretKeyEntity_get_S2K(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_S2K)
		this->_Inst_S2K = new TElPGPS2K(hOutResult, ohFalse);
	else
		this->_Inst_S2K->updateHandle(hOutResult);
	return this->_Inst_S2K;
}

SB_INLINE void TElPGPSecretKeyEntity::set_S2K(TElPGPS2K &Value)
{
	SBCheckError(TElPGPSecretKeyEntity_set_S2K(_Handle, Value.getHandle()));
}

SB_INLINE void TElPGPSecretKeyEntity::set_S2K(TElPGPS2K *Value)
{
	SBCheckError(TElPGPSecretKeyEntity_set_S2K(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPS2K */

SB_INLINE uint8_t TElPGPSecretKeyEntity::get_S2KUsage()
{
	uint8_t OutResult;
	SBCheckError(TElPGPSecretKeyEntity_get_S2KUsage(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSecretKeyEntity::set_S2KUsage(uint8_t Value)
{
	SBCheckError(TElPGPSecretKeyEntity_set_S2KUsage(_Handle, Value));
}

void TElPGPSecretKeyEntity::get_IV(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPSecretKeyEntity_get_IV(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1198299137, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPSecretKeyEntity::set_IV(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPGPSecretKeyEntity_set_IV(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPGPSecretKeyEntity::get_EncryptedKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPGPSecretKeyEntity_get_EncryptedKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1936752746, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPSecretKeyEntity::set_EncryptedKey(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPGPSecretKeyEntity_set_EncryptedKey(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPGPSecretKeyEntity::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPS2K
	this->_Inst_S2K = NULL;
#endif /* SB_USE_CLASS_TELPGPS2K */
}

TElPGPSecretKeyEntity::TElPGPSecretKeyEntity(TElPGPSecretKeyEntityHandle handle, TElOwnHandle ownHandle) : TElPGPPublicKeyEntity(handle, ownHandle)
{
	initInstances();
}

TElPGPSecretKeyEntity::TElPGPSecretKeyEntity() : TElPGPPublicKeyEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPSecretKeyEntity_Create(&_Handle));
}

TElPGPSecretKeyEntity::TElPGPSecretKeyEntity(bool Subkey) : TElPGPPublicKeyEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPSecretKeyEntity_Create_1((int8_t)Subkey, &_Handle));
}

TElPGPSecretKeyEntity::~TElPGPSecretKeyEntity()
{
#ifdef SB_USE_CLASS_TELPGPS2K
	delete this->_Inst_S2K;
	this->_Inst_S2K = NULL;
#endif /* SB_USE_CLASS_TELPGPS2K */
}
#endif /* SB_USE_CLASS_TELPGPSECRETKEYENTITY */

#ifdef SB_USE_CLASS_TELPGPSTREAMINGENTITY

SB_INLINE void TElPGPStreamingEntity::DataAvailable()
{
	SBCheckError(TElPGPStreamingEntity_DataAvailable(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPStreamingEntity::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElPGPStreamingEntity_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElPGPStreamingEntity::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElPGPStreamingEntity_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPStreamingEntity::SaveToStream(TStream &Stream)
{
	SBCheckError(TElPGPStreamingEntity_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElPGPStreamingEntity::SaveToStream(TStream *Stream)
{
	SBCheckError(TElPGPStreamingEntity_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPGPStreamingEntity::Save(void * AReadUserData, void * AWriteUserData)
{
	SBCheckError(TElPGPStreamingEntity_Save(_Handle, AReadUserData, AWriteUserData));
}

bool TElPGPStreamingEntity::get_WriteFixedLength()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPStreamingEntity_get_WriteFixedLength(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPStreamingEntity::set_WriteFixedLength(bool Value)
{
	SBCheckError(TElPGPStreamingEntity_set_WriteFixedLength(_Handle, (int8_t)Value));
}

SB_INLINE void TElPGPStreamingEntity::get_OnHeaderProcessed(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPStreamingEntity_get_OnHeaderProcessed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPStreamingEntity::set_OnHeaderProcessed(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPStreamingEntity_set_OnHeaderProcessed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPStreamingEntity::get_OnTemporaryStream(TSBPGPTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPStreamingEntity_get_OnTemporaryStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPStreamingEntity::set_OnTemporaryStream(TSBPGPTemporaryStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPStreamingEntity_set_OnTemporaryStream(_Handle, pMethodValue, pDataValue));
}

TElPGPStreamingEntity::TElPGPStreamingEntity(TElPGPStreamingEntityHandle handle, TElOwnHandle ownHandle) : TElPGPEntity(handle, ownHandle)
{
}

TElPGPStreamingEntity::TElPGPStreamingEntity() : TElPGPEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPStreamingEntity_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPSTREAMINGENTITY */

#ifdef SB_USE_CLASS_TELPGPLITERAL

SB_INLINE void TElPGPLiteral::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPLiteral_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPLiteral::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPLiteral_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPLiteral::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPLiteral_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPLiteral::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPLiteral_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

void TElPGPLiteral::get_Filename(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPLiteral_get_Filename(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-669039968, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPLiteral::set_Filename(const std::string &Value)
{
	SBCheckError(TElPGPLiteral_set_Filename(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElPGPLiteral::get_Timestamp()
{
	int64_t OutResult;
	SBCheckError(TElPGPLiteral_get_Timestamp(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPLiteral::set_Timestamp(int64_t Value)
{
	SBCheckError(TElPGPLiteral_set_Timestamp(_Handle, Value));
}

bool TElPGPLiteral::get_TextMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPLiteral_get_TextMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPLiteral::set_TextMode(bool Value)
{
	SBCheckError(TElPGPLiteral_set_TextMode(_Handle, (int8_t)Value));
}

TElPGPLiteral::TElPGPLiteral(TElPGPLiteralHandle handle, TElOwnHandle ownHandle) : TElPGPStreamingEntity(handle, ownHandle)
{
}

TElPGPLiteral::TElPGPLiteral() : TElPGPStreamingEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPLiteral_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPLITERAL */

#ifdef SB_USE_CLASS_TELPGPSYMMETRICALLYENCRYPTED

SB_INLINE void TElPGPSymmetricallyEncrypted::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPSymmetricallyEncrypted_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPSymmetricallyEncrypted::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPSymmetricallyEncrypted_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPSymmetricallyEncrypted::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPSymmetricallyEncrypted_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPSymmetricallyEncrypted::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPSymmetricallyEncrypted_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

bool TElPGPSymmetricallyEncrypted::get_IntegrityProtected()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPSymmetricallyEncrypted_get_IntegrityProtected(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPSymmetricallyEncrypted::set_IntegrityProtected(bool Value)
{
	SBCheckError(TElPGPSymmetricallyEncrypted_set_IntegrityProtected(_Handle, (int8_t)Value));
}

SB_INLINE uint8_t TElPGPSymmetricallyEncrypted::get_Version()
{
	uint8_t OutResult;
	SBCheckError(TElPGPSymmetricallyEncrypted_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSymmetricallyEncrypted::set_Version(uint8_t Value)
{
	SBCheckError(TElPGPSymmetricallyEncrypted_set_Version(_Handle, Value));
}

TElPGPSymmetricallyEncrypted::TElPGPSymmetricallyEncrypted(TElPGPSymmetricallyEncryptedHandle handle, TElOwnHandle ownHandle) : TElPGPStreamingEntity(handle, ownHandle)
{
}

TElPGPSymmetricallyEncrypted::TElPGPSymmetricallyEncrypted() : TElPGPStreamingEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPSymmetricallyEncrypted_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPSYMMETRICALLYENCRYPTED */

#ifdef SB_USE_CLASS_TELPGPCOMPRESSED

SB_INLINE void TElPGPCompressed::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPCompressed_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPCompressed::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPCompressed_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPCompressed::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPCompressed_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPCompressed::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPCompressed_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE uint8_t TElPGPCompressed::get_Algorithm()
{
	uint8_t OutResult;
	SBCheckError(TElPGPCompressed_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPCompressed::set_Algorithm(uint8_t Value)
{
	SBCheckError(TElPGPCompressed_set_Algorithm(_Handle, Value));
}

TElPGPCompressed::TElPGPCompressed(TElPGPCompressedHandle handle, TElOwnHandle ownHandle) : TElPGPStreamingEntity(handle, ownHandle)
{
}

TElPGPCompressed::TElPGPCompressed() : TElPGPStreamingEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPCompressed_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPCOMPRESSED */

#ifdef SB_USE_CLASS_TELPGPSTREAMPROCESSOR

SB_INLINE void TElPGPStreamProcessor::Assign(TPersistent &Source)
{
	SBCheckError(TElPGPStreamProcessor_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElPGPStreamProcessor::Assign(TPersistent *Source)
{
	SBCheckError(TElPGPStreamProcessor_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPStreamProcessor::AssignTo(TPersistent &Dest)
{
	SBCheckError(TElPGPStreamProcessor_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElPGPStreamProcessor::AssignTo(TPersistent *Dest)
{
	SBCheckError(TElPGPStreamProcessor_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPGPStreamProcessor::Process(void * AReadUserData, void * AWriteUserData)
{
	SBCheckError(TElPGPStreamProcessor_Process(_Handle, AReadUserData, AWriteUserData));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPStreamProcessor::ProcessStream(TStream &Stream)
{
	SBCheckError(TElPGPStreamProcessor_ProcessStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElPGPStreamProcessor::ProcessStream(TStream *Stream)
{
	SBCheckError(TElPGPStreamProcessor_ProcessStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElPGPStreamProcessor::DataAvailable()
{
	SBCheckError(TElPGPStreamProcessor_DataAvailable(_Handle));
}

#ifdef SB_USE_CLASS_TELPGPENTITY
TElPGPEntity* TElPGPStreamProcessor::get_CurrentEntity()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPStreamProcessor_get_CurrentEntity(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CurrentEntity)
		this->_Inst_CurrentEntity = new TElPGPEntity(hOutResult, ohFalse);
	else
		this->_Inst_CurrentEntity->updateHandle(hOutResult);
	return this->_Inst_CurrentEntity;
}
#endif /* SB_USE_CLASS_TELPGPENTITY */

bool TElPGPStreamProcessor::get_Empty()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPStreamProcessor_get_Empty(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPStreamProcessor::set_Empty(bool Value)
{
	SBCheckError(TElPGPStreamProcessor_set_Empty(_Handle, (int8_t)Value));
}

bool TElPGPStreamProcessor::get_AsyncMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPStreamProcessor_get_AsyncMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPStreamProcessor::set_AsyncMode(bool Value)
{
	SBCheckError(TElPGPStreamProcessor_set_AsyncMode(_Handle, (int8_t)Value));
}

SB_INLINE void * TElPGPStreamProcessor::get_ReadUserData()
{
	void * OutResult;
	SBCheckError(TElPGPStreamProcessor_get_ReadUserData(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void * TElPGPStreamProcessor::get_WriteUserData()
{
	void * OutResult;
	SBCheckError(TElPGPStreamProcessor_get_WriteUserData(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPStreamProcessor::get_OnRead(TSBPGPReadEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPStreamProcessor_get_OnRead(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPStreamProcessor::set_OnRead(TSBPGPReadEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPStreamProcessor_set_OnRead(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPStreamProcessor::get_OnWrite(TSBPGPWriteEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPStreamProcessor_get_OnWrite(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPStreamProcessor::set_OnWrite(TSBPGPWriteEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPStreamProcessor_set_OnWrite(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPStreamProcessor::get_OnPacket(TSBPGPPacketEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPStreamProcessor_get_OnPacket(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPStreamProcessor::set_OnPacket(TSBPGPPacketEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPStreamProcessor_set_OnPacket(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPStreamProcessor::get_OnPacketProcessed(TSBPGPPacketProcessedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPStreamProcessor_get_OnPacketProcessed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPStreamProcessor::set_OnPacketProcessed(TSBPGPPacketProcessedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPStreamProcessor_set_OnPacketProcessed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPStreamProcessor::get_OnFinish(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPStreamProcessor_get_OnFinish(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPStreamProcessor::set_OnFinish(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPStreamProcessor_set_OnFinish(_Handle, pMethodValue, pDataValue));
}

void TElPGPStreamProcessor::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPENTITY
	this->_Inst_CurrentEntity = NULL;
#endif /* SB_USE_CLASS_TELPGPENTITY */
}

TElPGPStreamProcessor::TElPGPStreamProcessor(TElPGPStreamProcessorHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElPGPStreamProcessor::TElPGPStreamProcessor() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPStreamProcessor_Create(&_Handle));
}

TElPGPStreamProcessor::~TElPGPStreamProcessor()
{
#ifdef SB_USE_CLASS_TELPGPENTITY
	delete this->_Inst_CurrentEntity;
	this->_Inst_CurrentEntity = NULL;
#endif /* SB_USE_CLASS_TELPGPENTITY */
}
#endif /* SB_USE_CLASS_TELPGPSTREAMPROCESSOR */

#ifdef SB_USE_CLASS_TELPGPSTUBENTITY

TElPGPStubEntity::TElPGPStubEntity(TElPGPStubEntityHandle handle, TElOwnHandle ownHandle) : TElPGPEntity(handle, ownHandle)
{
}

TElPGPStubEntity::TElPGPStubEntity() : TElPGPEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPStubEntity_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPSTUBENTITY */

#ifdef SB_USE_CLASS_TELPGPSTREAMIO

void TElPGPStreamIO::Read(TObject &Sender, void * UserData, void * Buffer, int32_t MaxSize, int32_t &Written, bool &Last)
{
	int8_t LastRaw = (int8_t)Last;
	SBCheckError(TElPGPStreamIO_Read(_Handle, Sender.getHandle(), UserData, Buffer, MaxSize, &Written, &LastRaw));
	Last = (LastRaw != 0);
}

void TElPGPStreamIO::Read(TObject *Sender, void * UserData, void * Buffer, int32_t MaxSize, int32_t &Written, bool &Last)
{
	int8_t LastRaw = (int8_t)Last;
	SBCheckError(TElPGPStreamIO_Read(_Handle, (Sender != NULL) ? Sender->getHandle() : SB_NULL_HANDLE, UserData, Buffer, MaxSize, &Written, &LastRaw));
	Last = (LastRaw != 0);
}

SB_INLINE void TElPGPStreamIO::Write(TObject &Sender, void * UserData, void * Buffer, int32_t Size)
{
	SBCheckError(TElPGPStreamIO_Write(_Handle, Sender.getHandle(), UserData, Buffer, Size));
}

SB_INLINE void TElPGPStreamIO::Write(TObject *Sender, void * UserData, void * Buffer, int32_t Size)
{
	SBCheckError(TElPGPStreamIO_Write(_Handle, (Sender != NULL) ? Sender->getHandle() : SB_NULL_HANDLE, UserData, Buffer, Size));
}

#ifdef SB_USE_CLASS_TSTREAM
TStream* TElPGPStreamIO::get_Stream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPStreamIO_get_Stream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Stream)
		this->_Inst_Stream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_Stream->updateHandle(hOutResult);
	return this->_Inst_Stream;
}

SB_INLINE void TElPGPStreamIO::set_Stream(TStream &Value)
{
	SBCheckError(TElPGPStreamIO_set_Stream(_Handle, Value.getHandle()));
}

SB_INLINE void TElPGPStreamIO::set_Stream(TStream *Value)
{
	SBCheckError(TElPGPStreamIO_set_Stream(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElPGPStreamIO::initInstances()
{
#ifdef SB_USE_CLASS_TSTREAM
	this->_Inst_Stream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
}

TElPGPStreamIO::TElPGPStreamIO(TElPGPStreamIOHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TSTREAM
TElPGPStreamIO::TElPGPStreamIO(TStream &Strm) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPStreamIO_Create(Strm.getHandle(), &_Handle));
}

TElPGPStreamIO::TElPGPStreamIO(TStream *Strm) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPStreamIO_Create((Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TSTREAM */

TElPGPStreamIO::~TElPGPStreamIO()
{
#ifdef SB_USE_CLASS_TSTREAM
	delete this->_Inst_Stream;
	this->_Inst_Stream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
}
#endif /* SB_USE_CLASS_TELPGPSTREAMIO */

#ifdef SB_USE_GLOBAL_PROCS_PGPENTITIES

#ifdef SB_USE_CLASS_TELPGPENTITY
SB_INLINE TElPGPEntityHandle CreateEntity(uint8_t PktType)
{
	TElPGPEntityHandle OutResult;
	SBCheckError(SBPGPEntities_CreateEntity(PktType, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPENTITY */

#ifdef SB_USE_CLASS_TELPGPENTITY
SB_INLINE TElPGPEntityHandle CloneEntity(TElPGPEntity &Entity)
{
	TElPGPEntityHandle OutResult;
	SBCheckError(SBPGPEntities_CloneEntity(Entity.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE TElPGPEntityHandle CloneEntity(TElPGPEntity *Entity)
{
	TElPGPEntityHandle OutResult;
	SBCheckError(SBPGPEntities_CloneEntity((Entity != NULL) ? Entity->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPENTITY */

#endif /* SB_USE_GLOBAL_PROCS_PGPENTITIES */

};	/* namespace SecureBlackbox */

