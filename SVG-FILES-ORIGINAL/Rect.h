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
	String colour;
public:
	Rect();
	Rect(const int x, const int y, const int width, const int height, String colour);
	

	friend std::ostream& operator<<(std::ostream& os, const Rect& rect);
	Rect& operator= (const Rect& other);
	void print(std::ostream& os)override;
	void translate(int vertical, int horizontal) override;
	String getFigureType() override;
	void printSave(std::ostream& os) override;
	Vector<int> getParams() override;

	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;

};

