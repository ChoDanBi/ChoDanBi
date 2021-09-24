#include "Stage.h"

#include "SceneManager.h"
#include "ObjectManager.h"
#include "CollisionManager.h"

#include "Player.h"
#include "Enemy.h"
#include "ObjectFactory.h"
#include "Stage_Back.h"


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

	PlayerHitPoint = m_pPlayer->GetHitPoint();

	// ** 오브젝트 매니저에서 총알 리스트를 받아옴. (포인터로...)
	BulletList = ObjectManager::GetInstance()->GetBulletList();

	// ** 오브젝트 매니저에서 몬스터 리스트를 받아옴. (포인터로...)
	EnemyList = ObjectManager::GetInstance()->GetEnemyList();

	EBulletList = ObjectManager::GetInstance()->GetEnemyBullet();
	
	State_Back = new Stage_Back;
	State_Back->Initialize();
	((Stage_Back*)State_Back)->SetStageState(2);
	
	Vector3 Center = Vector3(WindowsWidth / 2.0f, WindowsHeight / 2.0f);

	for (int y = 0; y < 4; ++y)
	{
		Object* pObj = new Enemy;
		pObj->Initialize();

		pObj->SetPosition(1000, 100 + y * 150);

		EnemyList->push_back(pObj);
	}


	ImageList = Object::GetImageList();
}

void Stage::Update()
{
	m_pPlayer->Update();

	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end(); ++iter)
		(*iter)->Update();

for (vector<Object*>::iterator iter = EBulletList->begin();
		iter != EBulletList->end(); ++iter)
		(*iter)->Update();

//==============================

	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); )
	{
		int iResult = (*iter)->Update();

		for (vector<Object*>::iterator iter2 = EnemyList->begin();
			iter2 != EnemyList->end(); )
		{
			if ((*iter2)->GetHitPoint() <= 0)
			{
				iter2 = EnemyList->erase(iter2);
				break;
			}
			if (CollisionManager::RectCollision((*iter)->GetCollider(), (*iter2)->GetCollider()))
			{
				(*iter2)->CrashHitPoint(1);
				iResult = 1;
				break;
			}
			else
				++iter2;
		}
		if (iResult == 1)
			iter = BulletList->erase(iter);
		else
			++iter;
	}


	for (vector<Object*>::iterator iter = EBulletList->begin();
		iter != EBulletList->end();++iter)
	{
		if (CollisionManager::RectCollision(m_pPlayer->GetCollider(), (*iter)->GetCollider()))
		{
			iter = EBulletList->erase(iter);
			PlayerHitPoint--;
			break;
		}
	}
	

	if (PlayerHitPoint <= 0) SceneManager::GetInstance()->SetScene(SCENEID::MENU);
}

void Stage::Render(HDC _hdc)
{
	State_Back->Render(ImageList["Buffer"]->GetMemDC());

	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());

	for (vector<Object*>::iterator iter = EBulletList->begin();
		iter != EBulletList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());

	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());

	m_pPlayer->Render(ImageList["Buffer"]->GetMemDC());


	
	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0, 
		SRCCOPY);
}

void Stage::Release()
{

}
