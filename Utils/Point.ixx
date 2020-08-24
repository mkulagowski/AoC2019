#pragma warning(disable: 5050)
export module point;

import std.core;

export class alignas(16) Point
{
public:
	int x, y;

	Point(int xx, int yy);
	Point(int val);
	Point();

	float Length() const;

	Point operator* (const int b) const;
	Point operator*= (const int b);

	Point operator* (const Point& b) const;
	Point& operator*= (const Point& b);

	Point operator+ (const Point& b) const;
	Point& operator+= (const Point& b);
};
