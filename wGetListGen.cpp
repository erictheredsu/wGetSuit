// wGetListGen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

inline char separator()
{
#if defined _WIN32 || defined __CYGWIN__
	return '\\';
#else
	return '/';
#endif
}

bool checkFileExist(const string filename)
{
	ifstream Infield(filename);
	bool isExist = Infield.good();
	Infield.close();
	return isExist;
}


int checklist(int lastNumber, string urlPath, string ext)
{
	string galleryNum;

	std::size_t path_sep = urlPath.find_last_of("/\\");
	if (path_sep > 0)
	{
		galleryNum = urlPath.substr(path_sep+1);
		//cout << endl << path << endl;
	}
	else
	{
		cout << "wrong url gallery number format" << endl;
	}

	string sep (1, separator());
	string path = "." + sep + "i.nhentai.net" + sep + "galleries" +sep + galleryNum + sep;
	string fileName;
	bool bAllExist = true;
	for (int i = 1; i <= lastNumber; i++) 
	{
		fileName = path + std::to_string(i) + "." + ext;
		if (!checkFileExist(fileName))
		{
			bAllExist = false;
			cout << fileName << " doesn't exist!" << endl;
		}
	}

	if (bAllExist)
	{
		cout << "good job! all files are exist!"<<endl;
	}

	return 0;
}

int main(int argc, char* argv[])
{
	// handle args
	int counter;
	if (argc < 3)
	{
		cout << "Wrong input parameters: " << argc << " expected: 3 or 4"<< endl;
		cout << "usage: "<< argv[0] << " URL LastNumber isChecklist(Y/N)" << endl;
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

	if (argc == 4 && (argv[3][0] == 'Y' || argv[3][0] == 'y'))
	{
		cout << "check files exist" << endl;
		return checklist(lastNumber ,path, ext);
	}
	else
	{

		std::ofstream outfile("filelist.txt", std::ofstream::out | std::ofstream::trunc);

		for (int i = 1; i <= lastNumber; i++)
		{
			outfile << path << "/" << i << "." << ext << endl;
		}

		outfile.close();
	}

	return 0;
}

