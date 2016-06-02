#ifndef __INC_SBCORE
#define __INC_SBCORE

#if _MSC_VER > 1000
#  pragma once
#endif

#include "sbdefs.h"

#ifdef __cplusplus

#include <string>
#include <vector>
#include <exception>

#endif


#ifdef _MSC_VER

#  if (_MSC_VER >= 1600)

     // Visual Studio 2010 and up
#    include <stdint.h>

#  else

typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#    if (_MSC_VER >= 1300)
  
       // Visual Studio 2002 and up
       typedef _Longlong int64_t;
       typedef _ULonglong uint64_t;

#    else

       typedef __int64 int64_t;
       typedef unsigned __int64 uint64_t;

#    endif

#  endif

#else

     // GNU C++ Compiler
#    include <inttypes.h>

#endif


#if (WCHAR_MAX == 0xFFFFu) || (defined(__WCHAR_MAX__) && ((__WCHAR_MAX__ == 0x7fff) || (__WCHAR_MAX__ == 0xffff)))

	typedef wchar_t sb_char16_t;

#    ifdef __cplusplus

#      ifdef SB_DEFINE_WSTRING
	namespace std {
		typedef std::basic_string <wchar_t> wstring;
	};
#      endif

	typedef std::wstring sb_u16string;

#    endif

#else

#  if defined(__GXX_EXPERIMENTAL_CXX0X__) || (defined(__cplusplus) && (__cplusplus >= 201103L)) || (defined(_MSC_VER) && (_MSC_VER >= 1600))

	typedef char16_t sb_char16_t;
#       define SB_CHAR16_USED

#    ifdef __cplusplus
	typedef std::u16string sb_u16string;
#       define SB_U16STRING_USED

#       if (defined(_MSC_VER) && (_MSC_VER >= 1600))
#         define SB_HAS_CODECVT_UTF16
#       endif
#       if defined(__has_include)
#         if __has_include(<codecvt>)
#           define SB_HAS_CODECVT_UTF16
#         else
#           undef SB_HAS_CODECVT_UTF16
#         endif
#       endif

#    endif

#  else

#    ifdef SB_DEFINE_CHAR16

	typedef uint16_t sb_char16_t;
#       define SB_CHAR16_USED

#    ifdef __cplusplus
	typedef std::basic_string <sb_char16_t> sb_u16string;
#       define SB_U16STRING_USED
#    endif

#    else
#      ifdef SB_IOS
#error The SecureBlackbox library requires compiler and library support for the ISO C++ 2011 standard. The ISO C++ 2011 standard support may be enabled with the -std=c++11 or -std=gnu++11 or -std=c++0x or -std=gnu++0x compiler options.
#      else
#error The SecureBlackbox library requires either compiler and library support for the ISO C++ 2011 standard or SB_DEFINE_CHAR16 define. The ISO C++ 2011 standard support may be enabled with the -std=c++11 or -std=gnu++11 or -std=c++0x or -std=gnu++0x compiler options. Note: For static library and a project those options should match.
#      endif
#    endif

#  endif

#endif 	/* WCHAR_MAX != 0xFFFFu */


#if defined(__cplusplus) && defined(SB_DEFINE_WSTRING)

namespace std {
	typedef std::basic_string <wchar_t> wstring;
};

#endif


#if defined(LINUX) || defined(MACOS)
#  define SB_APIENTRY
#  define SB_CALLBACK
#else
#  define SB_APIENTRY __stdcall
#  define SB_CALLBACK __stdcall
#endif

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifndef SB_IMPORT
#  ifndef __DECLSPEC_SUPPORTED
#    define SB_IMPORT
#  else
#    define SB_IMPORT
//#    define SB_IMPORT __declspec(dllimport)
#  endif
#endif

#ifndef SB_INLINE
#  ifndef SB_USE_INLINE
#    define SB_INLINE  /* do not inline for static library */
#  else
#    ifdef _MSC_VER
#      define SB_INLINE __forceinline /* use __forceinline (VC++ specific) */
#    else
#      define SB_INLINE inline        /* use standard inline */
#    endif
#  endif
#endif
 
#ifndef SB_DECLARE_PROPERTY
#  if defined(__DECLSPEC_SUPPORTED) && !defined(__MINGW32__)
#    define SB_DECLARE_PROPERTY_GET( type, getfunc, base, var ) \
	__declspec( property( get=getfunc ) ) type var
#    define SB_DECLARE_PROPERTY_SET( type, setfunc, base, var ) \
	__declspec( property( put=setfunc ) ) type var
#    define SB_DECLARE_PROPERTY( type, getfunc, setfunc, base, var ) \
	__declspec( property( get=getfunc, put=setfunc ) ) type var
#  else
#    define SB_DECLARE_PROPERTY_GET( type, getfunc, base, var )
#    define SB_DECLARE_PROPERTY_SET( type, setfunc, base, var )
#    define SB_DECLARE_PROPERTY( type, getfunc, setfunc, base, var )
#  endif
#endif

#if defined(_MSC_VER) && ((_ITERATOR_DEBUG_LEVEL > 0) || _HAS_ITERATOR_DEBUGGING || _SECURE_SCL)
#  define SB_STD_VECTOR_FRONT_ADR(name)  (name.size() ? &name.front() : NULL)
#else
#  define SB_STD_VECTOR_FRONT_ADR(name)  &name.front()
#endif

#define SB_DEFINE_ENUM_FLAG_OPERATORS(name) \
  inline name operator~ (name a) \
  { return static_cast<name>(~static_cast<uint32_t>(a)); } \
  inline name operator| (name a, name b) \
  { return static_cast<name>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b)); } \
  inline name operator& (name a, name b) \
  { return static_cast<name>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b)); } \
  inline name operator^ (name a, name b) \
  { return static_cast<name>(static_cast<uint32_t>(a) ^ static_cast<uint32_t>(b)); }

#define SB_DEFINE_ENUM_FLAG_OPERATORS_U64(name) \
  inline name operator~ (name a) \
  { return static_cast<name>(~static_cast<uint64_t>(a)); } \
  inline name operator| (name a, name b) \
  { return static_cast<name>(static_cast<uint64_t>(a) | static_cast<uint64_t>(b)); } \
  inline name operator& (name a, name b) \
  { return static_cast<name>(static_cast<uint64_t>(a) & static_cast<uint64_t>(b)); } \
  inline name operator^ (name a, name b) \
  { return static_cast<name>(static_cast<uint64_t>(a) ^ static_cast<uint64_t>(b)); }

// disables the use of copy constructors and assignment operators for a class
#define SB_DISABLE_COPY(classname) \
  classname(const classname &); \
  classname & operator=(const classname &);


// #define SB_DEFINE_FPC_SPECIFIC_METHODS


#ifdef __cplusplus
extern "C" {
#endif

#define SB_ERROR_OK				0
#define SB_ERROR_RUNTIME			1
#define SB_ERROR_LIBRARY			2
#define SB_ERROR_INSUFFICIENT_BUFFER_SIZE	3
#define SB_ERROR_INVALID_BUFFER_SIZE		4
#define SB_ERROR_INVALID_PARAMETER		5
#define SB_ERROR_INTERNAL			6

// #define SB_STRING_DEFAULT_SIZE	255

#pragma pack(1)
typedef struct 
{
} TElClassHandleValue, *TElClassHandle;
//typedef uint32_t TElClassHandle;

typedef TElClassHandle TElCallbackStreamHandle;

#define SB_NULL_HANDLE	(TElClassHandle)NULL

typedef int32_t (SB_CALLBACK * TSBCallbackStreamReadFunc)(void * Buffer, int32_t Count, void * Data);
typedef int32_t (SB_CALLBACK * TSBCallbackStreamWriteFunc)(void * Buffer, int32_t Count, void * Data);
typedef int64_t (SB_CALLBACK * TSBCallbackStreamSeekFunc)(int64_t Offset, uint16_t Origin, void * Data);

SB_IMPORT uint32_t SB_APIENTRY SBGetLastError();
SB_IMPORT int32_t SB_APIENTRY SBGetLastErrorCode();
SB_IMPORT int32_t SB_APIENTRY SBGetLastSupplErrorCode();
SB_IMPORT uint32_t SB_APIENTRY SBGetLastErrorNameA(char * pstrBuffer, int32_t * nSize);
SB_IMPORT uint32_t SB_APIENTRY SBGetLastErrorMessageA(char * pstrBuffer, int32_t * nSize);
SB_IMPORT uint32_t SB_APIENTRY SBGetLastErrorStackTraceA(char * pstrBuffer, int32_t * nSize);

SB_IMPORT uint32_t SB_APIENTRY SBGetReturnStringA(int32_t index, char * pstrBuffer, int32_t * nSize);
SB_IMPORT uint32_t SB_APIENTRY SBGetReturnStringW(int32_t index, sb_char16_t * pstrBuffer, int32_t * nSize);
SB_IMPORT uint32_t SB_APIENTRY SBGetReturnBuffer(int32_t index, void * pBuffer, int32_t * nSize);

SB_IMPORT uint32_t SB_APIENTRY SBSetEventReturnStringA(int32_t index, const char * pstrBuffer, int32_t nSize);
SB_IMPORT uint32_t SB_APIENTRY SBSetEventReturnStringW(int32_t index, const sb_char16_t * pstrBuffer, int32_t nSize);
SB_IMPORT uint32_t SB_APIENTRY SBSetEventReturnBuffer(int32_t index, const void * pBuffer, int32_t nSize);

SB_IMPORT uint32_t SB_APIENTRY SBSetEventFirstReturnStringA(const char * pstrBuffer, int32_t nSize);
SB_IMPORT uint32_t SB_APIENTRY SBSetEventFirstReturnStringW(const sb_char16_t * pstrBuffer, int32_t nSize);
SB_IMPORT uint32_t SB_APIENTRY SBSetEventFirstReturnBuffer(const void * pBuffer, int32_t nSize);

// For internal use:
SB_IMPORT uint32_t SB_APIENTRY SBGetLastReturnStringA(int32_t idProc, int32_t index, char * pstrBuffer, int32_t * nSize);
SB_IMPORT uint32_t SB_APIENTRY SBGetLastReturnStringW(int32_t idProc, int32_t index, sb_char16_t * pstrBuffer, int32_t * nSize);
SB_IMPORT uint32_t SB_APIENTRY SBGetLastReturnBuffer(int32_t idProc, int32_t index, void * pBuffer, int32_t * nSize);

SB_IMPORT uint32_t SB_APIENTRY TElCallbackStream_Create(void * Data, TSBCallbackStreamReadFunc ReadFunc, TSBCallbackStreamWriteFunc WriteFunc, TSBCallbackStreamSeekFunc SeekFunc, TElCallbackStreamHandle * OutResult);

// #ifdef UNICODE
// #else
// #endif

// SB_IMPORT void SB_APIENTRY SBRegisterCallbacks();

#ifdef __cplusplus
};	/* extern "C" */
#endif


