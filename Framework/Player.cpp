#include "Player.h"
#include "InputManager.h"
#include "Bullet.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(0.0f, 0.0f);

	strKey = "Player";
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_UP)
		TransInfo.Position.y--;

	if (dwKey & KEY_DOWN)
		TransInfo.Position.y++;

	if (dwKey & KEY_LEFT)
		TransInfo.Position.x--;

	if (dwKey & KEY_RIGHT)
		TransInfo.Position.x++;

	if (dwKey & KEY_SPACE)
	{
		//** ºí·¿ »ý¼º
		for (int i = 0; i < 1; ++i)
		{
			ObjectManager::GetInstance()->AddObject(
				ObjectFactory<Bullet>::CreateObject());
		}
	}


	/*
	if (dwKey & KEY_ESCAPE)
	{

	}


	if (dwKey & KEY_ENTER)
	{

	}
	*/
	return 0;
}

void Player::Render()
{
	cout << "Player Position : (" << TransInfo.Position.x << ", " << TransInfo.Position.y << ") " << endl;
}

void Player::Release()
{

}
