#ifndef __INC_SBENCSTREAM
#define __INC_SBENCSTREAM

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
#include "sbcryptoprov.h"
#include "sbhashfunction.h"
#include "sbsymmetriccrypto.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElChunkedEncryptingStreamHandle;

typedef TElClassHandle TElChunkedDecryptingStreamHandle;

#ifdef SB_USE_CLASS_TELCHUNKEDENCRYPTINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElChunkedEncryptingStream_Read(TElChunkedEncryptingStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedEncryptingStream_Write(TElChunkedEncryptingStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedEncryptingStream_Seek(TElChunkedEncryptingStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedEncryptingStream_Seek_1(TElChunkedEncryptingStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedEncryptingStream_get_HashAlgorithm(TElChunkedEncryptingStreamHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedEncryptingStream_set_HashAlgorithm(TElChunkedEncryptingStreamHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedEncryptingStream_get_HashResult(TElChunkedEncryptingStreamHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedEncryptingStream_get_SourceStream(TElChunkedEncryptingStreamHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedEncryptingStream_get_Finalized(TElChunkedEncryptingStreamHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedEncryptingStream_get_OnProgress(TElChunkedEncryptingStreamHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedEncryptingStream_set_OnProgress(TElChunkedEncryptingStreamHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedEncryptingStream_get_OnHashResultAvailable(TElChunkedEncryptingStreamHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedEncryptingStream_set_OnHashResultAvailable(TElChunkedEncryptingStreamHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedEncryptingStream_Create(TStreamHandle SourceStream, int32_t Algorithm, const uint8_t pKey[], int32_t szKey, const uint8_t pIV[], int32_t szIV, int64_t Count, TElCustomCryptoProviderManagerHandle Manager, int8_t ReleaseSourceStream, TElChunkedEncryptingStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedEncryptingStream_Create_1(TStreamHandle SourceStream, int32_t Algorithm, TSBSymmetricCryptoModeRaw Mode, const uint8_t pKey[], int32_t szKey, const uint8_t pIV[], int32_t szIV, int64_t Count, TElCustomCryptoProviderManagerHandle Manager, int8_t ReleaseSourceStream, TElChunkedEncryptingStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedEncryptingStream_Create_2(TStreamHandle SourceStream, int32_t Algorithm, TSBSymmetricCryptoModeRaw Mode, const uint8_t pKey[], int32_t szKey, const uint8_t pIV[], int32_t szIV, int64_t Offset, int64_t Count, TElCustomCryptoProviderManagerHandle Manager, int8_t ReleaseSourceStream, TElChunkedEncryptingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELCHUNKEDENCRYPTINGSTREAM */

#ifdef SB_USE_CLASS_TELCHUNKEDDECRYPTINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElChunkedDecryptingStream_FinalizeOutput(TElChunkedDecryptingStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedDecryptingStream_Read(TElChunkedDecryptingStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedDecryptingStream_Write(TElChunkedDecryptingStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedDecryptingStream_Seek(TElChunkedDecryptingStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedDecryptingStream_Seek_1(TElChunkedDecryptingStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedDecryptingStream_get_HashAlgorithm(TElChunkedDecryptingStreamHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedDecryptingStream_set_HashAlgorithm(TElChunkedDecryptingStreamHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedDecryptingStream_get_HashResult(TElChunkedDecryptingStreamHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedDecryptingStream_get_ExpectFinalize(TElChunkedDecryptingStreamHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedDecryptingStream_set_ExpectFinalize(TElChunkedDecryptingStreamHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedDecryptingStream_get_DestStream(TElChunkedDecryptingStreamHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedDecryptingStream_get_OnProgress(TElChunkedDecryptingStreamHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedDecryptingStream_set_OnProgress(TElChunkedDecryptingStreamHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedDecryptingStream_Create(TStreamHandle DestStream, int32_t Algorithm, const uint8_t pKey[], int32_t szKey, const uint8_t pIV[], int32_t szIV, int64_t Count, TElCustomCryptoProviderManagerHandle Manager, int8_t ReleaseDestStream, TElChunkedDecryptingStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedDecryptingStream_Create_1(TStreamHandle DestStream, int32_t Algorithm, TSBSymmetricCryptoModeRaw Mode, const uint8_t pKey[], int32_t szKey, const uint8_t pIV[], int32_t szIV, int64_t Count, TElCustomCryptoProviderManagerHandle Manager, int8_t ReleaseDestStream, TElChunkedDecryptingStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElChunkedDecryptingStream_Create_2(TStreamHandle DestStream, int32_t Algorithm, TSBSymmetricCryptoModeRaw Mode, const uint8_t pKey[], int32_t szKey, const uint8_t pIV[], int32_t szIV, int64_t Offset, int64_t Count, TElCustomCryptoProviderManagerHandle Manager, int8_t ReleaseDestStream, TElChunkedDecryptingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELCHUNKEDDECRYPTINGSTREAM */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElChunkedEncryptingStream;
class TElChunkedDecryptingStream;

#ifdef SB_USE_CLASS_TELCHUNKEDENCRYPTINGSTREAM
class TElChunkedEncryptingStream: public TStream
{
	private:
		SB_DISABLE_COPY(TElChunkedEncryptingStream)
		TStream* _Inst_SourceStream;

		void initInstances();

	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElChunkedEncryptingStream, HashAlgorithm);

		virtual void get_HashResult(std::vector<uint8_t> &OutResult);

		virtual TStream* get_SourceStream();

		SB_DECLARE_PROPERTY_GET(TStream*, get_SourceStream, TElChunkedEncryptingStream, SourceStream);

		virtual bool get_Finalized();

		SB_DECLARE_PROPERTY_GET(bool, get_Finalized, TElChunkedEncryptingStream, Finalized);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnHashResultAvailable(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnHashResultAvailable(TNotifyEvent pMethodValue, void * pDataValue);

		TElChunkedEncryptingStream(TElChunkedEncryptingStreamHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElChunkedEncryptingStream(TStream &SourceStream, int32_t Algorithm, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Count, TElCustomCryptoProviderManager &Manager, bool ReleaseSourceStream);

		TElChunkedEncryptingStream(TStream *SourceStream, int32_t Algorithm, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Count, TElCustomCryptoProviderManager *Manager, bool ReleaseSourceStream);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElChunkedEncryptingStream(TStream &SourceStream, int32_t Algorithm, TSBSymmetricCryptoMode Mode, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Count, TElCustomCryptoProviderManager &Manager, bool ReleaseSourceStream);

		TElChunkedEncryptingStream(TStream *SourceStream, int32_t Algorithm, TSBSymmetricCryptoMode Mode, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Count, TElCustomCryptoProviderManager *Manager, bool ReleaseSourceStream);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElChunkedEncryptingStream(TStream &SourceStream, int32_t Algorithm, TSBSymmetricCryptoMode Mode, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Offset, int64_t Count, TElCustomCryptoProviderManager &Manager, bool ReleaseSourceStream);

		TElChunkedEncryptingStream(TStream *SourceStream, int32_t Algorithm, TSBSymmetricCryptoMode Mode, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Offset, int64_t Count, TElCustomCryptoProviderManager *Manager, bool ReleaseSourceStream);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual ~TElChunkedEncryptingStream();

};
#endif /* SB_USE_CLASS_TELCHUNKEDENCRYPTINGSTREAM */

#ifdef SB_USE_CLASS_TELCHUNKEDDECRYPTINGSTREAM
class TElChunkedDecryptingStream: public TStream
{
	private:
		SB_DISABLE_COPY(TElChunkedDecryptingStream)
		TStream* _Inst_DestStream;

		void initInstances();

	public:
		void FinalizeOutput();

		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElChunkedDecryptingStream, HashAlgorithm);

		virtual void get_HashResult(std::vector<uint8_t> &OutResult);

		virtual bool get_ExpectFinalize();

		virtual void set_ExpectFinalize(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ExpectFinalize, set_ExpectFinalize, TElChunkedDecryptingStream, ExpectFinalize);

		virtual TStream* get_DestStream();

		SB_DECLARE_PROPERTY_GET(TStream*, get_DestStream, TElChunkedDecryptingStream, DestStream);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		TElChunkedDecryptingStream(TElChunkedDecryptingStreamHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElChunkedDecryptingStream(TStream &DestStream, int32_t Algorithm, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Count, TElCustomCryptoProviderManager &Manager, bool ReleaseDestStream);

		TElChunkedDecryptingStream(TStream *DestStream, int32_t Algorithm, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Count, TElCustomCryptoProviderManager *Manager, bool ReleaseDestStream);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElChunkedDecryptingStream(TStream &DestStream, int32_t Algorithm, TSBSymmetricCryptoMode Mode, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Count, TElCustomCryptoProviderManager &Manager, bool ReleaseDestStream);

		TElChunkedDecryptingStream(TStream *DestStream, int32_t Algorithm, TSBSymmetricCryptoMode Mode, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Count, TElCustomCryptoProviderManager *Manager, bool ReleaseDestStream);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElChunkedDecryptingStream(TStream &DestStream, int32_t Algorithm, TSBSymmetricCryptoMode Mode, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Offset, int64_t Count, TElCustomCryptoProviderManager &Manager, bool ReleaseDestStream);

		TElChunkedDecryptingStream(TStream *DestStream, int32_t Algorithm, TSBSymmetricCryptoMode Mode, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Offset, int64_t Count, TElCustomCryptoProviderManager *Manager, bool ReleaseDestStream);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual ~TElChunkedDecryptingStream();

};
#endif /* SB_USE_CLASS_TELCHUNKEDDECRYPTINGSTREAM */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBENCSTREAM */

