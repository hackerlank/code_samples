#ifndef __INC_SBPDF
#define __INC_SBPDF

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbpdfcore.h"
#include "sbpdfutils.h"
#include "sbrc4.h"
#include "sbmd.h"
#include "sbcryptoprov.h"
#include "sbconstants.h"
#include "sbsharedresource.h"
#include "sbrdn.h"
#include "sbx509.h"
#include "sbsha.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbstreams.h"
#include "sbcustomcertstorage.h"
#include "sbsymmetriccrypto.h"
#include "sbpkcs7.h"
#include "sbhashfunction.h"
#include "sbzlib.h"
#include "sbdc.h"
#include "sbencoding.h"
#include "sbrandom.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SPDFNotImplemented 	"Not implemented"
#define SB_SPDFInvalidSecurityHandlerInformation 	"Invalid security handler information"
#define SB_SPDFInvalidPassword 	"Invalid password"
#define SB_SPDFNoDecryptionKeyFound 	"No decryption key found"
#define SB_SPDFCannotTimestampEncryptedDocument 	"Cannot timestamp encrypted document"
#define SB_SPDFCannotModifyDocumentAfterSignatureUpdate 	"Cannot modify document after signature update"
#define SB_SPDFCannotUpdateSignatureInEncryptedDocument 	"Cannot update signature in encrypted document"
#define SB_SPDFUnsupportedTimestampType 	"Unsupported timestamp type"
#define SB_SPDFBadAsyncState 	"Bad asynchronous operation state"
#define SB_SPDFSecurityHandlerNotFound 	"Security handler not found"
#define SB_SPDFDCModuleUnavailable 	"Distributed Cryptography module is not available"
#define SB_SPDFSignatureSizeEstimatedIncorrectly 	"Signature is too large to fit in the allocated window. Please consider extending the window by assigning the number of bytes to add to the TElPDFSignature.ExtraSpace property before closing the document."
#define SB_SPDFCannotChangeDecryptionModePropertyForOpenedDocument 	"Cannot change DecryptionMode property for opened document"
#define SB_SFPDFUnsupportedSecurityHandlerSubfilter 	"Unsupported security handler subfilter (%s)"
#define SB_SFPDFInternalError 	"Internal error %s"
#define SB_SFPDFIndexOutOfBounds 	"Index out of bounds (%d)"

typedef TElClassHandle TElPDFDocumentHandle;

typedef TElPDFDocumentHandle ElPDFDocumentHandle;

typedef TElClassHandle TElPDFURPropertiesHandle;

typedef TElPDFURPropertiesHandle ElPDFURPropertiesHandle;

typedef TElClassHandle TElPDFSigRefEntryHandle;

typedef TElPDFSigRefEntryHandle ElPDFSigRefEntryHandle;

typedef TElClassHandle TElPDFSecurityHandlerHandle;

typedef TElPDFSecurityHandlerHandle ElPDFSecurityHandlerHandle;

typedef TElClassHandle TElPDFByteRangeHandle;

typedef TElPDFByteRangeHandle ElPDFByteRangeHandle;

typedef TElClassHandle TElPDFImageHandle;

typedef TElPDFImageHandle ElPDFImageHandle;

typedef TElClassHandle TElPDFCustomFontObjectHandle;

typedef TElPDFCustomFontObjectHandle ElPDFCustomFontObjectHandle;

typedef TElClassHandle TElPDFEncodingHandle;

typedef TElPDFEncodingHandle ElPDFEncodingHandle;

typedef TElClassHandle TElPDFFontDescriptorHandle;

typedef TElPDFFontDescriptorHandle ElPDFFontDescriptorHandle;

typedef TElClassHandle TElPDFCIDFontDescriptorHandle;

typedef TElPDFCIDFontDescriptorHandle ElPDFCIDFontDescriptorHandle;

typedef TElClassHandle TElPDFCIDSystemInfoHandle;

typedef TElPDFCIDSystemInfoHandle ElPDFCIDSystemInfoHandle;

typedef TElClassHandle TElPDFCustomFontHandle;

typedef TElPDFCustomFontHandle ElPDFCustomFontHandle;

typedef TElClassHandle TElPDFSimpleFontHandle;

typedef TElPDFSimpleFontHandle ElPDFSimpleFontHandle;

typedef TElClassHandle TElPDFCompositeFontHandle;

typedef TElPDFCompositeFontHandle ElPDFCompositeFontHandle;

typedef TElClassHandle TElPDFMetricWHandle;

typedef TElPDFMetricWHandle ElPDFMetricWHandle;

typedef TElClassHandle TElPDFMetricW2Handle;

typedef TElPDFMetricW2Handle ElPDFMetricW2Handle;

typedef TElClassHandle TElPDFCIDFontHandle;

typedef TElPDFCIDFontHandle ElPDFCIDFontHandle;

typedef TElClassHandle TElPDFSignatureWidgetTextHandle;

typedef TElPDFSignatureWidgetTextHandle ElPDFSignatureWidgetTextHandle;

typedef TElClassHandle TElPDFSignatureWidgetTextListHandle;

typedef TElPDFSignatureWidgetTextListHandle ElPDFSignatureWidgetTextListHandle;

typedef TElClassHandle TElPDFSignatureWidgetPropsHandle;

typedef TElPDFSignatureWidgetPropsHandle ElPDFSignatureWidgetPropsHandle;

typedef TElClassHandle TElPDFSignatureHandle;

typedef TElPDFSignatureHandle ElPDFSignatureHandle;

typedef TElClassHandle TElPDFSignatureInfoHandle;

typedef TElPDFSignatureInfoHandle ElPDFSignatureInfoHandle;

typedef TElClassHandle TElPDFEncodingHandlerHandle;

typedef TElPDFEncodingHandlerHandle ElPDFEncodingHandlerHandle;

typedef TElClassHandle TElPDFRequirementHandlerHandle;

typedef TElPDFRequirementHandlerHandle ElPDFRequirementHandlerHandle;

typedef TElClassHandle TElPDFRequirementHandle;

typedef TElPDFRequirementHandle ElPDFRequirementHandle;

typedef TElClassHandle TElPDFPageInfoHandle;

typedef TElPDFPageInfoHandle ElPDFPageInfoHandle;

typedef TElClassHandle TElPDFFileAttachmentHandle;

typedef TElClassHandle TElPDFLegalContentAttestationHandle;

typedef uint8_t TSBPDFSignatureTypeRaw;

typedef enum
{
	stDocument = 0,
	stMDP = 1,
	stUsageRights = 2,
	stObject = 3,
	stUnknown = 4
} TSBPDFSignatureType;

typedef uint8_t TSBPDFTransformMethodRaw;

typedef enum
{
	tmDocMDP = 0,
	tmUR = 1,
	tmUR3 = 2,
	tmFieldMDP = 3,
	tmIdentity = 4,
	tmObject = 5,
	tmUnknown = 6
} TSBPDFTransformMethod;

typedef uint8_t TSBPDFDigestMethodRaw;

typedef enum
{
	dmMD5 = 0,
	dmSHA1 = 1,
	dmUnknown = 2
} TSBPDFDigestMethod;

typedef uint8_t TSBPDFFieldMDPActionRaw;

typedef enum
{
	fmaAll = 0,
	fmaInclude = 1,
	fmaExclude = 2,
	fmaUnknown = 3
} TSBPDFFieldMDPAction;

typedef uint8_t TSBPDFDecryptionModeRaw;

typedef enum
{
	dmFull = 0,
	dmOnDemand = 1,
	dmSign = 2
} TSBPDFDecryptionMode;

typedef uint8_t TSBPDFSignatureRemoveOptionRaw;

typedef enum
{
	sroFull = 0,
	sroKeepField = 1,
	sroKeepAppearance = 2
} TSBPDFSignatureRemoveOption;

typedef uint8_t TSBPDFImageTypeRaw;

typedef enum
{
	pitJPEG2000 = 0,
	pitJPEG = 1,
	pitMask = 2,
	pitMaskInverted = 3,
	pitCustom = 4
} TSBPDFImageType;

typedef uint8_t TSBPDFColorSpaceTypeRaw;

typedef enum
{
	pcstNone = 0,
	pcstGray = 1,
	pcstRGB = 2,
	pcstCMYK = 3
} TSBPDFColorSpaceType;

typedef uint8_t TSBPDFStandardType1FontRaw;

typedef enum
{
	psfUnknown = 0,
	psfHelvetica = 1,
	psfTimesRoman = 2,
	psfCourier = 3,
	psfHelveticaBold = 4,
	psfTimesBold = 5,
	psfCourierBold = 6,
	psfHelveticaOblique = 7,
	psfTimesItalic = 8,
	psfCourierOblique = 9,
	psfHelveticaBoldOblique = 10,
	psfTimesBoldItalic = 11,
	psfCourierBoldOblique = 12,
	psfSymbol = 13,
	psfZapfDingbats = 14
} TSBPDFStandardType1Font;

typedef uint8_t TSBPDFWidgetBackgroundStyleRaw;

typedef enum
{
	pbsDefault = 0,
	pbsNoBackground = 1,
	pbsCustom = 2
} TSBPDFWidgetBackgroundStyle;

typedef void (SB_CALLBACK *TSBPDFConvertStringToAnsiEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcStr, int32_t szStr, uint8_t pOutResult[], int32_t * szOutResult);

typedef void (SB_CALLBACK *TSBPDFLookupGlyphNameEvent)(void * _ObjectData, TObjectHandle Sender, int32_t UCS, char * pcOutResult, int32_t * szOutResult);

typedef void (SB_CALLBACK *TSBPDFLookupGlyphWidthEvent)(void * _ObjectData, TObjectHandle Sender, int32_t UCS, int32_t * Width);

typedef uint8_t TSBPDFSignatureAllowedChangeRaw;

typedef enum
{
	sacFillInForms = 0,
	sacComment = 1
} TSBPDFSignatureAllowedChange;

typedef uint32_t TSBPDFSignatureAllowedChangesRaw;

typedef enum 
{
	f_sacFillInForms = 1,
	f_sacComment = 2
} TSBPDFSignatureAllowedChanges;

typedef uint8_t TSBPDFSignatureOptionRaw;

typedef enum
{
	psoSuppressEmptyAuthorName = 0
} TSBPDFSignatureOption;

typedef uint32_t TSBPDFSignatureOptionsRaw;

typedef enum 
{
	f_psoSuppressEmptyAuthorName = 1
} TSBPDFSignatureOptions;

typedef uint8_t TSBSVDConstraintRaw;

typedef enum
{
	svdcFilter = 0,
	svdcSubFilter = 1,
	svdcV = 2,
	svdcReasons = 3,
	svdcLegalAttestation = 4,
	svdcAddRevInfo = 5,
	svdcDigestMethod = 6,
	svdcLockDocument = 7,
	svdcAppearanceFilter = 8
} TSBSVDConstraint;

typedef uint32_t TSBSVDConstraintsRaw;

typedef enum 
{
	f_svdcFilter = 1,
	f_svdcSubFilter = 2,
	f_svdcV = 4,
	f_svdcReasons = 8,
	f_svdcLegalAttestation = 16,
	f_svdcAddRevInfo = 32,
	f_svdcDigestMethod = 64,
	f_svdcLockDocument = 128,
	f_svdcAppearanceFilter = 256
} TSBSVDConstraints;

typedef uint8_t TSBPDFFieldFlagRaw;

typedef enum
{
	ffReadOnly = 0,
	ffRequired = 1,
	ffNoExport = 2
} TSBPDFFieldFlag;

typedef uint32_t TSBPDFFieldFlagsRaw;

typedef enum 
{
	f_ffReadOnly = 1,
	f_ffRequired = 2,
	f_ffNoExport = 4
} TSBPDFFieldFlags;

typedef uint8_t TSBPDFSecurityHandlerEncryptionMethodRaw;

typedef enum
{
	_emNone = 0,
	emV2 = 1,
	emAESV2 = 2,
	emAESV3 = 3,
	emUnknown = 4
} TSBPDFSecurityHandlerEncryptionMethod;

typedef uint8_t TSBPDFEncryptionSubjectRaw;

typedef enum
{
	esStream = 0,
	esString = 1
} TSBPDFEncryptionSubject;

typedef TElClassHandle TElPDFSecurityHandlerClassHandle;

typedef TElClassHandle TElPDFEncodingHandlerClassHandle;

typedef TElPDFEncodingHandlerClassHandle ElPDFEncodingHandlerClassHandle;

typedef uint8_t TSBPDFAssemblyOptionRaw;

typedef enum
{
	aoAcrobatFriendlyAcroForm = 0,
	aoAdjustTimesToUTC = 1
} TSBPDFAssemblyOption;

typedef uint32_t TSBPDFAssemblyOptionsRaw;

typedef enum 
{
	f_aoAcrobatFriendlyAcroForm = 1,
	f_aoAdjustTimesToUTC = 2
} TSBPDFAssemblyOptions;

typedef void (SB_CALLBACK *TSBPDFBeforeSignEvent)(void * _ObjectData, TObjectHandle Sender, TElPDFSignatureHandle Signature);

