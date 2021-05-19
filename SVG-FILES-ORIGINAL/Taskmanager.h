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

	void print(Vector<String> splittedCommand);
	void open(Vector<String> splittedCommand);
	void help(Vector<String> splittedCommand);
	void save(Vector<String> splittedCommand);
	void create(Vector<String> splittedCommand);
	void close(Vector<String> splittedCommand);
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

	bool isValidColour(String colour);
	bool validRectParams(Vector<String>& splittedCommand);
	bool validCircleParams(Vector<String>& splittedCommand);
	bool validLineParams(Vector<String>& splittedCommand);
	bool validRectAreaParams(Vector<String>& splittedCommand);
	bool validCircleAreaParams(Vector<String>& splittedCommand);
	bool areValidParamsTranslate(Vector<String>& splittedCommand);
	bool checkHorizontal(String command);
	bool checkVertical(String command);

	
};