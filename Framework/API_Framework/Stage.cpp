#include "Stage.h"

#include "SceneManager.h"
#include "ObjectManager.h"
#include "CollisionManager.h"

#include "Player.h"
#include "Enemy.h"
#include "BaseEnemy.h"
#include "StageButton.h"

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
	SelectButton = ObjectManager::GetInstance()->GetButton();

	m_pPlayer = ObjectManager::GetInstance()->GetPlayer();

	PlayerHitPoint = m_pPlayer->GetHitPoint();

	m_pPlayer->SetPosition(200.0f, WindowsHeight / 2);

	// ** 오브젝트 매니저에서 총알 리스트를 받아옴. (포인터로...)
	BulletList = ObjectManager::GetInstance()->GetBulletList();

	// ** 오브젝트 매니저에서 몬스터 리스트를 받아옴. (포인터로...)
	EnemyList = ObjectManager::GetInstance()->GetEnemyList();

	EBulletList = ObjectManager::GetInstance()->GetEnemyBullet();
	
	State_Back = new Stage_Back;
	State_Back->Initialize();
	((Stage_Back*)State_Back)->SetStageState(2);
	
	Vector3 Center = Vector3(WindowsWidth / 2.0f, WindowsHeight / 2.0f);
	
	PlayTime = GetTickCount64();
	Timer = GetTickCount64();

	for (int y = 0; y < 3; ++y)
	{
	//	EnemyList->push_back(CreateBullet<BaseEnemy>(Vector3(1000, 100 + y * 150)));
		EnemyList->push_back(CreateBullet<BaseEnemy>(Vector3(1400, rand() % 200 + 150 + y * 150)));
		
	}
	/*
	for (int y = 0; y < 4; ++y)
	{
		Object* pObj = new Enemy;
		pObj->Initialize();

		pObj->SetPosition(1000, 100 + y * 150);

		EnemyList->push_back(pObj);
	}
*/

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
//=
if (PlayTime + 280000 > GetTickCount64())
{
	if (Timer + rand() % 1000 + 2000 < GetTickCount64())
	{
		Timer = GetTickCount64();
		EnemyList->push_back(CreateBullet<BaseEnemy>(Vector3(1400, rand() % 580 + 50)));
	}
}

//==
//플레이어는 적탄환과 적에게 맞으면 hp감소
//플레이어는 맞았을 시 3초 무적
//플레이어 탄환은 적을 없앰

{
	//플레이어 탄환과 적 충돌
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
				(*iter2)->CrashHitPoint((*iter)->GetDamage());
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

	//적 탄환과 플레이어 충돌
	for (vector<Object*>::iterator iter = EBulletList->begin();
		iter != EBulletList->end(); ++iter)
	{
		if (CollisionManager::RectCollision(m_pPlayer->GetCollider(), (*iter)->GetCollider()))
		{
			iter = EBulletList->erase(iter);
			PlayerHitPoint--;
			break;
		}
	}
}
	//==


if (PlayTime + 1000 <= GetTickCount64())
{
		SceneManager::GetInstance()->SetScene(SCENEID::SELECTSTAGE);
		((StageButton*)SelectButton)->StageClear(0);
}

	//if (EnemyList->empty())
	if (PlayerHitPoint <= 0)
		SceneManager::GetInstance()->SetScene(SCENEID::SELECTSTAGE);
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

	PlayerHitPoint = ((Player*)m_pPlayer)->GetHitPoint();
}

/*
for (int y = 0; y < 4; ++y)
	{
		EnemyList->push_back(CreateBullet<BaseEnemy>(Vector3(1000, 100 + y * 150)));

	}
* 
static Object* CreateObject(Vector3 _vPos, Bridge* pBridge)
	{
		Object* pObj = new T;

		pObj->Initialize();
		pObj->SetPosition(_vPos);

		pBridge->SetObject(pObj);
		pBridge->Initialize();

		((T*)pObj)->SetBridge(pBridge);

		return pObj;
	}
	*/

template<typename T>
Object* Stage::CreateBullet(Vector3 _Pos)
{
	Bridge* eBridge = new T;

	Object* eEnemy = ObjectFactory<Enemy>::CreateObject(_Pos, eBridge);

	return eEnemy;
}