#include "sbmisc.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TSTREAM

#if defined(_MSC_VER)
//#  pragma warning(push)
//#  pragma warning(disable : 4996) // disable unsafe call
#endif 

int32_t SB_APIENTRY CallbackIStreamReadFunc(void * buffer, int32_t count, std::istream &stream)
{
	stream.read((char *)buffer, count);
	int32_t n = (int32_t)stream.gcount();
	if (stream.good())
		return n;
	else
		return 0;
}

#if defined(_MSC_VER)
//#pragma warning(pop)
#endif 

int32_t SB_APIENTRY CallbackOStreamWriteFunc(void * buffer, int32_t count, std::ostream &stream)
{
	stream.write((char *)buffer, count);
	if (stream.good())
		return count;
	else
		return 0;
}

int64_t SB_APIENTRY CallbackIStreamSeekFunc(int64_t offset, uint16_t origin, std::istream &stream)
{
	if (soFromCurrent == origin)
	{
		if (offset != 0)
			stream.seekg((std::streamoff)offset, std::ios_base::cur);
	}
	else if (soFromBeginning == origin)
		stream.seekg((std::streamoff)offset, std::ios_base::beg);
	else
		stream.seekg((std::streamoff)offset, std::ios_base::end);

	return stream.tellg();
}
 
int64_t SB_APIENTRY CallbackOStreamSeekFunc(int64_t offset, uint16_t origin, std::ostream &stream)
{
	if (soFromCurrent == origin)
	{
		if (offset != 0)
			stream.seekp((std::streamoff)offset, std::ios_base::cur);
	}
	else if (soFromBeginning == origin)
		stream.seekp((std::streamoff)offset, std::ios_base::beg);
	else
		stream.seekp((std::streamoff)offset, std::ios_base::end);

	return stream.tellp();
}

int64_t SB_APIENTRY CallbackIOStreamSeekFunc(int64_t offset, uint16_t origin, std::iostream &stream)
{
	if (soFromCurrent == origin)
	{
		if (offset != 0)
		{
			stream.seekg((std::streamoff)offset, std::ios_base::cur);
			stream.seekp((std::streamoff)offset, std::ios_base::cur);
		}
	}
	else if (soFromBeginning == origin)
	{
		stream.seekg((std::streamoff)offset, std::ios_base::beg);
		stream.seekp((std::streamoff)offset, std::ios_base::beg);
	}
	else
	{
		stream.seekg((std::streamoff)offset, std::ios_base::end);
		stream.seekp((std::streamoff)offset, std::ios_base::end);
	}

	return stream.tellg();
}
 
TElCallbackStream::TElCallbackStream(TElCallbackStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
}

TElCallbackStream::TElCallbackStream(std::iostream &stream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCallbackStream_Create(&stream, (TSBCallbackStreamReadFunc)CallbackIStreamReadFunc,
		(TSBCallbackStreamWriteFunc)CallbackOStreamWriteFunc, 
		(TSBCallbackStreamSeekFunc)CallbackIOStreamSeekFunc, &_Handle));
}

TElCallbackStream::TElCallbackStream(std::ostream &stream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCallbackStream_Create(&stream, (TSBCallbackStreamReadFunc)NULL,
		(TSBCallbackStreamWriteFunc)CallbackOStreamWriteFunc, 
		(TSBCallbackStreamSeekFunc)CallbackOStreamSeekFunc, &_Handle));
}

TElCallbackStream::TElCallbackStream(std::istream &stream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCallbackStream_Create(&stream, (TSBCallbackStreamReadFunc)CallbackIStreamReadFunc,
		(TSBCallbackStreamWriteFunc)NULL, 
		(TSBCallbackStreamSeekFunc)CallbackIStreamSeekFunc, &_Handle));
}

TElCallbackStream::TElCallbackStream(void * data, TSBCallbackStreamReadFunc readFunc, TSBCallbackStreamWriteFunc writeFunc, TSBCallbackStreamSeekFunc seekFunc) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCallbackStream_Create(data, readFunc, writeFunc, seekFunc, &_Handle));
}

#endif /* SB_USE_CLASS_TSTREAM */

};	/* namespace SecureBlackbox */
