//  main.cpp

#include <fstream>
#include <iostream>
#include <string>


using std::string;

struct LibraryRecord
{
	char callNumber[60]{ "" };
	char title[60]{ "" };
	char Author[60]{ "" };
	char bookStatus[60]{ "" };

	void printRecord()
	{
		std::cout << callNumber << std::endl;
		std::cout << title << std::endl;
		std::cout << Author << std::endl;
		std::cout << bookStatus << std::endl;
	}
};

void fileLoad(LibraryRecord *  records2) 
{
	LibraryRecord records[3];
	std::fstream binFile;
	binFile.open("library.dat", std::ios::in | std::ios::binary);
	if (binFile.is_open())
	{
		binFile.read((char*)records2, sizeof(records));
		binFile.close();
	}
	else
	{
		binFile.close();
		std::fstream textFile;
		textFile.open("library.txt", std::ios::in);

		if (textFile.bad())
		{
			std::cout << "ERROR FILE NOT FOUND" << std::endl;
		}
		else
		{
			string a;

			for (int i = 0; i < 3; i++)
			{

				std::getline(textFile, a);
				strcpy_s(records[i].callNumber, a.c_str());

				std::getline(textFile, a);
				strcpy_s(records[i].title, a.c_str());

				std::getline(textFile, a);
				strcpy_s(records[i].Author, a.c_str());

				std::getline(textFile, a);
				strcpy_s(records[i].bookStatus, a.c_str());
			}
			textFile.close();

			binFile.open("library.dat", std::ios::out | std::ios::binary);
			binFile.write((char*)&records, sizeof(records));
			binFile.close();
		}
	}	
}

void bookAdd() 
{
	LibraryRecord record;


}

int main()
{
	LibraryRecord records[5];

	fileLoad(records);

	for (int i = 0; i < 5; i++)
	{
		records[i].printRecord();
		std::fstream binFile;
	}
	
	while (true) {}
	return 0;
}