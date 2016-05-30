#ifndef __INC_SBTARENTITIES
#define __INC_SBTARENTITIES

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbtarutils.h"
#include "sbstreams.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElTarFileHeaderHandle;

typedef TElClassHandle TElBaseTarHeaderHandle;

typedef TElClassHandle TElUStarTarHeaderHandle;

typedef TElClassHandle TElTarProcessorHandle;

typedef void (SB_CALLBACK *TSBTarFileHeaderLoadedEvent)(void * _ObjectData, TObjectHandle Sender, TElTarFileHeaderHandle Header);

typedef void (SB_CALLBACK *TSBTarArchiveErrorEvent)(void * _ObjectData, TObjectHandle Sender, int32_t ErrorCode, const char * pcErrorMessage, int32_t szErrorMessage, int8_t * TryContinue);

#ifdef SB_USE_CLASS_TELTARFILEHEADER
SB_IMPORT uint32_t SB_APIENTRY TElTarFileHeader_Assign(TElTarFileHeaderHandle _Handle, TElTarFileHeaderHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileHeader_AssignTo(TElTarFileHeaderHandle _Handle, TElTarFileHeaderHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileHeader_CalculateCheckSum(TElTarFileHeaderHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileHeader_get_Base(TElTarFileHeaderHandle _Handle, TElBaseTarHeaderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileHeader_set_Base(TElTarFileHeaderHandle _Handle, TElBaseTarHeaderHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileHeader_get_HasUStar(TElTarFileHeaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileHeader_set_HasUStar(TElTarFileHeaderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileHeader_get_UStar(TElTarFileHeaderHandle _Handle, TElUStarTarHeaderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileHeader_set_UStar(TElTarFileHeaderHandle _Handle, TElUStarTarHeaderHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileHeader_get_LocalHeaderOffset(TElTarFileHeaderHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileHeader_set_LocalHeaderOffset(TElTarFileHeaderHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileHeader_get_FileSize(TElTarFileHeaderHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileHeader_set_FileSize(TElTarFileHeaderHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileHeader_Create(TElTarFileHeaderHandle * OutResult);
#endif /* SB_USE_CLASS_TELTARFILEHEADER */

#ifdef SB_USE_CLASS_TELBASETARHEADER
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_Assign(TElBaseTarHeaderHandle _Handle, TElBaseTarHeaderHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_AssignTo(TElBaseTarHeaderHandle _Handle, TElBaseTarHeaderHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_LoadFromBuffer(TElBaseTarHeaderHandle _Handle, const uint8_t pBuf[], int32_t szBuf);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_SaveToBuffer(TElBaseTarHeaderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_get_Name(TElBaseTarHeaderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_set_Name(TElBaseTarHeaderHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_get_Mode(TElBaseTarHeaderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_set_Mode(TElBaseTarHeaderHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_get_UID(TElBaseTarHeaderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_set_UID(TElBaseTarHeaderHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_get_GID(TElBaseTarHeaderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_set_GID(TElBaseTarHeaderHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_get_Size(TElBaseTarHeaderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_set_Size(TElBaseTarHeaderHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_get_MTime(TElBaseTarHeaderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_set_MTime(TElBaseTarHeaderHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_get_CheckSum(TElBaseTarHeaderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_set_CheckSum(TElBaseTarHeaderHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_get_TypeFlag(TElBaseTarHeaderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_set_TypeFlag(TElBaseTarHeaderHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_get_LinkName(TElBaseTarHeaderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_set_LinkName(TElBaseTarHeaderHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBaseTarHeader_Create(TElBaseTarHeaderHandle * OutResult);
#endif /* SB_USE_CLASS_TELBASETARHEADER */

#ifdef SB_USE_CLASS_TELUSTARTARHEADER
SB_IMPORT uint32_t SB_APIENTRY TElUStarTarHeader_Assign(TElUStarTarHeaderHandle _Handle, TElUStarTarHeaderHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElUStarTarHeader_AssignTo(TElUStarTarHeaderHandle _Handle, TElUStarTarHeaderHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElUStarTarHeader_LoadFromBuffer(TElUStarTarHeaderHandle _Handle, const uint8_t pB[], int32_t szB);
SB_IMPORT uint32_t SB_APIENTRY TElUStarTarHeader_SaveToBuffer(TElUStarTarHeaderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUStarTarHeader_get_Magic(TElUStarTarHeaderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUStarTarHeader_set_Magic(TElUStarTarHeaderHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElUStarTarHeader_get_UName(TElUStarTarHeaderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUStarTarHeader_set_UName(TElUStarTarHeaderHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElUStarTarHeader_get_GName(TElUStarTarHeaderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUStarTarHeader_set_GName(TElUStarTarHeaderHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElUStarTarHeader_get_DevMajor(TElUStarTarHeaderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUStarTarHeader_set_DevMajor(TElUStarTarHeaderHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElUStarTarHeader_get_DevMinor(TElUStarTarHeaderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUStarTarHeader_set_DevMinor(TElUStarTarHeaderHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElUStarTarHeader_get_Prefix(TElUStarTarHeaderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUStarTarHeader_set_Prefix(TElUStarTarHeaderHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElUStarTarHeader_Create(TElUStarTarHeaderHandle * OutResult);
#endif /* SB_USE_CLASS_TELUSTARTARHEADER */

#ifdef SB_USE_CLASS_TELTARPROCESSOR
SB_IMPORT uint32_t SB_APIENTRY TElTarProcessor_Process(TElTarProcessorHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElTarProcessor_DataAvailable(TElTarProcessorHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTarProcessor_get_Processed(TElTarProcessorHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarProcessor_get_OnTarFileHeaderLoaded(TElTarProcessorHandle _Handle, TSBTarFileHeaderLoadedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarProcessor_set_OnTarFileHeaderLoaded(TElTarProcessorHandle _Handle, TSBTarFileHeaderLoadedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarProcessor_get_OnArchiveError(TElTarProcessorHandle _Handle, TSBTarArchiveErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarProcessor_set_OnArchiveError(TElTarProcessorHandle _Handle, TSBTarArchiveErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarProcessor_Create(TElTarProcessorHandle * OutResult);
#endif /* SB_USE_CLASS_TELTARPROCESSOR */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElTarFileHeader;
class TElBaseTarHeader;
class TElUStarTarHeader;
class TElTarProcessor;

#ifdef SB_USE_CLASS_TELTARFILEHEADER
class TElTarFileHeader: public TObject
{
	private:
		SB_DISABLE_COPY(TElTarFileHeader)
#ifdef SB_USE_CLASS_TELBASETARHEADER
		TElBaseTarHeader* _Inst_Base;
#endif /* SB_USE_CLASS_TELBASETARHEADER */
#ifdef SB_USE_CLASS_TELUSTARTARHEADER
		TElUStarTarHeader* _Inst_UStar;
#endif /* SB_USE_CLASS_TELUSTARTARHEADER */

		void initInstances();

	public:
		void Assign(TElTarFileHeader &Source);

		void Assign(TElTarFileHeader *Source);

		void AssignTo(TElTarFileHeader &Dest);

		void AssignTo(TElTarFileHeader *Dest);

		int64_t CalculateCheckSum();

#ifdef SB_USE_CLASS_TELBASETARHEADER
		virtual TElBaseTarHeader* get_Base();

		virtual void set_Base(TElBaseTarHeader &Value);

		virtual void set_Base(TElBaseTarHeader *Value);

		SB_DECLARE_PROPERTY(TElBaseTarHeader*, get_Base, set_Base, TElTarFileHeader, Base);
#endif /* SB_USE_CLASS_TELBASETARHEADER */

		virtual bool get_HasUStar();

		virtual void set_HasUStar(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HasUStar, set_HasUStar, TElTarFileHeader, HasUStar);

#ifdef SB_USE_CLASS_TELUSTARTARHEADER
		virtual TElUStarTarHeader* get_UStar();

		virtual void set_UStar(TElUStarTarHeader &Value);

		virtual void set_UStar(TElUStarTarHeader *Value);

		SB_DECLARE_PROPERTY(TElUStarTarHeader*, get_UStar, set_UStar, TElTarFileHeader, UStar);
#endif /* SB_USE_CLASS_TELUSTARTARHEADER */

		virtual int64_t get_LocalHeaderOffset();

		virtual void set_LocalHeaderOffset(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_LocalHeaderOffset, set_LocalHeaderOffset, TElTarFileHeader, LocalHeaderOffset);

		virtual int64_t get_FileSize();

		virtual void set_FileSize(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_FileSize, set_FileSize, TElTarFileHeader, FileSize);

		TElTarFileHeader(TElTarFileHeaderHandle handle, TElOwnHandle ownHandle);

		TElTarFileHeader();

		virtual ~TElTarFileHeader();

};
#endif /* SB_USE_CLASS_TELTARFILEHEADER */

#ifdef SB_USE_CLASS_TELBASETARHEADER
class TElBaseTarHeader: public TObject
{
	private:
		SB_DISABLE_COPY(TElBaseTarHeader)
	public:
		void Assign(TElBaseTarHeader &Source);

		void Assign(TElBaseTarHeader *Source);

		void AssignTo(TElBaseTarHeader &Dest);

		void AssignTo(TElBaseTarHeader *Dest);

		void LoadFromBuffer(const std::vector<uint8_t> &Buf);

		void SaveToBuffer(std::vector<uint8_t> &OutResult);

		virtual void get_Name(std::vector<uint8_t> &OutResult);

		virtual void set_Name(const std::vector<uint8_t> &Value);

		virtual void get_Mode(std::vector<uint8_t> &OutResult);

		virtual void set_Mode(const std::vector<uint8_t> &Value);

		virtual void get_UID(std::vector<uint8_t> &OutResult);

		virtual void set_UID(const std::vector<uint8_t> &Value);

		virtual void get_GID(std::vector<uint8_t> &OutResult);

		virtual void set_GID(const std::vector<uint8_t> &Value);

		virtual void get_Size(std::vector<uint8_t> &OutResult);

		virtual void set_Size(const std::vector<uint8_t> &Value);

		virtual void get_MTime(std::vector<uint8_t> &OutResult);

		virtual void set_MTime(const std::vector<uint8_t> &Value);

		virtual void get_CheckSum(std::vector<uint8_t> &OutResult);

		virtual void set_CheckSum(const std::vector<uint8_t> &Value);

		virtual void get_TypeFlag(std::vector<uint8_t> &OutResult);

		virtual void set_TypeFlag(const std::vector<uint8_t> &Value);

		virtual void get_LinkName(std::vector<uint8_t> &OutResult);

		virtual void set_LinkName(const std::vector<uint8_t> &Value);

		TElBaseTarHeader(TElBaseTarHeaderHandle handle, TElOwnHandle ownHandle);

		TElBaseTarHeader();

};
#endif /* SB_USE_CLASS_TELBASETARHEADER */

#ifdef SB_USE_CLASS_TELUSTARTARHEADER
class TElUStarTarHeader: public TObject
{
	private:
		SB_DISABLE_COPY(TElUStarTarHeader)
	public:
		void Assign(TElUStarTarHeader &Source);

		void Assign(TElUStarTarHeader *Source);

		void AssignTo(TElUStarTarHeader &Dest);

		void AssignTo(TElUStarTarHeader *Dest);

		void LoadFromBuffer(const std::vector<uint8_t> &B);

		void SaveToBuffer(std::vector<uint8_t> &OutResult);

		virtual void get_Magic(std::vector<uint8_t> &OutResult);

		virtual void set_Magic(const std::vector<uint8_t> &Value);

		virtual void get_UName(std::vector<uint8_t> &OutResult);

		virtual void set_UName(const std::vector<uint8_t> &Value);

		virtual void get_GName(std::vector<uint8_t> &OutResult);

		virtual void set_GName(const std::vector<uint8_t> &Value);

		virtual void get_DevMajor(std::vector<uint8_t> &OutResult);

		virtual void set_DevMajor(const std::vector<uint8_t> &Value);

		virtual void get_DevMinor(std::vector<uint8_t> &OutResult);

		virtual void set_DevMinor(const std::vector<uint8_t> &Value);

		virtual void get_Prefix(std::vector<uint8_t> &OutResult);

		virtual void set_Prefix(const std::vector<uint8_t> &Value);

		TElUStarTarHeader(TElUStarTarHeaderHandle handle, TElOwnHandle ownHandle);

		TElUStarTarHeader();

};
#endif /* SB_USE_CLASS_TELUSTARTARHEADER */

#ifdef SB_USE_CLASS_TELTARPROCESSOR
class TElTarProcessor: public TObject
{
	private:
		SB_DISABLE_COPY(TElTarProcessor)
	public:
#ifdef SB_USE_CLASS_TSTREAM
		void Process(TStream &Stream);

		void Process(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		void DataAvailable();

		virtual bool get_Processed();

		SB_DECLARE_PROPERTY_GET(bool, get_Processed, TElTarProcessor, Processed);

		virtual void get_OnTarFileHeaderLoaded(TSBTarFileHeaderLoadedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTarFileHeaderLoaded(TSBTarFileHeaderLoadedEvent pMethodValue, void * pDataValue);

		virtual void get_OnArchiveError(TSBTarArchiveErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnArchiveError(TSBTarArchiveErrorEvent pMethodValue, void * pDataValue);

		TElTarProcessor(TElTarProcessorHandle handle, TElOwnHandle ownHandle);

		TElTarProcessor();

};
#endif /* SB_USE_CLASS_TELTARPROCESSOR */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBTARENTITIES */

