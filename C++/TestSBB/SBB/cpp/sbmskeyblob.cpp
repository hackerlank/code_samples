#include "sbmskeyblob.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_MSKEYBLOB

bool WriteMSPublicKeyBlob(void * Buffer, int32_t Size, void * OutBuffer, int32_t &OutSize, int32_t BlobType)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBMSKeyBlob_WriteMSPublicKeyBlob(Buffer, Size, OutBuffer, &OutSize, BlobType, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool WriteMSDSSPublicKeyBlob(void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBMSKeyBlob_WriteMSDSSPublicKeyBlob(P, PSize, Q, QSize, G, GSize, Y, YSize, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t ParseMSKeyBlob(void * Buffer, int32_t Size, void * OutBuffer, int32_t &OutSize, int32_t &BlobType)
{
	int32_t OutResult;
	SBCheckError(SBMSKeyBlob_ParseMSKeyBlob(Buffer, Size, OutBuffer, &OutSize, &BlobType, &OutResult));
	return OutResult;
}

bool WriteMSKeyBlob(void * Buffer, int32_t Size, void * OutBuffer, int32_t &OutSize, uint8_t BlobType)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBMSKeyBlob_WriteMSKeyBlob(Buffer, Size, OutBuffer, &OutSize, BlobType, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
bool WriteMSKeyBlobEx(void * Buffer, int32_t Size, void * OutBuffer, int32_t &OutSize, TElAlgorithmIdentifier &Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBMSKeyBlob_WriteMSKeyBlobEx(Buffer, Size, OutBuffer, &OutSize, Algorithm.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}
bool WriteMSKeyBlobEx(void * Buffer, int32_t Size, void * OutBuffer, int32_t &OutSize, TElAlgorithmIdentifier *Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBMSKeyBlob_WriteMSKeyBlobEx(Buffer, Size, OutBuffer, &OutSize, (Algorithm != NULL) ? Algorithm->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#endif /* SB_USE_GLOBAL_PROCS_MSKEYBLOB */

};	/* namespace SecureBlackbox */

