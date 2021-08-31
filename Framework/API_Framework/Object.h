#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform TransInfo;
	string strKey;
	bool Active;
	float Speed;
public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;

	virtual Object* Clone()PURE;
public:
	string GetKey() const { return strKey; }

	void SetPosition(Vector3 _position) { TransInfo.Position = _position; }
	Vector3 GetPosition() { return TransInfo.Position; }

	bool GetActive() const { return Active; }
	void SetActive(const bool& _Active) { Active = _Active; }
public:
	Object();
	Object(const Transform& _rTransInfo) : TransInfo(_rTransInfo) { }
	virtual ~Object();
};