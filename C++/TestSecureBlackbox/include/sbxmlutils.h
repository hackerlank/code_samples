#ifndef __INC_SBXMLUTILS
#define __INC_SBXMLUTILS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbstrutils.h"
#include "sbencoding.h"
#include "sbxmldefs.h"
#include "sbxmlcore.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_XML_DATETIME_SKIP_TIMEZONE 	-1000

typedef uint8_t TSBXMLDateTimeFormatRaw;

typedef enum
{
	xdfYear = 0,
	xdfYearMonth = 1,
	xdfFullDate = 2,
	xdfDateHoursMinutes = 3,
	xdfDateTimeWithSeconds = 4,
	xdfDateTimeWithSecondFraction = 5,
	xdfFullDateTime = 6
} TSBXMLDateTimeFormat;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_XMLUTILS

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
TElXMLDOMElementHandle ParseElementFromXMLString(const sb_u16string &Data, const TElXMLDOMDocument &Document);
TElXMLDOMElementHandle ParseElementFromXMLString(const sb_u16string &Data, const TElXMLDOMDocument *Document);
#ifdef SB_U16STRING_USED
TElXMLDOMElementHandle ParseElementFromXMLString(const std::wstring &Data, const TElXMLDOMDocument &Document);
TElXMLDOMElementHandle ParseElementFromXMLString(const std::wstring &Data, const TElXMLDOMDocument *Document);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMNODELIST
TElXMLDOMNodeListHandle ParseNodeListFromXMLString(const sb_u16string &Data, const TElXMLDOMDocument &Document);
TElXMLDOMNodeListHandle ParseNodeListFromXMLString(const sb_u16string &Data, const TElXMLDOMDocument *Document);
#ifdef SB_U16STRING_USED
TElXMLDOMNodeListHandle ParseNodeListFromXMLString(const std::wstring &Data, const TElXMLDOMDocument &Document);
TElXMLDOMNodeListHandle ParseNodeListFromXMLString(const std::wstring &Data, const TElXMLDOMDocument *Document);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMNODELIST */

void ConvertToBase64String(const std::vector<uint8_t> &Buf, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void ConvertToBase64String(const std::vector<uint8_t> &Buf, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void ConvertFromBase64String(const sb_u16string &S, std::vector<uint8_t> &OutResult);
#ifdef SB_U16STRING_USED
void ConvertFromBase64String(const std::wstring &S, std::vector<uint8_t> &OutResult);
#endif /* SB_U16STRING_USED */

void ConvertBinaryToBigInt(const std::vector<uint8_t> &Buf, bool AllowNegativeNumbers, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void ConvertBinaryToBigInt(const std::vector<uint8_t> &Buf, bool AllowNegativeNumbers, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void ConvertBigIntToBinary(const sb_u16string &Value, bool AllowHexNumbers, std::vector<uint8_t> &OutResult);
#ifdef SB_U16STRING_USED
void ConvertBigIntToBinary(const std::wstring &Value, bool AllowHexNumbers, std::vector<uint8_t> &OutResult);
#endif /* SB_U16STRING_USED */

void ConvertHexToBinary(const sb_u16string &Value, std::vector<uint8_t> &OutResult);
#ifdef SB_U16STRING_USED
void ConvertHexToBinary(const std::wstring &Value, std::vector<uint8_t> &OutResult);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
void AddTextToXMLElement(const sb_u16string &Text, const TElXMLDOMElement &Element);
void AddTextToXMLElement(const sb_u16string &Text, const TElXMLDOMElement *Element);
#ifdef SB_U16STRING_USED
void AddTextToXMLElement(const std::wstring &Text, const TElXMLDOMElement &Element);
void AddTextToXMLElement(const std::wstring &Text, const TElXMLDOMElement *Element);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLDOMNODE
void InsertTextBeforeXMLElement(const sb_u16string &Text, TElXMLDOMElement &Element, TElXMLDOMNode &Ref);
void InsertTextBeforeXMLElement(const sb_u16string &Text, TElXMLDOMElement *Element, TElXMLDOMNode *Ref);
#ifdef SB_U16STRING_USED
void InsertTextBeforeXMLElement(const std::wstring &Text, TElXMLDOMElement &Element, TElXMLDOMNode &Ref);
void InsertTextBeforeXMLElement(const std::wstring &Text, TElXMLDOMElement *Element, TElXMLDOMNode *Ref);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
void GetTextFromXMLElement(const TElXMLDOMElement &Element, sb_u16string &OutResult);
void GetTextFromXMLElement(const TElXMLDOMElement *Element, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void GetTextFromXMLElement(const TElXMLDOMElement &Element, std::wstring &OutResult);
void GetTextFromXMLElement(const TElXMLDOMElement *Element, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
void GetStrictTextFromXMLElement(const TElXMLDOMElement &Element, sb_u16string &OutResult);
void GetStrictTextFromXMLElement(const TElXMLDOMElement *Element, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void GetStrictTextFromXMLElement(const TElXMLDOMElement &Element, std::wstring &OutResult);
void GetStrictTextFromXMLElement(const TElXMLDOMElement *Element, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElementHandle FindChildElementByLocalName(const TElXMLDOMElement &Element, const sb_u16string &LocalName);
TElXMLDOMElementHandle FindChildElementByLocalName(const TElXMLDOMElement *Element, const sb_u16string &LocalName);
#ifdef SB_U16STRING_USED
TElXMLDOMElementHandle FindChildElementByLocalName(const TElXMLDOMElement &Element, const std::wstring &LocalName);
TElXMLDOMElementHandle FindChildElementByLocalName(const TElXMLDOMElement *Element, const std::wstring &LocalName);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElementHandle FindChildElement(const TElXMLDOMElement &Element, const sb_u16string &Name, const sb_u16string &NamespaceURI, const sb_u16string &DefaultPrefix);
TElXMLDOMElementHandle FindChildElement(const TElXMLDOMElement *Element, const sb_u16string &Name, const sb_u16string &NamespaceURI, const sb_u16string &DefaultPrefix);
#ifdef SB_U16STRING_USED
TElXMLDOMElementHandle FindChildElement(const TElXMLDOMElement &Element, const std::wstring &Name, const std::wstring &NamespaceURI, const std::wstring &DefaultPrefix);
TElXMLDOMElementHandle FindChildElement(const TElXMLDOMElement *Element, const std::wstring &Name, const std::wstring &NamespaceURI, const std::wstring &DefaultPrefix);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElementHandle FindElementById(const TElXMLDOMElement &RootElement, const sb_u16string &ID);
TElXMLDOMElementHandle FindElementById(const TElXMLDOMElement *RootElement, const sb_u16string &ID);
#ifdef SB_U16STRING_USED
TElXMLDOMElementHandle FindElementById(const TElXMLDOMElement &RootElement, const std::wstring &ID);
TElXMLDOMElementHandle FindElementById(const TElXMLDOMElement *RootElement, const std::wstring &ID);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElementHandle FindElementById(const TElXMLDOMElement &RootElement, const sb_u16string &ID, const sb_u16string &NamespaceURI);
TElXMLDOMElementHandle FindElementById(const TElXMLDOMElement *RootElement, const sb_u16string &ID, const sb_u16string &NamespaceURI);
#ifdef SB_U16STRING_USED
TElXMLDOMElementHandle FindElementById(const TElXMLDOMElement &RootElement, const std::wstring &ID, const std::wstring &NamespaceURI);
TElXMLDOMElementHandle FindElementById(const TElXMLDOMElement *RootElement, const std::wstring &ID, const std::wstring &NamespaceURI);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElementHandle FindElementByName(const TElXMLDOMElement &RootElement, const sb_u16string &Name, const sb_u16string &NamespaceURI);
TElXMLDOMElementHandle FindElementByName(const TElXMLDOMElement *RootElement, const sb_u16string &Name, const sb_u16string &NamespaceURI);
#ifdef SB_U16STRING_USED
TElXMLDOMElementHandle FindElementByName(const TElXMLDOMElement &RootElement, const std::wstring &Name, const std::wstring &NamespaceURI);
TElXMLDOMElementHandle FindElementByName(const TElXMLDOMElement *RootElement, const std::wstring &Name, const std::wstring &NamespaceURI);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void ExtractIdFromLocalURI(const sb_u16string &URI, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void ExtractIdFromLocalURI(const std::wstring &URI, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

bool SBXMLUtils_ExtractIdFromLocalURI(const sb_u16string &URI, sb_u16string &Id);
#ifdef SB_U16STRING_USED
bool SBXMLUtils_ExtractIdFromLocalURI(const std::wstring &URI, std::wstring &Id);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
void GetElementId(TElXMLDOMElement &Element, sb_u16string &OutResult);
void GetElementId(TElXMLDOMElement *Element, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void GetElementId(TElXMLDOMElement &Element, std::wstring &OutResult);
void GetElementId(TElXMLDOMElement *Element, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
void SetElementId(TElXMLDOMElement &Element, const sb_u16string &Value);
void SetElementId(TElXMLDOMElement *Element, const sb_u16string &Value);
#ifdef SB_U16STRING_USED
void SetElementId(TElXMLDOMElement &Element, const std::wstring &Value);
void SetElementId(TElXMLDOMElement *Element, const std::wstring &Value);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void CanonicalizationMethodToURI(TElXMLCanonicalizationMethod ACanonicalizationMethod, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void CanonicalizationMethodToURI(TElXMLCanonicalizationMethod ACanonicalizationMethod, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

TElXMLCanonicalizationMethod URIToCanonicalizationMethod(const sb_u16string &AURI);
#ifdef SB_U16STRING_USED
TElXMLCanonicalizationMethod URIToCanonicalizationMethod(const std::wstring &AURI);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
void AddPrefixes(TElXMLDOMElement &Element, const sb_u16string &Prefixes, const sb_u16string &NamespaceURI);
void AddPrefixes(TElXMLDOMElement *Element, const sb_u16string &Prefixes, const sb_u16string &NamespaceURI);
#ifdef SB_U16STRING_USED
void AddPrefixes(TElXMLDOMElement &Element, const std::wstring &Prefixes, const std::wstring &NamespaceURI);
void AddPrefixes(TElXMLDOMElement *Element, const std::wstring &Prefixes, const std::wstring &NamespaceURI);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void DateTimeToXMLString(int64_t Value, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void DateTimeToXMLString(int64_t Value, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void DateTimeToXMLString(int64_t Value, TSBXMLDateTimeFormat Format, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void DateTimeToXMLString(int64_t Value, TSBXMLDateTimeFormat Format, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void DateTimeToXMLString(int64_t Value, TSBXMLDateTimeFormat Format, int32_t TimeZoneOffset, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void DateTimeToXMLString(int64_t Value, TSBXMLDateTimeFormat Format, int32_t TimeZoneOffset, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

int64_t XMLStringToDateTime(const sb_u16string &Value);
#ifdef SB_U16STRING_USED
int64_t XMLStringToDateTime(const std::wstring &Value);
#endif /* SB_U16STRING_USED */

void DateTimeFormatToString(TSBXMLDateTimeFormat Format, std::string &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_XMLUTILS */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_XMLUTILS
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_ParseElementFromXMLString(const sb_char16_t * pcData, int32_t szData, const TElXMLDOMDocumentHandle Document, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_ParseNodeListFromXMLString(const sb_char16_t * pcData, int32_t szData, const TElXMLDOMDocumentHandle Document, TElXMLDOMNodeListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_ConvertToBase64String(const uint8_t pBuf[], int32_t szBuf, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_ConvertFromBase64String(const sb_char16_t * pcS, int32_t szS, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_ConvertBinaryToBigInt(const uint8_t pBuf[], int32_t szBuf, int8_t AllowNegativeNumbers, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_ConvertBigIntToBinary(const sb_char16_t * pcValue, int32_t szValue, int8_t AllowHexNumbers, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_ConvertHexToBinary(const sb_char16_t * pcValue, int32_t szValue, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_AddTextToXMLElement(const sb_char16_t * pcText, int32_t szText, const TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_InsertTextBeforeXMLElement(const sb_char16_t * pcText, int32_t szText, TElXMLDOMElementHandle Element, TElXMLDOMNodeHandle Ref);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_GetTextFromXMLElement(const TElXMLDOMElementHandle Element, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_GetStrictTextFromXMLElement(const TElXMLDOMElementHandle Element, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_FindChildElementByLocalName(const TElXMLDOMElementHandle Element, const sb_char16_t * pcLocalName, int32_t szLocalName, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_FindChildElement(const TElXMLDOMElementHandle Element, const sb_char16_t * pcName, int32_t szName, const sb_char16_t * pcNamespaceURI, int32_t szNamespaceURI, const sb_char16_t * pcDefaultPrefix, int32_t szDefaultPrefix, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_FindElementById(const TElXMLDOMElementHandle RootElement, const sb_char16_t * pcID, int32_t szID, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_FindElementById_1(const TElXMLDOMElementHandle RootElement, const sb_char16_t * pcID, int32_t szID, const sb_char16_t * pcNamespaceURI, int32_t szNamespaceURI, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_FindElementByName(const TElXMLDOMElementHandle RootElement, const sb_char16_t * pcName, int32_t szName, const sb_char16_t * pcNamespaceURI, int32_t szNamespaceURI, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_ExtractIdFromLocalURI(const sb_char16_t * pcURI, int32_t szURI, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_ExtractIdFromLocalURI_1(const sb_char16_t * pcURI, int32_t szURI, sb_char16_t * pcId, int32_t * szId, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_GetElementId(TElXMLDOMElementHandle Element, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_SetElementId(TElXMLDOMElementHandle Element, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_CanonicalizationMethodToURI(TElXMLCanonicalizationMethodRaw ACanonicalizationMethod, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_URIToCanonicalizationMethod(const sb_char16_t * pcAURI, int32_t szAURI, TElXMLCanonicalizationMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_AddPrefixes(TElXMLDOMElementHandle Element, const sb_char16_t * pcPrefixes, int32_t szPrefixes, const sb_char16_t * pcNamespaceURI, int32_t szNamespaceURI);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_DateTimeToXMLString(int64_t Value, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_DateTimeToXMLString_1(int64_t Value, TSBXMLDateTimeFormatRaw Format, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_DateTimeToXMLString_2(int64_t Value, TSBXMLDateTimeFormatRaw Format, int32_t TimeZoneOffset, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_XMLStringToDateTime(const sb_char16_t * pcValue, int32_t szValue, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLUtils_DateTimeFormatToString(TSBXMLDateTimeFormatRaw Format, char * pcOutResult, int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_XMLUTILS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBXMLUTILS */

