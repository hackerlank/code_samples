#ifndef __INC_SBCRLSTORAGE
#define __INC_SBCRLSTORAGE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbx509.h"
#include "sbpem.h"
#include "sbx509ext.h"
#include "sbrdn.h"
#include "sbsharedresource.h"
#include "sbcustomcrypto.h"
#include "sbpublickeycrypto.h"
#include "sbalgorithmidentifier.h"
#include "sbcrl.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElCustomCRLStorageHandle;

typedef TElCustomCRLStorageHandle ElCustomCRLStorageHandle;

typedef TElClassHandle TElCRLLookupHandle;

typedef TElCRLLookupHandle ElCRLLookupHandle;

typedef TElClassHandle TElMemoryCRLStorageHandle;

typedef TElMemoryCRLStorageHandle ElMemoryCRLStorageHandle;

typedef TElClassHandle TElCRLCacheStorageHandle;

typedef TElClassHandle TElCustomCRLRetrieverHandle;

typedef TElCustomCRLRetrieverHandle ElCustomCRLRetrieverHandle;

typedef TElClassHandle TElCustomCRLRetrieverFactoryHandle;

typedef TElClassHandle TElCRLManagerHandle;

typedef TElCRLManagerHandle ElCRLManagerHandle;

typedef uint8_t TSBCRLLookupCriterionRaw;

typedef enum
{
	clcIssuer = 0,
	clcDistributionPoint = 1,
	clcNumber = 2,
	clcReason = 3,
	clcAuthorityKeyIdentifier = 4,
	clcBaseCRLNumber = 5
} TSBCRLLookupCriterion;

typedef uint32_t TSBCRLLookupCriteriaRaw;

typedef enum 
{
	f_clcIssuer = 1,
	f_clcDistributionPoint = 2,
	f_clcNumber = 4,
	f_clcReason = 8,
	f_clcAuthorityKeyIdentifier = 16,
	f_clcBaseCRLNumber = 32
} TSBCRLLookupCriteria;

typedef uint8_t TSBCRLLookupOptionRaw;

typedef enum
{
	cloExactMatch = 0,
	cloMatchAll = 1
} TSBCRLLookupOption;

typedef uint32_t TSBCRLLookupOptionsRaw;

typedef enum 
{
	f_cloExactMatch = 1,
	f_cloMatchAll = 2
} TSBCRLLookupOptions;

#ifdef SB_USE_CLASS_TELCUSTOMCRLSTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLStorage_BeginRead(TElCustomCRLStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLStorage_EndRead(TElCustomCRLStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLStorage_BeginWrite(TElCustomCRLStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLStorage_EndWrite(TElCustomCRLStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLStorage_Add(TElCustomCRLStorageHandle _Handle, TElCertificateRevocationListHandle CRL, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLStorage_FindMatchingCRLs(TElCustomCRLStorageHandle _Handle, TElX509CertificateHandle Certificate, TElDistributionPointHandle DistributionPoint, TListHandle List);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLStorage_Remove(TElCustomCRLStorageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLStorage_Clear(TElCustomCRLStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLStorage_FindFirst(TElCustomCRLStorageHandle _Handle, TElCRLLookupHandle Lookup, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLStorage_FindNext(TElCustomCRLStorageHandle _Handle, TElCRLLookupHandle Lookup, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLStorage_ExportTo(TElCustomCRLStorageHandle _Handle, TElCustomCRLStorageHandle Storage);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLStorage_IndexOf(TElCustomCRLStorageHandle _Handle, TElCertificateRevocationListHandle Crl, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLStorage_get_CRLs(TElCustomCRLStorageHandle _Handle, int32_t Index, TElCertificateRevocationListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLStorage_get_Count(TElCustomCRLStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLStorage_Create(TComponentHandle AOwner, TElCustomCRLStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMCRLSTORAGE */

#ifdef SB_USE_CLASS_TELCRLLOOKUP
SB_IMPORT uint32_t SB_APIENTRY TElCRLLookup_get_IssuerRDN(TElCRLLookupHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLLookup_get_DistributionPoint(TElCRLLookupHandle _Handle, TElGeneralNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLLookup_get_Number(TElCRLLookupHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLLookup_set_Number(TElCRLLookupHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCRLLookup_get_Reasons(TElCRLLookupHandle _Handle, TSBCRLReasonFlagsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLLookup_set_Reasons(TElCRLLookupHandle _Handle, TSBCRLReasonFlagsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCRLLookup_get_AuthorityKeyIdentifier(TElCRLLookupHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLLookup_set_AuthorityKeyIdentifier(TElCRLLookupHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCRLLookup_get_BaseCRLNumber(TElCRLLookupHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLLookup_set_BaseCRLNumber(TElCRLLookupHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCRLLookup_get_Criteria(TElCRLLookupHandle _Handle, TSBCRLLookupCriteriaRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLLookup_set_Criteria(TElCRLLookupHandle _Handle, TSBCRLLookupCriteriaRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCRLLookup_get_Options(TElCRLLookupHandle _Handle, TSBCRLLookupOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLLookup_set_Options(TElCRLLookupHandle _Handle, TSBCRLLookupOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCRLLookup_Create(TComponentHandle AOwner, TElCRLLookupHandle * OutResult);
#endif /* SB_USE_CLASS_TELCRLLOOKUP */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElMemoryCRLStorage_BeginRead(TElMemoryCRLStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryCRLStorage_EndRead(TElMemoryCRLStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryCRLStorage_BeginWrite(TElMemoryCRLStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryCRLStorage_EndWrite(TElMemoryCRLStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryCRLStorage_Add(TElMemoryCRLStorageHandle _Handle, TElCertificateRevocationListHandle CRL, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryCRLStorage_Remove(TElMemoryCRLStorageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryCRLStorage_Clear(TElMemoryCRLStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryCRLStorage_IndexOf(TElMemoryCRLStorageHandle _Handle, TElCertificateRevocationListHandle Crl, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryCRLStorage_Create(TComponentHandle AOwner, TElMemoryCRLStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

#ifdef SB_USE_CLASS_TELCRLCACHESTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElCRLCacheStorage_Add(TElCRLCacheStorageHandle _Handle, TElCertificateRevocationListHandle CRL, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLCacheStorage_get_Enabled(TElCRLCacheStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLCacheStorage_set_Enabled(TElCRLCacheStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCRLCacheStorage_Create(TComponentHandle AOwner, TElMemoryCRLStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELCRLCACHESTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRLRETRIEVER
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLRetriever_Supports(TElCustomCRLRetrieverHandle _Handle, TSBGeneralNameRaw NameType, const char * pcLocation, int32_t szLocation, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLRetriever_GetCRL(TElCustomCRLRetrieverHandle _Handle, TElX509CertificateHandle ACertificate, TElX509CertificateHandle CACertificate, TSBGeneralNameRaw NameType, const char * pcLocation, int32_t szLocation, TElCertificateRevocationListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLRetriever_Create(TComponentHandle AOwner, TComponentHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMCRLRETRIEVER */

#ifdef SB_USE_CLASS_TELCUSTOMCRLRETRIEVERFACTORY
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLRetrieverFactory_Supports(TElCustomCRLRetrieverFactoryHandle _Handle, TSBGeneralNameRaw NameType, const char * pcLocation, int32_t szLocation, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLRetrieverFactory_GetRetrieverInstance(TElCustomCRLRetrieverFactoryHandle _Handle, TObjectHandle Validator, TElCustomCRLRetrieverHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCRLRetrieverFactory_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMCRLRETRIEVERFACTORY */

#ifdef SB_USE_CLASS_TELCRLMANAGER
SB_IMPORT uint32_t SB_APIENTRY TElCRLManager_PurgeExpiredCRLs(TElCRLManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCRLManager_RegisterCRLRetrieverFactory(TElCRLManagerHandle _Handle, TElCustomCRLRetrieverFactoryHandle Factory);
SB_IMPORT uint32_t SB_APIENTRY TElCRLManager_UnregisterCRLRetrieverFactory(TElCRLManagerHandle _Handle, TElCustomCRLRetrieverFactoryHandle Factory);
SB_IMPORT uint32_t SB_APIENTRY TElCRLManager_FindCRLRetriever(TElCRLManagerHandle _Handle, TSBGeneralNameRaw NameType, const char * pcLocation, int32_t szLocation, TObjectHandle Validator, TElCustomCRLRetrieverHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLManager_get_CRLCache(TElCRLManagerHandle _Handle, TElCRLCacheStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLManager_get_UseCache(TElCRLManagerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLManager_set_UseCache(TElCRLManagerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCRLManager_Create(TElCRLManagerHandle * OutResult);
#endif /* SB_USE_CLASS_TELCRLMANAGER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElCustomCRLStorage;
typedef TElCustomCRLStorage ElCustomCRLStorage;
class TElCRLLookup;
typedef TElCRLLookup ElCRLLookup;
class TElMemoryCRLStorage;
typedef TElMemoryCRLStorage ElMemoryCRLStorage;
class TElCRLCacheStorage;
class TElCustomCRLRetriever;
typedef TElCustomCRLRetriever ElCustomCRLRetriever;
class TElCustomCRLRetrieverFactory;
class TElCRLManager;
typedef TElCRLManager ElCRLManager;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBCRLLookupCriteria)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBCRLLookupOptions)

#ifdef SB_USE_CLASS_TELCUSTOMCRLSTORAGE
class TElCustomCRLStorage: public TComponent
{
	private:
		SB_DISABLE_COPY(TElCustomCRLStorage)
#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		TElCertificateRevocationList* _Inst_CRLs;
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

		void initInstances();

	public:
		virtual void BeginRead();

		virtual void EndRead();

		virtual void BeginWrite();

		virtual void EndWrite();

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		virtual int32_t Add(TElCertificateRevocationList &CRL);

		virtual int32_t Add(TElCertificateRevocationList *CRL);
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef SB_USE_CLASSES_TELDISTRIBUTIONPOINT_AND_TELX509CERTIFICATE_AND_TLIST
		void FindMatchingCRLs(TElX509Certificate &Certificate, TElDistributionPoint &DistributionPoint, TList &List);

		void FindMatchingCRLs(TElX509Certificate *Certificate, TElDistributionPoint *DistributionPoint, TList *List);
#endif /* SB_USE_CLASSES_TELDISTRIBUTIONPOINT_AND_TELX509CERTIFICATE_AND_TLIST */

		virtual void Remove(int32_t Index);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELCRLLOOKUP
		int32_t FindFirst(TElCRLLookup &Lookup);

		int32_t FindFirst(TElCRLLookup *Lookup);
#endif /* SB_USE_CLASS_TELCRLLOOKUP */

#ifdef SB_USE_CLASS_TELCRLLOOKUP
		int32_t FindNext(TElCRLLookup &Lookup);

		int32_t FindNext(TElCRLLookup *Lookup);
#endif /* SB_USE_CLASS_TELCRLLOOKUP */

		void ExportTo(TElCustomCRLStorage &Storage);

		void ExportTo(TElCustomCRLStorage *Storage);

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		virtual int32_t IndexOf(TElCertificateRevocationList &Crl);

		virtual int32_t IndexOf(TElCertificateRevocationList *Crl);
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		virtual TElCertificateRevocationList* get_CRLs(int32_t Index);
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElCustomCRLStorage, Count);

		TElCustomCRLStorage(TElCustomCRLStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElCustomCRLStorage(TComponent &AOwner);

		explicit TElCustomCRLStorage(TComponent *AOwner);

		virtual ~TElCustomCRLStorage();

};
#endif /* SB_USE_CLASS_TELCUSTOMCRLSTORAGE */

#ifdef SB_USE_CLASS_TELCRLLOOKUP
class TElCRLLookup: public TComponent
{
	private:
		SB_DISABLE_COPY(TElCRLLookup)
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_IssuerRDN;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELGENERALNAME
		TElGeneralName* _Inst_DistributionPoint;
#endif /* SB_USE_CLASS_TELGENERALNAME */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_IssuerRDN();

		SB_DECLARE_PROPERTY_GET(TElRelativeDistinguishedName*, get_IssuerRDN, TElCRLLookup, IssuerRDN);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELGENERALNAME
		virtual TElGeneralName* get_DistributionPoint();

		SB_DECLARE_PROPERTY_GET(TElGeneralName*, get_DistributionPoint, TElCRLLookup, DistributionPoint);
#endif /* SB_USE_CLASS_TELGENERALNAME */

		virtual void get_Number(std::vector<uint8_t> &OutResult);

		virtual void set_Number(const std::vector<uint8_t> &Value);

		virtual TSBCRLReasonFlags get_Reasons();

		virtual void set_Reasons(TSBCRLReasonFlags Value);

		SB_DECLARE_PROPERTY(TSBCRLReasonFlags, get_Reasons, set_Reasons, TElCRLLookup, Reasons);

		virtual void get_AuthorityKeyIdentifier(std::vector<uint8_t> &OutResult);

		virtual void set_AuthorityKeyIdentifier(const std::vector<uint8_t> &Value);

		virtual void get_BaseCRLNumber(std::vector<uint8_t> &OutResult);

		virtual void set_BaseCRLNumber(const std::vector<uint8_t> &Value);

		virtual TSBCRLLookupCriteria get_Criteria();

		virtual void set_Criteria(TSBCRLLookupCriteria Value);

		SB_DECLARE_PROPERTY(TSBCRLLookupCriteria, get_Criteria, set_Criteria, TElCRLLookup, Criteria);

		virtual TSBCRLLookupOptions get_Options();

		virtual void set_Options(TSBCRLLookupOptions Value);

		SB_DECLARE_PROPERTY(TSBCRLLookupOptions, get_Options, set_Options, TElCRLLookup, Options);

		TElCRLLookup(TElCRLLookupHandle handle, TElOwnHandle ownHandle);

		explicit TElCRLLookup(TComponent &AOwner);

		explicit TElCRLLookup(TComponent *AOwner);

		virtual ~TElCRLLookup();

};
#endif /* SB_USE_CLASS_TELCRLLOOKUP */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
class TElMemoryCRLStorage: public TElCustomCRLStorage
{
	private:
		SB_DISABLE_COPY(TElMemoryCRLStorage)
	public:
		virtual void BeginRead();

		virtual void EndRead();

		virtual void BeginWrite();

		virtual void EndWrite();

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		virtual int32_t Add(TElCertificateRevocationList &CRL);

		virtual int32_t Add(TElCertificateRevocationList *CRL);
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

		virtual void Remove(int32_t Index);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		virtual int32_t IndexOf(TElCertificateRevocationList &Crl);

		virtual int32_t IndexOf(TElCertificateRevocationList *Crl);
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

		TElMemoryCRLStorage(TElMemoryCRLStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElMemoryCRLStorage(TComponent &AOwner);

		explicit TElMemoryCRLStorage(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

#ifdef SB_USE_CLASS_TELCRLCACHESTORAGE
class TElCRLCacheStorage: public TElMemoryCRLStorage
{
	private:
		SB_DISABLE_COPY(TElCRLCacheStorage)
	public:
#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		virtual int32_t Add(TElCertificateRevocationList &CRL);

		virtual int32_t Add(TElCertificateRevocationList *CRL);
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElCRLCacheStorage, Enabled);

		TElCRLCacheStorage(TElCRLCacheStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElCRLCacheStorage(TComponent &AOwner);

		explicit TElCRLCacheStorage(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELCRLCACHESTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRLRETRIEVER
class TElCustomCRLRetriever: public TComponent
{
	private:
		SB_DISABLE_COPY(TElCustomCRLRetriever)
	public:
		virtual bool Supports(TSBGeneralName NameType, const std::string &Location);

#ifdef SB_USE_CLASSES_TELCERTIFICATEREVOCATIONLIST_AND_TELX509CERTIFICATE
		virtual TElCertificateRevocationListHandle GetCRL(TElX509Certificate &ACertificate, TElX509Certificate &CACertificate, TSBGeneralName NameType, const std::string &Location);

		virtual TElCertificateRevocationListHandle GetCRL(TElX509Certificate *ACertificate, TElX509Certificate *CACertificate, TSBGeneralName NameType, const std::string &Location);
#endif /* SB_USE_CLASSES_TELCERTIFICATEREVOCATIONLIST_AND_TELX509CERTIFICATE */

		TElCustomCRLRetriever(TElCustomCRLRetrieverHandle handle, TElOwnHandle ownHandle);

		explicit TElCustomCRLRetriever(TComponent &AOwner);

		explicit TElCustomCRLRetriever(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELCUSTOMCRLRETRIEVER */

#ifdef SB_USE_CLASS_TELCUSTOMCRLRETRIEVERFACTORY
class TElCustomCRLRetrieverFactory: public TObject
{
	private:
		SB_DISABLE_COPY(TElCustomCRLRetrieverFactory)
	public:
		virtual bool Supports(TSBGeneralName NameType, const std::string &Location);

#ifdef SB_USE_CLASS_TELCUSTOMCRLRETRIEVER
		virtual TElCustomCRLRetrieverHandle GetRetrieverInstance(TObject &Validator);

		virtual TElCustomCRLRetrieverHandle GetRetrieverInstance(TObject *Validator);
#endif /* SB_USE_CLASS_TELCUSTOMCRLRETRIEVER */

		TElCustomCRLRetrieverFactory(TElCustomCRLRetrieverFactoryHandle handle, TElOwnHandle ownHandle);

		TElCustomCRLRetrieverFactory();

};
#endif /* SB_USE_CLASS_TELCUSTOMCRLRETRIEVERFACTORY */

#ifdef SB_USE_CLASS_TELCRLMANAGER
class TElCRLManager: public TObject
{
	private:
		SB_DISABLE_COPY(TElCRLManager)
#ifdef SB_USE_CLASS_TELCRLCACHESTORAGE
		TElCRLCacheStorage* _Inst_CRLCache;
#endif /* SB_USE_CLASS_TELCRLCACHESTORAGE */

		void initInstances();

	public:
		void PurgeExpiredCRLs();

#ifdef SB_USE_CLASS_TELCUSTOMCRLRETRIEVERFACTORY
		void RegisterCRLRetrieverFactory(TElCustomCRLRetrieverFactory &Factory);

		void RegisterCRLRetrieverFactory(TElCustomCRLRetrieverFactory *Factory);
#endif /* SB_USE_CLASS_TELCUSTOMCRLRETRIEVERFACTORY */

#ifdef SB_USE_CLASS_TELCUSTOMCRLRETRIEVERFACTORY
		void UnregisterCRLRetrieverFactory(TElCustomCRLRetrieverFactory &Factory);

		void UnregisterCRLRetrieverFactory(TElCustomCRLRetrieverFactory *Factory);
#endif /* SB_USE_CLASS_TELCUSTOMCRLRETRIEVERFACTORY */

#ifdef SB_USE_CLASS_TELCUSTOMCRLRETRIEVER
		TElCustomCRLRetrieverHandle FindCRLRetriever(TSBGeneralName NameType, const std::string &Location, TObject &Validator);

		TElCustomCRLRetrieverHandle FindCRLRetriever(TSBGeneralName NameType, const std::string &Location, TObject *Validator);
#endif /* SB_USE_CLASS_TELCUSTOMCRLRETRIEVER */

#ifdef SB_USE_CLASS_TELCRLCACHESTORAGE
		virtual TElCRLCacheStorage* get_CRLCache();

		SB_DECLARE_PROPERTY_GET(TElCRLCacheStorage*, get_CRLCache, TElCRLManager, CRLCache);
#endif /* SB_USE_CLASS_TELCRLCACHESTORAGE */

		virtual bool get_UseCache();

		virtual void set_UseCache(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseCache, set_UseCache, TElCRLManager, UseCache);

		TElCRLManager(TElCRLManagerHandle handle, TElOwnHandle ownHandle);

		TElCRLManager();

		virtual ~TElCRLManager();

};
#endif /* SB_USE_CLASS_TELCRLMANAGER */

#ifdef SB_USE_GLOBAL_PROCS_CRLSTORAGE

#ifdef SB_USE_CLASS_TELCRLMANAGER
TElCRLManagerHandle CRLManagerAddRef();
#endif /* SB_USE_CLASS_TELCRLMANAGER */

void CRLManagerRelease();

#endif /* SB_USE_GLOBAL_PROCS_CRLSTORAGE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_CRLSTORAGE
SB_IMPORT uint32_t SB_APIENTRY SBCRLStorage_CRLManagerAddRef(TElCRLManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCRLStorage_CRLManagerRelease(void);
#endif /* SB_USE_GLOBAL_PROCS_CRLSTORAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCRLSTORAGE */

