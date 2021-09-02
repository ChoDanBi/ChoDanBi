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
	/* �̷��� �ϸ� ���ʿ� �÷��̾ �ʱ� ��ġ�� �����Ǵµ�...
	for (int i = 0; i < 100; i++)
	{
		Object* pObj = new Bullet;
		pObj->Initialize();
		pObj->SetPosition(m_pPlayer->GetPosition());
		BulletList.push_back(pObj);
	}*/
}
	//���⼭ ��׵� �����ϰ� �����ϴµ� �׷� ���⼭ bullet�� ������ �ϴµ�...
void Stage::Update()
{
	m_pPlayer->Update();

	m_Bullet->Update(); //bullet�� ���µ� �۵���Ű�� �����ϱ�...

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
