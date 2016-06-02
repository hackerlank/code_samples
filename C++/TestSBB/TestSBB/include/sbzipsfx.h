#ifndef __INC_SBZIPSFX
#define __INC_SBZIPSFX

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
#include "sbstreams.h"
#include "sbarczip.h"
#include "sbziputils.h"
#include "sbzipentities.h"
#include "sbzipsfxmaker.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifndef SB_WINCE_OR_NOT_WINDOWS
#define SB_ZIPSFXStubAllSwitches 	{0,1,2,3,4,5}
#define SB_SErrUserAbort 	"Cancelled by the user"
#define SB_SErrInternalError 	"Internal error"
#define SB_SErrInvalidParamTarget 	"No target folder specified"
#define SB_SErrInvalidParamPublic 	"No public keyring file specified"
#define SB_SErrInvalidParamKeyPass 	"No secret key passphrase specified"
#define SB_SErrInvalidParamPass 	"No decryption passphrase specified"
#ifndef SB_SErrInvalidParamExtract
#define SB_SErrInvalidParamExtract 	"No zip-archive file name specified"
#endif
#define SB_SErrInvalidParamTemp 	"No or invalid temporary file location specified"
#define SB_SErrTargetFolderFailure 	"Failed to create target folder %s"
#define SB_SErrInputStreamFailure 	"Failed to open input stream"
#define SB_SErrNoZIPData 	"No ZIP data found"
#define SB_SErrNoSFXData 	"No SFX data found"
#define SB_SErrPacketFileAlreadyExists 	"File %s already exists"
#define SB_SErrPacketFileFailure 	"Failed to create or open the output file %s"

typedef TElClassHandle TElZIPSFXStubHandle;

typedef uint8_t TSBZIPSFXCommandLineSwitchRaw;

typedef enum
{
	_clsHelp = 0,
	_clsSilent = 1,
	_clsTarget = 2,
	_clsPass = 3,
	_clsExtract = 4,
	_clsTempFile = 5
} TSBZIPSFXCommandLineSwitch;

typedef uint32_t TSBZIPSFXCommandLineSwitchesRaw;

typedef enum 
{
	_f_clsHelp = 1,
	_f_clsSilent = 2,
	_f_clsTarget = 4,
	_f_clsPass = 8,
	_f_clsExtract = 16,
	_f_clsTempFile = 32
} TSBZIPSFXCommandLineSwitches;

typedef void (SB_CALLBACK *TSBZIPSFXExtractingEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcFolder, int32_t szFolder, const char * pcFileName, int32_t szFileName);

typedef void (SB_CALLBACK *TSBZIPSFXErrorEvent)(void * _ObjectData, TObjectHandle Sender, TElClassHandle Error);

typedef void (SB_CALLBACK *TSBZIPSFXStartEvent)(void * _ObjectData, TObjectHandle Sender, int8_t HelpRequested, int8_t * Abort);

typedef void (SB_CALLBACK *TSBZIPSFXTargetFolderEvent)(void * _ObjectData, TObjectHandle Sender, char * pcFolder, int32_t * szFolder, int8_t * Abort);

#ifdef SB_USE_CLASS_TELZIPSFXSTUB
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_Execute(TElZIPSFXStubHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_Copyright(TElZIPSFXStubHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_Evaluation(TElZIPSFXStubHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_Title(TElZIPSFXStubHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_UsedSwitches(TElZIPSFXStubHandle _Handle, TSBZIPSFXCommandLineSwitchesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_Extract(TElZIPSFXStubHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_set_Extract(TElZIPSFXStubHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_Password(TElZIPSFXStubHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_set_Password(TElZIPSFXStubHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_CertFile(TElZIPSFXStubHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_set_CertFile(TElZIPSFXStubHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_CertPassword(TElZIPSFXStubHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_set_CertPassword(TElZIPSFXStubHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_Silent(TElZIPSFXStubHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_set_Silent(TElZIPSFXStubHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_SupportedSwitches(TElZIPSFXStubHandle _Handle, TSBZIPSFXCommandLineSwitchesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_set_SupportedSwitches(TElZIPSFXStubHandle _Handle, TSBZIPSFXCommandLineSwitchesRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_Target(TElZIPSFXStubHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_set_Target(TElZIPSFXStubHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_UseCommandLine(TElZIPSFXStubHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_set_UseCommandLine(TElZIPSFXStubHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_OnAbort(TElZIPSFXStubHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_set_OnAbort(TElZIPSFXStubHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_OnCommandLine(TElZIPSFXStubHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_set_OnCommandLine(TElZIPSFXStubHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_OnError(TElZIPSFXStubHandle _Handle, TSBZIPSFXErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_set_OnError(TElZIPSFXStubHandle _Handle, TSBZIPSFXErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_OnExtracting(TElZIPSFXStubHandle _Handle, TSBZIPSFXExtractingEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_set_OnExtracting(TElZIPSFXStubHandle _Handle, TSBZIPSFXExtractingEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_OnFinish(TElZIPSFXStubHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_set_OnFinish(TElZIPSFXStubHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_OnPasswordNeeded(TElZIPSFXStubHandle _Handle, TSBZipPasswordNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_set_OnPasswordNeeded(TElZIPSFXStubHandle _Handle, TSBZipPasswordNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_OnProgress(TElZIPSFXStubHandle _Handle, TSBZipProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_set_OnProgress(TElZIPSFXStubHandle _Handle, TSBZipProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_OnFileStart(TElZIPSFXStubHandle _Handle, TSBZipExtractionStartEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_set_OnFileStart(TElZIPSFXStubHandle _Handle, TSBZipExtractionStartEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_OnFileFinish(TElZIPSFXStubHandle _Handle, TSBZipExtractionFinishedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_set_OnFileFinish(TElZIPSFXStubHandle _Handle, TSBZipExtractionFinishedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_OnUserActionNeeded(TElZIPSFXStubHandle _Handle, TSBZipUserActionNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_set_OnUserActionNeeded(TElZIPSFXStubHandle _Handle, TSBZipUserActionNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_OnStart(TElZIPSFXStubHandle _Handle, TSBZIPSFXStartEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_set_OnStart(TElZIPSFXStubHandle _Handle, TSBZIPSFXStartEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_get_OnTargetFolder(TElZIPSFXStubHandle _Handle, TSBZIPSFXTargetFolderEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_set_OnTargetFolder(TElZIPSFXStubHandle _Handle, TSBZIPSFXTargetFolderEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZIPSFXStub_Create(TComponentHandle AOwner, TElZIPSFXStubHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPSFXSTUB */
#endif

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifndef SB_WINCE_OR_NOT_WINDOWS
#ifdef __cplusplus

// Class forward declaration
class TElZIPSFXStub;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBZIPSFXCommandLineSwitches)

#ifdef SB_USE_CLASS_TELZIPSFXSTUB
class TElZIPSFXStub: public TComponent
{
	private:
		SB_DISABLE_COPY(TElZIPSFXStub)
	public:
		int32_t Execute();

		virtual void get_Copyright(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Copyright(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual bool get_Evaluation();

		SB_DECLARE_PROPERTY_GET(bool, get_Evaluation, TElZIPSFXStub, Evaluation);

		virtual void get_Title(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Title(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual TSBZIPSFXCommandLineSwitches get_UsedSwitches();

		SB_DECLARE_PROPERTY_GET(TSBZIPSFXCommandLineSwitches, get_UsedSwitches, TElZIPSFXStub, UsedSwitches);

		virtual void get_Extract(std::string &OutResult);

		virtual void set_Extract(const std::string &Value);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual void get_CertFile(std::string &OutResult);

		virtual void set_CertFile(const std::string &Value);

		virtual void get_CertPassword(std::string &OutResult);

		virtual void set_CertPassword(const std::string &Value);

		virtual bool get_Silent();

		virtual void set_Silent(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Silent, set_Silent, TElZIPSFXStub, Silent);

		virtual TSBZIPSFXCommandLineSwitches get_SupportedSwitches();

		virtual void set_SupportedSwitches(TSBZIPSFXCommandLineSwitches Value);

		SB_DECLARE_PROPERTY(TSBZIPSFXCommandLineSwitches, get_SupportedSwitches, set_SupportedSwitches, TElZIPSFXStub, SupportedSwitches);

		virtual void get_Target(std::string &OutResult);

		virtual void set_Target(const std::string &Value);

		virtual bool get_UseCommandLine();

		virtual void set_UseCommandLine(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseCommandLine, set_UseCommandLine, TElZIPSFXStub, UseCommandLine);

		virtual void get_OnAbort(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAbort(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnCommandLine(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCommandLine(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnError(TSBZIPSFXErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSBZIPSFXErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtracting(TSBZIPSFXExtractingEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtracting(TSBZIPSFXExtractingEvent pMethodValue, void * pDataValue);

		virtual void get_OnFinish(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFinish(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnPasswordNeeded(TSBZipPasswordNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPasswordNeeded(TSBZipPasswordNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBZipProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBZipProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileStart(TSBZipExtractionStartEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileStart(TSBZipExtractionStartEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileFinish(TSBZipExtractionFinishedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileFinish(TSBZipExtractionFinishedEvent pMethodValue, void * pDataValue);

		virtual void get_OnUserActionNeeded(TSBZipUserActionNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnUserActionNeeded(TSBZipUserActionNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnStart(TSBZIPSFXStartEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnStart(TSBZIPSFXStartEvent pMethodValue, void * pDataValue);

		virtual void get_OnTargetFolder(TSBZIPSFXTargetFolderEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTargetFolder(TSBZIPSFXTargetFolderEvent pMethodValue, void * pDataValue);

		TElZIPSFXStub(TElZIPSFXStubHandle handle, TElOwnHandle ownHandle);

		explicit TElZIPSFXStub(TComponent &AOwner);

		explicit TElZIPSFXStub(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELZIPSFXSTUB */

#endif  /* __cplusplus */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBZIPSFX */
