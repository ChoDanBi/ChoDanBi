#pragma once

struct Vector3
{
	float x, y, z;

	Vector3() : x(0), y(0), z(0) {}

	Vector3(float _x, float  _y) : x(_x), y(_y), z(0) {}
};

struct Transform
{
	Vector3 Position;
	Vector3 Scale;
	Vector3 Direction;
};

