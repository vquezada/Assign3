#include <iostream>
#include <fstream>
#include "syntaxChecker.h"
#include "GenStack.h"
using namespace std;
//opens file
syntaxChecker::syntaxChecker(string file)
{
	myfile = openFile(file);
	line = 1;
}
void syntaxChecker::setFile(string file)
{
	myfile = openFile(file);
	line = 1;
}
string syntaxChecker::openFile(string file)
{
	//throws error
	ifstream inputFile;
	inputFile.open(file);
	while(!inputFile){
		cout << endl;
		cout << "ERROR INVALID FILE Enter file:" << endl;
		cin >> file;
		inputFile.open(file);
	}
	return file;
}
//checks for open
char syntaxChecker::openDel(char d)
{
	if(d == '}')
	{
		return '{';
	}
	else if(d == ')')
	{
		return '(';
	}
	else if(d == ']')
	{
		return '[';
	}
}
//checks for close
char syntaxChecker::closeDel(char d)
{
	if(d == '{')
	{
		return '}';
	}
	else if(d == '(')
	{
		return ')';
	}
	else if(d == '[')
	{
		return ']';
	}
}
//adds to stack
void syntaxChecker::delimChecker()
{
	int max = 0;
	GenStack<char> s1(20);
	ifstream file(myfile);
	char delim;
	while(!file.eof()){
		file.get(delim);
		if(delim == '\n')
		{
			line++;
		}
		else if(delim == '{' || delim == '(' || delim == '[')
		{
			s1.push(delim);
		}
		else if(delim == '}' || delim == ')' || delim == ']')
		{
			if(s1.isEmpty())
			{
				cout << "Line " << line << ": Expected " << openDel(delim) << " but found " << delim << ".\n" << endl;
				exit(0);
			}
			else if(s1.peek() != openDel(delim))
			{
				cout << "Line " << line << ": Expected " << closeDel(s1.peek()) << " but found " << delim << ".\n" << endl;
				exit(0);
			}
			s1.pop();
		}
	}
	//checks if stack is empty
	if(!s1.isEmpty())
	{
		cout << "Reached end of file: missing " << closeDel(s1.peek()) << ".\n"<< endl;
		exit(0);
	}
	cout << "Delimiter syntax is correct." << endl;
}
