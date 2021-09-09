#pragma once
#include "Object.h"

class Stage_Back : public Object
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()
	{
		return new Stage_Back(*this);
	};
public:
	Stage_Back();
	virtual ~Stage_Back();
};