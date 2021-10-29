#include "Stage.h"

#include "SceneManager.h"
#include "ObjectManager.h"
#include "CollisionManager.h"
#include "ObjectFactory.h"
#include "InventoryManager.h"
#include "SoundManager.h"

#include "Player.h"
#include "Enemy.h"
#include "BaseEnemy.h"

#include "StageButton.h"
#include "Stage_Back.h"
#include "StageResult.h"
#include "Effect.h"


Stage::Stage() 
{

}

Stage::~Stage()
{
	Release();
}

void Stage::Initialize()
{

	m_pPlayer = ObjectManager::GetInstance()->GetPlayer();
	m_pPlayer->SetPosition(200.0f, WindowsHeight / 2);	

	SoundManager::GetInstance()->OnPlaySound("Stage");

	EffectList.clear();

	SelectButton = ObjectManager::GetInstance()->GetButton();
	BulletList = ObjectManager::GetInstance()->GetBulletList();
	EnemyList = ObjectManager::GetInstance()->GetEnemyList();
	EBulletList = ObjectManager::GetInstance()->GetEnemyBullet();

	PlayTime = GetTickCount64();

	Timer = GetTickCount64();
	Active = true;

	State_Back = new Stage_Back;
	State_Back->Initialize();
	((Stage_Back*)State_Back)->SetStageState(2);

	Result = new StageResult;
	Result->Initialize();
	((StageResult*)Result)->SetStageNumber(1);
	((StageResult*)Result)->SetClick(0);

	ImageList = Object::GetImageList();
}

void Stage::Update()
{
	if (Active)
	{
		State_Back->Update();

		//�÷��̾� ����
		m_pPlayer->Update();



		//�÷��̾� źȯ ����
		for (vector<Object*>::iterator Pb_iter = BulletList->begin();
			Pb_iter != BulletList->end();)
		{
			int iResult = (*Pb_iter)->Update();
			if (iResult == 1)
				Pb_iter = BulletList->erase(Pb_iter);
			else
				Pb_iter++;
		}

		//�� źȯ�� �÷��̾� ��ȣ�ۿ�
		for (vector<Object*>::iterator iter = EBulletList->begin();
			iter != EBulletList->end(); ++iter)
		{
			(*iter)->Update();

			if (m_pPlayer->GetActive() && CollisionManager::RectCollision(m_pPlayer->GetCollider(), (*iter)->GetCollider()))
			{
				SoundManager::GetInstance()->OnPlaySoundDot("Crash");
				m_pPlayer->SetActive(false);
				iter = EBulletList->erase(iter);
				m_pPlayer->CrashHitPoint(1);
				break;
			}
			if ((*iter)->GetPosition().x <= -10)
			{
				iter = EBulletList->erase(iter);
				break;
			}
		}

		//���� �÷��̾� źȯ ��ȣ�ۿ�
		for (vector<Object*>::iterator E_iter = EnemyList->begin();
			E_iter != EnemyList->end(); )
		{
			int iResult = (*E_iter)->Update();

			//�÷��̾� HP����
			if (m_pPlayer->GetActive() && CollisionManager::RectCollision(m_pPlayer->GetCollider(), (*E_iter)->GetCollider()))
			{
				m_pPlayer->SetActive(false);
				m_pPlayer->CrashHitPoint(1);
				SoundManager::GetInstance()->OnPlaySoundDot("Crash");
				break;
			}

			
			for (vector<Object*>::iterator Pb_iter = BulletList->begin();
				Pb_iter != BulletList->end(); )
			{
				if ((*E_iter)->GetHitPoint() <= 0)
				{
					InventoryManager::GetInstance()->AddItem(INVENTORY::GOLD, 20);
					iResult = 1;
					break;
				}

				//�� �κп��� �� ������

				if (CollisionManager::RectCollision((*E_iter)->GetCollider(), (*Pb_iter)->GetCollider()))
				{

					(*E_iter)->CrashHitPoint((*Pb_iter)->GetDamage());

					if ((*Pb_iter)->Update() == 2)
						(*Pb_iter)->SetActive(false);
					SoundManager::GetInstance()->OnPlaySoundDot("Hit");

					EffectList.push_back(ObjectFactory<Effect>::CreateObject(
						(*Pb_iter)->GetPosition().x + rand() % 30 + 20,
						(*Pb_iter)->GetPosition().y + rand() % 20 + 10));
					if ((*Pb_iter)->Update() == 0)
						Pb_iter = BulletList->erase(Pb_iter);
					break;
				}
				else
					Pb_iter++;
			}

			if (iResult == 1)
				E_iter = EnemyList->erase(E_iter);
			else
				++E_iter;
		}
		
		if (!EffectList.empty())
		{
			for (vector<Object*>::iterator iter = EffectList.begin();
				iter != EffectList.end(); )
			{
				(*iter)->Update();

				if (!(*iter)->GetActive())
					iter = EffectList.erase(iter);
				else
					iter++;
			}
		}

		if (Timer + rand() % 1000 + 2000 < GetTickCount64())
		{
			Timer = GetTickCount64();
			EnemyList->push_back(CreateEnemy<BaseEnemy>(Vector3(1300.0f , float(rand() % 580 + 50))));
		}

		if (PlayTime + 45000 <= GetTickCount64())
		{
			((StageButton*)SelectButton)->StageClear(1);
			Active = false;
			((StageResult*)Result)->SetClear(true);
		}
		if (m_pPlayer->GetHitPoint() <= 0)
		{
			Active = false;
			((StageResult*)Result)->SetClear(false);
		}
	}
	else
	{
		Result->Update();
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

	
	if (!EffectList.empty())
	{
		for (vector<Object*>::iterator iter = EffectList.begin();
			iter != EffectList.end(); iter++)
			(*iter)->Render(ImageList["Buffer"]->GetMemDC());
	}
	
	

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

void Stage::Release()
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

	((Stage_Back*)State_Back)->SetFrame(0);
	((Player*)m_pPlayer)->Setter();
	m_pPlayer->SetHitPoint(3);
	m_pPlayer->SetActive(true);

	((StageResult*)Result)->SetClear(false);
}

template<typename T>
Object* Stage::CreateEnemy(Vector3 _Pos)
{
	Bridge* eBridge = new T;

	Object* eEnemy = ObjectFactory<Enemy>::CreateObject(_Pos, eBridge);

	return eEnemy;
}