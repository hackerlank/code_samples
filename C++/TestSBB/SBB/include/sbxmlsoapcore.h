#ifndef __INC_SBXMLSOAPCORE
#define __INC_SBXMLSOAPCORE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstrutils.h"
#include "sbutils.h"
#include "sbxmldefs.h"
#include "sbxmlcore.h"
#include "sbxmlsec.h"
#include "sbxmlutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SSOAPUnsupportedOperation 	"This operation is not supported"
#define SB_SSOAPDocumentElementExists 	"The XML document already contains a DocumentElement"
#define SB_SSOAPEnvelopeBodyElementExists 	"SOAP envelope already contain a Body element"
#define SB_SSOAPEnvelopeHeaderElementExists 	"SOAP envelope already contain a Header element"
#define SB_SSOAPHeaderElementNotLoaded 	"Header element is not loaded"
#define SB_SSOAPHeaderBlockNotLoaded 	"Header block is not loaded"
#define SB_SSOAPBodyElementNotLoaded 	"Body element is not loaded"

typedef TElClassHandle TElXMLSOAPElementHandle;

typedef TElClassHandle TElXMLSOAPHeaderBlockHandle;

typedef TElClassHandle TElXMLSOAPHeaderHandle;

typedef TElClassHandle TElXMLSOAPBodyEntryHandle;

typedef TElClassHandle TElXMLSOAPBodyHandle;

typedef TElClassHandle TElXMLSOAPEnvelopeHandle;

typedef uint8_t TSBXMLSOAPVersionRaw;

typedef enum
{
	SOAP_v1_1 = 0,
	SOAP_v1_2 = 1
} TSBXMLSOAPVersion;

#ifdef SB_USE_CLASS_TELXMLSOAPELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPElement_LoadFromXML(TElXMLSOAPElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPElement_SaveToXML(TElXMLSOAPElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPElement_get_SOAPVersion(TElXMLSOAPElementHandle _Handle, TSBXMLSOAPVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPElement_get_NamespaceURI(TElXMLSOAPElementHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPElement_Create(TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, TElXMLSOAPElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPElement_Create_1(TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, const sb_char16_t * pcAName, int32_t szAName, TElXMLSOAPElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPElement_Create_2(TElXMLDOMElementHandle ParentElement, TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, TElXMLSOAPElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPElement_Create_3(TElXMLDOMElementHandle ParentElement, TElXMLDOMElementHandle BeforeChild, TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, const sb_char16_t * pcAName, int32_t szAName, TElXMLSOAPElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPELEMENT */

#ifdef SB_USE_CLASS_TELXMLSOAPHEADERBLOCK
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeaderBlock_LoadFromXML(TElXMLSOAPHeaderBlockHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeaderBlock_SaveToXML(TElXMLSOAPHeaderBlockHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeaderBlock_get_Actor(TElXMLSOAPHeaderBlockHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeaderBlock_set_Actor(TElXMLSOAPHeaderBlockHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeaderBlock_get_EncodingStyle(TElXMLSOAPHeaderBlockHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeaderBlock_set_EncodingStyle(TElXMLSOAPHeaderBlockHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeaderBlock_get_Role(TElXMLSOAPHeaderBlockHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeaderBlock_set_Role(TElXMLSOAPHeaderBlockHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeaderBlock_get_MustUnderstand(TElXMLSOAPHeaderBlockHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeaderBlock_set_MustUnderstand(TElXMLSOAPHeaderBlockHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeaderBlock_get_Relay(TElXMLSOAPHeaderBlockHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeaderBlock_set_Relay(TElXMLSOAPHeaderBlockHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeaderBlock_get_SOAPNamespaceURI(TElXMLSOAPHeaderBlockHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeaderBlock_Create(const sb_char16_t * pcASOAPNamespaceURI, int32_t szASOAPNamespaceURI, TElXMLSOAPHeaderBlockHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPHEADERBLOCK */

#ifdef SB_USE_CLASS_TELXMLSOAPHEADER
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeader_Clear(TElXMLSOAPHeaderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeader_ReloadBlocks(TElXMLSOAPHeaderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeader_LoadFromXML(TElXMLSOAPHeaderHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeader_LoadBlockFromXML(TElXMLSOAPHeaderHandle _Handle, TElXMLDOMElementHandle Element, TElXMLSOAPHeaderBlockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeader_get_BlockCount(TElXMLSOAPHeaderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeader_get_Blocks(TElXMLSOAPHeaderHandle _Handle, int32_t Index, TElXMLSOAPHeaderBlockHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeader_Create(TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, TElXMLSOAPHeaderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeader_Create_1(TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, const sb_char16_t * pcAName, int32_t szAName, TElXMLSOAPHeaderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeader_Create_2(TElXMLDOMElementHandle ParentElement, TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, TElXMLSOAPHeaderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPHeader_Create_3(TElXMLDOMElementHandle ParentElement, TElXMLDOMElementHandle BeforeChild, TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, const sb_char16_t * pcAName, int32_t szAName, TElXMLSOAPHeaderHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPHEADER */

#ifdef SB_USE_CLASS_TELXMLSOAPBODYENTRY
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBodyEntry_LoadFromXML(TElXMLSOAPBodyEntryHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBodyEntry_SaveToXML(TElXMLSOAPBodyEntryHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBodyEntry_get_EncodingStyle(TElXMLSOAPBodyEntryHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBodyEntry_set_EncodingStyle(TElXMLSOAPBodyEntryHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBodyEntry_get_NamespaceURI(TElXMLSOAPBodyEntryHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBodyEntry_Create(const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, TElXMLSOAPBodyEntryHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPBODYENTRY */

#ifdef SB_USE_CLASS_TELXMLSOAPBODY
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBody_Clear(TElXMLSOAPBodyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBody_ReloadEntries(TElXMLSOAPBodyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBody_LoadFromXML(TElXMLSOAPBodyHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBody_get_EntryCount(TElXMLSOAPBodyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBody_get_Entries(TElXMLSOAPBodyHandle _Handle, int32_t Index, TElXMLSOAPBodyEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBody_Create(TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, TElXMLSOAPBodyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBody_Create_1(TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, const sb_char16_t * pcAName, int32_t szAName, TElXMLSOAPBodyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBody_Create_2(TElXMLDOMElementHandle ParentElement, TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, TElXMLSOAPBodyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPBody_Create_3(TElXMLDOMElementHandle ParentElement, TElXMLDOMElementHandle BeforeChild, TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, const sb_char16_t * pcAName, int32_t szAName, TElXMLSOAPBodyHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPBODY */

#ifdef SB_USE_CLASS_TELXMLSOAPENVELOPE
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPEnvelope_Clear(TElXMLSOAPEnvelopeHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPEnvelope_LoadFromXML(TElXMLSOAPEnvelopeHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPEnvelope_CreateHeader(TElXMLSOAPEnvelopeHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPEnvelope_CreateBody(TElXMLSOAPEnvelopeHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPEnvelope_get_Header(TElXMLSOAPEnvelopeHandle _Handle, TElXMLSOAPHeaderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPEnvelope_get_Body(TElXMLSOAPEnvelopeHandle _Handle, TElXMLSOAPBodyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPEnvelope_Create(TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, TElXMLSOAPEnvelopeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPEnvelope_Create_1(TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, const sb_char16_t * pcAName, int32_t szAName, TElXMLSOAPEnvelopeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPEnvelope_Create_2(TElXMLDOMElementHandle ParentElement, TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, TElXMLSOAPEnvelopeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPEnvelope_Create_3(TElXMLDOMElementHandle ParentElement, TElXMLDOMElementHandle BeforeChild, TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, const sb_char16_t * pcAName, int32_t szAName, TElXMLSOAPEnvelopeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPEnvelope_Create_4(TElXMLDOMDocumentHandle Document, TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, TElXMLSOAPEnvelopeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLSOAPEnvelope_Create_5(TElXMLDOMDocumentHandle Document, TSBXMLSOAPVersionRaw AVersion, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, const sb_char16_t * pcAName, int32_t szAName, TElXMLSOAPEnvelopeHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSOAPENVELOPE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElXMLSOAPElement;
class TElXMLSOAPHeaderBlock;
class TElXMLSOAPHeader;
class TElXMLSOAPBodyEntry;
class TElXMLSOAPBody;
class TElXMLSOAPEnvelope;

#ifdef SB_USE_CLASS_TELXMLSOAPELEMENT
class TElXMLSOAPElement: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPElement)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual TSBXMLSOAPVersion get_SOAPVersion();

		SB_DECLARE_PROPERTY_GET(TSBXMLSOAPVersion, get_SOAPVersion, TElXMLSOAPElement, SOAPVersion);

		virtual void get_NamespaceURI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_NamespaceURI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		TElXMLSOAPElement(TElXMLSOAPElementHandle handle, TElOwnHandle ownHandle);

		TElXMLSOAPElement(TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI);

#ifdef SB_U16STRING_USED
		TElXMLSOAPElement(TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI);

#endif /* SB_U16STRING_USED */
		TElXMLSOAPElement(TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSOAPElement(TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLSOAPElement(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI);

		TElXMLSOAPElement(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI);

#ifdef SB_U16STRING_USED
		TElXMLSOAPElement(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI);

		TElXMLSOAPElement(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLSOAPElement(TElXMLDOMElement &ParentElement, TElXMLDOMElement &BeforeChild, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName);

		TElXMLSOAPElement(TElXMLDOMElement *ParentElement, TElXMLDOMElement *BeforeChild, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSOAPElement(TElXMLDOMElement &ParentElement, TElXMLDOMElement &BeforeChild, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName);

		TElXMLSOAPElement(TElXMLDOMElement *ParentElement, TElXMLDOMElement *BeforeChild, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
};
#endif /* SB_USE_CLASS_TELXMLSOAPELEMENT */

#ifdef SB_USE_CLASS_TELXMLSOAPHEADERBLOCK
class TElXMLSOAPHeaderBlock: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPHeaderBlock)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_Actor(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Actor(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Actor(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Actor(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_EncodingStyle(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_EncodingStyle(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_EncodingStyle(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_EncodingStyle(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_Role(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Role(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Role(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Role(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_MustUnderstand(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_MustUnderstand(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_MustUnderstand(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_MustUnderstand(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_Relay(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Relay(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Relay(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Relay(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_SOAPNamespaceURI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_SOAPNamespaceURI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		TElXMLSOAPHeaderBlock(TElXMLSOAPHeaderBlockHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLSOAPHeaderBlock(const sb_u16string &ASOAPNamespaceURI);

#ifdef SB_U16STRING_USED
		explicit TElXMLSOAPHeaderBlock(const std::wstring &ASOAPNamespaceURI);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELXMLSOAPHEADERBLOCK */

#ifdef SB_USE_CLASS_TELXMLSOAPHEADER
class TElXMLSOAPHeader: public TElXMLSOAPElement
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPHeader)
#ifdef SB_USE_CLASS_TELXMLSOAPHEADERBLOCK
		TElXMLSOAPHeaderBlock* _Inst_Blocks;
#endif /* SB_USE_CLASS_TELXMLSOAPHEADERBLOCK */

		void initInstances();

	public:
		virtual void Clear();

		void ReloadBlocks();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLSOAPHEADERBLOCK
		TElXMLSOAPHeaderBlockHandle LoadBlockFromXML(TElXMLDOMElement &Element);

		TElXMLSOAPHeaderBlockHandle LoadBlockFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASSES_TELXMLDOMELEMENT_AND_TELXMLSOAPHEADERBLOCK */

		virtual int32_t get_BlockCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_BlockCount, TElXMLSOAPHeader, BlockCount);

#ifdef SB_USE_CLASS_TELXMLSOAPHEADERBLOCK
		virtual TElXMLSOAPHeaderBlock* get_Blocks(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLSOAPHEADERBLOCK */

		TElXMLSOAPHeader(TElXMLSOAPHeaderHandle handle, TElOwnHandle ownHandle);

		TElXMLSOAPHeader(TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI);

#ifdef SB_U16STRING_USED
		TElXMLSOAPHeader(TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI);

#endif /* SB_U16STRING_USED */
		TElXMLSOAPHeader(TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSOAPHeader(TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLSOAPHeader(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI);

		TElXMLSOAPHeader(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI);

#ifdef SB_U16STRING_USED
		TElXMLSOAPHeader(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI);

		TElXMLSOAPHeader(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLSOAPHeader(TElXMLDOMElement &ParentElement, TElXMLDOMElement &BeforeChild, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName);

		TElXMLSOAPHeader(TElXMLDOMElement *ParentElement, TElXMLDOMElement *BeforeChild, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSOAPHeader(TElXMLDOMElement &ParentElement, TElXMLDOMElement &BeforeChild, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName);

		TElXMLSOAPHeader(TElXMLDOMElement *ParentElement, TElXMLDOMElement *BeforeChild, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
		virtual ~TElXMLSOAPHeader();

};
#endif /* SB_USE_CLASS_TELXMLSOAPHEADER */

#ifdef SB_USE_CLASS_TELXMLSOAPBODYENTRY
class TElXMLSOAPBodyEntry: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPBodyEntry)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_EncodingStyle(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_EncodingStyle(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_EncodingStyle(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_EncodingStyle(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_NamespaceURI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_NamespaceURI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		TElXMLSOAPBodyEntry(TElXMLSOAPBodyEntryHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLSOAPBodyEntry(const sb_u16string &ANamespaceURI);

#ifdef SB_U16STRING_USED
		explicit TElXMLSOAPBodyEntry(const std::wstring &ANamespaceURI);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELXMLSOAPBODYENTRY */

#ifdef SB_USE_CLASS_TELXMLSOAPBODY
class TElXMLSOAPBody: public TElXMLSOAPElement
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPBody)
#ifdef SB_USE_CLASS_TELXMLSOAPBODYENTRY
		TElXMLSOAPBodyEntry* _Inst_Entries;
#endif /* SB_USE_CLASS_TELXMLSOAPBODYENTRY */

		void initInstances();

	public:
		virtual void Clear();

		void ReloadEntries();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual int32_t get_EntryCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_EntryCount, TElXMLSOAPBody, EntryCount);

#ifdef SB_USE_CLASS_TELXMLSOAPBODYENTRY
		virtual TElXMLSOAPBodyEntry* get_Entries(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLSOAPBODYENTRY */

		TElXMLSOAPBody(TElXMLSOAPBodyHandle handle, TElOwnHandle ownHandle);

		TElXMLSOAPBody(TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI);

#ifdef SB_U16STRING_USED
		TElXMLSOAPBody(TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI);

#endif /* SB_U16STRING_USED */
		TElXMLSOAPBody(TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSOAPBody(TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLSOAPBody(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI);

		TElXMLSOAPBody(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI);

#ifdef SB_U16STRING_USED
		TElXMLSOAPBody(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI);

		TElXMLSOAPBody(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLSOAPBody(TElXMLDOMElement &ParentElement, TElXMLDOMElement &BeforeChild, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName);

		TElXMLSOAPBody(TElXMLDOMElement *ParentElement, TElXMLDOMElement *BeforeChild, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSOAPBody(TElXMLDOMElement &ParentElement, TElXMLDOMElement &BeforeChild, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName);

		TElXMLSOAPBody(TElXMLDOMElement *ParentElement, TElXMLDOMElement *BeforeChild, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
		virtual ~TElXMLSOAPBody();

};
#endif /* SB_USE_CLASS_TELXMLSOAPBODY */

#ifdef SB_USE_CLASS_TELXMLSOAPENVELOPE
class TElXMLSOAPEnvelope: public TElXMLSOAPElement
{
	private:
		SB_DISABLE_COPY(TElXMLSOAPEnvelope)
#ifdef SB_USE_CLASS_TELXMLSOAPHEADER
		TElXMLSOAPHeader* _Inst_Header;
#endif /* SB_USE_CLASS_TELXMLSOAPHEADER */
#ifdef SB_USE_CLASS_TELXMLSOAPBODY
		TElXMLSOAPBody* _Inst_Body;
#endif /* SB_USE_CLASS_TELXMLSOAPBODY */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		void CreateHeader();

		void CreateBody();

#ifdef SB_USE_CLASS_TELXMLSOAPHEADER
		virtual TElXMLSOAPHeader* get_Header();

		SB_DECLARE_PROPERTY_GET(TElXMLSOAPHeader*, get_Header, TElXMLSOAPEnvelope, Header);
#endif /* SB_USE_CLASS_TELXMLSOAPHEADER */

#ifdef SB_USE_CLASS_TELXMLSOAPBODY
		virtual TElXMLSOAPBody* get_Body();

		SB_DECLARE_PROPERTY_GET(TElXMLSOAPBody*, get_Body, TElXMLSOAPEnvelope, Body);
#endif /* SB_USE_CLASS_TELXMLSOAPBODY */

		TElXMLSOAPEnvelope(TElXMLSOAPEnvelopeHandle handle, TElOwnHandle ownHandle);

		TElXMLSOAPEnvelope(TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI);

#ifdef SB_U16STRING_USED
		TElXMLSOAPEnvelope(TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI);

#endif /* SB_U16STRING_USED */
		TElXMLSOAPEnvelope(TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSOAPEnvelope(TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLSOAPEnvelope(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI);

		TElXMLSOAPEnvelope(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI);

#ifdef SB_U16STRING_USED
		TElXMLSOAPEnvelope(TElXMLDOMElement &ParentElement, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI);

		TElXMLSOAPEnvelope(TElXMLDOMElement *ParentElement, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLSOAPEnvelope(TElXMLDOMElement &ParentElement, TElXMLDOMElement &BeforeChild, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName);

		TElXMLSOAPEnvelope(TElXMLDOMElement *ParentElement, TElXMLDOMElement *BeforeChild, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSOAPEnvelope(TElXMLDOMElement &ParentElement, TElXMLDOMElement &BeforeChild, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName);

		TElXMLSOAPEnvelope(TElXMLDOMElement *ParentElement, TElXMLDOMElement *BeforeChild, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		TElXMLSOAPEnvelope(TElXMLDOMDocument &Document, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI);

		TElXMLSOAPEnvelope(TElXMLDOMDocument *Document, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI);

#ifdef SB_U16STRING_USED
		TElXMLSOAPEnvelope(TElXMLDOMDocument &Document, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI);

		TElXMLSOAPEnvelope(TElXMLDOMDocument *Document, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		TElXMLSOAPEnvelope(TElXMLDOMDocument &Document, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName);

		TElXMLSOAPEnvelope(TElXMLDOMDocument *Document, TSBXMLSOAPVersion AVersion, const sb_u16string &ANamespaceURI, const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		TElXMLSOAPEnvelope(TElXMLDOMDocument &Document, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName);

		TElXMLSOAPEnvelope(TElXMLDOMDocument *Document, TSBXMLSOAPVersion AVersion, const std::wstring &ANamespaceURI, const std::wstring &AName);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */
		virtual ~TElXMLSOAPEnvelope();

};
#endif /* SB_USE_CLASS_TELXMLSOAPENVELOPE */

#ifdef SB_USE_GLOBAL_PROCS_XMLSOAPCORE

void GetSOAPNamespaceURI(TSBXMLSOAPVersion Version, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void GetSOAPNamespaceURI(TSBXMLSOAPVersion Version, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
void SOAPSecGetElementId(TElXMLDOMElement &Element, sb_u16string &OutResult);
void SOAPSecGetElementId(TElXMLDOMElement *Element, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void SOAPSecGetElementId(TElXMLDOMElement &Element, std::wstring &OutResult);
void SOAPSecGetElementId(TElXMLDOMElement *Element, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
void SOAPSecSetElementId(TElXMLDOMElement &Element, const sb_u16string &Value);
void SOAPSecSetElementId(TElXMLDOMElement *Element, const sb_u16string &Value);
#ifdef SB_U16STRING_USED
void SOAPSecSetElementId(TElXMLDOMElement &Element, const std::wstring &Value);
void SOAPSecSetElementId(TElXMLDOMElement *Element, const std::wstring &Value);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#endif /* SB_USE_GLOBAL_PROCS_XMLSOAPCORE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_XMLSOAPCORE
SB_IMPORT uint32_t SB_APIENTRY SBXMLSOAPCore_GetSOAPNamespaceURI(TSBXMLSOAPVersionRaw Version, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSOAPCore_SOAPSecGetElementId(TElXMLDOMElementHandle Element, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSOAPCore_SOAPSecSetElementId(TElXMLDOMElementHandle Element, const sb_char16_t * pcValue, int32_t szValue);
#endif /* SB_USE_GLOBAL_PROCS_XMLSOAPCORE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBXMLSOAPCORE */

