#ifndef __INC_SBOFFICECOMMON
#define __INC_SBOFFICECOMMON

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstreams.h"
#include "sbtypes.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef uint8_t TSBOfficeDocumentFormatRaw;

typedef enum
{
	dfUnknown = 0,
	dfBinary = 1,
	dfOpenXML = 2,
	dfOpenXPS = 3,
	dfOpenDocument = 4
} TSBOfficeDocumentFormat;

typedef uint8_t TSBOfficeBinaryDocumentTypeRaw;

typedef enum
{
	dtUnknown = 0,
	dtDocument = 1,
	dtSpreadsheet = 2,
	dtPresentation = 3
} TSBOfficeBinaryDocumentType;

typedef uint8_t TSBOfficeOpenXMLDocumentTypeRaw;

typedef enum
{
	xdtUnknown = 0,
	xdtDocument = 1,
	xdtDocumentTemplate = 2,
	xdtSpreadsheet = 3,
	xdtSpreadsheetTemplate = 4,
	xdtSpreadsheetBinary = 5,
	xdtSpreadsheetAddIn = 6,
	xdtPresentation = 7,
	xdtPresentationTemplate = 8,
	xdtPresentationSlideshow = 9,
	xdtPresentationAddIn = 10
} TSBOfficeOpenXMLDocumentType;

typedef uint8_t TSBOpenOfficeDocumentTypeRaw;

typedef enum
{
	odtUnknown = 0,
	odtText = 1,
	odtTextTemplate = 2,
	odtTextMaster = 3,
	odtTextWeb = 4,
	odtSpreadsheet = 5,
	odtSpreadsheetTemplate = 6,
	odtDrawing = 7,
	odtDrawingTemplate = 8,
	odtPresentation = 9,
	odtPresentationTemplate = 10,
	odtChart = 11,
	odtChartTemplate = 12,
	odtImage = 13,
	odtImageTemplate = 14,
	odtFormula = 15,
	odtFormulaTemplate = 16,
	odtDatabase = 17
} TSBOpenOfficeDocumentType;

#pragma pack(4)
typedef struct 
{
	uint16_t Major;
	uint16_t Minor;
} TSBOfficeVersion;

typedef void (SB_CALLBACK *TSBOfficeCreateTemporaryStreamEvent)(void * _ObjectData, TObjectHandle Sender, int64_t ExpectedSize, TStreamHandle * Stream, int8_t * FreeOnClose);

typedef void (SB_CALLBACK *TSBOfficeCloseTemporaryStreamEvent)(void * _ObjectData, TObjectHandle Sender, TStreamHandle Stream);

typedef void (SB_CALLBACK *TSBOfficeProgressEvent)(void * _ObjectData, TObjectHandle Sender, int32_t Percent, int8_t * Cancel);

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBOFFICECOMMON */

