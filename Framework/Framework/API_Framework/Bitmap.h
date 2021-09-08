#pragma once
#include "Headers.h"
class Bitmap
{
private:
	HDC hdc, MemDC; //hdc�� �׸���(����), MemDC�� �׸� �̸��� ��ĥ��� h�� ����
	HBITMAP hBitmap, Oldbitmap;

public:
	Bitmap* LoadBmp(LPCWSTR _FileName);
	void Release();

public:
	HDC GetMemDC() const { return MemDC; };

public:
	Bitmap();
	~Bitmap();
};

