#include "Line.h"
#include <string.h>

Line::Line() : Figure()
{
	colour = nullptr;
}

Line::Line(const int _x1, const int _y1, const int _x2, const int _y2, const int _width, String _colour) : Figure()
{
	x1 = _x1;
	y1 = _y1;
	x2 = _x2;
	y2 = _y2;
	width = _width;
	colour = _colour;
}



Line& Line::operator=(const Line& other)
{
	
	x1 = other.x1;
	x2 = other.x2;
	y1 = other.y1;
	y2 = other.y2;
	width = other.width;
	colour = other.colour;

	return *this;
}

void Line::print(std::ostream& os)
{
	 os << this->getId() << ". " << *this << std::endl;
}

void Line::translate(int vertical, int horizontal)
{
	x1 += horizontal;
	x2 += horizontal;
	y1 += vertical;
	y2 += vertical;

}

String Line::getFigureType()
{
	String type("line");
	return type;
}

void Line::printSave(std::ostream& os)
{
	os << "	<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\" width=\"" << width 
		<<"\" fill=\"" << colour << "\" />" << std::endl;
}

Vector<int> Line::getParams()
{
	Vector<int> params;
	params.pushAtBack(x1);
	params.pushAtBack(y1);
	params.pushAtBack(x2);
	params.pushAtBack(y2);
	return params;
}

int Line::getX1() const
{
	return x1;
}

int Line::getX2() const
{
	return x2;
}

int Line::getY1() const
{
	return y1;
}

int Line::getY2() const
{
	return y2;
}

std::ostream& operator<<(std::ostream& os, const Line& line)
{
	os << "line " << line.x1 << " " << line.y1 << " " << line.x2 << " "
		<< line.y2 << " " << line.width << " " << line.colour;
	return os;
}
