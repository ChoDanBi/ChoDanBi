#pragma once
#include "Scene.h"

class Object;
class Menu : public Scene
{
private:
	Object* StageBack;
	Transform Buttom1;
//	Transform Buttom2;
//	Transform Buttom3;
	map<string, Bitmap*> ImageList;

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Menu();
	virtual ~Menu();
};