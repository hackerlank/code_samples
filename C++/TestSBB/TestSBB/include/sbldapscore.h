#ifndef __INC_SBLDAPSCORE
#define __INC_SBLDAPSCORE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbsslcommon.h"
#include "sbsimplessl.h"
#include "sbcustomcertstorage.h"
#include "sbsslconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbstreams.h"
#include "sbsocket.h"
#include "sbstringlist.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifndef SB_SInternalError
#define SB_SInternalError 	"Internal error: "
#endif
#define SB_SWrongMessageError 	"Wrong message content"
#define SB_SBindError 	"Bind operation failed"
#define SB_SSASLError 	"SASL error"
#define SB_SWrongResponse 	"Wrong server response message"
#define SB_SServerError 	"Server returned error"
#define SB_SNotImplemented 	"Not implemented"
#define SB_SInvalidFilterString 	"Invalid filter string"
#define SB_SInvalidFilterSequence 	"Invalid filters sequence"
#define SB_SInvalidLdapUrl 	"Invalid LDAP URL"
#define SB_SWrongParameter 	"Invalid function parameter"
#define SB_LDAP_VERSION 	3
#define SB_LDAP_UNKNOWN 	-1
#define SB_LDAP_REQ_BIND 	96
#define SB_LDAP_REQ_UNBIND 	66
#define SB_LDAP_REQ_SEARCH 	99
#define SB_LDAP_REQ_MODIFY 	102
#define SB_LDAP_REQ_ADD 	104
#define SB_LDAP_REQ_DELETE 	74
#define SB_LDAP_REQ_MODDN 	108
#define SB_LDAP_REQ_MODRDN 	108
#define SB_LDAP_REQ_RENAME 	108
#define SB_LDAP_REQ_COMPARE 	110
#define SB_LDAP_REQ_ABANDON 	80
#define SB_LDAP_REQ_EXTENDED 	119
#define SB_LDAP_RES_BIND 	97
#define SB_LDAP_RES_SEARCH_ENTRY 	100
#define SB_LDAP_RES_SEARCH_REFERENCE 	115
#define SB_LDAP_RES_SEARCH_RESULT 	101
#define SB_LDAP_RES_MODIFY 	103
#define SB_LDAP_RES_ADD 	105
#define SB_LDAP_RES_DELETE 	107
#define SB_LDAP_RES_MODDN 	109
#define SB_LDAP_RES_MODRDN 	109
#define SB_LDAP_RES_RENAME 	109
#define SB_LDAP_RES_COMPARE 	111
#define SB_LDAP_RES_EXTENDED 	120
#define SB_LDAP_RES_INTERMEDIATE 	121
#define SB_LDAP_FILTER_AND 	160
#define SB_LDAP_FILTER_OR 	161
#define SB_LDAP_FILTER_NOT 	162
#define SB_LDAP_FILTER_EQUALITY 	163
#define SB_LDAP_FILTER_SUBSTRINGS 	164
#define SB_LDAP_FILTER_GE 	165
#define SB_LDAP_FILTER_LE 	166
#define SB_LDAP_FILTER_PRESENT 	135
#define SB_LDAP_FILTER_APPROX 	168
#define SB_LDAP_FILTER_EXT 	169
#define SB_LDAP_FILTER_EXT_OID 	129
#define SB_LDAP_FILTER_EXT_TYPE 	130
#define SB_LDAP_FILTER_EXT_VALUE 	131
#define SB_LDAP_FILTER_EXT_DNATTRS 	132
#define SB_LDAP_SUBSTRING_INITIAL 	128
#define SB_LDAP_SUBSTRING_ANY 	129
#define SB_LDAP_SUBSTRING_FINAL 	130
#define SB_LDAP_RESULT_SUCCESS 	0
#define SB_LDAP_RESULT_OPERATIONS_ERROR 	1
#define SB_LDAP_RESULT_PROTOCOL_ERROR 	2
#define SB_LDAP_RESULT_TIME_LIMIT 	3
#define SB_LDAP_RESULT_SIZE_LIMIT 	4
#define SB_LDAP_RESULT_COMPARE_FALSE 	5
#define SB_LDAP_RESULT_COMPARE_TRUE 	6
#define SB_LDAP_RESULT_AUTH_METHOD_NOT_SUPPORTED 	7
#define SB_LDAP_RESULT_STRONGER_AUTH_REQUIRED 	8
#define SB_LDAP_RESULT_REFERRAL 	10
#define SB_LDAP_RESULT_ADMIN_LIMIT 	11
#define SB_LDAP_RESULT_UNAVALIABLE_CRITICAL_EXTENSION 	12
#define SB_LDAP_RESULT_CONFIDENTIALITY_REQUIRED 	13
#define SB_LDAP_RESULT_SASL_BIND_IN_PROGRESS 	14
#define SB_LDAP_RESULT_NO_SUCH_ATTRIBUTE 	16
#define SB_LDAP_RESULT_UNDEFINED_ATTRIBUTE_TYPE 	17
#define SB_LDAP_RESULT_INAPPROPRIATE_MATCHING 	18
#define SB_LDAP_RESULT_CONSTRAINT_VIOLATION 	19
#define SB_LDAP_RESULT_ATTRIBUTE_OR_VALUE_EXISTS 	20
#define SB_LDAP_RESULT_INVALID_ATTRIBUTE_SYNTAX 	21
#define SB_LDAP_RESULT_NO_SUCH_OBJECT 	32
#define SB_LDAP_RESULT_ALIAS_PROBLEM 	33
#define SB_LDAP_RESULT_INVALID_DN_SYNTAX 	34
#define SB_LDAP_RESULT_ALIAS_DEREFERENCING_PROBLEM 	36
#define SB_LDAP_RESULT_INAPPROPRIATE_AUTHENTICATION 	48
#define SB_LDAP_RESULT_INVALID_CREDENTIALS 	49
#define SB_LDAP_RESULT_INSUFFICIENT_ACCESS_RIGHTS 	50
#define SB_LDAP_RESULT_BUSY 	51
#define SB_LDAP_RESULT_UNAVAILABLE 	52
#define SB_LDAP_RESULT_UNWILLING_TO_PERFORM 	53
#define SB_LDAP_RESULT_LOOP_DETECT 	54
#define SB_LDAP_RESULT_NAMING_VIOLATION 	64
#define SB_LDAP_RESULT_OBJECT_CLASS_VIOLATION 	65
#define SB_LDAP_RESULT_NOT_ALLOWED_ON_NON_LEAF 	66
#define SB_LDAP_RESULT_NOT_ALLOWED_ON_RDN 	67
#define SB_LDAP_RESULT_ENTRY_ALREADY_EXISTS 	68
#define SB_LDAP_RESULT_OBJECT_CLASS_MODS_PROHIBITED 	69
#define SB_LDAP_RESULT_AFFECTS_MULTIPLE_DSAS 	71
#define SB_LDAP_RESULT_OTHER 	80
#define SB_LDAP_ERROR_INTERNAL 	81
#define SB_LDAP_ERROR_WRONG_MESSAGE 	82
#define SB_LDAP_ERROR_BIND 	83
#define SB_LDAP_ERROR_SEARCH 	84
#define SB_LDAP_ERROR_SEARCH_FILTER 	85
#define SB_LDAP_ERROR_FILTER_SEQUENCE 	86
#define SB_LDAP_ERROR_GET_RESPONSE 	87
#define SB_LDAP_ERROR_SASL 	88
#define SB_LDAP_WRONG_LDAP_URL 	89
#define SB_LDAP_ERROR_DELETE 	90
#define SB_LDAP_ERROR_ADD 	91
#define SB_LDAP_ERROR_MODIFY 	92

typedef TElClassHandle TElLDAPMessageHandle;

typedef TElLDAPMessageHandle ElLDAPMessageHandle;

typedef TElClassHandle TElLDAPSimpleBindMessageHandle;

typedef TElLDAPSimpleBindMessageHandle ElLDAPSimpleBindMessageHandle;

typedef TElClassHandle TElLDAPSASLBindMessageHandle;

typedef TElLDAPSASLBindMessageHandle ElLDAPSASLBindMessageHandle;

typedef TElClassHandle TElLDAPUnbindMessageHandle;

typedef TElLDAPUnbindMessageHandle ElLDAPUnbindMessageHandle;

typedef TElClassHandle TElLDAPResultHandle;

typedef TElLDAPResultHandle ElLDAPResultHandle;

typedef TElClassHandle TElLDAPResultMessageHandle;

typedef TElLDAPResultMessageHandle ElLDAPResultMessageHandle;

typedef TElLDAPResultMessageHandle TElLDAPSearchResultDoneMessageHandle;

typedef TElLDAPResultMessageHandle ElLDAPSearchResultDoneMessageHandle;

typedef TElClassHandle TElLDAPBindResponseMessageHandle;

typedef TElLDAPBindResponseMessageHandle ElLDAPBindResponseMessageHandle;

