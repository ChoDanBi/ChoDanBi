#pragma once
#include "Scene.h"
//�̰� �긴���� �³�? ��� ������ ������ ��^^


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

