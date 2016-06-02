#ifndef __INC_SBPEM
#define __INC_SBPEM

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbencoding.h"
#include "sbsymmetriccrypto.h"
#include "sbhashfunction.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_PEM_DECODE_RESULT_OK 	0
#define SB_PEM_DECODE_RESULT_INVALID_FORMAT 	7425
#define SB_PEM_DECODE_RESULT_INVALID_PASSPHRASE 	7426
#define SB_PEM_DECODE_RESULT_NOT_ENOUGH_SPACE 	7427
#define SB_PEM_DECODE_RESULT_UNKNOWN_CIPHER 	7428

typedef TElClassHandle TElPEMProcessorHandle;

#ifdef SB_USE_CLASS_TELPEMPROCESSOR
SB_IMPORT uint32_t SB_APIENTRY TElPEMProcessor_PEMEncode(TElPEMProcessorHandle _Handle, const uint8_t pInBuffer[], int32_t szInBuffer, uint8_t pOutBuffer[], int32_t * szOutBuffer, int8_t Encrypt, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPEMProcessor_PEMEncode_1(TElPEMProcessorHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int8_t Encrypt, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPEMProcessor_PEMDecode(TElPEMProcessorHandle _Handle, const uint8_t pInBuffer[], int32_t szInBuffer, uint8_t pOutBuffer[], int32_t * szOutBuffer, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPEMProcessor_PEMDecode_1(TElPEMProcessorHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPEMProcessor_get_Header(TElPEMProcessorHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPEMProcessor_set_Header(TElPEMProcessorHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPEMProcessor_get_Passphrase(TElPEMProcessorHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPEMProcessor_set_Passphrase(TElPEMProcessorHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPEMProcessor_get_EncryptionAlgorithm(TElPEMProcessorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPEMProcessor_set_EncryptionAlgorithm(TElPEMProcessorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPEMProcessor_get_EncryptionMode(TElPEMProcessorHandle _Handle, TSBSymmetricCryptoModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPEMProcessor_set_EncryptionMode(TElPEMProcessorHandle _Handle, TSBSymmetricCryptoModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPEMProcessor_Create(TComponentHandle AOwner, TElPEMProcessorHandle * OutResult);
#endif /* SB_USE_CLASS_TELPEMPROCESSOR */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPEMProcessor;

#ifdef SB_USE_CLASS_TELPEMPROCESSOR
class TElPEMProcessor: public TComponent
{
	private:
		SB_DISABLE_COPY(TElPEMProcessor)
	public:
		bool PEMEncode(const std::vector<uint8_t> &InBuffer, std::vector<uint8_t> &OutBuffer, bool Encrypt);

		bool PEMEncode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, bool Encrypt);

		int32_t PEMDecode(const std::vector<uint8_t> &InBuffer, std::vector<uint8_t> &OutBuffer);

		int32_t PEMDecode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

		virtual void get_Header(std::string &OutResult);

		virtual void set_Header(const std::string &Value);

		virtual void get_Passphrase(std::string &OutResult);

		virtual void set_Passphrase(const std::string &Value);

		virtual int32_t get_EncryptionAlgorithm();

		virtual void set_EncryptionAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_EncryptionAlgorithm, set_EncryptionAlgorithm, TElPEMProcessor, EncryptionAlgorithm);

		virtual TSBSymmetricCryptoMode get_EncryptionMode();

		virtual void set_EncryptionMode(TSBSymmetricCryptoMode Value);

		SB_DECLARE_PROPERTY(TSBSymmetricCryptoMode, get_EncryptionMode, set_EncryptionMode, TElPEMProcessor, EncryptionMode);

		TElPEMProcessor(TElPEMProcessorHandle handle, TElOwnHandle ownHandle);

		explicit TElPEMProcessor(TComponent &AOwner);

		explicit TElPEMProcessor(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELPEMPROCESSOR */

#ifdef SB_USE_GLOBAL_PROCS_PEM

bool Encode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, const std::string &Header, bool Encrypt, const std::string &PassPhrase);

bool EncodeEx(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, const std::string &Header, int32_t EncryptionAlgorithm, const std::string &PassPhrase);

bool EncodeEx(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, const std::string &Header, int32_t EncryptionAlgorithm, TSBSymmetricCryptoMode EncryptionMode, const std::string &PassPhrase);

int32_t Decode(void * InBuffer, int32_t InSize, void * OutBuffer, const std::string &PassPhrase, int32_t &OutSize, std::string &Header);

bool IsBase64UnicodeSequence(void * Buffer, int32_t Size);

bool IsBase64Sequence(void * Buffer, int32_t Size);

bool IsPEMSequence(void * Buffer, int32_t Size);

void RaisePEMError(int32_t ErrorCode);

#endif /* SB_USE_GLOBAL_PROCS_PEM */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_PEM
SB_IMPORT uint32_t SB_APIENTRY SBPEM_Encode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, const char * pcHeader, int32_t szHeader, int8_t Encrypt, const char * pcPassPhrase, int32_t szPassPhrase, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPEM_EncodeEx(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, const char * pcHeader, int32_t szHeader, int32_t EncryptionAlgorithm, const char * pcPassPhrase, int32_t szPassPhrase, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPEM_EncodeEx_1(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, const char * pcHeader, int32_t szHeader, int32_t EncryptionAlgorithm, TSBSymmetricCryptoModeRaw EncryptionMode, const char * pcPassPhrase, int32_t szPassPhrase, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPEM_Decode(void * InBuffer, int32_t InSize, void * OutBuffer, const char * pcPassPhrase, int32_t szPassPhrase, int32_t * OutSize, char * pcHeader, int32_t * szHeader, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPEM_IsBase64UnicodeSequence(void * Buffer, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPEM_IsBase64Sequence(void * Buffer, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPEM_IsPEMSequence(void * Buffer, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPEM_RaisePEMError(int32_t ErrorCode);
#endif /* SB_USE_GLOBAL_PROCS_PEM */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPEM */

