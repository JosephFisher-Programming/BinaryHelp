//  main.cpp

#include <iostream>
#include <fstream>
#include <string>

int main() 
{
	int decision = 0;
	std::ofstream writeFile;
	std::ifstream readFile;

	while (true) 
	{
		std::cout << "What do you want to do? \n[1] Display | [2] Write | [3] Clear | [4] Exit" << std::endl;
		std::cin >> decision;

		if (std::cin.fail())
		{
			std::cout << "You are an idiot" << std::endl;
			decision = 0;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else 
		{
			std::cin.ignore();
		}

		if (decision == 1) 
		{
			readFile.open("MyLog.txt", std::ios::in);
			std::string buffer;
			while (std::getline(readFile, buffer))
			{
				std::cout << buffer << std::endl;
			}
			readFile.close();
		}

		if (decision == 2) 
		{
			writeFile.open("MyLog.txt", std::ios::app);
			std::string input;

			std::cout << "What do you want to write in?" << std::endl;
			std::getline(std::cin, input);
			writeFile.seekp(0, std::ios_base::end);

			writeFile << input << std::endl;

			writeFile.flush();
			writeFile.close();
		}

		if (decision == 3) 
		{
			writeFile.open("MyLog.txt", std::ios::out);
			writeFile.clear();
			writeFile.close();
		}

		if (decision == 4) 
		{
			break;
		}
	}

	return 0;
}