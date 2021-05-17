#include "Circle.h"
#include <string.h>

Circle::Circle() : Figure()
{
  colour = nullptr;
}

Circle::Circle(const int _cx, const int _cy, const int _r, const char* _colour) : Figure()
{
	cx = _cx;
	cy = _cy;
	r = _r;
	colour = new char[strlen(_colour) + 1];
	strcpy_s(colour, strlen(_colour) + 1, _colour);
}

Circle::~Circle()
{
	cx = cy = r = 0;
	delete[] colour;
}

Circle& Circle::operator=(const Circle& other)
{
	if (colour != nullptr)
	{
		delete[] colour;
	}
	cx = other.cx;
	cy = other.cy;
	r = other.r;
	colour = new char[strlen(other.colour) + 1];
	strcpy_s(colour, strlen(other.colour) + 1, other.colour);
	return *this;
}

void Circle::print(std::ostream& os)
{
	os << this->getId() << ". " << *this << std::endl;
}

void Circle::translate(int vertical, int horizontal)
{
	cx += horizontal;
	cy += vertical;

}

String Circle::getFigureType()
{
	String type("circle");
	return type;
}

void Circle::printSave(std::ostream& os)
{
	os << "	<circle cx=\"" << cx << "\" cy=\"" << cy << "\" r=\"" << r << "\" fill=\"" << colour << "\" />" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Circle& circle)
{
	os << "circle " << circle.cx << " " << circle.cy << " " << circle.r << " " << circle.colour;
	return os;
}
