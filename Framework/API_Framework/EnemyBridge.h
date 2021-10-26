#pragma once
#include "Bridge.h"

class EnemyBridge : public Bridge
{
protected:
	int HitPoint;
	float Speed;
	int Frame;

	ANIMATION Animation;

	ULONGLONG Time;
	ULONGLONG a_Time;
	vector<Object*>* EBulletList;

public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& _rTransInfo)PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;

public:
	Vector3 GetScale() { return Vector3(TransInfo.Scale.x,TransInfo.Scale.y); }

public:
	EnemyBridge();
	virtual ~EnemyBridge();

};

