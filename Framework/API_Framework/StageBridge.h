#pragma once
#include "Bridge.h"

class StageBridge:public Bridge
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

