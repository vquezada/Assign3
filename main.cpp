#include <iostream>
#include <fstream>
#include "syntaxChecker.h"
using namespace std;
int main(int argc, char** argv)
{
	cout << endl;
	string file;
	if(argc > 1)
	{
		file = argv[1];
	}
	else
	{
		cout << "Enter file:" << endl;
		cin >> file;
	}
	//user enters file
	syntaxChecker d1(file);
	d1.delimChecker();
	cout << "\nTo ckeck another file enter: Y\n To exit enter: N" << endl;
	char choice;
	cin >> choice;
	while(choice == 'y' || choice == 'Y')
	{
		cout << "\nEnter file:" << endl;
		cin >> file;
		d1.setFile(file);
		d1.delimChecker();
		cout << "\nTo ckeck another file enter: Y\n To exit enter: N" << endl;
		cin >> choice;
	}
	cout << endl;
	return 0;
}
