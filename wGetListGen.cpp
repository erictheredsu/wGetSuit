// wGetListGen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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

 void splitPath(string s, vector<string> &vect)
{
	 std::string delimiter = "/";

	 size_t pos = 0;
	 std::string token;
	 while ((pos = s.find(delimiter)) != std::string::npos) {
		 token = s.substr(0, pos);
		 //std::cout << token << std::endl;
		 if (token.length() > 0)
		 {
			 vect.push_back(token);
		 }
		 s.erase(0, pos + delimiter.length());
	 }
	 vect.push_back(s); //add left part;
}


int checklist(int startNumber, int lastNumber, string urlPath, string ext)
{
	//string galleryNum;

	//std::size_t path_sep = urlPath.find_last_of("/\\");
	//if (path_sep > 0)
	//{
	//	galleryNum = urlPath.substr(path_sep+1);
	//	//cout << endl << path << endl;
	//	return 0;
	//}
	//else
	//{
	//	cout << "wrong url gallery number format" << endl;
	//	return 0;
	//}

	vector<string> vect;
	splitPath(urlPath, vect);
	if (vect.size() == 0)
	{
		cout << "parse url fail!" << endl;
		return 0;
	}


	string sep (1, separator());
	//string path = "." + sep + "i.nhentai.net" + sep + "galleries" +sep + galleryNum + sep;
	string path = "." + sep + "Author_Unknown" + sep + vect[1] + sep +vect[2] + sep + vect[3] + sep;

	string fileName;
	bool bAllExist = true;
	for (int i = startNumber; i <= lastNumber; i++)
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
	if (argc < 4 || argc > 5)
	{
		cout << "Wrong input parameters: " << argc << " expected parameter number: 4 or 5"<< endl;
		cout << "usage: check files list range" << argv[0] << " URL startNumber endNumber " << endl;
		cout << "usage: check files exist" << argv[0] << " URL startNumber LastNumber check" << endl;

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

	//handle url
	string url = argv[1];
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

	int startNumber = atoi(argv[2]);
	int endNumber = atoi(argv[3]);

	if (argc == 5 && (argv[4][0] == 'C' || argv[4][0] == 'c'))
	{
		cout << "check files exist" << endl;
		return checklist(startNumber, endNumber, path, ext);
	}
	else // argc ==4
	{

		std::ofstream outfile("filelist.txt", std::ofstream::out | std::ofstream::trunc);

		for (int i = startNumber; i <= endNumber; i++)
		{
			outfile << path << "/" << i << "." << ext << endl;
		}

		outfile.close();
	}

	return 0;
}

