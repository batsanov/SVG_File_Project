#include "Taskmanager.h"
#include <iostream>
#include <fstream>
#include "Rect.h"
#include "Circle.h"
#include "Line.h"

TaskManager::TaskManager()
{
	currentFile = "";
}

void TaskManager::print()
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

void TaskManager::open(Vector<String> splittedCommand)
{
	
	currentFile = splittedCommand[1];
	char* fileName = new char[currentFile.length() + 3];
	currentFile.stringCopy(fileName);

	std::ifstream in;
	in.open(fileName);
	
	if (in)
	{
		std::cout << "Successfully opened " << fileName <<  std::endl;

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
				else if(word == "<circle")
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

void TaskManager::help()
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
	std::cout << "erase<n>		erases figure with a number <n>" << std::endl;
	std::cout << "within<option>		Displays all figures contained in given region. The user can specify by <option> what the region should be - circle (circle) or rectangle (rectangle)" << std::endl;
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
	String areaShape = splittedCommand[1];
	
	for (size_t i = 0; i < container.getsize(); i++)
	{
		
	}

}



void TaskManager::create(Vector<String> splittedCommand)
{
	String wantedShape = splittedCommand[1];

	if (wantedShape == "rectangle" || wantedShape == "Rectangle")
	{
		loadRectFromInput(splittedCommand);
		std::cout << "Successfully created " << wantedShape << std::endl;
	}
	else if (wantedShape == "circle" || wantedShape == "Circle")
	{
		loadCircleFromInput(splittedCommand);
		std::cout << "Successfully created " << wantedShape << std::endl;
	}
	else if (wantedShape == "line" || wantedShape == "Line") {
		loadLineFromInput(splittedCommand);
		std::cout << "Successfully created " << wantedShape << std::endl;
	}
	else
	{
		std::cout << "Invalid shape!" << std::endl;
	}
}

void TaskManager::close()
{
	std::cout << "Successfully closed " << currentFile << std::endl;
	container.clearVector();
	currentFile = "";
}

void TaskManager::translate(Vector<String> splittedCommand)
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
				//translate 1 vertical=20 horizontal=10
				String firstCommand(splittedCommand[2]);
				String secondCommand(splittedCommand[3]);
				String firstParam("");
				String secondParam("");

				// 9,11 to const

				for (size_t i = 9; i < firstCommand.length(); i++)
				{
					firstParam += firstCommand[i];
				}

				for (size_t i = 11; i < secondCommand.length(); i++)
				{
					secondParam += secondCommand[i];
				}

				container[figureIndex - 1]->translate(firstParam.parseToInt(), secondParam.parseToInt());
				std::cout << "Translated figure No " << figureIndex <<std::endl;
			}
			
	}
	else
	{
		String firstCommand(splittedCommand[1]);
		String secondCommand(splittedCommand[2]);
		String firstParam("");
		String secondParam("");

		for (size_t i = 9; i < firstCommand.length(); i++)
		{
			firstParam += firstCommand[i];
		}

		for (size_t i = 11; i < secondCommand.length(); i++)
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

void TaskManager::erase(Vector<String> splittedCommand)
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
		Figure::idCounter = 1;
		for (size_t i = 0; i < container.getsize(); i++)
		{
			container[i]->setId(container[i]->idCounter++);
		}
	}
}


//Helping functions

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

void TaskManager::loadRectFromInput(Vector<String>& splittedCommand)
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

	char* color = new char[splittedCommand[6].length() + 1];
	splittedCommand[6].stringCopy(color);
	Figure* newFigure = new Rect(params[0], params[1], params[2], params[3], color);
	container.pushAtBack(newFigure);
	delete[] color;
}

void TaskManager::loadCircleFromInput(Vector<String>& splittedCommand)
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

	char* color = new char[splittedCommand[5].length() + 1];
	splittedCommand[5].stringCopy(color);
	Figure* newFigure = new Circle(params[0], params[1], params[2], color);
	container.pushAtBack(newFigure);
	delete[] color;
}

void TaskManager::loadLineFromInput(Vector<String>& splittedCommand)
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

	char* color = new char[splittedCommand[7].length() + 1];
	splittedCommand[7].stringCopy(color);
	Figure* newFigure = new Line(params[0], params[1], params[2], params[3], params[4], color);
	container.pushAtBack(newFigure);
	delete[] color;

}

String TaskManager::getCurrentFile() const
{
	return currentFile;
}