#ifdef __cplusplus

// typedef enum {
//  ohFalse = 0,
//  ohTrue = 1
// } TElOwnHandle;

typedef bool TElOwnHandle;

#define ohFalse false
#define ohTrue true
#define SB_OWN_HANDLE true
// #define SB_OWN_HANDLE	ohTrue

// int SBGetLastErrorNameW(sb_char16_t * pstrBuffer, int32_t * nSize);

uint32_t SBGetLastErrorName(char * pstrBuffer, int32_t * nSize);
uint32_t SBGetLastErrorMessage(char * pstrBuffer, int32_t * nSize);
uint32_t SBGetLastErrorStackTrace(char * pstrBuffer, int32_t * nSize);

bool SBGetLastErrorName(std::string &errorName);
bool SBGetLastErrorMessage(std::string &errorMsg);
bool SBGetLastErrorStackTrace(std::string &errorStackTrace);

class SBException : public std::exception
{
        protected:
                uint32_t _Error;
                int32_t _ErrorCode;
                int32_t _SupplErrorCode;
                std::string _ErrorName;
                std::string _ErrorMsg;
                std::string _ErrorStackTrace;
                std::string _ErrorDesc;
	public:
		SBException();

		SBException(uint32_t error);

		~SBException() throw();
		
		uint32_t getError();

		int32_t getErrorCode();

		int32_t getSupplErrorCode();

		std::string getErrorName() const;

		std::string getErrorMessage() const;

		std::string getErrorStackTrace() const;

		virtual const char* what() const throw();

                SB_DECLARE_PROPERTY_GET(uint32_t, getError, SBException, Error);
};

class SBInsufficientBufferSizeException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class SBInvalidBufferSizeException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class SBInvalidParameterException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class SBInternalException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

void SBCheckError(uint32_t error);

void SBSetEventReturnStringA(int32_t index, const std::string &strBuffer);
void SBSetEventReturnStringW(int32_t index, const sb_u16string &strBuffer);
void SBSetEventFirstReturnStringA(const std::string &strBuffer);
void SBSetEventFirstReturnStringW(const sb_u16string &strBuffer);
#ifdef SB_U16STRING_USED
void SBSetEventReturnStringW(int32_t index, const std::wstring &strBuffer);
void SBSetEventFirstReturnStringW(const std::wstring &strBuffer);
#endif

#ifdef SB_U16STRING_USED
#ifdef SB_HAS_CODECVT_UTF16
void sb_initialize_string_conv();
void sb_finalize_string_conv();
void sb_to_u16string(const std::wstring &src, sb_u16string &dst);
void sb_to_wstring(const sb_u16string &src, std::wstring &dst);
#endif
void sb_to_u16string(const std::wstring &src, std::string &dst);
void sb_u16_to_wstring(const std::string &src, std::wstring &dst);
#endif

#endif	/* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCORE */
