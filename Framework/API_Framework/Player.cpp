#include "Player.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "InventoryManager.h"

#include "Bullet.h"
#include "NormalBullet.h"
#include "Boom.h"


Player::Player()
{

}

Player::~Player()
{

}

void Player::Initialize()
{
	TransInfo.Position = Vector3(WindowsWidth / 2, WindowsHeight / 2);
	TransInfo.Scale = Vector3(63.5f, 63.0f);

	Collider.Position = Vector3(0.0f,-500.0f);
	Collider.Scale = Vector3(56.0f, 56.0f);

	strKey = "Char";
	Active = true;
	s_Active = true;

	HitPoint = 3;
	Speed = InventoryManager::GetInstance()->GetItem(INVENTORY::SPEED);
	Frame = 0;

	Time[0] = GetTickCount64();
	Time [1]= GetTickCount64();
	Time [2]= GetTickCount64();
	nTime[0] = 0;
	nTime[1] = 0;

	BulletList = ObjectManager::GetInstance()->GetBulletList();
}

int Player::Update()
{
	if (TransInfo.Position.x < 0)
		TransInfo.Position.x += Speed;
	else if (TransInfo.Position.x > 1270)
		TransInfo.Position.x -= Speed;

	if (TransInfo.Position.y < 0)
		TransInfo.Position.y += Speed;
	else if (TransInfo.Position.y > 720)
		TransInfo.Position.y -= Speed;

	if (GetAsyncKeyState('W'))			//위로
		TransInfo.Position.y -= Speed;
	if (GetAsyncKeyState('S'))			//아래로
		TransInfo.Position.y += Speed;
	if (GetAsyncKeyState('A'))			//왼쪽으로
		TransInfo.Position.x -= Speed;
	if (GetAsyncKeyState('D'))			//오른쪽으로
		TransInfo.Position.x += Speed;
	
	Collider.Position = TransInfo.Position;

	if (Time[0] + 200 <= GetTickCount64())
	{
		Time[0] = GetTickCount64();
	
		if (InventoryManager::GetInstance()->GetItem(INVENTORY::DAMAGE) / 6 == 1)
		{
			BulletList->push_back(CreateBullet<NormalBullet>(0));
			BulletList->push_back(CreateBullet<NormalBullet>(2));
		}
		
		BulletList->push_back(CreateBullet<NormalBullet>(1));
	

		if (Frame == 0) Frame = 1;
		else if (Frame == 1) Frame = 0;
	}
	if (GetAsyncKeyState('Q') &0x0001 && InventoryManager::GetInstance()->GetItem(INVENTORY::BOMB) > 0)
	{
		InventoryManager::GetInstance()->UseItem(INVENTORY::BOMB);
		BulletList->push_back(CreateBullet<Boom>(0));
	}
	if ( Active && GetAsyncKeyState('E') & 0x0001 && InventoryManager::GetInstance()->GetItem(INVENTORY::SHIELD) > 0)
	{
		InventoryManager::GetInstance()->UseItem(INVENTORY::SHIELD);
		Active = s_Active = false;
	}

	if (!s_Active && Time[2] + 350 < GetTickCount64())
	{
		Time[2] = GetTickCount64();
		nTime[1]++;

		if (nTime[1] >= 11)
		{
			nTime[1] = 0;
			Active = s_Active = true;
		}
	}

	if (!Active && Time[1] + 350 < GetTickCount64() && s_Active)
	{
		Time[1] = GetTickCount64();
		nTime[0]++;

		if (nTime[0] >= 11)
		{
			nTime[0] = 0;
			Active = true;
		}
	}



	return 0;
}

void Player::Render(HDC _hdc)
{
	if (!s_Active)
		TransparentBlt(_hdc,
			int(TransInfo.Position.x - (216 / 2)),
			int(TransInfo.Position.y - (179 / 2)),
			216,
			179,
			ImageList["Shild"]->GetMemDC(),
			0,
			0,
			216,
			179,
			RGB(255, 0, 255));

	if (Active || !Active && nTime[0] % 2 == 0)
	{
		TransparentBlt(_hdc,
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
	
	TransparentBlt(_hdc, 
		860,
		570,
		384 - 128 * (3 - HitPoint),
		128,
		ImageList["Heart"]->GetMemDC(),
		0, 0,
		384- 128*(3-HitPoint),128,
		RGB(255, 0, 255));

	/*
	Ellipse(_hdc,
		int(Collider.Position.x - Collider.Scale.x / 2),
		int(Collider.Position.y - Collider.Scale.y / 2),
		int(Collider.Position.x + Collider.Scale.x / 2),
		int(Collider.Position.y + Collider.Scale.y / 2) );
	*/
}

void Player::Release()
{
	
}

template <typename T>
Object* Player::CreateBullet(int _Pattern)
{
	Bridge* pBridge = new T;

	Object* pBullet = ObjectFactory<Bullet>::CreateObject(TransInfo.Position, pBridge, _Pattern);

	return pBullet;
}
