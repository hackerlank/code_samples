#ifndef __INC_SBBCRYPT
#define __INC_SBBCRYPT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbencoding.h"
#include "sbblowfish.h"
#include "sbtypes.h"
#include "sbrandom.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SInvalidRoundsNumber 	"Invalid rounds number"
#define SB_SInvalidSaltSize 	"Invalid salt size"
#define SB_SInvalidPasswordLength 	"Invalid password length"
#define SB_SInvalidBase64Encoding 	"Invalid Base-64 encoding"
#define SB_SInvalidEncryptedPassword 	"Invalid encrypted password"

typedef TElClassHandle TElBCryptHandle;

#ifdef SB_USE_CLASS_TELBCRYPT
SB_IMPORT uint32_t SB_APIENTRY TElBCrypt_GenerateSalt(uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBCrypt_GenerateSalt_1(TElBCryptHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBCrypt_EncryptPassword(const char * pcPassword, int32_t szPassword, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBCrypt_EncryptPassword_1(TElBCryptHandle _Handle, const char * pcPassword, int32_t szPassword, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBCrypt_EncryptPassword_2(const char * pcPassword, int32_t szPassword, const uint8_t pSalt[], int32_t szSalt, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBCrypt_EncryptPassword_3(TElBCryptHandle _Handle, const char * pcPassword, int32_t szPassword, const uint8_t pSalt[], int32_t szSalt, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBCrypt_EncryptPassword_4(const char * pcPassword, int32_t szPassword, const uint8_t pSalt[], int32_t szSalt, int32_t Rounds, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBCrypt_EncryptPassword_5(TElBCryptHandle _Handle, const char * pcPassword, int32_t szPassword, const uint8_t pSalt[], int32_t szSalt, int32_t Rounds, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBCrypt_CheckPassword(const char * pcPassword, int32_t szPassword, const char * pcEncryptedPassword, int32_t szEncryptedPassword, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBCrypt_CheckPassword_1(TElBCryptHandle _Handle, const char * pcPassword, int32_t szPassword, const char * pcEncryptedPassword, int32_t szEncryptedPassword, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBCrypt_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELBCRYPT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElBCrypt;

#ifdef SB_USE_CLASS_TELBCRYPT
class TElBCrypt: public TObject
{
	private:
		SB_DISABLE_COPY(TElBCrypt)
	public:
		static void GenerateSalt(std::vector<uint8_t> &OutResult);

		void GenerateSalt_Inst(std::vector<uint8_t> &OutResult);

		static void EncryptPassword(const std::string &Password, std::string &OutResult);

		void EncryptPassword_Inst(const std::string &Password, std::string &OutResult);

		static void EncryptPassword(const std::string &Password, const std::vector<uint8_t> &Salt, std::string &OutResult);

		void EncryptPassword_Inst(const std::string &Password, const std::vector<uint8_t> &Salt, std::string &OutResult);

		static void EncryptPassword(const std::string &Password, const std::vector<uint8_t> &Salt, int32_t Rounds, std::string &OutResult);

		void EncryptPassword_Inst(const std::string &Password, const std::vector<uint8_t> &Salt, int32_t Rounds, std::string &OutResult);

		static bool CheckPassword(const std::string &Password, const std::string &EncryptedPassword);

		bool CheckPassword_Inst(const std::string &Password, const std::string &EncryptedPassword);

		TElBCrypt(TElBCryptHandle handle, TElOwnHandle ownHandle);

		TElBCrypt();

};
#endif /* SB_USE_CLASS_TELBCRYPT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBBCRYPT */

