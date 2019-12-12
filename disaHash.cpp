/*
disability collections cpp file: this file defines the constructors, hash funcs, and the user-based funcs
author: Alex Daughters
*/

#include "disaHash.h"

using namespace std;

const int TABLE_SIZE = 20;
const int MULT = 2;

//default constructor 
disaHash::disaHash()
{
	table = new disaNode*[TABLE_SIZE];
	/*
	for( int i = 0; i < TABLE_SIZE; i++)
	{
		table[i]->setGeo_name(NULL);
		table[i]->setHearing_disability(NULL);
		table[i]->setVision_disability(NULL);
		table[i]->setCognition_disability(NULL);
		table[i]->setAmbulatory_disability(NULL);
		table[i]->setSelf_care_disability(NULL);
		table[i]->setIndependent_living_disability(NULL);
	}
	*/
}

//deconstructor to delete 
disaHash::~disaHash()
{
	for( int i = 0; i < TABLE_SIZE; i++)
	{
		if(table[i] != NULL)
		{
			delete table[i];
			//delete[] table;
		}
	}
	delete table;
}

int disaHash::hash(string k)//linear hashing
{
	int pos = 0;

	for(char c : k)
	{
		pos = (pos * MULT) + c;
	}
	return (pos % TABLE_SIZE);
}

void disaHash::INSERT(string geo, string hearing, string vision, string cognition, string ambu,string SC, string IL, string table_name)
{
	int pos = hash(geo);
	int probed = 0;

	while(probed < TABLE_SIZE)
	{
		//setting all of the values into the bucket at pos if nothing is there
		if(table[pos]== NULL)
		{
			/*
			table[pos]->setGeo_name(geo);
			table[pos]->setHearing_disability(hearing);
			table[pos]->setVision_disability(vision);
			table[pos]->setCognition_disability(cognition);
			table[pos]->setAmbulatory_disability(ambu);
			table[pos]->setSelf_care_disability(SC);
			table[pos]->setIndependent_living_disability(IL);
			*/

			table[pos] = new disaNode(geo,hearing,vision,cognition,ambu,SC,IL);
			
			//cout the inserted information to the user
			cout << "Inserted (" << geo << "," << hearing << "," << vision << "," << cognition << "," << ambu << "," << SC << "," << IL << ") into " << table_name << endl;
			return;
		}
		
		//incrimenting to the next bucket
		pos = (pos + 1) % TABLE_SIZE;
		probed++;
	}
	cout << "Failed to insert (\"" << geo << "\"," << hearing << ","
		 << vision << "," << cognition << "," << ambu << "," << SC
		 << "," << IL << ") into " << table_name << endl;

}

void disaHash::UPDATE(string geo, string hearing, string vision, string cognition, string ambu,string SC, string IL, string table_name)		
{
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		if(table[i] == NULL)
		{
			table[i]->setGeo_name(geo);
			table[i]->setHearing_disability(hearing);
			table[i]->setVision_disability(vision);
			table[i]->setCognition_disability(cognition);
			table[i]->setAmbulatory_disability(ambu);
			table[i]->setSelf_care_disability(SC);
			table[i]->setIndependent_living_disability(IL);

			cout << "Updated (\"" << geo << "\"," << hearing << ","
				<< vision << "," << cognition << "," << ambu << "," << SC
				<< "," << IL << ") into " << table_name << endl;
			return;
		}
	}

	cout << "Failed to update (\"" << geo << "\"," << hearing << ","
		<< vision << "," << cognition << "," << ambu << "," << SC
		<< "," << IL << ") into " << table_name << endl;
}

void disaHash::DISPLAY()
{
	cout << setw(45) << "geo_name" << setw(19) << "hearing_disability" << setw(18) << "vision_disability"
		<< setw(21) << "cognition_disability" << setw(22) << "ambulatory_disability" << setw(21)
		<< "self_care_disability" << setw(30) << "independent_living_disability" << endl;
	

	for(int i = 0; i < TABLE_SIZE; i++)
	{
		if(table[i] != NULL)
		{
			cout << setw(45) << table[i]->getGeo_name();
			cout << setw(19) << table[i]->getHearing_disability();
			cout << setw(18) << table[i]->getVision_disability();
			cout << setw(21) << table[i]->getCognition_disability();
			cout << setw(22) << table[i]->getAmbulatory_disability();
			cout << setw(21) << table[i]->getSelf_care_disability();
			cout << setw(30) << table[i]->getIndependent_living_disability();
			cout << endl;
		}
	}
	cout << endl;
}

void disaHash::WRITE()
{
	ofstream out;
	out.open("disability_1.csv");
	
	out << "geo_name" << endl;
	out << "geo_name,hearing_disability,vision_disability,cognitive_disability,ambulatory_disability,self_care_disability,independent_living_disability" << endl;
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		if(table[i] != NULL)
		{
			out << table[i]->getGeo_name() << "," << table[i]->getHearing_disability() << "," << table[i]->getVision_disability() << "," << table[i]->getCognition_disability() << "," << table[i]->getAmbulatory_disability() << "," << table[i]->getSelf_care_disability() << "," << table[i]->getIndependent_living_disability() << endl;
		}
	}
}

