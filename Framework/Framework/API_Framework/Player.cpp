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

	strKey = "Player";
	Active = false;

	Speed = 3.0f;

	Drop = false;
	bJump = false;

	OldPositionY = 0.0f;
	JumpSpeed = 8.0f;
	JumpTime = 0.0f;
}

int Player::Update()
{
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
		ObjectManager::GetInstance()->AddBullet(TransInfo.Position);
	}

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




void Player::Jump()
{
	if (bJump)
		return;

	bJump = true;
	OldPositionY = TransInfo.Position.y;
	JumpTime = 0.0f;
} 