#ifdef SB_USE_CLASS_TELPDFDOCUMENT
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_Open(TElPDFDocumentHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_Close(TElPDFDocumentHandle _Handle, int8_t Save);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_Encrypt(TElPDFDocumentHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_SignAndEncrypt(TElPDFDocumentHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_Decrypt(TElPDFDocumentHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_AddSignature(TElPDFDocumentHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_AddSignature_1(TElPDFDocumentHandle _Handle, int32_t EmptySignatureField, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_InsertSignature(TElPDFDocumentHandle _Handle, int32_t Index, TElPDFSignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_ClearSignatures(TElPDFDocumentHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_RemoveSignature(TElPDFDocumentHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_RemoveSignature_1(TElPDFDocumentHandle _Handle, int32_t Index, TSBPDFSignatureRemoveOptionRaw SigRemoveOption);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_RemoveEmptySignatureField(TElPDFDocumentHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_RemoveEmptySignatureField_1(TElPDFDocumentHandle _Handle, int32_t Index, TSBPDFSignatureRemoveOptionRaw SigRemoveOption);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_AddAttachedFile(TElPDFDocumentHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_RemoveAttachedFile(TElPDFDocumentHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_InitiateAsyncOperation(TElPDFDocumentHandle _Handle, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_InitiateAsyncOperation_1(TElPDFDocumentHandle _Handle, TSBDCAsyncSignMethodRaw AsyncSignMethod, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_CompleteAsyncOperation(TElPDFDocumentHandle _Handle, TStreamHandle Stream, TElDCAsyncStateHandle AsyncState, TElPDFSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_PageInfos(TElPDFDocumentHandle _Handle, int32_t Index, TElPDFPageInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_Signatures(TElPDFDocumentHandle _Handle, int32_t Index, TElPDFSignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_AttachedFiles(TElPDFDocumentHandle _Handle, int32_t Index, TElPDFFileAttachmentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_EmptySignatureFields(TElPDFDocumentHandle _Handle, int32_t Index, TElPDFSignatureInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_DocumentRequirements(TElPDFDocumentHandle _Handle, int32_t Index, TElPDFRequirementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_DocumentID(TElPDFDocumentHandle _Handle, TElPDFArrayHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_DocumentVersion(TElPDFDocumentHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_set_DocumentVersion(TElPDFDocumentHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_EmptySignatureFieldCount(TElPDFDocumentHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_Decrypted(TElPDFDocumentHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_Encrypted(TElPDFDocumentHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_EncryptionHandler(TElPDFDocumentHandle _Handle, TElPDFSecurityHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_set_EncryptionHandler(TElPDFDocumentHandle _Handle, TElPDFSecurityHandlerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_Opened(TElPDFDocumentHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_DocumentRequirementCount(TElPDFDocumentHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_PageInfoCount(TElPDFDocumentHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_SignatureCount(TElPDFDocumentHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_Signed(TElPDFDocumentHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_AttachedFileCount(TElPDFDocumentHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_AssemblyOptions(TElPDFDocumentHandle _Handle, TSBPDFAssemblyOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_set_AssemblyOptions(TElPDFDocumentHandle _Handle, TSBPDFAssemblyOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_DocumentRoot(TElPDFDocumentHandle _Handle, TElPDFArrayHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_PDFFile(TElPDFDocumentHandle _Handle, TElPDFFileHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_DecryptionMode(TElPDFDocumentHandle _Handle, TSBPDFDecryptionModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_set_DecryptionMode(TElPDFDocumentHandle _Handle, TSBPDFDecryptionModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_Adobe8Compatibility(TElPDFDocumentHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_set_Adobe8Compatibility(TElPDFDocumentHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_ExtractSignaturesFromPages(TElPDFDocumentHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_set_ExtractSignaturesFromPages(TElPDFDocumentHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_SignatureCustomDataName(TElPDFDocumentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_set_SignatureCustomDataName(TElPDFDocumentHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_LegalContentAttestation(TElPDFDocumentHandle _Handle, TElPDFLegalContentAttestationHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_ActivateSecurityHandlers(TElPDFDocumentHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_set_ActivateSecurityHandlers(TElPDFDocumentHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_OwnActivatedSecurityHandlers(TElPDFDocumentHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_set_OwnActivatedSecurityHandlers(TElPDFDocumentHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_Compress(TElPDFDocumentHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_set_Compress(TElPDFDocumentHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_OnProgress(TElPDFDocumentHandle _Handle, TSBPDFProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_set_OnProgress(TElPDFDocumentHandle _Handle, TSBPDFProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_OnCreateTemporaryStream(TElPDFDocumentHandle _Handle, TSBPDFCreateTemporaryStreamEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_set_OnCreateTemporaryStream(TElPDFDocumentHandle _Handle, TSBPDFCreateTemporaryStreamEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_OnDecryptionInfoNeeded(TElPDFDocumentHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_set_OnDecryptionInfoNeeded(TElPDFDocumentHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_get_OnBeforeSign(TElPDFDocumentHandle _Handle, TSBPDFBeforeSignEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_set_OnBeforeSign(TElPDFDocumentHandle _Handle, TSBPDFBeforeSignEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDocument_Create(TComponentHandle AOwner, TElPDFDocumentHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFDOCUMENT */

#ifdef SB_USE_CLASS_TELPDFURPROPERTIES
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_get_AnnotationRights(TElPDFURPropertiesHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_set_AnnotationRights(TElPDFURPropertiesHandle _Handle, TStringListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_get_DocumentRights(TElPDFURPropertiesHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_set_DocumentRights(TElPDFURPropertiesHandle _Handle, TStringListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_get_EmbeddedFileRights(TElPDFURPropertiesHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_set_EmbeddedFileRights(TElPDFURPropertiesHandle _Handle, TStringListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_get_FormExRights(TElPDFURPropertiesHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_set_FormExRights(TElPDFURPropertiesHandle _Handle, TStringListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_get_FormRights(TElPDFURPropertiesHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_set_FormRights(TElPDFURPropertiesHandle _Handle, TStringListHandle Value);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_get_AnnotationRights(TElPDFURPropertiesHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_set_AnnotationRights(TElPDFURPropertiesHandle _Handle, TElStringListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_get_DocumentRights(TElPDFURPropertiesHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_set_DocumentRights(TElPDFURPropertiesHandle _Handle, TElStringListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_get_EmbeddedFileRights(TElPDFURPropertiesHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_set_EmbeddedFileRights(TElPDFURPropertiesHandle _Handle, TElStringListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_get_FormExRights(TElPDFURPropertiesHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_set_FormExRights(TElPDFURPropertiesHandle _Handle, TElStringListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_get_FormRights(TElPDFURPropertiesHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_set_FormRights(TElPDFURPropertiesHandle _Handle, TElStringListHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_get_Message(TElPDFURPropertiesHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_set_Message(TElPDFURPropertiesHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_get_P(TElPDFURPropertiesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_set_P(TElPDFURPropertiesHandle _Handle, int8_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_get_SignatureRights(TElPDFURPropertiesHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_set_SignatureRights(TElPDFURPropertiesHandle _Handle, TStringListHandle Value);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_get_SignatureRights(TElPDFURPropertiesHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_set_SignatureRights(TElPDFURPropertiesHandle _Handle, TElStringListHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPDFURProperties_Create(TElPDFURPropertiesHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFURPROPERTIES */

#ifdef SB_USE_CLASS_TELPDFSIGREFENTRY
SB_IMPORT uint32_t SB_APIENTRY TElPDFSigRefEntry_get_Valid(TElPDFSigRefEntryHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSigRefEntry_get_DocMDPAccessPermissions(TElPDFSigRefEntryHandle _Handle, int16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSigRefEntry_set_DocMDPAccessPermissions(TElPDFSigRefEntryHandle _Handle, int16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSigRefEntry_get_FieldMDPAction(TElPDFSigRefEntryHandle _Handle, TSBPDFFieldMDPActionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSigRefEntry_set_FieldMDPAction(TElPDFSigRefEntryHandle _Handle, TSBPDFFieldMDPActionRaw Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPDFSigRefEntry_get_FieldMDPFields(TElPDFSigRefEntryHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPDFSigRefEntry_get_FieldMDPFields(TElPDFSigRefEntryHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPDFSigRefEntry_get_DigestMethod(TElPDFSigRefEntryHandle _Handle, TSBPDFDigestMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSigRefEntry_set_DigestMethod(TElPDFSigRefEntryHandle _Handle, TSBPDFDigestMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSigRefEntry_get_TransformMethod(TElPDFSigRefEntryHandle _Handle, TSBPDFTransformMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSigRefEntry_set_TransformMethod(TElPDFSigRefEntryHandle _Handle, TSBPDFTransformMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSigRefEntry_get_URProperties(TElPDFSigRefEntryHandle _Handle, TElPDFURPropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSigRefEntry_Create(TElPDFSigRefEntryHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFSIGREFENTRY */

#ifdef SB_USE_CLASS_TELPDFSECURITYHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_Reset(TElPDFSecurityHandlerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_GetName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_GetName_1(TElPDFSecurityHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_GetDescription(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_GetDescription_1(TElPDFSecurityHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_get_StreamEncryptionAlgorithm(TElPDFSecurityHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_set_StreamEncryptionAlgorithm(TElPDFSecurityHandlerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_get_StringEncryptionAlgorithm(TElPDFSecurityHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_set_StringEncryptionAlgorithm(TElPDFSecurityHandlerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_get_StreamEncryptionKeyBits(TElPDFSecurityHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_set_StreamEncryptionKeyBits(TElPDFSecurityHandlerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_get_StringEncryptionKeyBits(TElPDFSecurityHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_set_StringEncryptionKeyBits(TElPDFSecurityHandlerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_get_EncryptMetadata(TElPDFSecurityHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_set_EncryptMetadata(TElPDFSecurityHandlerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_get_CustomName(TElPDFSecurityHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_set_CustomName(TElPDFSecurityHandlerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_get_CryptoProviderManager(TElPDFSecurityHandlerHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_set_CryptoProviderManager(TElPDFSecurityHandlerHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSecurityHandler_Create(TComponentHandle Owner, TElPDFSecurityHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFSECURITYHANDLER */

#ifdef SB_USE_CLASS_TELPDFBYTERANGE
SB_IMPORT uint32_t SB_APIENTRY TElPDFByteRange_get_StartOffset(TElPDFByteRangeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFByteRange_set_StartOffset(TElPDFByteRangeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFByteRange_get_Count(TElPDFByteRangeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFByteRange_set_Count(TElPDFByteRangeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFByteRange_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFBYTERANGE */

#ifdef SB_USE_CLASS_TELPDFIMAGE
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_AddMaskColorComponent(TElPDFImageHandle _Handle, int32_t MinCC, int32_t MaxCC, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_DeleteMaskColorComponent(TElPDFImageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_get_ImageType(TElPDFImageHandle _Handle, TSBPDFImageTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_set_ImageType(TElPDFImageHandle _Handle, TSBPDFImageTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_get_Data(TElPDFImageHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_set_Data(TElPDFImageHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_get_Width(TElPDFImageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_set_Width(TElPDFImageHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_get_Height(TElPDFImageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_set_Height(TElPDFImageHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_get_MaskImage(TElPDFImageHandle _Handle, TElPDFImageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_get_MaskColorComponentCount(TElPDFImageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_get_MaskColorComponentsMin(TElPDFImageHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_get_MaskColorComponentsMax(TElPDFImageHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_get_BitsPerComponent(TElPDFImageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_set_BitsPerComponent(TElPDFImageHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_get_ColorSpaceType(TElPDFImageHandle _Handle, TSBPDFColorSpaceTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_set_ColorSpaceType(TElPDFImageHandle _Handle, TSBPDFColorSpaceTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_get_Interpolate(TElPDFImageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_set_Interpolate(TElPDFImageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_get_ResourceName(TElPDFImageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_set_ResourceName(TElPDFImageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFImage_Create(TElPDFImageHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFIMAGE */

#ifdef SB_USE_CLASS_TELPDFCUSTOMFONTOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElPDFCustomFontObject_Create(TElPDFCustomFontObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFCUSTOMFONTOBJECT */

#ifdef SB_USE_CLASS_TELPDFENCODING
SB_IMPORT uint32_t SB_APIENTRY TElPDFEncoding_get_BaseEncoding(TElPDFEncodingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFEncoding_set_BaseEncoding(TElPDFEncodingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFEncoding_get_Differences(TElPDFEncodingHandle _Handle, int32_t Index, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFEncoding_set_Differences(TElPDFEncodingHandle _Handle, int32_t Index, const char * pcName, int32_t szName);
SB_IMPORT uint32_t SB_APIENTRY TElPDFEncoding_Create(TElPDFEncodingHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFENCODING */

#ifdef SB_USE_CLASS_TELPDFFONTDESCRIPTOR
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_FontName(TElPDFFontDescriptorHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_FontName(TElPDFFontDescriptorHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_FontFamily(TElPDFFontDescriptorHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_FontFamily(TElPDFFontDescriptorHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_FontStretch(TElPDFFontDescriptorHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_FontStretch(TElPDFFontDescriptorHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_FontWeight(TElPDFFontDescriptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_FontWeight(TElPDFFontDescriptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_Flags(TElPDFFontDescriptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_Flags(TElPDFFontDescriptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_FontBBoxX1(TElPDFFontDescriptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_FontBBoxX1(TElPDFFontDescriptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_FontBBoxX2(TElPDFFontDescriptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_FontBBoxX2(TElPDFFontDescriptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_FontBBoxY1(TElPDFFontDescriptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_FontBBoxY1(TElPDFFontDescriptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_FontBBoxY2(TElPDFFontDescriptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_FontBBoxY2(TElPDFFontDescriptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_ItalicAngle(TElPDFFontDescriptorHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_ItalicAngle(TElPDFFontDescriptorHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_Ascent(TElPDFFontDescriptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_Ascent(TElPDFFontDescriptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_Descent(TElPDFFontDescriptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_Descent(TElPDFFontDescriptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_Leading(TElPDFFontDescriptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_Leading(TElPDFFontDescriptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_CapHeight(TElPDFFontDescriptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_CapHeight(TElPDFFontDescriptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_XHeight(TElPDFFontDescriptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_XHeight(TElPDFFontDescriptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_StemV(TElPDFFontDescriptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_StemV(TElPDFFontDescriptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_StemH(TElPDFFontDescriptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_StemH(TElPDFFontDescriptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_AvgWidth(TElPDFFontDescriptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_AvgWidth(TElPDFFontDescriptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_MaxWidth(TElPDFFontDescriptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_MaxWidth(TElPDFFontDescriptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_MissingWidth(TElPDFFontDescriptorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_MissingWidth(TElPDFFontDescriptorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_FontFile(TElPDFFontDescriptorHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_FontFile(TElPDFFontDescriptorHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_FontFile2(TElPDFFontDescriptorHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_FontFile2(TElPDFFontDescriptorHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_FontFile3(TElPDFFontDescriptorHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_FontFile3(TElPDFFontDescriptorHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_get_CharSet(TElPDFFontDescriptorHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_set_CharSet(TElPDFFontDescriptorHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFontDescriptor_Create(TElPDFFontDescriptorHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFFONTDESCRIPTOR */

#ifdef SB_USE_CLASS_TELPDFCIDFONTDESCRIPTOR
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFontDescriptor_get_Lang(TElPDFCIDFontDescriptorHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFontDescriptor_set_Lang(TElPDFCIDFontDescriptorHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFontDescriptor_get_CIDSet(TElPDFCIDFontDescriptorHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFontDescriptor_set_CIDSet(TElPDFCIDFontDescriptorHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFontDescriptor_Create(TElPDFCIDFontDescriptorHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFCIDFONTDESCRIPTOR */

#ifdef SB_USE_CLASS_TELPDFCIDSYSTEMINFO
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDSystemInfo_get_Registry(TElPDFCIDSystemInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDSystemInfo_set_Registry(TElPDFCIDSystemInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDSystemInfo_get_Ordering(TElPDFCIDSystemInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDSystemInfo_set_Ordering(TElPDFCIDSystemInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDSystemInfo_get_Supplement(TElPDFCIDSystemInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDSystemInfo_set_Supplement(TElPDFCIDSystemInfoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDSystemInfo_Create(TElPDFCIDSystemInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFCIDSYSTEMINFO */

#ifdef SB_USE_CLASS_TELPDFCUSTOMFONT
SB_IMPORT uint32_t SB_APIENTRY TElPDFCustomFont_get_Subtype(TElPDFCustomFontHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCustomFont_set_Subtype(TElPDFCustomFontHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCustomFont_get_BaseFont(TElPDFCustomFontHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCustomFont_set_BaseFont(TElPDFCustomFontHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCustomFont_get_ResourceName(TElPDFCustomFontHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCustomFont_set_ResourceName(TElPDFCustomFontHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCustomFont_get_ToUnicode(TElPDFCustomFontHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCustomFont_set_ToUnicode(TElPDFCustomFontHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCustomFont_Create(TElPDFCustomFontHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFCUSTOMFONT */

#ifdef SB_USE_CLASS_TELPDFSIMPLEFONT
SB_IMPORT uint32_t SB_APIENTRY TElPDFSimpleFont_get_Encoding(TElPDFSimpleFontHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSimpleFont_set_Encoding(TElPDFSimpleFontHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSimpleFont_get_EncodingObject(TElPDFSimpleFontHandle _Handle, TElPDFEncodingHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSimpleFont_set_EncodingObject(TElPDFSimpleFontHandle _Handle, TElPDFEncodingHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSimpleFont_get_FontDescriptor(TElPDFSimpleFontHandle _Handle, TElPDFFontDescriptorHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSimpleFont_set_FontDescriptor(TElPDFSimpleFontHandle _Handle, TElPDFFontDescriptorHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSimpleFont_get_FontName(TElPDFSimpleFontHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSimpleFont_set_FontName(TElPDFSimpleFontHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSimpleFont_get_FirstChar(TElPDFSimpleFontHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSimpleFont_set_FirstChar(TElPDFSimpleFontHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSimpleFont_get_LastChar(TElPDFSimpleFontHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSimpleFont_set_LastChar(TElPDFSimpleFontHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSimpleFont_get_Widths(TElPDFSimpleFontHandle _Handle, int32_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSimpleFont_set_Widths(TElPDFSimpleFontHandle _Handle, const int32_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSimpleFont_Create(TElPDFSimpleFontHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFSIMPLEFONT */

#ifdef SB_USE_CLASS_TELPDFCOMPOSITEFONT
SB_IMPORT uint32_t SB_APIENTRY TElPDFCompositeFont_get_DescendantFonts(TElPDFCompositeFontHandle _Handle, TElPDFCustomFontHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCompositeFont_set_DescendantFonts(TElPDFCompositeFontHandle _Handle, TElPDFCustomFontHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCompositeFont_get_Encoding(TElPDFCompositeFontHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCompositeFont_set_Encoding(TElPDFCompositeFontHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCompositeFont_get_EncodingData(TElPDFCompositeFontHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCompositeFont_set_EncodingData(TElPDFCompositeFontHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCompositeFont_Create(TElPDFCompositeFontHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFCOMPOSITEFONT */

#ifdef SB_USE_CLASS_TELPDFMETRICW
SB_IMPORT uint32_t SB_APIENTRY TElPDFMetricW_Add(TElPDFMetricWHandle _Handle, int32_t CID, int32_t Width);
SB_IMPORT uint32_t SB_APIENTRY TElPDFMetricW_AddRange(TElPDFMetricWHandle _Handle, int32_t First, int32_t Last, int32_t Width);
SB_IMPORT uint32_t SB_APIENTRY TElPDFMetricW_Create(TElPDFMetricWHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFMETRICW */

#ifdef SB_USE_CLASS_TELPDFMETRICW2
SB_IMPORT uint32_t SB_APIENTRY TElPDFMetricW2_Add(TElPDFMetricW2Handle _Handle, int32_t CID, int32_t Width, int32_t VX, int32_t VY);
SB_IMPORT uint32_t SB_APIENTRY TElPDFMetricW2_AddRange(TElPDFMetricW2Handle _Handle, int32_t First, int32_t Last, int32_t Width, int32_t VX, int32_t VY);
SB_IMPORT uint32_t SB_APIENTRY TElPDFMetricW2_Create(TElPDFMetricW2Handle * OutResult);
#endif /* SB_USE_CLASS_TELPDFMETRICW2 */

#ifdef SB_USE_CLASS_TELPDFCIDFONT
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFont_get_CIDSystemInfo(TElPDFCIDFontHandle _Handle, TElPDFCIDSystemInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFont_set_CIDSystemInfo(TElPDFCIDFontHandle _Handle, TElPDFCIDSystemInfoHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFont_get_FontDescriptor(TElPDFCIDFontHandle _Handle, TElPDFCIDFontDescriptorHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFont_set_FontDescriptor(TElPDFCIDFontHandle _Handle, TElPDFCIDFontDescriptorHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFont_get_DW(TElPDFCIDFontHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFont_set_DW(TElPDFCIDFontHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFont_get_W(TElPDFCIDFontHandle _Handle, TElPDFMetricWHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFont_get_DW2(TElPDFCIDFontHandle _Handle, int32_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFont_set_DW2(TElPDFCIDFontHandle _Handle, const int32_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFont_get_W2(TElPDFCIDFontHandle _Handle, TElPDFMetricW2Handle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFont_set_W2(TElPDFCIDFontHandle _Handle, TElPDFMetricW2Handle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFont_get_CIDToGIDMap(TElPDFCIDFontHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFont_set_CIDToGIDMap(TElPDFCIDFontHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFont_get_CIDToGIDMapData(TElPDFCIDFontHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFont_set_CIDToGIDMapData(TElPDFCIDFontHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCIDFont_Create(TElPDFCIDFontHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFCIDFONT */

#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXT
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetText_get_Text(TElPDFSignatureWidgetTextHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetText_set_Text(TElPDFSignatureWidgetTextHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetText_get_FontSizeX(TElPDFSignatureWidgetTextHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetText_set_FontSizeX(TElPDFSignatureWidgetTextHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetText_get_FontSizeY(TElPDFSignatureWidgetTextHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetText_set_FontSizeY(TElPDFSignatureWidgetTextHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetText_get_X(TElPDFSignatureWidgetTextHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetText_set_X(TElPDFSignatureWidgetTextHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetText_get_Y(TElPDFSignatureWidgetTextHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetText_set_Y(TElPDFSignatureWidgetTextHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetText_get_FontResourceName(TElPDFSignatureWidgetTextHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetText_set_FontResourceName(TElPDFSignatureWidgetTextHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetText_get_CustomData(TElPDFSignatureWidgetTextHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetText_set_CustomData(TElPDFSignatureWidgetTextHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetText_Create(TElPDFSignatureWidgetTextHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXT */

#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXTLIST
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetTextList_Add(TElPDFSignatureWidgetTextListHandle _Handle, const char * pcText, int32_t szText, double X, double Y, double FontSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetTextList_Add_1(TElPDFSignatureWidgetTextListHandle _Handle, const char * pcText, int32_t szText, double X, double Y, double FontSizeX, double FontSizeY, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetTextList_Add_2(TElPDFSignatureWidgetTextListHandle _Handle, TElPDFSignatureWidgetTextHandle ATextData, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetTextList_Add_3(TElPDFSignatureWidgetTextListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetTextList_Delete(TElPDFSignatureWidgetTextListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetTextList_Clear(TElPDFSignatureWidgetTextListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetTextList_get_Count(TElPDFSignatureWidgetTextListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetTextList_get_TextData(TElPDFSignatureWidgetTextListHandle _Handle, int32_t Index, TElPDFSignatureWidgetTextHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetTextList_Create(TElPDFSignatureWidgetTextListHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXTLIST */

#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETPROPS
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_AddFont(TElPDFSignatureWidgetPropsHandle _Handle, TElPDFCustomFontHandle Font);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_AddFontObject(TElPDFSignatureWidgetPropsHandle _Handle, TElPDFCustomFontObjectHandle FontObject);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_AddImage(TElPDFSignatureWidgetPropsHandle _Handle, TElPDFImageHandle Image);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_AddImage_1(TElPDFSignatureWidgetPropsHandle _Handle, TElPDFImageHandle Image, double X, double Y, double SizeX, double SizeY);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_ClearFonts(TElPDFSignatureWidgetPropsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_ClearFontObjects(TElPDFSignatureWidgetPropsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_ClearImages(TElPDFSignatureWidgetPropsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_AlgorithmInfo(TElPDFSignatureWidgetPropsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_AlgorithmInfo(TElPDFSignatureWidgetPropsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_AutoAdjustEncoding(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_AutoAdjustEncoding(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_AutoText(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_AutoText(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_AutoFontSize(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_AutoFontSize(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_AutoSize(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_AutoSize(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_AutoPos(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_AutoPos(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_AutoStretchBackground(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_AutoStretchBackground(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_Header(TElPDFSignatureWidgetPropsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_Header(TElPDFSignatureWidgetPropsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_Height(TElPDFSignatureWidgetPropsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_Height(TElPDFSignatureWidgetPropsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_Locked(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_Locked(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_LockedContents(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_LockedContents(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_NoRotate(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_NoRotate(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_NoView(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_NoView(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_NoZoom(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_NoZoom(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_Print(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_Print(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_ReadOnly(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_ReadOnly(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_ToggleNoView(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_ToggleNoView(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_ShowTimestamp(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_ShowTimestamp(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_SignerInfo(TElPDFSignatureWidgetPropsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_SignerInfo(TElPDFSignatureWidgetPropsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_Width(TElPDFSignatureWidgetPropsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_Width(TElPDFSignatureWidgetPropsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_OffsetX(TElPDFSignatureWidgetPropsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_OffsetX(TElPDFSignatureWidgetPropsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_OffsetY(TElPDFSignatureWidgetPropsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_OffsetY(TElPDFSignatureWidgetPropsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_TitleFontSize(TElPDFSignatureWidgetPropsHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_TitleFontSize(TElPDFSignatureWidgetPropsHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_TimestampFontSize(TElPDFSignatureWidgetPropsHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_TimestampFontSize(TElPDFSignatureWidgetPropsHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_SectionTitleFontSize(TElPDFSignatureWidgetPropsHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_SectionTitleFontSize(TElPDFSignatureWidgetPropsHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_SectionTextFontSize(TElPDFSignatureWidgetPropsHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_SectionTextFontSize(TElPDFSignatureWidgetPropsHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_Background(TElPDFSignatureWidgetPropsHandle _Handle, TElPDFImageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_BackgroundStyle(TElPDFSignatureWidgetPropsHandle _Handle, TSBPDFWidgetBackgroundStyleRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_BackgroundStyle(TElPDFSignatureWidgetPropsHandle _Handle, TSBPDFWidgetBackgroundStyleRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_StretchX(TElPDFSignatureWidgetPropsHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_StretchX(TElPDFSignatureWidgetPropsHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_StretchY(TElPDFSignatureWidgetPropsHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_StretchY(TElPDFSignatureWidgetPropsHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_Rotate(TElPDFSignatureWidgetPropsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_Rotate(TElPDFSignatureWidgetPropsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_SignerCaption(TElPDFSignatureWidgetPropsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_SignerCaption(TElPDFSignatureWidgetPropsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_AlgorithmCaption(TElPDFSignatureWidgetPropsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_AlgorithmCaption(TElPDFSignatureWidgetPropsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_DateCaptionFormat(TElPDFSignatureWidgetPropsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_DateCaptionFormat(TElPDFSignatureWidgetPropsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_CustomAppearance(TElPDFSignatureWidgetPropsHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_CustomAppearance(TElPDFSignatureWidgetPropsHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_CustomText(TElPDFSignatureWidgetPropsHandle _Handle, TElPDFSignatureWidgetTextListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_HideDefaultText(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_HideDefaultText(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_CompressWidgetData(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_CompressWidgetData(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_CustomBackgroundContentStream(TElPDFSignatureWidgetPropsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_CustomBackgroundContentStream(TElPDFSignatureWidgetPropsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_ShowVisualStatus(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_ShowVisualStatus(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_CustomVisualStatusMatrix(TElPDFSignatureWidgetPropsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_CustomVisualStatusMatrix(TElPDFSignatureWidgetPropsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_SigningTime(TElPDFSignatureWidgetPropsHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_SigningTime(TElPDFSignatureWidgetPropsHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_IgnoreExistingAppearance(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_IgnoreExistingAppearance(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_ShowOnAllPages(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_ShowOnAllPages(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_SaveStringsInUnicodeEncoding(TElPDFSignatureWidgetPropsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_SaveStringsInUnicodeEncoding(TElPDFSignatureWidgetPropsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_OnConvertStringToAnsi(TElPDFSignatureWidgetPropsHandle _Handle, TSBPDFConvertStringToAnsiEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_OnConvertStringToAnsi(TElPDFSignatureWidgetPropsHandle _Handle, TSBPDFConvertStringToAnsiEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_OnLookupGlyphName(TElPDFSignatureWidgetPropsHandle _Handle, TSBPDFLookupGlyphNameEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_OnLookupGlyphName(TElPDFSignatureWidgetPropsHandle _Handle, TSBPDFLookupGlyphNameEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_get_OnLookupGlyphWidth(TElPDFSignatureWidgetPropsHandle _Handle, TSBPDFLookupGlyphWidthEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_set_OnLookupGlyphWidth(TElPDFSignatureWidgetPropsHandle _Handle, TSBPDFLookupGlyphWidthEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureWidgetProps_Create(TElPDFSignatureWidgetPropsHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETPROPS */

#ifdef SB_USE_CLASS_TELPDFSIGNATURE
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_Validate(TElPDFSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_Validate_1(TElPDFSignatureHandle _Handle, int8_t MDPLiberalMode, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_GetSignedVersion(TElPDFSignatureHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_IsDocumentSigned(TElPDFSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_Update(TElPDFSignatureHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_Timestamp(TElPDFSignatureHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_SignatureType(TElPDFSignatureHandle _Handle, TSBPDFSignatureTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_SignatureType(TElPDFSignatureHandle _Handle, TSBPDFSignatureTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_AllowedChanges(TElPDFSignatureHandle _Handle, TSBPDFSignatureAllowedChangesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_AllowedChanges(TElPDFSignatureHandle _Handle, TSBPDFSignatureAllowedChangesRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_Handler(TElPDFSignatureHandle _Handle, TElPDFSecurityHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_Handler(TElPDFSignatureHandle _Handle, TElPDFSecurityHandlerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_SignatureName(TElPDFSignatureHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_SignatureName(TElPDFSignatureHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_AuthorName(TElPDFSignatureHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_AuthorName(TElPDFSignatureHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_ContactInfo(TElPDFSignatureHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_ContactInfo(TElPDFSignatureHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_Location(TElPDFSignatureHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_Location(TElPDFSignatureHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_Reason(TElPDFSignatureHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_Reason(TElPDFSignatureHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_SigningTime(TElPDFSignatureHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_SigningTime(TElPDFSignatureHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_WidgetProps(TElPDFSignatureHandle _Handle, TElPDFSignatureWidgetPropsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_Invisible(TElPDFSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_Invisible(TElPDFSignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_Page(TElPDFSignatureHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_Page(TElPDFSignatureHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_UseHexEncoding(TElPDFSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_UseHexEncoding(TElPDFSignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_MDPHashAlgorithm(TElPDFSignatureHandle _Handle, TSBPDFDigestMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_MDPHashAlgorithm(TElPDFSignatureHandle _Handle, TSBPDFDigestMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_DisableDocMDPTransformDigestValue(TElPDFSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_DisableDocMDPTransformDigestValue(TElPDFSignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_DisableFieldMDPTransformDigestValue(TElPDFSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_DisableFieldMDPTransformDigestValue(TElPDFSignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_ExtraSpace(TElPDFSignatureHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_ExtraSpace(TElPDFSignatureHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_EmptyField(TElPDFSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_EmptyField(TElPDFSignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_ExplicitElementSignature(TElPDFSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_ExplicitElementSignature(TElPDFSignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_ExplicitElement(TElPDFSignatureHandle _Handle, TElPDFObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_ExplicitElement(TElPDFSignatureHandle _Handle, TElPDFObjectHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_CustomData(TElPDFSignatureHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_CustomData(TElPDFSignatureHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_CustomDataEncoding(TElPDFSignatureHandle _Handle, TPDFStringEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_CustomDataEncoding(TElPDFSignatureHandle _Handle, TPDFStringEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_Options(TElPDFSignatureHandle _Handle, TSBPDFSignatureOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_Options(TElPDFSignatureHandle _Handle, TSBPDFSignatureOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_PDFObject(TElPDFSignatureHandle _Handle, TElPDFObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_LockAction(TElPDFSignatureHandle _Handle, TSBPDFFieldMDPActionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_set_LockAction(TElPDFSignatureHandle _Handle, TSBPDFFieldMDPActionRaw Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_LockFields(TElPDFSignatureHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_get_LockFields(TElPDFSignatureHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignature_Create(TElPDFDocumentHandle Owner, TElPDFSignatureHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFSIGNATURE */

#ifdef SB_USE_CLASS_TELPDFSIGNATUREINFO
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_FieldName(TElPDFSignatureInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_FieldFlags(TElPDFSignatureInfoHandle _Handle, TSBPDFFieldFlagsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_MappingName(TElPDFSignatureInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_AlternateName(TElPDFSignatureInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_RequiredConstraints(TElPDFSignatureInfoHandle _Handle, TSBSVDConstraintsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_RequiredFilter(TElPDFSignatureInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_RequiredSubfilters(TElPDFSignatureInfoHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_RequiredSubfilters(TElPDFSignatureInfoHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_RequiredDigestAlgorithms(TElPDFSignatureInfoHandle _Handle, int32_t pOutResult[], int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_RequiredReasons(TElPDFSignatureInfoHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_RequiredReasons(TElPDFSignatureInfoHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_RequiredLockAction(TElPDFSignatureInfoHandle _Handle, TSBPDFFieldMDPActionRaw * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_RequiredLockFields(TElPDFSignatureInfoHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_RequiredLockFields(TElPDFSignatureInfoHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_RequiredAllowedChanges(TElPDFSignatureInfoHandle _Handle, TSBPDFSignatureAllowedChangesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_TSPURL(TElPDFSignatureInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_TimestampRequired(TElPDFSignatureInfoHandle _Handle, int8_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_LegalAttestations(TElPDFSignatureInfoHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_LegalAttestations(TElPDFSignatureInfoHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_AddRevInfo(TElPDFSignatureInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_Height(TElPDFSignatureInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_Width(TElPDFSignatureInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_OffsetX(TElPDFSignatureInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_OffsetY(TElPDFSignatureInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_Page(TElPDFSignatureInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_get_Invisible(TElPDFSignatureInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFSignatureInfo_Create(TElPDFSignatureInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFSIGNATUREINFO */

#ifdef SB_USE_CLASS_TELPDFENCODINGHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElPDFEncodingHandler_GetName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFEncodingHandler_GetName_1(TElPDFEncodingHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFEncodingHandler_GetDescription(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFEncodingHandler_GetDescription_1(TElPDFEncodingHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFEncodingHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFEncodingHandler_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFENCODINGHANDLER */

#ifdef SB_USE_CLASS_TELPDFREQUIREMENTHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElPDFRequirementHandler_get_HandlerType(TElPDFRequirementHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFRequirementHandler_get_ScriptName(TElPDFRequirementHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFRequirementHandler_Create(TElPDFRequirementHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFREQUIREMENTHANDLER */

#ifdef SB_USE_CLASS_TELPDFREQUIREMENT
SB_IMPORT uint32_t SB_APIENTRY TElPDFRequirement_get_RequirementType(TElPDFRequirementHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFRequirement_get_HandlerCount(TElPDFRequirementHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFRequirement_get_Handlers(TElPDFRequirementHandle _Handle, int32_t Index, TElPDFRequirementHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFRequirement_Create(TElPDFRequirementHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFREQUIREMENT */

#ifdef SB_USE_CLASS_TELPDFPAGEINFO
SB_IMPORT uint32_t SB_APIENTRY TElPDFPageInfo_CropBoxEmpty(TElPDFPageInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPageInfo_get_Width(TElPDFPageInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPageInfo_get_Height(TElPDFPageInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPageInfo_get_Rotate(TElPDFPageInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPageInfo_get_CropLLX(TElPDFPageInfoHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPageInfo_get_CropLLY(TElPDFPageInfoHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPageInfo_get_CropURX(TElPDFPageInfoHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPageInfo_get_CropURY(TElPDFPageInfoHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPageInfo_get_MediaLLX(TElPDFPageInfoHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPageInfo_get_MediaLLY(TElPDFPageInfoHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPageInfo_get_MediaURX(TElPDFPageInfoHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPageInfo_get_MediaURY(TElPDFPageInfoHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPageInfo_get_PageObject(TElPDFPageInfoHandle _Handle, TElPDFDictionaryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPageInfo_Create(TElPDFPageInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFPAGEINFO */

#ifdef SB_USE_CLASS_TELPDFFILEATTACHMENT
SB_IMPORT uint32_t SB_APIENTRY TElPDFFileAttachment_Init(TElPDFFileAttachmentHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFileAttachment_Save(TElPDFFileAttachmentHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFileAttachment_get_ObjectName(TElPDFFileAttachmentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFileAttachment_set_ObjectName(TElPDFFileAttachmentHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFileAttachment_get_Filename(TElPDFFileAttachmentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFileAttachment_set_Filename(TElPDFFileAttachmentHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFileAttachment_get_UnicodeFilename(TElPDFFileAttachmentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFileAttachment_set_UnicodeFilename(TElPDFFileAttachmentHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFileAttachment_get_Description(TElPDFFileAttachmentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFileAttachment_set_Description(TElPDFFileAttachmentHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFileAttachment_get_SubType(TElPDFFileAttachmentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFileAttachment_set_SubType(TElPDFFileAttachmentHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFileAttachment_get_Size(TElPDFFileAttachmentHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFileAttachment_get_CreationDate(TElPDFFileAttachmentHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFileAttachment_set_CreationDate(TElPDFFileAttachmentHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFileAttachment_get_ModificationDate(TElPDFFileAttachmentHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFileAttachment_set_ModificationDate(TElPDFFileAttachmentHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFileAttachment_get_MD5Checksum(TElPDFFileAttachmentHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFileAttachment_Create(TElPDFFileAttachmentHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFFILEATTACHMENT */

#ifdef SB_USE_CLASS_TELPDFLEGALCONTENTATTESTATION
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_JavascriptActions(TElPDFLegalContentAttestationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_JavascriptActions(TElPDFLegalContentAttestationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_LaunchActions(TElPDFLegalContentAttestationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_LaunchActions(TElPDFLegalContentAttestationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_URIActions(TElPDFLegalContentAttestationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_URIActions(TElPDFLegalContentAttestationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_MovieActions(TElPDFLegalContentAttestationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_MovieActions(TElPDFLegalContentAttestationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_SoundActions(TElPDFLegalContentAttestationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_SoundActions(TElPDFLegalContentAttestationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_HideAnnotationActions(TElPDFLegalContentAttestationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_HideAnnotationActions(TElPDFLegalContentAttestationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_GoToRemoteActions(TElPDFLegalContentAttestationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_GoToRemoteActions(TElPDFLegalContentAttestationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_AlternateImages(TElPDFLegalContentAttestationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_AlternateImages(TElPDFLegalContentAttestationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_ExternalStreams(TElPDFLegalContentAttestationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_ExternalStreams(TElPDFLegalContentAttestationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_TrueTypeFonts(TElPDFLegalContentAttestationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_TrueTypeFonts(TElPDFLegalContentAttestationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_ExternalRefXObjects(TElPDFLegalContentAttestationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_ExternalRefXObjects(TElPDFLegalContentAttestationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_ExternalOPIDicts(TElPDFLegalContentAttestationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_ExternalOPIDicts(TElPDFLegalContentAttestationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_NonEmbeddedFonts(TElPDFLegalContentAttestationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_NonEmbeddedFonts(TElPDFLegalContentAttestationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_DevDepGSOP(TElPDFLegalContentAttestationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_DevDepGSOP(TElPDFLegalContentAttestationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_DevDepGSHT(TElPDFLegalContentAttestationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_DevDepGSHT(TElPDFLegalContentAttestationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_DevDepGSTR(TElPDFLegalContentAttestationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_DevDepGSTR(TElPDFLegalContentAttestationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_DevDepGSUCR(TElPDFLegalContentAttestationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_DevDepGSUCR(TElPDFLegalContentAttestationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_DevDepGSBG(TElPDFLegalContentAttestationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_DevDepGSBG(TElPDFLegalContentAttestationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_DevDepGSFL(TElPDFLegalContentAttestationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_DevDepGSFL(TElPDFLegalContentAttestationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_Annotations(TElPDFLegalContentAttestationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_Annotations(TElPDFLegalContentAttestationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_OptionalContent(TElPDFLegalContentAttestationHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_OptionalContent(TElPDFLegalContentAttestationHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_Attestation(TElPDFLegalContentAttestationHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_Attestation(TElPDFLegalContentAttestationHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_get_Include(TElPDFLegalContentAttestationHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_set_Include(TElPDFLegalContentAttestationHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFLegalContentAttestation_Create(TElPDFLegalContentAttestationHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFLEGALCONTENTATTESTATION */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPDFDocument;
typedef TElPDFDocument ElPDFDocument;
class TElPDFURProperties;
typedef TElPDFURProperties ElPDFURProperties;
class TElPDFSigRefEntry;
typedef TElPDFSigRefEntry ElPDFSigRefEntry;
class TElPDFSecurityHandler;
typedef TElPDFSecurityHandler ElPDFSecurityHandler;
class TElPDFByteRange;
typedef TElPDFByteRange ElPDFByteRange;
class TElPDFImage;
typedef TElPDFImage ElPDFImage;
class TElPDFCustomFontObject;
typedef TElPDFCustomFontObject ElPDFCustomFontObject;
class TElPDFEncoding;
typedef TElPDFEncoding ElPDFEncoding;
class TElPDFFontDescriptor;
typedef TElPDFFontDescriptor ElPDFFontDescriptor;
class TElPDFCIDFontDescriptor;
typedef TElPDFCIDFontDescriptor ElPDFCIDFontDescriptor;
class TElPDFCIDSystemInfo;
typedef TElPDFCIDSystemInfo ElPDFCIDSystemInfo;
class TElPDFCustomFont;
typedef TElPDFCustomFont ElPDFCustomFont;
class TElPDFSimpleFont;
typedef TElPDFSimpleFont ElPDFSimpleFont;
class TElPDFCompositeFont;
typedef TElPDFCompositeFont ElPDFCompositeFont;
class TElPDFMetricW;
typedef TElPDFMetricW ElPDFMetricW;
class TElPDFMetricW2;
typedef TElPDFMetricW2 ElPDFMetricW2;
class TElPDFCIDFont;
typedef TElPDFCIDFont ElPDFCIDFont;
class TElPDFSignatureWidgetText;
typedef TElPDFSignatureWidgetText ElPDFSignatureWidgetText;
class TElPDFSignatureWidgetTextList;
typedef TElPDFSignatureWidgetTextList ElPDFSignatureWidgetTextList;
class TElPDFSignatureWidgetProps;
typedef TElPDFSignatureWidgetProps ElPDFSignatureWidgetProps;
class TElPDFSignature;
typedef TElPDFSignature ElPDFSignature;
class TElPDFSignatureInfo;
typedef TElPDFSignatureInfo ElPDFSignatureInfo;
class TElPDFEncodingHandler;
typedef TElPDFEncodingHandler ElPDFEncodingHandler;
class TElPDFRequirementHandler;
typedef TElPDFRequirementHandler ElPDFRequirementHandler;
class TElPDFRequirement;
typedef TElPDFRequirement ElPDFRequirement;
class TElPDFPageInfo;
typedef TElPDFPageInfo ElPDFPageInfo;
class TElPDFFileAttachment;
class TElPDFLegalContentAttestation;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBPDFSignatureAllowedChanges)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBPDFSignatureOptions)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBSVDConstraints)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBPDFFieldFlags)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBPDFAssemblyOptions)

#ifdef SB_USE_CLASS_TELPDFDOCUMENT
class TElPDFDocument: public TComponent
{
	private:
		SB_DISABLE_COPY(TElPDFDocument)
#ifdef SB_USE_CLASS_TELPDFPAGEINFO
		TElPDFPageInfo* _Inst_PageInfos;
#endif /* SB_USE_CLASS_TELPDFPAGEINFO */
#ifdef SB_USE_CLASS_TELPDFSIGNATURE
		TElPDFSignature* _Inst_Signatures;
#endif /* SB_USE_CLASS_TELPDFSIGNATURE */
#ifdef SB_USE_CLASS_TELPDFFILEATTACHMENT
		TElPDFFileAttachment* _Inst_AttachedFiles;
#endif /* SB_USE_CLASS_TELPDFFILEATTACHMENT */
#ifdef SB_USE_CLASS_TELPDFSIGNATUREINFO
		TElPDFSignatureInfo* _Inst_EmptySignatureFields;
#endif /* SB_USE_CLASS_TELPDFSIGNATUREINFO */
#ifdef SB_USE_CLASS_TELPDFREQUIREMENT
		TElPDFRequirement* _Inst_DocumentRequirements;
#endif /* SB_USE_CLASS_TELPDFREQUIREMENT */
#ifdef SB_USE_CLASS_TELPDFARRAY
		TElPDFArray* _Inst_DocumentID;
#endif /* SB_USE_CLASS_TELPDFARRAY */
#ifdef SB_USE_CLASS_TELPDFSECURITYHANDLER
		TElPDFSecurityHandler* _Inst_EncryptionHandler;
#endif /* SB_USE_CLASS_TELPDFSECURITYHANDLER */
#ifdef SB_USE_CLASS_TELPDFARRAY
		TElPDFArray* _Inst_DocumentRoot;
#endif /* SB_USE_CLASS_TELPDFARRAY */
#ifdef SB_USE_CLASS_TELPDFFILE
		TElPDFFile* _Inst_PDFFile;
#endif /* SB_USE_CLASS_TELPDFFILE */
#ifdef SB_USE_CLASS_TELPDFLEGALCONTENTATTESTATION
		TElPDFLegalContentAttestation* _Inst_LegalContentAttestation;
#endif /* SB_USE_CLASS_TELPDFLEGALCONTENTATTESTATION */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TSTREAM
		void Open(TStream &Stream);

		void Open(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		void Close(bool Save);

		void Encrypt();

		void SignAndEncrypt();

		void Decrypt();

		int32_t AddSignature();

		int32_t AddSignature(int32_t EmptySignatureField);

#ifdef SB_USE_CLASS_TELPDFSIGNATURE
		TElPDFSignatureHandle InsertSignature(int32_t Index);
#endif /* SB_USE_CLASS_TELPDFSIGNATURE */

		void ClearSignatures();

		void RemoveSignature(int32_t Index);

		void RemoveSignature(int32_t Index, TSBPDFSignatureRemoveOption SigRemoveOption);

		void RemoveEmptySignatureField(int32_t Index);

		void RemoveEmptySignatureField(int32_t Index, TSBPDFSignatureRemoveOption SigRemoveOption);

		int32_t AddAttachedFile();

		void RemoveAttachedFile(int32_t Index);

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
		TElDCAsyncStateHandle InitiateAsyncOperation();
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
		TElDCAsyncStateHandle InitiateAsyncOperation(TSBDCAsyncSignMethod AsyncSignMethod);
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELPDFSECURITYHANDLER_AND_TSTREAM
		void CompleteAsyncOperation(TStream &Stream, TElDCAsyncState &AsyncState, TElPDFSecurityHandler &Handler);

		void CompleteAsyncOperation(TStream *Stream, TElDCAsyncState *AsyncState, TElPDFSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELPDFSECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELPDFPAGEINFO
		virtual TElPDFPageInfo* get_PageInfos(int32_t Index);
#endif /* SB_USE_CLASS_TELPDFPAGEINFO */

#ifdef SB_USE_CLASS_TELPDFSIGNATURE
		virtual TElPDFSignature* get_Signatures(int32_t Index);
#endif /* SB_USE_CLASS_TELPDFSIGNATURE */

#ifdef SB_USE_CLASS_TELPDFFILEATTACHMENT
		virtual TElPDFFileAttachment* get_AttachedFiles(int32_t Index);
#endif /* SB_USE_CLASS_TELPDFFILEATTACHMENT */

#ifdef SB_USE_CLASS_TELPDFSIGNATUREINFO
		virtual TElPDFSignatureInfo* get_EmptySignatureFields(int32_t Index);
#endif /* SB_USE_CLASS_TELPDFSIGNATUREINFO */

#ifdef SB_USE_CLASS_TELPDFREQUIREMENT
		virtual TElPDFRequirement* get_DocumentRequirements(int32_t Index);
#endif /* SB_USE_CLASS_TELPDFREQUIREMENT */

#ifdef SB_USE_CLASS_TELPDFARRAY
		virtual TElPDFArray* get_DocumentID();

		SB_DECLARE_PROPERTY_GET(TElPDFArray*, get_DocumentID, TElPDFDocument, DocumentID);
#endif /* SB_USE_CLASS_TELPDFARRAY */

		virtual int32_t get_DocumentVersion();

		virtual void set_DocumentVersion(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DocumentVersion, set_DocumentVersion, TElPDFDocument, DocumentVersion);

		virtual int32_t get_EmptySignatureFieldCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_EmptySignatureFieldCount, TElPDFDocument, EmptySignatureFieldCount);

		virtual bool get_Decrypted();

		SB_DECLARE_PROPERTY_GET(bool, get_Decrypted, TElPDFDocument, Decrypted);

		virtual bool get_Encrypted();

		SB_DECLARE_PROPERTY_GET(bool, get_Encrypted, TElPDFDocument, Encrypted);

#ifdef SB_USE_CLASS_TELPDFSECURITYHANDLER
		virtual TElPDFSecurityHandler* get_EncryptionHandler();

		virtual void set_EncryptionHandler(TElPDFSecurityHandler &Value);

		virtual void set_EncryptionHandler(TElPDFSecurityHandler *Value);

		SB_DECLARE_PROPERTY(TElPDFSecurityHandler*, get_EncryptionHandler, set_EncryptionHandler, TElPDFDocument, EncryptionHandler);
#endif /* SB_USE_CLASS_TELPDFSECURITYHANDLER */

		virtual bool get_Opened();

		SB_DECLARE_PROPERTY_GET(bool, get_Opened, TElPDFDocument, Opened);

		virtual int32_t get_DocumentRequirementCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_DocumentRequirementCount, TElPDFDocument, DocumentRequirementCount);

		virtual int32_t get_PageInfoCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_PageInfoCount, TElPDFDocument, PageInfoCount);

		virtual int32_t get_SignatureCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignatureCount, TElPDFDocument, SignatureCount);

		virtual bool get_Signed();

		SB_DECLARE_PROPERTY_GET(bool, get_Signed, TElPDFDocument, Signed);

		virtual int32_t get_AttachedFileCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AttachedFileCount, TElPDFDocument, AttachedFileCount);

		virtual TSBPDFAssemblyOptions get_AssemblyOptions();

		virtual void set_AssemblyOptions(TSBPDFAssemblyOptions Value);

		SB_DECLARE_PROPERTY(TSBPDFAssemblyOptions, get_AssemblyOptions, set_AssemblyOptions, TElPDFDocument, AssemblyOptions);

#ifdef SB_USE_CLASS_TELPDFARRAY
		virtual TElPDFArray* get_DocumentRoot();

		SB_DECLARE_PROPERTY_GET(TElPDFArray*, get_DocumentRoot, TElPDFDocument, DocumentRoot);
#endif /* SB_USE_CLASS_TELPDFARRAY */

#ifdef SB_USE_CLASS_TELPDFFILE
		virtual TElPDFFile* get_PDFFile();

		SB_DECLARE_PROPERTY_GET(TElPDFFile*, get_PDFFile, TElPDFDocument, PDFFile);
#endif /* SB_USE_CLASS_TELPDFFILE */

		virtual TSBPDFDecryptionMode get_DecryptionMode();

		virtual void set_DecryptionMode(TSBPDFDecryptionMode Value);

		SB_DECLARE_PROPERTY(TSBPDFDecryptionMode, get_DecryptionMode, set_DecryptionMode, TElPDFDocument, DecryptionMode);

		virtual bool get_Adobe8Compatibility();

		virtual void set_Adobe8Compatibility(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Adobe8Compatibility, set_Adobe8Compatibility, TElPDFDocument, Adobe8Compatibility);

		virtual bool get_ExtractSignaturesFromPages();

		virtual void set_ExtractSignaturesFromPages(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ExtractSignaturesFromPages, set_ExtractSignaturesFromPages, TElPDFDocument, ExtractSignaturesFromPages);

		virtual void get_SignatureCustomDataName(std::string &OutResult);

		virtual void set_SignatureCustomDataName(const std::string &Value);

#ifdef SB_USE_CLASS_TELPDFLEGALCONTENTATTESTATION
		virtual TElPDFLegalContentAttestation* get_LegalContentAttestation();

		SB_DECLARE_PROPERTY_GET(TElPDFLegalContentAttestation*, get_LegalContentAttestation, TElPDFDocument, LegalContentAttestation);
#endif /* SB_USE_CLASS_TELPDFLEGALCONTENTATTESTATION */

		virtual bool get_ActivateSecurityHandlers();

		virtual void set_ActivateSecurityHandlers(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ActivateSecurityHandlers, set_ActivateSecurityHandlers, TElPDFDocument, ActivateSecurityHandlers);

		virtual bool get_OwnActivatedSecurityHandlers();

		virtual void set_OwnActivatedSecurityHandlers(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OwnActivatedSecurityHandlers, set_OwnActivatedSecurityHandlers, TElPDFDocument, OwnActivatedSecurityHandlers);

		virtual bool get_Compress();

		virtual void set_Compress(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Compress, set_Compress, TElPDFDocument, Compress);

		virtual void get_OnProgress(TSBPDFProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBPDFProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnCreateTemporaryStream(TSBPDFCreateTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCreateTemporaryStream(TSBPDFCreateTemporaryStreamEvent pMethodValue, void * pDataValue);

		virtual void get_OnDecryptionInfoNeeded(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDecryptionInfoNeeded(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeSign(TSBPDFBeforeSignEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeSign(TSBPDFBeforeSignEvent pMethodValue, void * pDataValue);

		TElPDFDocument(TElPDFDocumentHandle handle, TElOwnHandle ownHandle);

		explicit TElPDFDocument(TComponent &AOwner);

		explicit TElPDFDocument(TComponent *AOwner);

		virtual ~TElPDFDocument();

};
#endif /* SB_USE_CLASS_TELPDFDOCUMENT */

#ifdef SB_USE_CLASS_TELPDFURPROPERTIES
class TElPDFURProperties: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFURProperties)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_AnnotationRights;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_DocumentRights;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_EmbeddedFileRights;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_FormExRights;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_FormRights;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_SignatureRights;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_AnnotationRights;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_DocumentRights;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_EmbeddedFileRights;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_FormExRights;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_FormRights;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_SignatureRights;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_AnnotationRights();

		virtual void set_AnnotationRights(TStringList &Value);

		virtual void set_AnnotationRights(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_AnnotationRights, set_AnnotationRights, TElPDFURProperties, AnnotationRights);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_AnnotationRights();

		virtual void set_AnnotationRights(TElStringList &Value);

		virtual void set_AnnotationRights(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_AnnotationRights, set_AnnotationRights, TElPDFURProperties, AnnotationRights);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_DocumentRights();

		virtual void set_DocumentRights(TStringList &Value);

		virtual void set_DocumentRights(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_DocumentRights, set_DocumentRights, TElPDFURProperties, DocumentRights);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_DocumentRights();

		virtual void set_DocumentRights(TElStringList &Value);

		virtual void set_DocumentRights(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_DocumentRights, set_DocumentRights, TElPDFURProperties, DocumentRights);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_EmbeddedFileRights();

		virtual void set_EmbeddedFileRights(TStringList &Value);

		virtual void set_EmbeddedFileRights(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_EmbeddedFileRights, set_EmbeddedFileRights, TElPDFURProperties, EmbeddedFileRights);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_EmbeddedFileRights();

		virtual void set_EmbeddedFileRights(TElStringList &Value);

		virtual void set_EmbeddedFileRights(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_EmbeddedFileRights, set_EmbeddedFileRights, TElPDFURProperties, EmbeddedFileRights);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_FormExRights();

		virtual void set_FormExRights(TStringList &Value);

		virtual void set_FormExRights(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_FormExRights, set_FormExRights, TElPDFURProperties, FormExRights);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_FormExRights();

		virtual void set_FormExRights(TElStringList &Value);

		virtual void set_FormExRights(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_FormExRights, set_FormExRights, TElPDFURProperties, FormExRights);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_FormRights();

		virtual void set_FormRights(TStringList &Value);

		virtual void set_FormRights(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_FormRights, set_FormRights, TElPDFURProperties, FormRights);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_FormRights();

		virtual void set_FormRights(TElStringList &Value);

		virtual void set_FormRights(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_FormRights, set_FormRights, TElPDFURProperties, FormRights);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_Message(std::string &OutResult);

		virtual void set_Message(const std::string &Value);

		virtual bool get_P();

		virtual void set_P(bool Value);

		SB_DECLARE_PROPERTY(bool, get_P, set_P, TElPDFURProperties, P);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_SignatureRights();

		virtual void set_SignatureRights(TStringList &Value);

		virtual void set_SignatureRights(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_SignatureRights, set_SignatureRights, TElPDFURProperties, SignatureRights);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_SignatureRights();

		virtual void set_SignatureRights(TElStringList &Value);

		virtual void set_SignatureRights(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_SignatureRights, set_SignatureRights, TElPDFURProperties, SignatureRights);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		TElPDFURProperties(TElPDFURPropertiesHandle handle, TElOwnHandle ownHandle);

		TElPDFURProperties();

		virtual ~TElPDFURProperties();

};
#endif /* SB_USE_CLASS_TELPDFURPROPERTIES */

#ifdef SB_USE_CLASS_TELPDFSIGREFENTRY
class TElPDFSigRefEntry: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFSigRefEntry)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_FieldMDPFields;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_FieldMDPFields;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELPDFURPROPERTIES
		TElPDFURProperties* _Inst_URProperties;
#endif /* SB_USE_CLASS_TELPDFURPROPERTIES */

		void initInstances();

	public:
		virtual bool get_Valid();

		SB_DECLARE_PROPERTY_GET(bool, get_Valid, TElPDFSigRefEntry, Valid);

		virtual int16_t get_DocMDPAccessPermissions();

		virtual void set_DocMDPAccessPermissions(int16_t Value);

		SB_DECLARE_PROPERTY(int16_t, get_DocMDPAccessPermissions, set_DocMDPAccessPermissions, TElPDFSigRefEntry, DocMDPAccessPermissions);

		virtual TSBPDFFieldMDPAction get_FieldMDPAction();

		virtual void set_FieldMDPAction(TSBPDFFieldMDPAction Value);

		SB_DECLARE_PROPERTY(TSBPDFFieldMDPAction, get_FieldMDPAction, set_FieldMDPAction, TElPDFSigRefEntry, FieldMDPAction);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_FieldMDPFields();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_FieldMDPFields, TElPDFSigRefEntry, FieldMDPFields);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_FieldMDPFields();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_FieldMDPFields, TElPDFSigRefEntry, FieldMDPFields);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual TSBPDFDigestMethod get_DigestMethod();

		virtual void set_DigestMethod(TSBPDFDigestMethod Value);

		SB_DECLARE_PROPERTY(TSBPDFDigestMethod, get_DigestMethod, set_DigestMethod, TElPDFSigRefEntry, DigestMethod);

		virtual TSBPDFTransformMethod get_TransformMethod();

		virtual void set_TransformMethod(TSBPDFTransformMethod Value);

		SB_DECLARE_PROPERTY(TSBPDFTransformMethod, get_TransformMethod, set_TransformMethod, TElPDFSigRefEntry, TransformMethod);

#ifdef SB_USE_CLASS_TELPDFURPROPERTIES
		virtual TElPDFURProperties* get_URProperties();

		SB_DECLARE_PROPERTY_GET(TElPDFURProperties*, get_URProperties, TElPDFSigRefEntry, URProperties);
#endif /* SB_USE_CLASS_TELPDFURPROPERTIES */

		TElPDFSigRefEntry(TElPDFSigRefEntryHandle handle, TElOwnHandle ownHandle);

		TElPDFSigRefEntry();

		virtual ~TElPDFSigRefEntry();

};
#endif /* SB_USE_CLASS_TELPDFSIGREFENTRY */

#ifdef SB_USE_CLASS_TELPDFSECURITYHANDLER
class TElPDFSecurityHandler: public TComponent
{
	private:
		SB_DISABLE_COPY(TElPDFSecurityHandler)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		void initInstances();

	public:
		virtual void Reset();

		static void GetName(std::string &OutResult);

		virtual void GetName_Inst(std::string &OutResult);

		static void GetDescription(std::string &OutResult);

		virtual void GetDescription_Inst(std::string &OutResult);

		static TClassHandle ClassType();

		virtual int32_t get_StreamEncryptionAlgorithm();

		virtual void set_StreamEncryptionAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_StreamEncryptionAlgorithm, set_StreamEncryptionAlgorithm, TElPDFSecurityHandler, StreamEncryptionAlgorithm);

		virtual int32_t get_StringEncryptionAlgorithm();

		virtual void set_StringEncryptionAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_StringEncryptionAlgorithm, set_StringEncryptionAlgorithm, TElPDFSecurityHandler, StringEncryptionAlgorithm);

		virtual int32_t get_StreamEncryptionKeyBits();

		virtual void set_StreamEncryptionKeyBits(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_StreamEncryptionKeyBits, set_StreamEncryptionKeyBits, TElPDFSecurityHandler, StreamEncryptionKeyBits);

		virtual int32_t get_StringEncryptionKeyBits();

		virtual void set_StringEncryptionKeyBits(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_StringEncryptionKeyBits, set_StringEncryptionKeyBits, TElPDFSecurityHandler, StringEncryptionKeyBits);

		virtual bool get_EncryptMetadata();

		virtual void set_EncryptMetadata(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EncryptMetadata, set_EncryptMetadata, TElPDFSecurityHandler, EncryptMetadata);

		virtual void get_CustomName(std::string &OutResult);

		virtual void set_CustomName(const std::string &Value);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElPDFSecurityHandler, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		TElPDFSecurityHandler(TElPDFSecurityHandlerHandle handle, TElOwnHandle ownHandle);

		explicit TElPDFSecurityHandler(TComponent &Owner);

		explicit TElPDFSecurityHandler(TComponent *Owner);

		virtual ~TElPDFSecurityHandler();

};
#endif /* SB_USE_CLASS_TELPDFSECURITYHANDLER */

#ifdef SB_USE_CLASS_TELPDFBYTERANGE
class TElPDFByteRange: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFByteRange)
	public:
		virtual int32_t get_StartOffset();

		virtual void set_StartOffset(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_StartOffset, set_StartOffset, TElPDFByteRange, StartOffset);

		virtual int32_t get_Count();

		virtual void set_Count(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Count, set_Count, TElPDFByteRange, Count);

		TElPDFByteRange(TElPDFByteRangeHandle handle, TElOwnHandle ownHandle);

		TElPDFByteRange();

};
#endif /* SB_USE_CLASS_TELPDFBYTERANGE */

#ifdef SB_USE_CLASS_TELPDFIMAGE
class TElPDFImage: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFImage)
		TElPDFImage* _Inst_MaskImage;

		void initInstances();

	public:
		int32_t AddMaskColorComponent(int32_t MinCC, int32_t MaxCC);

		void DeleteMaskColorComponent(int32_t Index);

		virtual TSBPDFImageType get_ImageType();

		virtual void set_ImageType(TSBPDFImageType Value);

		SB_DECLARE_PROPERTY(TSBPDFImageType, get_ImageType, set_ImageType, TElPDFImage, ImageType);

		virtual void get_Data(std::vector<uint8_t> &OutResult);

		virtual void set_Data(const std::vector<uint8_t> &Value);

		virtual int32_t get_Width();

		virtual void set_Width(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Width, set_Width, TElPDFImage, Width);

		virtual int32_t get_Height();

		virtual void set_Height(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Height, set_Height, TElPDFImage, Height);

		virtual TElPDFImage* get_MaskImage();

		SB_DECLARE_PROPERTY_GET(TElPDFImage*, get_MaskImage, TElPDFImage, MaskImage);

		virtual int32_t get_MaskColorComponentCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_MaskColorComponentCount, TElPDFImage, MaskColorComponentCount);

		virtual int32_t get_MaskColorComponentsMin(int32_t Index);

		virtual int32_t get_MaskColorComponentsMax(int32_t Index);

		virtual int32_t get_BitsPerComponent();

		virtual void set_BitsPerComponent(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_BitsPerComponent, set_BitsPerComponent, TElPDFImage, BitsPerComponent);

		virtual TSBPDFColorSpaceType get_ColorSpaceType();

		virtual void set_ColorSpaceType(TSBPDFColorSpaceType Value);

		SB_DECLARE_PROPERTY(TSBPDFColorSpaceType, get_ColorSpaceType, set_ColorSpaceType, TElPDFImage, ColorSpaceType);

		virtual bool get_Interpolate();

		virtual void set_Interpolate(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Interpolate, set_Interpolate, TElPDFImage, Interpolate);

		virtual void get_ResourceName(std::string &OutResult);

		virtual void set_ResourceName(const std::string &Value);

		TElPDFImage(TElPDFImageHandle handle, TElOwnHandle ownHandle);

		TElPDFImage();

		virtual ~TElPDFImage();

};
#endif /* SB_USE_CLASS_TELPDFIMAGE */

#ifdef SB_USE_CLASS_TELPDFCUSTOMFONTOBJECT
class TElPDFCustomFontObject: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFCustomFontObject)
	public:
		TElPDFCustomFontObject(TElPDFCustomFontObjectHandle handle, TElOwnHandle ownHandle);

		TElPDFCustomFontObject();

};
#endif /* SB_USE_CLASS_TELPDFCUSTOMFONTOBJECT */

#ifdef SB_USE_CLASS_TELPDFENCODING
class TElPDFEncoding: public TElPDFCustomFontObject
{
	private:
		SB_DISABLE_COPY(TElPDFEncoding)
	public:
		virtual void get_BaseEncoding(std::string &OutResult);

		virtual void set_BaseEncoding(const std::string &Value);

		virtual void get_Differences(int32_t Index, std::string &OutResult);

		virtual void set_Differences(int32_t Index, const std::string &Name);

		TElPDFEncoding(TElPDFEncodingHandle handle, TElOwnHandle ownHandle);

		TElPDFEncoding();

};
#endif /* SB_USE_CLASS_TELPDFENCODING */

#ifdef SB_USE_CLASS_TELPDFFONTDESCRIPTOR
class TElPDFFontDescriptor: public TElPDFCustomFontObject
{
	private:
		SB_DISABLE_COPY(TElPDFFontDescriptor)
	public:
		virtual void get_FontName(std::string &OutResult);

		virtual void set_FontName(const std::string &Value);

		virtual void get_FontFamily(std::string &OutResult);

		virtual void set_FontFamily(const std::string &Value);

		virtual void get_FontStretch(std::string &OutResult);

		virtual void set_FontStretch(const std::string &Value);

		virtual int32_t get_FontWeight();

		virtual void set_FontWeight(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_FontWeight, set_FontWeight, TElPDFFontDescriptor, FontWeight);

		virtual int32_t get_Flags();

		virtual void set_Flags(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Flags, set_Flags, TElPDFFontDescriptor, Flags);

		virtual int32_t get_FontBBoxX1();

		virtual void set_FontBBoxX1(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_FontBBoxX1, set_FontBBoxX1, TElPDFFontDescriptor, FontBBoxX1);

		virtual int32_t get_FontBBoxX2();

		virtual void set_FontBBoxX2(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_FontBBoxX2, set_FontBBoxX2, TElPDFFontDescriptor, FontBBoxX2);

		virtual int32_t get_FontBBoxY1();

		virtual void set_FontBBoxY1(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_FontBBoxY1, set_FontBBoxY1, TElPDFFontDescriptor, FontBBoxY1);

		virtual int32_t get_FontBBoxY2();

		virtual void set_FontBBoxY2(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_FontBBoxY2, set_FontBBoxY2, TElPDFFontDescriptor, FontBBoxY2);

		virtual double get_ItalicAngle();

		virtual void set_ItalicAngle(double Value);

		SB_DECLARE_PROPERTY(double, get_ItalicAngle, set_ItalicAngle, TElPDFFontDescriptor, ItalicAngle);

		virtual int32_t get_Ascent();

		virtual void set_Ascent(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Ascent, set_Ascent, TElPDFFontDescriptor, Ascent);

		virtual int32_t get_Descent();

		virtual void set_Descent(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Descent, set_Descent, TElPDFFontDescriptor, Descent);

		virtual int32_t get_Leading();

		virtual void set_Leading(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Leading, set_Leading, TElPDFFontDescriptor, Leading);

		virtual int32_t get_CapHeight();

		virtual void set_CapHeight(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CapHeight, set_CapHeight, TElPDFFontDescriptor, CapHeight);

		virtual int32_t get_XHeight();

		virtual void set_XHeight(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_XHeight, set_XHeight, TElPDFFontDescriptor, XHeight);

		virtual int32_t get_StemV();

		virtual void set_StemV(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_StemV, set_StemV, TElPDFFontDescriptor, StemV);

		virtual int32_t get_StemH();

		virtual void set_StemH(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_StemH, set_StemH, TElPDFFontDescriptor, StemH);

		virtual int32_t get_AvgWidth();

		virtual void set_AvgWidth(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AvgWidth, set_AvgWidth, TElPDFFontDescriptor, AvgWidth);

		virtual int32_t get_MaxWidth();

		virtual void set_MaxWidth(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxWidth, set_MaxWidth, TElPDFFontDescriptor, MaxWidth);

		virtual int32_t get_MissingWidth();

		virtual void set_MissingWidth(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MissingWidth, set_MissingWidth, TElPDFFontDescriptor, MissingWidth);

		virtual void get_FontFile(std::vector<uint8_t> &OutResult);

		virtual void set_FontFile(const std::vector<uint8_t> &Value);

		virtual void get_FontFile2(std::vector<uint8_t> &OutResult);

		virtual void set_FontFile2(const std::vector<uint8_t> &Value);

		virtual void get_FontFile3(std::vector<uint8_t> &OutResult);

		virtual void set_FontFile3(const std::vector<uint8_t> &Value);

		virtual void get_CharSet(std::string &OutResult);

		virtual void set_CharSet(const std::string &Value);

		TElPDFFontDescriptor(TElPDFFontDescriptorHandle handle, TElOwnHandle ownHandle);

		TElPDFFontDescriptor();

};
#endif /* SB_USE_CLASS_TELPDFFONTDESCRIPTOR */

#ifdef SB_USE_CLASS_TELPDFCIDFONTDESCRIPTOR
class TElPDFCIDFontDescriptor: public TElPDFFontDescriptor
{
	private:
		SB_DISABLE_COPY(TElPDFCIDFontDescriptor)
	public:
		virtual void get_Lang(std::string &OutResult);

		virtual void set_Lang(const std::string &Value);

		virtual void get_CIDSet(std::vector<uint8_t> &OutResult);

		virtual void set_CIDSet(const std::vector<uint8_t> &Value);

		TElPDFCIDFontDescriptor(TElPDFCIDFontDescriptorHandle handle, TElOwnHandle ownHandle);

		TElPDFCIDFontDescriptor();

};
#endif /* SB_USE_CLASS_TELPDFCIDFONTDESCRIPTOR */

#ifdef SB_USE_CLASS_TELPDFCIDSYSTEMINFO
class TElPDFCIDSystemInfo: public TElPDFCustomFontObject
{
	private:
		SB_DISABLE_COPY(TElPDFCIDSystemInfo)
	public:
		virtual void get_Registry(std::string &OutResult);

		virtual void set_Registry(const std::string &Value);

		virtual void get_Ordering(std::string &OutResult);

		virtual void set_Ordering(const std::string &Value);

		virtual int32_t get_Supplement();

		virtual void set_Supplement(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Supplement, set_Supplement, TElPDFCIDSystemInfo, Supplement);

		TElPDFCIDSystemInfo(TElPDFCIDSystemInfoHandle handle, TElOwnHandle ownHandle);

		TElPDFCIDSystemInfo();

};
#endif /* SB_USE_CLASS_TELPDFCIDSYSTEMINFO */

#ifdef SB_USE_CLASS_TELPDFCUSTOMFONT
class TElPDFCustomFont: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFCustomFont)
	public:
		virtual void get_Subtype(std::string &OutResult);

		virtual void set_Subtype(const std::string &Value);

		virtual void get_BaseFont(std::string &OutResult);

		virtual void set_BaseFont(const std::string &Value);

		virtual void get_ResourceName(std::string &OutResult);

		virtual void set_ResourceName(const std::string &Value);

		virtual void get_ToUnicode(std::vector<uint8_t> &OutResult);

		virtual void set_ToUnicode(const std::vector<uint8_t> &Value);

		TElPDFCustomFont(TElPDFCustomFontHandle handle, TElOwnHandle ownHandle);

		TElPDFCustomFont();

};
#endif /* SB_USE_CLASS_TELPDFCUSTOMFONT */

#ifdef SB_USE_CLASS_TELPDFSIMPLEFONT
class TElPDFSimpleFont: public TElPDFCustomFont
{
	private:
		SB_DISABLE_COPY(TElPDFSimpleFont)
#ifdef SB_USE_CLASS_TELPDFENCODING
		TElPDFEncoding* _Inst_EncodingObject;
#endif /* SB_USE_CLASS_TELPDFENCODING */
#ifdef SB_USE_CLASS_TELPDFFONTDESCRIPTOR
		TElPDFFontDescriptor* _Inst_FontDescriptor;
#endif /* SB_USE_CLASS_TELPDFFONTDESCRIPTOR */

		void initInstances();

	public:
		virtual void get_Encoding(std::string &OutResult);

		virtual void set_Encoding(const std::string &Value);

#ifdef SB_USE_CLASS_TELPDFENCODING
		virtual TElPDFEncoding* get_EncodingObject();

		virtual void set_EncodingObject(TElPDFEncoding &Value);

		virtual void set_EncodingObject(TElPDFEncoding *Value);

		SB_DECLARE_PROPERTY(TElPDFEncoding*, get_EncodingObject, set_EncodingObject, TElPDFSimpleFont, EncodingObject);
#endif /* SB_USE_CLASS_TELPDFENCODING */

#ifdef SB_USE_CLASS_TELPDFFONTDESCRIPTOR
		virtual TElPDFFontDescriptor* get_FontDescriptor();

		virtual void set_FontDescriptor(TElPDFFontDescriptor &Value);

		virtual void set_FontDescriptor(TElPDFFontDescriptor *Value);

		SB_DECLARE_PROPERTY(TElPDFFontDescriptor*, get_FontDescriptor, set_FontDescriptor, TElPDFSimpleFont, FontDescriptor);
#endif /* SB_USE_CLASS_TELPDFFONTDESCRIPTOR */

		virtual void get_FontName(std::string &OutResult);

		virtual void set_FontName(const std::string &Value);

		virtual int32_t get_FirstChar();

		virtual void set_FirstChar(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_FirstChar, set_FirstChar, TElPDFSimpleFont, FirstChar);

		virtual int32_t get_LastChar();

		virtual void set_LastChar(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_LastChar, set_LastChar, TElPDFSimpleFont, LastChar);

		virtual void get_Widths(std::vector<int32_t> &OutResult);

		virtual void set_Widths(const std::vector<int32_t> &Value);

		TElPDFSimpleFont(TElPDFSimpleFontHandle handle, TElOwnHandle ownHandle);

		TElPDFSimpleFont();

		virtual ~TElPDFSimpleFont();

};
#endif /* SB_USE_CLASS_TELPDFSIMPLEFONT */

#ifdef SB_USE_CLASS_TELPDFCOMPOSITEFONT
class TElPDFCompositeFont: public TElPDFCustomFont
{
	private:
		SB_DISABLE_COPY(TElPDFCompositeFont)
		TElPDFCustomFont* _Inst_DescendantFonts;

		void initInstances();

	public:
		virtual TElPDFCustomFont* get_DescendantFonts();

		virtual void set_DescendantFonts(TElPDFCustomFont &Value);

		virtual void set_DescendantFonts(TElPDFCustomFont *Value);

		SB_DECLARE_PROPERTY(TElPDFCustomFont*, get_DescendantFonts, set_DescendantFonts, TElPDFCompositeFont, DescendantFonts);

		virtual void get_Encoding(std::string &OutResult);

		virtual void set_Encoding(const std::string &Value);

		virtual void get_EncodingData(std::vector<uint8_t> &OutResult);

		virtual void set_EncodingData(const std::vector<uint8_t> &Value);

		TElPDFCompositeFont(TElPDFCompositeFontHandle handle, TElOwnHandle ownHandle);

		TElPDFCompositeFont();

		virtual ~TElPDFCompositeFont();

};
#endif /* SB_USE_CLASS_TELPDFCOMPOSITEFONT */

#ifdef SB_USE_CLASS_TELPDFMETRICW
class TElPDFMetricW: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFMetricW)
	public:
		void Add(int32_t CID, int32_t Width);

		void AddRange(int32_t First, int32_t Last, int32_t Width);

		TElPDFMetricW(TElPDFMetricWHandle handle, TElOwnHandle ownHandle);

		TElPDFMetricW();

};
#endif /* SB_USE_CLASS_TELPDFMETRICW */

#ifdef SB_USE_CLASS_TELPDFMETRICW2
class TElPDFMetricW2: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFMetricW2)
	public:
		void Add(int32_t CID, int32_t Width, int32_t VX, int32_t VY);

		void AddRange(int32_t First, int32_t Last, int32_t Width, int32_t VX, int32_t VY);

		TElPDFMetricW2(TElPDFMetricW2Handle handle, TElOwnHandle ownHandle);

		TElPDFMetricW2();

};
#endif /* SB_USE_CLASS_TELPDFMETRICW2 */

#ifdef SB_USE_CLASS_TELPDFCIDFONT
class TElPDFCIDFont: public TElPDFCustomFont
{
	private:
		SB_DISABLE_COPY(TElPDFCIDFont)
#ifdef SB_USE_CLASS_TELPDFCIDSYSTEMINFO
		TElPDFCIDSystemInfo* _Inst_CIDSystemInfo;
#endif /* SB_USE_CLASS_TELPDFCIDSYSTEMINFO */
#ifdef SB_USE_CLASS_TELPDFCIDFONTDESCRIPTOR
		TElPDFCIDFontDescriptor* _Inst_FontDescriptor;
#endif /* SB_USE_CLASS_TELPDFCIDFONTDESCRIPTOR */
#ifdef SB_USE_CLASS_TELPDFMETRICW
		TElPDFMetricW* _Inst_W;
#endif /* SB_USE_CLASS_TELPDFMETRICW */
#ifdef SB_USE_CLASS_TELPDFMETRICW2
		TElPDFMetricW2* _Inst_W2;
#endif /* SB_USE_CLASS_TELPDFMETRICW2 */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELPDFCIDSYSTEMINFO
		virtual TElPDFCIDSystemInfo* get_CIDSystemInfo();

		virtual void set_CIDSystemInfo(TElPDFCIDSystemInfo &Value);

		virtual void set_CIDSystemInfo(TElPDFCIDSystemInfo *Value);

		SB_DECLARE_PROPERTY(TElPDFCIDSystemInfo*, get_CIDSystemInfo, set_CIDSystemInfo, TElPDFCIDFont, CIDSystemInfo);
#endif /* SB_USE_CLASS_TELPDFCIDSYSTEMINFO */

#ifdef SB_USE_CLASS_TELPDFCIDFONTDESCRIPTOR
		virtual TElPDFCIDFontDescriptor* get_FontDescriptor();

		virtual void set_FontDescriptor(TElPDFCIDFontDescriptor &Value);

		virtual void set_FontDescriptor(TElPDFCIDFontDescriptor *Value);

		SB_DECLARE_PROPERTY(TElPDFCIDFontDescriptor*, get_FontDescriptor, set_FontDescriptor, TElPDFCIDFont, FontDescriptor);
#endif /* SB_USE_CLASS_TELPDFCIDFONTDESCRIPTOR */

		virtual int32_t get_DW();

		virtual void set_DW(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DW, set_DW, TElPDFCIDFont, DW);

#ifdef SB_USE_CLASS_TELPDFMETRICW
		virtual TElPDFMetricW* get_W();

		SB_DECLARE_PROPERTY_GET(TElPDFMetricW*, get_W, TElPDFCIDFont, W);
#endif /* SB_USE_CLASS_TELPDFMETRICW */

		virtual void get_DW2(std::vector<int32_t> &OutResult);

		virtual void set_DW2(const std::vector<int32_t> &Value);

#ifdef SB_USE_CLASS_TELPDFMETRICW2
		virtual TElPDFMetricW2* get_W2();

		virtual void set_W2(TElPDFMetricW2 &Value);

		virtual void set_W2(TElPDFMetricW2 *Value);

		SB_DECLARE_PROPERTY(TElPDFMetricW2*, get_W2, set_W2, TElPDFCIDFont, W2);
#endif /* SB_USE_CLASS_TELPDFMETRICW2 */

		virtual void get_CIDToGIDMap(std::string &OutResult);

		virtual void set_CIDToGIDMap(const std::string &Value);

		virtual void get_CIDToGIDMapData(std::vector<uint8_t> &OutResult);

		virtual void set_CIDToGIDMapData(const std::vector<uint8_t> &Value);

		TElPDFCIDFont(TElPDFCIDFontHandle handle, TElOwnHandle ownHandle);

		TElPDFCIDFont();

		virtual ~TElPDFCIDFont();

};
#endif /* SB_USE_CLASS_TELPDFCIDFONT */

#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXT
class TElPDFSignatureWidgetText: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFSignatureWidgetText)
	public:
		virtual void get_Text(std::string &OutResult);

		virtual void set_Text(const std::string &Value);

		virtual double get_FontSizeX();

		virtual void set_FontSizeX(double Value);

		SB_DECLARE_PROPERTY(double, get_FontSizeX, set_FontSizeX, TElPDFSignatureWidgetText, FontSizeX);

		virtual double get_FontSizeY();

		virtual void set_FontSizeY(double Value);

		SB_DECLARE_PROPERTY(double, get_FontSizeY, set_FontSizeY, TElPDFSignatureWidgetText, FontSizeY);

		virtual double get_X();

		virtual void set_X(double Value);

		SB_DECLARE_PROPERTY(double, get_X, set_X, TElPDFSignatureWidgetText, X);

		virtual double get_Y();

		virtual void set_Y(double Value);

		SB_DECLARE_PROPERTY(double, get_Y, set_Y, TElPDFSignatureWidgetText, Y);

		virtual void get_FontResourceName(std::string &OutResult);

		virtual void set_FontResourceName(const std::string &Value);

		virtual void get_CustomData(std::string &OutResult);

		virtual void set_CustomData(const std::string &Value);

		TElPDFSignatureWidgetText(TElPDFSignatureWidgetTextHandle handle, TElOwnHandle ownHandle);

		TElPDFSignatureWidgetText();

};
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXT */

#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXTLIST
class TElPDFSignatureWidgetTextList: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFSignatureWidgetTextList)
#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXT
		TElPDFSignatureWidgetText* _Inst_TextData;
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXT */

		void initInstances();

	public:
		int32_t Add(const std::string &Text, double X, double Y, double FontSize);

		int32_t Add(const std::string &Text, double X, double Y, double FontSizeX, double FontSizeY);

#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXT
		int32_t Add(TElPDFSignatureWidgetText &ATextData);

		int32_t Add(TElPDFSignatureWidgetText *ATextData);
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXT */

		int32_t Add();

		void Delete(int32_t Index);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElPDFSignatureWidgetTextList, Count);

#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXT
		virtual TElPDFSignatureWidgetText* get_TextData(int32_t Index);
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXT */

		TElPDFSignatureWidgetTextList(TElPDFSignatureWidgetTextListHandle handle, TElOwnHandle ownHandle);

		TElPDFSignatureWidgetTextList();

		virtual ~TElPDFSignatureWidgetTextList();

};
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXTLIST */

#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETPROPS
class TElPDFSignatureWidgetProps: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFSignatureWidgetProps)
#ifdef SB_USE_CLASS_TELPDFIMAGE
		TElPDFImage* _Inst_Background;
#endif /* SB_USE_CLASS_TELPDFIMAGE */
#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXTLIST
		TElPDFSignatureWidgetTextList* _Inst_CustomText;
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXTLIST */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELPDFCUSTOMFONT
		void AddFont(TElPDFCustomFont &Font);

		void AddFont(TElPDFCustomFont *Font);
#endif /* SB_USE_CLASS_TELPDFCUSTOMFONT */

#ifdef SB_USE_CLASS_TELPDFCUSTOMFONTOBJECT
		void AddFontObject(TElPDFCustomFontObject &FontObject);

		void AddFontObject(TElPDFCustomFontObject *FontObject);
#endif /* SB_USE_CLASS_TELPDFCUSTOMFONTOBJECT */

#ifdef SB_USE_CLASS_TELPDFIMAGE
		void AddImage(TElPDFImage &Image);

		void AddImage(TElPDFImage *Image);
#endif /* SB_USE_CLASS_TELPDFIMAGE */

#ifdef SB_USE_CLASS_TELPDFIMAGE
		void AddImage(TElPDFImage &Image, double X, double Y, double SizeX, double SizeY);

		void AddImage(TElPDFImage *Image, double X, double Y, double SizeX, double SizeY);
#endif /* SB_USE_CLASS_TELPDFIMAGE */

		void ClearFonts();

		void ClearFontObjects();

		void ClearImages();

		virtual void get_AlgorithmInfo(std::string &OutResult);

		virtual void set_AlgorithmInfo(const std::string &Value);

		virtual bool get_AutoAdjustEncoding();

		virtual void set_AutoAdjustEncoding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoAdjustEncoding, set_AutoAdjustEncoding, TElPDFSignatureWidgetProps, AutoAdjustEncoding);

		virtual bool get_AutoText();

		virtual void set_AutoText(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoText, set_AutoText, TElPDFSignatureWidgetProps, AutoText);

		virtual bool get_AutoFontSize();

		virtual void set_AutoFontSize(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoFontSize, set_AutoFontSize, TElPDFSignatureWidgetProps, AutoFontSize);

		virtual bool get_AutoSize();

		virtual void set_AutoSize(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoSize, set_AutoSize, TElPDFSignatureWidgetProps, AutoSize);

		virtual bool get_AutoPos();

		virtual void set_AutoPos(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoPos, set_AutoPos, TElPDFSignatureWidgetProps, AutoPos);

		virtual bool get_AutoStretchBackground();

		virtual void set_AutoStretchBackground(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoStretchBackground, set_AutoStretchBackground, TElPDFSignatureWidgetProps, AutoStretchBackground);

		virtual void get_Header(std::string &OutResult);

		virtual void set_Header(const std::string &Value);

		virtual int32_t get_Height();

		virtual void set_Height(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Height, set_Height, TElPDFSignatureWidgetProps, Height);

		virtual bool get_Locked();

		virtual void set_Locked(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Locked, set_Locked, TElPDFSignatureWidgetProps, Locked);

		virtual bool get_LockedContents();

		virtual void set_LockedContents(bool Value);

		SB_DECLARE_PROPERTY(bool, get_LockedContents, set_LockedContents, TElPDFSignatureWidgetProps, LockedContents);

		virtual bool get_NoRotate();

		virtual void set_NoRotate(bool Value);

		SB_DECLARE_PROPERTY(bool, get_NoRotate, set_NoRotate, TElPDFSignatureWidgetProps, NoRotate);

		virtual bool get_NoView();

		virtual void set_NoView(bool Value);

		SB_DECLARE_PROPERTY(bool, get_NoView, set_NoView, TElPDFSignatureWidgetProps, NoView);

		virtual bool get_NoZoom();

		virtual void set_NoZoom(bool Value);

		SB_DECLARE_PROPERTY(bool, get_NoZoom, set_NoZoom, TElPDFSignatureWidgetProps, NoZoom);

		virtual bool get_Print();

		virtual void set_Print(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Print, set_Print, TElPDFSignatureWidgetProps, Print);

		virtual bool get_ReadOnly();

		virtual void set_ReadOnly(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ReadOnly, set_ReadOnly, TElPDFSignatureWidgetProps, ReadOnly);

		virtual bool get_ToggleNoView();

		virtual void set_ToggleNoView(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ToggleNoView, set_ToggleNoView, TElPDFSignatureWidgetProps, ToggleNoView);

		virtual bool get_ShowTimestamp();

		virtual void set_ShowTimestamp(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ShowTimestamp, set_ShowTimestamp, TElPDFSignatureWidgetProps, ShowTimestamp);

		virtual void get_SignerInfo(std::string &OutResult);

		virtual void set_SignerInfo(const std::string &Value);

		virtual int32_t get_Width();

		virtual void set_Width(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Width, set_Width, TElPDFSignatureWidgetProps, Width);

		virtual int32_t get_OffsetX();

		virtual void set_OffsetX(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_OffsetX, set_OffsetX, TElPDFSignatureWidgetProps, OffsetX);

		virtual int32_t get_OffsetY();

		virtual void set_OffsetY(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_OffsetY, set_OffsetY, TElPDFSignatureWidgetProps, OffsetY);

		virtual double get_TitleFontSize();

		virtual void set_TitleFontSize(double Value);

		SB_DECLARE_PROPERTY(double, get_TitleFontSize, set_TitleFontSize, TElPDFSignatureWidgetProps, TitleFontSize);

		virtual double get_TimestampFontSize();

		virtual void set_TimestampFontSize(double Value);

		SB_DECLARE_PROPERTY(double, get_TimestampFontSize, set_TimestampFontSize, TElPDFSignatureWidgetProps, TimestampFontSize);

		virtual double get_SectionTitleFontSize();

		virtual void set_SectionTitleFontSize(double Value);

		SB_DECLARE_PROPERTY(double, get_SectionTitleFontSize, set_SectionTitleFontSize, TElPDFSignatureWidgetProps, SectionTitleFontSize);

		virtual double get_SectionTextFontSize();

		virtual void set_SectionTextFontSize(double Value);

		SB_DECLARE_PROPERTY(double, get_SectionTextFontSize, set_SectionTextFontSize, TElPDFSignatureWidgetProps, SectionTextFontSize);

#ifdef SB_USE_CLASS_TELPDFIMAGE
		virtual TElPDFImage* get_Background();

		SB_DECLARE_PROPERTY_GET(TElPDFImage*, get_Background, TElPDFSignatureWidgetProps, Background);
#endif /* SB_USE_CLASS_TELPDFIMAGE */

		virtual TSBPDFWidgetBackgroundStyle get_BackgroundStyle();

		virtual void set_BackgroundStyle(TSBPDFWidgetBackgroundStyle Value);

		SB_DECLARE_PROPERTY(TSBPDFWidgetBackgroundStyle, get_BackgroundStyle, set_BackgroundStyle, TElPDFSignatureWidgetProps, BackgroundStyle);

		virtual double get_StretchX();

		virtual void set_StretchX(double Value);

		SB_DECLARE_PROPERTY(double, get_StretchX, set_StretchX, TElPDFSignatureWidgetProps, StretchX);

		virtual double get_StretchY();

		virtual void set_StretchY(double Value);

		SB_DECLARE_PROPERTY(double, get_StretchY, set_StretchY, TElPDFSignatureWidgetProps, StretchY);

		virtual int32_t get_Rotate();

		virtual void set_Rotate(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Rotate, set_Rotate, TElPDFSignatureWidgetProps, Rotate);

		virtual void get_SignerCaption(std::string &OutResult);

		virtual void set_SignerCaption(const std::string &Value);

		virtual void get_AlgorithmCaption(std::string &OutResult);

		virtual void set_AlgorithmCaption(const std::string &Value);

		virtual void get_DateCaptionFormat(std::string &OutResult);

		virtual void set_DateCaptionFormat(const std::string &Value);

		virtual void get_CustomAppearance(std::vector<uint8_t> &OutResult);

		virtual void set_CustomAppearance(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXTLIST
		virtual TElPDFSignatureWidgetTextList* get_CustomText();

		SB_DECLARE_PROPERTY_GET(TElPDFSignatureWidgetTextList*, get_CustomText, TElPDFSignatureWidgetProps, CustomText);
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETTEXTLIST */

		virtual bool get_HideDefaultText();

		virtual void set_HideDefaultText(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HideDefaultText, set_HideDefaultText, TElPDFSignatureWidgetProps, HideDefaultText);

		virtual bool get_CompressWidgetData();

		virtual void set_CompressWidgetData(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CompressWidgetData, set_CompressWidgetData, TElPDFSignatureWidgetProps, CompressWidgetData);

		virtual void get_CustomBackgroundContentStream(std::string &OutResult);

		virtual void set_CustomBackgroundContentStream(const std::string &Value);

		virtual bool get_ShowVisualStatus();

		virtual void set_ShowVisualStatus(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ShowVisualStatus, set_ShowVisualStatus, TElPDFSignatureWidgetProps, ShowVisualStatus);

		virtual void get_CustomVisualStatusMatrix(std::string &OutResult);

		virtual void set_CustomVisualStatusMatrix(const std::string &Value);

		virtual int64_t get_SigningTime();

		virtual void set_SigningTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_SigningTime, set_SigningTime, TElPDFSignatureWidgetProps, SigningTime);

		virtual bool get_IgnoreExistingAppearance();

		virtual void set_IgnoreExistingAppearance(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreExistingAppearance, set_IgnoreExistingAppearance, TElPDFSignatureWidgetProps, IgnoreExistingAppearance);

		virtual bool get_ShowOnAllPages();

		virtual void set_ShowOnAllPages(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ShowOnAllPages, set_ShowOnAllPages, TElPDFSignatureWidgetProps, ShowOnAllPages);

		virtual bool get_SaveStringsInUnicodeEncoding();

		virtual void set_SaveStringsInUnicodeEncoding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SaveStringsInUnicodeEncoding, set_SaveStringsInUnicodeEncoding, TElPDFSignatureWidgetProps, SaveStringsInUnicodeEncoding);

		virtual void get_OnConvertStringToAnsi(TSBPDFConvertStringToAnsiEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnConvertStringToAnsi(TSBPDFConvertStringToAnsiEvent pMethodValue, void * pDataValue);

		virtual void get_OnLookupGlyphName(TSBPDFLookupGlyphNameEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnLookupGlyphName(TSBPDFLookupGlyphNameEvent pMethodValue, void * pDataValue);

		virtual void get_OnLookupGlyphWidth(TSBPDFLookupGlyphWidthEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnLookupGlyphWidth(TSBPDFLookupGlyphWidthEvent pMethodValue, void * pDataValue);

		TElPDFSignatureWidgetProps(TElPDFSignatureWidgetPropsHandle handle, TElOwnHandle ownHandle);

		TElPDFSignatureWidgetProps();

		virtual ~TElPDFSignatureWidgetProps();

};
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETPROPS */

#ifdef SB_USE_CLASS_TELPDFSIGNATURE
class TElPDFSignature: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFSignature)
#ifdef SB_USE_CLASS_TELPDFSECURITYHANDLER
		TElPDFSecurityHandler* _Inst_Handler;
#endif /* SB_USE_CLASS_TELPDFSECURITYHANDLER */
#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETPROPS
		TElPDFSignatureWidgetProps* _Inst_WidgetProps;
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETPROPS */
#ifdef SB_USE_CLASS_TELPDFOBJECT
		TElPDFObject* _Inst_ExplicitElement;
#endif /* SB_USE_CLASS_TELPDFOBJECT */
#ifdef SB_USE_CLASS_TELPDFOBJECT
		TElPDFObject* _Inst_PDFObject;
#endif /* SB_USE_CLASS_TELPDFOBJECT */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_LockFields;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_LockFields;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		bool Validate();

		bool Validate(bool MDPLiberalMode);

#ifdef SB_USE_CLASS_TSTREAM
		void GetSignedVersion(TStream &Stream);

		void GetSignedVersion(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		bool IsDocumentSigned();

		void Update();

		void Timestamp();

		virtual TSBPDFSignatureType get_SignatureType();

		virtual void set_SignatureType(TSBPDFSignatureType Value);

		SB_DECLARE_PROPERTY(TSBPDFSignatureType, get_SignatureType, set_SignatureType, TElPDFSignature, SignatureType);

		virtual TSBPDFSignatureAllowedChanges get_AllowedChanges();

		virtual void set_AllowedChanges(TSBPDFSignatureAllowedChanges Value);

		SB_DECLARE_PROPERTY(TSBPDFSignatureAllowedChanges, get_AllowedChanges, set_AllowedChanges, TElPDFSignature, AllowedChanges);

#ifdef SB_USE_CLASS_TELPDFSECURITYHANDLER
		virtual TElPDFSecurityHandler* get_Handler();

		virtual void set_Handler(TElPDFSecurityHandler &Value);

		virtual void set_Handler(TElPDFSecurityHandler *Value);

		SB_DECLARE_PROPERTY(TElPDFSecurityHandler*, get_Handler, set_Handler, TElPDFSignature, Handler);
#endif /* SB_USE_CLASS_TELPDFSECURITYHANDLER */

		virtual void get_SignatureName(std::string &OutResult);

		virtual void set_SignatureName(const std::string &Value);

		virtual void get_AuthorName(std::string &OutResult);

		virtual void set_AuthorName(const std::string &Value);

		virtual void get_ContactInfo(std::string &OutResult);

		virtual void set_ContactInfo(const std::string &Value);

		virtual void get_Location(std::string &OutResult);

		virtual void set_Location(const std::string &Value);

		virtual void get_Reason(std::string &OutResult);

		virtual void set_Reason(const std::string &Value);

		virtual int64_t get_SigningTime();

		virtual void set_SigningTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_SigningTime, set_SigningTime, TElPDFSignature, SigningTime);

#ifdef SB_USE_CLASS_TELPDFSIGNATUREWIDGETPROPS
		virtual TElPDFSignatureWidgetProps* get_WidgetProps();

		SB_DECLARE_PROPERTY_GET(TElPDFSignatureWidgetProps*, get_WidgetProps, TElPDFSignature, WidgetProps);
#endif /* SB_USE_CLASS_TELPDFSIGNATUREWIDGETPROPS */

		virtual bool get_Invisible();

		virtual void set_Invisible(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Invisible, set_Invisible, TElPDFSignature, Invisible);

		virtual int32_t get_Page();

		virtual void set_Page(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Page, set_Page, TElPDFSignature, Page);

		virtual bool get_UseHexEncoding();

		virtual void set_UseHexEncoding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseHexEncoding, set_UseHexEncoding, TElPDFSignature, UseHexEncoding);

		virtual TSBPDFDigestMethod get_MDPHashAlgorithm();

		virtual void set_MDPHashAlgorithm(TSBPDFDigestMethod Value);

		SB_DECLARE_PROPERTY(TSBPDFDigestMethod, get_MDPHashAlgorithm, set_MDPHashAlgorithm, TElPDFSignature, MDPHashAlgorithm);

		virtual bool get_DisableDocMDPTransformDigestValue();

		virtual void set_DisableDocMDPTransformDigestValue(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DisableDocMDPTransformDigestValue, set_DisableDocMDPTransformDigestValue, TElPDFSignature, DisableDocMDPTransformDigestValue);

		virtual bool get_DisableFieldMDPTransformDigestValue();

		virtual void set_DisableFieldMDPTransformDigestValue(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DisableFieldMDPTransformDigestValue, set_DisableFieldMDPTransformDigestValue, TElPDFSignature, DisableFieldMDPTransformDigestValue);

		virtual int32_t get_ExtraSpace();

		virtual void set_ExtraSpace(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ExtraSpace, set_ExtraSpace, TElPDFSignature, ExtraSpace);

		virtual bool get_EmptyField();

		virtual void set_EmptyField(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EmptyField, set_EmptyField, TElPDFSignature, EmptyField);

		virtual bool get_ExplicitElementSignature();

		virtual void set_ExplicitElementSignature(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ExplicitElementSignature, set_ExplicitElementSignature, TElPDFSignature, ExplicitElementSignature);

#ifdef SB_USE_CLASS_TELPDFOBJECT
		virtual TElPDFObject* get_ExplicitElement();

		virtual void set_ExplicitElement(TElPDFObject &Value);

		virtual void set_ExplicitElement(TElPDFObject *Value);

		SB_DECLARE_PROPERTY(TElPDFObject*, get_ExplicitElement, set_ExplicitElement, TElPDFSignature, ExplicitElement);
#endif /* SB_USE_CLASS_TELPDFOBJECT */

		virtual void get_CustomData(std::vector<uint8_t> &OutResult);

		virtual void set_CustomData(const std::vector<uint8_t> &Value);

		virtual TPDFStringEncoding get_CustomDataEncoding();

		virtual void set_CustomDataEncoding(TPDFStringEncoding Value);

		SB_DECLARE_PROPERTY(TPDFStringEncoding, get_CustomDataEncoding, set_CustomDataEncoding, TElPDFSignature, CustomDataEncoding);

		virtual TSBPDFSignatureOptions get_Options();

		virtual void set_Options(TSBPDFSignatureOptions Value);

		SB_DECLARE_PROPERTY(TSBPDFSignatureOptions, get_Options, set_Options, TElPDFSignature, Options);

#ifdef SB_USE_CLASS_TELPDFOBJECT
		virtual TElPDFObject* get_PDFObject();

		SB_DECLARE_PROPERTY_GET(TElPDFObject*, get_PDFObject, TElPDFSignature, PDFObject);
#endif /* SB_USE_CLASS_TELPDFOBJECT */

		virtual TSBPDFFieldMDPAction get_LockAction();

		virtual void set_LockAction(TSBPDFFieldMDPAction Value);

		SB_DECLARE_PROPERTY(TSBPDFFieldMDPAction, get_LockAction, set_LockAction, TElPDFSignature, LockAction);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_LockFields();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_LockFields, TElPDFSignature, LockFields);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_LockFields();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_LockFields, TElPDFSignature, LockFields);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		TElPDFSignature(TElPDFSignatureHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPDFDOCUMENT
		explicit TElPDFSignature(TElPDFDocument &Owner);

		explicit TElPDFSignature(TElPDFDocument *Owner);
#endif /* SB_USE_CLASS_TELPDFDOCUMENT */

		virtual ~TElPDFSignature();

};
#endif /* SB_USE_CLASS_TELPDFSIGNATURE */

#ifdef SB_USE_CLASS_TELPDFSIGNATUREINFO
class TElPDFSignatureInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFSignatureInfo)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_RequiredSubfilters;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_RequiredReasons;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_RequiredLockFields;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_LegalAttestations;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_RequiredSubfilters;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_RequiredReasons;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_RequiredLockFields;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_LegalAttestations;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		virtual void get_FieldName(std::string &OutResult);

		virtual TSBPDFFieldFlags get_FieldFlags();

		SB_DECLARE_PROPERTY_GET(TSBPDFFieldFlags, get_FieldFlags, TElPDFSignatureInfo, FieldFlags);

		virtual void get_MappingName(std::string &OutResult);

		virtual void get_AlternateName(std::string &OutResult);

		virtual TSBSVDConstraints get_RequiredConstraints();

		SB_DECLARE_PROPERTY_GET(TSBSVDConstraints, get_RequiredConstraints, TElPDFSignatureInfo, RequiredConstraints);

		virtual void get_RequiredFilter(std::string &OutResult);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_RequiredSubfilters();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_RequiredSubfilters, TElPDFSignatureInfo, RequiredSubfilters);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_RequiredSubfilters();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_RequiredSubfilters, TElPDFSignatureInfo, RequiredSubfilters);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_RequiredDigestAlgorithms(std::vector<int32_t> &OutResult);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_RequiredReasons();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_RequiredReasons, TElPDFSignatureInfo, RequiredReasons);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_RequiredReasons();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_RequiredReasons, TElPDFSignatureInfo, RequiredReasons);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual TSBPDFFieldMDPAction get_RequiredLockAction();

		SB_DECLARE_PROPERTY_GET(TSBPDFFieldMDPAction, get_RequiredLockAction, TElPDFSignatureInfo, RequiredLockAction);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_RequiredLockFields();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_RequiredLockFields, TElPDFSignatureInfo, RequiredLockFields);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_RequiredLockFields();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_RequiredLockFields, TElPDFSignatureInfo, RequiredLockFields);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual TSBPDFSignatureAllowedChanges get_RequiredAllowedChanges();

		SB_DECLARE_PROPERTY_GET(TSBPDFSignatureAllowedChanges, get_RequiredAllowedChanges, TElPDFSignatureInfo, RequiredAllowedChanges);

		virtual void get_TSPURL(std::string &OutResult);

		virtual bool get_TimestampRequired();

		SB_DECLARE_PROPERTY_GET(bool, get_TimestampRequired, TElPDFSignatureInfo, TimestampRequired);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_LegalAttestations();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_LegalAttestations, TElPDFSignatureInfo, LegalAttestations);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_LegalAttestations();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_LegalAttestations, TElPDFSignatureInfo, LegalAttestations);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual bool get_AddRevInfo();

		SB_DECLARE_PROPERTY_GET(bool, get_AddRevInfo, TElPDFSignatureInfo, AddRevInfo);

		virtual int32_t get_Height();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Height, TElPDFSignatureInfo, Height);

		virtual int32_t get_Width();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Width, TElPDFSignatureInfo, Width);

		virtual int32_t get_OffsetX();

		SB_DECLARE_PROPERTY_GET(int32_t, get_OffsetX, TElPDFSignatureInfo, OffsetX);

		virtual int32_t get_OffsetY();

		SB_DECLARE_PROPERTY_GET(int32_t, get_OffsetY, TElPDFSignatureInfo, OffsetY);

		virtual int32_t get_Page();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Page, TElPDFSignatureInfo, Page);

		virtual bool get_Invisible();

		SB_DECLARE_PROPERTY_GET(bool, get_Invisible, TElPDFSignatureInfo, Invisible);

		TElPDFSignatureInfo(TElPDFSignatureInfoHandle handle, TElOwnHandle ownHandle);

		TElPDFSignatureInfo();

		virtual ~TElPDFSignatureInfo();

};
#endif /* SB_USE_CLASS_TELPDFSIGNATUREINFO */

#ifdef SB_USE_CLASS_TELPDFENCODINGHANDLER
class TElPDFEncodingHandler: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFEncodingHandler)
	public:
		static void GetName(std::string &OutResult);

		virtual void GetName_Inst(std::string &OutResult);

		static void GetDescription(std::string &OutResult);

		virtual void GetDescription_Inst(std::string &OutResult);

		static TClassHandle ClassType();

		TElPDFEncodingHandler(TElPDFEncodingHandlerHandle handle, TElOwnHandle ownHandle);

		TElPDFEncodingHandler();

};
#endif /* SB_USE_CLASS_TELPDFENCODINGHANDLER */

#ifdef SB_USE_CLASS_TELPDFREQUIREMENTHANDLER
class TElPDFRequirementHandler: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFRequirementHandler)
	public:
		virtual void get_HandlerType(std::string &OutResult);

		virtual void get_ScriptName(std::string &OutResult);

		TElPDFRequirementHandler(TElPDFRequirementHandlerHandle handle, TElOwnHandle ownHandle);

		TElPDFRequirementHandler();

};
#endif /* SB_USE_CLASS_TELPDFREQUIREMENTHANDLER */

#ifdef SB_USE_CLASS_TELPDFREQUIREMENT
class TElPDFRequirement: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFRequirement)
#ifdef SB_USE_CLASS_TELPDFREQUIREMENTHANDLER
		TElPDFRequirementHandler* _Inst_Handlers;
#endif /* SB_USE_CLASS_TELPDFREQUIREMENTHANDLER */

		void initInstances();

	public:
		virtual void get_RequirementType(std::string &OutResult);

		virtual int32_t get_HandlerCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_HandlerCount, TElPDFRequirement, HandlerCount);

#ifdef SB_USE_CLASS_TELPDFREQUIREMENTHANDLER
		virtual TElPDFRequirementHandler* get_Handlers(int32_t Index);
#endif /* SB_USE_CLASS_TELPDFREQUIREMENTHANDLER */

		TElPDFRequirement(TElPDFRequirementHandle handle, TElOwnHandle ownHandle);

		TElPDFRequirement();

		virtual ~TElPDFRequirement();

};
#endif /* SB_USE_CLASS_TELPDFREQUIREMENT */

#ifdef SB_USE_CLASS_TELPDFPAGEINFO
class TElPDFPageInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFPageInfo)
#ifdef SB_USE_CLASS_TELPDFDICTIONARY
		TElPDFDictionary* _Inst_PageObject;
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

		void initInstances();

	public:
		bool CropBoxEmpty();

		virtual int32_t get_Width();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Width, TElPDFPageInfo, Width);

		virtual int32_t get_Height();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Height, TElPDFPageInfo, Height);

		virtual int32_t get_Rotate();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Rotate, TElPDFPageInfo, Rotate);

		virtual double get_CropLLX();

		SB_DECLARE_PROPERTY_GET(double, get_CropLLX, TElPDFPageInfo, CropLLX);

		virtual double get_CropLLY();

		SB_DECLARE_PROPERTY_GET(double, get_CropLLY, TElPDFPageInfo, CropLLY);

		virtual double get_CropURX();

		SB_DECLARE_PROPERTY_GET(double, get_CropURX, TElPDFPageInfo, CropURX);

		virtual double get_CropURY();

		SB_DECLARE_PROPERTY_GET(double, get_CropURY, TElPDFPageInfo, CropURY);

		virtual double get_MediaLLX();

		SB_DECLARE_PROPERTY_GET(double, get_MediaLLX, TElPDFPageInfo, MediaLLX);

		virtual double get_MediaLLY();

		SB_DECLARE_PROPERTY_GET(double, get_MediaLLY, TElPDFPageInfo, MediaLLY);

		virtual double get_MediaURX();

		SB_DECLARE_PROPERTY_GET(double, get_MediaURX, TElPDFPageInfo, MediaURX);

		virtual double get_MediaURY();

		SB_DECLARE_PROPERTY_GET(double, get_MediaURY, TElPDFPageInfo, MediaURY);

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
		virtual TElPDFDictionary* get_PageObject();

		SB_DECLARE_PROPERTY_GET(TElPDFDictionary*, get_PageObject, TElPDFPageInfo, PageObject);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

		TElPDFPageInfo(TElPDFPageInfoHandle handle, TElOwnHandle ownHandle);

		TElPDFPageInfo();

		virtual ~TElPDFPageInfo();

};
#endif /* SB_USE_CLASS_TELPDFPAGEINFO */

#ifdef SB_USE_CLASS_TELPDFFILEATTACHMENT
class TElPDFFileAttachment: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFFileAttachment)
	public:
#ifdef SB_USE_CLASS_TSTREAM
		void Init(TStream &Stream);

		void Init(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Save(TStream &Stream);

		void Save(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void get_ObjectName(std::string &OutResult);

		virtual void set_ObjectName(const std::string &Value);

		virtual void get_Filename(std::string &OutResult);

		virtual void set_Filename(const std::string &Value);

		virtual void get_UnicodeFilename(std::string &OutResult);

		virtual void set_UnicodeFilename(const std::string &Value);

		virtual void get_Description(std::string &OutResult);

		virtual void set_Description(const std::string &Value);

		virtual void get_SubType(std::string &OutResult);

		virtual void set_SubType(const std::string &Value);

		virtual int64_t get_Size();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Size, TElPDFFileAttachment, Size);

		virtual int64_t get_CreationDate();

		virtual void set_CreationDate(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_CreationDate, set_CreationDate, TElPDFFileAttachment, CreationDate);

		virtual int64_t get_ModificationDate();

		virtual void set_ModificationDate(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ModificationDate, set_ModificationDate, TElPDFFileAttachment, ModificationDate);

		virtual void get_MD5Checksum(std::vector<uint8_t> &OutResult);

		TElPDFFileAttachment(TElPDFFileAttachmentHandle handle, TElOwnHandle ownHandle);

		TElPDFFileAttachment();

};
#endif /* SB_USE_CLASS_TELPDFFILEATTACHMENT */

#ifdef SB_USE_CLASS_TELPDFLEGALCONTENTATTESTATION
class TElPDFLegalContentAttestation: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFLegalContentAttestation)
	public:
		virtual int32_t get_JavascriptActions();

		virtual void set_JavascriptActions(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_JavascriptActions, set_JavascriptActions, TElPDFLegalContentAttestation, JavascriptActions);

		virtual int32_t get_LaunchActions();

		virtual void set_LaunchActions(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_LaunchActions, set_LaunchActions, TElPDFLegalContentAttestation, LaunchActions);

		virtual int32_t get_URIActions();

		virtual void set_URIActions(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_URIActions, set_URIActions, TElPDFLegalContentAttestation, URIActions);

		virtual int32_t get_MovieActions();

		virtual void set_MovieActions(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MovieActions, set_MovieActions, TElPDFLegalContentAttestation, MovieActions);

		virtual int32_t get_SoundActions();

		virtual void set_SoundActions(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SoundActions, set_SoundActions, TElPDFLegalContentAttestation, SoundActions);

		virtual int32_t get_HideAnnotationActions();

		virtual void set_HideAnnotationActions(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HideAnnotationActions, set_HideAnnotationActions, TElPDFLegalContentAttestation, HideAnnotationActions);

		virtual int32_t get_GoToRemoteActions();

		virtual void set_GoToRemoteActions(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_GoToRemoteActions, set_GoToRemoteActions, TElPDFLegalContentAttestation, GoToRemoteActions);

		virtual int32_t get_AlternateImages();

		virtual void set_AlternateImages(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AlternateImages, set_AlternateImages, TElPDFLegalContentAttestation, AlternateImages);

		virtual int32_t get_ExternalStreams();

		virtual void set_ExternalStreams(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ExternalStreams, set_ExternalStreams, TElPDFLegalContentAttestation, ExternalStreams);

		virtual int32_t get_TrueTypeFonts();

		virtual void set_TrueTypeFonts(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TrueTypeFonts, set_TrueTypeFonts, TElPDFLegalContentAttestation, TrueTypeFonts);

		virtual int32_t get_ExternalRefXObjects();

		virtual void set_ExternalRefXObjects(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ExternalRefXObjects, set_ExternalRefXObjects, TElPDFLegalContentAttestation, ExternalRefXObjects);

		virtual int32_t get_ExternalOPIDicts();

		virtual void set_ExternalOPIDicts(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ExternalOPIDicts, set_ExternalOPIDicts, TElPDFLegalContentAttestation, ExternalOPIDicts);

		virtual int32_t get_NonEmbeddedFonts();

		virtual void set_NonEmbeddedFonts(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_NonEmbeddedFonts, set_NonEmbeddedFonts, TElPDFLegalContentAttestation, NonEmbeddedFonts);

		virtual int32_t get_DevDepGSOP();

		virtual void set_DevDepGSOP(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DevDepGSOP, set_DevDepGSOP, TElPDFLegalContentAttestation, DevDepGSOP);

		virtual int32_t get_DevDepGSHT();

		virtual void set_DevDepGSHT(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DevDepGSHT, set_DevDepGSHT, TElPDFLegalContentAttestation, DevDepGSHT);

		virtual int32_t get_DevDepGSTR();

		virtual void set_DevDepGSTR(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DevDepGSTR, set_DevDepGSTR, TElPDFLegalContentAttestation, DevDepGSTR);

		virtual int32_t get_DevDepGSUCR();

		virtual void set_DevDepGSUCR(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DevDepGSUCR, set_DevDepGSUCR, TElPDFLegalContentAttestation, DevDepGSUCR);

		virtual int32_t get_DevDepGSBG();

		virtual void set_DevDepGSBG(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DevDepGSBG, set_DevDepGSBG, TElPDFLegalContentAttestation, DevDepGSBG);

		virtual int32_t get_DevDepGSFL();

		virtual void set_DevDepGSFL(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DevDepGSFL, set_DevDepGSFL, TElPDFLegalContentAttestation, DevDepGSFL);

		virtual int32_t get_Annotations();

		virtual void set_Annotations(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Annotations, set_Annotations, TElPDFLegalContentAttestation, Annotations);

		virtual bool get_OptionalContent();

		virtual void set_OptionalContent(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OptionalContent, set_OptionalContent, TElPDFLegalContentAttestation, OptionalContent);

		virtual void get_Attestation(std::string &OutResult);

		virtual void set_Attestation(const std::string &Value);

		virtual bool get_Include();

		virtual void set_Include(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Include, set_Include, TElPDFLegalContentAttestation, Include);

		TElPDFLegalContentAttestation(TElPDFLegalContentAttestationHandle handle, TElOwnHandle ownHandle);

		TElPDFLegalContentAttestation();

};
#endif /* SB_USE_CLASS_TELPDFLEGALCONTENTATTESTATION */

#ifdef SB_USE_GLOBAL_PROCS_PDF

void GetPDFStandardType1FontName(TSBPDFStandardType1Font Font, std::string &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_PDF */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_PDF
SB_IMPORT uint32_t SB_APIENTRY SBPDF_RegisterSecurityHandler(TElPDFSecurityHandlerClassHandle HandlerClass);
SB_IMPORT uint32_t SB_APIENTRY SBPDF_UnregisterSecurityHandler(TElPDFSecurityHandlerClassHandle HandlerClass);
SB_IMPORT uint32_t SB_APIENTRY SBPDF_GetPDFStandardType1FontName(TSBPDFStandardType1FontRaw Font, char * pcOutResult, int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_PDF */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPDF */
