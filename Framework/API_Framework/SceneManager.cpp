#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Shop.h"
#include "SelectStage.h"
#include "Stage.h"
#include "Stage2.h"
#include "Stage3.h"
#include "Stage4.h"
#include "Ending.h"

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

	case SCENEID::SHOP:
		pSceneState = new Shop;
		break;

	case SCENEID::SELECTSTAGE:
		pSceneState = new SelectStage;
		break;

	case SCENEID::STAGE:
		pSceneState = new Stage;
		break;

	case SCENEID::STAGE2:
		pSceneState = new Stage2;
		break;

	case SCENEID::STAGE3:
		pSceneState = new Stage3;
		break;

	case SCENEID::STAGE4:
		pSceneState = new Stage4;
		break;

	case SCENEID::END:
		pSceneState = new Ending;
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