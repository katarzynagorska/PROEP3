#pragma once
#include "mylist.h"
#include "healthcareunit.h"
#include "NailArtSaloon.h"
#include "Clinic.h"
#include "beautystudio.h"

class AppModel{

public:
	AppModel(){};
	~AppModel(){};

	void addObject(HealthCareUnit &h);

	HealthCareUnit& getObject(int i);

	void setname(int i, string name);

	///Returns true if name and address are set
	bool clinicIsReady();

	///Returns true if name and address are set
	bool beautyIsReady();

	///Returns true if name and address are set
	bool nailsIsReady();

	//Getters
	Clinic& getClinic();// {return this->clinic; }
	BeautyStudio& getBeauty();// {return this->beauty; }
	NailArtSaloon& getNails();// {return this->nails; }
	HealthCareUnit& getHCU(){ return *hcu; }

	myList<HealthCareUnit*> list;
private:

	HealthCareUnit* hcu;
	Clinic clinic;
	BeautyStudio beauty;
	NailArtSaloon nails;

};