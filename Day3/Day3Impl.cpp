#pragma warning(disable: 5050)
module day3;

import std.core;

bool isVertical(const char dir)
{
	return dir == 'U' || dir == 'D';
}

bool isHorizontal(const char dir)
{
	return dir == 'R' || dir == 'L';
}

const Point moveFromChar(const char direction)
{
	switch (direction)
	{
		case 'R':
			return {1, 0};
		case 'L':
			return {-1, 0};
		case 'U':
			return {0, 1};
		case 'D':
			return {0, -1};
	}
	return {0, 0};
}

const Point calcWireEnd(const Point& start, const char direction, const int distance)
{
	return start + (moveFromChar(direction) * distance);
}

const SegmentPair sortWires(const char directionA, const Segment& wireA, const Segment& wireB)
{
	const auto horizontal = isVertical(directionA) ? wireB : wireA;
	const auto vertical = isVertical(directionA) ? wireA : wireB;
	return std::make_pair(horizontal, vertical);
}

bool canIntersect(const char directionA, const char directionB)
{
	return (isHorizontal(directionA) && isVertical(directionB))
		|| (isHorizontal(directionB) && isVertical(directionA));
}

bool doIntersect(const Segment& horizontalWire, const Segment& verticalWire)
{
	const bool isHorizontallyOk = (horizontalWire.first.y >= verticalWire.first.y && horizontalWire.first.y <= verticalWire.second.y)
		|| (horizontalWire.first.y <= verticalWire.first.y && horizontalWire.first.y >= verticalWire.second.y);
	const bool isVerticallyOk = (verticalWire.first.x >= horizontalWire.first.x && verticalWire.first.x <= horizontalWire.second.x)
		|| (verticalWire.first.x <= horizontalWire.first.x && verticalWire.first.x >= horizontalWire.second.x);

	return isHorizontallyOk && isVerticallyOk;
}