#pragma once
#include <iostream>
#include "Figure.h"
#include "String.h"
class Line : public Figure {
private:
	int x1;
	int y1;
	int x2;
	int y2;
	int width;
	String colour;
public:
	Line();
	Line(const int _x1, const int _y1, const int _x2, const int _y2, const int width, String _colour);
	
	Line& operator=(const Line& other);

	friend std::ostream& operator<<(std::ostream& os, const Line& line);
	void print(std::ostream& os)override;
	void translate(int vertical, int horizontal) override;
	String getFigureType() override;
	void printSave(std::ostream& os) override;
	Vector<int> getParams() override; 

	int getX1()const;
	int getX2()const;
	int getY1()const;
	int getY2()const;
};
