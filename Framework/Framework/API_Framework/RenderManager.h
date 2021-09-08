#pragma once
#include "Headers.h"

class RenderManager
{
private:
	HDC hdc, MemDC; //hdc는 그림판(종이), MemDC는 그림 이름이 겹칠까봐 h를 붙임
	HBITMAP Bitmap, Oldbitmap;

public:
	//RenderManager*
	void Release();

public:
	RenderManager();
	~RenderManager();
};

