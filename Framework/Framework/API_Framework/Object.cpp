#include "Object.h"




Object::Object()
{

}

Object::~Object()
{

}

RECT Object::GetRect()
{
	return RECT{
		LONG(TransInfo.Position.x - (TransInfo.Scale.y / 2)) ,
		LONG(TransInfo.Position.y - (TransInfo.Scale.y / 2)) ,
		LONG(TransInfo.Position.x + (TransInfo.Scale.y / 2)) ,
		LONG(TransInfo.Position.y + (TransInfo.Scale.y / 2)) };
}