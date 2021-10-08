#pragma once
#include "PatternBridge.h"

class NormalPattern: public PatternBridge
{
public:
	virtual void Initialize();
	virtual int Update(Transform& _rTransInfo);
	virtual void Render(HDC _hdc);
	virtual void Release();

public:
	NormalPattern();
	virtual ~NormalPattern();
};

