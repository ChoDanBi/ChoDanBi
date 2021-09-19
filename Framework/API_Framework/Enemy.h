#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Enemy(*this); }
public:
	Enemy();
	Enemy(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~Enemy();
};
