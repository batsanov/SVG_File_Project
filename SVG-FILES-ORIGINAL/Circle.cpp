#include "Circle.h"
#include <string.h>



Circle::Circle() : Figure()
{
}

Circle::Circle(const int _cx, const int _cy, const int _r, String _colour) : Figure()
{
	cx = _cx;
	cy = _cy;
	r = _r;
	colour = _colour;
}



Circle& Circle::operator=(const Circle& other)
{

	cx = other.cx;
	cy = other.cy;
	r = other.r;
	colour = other.colour;
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

Vector<int> Circle::getParams()
{
	Vector<int> params;
	params.pushAtBack(cx);
	params.pushAtBack(cy);
	params.pushAtBack(r);
	return params;
}



int Circle::getCx() const
{
	return cx;
}

int Circle::getCy() const
{
	return cy;
}

int Circle::getR() const
{
	return r;
}

std::ostream& operator<<(std::ostream& os, const Circle& circle)
{
	os << "circle " << circle.cx << " " << circle.cy << " " << circle.r << " " << circle.colour;
	return os;
}
