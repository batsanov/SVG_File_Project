#include "CommandReader.h"
#include <cstring>

CommandReader::CommandReader()
{
	commandsSet.pushAtBack("print");
	commandsSet.pushAtBack("open");
	commandsSet.pushAtBack("help");
	commandsSet.pushAtBack("save");
	commandsSet.pushAtBack("create");
	commandsSet.pushAtBack("close"); 
	commandsSet.pushAtBack("translate");
	commandsSet.pushAtBack("erase");
	commandsSet.pushAtBack("saveas");
	commandsSet.pushAtBack("within");
	commandsSet.pushAtBack("exit");

}

void CommandReader::print()
{
	for (size_t i = 0; i < commandsSet.getsize(); i++)
	{
		std::cout << commandsSet[i] << " ";
	}
}

void CommandReader::start()
{
	TaskManager manager;
	do
	{
		bool isCommand = false;
		char temp[256];
		std::cin.getline(temp, 256);
		command = temp;
		split();
		
		size_t i = 0;
		for (i ; i < commandsSet.getsize(); i++)
		{
			if (splittedCommand[0] == commandsSet[i])
			{
				isCommand = true;
				break;
			}
		}

		if (!isCommand)
		{
			std::cout << "Invalid command! Type help for more info." << std::endl;
		}
		else if (!(splittedCommand[0] == "open") && manager.getCurrentFile() == "" && !(splittedCommand[0] == "help") && !(splittedCommand[0] == "exit"))
		{
			std::cout << "Wrong command! Open file first." << std::endl;
		}
		
		else {
			switch (i)
			{
			case 0: manager.print(); break;
			case 1: manager.open(splittedCommand); break;
			case 2: manager.help(); break;
			case 3: manager.save(splittedCommand); break;
			case 4: manager.create(splittedCommand); break;
			case 5: manager.close(); break;
			case 6: manager.translate(splittedCommand); break;
			case 7: manager.erase(splittedCommand); break;
			case 8: manager.saveas(splittedCommand); break;
			case 9: manager.within(splittedCommand); break;


			default:
				break;
			}
		}

	} while (!(command == "exit"));
	std::cout << "Exiting the program...";
}


void CommandReader::split()
{
	splittedCommand.clearVector();
	String currentWord = "";
	for (size_t i = 0; i < command.length(); i++)
	{
		if (command[i] == ' ')
		{
			splittedCommand.pushAtBack(currentWord);
			currentWord = "";
		}

		else {
			currentWord += command[i];

			if (i == command.length() - 1)
			{
				splittedCommand.pushAtBack(currentWord);
			}
		}
	}
}

