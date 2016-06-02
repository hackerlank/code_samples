#ifndef __INC_SBOTPCLIENT
#define __INC_SBOTPCLIENT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbotpcommon.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElOTPClientHandle;

typedef TElOTPClientHandle ElOTPClientHandle;

typedef TElClassHandle TElHOTPClientHandle;

typedef TElHOTPClientHandle ElHOTPClientHandle;

typedef TElClassHandle TElTOTPClientHandle;

typedef TElTOTPClientHandle ElTOTPClientHandle;

#ifdef SB_USE_CLASS_TELOTPCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElOTPClient_get_KeySecret(TElOTPClientHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOTPClient_set_KeySecret(TElOTPClientHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOTPClient_get_PasswordLen(TElOTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOTPClient_set_PasswordLen(TElOTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOTPClient_Create(const uint8_t pKeySecret[], int32_t szKeySecret, int32_t PasswordLength, TElOTPClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELOTPCLIENT */

#ifdef SB_USE_CLASS_TELHOTPCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElHOTPClient_GetPassword(TElHOTPClientHandle _Handle, int32_t Counter, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHOTPClient_Create(const uint8_t pKeySecret[], int32_t szKeySecret, int32_t PasswordLength, TElHOTPClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELHOTPCLIENT */

#ifdef SB_USE_CLASS_TELTOTPCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElTOTPClient_GetPassword(TElTOTPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPClient_GetPassword_1(TElTOTPClientHandle _Handle, int64_t Time, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPClient_get_TimeInterval(TElTOTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPClient_set_TimeInterval(TElTOTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPClient_get_HashAlgorithm(TElTOTPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPClient_set_HashAlgorithm(TElTOTPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPClient_Create(const uint8_t pKeySecret[], int32_t szKeySecret, int32_t PasswordLength, TElTOTPClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELTOTPCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElOTPClient;
typedef TElOTPClient ElOTPClient;
class TElHOTPClient;
typedef TElHOTPClient ElHOTPClient;
class TElTOTPClient;
typedef TElTOTPClient ElTOTPClient;

#ifdef SB_USE_CLASS_TELOTPCLIENT
class TElOTPClient: public TElOTPClass
{
	private:
		SB_DISABLE_COPY(TElOTPClient)
	public:
		virtual void get_KeySecret(std::vector<uint8_t> &OutResult);

		virtual void set_KeySecret(const std::vector<uint8_t> &Value);

		virtual int32_t get_PasswordLen();

		virtual void set_PasswordLen(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PasswordLen, set_PasswordLen, TElOTPClient, PasswordLen);

		TElOTPClient(TElOTPClientHandle handle, TElOwnHandle ownHandle);

		TElOTPClient(const std::vector<uint8_t> &KeySecret, int32_t PasswordLength);

};
#endif /* SB_USE_CLASS_TELOTPCLIENT */

#ifdef SB_USE_CLASS_TELHOTPCLIENT
class TElHOTPClient: public TElOTPClient
{
	private:
		SB_DISABLE_COPY(TElHOTPClient)
	public:
		void GetPassword(int32_t Counter, std::string &OutResult);

		TElHOTPClient(TElHOTPClientHandle handle, TElOwnHandle ownHandle);

		TElHOTPClient(const std::vector<uint8_t> &KeySecret, int32_t PasswordLength);

};
#endif /* SB_USE_CLASS_TELHOTPCLIENT */

#ifdef SB_USE_CLASS_TELTOTPCLIENT
class TElTOTPClient: public TElOTPClient
{
	private:
		SB_DISABLE_COPY(TElTOTPClient)
	public:
		void GetPassword(std::string &OutResult);

		void GetPassword(int64_t Time, std::string &OutResult);

		virtual int32_t get_TimeInterval();

		virtual void set_TimeInterval(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TimeInterval, set_TimeInterval, TElTOTPClient, TimeInterval);

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElTOTPClient, HashAlgorithm);

		TElTOTPClient(TElTOTPClientHandle handle, TElOwnHandle ownHandle);

		TElTOTPClient(const std::vector<uint8_t> &KeySecret, int32_t PasswordLength);

};
#endif /* SB_USE_CLASS_TELTOTPCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBOTPCLIENT */

