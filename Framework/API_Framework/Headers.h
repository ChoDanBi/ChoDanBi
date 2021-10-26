#pragma once

#include <Windows.h>
#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <stack>

using namespace std;

#include "Enum.h"
#include "Constant.h"
#include "Define.h"
#include "Bitmap.h"

// ** 이미지
#pragma comment(lib, "msimg32.lib")




#include "Struct.h"
#include "Constant.h"

/*
// ** 동영상
#include <Vfw.h>
#pragma comment(lib, "vfw32.lib")
*/


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