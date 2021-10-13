#pragma once
#include "Scene.h"

class Object;
class Shop :public Scene
{
 private:
	int click;
	Object* StageBack;
	Object* State;
	Transform Buttom[5];
	map<string, Bitmap*> ImageList;

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

public:
	Shop();
	virtual ~Shop();

};