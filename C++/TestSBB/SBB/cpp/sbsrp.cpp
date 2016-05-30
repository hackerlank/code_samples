#include "sbsrp.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSRPCREDENTIAL

SB_INLINE void TElSRPCredential::Generate(const std::string &Username, const std::string &Password, TSBSRPCredentialPrimeLen PrimeLen)
{
	SBCheckError(TElSRPCredential_Generate(_Handle, Username.data(), (int32_t)Username.length(), Password.data(), (int32_t)Password.length(), (TSBSRPCredentialPrimeLenRaw)PrimeLen));
}

SB_INLINE void TElSRPCredential::Generate(const std::string &Username, const std::string &Password, const std::vector<uint8_t> &Prime, const std::vector<uint8_t> &Generator)
{
	SBCheckError(TElSRPCredential_Generate_1(_Handle, Username.data(), (int32_t)Username.length(), Password.data(), (int32_t)Password.length(), SB_STD_VECTOR_FRONT_ADR(Prime), (int32_t)Prime.size(), SB_STD_VECTOR_FRONT_ADR(Generator), (int32_t)Generator.size()));
}

SB_INLINE void TElSRPCredential::Load(const std::string &Data)
{
	SBCheckError(TElSRPCredential_Load(_Handle, Data.data(), (int32_t)Data.length()));
}

SB_INLINE void TElSRPCredential::Load(const std::string &Username, const std::vector<uint8_t> &Salt, const std::vector<uint8_t> &Prime, const std::vector<uint8_t> &Generator, const std::vector<uint8_t> &Verifier)
{
	SBCheckError(TElSRPCredential_Load_1(_Handle, Username.data(), (int32_t)Username.length(), SB_STD_VECTOR_FRONT_ADR(Salt), (int32_t)Salt.size(), SB_STD_VECTOR_FRONT_ADR(Prime), (int32_t)Prime.size(), SB_STD_VECTOR_FRONT_ADR(Generator), (int32_t)Generator.size(), SB_STD_VECTOR_FRONT_ADR(Verifier), (int32_t)Verifier.size()));
}

void TElSRPCredential::Save(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSRPCredential_Save(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-771191387, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSRPCredential::get_Username(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSRPCredential_get_Username(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1256693578, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSRPCredential::get_Prime(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSRPCredential_get_Prime(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-228639922, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSRPCredential::get_Generator(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSRPCredential_get_Generator(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-192798531, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSRPCredential::set_Generator(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSRPCredential_set_Generator(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElSRPCredential::get_Salt(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSRPCredential_get_Salt(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(687009396, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSRPCredential::get_Verifier(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSRPCredential_get_Verifier(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1227412343, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElSRPCredential::TElSRPCredential(TElSRPCredentialHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSRPCredential::TElSRPCredential() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSRPCredential_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSRPCREDENTIAL */

#ifdef SB_USE_CLASS_TELSRPCREDENTIALSTORE

SB_INLINE int32_t TElSRPCredentialStore::Add()
{
	int32_t OutResult;
	SBCheckError(TElSRPCredentialStore_Add(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSRPCredentialStore::Add(const std::string &Username, const std::string &Password, TSBSRPCredentialPrimeLen PrimeLen)
{
	int32_t OutResult;
	SBCheckError(TElSRPCredentialStore_Add_1(_Handle, Username.data(), (int32_t)Username.length(), Password.data(), (int32_t)Password.length(), (TSBSRPCredentialPrimeLenRaw)PrimeLen, &OutResult));
	return OutResult;
}

SB_INLINE void TElSRPCredentialStore::Remove(int32_t Index)
{
	SBCheckError(TElSRPCredentialStore_Remove(_Handle, Index));
}

SB_INLINE void TElSRPCredentialStore::Clear()
{
	SBCheckError(TElSRPCredentialStore_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSRPCredentialStore::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElSRPCredentialStore_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElSRPCredentialStore::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElSRPCredentialStore_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElSRPCredentialStore::SaveToStream(TStream &Stream)
{
	SBCheckError(TElSRPCredentialStore_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElSRPCredentialStore::SaveToStream(TStream *Stream)
{
	SBCheckError(TElSRPCredentialStore_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELSRPCREDENTIAL
TElSRPCredential* TElSRPCredentialStore::get_Credentials(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSRPCredentialStore_get_Credentials(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Credentials)
		this->_Inst_Credentials = new TElSRPCredential(hOutResult, ohFalse);
	else
		this->_Inst_Credentials->updateHandle(hOutResult);
	return this->_Inst_Credentials;
}
#endif /* SB_USE_CLASS_TELSRPCREDENTIAL */

SB_INLINE int32_t TElSRPCredentialStore::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElSRPCredentialStore_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElSRPCredentialStore::initInstances()
{
#ifdef SB_USE_CLASS_TELSRPCREDENTIAL
	this->_Inst_Credentials = NULL;
#endif /* SB_USE_CLASS_TELSRPCREDENTIAL */
}

TElSRPCredentialStore::TElSRPCredentialStore(TElSRPCredentialStoreHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElSRPCredentialStore::TElSRPCredentialStore(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSRPCredentialStore_Create(AOwner.getHandle(), &_Handle));
}

TElSRPCredentialStore::TElSRPCredentialStore(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSRPCredentialStore_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSRPCredentialStore::~TElSRPCredentialStore()
{
#ifdef SB_USE_CLASS_TELSRPCREDENTIAL
	delete this->_Inst_Credentials;
	this->_Inst_Credentials = NULL;
#endif /* SB_USE_CLASS_TELSRPCREDENTIAL */
}
#endif /* SB_USE_CLASS_TELSRPCREDENTIALSTORE */

#ifdef SB_USE_GLOBAL_PROCS_SRP

SB_INLINE void SrpInitContext(TSRPContext &SRP)
{
	SBCheckError(SBSRP_SrpInitContext(&SRP));
}

SB_INLINE void SrpDestroyContext(TSRPContext &SRP)
{
	SBCheckError(SBSRP_SrpDestroyContext(&SRP));
}

SB_INLINE void SrpServerInit(TSRPContext &SRP)
{
	SBCheckError(SBSRP_SrpServerInit(&SRP));
}

SB_INLINE void SrpGetU(PLInt N, PLInt A, PLInt B, const std::string &Proto, PLInt &U)
{
	SBCheckError(SBSRP_SrpGetU(N, A, B, Proto.data(), (int32_t)Proto.length(), &U));
}

SB_INLINE void SrpGetUTLS(PLInt A, PLInt B, PLInt N, PLInt &U)
{
	SBCheckError(SBSRP_SrpGetUTLS(A, B, N, &U));
}

SB_INLINE void SrpGetA(TSRPContext &SRP)
{
	SBCheckError(SBSRP_SrpGetA(&SRP));
}

SB_INLINE void SrpGetB(TSRPContext &SRP)
{
	SBCheckError(SBSRP_SrpGetB(&SRP));
}

SB_INLINE void SrpGetK(TSRPContext &SRP)
{
	SBCheckError(SBSRP_SrpGetK(&SRP));
}

SB_INLINE void SrpPrepareClientX(const std::string &Username, const std::string &Password, const std::vector<uint8_t> &Salt, PLInt &ClX)
{
	SBCheckError(SBSRP_SrpPrepareClientX(Username.data(), (int32_t)Username.length(), Password.data(), (int32_t)Password.length(), SB_STD_VECTOR_FRONT_ADR(Salt), (int32_t)Salt.size(), &ClX));
}

SB_INLINE void SrpGetClientKey(TSRPContext &SRP)
{
	SBCheckError(SBSRP_SrpGetClientKey(&SRP));
}

SB_INLINE void SrpPrepareClientKeyTLS(TSRPContext &SRP)
{
	SBCheckError(SBSRP_SrpPrepareClientKeyTLS(&SRP));
}

SB_INLINE void SrpPrepareServerPreKeyTLS(TSRPContext &SRP)
{
	SBCheckError(SBSRP_SrpPrepareServerPreKeyTLS(&SRP));
}

SB_INLINE void SrpPrepareServerKeyTLS(TSRPContext &SRP)
{
	SBCheckError(SBSRP_SrpPrepareServerKeyTLS(&SRP));
}

SB_INLINE void SrpGetServerKey(TSRPContext &SRP)
{
	SBCheckError(SBSRP_SrpGetServerKey(&SRP));
}

void SrpGetNewServerData(const std::string &UserName, const std::string &UserPassword, TSSRPPrimeLen PrimeLen, std::vector<uint8_t> &N, std::vector<uint8_t> &G, std::vector<uint8_t> &Salt, std::vector<uint8_t> &V)
{
	int32_t szN = (int32_t)N.size();
	int32_t szG = (int32_t)G.size();
	int32_t szSalt = (int32_t)Salt.size();
	int32_t szV = (int32_t)V.size();
	uint32_t _err = SBSRP_SrpGetNewServerData(UserName.data(), (int32_t)UserName.length(), UserPassword.data(), (int32_t)UserPassword.length(), (TSSRPPrimeLenRaw)PrimeLen, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(N), &szN, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(G), &szG, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Salt), &szSalt, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(V), &szV);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		N.resize(szN);
		SBCheckError(SBGetLastReturnBuffer(1995399686, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(N), &szN));
		G.resize(szG);
		SBCheckError(SBGetLastReturnBuffer(1995399686, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(G), &szG));
		Salt.resize(szSalt);
		SBCheckError(SBGetLastReturnBuffer(1995399686, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Salt), &szSalt));
		V.resize(szV);
		SBCheckError(SBGetLastReturnBuffer(1995399686, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(V), &szV));
	}
	else
		SBCheckError(_err);

	N.resize(szN);
	G.resize(szG);
	Salt.resize(szSalt);
	V.resize(szV);
}

void SrpLIntToBytesImplicit(PLInt X, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBSRP_SrpLIntToBytesImplicit(X, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-635829881, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SrpLIntToBytesPAD(PLInt X, int32_t Len, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBSRP_SrpLIntToBytesPAD(X, Len, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(116353562, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void LIntToBytes(PLInt I, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBSRP_LIntToBytes(I, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1101215986, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void LInitBytes(PLInt I, const std::vector<uint8_t> &BA)
{
	SBCheckError(SBSRP_LInitBytes(I, SB_STD_VECTOR_FRONT_ADR(BA), (int32_t)BA.size()));
}

void SrpGenerateVerifier(const std::string &Username, const std::string &Password, const std::vector<uint8_t> &Prime, const std::vector<uint8_t> &Generator, const std::vector<uint8_t> &Salt, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBSRP_SrpGenerateVerifier(Username.data(), (int32_t)Username.length(), Password.data(), (int32_t)Password.length(), SB_STD_VECTOR_FRONT_ADR(Prime), (int32_t)Prime.size(), SB_STD_VECTOR_FRONT_ADR(Generator), (int32_t)Generator.size(), SB_STD_VECTOR_FRONT_ADR(Salt), (int32_t)Salt.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-503293982, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#endif /* SB_USE_GLOBAL_PROCS_SRP */

};	/* namespace SecureBlackbox */

