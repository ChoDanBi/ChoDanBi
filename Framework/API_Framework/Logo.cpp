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
	ImageList["BackGround"] = (new Bitmap)->LoadBmp(L"../Resource/BackGround.bmp");
	ImageList["Hammer"] = (new Bitmap)->LoadBmp(L"../Resource/Hammer.bmp");
	ImageList["Mole"] = (new Bitmap)->LoadBmp(L"../Resource/Mole.bmp");
	ImageList["Hole"] = (new Bitmap)->LoadBmp(L"../Resource/Hole.bmp");
	ImageList["Effect"] = (new Bitmap)->LoadBmp(L"../Resource/Effect.bmp");

	ImageList["on_off_Back"] = (new Bitmap)->LoadBmp(L"../Resource/on_off_Back.bmp");
	ImageList["on_off_Button"] = (new Bitmap)->LoadBmp(L"../Resource/on_off_Button.bmp");
	//=====================
	ImageList["Stay"] = (new Bitmap)->LoadBmp(L"../Resource/BackGround_Stay.bmp");
	ImageList["Char"] = (new Bitmap)->LoadBmp(L"../Resource/Char.bmp");


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
