/*
collections header file for age: this file compiles the data declared in the age node header and declares the funcs
author: Summer Hodges
*/
#include "ageNod.h"
#include <regex>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

class ageHash 
{
	private: //decla of dynamic array and vector matrix 
		ageNod **tableA; //hash table
		vector< vector<string*> > ageLinkedList;
	public:
		ageHash(); //default constructor
		~ageHash(); //defaualt deconstructor

		//decla of all funcs 
		int hashF(int key); //modulos hashing 
		void INSERT(string ageK, string u5, string u18, string o65, string table_name); //quadratic probing used along with modulos hashing
		void UPDATE(string ageK, string u5, string u18, string o65, string table_name);
		vector<ageNod> SELECT(string ageeK, string u5, string u18, string o65, string table_name);
		void DELETE(string ageK, string u5, string u18, string o65, string table_name);
		void DISPLAY();
		void WRITE();



};
