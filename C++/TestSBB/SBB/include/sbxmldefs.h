#ifndef __INC_SBXMLDEFS
#define __INC_SBXMLDEFS

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

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_XML_ERROR_BASE 	724992
#define SB_XML_ERROR_UTILS_BASE 	725248
#define SB_XML_ERROR_TRANSFORM_BASE 	725504
#define SB_XML_ERROR_SECURITY_BASE 	725760
#define SB_XML_ERROR_ENCRYPTION_BASE 	726016
#define SB_XML_ERROR_XADES_BASE 	726272
#define SB_SOAP_ERROR_BASE 	729088
#define SB_SOAP_ERROR_WSS_BASE 	729344
#define SB_SOAP_ERROR_SECURITY_BASE 	729600
#define SB_SOAP_ERROR_CLIENT_BASE 	729856
#define SB_XML_ERROR_INTERNAL_ERROR 	724993
#define SB_XML_ERROR_NOT_IMPLEMENTED 	724994
#define SB_XML_ERROR_INDEX_OUT_OF_BOUNDS 	724995
#define SB_XML_ERROR_INVALID_PARAMATER 	724996
#define SB_XML_ERROR_NO_DOCUMENT_PARAMETER 	725002
#define SB_XML_ERROR_NO_ELEMENT_PARAMETER 	725003
#define SB_XML_ERROR_NO_NODE_PARAMETER 	725004
#define SB_XML_ERROR_NO_NODE_LIST_PARAMETER 	725005
#define SB_XML_ERROR_NO_ELEMENT 	725006
#define SB_XML_ERROR_NO_NODE 	725007
#define SB_XML_ERROR_INVALID_NODE 	725008
#define SB_XML_ERROR_INVALID_ELEMENT 	725009
#define SB_XML_ERROR_ELEMENT_NOT_FOUND 	725010
#define SB_XML_ERROR_NODE_NOT_FOUND 	725011
#define SB_XML_ERROR_INVALID_CHARACTER_AT_POSITION 	725022
#define SB_XML_ERROR_UNEXPECTED_END_OF_FILE 	725023
#define SB_XML_ERROR_NO_ENCODING 	725024
#define SB_XML_ERROR_MALFORMED_SEQUENCE 	725025
#define SB_XML_ERROR_INVALID_SEQUENCE 	725026
#define SB_XML_ERROR_INVALID_CHAR 	725027
#define SB_XML_ERROR_PARSE_FAILED_AT_POSITION 	725042
#define SB_XML_ERROR_DOCUMENT_ELEMENT_EMPTY_NAME 	725043
#define SB_XML_ERROR_ELEMENT_EMPTY_NAME 	725044
#define SB_XML_ERROR_NODE_EMPTY_NAME 	725045
#define SB_XML_ERROR_NODE_DATA_RELOAD_FAILED 	725046
#define SB_XML_ERROR_RAW_DATA_LOAD_FAILED 	725047
#define SB_XML_ERROR_NODE_NO_CHILD_NODES 	725048
#define SB_XML_ERROR_NODE_WRONG_DOCUMENT 	725049
#define SB_XML_ERROR_NODE_INVALID_NODE_TYPE 	725050
#define SB_XML_ERROR_NODE_HAS_PARENT 	725051
#define SB_XML_ERROR_NODE_PARENT_EQUAL_SELF 	725052
#define SB_XML_ERROR_NODE_INVALID_QUOTE 	725053
#define SB_XML_ERROR_INVALID_PARAMETER_OFFSET 	725054
#define SB_XML_ERROR_INVALID_ENCODING 	725055
#define SB_XML_ERROR_DEFAULT_PREFIX_OVERRIDE 	725056
#define SB_XML_ERROR_INVALID_C14N_METHOD 	725057
#define SB_XML_ERROR_NO_C14N_METHOD 	725058
#define SB_XML_ERROR_INVALID_XPATH_NODE_TYPE 	725082
#define SB_XML_ERROR_INVALID_XPATH_VARIABLE_VALUE 	725083
#define SB_XML_ERROR_BASE64_ENCODING_FAILED 	725249
#define SB_XML_ERROR_BASE64_DECODING_FAILED 	725250
#define SB_XML_ERROR_ID_EXTRACT_FAILED 	725251
#define SB_XML_ERROR_DATETIME_PARSE_FAILED 	725252
#define SB_XML_ERROR_UNSUPPORTED_DATETIME_FORMAT 	725253
#define SB_XML_ERROR_INVALID_PUBLIC_KEY 	725761
#define SB_XML_ERROR_NO_SIGNING_CERTIFICATE 	725762
#define SB_XML_ERROR_UNSUPPORTED_DIGEST_ALGORITHM 	725763
#define SB_XML_ERROR_UNSUPPORTED_EC_FIELD_TYPE 	725764
#define SB_XML_ERROR_UNSUPPORTED_MASK_GENERATION_FUNCTION 	725765
#define SB_XML_ERROR_UNSUPPORTED_EC_PRIME_NUMBER_TYPE 	725766
#define SB_XML_ERROR_NO_KEY_DATA 	725770
#define SB_XML_ERROR_NO_HMAC_KEY_DATA 	725771
#define SB_XML_ERROR_NO_DSA_KEY_DATA 	725772
#define SB_XML_ERROR_NO_RSA_KEY_DATA 	725773
#define SB_XML_ERROR_NO_ECDSA_KEY_DATA 	725774
#define SB_XML_ERROR_NO_GOST94_KEY_DATA 	725775
#define SB_XML_ERROR_NO_GOST2001_KEY_DATA 	725776
#define SB_XML_ERROR_INVALID_KEY_DATA 	725777
#define SB_XML_ERROR_UNSUPPORTED_HMAC_METHOD 	725778
#define SB_XML_ERROR_UNSUPPORTED_SIGNATURE_METHOD 	725779
#define SB_XML_ERROR_UNSUPPORTED_SIGNATURE_ALGORITHM 	725780
#define SB_XML_ERROR_BAD_ASYNC_STATE 	725781
#define SB_XML_ERROR_NO_ASYNC_SIGNATURE 	725782
#define SB_XML_ERROR_ASYNC_MODE_NOT_SUPPORTED 	725783
#define SB_XML_ERROR_TIMESTAMP_FAILED 	725784
#define SB_XML_ERROR_SIGNATURE_NOT_LOADED 	725785
#define SB_XML_ERROR_NO_RSA_PSS_PARAMETERS 	725786
#define SB_XML_ERROR_TOO_MANY_QUALIFYING_PROPERTIES 	725787
#define SB_XML_ERROR_TOO_MANY_SIGNATURE_PROPERTIES 	725788
#define SB_XML_ERROR_NO_SIGNATURE_PROPERTIES 	725789
#define SB_XML_ERROR_INVALID_AES_KEY_LENGTH 	726017
#define SB_XML_ERROR_INVALID_CAMELLIA_KEY_LENGTH 	726018
#define SB_XML_ERROR_INVALID_AES_WRAPPED_KEY_LENGTH 	726019
#define SB_XML_ERROR_INVALID_EXTERNAL_MODE_FOR_NODE_ENCRYPTION 	726020
#define SB_XML_ERROR_INVALID_EXTERNAL_MODE_FOR_NODE_LIST_ENCRYPTION 	726021
#define SB_XML_ERROR_INVALID_ELEMENT_MODE_FOR_NODE_LIST_ENCRYPTION 	726022
#define SB_XML_ERROR_INVALID_ELEMENT_MODE_FOR_BINARY_ENCRYPTION 	726023
#define SB_XML_ERROR_INVALID_CONTENT_MODE_FOR_BINARY_ENCRYPTION 	726024
#define SB_XML_ERROR_ENCRYPTED_DATA_NOT_LOADED 	726025
#define SB_XML_ERROR_NO_KEY_ENCRYPTION_KEY_DATA 	726026
#define SB_XML_ERROR_INVALID_KEY_ENCRYPTION_KEY_DATA 	726027
#define SB_XML_ERROR_INVALID_KEY_WRAP_METHOD 	726028
#define SB_XML_ERROR_UNSUPPORTED_ENCRYPTION_METHOD 	726029
#define SB_XML_ERROR_UNSUPPORTED_ENCRYPTION_ALGORITHM 	726030
#define SB_XML_ERROR_UNSUPPORTED_KEY_ENCRYPTION_KEY_METHOD 	726031
#define SB_XML_ERROR_UNSUPPORTED_KEY_ENCRYPTION_TYPE 	726032
#define SB_XML_ERROR_UNSUPPORTED_KEY_WRAP_METHOD 	726033
#define SB_XML_ERROR_UNSUPPORTED_KEY_TRANSPORT_METHOD 	726034
#define SB_XML_ERROR_INVALID_TRIPLE_DES_WRAPPED_KEY_LENGTH 	726035
#define SB_XML_ERROR_INVALID_AES_ENCRYPTED_WRAPPED_KEY_LENGTH 	726036
#define SB_XML_ERROR_INVALID_ENCRYPTED_WRAPPED_KEY 	726037
#define SB_XML_ERROR_INVALID_ENCRYPTED_DATA 	726038
#define SB_XML_ERROR_INVALID_TRIPLE_DES_ENCRYPTED_WRAPPED_KEY_LENGTH 	726039
#define SB_XML_ERROR_CANT_ENCRYPT_ATTRIBUTE_NODE 	726040
#define SB_XML_ERROR_NO_CIPHER_VALUE 	726041
#define SB_XML_ERROR_REFERENCE_NO_CONTEXT 	725505
#define SB_XML_ERROR_TRANSFORM_CHAIN_NO_DATA 	725506
#define SB_XML_ERROR_UNSUPPORTED_TRANSFORM 	725507
#define SB_XML_ERROR_UNSUPPORTED_TRANSFORM_ALGORITHM 	725508
#define SB_XML_ERROR_TRANSFORM_ALREADY_REGISTERED 	725509
#define SB_XML_ERROR_INVALID_TRANSFORM_ORDER 	725510
#define SB_XML_ERROR_BASE64_TRANSFORM_FAILED 	725511
#define SB_XML_ERROR_XPATH_TRANSFORM_NO_CONTEXT 	725512
#define SB_XML_ERROR_XPATH_FILTER2_TRANSFORM_NO_CONTEXT 	725513
#define SB_XML_ERROR_BINARY_DATA_TRANSFORM_FAILED 	725514
#define SB_XML_ERROR_DECRYPTION_TRANSFORM_FAILED 	725515
#define SB_XML_ERROR_BINARY_DECRYPTION_TRANSFORM_FAILED 	725516
#define SB_XML_ERROR_INVALID_DECRYPTION_TRANSFORM_RESULT 	725517
#define SB_XML_ERROR_INVALID_XADES_VERSION 	726273
#define SB_XML_ERROR_UNSUPPORTED_XADES_VERSION 	726274
#define SB_XML_ERROR_INVALID_OBJECT_TYPE_PARAMETER 	726275
#define SB_XML_ERROR_UNSUPPORTED_QUALIFIER_TYPE 	726276
#define SB_XML_ERROR_UNSUPPORTED_PKI_DATA_ENCODING_METHOD 	726277
#define SB_XML_ERROR_UNSUPPORTED_XADES_V111_PROPERTY 	726278
#define SB_XML_ERROR_UNSUPPORTED_XADES_V111_V122_PROPERTY 	726279
#define SB_XML_ERROR_UNSUPPORTED_XADES_FORM 	726280
#define SB_XML_ERROR_INCLUCE_NO_CONTEXT 	726281
#define SB_XML_ERROR_INCLUDE_INVALID_CONTEXT 	726282
#define SB_XML_ERROR_NO_TSP_CLIENT 	726283
#define SB_XML_ERROR_SIGNING_CERTIFICATE_NOT_FOUND 	726284
#define SB_XML_ERROR_QUALIFYING_PROPERTIES_NOT_FOUND 	726285
#define SB_XML_ERROR_VALIDATION_INFORMATION_INCOMPLETE 	726286
#define SB_XML_ERROR_SIGNER_PROCESSOR_EXPECTED 	726287
#define SB_XML_ERROR_RETRIEVED_CERTIFICATE_NOT_MATCH 	726288
#define SB_XML_ERROR_RETRIEVED_CRL_NOT_MATCH 	726289
#define SB_XML_ERROR_RETRIEVED_OCSP_RESPONSE_NOT_MATCH 	726290
#define SB_XML_ERROR_UNSIGNED_SIGNATURE_PROPERTY_ADD_FAILED 	726291
#define SB_XML_ERROR_UNSIGNED_SIGNATURE_PROPERTY_ALREADY_EXISTS 	726292
#define SB_XML_ERROR_DOCUMENT_SIGNED_CANT_ADD_ALL_DATA_OBJECTS_TIMESTAMP 	726293
#define SB_XML_ERROR_CANT_ADD_ARCHIVE_TIMESTAMP 	726294
#define SB_XML_ERROR_VERIFIER_PROCESSOR_EXPECTED 	726295
#define SB_SOAP_ERROR_INTERNAL_ERROR 	729089
#define SB_SOAP_ERROR_NOT_IMPLEMENTED 	729090
#define SB_SOAP_ERROR_UNSUPPORTED_OPERATION 	729093
#define SB_SOAP_ERROR_DOCUMENT_ELEMENT_EXISTS 	729099
#define SB_SOAP_ERROR_ENVELOPE_BODY_ELEMENT_EXISTS 	729100
#define SB_SOAP_ERROR_ENVELOPE_HEADER_ELEMENT_EXISTS 	729101
#define SB_SOAP_ERROR_BODY_ELEMENT_NOT_LOADED 	729102
#define SB_SOAP_ERROR_HEADER_ELEMENT_NOT_LOADED 	729103
#define SB_SOAP_ERROR_HEADER_BLOCK_NOT_LOADED 	729104
#define SB_SOAP_ERROR_MESSAGE_NOT_LOADED 	729105
#define SB_SOAP_ERROR_WSSE_NO_HEADER_BLOCK 	729345
#define SB_SOAP_ERROR_WSSE_TOKEN_NOT_LOADED 	729346
#define SB_SOAP_ERROR_WSSE_ELEMENT_NOT_LOADED 	729347
#define SB_SOAP_ERROR_WSSE_BINARY_SECURITY_TOKEN_NOT_LOADED 	729348
#define SB_SOAP_ERROR_WSSE_PASSWORD_NOT_LOADED 	729349
#define SB_SOAP_ERROR_WSSE_NONCE_NOT_LOADED 	729350
#define SB_SOAP_ERROR_WSSE_ADD_TOKEN_FAILED 	729351
#define SB_SOAP_ERROR_WSSE_INVALID_BINARY_SECURITY_TOKEN_VALUE_TYPE 	729352
#define SB_SOAP_ERROR_WSSE_USERNAME_TOKEN_NONCE_ELEMENT_EXISTS 	729353
#define SB_SOAP_ERROR_WSSE_USERNAME_TOKEN_PASSWORD_ELEMENT_EXISTS 	729354
#define SB_SOAP_ERROR_WSSE_USERNAME_TOKEN_USERNAME_ELEMENT_EXISTS 	729355
#define SB_SOAP_ERROR_WSU_DATETIME_NOT_LOADED 	729356
#define SB_SOAP_ERROR_WSU_TIMESTAMP_CREATED_ELEMENT_EXISTS 	729357
#define SB_SOAP_ERROR_WSU_TIMESTAMP_EXPIRES_ELEMENT_EXISTS 	729358
#define SB_SOAP_ERROR_WSSE_USERNAME_TOKEN_CREATED_ELEMENT_EXISTS 	729359
#define SB_SOAP_ERROR_SECURITY_HANDLER_ALREADY_REGISTERED 	729601
#define SB_SOAP_ERROR_SIGNATURE_HANDLER_NOT_ATTACHED 	729602
#define SB_SOAP_ERROR_SIGNATURE_CALCULATED_CANT_SIGN 	729603
#define SB_SOAP_ERROR_SIGNATURE_NOT_CALCULATED_CANT_VALIDATE 	729604
#define SB_SOAP_ERROR_NO_SIGNATURE_CANT_COMPLETE_ASYNC_SIGN 	729605
#define SB_SOAP_ERROR_TARGET_ELEMENT_HAS_NO_ID 	729606
#define SB_SOAP_ERROR_NOTHING_TO_SIGN 	729607
#define SB_SOAP_ERROR_NO_CERTIFICATE 	729608
#define SB_SOAP_ERROR_NO_KEY_DATA 	729609
#define SB_SOAP_ERROR_UNSUPPORTED_CERTIFICATE_PUBLIC_KEY_ALGORITHM 	729610
#define SB_SOAP_ERROR_SIGNATURE_ELEMENT_MODIFICATION_FAILED 	729611
#define SB_SOAP_ERROR_INVALID_PARAMETERS_COMBINATION 	729612
#define SB_SOAP_ERROR_SIGNATURE_CALCULATED_CANT_CHANGE_SECURITY_HEADER_BLOCK 	729613
#define SB_SOAP_ERROR_UNEXPECTED_HTTP_STATUS_CODE 	729857
#define SB_SOAP_ERROR_NO_HTTP_CLIENT 	729858
#define SB_SOAP_ERROR_INVALID_PARTS_LIST_PARAMETER 	729859
#define SB_SOAP_ERROR_INVALID_BOOLEAN_VALUE 	729860
#define SB_SOAP_ERROR_INVALID_NUMBER_VALUE 	729861
#define SB_SOAP_ERROR_INVALID_DATETIME_VALUE 	729862
#define SB_SOAP_ERROR_INVALID_BASE64_VALUE 	729863
#define SB_SOAP_ERROR_INVALID_PARAMETER_NAME 	729864
#define SB_xmlNamespace 	"http://www.w3.org/XML/1998/namespace"
#define SB_xmlSchemaNamespace 	"http://www.w3.org/2001/XMLSchema"
#define SB_xmlSchemaInstanceNamespace 	"http://www.w3.org/2001/XMLSchema-instance"
#define SB_xmlEncryptionNamespace 	"http://www.w3.org/2001/04/xmlenc#"
#define SB_xmlSignatureNamespace 	"http://www.w3.org/2000/09/xmldsig#"
#define SB_xmlSignatureNamespaceMore 	"http://www.w3.org/2001/04/xmldsig-more#"
#define SB_xmlSignatureNamespace_v1_1 	"http://www.w3.org/2009/xmldsig11#"
#define SB_xmlSignatureNamespacePSS 	"http://www.w3.org/2007/05/xmldsig-more#"
#define SB_xmlDecryptionNamespace 	"http://www.w3.org/2002/07/decrypt#"
#define SB_xmlXAdESNamespace_v1_1_1 	"http://uri.etsi.org/01903/v1.1.1#"
#define SB_xmlXAdESNamespace_v1_2_2 	"http://uri.etsi.org/01903/v1.2.2#"
#define SB_xmlXAdESNamespace_v1_3_2 	"http://uri.etsi.org/01903/v1.3.2#"
#define SB_xmlXAdESNamespace_v1_4_1 	"http://uri.etsi.org/01903/v1.4.1#"
#define SB_xmlExclCanonicalizationNamespace 	"http://www.w3.org/2001/10/xml-exc-c14n#"
#define SB_xmlXKMSNamespace 	"http://www.w3.org/2002/03/xkms#"
#define SB_xmlXPathFilter2Namespace 	"http://www.w3.org/2002/06/xmldsig-filter2"
#define SB_xmlXPathFilter2Namespace04 	"http://www.w3.org/2002/04/xmldsig-filter2"
#define SB_xmlEBICSNamespace 	"http://www.ebics.org/H003"
#define SB_xmlCPXMLSpecNamespace 	"urn:ietf:params:xml:ns:cpxmlsec"
#define SB_xmlSOAPEnvelopeNamespace_v1_1 	"http://schemas.xmlsoap.org/soap/envelope/"
#define SB_xmlSOAPSecurityNamespace 	"http://schemas.xmlsoap.org/soap/security/2000-12"
#define SB_xmlWSSENamespace_v1_0 	"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd"
#define SB_xmlWSSENamespace_v1_1 	"http://docs.oasis-open.org/wss/oasis-wss-wssecurity-secext-1.1.xsd"
#define SB_xmlWSUNamespace 	"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd"
#define SB_xmlPrefix 	"xml"
#ifndef SB_xmlSchemaPrefix
#define SB_xmlSchemaPrefix 	"xs"
#endif
#define SB_xmlSchemaInstancePrefix 	"xsi"
#define SB_xmlEncryptionPrefix 	"xenc"
#define SB_xmlSignaturePrefix 	"ds"
#define SB_xmlDSIGPrefix 	"dsig"
#define SB_xmlDSIGPrefix_v1_1 	"dsig11"
#define SB_xmlXAdESPrefix 	"xades"
#define SB_xmlXAdESPrefix_v1_4_1 	"xadesv141"
#define SB_xmlDecryptionPrefix 	"dcrpt"
#define SB_xmlExclCanonicalizationPrefix 	"ec"
#define SB_xmlXKMSPrefix 	"xkms"
#define SB_xmlXPathFilter2Prefix 	"xf"
#define SB_xmlCPXMLSpecPrefix 	"cpxmlsec"
#define SB_xmlSOAPEnvelopePrefix_v1_1 	"SOAP-ENV"
#define SB_xmlSOAPEnvelopePrefix_v1_2 	"env"
#define SB_xmlSOAPSecurityPrefix 	"SOAP-SEC"
#define SB_xmlWSSEPrefix 	"wsse"
#define SB_xmlWSUPrefix 	"wsu"
#define SB_xmlECDSAPrefix 	"ecdsa"
#define SB_xmlPSSPrefix 	"pss"
#define SB_xmlEncryptedDataTypeElement 	"http://www.w3.org/2001/04/xmlenc#Element"
#define SB_xmlEncryptedDataTypeContent 	"http://www.w3.org/2001/04/xmlenc#Content"
#define SB_xmlRefTypeSignedProperties_v1_1_1 	"http://uri.etsi.org/01903/v1.1.1#SignedProperties"
#define SB_xmlRefTypeSignedProperties_v1_2_2 	"http://uri.etsi.org/01903/v1.2.2#SignedProperties"
#define SB_xmlRefTypeSignedProperties 	"http://uri.etsi.org/01903#SignedProperties"
#define SB_xmlRefTypeCountersignedSignature 	"http://uri.etsi.org/01903#CountersignedSignature"
#define SB_xmlEncryptedKeyType 	"http://www.w3.org/2001/04/xmlenc#EncryptedKey"
#define SB_xmlMimeTypeXML 	"text/xml"
#define SB_xmlDigestMethodSHA1 	"http://www.w3.org/2000/09/xmldsig#sha1"
#define SB_xmlDigestMethodMD5 	"http://www.w3.org/2001/04/xmldsig-more#md5"
#define SB_xmlDigestMethodSHA224 	"http://www.w3.org/2001/04/xmldsig-more#sha224"
#define SB_xmlDigestMethodSHA256 	"http://www.w3.org/2001/04/xmlenc#sha256"
#define SB_xmlDigestMethodSHA384 	"http://www.w3.org/2001/04/xmldsig-more#sha384"
#define SB_xmlDigestMethodSHA512 	"http://www.w3.org/2001/04/xmlenc#sha512"
#define SB_xmlDigestMethodRIPEMD160 	"http://www.w3.org/2001/04/xmlenc#ripemd160"
#define SB_xmlDigestMethodWhirlpool 	"http://www.w3.org/2007/05/xmldsig-more#whirlpool"
#define SB_xmlDigestMethodSHA3_224 	"http://www.w3.org/2007/05/xmldsig-more#sha3-224"
#define SB_xmlDigestMethodSHA3_256 	"http://www.w3.org/2007/05/xmldsig-more#sha3-256"
#define SB_xmlDigestMethodSHA3_384 	"http://www.w3.org/2007/05/xmldsig-more#sha3-384"
#define SB_xmlDigestMethodSHA3_512 	"http://www.w3.org/2007/05/xmldsig-more#sha3-512"
#define SB_xmlDigestMethodGOSTR3411_Draft0 	"http://www.w3.org/2001/04/xmldsig-more#gostr3411"
#define SB_xmlDigestMethodGOSTR3411_Draft1 	"http://www.w3.org/2006/10/xmldsig-gost#gostr3411"
#define SB_xmlDigestMethodGOSTR3411_Draft2 	"urn:ietf:params:xml:ns:xmlsec-gost:algorithms:gostr3411"
#define SB_xmlDigestMethodGOSTR3411_URN 	"urn:ietf:params:xml:ns:cpxmlsec:algorithms:gostr3411"
#define SB_xmlEncryptionMethod3DES 	"http://www.w3.org/2001/04/xmlenc#tripledes-cbc"
#define SB_xmlEncryptionMethodAES128 	"http://www.w3.org/2001/04/xmlenc#aes128-cbc"
#define SB_xmlEncryptionMethodAES192 	"http://www.w3.org/2001/04/xmlenc#aes192-cbc"
#define SB_xmlEncryptionMethodAES256 	"http://www.w3.org/2001/04/xmlenc#aes256-cbc"
#define SB_xmlEncryptionMethodDES 	"http://www.w3.org/2001/04/xmlenc#des-cbc"
#define SB_xmlEncryptionMethodCamellia128 	"http://www.w3.org/2001/04/xmldsig-more#camellia128-cbc"
#define SB_xmlEncryptionMethodCamellia192 	"http://www.w3.org/2001/04/xmldsig-more#camellia192-cbc"
#define SB_xmlEncryptionMethodCamellia256 	"http://www.w3.org/2001/04/xmldsig-more#camellia256-cbc"
#define SB_xmlEncryptionMethodRC4 	"http://www.w3.org/2001/04/xmldsig-more#arcfour"
#define SB_xmlEncryptionMethodSEED 	"http://www.w3.org/2007/05/xmldsig-more#seed128-cbc"
#define SB_xmlEncryptionMethodAES128_GCM 	"http://www.w3.org/2009/xmlenc11#aes128-gcm"
#define SB_xmlEncryptionMethodAES192_GCM 	"http://www.w3.org/2009/xmlenc11#aes192-gcm"
#define SB_xmlEncryptionMethodAES256_GCM 	"http://www.w3.org/2009/xmlenc11#aes256-gcm"
#define SB_xmlKeyWrapMethod3DES 	"http://www.w3.org/2001/04/xmlenc#kw-tripledes"
#define SB_xmlKeyWrapMethodAES128 	"http://www.w3.org/2001/04/xmlenc#kw-aes128"
#define SB_xmlKeyWrapMethodAES192 	"http://www.w3.org/2001/04/xmlenc#kw-aes192"
#define SB_xmlKeyWrapMethodAES256 	"http://www.w3.org/2001/04/xmlenc#kw-aes256"
#define SB_xmlKeyWrapMethodCamellia128 	"http://www.w3.org/2001/04/xmldsig-more#kw-camellia128"
#define SB_xmlKeyWrapMethodCamellia192 	"http://www.w3.org/2001/04/xmldsig-more#kw-camellia192"
#define SB_xmlKeyWrapMethodCamellia256 	"http://www.w3.org/2001/04/xmldsig-more#kw-camellia256"
#define SB_xmlKeyWrapMethodSEED 	"http://www.w3.org/2007/05/xmldsig-more#kw-seed128"
#define SB_xmlKeyTransportMethodRSA15 	"http://www.w3.org/2001/04/xmlenc#rsa-1_5"
#define SB_xmlKeyTransportMethodRSAOAEP 	"http://www.w3.org/2001/04/xmlenc#rsa-oaep-mgf1p"
#define SB_xmlTransformBase64 	"http://www.w3.org/2000/09/xmldsig#base64"
#define SB_xmlTransformEnvelopedSignature 	"http://www.w3.org/2000/09/xmldsig#enveloped-signature"
#define SB_xmlTransformNull 	"http://www.w3.org/2000/09/xmldsig#null"
#define SB_xmlTransformDecryptBinary 	"http://www.w3.org/2002/07/decrypt#Binary"
#define SB_xmlTransformDecryptXML 	"http://www.w3.org/2002/07/decrypt#XML"
#define SB_xmlCanonicalizationMinimal 	"http://www.w3.org/2000/09/xmldsig#minimal"
#define SB_xmlSignatureAlgorithmDSASHA1 	"http://www.w3.org/2000/09/xmldsig#dsa-sha1"
#define SB_xmlSignatureAlgorithmDSASHA256 	"http://www.w3.org/2009/xmldsig11#dsa-sha256"
#define SB_xmlSignatureAlgorithmRSASHA1 	"http://www.w3.org/2000/09/xmldsig#rsa-sha1"
#define SB_xmlSignatureAlgorithmRSAMD5 	"http://www.w3.org/2001/04/xmldsig-more#rsa-md5"
#define SB_xmlSignatureAlgorithmRSASHA224 	"http://www.w3.org/2007/05/xmldsig-more#rsa-sha224"
#define SB_xmlSignatureAlgorithmRSASHA256 	"http://www.w3.org/2001/04/xmldsig-more#rsa-sha256"
#define SB_xmlSignatureAlgorithmRSASHA384 	"http://www.w3.org/2001/04/xmldsig-more#rsa-sha384"
#define SB_xmlSignatureAlgorithmRSASHA512 	"http://www.w3.org/2001/04/xmldsig-more#rsa-sha512"
#define SB_xmlSignatureAlgorithmRSARIPEMD160 	"http://www.w3.org/2001/04/xmldsig-more#rsa-ripemd160"
#define SB_xmlSignatureAlgorithmRSARIPEMD160Typo 	"http://www.w3.org/2001/04/xmldsig-more/rsa-ripemd160"
#define SB_xmlSignatureAlgorithmRSAWhirlpool 	"http://www.w3.org/2007/05/xmldsig-more#rsa-whirlpool"
#define SB_xmlSignatureAlgorithmECDSASHA1 	"http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha1"
#define SB_xmlSignatureAlgorithmECDSASHA224 	"http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha224"
#define SB_xmlSignatureAlgorithmECDSASHA256 	"http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha256"
#define SB_xmlSignatureAlgorithmECDSASHA384 	"http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha384"
#define SB_xmlSignatureAlgorithmECDSASHA512 	"http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha512"
#define SB_xmlSignatureAlgorithmECDSARIPEMD160 	"http://www.w3.org/2007/05/xmldsig-more#ecdsa-ripemd160"
#define SB_xmlSignatureAlgorithmECDSAWhirlpool 	"http://www.w3.org/2007/05/xmldsig-more#ecdsa-whirlpool"
#define SB_xmlSignatureAlgorithmGOSTR341094_GOSTR3411_Draft0 	"http://www.w3.org/2001/04/xmldsig-more#gostr341094-gostr3411"
#define SB_xmlSignatureAlgorithmGOSTR341094_GOSTR3411_Draft1 	"http://www.w3.org/2001/04/xmldsig-gost#gostr341094-gostr3411"
#define SB_xmlSignatureAlgorithmGOSTR34102001_GOSTR3411_Draft0 	"http://www.w3.org/2001/04/xmldsig-more#gostr34102001-gostr3411"
#define SB_xmlSignatureAlgorithmGOSTR34102001_GOSTR3411_Draft1 	"http://www.w3.org/2006/10/xmldsig-gost#gostr34102001-gostr3411"
#define SB_xmlSignatureAlgorithmGOSTR34102001_GOSTR3411_Draft2 	"urn:ietf:params:xml:ns:xmlsec-gost:algorithms:gostr34102001-gostr3411"
#define SB_xmlSignatureAlgorithmGOSTR34102001_GOSTR3411_URN 	"urn:ietf:params:xml:ns:cpxmlsec:algorithms:gostr34102001-gostr3411"
#define SB_xmlSignatureAlgorithmRSAPSS 	"http://www.w3.org/2007/05/xmldsig-more#rsa-pss"
#define SB_xmlSignatureAlgorithmRSAPSS_MD5_MGF1 	"http://www.w3.org/2007/05/xmldsig-more#md5-rsa-MGF1"
#define SB_xmlSignatureAlgorithmRSAPSS_SHA1_MGF1 	"http://www.w3.org/2007/05/xmldsig-more#sha1-rsa-MGF1"
#define SB_xmlSignatureAlgorithmRSAPSS_SHA224_MGF1 	"http://www.w3.org/2007/05/xmldsig-more#sha224-rsa-MGF1"
#define SB_xmlSignatureAlgorithmRSAPSS_SHA256_MGF1 	"http://www.w3.org/2007/05/xmldsig-more#sha256-rsa-MGF1"
#define SB_xmlSignatureAlgorithmRSAPSS_SHA384_MGF1 	"http://www.w3.org/2007/05/xmldsig-more#sha384-rsa-MGF1"
#define SB_xmlSignatureAlgorithmRSAPSS_SHA512_MGF1 	"http://www.w3.org/2007/05/xmldsig-more#sha512-rsa-MGF1"
#define SB_xmlSignatureAlgorithmRSAPSS_RIPEMD160_MGF1 	"http://www.w3.org/2007/05/xmldsig-more#ripemd160-rsa-MGF1"
#define SB_xmlSignatureAlgorithmRSAPSS_Whirlpool_MGF1 	"http://www.w3.org/2007/05/xmldsig-more#whirlpool-rsa-MGF1"
#define SB_xmlMaskGenerationFunctionMGF1 	"http://www.w3.org/2007/05/xmldsig-more#MGF1"
#define SB_xmlSignatureHMACSHA1 	"http://www.w3.org/2000/09/xmldsig#hmac-sha1"
#define SB_xmlSignatureHMACMD5 	"http://www.w3.org/2001/04/xmldsig-more#hmac-md5"
#define SB_xmlSignatureHMACSHA224 	"http://www.w3.org/2001/04/xmldsig-more#hmac-sha224"
#define SB_xmlSignatureHMACSHA256 	"http://www.w3.org/2001/04/xmldsig-more#hmac-sha256"
#define SB_xmlSignatureHMACSHA384 	"http://www.w3.org/2001/04/xmldsig-more#hmac-sha384"
#define SB_xmlSignatureHMACSHA512 	"http://www.w3.org/2001/04/xmldsig-more#hmac-sha512"
#define SB_xmlSignatureHMACRIPEMD160 	"http://www.w3.org/2001/04/xmldsig-more#hmac-ripemd160"
#define SB_xmlKeyInfoDSA 	"http://www.w3.org/2000/09/xmldsig#DSAKeyValue"
#define SB_xmlKeyInfoRSA 	"http://www.w3.org/2000/09/xmldsig#RSAKeyValue"
#define SB_xmlKeyInfoGOST 	"http://www.w3.org/2000/09/xmldsig#KeyValue/GostKeyValue"
#define SB_xmlKeyInfoGOST_URN 	"urn:ietf:params:xml:ns:cpxmlsec:GOSTKeyValue"
#define SB_xmlKeyInfoX509Data 	"http://www.w3.org/2000/09/xmldsig#X509Data"
#define SB_xmlKeyInfoPGPData 	"http://www.w3.org/2000/09/xmldsig#PGPData"
#define SB_xmlKeyInfoSPKIData 	"http://www.w3.org/2000/09/xmldsig#SPKIData"
#define SB_xmlKeyInfoMgmtData 	"http://www.w3.org/2000/09/xmldsig#MgmtData"
#define SB_xmlKeyInfoRawX509Certificate 	"http://www.w3.org/2000/09/xmldsig#rawX509Certificate"
#define SB_xmlKeyInfoPKCS7signedData 	"http://www.w3.org/2001/04/xmldsig-more#PKCS7signedData"
#define SB_xmlKeyInfoRawPKCS7signedData 	"http://www.w3.org/2001/04/xmldsig-more#rawPKCS7signedData"
#define SB_xmlKeyInfoECKeyValue 	"http://www.w3.org/2009/xmldsig11#ECKeyValue"
#define SB_xmlKeyInfoDEREncodedKeyValue 	"http://www.w3.org/2009/xmldsig11#DEREncodedKeyValue"
#define SB_xmlReferenceObject 	"http://www.w3.org/2000/09/xmldsig#Object"
#define SB_xmlReferenceManifest 	"http://www.w3.org/2000/09/xmldsig#Manifest"
#define SB_xmlReferenceSignatureProperties 	"http://www.w3.org/2000/09/xmldsig#SignatureProperties"
#define SB_xmlReferenceSignatureProperty 	"http://www.w3.org/2000/02/xmldsig#SignatureProperty"
#define SB_xmlWSSEncodingBase64Binary 	"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-soap-message-security-1.0#Base64Binary"
#define SB_xmlWSSTransformSTR 	"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-soap-message-security-1.0#STR-Transform"
#define SB_xmlWSSBinaryTokenPKCS7 	"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-x509-token-profile-1.0#PKCS7"
#define SB_xmlWSSBinaryTokenX509v3 	"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-x509-token-profile-1.0#X509v3"
#define SB_xmlWSSBinaryTokenX509v1 	"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-x509-token-profile-1.0#X509v1"
#define SB_xmlWSSBinaryTokenX509PKIPathv1 	"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-x509-token-profile-1.0#X509PKIPathv1"
#define SB_xmlWSSBinaryTokenX509SubjectKeyIdentifier 	"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-x509-token-profile-1.0#X509SubjectKeyIdentifier"
#define SB_SXMLNoNodeAvailable 	"No XML node available."
#define SB_SXMLNoDocumentAvailable 	"No XML document available."
#define SB_SXMLNoElementAvailable 	"No XML element available."
#define SB_SXMLNoNodeListAvailable 	"No XML node list available."
#define SB_SXMLNoKeyDataAvailable 	"No key data available."
#define SB_SXMLInvalidNode 	"Invalid XML node."
#define SB_SXMLInvalidElement 	"Invalid XML element."
#define SB_SXMLNoInclusiveNamespacesPrefixList 	"Canonicalization method doesn\'t support InclusiveNamespaces PrefixList."
#define SB_SFXMLElementNotFound 	"XML element \'%s\' not found."
#define SB_SFXMLIndexOutOfBounds 	"Index out of bounds (%d)."
#define SB_SFXMLInvalidElement 	"Invalid XML element (%s)."

typedef TElClassHandle TElVersionURIHandle;

typedef TElVersionURIHandle ElVersionURIHandle;

typedef uint8_t TElXMLCanonicalizationMethodRaw;

typedef enum
{
	xcmNone = 0,
	xcmCanon = 1,
	xcmCanonComment = 2,
	xcmExclCanon = 3,
	xcmExclCanonComment = 4,
	xcmMinCanon = 5,
	xcmCanon_v1_1 = 6,
	xcmCanonComment_v1_1 = 7
} TElXMLCanonicalizationMethod;

typedef TElXMLCanonicalizationMethod ElXMLCanonicalizationMethod;

typedef uint8_t TElXMLTextTypeRaw;

typedef enum
{
	ttNormal = 0,
	ttBase64 = 1
} TElXMLTextType;

typedef TElXMLTextType ElXMLTextType;

#ifdef SB_USE_CLASS_TELVERSIONURI
SB_IMPORT uint32_t SB_APIENTRY TElVersionURI_IsEqual(TElVersionURIHandle _Handle, const char * pcURI, int32_t szURI, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElVersionURI_get_DefaultVersion(TElVersionURIHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElVersionURI_set_DefaultVersion(TElVersionURIHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElVersionURI_get_LatestVersion(TElVersionURIHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElVersionURI_Create(const char * pcADefaultVersion, int32_t szADefaultVersion, const char * pcALatestVersion, int32_t szALatestVersion, const TStringListHandle AVersions, TElVersionURIHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElVersionURI_Create_1(const TElVersionURIHandle ABaseURI, const char * pcAAnchor, int32_t szAAnchor, TElVersionURIHandle * OutResult);
#endif /* SB_USE_CLASS_TELVERSIONURI */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElVersionURI;
typedef TElVersionURI ElVersionURI;

#ifdef SB_USE_CLASS_TELVERSIONURI
class TElVersionURI: public TObject
{
	private:
		SB_DISABLE_COPY(TElVersionURI)
	public:
		bool IsEqual(const std::string &URI);

		virtual void get_DefaultVersion(std::string &OutResult);

		virtual void set_DefaultVersion(const std::string &Value);

		virtual void get_LatestVersion(std::string &OutResult);

		TElVersionURI(TElVersionURIHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TSTRINGLIST
		TElVersionURI(const std::string &ADefaultVersion, const std::string &ALatestVersion, const TStringList &AVersions);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		TElVersionURI(const TElVersionURI &ABaseURI, const std::string &AAnchor);

		TElVersionURI(const TElVersionURI *ABaseURI, const std::string &AAnchor);

};
#endif /* SB_USE_CLASS_TELVERSIONURI */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBXMLDEFS */

