#include "Stage4.h"

#include "SceneManager.h"
#include "ObjectManager.h"
#include "CollisionManager.h"
#include "ObjectFactory.h"

#include "Player.h"
#include "Enemy.h"
#include "BossEnemy.h"

#include "StageButton.h"
#include "Stage_Back.h"
#include "StageResult.h"


Stage4::Stage4()
{

}

Stage4::~Stage4()
{
	Release();
}

void Stage4::Initialize()
{
	m_pPlayer = ObjectManager::GetInstance()->GetPlayer();
	m_pPlayer->SetPosition(200.0f, WindowsHeight / 2);


	SelectButton = ObjectManager::GetInstance()->GetButton();
	BulletList = ObjectManager::GetInstance()->GetBulletList();
	EnemyList = ObjectManager::GetInstance()->GetEnemyList();
	EBulletList = ObjectManager::GetInstance()->GetEnemyBullet();


	EnemyList->push_back(CreateEnemy<BossEnemy>(Vector3(1000, WindowsHeight/2)));

	PlayTime = GetTickCount64();
	Timer = GetTickCount64();
	Active = true;

	State_Back = new Stage_Back;
	State_Back->Initialize();
	((Stage_Back*)State_Back)->SetStageState(5);

	Result = new StageResult;
	Result->Initialize();
	((StageResult*)Result)->SetStageNumber(4);

	ImageList = Object::GetImageList();
}

void Stage4::Update()
{
	if (Active)
	{
		m_pPlayer->Update();

		for (vector<Object*>::iterator Pb_iter = BulletList->begin();
			Pb_iter != BulletList->end(); Pb_iter++)
		{
			int iResult = (*Pb_iter)->Update();
			if (iResult == 1)
				Pb_iter = BulletList->erase(Pb_iter);
		}

		for (vector<Object*>::iterator iter = EBulletList->begin();
			iter != EBulletList->end(); ++iter)
		{
			(*iter)->Update();
			if (CollisionManager::RectCollision(m_pPlayer->GetCollider(), (*iter)->GetCollider()))
			{
				iter = EBulletList->erase(iter);
				m_pPlayer->CrashHitPoint(1);
				break;
			}
		}

		for (vector<Object*>::iterator E_iter = EnemyList->begin();
			E_iter != EnemyList->end(); )
		{
			int iResult = (*E_iter)->Update();

			for (vector<Object*>::iterator Pb_iter = BulletList->begin();
				Pb_iter != BulletList->end(); )
			{
				if ((*E_iter)->GetHitPoint() <= 0)
				{
					iResult = 1;
					break;
				}
				if (CollisionManager::RectCollision((*E_iter)->GetCollider(), (*Pb_iter)->GetCollider()))
				{
					(*E_iter)->CrashHitPoint((*Pb_iter)->GetDamage());
					Pb_iter = BulletList->erase(Pb_iter);
					break;
				}
				else Pb_iter++;
			}

			if (iResult == 1)
				E_iter = EnemyList->erase(E_iter);
			else
				++E_iter;
		}

		if (PlayTime + 100000 <= GetTickCount64())
		{
			((StageButton*)SelectButton)->StageClear(4);
			Active = false;
			((StageResult*)Result)->SetClear(true);
		}
		if (m_pPlayer->GetHitPoint() <= 0)
		{
			Active = false;
			((StageResult*)Result)->SetClear(false);
		}
	}
	if (!Active)
	{
		Result->Update();
	}
}

void Stage4::Render(HDC _hdc)
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

	if (!Active)
	{
		Result->Render(ImageList["Buffer"]->GetMemDC());
	}

	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Stage4::Release()
{
	if (!EnemyList->empty())
	{
		EnemyList->clear();
		EnemyList = nullptr;
	}

	if (!EBulletList->empty())
	{
		EBulletList->clear();
		EBulletList = nullptr;
	}

	if (!BulletList->empty())
	{
		BulletList->clear();
		BulletList = nullptr;
	}

	m_pPlayer->SetHitPoint(3);
}

template<typename T>
Object* Stage4::CreateEnemy(Vector3 _Pos)
{
	Bridge* eBridge = new T;

	Object* eEnemy = ObjectFactory<Enemy>::CreateObject(_Pos, eBridge);

	return eEnemy;
}