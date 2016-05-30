#ifndef __INC_SBPDFUTILS
#define __INC_SBPDFUTILS

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
#define SB_PREDICTOR_NONE 	1
#define SB_PREDICTOR_PNG_UP 	12

typedef TElClassHandle TElPDFPermissionsHandle;

typedef TElPDFPermissionsHandle ElPDFPermissionsHandle;

#ifdef SB_USE_CLASS_TELPDFPERMISSIONS
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_Load(TElPDFPermissionsHandle _Handle, uint32_t Value, int32_t Revision);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_Save(TElPDFPermissionsHandle _Handle, int32_t Revision, int8_t PubKeyHandler, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_DisableAll(TElPDFPermissionsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_EnableAll(TElPDFPermissionsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_get_Modify(TElPDFPermissionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_set_Modify(TElPDFPermissionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_get_Extract(TElPDFPermissionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_set_Extract(TElPDFPermissionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_get_Annotations(TElPDFPermissionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_set_Annotations(TElPDFPermissionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_get_FillInForms(TElPDFPermissionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_set_FillInForms(TElPDFPermissionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_get_ExtractAcc(TElPDFPermissionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_set_ExtractAcc(TElPDFPermissionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_get_Assemble(TElPDFPermissionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_set_Assemble(TElPDFPermissionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_get_LowQualityPrint(TElPDFPermissionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_set_LowQualityPrint(TElPDFPermissionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_get_HighQualityPrint(TElPDFPermissionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_set_HighQualityPrint(TElPDFPermissionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFPermissions_Create(TElPDFPermissionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFPERMISSIONS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPDFPermissions;
typedef TElPDFPermissions ElPDFPermissions;

#ifdef SB_USE_CLASS_TELPDFPERMISSIONS
class TElPDFPermissions: public TObject
{
	private:
		SB_DISABLE_COPY(TElPDFPermissions)
	public:
		virtual void Load(uint32_t Value, int32_t Revision);

		virtual uint32_t Save(int32_t Revision, bool PubKeyHandler);

		void DisableAll();

		void EnableAll();

		virtual bool get_Modify();

		virtual void set_Modify(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Modify, set_Modify, TElPDFPermissions, Modify);

		virtual bool get_Extract();

		virtual void set_Extract(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Extract, set_Extract, TElPDFPermissions, Extract);

		virtual bool get_Annotations();

		virtual void set_Annotations(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Annotations, set_Annotations, TElPDFPermissions, Annotations);

		virtual bool get_FillInForms();

		virtual void set_FillInForms(bool Value);

		SB_DECLARE_PROPERTY(bool, get_FillInForms, set_FillInForms, TElPDFPermissions, FillInForms);

		virtual bool get_ExtractAcc();

		virtual void set_ExtractAcc(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ExtractAcc, set_ExtractAcc, TElPDFPermissions, ExtractAcc);

		virtual bool get_Assemble();

		virtual void set_Assemble(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Assemble, set_Assemble, TElPDFPermissions, Assemble);

		virtual bool get_LowQualityPrint();

		virtual void set_LowQualityPrint(bool Value);

		SB_DECLARE_PROPERTY(bool, get_LowQualityPrint, set_LowQualityPrint, TElPDFPermissions, LowQualityPrint);

		virtual bool get_HighQualityPrint();

		virtual void set_HighQualityPrint(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HighQualityPrint, set_HighQualityPrint, TElPDFPermissions, HighQualityPrint);

		TElPDFPermissions(TElPDFPermissionsHandle handle, TElOwnHandle ownHandle);

		TElPDFPermissions();

};
#endif /* SB_USE_CLASS_TELPDFPERMISSIONS */

#ifdef SB_USE_GLOBAL_PROCS_PDFUTILS

void IntToByteArray(int32_t Value, bool LittleEndian, std::vector<uint8_t> &OutResult);

void UIntToByteArray(uint32_t Value, bool LittleEndian, std::vector<uint8_t> &OutResult);

bool IsPNGPredictor(int32_t Value);

void DecodePNG(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count, int32_t Cols, std::vector<uint8_t> &OutResult);

void TrimArray(std::vector<uint8_t> &a);

#endif /* SB_USE_GLOBAL_PROCS_PDFUTILS */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_PDFUTILS
SB_IMPORT uint32_t SB_APIENTRY SBPDFUtils_IntToByteArray(int32_t Value, int8_t LittleEndian, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPDFUtils_UIntToByteArray(uint32_t Value, int8_t LittleEndian, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPDFUtils_IsPNGPredictor(int32_t Value, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPDFUtils_DecodePNG(const uint8_t pBuffer[], int32_t szBuffer, int32_t StartIndex, int32_t Count, int32_t Cols, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPDFUtils_TrimArray(uint8_t pa[], int32_t * sza);
#endif /* SB_USE_GLOBAL_PROCS_PDFUTILS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPDFUTILS */

