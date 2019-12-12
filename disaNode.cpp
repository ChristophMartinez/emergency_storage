#include "disaNode.h"

using namespace std;

disaNode::disaNode()
{
	geo_name = "";
	hearing_disability = "";
	vision_disability = "";
	cognition_disability = "";
	ambulatory_disability = "";
	self_care_disability = "";
	independent_living_disability = "";
}

disaNode::disaNode(string a, string b, string c, string d, string e, string f, string g)
{
        geo_name = a;
        hearing_disability = b;
        vision_disability = c;
        cognition_disability = d;
        ambulatory_disability = e;
        self_care_disability = f;
        independent_living_disability = g;
}

void disaNode::setGeo_name(string x)
{
	geo_name = x;
}

string disaNode::getGeo_name()
{
	return geo_name;
}

void disaNode::setHearing_disability(string x)
{
	hearing_disability = x;
}

string disaNode::getHearing_disability()
{
	return hearing_disability;
}

void disaNode::setVision_disability(string x)
{
	vision_disability = x;
}

string disaNode::getVision_disability()
{
	return vision_disability;
}

void disaNode::setCognition_disability(string x)
{
	cognition_disability = x;
}

string disaNode::getCognition_disability()
{
	return cognition_disability;
}

void disaNode::setAmbulatory_disability(string x)
{
	ambulatory_disability = x;
}

string disaNode::getAmbulatory_disability()
{
	return ambulatory_disability;
}

void disaNode::setSelf_care_disability(string x)
{
	self_care_disability = x;
}

string disaNode::getSelf_care_disability()
{
	return self_care_disability;
}

void disaNode::setIndependent_living_disability(string x)
{
	independent_living_disability = x;
}

string disaNode::getIndependent_living_disability()
{
	return independent_living_disability;
}

