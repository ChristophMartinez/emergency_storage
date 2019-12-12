/*
get/set functions for Age Node Type file "ageNod.h"
*/
#include "ageNod.h"

using namespace std;

ageNod::ageNod()
{
	ageKey = "";
	under5 = "";
	under18 = "";
	over65 = "";
}

ageNod::ageNod(string a, string b, string c, string d)
{
	ageKey = a;
	under5 = b;
	under18 = c;
	over65 = d;
}

string ageNod::getAgeKey()
{
	return ageKey;
}

void ageNod::setAgeKey(string AgeKey)
{
	ageKey = AgeKey;
}

string ageNod::getUnder5()
{
	return under5;
}

void ageNod::setUnder5(string Under5)
{
	under5 = Under5;
}

string ageNod::getUnder18()
{
	return under18;
}

void ageNod::setUnder18(string Under18)
{	
	under18 = Under18;
}

string ageNod::getOver65()
{
	return over65;
}

void ageNod::setOver65(string Over65)
{
	over65 = Over65;
}
