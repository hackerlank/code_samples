#ifndef __INC_SBPKCS11BASE
#define __INC_SBPKCS11BASE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbrsa.h"
#include "sbdsa.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbrandom.h"
#include "sbconstants.h"
#include "sbpkcs11common.h"
#include "sbcustomcrypto.h"
#include "sbcryptoprov.h"
#include "sbcryptoprovutils.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbrdn.h"
#include "sbsharedresource.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_TOKEN_PROP_FIRST 	0
#define SB_TOKEN_PROP_TOKEN_ATTR_UNSUPPORTED 	0
#define SB_TOKEN_PROP_REQUIRES_KEYS_TO_BE_ADDED_PRIOR_TO_CERTS 	1
#define SB_TOKEN_PROP_REQUIRES_SENSITIVE_FLAG_FOR_PRIVATE_KEY 	2
#define SB_TOKEN_PROP_REQUIRES_EXTRACTABLE_FLAG_FOR_PRIVATE_KEY 	3
#define SB_TOKEN_PROP_SUPPORTS_MODIFIABLE_FLAG_FOR_OBJECTS 	4
#define SB_TOKEN_PROP_LAST 	4
#define SB_PKCS11_ON_DEMAND_SESSION_HANDLE_START 	251658241
#define SB_SPKCS11ProviderNotOpened 	"PKCS#11 storage is not opened"
#define SB_SNoPKCS11ProviderSpecified 	"No PKCS#11 provider DLL has been specified"
#define SB_SPKCS11ProviderNoFunctions 	"PKCS#11 provider DLL doesn\'t export all required functions"
#define SB_SPKCS11ProviderNotFound 	"PKCS#11 provider DLL could not be found or loaded"
#define SB_SPKCS11ProviderError 	"PKCS#11 provider DLL function returned fatal error"
#ifndef SB_SIndexOutOfBounds
#define SB_SIndexOutOfBounds 	"Index out of bounds"
#endif
#define SB_SPKCS11Error 	"PKCS#11 error"
#define SB_SPKCS11FunctionError 	"PKCS#11 error in function #%d"
#define SB_SPKCS11FunctionErrorStr 	"PKCS#11 error %s in function %s"
#define SB_SAlgorithmDoesNotSupportEncryption 	"Certificate algorithm (%d) does not support encryption"
#define SB_SAlgorithmDoesNotSupportSigning 	"Certificate algorithm (%d) does not support signing"
#ifndef SB_SInternalError
#define SB_SInternalError 	"Internal error"
#endif
#define SB_SNotPKCS11Certificate 	"Not a PKCS#11 certificate"
#define SB_SObjectDoesNotBelongToSession 	"Object does not belong to any PKCS #11 session"
#define SB_SUnsupportedObjectType 	"Unsupported object type"
#ifndef SB_SBufferTooSmall
#define SB_SBufferTooSmall 	"Buffer is too small"
#endif
#define SB_SObjectNotFound 	"Object not found"
#define SB_SNumberOfSlotsChanged 	"Number of available slots changed"
#define SB_SNotInOnDemandMode 	"The session is running in non on-demand mode"
#define SB_SOnlyOneSessionAllowedInOnDemandMode 	"Only one session is allowed in on-demand mode"
#define SB_SAlreadyLoggedIn 	"Already logged in"
#define SB_SNotLoggedIn 	"Not logged in"
#define SB_SReadOnlySessionsOnlyAllowedInOnDemandMode 	"Read-only sessions are only allowed in on-demand mode"
#define SB_SUpdateFailedObjectsChanged 	"Update failed (one or more objects have been modified outside the application)"
#ifdef SB_IOS
#define SB_SPKCS11CallbackIDError 	"Callback not assigned for PKCS#11-driver GetUniqueID function"
#define SB_SPKCS11CallbackError 	"Callback not assigned for PKCS#11 function %s"
#endif

typedef TElClassHandle TElPKCS11ModuleHandle;

typedef TElClassHandle TElPKCS11SlotInfoHandle;

typedef TElClassHandle TElPKCS11SessionInfoHandle;

#ifdef SB_IOS
typedef TElClassHandle TElPKCS11FunctionsManagerHandle;
#endif

typedef TElClassHandle TElPKCS11ConsumerHandle;

typedef TElPKCS11ConsumerHandle ElPKCS11ConsumerHandle;

typedef TElClassHandle TElPKCS11AttributeListHandle;

typedef TElClassHandle TElPKCS11ObjectHandle;

typedef TElClassHandle TElPKCS11DataObjectHandle;

typedef TElClassHandle TElPKCS11CertificateObjectHandle;

typedef TElClassHandle TElPKCS11X509CertificateObjectHandle;

typedef TElClassHandle TElPKCS11WTLSCertificateObjectHandle;

typedef TElClassHandle TElPKCS11X509AttributeCertificateObjectHandle;

typedef TElClassHandle TElPKCS11KeyObjectHandle;

typedef TElClassHandle TElPKCS11PublicKeyObjectHandle;

typedef TElClassHandle TElPKCS11PrivateKeyObjectHandle;

typedef TElClassHandle TElPKCS11SecretKeyObjectHandle;

typedef TElClassHandle TElPKCS11DomainParametersObjectHandle;

typedef TElClassHandle TElPKCS11UtilsHandle;

typedef TElClassHandle TElPKCS11NSSParamsHandle;

typedef TElClassHandle TElPKCS11ModuleListHandle;

typedef TElPKCS11ModuleListHandle ElPKCS11ModuleListHandle;

typedef TElClassHandle TElPKCS11AlgorithmInfoHandle;

typedef TElClassHandle TElPKCS11AlgorithmConverterHandle;

typedef TElClassHandle TElSlotEventMonitoringThreadHandle;

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetFunctionListFunc)(PPKCS11FunctionList (* FunctionList), uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetFunctionListFunc)(PPKCS11FunctionList (* FunctionList), int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetFunctionListFunc)(void * _ObjectData, PPKCS11FunctionList (* FunctionList), uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetFunctionListFunc)(void * _ObjectData, PPKCS11FunctionList (* FunctionList), int64_t * OutResult);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11NotifyCallbackFunc)(uint32_t hSession, uint32_t event, void * pApplication, uint32_t * OutResult);
#else
typedef void (SB_CALLBACK *TPKCS11NotifyCallbackFunc)(int64_t hSession, int64_t event, void * pApplication, int64_t * OutResult);
#endif

typedef TPKCS11NotifyCallbackFunc * SB_CK_NOTIFY;

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11InitializeFunc)(PPKCS11InitializeArgs pArgs, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11InitializeFunc)(PPKCS11InitializeArgs pArgs, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11InitializeFunc)(void * _ObjectData, PPKCS11InitializeArgs pArgs, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11InitializeFunc)(void * _ObjectData, PPKCS11InitializeArgs pArgs, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11FinalizeFunc)(void * pReserved, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11FinalizeFunc)(void * pReserved, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11FinalizeFunc)(void * _ObjectData, void * pReserved, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11FinalizeFunc)(void * _ObjectData, void * pReserved, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetInfoFunc)(TPKCS11Info * pInfo, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetInfoFunc)(TPKCS11Info * pInfo, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetInfoFunc)(void * _ObjectData, TPKCS11Info * pInfo, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetInfoFunc)(void * _ObjectData, TPKCS11Info * pInfo, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetSlotListFunc)(uint8_t tokenPresent, uint32_t * pSlotList, uint32_t * pulCount, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetSlotListFunc)(uint8_t tokenPresent, int64_t * pSlotList, int64_t * pulCount, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetSlotListFunc)(void * _ObjectData, uint8_t tokenPresent, uint32_t * pSlotList, uint32_t * pulCount, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetSlotListFunc)(void * _ObjectData, uint8_t tokenPresent, int64_t * pSlotList, int64_t * pulCount, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetSlotInfoFunc)(uint32_t slotID, TPKCS11SlotInfo * pInfo, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetSlotInfoFunc)(int64_t slotID, TPKCS11SlotInfo * pInfo, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetSlotInfoFunc)(void * _ObjectData, uint32_t slotID, TPKCS11SlotInfo * pInfo, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetSlotInfoFunc)(void * _ObjectData, int64_t slotID, TPKCS11SlotInfo * pInfo, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetTokenInfoFunc)(uint32_t slotID, TPKCS11TokenInfo * pInfo, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetTokenInfoFunc)(int64_t slotID, TPKCS11TokenInfo * pInfo, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetTokenInfoFunc)(void * _ObjectData, uint32_t slotID, TPKCS11TokenInfo * pInfo, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetTokenInfoFunc)(void * _ObjectData, int64_t slotID, TPKCS11TokenInfo * pInfo, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11OpenSessionFunc)(uint32_t slotID, uint32_t flags, void * CallbackData, void * NotifyProc, uint32_t * SessionHandle, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11OpenSessionFunc)(int64_t slotID, int64_t flags, void * CallbackData, void * NotifyProc, int64_t * SessionHandle, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11OpenSessionFunc)(void * _ObjectData, uint32_t slotID, uint32_t flags, void * CallbackData, void * NotifyProc, uint32_t * SessionHandle, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11OpenSessionFunc)(void * _ObjectData, int64_t slotID, int64_t flags, void * CallbackData, void * NotifyProc, int64_t * SessionHandle, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetSessionInfoFunc)(uint32_t hSession, TPKCS11SessionInfo * pInfo, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetSessionInfoFunc)(int64_t hSession, TPKCS11SessionInfo * pInfo, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetSessionInfoFunc)(void * _ObjectData, uint32_t hSession, TPKCS11SessionInfo * pInfo, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetSessionInfoFunc)(void * _ObjectData, int64_t hSession, TPKCS11SessionInfo * pInfo, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11CloseSessionFunc)(uint32_t hSession, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11CloseSessionFunc)(int64_t hSession, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11CloseSessionFunc)(void * _ObjectData, uint32_t hSession, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11CloseSessionFunc)(void * _ObjectData, int64_t hSession, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11LoginFunc)(uint32_t hSession, uint32_t userType, char * pPin, uint32_t ulPinLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11LoginFunc)(int64_t hSession, int64_t userType, char * pPin, int64_t ulPinLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11LoginFunc)(void * _ObjectData, uint32_t hSession, uint32_t userType, char * pPin, uint32_t ulPinLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11LoginFunc)(void * _ObjectData, int64_t hSession, int64_t userType, char * pPin, int64_t ulPinLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11LogoutFunc)(uint32_t hSession, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11LogoutFunc)(int64_t hSession, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11LogoutFunc)(void * _ObjectData, uint32_t hSession, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11LogoutFunc)(void * _ObjectData, int64_t hSession, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11FindObjectsInitFunc)(uint32_t hSession, SB_CK_ATTRIBUTE_PTR pAttributes, uint32_t ulCount, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11FindObjectsInitFunc)(int64_t hSession, SB_CK_ATTRIBUTE_PTR pAttributes, int64_t ulCount, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11FindObjectsInitFunc)(void * _ObjectData, uint32_t hSession, SB_CK_ATTRIBUTE_PTR pAttributes, uint32_t ulCount, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11FindObjectsInitFunc)(void * _ObjectData, int64_t hSession, SB_CK_ATTRIBUTE_PTR pAttributes, int64_t ulCount, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11FindObjectsFunc)(uint32_t hSession, uint32_t * phObject, uint32_t ulMaxObjectCount, uint32_t * pulObjectCount, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11FindObjectsFunc)(int64_t hSession, int64_t * phObject, int64_t ulMaxObjectCount, int64_t * pulObjectCount, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11FindObjectsFunc)(void * _ObjectData, uint32_t hSession, uint32_t * phObject, uint32_t ulMaxObjectCount, uint32_t * pulObjectCount, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11FindObjectsFunc)(void * _ObjectData, int64_t hSession, int64_t * phObject, int64_t ulMaxObjectCount, int64_t * pulObjectCount, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11FindObjectsFinalFunc)(uint32_t hSession, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11FindObjectsFinalFunc)(int64_t hSession, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11FindObjectsFinalFunc)(void * _ObjectData, uint32_t hSession, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11FindObjectsFinalFunc)(void * _ObjectData, int64_t hSession, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetAttributeValueFunc)(uint32_t hSession, uint32_t hObject, void * pTemplate, uint32_t ulCount, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetAttributeValueFunc)(int64_t hSession, int64_t hObject, void * pTemplate, int64_t ulCount, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetAttributeValueFunc)(void * _ObjectData, uint32_t hSession, uint32_t hObject, void * pTemplate, uint32_t ulCount, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetAttributeValueFunc)(void * _ObjectData, int64_t hSession, int64_t hObject, void * pTemplate, int64_t ulCount, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DestroyObjectFunc)(uint32_t hSession, uint32_t hObject, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DestroyObjectFunc)(int64_t hSession, int64_t hObject, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DestroyObjectFunc)(void * _ObjectData, uint32_t hSession, uint32_t hObject, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DestroyObjectFunc)(void * _ObjectData, int64_t hSession, int64_t hObject, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11CreateObjectFunc)(uint32_t hSession, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t * hObject, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11CreateObjectFunc)(int64_t hSession, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t * hObject, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11CreateObjectFunc)(void * _ObjectData, uint32_t hSession, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t * hObject, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11CreateObjectFunc)(void * _ObjectData, int64_t hSession, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t * hObject, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SignInitFunc)(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SignInitFunc)(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SignInitFunc)(void * _ObjectData, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SignInitFunc)(void * _ObjectData, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SignFunc)(uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pSignature, uint32_t * pulSignatureLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SignFunc)(int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pSignature, int64_t * pulSignatureLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SignFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pSignature, uint32_t * pulSignatureLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SignFunc)(void * _ObjectData, int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pSignature, int64_t * pulSignatureLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DecryptInitFunc)(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DecryptInitFunc)(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DecryptInitFunc)(void * _ObjectData, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DecryptInitFunc)(void * _ObjectData, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DecryptFunc)(uint32_t hSession, uint8_t * pEncryptedData, uint32_t ulEncryptedDataLen, uint8_t * pData, uint32_t * pulDataLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DecryptFunc)(int64_t hSession, uint8_t * pEncryptedData, int64_t ulEncryptedDataLen, uint8_t * pData, int64_t * pulDataLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DecryptFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pEncryptedData, uint32_t ulEncryptedDataLen, uint8_t * pData, uint32_t * pulDataLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DecryptFunc)(void * _ObjectData, int64_t hSession, uint8_t * pEncryptedData, int64_t ulEncryptedDataLen, uint8_t * pData, int64_t * pulDataLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11WaitForSlotEventFunc)(uint32_t flags, uint32_t * pSlot, void * pReserved, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11WaitForSlotEventFunc)(int64_t flags, int64_t * pSlot, void * pReserved, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11WaitForSlotEventFunc)(void * _ObjectData, uint32_t flags, uint32_t * pSlot, void * pReserved, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11WaitForSlotEventFunc)(void * _ObjectData, int64_t flags, int64_t * pSlot, void * pReserved, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetMechanismListFunc)(uint32_t slotID, uint32_t * pMechanismList, uint32_t * pulCount, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetMechanismListFunc)(int64_t slotID, int64_t * pMechanismList, int64_t * pulCount, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetMechanismListFunc)(void * _ObjectData, uint32_t slotID, uint32_t * pMechanismList, uint32_t * pulCount, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetMechanismListFunc)(void * _ObjectData, int64_t slotID, int64_t * pMechanismList, int64_t * pulCount, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetMechanismInfoFunc)(uint32_t slotID, uint32_t mechanism_type, TPKCS11MechanismInfo * pInfo, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetMechanismInfoFunc)(int64_t slotID, int64_t mechanism_type, TPKCS11MechanismInfo * pInfo, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetMechanismInfoFunc)(void * _ObjectData, uint32_t slotID, uint32_t mechanism_type, TPKCS11MechanismInfo * pInfo, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetMechanismInfoFunc)(void * _ObjectData, int64_t slotID, int64_t mechanism_type, TPKCS11MechanismInfo * pInfo, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11InitTokenFunc)(uint32_t slotID, char * pPin, uint32_t ulPinLen, char * pLabel, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11InitTokenFunc)(int64_t slotID, char * pPin, int64_t ulPinLen, char * pLabel, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11InitTokenFunc)(void * _ObjectData, uint32_t slotID, char * pPin, uint32_t ulPinLen, char * pLabel, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11InitTokenFunc)(void * _ObjectData, int64_t slotID, char * pPin, int64_t ulPinLen, char * pLabel, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11InitPINFunc)(uint32_t hSession, char * pPin, uint32_t ulPinLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11InitPINFunc)(int64_t hSession, char * pPin, int64_t ulPinLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11InitPINFunc)(void * _ObjectData, uint32_t hSession, char * pPin, uint32_t ulPinLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11InitPINFunc)(void * _ObjectData, int64_t hSession, char * pPin, int64_t ulPinLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SetPINFunc)(uint32_t hSession, char * pOldPin, uint32_t ulOldLen, char * pNewPin, uint32_t ulNewLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SetPINFunc)(int64_t hSession, char * pOldPin, int64_t ulOldLen, char * pNewPin, int64_t ulNewLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SetPINFunc)(void * _ObjectData, uint32_t hSession, char * pOldPin, uint32_t ulOldLen, char * pNewPin, uint32_t ulNewLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SetPINFunc)(void * _ObjectData, int64_t hSession, char * pOldPin, int64_t ulOldLen, char * pNewPin, int64_t ulNewLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11CloseAllSessionsFunc)(uint32_t slotID, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11CloseAllSessionsFunc)(int64_t slotID, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11CloseAllSessionsFunc)(void * _ObjectData, uint32_t slotID, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11CloseAllSessionsFunc)(void * _ObjectData, int64_t slotID, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetOperationStateFunc)(uint32_t hSession, uint8_t * pOperationState, uint32_t * pulOperationStateLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetOperationStateFunc)(int64_t hSession, uint8_t * pOperationState, int64_t * pulOperationStateLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetOperationStateFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pOperationState, uint32_t * pulOperationStateLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetOperationStateFunc)(void * _ObjectData, int64_t hSession, uint8_t * pOperationState, int64_t * pulOperationStateLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SetOperationStateFunc)(uint32_t hSession, uint8_t * pOperationState, uint32_t ulOperationStateLen, uint32_t hEncryptionKey, uint32_t hAuthenticationKey, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SetOperationStateFunc)(int64_t hSession, uint8_t * pOperationState, int64_t ulOperationStateLen, int64_t hEncryptionKey, int64_t hAuthenticationKey, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SetOperationStateFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pOperationState, uint32_t ulOperationStateLen, uint32_t hEncryptionKey, uint32_t hAuthenticationKey, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SetOperationStateFunc)(void * _ObjectData, int64_t hSession, uint8_t * pOperationState, int64_t ulOperationStateLen, int64_t hEncryptionKey, int64_t hAuthenticationKey, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11CopyObjectFunc)(uint32_t hSession, uint32_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t * phNewObject, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11CopyObjectFunc)(int64_t hSession, int64_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t * phNewObject, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11CopyObjectFunc)(void * _ObjectData, uint32_t hSession, uint32_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t * phNewObject, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11CopyObjectFunc)(void * _ObjectData, int64_t hSession, int64_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t * phNewObject, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetObjectSizeFunc)(uint32_t hSession, uint32_t hObject, uint32_t * pulSize, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetObjectSizeFunc)(int64_t hSession, int64_t hObject, int64_t * pulSize, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetObjectSizeFunc)(void * _ObjectData, uint32_t hSession, uint32_t hObject, uint32_t * pulSize, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetObjectSizeFunc)(void * _ObjectData, int64_t hSession, int64_t hObject, int64_t * pulSize, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SetAttributeValueFunc)(uint32_t hSession, uint32_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SetAttributeValueFunc)(int64_t hSession, int64_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SetAttributeValueFunc)(void * _ObjectData, uint32_t hSession, uint32_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SetAttributeValueFunc)(void * _ObjectData, int64_t hSession, int64_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11EncryptInitFunc)(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11EncryptInitFunc)(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11EncryptInitFunc)(void * _ObjectData, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11EncryptInitFunc)(void * _ObjectData, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11EncryptFunc)(uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pEncryptedData, uint32_t * pulEncryptedDataLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11EncryptFunc)(int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pEncryptedData, int64_t * pulEncryptedDataLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11EncryptFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pEncryptedData, uint32_t * pulEncryptedDataLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11EncryptFunc)(void * _ObjectData, int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pEncryptedData, int64_t * pulEncryptedDataLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11EncryptUpdateFunc)(uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint8_t * pEncryptedPart, uint32_t * pulEncryptedPartLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11EncryptUpdateFunc)(int64_t hSession, uint8_t * pPart, int64_t ulPartLen, uint8_t * pEncryptedPart, int64_t * pulEncryptedPartLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11EncryptUpdateFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint8_t * pEncryptedPart, uint32_t * pulEncryptedPartLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11EncryptUpdateFunc)(void * _ObjectData, int64_t hSession, uint8_t * pPart, int64_t ulPartLen, uint8_t * pEncryptedPart, int64_t * pulEncryptedPartLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11EncryptFinalFunc)(uint32_t hSession, uint8_t * pLastEncryptedPart, uint32_t * pulLastEncryptedPartLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11EncryptFinalFunc)(int64_t hSession, uint8_t * pLastEncryptedPart, int64_t * pulLastEncryptedPartLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11EncryptFinalFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pLastEncryptedPart, uint32_t * pulLastEncryptedPartLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11EncryptFinalFunc)(void * _ObjectData, int64_t hSession, uint8_t * pLastEncryptedPart, int64_t * pulLastEncryptedPartLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DecryptUpdateFunc)(uint32_t hSession, uint8_t * pEncryptedPart, uint32_t ulEncryptedPartLen, uint8_t * pPart, uint32_t * pulPartLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DecryptUpdateFunc)(int64_t hSession, uint8_t * pEncryptedPart, int64_t ulEncryptedPartLen, uint8_t * pPart, int64_t * pulPartLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DecryptUpdateFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pEncryptedPart, uint32_t ulEncryptedPartLen, uint8_t * pPart, uint32_t * pulPartLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DecryptUpdateFunc)(void * _ObjectData, int64_t hSession, uint8_t * pEncryptedPart, int64_t ulEncryptedPartLen, uint8_t * pPart, int64_t * pulPartLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DecryptFinalFunc)(uint32_t hSession, uint8_t * pLastPart, uint32_t * pulLastPartLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DecryptFinalFunc)(int64_t hSession, uint8_t * pLastPart, int64_t * pulLastPartLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DecryptFinalFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pLastPart, uint32_t * pulLastPartLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DecryptFinalFunc)(void * _ObjectData, int64_t hSession, uint8_t * pLastPart, int64_t * pulLastPartLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DigestInitFunc)(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DigestInitFunc)(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DigestInitFunc)(void * _ObjectData, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DigestInitFunc)(void * _ObjectData, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DigestFunc)(uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pDigest, uint32_t * pulDigestLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DigestFunc)(int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pDigest, int64_t * pulDigestLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DigestFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pDigest, uint32_t * pulDigestLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DigestFunc)(void * _ObjectData, int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pDigest, int64_t * pulDigestLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DigestUpdateFunc)(uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DigestUpdateFunc)(int64_t hSession, uint8_t * pPart, int64_t ulPartLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DigestUpdateFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DigestUpdateFunc)(void * _ObjectData, int64_t hSession, uint8_t * pPart, int64_t ulPartLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DigestKeyFunc)(uint32_t hSession, uint32_t hKey, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DigestKeyFunc)(int64_t hSession, int64_t hKey, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DigestKeyFunc)(void * _ObjectData, uint32_t hSession, uint32_t hKey, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DigestKeyFunc)(void * _ObjectData, int64_t hSession, int64_t hKey, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DigestFinalFunc)(uint32_t hSession, uint8_t * pDigest, uint32_t * pulDigestLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DigestFinalFunc)(int64_t hSession, uint8_t * pDigest, int64_t * pulDigestLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DigestFinalFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pDigest, uint32_t * pulDigestLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DigestFinalFunc)(void * _ObjectData, int64_t hSession, uint8_t * pDigest, int64_t * pulDigestLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SignUpdateFunc)(uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SignUpdateFunc)(int64_t hSession, uint8_t * pPart, int64_t ulPartLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SignUpdateFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SignUpdateFunc)(void * _ObjectData, int64_t hSession, uint8_t * pPart, int64_t ulPartLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SignFinalFunc)(uint32_t hSession, uint8_t * pSignature, uint32_t * pulSignatureLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SignFinalFunc)(int64_t hSession, uint8_t * pSignature, int64_t * pulSignatureLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SignFinalFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pSignature, uint32_t * pulSignatureLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SignFinalFunc)(void * _ObjectData, int64_t hSession, uint8_t * pSignature, int64_t * pulSignatureLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SignRecoverInitFunc)(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SignRecoverInitFunc)(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SignRecoverInitFunc)(void * _ObjectData, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SignRecoverInitFunc)(void * _ObjectData, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SignRecoverFunc)(uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pSignature, uint32_t * pulSignatureLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SignRecoverFunc)(int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pSignature, int64_t * pulSignatureLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SignRecoverFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pSignature, uint32_t * pulSignatureLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SignRecoverFunc)(void * _ObjectData, int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pSignature, int64_t * pulSignatureLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11VerifyInitFunc)(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11VerifyInitFunc)(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11VerifyInitFunc)(void * _ObjectData, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11VerifyInitFunc)(void * _ObjectData, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11VerifyFunc)(uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pSignature, uint32_t ulSignatureLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11VerifyFunc)(int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pSignature, int64_t ulSignatureLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11VerifyFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pSignature, uint32_t ulSignatureLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11VerifyFunc)(void * _ObjectData, int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pSignature, int64_t ulSignatureLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11VerifyUpdateFunc)(uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11VerifyUpdateFunc)(int64_t hSession, uint8_t * pPart, int64_t ulPartLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11VerifyUpdateFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11VerifyUpdateFunc)(void * _ObjectData, int64_t hSession, uint8_t * pPart, int64_t ulPartLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11VerifyFinalFunc)(uint32_t hSession, uint8_t * pSignature, uint32_t ulSignatureLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11VerifyFinalFunc)(int64_t hSession, uint8_t * pSignature, int64_t ulSignatureLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11VerifyFinalFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pSignature, uint32_t ulSignatureLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11VerifyFinalFunc)(void * _ObjectData, int64_t hSession, uint8_t * pSignature, int64_t ulSignatureLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11VerifyRecoverInitFunc)(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11VerifyRecoverInitFunc)(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11VerifyRecoverInitFunc)(void * _ObjectData, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11VerifyRecoverInitFunc)(void * _ObjectData, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11VerifyRecoverFunc)(uint32_t hSession, uint8_t * pSignature, uint32_t ulSignatureLen, uint8_t * pData, uint32_t * pulDataLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11VerifyRecoverFunc)(int64_t hSession, uint8_t * pSignature, int64_t ulSignatureLen, uint8_t * pData, int64_t * pulDataLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11VerifyRecoverFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pSignature, uint32_t ulSignatureLen, uint8_t * pData, uint32_t * pulDataLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11VerifyRecoverFunc)(void * _ObjectData, int64_t hSession, uint8_t * pSignature, int64_t ulSignatureLen, uint8_t * pData, int64_t * pulDataLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DigestEncryptUpdateFunc)(uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint8_t * pEncryptedPart, uint32_t * pulEncryptedPartLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DigestEncryptUpdateFunc)(int64_t hSession, uint8_t * pPart, int64_t ulPartLen, uint8_t * pEncryptedPart, int64_t * pulEncryptedPartLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DigestEncryptUpdateFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint8_t * pEncryptedPart, uint32_t * pulEncryptedPartLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DigestEncryptUpdateFunc)(void * _ObjectData, int64_t hSession, uint8_t * pPart, int64_t ulPartLen, uint8_t * pEncryptedPart, int64_t * pulEncryptedPartLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DecryptDigestUpdateFunc)(uint32_t hSession, uint8_t * pEncryptedPart, uint32_t ulEncryptedPartLen, uint8_t * pPart, uint32_t * pulPartLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DecryptDigestUpdateFunc)(int64_t hSession, uint8_t * pEncryptedPart, int64_t ulEncryptedPartLen, uint8_t * pPart, int64_t * pulPartLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DecryptDigestUpdateFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pEncryptedPart, uint32_t ulEncryptedPartLen, uint8_t * pPart, uint32_t * pulPartLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DecryptDigestUpdateFunc)(void * _ObjectData, int64_t hSession, uint8_t * pEncryptedPart, int64_t ulEncryptedPartLen, uint8_t * pPart, int64_t * pulPartLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SignEncryptUpdateFunc)(uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint8_t * pEncryptedPart, uint32_t * pulEncryptedPartLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SignEncryptUpdateFunc)(int64_t hSession, uint8_t * pPart, int64_t ulPartLen, uint8_t * pEncryptedPart, int64_t * pulEncryptedPartLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SignEncryptUpdateFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint8_t * pEncryptedPart, uint32_t * pulEncryptedPartLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SignEncryptUpdateFunc)(void * _ObjectData, int64_t hSession, uint8_t * pPart, int64_t ulPartLen, uint8_t * pEncryptedPart, int64_t * pulEncryptedPartLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DecryptVerifyUpdateFunc)(uint32_t hSession, uint8_t * pEncryptedPart, uint32_t ulEncryptedPartLen, uint8_t * pPart, uint32_t * pulPartLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DecryptVerifyUpdateFunc)(int64_t hSession, uint8_t * pEncryptedPart, int64_t ulEncryptedPartLen, uint8_t * pPart, int64_t * pulPartLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DecryptVerifyUpdateFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pEncryptedPart, uint32_t ulEncryptedPartLen, uint8_t * pPart, uint32_t * pulPartLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DecryptVerifyUpdateFunc)(void * _ObjectData, int64_t hSession, uint8_t * pEncryptedPart, int64_t ulEncryptedPartLen, uint8_t * pPart, int64_t * pulPartLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GenerateKeyFunc)(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t * phKey, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GenerateKeyFunc)(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t * phKey, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GenerateKeyFunc)(void * _ObjectData, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t * phKey, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GenerateKeyFunc)(void * _ObjectData, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t * phKey, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GenerateKeyPairFunc)(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pPublicKeyTemplate, uint32_t ulPublicKeyAttributeCount, SB_CK_ATTRIBUTE_PTR pPrivateKeyTemplate, uint32_t ulPrivateKeyAttributeCount, uint32_t * phPublicKey, uint32_t * phPrivateKey, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GenerateKeyPairFunc)(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pPublicKeyTemplate, int64_t ulPublicKeyAttributeCount, SB_CK_ATTRIBUTE_PTR pPrivateKeyTemplate, int64_t ulPrivateKeyAttributeCount, int64_t * phPublicKey, int64_t * phPrivateKey, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GenerateKeyPairFunc)(void * _ObjectData, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pPublicKeyTemplate, uint32_t ulPublicKeyAttributeCount, SB_CK_ATTRIBUTE_PTR pPrivateKeyTemplate, uint32_t ulPrivateKeyAttributeCount, uint32_t * phPublicKey, uint32_t * phPrivateKey, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GenerateKeyPairFunc)(void * _ObjectData, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pPublicKeyTemplate, int64_t ulPublicKeyAttributeCount, SB_CK_ATTRIBUTE_PTR pPrivateKeyTemplate, int64_t ulPrivateKeyAttributeCount, int64_t * phPublicKey, int64_t * phPrivateKey, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11WrapKeyFunc)(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hWrappingKey, uint32_t hKey, uint8_t * pWrappedKey, uint32_t * pulWrappedKeyLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11WrapKeyFunc)(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hWrappingKey, int64_t hKey, uint8_t * pWrappedKey, int64_t * pulWrappedKeyLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11WrapKeyFunc)(void * _ObjectData, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hWrappingKey, uint32_t hKey, uint8_t * pWrappedKey, uint32_t * pulWrappedKeyLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11WrapKeyFunc)(void * _ObjectData, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hWrappingKey, int64_t hKey, uint8_t * pWrappedKey, int64_t * pulWrappedKeyLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11UnwrapKeyFunc)(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hUnwrappingKey, uint8_t * pWrappedKey, uint32_t ulWrappedKeyLen, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulAttributeCount, uint32_t * phKey, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11UnwrapKeyFunc)(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hUnwrappingKey, uint8_t * pWrappedKey, int64_t ulWrappedKeyLen, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulAttributeCount, int64_t * phKey, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11UnwrapKeyFunc)(void * _ObjectData, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hUnwrappingKey, uint8_t * pWrappedKey, uint32_t ulWrappedKeyLen, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulAttributeCount, uint32_t * phKey, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11UnwrapKeyFunc)(void * _ObjectData, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hUnwrappingKey, uint8_t * pWrappedKey, int64_t ulWrappedKeyLen, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulAttributeCount, int64_t * phKey, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DeriveKeyFunc)(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hBaseKey, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulAttributeCount, uint32_t * phKey, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11DeriveKeyFunc)(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hBaseKey, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulAttributeCount, int64_t * phKey, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DeriveKeyFunc)(void * _ObjectData, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hBaseKey, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulAttributeCount, uint32_t * phKey, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11DeriveKeyFunc)(void * _ObjectData, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hBaseKey, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulAttributeCount, int64_t * phKey, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SeedRandomFunc)(uint32_t hSession, uint8_t * pSeed, uint32_t ulSeedLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11SeedRandomFunc)(int64_t hSession, uint8_t * pSeed, int64_t ulSeedLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SeedRandomFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pSeed, uint32_t ulSeedLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11SeedRandomFunc)(void * _ObjectData, int64_t hSession, uint8_t * pSeed, int64_t ulSeedLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GenerateRandomFunc)(uint32_t hSession, uint8_t * pRandomData, uint32_t ulRandomLen, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GenerateRandomFunc)(int64_t hSession, uint8_t * pRandomData, int64_t ulRandomLen, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GenerateRandomFunc)(void * _ObjectData, uint32_t hSession, uint8_t * pRandomData, uint32_t ulRandomLen, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GenerateRandomFunc)(void * _ObjectData, int64_t hSession, uint8_t * pRandomData, int64_t ulRandomLen, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetFunctionStatusFunc)(uint32_t hSession, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11GetFunctionStatusFunc)(int64_t hSession, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetFunctionStatusFunc)(void * _ObjectData, uint32_t hSession, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11GetFunctionStatusFunc)(void * _ObjectData, int64_t hSession, int64_t * OutResult);
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11CancelFunctionFunc)(uint32_t hSession, uint32_t * OutResult);
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
typedef void (SB_CALLBACK *TPKCS11CancelFunctionFunc)(int64_t hSession, int64_t * OutResult);
#endif
#ifndef SB_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11CancelFunctionFunc)(void * _ObjectData, uint32_t hSession, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
typedef void (SB_CALLBACK *TPKCS11CancelFunctionFunc)(void * _ObjectData, int64_t hSession, int64_t * OutResult);
#endif

