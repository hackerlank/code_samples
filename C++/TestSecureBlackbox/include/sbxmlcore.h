#ifndef __INC_SBXMLCORE
#define __INC_SBXMLCORE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbstreams.h"
#include "sbxmldefs.h"
#include "sbxmlcharsets.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ntElement 	1
#define SB_ntAttribute 	2
#define SB_ntText 	3
#define SB_ntCDataSection 	4
#define SB_ntEntityReference 	5
#define SB_ntEntity 	6
#define SB_ntProcessingInstruction 	7
#define SB_ntComment 	8
#define SB_ntDocument 	9
#define SB_ntDocumentType 	10
#define SB_ntDocumentFragment 	11
#define SB_ntNotation 	12

typedef TElClassHandle TElXMLDOMImplementationHandle;

typedef TElXMLDOMImplementationHandle ElXMLDOMImplementationHandle;

typedef TElClassHandle TElXMLDOMDocumentFragmentHandle;

typedef TElXMLDOMDocumentFragmentHandle ElXMLDOMDocumentFragmentHandle;

typedef TElClassHandle TElXMLDOMDocumentHandle;

typedef TElXMLDOMDocumentHandle ElXMLDOMDocumentHandle;

typedef TElClassHandle TElXMLDOMNodeHandle;

typedef TElXMLDOMNodeHandle ElXMLDOMNodeHandle;

typedef TElClassHandle TElXMLNodeSetHandle;

typedef TElXMLNodeSetHandle ElXMLNodeSetHandle;

typedef TElClassHandle TElXMLDOMNodeListHandle;

typedef TElXMLDOMNodeListHandle ElXMLDOMNodeListHandle;

typedef TElClassHandle TElXMLDOMNamedNodeMapHandle;

typedef TElXMLDOMNamedNodeMapHandle ElXMLDOMNamedNodeMapHandle;

typedef TElClassHandle TElXMLDOMCharacterDataHandle;

typedef TElXMLDOMCharacterDataHandle ElXMLDOMCharacterDataHandle;

typedef TElClassHandle TElXMLDOMAttrHandle;

typedef TElXMLDOMAttrHandle ElXMLDOMAttrHandle;

typedef TElClassHandle TElXMLDOMElementHandle;

typedef TElXMLDOMElementHandle ElXMLDOMElementHandle;

typedef TElClassHandle TElXMLDOMTextHandle;

typedef TElXMLDOMTextHandle ElXMLDOMTextHandle;

typedef TElClassHandle TElXMLDOMCommentHandle;

typedef TElXMLDOMCommentHandle ElXMLDOMCommentHandle;

typedef TElClassHandle TElXMLDOMCDATASectionHandle;

typedef TElXMLDOMCDATASectionHandle ElXMLDOMCDATASectionHandle;

typedef TElClassHandle TElXMLDOMDocumentTypeHandle;

typedef TElXMLDOMDocumentTypeHandle ElXMLDOMDocumentTypeHandle;

typedef TElClassHandle TElXMLDOMNotationHandle;

typedef TElXMLDOMNotationHandle ElXMLDOMNotationHandle;

typedef TElClassHandle TElXMLDOMEntityHandle;

typedef TElXMLDOMEntityHandle ElXMLDOMEntityHandle;

typedef TElClassHandle TElXMLDOMEntityReferenceHandle;

typedef TElXMLDOMEntityReferenceHandle ElXMLDOMEntityReferenceHandle;

typedef TElClassHandle TElXMLDOMProcessingInstructionHandle;

typedef TElXMLDOMProcessingInstructionHandle ElXMLDOMProcessingInstructionHandle;

typedef TElClassHandle TElXMLParserHandle;

typedef TElXMLParserHandle ElXMLParserHandle;

typedef TElClassHandle TElXMLNamespaceMapHandle;

typedef TElXMLNamespaceMapHandle ElXMLNamespaceMapHandle;

typedef TElClassHandle TElXMLCustomFormatterHandle;

typedef TElXMLCustomFormatterHandle ElXMLCustomFormatterHandle;

typedef TElClassHandle TElXMLCustomElementHandle;

typedef TElXMLCustomElementHandle ElXMLCustomElementHandle;

typedef uint8_t TElXMLDelayLoadModeTypeRaw;

typedef enum
{
	dlmCDATA = 0,
	dlmComment = 1,
	dlmText = 2
} TElXMLDelayLoadModeType;

typedef uint32_t TElXMLDelayLoadModeRaw;

typedef enum 
{
	f_dlmCDATA = 1,
	f_dlmComment = 2,
	f_dlmText = 4
} TElXMLDelayLoadMode;

typedef void (SB_CALLBACK *TElXMLValidationFunc)(sb_char16_t c, int8_t * OutResult);

#ifdef SB_USE_CLASS_TELXMLDOMIMPLEMENTATION
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMImplementation_HasFeature(TElXMLDOMImplementationHandle _Handle, const sb_char16_t * pcFeature, int32_t szFeature, const sb_char16_t * pcVersion, int32_t szVersion, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMImplementation_CreateDocumentType(TElXMLDOMImplementationHandle _Handle, const sb_char16_t * pcQualifiedName, int32_t szQualifiedName, const sb_char16_t * pcPublicID, int32_t szPublicID, const sb_char16_t * pcSystemID, int32_t szSystemID, TElXMLDOMDocumentTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMImplementation_CreateDocumentType_1(TElXMLDOMImplementationHandle _Handle, const sb_char16_t * pcQualifiedName, int32_t szQualifiedName, const sb_char16_t * pcPublicID, int32_t szPublicID, const sb_char16_t * pcSystemID, int32_t szSystemID, const sb_char16_t * pcInternalSubset, int32_t szInternalSubset, TElXMLDOMDocumentTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMImplementation_CreateDocument(TElXMLDOMImplementationHandle _Handle, const sb_char16_t * pcNamespaceURI, int32_t szNamespaceURI, const sb_char16_t * pcQualifiedName, int32_t szQualifiedName, TElXMLDOMDocumentTypeHandle DocType, TElXMLDOMDocumentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMImplementation_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMIMPLEMENTATION */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_ReloadData(TElXMLDOMNodeHandle _Handle, TElXMLDelayLoadModeRaw LoadedData, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_UnloadData(TElXMLDOMNodeHandle _Handle, TElXMLDelayLoadModeRaw DataToUnload);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_GetOuterXMLCanonical(TElXMLDOMNodeHandle _Handle, TElXMLCanonicalizationMethodRaw aMethod, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_GetOuterXMLCanonical_1(TElXMLDOMNodeHandle _Handle, TElXMLCanonicalizationMethodRaw aMethod, const sb_char16_t * pcInclNSPrefixList, int32_t szInclNSPrefixList, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_SelectNodes(TElXMLDOMNodeHandle _Handle, const sb_char16_t * pcXPath, int32_t szXPath, TElXMLNodeSetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_SelectNodes_1(TElXMLDOMNodeHandle _Handle, const sb_char16_t * pcXPath, int32_t szXPath, TElXMLNamespaceMapHandle NSMap, TElXMLNodeSetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_InsertBefore(TElXMLDOMNodeHandle _Handle, TElXMLDOMNodeHandle NewChild, TElXMLDOMNodeHandle RefChild, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_ReplaceChild(TElXMLDOMNodeHandle _Handle, TElXMLDOMNodeHandle NewChild, TElXMLDOMNodeHandle OldChild, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_RemoveChild(TElXMLDOMNodeHandle _Handle, TElXMLDOMNodeHandle OldChild);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_AppendChild(TElXMLDOMNodeHandle _Handle, TElXMLDOMNodeHandle NewChild, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_AppendChild_1(TElXMLDOMNodeHandle _Handle, TElXMLDOMNodeHandle NewChild, int8_t DisablePrefixUpdate, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_HasChildNodes(TElXMLDOMNodeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_CloneNode(TElXMLDOMNodeHandle _Handle, int8_t Deep, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_CloneNode_1(TElXMLDOMNodeHandle _Handle, int8_t Deep, TElXMLDOMDocumentHandle aCloneOwner, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_Normalize(TElXMLDOMNodeHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_HasAttributes(TElXMLDOMNodeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_isSupported(TElXMLDOMNodeHandle _Handle, const sb_char16_t * pcFeature, int32_t szFeature, const sb_char16_t * pcVersion, int32_t szVersion, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_FindNode(TElXMLDOMNodeHandle _Handle, const sb_char16_t * pcaNodeName, int32_t szaNodeName, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_FindNode_1(TElXMLDOMNodeHandle _Handle, const sb_char16_t * pcaNodeName, int32_t szaNodeName, int8_t Deep, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_get_RelativeIndex(TElXMLDOMNodeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_get_NodeName(TElXMLDOMNodeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_get_NodeValue(TElXMLDOMNodeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_set_NodeValue(TElXMLDOMNodeHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_get_NodeType(TElXMLDOMNodeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_get_ParentNode(TElXMLDOMNodeHandle _Handle, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_get_FirstChild(TElXMLDOMNodeHandle _Handle, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_get_LastChild(TElXMLDOMNodeHandle _Handle, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_get_ChildNodes(TElXMLDOMNodeHandle _Handle, TElXMLDOMNodeListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_get_PreviousSibling(TElXMLDOMNodeHandle _Handle, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_get_NextSibling(TElXMLDOMNodeHandle _Handle, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_get_Attributes(TElXMLDOMNodeHandle _Handle, TElXMLDOMNamedNodeMapHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_get_OwnerDocument(TElXMLDOMNodeHandle _Handle, TElXMLDOMDocumentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_get_RawData(TElXMLDOMNodeHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_get_RawDataLength(TElXMLDOMNodeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_get_Loaded(TElXMLDOMNodeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_get_OuterXML(TElXMLDOMNodeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_get_NamespaceURI(TElXMLDOMNodeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_get_LocalName(TElXMLDOMNodeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_get_Prefix(TElXMLDOMNodeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNode_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_LoadFromStream(TElXMLDOMDocumentHandle _Handle, TStreamHandle aStream);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_LoadFromStream_1(TElXMLDOMDocumentHandle _Handle, TStreamHandle aStream, const char * pcDefaultEncoding, int32_t szDefaultEncoding, int8_t NormalizeNEL);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_LoadFromStream_2(TElXMLDOMDocumentHandle _Handle, TStreamHandle aStream, int8_t OwnStream, TElXMLDelayLoadModeRaw DataToLoad);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_LoadFromStream_3(TElXMLDOMDocumentHandle _Handle, TStreamHandle aStream, int8_t OwnStream, TElXMLDelayLoadModeRaw DataToLoad, const char * pcDefaultEncoding, int32_t szDefaultEncoding, int8_t NormalizeNEL);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_SaveToStream(TElXMLDOMDocumentHandle _Handle, TStreamHandle aStream);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_SaveToStream_1(TElXMLDOMDocumentHandle _Handle, TStreamHandle aStream, TElXMLCanonicalizationMethodRaw aMethod, TElXMLCodecHandle aEncoding);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_SaveToStream_2(TElXMLDOMDocumentHandle _Handle, TStreamHandle aStream, TElXMLCanonicalizationMethodRaw aMethod, const char * pcaCharset, int32_t szaCharset);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_LoadFromFile(TElXMLDOMDocumentHandle _Handle, const char * pcaFileName, int32_t szaFileName);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_LoadFromFile_1(TElXMLDOMDocumentHandle _Handle, const char * pcaFileName, int32_t szaFileName, const char * pcDefaultEncoding, int32_t szDefaultEncoding, int8_t NormalizeNEL);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_LoadFromFile_2(TElXMLDOMDocumentHandle _Handle, const char * pcaFileName, int32_t szaFileName, TElXMLDelayLoadModeRaw DataToLoad);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_LoadFromFile_3(TElXMLDOMDocumentHandle _Handle, const char * pcaFileName, int32_t szaFileName, TElXMLDelayLoadModeRaw DataToLoad, const char * pcDefaultEncoding, int32_t szDefaultEncoding, int8_t NormalizeNEL);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_SaveToFile(TElXMLDOMDocumentHandle _Handle, const char * pcaFileName, int32_t szaFileName);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_SaveToFile_1(TElXMLDOMDocumentHandle _Handle, const char * pcaFileName, int32_t szaFileName, TElXMLCanonicalizationMethodRaw aMethod);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_ReloadAll(TElXMLDOMDocumentHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_LookupEntityByRef(TElXMLDOMDocumentHandle _Handle, const sb_char16_t * pcaRef, int32_t szaRef, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_CreateElement(TElXMLDOMDocumentHandle _Handle, const sb_char16_t * pcTagName, int32_t szTagName, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_CreateDocumentFragment(TElXMLDOMDocumentHandle _Handle, TElXMLDOMDocumentFragmentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_CreateTextNode(TElXMLDOMDocumentHandle _Handle, const sb_char16_t * pcData, int32_t szData, TElXMLDOMTextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_CreateComment(TElXMLDOMDocumentHandle _Handle, const sb_char16_t * pcData, int32_t szData, TElXMLDOMCommentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_CreateAttribute(TElXMLDOMDocumentHandle _Handle, const sb_char16_t * pcName, int32_t szName, TElXMLDOMAttrHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_GetElementsByTagName(TElXMLDOMDocumentHandle _Handle, const sb_char16_t * pcTagName, int32_t szTagName, TElXMLDOMNodeListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_ImportNode(TElXMLDOMDocumentHandle _Handle, const TElXMLDOMNodeHandle aNode, int8_t Deep, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_CreateElementNS(TElXMLDOMDocumentHandle _Handle, const sb_char16_t * pcaNSURI, int32_t szaNSURI, const sb_char16_t * pcaName, int32_t szaName, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_CreateAttributeNS(TElXMLDOMDocumentHandle _Handle, const sb_char16_t * pcaNSURi, int32_t szaNSURi, const sb_char16_t * pcaName, int32_t szaName, TElXMLDOMAttrHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_GetElementsByTagNameNS(TElXMLDOMDocumentHandle _Handle, const sb_char16_t * pcaNSURi, int32_t szaNSURi, const sb_char16_t * pcaName, int32_t szaName, TElXMLDOMNodeListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_GetElementByID(TElXMLDOMDocumentHandle _Handle, const sb_char16_t * pcaElementID, int32_t szaElementID, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_CreateEntity(TElXMLDOMDocumentHandle _Handle, const sb_char16_t * pcData, int32_t szData, TElXMLDOMEntityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_CreateCDATASection(TElXMLDOMDocumentHandle _Handle, const sb_char16_t * pcData, int32_t szData, TElXMLDOMCDATASectionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_CreateProcessingInstruction(TElXMLDOMDocumentHandle _Handle, const sb_char16_t * pcTarget, int32_t szTarget, const sb_char16_t * pcData, int32_t szData, TElXMLDOMProcessingInstructionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_CreateEntityReference(TElXMLDOMDocumentHandle _Handle, const sb_char16_t * pcName, int32_t szName, TElXMLDOMEntityReferenceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_get_DocumentType(TElXMLDOMDocumentHandle _Handle, TElXMLDOMDocumentTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_get_Impl(TElXMLDOMDocumentHandle _Handle, TElXMLDOMImplementationHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_get_DocumentElement(TElXMLDOMDocumentHandle _Handle, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_get_XmlNS(TElXMLDOMDocumentHandle _Handle, TElXMLDOMAttrHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_get_OriginalEncoding(TElXMLDOMDocumentHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_get_Version(TElXMLDOMDocumentHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_set_Version(TElXMLDOMDocumentHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocument_Create(TElXMLDOMDocumentHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENTFRAGMENT
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocumentFragment_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENTFRAGMENT */

#ifdef SB_USE_CLASS_TELXMLNODESET
SB_IMPORT uint32_t SB_APIENTRY TElXMLNodeSet_Add(TElXMLNodeSetHandle _Handle, TElXMLDOMNodeHandle ANode, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNodeSet_Insert(TElXMLNodeSetHandle _Handle, int32_t Index, TElXMLDOMNodeHandle ANode);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNodeSet_Delete(TElXMLNodeSetHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNodeSet_Clear(TElXMLNodeSetHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNodeSet_HasNode(TElXMLNodeSetHandle _Handle, TElXMLDOMNodeHandle Node, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNodeSet_IndexOf(TElXMLNodeSetHandle _Handle, TElXMLDOMNodeHandle Node, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNodeSet_get_Count(TElXMLNodeSetHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNodeSet_get_Node(TElXMLNodeSetHandle _Handle, int32_t Index, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNodeSet_get_OwnNodes(TElXMLNodeSetHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNodeSet_set_OwnNodes(TElXMLNodeSetHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNodeSet_Create(int8_t AOwnNodes, TElXMLNodeSetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNodeSet_Create_1(TElXMLDOMNodeListHandle NodeList, TElXMLNodeSetHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLNODESET */

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNodeList_get_Item(TElXMLDOMNodeListHandle _Handle, int32_t index, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNodeList_get_Length(TElXMLDOMNodeListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNodeList_Create(TElXMLDOMNodeHandle aNode, int8_t aOwnNode, TElXMLDOMNodeListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNodeList_Create_1(TElXMLDOMNodeHandle aNode, const sb_char16_t * pcaFilter, int32_t szaFilter, int8_t aOwnNode, TElXMLDOMNodeListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNodeList_Create_2(TElXMLDOMNodeHandle aNode, const sb_char16_t * pcaNSURI, int32_t szaNSURI, const sb_char16_t * pcaFilter, int32_t szaFilter, int8_t aOwnNode, TElXMLDOMNodeListHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

#ifdef SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNamedNodeMap_Clear(TElXMLDOMNamedNodeMapHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNamedNodeMap_GetNamedItem(TElXMLDOMNamedNodeMapHandle _Handle, const sb_char16_t * pcName, int32_t szName, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNamedNodeMap_SetNamedItem(TElXMLDOMNamedNodeMapHandle _Handle, TElXMLDOMNodeHandle arg, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNamedNodeMap_RemoveNamedItem(TElXMLDOMNamedNodeMapHandle _Handle, const sb_char16_t * pcName, int32_t szName, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNamedNodeMap_GetNamedItemNS(TElXMLDOMNamedNodeMapHandle _Handle, const sb_char16_t * pcaNSURI, int32_t szaNSURI, const sb_char16_t * pcaName, int32_t szaName, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNamedNodeMap_SetNamedItemNS(TElXMLDOMNamedNodeMapHandle _Handle, TElXMLDOMNodeHandle arg, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNamedNodeMap_RemoveNamedItemNS(TElXMLDOMNamedNodeMapHandle _Handle, const sb_char16_t * pcaNSURI, int32_t szaNSURI, const sb_char16_t * pcaName, int32_t szaName, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNamedNodeMap_get_Item(TElXMLDOMNamedNodeMapHandle _Handle, int32_t index, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNamedNodeMap_set_Item(TElXMLDOMNamedNodeMapHandle _Handle, int32_t index, TElXMLDOMNodeHandle aItem);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNamedNodeMap_get_Length(TElXMLDOMNamedNodeMapHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNamedNodeMap_Create(TListHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP */

#ifdef SB_USE_CLASS_TELXMLDOMCHARACTERDATA
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMCharacterData_UnloadData(TElXMLDOMCharacterDataHandle _Handle, TElXMLDelayLoadModeRaw DataToUnload);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMCharacterData_SubstringData(TElXMLDOMCharacterDataHandle _Handle, int32_t ofs, int32_t len, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMCharacterData_AppendData(TElXMLDOMCharacterDataHandle _Handle, const sb_char16_t * pcarg, int32_t szarg);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMCharacterData_InsertData(TElXMLDOMCharacterDataHandle _Handle, int32_t ofs, const sb_char16_t * pcarg, int32_t szarg);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMCharacterData_DeleteData(TElXMLDOMCharacterDataHandle _Handle, int32_t ofs, int32_t len);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMCharacterData_ReplaceData(TElXMLDOMCharacterDataHandle _Handle, int32_t ofs, int32_t len, const sb_char16_t * pcarg, int32_t szarg);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMCharacterData_get_Data(TElXMLDOMCharacterDataHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMCharacterData_get_Length(TElXMLDOMCharacterDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMCharacterData_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMCHARACTERDATA */

#ifdef SB_USE_CLASS_TELXMLDOMATTR
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMAttr_CloneNode(TElXMLDOMAttrHandle _Handle, int8_t Deep, TElXMLDOMDocumentHandle aCloneOwner, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMAttr_get_Quote(TElXMLDOMAttrHandle _Handle, sb_char16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMAttr_set_Quote(TElXMLDOMAttrHandle _Handle, sb_char16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMAttr_get_Value(TElXMLDOMAttrHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMAttr_set_Value(TElXMLDOMAttrHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMAttr_get_OwnerElement(TElXMLDOMAttrHandle _Handle, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMAttr_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_CloneNode(TElXMLDOMElementHandle _Handle, int8_t Deep, TElXMLDOMDocumentHandle aCloneOwner, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_RemoveAttribute(TElXMLDOMElementHandle _Handle, const sb_char16_t * pcaName, int32_t szaName);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_GetAttributeNode(TElXMLDOMElementHandle _Handle, const sb_char16_t * pcaName, int32_t szaName, TElXMLDOMAttrHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_SetAttributeNode(TElXMLDOMElementHandle _Handle, TElXMLDOMAttrHandle aNewAttr, TElXMLDOMAttrHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_RemoveAttributeNode(TElXMLDOMElementHandle _Handle, TElXMLDOMAttrHandle aOldAttr, TElXMLDOMAttrHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_GetElementsByTagName(TElXMLDOMElementHandle _Handle, const sb_char16_t * pcaName, int32_t szaName, TElXMLDOMNodeListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_HasAttributes(TElXMLDOMElementHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_GetOuterXMLCanonical(TElXMLDOMElementHandle _Handle, TElXMLCanonicalizationMethodRaw aMethod, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_GetOuterXMLCanonical_1(TElXMLDOMElementHandle _Handle, TElXMLCanonicalizationMethodRaw aMethod, const sb_char16_t * pcInclNSPrefixList, int32_t szInclNSPrefixList, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_GetOuterXMLCanonical_2(TElXMLDOMElementHandle _Handle, TElXMLCanonicalizationMethodRaw aMethod, TElXMLDOMNodeHandle ReferenceNode, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_GetOuterXMLCanonical_3(TElXMLDOMElementHandle _Handle, TElXMLCanonicalizationMethodRaw aMethod, const sb_char16_t * pcInclNSPrefixList, int32_t szInclNSPrefixList, TElXMLDOMNodeHandle ReferenceNode, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_InnerText(TElXMLDOMElementHandle _Handle, const sb_char16_t * pcSeparator, int32_t szSeparator, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_GetAttribute(TElXMLDOMElementHandle _Handle, const sb_char16_t * pcaName, int32_t szaName, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_SetAttribute(TElXMLDOMElementHandle _Handle, const sb_char16_t * pcaName, int32_t szaName, const sb_char16_t * pcaValue, int32_t szaValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_GetAttributeNS(TElXMLDOMElementHandle _Handle, const sb_char16_t * pcaNSURI, int32_t szaNSURI, const sb_char16_t * pcaName, int32_t szaName, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_SetAttributeNS(TElXMLDOMElementHandle _Handle, const sb_char16_t * pcaNSURI, int32_t szaNSURI, const sb_char16_t * pcaName, int32_t szaName, const sb_char16_t * pcaValue, int32_t szaValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_RemoveAttributeNS(TElXMLDOMElementHandle _Handle, const sb_char16_t * pcaNSURI, int32_t szaNSURI, const sb_char16_t * pcaName, int32_t szaName);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_GetAttributeNodeNS(TElXMLDOMElementHandle _Handle, const sb_char16_t * pcaNSURI, int32_t szaNSURI, const sb_char16_t * pcaName, int32_t szaName, TElXMLDOMAttrHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_SetAttributeNodeNS(TElXMLDOMElementHandle _Handle, TElXMLDOMAttrHandle aNewAttr, TElXMLDOMAttrHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_GetElementsByTagNameNS(TElXMLDOMElementHandle _Handle, const sb_char16_t * pcaNSURI, int32_t szaNSURI, const sb_char16_t * pcaName, int32_t szaName, TElXMLDOMNodeListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_HasAttribute(TElXMLDOMElementHandle _Handle, const sb_char16_t * pcaName, int32_t szaName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_HasAttributeNS(TElXMLDOMElementHandle _Handle, const sb_char16_t * pcaNSURI, int32_t szaNSURI, const sb_char16_t * pcaName, int32_t szaName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_GetCurrentNSURI(TElXMLDOMElementHandle _Handle, const sb_char16_t * pcs, int32_t szs, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_get_TextContent(TElXMLDOMElementHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_set_TextContent(TElXMLDOMElementHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_get_InnerXML(TElXMLDOMElementHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_set_InnerXML(TElXMLDOMElementHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_get_AttribStrings(TElXMLDOMElementHandle _Handle, const sb_char16_t * pcaName, int32_t szaName, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_set_AttribStrings(TElXMLDOMElementHandle _Handle, const sb_char16_t * pcaName, int32_t szaName, const sb_char16_t * pcaValue, int32_t szaValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMElement_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMTEXT
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMText_CloneNode(TElXMLDOMTextHandle _Handle, int8_t Deep, TElXMLDOMDocumentHandle aCloneOwner, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMText_SplitText(TElXMLDOMTextHandle _Handle, int32_t ofs, TElXMLDOMTextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMText_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMTEXT */

#ifdef SB_USE_CLASS_TELXMLDOMCOMMENT
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMComment_CloneNode(TElXMLDOMCommentHandle _Handle, int8_t Deep, TElXMLDOMDocumentHandle aCloneOwner, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMComment_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMCOMMENT */

#ifdef SB_USE_CLASS_TELXMLDOMCDATASECTION
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMCDATASection_CloneNode(TElXMLDOMCDATASectionHandle _Handle, int8_t Deep, TElXMLDOMDocumentHandle aCloneOwner, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMCDATASection_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMCDATASECTION */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocumentType_CloneNode(TElXMLDOMDocumentTypeHandle _Handle, int8_t Deep, TElXMLDOMDocumentHandle aCloneOwner, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocumentType_ResolveExternalDTD(TElXMLDOMDocumentTypeHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocumentType_get_Name(TElXMLDOMDocumentTypeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocumentType_get_Entities(TElXMLDOMDocumentTypeHandle _Handle, TElXMLDOMNamedNodeMapHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocumentType_get_Notations(TElXMLDOMDocumentTypeHandle _Handle, TElXMLDOMNamedNodeMapHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocumentType_get_PublicID(TElXMLDOMDocumentTypeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocumentType_get_SystemID(TElXMLDOMDocumentTypeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocumentType_get_InternalSubset(TElXMLDOMDocumentTypeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMDocumentType_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE */

#ifdef SB_USE_CLASS_TELXMLDOMNOTATION
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNotation_CloneNode(TElXMLDOMNotationHandle _Handle, int8_t Deep, TElXMLDOMDocumentHandle aCloneOwner, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNotation_get_PublicID(TElXMLDOMNotationHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNotation_get_SystemID(TElXMLDOMNotationHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMNotation_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMNOTATION */

#ifdef SB_USE_CLASS_TELXMLDOMENTITY
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMEntity_CloneNode(TElXMLDOMEntityHandle _Handle, int8_t Deep, TElXMLDOMDocumentHandle aCloneOwner, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMEntity_get_PublicID(TElXMLDOMEntityHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMEntity_get_SystemID(TElXMLDOMEntityHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMEntity_get_NotationName(TElXMLDOMEntityHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMEntity_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMENTITY */

#ifdef SB_USE_CLASS_TELXMLDOMENTITYREFERENCE
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMEntityReference_CloneNode(TElXMLDOMEntityReferenceHandle _Handle, int8_t Deep, TElXMLDOMDocumentHandle aCloneOwner, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMEntityReference_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMENTITYREFERENCE */

#ifdef SB_USE_CLASS_TELXMLDOMPROCESSINGINSTRUCTION
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMProcessingInstruction_CloneNode(TElXMLDOMProcessingInstructionHandle _Handle, int8_t Deep, TElXMLDOMDocumentHandle aCloneOwner, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMProcessingInstruction_get_Target(TElXMLDOMProcessingInstructionHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMProcessingInstruction_get_Data(TElXMLDOMProcessingInstructionHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDOMProcessingInstruction_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMPROCESSINGINSTRUCTION */

#ifdef SB_USE_CLASS_TELXMLPARSER
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_RaiseExc(TElXMLParserHandle _Handle, const char * pcaMsg, int32_t szaMsg);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_InitStream(TElXMLParserHandle _Handle, const char * pcDefaultEncoding, int32_t szDefaultEncoding);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_bufInit(TElXMLParserHandle _Handle, sb_char16_t * pcaArg, int32_t * szaArg);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_bufAddChar(TElXMLParserHandle _Handle, sb_char16_t * pcaArg, int32_t * szaArg, sb_char16_t c);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_bufFlush(TElXMLParserHandle _Handle, sb_char16_t * pcaArg, int32_t * szaArg);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_bufFree(TElXMLParserHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_sEOF(TElXMLParserHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_NextChar(TElXMLParserHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_PushData(TElXMLParserHandle _Handle, const sb_char16_t * pcData, int32_t szData);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_PushData_1(TElXMLParserHandle _Handle, const sb_char16_t * pcData, int32_t szData, const sb_char16_t * pcMarker, int32_t szMarker, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_Write(TElXMLParserHandle _Handle, const sb_char16_t * pcaArg, int32_t szaArg);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_Write_1(TElXMLParserHandle _Handle, sb_char16_t c);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_SkipBlank(TElXMLParserHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_ExpectBlank(TElXMLParserHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_ExpectString(TElXMLParserHandle _Handle, const sb_char16_t * pcaArg, int32_t szaArg);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_UntilString(TElXMLParserHandle _Handle, const sb_char16_t * pcaArg, int32_t szaArg, int8_t LeaveString, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_UntilStringSkip(TElXMLParserHandle _Handle, const sb_char16_t * pcaArg, int32_t szaArg);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_CheckForMulti(TElXMLParserHandle _Handle, const int32_t pExpect[], int32_t szExpect, int8_t Recall, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_CheckFor(TElXMLParserHandle _Handle, const sb_char16_t * pcaArg, int32_t szaArg, int8_t Recall, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_GetWhile(TElXMLParserHandle _Handle, void * aFunc, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_GetWhile_1(TElXMLParserHandle _Handle, int32_t aCharKind, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_GetUntil(TElXMLParserHandle _Handle, void * aFunc, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_GetUntil_1(TElXMLParserHandle _Handle, int32_t aCharKind, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_GetUntilSkip(TElXMLParserHandle _Handle, void * aFunc);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_GetUntilSkip_1(TElXMLParserHandle _Handle, int32_t aCharKind);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_GetNMtok(TElXMLParserHandle _Handle, sb_char16_t * pcaArg, int32_t * szaArg, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_get_sPos(TElXMLParserHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_set_sPos(TElXMLParserHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_get_LastPos(TElXMLParserHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_get_Last(TElXMLParserHandle _Handle, sb_char16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_get_NormalizeNEL(TElXMLParserHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_set_NormalizeNEL(TElXMLParserHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_get_OEnc(TElXMLParserHandle _Handle, TElXMLCodecHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_set_OEnc(TElXMLParserHandle _Handle, TElXMLCodecHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLParser_Create(TElXMLDOMDocumentHandle aDoc, int8_t DoInitStream, const char * pcDefaultEncoding, int32_t szDefaultEncoding, int8_t NormNEL, TElXMLParserHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLPARSER */

#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
SB_IMPORT uint32_t SB_APIENTRY TElXMLNamespaceMap_Clear(TElXMLNamespaceMapHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNamespaceMap_Add(TElXMLNamespaceMapHandle _Handle, TElXMLNamespaceMapHandle NSMap, int8_t OverwriteIfExists);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNamespaceMap_AddNamespace(TElXMLNamespaceMapHandle _Handle, const sb_char16_t * pcPrefix, int32_t szPrefix, const sb_char16_t * pcURI, int32_t szURI);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNamespaceMap_RemoveNamespace(TElXMLNamespaceMapHandle _Handle, const sb_char16_t * pcPrefix, int32_t szPrefix);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNamespaceMap_FindNamespace(TElXMLNamespaceMapHandle _Handle, const sb_char16_t * pcPrefix, int32_t szPrefix, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNamespaceMap_FindPrefix(TElXMLNamespaceMapHandle _Handle, const sb_char16_t * pcURI, int32_t szURI, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNamespaceMap_get_Count(TElXMLNamespaceMapHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNamespaceMap_get_Prefix(TElXMLNamespaceMapHandle _Handle, int32_t Index, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNamespaceMap_get_URI(TElXMLNamespaceMapHandle _Handle, int32_t Index, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLNamespaceMap_Create(TElXMLNamespaceMapHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */

#ifdef SB_USE_CLASS_TELXMLCUSTOMFORMATTER
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomFormatter_AppendElement(TElXMLCustomFormatterHandle _Handle, TElXMLDOMElementHandle Parent, TElXMLDOMElementHandle Child);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomFormatter_AppendElement_1(TElXMLCustomFormatterHandle _Handle, TElXMLDOMElementHandle Parent, TElXMLCustomElementHandle Child, TElXMLDOMDocumentHandle Document, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomFormatter_AppendElementWithText(TElXMLCustomFormatterHandle _Handle, TElXMLDOMElementHandle Parent, TElXMLDOMElementHandle Child, const sb_char16_t * pcChildText, int32_t szChildText, TElXMLTextTypeRaw ChildTextType);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomFormatter_AppendText(TElXMLCustomFormatterHandle _Handle, TElXMLDOMElementHandle Parent, const sb_char16_t * pcText, int32_t szText, TElXMLTextTypeRaw TextType);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomFormatter_InsertBefore(TElXMLCustomFormatterHandle _Handle, TElXMLDOMElementHandle Parent, TElXMLDOMNodeHandle ChildRef, TElXMLCustomElementHandle Child, TElXMLDOMDocumentHandle Document);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomFormatter_Clear(TElXMLCustomFormatterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomFormatter_Push(TElXMLCustomFormatterHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomFormatter_Pop(TElXMLCustomFormatterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomFormatter_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELXMLCUSTOMELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomElement_Clear(TElXMLCustomElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomElement_LoadFromXML(TElXMLCustomElementHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomElement_SaveToXML(TElXMLCustomElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomElement_SaveToXML_1(TElXMLCustomElementHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomElement_get_XMLElement(TElXMLCustomElementHandle _Handle, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomElement_set_XMLElement(TElXMLCustomElementHandle _Handle, TElXMLDOMElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCustomElement_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCUSTOMELEMENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElXMLDOMImplementation;
typedef TElXMLDOMImplementation ElXMLDOMImplementation;
class TElXMLDOMDocumentFragment;
typedef TElXMLDOMDocumentFragment ElXMLDOMDocumentFragment;
class TElXMLDOMDocument;
typedef TElXMLDOMDocument ElXMLDOMDocument;
class TElXMLDOMNode;
typedef TElXMLDOMNode ElXMLDOMNode;
class TElXMLNodeSet;
typedef TElXMLNodeSet ElXMLNodeSet;
class TElXMLDOMNodeList;
typedef TElXMLDOMNodeList ElXMLDOMNodeList;
class TElXMLDOMNamedNodeMap;
typedef TElXMLDOMNamedNodeMap ElXMLDOMNamedNodeMap;
class TElXMLDOMCharacterData;
typedef TElXMLDOMCharacterData ElXMLDOMCharacterData;
class TElXMLDOMAttr;
typedef TElXMLDOMAttr ElXMLDOMAttr;
class TElXMLDOMElement;
typedef TElXMLDOMElement ElXMLDOMElement;
class TElXMLDOMText;
typedef TElXMLDOMText ElXMLDOMText;
class TElXMLDOMComment;
typedef TElXMLDOMComment ElXMLDOMComment;
class TElXMLDOMCDATASection;
typedef TElXMLDOMCDATASection ElXMLDOMCDATASection;
class TElXMLDOMDocumentType;
typedef TElXMLDOMDocumentType ElXMLDOMDocumentType;
class TElXMLDOMNotation;
typedef TElXMLDOMNotation ElXMLDOMNotation;
class TElXMLDOMEntity;
typedef TElXMLDOMEntity ElXMLDOMEntity;
class TElXMLDOMEntityReference;
typedef TElXMLDOMEntityReference ElXMLDOMEntityReference;
class TElXMLDOMProcessingInstruction;
typedef TElXMLDOMProcessingInstruction ElXMLDOMProcessingInstruction;
class TElXMLParser;
typedef TElXMLParser ElXMLParser;
class TElXMLNamespaceMap;
typedef TElXMLNamespaceMap ElXMLNamespaceMap;
class TElXMLCustomFormatter;
typedef TElXMLCustomFormatter ElXMLCustomFormatter;
class TElXMLCustomElement;
typedef TElXMLCustomElement ElXMLCustomElement;

SB_DEFINE_ENUM_FLAG_OPERATORS(TElXMLDelayLoadMode)

#ifdef SB_USE_CLASS_TELXMLDOMIMPLEMENTATION
class TElXMLDOMImplementation: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLDOMImplementation)
	public:
		bool HasFeature(const sb_u16string &Feature, const sb_u16string &Version);
#ifdef SB_U16STRING_USED
		bool HasFeature(const std::wstring &Feature, const std::wstring &Version);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE
		TElXMLDOMDocumentTypeHandle CreateDocumentType(const sb_u16string &QualifiedName, const sb_u16string &PublicID, const sb_u16string &SystemID);
#ifdef SB_U16STRING_USED
		TElXMLDOMDocumentTypeHandle CreateDocumentType(const std::wstring &QualifiedName, const std::wstring &PublicID, const std::wstring &SystemID);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE
		TElXMLDOMDocumentTypeHandle CreateDocumentType(const sb_u16string &QualifiedName, const sb_u16string &PublicID, const sb_u16string &SystemID, const sb_u16string &InternalSubset);
#ifdef SB_U16STRING_USED
		TElXMLDOMDocumentTypeHandle CreateDocumentType(const std::wstring &QualifiedName, const std::wstring &PublicID, const std::wstring &SystemID, const std::wstring &InternalSubset);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE */

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMDOCUMENTTYPE
		TElXMLDOMDocumentHandle CreateDocument(const sb_u16string &NamespaceURI, const sb_u16string &QualifiedName, TElXMLDOMDocumentType &DocType);

		TElXMLDOMDocumentHandle CreateDocument(const sb_u16string &NamespaceURI, const sb_u16string &QualifiedName, TElXMLDOMDocumentType *DocType);
#ifdef SB_U16STRING_USED
		TElXMLDOMDocumentHandle CreateDocument(const std::wstring &NamespaceURI, const std::wstring &QualifiedName, TElXMLDOMDocumentType &DocType);

		TElXMLDOMDocumentHandle CreateDocument(const std::wstring &NamespaceURI, const std::wstring &QualifiedName, TElXMLDOMDocumentType *DocType);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMDOCUMENTTYPE */

		TElXMLDOMImplementation(TElXMLDOMImplementationHandle handle, TElOwnHandle ownHandle);

		TElXMLDOMImplementation();

};
#endif /* SB_USE_CLASS_TELXMLDOMIMPLEMENTATION */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
class TElXMLDOMNode: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLDOMNode)
		TElXMLDOMNode* _Inst_ParentNode;
		TElXMLDOMNode* _Inst_FirstChild;
		TElXMLDOMNode* _Inst_LastChild;
#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
		TElXMLDOMNodeList* _Inst_ChildNodes;
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */
		TElXMLDOMNode* _Inst_PreviousSibling;
		TElXMLDOMNode* _Inst_NextSibling;
#ifdef SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP
		TElXMLDOMNamedNodeMap* _Inst_Attributes;
#endif /* SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP */
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		TElXMLDOMDocument* _Inst_OwnerDocument;
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

		void initInstances();

	public:
		bool ReloadData(TElXMLDelayLoadMode LoadedData);

		virtual void UnloadData(TElXMLDelayLoadMode DataToUnload);

		virtual void GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		virtual void GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual void GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, const sb_u16string &InclNSPrefixList, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		virtual void GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, const std::wstring &InclNSPrefixList, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLNODESET
		TElXMLNodeSetHandle SelectNodes(const sb_u16string &XPath);
#ifdef SB_U16STRING_USED
		TElXMLNodeSetHandle SelectNodes(const std::wstring &XPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLNODESET */

#ifdef SB_USE_CLASSES_TELXMLNAMESPACEMAP_AND_TELXMLNODESET
		TElXMLNodeSetHandle SelectNodes(const sb_u16string &XPath, TElXMLNamespaceMap &NSMap);

		TElXMLNodeSetHandle SelectNodes(const sb_u16string &XPath, TElXMLNamespaceMap *NSMap);
#ifdef SB_U16STRING_USED
		TElXMLNodeSetHandle SelectNodes(const std::wstring &XPath, TElXMLNamespaceMap &NSMap);

		TElXMLNodeSetHandle SelectNodes(const std::wstring &XPath, TElXMLNamespaceMap *NSMap);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELXMLNAMESPACEMAP_AND_TELXMLNODESET */

		virtual TElXMLDOMNodeHandle InsertBefore(TElXMLDOMNode &NewChild, TElXMLDOMNode &RefChild);

		virtual TElXMLDOMNodeHandle InsertBefore(TElXMLDOMNode *NewChild, TElXMLDOMNode *RefChild);

		virtual TElXMLDOMNodeHandle ReplaceChild(TElXMLDOMNode &NewChild, TElXMLDOMNode &OldChild);

		virtual TElXMLDOMNodeHandle ReplaceChild(TElXMLDOMNode *NewChild, TElXMLDOMNode *OldChild);

		virtual void RemoveChild(TElXMLDOMNode &OldChild);

		virtual void RemoveChild(TElXMLDOMNode *OldChild);

		virtual TElXMLDOMNodeHandle AppendChild(TElXMLDOMNode &NewChild);

		virtual TElXMLDOMNodeHandle AppendChild(TElXMLDOMNode *NewChild);

		TElXMLDOMNodeHandle AppendChild(TElXMLDOMNode &NewChild, bool DisablePrefixUpdate);

		TElXMLDOMNodeHandle AppendChild(TElXMLDOMNode *NewChild, bool DisablePrefixUpdate);

		virtual bool HasChildNodes();

		TElXMLDOMNodeHandle CloneNode(bool Deep);

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner);

		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

		void Normalize();

		virtual bool HasAttributes();

		virtual bool isSupported(const sb_u16string &Feature, const sb_u16string &Version);
#ifdef SB_U16STRING_USED
		virtual bool isSupported(const std::wstring &Feature, const std::wstring &Version);
#endif /* SB_U16STRING_USED */

		TElXMLDOMNodeHandle FindNode(const sb_u16string &aNodeName);
#ifdef SB_U16STRING_USED
		TElXMLDOMNodeHandle FindNode(const std::wstring &aNodeName);
#endif /* SB_U16STRING_USED */

		TElXMLDOMNodeHandle FindNode(const sb_u16string &aNodeName, bool Deep);
#ifdef SB_U16STRING_USED
		TElXMLDOMNodeHandle FindNode(const std::wstring &aNodeName, bool Deep);
#endif /* SB_U16STRING_USED */

		virtual int32_t get_RelativeIndex();

		SB_DECLARE_PROPERTY_GET(int32_t, get_RelativeIndex, TElXMLDOMNode, RelativeIndex);

		virtual void get_NodeName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_NodeName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_NodeValue(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_NodeValue(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_NodeValue(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_NodeValue(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual int32_t get_NodeType();

		SB_DECLARE_PROPERTY_GET(int32_t, get_NodeType, TElXMLDOMNode, NodeType);

		virtual TElXMLDOMNode* get_ParentNode();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMNode*, get_ParentNode, TElXMLDOMNode, ParentNode);

		virtual TElXMLDOMNode* get_FirstChild();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMNode*, get_FirstChild, TElXMLDOMNode, FirstChild);

		virtual TElXMLDOMNode* get_LastChild();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMNode*, get_LastChild, TElXMLDOMNode, LastChild);

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
		virtual TElXMLDOMNodeList* get_ChildNodes();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMNodeList*, get_ChildNodes, TElXMLDOMNode, ChildNodes);
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

		virtual TElXMLDOMNode* get_PreviousSibling();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMNode*, get_PreviousSibling, TElXMLDOMNode, PreviousSibling);

		virtual TElXMLDOMNode* get_NextSibling();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMNode*, get_NextSibling, TElXMLDOMNode, NextSibling);

#ifdef SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP
		virtual TElXMLDOMNamedNodeMap* get_Attributes();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMNamedNodeMap*, get_Attributes, TElXMLDOMNode, Attributes);
#endif /* SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual TElXMLDOMDocument* get_OwnerDocument();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMDocument*, get_OwnerDocument, TElXMLDOMNode, OwnerDocument);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

		virtual void get_RawData(std::vector<uint8_t> &OutResult);

		virtual int32_t get_RawDataLength();

		SB_DECLARE_PROPERTY_GET(int32_t, get_RawDataLength, TElXMLDOMNode, RawDataLength);

		virtual bool get_Loaded();

		SB_DECLARE_PROPERTY_GET(bool, get_Loaded, TElXMLDOMNode, Loaded);

		virtual void get_OuterXML(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_OuterXML(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_NamespaceURI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_NamespaceURI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_LocalName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_LocalName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_Prefix(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Prefix(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		TElXMLDOMNode(TElXMLDOMNodeHandle handle, TElOwnHandle ownHandle);

		TElXMLDOMNode();

		virtual ~TElXMLDOMNode();

};
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
class TElXMLDOMDocument: public TElXMLDOMNode
{
	private:
		SB_DISABLE_COPY(TElXMLDOMDocument)
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE
		TElXMLDOMDocumentType* _Inst_DocumentType;
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE */
#ifdef SB_USE_CLASS_TELXMLDOMIMPLEMENTATION
		TElXMLDOMImplementation* _Inst_Impl;
#endif /* SB_USE_CLASS_TELXMLDOMIMPLEMENTATION */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLDOMElement* _Inst_DocumentElement;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELXMLDOMATTR
		TElXMLDOMAttr* _Inst_XmlNS;
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromStream(TStream &aStream);

		void LoadFromStream(TStream *aStream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromStream(TStream &aStream, const std::string &DefaultEncoding, bool NormalizeNEL);

		void LoadFromStream(TStream *aStream, const std::string &DefaultEncoding, bool NormalizeNEL);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromStream(TStream &aStream, bool OwnStream, TElXMLDelayLoadMode DataToLoad);

		void LoadFromStream(TStream *aStream, bool OwnStream, TElXMLDelayLoadMode DataToLoad);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromStream(TStream &aStream, bool OwnStream, TElXMLDelayLoadMode DataToLoad, const std::string &DefaultEncoding, bool NormalizeNEL);

		void LoadFromStream(TStream *aStream, bool OwnStream, TElXMLDelayLoadMode DataToLoad, const std::string &DefaultEncoding, bool NormalizeNEL);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToStream(TStream &aStream);

		void SaveToStream(TStream *aStream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELXMLCODEC_AND_TSTREAM
		void SaveToStream(TStream &aStream, TElXMLCanonicalizationMethod aMethod, TElXMLCodec &aEncoding);

		void SaveToStream(TStream *aStream, TElXMLCanonicalizationMethod aMethod, TElXMLCodec *aEncoding);
#endif /* SB_USE_CLASSES_TELXMLCODEC_AND_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToStream(TStream &aStream, TElXMLCanonicalizationMethod aMethod, const std::string &aCharset);

		void SaveToStream(TStream *aStream, TElXMLCanonicalizationMethod aMethod, const std::string &aCharset);
#endif /* SB_USE_CLASS_TSTREAM */

		void LoadFromFile(const std::string &aFileName);

		void LoadFromFile(const std::string &aFileName, const std::string &DefaultEncoding, bool NormalizeNEL);

		void LoadFromFile(const std::string &aFileName, TElXMLDelayLoadMode DataToLoad);

		void LoadFromFile(const std::string &aFileName, TElXMLDelayLoadMode DataToLoad, const std::string &DefaultEncoding, bool NormalizeNEL);

		void SaveToFile(const std::string &aFileName);

		void SaveToFile(const std::string &aFileName, TElXMLCanonicalizationMethod aMethod);

		void ReloadAll();

		void LookupEntityByRef(const sb_u16string &aRef, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void LookupEntityByRef(const std::wstring &aRef, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle CreateElement(const sb_u16string &TagName);
#ifdef SB_U16STRING_USED
		virtual TElXMLDOMElementHandle CreateElement(const std::wstring &TagName);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENTFRAGMENT
		TElXMLDOMDocumentFragmentHandle CreateDocumentFragment();
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENTFRAGMENT */

#ifdef SB_USE_CLASS_TELXMLDOMTEXT
		TElXMLDOMTextHandle CreateTextNode(const sb_u16string &Data);
#ifdef SB_U16STRING_USED
		TElXMLDOMTextHandle CreateTextNode(const std::wstring &Data);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMTEXT */

#ifdef SB_USE_CLASS_TELXMLDOMCOMMENT
		TElXMLDOMCommentHandle CreateComment(const sb_u16string &Data);
#ifdef SB_U16STRING_USED
		TElXMLDOMCommentHandle CreateComment(const std::wstring &Data);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMCOMMENT */

#ifdef SB_USE_CLASS_TELXMLDOMATTR
		virtual TElXMLDOMAttrHandle CreateAttribute(const sb_u16string &Name);
#ifdef SB_U16STRING_USED
		virtual TElXMLDOMAttrHandle CreateAttribute(const std::wstring &Name);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
		TElXMLDOMNodeListHandle GetElementsByTagName(const sb_u16string &TagName);
#ifdef SB_U16STRING_USED
		TElXMLDOMNodeListHandle GetElementsByTagName(const std::wstring &TagName);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

		TElXMLDOMNodeHandle ImportNode(const TElXMLDOMNode &aNode, bool Deep);

		TElXMLDOMNodeHandle ImportNode(const TElXMLDOMNode *aNode, bool Deep);

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle CreateElementNS(const sb_u16string &aNSURI, const sb_u16string &aName);
#ifdef SB_U16STRING_USED
		virtual TElXMLDOMElementHandle CreateElementNS(const std::wstring &aNSURI, const std::wstring &aName);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMATTR
		virtual TElXMLDOMAttrHandle CreateAttributeNS(const sb_u16string &aNSURi, const sb_u16string &aName);
#ifdef SB_U16STRING_USED
		virtual TElXMLDOMAttrHandle CreateAttributeNS(const std::wstring &aNSURi, const std::wstring &aName);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
		TElXMLDOMNodeListHandle GetElementsByTagNameNS(const sb_u16string &aNSURi, const sb_u16string &aName);
#ifdef SB_U16STRING_USED
		TElXMLDOMNodeListHandle GetElementsByTagNameNS(const std::wstring &aNSURi, const std::wstring &aName);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLDOMElementHandle GetElementByID(const sb_u16string &aElementID);
#ifdef SB_U16STRING_USED
		TElXMLDOMElementHandle GetElementByID(const std::wstring &aElementID);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMENTITY
		TElXMLDOMEntityHandle CreateEntity(const sb_u16string &Data);
#ifdef SB_U16STRING_USED
		TElXMLDOMEntityHandle CreateEntity(const std::wstring &Data);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMENTITY */

#ifdef SB_USE_CLASS_TELXMLDOMCDATASECTION
		virtual TElXMLDOMCDATASectionHandle CreateCDATASection(const sb_u16string &Data);
#ifdef SB_U16STRING_USED
		virtual TElXMLDOMCDATASectionHandle CreateCDATASection(const std::wstring &Data);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMCDATASECTION */

#ifdef SB_USE_CLASS_TELXMLDOMPROCESSINGINSTRUCTION
		virtual TElXMLDOMProcessingInstructionHandle CreateProcessingInstruction(const sb_u16string &Target, const sb_u16string &Data);
#ifdef SB_U16STRING_USED
		virtual TElXMLDOMProcessingInstructionHandle CreateProcessingInstruction(const std::wstring &Target, const std::wstring &Data);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMPROCESSINGINSTRUCTION */

#ifdef SB_USE_CLASS_TELXMLDOMENTITYREFERENCE
		virtual TElXMLDOMEntityReferenceHandle CreateEntityReference(const sb_u16string &Name);
#ifdef SB_U16STRING_USED
		virtual TElXMLDOMEntityReferenceHandle CreateEntityReference(const std::wstring &Name);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMENTITYREFERENCE */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE
		virtual TElXMLDOMDocumentType* get_DocumentType();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMDocumentType*, get_DocumentType, TElXMLDOMDocument, DocumentType);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE */

#ifdef SB_USE_CLASS_TELXMLDOMIMPLEMENTATION
		virtual TElXMLDOMImplementation* get_Impl();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMImplementation*, get_Impl, TElXMLDOMDocument, Impl);
#endif /* SB_USE_CLASS_TELXMLDOMIMPLEMENTATION */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLDOMElement* get_DocumentElement();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMElement*, get_DocumentElement, TElXMLDOMDocument, DocumentElement);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMATTR
		virtual TElXMLDOMAttr* get_XmlNS();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMAttr*, get_XmlNS, TElXMLDOMDocument, XmlNS);
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

		virtual void get_OriginalEncoding(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_OriginalEncoding(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_Version(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Version(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Version(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Version(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLDOMDocument(TElXMLDOMDocumentHandle handle, TElOwnHandle ownHandle);

		TElXMLDOMDocument();

		virtual ~TElXMLDOMDocument();

};
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENTFRAGMENT
class TElXMLDOMDocumentFragment: public TElXMLDOMNode
{
	private:
		SB_DISABLE_COPY(TElXMLDOMDocumentFragment)
	public:
		TElXMLDOMDocumentFragment(TElXMLDOMDocumentFragmentHandle handle, TElOwnHandle ownHandle);

		TElXMLDOMDocumentFragment();

};
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENTFRAGMENT */

#ifdef SB_USE_CLASS_TELXMLNODESET
class TElXMLNodeSet: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLNodeSet)
#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNode* _Inst_Node;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMNODE
		int32_t Add(TElXMLDOMNode &ANode);

		int32_t Add(TElXMLDOMNode *ANode);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		void Insert(int32_t Index, TElXMLDOMNode &ANode);

		void Insert(int32_t Index, TElXMLDOMNode *ANode);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		void Delete(int32_t Index);

		void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		bool HasNode(TElXMLDOMNode &Node);

		bool HasNode(TElXMLDOMNode *Node);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		int32_t IndexOf(TElXMLDOMNode &Node);

		int32_t IndexOf(TElXMLDOMNode *Node);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLNodeSet, Count);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TElXMLDOMNode* get_Node(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		virtual bool get_OwnNodes();

		virtual void set_OwnNodes(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OwnNodes, set_OwnNodes, TElXMLNodeSet, OwnNodes);

		TElXMLNodeSet(TElXMLNodeSetHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLNodeSet(bool AOwnNodes);

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
		explicit TElXMLNodeSet(TElXMLDOMNodeList &NodeList);

		explicit TElXMLNodeSet(TElXMLDOMNodeList *NodeList);
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

		virtual ~TElXMLNodeSet();

};
#endif /* SB_USE_CLASS_TELXMLNODESET */

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
class TElXMLDOMNodeList: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLDOMNodeList)
#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNode* _Inst_Item;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TElXMLDOMNode* get_Item(int32_t index);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		virtual int32_t get_Length();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Length, TElXMLDOMNodeList, Length);

		TElXMLDOMNodeList(TElXMLDOMNodeListHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNodeList(TElXMLDOMNode &aNode, bool aOwnNode);

		TElXMLDOMNodeList(TElXMLDOMNode *aNode, bool aOwnNode);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNodeList(TElXMLDOMNode &aNode, const sb_u16string &aFilter, bool aOwnNode);

		TElXMLDOMNodeList(TElXMLDOMNode *aNode, const sb_u16string &aFilter, bool aOwnNode);

#ifdef SB_U16STRING_USED
		TElXMLDOMNodeList(TElXMLDOMNode &aNode, const std::wstring &aFilter, bool aOwnNode);

		TElXMLDOMNodeList(TElXMLDOMNode *aNode, const std::wstring &aFilter, bool aOwnNode);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNodeList(TElXMLDOMNode &aNode, const sb_u16string &aNSURI, const sb_u16string &aFilter, bool aOwnNode);

		TElXMLDOMNodeList(TElXMLDOMNode *aNode, const sb_u16string &aNSURI, const sb_u16string &aFilter, bool aOwnNode);

#ifdef SB_U16STRING_USED
		TElXMLDOMNodeList(TElXMLDOMNode &aNode, const std::wstring &aNSURI, const std::wstring &aFilter, bool aOwnNode);

		TElXMLDOMNodeList(TElXMLDOMNode *aNode, const std::wstring &aNSURI, const std::wstring &aFilter, bool aOwnNode);

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
		virtual ~TElXMLDOMNodeList();

};
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

#ifdef SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP
class TElXMLDOMNamedNodeMap: public TList
{
	private:
		SB_DISABLE_COPY(TElXMLDOMNamedNodeMap)
#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNode* _Inst_Item;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNodeHandle GetNamedItem(const sb_u16string &Name);
#ifdef SB_U16STRING_USED
		TElXMLDOMNodeHandle GetNamedItem(const std::wstring &Name);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNodeHandle SetNamedItem(TElXMLDOMNode &arg);

		TElXMLDOMNodeHandle SetNamedItem(TElXMLDOMNode *arg);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNodeHandle RemoveNamedItem(const sb_u16string &Name);
#ifdef SB_U16STRING_USED
		TElXMLDOMNodeHandle RemoveNamedItem(const std::wstring &Name);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNodeHandle GetNamedItemNS(const sb_u16string &aNSURI, const sb_u16string &aName);
#ifdef SB_U16STRING_USED
		TElXMLDOMNodeHandle GetNamedItemNS(const std::wstring &aNSURI, const std::wstring &aName);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNodeHandle SetNamedItemNS(TElXMLDOMNode &arg);

		TElXMLDOMNodeHandle SetNamedItemNS(TElXMLDOMNode *arg);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNodeHandle RemoveNamedItemNS(const sb_u16string &aNSURI, const sb_u16string &aName);
#ifdef SB_U16STRING_USED
		TElXMLDOMNodeHandle RemoveNamedItemNS(const std::wstring &aNSURI, const std::wstring &aName);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TElXMLDOMNode* get_Item(int32_t index);

		virtual void set_Item(int32_t index, TElXMLDOMNode &aItem);

		virtual void set_Item(int32_t index, TElXMLDOMNode *aItem);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		virtual int32_t get_Length();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Length, TElXMLDOMNamedNodeMap, Length);

		TElXMLDOMNamedNodeMap(TElXMLDOMNamedNodeMapHandle handle, TElOwnHandle ownHandle);

		TElXMLDOMNamedNodeMap();

		virtual ~TElXMLDOMNamedNodeMap();

};
#endif /* SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP */

#ifdef SB_USE_CLASS_TELXMLDOMCHARACTERDATA
class TElXMLDOMCharacterData: public TElXMLDOMNode
{
	private:
		SB_DISABLE_COPY(TElXMLDOMCharacterData)
	public:
		virtual void UnloadData(TElXMLDelayLoadMode DataToUnload);

		void SubstringData(int32_t ofs, int32_t len, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void SubstringData(int32_t ofs, int32_t len, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		void AppendData(const sb_u16string &arg);
#ifdef SB_U16STRING_USED
		void AppendData(const std::wstring &arg);
#endif /* SB_U16STRING_USED */

		void InsertData(int32_t ofs, const sb_u16string &arg);
#ifdef SB_U16STRING_USED
		void InsertData(int32_t ofs, const std::wstring &arg);
#endif /* SB_U16STRING_USED */

		void DeleteData(int32_t ofs, int32_t len);

		void ReplaceData(int32_t ofs, int32_t len, const sb_u16string &arg);
#ifdef SB_U16STRING_USED
		void ReplaceData(int32_t ofs, int32_t len, const std::wstring &arg);
#endif /* SB_U16STRING_USED */

		virtual void get_Data(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Data(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual int32_t get_Length();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Length, TElXMLDOMCharacterData, Length);

		TElXMLDOMCharacterData(TElXMLDOMCharacterDataHandle handle, TElOwnHandle ownHandle);

		TElXMLDOMCharacterData();

};
#endif /* SB_USE_CLASS_TELXMLDOMCHARACTERDATA */

#ifdef SB_USE_CLASS_TELXMLDOMATTR
class TElXMLDOMAttr: public TElXMLDOMNode
{
	private:
		SB_DISABLE_COPY(TElXMLDOMAttr)
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLDOMElement* _Inst_OwnerElement;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner);

		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

		virtual sb_char16_t get_Quote();

		virtual void set_Quote(sb_char16_t Value);

		SB_DECLARE_PROPERTY(sb_char16_t, get_Quote, set_Quote, TElXMLDOMAttr, Quote);

		virtual void get_Value(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Value(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Value(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Value(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLDOMElement* get_OwnerElement();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMElement*, get_OwnerElement, TElXMLDOMAttr, OwnerElement);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		TElXMLDOMAttr(TElXMLDOMAttrHandle handle, TElOwnHandle ownHandle);

		TElXMLDOMAttr();

		virtual ~TElXMLDOMAttr();

};
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
class TElXMLDOMElement: public TElXMLDOMNode
{
	private:
		SB_DISABLE_COPY(TElXMLDOMElement)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner);

		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

		void RemoveAttribute(const sb_u16string &aName);
#ifdef SB_U16STRING_USED
		void RemoveAttribute(const std::wstring &aName);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLDOMATTR
		TElXMLDOMAttrHandle GetAttributeNode(const sb_u16string &aName);
#ifdef SB_U16STRING_USED
		TElXMLDOMAttrHandle GetAttributeNode(const std::wstring &aName);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

#ifdef SB_USE_CLASS_TELXMLDOMATTR
		TElXMLDOMAttrHandle SetAttributeNode(TElXMLDOMAttr &aNewAttr);

		TElXMLDOMAttrHandle SetAttributeNode(TElXMLDOMAttr *aNewAttr);
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

#ifdef SB_USE_CLASS_TELXMLDOMATTR
		TElXMLDOMAttrHandle RemoveAttributeNode(TElXMLDOMAttr &aOldAttr);

		TElXMLDOMAttrHandle RemoveAttributeNode(TElXMLDOMAttr *aOldAttr);
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
		TElXMLDOMNodeListHandle GetElementsByTagName(const sb_u16string &aName);
#ifdef SB_U16STRING_USED
		TElXMLDOMNodeListHandle GetElementsByTagName(const std::wstring &aName);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

		virtual bool HasAttributes();

		virtual void GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		virtual void GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual void GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, const sb_u16string &InclNSPrefixList, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		virtual void GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, const std::wstring &InclNSPrefixList, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		void GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, TElXMLDOMNode &ReferenceNode, sb_u16string &OutResult);

		void GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, TElXMLDOMNode *ReferenceNode, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, TElXMLDOMNode &ReferenceNode, std::wstring &OutResult);

		void GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, TElXMLDOMNode *ReferenceNode, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		void GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, const sb_u16string &InclNSPrefixList, TElXMLDOMNode &ReferenceNode, sb_u16string &OutResult);

		void GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, const sb_u16string &InclNSPrefixList, TElXMLDOMNode *ReferenceNode, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, const std::wstring &InclNSPrefixList, TElXMLDOMNode &ReferenceNode, std::wstring &OutResult);

		void GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, const std::wstring &InclNSPrefixList, TElXMLDOMNode *ReferenceNode, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		void InnerText(const sb_u16string &Separator, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void InnerText(const std::wstring &Separator, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		void GetAttribute(const sb_u16string &aName, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void GetAttribute(const std::wstring &aName, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		void SetAttribute(const sb_u16string &aName, const sb_u16string &aValue);
#ifdef SB_U16STRING_USED
		void SetAttribute(const std::wstring &aName, const std::wstring &aValue);
#endif /* SB_U16STRING_USED */

		void GetAttributeNS(const sb_u16string &aNSURI, const sb_u16string &aName, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void GetAttributeNS(const std::wstring &aNSURI, const std::wstring &aName, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		void SetAttributeNS(const sb_u16string &aNSURI, const sb_u16string &aName, const sb_u16string &aValue);
#ifdef SB_U16STRING_USED
		void SetAttributeNS(const std::wstring &aNSURI, const std::wstring &aName, const std::wstring &aValue);
#endif /* SB_U16STRING_USED */

		void RemoveAttributeNS(const sb_u16string &aNSURI, const sb_u16string &aName);
#ifdef SB_U16STRING_USED
		void RemoveAttributeNS(const std::wstring &aNSURI, const std::wstring &aName);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLDOMATTR
		TElXMLDOMAttrHandle GetAttributeNodeNS(const sb_u16string &aNSURI, const sb_u16string &aName);
#ifdef SB_U16STRING_USED
		TElXMLDOMAttrHandle GetAttributeNodeNS(const std::wstring &aNSURI, const std::wstring &aName);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

#ifdef SB_USE_CLASS_TELXMLDOMATTR
		TElXMLDOMAttrHandle SetAttributeNodeNS(TElXMLDOMAttr &aNewAttr);

		TElXMLDOMAttrHandle SetAttributeNodeNS(TElXMLDOMAttr *aNewAttr);
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
		TElXMLDOMNodeListHandle GetElementsByTagNameNS(const sb_u16string &aNSURI, const sb_u16string &aName);
#ifdef SB_U16STRING_USED
		TElXMLDOMNodeListHandle GetElementsByTagNameNS(const std::wstring &aNSURI, const std::wstring &aName);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

		bool HasAttribute(const sb_u16string &aName);
#ifdef SB_U16STRING_USED
		bool HasAttribute(const std::wstring &aName);
#endif /* SB_U16STRING_USED */

		bool HasAttributeNS(const sb_u16string &aNSURI, const sb_u16string &aName);
#ifdef SB_U16STRING_USED
		bool HasAttributeNS(const std::wstring &aNSURI, const std::wstring &aName);
#endif /* SB_U16STRING_USED */

		void GetCurrentNSURI(const sb_u16string &s, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void GetCurrentNSURI(const std::wstring &s, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual void get_TextContent(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_TextContent(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_TextContent(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_TextContent(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_InnerXML(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_InnerXML(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_InnerXML(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_InnerXML(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_AttribStrings(const sb_u16string &aName, sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_AttribStrings(const std::wstring &aName, std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_AttribStrings(const sb_u16string &aName, const sb_u16string &aValue);

#ifdef SB_U16STRING_USED
		virtual void set_AttribStrings(const std::wstring &aName, const std::wstring &aValue);

#endif /* SB_U16STRING_USED */
		TElXMLDOMElement(TElXMLDOMElementHandle handle, TElOwnHandle ownHandle);

		TElXMLDOMElement();

};
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMTEXT
class TElXMLDOMText: public TElXMLDOMCharacterData
{
	private:
		SB_DISABLE_COPY(TElXMLDOMText)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner);

		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

		TElXMLDOMTextHandle SplitText(int32_t ofs);

		TElXMLDOMText(TElXMLDOMTextHandle handle, TElOwnHandle ownHandle);

		TElXMLDOMText();

};
#endif /* SB_USE_CLASS_TELXMLDOMTEXT */

#ifdef SB_USE_CLASS_TELXMLDOMCOMMENT
class TElXMLDOMComment: public TElXMLDOMCharacterData
{
	private:
		SB_DISABLE_COPY(TElXMLDOMComment)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner);

		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

		TElXMLDOMComment(TElXMLDOMCommentHandle handle, TElOwnHandle ownHandle);

		TElXMLDOMComment();

};
#endif /* SB_USE_CLASS_TELXMLDOMCOMMENT */

#ifdef SB_USE_CLASS_TELXMLDOMCDATASECTION
class TElXMLDOMCDATASection: public TElXMLDOMText
{
	private:
		SB_DISABLE_COPY(TElXMLDOMCDATASection)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner);

		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

		TElXMLDOMCDATASection(TElXMLDOMCDATASectionHandle handle, TElOwnHandle ownHandle);

		TElXMLDOMCDATASection();

};
#endif /* SB_USE_CLASS_TELXMLDOMCDATASECTION */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE
class TElXMLDOMDocumentType: public TElXMLDOMNode
{
	private:
		SB_DISABLE_COPY(TElXMLDOMDocumentType)
#ifdef SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP
		TElXMLDOMNamedNodeMap* _Inst_Entities;
#endif /* SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP */
#ifdef SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP
		TElXMLDOMNamedNodeMap* _Inst_Notations;
#endif /* SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner);

		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

		void ResolveExternalDTD(const sb_u16string &Value);
#ifdef SB_U16STRING_USED
		void ResolveExternalDTD(const std::wstring &Value);
#endif /* SB_U16STRING_USED */

		virtual void get_Name(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Name(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP
		virtual TElXMLDOMNamedNodeMap* get_Entities();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMNamedNodeMap*, get_Entities, TElXMLDOMDocumentType, Entities);
#endif /* SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP */

#ifdef SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP
		virtual TElXMLDOMNamedNodeMap* get_Notations();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMNamedNodeMap*, get_Notations, TElXMLDOMDocumentType, Notations);
#endif /* SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP */

		virtual void get_PublicID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_PublicID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_SystemID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_SystemID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_InternalSubset(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_InternalSubset(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		TElXMLDOMDocumentType(TElXMLDOMDocumentTypeHandle handle, TElOwnHandle ownHandle);

		TElXMLDOMDocumentType();

		virtual ~TElXMLDOMDocumentType();

};
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE */

#ifdef SB_USE_CLASS_TELXMLDOMNOTATION
class TElXMLDOMNotation: public TElXMLDOMNode
{
	private:
		SB_DISABLE_COPY(TElXMLDOMNotation)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner);

		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

		virtual void get_PublicID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_PublicID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_SystemID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_SystemID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		TElXMLDOMNotation(TElXMLDOMNotationHandle handle, TElOwnHandle ownHandle);

		TElXMLDOMNotation();

};
#endif /* SB_USE_CLASS_TELXMLDOMNOTATION */

#ifdef SB_USE_CLASS_TELXMLDOMENTITY
class TElXMLDOMEntity: public TElXMLDOMNode
{
	private:
		SB_DISABLE_COPY(TElXMLDOMEntity)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner);

		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

		virtual void get_PublicID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_PublicID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_SystemID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_SystemID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_NotationName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_NotationName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		TElXMLDOMEntity(TElXMLDOMEntityHandle handle, TElOwnHandle ownHandle);

		TElXMLDOMEntity();

};
#endif /* SB_USE_CLASS_TELXMLDOMENTITY */

#ifdef SB_USE_CLASS_TELXMLDOMENTITYREFERENCE
class TElXMLDOMEntityReference: public TElXMLDOMNode
{
	private:
		SB_DISABLE_COPY(TElXMLDOMEntityReference)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner);

		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

		TElXMLDOMEntityReference(TElXMLDOMEntityReferenceHandle handle, TElOwnHandle ownHandle);

		TElXMLDOMEntityReference();

};
#endif /* SB_USE_CLASS_TELXMLDOMENTITYREFERENCE */

#ifdef SB_USE_CLASS_TELXMLDOMPROCESSINGINSTRUCTION
class TElXMLDOMProcessingInstruction: public TElXMLDOMNode
{
	private:
		SB_DISABLE_COPY(TElXMLDOMProcessingInstruction)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner);

		virtual TElXMLDOMNodeHandle CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

		virtual void get_Target(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Target(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_Data(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Data(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		TElXMLDOMProcessingInstruction(TElXMLDOMProcessingInstructionHandle handle, TElOwnHandle ownHandle);

		TElXMLDOMProcessingInstruction();

};
#endif /* SB_USE_CLASS_TELXMLDOMPROCESSINGINSTRUCTION */

#ifdef SB_USE_CLASS_TELXMLPARSER
class TElXMLParser: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLParser)
#ifdef SB_USE_CLASS_TELXMLCODEC
		TElXMLCodec* _Inst_OEnc;
#endif /* SB_USE_CLASS_TELXMLCODEC */

		void initInstances();

	public:
		void RaiseExc(const std::string &aMsg);

		void InitStream(const std::string &DefaultEncoding);

		void bufInit(sb_u16string &aArg);
#ifdef SB_U16STRING_USED
		void bufInit(std::wstring &aArg);
#endif /* SB_U16STRING_USED */

		void bufAddChar(sb_u16string &aArg, sb_char16_t c);
#ifdef SB_U16STRING_USED
		void bufAddChar(std::wstring &aArg, sb_char16_t c);
#endif /* SB_U16STRING_USED */

		void bufFlush(sb_u16string &aArg);
#ifdef SB_U16STRING_USED
		void bufFlush(std::wstring &aArg);
#endif /* SB_U16STRING_USED */

		void bufFree();

		bool sEOF();

		void NextChar();

		void PushData(const sb_u16string &Data);
#ifdef SB_U16STRING_USED
		void PushData(const std::wstring &Data);
#endif /* SB_U16STRING_USED */

		bool PushData(const sb_u16string &Data, const sb_u16string &Marker);
#ifdef SB_U16STRING_USED
		bool PushData(const std::wstring &Data, const std::wstring &Marker);
#endif /* SB_U16STRING_USED */

		void Write(const sb_u16string &aArg);
#ifdef SB_U16STRING_USED
		void Write(const std::wstring &aArg);
#endif /* SB_U16STRING_USED */

		void Write(sb_char16_t c);

		bool SkipBlank();

		void ExpectBlank();

		void ExpectString(const sb_u16string &aArg);
#ifdef SB_U16STRING_USED
		void ExpectString(const std::wstring &aArg);
#endif /* SB_U16STRING_USED */

		void UntilString(const sb_u16string &aArg, bool LeaveString, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void UntilString(const std::wstring &aArg, bool LeaveString, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		void UntilStringSkip(const sb_u16string &aArg);
#ifdef SB_U16STRING_USED
		void UntilStringSkip(const std::wstring &aArg);
#endif /* SB_U16STRING_USED */

		int32_t CheckForMulti(const std::vector<int32_t> &Expect, bool Recall);

		bool CheckFor(const sb_u16string &aArg, bool Recall);
#ifdef SB_U16STRING_USED
		bool CheckFor(const std::wstring &aArg, bool Recall);
#endif /* SB_U16STRING_USED */

		void GetWhile(void * aFunc, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void GetWhile(void * aFunc, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		void GetWhile(int32_t aCharKind, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void GetWhile(int32_t aCharKind, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		void GetUntil(void * aFunc, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void GetUntil(void * aFunc, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		void GetUntil(int32_t aCharKind, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void GetUntil(int32_t aCharKind, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		void GetUntilSkip(void * aFunc);

		void GetUntilSkip(int32_t aCharKind);

		bool GetNMtok(sb_u16string &aArg);
#ifdef SB_U16STRING_USED
		bool GetNMtok(std::wstring &aArg);
#endif /* SB_U16STRING_USED */

		virtual int64_t get_sPos();

		virtual void set_sPos(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_sPos, set_sPos, TElXMLParser, sPos);

		virtual int64_t get_LastPos();

		SB_DECLARE_PROPERTY_GET(int64_t, get_LastPos, TElXMLParser, LastPos);

		virtual sb_char16_t get_Last();

		SB_DECLARE_PROPERTY_GET(sb_char16_t, get_Last, TElXMLParser, Last);

		virtual bool get_NormalizeNEL();

		virtual void set_NormalizeNEL(bool Value);

		SB_DECLARE_PROPERTY(bool, get_NormalizeNEL, set_NormalizeNEL, TElXMLParser, NormalizeNEL);

#ifdef SB_USE_CLASS_TELXMLCODEC
		virtual TElXMLCodec* get_OEnc();

		virtual void set_OEnc(TElXMLCodec &Value);

		virtual void set_OEnc(TElXMLCodec *Value);

		SB_DECLARE_PROPERTY(TElXMLCodec*, get_OEnc, set_OEnc, TElXMLParser, OEnc);
#endif /* SB_USE_CLASS_TELXMLCODEC */

		TElXMLParser(TElXMLParserHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		TElXMLParser(TElXMLDOMDocument &aDoc, bool DoInitStream, const std::string &DefaultEncoding, bool NormNEL);

		TElXMLParser(TElXMLDOMDocument *aDoc, bool DoInitStream, const std::string &DefaultEncoding, bool NormNEL);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

		virtual ~TElXMLParser();

};
#endif /* SB_USE_CLASS_TELXMLPARSER */

#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP
class TElXMLNamespaceMap: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLNamespaceMap)
	public:
		void Clear();

		void Add(TElXMLNamespaceMap &NSMap, bool OverwriteIfExists);

		void Add(TElXMLNamespaceMap *NSMap, bool OverwriteIfExists);

		void AddNamespace(const sb_u16string &Prefix, const sb_u16string &URI);
#ifdef SB_U16STRING_USED
		void AddNamespace(const std::wstring &Prefix, const std::wstring &URI);
#endif /* SB_U16STRING_USED */

		void RemoveNamespace(const sb_u16string &Prefix);
#ifdef SB_U16STRING_USED
		void RemoveNamespace(const std::wstring &Prefix);
#endif /* SB_U16STRING_USED */

		void FindNamespace(const sb_u16string &Prefix, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void FindNamespace(const std::wstring &Prefix, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		void FindPrefix(const sb_u16string &URI, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void FindPrefix(const std::wstring &URI, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLNamespaceMap, Count);

		virtual void get_Prefix(int32_t Index, sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Prefix(int32_t Index, std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_URI(int32_t Index, sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_URI(int32_t Index, std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		TElXMLNamespaceMap(TElXMLNamespaceMapHandle handle, TElOwnHandle ownHandle);

		TElXMLNamespaceMap();

};
#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */

#ifdef SB_USE_CLASS_TELXMLCUSTOMFORMATTER
class TElXMLCustomFormatter: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLCustomFormatter)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void AppendElement(TElXMLDOMElement &Parent, TElXMLDOMElement &Child);

		virtual void AppendElement(TElXMLDOMElement *Parent, TElXMLDOMElement *Child);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMELEMENT_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle AppendElement(TElXMLDOMElement &Parent, TElXMLCustomElement &Child, TElXMLDOMDocument &Document);

		virtual TElXMLDOMElementHandle AppendElement(TElXMLDOMElement *Parent, TElXMLCustomElement *Child, TElXMLDOMDocument *Document);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMELEMENT_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void AppendElementWithText(TElXMLDOMElement &Parent, TElXMLDOMElement &Child, const sb_u16string &ChildText, TElXMLTextType ChildTextType);

		virtual void AppendElementWithText(TElXMLDOMElement *Parent, TElXMLDOMElement *Child, const sb_u16string &ChildText, TElXMLTextType ChildTextType);
#ifdef SB_U16STRING_USED
		virtual void AppendElementWithText(TElXMLDOMElement &Parent, TElXMLDOMElement &Child, const std::wstring &ChildText, TElXMLTextType ChildTextType);

		virtual void AppendElementWithText(TElXMLDOMElement *Parent, TElXMLDOMElement *Child, const std::wstring &ChildText, TElXMLTextType ChildTextType);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void AppendText(TElXMLDOMElement &Parent, const sb_u16string &Text, TElXMLTextType TextType);

		virtual void AppendText(TElXMLDOMElement *Parent, const sb_u16string &Text, TElXMLTextType TextType);
#ifdef SB_U16STRING_USED
		virtual void AppendText(TElXMLDOMElement &Parent, const std::wstring &Text, TElXMLTextType TextType);

		virtual void AppendText(TElXMLDOMElement *Parent, const std::wstring &Text, TElXMLTextType TextType);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMELEMENT_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT_AND_TELXMLDOMNODE
		virtual void InsertBefore(TElXMLDOMElement &Parent, TElXMLDOMNode &ChildRef, TElXMLCustomElement &Child, TElXMLDOMDocument &Document);

		virtual void InsertBefore(TElXMLDOMElement *Parent, TElXMLDOMNode *ChildRef, TElXMLCustomElement *Child, TElXMLDOMDocument *Document);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMELEMENT_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT_AND_TELXMLDOMNODE */

		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void Push(TElXMLDOMElement &Element);

		virtual void Push(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual void Pop();

		TElXMLCustomFormatter(TElXMLCustomFormatterHandle handle, TElOwnHandle ownHandle);

		TElXMLCustomFormatter();

};
#endif /* SB_USE_CLASS_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELXMLCUSTOMELEMENT
class TElXMLCustomElement: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLCustomElement)
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLDOMElement* _Inst_XMLElement;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document);

		TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document);
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLDOMElement* get_XMLElement();

		virtual void set_XMLElement(TElXMLDOMElement &Value);

		virtual void set_XMLElement(TElXMLDOMElement *Value);

		SB_DECLARE_PROPERTY(TElXMLDOMElement*, get_XMLElement, set_XMLElement, TElXMLCustomElement, XMLElement);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		TElXMLCustomElement(TElXMLCustomElementHandle handle, TElOwnHandle ownHandle);

		TElXMLCustomElement();

		virtual ~TElXMLCustomElement();

};
#endif /* SB_USE_CLASS_TELXMLCUSTOMELEMENT */

#ifdef SB_USE_GLOBAL_PROCS_XMLCORE

bool isXMLIdeographic(sb_char16_t c);

bool isXMLBaseChar(sb_char16_t c);

bool isXMLCombining(sb_char16_t c);

bool isXMLDigit(sb_char16_t c);

bool isXMLExtender(sb_char16_t c);

#endif /* SB_USE_GLOBAL_PROCS_XMLCORE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_XMLCORE
SB_IMPORT uint32_t SB_APIENTRY SBXMLCore_isXMLIdeographic(sb_char16_t c, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLCore_isXMLBaseChar(sb_char16_t c, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLCore_isXMLCombining(sb_char16_t c, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLCore_isXMLDigit(sb_char16_t c, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLCore_isXMLExtender(sb_char16_t c, int8_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_XMLCORE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBXMLCORE */

