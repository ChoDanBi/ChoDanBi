#include "MainUpdate.h"
#include "Player.h"
#include "Enemy.h"
#include "SceneManager.h"
#include "InputManager.h"


MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{
	Release();
}


void MainUpdate::Initialize()
{
	m_hdc = GetDC(g_hWnd);

	SceneManager::GetInstance()->SetScene(SCENEID::LOGO);
	//SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
}

void MainUpdate::Update()
{
	SceneManager::GetInstance()->Update();

	InputManager::GetInstance()->CheckKey();
}

void MainUpdate::Render()
{
	Rectangle(m_hdc, 0, 0, WindowsWidth, WindowsHeight);

	SceneManager::GetInstance()->Render(m_hdc);
}

void MainUpdate::Release()
{
	
}
