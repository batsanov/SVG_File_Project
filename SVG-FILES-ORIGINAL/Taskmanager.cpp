#include "Taskmanager.h"
#include <iostream>
#include <fstream>
#include "Rect.h"
#include "Circle.h"
#include "Line.h"
#include "WithinCalculator.h"

bool isValidColour(String colour)
{
	if (colour == "blue" || colour == "red" || colour == "purple" || colour == "yellow" || colour == "pink" || colour == "green" ||
		colour == "orange" || colour == "lime" || colour == "aqua" || colour == "navy" || colour == "coral" || colour == "teal" ||
		colour == "mustard" || colour == "blue violet" || colour == "black" || colour == "white" || colour == "grey" || colour == "brown" ||
		colour == "dark green" || colour == "blue gray" || colour == "indigo" || colour == "pea green" || colour == "amber" || colour == "maroon")
	{
		return true;
	}
	return false;
}

bool validRectParams(Vector<String>& splittedCommand)
{
	for (size_t i = 2; i < 6; i++)
	{

		if (!(splittedCommand[i].isNumber()))
		{
			return false;
		}
	}

	if (splittedCommand.getsize() == 7 && isValidColour(splittedCommand[6])) {
		return true;
	}
	return false;
}

bool validCircleParams(Vector<String>& splittedCommand)
{
	for (size_t i = 2; i < 5; i++)
	{
		if (!(splittedCommand[i].isNumber()))
		{
			return false;
		}
	}

	if (splittedCommand.getsize() == 6 && isValidColour(splittedCommand[5])) {
		return true;
	}
	return false;
}

bool validLineParams(Vector<String>& splittedCommand)
{
	for (size_t i = 2; i < 7; i++)
	{
		if (!(splittedCommand[i].isNumber()))
		{
			return false;
		}
	}

	if (splittedCommand.getsize() == 8 && isValidColour(splittedCommand[7])) {
		return true;
	}
	return false;
}

bool validRectAreaParams(Vector<String>& splittedCommand)
{

	for (size_t i = 2; i < 6; i++)
	{
		if (!(splittedCommand[i].isNumber()))
		{
			return false;
		}
	}
	if (splittedCommand.getsize() != 6)
	{
		return false;
	}
	return true;
}

bool validCircleAreaParams(Vector<String>& splittedCommand)
{
	for (size_t i = 2; i < 5; i++)
	{
		if (!(splittedCommand[i].isNumber()))
		{
			return false;
		}
	}
	if (splittedCommand.getsize() != 5)
	{
		return false;
	}
	return true;
}



bool checkHorizontal(String command)
{
	String horizontal = "horizontal=";
	size_t i = 0;
	for (i; i < 11; i++)
	{
		if (command[i] != horizontal[i])
		{
			return false;
		}
	}
	for (i; i < command.length(); i++)
	{
		if (command[i] < '0' || command[i] > '9')
		{
			return false;
		}
	}
	return true;
}

bool checkVertical(String command)
{
	String vertical = "vertical=";
	size_t i = 0;
	for (i; i < 9; i++)
	{
		if (command[i] != vertical[i])
		{
			return false;
		}
	}
	for (i; i < command.length(); i++)
	{
		if (command[i] < '0' || command[i] > '9')
		{
			return false;
		}
	}
	return true;
}


bool areValidParamsTranslate(Vector<String>& splittedCommand)
{

	if (splittedCommand.getsize() == 3)
	{
		if (checkVertical(splittedCommand[1]) && checkHorizontal(splittedCommand[2]))
		{
			return true;
		}
		return false;

	}
	else if (splittedCommand.getsize() == 4)
	{

		if (checkVertical(splittedCommand[2]) && checkHorizontal(splittedCommand[3]))
		{
			return true;
		}
		return false;

	}
	else return false;
}




TaskManager::TaskManager()
{
	currentFile = "";
}

void TaskManager::print(Vector<String> splittedCommand)
{
	if (splittedCommand.getsize() == 1)
	{
		if (container.getsize() > 0)
		{
			for (size_t i = 0; i < container.getsize(); i++)
			{
				container[i]->print(std::cout);
			}
		}
		else
		{
			std::cout << "There is no existing figures!" << std::endl;
		}
	}
	else std::cout << "Invalid command! Try \"print\"!" << std::endl;
	
}

