#ifndef __INC_SBRDN
#define __INC_SBRDN

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstringlist.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbchsunicode.h"
#include "sbasn1tree.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_NullCharsCount 	214
#define SB_SpaceCharsCount 	24

typedef TElClassHandle TElRelativeDistinguishedNameHandle;

typedef TElRelativeDistinguishedNameHandle ElRelativeDistinguishedNameHandle;

typedef TElClassHandle TElRDNConverterHandle;

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_Assign(TElRelativeDistinguishedNameHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_LoadFromTag(TElRelativeDistinguishedNameHandle _Handle, TElASN1ConstrainedTagHandle Tag, int8_t IgnoreTopSequence, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_LoadFromDNString(TElRelativeDistinguishedNameHandle _Handle, const char * pcS, int32_t szS, int8_t LiberalMode, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_SaveToTag(TElRelativeDistinguishedNameHandle _Handle, TElASN1ConstrainedTagHandle Tag, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_SaveToDNString(TElRelativeDistinguishedNameHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_Add(TElRelativeDistinguishedNameHandle _Handle, const uint8_t pOID[], int32_t szOID, const uint8_t pValue[], int32_t szValue, uint8_t Tag, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_Remove(TElRelativeDistinguishedNameHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_IndexOf(TElRelativeDistinguishedNameHandle _Handle, const uint8_t pOID[], int32_t szOID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_Clear(TElRelativeDistinguishedNameHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_GetValuesByOID(TElRelativeDistinguishedNameHandle _Handle, const uint8_t pOID[], int32_t szOID, TElByteArrayListHandle Values);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_GetFirstValueByOID(TElRelativeDistinguishedNameHandle _Handle, const uint8_t pOID[], int32_t szOID, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_GetStringValuesByOID(TElRelativeDistinguishedNameHandle _Handle, const uint8_t pOID[], int32_t szOID, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_GetStringValuesByOID_1(TElRelativeDistinguishedNameHandle _Handle, const uint8_t pOID[], int32_t szOID, const char * pcValueSeparator, int32_t szValueSeparator, int8_t EncodeSpecialChars, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_GetFirstStringValueByOID(TElRelativeDistinguishedNameHandle _Handle, const uint8_t pOID[], int32_t szOID, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_GetFirstStringValueByOID_1(TElRelativeDistinguishedNameHandle _Handle, const uint8_t pOID[], int32_t szOID, int8_t EncodeSpecialChars, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_Contains(TElRelativeDistinguishedNameHandle _Handle, TElRelativeDistinguishedNameHandle RDN, int8_t IgnoreTags, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_get_Values(TElRelativeDistinguishedNameHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_set_Values(TElRelativeDistinguishedNameHandle _Handle, int32_t Index, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_get_NormValues(TElRelativeDistinguishedNameHandle _Handle, int32_t Index, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_set_NormValues(TElRelativeDistinguishedNameHandle _Handle, int32_t Index, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_get_OIDs(TElRelativeDistinguishedNameHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_set_OIDs(TElRelativeDistinguishedNameHandle _Handle, int32_t Index, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_get_Tags(TElRelativeDistinguishedNameHandle _Handle, int32_t Index, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_set_Tags(TElRelativeDistinguishedNameHandle _Handle, int32_t Index, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_get_Groups(TElRelativeDistinguishedNameHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_set_Groups(TElRelativeDistinguishedNameHandle _Handle, int32_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_get_Count(TElRelativeDistinguishedNameHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_set_Count(TElRelativeDistinguishedNameHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRelativeDistinguishedName_Create(TElRelativeDistinguishedNameHandle * OutResult);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRDNCONVERTER
SB_IMPORT uint32_t SB_APIENTRY TElRDNConverter_SaveToDNString(TElRDNConverterHandle _Handle, TElRelativeDistinguishedNameHandle RDN, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRDNConverter_LoadFromDNString(TElRDNConverterHandle _Handle, TElRelativeDistinguishedNameHandle RDN, const char * pcS, int32_t szS, int8_t LiberalMode);
SB_IMPORT uint32_t SB_APIENTRY TElRDNConverter_get_Separator(TElRDNConverterHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRDNConverter_set_Separator(TElRDNConverterHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElRDNConverter_get_InsertSeparatorPrefix(TElRDNConverterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRDNConverter_set_InsertSeparatorPrefix(TElRDNConverterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRDNConverter_Create(TElRDNConverterHandle * OutResult);
#endif /* SB_USE_CLASS_TELRDNCONVERTER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElRelativeDistinguishedName;
typedef TElRelativeDistinguishedName ElRelativeDistinguishedName;
class TElRDNConverter;

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
class TElRelativeDistinguishedName: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElRelativeDistinguishedName)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
		bool LoadFromTag(TElASN1ConstrainedTag &Tag, bool IgnoreTopSequence);

		bool LoadFromTag(TElASN1ConstrainedTag *Tag, bool IgnoreTopSequence);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

		bool LoadFromDNString(const std::string &S, bool LiberalMode);

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
		bool SaveToTag(TElASN1ConstrainedTag &Tag);

		bool SaveToTag(TElASN1ConstrainedTag *Tag);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

		void SaveToDNString(std::string &OutResult);

		int32_t Add(const std::vector<uint8_t> &OID, const std::vector<uint8_t> &Value, uint8_t Tag);

		void Remove(int32_t Index);

		int32_t IndexOf(const std::vector<uint8_t> &OID);

		void Clear();

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
		void GetValuesByOID(const std::vector<uint8_t> &OID, TElByteArrayList &Values);

		void GetValuesByOID(const std::vector<uint8_t> &OID, TElByteArrayList *Values);
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

		void GetFirstValueByOID(const std::vector<uint8_t> &OID, std::vector<uint8_t> &OutResult);

		void GetStringValuesByOID(const std::vector<uint8_t> &OID, std::string &OutResult);

		void GetStringValuesByOID(const std::vector<uint8_t> &OID, const std::string &ValueSeparator, bool EncodeSpecialChars, std::string &OutResult);

		void GetFirstStringValueByOID(const std::vector<uint8_t> &OID, std::string &OutResult);

		void GetFirstStringValueByOID(const std::vector<uint8_t> &OID, bool EncodeSpecialChars, std::string &OutResult);

		bool Contains(TElRelativeDistinguishedName &RDN, bool IgnoreTags);

		bool Contains(TElRelativeDistinguishedName *RDN, bool IgnoreTags);

		virtual void get_Values(int32_t Index, std::vector<uint8_t> &OutResult);

		virtual void set_Values(int32_t Index, const std::vector<uint8_t> &Value);

		virtual void get_NormValues(int32_t Index, sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_NormValues(int32_t Index, std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_NormValues(int32_t Index, const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_NormValues(int32_t Index, const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_OIDs(int32_t Index, std::vector<uint8_t> &OutResult);

		virtual void set_OIDs(int32_t Index, const std::vector<uint8_t> &Value);

		virtual uint8_t get_Tags(int32_t Index);

		virtual void set_Tags(int32_t Index, uint8_t Value);

		virtual int32_t get_Groups(int32_t Index);

		virtual void set_Groups(int32_t Index, int32_t Value);

		virtual int32_t get_Count();

		virtual void set_Count(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Count, set_Count, TElRelativeDistinguishedName, Count);

		TElRelativeDistinguishedName(TElRelativeDistinguishedNameHandle handle, TElOwnHandle ownHandle);

		TElRelativeDistinguishedName();

};
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRDNCONVERTER
class TElRDNConverter: public TObject
{
	private:
		SB_DISABLE_COPY(TElRDNConverter)
	public:
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		void SaveToDNString(TElRelativeDistinguishedName &RDN, std::string &OutResult);

		void SaveToDNString(TElRelativeDistinguishedName *RDN, std::string &OutResult);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		void LoadFromDNString(TElRelativeDistinguishedName &RDN, const std::string &S, bool LiberalMode);

		void LoadFromDNString(TElRelativeDistinguishedName *RDN, const std::string &S, bool LiberalMode);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void get_Separator(std::string &OutResult);

		virtual void set_Separator(const std::string &Value);

		virtual bool get_InsertSeparatorPrefix();

		virtual void set_InsertSeparatorPrefix(bool Value);

		SB_DECLARE_PROPERTY(bool, get_InsertSeparatorPrefix, set_InsertSeparatorPrefix, TElRDNConverter, InsertSeparatorPrefix);

		TElRDNConverter(TElRDNConverterHandle handle, TElOwnHandle ownHandle);

		TElRDNConverter();

};
#endif /* SB_USE_CLASS_TELRDNCONVERTER */

#ifdef SB_USE_GLOBAL_PROCS_RDN

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
void FormatRDN(TElRelativeDistinguishedName &RDN, std::string &OutResult);
void FormatRDN(TElRelativeDistinguishedName *RDN, std::string &OutResult);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

void MapUnicodeString(const sb_u16string &str, bool CaseIgnore, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void MapUnicodeString(const std::wstring &str, bool CaseIgnore, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void InsignificantSpaceHandling(const sb_u16string &str, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void InsignificantSpaceHandling(const std::wstring &str, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
void GetRDNStringValue(const TElRelativeDistinguishedName &RDN, int32_t Index, sb_u16string &OutResult);
void GetRDNStringValue(const TElRelativeDistinguishedName *RDN, int32_t Index, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void GetRDNStringValue(const TElRelativeDistinguishedName &RDN, int32_t Index, std::wstring &OutResult);
void GetRDNStringValue(const TElRelativeDistinguishedName *RDN, int32_t Index, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
void GetNormalizedRDNStringValue(const TElRelativeDistinguishedName &RDN, int32_t Index, sb_u16string &OutResult);
void GetNormalizedRDNStringValue(const TElRelativeDistinguishedName *RDN, int32_t Index, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void GetNormalizedRDNStringValue(const TElRelativeDistinguishedName &RDN, int32_t Index, std::wstring &OutResult);
void GetNormalizedRDNStringValue(const TElRelativeDistinguishedName *RDN, int32_t Index, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

void GetNormalizedRDNString(const sb_u16string &Value, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void GetNormalizedRDNString(const std::wstring &Value, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool CompareRDN(TElRelativeDistinguishedName &Name1, TElRelativeDistinguishedName &Name2);
bool CompareRDN(TElRelativeDistinguishedName *Name1, TElRelativeDistinguishedName *Name2);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool CompareRDNAsStrings(TElRelativeDistinguishedName &Name1, TElRelativeDistinguishedName &Name2);
bool CompareRDNAsStrings(TElRelativeDistinguishedName *Name1, TElRelativeDistinguishedName *Name2);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool NonstrictCompareRDN(TElRelativeDistinguishedName &InnerRDN, TElRelativeDistinguishedName &OuterRDN);
bool NonstrictCompareRDN(TElRelativeDistinguishedName *InnerRDN, TElRelativeDistinguishedName *OuterRDN);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool NonstrictCompareRDNAsStrings(TElRelativeDistinguishedName &InnerRDN, TElRelativeDistinguishedName &OuterRDN);
bool NonstrictCompareRDNAsStrings(TElRelativeDistinguishedName *InnerRDN, TElRelativeDistinguishedName *OuterRDN);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

bool GetIgnoreTagsWhenComparingRDNs();

void SetIgnoreTagsWhenComparingRDNs(bool Value);

#endif /* SB_USE_GLOBAL_PROCS_RDN */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_RDN
SB_IMPORT uint32_t SB_APIENTRY SBRDN_FormatRDN(TElRelativeDistinguishedNameHandle RDN, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRDN_MapUnicodeString(const sb_char16_t * pcstr, int32_t szstr, int8_t CaseIgnore, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRDN_InsignificantSpaceHandling(const sb_char16_t * pcstr, int32_t szstr, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRDN_GetRDNStringValue(const TElRelativeDistinguishedNameHandle RDN, int32_t Index, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRDN_GetNormalizedRDNStringValue(const TElRelativeDistinguishedNameHandle RDN, int32_t Index, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRDN_GetNormalizedRDNString(const sb_char16_t * pcValue, int32_t szValue, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRDN_CompareRDN(TElRelativeDistinguishedNameHandle Name1, TElRelativeDistinguishedNameHandle Name2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRDN_CompareRDNAsStrings(TElRelativeDistinguishedNameHandle Name1, TElRelativeDistinguishedNameHandle Name2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRDN_NonstrictCompareRDN(TElRelativeDistinguishedNameHandle InnerRDN, TElRelativeDistinguishedNameHandle OuterRDN, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRDN_NonstrictCompareRDNAsStrings(TElRelativeDistinguishedNameHandle InnerRDN, TElRelativeDistinguishedNameHandle OuterRDN, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRDN_GetIgnoreTagsWhenComparingRDNs(int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRDN_SetIgnoreTagsWhenComparingRDNs(int8_t Value);
#endif /* SB_USE_GLOBAL_PROCS_RDN */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBRDN */

