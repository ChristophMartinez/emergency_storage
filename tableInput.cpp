/* File: tableInput.cpp
 *
 * Author: Mason Bone
 *
 * File: this file cotains the function definitions for the input table class
 */

#include "tableInput.h"

//This function gets the intial tables and stores themm
void tableInput::initialInput()
{
	//Gets the users file 
	string fileName;
	cout << "Please enter the main file's name: ";
	cin >> fileName;

	ifstream instream;
	//Opens file
	instream.open(fileName);

	string temp;
	
	//Gets the file names and the table names
	for(int i= 0; i < 6; i++)
	{
		instream >> temp;
		regex e ("csv");
		if(regex_search(temp, e)) //temp.find(".csv") != string::npos)
		{
			tableFiles.push_back(temp);
		}
		else
		{
			tableNames.push_back(temp);
		}
	}
	/*
	vector<string> tempNames;
	vecotr<string> tempFiles;
	regex age ("age");
	regex geog ("geog");
	regex disa ("disa");
	if(regex_search(tableNames.at(0), geog) && regex_search(tableNames.at(1), age) && regex_search(tableNames.at(2), disa))
	{
	}
	else if(regex_search(tableNames.at(1), geog) && regex_search(tableNames.at(0), age) && regex_search(tableNames.at(2), disa))
	{
		tempNames.push_back
	}
	*/
	regex age ("age");
        regex geog ("geog");
        regex disa ("disa");

	//finds which table goes with which scheme
	for(int i = 0; i < 3; i++)
	{
		//Checks to see if both the file name and table name contain the word
		if(regex_search(tableNames.at(i), geog) && regex_search(tableFiles.at(i), geog))
		{
			start1(i);
		}
		else if(regex_search(tableNames.at(i), age) && regex_search(tableFiles.at(i), age))
                {
			start2(i);
		}
		else if(regex_search(tableNames.at(i), disa) && regex_search(tableFiles.at(i), disa))
		{
			start3(i);
		}
	}
	
	//Gets the rest of the functions to later be called
	while(!instream.eof())
	{
		getline(instream, temp);
		functions.push_back(temp);
	}
	instream.close();
}

//This fuction sorts and calls the fuctions given by the input file
void tableInput::tableFuncs()
{
	string temp;
	vector<string> results;
	//goes through every function
	for(int i = 0; i < functions.size(); i++)
	{
		//Finds what kind of function it is calling
		if(regex_search(functions.at(i), regex("DISPLAY")))
		{
			cout << "display" << endl;
			geogObj.DISPLAY();
			ageObj.DISPLAY();
			disaObj.DISPLAY();
		}
		else if(regex_search(functions.at(i), regex("INSERT")))
		{
			/*
			if(regex_search(functions.at(i), regex("geog")))
			{
				temp = functions.at(i).substr(functions.at(i).begin()+8, functions.at(i).end()-11);
				boost::split(results, temp, [](char c) {return c == ',';});	
				results.at(1) = results.at(1) + ',' + results.at(2);
                		geogObj.INSERT(results.at(0), results.at(1), results.at(3), results.at(4), results.at(5), results.at(6), results.at(7), results.at(8), tableNames.at(0));
			}
			else if(regex_search(functions.at(i), regex("age"))
			{

			}
			else if(regex_search(functions.at(i), regex("disa"))
			{
			}
			*/
		}
		else if(regex_search(functions.at(i), regex("UPDATE")))
		{

		}
		else if(regex_search(functions.at(i), regex("SELECT")))
		{

		}
		else if(regex_search(functions.at(i), regex("DELETE")))
		{

		}
		else if(regex_search(functions.at(i), regex("WRITE")))
		{
			geogObj.WRITE();
                        ageObj.WRITE();
                        disaObj.WRITE();
		}
	}
}

//Initializes the first table
void tableInput::start1(int z)
{
	//printd the first tables name and file anem
	cout << tableFiles.at(z) << " " << tableNames.at(z) << endl;
	cout << "Processing " << tableNames.at(z) << " table." << endl;

	ifstream is;
	string temp;
	is.open(tableFiles.at(z));
	
	getline(is, temp);
	getline(is, temp);
	
	vector<string> results;
	//gets all the iinformation for the first table
	while(!is.eof())
	{
		//splices the information to be called later
		getline(is, temp);
		boost::split(results, temp, [](char c) {return c == ',';});
		table1.push_back(results);
		results.clear();
	}

	//inserts the infor mation
	for(int i = 0; i < table1.size()-1; i++)
	{
		table1.at(i).at(1) = table1.at(i).at(1) + ',' + table1.at(i).at(2);
		geogObj.INSERT(table1.at(i).at(0), table1.at(i).at(1), table1.at(i).at(3), table1.at(i).at(4), table1.at(i).at(5), table1.at(i).at(6), table1.at(i).at(7), table1.at(i).at(8), tableNames.at(0));
	}
	//clears the table and closes the input stream
	table1.clear();
	is.close();
}

//initializes the second table
void tableInput::start2(int z)
{
	cout << tableFiles.at(z) << " " << tableNames.at(z) << endl;
	cout << "Processing " << tableNames.at(z) << " table." << endl;

        ifstream is;
        string temp;
        is.open(tableFiles.at(z));

        getline(is, temp);
        getline(is, temp);

        vector<string> results;

	//gets all info
        while(!is.eof())
        {
		//splices info
                getline(is, temp);
                boost::split(results, temp, [](char c) {return c == ',';});
                table2.push_back(results);
		results.clear();
        }

	//inserts info
        for(int i = 0; i < table2.size()-1; i++)
        {
                ageObj.INSERT(table2.at(i).at(0), table2.at(i).at(1), table2.at(i).at(2), table2.at(i).at(3), tableNames.at(1));
        }
	table2.clear();
        is.close();

}

//initializes the third table
void tableInput::start3(int z)
{
	cout << tableFiles.at(z) << " " << tableNames.at(z) << endl;
        cout << "Processing " << tableNames.at(z) << " table." << endl;

        ifstream is;
        string temp;
        is.open(tableFiles.at(z));

        getline(is, temp);
        getline(is, temp);

        vector<string> results;
	
	//gets info
        while(!is.eof())
        {
		//splices info
                getline(is, temp);
                boost::split(results, temp, [](char c) {return c == ',';});
                table3.push_back(results);
		results.clear();
        }

	//stores info
        for(int i = 0; i < table3.size()-1; i++)
        {
		table3.at(i).at(0) = table3.at(i).at(0) + ',' + table3.at(i).at(1);;
                disaObj.INSERT(table3.at(i).at(0), table3.at(i).at(2), table3.at(i).at(3), table3.at(i).at(4), table3.at(i).at(5), table3.at(i).at(6), table3.at(i).at(7), tableNames.at(1));
        }
	table3.clear();
        is.close();
}

