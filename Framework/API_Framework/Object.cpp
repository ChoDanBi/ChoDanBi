#include "Object.h"

map<string, Bitmap*> Object::ImageList;

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

RECT Object::GetCollider()
{
	return RECT{
		LONG(Collider.Position.x - (Collider.Scale.y / 2)) ,
		LONG(Collider.Position.y - (Collider.Scale.y / 2)) ,
		LONG(Collider.Position.x + (Collider.Scale.y / 2)) ,
		LONG(Collider.Position.y + (Collider.Scale.y / 2)) };
}