/*
disability collections header file: this file declares all the table and the user-based funcs and hash funcs
author: Alex Daughters
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "disaNode.h"

using namespace std;

class disaHash
{
	private:
		disaNode **table; //decla of dynamic array
//		vector<vector<*disaNode>> nodeBoi;	


	public:
		disaHash(); //default constructor 
		~disaHash(); //deconstructor
		int hash(string k); //linear probing
		void INSERT(string geo, string hearing, string vision, string cognition, string ambu, string SC, string IL, string table_name);
		void UPDATE(string geo, string hearing, string vision, string cognition, string ambu, string SC, string IL, string table_name);
		void WRITE();
		void DISPLAY();
		void SELECT(); //FIXME
		void DELETE();

};
