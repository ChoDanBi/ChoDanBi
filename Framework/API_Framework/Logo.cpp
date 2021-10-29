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

	Inventory.insert(make_pair(INVENTORY::GOLD, 100));
	Inventory.insert(make_pair(INVENTORY::DAMAGE, 1));
	Inventory.insert(make_pair(INVENTORY::SPEED, 2));
	Inventory.insert(make_pair(INVENTORY::BOMB, 4));
	Inventory.insert(make_pair(INVENTORY::SHIELD, 2));

	InventoryManager::GetInstance()->SetInventory(Inventory);

	ObjectManager::GetInstance()->SetPlayer(
		ObjectFactory<Player>::CreateObject() );

	ObjectManager::GetInstance()->SetButton(
		ObjectFactory<StageButton>::CreateObject());

	ImageList["Buffer"] = (new Bitmap)->LoadBmp(L"../Resource/Buffer.bmp");

	ImageList["Char"] = (new Bitmap)->LoadBmp(L"../Resource/Char_.bmp");			//94.0f,92.0f
	ImageList["BaseEnemy"] = (new Bitmap)->LoadBmp(L"../Resource/BaseEnemy_.bmp");	//120.0f,111.0f
	ImageList["NormalEnemy"] = (new Bitmap)->LoadBmp(L"../Resource/NormalEnemy_.bmp");	//166.0f,212.0f
	ImageList["EliteEnemy"] = (new Bitmap)->LoadBmp(L"../Resource/EliteEnemy_.bmp");	//212.0f,162.0f
	ImageList["BossEnemy"] = (new Bitmap)->LoadBmp(L"../Resource/BossEnemy_.bmp");	//443.0f,434.0f


	//1280,720 + 30
	ImageList["Stay"] = (new Bitmap)->LoadBmp(L"../Resource/BackGround_Stay2.bmp");
	ImageList["Stage1"] = (new Bitmap)->LoadBmp(L"../Resource/BackGround_Stage1_1.bmp");
	ImageList["Stage2"] = (new Bitmap)->LoadBmp(L"../Resource/BackGround_Stage2_1.bmp");
	ImageList["Stage3"] = (new Bitmap)->LoadBmp(L"../Resource/BackGround_Stage3_1.bmp");
	ImageList["Stage4"] = (new Bitmap)->LoadBmp(L"../Resource/BackGround_Stage4.bmp");

	ImageList["Select"] = (new Bitmap)->LoadBmp(L"../Resource/SelectStage.bmp");
	ImageList["Star"] = (new Bitmap)->LoadBmp(L"../Resource/Star.bmp"); //128.0f,64.0f

	ImageList["PBullet"] = (new Bitmap)->LoadBmp(L"../Resource/PlayerBullet_.bmp"); //128.0f,64.0f
	ImageList["EBullet"] = (new Bitmap)->LoadBmp(L"../Resource/EnemyBullet.bmp"); //128.0f,64.0f

	ImageList["Heart"] = (new Bitmap)->LoadBmp(L"../Resource/Heart.bmp"); //384.0f,128.0f
	ImageList["Clear"] = (new Bitmap)->LoadBmp(L"../Resource/StageClear.bmp"); //759.0f,587.0f
	ImageList["Over"] = (new Bitmap)->LoadBmp(L"../Resource/GameOver.bmp"); //759.0f,587.0f

	ImageList["Bar"] = (new Bitmap)->LoadBmp(L"../Resource/StateBar.bmp"); //759.0f,587.0f
	ImageList["Shop"] = (new Bitmap)->LoadBmp(L"../Resource/Store.bmp"); //759.0f,587.0f

	ImageList["Shild"] = (new Bitmap)->LoadBmp(L"../Resource/Shild.bmp");
	ImageList["Bomb"] = (new Bitmap)->LoadBmp(L"../Resource/Boom.bmp");
	ImageList["TBomb"] = (new Bitmap)->LoadBmp(L"../Resource/BoomThrow.bmp");
	ImageList["Effect"] = (new Bitmap)->LoadBmp(L"../Resource/Effect.bmp");

	ImageList["HitPoint1"] = (new Bitmap)->LoadBmp(L"../Resource/HitPointBar1.bmp");
	ImageList["HitPoint2"] = (new Bitmap)->LoadBmp(L"../Resource/HitPointBar2.bmp");

	ImageList["BossHitPoint1"] = (new Bitmap)->LoadBmp(L"../Resource/BossHitPointBar1.bmp");
	ImageList["BossHitPoint2"] = (new Bitmap)->LoadBmp(L"../Resource/BossHitPointBar2.bmp");
	
	Object::SetImageList(ImageList);
	Bridge::SetImageList(ImageList);	//이거 없으면 브릿지 이미지 안됨

	Image[0] = (new Bitmap)->LoadBmp(L"../Resource/Logo.bmp");
	Image[1] = (new Bitmap)->LoadBmp(L"../Resource/Touch.bmp");
	
	Time = GetTickCount64();
	Frame = 0;

	TransInfo.Position = Vector3(1280.0f, 720.0f);
	TransInfo.Scale = Vector3(1280.0f , 720.0f);

	SoundManager::GetInstance()->OnPlaySound("Wait");
}

void Logo::Update()
{
	if (GetAsyncKeyState(' ') & 0x0001)
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);

	if (Time + 1000 < GetTickCount64())
	{
		Time = GetTickCount64();
		Frame = !Frame;
	}
}

void Logo::Render(HDC _hdc)
{
	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		Image[0]->GetMemDC(),
		0, 0,
		SRCCOPY);

	TransparentBlt(_hdc,
		WindowsWidth / 2 - 231 / 2, 600,
		231, 40,
		Image[1]->GetMemDC(),
		Frame * 231, 0,
		231, 40,
		RGB(255, 0, 255));
	
}

void Logo::Release()
{

}
