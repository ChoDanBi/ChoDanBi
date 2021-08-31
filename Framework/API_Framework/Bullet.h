#pragma once
#include "Object.h"

class Bullet : public Object
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Bullet(*this); }
public:
	Bullet();
	Bullet(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~Bullet();
};

