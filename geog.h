/*
geog node file: this declares all the data types that will be stored for the geog set
author: Christopher Martinez
*/
#ifndef GEOG_H
#define GEOG_H
#include <iostream>
#include <string>


using namespace std;

class geogNode
{
	private: //vars for geogNode data types 
		string replan_id;
		string geo_name;
		string geo_stusub;
		string geo_sumlevel;
		string geo_state;
		string geo_county;
		string geo_geoId;
		string population;
		

	public: //funcs for geogNode data types
		geogNode(); //default constructor 
		geogNode(string a, string b, string c, string d, string e, string f, string g, string h); //copy constructor
		
		//get and set funcs for the data types
		void setReplan_id(string replanid) {replan_id = replanid;};
		string getReplan_id() { return replan_id;};

		void setGeo_name(string geoname) {geo_name = geoname;};
		string getGeo_name() { return geo_name;};

		void setGeo_sumlevel(string geosumlevel) {geo_sumlevel = geosumlevel;};
		string getGeo_sumlevel() { return geo_sumlevel;};

		void setGeo_stusub(string geostusub) {geo_stusub = geostusub;};
		string getGeo_stusub() { return geo_stusub;};

		void setGeo_state(string geostate) {geo_state = geostate;};
		string getGeo_state() { return geo_state;};

		void setGeo_county(string geocounty) {geo_county = geocounty;};
		string getGeo_county() { return geo_county;};

		void setGeo_geoId(string geogeoId) {geo_geoId = geogeoId;};
		string getGeo_geoId() { return geo_geoId;};

		void setPopulation(string pop) {population = pop;};
		string getPopulation() { return population;};
};

#endif

