/**
* \class NailArtSaloon
*
* \brief Class representing Nail Art Saloon
*
* This class is representation of nail art saloon. It it a beauty studio
* that has special service list.
*
* \note Thos class is part of the second PROE project.
*
*/

#pragma once
#include "beautystudio.h"
#include <map>


using namespace std;
class NailArtSaloon : public BeautyStudio
{
public:
	///Constructor
	NailArtSaloon();
	///Destructor
	virtual ~NailArtSaloon();

	string infoToStr();
	string servicesToStr();
	void addService(string service, int price);


	void removeService(string service);


	///Method for updating mean price for all services
	void updateMeanPrice();




protected:
	map<string, int> service;	///<List of services
};

