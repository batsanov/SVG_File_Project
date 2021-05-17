#include "Rect.h"
#include <string.h>

Rect::Rect() : Figure()
{
	x = y = width = height = 0;
	colour = new char[2];
	strcpy_s(colour, 2, " ");
}

Rect::Rect(const int _x, const int _y, const int _width, const int _height, const char* _colour) : Figure()
{
	x = _x;
	y = _y;
	width = _width;
	height = _height;
	colour = new char[strlen(_colour) + 1];
	strcpy_s(colour, strlen(_colour) + 1, _colour);
}

Rect::~Rect()
{
	x = y = width = height = 0;
	delete[] colour;
}

Rect& Rect::operator=(const Rect& other)
{
	x = other.x;
	y = other.y;
	width = other.width;
	height = other.height;
	if (colour != nullptr)
	{
		delete[] colour;
	}
	colour = new char[strlen(other.colour) + 1];
	strcpy_s(colour, strlen(other.colour) + 1, other.colour);
	return *this;
}

void Rect::print(std::ostream& os)
{
	os << this->getId() << ". " << *this << std::endl;
}

void Rect::translate(int vertical, int horizontal)
{
	x += horizontal;
	y += vertical;
}

String Rect::getFigureType()
{
	String type("rectangle");
	return type;
}

void Rect::printSave(std::ostream& os)
{
	os << "	<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << width 
		<< "\" height=\"" << height << "\" fill=\"" << colour << "\" />" << std::endl;
}


std::ostream& operator<<(std::ostream& os, const Rect& rect)
{
	os << "rectangle " << rect.x << " " << rect.y << " " << rect.width << " " << rect.height << " " << rect.colour;
	return os;
}