#pragma once
#include <iostream>
#include "String.h"
#include "Circle.h"

class Figure {
private:
	int id;
	
public:
	
	static int idCounter;
	int getId()const;
	virtual void print(std::ostream& os) = 0;
	virtual void translate(int vertical, int horizontal) = 0;
	virtual String getFigureType() = 0;
	virtual void printSave(std::ostream& os) = 0;
	virtual bool isWithinRectangle(Rect& other) = 0; // implement
	virtual bool isWithinCircle(Circle other) = 0; // implement
	void setId(int _id);
	Figure();
};



