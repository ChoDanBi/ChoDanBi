#pragma once
#include "Object.h"

class Stage_Back : public Object
{
private :
	string m_strKey[7];
	int StageState;
	int Frame;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

public:
	void SetStageState(int _Num) { StageState = _Num; }
	void SetFrame(int _Frame) { Frame = _Frame; }

	virtual Object* Clone()
	{
		return new Stage_Back(*this);
	};
public:
	Stage_Back();
	virtual ~Stage_Back();
};