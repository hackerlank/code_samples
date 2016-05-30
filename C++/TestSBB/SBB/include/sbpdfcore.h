#ifndef __INC_SBPDFCORE
#define __INC_SBPDFCORE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbstreams.h"
#include "sbcustomcertstorage.h"
#include "sbzlib.h"
#include "sbrandom.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SFPDFDecompressionError 	"Decompression error: %s"
#define SB_SFPDFUnsupportedPredictorAlgorithm 	"Unsupported predictor algorithm: %d"
#define SB_SPDFInterruptedByUser 	"Operation was interrupted by user"
#define SB_SPDFUnsupportedEncodingFilter 	"Unsupported encoding filter"
#define SB_SPDFFailedToCloneObject 	"Failed to clone object"
#define SB_SPDFInvalidStreamDictionary 	"Invalid stream dictionary"
#define SB_PDF_ERROR_BASE 	720896
#define SB_PDF_ERROR_SECURITY_BASE 	721152
#define SB_PDF_ERROR_PADES_BASE 	721408
#define SB_PDF_ERROR_INTERNAL_ERROR 	720897
#define SB_PDF_ERROR_NOT_IMPLEMENTED 	720898
#define SB_PDF_ERROR_INDEX_OUT_OF_BOUNDS 	720899
#define SB_PDF_ERROR_INVALID_PARAMATER 	720900
#define SB_PDF_ERROR_INTERRUPTED_BY_USER 	720901
#define SB_PDF_ERROR_SILENT_ERROR 	720902
#define SB_PDF_ERROR_CLONE_OBJECT_FAILED 	720897
#define SB_PDF_ERROR_INVALID_STREAM_DATA 	720898
#define SB_PDF_ERROR_INVALID_STREAM_DICTIONARY 	720899
#define SB_PDF_ERROR_INVALID_REFERENCE 	720900
#define SB_PDF_ERROR_INVALID_REFERENCE_TABLE 	720901
#define SB_PDF_ERROR_INVALID_INDIRECT_OBJECT 	720902
#define SB_PDF_ERROR_INVALID_OBJECT_STREAM 	720903
#define SB_PDF_ERROR_INVALID_OBJECT_OR_GENERATION_NUMBER 	720904
#define SB_PDF_ERROR_INVALID_ROOT_OBJECT_LIST_ITEM_TYPE 	720905
#define SB_PDF_ERROR_INVALID_CROSS_REFERENCE_STREAM 	720906
#define SB_PDF_ERROR_INVALID_CROSS_REFERENCE_STREAM_DATA 	720907
#define SB_PDF_ERROR_INDIRECT_OBJECT_EXPECTED 	720908
#define SB_PDF_ERROR_BAD_OBJECT 	720909
#define SB_PDF_ERROR_BAD_TRAILER 	720910
#define SB_PDF_ERROR_UNEXPECTED_EOF 	720911
#define SB_PDF_ERROR_UNEXPECTED_CHARACTER 	720912
#define SB_PDF_ERROR_ILLEGAL_STRING 	720913
#define SB_PDF_ERROR_ILLEGAL_STREAM_DICTIONARY 	720914
#define SB_PDF_ERROR_UNSUPPORTED_VERSION 	720915
#define SB_PDF_ERROR_BAD_CROSS_REFERENCE_ENTRY 	720916
#define SB_PDF_ERROR_CYCLE_CROSS_REFERENCE 	720917
#define SB_PDF_ERROR_XREF_TABLE_ERROR_INDIRECT_EXPECTED 	720918
#define SB_PDF_ERROR_UNSUPPORTED_CROSS_REFERENCE_FIELD_SIZE 	720919
#define SB_PDF_ERROR_UNSUPPORTED_ENCODING_FILTER 	720920
#define SB_PDF_ERROR_CROSS_REFERENCE_STREAM_INVALID_INDEX 	720921
#define SB_PDF_ERROR_CROSS_REFERENCE_STREAM_INVALID_W_ENTRY 	720922
#define SB_PDF_ERROR_OBJECT_ALREADY_EXISTS 	720923
#define SB_PDF_ERROR_DECOMPRESSION_FAILED 	720924
#define SB_PDF_ERROR_INVALID_PNG_DATA 	720925
#define SB_PDF_ERROR_UNSUPPORTED_PNG_PREDICTOR 	720926
#define SB_PDF_ERROR_UNSUPPORTED_PREDICTOR_ALGORITHM 	720927
#define SB_PDF_ERROR_NO_DOCUMENT 	720966
#define SB_PDF_ERROR_DOCUMENT_NOT_OPENED 	720967
#define SB_PDF_ERROR_UNSUPPORTED_DOCUMENT_FORMAT 	720968
#define SB_PDF_ERROR_INVALID_ACRO_FORM_ENTRY 	720969
#define SB_PDF_ERROR_INVALID_ROOT_ENTRY 	720970
#define SB_PDF_ERROR_INVALID_LINEARIZATION_DICTIONARY 	720971
#define SB_PDF_ERROR_INVALID_DOCUMENT_ID 	720972
#define SB_PDF_ERROR_INVALID_DOCUMENT_CATALOG 	720973
#define SB_PDF_ERROR_INVALID_DOCUMENT_INFO_DICTIONARY 	720974
#define SB_PDF_ERROR_INVALID_DOCUMENT_PAGES_DICTIONARY 	720975
#define SB_PDF_ERROR_INVALID_DOCUMENT_REQUIREMENTS_DICTIONARY 	720976
#define SB_PDF_ERROR_INVALID_DOCUMENT_NAMES_DICTIONARY 	720977
#define SB_PDF_ERROR_INVALID_DOCUMENT_ANNOTATION 	720978
#define SB_PDF_ERROR_DOCUMENT_SIGNED_CANT_CHANGE_VERSION 	720979
#define SB_PDF_ERROR_DOCUMENT_OPENED_CANT_CHANGE_PROPERTY 	720980
#define SB_PDF_ERROR_UNSUPPORTED_IMAGE_TYPE 	720981
#define SB_PDF_ERROR_UNSUPPORTED_MASK_IMAGE_TYPE 	720982
#define SB_PDF_ERROR_UNSUPPORTED_COLOR_SPACE_TYPE 	720983
#define SB_PDF_ERROR_ENCODING_HANDLER_NOT_FOUND 	720984
#define SB_PDF_ERROR_SECURITY_HANDLER_ALREADY_REGISTERED 	721153
#define SB_PDF_ERROR_SECURITY_HANDLER_NOT_FOUND 	721154
#define SB_PDF_ERROR_SECURITY_HANDLER_NOT_ATTACHED 	721155
#define SB_PDF_ERROR_NO_SECURITY_HANDLER 	721156
#define SB_PDF_ERROR_NO_SIGNATURE_HANDLER 	721157
#define SB_PDF_ERROR_UNSUPPORTED_DIGEST_ALGORITHM 	721158
#define SB_PDF_ERROR_UNSUPPORTED_ENCRYPTION_ALGORITHM 	721159
#define SB_PDF_ERROR_INVALID_DIGEST 	721160
#define SB_PDF_ERROR_INVALID_SIGNATURE_REFERENCE 	721161
#define SB_PDF_ERROR_INVALID_SECURTIY_HANDLER 	721162
#define SB_PDF_ERROR_INVALID_SIGNATURE_CONTENTS 	721163
#define SB_PDF_ERROR_INVALID_SIGNATURE_BYTE_RANGE 	721164
#define SB_PDF_ERROR_BYTE_RANGE_NOT_COVER_DOCUMENT 	721165
#define SB_PDF_ERROR_DOCUMENT_NOT_ENCRYPTED 	721166
#define SB_PDF_ERROR_DOCUMENT_SIGNED_CANT_ENCRYPT 	721167
#define SB_PDF_ERROR_DOCUMENT_ENCRYPTED_CANT_ENCRYPT 	721168
#define SB_PDF_ERROR_DOCUMENT_ENCRYPTED_CANT_SIGN 	721169
#define SB_PDF_ERROR_DOCUMENT_ENCRYPTED_CANT_TIMESTAMP 	721170
#define SB_PDF_ERROR_DOCUMENT_ENCRYPTED_CANT_UPDATE_SIGNATURE 	721171
#define SB_PDF_ERROR_CANT_SIGN_AND_ENCRYPT_TOO_MANY_SIGNATURES 	721172
#define SB_PDF_ERROR_INVALID_DECRYPTION_MODE 	721173
#define SB_PDF_ERROR_INVALID_DECRYPTION_MODE_CANT_SIGN 	721174
#define SB_PDF_ERROR_SIGNATURE_UPDATED_CANT_MODIFY 	721175
#define SB_PDF_ERROR_NO_ENOUGH_SPACE_FOR_SIGNATURE 	721176
#define SB_PDF_ERROR_NO_ENOUGH_SPACE_FOR_SIGNATURE_UPDATE 	721177
#define SB_PDF_ERROR_NO_ENOUGH_SPACE_FOR_TIMESTAMP 	721178
#define SB_PDF_ERROR_RELOAD_SIGNATURE_FAILED 	721179
#define SB_PDF_ERROR_SIGNATURE_SIZE_TOO_LARGE 	721180
#define SB_PDF_ERROR_MDP_SIGNATURE_NOT_FIRST 	721181
#define SB_PDF_ERROR_ADOBE8_COMPATIBILITY_WARNING 	721182
#define SB_PDF_ERROR_CANT_DECODE_OBJECT 	721183
#define SB_PDF_ERROR_CANT_DECRYPT_OBJECT 	721184
#define SB_PDF_ERROR_CANT_ADD_SECOND_SIGNATURE 	721185
#define SB_PDF_ERROR_INVALID_SIGNATURE_INFORMATION 	721186
#define SB_PDF_ERROR_INVALID_SECURITY_HANDLER_INFORMATION 	721187
#define SB_PDF_ERROR_INVALID_ENCRYPTED_DATA 	721188
#define SB_PDF_ERROR_INVALID_BLOCK_CIPHER_PADDING 	721189
#define SB_PDF_ERROR_INVALID_KEY_SIZE 	721190
#define SB_PDF_ERROR_INVALID_PASSWORD 	721191
#define SB_PDF_ERROR_INVALID_PASSWORD_INFO 	721192
#define SB_PDF_ERROR_OBJECT_NOT_ENCRYPTED 	721193
#define SB_PDF_ERROR_UNEXPECTED_CIPHER_INFO 	721194
#define SB_PDF_ERROR_PERMISSIONS_VERIFICATION_FAILED 	721195
#define SB_PDF_ERROR_UNSUPPORTED_PASSWORD_HANDLER_REVISION 	721196
#define SB_PDF_ERROR_UNSUPPORTED_SECURITY_HANDLER_SUBFILTER 	721197
#define SB_PDF_ERROR_INVALID_SIGNING_CERTIFICATE_CHAIN 	721198
#define SB_PDF_ERROR_INVALID_PKCS7_DATA 	721199
#define SB_PDF_ERROR_PKCS7_SIGNING_FAILED 	721200
#define SB_PDF_ERROR_NO_SIGNING_CERTIFICATE 	721201
#define SB_PDF_ERROR_NO_SIGNER_CERTIFICATE 	721202
#define SB_PDF_ERROR_UNSUPPORTED_FEATURE 	721203
#define SB_PDF_ERROR_UNSUPPORTED_SIGNATURE_TYPE 	721204
#define SB_PDF_ERROR_NO_TSP_CLIENT 	721205
#define SB_PDF_ERROR_NO_ENCRYPTION_CERTIFICATE 	721206
#define SB_PDF_ERROR_UNSUPPORTED_KEY_ENCRYPTION_ALGORITHM 	721207
#define SB_PDF_ERROR_ENCRYPTION_FAILED 	721208
#define SB_PDF_ERROR_ENCRYPTION_KEY_GENERATION_FAILED 	721209
#define SB_PDF_ERROR_NO_DECRYPTION_KEY 	721210
#define SB_PDF_ERROR_BAD_ASYNC_STATE 	721211
#define SB_PDF_ERROR_DC_MODULE_UNAVAILABLE 	721212
#define SB_PDF_ERROR_BAD_PRESIGNATURE 	721409
#define SB_PDF_ERROR_SIGNATURE_NOT_FOUND 	721410
#define SB_PDF_ERROR_TOO_MANY_SIGNATURES 	721411
#define SB_PDF_ERROR_BAD_SIGNATURE_TYPE 	721412
#define SB_PDF_ERROR_TIMESTAMPING_FAILED 	721413
#define SB_PDF_ERROR_INVALID_TIMESTAMP_DATA 	721414
#define SB_PDF_ERROR_INVALID_CMS_DATA 	721415
#define SB_PDF_ERROR_BAD_SIGNING_CERTIFICATE_ATTRIBUTE 	721416
#define SB_PDF_ERROR_CHAIN_VALIDATION_FAILED 	721417
#define SB_PDF_CONST_STR_STARTXREF 	"startxref"
#define SB_PDF_CONST_STR_EOF 	"%%EOF"

