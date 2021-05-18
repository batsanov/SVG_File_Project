#include "Rect.h"
#include "Circle.h"
#include "Line.h"
#include "Figure.h"
#include "CommandReader.h"
#include "Taskmanager.h"
#include "Vector.h"
#include "WithinCalculator.h"
#include <iostream>


int main() {

	//CommandReader reader;
	//reader.start();

	Figure* fgr = new Circle(5, 10, 15, "red");
     fgr->getParams().print();
	
}