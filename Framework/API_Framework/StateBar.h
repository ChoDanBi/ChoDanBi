#pragma once
#include "Object.h"

class StateBar :public Object
{
private:
	Transform TransInfo;

public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new StateBar(*this); }

public:
	StateBar();
	StateBar(const Transform& _rTransInfo) : Object(_rTransInfo) {}
	virtual ~StateBar();
};

