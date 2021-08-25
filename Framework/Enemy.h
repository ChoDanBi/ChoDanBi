#pragma once
#include "Object.h"

class Enemy : public Object
{
private:
	int Count;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Enemy();
	virtual ~Enemy();
};