typedef TElClassHandle TElLDAPSearchMessageHandle;

typedef TElLDAPSearchMessageHandle ElLDAPSearchMessageHandle;

typedef TElClassHandle TElLDAPAttributeValueHandle;

typedef TElLDAPAttributeValueHandle ElLDAPAttributeValueHandle;

typedef TElClassHandle TElLDAPPartialAttributeHandle;

typedef TElLDAPPartialAttributeHandle ElLDAPPartialAttributeHandle;

typedef TElLDAPPartialAttributeHandle TElLDAPAttributeHandle;

typedef TElLDAPPartialAttributeHandle ElLDAPAttributeHandle;

typedef TElClassHandle TElLDAPSearchEntryMessageHandle;

typedef TElLDAPSearchEntryMessageHandle ElLDAPSearchEntryMessageHandle;

typedef TElClassHandle TElLDAPSearchReferenceMessageHandle;

typedef TElLDAPSearchReferenceMessageHandle ElLDAPSearchReferenceMessageHandle;

typedef TElClassHandle TElLDAPDeleteMessageHandle;

typedef TElLDAPDeleteMessageHandle ElLDAPDeleteMessageHandle;

typedef TElLDAPResultMessageHandle TElLDAPDeleteResponseMessageHandle;

typedef TElLDAPResultMessageHandle ElLDAPDeleteResponseMessageHandle;

typedef TElClassHandle TElLDAPModifyMessageHandle;

typedef TElLDAPModifyMessageHandle ElLDAPModifyMessageHandle;

typedef TElLDAPModifyMessageHandle TElLDAPAddMessageHandle;

typedef TElLDAPModifyMessageHandle ElLDAPAddMessageHandle;

typedef TElLDAPResultMessageHandle TElLDAPAddResponseMessageHandle;

typedef TElLDAPResultMessageHandle ElLDAPAddResponseMessageHandle;

typedef TElLDAPResultMessageHandle TElLDAPModifyResponseMessageHandle;

typedef TElLDAPResultMessageHandle ElLDAPModifyResponseMessageHandle;

typedef uint8_t TSBLDAPScopeRaw;

typedef enum
{
	scBase = 0,
	scOneLevel = 1,
	scSubTree = 2
} TSBLDAPScope;

typedef uint8_t TSBLDAPModifyOperationRaw;

typedef enum
{
	moNone = 0,
	moAdd = 1,
	moDelete = 2,
	moReplace = 3
} TSBLDAPModifyOperation;

#ifdef SB_USE_CLASS_TELLDAPMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElLDAPMessage_SaveToBuffer(TElLDAPMessageHandle _Handle, void * Buf, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPMessage_get_Code(TElLDAPMessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPMessage_get_ID(TElLDAPMessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPMessage_Create(TElLDAPMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPMessage_Create_1(int32_t MessageID, int32_t Code, TElLDAPMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPSIMPLEBINDMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSimpleBindMessage_Create(int32_t MessageID, const char * pcLDAPDN, int32_t szLDAPDN, const char * pcPassword, int32_t szPassword, TElLDAPSimpleBindMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPSIMPLEBINDMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPSASLBINDMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSASLBindMessage_Create(int32_t MessageID, const char * pcLDAPDN, int32_t szLDAPDN, const char * pcPassword, int32_t szPassword, const char * pcMechanism, int32_t szMechanism, const uint8_t pCredentials[], int32_t szCredentials, int32_t CredLen, TElLDAPSASLBindMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPSASLBINDMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPUNBINDMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElLDAPUnbindMessage_Create(int32_t MessageID, TElLDAPUnbindMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPUNBINDMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPRESULT
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResult_get_ResultCode(TElLDAPResultHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResult_get_MatchedDN(TElLDAPResultHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResult_get_DiagnosticMessage(TElLDAPResultHandle _Handle, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResult_get_Referal(TElLDAPResultHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResult_get_Referal(TElLDAPResultHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResult_get_HasReferal(TElLDAPResultHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResult_get_Success(TElLDAPResultHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResult_Create(TElASN1ConstrainedTagHandle * Tag, TElLDAPResultHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPRESULT */

#ifdef SB_USE_CLASS_TELLDAPRESULTMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResultMessage_get_ResultCode(TElLDAPResultMessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResultMessage_get_MatchedDN(TElLDAPResultMessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResultMessage_get_DiagnosticMessage(TElLDAPResultMessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResultMessage_get_Referal(TElLDAPResultMessageHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResultMessage_get_Referal(TElLDAPResultMessageHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResultMessage_get_HasReferal(TElLDAPResultMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResultMessage_get_Success(TElLDAPResultMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPResultMessage_Create(void * Buf, int32_t Size, TElLDAPResultMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPRESULTMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPBINDRESPONSEMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElLDAPBindResponseMessage_get_ResultCode(TElLDAPBindResponseMessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPBindResponseMessage_get_MatchedDN(TElLDAPBindResponseMessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPBindResponseMessage_get_DiagnosticMessage(TElLDAPBindResponseMessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElLDAPBindResponseMessage_get_Referal(TElLDAPBindResponseMessageHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElLDAPBindResponseMessage_get_Referal(TElLDAPBindResponseMessageHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElLDAPBindResponseMessage_get_HasReferal(TElLDAPBindResponseMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPBindResponseMessage_get_Success(TElLDAPBindResponseMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPBindResponseMessage_get_ServerSaslCreds(TElLDAPBindResponseMessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPBindResponseMessage_Create(void * Buf, int32_t Size, TElLDAPBindResponseMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPBINDRESPONSEMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPSEARCHMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSearchMessage_Create(int32_t MessageID, const char * pcBaseDN, int32_t szBaseDN, TSBLDAPScopeRaw Scope, const char * pcFilter, int32_t szFilter, const TStringListHandle Attrs, int8_t AttrsOnly, TElLDAPSearchMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPSEARCHMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPATTRIBUTEVALUE
SB_IMPORT uint32_t SB_APIENTRY TElLDAPAttributeValue_ToString(TElLDAPAttributeValueHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPAttributeValue_get_Value(TElLDAPAttributeValueHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPAttributeValue_set_Value(TElLDAPAttributeValueHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPAttributeValue_Create(const uint8_t pValue[], int32_t szValue, TElLDAPAttributeValueHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPATTRIBUTEVALUE */

#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElLDAPPartialAttribute_Add(TElLDAPPartialAttributeHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPPartialAttribute_Add_1(TElLDAPPartialAttributeHandle _Handle, const TElLDAPAttributeValueHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPPartialAttribute_Save(TElLDAPPartialAttributeHandle _Handle, TElASN1ConstrainedTagHandle * Tag);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPPartialAttribute_get_Operation(TElLDAPPartialAttributeHandle _Handle, TSBLDAPModifyOperationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPPartialAttribute_get_Binary(TElLDAPPartialAttributeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPPartialAttribute_get_Type_(TElLDAPPartialAttributeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPPartialAttribute_get_Count(TElLDAPPartialAttributeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPPartialAttribute_get_Values(TElLDAPPartialAttributeHandle _Handle, int32_t Index, TElLDAPAttributeValueHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPPartialAttribute_Create(const char * pcType_, int32_t szType_, TSBLDAPModifyOperationRaw Operation, TElLDAPPartialAttributeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPPartialAttribute_Create_1(TElASN1ConstrainedTagHandle * Tag, TElLDAPPartialAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */

#ifdef SB_USE_CLASS_TELLDAPSEARCHENTRYMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSearchEntryMessage_get_ObjectName(TElLDAPSearchEntryMessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSearchEntryMessage_get_Count(TElLDAPSearchEntryMessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSearchEntryMessage_get_Attributes(TElLDAPSearchEntryMessageHandle _Handle, int32_t Index, TElLDAPPartialAttributeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSearchEntryMessage_get_ByType(TElLDAPSearchEntryMessageHandle _Handle, const char * pcIndex, int32_t szIndex, TElLDAPPartialAttributeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSearchEntryMessage_Create(void * Buf, int32_t Size, TElLDAPSearchEntryMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPSEARCHENTRYMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPSEARCHREFERENCEMESSAGE
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSearchReferenceMessage_get_URIs(TElLDAPSearchReferenceMessageHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSearchReferenceMessage_get_URIs(TElLDAPSearchReferenceMessageHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElLDAPSearchReferenceMessage_Create(void * Buf, int32_t Size, TElLDAPSearchReferenceMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPSEARCHREFERENCEMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPDELETEMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElLDAPDeleteMessage_Create(int32_t MessageID, const char * pcLDAPDN, int32_t szLDAPDN, TElLDAPDeleteMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPDELETEMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPMODIFYMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElLDAPModifyMessage_Create(int32_t MessageID, const char * pcDN, int32_t szDN, const TElLDAPPartialAttributeHandle pAttributes[], int32_t szAttributes, TElLDAPModifyMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELLDAPMODIFYMESSAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElLDAPMessage;
typedef TElLDAPMessage ElLDAPMessage;
class TElLDAPSimpleBindMessage;
typedef TElLDAPSimpleBindMessage ElLDAPSimpleBindMessage;
class TElLDAPSASLBindMessage;
typedef TElLDAPSASLBindMessage ElLDAPSASLBindMessage;
class TElLDAPUnbindMessage;
typedef TElLDAPUnbindMessage ElLDAPUnbindMessage;
class TElLDAPResult;
typedef TElLDAPResult ElLDAPResult;
class TElLDAPResultMessage;
typedef TElLDAPResultMessage ElLDAPResultMessage;
typedef TElLDAPResultMessage TElLDAPSearchResultDoneMessage;
typedef TElLDAPResultMessage ElLDAPSearchResultDoneMessage;
class TElLDAPBindResponseMessage;
typedef TElLDAPBindResponseMessage ElLDAPBindResponseMessage;
class TElLDAPSearchMessage;
typedef TElLDAPSearchMessage ElLDAPSearchMessage;
class TElLDAPAttributeValue;
typedef TElLDAPAttributeValue ElLDAPAttributeValue;
class TElLDAPPartialAttribute;
typedef TElLDAPPartialAttribute ElLDAPPartialAttribute;
typedef TElLDAPPartialAttribute TElLDAPAttribute;
typedef TElLDAPPartialAttribute ElLDAPAttribute;
class TElLDAPSearchEntryMessage;
typedef TElLDAPSearchEntryMessage ElLDAPSearchEntryMessage;
class TElLDAPSearchReferenceMessage;
typedef TElLDAPSearchReferenceMessage ElLDAPSearchReferenceMessage;
class TElLDAPDeleteMessage;
typedef TElLDAPDeleteMessage ElLDAPDeleteMessage;
typedef TElLDAPResultMessage TElLDAPDeleteResponseMessage;
typedef TElLDAPResultMessage ElLDAPDeleteResponseMessage;
class TElLDAPModifyMessage;
typedef TElLDAPModifyMessage ElLDAPModifyMessage;
typedef TElLDAPModifyMessage TElLDAPAddMessage;
typedef TElLDAPModifyMessage ElLDAPAddMessage;
typedef TElLDAPResultMessage TElLDAPAddResponseMessage;
typedef TElLDAPResultMessage ElLDAPAddResponseMessage;
typedef TElLDAPResultMessage TElLDAPModifyResponseMessage;
typedef TElLDAPResultMessage ElLDAPModifyResponseMessage;

#ifdef SB_USE_CLASS_TELLDAPMESSAGE
class TElLDAPMessage: public TObject
{
	private:
		SB_DISABLE_COPY(TElLDAPMessage)
	public:
		void SaveToBuffer(void * Buf, int32_t &Size);

		virtual int32_t get_Code();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Code, TElLDAPMessage, Code);

		virtual int32_t get_ID();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ID, TElLDAPMessage, ID);

		TElLDAPMessage(TElLDAPMessageHandle handle, TElOwnHandle ownHandle);

		TElLDAPMessage();

		TElLDAPMessage(int32_t MessageID, int32_t Code);

};
#endif /* SB_USE_CLASS_TELLDAPMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPSIMPLEBINDMESSAGE
class TElLDAPSimpleBindMessage: public TElLDAPMessage
{
	private:
		SB_DISABLE_COPY(TElLDAPSimpleBindMessage)
	public:
		TElLDAPSimpleBindMessage(TElLDAPSimpleBindMessageHandle handle, TElOwnHandle ownHandle);

		TElLDAPSimpleBindMessage(int32_t MessageID, const std::string &LDAPDN, const std::string &Password);

};
#endif /* SB_USE_CLASS_TELLDAPSIMPLEBINDMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPSASLBINDMESSAGE
class TElLDAPSASLBindMessage: public TElLDAPMessage
{
	private:
		SB_DISABLE_COPY(TElLDAPSASLBindMessage)
	public:
		TElLDAPSASLBindMessage(TElLDAPSASLBindMessageHandle handle, TElOwnHandle ownHandle);

		TElLDAPSASLBindMessage(int32_t MessageID, const std::string &LDAPDN, const std::string &Password, const std::string &Mechanism, const std::vector<uint8_t> &Credentials, int32_t CredLen);

};
#endif /* SB_USE_CLASS_TELLDAPSASLBINDMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPUNBINDMESSAGE
class TElLDAPUnbindMessage: public TElLDAPMessage
{
	private:
		SB_DISABLE_COPY(TElLDAPUnbindMessage)
	public:
		TElLDAPUnbindMessage(TElLDAPUnbindMessageHandle handle, TElOwnHandle ownHandle);

		explicit TElLDAPUnbindMessage(int32_t MessageID);

};
#endif /* SB_USE_CLASS_TELLDAPUNBINDMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPRESULT
class TElLDAPResult: public TObject
{
	private:
		SB_DISABLE_COPY(TElLDAPResult)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Referal;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Referal;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		virtual int32_t get_ResultCode();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ResultCode, TElLDAPResult, ResultCode);

		virtual void get_MatchedDN(std::string &OutResult);

		virtual void get_DiagnosticMessage(std::string &OutResult);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Referal();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Referal, TElLDAPResult, Referal);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Referal();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Referal, TElLDAPResult, Referal);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual bool get_HasReferal();

		SB_DECLARE_PROPERTY_GET(bool, get_HasReferal, TElLDAPResult, HasReferal);

		virtual bool get_Success();

		SB_DECLARE_PROPERTY_GET(bool, get_Success, TElLDAPResult, Success);

		TElLDAPResult(TElLDAPResultHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
		explicit TElLDAPResult(TElASN1ConstrainedTag &Tag);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

		virtual ~TElLDAPResult();

};
#endif /* SB_USE_CLASS_TELLDAPRESULT */

#ifdef SB_USE_CLASS_TELLDAPRESULTMESSAGE
class TElLDAPResultMessage: public TElLDAPMessage
{
	private:
		SB_DISABLE_COPY(TElLDAPResultMessage)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Referal;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Referal;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		virtual int32_t get_ResultCode();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ResultCode, TElLDAPResultMessage, ResultCode);

		virtual void get_MatchedDN(std::string &OutResult);

		virtual void get_DiagnosticMessage(std::string &OutResult);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Referal();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Referal, TElLDAPResultMessage, Referal);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Referal();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Referal, TElLDAPResultMessage, Referal);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual bool get_HasReferal();

		SB_DECLARE_PROPERTY_GET(bool, get_HasReferal, TElLDAPResultMessage, HasReferal);

		virtual bool get_Success();

		SB_DECLARE_PROPERTY_GET(bool, get_Success, TElLDAPResultMessage, Success);

		TElLDAPResultMessage(TElLDAPResultMessageHandle handle, TElOwnHandle ownHandle);

		TElLDAPResultMessage(void * Buf, int32_t Size);

		virtual ~TElLDAPResultMessage();

};
#endif /* SB_USE_CLASS_TELLDAPRESULTMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPBINDRESPONSEMESSAGE
class TElLDAPBindResponseMessage: public TElLDAPMessage
{
	private:
		SB_DISABLE_COPY(TElLDAPBindResponseMessage)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Referal;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Referal;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		virtual int32_t get_ResultCode();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ResultCode, TElLDAPBindResponseMessage, ResultCode);

		virtual void get_MatchedDN(std::string &OutResult);

		virtual void get_DiagnosticMessage(std::string &OutResult);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Referal();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Referal, TElLDAPBindResponseMessage, Referal);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Referal();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Referal, TElLDAPBindResponseMessage, Referal);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual bool get_HasReferal();

		SB_DECLARE_PROPERTY_GET(bool, get_HasReferal, TElLDAPBindResponseMessage, HasReferal);

		virtual bool get_Success();

		SB_DECLARE_PROPERTY_GET(bool, get_Success, TElLDAPBindResponseMessage, Success);

		virtual void get_ServerSaslCreds(std::string &OutResult);

		TElLDAPBindResponseMessage(TElLDAPBindResponseMessageHandle handle, TElOwnHandle ownHandle);

		TElLDAPBindResponseMessage(void * Buf, int32_t Size);

		virtual ~TElLDAPBindResponseMessage();

};
#endif /* SB_USE_CLASS_TELLDAPBINDRESPONSEMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPSEARCHMESSAGE
class TElLDAPSearchMessage: public TElLDAPMessage
{
	private:
		SB_DISABLE_COPY(TElLDAPSearchMessage)
	public:
		TElLDAPSearchMessage(TElLDAPSearchMessageHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TSTRINGLIST
		TElLDAPSearchMessage(int32_t MessageID, const std::string &BaseDN, TSBLDAPScope Scope, const std::string &Filter, const TStringList &Attrs, bool AttrsOnly);
#endif /* SB_USE_CLASS_TSTRINGLIST */

};
#endif /* SB_USE_CLASS_TELLDAPSEARCHMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPATTRIBUTEVALUE
class TElLDAPAttributeValue: public TObject
{
	private:
		SB_DISABLE_COPY(TElLDAPAttributeValue)
	public:
		void ToString(std::string &OutResult);

		virtual void get_Value(std::vector<uint8_t> &OutResult);

		virtual void set_Value(const std::vector<uint8_t> &Value);

		TElLDAPAttributeValue(TElLDAPAttributeValueHandle handle, TElOwnHandle ownHandle);

		explicit TElLDAPAttributeValue(const std::vector<uint8_t> &Value);

};
#endif /* SB_USE_CLASS_TELLDAPATTRIBUTEVALUE */

#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
class TElLDAPPartialAttribute: public TObject
{
	private:
		SB_DISABLE_COPY(TElLDAPPartialAttribute)
#ifdef SB_USE_CLASS_TELLDAPATTRIBUTEVALUE
		TElLDAPAttributeValue* _Inst_Values;
#endif /* SB_USE_CLASS_TELLDAPATTRIBUTEVALUE */

		void initInstances();

	public:
		void Add(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELLDAPATTRIBUTEVALUE
		void Add(const TElLDAPAttributeValue &Value);

		void Add(const TElLDAPAttributeValue *Value);
#endif /* SB_USE_CLASS_TELLDAPATTRIBUTEVALUE */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
		void Save(TElASN1ConstrainedTag &Tag);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

		virtual TSBLDAPModifyOperation get_Operation();

		SB_DECLARE_PROPERTY_GET(TSBLDAPModifyOperation, get_Operation, TElLDAPPartialAttribute, Operation);

		virtual bool get_Binary();

		SB_DECLARE_PROPERTY_GET(bool, get_Binary, TElLDAPPartialAttribute, Binary);

		virtual void get_Type_(std::string &OutResult);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElLDAPPartialAttribute, Count);

#ifdef SB_USE_CLASS_TELLDAPATTRIBUTEVALUE
		virtual TElLDAPAttributeValue* get_Values(int32_t Index);
#endif /* SB_USE_CLASS_TELLDAPATTRIBUTEVALUE */

		TElLDAPPartialAttribute(TElLDAPPartialAttributeHandle handle, TElOwnHandle ownHandle);

		TElLDAPPartialAttribute(const std::string &Type_, TSBLDAPModifyOperation Operation);

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
		explicit TElLDAPPartialAttribute(TElASN1ConstrainedTag &Tag);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

		virtual ~TElLDAPPartialAttribute();

};
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */

#ifdef SB_USE_CLASS_TELLDAPSEARCHENTRYMESSAGE
class TElLDAPSearchEntryMessage: public TElLDAPMessage
{
	private:
		SB_DISABLE_COPY(TElLDAPSearchEntryMessage)
#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
		TElLDAPPartialAttribute* _Inst_Attributes;
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */
#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
		TElLDAPPartialAttribute* _Inst_ByType;
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */

		void initInstances();

	public:
		virtual void get_ObjectName(std::string &OutResult);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElLDAPSearchEntryMessage, Count);

#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
		virtual TElLDAPPartialAttribute* get_Attributes(int32_t Index);
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */

#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
		virtual TElLDAPPartialAttribute* get_ByType(const std::string &Index);
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */

		TElLDAPSearchEntryMessage(TElLDAPSearchEntryMessageHandle handle, TElOwnHandle ownHandle);

		TElLDAPSearchEntryMessage(void * Buf, int32_t Size);

		virtual ~TElLDAPSearchEntryMessage();

};
#endif /* SB_USE_CLASS_TELLDAPSEARCHENTRYMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPSEARCHREFERENCEMESSAGE
class TElLDAPSearchReferenceMessage: public TElLDAPMessage
{
	private:
		SB_DISABLE_COPY(TElLDAPSearchReferenceMessage)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_URIs;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_URIs;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_URIs();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_URIs, TElLDAPSearchReferenceMessage, URIs);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_URIs();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_URIs, TElLDAPSearchReferenceMessage, URIs);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		TElLDAPSearchReferenceMessage(TElLDAPSearchReferenceMessageHandle handle, TElOwnHandle ownHandle);

		TElLDAPSearchReferenceMessage(void * Buf, int32_t Size);

		virtual ~TElLDAPSearchReferenceMessage();

};
#endif /* SB_USE_CLASS_TELLDAPSEARCHREFERENCEMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPDELETEMESSAGE
class TElLDAPDeleteMessage: public TElLDAPMessage
{
	private:
		SB_DISABLE_COPY(TElLDAPDeleteMessage)
	public:
		TElLDAPDeleteMessage(TElLDAPDeleteMessageHandle handle, TElOwnHandle ownHandle);

		TElLDAPDeleteMessage(int32_t MessageID, const std::string &LDAPDN);

};
#endif /* SB_USE_CLASS_TELLDAPDELETEMESSAGE */

#ifdef SB_USE_CLASS_TELLDAPMODIFYMESSAGE
class TElLDAPModifyMessage: public TElLDAPMessage
{
	private:
		SB_DISABLE_COPY(TElLDAPModifyMessage)
	public:
		TElLDAPModifyMessage(TElLDAPModifyMessageHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
		TElLDAPModifyMessage(int32_t MessageID, const std::string &DN, const std::vector<TElLDAPPartialAttributeHandle> &Attributes);
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */

};
#endif /* SB_USE_CLASS_TELLDAPMODIFYMESSAGE */

#ifdef SB_USE_GLOBAL_PROCS_LDAPSCORE

#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
TElLDAPPartialAttributeHandle AttrFromString(const std::string &Type_, const std::string &Value, TSBLDAPModifyOperation Operation);
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */

#ifdef SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE
TElLDAPPartialAttributeHandle AttrFromBuffer(const std::string &Type_, const std::vector<uint8_t> &Value, TSBLDAPModifyOperation Operation);
#endif /* SB_USE_CLASS_TELLDAPPARTIALATTRIBUTE */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
void PutSimpleFilter(TElASN1ConstrainedTag &Tag, const std::string &s);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
void PutSubstringFilter(TElASN1ConstrainedTag &Tag, int32_t TagId, const std::string &Type_, const std::string &Value);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
void SplitValue(TStringList &List, const std::string &s);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
void SplitValue(TElStringList &List, const std::string &s);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
void PutFilterList(TElASN1ConstrainedTag &Tag, const std::string &s);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

bool IsDigit(char c);

bool IsHexLower(char c);

bool IsHexUpper(char c);

bool IsHex(char c);

bool IsLower(char c);

bool IsUpper(char c);

bool IsAlpha(char c);

bool IsAlnum(char c);

bool IsLdh(char c);

bool IsSpace(char c);

int32_t Hex2Value(char c);

int32_t GetMessageLenSize(std::vector<uint8_t> &Buf, int32_t Size);

int32_t GetMessageLen(std::vector<uint8_t> &Buf, int32_t Size);

int32_t GetMessageType(std::vector<uint8_t> &Buf, int32_t Size);

#endif /* SB_USE_GLOBAL_PROCS_LDAPSCORE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_LDAPSCORE
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_AttrFromString(const char * pcType_, int32_t szType_, const char * pcValue, int32_t szValue, TSBLDAPModifyOperationRaw Operation, TElLDAPPartialAttributeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_AttrFromBuffer(const char * pcType_, int32_t szType_, const uint8_t pValue[], int32_t szValue, TSBLDAPModifyOperationRaw Operation, TElLDAPPartialAttributeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_PutSimpleFilter(TElASN1ConstrainedTagHandle * Tag, const char * pcs, int32_t szs);
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_PutSubstringFilter(TElASN1ConstrainedTagHandle * Tag, int32_t TagId, const char * pcType_, int32_t szType_, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_SplitValue(TStringListHandle * List, const char * pcs, int32_t szs);
#else
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_SplitValue(TElStringListHandle * List, const char * pcs, int32_t szs);
#endif
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_PutFilterList(TElASN1ConstrainedTagHandle * Tag, const char * pcs, int32_t szs);
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_IsDigit(char c, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_IsHexLower(char c, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_IsHexUpper(char c, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_IsHex(char c, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_IsLower(char c, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_IsUpper(char c, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_IsAlpha(char c, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_IsAlnum(char c, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_IsLdh(char c, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_IsSpace(char c, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_Hex2Value(char c, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_GetMessageLenSize(uint8_t pBuf[], int32_t * szBuf, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_GetMessageLen(uint8_t pBuf[], int32_t * szBuf, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBLDAPSCore_GetMessageType(uint8_t pBuf[], int32_t * szBuf, int32_t Size, int32_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_LDAPSCORE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBLDAPSCORE */
