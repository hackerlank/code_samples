#include "sbsshkeystorage.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSSHKEY

bool TElSSHKey::IsKeyValid()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHKey_IsKeyValid(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElSSHKey::Copy(TElSSHKey &Dest)
{
	TElClassHandle hDest = Dest.getHandle();
	SBCheckError(TElSSHKey_Copy(_Handle, &hDest));
	Dest.updateHandle(hDest);
}

SB_INLINE void TElSSHKey::Clear()
{
	SBCheckError(TElSSHKey_Clear(_Handle));
}

SB_INLINE TElSSHKeyHandle TElSSHKey::Clone()
{
	TElSSHKeyHandle OutResult;
	SBCheckError(TElSSHKey_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE TElSSHKeyHandle TElSSHKey::CreateObjectInstance()
{
	TElSSHKeyHandle OutResult;
	SBCheckError(TElSSHKey_CreateObjectInstance(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHKey::Generate(int32_t Algorithm, int32_t Bits)
{
	int32_t OutResult;
	SBCheckError(TElSSHKey_Generate(_Handle, Algorithm, Bits, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHKey::GenerateEC(int32_t Curve)
{
	int32_t OutResult;
	SBCheckError(TElSSHKey_GenerateEC(_Handle, Curve, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHKey::LoadPublicKey(const std::string &PublicKeyFile)
{
	int32_t OutResult;
	SBCheckError(TElSSHKey_LoadPublicKey(_Handle, PublicKeyFile.data(), (int32_t)PublicKeyFile.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHKey::LoadPublicKey(void * Buffer, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElSSHKey_LoadPublicKey_1(_Handle, Buffer, Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHKey::LoadPrivateKey(const std::string &PrivateKeyFile, const std::string &Passphrase)
{
	int32_t OutResult;
	SBCheckError(TElSSHKey_LoadPrivateKey(_Handle, PrivateKeyFile.data(), (int32_t)PrivateKeyFile.length(), Passphrase.data(), (int32_t)Passphrase.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHKey::LoadPrivateKey(void * Buffer, int32_t Size, const std::string &Passphrase)
{
	int32_t OutResult;
	SBCheckError(TElSSHKey_LoadPrivateKey_1(_Handle, Buffer, Size, Passphrase.data(), (int32_t)Passphrase.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHKey::SavePublicKey(void * Buffer, int32_t &Size, TSBEOLMarker EOLMarker)
{
	int32_t OutResult;
	SBCheckError(TElSSHKey_SavePublicKey(_Handle, Buffer, &Size, (TSBEOLMarkerRaw)EOLMarker, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHKey::SavePublicKey(const std::string &PublicKeyFile, TSBEOLMarker EOLMarker)
{
	int32_t OutResult;
	SBCheckError(TElSSHKey_SavePublicKey_1(_Handle, PublicKeyFile.data(), (int32_t)PublicKeyFile.length(), (TSBEOLMarkerRaw)EOLMarker, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHKey::SavePrivateKey(void * Buffer, int32_t &Size, const std::string &Passphrase)
{
	int32_t OutResult;
	SBCheckError(TElSSHKey_SavePrivateKey(_Handle, Buffer, &Size, Passphrase.data(), (int32_t)Passphrase.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHKey::SavePrivateKey(const std::string &PrivateKeyFile, const std::string &Passphrase)
{
	int32_t OutResult;
	SBCheckError(TElSSHKey_SavePrivateKey_1(_Handle, PrivateKeyFile.data(), (int32_t)PrivateKeyFile.length(), Passphrase.data(), (int32_t)Passphrase.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElSSHKey::Import(TElX509Certificate &Certificate)
{
	SBCheckError(TElSSHKey_Import(_Handle, Certificate.getHandle()));
}

SB_INLINE void TElSSHKey::Import(TElX509Certificate *Certificate)
{
	SBCheckError(TElSSHKey_Import(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE int32_t TElSSHKey::LoadPublicKeyFromBlob(const std::string &AlgName, void * Buffer, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElSSHKey_LoadPublicKeyFromBlob(_Handle, AlgName.data(), (int32_t)AlgName.length(), Buffer, Size, &OutResult));
	return OutResult;
}

int32_t TElSSHKey::SavePublicKeyToBlob(std::string &AlgName, void * Buffer, int32_t &Size)
{
	int32_t OutResult;
	int32_t szAlgName = (int32_t)AlgName.length();
	uint32_t _err = TElSSHKey_SavePublicKeyToBlob(_Handle, (char *)AlgName.data(), &szAlgName, Buffer, &Size, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		AlgName.resize(szAlgName);
		SBCheckError(SBGetLastReturnStringA(1349135830, 1, (char *)AlgName.data(), &szAlgName));
	}
	else
		SBCheckError(_err);

	AlgName.resize(szAlgName);
	return OutResult;
}

void TElSSHKey::get_RSAPublicExponent(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHKey_get_RSAPublicExponent(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(805138151, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHKey::set_RSAPublicExponent(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSSHKey_set_RSAPublicExponent(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElSSHKey::get_RSAPublicModulus(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHKey_get_RSAPublicModulus(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1068118099, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHKey::set_RSAPublicModulus(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSSHKey_set_RSAPublicModulus(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElSSHKey::get_RSAPrivateExponent(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHKey_get_RSAPrivateExponent(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2046612759, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHKey::set_RSAPrivateExponent(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSSHKey_set_RSAPrivateExponent(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElSSHKey::get_DSSP(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHKey_get_DSSP(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-750935818, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHKey::set_DSSP(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSSHKey_set_DSSP(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElSSHKey::get_DSSQ(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHKey_get_DSSQ(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1539665824, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHKey::set_DSSQ(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSSHKey_set_DSSQ(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElSSHKey::get_DSSG(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHKey_get_DSSG(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1357784369, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHKey::set_DSSG(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSSHKey_set_DSSG(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElSSHKey::get_DSSY(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHKey_get_DSSY(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1428088750, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHKey::set_DSSY(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSSHKey_set_DSSY(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElSSHKey::get_DSSX(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHKey_get_DSSX(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-572118844, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHKey::set_DSSX(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSSHKey_set_DSSX(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElSSHKey::get_CurveID()
{
	int32_t OutResult;
	SBCheckError(TElSSHKey_get_CurveID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHKey::set_CurveID(int32_t Value)
{
	SBCheckError(TElSSHKey_set_CurveID(_Handle, Value));
}

void TElSSHKey::get_ECCD(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHKey_get_ECCD(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(666870479, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHKey::set_ECCD(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSSHKey_set_ECCD(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElSSHKey::get_ECCQX(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHKey_get_ECCQX(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1509515089, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHKey::set_ECCQX(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSSHKey_set_ECCQX(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElSSHKey::get_ECCQY(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSSHKey_get_ECCQY(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(788426695, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHKey::set_ECCQY(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElSSHKey_set_ECCQY(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE void TElSSHKey::get_FingerprintMD5(TMessageDigest128 &OutResult)
{
	SBCheckError(TElSSHKey_get_FingerprintMD5(_Handle, &OutResult));
}

void TElSSHKey::get_FingerprintMD5String(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHKey_get_FingerprintMD5String(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1073589137, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHKey::get_FingerprintSHA1(TMessageDigest160 &OutResult)
{
	SBCheckError(TElSSHKey_get_FingerprintSHA1(_Handle, &OutResult));
}

void TElSSHKey::get_FingerprintSHA1String(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHKey_get_FingerprintSHA1String(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(587708403, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElSSHKey::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElSSHKey_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHKey::set_Algorithm(int32_t Value)
{
	SBCheckError(TElSSHKey_set_Algorithm(_Handle, Value));
}

SB_INLINE int32_t TElSSHKey::get_Bits()
{
	int32_t OutResult;
	SBCheckError(TElSSHKey_get_Bits(_Handle, &OutResult));
	return OutResult;
}

void TElSSHKey::get_Comment(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHKey_get_Comment(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(258202189, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHKey::set_Comment(const std::string &Value)
{
	SBCheckError(TElSSHKey_set_Comment(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElSSHKey::get_Subject(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElSSHKey_get_Subject(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1624880731, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSSHKey::set_Subject(const std::string &Value)
{
	SBCheckError(TElSSHKey_set_Subject(_Handle, Value.data(), (int32_t)Value.length()));
}

TSBSSHKeyFormat TElSSHKey::get_KeyFormat()
{
	TSBSSHKeyFormatRaw OutResultRaw = 0;
	SBCheckError(TElSSHKey_get_KeyFormat(_Handle, &OutResultRaw));
	return (TSBSSHKeyFormat)OutResultRaw;
}

SB_INLINE void TElSSHKey::set_KeyFormat(TSBSSHKeyFormat Value)
{
	SBCheckError(TElSSHKey_set_KeyFormat(_Handle, (TSBSSHKeyFormatRaw)Value));
}

SB_INLINE int32_t TElSSHKey::get_KeyProtectionAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElSSHKey_get_KeyProtectionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSSHKey::set_KeyProtectionAlgorithm(int32_t Value)
{
	SBCheckError(TElSSHKey_set_KeyProtectionAlgorithm(_Handle, Value));
}

bool TElSSHKey::get_IsPrivate()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHKey_get_IsPrivate(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSSHKey::get_IsPublic()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHKey_get_IsPublic(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElSSHKey::get_IsExtractable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHKey_get_IsExtractable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElSSHKey::get_Headers()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHKey_get_Headers(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Headers)
		this->_Inst_Headers = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Headers->updateHandle(hOutResult);
	return this->_Inst_Headers;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
TElStringList* TElSSHKey::get_Headers()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHKey_get_Headers(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Headers)
		this->_Inst_Headers = new TElStringList(hOutResult, ohFalse);
	else
		this->_Inst_Headers->updateHandle(hOutResult);
	return this->_Inst_Headers;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElSSHKey::get_Certificate()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHKey_get_Certificate(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificate)
		this->_Inst_Certificate = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_Certificate->updateHandle(hOutResult);
	return this->_Inst_Certificate;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
TElPublicKeyMaterial* TElSSHKey::get_KeyMaterial()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHKey_get_KeyMaterial(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_KeyMaterial)
		this->_Inst_KeyMaterial = new TElPublicKeyMaterial(hOutResult, ohFalse);
	else
		this->_Inst_KeyMaterial->updateHandle(hOutResult);
	return this->_Inst_KeyMaterial;
}
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

bool TElSSHKey::get_UsePlatformKeyGeneration()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSSHKey_get_UsePlatformKeyGeneration(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSSHKey::set_UsePlatformKeyGeneration(bool Value)
{
	SBCheckError(TElSSHKey_set_UsePlatformKeyGeneration(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElSSHKey::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHKey_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElSSHKey::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElSSHKey_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHKey::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElSSHKey_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

void TElSSHKey::initInstances()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Headers = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	this->_Inst_Headers = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_Certificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}

TElSSHKey::TElSSHKey(TElSSHKeyHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElSSHKey::TElSSHKey() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHKey_Create(&_Handle));
}

TElSSHKey::~TElSSHKey()
{
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Headers;
	this->_Inst_Headers = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
	delete this->_Inst_Headers;
	this->_Inst_Headers = NULL;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_Certificate;
	this->_Inst_Certificate = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
	delete this->_Inst_KeyMaterial;
	this->_Inst_KeyMaterial = NULL;
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE

#ifdef SB_USE_CLASS_TELSSHKEY
SB_INLINE void TElSSHCustomKeyStorage::Add(TElSSHKey &Key)
{
	SBCheckError(TElSSHCustomKeyStorage_Add(_Handle, Key.getHandle()));
}

SB_INLINE void TElSSHCustomKeyStorage::Add(TElSSHKey *Key)
{
	SBCheckError(TElSSHCustomKeyStorage_Add(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHKEY */

SB_INLINE void TElSSHCustomKeyStorage::Remove(int32_t Index)
{
	SBCheckError(TElSSHCustomKeyStorage_Remove(_Handle, Index));
}

SB_INLINE void TElSSHCustomKeyStorage::Clear()
{
	SBCheckError(TElSSHCustomKeyStorage_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELSSHKEY
SB_INLINE int32_t TElSSHCustomKeyStorage::IndexOf(TElSSHKey &Key)
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomKeyStorage_IndexOf(_Handle, Key.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHCustomKeyStorage::IndexOf(TElSSHKey *Key)
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomKeyStorage_IndexOf(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElSSHCustomKeyStorage::LoadPublic(TStream &F, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomKeyStorage_LoadPublic(_Handle, F.getHandle(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHCustomKeyStorage::LoadPublic(TStream *F, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomKeyStorage_LoadPublic(_Handle, (F != NULL) ? F->getHandle() : SB_NULL_HANDLE, Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElSSHCustomKeyStorage::LoadPublic(const std::string &Filename)
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomKeyStorage_LoadPublic_1(_Handle, Filename.data(), (int32_t)Filename.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElSSHCustomKeyStorage::SavePublic(TStream &F)
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomKeyStorage_SavePublic(_Handle, F.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHCustomKeyStorage::SavePublic(TStream *F)
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomKeyStorage_SavePublic(_Handle, (F != NULL) ? F->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElSSHCustomKeyStorage::SavePublic(const std::string &Filename)
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomKeyStorage_SavePublic_1(_Handle, Filename.data(), (int32_t)Filename.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSSHKEY
TElSSHKey* TElSSHCustomKeyStorage::get_Keys(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHCustomKeyStorage_get_Keys(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Keys)
		this->_Inst_Keys = new TElSSHKey(hOutResult, ohFalse);
	else
		this->_Inst_Keys->updateHandle(hOutResult);
	return this->_Inst_Keys;
}
#endif /* SB_USE_CLASS_TELSSHKEY */

SB_INLINE int32_t TElSSHCustomKeyStorage::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElSSHCustomKeyStorage_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElCustomCryptoProviderManager* TElSSHCustomKeyStorage::get_CryptoProviderManager()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElSSHCustomKeyStorage_get_CryptoProviderManager(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProviderManager)
		this->_Inst_CryptoProviderManager = new TElCustomCryptoProviderManager(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProviderManager->updateHandle(hOutResult);
	return this->_Inst_CryptoProviderManager;
}

SB_INLINE void TElSSHCustomKeyStorage::set_CryptoProviderManager(TElCustomCryptoProviderManager &Value)
{
	SBCheckError(TElSSHCustomKeyStorage_set_CryptoProviderManager(_Handle, Value.getHandle()));
}

SB_INLINE void TElSSHCustomKeyStorage::set_CryptoProviderManager(TElCustomCryptoProviderManager *Value)
{
	SBCheckError(TElSSHCustomKeyStorage_set_CryptoProviderManager(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

void TElSSHCustomKeyStorage::initInstances()
{
#ifdef SB_USE_CLASS_TELSSHKEY
	this->_Inst_Keys = NULL;
#endif /* SB_USE_CLASS_TELSSHKEY */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}

TElSSHCustomKeyStorage::TElSSHCustomKeyStorage(TElSSHCustomKeyStorageHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElSSHCustomKeyStorage::TElSSHCustomKeyStorage(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHCustomKeyStorage_Create(AOwner.getHandle(), &_Handle));
}

TElSSHCustomKeyStorage::TElSSHCustomKeyStorage(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElSSHCustomKeyStorage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElSSHCustomKeyStorage::~TElSSHCustomKeyStorage()
{
#ifdef SB_USE_CLASS_TELSSHKEY
	delete this->_Inst_Keys;
	this->_Inst_Keys = NULL;
#endif /* SB_USE_CLASS_TELSSHKEY */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
	delete this->_Inst_CryptoProviderManager;
	this->_Inst_CryptoProviderManager = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
}
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

#ifdef SB_USE_CLASS_TELSSHMEMORYKEYSTORAGE

#ifdef SB_USE_CLASS_TELSSHKEY
SB_INLINE void TElSSHMemoryKeyStorage::Add(TElSSHKey &Key)
{
	SBCheckError(TElSSHMemoryKeyStorage_Add(_Handle, Key.getHandle()));
}

SB_INLINE void TElSSHMemoryKeyStorage::Add(TElSSHKey *Key)
{
	SBCheckError(TElSSHMemoryKeyStorage_Add(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSSHKEY */

SB_INLINE void TElSSHMemoryKeyStorage::Remove(int32_t Index)
{
	SBCheckError(TElSSHMemoryKeyStorage_Remove(_Handle, Index));
}

SB_INLINE void TElSSHMemoryKeyStorage::Clear()
{
	SBCheckError(TElSSHMemoryKeyStorage_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElSSHMemoryKeyStorage::LoadPublic(TStream &F, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElSSHMemoryKeyStorage_LoadPublic(_Handle, F.getHandle(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHMemoryKeyStorage::LoadPublic(TStream *F, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElSSHMemoryKeyStorage_LoadPublic(_Handle, (F != NULL) ? F->getHandle() : SB_NULL_HANDLE, Count, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElSSHMemoryKeyStorage::LoadPublic(const std::string &Filename)
{
	int32_t OutResult;
	SBCheckError(TElSSHMemoryKeyStorage_LoadPublic_1(_Handle, Filename.data(), (int32_t)Filename.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElSSHMemoryKeyStorage::SavePublic(TStream &F)
{
	int32_t OutResult;
	SBCheckError(TElSSHMemoryKeyStorage_SavePublic(_Handle, F.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHMemoryKeyStorage::SavePublic(TStream *F)
{
	int32_t OutResult;
	SBCheckError(TElSSHMemoryKeyStorage_SavePublic(_Handle, (F != NULL) ? F->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElSSHMemoryKeyStorage::SavePublic(const std::string &Filename)
{
	int32_t OutResult;
	SBCheckError(TElSSHMemoryKeyStorage_SavePublic_1(_Handle, Filename.data(), (int32_t)Filename.length(), &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELSSHKEY
SB_INLINE int32_t TElSSHMemoryKeyStorage::IndexOf(TElSSHKey &Key)
{
	int32_t OutResult;
	SBCheckError(TElSSHMemoryKeyStorage_IndexOf(_Handle, Key.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSSHMemoryKeyStorage::IndexOf(TElSSHKey *Key)
{
	int32_t OutResult;
	SBCheckError(TElSSHMemoryKeyStorage_IndexOf(_Handle, (Key != NULL) ? Key->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSSHKEY */

TElSSHMemoryKeyStorage::TElSSHMemoryKeyStorage(TElSSHMemoryKeyStorageHandle handle, TElOwnHandle ownHandle) : TElSSHCustomKeyStorage(handle, ownHandle)
{
}

TElSSHMemoryKeyStorage::TElSSHMemoryKeyStorage(TComponent &AOwner) : TElSSHCustomKeyStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHMemoryKeyStorage_Create(AOwner.getHandle(), &_Handle));
}

TElSSHMemoryKeyStorage::TElSSHMemoryKeyStorage(TComponent *AOwner) : TElSSHCustomKeyStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSSHMemoryKeyStorage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSSHMEMORYKEYSTORAGE */

};	/* namespace SecureBlackbox */
