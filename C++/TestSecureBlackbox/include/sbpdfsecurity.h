#ifndef __INC_SBPDFSECURITY
#define __INC_SBPDFSECURITY

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbcryptoprov.h"
#include "sbpdfcore.h"
#include "sbpdf.h"
#include "sbhashfunction.h"
#include "sbpkcs7.h"
#include "sbpkcs7utils.h"
#include "sbcustomcertstorage.h"
#include "sbx509.h"
#include "sbcrl.h"
#include "sbcustomcrypto.h"
#include "sbpublickeycrypto.h"
#include "sbrsa.h"
#include "sbmessages.h"
#include "sbdc.h"
#include "sbdcdef.h"
#include "sbtspcommon.h"
#include "sbtspclient.h"
#include "sbconstants.h"
#include "sbasn1tree.h"
#include "sbrdn.h"
#include "sbpdfutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SPDFNoSigningCertificate 	"No signing certificate found"
#define SB_SPDFInvalidPKCS7Data 	"Invalid PKCS#7 data"
#define SB_SPDFTSPClientNotFound 	"TSP client component not found"

typedef TElClassHandle TElPDFPasswordSecurityHandlerHandle;

typedef TElPDFPasswordSecurityHandlerHandle ElPDFPasswordSecurityHandlerHandle;

typedef TElClassHandle TElPDFPublicKeySecurityHandlerHandle;

typedef TElPDFPublicKeySecurityHandlerHandle ElPDFPublicKeySecurityHandlerHandle;

typedef TElClassHandle TElPDFPublicKeyRecipientGroupHandle;

typedef TElPDFPublicKeyRecipientGroupHandle ElPDFPublicKeyRecipientGroupHandle;

typedef TElClassHandle TElPDFPublicKeyRevocationInfoHandle;

typedef uint8_t TSBPDFPublicKeySignatureTypeRaw;

typedef enum
{
	pstX509RSASHA1 = 0,
	pstPKCS7SHA1 = 1
} TSBPDFPublicKeySignatureType;

#ifdef SB_USE_CLASS_TELPDFPASSWORDSECURITYHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElPDFPasswordSecurityHandler_Reset(TElPDFPasswordSecurityHandlerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPasswordSecurityHandler_IsUserPasswordValid(TElPDFPasswordSecurityHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPasswordSecurityHandler_IsOwnerPasswordValid(TElPDFPasswordSecurityHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPasswordSecurityHandler_GetName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPasswordSecurityHandler_GetName_1(TElPDFPasswordSecurityHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPasswordSecurityHandler_GetDescription(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPasswordSecurityHandler_GetDescription_1(TElPDFPasswordSecurityHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPasswordSecurityHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPasswordSecurityHandler_get_UserPassword(TElPDFPasswordSecurityHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPasswordSecurityHandler_set_UserPassword(TElPDFPasswordSecurityHandlerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPasswordSecurityHandler_get_OwnerPassword(TElPDFPasswordSecurityHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPasswordSecurityHandler_set_OwnerPassword(TElPDFPasswordSecurityHandlerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPasswordSecurityHandler_get_Permissions(TElPDFPasswordSecurityHandlerHandle _Handle, TElPDFPermissionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPasswordSecurityHandler_get_RevisionNumber(TElPDFPasswordSecurityHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPasswordSecurityHandler_set_RevisionNumber(TElPDFPasswordSecurityHandlerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPasswordSecurityHandler_Create(TComponentHandle Owner, TElPDFSecurityHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFPASSWORDSECURITYHANDLER */

#ifdef SB_USE_CLASS_TELPDFPUBLICKEYSECURITYHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_Reset(TElPDFPublicKeySecurityHandlerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_AddRecipientGroup(TElPDFPublicKeySecurityHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_RemoveRecipientGroup(TElPDFPublicKeySecurityHandlerHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_ClearRecipientGroups(TElPDFPublicKeySecurityHandlerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_GetName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_GetName_1(TElPDFPublicKeySecurityHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_GetDescription(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_GetDescription_1(TElPDFPublicKeySecurityHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_GetSignerCertificate(TElPDFPublicKeySecurityHandlerHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_get_RecipientGroups(TElPDFPublicKeySecurityHandlerHandle _Handle, int32_t Index, TElPDFPublicKeyRecipientGroupHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_get_CertIDs(TElPDFPublicKeySecurityHandlerHandle _Handle, int32_t Index, TElPKCS7IssuerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_get_Timestamps(TElPDFPublicKeySecurityHandlerHandle _Handle, int32_t Index, TElClientTSPInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_get_RecipientGroupCount(TElPDFPublicKeySecurityHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_get_CertStorage(TElPDFPublicKeySecurityHandlerHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_set_CertStorage(TElPDFPublicKeySecurityHandlerHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_get_Certificates(TElPDFPublicKeySecurityHandlerHandle _Handle, TElMemoryCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_get_SignatureType(TElPDFPublicKeySecurityHandlerHandle _Handle, TSBPDFPublicKeySignatureTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_set_SignatureType(TElPDFPublicKeySecurityHandlerHandle _Handle, TSBPDFPublicKeySignatureTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_get_HashAlgorithm(TElPDFPublicKeySecurityHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_set_HashAlgorithm(TElPDFPublicKeySecurityHandlerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_get_Detached(TElPDFPublicKeySecurityHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_set_Detached(TElPDFPublicKeySecurityHandlerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_get_CertIDCount(TElPDFPublicKeySecurityHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_get_TimestampCount(TElPDFPublicKeySecurityHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_get_RevocationInfo(TElPDFPublicKeySecurityHandlerHandle _Handle, TElPDFPublicKeyRevocationInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_get_LastValidationResult(TElPDFPublicKeySecurityHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_get_SignatureContents(TElPDFPublicKeySecurityHandlerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_get_TSPClient(TElPDFPublicKeySecurityHandlerHandle _Handle, TElCustomTSPClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_set_TSPClient(TElPDFPublicKeySecurityHandlerHandle _Handle, TElCustomTSPClientHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_get_IgnoreTimestampFailure(TElPDFPublicKeySecurityHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_set_IgnoreTimestampFailure(TElPDFPublicKeySecurityHandlerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeySecurityHandler_Create(TComponentHandle Owner, TElPDFSecurityHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYSECURITYHANDLER */

#ifdef SB_USE_CLASS_TELPDFPUBLICKEYRECIPIENTGROUP
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRecipientGroup_AddRecipient(TElPDFPublicKeyRecipientGroupHandle _Handle, TElX509CertificateHandle Cert, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRecipientGroup_RemoveRecipient(TElPDFPublicKeyRecipientGroupHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRecipientGroup_ClearRecipients(TElPDFPublicKeyRecipientGroupHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRecipientGroup_get_Recipients(TElPDFPublicKeyRecipientGroupHandle _Handle, int32_t Index, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRecipientGroup_get_RecipientInfos(TElPDFPublicKeyRecipientGroupHandle _Handle, int32_t Index, TElPKCS7IssuerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRecipientGroup_get_RecipientCount(TElPDFPublicKeyRecipientGroupHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRecipientGroup_get_RecipientInfoCount(TElPDFPublicKeyRecipientGroupHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRecipientGroup_get_KeyEncryptionAlgorithm(TElPDFPublicKeyRecipientGroupHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRecipientGroup_set_KeyEncryptionAlgorithm(TElPDFPublicKeyRecipientGroupHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRecipientGroup_get_Permissions(TElPDFPublicKeyRecipientGroupHandle _Handle, TElPDFPermissionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRecipientGroup_Create(TElPDFPublicKeyRecipientGroupHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRecipientGroup_Create_1(TElPKCS7MessageHandle Msg, TElPDFPublicKeySecurityHandlerHandle Owner, TElPDFPublicKeyRecipientGroupHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYRECIPIENTGROUP */

#ifdef SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRevocationInfo_Assign(TElPDFPublicKeyRevocationInfoHandle _Handle, TElPDFPublicKeyRevocationInfoHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRevocationInfo_Assign_1(TElPDFPublicKeyRevocationInfoHandle _Handle, TElPDFPublicKeyRevocationInfoHandle Source, int8_t Clear);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRevocationInfo_AddCRL(TElPDFPublicKeyRevocationInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRevocationInfo_RemoveCRL(TElPDFPublicKeyRevocationInfoHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRevocationInfo_ClearCRLs(TElPDFPublicKeyRevocationInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRevocationInfo_ContainsCRL(TElPDFPublicKeyRevocationInfoHandle _Handle, TElCertificateRevocationListHandle Crl, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRevocationInfo_AddOCSPResponse(TElPDFPublicKeyRevocationInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRevocationInfo_RemoveOCSPRespose(TElPDFPublicKeyRevocationInfoHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRevocationInfo_ClearOCSPResponses(TElPDFPublicKeyRevocationInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRevocationInfo_ContainsOCSPResponse(TElPDFPublicKeyRevocationInfoHandle _Handle, const uint8_t pResponse[], int32_t szResponse, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRevocationInfo_Clear(TElPDFPublicKeyRevocationInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRevocationInfo_IsEmpty(TElPDFPublicKeyRevocationInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRevocationInfo_get_CRLs(TElPDFPublicKeyRevocationInfoHandle _Handle, int32_t Index, TElCertificateRevocationListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRevocationInfo_get_OCSPResponses(TElPDFPublicKeyRevocationInfoHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRevocationInfo_set_OCSPResponses(TElPDFPublicKeyRevocationInfoHandle _Handle, int32_t Index, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRevocationInfo_get_CRLCount(TElPDFPublicKeyRevocationInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRevocationInfo_get_OCSPResponseCount(TElPDFPublicKeyRevocationInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRevocationInfo_get_Certificates(TElPDFPublicKeyRevocationInfoHandle _Handle, TElMemoryCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRevocationInfo_get_OtherInfo(TElPDFPublicKeyRevocationInfoHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPublicKeyRevocationInfo_Create(TElPDFPublicKeyRevocationInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPDFPasswordSecurityHandler;
typedef TElPDFPasswordSecurityHandler ElPDFPasswordSecurityHandler;
class TElPDFPublicKeySecurityHandler;
typedef TElPDFPublicKeySecurityHandler ElPDFPublicKeySecurityHandler;
class TElPDFPublicKeyRecipientGroup;
typedef TElPDFPublicKeyRecipientGroup ElPDFPublicKeyRecipientGroup;
class TElPDFPublicKeyRevocationInfo;

#ifdef SB_USE_CLASS_TELPDFPASSWORDSECURITYHANDLER
class TElPDFPasswordSecurityHandler: public TElPDFSecurityHandler
{
	private:
		SB_DISABLE_COPY(TElPDFPasswordSecurityHandler)
#ifdef SB_USE_CLASS_TELPDFPERMISSIONS
		TElPDFPermissions* _Inst_Permissions;
#endif /* SB_USE_CLASS_TELPDFPERMISSIONS */

		void initInstances();

	public:
		virtual void Reset();

		bool IsUserPasswordValid();

		bool IsOwnerPasswordValid();

		static void GetName(std::string &OutResult);

		virtual void GetName_Inst(std::string &OutResult);

		static void GetDescription(std::string &OutResult);

		virtual void GetDescription_Inst(std::string &OutResult);

		static TClassHandle ClassType();

		virtual void get_UserPassword(std::string &OutResult);

		virtual void set_UserPassword(const std::string &Value);

		virtual void get_OwnerPassword(std::string &OutResult);

		virtual void set_OwnerPassword(const std::string &Value);

#ifdef SB_USE_CLASS_TELPDFPERMISSIONS
		virtual TElPDFPermissions* get_Permissions();

		SB_DECLARE_PROPERTY_GET(TElPDFPermissions*, get_Permissions, TElPDFPasswordSecurityHandler, Permissions);
#endif /* SB_USE_CLASS_TELPDFPERMISSIONS */

		virtual int32_t get_RevisionNumber();

		virtual void set_RevisionNumber(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_RevisionNumber, set_RevisionNumber, TElPDFPasswordSecurityHandler, RevisionNumber);

		TElPDFPasswordSecurityHandler(TElPDFPasswordSecurityHandlerHandle handle, TElOwnHandle ownHandle);

		explicit TElPDFPasswordSecurityHandler(TComponent &Owner);

		explicit TElPDFPasswordSecurityHandler(TComponent *Owner);

		virtual ~TElPDFPasswordSecurityHandler();

};
#endif /* SB_USE_CLASS_TELPDFPASSWORDSECURITYHANDLER */

#ifdef SB_USE_CLASS_TELPDFPUBLICKEYSECURITYHANDLER
class TElPDFPublicKeySecurityHandler: public TElPDFSecurityHandler
{
	private:
		SB_DISABLE_COPY(TElPDFPublicKeySecurityHandler)
#ifdef SB_USE_CLASS_TELPDFPUBLICKEYRECIPIENTGROUP
		TElPDFPublicKeyRecipientGroup* _Inst_RecipientGroups;
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYRECIPIENTGROUP */
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
		TElPKCS7Issuer* _Inst_CertIDs;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		TElClientTSPInfo* _Inst_Timestamps;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
		TElMemoryCertStorage* _Inst_Certificates;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO
		TElPDFPublicKeyRevocationInfo* _Inst_RevocationInfo;
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO */
#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		TElCustomTSPClient* _Inst_TSPClient;
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

		void initInstances();

	public:
		virtual void Reset();

		int32_t AddRecipientGroup();

		void RemoveRecipientGroup(int32_t Index);

		void ClearRecipientGroups();

		static void GetName(std::string &OutResult);

		virtual void GetName_Inst(std::string &OutResult);

		static void GetDescription(std::string &OutResult);

		virtual void GetDescription_Inst(std::string &OutResult);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509CertificateHandle GetSignerCertificate();
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELPDFPUBLICKEYRECIPIENTGROUP
		virtual TElPDFPublicKeyRecipientGroup* get_RecipientGroups(int32_t Index);
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYRECIPIENTGROUP */

#ifdef SB_USE_CLASS_TELPKCS7ISSUER
		virtual TElPKCS7Issuer* get_CertIDs(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		virtual TElClientTSPInfo* get_Timestamps(int32_t Index);
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

		virtual int32_t get_RecipientGroupCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_RecipientGroupCount, TElPDFPublicKeySecurityHandler, RecipientGroupCount);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElPDFPublicKeySecurityHandler, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
		virtual TElMemoryCertStorage* get_Certificates();

		SB_DECLARE_PROPERTY_GET(TElMemoryCertStorage*, get_Certificates, TElPDFPublicKeySecurityHandler, Certificates);
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

		virtual TSBPDFPublicKeySignatureType get_SignatureType();

		virtual void set_SignatureType(TSBPDFPublicKeySignatureType Value);

		SB_DECLARE_PROPERTY(TSBPDFPublicKeySignatureType, get_SignatureType, set_SignatureType, TElPDFPublicKeySecurityHandler, SignatureType);

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElPDFPublicKeySecurityHandler, HashAlgorithm);

		virtual bool get_Detached();

		virtual void set_Detached(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Detached, set_Detached, TElPDFPublicKeySecurityHandler, Detached);

		virtual int32_t get_CertIDCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CertIDCount, TElPDFPublicKeySecurityHandler, CertIDCount);

		virtual int32_t get_TimestampCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_TimestampCount, TElPDFPublicKeySecurityHandler, TimestampCount);

#ifdef SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO
		virtual TElPDFPublicKeyRevocationInfo* get_RevocationInfo();

		SB_DECLARE_PROPERTY_GET(TElPDFPublicKeyRevocationInfo*, get_RevocationInfo, TElPDFPublicKeySecurityHandler, RevocationInfo);
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO */

		virtual int32_t get_LastValidationResult();

		SB_DECLARE_PROPERTY_GET(int32_t, get_LastValidationResult, TElPDFPublicKeySecurityHandler, LastValidationResult);

		virtual void get_SignatureContents(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		virtual TElCustomTSPClient* get_TSPClient();

		virtual void set_TSPClient(TElCustomTSPClient &Value);

		virtual void set_TSPClient(TElCustomTSPClient *Value);

		SB_DECLARE_PROPERTY(TElCustomTSPClient*, get_TSPClient, set_TSPClient, TElPDFPublicKeySecurityHandler, TSPClient);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

		virtual bool get_IgnoreTimestampFailure();

		virtual void set_IgnoreTimestampFailure(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreTimestampFailure, set_IgnoreTimestampFailure, TElPDFPublicKeySecurityHandler, IgnoreTimestampFailure);

		TElPDFPublicKeySecurityHandler(TElPDFPublicKeySecurityHandlerHandle handle, TElOwnHandle ownHandle);

		explicit TElPDFPublicKeySecurityHandler(TComponent &Owner);

		explicit TElPDFPublicKeySecurityHandler(TComponent *Owner);

		virtual ~TElPDFPublicKeySecurityHandler();

};
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYSECURITYHANDLER */

#ifdef SB_USE_CLASS_TELPDFPUBLICKEYRECIPIENTGROUP
class TElPDFPublicKeyRecipientGroup: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFPublicKeyRecipientGroup)
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_Recipients;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
		TElPKCS7Issuer* _Inst_RecipientInfos;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELPDFPERMISSIONS
		TElPDFPermissions* _Inst_Permissions;
#endif /* SB_USE_CLASS_TELPDFPERMISSIONS */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		int32_t AddRecipient(TElX509Certificate &Cert);

		int32_t AddRecipient(TElX509Certificate *Cert);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		void RemoveRecipient(int32_t Index);

		void ClearRecipients();

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_Recipients(int32_t Index);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELPKCS7ISSUER
		virtual TElPKCS7Issuer* get_RecipientInfos(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

		virtual int32_t get_RecipientCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_RecipientCount, TElPDFPublicKeyRecipientGroup, RecipientCount);

		virtual int32_t get_RecipientInfoCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_RecipientInfoCount, TElPDFPublicKeyRecipientGroup, RecipientInfoCount);

		virtual int32_t get_KeyEncryptionAlgorithm();

		virtual void set_KeyEncryptionAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_KeyEncryptionAlgorithm, set_KeyEncryptionAlgorithm, TElPDFPublicKeyRecipientGroup, KeyEncryptionAlgorithm);

#ifdef SB_USE_CLASS_TELPDFPERMISSIONS
		virtual TElPDFPermissions* get_Permissions();

		SB_DECLARE_PROPERTY_GET(TElPDFPermissions*, get_Permissions, TElPDFPublicKeyRecipientGroup, Permissions);
#endif /* SB_USE_CLASS_TELPDFPERMISSIONS */

		TElPDFPublicKeyRecipientGroup(TElPDFPublicKeyRecipientGroupHandle handle, TElOwnHandle ownHandle);

		TElPDFPublicKeyRecipientGroup();

#ifdef SB_USE_CLASSES_TELPDFPUBLICKEYSECURITYHANDLER_AND_TELPKCS7MESSAGE
		TElPDFPublicKeyRecipientGroup(TElPKCS7Message &Msg, TElPDFPublicKeySecurityHandler &Owner);

		TElPDFPublicKeyRecipientGroup(TElPKCS7Message *Msg, TElPDFPublicKeySecurityHandler *Owner);
#endif /* SB_USE_CLASSES_TELPDFPUBLICKEYSECURITYHANDLER_AND_TELPKCS7MESSAGE */

		virtual ~TElPDFPublicKeyRecipientGroup();

};
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYRECIPIENTGROUP */

#ifdef SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO
class TElPDFPublicKeyRevocationInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFPublicKeyRevocationInfo)
#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		TElCertificateRevocationList* _Inst_CRLs;
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
		TElMemoryCertStorage* _Inst_Certificates;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_OtherInfo;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		void initInstances();

	public:
		void Assign(TElPDFPublicKeyRevocationInfo &Source);

		void Assign(TElPDFPublicKeyRevocationInfo *Source);

		void Assign(TElPDFPublicKeyRevocationInfo &Source, bool Clear);

		void Assign(TElPDFPublicKeyRevocationInfo *Source, bool Clear);

		int32_t AddCRL();

		void RemoveCRL(int32_t Index);

		void ClearCRLs();

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		bool ContainsCRL(TElCertificateRevocationList &Crl);

		bool ContainsCRL(TElCertificateRevocationList *Crl);
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

		int32_t AddOCSPResponse();

		void RemoveOCSPRespose(int32_t Index);

		void ClearOCSPResponses();

		bool ContainsOCSPResponse(const std::vector<uint8_t> &Response);

		void Clear();

		bool IsEmpty();

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		virtual TElCertificateRevocationList* get_CRLs(int32_t Index);
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

		virtual void get_OCSPResponses(int32_t Index, std::vector<uint8_t> &OutResult);

		virtual void set_OCSPResponses(int32_t Index, const std::vector<uint8_t> &Value);

		virtual int32_t get_CRLCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CRLCount, TElPDFPublicKeyRevocationInfo, CRLCount);

		virtual int32_t get_OCSPResponseCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_OCSPResponseCount, TElPDFPublicKeyRevocationInfo, OCSPResponseCount);

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
		virtual TElMemoryCertStorage* get_Certificates();

		SB_DECLARE_PROPERTY_GET(TElMemoryCertStorage*, get_Certificates, TElPDFPublicKeyRevocationInfo, Certificates);
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_OtherInfo();

		SB_DECLARE_PROPERTY_GET(TElRelativeDistinguishedName*, get_OtherInfo, TElPDFPublicKeyRevocationInfo, OtherInfo);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		TElPDFPublicKeyRevocationInfo(TElPDFPublicKeyRevocationInfoHandle handle, TElOwnHandle ownHandle);

		TElPDFPublicKeyRevocationInfo();

		virtual ~TElPDFPublicKeyRevocationInfo();

};
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPDFSECURITY */

