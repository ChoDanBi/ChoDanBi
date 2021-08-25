#pragma once
#include "Scene.h"


class Object;
class Stage : public Scene
{
private:
	Object* m_pPlayer;
	map<string, list<Object*>>* ObjectList;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Stage();
	virtual ~Stage();
};