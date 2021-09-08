#pragma once
#include "Headers.h"
class Bitmap
{
private:
	HDC hdc, MemDC; //hdc는 그림판(종이), MemDC는 그림 이름이 겹칠까봐 h를 붙임
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

