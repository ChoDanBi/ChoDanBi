#pragma once
#include "Headers.h"

class Object;
class Bridge
{
protected:
	string DrawKey;
	Object* RealObject;
	Transform TransInfo;
	static map<string, Bitmap*> ImageList;

public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& _rTransInfo)PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;
public:
	void SetObject(Object* _pObject) { RealObject = _pObject; }
	void SetPosintion(Vector3 _Pos) { TransInfo.Position = _Pos; }
public:
	Bridge();
	virtual ~Bridge();
};

