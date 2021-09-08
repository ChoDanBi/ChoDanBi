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
	hdc = GetDC(g_hWnd);					//��ȭ�� �ޱ�
	MemDC = CreateCompatibleDC(hdc);	//��ȭ���� �׸� ���� �ѱ��

	hBitmap = (HBITMAP)LoadImage(NULL,
		_FileName,IMAGE_BITMAP,0,0,
		LR_LOADFROMFILE|LR_CREATEDIBSECTION);	//������ �������� ����:: ����ó�� ��


	Oldbitmap = (HBITMAP)SelectObject(MemDC, hBitmap);	//hBitmap�� ���Ͽ��� �̹��� ������ MemDC�� �׷���

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

