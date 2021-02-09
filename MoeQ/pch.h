// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#define _CRT_SECURE_NO_WARNINGS

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"
#include "resource.h"

#include <vector>
#include <random>
#include <chrono>

#include "Defined.h"

#include "..\include\rapidjson\document.h"
#include "..\include\sqlite3\sqlite3.h"
#include <openssl\sha.h>
#include <openssl\md5.h>
#include <openssl\ecdh.h>
#include <openssl\des.h>
#include "..\include\zlib\zlib.h"
#include "..\include\miniblink\wke.h" //include windows.h

#pragma comment(lib, "crypt32.lib")

#ifdef _WINDOWS
#ifdef _DEBUG
#pragma comment(lib, "..\\lib\\openssl_lib_windows\\x64\\libcrypto.lib")
#pragma comment(lib, "..\\lib\\zlib_lib_windows\\x64\\zlibstat.lib")
#pragma comment(lib, "..\\lib\\sqlite3_lib_windows\\debug\\x64\\sqlite3.lib")
#else
#pragma comment(lib, "..\\lib\\openssl_lib_windows\\x64\\libcrypto.lib")
#pragma comment(lib, "..\\lib\\zlib_lib_windows\\x64\\zlibstat.lib")
#pragma comment(lib, "..\\lib\\sqlite3_lib_windows\\release\\x64\\sqlite3.lib")
#endif
#elif _MAC
#pragma comment(lib, "..\\lib\\openssl_lib_mac\\libcrypto.a")
#pragma comment(lib, "..\\lib\\zlib_lib_mac\\zlibstat.a")
#endif

#endif //PCH_H
