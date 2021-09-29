#pragma once
#include "Headers.h"

class Bitmap;
class Object
{
protected:
	// ** ������Ʈ�� �⺻ Transform
	Transform TransInfo;

	// ** �浹ü��  �⺻ Transform
	Transform Collider;
	Vector3 Offset;

	string strKey;
	bool Active;
	float Speed;
	int HitPoint;
	int Damage;

	// ** ��� �̹��� ����
	static map<string, Bitmap*> ImageList;
	//Object* Target;

public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;

	virtual Object* Clone()PURE;
public:
	// ** map���� ������ Image ���� �����̳ʺz Setting
	static void SetImageList(const map<string, Bitmap*>& _ImageList) { ImageList = _ImageList; }

	// ** map���� ������ Image ���� �����̳ʺz out
	static map<string, Bitmap*> GetImageList() { return ImageList; }


	// ** �̹����� ����ϴµ� ����ϴ� Key ���� out
	string GetKey() const { return strKey; }

	// ** ��ǥ�� Setting (Vector3)
	void SetPosition(Vector3 _position) { TransInfo.Position = _position; }

	// ** ��ǥ�� Setting (_x, _y)
	void SetPosition(float _x, float _y) { TransInfo.Position.x = _x; TransInfo.Position.y = _y; }

	// ** ��ǥ�� Vector3�� out
	Vector3 GetPosition() { return TransInfo.Position; }

	// ** ũ�⸦ Vector3�� out
	Vector3 GetScale() { return TransInfo.Scale; }

	void SetCollider(Vector3 _collider) { Collider.Scale = Vector3(_collider); }
	// ** �浹ü�� out.
	RECT GetCollider();
	
	Vector3 GetColliderPosition() { return Collider.Position; }
	Transform GetColliderTransform() { return Collider; }

	void SetDamage(int _Damage) { Damage = _Damage; }
	int GetDamage() { return Damage; }

	void SetHitPoint(int _HitPoint) { HitPoint = _HitPoint; }
	int GetHitPoint() { return HitPoint; }

	void CrashHitPoint(int _Damage) { HitPoint -= _Damage; }

	// ** �浹ü�� Setting
	void SetColliderPosition(float _x, float _y) { Collider.Position.x = _x; Collider.Position.y = _y; }
	
	void SetScale(Vector3 _Scale) { TransInfo.Scale.x = _Scale.x; TransInfo.Scale.y = _Scale.y; }

	// ** �浹ü�� Top ��ǥ�� ��ȯ.
	// ** ������Ʈ�� ����� ��� �̺�Ʈ �߻��� ��밡��.
	float GetRectTop() { return TransInfo.Position.y - (TransInfo.Scale.y / 2); }

	// ** ������ �������� �ִ°�� �Ʒ��� ���鿡�� ������ �Ǵٸ� �������� �����̵� Ȥ��
	// ** �Ϲ� �̵��ÿ� ������ �ϴܺκа� �浹�� ������ �� ����.
	float GetRectBottom() { return TransInfo.Position.y + (TransInfo.Scale.y / 2); }

	// ** ������Ʈ�� Ȱ��/��Ȱ�� �� [Ȯ��] �ϱ� ���� ��������� ���� ������� �ʰ�����. 
	bool GetActive() const { return Active; }

	// ** ������Ʈ�� Ȱ��/��Ȱ�� �� [Setting] �ϱ� ���� ��������� ���� ������� �ʰ�����. 
	void SetActive(const bool& _Active) { Active = _Active; }
public:
	Object();
	Object(const Transform& _rTransInfo) : TransInfo(_rTransInfo) { }
	virtual ~Object();
};

