#ifndef __INC_SBVCARD
#define __INC_SBVCARD

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstringlist.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbdictionary.h"
#include "sbstreams.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_VCARDCAL_ERROR_VERSION 	1
#define SB_VCARDCAL_ERROR_FORMAT 	2
#define SB_VCARDCAL_ERROR_INTERNAL 	3
#define SB_VCARDCAL_ERROR_NON_EXPANDABLE 	4
#define SB_VCARDCAL_ERROR_UNSUPPORTED_VERSION 	5
#define SB_VCARDCAL_VERSION_UNKNOWN 	-1
#define SB_VCARDCAL_VERSION_2_1 	0
#define SB_VCARDCAL_VERSION_3_0 	1
#define SB_VCARDCAL_VERSION_4_0 	2

typedef TElClassHandle TElDirInfoAttributeHandle;

typedef TElClassHandle TElDirInfoPropertyHandle;

typedef TElClassHandle TElDirInfoPropertiesListHandle;

typedef TElClassHandle TElDirInfoHandle;

typedef TElClassHandle TElVCardHandle;

typedef TElClassHandle TElVCalendarHandle;

#ifdef SB_USE_CLASS_TELDIRINFOATTRIBUTE
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoAttribute_get_Name(TElDirInfoAttributeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoAttribute_set_Name(TElDirInfoAttributeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoAttribute_get_Value(TElDirInfoAttributeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoAttribute_set_Value(TElDirInfoAttributeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoAttribute_Create(TElDirInfoAttributeHandle * OutResult);
#endif /* SB_USE_CLASS_TELDIRINFOATTRIBUTE */

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoProperty_AddAttribute(TElDirInfoPropertyHandle _Handle, TElDirInfoAttributeHandle Attr);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoProperty_RemoveAttribute(TElDirInfoPropertyHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoProperty_AttributeByName(TElDirInfoPropertyHandle _Handle, const char * pcName, int32_t szName, TElDirInfoAttributeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoProperty_get_Name(TElDirInfoPropertyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoProperty_set_Name(TElDirInfoPropertyHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoProperty_get_Value(TElDirInfoPropertyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoProperty_set_Value(TElDirInfoPropertyHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoProperty_get_FullName(TElDirInfoPropertyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoProperty_get_Attributes(TElDirInfoPropertyHandle _Handle, int32_t Index, TElDirInfoAttributeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoProperty_get_AttributeCount(TElDirInfoPropertyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoProperty_Create(TElDirInfoPropertyHandle * OutResult);
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTIESLIST
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoPropertiesList_Clear(TElDirInfoPropertiesListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoPropertiesList_Add(TElDirInfoPropertiesListHandle _Handle, TElDirInfoPropertyHandle Prop);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoPropertiesList_Insert(TElDirInfoPropertiesListHandle _Handle, int32_t Index, TElDirInfoPropertyHandle Prop);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoPropertiesList_Remove(TElDirInfoPropertiesListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoPropertiesList_get_SubProperties(TElDirInfoPropertiesListHandle _Handle, int32_t Index, TElDirInfoPropertyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoPropertiesList_get_SubPropertyCount(TElDirInfoPropertiesListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoPropertiesList_get_IsSingle(TElDirInfoPropertiesListHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoPropertiesList_get_SingleProperty(TElDirInfoPropertiesListHandle _Handle, TElDirInfoPropertyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfoPropertiesList_Create(TElDirInfoPropertiesListHandle * OutResult);
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTIESLIST */

#ifdef SB_USE_CLASS_TELDIRINFO
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_LoadFromStream(TElDirInfoHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_SaveToStream(TElDirInfoHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_LoadFromFile(TElDirInfoHandle _Handle, const char * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_SaveToFile(TElDirInfoHandle _Handle, const char * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_ToString(TElDirInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_AddSection(TElDirInfoHandle _Handle, const char * pcName, int32_t szName, TElDirInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_AddSection_1(TElDirInfoHandle _Handle, TElDirInfoHandle Sect);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_RemoveSection(TElDirInfoHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_AddProperty(TElDirInfoHandle _Handle, TElDirInfoPropertyHandle Prop);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_InsertProperty(TElDirInfoHandle _Handle, int32_t Index, TElDirInfoPropertyHandle Prop);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_RemoveProperty(TElDirInfoHandle _Handle, const char * pcName, int32_t szName);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_RemoveAndAddProperty(TElDirInfoHandle _Handle, TElDirInfoPropertyHandle Prop);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_GetPropertyNames(TElDirInfoHandle _Handle, TStringListHandle OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_SectionByName(TElDirInfoHandle _Handle, const char * pcName, int32_t szName, TElDirInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_GetPropertyValue(TElDirInfoHandle _Handle, const char * pcName, int32_t szName, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_SetPropertyValue(TElDirInfoHandle _Handle, const char * pcName, int32_t szName, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_get_Parent(TElDirInfoHandle _Handle, TElDirInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_set_Parent(TElDirInfoHandle _Handle, TElDirInfoHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_get_Name(TElDirInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_set_Name(TElDirInfoHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_get_Include(TElDirInfoHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_get_Include(TElDirInfoHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_get_FullPath(TElDirInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_get_FullPathEx(TElDirInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_get_GenerateUID(TElDirInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_set_GenerateUID(TElDirInfoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_get_Properties(TElDirInfoHandle _Handle, const char * pcIndex, int32_t szIndex, TElDirInfoPropertiesListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_get_PropertyCount(TElDirInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_get_Sections(TElDirInfoHandle _Handle, int32_t Index, TElDirInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_get_SectionCount(TElDirInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDirInfo_Create(TElDirInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELDIRINFO */

#ifdef SB_USE_CLASS_TELVCARD
SB_IMPORT uint32_t SB_APIENTRY TElVCard_get_Version(TElVCardHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElVCard_set_Version(TElVCardHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElVCard_Create(TElVCardHandle * OutResult);
#endif /* SB_USE_CLASS_TELVCARD */

#ifdef SB_USE_CLASS_TELVCALENDAR
SB_IMPORT uint32_t SB_APIENTRY TElVCalendar_Create(TElVCalendarHandle * OutResult);
#endif /* SB_USE_CLASS_TELVCALENDAR */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElDirInfoAttribute;
class TElDirInfoProperty;
class TElDirInfoPropertiesList;
class TElDirInfo;
class TElVCard;
class TElVCalendar;

#ifdef SB_USE_CLASS_TELDIRINFOATTRIBUTE
class TElDirInfoAttribute: public TObject
{
	private:
		SB_DISABLE_COPY(TElDirInfoAttribute)
	public:
		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual void get_Value(std::string &OutResult);

		virtual void set_Value(const std::string &Value);

		TElDirInfoAttribute(TElDirInfoAttributeHandle handle, TElOwnHandle ownHandle);

		TElDirInfoAttribute();

};
#endif /* SB_USE_CLASS_TELDIRINFOATTRIBUTE */

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
class TElDirInfoProperty: public TObject
{
	private:
		SB_DISABLE_COPY(TElDirInfoProperty)
#ifdef SB_USE_CLASS_TELDIRINFOATTRIBUTE
		TElDirInfoAttribute* _Inst_Attributes;
#endif /* SB_USE_CLASS_TELDIRINFOATTRIBUTE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELDIRINFOATTRIBUTE
		void AddAttribute(TElDirInfoAttribute &Attr);

		void AddAttribute(TElDirInfoAttribute *Attr);
#endif /* SB_USE_CLASS_TELDIRINFOATTRIBUTE */

		void RemoveAttribute(int32_t Index);

#ifdef SB_USE_CLASS_TELDIRINFOATTRIBUTE
		TElDirInfoAttributeHandle AttributeByName(const std::string &Name);
#endif /* SB_USE_CLASS_TELDIRINFOATTRIBUTE */

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual void get_Value(std::string &OutResult);

		virtual void set_Value(const std::string &Value);

		virtual void get_FullName(std::string &OutResult);

#ifdef SB_USE_CLASS_TELDIRINFOATTRIBUTE
		virtual TElDirInfoAttribute* get_Attributes(int32_t Index);
#endif /* SB_USE_CLASS_TELDIRINFOATTRIBUTE */

		virtual int32_t get_AttributeCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AttributeCount, TElDirInfoProperty, AttributeCount);

		TElDirInfoProperty(TElDirInfoPropertyHandle handle, TElOwnHandle ownHandle);

		TElDirInfoProperty();

		virtual ~TElDirInfoProperty();

};
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTIESLIST
class TElDirInfoPropertiesList: public TObject
{
	private:
		SB_DISABLE_COPY(TElDirInfoPropertiesList)
#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
		TElDirInfoProperty* _Inst_SubProperties;
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */
#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
		TElDirInfoProperty* _Inst_SingleProperty;
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */

		void initInstances();

	public:
		void Clear();

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
		void Add(TElDirInfoProperty &Prop);

		void Add(TElDirInfoProperty *Prop);
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
		void Insert(int32_t Index, TElDirInfoProperty &Prop);

		void Insert(int32_t Index, TElDirInfoProperty *Prop);
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */

		void Remove(int32_t Index);

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
		virtual TElDirInfoProperty* get_SubProperties(int32_t Index);
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */

		virtual int32_t get_SubPropertyCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SubPropertyCount, TElDirInfoPropertiesList, SubPropertyCount);

		virtual bool get_IsSingle();

		SB_DECLARE_PROPERTY_GET(bool, get_IsSingle, TElDirInfoPropertiesList, IsSingle);

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
		virtual TElDirInfoProperty* get_SingleProperty();

		SB_DECLARE_PROPERTY_GET(TElDirInfoProperty*, get_SingleProperty, TElDirInfoPropertiesList, SingleProperty);
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */

		TElDirInfoPropertiesList(TElDirInfoPropertiesListHandle handle, TElOwnHandle ownHandle);

		TElDirInfoPropertiesList();

		virtual ~TElDirInfoPropertiesList();

};
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTIESLIST */

#ifdef SB_USE_CLASS_TELDIRINFO
class TElDirInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElDirInfo)
		TElDirInfo* _Inst_Parent;
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Include;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Include;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELDIRINFOPROPERTIESLIST
		TElDirInfoPropertiesList* _Inst_Properties;
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTIESLIST */
		TElDirInfo* _Inst_Sections;

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromStream(TStream &Stream);

		void LoadFromStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToStream(TStream &Stream);

		void SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		void LoadFromFile(const std::string &FileName);

		void SaveToFile(const std::string &FileName);

		void ToString(std::string &OutResult);

		TElDirInfoHandle AddSection(const std::string &Name);

		void AddSection(TElDirInfo &Sect);

		void AddSection(TElDirInfo *Sect);

		void RemoveSection(int32_t Index);

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
		void AddProperty(TElDirInfoProperty &Prop);

		void AddProperty(TElDirInfoProperty *Prop);
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
		void InsertProperty(int32_t Index, TElDirInfoProperty &Prop);

		void InsertProperty(int32_t Index, TElDirInfoProperty *Prop);
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */

		void RemoveProperty(const std::string &Name);

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTY
		void RemoveAndAddProperty(TElDirInfoProperty &Prop);

		void RemoveAndAddProperty(TElDirInfoProperty *Prop);
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTY */

#ifdef SB_USE_CLASS_TSTRINGLIST
		void GetPropertyNames(TStringList &OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		TElDirInfoHandle SectionByName(const std::string &Name);

		void GetPropertyValue(const std::string &Name, std::string &OutResult);

		void SetPropertyValue(const std::string &Name, const std::string &Value);

		virtual TElDirInfo* get_Parent();

		virtual void set_Parent(TElDirInfo &Value);

		virtual void set_Parent(TElDirInfo *Value);

		SB_DECLARE_PROPERTY(TElDirInfo*, get_Parent, set_Parent, TElDirInfo, Parent);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Include();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Include, TElDirInfo, Include);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Include();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Include, TElDirInfo, Include);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_FullPath(std::string &OutResult);

		virtual void get_FullPathEx(std::string &OutResult);

		virtual bool get_GenerateUID();

		virtual void set_GenerateUID(bool Value);

		SB_DECLARE_PROPERTY(bool, get_GenerateUID, set_GenerateUID, TElDirInfo, GenerateUID);

#ifdef SB_USE_CLASS_TELDIRINFOPROPERTIESLIST
		virtual TElDirInfoPropertiesList* get_Properties(const std::string &Index);
#endif /* SB_USE_CLASS_TELDIRINFOPROPERTIESLIST */

		virtual int32_t get_PropertyCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_PropertyCount, TElDirInfo, PropertyCount);

		virtual TElDirInfo* get_Sections(int32_t Index);

		virtual int32_t get_SectionCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SectionCount, TElDirInfo, SectionCount);

		TElDirInfo(TElDirInfoHandle handle, TElOwnHandle ownHandle);

		TElDirInfo();

		virtual ~TElDirInfo();

};
#endif /* SB_USE_CLASS_TELDIRINFO */

#ifdef SB_USE_CLASS_TELVCARD
class TElVCard: public TElDirInfo
{
	private:
		SB_DISABLE_COPY(TElVCard)
	public:
		virtual int32_t get_Version();

		virtual void set_Version(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Version, set_Version, TElVCard, Version);

		TElVCard(TElVCardHandle handle, TElOwnHandle ownHandle);

		TElVCard();

};
#endif /* SB_USE_CLASS_TELVCARD */

#ifdef SB_USE_CLASS_TELVCALENDAR
class TElVCalendar: public TElDirInfo
{
	private:
		SB_DISABLE_COPY(TElVCalendar)
	public:
		TElVCalendar(TElVCalendarHandle handle, TElOwnHandle ownHandle);

		TElVCalendar();

};
#endif /* SB_USE_CLASS_TELVCALENDAR */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBVCARD */
