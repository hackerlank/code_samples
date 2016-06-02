#ifndef __INC_SBSIMPLEMIME
#define __INC_SBSIMPLEMIME

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbstreams.h"
#include "sbmime.h"
#include "sbdomainkeys.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElSimpleMIMEAttachmentHandle;

typedef TElSimpleMIMEAttachmentHandle ElSimpleMIMEAttachmentHandle;

typedef TElClassHandle TElSimpleMIMEMessageHandle;

typedef TElSimpleMIMEMessageHandle ElSimpleMIMEMessageHandle;

#ifdef SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEAttachment_AttachFile(TElSimpleMIMEAttachmentHandle _Handle, const char * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEAttachment_get_ContentDisposition(TElSimpleMIMEAttachmentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEAttachment_set_ContentDisposition(TElSimpleMIMEAttachmentHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEAttachment_get_ContentId(TElSimpleMIMEAttachmentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEAttachment_set_ContentId(TElSimpleMIMEAttachmentHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEAttachment_get_ContentStream(TElSimpleMIMEAttachmentHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEAttachment_set_ContentStream(TElSimpleMIMEAttachmentHandle _Handle, TStreamHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEAttachment_get_ContentType(TElSimpleMIMEAttachmentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEAttachment_set_ContentType(TElSimpleMIMEAttachmentHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEAttachment_get_Name(TElSimpleMIMEAttachmentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEAttachment_set_Name(TElSimpleMIMEAttachmentHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEAttachment_get_DisposeStream(TElSimpleMIMEAttachmentHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEAttachment_set_DisposeStream(TElSimpleMIMEAttachmentHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEAttachment_Create(TElSimpleMIMEAttachmentHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT */

#ifdef SB_USE_CLASS_TELSIMPLEMIMEMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_AddAttachment(TElSimpleMIMEMessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_DeleteAttachment(TElSimpleMIMEMessageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_IndexOfAttachment(TElSimpleMIMEMessageHandle _Handle, TElSimpleMIMEAttachmentHandle Attachment, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_RemoveAttachment(TElSimpleMIMEMessageHandle _Handle, TElSimpleMIMEAttachmentHandle Attachment);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_SaveToStream(TElSimpleMIMEMessageHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_SaveToText(TElSimpleMIMEMessageHandle _Handle, TStringsHandle Text);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_Attachments(TElSimpleMIMEMessageHandle _Handle, int32_t Index, TElSimpleMIMEAttachmentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_AttachEncoding(TElSimpleMIMEMessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_AttachEncoding(TElSimpleMIMEMessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_AttachmentCount(TElSimpleMIMEMessageHandle _Handle, int32_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_BCC(TElSimpleMIMEMessageHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_BCC(TElSimpleMIMEMessageHandle _Handle, TStringListHandle Value);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_BCC(TElSimpleMIMEMessageHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_BCC(TElSimpleMIMEMessageHandle _Handle, TElStringListHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_BodyEncoding(TElSimpleMIMEMessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_BodyEncoding(TElSimpleMIMEMessageHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_BodyHTML(TElSimpleMIMEMessageHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_BodyHTML(TElSimpleMIMEMessageHandle _Handle, TStringListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_BodyPlain(TElSimpleMIMEMessageHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_BodyPlain(TElSimpleMIMEMessageHandle _Handle, TStringListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_CC(TElSimpleMIMEMessageHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_CC(TElSimpleMIMEMessageHandle _Handle, TStringListHandle Value);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_BodyHTML(TElSimpleMIMEMessageHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_BodyHTML(TElSimpleMIMEMessageHandle _Handle, TElStringListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_BodyPlain(TElSimpleMIMEMessageHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_BodyPlain(TElSimpleMIMEMessageHandle _Handle, TElStringListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_CC(TElSimpleMIMEMessageHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_CC(TElSimpleMIMEMessageHandle _Handle, TElStringListHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_Charset(TElSimpleMIMEMessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_Charset(TElSimpleMIMEMessageHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_CustomHeaders(TElSimpleMIMEMessageHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_CustomHeaders(TElSimpleMIMEMessageHandle _Handle, TStringListHandle Value);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_CustomHeaders(TElSimpleMIMEMessageHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_CustomHeaders(TElSimpleMIMEMessageHandle _Handle, TElStringListHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_DomainKeysSigner(TElSimpleMIMEMessageHandle _Handle, TElDomainKeysSignerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_DomainKeysSigner(TElSimpleMIMEMessageHandle _Handle, TElDomainKeysSignerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_From(TElSimpleMIMEMessageHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_From(TElSimpleMIMEMessageHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_HeaderEncoding(TElSimpleMIMEMessageHandle _Handle, TElHeaderEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_HeaderEncoding(TElSimpleMIMEMessageHandle _Handle, TElHeaderEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_InReplyTo(TElSimpleMIMEMessageHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_InReplyTo(TElSimpleMIMEMessageHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_IsHTML(TElSimpleMIMEMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_IsHTML(TElSimpleMIMEMessageHandle _Handle, int8_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_To_(TElSimpleMIMEMessageHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_To_(TElSimpleMIMEMessageHandle _Handle, TStringListHandle Value);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_To_(TElSimpleMIMEMessageHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_To_(TElSimpleMIMEMessageHandle _Handle, TElStringListHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_Priority(TElSimpleMIMEMessageHandle _Handle, TElMIMEMessagePriorityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_Priority(TElSimpleMIMEMessageHandle _Handle, TElMIMEMessagePriorityRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_RequestDeliveryReceipt(TElSimpleMIMEMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_RequestDeliveryReceipt(TElSimpleMIMEMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_RequestReadReceipt(TElSimpleMIMEMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_RequestReadReceipt(TElSimpleMIMEMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_ReplyTo(TElSimpleMIMEMessageHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_ReplyTo(TElSimpleMIMEMessageHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_Sender(TElSimpleMIMEMessageHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_Sender(TElSimpleMIMEMessageHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_get_Subject(TElSimpleMIMEMessageHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_set_Subject(TElSimpleMIMEMessageHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleMIMEMessage_Create(TComponentHandle AOwner, TElSimpleMIMEMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIMPLEMIMEMESSAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSimpleMIMEAttachment;
typedef TElSimpleMIMEAttachment ElSimpleMIMEAttachment;
class TElSimpleMIMEMessage;
typedef TElSimpleMIMEMessage ElSimpleMIMEMessage;

#ifdef SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT
class TElSimpleMIMEAttachment: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElSimpleMIMEAttachment)
#ifdef SB_USE_CLASS_TSTREAM
		TStream* _Inst_ContentStream;
#endif /* SB_USE_CLASS_TSTREAM */

		void initInstances();

	public:
		void AttachFile(const std::string &FileName);

		virtual void get_ContentDisposition(std::string &OutResult);

		virtual void set_ContentDisposition(const std::string &Value);

		virtual void get_ContentId(std::string &OutResult);

		virtual void set_ContentId(const std::string &Value);

#ifdef SB_USE_CLASS_TSTREAM
		virtual TStream* get_ContentStream();

		virtual void set_ContentStream(TStream &Value);

		virtual void set_ContentStream(TStream *Value);

		SB_DECLARE_PROPERTY(TStream*, get_ContentStream, set_ContentStream, TElSimpleMIMEAttachment, ContentStream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void get_ContentType(std::string &OutResult);

		virtual void set_ContentType(const std::string &Value);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual bool get_DisposeStream();

		virtual void set_DisposeStream(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DisposeStream, set_DisposeStream, TElSimpleMIMEAttachment, DisposeStream);

		TElSimpleMIMEAttachment(TElSimpleMIMEAttachmentHandle handle, TElOwnHandle ownHandle);

		TElSimpleMIMEAttachment();

		virtual ~TElSimpleMIMEAttachment();

};
#endif /* SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT */

#ifdef SB_USE_CLASS_TELSIMPLEMIMEMESSAGE
class TElSimpleMIMEMessage: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSimpleMIMEMessage)
#ifdef SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT
		TElSimpleMIMEAttachment* _Inst_Attachments;
#endif /* SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_BCC;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_BodyHTML;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_BodyPlain;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_CC;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_CustomHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_BCC;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_BodyHTML;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_BodyPlain;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_CC;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_CustomHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELDOMAINKEYSSIGNER
		TElDomainKeysSigner* _Inst_DomainKeysSigner;
#endif /* SB_USE_CLASS_TELDOMAINKEYSSIGNER */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_To_;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_To_;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		int32_t AddAttachment();

		void DeleteAttachment(int32_t Index);

#ifdef SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT
		int32_t IndexOfAttachment(TElSimpleMIMEAttachment &Attachment);

		int32_t IndexOfAttachment(TElSimpleMIMEAttachment *Attachment);
#endif /* SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT */

#ifdef SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT
		void RemoveAttachment(TElSimpleMIMEAttachment &Attachment);

		void RemoveAttachment(TElSimpleMIMEAttachment *Attachment);
#endif /* SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToStream(TStream &Stream);

		void SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTRINGS
		void SaveToText(TStrings &Text);

		void SaveToText(TStrings *Text);
#endif /* SB_USE_CLASS_TSTRINGS */

#ifdef SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT
		virtual TElSimpleMIMEAttachment* get_Attachments(int32_t Index);
#endif /* SB_USE_CLASS_TELSIMPLEMIMEATTACHMENT */

		virtual void get_AttachEncoding(std::string &OutResult);

		virtual void set_AttachEncoding(const std::string &Value);

		virtual int32_t get_AttachmentCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AttachmentCount, TElSimpleMIMEMessage, AttachmentCount);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_BCC();

		virtual void set_BCC(TStringList &Value);

		virtual void set_BCC(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_BCC, set_BCC, TElSimpleMIMEMessage, BCC);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_BCC();

		virtual void set_BCC(TElStringList &Value);

		virtual void set_BCC(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_BCC, set_BCC, TElSimpleMIMEMessage, BCC);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_BodyEncoding(std::string &OutResult);

		virtual void set_BodyEncoding(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_BodyHTML();

		virtual void set_BodyHTML(TStringList &Value);

		virtual void set_BodyHTML(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_BodyHTML, set_BodyHTML, TElSimpleMIMEMessage, BodyHTML);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_BodyHTML();

		virtual void set_BodyHTML(TElStringList &Value);

		virtual void set_BodyHTML(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_BodyHTML, set_BodyHTML, TElSimpleMIMEMessage, BodyHTML);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_BodyPlain();

		virtual void set_BodyPlain(TStringList &Value);

		virtual void set_BodyPlain(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_BodyPlain, set_BodyPlain, TElSimpleMIMEMessage, BodyPlain);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_BodyPlain();

		virtual void set_BodyPlain(TElStringList &Value);

		virtual void set_BodyPlain(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_BodyPlain, set_BodyPlain, TElSimpleMIMEMessage, BodyPlain);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_CC();

		virtual void set_CC(TStringList &Value);

		virtual void set_CC(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_CC, set_CC, TElSimpleMIMEMessage, CC);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_CC();

		virtual void set_CC(TElStringList &Value);

		virtual void set_CC(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_CC, set_CC, TElSimpleMIMEMessage, CC);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_Charset(std::string &OutResult);

		virtual void set_Charset(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_CustomHeaders();

		virtual void set_CustomHeaders(TStringList &Value);

		virtual void set_CustomHeaders(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_CustomHeaders, set_CustomHeaders, TElSimpleMIMEMessage, CustomHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_CustomHeaders();

		virtual void set_CustomHeaders(TElStringList &Value);

		virtual void set_CustomHeaders(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_CustomHeaders, set_CustomHeaders, TElSimpleMIMEMessage, CustomHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELDOMAINKEYSSIGNER
		virtual TElDomainKeysSigner* get_DomainKeysSigner();

		virtual void set_DomainKeysSigner(TElDomainKeysSigner &Value);

		virtual void set_DomainKeysSigner(TElDomainKeysSigner *Value);

		SB_DECLARE_PROPERTY(TElDomainKeysSigner*, get_DomainKeysSigner, set_DomainKeysSigner, TElSimpleMIMEMessage, DomainKeysSigner);
#endif /* SB_USE_CLASS_TELDOMAINKEYSSIGNER */

		virtual void get_From(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_From(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_From(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_From(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual TElHeaderEncoding get_HeaderEncoding();

		virtual void set_HeaderEncoding(TElHeaderEncoding Value);

		SB_DECLARE_PROPERTY(TElHeaderEncoding, get_HeaderEncoding, set_HeaderEncoding, TElSimpleMIMEMessage, HeaderEncoding);

		virtual void get_InReplyTo(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_InReplyTo(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_InReplyTo(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_InReplyTo(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual bool get_IsHTML();

		virtual void set_IsHTML(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IsHTML, set_IsHTML, TElSimpleMIMEMessage, IsHTML);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_To_();

		virtual void set_To_(TStringList &Value);

		virtual void set_To_(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_To_, set_To_, TElSimpleMIMEMessage, To_);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_To_();

		virtual void set_To_(TElStringList &Value);

		virtual void set_To_(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_To_, set_To_, TElSimpleMIMEMessage, To_);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual TElMIMEMessagePriority get_Priority();

		virtual void set_Priority(TElMIMEMessagePriority Value);

		SB_DECLARE_PROPERTY(TElMIMEMessagePriority, get_Priority, set_Priority, TElSimpleMIMEMessage, Priority);

		virtual bool get_RequestDeliveryReceipt();

		virtual void set_RequestDeliveryReceipt(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RequestDeliveryReceipt, set_RequestDeliveryReceipt, TElSimpleMIMEMessage, RequestDeliveryReceipt);

		virtual bool get_RequestReadReceipt();

		virtual void set_RequestReadReceipt(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RequestReadReceipt, set_RequestReadReceipt, TElSimpleMIMEMessage, RequestReadReceipt);

		virtual void get_ReplyTo(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ReplyTo(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ReplyTo(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ReplyTo(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_Sender(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Sender(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Sender(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Sender(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_Subject(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Subject(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Subject(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Subject(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElSimpleMIMEMessage(TElSimpleMIMEMessageHandle handle, TElOwnHandle ownHandle);

		explicit TElSimpleMIMEMessage(TComponent &AOwner);

		explicit TElSimpleMIMEMessage(TComponent *AOwner);

		virtual ~TElSimpleMIMEMessage();

};
#endif /* SB_USE_CLASS_TELSIMPLEMIMEMESSAGE */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSIMPLEMIME */
