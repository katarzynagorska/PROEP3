#pragma once
#include "mylist.h"
#include "healthcareunit.h"
#include "NailArtSaloon.h"
#include "Clinic.h"
#include "beautystudio.h"

enum HCUType{
	CLINIC,
	BEAUTY,
	NAILS,
};


class AppModel{

public:
	AppModel(){};
	~AppModel(){};

	void addObject(HealthCareUnit &h);
	
	void addNewObject(string name, HCUType type);
	

	HealthCareUnit& getObject(int i);
	HealthCareUnit& findObject(string name);

	void setObjectName(int i, string name);

	//Getters
	Clinic& getClinic();
	BeautyStudio& getBeauty();
	NailArtSaloon& getNails();
	HealthCareUnit& getHCU(){ return *hcu; }
	//Setters
	void setHCU(HealthCareUnit &h);
	

	HealthCareUnit* hcu;
	myList<HealthCareUnit*> list;
private:

	
	Clinic clinic;
	BeautyStudio beauty;
	NailArtSaloon nails;

};