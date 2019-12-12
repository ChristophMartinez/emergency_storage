/*
cpp geog collection file: this file defines all the user-baseed funcs as well as the modulos and mid-square funcs that are used
author: Chistopher Martinez
*/
#include "geog.h"
#include "geogHash.h"
#include <string>
#include <cmath>

using namespace std;

const int TABLE_SIZE = 20;
const int r = ceil(log10(TABLE_SIZE));

geogHash::geogHash()//default constructor to initialize table  
{
	tableG = new geogNode *[TABLE_SIZE]();
	/*
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		cout << "here" << endl;
		table[i]->setReplan_id("");
		cout << "here2" << endl;
		table[i]->setGeo_name("");
		table[i]->setGeo_state("");
		table[i]->setGeo_stusub("");
		table[i]->setGeo_sumlevel("");
		table[i]->setGeo_county("");
		table[i]->setGeo_geoId("");
		table[i]->setPopulation("");
	}
	*/
}

//deconstructor to clean it up
geogHash::~geogHash()
{
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		if(tableG[i] != NULL)
		{
			delete tableG[i];
			//delete[] table; //check on this later
		}

	}
	delete tableG;
}

//mid-square func 
int geogHash::hashFunc(int key)
{
	int pos = pow(key, 2);
	string spos = to_string(pos);
	string mpos = mpos.substr(floor(spos.size() / 2), r);
	return stoi(spos) % TABLE_SIZE;
}

//modulos func
int geogHash::hashFunc2(int key)
{
	return key % TABLE_SIZE;
}


//func that using collison strategy to save new info in bucket
void geogHash::INSERT(string replan, string geoName, string geoSub, string geoState, string geoLevel, string geoCounty, string geoId, string pop, string tableName)
{
	int key = stoi(replan);
	int pos = hashFunc(key);
	int probed = 0;
	
	while(probed < TABLE_SIZE)
	{
		if(tableG[pos] == NULL)
		{
			tableG[pos] = new geogNode(replan,geoName,geoSub,geoState,geoLevel,geoCounty,geoId,pop);
			/*
			cout << "geog 1: " << endl;
			*table[pos]->setReplan_id(replan);
			cout << "geog 2: " << endl;
                	table[pos]->setGeo_name(geoName);
                	table[pos]->setGeo_state(geoState);
                	table[pos]->setGeo_stusub(geoSub);
			table[pos]->setGeo_sumlevel(geoLevel);
                	table[pos]->setGeo_county(geoCounty);
                	table[pos]->setGeo_geoId(geoId);
                	table[pos]->setPopulation(pop);
			*/

			cout << "Inserted (" << replan << "," << geoName << "," << geoState << "," << geoSub << "," << geoLevel << "," << geoCounty << "," << geoId << "," << pop << ") into " << tableName << endl;

		return;	
		}
		
		probed++;

		pos = (hashFunc(stoi(replan)) + hashFunc2(stoi(replan)) * probed) % TABLE_SIZE;
	}
	cout << "Failed to insert (" << replan << ",\"" << geoName << "\"," << geoState << "\"" << geoSub << "\"" << geoLevel << "\"" << geoCounty << "\"" << geoId << "," << pop << "into (" << tableName << "\"" << ")" << endl;
}

//func that searches and updates new info into buckets
void geogHash::UPDATE(string replan, string geoName, string geoSub, string geoState, string geoLevel, string geoCounty, string geoId, string pop, string tablename)
{
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		if(tableG[i]->getReplan_id() == replan)
		{
			tableG[i] -> setReplan_id(replan);
			tableG[i] -> setGeo_name(geoName);
			tableG[i] -> setGeo_state(geoState);
			tableG[i] -> setGeo_stusub(geoSub);
			tableG[i] -> setGeo_sumlevel(geoLevel);
			tableG[i] -> setGeo_county(geoCounty);
			tableG[i] -> setGeo_geoId(geoId);
			tableG[i] -> setPopulation(pop);

		cout << "Successful update (" << replan << ".\"" << geoName << "\"." << geoState << "\"" << geoSub << "\"" << geoLevel << "\"" << geoCounty << "\"" << geoId << "." << pop << "into (" << tablename << "\"" << ")" << endl;
		
		return;
		}
		else
		{
			cout << "Could not update." << endl;
		}
	}
}


//func that displays stored data to user
void geogHash::DISPLAY()
{
	cout << setw(10) << "Replan_ID" << "Geo_Name" << "Geo_stusub" << "Geo_sumlevel" << "Geo_state" << "Geo_county" << "Geo_geoid" << "Population" << endl;

	for(int i = 0; i < TABLE_SIZE; i++)
	{
		if(tableG[i] != NULL)
		{
			cout << setw(10) << tableG[i] -> getReplan_id();
		       	cout << setw(45) << tableG[i] -> getGeo_name();
			cout << setw(30) << tableG[i] -> getGeo_stusub();
			cout << setw(30) << tableG[i] -> getGeo_sumlevel();
			cout << setw(30) << tableG[i] -> getGeo_state();
			cout << setw(30) << tableG[i] -> getGeo_county();
			cout << setw(30) << tableG[i] -> getGeo_geoId();
			cout << setw(30) << tableG[i] -> getPopulation();
			cout << endl;
		}
	}
	cout << endl;
}

//func that will save stored data to a seperate file
void geogHash::WRITE()
{
	ofstream os;

	os.open("geog_1.csv");

	os << "replan_id" << endl;

	os << "replan_id,geo_name,geo_stusab,geo_sumlev,geo_state,geo_county,geo_geoid,population" << endl;

	for(int i = 0; i < TABLE_SIZE; i++)
	{
		if(tableG[i] != NULL)
		{
			os << tableG[i]->getReplan_id() << "," << tableG[i]->getGeo_name() << "," << tableG[i]->getGeo_stusub() << "," << tableG[i]->getGeo_sumlevel() << "," << tableG[i]->getGeo_state() << "," << tableG[i]->getGeo_state() << "," << tableG[i]->getGeo_county() << "," << tableG[i]->getGeo_geoId() << "," << tableG[i]->getPopulation() << endl;
		}
	}
}


//select func
vector<geogNode> geogHash::SELECT(string replan, string geoName, string geoSub, string geoState, string geoLevel, string geoCounty, string geoId, string pop, string table_name)
{
        vector<geogNode> found;
        geogNode temp;
        for(int i = 0; i < TABLE_SIZE; i++)
        {
                if(tableG[i] != NULL)
                {
                        if((replan == "*" || replan == tableG[i]->getReplan_id()) && (geoName == "*" || geoName == tableG[i]->getGeo_name()) && (geoSub == "*" || geoSub == tableG[i]->getGeo_stusub()) && (geoState == "*" || geoState == tableG[i]->getGeo_state()) && (geoLevel == "*" || geoLevel == tableG[i]->getGeo_sumlevel()) && (geoCounty == "*" || geoCounty == tableG[i]->getGeo_county()) && (geoId == "*" || geoId == tableG[i]->getGeo_geoId()) && (pop == "*" || pop == tableG[i]->getPopulation()))
			{					
                                temp = *tableG[i];
                        	found.push_back(temp);
                        }
                }
        }
	if(found.size() > 1)
        {
                cout << "Found enteries: " << endl;
                for(int j = 0; j < found.size(); j++)
                {
                        cout << "(" << found.at(j).getReplan_id() << "," << found.at(j).getGeo_name() << "," << found.at(j).getGeo_sumlevel() << "," << found.at(j).getGeo_stusub() << "," << found.at(j).getGeo_state() << "," << found.at(j).getGeo_county() << "," << found.at(j).getGeo_geoId() << "," << found.at(j).getPopulation() << ") in " << table_name << endl;
                }
        }
        else if(found.size() == 1)
        {
                cout << "Found (" << found.at(0).getReplan_id() << "," << found.at(0).getGeo_name() << "," << found.at(0).getGeo_sumlevel() << "," << found.at(0).getGeo_stusub() << "," << found.at(0).getGeo_state() << "," << found.at(0).getGeo_county() << "," << found.at(0).getGeo_geoId() << "," << found.at(0).getPopulation() << ") in " << table_name << endl;
        }
        else
        {
                cout << "No entries match the query (" << replan << ".\"" << geoName << "\"." << geoState << "\"" << geoSub << "\"" << geoLevel << "\"" << geoCounty << "\"" << geoId << "." << pop << "into (" << table_name << "\"" << ")" << endl;
        }
}

void geogHash::DELETE(string replan, string geoName, string geoSub, string geoState, string geoLevel, string geoCounty, string geoId, string pop, string table_name)
{
	vector<int> found;
        for(int i = 0; i < TABLE_SIZE; i++)
        {
                if(tableG[i] != NULL)
                {
                        if((replan == "*" || replan == tableG[i]->getReplan_id()) && (geoName == "*" || geoName == tableG[i]->getGeo_name()) && (geoSub == "*" || geoSub == tableG[i]->getGeo_stusub()) && (geoState == "*" || geoState == tableG[i]->getGeo_state()) && (geoLevel == "*" || geoLevel == tableG[i]->getGeo_sumlevel()) && (geoCounty == "*" || geoCounty == tableG[i]->getGeo_county()) && (geoId == "*" || geoId == tableG[i]->getGeo_geoId()) && (pop == "*" || pop == tableG[i]->getPopulation()))
                        {
                                found.push_back(i);
                        }
                }
        }
        if(found.size() > 1)
        {
                cout << "Deleted enteries: " << endl;
                for(int j = 0; j < found.size(); j++)
                {
		       	cout << "Deleted (" << tableG[found.at(j)]->getReplan_id() << "," << tableG[found.at(j)]->getGeo_name() << "," << tableG[found.at(j)]->getGeo_sumlevel() << "," << tableG[found.at(j)]->getGeo_stusub() << "," << tableG[found.at(j)]->getGeo_state() << "," << tableG[found.at(j)]->getGeo_county() << "," << tableG[found.at(j)]->getGeo_geoId() << "," << tableG[found.at(j)]->getPopulation() << ") in " << table_name << endl;

			tableG[found.at(j)]->setReplan_id("");
			tableG[found.at(j)]->setGeo_name("");
			tableG[found.at(j)]->setGeo_sumlevel("");
			tableG[found.at(j)]->setGeo_stusub("");
			tableG[found.at(j)]->setGeo_state("");
			tableG[found.at(j)]->setGeo_county("");
			tableG[found.at(j)]->setGeo_geoId("");
			tableG[found.at(j)]->setPopulation("");

			delete tableG[found.at(0)];
		}
        }
        else if(found.size() == 1)
        {
		cout << "Deleted (" << tableG[found.at(0)]->getReplan_id() << "," << tableG[found.at(0)]->getGeo_name() << "," << tableG[found.at(0)]->getGeo_sumlevel() << "," << tableG[found.at(0)]->getGeo_stusub() << "," << tableG[found.at(0)]->getGeo_state() << "," << tableG[found.at(0)]->getGeo_county() << "," << tableG[found.at(0)]->getGeo_geoId() << "," << tableG[found.at(0)]->getPopulation() << ") in " << table_name << endl;

		tableG[found.at(0)]->setReplan_id("");
                tableG[found.at(0)]->setGeo_name("");
                tableG[found.at(0)]->setGeo_sumlevel("");
                tableG[found.at(0)]->setGeo_stusub("");
                tableG[found.at(0)]->setGeo_state("");
                tableG[found.at(0)]->setGeo_county("");
                tableG[found.at(0)]->setGeo_geoId("");
                tableG[found.at(0)]->setPopulation("");

                delete tableG[found.at(0)];

        }
        else
        {
                cout << "Failed to delete (" << replan << ".\"" << geoName << "\"." << geoState << "\"" << geoSub << "\"" << geoLevel << "\"" << geoCounty << "\"" << geoId << "." << pop << "into (" << table_name << "\"" << ")" << endl;
        }
}

