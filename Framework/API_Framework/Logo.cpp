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
	ObjectManager::GetInstance()->Initialize();

	ObjectManager::GetInstance()->SetPlayer(
		ObjectFactory<Player>::CreateObject() );

	ImageList["Buffer"] = (new Bitmap)->LoadBmp(L"../Resource/Buffer.bmp");

	ImageList["Char"] = (new Bitmap)->LoadBmp(L"../Resource/Char.bmp");			//94.0f,92.0f
	ImageList["Enemy_1"] = (new Bitmap)->LoadBmp(L"../Resource/Enemy_1.bmp");	//164.0f,153.0f


	//1280,720 + 30
	ImageList["Stay"] = (new Bitmap)->LoadBmp(L"../Resource/BackGround_Stay2.bmp");
	ImageList["Stage1"] = (new Bitmap)->LoadBmp(L"../Resource/BackGround_Stage1.bmp");
	ImageList["Stage2"] = (new Bitmap)->LoadBmp(L"../Resource/BackGround_Stage2.bmp");
	ImageList["Stage3"] = (new Bitmap)->LoadBmp(L"../Resource/BackGround_Stage3.bmp");
	ImageList["Stage4"] = (new Bitmap)->LoadBmp(L"../Resource/BackGround_Stage4.bmp");

	ImageList["Select"] = (new Bitmap)->LoadBmp(L"../Resource/SelectStage.bmp");


	Object::SetImageList(ImageList);
}

void Logo::Update()
{
	if (GetAsyncKeyState('A'))
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
}

void Logo::Render(HDC _hdc)
{
    
}

void Logo::Release()
{

}
