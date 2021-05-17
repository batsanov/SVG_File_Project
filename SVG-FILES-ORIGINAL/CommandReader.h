#pragma once
#include <iostream> 
#include "CommandReader.h"
#include "String.h"
#include "Taskmanager.h"
#include "Vector.h"

class CommandReader {
private:
	Vector<String> commandsSet;
	String command;
	Vector<String> splittedCommand;
public:
	CommandReader();
	void print();
	void start();
	void split();
	
};
