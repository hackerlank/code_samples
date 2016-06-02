#ifndef __INC_SBJKS
#define __INC_SBJKS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbx509.h"
#include "sbsha.h"
#include "sbrandom.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_E_JKS_FORMAT_ERROR 	1
#define SB_E_JKS_READ_ERROR 	2
#define SB_E_JKS_WRITE_ERROR 	3
#define SB_E_JKS_VERSION_ERROR 	4
#define SB_E_JKS_KEY_FORMAT_ERROR 	5
#define SB_E_JKS_UNKNOWN_CERT 	6
#define SB_E_JKS_CHECKSUM 	7
#define SB_E_JKS_SIGNATURE 	8
#define SB_E_JKS_NO_SPACE 	9

typedef TElClassHandle TElJKSHandle;

typedef TElJKSHandle ElJKSHandle;

#pragma pack(4)
typedef struct 
{
	void * Alias;
	double CreationDate;
	void * EncodedKey;
	void * Certificate_Chain;
} TJKSEntry;

typedef void (SB_CALLBACK *TElJKSPasswordEvent)(void * _ObjectData, const char * pcAlias, int32_t szAlias, char * pcPassword, int32_t * szPassword, int8_t * OutResult);

typedef void (SB_CALLBACK *TElJKSAliasNeededEvent)(void * _ObjectData, TElX509CertificateHandle Cert, char * pcAlias, int32_t * szAlias, int8_t * OutResult);

#ifdef SB_USE_CLASS_TELJKS
SB_IMPORT uint32_t SB_APIENTRY TElJKS_LoadFromStream(TElJKSHandle _Handle, TStreamHandle Stream, const char * pcJKS_Pass, int32_t szJKS_Pass, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_LoadFromBuffer(TElJKSHandle _Handle, void * Src_Ptr, int32_t BufferSize, int32_t * BufferPos, const char * pcJKS_Pass, int32_t szJKS_Pass, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_GetSaveBufferSize(TElJKSHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_SaveToStream(TElJKSHandle _Handle, TStreamHandle Stream, const char * pcJKS_Pass, int32_t szJKS_Pass, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_SaveToBuffer(TElJKSHandle _Handle, uint8_t pDstBuffer[], int32_t * szDstBuffer, int32_t BufferSize, int32_t * BufferPos, const char * pcJKS_Pass, int32_t szJKS_Pass, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_GetPrivateKey(TElJKSHandle _Handle, int32_t Index, const char * pcPass, int32_t szPass, uint8_t pKey[], int32_t * szKey, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_SetPrivateKey(TElJKSHandle _Handle, int32_t Index, const char * pcPass, int32_t szPass, const uint8_t pKey[], int32_t szKey, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_AddPrivateKey(TElJKSHandle _Handle, const char * pcPass, int32_t szPass, const uint8_t pKey[], int32_t szKey, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_GetKeyCertificate(TElJKSHandle _Handle, int32_t Index, int32_t Cert_Index, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_AddKeyCertificate(TElJKSHandle _Handle, int32_t Index, TElX509CertificateHandle Cert, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_DelKeyCertificate(TElJKSHandle _Handle, int32_t Index, int32_t Cert_Index);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_GetTrustedCertificate(TElJKSHandle _Handle, int32_t Index, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_AddTrustedCertificate(TElJKSHandle _Handle, TElX509CertificateHandle Cert, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_DelTrustedCertificate(TElJKSHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_GetAlias(TElJKSHandle _Handle, int32_t Index, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_SetAlias(TElJKSHandle _Handle, int32_t Index, const char * pcAlias, int32_t szAlias);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_get_Entries_Count(TElJKSHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_get_PrivateKeyCert_Count(TElJKSHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_get_IsPrivateKey(TElJKSHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_get_IgnoreBadStorageSignature(TElJKSHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_set_IgnoreBadStorageSignature(TElJKSHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElJKS_Create(TElJKSHandle * OutResult);
#endif /* SB_USE_CLASS_TELJKS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElJKS;
typedef TElJKS ElJKS;

#ifdef SB_USE_CLASS_TELJKS
class TElJKS: public TObject
{
	private:
		SB_DISABLE_COPY(TElJKS)
	public:
#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadFromStream(TStream &Stream, const std::string &JKS_Pass);

		int32_t LoadFromStream(TStream *Stream, const std::string &JKS_Pass);
#endif /* SB_USE_CLASS_TSTREAM */

		int32_t LoadFromBuffer(void * Src_Ptr, int32_t BufferSize, int32_t &BufferPos, const std::string &JKS_Pass);

		int32_t GetSaveBufferSize();

#ifdef SB_USE_CLASS_TSTREAM
		int32_t SaveToStream(TStream &Stream, const std::string &JKS_Pass);

		int32_t SaveToStream(TStream *Stream, const std::string &JKS_Pass);
#endif /* SB_USE_CLASS_TSTREAM */

		int32_t SaveToBuffer(std::vector<uint8_t> &DstBuffer, int32_t BufferSize, int32_t &BufferPos, const std::string &JKS_Pass);

		bool GetPrivateKey(int32_t Index, const std::string &Pass, std::vector<uint8_t> &Key);

		bool SetPrivateKey(int32_t Index, const std::string &Pass, const std::vector<uint8_t> &Key);

		int32_t AddPrivateKey(const std::string &Pass, const std::vector<uint8_t> &Key);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509CertificateHandle GetKeyCertificate(int32_t Index, int32_t Cert_Index);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		int32_t AddKeyCertificate(int32_t Index, TElX509Certificate &Cert);

		int32_t AddKeyCertificate(int32_t Index, TElX509Certificate *Cert);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		void DelKeyCertificate(int32_t Index, int32_t Cert_Index);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509CertificateHandle GetTrustedCertificate(int32_t Index);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		int32_t AddTrustedCertificate(TElX509Certificate &Cert);

		int32_t AddTrustedCertificate(TElX509Certificate *Cert);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		void DelTrustedCertificate(int32_t Index);

		void GetAlias(int32_t Index, std::string &OutResult);

		void SetAlias(int32_t Index, const std::string &Alias);

		virtual int32_t get_Entries_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Entries_Count, TElJKS, Entries_Count);

		virtual int32_t get_PrivateKeyCert_Count(int32_t Index);

		virtual bool get_IsPrivateKey(int32_t Index);

		virtual bool get_IgnoreBadStorageSignature();

		virtual void set_IgnoreBadStorageSignature(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreBadStorageSignature, set_IgnoreBadStorageSignature, TElJKS, IgnoreBadStorageSignature);

		TElJKS(TElJKSHandle handle, TElOwnHandle ownHandle);

		TElJKS();

};
#endif /* SB_USE_CLASS_TELJKS */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBJKS */

