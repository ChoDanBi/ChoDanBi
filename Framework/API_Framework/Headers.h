#pragma once

#include <Windows.h>
#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <stack>

using namespace std;

#include "Struct.h"
#include "Enum.h"
#include "Constant.h"
#include "Define.h"
#include "Bitmap.h"

#pragma comment(lib, "msimg32.lib")

/*
// ** �̹���
#pragma comment(lib, "msimg32.lib")


// ** ������
#include <Vfw.h>
#pragma comment(lib, "vfw32.lib")

*/

// ** Sound
#pragma comment(lib, "fmod_vc.lib")
#include <fmod.hpp>
using namespace FMOD;

#include "Struct.h"
#include "Constant.h"

extern HWND g_hWnd;


template <typename T>
inline void Safe_Delete(T& _pObj)
{
	if (_pObj)
	{
		delete _pObj;
		_pObj = nullptr;
	}
}