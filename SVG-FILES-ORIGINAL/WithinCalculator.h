#pragma once
#include "Circle.h"
#include "Rect.h"
#include "Line.h"

// MAKE ALL TO WORK WITH VECTOR OF INTS AS SECOND PARAM

class WithinCalculator {
public:
	static bool isWithin(Rect rect, Figure* other);
	static bool isWithin(Circle circle, Figure* other);

	static bool rectWithinRect( Rect& second, Rect& first);
	static bool circleWithinRect(Circle& circle, Rect& rect); 
	static bool lineWithinRect(Line& line, Rect& rect); 

	static bool circleWithinCircle(Circle& first, Circle& second);
	static bool rectWithinCircle(Rect& rect, Circle& circle); 
	static bool lineWithinCircle(Line& line, Circle& circle); 

	static bool pointWithinRect(int x1, int y1, int x2, int y2, int x, int y);
};