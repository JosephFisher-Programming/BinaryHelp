//  main.cpp

#include <fstream>
#include <iostream>
#include <string>


using std::string;

struct LibraryRecord
{
	string callNumber = "";
	string title = "";
	string Author = "";
	string bookStatus = "";
};

int main()
{
	LibraryRecord records[3];

	std::fstream binFile;
	binFile.open("library.dat", std::ios::in | std::ios::binary);
	binFile.read((char*)&records, sizeof(LibraryRecord));
	if (binFile.goodbit == true)
	{
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
			/*string a;
			while (std::getline(textFile, a))
			{
				records[0].callNumber = a;
				
			}*/
				string a;

			for (int i = 0; i < 3; i++) 
			{
				
				std::getline(textFile, a);
				records[i].callNumber = a;
				std::getline(textFile, a);
				records[i].title = a;
				/*std::getline(textFile, c);
				records[i].Author = c;
				std::getline(textFile, d);
				records[i].bookStatus = d;*/
			}

			binFile.open("library.dat", std::ios::out | std::ios::binary);
			binFile.write((char*)&records, sizeof(LibraryRecord));
			binFile.close();
				
		}

			
		}
	while (true) {}
	return 0;
}