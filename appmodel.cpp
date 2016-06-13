#include "appmodel.h"
#include <QString>
#include <qmessagebox.h>

void AppModel::addObject(HealthCareUnit &h){
	list.push_back(&h);
}

HealthCareUnit& AppModel::getObject(int i){
	return *list[i];
}

void AppModel::setname(int i, string name){
	list[i]->setName(name);
}

///Returns true if name and address are set
bool AppModel::clinicIsReady(){
	bool not_ready = (clinic.getName() == "");
	if (not_ready)
		throw new QString("Wypelnij pola adresu i nazwy");
	return !not_ready;
}

///Returns true if name and address are set
bool AppModel::beautyIsReady(){
	bool not_ready = (beauty.getName() == "");
	if (not_ready)
		throw new QString("Wypelnij pola adresu i nazwy");
	return !not_ready;
}

///Returns true if name and address are set
bool AppModel::nailsIsReady(){
	bool not_ready = (nails.getName() == "");
	if (not_ready)
		throw new QString("Wypelnij pola adresu i nazwy");
	return !not_ready;
}

//Getters
Clinic& AppModel::getClinic(){ return this->clinic; }
BeautyStudio& AppModel::getBeauty(){ return this->beauty; }
NailArtSaloon& AppModel::getNails(){ return this->nails; }