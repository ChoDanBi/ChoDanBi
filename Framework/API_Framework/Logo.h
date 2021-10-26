#pragma once
#include "Scene.h"

class Logo : public Scene
{
private:
	map<string, Bitmap*> ImageList;
	Bitmap* Image;
	Transform TransInfo;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Logo();
	virtual ~Logo();
};