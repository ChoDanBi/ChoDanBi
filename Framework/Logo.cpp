#include "Logo.h"
#include "Player.h"
#include "Enemy.h"

#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"


Logo::Logo()
{

}

Logo::~Logo()
{

}

void Logo::Initialize()
{
	ObjectManager::GetInstance()->SetPlayer(
		ObjectFactory<Player>::CreateObject());

	for (int i = 0; i < 5; ++i)
	{
		ObjectManager::GetInstance()->AddObject(
			ObjectFactory<Enemy>::CreateObject());
	}
}

void Logo::Update()
{
	cout << "Logo::Update" << endl;

	if (GetAsyncKeyState('A'))
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
}

void Logo::Render()
{
	cout << "Logo::Render" << endl;
}

void Logo::Release()
{

}