void TaskManager::open(Vector<String> splittedCommand)
{
	
	if (splittedCommand.getsize() > 1)
	{
		if (!(currentFile == ""))
		{
			std::cout << "Close the opened file first!" << std::endl;
		}
		else {
			currentFile = splittedCommand[1];
			char* fileName = new char[currentFile.length() + 3];
			currentFile.stringCopy(fileName);

			std::ifstream in;
			in.open(fileName);

			if (in)
			{
				std::cout << "Successfully opened " << fileName << std::endl;

				bool readingFigures = false;
				char buffer[100];

				while (in >> buffer)
				{
					String word(buffer);
					if (word == "<svg>") readingFigures = true;
					if (word == "</svg>") break;

					if (readingFigures) {

						in.getline(buffer, 100);
						if (word == "<rect")
						{
							loadRect(buffer);

						}
						else if (word == "<circle")
						{
							loadCircle(buffer);
						}
						else if (word == "<line") {
							loadLine(buffer);
						}
					}

				}
				in.close();
			}
			else
			{
				std::cout << "File does not exist. Created new file!" << std::endl;
				std::ofstream of;
				of.open(fileName);
			}
			delete[]fileName;
		}
		}
		
	else {
		std::cout << "Enter valid file name!" << std::endl;
	}
	
}

void TaskManager::help(Vector<String> splittedCommand)
{
	if (splittedCommand.getsize() == 1)
	{
		std::cout << "The following commands are supported :" << std::endl;
		std::cout << "open <file>		opens <file>" << std::endl;
		std::cout << "close			closes currently opened file" << std::endl;
		std::cout << "save			saves the currently open file" << std::endl;
		std::cout << "saveas <file>		saves the currently open file in <file>" << std::endl;
		std::cout << "help			prints this information" << std::endl;
		std::cout << "print			prints all the figures" << std::endl;
		std::cout << "create			creates new figure" << std::endl;
		std::cout << "erase<n>		erases figure with a number <n>" << std::endl;
		std::cout << "translate<n>		translates figure with a number <n>, or all the figures if there is no <n>" << std::endl;
		std::cout << "within<option>		Displays all figures contained in given region. The user can specify by <option> what the region should be - circle (circle) or rectangle (rectangle)" << std::endl;
	}
	else
		std::cout << "Invalid command! Try \"help\"!" << std::endl;
	
}

void saveHelper(char* fileName, Vector<Figure*>& container) {
	std::ofstream out;
	out.open(fileName);
	if (out)
	{
		out << "<?xml version= \"1.0\" standalone=\"no\"?>" << std::endl;
		out << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"" << std::endl;
		out << "  \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << std::endl;
		out << "<svg>" << std::endl;
		for (size_t i = 0; i < container.getsize(); i++)
		{
			container[i]->printSave(out);
		}
		out << "</svg>";
		std::cout << "Successfully saved the file" << std::endl;
	}
	else
	{
		std::cout << "An error occurred while saving the file! Please enter new command!" << std::endl;
	}
}

void TaskManager::save(Vector<String> splittedCommand)
{
	if (splittedCommand.getsize() > 1)
	{
		std::cout << "Invalid command!" << std::endl;
	}
	else
	{
		char* fileName = new char[currentFile.length() + 1];
		currentFile.stringCopy(fileName);

		saveHelper(fileName, container);
		delete[] fileName;
	}
	
}

void TaskManager::saveas(Vector<String> splittedCommand)
{
	char* fileName = new char[splittedCommand[1].length() + 1];
	splittedCommand[1].stringCopy(fileName);
	
	saveHelper(fileName, container);
	delete[] fileName;
}

