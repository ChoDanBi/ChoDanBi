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
	//ĳ���� ��ǵ�
	void fall_animation();	//ĳ���Ͱ� �Ʒ��� �������� ���		
	void stay_animation();	//ĳ���Ͱ� �����ִ� ���			
	void jump_animation();	//ĳ���Ͱ� ������ �غ����� ���		
	void move_animation();	//ĳ���Ͱ� �����̴� ���			
	void jumping_animation();	//ĳ���Ͱ� ���� �������� ���	
	void down_animation();	//ĳ���Ͱ� ������ ���				
	void crash_animation();	//ĳ���Ͱ� �΋H�� ���				


	//ĳ���� �ǽð����� ��� ����� ���Ұ�����
	void update(float dt);
	void scheduleCallback(float dt);

	cocos2d::PhysicsWorld* m_world;
	void createMyPhysicsWorld();

	//Ű����
	virtual void onEnter();
	virtual void onExit();

	virtual void onKeyPressed
	(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void onKeyReleased
	(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	//=====================
	CREATE_FUNC(MainClass);

	

	cocos2d::Sprite*chara;
//	cocos2d::Vec2 currentPos;	//ĳ������ ���� ��ġ: ��ǰ����� ���
private:
	cocos2d::EventListenerKeyboard*_listener;
	cocos2d::Vec2 beforePos;	//ĳ������ ���� ��ġ: ��ǰ����� ���

	float jumpPower;				//������ �󸶸�ŭ �Ұ����� ���
	bool fire;					//������ �ߴ��� �˾ƺ���
	bool rightMove, leftMove;	//���ʰ� ���������� ���� ���ش�
	bool left;					//�¿� ���� �� ���� �����Ǵ��� ����
	bool lend;	
	int lendtick;

	int charaSizeX;
	int charaSizeY;

	int _scene = 4;

	cocos2d::Layer*stage;
};