#pragma once
#include "PatternBridge.h"

class PatternDash: public PatternBridge
{
public:

public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

public:
	
public:
	PatternDash();
	virtual ~PatternDash();
};

