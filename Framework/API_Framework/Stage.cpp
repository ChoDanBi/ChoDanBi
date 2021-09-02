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

	m_Bullet = ObjectManager::GetInstance()->CreateObject("Bullet", m_pPlayer->GetPosition());

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
}
	//여기서 얘네들 생성하고 삭제하는데 그럼 여기서 bullet을 만들어야 하는데...
void Stage::Update()
{
	m_pPlayer->Update();

	m_Bullet->Update(); //bullet이 없는데 작동시키면 터지니까...

	for (vector<Object*>::iterator iter = EnemyList.begin();
		iter != EnemyList.end(); )
	{
		if (CollisionManager::EllipseCollision(m_Bullet, (*iter)))
		{
			iter = EnemyList.erase(iter);
		}
		else
			++iter;
	}

	/*
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
	}*/
	
}

void Stage::Render(HDC _hdc)
{
	m_pPlayer->Render(_hdc);

	m_Bullet->Render(_hdc);

	for (int i = 0; i < EnemyList.size(); ++i)
		EnemyList[i]->Render(_hdc);

	/*
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_SPACE)
	{
		for (int i = 0; i < BulletList.size(); i++)
			BulletList[i]->Render(_hdc);
	}
*/
	

}

void Stage::Release()
{

}
