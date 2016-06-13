#include "beautystudio.h"

#include <iostream>
#include <algorithm>


BeautyStudio::BeautyStudio() : HealthCareUnit()
{
	price = 0;
}


BeautyStudio::~BeautyStudio()
{
}


//TODO
string BeautyStudio::infoToStr(){

	string s;
	s = "----Salon pieknosci----\n";
	s += name + "\n";
	s += "Cena zabiegu: " + to_string(price);
	s += "\n\n";
	s += equipToStr();
	s += "\n\n";
	s += beauticiansToStr();

	return s;
}
//TODO
string BeautyStudio::beauticiansToStr(){
	string s;
	s = "Kosmetyczki pracujace w salonie:\n";
	for (string &b : beautician)// (int i = 0; i < int(beautician.size()); i++)
		s += b + "\n";
	return s;
}

void BeautyStudio::addBeautician(string b)
{
	vector<string>::iterator it;

	it = find(beautician.begin(), beautician.end(), b);
	if (it != beautician.end())
		return;
	else
		beautician.push_back(b);
}

void BeautyStudio::removeBeautician(string b)
{
	vector<string>::iterator it;

	it = find(beautician.begin(), beautician.end(), b);
	if (it != beautician.end())
		beautician.erase(it);
}

void BeautyStudio::setPrice(int price)
{
	this->price = price;
}

void BeautyStudio::getPrice()
{
	cout << "Srednia cena ze uslugi: " << price << endl;
}