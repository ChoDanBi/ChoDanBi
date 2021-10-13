#pragma once
#include "Object.h"

class Effect:public Object
{
private:
	int Frame;
	ULONGLONG Time;

public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Effect(*this); }

public:
	Effect();
	Effect(const Transform& _rTransInfo) : Object(_rTransInfo) {}
	virtual ~Effect();


};

