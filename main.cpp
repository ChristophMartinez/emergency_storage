/*
 Part 1: Mason Bone
 Part 2: Christopher Martinez
 Part 3: Summer Hodges 
 Part 4: Alex Daughters
 
Description: The project as a whole takes data from multiple files and uses user-specfied queries from a stored census and vulnerability database. This program allows users to load in data in table format, query based searching, and then stores the data entered for later use.  
*/


#include<iostream>
#include"tableInput.h"

using namespace std;

int main()
{
	cout << "+---------------------------------------------+" << endl;
	cout << "|     Summer Hodges, Mason Bone, Christopher  |" << endl;
	cout << "|         Martinez, and Alex Daughters        |" << endl;
	cout << "|                CSCE 2110.001                |" << endl;
	cout << "|                   Group 39                  |" << endl;
	cout << "|       Project 3: Emergency Storage          |" << endl;
	cout << "+---------------------------------------------+" << endl;

	tableInput tableObj;
	tableObj.initialInput();
	cout << "IN funcs" << endl;
	tableObj.tableFuncs();
	return 0;
}
