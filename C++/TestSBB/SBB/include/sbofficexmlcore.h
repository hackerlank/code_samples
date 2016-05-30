#ifndef __INC_SBOFFICEXMLCORE
#define __INC_SBOFFICEXMLCORE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbofficeconstants.h"
#include "sbofficecommon.h"
#include "sbofficeresources.h"
#include "sbxmlcore.h"
#include "sbxmldefs.h"
#include "sbxmlsec.h"
#include "sbxmlsig.h"
#include "sbxmltransform.h"
#include "sbxmlutils.h"
#include "sbtypes.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ooxmlRelationshipsNamespace 	"http://schemas.openxmlformats.org/package/2006/relationships"
#define SB_ooxmlOfficeRelationshipsNamespace 	"http://schemas.openxmlformats.org/officeDocument/2006/relationships"
#define SB_ooxmlContentTypesNamespace 	"http://schemas.openxmlformats.org/package/2006/content-types"
#define SB_ooxmlCorePropertiesNamespace 	"http://schemas.openxmlformats.org/package/2006/metadata/core-properties"
#define SB_ooxmlDigitalSignatureNamespace 	"http://schemas.openxmlformats.org/package/2006/digital-signature"
#define SB_ooxmlMarkupCompatibilityNamespace 	"http://schemas.openxmlformats.org/markup-compatibility/2006"
#define SB_ooxmlDublinCoreTermsNamespace 	"http://purl.org/dc/terms/"
#define SB_ooxmlDublinCoreNamespace 	"http://purl.org/dc/elements/1.1/"
#define SB_ooxmlOfficeEncryptionNamespace 	"http://schemas.microsoft.com/office/2006/encryption"
#define SB_ooxmlKeyEncryptorPasswordNamespace 	"http://schemas.microsoft.com/office/2006/keyEncryptor/password"
#define SB_ooxmlOfficeDigitalSignatureNamespace 	"http://schemas.microsoft.com/office/2006/digsig"
#define SB_oxpsNamespace_200506 	"http://schemas.microsoft.com/xps/2005/06"
#define SB_oxpsNamespace_V1 	"http://schemas.openxps.org/oxps/v1.0"
#define SB_oxpsNamespace_Latest 	"http://schemas.microsoft.com/xps/2005/06"
#define SB_oxpsSignatureDefinitionsNamespace_200506 	"http://schemas.microsoft.com/xps/2005/06/signature-definitions"
#define SB_oxpsSignatureDefinitionsNamespace_V1 	"http://schemas.openxps.org/oxps/v1.0/signature-definitions"
#define SB_oxpsSignatureDefinitionsNamespace_Latest 	"http://schemas.microsoft.com/xps/2005/06/signature-definitions"
#define SB_ooxmlMSVMLNamespace 	"urn:schemas-microsoft-com:vml"
#define SB_ooxmlMSOfficeNamespace 	"urn:schemas-microsoft-com:office:office"
#define SB_ooxmlMSOfficeWordNamespace 	"urn:schemas-microsoft-com:office:word"
#define SB_ooxmlMSOfficeExcelNamespace 	"urn:schemas-microsoft-com:office:excel"
#define SB_ooxmlMSOfficePowerpointNamespace 	"urn:schemas-microsoft-com:office:powerpoint"
#define SB_odfManifestNamespace 	"urn:oasis:names:tc:opendocument:xmlns:manifest:1.0"
#define SB_odfSignatureNamespace 	"urn:oasis:names:tc:opendocument:xmlns:digitalsignature:1.0"
#define SB_odfPackageNamespace 	"http://docs.oasis-open.org/ns/office/1.2/meta/pkg#"
#define SB_ooxmlDublinCoreTermsPrefix 	"dcterms"
#define SB_ooxmlDublinCorePrefix 	"dc"
#define SB_ooxmlKeyEncryptorPasswordPrefix 	'p'
#define SB_odfManifestPrefix 	"manifest"
#define SB_ooxmlOfficeDocumentRelationshipType 	"http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument"
#define SB_ooxmlCorePropertiesRelationshipType 	"http://schemas.openxmlformats.org/package/2006/relationships/metadata/core-properties"
#define SB_ooxmlDigitalSignatureRelationshipType 	"http://schemas.openxmlformats.org/package/2006/relationships/digital-signature/signature"
#define SB_ooxmlDigitalSignatureOriginRelationshipType 	"http://schemas.openxmlformats.org/package/2006/relationships/digital-signature/origin"
#define SB_ooxmlDigitalSignatureCertificateRelationshipType 	"http://schemas.openxmlformats.org/package/2006/relationships/digital-signature/certificate"
#define SB_ooxmlThumbnailRelationshipType 	"http://schemas.openxmlformats.org/package/2006/relationships/metadata/thumbnail"
#define SB_ooxmlApplicationPropertiesRelationshipType 	"http://schemas.openxmlformats.org/officeDocument/2006/relationships/extended-properties"
#define SB_ooxmlCustomXMLPropertiesRelationshipType 	"http://schemas.openxmlformats.org/officeDocument/2006/relationships/customXmlProps"
#define SB_ooxmlCustomXMLRelationshipType 	"http://schemas.openxmlformats.org/officeDocument/2006/relationships/customXml"
#define SB_ooxmlCorePropertiesContentType 	"application/vnd.openxmlformats-package.core-properties+xml"
#define SB_ooxmlApplicationPropertiesContentType 	"application/vnd.openxmlformats-officedocument.extended-properties+xml"
#define SB_ooxmlDigitalSignatureCertificateContentType 	"application/vnd.openxmlformats-package.digital-signature-certificate"
#define SB_ooxmlDigitalSignatureOriginContentType 	"application/vnd.openxmlformats-package.digital-signature-origin"
#define SB_ooxmlDigitalSignatureXMLSignatureContentType 	"application/vnd.openxmlformats-package.digital-signature-xmlsignature+xml"
#define SB_ooxmlRelationshipsContentType 	"application/vnd.openxmlformats-package.relationships+xml"
#define SB_ooxmlCustomXMLPropertiesContentType 	"application/vnd.openxmlformats-officedocument.customXmlProperties+xml"
#define SB_ooxmlWordprocessingMLContentType 	"application/vnd.openxmlformats-officedocument.wordprocessingml.document.main+xml"
#define SB_ooxmlWordMacroEnabledContentType 	"application/vnd.ms-word.document.macroEnabled.main+xml"
#define SB_ooxmlWordprocessingMLTemplateContentType 	"application/vnd.openxmlformats-officedocument.wordprocessingml.template.main+xml"
#define SB_ooxmlWordTemplateMacroEnabledContentType 	"application/vnd.ms-word.template.macroEnabledTemplate.main+xml"
#define SB_ooxmlSpreadsheetMLContentType 	"application/vnd.openxmlformats-officedocument.spreadsheetml.sheet.main+xml"
#define SB_ooxmlSpreadsheetMLWorksheetContentType 	"application/vnd.openxmlformatsofficedocument.spreadsheetml.worksheet+xml"
#define SB_ooxmlExcelMacroEnabledContentType 	"application/vnd.ms-excel.sheet.macroEnabled.main+xml"
#define SB_ooxmlSpreadsheetMLTemplateContentType 	"application/vnd.openxmlformats-officedocument.spreadsheetml.template.main+xml"
#define SB_ooxmlExcelTemplateMacroEnabledContentType 	"application/vnd.ms-excel.template.macroEnabled.main+xml"
#define SB_ooxmlExcelBinaryMacroEnabledContentType 	"application/vnd.ms-excel.sheet.binary.macroEnabled.main"
#define SB_ooxmlExcelAddInMacroEnabledContentType 	"application/vnd.ms-excel.addin.macroEnabled.main+xml"
#define SB_ooxmlPresentationMLContentType 	"application/vnd.openxmlformats-officedocument.presentationml.presentation.main+xml"
#define SB_ooxmlPowerPointMacroEnabledContentType 	"application/vnd.ms-powerpoint.presentation.macroEnabled.main+xml"
#define SB_ooxmlPresentationMLTemplateContentType 	"application/vnd.openxmlformats-officedocument.presentationml.template.main+xml"
#define SB_ooxmlPowerPointTemplateMacroEnabledContentType 	"application/vnd.ms-powerpoint.template.macroEnabled.main+xml"
#define SB_ooxmlPresentationMLSlideshowContentType 	"application/vnd.openxmlformats-officedocument.presentationml.slideshow.main+xml"
#define SB_ooxmlPowerPointSlideshowMacroEnabledContentType 	"application/vnd.ms-powerpoint.slideshow.macroEnabled.main+xml"
#define SB_ooxmlPowerPointAddInMacroEnabledContentType 	"application/vnd.ms-powerpoint.addin.macroEnabled.main+xml"
#define SB_oxpsSignatureDefinitionsContentType 	"application/vnd.ms-package.xpssignaturedefinitions+xml"
#define SB_oxpsFixedDocumentContentType 	"application/vnd.ms-package.xps-fixeddocument+xml"
#define SB_oxpsFixedDocumentSequenceContentType 	"application/vnd.ms-package.xpsfixeddocumentsequence+xml"
#define SB_oxpsFixedPageContentType 	"application/vnd.ms-package.xps-fixedpage+xml"
#define SB_oxpsDiscardControlContentType 	"application/vnd.ms-package.xps-discard-control+xml"
#define SB_oxpsDocumentStructureContentType 	"application/vnd.ms-package.xpsdocumentstructure+xml"
#define SB_oxpsFontContentType 	"application/vnd.ms-opentype"
#define SB_oxpsICCProfileContentType 	"application/vnd.ms-color.iccprofile"
#define SB_oxpsObfuscatedFontContentType 	"application/vnd.ms-package.obfuscated-opentype"
#define SB_oxpsStoryFragmentsContentType 	"application/vnd.ms-package.xps-storyfragments+xml"
#define SB_oxpsPrintTicketContentType 	"application/vnd.ms-printing.printticket+xml"
#define SB_oxpsDigitalSignatureDefinitionsRelationshipType 	"http://schemas.microsoft.com/xps/2005/06/signature-definitions"
#define SB_oxpsDiscardControlRelationshipType 	"http://schemas.microsoft.com/xps/2005/06/discard-control"
#define SB_oxpsDocumentStructureRelationshipType 	"http://schemas.microsoft.com/xps/2005/06/documentstructure"
#define SB_oxpsPrintTicketRelationshipType 	"http://schemas.microsoft.com/xps/2005/06/printticket"
#define SB_oxpsRequiredResourceRelationshipType 	"http://schemas.microsoft.com/xps/2005/06/required-resource"
#define SB_oxpsRestrictedFontRelationshipType 	"http://schemas.microsoft.com/xps/2005/06/restricted-font"
#define SB_oxpsStartPartRelationshipType 	"http://schemas.microsoft.com/xps/2005/06/fixedrepresentation"
#define SB_oxpsStoryFragmentsRelationshipType 	"http://schemas.microsoft.com/xps/2005/06/storyfragments"
#define SB_ooxmlTransformRelationship_2006 	"http://schemas.openxmlformats.org/package/2006/RelationshipTransform"
#define SB_ooxmlTransformRelationship_200506 	"http://schemas.openxmlformats.org/package/2005/06/RelationshipTransform"
#define SB_ooxmlTransformRelationship_Latest 	"http://schemas.openxmlformats.org/package/2006/RelationshipTransform"
#define SB_oxJPEGImageContentType 	"image/jpeg"
#define SB_oxPNGImageContentType 	"image/png"
#define SB_oxTIFFImageContentType 	"image/tiff"
#define SB_odfOpenDocumentTextMimeType 	"application/vnd.oasis.opendocument.text"
#define SB_odfOpenDocumentTextTemplateMimeType 	"application/vnd.oasis.opendocument.text-template"
#define SB_odfOpenDocumentTextMasterMimeType 	"application/vnd.oasis.opendocument.text-master"
#define SB_odfOpenDocumentTextWebMimeType 	"application/vnd.oasis.opendocument.text-web"
#define SB_odfOpenDocumentSpreadsheetMimeType 	"application/vnd.oasis.opendocument.spreadsheet"
#define SB_odfOpenDocumentSpreadsheetTemplateMimeType 	"application/vnd.oasis.opendocument.spreadsheet-template"
#define SB_odfOpenDocumentDrawingMimeType 	"application.vnd.oasis.opendocument.graphics"
#define SB_odfOpenDocumentDrawingTemplateMimeType 	"application/vnd.oasis.opendocument.graphic-template"
#define SB_odfOpenDocumentPresentationMimeType 	"application/vnd.oasis.opendocument.presentation"
#define SB_odfOpenDocumentPresentationTemplateMimeType 	"application/vnd.oasis.opendocument.presentation-template"
#define SB_odfOpenDocumentChartMimeType 	"application/vnd.oasis.opendocument.chart"
#define SB_odfOpenDocumentChartTemplateMimeType 	"application/vnd.oasis.opendocument.chart-template"
#define SB_odfOpenDocumentImageMimeType 	"application/vnd.oasis.opendocument.image"
#define SB_odfOpenDocumentImageTemplateMimeType 	"application/vnd.oasis.opendocument.image-template"
#define SB_odfOpenDocumentFormulaMimeType 	"application/vnd.oasis.opendocument.formula"
#define SB_odfOpenDocumentFormulaTemplateMimeType 	"application/vnd.oasis.opendocument.formula-template"
#define SB_odfOpenDocumentDatabaseMimeType 	"application/vnd.oasis.opendocument.base"
#define SB_odfEncryptionMethodBlowfish 	"urn:oasis:names:tc:opendocument:xmlns:manifest:1.0#blowfish"
#define SB_odfDigestMethodSHA1 	"urn:oasis:names:tc:opendocument:xmlns:manifest:1.0#sha1"
#define SB_odfDerivationMethodPBKDF2 	"urn:oasis:names:tc:opendocument:xmlns:manifest:1.0#pbkdf2"

