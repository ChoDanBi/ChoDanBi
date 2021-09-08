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
	hdc = GetDC(g_hWnd);					//도화지 받기
	MemDC = CreateCompatibleDC(hdc);	//도화지에 그릴 공간 넘기기

	hBitmap = (HBITMAP)LoadImage(NULL,
		_FileName,IMAGE_BITMAP,0,0,
		LR_LOADFROMFILE|LR_CREATEDIBSECTION);	//도구의 개념으로 쓰임:: 도장처럼 찍어냄


	Oldbitmap = (HBITMAP)SelectObject(MemDC, hBitmap);	//hBitmap은 파일에서 이미지 가져와 MemDC에 그려냄

	/*
	LoadImage(
	 _In_opt_ HINSTANCE hInst,
    _In_ LPCWSTR name,
    _In_ UINT type,
    _In_ int cx,
    _In_ int cy,
    _In_ UINT fuLoad);
	*/
	

	ReleaseDC(g_hWnd,hdc);

	return this;
}

void Bitmap::Release()
{
	SelectObject(MemDC, Oldbitmap);
	DeleteObject(hBitmap);
	ReleaseDC(g_hWnd, hdc);
}

