#include "Logo.h"
#include "Player.h"
#include "Enemy.h"
#include "StageButton.h"

#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "InputManager.h"
#include "InventoryManager.h"

Logo::Logo()
{

}

Logo::~Logo()
{

}

void Logo::Initialize()
{
	ObjectManager::GetInstance()->Initialize();

	map<INVENTORY, int> Inventory;

	Inventory.insert(make_pair(INVENTORY::GOLD, 0));
	Inventory.insert(make_pair(INVENTORY::DAMAGE, 1));
	Inventory.insert(make_pair(INVENTORY::SPEED, 3));
	Inventory.insert(make_pair(INVENTORY::BOMB, 0));
	Inventory.insert(make_pair(INVENTORY::SHIELD, 0));

	InventoryManager::GetInstance()->SetInventory(Inventory);

	ObjectManager::GetInstance()->SetPlayer(
		ObjectFactory<Player>::CreateObject() );

	ObjectManager::GetInstance()->SetButton(
		ObjectFactory<StageButton>::CreateObject());

	ImageList["Buffer"] = (new Bitmap)->LoadBmp(L"../Resource/Buffer.bmp");

	ImageList["Char"] = (new Bitmap)->LoadBmp(L"../Resource/Char.bmp");			//94.0f,92.0f
	ImageList["BaseEnemy"] = (new Bitmap)->LoadBmp(L"../Resource/BaseEnemy.bmp");	//120.0f,111.0f
	ImageList["NormalEnemy"] = (new Bitmap)->LoadBmp(L"../Resource/NormalEnemy.bmp");	//166.0f,212.0f
	ImageList["EliteEnemy"] = (new Bitmap)->LoadBmp(L"../Resource/EliteEnemy.bmp");	//212.0f,162.0f
	ImageList["BossEnemy"] = (new Bitmap)->LoadBmp(L"../Resource/BossEnemy.bmp");	//443.0f,434.0f


	//1280,720 + 30
	ImageList["Stay"] = (new Bitmap)->LoadBmp(L"../Resource/BackGround_Stay2.bmp");
	ImageList["Stage1"] = (new Bitmap)->LoadBmp(L"../Resource/BackGround_Stage1.bmp");
	ImageList["Stage2"] = (new Bitmap)->LoadBmp(L"../Resource/BackGround_Stage2.bmp");
	ImageList["Stage3"] = (new Bitmap)->LoadBmp(L"../Resource/BackGround_Stage3.bmp");
	ImageList["Stage4"] = (new Bitmap)->LoadBmp(L"../Resource/BackGround_Stage4.bmp");

	ImageList["Select"] = (new Bitmap)->LoadBmp(L"../Resource/SelectStage.bmp");
	ImageList["Star"] = (new Bitmap)->LoadBmp(L"../Resource/Star.bmp"); //128.0f,64.0f

	ImageList["PBullet"] = (new Bitmap)->LoadBmp(L"../Resource/PlayerBullet.bmp"); //128.0f,64.0f
	ImageList["EBullet"] = (new Bitmap)->LoadBmp(L"../Resource/EnemyBullet.bmp"); //128.0f,64.0f

	ImageList["Heart"] = (new Bitmap)->LoadBmp(L"../Resource/Heart.bmp"); //384.0f,128.0f
	ImageList["Clear"] = (new Bitmap)->LoadBmp(L"../Resource/StageClear.bmp"); //759.0f,587.0f
	ImageList["Over"] = (new Bitmap)->LoadBmp(L"../Resource/GameOver.bmp"); //759.0f,587.0f

	ImageList["Bar"] = (new Bitmap)->LoadBmp(L"../Resource/StateBar.bmp"); //759.0f,587.0f
	ImageList["Shop"] = (new Bitmap)->LoadBmp(L"../Resource/Store.bmp"); //759.0f,587.0f

	ImageList["Bomb"] = (new Bitmap)->LoadBmp(L"../Resource/Boom.bmp");
	ImageList["Effect"] = (new Bitmap)->LoadBmp(L"../Resource/Effect.bmp");
	
	Object::SetImageList(ImageList);
	Bridge::SetImageList(ImageList);	//이거 없으면 브릿지 이미지 안됨

	
}

void Logo::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_LBUTTON)
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
}

void Logo::Render(HDC _hdc)
{
}

void Logo::Release()
{

}
