/*
geog node header file: this files defines the default and copy constructors
author: Christopher Martinez
*/

#include"geog.h"
using namespace std;

geogNode::geogNode()
{
        replan_id = "";
        geo_name = "";
        geo_stusub = "";
        geo_sumlevel = "";
        geo_state = "";
        geo_county = "";
        geo_geoId = "";
        population = "";

}

geogNode::geogNode(string a, string b, string c, string d, string e, string f, string g, string h)
{
	replan_id = a;
	geo_name = b;
	geo_stusub = c;
	geo_sumlevel = d;
	geo_state = e;
	geo_county = f;
	geo_geoId = g;
	population = h;
}

