#include "SelectStage.h"
#include "Stage_Back.h"
#include "SceneManager.h"

SelectStage::SelectStage()
{
}

SelectStage::~SelectStage()
{
}

void SelectStage::Initialize()
{
	StageBack = new Stage_Back;
	StageBack->Initialize();
	((Stage_Back*)StageBack)->SetStageState(1);

	ImageList = Object::GetImageList();
}

void SelectStage::Update()
{
}

void SelectStage::Render(HDC _hdc)
{
	StageBack->Render(ImageList["Buffer"]->GetMemDC());

	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void SelectStage::Release()
{
}


