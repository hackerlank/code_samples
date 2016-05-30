#ifndef __INC_SBRESTCLIENT
#define __INC_SBRESTCLIENT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbhttpsclient.h"
#include "sbhttpscommon.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbstreams.h"
#include "sbxmlcore.h"
#include "sbxmldefs.h"
#include "sbjson.h"
#include "sbchsconv.h"
#include "sbchsconvcharsets.h"
#include "sbchscjk.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElRESTClientHandle;

typedef TElRESTClientHandle ElRESTClientHandle;

typedef uint8_t TSBRESTResponseTypeRaw;

typedef enum
{
	rrtUnknown = 0,
	rrtXML = 1,
	rrtJSON = 2
} TSBRESTResponseType;

#ifdef SB_USE_CLASS_TELRESTCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElRESTClient_Post(TElRESTClientHandle _Handle, const char * pcURL, int32_t szURL, TElXMLDOMDocumentHandle Content, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRESTClient_Post_1(TElRESTClientHandle _Handle, const char * pcURL, int32_t szURL, TElJsonEntityHandle Content, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRESTClient_Put(TElRESTClientHandle _Handle, const char * pcURL, int32_t szURL, TElXMLDOMDocumentHandle Content, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRESTClient_Put_1(TElRESTClientHandle _Handle, const char * pcURL, int32_t szURL, TElJsonEntityHandle Content, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRESTClient_get_XMLCanonicalizationMethod(TElRESTClientHandle _Handle, TElXMLCanonicalizationMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRESTClient_set_XMLCanonicalizationMethod(TElRESTClientHandle _Handle, TElXMLCanonicalizationMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElRESTClient_get_XMLCharset(TElRESTClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRESTClient_set_XMLCharset(TElRESTClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElRESTClient_get_JSONIndentChar(TElRESTClientHandle _Handle, char * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRESTClient_set_JSONIndentChar(TElRESTClientHandle _Handle, char Value);
SB_IMPORT uint32_t SB_APIENTRY TElRESTClient_get_JSONCharsPerIndentLevel(TElRESTClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRESTClient_set_JSONCharsPerIndentLevel(TElRESTClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRESTClient_get_ResponseType(TElRESTClientHandle _Handle, TSBRESTResponseTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRESTClient_get_ResponseXML(TElRESTClientHandle _Handle, TElXMLDOMDocumentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRESTClient_get_ResponseJSON(TElRESTClientHandle _Handle, TElJsonEntityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRESTClient_get_ResponseText(TElRESTClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRESTClient_Create(TComponentHandle AOwner, TElRESTClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELRESTCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElRESTClient;
typedef TElRESTClient ElRESTClient;

#ifdef SB_USE_CLASS_TELRESTCLIENT
class TElRESTClient: public TElHTTPSClient
{
	private:
		SB_DISABLE_COPY(TElRESTClient)
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		TElXMLDOMDocument* _Inst_ResponseXML;
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */
#ifdef SB_USE_CLASS_TELJSONENTITY
		TElJsonEntity* _Inst_ResponseJSON;
#endif /* SB_USE_CLASS_TELJSONENTITY */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		int32_t Post(const std::string &URL, TElXMLDOMDocument &Content);

		int32_t Post(const std::string &URL, TElXMLDOMDocument *Content);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELJSONENTITY
		int32_t Post(const std::string &URL, TElJsonEntity &Content);

		int32_t Post(const std::string &URL, TElJsonEntity *Content);
#endif /* SB_USE_CLASS_TELJSONENTITY */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		int32_t Put(const std::string &URL, TElXMLDOMDocument &Content);

		int32_t Put(const std::string &URL, TElXMLDOMDocument *Content);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELJSONENTITY
		int32_t Put(const std::string &URL, TElJsonEntity &Content);

		int32_t Put(const std::string &URL, TElJsonEntity *Content);
#endif /* SB_USE_CLASS_TELJSONENTITY */

		virtual TElXMLCanonicalizationMethod get_XMLCanonicalizationMethod();

		virtual void set_XMLCanonicalizationMethod(TElXMLCanonicalizationMethod Value);

		SB_DECLARE_PROPERTY(TElXMLCanonicalizationMethod, get_XMLCanonicalizationMethod, set_XMLCanonicalizationMethod, TElRESTClient, XMLCanonicalizationMethod);

		virtual void get_XMLCharset(std::string &OutResult);

		virtual void set_XMLCharset(const std::string &Value);

		virtual char get_JSONIndentChar();

		virtual void set_JSONIndentChar(char Value);

		SB_DECLARE_PROPERTY(char, get_JSONIndentChar, set_JSONIndentChar, TElRESTClient, JSONIndentChar);

		virtual int32_t get_JSONCharsPerIndentLevel();

		virtual void set_JSONCharsPerIndentLevel(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_JSONCharsPerIndentLevel, set_JSONCharsPerIndentLevel, TElRESTClient, JSONCharsPerIndentLevel);

		virtual TSBRESTResponseType get_ResponseType();

		SB_DECLARE_PROPERTY_GET(TSBRESTResponseType, get_ResponseType, TElRESTClient, ResponseType);

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual TElXMLDOMDocument* get_ResponseXML();

		SB_DECLARE_PROPERTY_GET(TElXMLDOMDocument*, get_ResponseXML, TElRESTClient, ResponseXML);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELJSONENTITY
		virtual TElJsonEntity* get_ResponseJSON();

		SB_DECLARE_PROPERTY_GET(TElJsonEntity*, get_ResponseJSON, TElRESTClient, ResponseJSON);
#endif /* SB_USE_CLASS_TELJSONENTITY */

		virtual void get_ResponseText(std::string &OutResult);

		TElRESTClient(TElRESTClientHandle handle, TElOwnHandle ownHandle);

		explicit TElRESTClient(TComponent &AOwner);

		explicit TElRESTClient(TComponent *AOwner);

		virtual ~TElRESTClient();

};
#endif /* SB_USE_CLASS_TELRESTCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBRESTCLIENT */

