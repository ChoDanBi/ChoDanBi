#pragma once
#include "Object.h"

class Bridge;
class Enemy : public Object
{
public:
	//ULONGLONG Time;
	//vector<Object*>* EBulletList;
	Bridge* BridgeObject;

public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Enemy(*this); }

	
public:
	void SetBridge(Bridge* _pBridge) { BridgeObject = _pBridge; }
	/*
	template <typename T>
	Object* CreateBullet();
*/
public:
	Enemy();
	Enemy(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~Enemy();
};


