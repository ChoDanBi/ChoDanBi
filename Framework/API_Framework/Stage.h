#pragma once
#include "Scene.h"


class Object;
class Stage : public Scene
{
private:
	Object* m_pPlayer;
	list<Object*>* EnableList;
	map<string, list<Object*>>* DisableList;

	ULONGLONG Time;
	ULONGLONG SetTime;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Stage();
	virtual ~Stage();
};