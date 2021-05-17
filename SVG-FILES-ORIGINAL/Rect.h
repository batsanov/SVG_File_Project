#pragma once
#include <iostream>
#include "Figure.h"
#include "String.h"


class Rect : public Figure {
private:
	int x;
	int y;
	int width;
	int height;
	char* colour;
public:
	Rect();
	Rect(const int x, const int y, const int width, const int height, const char* colour);
	~Rect();
	friend std::ostream& operator<<(std::ostream& os, const Rect& rect);
	Rect& operator= (const Rect& other);
	void print(std::ostream& os)override;
	void translate(int vertical, int horizontal) override;
	String getFigureType() override;
	void printSave(std::ostream& os) override;

    bool isWithinRectangle(Rect& other) override; //to be implemented

};

