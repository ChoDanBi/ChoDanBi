#include "Object.h"

map<string, Bitmap*> Object::ImageList;

Object::Object()
{

}

Object::~Object()
{

}

RECT Object::GetCollider()
{
	return RECT{
		LONG(Collider.Position.x - (Collider.Scale.y / 2)) ,
		LONG(Collider.Position.y - (Collider.Scale.y / 2)) ,
		LONG(Collider.Position.x + (Collider.Scale.y / 2)) ,
		LONG(Collider.Position.y + (Collider.Scale.y / 2)) };
}