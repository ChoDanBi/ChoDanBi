#pragma once
#include "Headers.h"

class RenderManager
{
private:
	HDC hdc, MemDC; //hdc�� �׸���(����), MemDC�� �׸� �̸��� ��ĥ��� h�� ����
	HBITMAP Bitmap, Oldbitmap;

public:
	//RenderManager*
	void Release();

public:
	RenderManager();
	~RenderManager();
};

