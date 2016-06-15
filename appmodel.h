#pragma once
#include "mylist.h"
#include "healthcareunit.h"
#include "NailArtSaloon.h"
#include "Clinic.h"
#include "beautystudio.h"

enum HCUType{
	CLINIC,
	NAILS,
	BEAUTY,
};


class AppModel{

public:
	AppModel(){};
	~AppModel(){};

	void addObject(HealthCareUnit &h);
	
	void addNewObject(string name, HCUType type);
	

	HealthCareUnit& getObject(int i);

	void setObjectName(int i, string name);

	//Getters
	Clinic& getClinic();// {return this->clinic; }
	BeautyStudio& getBeauty();// {return this->beauty; }
	NailArtSaloon& getNails();// {return this->nails; }
	HealthCareUnit& getHCU(){ return *hcu; }

	HealthCareUnit* hcu;


	myList<HealthCareUnit*> list;
private:

	
	Clinic clinic;
	BeautyStudio beauty;
	NailArtSaloon nails;

};