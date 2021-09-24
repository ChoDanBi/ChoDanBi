#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "SelectStage.h"
#include "Stage.h"

SceneManager* SceneManager::Instance = nullptr;


void SceneManager::SetScene(SCENEID _SceneID)
{
	::Safe_Delete(pSceneState);
	
	switch (_SceneID)
	{
	case SCENEID::LOGO:
		pSceneState = new Logo;
		break;

	case SCENEID::MENU:
		pSceneState = new Menu;
		break;

	case SCENEID::SELECTSTAGE:
		pSceneState = new SelectStage;
		break;

	case SCENEID::STAGE:
		pSceneState = new Stage;
		break;

	case SCENEID::EXIT:
		exit(NULL);
		break;
	}

	pSceneState->Initialize();
}

void SceneManager::Update()
{
	pSceneState->Update();
}

void SceneManager::Render(HDC _hdc)
{
	pSceneState->Render(_hdc);
}

void SceneManager::Release()
{
	::Safe_Delete(pSceneState);
}