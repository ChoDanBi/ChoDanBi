#include "Stage.h"

#include "SceneManager.h"
#include "ObjectManager.h"
#include "CollisionManager.h"

#include "Player.h"
#include "Enemy.h"
#include "BaseEnemy.h"

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
	m_pPlayer->SetPosition(200.0f, WindowsHeight / 2);

	// ** ������Ʈ �Ŵ������� �Ѿ� ����Ʈ�� �޾ƿ�. (�����ͷ�...)
	BulletList = ObjectManager::GetInstance()->GetBulletList();

	// ** ������Ʈ �Ŵ������� ���� ����Ʈ�� �޾ƿ�. (�����ͷ�...)
	EnemyList = ObjectManager::GetInstance()->GetEnemyList();

	EBulletList = ObjectManager::GetInstance()->GetEnemyBullet();
	
	State_Back = new Stage_Back;
	State_Back->Initialize();
	((Stage_Back*)State_Back)->SetStageState(2);
	
	Vector3 Center = Vector3(WindowsWidth / 2.0f, WindowsHeight / 2.0f);
	
	for (int y = 0; y < 4; ++y)
	{
		EnemyList->push_back(CreateBullet<BaseEnemy>(Vector3(1000, 100 + y * 150)));
		
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


//�÷��̾� źȯ�� �� �浹
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

	//�� źȯ�� �÷��̾� �浹
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
	

	if (PlayerHitPoint <= 0) SceneManager::GetInstance()->SetScene(SCENEID::SELECTSTAGE);
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
	//������Ʈ���� �� ������� �ٽ� ���������� ������ ���� ����� + ������ �ִ°�
	//������ ���־� �ϴµ�...
	/*
	for (vector<Object*>::iterator iter = EBulletList->begin();
		iter != EBulletList->end(); ++iter)
		iter = EBulletList->erase(iter);

	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); ++iter)
		iter = BulletList->erase(iter);

	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end(); ++iter)
		iter = EnemyList->erase(iter);
		*/
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