#pragma once
#include "Object.h"

class HammerEffect : public Object
{
private:
	int Frame;

	ULONGLONG Time;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new HammerEffect(*this); }
public:
	HammerEffect();
	HammerEffect(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~HammerEffect();
};

