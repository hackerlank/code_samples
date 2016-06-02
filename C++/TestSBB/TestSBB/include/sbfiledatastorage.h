#ifndef __INC_SBFILEDATASTORAGE
#define __INC_SBFILEDATASTORAGE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstreams.h"
#include "sbdatastorage.h"
#include "sbcustomfsadapter.h"
#include "sbdiskfsadapter.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElFileDataStorageObjectHandle;

typedef TElClassHandle TElFileDataStorageHandle;

typedef uint8_t TSBFileDataStorageConditionRaw;

typedef enum
{
	fdscETag = 0,
	fdscModTime = 1
} TSBFileDataStorageCondition;

typedef uint32_t TSBFileDataStorageConditionsRaw;

typedef enum 
{
	f_fdscETag = 1,
	f_fdscModTime = 2
} TSBFileDataStorageConditions;

#ifdef SB_USE_CLASS_TELFILEDATASTORAGEOBJECT
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorageObject_Assign(TElFileDataStorageObjectHandle _Handle, TElCustomDataStorageObjectHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorageObject_Clone(TElFileDataStorageObjectHandle _Handle, TElCustomDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorageObject_get_Size(TElFileDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorageObject_get_ModificationTime(TElFileDataStorageObjectHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorageObject_get_ETag(TElFileDataStorageObjectHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorageObject_Create(TElFileDataStorageObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELFILEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELFILEDATASTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_AcquireObject(TElFileDataStorageHandle _Handle, const char * pcObjName, int32_t szObjName, TElFileDataStorageObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_WriteObject(TElFileDataStorageHandle _Handle, const char * pcObjName, int32_t szObjName, const char * pcData, int32_t szData, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_WriteObject_1(TElFileDataStorageHandle _Handle, const char * pcObjName, int32_t szObjName, TStreamHandle Strm, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_WriteObject_2(TElFileDataStorageHandle _Handle, const char * pcObjName, int32_t szObjName, TStreamHandle Strm, const uint8_t pETag[], int32_t szETag, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_WriteObject_3(TElFileDataStorageHandle _Handle, const char * pcObjName, int32_t szObjName, TStreamHandle Strm, const uint8_t pETag[], int32_t szETag, TElCustomDataStorageSecurityHandlerHandle Handler, uint8_t pNewETag[], int32_t * szNewETag);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_WriteObject_4(TElFileDataStorageHandle _Handle, TElFileDataStorageObjectHandle Obj, TStreamHandle Strm, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_WriteObject_5(TElFileDataStorageHandle _Handle, TElFileDataStorageObjectHandle Obj, TStreamHandle Strm, const uint8_t pETag[], int32_t szETag, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_WriteBlock(TElFileDataStorageHandle _Handle, const char * pcObjName, int32_t szObjName, TStreamHandle Strm, TElCustomDataStorageSecurityHandlerHandle Handler, int64_t Offset, int64_t * Written);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_ReadObject(TElFileDataStorageHandle _Handle, const char * pcObjName, int32_t szObjName, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_ReadObject_1(TElFileDataStorageHandle _Handle, const char * pcObjName, int32_t szObjName, TStreamHandle Strm, const uint8_t pETag[], int32_t szETag);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_ReadObject_2(TElFileDataStorageHandle _Handle, TElFileDataStorageObjectHandle Obj, TStreamHandle Strm);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_ReadObject_3(TElFileDataStorageHandle _Handle, TElFileDataStorageObjectHandle Obj, TStreamHandle Strm, const uint8_t pETag[], int32_t szETag);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_CopyObject(TElFileDataStorageHandle _Handle, const char * pcSrcObjName, int32_t szSrcObjName, const char * pcDestObjName, int32_t szDestObjName, TElCustomDataStorageSecurityHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_DeleteObject(TElFileDataStorageHandle _Handle, const char * pcObjName, int32_t szObjName);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_DeleteObject_1(TElFileDataStorageHandle _Handle, const char * pcObjName, int32_t szObjName, const uint8_t pETag[], int32_t szETag);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_ObjectExists(TElFileDataStorageHandle _Handle, const char * pcObjName, int32_t szObjName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_GetProtectionInfo(TElFileDataStorageHandle _Handle, const char * pcObjName, int32_t szObjName, TElCustomDataStorageSecurityHandlerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_get_DataFileExtension(TElFileDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_set_DataFileExtension(TElFileDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_get_Directory(TElFileDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_set_Directory(TElFileDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_get_EmbeddedMetadataMode(TElFileDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_set_EmbeddedMetadataMode(TElFileDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_get_FileSystemAdapter(TElFileDataStorageHandle _Handle, TElCustomFileSystemAdapterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_set_FileSystemAdapter(TElFileDataStorageHandle _Handle, TElCustomFileSystemAdapterHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_get_MedataFileExtension(TElFileDataStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_set_MedataFileExtension(TElFileDataStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_get_Overwrite(TElFileDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_set_Overwrite(TElFileDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_get_PassthroughMode(TElFileDataStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_set_PassthroughMode(TElFileDataStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFileDataStorage_Create(TComponentHandle AOwner, TElFileDataStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELFILEDATASTORAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElFileDataStorageObject;
class TElFileDataStorage;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBFileDataStorageConditions)

#ifdef SB_USE_CLASS_TELFILEDATASTORAGEOBJECT
class TElFileDataStorageObject: public TElCustomDataStorageObject
{
	private:
		SB_DISABLE_COPY(TElFileDataStorageObject)
	public:
		virtual void Assign(TElCustomDataStorageObject &Source);

		virtual void Assign(TElCustomDataStorageObject *Source);

		virtual TElCustomDataStorageObjectHandle Clone();

		virtual int64_t get_Size();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Size, TElFileDataStorageObject, Size);

		virtual int64_t get_ModificationTime();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ModificationTime, TElFileDataStorageObject, ModificationTime);

		virtual void get_ETag(std::vector<uint8_t> &OutResult);

		TElFileDataStorageObject(TElFileDataStorageObjectHandle handle, TElOwnHandle ownHandle);

		TElFileDataStorageObject();

};
#endif /* SB_USE_CLASS_TELFILEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELFILEDATASTORAGE
class TElFileDataStorage: public TElCustomDataStorage
{
	private:
		SB_DISABLE_COPY(TElFileDataStorage)
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		TElCustomFileSystemAdapter* _Inst_FileSystemAdapter;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELFILEDATASTORAGEOBJECT
		TElFileDataStorageObjectHandle AcquireObject(const std::string &ObjName);
#endif /* SB_USE_CLASS_TELFILEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
		void WriteObject(const std::string &ObjName, const std::string &Data, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &ObjName, const std::string &Data, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void WriteObject(const std::string &ObjName, TStream &Strm, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &ObjName, TStream *Strm, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void WriteObject(const std::string &ObjName, TStream &Strm, const std::vector<uint8_t> &ETag, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(const std::string &ObjName, TStream *Strm, const std::vector<uint8_t> &ETag, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void WriteObject(const std::string &ObjName, TStream &Strm, const std::vector<uint8_t> &ETag, TElCustomDataStorageSecurityHandler &Handler, std::vector<uint8_t> &NewETag);

		void WriteObject(const std::string &ObjName, TStream *Strm, const std::vector<uint8_t> &ETag, TElCustomDataStorageSecurityHandler *Handler, std::vector<uint8_t> &NewETag);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELFILEDATASTORAGEOBJECT_AND_TSTREAM
		void WriteObject(TElFileDataStorageObject &Obj, TStream &Strm, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(TElFileDataStorageObject *Obj, TStream *Strm, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELFILEDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELFILEDATASTORAGEOBJECT_AND_TSTREAM
		void WriteObject(TElFileDataStorageObject &Obj, TStream &Strm, const std::vector<uint8_t> &ETag, TElCustomDataStorageSecurityHandler &Handler);

		void WriteObject(TElFileDataStorageObject *Obj, TStream *Strm, const std::vector<uint8_t> &ETag, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELFILEDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
		void WriteBlock(const std::string &ObjName, TStream &Strm, TElCustomDataStorageSecurityHandler &Handler, int64_t Offset, int64_t &Written);

		void WriteBlock(const std::string &ObjName, TStream *Strm, TElCustomDataStorageSecurityHandler *Handler, int64_t Offset, int64_t &Written);
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadObject(const std::string &ObjName, TStream &Strm);

		void ReadObject(const std::string &ObjName, TStream *Strm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ReadObject(const std::string &ObjName, TStream &Strm, const std::vector<uint8_t> &ETag);

		void ReadObject(const std::string &ObjName, TStream *Strm, const std::vector<uint8_t> &ETag);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELFILEDATASTORAGEOBJECT_AND_TSTREAM
		void ReadObject(TElFileDataStorageObject &Obj, TStream &Strm);

		void ReadObject(TElFileDataStorageObject *Obj, TStream *Strm);
#endif /* SB_USE_CLASSES_TELFILEDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELFILEDATASTORAGEOBJECT_AND_TSTREAM
		void ReadObject(TElFileDataStorageObject &Obj, TStream &Strm, const std::vector<uint8_t> &ETag);

		void ReadObject(TElFileDataStorageObject *Obj, TStream *Strm, const std::vector<uint8_t> &ETag);
#endif /* SB_USE_CLASSES_TELFILEDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
		void CopyObject(const std::string &SrcObjName, const std::string &DestObjName, TElCustomDataStorageSecurityHandler &Handler);

		void CopyObject(const std::string &SrcObjName, const std::string &DestObjName, TElCustomDataStorageSecurityHandler *Handler);
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

		void DeleteObject(const std::string &ObjName);

		void DeleteObject(const std::string &ObjName, const std::vector<uint8_t> &ETag);

		bool ObjectExists(const std::string &ObjName);

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
		TElCustomDataStorageSecurityHandlerHandle GetProtectionInfo(const std::string &ObjName);
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

		virtual void get_DataFileExtension(std::string &OutResult);

		virtual void set_DataFileExtension(const std::string &Value);

		virtual void get_Directory(std::string &OutResult);

		virtual void set_Directory(const std::string &Value);

		virtual bool get_EmbeddedMetadataMode();

		virtual void set_EmbeddedMetadataMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EmbeddedMetadataMode, set_EmbeddedMetadataMode, TElFileDataStorage, EmbeddedMetadataMode);

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		virtual TElCustomFileSystemAdapter* get_FileSystemAdapter();

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter &Value);

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter *Value);

		SB_DECLARE_PROPERTY(TElCustomFileSystemAdapter*, get_FileSystemAdapter, set_FileSystemAdapter, TElFileDataStorage, FileSystemAdapter);
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

		virtual void get_MedataFileExtension(std::string &OutResult);

		virtual void set_MedataFileExtension(const std::string &Value);

		virtual bool get_Overwrite();

		virtual void set_Overwrite(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Overwrite, set_Overwrite, TElFileDataStorage, Overwrite);

		virtual bool get_PassthroughMode();

		virtual void set_PassthroughMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PassthroughMode, set_PassthroughMode, TElFileDataStorage, PassthroughMode);

		TElFileDataStorage(TElFileDataStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElFileDataStorage(TComponent &AOwner);

		explicit TElFileDataStorage(TComponent *AOwner);

		virtual ~TElFileDataStorage();

};
#endif /* SB_USE_CLASS_TELFILEDATASTORAGE */

#ifdef SB_USE_GLOBAL_PROCS_FILEDATASTORAGE

void ComposeETag(int64_t ModTime, int64_t Size, std::vector<uint8_t> &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_FILEDATASTORAGE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_FILEDATASTORAGE
SB_IMPORT uint32_t SB_APIENTRY SBFileDataStorage_ComposeETag(int64_t ModTime, int64_t Size, uint8_t pOutResult[], int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_FILEDATASTORAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBFILEDATASTORAGE */

