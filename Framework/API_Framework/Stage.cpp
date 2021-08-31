#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectFactory.h"


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

	EnableList = ObjectManager::GetInstance()->GetEnableList();
	DisableList = ObjectManager::GetInstance()->GetDisableList();

	SetTime = rand() % 5000 + 3000;
	Time = GetTickCount64();
}

void Stage::Update()
{
	m_pPlayer->Update();

	for (list<Object*>::iterator iter = EnableList->begin();
		iter != EnableList->end(); )
	{
		int Result = (*iter)->Update();

		if (Result == 1)
			iter = EnableList->erase(iter);
		else
			++iter;
	}

	if (Time + SetTime < GetTickCount64())
	{
		for (int i = 0; i < 6; ++i)
		{
			Vector3 vPos = Vector3(WindowsWidth - 100, i * 110 + 60);
			ObjectManager::GetInstance()->FindObject("Enemy", vPos);
		}

		SetTime = rand() % 5000 + 3000;
		Time = GetTickCount64();
	}
}

void Stage::Render(HDC _hdc)
{
	m_pPlayer->Render(_hdc);

	for (list<Object*>::iterator iter = EnableList->begin();
		iter != EnableList->end(); ++iter)
	{
		(*iter)->Render(_hdc);
	}
}

void Stage::Release()
{

}
