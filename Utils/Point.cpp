#pragma warning(disable: 5050)
module point;

import std.core;

Point::Point(int xx, int yy)
	: x(xx)
	, y(yy)
{
}

Point::Point(int val)
	: Point(val, val)
{
}

Point::Point()
	: Point(0)
{
}

float Point::Length() const
{
	return sqrtf(x^2 + y^2);
}

Point Point::operator* (const int b) const
{
	return Point(*this) *= b;
}

Point Point::operator*= (int b)
{
	x *= b;
	y *= b;
	return *this;
}

Point Point::operator* (const Point& b) const
{
	return Point(*this) *= b;
}

Point& Point::operator*= (const Point& b)
{
	x *= b.x;
	y *= b.y;
	return *this;
}

Point Point::operator+ (const Point& b) const
{
	return Point(*this) += b;
}

Point& Point::operator+= (const Point& b)
{
	x += b.x;
	y += b.y;
	return *this;
}
