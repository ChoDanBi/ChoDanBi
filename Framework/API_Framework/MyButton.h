#pragma once
#include "Object.h"

class MyButton : public Object
{
private:
	int Horizontal;
	bool MOVE;
	int ButtonOffSet[2];
	ULONGLONG Time;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new MyButton(*this); }
public:
	void Check();
public:
	MyButton();
	MyButton(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~MyButton();
};