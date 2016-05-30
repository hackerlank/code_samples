#ifndef __INC_SBPKCS11MANAGER
#define __INC_SBPKCS11MANAGER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstrutils.h"
#include "sbrsa.h"
#include "sbdsa.h"
#include "sbasn1.h"
#include "sbpkcs11common.h"
#include "sbpkcs11base.h"
#include "sbx509.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbsharedresource.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElPKCS11ManagerHandle;

typedef TElPKCS11ManagerHandle ElPKCS11ManagerHandle;

typedef TElClassHandle TElPKCS11ManagerObjectHandle;

typedef TElPKCS11ManagerObjectHandle ElPKCS11ManagerObjectHandle;

typedef TElClassHandle TElPKCS11ManagerDataObjectHandle;

typedef TElPKCS11ManagerDataObjectHandle ElPKCS11ManagerDataObjectHandle;

typedef TElClassHandle TElPKCS11ManagerCertificateObjectHandle;

typedef TElPKCS11ManagerCertificateObjectHandle ElPKCS11ManagerCertificateObjectHandle;

typedef TElClassHandle TElPKCS11ManagerKeyObjectHandle;

typedef TElPKCS11ManagerKeyObjectHandle ElPKCS11ManagerKeyObjectHandle;

typedef TElClassHandle TElPKCS11ManagerPublicKeyObjectHandle;

typedef TElPKCS11ManagerPublicKeyObjectHandle ElPKCS11ManagerPublicKeyObjectHandle;

typedef TElClassHandle TElPKCS11ManagerPrivateKeyObjectHandle;

typedef TElPKCS11ManagerPrivateKeyObjectHandle ElPKCS11ManagerPrivateKeyObjectHandle;

typedef TElClassHandle TElPKCS11ManagerSecretKeyObjectHandle;

typedef TElPKCS11ManagerSecretKeyObjectHandle ElPKCS11ManagerSecretKeyObjectHandle;

typedef TElClassHandle TElPKCS11ConsumerManagerHandle;

typedef TElPKCS11ConsumerManagerHandle ElPKCS11ConsumerManagerHandle;

