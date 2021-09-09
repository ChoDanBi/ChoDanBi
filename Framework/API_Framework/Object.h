#pragma once
#include "Headers.h"

class Bitmap;
class Object
{
protected:
	Transform TransInfo;
	Transform Collider;
	Vector3 Offset;

	//STATE State;

	string strKey;
	bool Active;
	float Speed;



	static map<string, Bitmap*> ImageList;
	//Object* Target;
public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;

	virtual Object* Clone()PURE;
public:
	static void SetImageList(const map<string, Bitmap*>& _ImageList) { ImageList = _ImageList; }
	static map<string, Bitmap*> GetImageList() { return ImageList; }
	string GetKey() const { return strKey; }

	void SetPosition(Vector3 _position) { TransInfo.Position = _position; }
	void SetPosition(float _x, float _y) { TransInfo.Position.x = _x; TransInfo.Position.y = _y; }
	Vector3 GetPosition() { return TransInfo.Position; }
	Vector3 GetScale() { return TransInfo.Scale; }


	RECT GetRect();
	RECT GetCollider();
	void SetColliderPosition(float _x, float _y) { Collider.Position.x = _x; Collider.Position.y = _y; }
	
	//STATE GetState() { return State; }
	
	float GetRectTop() { return TransInfo.Position.y - (TransInfo.Scale.y / 2); }
	float GetRectBottom() { return TransInfo.Position.y + (TransInfo.Scale.y / 2); }

	bool GetActive() const { return Active; }
	void SetActive(const bool& _Active) { Active = _Active; }
public:
	Object();
	Object(const Transform& _rTransInfo) : TransInfo(_rTransInfo) { }
	virtual ~Object();
};