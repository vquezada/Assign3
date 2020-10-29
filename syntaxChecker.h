#include <iostream>
#include <fstream>
#ifndef SYNTAXCHECKER_H
#define SYNTAXCHECKER_H
using namespace std;
//syntax checker functions
class syntaxChecker
{
private:
	string myfile;
	int line;
public:
	syntaxChecker(string file);
	void setFile(string file);
	string openFile(string file);
	char openDel(char d);
	char closeDel(char d);
	void delimChecker();
};
#endif
