#ifndef __INC_SBCRLEX
#define __INC_SBCRLEX

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcrl.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbalgorithmidentifier.h"
#include "sbcustomcrypto.h"
#include "sbpublickeycrypto.h"
#include "sbpem.h"
#include "sbx509.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElCertificateRevocationListExHandle;

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLISTEX
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationListEx_SaveToBuffer(TElCertificateRevocationListExHandle _Handle, void * Buffer, int32_t * Size, TElX509CertificateHandle Certificate, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationListEx_SaveToBufferPEM(TElCertificateRevocationListExHandle _Handle, void * Buffer, int32_t * Size, TElX509CertificateHandle Certificate, const char * pcPassphrase, int32_t szPassphrase, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationListEx_SaveToBufferPEM_1(TElCertificateRevocationListExHandle _Handle, uint8_t pBuffer[], int32_t * szBuffer, TElX509CertificateHandle Certificate, const char * pcPassphrase, int32_t szPassphrase, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationListEx_SaveToStream(TElCertificateRevocationListExHandle _Handle, TStreamHandle Stream, TElX509CertificateHandle Certificate, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationListEx_SaveToStreamPEM(TElCertificateRevocationListExHandle _Handle, TStreamHandle Stream, TElX509CertificateHandle Certificate, const char * pcPassphrase, int32_t szPassphrase, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationListEx_get_PreferredHashAlgorithm(TElCertificateRevocationListExHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationListEx_set_PreferredHashAlgorithm(TElCertificateRevocationListExHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationListEx_Create(TComponentHandle Owner, TElCertificateRevocationListExHandle * OutResult);
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLISTEX */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElCertificateRevocationListEx;

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLISTEX
class TElCertificateRevocationListEx: public TElCertificateRevocationList
{
	private:
		SB_DISABLE_COPY(TElCertificateRevocationListEx)
	public:
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		int32_t SaveToBuffer(void * Buffer, int32_t &Size, TElX509Certificate &Certificate);

		int32_t SaveToBuffer(void * Buffer, int32_t &Size, TElX509Certificate *Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		int32_t SaveToBufferPEM(void * Buffer, int32_t &Size, TElX509Certificate &Certificate, const std::string &Passphrase);

		int32_t SaveToBufferPEM(void * Buffer, int32_t &Size, TElX509Certificate *Certificate, const std::string &Passphrase);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		int32_t SaveToBufferPEM(std::vector<uint8_t> &Buffer, TElX509Certificate &Certificate, const std::string &Passphrase);

		int32_t SaveToBufferPEM(std::vector<uint8_t> &Buffer, TElX509Certificate *Certificate, const std::string &Passphrase);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TSTREAM
		int32_t SaveToStream(TStream &Stream, TElX509Certificate &Certificate);

		int32_t SaveToStream(TStream *Stream, TElX509Certificate *Certificate);
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TSTREAM
		int32_t SaveToStreamPEM(TStream &Stream, TElX509Certificate &Certificate, const std::string &Passphrase);

		int32_t SaveToStreamPEM(TStream *Stream, TElX509Certificate *Certificate, const std::string &Passphrase);
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TSTREAM */

		virtual int32_t get_PreferredHashAlgorithm();

		virtual void set_PreferredHashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PreferredHashAlgorithm, set_PreferredHashAlgorithm, TElCertificateRevocationListEx, PreferredHashAlgorithm);

		TElCertificateRevocationListEx(TElCertificateRevocationListExHandle handle, TElOwnHandle ownHandle);

		explicit TElCertificateRevocationListEx(TComponent &Owner);

		explicit TElCertificateRevocationListEx(TComponent *Owner);

};
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLISTEX */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCRLEX */

