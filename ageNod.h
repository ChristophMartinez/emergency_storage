/*
age node header file: this file declares all the data types needed to store the age data set
author: Summer Hodges
*/
#ifndef AGENOD_H
#define AGENOD_H
#include <iostream>
#include <string>

using namespace std;

class ageNod {
	private: //vars for key and ages 
		string ageKey;
		string under5;
		string under18;
		string over65;
	public: //funcs to set and get all the data types 
		ageNod(); //default constructor 
		ageNod(string a,string b,string c,string d); //copy constructor

		//set and get funcs	
		string getAgeKey();
		void setAgeKey(string AgeKey);

		string getUnder5();
		void setUnder5(string Under5);

		string getUnder18();
		void setUnder18(string Under18);

		string getOver65();
		void setOver65(string Over65);
};

#endif
