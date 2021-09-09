#include "Bitmap.h"


Bitmap::Bitmap()
{

}

Bitmap::~Bitmap()
{
	Release();
}


Bitmap* Bitmap::LoadBmp(LPCWSTR _FileName)
{
	hdc = GetDC(g_hWnd);
	MemDC = CreateCompatibleDC(hdc);

	/*
	LoadImageW(
	_In_opt_ HINSTANCE hInst,
	_In_ LPCWSTR name,
	_In_ UINT type,
	_In_ int cx,
	_In_ int cy,
	_In_ UINT fuLoad);
	*/

	hBitmap = (HBITMAP)LoadImage(NULL,
		_FileName, IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);



	OldBitmap = (HBITMAP)SelectObject(MemDC, hBitmap);

	ReleaseDC(g_hWnd, hdc);

	return this;
}

void Bitmap::Release()
{
	SelectObject(MemDC, OldBitmap);
	DeleteObject(hBitmap);
	ReleaseDC(g_hWnd, MemDC);
}

