/* File: inputTable.cpp
 *
 * Authour: Mason BOne
 *
 * FIle: this file contains the declaration for the class table input
 */


#include <iostream>
#include<vector>
#include<string>
#include<fstream>
#include<regex>
#include<boost/algorithm/string.hpp>
#include"geogHash.h"
#include"ageHash.h"
#include"disaHash.h"
using namespace std;

//This class contains all initail info and the call the fuctions to change the tables
class tableInput
{
	private:
		//File objects
		geogHash geogObj;
		ageHash ageObj;
		disaHash disaObj;
		//Informaiton for the tables
		vector<string> tableNames;
		vector<string> tableFiles;
		//Data to go into the tables
		vector< vector<string> > table1;
		vector< vector<string> > table2;
		vector< vector<string> > table3;
		//Hiolds all funtions to be called
		vector<string> functions;

	public:
		//Intializes the tables
		void initialInput();
		//Calls the functions for the tables
		void tableFuncs();
		//Inializes the first table
		void start1(int z);
		//Inializes the second table
		void start2(int z);
		//Inializes the third table
		void start3(int z);
};
