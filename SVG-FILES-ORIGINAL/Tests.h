#pragma once
#include <stdlib.h>
#include "Taskmanager.h"

void clearConsole() {
	char enter;
	std::cout << std::endl << "press a key to continue:";
	std::cin >> enter;
	system("CLS");
}

// The validation tests work for every functionality

void tests(){

	TaskManager m;
	Vector<String> print;
	print.pushAtBack("print");

	Vector<String> params;
	params.pushAtBack("help");
	m.help(params);             // prints all the functionalities of the app

	///////////////////////////////////////////////////////

	clearConsole();

	///////////////////////////////////////////////////////

	            // CREATE + WITHIN TESTS //

	params.clearVector();
	params.pushAtBack("create");
	params.pushAtBack("circle");
	params.pushAtBack("10");
	params.pushAtBack("10");
	params.pushAtBack("5");
	params.pushAtBack("red");
	m.create(params);      // 1st line - confirming the operation

	params.clearVector();
	params.pushAtBack("create");
	params.pushAtBack("rectangle");
	params.pushAtBack("5");
	params.pushAtBack("5");
	params.pushAtBack("10");
	params.pushAtBack("10");
	params.pushAtBack("red");
	m.create(params);         // 2nd line - confirming the operation

	params.clearVector();
	params.pushAtBack("create");
	params.pushAtBack("circle");
	params.pushAtBack("10");
	params.pushAtBack("z");
	params.pushAtBack("5");
	params.pushAtBack("red");
	m.create(params);      // 3rd line - invalid parameters because the input is a char instead of number

	params.clearVector();
	params.pushAtBack("create");
	params.pushAtBack("circle");
	params.pushAtBack("10");
	params.pushAtBack("4");
	params.pushAtBack("5");
	params.pushAtBack("boo");
	m.create(params);      // 4th line - invalid parameters because the input colour is not a valid one

	m.print(print);    // 5rd and 6th line - printing the existing objects with the same coordinates
					   // as the ones given at create function

	params.clearVector();
	params.pushAtBack("within");
	params.pushAtBack("rectangle");
	params.pushAtBack("0");
	params.pushAtBack("0");
	params.pushAtBack("15");
	params.pushAtBack("15");
	m.within(params); // 7th line - printing the circle as only it is within the rectangle that is wanted above

	params.clearVector();
	params.pushAtBack("within");
	params.pushAtBack("boo");
	params.pushAtBack("0");
	params.pushAtBack("0");
	params.pushAtBack("15");
	params.pushAtBack("15");  
	m.within(params);  // 8th line - printing invalid shape as input shape is boo

	///////////////////////////////////////////////////////
	
	clearConsole();

	///////////////////////////////////////////////////////
	
	     //  Translate + erase functionalities

	params.clearVector();
	params.pushAtBack("translate");
	params.pushAtBack("vertical=10");
	params.pushAtBack("horizontal=20");
	m.print(print);// 1st and 2nd line - current figures
	m.translate(params); // 3rd line - confirmation for the finished task
	m.print(print); // 4th and 5th line - translated all figures because there is no indication of wanted figure id

	params.clearVector();
	params.pushAtBack("translate");
	params.pushAtBack("1");
	params.pushAtBack("vertical=100");
	params.pushAtBack("horizontal=200");
	m.translate(params); //  6th line - confirmation for the finished task
	m.print(print); // 7th line- translated only figure 1 as the input indicated
		
	params.clearVector();
	params.pushAtBack("erase");
	params.pushAtBack("2");
	m.erase(params); // 8th line - confirmation for the finished task
	m.print(print); // 9th line - printing current figures

	params.clearVector();
	params.pushAtBack("erase");
	params.pushAtBack("4");
	m.erase(params); // 10th line - Error, no figure with id 4

	params.clearVector();
	params.pushAtBack("erase");
	params.pushAtBack("1");
	m.erase(params); // 11th -  confirmation for the finished task
	m.print(print); // printing no existing figures, as we erased them

}