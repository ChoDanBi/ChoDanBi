#pragma once
#include "Object.h"

class Player : public Object
{
private:
	bool bJump;
	bool Drop;
	float JumpSpeed;
	float OldPositionY;
	float JumpTime;
	int Frame;


public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
	
	virtual Object* Clone()override { return new Player(*this); }
public:
	bool GetJumpState() const { return bJump; }
	void Jump();
	void JumpOff() { bJump = false; }

	int GetSwing() { return Frame; }
public:
	Player();
	Player(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~Player();
};

