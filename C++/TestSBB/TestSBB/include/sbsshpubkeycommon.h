#ifndef __INC_SBSSHPUBKEYCOMMON
#define __INC_SBSSHPUBKEYCOMMON

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbsshcommon.h"
#include "sbsshconstants.h"
#include "sbsshkeystorage.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbsshutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SSH_PUBLICKEY_SUCCESS 	0
#define SB_SSH_PUBLICKEY_ACCESS_DENIED 	1
#define SB_SSH_PUBLICKEY_STORAGE_EXCEEDED 	2
#define SB_SSH_PUBLICKEY_VERSION_NOT_SUPPORTED 	3
#define SB_SSH_PUBLICKEY_KEY_NOT_FOUND 	4
#define SB_SSH_PUBLICKEY_KEY_NOT_SUPPORTED 	5
#define SB_SSH_PUBLICKEY_KEY_ALREADY_PRESENT 	6
#define SB_SSH_PUBLICKEY_GENERAL_FAILURE 	7
#define SB_SSH_PUBLICKEY_REQUEST_NOT_SUPPORTED 	8
#define SB_SSH_PUBLICKEY_ATTRIBUTE_NOT_SUPPORTED 	9
#ifndef SB_BUFFER_SIZE
#define SB_BUFFER_SIZE 	16384
#endif

typedef TElClassHandle TElSSHPublicKeyAttributesHandle;

typedef TElSSHPublicKeyAttributesHandle ElSSHPublicKeyAttributesHandle;

typedef void (SB_CALLBACK *TSBSSHPublicKeyErrorEvent)(void * _ObjectData, TObjectHandle Sender, int32_t ErrorCode, const char * pcComment, int32_t szComment);

typedef void (SB_CALLBACK *TSBSSHPublicKeyInvalidReplyEvent)(void * _ObjectData, TObjectHandle Sender);

typedef void (SB_CALLBACK *TSBSSHPublicKeyStatusEvent)(void * _ObjectData, TObjectHandle Sender, int32_t Status, const char * pcDescr, int32_t szDescr, const char * pcTag, int32_t szTag);

typedef void (SB_CALLBACK *TSBSSHPublicKeyAttributeEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcAttr, int32_t szAttr, int8_t Compulsory);

typedef void (SB_CALLBACK *TSBSSHPublicKeyPublicKeyEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHKeyHandle Key, TElSSHPublicKeyAttributesHandle Attributes);

typedef void (SB_CALLBACK *TSBSSHPublicKeySendEvent)(void * _ObjectData, TObjectHandle Sender, void * Buffer, int32_t Size);

typedef void (SB_CALLBACK *TSBSSHPublicKeyReceiveEvent)(void * _ObjectData, TObjectHandle Sender, void * Buffer, int32_t MaxSize, int32_t * Written);

typedef void (SB_CALLBACK *TSBSSHPublicKeyAddEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHKeyHandle Key, TElSSHPublicKeyAttributesHandle Attributes, int8_t Overwrite, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TSBSSHPublicKeyRemoveEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHKeyHandle Key, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TSBSSHPublicKeyListEvent)(void * _ObjectData, TObjectHandle Sender, TListHandle Keys, TListHandle Attributes, int8_t * FreeObjects, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TSBSSHPublicKeyListAttributesEvent)(void * _ObjectData, TObjectHandle Sender, TStringListHandle Names, TBitsHandle Compulsories, int32_t * ErrorCode, char * pcComment, int32_t * szComment);

typedef void (SB_CALLBACK *TSBSSHPublicKeyAttrubuteSupportedEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcAttr, int32_t szAttr, int8_t * Supported);

#ifdef SB_USE_CLASS_TELSSHPUBLICKEYATTRIBUTES
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyAttributes_Add(TElSSHPublicKeyAttributesHandle _Handle, const char * pcAName, int32_t szAName, const char * pcAValue, int32_t szAValue, int8_t AMandatory);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyAttributes_Remove(TElSSHPublicKeyAttributesHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyAttributes_Clear(TElSSHPublicKeyAttributesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyAttributes_get_Count(TElSSHPublicKeyAttributesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyAttributes_get_Names(TElSSHPublicKeyAttributesHandle _Handle, int32_t i, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyAttributes_set_Names(TElSSHPublicKeyAttributesHandle _Handle, int32_t i, const char * pcv, int32_t szv);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyAttributes_get_Values(TElSSHPublicKeyAttributesHandle _Handle, int32_t i, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyAttributes_set_Values(TElSSHPublicKeyAttributesHandle _Handle, int32_t i, const char * pcv, int32_t szv);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyAttributes_get_Mandatory(TElSSHPublicKeyAttributesHandle _Handle, int32_t i, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyAttributes_set_Mandatory(TElSSHPublicKeyAttributesHandle _Handle, int32_t i, int8_t v);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyAttributes_Create(TElSSHPublicKeyAttributesHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHPUBLICKEYATTRIBUTES */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSSHPublicKeyAttributes;
typedef TElSSHPublicKeyAttributes ElSSHPublicKeyAttributes;

#ifdef SB_USE_CLASS_TELSSHPUBLICKEYATTRIBUTES
class TElSSHPublicKeyAttributes: public TObject
{
	private:
		SB_DISABLE_COPY(TElSSHPublicKeyAttributes)
	public:
		void Add(const std::string &AName, const std::string &AValue, bool AMandatory);

		void Remove(int32_t Index);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElSSHPublicKeyAttributes, Count);

		virtual void get_Names(int32_t i, std::string &OutResult);

		virtual void set_Names(int32_t i, const std::string &v);

		virtual void get_Values(int32_t i, std::string &OutResult);

		virtual void set_Values(int32_t i, const std::string &v);

		virtual bool get_Mandatory(int32_t i);

		virtual void set_Mandatory(int32_t i, bool v);

		TElSSHPublicKeyAttributes(TElSSHPublicKeyAttributesHandle handle, TElOwnHandle ownHandle);

		TElSSHPublicKeyAttributes();

};
#endif /* SB_USE_CLASS_TELSSHPUBLICKEYATTRIBUTES */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSSHPUBKEYCOMMON */

