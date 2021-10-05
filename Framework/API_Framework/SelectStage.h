#pragma once
#include "Scene.h"

class Object;
class SelectStage: public Scene
{
private:
	int click;
	Transform BackButtom;

	Object* s_SelectButton;
	Object* StageBack;

	map<string, Bitmap*> ImageList;

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

public:
	SelectStage();
	virtual ~SelectStage();

};

