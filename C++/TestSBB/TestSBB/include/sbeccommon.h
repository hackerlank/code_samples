#ifndef __INC_SBECCOMMON
#define __INC_SBECCOMMON

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbmath.h"
#include "sbecmath.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElECDomainParametersHandle;

#ifdef SB_USE_CLASS_TELECDOMAINPARAMETERS
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_SetupCurveParameters(TElECDomainParametersHandle _Handle, int32_t Curve);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_SetP(TElECDomainParametersHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_UpdateP(TElECDomainParametersHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_SetM(TElECDomainParametersHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_SetK1(TElECDomainParametersHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_SetK2(TElECDomainParametersHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_SetK3(TElECDomainParametersHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_SetField(TElECDomainParametersHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_SetCurve(TElECDomainParametersHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_SetCurveOID(TElECDomainParametersHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_SetSeed(TElECDomainParametersHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_SetA(TElECDomainParametersHandle _Handle, const uint8_t pV[], int32_t szV);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_SetB(TElECDomainParametersHandle _Handle, const uint8_t pV[], int32_t szV);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_SetN(TElECDomainParametersHandle _Handle, const uint8_t pV[], int32_t szV);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_SetX(TElECDomainParametersHandle _Handle, const uint8_t pV[], int32_t szV);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_SetY(TElECDomainParametersHandle _Handle, const uint8_t pV[], int32_t szV);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_GetFieldBits(TElECDomainParametersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_GetSubgroupBits(TElECDomainParametersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_Reset(TElECDomainParametersHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_Check(TElECDomainParametersHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_get_Curve(TElECDomainParametersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_set_Curve(TElECDomainParametersHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_get_CurveOID(TElECDomainParametersHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_set_CurveOID(TElECDomainParametersHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_get_P(TElECDomainParametersHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_set_P(TElECDomainParametersHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_get_A(TElECDomainParametersHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_set_A(TElECDomainParametersHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_get_B(TElECDomainParametersHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_set_B(TElECDomainParametersHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_get_N(TElECDomainParametersHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_set_N(TElECDomainParametersHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_get_H(TElECDomainParametersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_set_H(TElECDomainParametersHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_get_X(TElECDomainParametersHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_set_X(TElECDomainParametersHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_get_Y(TElECDomainParametersHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_set_Y(TElECDomainParametersHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_get_Seed(TElECDomainParametersHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_set_Seed(TElECDomainParametersHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_get_FieldType(TElECDomainParametersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_set_FieldType(TElECDomainParametersHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_get_Field(TElECDomainParametersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_set_Field(TElECDomainParametersHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_get_FieldBits(TElECDomainParametersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_get_SubgroupBits(TElECDomainParametersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_get_M(TElECDomainParametersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_set_M(TElECDomainParametersHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_get_K1(TElECDomainParametersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_set_K1(TElECDomainParametersHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_get_K2(TElECDomainParametersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_set_K2(TElECDomainParametersHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_get_K3(TElECDomainParametersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_set_K3(TElECDomainParametersHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECDomainParameters_Create(TElECDomainParametersHandle * OutResult);
#endif /* SB_USE_CLASS_TELECDOMAINPARAMETERS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElECDomainParameters;

#ifdef SB_USE_CLASS_TELECDOMAINPARAMETERS
class TElECDomainParameters: public TObject
{
	private:
		SB_DISABLE_COPY(TElECDomainParameters)
	public:
		void SetupCurveParameters(int32_t Curve);

		void SetP(const std::vector<uint8_t> &Value);

		void UpdateP();

		void SetM(int32_t Value);

		void SetK1(int32_t Value);

		void SetK2(int32_t Value);

		void SetK3(int32_t Value);

		void SetField(int32_t Value);

		void SetCurve(int32_t Value);

		void SetCurveOID(const std::vector<uint8_t> &Value);

		void SetSeed(const std::vector<uint8_t> &Value);

		void SetA(const std::vector<uint8_t> &V);

		void SetB(const std::vector<uint8_t> &V);

		void SetN(const std::vector<uint8_t> &V);

		void SetX(const std::vector<uint8_t> &V);

		void SetY(const std::vector<uint8_t> &V);

		int32_t GetFieldBits();

		int32_t GetSubgroupBits();

		void Reset();

		bool Check();

		virtual int32_t get_Curve();

		virtual void set_Curve(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Curve, set_Curve, TElECDomainParameters, Curve);

		virtual void get_CurveOID(std::vector<uint8_t> &OutResult);

		virtual void set_CurveOID(const std::vector<uint8_t> &Value);

		virtual void get_P(std::vector<uint8_t> &OutResult);

		virtual void set_P(const std::vector<uint8_t> &Value);

		virtual void get_A(std::vector<uint8_t> &OutResult);

		virtual void set_A(const std::vector<uint8_t> &Value);

		virtual void get_B(std::vector<uint8_t> &OutResult);

		virtual void set_B(const std::vector<uint8_t> &Value);

		virtual void get_N(std::vector<uint8_t> &OutResult);

		virtual void set_N(const std::vector<uint8_t> &Value);

		virtual int32_t get_H();

		virtual void set_H(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_H, set_H, TElECDomainParameters, H);

		virtual void get_X(std::vector<uint8_t> &OutResult);

		virtual void set_X(const std::vector<uint8_t> &Value);

		virtual void get_Y(std::vector<uint8_t> &OutResult);

		virtual void set_Y(const std::vector<uint8_t> &Value);

		virtual void get_Seed(std::vector<uint8_t> &OutResult);

		virtual void set_Seed(const std::vector<uint8_t> &Value);

		virtual int32_t get_FieldType();

		virtual void set_FieldType(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_FieldType, set_FieldType, TElECDomainParameters, FieldType);

		virtual int32_t get_Field();

		virtual void set_Field(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Field, set_Field, TElECDomainParameters, Field);

		virtual int32_t get_FieldBits();

		SB_DECLARE_PROPERTY_GET(int32_t, get_FieldBits, TElECDomainParameters, FieldBits);

		virtual int32_t get_SubgroupBits();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SubgroupBits, TElECDomainParameters, SubgroupBits);

		virtual int32_t get_M();

		virtual void set_M(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_M, set_M, TElECDomainParameters, M);

		virtual int32_t get_K1();

		virtual void set_K1(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_K1, set_K1, TElECDomainParameters, K1);

		virtual int32_t get_K2();

		virtual void set_K2(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_K2, set_K2, TElECDomainParameters, K2);

		virtual int32_t get_K3();

		virtual void set_K3(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_K3, set_K3, TElECDomainParameters, K3);

		TElECDomainParameters(TElECDomainParametersHandle handle, TElOwnHandle ownHandle);

		TElECDomainParameters();

};
#endif /* SB_USE_CLASS_TELECDOMAINPARAMETERS */

#ifdef SB_USE_GLOBAL_PROCS_ECCOMMON

int32_t GetCurveByOID(const std::vector<uint8_t> &OID);

void GetOIDByCurve(int32_t Curve, std::vector<uint8_t> &OutResult);

bool IsPointCompressed(void * Buffer, int32_t Size);

#ifdef SB_USE_CLASS_TELECDOMAINPARAMETERS
bool BufferToPoint(void * Buffer, int32_t Size, TElECDomainParameters &DomainParams, void * X, int32_t &XSize, void * Y, int32_t &YSize);
bool BufferToPoint(void * Buffer, int32_t Size, TElECDomainParameters *DomainParams, void * X, int32_t &XSize, void * Y, int32_t &YSize);
#endif /* SB_USE_CLASS_TELECDOMAINPARAMETERS */

#ifdef SB_USE_CLASS_TELECDOMAINPARAMETERS
bool PointToBuffer(void * X, int32_t XSize, void * Y, int32_t YSize, TElECDomainParameters &DomainParams, void * Buffer, int32_t &Size, bool Compress, bool Hybrid);
bool PointToBuffer(void * X, int32_t XSize, void * Y, int32_t YSize, TElECDomainParameters *DomainParams, void * Buffer, int32_t &Size, bool Compress, bool Hybrid);
#endif /* SB_USE_CLASS_TELECDOMAINPARAMETERS */

#ifdef SB_USE_CLASS_TELECDOMAINPARAMETERS
bool ValidateKey(TElECDomainParameters &DomainParams, void * D, int32_t DSize, void * Qx, int32_t QxSize, void * Qy, int32_t QySize);
bool ValidateKey(TElECDomainParameters *DomainParams, void * D, int32_t DSize, void * Qx, int32_t QxSize, void * Qy, int32_t QySize);
#endif /* SB_USE_CLASS_TELECDOMAINPARAMETERS */

void HexStrToFieldElement(const std::string &Src, bool LittleEndian, int32_t PSize, std::vector<uint8_t> &OutResult);

void BufferToFieldElement(const std::vector<uint8_t> &Buf, PLInt &A, PLInt P);

void BufferToFieldElement(void * Buf, int32_t Size, PLInt &A, PLInt P);

#endif /* SB_USE_GLOBAL_PROCS_ECCOMMON */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_ECCOMMON
SB_IMPORT uint32_t SB_APIENTRY SBECCommon_GetCurveByOID(const uint8_t pOID[], int32_t szOID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECCommon_GetOIDByCurve(int32_t Curve, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECCommon_IsPointCompressed(void * Buffer, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECCommon_BufferToPoint(void * Buffer, int32_t Size, TElECDomainParametersHandle DomainParams, void * X, int32_t * XSize, void * Y, int32_t * YSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECCommon_PointToBuffer(void * X, int32_t XSize, void * Y, int32_t YSize, TElECDomainParametersHandle DomainParams, void * Buffer, int32_t * Size, int8_t Compress, int8_t Hybrid, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECCommon_ValidateKey(TElECDomainParametersHandle DomainParams, void * D, int32_t DSize, void * Qx, int32_t QxSize, void * Qy, int32_t QySize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECCommon_HexStrToFieldElement(const char * pcSrc, int32_t szSrc, int8_t LittleEndian, int32_t PSize, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBECCommon_BufferToFieldElement(const uint8_t pBuf[], int32_t szBuf, PLInt * A, PLInt P);
SB_IMPORT uint32_t SB_APIENTRY SBECCommon_BufferToFieldElement_1(void * Buf, int32_t Size, PLInt * A, PLInt P);
#endif /* SB_USE_GLOBAL_PROCS_ECCOMMON */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBECCOMMON */

