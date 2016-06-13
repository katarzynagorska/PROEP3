/**
* \class BeautyStudio
*
* \brief Class representing BeautyStudio
*
* This class is representation of beauty studio. It it a health Care Unit
* that has beauticians and price for services.
*
* \note Thos class is part of the second PROE project.
*
*
*/

#pragma once
#include "healthcareunit.h"

class BeautyStudio : public HealthCareUnit
{
public:

	BeautyStudio();
	virtual ~BeautyStudio();


	///Method returning HCU info to string
	virtual string infoToStr();
	virtual string classType(){ return "beauty"; }

	void addBeautician(string b);


	void removeBeautician(string b);

	string beauticiansToStr();


	void setPrice(int price);

	///Function for printing service price to console
	void getPrice();


protected:
	vector<string> beautician;	///<list of workers
	int price;					///<service price
};

