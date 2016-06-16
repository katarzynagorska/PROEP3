#include "appmodel.h"
#include <QString>
#include <qmessagebox.h>

void AppModel::addObject(HealthCareUnit &h){
	list.push_back(&h);
}

void AppModel::addNewObject(string name, HCUType type){
	
	//Initialization before switch statement, errors otherwise
	Clinic *newC; 
	BeautyStudio *newB;
	NailArtSaloon *newN;

	switch (type)
	{
	case CLINIC:
		newC = new Clinic();
		clinic.clear();
		clinic.setName(name);
		*newC = clinic;
		addObject(*newC);
		
		break;
	
	case BEAUTY:
		newB = new BeautyStudio();
		beauty.clear();
		beauty.setName(name);
		*newB = beauty;
		addObject(*newB);
		
		break;

	case NAILS:
		newN = new NailArtSaloon();
		nails.clear();
		nails.setName(name);
		*newN = nails;
		addObject(*newN);
		
		break;
	
	default:
		return;
	}

	
}

HealthCareUnit& AppModel::getObject(int i){
	return *list[i];
}
HealthCareUnit& AppModel::findObject(string name){
	
	for (int i = 0; i < list.size(); i++)
	{
		if (list.at(i)->getName() == name)
			return *list.at(i);
	}
	//TODO insert return statement here
}

void AppModel::setObjectName(int i, string name){
	list[i]->setName(name);
}

//Getters
Clinic& AppModel::getClinic(){ return this->clinic; }
BeautyStudio& AppModel::getBeauty(){ return this->beauty; }
NailArtSaloon& AppModel::getNails(){ return this->nails; }

void AppModel::setHCU(HealthCareUnit &h){
	*hcu = h;
}