#pragma once
#include "Figure.h"
#include "Vector.h"
#include "String.h"
#include "Rect.h"
#include "Circle.h"
#include "Line.h"

class TaskManager {
private:   
	Vector<Figure*> container;
	String currentFile;
public:
	TaskManager();

	void print();
	void open(Vector<String> splittedCommand);
	void help();
	void save(Vector<String> splittedCommand);
	void create(Vector<String> splittedCommand);
	void close();
	void translate(Vector<String> splittedCommand);
	void erase(Vector<String> splittedCommand);
	void saveas(Vector<String> splittedCommand);
	void within(Vector<String> splittedCommand);

	void loadRect(char buff[100]);
	void loadCircle(char buff[100]);
	void loadLine(char buff[100]);

	Figure* loadRectFigFromInput(Vector<String>& splittedCommand);
	Figure* loadCircleFigFromInput(Vector<String>& splittedCommand);
	Figure* loadLineFigFromInput(Vector<String>& splittedCommand);

	Rect loadRectFromInput(Vector<String>& splittedCommand);
	Circle loadCircleFromInput(Vector<String>& splittedCommand);
	Line loadLineFromInput(Vector<String>& splittedCommand);

	String getCurrentFile()const ;

	
	
};