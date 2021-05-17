#include "Line.h"
#include <string.h>

Line::Line() : Figure()
{
	colour = nullptr;
}

Line::Line(const int _x1, const int _y1, const int _x2, const int _y2, const int _width, const char* _colour) : Figure()
{
	x1 = _x1;
	y1 = _y1;
	x2 = _x2;
	y2 = _y2;
	width = _width;
	colour = new char[strlen(_colour) + 1];
	strcpy_s(colour, strlen(_colour) + 1, _colour);
}

Line::~Line()
{
	x1 = y1 = x2 = y2 = width = 0;
	delete[] colour;
}

Line& Line::operator=(const Line& other)
{
	if (colour != nullptr)
	{
		delete[] colour;
	}
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

std::ostream& operator<<(std::ostream& os, const Line& line)
{
	os << "line " << line.x1 << " " << line.y1 << " " << line.x2 << " "
		<< line.y2 << " " << line.width << " " << line.colour;
	return os;
}
