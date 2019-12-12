/*
this is the collection header file: this file compiles the data grom the geog node header file and declares the hashing and user based funcs
author: Christopher Martinez
*/

#ifndef GEOGHASH_H
#define GEOGHASH_H
#include "geog.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class geogHash
{
	private:
		geogNode **tableG; //hash table of type geogNode
		vector < vector <string*> > geogList; 

	public:
		geogHash(); //used to init table
		~geogHash(); //default deconstructor

		int hashFunc(int key);// hash function to search through bucket
	       	int hashFunc2(int key);// ooh look another hash and no brown

		void INSERT(string replan, string geoName, string geoSub, string geoState, string geoLevel, string geoCountry, string geoId, string pop, string tableName);
		void UPDATE(string replan, string geoName, string geoSub, string geoState, string geoLevel, string geoCountry, string geoId, string pop, string tablename);	
		vector<geogNode> SELECT(string replan, string geoName, string geoSub, string geoState, string geoLevel, string geoCountry, string geoId, string pop, string tablename);		
		void DELETE(string replan, string geoName, string geoSub, string geoState, string geoLevel, string geoCountry, string geoId, string pop, string tablename);

		void DISPLAY();
		void WRITE();

};

#endif

