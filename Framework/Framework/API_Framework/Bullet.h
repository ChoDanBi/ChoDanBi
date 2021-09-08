#pragma once
#include "Object.h"

class Bullet : public Object
{
private:
	Object* Target;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Bullet(*this); }
public:
	void SetTarget(Object* _Target) { Target = _Target; }



public:
	Bullet();
	Bullet(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~Bullet();
};

