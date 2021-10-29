#pragma once

enum class SCENEID
{
	LOGO ,
	MENU ,
	SHOP ,
	SELECTSTAGE,
	STAGE,
	STAGE2,
	STAGE3,
	STAGE4,
	END,
	EXIT ,
};

enum class SKILL
{
	WAIT,
	ATTACK,
	DASH,
	STRINGPATTERN,
	END
};

enum class INVENTORY
{
	GOLD,
	DAMAGE,
	SPEED,
	BOMB,
	SHIELD
};

enum class ANIMATION
{
	UPSWING,
	DOWNSWING
};

enum class MOVE
{
	UP,
	DOWN,
	BACK,
	FORWARD,
	STAY
};