void TaskManager::within(Vector<String> splittedCommand)
{
	String wantedShape = splittedCommand[1];
	

	if (wantedShape == "rectangle" || wantedShape == "Rectangle" )
	{
		if (!validRectAreaParams(splittedCommand))
		{
			std::cout << "Invalid parameters! " << std::endl;
		}
		else
		{
			Rect rect = loadRectFromInput(splittedCommand);
			Vector<Figure*> areWithin;

			for (size_t i = 0; i < container.getsize(); i++)
			{
				if (WithinCalculator::isWithin(rect, container[i]))
				{
					areWithin.pushAtBack(container[i]);
				}
			}

			if (areWithin.getsize() > 0)
			{
				for (size_t i = 0; i < areWithin.getsize(); i++)
				{
					areWithin[i]->print(std::cout);
				}
			}
			else std::cout << "No figures are located within wanted area!" << std::endl;
		}
		reNumerate();
	}

	else if (wantedShape == "circle" || wantedShape == "Circle")
	{
		if (!validCircleAreaParams(splittedCommand))
		{
			std::cout << "Invalid parameters!" << std::endl;
		}

		else
		{
			Circle circle = loadCircleFromInput(splittedCommand);
			Vector<Figure*> areWithin;

			for (size_t i = 0; i < container.getsize(); i++)
			{
				if (WithinCalculator::isWithin(circle, container[i]))
				{
					areWithin.pushAtBack(container[i]);
				}
			}

			if (areWithin.getsize() > 0)
			{
				for (size_t i = 0; i < areWithin.getsize(); i++)
				{
					areWithin[i]->print(std::cout);
				}
			}
			else std::cout << "No figures are located within wanted area!" << std::endl;

		}
		
	}
	else if (wantedShape == "line" || wantedShape == "Line") {
		std::cout << "Wanted area is a line! Try rectangle or circle area!" << std::endl;
	}
	else
	{
		std::cout << "Invalid shape!" << std::endl;
		return;
	}

}



void TaskManager::create(Vector<String> splittedCommand)
{
	String wantedShape = splittedCommand[1];

	if (wantedShape == "rectangle" || wantedShape == "Rectangle")
	{
		if (validRectParams(splittedCommand))
		{
			container.pushAtBack(loadRectFigFromInput(splittedCommand));
			std::cout << "Successfully created " << wantedShape << std::endl;
		}
		else std::cout << "Invalid parameters!" << std::endl;
	}

	else if (wantedShape == "circle" || wantedShape == "Circle")
	{
		if (validCircleParams(splittedCommand))
		{
			container.pushAtBack(loadCircleFigFromInput(splittedCommand));
			std::cout << "Successfully created " << wantedShape << std::endl;
		}
		else std::cout << "Invalid parameters!" << std::endl;
	}

	else if (wantedShape == "line" || wantedShape == "Line") {
		if (validLineParams(splittedCommand))
		{
			container.pushAtBack(loadLineFigFromInput(splittedCommand));
			std::cout << "Successfully created " << wantedShape << std::endl;
		}
		else std::cout << "Invalid parameters!" << std::endl;
	}
	else
	{
		std::cout << "Invalid shape!" << std::endl;
	}
}

void TaskManager::close(Vector<String> splittedCommand)
{
	if (splittedCommand.getsize() == 1)
	{
		std::cout << "Successfully closed " << currentFile << std::endl;
		container.clearVector();
		currentFile = "";
	}
	else
		std::cout << "Invalid command! Try \"close\"!" << std::endl;
	
}

