#ifndef __INC_SBSSHTERM
#define __INC_SBSSHTERM

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_OPCODE_FIRST 	1
#define SB_OPCODE_VINTR 	1
#define SB_OPCODE_VQUIT 	2
#define SB_OPCODE_VERASE 	3
#define SB_OPCODE_VKILL 	4
#define SB_OPCODE_VEOF 	5
#define SB_OPCODE_VEOL 	6
#define SB_OPCODE_VEOL2 	7
#define SB_OPCODE_VSTART 	8
#define SB_OPCODE_VSTOP 	9
#define SB_OPCODE_VSUSP 	10
#define SB_OPCODE_VDSUSP 	11
#define SB_OPCODE_VREPRINT 	12
#define SB_OPCODE_VWERASE 	13
#define SB_OPCODE_VLNEXT 	14
#define SB_OPCODE_VFLUSH 	15
#define SB_OPCODE_VSWTCH 	16
#define SB_OPCODE_VSTATUS 	17
#define SB_OPCODE_VDISCARD 	18
#define SB_OPCODE_IGNPAR 	30
#define SB_OPCODE_PARMRK 	31
#define SB_OPCODE_INPCK 	32
#define SB_OPCODE_ISTRIP 	33
#define SB_OPCODE_INLCR 	34
#define SB_OPCODE_IGNCR 	35
#define SB_OPCODE_CRNL 	36
#define SB_OPCODE_IUCLC 	37
#define SB_OPCODE_IXON 	38
#define SB_OPCODE_IXANY 	39
#define SB_OPCODE_IXOFF 	40
#define SB_OPCODE_IMAXBEL 	41
#define SB_OPCODE_ISIG 	50
#define SB_OPCODE_ICANON 	51
#define SB_OPCODE_XCASE 	52
#define SB_OPCODE_ECHO 	53
#define SB_OPCODE_ECHOE 	54
#define SB_OPCODE_ECHOK 	55
#define SB_OPCODE_ECHONL 	56
#define SB_OPCODE_NOFLSH 	57
#define SB_OPCODE_TOSTOP 	58
#define SB_OPCODE_IEXTEN 	59
#define SB_OPCODE_ECHOCTL 	60
#define SB_OPCODE_ECHOKE 	61
#define SB_OPCODE_PENDIN 	62
#define SB_OPCODE_OPOST 	70
#define SB_OPCODE_OLCUC 	71
#define SB_OPCODE_ONLCR 	72
#define SB_OPCODE_OCRNL 	73
#define SB_OPCODE_ONOCR 	74
#define SB_OPCODE_ONLRET 	75
#define SB_OPCODE_CS7 	90
#define SB_OPCODE_CS8 	91
#define SB_OPCODE_PARENB 	92
#define SB_OPCODE_PARODD 	93
#define SB_OPCODE_LAST_DEFINED 	93
#define SB_OPCODE_LAST 	159
#define SB_OPCODE_NOT_SPECIFIED 	-32768

typedef TElClassHandle TElTerminalInfoHandle;

typedef TElTerminalInfoHandle ElTerminalInfoHandle;

typedef void (SB_CALLBACK *TSBTerminalChangeNotificationEvent)(void * _ObjectData, TObjectHandle Sender);

#pragma pack(4)
typedef struct 
{
	void * E;
} TSBChangeNotification, * PSBChangeNotification;

#ifdef SB_USE_CLASS_TELTERMINALINFO
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_GetTerminalType(TElTerminalInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_SetTerminalType(TElTerminalInfoHandle _Handle, const char * pcAValue, int32_t szAValue);
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_SetDefaultOpcodes(TElTerminalInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_AddChangeNotification(TElTerminalInfoHandle _Handle, const TSBTerminalChangeNotificationEvent pMethodValue, const void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_RemoveChangeNotification(TElTerminalInfoHandle _Handle, TSBTerminalChangeNotificationEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_BeginUpdate(TElTerminalInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_EndUpdate(TElTerminalInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_ClearOpcodes(TElTerminalInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_get_Opcodes(TElTerminalInfoHandle _Handle, int8_t Index, int16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_set_Opcodes(TElTerminalInfoHandle _Handle, int8_t Index, int16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_get_TerminalType(TElTerminalInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_set_TerminalType(TElTerminalInfoHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_get_Cols(TElTerminalInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_set_Cols(TElTerminalInfoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_get_Width(TElTerminalInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_set_Width(TElTerminalInfoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_get_Rows(TElTerminalInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_set_Rows(TElTerminalInfoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_get_Height(TElTerminalInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_set_Height(TElTerminalInfoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTerminalInfo_Create(TComponentHandle AOwner, TElTerminalInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELTERMINALINFO */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElTerminalInfo;
typedef TElTerminalInfo ElTerminalInfo;

#ifdef SB_USE_CLASS_TELTERMINALINFO
class TElTerminalInfo: public TComponent
{
	private:
		SB_DISABLE_COPY(TElTerminalInfo)
	public:
		void GetTerminalType(std::string &OutResult);

		void SetTerminalType(const std::string &AValue);

		void SetDefaultOpcodes();

		void AddChangeNotification(const TSBTerminalChangeNotificationEvent pMethodValue, const void * pDataValue);

		void RemoveChangeNotification(TSBTerminalChangeNotificationEvent pMethodValue, void * pDataValue);

		void BeginUpdate();

		void EndUpdate();

		void ClearOpcodes();

		virtual int16_t get_Opcodes(int8_t Index);

		virtual void set_Opcodes(int8_t Index, int16_t Value);

		virtual void get_TerminalType(std::string &OutResult);

		virtual void set_TerminalType(const std::string &Value);

		virtual int32_t get_Cols();

		virtual void set_Cols(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Cols, set_Cols, TElTerminalInfo, Cols);

		virtual int32_t get_Width();

		virtual void set_Width(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Width, set_Width, TElTerminalInfo, Width);

		virtual int32_t get_Rows();

		virtual void set_Rows(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Rows, set_Rows, TElTerminalInfo, Rows);

		virtual int32_t get_Height();

		virtual void set_Height(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Height, set_Height, TElTerminalInfo, Height);

		TElTerminalInfo(TElTerminalInfoHandle handle, TElOwnHandle ownHandle);

		explicit TElTerminalInfo(TComponent &AOwner);

		explicit TElTerminalInfo(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELTERMINALINFO */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSSHTERM */

