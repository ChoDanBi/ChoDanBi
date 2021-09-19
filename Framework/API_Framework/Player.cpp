#include "Player.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

#include "Bullet.h"
#include "NormalBullet.h"


Player::Player()
{

}

Player::~Player()
{

}

void Player::Initialize()
{
	TransInfo.Position = Vector3(WindowsWidth / 2, WindowsHeight / 2);
	TransInfo.Scale = Vector3(94.0f, 92.0f);

	Collider.Position = Vector3(TransInfo.Position.x, TransInfo.Position.y - 20.0f);
	Collider.Scale = Vector3(120.0f, 60.0f);

	strKey = "Char";
	Active = false;

	Speed = 3.0f;
	Frame = 0;

	Time = GetTickCount64();
//	Offset = Vector3(95.0f, -85.0f);
	Offset = Vector3(0.0f, 0.0f);

	BulletList = ObjectManager::GetInstance()->GetBulletList();
}

int Player::Update()
{
//	TransInfo.Position = InputManager::GetInstance()->GetMousePosition();
	Collider.Position = InputManager::GetInstance()->GetMousePosition();

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	/*
	if (dwKey & KEY_LBUTTON)
	{
		Frame = 1;
	}
	else
		Frame = 0;
*/

	if (GetAsyncKeyState('Q'))
	{
		BulletList->push_back(CreateBullet<NormalBullet>());
	}

	if (Time + 450 <= GetTickCount64())
	{
		Time = GetTickCount64();
		BulletList->push_back(CreateBullet<NormalBullet>());
		if (Frame == 0) Frame = 1;
		else if (Frame == 1) Frame = 0;
	}

	if (GetAsyncKeyState('W'))			//위로
		TransInfo.Position.y -= Speed;
	if (GetAsyncKeyState('S'))			//아래로
		TransInfo.Position.y += Speed;
	if (GetAsyncKeyState('A'))			//왼쪽으로
		TransInfo.Position.x -= Speed;
	if (GetAsyncKeyState('D'))			//오른쪽으로
		TransInfo.Position.x += Speed;
	return 0;
}

void Player::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		int(TransInfo.Scale.x * Frame),
		int(TransInfo.Scale.y * 0),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));
}

void Player::Release()
{
	
}

template <typename T>
Object* Player::CreateBullet()
{
	Bridge* pBridge = new T;

	Object* pBullet = ObjectFactory<Bullet>::CreateObject(TransInfo.Position, pBridge);

	return pBullet;
}
