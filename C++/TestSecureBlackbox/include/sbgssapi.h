#ifndef __INC_SBGSSAPI
#define __INC_SBGSSAPI

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbgssapibase.h"
#include "sbmd.h"
#include "sbtypes.h"
#include "sbstrutils.h"
#include "sbutils.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_GSS_C_NO_NAME 	0
#define SB_GSS_C_NO_BUFFER 	0
#define SB_GSS_C_NO_OID 	0
#define SB_GSS_C_NO_OID_SET 	0
#define SB_GSS_C_NO_CONTEXT 	0
#define SB_GSS_C_NO_CREDENTIAL 	0
#define SB_GSS_C_NO_CHANNEL_BINDINGS 	0
#define SB_GSS_C_NULL_OID 	0
#define SB_GSS_C_NULL_OID_SET 	0
#define SB_GSS_C_NT_HOSTBASED_SERVICE_OID 	"+\x06""\x01""\x05""\x06""\x02"
#define SB_GSS_KRB5_NT_PRINCIPAL_NAME_OID 	"*\x86""H\x86""\xF7""\x12""\x01""\x02""\x02""\x01"

typedef TElClassHandle TElGSSCustomContextHandle;

typedef TElClassHandle TElGSSCustomNameHandle;

typedef TElClassHandle TElGSSBaseMechanismHandle;

typedef TElClassHandle TElGSSAPIContextHandle;

typedef TElClassHandle TElGSSAPINameHandle;

typedef TElClassHandle TElGSSAPIMechanismHandle;

typedef TElClassHandle TElGSSMechanismCollectionHandle;

typedef Pointer gss_ctx_id_t;

typedef Pointer gss_cred_id_t;

typedef Pointer gss_name_t;

#pragma pack(4)
typedef struct 
{
	uint32_t length;
	void * elements;
} gss_OID_desc, * gss_OID;

#pragma pack(4)
typedef struct 
{
	uint32_t count;
	gss_OID elements;
} gss_OID_set_desc, * gss_OID_set;

#pragma pack(4)
typedef struct 
{
	uint32_t length;
	void * value;
} gss_buffer_desc, * gss_buffer_t;

#pragma pack(4)
typedef struct 
{
	uint32_t initiator_addrtype;
	gss_buffer_desc initiator_address;
	uint32_t acceptor_addrtype;
	gss_buffer_desc acceptor_address;
	gss_buffer_desc application_data;
} gss_channel_bindings_desc_t, * gss_channel_bindings_t;

typedef void (SB_CALLBACK *gss_acquire_cred)(uint32_t * minor_status, const void * desired_name, uint32_t time_req, const gss_OID_set desired_mechs, int32_t cred_usage, void * (* output_cred_handle), gss_OID_set (* actual_mechs), uint32_t * time_rec, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_release_cred)(uint32_t * minor_status, void * (* cred_handle), uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_init_sec_context)(uint32_t * minor_status, const void * initiator_cred_handle, void * (* context_handle), const void * target_name, const gss_OID mech_type, uint32_t req_flags, uint32_t time_req, gss_channel_bindings_t input_chan_bindings, const gss_buffer_t input_token, gss_OID (* actual_mech_type), gss_buffer_t output_token, uint32_t * ret_flags, uint32_t * time_rec, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_accept_sec_context)(uint32_t * minor_status, void * (* context_handle), const void * acceptor_cred_handle, const gss_buffer_t input_token_buffer, const gss_channel_bindings_t input_chan_bindings, void * (* src_name), gss_OID (* mech_type), gss_buffer_t output_token, uint32_t * ret_flags, uint32_t * time_rec, void * (* delegated_cred_handle), uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_process_context_token)(uint32_t * minor_status, const void * context_handle, const gss_buffer_t token_buffer, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_delete_sec_context)(uint32_t * minor_status, void * (* context_handle), gss_buffer_t output_token, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_context_time)(uint32_t * minor_status, const void * context_handle, uint32_t * time_rec, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_get_mic)(uint32_t * minor_status, const void * context_handle, uint32_t qop_req, const gss_buffer_t message_buffer, gss_buffer_t message_token, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_verify_mic)(uint32_t * minor_status, const void * context_handle, const gss_buffer_t message_buffer, const gss_buffer_t token_buffer, uint32_t * qop_state, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_wrap)(uint32_t * minor_status, const void * context_handle, int32_t conf_req_flag, uint32_t qop_req, const gss_buffer_t input_message_buffer, int32_t * conf_state, gss_buffer_t output_message_buffer, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_unwrap)(uint32_t * minor_status, const void * context_handle, const gss_buffer_t input_message_buffer, gss_buffer_t output_message_buffer, int32_t * conf_state, uint32_t * qop_state, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_display_status)(uint32_t * minor_status, uint32_t status_value, int32_t status_type, const gss_OID mech_type, uint32_t * message_context, gss_buffer_t status_string, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_indicate_mechs)(uint32_t * minor_status, gss_OID_set (* mech_set), uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_compare_name)(uint32_t * minor_status, const void * name1, const void * name2, int32_t * name_equal, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_display_name)(uint32_t * minor_status, const void * input_name, gss_buffer_t output_name_buffer, gss_OID (* output_name_type), uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_import_name)(uint32_t * minor_status, const gss_buffer_t input_name_buffer, const gss_OID input_name_type, void * (* output_name), uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_export_name)(uint32_t * minor_status, const void * input_name, gss_buffer_t exported_name, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_release_name)(uint32_t * minor_status, void * (* input_name), uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_release_buffer)(uint32_t * minor_status, gss_buffer_t buffer, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_release_oid_set)(uint32_t * minor_status, gss_OID_set (* oid_set), uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_inquire_cred)(uint32_t * minor_status, const void * cred_handle, void * (* name), uint32_t * lifetime, int32_t * cred_usage, gss_OID_set (* mechanisms), uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_inquire_context)(uint32_t * minor_status, const void * context_handle, void * (* src_name), void * (* targ_name), uint32_t * lifetime_rec, gss_OID (* mech_type), uint32_t * ctx_flags, int32_t * locally_initiated, int32_t * open, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_wrap_size_limit)(uint32_t * minor_status, const void * context_handle, int32_t conf_req_flag, uint32_t qop_req, uint32_t req_output_size, uint32_t * max_input_size, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_add_cred)(uint32_t * minor_status, const void * input_cred_handle, const void * desired_name, const gss_OID desired_mech, int32_t cred_usage, uint32_t initiator_time_req, uint32_t acceptor_time_req, void * (* output_cred_handle), gss_OID_set (* actual_mechs), uint32_t * initiator_time_rec, uint32_t * acceptor_time_rec, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_store_cred)(uint32_t * minor_status, const void * input_cred, int32_t cred_usage, const gss_OID desired_mech, uint32_t overwrite_cred, uint32_t default_cred, gss_OID_set (* elements_stored), int32_t * cred_usage_stored, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_inquire_cred_by_mech)(uint32_t * minor_status, const void * cred_handle, const gss_OID mech_type, void * (* name), uint32_t * initiator_lifetime, uint32_t * acceptor_lifetime, int32_t * cred_usage, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_export_sec_context)(uint32_t * minor_status, void * (* context_handle), gss_buffer_t interprocess_token, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_import_sec_context)(uint32_t * minor_status, const gss_buffer_t interprocess_token, void * (* context_handle), uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_create_empty_oid_set)(uint32_t * minor_status, gss_OID_set (* oid_set), uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_add_oid_set_member)(uint32_t * minor_status, const gss_OID member_oid, gss_OID_set (* oid_set), uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_test_oid_set_member)(uint32_t * minor_status, const gss_OID member, const gss_OID_set oid_set, int32_t * present, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_inquire_names_for_mech)(uint32_t * minor_status, const gss_OID mechanism, gss_OID_set (* name_types), uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_inquire_mechs_for_name)(uint32_t * minor_status, const void * input_name, gss_OID_set (* mech_types), uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_canonicalize_name)(uint32_t * minor_status, const void * input_name, const gss_OID mech_type, void * (* output_name), uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_duplicate_name)(uint32_t * minor_status, const void * src_name, void * (* dest_name), uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_release_oid)(uint32_t * minor_status, gss_OID (* oid), uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_str_to_oid)(uint32_t * minor_status, const gss_buffer_t oid_str, gss_OID (* oid), uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_oid_to_str)(uint32_t * minor_status, const gss_OID oid, gss_buffer_t oid_str, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_sign)(uint32_t * minor_status, void * context_handle, int32_t qop_req, gss_buffer_t message_buffer, gss_buffer_t message_token, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_verify)(uint32_t * minor_status, void * context_handle, gss_buffer_t message_buffer, gss_buffer_t token_buffer, int32_t * qop_state, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_seal)(uint32_t * minor_status, void * context_handle, int32_t conf_req_flag, int32_t qop_req, gss_buffer_t input_message_buffer, int32_t * conf_state, gss_buffer_t output_message_buffer, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_unseal)(uint32_t * minor_status, void * context_handle, gss_buffer_t input_message_buffer, gss_buffer_t output_message_buffer, int32_t * conf_state, int32_t * qop_state, uint32_t * OutResult);

typedef void (SB_CALLBACK *gss_krb5_ccache_name)(uint32_t * minor_status, const void * name, const void * out_name, uint32_t * OutResult);

typedef void (SB_CALLBACK *TSBGSSErrorEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcOperation, int32_t szOperation, uint32_t MajorStatus, uint32_t MinorStatus, const char * pcMajorErrorMsg, int32_t szMajorErrorMsg, const char * pcMinorErrorMsg, int32_t szMinorErrorMsg);

typedef gss_OID (* p_gss_OID);

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
SB_IMPORT uint32_t SB_APIENTRY TElGSSCustomContext_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMNAME
SB_IMPORT uint32_t SB_APIENTRY TElGSSCustomName_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
SB_IMPORT uint32_t SB_APIENTRY TElGSSBaseMechanism_Initialize(TElGSSBaseMechanismHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSBaseMechanism_GetLastMajorStatus(TElGSSBaseMechanismHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSBaseMechanism_GetLastMinorStatus(TElGSSBaseMechanismHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSBaseMechanism_AcquireCred(TElGSSBaseMechanismHandle _Handle, const uint8_t pMechOID[], int32_t szMechOID, TElGSSCustomContextHandle * Ctx, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSBaseMechanism_AcceptSecContext(TElGSSBaseMechanismHandle _Handle, TElGSSCustomContextHandle Ctx, TElGSSCustomNameHandle SourceName, const uint8_t pInputToken[], int32_t szInputToken, uint8_t pOutputToken[], int32_t * szOutputToken, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSBaseMechanism_InitSecContext(TElGSSBaseMechanismHandle _Handle, TElGSSCustomContextHandle Ctx, TElGSSCustomNameHandle TargetName, int8_t DelegateCred, const uint8_t pInputToken[], int32_t szInputToken, uint8_t pOutputToken[], int32_t * szOutputToken, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSBaseMechanism_ReleaseContext(TElGSSBaseMechanismHandle _Handle, TElGSSCustomContextHandle * Ctx, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSBaseMechanism_ImportName(TElGSSBaseMechanismHandle _Handle, const uint8_t pMechOID[], int32_t szMechOID, const char * pcInputName, int32_t szInputName, TElGSSCustomNameHandle * OutputName, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSBaseMechanism_ReleaseName(TElGSSBaseMechanismHandle _Handle, TElGSSCustomNameHandle * Name, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSBaseMechanism_GetMIC(TElGSSBaseMechanismHandle _Handle, TElGSSCustomContextHandle Ctx, const uint8_t pMessageBuffer[], int32_t szMessageBuffer, uint8_t pMessageToken[], int32_t * szMessageToken, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSBaseMechanism_VerifyMIC(TElGSSBaseMechanismHandle _Handle, TElGSSCustomContextHandle Ctx, const uint8_t pMessageBuffer[], int32_t szMessageBuffer, const uint8_t pMessageToken[], int32_t szMessageToken, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSBaseMechanism_IsMechSupported(TElGSSBaseMechanismHandle _Handle, const uint8_t pOID[], int32_t szOID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSBaseMechanism_IsIntegrityAvailable(TElGSSBaseMechanismHandle _Handle, TElGSSCustomContextHandle Ctx, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSBaseMechanism_IsMutualAvailable(TElGSSBaseMechanismHandle _Handle, TElGSSCustomContextHandle Ctx, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSBaseMechanism_GetMechOIDByHash(TElGSSBaseMechanismHandle _Handle, const uint8_t pHash[], int32_t szHash, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSBaseMechanism_get_Count(TElGSSBaseMechanismHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSBaseMechanism_get_Mechs(TElGSSBaseMechanismHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSBaseMechanism_get_OnError(TElGSSBaseMechanismHandle _Handle, TSBGSSErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSBaseMechanism_set_OnError(TElGSSBaseMechanismHandle _Handle, TSBGSSErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElGSSBaseMechanism_Create(TElGSSBaseMechanismHandle * OutResult);
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */

#ifdef SB_USE_CLASS_TELGSSAPICONTEXT
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIContext_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELGSSAPICONTEXT */

#ifdef SB_USE_CLASS_TELGSSAPINAME
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIName_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELGSSAPINAME */

#ifdef SB_USE_CLASS_TELGSSAPIMECHANISM
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_Initialize(TElGSSAPIMechanismHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_AcquireCred(TElGSSAPIMechanismHandle _Handle, const uint8_t pMechOID[], int32_t szMechOID, TElGSSCustomContextHandle * Ctx, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_AcceptSecContext(TElGSSAPIMechanismHandle _Handle, TElGSSCustomContextHandle Ctx, TElGSSCustomNameHandle SourceName, const uint8_t pInputToken[], int32_t szInputToken, uint8_t pOutputToken[], int32_t * szOutputToken, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_InitSecContext(TElGSSAPIMechanismHandle _Handle, TElGSSCustomContextHandle Ctx, TElGSSCustomNameHandle TargetName, int8_t DelegateCred, const uint8_t pInputToken[], int32_t szInputToken, uint8_t pOutputToken[], int32_t * szOutputToken, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_ReleaseContext(TElGSSAPIMechanismHandle _Handle, TElGSSCustomContextHandle * Ctx, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_ImportName(TElGSSAPIMechanismHandle _Handle, const uint8_t pMechOID[], int32_t szMechOID, const char * pcInputName, int32_t szInputName, TElGSSCustomNameHandle * OutputName, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_ReleaseName(TElGSSAPIMechanismHandle _Handle, TElGSSCustomNameHandle * Name, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_GetMIC(TElGSSAPIMechanismHandle _Handle, TElGSSCustomContextHandle Ctx, const uint8_t pMessageBuffer[], int32_t szMessageBuffer, uint8_t pMessageToken[], int32_t * szMessageToken, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_VerifyMIC(TElGSSAPIMechanismHandle _Handle, TElGSSCustomContextHandle Ctx, const uint8_t pMessageBuffer[], int32_t szMessageBuffer, const uint8_t pMessageToken[], int32_t szMessageToken, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_get_LibraryName(TElGSSAPIMechanismHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_set_LibraryName(TElGSSAPIMechanismHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_get_KRB5CredentialCacheName(TElGSSAPIMechanismHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_set_KRB5CredentialCacheName(TElGSSAPIMechanismHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_get_RequestFlags(TElGSSAPIMechanismHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_set_RequestFlags(TElGSSAPIMechanismHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_get_accept_sec_context(TElGSSAPIMechanismHandle _Handle, gss_accept_sec_context * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_set_accept_sec_context(TElGSSAPIMechanismHandle _Handle, gss_accept_sec_context Value);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_get_acquire_cred(TElGSSAPIMechanismHandle _Handle, gss_acquire_cred * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_set_acquire_cred(TElGSSAPIMechanismHandle _Handle, gss_acquire_cred Value);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_get_delete_sec_context(TElGSSAPIMechanismHandle _Handle, gss_delete_sec_context * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_set_delete_sec_context(TElGSSAPIMechanismHandle _Handle, gss_delete_sec_context Value);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_get_display_status(TElGSSAPIMechanismHandle _Handle, gss_display_status * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_set_display_status(TElGSSAPIMechanismHandle _Handle, gss_display_status Value);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_get_get_mic(TElGSSAPIMechanismHandle _Handle, gss_get_mic * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_set_get_mic(TElGSSAPIMechanismHandle _Handle, gss_get_mic Value);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_get_indicate_mechs(TElGSSAPIMechanismHandle _Handle, gss_indicate_mechs * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_set_indicate_mechs(TElGSSAPIMechanismHandle _Handle, gss_indicate_mechs Value);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_get_init_sec_context(TElGSSAPIMechanismHandle _Handle, gss_init_sec_context * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_set_init_sec_context(TElGSSAPIMechanismHandle _Handle, gss_init_sec_context Value);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_get_import_name(TElGSSAPIMechanismHandle _Handle, gss_import_name * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_set_import_name(TElGSSAPIMechanismHandle _Handle, gss_import_name Value);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_get_krb5_ccache_name(TElGSSAPIMechanismHandle _Handle, gss_krb5_ccache_name * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_set_krb5_ccache_name(TElGSSAPIMechanismHandle _Handle, gss_krb5_ccache_name Value);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_get_release_buffer(TElGSSAPIMechanismHandle _Handle, gss_release_buffer * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_set_release_buffer(TElGSSAPIMechanismHandle _Handle, gss_release_buffer Value);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_get_release_cred(TElGSSAPIMechanismHandle _Handle, gss_release_cred * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_set_release_cred(TElGSSAPIMechanismHandle _Handle, gss_release_cred Value);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_get_release_name(TElGSSAPIMechanismHandle _Handle, gss_release_name * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_set_release_name(TElGSSAPIMechanismHandle _Handle, gss_release_name Value);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_get_release_oid_set(TElGSSAPIMechanismHandle _Handle, gss_release_oid_set * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_set_release_oid_set(TElGSSAPIMechanismHandle _Handle, gss_release_oid_set Value);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_get_verify_mic(TElGSSAPIMechanismHandle _Handle, gss_verify_mic * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_set_verify_mic(TElGSSAPIMechanismHandle _Handle, gss_verify_mic Value);
SB_IMPORT uint32_t SB_APIENTRY TElGSSAPIMechanism_Create(TElGSSAPIMechanismHandle * OutResult);
#endif /* SB_USE_CLASS_TELGSSAPIMECHANISM */

#ifdef SB_USE_CLASS_TELGSSMECHANISMCOLLECTION
SB_IMPORT uint32_t SB_APIENTRY TElGSSMechanismCollection_Initialize(TElGSSMechanismCollectionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSMechanismCollection_GetMechByOID(TElGSSMechanismCollectionHandle _Handle, const uint8_t pOID[], int32_t szOID, TElGSSBaseMechanismHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSMechanismCollection_RegisterMechanism(TElGSSMechanismCollectionHandle _Handle, TElGSSBaseMechanismHandle Mech);
SB_IMPORT uint32_t SB_APIENTRY TElGSSMechanismCollection_UnregisterMechanism(TElGSSMechanismCollectionHandle _Handle, TElGSSBaseMechanismHandle Mech);
SB_IMPORT uint32_t SB_APIENTRY TElGSSMechanismCollection_AcquireCred(TElGSSMechanismCollectionHandle _Handle, const uint8_t pMechOID[], int32_t szMechOID, TElGSSCustomContextHandle * Ctx, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSMechanismCollection_AcceptSecContext(TElGSSMechanismCollectionHandle _Handle, TElGSSCustomContextHandle Ctx, TElGSSCustomNameHandle SourceName, const uint8_t pInputToken[], int32_t szInputToken, uint8_t pOutputToken[], int32_t * szOutputToken, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSMechanismCollection_InitSecContext(TElGSSMechanismCollectionHandle _Handle, TElGSSCustomContextHandle Ctx, TElGSSCustomNameHandle TargetName, int8_t DelegateCred, const uint8_t pInputToken[], int32_t szInputToken, uint8_t pOutputToken[], int32_t * szOutputToken, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSMechanismCollection_ReleaseContext(TElGSSMechanismCollectionHandle _Handle, TElGSSCustomContextHandle * Ctx, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSMechanismCollection_ImportName(TElGSSMechanismCollectionHandle _Handle, const uint8_t pMechOID[], int32_t szMechOID, const char * pcInputName, int32_t szInputName, TElGSSCustomNameHandle * OutputName, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSMechanismCollection_ReleaseName(TElGSSMechanismCollectionHandle _Handle, TElGSSCustomNameHandle * Name, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSMechanismCollection_GetMIC(TElGSSMechanismCollectionHandle _Handle, TElGSSCustomContextHandle Ctx, const uint8_t pMessageBuffer[], int32_t szMessageBuffer, uint8_t pMessageToken[], int32_t * szMessageToken, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSMechanismCollection_VerifyMIC(TElGSSMechanismCollectionHandle _Handle, TElGSSCustomContextHandle Ctx, const uint8_t pMessageBuffer[], int32_t szMessageBuffer, const uint8_t pMessageToken[], int32_t szMessageToken, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSMechanismCollection_IsMechSupported(TElGSSMechanismCollectionHandle _Handle, const uint8_t pOID[], int32_t szOID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSMechanismCollection_IsIntegrityAvailable(TElGSSMechanismCollectionHandle _Handle, TElGSSCustomContextHandle Ctx, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGSSMechanismCollection_Create(TElGSSMechanismCollectionHandle * OutResult);
#endif /* SB_USE_CLASS_TELGSSMECHANISMCOLLECTION */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElGSSCustomContext;
class TElGSSCustomName;
class TElGSSBaseMechanism;
class TElGSSAPIContext;
class TElGSSAPIName;
class TElGSSAPIMechanism;
class TElGSSMechanismCollection;

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
class TElGSSCustomContext: public TObject
{
	private:
		SB_DISABLE_COPY(TElGSSCustomContext)
	public:
		TElGSSCustomContext(TElGSSCustomContextHandle handle, TElOwnHandle ownHandle);

		TElGSSCustomContext();

};
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMNAME
class TElGSSCustomName: public TObject
{
	private:
		SB_DISABLE_COPY(TElGSSCustomName)
	public:
		TElGSSCustomName(TElGSSCustomNameHandle handle, TElOwnHandle ownHandle);

		TElGSSCustomName();

};
#endif /* SB_USE_CLASS_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
class TElGSSBaseMechanism: public TObject
{
	private:
		SB_DISABLE_COPY(TElGSSBaseMechanism)
	public:
		virtual bool Initialize();

		uint32_t GetLastMajorStatus();

		uint32_t GetLastMinorStatus();

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
		virtual uint32_t AcquireCred(const std::vector<uint8_t> &MechOID, TElGSSCustomContext &Ctx);
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME
		virtual uint32_t AcceptSecContext(TElGSSCustomContext &Ctx, TElGSSCustomName &SourceName, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken);

		virtual uint32_t AcceptSecContext(TElGSSCustomContext *Ctx, TElGSSCustomName *SourceName, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken);
#endif /* SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME
		virtual uint32_t InitSecContext(TElGSSCustomContext &Ctx, TElGSSCustomName &TargetName, bool DelegateCred, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken);

		virtual uint32_t InitSecContext(TElGSSCustomContext *Ctx, TElGSSCustomName *TargetName, bool DelegateCred, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken);
#endif /* SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
		virtual uint32_t ReleaseContext(TElGSSCustomContext &Ctx);
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMNAME
		virtual uint32_t ImportName(const std::vector<uint8_t> &MechOID, const std::string &InputName, TElGSSCustomName &OutputName);
#endif /* SB_USE_CLASS_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMNAME
		virtual uint32_t ReleaseName(TElGSSCustomName &Name);
#endif /* SB_USE_CLASS_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
		virtual uint32_t GetMIC(TElGSSCustomContext &Ctx, const std::vector<uint8_t> &MessageBuffer, std::vector<uint8_t> &MessageToken);

		virtual uint32_t GetMIC(TElGSSCustomContext *Ctx, const std::vector<uint8_t> &MessageBuffer, std::vector<uint8_t> &MessageToken);
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
		virtual uint32_t VerifyMIC(TElGSSCustomContext &Ctx, const std::vector<uint8_t> &MessageBuffer, const std::vector<uint8_t> &MessageToken);

		virtual uint32_t VerifyMIC(TElGSSCustomContext *Ctx, const std::vector<uint8_t> &MessageBuffer, const std::vector<uint8_t> &MessageToken);
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

		virtual bool IsMechSupported(const std::vector<uint8_t> &OID);

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
		virtual bool IsIntegrityAvailable(TElGSSCustomContext &Ctx);

		virtual bool IsIntegrityAvailable(TElGSSCustomContext *Ctx);
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
		virtual bool IsMutualAvailable(TElGSSCustomContext &Ctx);

		virtual bool IsMutualAvailable(TElGSSCustomContext *Ctx);
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

		void GetMechOIDByHash(const std::vector<uint8_t> &Hash, std::vector<uint8_t> &OutResult);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElGSSBaseMechanism, Count);

		virtual void get_Mechs(int32_t Index, std::vector<uint8_t> &OutResult);

		virtual void get_OnError(TSBGSSErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSBGSSErrorEvent pMethodValue, void * pDataValue);

		TElGSSBaseMechanism(TElGSSBaseMechanismHandle handle, TElOwnHandle ownHandle);

		TElGSSBaseMechanism();

};
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */

#ifdef SB_USE_CLASS_TELGSSAPICONTEXT
class TElGSSAPIContext: public TElGSSCustomContext
{
	private:
		SB_DISABLE_COPY(TElGSSAPIContext)
	public:
		TElGSSAPIContext(TElGSSAPIContextHandle handle, TElOwnHandle ownHandle);

		TElGSSAPIContext();

};
#endif /* SB_USE_CLASS_TELGSSAPICONTEXT */

#ifdef SB_USE_CLASS_TELGSSAPINAME
class TElGSSAPIName: public TElGSSCustomName
{
	private:
		SB_DISABLE_COPY(TElGSSAPIName)
	public:
		TElGSSAPIName(TElGSSAPINameHandle handle, TElOwnHandle ownHandle);

		TElGSSAPIName();

};
#endif /* SB_USE_CLASS_TELGSSAPINAME */

#ifdef SB_USE_CLASS_TELGSSAPIMECHANISM
class TElGSSAPIMechanism: public TElGSSBaseMechanism
{
	private:
		SB_DISABLE_COPY(TElGSSAPIMechanism)
	public:
		virtual bool Initialize();

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
		virtual uint32_t AcquireCred(const std::vector<uint8_t> &MechOID, TElGSSCustomContext &Ctx);
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME
		virtual uint32_t AcceptSecContext(TElGSSCustomContext &Ctx, TElGSSCustomName &SourceName, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken);

		virtual uint32_t AcceptSecContext(TElGSSCustomContext *Ctx, TElGSSCustomName *SourceName, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken);
#endif /* SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME
		virtual uint32_t InitSecContext(TElGSSCustomContext &Ctx, TElGSSCustomName &TargetName, bool DelegateCred, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken);

		virtual uint32_t InitSecContext(TElGSSCustomContext *Ctx, TElGSSCustomName *TargetName, bool DelegateCred, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken);
#endif /* SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
		virtual uint32_t ReleaseContext(TElGSSCustomContext &Ctx);
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMNAME
		virtual uint32_t ImportName(const std::vector<uint8_t> &MechOID, const std::string &InputName, TElGSSCustomName &OutputName);
#endif /* SB_USE_CLASS_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMNAME
		virtual uint32_t ReleaseName(TElGSSCustomName &Name);
#endif /* SB_USE_CLASS_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
		virtual uint32_t GetMIC(TElGSSCustomContext &Ctx, const std::vector<uint8_t> &MessageBuffer, std::vector<uint8_t> &MessageToken);

		virtual uint32_t GetMIC(TElGSSCustomContext *Ctx, const std::vector<uint8_t> &MessageBuffer, std::vector<uint8_t> &MessageToken);
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
		virtual uint32_t VerifyMIC(TElGSSCustomContext &Ctx, const std::vector<uint8_t> &MessageBuffer, const std::vector<uint8_t> &MessageToken);

		virtual uint32_t VerifyMIC(TElGSSCustomContext *Ctx, const std::vector<uint8_t> &MessageBuffer, const std::vector<uint8_t> &MessageToken);
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

		virtual void get_LibraryName(std::string &OutResult);

		virtual void set_LibraryName(const std::string &Value);

		virtual void get_KRB5CredentialCacheName(std::string &OutResult);

		virtual void set_KRB5CredentialCacheName(const std::string &Value);

		virtual uint32_t get_RequestFlags();

		virtual void set_RequestFlags(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_RequestFlags, set_RequestFlags, TElGSSAPIMechanism, RequestFlags);

		virtual gss_accept_sec_context get_accept_sec_context();

		virtual void set_accept_sec_context(gss_accept_sec_context Value);

		virtual gss_acquire_cred get_acquire_cred();

		virtual void set_acquire_cred(gss_acquire_cred Value);

		virtual gss_delete_sec_context get_delete_sec_context();

		virtual void set_delete_sec_context(gss_delete_sec_context Value);

		virtual gss_display_status get_display_status();

		virtual void set_display_status(gss_display_status Value);

		virtual gss_get_mic get_get_mic();

		virtual void set_get_mic(gss_get_mic Value);

		virtual gss_indicate_mechs get_indicate_mechs();

		virtual void set_indicate_mechs(gss_indicate_mechs Value);

		virtual gss_init_sec_context get_init_sec_context();

		virtual void set_init_sec_context(gss_init_sec_context Value);

		virtual gss_import_name get_import_name();

		virtual void set_import_name(gss_import_name Value);

		virtual gss_krb5_ccache_name get_krb5_ccache_name();

		virtual void set_krb5_ccache_name(gss_krb5_ccache_name Value);

		virtual gss_release_buffer get_release_buffer();

		virtual void set_release_buffer(gss_release_buffer Value);

		virtual gss_release_cred get_release_cred();

		virtual void set_release_cred(gss_release_cred Value);

		virtual gss_release_name get_release_name();

		virtual void set_release_name(gss_release_name Value);

		virtual gss_release_oid_set get_release_oid_set();

		virtual void set_release_oid_set(gss_release_oid_set Value);

		virtual gss_verify_mic get_verify_mic();

		virtual void set_verify_mic(gss_verify_mic Value);

		TElGSSAPIMechanism(TElGSSAPIMechanismHandle handle, TElOwnHandle ownHandle);

		TElGSSAPIMechanism();

};
#endif /* SB_USE_CLASS_TELGSSAPIMECHANISM */

#ifdef SB_USE_CLASS_TELGSSMECHANISMCOLLECTION
class TElGSSMechanismCollection: public TElGSSBaseMechanism
{
	private:
		SB_DISABLE_COPY(TElGSSMechanismCollection)
	public:
		virtual bool Initialize();

		TElGSSBaseMechanismHandle GetMechByOID(const std::vector<uint8_t> &OID);

		void RegisterMechanism(TElGSSBaseMechanism &Mech);

		void RegisterMechanism(TElGSSBaseMechanism *Mech);

		void UnregisterMechanism(TElGSSBaseMechanism &Mech);

		void UnregisterMechanism(TElGSSBaseMechanism *Mech);

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
		virtual uint32_t AcquireCred(const std::vector<uint8_t> &MechOID, TElGSSCustomContext &Ctx);
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME
		virtual uint32_t AcceptSecContext(TElGSSCustomContext &Ctx, TElGSSCustomName &SourceName, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken);

		virtual uint32_t AcceptSecContext(TElGSSCustomContext *Ctx, TElGSSCustomName *SourceName, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken);
#endif /* SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME
		virtual uint32_t InitSecContext(TElGSSCustomContext &Ctx, TElGSSCustomName &TargetName, bool DelegateCred, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken);

		virtual uint32_t InitSecContext(TElGSSCustomContext *Ctx, TElGSSCustomName *TargetName, bool DelegateCred, const std::vector<uint8_t> &InputToken, std::vector<uint8_t> &OutputToken);
#endif /* SB_USE_CLASSES_TELGSSCUSTOMCONTEXT_AND_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
		virtual uint32_t ReleaseContext(TElGSSCustomContext &Ctx);
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMNAME
		virtual uint32_t ImportName(const std::vector<uint8_t> &MechOID, const std::string &InputName, TElGSSCustomName &OutputName);
#endif /* SB_USE_CLASS_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMNAME
		virtual uint32_t ReleaseName(TElGSSCustomName &Name);
#endif /* SB_USE_CLASS_TELGSSCUSTOMNAME */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
		virtual uint32_t GetMIC(TElGSSCustomContext &Ctx, const std::vector<uint8_t> &MessageBuffer, std::vector<uint8_t> &MessageToken);

		virtual uint32_t GetMIC(TElGSSCustomContext *Ctx, const std::vector<uint8_t> &MessageBuffer, std::vector<uint8_t> &MessageToken);
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
		virtual uint32_t VerifyMIC(TElGSSCustomContext &Ctx, const std::vector<uint8_t> &MessageBuffer, const std::vector<uint8_t> &MessageToken);

		virtual uint32_t VerifyMIC(TElGSSCustomContext *Ctx, const std::vector<uint8_t> &MessageBuffer, const std::vector<uint8_t> &MessageToken);
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

		virtual bool IsMechSupported(const std::vector<uint8_t> &OID);

#ifdef SB_USE_CLASS_TELGSSCUSTOMCONTEXT
		virtual bool IsIntegrityAvailable(TElGSSCustomContext &Ctx);

		virtual bool IsIntegrityAvailable(TElGSSCustomContext *Ctx);
#endif /* SB_USE_CLASS_TELGSSCUSTOMCONTEXT */

		TElGSSMechanismCollection(TElGSSMechanismCollectionHandle handle, TElOwnHandle ownHandle);

		TElGSSMechanismCollection();

};
#endif /* SB_USE_CLASS_TELGSSMECHANISMCOLLECTION */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBGSSAPI */

