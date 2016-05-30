#ifndef __INC_SBDCENC
#define __INC_SBDCENC

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbstreams.h"
#include "sbrdn.h"
#include "sbencoding.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElDCEncodingHandle;

typedef TElClassHandle TElDCNodeHandle;

#ifdef SB_USE_CLASS_TELDCENCODING
SB_IMPORT uint32_t SB_APIENTRY TElDCEncoding_Encode(TElDCEncodingHandle _Handle, TElDCNodeHandle Root, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElDCEncoding_Decode(TElDCEncodingHandle _Handle, TElDCNodeHandle Root, TStreamHandle Stream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElDCEncoding_GetName(TElDCEncodingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCEncoding_GetDescription(TElDCEncodingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCEncoding_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELDCENCODING */

#ifdef SB_USE_CLASS_TELDCNODE
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_AddNode(TElDCNodeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_AddNode_1(TElDCNodeHandle _Handle, const char * pcName, int32_t szName, const char * pcValue, int32_t szValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_AddNode_2(TElDCNodeHandle _Handle, const char * pcName, int32_t szName, int32_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_AddNode_3(TElDCNodeHandle _Handle, const char * pcName, int32_t szName, int8_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_AddNode_4(TElDCNodeHandle _Handle, const char * pcName, int32_t szName, TElRelativeDistinguishedNameHandle Value, const char * pcElemName, int32_t szElemName, int32_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_AddNode_5(TElDCNodeHandle _Handle, const char * pcName, int32_t szName, TStringListHandle Value, const char * pcElemName, int32_t szElemName, int32_t * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_AddNode_5(TElDCNodeHandle _Handle, const char * pcName, int32_t szName, TElStringListHandle Value, const char * pcElemName, int32_t szElemName, int32_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_RemoveNode(TElDCNodeHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_Clear(TElDCNodeHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_ReadString(TElDCNodeHandle _Handle, const char * pcName, int32_t szName, const char * pcDefault, int32_t szDefault, int8_t RaiseExceptionIfNotFound, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_ReadInteger(TElDCNodeHandle _Handle, const char * pcName, int32_t szName, int32_t Default, int8_t RaiseExceptionIfNotFound, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_ReadBoolean(TElDCNodeHandle _Handle, const char * pcName, int32_t szName, int8_t Default, int8_t RaiseExceptionIfNotFound, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_ReadRDN(TElDCNodeHandle _Handle, const char * pcName, int32_t szName, TElRelativeDistinguishedNameHandle Rdn, int8_t RaiseExceptionIfNotFound);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_ReadStringList(TElDCNodeHandle _Handle, const char * pcName, int32_t szName, TStringListHandle Lst, int8_t RaiseExceptionIfNotFound);
#else
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_ReadStringList(TElDCNodeHandle _Handle, const char * pcName, int32_t szName, TElStringListHandle Lst, int8_t RaiseExceptionIfNotFound);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_LoadFromStream(TElDCNodeHandle _Handle, TStreamHandle Stream, int32_t Count, TElDCEncodingHandle Encoding);
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_SaveToStream(TElDCNodeHandle _Handle, TStreamHandle Stream, TElDCEncodingHandle Encoding);
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_get_Nodes(TElDCNodeHandle _Handle, int32_t Index, TElDCNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_get_NodeCount(TElDCNodeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_get_Name(TElDCNodeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_set_Name(TElDCNodeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_get_Value(TElDCNodeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_set_Value(TElDCNodeHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_get_Params(TElDCNodeHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_get_Params(TElDCNodeHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElDCNode_Create(TElDCNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELDCNODE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElDCEncoding;
class TElDCNode;

#ifdef SB_USE_CLASS_TELDCENCODING
class TElDCEncoding: public TObject
{
	private:
		SB_DISABLE_COPY(TElDCEncoding)
	public:
#ifdef SB_USE_CLASSES_TELDCNODE_AND_TSTREAM
		virtual void Encode(TElDCNode &Root, TStream &Stream);

		virtual void Encode(TElDCNode *Root, TStream *Stream);
#endif /* SB_USE_CLASSES_TELDCNODE_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELDCNODE_AND_TSTREAM
		virtual void Decode(TElDCNode &Root, TStream &Stream, int32_t Count);

		virtual void Decode(TElDCNode *Root, TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASSES_TELDCNODE_AND_TSTREAM */

		virtual void GetName(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		TElDCEncoding(TElDCEncodingHandle handle, TElOwnHandle ownHandle);

		TElDCEncoding();

};
#endif /* SB_USE_CLASS_TELDCENCODING */

#ifdef SB_USE_CLASS_TELDCNODE
class TElDCNode: public TObject
{
	private:
		SB_DISABLE_COPY(TElDCNode)
		TElDCNode* _Inst_Nodes;
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Params;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Params;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		int32_t AddNode();

		int32_t AddNode(const std::string &Name, const std::string &Value);

		int32_t AddNode(const std::string &Name, int32_t Value);

		int32_t AddNode(const std::string &Name, bool Value);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		int32_t AddNode(const std::string &Name, TElRelativeDistinguishedName &Value, const std::string &ElemName);

		int32_t AddNode(const std::string &Name, TElRelativeDistinguishedName *Value, const std::string &ElemName);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		int32_t AddNode(const std::string &Name, TStringList &Value, const std::string &ElemName);

		int32_t AddNode(const std::string &Name, TStringList *Value, const std::string &ElemName);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		int32_t AddNode(const std::string &Name, TElStringList &Value, const std::string &ElemName);

		int32_t AddNode(const std::string &Name, TElStringList *Value, const std::string &ElemName);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void RemoveNode(int32_t Index);

		void Clear();

		void ReadString(const std::string &Name, const std::string &Default, bool RaiseExceptionIfNotFound, std::string &OutResult);

		int32_t ReadInteger(const std::string &Name, int32_t Default, bool RaiseExceptionIfNotFound);

		bool ReadBoolean(const std::string &Name, bool Default, bool RaiseExceptionIfNotFound);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		void ReadRDN(const std::string &Name, TElRelativeDistinguishedName &Rdn, bool RaiseExceptionIfNotFound);

		void ReadRDN(const std::string &Name, TElRelativeDistinguishedName *Rdn, bool RaiseExceptionIfNotFound);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void ReadStringList(const std::string &Name, TStringList &Lst, bool RaiseExceptionIfNotFound);

		void ReadStringList(const std::string &Name, TStringList *Lst, bool RaiseExceptionIfNotFound);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void ReadStringList(const std::string &Name, TElStringList &Lst, bool RaiseExceptionIfNotFound);

		void ReadStringList(const std::string &Name, TElStringList *Lst, bool RaiseExceptionIfNotFound);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM
		void LoadFromStream(TStream &Stream, int32_t Count, TElDCEncoding &Encoding);

		void LoadFromStream(TStream *Stream, int32_t Count, TElDCEncoding *Encoding);
#endif /* SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM
		void SaveToStream(TStream &Stream, TElDCEncoding &Encoding);

		void SaveToStream(TStream *Stream, TElDCEncoding *Encoding);
#endif /* SB_USE_CLASSES_TELDCENCODING_AND_TSTREAM */

		virtual TElDCNode* get_Nodes(int32_t Index);

		virtual int32_t get_NodeCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_NodeCount, TElDCNode, NodeCount);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual void get_Value(std::string &OutResult);

		virtual void set_Value(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Params();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Params, TElDCNode, Params);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Params();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Params, TElDCNode, Params);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		TElDCNode(TElDCNodeHandle handle, TElOwnHandle ownHandle);

		TElDCNode();

		virtual ~TElDCNode();

};
#endif /* SB_USE_CLASS_TELDCNODE */

#ifdef SB_USE_GLOBAL_PROCS_DCENC

#ifdef SB_USE_CLASS_TELDCENCODING
void SetDefaultDCEncoding(TElDCEncoding &Value);
void SetDefaultDCEncoding(TElDCEncoding *Value);
#endif /* SB_USE_CLASS_TELDCENCODING */

#ifdef SB_USE_CLASS_TELDCENCODING
TElDCEncodingHandle GetDefaultDCEncoding();
#endif /* SB_USE_CLASS_TELDCENCODING */

#endif /* SB_USE_GLOBAL_PROCS_DCENC */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_DCENC
SB_IMPORT uint32_t SB_APIENTRY SBDCEnc_SetDefaultDCEncoding(TElDCEncodingHandle Value);
SB_IMPORT uint32_t SB_APIENTRY SBDCEnc_GetDefaultDCEncoding(TElDCEncodingHandle * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_DCENC */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDCENC */
