/*
cpp file for age hash header file: this file defines all the funcs that were declared in header file
author: Summer Hodges
*/

#include "ageHash.h"

const int table_size = 20;

//constructor
ageHash::ageHash()
{
	tableA = new ageNod*[table_size];

	//initialize everything to NULL
	/*
	for(int i = 0; i < table_size; i++)
	{
		table[i]->setAgeKey("");
		table[i]->setUnder5("");
		table[i]->setUnder18("");
		table[i]->setOver65("");
	}
	*/
}

//deconstructor
ageHash::~ageHash()
{
	for(int i = 0; i < table_size; i++)
	{
		if(tableA[i] != NULL)
		{
			delete tableA[i];
		}
	}
	delete tableA;
}

//modulos hashing
int ageHash::hashF(int key)
{
	return key % table_size;
}

//quadratic collisons 
void ageHash::INSERT(string ageK, string u5, string u18, string o65, string table_name)
{
	int c1 = 3;
	int c2 = 5;
	regex e ("US");
	smatch sm;
	regex_search(ageK, sm, e);
	int pos = hashF(stoi(sm.suffix().str()));
	int probed = 0;
	
	while(probed < table_size)
	{
		if(tableA[pos] == NULL)
		{
			tableA[pos] = new ageNod(ageK,u5,u18,o65);
			/*
			table[pos]->setAgeKey(ageK);
			table[pos]->setUnder5(u5);
			table[pos]->setUnder18(u18);
			table[pos]->setOver65(o65);
			*/
			cout << "Inserted (" << ageK << "," << u5 << "," << u18 << "," << o65 << ") into " << table_name << endl;
			
			return;
		}
		
		probed++;
		int key = ceil((stoi(ageK)) + c1*probed + c2*pow(probed, 2));
		pos = (int) key;
		pos %= table_size;
	}

	cout << "Failed to insert (\"" << ageK << "\"," << u5 << "," << u18 << "," << o65 << ") into " << table_name << endl;
}

void ageHash::UPDATE(string ageK, string u5, string u18, string o65, string table_name)
{
	for(int i = 0; i < table_size; i++)
	{
		if(ageK == tableA[i]->getAgeKey())
		{
			tableA[i]->setAgeKey(ageK);
			tableA[i]->setUnder5(u5);
			tableA[i]->setUnder18(u18);
			tableA[i]->setOver65(o65);

			cout << "Updated (\"" << ageK << "\"," << u5 << "," << u18 << "," << o65 << ") in " << table_name << endl;

			return;
		}
	}

	cout << "Failed to update (\"" << ageK << "\"," << u5 << "," << u18 << "," << o65 << ") in " << table_name << endl;
}


vector<ageNod> ageHash::SELECT(string ageK, string u5, string u18, string o65, string table_name)
{
	vector<ageNod> found;
	ageNod temp;
	for(int i = 0; i < table_size; i++)
	{
		if(tableA[i] != NULL)
		{
			if(ageK == "*" || ageK == tableA[i]->getAgeKey())
			{
				if(u5 == "*" || u5 == tableA[i]->getUnder5())
				{
					if(u18 == "*" || u18 == tableA[i]->getUnder18())
					{
						if(o65 == "*" || o65 == tableA[i]->getOver65())
						{
							temp = *tableA[i];
							found.push_back(temp);
						}
					}
				}
			}
		}
	}
	if(found.size() > 1)
	{
		cout << "Found enteries: " << endl;
		for(int j = 0; j < found.size(); j++)
		{
			cout << "(\"" << found.at(j).getAgeKey() << "\"," << found.at(0).getUnder5() << "," << found.at(0).getUnder18() << "," << found.at(0).getOver65() << ") in " << table_name << endl;
		}
	}
	else if(found.size() == 1)
	{
		cout << "Found (\"" << found.at(0).getAgeKey() << "\"," << found.at(0).getUnder5() << "," << found.at(0).getUnder18() << "," << found.at(0).getOver65() << ") in " << table_name << endl;
	}
	else
	{
		cout << "No entries match the query (\"" << ageK << "\"," << u5 << "," << u18 << "," << o65 << ") in " << table_name << endl;
	}
}

//uses key to search through bucket and then sets queried find to null 
void ageHash::DELETE(string ageK, string u5, string u18, string o65, string table_name)
{
	vector<int> found;
        for(int i = 0; i < table_size; i++)
        {
                if(tableA[i] != NULL)
                {
                        if(ageK == "*" || ageK == tableA[i]->getAgeKey())
                        {
                                if(u5 == "*" || u5 == tableA[i]->getUnder5())
                                {
                                        if(u18 == "*" || u18 == tableA[i]->getUnder18())
                                        {
                                                if(o65 == "*" || o65 == tableA[i]->getOver65())
                                                {
                                                        found.push_back(i);
                                                }
                                        }
                                }
                        }
                }
        }
	if(found.size() > 1)
	{
		cout << "Deleted entries:" << endl;
		for(int i = 0; i < found.size(); i++)
		{
			cout << "(\"" << tableA[found.at(i)]->getAgeKey() << "\"," << tableA[found.at(i)]->getUnder5() << "," << tableA[found.at(i)]->getUnder18() << "," << tableA[found.at(i)]->getOver65() << ") in " << table_name << endl;
			
			tableA[found.at(i)]->setAgeKey("");
                        tableA[found.at(i)]->setUnder5("");
                        tableA[found.at(i)]->setUnder18("");
                        tableA[found.at(i)]->setOver65("");
			delete tableA[found.at(i)];
		}
	}
	if(found.size() == 1)
	{
		cout << "Deleted (\"" << tableA[found.at(0)]->getAgeKey() << "\"," << tableA[found.at(0)]->getUnder5() << "," << tableA[found.at(0)]->getUnder18() << "," << tableA[found.at(0)]->getOver65() << ") in " << table_name << endl;

                tableA[found.at(0)]->setAgeKey("");
               	tableA[found.at(0)]->setUnder5("");
                tableA[found.at(0)]->setUnder18("");
                tableA[found.at(0)]->setOver65("");
	}
	else
	{
		cout << "Failed to delete (\"" << ageK << "\"," << u5 << "," << u18 << "," << o65 << ") in " << table_name << endl;
	}
}

//displays saved data to user 
void ageHash::DISPLAY()
{
	cout << setw(13) << "geo_geoid";
	cout << setw(8) << "under_5";
	cout << setw(9) << "under_18";
	cout << setw(8) << "over_65" << endl;

	for(int i = 0; i < table_size; i++)
	{
		if(tableA[i] != NULL)
		{
			cout << setw(13) << tableA[i]->getAgeKey();
			cout << setw(8) << tableA[i]->getUnder5();
			cout << setw(9) << tableA[i]->getUnder18();
			cout << setw(8) << tableA[i]->getOver65() << endl;
		}
	}

	cout << endl;
}

//saves data to a separate file
void ageHash::WRITE()
{
	ofstream os;
	os.open("age_1.csv");

	os << "geo_geoid" << endl;
	os << "geo_geoid, under_5, under_18, over_65" << endl;

	for(int i = 0; i < table_size; i++)
	{
		if(tableA[i] != NULL)
		{
			os << tableA[i]->getAgeKey() << "," << tableA[i]->getUnder5() << "," << tableA[i]->getUnder18() << "," << tableA[i]->getOver65() << endl;
		}
	}
}

