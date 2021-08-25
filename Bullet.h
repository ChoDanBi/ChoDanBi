#pragma once
#include "Object.h"

class Bullet : public Object
{
private:
	int Count;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Bullet();
	virtual ~Bullet();
};

