#include"clinic.h"

#include <string>
#include <iostream>
#include <vector>

#include <sstream>




//Konstruktor 
Clinic::Clinic() : HealthCareUnit()
{

}

//Destruktor
Clinic::~Clinic()
{

}

string Clinic::patientsToStr(){
	stringstream ss;
	ss << endl << "PACJENCI: " << endl;
	for (int i = 0; i < int(patients.size()); i++)
		ss << patients[i] << endl;

	return ss.str();
}
string Clinic::infoToStr(){
	stringstream ss;
	ss << "----Przychodnia----" << endl;
	ss << name << endl;

	ss << equipToStr() << endl;

	ss << patientsToStr() << endl << endl;


	return ss.str();
}

void Clinic::addPatient(string _patient){
	patients.push_back(_patient);
}