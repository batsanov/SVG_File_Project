#include "Rect.h"
#include <string.h>

Rect::Rect() : Figure()
{
}

Rect::Rect(const int _x, const int _y, const int _width, const int _height, String _colour) : Figure()
{
	x = _x;
	y = _y;
	width = _width;
	height = _height;
	colour = _colour;
}


Rect& Rect::operator=(const Rect& other)
{
	x = other.x;
	y = other.y;
	width = other.width;
	height = other.height;
	colour = other.colour;

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

Vector<int> Rect::getParams()
{
	Vector<int> params;
	params.pushAtBack(x);
	params.pushAtBack(y);
	params.pushAtBack(width);
	params.pushAtBack(height);
	return params;
}

int Rect::getX()const
{
	return x;
}

int Rect::getY()const
{
	return y;
}

int Rect::getWidth()const
{
	return width; 
}

int Rect::getHeight()const
{
	return height;
}



std::ostream& operator<<(std::ostream& os, const Rect& rect)
{
	os << "rectangle " << rect.x << " " << rect.y << " " << rect.width << " " << rect.height << " " << rect.colour;
	return os;
}