// wGetListGen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	// handle args
	int counter;
	if (argc != 3)
	{
		cout << "Wrong input parameters: " << argc << " expected: 3"<< endl;
		cout << "usage: "<< argv[0] << " URL LastNumber" << endl;
		return 0;
	}
	else
	{
		printf("\nNumber Of Arguments Passed: %d", argc);
		printf("\n----Following Are The Command Line Arguments Passed----");
		for (counter = 0; counter < argc; counter++)
			printf("\nargv[%d]: %s", counter, argv[counter]);
		cout << endl;
	}

	string url = argv[1];
	int lastNumber = atoi(argv[2]);
	string path;
	string ext;

	std::size_t path_sep = url.find_last_of("/\\");
	if (path_sep > 0)
	{
		path = url.substr(0, path_sep);
		//cout << endl << path << endl;
	}
	else
	{
		cout << "wrong url path format" << endl;
	}

	std::size_t ext_sep = url.find_last_of("/.");
	if (ext_sep > 0)
	{
		ext = url.substr(ext_sep+1);
		//cout << endl << ext << endl;
	}
	else
	{
		cout << "wrong url ext format" << endl;
	}

	std::ofstream outfile("filelist.txt", std::ofstream::out| std::ofstream::trunc);

	for (int i = 1; i <= lastNumber; i++) 
	{
		outfile << path << "/" << i << "." << ext << endl;
	}
	
	outfile.close();

	return 0;
}

