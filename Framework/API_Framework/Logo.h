#pragma once
#include "Scene.h"

class Logo : public Scene
{
private:
	//Object* StageBack;
	map<string, Bitmap*> ImageList;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Logo();
	virtual ~Logo();
};