#pragma once
#include <iostream>
#include "Figure.h"
#include "String.h"


class Circle : public Figure  {
private:
	int cx;
	int cy;
	int r;
	String colour;


public:

	Circle();
	Circle( const int _cx, const int _cy, const int _r, String _colour);
	Circle& operator=(const Circle&);


	friend std::ostream& operator<<(std::ostream& os, const Circle& circle);
	void print(std::ostream& os) override;
	void translate(int vertical, int horizontal) override;
	String getFigureType() override;
	void printSave(std::ostream& os) override;
	Vector<int> getParams() override;

	int getCx() const;
	int getCy() const;
	int getR() const;
	
};