typedef TElClassHandle TElOfficeOpenXMLElementHandle;

typedef TElClassHandle TElOfficeOpenXMLRelationshipHandle;

typedef TElClassHandle TElOfficeOpenXMLRelationshipsHandle;

typedef TElClassHandle TElOfficeOpenXMLDefaultHandle;

typedef TElClassHandle TElOfficeOpenXMLDefaultListHandle;

typedef TElClassHandle TElOfficeOpenXMLOverrideHandle;

typedef TElClassHandle TElOfficeOpenXMLOverrideListHandle;

typedef TElClassHandle TElOfficeOpenXMLContentTypesHandle;

typedef TElClassHandle TElOfficeXMLDCSimpleLiteralHandle;

typedef TElClassHandle TElOfficeXMLDCDateHandle;

typedef TElClassHandle TElOfficeOpenXMLCorePropertiesHandle;

typedef TElClassHandle TElOfficeXMLKeyDataHandle;

typedef TElClassHandle TElOfficeXMLDataIntegrityHandle;

typedef TElClassHandle TElOfficeXMLKeyEncryptorHandle;

typedef TElClassHandle TElOfficeXMLKeyEncryptorsHandle;

typedef TElClassHandle TElOfficeXMLPasswordKeyEncryptorHandle;

typedef TElClassHandle TElOfficeXMLEncryptionHandle;

typedef TElClassHandle TElOfficeXMLSignatureTimeHandle;

typedef TElClassHandle TElOfficeOpenXMLRelationshipTransformHandle;

typedef TElClassHandle TElOfficeXMLSignatureInfoV1Handle;

typedef TElClassHandle TElOfficeXMLSpotLocationHandle;

typedef TElClassHandle TElOfficeXMLSignatureDefinitionHandle;

typedef TElClassHandle TElOfficeXMLFixedDocumentSequenceHandle;

typedef TElClassHandle TElOfficeXMLPageContentHandle;

typedef TElClassHandle TElOfficeXMLFixedDocumentHandle;

typedef TElClassHandle TElOpenOfficeXMLManifestAlgorithmHandle;

typedef TElClassHandle TElOpenOfficeXMLManifestKeyDerivationHandle;

typedef TElClassHandle TElOpenOfficeXMLManifestStartKeyGenerationHandle;

typedef TElClassHandle TElOpenOfficeXMLManifestEncryptionDataHandle;

typedef TElClassHandle TElOpenOfficeXMLManifestFileEntryHandle;

typedef TElClassHandle TElOpenOfficeXMLManifestHandle;

typedef uint8_t TSBOfficeOpenXMLTargetModeRaw;

