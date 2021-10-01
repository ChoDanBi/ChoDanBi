#pragma once
#include "Scene.h"
//이게 브릿지가 맞나? 라는 생각이 들지만 흠^^


class StageBridge:public Scene
{
public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;
public:
	StageBridge();
	virtual ~StageBridge();
};

class StageBridge
{
};

