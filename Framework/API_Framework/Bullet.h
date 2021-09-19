#pragma once
#include "Object.h"


class Bridge;
class Bullet : public Object
{
private:
	Bridge* BridgeObject;

public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Bullet(*this); }
public:
	void SetBridge(Bridge* _pBridge) { BridgeObject = _pBridge; }
public:
	Bullet();
	Bullet(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~Bullet();
};


/*
class A
{
public:
	virtual void Output() = 0;
};

class D;
class E;
class B : public A
{
private:
	C* ddd = new D;
	C* eee = new E;
public:
	virtual void Output()override
	{
		ddd->Output();
		eee->Output();
	}
};

class C
{
public:
	virtual void Output() = 0;
};

class D : public C
{
public:
	virtual void Output()override
	{
		cout << "DDD" << endl;
	}
};

class E : public C
{
public:
	virtual void Output()override
	{
		cout << "EEE" << endl;
	}
};
*/