#ifdef SB_USE_CLASS_TELPKCS11MANAGER
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_Close(TElPKCS11ManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_Open(TElPKCS11ManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_OpenSession(TElPKCS11ManagerHandle _Handle, int32_t SlotIndex, int8_t ReadOnly, TElPKCS11SessionInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_CloseSession(TElPKCS11ManagerHandle _Handle);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_IndexOfObject(TElPKCS11ManagerHandle _Handle, uint32_t Handle, int32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_IndexOfObject(TElPKCS11ManagerHandle _Handle, int64_t Handle, int32_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_IndexOfObject_1(TElPKCS11ManagerHandle _Handle, TElPKCS11ManagerObjectHandle AnObject, int32_t * OutResult);
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_RemoveObject(TElPKCS11ManagerHandle _Handle, uint32_t Handle);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_RemoveObject(TElPKCS11ManagerHandle _Handle, int64_t Handle);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_RemoveObject_1(TElPKCS11ManagerHandle _Handle, TElPKCS11ManagerObjectHandle AnObject);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_RemoveObject_2(TElPKCS11ManagerHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_RefreshObjects(TElPKCS11ManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_AddObject(TElPKCS11ManagerHandle _Handle, TElPKCS11ManagerObjectHandle AnObject, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_get_Objects(TElPKCS11ManagerHandle _Handle, int32_t Index, TElPKCS11ManagerObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_get_Count(TElPKCS11ManagerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_get_Module(TElPKCS11ManagerHandle _Handle, TElPKCS11ModuleHandle * OutResult);
#ifndef SB_IOS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_get_DLLName(TElPKCS11ManagerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_set_DLLName(TElPKCS11ManagerHandle _Handle, const char * pcValue, int32_t szValue);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_get_FunctionsManager(TElPKCS11ManagerHandle _Handle, TElPKCS11FunctionsManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_set_FunctionsManager(TElPKCS11ManagerHandle _Handle, TElPKCS11FunctionsManagerHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_get_PKCS11Options(TElPKCS11ManagerHandle _Handle, TSBPKCS11StorageOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_set_PKCS11Options(TElPKCS11ManagerHandle _Handle, TSBPKCS11StorageOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_get_OnNotification(TElPKCS11ManagerHandle _Handle, TElPKCSNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_set_OnNotification(TElPKCS11ManagerHandle _Handle, TElPKCSNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11Manager_Create(TComponentHandle Owner, TElPKCS11ManagerHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11MANAGER */

#ifdef SB_USE_CLASS_TELPKCS11MANAGEROBJECT
#ifdef SB_NOT_CPU64_OR_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerObject_get_Handle(TElPKCS11ManagerObjectHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerObject_get_HWSize(TElPKCS11ManagerObjectHandle _Handle, uint32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerObject_get_Handle(TElPKCS11ManagerObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerObject_get_HWSize(TElPKCS11ManagerObjectHandle _Handle, int64_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerObject_get_ID(TElPKCS11ManagerObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerObject_get_Label_(TElPKCS11ManagerObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerObject_set_Label_(TElPKCS11ManagerObjectHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerObject_get_Modifiable(TElPKCS11ManagerObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerObject_set_Modifiable(TElPKCS11ManagerObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerObject_get_Private_(TElPKCS11ManagerObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerObject_set_Private_(TElPKCS11ManagerObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerObject_get_Token(TElPKCS11ManagerObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerObject_set_Token(TElPKCS11ManagerObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerObject_Create(TElPKCS11ManagerHandle Owner, TElPKCS11ManagerObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11MANAGEROBJECT */

#ifdef SB_USE_CLASS_TELPKCS11MANAGERDATAOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerDataObject_get_Application(TElPKCS11ManagerDataObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerDataObject_set_Application(TElPKCS11ManagerDataObjectHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerDataObject_get_OID(TElPKCS11ManagerDataObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerDataObject_set_OID(TElPKCS11ManagerDataObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerDataObject_get_Value(TElPKCS11ManagerDataObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerDataObject_set_Value(TElPKCS11ManagerDataObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerDataObject_Create(TElPKCS11ManagerHandle Owner, TElPKCS11ManagerObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11MANAGERDATAOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11MANAGERCERTIFICATEOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_get_ACAttrTypes(TElPKCS11ManagerCertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_set_ACAttrTypes(TElPKCS11ManagerCertificateObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_get_ACIssuer(TElPKCS11ManagerCertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_set_ACIssuer(TElPKCS11ManagerCertificateObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_get_ACOwner(TElPKCS11ManagerCertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_set_ACOwner(TElPKCS11ManagerCertificateObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_get_Category(TElPKCS11ManagerCertificateObjectHandle _Handle, TElPKCS11CertificateCategoryRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_set_Category(TElPKCS11ManagerCertificateObjectHandle _Handle, TElPKCS11CertificateCategoryRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_get_CertificateType(TElPKCS11ManagerCertificateObjectHandle _Handle, TElPKCS11CertificateTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_set_CertificateType(TElPKCS11ManagerCertificateObjectHandle _Handle, TElPKCS11CertificateTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_get_Issuer(TElPKCS11ManagerCertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_set_Issuer(TElPKCS11ManagerCertificateObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_get_SerialNumber(TElPKCS11ManagerCertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_set_SerialNumber(TElPKCS11ManagerCertificateObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_get_Subject(TElPKCS11ManagerCertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_set_Subject(TElPKCS11ManagerCertificateObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_get_Trusted(TElPKCS11ManagerCertificateObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_set_Trusted(TElPKCS11ManagerCertificateObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_get_ValidFrom(TElPKCS11ManagerCertificateObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_set_ValidFrom(TElPKCS11ManagerCertificateObjectHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_get_ValidTo(TElPKCS11ManagerCertificateObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_set_ValidTo(TElPKCS11ManagerCertificateObjectHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_get_URL(TElPKCS11ManagerCertificateObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_set_URL(TElPKCS11ManagerCertificateObjectHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_get_Value(TElPKCS11ManagerCertificateObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_set_Value(TElPKCS11ManagerCertificateObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerCertificateObject_Create(TElPKCS11ManagerHandle Owner, TElPKCS11ManagerObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11MANAGERCERTIFICATEOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11MANAGERKEYOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerKeyObject_get_ValidFrom(TElPKCS11ManagerKeyObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerKeyObject_set_ValidFrom(TElPKCS11ManagerKeyObjectHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerKeyObject_get_ValidTo(TElPKCS11ManagerKeyObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerKeyObject_set_ValidTo(TElPKCS11ManagerKeyObjectHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerKeyObject_Create(TElPKCS11ManagerHandle Owner, TElPKCS11ManagerObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11MANAGERKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11MANAGERPUBLICKEYOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPublicKeyObject_get_Encrypt(TElPKCS11ManagerPublicKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPublicKeyObject_set_Encrypt(TElPKCS11ManagerPublicKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPublicKeyObject_get_Subject(TElPKCS11ManagerPublicKeyObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPublicKeyObject_set_Subject(TElPKCS11ManagerPublicKeyObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPublicKeyObject_get_Trusted(TElPKCS11ManagerPublicKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPublicKeyObject_set_Trusted(TElPKCS11ManagerPublicKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPublicKeyObject_get_Verify(TElPKCS11ManagerPublicKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPublicKeyObject_set_Verify(TElPKCS11ManagerPublicKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPublicKeyObject_get_VerifyRecover(TElPKCS11ManagerPublicKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPublicKeyObject_set_VerifyRecover(TElPKCS11ManagerPublicKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPublicKeyObject_get_Wrap(TElPKCS11ManagerPublicKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPublicKeyObject_set_Wrap(TElPKCS11ManagerPublicKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPublicKeyObject_Create(TElPKCS11ManagerHandle Owner, TElPKCS11ManagerObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11MANAGERPUBLICKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11MANAGERPRIVATEKEYOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPrivateKeyObject_get_AlwaysAuthenticate(TElPKCS11ManagerPrivateKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPrivateKeyObject_set_AlwaysAuthenticate(TElPKCS11ManagerPrivateKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPrivateKeyObject_get_Decrypt(TElPKCS11ManagerPrivateKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPrivateKeyObject_set_Decrypt(TElPKCS11ManagerPrivateKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPrivateKeyObject_get_Extractable(TElPKCS11ManagerPrivateKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPrivateKeyObject_set_Extractable(TElPKCS11ManagerPrivateKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPrivateKeyObject_get_Sensitive(TElPKCS11ManagerPrivateKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPrivateKeyObject_set_Sensitive(TElPKCS11ManagerPrivateKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPrivateKeyObject_get_Sign(TElPKCS11ManagerPrivateKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPrivateKeyObject_set_Sign(TElPKCS11ManagerPrivateKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPrivateKeyObject_get_SignRecover(TElPKCS11ManagerPrivateKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPrivateKeyObject_set_SignRecover(TElPKCS11ManagerPrivateKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPrivateKeyObject_get_Subject(TElPKCS11ManagerPrivateKeyObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPrivateKeyObject_set_Subject(TElPKCS11ManagerPrivateKeyObjectHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPrivateKeyObject_get_Unwrap(TElPKCS11ManagerPrivateKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPrivateKeyObject_set_Unwrap(TElPKCS11ManagerPrivateKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerPrivateKeyObject_Create(TElPKCS11ManagerHandle Owner, TElPKCS11ManagerObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11MANAGERPRIVATEKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11MANAGERSECRETKEYOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerSecretKeyObject_get_Decrypt(TElPKCS11ManagerSecretKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerSecretKeyObject_set_Decrypt(TElPKCS11ManagerSecretKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerSecretKeyObject_get_Encrypt(TElPKCS11ManagerSecretKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerSecretKeyObject_set_Encrypt(TElPKCS11ManagerSecretKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerSecretKeyObject_get_Extractable(TElPKCS11ManagerSecretKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerSecretKeyObject_set_Extractable(TElPKCS11ManagerSecretKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerSecretKeyObject_get_Sensitive(TElPKCS11ManagerSecretKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerSecretKeyObject_set_Sensitive(TElPKCS11ManagerSecretKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerSecretKeyObject_get_Sign(TElPKCS11ManagerSecretKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerSecretKeyObject_set_Sign(TElPKCS11ManagerSecretKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerSecretKeyObject_get_Unwrap(TElPKCS11ManagerSecretKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerSecretKeyObject_set_Unwrap(TElPKCS11ManagerSecretKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerSecretKeyObject_get_Verify(TElPKCS11ManagerSecretKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerSecretKeyObject_set_Verify(TElPKCS11ManagerSecretKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerSecretKeyObject_get_Wrap(TElPKCS11ManagerSecretKeyObjectHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerSecretKeyObject_set_Wrap(TElPKCS11ManagerSecretKeyObjectHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ManagerSecretKeyObject_Create(TElPKCS11ManagerHandle Owner, TElPKCS11ManagerObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11MANAGERSECRETKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11CONSUMERMANAGER
SB_IMPORT uint32_t SB_APIENTRY TElPKCS11ConsumerManager_Create(TElPKCS11ConsumerHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS11CONSUMERMANAGER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPKCS11Manager;
typedef TElPKCS11Manager ElPKCS11Manager;
class TElPKCS11ManagerObject;
typedef TElPKCS11ManagerObject ElPKCS11ManagerObject;
class TElPKCS11ManagerDataObject;
typedef TElPKCS11ManagerDataObject ElPKCS11ManagerDataObject;
class TElPKCS11ManagerCertificateObject;
typedef TElPKCS11ManagerCertificateObject ElPKCS11ManagerCertificateObject;
class TElPKCS11ManagerKeyObject;
typedef TElPKCS11ManagerKeyObject ElPKCS11ManagerKeyObject;
class TElPKCS11ManagerPublicKeyObject;
typedef TElPKCS11ManagerPublicKeyObject ElPKCS11ManagerPublicKeyObject;
class TElPKCS11ManagerPrivateKeyObject;
typedef TElPKCS11ManagerPrivateKeyObject ElPKCS11ManagerPrivateKeyObject;
class TElPKCS11ManagerSecretKeyObject;
typedef TElPKCS11ManagerSecretKeyObject ElPKCS11ManagerSecretKeyObject;
class TElPKCS11ConsumerManager;
typedef TElPKCS11ConsumerManager ElPKCS11ConsumerManager;

#ifdef SB_USE_CLASS_TELPKCS11MANAGER
class TElPKCS11Manager: public TComponent
{
	private:
		SB_DISABLE_COPY(TElPKCS11Manager)
#ifdef SB_USE_CLASS_TELPKCS11MANAGEROBJECT
		TElPKCS11ManagerObject* _Inst_Objects;
#endif /* SB_USE_CLASS_TELPKCS11MANAGEROBJECT */
#ifdef SB_USE_CLASS_TELPKCS11MODULE
		TElPKCS11Module* _Inst_Module;
#endif /* SB_USE_CLASS_TELPKCS11MODULE */
#ifdef SB_IOS
#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
		TElPKCS11FunctionsManager* _Inst_FunctionsManager;
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */
#endif

		void initInstances();

	public:
		void Close();

		void Open();

#ifdef SB_USE_CLASS_TELPKCS11SESSIONINFO
		TElPKCS11SessionInfoHandle OpenSession(int32_t SlotIndex, bool ReadOnly);
#endif /* SB_USE_CLASS_TELPKCS11SESSIONINFO */

		void CloseSession();

#ifdef SB_NOT_CPU64_OR_WINDOWS
		int32_t IndexOfObject(uint32_t Handle);
#else
		int32_t IndexOfObject(int64_t Handle);
#endif

#ifdef SB_USE_CLASS_TELPKCS11MANAGEROBJECT
		int32_t IndexOfObject(TElPKCS11ManagerObject &AnObject);

		int32_t IndexOfObject(TElPKCS11ManagerObject *AnObject);
#endif /* SB_USE_CLASS_TELPKCS11MANAGEROBJECT */

#ifdef SB_NOT_CPU64_OR_WINDOWS
		void RemoveObject(uint32_t Handle);
#else
		void RemoveObject(int64_t Handle);
#endif

#ifdef SB_USE_CLASS_TELPKCS11MANAGEROBJECT
		void RemoveObject(TElPKCS11ManagerObject &AnObject);

		void RemoveObject(TElPKCS11ManagerObject *AnObject);
#endif /* SB_USE_CLASS_TELPKCS11MANAGEROBJECT */

		void RemoveObject(int32_t Index);

		void RefreshObjects();

#ifdef SB_USE_CLASS_TELPKCS11MANAGEROBJECT
		bool AddObject(TElPKCS11ManagerObject &AnObject);

		bool AddObject(TElPKCS11ManagerObject *AnObject);
#endif /* SB_USE_CLASS_TELPKCS11MANAGEROBJECT */

#ifdef SB_USE_CLASS_TELPKCS11MANAGEROBJECT
		virtual TElPKCS11ManagerObject* get_Objects(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS11MANAGEROBJECT */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElPKCS11Manager, Count);

#ifdef SB_USE_CLASS_TELPKCS11MODULE
		virtual TElPKCS11Module* get_Module();

		SB_DECLARE_PROPERTY_GET(TElPKCS11Module*, get_Module, TElPKCS11Manager, Module);
#endif /* SB_USE_CLASS_TELPKCS11MODULE */

#ifndef SB_IOS
		virtual void get_DLLName(std::string &OutResult);
#else
#ifdef SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER
		virtual TElPKCS11FunctionsManager* get_FunctionsManager();

		virtual void set_FunctionsManager(TElPKCS11FunctionsManager &Value);

		virtual void set_FunctionsManager(TElPKCS11FunctionsManager *Value);

		SB_DECLARE_PROPERTY(TElPKCS11FunctionsManager*, get_FunctionsManager, set_FunctionsManager, TElPKCS11Manager, FunctionsManager);
#endif /* SB_USE_CLASS_TELPKCS11FUNCTIONSMANAGER */
#endif

#ifndef SB_IOS
		virtual void set_DLLName(const std::string &Value);
#endif

		virtual TSBPKCS11StorageOptions get_PKCS11Options();

		virtual void set_PKCS11Options(TSBPKCS11StorageOptions Value);

		SB_DECLARE_PROPERTY(TSBPKCS11StorageOptions, get_PKCS11Options, set_PKCS11Options, TElPKCS11Manager, PKCS11Options);

		virtual void get_OnNotification(TElPKCSNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnNotification(TElPKCSNotifyEvent pMethodValue, void * pDataValue);

		TElPKCS11Manager(TElPKCS11ManagerHandle handle, TElOwnHandle ownHandle);

		explicit TElPKCS11Manager(TComponent &Owner);

		explicit TElPKCS11Manager(TComponent *Owner);

		virtual ~TElPKCS11Manager();

};
#endif /* SB_USE_CLASS_TELPKCS11MANAGER */

#ifdef SB_USE_CLASS_TELPKCS11MANAGEROBJECT
class TElPKCS11ManagerObject: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11ManagerObject)
	public:
#ifdef SB_NOT_CPU64_OR_WINDOWS
		virtual uint32_t get_Handle();
#else
		virtual int64_t get_Handle();
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		SB_DECLARE_PROPERTY_GET(uint32_t, get_Handle, TElPKCS11ManagerObject, Handle);
#else
		SB_DECLARE_PROPERTY_GET(int64_t, get_Handle, TElPKCS11ManagerObject, Handle);
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		virtual uint32_t get_HWSize();
#else
		virtual int64_t get_HWSize();
#endif

#ifdef SB_NOT_CPU64_OR_WINDOWS
		SB_DECLARE_PROPERTY_GET(uint32_t, get_HWSize, TElPKCS11ManagerObject, HWSize);
#else
		SB_DECLARE_PROPERTY_GET(int64_t, get_HWSize, TElPKCS11ManagerObject, HWSize);
#endif

		virtual void get_ID(std::vector<uint8_t> &OutResult);

		virtual void get_Label_(std::string &OutResult);

		virtual void set_Label_(const std::string &Value);

		virtual bool get_Modifiable();

		virtual void set_Modifiable(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Modifiable, set_Modifiable, TElPKCS11ManagerObject, Modifiable);

		virtual bool get_Private_();

		virtual void set_Private_(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Private_, set_Private_, TElPKCS11ManagerObject, Private_);

		virtual bool get_Token();

		virtual void set_Token(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Token, set_Token, TElPKCS11ManagerObject, Token);

		TElPKCS11ManagerObject(TElPKCS11ManagerObjectHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPKCS11MANAGER
		explicit TElPKCS11ManagerObject(TElPKCS11Manager &Owner);

		explicit TElPKCS11ManagerObject(TElPKCS11Manager *Owner);
#endif /* SB_USE_CLASS_TELPKCS11MANAGER */

};
#endif /* SB_USE_CLASS_TELPKCS11MANAGEROBJECT */

#ifdef SB_USE_CLASS_TELPKCS11MANAGERDATAOBJECT
class TElPKCS11ManagerDataObject: public TElPKCS11ManagerObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11ManagerDataObject)
	public:
		virtual void get_Application(std::string &OutResult);

		virtual void set_Application(const std::string &Value);

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual void set_OID(const std::vector<uint8_t> &Value);

		virtual void get_Value(std::vector<uint8_t> &OutResult);

		virtual void set_Value(const std::vector<uint8_t> &Value);

		TElPKCS11ManagerDataObject(TElPKCS11ManagerDataObjectHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPKCS11MANAGER
		explicit TElPKCS11ManagerDataObject(TElPKCS11Manager &Owner);

		explicit TElPKCS11ManagerDataObject(TElPKCS11Manager *Owner);
#endif /* SB_USE_CLASS_TELPKCS11MANAGER */

};
#endif /* SB_USE_CLASS_TELPKCS11MANAGERDATAOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11MANAGERCERTIFICATEOBJECT
class TElPKCS11ManagerCertificateObject: public TElPKCS11ManagerObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11ManagerCertificateObject)
	public:
		virtual void get_ACAttrTypes(std::vector<uint8_t> &OutResult);

		virtual void set_ACAttrTypes(const std::vector<uint8_t> &Value);

		virtual void get_ACIssuer(std::vector<uint8_t> &OutResult);

		virtual void set_ACIssuer(const std::vector<uint8_t> &Value);

		virtual void get_ACOwner(std::vector<uint8_t> &OutResult);

		virtual void set_ACOwner(const std::vector<uint8_t> &Value);

		virtual TElPKCS11CertificateCategory get_Category();

		virtual void set_Category(TElPKCS11CertificateCategory Value);

		SB_DECLARE_PROPERTY(TElPKCS11CertificateCategory, get_Category, set_Category, TElPKCS11ManagerCertificateObject, Category);

		virtual TElPKCS11CertificateType get_CertificateType();

		virtual void set_CertificateType(TElPKCS11CertificateType Value);

		SB_DECLARE_PROPERTY(TElPKCS11CertificateType, get_CertificateType, set_CertificateType, TElPKCS11ManagerCertificateObject, CertificateType);

		virtual void get_Issuer(std::vector<uint8_t> &OutResult);

		virtual void set_Issuer(const std::vector<uint8_t> &Value);

		virtual void get_SerialNumber(std::vector<uint8_t> &OutResult);

		virtual void set_SerialNumber(const std::vector<uint8_t> &Value);

		virtual void get_Subject(std::vector<uint8_t> &OutResult);

		virtual void set_Subject(const std::vector<uint8_t> &Value);

		virtual bool get_Trusted();

		virtual void set_Trusted(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Trusted, set_Trusted, TElPKCS11ManagerCertificateObject, Trusted);

		virtual int64_t get_ValidFrom();

		virtual void set_ValidFrom(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ValidFrom, set_ValidFrom, TElPKCS11ManagerCertificateObject, ValidFrom);

		virtual int64_t get_ValidTo();

		virtual void set_ValidTo(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ValidTo, set_ValidTo, TElPKCS11ManagerCertificateObject, ValidTo);

		virtual void get_URL(std::string &OutResult);

		virtual void set_URL(const std::string &Value);

		virtual void get_Value(std::vector<uint8_t> &OutResult);

		virtual void set_Value(const std::vector<uint8_t> &Value);

		TElPKCS11ManagerCertificateObject(TElPKCS11ManagerCertificateObjectHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPKCS11MANAGER
		explicit TElPKCS11ManagerCertificateObject(TElPKCS11Manager &Owner);

		explicit TElPKCS11ManagerCertificateObject(TElPKCS11Manager *Owner);
#endif /* SB_USE_CLASS_TELPKCS11MANAGER */

};
#endif /* SB_USE_CLASS_TELPKCS11MANAGERCERTIFICATEOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11MANAGERKEYOBJECT
class TElPKCS11ManagerKeyObject: public TElPKCS11ManagerObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11ManagerKeyObject)
	public:
		virtual int64_t get_ValidFrom();

		virtual void set_ValidFrom(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ValidFrom, set_ValidFrom, TElPKCS11ManagerKeyObject, ValidFrom);

		virtual int64_t get_ValidTo();

		virtual void set_ValidTo(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ValidTo, set_ValidTo, TElPKCS11ManagerKeyObject, ValidTo);

		TElPKCS11ManagerKeyObject(TElPKCS11ManagerKeyObjectHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPKCS11MANAGER
		explicit TElPKCS11ManagerKeyObject(TElPKCS11Manager &Owner);

		explicit TElPKCS11ManagerKeyObject(TElPKCS11Manager *Owner);
#endif /* SB_USE_CLASS_TELPKCS11MANAGER */

};
#endif /* SB_USE_CLASS_TELPKCS11MANAGERKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11MANAGERPUBLICKEYOBJECT
class TElPKCS11ManagerPublicKeyObject: public TElPKCS11ManagerKeyObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11ManagerPublicKeyObject)
	public:
		virtual bool get_Encrypt();

		virtual void set_Encrypt(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Encrypt, set_Encrypt, TElPKCS11ManagerPublicKeyObject, Encrypt);

		virtual void get_Subject(std::vector<uint8_t> &OutResult);

		virtual void set_Subject(const std::vector<uint8_t> &Value);

		virtual bool get_Trusted();

		virtual void set_Trusted(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Trusted, set_Trusted, TElPKCS11ManagerPublicKeyObject, Trusted);

		virtual bool get_Verify();

		virtual void set_Verify(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Verify, set_Verify, TElPKCS11ManagerPublicKeyObject, Verify);

		virtual bool get_VerifyRecover();

		virtual void set_VerifyRecover(bool Value);

		SB_DECLARE_PROPERTY(bool, get_VerifyRecover, set_VerifyRecover, TElPKCS11ManagerPublicKeyObject, VerifyRecover);

		virtual bool get_Wrap();

		virtual void set_Wrap(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Wrap, set_Wrap, TElPKCS11ManagerPublicKeyObject, Wrap);

		TElPKCS11ManagerPublicKeyObject(TElPKCS11ManagerPublicKeyObjectHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPKCS11MANAGER
		explicit TElPKCS11ManagerPublicKeyObject(TElPKCS11Manager &Owner);

		explicit TElPKCS11ManagerPublicKeyObject(TElPKCS11Manager *Owner);
#endif /* SB_USE_CLASS_TELPKCS11MANAGER */

};
#endif /* SB_USE_CLASS_TELPKCS11MANAGERPUBLICKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11MANAGERPRIVATEKEYOBJECT
class TElPKCS11ManagerPrivateKeyObject: public TElPKCS11ManagerKeyObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11ManagerPrivateKeyObject)
	public:
		virtual bool get_AlwaysAuthenticate();

		virtual void set_AlwaysAuthenticate(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AlwaysAuthenticate, set_AlwaysAuthenticate, TElPKCS11ManagerPrivateKeyObject, AlwaysAuthenticate);

		virtual bool get_Decrypt();

		virtual void set_Decrypt(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Decrypt, set_Decrypt, TElPKCS11ManagerPrivateKeyObject, Decrypt);

		virtual bool get_Extractable();

		virtual void set_Extractable(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Extractable, set_Extractable, TElPKCS11ManagerPrivateKeyObject, Extractable);

		virtual bool get_Sensitive();

		virtual void set_Sensitive(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Sensitive, set_Sensitive, TElPKCS11ManagerPrivateKeyObject, Sensitive);

		virtual bool get_Sign();

		virtual void set_Sign(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Sign, set_Sign, TElPKCS11ManagerPrivateKeyObject, Sign);

		virtual bool get_SignRecover();

		virtual void set_SignRecover(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SignRecover, set_SignRecover, TElPKCS11ManagerPrivateKeyObject, SignRecover);

		virtual void get_Subject(std::vector<uint8_t> &OutResult);

		virtual void set_Subject(const std::vector<uint8_t> &Value);

		virtual bool get_Unwrap();

		virtual void set_Unwrap(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Unwrap, set_Unwrap, TElPKCS11ManagerPrivateKeyObject, Unwrap);

		TElPKCS11ManagerPrivateKeyObject(TElPKCS11ManagerPrivateKeyObjectHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPKCS11MANAGER
		explicit TElPKCS11ManagerPrivateKeyObject(TElPKCS11Manager &Owner);

		explicit TElPKCS11ManagerPrivateKeyObject(TElPKCS11Manager *Owner);
#endif /* SB_USE_CLASS_TELPKCS11MANAGER */

};
#endif /* SB_USE_CLASS_TELPKCS11MANAGERPRIVATEKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11MANAGERSECRETKEYOBJECT
class TElPKCS11ManagerSecretKeyObject: public TElPKCS11ManagerKeyObject
{
	private:
		SB_DISABLE_COPY(TElPKCS11ManagerSecretKeyObject)
	public:
		virtual bool get_Decrypt();

		virtual void set_Decrypt(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Decrypt, set_Decrypt, TElPKCS11ManagerSecretKeyObject, Decrypt);

		virtual bool get_Encrypt();

		virtual void set_Encrypt(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Encrypt, set_Encrypt, TElPKCS11ManagerSecretKeyObject, Encrypt);

		virtual bool get_Extractable();

		virtual void set_Extractable(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Extractable, set_Extractable, TElPKCS11ManagerSecretKeyObject, Extractable);

		virtual bool get_Sensitive();

		virtual void set_Sensitive(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Sensitive, set_Sensitive, TElPKCS11ManagerSecretKeyObject, Sensitive);

		virtual bool get_Sign();

		virtual void set_Sign(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Sign, set_Sign, TElPKCS11ManagerSecretKeyObject, Sign);

		virtual bool get_Unwrap();

		virtual void set_Unwrap(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Unwrap, set_Unwrap, TElPKCS11ManagerSecretKeyObject, Unwrap);

		virtual bool get_Verify();

		virtual void set_Verify(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Verify, set_Verify, TElPKCS11ManagerSecretKeyObject, Verify);

		virtual bool get_Wrap();

		virtual void set_Wrap(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Wrap, set_Wrap, TElPKCS11ManagerSecretKeyObject, Wrap);

		TElPKCS11ManagerSecretKeyObject(TElPKCS11ManagerSecretKeyObjectHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELPKCS11MANAGER
		explicit TElPKCS11ManagerSecretKeyObject(TElPKCS11Manager &Owner);

		explicit TElPKCS11ManagerSecretKeyObject(TElPKCS11Manager *Owner);
#endif /* SB_USE_CLASS_TELPKCS11MANAGER */

};
#endif /* SB_USE_CLASS_TELPKCS11MANAGERSECRETKEYOBJECT */

#ifdef SB_USE_CLASS_TELPKCS11CONSUMERMANAGER
class TElPKCS11ConsumerManager: public TElPKCS11Consumer
{
	private:
		SB_DISABLE_COPY(TElPKCS11ConsumerManager)
	public:
		TElPKCS11ConsumerManager(TElPKCS11ConsumerManagerHandle handle, TElOwnHandle ownHandle);

		TElPKCS11ConsumerManager();

};
#endif /* SB_USE_CLASS_TELPKCS11CONSUMERMANAGER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPKCS11MANAGER */
