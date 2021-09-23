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

	// ** ������Ʈ �Ŵ������� �Ѿ� ����Ʈ�� �޾ƿ�. (�����ͷ�...)
	BulletList = ObjectManager::GetInstance()->GetBulletList();

	// ** ������Ʈ �Ŵ������� ���� ����Ʈ�� �޾ƿ�. (�����ͷ�...)
	EnemyList = ObjectManager::GetInstance()->GetEnemyList();

	EBulletList = ObjectManager::GetInstance()->GetEnemyBullet();
	
	State_Back = new Stage_Back;
	State_Back->Initialize();

	
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

	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); )
	{
		int iResult = (*iter)->Update();

		for (vector<Object*>::iterator iter2 = EnemyList->begin();
			iter2 != EnemyList->end(); )
		{
			if (CollisionManager::EllipseCollision((*iter), (*iter2)))
			{
				iter2 = EnemyList->erase(iter2);
				iResult = 1;
				break;
			}
			else
				++iter2;
		}

		// ** �Ѿ��� �����ϴ� ����.
		if (iResult == 1)
			iter = BulletList->erase(iter);
		else
			++iter;
	}
	
	
	//�ش� �κп��� ������ ����
	for (vector<Object*>::iterator iter = EBulletList->begin();
		iter != EBulletList->end(); )
	{
		(*iter)->Update();
	}

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
