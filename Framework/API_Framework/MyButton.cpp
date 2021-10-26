#include "MyButton.h"
#include "InputManager.h"
#include "CollisionManager.h"

MyButton::MyButton()
{

}

MyButton::~MyButton()
{

}


void MyButton::Initialize()
{
	TransInfo.Position = Vector3(WindowsWidth - 250 , 150.0f);
	TransInfo.Scale = Vector3(187.0f, 113.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);

	strKey = "";
	Active = false;
	Speed = 3;

	MOVE = false;
	Horizontal = false;
	ButtonOffSet[0] = (int(187.0f / 4));
	ButtonOffSet[1] = int(ButtonOffSet[0] - 85);
	Time = GetTickCount64();
	//Offset = Vector3(0.0f, 0.0f);
}

int MyButton::Update()
{
	Transform Mouse;

	Mouse.Position = InputManager::GetInstance()->GetMousePosition();
	Mouse.Scale = Vector3(5.0f, 5.0f);

	if (CollisionManager::EllipseCollision(TransInfo, Mouse))
	{
		DWORD dwKey = InputManager::GetInstance()->GetKey();

		if (dwKey & KEY_LBUTTON)
		{
			Time = GetTickCount64();

			Check();
		}
		else
			MOVE = false;
	}

	return 0;
}

void MyButton::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Scale.x), int(TransInfo.Scale.y),
		ImageList["on_off_Back"]->GetMemDC(),
		int(TransInfo.Scale.x * 0), int(TransInfo.Scale.y * 0),
		int(TransInfo.Scale.x), int(TransInfo.Scale.y),
		RGB(255, 0, 255));

	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(TransInfo.Position.x - (69.0f / 2) + ButtonOffSet[Horizontal]),
		int(TransInfo.Position.y - (73.0f / 2) ), //Offset.y),
		int(69.0f), int(73.0f),
		ImageList["on_off_Button"]->GetMemDC(),
		int(69.0f * 0), int(73.0f * 0),
		int(69.0f), int(73.0f),
		RGB(255, 0, 255));
}

void MyButton::Release()
{

}

void MyButton::Check()
{
	if (MOVE)
		return;

	MOVE = true;
	Horizontal = !Horizontal;
}