typedef enum
{
	tmInternal = 0,
	tmExternal = 1
} TSBOfficeOpenXMLTargetMode;

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLELEMENT
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLElement_Clear(TElOfficeOpenXMLElementHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLElement_get_IsModified(TElOfficeOpenXMLElementHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLElement_set_IsModified(TElOfficeOpenXMLElementHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLElement_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLELEMENT */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationship_Clear(TElOfficeOpenXMLRelationshipHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationship_LoadFromXML(TElOfficeOpenXMLRelationshipHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationship_SaveToXML(TElOfficeOpenXMLRelationshipHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationship_get_ID(TElOfficeOpenXMLRelationshipHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationship_set_ID(TElOfficeOpenXMLRelationshipHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationship_get_RelationshipType(TElOfficeOpenXMLRelationshipHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationship_set_RelationshipType(TElOfficeOpenXMLRelationshipHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationship_get_Target(TElOfficeOpenXMLRelationshipHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationship_set_Target(TElOfficeOpenXMLRelationshipHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationship_get_TargetMode(TElOfficeOpenXMLRelationshipHandle _Handle, TSBOfficeOpenXMLTargetModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationship_set_TargetMode(TElOfficeOpenXMLRelationshipHandle _Handle, TSBOfficeOpenXMLTargetModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationship_Create(TElOfficeOpenXMLRelationshipHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationships_Add(TElOfficeOpenXMLRelationshipsHandle _Handle, TElOfficeOpenXMLRelationshipHandle ARelationship, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationships_Add_1(TElOfficeOpenXMLRelationshipsHandle _Handle, const sb_char16_t * pcID, int32_t szID, const sb_char16_t * pcTarget, int32_t szTarget, const sb_char16_t * pcRelationshipType, int32_t szRelationshipType, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationships_Insert(TElOfficeOpenXMLRelationshipsHandle _Handle, int32_t Index, TElOfficeOpenXMLRelationshipHandle ARelationship);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationships_Delete(TElOfficeOpenXMLRelationshipsHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationships_Clear(TElOfficeOpenXMLRelationshipsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationships_CreateRelationship(TElOfficeOpenXMLRelationshipsHandle _Handle, const sb_char16_t * pcTarget, int32_t szTarget, TSBOfficeOpenXMLTargetModeRaw TargetMode, const sb_char16_t * pcRelationshipType, int32_t szRelationshipType, const sb_char16_t * pcID, int32_t szID, TElOfficeOpenXMLRelationshipHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationships_GetRelationshipById(TElOfficeOpenXMLRelationshipsHandle _Handle, const sb_char16_t * pcID, int32_t szID, TElOfficeOpenXMLRelationshipHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationships_GetRelationshipByType(TElOfficeOpenXMLRelationshipsHandle _Handle, const sb_char16_t * pcRelType, int32_t szRelType, TElOfficeOpenXMLRelationshipHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationships_SortRelationshipsById(TElOfficeOpenXMLRelationshipsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationships_LoadFromXML(TElOfficeOpenXMLRelationshipsHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationships_SaveToXML(TElOfficeOpenXMLRelationshipsHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationships_get_Count(TElOfficeOpenXMLRelationshipsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationships_get_Relationships(TElOfficeOpenXMLRelationshipsHandle _Handle, int32_t Index, TElOfficeOpenXMLRelationshipHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationships_Create(TElOfficeOpenXMLRelationshipsHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLDefault_Clear(TElOfficeOpenXMLDefaultHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLDefault_LoadFromXML(TElOfficeOpenXMLDefaultHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLDefault_SaveToXML(TElOfficeOpenXMLDefaultHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLDefault_get_ContentType(TElOfficeOpenXMLDefaultHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLDefault_set_ContentType(TElOfficeOpenXMLDefaultHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLDefault_get_Extension(TElOfficeOpenXMLDefaultHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLDefault_set_Extension(TElOfficeOpenXMLDefaultHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLDefault_Create(TElOfficeOpenXMLDefaultHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDEFAULTLIST
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLDefaultList_Add(TElOfficeOpenXMLDefaultListHandle _Handle, TElOfficeOpenXMLDefaultHandle ADefault, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLDefaultList_Insert(TElOfficeOpenXMLDefaultListHandle _Handle, int32_t Index, TElOfficeOpenXMLDefaultHandle ADefault);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLDefaultList_Delete(TElOfficeOpenXMLDefaultListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLDefaultList_Clear(TElOfficeOpenXMLDefaultListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLDefaultList_get_Count(TElOfficeOpenXMLDefaultListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLDefaultList_get_DefaultItems(TElOfficeOpenXMLDefaultListHandle _Handle, int32_t Index, TElOfficeOpenXMLDefaultHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLDefaultList_Create(TElOfficeOpenXMLDefaultListHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDEFAULTLIST */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLOverride_Clear(TElOfficeOpenXMLOverrideHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLOverride_LoadFromXML(TElOfficeOpenXMLOverrideHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLOverride_SaveToXML(TElOfficeOpenXMLOverrideHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLOverride_get_ContentType(TElOfficeOpenXMLOverrideHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLOverride_set_ContentType(TElOfficeOpenXMLOverrideHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLOverride_get_PartName(TElOfficeOpenXMLOverrideHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLOverride_set_PartName(TElOfficeOpenXMLOverrideHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLOverride_Create(TElOfficeOpenXMLOverrideHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDELIST
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLOverrideList_Add(TElOfficeOpenXMLOverrideListHandle _Handle, TElOfficeOpenXMLOverrideHandle AOverride, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLOverrideList_Insert(TElOfficeOpenXMLOverrideListHandle _Handle, int32_t Index, TElOfficeOpenXMLOverrideHandle AOverride);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLOverrideList_Delete(TElOfficeOpenXMLOverrideListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLOverrideList_Clear(TElOfficeOpenXMLOverrideListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLOverrideList_get_Count(TElOfficeOpenXMLOverrideListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLOverrideList_get_OverrideItems(TElOfficeOpenXMLOverrideListHandle _Handle, int32_t Index, TElOfficeOpenXMLOverrideHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLOverrideList_Create(TElOfficeOpenXMLOverrideListHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDELIST */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCONTENTTYPES
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLContentTypes_Clear(TElOfficeOpenXMLContentTypesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLContentTypes_LoadFromXML(TElOfficeOpenXMLContentTypesHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLContentTypes_SaveToXML(TElOfficeOpenXMLContentTypesHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLContentTypes_get_Defaults(TElOfficeOpenXMLContentTypesHandle _Handle, TElOfficeOpenXMLDefaultListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLContentTypes_get_Overrides(TElOfficeOpenXMLContentTypesHandle _Handle, TElOfficeOpenXMLOverrideListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLContentTypes_Create(TElOfficeOpenXMLContentTypesHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCONTENTTYPES */

#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCSimpleLiteral_Clear(TElOfficeXMLDCSimpleLiteralHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCSimpleLiteral_IsEmpty(TElOfficeXMLDCSimpleLiteralHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCSimpleLiteral_LoadFromXML(TElOfficeXMLDCSimpleLiteralHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCSimpleLiteral_SaveToXML(TElOfficeXMLDCSimpleLiteralHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCSimpleLiteral_get_Language(TElOfficeXMLDCSimpleLiteralHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCSimpleLiteral_set_Language(TElOfficeXMLDCSimpleLiteralHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCSimpleLiteral_get_Value(TElOfficeXMLDCSimpleLiteralHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCSimpleLiteral_set_Value(TElOfficeXMLDCSimpleLiteralHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCSimpleLiteral_Create(const sb_char16_t * pcAName, int32_t szAName, TElOfficeXMLDCSimpleLiteralHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */

#ifdef SB_USE_CLASS_TELOFFICEXMLDCDATE
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCDate_Clear(TElOfficeXMLDCDateHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCDate_IsEmpty(TElOfficeXMLDCDateHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCDate_LoadFromXML(TElOfficeXMLDCDateHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCDate_SaveToXML(TElOfficeXMLDCDateHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCDate_get_Value(TElOfficeXMLDCDateHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCDate_set_Value(TElOfficeXMLDCDateHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCDate_get_ValueUTC(TElOfficeXMLDCDateHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCDate_set_ValueUTC(TElOfficeXMLDCDateHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCDate_get_DateTimeFormat(TElOfficeXMLDCDateHandle _Handle, TSBXMLDateTimeFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCDate_set_DateTimeFormat(TElOfficeXMLDCDateHandle _Handle, TSBXMLDateTimeFormatRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCDate_get_IncludeTimeZone(TElOfficeXMLDCDateHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCDate_set_IncludeTimeZone(TElOfficeXMLDCDateHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDCDate_Create(TElOfficeXMLDCDateHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEXMLDCDATE */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLCoreProperties_Clear(TElOfficeOpenXMLCorePropertiesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLCoreProperties_LoadFromXML(TElOfficeOpenXMLCorePropertiesHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLCoreProperties_SaveToXML(TElOfficeOpenXMLCorePropertiesHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLCoreProperties_get_Category(TElOfficeOpenXMLCorePropertiesHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLCoreProperties_set_Category(TElOfficeOpenXMLCorePropertiesHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLCoreProperties_get_ContentStatus(TElOfficeOpenXMLCorePropertiesHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLCoreProperties_set_ContentStatus(TElOfficeOpenXMLCorePropertiesHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLCoreProperties_get_Creator(TElOfficeOpenXMLCorePropertiesHandle _Handle, TElOfficeXMLDCSimpleLiteralHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLCoreProperties_get_Description(TElOfficeOpenXMLCorePropertiesHandle _Handle, TElOfficeXMLDCSimpleLiteralHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLCoreProperties_get_Identifier(TElOfficeOpenXMLCorePropertiesHandle _Handle, TElOfficeXMLDCSimpleLiteralHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLCoreProperties_get_Language(TElOfficeOpenXMLCorePropertiesHandle _Handle, TElOfficeXMLDCSimpleLiteralHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLCoreProperties_get_LastModifiedBy(TElOfficeOpenXMLCorePropertiesHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLCoreProperties_set_LastModifiedBy(TElOfficeOpenXMLCorePropertiesHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLCoreProperties_get_Revision(TElOfficeOpenXMLCorePropertiesHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLCoreProperties_set_Revision(TElOfficeOpenXMLCorePropertiesHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLCoreProperties_get_Subject(TElOfficeOpenXMLCorePropertiesHandle _Handle, TElOfficeXMLDCSimpleLiteralHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLCoreProperties_get_Title(TElOfficeOpenXMLCorePropertiesHandle _Handle, TElOfficeXMLDCSimpleLiteralHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLCoreProperties_get_Version(TElOfficeOpenXMLCorePropertiesHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLCoreProperties_set_Version(TElOfficeOpenXMLCorePropertiesHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLCoreProperties_Create(TElOfficeOpenXMLCorePropertiesHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES */

#ifdef SB_USE_CLASS_TELOFFICEXMLKEYDATA
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyData_Clear(TElOfficeXMLKeyDataHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyData_LoadFromXML(TElOfficeXMLKeyDataHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyData_SaveToXML(TElOfficeXMLKeyDataHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyData_get_SaltSize(TElOfficeXMLKeyDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyData_set_SaltSize(TElOfficeXMLKeyDataHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyData_get_BlockSize(TElOfficeXMLKeyDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyData_set_BlockSize(TElOfficeXMLKeyDataHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyData_get_KeyBits(TElOfficeXMLKeyDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyData_set_KeyBits(TElOfficeXMLKeyDataHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyData_get_HashSize(TElOfficeXMLKeyDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyData_set_HashSize(TElOfficeXMLKeyDataHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyData_get_CipherAlgorithm(TElOfficeXMLKeyDataHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyData_set_CipherAlgorithm(TElOfficeXMLKeyDataHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyData_get_CipherChaining(TElOfficeXMLKeyDataHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyData_set_CipherChaining(TElOfficeXMLKeyDataHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyData_get_HashAlgorithm(TElOfficeXMLKeyDataHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyData_set_HashAlgorithm(TElOfficeXMLKeyDataHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyData_get_SaltValue(TElOfficeXMLKeyDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyData_set_SaltValue(TElOfficeXMLKeyDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyData_Create(TElOfficeXMLKeyDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYDATA */

#ifdef SB_USE_CLASS_TELOFFICEXMLDATAINTEGRITY
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDataIntegrity_Clear(TElOfficeXMLDataIntegrityHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDataIntegrity_LoadFromXML(TElOfficeXMLDataIntegrityHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDataIntegrity_SaveToXML(TElOfficeXMLDataIntegrityHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDataIntegrity_get_EncryptedHmacKey(TElOfficeXMLDataIntegrityHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDataIntegrity_set_EncryptedHmacKey(TElOfficeXMLDataIntegrityHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDataIntegrity_get_EncryptedHmacValue(TElOfficeXMLDataIntegrityHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDataIntegrity_set_EncryptedHmacValue(TElOfficeXMLDataIntegrityHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLDataIntegrity_Create(TElOfficeXMLDataIntegrityHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEXMLDATAINTEGRITY */

#ifdef SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyEncryptor_get_URI(TElOfficeXMLKeyEncryptorHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyEncryptor_Create(TElOfficeXMLKeyEncryptorHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR */

#ifdef SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTORS
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyEncryptors_Add(TElOfficeXMLKeyEncryptorsHandle _Handle, TElOfficeXMLKeyEncryptorHandle AKeyEncryptor, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyEncryptors_Insert(TElOfficeXMLKeyEncryptorsHandle _Handle, int32_t Index, TElOfficeXMLKeyEncryptorHandle AKeyEncryptor);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyEncryptors_Delete(TElOfficeXMLKeyEncryptorsHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyEncryptors_Clear(TElOfficeXMLKeyEncryptorsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyEncryptors_LoadFromXML(TElOfficeXMLKeyEncryptorsHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyEncryptors_SaveToXML(TElOfficeXMLKeyEncryptorsHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyEncryptors_get_Count(TElOfficeXMLKeyEncryptorsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyEncryptors_get_KeyEncryptors(TElOfficeXMLKeyEncryptorsHandle _Handle, int32_t Index, TElOfficeXMLKeyEncryptorHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLKeyEncryptors_Create(TElOfficeXMLKeyEncryptorsHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTORS */

#ifdef SB_USE_CLASS_TELOFFICEXMLPASSWORDKEYENCRYPTOR
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_Clear(TElOfficeXMLPasswordKeyEncryptorHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_LoadFromXML(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_SaveToXML(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_get_SaltSize(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_set_SaltSize(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_get_BlockSize(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_set_BlockSize(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_get_KeyBits(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_set_KeyBits(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_get_HashSize(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_set_HashSize(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_get_CipherAlgorithm(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_set_CipherAlgorithm(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_get_CipherChaining(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_set_CipherChaining(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_get_HashAlgorithm(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_set_HashAlgorithm(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_get_SaltValue(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_set_SaltValue(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_get_SpinCount(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_set_SpinCount(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_get_EncryptedVerifierHashInput(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_set_EncryptedVerifierHashInput(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_get_EncryptedVerifierHashValue(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_set_EncryptedVerifierHashValue(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_get_EncryptedKeyValue(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_set_EncryptedKeyValue(TElOfficeXMLPasswordKeyEncryptorHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPasswordKeyEncryptor_Create(TElOfficeXMLPasswordKeyEncryptorHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEXMLPASSWORDKEYENCRYPTOR */

#ifdef SB_USE_CLASS_TELOFFICEXMLENCRYPTION
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLEncryption_Clear(TElOfficeXMLEncryptionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLEncryption_LoadFromXML(TElOfficeXMLEncryptionHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLEncryption_SaveToXML(TElOfficeXMLEncryptionHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLEncryption_get_DataIntegrity(TElOfficeXMLEncryptionHandle _Handle, TElOfficeXMLDataIntegrityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLEncryption_get_KeyData(TElOfficeXMLEncryptionHandle _Handle, TElOfficeXMLKeyDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLEncryption_get_KeyEncryptors(TElOfficeXMLEncryptionHandle _Handle, TElOfficeXMLKeyEncryptorsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLEncryption_Create(TElOfficeXMLEncryptionHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEXMLENCRYPTION */

#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATURETIME
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureTime_Clear(TElOfficeXMLSignatureTimeHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureTime_LoadFromXML(TElOfficeXMLSignatureTimeHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureTime_SaveToXML(TElOfficeXMLSignatureTimeHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureTime_get_Format(TElOfficeXMLSignatureTimeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureTime_set_Format(TElOfficeXMLSignatureTimeHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureTime_get_Value(TElOfficeXMLSignatureTimeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureTime_set_Value(TElOfficeXMLSignatureTimeHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureTime_get_ValueUTC(TElOfficeXMLSignatureTimeHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureTime_set_ValueUTC(TElOfficeXMLSignatureTimeHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureTime_Create(TElOfficeXMLSignatureTimeHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATURETIME */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPTRANSFORM
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_GetDefaultTransformAlgorithmURI(sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_GetDefaultTransformAlgorithmURI_1(TElOfficeOpenXMLRelationshipTransformHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_IsTransformAlgorithmSupported(const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_IsTransformAlgorithmSupported_1(TElOfficeOpenXMLRelationshipTransformHandle _Handle, const sb_char16_t * pcAlgorithm, int32_t szAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_Clear(TElOfficeOpenXMLRelationshipTransformHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_AddSourceId(TElOfficeOpenXMLRelationshipTransformHandle _Handle, const sb_char16_t * pcSourceId, int32_t szSourceId, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_AddSourceType(TElOfficeOpenXMLRelationshipTransformHandle _Handle, const sb_char16_t * pcSourceType, int32_t szSourceType, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_DeleteSourceId(TElOfficeOpenXMLRelationshipTransformHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_DeleteSourceType(TElOfficeOpenXMLRelationshipTransformHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_LoadFromXML(TElOfficeOpenXMLRelationshipTransformHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_SaveToXML(TElOfficeOpenXMLRelationshipTransformHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_TransformData(TElOfficeOpenXMLRelationshipTransformHandle _Handle, const uint8_t pData[], int32_t szData, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_TransformData_1(TElOfficeOpenXMLRelationshipTransformHandle _Handle, TElXMLDOMNodeHandle Node, TElXMLDOMNodeHandle Reference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_TransformData_2(TElOfficeOpenXMLRelationshipTransformHandle _Handle, TElXMLDOMNodeListHandle Nodes, const TElXMLDOMNodeHandle pReference[], int32_t szReference, TSBTransformedDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_TransformNode(TElOfficeOpenXMLRelationshipTransformHandle _Handle, TElXMLDOMNodeHandle Node, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_get_SourceIdCount(TElOfficeOpenXMLRelationshipTransformHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_get_SourceTypeCount(TElOfficeOpenXMLRelationshipTransformHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_get_SourceIds(TElOfficeOpenXMLRelationshipTransformHandle _Handle, int32_t Index, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_get_SourceTypes(TElOfficeOpenXMLRelationshipTransformHandle _Handle, int32_t Index, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeOpenXMLRelationshipTransform_Create(TElOfficeOpenXMLRelationshipTransformHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPTRANSFORM */

#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATUREINFOV1
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_Clear(TElOfficeXMLSignatureInfoV1Handle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_CheckReferences(TElOfficeXMLSignatureInfoV1Handle _Handle, TElXMLReferenceListHandle Refs, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_CreateReferences(TElOfficeXMLSignatureInfoV1Handle _Handle, TElXMLReferenceListHandle Refs, TElXMLDigestMethodRaw DigestMethod);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_CreateObjects(TElOfficeXMLSignatureInfoV1Handle _Handle, TElXMLObjectListHandle Objects, const sb_char16_t * pcTarget, int32_t szTarget, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_LoadFromObjectList(TElOfficeXMLSignatureInfoV1Handle _Handle, TElXMLObjectListHandle Objects);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_Included(TElOfficeXMLSignatureInfoV1Handle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_Included(TElOfficeXMLSignatureInfoV1Handle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_ApplicationVersion(TElOfficeXMLSignatureInfoV1Handle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_ApplicationVersion(TElOfficeXMLSignatureInfoV1Handle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_ColorDepth(TElOfficeXMLSignatureInfoV1Handle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_ColorDepth(TElOfficeXMLSignatureInfoV1Handle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_DelegateSuggestedSigner(TElOfficeXMLSignatureInfoV1Handle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_DelegateSuggestedSigner(TElOfficeXMLSignatureInfoV1Handle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_DelegateSuggestedSigner2(TElOfficeXMLSignatureInfoV1Handle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_DelegateSuggestedSigner2(TElOfficeXMLSignatureInfoV1Handle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_DelegateSuggestedSignerEmail(TElOfficeXMLSignatureInfoV1Handle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_DelegateSuggestedSignerEmail(TElOfficeXMLSignatureInfoV1Handle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_HorizontalResolution(TElOfficeXMLSignatureInfoV1Handle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_HorizontalResolution(TElOfficeXMLSignatureInfoV1Handle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_ManifestHashAlgorithm(TElOfficeXMLSignatureInfoV1Handle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_ManifestHashAlgorithm(TElOfficeXMLSignatureInfoV1Handle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_Monitors(TElOfficeXMLSignatureInfoV1Handle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_Monitors(TElOfficeXMLSignatureInfoV1Handle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_OfficeVersion(TElOfficeXMLSignatureInfoV1Handle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_OfficeVersion(TElOfficeXMLSignatureInfoV1Handle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_SetupID(TElOfficeXMLSignatureInfoV1Handle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_SetupID(TElOfficeXMLSignatureInfoV1Handle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_SignatureComments(TElOfficeXMLSignatureInfoV1Handle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_SignatureComments(TElOfficeXMLSignatureInfoV1Handle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_SignatureImage(TElOfficeXMLSignatureInfoV1Handle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_SignatureImage(TElOfficeXMLSignatureInfoV1Handle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_SignatureProviderDetails(TElOfficeXMLSignatureInfoV1Handle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_SignatureProviderDetails(TElOfficeXMLSignatureInfoV1Handle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_SignatureProviderId(TElOfficeXMLSignatureInfoV1Handle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_SignatureProviderId(TElOfficeXMLSignatureInfoV1Handle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_SignatureProviderUrl(TElOfficeXMLSignatureInfoV1Handle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_SignatureProviderUrl(TElOfficeXMLSignatureInfoV1Handle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_SignatureText(TElOfficeXMLSignatureInfoV1Handle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_SignatureText(TElOfficeXMLSignatureInfoV1Handle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_SignatureType(TElOfficeXMLSignatureInfoV1Handle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_SignatureType(TElOfficeXMLSignatureInfoV1Handle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_VerticalResolution(TElOfficeXMLSignatureInfoV1Handle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_VerticalResolution(TElOfficeXMLSignatureInfoV1Handle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_WindowsVersion(TElOfficeXMLSignatureInfoV1Handle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_WindowsVersion(TElOfficeXMLSignatureInfoV1Handle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_ValidSignatureLnImage(TElOfficeXMLSignatureInfoV1Handle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_ValidSignatureLnImage(TElOfficeXMLSignatureInfoV1Handle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_get_InvalidSignatureLnImage(TElOfficeXMLSignatureInfoV1Handle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_set_InvalidSignatureLnImage(TElOfficeXMLSignatureInfoV1Handle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureInfoV1_Create(TElOfficeXMLSignatureInfoV1Handle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATUREINFOV1 */

#ifdef SB_USE_CLASS_TELOFFICEXMLSPOTLOCATION
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSpotLocation_Clear(TElOfficeXMLSpotLocationHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSpotLocation_LoadFromXML(TElOfficeXMLSpotLocationHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSpotLocation_SaveToXML(TElOfficeXMLSpotLocationHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSpotLocation_get_PageURI(TElOfficeXMLSpotLocationHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSpotLocation_set_PageURI(TElOfficeXMLSpotLocationHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSpotLocation_get_StartX(TElOfficeXMLSpotLocationHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSpotLocation_set_StartX(TElOfficeXMLSpotLocationHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSpotLocation_get_StartY(TElOfficeXMLSpotLocationHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSpotLocation_set_StartY(TElOfficeXMLSpotLocationHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSpotLocation_Create(TElOfficeXMLSpotLocationHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEXMLSPOTLOCATION */

#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATUREDEFINITION
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureDefinition_Clear(TElOfficeXMLSignatureDefinitionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureDefinition_LoadFromXML(TElOfficeXMLSignatureDefinitionHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureDefinition_SaveToXML(TElOfficeXMLSignatureDefinitionHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureDefinition_get_Intent(TElOfficeXMLSignatureDefinitionHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureDefinition_set_Intent(TElOfficeXMLSignatureDefinitionHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureDefinition_get_SignBy(TElOfficeXMLSignatureDefinitionHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureDefinition_set_SignBy(TElOfficeXMLSignatureDefinitionHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureDefinition_get_SignByUTC(TElOfficeXMLSignatureDefinitionHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureDefinition_set_SignByUTC(TElOfficeXMLSignatureDefinitionHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureDefinition_get_SigningLocation(TElOfficeXMLSignatureDefinitionHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureDefinition_set_SigningLocation(TElOfficeXMLSignatureDefinitionHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureDefinition_get_SignerName(TElOfficeXMLSignatureDefinitionHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureDefinition_set_SignerName(TElOfficeXMLSignatureDefinitionHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureDefinition_get_SpotID(TElOfficeXMLSignatureDefinitionHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureDefinition_set_SpotID(TElOfficeXMLSignatureDefinitionHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureDefinition_get_SpotLocation(TElOfficeXMLSignatureDefinitionHandle _Handle, TElOfficeXMLSpotLocationHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLSignatureDefinition_Create(TElOfficeXMLSignatureDefinitionHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATUREDEFINITION */

#ifdef SB_USE_CLASS_TELOFFICEXMLFIXEDDOCUMENTSEQUENCE
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLFixedDocumentSequence_Add(TElOfficeXMLFixedDocumentSequenceHandle _Handle, const sb_char16_t * pcDocRef, int32_t szDocRef, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLFixedDocumentSequence_Delete(TElOfficeXMLFixedDocumentSequenceHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLFixedDocumentSequence_Clear(TElOfficeXMLFixedDocumentSequenceHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLFixedDocumentSequence_LoadFromXML(TElOfficeXMLFixedDocumentSequenceHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLFixedDocumentSequence_SaveToXML(TElOfficeXMLFixedDocumentSequenceHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLFixedDocumentSequence_get_Count(TElOfficeXMLFixedDocumentSequenceHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLFixedDocumentSequence_get_DocumentReferences(TElOfficeXMLFixedDocumentSequenceHandle _Handle, int32_t Index, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLFixedDocumentSequence_Create(TElOfficeXMLFixedDocumentSequenceHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEXMLFIXEDDOCUMENTSEQUENCE */

#ifdef SB_USE_CLASS_TELOFFICEXMLPAGECONTENT
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPageContent_AddLinkTarget(TElOfficeXMLPageContentHandle _Handle, const sb_char16_t * pcName, int32_t szName, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPageContent_DeleteLinkTarget(TElOfficeXMLPageContentHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPageContent_Clear(TElOfficeXMLPageContentHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPageContent_LoadFromXML(TElOfficeXMLPageContentHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPageContent_SaveToXML(TElOfficeXMLPageContentHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPageContent_get_Source(TElOfficeXMLPageContentHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPageContent_set_Source(TElOfficeXMLPageContentHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPageContent_get_Width(TElOfficeXMLPageContentHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPageContent_set_Width(TElOfficeXMLPageContentHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPageContent_get_Height(TElOfficeXMLPageContentHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPageContent_set_Height(TElOfficeXMLPageContentHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPageContent_get_LinkTargetCount(TElOfficeXMLPageContentHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPageContent_get_LinkTargets(TElOfficeXMLPageContentHandle _Handle, int32_t Index, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLPageContent_Create(TElOfficeXMLPageContentHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEXMLPAGECONTENT */

#ifdef SB_USE_CLASS_TELOFFICEXMLFIXEDDOCUMENT
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLFixedDocument_Add(TElOfficeXMLFixedDocumentHandle _Handle, TElOfficeXMLPageContentHandle PageContent, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLFixedDocument_Delete(TElOfficeXMLFixedDocumentHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLFixedDocument_Clear(TElOfficeXMLFixedDocumentHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLFixedDocument_LoadFromXML(TElOfficeXMLFixedDocumentHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLFixedDocument_SaveToXML(TElOfficeXMLFixedDocumentHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLFixedDocument_get_Count(TElOfficeXMLFixedDocumentHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLFixedDocument_get_PageContents(TElOfficeXMLFixedDocumentHandle _Handle, int32_t Index, TElOfficeXMLPageContentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeXMLFixedDocument_Create(TElOfficeXMLFixedDocumentHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEXMLFIXEDDOCUMENT */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTALGORITHM
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestAlgorithm_Clear(TElOpenOfficeXMLManifestAlgorithmHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestAlgorithm_LoadFromXML(TElOpenOfficeXMLManifestAlgorithmHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestAlgorithm_SaveToXML(TElOpenOfficeXMLManifestAlgorithmHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestAlgorithm_get_AlgorithmName(TElOpenOfficeXMLManifestAlgorithmHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestAlgorithm_set_AlgorithmName(TElOpenOfficeXMLManifestAlgorithmHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestAlgorithm_get_IV(TElOpenOfficeXMLManifestAlgorithmHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestAlgorithm_set_IV(TElOpenOfficeXMLManifestAlgorithmHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestAlgorithm_Create(TElOpenOfficeXMLManifestAlgorithmHandle * OutResult);
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTALGORITHM */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTKEYDERIVATION
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestKeyDerivation_Clear(TElOpenOfficeXMLManifestKeyDerivationHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestKeyDerivation_LoadFromXML(TElOpenOfficeXMLManifestKeyDerivationHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestKeyDerivation_SaveToXML(TElOpenOfficeXMLManifestKeyDerivationHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestKeyDerivation_get_IterationCount(TElOpenOfficeXMLManifestKeyDerivationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestKeyDerivation_set_IterationCount(TElOpenOfficeXMLManifestKeyDerivationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestKeyDerivation_get_KeyDerivationName(TElOpenOfficeXMLManifestKeyDerivationHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestKeyDerivation_set_KeyDerivationName(TElOpenOfficeXMLManifestKeyDerivationHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestKeyDerivation_get_KeySize(TElOpenOfficeXMLManifestKeyDerivationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestKeyDerivation_set_KeySize(TElOpenOfficeXMLManifestKeyDerivationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestKeyDerivation_get_Salt(TElOpenOfficeXMLManifestKeyDerivationHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestKeyDerivation_set_Salt(TElOpenOfficeXMLManifestKeyDerivationHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestKeyDerivation_Create(TElOpenOfficeXMLManifestKeyDerivationHandle * OutResult);
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTKEYDERIVATION */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTSTARTKEYGENERATION
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestStartKeyGeneration_Clear(TElOpenOfficeXMLManifestStartKeyGenerationHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestStartKeyGeneration_LoadFromXML(TElOpenOfficeXMLManifestStartKeyGenerationHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestStartKeyGeneration_SaveToXML(TElOpenOfficeXMLManifestStartKeyGenerationHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestStartKeyGeneration_get_KeySize(TElOpenOfficeXMLManifestStartKeyGenerationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestStartKeyGeneration_set_KeySize(TElOpenOfficeXMLManifestStartKeyGenerationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestStartKeyGeneration_get_StartKeyGenerationName(TElOpenOfficeXMLManifestStartKeyGenerationHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestStartKeyGeneration_set_StartKeyGenerationName(TElOpenOfficeXMLManifestStartKeyGenerationHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestStartKeyGeneration_Create(TElOpenOfficeXMLManifestStartKeyGenerationHandle * OutResult);
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTSTARTKEYGENERATION */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTENCRYPTIONDATA
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestEncryptionData_Clear(TElOpenOfficeXMLManifestEncryptionDataHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestEncryptionData_LoadFromXML(TElOpenOfficeXMLManifestEncryptionDataHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestEncryptionData_SaveToXML(TElOpenOfficeXMLManifestEncryptionDataHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestEncryptionData_get_Checksum(TElOpenOfficeXMLManifestEncryptionDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestEncryptionData_set_Checksum(TElOpenOfficeXMLManifestEncryptionDataHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestEncryptionData_get_ChecksumType(TElOpenOfficeXMLManifestEncryptionDataHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestEncryptionData_set_ChecksumType(TElOpenOfficeXMLManifestEncryptionDataHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestEncryptionData_get_Algorithm(TElOpenOfficeXMLManifestEncryptionDataHandle _Handle, TElOpenOfficeXMLManifestAlgorithmHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestEncryptionData_get_KeyDerivation(TElOpenOfficeXMLManifestEncryptionDataHandle _Handle, TElOpenOfficeXMLManifestKeyDerivationHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestEncryptionData_get_StartKeyGeneration(TElOpenOfficeXMLManifestEncryptionDataHandle _Handle, TElOpenOfficeXMLManifestStartKeyGenerationHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestEncryptionData_Create(TElOpenOfficeXMLManifestEncryptionDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTENCRYPTIONDATA */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestFileEntry_Clear(TElOpenOfficeXMLManifestFileEntryHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestFileEntry_LoadFromXML(TElOpenOfficeXMLManifestFileEntryHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestFileEntry_SaveToXML(TElOpenOfficeXMLManifestFileEntryHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestFileEntry_get_IsEncrypted(TElOpenOfficeXMLManifestFileEntryHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestFileEntry_get_EncryptionData(TElOpenOfficeXMLManifestFileEntryHandle _Handle, TElOpenOfficeXMLManifestEncryptionDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestFileEntry_get_FullPath(TElOpenOfficeXMLManifestFileEntryHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestFileEntry_set_FullPath(TElOpenOfficeXMLManifestFileEntryHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestFileEntry_get_MediaType(TElOpenOfficeXMLManifestFileEntryHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestFileEntry_set_MediaType(TElOpenOfficeXMLManifestFileEntryHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestFileEntry_get_PreferredViewMode(TElOpenOfficeXMLManifestFileEntryHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestFileEntry_set_PreferredViewMode(TElOpenOfficeXMLManifestFileEntryHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestFileEntry_get_Size(TElOpenOfficeXMLManifestFileEntryHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestFileEntry_set_Size(TElOpenOfficeXMLManifestFileEntryHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestFileEntry_get_Version(TElOpenOfficeXMLManifestFileEntryHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestFileEntry_set_Version(TElOpenOfficeXMLManifestFileEntryHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifestFileEntry_Create(TElOpenOfficeXMLManifestFileEntryHandle * OutResult);
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFEST
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifest_Add(TElOpenOfficeXMLManifestHandle _Handle, TElOpenOfficeXMLManifestFileEntryHandle AFileEntry, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifest_Add_1(TElOpenOfficeXMLManifestHandle _Handle, const sb_char16_t * pcFullPath, int32_t szFullPath, const sb_char16_t * pcMediaType, int32_t szMediaType, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifest_Insert(TElOpenOfficeXMLManifestHandle _Handle, int32_t Index, TElOpenOfficeXMLManifestFileEntryHandle AFileEntry);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifest_Delete(TElOpenOfficeXMLManifestHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifest_Clear(TElOpenOfficeXMLManifestHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifest_GetFileEntryByFullPath(TElOpenOfficeXMLManifestHandle _Handle, const sb_char16_t * pcFullPath, int32_t szFullPath, TElOpenOfficeXMLManifestFileEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifest_LoadFromXML(TElOpenOfficeXMLManifestHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifest_SaveToXML(TElOpenOfficeXMLManifestHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifest_get_Count(TElOpenOfficeXMLManifestHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifest_get_FileEntries(TElOpenOfficeXMLManifestHandle _Handle, int32_t Index, TElOpenOfficeXMLManifestFileEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficeXMLManifest_Create(TElOpenOfficeXMLManifestHandle * OutResult);
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFEST */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElOfficeOpenXMLElement;
class TElOfficeOpenXMLRelationship;
class TElOfficeOpenXMLRelationships;
class TElOfficeOpenXMLDefault;
class TElOfficeOpenXMLDefaultList;
class TElOfficeOpenXMLOverride;
class TElOfficeOpenXMLOverrideList;
class TElOfficeOpenXMLContentTypes;
class TElOfficeXMLDCSimpleLiteral;
class TElOfficeXMLDCDate;
class TElOfficeOpenXMLCoreProperties;
class TElOfficeXMLKeyData;
class TElOfficeXMLDataIntegrity;
class TElOfficeXMLKeyEncryptor;
class TElOfficeXMLKeyEncryptors;
class TElOfficeXMLPasswordKeyEncryptor;
class TElOfficeXMLEncryption;
class TElOfficeXMLSignatureTime;
class TElOfficeOpenXMLRelationshipTransform;
class TElOfficeXMLSignatureInfoV1;
class TElOfficeXMLSpotLocation;
class TElOfficeXMLSignatureDefinition;
class TElOfficeXMLFixedDocumentSequence;
class TElOfficeXMLPageContent;
class TElOfficeXMLFixedDocument;
class TElOpenOfficeXMLManifestAlgorithm;
class TElOpenOfficeXMLManifestKeyDerivation;
class TElOpenOfficeXMLManifestStartKeyGeneration;
class TElOpenOfficeXMLManifestEncryptionData;
class TElOpenOfficeXMLManifestFileEntry;
class TElOpenOfficeXMLManifest;

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLELEMENT
class TElOfficeOpenXMLElement: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElOfficeOpenXMLElement)
	public:
		virtual void Clear();

		virtual bool get_IsModified();

		virtual void set_IsModified(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IsModified, set_IsModified, TElOfficeOpenXMLElement, IsModified);

		TElOfficeOpenXMLElement(TElOfficeOpenXMLElementHandle handle, TElOwnHandle ownHandle);

		TElOfficeOpenXMLElement();

};
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLELEMENT */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP
class TElOfficeOpenXMLRelationship: public TElOfficeOpenXMLElement
{
	private:
		SB_DISABLE_COPY(TElOfficeOpenXMLRelationship)
	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_RelationshipType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_RelationshipType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_RelationshipType(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_RelationshipType(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_Target(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Target(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Target(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Target(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual TSBOfficeOpenXMLTargetMode get_TargetMode();

		virtual void set_TargetMode(TSBOfficeOpenXMLTargetMode Value);

		SB_DECLARE_PROPERTY(TSBOfficeOpenXMLTargetMode, get_TargetMode, set_TargetMode, TElOfficeOpenXMLRelationship, TargetMode);

		TElOfficeOpenXMLRelationship(TElOfficeOpenXMLRelationshipHandle handle, TElOwnHandle ownHandle);

		TElOfficeOpenXMLRelationship();

};
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS
class TElOfficeOpenXMLRelationships: public TElOfficeOpenXMLElement
{
	private:
		SB_DISABLE_COPY(TElOfficeOpenXMLRelationships)
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP
		TElOfficeOpenXMLRelationship* _Inst_Relationships;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP
		int32_t Add(TElOfficeOpenXMLRelationship &ARelationship);

		int32_t Add(TElOfficeOpenXMLRelationship *ARelationship);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP */

		int32_t Add(const sb_u16string &ID, const sb_u16string &Target, const sb_u16string &RelationshipType);
#ifdef SB_U16STRING_USED
		int32_t Add(const std::wstring &ID, const std::wstring &Target, const std::wstring &RelationshipType);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP
		void Insert(int32_t Index, TElOfficeOpenXMLRelationship &ARelationship);

		void Insert(int32_t Index, TElOfficeOpenXMLRelationship *ARelationship);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP */

		void Delete(int32_t Index);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP
		TElOfficeOpenXMLRelationshipHandle CreateRelationship(const sb_u16string &Target, TSBOfficeOpenXMLTargetMode TargetMode, const sb_u16string &RelationshipType, const sb_u16string &ID);
#ifdef SB_U16STRING_USED
		TElOfficeOpenXMLRelationshipHandle CreateRelationship(const std::wstring &Target, TSBOfficeOpenXMLTargetMode TargetMode, const std::wstring &RelationshipType, const std::wstring &ID);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP
		TElOfficeOpenXMLRelationshipHandle GetRelationshipById(const sb_u16string &ID);
#ifdef SB_U16STRING_USED
		TElOfficeOpenXMLRelationshipHandle GetRelationshipById(const std::wstring &ID);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP
		TElOfficeOpenXMLRelationshipHandle GetRelationshipByType(const sb_u16string &RelType);
#ifdef SB_U16STRING_USED
		TElOfficeOpenXMLRelationshipHandle GetRelationshipByType(const std::wstring &RelType);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP */

		void SortRelationshipsById();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElOfficeOpenXMLRelationships, Count);

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP
		virtual TElOfficeOpenXMLRelationship* get_Relationships(int32_t Index);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIP */

		TElOfficeOpenXMLRelationships(TElOfficeOpenXMLRelationshipsHandle handle, TElOwnHandle ownHandle);

		TElOfficeOpenXMLRelationships();

		virtual ~TElOfficeOpenXMLRelationships();

};
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT
class TElOfficeOpenXMLDefault: public TElOfficeOpenXMLElement
{
	private:
		SB_DISABLE_COPY(TElOfficeOpenXMLDefault)
	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_ContentType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ContentType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ContentType(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ContentType(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_Extension(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Extension(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Extension(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Extension(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElOfficeOpenXMLDefault(TElOfficeOpenXMLDefaultHandle handle, TElOwnHandle ownHandle);

		TElOfficeOpenXMLDefault();

};
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDEFAULTLIST
class TElOfficeOpenXMLDefaultList: public TObject
{
	private:
		SB_DISABLE_COPY(TElOfficeOpenXMLDefaultList)
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT
		TElOfficeOpenXMLDefault* _Inst_DefaultItems;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT
		int32_t Add(TElOfficeOpenXMLDefault &ADefault);

		int32_t Add(TElOfficeOpenXMLDefault *ADefault);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT
		void Insert(int32_t Index, TElOfficeOpenXMLDefault &ADefault);

		void Insert(int32_t Index, TElOfficeOpenXMLDefault *ADefault);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT */

		void Delete(int32_t Index);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElOfficeOpenXMLDefaultList, Count);

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT
		virtual TElOfficeOpenXMLDefault* get_DefaultItems(int32_t Index);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDEFAULT */

		TElOfficeOpenXMLDefaultList(TElOfficeOpenXMLDefaultListHandle handle, TElOwnHandle ownHandle);

		TElOfficeOpenXMLDefaultList();

		virtual ~TElOfficeOpenXMLDefaultList();

};
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDEFAULTLIST */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE
class TElOfficeOpenXMLOverride: public TElOfficeOpenXMLElement
{
	private:
		SB_DISABLE_COPY(TElOfficeOpenXMLOverride)
	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_ContentType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ContentType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ContentType(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ContentType(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_PartName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_PartName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_PartName(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_PartName(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElOfficeOpenXMLOverride(TElOfficeOpenXMLOverrideHandle handle, TElOwnHandle ownHandle);

		TElOfficeOpenXMLOverride();

};
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDELIST
class TElOfficeOpenXMLOverrideList: public TObject
{
	private:
		SB_DISABLE_COPY(TElOfficeOpenXMLOverrideList)
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE
		TElOfficeOpenXMLOverride* _Inst_OverrideItems;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE
		int32_t Add(TElOfficeOpenXMLOverride &AOverride);

		int32_t Add(TElOfficeOpenXMLOverride *AOverride);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE
		void Insert(int32_t Index, TElOfficeOpenXMLOverride &AOverride);

		void Insert(int32_t Index, TElOfficeOpenXMLOverride *AOverride);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE */

		void Delete(int32_t Index);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElOfficeOpenXMLOverrideList, Count);

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE
		virtual TElOfficeOpenXMLOverride* get_OverrideItems(int32_t Index);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDE */

		TElOfficeOpenXMLOverrideList(TElOfficeOpenXMLOverrideListHandle handle, TElOwnHandle ownHandle);

		TElOfficeOpenXMLOverrideList();

		virtual ~TElOfficeOpenXMLOverrideList();

};
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDELIST */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCONTENTTYPES
class TElOfficeOpenXMLContentTypes: public TElOfficeOpenXMLElement
{
	private:
		SB_DISABLE_COPY(TElOfficeOpenXMLContentTypes)
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDEFAULTLIST
		TElOfficeOpenXMLDefaultList* _Inst_Defaults;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDEFAULTLIST */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDELIST
		TElOfficeOpenXMLOverrideList* _Inst_Overrides;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDELIST */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLDEFAULTLIST
		virtual TElOfficeOpenXMLDefaultList* get_Defaults();

		SB_DECLARE_PROPERTY_GET(TElOfficeOpenXMLDefaultList*, get_Defaults, TElOfficeOpenXMLContentTypes, Defaults);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLDEFAULTLIST */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDELIST
		virtual TElOfficeOpenXMLOverrideList* get_Overrides();

		SB_DECLARE_PROPERTY_GET(TElOfficeOpenXMLOverrideList*, get_Overrides, TElOfficeOpenXMLContentTypes, Overrides);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLOVERRIDELIST */

		TElOfficeOpenXMLContentTypes(TElOfficeOpenXMLContentTypesHandle handle, TElOwnHandle ownHandle);

		TElOfficeOpenXMLContentTypes();

		virtual ~TElOfficeOpenXMLContentTypes();

};
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCONTENTTYPES */

#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
class TElOfficeXMLDCSimpleLiteral: public TElOfficeOpenXMLElement
{
	private:
		SB_DISABLE_COPY(TElOfficeXMLDCSimpleLiteral)
	public:
		virtual void Clear();

		bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_Language(std::string &OutResult);

		virtual void set_Language(const std::string &Value);

		virtual void get_Value(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Value(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Value(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Value(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElOfficeXMLDCSimpleLiteral(TElOfficeXMLDCSimpleLiteralHandle handle, TElOwnHandle ownHandle);

		explicit TElOfficeXMLDCSimpleLiteral(const sb_u16string &AName);

#ifdef SB_U16STRING_USED
		explicit TElOfficeXMLDCSimpleLiteral(const std::wstring &AName);

#endif /* SB_U16STRING_USED */
};
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */

#ifdef SB_USE_CLASS_TELOFFICEXMLDCDATE
class TElOfficeXMLDCDate: public TElOfficeOpenXMLElement
{
	private:
		SB_DISABLE_COPY(TElOfficeXMLDCDate)
	public:
		virtual void Clear();

		bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_Value(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Value(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Value(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Value(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual int64_t get_ValueUTC();

		virtual void set_ValueUTC(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ValueUTC, set_ValueUTC, TElOfficeXMLDCDate, ValueUTC);

		virtual TSBXMLDateTimeFormat get_DateTimeFormat();

		virtual void set_DateTimeFormat(TSBXMLDateTimeFormat Value);

		SB_DECLARE_PROPERTY(TSBXMLDateTimeFormat, get_DateTimeFormat, set_DateTimeFormat, TElOfficeXMLDCDate, DateTimeFormat);

		virtual bool get_IncludeTimeZone();

		virtual void set_IncludeTimeZone(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeTimeZone, set_IncludeTimeZone, TElOfficeXMLDCDate, IncludeTimeZone);

		TElOfficeXMLDCDate(TElOfficeXMLDCDateHandle handle, TElOwnHandle ownHandle);

		TElOfficeXMLDCDate();

};
#endif /* SB_USE_CLASS_TELOFFICEXMLDCDATE */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES
class TElOfficeOpenXMLCoreProperties: public TElOfficeOpenXMLElement
{
	private:
		SB_DISABLE_COPY(TElOfficeOpenXMLCoreProperties)
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
		TElOfficeXMLDCSimpleLiteral* _Inst_Creator;
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
		TElOfficeXMLDCSimpleLiteral* _Inst_Description;
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
		TElOfficeXMLDCSimpleLiteral* _Inst_Identifier;
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
		TElOfficeXMLDCSimpleLiteral* _Inst_Language;
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
		TElOfficeXMLDCSimpleLiteral* _Inst_Subject;
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
		TElOfficeXMLDCSimpleLiteral* _Inst_Title;
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_Category(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Category(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Category(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Category(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_ContentStatus(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ContentStatus(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ContentStatus(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ContentStatus(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
		virtual TElOfficeXMLDCSimpleLiteral* get_Creator();

		SB_DECLARE_PROPERTY_GET(TElOfficeXMLDCSimpleLiteral*, get_Creator, TElOfficeOpenXMLCoreProperties, Creator);
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */

#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
		virtual TElOfficeXMLDCSimpleLiteral* get_Description();

		SB_DECLARE_PROPERTY_GET(TElOfficeXMLDCSimpleLiteral*, get_Description, TElOfficeOpenXMLCoreProperties, Description);
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */

#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
		virtual TElOfficeXMLDCSimpleLiteral* get_Identifier();

		SB_DECLARE_PROPERTY_GET(TElOfficeXMLDCSimpleLiteral*, get_Identifier, TElOfficeOpenXMLCoreProperties, Identifier);
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */

#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
		virtual TElOfficeXMLDCSimpleLiteral* get_Language();

		SB_DECLARE_PROPERTY_GET(TElOfficeXMLDCSimpleLiteral*, get_Language, TElOfficeOpenXMLCoreProperties, Language);
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */

		virtual void get_LastModifiedBy(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_LastModifiedBy(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_LastModifiedBy(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_LastModifiedBy(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_Revision(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Revision(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Revision(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Revision(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
		virtual TElOfficeXMLDCSimpleLiteral* get_Subject();

		SB_DECLARE_PROPERTY_GET(TElOfficeXMLDCSimpleLiteral*, get_Subject, TElOfficeOpenXMLCoreProperties, Subject);
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */

#ifdef SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL
		virtual TElOfficeXMLDCSimpleLiteral* get_Title();

		SB_DECLARE_PROPERTY_GET(TElOfficeXMLDCSimpleLiteral*, get_Title, TElOfficeOpenXMLCoreProperties, Title);
#endif /* SB_USE_CLASS_TELOFFICEXMLDCSIMPLELITERAL */

		virtual void get_Version(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Version(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Version(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Version(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElOfficeOpenXMLCoreProperties(TElOfficeOpenXMLCorePropertiesHandle handle, TElOwnHandle ownHandle);

		TElOfficeOpenXMLCoreProperties();

		virtual ~TElOfficeOpenXMLCoreProperties();

};
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES */

#ifdef SB_USE_CLASS_TELOFFICEXMLKEYDATA
class TElOfficeXMLKeyData: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElOfficeXMLKeyData)
	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual int32_t get_SaltSize();

		virtual void set_SaltSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SaltSize, set_SaltSize, TElOfficeXMLKeyData, SaltSize);

		virtual int32_t get_BlockSize();

		virtual void set_BlockSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_BlockSize, set_BlockSize, TElOfficeXMLKeyData, BlockSize);

		virtual int32_t get_KeyBits();

		virtual void set_KeyBits(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_KeyBits, set_KeyBits, TElOfficeXMLKeyData, KeyBits);

		virtual int32_t get_HashSize();

		virtual void set_HashSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashSize, set_HashSize, TElOfficeXMLKeyData, HashSize);

		virtual void get_CipherAlgorithm(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_CipherAlgorithm(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_CipherAlgorithm(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_CipherAlgorithm(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_CipherChaining(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_CipherChaining(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_CipherChaining(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_CipherChaining(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_HashAlgorithm(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_HashAlgorithm(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_HashAlgorithm(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_HashAlgorithm(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_SaltValue(std::vector<uint8_t> &OutResult);

		virtual void set_SaltValue(const std::vector<uint8_t> &Value);

		TElOfficeXMLKeyData(TElOfficeXMLKeyDataHandle handle, TElOwnHandle ownHandle);

		TElOfficeXMLKeyData();

};
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYDATA */

#ifdef SB_USE_CLASS_TELOFFICEXMLDATAINTEGRITY
class TElOfficeXMLDataIntegrity: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElOfficeXMLDataIntegrity)
	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_EncryptedHmacKey(std::vector<uint8_t> &OutResult);

		virtual void set_EncryptedHmacKey(const std::vector<uint8_t> &Value);

		virtual void get_EncryptedHmacValue(std::vector<uint8_t> &OutResult);

		virtual void set_EncryptedHmacValue(const std::vector<uint8_t> &Value);

		TElOfficeXMLDataIntegrity(TElOfficeXMLDataIntegrityHandle handle, TElOwnHandle ownHandle);

		TElOfficeXMLDataIntegrity();

};
#endif /* SB_USE_CLASS_TELOFFICEXMLDATAINTEGRITY */

#ifdef SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR
class TElOfficeXMLKeyEncryptor: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElOfficeXMLKeyEncryptor)
	public:
		virtual void get_URI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_URI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		TElOfficeXMLKeyEncryptor(TElOfficeXMLKeyEncryptorHandle handle, TElOwnHandle ownHandle);

		TElOfficeXMLKeyEncryptor();

};
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR */

#ifdef SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTORS
class TElOfficeXMLKeyEncryptors: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElOfficeXMLKeyEncryptors)
#ifdef SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR
		TElOfficeXMLKeyEncryptor* _Inst_KeyEncryptors;
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR
		int32_t Add(TElOfficeXMLKeyEncryptor &AKeyEncryptor);

		int32_t Add(TElOfficeXMLKeyEncryptor *AKeyEncryptor);
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR */

#ifdef SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR
		void Insert(int32_t Index, TElOfficeXMLKeyEncryptor &AKeyEncryptor);

		void Insert(int32_t Index, TElOfficeXMLKeyEncryptor *AKeyEncryptor);
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR */

		void Delete(int32_t Index);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElOfficeXMLKeyEncryptors, Count);

#ifdef SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR
		virtual TElOfficeXMLKeyEncryptor* get_KeyEncryptors(int32_t Index);
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTOR */

		TElOfficeXMLKeyEncryptors(TElOfficeXMLKeyEncryptorsHandle handle, TElOwnHandle ownHandle);

		TElOfficeXMLKeyEncryptors();

		virtual ~TElOfficeXMLKeyEncryptors();

};
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTORS */

#ifdef SB_USE_CLASS_TELOFFICEXMLPASSWORDKEYENCRYPTOR
class TElOfficeXMLPasswordKeyEncryptor: public TElOfficeXMLKeyEncryptor
{
	private:
		SB_DISABLE_COPY(TElOfficeXMLPasswordKeyEncryptor)
	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual int32_t get_SaltSize();

		virtual void set_SaltSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SaltSize, set_SaltSize, TElOfficeXMLPasswordKeyEncryptor, SaltSize);

		virtual int32_t get_BlockSize();

		virtual void set_BlockSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_BlockSize, set_BlockSize, TElOfficeXMLPasswordKeyEncryptor, BlockSize);

		virtual int32_t get_KeyBits();

		virtual void set_KeyBits(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_KeyBits, set_KeyBits, TElOfficeXMLPasswordKeyEncryptor, KeyBits);

		virtual int32_t get_HashSize();

		virtual void set_HashSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashSize, set_HashSize, TElOfficeXMLPasswordKeyEncryptor, HashSize);

		virtual void get_CipherAlgorithm(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_CipherAlgorithm(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_CipherAlgorithm(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_CipherAlgorithm(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_CipherChaining(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_CipherChaining(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_CipherChaining(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_CipherChaining(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_HashAlgorithm(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_HashAlgorithm(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_HashAlgorithm(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_HashAlgorithm(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_SaltValue(std::vector<uint8_t> &OutResult);

		virtual void set_SaltValue(const std::vector<uint8_t> &Value);

		virtual int32_t get_SpinCount();

		virtual void set_SpinCount(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SpinCount, set_SpinCount, TElOfficeXMLPasswordKeyEncryptor, SpinCount);

		virtual void get_EncryptedVerifierHashInput(std::vector<uint8_t> &OutResult);

		virtual void set_EncryptedVerifierHashInput(const std::vector<uint8_t> &Value);

		virtual void get_EncryptedVerifierHashValue(std::vector<uint8_t> &OutResult);

		virtual void set_EncryptedVerifierHashValue(const std::vector<uint8_t> &Value);

		virtual void get_EncryptedKeyValue(std::vector<uint8_t> &OutResult);

		virtual void set_EncryptedKeyValue(const std::vector<uint8_t> &Value);

		TElOfficeXMLPasswordKeyEncryptor(TElOfficeXMLPasswordKeyEncryptorHandle handle, TElOwnHandle ownHandle);

		TElOfficeXMLPasswordKeyEncryptor();

};
#endif /* SB_USE_CLASS_TELOFFICEXMLPASSWORDKEYENCRYPTOR */

#ifdef SB_USE_CLASS_TELOFFICEXMLENCRYPTION
class TElOfficeXMLEncryption: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElOfficeXMLEncryption)
#ifdef SB_USE_CLASS_TELOFFICEXMLDATAINTEGRITY
		TElOfficeXMLDataIntegrity* _Inst_DataIntegrity;
#endif /* SB_USE_CLASS_TELOFFICEXMLDATAINTEGRITY */
#ifdef SB_USE_CLASS_TELOFFICEXMLKEYDATA
		TElOfficeXMLKeyData* _Inst_KeyData;
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYDATA */
#ifdef SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTORS
		TElOfficeXMLKeyEncryptors* _Inst_KeyEncryptors;
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTORS */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELOFFICEXMLDATAINTEGRITY
		virtual TElOfficeXMLDataIntegrity* get_DataIntegrity();

		SB_DECLARE_PROPERTY_GET(TElOfficeXMLDataIntegrity*, get_DataIntegrity, TElOfficeXMLEncryption, DataIntegrity);
#endif /* SB_USE_CLASS_TELOFFICEXMLDATAINTEGRITY */

#ifdef SB_USE_CLASS_TELOFFICEXMLKEYDATA
		virtual TElOfficeXMLKeyData* get_KeyData();

		SB_DECLARE_PROPERTY_GET(TElOfficeXMLKeyData*, get_KeyData, TElOfficeXMLEncryption, KeyData);
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYDATA */

#ifdef SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTORS
		virtual TElOfficeXMLKeyEncryptors* get_KeyEncryptors();

		SB_DECLARE_PROPERTY_GET(TElOfficeXMLKeyEncryptors*, get_KeyEncryptors, TElOfficeXMLEncryption, KeyEncryptors);
#endif /* SB_USE_CLASS_TELOFFICEXMLKEYENCRYPTORS */

		TElOfficeXMLEncryption(TElOfficeXMLEncryptionHandle handle, TElOwnHandle ownHandle);

		TElOfficeXMLEncryption();

		virtual ~TElOfficeXMLEncryption();

};
#endif /* SB_USE_CLASS_TELOFFICEXMLENCRYPTION */

#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATURETIME
class TElOfficeXMLSignatureTime: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElOfficeXMLSignatureTime)
	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_Format(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Format(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Format(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Format(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_Value(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Value(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Value(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Value(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual int64_t get_ValueUTC();

		virtual void set_ValueUTC(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ValueUTC, set_ValueUTC, TElOfficeXMLSignatureTime, ValueUTC);

		TElOfficeXMLSignatureTime(TElOfficeXMLSignatureTimeHandle handle, TElOwnHandle ownHandle);

		TElOfficeXMLSignatureTime();

};
#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATURETIME */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPTRANSFORM
class TElOfficeOpenXMLRelationshipTransform: public TElXMLTransform
{
	private:
		SB_DISABLE_COPY(TElOfficeOpenXMLRelationshipTransform)
	public:
		static void GetDefaultTransformAlgorithmURI(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		static void GetDefaultTransformAlgorithmURI(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual void GetDefaultTransformAlgorithmURI_Inst(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		virtual void GetDefaultTransformAlgorithmURI_Inst(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		static bool IsTransformAlgorithmSupported(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		static bool IsTransformAlgorithmSupported(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

		virtual bool IsTransformAlgorithmSupported_Inst(const sb_u16string &Algorithm);
#ifdef SB_U16STRING_USED
		virtual bool IsTransformAlgorithmSupported_Inst(const std::wstring &Algorithm);
#endif /* SB_U16STRING_USED */

		virtual void Clear();

		int32_t AddSourceId(const sb_u16string &SourceId);
#ifdef SB_U16STRING_USED
		int32_t AddSourceId(const std::wstring &SourceId);
#endif /* SB_U16STRING_USED */

		int32_t AddSourceType(const sb_u16string &SourceType);
#ifdef SB_U16STRING_USED
		int32_t AddSourceType(const std::wstring &SourceType);
#endif /* SB_U16STRING_USED */

		void DeleteSourceId(int32_t Index);

		void DeleteSourceType(int32_t Index);

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual TSBTransformedDataType TransformData(const std::vector<uint8_t> &Data);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TSBTransformedDataType TransformData(TElXMLDOMNode &Node, TElXMLDOMNode &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNode *Node, TElXMLDOMNode *Reference);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST
		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList &Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);

		virtual TSBTransformedDataType TransformData(TElXMLDOMNodeList *Nodes, const std::vector<TElXMLDOMNodeHandle> &Reference);
#endif /* SB_USE_CLASSES_TELXMLDOMNODE_AND_TELXMLDOMNODELIST */

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNodeHandle TransformNode(TElXMLDOMNode &Node);

		TElXMLDOMNodeHandle TransformNode(TElXMLDOMNode *Node);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		static TClassHandle ClassType();

		virtual int32_t get_SourceIdCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SourceIdCount, TElOfficeOpenXMLRelationshipTransform, SourceIdCount);

		virtual int32_t get_SourceTypeCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SourceTypeCount, TElOfficeOpenXMLRelationshipTransform, SourceTypeCount);

		virtual void get_SourceIds(int32_t Index, sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_SourceIds(int32_t Index, std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_SourceTypes(int32_t Index, sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_SourceTypes(int32_t Index, std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		TElOfficeOpenXMLRelationshipTransform(TElOfficeOpenXMLRelationshipTransformHandle handle, TElOwnHandle ownHandle);

		TElOfficeOpenXMLRelationshipTransform();

};
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPTRANSFORM */

#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATUREINFOV1
class TElOfficeXMLSignatureInfoV1: public TObject
{
	private:
		SB_DISABLE_COPY(TElOfficeXMLSignatureInfoV1)
	public:
		void Clear();

#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
		bool CheckReferences(TElXMLReferenceList &Refs);

		bool CheckReferences(TElXMLReferenceList *Refs);
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */

#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
		void CreateReferences(TElXMLReferenceList &Refs, TElXMLDigestMethod DigestMethod);

		void CreateReferences(TElXMLReferenceList *Refs, TElXMLDigestMethod DigestMethod);
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLOBJECTLIST
		void CreateObjects(TElXMLObjectList &Objects, const sb_u16string &Target, TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		void CreateObjects(TElXMLObjectList *Objects, const sb_u16string &Target, TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#ifdef SB_U16STRING_USED
		void CreateObjects(TElXMLObjectList &Objects, const std::wstring &Target, TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		void CreateObjects(TElXMLObjectList *Objects, const std::wstring &Target, TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLOBJECTLIST */

#ifdef SB_USE_CLASS_TELXMLOBJECTLIST
		void LoadFromObjectList(TElXMLObjectList &Objects);

		void LoadFromObjectList(TElXMLObjectList *Objects);
#endif /* SB_USE_CLASS_TELXMLOBJECTLIST */

		virtual bool get_Included();

		virtual void set_Included(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Included, set_Included, TElOfficeXMLSignatureInfoV1, Included);

		virtual void get_ApplicationVersion(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ApplicationVersion(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ApplicationVersion(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ApplicationVersion(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual int32_t get_ColorDepth();

		virtual void set_ColorDepth(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ColorDepth, set_ColorDepth, TElOfficeXMLSignatureInfoV1, ColorDepth);

		virtual void get_DelegateSuggestedSigner(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_DelegateSuggestedSigner(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_DelegateSuggestedSigner(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_DelegateSuggestedSigner(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_DelegateSuggestedSigner2(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_DelegateSuggestedSigner2(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_DelegateSuggestedSigner2(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_DelegateSuggestedSigner2(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_DelegateSuggestedSignerEmail(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_DelegateSuggestedSignerEmail(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_DelegateSuggestedSignerEmail(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_DelegateSuggestedSignerEmail(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual int32_t get_HorizontalResolution();

		virtual void set_HorizontalResolution(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HorizontalResolution, set_HorizontalResolution, TElOfficeXMLSignatureInfoV1, HorizontalResolution);

		virtual void get_ManifestHashAlgorithm(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ManifestHashAlgorithm(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ManifestHashAlgorithm(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ManifestHashAlgorithm(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual int32_t get_Monitors();

		virtual void set_Monitors(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Monitors, set_Monitors, TElOfficeXMLSignatureInfoV1, Monitors);

		virtual void get_OfficeVersion(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_OfficeVersion(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_OfficeVersion(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_OfficeVersion(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_SetupID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_SetupID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_SetupID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_SetupID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_SignatureComments(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_SignatureComments(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_SignatureComments(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_SignatureComments(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_SignatureImage(std::vector<uint8_t> &OutResult);

		virtual void set_SignatureImage(const std::vector<uint8_t> &Value);

		virtual int32_t get_SignatureProviderDetails();

		virtual void set_SignatureProviderDetails(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SignatureProviderDetails, set_SignatureProviderDetails, TElOfficeXMLSignatureInfoV1, SignatureProviderDetails);

		virtual void get_SignatureProviderId(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_SignatureProviderId(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_SignatureProviderId(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_SignatureProviderId(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_SignatureProviderUrl(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_SignatureProviderUrl(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_SignatureProviderUrl(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_SignatureProviderUrl(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_SignatureText(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_SignatureText(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_SignatureText(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_SignatureText(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual int32_t get_SignatureType();

		virtual void set_SignatureType(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SignatureType, set_SignatureType, TElOfficeXMLSignatureInfoV1, SignatureType);

		virtual int32_t get_VerticalResolution();

		virtual void set_VerticalResolution(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_VerticalResolution, set_VerticalResolution, TElOfficeXMLSignatureInfoV1, VerticalResolution);

		virtual void get_WindowsVersion(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_WindowsVersion(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_WindowsVersion(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_WindowsVersion(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_ValidSignatureLnImage(std::vector<uint8_t> &OutResult);

		virtual void set_ValidSignatureLnImage(const std::vector<uint8_t> &Value);

		virtual void get_InvalidSignatureLnImage(std::vector<uint8_t> &OutResult);

		virtual void set_InvalidSignatureLnImage(const std::vector<uint8_t> &Value);

		TElOfficeXMLSignatureInfoV1(TElOfficeXMLSignatureInfoV1Handle handle, TElOwnHandle ownHandle);

		TElOfficeXMLSignatureInfoV1();

};
#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATUREINFOV1 */

#ifdef SB_USE_CLASS_TELOFFICEXMLSPOTLOCATION
class TElOfficeXMLSpotLocation: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElOfficeXMLSpotLocation)
	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_PageURI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_PageURI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_PageURI(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_PageURI(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual double get_StartX();

		virtual void set_StartX(double Value);

		SB_DECLARE_PROPERTY(double, get_StartX, set_StartX, TElOfficeXMLSpotLocation, StartX);

		virtual double get_StartY();

		virtual void set_StartY(double Value);

		SB_DECLARE_PROPERTY(double, get_StartY, set_StartY, TElOfficeXMLSpotLocation, StartY);

		TElOfficeXMLSpotLocation(TElOfficeXMLSpotLocationHandle handle, TElOwnHandle ownHandle);

		TElOfficeXMLSpotLocation();

};
#endif /* SB_USE_CLASS_TELOFFICEXMLSPOTLOCATION */

#ifdef SB_USE_CLASS_TELOFFICEXMLSIGNATUREDEFINITION
class TElOfficeXMLSignatureDefinition: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElOfficeXMLSignatureDefinition)
#ifdef SB_USE_CLASS_TELOFFICEXMLSPOTLOCATION
		TElOfficeXMLSpotLocation* _Inst_SpotLocation;
#endif /* SB_USE_CLASS_TELOFFICEXMLSPOTLOCATION */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_Intent(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Intent(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Intent(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Intent(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_SignBy(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_SignBy(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_SignBy(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_SignBy(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual int64_t get_SignByUTC();

		virtual void set_SignByUTC(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_SignByUTC, set_SignByUTC, TElOfficeXMLSignatureDefinition, SignByUTC);

		virtual void get_SigningLocation(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_SigningLocation(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_SigningLocation(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_SigningLocation(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_SignerName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_SignerName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_SignerName(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_SignerName(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_SpotID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_SpotID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_SpotID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_SpotID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELOFFICEXMLSPOTLOCATION
		virtual TElOfficeXMLSpotLocation* get_SpotLocation();

		SB_DECLARE_PROPERTY_GET(TElOfficeXMLSpotLocation*, get_SpotLocation, TElOfficeXMLSignatureDefinition, SpotLocation);
#endif /* SB_USE_CLASS_TELOFFICEXMLSPOTLOCATION */

		TElOfficeXMLSignatureDefinition(TElOfficeXMLSignatureDefinitionHandle handle, TElOwnHandle ownHandle);

		TElOfficeXMLSignatureDefinition();

		virtual ~TElOfficeXMLSignatureDefinition();

};
#endif /* SB_USE_CLASS_TELOFFICEXMLSIGNATUREDEFINITION */

#ifdef SB_USE_CLASS_TELOFFICEXMLFIXEDDOCUMENTSEQUENCE
class TElOfficeXMLFixedDocumentSequence: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElOfficeXMLFixedDocumentSequence)
	public:
		int32_t Add(const sb_u16string &DocRef);
#ifdef SB_U16STRING_USED
		int32_t Add(const std::wstring &DocRef);
#endif /* SB_U16STRING_USED */

		void Delete(int32_t Index);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElOfficeXMLFixedDocumentSequence, Count);

		virtual void get_DocumentReferences(int32_t Index, sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_DocumentReferences(int32_t Index, std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		TElOfficeXMLFixedDocumentSequence(TElOfficeXMLFixedDocumentSequenceHandle handle, TElOwnHandle ownHandle);

		TElOfficeXMLFixedDocumentSequence();

};
#endif /* SB_USE_CLASS_TELOFFICEXMLFIXEDDOCUMENTSEQUENCE */

#ifdef SB_USE_CLASS_TELOFFICEXMLPAGECONTENT
class TElOfficeXMLPageContent: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElOfficeXMLPageContent)
	public:
		int32_t AddLinkTarget(const sb_u16string &Name);
#ifdef SB_U16STRING_USED
		int32_t AddLinkTarget(const std::wstring &Name);
#endif /* SB_U16STRING_USED */

		void DeleteLinkTarget(int32_t Index);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_Source(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Source(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Source(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Source(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual int32_t get_Width();

		virtual void set_Width(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Width, set_Width, TElOfficeXMLPageContent, Width);

		virtual int32_t get_Height();

		virtual void set_Height(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Height, set_Height, TElOfficeXMLPageContent, Height);

		virtual int32_t get_LinkTargetCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_LinkTargetCount, TElOfficeXMLPageContent, LinkTargetCount);

		virtual void get_LinkTargets(int32_t Index, sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_LinkTargets(int32_t Index, std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		TElOfficeXMLPageContent(TElOfficeXMLPageContentHandle handle, TElOwnHandle ownHandle);

		TElOfficeXMLPageContent();

};
#endif /* SB_USE_CLASS_TELOFFICEXMLPAGECONTENT */

#ifdef SB_USE_CLASS_TELOFFICEXMLFIXEDDOCUMENT
class TElOfficeXMLFixedDocument: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElOfficeXMLFixedDocument)
#ifdef SB_USE_CLASS_TELOFFICEXMLPAGECONTENT
		TElOfficeXMLPageContent* _Inst_PageContents;
#endif /* SB_USE_CLASS_TELOFFICEXMLPAGECONTENT */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELOFFICEXMLPAGECONTENT
		int32_t Add(TElOfficeXMLPageContent &PageContent);

		int32_t Add(TElOfficeXMLPageContent *PageContent);
#endif /* SB_USE_CLASS_TELOFFICEXMLPAGECONTENT */

		void Delete(int32_t Index);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElOfficeXMLFixedDocument, Count);

#ifdef SB_USE_CLASS_TELOFFICEXMLPAGECONTENT
		virtual TElOfficeXMLPageContent* get_PageContents(int32_t Index);
#endif /* SB_USE_CLASS_TELOFFICEXMLPAGECONTENT */

		TElOfficeXMLFixedDocument(TElOfficeXMLFixedDocumentHandle handle, TElOwnHandle ownHandle);

		TElOfficeXMLFixedDocument();

		virtual ~TElOfficeXMLFixedDocument();

};
#endif /* SB_USE_CLASS_TELOFFICEXMLFIXEDDOCUMENT */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTALGORITHM
class TElOpenOfficeXMLManifestAlgorithm: public TElOfficeOpenXMLElement
{
	private:
		SB_DISABLE_COPY(TElOpenOfficeXMLManifestAlgorithm)
	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_AlgorithmName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_AlgorithmName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_AlgorithmName(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_AlgorithmName(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_IV(std::vector<uint8_t> &OutResult);

		virtual void set_IV(const std::vector<uint8_t> &Value);

		TElOpenOfficeXMLManifestAlgorithm(TElOpenOfficeXMLManifestAlgorithmHandle handle, TElOwnHandle ownHandle);

		TElOpenOfficeXMLManifestAlgorithm();

};
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTALGORITHM */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTKEYDERIVATION
class TElOpenOfficeXMLManifestKeyDerivation: public TElOfficeOpenXMLElement
{
	private:
		SB_DISABLE_COPY(TElOpenOfficeXMLManifestKeyDerivation)
	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual int32_t get_IterationCount();

		virtual void set_IterationCount(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_IterationCount, set_IterationCount, TElOpenOfficeXMLManifestKeyDerivation, IterationCount);

		virtual void get_KeyDerivationName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_KeyDerivationName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_KeyDerivationName(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_KeyDerivationName(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual int32_t get_KeySize();

		virtual void set_KeySize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_KeySize, set_KeySize, TElOpenOfficeXMLManifestKeyDerivation, KeySize);

		virtual void get_Salt(std::vector<uint8_t> &OutResult);

		virtual void set_Salt(const std::vector<uint8_t> &Value);

		TElOpenOfficeXMLManifestKeyDerivation(TElOpenOfficeXMLManifestKeyDerivationHandle handle, TElOwnHandle ownHandle);

		TElOpenOfficeXMLManifestKeyDerivation();

};
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTKEYDERIVATION */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTSTARTKEYGENERATION
class TElOpenOfficeXMLManifestStartKeyGeneration: public TElOfficeOpenXMLElement
{
	private:
		SB_DISABLE_COPY(TElOpenOfficeXMLManifestStartKeyGeneration)
	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual int32_t get_KeySize();

		virtual void set_KeySize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_KeySize, set_KeySize, TElOpenOfficeXMLManifestStartKeyGeneration, KeySize);

		virtual void get_StartKeyGenerationName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_StartKeyGenerationName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_StartKeyGenerationName(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_StartKeyGenerationName(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElOpenOfficeXMLManifestStartKeyGeneration(TElOpenOfficeXMLManifestStartKeyGenerationHandle handle, TElOwnHandle ownHandle);

		TElOpenOfficeXMLManifestStartKeyGeneration();

};
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTSTARTKEYGENERATION */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTENCRYPTIONDATA
class TElOpenOfficeXMLManifestEncryptionData: public TElOfficeOpenXMLElement
{
	private:
		SB_DISABLE_COPY(TElOpenOfficeXMLManifestEncryptionData)
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTALGORITHM
		TElOpenOfficeXMLManifestAlgorithm* _Inst_Algorithm;
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTALGORITHM */
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTKEYDERIVATION
		TElOpenOfficeXMLManifestKeyDerivation* _Inst_KeyDerivation;
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTKEYDERIVATION */
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTSTARTKEYGENERATION
		TElOpenOfficeXMLManifestStartKeyGeneration* _Inst_StartKeyGeneration;
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTSTARTKEYGENERATION */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual void get_Checksum(std::vector<uint8_t> &OutResult);

		virtual void set_Checksum(const std::vector<uint8_t> &Value);

		virtual void get_ChecksumType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ChecksumType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ChecksumType(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ChecksumType(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTALGORITHM
		virtual TElOpenOfficeXMLManifestAlgorithm* get_Algorithm();

		SB_DECLARE_PROPERTY_GET(TElOpenOfficeXMLManifestAlgorithm*, get_Algorithm, TElOpenOfficeXMLManifestEncryptionData, Algorithm);
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTALGORITHM */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTKEYDERIVATION
		virtual TElOpenOfficeXMLManifestKeyDerivation* get_KeyDerivation();

		SB_DECLARE_PROPERTY_GET(TElOpenOfficeXMLManifestKeyDerivation*, get_KeyDerivation, TElOpenOfficeXMLManifestEncryptionData, KeyDerivation);
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTKEYDERIVATION */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTSTARTKEYGENERATION
		virtual TElOpenOfficeXMLManifestStartKeyGeneration* get_StartKeyGeneration();

		SB_DECLARE_PROPERTY_GET(TElOpenOfficeXMLManifestStartKeyGeneration*, get_StartKeyGeneration, TElOpenOfficeXMLManifestEncryptionData, StartKeyGeneration);
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTSTARTKEYGENERATION */

		TElOpenOfficeXMLManifestEncryptionData(TElOpenOfficeXMLManifestEncryptionDataHandle handle, TElOwnHandle ownHandle);

		TElOpenOfficeXMLManifestEncryptionData();

		virtual ~TElOpenOfficeXMLManifestEncryptionData();

};
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTENCRYPTIONDATA */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY
class TElOpenOfficeXMLManifestFileEntry: public TElOfficeOpenXMLElement
{
	private:
		SB_DISABLE_COPY(TElOpenOfficeXMLManifestFileEntry)
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTENCRYPTIONDATA
		TElOpenOfficeXMLManifestEncryptionData* _Inst_EncryptionData;
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTENCRYPTIONDATA */

		void initInstances();

	public:
		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual bool get_IsEncrypted();

		SB_DECLARE_PROPERTY_GET(bool, get_IsEncrypted, TElOpenOfficeXMLManifestFileEntry, IsEncrypted);

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTENCRYPTIONDATA
		virtual TElOpenOfficeXMLManifestEncryptionData* get_EncryptionData();

		SB_DECLARE_PROPERTY_GET(TElOpenOfficeXMLManifestEncryptionData*, get_EncryptionData, TElOpenOfficeXMLManifestFileEntry, EncryptionData);
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTENCRYPTIONDATA */

		virtual void get_FullPath(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_FullPath(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_FullPath(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_FullPath(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_MediaType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_MediaType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_MediaType(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_MediaType(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_PreferredViewMode(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_PreferredViewMode(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_PreferredViewMode(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_PreferredViewMode(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual int32_t get_Size();

		virtual void set_Size(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Size, set_Size, TElOpenOfficeXMLManifestFileEntry, Size);

		virtual void get_Version(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Version(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Version(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Version(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElOpenOfficeXMLManifestFileEntry(TElOpenOfficeXMLManifestFileEntryHandle handle, TElOwnHandle ownHandle);

		TElOpenOfficeXMLManifestFileEntry();

		virtual ~TElOpenOfficeXMLManifestFileEntry();

};
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFEST
class TElOpenOfficeXMLManifest: public TElOfficeOpenXMLElement
{
	private:
		SB_DISABLE_COPY(TElOpenOfficeXMLManifest)
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY
		TElOpenOfficeXMLManifestFileEntry* _Inst_FileEntries;
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY
		int32_t Add(TElOpenOfficeXMLManifestFileEntry &AFileEntry);

		int32_t Add(TElOpenOfficeXMLManifestFileEntry *AFileEntry);
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY */

		int32_t Add(const sb_u16string &FullPath, const sb_u16string &MediaType);
#ifdef SB_U16STRING_USED
		int32_t Add(const std::wstring &FullPath, const std::wstring &MediaType);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY
		void Insert(int32_t Index, TElOpenOfficeXMLManifestFileEntry &AFileEntry);

		void Insert(int32_t Index, TElOpenOfficeXMLManifestFileEntry *AFileEntry);
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY */

		void Delete(int32_t Index);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY
		TElOpenOfficeXMLManifestFileEntryHandle GetFileEntryByFullPath(const sb_u16string &FullPath);
#ifdef SB_U16STRING_USED
		TElOpenOfficeXMLManifestFileEntryHandle GetFileEntryByFullPath(const std::wstring &FullPath);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElOpenOfficeXMLManifest, Count);

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY
		virtual TElOpenOfficeXMLManifestFileEntry* get_FileEntries(int32_t Index);
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFESTFILEENTRY */

		TElOpenOfficeXMLManifest(TElOpenOfficeXMLManifestHandle handle, TElOwnHandle ownHandle);

		TElOpenOfficeXMLManifest();

		virtual ~TElOpenOfficeXMLManifest();

};
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFEST */

#ifdef SB_USE_GLOBAL_PROCS_OFFICEXMLCORE

bool IsValidPartIRI(const sb_u16string &IRI);
#ifdef SB_U16STRING_USED
bool IsValidPartIRI(const std::wstring &IRI);
#endif /* SB_U16STRING_USED */

bool IsValidPartURI(const std::string &URI);

void ConvertPartIRIToURI(const sb_u16string &IRI, std::string &OutResult);
#ifdef SB_U16STRING_USED
void ConvertPartIRIToURI(const std::wstring &IRI, std::string &OutResult);
#endif /* SB_U16STRING_USED */

void ConvertPartURIToIRI(const std::string &URI, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void ConvertPartURIToIRI(const std::string &URI, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

int32_t ComparePartIRI(const sb_u16string &X, const sb_u16string &Y);
#ifdef SB_U16STRING_USED
int32_t ComparePartIRI(const std::wstring &X, const std::wstring &Y);
#endif /* SB_U16STRING_USED */

int32_t ComparePartURI(const std::string &X, const std::string &Y);

void NormalizePartIRI(const sb_u16string &IRI, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void NormalizePartIRI(const std::wstring &IRI, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void NormalizePartURI(const std::string &URI, std::string &OutResult);

void ResolveRelativePartIRI(const sb_u16string &BaseIRI, const sb_u16string &TargetIRI, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void ResolveRelativePartIRI(const std::wstring &BaseIRI, const std::wstring &TargetIRI, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void ResolveRelativePartURI(const std::string &BaseURI, const std::string &TargetURI, std::string &OutResult);

void GetRelativePartURI(const std::string &URI, const std::string &BaseURI, std::string &OutResult);

void GetRelationshipURI(const std::string &PartURI, std::string &OutResult);

void GetPartURIExtension(const std::string &URI, std::string &OutResult);

void GetPartURIPath(const std::string &URI, std::string &OutResult);

void GetPartURIName(const std::string &URI, std::string &OutResult);

void GetPartURIQueryComponent(const std::string &URI, std::string &OutResult);

void RemovePartURIExtension(const std::string &URI, std::string &OutResult);

void RemovePartIRIQueryComponent(const sb_u16string &IRI, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void RemovePartIRIQueryComponent(const std::wstring &IRI, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void RemovePartURIQueryComponent(const std::string &URI, std::string &OutResult);

void GetValueFromQueryComponent(const std::string &Query, const std::string &Key, std::string &OutResult);

bool IsLogicalItemSuffixName(const std::string &SuffixName);

int32_t ParseLogicalItemSuffixName(const std::string &SuffixName, bool &IsLast);

void FormatLogicalItemSuffixName(int32_t PieceNumber, bool IsLast, bool SkipSlash, std::string &OutResult);

void DecodeXMLEntities(const sb_u16string &Str, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void DecodeXMLEntities(const std::wstring &Str, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void EncodeXMLEntities(const sb_u16string &Str, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void EncodeXMLEntities(const std::wstring &Str, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void DecodeXMLName(const sb_u16string &Str, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void DecodeXMLName(const std::wstring &Str, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void EncodeXMLNameSimple(const sb_u16string &Str, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void EncodeXMLNameSimple(const std::wstring &Str, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS
void GenerateUniqueIdForRelationship(TElOfficeOpenXMLRelationships &Relationships, sb_u16string &OutResult);
void GenerateUniqueIdForRelationship(TElOfficeOpenXMLRelationships *Relationships, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void GenerateUniqueIdForRelationship(TElOfficeOpenXMLRelationships &Relationships, std::wstring &OutResult);
void GenerateUniqueIdForRelationship(TElOfficeOpenXMLRelationships *Relationships, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS */

TSBOfficeOpenXMLDocumentType GetOpenXMLDocumentTypeFromContentType(const std::string &ContentType);

TSBOpenOfficeDocumentType GetOpenDocumentTypeFromMimeType(const std::string &MimeType);

int32_t WideCompareStrOrdinal(const sb_u16string &S1, const sb_u16string &S2);
#ifdef SB_U16STRING_USED
int32_t WideCompareStrOrdinal(const std::wstring &S1, const std::wstring &S2);
#endif /* SB_U16STRING_USED */

#endif /* SB_USE_GLOBAL_PROCS_OFFICEXMLCORE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_OFFICEXMLCORE
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_IsValidPartIRI(const sb_char16_t * pcIRI, int32_t szIRI, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_IsValidPartURI(const char * pcURI, int32_t szURI, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_ConvertPartIRIToURI(const sb_char16_t * pcIRI, int32_t szIRI, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_ConvertPartURIToIRI(const char * pcURI, int32_t szURI, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_ComparePartIRI(const sb_char16_t * pcX, int32_t szX, const sb_char16_t * pcY, int32_t szY, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_ComparePartURI(const char * pcX, int32_t szX, const char * pcY, int32_t szY, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_NormalizePartIRI(const sb_char16_t * pcIRI, int32_t szIRI, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_NormalizePartURI(const char * pcURI, int32_t szURI, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_ResolveRelativePartIRI(const sb_char16_t * pcBaseIRI, int32_t szBaseIRI, const sb_char16_t * pcTargetIRI, int32_t szTargetIRI, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_ResolveRelativePartURI(const char * pcBaseURI, int32_t szBaseURI, const char * pcTargetURI, int32_t szTargetURI, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_GetRelativePartURI(const char * pcURI, int32_t szURI, const char * pcBaseURI, int32_t szBaseURI, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_GetRelationshipURI(const char * pcPartURI, int32_t szPartURI, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_GetPartURIExtension(const char * pcURI, int32_t szURI, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_GetPartURIPath(const char * pcURI, int32_t szURI, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_GetPartURIName(const char * pcURI, int32_t szURI, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_GetPartURIQueryComponent(const char * pcURI, int32_t szURI, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_RemovePartURIExtension(const char * pcURI, int32_t szURI, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_RemovePartIRIQueryComponent(const sb_char16_t * pcIRI, int32_t szIRI, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_RemovePartURIQueryComponent(const char * pcURI, int32_t szURI, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_GetValueFromQueryComponent(const char * pcQuery, int32_t szQuery, const char * pcKey, int32_t szKey, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_IsLogicalItemSuffixName(const char * pcSuffixName, int32_t szSuffixName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_ParseLogicalItemSuffixName(const char * pcSuffixName, int32_t szSuffixName, int8_t * IsLast, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_FormatLogicalItemSuffixName(int32_t PieceNumber, int8_t IsLast, int8_t SkipSlash, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_DecodeXMLEntities(const sb_char16_t * pcStr, int32_t szStr, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_EncodeXMLEntities(const sb_char16_t * pcStr, int32_t szStr, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_DecodeXMLName(const sb_char16_t * pcStr, int32_t szStr, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_EncodeXMLNameSimple(const sb_char16_t * pcStr, int32_t szStr, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_GenerateUniqueIdForRelationship(TElOfficeOpenXMLRelationshipsHandle Relationships, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_GetOpenXMLDocumentTypeFromContentType(const char * pcContentType, int32_t szContentType, TSBOfficeOpenXMLDocumentTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_GetOpenDocumentTypeFromMimeType(const char * pcMimeType, int32_t szMimeType, TSBOpenOfficeDocumentTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOfficeXMLCore_WideCompareStrOrdinal(const sb_char16_t * pcS1, int32_t szS1, const sb_char16_t * pcS2, int32_t szS2, int32_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_OFFICEXMLCORE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBOFFICEXMLCORE */

