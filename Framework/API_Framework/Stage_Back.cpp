#include "Stage_Back.h"

Stage_Back::Stage_Back()
{

}

Stage_Back::~Stage_Back()
{

}


void Stage_Back::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(0.0f, 0.0f);

	strKey = "Bullet";
	Active = false;
}

int Stage_Back::Update()
{

	return 0;
}

void Stage_Back::Render(HDC _hdc)
{
	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Stay"]->GetMemDC(),
		0, 30,
		SRCCOPY);
}

void Stage_Back::Release()
{

}

