/*
disbility node header file: this file declares all the data and funcs for the disability set
author: Alex Daughters
*/

#ifndef DISANODE_H
#define DISANODE_H
#include <iostream>
#include <string>

using namespace std;

class disaNode
{
	private: //data type declas 
		string geo_name;
		string hearing_disability;
		string vision_disability;
		string cognition_disability;
		string ambulatory_disability;
		string self_care_disability;
		string independent_living_disability;

	public: //funcs decla 
		disaNode(); //default constructor 
		disaNode(string a, string b, string c, string d, string e, string f, string g); //copy constructor
		//set and get funcs for data types 
		void setGeo_name(string x);
		string getGeo_name();
		void setHearing_disability(string x);
		string getHearing_disability();
		void setVision_disability(string x);
		string getVision_disability();
		void setCognition_disability(string x);
		string getCognition_disability();
		void setAmbulatory_disability(string x);
		string getAmbulatory_disability();
		void setSelf_care_disability(string x);
		string getSelf_care_disability();
		void setIndependent_living_disability(string x);
		string getIndependent_living_disability();


};

#endif
