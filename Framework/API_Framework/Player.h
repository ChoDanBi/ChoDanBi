#pragma once
#include "Object.h"

class Player : public Object
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
	
	virtual Object* Clone()override { return new Player(*this); }
public:
	Player();
	Player(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~Player();
};

