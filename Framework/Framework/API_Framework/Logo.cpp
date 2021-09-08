#include "Logo.h"
#include "Player.h"
#include "Enemy.h"

#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

//#include "Bitmap.h"

Logo::Logo()
{

}

Logo::~Logo()
{

}

void Logo::Initialize()
{
	//Bitmap* BitObject = new Bitmap;
	//BitObject->LoadBmp(L"asdasdasd");

	ImageList["test_02"] = (new Bitmap)->LoadBmp(L"../Resource/test_02.bmp");
	ImageList["test_01"] = (new Bitmap)->LoadBmp(L"../Resource/test_01.bmp");


	ObjectManager::GetInstance()->Initialize();

	ObjectManager::GetInstance()->SetPlayer(
		ObjectFactory<Player>::CreateObject());
}

void Logo::Update()
{
	if (GetAsyncKeyState('A'))
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
}

void Logo::Render(HDC _hdc)
{
	TransparentBlt(_hdc,/*최종 출력 위치*/
		(WindowsWidth / 2) - (300 / 2),
		(WindowsHeight / 2) - (300 / 2),
		300, 300,
		ImageList["test_02"]->GetMemDC(),
		0, 0,
		300, 300,
		RGB(255, 0, 255));
}

void Logo::Release()
{

}
