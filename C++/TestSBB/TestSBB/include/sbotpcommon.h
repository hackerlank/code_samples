#ifndef __INC_SBOTPCOMMON
#define __INC_SBOTPCOMMON

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbstrutils.h"
#include "sbutils.h"
#include "sbhashfunction.h"
#include "sbconstants.h"
#include "sbencoding.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_OTP_ERROR_NOT_SUPPORTED_ALGORITHM 	"Algorithm is not supported"
#define SB_OTP_ERROR_KEY_EMPTY 	"Key secret is not set"
#define SB_OTP_ERROR_NO_PASSWORD_LENGTH 	"Password length is not set"
#define SB_OTP_ERROR_DATA_TOO_LONG 	"Hashed data is too long"
#define SB_OTP_ERROR_DATA_EMPTY 	"Hashed data is empty"
#define SB_OTP_ERROR_COUNTER_INCORRECT 	"Counter value is incorrect"
#define SB_OTP_NO_USER_STORAGE 	"User storage is not set"
#define SB_OTP_EMPTY_USER_STORAGE 	"User storage is empty"
#define SB_OTP_NO_FIND_USER 	"User is not found in storage"
#define SB_OTP_NOT_IMPLEMENTED 	"Not implemented"
#define SB_OTP_INVALID_TYPE_CAST 	"Invalid type cast"
#define SB_ALGORITHM_OTP_BASE 	30464
#define SB_ALGORITHM_OTP_HMAC_BASED 	30465
#define SB_ALGORITHM_OTP_TIME_BASED 	30466

typedef TElClassHandle TElOTPClassHandle;

typedef TElOTPClassHandle ElOTPClassHandle;

typedef TElClassHandle TElHOTPPasswordGeneratorHandle;

typedef TElHOTPPasswordGeneratorHandle ElHOTPPasswordGeneratorHandle;

typedef TElClassHandle TElTOTPPasswordGeneratorHandle;

typedef TElTOTPPasswordGeneratorHandle ElTOTPPasswordGeneratorHandle;

#ifdef SB_USE_CLASS_TELOTPCLASS
SB_IMPORT uint32_t SB_APIENTRY TElOTPClass_Create(TComponentHandle Owner, TElOTPClassHandle * OutResult);
#endif /* SB_USE_CLASS_TELOTPCLASS */

#ifdef SB_USE_CLASS_TELHOTPPASSWORDGENERATOR
SB_IMPORT uint32_t SB_APIENTRY TElHOTPPasswordGenerator_GeneratePassword(TElHOTPPasswordGeneratorHandle _Handle, const uint8_t pHashedData[], int32_t szHashedData, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHOTPPasswordGenerator_GeneratePassword_1(TElHOTPPasswordGeneratorHandle _Handle, int32_t Counter, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHOTPPasswordGenerator_get_KeySecret(TElHOTPPasswordGeneratorHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHOTPPasswordGenerator_set_KeySecret(TElHOTPPasswordGeneratorHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElHOTPPasswordGenerator_get_PasswordLen(TElHOTPPasswordGeneratorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHOTPPasswordGenerator_set_PasswordLen(TElHOTPPasswordGeneratorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHOTPPasswordGenerator_Create(const uint8_t pKeySecret[], int32_t szKeySecret, int32_t PasswordLength, TElHOTPPasswordGeneratorHandle * OutResult);
#endif /* SB_USE_CLASS_TELHOTPPASSWORDGENERATOR */

#ifdef SB_USE_CLASS_TELTOTPPASSWORDGENERATOR
SB_IMPORT uint32_t SB_APIENTRY TElTOTPPasswordGenerator_GeneratePassword(TElTOTPPasswordGeneratorHandle _Handle, int64_t Time, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPPasswordGenerator_get_HashAlgorithm(TElTOTPPasswordGeneratorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPPasswordGenerator_set_HashAlgorithm(TElTOTPPasswordGeneratorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPPasswordGenerator_get_TimeInterval(TElTOTPPasswordGeneratorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPPasswordGenerator_set_TimeInterval(TElTOTPPasswordGeneratorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPPasswordGenerator_Create(const uint8_t pKeySecret[], int32_t szKeySecret, int32_t PasswordLength, TElTOTPPasswordGeneratorHandle * OutResult);
#endif /* SB_USE_CLASS_TELTOTPPASSWORDGENERATOR */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElOTPClass;
typedef TElOTPClass ElOTPClass;
class TElHOTPPasswordGenerator;
typedef TElHOTPPasswordGenerator ElHOTPPasswordGenerator;
class TElTOTPPasswordGenerator;
typedef TElTOTPPasswordGenerator ElTOTPPasswordGenerator;

#ifdef SB_USE_CLASS_TELOTPCLASS
class TElOTPClass: public TComponent
{
	private:
		SB_DISABLE_COPY(TElOTPClass)
	public:
		TElOTPClass(TElOTPClassHandle handle, TElOwnHandle ownHandle);

		explicit TElOTPClass(TComponent &Owner);

		explicit TElOTPClass(TComponent *Owner);

};
#endif /* SB_USE_CLASS_TELOTPCLASS */

#ifdef SB_USE_CLASS_TELHOTPPASSWORDGENERATOR
class TElHOTPPasswordGenerator: public TObject
{
	private:
		SB_DISABLE_COPY(TElHOTPPasswordGenerator)
	public:
		virtual void GeneratePassword(const std::vector<uint8_t> &HashedData, std::string &OutResult);

		virtual void GeneratePassword(int32_t Counter, std::string &OutResult);

		virtual void get_KeySecret(std::vector<uint8_t> &OutResult);

		virtual void set_KeySecret(const std::vector<uint8_t> &Value);

		virtual int32_t get_PasswordLen();

		virtual void set_PasswordLen(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PasswordLen, set_PasswordLen, TElHOTPPasswordGenerator, PasswordLen);

		TElHOTPPasswordGenerator(TElHOTPPasswordGeneratorHandle handle, TElOwnHandle ownHandle);

		TElHOTPPasswordGenerator(const std::vector<uint8_t> &KeySecret, int32_t PasswordLength);

};
#endif /* SB_USE_CLASS_TELHOTPPASSWORDGENERATOR */

#ifdef SB_USE_CLASS_TELTOTPPASSWORDGENERATOR
class TElTOTPPasswordGenerator: public TElHOTPPasswordGenerator
{
	private:
		SB_DISABLE_COPY(TElTOTPPasswordGenerator)
	public:
		void GeneratePassword(int64_t Time, std::string &OutResult);

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElTOTPPasswordGenerator, HashAlgorithm);

		virtual int32_t get_TimeInterval();

		virtual void set_TimeInterval(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TimeInterval, set_TimeInterval, TElTOTPPasswordGenerator, TimeInterval);

		TElTOTPPasswordGenerator(TElTOTPPasswordGeneratorHandle handle, TElOwnHandle ownHandle);

		TElTOTPPasswordGenerator(const std::vector<uint8_t> &KeySecret, int32_t PasswordLength);

};
#endif /* SB_USE_CLASS_TELTOTPPASSWORDGENERATOR */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBOTPCOMMON */

