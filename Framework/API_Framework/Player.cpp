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
	TransInfo.Scale = Vector3(482.0f, 424.0f);

	Collider.Position = Vector3(TransInfo.Position.x, TransInfo.Position.y - 20.0f);
	Collider.Scale = Vector3(120.0f, 60.0f);

	//State = STATE::WAIT;

	strKey = "Hammer";
	Active = false;

	Speed = 3.0f;

	Drop = false;
	bJump = false;

	Frame = 0;
	OldPositionY = 0.0f;
	JumpSpeed = 8.0f;
	JumpTime = 0.0f;

	Offset = Vector3(95.0f, -85.0f);

	BulletList = ObjectManager::GetInstance()->GetBulletList();
}

int Player::Update()
{
	TransInfo.Position = InputManager::GetInstance()->GetMousePosition();
	Collider.Position = InputManager::GetInstance()->GetMousePosition();

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_LBUTTON)
	{ 
		//BulletList->push_back(CreateBullet());
		Frame = 1;
	//	State = STATE::HIT;
	}
	else
	{
		Frame = 0; 
	//	State = STATE::WAIT;
	}

	if (GetAsyncKeyState('Q'))
	{
		BulletList->push_back(CreateBullet<NormalBullet>());
	}

	if (GetAsyncKeyState('W'))
	{
		BulletList->push_back(CreateBullet<NormalBullet>());
	}

	return 0;
}

void Player::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		TransInfo.Position.x - (TransInfo.Scale.x / 2) + Offset.x,
		TransInfo.Position.y - (TransInfo.Scale.y / 2) + Offset.y,
		TransInfo.Scale.x,
		TransInfo.Scale.y,
		ImageList[strKey]->GetMemDC(),
		TransInfo.Scale.x * Frame,
		0,
		TransInfo.Scale.x,
		TransInfo.Scale.y,
		RGB(255, 0, 255));

	
	/*Ellipse(_hdc,
		Collider.Position.x - Collider.Scale.x / 2,
		Collider.Position.y - Collider.Scale.y / 2,
		Collider.Position.x + Collider.Scale.x / 2,
		Collider.Position.y + Collider.Scale.y / 2);*/
}

void Player::Release()
{
	
}

void Player::Jump()
{
	if (bJump)
		return;

	bJump = true;
	OldPositionY = TransInfo.Position.y;
	JumpTime = 0.0f;
} 

template <typename T>
Object* Player::CreateBullet()
{
	Bridge* pBridge = new T;

	Object* pBullet = ObjectFactory<Bullet>::CreateObject(TransInfo.Position, pBridge);

	return pBullet;
}
