#ifndef __INC_SBTSPCOMMON
#define __INC_SBTSPCOMMON

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbx509ext.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ERROR_FACILITY_TSP 	81920
#define SB_ERROR_TSP_PROTOCOL_ERROR_FLAG 	2048
#define SB_TSP_ERROR_ABORTED 	83969
#define SB_TSP_ERROR_NO_REPLY 	83970
#define SB_TSP_ERROR_NO_PARAMETERS 	83971
#define SB_TSP_ERROR_NO_CERTIFICATES 	83972
#define SB_TSP_ERROR_WRONG_DATA 	83973
#define SB_TSP_ERROR_WRONG_IMPRINT 	83974
#define SB_TSP_ERROR_WRONG_NONCE 	83975
#define SB_TSP_ERROR_UNEXPECTED_CERTIFICATES 	83976
#define SB_TSP_ERROR_UNRECOGNIZED_FORMAT 	81921
#define SB_TSP_ERROR_DATA_TOO_LONG 	81922
#define SB_TSP_ERROR_UNSUPPORTED_REPLY 	81923
#define SB_TSP_ERROR_GENERAL_ERROR 	81924
#define SB_TSP_ERROR_REQUEST_REJECTED 	81925
#define SB_tfiBadAlg 	0
#define SB_tfiBadRequest 	2
#define SB_tfiBadDataFormat 	5
#define SB_tfiTimeNotAvailable 	14
#define SB_tfiUnacceptedPolicy 	15
#define SB_tfiUnacceptedExtension 	16
#define SB_tfiAddInfoNotAvailable 	17
#define SB_tfiSystemFailure 	25
#define SB_TSP_OID_AUTHENTICODE_TIMESTAMP 	"+\x06""\x01""\x04""\x01""\x82""7\x03""\x02""\x01"
#define SB_TSP_OID_PKCS7_DATA 	"*\x86""H\x86""\xF7""\r\x01""\a\x01"

typedef TElClassHandle TElTSPInfoHandle;

typedef TElTSPInfoHandle ElTSPInfoHandle;

typedef TElClassHandle TElTSPClassHandle;

typedef TElTSPClassHandle ElTSPClassHandle;

#ifdef SB_USE_CLASS_TELTSPINFO
SB_IMPORT uint32_t SB_APIENTRY TElTSPInfo_Assign(TElTSPInfoHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElTSPInfo_Reset(TElTSPInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTSPInfo_get_SerialNumber(TElTSPInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTSPInfo_set_SerialNumber(TElTSPInfoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElTSPInfo_get_Nonce(TElTSPInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTSPInfo_set_Nonce(TElTSPInfoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElTSPInfo_get_Time(TElTSPInfoHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTSPInfo_set_Time(TElTSPInfoHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTSPInfo_get_AccuracySec(TElTSPInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTSPInfo_set_AccuracySec(TElTSPInfoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTSPInfo_get_AccuracyMilli(TElTSPInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTSPInfo_set_AccuracyMilli(TElTSPInfoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTSPInfo_get_AccuracyMicro(TElTSPInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTSPInfo_set_AccuracyMicro(TElTSPInfoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTSPInfo_get_AccuracySet(TElTSPInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTSPInfo_set_AccuracySet(TElTSPInfoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTSPInfo_get_TSAName(TElTSPInfoHandle _Handle, TElGeneralNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTSPInfo_get_TSANameSet(TElTSPInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTSPInfo_set_TSANameSet(TElTSPInfoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTSPInfo_Create(TElTSPInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELTSPINFO */

#ifdef SB_USE_CLASS_TELTSPCLASS
SB_IMPORT uint32_t SB_APIENTRY TElTSPClass_ValidateImprint(TElTSPClassHandle _Handle, int32_t Algorithm, const uint8_t pHashedData[], int32_t szHashedData, const uint8_t pImprint[], int32_t szImprint, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTSPClass_Create(TComponentHandle Owner, TElTSPClassHandle * OutResult);
#endif /* SB_USE_CLASS_TELTSPCLASS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElTSPInfo;
typedef TElTSPInfo ElTSPInfo;
class TElTSPClass;
typedef TElTSPClass ElTSPClass;

#ifdef SB_USE_CLASS_TELTSPINFO
class TElTSPInfo: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElTSPInfo)
#ifdef SB_USE_CLASS_TELGENERALNAME
		TElGeneralName* _Inst_TSAName;
#endif /* SB_USE_CLASS_TELGENERALNAME */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Reset();

		virtual void get_SerialNumber(std::vector<uint8_t> &OutResult);

		virtual void set_SerialNumber(const std::vector<uint8_t> &Value);

		virtual void get_Nonce(std::vector<uint8_t> &OutResult);

		virtual void set_Nonce(const std::vector<uint8_t> &Value);

		virtual int64_t get_Time();

		virtual void set_Time(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Time, set_Time, TElTSPInfo, Time);

		virtual int32_t get_AccuracySec();

		virtual void set_AccuracySec(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AccuracySec, set_AccuracySec, TElTSPInfo, AccuracySec);

		virtual int32_t get_AccuracyMilli();

		virtual void set_AccuracyMilli(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AccuracyMilli, set_AccuracyMilli, TElTSPInfo, AccuracyMilli);

		virtual int32_t get_AccuracyMicro();

		virtual void set_AccuracyMicro(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AccuracyMicro, set_AccuracyMicro, TElTSPInfo, AccuracyMicro);

		virtual bool get_AccuracySet();

		virtual void set_AccuracySet(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AccuracySet, set_AccuracySet, TElTSPInfo, AccuracySet);

#ifdef SB_USE_CLASS_TELGENERALNAME
		virtual TElGeneralName* get_TSAName();

		SB_DECLARE_PROPERTY_GET(TElGeneralName*, get_TSAName, TElTSPInfo, TSAName);
#endif /* SB_USE_CLASS_TELGENERALNAME */

		virtual bool get_TSANameSet();

		virtual void set_TSANameSet(bool Value);

		SB_DECLARE_PROPERTY(bool, get_TSANameSet, set_TSANameSet, TElTSPInfo, TSANameSet);

		TElTSPInfo(TElTSPInfoHandle handle, TElOwnHandle ownHandle);

		TElTSPInfo();

		virtual ~TElTSPInfo();

};
#endif /* SB_USE_CLASS_TELTSPINFO */

#ifdef SB_USE_CLASS_TELTSPCLASS
class TElTSPClass: public TComponent
{
	private:
		SB_DISABLE_COPY(TElTSPClass)
	public:
		bool ValidateImprint(int32_t Algorithm, const std::vector<uint8_t> &HashedData, const std::vector<uint8_t> &Imprint);

		TElTSPClass(TElTSPClassHandle handle, TElOwnHandle ownHandle);

		explicit TElTSPClass(TComponent &Owner);

		explicit TElTSPClass(TComponent *Owner);

};
#endif /* SB_USE_CLASS_TELTSPCLASS */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBTSPCOMMON */

