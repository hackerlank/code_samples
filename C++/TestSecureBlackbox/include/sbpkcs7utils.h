#ifndef __INC_SBPKCS7UTILS
#define __INC_SBPKCS7UTILS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbrdn.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbasn1tree.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ERROR_FACILITY_PKCS7 	7680
#define SB_PKCS7_ERROR_INVALID_ASN_DATA 	7681
#define SB_PKCS7_ERROR_NO_DATA 	7682
#define SB_PKCS7_ERROR_INVALID_CONTENT_INFO 	7683
#define SB_PKCS7_ERROR_UNKNOWN_DATA_TYPE 	7684
#define SB_PKCS7_ERROR_INVALID_DATA 	7685
#define SB_PKCS7_ERROR_INVALID_ENVELOPED_DATA 	7686
#define SB_PKCS7_ERROR_INVALID_ENVELOPED_DATA_VERSION 	7687
#define SB_PKCS7_ERROR_INVALID_ENVELOPED_DATA_CONTENT 	7688
#define SB_PKCS7_ERROR_INVALID_RECIPIENT_INFOS 	7689
#define SB_PKCS7_ERROR_INVALID_RECIPIENT_INFO 	7690
#define SB_PKCS7_ERROR_INVALID_RECIPIENT_INFO_VERSION 	7691
#define SB_PKCS7_ERROR_INVALID_RECIPIENT_INFO_KEY 	7692
#define SB_PKCS7_ERROR_INVALID_ISSUER 	7693
#define SB_PKCS7_ERROR_INVALID_ALGORITHM 	7694
#define SB_PKCS7_ERROR_INVALID_SIGNED_DATA 	7695
#define SB_PKCS7_ERROR_INVALID_SIGNED_DATA_VERSION 	7696
#define SB_PKCS7_ERROR_INVALID_SIGNER_INFOS 	7697
#define SB_PKCS7_ERROR_INVALID_SIGNER_INFO_VERSION 	7698
#define SB_PKCS7_ERROR_INVALID_SIGNER_INFO 	7699
#define SB_PKCS7_ERROR_INTERNAL_ERROR 	7700
#define SB_PKCS7_ERROR_INVALID_ATTRIBUTES 	7701
#define SB_PKCS7_ERROR_INVALID_DIGESTED_DATA 	7702
#define SB_PKCS7_ERROR_INVALID_DIGESTED_DATA_VERSION 	7703
#define SB_PKCS7_ERROR_INVALID_ENCRYPTED_DATA 	7704
#define SB_PKCS7_ERROR_INVALID_ENCRYPTED_DATA_VERSION 	7705
#define SB_PKCS7_ERROR_INVALID_SIGNED_AND_ENVELOPED_DATA 	7706
#define SB_PKCS7_ERROR_INVALID_SIGNED_AND_ENVELOPED_DATA_VERSION 	7707
#define SB_PKCS7_ERROR_INVALID_AUTHENTICATED_DATA 	7708
#define SB_PKCS7_ERROR_INVALID_AUTHENTICATED_DATA_VERSION 	7709
#define SB_PKCS7_ERROR_INVALID_COMPRESSED_DATA 	7710
#define SB_PKCS7_ERROR_INVALID_COMPRESSED_DATA_CONTENT 	7711
#define SB_PKCS7_ERROR_INVALID_TIMESTAMPED_DATA 	7712
#define SB_PKCS7_ERROR_INVALID_TIMESTAMPED_DATA_VERSION 	7713
#define SB_PKCS7_ERROR_INVALID_TIMESTAMPED_DATA_CONTENT 	7714
#define SB_PKCS7_ERROR_ASN_LIMIT_EXCEEDED 	7715

typedef TElClassHandle TElPKCS7AttributesHandle;

typedef TElClassHandle TElPKCS7IssuerHandle;

typedef uint8_t TSBPKCS7IssuerTypeRaw;

typedef enum
{
	itIssuerAndSerialNumber = 0,
	itSubjectKeyIdentifier = 1
} TSBPKCS7IssuerType;

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Attributes_Remove(TElPKCS7AttributesHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Attributes_Copy(TElPKCS7AttributesHandle _Handle, TElPKCS7AttributesHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Attributes_SaveToBuffer(TElPKCS7AttributesHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Attributes_LoadFromBuffer(TElPKCS7AttributesHandle _Handle, void * Buffer, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Attributes_FindAttribute(TElPKCS7AttributesHandle _Handle, const uint8_t pName[], int32_t szName, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Attributes_SortLexicographically(TElPKCS7AttributesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Attributes_RecalculateRawAttributeSequences(TElPKCS7AttributesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Attributes_Clear(TElPKCS7AttributesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Attributes_get_Attributes(TElPKCS7AttributesHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Attributes_set_Attributes(TElPKCS7AttributesHandle _Handle, int32_t Index, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Attributes_get_Values(TElPKCS7AttributesHandle _Handle, int32_t Index, TElByteArrayListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Attributes_get_RawAttributeSequences(TElPKCS7AttributesHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Attributes_set_RawAttributeSequences(TElPKCS7AttributesHandle _Handle, int32_t Index, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Attributes_get_Count(TElPKCS7AttributesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Attributes_set_Count(TElPKCS7AttributesHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Attributes_Create(TElPKCS7AttributesHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

#ifdef SB_USE_CLASS_TELPKCS7ISSUER
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Issuer_Assign(TElPKCS7IssuerHandle _Handle, TElPKCS7IssuerHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Issuer_Reset(TElPKCS7IssuerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Issuer_get_Issuer(TElPKCS7IssuerHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Issuer_get_SerialNumber(TElPKCS7IssuerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Issuer_set_SerialNumber(TElPKCS7IssuerHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Issuer_get_SubjectKeyIdentifier(TElPKCS7IssuerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Issuer_set_SubjectKeyIdentifier(TElPKCS7IssuerHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Issuer_get_IssuerType(TElPKCS7IssuerHandle _Handle, TSBPKCS7IssuerTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Issuer_set_IssuerType(TElPKCS7IssuerHandle _Handle, TSBPKCS7IssuerTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS7Issuer_Create(TElPKCS7IssuerHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPKCS7Attributes;
class TElPKCS7Issuer;

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
class TElPKCS7Attributes: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS7Attributes)
#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
		TElByteArrayList* _Inst_Values;
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

		void initInstances();

	public:
		bool Remove(int32_t Index);

		void Copy(TElPKCS7Attributes &Dest);

		void Copy(TElPKCS7Attributes *Dest);

		bool SaveToBuffer(void * Buffer, int32_t &Size);

		bool LoadFromBuffer(void * Buffer, int32_t Size);

		int32_t FindAttribute(const std::vector<uint8_t> &Name);

		void SortLexicographically();

		void RecalculateRawAttributeSequences();

		void Clear();

		virtual void get_Attributes(int32_t Index, std::vector<uint8_t> &OutResult);

		virtual void set_Attributes(int32_t Index, const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
		virtual TElByteArrayList* get_Values(int32_t Index);
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

		virtual void get_RawAttributeSequences(int32_t Index, std::vector<uint8_t> &OutResult);

		virtual void set_RawAttributeSequences(int32_t Index, const std::vector<uint8_t> &Value);

		virtual int32_t get_Count();

		virtual void set_Count(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Count, set_Count, TElPKCS7Attributes, Count);

		TElPKCS7Attributes(TElPKCS7AttributesHandle handle, TElOwnHandle ownHandle);

		TElPKCS7Attributes();

		virtual ~TElPKCS7Attributes();

};
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

#ifdef SB_USE_CLASS_TELPKCS7ISSUER
class TElPKCS7Issuer: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS7Issuer)
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_Issuer;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		void initInstances();

	public:
		void Assign(TElPKCS7Issuer &Source);

		void Assign(TElPKCS7Issuer *Source);

		void Reset();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_Issuer();

		SB_DECLARE_PROPERTY_GET(TElRelativeDistinguishedName*, get_Issuer, TElPKCS7Issuer, Issuer);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void get_SerialNumber(std::vector<uint8_t> &OutResult);

		virtual void set_SerialNumber(const std::vector<uint8_t> &Value);

		virtual void get_SubjectKeyIdentifier(std::vector<uint8_t> &OutResult);

		virtual void set_SubjectKeyIdentifier(const std::vector<uint8_t> &Value);

		virtual TSBPKCS7IssuerType get_IssuerType();

		virtual void set_IssuerType(TSBPKCS7IssuerType Value);

		SB_DECLARE_PROPERTY(TSBPKCS7IssuerType, get_IssuerType, set_IssuerType, TElPKCS7Issuer, IssuerType);

		TElPKCS7Issuer(TElPKCS7IssuerHandle handle, TElOwnHandle ownHandle);

		TElPKCS7Issuer();

		virtual ~TElPKCS7Issuer();

};
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

#ifdef SB_USE_GLOBAL_PROCS_PKCS7UTILS

#ifdef SB_USE_CLASSES_TELASN1CONSTRAINEDTAG_AND_TELPKCS7ATTRIBUTES
void SaveAttributes(TElASN1ConstrainedTag &Tag, TElPKCS7Attributes &Attributes, uint8_t TagID);
void SaveAttributes(TElASN1ConstrainedTag *Tag, TElPKCS7Attributes *Attributes, uint8_t TagID);
#endif /* SB_USE_CLASSES_TELASN1CONSTRAINEDTAG_AND_TELPKCS7ATTRIBUTES */

#ifdef SB_USE_CLASSES_TELASN1CUSTOMTAG_AND_TELPKCS7ATTRIBUTES
int32_t ProcessAttributes(TElASN1CustomTag &Tag, TElPKCS7Attributes &Attributes);
int32_t ProcessAttributes(TElASN1CustomTag *Tag, TElPKCS7Attributes *Attributes);
#endif /* SB_USE_CLASSES_TELASN1CUSTOMTAG_AND_TELPKCS7ATTRIBUTES */

#ifdef SB_USE_CLASS_TELASN1CUSTOMTAG
int32_t ProcessAlgorithmIdentifier(TElASN1CustomTag &Tag, std::vector<uint8_t> &Algorithm, std::vector<uint8_t> &Params, bool ImplicitTagging);
int32_t ProcessAlgorithmIdentifier(TElASN1CustomTag *Tag, std::vector<uint8_t> &Algorithm, std::vector<uint8_t> &Params, bool ImplicitTagging);
#endif /* SB_USE_CLASS_TELASN1CUSTOMTAG */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
void SaveAlgorithmIdentifier(TElASN1ConstrainedTag &Tag, const std::vector<uint8_t> &Algorithm, const std::vector<uint8_t> &Params, uint8_t ImplicitTag, bool WriteNullIfParamsAreEmpty);
void SaveAlgorithmIdentifier(TElASN1ConstrainedTag *Tag, const std::vector<uint8_t> &Algorithm, const std::vector<uint8_t> &Params, uint8_t ImplicitTag, bool WriteNullIfParamsAreEmpty);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#endif /* SB_USE_GLOBAL_PROCS_PKCS7UTILS */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_PKCS7UTILS
SB_IMPORT uint32_t SB_APIENTRY SBPKCS7Utils_SaveAttributes(TElASN1ConstrainedTagHandle Tag, TElPKCS7AttributesHandle Attributes, uint8_t TagID);
SB_IMPORT uint32_t SB_APIENTRY SBPKCS7Utils_ProcessAttributes(TElASN1CustomTagHandle Tag, TElPKCS7AttributesHandle Attributes, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPKCS7Utils_ProcessAlgorithmIdentifier(TElASN1CustomTagHandle Tag, uint8_t pAlgorithm[], int32_t * szAlgorithm, uint8_t pParams[], int32_t * szParams, int8_t ImplicitTagging, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPKCS7Utils_SaveAlgorithmIdentifier(TElASN1ConstrainedTagHandle Tag, const uint8_t pAlgorithm[], int32_t szAlgorithm, const uint8_t pParams[], int32_t szParams, uint8_t ImplicitTag, int8_t WriteNullIfParamsAreEmpty);
#endif /* SB_USE_GLOBAL_PROCS_PKCS7UTILS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPKCS7UTILS */