void TaskManager::translate(Vector<String> splittedCommand)
{
	if (splittedCommand.getsize() == 1)
	{
		std::cout << "Enter valid parameters!" << std::endl;
	}
	else if ((areValidParamsTranslate(splittedCommand)))
	{

		if (splittedCommand[1].isNumber())
		{
			int figureIndex = splittedCommand[1].parseToInt();
			if (figureIndex > container.getsize())
			{
				std::cout << "There is no figure number " << figureIndex << " !";
			}
			else
			{
				String firstCommand(splittedCommand[2]);
				String secondCommand(splittedCommand[3]);
				String firstParam("");
				String secondParam("");

				const int verticalSize = 9;
				const int horizontalSize = 11;

				for (size_t i = verticalSize; i < firstCommand.length(); i++)
				{
					firstParam += firstCommand[i];
				}

				for (size_t i = horizontalSize; i < secondCommand.length(); i++)
				{
					secondParam += secondCommand[i];
				}

				container[figureIndex - 1]->translate(firstParam.parseToInt(), secondParam.parseToInt());
				std::cout << "Translated figure No " << figureIndex << std::endl;
			}

		}
		else
		{
			String firstCommand(splittedCommand[1]);
			String secondCommand(splittedCommand[2]);
			String firstParam("");
			String secondParam("");

			const int vertical = 9;
			const int horizontal = 11;

			for (size_t i = vertical; i < firstCommand.length(); i++)
			{
				firstParam += firstCommand[i];
			}

			for (size_t i = horizontal; i < secondCommand.length(); i++)
			{
				secondParam += secondCommand[i];
			}

			for (size_t i = 0; i < container.getsize(); i++)
			{
				container[i]->translate(firstParam.parseToInt(), secondParam.parseToInt());
			}
			std::cout << "Translated all figures" << std::endl;
		}
	}
	else std::cout << "Invalid command! Please check your spelling!" << std::endl;
}
	

void TaskManager::erase(Vector<String> splittedCommand)
{
	if (splittedCommand.getsize() > 1 )
	{
		if (splittedCommand[1].isNumber())
		{
			int index = splittedCommand[1].parseToInt();
			if (index > container.getsize())
			{
				std::cout << "There is no figure number " << index << " !" << std::endl;
			}
			else
			{
				std::cout << "Erased a " << container[index - 1]->getFigureType() << "(" << index << ")" << std::endl;
				container.eraseAt(index - 1);
				reNumerate();
			}
		}
		else std::cout << "Invalid position input!" << std::endl;
		
	}
	else {
		std::cout << "Invalid command! Type help for more info" << std::endl;
	}


}



void TaskManager::loadRect(char buff[100])
{

	Vector<int> params;
	String color;
	String currentParam = "";
	char ch = ' ';
	bool isParam = false;
	int pushesCounter = 0;

	for (size_t i = 0; i < 100; i++)
	{
		ch = buff[i];
		if (ch == '>') break;

		if (ch == '"' && isParam == false) {  // check if opening "
			isParam = true;
			continue;
		}

		else if (ch == '"' && isParam == true) {  // check if closing "
			if (pushesCounter == 4)
			{
				isParam = false;
				color = currentParam;
				currentParam = "";
			}
			else
			{
				isParam = false;
				params.pushAtBack(currentParam.parseToInt());
				currentParam = "";
				pushesCounter++;
			}
			
		}

		if (isParam)
		{
			currentParam += ch;
		}
	}
	char* col = new char[color.length() + 1];
	color.stringCopy(col);
	
	Figure* shape = new Rect(params[0], params[1], params[2], params[3], col);
	container.pushAtBack(shape);
}

void TaskManager::loadCircle(char buff[100])
{
	Vector<int> params;
	String color;
	String currentParam = "";
	char ch = ' ';
	bool isParam = false;
	int pushesCounter = 0;

	for (size_t i = 0; i < 100; i++)
	{
		ch = buff[i];
		if (ch == '>') break;

		if (ch == '"' && isParam == false) {  // check if opening "
			isParam = true;
			continue;
		}

		else if (ch == '"' && isParam == true) {  // check if closing "
			if (pushesCounter == 3)
			{
				isParam = false;
				color = currentParam;
				currentParam = "";
			}
			else
			{
				isParam = false;
				params.pushAtBack(currentParam.parseToInt());
				currentParam = "";
				pushesCounter++;
			}

		}

		if (isParam)
		{
			currentParam += ch;
		}
	}
	char* col = new char[color.length() + 1];
	color.stringCopy(col);

	Figure* shape = new Circle(params[0], params[1], params[2], col);
	container.pushAtBack(shape);
}

void TaskManager::loadLine(char buff[100])
{
	Vector<int> params;
	String color;
	String currentParam = "";
	char ch = ' ';
	bool isParam = false;
	int pushesCounter = 0;

	for (size_t i = 0; i < 100; i++)
	{
		ch = buff[i];
		if (ch == '>') break;

		if (ch == '"' && isParam == false) {  // check if opening "
			isParam = true;
			continue;
		}

		else if (ch == '"' && isParam == true) {  // check if closing "
			if (pushesCounter == 5)
			{
				isParam = false;
				color = currentParam;
				currentParam = "";
			}
			else
			{
				isParam = false;
				params.pushAtBack(currentParam.parseToInt());
				currentParam = "";
				pushesCounter++;
			}

		}

		if (isParam)
		{
			currentParam += ch;
		}
	}
	char* col = new char[color.length() + 1];
	color.stringCopy(col);

	Figure* shape = new Line(params[0], params[1], params[2], params[3],params[4], col);
	container.pushAtBack(shape);

}





Figure* TaskManager::loadRectFigFromInput(Vector<String>& splittedCommand)
{
	
	int params[4] ;
	for (size_t i = 2; i < 6; i++)
	{
		
		if (splittedCommand[i].parseToInt() < 0)
		{
			params[i - 2] = splittedCommand[i].parseToInt() * (-1);
		}
		else {
			params[i - 2] = splittedCommand[i].parseToInt();
		}
	}

	String color = splittedCommand[6];
	Figure* newFigure = new Rect(params[0], params[1], params[2], params[3], color);
	
	return newFigure;
}

Figure* TaskManager::loadCircleFigFromInput(Vector<String>& splittedCommand)
{
	int params[3];
	for (size_t i = 2; i < 5; i++)
	{
		if (splittedCommand[i].parseToInt() < 0)
		{
			params[i - 2] = splittedCommand[i].parseToInt() * (-1);
		}
		else {
			params[i - 2] = splittedCommand[i].parseToInt();
		}
	}

	String color = splittedCommand[5];
	Figure* newFigure = new Circle(params[0], params[1], params[2], color);

	return newFigure;
}

Figure* TaskManager::loadLineFigFromInput(Vector<String>& splittedCommand)
{
	int params[5];
	for (size_t i = 2; i < 7; i++)
	{
		if (splittedCommand[i].parseToInt() < 0)
		{
			params[i - 2] = splittedCommand[i].parseToInt() * (-1);
		}
		else {
			params[i - 2] = splittedCommand[i].parseToInt();
		}
	}

	String color = splittedCommand[7];
	Figure* newFigure = new Line(params[0], params[1], params[2], params[3], params[4], color);
	
	return newFigure;
}

Rect TaskManager::loadRectFromInput(Vector<String>& splittedCommand)
{
	int params[4];
	for (size_t i = 2; i < 6; i++)
	{

		if (splittedCommand[i].parseToInt() < 0)
		{
			params[i - 2] = splittedCommand[i].parseToInt() * (-1);
		}
		else {
			params[i - 2] = splittedCommand[i].parseToInt();
		}
	}

	String color = splittedCommand[6];
	 Rect newRect (params[0], params[1], params[2], params[3], color);

	return newRect;
}

Circle TaskManager::loadCircleFromInput(Vector<String>& splittedCommand)
{
	int params[3];
	for (size_t i = 2; i < 5; i++)
	{
		if (splittedCommand[i].parseToInt() < 0)
		{
			params[i - 2] = splittedCommand[i].parseToInt() * (-1);
		}
		else {
			params[i - 2] = splittedCommand[i].parseToInt();
		}
	}

	String color = splittedCommand[5];
	Circle newCircle (params[0], params[1], params[2], color);

	return newCircle;
}

Line TaskManager::loadLineFromInput(Vector<String>& splittedCommand)
{
	int params[5];
	for (size_t i = 2; i < 7; i++)
	{
		if (splittedCommand[i].parseToInt() < 0)
		{
			params[i - 2] = splittedCommand[i].parseToInt() * (-1);
		}
		else {
			params[i - 2] = splittedCommand[i].parseToInt();
		}
	}

	String color = splittedCommand[7];
	Line newLine (params[0], params[1], params[2], params[3], params[4], color);

	return newLine;
}

String TaskManager::getCurrentFile() const
{
	return currentFile;
}

void TaskManager::reNumerate()
{
	Figure::idCounter = 1;
	for (size_t i = 0; i < container.getsize(); i++)
	{
		container[i]->setId(container[i]->idCounter++);
	}
}









