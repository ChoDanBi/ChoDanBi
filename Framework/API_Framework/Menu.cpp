#include "Menu.h"
#include "SceneManager.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::Initialize()
{

}

void Menu::Update()
{
	//cout << "Menu::Update" << endl;

	if (GetAsyncKeyState('S'))
		SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
}

void Menu::Render(HDC _hdc)
{
	//cout << "Menu::Render" << endl;
}

void Menu::Release()
{

}
