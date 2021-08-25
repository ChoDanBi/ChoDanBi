#pragma once

#include <Windows.h>
#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <string>

using namespace std;

#include "Struct.h"
#include "Enum.h"
#include "Constant.h"





template <typename T>
inline void Safe_Delete(T& _pObj)
{
	if (_pObj)
	{
		delete _pObj;
		_pObj = nullptr;
	}
}