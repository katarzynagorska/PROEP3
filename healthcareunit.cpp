#include "healthcareunit.h"
#include <iostream>
#include <algorithm>
using namespace std;

HealthCareUnit::HealthCareUnit()
{
	name = "";
}


HealthCareUnit::~HealthCareUnit()
{
}

string HealthCareUnit::equipToStr(){
	string s;
	s = "Wyposazenie obiektu:\n";
	for (int i = 0; i <int(equipment.size()); i++)
		s += "- " + equipment[i] + "\n";
	return s;
}

void HealthCareUnit::addEquipment(string e)
{

	vector<string>::iterator it;

	it = find(equipment.begin(), equipment.end(), e);
	if (it != equipment.end())
		return;
	else
		equipment.push_back(e);
}

void HealthCareUnit::removeEquipment(string eq)
{
	int idx = -1;
	for (int i = 0; i < int(equipment.size()); i++)
	if (equipment[i] == eq)
		idx = i;
	if (idx >= 0)
		equipment.erase(equipment.begin() + idx);
}

void HealthCareUnit::setName(string s)
{
	name = s;
}
void HealthCareUnit::setImage(string filepath){
	//TODO setting image
}

void HealthCareUnit::clear(){
	equipment.erase(equipment.begin(), equipment.end());
}