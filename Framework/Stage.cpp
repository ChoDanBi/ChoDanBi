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
	ObjectList = ObjectManager::GetInstance()->GetObjectList();
}

void Stage::Update()
{
	m_pPlayer->Update();

	for (map<string, list<Object*>>::iterator iter = ObjectList->begin();
		iter != ObjectList->end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end();)
		{
			int Result = (*iter2)->Update();

			if (Result == 1)
				iter2 = iter->second.erase(iter2);
			else
				++iter2;
		}
	}

	if (GetAsyncKeyState(VK_RETURN))
	{
		for (int i = 0; i < 1; ++i)
		{
			ObjectManager::GetInstance()->AddObject(
				ObjectFactory<Enemy>::CreateObject());
		}
	}
}

void Stage::Render()
{
	m_pPlayer->Render();

	for (map<string, list<Object*>>::iterator iter = ObjectList->begin();
		iter != ObjectList->end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			(*iter2)->Render();
		}
	}
}

void Stage::Release()
{
	/*
	::Safe_Delete(m_pPlayer);

	for (map<string, list<Object*>>::iterator iter = ObjectList->begin();
		iter != ObjectList->end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			::Safe_Delete((*iter2));
		}
		iter->second.clear();
	}
	ObjectList->clear();
	*/
}