typedef TElClassHandle TElPDFObjectHandle;

typedef TElClassHandle TElPDFFileHandle;

typedef TElPDFFileHandle TPDFFileHandle;

typedef TElPDFObjectHandle TPDFObjectHandle;

typedef TElClassHandle TElPDFNullHandle;

typedef TElPDFNullHandle TPDFNullHandle;

typedef TElClassHandle TElPDFBooleanHandle;

typedef TElPDFBooleanHandle TPDFBooleanHandle;

typedef TElClassHandle TElPDFRealHandle;

typedef TElPDFRealHandle TPDFRealHandle;

typedef TElClassHandle TElPDFStringHandle;

typedef TElPDFStringHandle TPDFStringHandle;

typedef TElClassHandle TElPDFCommentHandle;

typedef TElPDFCommentHandle TPDFCommentHandle;

typedef TElClassHandle TElPDFNameHandle;

typedef TElPDFNameHandle TPDFNameHandle;

typedef TElClassHandle TElPDFCpxObjHandle;

typedef TElPDFCpxObjHandle TPDFCpxObjHandle;

typedef TElClassHandle TElPDFArrayHandle;

typedef TElPDFArrayHandle TPDFArrayHandle;

typedef TElClassHandle TElPDFDictionaryHandle;

typedef TElPDFDictionaryHandle TPDFDictionaryHandle;

typedef TElClassHandle TElPDFStreamHandle;

typedef TElPDFStreamHandle TPDFStreamHandle;

typedef TElClassHandle TElPDFIndirectHandle;

typedef TElPDFIndirectHandle TPDFIndirectHandle;

typedef TElClassHandle TElPDFRefHandle;

typedef TElPDFRefHandle TPDFRefHandle;

typedef TElClassHandle TElPDFXRefHandle;

typedef TElPDFXRefHandle TPDFXRefHandle;

typedef TElClassHandle TElPDFXrefEntryHandle;

typedef TElPDFXrefEntryHandle TPDFXrefEntryHandle;

typedef TElClassHandle TElPDFXRefsHandle;

typedef TElPDFXRefsHandle TPDFXRefsHandle;

typedef uint8_t TPDFAssembleTypeRaw;

typedef enum
{
	atAppendChanges = 0,
	atReassemble = 1
} TPDFAssembleType;

typedef void (SB_CALLBACK *TSBPDFCreateTemporaryStreamEvent)(void * _ObjectData, TObjectHandle Sender, TStreamHandle * Stream, int8_t * FreeOnClose);

typedef void (SB_CALLBACK *TSBPDFProgressEvent)(void * _ObjectData, TObjectHandle Sender, int32_t Percent, int8_t * Cancel);

typedef void (SB_CALLBACK *TSBPDFCallbackFunc)(void * _ObjectData, TElPDFObjectHandle Obj, int8_t * OutResult);

typedef uint8_t TPDFStringEncodingRaw;

typedef enum
{
	seBinary = 0,
	seHexadecimal = 1,
	seOctal = 2
} TPDFStringEncoding;

typedef uint8_t TPDFXrefEntryTypeRaw;

typedef enum
{
	etGeneric = 0,
	etObjStream = 1
} TPDFXrefEntryType;

#ifdef SB_USE_CLASS_TELPDFOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElPDFObject_CreateCopy(TElPDFObjectHandle _Handle, TElPDFObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFObject_Write(TElPDFObjectHandle _Handle, TStreamHandle s, int8_t Assemble);
SB_IMPORT uint32_t SB_APIENTRY TElPDFObject_get_Data(TElPDFObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFObject_set_Data(TElPDFObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFObject_get_After(TElPDFObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFObject_set_After(TElPDFObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFObject_get_Between(TElPDFObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFObject_set_Between(TElPDFObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFObject_get_TypeErr(TElPDFObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFObject_get_Parent(TElPDFObjectHandle _Handle, TElPDFObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFObject_get_Offset(TElPDFObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFObject_get_Size(TElPDFObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFObject_get_OrigOffset(TElPDFObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFObject_get_Tag(TElPDFObjectHandle _Handle, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFObject_set_Tag(TElPDFObjectHandle _Handle, TObjectHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFObject_Create(TElPDFFileHandle Owner, TElPDFObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFOBJECT */

#ifdef SB_USE_CLASS_TELPDFFILE
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_Add(TElPDFFileHandle _Handle, TElPDFObjectHandle v);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_Clear(TElPDFFileHandle _Handle, int8_t ADestroyOwnedObjects);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_Load(TElPDFFileHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_Save(TElPDFFileHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_GetRootObjectIndex(TElPDFFileHandle _Handle, TElPDFObjectHandle Obj, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_GetLastObjectNum(TElPDFFileHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_SearchForEOFOffset(TElPDFFileHandle _Handle, TStreamHandle f, int64_t LastPosition, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_FindObj(TElPDFFileHandle _Handle, int32_t ObjNumber, int32_t GenNumber, TElPDFRefHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_GetXRefEntry(TElPDFFileHandle _Handle, int32_t ObjNumber, int32_t GenNumber, TElPDFXrefEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_get_Stream(TElPDFFileHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_set_Stream(TElPDFFileHandle _Handle, TStreamHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_get_Root(TElPDFFileHandle _Handle, TElPDFArrayHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_get_Trailer(TElPDFFileHandle _Handle, TElPDFDictionaryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_set_Trailer(TElPDFFileHandle _Handle, TElPDFDictionaryHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_get_Version(TElPDFFileHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_set_Version(TElPDFFileHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_get_AssembleType(TElPDFFileHandle _Handle, TPDFAssembleTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_set_AssembleType(TElPDFFileHandle _Handle, TPDFAssembleTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_get_PromptReassemble(TElPDFFileHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_set_PromptReassemble(TElPDFFileHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_get_XRefStreamsUsed(TElPDFFileHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_get_ContainsObjectStreams(TElPDFFileHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_get_SkipObjLoadingFromObjStream(TElPDFFileHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_set_SkipObjLoadingFromObjStream(TElPDFFileHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_get_Encrypted(TElPDFFileHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_get_NewLine(TElPDFFileHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_set_NewLine(TElPDFFileHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_get_OnCreateTemporaryStream(TElPDFFileHandle _Handle, TSBPDFCreateTemporaryStreamEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_set_OnCreateTemporaryStream(TElPDFFileHandle _Handle, TSBPDFCreateTemporaryStreamEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_get_OnProgress(TElPDFFileHandle _Handle, TSBPDFProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_set_OnProgress(TElPDFFileHandle _Handle, TSBPDFProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_get_OnDecryptStream(TElPDFFileHandle _Handle, TSBPDFCallbackFunc * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_set_OnDecryptStream(TElPDFFileHandle _Handle, TSBPDFCallbackFunc pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFFile_Create(TStreamHandle aStream, TElPDFFileHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFFILE */

#ifdef SB_USE_CLASS_TELPDFNULL
SB_IMPORT uint32_t SB_APIENTRY TElPDFNull_CreateCopy(TElPDFNullHandle _Handle, TElPDFObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFNull_Create(TElPDFFileHandle Owner, TElPDFObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFNULL */

#ifdef SB_USE_CLASS_TELPDFBOOLEAN
SB_IMPORT uint32_t SB_APIENTRY TElPDFBoolean_CreateCopy(TElPDFBooleanHandle _Handle, TElPDFObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFBoolean_get_Bool(TElPDFBooleanHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFBoolean_set_Bool(TElPDFBooleanHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFBoolean_Create(TElPDFFileHandle Owner, TElPDFObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFBOOLEAN */

#ifdef SB_USE_CLASS_TELPDFREAL
SB_IMPORT uint32_t SB_APIENTRY TElPDFReal_CreateCopy(TElPDFRealHandle _Handle, TElPDFObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFReal_get_RealValue(TElPDFRealHandle _Handle, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFReal_set_RealValue(TElPDFRealHandle _Handle, double Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFReal_get_IntValue(TElPDFRealHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFReal_set_IntValue(TElPDFRealHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFReal_get_IsInt(TElPDFRealHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFReal_Create(TElPDFFileHandle Owner, TElPDFObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFREAL */

#ifdef SB_USE_CLASS_TELPDFSTRING
SB_IMPORT uint32_t SB_APIENTRY TElPDFString_CreateCopy(TElPDFStringHandle _Handle, TElPDFObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFString_get_Str(TElPDFStringHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFString_set_Str(TElPDFStringHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFString_get_OrigStr(TElPDFStringHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFString_set_OrigStr(TElPDFStringHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFString_get_Encoding(TElPDFStringHandle _Handle, TPDFStringEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFString_set_Encoding(TElPDFStringHandle _Handle, TPDFStringEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFString_Create(TElPDFFileHandle Owner, TElPDFStringHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFSTRING */

#ifdef SB_USE_CLASS_TELPDFCOMMENT
SB_IMPORT uint32_t SB_APIENTRY TElPDFComment_CreateCopy(TElPDFCommentHandle _Handle, TElPDFObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFComment_get_Comment(TElPDFCommentHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFComment_set_Comment(TElPDFCommentHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFComment_Create(TElPDFFileHandle Owner, TElPDFCommentHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFCOMMENT */

#ifdef SB_USE_CLASS_TELPDFNAME
SB_IMPORT uint32_t SB_APIENTRY TElPDFName_CreateCopy(TElPDFNameHandle _Handle, TElPDFObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFName_get_Name(TElPDFNameHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFName_set_Name(TElPDFNameHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFName_Create(TElPDFFileHandle Owner, TElPDFObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFNAME */

#ifdef SB_USE_CLASS_TELPDFCPXOBJ
SB_IMPORT uint32_t SB_APIENTRY TElPDFCpxObj_get_Before(TElPDFCpxObjHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCpxObj_set_Before(TElPDFCpxObjHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFCpxObj_Create(TElPDFFileHandle Owner, TElPDFCpxObjHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFCPXOBJ */

#ifdef SB_USE_CLASS_TELPDFARRAY
SB_IMPORT uint32_t SB_APIENTRY TElPDFArray_CreateCopy(TElPDFArrayHandle _Handle, TElPDFObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFArray_Add(TElPDFArrayHandle _Handle, TElPDFObjectHandle v);
SB_IMPORT uint32_t SB_APIENTRY TElPDFArray_Insert(TElPDFArrayHandle _Handle, TElPDFObjectHandle v, int32_t Position);
SB_IMPORT uint32_t SB_APIENTRY TElPDFArray_Remove(TElPDFArrayHandle _Handle, TElPDFObjectHandle v);
SB_IMPORT uint32_t SB_APIENTRY TElPDFArray_Clear(TElPDFArrayHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFArray_get_Items(TElPDFArrayHandle _Handle, int64_t Index, TElPDFObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFArray_set_Items(TElPDFArrayHandle _Handle, int64_t Index, TElPDFObjectHandle v);
SB_IMPORT uint32_t SB_APIENTRY TElPDFArray_get_Count(TElPDFArrayHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFArray_get_Render(TElPDFArrayHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFArray_set_Render(TElPDFArrayHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFArray_Create(TElPDFFileHandle Owner, TElPDFArrayHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFARRAY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
SB_IMPORT uint32_t SB_APIENTRY TElPDFDictionary_CreateCopy(TElPDFDictionaryHandle _Handle, TElPDFObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDictionary_Add(TElPDFDictionaryHandle _Handle, const uint8_t pName[], int32_t szName, TElPDFObjectHandle v);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDictionary_Add_1(TElPDFDictionaryHandle _Handle, const char * pcName, int32_t szName, TElPDFObjectHandle v);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDictionary_GetItemByName(TElPDFDictionaryHandle _Handle, const uint8_t pName[], int32_t szName, TElPDFObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDictionary_GetItemByName_1(TElPDFDictionaryHandle _Handle, const char * pcS, int32_t szS, TElPDFObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDictionary_SetItemByName(TElPDFDictionaryHandle _Handle, const uint8_t pName[], int32_t szName, TElPDFObjectHandle Item);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDictionary_SetItemByName_1(TElPDFDictionaryHandle _Handle, const char * pcS, int32_t szS, TElPDFObjectHandle Item);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDictionary_AddString(TElPDFDictionaryHandle _Handle, const char * pcName, int32_t szName, const char * pcData, int32_t szData, TPDFStringEncodingRaw Enc, int8_t Overwrite);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDictionary_AddName(TElPDFDictionaryHandle _Handle, const char * pcName, int32_t szName, const char * pcData, int32_t szData, int8_t Overwrite);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDictionary_AddInt(TElPDFDictionaryHandle _Handle, const char * pcName, int32_t szName, int64_t Value, int8_t Overwrite);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDictionary_AddBoolean(TElPDFDictionaryHandle _Handle, const char * pcName, int32_t szName, int8_t Value, int8_t Overwrite);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDictionary_AddReal(TElPDFDictionaryHandle _Handle, const char * pcName, int32_t szName, double Value, int8_t Overwrite);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDictionary_AddRect(TElPDFDictionaryHandle _Handle, const char * pcName, int32_t szName, int32_t X1, int32_t Y1, int32_t X2, int32_t Y2, int8_t Overwrite);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDictionary_RemoveItemByName(TElPDFDictionaryHandle _Handle, const char * pcS, int32_t szS);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDictionary_get_Names(TElPDFDictionaryHandle _Handle, int64_t Index, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFDictionary_Create(TElPDFFileHandle Owner, TElPDFArrayHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElPDFStream_CreateCopy(TElPDFStreamHandle _Handle, TElPDFObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFStream_Write(TElPDFStreamHandle _Handle, TStreamHandle s, int8_t Assemble);
SB_IMPORT uint32_t SB_APIENTRY TElPDFStream_get_Data(TElPDFStreamHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFStream_set_Data(TElPDFStreamHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFStream_set_CR2(TElPDFStreamHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFStream_get_Stream(TElPDFStreamHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFStream_set_Stream(TElPDFStreamHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFStream_get_DecompressedStream(TElPDFStreamHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFStream_get_Dict(TElPDFStreamHandle _Handle, TElPDFDictionaryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFStream_set_Dict(TElPDFStreamHandle _Handle, TElPDFDictionaryHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFStream_get_OrigStream(TElPDFStreamHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFStream_set_OrigStream(TElPDFStreamHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFStream_Create(TElPDFFileHandle Owner, TElPDFStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFSTREAM */

#ifdef SB_USE_CLASS_TELPDFINDIRECT
SB_IMPORT uint32_t SB_APIENTRY TElPDFIndirect_CreateCopy(TElPDFIndirectHandle _Handle, TElPDFObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFIndirect_XrefAdd(TElPDFIndirectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFIndirect_XrefAddOnce(TElPDFIndirectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFIndirect_XrefFree(TElPDFIndirectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFIndirect_get_ObjNumber(TElPDFIndirectHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFIndirect_set_ObjNumber(TElPDFIndirectHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFIndirect_get_GenNumber(TElPDFIndirectHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFIndirect_set_GenNumber(TElPDFIndirectHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFIndirect_get_Obj(TElPDFIndirectHandle _Handle, TElPDFObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFIndirect_set_Obj(TElPDFIndirectHandle _Handle, TElPDFObjectHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFIndirect_get_XrefAdded(TElPDFIndirectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFIndirect_Create(TElPDFFileHandle Owner, TElPDFIndirectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFINDIRECT */

#ifdef SB_USE_CLASS_TELPDFREF
SB_IMPORT uint32_t SB_APIENTRY TElPDFRef_CreateCopy(TElPDFRefHandle _Handle, TElPDFObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFRef_SetNumbers(TElPDFRefHandle _Handle, int32_t ObjNum, int32_t GenNum);
SB_IMPORT uint32_t SB_APIENTRY TElPDFRef_get_ObjNumber(TElPDFRefHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFRef_set_ObjNumber(TElPDFRefHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFRef_get_GenNumber(TElPDFRefHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFRef_set_GenNumber(TElPDFRefHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFRef_get_Obj(TElPDFRefHandle _Handle, TElPDFIndirectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFRef_get_Loaded(TElPDFRefHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFRef_Create(TElPDFFileHandle Owner, TElPDFRefHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFREF */

#ifdef SB_USE_CLASS_TELPDFXREF
SB_IMPORT uint32_t SB_APIENTRY TElPDFXRef_get_Trailer(TElPDFXRefHandle _Handle, TElPDFDictionaryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFXRef_set_Trailer(TElPDFXRefHandle _Handle, TElPDFDictionaryHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFXRef_Create(TElPDFFileHandle Owner, TElPDFXRefHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFXREF */

#ifdef SB_USE_CLASS_TELPDFXREFENTRY
SB_IMPORT uint32_t SB_APIENTRY TElPDFXrefEntry_get_EntryType(TElPDFXrefEntryHandle _Handle, TPDFXrefEntryTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFXrefEntry_Create(TElPDFFileHandle Owner, TElPDFXrefEntryHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFXREFENTRY */

#ifdef SB_USE_CLASS_TELPDFXREFS
SB_IMPORT uint32_t SB_APIENTRY TElPDFXRefs_AddXRef(TElPDFXRefsHandle _Handle, int32_t ObjNumber, int32_t GenNumber, int64_t Offset, int8_t RaiseExceptionIfExists, int8_t OverwriteIfExists, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFXRefs_AddXRef_1(TElPDFXRefsHandle _Handle, int32_t ObjNumber, int32_t GenNumber, int32_t StreamObjNumber, int32_t StreamObjIndex, int8_t RaiseExceptionIfExists, int8_t OverwriteIfExists, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFXRefs_RemoveXRef(TElPDFXRefsHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPDFXRefs_Clear(TElPDFXRefsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFXRefs_Find(TElPDFXRefsHandle _Handle, int32_t ObjNumber, int32_t GenNumber, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFXRefs_get_XRefs(TElPDFXRefsHandle _Handle, int32_t Index, TElPDFXrefEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFXRefs_get_Count(TElPDFXRefsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFXRefs_Create(TElPDFFileHandle Owner, TElPDFXRefsHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFXREFS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPDFObject;
class TElPDFFile;
typedef TElPDFFile TPDFFile;
typedef TElPDFObject TPDFObject;
class TElPDFNull;
typedef TElPDFNull TPDFNull;
class TElPDFBoolean;
typedef TElPDFBoolean TPDFBoolean;
class TElPDFReal;
typedef TElPDFReal TPDFReal;
class TElPDFString;
typedef TElPDFString TPDFString;
class TElPDFComment;
typedef TElPDFComment TPDFComment;
class TElPDFName;
typedef TElPDFName TPDFName;
class TElPDFCpxObj;
typedef TElPDFCpxObj TPDFCpxObj;
class TElPDFArray;
typedef TElPDFArray TPDFArray;
class TElPDFDictionary;
typedef TElPDFDictionary TPDFDictionary;
class TElPDFStream;
typedef TElPDFStream TPDFStream;
class TElPDFIndirect;
typedef TElPDFIndirect TPDFIndirect;
class TElPDFRef;
typedef TElPDFRef TPDFRef;
class TElPDFXRef;
typedef TElPDFXRef TPDFXRef;
class TElPDFXrefEntry;
typedef TElPDFXrefEntry TPDFXrefEntry;
class TElPDFXRefs;
typedef TElPDFXRefs TPDFXRefs;

#ifdef SB_USE_CLASS_TELPDFOBJECT
class TElPDFObject: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFObject)
		TElPDFObject* _Inst_Parent;
		TObject* _Inst_Tag;

		void initInstances();

	public:
		virtual TElPDFObjectHandle CreateCopy();

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Write(TStream &s, bool Assemble);

		virtual void Write(TStream *s, bool Assemble);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void get_Data(std::vector<uint8_t> &OutResult);

		virtual void set_Data(const std::vector<uint8_t> &Value);

		virtual void get_After(std::vector<uint8_t> &OutResult);

		virtual void set_After(const std::vector<uint8_t> &Value);

		virtual void get_Between(std::vector<uint8_t> &OutResult);

		virtual void set_Between(const std::vector<uint8_t> &Value);

		virtual bool get_TypeErr();

		SB_DECLARE_PROPERTY_GET(bool, get_TypeErr, TElPDFObject, TypeErr);

		virtual TElPDFObject* get_Parent();

		SB_DECLARE_PROPERTY_GET(TElPDFObject*, get_Parent, TElPDFObject, Parent);

		virtual int64_t get_Offset();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Offset, TElPDFObject, Offset);

		virtual int64_t get_Size();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Size, TElPDFObject, Size);

		virtual int64_t get_OrigOffset();

		SB_DECLARE_PROPERTY_GET(int64_t, get_OrigOffset, TElPDFObject, OrigOffset);

		virtual TObject* get_Tag();

		virtual void set_Tag(TObject &Value);

		virtual void set_Tag(TObject *Value);

		SB_DECLARE_PROPERTY(TObject*, get_Tag, set_Tag, TElPDFObject, Tag);

		TElPDFObject(TElPDFObjectHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPDFFILE
		explicit TElPDFObject(TElPDFFile &Owner);

		explicit TElPDFObject(TElPDFFile *Owner);
#endif /* SB_USE_CLASS_TELPDFFILE */

		virtual ~TElPDFObject();

};
#endif /* SB_USE_CLASS_TELPDFOBJECT */

#ifdef SB_USE_CLASS_TELPDFFILE
class TElPDFFile: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFFile)
#ifdef SB_USE_CLASS_TSTREAM
		TStream* _Inst_Stream;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TELPDFARRAY
		TElPDFArray* _Inst_Root;
#endif /* SB_USE_CLASS_TELPDFARRAY */
#ifdef SB_USE_CLASS_TELPDFDICTIONARY
		TElPDFDictionary* _Inst_Trailer;
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELPDFOBJECT
		virtual void Add(TElPDFObject &v);

		virtual void Add(TElPDFObject *v);
#endif /* SB_USE_CLASS_TELPDFOBJECT */

		virtual void Clear(bool ADestroyOwnedObjects);

		virtual void Load();

		virtual void Save();

#ifdef SB_USE_CLASS_TELPDFOBJECT
		int32_t GetRootObjectIndex(TElPDFObject &Obj);

		int32_t GetRootObjectIndex(TElPDFObject *Obj);
#endif /* SB_USE_CLASS_TELPDFOBJECT */

		int32_t GetLastObjectNum();

#ifdef SB_USE_CLASS_TSTREAM
		int64_t SearchForEOFOffset(TStream &f, int64_t LastPosition);

		int64_t SearchForEOFOffset(TStream *f, int64_t LastPosition);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELPDFREF
		TElPDFRefHandle FindObj(int32_t ObjNumber, int32_t GenNumber);
#endif /* SB_USE_CLASS_TELPDFREF */

#ifdef SB_USE_CLASS_TELPDFXREFENTRY
		TElPDFXrefEntryHandle GetXRefEntry(int32_t ObjNumber, int32_t GenNumber);
#endif /* SB_USE_CLASS_TELPDFXREFENTRY */

#ifdef SB_USE_CLASS_TSTREAM
		virtual TStream* get_Stream();

		virtual void set_Stream(TStream &Value);

		virtual void set_Stream(TStream *Value);

		SB_DECLARE_PROPERTY(TStream*, get_Stream, set_Stream, TElPDFFile, Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELPDFARRAY
		virtual TElPDFArray* get_Root();

		SB_DECLARE_PROPERTY_GET(TElPDFArray*, get_Root, TElPDFFile, Root);
#endif /* SB_USE_CLASS_TELPDFARRAY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
		virtual TElPDFDictionary* get_Trailer();

		virtual void set_Trailer(TElPDFDictionary &Value);

		virtual void set_Trailer(TElPDFDictionary *Value);

		SB_DECLARE_PROPERTY(TElPDFDictionary*, get_Trailer, set_Trailer, TElPDFFile, Trailer);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

		virtual int32_t get_Version();

		virtual void set_Version(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Version, set_Version, TElPDFFile, Version);

		virtual TPDFAssembleType get_AssembleType();

		virtual void set_AssembleType(TPDFAssembleType Value);

		SB_DECLARE_PROPERTY(TPDFAssembleType, get_AssembleType, set_AssembleType, TElPDFFile, AssembleType);

		virtual bool get_PromptReassemble();

		virtual void set_PromptReassemble(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PromptReassemble, set_PromptReassemble, TElPDFFile, PromptReassemble);

		virtual bool get_XRefStreamsUsed();

		SB_DECLARE_PROPERTY_GET(bool, get_XRefStreamsUsed, TElPDFFile, XRefStreamsUsed);

		virtual bool get_ContainsObjectStreams();

		SB_DECLARE_PROPERTY_GET(bool, get_ContainsObjectStreams, TElPDFFile, ContainsObjectStreams);

		virtual bool get_SkipObjLoadingFromObjStream();

		virtual void set_SkipObjLoadingFromObjStream(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SkipObjLoadingFromObjStream, set_SkipObjLoadingFromObjStream, TElPDFFile, SkipObjLoadingFromObjStream);

		virtual bool get_Encrypted();

		SB_DECLARE_PROPERTY_GET(bool, get_Encrypted, TElPDFFile, Encrypted);

		virtual void get_NewLine(std::string &OutResult);

		virtual void set_NewLine(const std::string &Value);

		virtual void get_OnCreateTemporaryStream(TSBPDFCreateTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCreateTemporaryStream(TSBPDFCreateTemporaryStreamEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBPDFProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBPDFProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnDecryptStream(TSBPDFCallbackFunc &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDecryptStream(TSBPDFCallbackFunc pMethodValue, void * pDataValue);

		TElPDFFile(TElPDFFileHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TSTREAM
		explicit TElPDFFile(TStream &aStream);

		explicit TElPDFFile(TStream *aStream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual ~TElPDFFile();

};
#endif /* SB_USE_CLASS_TELPDFFILE */

#ifdef SB_USE_CLASS_TELPDFNULL
class TElPDFNull: public TElPDFObject
{
	private:
		SB_DISABLE_COPY(TElPDFNull)
	public:
		virtual TElPDFObjectHandle CreateCopy();

		TElPDFNull(TElPDFNullHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPDFFILE
		explicit TElPDFNull(TElPDFFile &Owner);

		explicit TElPDFNull(TElPDFFile *Owner);
#endif /* SB_USE_CLASS_TELPDFFILE */

};
#endif /* SB_USE_CLASS_TELPDFNULL */

#ifdef SB_USE_CLASS_TELPDFBOOLEAN
class TElPDFBoolean: public TElPDFObject
{
	private:
		SB_DISABLE_COPY(TElPDFBoolean)
	public:
		virtual TElPDFObjectHandle CreateCopy();

		virtual bool get_Bool();

		virtual void set_Bool(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Bool, set_Bool, TElPDFBoolean, Bool);

		TElPDFBoolean(TElPDFBooleanHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPDFFILE
		explicit TElPDFBoolean(TElPDFFile &Owner);

		explicit TElPDFBoolean(TElPDFFile *Owner);
#endif /* SB_USE_CLASS_TELPDFFILE */

};
#endif /* SB_USE_CLASS_TELPDFBOOLEAN */

#ifdef SB_USE_CLASS_TELPDFREAL
class TElPDFReal: public TElPDFObject
{
	private:
		SB_DISABLE_COPY(TElPDFReal)
	public:
		virtual TElPDFObjectHandle CreateCopy();

		virtual double get_RealValue();

		virtual void set_RealValue(double Value);

		SB_DECLARE_PROPERTY(double, get_RealValue, set_RealValue, TElPDFReal, RealValue);

		virtual int32_t get_IntValue();

		virtual void set_IntValue(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_IntValue, set_IntValue, TElPDFReal, IntValue);

		virtual bool get_IsInt();

		SB_DECLARE_PROPERTY_GET(bool, get_IsInt, TElPDFReal, IsInt);

		TElPDFReal(TElPDFRealHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPDFFILE
		explicit TElPDFReal(TElPDFFile &Owner);

		explicit TElPDFReal(TElPDFFile *Owner);
#endif /* SB_USE_CLASS_TELPDFFILE */

};
#endif /* SB_USE_CLASS_TELPDFREAL */

#ifdef SB_USE_CLASS_TELPDFSTRING
class TElPDFString: public TElPDFObject
{
	private:
		SB_DISABLE_COPY(TElPDFString)
	public:
		virtual TElPDFObjectHandle CreateCopy();

		virtual void get_Str(std::string &OutResult);

		virtual void set_Str(const std::string &Value);

		virtual void get_OrigStr(std::string &OutResult);

		virtual void set_OrigStr(const std::string &Value);

		virtual TPDFStringEncoding get_Encoding();

		virtual void set_Encoding(TPDFStringEncoding Value);

		SB_DECLARE_PROPERTY(TPDFStringEncoding, get_Encoding, set_Encoding, TElPDFString, Encoding);

		TElPDFString(TElPDFStringHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPDFFILE
		explicit TElPDFString(TElPDFFile &Owner);

		explicit TElPDFString(TElPDFFile *Owner);
#endif /* SB_USE_CLASS_TELPDFFILE */

};
#endif /* SB_USE_CLASS_TELPDFSTRING */

#ifdef SB_USE_CLASS_TELPDFCOMMENT
class TElPDFComment: public TElPDFObject
{
	private:
		SB_DISABLE_COPY(TElPDFComment)
	public:
		virtual TElPDFObjectHandle CreateCopy();

		virtual void get_Comment(std::vector<uint8_t> &OutResult);

		virtual void set_Comment(const std::vector<uint8_t> &Value);

		TElPDFComment(TElPDFCommentHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPDFFILE
		explicit TElPDFComment(TElPDFFile &Owner);

		explicit TElPDFComment(TElPDFFile *Owner);
#endif /* SB_USE_CLASS_TELPDFFILE */

};
#endif /* SB_USE_CLASS_TELPDFCOMMENT */

#ifdef SB_USE_CLASS_TELPDFNAME
class TElPDFName: public TElPDFObject
{
	private:
		SB_DISABLE_COPY(TElPDFName)
	public:
		virtual TElPDFObjectHandle CreateCopy();

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		TElPDFName(TElPDFNameHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPDFFILE
		explicit TElPDFName(TElPDFFile &Owner);

		explicit TElPDFName(TElPDFFile *Owner);
#endif /* SB_USE_CLASS_TELPDFFILE */

};
#endif /* SB_USE_CLASS_TELPDFNAME */

#ifdef SB_USE_CLASS_TELPDFCPXOBJ
class TElPDFCpxObj: public TElPDFObject
{
	private:
		SB_DISABLE_COPY(TElPDFCpxObj)
	public:
		virtual void get_Before(std::vector<uint8_t> &OutResult);

		virtual void set_Before(const std::vector<uint8_t> &Value);

		TElPDFCpxObj(TElPDFCpxObjHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPDFFILE
		explicit TElPDFCpxObj(TElPDFFile &Owner);

		explicit TElPDFCpxObj(TElPDFFile *Owner);
#endif /* SB_USE_CLASS_TELPDFFILE */

};
#endif /* SB_USE_CLASS_TELPDFCPXOBJ */

#ifdef SB_USE_CLASS_TELPDFARRAY
class TElPDFArray: public TElPDFCpxObj
{
	private:
		SB_DISABLE_COPY(TElPDFArray)
		TElPDFObject* _Inst_Items;

		void initInstances();

	public:
		virtual TElPDFObjectHandle CreateCopy();

		virtual void Add(TElPDFObject &v);

		virtual void Add(TElPDFObject *v);

		virtual void Insert(TElPDFObject &v, int32_t Position);

		virtual void Insert(TElPDFObject *v, int32_t Position);

		virtual void Remove(TElPDFObject &v);

		virtual void Remove(TElPDFObject *v);

		virtual void Clear();

		virtual TElPDFObject* get_Items(int64_t Index);

		virtual void set_Items(int64_t Index, TElPDFObject &v);

		virtual void set_Items(int64_t Index, TElPDFObject *v);

		virtual int64_t get_Count();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Count, TElPDFArray, Count);

		virtual bool get_Render();

		virtual void set_Render(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Render, set_Render, TElPDFArray, Render);

		TElPDFArray(TElPDFArrayHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPDFFILE
		explicit TElPDFArray(TElPDFFile &Owner);

		explicit TElPDFArray(TElPDFFile *Owner);
#endif /* SB_USE_CLASS_TELPDFFILE */

		virtual ~TElPDFArray();

};
#endif /* SB_USE_CLASS_TELPDFARRAY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
class TElPDFDictionary: public TElPDFArray
{
	private:
		SB_DISABLE_COPY(TElPDFDictionary)
	public:
		virtual TElPDFObjectHandle CreateCopy();

		virtual void Add(const std::vector<uint8_t> &Name, TElPDFObject &v);

		virtual void Add(const std::vector<uint8_t> &Name, TElPDFObject *v);

		virtual void Add(const std::string &Name, TElPDFObject &v);

		virtual void Add(const std::string &Name, TElPDFObject *v);

		TElPDFObjectHandle GetItemByName(const std::vector<uint8_t> &Name);

		TElPDFObjectHandle GetItemByName(const std::string &S);

		void SetItemByName(const std::vector<uint8_t> &Name, TElPDFObject &Item);

		void SetItemByName(const std::vector<uint8_t> &Name, TElPDFObject *Item);

		void SetItemByName(const std::string &S, TElPDFObject &Item);

		void SetItemByName(const std::string &S, TElPDFObject *Item);

		void AddString(const std::string &Name, const std::string &Data, TPDFStringEncoding Enc, bool Overwrite);

		void AddName(const std::string &Name, const std::string &Data, bool Overwrite);

		void AddInt(const std::string &Name, int64_t Value, bool Overwrite);

		void AddBoolean(const std::string &Name, bool Value, bool Overwrite);

		void AddReal(const std::string &Name, double Value, bool Overwrite);

		void AddRect(const std::string &Name, int32_t X1, int32_t Y1, int32_t X2, int32_t Y2, bool Overwrite);

		void RemoveItemByName(const std::string &S);

		virtual void get_Names(int64_t Index, std::string &OutResult);

		TElPDFDictionary(TElPDFDictionaryHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPDFFILE
		explicit TElPDFDictionary(TElPDFFile &Owner);

		explicit TElPDFDictionary(TElPDFFile *Owner);
#endif /* SB_USE_CLASS_TELPDFFILE */

};
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFSTREAM
class TElPDFStream: public TElPDFCpxObj
{
	private:
		SB_DISABLE_COPY(TElPDFStream)
#ifdef SB_USE_CLASS_TELPDFDICTIONARY
		TElPDFDictionary* _Inst_Dict;
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

		void initInstances();

	public:
		virtual TElPDFObjectHandle CreateCopy();

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Write(TStream &s, bool Assemble);

		virtual void Write(TStream *s, bool Assemble);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void get_Data(std::vector<uint8_t> &OutResult);

		virtual void set_Data(const std::vector<uint8_t> &Value);

		virtual void set_CR2(const std::vector<uint8_t> &Value);

		virtual void get_Stream(std::vector<uint8_t> &OutResult);

		virtual void set_Stream(const std::vector<uint8_t> &Value);

		virtual void get_DecompressedStream(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
		virtual TElPDFDictionary* get_Dict();

		virtual void set_Dict(TElPDFDictionary &Value);

		virtual void set_Dict(TElPDFDictionary *Value);

		SB_DECLARE_PROPERTY(TElPDFDictionary*, get_Dict, set_Dict, TElPDFStream, Dict);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

		virtual void get_OrigStream(std::vector<uint8_t> &OutResult);

		virtual void set_OrigStream(const std::vector<uint8_t> &Value);

		TElPDFStream(TElPDFStreamHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPDFFILE
		explicit TElPDFStream(TElPDFFile &Owner);

		explicit TElPDFStream(TElPDFFile *Owner);
#endif /* SB_USE_CLASS_TELPDFFILE */

		virtual ~TElPDFStream();

};
#endif /* SB_USE_CLASS_TELPDFSTREAM */

#ifdef SB_USE_CLASS_TELPDFINDIRECT
class TElPDFIndirect: public TElPDFCpxObj
{
	private:
		SB_DISABLE_COPY(TElPDFIndirect)
		TElPDFObject* _Inst_Obj;

		void initInstances();

	public:
		virtual TElPDFObjectHandle CreateCopy();

		void XrefAdd();

		void XrefAddOnce();

		void XrefFree();

		virtual int32_t get_ObjNumber();

		virtual void set_ObjNumber(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ObjNumber, set_ObjNumber, TElPDFIndirect, ObjNumber);

		virtual int32_t get_GenNumber();

		virtual void set_GenNumber(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_GenNumber, set_GenNumber, TElPDFIndirect, GenNumber);

		virtual TElPDFObject* get_Obj();

		virtual void set_Obj(TElPDFObject &Value);

		virtual void set_Obj(TElPDFObject *Value);

		SB_DECLARE_PROPERTY(TElPDFObject*, get_Obj, set_Obj, TElPDFIndirect, Obj);

		virtual bool get_XrefAdded();

		SB_DECLARE_PROPERTY_GET(bool, get_XrefAdded, TElPDFIndirect, XrefAdded);

		TElPDFIndirect(TElPDFIndirectHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPDFFILE
		explicit TElPDFIndirect(TElPDFFile &Owner);

		explicit TElPDFIndirect(TElPDFFile *Owner);
#endif /* SB_USE_CLASS_TELPDFFILE */

		virtual ~TElPDFIndirect();

};
#endif /* SB_USE_CLASS_TELPDFINDIRECT */

#ifdef SB_USE_CLASS_TELPDFREF
class TElPDFRef: public TElPDFObject
{
	private:
		SB_DISABLE_COPY(TElPDFRef)
#ifdef SB_USE_CLASS_TELPDFINDIRECT
		TElPDFIndirect* _Inst_Obj;
#endif /* SB_USE_CLASS_TELPDFINDIRECT */

		void initInstances();

	public:
		virtual TElPDFObjectHandle CreateCopy();

		void SetNumbers(int32_t ObjNum, int32_t GenNum);

		virtual int32_t get_ObjNumber();

		virtual void set_ObjNumber(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ObjNumber, set_ObjNumber, TElPDFRef, ObjNumber);

		virtual int32_t get_GenNumber();

		virtual void set_GenNumber(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_GenNumber, set_GenNumber, TElPDFRef, GenNumber);

#ifdef SB_USE_CLASS_TELPDFINDIRECT
		virtual TElPDFIndirect* get_Obj();

		SB_DECLARE_PROPERTY_GET(TElPDFIndirect*, get_Obj, TElPDFRef, Obj);
#endif /* SB_USE_CLASS_TELPDFINDIRECT */

		virtual bool get_Loaded();

		SB_DECLARE_PROPERTY_GET(bool, get_Loaded, TElPDFRef, Loaded);

		TElPDFRef(TElPDFRefHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPDFFILE
		explicit TElPDFRef(TElPDFFile &Owner);

		explicit TElPDFRef(TElPDFFile *Owner);
#endif /* SB_USE_CLASS_TELPDFFILE */

		virtual ~TElPDFRef();

};
#endif /* SB_USE_CLASS_TELPDFREF */

#ifdef SB_USE_CLASS_TELPDFXREF
class TElPDFXRef: public TElPDFCpxObj
{
	private:
		SB_DISABLE_COPY(TElPDFXRef)
#ifdef SB_USE_CLASS_TELPDFDICTIONARY
		TElPDFDictionary* _Inst_Trailer;
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELPDFDICTIONARY
		virtual TElPDFDictionary* get_Trailer();

		virtual void set_Trailer(TElPDFDictionary &Value);

		virtual void set_Trailer(TElPDFDictionary *Value);

		SB_DECLARE_PROPERTY(TElPDFDictionary*, get_Trailer, set_Trailer, TElPDFXRef, Trailer);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

		TElPDFXRef(TElPDFXRefHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPDFFILE
		explicit TElPDFXRef(TElPDFFile &Owner);

		explicit TElPDFXRef(TElPDFFile *Owner);
#endif /* SB_USE_CLASS_TELPDFFILE */

		virtual ~TElPDFXRef();

};
#endif /* SB_USE_CLASS_TELPDFXREF */

#ifdef SB_USE_CLASS_TELPDFXREFENTRY
class TElPDFXrefEntry: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFXrefEntry)
	public:
		virtual TPDFXrefEntryType get_EntryType();

		SB_DECLARE_PROPERTY_GET(TPDFXrefEntryType, get_EntryType, TElPDFXrefEntry, EntryType);

		TElPDFXrefEntry(TElPDFXrefEntryHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPDFFILE
		explicit TElPDFXrefEntry(TElPDFFile &Owner);

		explicit TElPDFXrefEntry(TElPDFFile *Owner);
#endif /* SB_USE_CLASS_TELPDFFILE */

};
#endif /* SB_USE_CLASS_TELPDFXREFENTRY */

#ifdef SB_USE_CLASS_TELPDFXREFS
class TElPDFXRefs: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFXRefs)
#ifdef SB_USE_CLASS_TELPDFXREFENTRY
		TElPDFXrefEntry* _Inst_XRefs;
#endif /* SB_USE_CLASS_TELPDFXREFENTRY */

		void initInstances();

	public:
		int32_t AddXRef(int32_t ObjNumber, int32_t GenNumber, int64_t Offset, bool RaiseExceptionIfExists, bool OverwriteIfExists);

		int32_t AddXRef(int32_t ObjNumber, int32_t GenNumber, int32_t StreamObjNumber, int32_t StreamObjIndex, bool RaiseExceptionIfExists, bool OverwriteIfExists);

		void RemoveXRef(int32_t Index);

		void Clear();

		int32_t Find(int32_t ObjNumber, int32_t GenNumber);

#ifdef SB_USE_CLASS_TELPDFXREFENTRY
		virtual TElPDFXrefEntry* get_XRefs(int32_t Index);
#endif /* SB_USE_CLASS_TELPDFXREFENTRY */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElPDFXRefs, Count);

		TElPDFXRefs(TElPDFXRefsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPDFFILE
		explicit TElPDFXRefs(TElPDFFile &Owner);

		explicit TElPDFXRefs(TElPDFFile *Owner);
#endif /* SB_USE_CLASS_TELPDFFILE */

		virtual ~TElPDFXRefs();

};
#endif /* SB_USE_CLASS_TELPDFXREFS */

#ifdef SB_USE_GLOBAL_PROCS_PDFCORE

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
void GetNameObjectFromDictionary(TElPDFDictionary &Dict, const std::string &Name, const std::string &Default, bool RaiseException, std::string &OutResult);
void GetNameObjectFromDictionary(TElPDFDictionary *Dict, const std::string &Name, const std::string &Default, bool RaiseException, std::string &OutResult);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
int32_t GetIntObjectFromDictionary(TElPDFDictionary &Dict, const std::string &Name, int32_t Default, bool RaiseException);
int32_t GetIntObjectFromDictionary(TElPDFDictionary *Dict, const std::string &Name, int32_t Default, bool RaiseException);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
double GetRealObjectFromDictionary(TElPDFDictionary &Dict, const std::string &Name, double Default, bool RaiseException);
double GetRealObjectFromDictionary(TElPDFDictionary *Dict, const std::string &Name, double Default, bool RaiseException);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
void GetStringObjectFromDictionary(TElPDFDictionary &Dict, const std::string &Name, bool RaiseException, std::vector<uint8_t> &OutResult);
void GetStringObjectFromDictionary(TElPDFDictionary *Dict, const std::string &Name, bool RaiseException, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASSES_TELPDFARRAY_AND_TELPDFDICTIONARY
TElPDFArrayHandle GetArrayObjectFromDictionary(TElPDFDictionary &Dict, const std::string &Name, bool RaiseException);
TElPDFArrayHandle GetArrayObjectFromDictionary(TElPDFDictionary *Dict, const std::string &Name, bool RaiseException);
#endif /* SB_USE_CLASSES_TELPDFARRAY_AND_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
TElPDFDictionaryHandle GetDictionaryObjectFromDictionary(TElPDFDictionary &Dict, const std::string &Name, bool RaiseException);
TElPDFDictionaryHandle GetDictionaryObjectFromDictionary(TElPDFDictionary *Dict, const std::string &Name, bool RaiseException);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
bool GetBooleanObjectFromDictionary(TElPDFDictionary &Dict, const std::string &Name, bool Default, bool RaiseException);
bool GetBooleanObjectFromDictionary(TElPDFDictionary *Dict, const std::string &Name, bool Default, bool RaiseException);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
void AddRealObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, double Value);
void AddRealObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, double Value);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
void AddRealObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, double Value, bool Overwrite);
void AddRealObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, double Value, bool Overwrite);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
void AddIntObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, int32_t Value);
void AddIntObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, int32_t Value);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
void AddIntObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, int32_t Value, bool Overwrite);
void AddIntObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, int32_t Value, bool Overwrite);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
void AddBooleanObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, bool Value);
void AddBooleanObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, bool Value);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
void AddBooleanObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, bool Value, bool Overwrite);
void AddBooleanObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, bool Value, bool Overwrite);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASSES_TELPDFDICTIONARY_AND_TELPDFSTRING
TElPDFStringHandle AddStringObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, const std::vector<uint8_t> &Value, TPDFStringEncoding Enc);
TElPDFStringHandle AddStringObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, const std::vector<uint8_t> &Value, TPDFStringEncoding Enc);
#endif /* SB_USE_CLASSES_TELPDFDICTIONARY_AND_TELPDFSTRING */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
void AddStringObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, const std::vector<uint8_t> &Value, TPDFStringEncoding Enc, bool Overwrite);
void AddStringObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, const std::vector<uint8_t> &Value, TPDFStringEncoding Enc, bool Overwrite);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
void AddNameObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, const std::string &Value);
void AddNameObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, const std::string &Value);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
void AddNameObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, const std::string &Value, bool Overwrite);
void AddNameObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, const std::string &Value, bool Overwrite);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASSES_TELPDFARRAY_AND_TELPDFDICTIONARY
TElPDFArrayHandle AddRectangleObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, int32_t X1, int32_t Y1, int32_t X2, int32_t Y2);
TElPDFArrayHandle AddRectangleObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, int32_t X1, int32_t Y1, int32_t X2, int32_t Y2);
#endif /* SB_USE_CLASSES_TELPDFARRAY_AND_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
void AddRectangleObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, int32_t X1, int32_t Y1, int32_t X2, int32_t Y2, bool Overwrite);
void AddRectangleObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, int32_t X1, int32_t Y1, int32_t X2, int32_t Y2, bool Overwrite);
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASSES_TELPDFDICTIONARY_AND_TELPDFREF
void AddReferenceToDictionary(TElPDFDictionary &Dict, const std::string &Name, TElPDFRef &Obj);
void AddReferenceToDictionary(TElPDFDictionary *Dict, const std::string &Name, TElPDFRef *Obj);
#endif /* SB_USE_CLASSES_TELPDFDICTIONARY_AND_TELPDFREF */

#ifdef SB_USE_CLASSES_TELPDFDICTIONARY_AND_TELPDFREF
void AddReferenceToDictionary(TElPDFDictionary &Dict, const std::string &Name, TElPDFRef &Obj, bool Overwrite);
void AddReferenceToDictionary(TElPDFDictionary *Dict, const std::string &Name, TElPDFRef *Obj, bool Overwrite);
#endif /* SB_USE_CLASSES_TELPDFDICTIONARY_AND_TELPDFREF */

#ifdef SB_USE_CLASS_TELPDFARRAY
void AddRealObjectToArray(TElPDFArray &Arr, double Value);
void AddRealObjectToArray(TElPDFArray *Arr, double Value);
#endif /* SB_USE_CLASS_TELPDFARRAY */

#ifdef SB_USE_CLASS_TELPDFARRAY
void AddIntObjectToArray(TElPDFArray &Arr, int32_t Value);
void AddIntObjectToArray(TElPDFArray *Arr, int32_t Value);
#endif /* SB_USE_CLASS_TELPDFARRAY */

#ifdef SB_USE_CLASS_TELPDFARRAY
void AddNameObjectToArray(TElPDFArray &Arr, const std::string &Value);
void AddNameObjectToArray(TElPDFArray *Arr, const std::string &Value);
#endif /* SB_USE_CLASS_TELPDFARRAY */

#ifdef SB_USE_CLASS_TELPDFARRAY
void AddStringObjectToArray(TElPDFArray &Arr, const std::vector<uint8_t> &Value, TPDFStringEncoding Enc);
void AddStringObjectToArray(TElPDFArray *Arr, const std::vector<uint8_t> &Value, TPDFStringEncoding Enc);
#endif /* SB_USE_CLASS_TELPDFARRAY */

#ifdef SB_USE_CLASSES_TELPDFFILE_AND_TELPDFSTREAM
TElPDFStreamHandle CreateStream(TElPDFFile &Owner);
TElPDFStreamHandle CreateStream(TElPDFFile *Owner);
#endif /* SB_USE_CLASSES_TELPDFFILE_AND_TELPDFSTREAM */

#ifdef SB_USE_CLASS_TELPDFSTREAM
void CompressStream(TElPDFStream &Strm, bool AddCRLF);
void CompressStream(TElPDFStream *Strm, bool AddCRLF);
#endif /* SB_USE_CLASS_TELPDFSTREAM */

void EncodePDFDate(int64_t D, std::string &OutResult);

void EncodePDFDate(int64_t D, bool AddUTCPostfix, std::string &OutResult);

int64_t DecodePDFDate(const std::string &S);

void EncodeTextString(const std::string &Str, std::vector<uint8_t> &OutResult);

void EncodeTextStringUnicode(const std::string &Str, std::vector<uint8_t> &OutResult);

void DecodeTextString(const std::vector<uint8_t> &Buf, std::string &OutResult);

#ifdef SB_USE_CLASSES_TELPDFDICTIONARY_AND_TSTRINGLIST
void GetSortedKeyList(TElPDFDictionary &Dictionary, TStringList &List);
void GetSortedKeyList(TElPDFDictionary *Dictionary, TStringList *List);
#endif /* SB_USE_CLASSES_TELPDFDICTIONARY_AND_TSTRINGLIST */

#endif /* SB_USE_GLOBAL_PROCS_PDFCORE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_PDFCORE
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_GetNameObjectFromDictionary(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, const char * pcDefault, int32_t szDefault, int8_t RaiseException, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_GetIntObjectFromDictionary(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, int32_t Default, int8_t RaiseException, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_GetRealObjectFromDictionary(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, double Default, int8_t RaiseException, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_GetStringObjectFromDictionary(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, int8_t RaiseException, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_GetArrayObjectFromDictionary(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, int8_t RaiseException, TElPDFArrayHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_GetDictionaryObjectFromDictionary(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, int8_t RaiseException, TElPDFDictionaryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_GetBooleanObjectFromDictionary(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, int8_t Default, int8_t RaiseException, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_AddRealObjectToDictionary(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, double Value);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_AddRealObjectToDictionary_1(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, double Value, int8_t Overwrite);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_AddIntObjectToDictionary(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_AddIntObjectToDictionary_1(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, int32_t Value, int8_t Overwrite);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_AddBooleanObjectToDictionary(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_AddBooleanObjectToDictionary_1(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, int8_t Value, int8_t Overwrite);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_AddStringObjectToDictionary(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, const uint8_t pValue[], int32_t szValue, TPDFStringEncodingRaw Enc, TElPDFStringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_AddStringObjectToDictionary_1(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, const uint8_t pValue[], int32_t szValue, TPDFStringEncodingRaw Enc, int8_t Overwrite);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_AddNameObjectToDictionary(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_AddNameObjectToDictionary_1(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, const char * pcValue, int32_t szValue, int8_t Overwrite);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_AddRectangleObjectToDictionary(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, int32_t X1, int32_t Y1, int32_t X2, int32_t Y2, TElPDFArrayHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_AddRectangleObjectToDictionary_1(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, int32_t X1, int32_t Y1, int32_t X2, int32_t Y2, int8_t Overwrite);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_AddReferenceToDictionary(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, TElPDFRefHandle Obj);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_AddReferenceToDictionary_1(TElPDFDictionaryHandle Dict, const char * pcName, int32_t szName, TElPDFRefHandle Obj, int8_t Overwrite);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_AddRealObjectToArray(TElPDFArrayHandle Arr, double Value);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_AddIntObjectToArray(TElPDFArrayHandle Arr, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_AddNameObjectToArray(TElPDFArrayHandle Arr, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_AddStringObjectToArray(TElPDFArrayHandle Arr, const uint8_t pValue[], int32_t szValue, TPDFStringEncodingRaw Enc);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_CreateStream(TElPDFFileHandle Owner, TElPDFStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_CompressStream(TElPDFStreamHandle Strm, int8_t AddCRLF);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_EncodePDFDate(int64_t D, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_EncodePDFDate_1(int64_t D, int8_t AddUTCPostfix, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_DecodePDFDate(const char * pcS, int32_t szS, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_EncodeTextString(const char * pcStr, int32_t szStr, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_EncodeTextStringUnicode(const char * pcStr, int32_t szStr, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_DecodeTextString(const uint8_t pBuf[], int32_t szBuf, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPDFCore_GetSortedKeyList(TElPDFDictionaryHandle Dictionary, TStringListHandle List);
#endif /* SB_USE_GLOBAL_PROCS_PDFCORE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPDFCORE */

