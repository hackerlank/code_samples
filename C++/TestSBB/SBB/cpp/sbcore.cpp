#include "sbcore.h"
#ifdef SB_U16STRING_USED
#  ifdef SB_HAS_CODECVT_UTF16
#    include <locale>
#    include <codecvt>
#  endif
#endif

namespace SecureBlackbox {

SB_INLINE uint32_t SBGetLastErrorName(char * pstrBuffer, int32_t * nSize)
{
	return SBGetLastErrorNameA(pstrBuffer, nSize);
}

SB_INLINE uint32_t SBGetLastErrorMessage(char * pstrBuffer, int32_t * nSize)
{
	return SBGetLastErrorMessageA(pstrBuffer, nSize);
}

SB_INLINE uint32_t SBGetLastErrorStackTrace(char * pstrBuffer, int32_t * nSize)
{
	return SBGetLastErrorStackTraceA(pstrBuffer, nSize);
}

bool SBGetLastErrorName(std::string &errorName)
{
	int32_t nSize = (int32_t)errorName.capacity();
	if (nSize)
		errorName.resize(nSize);

	uint32_t err = SBGetLastErrorNameA((char *)errorName.data(), &nSize);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == err)
	{
        	errorName.resize(nSize);
		err = SBGetLastErrorNameA((char *)errorName.data(), &nSize);
	}

	if (SB_ERROR_OK == err)
	{
                errorName.resize(nSize);
 		return true;
	}

#if defined(_MSC_VER) && (_MSC_VER <= 1200)
	errorName.resize(0);
#else
	errorName.clear();
#endif
	return false;
}

bool SBGetLastErrorMessage(std::string &errorMsg)
{
	int32_t nSize = (int32_t)errorMsg.capacity();
	if (nSize)
		errorMsg.resize(nSize);

	uint32_t err = SBGetLastErrorMessageA((char *)errorMsg.data(), &nSize);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == err)
	{
        	errorMsg.resize(nSize);
		err = SBGetLastErrorMessageA((char *)errorMsg.data(), &nSize);
	}

	if (SB_ERROR_OK == err)
	{
                errorMsg.resize(nSize);
 		return true;
	}

#if defined(_MSC_VER) && (_MSC_VER <= 1200)
	errorMsg.resize(0);
#else
	errorMsg.clear();
#endif
	return false;
}

bool SBGetLastErrorStackTrace(std::string &errorStackTrace)
{
	int32_t nSize = (int32_t)errorStackTrace.capacity();
	if (nSize)
		errorStackTrace.resize(nSize);

	uint32_t err = SBGetLastErrorStackTraceA((char *)errorStackTrace.data(), &nSize);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == err)
	{
        	errorStackTrace.resize(nSize);
		err = SBGetLastErrorStackTraceA((char *)errorStackTrace.data(), &nSize);
	}

	if (SB_ERROR_OK == err)
	{
                errorStackTrace.resize(nSize);
 		return true;
	}

#if defined(_MSC_VER) && (_MSC_VER <= 1200)
	errorStackTrace.resize(0);
#else
	errorStackTrace.clear();
#endif
	return false;
}

char* htoa(uint32_t val)
{
	static char buf[10] = {0};

	int i = 8;
	for(; val && i ; --i, val >>= 4)
		buf[i] = "0123456789abcdef"[val & 0xf];

	for(; i ; --i)
		buf[i] = '0';

	return &buf[1];
}

SBException::SBException() : std::exception()
{
}

SBException::SBException(uint32_t error) : std::exception()
{
	_Error = error;
	_ErrorCode = SBGetLastErrorCode();
	_SupplErrorCode = SBGetLastSupplErrorCode();
	SBGetLastErrorName(_ErrorName);
	SBGetLastErrorMessage(_ErrorMsg);
	SBGetLastErrorStackTrace(_ErrorStackTrace);
	if (SB_ERROR_RUNTIME == error)
		_ErrorDesc = "SecureBlackbox runtime exception: ";
	else
		_ErrorDesc = "SecureBlackbox library exception: ";

	_ErrorDesc += _ErrorName + "(Message: '" + _ErrorMsg + "', ErrorCode: 0x" + htoa(_ErrorCode);
	if (_SupplErrorCode != 0)
		_ErrorDesc = _ErrorDesc + ", SupplErrorCode: 0x" + htoa(_SupplErrorCode);

	_ErrorDesc += ")";
}

SBException::~SBException() throw()
{
}
		
uint32_t SBException::getError()
{
	return _Error;
}

int32_t SBException::getErrorCode()
{
	return _ErrorCode;
}

int32_t SBException::getSupplErrorCode()
{
	return _SupplErrorCode;
}

std::string SBException::getErrorName() const
{
	return _ErrorName;
}

std::string SBException::getErrorMessage() const
{
	return _ErrorMsg;
}

std::string SBException::getErrorStackTrace() const
{
	return _ErrorStackTrace;
}

const char* SBException::what() const throw()
{
	return _ErrorDesc.c_str();
}

const char* SBInsufficientBufferSizeException::what() const throw()
{
	return "Insufficient Buffer Size";
}

const char* SBInvalidBufferSizeException::what() const throw()
{
	return "Invalid Buffer Size";
}

const char* SBInvalidParameterException::what() const throw()
{
	return "Insufficient Parameter";
}

const char* SBInternalException::what() const throw()
{
	return "Internal error";
}

void SBCheckError(uint32_t error)
{
	if (SB_ERROR_OK != error)
	{
		if ((SB_ERROR_RUNTIME == error) || (SB_ERROR_LIBRARY == error))
			throw SBException(error);
		else if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == error)
			throw SBInsufficientBufferSizeException();
		else if (SB_ERROR_INVALID_BUFFER_SIZE == error)
			throw SBInvalidBufferSizeException();
		else if (SB_ERROR_INVALID_PARAMETER == error)
			throw SBInvalidParameterException();
		else
			throw SBInternalException();
	}
}

SB_INLINE void SBSetEventReturnStringA(int32_t index, const std::string &strBuffer)
{
	SBCheckError(SBSetEventReturnStringA(index, strBuffer.data(), (int32_t)strBuffer.length()));
}

SB_INLINE void SBSetEventReturnStringW(int32_t index, const sb_u16string &strBuffer)
{
	SBCheckError(SBSetEventReturnStringW(index, strBuffer.data(), (int32_t)strBuffer.length()));
}

SB_INLINE void SBSetEventFirstReturnStringA(const std::string &strBuffer)
{
	SBCheckError(SBSetEventFirstReturnStringA(strBuffer.data(), (int32_t)strBuffer.length()));
}

SB_INLINE void SBSetEventFirstReturnStringW(const sb_u16string &strBuffer)
{
	SBCheckError(SBSetEventFirstReturnStringW(strBuffer.data(), (int32_t)strBuffer.length()));
}

#ifdef SB_U16STRING_USED
void SBSetEventReturnStringW(int32_t index, const std::wstring &strBuffer)
{
	std::string u16strBuffer;
	sb_to_u16string(strBuffer, u16strBuffer);
	SBCheckError(SBSetEventReturnStringW(index, reinterpret_cast<const sb_char16_t*>(u16strBuffer.data()), (int32_t)u16strBuffer.length() >> 1));
}

void SBSetEventFirstReturnStringW(const std::wstring &strBuffer)
{
	std::string u16strBuffer;
	sb_to_u16string(strBuffer, u16strBuffer);
	SBCheckError(SBSetEventFirstReturnStringW(reinterpret_cast<const sb_char16_t*>(u16strBuffer.data()), (int32_t)u16strBuffer.length() >> 1));
}
#endif

/*
// For internal use:
void SBGetLastReturnStringA(int32_t idProc, int32_t index, std::string &str, int newSize)
{
	str.resize(newSize);
	SBCheckError(SBGetLastReturnStringA(idProc, index, (char *)str.data(), &newSize));
	str.resize(newSize);
}
*/


#ifdef SB_U16STRING_USED

#  ifdef SB_HAS_CODECVT_UTF16

std::wstring_convert<std::codecvt_utf16<wchar_t, 0x10ffff, std::little_endian>, wchar_t>* wconv = NULL;

#  else

static void ucs4_to_utf16le(const uint32_t* frm, const uint32_t* frm_end, const uint32_t*& frm_nxt,
                uint8_t* to, uint8_t* to_end, uint8_t*& to_nxt, bool generate_header = false)
{
    frm_nxt = frm;
    to_nxt = to;
    if (generate_header)
    {
        if (to_end-to_nxt < 2)
            throw SBInvalidBufferSizeException(); // partial
        *to_nxt++ = static_cast<uint8_t>(0xFF);
        *to_nxt++ = static_cast<uint8_t>(0xFE);
    }
    for (; frm_nxt < frm_end; ++frm_nxt)
    {
        uint32_t wc = *frm_nxt;
        if ((wc & 0xFFFFF800) == 0x00D800 || wc > 0x10FFFF)
            throw SBInternalException(); // error
        if (wc < 0x010000)
        {
            if (to_end-to_nxt < 2)
                throw SBInvalidBufferSizeException(); // partial
            *to_nxt++ = static_cast<uint8_t>(wc);
            *to_nxt++ = static_cast<uint8_t>(wc >> 8);
        }
        else
        {
            if (to_end-to_nxt < 4)
                throw SBInvalidBufferSizeException(); // partial
            uint16_t t = static_cast<uint16_t>(
                    0xD800
                  | ((((wc & 0x1F0000) >> 16) - 1) << 6)
                  |   ((wc & 0x00FC00) >> 10));
            *to_nxt++ = static_cast<uint8_t>(t);
            *to_nxt++ = static_cast<uint8_t>(t >> 8);
            t = static_cast<uint16_t>(0xDC00 | (wc & 0x03FF));
            *to_nxt++ = static_cast<uint8_t>(t);
            *to_nxt++ = static_cast<uint8_t>(t >> 8);
        }
    }
    // OK
}

static void utf16le_to_ucs4(const uint8_t* frm, const uint8_t* frm_end, const uint8_t*& frm_nxt,
                uint32_t* to, uint32_t* to_end, uint32_t*& to_nxt, bool consume_header = false)
{
    frm_nxt = frm;
    to_nxt = to;
    if (consume_header)
    {
        if (frm_end-frm_nxt >= 2 && frm_nxt[0] == 0xFF && frm_nxt[1] == 0xFE)
            frm_nxt += 2;
    }
    for (; frm_nxt < frm_end - 1 && to_nxt < to_end; ++to_nxt)
    {
        uint16_t c1 = static_cast<uint16_t>(frm_nxt[1] << 8 | frm_nxt[0]);
        if ((c1 & 0xFC00) == 0xDC00)
            throw SBInternalException(); // error
        if ((c1 & 0xFC00) != 0xD800)
        {
            //if (c1 > 0x10FFFF)
                //throw SBInternalException(); // error
            *to_nxt = static_cast<uint32_t>(c1);
            frm_nxt += 2;
        }
        else
        {
            if (frm_end-frm_nxt < 4)
                throw SBInvalidBufferSizeException(); // partial
            uint16_t c2 = static_cast<uint16_t>(frm_nxt[3] << 8 | frm_nxt[2]);
            if ((c2 & 0xFC00) != 0xDC00)
                throw SBInternalException(); // error
            uint32_t t = static_cast<uint32_t>(
                    ((((c1 & 0x03C0) >> 6) + 1) << 16)
                  |   ((c1 & 0x003F) << 10)
                  |    (c2 & 0x03FF));
            if (t > 0x10FFFF)
                throw SBInternalException(); // error
            *to_nxt = t;
            frm_nxt += 4;
        }
    }
    if (frm_nxt < frm_end) 
        throw SBInvalidBufferSizeException(); // partial
    // OK
}

#  endif

#ifdef SB_HAS_CODECVT_UTF16
void sb_initialize_string_conv()
{
	if (wconv == NULL)
		wconv = new std::wstring_convert<std::codecvt_utf16<wchar_t, 0x10ffff, std::little_endian>, wchar_t>();
}
#endif

#ifdef SB_HAS_CODECVT_UTF16
void sb_finalize_string_conv()
{
	if (wconv != NULL)
		delete wconv;
}
#endif

#ifdef SB_HAS_CODECVT_UTF16
void sb_to_u16string(const std::wstring &src, sb_u16string &dst)
{
	if (wconv == NULL)
		sb_initialize_string_conv();

	std::string s = wconv->to_bytes(src);
	dst = sb_u16string(
		reinterpret_cast<const sb_char16_t*> (s.data()), s.length() >> 1);
}
#endif

#ifdef SB_HAS_CODECVT_UTF16
void sb_to_wstring(const sb_u16string &src, std::wstring &dst)
{
	if (wconv == NULL)
		sb_initialize_string_conv();

	dst = wconv->from_bytes(
		reinterpret_cast<const char*> (src.data()),
		reinterpret_cast<const char*> (src.data() + src.length()));
}
#endif

void sb_to_u16string(const std::wstring &src, std::string &dst)
{
    if (src.length() == 0)
    {
        dst.resize(0);
        return;
    }

#ifdef SB_HAS_CODECVT_UTF16
	if (wconv == NULL)
		sb_initialize_string_conv();

	dst = wconv->to_bytes(src);
#else
    dst.resize(src.length() << 2);
    const uint32_t* _frm = reinterpret_cast<const uint32_t*>(src.data());
    const uint32_t* _frm_end = reinterpret_cast<const uint32_t*>(src.data() + src.length());
    const uint32_t* _frm_nxt = _frm;
    uint8_t* _to = reinterpret_cast<uint8_t*>((char*)dst.data());
    uint8_t* _to_end = reinterpret_cast<uint8_t*>((char*)dst.data() + dst.length());
    uint8_t* _to_nxt = _to;
    ucs4_to_utf16le(_frm, _frm_end, _frm_nxt, _to, _to_end, _to_nxt);
    dst.resize((size_t)(_to_nxt - _to));
#endif
}

void sb_u16_to_wstring(const std::string &src, std::wstring &dst)
{
    if (src.length() == 0)
    {
        dst.resize(0);
        return;
    }

#ifdef SB_HAS_CODECVT_UTF16
	if (wconv == NULL)
		sb_initialize_string_conv();

    dst = wconv->from_bytes(src.data(), src.data() + src.length());
#else
    dst.resize(src.length());
    const uint8_t* _frm = reinterpret_cast<const uint8_t*>(src.data());
    const uint8_t* _frm_end = reinterpret_cast<const uint8_t*>(src.data() + src.length());
    const uint8_t* _frm_nxt = _frm;
    uint32_t* _to = reinterpret_cast<uint32_t*>((wchar_t*)dst.data());
    uint32_t* _to_end = reinterpret_cast<uint32_t*>((wchar_t*)dst.data() + dst.length());
    uint32_t* _to_nxt = _to;
    utf16le_to_ucs4(_frm, _frm_end, _frm_nxt, _to, _to_end, _to_nxt);
    dst.resize((size_t)(_to_nxt - _to));
#endif
}

#endif

};	/* namespace SecureBlackbox */
