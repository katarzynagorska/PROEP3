#include "nailartsaloon.h"
#include <iostream>
#include <sstream>

using namespace std;


NailArtSaloon::NailArtSaloon() : BeautyStudio()
{

}


NailArtSaloon::~NailArtSaloon()
{
}

string NailArtSaloon::infoToStr(){
	string s;
	s = "----Studio paznokci----\n";
	s += name + "\n";

	s += "\n";
	s += equipToStr();

	s += "\n";
	s += beauticiansToStr();

	s += "\n";
	s += servicesToStr();



	return s;
}

string NailArtSaloon::servicesToStr(){
	string s;
	stringstream ss;
	ss << "Cennik uslug: " << endl;

	map<string, int>::iterator it;
	it = service.begin();

	while (it != service.end())
	{
		ss << it->first << "\t - \t" << it->second << endl;
		it++;
	}

	ss << endl << "Srednia cena za zabieg wynosi: " << price;

	s = ss.str();
	return s;
}

void NailArtSaloon::addService(string service, int price)
{
	map<string, int>::iterator it;

	it = this->service.find(service);
	if (it != this->service.end())
		return;

	this->service.insert(pair<string, int>(service, price));
	updateMeanPrice();
}

void NailArtSaloon::removeService(string service)
{

	map<string, int>::iterator it;

	it = this->service.find(service);
	if (it != this->service.end())
		this->service.erase(it);

	updateMeanPrice();
}

void NailArtSaloon::updateMeanPrice()
{
	price = 0;

	if (service.size() > 0){
		map<string, int>::iterator it;
		it = service.begin();

		while (it != service.end()) {
			price += it->second;
			it++;
		}

		price /= service.size();
	}
}

void NailArtSaloon::clear(){
	BeautyStudio::clear();
	service.erase(service.begin(), service.end());
	updateMeanPrice();
}