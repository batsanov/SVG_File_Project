#pragma once
#include <iostream>
#include "String.h"
#include "Vector.h"


class Figure {
private:
	int id;
	
public:
	Figure();

	static int idCounter;
	int getId()const;
	virtual void print(std::ostream& os) = 0;
	virtual void translate(int vertical, int horizontal) = 0;
	virtual String getFigureType() = 0;
	virtual void printSave(std::ostream& os) = 0;
	void setId(int _id);
	
	virtual Vector<int> getParams() = 0;
};



