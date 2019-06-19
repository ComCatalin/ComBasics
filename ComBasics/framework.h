// header.h : include file for standard system include files,
// or project specific include files
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#include <atlbase.h>
#include <wrl.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#define NOMINMAX

#define ASSERT ATLASSERT
#define VERIFY ATLVERIFY
#define TRACE ATLTRACE

#ifdef DEBUG
#define HR(expression) ASSERT(S_OK == (expression))
#else
struct ComException
{
	HRESULT const hr;
	ComException(HRESULT const value) : hr(value) {}
};

inline void HR(HRESULT hr)
{
	if (S_OK != hr) throw ComException(hr);
}
#endif

#pragma warning(disable: 4706)
