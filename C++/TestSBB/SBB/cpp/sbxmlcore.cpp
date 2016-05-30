#include "sbxmlcore.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELXMLDOMIMPLEMENTATION

bool TElXMLDOMImplementation::HasFeature(const sb_u16string &Feature, const sb_u16string &Version)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDOMImplementation_HasFeature(_Handle, Feature.data(), (int32_t)Feature.length(), Version.data(), (int32_t)Version.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLDOMImplementation::HasFeature(const std::wstring &Feature, const std::wstring &Version)
{
	std::string u16Feature;
	sb_to_u16string(Feature, u16Feature);
	std::string u16Version;
	sb_to_u16string(Version, u16Version);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDOMImplementation_HasFeature(_Handle, reinterpret_cast<const sb_char16_t*>(u16Feature.data()), (int32_t)u16Feature.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Version.data()), (int32_t)u16Version.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE
SB_INLINE TElXMLDOMDocumentTypeHandle TElXMLDOMImplementation::CreateDocumentType(const sb_u16string &QualifiedName, const sb_u16string &PublicID, const sb_u16string &SystemID)
{
	TElXMLDOMDocumentTypeHandle OutResult;
	SBCheckError(TElXMLDOMImplementation_CreateDocumentType(_Handle, QualifiedName.data(), (int32_t)QualifiedName.length(), PublicID.data(), (int32_t)PublicID.length(), SystemID.data(), (int32_t)SystemID.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMDocumentTypeHandle TElXMLDOMImplementation::CreateDocumentType(const std::wstring &QualifiedName, const std::wstring &PublicID, const std::wstring &SystemID)
{
	TElXMLDOMDocumentTypeHandle OutResult;
	std::string u16QualifiedName;
	sb_to_u16string(QualifiedName, u16QualifiedName);
	std::string u16PublicID;
	sb_to_u16string(PublicID, u16PublicID);
	std::string u16SystemID;
	sb_to_u16string(SystemID, u16SystemID);
	SBCheckError(TElXMLDOMImplementation_CreateDocumentType(_Handle, reinterpret_cast<const sb_char16_t*>(u16QualifiedName.data()), (int32_t)u16QualifiedName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16PublicID.data()), (int32_t)u16PublicID.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16SystemID.data()), (int32_t)u16SystemID.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE
SB_INLINE TElXMLDOMDocumentTypeHandle TElXMLDOMImplementation::CreateDocumentType(const sb_u16string &QualifiedName, const sb_u16string &PublicID, const sb_u16string &SystemID, const sb_u16string &InternalSubset)
{
	TElXMLDOMDocumentTypeHandle OutResult;
	SBCheckError(TElXMLDOMImplementation_CreateDocumentType_1(_Handle, QualifiedName.data(), (int32_t)QualifiedName.length(), PublicID.data(), (int32_t)PublicID.length(), SystemID.data(), (int32_t)SystemID.length(), InternalSubset.data(), (int32_t)InternalSubset.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMDocumentTypeHandle TElXMLDOMImplementation::CreateDocumentType(const std::wstring &QualifiedName, const std::wstring &PublicID, const std::wstring &SystemID, const std::wstring &InternalSubset)
{
	TElXMLDOMDocumentTypeHandle OutResult;
	std::string u16QualifiedName;
	sb_to_u16string(QualifiedName, u16QualifiedName);
	std::string u16PublicID;
	sb_to_u16string(PublicID, u16PublicID);
	std::string u16SystemID;
	sb_to_u16string(SystemID, u16SystemID);
	std::string u16InternalSubset;
	sb_to_u16string(InternalSubset, u16InternalSubset);
	SBCheckError(TElXMLDOMImplementation_CreateDocumentType_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16QualifiedName.data()), (int32_t)u16QualifiedName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16PublicID.data()), (int32_t)u16PublicID.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16SystemID.data()), (int32_t)u16SystemID.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16InternalSubset.data()), (int32_t)u16InternalSubset.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE */

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMDOCUMENTTYPE
SB_INLINE TElXMLDOMDocumentHandle TElXMLDOMImplementation::CreateDocument(const sb_u16string &NamespaceURI, const sb_u16string &QualifiedName, TElXMLDOMDocumentType &DocType)
{
	TElXMLDOMDocumentHandle OutResult;
	SBCheckError(TElXMLDOMImplementation_CreateDocument(_Handle, NamespaceURI.data(), (int32_t)NamespaceURI.length(), QualifiedName.data(), (int32_t)QualifiedName.length(), DocType.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMDocumentHandle TElXMLDOMImplementation::CreateDocument(const sb_u16string &NamespaceURI, const sb_u16string &QualifiedName, TElXMLDOMDocumentType *DocType)
{
	TElXMLDOMDocumentHandle OutResult;
	SBCheckError(TElXMLDOMImplementation_CreateDocument(_Handle, NamespaceURI.data(), (int32_t)NamespaceURI.length(), QualifiedName.data(), (int32_t)QualifiedName.length(), (DocType != NULL) ? DocType->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMDocumentHandle TElXMLDOMImplementation::CreateDocument(const std::wstring &NamespaceURI, const std::wstring &QualifiedName, TElXMLDOMDocumentType &DocType)
{
	TElXMLDOMDocumentHandle OutResult;
	std::string u16NamespaceURI;
	sb_to_u16string(NamespaceURI, u16NamespaceURI);
	std::string u16QualifiedName;
	sb_to_u16string(QualifiedName, u16QualifiedName);
	SBCheckError(TElXMLDOMImplementation_CreateDocument(_Handle, reinterpret_cast<const sb_char16_t*>(u16NamespaceURI.data()), (int32_t)u16NamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16QualifiedName.data()), (int32_t)u16QualifiedName.length() >> 1, DocType.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMDocumentHandle TElXMLDOMImplementation::CreateDocument(const std::wstring &NamespaceURI, const std::wstring &QualifiedName, TElXMLDOMDocumentType *DocType)
{
	TElXMLDOMDocumentHandle OutResult;
	std::string u16NamespaceURI;
	sb_to_u16string(NamespaceURI, u16NamespaceURI);
	std::string u16QualifiedName;
	sb_to_u16string(QualifiedName, u16QualifiedName);
	SBCheckError(TElXMLDOMImplementation_CreateDocument(_Handle, reinterpret_cast<const sb_char16_t*>(u16NamespaceURI.data()), (int32_t)u16NamespaceURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16QualifiedName.data()), (int32_t)u16QualifiedName.length() >> 1, (DocType != NULL) ? DocType->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMDOCUMENTTYPE */

TElXMLDOMImplementation::TElXMLDOMImplementation(TElXMLDOMImplementationHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElXMLDOMImplementation::TElXMLDOMImplementation() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLDOMImplementation_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLDOMIMPLEMENTATION */

#ifdef SB_USE_CLASS_TELXMLDOMNODE

bool TElXMLDOMNode::ReloadData(TElXMLDelayLoadMode LoadedData)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDOMNode_ReloadData(_Handle, (TElXMLDelayLoadModeRaw)LoadedData, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLDOMNode::UnloadData(TElXMLDelayLoadMode DataToUnload)
{
	SBCheckError(TElXMLDOMNode_UnloadData(_Handle, (TElXMLDelayLoadModeRaw)DataToUnload));
}

void TElXMLDOMNode::GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMNode_GetOuterXMLCanonical(_Handle, (TElXMLCanonicalizationMethodRaw)aMethod, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(31459282, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLDOMNode::GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMNode_GetOuterXMLCanonical(_Handle, (TElXMLCanonicalizationMethodRaw)aMethod, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(31459282, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLDOMNode::GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, const sb_u16string &InclNSPrefixList, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMNode_GetOuterXMLCanonical_1(_Handle, (TElXMLCanonicalizationMethodRaw)aMethod, InclNSPrefixList.data(), (int32_t)InclNSPrefixList.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-637201611, 3, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLDOMNode::GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, const std::wstring &InclNSPrefixList, std::wstring &OutResult)
{
	std::string u16InclNSPrefixList;
	sb_to_u16string(InclNSPrefixList, u16InclNSPrefixList);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMNode_GetOuterXMLCanonical_1(_Handle, (TElXMLCanonicalizationMethodRaw)aMethod, reinterpret_cast<const sb_char16_t*>(u16InclNSPrefixList.data()), (int32_t)u16InclNSPrefixList.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-637201611, 3, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLNODESET
SB_INLINE TElXMLNodeSetHandle TElXMLDOMNode::SelectNodes(const sb_u16string &XPath)
{
	TElXMLNodeSetHandle OutResult;
	SBCheckError(TElXMLDOMNode_SelectNodes(_Handle, XPath.data(), (int32_t)XPath.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLNodeSetHandle TElXMLDOMNode::SelectNodes(const std::wstring &XPath)
{
	TElXMLNodeSetHandle OutResult;
	std::string u16XPath;
	sb_to_u16string(XPath, u16XPath);
	SBCheckError(TElXMLDOMNode_SelectNodes(_Handle, reinterpret_cast<const sb_char16_t*>(u16XPath.data()), (int32_t)u16XPath.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLNODESET */

#ifdef SB_USE_CLASSES_TELXMLNAMESPACEMAP_AND_TELXMLNODESET
SB_INLINE TElXMLNodeSetHandle TElXMLDOMNode::SelectNodes(const sb_u16string &XPath, TElXMLNamespaceMap &NSMap)
{
	TElXMLNodeSetHandle OutResult;
	SBCheckError(TElXMLDOMNode_SelectNodes_1(_Handle, XPath.data(), (int32_t)XPath.length(), NSMap.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLNodeSetHandle TElXMLDOMNode::SelectNodes(const sb_u16string &XPath, TElXMLNamespaceMap *NSMap)
{
	TElXMLNodeSetHandle OutResult;
	SBCheckError(TElXMLDOMNode_SelectNodes_1(_Handle, XPath.data(), (int32_t)XPath.length(), (NSMap != NULL) ? NSMap->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLNodeSetHandle TElXMLDOMNode::SelectNodes(const std::wstring &XPath, TElXMLNamespaceMap &NSMap)
{
	TElXMLNodeSetHandle OutResult;
	std::string u16XPath;
	sb_to_u16string(XPath, u16XPath);
	SBCheckError(TElXMLDOMNode_SelectNodes_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16XPath.data()), (int32_t)u16XPath.length() >> 1, NSMap.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLNodeSetHandle TElXMLDOMNode::SelectNodes(const std::wstring &XPath, TElXMLNamespaceMap *NSMap)
{
	TElXMLNodeSetHandle OutResult;
	std::string u16XPath;
	sb_to_u16string(XPath, u16XPath);
	SBCheckError(TElXMLDOMNode_SelectNodes_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16XPath.data()), (int32_t)u16XPath.length() >> 1, (NSMap != NULL) ? NSMap->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELXMLNAMESPACEMAP_AND_TELXMLNODESET */

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNode::InsertBefore(TElXMLDOMNode &NewChild, TElXMLDOMNode &RefChild)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNode_InsertBefore(_Handle, NewChild.getHandle(), RefChild.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNode::InsertBefore(TElXMLDOMNode *NewChild, TElXMLDOMNode *RefChild)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNode_InsertBefore(_Handle, (NewChild != NULL) ? NewChild->getHandle() : SB_NULL_HANDLE, (RefChild != NULL) ? RefChild->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNode::ReplaceChild(TElXMLDOMNode &NewChild, TElXMLDOMNode &OldChild)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNode_ReplaceChild(_Handle, NewChild.getHandle(), OldChild.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNode::ReplaceChild(TElXMLDOMNode *NewChild, TElXMLDOMNode *OldChild)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNode_ReplaceChild(_Handle, (NewChild != NULL) ? NewChild->getHandle() : SB_NULL_HANDLE, (OldChild != NULL) ? OldChild->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLDOMNode::RemoveChild(TElXMLDOMNode &OldChild)
{
	SBCheckError(TElXMLDOMNode_RemoveChild(_Handle, OldChild.getHandle()));
}

SB_INLINE void TElXMLDOMNode::RemoveChild(TElXMLDOMNode *OldChild)
{
	SBCheckError(TElXMLDOMNode_RemoveChild(_Handle, (OldChild != NULL) ? OldChild->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNode::AppendChild(TElXMLDOMNode &NewChild)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNode_AppendChild(_Handle, NewChild.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNode::AppendChild(TElXMLDOMNode *NewChild)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNode_AppendChild(_Handle, (NewChild != NULL) ? NewChild->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNode::AppendChild(TElXMLDOMNode &NewChild, bool DisablePrefixUpdate)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNode_AppendChild_1(_Handle, NewChild.getHandle(), (int8_t)DisablePrefixUpdate, &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNode::AppendChild(TElXMLDOMNode *NewChild, bool DisablePrefixUpdate)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNode_AppendChild_1(_Handle, (NewChild != NULL) ? NewChild->getHandle() : SB_NULL_HANDLE, (int8_t)DisablePrefixUpdate, &OutResult));
	return OutResult;
}

bool TElXMLDOMNode::HasChildNodes()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDOMNode_HasChildNodes(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNode::CloneNode(bool Deep)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNode_CloneNode(_Handle, (int8_t)Deep, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNode::CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNode_CloneNode_1(_Handle, (int8_t)Deep, aCloneOwner.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNode::CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNode_CloneNode_1(_Handle, (int8_t)Deep, (aCloneOwner != NULL) ? aCloneOwner->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

SB_INLINE void TElXMLDOMNode::Normalize()
{
	SBCheckError(TElXMLDOMNode_Normalize(_Handle));
}

bool TElXMLDOMNode::HasAttributes()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDOMNode_HasAttributes(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXMLDOMNode::isSupported(const sb_u16string &Feature, const sb_u16string &Version)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDOMNode_isSupported(_Handle, Feature.data(), (int32_t)Feature.length(), Version.data(), (int32_t)Version.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLDOMNode::isSupported(const std::wstring &Feature, const std::wstring &Version)
{
	std::string u16Feature;
	sb_to_u16string(Feature, u16Feature);
	std::string u16Version;
	sb_to_u16string(Version, u16Version);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDOMNode_isSupported(_Handle, reinterpret_cast<const sb_char16_t*>(u16Feature.data()), (int32_t)u16Feature.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Version.data()), (int32_t)u16Version.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNode::FindNode(const sb_u16string &aNodeName)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNode_FindNode(_Handle, aNodeName.data(), (int32_t)aNodeName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNode::FindNode(const std::wstring &aNodeName)
{
	TElXMLDOMNodeHandle OutResult;
	std::string u16aNodeName;
	sb_to_u16string(aNodeName, u16aNodeName);
	SBCheckError(TElXMLDOMNode_FindNode(_Handle, reinterpret_cast<const sb_char16_t*>(u16aNodeName.data()), (int32_t)u16aNodeName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNode::FindNode(const sb_u16string &aNodeName, bool Deep)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNode_FindNode_1(_Handle, aNodeName.data(), (int32_t)aNodeName.length(), (int8_t)Deep, &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNode::FindNode(const std::wstring &aNodeName, bool Deep)
{
	TElXMLDOMNodeHandle OutResult;
	std::string u16aNodeName;
	sb_to_u16string(aNodeName, u16aNodeName);
	SBCheckError(TElXMLDOMNode_FindNode_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16aNodeName.data()), (int32_t)u16aNodeName.length() >> 1, (int8_t)Deep, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLDOMNode::get_RelativeIndex()
{
	int32_t OutResult;
	SBCheckError(TElXMLDOMNode_get_RelativeIndex(_Handle, &OutResult));
	return OutResult;
}

void TElXMLDOMNode::get_NodeName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMNode_get_NodeName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1415144006, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMNode::get_NodeName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMNode_get_NodeName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1415144006, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLDOMNode::get_NodeValue(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMNode_get_NodeValue(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(223858173, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMNode::get_NodeValue(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMNode_get_NodeValue(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(223858173, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLDOMNode::set_NodeValue(const sb_u16string &Value)
{
	SBCheckError(TElXMLDOMNode_set_NodeValue(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDOMNode::set_NodeValue(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLDOMNode_set_NodeValue(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE int32_t TElXMLDOMNode::get_NodeType()
{
	int32_t OutResult;
	SBCheckError(TElXMLDOMNode_get_NodeType(_Handle, &OutResult));
	return OutResult;
}

TElXMLDOMNode* TElXMLDOMNode::get_ParentNode()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDOMNode_get_ParentNode(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ParentNode)
		this->_Inst_ParentNode = new TElXMLDOMNode(hOutResult, ohFalse);
	else
		this->_Inst_ParentNode->updateHandle(hOutResult);
	return this->_Inst_ParentNode;
}

TElXMLDOMNode* TElXMLDOMNode::get_FirstChild()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDOMNode_get_FirstChild(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FirstChild)
		this->_Inst_FirstChild = new TElXMLDOMNode(hOutResult, ohFalse);
	else
		this->_Inst_FirstChild->updateHandle(hOutResult);
	return this->_Inst_FirstChild;
}

TElXMLDOMNode* TElXMLDOMNode::get_LastChild()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDOMNode_get_LastChild(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_LastChild)
		this->_Inst_LastChild = new TElXMLDOMNode(hOutResult, ohFalse);
	else
		this->_Inst_LastChild->updateHandle(hOutResult);
	return this->_Inst_LastChild;
}

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
TElXMLDOMNodeList* TElXMLDOMNode::get_ChildNodes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDOMNode_get_ChildNodes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ChildNodes)
		this->_Inst_ChildNodes = new TElXMLDOMNodeList(hOutResult, ohFalse);
	else
		this->_Inst_ChildNodes->updateHandle(hOutResult);
	return this->_Inst_ChildNodes;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

TElXMLDOMNode* TElXMLDOMNode::get_PreviousSibling()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDOMNode_get_PreviousSibling(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PreviousSibling)
		this->_Inst_PreviousSibling = new TElXMLDOMNode(hOutResult, ohFalse);
	else
		this->_Inst_PreviousSibling->updateHandle(hOutResult);
	return this->_Inst_PreviousSibling;
}

TElXMLDOMNode* TElXMLDOMNode::get_NextSibling()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDOMNode_get_NextSibling(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_NextSibling)
		this->_Inst_NextSibling = new TElXMLDOMNode(hOutResult, ohFalse);
	else
		this->_Inst_NextSibling->updateHandle(hOutResult);
	return this->_Inst_NextSibling;
}

#ifdef SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP
TElXMLDOMNamedNodeMap* TElXMLDOMNode::get_Attributes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDOMNode_get_Attributes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Attributes)
		this->_Inst_Attributes = new TElXMLDOMNamedNodeMap(hOutResult, ohFalse);
	else
		this->_Inst_Attributes->updateHandle(hOutResult);
	return this->_Inst_Attributes;
}
#endif /* SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
TElXMLDOMDocument* TElXMLDOMNode::get_OwnerDocument()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDOMNode_get_OwnerDocument(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OwnerDocument)
		this->_Inst_OwnerDocument = new TElXMLDOMDocument(hOutResult, ohFalse);
	else
		this->_Inst_OwnerDocument->updateHandle(hOutResult);
	return this->_Inst_OwnerDocument;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

void TElXMLDOMNode::get_RawData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElXMLDOMNode_get_RawData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-553059733, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElXMLDOMNode::get_RawDataLength()
{
	int32_t OutResult;
	SBCheckError(TElXMLDOMNode_get_RawDataLength(_Handle, &OutResult));
	return OutResult;
}

bool TElXMLDOMNode::get_Loaded()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDOMNode_get_Loaded(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElXMLDOMNode::get_OuterXML(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMNode_get_OuterXML(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-519734793, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMNode::get_OuterXML(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMNode_get_OuterXML(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-519734793, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLDOMNode::get_NamespaceURI(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMNode_get_NamespaceURI(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1457466651, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMNode::get_NamespaceURI(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMNode_get_NamespaceURI(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1457466651, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLDOMNode::get_LocalName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMNode_get_LocalName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-460026458, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMNode::get_LocalName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMNode_get_LocalName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-460026458, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLDOMNode::get_Prefix(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMNode_get_Prefix(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(36384557, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMNode::get_Prefix(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMNode_get_Prefix(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(36384557, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLDOMNode::initInstances()
{
	this->_Inst_ParentNode = NULL;
	this->_Inst_FirstChild = NULL;
	this->_Inst_LastChild = NULL;
#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
	this->_Inst_ChildNodes = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */
	this->_Inst_PreviousSibling = NULL;
	this->_Inst_NextSibling = NULL;
#ifdef SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP */
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
	this->_Inst_OwnerDocument = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */
}

TElXMLDOMNode::TElXMLDOMNode(TElXMLDOMNodeHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLDOMNode::TElXMLDOMNode() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLDOMNode_Create(&_Handle));
}

TElXMLDOMNode::~TElXMLDOMNode()
{
	delete this->_Inst_ParentNode;
	this->_Inst_ParentNode = NULL;
	delete this->_Inst_FirstChild;
	this->_Inst_FirstChild = NULL;
	delete this->_Inst_LastChild;
	this->_Inst_LastChild = NULL;
#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
	delete this->_Inst_ChildNodes;
	this->_Inst_ChildNodes = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */
	delete this->_Inst_PreviousSibling;
	this->_Inst_PreviousSibling = NULL;
	delete this->_Inst_NextSibling;
	this->_Inst_NextSibling = NULL;
#ifdef SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP
	delete this->_Inst_Attributes;
	this->_Inst_Attributes = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP */
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
	delete this->_Inst_OwnerDocument;
	this->_Inst_OwnerDocument = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElXMLDOMDocument::LoadFromStream(TStream &aStream)
{
	SBCheckError(TElXMLDOMDocument_LoadFromStream(_Handle, aStream.getHandle()));
}

SB_INLINE void TElXMLDOMDocument::LoadFromStream(TStream *aStream)
{
	SBCheckError(TElXMLDOMDocument_LoadFromStream(_Handle, (aStream != NULL) ? aStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElXMLDOMDocument::LoadFromStream(TStream &aStream, const std::string &DefaultEncoding, bool NormalizeNEL)
{
	SBCheckError(TElXMLDOMDocument_LoadFromStream_1(_Handle, aStream.getHandle(), DefaultEncoding.data(), (int32_t)DefaultEncoding.length(), (int8_t)NormalizeNEL));
}

SB_INLINE void TElXMLDOMDocument::LoadFromStream(TStream *aStream, const std::string &DefaultEncoding, bool NormalizeNEL)
{
	SBCheckError(TElXMLDOMDocument_LoadFromStream_1(_Handle, (aStream != NULL) ? aStream->getHandle() : SB_NULL_HANDLE, DefaultEncoding.data(), (int32_t)DefaultEncoding.length(), (int8_t)NormalizeNEL));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElXMLDOMDocument::LoadFromStream(TStream &aStream, bool OwnStream, TElXMLDelayLoadMode DataToLoad)
{
	SBCheckError(TElXMLDOMDocument_LoadFromStream_2(_Handle, aStream.getHandle(), (int8_t)OwnStream, (TElXMLDelayLoadModeRaw)DataToLoad));
}

SB_INLINE void TElXMLDOMDocument::LoadFromStream(TStream *aStream, bool OwnStream, TElXMLDelayLoadMode DataToLoad)
{
	SBCheckError(TElXMLDOMDocument_LoadFromStream_2(_Handle, (aStream != NULL) ? aStream->getHandle() : SB_NULL_HANDLE, (int8_t)OwnStream, (TElXMLDelayLoadModeRaw)DataToLoad));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElXMLDOMDocument::LoadFromStream(TStream &aStream, bool OwnStream, TElXMLDelayLoadMode DataToLoad, const std::string &DefaultEncoding, bool NormalizeNEL)
{
	SBCheckError(TElXMLDOMDocument_LoadFromStream_3(_Handle, aStream.getHandle(), (int8_t)OwnStream, (TElXMLDelayLoadModeRaw)DataToLoad, DefaultEncoding.data(), (int32_t)DefaultEncoding.length(), (int8_t)NormalizeNEL));
}

SB_INLINE void TElXMLDOMDocument::LoadFromStream(TStream *aStream, bool OwnStream, TElXMLDelayLoadMode DataToLoad, const std::string &DefaultEncoding, bool NormalizeNEL)
{
	SBCheckError(TElXMLDOMDocument_LoadFromStream_3(_Handle, (aStream != NULL) ? aStream->getHandle() : SB_NULL_HANDLE, (int8_t)OwnStream, (TElXMLDelayLoadModeRaw)DataToLoad, DefaultEncoding.data(), (int32_t)DefaultEncoding.length(), (int8_t)NormalizeNEL));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElXMLDOMDocument::SaveToStream(TStream &aStream)
{
	SBCheckError(TElXMLDOMDocument_SaveToStream(_Handle, aStream.getHandle()));
}

SB_INLINE void TElXMLDOMDocument::SaveToStream(TStream *aStream)
{
	SBCheckError(TElXMLDOMDocument_SaveToStream(_Handle, (aStream != NULL) ? aStream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELXMLCODEC_AND_TSTREAM
SB_INLINE void TElXMLDOMDocument::SaveToStream(TStream &aStream, TElXMLCanonicalizationMethod aMethod, TElXMLCodec &aEncoding)
{
	SBCheckError(TElXMLDOMDocument_SaveToStream_1(_Handle, aStream.getHandle(), (TElXMLCanonicalizationMethodRaw)aMethod, aEncoding.getHandle()));
}

SB_INLINE void TElXMLDOMDocument::SaveToStream(TStream *aStream, TElXMLCanonicalizationMethod aMethod, TElXMLCodec *aEncoding)
{
	SBCheckError(TElXMLDOMDocument_SaveToStream_1(_Handle, (aStream != NULL) ? aStream->getHandle() : SB_NULL_HANDLE, (TElXMLCanonicalizationMethodRaw)aMethod, (aEncoding != NULL) ? aEncoding->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELXMLCODEC_AND_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElXMLDOMDocument::SaveToStream(TStream &aStream, TElXMLCanonicalizationMethod aMethod, const std::string &aCharset)
{
	SBCheckError(TElXMLDOMDocument_SaveToStream_2(_Handle, aStream.getHandle(), (TElXMLCanonicalizationMethodRaw)aMethod, aCharset.data(), (int32_t)aCharset.length()));
}

SB_INLINE void TElXMLDOMDocument::SaveToStream(TStream *aStream, TElXMLCanonicalizationMethod aMethod, const std::string &aCharset)
{
	SBCheckError(TElXMLDOMDocument_SaveToStream_2(_Handle, (aStream != NULL) ? aStream->getHandle() : SB_NULL_HANDLE, (TElXMLCanonicalizationMethodRaw)aMethod, aCharset.data(), (int32_t)aCharset.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElXMLDOMDocument::LoadFromFile(const std::string &aFileName)
{
	SBCheckError(TElXMLDOMDocument_LoadFromFile(_Handle, aFileName.data(), (int32_t)aFileName.length()));
}

SB_INLINE void TElXMLDOMDocument::LoadFromFile(const std::string &aFileName, const std::string &DefaultEncoding, bool NormalizeNEL)
{
	SBCheckError(TElXMLDOMDocument_LoadFromFile_1(_Handle, aFileName.data(), (int32_t)aFileName.length(), DefaultEncoding.data(), (int32_t)DefaultEncoding.length(), (int8_t)NormalizeNEL));
}

SB_INLINE void TElXMLDOMDocument::LoadFromFile(const std::string &aFileName, TElXMLDelayLoadMode DataToLoad)
{
	SBCheckError(TElXMLDOMDocument_LoadFromFile_2(_Handle, aFileName.data(), (int32_t)aFileName.length(), (TElXMLDelayLoadModeRaw)DataToLoad));
}

SB_INLINE void TElXMLDOMDocument::LoadFromFile(const std::string &aFileName, TElXMLDelayLoadMode DataToLoad, const std::string &DefaultEncoding, bool NormalizeNEL)
{
	SBCheckError(TElXMLDOMDocument_LoadFromFile_3(_Handle, aFileName.data(), (int32_t)aFileName.length(), (TElXMLDelayLoadModeRaw)DataToLoad, DefaultEncoding.data(), (int32_t)DefaultEncoding.length(), (int8_t)NormalizeNEL));
}

SB_INLINE void TElXMLDOMDocument::SaveToFile(const std::string &aFileName)
{
	SBCheckError(TElXMLDOMDocument_SaveToFile(_Handle, aFileName.data(), (int32_t)aFileName.length()));
}

SB_INLINE void TElXMLDOMDocument::SaveToFile(const std::string &aFileName, TElXMLCanonicalizationMethod aMethod)
{
	SBCheckError(TElXMLDOMDocument_SaveToFile_1(_Handle, aFileName.data(), (int32_t)aFileName.length(), (TElXMLCanonicalizationMethodRaw)aMethod));
}

SB_INLINE void TElXMLDOMDocument::ReloadAll()
{
	SBCheckError(TElXMLDOMDocument_ReloadAll(_Handle));
}

void TElXMLDOMDocument::LookupEntityByRef(const sb_u16string &aRef, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMDocument_LookupEntityByRef(_Handle, aRef.data(), (int32_t)aRef.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1045003991, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLDOMDocument::LookupEntityByRef(const std::wstring &aRef, std::wstring &OutResult)
{
	std::string u16aRef;
	sb_to_u16string(aRef, u16aRef);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMDocument_LookupEntityByRef(_Handle, reinterpret_cast<const sb_char16_t*>(u16aRef.data()), (int32_t)u16aRef.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1045003991, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLDOMDocument::CreateElement(const sb_u16string &TagName)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLDOMDocument_CreateElement(_Handle, TagName.data(), (int32_t)TagName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMElementHandle TElXMLDOMDocument::CreateElement(const std::wstring &TagName)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16TagName;
	sb_to_u16string(TagName, u16TagName);
	SBCheckError(TElXMLDOMDocument_CreateElement(_Handle, reinterpret_cast<const sb_char16_t*>(u16TagName.data()), (int32_t)u16TagName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENTFRAGMENT
SB_INLINE TElXMLDOMDocumentFragmentHandle TElXMLDOMDocument::CreateDocumentFragment()
{
	TElXMLDOMDocumentFragmentHandle OutResult;
	SBCheckError(TElXMLDOMDocument_CreateDocumentFragment(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENTFRAGMENT */

#ifdef SB_USE_CLASS_TELXMLDOMTEXT
SB_INLINE TElXMLDOMTextHandle TElXMLDOMDocument::CreateTextNode(const sb_u16string &Data)
{
	TElXMLDOMTextHandle OutResult;
	SBCheckError(TElXMLDOMDocument_CreateTextNode(_Handle, Data.data(), (int32_t)Data.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMTextHandle TElXMLDOMDocument::CreateTextNode(const std::wstring &Data)
{
	TElXMLDOMTextHandle OutResult;
	std::string u16Data;
	sb_to_u16string(Data, u16Data);
	SBCheckError(TElXMLDOMDocument_CreateTextNode(_Handle, reinterpret_cast<const sb_char16_t*>(u16Data.data()), (int32_t)u16Data.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMTEXT */

#ifdef SB_USE_CLASS_TELXMLDOMCOMMENT
SB_INLINE TElXMLDOMCommentHandle TElXMLDOMDocument::CreateComment(const sb_u16string &Data)
{
	TElXMLDOMCommentHandle OutResult;
	SBCheckError(TElXMLDOMDocument_CreateComment(_Handle, Data.data(), (int32_t)Data.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMCommentHandle TElXMLDOMDocument::CreateComment(const std::wstring &Data)
{
	TElXMLDOMCommentHandle OutResult;
	std::string u16Data;
	sb_to_u16string(Data, u16Data);
	SBCheckError(TElXMLDOMDocument_CreateComment(_Handle, reinterpret_cast<const sb_char16_t*>(u16Data.data()), (int32_t)u16Data.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMCOMMENT */

#ifdef SB_USE_CLASS_TELXMLDOMATTR
SB_INLINE TElXMLDOMAttrHandle TElXMLDOMDocument::CreateAttribute(const sb_u16string &Name)
{
	TElXMLDOMAttrHandle OutResult;
	SBCheckError(TElXMLDOMDocument_CreateAttribute(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMAttrHandle TElXMLDOMDocument::CreateAttribute(const std::wstring &Name)
{
	TElXMLDOMAttrHandle OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	SBCheckError(TElXMLDOMDocument_CreateAttribute(_Handle, reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
SB_INLINE TElXMLDOMNodeListHandle TElXMLDOMDocument::GetElementsByTagName(const sb_u16string &TagName)
{
	TElXMLDOMNodeListHandle OutResult;
	SBCheckError(TElXMLDOMDocument_GetElementsByTagName(_Handle, TagName.data(), (int32_t)TagName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMNodeListHandle TElXMLDOMDocument::GetElementsByTagName(const std::wstring &TagName)
{
	TElXMLDOMNodeListHandle OutResult;
	std::string u16TagName;
	sb_to_u16string(TagName, u16TagName);
	SBCheckError(TElXMLDOMDocument_GetElementsByTagName(_Handle, reinterpret_cast<const sb_char16_t*>(u16TagName.data()), (int32_t)u16TagName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMDocument::ImportNode(const TElXMLDOMNode &aNode, bool Deep)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMDocument_ImportNode(_Handle, aNode.getHandle(), (int8_t)Deep, &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMDocument::ImportNode(const TElXMLDOMNode *aNode, bool Deep)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMDocument_ImportNode(_Handle, (aNode != NULL) ? aNode->getHandle() : SB_NULL_HANDLE, (int8_t)Deep, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLDOMDocument::CreateElementNS(const sb_u16string &aNSURI, const sb_u16string &aName)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLDOMDocument_CreateElementNS(_Handle, aNSURI.data(), (int32_t)aNSURI.length(), aName.data(), (int32_t)aName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMElementHandle TElXMLDOMDocument::CreateElementNS(const std::wstring &aNSURI, const std::wstring &aName)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16aNSURI;
	sb_to_u16string(aNSURI, u16aNSURI);
	std::string u16aName;
	sb_to_u16string(aName, u16aName);
	SBCheckError(TElXMLDOMDocument_CreateElementNS(_Handle, reinterpret_cast<const sb_char16_t*>(u16aNSURI.data()), (int32_t)u16aNSURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16aName.data()), (int32_t)u16aName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMATTR
SB_INLINE TElXMLDOMAttrHandle TElXMLDOMDocument::CreateAttributeNS(const sb_u16string &aNSURi, const sb_u16string &aName)
{
	TElXMLDOMAttrHandle OutResult;
	SBCheckError(TElXMLDOMDocument_CreateAttributeNS(_Handle, aNSURi.data(), (int32_t)aNSURi.length(), aName.data(), (int32_t)aName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMAttrHandle TElXMLDOMDocument::CreateAttributeNS(const std::wstring &aNSURi, const std::wstring &aName)
{
	TElXMLDOMAttrHandle OutResult;
	std::string u16aNSURi;
	sb_to_u16string(aNSURi, u16aNSURi);
	std::string u16aName;
	sb_to_u16string(aName, u16aName);
	SBCheckError(TElXMLDOMDocument_CreateAttributeNS(_Handle, reinterpret_cast<const sb_char16_t*>(u16aNSURi.data()), (int32_t)u16aNSURi.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16aName.data()), (int32_t)u16aName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
SB_INLINE TElXMLDOMNodeListHandle TElXMLDOMDocument::GetElementsByTagNameNS(const sb_u16string &aNSURi, const sb_u16string &aName)
{
	TElXMLDOMNodeListHandle OutResult;
	SBCheckError(TElXMLDOMDocument_GetElementsByTagNameNS(_Handle, aNSURi.data(), (int32_t)aNSURi.length(), aName.data(), (int32_t)aName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMNodeListHandle TElXMLDOMDocument::GetElementsByTagNameNS(const std::wstring &aNSURi, const std::wstring &aName)
{
	TElXMLDOMNodeListHandle OutResult;
	std::string u16aNSURi;
	sb_to_u16string(aNSURi, u16aNSURi);
	std::string u16aName;
	sb_to_u16string(aName, u16aName);
	SBCheckError(TElXMLDOMDocument_GetElementsByTagNameNS(_Handle, reinterpret_cast<const sb_char16_t*>(u16aNSURi.data()), (int32_t)u16aNSURi.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16aName.data()), (int32_t)u16aName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLDOMDocument::GetElementByID(const sb_u16string &aElementID)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLDOMDocument_GetElementByID(_Handle, aElementID.data(), (int32_t)aElementID.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMElementHandle TElXMLDOMDocument::GetElementByID(const std::wstring &aElementID)
{
	TElXMLDOMElementHandle OutResult;
	std::string u16aElementID;
	sb_to_u16string(aElementID, u16aElementID);
	SBCheckError(TElXMLDOMDocument_GetElementByID(_Handle, reinterpret_cast<const sb_char16_t*>(u16aElementID.data()), (int32_t)u16aElementID.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMENTITY
SB_INLINE TElXMLDOMEntityHandle TElXMLDOMDocument::CreateEntity(const sb_u16string &Data)
{
	TElXMLDOMEntityHandle OutResult;
	SBCheckError(TElXMLDOMDocument_CreateEntity(_Handle, Data.data(), (int32_t)Data.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMEntityHandle TElXMLDOMDocument::CreateEntity(const std::wstring &Data)
{
	TElXMLDOMEntityHandle OutResult;
	std::string u16Data;
	sb_to_u16string(Data, u16Data);
	SBCheckError(TElXMLDOMDocument_CreateEntity(_Handle, reinterpret_cast<const sb_char16_t*>(u16Data.data()), (int32_t)u16Data.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMENTITY */

#ifdef SB_USE_CLASS_TELXMLDOMCDATASECTION
SB_INLINE TElXMLDOMCDATASectionHandle TElXMLDOMDocument::CreateCDATASection(const sb_u16string &Data)
{
	TElXMLDOMCDATASectionHandle OutResult;
	SBCheckError(TElXMLDOMDocument_CreateCDATASection(_Handle, Data.data(), (int32_t)Data.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMCDATASectionHandle TElXMLDOMDocument::CreateCDATASection(const std::wstring &Data)
{
	TElXMLDOMCDATASectionHandle OutResult;
	std::string u16Data;
	sb_to_u16string(Data, u16Data);
	SBCheckError(TElXMLDOMDocument_CreateCDATASection(_Handle, reinterpret_cast<const sb_char16_t*>(u16Data.data()), (int32_t)u16Data.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMCDATASECTION */

#ifdef SB_USE_CLASS_TELXMLDOMPROCESSINGINSTRUCTION
SB_INLINE TElXMLDOMProcessingInstructionHandle TElXMLDOMDocument::CreateProcessingInstruction(const sb_u16string &Target, const sb_u16string &Data)
{
	TElXMLDOMProcessingInstructionHandle OutResult;
	SBCheckError(TElXMLDOMDocument_CreateProcessingInstruction(_Handle, Target.data(), (int32_t)Target.length(), Data.data(), (int32_t)Data.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMProcessingInstructionHandle TElXMLDOMDocument::CreateProcessingInstruction(const std::wstring &Target, const std::wstring &Data)
{
	TElXMLDOMProcessingInstructionHandle OutResult;
	std::string u16Target;
	sb_to_u16string(Target, u16Target);
	std::string u16Data;
	sb_to_u16string(Data, u16Data);
	SBCheckError(TElXMLDOMDocument_CreateProcessingInstruction(_Handle, reinterpret_cast<const sb_char16_t*>(u16Target.data()), (int32_t)u16Target.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Data.data()), (int32_t)u16Data.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMPROCESSINGINSTRUCTION */

#ifdef SB_USE_CLASS_TELXMLDOMENTITYREFERENCE
SB_INLINE TElXMLDOMEntityReferenceHandle TElXMLDOMDocument::CreateEntityReference(const sb_u16string &Name)
{
	TElXMLDOMEntityReferenceHandle OutResult;
	SBCheckError(TElXMLDOMDocument_CreateEntityReference(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMEntityReferenceHandle TElXMLDOMDocument::CreateEntityReference(const std::wstring &Name)
{
	TElXMLDOMEntityReferenceHandle OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	SBCheckError(TElXMLDOMDocument_CreateEntityReference(_Handle, reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMENTITYREFERENCE */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE
TElXMLDOMDocumentType* TElXMLDOMDocument::get_DocumentType()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDOMDocument_get_DocumentType(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DocumentType)
		this->_Inst_DocumentType = new TElXMLDOMDocumentType(hOutResult, ohFalse);
	else
		this->_Inst_DocumentType->updateHandle(hOutResult);
	return this->_Inst_DocumentType;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE */

#ifdef SB_USE_CLASS_TELXMLDOMIMPLEMENTATION
TElXMLDOMImplementation* TElXMLDOMDocument::get_Impl()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDOMDocument_get_Impl(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Impl)
		this->_Inst_Impl = new TElXMLDOMImplementation(hOutResult, ohFalse);
	else
		this->_Inst_Impl->updateHandle(hOutResult);
	return this->_Inst_Impl;
}
#endif /* SB_USE_CLASS_TELXMLDOMIMPLEMENTATION */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElement* TElXMLDOMDocument::get_DocumentElement()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDOMDocument_get_DocumentElement(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DocumentElement)
		this->_Inst_DocumentElement = new TElXMLDOMElement(hOutResult, ohFalse);
	else
		this->_Inst_DocumentElement->updateHandle(hOutResult);
	return this->_Inst_DocumentElement;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMATTR
TElXMLDOMAttr* TElXMLDOMDocument::get_XmlNS()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDOMDocument_get_XmlNS(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_XmlNS)
		this->_Inst_XmlNS = new TElXMLDOMAttr(hOutResult, ohFalse);
	else
		this->_Inst_XmlNS->updateHandle(hOutResult);
	return this->_Inst_XmlNS;
}
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

void TElXMLDOMDocument::get_OriginalEncoding(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMDocument_get_OriginalEncoding(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(932249875, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMDocument::get_OriginalEncoding(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMDocument_get_OriginalEncoding(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(932249875, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLDOMDocument::get_Version(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMDocument_get_Version(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-936656825, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMDocument::get_Version(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMDocument_get_Version(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-936656825, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLDOMDocument::set_Version(const sb_u16string &Value)
{
	SBCheckError(TElXMLDOMDocument_set_Version(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDOMDocument::set_Version(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLDOMDocument_set_Version(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLDOMDocument::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE
	this->_Inst_DocumentType = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE */
#ifdef SB_USE_CLASS_TELXMLDOMIMPLEMENTATION
	this->_Inst_Impl = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMIMPLEMENTATION */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	this->_Inst_DocumentElement = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELXMLDOMATTR
	this->_Inst_XmlNS = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMATTR */
}

TElXMLDOMDocument::TElXMLDOMDocument(TElXMLDOMDocumentHandle handle, TElOwnHandle ownHandle) : TElXMLDOMNode(handle, ownHandle)
{
	initInstances();
}

TElXMLDOMDocument::TElXMLDOMDocument() : TElXMLDOMNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLDOMDocument_Create(&_Handle));
}

TElXMLDOMDocument::~TElXMLDOMDocument()
{
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE
	delete this->_Inst_DocumentType;
	this->_Inst_DocumentType = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE */
#ifdef SB_USE_CLASS_TELXMLDOMIMPLEMENTATION
	delete this->_Inst_Impl;
	this->_Inst_Impl = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMIMPLEMENTATION */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	delete this->_Inst_DocumentElement;
	this->_Inst_DocumentElement = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
#ifdef SB_USE_CLASS_TELXMLDOMATTR
	delete this->_Inst_XmlNS;
	this->_Inst_XmlNS = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMATTR */
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENTFRAGMENT

TElXMLDOMDocumentFragment::TElXMLDOMDocumentFragment(TElXMLDOMDocumentFragmentHandle handle, TElOwnHandle ownHandle) : TElXMLDOMNode(handle, ownHandle)
{
}

TElXMLDOMDocumentFragment::TElXMLDOMDocumentFragment() : TElXMLDOMNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLDOMDocumentFragment_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENTFRAGMENT */

#ifdef SB_USE_CLASS_TELXMLNODESET

#ifdef SB_USE_CLASS_TELXMLDOMNODE
SB_INLINE int32_t TElXMLNodeSet::Add(TElXMLDOMNode &ANode)
{
	int32_t OutResult;
	SBCheckError(TElXMLNodeSet_Add(_Handle, ANode.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLNodeSet::Add(TElXMLDOMNode *ANode)
{
	int32_t OutResult;
	SBCheckError(TElXMLNodeSet_Add(_Handle, (ANode != NULL) ? ANode->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
SB_INLINE void TElXMLNodeSet::Insert(int32_t Index, TElXMLDOMNode &ANode)
{
	SBCheckError(TElXMLNodeSet_Insert(_Handle, Index, ANode.getHandle()));
}

SB_INLINE void TElXMLNodeSet::Insert(int32_t Index, TElXMLDOMNode *ANode)
{
	SBCheckError(TElXMLNodeSet_Insert(_Handle, Index, (ANode != NULL) ? ANode->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

SB_INLINE void TElXMLNodeSet::Delete(int32_t Index)
{
	SBCheckError(TElXMLNodeSet_Delete(_Handle, Index));
}

SB_INLINE void TElXMLNodeSet::Clear()
{
	SBCheckError(TElXMLNodeSet_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
bool TElXMLNodeSet::HasNode(TElXMLDOMNode &Node)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLNodeSet_HasNode(_Handle, Node.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElXMLNodeSet::HasNode(TElXMLDOMNode *Node)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLNodeSet_HasNode(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
SB_INLINE int32_t TElXMLNodeSet::IndexOf(TElXMLDOMNode &Node)
{
	int32_t OutResult;
	SBCheckError(TElXMLNodeSet_IndexOf(_Handle, Node.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElXMLNodeSet::IndexOf(TElXMLDOMNode *Node)
{
	int32_t OutResult;
	SBCheckError(TElXMLNodeSet_IndexOf(_Handle, (Node != NULL) ? Node->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

SB_INLINE int32_t TElXMLNodeSet::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLNodeSet_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TElXMLDOMNode* TElXMLNodeSet::get_Node(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLNodeSet_get_Node(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Node)
		this->_Inst_Node = new TElXMLDOMNode(hOutResult, ohFalse);
	else
		this->_Inst_Node->updateHandle(hOutResult);
	return this->_Inst_Node;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

bool TElXMLNodeSet::get_OwnNodes()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLNodeSet_get_OwnNodes(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLNodeSet::set_OwnNodes(bool Value)
{
	SBCheckError(TElXMLNodeSet_set_OwnNodes(_Handle, (int8_t)Value));
}

void TElXMLNodeSet::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	this->_Inst_Node = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
}

TElXMLNodeSet::TElXMLNodeSet(TElXMLNodeSetHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLNodeSet::TElXMLNodeSet(bool AOwnNodes) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLNodeSet_Create((int8_t)AOwnNodes, &_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
TElXMLNodeSet::TElXMLNodeSet(TElXMLDOMNodeList &NodeList) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLNodeSet_Create_1(NodeList.getHandle(), &_Handle));
}

TElXMLNodeSet::TElXMLNodeSet(TElXMLDOMNodeList *NodeList) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLNodeSet_Create_1((NodeList != NULL) ? NodeList->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

TElXMLNodeSet::~TElXMLNodeSet()
{
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	delete this->_Inst_Node;
	this->_Inst_Node = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
}
#endif /* SB_USE_CLASS_TELXMLNODESET */

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TElXMLDOMNode* TElXMLDOMNodeList::get_Item(int32_t index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDOMNodeList_get_Item(_Handle, index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Item)
		this->_Inst_Item = new TElXMLDOMNode(hOutResult, ohFalse);
	else
		this->_Inst_Item->updateHandle(hOutResult);
	return this->_Inst_Item;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

SB_INLINE int32_t TElXMLDOMNodeList::get_Length()
{
	int32_t OutResult;
	SBCheckError(TElXMLDOMNodeList_get_Length(_Handle, &OutResult));
	return OutResult;
}

void TElXMLDOMNodeList::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	this->_Inst_Item = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
}

TElXMLDOMNodeList::TElXMLDOMNodeList(TElXMLDOMNodeListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TElXMLDOMNodeList::TElXMLDOMNodeList(TElXMLDOMNode &aNode, bool aOwnNode) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLDOMNodeList_Create(aNode.getHandle(), (int8_t)aOwnNode, &_Handle));
}

TElXMLDOMNodeList::TElXMLDOMNodeList(TElXMLDOMNode *aNode, bool aOwnNode) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLDOMNodeList_Create((aNode != NULL) ? aNode->getHandle() : SB_NULL_HANDLE, (int8_t)aOwnNode, &_Handle));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TElXMLDOMNodeList::TElXMLDOMNodeList(TElXMLDOMNode &aNode, const sb_u16string &aFilter, bool aOwnNode) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLDOMNodeList_Create_1(aNode.getHandle(), aFilter.data(), (int32_t)aFilter.length(), (int8_t)aOwnNode, &_Handle));
}

TElXMLDOMNodeList::TElXMLDOMNodeList(TElXMLDOMNode *aNode, const sb_u16string &aFilter, bool aOwnNode) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLDOMNodeList_Create_1((aNode != NULL) ? aNode->getHandle() : SB_NULL_HANDLE, aFilter.data(), (int32_t)aFilter.length(), (int8_t)aOwnNode, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLDOMNodeList::TElXMLDOMNodeList(TElXMLDOMNode &aNode, const std::wstring &aFilter, bool aOwnNode) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16aFilter;
	sb_to_u16string(aFilter, u16aFilter);
	SBCheckError(TElXMLDOMNodeList_Create_1(aNode.getHandle(), reinterpret_cast<const sb_char16_t*>(u16aFilter.data()), (int32_t)u16aFilter.length() >> 1, (int8_t)aOwnNode, &_Handle));
}

TElXMLDOMNodeList::TElXMLDOMNodeList(TElXMLDOMNode *aNode, const std::wstring &aFilter, bool aOwnNode) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16aFilter;
	sb_to_u16string(aFilter, u16aFilter);
	SBCheckError(TElXMLDOMNodeList_Create_1((aNode != NULL) ? aNode->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16aFilter.data()), (int32_t)u16aFilter.length() >> 1, (int8_t)aOwnNode, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
#ifdef SB_USE_CLASS_TELXMLDOMNODE
TElXMLDOMNodeList::TElXMLDOMNodeList(TElXMLDOMNode &aNode, const sb_u16string &aNSURI, const sb_u16string &aFilter, bool aOwnNode) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLDOMNodeList_Create_2(aNode.getHandle(), aNSURI.data(), (int32_t)aNSURI.length(), aFilter.data(), (int32_t)aFilter.length(), (int8_t)aOwnNode, &_Handle));
}

TElXMLDOMNodeList::TElXMLDOMNodeList(TElXMLDOMNode *aNode, const sb_u16string &aNSURI, const sb_u16string &aFilter, bool aOwnNode) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLDOMNodeList_Create_2((aNode != NULL) ? aNode->getHandle() : SB_NULL_HANDLE, aNSURI.data(), (int32_t)aNSURI.length(), aFilter.data(), (int32_t)aFilter.length(), (int8_t)aOwnNode, &_Handle));
}

#ifdef SB_U16STRING_USED
TElXMLDOMNodeList::TElXMLDOMNodeList(TElXMLDOMNode &aNode, const std::wstring &aNSURI, const std::wstring &aFilter, bool aOwnNode) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16aNSURI;
	sb_to_u16string(aNSURI, u16aNSURI);
	std::string u16aFilter;
	sb_to_u16string(aFilter, u16aFilter);
	SBCheckError(TElXMLDOMNodeList_Create_2(aNode.getHandle(), reinterpret_cast<const sb_char16_t*>(u16aNSURI.data()), (int32_t)u16aNSURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16aFilter.data()), (int32_t)u16aFilter.length() >> 1, (int8_t)aOwnNode, &_Handle));
}

TElXMLDOMNodeList::TElXMLDOMNodeList(TElXMLDOMNode *aNode, const std::wstring &aNSURI, const std::wstring &aFilter, bool aOwnNode) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	std::string u16aNSURI;
	sb_to_u16string(aNSURI, u16aNSURI);
	std::string u16aFilter;
	sb_to_u16string(aFilter, u16aFilter);
	SBCheckError(TElXMLDOMNodeList_Create_2((aNode != NULL) ? aNode->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16aNSURI.data()), (int32_t)u16aNSURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16aFilter.data()), (int32_t)u16aFilter.length() >> 1, (int8_t)aOwnNode, &_Handle));
}

#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
TElXMLDOMNodeList::~TElXMLDOMNodeList()
{
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	delete this->_Inst_Item;
	this->_Inst_Item = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
}
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

#ifdef SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP

SB_INLINE void TElXMLDOMNamedNodeMap::Clear()
{
	SBCheckError(TElXMLDOMNamedNodeMap_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMNODE
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNamedNodeMap::GetNamedItem(const sb_u16string &Name)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNamedNodeMap_GetNamedItem(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNamedNodeMap::GetNamedItem(const std::wstring &Name)
{
	TElXMLDOMNodeHandle OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	SBCheckError(TElXMLDOMNamedNodeMap_GetNamedItem(_Handle, reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNamedNodeMap::SetNamedItem(TElXMLDOMNode &arg)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNamedNodeMap_SetNamedItem(_Handle, arg.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNamedNodeMap::SetNamedItem(TElXMLDOMNode *arg)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNamedNodeMap_SetNamedItem(_Handle, (arg != NULL) ? arg->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNamedNodeMap::RemoveNamedItem(const sb_u16string &Name)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNamedNodeMap_RemoveNamedItem(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNamedNodeMap::RemoveNamedItem(const std::wstring &Name)
{
	TElXMLDOMNodeHandle OutResult;
	std::string u16Name;
	sb_to_u16string(Name, u16Name);
	SBCheckError(TElXMLDOMNamedNodeMap_RemoveNamedItem(_Handle, reinterpret_cast<const sb_char16_t*>(u16Name.data()), (int32_t)u16Name.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNamedNodeMap::GetNamedItemNS(const sb_u16string &aNSURI, const sb_u16string &aName)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNamedNodeMap_GetNamedItemNS(_Handle, aNSURI.data(), (int32_t)aNSURI.length(), aName.data(), (int32_t)aName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNamedNodeMap::GetNamedItemNS(const std::wstring &aNSURI, const std::wstring &aName)
{
	TElXMLDOMNodeHandle OutResult;
	std::string u16aNSURI;
	sb_to_u16string(aNSURI, u16aNSURI);
	std::string u16aName;
	sb_to_u16string(aName, u16aName);
	SBCheckError(TElXMLDOMNamedNodeMap_GetNamedItemNS(_Handle, reinterpret_cast<const sb_char16_t*>(u16aNSURI.data()), (int32_t)u16aNSURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16aName.data()), (int32_t)u16aName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNamedNodeMap::SetNamedItemNS(TElXMLDOMNode &arg)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNamedNodeMap_SetNamedItemNS(_Handle, arg.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNamedNodeMap::SetNamedItemNS(TElXMLDOMNode *arg)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNamedNodeMap_SetNamedItemNS(_Handle, (arg != NULL) ? arg->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNamedNodeMap::RemoveNamedItemNS(const sb_u16string &aNSURI, const sb_u16string &aName)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNamedNodeMap_RemoveNamedItemNS(_Handle, aNSURI.data(), (int32_t)aNSURI.length(), aName.data(), (int32_t)aName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNamedNodeMap::RemoveNamedItemNS(const std::wstring &aNSURI, const std::wstring &aName)
{
	TElXMLDOMNodeHandle OutResult;
	std::string u16aNSURI;
	sb_to_u16string(aNSURI, u16aNSURI);
	std::string u16aName;
	sb_to_u16string(aName, u16aName);
	SBCheckError(TElXMLDOMNamedNodeMap_RemoveNamedItemNS(_Handle, reinterpret_cast<const sb_char16_t*>(u16aNSURI.data()), (int32_t)u16aNSURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16aName.data()), (int32_t)u16aName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
TElXMLDOMNode* TElXMLDOMNamedNodeMap::get_Item(int32_t index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDOMNamedNodeMap_get_Item(_Handle, index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Item)
		this->_Inst_Item = new TElXMLDOMNode(hOutResult, ohFalse);
	else
		this->_Inst_Item->updateHandle(hOutResult);
	return this->_Inst_Item;
}

SB_INLINE void TElXMLDOMNamedNodeMap::set_Item(int32_t index, TElXMLDOMNode &aItem)
{
	SBCheckError(TElXMLDOMNamedNodeMap_set_Item(_Handle, index, aItem.getHandle()));
}

SB_INLINE void TElXMLDOMNamedNodeMap::set_Item(int32_t index, TElXMLDOMNode *aItem)
{
	SBCheckError(TElXMLDOMNamedNodeMap_set_Item(_Handle, index, (aItem != NULL) ? aItem->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

SB_INLINE int32_t TElXMLDOMNamedNodeMap::get_Length()
{
	int32_t OutResult;
	SBCheckError(TElXMLDOMNamedNodeMap_get_Length(_Handle, &OutResult));
	return OutResult;
}

void TElXMLDOMNamedNodeMap::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	this->_Inst_Item = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
}

TElXMLDOMNamedNodeMap::TElXMLDOMNamedNodeMap(TElXMLDOMNamedNodeMapHandle handle, TElOwnHandle ownHandle) : TList(handle, ownHandle)
{
	initInstances();
}

TElXMLDOMNamedNodeMap::TElXMLDOMNamedNodeMap() : TList(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLDOMNamedNodeMap_Create(&_Handle));
}

TElXMLDOMNamedNodeMap::~TElXMLDOMNamedNodeMap()
{
#ifdef SB_USE_CLASS_TELXMLDOMNODE
	delete this->_Inst_Item;
	this->_Inst_Item = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
}
#endif /* SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP */

#ifdef SB_USE_CLASS_TELXMLDOMCHARACTERDATA

SB_INLINE void TElXMLDOMCharacterData::UnloadData(TElXMLDelayLoadMode DataToUnload)
{
	SBCheckError(TElXMLDOMCharacterData_UnloadData(_Handle, (TElXMLDelayLoadModeRaw)DataToUnload));
}

void TElXMLDOMCharacterData::SubstringData(int32_t ofs, int32_t len, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMCharacterData_SubstringData(_Handle, ofs, len, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(88213114, 3, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLDOMCharacterData::SubstringData(int32_t ofs, int32_t len, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMCharacterData_SubstringData(_Handle, ofs, len, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(88213114, 3, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLDOMCharacterData::AppendData(const sb_u16string &arg)
{
	SBCheckError(TElXMLDOMCharacterData_AppendData(_Handle, arg.data(), (int32_t)arg.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDOMCharacterData::AppendData(const std::wstring &arg)
{
	std::string u16arg;
	sb_to_u16string(arg, u16arg);
	SBCheckError(TElXMLDOMCharacterData_AppendData(_Handle, reinterpret_cast<const sb_char16_t*>(u16arg.data()), (int32_t)u16arg.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLDOMCharacterData::InsertData(int32_t ofs, const sb_u16string &arg)
{
	SBCheckError(TElXMLDOMCharacterData_InsertData(_Handle, ofs, arg.data(), (int32_t)arg.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDOMCharacterData::InsertData(int32_t ofs, const std::wstring &arg)
{
	std::string u16arg;
	sb_to_u16string(arg, u16arg);
	SBCheckError(TElXMLDOMCharacterData_InsertData(_Handle, ofs, reinterpret_cast<const sb_char16_t*>(u16arg.data()), (int32_t)u16arg.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLDOMCharacterData::DeleteData(int32_t ofs, int32_t len)
{
	SBCheckError(TElXMLDOMCharacterData_DeleteData(_Handle, ofs, len));
}

SB_INLINE void TElXMLDOMCharacterData::ReplaceData(int32_t ofs, int32_t len, const sb_u16string &arg)
{
	SBCheckError(TElXMLDOMCharacterData_ReplaceData(_Handle, ofs, len, arg.data(), (int32_t)arg.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDOMCharacterData::ReplaceData(int32_t ofs, int32_t len, const std::wstring &arg)
{
	std::string u16arg;
	sb_to_u16string(arg, u16arg);
	SBCheckError(TElXMLDOMCharacterData_ReplaceData(_Handle, ofs, len, reinterpret_cast<const sb_char16_t*>(u16arg.data()), (int32_t)u16arg.length() >> 1));
}
#endif /* SB_U16STRING_USED */

void TElXMLDOMCharacterData::get_Data(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMCharacterData_get_Data(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(535713726, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMCharacterData::get_Data(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMCharacterData_get_Data(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(535713726, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE int32_t TElXMLDOMCharacterData::get_Length()
{
	int32_t OutResult;
	SBCheckError(TElXMLDOMCharacterData_get_Length(_Handle, &OutResult));
	return OutResult;
}

TElXMLDOMCharacterData::TElXMLDOMCharacterData(TElXMLDOMCharacterDataHandle handle, TElOwnHandle ownHandle) : TElXMLDOMNode(handle, ownHandle)
{
}

TElXMLDOMCharacterData::TElXMLDOMCharacterData() : TElXMLDOMNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLDOMCharacterData_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLDOMCHARACTERDATA */

#ifdef SB_USE_CLASS_TELXMLDOMATTR

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMAttr::CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMAttr_CloneNode(_Handle, (int8_t)Deep, aCloneOwner.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMAttr::CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMAttr_CloneNode(_Handle, (int8_t)Deep, (aCloneOwner != NULL) ? aCloneOwner->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

SB_INLINE sb_char16_t TElXMLDOMAttr::get_Quote()
{
	sb_char16_t OutResult;
	SBCheckError(TElXMLDOMAttr_get_Quote(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLDOMAttr::set_Quote(sb_char16_t Value)
{
	SBCheckError(TElXMLDOMAttr_set_Quote(_Handle, Value));
}

void TElXMLDOMAttr::get_Value(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMAttr_get_Value(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1649904999, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMAttr::get_Value(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMAttr_get_Value(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1649904999, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLDOMAttr::set_Value(const sb_u16string &Value)
{
	SBCheckError(TElXMLDOMAttr_set_Value(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDOMAttr::set_Value(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLDOMAttr_set_Value(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElement* TElXMLDOMAttr::get_OwnerElement()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDOMAttr_get_OwnerElement(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OwnerElement)
		this->_Inst_OwnerElement = new TElXMLDOMElement(hOutResult, ohFalse);
	else
		this->_Inst_OwnerElement->updateHandle(hOutResult);
	return this->_Inst_OwnerElement;
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void TElXMLDOMAttr::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	this->_Inst_OwnerElement = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
}

TElXMLDOMAttr::TElXMLDOMAttr(TElXMLDOMAttrHandle handle, TElOwnHandle ownHandle) : TElXMLDOMNode(handle, ownHandle)
{
	initInstances();
}

TElXMLDOMAttr::TElXMLDOMAttr() : TElXMLDOMNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLDOMAttr_Create(&_Handle));
}

TElXMLDOMAttr::~TElXMLDOMAttr()
{
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	delete this->_Inst_OwnerElement;
	this->_Inst_OwnerElement = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
}
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMElement::CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMElement_CloneNode(_Handle, (int8_t)Deep, aCloneOwner.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMElement::CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMElement_CloneNode(_Handle, (int8_t)Deep, (aCloneOwner != NULL) ? aCloneOwner->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

SB_INLINE void TElXMLDOMElement::RemoveAttribute(const sb_u16string &aName)
{
	SBCheckError(TElXMLDOMElement_RemoveAttribute(_Handle, aName.data(), (int32_t)aName.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDOMElement::RemoveAttribute(const std::wstring &aName)
{
	std::string u16aName;
	sb_to_u16string(aName, u16aName);
	SBCheckError(TElXMLDOMElement_RemoveAttribute(_Handle, reinterpret_cast<const sb_char16_t*>(u16aName.data()), (int32_t)u16aName.length() >> 1));
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLDOMATTR
SB_INLINE TElXMLDOMAttrHandle TElXMLDOMElement::GetAttributeNode(const sb_u16string &aName)
{
	TElXMLDOMAttrHandle OutResult;
	SBCheckError(TElXMLDOMElement_GetAttributeNode(_Handle, aName.data(), (int32_t)aName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMAttrHandle TElXMLDOMElement::GetAttributeNode(const std::wstring &aName)
{
	TElXMLDOMAttrHandle OutResult;
	std::string u16aName;
	sb_to_u16string(aName, u16aName);
	SBCheckError(TElXMLDOMElement_GetAttributeNode(_Handle, reinterpret_cast<const sb_char16_t*>(u16aName.data()), (int32_t)u16aName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

#ifdef SB_USE_CLASS_TELXMLDOMATTR
SB_INLINE TElXMLDOMAttrHandle TElXMLDOMElement::SetAttributeNode(TElXMLDOMAttr &aNewAttr)
{
	TElXMLDOMAttrHandle OutResult;
	SBCheckError(TElXMLDOMElement_SetAttributeNode(_Handle, aNewAttr.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMAttrHandle TElXMLDOMElement::SetAttributeNode(TElXMLDOMAttr *aNewAttr)
{
	TElXMLDOMAttrHandle OutResult;
	SBCheckError(TElXMLDOMElement_SetAttributeNode(_Handle, (aNewAttr != NULL) ? aNewAttr->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

#ifdef SB_USE_CLASS_TELXMLDOMATTR
SB_INLINE TElXMLDOMAttrHandle TElXMLDOMElement::RemoveAttributeNode(TElXMLDOMAttr &aOldAttr)
{
	TElXMLDOMAttrHandle OutResult;
	SBCheckError(TElXMLDOMElement_RemoveAttributeNode(_Handle, aOldAttr.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMAttrHandle TElXMLDOMElement::RemoveAttributeNode(TElXMLDOMAttr *aOldAttr)
{
	TElXMLDOMAttrHandle OutResult;
	SBCheckError(TElXMLDOMElement_RemoveAttributeNode(_Handle, (aOldAttr != NULL) ? aOldAttr->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
SB_INLINE TElXMLDOMNodeListHandle TElXMLDOMElement::GetElementsByTagName(const sb_u16string &aName)
{
	TElXMLDOMNodeListHandle OutResult;
	SBCheckError(TElXMLDOMElement_GetElementsByTagName(_Handle, aName.data(), (int32_t)aName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMNodeListHandle TElXMLDOMElement::GetElementsByTagName(const std::wstring &aName)
{
	TElXMLDOMNodeListHandle OutResult;
	std::string u16aName;
	sb_to_u16string(aName, u16aName);
	SBCheckError(TElXMLDOMElement_GetElementsByTagName(_Handle, reinterpret_cast<const sb_char16_t*>(u16aName.data()), (int32_t)u16aName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

bool TElXMLDOMElement::HasAttributes()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDOMElement_HasAttributes(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElXMLDOMElement::GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMElement_GetOuterXMLCanonical(_Handle, (TElXMLCanonicalizationMethodRaw)aMethod, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-979734305, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLDOMElement::GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMElement_GetOuterXMLCanonical(_Handle, (TElXMLCanonicalizationMethodRaw)aMethod, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-979734305, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLDOMElement::GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, const sb_u16string &InclNSPrefixList, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMElement_GetOuterXMLCanonical_1(_Handle, (TElXMLCanonicalizationMethodRaw)aMethod, InclNSPrefixList.data(), (int32_t)InclNSPrefixList.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1637498795, 3, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLDOMElement::GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, const std::wstring &InclNSPrefixList, std::wstring &OutResult)
{
	std::string u16InclNSPrefixList;
	sb_to_u16string(InclNSPrefixList, u16InclNSPrefixList);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMElement_GetOuterXMLCanonical_1(_Handle, (TElXMLCanonicalizationMethodRaw)aMethod, reinterpret_cast<const sb_char16_t*>(u16InclNSPrefixList.data()), (int32_t)u16InclNSPrefixList.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1637498795, 3, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLDOMElement::GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, TElXMLDOMNode &ReferenceNode, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMElement_GetOuterXMLCanonical_2(_Handle, (TElXMLCanonicalizationMethodRaw)aMethod, ReferenceNode.getHandle(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-977352571, 3, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLDOMElement::GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, TElXMLDOMNode *ReferenceNode, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMElement_GetOuterXMLCanonical_2(_Handle, (TElXMLCanonicalizationMethodRaw)aMethod, (ReferenceNode != NULL) ? ReferenceNode->getHandle() : SB_NULL_HANDLE, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-977352571, 3, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLDOMElement::GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, TElXMLDOMNode &ReferenceNode, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMElement_GetOuterXMLCanonical_2(_Handle, (TElXMLCanonicalizationMethodRaw)aMethod, ReferenceNode.getHandle(), NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-977352571, 3, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

void TElXMLDOMElement::GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, TElXMLDOMNode *ReferenceNode, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMElement_GetOuterXMLCanonical_2(_Handle, (TElXMLCanonicalizationMethodRaw)aMethod, (ReferenceNode != NULL) ? ReferenceNode->getHandle() : SB_NULL_HANDLE, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-977352571, 3, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLDOMElement::GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, const sb_u16string &InclNSPrefixList, TElXMLDOMNode &ReferenceNode, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMElement_GetOuterXMLCanonical_3(_Handle, (TElXMLCanonicalizationMethodRaw)aMethod, InclNSPrefixList.data(), (int32_t)InclNSPrefixList.length(), ReferenceNode.getHandle(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1584340673, 4, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElXMLDOMElement::GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, const sb_u16string &InclNSPrefixList, TElXMLDOMNode *ReferenceNode, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMElement_GetOuterXMLCanonical_3(_Handle, (TElXMLCanonicalizationMethodRaw)aMethod, InclNSPrefixList.data(), (int32_t)InclNSPrefixList.length(), (ReferenceNode != NULL) ? ReferenceNode->getHandle() : SB_NULL_HANDLE, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1584340673, 4, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLDOMElement::GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, const std::wstring &InclNSPrefixList, TElXMLDOMNode &ReferenceNode, std::wstring &OutResult)
{
	std::string u16InclNSPrefixList;
	sb_to_u16string(InclNSPrefixList, u16InclNSPrefixList);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMElement_GetOuterXMLCanonical_3(_Handle, (TElXMLCanonicalizationMethodRaw)aMethod, reinterpret_cast<const sb_char16_t*>(u16InclNSPrefixList.data()), (int32_t)u16InclNSPrefixList.length() >> 1, ReferenceNode.getHandle(), NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1584340673, 4, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

void TElXMLDOMElement::GetOuterXMLCanonical(TElXMLCanonicalizationMethod aMethod, const std::wstring &InclNSPrefixList, TElXMLDOMNode *ReferenceNode, std::wstring &OutResult)
{
	std::string u16InclNSPrefixList;
	sb_to_u16string(InclNSPrefixList, u16InclNSPrefixList);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMElement_GetOuterXMLCanonical_3(_Handle, (TElXMLCanonicalizationMethodRaw)aMethod, reinterpret_cast<const sb_char16_t*>(u16InclNSPrefixList.data()), (int32_t)u16InclNSPrefixList.length() >> 1, (ReferenceNode != NULL) ? ReferenceNode->getHandle() : SB_NULL_HANDLE, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1584340673, 4, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLDOMElement::InnerText(const sb_u16string &Separator, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMElement_InnerText(_Handle, Separator.data(), (int32_t)Separator.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1310739780, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLDOMElement::InnerText(const std::wstring &Separator, std::wstring &OutResult)
{
	std::string u16Separator;
	sb_to_u16string(Separator, u16Separator);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMElement_InnerText(_Handle, reinterpret_cast<const sb_char16_t*>(u16Separator.data()), (int32_t)u16Separator.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1310739780, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLDOMElement::GetAttribute(const sb_u16string &aName, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMElement_GetAttribute(_Handle, aName.data(), (int32_t)aName.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1444231553, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLDOMElement::GetAttribute(const std::wstring &aName, std::wstring &OutResult)
{
	std::string u16aName;
	sb_to_u16string(aName, u16aName);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMElement_GetAttribute(_Handle, reinterpret_cast<const sb_char16_t*>(u16aName.data()), (int32_t)u16aName.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1444231553, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLDOMElement::SetAttribute(const sb_u16string &aName, const sb_u16string &aValue)
{
	SBCheckError(TElXMLDOMElement_SetAttribute(_Handle, aName.data(), (int32_t)aName.length(), aValue.data(), (int32_t)aValue.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDOMElement::SetAttribute(const std::wstring &aName, const std::wstring &aValue)
{
	std::string u16aName;
	sb_to_u16string(aName, u16aName);
	std::string u16aValue;
	sb_to_u16string(aValue, u16aValue);
	SBCheckError(TElXMLDOMElement_SetAttribute(_Handle, reinterpret_cast<const sb_char16_t*>(u16aName.data()), (int32_t)u16aName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16aValue.data()), (int32_t)u16aValue.length() >> 1));
}
#endif /* SB_U16STRING_USED */

void TElXMLDOMElement::GetAttributeNS(const sb_u16string &aNSURI, const sb_u16string &aName, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMElement_GetAttributeNS(_Handle, aNSURI.data(), (int32_t)aNSURI.length(), aName.data(), (int32_t)aName.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1177147603, 3, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLDOMElement::GetAttributeNS(const std::wstring &aNSURI, const std::wstring &aName, std::wstring &OutResult)
{
	std::string u16aNSURI;
	sb_to_u16string(aNSURI, u16aNSURI);
	std::string u16aName;
	sb_to_u16string(aName, u16aName);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMElement_GetAttributeNS(_Handle, reinterpret_cast<const sb_char16_t*>(u16aNSURI.data()), (int32_t)u16aNSURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16aName.data()), (int32_t)u16aName.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1177147603, 3, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLDOMElement::SetAttributeNS(const sb_u16string &aNSURI, const sb_u16string &aName, const sb_u16string &aValue)
{
	SBCheckError(TElXMLDOMElement_SetAttributeNS(_Handle, aNSURI.data(), (int32_t)aNSURI.length(), aName.data(), (int32_t)aName.length(), aValue.data(), (int32_t)aValue.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDOMElement::SetAttributeNS(const std::wstring &aNSURI, const std::wstring &aName, const std::wstring &aValue)
{
	std::string u16aNSURI;
	sb_to_u16string(aNSURI, u16aNSURI);
	std::string u16aName;
	sb_to_u16string(aName, u16aName);
	std::string u16aValue;
	sb_to_u16string(aValue, u16aValue);
	SBCheckError(TElXMLDOMElement_SetAttributeNS(_Handle, reinterpret_cast<const sb_char16_t*>(u16aNSURI.data()), (int32_t)u16aNSURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16aName.data()), (int32_t)u16aName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16aValue.data()), (int32_t)u16aValue.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLDOMElement::RemoveAttributeNS(const sb_u16string &aNSURI, const sb_u16string &aName)
{
	SBCheckError(TElXMLDOMElement_RemoveAttributeNS(_Handle, aNSURI.data(), (int32_t)aNSURI.length(), aName.data(), (int32_t)aName.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDOMElement::RemoveAttributeNS(const std::wstring &aNSURI, const std::wstring &aName)
{
	std::string u16aNSURI;
	sb_to_u16string(aNSURI, u16aNSURI);
	std::string u16aName;
	sb_to_u16string(aName, u16aName);
	SBCheckError(TElXMLDOMElement_RemoveAttributeNS(_Handle, reinterpret_cast<const sb_char16_t*>(u16aNSURI.data()), (int32_t)u16aNSURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16aName.data()), (int32_t)u16aName.length() >> 1));
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELXMLDOMATTR
SB_INLINE TElXMLDOMAttrHandle TElXMLDOMElement::GetAttributeNodeNS(const sb_u16string &aNSURI, const sb_u16string &aName)
{
	TElXMLDOMAttrHandle OutResult;
	SBCheckError(TElXMLDOMElement_GetAttributeNodeNS(_Handle, aNSURI.data(), (int32_t)aNSURI.length(), aName.data(), (int32_t)aName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMAttrHandle TElXMLDOMElement::GetAttributeNodeNS(const std::wstring &aNSURI, const std::wstring &aName)
{
	TElXMLDOMAttrHandle OutResult;
	std::string u16aNSURI;
	sb_to_u16string(aNSURI, u16aNSURI);
	std::string u16aName;
	sb_to_u16string(aName, u16aName);
	SBCheckError(TElXMLDOMElement_GetAttributeNodeNS(_Handle, reinterpret_cast<const sb_char16_t*>(u16aNSURI.data()), (int32_t)u16aNSURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16aName.data()), (int32_t)u16aName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

#ifdef SB_USE_CLASS_TELXMLDOMATTR
SB_INLINE TElXMLDOMAttrHandle TElXMLDOMElement::SetAttributeNodeNS(TElXMLDOMAttr &aNewAttr)
{
	TElXMLDOMAttrHandle OutResult;
	SBCheckError(TElXMLDOMElement_SetAttributeNodeNS(_Handle, aNewAttr.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMAttrHandle TElXMLDOMElement::SetAttributeNodeNS(TElXMLDOMAttr *aNewAttr)
{
	TElXMLDOMAttrHandle OutResult;
	SBCheckError(TElXMLDOMElement_SetAttributeNodeNS(_Handle, (aNewAttr != NULL) ? aNewAttr->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMATTR */

#ifdef SB_USE_CLASS_TELXMLDOMNODELIST
SB_INLINE TElXMLDOMNodeListHandle TElXMLDOMElement::GetElementsByTagNameNS(const sb_u16string &aNSURI, const sb_u16string &aName)
{
	TElXMLDOMNodeListHandle OutResult;
	SBCheckError(TElXMLDOMElement_GetElementsByTagNameNS(_Handle, aNSURI.data(), (int32_t)aNSURI.length(), aName.data(), (int32_t)aName.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElXMLDOMNodeListHandle TElXMLDOMElement::GetElementsByTagNameNS(const std::wstring &aNSURI, const std::wstring &aName)
{
	TElXMLDOMNodeListHandle OutResult;
	std::string u16aNSURI;
	sb_to_u16string(aNSURI, u16aNSURI);
	std::string u16aName;
	sb_to_u16string(aName, u16aName);
	SBCheckError(TElXMLDOMElement_GetElementsByTagNameNS(_Handle, reinterpret_cast<const sb_char16_t*>(u16aNSURI.data()), (int32_t)u16aNSURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16aName.data()), (int32_t)u16aName.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMNODELIST */

bool TElXMLDOMElement::HasAttribute(const sb_u16string &aName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDOMElement_HasAttribute(_Handle, aName.data(), (int32_t)aName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLDOMElement::HasAttribute(const std::wstring &aName)
{
	std::string u16aName;
	sb_to_u16string(aName, u16aName);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDOMElement_HasAttribute(_Handle, reinterpret_cast<const sb_char16_t*>(u16aName.data()), (int32_t)u16aName.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

bool TElXMLDOMElement::HasAttributeNS(const sb_u16string &aNSURI, const sb_u16string &aName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDOMElement_HasAttributeNS(_Handle, aNSURI.data(), (int32_t)aNSURI.length(), aName.data(), (int32_t)aName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLDOMElement::HasAttributeNS(const std::wstring &aNSURI, const std::wstring &aName)
{
	std::string u16aNSURI;
	sb_to_u16string(aNSURI, u16aNSURI);
	std::string u16aName;
	sb_to_u16string(aName, u16aName);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLDOMElement_HasAttributeNS(_Handle, reinterpret_cast<const sb_char16_t*>(u16aNSURI.data()), (int32_t)u16aNSURI.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16aName.data()), (int32_t)u16aName.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

void TElXMLDOMElement::GetCurrentNSURI(const sb_u16string &s, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMElement_GetCurrentNSURI(_Handle, s.data(), (int32_t)s.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-413432038, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLDOMElement::GetCurrentNSURI(const std::wstring &s, std::wstring &OutResult)
{
	std::string u16s;
	sb_to_u16string(s, u16s);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMElement_GetCurrentNSURI(_Handle, reinterpret_cast<const sb_char16_t*>(u16s.data()), (int32_t)u16s.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-413432038, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLDOMElement::get_TextContent(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMElement_get_TextContent(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(779962570, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMElement::get_TextContent(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMElement_get_TextContent(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(779962570, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLDOMElement::set_TextContent(const sb_u16string &Value)
{
	SBCheckError(TElXMLDOMElement_set_TextContent(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDOMElement::set_TextContent(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLDOMElement_set_TextContent(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLDOMElement::get_InnerXML(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMElement_get_InnerXML(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1872307175, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMElement::get_InnerXML(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMElement_get_InnerXML(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1872307175, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLDOMElement::set_InnerXML(const sb_u16string &Value)
{
	SBCheckError(TElXMLDOMElement_set_InnerXML(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDOMElement::set_InnerXML(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLDOMElement_set_InnerXML(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
void TElXMLDOMElement::get_AttribStrings(const sb_u16string &aName, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMElement_get_AttribStrings(_Handle, aName.data(), (int32_t)aName.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(174248822, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMElement::get_AttribStrings(const std::wstring &aName, std::wstring &OutResult)
{
	std::string u16aName;
	sb_to_u16string(aName, u16aName);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMElement_get_AttribStrings(_Handle, reinterpret_cast<const sb_char16_t*>(u16aName.data()), (int32_t)u16aName.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(174248822, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElXMLDOMElement::set_AttribStrings(const sb_u16string &aName, const sb_u16string &aValue)
{
	SBCheckError(TElXMLDOMElement_set_AttribStrings(_Handle, aName.data(), (int32_t)aName.length(), aValue.data(), (int32_t)aValue.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDOMElement::set_AttribStrings(const std::wstring &aName, const std::wstring &aValue)
{
	std::string u16aName;
	sb_to_u16string(aName, u16aName);
	std::string u16aValue;
	sb_to_u16string(aValue, u16aValue);
	SBCheckError(TElXMLDOMElement_set_AttribStrings(_Handle, reinterpret_cast<const sb_char16_t*>(u16aName.data()), (int32_t)u16aName.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16aValue.data()), (int32_t)u16aValue.length() >> 1));
}

#endif /* SB_U16STRING_USED */
TElXMLDOMElement::TElXMLDOMElement(TElXMLDOMElementHandle handle, TElOwnHandle ownHandle) : TElXMLDOMNode(handle, ownHandle)
{
}

TElXMLDOMElement::TElXMLDOMElement() : TElXMLDOMNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLDOMElement_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMTEXT

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMText::CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMText_CloneNode(_Handle, (int8_t)Deep, aCloneOwner.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMText::CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMText_CloneNode(_Handle, (int8_t)Deep, (aCloneOwner != NULL) ? aCloneOwner->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

SB_INLINE TElXMLDOMTextHandle TElXMLDOMText::SplitText(int32_t ofs)
{
	TElXMLDOMTextHandle OutResult;
	SBCheckError(TElXMLDOMText_SplitText(_Handle, ofs, &OutResult));
	return OutResult;
}

TElXMLDOMText::TElXMLDOMText(TElXMLDOMTextHandle handle, TElOwnHandle ownHandle) : TElXMLDOMCharacterData(handle, ownHandle)
{
}

TElXMLDOMText::TElXMLDOMText() : TElXMLDOMCharacterData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLDOMText_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLDOMTEXT */

#ifdef SB_USE_CLASS_TELXMLDOMCOMMENT

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMComment::CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMComment_CloneNode(_Handle, (int8_t)Deep, aCloneOwner.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMComment::CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMComment_CloneNode(_Handle, (int8_t)Deep, (aCloneOwner != NULL) ? aCloneOwner->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

TElXMLDOMComment::TElXMLDOMComment(TElXMLDOMCommentHandle handle, TElOwnHandle ownHandle) : TElXMLDOMCharacterData(handle, ownHandle)
{
}

TElXMLDOMComment::TElXMLDOMComment() : TElXMLDOMCharacterData(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLDOMComment_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLDOMCOMMENT */

#ifdef SB_USE_CLASS_TELXMLDOMCDATASECTION

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMCDATASection::CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMCDATASection_CloneNode(_Handle, (int8_t)Deep, aCloneOwner.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMCDATASection::CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMCDATASection_CloneNode(_Handle, (int8_t)Deep, (aCloneOwner != NULL) ? aCloneOwner->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

TElXMLDOMCDATASection::TElXMLDOMCDATASection(TElXMLDOMCDATASectionHandle handle, TElOwnHandle ownHandle) : TElXMLDOMText(handle, ownHandle)
{
}

TElXMLDOMCDATASection::TElXMLDOMCDATASection() : TElXMLDOMText(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLDOMCDATASection_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLDOMCDATASECTION */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMDocumentType::CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMDocumentType_CloneNode(_Handle, (int8_t)Deep, aCloneOwner.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMDocumentType::CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMDocumentType_CloneNode(_Handle, (int8_t)Deep, (aCloneOwner != NULL) ? aCloneOwner->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

SB_INLINE void TElXMLDOMDocumentType::ResolveExternalDTD(const sb_u16string &Value)
{
	SBCheckError(TElXMLDOMDocumentType_ResolveExternalDTD(_Handle, Value.data(), (int32_t)Value.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLDOMDocumentType::ResolveExternalDTD(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElXMLDOMDocumentType_ResolveExternalDTD(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}
#endif /* SB_U16STRING_USED */

void TElXMLDOMDocumentType::get_Name(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMDocumentType_get_Name(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-949583848, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMDocumentType::get_Name(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMDocumentType_get_Name(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-949583848, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP
TElXMLDOMNamedNodeMap* TElXMLDOMDocumentType::get_Entities()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDOMDocumentType_get_Entities(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Entities)
		this->_Inst_Entities = new TElXMLDOMNamedNodeMap(hOutResult, ohFalse);
	else
		this->_Inst_Entities->updateHandle(hOutResult);
	return this->_Inst_Entities;
}
#endif /* SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP */

#ifdef SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP
TElXMLDOMNamedNodeMap* TElXMLDOMDocumentType::get_Notations()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLDOMDocumentType_get_Notations(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Notations)
		this->_Inst_Notations = new TElXMLDOMNamedNodeMap(hOutResult, ohFalse);
	else
		this->_Inst_Notations->updateHandle(hOutResult);
	return this->_Inst_Notations;
}
#endif /* SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP */

void TElXMLDOMDocumentType::get_PublicID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMDocumentType_get_PublicID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(409733271, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMDocumentType::get_PublicID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMDocumentType_get_PublicID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(409733271, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLDOMDocumentType::get_SystemID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMDocumentType_get_SystemID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1995310385, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMDocumentType::get_SystemID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMDocumentType_get_SystemID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1995310385, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLDOMDocumentType::get_InternalSubset(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMDocumentType_get_InternalSubset(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1694089611, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMDocumentType::get_InternalSubset(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMDocumentType_get_InternalSubset(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1694089611, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLDOMDocumentType::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP
	this->_Inst_Entities = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP */
#ifdef SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP
	this->_Inst_Notations = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP */
}

TElXMLDOMDocumentType::TElXMLDOMDocumentType(TElXMLDOMDocumentTypeHandle handle, TElOwnHandle ownHandle) : TElXMLDOMNode(handle, ownHandle)
{
	initInstances();
}

TElXMLDOMDocumentType::TElXMLDOMDocumentType() : TElXMLDOMNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLDOMDocumentType_Create(&_Handle));
}

TElXMLDOMDocumentType::~TElXMLDOMDocumentType()
{
#ifdef SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP
	delete this->_Inst_Entities;
	this->_Inst_Entities = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP */
#ifdef SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP
	delete this->_Inst_Notations;
	this->_Inst_Notations = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMNAMEDNODEMAP */
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENTTYPE */

#ifdef SB_USE_CLASS_TELXMLDOMNOTATION

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNotation::CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNotation_CloneNode(_Handle, (int8_t)Deep, aCloneOwner.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMNotation::CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMNotation_CloneNode(_Handle, (int8_t)Deep, (aCloneOwner != NULL) ? aCloneOwner->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

void TElXMLDOMNotation::get_PublicID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMNotation_get_PublicID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1798530777, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMNotation::get_PublicID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMNotation_get_PublicID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1798530777, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLDOMNotation::get_SystemID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMNotation_get_SystemID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-95513471, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMNotation::get_SystemID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMNotation_get_SystemID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-95513471, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
TElXMLDOMNotation::TElXMLDOMNotation(TElXMLDOMNotationHandle handle, TElOwnHandle ownHandle) : TElXMLDOMNode(handle, ownHandle)
{
}

TElXMLDOMNotation::TElXMLDOMNotation() : TElXMLDOMNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLDOMNotation_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLDOMNOTATION */

#ifdef SB_USE_CLASS_TELXMLDOMENTITY

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMEntity::CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMEntity_CloneNode(_Handle, (int8_t)Deep, aCloneOwner.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMEntity::CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMEntity_CloneNode(_Handle, (int8_t)Deep, (aCloneOwner != NULL) ? aCloneOwner->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

void TElXMLDOMEntity::get_PublicID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMEntity_get_PublicID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1369956361, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMEntity::get_PublicID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMEntity_get_PublicID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1369956361, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLDOMEntity::get_SystemID(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMEntity_get_SystemID(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1059450287, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMEntity::get_SystemID(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMEntity_get_SystemID(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1059450287, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLDOMEntity::get_NotationName(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMEntity_get_NotationName(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-78150741, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMEntity::get_NotationName(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMEntity_get_NotationName(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-78150741, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
TElXMLDOMEntity::TElXMLDOMEntity(TElXMLDOMEntityHandle handle, TElOwnHandle ownHandle) : TElXMLDOMNode(handle, ownHandle)
{
}

TElXMLDOMEntity::TElXMLDOMEntity() : TElXMLDOMNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLDOMEntity_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLDOMENTITY */

#ifdef SB_USE_CLASS_TELXMLDOMENTITYREFERENCE

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMEntityReference::CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMEntityReference_CloneNode(_Handle, (int8_t)Deep, aCloneOwner.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMEntityReference::CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMEntityReference_CloneNode(_Handle, (int8_t)Deep, (aCloneOwner != NULL) ? aCloneOwner->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

TElXMLDOMEntityReference::TElXMLDOMEntityReference(TElXMLDOMEntityReferenceHandle handle, TElOwnHandle ownHandle) : TElXMLDOMNode(handle, ownHandle)
{
}

TElXMLDOMEntityReference::TElXMLDOMEntityReference() : TElXMLDOMNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLDOMEntityReference_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLDOMENTITYREFERENCE */

#ifdef SB_USE_CLASS_TELXMLDOMPROCESSINGINSTRUCTION

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
SB_INLINE TElXMLDOMNodeHandle TElXMLDOMProcessingInstruction::CloneNode(bool Deep, TElXMLDOMDocument &aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMProcessingInstruction_CloneNode(_Handle, (int8_t)Deep, aCloneOwner.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMNodeHandle TElXMLDOMProcessingInstruction::CloneNode(bool Deep, TElXMLDOMDocument *aCloneOwner)
{
	TElXMLDOMNodeHandle OutResult;
	SBCheckError(TElXMLDOMProcessingInstruction_CloneNode(_Handle, (int8_t)Deep, (aCloneOwner != NULL) ? aCloneOwner->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

void TElXMLDOMProcessingInstruction::get_Target(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMProcessingInstruction_get_Target(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1263917797, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMProcessingInstruction::get_Target(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMProcessingInstruction_get_Target(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1263917797, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLDOMProcessingInstruction::get_Data(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLDOMProcessingInstruction_get_Data(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1065500280, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLDOMProcessingInstruction::get_Data(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLDOMProcessingInstruction_get_Data(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1065500280, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
TElXMLDOMProcessingInstruction::TElXMLDOMProcessingInstruction(TElXMLDOMProcessingInstructionHandle handle, TElOwnHandle ownHandle) : TElXMLDOMNode(handle, ownHandle)
{
}

TElXMLDOMProcessingInstruction::TElXMLDOMProcessingInstruction() : TElXMLDOMNode(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLDOMProcessingInstruction_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLDOMPROCESSINGINSTRUCTION */

#ifdef SB_USE_CLASS_TELXMLPARSER

SB_INLINE void TElXMLParser::RaiseExc(const std::string &aMsg)
{
	SBCheckError(TElXMLParser_RaiseExc(_Handle, aMsg.data(), (int32_t)aMsg.length()));
}

SB_INLINE void TElXMLParser::InitStream(const std::string &DefaultEncoding)
{
	SBCheckError(TElXMLParser_InitStream(_Handle, DefaultEncoding.data(), (int32_t)DefaultEncoding.length()));
}

void TElXMLParser::bufInit(sb_u16string &aArg)
{
	int32_t szaArg = (int32_t)aArg.length();
	uint32_t _err = TElXMLParser_bufInit(_Handle, (sb_char16_t *)aArg.data(), &szaArg);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		aArg.resize(szaArg);
		SBCheckError(SBGetLastReturnStringW(-1754624660, 1, (sb_char16_t *)aArg.data(), &szaArg));
	}
	else
		SBCheckError(_err);

	aArg.resize(szaArg);
}
#ifdef SB_U16STRING_USED
void TElXMLParser::bufInit(std::wstring &aArg)
{
	std::string u16aArg;
	sb_to_u16string(aArg, u16aArg);
	int32_t szaArg = (int32_t)u16aArg.length() >> 1;
	uint32_t _err = TElXMLParser_bufInit(_Handle, reinterpret_cast<sb_char16_t*>((char*)u16aArg.data()), &szaArg);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16aArg.resize(szaArg << 1);
		SBCheckError(SBGetLastReturnStringW(-1754624660, 1, reinterpret_cast<sb_char16_t*>((char*)u16aArg.data()), &szaArg));
	}
	else
		SBCheckError(_err);

	u16aArg.resize(szaArg << 1);
	sb_u16_to_wstring(u16aArg, aArg);
}
#endif /* SB_U16STRING_USED */

void TElXMLParser::bufAddChar(sb_u16string &aArg, sb_char16_t c)
{
	int32_t szaArg = (int32_t)aArg.length();
	uint32_t _err = TElXMLParser_bufAddChar(_Handle, (sb_char16_t *)aArg.data(), &szaArg, c);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		aArg.resize(szaArg);
		SBCheckError(SBGetLastReturnStringW(1265710763, 1, (sb_char16_t *)aArg.data(), &szaArg));
	}
	else
		SBCheckError(_err);

	aArg.resize(szaArg);
}
#ifdef SB_U16STRING_USED
void TElXMLParser::bufAddChar(std::wstring &aArg, sb_char16_t c)
{
	std::string u16aArg;
	sb_to_u16string(aArg, u16aArg);
	int32_t szaArg = (int32_t)u16aArg.length() >> 1;
	uint32_t _err = TElXMLParser_bufAddChar(_Handle, reinterpret_cast<sb_char16_t*>((char*)u16aArg.data()), &szaArg, c);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16aArg.resize(szaArg << 1);
		SBCheckError(SBGetLastReturnStringW(1265710763, 1, reinterpret_cast<sb_char16_t*>((char*)u16aArg.data()), &szaArg));
	}
	else
		SBCheckError(_err);

	u16aArg.resize(szaArg << 1);
	sb_u16_to_wstring(u16aArg, aArg);
}
#endif /* SB_U16STRING_USED */

void TElXMLParser::bufFlush(sb_u16string &aArg)
{
	int32_t szaArg = (int32_t)aArg.length();
	uint32_t _err = TElXMLParser_bufFlush(_Handle, (sb_char16_t *)aArg.data(), &szaArg);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		aArg.resize(szaArg);
		SBCheckError(SBGetLastReturnStringW(-279391166, 1, (sb_char16_t *)aArg.data(), &szaArg));
	}
	else
		SBCheckError(_err);

	aArg.resize(szaArg);
}
#ifdef SB_U16STRING_USED
void TElXMLParser::bufFlush(std::wstring &aArg)
{
	std::string u16aArg;
	sb_to_u16string(aArg, u16aArg);
	int32_t szaArg = (int32_t)u16aArg.length() >> 1;
	uint32_t _err = TElXMLParser_bufFlush(_Handle, reinterpret_cast<sb_char16_t*>((char*)u16aArg.data()), &szaArg);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16aArg.resize(szaArg << 1);
		SBCheckError(SBGetLastReturnStringW(-279391166, 1, reinterpret_cast<sb_char16_t*>((char*)u16aArg.data()), &szaArg));
	}
	else
		SBCheckError(_err);

	u16aArg.resize(szaArg << 1);
	sb_u16_to_wstring(u16aArg, aArg);
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLParser::bufFree()
{
	SBCheckError(TElXMLParser_bufFree(_Handle));
}

bool TElXMLParser::sEOF()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLParser_sEOF(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLParser::NextChar()
{
	SBCheckError(TElXMLParser_NextChar(_Handle));
}

SB_INLINE void TElXMLParser::PushData(const sb_u16string &Data)
{
	SBCheckError(TElXMLParser_PushData(_Handle, Data.data(), (int32_t)Data.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLParser::PushData(const std::wstring &Data)
{
	std::string u16Data;
	sb_to_u16string(Data, u16Data);
	SBCheckError(TElXMLParser_PushData(_Handle, reinterpret_cast<const sb_char16_t*>(u16Data.data()), (int32_t)u16Data.length() >> 1));
}
#endif /* SB_U16STRING_USED */

bool TElXMLParser::PushData(const sb_u16string &Data, const sb_u16string &Marker)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLParser_PushData_1(_Handle, Data.data(), (int32_t)Data.length(), Marker.data(), (int32_t)Marker.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLParser::PushData(const std::wstring &Data, const std::wstring &Marker)
{
	std::string u16Data;
	sb_to_u16string(Data, u16Data);
	std::string u16Marker;
	sb_to_u16string(Marker, u16Marker);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLParser_PushData_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16Data.data()), (int32_t)u16Data.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16Marker.data()), (int32_t)u16Marker.length() >> 1, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLParser::Write(const sb_u16string &aArg)
{
	SBCheckError(TElXMLParser_Write(_Handle, aArg.data(), (int32_t)aArg.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLParser::Write(const std::wstring &aArg)
{
	std::string u16aArg;
	sb_to_u16string(aArg, u16aArg);
	SBCheckError(TElXMLParser_Write(_Handle, reinterpret_cast<const sb_char16_t*>(u16aArg.data()), (int32_t)u16aArg.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLParser::Write(sb_char16_t c)
{
	SBCheckError(TElXMLParser_Write_1(_Handle, c));
}

bool TElXMLParser::SkipBlank()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLParser_SkipBlank(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLParser::ExpectBlank()
{
	SBCheckError(TElXMLParser_ExpectBlank(_Handle));
}

SB_INLINE void TElXMLParser::ExpectString(const sb_u16string &aArg)
{
	SBCheckError(TElXMLParser_ExpectString(_Handle, aArg.data(), (int32_t)aArg.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLParser::ExpectString(const std::wstring &aArg)
{
	std::string u16aArg;
	sb_to_u16string(aArg, u16aArg);
	SBCheckError(TElXMLParser_ExpectString(_Handle, reinterpret_cast<const sb_char16_t*>(u16aArg.data()), (int32_t)u16aArg.length() >> 1));
}
#endif /* SB_U16STRING_USED */

void TElXMLParser::UntilString(const sb_u16string &aArg, bool LeaveString, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLParser_UntilString(_Handle, aArg.data(), (int32_t)aArg.length(), (int8_t)LeaveString, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1106973766, 3, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLParser::UntilString(const std::wstring &aArg, bool LeaveString, std::wstring &OutResult)
{
	std::string u16aArg;
	sb_to_u16string(aArg, u16aArg);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLParser_UntilString(_Handle, reinterpret_cast<const sb_char16_t*>(u16aArg.data()), (int32_t)u16aArg.length() >> 1, (int8_t)LeaveString, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1106973766, 3, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLParser::UntilStringSkip(const sb_u16string &aArg)
{
	SBCheckError(TElXMLParser_UntilStringSkip(_Handle, aArg.data(), (int32_t)aArg.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLParser::UntilStringSkip(const std::wstring &aArg)
{
	std::string u16aArg;
	sb_to_u16string(aArg, u16aArg);
	SBCheckError(TElXMLParser_UntilStringSkip(_Handle, reinterpret_cast<const sb_char16_t*>(u16aArg.data()), (int32_t)u16aArg.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLParser::CheckForMulti(const std::vector<int32_t> &Expect, bool Recall)
{
	int32_t OutResult;
	SBCheckError(TElXMLParser_CheckForMulti(_Handle, SB_STD_VECTOR_FRONT_ADR(Expect), (int32_t)Expect.size(), (int8_t)Recall, &OutResult));
	return OutResult;
}

bool TElXMLParser::CheckFor(const sb_u16string &aArg, bool Recall)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLParser_CheckFor(_Handle, aArg.data(), (int32_t)aArg.length(), (int8_t)Recall, &OutResultRaw));
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLParser::CheckFor(const std::wstring &aArg, bool Recall)
{
	std::string u16aArg;
	sb_to_u16string(aArg, u16aArg);
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLParser_CheckFor(_Handle, reinterpret_cast<const sb_char16_t*>(u16aArg.data()), (int32_t)u16aArg.length() >> 1, (int8_t)Recall, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

void TElXMLParser::GetWhile(void * aFunc, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLParser_GetWhile(_Handle, aFunc, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(863152122, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLParser::GetWhile(void * aFunc, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLParser_GetWhile(_Handle, aFunc, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(863152122, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLParser::GetWhile(int32_t aCharKind, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLParser_GetWhile_1(_Handle, aCharKind, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-576565608, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLParser::GetWhile(int32_t aCharKind, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLParser_GetWhile_1(_Handle, aCharKind, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-576565608, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLParser::GetUntil(void * aFunc, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLParser_GetUntil(_Handle, aFunc, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-978523705, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLParser::GetUntil(void * aFunc, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLParser_GetUntil(_Handle, aFunc, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-978523705, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLParser::GetUntil(int32_t aCharKind, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLParser_GetUntil_1(_Handle, aCharKind, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-522963717, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLParser::GetUntil(int32_t aCharKind, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLParser_GetUntil_1(_Handle, aCharKind, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-522963717, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLParser::GetUntilSkip(void * aFunc)
{
	SBCheckError(TElXMLParser_GetUntilSkip(_Handle, aFunc));
}

SB_INLINE void TElXMLParser::GetUntilSkip(int32_t aCharKind)
{
	SBCheckError(TElXMLParser_GetUntilSkip_1(_Handle, aCharKind));
}

bool TElXMLParser::GetNMtok(sb_u16string &aArg)
{
	int32_t szaArg = (int32_t)aArg.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElXMLParser_GetNMtok(_Handle, (sb_char16_t *)aArg.data(), &szaArg, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		aArg.resize(szaArg);
		SBCheckError(SBGetLastReturnStringW(-626496359, 1, (sb_char16_t *)aArg.data(), &szaArg));
	}
	else
		SBCheckError(_err);

	aArg.resize(szaArg);
	return (OutResultRaw != 0);
}
#ifdef SB_U16STRING_USED
bool TElXMLParser::GetNMtok(std::wstring &aArg)
{
	std::string u16aArg;
	sb_to_u16string(aArg, u16aArg);
	int32_t szaArg = (int32_t)u16aArg.length() >> 1;
	int8_t OutResultRaw = 0;
	uint32_t _err = TElXMLParser_GetNMtok(_Handle, reinterpret_cast<sb_char16_t*>((char*)u16aArg.data()), &szaArg, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16aArg.resize(szaArg << 1);
		SBCheckError(SBGetLastReturnStringW(-626496359, 1, reinterpret_cast<sb_char16_t*>((char*)u16aArg.data()), &szaArg));
	}
	else
		SBCheckError(_err);

	u16aArg.resize(szaArg << 1);
	sb_u16_to_wstring(u16aArg, aArg);
	return (OutResultRaw != 0);
}
#endif /* SB_U16STRING_USED */

SB_INLINE int64_t TElXMLParser::get_sPos()
{
	int64_t OutResult;
	SBCheckError(TElXMLParser_get_sPos(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElXMLParser::set_sPos(int64_t Value)
{
	SBCheckError(TElXMLParser_set_sPos(_Handle, Value));
}

SB_INLINE int64_t TElXMLParser::get_LastPos()
{
	int64_t OutResult;
	SBCheckError(TElXMLParser_get_LastPos(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE sb_char16_t TElXMLParser::get_Last()
{
	sb_char16_t OutResult;
	SBCheckError(TElXMLParser_get_Last(_Handle, &OutResult));
	return OutResult;
}

bool TElXMLParser::get_NormalizeNEL()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElXMLParser_get_NormalizeNEL(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElXMLParser::set_NormalizeNEL(bool Value)
{
	SBCheckError(TElXMLParser_set_NormalizeNEL(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELXMLCODEC
TElXMLCodec* TElXMLParser::get_OEnc()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLParser_get_OEnc(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OEnc)
		this->_Inst_OEnc = new TElXMLCodec(hOutResult, ohFalse);
	else
		this->_Inst_OEnc->updateHandle(hOutResult);
	return this->_Inst_OEnc;
}

SB_INLINE void TElXMLParser::set_OEnc(TElXMLCodec &Value)
{
	SBCheckError(TElXMLParser_set_OEnc(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLParser::set_OEnc(TElXMLCodec *Value)
{
	SBCheckError(TElXMLParser_set_OEnc(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLCODEC */

void TElXMLParser::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLCODEC
	this->_Inst_OEnc = NULL;
#endif /* SB_USE_CLASS_TELXMLCODEC */
}

TElXMLParser::TElXMLParser(TElXMLParserHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
TElXMLParser::TElXMLParser(TElXMLDOMDocument &aDoc, bool DoInitStream, const std::string &DefaultEncoding, bool NormNEL) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLParser_Create(aDoc.getHandle(), (int8_t)DoInitStream, DefaultEncoding.data(), (int32_t)DefaultEncoding.length(), (int8_t)NormNEL, &_Handle));
}

TElXMLParser::TElXMLParser(TElXMLDOMDocument *aDoc, bool DoInitStream, const std::string &DefaultEncoding, bool NormNEL) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLParser_Create((aDoc != NULL) ? aDoc->getHandle() : SB_NULL_HANDLE, (int8_t)DoInitStream, DefaultEncoding.data(), (int32_t)DefaultEncoding.length(), (int8_t)NormNEL, &_Handle));
}
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

TElXMLParser::~TElXMLParser()
{
#ifdef SB_USE_CLASS_TELXMLCODEC
	delete this->_Inst_OEnc;
	this->_Inst_OEnc = NULL;
#endif /* SB_USE_CLASS_TELXMLCODEC */
}
#endif /* SB_USE_CLASS_TELXMLPARSER */

#ifdef SB_USE_CLASS_TELXMLNAMESPACEMAP

SB_INLINE void TElXMLNamespaceMap::Clear()
{
	SBCheckError(TElXMLNamespaceMap_Clear(_Handle));
}

SB_INLINE void TElXMLNamespaceMap::Add(TElXMLNamespaceMap &NSMap, bool OverwriteIfExists)
{
	SBCheckError(TElXMLNamespaceMap_Add(_Handle, NSMap.getHandle(), (int8_t)OverwriteIfExists));
}

SB_INLINE void TElXMLNamespaceMap::Add(TElXMLNamespaceMap *NSMap, bool OverwriteIfExists)
{
	SBCheckError(TElXMLNamespaceMap_Add(_Handle, (NSMap != NULL) ? NSMap->getHandle() : SB_NULL_HANDLE, (int8_t)OverwriteIfExists));
}

SB_INLINE void TElXMLNamespaceMap::AddNamespace(const sb_u16string &Prefix, const sb_u16string &URI)
{
	SBCheckError(TElXMLNamespaceMap_AddNamespace(_Handle, Prefix.data(), (int32_t)Prefix.length(), URI.data(), (int32_t)URI.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLNamespaceMap::AddNamespace(const std::wstring &Prefix, const std::wstring &URI)
{
	std::string u16Prefix;
	sb_to_u16string(Prefix, u16Prefix);
	std::string u16URI;
	sb_to_u16string(URI, u16URI);
	SBCheckError(TElXMLNamespaceMap_AddNamespace(_Handle, reinterpret_cast<const sb_char16_t*>(u16Prefix.data()), (int32_t)u16Prefix.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16URI.data()), (int32_t)u16URI.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElXMLNamespaceMap::RemoveNamespace(const sb_u16string &Prefix)
{
	SBCheckError(TElXMLNamespaceMap_RemoveNamespace(_Handle, Prefix.data(), (int32_t)Prefix.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLNamespaceMap::RemoveNamespace(const std::wstring &Prefix)
{
	std::string u16Prefix;
	sb_to_u16string(Prefix, u16Prefix);
	SBCheckError(TElXMLNamespaceMap_RemoveNamespace(_Handle, reinterpret_cast<const sb_char16_t*>(u16Prefix.data()), (int32_t)u16Prefix.length() >> 1));
}
#endif /* SB_U16STRING_USED */

void TElXMLNamespaceMap::FindNamespace(const sb_u16string &Prefix, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLNamespaceMap_FindNamespace(_Handle, Prefix.data(), (int32_t)Prefix.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(1713285262, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLNamespaceMap::FindNamespace(const std::wstring &Prefix, std::wstring &OutResult)
{
	std::string u16Prefix;
	sb_to_u16string(Prefix, u16Prefix);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLNamespaceMap_FindNamespace(_Handle, reinterpret_cast<const sb_char16_t*>(u16Prefix.data()), (int32_t)u16Prefix.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(1713285262, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void TElXMLNamespaceMap::FindPrefix(const sb_u16string &URI, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLNamespaceMap_FindPrefix(_Handle, URI.data(), (int32_t)URI.length(), (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1691813738, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void TElXMLNamespaceMap::FindPrefix(const std::wstring &URI, std::wstring &OutResult)
{
	std::string u16URI;
	sb_to_u16string(URI, u16URI);
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLNamespaceMap_FindPrefix(_Handle, reinterpret_cast<const sb_char16_t*>(u16URI.data()), (int32_t)u16URI.length() >> 1, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1691813738, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

SB_INLINE int32_t TElXMLNamespaceMap::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElXMLNamespaceMap_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElXMLNamespaceMap::get_Prefix(int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLNamespaceMap_get_Prefix(_Handle, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1108027799, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLNamespaceMap::get_Prefix(int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLNamespaceMap_get_Prefix(_Handle, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1108027799, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
void TElXMLNamespaceMap::get_URI(int32_t Index, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElXMLNamespaceMap_get_URI(_Handle, Index, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-617928468, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElXMLNamespaceMap::get_URI(int32_t Index, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElXMLNamespaceMap_get_URI(_Handle, Index, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-617928468, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
TElXMLNamespaceMap::TElXMLNamespaceMap(TElXMLNamespaceMapHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElXMLNamespaceMap::TElXMLNamespaceMap() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLNamespaceMap_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLNAMESPACEMAP */

#ifdef SB_USE_CLASS_TELXMLCUSTOMFORMATTER

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLCustomFormatter::AppendElement(TElXMLDOMElement &Parent, TElXMLDOMElement &Child)
{
	SBCheckError(TElXMLCustomFormatter_AppendElement(_Handle, Parent.getHandle(), Child.getHandle()));
}

SB_INLINE void TElXMLCustomFormatter::AppendElement(TElXMLDOMElement *Parent, TElXMLDOMElement *Child)
{
	SBCheckError(TElXMLCustomFormatter_AppendElement(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, (Child != NULL) ? Child->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMELEMENT_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLCustomFormatter::AppendElement(TElXMLDOMElement &Parent, TElXMLCustomElement &Child, TElXMLDOMDocument &Document)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCustomFormatter_AppendElement_1(_Handle, Parent.getHandle(), Child.getHandle(), Document.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLCustomFormatter::AppendElement(TElXMLDOMElement *Parent, TElXMLCustomElement *Child, TElXMLDOMDocument *Document)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCustomFormatter_AppendElement_1(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, (Child != NULL) ? Child->getHandle() : SB_NULL_HANDLE, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMELEMENT_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLCustomFormatter::AppendElementWithText(TElXMLDOMElement &Parent, TElXMLDOMElement &Child, const sb_u16string &ChildText, TElXMLTextType ChildTextType)
{
	SBCheckError(TElXMLCustomFormatter_AppendElementWithText(_Handle, Parent.getHandle(), Child.getHandle(), ChildText.data(), (int32_t)ChildText.length(), (TElXMLTextTypeRaw)ChildTextType));
}

SB_INLINE void TElXMLCustomFormatter::AppendElementWithText(TElXMLDOMElement *Parent, TElXMLDOMElement *Child, const sb_u16string &ChildText, TElXMLTextType ChildTextType)
{
	SBCheckError(TElXMLCustomFormatter_AppendElementWithText(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, (Child != NULL) ? Child->getHandle() : SB_NULL_HANDLE, ChildText.data(), (int32_t)ChildText.length(), (TElXMLTextTypeRaw)ChildTextType));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLCustomFormatter::AppendElementWithText(TElXMLDOMElement &Parent, TElXMLDOMElement &Child, const std::wstring &ChildText, TElXMLTextType ChildTextType)
{
	std::string u16ChildText;
	sb_to_u16string(ChildText, u16ChildText);
	SBCheckError(TElXMLCustomFormatter_AppendElementWithText(_Handle, Parent.getHandle(), Child.getHandle(), reinterpret_cast<const sb_char16_t*>(u16ChildText.data()), (int32_t)u16ChildText.length() >> 1, (TElXMLTextTypeRaw)ChildTextType));
}

SB_INLINE void TElXMLCustomFormatter::AppendElementWithText(TElXMLDOMElement *Parent, TElXMLDOMElement *Child, const std::wstring &ChildText, TElXMLTextType ChildTextType)
{
	std::string u16ChildText;
	sb_to_u16string(ChildText, u16ChildText);
	SBCheckError(TElXMLCustomFormatter_AppendElementWithText(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, (Child != NULL) ? Child->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16ChildText.data()), (int32_t)u16ChildText.length() >> 1, (TElXMLTextTypeRaw)ChildTextType));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLCustomFormatter::AppendText(TElXMLDOMElement &Parent, const sb_u16string &Text, TElXMLTextType TextType)
{
	SBCheckError(TElXMLCustomFormatter_AppendText(_Handle, Parent.getHandle(), Text.data(), (int32_t)Text.length(), (TElXMLTextTypeRaw)TextType));
}

SB_INLINE void TElXMLCustomFormatter::AppendText(TElXMLDOMElement *Parent, const sb_u16string &Text, TElXMLTextType TextType)
{
	SBCheckError(TElXMLCustomFormatter_AppendText(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, Text.data(), (int32_t)Text.length(), (TElXMLTextTypeRaw)TextType));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElXMLCustomFormatter::AppendText(TElXMLDOMElement &Parent, const std::wstring &Text, TElXMLTextType TextType)
{
	std::string u16Text;
	sb_to_u16string(Text, u16Text);
	SBCheckError(TElXMLCustomFormatter_AppendText(_Handle, Parent.getHandle(), reinterpret_cast<const sb_char16_t*>(u16Text.data()), (int32_t)u16Text.length() >> 1, (TElXMLTextTypeRaw)TextType));
}

SB_INLINE void TElXMLCustomFormatter::AppendText(TElXMLDOMElement *Parent, const std::wstring &Text, TElXMLTextType TextType)
{
	std::string u16Text;
	sb_to_u16string(Text, u16Text);
	SBCheckError(TElXMLCustomFormatter_AppendText(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16Text.data()), (int32_t)u16Text.length() >> 1, (TElXMLTextTypeRaw)TextType));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMELEMENT_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT_AND_TELXMLDOMNODE
SB_INLINE void TElXMLCustomFormatter::InsertBefore(TElXMLDOMElement &Parent, TElXMLDOMNode &ChildRef, TElXMLCustomElement &Child, TElXMLDOMDocument &Document)
{
	SBCheckError(TElXMLCustomFormatter_InsertBefore(_Handle, Parent.getHandle(), ChildRef.getHandle(), Child.getHandle(), Document.getHandle()));
}

SB_INLINE void TElXMLCustomFormatter::InsertBefore(TElXMLDOMElement *Parent, TElXMLDOMNode *ChildRef, TElXMLCustomElement *Child, TElXMLDOMDocument *Document)
{
	SBCheckError(TElXMLCustomFormatter_InsertBefore(_Handle, (Parent != NULL) ? Parent->getHandle() : SB_NULL_HANDLE, (ChildRef != NULL) ? ChildRef->getHandle() : SB_NULL_HANDLE, (Child != NULL) ? Child->getHandle() : SB_NULL_HANDLE, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMELEMENT_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT_AND_TELXMLDOMNODE */

SB_INLINE void TElXMLCustomFormatter::Clear()
{
	SBCheckError(TElXMLCustomFormatter_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLCustomFormatter::Push(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLCustomFormatter_Push(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLCustomFormatter::Push(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLCustomFormatter_Push(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

SB_INLINE void TElXMLCustomFormatter::Pop()
{
	SBCheckError(TElXMLCustomFormatter_Pop(_Handle));
}

TElXMLCustomFormatter::TElXMLCustomFormatter(TElXMLCustomFormatterHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElXMLCustomFormatter::TElXMLCustomFormatter() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElXMLCustomFormatter_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELXMLCUSTOMFORMATTER */

#ifdef SB_USE_CLASS_TELXMLCUSTOMELEMENT

SB_INLINE void TElXMLCustomElement::Clear()
{
	SBCheckError(TElXMLCustomElement_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
SB_INLINE void TElXMLCustomElement::LoadFromXML(TElXMLDOMElement &Element)
{
	SBCheckError(TElXMLCustomElement_LoadFromXML(_Handle, Element.getHandle()));
}

SB_INLINE void TElXMLCustomElement::LoadFromXML(TElXMLDOMElement *Element)
{
	SBCheckError(TElXMLCustomElement_LoadFromXML(_Handle, (Element != NULL) ? Element->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLCustomElement::SaveToXML(TElXMLDOMDocument &Document)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCustomElement_SaveToXML(_Handle, Document.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLCustomElement::SaveToXML(TElXMLDOMDocument *Document)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCustomElement_SaveToXML(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
SB_INLINE TElXMLDOMElementHandle TElXMLCustomElement::SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCustomElement_SaveToXML_1(_Handle, Document.getHandle(), Formatter.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE TElXMLDOMElementHandle TElXMLCustomElement::SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter)
{
	TElXMLDOMElementHandle OutResult;
	SBCheckError(TElXMLCustomElement_SaveToXML_1(_Handle, (Document != NULL) ? Document->getHandle() : SB_NULL_HANDLE, (Formatter != NULL) ? Formatter->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElement* TElXMLCustomElement::get_XMLElement()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElXMLCustomElement_get_XMLElement(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_XMLElement)
		this->_Inst_XMLElement = new TElXMLDOMElement(hOutResult, ohFalse);
	else
		this->_Inst_XMLElement->updateHandle(hOutResult);
	return this->_Inst_XMLElement;
}

SB_INLINE void TElXMLCustomElement::set_XMLElement(TElXMLDOMElement &Value)
{
	SBCheckError(TElXMLCustomElement_set_XMLElement(_Handle, Value.getHandle()));
}

SB_INLINE void TElXMLCustomElement::set_XMLElement(TElXMLDOMElement *Value)
{
	SBCheckError(TElXMLCustomElement_set_XMLElement(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void TElXMLCustomElement::initInstances()
{
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	this->_Inst_XMLElement = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
}

TElXMLCustomElement::TElXMLCustomElement(TElXMLCustomElementHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElXMLCustomElement::TElXMLCustomElement() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElXMLCustomElement_Create(&_Handle));
}

TElXMLCustomElement::~TElXMLCustomElement()
{
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
	delete this->_Inst_XMLElement;
	this->_Inst_XMLElement = NULL;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */
}
#endif /* SB_USE_CLASS_TELXMLCUSTOMELEMENT */

#ifdef SB_USE_GLOBAL_PROCS_XMLCORE

bool isXMLIdeographic(sb_char16_t c)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBXMLCore_isXMLIdeographic(c, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool isXMLBaseChar(sb_char16_t c)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBXMLCore_isXMLBaseChar(c, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool isXMLCombining(sb_char16_t c)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBXMLCore_isXMLCombining(c, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool isXMLDigit(sb_char16_t c)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBXMLCore_isXMLDigit(c, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool isXMLExtender(sb_char16_t c)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBXMLCore_isXMLExtender(c, &OutResultRaw));
	return (OutResultRaw != 0);
}

#endif /* SB_USE_GLOBAL_PROCS_XMLCORE */

};	/* namespace SecureBlackbox */

