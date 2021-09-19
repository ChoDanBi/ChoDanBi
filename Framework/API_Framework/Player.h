#pragma once
#include "Object.h"

class Player : public Object
{
private:
	int Frame;

	ULONGLONG Time;

	vector<Object*>* BulletList;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
	
	virtual Object* Clone()override { return new Player(*this); }
public:
	int GetSwing() { return Frame; }

	template <typename T>
	Object* CreateBullet();
public:
	Player();
	Player(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~Player();
};

