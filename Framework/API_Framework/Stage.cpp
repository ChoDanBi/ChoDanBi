#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "ObjectFactory.h"
#include "CollisionManager.h"


Stage::Stage() : m_pPlayer(nullptr)
{

}

Stage::~Stage()
{
	Release();
}

void Stage::Initialize()
{
	m_pPlayer = ObjectManager::GetInstance()->GetPlayer();

	for (int i = 0; i < 8; ++i)
	{
		Object* pObj = new Enemy;
		pObj->Initialize();

		pObj->SetPosition(
			float(rand() % (WindowsWidth - 120) + 60), 
			float(rand() % (WindowsHeight - 120) + 60));

		EnemyList.push_back(pObj);
	}
	/* 이렇게 하면 애초에 플레이어에 초기 위치에 생성되는데...
	for (int i = 0; i < 100; i++)
	{
		Object* pObj = new Bullet;
		pObj->Initialize();
		pObj->SetPosition(m_pPlayer->GetPosition());
		BulletList.push_back(pObj);
	}*/

	/*
	EnableList = ObjectManager::GetInstance()->GetEnableList();
	DisableList = ObjectManager::GetInstance()->GetDisableList();

	SetTime = ULONGLONG(rand() % 5000 + 3000);
	Time = GetTickCount64();
	*/
}

void Stage::Update()
{
	m_pPlayer->Update();



	for (vector<Object*>::iterator iter = EnemyList.begin();
		iter != EnemyList.end(); )
	{
		for (vector<Object*>::iterator itr = BulletList.begin(); itr != BulletList.end();)
		{		
		if (CollisionManager::EllipseCollision((*itr), (*iter)))
		{
			iter = EnemyList.erase(iter);
			itr = BulletList.erase(itr);
		}
		else
			++iter;
			itr++;
		}
	}
	/*
	for (list<Object*>::iterator iter = EnableList->begin();
		iter != EnableList->end(); )
	{
		int Result = (*iter)->Update();

		if (Result == 1)
		{
			ObjectManager::GetInstance()->RecallObject(*iter);
			iter = EnableList->erase(iter);
		}
		else
			++iter;
	}

	if (Time + SetTime < GetTickCount64())
	{
		for (int i = 0; i < 6; ++i)
		{
			Vector3 vPos = Vector3(float(WindowsWidth - 100), float(i * 110 + 60));
			ObjectManager::GetInstance()->FindObject("Enemy", vPos);
		}

		SetTime = ULONGLONG(rand() % 5000 + 3000);
		Time = GetTickCount64();
	}
	*/
}

void Stage::Render(HDC _hdc)
{
	m_pPlayer->Render(_hdc);

	for (int i = 0; i < EnemyList.size(); ++i)
		EnemyList[i]->Render(_hdc);

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_SPACE)
	{
		for (int i = 0; i < BulletList.size(); i++)
			BulletList[i]->Render(_hdc);
	}

	/*
	for (list<Object*>::iterator iter = EnableList->begin();
		iter != EnableList->end(); ++iter)
	{
		(*iter)->Render(_hdc);
	}
	*/

}

void Stage::Release()
{

}
