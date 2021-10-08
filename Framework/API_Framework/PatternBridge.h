#pragma once
#include "Bridge.h"

class PatternBridge :public Bridge
{
protected:
	float Speed;

public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& _rTransInfo)PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;

public:
	PatternBridge();
	virtual ~PatternBridge();
};

