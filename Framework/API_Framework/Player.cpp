#include "Player.h"
#include "InputManager.h"
#include "ObjectManager.h"

#include "Bullet.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::Initialize()
{
	TransInfo.Position = Vector3(WindowsWidth / 2, WindowsHeight / 2);
	TransInfo.Scale = Vector3(100.0f, 100.0f);

	//strKey = "Player";
	//Active = false;

	//Speed = 3.0f;
}

int Player::Update()
{
	TransInfo.Position = InputManager::GetInstance()->GetMousePosition();



	/*
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_UP)
		TransInfo.Position.y -= Speed;

	if (dwKey & KEY_DOWN)
		TransInfo.Position.y += Speed;

	if (dwKey & KEY_LEFT)
		TransInfo.Position.x -= Speed;

	if (dwKey & KEY_RIGHT)
		TransInfo.Position.x += Speed;

	if (dwKey & KEY_SPACE)
	{
		//** 블렛 생성
		ObjectManager::GetInstance()->FindObject("Bullet", TransInfo.Position);
	}
	*/

	return 0;
}

void Player::Render(HDC _hdc)
{
	// ** 동그라미 함수
	Ellipse(_hdc, 
		int(TransInfo.Position.x - (TransInfo.Scale.x/2)) ,
		int(TransInfo.Position.y - (TransInfo.Scale.x/2)) , 
		int(TransInfo.Position.x + (TransInfo.Scale.x/2)) , 
		int(TransInfo.Position.y + (TransInfo.Scale.x/2)) );
}

void Player::Release()
{

}