typedef uint8_t TElPKCS11CertificateTypeRaw;

typedef enum
{
	pctX509 = 0,
	pctWTLS = 1,
	pctAttribute = 2,
	pctVendorDefined = 3
} TElPKCS11CertificateType;

typedef uint8_t TElPKCS11CertificateCategoryRaw;

typedef enum
{
	pccUnspecified = 0,
	pccTokenUser = 1,
	pccAuthority = 2,
	pccOtherEntity = 3
} TElPKCS11CertificateCategory;

typedef uint8_t TElPKCS11NotificationFlagRaw;

typedef enum
{
	nfNone = 0,
	nfSurrender = 1
} TElPKCS11NotificationFlag;

typedef uint8_t TElPKCS11UserTypeRaw;

typedef enum
{
	utSecurityOfficer = 0,
	utUser = 1
} TElPKCS11UserType;

typedef uint8_t TElPKCS11KeyTypeRaw;

typedef enum
{
	ktRSA = 0,
	ktDSA = 1,
	ktDH = 2,
	ktEC = 3
} TElPKCS11KeyType;

typedef uint8_t TElPKCS11SessionStateRaw;

typedef enum
{
	stROPublicSession = 0,
	stROUserFunctions = 1,
	stRWPublicSession = 2,
	stRWUserFunctions = 3,
	stRWSOFunctions = 4
} TElPKCS11SessionState;

typedef uint8_t TSBPKCS11StorageOptionRaw;

typedef enum
{
	pcsoAutoRefreshSlotInfo = 0,
	pcsoCreatePublicKeyObjects = 1,
	pcsoOnDemandMode = 2,
	pcsoUniqueIDs = 3,
	pcsoNoSessionLevelNotifications = 4,
	pcsoWeakenedKeySearchCriteria = 5,
	pcsoNoImplicitSlotInfoUpdates = 6,
#ifndef SB_IOS
	pcsoInitTemplateForFind = 7,
	pcsoUseSystemProcAddresses = 8
#else
	pcsoInitTemplateForFind = 7
#endif
} TSBPKCS11StorageOption;

typedef uint32_t TSBPKCS11StorageOptionsRaw;

typedef enum 
{
	f_pcsoAutoRefreshSlotInfo = 1,
	f_pcsoCreatePublicKeyObjects = 2,
	f_pcsoOnDemandMode = 4,
	f_pcsoUniqueIDs = 8,
	f_pcsoNoSessionLevelNotifications = 16,
	f_pcsoWeakenedKeySearchCriteria = 32,
	f_pcsoNoImplicitSlotInfoUpdates = 64,
#ifndef SB_IOS
	f_pcsoInitTemplateForFind = 128,
	f_pcsoUseSystemProcAddresses = 256
#else
	f_pcsoInitTemplateForFind = 128
#endif
} TSBPKCS11StorageOptions;

typedef void (SB_CALLBACK *TElPKCSNotifyEvent)(void * _ObjectData, TObjectHandle Sender, TElPKCS11SessionInfoHandle SessionInfo, TElPKCS11NotificationFlagRaw NotificationFlag, int8_t * AbortOperation);

typedef void (SB_CALLBACK *TElPKCSSlotEventEvent)(void * _ObjectData, TObjectHandle Sender, TElPKCS11SlotInfoHandle Slot);

typedef uint8_t TSBPKCS11SlotEventMonitoringModeRaw;

typedef enum
{
	semNoMonitoring = 0,
	semStandard = 1,
	semSynchronous = 2
} TSBPKCS11SlotEventMonitoringMode;

#ifdef SB_IOS
typedef void (SB_CALLBACK *TSBUniqueIDNeededEvent)(void * _ObjectData, TObjectHandle Sender, char * pcID, int32_t * szID);

#ifndef CPU64
typedef void (SB_CALLBACK *TSBGetFunctionListNeededEvent)(void * _ObjectData, TObjectHandle Sender, PPKCS11FunctionList (* FunctionList), uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBGetFunctionListNeededEvent)(void * _ObjectData, TObjectHandle Sender, PPKCS11FunctionList (* FunctionList), int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBInitializeNeededEvent)(void * _ObjectData, TObjectHandle Sender, PPKCS11InitializeArgs pArgs, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBInitializeNeededEvent)(void * _ObjectData, TObjectHandle Sender, PPKCS11InitializeArgs pArgs, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBFinalizeNeededEvent)(void * _ObjectData, TObjectHandle Sender, void * pReserved, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBFinalizeNeededEvent)(void * _ObjectData, TObjectHandle Sender, void * pReserved, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBGetInfoNeededEvent)(void * _ObjectData, TObjectHandle Sender, TPKCS11Info * pInfo, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBGetInfoNeededEvent)(void * _ObjectData, TObjectHandle Sender, TPKCS11Info * pInfo, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBGetSlotListNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint8_t tokenPresent, uint32_t * pSlotList, uint32_t * pulCount, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBGetSlotListNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint8_t tokenPresent, int64_t * pSlotList, int64_t * pulCount, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBGetSlotInfoNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t slotID, TPKCS11SlotInfo * pInfo, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBGetSlotInfoNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t slotID, TPKCS11SlotInfo * pInfo, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBGetTokenInfoNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t slotID, TPKCS11TokenInfo * pInfo, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBGetTokenInfoNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t slotID, TPKCS11TokenInfo * pInfo, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBOpenSessionNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t slotID, uint32_t flags, void * CallbackData, void * NotifyProc, uint32_t * SessionHandle, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBOpenSessionNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t slotID, int64_t flags, void * CallbackData, void * NotifyProc, int64_t * SessionHandle, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBGetSessionInfoNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, TPKCS11SessionInfo * pInfo, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBGetSessionInfoNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, TPKCS11SessionInfo * pInfo, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBCloseSessionNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBCloseSessionNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBLoginNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint32_t userType, char * pPin, uint32_t ulPinLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBLoginNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, int64_t userType, char * pPin, int64_t ulPinLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBLogoutNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBLogoutNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBFindObjectsInitNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, SB_CK_ATTRIBUTE_PTR pAttributes, uint32_t ulCount, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBFindObjectsInitNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, SB_CK_ATTRIBUTE_PTR pAttributes, int64_t ulCount, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBFindObjectsNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint32_t * phObject, uint32_t ulMaxObjectCount, uint32_t * pulObjectCount, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBFindObjectsNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, int64_t * phObject, int64_t ulMaxObjectCount, int64_t * pulObjectCount, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBFindObjectsFinalNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBFindObjectsFinalNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBGetAttributeValueNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint32_t hObject, void * pTemplate, uint32_t ulCount, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBGetAttributeValueNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, int64_t hObject, void * pTemplate, int64_t ulCount, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBDestroyObjectNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint32_t hObject, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBDestroyObjectNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, int64_t hObject, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBCreateObjectNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t * hObject, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBCreateObjectNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t * hObject, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBSignInitNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBSignInitNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBSignNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pSignature, uint32_t * pulSignatureLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBSignNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pSignature, int64_t * pulSignatureLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBDecryptInitNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBDecryptInitNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBDecryptNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pEncryptedData, uint32_t ulEncryptedDataLen, uint8_t * pData, uint32_t * pulDataLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBDecryptNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pEncryptedData, int64_t ulEncryptedDataLen, uint8_t * pData, int64_t * pulDataLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBWaitForSlotEventNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t flags, uint32_t * pSlot, void * pReserved, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBWaitForSlotEventNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t flags, int64_t * pSlot, void * pReserved, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBGetMechanismListNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t slotID, uint32_t * pMechanismList, uint32_t * pulCount, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBGetMechanismListNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t slotID, int64_t * pMechanismList, int64_t * pulCount, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBGetMechanismInfoNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t slotID, uint32_t mechanism_type, TPKCS11MechanismInfo * pInfo, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBGetMechanismInfoNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t slotID, int64_t mechanism_type, TPKCS11MechanismInfo * pInfo, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBInitTokenNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t slotID, char * pPin, uint32_t ulPinLen, char * pLabel, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBInitTokenNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t slotID, char * pPin, int64_t ulPinLen, char * pLabel, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBInitPINNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, char * pPin, uint32_t ulPinLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBInitPINNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, char * pPin, int64_t ulPinLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBSetPINNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, char * pOldPin, uint32_t ulOldLen, char * pNewPin, uint32_t ulNewLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBSetPINNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, char * pOldPin, int64_t ulOldLen, char * pNewPin, int64_t ulNewLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBCloseAllSessionsNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t slotID, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBCloseAllSessionsNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t slotID, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBGetOperationStateNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pOperationState, uint32_t * pulOperationStateLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBGetOperationStateNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pOperationState, int64_t * pulOperationStateLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBSetOperationStateNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pOperationState, uint32_t ulOperationStateLen, uint32_t hEncryptionKey, uint32_t hAuthenticationKey, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBSetOperationStateNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pOperationState, int64_t ulOperationStateLen, int64_t hEncryptionKey, int64_t hAuthenticationKey, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBCopyObjectNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint32_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t * phNewObject, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBCopyObjectNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, int64_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t * phNewObject, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBGetObjectSizeNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint32_t hObject, uint32_t * pulSize, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBGetObjectSizeNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, int64_t hObject, int64_t * pulSize, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBSetAttributeValueNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint32_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBSetAttributeValueNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, int64_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBEncryptInitNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBEncryptInitNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBEncryptNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pEncryptedData, uint32_t * pulEncryptedDataLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBEncryptNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pEncryptedData, int64_t * pulEncryptedDataLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBEncryptUpdateNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint8_t * pEncryptedPart, uint32_t * pulEncryptedPartLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBEncryptUpdateNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pPart, int64_t ulPartLen, uint8_t * pEncryptedPart, int64_t * pulEncryptedPartLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBEncryptFinalNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pLastEncryptedPart, uint32_t * pulLastEncryptedPartLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBEncryptFinalNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pLastEncryptedPart, int64_t * pulLastEncryptedPartLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBDecryptUpdateNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pEncryptedPart, uint32_t ulEncryptedPartLen, uint8_t * pPart, uint32_t * pulPartLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBDecryptUpdateNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pEncryptedPart, int64_t ulEncryptedPartLen, uint8_t * pPart, int64_t * pulPartLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBDecryptFinalNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pLastPart, uint32_t * pulLastPartLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBDecryptFinalNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pLastPart, int64_t * pulLastPartLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBDigestInitNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBDigestInitNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBDigestNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pDigest, uint32_t * pulDigestLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBDigestNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pDigest, int64_t * pulDigestLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBDigestUpdateNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBDigestUpdateNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pPart, int64_t ulPartLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBDigestKeyNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint32_t hKey, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBDigestKeyNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, int64_t hKey, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBDigestFinalNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pDigest, uint32_t * pulDigestLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBDigestFinalNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pDigest, int64_t * pulDigestLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBSignUpdateNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBSignUpdateNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pPart, int64_t ulPartLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBSignFinalNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pSignature, uint32_t * pulSignatureLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBSignFinalNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pSignature, int64_t * pulSignatureLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBSignRecoverInitNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBSignRecoverInitNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBSignRecoverNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pSignature, uint32_t * pulSignatureLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBSignRecoverNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pSignature, int64_t * pulSignatureLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBVerifyInitNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBVerifyInitNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBVerifyNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pSignature, uint32_t ulSignatureLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBVerifyNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pSignature, int64_t ulSignatureLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBVerifyUpdateNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBVerifyUpdateNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pPart, int64_t ulPartLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBVerifyFinalNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pSignature, uint32_t ulSignatureLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBVerifyFinalNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pSignature, int64_t ulSignatureLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBVerifyRecoverInitNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBVerifyRecoverInitNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBVerifyRecoverNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pSignature, uint32_t ulSignatureLen, uint8_t * pData, uint32_t * pulDataLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBVerifyRecoverNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pSignature, int64_t ulSignatureLen, uint8_t * pData, int64_t * pulDataLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBDigestEncryptUpdateNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint8_t * pEncryptedPart, uint32_t * pulEncryptedPartLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBDigestEncryptUpdateNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pPart, int64_t ulPartLen, uint8_t * pEncryptedPart, int64_t * pulEncryptedPartLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBDecryptDigestUpdateNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pEncryptedPart, uint32_t ulEncryptedPartLen, uint8_t * pPart, uint32_t * pulPartLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBDecryptDigestUpdateNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pEncryptedPart, int64_t ulEncryptedPartLen, uint8_t * pPart, int64_t * pulPartLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBSignEncryptUpdateNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint8_t * pEncryptedPart, uint32_t * pulEncryptedPartLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBSignEncryptUpdateNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pPart, int64_t ulPartLen, uint8_t * pEncryptedPart, int64_t * pulEncryptedPartLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBDecryptVerifyUpdateNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pEncryptedPart, uint32_t ulEncryptedPartLen, uint8_t * pPart, uint32_t * pulPartLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBDecryptVerifyUpdateNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pEncryptedPart, int64_t ulEncryptedPartLen, uint8_t * pPart, int64_t * pulPartLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBGenerateKeyNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t * phKey, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBGenerateKeyNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t * phKey, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBGenerateKeyPairNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pPublicKeyTemplate, uint32_t ulPublicKeyAttributeCount, SB_CK_ATTRIBUTE_PTR pPrivateKeyTemplate, uint32_t ulPrivateKeyAttributeCount, uint32_t * phPublicKey, uint32_t * phPrivateKey, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBGenerateKeyPairNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pPublicKeyTemplate, int64_t ulPublicKeyAttributeCount, SB_CK_ATTRIBUTE_PTR pPrivateKeyTemplate, int64_t ulPrivateKeyAttributeCount, int64_t * phPublicKey, int64_t * phPrivateKey, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBWrapKeyNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hWrappingKey, uint32_t hKey, uint8_t * pWrappedKey, uint32_t * pulWrappedKeyLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBWrapKeyNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hWrappingKey, int64_t hKey, uint8_t * pWrappedKey, int64_t * pulWrappedKeyLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBUnwrapKeyNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hUnwrappingKey, uint8_t * pWrappedKey, uint32_t ulWrappedKeyLen, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulAttributeCount, uint32_t * phKey, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBUnwrapKeyNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hUnwrappingKey, uint8_t * pWrappedKey, int64_t ulWrappedKeyLen, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulAttributeCount, int64_t * phKey, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBDeriveKeyNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hBaseKey, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulAttributeCount, uint32_t * phKey, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBDeriveKeyNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hBaseKey, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulAttributeCount, int64_t * phKey, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBSeedRandomNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pSeed, uint32_t ulSeedLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBSeedRandomNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pSeed, int64_t ulSeedLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBGenerateRandomNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint8_t * pRandomData, uint32_t ulRandomLen, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBGenerateRandomNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, uint8_t * pRandomData, int64_t ulRandomLen, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBGetFunctionStatusNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBGetFunctionStatusNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, int64_t * Res);
#endif

#ifndef CPU64
typedef void (SB_CALLBACK *TSBCancelFunctionNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t hSession, uint32_t * Res);
#else
typedef void (SB_CALLBACK *TSBCancelFunctionNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t hSession, int64_t * Res);
#endif
#endif

typedef uint8_t TSBPKCS11ObjectTypeRaw;

typedef enum
{
	otUnknown = 0,
	otData = 1,
	otCertificate = 2,
	otX509Certificate = 3,
	otWTLSCertificate = 4,
	otX509AttributeCertificate = 5,
	otPublicKey = 6,
	otPrivateKey = 7,
	otSecretKey = 8,
	otHardwareFeature = 9,
	otDomainParameters = 10,
	otMechanism = 11,
	otVendorDefined = 12
} TSBPKCS11ObjectType;

typedef TElClassHandle TElPKCS11ObjectClassHandle;

typedef uint8_t TSBPKCS11CertCategoryRaw;

typedef enum
{
	ccUnspecified = 0,
	ccTokenUser = 1,
	ccAuthority = 2,
	ccOtherEntity = 3
} TSBPKCS11CertCategory;

typedef uint8_t TSBPKCS11CertTypeRaw;

typedef enum
{
	ctX509 = 0,
	ctWTLS = 1,
	ctAttribute = 2
} TSBPKCS11CertType;

typedef uint8_t TSBPKCS11MIDPSecurityDomainRaw;

typedef enum
{
	msdUnspecified = 0,
	msdManufacturer = 1,
	msdOperator = 2,
	msdThirdParty = 3
} TSBPKCS11MIDPSecurityDomain;

typedef uint8_t TSBPKCS11TokenAccessModeRaw;

typedef enum
{
	tamCompatible = 0,
	tamFull = 1
} TSBPKCS11TokenAccessMode;

typedef void (SB_CALLBACK *TElSlotEventMonitoringThreadEvent)(void * _ObjectData, TObjectHandle Sender, uint32_t SlotID);

#ifdef SB_USE_CLASS_TELPKCS11MODULE
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Module_CloseSession(TElPKCS11ModuleHandle _Handle, TElPKCS11SessionInfoHandle SessionInfo, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Module_GetFunctionList(TElPKCS11ModuleHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Module_OpenSession(TElPKCS11ModuleHandle _Handle, int32_t SlotIndex, int8_t ReadOnly, TElPKCS11ConsumerHandle Consumer, TElPKCS11SessionInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Module_OpenSessionEx(TElPKCS11ModuleHandle _Handle, int32_t SlotIndex, int8_t ReadOnly, TElPKCS11ConsumerHandle Consumer, int8_t RequestNotifications, TElPKCS11SessionInfoHandle * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Module_GetSessionByHandle(TElPKCS11ModuleHandle _Handle, uint32_t Handle, TElPKCS11SessionInfoHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Module_GetSessionByHandle(TElPKCS11ModuleHandle _Handle, int64_t Handle, TElPKCS11SessionInfoHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Module_InitToken(TElPKCS11ModuleHandle _Handle, int32_t SlotIndex, const char * pcPin, int32_t szPin, const char * pcTokenLabel, int32_t szTokenLabel);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Module_get_ProviderDescription(TElPKCS11ModuleHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Module_set_ProviderDescription(TElPKCS11ModuleHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Module_get_Session(TElPKCS11ModuleHandle _Handle, int32_t Index, TElPKCS11SessionInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Module_get_SessionCount(TElPKCS11ModuleHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Module_get_Slot(TElPKCS11ModuleHandle _Handle, int32_t Index, TElPKCS11SlotInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Module_get_SlotCount(TElPKCS11ModuleHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Module_get_UniqueID(TElPKCS11ModuleHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
#ifndef SB_CPU64_OR_IOS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Module_get_HLib(TElPKCS11ModuleHandle _Handle, uint32_t * OutResult);
#endif
#ifndef SB_NOT_CPU64_OR_IOS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Module_get_HLib(TElPKCS11ModuleHandle _Handle, int64_t * OutResult);
#endif
#ifndef SB_IOS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Module_get_UseGetFunctionList(TElPKCS11ModuleHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Module_set_UseGetFunctionList(TElPKCS11ModuleHandle _Handle, int8_t Value);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Module_get_HLib(TElPKCS11ModuleHandle _Handle, TElPKCS11FunctionsManagerHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Module_Create(TElPKCS11ModuleHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_AddConsumer(TElPKCS11SlotInfoHandle _Handle, TElPKCS11ConsumerHandle Consumer);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_PinNeeded(TElPKCS11SlotInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_Refresh(TElPKCS11SlotInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_RefreshSlot(TElPKCS11SlotInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_RefreshSupportedAlgorithms(TElPKCS11SlotInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_RemoveConsumer(TElPKCS11SlotInfoHandle _Handle, TElPKCS11ConsumerHandle Consumer);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_ConsumerCount(TElPKCS11SlotInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_LoggedIn(TElPKCS11SlotInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_ReadOnly(TElPKCS11SlotInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_SlotManufacturerID(TElPKCS11SlotInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_SlotDescription(TElPKCS11SlotInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_SlotHardwareVersionHi(TElPKCS11SlotInfoHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_SlotFirmwareVersionHi(TElPKCS11SlotInfoHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_SlotHardwareVersionLo(TElPKCS11SlotInfoHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_SlotFirmwareVersionLo(TElPKCS11SlotInfoHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_TokenPresent(TElPKCS11SlotInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_TokenHardwareVersionHi(TElPKCS11SlotInfoHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_TokenFirmwareVersionHi(TElPKCS11SlotInfoHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_TokenHardwareVersionLo(TElPKCS11SlotInfoHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_TokenFirmwareVersionLo(TElPKCS11SlotInfoHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_TokenManufacturerID(TElPKCS11SlotInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_TokenLabel(TElPKCS11SlotInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_TokenModel(TElPKCS11SlotInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_TokenSerial(TElPKCS11SlotInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_TokenFlags(TElPKCS11SlotInfoHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_Module(TElPKCS11SlotInfoHandle _Handle, TElPKCS11ModuleHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_Consumers(TElPKCS11SlotInfoHandle _Handle, int32_t Index, TElPKCS11ConsumerHandle * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_SupportedPKCS11Mechanisms(TElPKCS11SlotInfoHandle _Handle, int32_t Index, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_SlotID(TElPKCS11SlotInfoHandle _Handle, uint32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_SupportedPKCS11Mechanisms(TElPKCS11SlotInfoHandle _Handle, int32_t Index, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_SlotID(TElPKCS11SlotInfoHandle _Handle, int64_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_get_SupportedPKCS11MechanismCount(TElPKCS11SlotInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SlotInfo_Create(TElPKCS11SlotInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_AddObject(TElPKCS11SessionInfoHandle _Handle, TSBPKCS11ObjectTypeRaw ObjectType, int8_t Token, int8_t Private, int8_t Modifiable, TElPKCS11AttributeListHandle Attributes, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_AddObject_1(TElPKCS11SessionInfoHandle _Handle, TSBPKCS11ObjectTypeRaw ObjectType, int8_t Token, TElPKCS11AttributeListHandle Attributes, int32_t * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_AddGeneratedObject(TElPKCS11SessionInfoHandle _Handle, uint32_t Handle, int32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_AddGeneratedObject(TElPKCS11SessionInfoHandle _Handle, int64_t Handle, int32_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_RemoveObject(TElPKCS11SessionInfoHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_RemoveObject_1(TElPKCS11SessionInfoHandle _Handle, TElPKCS11ObjectHandle Obj);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_RemoveObjectByHandle(TElPKCS11SessionInfoHandle _Handle, uint32_t Handle);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_RemoveObjectByHandle(TElPKCS11SessionInfoHandle _Handle, int64_t Handle);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_ClearObjects(TElPKCS11SessionInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_CopyObject(TElPKCS11SessionInfoHandle _Handle, int32_t Index, int8_t Token, int8_t Private, int8_t Modifiable, TElPKCS11AttributeListHandle Attributes, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_CopyObject_1(TElPKCS11SessionInfoHandle _Handle, TElPKCS11ObjectHandle Obj, int8_t Token, int8_t Private, int8_t Modifiable, TElPKCS11AttributeListHandle Attributes, int32_t * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_GetObjectByHandle(TElPKCS11SessionInfoHandle _Handle, uint32_t Handle, TElPKCS11ObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_GetObjectByHandle(TElPKCS11SessionInfoHandle _Handle, int64_t Handle, TElPKCS11ObjectHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_GetObjectBySubjectOrID(TElPKCS11SessionInfoHandle _Handle, TSBPKCS11ObjectTypeRaw ObjectType, const uint8_t pSubject[], int32_t szSubject, const uint8_t pID[], int32_t szID, TElPKCS11ObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_GetObjectBySubjectOrID_1(TElPKCS11SessionInfoHandle _Handle, TSBPKCS11ObjectTypeRaw ObjectType, const uint8_t pSubject[], int32_t szSubject, const uint8_t pID[], int32_t szID, int8_t SubjectMustMatch, int8_t IDMustMatch, TElPKCS11ObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_Close(TElPKCS11SessionInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_Login(TElPKCS11SessionInfoHandle _Handle, TElPKCS11UserTypeRaw UserType, const char * pcPIN, int32_t szPIN);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_Logout(TElPKCS11SessionInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_ClearObjectInstances(TElPKCS11SessionInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_RefreshObjectList(TElPKCS11SessionInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_UpdateObjectList(TElPKCS11SessionInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_AcquireSession(TElPKCS11SessionInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_ReleaseSession(TElPKCS11SessionInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_InitPIN(TElPKCS11SessionInfoHandle _Handle, const char * pcPin, int32_t szPin);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_SetPIN(TElPKCS11SessionInfoHandle _Handle, const char * pcOldPin, int32_t szOldPin, const char * pcNewPin, int32_t szNewPin);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_get_Consumer(TElPKCS11SessionInfoHandle _Handle, TElPKCS11ConsumerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_get_Slot(TElPKCS11SessionInfoHandle _Handle, TElPKCS11SlotInfoHandle * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_get_Handle(TElPKCS11SessionInfoHandle _Handle, uint32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_get_Handle(TElPKCS11SessionInfoHandle _Handle, int64_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_get_CryptoProvider(TElPKCS11SessionInfoHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_set_CryptoProvider(TElPKCS11SessionInfoHandle _Handle, TElCustomCryptoProviderHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_get_ObjectCount(TElPKCS11SessionInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_get_TokenAccessMode(TElPKCS11SessionInfoHandle _Handle, TSBPKCS11TokenAccessModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_set_TokenAccessMode(TElPKCS11SessionInfoHandle _Handle, TSBPKCS11TokenAccessModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_get_IsOnDemandSession(TElPKCS11SessionInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_get_Objects(TElPKCS11SessionInfoHandle _Handle, int32_t Index, TElPKCS11ObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_get_TokenProps(TElPKCS11SessionInfoHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SessionInfo_Create(TElPKCS11SessionInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

#ifdef SB_IOS
#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
#ifndef CPU64
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetFunctionList(TElPKCS11FunctionsManagerHandle _Handle, PPKCS11FunctionList * FunctionList, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_Initialize(TElPKCS11FunctionsManagerHandle _Handle, PPKCS11InitializeArgs pArgs, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_Finalize(TElPKCS11FunctionsManagerHandle _Handle, void * pReserved, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetInfo(TElPKCS11FunctionsManagerHandle _Handle, TPKCS11Info * pInfo, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetSlotList(TElPKCS11FunctionsManagerHandle _Handle, uint8_t tokenPresent, uint32_t * pSlotList, uint32_t * pulCount, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetSlotInfo(TElPKCS11FunctionsManagerHandle _Handle, uint32_t slotID, TPKCS11SlotInfo * pInfo, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetTokenInfo(TElPKCS11FunctionsManagerHandle _Handle, uint32_t slotID, TPKCS11TokenInfo * pInfo, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_OpenSession(TElPKCS11FunctionsManagerHandle _Handle, uint32_t slotID, uint32_t flags, void * CallbackData, void * NotifyProc, uint32_t * SessionHandle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetSessionInfo(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, TPKCS11SessionInfo * pInfo, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_CloseSession(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_Login(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint32_t userType, char * pPin, uint32_t ulPinLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_Logout(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_FindObjectsInit(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, SB_CK_ATTRIBUTE_PTR pAttributes, uint32_t ulCount, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_FindObjects(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint32_t * phObject, uint32_t ulMaxObjectCount, uint32_t * pulObjectCount, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_FindObjectsFinal(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetAttributeValue(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint32_t hObject, void * pTemplate, uint32_t ulCount, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DestroyObject(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint32_t hObject, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_CreateObject(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t * hObject, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_SignInit(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_Sign(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pSignature, uint32_t * pulSignatureLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DecryptInit(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_Decrypt(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pEncryptedData, uint32_t ulEncryptedDataLen, uint8_t * pData, uint32_t * pulDataLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_WaitForSlotEvent(TElPKCS11FunctionsManagerHandle _Handle, uint32_t flags, uint32_t * pSlot, void * pReserved, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetMechanismList(TElPKCS11FunctionsManagerHandle _Handle, uint32_t slotID, uint32_t * pMechanismList, uint32_t * pulCount, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetMechanismInfo(TElPKCS11FunctionsManagerHandle _Handle, uint32_t slotID, uint32_t mechanism_type, TPKCS11MechanismInfo * pInfo, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_InitToken(TElPKCS11FunctionsManagerHandle _Handle, uint32_t slotID, char * pPin, uint32_t ulPinLen, char * pLabel, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_InitPIN(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, char * pPin, uint32_t ulPinLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_SetPIN(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, char * pOldPin, uint32_t ulOldLen, char * pNewPin, uint32_t ulNewLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_CloseAllSessions(TElPKCS11FunctionsManagerHandle _Handle, uint32_t slotID, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetOperationState(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pOperationState, uint32_t * pulOperationStateLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_SetOperationState(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pOperationState, uint32_t ulOperationStateLen, uint32_t hEncryptionKey, uint32_t hAuthenticationKey, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_CopyObject(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint32_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t * phNewObject, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetObjectSize(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint32_t hObject, uint32_t * pulSize, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_SetAttributeValue(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint32_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_EncryptInit(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_Encrypt(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pEncryptedData, uint32_t * pulEncryptedDataLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_EncryptUpdate(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint8_t * pEncryptedPart, uint32_t * pulEncryptedPartLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_EncryptFinal(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pLastEncryptedPart, uint32_t * pulLastEncryptedPartLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DecryptUpdate(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pEncryptedPart, uint32_t ulEncryptedPartLen, uint8_t * pPart, uint32_t * pulPartLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DecryptFinal(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pLastPart, uint32_t * pulLastPartLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DigestInit(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_Digest(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pDigest, uint32_t * pulDigestLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DigestUpdate(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DigestKey(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint32_t hKey, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DigestFinal(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pDigest, uint32_t * pulDigestLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_SignUpdate(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_SignFinal(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pSignature, uint32_t * pulSignatureLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_SignRecoverInit(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_SignRecover(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pSignature, uint32_t * pulSignatureLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_VerifyInit(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_Verify(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pSignature, uint32_t ulSignatureLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_VerifyUpdate(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_VerifyFinal(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pSignature, uint32_t ulSignatureLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_VerifyRecoverInit(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_VerifyRecover(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pSignature, uint32_t ulSignatureLen, uint8_t * pData, uint32_t * pulDataLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DigestEncryptUpdate(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint8_t * pEncryptedPart, uint32_t * pulEncryptedPartLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DecryptDigestUpdate(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pEncryptedPart, uint32_t ulEncryptedPartLen, uint8_t * pPart, uint32_t * pulPartLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_SignEncryptUpdate(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint8_t * pEncryptedPart, uint32_t * pulEncryptedPartLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DecryptVerifyUpdate(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pEncryptedPart, uint32_t ulEncryptedPartLen, uint8_t * pPart, uint32_t * pulPartLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GenerateKey(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t * phKey, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GenerateKeyPair(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pPublicKeyTemplate, uint32_t ulPublicKeyAttributeCount, SB_CK_ATTRIBUTE_PTR pPrivateKeyTemplate, uint32_t ulPrivateKeyAttributeCount, uint32_t * phPublicKey, uint32_t * phPrivateKey, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_WrapKey(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hWrappingKey, uint32_t hKey, uint8_t * pWrappedKey, uint32_t * pulWrappedKeyLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_UnwrapKey(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hUnwrappingKey, uint8_t * pWrappedKey, uint32_t ulWrappedKeyLen, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulAttributeCount, uint32_t * phKey, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DeriveKey(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hBaseKey, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulAttributeCount, uint32_t * phKey, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_SeedRandom(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pSeed, uint32_t ulSeedLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GenerateRandom(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint8_t * pRandomData, uint32_t ulRandomLen, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetFunctionStatus(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_CancelFunction(TElPKCS11FunctionsManagerHandle _Handle, uint32_t hSession, uint32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetFunctionList(TElPKCS11FunctionsManagerHandle _Handle, PPKCS11FunctionList * FunctionList, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_Initialize(TElPKCS11FunctionsManagerHandle _Handle, PPKCS11InitializeArgs pArgs, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_Finalize(TElPKCS11FunctionsManagerHandle _Handle, void * pReserved, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetInfo(TElPKCS11FunctionsManagerHandle _Handle, TPKCS11Info * pInfo, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetSlotList(TElPKCS11FunctionsManagerHandle _Handle, uint8_t tokenPresent, int64_t * pSlotList, int64_t * pulCount, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetSlotInfo(TElPKCS11FunctionsManagerHandle _Handle, int64_t slotID, TPKCS11SlotInfo * pInfo, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetTokenInfo(TElPKCS11FunctionsManagerHandle _Handle, int64_t slotID, TPKCS11TokenInfo * pInfo, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_OpenSession(TElPKCS11FunctionsManagerHandle _Handle, int64_t slotID, int64_t flags, void * CallbackData, void * NotifyProc, int64_t * SessionHandle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetSessionInfo(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, TPKCS11SessionInfo * pInfo, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_CloseSession(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_Login(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, int64_t userType, char * pPin, int64_t ulPinLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_Logout(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_FindObjectsInit(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, SB_CK_ATTRIBUTE_PTR pAttributes, int64_t ulCount, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_FindObjects(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, int64_t * phObject, int64_t ulMaxObjectCount, int64_t * pulObjectCount, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_FindObjectsFinal(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetAttributeValue(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, int64_t hObject, void * pTemplate, int64_t ulCount, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DestroyObject(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, int64_t hObject, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_CreateObject(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t * hObject, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_SignInit(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_Sign(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pSignature, int64_t * pulSignatureLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DecryptInit(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_Decrypt(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pEncryptedData, int64_t ulEncryptedDataLen, uint8_t * pData, int64_t * pulDataLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_WaitForSlotEvent(TElPKCS11FunctionsManagerHandle _Handle, int64_t flags, int64_t * pSlot, void * pReserved, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetMechanismList(TElPKCS11FunctionsManagerHandle _Handle, int64_t slotID, int64_t * pMechanismList, int64_t * pulCount, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetMechanismInfo(TElPKCS11FunctionsManagerHandle _Handle, int64_t slotID, int64_t mechanism_type, TPKCS11MechanismInfo * pInfo, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_InitToken(TElPKCS11FunctionsManagerHandle _Handle, int64_t slotID, char * pPin, int64_t ulPinLen, char * pLabel, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_InitPIN(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, char * pPin, int64_t ulPinLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_SetPIN(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, char * pOldPin, int64_t ulOldLen, char * pNewPin, int64_t ulNewLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_CloseAllSessions(TElPKCS11FunctionsManagerHandle _Handle, int64_t slotID, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetOperationState(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pOperationState, int64_t * pulOperationStateLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_SetOperationState(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pOperationState, int64_t ulOperationStateLen, int64_t hEncryptionKey, int64_t hAuthenticationKey, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_CopyObject(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, int64_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t * phNewObject, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetObjectSize(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, int64_t hObject, int64_t * pulSize, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_SetAttributeValue(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, int64_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_EncryptInit(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_Encrypt(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pEncryptedData, int64_t * pulEncryptedDataLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_EncryptUpdate(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pPart, int64_t ulPartLen, uint8_t * pEncryptedPart, int64_t * pulEncryptedPartLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_EncryptFinal(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pLastEncryptedPart, int64_t * pulLastEncryptedPartLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DecryptUpdate(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pEncryptedPart, int64_t ulEncryptedPartLen, uint8_t * pPart, int64_t * pulPartLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DecryptFinal(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pLastPart, int64_t * pulLastPartLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DigestInit(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_Digest(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pDigest, int64_t * pulDigestLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DigestUpdate(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pPart, int64_t ulPartLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DigestKey(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, int64_t hKey, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DigestFinal(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pDigest, int64_t * pulDigestLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_SignUpdate(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pPart, int64_t ulPartLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_SignFinal(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pSignature, int64_t * pulSignatureLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_SignRecoverInit(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_SignRecover(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pSignature, int64_t * pulSignatureLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_VerifyInit(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_Verify(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pSignature, int64_t ulSignatureLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_VerifyUpdate(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pPart, int64_t ulPartLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_VerifyFinal(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pSignature, int64_t ulSignatureLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_VerifyRecoverInit(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_VerifyRecover(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pSignature, int64_t ulSignatureLen, uint8_t * pData, int64_t * pulDataLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DigestEncryptUpdate(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pPart, int64_t ulPartLen, uint8_t * pEncryptedPart, int64_t * pulEncryptedPartLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DecryptDigestUpdate(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pEncryptedPart, int64_t ulEncryptedPartLen, uint8_t * pPart, int64_t * pulPartLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_SignEncryptUpdate(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pPart, int64_t ulPartLen, uint8_t * pEncryptedPart, int64_t * pulEncryptedPartLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DecryptVerifyUpdate(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pEncryptedPart, int64_t ulEncryptedPartLen, uint8_t * pPart, int64_t * pulPartLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GenerateKey(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t * phKey, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GenerateKeyPair(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pPublicKeyTemplate, int64_t ulPublicKeyAttributeCount, SB_CK_ATTRIBUTE_PTR pPrivateKeyTemplate, int64_t ulPrivateKeyAttributeCount, int64_t * phPublicKey, int64_t * phPrivateKey, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_WrapKey(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hWrappingKey, int64_t hKey, uint8_t * pWrappedKey, int64_t * pulWrappedKeyLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_UnwrapKey(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hUnwrappingKey, uint8_t * pWrappedKey, int64_t ulWrappedKeyLen, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulAttributeCount, int64_t * phKey, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_DeriveKey(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hBaseKey, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulAttributeCount, int64_t * phKey, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_SeedRandom(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pSeed, int64_t ulSeedLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GenerateRandom(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, uint8_t * pRandomData, int64_t ulRandomLen, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_GetFunctionStatus(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_CancelFunction(TElPKCS11FunctionsManagerHandle _Handle, int64_t hSession, int64_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_UniqueID(TElPKCS11FunctionsManagerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnUniqueIDNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBUniqueIDNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnUniqueIDNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBUniqueIDNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnGetFunctionListNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetFunctionListNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnGetFunctionListNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetFunctionListNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnInitializeNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBInitializeNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnInitializeNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBInitializeNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnFinalizeNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBFinalizeNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnFinalizeNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBFinalizeNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnGetInfoNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetInfoNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnGetInfoNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetInfoNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnGetSlotListNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetSlotListNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnGetSlotListNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetSlotListNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnGetSlotInfoNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetSlotInfoNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnGetSlotInfoNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetSlotInfoNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnGetTokenInfoNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetTokenInfoNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnGetTokenInfoNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetTokenInfoNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnOpenSessionNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBOpenSessionNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnOpenSessionNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBOpenSessionNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnGetSessionInfoNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetSessionInfoNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnGetSessionInfoNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetSessionInfoNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnCloseSessionNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBCloseSessionNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnCloseSessionNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBCloseSessionNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnLoginNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBLoginNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnLoginNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBLoginNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnLogoutNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBLogoutNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnLogoutNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBLogoutNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnFindObjectsInitNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBFindObjectsInitNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnFindObjectsInitNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBFindObjectsInitNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnFindObjectsNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBFindObjectsNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnFindObjectsNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBFindObjectsNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnFindObjectsFinalNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBFindObjectsFinalNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnFindObjectsFinalNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBFindObjectsFinalNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnGetAttributeValueNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetAttributeValueNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnGetAttributeValueNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetAttributeValueNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnDestroyObjectNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDestroyObjectNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnDestroyObjectNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDestroyObjectNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnCreateObjectNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBCreateObjectNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnCreateObjectNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBCreateObjectNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnSignInitNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSignInitNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnSignInitNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSignInitNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnSignNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSignNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnSignNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSignNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnDecryptInitNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDecryptInitNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnDecryptInitNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDecryptInitNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnDecryptNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDecryptNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnDecryptNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDecryptNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnWaitForSlotEventNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBWaitForSlotEventNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnWaitForSlotEventNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBWaitForSlotEventNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnGetMechanismListNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetMechanismListNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnGetMechanismListNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetMechanismListNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnGetMechanismInfoNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetMechanismInfoNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnGetMechanismInfoNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetMechanismInfoNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnInitTokenNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBInitTokenNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnInitTokenNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBInitTokenNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnInitPINNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBInitPINNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnInitPINNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBInitPINNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnSetPINNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSetPINNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnSetPINNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSetPINNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnCloseAllSessionsNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBCloseAllSessionsNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnCloseAllSessionsNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBCloseAllSessionsNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnGetOperationStateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetOperationStateNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnGetOperationStateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetOperationStateNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnSetOperationStateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSetOperationStateNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnSetOperationStateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSetOperationStateNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnCopyObjectNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBCopyObjectNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnCopyObjectNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBCopyObjectNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnGetObjectSizeNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetObjectSizeNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnGetObjectSizeNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetObjectSizeNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnSetAttributeValueNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSetAttributeValueNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnSetAttributeValueNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSetAttributeValueNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnEncryptInitNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBEncryptInitNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnEncryptInitNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBEncryptInitNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnEncryptNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBEncryptNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnEncryptNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBEncryptNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnEncryptUpdateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBEncryptUpdateNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnEncryptUpdateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBEncryptUpdateNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnEncryptFinalNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBEncryptFinalNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnEncryptFinalNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBEncryptFinalNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnDecryptUpdateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDecryptUpdateNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnDecryptUpdateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDecryptUpdateNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnDecryptFinalNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDecryptFinalNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnDecryptFinalNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDecryptFinalNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnDigestInitNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDigestInitNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnDigestInitNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDigestInitNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnDigestNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDigestNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnDigestNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDigestNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnDigestUpdateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDigestUpdateNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnDigestUpdateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDigestUpdateNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnDigestKeyNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDigestKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnDigestKeyNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDigestKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnDigestFinalNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDigestFinalNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnDigestFinalNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDigestFinalNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnSignUpdateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSignUpdateNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnSignUpdateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSignUpdateNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnSignFinalNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSignFinalNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnSignFinalNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSignFinalNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnSignRecoverInitNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSignRecoverInitNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnSignRecoverInitNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSignRecoverInitNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnSignRecoverNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSignRecoverNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnSignRecoverNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSignRecoverNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnVerifyInitNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBVerifyInitNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnVerifyInitNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBVerifyInitNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnVerifyNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBVerifyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnVerifyNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBVerifyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnVerifyUpdateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBVerifyUpdateNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnVerifyUpdateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBVerifyUpdateNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnVerifyFinalNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBVerifyFinalNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnVerifyFinalNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBVerifyFinalNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnVerifyRecoverInitNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBVerifyRecoverInitNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnVerifyRecoverInitNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBVerifyRecoverInitNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnVerifyRecoverNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBVerifyRecoverNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnVerifyRecoverNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBVerifyRecoverNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnDigestEncryptUpdateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDigestEncryptUpdateNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnDigestEncryptUpdateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDigestEncryptUpdateNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnDecryptDigestUpdateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDecryptDigestUpdateNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnDecryptDigestUpdateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDecryptDigestUpdateNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnSignEncryptUpdateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSignEncryptUpdateNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnSignEncryptUpdateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSignEncryptUpdateNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnDecryptVerifyUpdateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDecryptVerifyUpdateNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnDecryptVerifyUpdateNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDecryptVerifyUpdateNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnGenerateKeyNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGenerateKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnGenerateKeyNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGenerateKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnGenerateKeyPairNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGenerateKeyPairNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnGenerateKeyPairNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGenerateKeyPairNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnWrapKeyNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBWrapKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnWrapKeyNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBWrapKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnUnwrapKeyNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBUnwrapKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnUnwrapKeyNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBUnwrapKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnDeriveKeyNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDeriveKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnDeriveKeyNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBDeriveKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnSeedRandomNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSeedRandomNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnSeedRandomNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBSeedRandomNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnGenerateRandomNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGenerateRandomNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnGenerateRandomNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGenerateRandomNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnGetFunctionStatusNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetFunctionStatusNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnGetFunctionStatusNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBGetFunctionStatusNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_get_OnCancelFunctionNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBCancelFunctionNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_set_OnCancelFunctionNeeded(TElPKCS11FunctionsManagerHandle _Handle, TSBCancelFunctionNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11FunctionsManager_Create(TElPKCS11FunctionsManagerHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */
#endif

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Consumer_get_UniqueID(TElPKCS11ConsumerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Consumer_Create(TElPKCS11ConsumerHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_Assign(TElPKCS11AttributeListHandle _Handle, TElPKCS11AttributeListHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_Add(TElPKCS11AttributeListHandle _Handle, int32_t * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_Add_1(TElPKCS11AttributeListHandle _Handle, uint32_t Attribute, const uint8_t pValue[], int32_t szValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_Add_2(TElPKCS11AttributeListHandle _Handle, uint32_t Attribute, uint32_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_Add_3(TElPKCS11AttributeListHandle _Handle, uint32_t Attribute, int8_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_AddByte(TElPKCS11AttributeListHandle _Handle, uint32_t Attribute, uint8_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_AddWord(TElPKCS11AttributeListHandle _Handle, uint32_t Attribute, uint16_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_AddThreeByteInteger(TElPKCS11AttributeListHandle _Handle, uint32_t Attribute, uint32_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_AddIntegerOptEnc(TElPKCS11AttributeListHandle _Handle, uint32_t Attribute, uint32_t Value, int32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_Add_1(TElPKCS11AttributeListHandle _Handle, int64_t Attribute, const uint8_t pValue[], int32_t szValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_Add_2(TElPKCS11AttributeListHandle _Handle, int64_t Attribute, int64_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_Add_3(TElPKCS11AttributeListHandle _Handle, int64_t Attribute, int8_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_AddByte(TElPKCS11AttributeListHandle _Handle, int64_t Attribute, uint8_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_AddWord(TElPKCS11AttributeListHandle _Handle, int64_t Attribute, uint16_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_AddThreeByteInteger(TElPKCS11AttributeListHandle _Handle, int64_t Attribute, int64_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_AddIntegerOptEnc(TElPKCS11AttributeListHandle _Handle, int64_t Attribute, int64_t Value, int32_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_Insert(TElPKCS11AttributeListHandle _Handle, int32_t Index);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_Insert_1(TElPKCS11AttributeListHandle _Handle, int32_t Index, uint32_t Attribute, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_Insert_2(TElPKCS11AttributeListHandle _Handle, int32_t Index, uint32_t Attribute, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_Insert_3(TElPKCS11AttributeListHandle _Handle, int32_t Index, uint32_t Attribute, int8_t Value);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_Insert_1(TElPKCS11AttributeListHandle _Handle, int32_t Index, int64_t Attribute, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_Insert_2(TElPKCS11AttributeListHandle _Handle, int32_t Index, int64_t Attribute, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_Insert_3(TElPKCS11AttributeListHandle _Handle, int32_t Index, int64_t Attribute, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_Remove(TElPKCS11AttributeListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_Clear(TElPKCS11AttributeListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_Serialize(TElPKCS11AttributeListHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_ToString(TElPKCS11AttributeListHandle _Handle, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_get_Attributes(TElPKCS11AttributeListHandle _Handle, int32_t Index, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_set_Attributes(TElPKCS11AttributeListHandle _Handle, int32_t Index, uint32_t Value);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_get_Attributes(TElPKCS11AttributeListHandle _Handle, int32_t Index, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_set_Attributes(TElPKCS11AttributeListHandle _Handle, int32_t Index, int64_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_get_Values(TElPKCS11AttributeListHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_set_Values(TElPKCS11AttributeListHandle _Handle, int32_t Index, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_get_Count(TElPKCS11AttributeListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_set_Count(TElPKCS11AttributeListHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AttributeList_Create(TElPKCS11AttributeListHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_SetAttribute(TElPKCS11ObjectHandle _Handle, uint32_t Attribute, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_SetAttribute_1(TElPKCS11ObjectHandle _Handle, uint32_t Attribute, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_SetAttribute_2(TElPKCS11ObjectHandle _Handle, uint32_t Attribute, int8_t Value);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_SetAttribute(TElPKCS11ObjectHandle _Handle, int64_t Attribute, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_SetAttribute_1(TElPKCS11ObjectHandle _Handle, int64_t Attribute, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_SetAttribute_2(TElPKCS11ObjectHandle _Handle, int64_t Attribute, int8_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_SetAttributes(TElPKCS11ObjectHandle _Handle, TElPKCS11AttributeListHandle Attributes);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_GetAttribute(TElPKCS11ObjectHandle _Handle, uint32_t Attribute, uint8_t pOutResult[], int32_t * szOutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_GetAttribute(TElPKCS11ObjectHandle _Handle, int64_t Attribute, uint8_t pOutResult[], int32_t * szOutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_ReadProperties(TElPKCS11ObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_get_ObjectType(TElPKCS11ObjectHandle _Handle, TSBPKCS11ObjectTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_get_Token(TElPKCS11ObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_get_Private(TElPKCS11ObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_get_Modifiable(TElPKCS11ObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_get_ObjectLabel(TElPKCS11ObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_set_ObjectLabel(TElPKCS11ObjectHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_get_ObjectSize(TElPKCS11ObjectHandle _Handle, int32_t * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_get_Handle(TElPKCS11ObjectHandle _Handle, uint32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_get_Handle(TElPKCS11ObjectHandle _Handle, int64_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_get_Session(TElPKCS11ObjectHandle _Handle, TElPKCS11SessionInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_get_CryptoProvider(TElPKCS11ObjectHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_set_CryptoProvider(TElPKCS11ObjectHandle _Handle, TElCustomCryptoProviderHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_Create(TElPKCS11ObjectHandle * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, uint32_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Object_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, int64_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#endif
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

#ifdef SB_USE_CLASS_TELPKCS11DATAOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11DataObject_ReadProperties(TElPKCS11DataObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11DataObject_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11DataObject_get_Application(TElPKCS11DataObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11DataObject_set_Application(TElPKCS11DataObjectHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11DataObject_get_ObjectID(TElPKCS11DataObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11DataObject_set_ObjectID(TElPKCS11DataObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11DataObject_get_Value(TElPKCS11DataObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11DataObject_set_Value(TElPKCS11DataObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11DataObject_Create(TElPKCS11ObjectHandle * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11DataObject_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, uint32_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11DataObject_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, int64_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#endif
#endif /* SB_USE_CLASS_TELPKCS11DATAOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11CERTIFICATEOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertificateObject_ReadProperties(TElPKCS11CertificateObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertificateObject_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertificateObject_get_CertType(TElPKCS11CertificateObjectHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertificateObject_get_Trusted(TElPKCS11CertificateObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertificateObject_set_Trusted(TElPKCS11CertificateObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertificateObject_get_CertCategory(TElPKCS11CertificateObjectHandle _Handle, TSBPKCS11CertCategoryRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertificateObject_get_Checksum(TElPKCS11CertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertificateObject_get_StartDate(TElPKCS11CertificateObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertificateObject_set_StartDate(TElPKCS11CertificateObjectHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertificateObject_get_EndDate(TElPKCS11CertificateObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertificateObject_set_EndDate(TElPKCS11CertificateObjectHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertificateObject_Create(TElPKCS11ObjectHandle * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertificateObject_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, uint32_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11CertificateObject_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, int64_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#endif
#endif /* SB_USE_CLASS_TELPKCS11CERTIFICATEOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11X509CERTIFICATEOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509CertificateObject_ReadProperties(TElPKCS11X509CertificateObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509CertificateObject_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509CertificateObject_get_Subject(TElPKCS11X509CertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509CertificateObject_get_KeyID(TElPKCS11X509CertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509CertificateObject_set_KeyID(TElPKCS11X509CertificateObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509CertificateObject_get_Issuer(TElPKCS11X509CertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509CertificateObject_set_Issuer(TElPKCS11X509CertificateObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509CertificateObject_get_SerialNumber(TElPKCS11X509CertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509CertificateObject_set_SerialNumber(TElPKCS11X509CertificateObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509CertificateObject_get_Value(TElPKCS11X509CertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509CertificateObject_get_URL(TElPKCS11X509CertificateObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509CertificateObject_get_SubjectPublicKeyHash(TElPKCS11X509CertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509CertificateObject_get_IssuerPublicKeyHash(TElPKCS11X509CertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509CertificateObject_get_MIDPSecurityDomain(TElPKCS11X509CertificateObjectHandle _Handle, TSBPKCS11MIDPSecurityDomainRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509CertificateObject_Create(TElPKCS11ObjectHandle * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509CertificateObject_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, uint32_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509CertificateObject_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, int64_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#endif
#endif /* SB_USE_CLASS_TELPKCS11X509CERTIFICATEOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11WTLSCERTIFICATEOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11WTLSCertificateObject_ReadProperties(TElPKCS11WTLSCertificateObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11WTLSCertificateObject_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11WTLSCertificateObject_get_Subject(TElPKCS11WTLSCertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11WTLSCertificateObject_get_Issuer(TElPKCS11WTLSCertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11WTLSCertificateObject_set_Issuer(TElPKCS11WTLSCertificateObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11WTLSCertificateObject_get_Value(TElPKCS11WTLSCertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11WTLSCertificateObject_get_URL(TElPKCS11WTLSCertificateObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11WTLSCertificateObject_get_SubjectPublicKeyHash(TElPKCS11WTLSCertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11WTLSCertificateObject_get_IssuerPublicKeyHash(TElPKCS11WTLSCertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11WTLSCertificateObject_Create(TElPKCS11ObjectHandle * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11WTLSCertificateObject_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, uint32_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11WTLSCertificateObject_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, int64_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#endif
#endif /* SB_USE_CLASS_TELPKCS11WTLSCERTIFICATEOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11X509ATTRIBUTECERTIFICATEOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509AttributeCertificateObject_ReadProperties(TElPKCS11X509AttributeCertificateObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509AttributeCertificateObject_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509AttributeCertificateObject_get_Owner(TElPKCS11X509AttributeCertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509AttributeCertificateObject_get_ACIssuer(TElPKCS11X509AttributeCertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509AttributeCertificateObject_set_ACIssuer(TElPKCS11X509AttributeCertificateObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509AttributeCertificateObject_get_SerialNumber(TElPKCS11X509AttributeCertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509AttributeCertificateObject_set_SerialNumber(TElPKCS11X509AttributeCertificateObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509AttributeCertificateObject_get_AttrTypes(TElPKCS11X509AttributeCertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509AttributeCertificateObject_set_AttrTypes(TElPKCS11X509AttributeCertificateObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509AttributeCertificateObject_get_Value(TElPKCS11X509AttributeCertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509AttributeCertificateObject_Create(TElPKCS11ObjectHandle * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509AttributeCertificateObject_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, uint32_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11X509AttributeCertificateObject_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, int64_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#endif
#endif /* SB_USE_CLASS_TELPKCS11X509ATTRIBUTECERTIFICATEOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11KEYOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11KeyObject_ReadProperties(TElPKCS11KeyObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11KeyObject_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11KeyObject_get_KeyType(TElPKCS11KeyObjectHandle _Handle, int32_t * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11KeyObject_get_PKCS11KeyType(TElPKCS11KeyObjectHandle _Handle, uint32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11KeyObject_get_PKCS11KeyType(TElPKCS11KeyObjectHandle _Handle, int64_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11KeyObject_get_KeyID(TElPKCS11KeyObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11KeyObject_set_KeyID(TElPKCS11KeyObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11KeyObject_get_StartDate(TElPKCS11KeyObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11KeyObject_set_StartDate(TElPKCS11KeyObjectHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11KeyObject_get_EndDate(TElPKCS11KeyObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11KeyObject_set_EndDate(TElPKCS11KeyObjectHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11KeyObject_get_Derive(TElPKCS11KeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11KeyObject_set_Derive(TElPKCS11KeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11KeyObject_get_Local(TElPKCS11KeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11KeyObject_get_KeyMaterial(TElPKCS11KeyObjectHandle _Handle, TElKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11KeyObject_Create(TElPKCS11ObjectHandle * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11KeyObject_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, uint32_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11KeyObject_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, int64_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#endif
#endif /* SB_USE_CLASS_TELPKCS11KEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11PUBLICKEYOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PublicKeyObject_ReadProperties(TElPKCS11PublicKeyObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PublicKeyObject_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PublicKeyObject_get_Subject(TElPKCS11PublicKeyObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PublicKeyObject_set_Subject(TElPKCS11PublicKeyObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PublicKeyObject_get_CanEncrypt(TElPKCS11PublicKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PublicKeyObject_set_CanEncrypt(TElPKCS11PublicKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PublicKeyObject_get_CanVerify(TElPKCS11PublicKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PublicKeyObject_set_CanVerify(TElPKCS11PublicKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PublicKeyObject_get_CanVerifyDetached(TElPKCS11PublicKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PublicKeyObject_set_CanVerifyDetached(TElPKCS11PublicKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PublicKeyObject_get_CanWrap(TElPKCS11PublicKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PublicKeyObject_set_CanWrap(TElPKCS11PublicKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PublicKeyObject_get_Trusted(TElPKCS11PublicKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PublicKeyObject_set_Trusted(TElPKCS11PublicKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PublicKeyObject_Create(TElPKCS11ObjectHandle * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PublicKeyObject_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, uint32_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PublicKeyObject_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, int64_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#endif
#endif /* SB_USE_CLASS_TELPKCS11PUBLICKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11PRIVATEKEYOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_ReadProperties(TElPKCS11PrivateKeyObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_get_Subject(TElPKCS11PrivateKeyObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_set_Subject(TElPKCS11PrivateKeyObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_get_Sensitive(TElPKCS11PrivateKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_set_Sensitive(TElPKCS11PrivateKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_get_CanDecrypt(TElPKCS11PrivateKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_set_CanDecrypt(TElPKCS11PrivateKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_get_CanSign(TElPKCS11PrivateKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_set_CanSign(TElPKCS11PrivateKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_get_CanSignDetached(TElPKCS11PrivateKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_set_CanSignDetached(TElPKCS11PrivateKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_get_CanUnwrap(TElPKCS11PrivateKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_set_CanUnwrap(TElPKCS11PrivateKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_get_Extractable(TElPKCS11PrivateKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_set_Extractable(TElPKCS11PrivateKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_get_AlwaysSensitive(TElPKCS11PrivateKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_get_NeverExtractable(TElPKCS11PrivateKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_get_WrapWithTrusted(TElPKCS11PrivateKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_set_WrapWithTrusted(TElPKCS11PrivateKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_get_AlwaysAuthenticate(TElPKCS11PrivateKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_set_AlwaysAuthenticate(TElPKCS11PrivateKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_Create(TElPKCS11ObjectHandle * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, uint32_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11PrivateKeyObject_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, int64_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#endif
#endif /* SB_USE_CLASS_TELPKCS11PRIVATEKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11SECRETKEYOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_ReadProperties(TElPKCS11SecretKeyObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_get_Sensitive(TElPKCS11SecretKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_set_Sensitive(TElPKCS11SecretKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_get_CanEncrypt(TElPKCS11SecretKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_set_CanEncrypt(TElPKCS11SecretKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_get_CanDecrypt(TElPKCS11SecretKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_set_CanDecrypt(TElPKCS11SecretKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_get_CanSign(TElPKCS11SecretKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_set_CanSign(TElPKCS11SecretKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_get_CanVerify(TElPKCS11SecretKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_set_CanVerify(TElPKCS11SecretKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_get_CanWrap(TElPKCS11SecretKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_set_CanWrap(TElPKCS11SecretKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_get_CanUnwrap(TElPKCS11SecretKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_set_CanUnwrap(TElPKCS11SecretKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_get_Extractable(TElPKCS11SecretKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_set_Extractable(TElPKCS11SecretKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_get_AlwaysSensitive(TElPKCS11SecretKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_get_NeverExtractable(TElPKCS11SecretKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_get_Checksum(TElPKCS11SecretKeyObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_get_WrapWithTrusted(TElPKCS11SecretKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_set_WrapWithTrusted(TElPKCS11SecretKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_get_Trusted(TElPKCS11SecretKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_set_Trusted(TElPKCS11SecretKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_Create(TElPKCS11ObjectHandle * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, uint32_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11SecretKeyObject_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, int64_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#endif
#endif /* SB_USE_CLASS_TELPKCS11SECRETKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11DOMAINPARAMETERSOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11DomainParametersObject_ReadProperties(TElPKCS11DomainParametersObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11DomainParametersObject_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11DomainParametersObject_get_KeyType(TElPKCS11DomainParametersObjectHandle _Handle, int32_t * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11DomainParametersObject_get_PKCS11KeyType(TElPKCS11DomainParametersObjectHandle _Handle, uint32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11DomainParametersObject_get_PKCS11KeyType(TElPKCS11DomainParametersObjectHandle _Handle, int64_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11DomainParametersObject_Create(TElPKCS11ObjectHandle * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11DomainParametersObject_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, uint32_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11DomainParametersObject_Create_1(TElPKCS11ModuleHandle Module, TElPKCS11SessionInfoHandle Session, TElPKCS11SlotInfoHandle Slot, int64_t Handle, int8_t CompatibleMode, TElCustomCryptoProviderHandle CryptoProvider, TElPKCS11ObjectHandle * OutResult);
#endif
#endif /* SB_USE_CLASS_TELPKCS11DOMAINPARAMETERSOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11UTILS
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_GetObjectAttribute(TElPKCS11ModuleHandle Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_GetObjectAttribute_1(TElPKCS11UtilsHandle _Handle, TElPKCS11ModuleHandle Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_GetBufferTypeAttribute(TElPKCS11ModuleHandle Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const uint8_t pDef[], int32_t szDef, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_GetBufferTypeAttribute_1(TElPKCS11UtilsHandle _Handle, TElPKCS11ModuleHandle Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const uint8_t pDef[], int32_t szDef, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_GetBooleanAttribute(TElPKCS11ModuleHandle Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int8_t Def, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_GetBooleanAttribute_1(TElPKCS11UtilsHandle _Handle, TElPKCS11ModuleHandle Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int8_t Def, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_GetULongAttribute(TElPKCS11ModuleHandle Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint32_t Def, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_GetULongAttribute_1(TElPKCS11UtilsHandle _Handle, TElPKCS11ModuleHandle Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint32_t Def, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_GetDateAttribute(TElPKCS11ModuleHandle Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int64_t Def, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_GetDateAttribute_1(TElPKCS11UtilsHandle _Handle, TElPKCS11ModuleHandle Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int64_t Def, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_SetObjectAttribute(TElPKCS11ModuleHandle Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_SetObjectAttribute_1(TElPKCS11UtilsHandle _Handle, TElPKCS11ModuleHandle Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_SetBufferTypeAttribute(TElPKCS11ModuleHandle Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_SetBufferTypeAttribute_1(TElPKCS11UtilsHandle _Handle, TElPKCS11ModuleHandle Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_SetBooleanAttribute(TElPKCS11ModuleHandle Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_SetBooleanAttribute_1(TElPKCS11UtilsHandle _Handle, TElPKCS11ModuleHandle Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_SetULongAttribute(TElPKCS11ModuleHandle Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_SetULongAttribute_1(TElPKCS11UtilsHandle _Handle, TElPKCS11ModuleHandle Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_SetDateAttribute(TElPKCS11ModuleHandle Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_SetDateAttribute_1(TElPKCS11UtilsHandle _Handle, TElPKCS11ModuleHandle Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int64_t Value);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_GetObjectAttribute(TElPKCS11ModuleHandle Module, int64_t hSession, int64_t hObject, int64_t Attribute, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_GetObjectAttribute_1(TElPKCS11UtilsHandle _Handle, TElPKCS11ModuleHandle Module, int64_t hSession, int64_t hObject, int64_t Attribute, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_GetBufferTypeAttribute(TElPKCS11ModuleHandle Module, int64_t hSession, int64_t hObject, int64_t Attribute, const uint8_t pDef[], int32_t szDef, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_GetBufferTypeAttribute_1(TElPKCS11UtilsHandle _Handle, TElPKCS11ModuleHandle Module, int64_t hSession, int64_t hObject, int64_t Attribute, const uint8_t pDef[], int32_t szDef, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_GetBooleanAttribute(TElPKCS11ModuleHandle Module, int64_t hSession, int64_t hObject, int64_t Attribute, int8_t Def, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_GetBooleanAttribute_1(TElPKCS11UtilsHandle _Handle, TElPKCS11ModuleHandle Module, int64_t hSession, int64_t hObject, int64_t Attribute, int8_t Def, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_GetULongAttribute(TElPKCS11ModuleHandle Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Def, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_GetULongAttribute_1(TElPKCS11UtilsHandle _Handle, TElPKCS11ModuleHandle Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Def, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_GetDateAttribute(TElPKCS11ModuleHandle Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Def, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_GetDateAttribute_1(TElPKCS11UtilsHandle _Handle, TElPKCS11ModuleHandle Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Def, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_SetObjectAttribute(TElPKCS11ModuleHandle Module, int64_t hSession, int64_t hObject, int64_t Attribute, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_SetObjectAttribute_1(TElPKCS11UtilsHandle _Handle, TElPKCS11ModuleHandle Module, int64_t hSession, int64_t hObject, int64_t Attribute, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_SetBufferTypeAttribute(TElPKCS11ModuleHandle Module, int64_t hSession, int64_t hObject, int64_t Attribute, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_SetBufferTypeAttribute_1(TElPKCS11UtilsHandle _Handle, TElPKCS11ModuleHandle Module, int64_t hSession, int64_t hObject, int64_t Attribute, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_SetBooleanAttribute(TElPKCS11ModuleHandle Module, int64_t hSession, int64_t hObject, int64_t Attribute, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_SetBooleanAttribute_1(TElPKCS11UtilsHandle _Handle, TElPKCS11ModuleHandle Module, int64_t hSession, int64_t hObject, int64_t Attribute, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_SetULongAttribute(TElPKCS11ModuleHandle Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_SetULongAttribute_1(TElPKCS11UtilsHandle _Handle, TElPKCS11ModuleHandle Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_SetDateAttribute(TElPKCS11ModuleHandle Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_SetDateAttribute_1(TElPKCS11UtilsHandle _Handle, TElPKCS11ModuleHandle Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_ConvertPKCS11KeyTypeToSBBKeyType(int32_t KeyType, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_ConvertPKCS11KeyTypeToSBBKeyType_1(TElPKCS11UtilsHandle _Handle, int32_t KeyType, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Utils_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11UTILS */

#ifdef SB_USE_CLASS_TELPKCS11NSSPARAMS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11NSSParams_Load(TElPKCS11NSSParamsHandle _Handle, const uint8_t pData[], int32_t szData, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11NSSParams_Save(TElPKCS11NSSParamsHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11NSSParams_get_ConfigDir(TElPKCS11NSSParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11NSSParams_set_ConfigDir(TElPKCS11NSSParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11NSSParams_get_CertPrefix(TElPKCS11NSSParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11NSSParams_set_CertPrefix(TElPKCS11NSSParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11NSSParams_get_KeyPrefix(TElPKCS11NSSParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11NSSParams_set_KeyPrefix(TElPKCS11NSSParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11NSSParams_get_SecMod(TElPKCS11NSSParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11NSSParams_set_SecMod(TElPKCS11NSSParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11NSSParams_get_Flags(TElPKCS11NSSParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11NSSParams_set_Flags(TElPKCS11NSSParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11NSSParams_get_UseNSSMode(TElPKCS11NSSParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11NSSParams_set_UseNSSMode(TElPKCS11NSSParamsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11NSSParams_get_RawParamsStr(TElPKCS11NSSParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11NSSParams_set_RawParamsStr(TElPKCS11NSSParamsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11NSSParams_Create(TElPKCS11NSSParamsHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11NSSPARAMS */

#ifdef SB_USE_CLASS_TELPKCS11MODULELIST
#ifndef SB_IOS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ModuleList_LoadModule(TElPKCS11ModuleListHandle _Handle, const char * pcModuleName, int32_t szModuleName, int8_t UseSystemProcAddresses, int8_t TrySingleThreadedMode, int8_t AutoRefreshSlotInfo, TElPKCS11ModuleHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ModuleList_LoadModule_1(TElPKCS11ModuleListHandle _Handle, const char * pcModuleName, int32_t szModuleName, int8_t UseSystemProcAddresses, int8_t TrySingleThreadedMode, int8_t AutoRefreshSlotInfo, int8_t PreserveSettingsIfExists, TElPKCS11ModuleHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ModuleList_LoadModule_2(TElPKCS11ModuleListHandle _Handle, const char * pcModuleName, int32_t szModuleName, int8_t UseSystemProcAddresses, int8_t TrySingleThreadedMode, int8_t AutoRefreshSlotInfo, int8_t PreserveSettingsIfExists, int8_t OnDemandMode, TElPKCS11ModuleHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ModuleList_LoadModule_3(TElPKCS11ModuleListHandle _Handle, const char * pcModuleName, int32_t szModuleName, int8_t UseSystemProcAddresses, int8_t TrySingleThreadedMode, int8_t AutoRefreshSlotInfo, int8_t PreserveSettingsIfExists, int8_t OnDemandMode, TElPKCS11NSSParamsHandle NSSParams, int8_t NoImplicitSlotInfoUpdates, TElPKCS11ModuleHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ModuleList_LoadModule(TElPKCS11ModuleListHandle _Handle, TElPKCS11FunctionsManagerHandle FuncMng, int8_t TrySingleThreadedMode, int8_t AutoRefreshSlotInfo, TElPKCS11ModuleHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ModuleList_LoadModule_1(TElPKCS11ModuleListHandle _Handle, TElPKCS11FunctionsManagerHandle FuncMng, int8_t TrySingleThreadedMode, int8_t AutoRefreshSlotInfo, int8_t PreserveSettingsIfExists, TElPKCS11ModuleHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ModuleList_LoadModule_2(TElPKCS11ModuleListHandle _Handle, TElPKCS11FunctionsManagerHandle FuncMng, int8_t TrySingleThreadedMode, int8_t AutoRefreshSlotInfo, int8_t PreserveSettingsIfExists, int8_t OnDemandMode, TElPKCS11ModuleHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ModuleList_LoadModule_3(TElPKCS11ModuleListHandle _Handle, TElPKCS11FunctionsManagerHandle FuncMng, int8_t TrySingleThreadedMode, int8_t AutoRefreshSlotInfo, int8_t PreserveSettingsIfExists, int8_t OnDemandMode, TElPKCS11NSSParamsHandle NSSParams, int8_t NoImplicitSlotInfoUpdates, TElPKCS11ModuleHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ModuleList_UnloadModule(TElPKCS11ModuleListHandle _Handle, TElPKCS11ModuleHandle aModule);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ModuleList_get_ModuleCount(TElPKCS11ModuleListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ModuleList_get_Modules(TElPKCS11ModuleListHandle _Handle, int32_t Index, TElPKCS11ModuleHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ModuleList_Create(TElPKCS11ModuleListHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11MODULELIST */

#ifdef SB_USE_CLASS_TELPKCS11ALGORITHMINFO
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmInfo_get_Algorithm(TElPKCS11AlgorithmInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmInfo_get_Mode(TElPKCS11AlgorithmInfoHandle _Handle, int32_t * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmInfo_get_Mechanism(TElPKCS11AlgorithmInfoHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmInfo_get_KeyMechanism(TElPKCS11AlgorithmInfoHandle _Handle, uint32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmInfo_get_Mechanism(TElPKCS11AlgorithmInfoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmInfo_get_KeyMechanism(TElPKCS11AlgorithmInfoHandle _Handle, int64_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmInfo_get_PaddingUsed(TElPKCS11AlgorithmInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmInfo_get_CanGenerate(TElPKCS11AlgorithmInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmInfo_get_CanEncrypt(TElPKCS11AlgorithmInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmInfo_get_CanSign(TElPKCS11AlgorithmInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmInfo_get_CanSignRecover(TElPKCS11AlgorithmInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmInfo_get_CanDigest(TElPKCS11AlgorithmInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmInfo_get_CanWrap(TElPKCS11AlgorithmInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmInfo_get_CanDerive(TElPKCS11AlgorithmInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmInfo_get_SignHashAlgorithm(TElPKCS11AlgorithmInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmInfo_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11ALGORITHMINFO */

#ifdef SB_USE_CLASS_TELPKCS11ALGORITHMCONVERTER
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmConverter_Find(TElPKCS11AlgorithmConverterHandle _Handle, int32_t Algorithm, int32_t Mode, int32_t Operation, int8_t PaddingUsed, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmConverter_Find_1(TElPKCS11AlgorithmConverterHandle _Handle, int32_t Algorithm, int32_t Mode, TListHandle Infos);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmConverter_FindSignatureAlgorithmInfo(TElPKCS11AlgorithmConverterHandle _Handle, int32_t Algorithm, int32_t HashAlgorithm, int32_t * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmConverter_GetAlgorithmByPKCS11Mechanism(TElPKCS11AlgorithmConverterHandle _Handle, uint32_t Mech, int32_t * Mode, int8_t * Gen, int32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmConverter_GetAlgorithmByPKCS11Mechanism(TElPKCS11AlgorithmConverterHandle _Handle, int64_t Mech, int32_t * Mode, int8_t * Gen, int32_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmConverter_GetPKCS11MechanismByAlgorithm(TElPKCS11AlgorithmConverterHandle _Handle, int32_t Algorithm, int32_t Mode, SB_CK_MECHANISM * Mech, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmConverter_get_AlgorithmInfos(TElPKCS11AlgorithmConverterHandle _Handle, int32_t Index, TElPKCS11AlgorithmInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmConverter_get_AlgorithmInfoCount(TElPKCS11AlgorithmConverterHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11AlgorithmConverter_Create(TElPKCS11AlgorithmConverterHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11ALGORITHMCONVERTER */

#ifdef SB_USE_CLASS_TELSLOTEVENTMONITORINGTHREAD
SB_IMPORT uint32_t SB_APIENTRY TElSlotEventMonitoringThread_get_OnSlotEvent(TElSlotEventMonitoringThreadHandle _Handle, TElSlotEventMonitoringThreadEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSlotEventMonitoringThread_set_OnSlotEvent(TElSlotEventMonitoringThreadHandle _Handle, TElSlotEventMonitoringThreadEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSlotEventMonitoringThread_Create(TElPKCS11ModuleHandle PKCS11Module, int8_t SynchronizeGUI, int8_t UseGetSlotInfo, int32_t Delay, TElSlotEventMonitoringThreadHandle * OutResult);
#endif /* SB_USE_CLASS_TELSLOTEVENTMONITORINGTHREAD */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPKCS11Module;
class TElPKCS11SlotInfo;
class TElPKCS11SessionInfo;
#ifdef SB_IOS
class TElPKCS11FunctionsManager;
#endif
class TElPKCS11Consumer;
typedef TElPKCS11Consumer ElPKCS11Consumer;
class TElPKCS11AttributeList;
class TElPKCS11Object;
class TElPKCS11DataObject;
class TElPKCS11CertificateObject;
class TElPKCS11X509CertificateObject;
class TElPKCS11WTLSCertificateObject;
class TElPKCS11X509AttributeCertificateObject;
class TElPKCS11KeyObject;
class TElPKCS11PublicKeyObject;
class TElPKCS11PrivateKeyObject;
class TElPKCS11SecretKeyObject;
class TElPKCS11DomainParametersObject;
class TElPKCS11Utils;
class TElPKCS11NSSParams;
class TElPKCS11ModuleList;
typedef TElPKCS11ModuleList ElPKCS11ModuleList;
class TElPKCS11AlgorithmInfo;
class TElPKCS11AlgorithmConverter;
class TElSlotEventMonitoringThread;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBPKCS11StorageOptions)

#ifndef SB_CPU64_OR_IOS
#ifdef SB_USE_CLASS_TELPKCS11MODULE
class TElPKCS11Module: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11Module)
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfo* _Inst_Session;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
		TElPKCS11SlotInfo* _Inst_Slot;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		bool CloseSession(TElPKCS11SessionInfo &SessionInfo);

		bool CloseSession(TElPKCS11SessionInfo *SessionInfo);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

		int32_t GetFunctionList();

#ifdef SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfoHandle OpenSession(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer &Consumer);

		TElPKCS11SessionInfoHandle OpenSession(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer *Consumer);
#endif /* SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfoHandle OpenSessionEx(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer &Consumer, bool RequestNotifications);

		TElPKCS11SessionInfoHandle OpenSessionEx(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer *Consumer, bool RequestNotifications);
#endif /* SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfoHandle GetSessionByHandle(uint32_t Handle);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

		void InitToken(int32_t SlotIndex, const std::string &Pin, const std::string &TokenLabel);

		virtual void get_ProviderDescription(std::string &OutResult);

		virtual void set_ProviderDescription(const std::string &Value);

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		virtual TElPKCS11SessionInfo* get_Session(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

		virtual int32_t get_SessionCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SessionCount, TElPKCS11Module, SessionCount);

#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
		virtual TElPKCS11SlotInfo* get_Slot(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

		virtual int32_t get_SlotCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SlotCount, TElPKCS11Module, SlotCount);

		virtual void get_UniqueID(std::vector<uint8_t> &OutResult);

		virtual uint32_t get_HLib();

		SB_DECLARE_PROPERTY_GET(uint32_t, get_HLib, TElPKCS11Module, HLib);

		virtual bool get_UseGetFunctionList();

		virtual void set_UseGetFunctionList(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseGetFunctionList, set_UseGetFunctionList, TElPKCS11Module, UseGetFunctionList);

		TElPKCS11Module(TElPKCS11ModuleHandle handle, TElOwnHandle ownHandle);

		TElPKCS11Module();

		virtual ~TElPKCS11Module();

};
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#endif
#ifndef SB_NOT_CPU64_OR_NOT_WINDOWS
#ifdef SB_USE_CLASS_TELPKCS11MODULE
class TElPKCS11Module: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11Module)
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfo* _Inst_Session;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
		TElPKCS11SlotInfo* _Inst_Slot;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		bool CloseSession(TElPKCS11SessionInfo &SessionInfo);

		bool CloseSession(TElPKCS11SessionInfo *SessionInfo);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

		int32_t GetFunctionList();

#ifdef SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfoHandle OpenSession(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer &Consumer);

		TElPKCS11SessionInfoHandle OpenSession(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer *Consumer);
#endif /* SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfoHandle OpenSessionEx(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer &Consumer, bool RequestNotifications);

		TElPKCS11SessionInfoHandle OpenSessionEx(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer *Consumer, bool RequestNotifications);
#endif /* SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfoHandle GetSessionByHandle(uint32_t Handle);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

		void InitToken(int32_t SlotIndex, const std::string &Pin, const std::string &TokenLabel);

		virtual void get_ProviderDescription(std::string &OutResult);

		virtual void set_ProviderDescription(const std::string &Value);

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		virtual TElPKCS11SessionInfo* get_Session(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

		virtual int32_t get_SessionCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SessionCount, TElPKCS11Module, SessionCount);

#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
		virtual TElPKCS11SlotInfo* get_Slot(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

		virtual int32_t get_SlotCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SlotCount, TElPKCS11Module, SlotCount);

		virtual void get_UniqueID(std::vector<uint8_t> &OutResult);

		virtual int64_t get_HLib();

		SB_DECLARE_PROPERTY_GET(int64_t, get_HLib, TElPKCS11Module, HLib);

		virtual bool get_UseGetFunctionList();

		virtual void set_UseGetFunctionList(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseGetFunctionList, set_UseGetFunctionList, TElPKCS11Module, UseGetFunctionList);

		TElPKCS11Module(TElPKCS11ModuleHandle handle, TElOwnHandle ownHandle);

		TElPKCS11Module();

		virtual ~TElPKCS11Module();

};
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
#ifdef SB_USE_CLASS_TELPKCS11MODULE
class TElPKCS11Module: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11Module)
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfo* _Inst_Session;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
		TElPKCS11SlotInfo* _Inst_Slot;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		bool CloseSession(TElPKCS11SessionInfo &SessionInfo);

		bool CloseSession(TElPKCS11SessionInfo *SessionInfo);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

		int32_t GetFunctionList();

#ifdef SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfoHandle OpenSession(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer &Consumer);

		TElPKCS11SessionInfoHandle OpenSession(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer *Consumer);
#endif /* SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfoHandle OpenSessionEx(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer &Consumer, bool RequestNotifications);

		TElPKCS11SessionInfoHandle OpenSessionEx(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer *Consumer, bool RequestNotifications);
#endif /* SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfoHandle GetSessionByHandle(int64_t Handle);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

		void InitToken(int32_t SlotIndex, const std::string &Pin, const std::string &TokenLabel);

		virtual void get_ProviderDescription(std::string &OutResult);

		virtual void set_ProviderDescription(const std::string &Value);

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		virtual TElPKCS11SessionInfo* get_Session(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

		virtual int32_t get_SessionCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SessionCount, TElPKCS11Module, SessionCount);

#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
		virtual TElPKCS11SlotInfo* get_Slot(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

		virtual int32_t get_SlotCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SlotCount, TElPKCS11Module, SlotCount);

		virtual void get_UniqueID(std::vector<uint8_t> &OutResult);

		virtual int64_t get_HLib();

		SB_DECLARE_PROPERTY_GET(int64_t, get_HLib, TElPKCS11Module, HLib);

		virtual bool get_UseGetFunctionList();

		virtual void set_UseGetFunctionList(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseGetFunctionList, set_UseGetFunctionList, TElPKCS11Module, UseGetFunctionList);

		TElPKCS11Module(TElPKCS11ModuleHandle handle, TElOwnHandle ownHandle);

		TElPKCS11Module();

		virtual ~TElPKCS11Module();

};
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
#ifdef SB_USE_CLASS_TELPKCS11MODULE
class TElPKCS11Module: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11Module)
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfo* _Inst_Session;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
		TElPKCS11SlotInfo* _Inst_Slot;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
		TElPKCS11FunctionsManager* _Inst_HLib;
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		bool CloseSession(TElPKCS11SessionInfo &SessionInfo);

		bool CloseSession(TElPKCS11SessionInfo *SessionInfo);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

		int32_t GetFunctionList();

#ifdef SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfoHandle OpenSession(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer &Consumer);

		TElPKCS11SessionInfoHandle OpenSession(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer *Consumer);
#endif /* SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfoHandle OpenSessionEx(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer &Consumer, bool RequestNotifications);

		TElPKCS11SessionInfoHandle OpenSessionEx(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer *Consumer, bool RequestNotifications);
#endif /* SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfoHandle GetSessionByHandle(int64_t Handle);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

		void InitToken(int32_t SlotIndex, const std::string &Pin, const std::string &TokenLabel);

		virtual void get_ProviderDescription(std::string &OutResult);

		virtual void set_ProviderDescription(const std::string &Value);

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		virtual TElPKCS11SessionInfo* get_Session(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

		virtual int32_t get_SessionCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SessionCount, TElPKCS11Module, SessionCount);

#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
		virtual TElPKCS11SlotInfo* get_Slot(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

		virtual int32_t get_SlotCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SlotCount, TElPKCS11Module, SlotCount);

		virtual void get_UniqueID(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
		virtual TElPKCS11FunctionsManager* get_HLib();

		SB_DECLARE_PROPERTY_GET(TElPKCS11FunctionsManager*, get_HLib, TElPKCS11Module, HLib);
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */

		TElPKCS11Module(TElPKCS11ModuleHandle handle, TElOwnHandle ownHandle);

		TElPKCS11Module();

		virtual ~TElPKCS11Module();

};
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#endif
#ifndef SB_CPU64_OR_NOT_IOS
#ifdef SB_USE_CLASS_TELPKCS11MODULE
class TElPKCS11Module: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11Module)
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfo* _Inst_Session;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
		TElPKCS11SlotInfo* _Inst_Slot;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
		TElPKCS11FunctionsManager* _Inst_HLib;
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		bool CloseSession(TElPKCS11SessionInfo &SessionInfo);

		bool CloseSession(TElPKCS11SessionInfo *SessionInfo);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

		int32_t GetFunctionList();

#ifdef SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfoHandle OpenSession(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer &Consumer);

		TElPKCS11SessionInfoHandle OpenSession(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer *Consumer);
#endif /* SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfoHandle OpenSessionEx(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer &Consumer, bool RequestNotifications);

		TElPKCS11SessionInfoHandle OpenSessionEx(int32_t SlotIndex, bool ReadOnly, TElPKCS11Consumer *Consumer, bool RequestNotifications);
#endif /* SB_USE_CLASSES_TELPKCS11CONSUMER_AND_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfoHandle GetSessionByHandle(uint32_t Handle);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

		void InitToken(int32_t SlotIndex, const std::string &Pin, const std::string &TokenLabel);

		virtual void get_ProviderDescription(std::string &OutResult);

		virtual void set_ProviderDescription(const std::string &Value);

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		virtual TElPKCS11SessionInfo* get_Session(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

		virtual int32_t get_SessionCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SessionCount, TElPKCS11Module, SessionCount);

#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
		virtual TElPKCS11SlotInfo* get_Slot(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

		virtual int32_t get_SlotCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SlotCount, TElPKCS11Module, SlotCount);

		virtual void get_UniqueID(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
		virtual TElPKCS11FunctionsManager* get_HLib();

		SB_DECLARE_PROPERTY_GET(TElPKCS11FunctionsManager*, get_HLib, TElPKCS11Module, HLib);
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */

		TElPKCS11Module(TElPKCS11ModuleHandle handle, TElOwnHandle ownHandle);

		TElPKCS11Module();

		virtual ~TElPKCS11Module();

};
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#endif

#ifndef SB_IOS
#ifdef SB_NOT_CPU64_OR_WINDOWS
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
class TElPKCS11SlotInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11SlotInfo)
#ifdef SB_USE_CLASS_TELPKCS11MODULE
		TElPKCS11Module* _Inst_Module;
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
		TElPKCS11Consumer* _Inst_Consumers;
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
		void AddConsumer(TElPKCS11Consumer &Consumer);

		void AddConsumer(TElPKCS11Consumer *Consumer);
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

		bool PinNeeded();

		void Refresh();

		void RefreshSlot();

		void RefreshSupportedAlgorithms();

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
		void RemoveConsumer(TElPKCS11Consumer &Consumer);

		void RemoveConsumer(TElPKCS11Consumer *Consumer);
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

		virtual int32_t get_ConsumerCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ConsumerCount, TElPKCS11SlotInfo, ConsumerCount);

		virtual bool get_LoggedIn();

		SB_DECLARE_PROPERTY_GET(bool, get_LoggedIn, TElPKCS11SlotInfo, LoggedIn);

		virtual bool get_ReadOnly();

		SB_DECLARE_PROPERTY_GET(bool, get_ReadOnly, TElPKCS11SlotInfo, ReadOnly);

		virtual void get_SlotManufacturerID(std::string &OutResult);

		virtual void get_SlotDescription(std::string &OutResult);

		virtual uint8_t get_SlotHardwareVersionHi();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_SlotHardwareVersionHi, TElPKCS11SlotInfo, SlotHardwareVersionHi);

		virtual uint8_t get_SlotFirmwareVersionHi();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_SlotFirmwareVersionHi, TElPKCS11SlotInfo, SlotFirmwareVersionHi);

		virtual uint8_t get_SlotHardwareVersionLo();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_SlotHardwareVersionLo, TElPKCS11SlotInfo, SlotHardwareVersionLo);

		virtual uint8_t get_SlotFirmwareVersionLo();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_SlotFirmwareVersionLo, TElPKCS11SlotInfo, SlotFirmwareVersionLo);

		virtual bool get_TokenPresent();

		SB_DECLARE_PROPERTY_GET(bool, get_TokenPresent, TElPKCS11SlotInfo, TokenPresent);

		virtual uint8_t get_TokenHardwareVersionHi();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_TokenHardwareVersionHi, TElPKCS11SlotInfo, TokenHardwareVersionHi);

		virtual uint8_t get_TokenFirmwareVersionHi();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_TokenFirmwareVersionHi, TElPKCS11SlotInfo, TokenFirmwareVersionHi);

		virtual uint8_t get_TokenHardwareVersionLo();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_TokenHardwareVersionLo, TElPKCS11SlotInfo, TokenHardwareVersionLo);

		virtual uint8_t get_TokenFirmwareVersionLo();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_TokenFirmwareVersionLo, TElPKCS11SlotInfo, TokenFirmwareVersionLo);

		virtual void get_TokenManufacturerID(std::string &OutResult);

		virtual void get_TokenLabel(std::string &OutResult);

		virtual void get_TokenModel(std::string &OutResult);

		virtual void get_TokenSerial(std::string &OutResult);

		virtual uint32_t get_TokenFlags();

		SB_DECLARE_PROPERTY_GET(uint32_t, get_TokenFlags, TElPKCS11SlotInfo, TokenFlags);

#ifdef SB_USE_CLASS_TELPKCS11MODULE
		virtual TElPKCS11Module* get_Module();

		SB_DECLARE_PROPERTY_GET(TElPKCS11Module*, get_Module, TElPKCS11SlotInfo, Module);
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
		virtual TElPKCS11Consumer* get_Consumers(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

		virtual uint32_t get_SupportedPKCS11Mechanisms(int32_t Index);

		virtual uint32_t get_SlotID();

		SB_DECLARE_PROPERTY_GET(uint32_t, get_SlotID, TElPKCS11SlotInfo, SlotID);

		virtual int32_t get_SupportedPKCS11MechanismCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SupportedPKCS11MechanismCount, TElPKCS11SlotInfo, SupportedPKCS11MechanismCount);

		TElPKCS11SlotInfo(TElPKCS11SlotInfoHandle handle, TElOwnHandle ownHandle);

		TElPKCS11SlotInfo();

		virtual ~TElPKCS11SlotInfo();

};
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
#endif
#endif
#ifndef SB_NOT_CPU64_OR_IOS_OR_WINDOWS
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
class TElPKCS11SlotInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11SlotInfo)
#ifdef SB_USE_CLASS_TELPKCS11MODULE
		TElPKCS11Module* _Inst_Module;
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
		TElPKCS11Consumer* _Inst_Consumers;
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
		void AddConsumer(TElPKCS11Consumer &Consumer);

		void AddConsumer(TElPKCS11Consumer *Consumer);
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

		bool PinNeeded();

		void Refresh();

		void RefreshSlot();

		void RefreshSupportedAlgorithms();

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
		void RemoveConsumer(TElPKCS11Consumer &Consumer);

		void RemoveConsumer(TElPKCS11Consumer *Consumer);
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

		virtual int32_t get_ConsumerCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ConsumerCount, TElPKCS11SlotInfo, ConsumerCount);

		virtual bool get_LoggedIn();

		SB_DECLARE_PROPERTY_GET(bool, get_LoggedIn, TElPKCS11SlotInfo, LoggedIn);

		virtual bool get_ReadOnly();

		SB_DECLARE_PROPERTY_GET(bool, get_ReadOnly, TElPKCS11SlotInfo, ReadOnly);

		virtual void get_SlotManufacturerID(std::string &OutResult);

		virtual void get_SlotDescription(std::string &OutResult);

		virtual uint8_t get_SlotHardwareVersionHi();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_SlotHardwareVersionHi, TElPKCS11SlotInfo, SlotHardwareVersionHi);

		virtual uint8_t get_SlotFirmwareVersionHi();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_SlotFirmwareVersionHi, TElPKCS11SlotInfo, SlotFirmwareVersionHi);

		virtual uint8_t get_SlotHardwareVersionLo();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_SlotHardwareVersionLo, TElPKCS11SlotInfo, SlotHardwareVersionLo);

		virtual uint8_t get_SlotFirmwareVersionLo();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_SlotFirmwareVersionLo, TElPKCS11SlotInfo, SlotFirmwareVersionLo);

		virtual bool get_TokenPresent();

		SB_DECLARE_PROPERTY_GET(bool, get_TokenPresent, TElPKCS11SlotInfo, TokenPresent);

		virtual uint8_t get_TokenHardwareVersionHi();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_TokenHardwareVersionHi, TElPKCS11SlotInfo, TokenHardwareVersionHi);

		virtual uint8_t get_TokenFirmwareVersionHi();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_TokenFirmwareVersionHi, TElPKCS11SlotInfo, TokenFirmwareVersionHi);

		virtual uint8_t get_TokenHardwareVersionLo();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_TokenHardwareVersionLo, TElPKCS11SlotInfo, TokenHardwareVersionLo);

		virtual uint8_t get_TokenFirmwareVersionLo();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_TokenFirmwareVersionLo, TElPKCS11SlotInfo, TokenFirmwareVersionLo);

		virtual void get_TokenManufacturerID(std::string &OutResult);

		virtual void get_TokenLabel(std::string &OutResult);

		virtual void get_TokenModel(std::string &OutResult);

		virtual void get_TokenSerial(std::string &OutResult);

		virtual uint32_t get_TokenFlags();

		SB_DECLARE_PROPERTY_GET(uint32_t, get_TokenFlags, TElPKCS11SlotInfo, TokenFlags);

#ifdef SB_USE_CLASS_TELPKCS11MODULE
		virtual TElPKCS11Module* get_Module();

		SB_DECLARE_PROPERTY_GET(TElPKCS11Module*, get_Module, TElPKCS11SlotInfo, Module);
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
		virtual TElPKCS11Consumer* get_Consumers(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

		virtual int64_t get_SupportedPKCS11Mechanisms(int32_t Index);

		virtual int64_t get_SlotID();

		SB_DECLARE_PROPERTY_GET(int64_t, get_SlotID, TElPKCS11SlotInfo, SlotID);

		virtual int32_t get_SupportedPKCS11MechanismCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SupportedPKCS11MechanismCount, TElPKCS11SlotInfo, SupportedPKCS11MechanismCount);

		TElPKCS11SlotInfo(TElPKCS11SlotInfoHandle handle, TElOwnHandle ownHandle);

		TElPKCS11SlotInfo();

		virtual ~TElPKCS11SlotInfo();

};
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
#endif

#ifndef SB_CPU64_OR_NOT_IOS
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
class TElPKCS11SlotInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11SlotInfo)
#ifdef SB_USE_CLASS_TELPKCS11MODULE
		TElPKCS11Module* _Inst_Module;
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
		TElPKCS11Consumer* _Inst_Consumers;
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
		void AddConsumer(TElPKCS11Consumer &Consumer);

		void AddConsumer(TElPKCS11Consumer *Consumer);
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

		bool PinNeeded();

		void Refresh();

		void RefreshSlot();

		void RefreshSupportedAlgorithms();

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
		void RemoveConsumer(TElPKCS11Consumer &Consumer);

		void RemoveConsumer(TElPKCS11Consumer *Consumer);
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

		virtual int32_t get_ConsumerCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ConsumerCount, TElPKCS11SlotInfo, ConsumerCount);

		virtual bool get_LoggedIn();

		SB_DECLARE_PROPERTY_GET(bool, get_LoggedIn, TElPKCS11SlotInfo, LoggedIn);

		virtual bool get_ReadOnly();

		SB_DECLARE_PROPERTY_GET(bool, get_ReadOnly, TElPKCS11SlotInfo, ReadOnly);

		virtual void get_SlotManufacturerID(std::string &OutResult);

		virtual void get_SlotDescription(std::string &OutResult);

		virtual uint8_t get_SlotHardwareVersionHi();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_SlotHardwareVersionHi, TElPKCS11SlotInfo, SlotHardwareVersionHi);

		virtual uint8_t get_SlotFirmwareVersionHi();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_SlotFirmwareVersionHi, TElPKCS11SlotInfo, SlotFirmwareVersionHi);

		virtual uint8_t get_SlotHardwareVersionLo();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_SlotHardwareVersionLo, TElPKCS11SlotInfo, SlotHardwareVersionLo);

		virtual uint8_t get_SlotFirmwareVersionLo();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_SlotFirmwareVersionLo, TElPKCS11SlotInfo, SlotFirmwareVersionLo);

		virtual bool get_TokenPresent();

		SB_DECLARE_PROPERTY_GET(bool, get_TokenPresent, TElPKCS11SlotInfo, TokenPresent);

		virtual uint8_t get_TokenHardwareVersionHi();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_TokenHardwareVersionHi, TElPKCS11SlotInfo, TokenHardwareVersionHi);

		virtual uint8_t get_TokenFirmwareVersionHi();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_TokenFirmwareVersionHi, TElPKCS11SlotInfo, TokenFirmwareVersionHi);

		virtual uint8_t get_TokenHardwareVersionLo();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_TokenHardwareVersionLo, TElPKCS11SlotInfo, TokenHardwareVersionLo);

		virtual uint8_t get_TokenFirmwareVersionLo();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_TokenFirmwareVersionLo, TElPKCS11SlotInfo, TokenFirmwareVersionLo);

		virtual void get_TokenManufacturerID(std::string &OutResult);

		virtual void get_TokenLabel(std::string &OutResult);

		virtual void get_TokenModel(std::string &OutResult);

		virtual void get_TokenSerial(std::string &OutResult);

		virtual uint32_t get_TokenFlags();

		SB_DECLARE_PROPERTY_GET(uint32_t, get_TokenFlags, TElPKCS11SlotInfo, TokenFlags);

#ifdef SB_USE_CLASS_TELPKCS11MODULE
		virtual TElPKCS11Module* get_Module();

		SB_DECLARE_PROPERTY_GET(TElPKCS11Module*, get_Module, TElPKCS11SlotInfo, Module);
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
		virtual TElPKCS11Consumer* get_Consumers(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

		virtual uint32_t get_SupportedPKCS11Mechanisms(int32_t Index);

		virtual uint32_t get_SlotID();

		SB_DECLARE_PROPERTY_GET(uint32_t, get_SlotID, TElPKCS11SlotInfo, SlotID);

		virtual int32_t get_SupportedPKCS11MechanismCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SupportedPKCS11MechanismCount, TElPKCS11SlotInfo, SupportedPKCS11MechanismCount);

		TElPKCS11SlotInfo(TElPKCS11SlotInfoHandle handle, TElOwnHandle ownHandle);

		TElPKCS11SlotInfo();

		virtual ~TElPKCS11SlotInfo();

};
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
#endif
#ifndef SB_NOT_CPU64_OR_NOT_IOS
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
class TElPKCS11SlotInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11SlotInfo)
#ifdef SB_USE_CLASS_TELPKCS11MODULE
		TElPKCS11Module* _Inst_Module;
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
		TElPKCS11Consumer* _Inst_Consumers;
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
		void AddConsumer(TElPKCS11Consumer &Consumer);

		void AddConsumer(TElPKCS11Consumer *Consumer);
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

		bool PinNeeded();

		void Refresh();

		void RefreshSlot();

		void RefreshSupportedAlgorithms();

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
		void RemoveConsumer(TElPKCS11Consumer &Consumer);

		void RemoveConsumer(TElPKCS11Consumer *Consumer);
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

		virtual int32_t get_ConsumerCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ConsumerCount, TElPKCS11SlotInfo, ConsumerCount);

		virtual bool get_LoggedIn();

		SB_DECLARE_PROPERTY_GET(bool, get_LoggedIn, TElPKCS11SlotInfo, LoggedIn);

		virtual bool get_ReadOnly();

		SB_DECLARE_PROPERTY_GET(bool, get_ReadOnly, TElPKCS11SlotInfo, ReadOnly);

		virtual void get_SlotManufacturerID(std::string &OutResult);

		virtual void get_SlotDescription(std::string &OutResult);

		virtual uint8_t get_SlotHardwareVersionHi();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_SlotHardwareVersionHi, TElPKCS11SlotInfo, SlotHardwareVersionHi);

		virtual uint8_t get_SlotFirmwareVersionHi();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_SlotFirmwareVersionHi, TElPKCS11SlotInfo, SlotFirmwareVersionHi);

		virtual uint8_t get_SlotHardwareVersionLo();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_SlotHardwareVersionLo, TElPKCS11SlotInfo, SlotHardwareVersionLo);

		virtual uint8_t get_SlotFirmwareVersionLo();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_SlotFirmwareVersionLo, TElPKCS11SlotInfo, SlotFirmwareVersionLo);

		virtual bool get_TokenPresent();

		SB_DECLARE_PROPERTY_GET(bool, get_TokenPresent, TElPKCS11SlotInfo, TokenPresent);

		virtual uint8_t get_TokenHardwareVersionHi();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_TokenHardwareVersionHi, TElPKCS11SlotInfo, TokenHardwareVersionHi);

		virtual uint8_t get_TokenFirmwareVersionHi();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_TokenFirmwareVersionHi, TElPKCS11SlotInfo, TokenFirmwareVersionHi);

		virtual uint8_t get_TokenHardwareVersionLo();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_TokenHardwareVersionLo, TElPKCS11SlotInfo, TokenHardwareVersionLo);

		virtual uint8_t get_TokenFirmwareVersionLo();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_TokenFirmwareVersionLo, TElPKCS11SlotInfo, TokenFirmwareVersionLo);

		virtual void get_TokenManufacturerID(std::string &OutResult);

		virtual void get_TokenLabel(std::string &OutResult);

		virtual void get_TokenModel(std::string &OutResult);

		virtual void get_TokenSerial(std::string &OutResult);

		virtual uint32_t get_TokenFlags();

		SB_DECLARE_PROPERTY_GET(uint32_t, get_TokenFlags, TElPKCS11SlotInfo, TokenFlags);

#ifdef SB_USE_CLASS_TELPKCS11MODULE
		virtual TElPKCS11Module* get_Module();

		SB_DECLARE_PROPERTY_GET(TElPKCS11Module*, get_Module, TElPKCS11SlotInfo, Module);
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
		virtual TElPKCS11Consumer* get_Consumers(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

		virtual int64_t get_SupportedPKCS11Mechanisms(int32_t Index);

		virtual int64_t get_SlotID();

		SB_DECLARE_PROPERTY_GET(int64_t, get_SlotID, TElPKCS11SlotInfo, SlotID);

		virtual int32_t get_SupportedPKCS11MechanismCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SupportedPKCS11MechanismCount, TElPKCS11SlotInfo, SupportedPKCS11MechanismCount);

		TElPKCS11SlotInfo(TElPKCS11SlotInfoHandle handle, TElOwnHandle ownHandle);

		TElPKCS11SlotInfo();

		virtual ~TElPKCS11SlotInfo();

};
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
#endif

#ifndef SB_IOS
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
class TElPKCS11SessionInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11SessionInfo)
#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
		TElPKCS11Consumer* _Inst_Consumer;
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
		TElPKCS11SlotInfo* _Inst_Slot;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProvider* _Inst_CryptoProvider;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELPKCS11OBJECT
		TElPKCS11Object* _Inst_Objects;
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
		int32_t AddObject(TSBPKCS11ObjectType ObjectType, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList &Attributes);

		int32_t AddObject(TSBPKCS11ObjectType ObjectType, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList *Attributes);
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
		int32_t AddObject(TSBPKCS11ObjectType ObjectType, bool Token, TElPKCS11AttributeList &Attributes);

		int32_t AddObject(TSBPKCS11ObjectType ObjectType, bool Token, TElPKCS11AttributeList *Attributes);
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifdef SB_NOT_CPU64_OR_WINDOWS
		int32_t AddGeneratedObject(uint32_t Handle);
#else
		int32_t AddGeneratedObject(int64_t Handle);
#endif

		void RemoveObject(int32_t Index);

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
		void RemoveObject(TElPKCS11Object &Obj);

		void RemoveObject(TElPKCS11Object *Obj);
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

#ifdef SB_NOT_CPU64_OR_WINDOWS
		void RemoveObjectByHandle(uint32_t Handle);
#else
		void RemoveObjectByHandle(int64_t Handle);
#endif

		void ClearObjects();

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
		int32_t CopyObject(int32_t Index, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList &Attributes);

		int32_t CopyObject(int32_t Index, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList *Attributes);
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifdef SB_USE_CLASSES_TELPKCS11ATTRIBUTELIST_AND_TELPKCS11OBJECT
		int32_t CopyObject(TElPKCS11Object &Obj, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList &Attributes);

		int32_t CopyObject(TElPKCS11Object *Obj, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList *Attributes);
#endif /* SB_USE_CLASSES_TELPKCS11ATTRIBUTELIST_AND_TELPKCS11OBJECT */

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11ObjectHandle GetObjectByHandle(uint32_t Handle);
#else
		TElPKCS11ObjectHandle GetObjectByHandle(int64_t Handle);
#endif
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
		TElPKCS11ObjectHandle GetObjectBySubjectOrID(TSBPKCS11ObjectType ObjectType, const std::vector<uint8_t> &Subject, const std::vector<uint8_t> &ID);
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
		TElPKCS11ObjectHandle GetObjectBySubjectOrID(TSBPKCS11ObjectType ObjectType, const std::vector<uint8_t> &Subject, const std::vector<uint8_t> &ID, bool SubjectMustMatch, bool IDMustMatch);
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

		bool Close();

		void Login(TElPKCS11UserType UserType, const std::string &PIN);

		void Logout();

		void ClearObjectInstances();

		void RefreshObjectList();

		void UpdateObjectList();

		void AcquireSession();

		void ReleaseSession();

		void InitPIN(const std::string &Pin);

		void SetPIN(const std::string &OldPin, const std::string &NewPin);

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
		virtual TElPKCS11Consumer* get_Consumer();

		SB_DECLARE_PROPERTY_GET(TElPKCS11Consumer*, get_Consumer, TElPKCS11SessionInfo, Consumer);
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
		virtual TElPKCS11SlotInfo* get_Slot();

		SB_DECLARE_PROPERTY_GET(TElPKCS11SlotInfo*, get_Slot, TElPKCS11SessionInfo, Slot);
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

#ifdef SB_NOT_CPU64_OR_WINDOWS
		virtual uint32_t get_Handle();
#else
		virtual int64_t get_Handle();
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		SB_DECLARE_PROPERTY_GET(uint32_t, get_Handle, TElPKCS11SessionInfo, Handle);
#else
		SB_DECLARE_PROPERTY_GET(int64_t, get_Handle, TElPKCS11SessionInfo, Handle);
#endif

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual TElCustomCryptoProvider* get_CryptoProvider();

		virtual void set_CryptoProvider(TElCustomCryptoProvider &Value);

		virtual void set_CryptoProvider(TElCustomCryptoProvider *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProvider*, get_CryptoProvider, set_CryptoProvider, TElPKCS11SessionInfo, CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		virtual int32_t get_ObjectCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ObjectCount, TElPKCS11SessionInfo, ObjectCount);

		virtual TSBPKCS11TokenAccessMode get_TokenAccessMode();

		virtual void set_TokenAccessMode(TSBPKCS11TokenAccessMode Value);

		SB_DECLARE_PROPERTY(TSBPKCS11TokenAccessMode, get_TokenAccessMode, set_TokenAccessMode, TElPKCS11SessionInfo, TokenAccessMode);

		virtual bool get_IsOnDemandSession();

		SB_DECLARE_PROPERTY_GET(bool, get_IsOnDemandSession, TElPKCS11SessionInfo, IsOnDemandSession);

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
		virtual TElPKCS11Object* get_Objects(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

		virtual bool get_TokenProps(int32_t Index);

		TElPKCS11SessionInfo(TElPKCS11SessionInfoHandle handle, TElOwnHandle ownHandle);

		TElPKCS11SessionInfo();

		virtual ~TElPKCS11SessionInfo();

};
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
class TElPKCS11Consumer: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11Consumer)
	public:
		virtual void get_UniqueID(std::vector<uint8_t> &OutResult);

		TElPKCS11Consumer(TElPKCS11ConsumerHandle handle, TElOwnHandle ownHandle);

		TElPKCS11Consumer();

};
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */
#else

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
class TElPKCS11SessionInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11SessionInfo)
#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
		TElPKCS11Consumer* _Inst_Consumer;
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */
#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
		TElPKCS11SlotInfo* _Inst_Slot;
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProvider* _Inst_CryptoProvider;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELPKCS11OBJECT
		TElPKCS11Object* _Inst_Objects;
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
		int32_t AddObject(TSBPKCS11ObjectType ObjectType, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList &Attributes);

		int32_t AddObject(TSBPKCS11ObjectType ObjectType, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList *Attributes);
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
		int32_t AddObject(TSBPKCS11ObjectType ObjectType, bool Token, TElPKCS11AttributeList &Attributes);

		int32_t AddObject(TSBPKCS11ObjectType ObjectType, bool Token, TElPKCS11AttributeList *Attributes);
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifndef CPU64
		int32_t AddGeneratedObject(uint32_t Handle);
#else
		int32_t AddGeneratedObject(int64_t Handle);
#endif

		void RemoveObject(int32_t Index);

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
		void RemoveObject(TElPKCS11Object &Obj);

		void RemoveObject(TElPKCS11Object *Obj);
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

#ifndef CPU64
		void RemoveObjectByHandle(uint32_t Handle);
#else
		void RemoveObjectByHandle(int64_t Handle);
#endif

		void ClearObjects();

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
		int32_t CopyObject(int32_t Index, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList &Attributes);

		int32_t CopyObject(int32_t Index, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList *Attributes);
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifdef SB_USE_CLASSES_TELPKCS11ATTRIBUTELIST_AND_TELPKCS11OBJECT
		int32_t CopyObject(TElPKCS11Object &Obj, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList &Attributes);

		int32_t CopyObject(TElPKCS11Object *Obj, bool Token, bool Private, bool Modifiable, TElPKCS11AttributeList *Attributes);
#endif /* SB_USE_CLASSES_TELPKCS11ATTRIBUTELIST_AND_TELPKCS11OBJECT */

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
#ifndef CPU64
		TElPKCS11ObjectHandle GetObjectByHandle(uint32_t Handle);
#else
		TElPKCS11ObjectHandle GetObjectByHandle(int64_t Handle);
#endif
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
		TElPKCS11ObjectHandle GetObjectBySubjectOrID(TSBPKCS11ObjectType ObjectType, const std::vector<uint8_t> &Subject, const std::vector<uint8_t> &ID);
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
		TElPKCS11ObjectHandle GetObjectBySubjectOrID(TSBPKCS11ObjectType ObjectType, const std::vector<uint8_t> &Subject, const std::vector<uint8_t> &ID, bool SubjectMustMatch, bool IDMustMatch);
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

		bool Close();

		void Login(TElPKCS11UserType UserType, const std::string &PIN);

		void Logout();

		void ClearObjectInstances();

		void RefreshObjectList();

		void UpdateObjectList();

		void AcquireSession();

		void ReleaseSession();

		void InitPIN(const std::string &Pin);

		void SetPIN(const std::string &OldPin, const std::string &NewPin);

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
		virtual TElPKCS11Consumer* get_Consumer();

		SB_DECLARE_PROPERTY_GET(TElPKCS11Consumer*, get_Consumer, TElPKCS11SessionInfo, Consumer);
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */

#ifdef SB_USE_CLASS_TELPKCS11SLOTINFO
		virtual TElPKCS11SlotInfo* get_Slot();

		SB_DECLARE_PROPERTY_GET(TElPKCS11SlotInfo*, get_Slot, TElPKCS11SessionInfo, Slot);
#endif /* SB_USE_CLASS_TELPKCS11SLOTINFO */

#ifndef CPU64
		virtual uint32_t get_Handle();
#else
		virtual int64_t get_Handle();
#endif

#ifndef CPU64
		SB_DECLARE_PROPERTY_GET(uint32_t, get_Handle, TElPKCS11SessionInfo, Handle);
#else
		SB_DECLARE_PROPERTY_GET(int64_t, get_Handle, TElPKCS11SessionInfo, Handle);
#endif

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual TElCustomCryptoProvider* get_CryptoProvider();

		virtual void set_CryptoProvider(TElCustomCryptoProvider &Value);

		virtual void set_CryptoProvider(TElCustomCryptoProvider *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProvider*, get_CryptoProvider, set_CryptoProvider, TElPKCS11SessionInfo, CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		virtual int32_t get_ObjectCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ObjectCount, TElPKCS11SessionInfo, ObjectCount);

		virtual TSBPKCS11TokenAccessMode get_TokenAccessMode();

		virtual void set_TokenAccessMode(TSBPKCS11TokenAccessMode Value);

		SB_DECLARE_PROPERTY(TSBPKCS11TokenAccessMode, get_TokenAccessMode, set_TokenAccessMode, TElPKCS11SessionInfo, TokenAccessMode);

		virtual bool get_IsOnDemandSession();

		SB_DECLARE_PROPERTY_GET(bool, get_IsOnDemandSession, TElPKCS11SessionInfo, IsOnDemandSession);

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
		virtual TElPKCS11Object* get_Objects(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

		virtual bool get_TokenProps(int32_t Index);

		TElPKCS11SessionInfo(TElPKCS11SessionInfoHandle handle, TElOwnHandle ownHandle);

		TElPKCS11SessionInfo();

		virtual ~TElPKCS11SessionInfo();

};
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
class TElPKCS11FunctionsManager: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11FunctionsManager)
	public:
#ifndef CPU64
		uint32_t GetFunctionList(PPKCS11FunctionList &FunctionList);
#else
		int64_t GetFunctionList(PPKCS11FunctionList &FunctionList);
#endif

#ifndef CPU64
		uint32_t Initialize(PPKCS11InitializeArgs pArgs);
#else
		int64_t Initialize(PPKCS11InitializeArgs pArgs);
#endif

#ifndef CPU64
		uint32_t Finalize(void * pReserved);
#else
		int64_t Finalize(void * pReserved);
#endif

#ifndef CPU64
		uint32_t GetInfo(TPKCS11Info &pInfo);
#else
		int64_t GetInfo(TPKCS11Info &pInfo);
#endif

#ifndef CPU64
		uint32_t GetSlotList(uint8_t tokenPresent, uint32_t &pSlotList, uint32_t &pulCount);
#else
		int64_t GetSlotList(uint8_t tokenPresent, int64_t &pSlotList, int64_t &pulCount);
#endif

#ifndef CPU64
		uint32_t GetSlotInfo(uint32_t slotID, TPKCS11SlotInfo &pInfo);
#else
		int64_t GetSlotInfo(int64_t slotID, TPKCS11SlotInfo &pInfo);
#endif

#ifndef CPU64
		uint32_t GetTokenInfo(uint32_t slotID, TPKCS11TokenInfo &pInfo);
#else
		int64_t GetTokenInfo(int64_t slotID, TPKCS11TokenInfo &pInfo);
#endif

#ifndef CPU64
		uint32_t OpenSession(uint32_t slotID, uint32_t flags, void * CallbackData, void * NotifyProc, uint32_t &SessionHandle);
#else
		int64_t OpenSession(int64_t slotID, int64_t flags, void * CallbackData, void * NotifyProc, int64_t &SessionHandle);
#endif

#ifndef CPU64
		uint32_t GetSessionInfo(uint32_t hSession, TPKCS11SessionInfo &pInfo);
#else
		int64_t GetSessionInfo(int64_t hSession, TPKCS11SessionInfo &pInfo);
#endif

#ifndef CPU64
		uint32_t CloseSession(uint32_t hSession);
#else
		int64_t CloseSession(int64_t hSession);
#endif

#ifndef CPU64
		uint32_t Login(uint32_t hSession, uint32_t userType, char * pPin, uint32_t ulPinLen);
#else
		int64_t Login(int64_t hSession, int64_t userType, char * pPin, int64_t ulPinLen);
#endif

#ifndef CPU64
		uint32_t Logout(uint32_t hSession);
#else
		int64_t Logout(int64_t hSession);
#endif

#ifndef CPU64
		uint32_t FindObjectsInit(uint32_t hSession, SB_CK_ATTRIBUTE_PTR pAttributes, uint32_t ulCount);
#else
		int64_t FindObjectsInit(int64_t hSession, SB_CK_ATTRIBUTE_PTR pAttributes, int64_t ulCount);
#endif

#ifndef CPU64
		uint32_t FindObjects(uint32_t hSession, uint32_t &phObject, uint32_t ulMaxObjectCount, uint32_t &pulObjectCount);
#else
		int64_t FindObjects(int64_t hSession, int64_t &phObject, int64_t ulMaxObjectCount, int64_t &pulObjectCount);
#endif

#ifndef CPU64
		uint32_t FindObjectsFinal(uint32_t hSession);
#else
		int64_t FindObjectsFinal(int64_t hSession);
#endif

#ifndef CPU64
		uint32_t GetAttributeValue(uint32_t hSession, uint32_t hObject, void * pTemplate, uint32_t ulCount);
#else
		int64_t GetAttributeValue(int64_t hSession, int64_t hObject, void * pTemplate, int64_t ulCount);
#endif

#ifndef CPU64
		uint32_t DestroyObject(uint32_t hSession, uint32_t hObject);
#else
		int64_t DestroyObject(int64_t hSession, int64_t hObject);
#endif

#ifndef CPU64
		uint32_t CreateObject(uint32_t hSession, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t &hObject);
#else
		int64_t CreateObject(int64_t hSession, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t &hObject);
#endif

#ifndef CPU64
		uint32_t SignInit(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey);
#else
		int64_t SignInit(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey);
#endif

#ifndef CPU64
		uint32_t Sign(uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pSignature, uint32_t * pulSignatureLen);
#else
		int64_t Sign(int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pSignature, int64_t * pulSignatureLen);
#endif

#ifndef CPU64
		uint32_t DecryptInit(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey);
#else
		int64_t DecryptInit(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey);
#endif

#ifndef CPU64
		uint32_t Decrypt(uint32_t hSession, uint8_t * pEncryptedData, uint32_t ulEncryptedDataLen, uint8_t * pData, uint32_t * pulDataLen);
#else
		int64_t Decrypt(int64_t hSession, uint8_t * pEncryptedData, int64_t ulEncryptedDataLen, uint8_t * pData, int64_t * pulDataLen);
#endif

#ifndef CPU64
		uint32_t WaitForSlotEvent(uint32_t flags, uint32_t &pSlot, void * pReserved);
#else
		int64_t WaitForSlotEvent(int64_t flags, int64_t &pSlot, void * pReserved);
#endif

#ifndef CPU64
		uint32_t GetMechanismList(uint32_t slotID, uint32_t * pMechanismList, uint32_t &pulCount);
#else
		int64_t GetMechanismList(int64_t slotID, int64_t * pMechanismList, int64_t &pulCount);
#endif

#ifndef CPU64
		uint32_t GetMechanismInfo(uint32_t slotID, uint32_t mechanism_type, TPKCS11MechanismInfo &pInfo);
#else
		int64_t GetMechanismInfo(int64_t slotID, int64_t mechanism_type, TPKCS11MechanismInfo &pInfo);
#endif

#ifndef CPU64
		uint32_t InitToken(uint32_t slotID, char * pPin, uint32_t ulPinLen, char * pLabel);
#else
		int64_t InitToken(int64_t slotID, char * pPin, int64_t ulPinLen, char * pLabel);
#endif

#ifndef CPU64
		uint32_t InitPIN(uint32_t hSession, char * pPin, uint32_t ulPinLen);
#else
		int64_t InitPIN(int64_t hSession, char * pPin, int64_t ulPinLen);
#endif

#ifndef CPU64
		uint32_t SetPIN(uint32_t hSession, char * pOldPin, uint32_t ulOldLen, char * pNewPin, uint32_t ulNewLen);
#else
		int64_t SetPIN(int64_t hSession, char * pOldPin, int64_t ulOldLen, char * pNewPin, int64_t ulNewLen);
#endif

#ifndef CPU64
		uint32_t CloseAllSessions(uint32_t slotID);
#else
		int64_t CloseAllSessions(int64_t slotID);
#endif

#ifndef CPU64
		uint32_t GetOperationState(uint32_t hSession, uint8_t &pOperationState, uint32_t &pulOperationStateLen);
#else
		int64_t GetOperationState(int64_t hSession, uint8_t &pOperationState, int64_t &pulOperationStateLen);
#endif

#ifndef CPU64
		uint32_t SetOperationState(uint32_t hSession, uint8_t * pOperationState, uint32_t ulOperationStateLen, uint32_t hEncryptionKey, uint32_t hAuthenticationKey);
#else
		int64_t SetOperationState(int64_t hSession, uint8_t * pOperationState, int64_t ulOperationStateLen, int64_t hEncryptionKey, int64_t hAuthenticationKey);
#endif

#ifndef CPU64
		uint32_t CopyObject(uint32_t hSession, uint32_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t &phNewObject);
#else
		int64_t CopyObject(int64_t hSession, int64_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t &phNewObject);
#endif

#ifndef CPU64
		uint32_t GetObjectSize(uint32_t hSession, uint32_t hObject, uint32_t &pulSize);
#else
		int64_t GetObjectSize(int64_t hSession, int64_t hObject, int64_t &pulSize);
#endif

#ifndef CPU64
		uint32_t SetAttributeValue(uint32_t hSession, uint32_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount);
#else
		int64_t SetAttributeValue(int64_t hSession, int64_t hObject, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount);
#endif

#ifndef CPU64
		uint32_t EncryptInit(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey);
#else
		int64_t EncryptInit(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey);
#endif

#ifndef CPU64
		uint32_t Encrypt(uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pEncryptedData, uint32_t &pulEncryptedDataLen);
#else
		int64_t Encrypt(int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pEncryptedData, int64_t &pulEncryptedDataLen);
#endif

#ifndef CPU64
		uint32_t EncryptUpdate(uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint8_t * pEncryptedPart, uint32_t &pulEncryptedPartLen);
#else
		int64_t EncryptUpdate(int64_t hSession, uint8_t * pPart, int64_t ulPartLen, uint8_t * pEncryptedPart, int64_t &pulEncryptedPartLen);
#endif

#ifndef CPU64
		uint32_t EncryptFinal(uint32_t hSession, uint8_t * pLastEncryptedPart, uint32_t &pulLastEncryptedPartLen);
#else
		int64_t EncryptFinal(int64_t hSession, uint8_t * pLastEncryptedPart, int64_t &pulLastEncryptedPartLen);
#endif

#ifndef CPU64
		uint32_t DecryptUpdate(uint32_t hSession, uint8_t * pEncryptedPart, uint32_t ulEncryptedPartLen, uint8_t * pPart, uint32_t &pulPartLen);
#else
		int64_t DecryptUpdate(int64_t hSession, uint8_t * pEncryptedPart, int64_t ulEncryptedPartLen, uint8_t * pPart, int64_t &pulPartLen);
#endif

#ifndef CPU64
		uint32_t DecryptFinal(uint32_t hSession, uint8_t * pLastPart, uint32_t &pulLastPartLen);
#else
		int64_t DecryptFinal(int64_t hSession, uint8_t * pLastPart, int64_t &pulLastPartLen);
#endif

#ifndef CPU64
		uint32_t DigestInit(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism);
#else
		int64_t DigestInit(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism);
#endif

#ifndef CPU64
		uint32_t Digest(uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t &pDigest, uint32_t &pulDigestLen);
#else
		int64_t Digest(int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t &pDigest, int64_t &pulDigestLen);
#endif

#ifndef CPU64
		uint32_t DigestUpdate(uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen);
#else
		int64_t DigestUpdate(int64_t hSession, uint8_t * pPart, int64_t ulPartLen);
#endif

#ifndef CPU64
		uint32_t DigestKey(uint32_t hSession, uint32_t hKey);
#else
		int64_t DigestKey(int64_t hSession, int64_t hKey);
#endif

#ifndef CPU64
		uint32_t DigestFinal(uint32_t hSession, uint8_t * pDigest, uint32_t &pulDigestLen);
#else
		int64_t DigestFinal(int64_t hSession, uint8_t * pDigest, int64_t &pulDigestLen);
#endif

#ifndef CPU64
		uint32_t SignUpdate(uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen);
#else
		int64_t SignUpdate(int64_t hSession, uint8_t * pPart, int64_t ulPartLen);
#endif

#ifndef CPU64
		uint32_t SignFinal(uint32_t hSession, uint8_t * pSignature, uint32_t &pulSignatureLen);
#else
		int64_t SignFinal(int64_t hSession, uint8_t * pSignature, int64_t &pulSignatureLen);
#endif

#ifndef CPU64
		uint32_t SignRecoverInit(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey);
#else
		int64_t SignRecoverInit(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey);
#endif

#ifndef CPU64
		uint32_t SignRecover(uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t &pSignature, uint32_t &pulSignatureLen);
#else
		int64_t SignRecover(int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t &pSignature, int64_t &pulSignatureLen);
#endif

#ifndef CPU64
		uint32_t VerifyInit(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey);
#else
		int64_t VerifyInit(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey);
#endif

#ifndef CPU64
		uint32_t Verify(uint32_t hSession, uint8_t * pData, uint32_t ulDataLen, uint8_t * pSignature, uint32_t ulSignatureLen);
#else
		int64_t Verify(int64_t hSession, uint8_t * pData, int64_t ulDataLen, uint8_t * pSignature, int64_t ulSignatureLen);
#endif

#ifndef CPU64
		uint32_t VerifyUpdate(uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen);
#else
		int64_t VerifyUpdate(int64_t hSession, uint8_t * pPart, int64_t ulPartLen);
#endif

#ifndef CPU64
		uint32_t VerifyFinal(uint32_t hSession, uint8_t * pSignature, uint32_t ulSignatureLen);
#else
		int64_t VerifyFinal(int64_t hSession, uint8_t * pSignature, int64_t ulSignatureLen);
#endif

#ifndef CPU64
		uint32_t VerifyRecoverInit(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hKey);
#else
		int64_t VerifyRecoverInit(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hKey);
#endif

#ifndef CPU64
		uint32_t VerifyRecover(uint32_t hSession, uint8_t * pSignature, uint32_t ulSignatureLen, uint8_t &pData, uint32_t &pulDataLen);
#else
		int64_t VerifyRecover(int64_t hSession, uint8_t * pSignature, int64_t ulSignatureLen, uint8_t &pData, int64_t &pulDataLen);
#endif

#ifndef CPU64
		uint32_t DigestEncryptUpdate(uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint8_t &pEncryptedPart, uint32_t &pulEncryptedPartLen);
#else
		int64_t DigestEncryptUpdate(int64_t hSession, uint8_t * pPart, int64_t ulPartLen, uint8_t &pEncryptedPart, int64_t &pulEncryptedPartLen);
#endif

#ifndef CPU64
		uint32_t DecryptDigestUpdate(uint32_t hSession, uint8_t * pEncryptedPart, uint32_t ulEncryptedPartLen, uint8_t &pPart, uint32_t &pulPartLen);
#else
		int64_t DecryptDigestUpdate(int64_t hSession, uint8_t * pEncryptedPart, int64_t ulEncryptedPartLen, uint8_t &pPart, int64_t &pulPartLen);
#endif

#ifndef CPU64
		uint32_t SignEncryptUpdate(uint32_t hSession, uint8_t * pPart, uint32_t ulPartLen, uint8_t &pEncryptedPart, uint32_t &pulEncryptedPartLen);
#else
		int64_t SignEncryptUpdate(int64_t hSession, uint8_t * pPart, int64_t ulPartLen, uint8_t &pEncryptedPart, int64_t &pulEncryptedPartLen);
#endif

#ifndef CPU64
		uint32_t DecryptVerifyUpdate(uint32_t hSession, uint8_t * pEncryptedPart, uint32_t ulEncryptedPartLen, uint8_t &pPart, uint32_t &pulPartLen);
#else
		int64_t DecryptVerifyUpdate(int64_t hSession, uint8_t * pEncryptedPart, int64_t ulEncryptedPartLen, uint8_t &pPart, int64_t &pulPartLen);
#endif

#ifndef CPU64
		uint32_t GenerateKey(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulCount, uint32_t &phKey);
#else
		int64_t GenerateKey(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulCount, int64_t &phKey);
#endif

#ifndef CPU64
		uint32_t GenerateKeyPair(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pPublicKeyTemplate, uint32_t ulPublicKeyAttributeCount, SB_CK_ATTRIBUTE_PTR pPrivateKeyTemplate, uint32_t ulPrivateKeyAttributeCount, uint32_t &phPublicKey, uint32_t &phPrivateKey);
#else
		int64_t GenerateKeyPair(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, SB_CK_ATTRIBUTE_PTR pPublicKeyTemplate, int64_t ulPublicKeyAttributeCount, SB_CK_ATTRIBUTE_PTR pPrivateKeyTemplate, int64_t ulPrivateKeyAttributeCount, int64_t &phPublicKey, int64_t &phPrivateKey);
#endif

#ifndef CPU64
		uint32_t WrapKey(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hWrappingKey, uint32_t hKey, uint8_t * pWrappedKey, uint32_t &pulWrappedKeyLen);
#else
		int64_t WrapKey(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hWrappingKey, int64_t hKey, uint8_t * pWrappedKey, int64_t &pulWrappedKeyLen);
#endif

#ifndef CPU64
		uint32_t UnwrapKey(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hUnwrappingKey, uint8_t * pWrappedKey, uint32_t ulWrappedKeyLen, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulAttributeCount, uint32_t &phKey);
#else
		int64_t UnwrapKey(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hUnwrappingKey, uint8_t * pWrappedKey, int64_t ulWrappedKeyLen, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulAttributeCount, int64_t &phKey);
#endif

#ifndef CPU64
		uint32_t DeriveKey(uint32_t hSession, SB_CK_MECHANISM_PTR pMechanism, uint32_t hBaseKey, SB_CK_ATTRIBUTE_PTR pTemplate, uint32_t ulAttributeCount, uint32_t &phKey);
#else
		int64_t DeriveKey(int64_t hSession, SB_CK_MECHANISM_PTR pMechanism, int64_t hBaseKey, SB_CK_ATTRIBUTE_PTR pTemplate, int64_t ulAttributeCount, int64_t &phKey);
#endif

#ifndef CPU64
		uint32_t SeedRandom(uint32_t hSession, uint8_t * pSeed, uint32_t ulSeedLen);
#else
		int64_t SeedRandom(int64_t hSession, uint8_t * pSeed, int64_t ulSeedLen);
#endif

#ifndef CPU64
		uint32_t GenerateRandom(uint32_t hSession, uint8_t * pRandomData, uint32_t ulRandomLen);
#else
		int64_t GenerateRandom(int64_t hSession, uint8_t * pRandomData, int64_t ulRandomLen);
#endif

#ifndef CPU64
		uint32_t GetFunctionStatus(uint32_t hSession);
#else
		int64_t GetFunctionStatus(int64_t hSession);
#endif

#ifndef CPU64
		uint32_t CancelFunction(uint32_t hSession);
#else
		int64_t CancelFunction(int64_t hSession);
#endif

		virtual void get_UniqueID(std::vector<uint8_t> &OutResult);

		virtual void get_OnUniqueIDNeeded(TSBUniqueIDNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnUniqueIDNeeded(TSBUniqueIDNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnGetFunctionListNeeded(TSBGetFunctionListNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetFunctionListNeeded(TSBGetFunctionListNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnInitializeNeeded(TSBInitializeNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnInitializeNeeded(TSBInitializeNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnFinalizeNeeded(TSBFinalizeNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFinalizeNeeded(TSBFinalizeNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnGetInfoNeeded(TSBGetInfoNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetInfoNeeded(TSBGetInfoNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnGetSlotListNeeded(TSBGetSlotListNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetSlotListNeeded(TSBGetSlotListNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnGetSlotInfoNeeded(TSBGetSlotInfoNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetSlotInfoNeeded(TSBGetSlotInfoNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnGetTokenInfoNeeded(TSBGetTokenInfoNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetTokenInfoNeeded(TSBGetTokenInfoNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnOpenSessionNeeded(TSBOpenSessionNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpenSessionNeeded(TSBOpenSessionNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnGetSessionInfoNeeded(TSBGetSessionInfoNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetSessionInfoNeeded(TSBGetSessionInfoNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnCloseSessionNeeded(TSBCloseSessionNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseSessionNeeded(TSBCloseSessionNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnLoginNeeded(TSBLoginNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnLoginNeeded(TSBLoginNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnLogoutNeeded(TSBLogoutNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnLogoutNeeded(TSBLogoutNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnFindObjectsInitNeeded(TSBFindObjectsInitNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFindObjectsInitNeeded(TSBFindObjectsInitNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnFindObjectsNeeded(TSBFindObjectsNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFindObjectsNeeded(TSBFindObjectsNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnFindObjectsFinalNeeded(TSBFindObjectsFinalNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFindObjectsFinalNeeded(TSBFindObjectsFinalNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnGetAttributeValueNeeded(TSBGetAttributeValueNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetAttributeValueNeeded(TSBGetAttributeValueNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDestroyObjectNeeded(TSBDestroyObjectNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDestroyObjectNeeded(TSBDestroyObjectNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnCreateObjectNeeded(TSBCreateObjectNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCreateObjectNeeded(TSBCreateObjectNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnSignInitNeeded(TSBSignInitNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSignInitNeeded(TSBSignInitNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnSignNeeded(TSBSignNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSignNeeded(TSBSignNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDecryptInitNeeded(TSBDecryptInitNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDecryptInitNeeded(TSBDecryptInitNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDecryptNeeded(TSBDecryptNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDecryptNeeded(TSBDecryptNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnWaitForSlotEventNeeded(TSBWaitForSlotEventNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnWaitForSlotEventNeeded(TSBWaitForSlotEventNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnGetMechanismListNeeded(TSBGetMechanismListNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetMechanismListNeeded(TSBGetMechanismListNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnGetMechanismInfoNeeded(TSBGetMechanismInfoNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetMechanismInfoNeeded(TSBGetMechanismInfoNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnInitTokenNeeded(TSBInitTokenNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnInitTokenNeeded(TSBInitTokenNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnInitPINNeeded(TSBInitPINNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnInitPINNeeded(TSBInitPINNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnSetPINNeeded(TSBSetPINNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSetPINNeeded(TSBSetPINNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnCloseAllSessionsNeeded(TSBCloseAllSessionsNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseAllSessionsNeeded(TSBCloseAllSessionsNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnGetOperationStateNeeded(TSBGetOperationStateNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetOperationStateNeeded(TSBGetOperationStateNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnSetOperationStateNeeded(TSBSetOperationStateNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSetOperationStateNeeded(TSBSetOperationStateNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnCopyObjectNeeded(TSBCopyObjectNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCopyObjectNeeded(TSBCopyObjectNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnGetObjectSizeNeeded(TSBGetObjectSizeNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetObjectSizeNeeded(TSBGetObjectSizeNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnSetAttributeValueNeeded(TSBSetAttributeValueNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSetAttributeValueNeeded(TSBSetAttributeValueNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnEncryptInitNeeded(TSBEncryptInitNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnEncryptInitNeeded(TSBEncryptInitNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnEncryptNeeded(TSBEncryptNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnEncryptNeeded(TSBEncryptNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnEncryptUpdateNeeded(TSBEncryptUpdateNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnEncryptUpdateNeeded(TSBEncryptUpdateNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnEncryptFinalNeeded(TSBEncryptFinalNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnEncryptFinalNeeded(TSBEncryptFinalNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDecryptUpdateNeeded(TSBDecryptUpdateNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDecryptUpdateNeeded(TSBDecryptUpdateNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDecryptFinalNeeded(TSBDecryptFinalNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDecryptFinalNeeded(TSBDecryptFinalNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDigestInitNeeded(TSBDigestInitNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDigestInitNeeded(TSBDigestInitNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDigestNeeded(TSBDigestNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDigestNeeded(TSBDigestNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDigestUpdateNeeded(TSBDigestUpdateNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDigestUpdateNeeded(TSBDigestUpdateNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDigestKeyNeeded(TSBDigestKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDigestKeyNeeded(TSBDigestKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDigestFinalNeeded(TSBDigestFinalNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDigestFinalNeeded(TSBDigestFinalNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnSignUpdateNeeded(TSBSignUpdateNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSignUpdateNeeded(TSBSignUpdateNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnSignFinalNeeded(TSBSignFinalNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSignFinalNeeded(TSBSignFinalNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnSignRecoverInitNeeded(TSBSignRecoverInitNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSignRecoverInitNeeded(TSBSignRecoverInitNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnSignRecoverNeeded(TSBSignRecoverNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSignRecoverNeeded(TSBSignRecoverNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnVerifyInitNeeded(TSBVerifyInitNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnVerifyInitNeeded(TSBVerifyInitNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnVerifyNeeded(TSBVerifyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnVerifyNeeded(TSBVerifyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnVerifyUpdateNeeded(TSBVerifyUpdateNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnVerifyUpdateNeeded(TSBVerifyUpdateNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnVerifyFinalNeeded(TSBVerifyFinalNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnVerifyFinalNeeded(TSBVerifyFinalNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnVerifyRecoverInitNeeded(TSBVerifyRecoverInitNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnVerifyRecoverInitNeeded(TSBVerifyRecoverInitNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnVerifyRecoverNeeded(TSBVerifyRecoverNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnVerifyRecoverNeeded(TSBVerifyRecoverNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDigestEncryptUpdateNeeded(TSBDigestEncryptUpdateNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDigestEncryptUpdateNeeded(TSBDigestEncryptUpdateNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDecryptDigestUpdateNeeded(TSBDecryptDigestUpdateNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDecryptDigestUpdateNeeded(TSBDecryptDigestUpdateNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnSignEncryptUpdateNeeded(TSBSignEncryptUpdateNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSignEncryptUpdateNeeded(TSBSignEncryptUpdateNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDecryptVerifyUpdateNeeded(TSBDecryptVerifyUpdateNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDecryptVerifyUpdateNeeded(TSBDecryptVerifyUpdateNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnGenerateKeyNeeded(TSBGenerateKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGenerateKeyNeeded(TSBGenerateKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnGenerateKeyPairNeeded(TSBGenerateKeyPairNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGenerateKeyPairNeeded(TSBGenerateKeyPairNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnWrapKeyNeeded(TSBWrapKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnWrapKeyNeeded(TSBWrapKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnUnwrapKeyNeeded(TSBUnwrapKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnUnwrapKeyNeeded(TSBUnwrapKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnDeriveKeyNeeded(TSBDeriveKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDeriveKeyNeeded(TSBDeriveKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnSeedRandomNeeded(TSBSeedRandomNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSeedRandomNeeded(TSBSeedRandomNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnGenerateRandomNeeded(TSBGenerateRandomNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGenerateRandomNeeded(TSBGenerateRandomNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnGetFunctionStatusNeeded(TSBGetFunctionStatusNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetFunctionStatusNeeded(TSBGetFunctionStatusNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnCancelFunctionNeeded(TSBCancelFunctionNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCancelFunctionNeeded(TSBCancelFunctionNeededEvent pMethodValue, void * pDataValue);

		TElPKCS11FunctionsManager(TElPKCS11FunctionsManagerHandle handle, TElOwnHandle ownHandle);

		TElPKCS11FunctionsManager();

};
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */

#ifdef SB_USE_CLASS_TELPKCS11CONSUMER
class TElPKCS11Consumer: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11Consumer)
	public:
		virtual void get_UniqueID(std::vector<uint8_t> &OutResult);

		TElPKCS11Consumer(TElPKCS11ConsumerHandle handle, TElOwnHandle ownHandle);

		TElPKCS11Consumer();

};
#endif /* SB_USE_CLASS_TELPKCS11CONSUMER */
#endif

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
class TElPKCS11AttributeList: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11AttributeList)
	public:
		void Assign(TElPKCS11AttributeList &Source);

		void Assign(TElPKCS11AttributeList *Source);

		int32_t Add();

#ifdef SB_NOT_CPU64_OR_WINDOWS
		int32_t Add(uint32_t Attribute, const std::vector<uint8_t> &Value);
#else
		int32_t Add(int64_t Attribute, const std::vector<uint8_t> &Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		int32_t Add(uint32_t Attribute, uint32_t Value);
#else
		int32_t Add(int64_t Attribute, int64_t Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		int32_t Add(uint32_t Attribute, bool Value);
#else
		int32_t Add(int64_t Attribute, bool Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		int32_t AddByte(uint32_t Attribute, uint8_t Value);
#else
		int32_t AddByte(int64_t Attribute, uint8_t Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		int32_t AddWord(uint32_t Attribute, uint16_t Value);
#else
		int32_t AddWord(int64_t Attribute, uint16_t Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		int32_t AddThreeByteInteger(uint32_t Attribute, uint32_t Value);
#else
		int32_t AddThreeByteInteger(int64_t Attribute, int64_t Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		int32_t AddIntegerOptEnc(uint32_t Attribute, uint32_t Value);
#else
		int32_t AddIntegerOptEnc(int64_t Attribute, int64_t Value);
#endif

		void Insert(int32_t Index);

#ifdef SB_NOT_CPU64_OR_WINDOWS
		void Insert(int32_t Index, uint32_t Attribute, const std::vector<uint8_t> &Value);
#else
		void Insert(int32_t Index, int64_t Attribute, const std::vector<uint8_t> &Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		void Insert(int32_t Index, uint32_t Attribute, uint32_t Value);
#else
		void Insert(int32_t Index, int64_t Attribute, int64_t Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		void Insert(int32_t Index, uint32_t Attribute, bool Value);
#else
		void Insert(int32_t Index, int64_t Attribute, bool Value);
#endif

		void Remove(int32_t Index);

		void Clear();

		void Serialize(void * Buffer, int32_t &Size);

		void ToString(std::string &OutResult);

#ifdef SB_NOT_CPU64_OR_WINDOWS
		virtual uint32_t get_Attributes(int32_t Index);
#else
		virtual int64_t get_Attributes(int32_t Index);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		virtual void set_Attributes(int32_t Index, uint32_t Value);
#else
		virtual void set_Attributes(int32_t Index, int64_t Value);
#endif

		virtual void get_Values(int32_t Index, std::vector<uint8_t> &OutResult);

		virtual void set_Values(int32_t Index, const std::vector<uint8_t> &Value);

		virtual int32_t get_Count();

		virtual void set_Count(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Count, set_Count, TElPKCS11AttributeList, Count);

		TElPKCS11AttributeList(TElPKCS11AttributeListHandle handle, TElOwnHandle ownHandle);

		TElPKCS11AttributeList();

};
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifdef SB_USE_CLASS_TELPKCS11OBJECT
class TElPKCS11Object: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11Object)
#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfo* _Inst_Session;
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProvider* _Inst_CryptoProvider;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		void initInstances();

	public:
#ifdef SB_NOT_CPU64_OR_WINDOWS
		void SetAttribute(uint32_t Attribute, const std::vector<uint8_t> &Value);
#else
		void SetAttribute(int64_t Attribute, const std::vector<uint8_t> &Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		void SetAttribute(uint32_t Attribute, uint32_t Value);
#else
		void SetAttribute(int64_t Attribute, int64_t Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		void SetAttribute(uint32_t Attribute, bool Value);
#else
		void SetAttribute(int64_t Attribute, bool Value);
#endif

#ifdef SB_USE_CLASS_TELPKCS11ATTRIBUTELIST
		void SetAttributes(TElPKCS11AttributeList &Attributes);

		void SetAttributes(TElPKCS11AttributeList *Attributes);
#endif /* SB_USE_CLASS_TELPKCS11ATTRIBUTELIST */

#ifdef SB_NOT_CPU64_OR_WINDOWS
		void GetAttribute(uint32_t Attribute, std::vector<uint8_t> &OutResult);
#else
		void GetAttribute(int64_t Attribute, std::vector<uint8_t> &OutResult);
#endif

		virtual void ReadProperties();

		static TClassHandle ClassType();

		virtual TSBPKCS11ObjectType get_ObjectType();

		SB_DECLARE_PROPERTY_GET(TSBPKCS11ObjectType, get_ObjectType, TElPKCS11Object, ObjectType);

		virtual bool get_Token();

		SB_DECLARE_PROPERTY_GET(bool, get_Token, TElPKCS11Object, Token);

		virtual bool get_Private();

		SB_DECLARE_PROPERTY_GET(bool, get_Private, TElPKCS11Object, Private);

		virtual bool get_Modifiable();

		SB_DECLARE_PROPERTY_GET(bool, get_Modifiable, TElPKCS11Object, Modifiable);

		virtual void get_ObjectLabel(std::string &OutResult);

		virtual void set_ObjectLabel(const std::string &Value);

		virtual int32_t get_ObjectSize();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ObjectSize, TElPKCS11Object, ObjectSize);

#ifdef SB_NOT_CPU64_OR_WINDOWS
		virtual uint32_t get_Handle();
#else
		virtual int64_t get_Handle();
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		SB_DECLARE_PROPERTY_GET(uint32_t, get_Handle, TElPKCS11Object, Handle);
#else
		SB_DECLARE_PROPERTY_GET(int64_t, get_Handle, TElPKCS11Object, Handle);
#endif

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		virtual TElPKCS11SessionInfo* get_Session();

		SB_DECLARE_PROPERTY_GET(TElPKCS11SessionInfo*, get_Session, TElPKCS11Object, Session);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual TElCustomCryptoProvider* get_CryptoProvider();

		virtual void set_CryptoProvider(TElCustomCryptoProvider &Value);

		virtual void set_CryptoProvider(TElCustomCryptoProvider *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProvider*, get_CryptoProvider, set_CryptoProvider, TElPKCS11Object, CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		TElPKCS11Object(TElPKCS11ObjectHandle handle, TElOwnHandle ownHandle);

		TElPKCS11Object();

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11Object(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#else
		TElPKCS11Object(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11Object(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#else
		TElPKCS11Object(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#endif
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

		virtual ~TElPKCS11Object();

};
#endif /* SB_USE_CLASS_TELPKCS11OBJECT */

#ifdef SB_USE_CLASS_TELPKCS11DATAOBJECT
class TElPKCS11DataObject: public TElPKCS11Object
{
	private:
		SB_DISABLE_COPY(TElPKCS11DataObject)
	public:
		virtual void ReadProperties();

		static TClassHandle ClassType();

		virtual void get_Application(std::string &OutResult);

		virtual void set_Application(const std::string &Value);

		virtual void get_ObjectID(std::vector<uint8_t> &OutResult);

		virtual void set_ObjectID(const std::vector<uint8_t> &Value);

		virtual void get_Value(std::vector<uint8_t> &OutResult);

		virtual void set_Value(const std::vector<uint8_t> &Value);

		TElPKCS11DataObject(TElPKCS11DataObjectHandle handle, TElOwnHandle ownHandle);

		TElPKCS11DataObject();

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11DataObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#else
		TElPKCS11DataObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11DataObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#else
		TElPKCS11DataObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#endif
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

};
#endif /* SB_USE_CLASS_TELPKCS11DATAOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11CERTIFICATEOBJECT
class TElPKCS11CertificateObject: public TElPKCS11Object
{
	private:
		SB_DISABLE_COPY(TElPKCS11CertificateObject)
	public:
		virtual void ReadProperties();

		static TClassHandle ClassType();

		virtual int32_t get_CertType();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CertType, TElPKCS11CertificateObject, CertType);

		virtual bool get_Trusted();

		virtual void set_Trusted(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Trusted, set_Trusted, TElPKCS11CertificateObject, Trusted);

		virtual TSBPKCS11CertCategory get_CertCategory();

		SB_DECLARE_PROPERTY_GET(TSBPKCS11CertCategory, get_CertCategory, TElPKCS11CertificateObject, CertCategory);

		virtual void get_Checksum(std::vector<uint8_t> &OutResult);

		virtual int64_t get_StartDate();

		virtual void set_StartDate(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_StartDate, set_StartDate, TElPKCS11CertificateObject, StartDate);

		virtual int64_t get_EndDate();

		virtual void set_EndDate(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_EndDate, set_EndDate, TElPKCS11CertificateObject, EndDate);

		TElPKCS11CertificateObject(TElPKCS11CertificateObjectHandle handle, TElOwnHandle ownHandle);

		TElPKCS11CertificateObject();

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11CertificateObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#else
		TElPKCS11CertificateObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11CertificateObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#else
		TElPKCS11CertificateObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#endif
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

};
#endif /* SB_USE_CLASS_TELPKCS11CERTIFICATEOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11X509CERTIFICATEOBJECT
class TElPKCS11X509CertificateObject: public TElPKCS11CertificateObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11X509CertificateObject)
	public:
		virtual void ReadProperties();

		static TClassHandle ClassType();

		virtual void get_Subject(std::vector<uint8_t> &OutResult);

		virtual void get_KeyID(std::vector<uint8_t> &OutResult);

		virtual void set_KeyID(const std::vector<uint8_t> &Value);

		virtual void get_Issuer(std::vector<uint8_t> &OutResult);

		virtual void set_Issuer(const std::vector<uint8_t> &Value);

		virtual void get_SerialNumber(std::vector<uint8_t> &OutResult);

		virtual void set_SerialNumber(const std::vector<uint8_t> &Value);

		virtual void get_Value(std::vector<uint8_t> &OutResult);

		virtual void get_URL(std::string &OutResult);

		virtual void get_SubjectPublicKeyHash(std::vector<uint8_t> &OutResult);

		virtual void get_IssuerPublicKeyHash(std::vector<uint8_t> &OutResult);

		virtual TSBPKCS11MIDPSecurityDomain get_MIDPSecurityDomain();

		SB_DECLARE_PROPERTY_GET(TSBPKCS11MIDPSecurityDomain, get_MIDPSecurityDomain, TElPKCS11X509CertificateObject, MIDPSecurityDomain);

		TElPKCS11X509CertificateObject(TElPKCS11X509CertificateObjectHandle handle, TElOwnHandle ownHandle);

		TElPKCS11X509CertificateObject();

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11X509CertificateObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#else
		TElPKCS11X509CertificateObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11X509CertificateObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#else
		TElPKCS11X509CertificateObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#endif
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

};
#endif /* SB_USE_CLASS_TELPKCS11X509CERTIFICATEOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11WTLSCERTIFICATEOBJECT
class TElPKCS11WTLSCertificateObject: public TElPKCS11CertificateObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11WTLSCertificateObject)
	public:
		virtual void ReadProperties();

		static TClassHandle ClassType();

		virtual void get_Subject(std::vector<uint8_t> &OutResult);

		virtual void get_Issuer(std::vector<uint8_t> &OutResult);

		virtual void set_Issuer(const std::vector<uint8_t> &Value);

		virtual void get_Value(std::vector<uint8_t> &OutResult);

		virtual void get_URL(std::string &OutResult);

		virtual void get_SubjectPublicKeyHash(std::vector<uint8_t> &OutResult);

		virtual void get_IssuerPublicKeyHash(std::vector<uint8_t> &OutResult);

		TElPKCS11WTLSCertificateObject(TElPKCS11WTLSCertificateObjectHandle handle, TElOwnHandle ownHandle);

		TElPKCS11WTLSCertificateObject();

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11WTLSCertificateObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#else
		TElPKCS11WTLSCertificateObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11WTLSCertificateObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#else
		TElPKCS11WTLSCertificateObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#endif
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

};
#endif /* SB_USE_CLASS_TELPKCS11WTLSCERTIFICATEOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11X509ATTRIBUTECERTIFICATEOBJECT
class TElPKCS11X509AttributeCertificateObject: public TElPKCS11CertificateObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11X509AttributeCertificateObject)
	public:
		virtual void ReadProperties();

		static TClassHandle ClassType();

		virtual void get_Owner(std::vector<uint8_t> &OutResult);

		virtual void get_ACIssuer(std::vector<uint8_t> &OutResult);

		virtual void set_ACIssuer(const std::vector<uint8_t> &Value);

		virtual void get_SerialNumber(std::vector<uint8_t> &OutResult);

		virtual void set_SerialNumber(const std::vector<uint8_t> &Value);

		virtual void get_AttrTypes(std::vector<uint8_t> &OutResult);

		virtual void set_AttrTypes(const std::vector<uint8_t> &Value);

		virtual void get_Value(std::vector<uint8_t> &OutResult);

		TElPKCS11X509AttributeCertificateObject(TElPKCS11X509AttributeCertificateObjectHandle handle, TElOwnHandle ownHandle);

		TElPKCS11X509AttributeCertificateObject();

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11X509AttributeCertificateObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#else
		TElPKCS11X509AttributeCertificateObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11X509AttributeCertificateObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#else
		TElPKCS11X509AttributeCertificateObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#endif
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

};
#endif /* SB_USE_CLASS_TELPKCS11X509ATTRIBUTECERTIFICATEOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11KEYOBJECT
class TElPKCS11KeyObject: public TElPKCS11Object
{
	private:
		SB_DISABLE_COPY(TElPKCS11KeyObject)
#ifdef SB_USE_CLASS_TELKEYMATERIAL
		TElKeyMaterial* _Inst_KeyMaterial;
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

		void initInstances();

	public:
		virtual void ReadProperties();

		static TClassHandle ClassType();

		virtual int32_t get_KeyType();

		SB_DECLARE_PROPERTY_GET(int32_t, get_KeyType, TElPKCS11KeyObject, KeyType);

#ifdef SB_NOT_CPU64_OR_WINDOWS
		virtual uint32_t get_PKCS11KeyType();
#else
		virtual int64_t get_PKCS11KeyType();
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		SB_DECLARE_PROPERTY_GET(uint32_t, get_PKCS11KeyType, TElPKCS11KeyObject, PKCS11KeyType);
#else
		SB_DECLARE_PROPERTY_GET(int64_t, get_PKCS11KeyType, TElPKCS11KeyObject, PKCS11KeyType);
#endif

		virtual void get_KeyID(std::vector<uint8_t> &OutResult);

		virtual void set_KeyID(const std::vector<uint8_t> &Value);

		virtual int64_t get_StartDate();

		virtual void set_StartDate(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_StartDate, set_StartDate, TElPKCS11KeyObject, StartDate);

		virtual int64_t get_EndDate();

		virtual void set_EndDate(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_EndDate, set_EndDate, TElPKCS11KeyObject, EndDate);

		virtual bool get_Derive();

		virtual void set_Derive(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Derive, set_Derive, TElPKCS11KeyObject, Derive);

		virtual bool get_Local();

		SB_DECLARE_PROPERTY_GET(bool, get_Local, TElPKCS11KeyObject, Local);

#ifdef SB_USE_CLASS_TELKEYMATERIAL
		virtual TElKeyMaterial* get_KeyMaterial();

		SB_DECLARE_PROPERTY_GET(TElKeyMaterial*, get_KeyMaterial, TElPKCS11KeyObject, KeyMaterial);
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

		TElPKCS11KeyObject(TElPKCS11KeyObjectHandle handle, TElOwnHandle ownHandle);

		TElPKCS11KeyObject();

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11KeyObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#else
		TElPKCS11KeyObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11KeyObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#else
		TElPKCS11KeyObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#endif
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

		virtual ~TElPKCS11KeyObject();

};
#endif /* SB_USE_CLASS_TELPKCS11KEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11PUBLICKEYOBJECT
class TElPKCS11PublicKeyObject: public TElPKCS11KeyObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11PublicKeyObject)
	public:
		virtual void ReadProperties();

		static TClassHandle ClassType();

		virtual void get_Subject(std::vector<uint8_t> &OutResult);

		virtual void set_Subject(const std::vector<uint8_t> &Value);

		virtual bool get_CanEncrypt();

		virtual void set_CanEncrypt(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CanEncrypt, set_CanEncrypt, TElPKCS11PublicKeyObject, CanEncrypt);

		virtual bool get_CanVerify();

		virtual void set_CanVerify(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CanVerify, set_CanVerify, TElPKCS11PublicKeyObject, CanVerify);

		virtual bool get_CanVerifyDetached();

		virtual void set_CanVerifyDetached(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CanVerifyDetached, set_CanVerifyDetached, TElPKCS11PublicKeyObject, CanVerifyDetached);

		virtual bool get_CanWrap();

		virtual void set_CanWrap(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CanWrap, set_CanWrap, TElPKCS11PublicKeyObject, CanWrap);

		virtual bool get_Trusted();

		virtual void set_Trusted(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Trusted, set_Trusted, TElPKCS11PublicKeyObject, Trusted);

		TElPKCS11PublicKeyObject(TElPKCS11PublicKeyObjectHandle handle, TElOwnHandle ownHandle);

		TElPKCS11PublicKeyObject();

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11PublicKeyObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#else
		TElPKCS11PublicKeyObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11PublicKeyObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#else
		TElPKCS11PublicKeyObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#endif
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

};
#endif /* SB_USE_CLASS_TELPKCS11PUBLICKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11PRIVATEKEYOBJECT
class TElPKCS11PrivateKeyObject: public TElPKCS11KeyObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11PrivateKeyObject)
	public:
		virtual void ReadProperties();

		static TClassHandle ClassType();

		virtual void get_Subject(std::vector<uint8_t> &OutResult);

		virtual void set_Subject(const std::vector<uint8_t> &Value);

		virtual bool get_Sensitive();

		virtual void set_Sensitive(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Sensitive, set_Sensitive, TElPKCS11PrivateKeyObject, Sensitive);

		virtual bool get_CanDecrypt();

		virtual void set_CanDecrypt(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CanDecrypt, set_CanDecrypt, TElPKCS11PrivateKeyObject, CanDecrypt);

		virtual bool get_CanSign();

		virtual void set_CanSign(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CanSign, set_CanSign, TElPKCS11PrivateKeyObject, CanSign);

		virtual bool get_CanSignDetached();

		virtual void set_CanSignDetached(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CanSignDetached, set_CanSignDetached, TElPKCS11PrivateKeyObject, CanSignDetached);

		virtual bool get_CanUnwrap();

		virtual void set_CanUnwrap(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CanUnwrap, set_CanUnwrap, TElPKCS11PrivateKeyObject, CanUnwrap);

		virtual bool get_Extractable();

		virtual void set_Extractable(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Extractable, set_Extractable, TElPKCS11PrivateKeyObject, Extractable);

		virtual bool get_AlwaysSensitive();

		SB_DECLARE_PROPERTY_GET(bool, get_AlwaysSensitive, TElPKCS11PrivateKeyObject, AlwaysSensitive);

		virtual bool get_NeverExtractable();

		SB_DECLARE_PROPERTY_GET(bool, get_NeverExtractable, TElPKCS11PrivateKeyObject, NeverExtractable);

		virtual bool get_WrapWithTrusted();

		virtual void set_WrapWithTrusted(bool Value);

		SB_DECLARE_PROPERTY(bool, get_WrapWithTrusted, set_WrapWithTrusted, TElPKCS11PrivateKeyObject, WrapWithTrusted);

		virtual bool get_AlwaysAuthenticate();

		virtual void set_AlwaysAuthenticate(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AlwaysAuthenticate, set_AlwaysAuthenticate, TElPKCS11PrivateKeyObject, AlwaysAuthenticate);

		TElPKCS11PrivateKeyObject(TElPKCS11PrivateKeyObjectHandle handle, TElOwnHandle ownHandle);

		TElPKCS11PrivateKeyObject();

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11PrivateKeyObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#else
		TElPKCS11PrivateKeyObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11PrivateKeyObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#else
		TElPKCS11PrivateKeyObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#endif
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

};
#endif /* SB_USE_CLASS_TELPKCS11PRIVATEKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11SECRETKEYOBJECT
class TElPKCS11SecretKeyObject: public TElPKCS11KeyObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11SecretKeyObject)
	public:
		virtual void ReadProperties();

		static TClassHandle ClassType();

		virtual bool get_Sensitive();

		virtual void set_Sensitive(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Sensitive, set_Sensitive, TElPKCS11SecretKeyObject, Sensitive);

		virtual bool get_CanEncrypt();

		virtual void set_CanEncrypt(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CanEncrypt, set_CanEncrypt, TElPKCS11SecretKeyObject, CanEncrypt);

		virtual bool get_CanDecrypt();

		virtual void set_CanDecrypt(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CanDecrypt, set_CanDecrypt, TElPKCS11SecretKeyObject, CanDecrypt);

		virtual bool get_CanSign();

		virtual void set_CanSign(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CanSign, set_CanSign, TElPKCS11SecretKeyObject, CanSign);

		virtual bool get_CanVerify();

		virtual void set_CanVerify(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CanVerify, set_CanVerify, TElPKCS11SecretKeyObject, CanVerify);

		virtual bool get_CanWrap();

		virtual void set_CanWrap(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CanWrap, set_CanWrap, TElPKCS11SecretKeyObject, CanWrap);

		virtual bool get_CanUnwrap();

		virtual void set_CanUnwrap(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CanUnwrap, set_CanUnwrap, TElPKCS11SecretKeyObject, CanUnwrap);

		virtual bool get_Extractable();

		virtual void set_Extractable(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Extractable, set_Extractable, TElPKCS11SecretKeyObject, Extractable);

		virtual bool get_AlwaysSensitive();

		SB_DECLARE_PROPERTY_GET(bool, get_AlwaysSensitive, TElPKCS11SecretKeyObject, AlwaysSensitive);

		virtual bool get_NeverExtractable();

		SB_DECLARE_PROPERTY_GET(bool, get_NeverExtractable, TElPKCS11SecretKeyObject, NeverExtractable);

		virtual void get_Checksum(std::vector<uint8_t> &OutResult);

		virtual bool get_WrapWithTrusted();

		virtual void set_WrapWithTrusted(bool Value);

		SB_DECLARE_PROPERTY(bool, get_WrapWithTrusted, set_WrapWithTrusted, TElPKCS11SecretKeyObject, WrapWithTrusted);

		virtual bool get_Trusted();

		virtual void set_Trusted(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Trusted, set_Trusted, TElPKCS11SecretKeyObject, Trusted);

		TElPKCS11SecretKeyObject(TElPKCS11SecretKeyObjectHandle handle, TElOwnHandle ownHandle);

		TElPKCS11SecretKeyObject();

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11SecretKeyObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#else
		TElPKCS11SecretKeyObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11SecretKeyObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#else
		TElPKCS11SecretKeyObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#endif
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

};
#endif /* SB_USE_CLASS_TELPKCS11SECRETKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11DOMAINPARAMETERSOBJECT
class TElPKCS11DomainParametersObject: public TElPKCS11Object
{
	private:
		SB_DISABLE_COPY(TElPKCS11DomainParametersObject)
	public:
		virtual void ReadProperties();

		static TClassHandle ClassType();

		virtual int32_t get_KeyType();

		SB_DECLARE_PROPERTY_GET(int32_t, get_KeyType, TElPKCS11DomainParametersObject, KeyType);

#ifdef SB_NOT_CPU64_OR_WINDOWS
		virtual uint32_t get_PKCS11KeyType();
#else
		virtual int64_t get_PKCS11KeyType();
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		SB_DECLARE_PROPERTY_GET(uint32_t, get_PKCS11KeyType, TElPKCS11DomainParametersObject, PKCS11KeyType);
#else
		SB_DECLARE_PROPERTY_GET(int64_t, get_PKCS11KeyType, TElPKCS11DomainParametersObject, PKCS11KeyType);
#endif

		TElPKCS11DomainParametersObject(TElPKCS11DomainParametersObjectHandle handle, TElOwnHandle ownHandle);

		TElPKCS11DomainParametersObject();

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO
#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11DomainParametersObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#else
		TElPKCS11DomainParametersObject(TElPKCS11Module &Module, TElPKCS11SessionInfo &Session, TElPKCS11SlotInfo &Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider &CryptoProvider);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		TElPKCS11DomainParametersObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, uint32_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#else
		TElPKCS11DomainParametersObject(TElPKCS11Module *Module, TElPKCS11SessionInfo *Session, TElPKCS11SlotInfo *Slot, int64_t Handle, bool CompatibleMode, TElCustomCryptoProvider *CryptoProvider);
#endif
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELPKCS11MODULE_AND_TELPKCS11SESSIONINFO_AND_TELPKCS11SLOTINFO */

};
#endif /* SB_USE_CLASS_TELPKCS11DOMAINPARAMETERSOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11UTILS
class TElPKCS11Utils: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11Utils)
	public:
#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
		static void GetObjectAttribute(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, std::vector<uint8_t> &OutResult);
#else
		static void GetObjectAttribute(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, std::vector<uint8_t> &OutResult);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		static void GetObjectAttribute(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, std::vector<uint8_t> &OutResult);
#else
		static void GetObjectAttribute(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, std::vector<uint8_t> &OutResult);
#endif
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
		void GetObjectAttribute_Inst(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, std::vector<uint8_t> &OutResult);
#else
		void GetObjectAttribute_Inst(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, std::vector<uint8_t> &OutResult);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		void GetObjectAttribute_Inst(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, std::vector<uint8_t> &OutResult);
#else
		void GetObjectAttribute_Inst(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, std::vector<uint8_t> &OutResult);
#endif
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
		static void GetBufferTypeAttribute(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Def, std::vector<uint8_t> &OutResult);
#else
		static void GetBufferTypeAttribute(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Def, std::vector<uint8_t> &OutResult);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		static void GetBufferTypeAttribute(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Def, std::vector<uint8_t> &OutResult);
#else
		static void GetBufferTypeAttribute(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Def, std::vector<uint8_t> &OutResult);
#endif
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
		void GetBufferTypeAttribute_Inst(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Def, std::vector<uint8_t> &OutResult);
#else
		void GetBufferTypeAttribute_Inst(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Def, std::vector<uint8_t> &OutResult);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		void GetBufferTypeAttribute_Inst(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Def, std::vector<uint8_t> &OutResult);
#else
		void GetBufferTypeAttribute_Inst(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Def, std::vector<uint8_t> &OutResult);
#endif
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
		static bool GetBooleanAttribute(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, bool Def);
#else
		static bool GetBooleanAttribute(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, bool Def);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		static bool GetBooleanAttribute(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, bool Def);
#else
		static bool GetBooleanAttribute(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, bool Def);
#endif
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
		bool GetBooleanAttribute_Inst(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, bool Def);
#else
		bool GetBooleanAttribute_Inst(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, bool Def);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		bool GetBooleanAttribute_Inst(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, bool Def);
#else
		bool GetBooleanAttribute_Inst(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, bool Def);
#endif
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
		static uint32_t GetULongAttribute(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint32_t Def);
#else
		static int64_t GetULongAttribute(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Def);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		static uint32_t GetULongAttribute(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint32_t Def);
#else
		static int64_t GetULongAttribute(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Def);
#endif
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
		uint32_t GetULongAttribute_Inst(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint32_t Def);
#else
		int64_t GetULongAttribute_Inst(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Def);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		uint32_t GetULongAttribute_Inst(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint32_t Def);
#else
		int64_t GetULongAttribute_Inst(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Def);
#endif
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
		static int64_t GetDateAttribute(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int64_t Def);
#else
		static int64_t GetDateAttribute(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Def);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		static int64_t GetDateAttribute(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int64_t Def);
#else
		static int64_t GetDateAttribute(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Def);
#endif
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
		int64_t GetDateAttribute_Inst(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int64_t Def);
#else
		int64_t GetDateAttribute_Inst(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Def);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		int64_t GetDateAttribute_Inst(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int64_t Def);
#else
		int64_t GetDateAttribute_Inst(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Def);
#endif
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
		static void SetObjectAttribute(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Value);
#else
		static void SetObjectAttribute(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		static void SetObjectAttribute(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Value);
#else
		static void SetObjectAttribute(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Value);
#endif
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
		void SetObjectAttribute_Inst(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Value);
#else
		void SetObjectAttribute_Inst(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		void SetObjectAttribute_Inst(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Value);
#else
		void SetObjectAttribute_Inst(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Value);
#endif
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
		static void SetBufferTypeAttribute(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Value);
#else
		static void SetBufferTypeAttribute(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		static void SetBufferTypeAttribute(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Value);
#else
		static void SetBufferTypeAttribute(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Value);
#endif
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
		void SetBufferTypeAttribute_Inst(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Value);
#else
		void SetBufferTypeAttribute_Inst(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		void SetBufferTypeAttribute_Inst(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, const std::vector<uint8_t> &Value);
#else
		void SetBufferTypeAttribute_Inst(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, const std::vector<uint8_t> &Value);
#endif
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
		static void SetBooleanAttribute(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, bool Value);
#else
		static void SetBooleanAttribute(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, bool Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		static void SetBooleanAttribute(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, bool Value);
#else
		static void SetBooleanAttribute(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, bool Value);
#endif
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
		void SetBooleanAttribute_Inst(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, bool Value);
#else
		void SetBooleanAttribute_Inst(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, bool Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		void SetBooleanAttribute_Inst(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, bool Value);
#else
		void SetBooleanAttribute_Inst(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, bool Value);
#endif
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
		static void SetULongAttribute(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint32_t Value);
#else
		static void SetULongAttribute(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		static void SetULongAttribute(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint32_t Value);
#else
		static void SetULongAttribute(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Value);
#endif
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
		void SetULongAttribute_Inst(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint32_t Value);
#else
		void SetULongAttribute_Inst(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		void SetULongAttribute_Inst(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, uint32_t Value);
#else
		void SetULongAttribute_Inst(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Value);
#endif
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
		static void SetDateAttribute(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int64_t Value);
#else
		static void SetDateAttribute(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		static void SetDateAttribute(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int64_t Value);
#else
		static void SetDateAttribute(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Value);
#endif
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifdef SB_USE_CLASS_TELPKCS11MODULE
#ifdef SB_NOT_CPU64_OR_WINDOWS
		void SetDateAttribute_Inst(TElPKCS11Module &Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int64_t Value);
#else
		void SetDateAttribute_Inst(TElPKCS11Module &Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Value);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		void SetDateAttribute_Inst(TElPKCS11Module *Module, uint32_t hSession, uint32_t hObject, uint32_t Attribute, int64_t Value);
#else
		void SetDateAttribute_Inst(TElPKCS11Module *Module, int64_t hSession, int64_t hObject, int64_t Attribute, int64_t Value);
#endif
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

		static int32_t ConvertPKCS11KeyTypeToSBBKeyType(int32_t KeyType);

		int32_t ConvertPKCS11KeyTypeToSBBKeyType_Inst(int32_t KeyType);

		TElPKCS11Utils(TElPKCS11UtilsHandle handle, TElOwnHandle ownHandle);

		TElPKCS11Utils();

};
#endif /* SB_USE_CLASS_TELPKCS11UTILS */

#ifdef SB_USE_CLASS_TELPKCS11NSSPARAMS
class TElPKCS11NSSParams: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11NSSParams)
	public:
		bool Load(const std::vector<uint8_t> &Data);

		void Save(std::vector<uint8_t> &OutResult);

		virtual void get_ConfigDir(std::string &OutResult);

		virtual void set_ConfigDir(const std::string &Value);

		virtual void get_CertPrefix(std::string &OutResult);

		virtual void set_CertPrefix(const std::string &Value);

		virtual void get_KeyPrefix(std::string &OutResult);

		virtual void set_KeyPrefix(const std::string &Value);

		virtual void get_SecMod(std::string &OutResult);

		virtual void set_SecMod(const std::string &Value);

		virtual void get_Flags(std::string &OutResult);

		virtual void set_Flags(const std::string &Value);

		virtual bool get_UseNSSMode();

		virtual void set_UseNSSMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseNSSMode, set_UseNSSMode, TElPKCS11NSSParams, UseNSSMode);

		virtual void get_RawParamsStr(std::string &OutResult);

		virtual void set_RawParamsStr(const std::string &Value);

		TElPKCS11NSSParams(TElPKCS11NSSParamsHandle handle, TElOwnHandle ownHandle);

		TElPKCS11NSSParams();

};
#endif /* SB_USE_CLASS_TELPKCS11NSSPARAMS */

#ifdef SB_USE_CLASS_TELPKCS11MODULELIST
class TElPKCS11ModuleList: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11ModuleList)
#ifdef SB_USE_CLASS_TELPKCS11MODULE
		TElPKCS11Module* _Inst_Modules;
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

		void initInstances();

	public:
#ifndef SB_IOS
#ifdef SB_USE_CLASS_TELPKCS11MODULE
		TElPKCS11ModuleHandle LoadModule(const std::string &ModuleName, bool UseSystemProcAddresses, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo);
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#else
#ifdef SB_USE_CLASSES_TELPKCS11FUNCTIONSMANAGER_AND_TELPKCS11MODULE
		TElPKCS11ModuleHandle LoadModule(TElPKCS11FunctionsManager &FuncMng, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo);

		TElPKCS11ModuleHandle LoadModule(TElPKCS11FunctionsManager *FuncMng, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo);
#endif /* SB_USE_CLASSES_TELPKCS11FUNCTIONSMANAGER_AND_TELPKCS11MODULE */
#endif

#ifndef SB_IOS
#ifdef SB_USE_CLASS_TELPKCS11MODULE
		TElPKCS11ModuleHandle LoadModule(const std::string &ModuleName, bool UseSystemProcAddresses, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo, bool PreserveSettingsIfExists);
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#endif

#ifndef SB_IOS
#ifdef SB_USE_CLASS_TELPKCS11MODULE
		TElPKCS11ModuleHandle LoadModule(const std::string &ModuleName, bool UseSystemProcAddresses, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo, bool PreserveSettingsIfExists, bool OnDemandMode);
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#else
#ifdef SB_USE_CLASSES_TELPKCS11FUNCTIONSMANAGER_AND_TELPKCS11MODULE
		TElPKCS11ModuleHandle LoadModule(TElPKCS11FunctionsManager &FuncMng, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo, bool PreserveSettingsIfExists);

		TElPKCS11ModuleHandle LoadModule(TElPKCS11FunctionsManager *FuncMng, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo, bool PreserveSettingsIfExists);
#endif /* SB_USE_CLASSES_TELPKCS11FUNCTIONSMANAGER_AND_TELPKCS11MODULE */
#endif

#ifndef SB_IOS
#ifdef SB_USE_CLASSES_TELPKCS11MODULE_AND_TELPKCS11NSSPARAMS
		TElPKCS11ModuleHandle LoadModule(const std::string &ModuleName, bool UseSystemProcAddresses, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo, bool PreserveSettingsIfExists, bool OnDemandMode, TElPKCS11NSSParams &NSSParams, bool NoImplicitSlotInfoUpdates);

		TElPKCS11ModuleHandle LoadModule(const std::string &ModuleName, bool UseSystemProcAddresses, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo, bool PreserveSettingsIfExists, bool OnDemandMode, TElPKCS11NSSParams *NSSParams, bool NoImplicitSlotInfoUpdates);
#endif /* SB_USE_CLASSES_TELPKCS11MODULE_AND_TELPKCS11NSSPARAMS */
#else

#ifdef SB_USE_CLASSES_TELPKCS11FUNCTIONSMANAGER_AND_TELPKCS11MODULE
		TElPKCS11ModuleHandle LoadModule(TElPKCS11FunctionsManager &FuncMng, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo, bool PreserveSettingsIfExists, bool OnDemandMode);

		TElPKCS11ModuleHandle LoadModule(TElPKCS11FunctionsManager *FuncMng, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo, bool PreserveSettingsIfExists, bool OnDemandMode);
#endif /* SB_USE_CLASSES_TELPKCS11FUNCTIONSMANAGER_AND_TELPKCS11MODULE */

#ifdef SB_USE_CLASSES_TELPKCS11FUNCTIONSMANAGER_AND_TELPKCS11MODULE_AND_TELPKCS11NSSPARAMS
		TElPKCS11ModuleHandle LoadModule(TElPKCS11FunctionsManager &FuncMng, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo, bool PreserveSettingsIfExists, bool OnDemandMode, TElPKCS11NSSParams &NSSParams, bool NoImplicitSlotInfoUpdates);

		TElPKCS11ModuleHandle LoadModule(TElPKCS11FunctionsManager *FuncMng, bool TrySingleThreadedMode, bool AutoRefreshSlotInfo, bool PreserveSettingsIfExists, bool OnDemandMode, TElPKCS11NSSParams *NSSParams, bool NoImplicitSlotInfoUpdates);
#endif /* SB_USE_CLASSES_TELPKCS11FUNCTIONSMANAGER_AND_TELPKCS11MODULE_AND_TELPKCS11NSSPARAMS */
#endif

#ifdef SB_USE_CLASS_TELPKCS11MODULE
		void UnloadModule(TElPKCS11Module &aModule);

		void UnloadModule(TElPKCS11Module *aModule);
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

		virtual int32_t get_ModuleCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ModuleCount, TElPKCS11ModuleList, ModuleCount);

#ifdef SB_USE_CLASS_TELPKCS11MODULE
		virtual TElPKCS11Module* get_Modules(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

		TElPKCS11ModuleList(TElPKCS11ModuleListHandle handle, TElOwnHandle ownHandle);

		TElPKCS11ModuleList();

		virtual ~TElPKCS11ModuleList();

};
#endif /* SB_USE_CLASS_TELPKCS11MODULELIST */

#ifdef SB_USE_CLASS_TELPKCS11ALGORITHMINFO
class TElPKCS11AlgorithmInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11AlgorithmInfo)
	public:
		virtual int32_t get_Algorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Algorithm, TElPKCS11AlgorithmInfo, Algorithm);

		virtual int32_t get_Mode();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Mode, TElPKCS11AlgorithmInfo, Mode);

#ifdef SB_NOT_CPU64_OR_WINDOWS
		virtual uint32_t get_Mechanism();
#else
		virtual int64_t get_Mechanism();
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		SB_DECLARE_PROPERTY_GET(uint32_t, get_Mechanism, TElPKCS11AlgorithmInfo, Mechanism);
#else
		SB_DECLARE_PROPERTY_GET(int64_t, get_Mechanism, TElPKCS11AlgorithmInfo, Mechanism);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		virtual uint32_t get_KeyMechanism();
#else
		virtual int64_t get_KeyMechanism();
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		SB_DECLARE_PROPERTY_GET(uint32_t, get_KeyMechanism, TElPKCS11AlgorithmInfo, KeyMechanism);
#else
		SB_DECLARE_PROPERTY_GET(int64_t, get_KeyMechanism, TElPKCS11AlgorithmInfo, KeyMechanism);
#endif

		virtual bool get_PaddingUsed();

		SB_DECLARE_PROPERTY_GET(bool, get_PaddingUsed, TElPKCS11AlgorithmInfo, PaddingUsed);

		virtual bool get_CanGenerate();

		SB_DECLARE_PROPERTY_GET(bool, get_CanGenerate, TElPKCS11AlgorithmInfo, CanGenerate);

		virtual bool get_CanEncrypt();

		SB_DECLARE_PROPERTY_GET(bool, get_CanEncrypt, TElPKCS11AlgorithmInfo, CanEncrypt);

		virtual bool get_CanSign();

		SB_DECLARE_PROPERTY_GET(bool, get_CanSign, TElPKCS11AlgorithmInfo, CanSign);

		virtual bool get_CanSignRecover();

		SB_DECLARE_PROPERTY_GET(bool, get_CanSignRecover, TElPKCS11AlgorithmInfo, CanSignRecover);

		virtual bool get_CanDigest();

		SB_DECLARE_PROPERTY_GET(bool, get_CanDigest, TElPKCS11AlgorithmInfo, CanDigest);

		virtual bool get_CanWrap();

		SB_DECLARE_PROPERTY_GET(bool, get_CanWrap, TElPKCS11AlgorithmInfo, CanWrap);

		virtual bool get_CanDerive();

		SB_DECLARE_PROPERTY_GET(bool, get_CanDerive, TElPKCS11AlgorithmInfo, CanDerive);

		virtual int32_t get_SignHashAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignHashAlgorithm, TElPKCS11AlgorithmInfo, SignHashAlgorithm);

		TElPKCS11AlgorithmInfo(TElPKCS11AlgorithmInfoHandle handle, TElOwnHandle ownHandle);

		TElPKCS11AlgorithmInfo();

};
#endif /* SB_USE_CLASS_TELPKCS11ALGORITHMINFO */

#ifdef SB_USE_CLASS_TELPKCS11ALGORITHMCONVERTER
class TElPKCS11AlgorithmConverter: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11AlgorithmConverter)
#ifdef SB_USE_CLASS_TELPKCS11ALGORITHMINFO
		TElPKCS11AlgorithmInfo* _Inst_AlgorithmInfos;
#endif /* SB_USE_CLASS_TELPKCS11ALGORITHMINFO */

		void initInstances();

	public:
		int32_t Find(int32_t Algorithm, int32_t Mode, int32_t Operation, bool PaddingUsed);

#ifdef SB_USE_CLASS_TLIST
		void Find(int32_t Algorithm, int32_t Mode, TList &Infos);

		void Find(int32_t Algorithm, int32_t Mode, TList *Infos);
#endif /* SB_USE_CLASS_TLIST */

		int32_t FindSignatureAlgorithmInfo(int32_t Algorithm, int32_t HashAlgorithm);

#ifdef SB_NOT_CPU64_OR_WINDOWS
		int32_t GetAlgorithmByPKCS11Mechanism(uint32_t Mech, int32_t &Mode, bool &Gen);
#else
		int32_t GetAlgorithmByPKCS11Mechanism(int64_t Mech, int32_t &Mode, bool &Gen);
#endif

		bool GetPKCS11MechanismByAlgorithm(int32_t Algorithm, int32_t Mode, SB_CK_MECHANISM &Mech);

#ifdef SB_USE_CLASS_TELPKCS11ALGORITHMINFO
		virtual TElPKCS11AlgorithmInfo* get_AlgorithmInfos(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11ALGORITHMINFO */

		virtual int32_t get_AlgorithmInfoCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AlgorithmInfoCount, TElPKCS11AlgorithmConverter, AlgorithmInfoCount);

		TElPKCS11AlgorithmConverter(TElPKCS11AlgorithmConverterHandle handle, TElOwnHandle ownHandle);

		TElPKCS11AlgorithmConverter();

		virtual ~TElPKCS11AlgorithmConverter();

};
#endif /* SB_USE_CLASS_TELPKCS11ALGORITHMCONVERTER */

#ifdef SB_USE_CLASS_TELSLOTEVENTMONITORINGTHREAD
class TElSlotEventMonitoringThread: public TThread
{
	private:
		SB_DISABLE_COPY(TElSlotEventMonitoringThread)
	public:
		virtual void get_OnSlotEvent(TElSlotEventMonitoringThreadEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSlotEvent(TElSlotEventMonitoringThreadEvent pMethodValue, void * pDataValue);

		TElSlotEventMonitoringThread(TElSlotEventMonitoringThreadHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPKCS11MODULE
		TElSlotEventMonitoringThread(TElPKCS11Module &PKCS11Module, bool SynchronizeGUI, bool UseGetSlotInfo, int32_t Delay);

		TElSlotEventMonitoringThread(TElPKCS11Module *PKCS11Module, bool SynchronizeGUI, bool UseGetSlotInfo, int32_t Delay);
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

};
#endif /* SB_USE_CLASS_TELSLOTEVENTMONITORINGTHREAD */

#ifdef SB_USE_GLOBAL_PROCS_PKCS11BASE

#ifdef SB_USE_CLASS_TELPKCS11ALGORITHMCONVERTER
TElPKCS11AlgorithmConverterHandle PKCS11AlgorithmConverter();
#endif /* SB_USE_CLASS_TELPKCS11ALGORITHMCONVERTER */

#ifdef SB_NOT_CPU64_OR_WINDOWS
uint32_t CreateMutexCallback(void * &MutexPtr);
#else
int64_t CreateMutexCallback(void * &MutexPtr);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
uint32_t DestroyMutexCallback(void * MutexPtr);
#else
int64_t DestroyMutexCallback(void * MutexPtr);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
uint32_t LockMutexCallback(void * MutexPtr);
#else
int64_t LockMutexCallback(void * MutexPtr);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
uint32_t UnlockMutexCallback(void * MutexPtr);
#else
int64_t UnlockMutexCallback(void * MutexPtr);
#endif

void GetPKCS11String(const std::vector<uint8_t> &Buffer, int32_t MaxLength, std::string &OutResult);

#ifdef SB_NOT_CPU64_OR_WINDOWS
void PKCS11CheckError(int32_t FunctionCode, uint32_t ResultCode);
#else
void PKCS11CheckError(int32_t FunctionCode, int64_t ResultCode);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
void GetPKCS11ErrorNameByCode(uint32_t Code, std::string &OutResult);
#else
void GetPKCS11ErrorNameByCode(int64_t Code, std::string &OutResult);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
void PKCS11AddAttribute(std::vector<TPKCS11Attribute> &Attributes, uint32_t _type, void * pValue, uint32_t ulValueLen);
#else
void PKCS11AddAttribute(std::vector<TPKCS11Attribute> &Attributes, int64_t _type, void * pValue, int64_t ulValueLen);
#endif

bool EncodeErrorInfo(const std::string &MethodName, const std::string &ErrorStr, const std::string &ErrorClassName, void * Buffer, int32_t &Size);

#ifdef SB_USE_CLASS_TELPKCS11MODULELIST
TElPKCS11ModuleListHandle GetPKCS11ModuleList();
#endif /* SB_USE_CLASS_TELPKCS11MODULELIST */

#endif /* SB_USE_GLOBAL_PROCS_PKCS11BASE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_PKCS11BASE
SB_IMPORT uint32_t SB_APIENTRY SBPKCS11Base_PKCS11AlgorithmConverter(TElPKCS11AlgorithmConverterHandle * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY SBPKCS11Base_CreateMutexCallback(void * * MutexPtr, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPKCS11Base_DestroyMutexCallback(void * MutexPtr, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPKCS11Base_LockMutexCallback(void * MutexPtr, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPKCS11Base_UnlockMutexCallback(void * MutexPtr, uint32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY SBPKCS11Base_CreateMutexCallback(void * * MutexPtr, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPKCS11Base_DestroyMutexCallback(void * MutexPtr, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPKCS11Base_LockMutexCallback(void * MutexPtr, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPKCS11Base_UnlockMutexCallback(void * MutexPtr, int64_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY SBPKCS11Base_GetPKCS11String(const uint8_t pBuffer[], int32_t szBuffer, int32_t MaxLength, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY SBPKCS11Base_PKCS11CheckError(int32_t FunctionCode, uint32_t ResultCode);
SB_IMPORT uint32_t SB_APIENTRY SBPKCS11Base_GetPKCS11ErrorNameByCode(uint32_t Code, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPKCS11Base_PKCS11AddAttribute(TPKCS11Attribute pAttributes[], int32_t * szAttributes, uint32_t _type, void * pValue, uint32_t ulValueLen);
#else
SB_IMPORT uint32_t SB_APIENTRY SBPKCS11Base_PKCS11CheckError(int32_t FunctionCode, int64_t ResultCode);
SB_IMPORT uint32_t SB_APIENTRY SBPKCS11Base_GetPKCS11ErrorNameByCode(int64_t Code, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPKCS11Base_PKCS11AddAttribute(TPKCS11Attribute pAttributes[], int32_t * szAttributes, int64_t _type, void * pValue, int64_t ulValueLen);
#endif
SB_IMPORT uint32_t SB_APIENTRY SBPKCS11Base_EncodeErrorInfo(const char * pcMethodName, int32_t szMethodName, const char * pcErrorStr, int32_t szErrorStr, const char * pcErrorClassName, int32_t szErrorClassName, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPKCS11Base_GetPKCS11ModuleList(TElPKCS11ModuleListHandle * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_PKCS11BASE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPKCS11BASE */
