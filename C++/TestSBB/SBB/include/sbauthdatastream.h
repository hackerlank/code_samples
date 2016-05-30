#ifndef __INC_SBAUTHDATASTREAM
#define __INC_SBAUTHDATASTREAM

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstringlist.h"
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
typedef TElClassHandle TElAuthenticatedDataWriteStreamHandle;

typedef TElClassHandle TElAuthenticatedDataReadStreamHandle;

typedef uint8_t TSBAuthenticatedDataDigestsLocationRaw;

typedef enum
{
	addlNoDigests = 0,
	addlExternal = 1,
	addlEmbedded = 2,
	addlAppended = 3
} TSBAuthenticatedDataDigestsLocation;

#ifdef SB_USE_CLASS_TELAUTHENTICATEDDATAWRITESTREAM
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataWriteStream_Read(TElAuthenticatedDataWriteStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataWriteStream_Write(TElAuthenticatedDataWriteStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataWriteStream_Seek(TElAuthenticatedDataWriteStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataWriteStream_Seek_1(TElAuthenticatedDataWriteStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataWriteStream_get_CachedDigests(TElAuthenticatedDataWriteStreamHandle _Handle, TElByteArrayListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataWriteStream_get_OnProgress(TElAuthenticatedDataWriteStreamHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataWriteStream_set_OnProgress(TElAuthenticatedDataWriteStreamHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataWriteStream_Create(TStreamHandle SourceStream, int32_t Algorithm, int64_t BlockSize, int32_t DigestSize, TSBAuthenticatedDataDigestsLocationRaw DigestsLocation, const uint8_t pKey[], int32_t szKey, int64_t StartBlockNumber, int64_t Count, TElCustomCryptoProviderManagerHandle Manager, TElAuthenticatedDataWriteStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELAUTHENTICATEDDATAWRITESTREAM */

#ifdef SB_USE_CLASS_TELAUTHENTICATEDDATAREADSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataReadStream_FinalizeOutput(TElAuthenticatedDataReadStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataReadStream_Read(TElAuthenticatedDataReadStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataReadStream_Write(TElAuthenticatedDataReadStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataReadStream_Seek(TElAuthenticatedDataReadStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataReadStream_Seek_1(TElAuthenticatedDataReadStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataReadStream_get_ExpectFinalize(TElAuthenticatedDataReadStreamHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataReadStream_set_ExpectFinalize(TElAuthenticatedDataReadStreamHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataReadStream_get_CachedDigests(TElAuthenticatedDataReadStreamHandle _Handle, TElByteArrayListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataReadStream_get_OnProgress(TElAuthenticatedDataReadStreamHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataReadStream_set_OnProgress(TElAuthenticatedDataReadStreamHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticatedDataReadStream_Create(TStreamHandle DestStream, int32_t Algorithm, int64_t BlockSize, int32_t DigestSize, TSBAuthenticatedDataDigestsLocationRaw DigestsLocation, const uint8_t pKey[], int32_t szKey, int64_t StartBlockNumber, TElCustomCryptoProviderManagerHandle Manager, TElAuthenticatedDataReadStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELAUTHENTICATEDDATAREADSTREAM */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElAuthenticatedDataWriteStream;
class TElAuthenticatedDataReadStream;

#ifdef SB_USE_CLASS_TELAUTHENTICATEDDATAWRITESTREAM
class TElAuthenticatedDataWriteStream: public TStream
{
	private:
		SB_DISABLE_COPY(TElAuthenticatedDataWriteStream)
#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
		TElByteArrayList* _Inst_CachedDigests;
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

		void initInstances();

	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
		virtual TElByteArrayList* get_CachedDigests();

		SB_DECLARE_PROPERTY_GET(TElByteArrayList*, get_CachedDigests, TElAuthenticatedDataWriteStream, CachedDigests);
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		TElAuthenticatedDataWriteStream(TElAuthenticatedDataWriteStreamHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElAuthenticatedDataWriteStream(TStream &SourceStream, int32_t Algorithm, int64_t BlockSize, int32_t DigestSize, TSBAuthenticatedDataDigestsLocation DigestsLocation, const std::vector<uint8_t> &Key, int64_t StartBlockNumber, int64_t Count, TElCustomCryptoProviderManager &Manager);

		TElAuthenticatedDataWriteStream(TStream *SourceStream, int32_t Algorithm, int64_t BlockSize, int32_t DigestSize, TSBAuthenticatedDataDigestsLocation DigestsLocation, const std::vector<uint8_t> &Key, int64_t StartBlockNumber, int64_t Count, TElCustomCryptoProviderManager *Manager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual ~TElAuthenticatedDataWriteStream();

};
#endif /* SB_USE_CLASS_TELAUTHENTICATEDDATAWRITESTREAM */

#ifdef SB_USE_CLASS_TELAUTHENTICATEDDATAREADSTREAM
class TElAuthenticatedDataReadStream: public TStream
{
	private:
		SB_DISABLE_COPY(TElAuthenticatedDataReadStream)
#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
		TElByteArrayList* _Inst_CachedDigests;
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

		void initInstances();

	public:
		void FinalizeOutput();

		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		virtual bool get_ExpectFinalize();

		virtual void set_ExpectFinalize(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ExpectFinalize, set_ExpectFinalize, TElAuthenticatedDataReadStream, ExpectFinalize);

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
		virtual TElByteArrayList* get_CachedDigests();

		SB_DECLARE_PROPERTY_GET(TElByteArrayList*, get_CachedDigests, TElAuthenticatedDataReadStream, CachedDigests);
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		TElAuthenticatedDataReadStream(TElAuthenticatedDataReadStreamHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElAuthenticatedDataReadStream(TStream &DestStream, int32_t Algorithm, int64_t BlockSize, int32_t DigestSize, TSBAuthenticatedDataDigestsLocation DigestsLocation, const std::vector<uint8_t> &Key, int64_t StartBlockNumber, TElCustomCryptoProviderManager &Manager);

		TElAuthenticatedDataReadStream(TStream *DestStream, int32_t Algorithm, int64_t BlockSize, int32_t DigestSize, TSBAuthenticatedDataDigestsLocation DigestsLocation, const std::vector<uint8_t> &Key, int64_t StartBlockNumber, TElCustomCryptoProviderManager *Manager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual ~TElAuthenticatedDataReadStream();

};
#endif /* SB_USE_CLASS_TELAUTHENTICATEDDATAREADSTREAM */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBAUTHDATASTREAM */

