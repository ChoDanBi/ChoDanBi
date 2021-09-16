#pragma once
#include "Object.h"

class MyButton : public Object
{
private:
	int Horizontal;
	bool Move;

	int ButtonOffset[2];
	ULONGLONG Time;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new MyButton(*this); }

public:
	MyButton();
	virtual ~MyButton();
};