#pragma once
#include "cocos2d.h"
class MainClass :public cocos2d::Scene
{
public:
	static cocos2d::Scene*createScene();
	virtual bool init();
	//====================
	int audio1, audio2;
	//===================
	//캐릭터 모션들
	void fall_animation();	//캐릭터가 아래로 떨어지는 모션		
	void stay_animation();	//캐릭터가 멈춰있는 모션			
	void jump_animation();	//캐릭터가 점프를 준비중인 모션		
	void move_animation();	//캐릭터가 움직이는 모션			
	void jumping_animation();	//캐릭터가 위로 점프중인 모션	
	void down_animation();	//캐릭터가 쓰러진 모션				
	void crash_animation();	//캐릭터가 부딫힌 모션				


	//캐릭터 실시간으로 어느 모션을 취할것인지
	void update(float dt);
	void scheduleCallback(float dt);

	cocos2d::PhysicsWorld* m_world;
	void createMyPhysicsWorld();

	//키보드
	virtual void onEnter();
	virtual void onExit();

	virtual void onKeyPressed
	(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void onKeyReleased
	(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	//=====================
	CREATE_FUNC(MainClass);

	

	cocos2d::Sprite*chara;
//	cocos2d::Vec2 currentPos;	//캐릭터의 현재 위치: 모션값으로 사용
private:
	cocos2d::EventListenerKeyboard*_listener;
	cocos2d::Vec2 beforePos;	//캐릭터의 이전 위치: 모션값으로 사용

	float jumpPower;				//점프를 얼마만큼 할것인지 사용
	bool fire;					//점프를 했는지 알아본다
	bool rightMove, leftMove;	//왼쪽과 오른쪽으로 가게 해준다
	bool left;					//좌우 반전 및 어디로 점프되는지 선택
	bool lend;	
	int lendtick;

	int charaSizeX;
	int charaSizeY;

	int _scene = 4;

	cocos2d::Layer*stage;
};