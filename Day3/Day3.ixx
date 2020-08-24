#pragma warning(disable: 5050)
export module day3;

import std.core;
export import point;

export using Segment = std::pair<Point, Point>;
export using SegmentPair = std::pair<Segment, Segment>;

export const Point calcWireEnd(const Point& start, const char direction, const int distance);
export const SegmentPair sortWires(const char directionA, const Segment& wireA, const Segment& wireB);
export bool canIntersect(const char directionA, const char directionB);
export bool doIntersect(const Segment& horizontalWire, const Segment& verticalWire);