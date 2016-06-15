/**
* \class Clinic
*
* \brief Class representing Clinic
*
* This class is representation of clinic. It is a Health Care Unit
* that stores patients data
*
*\note Thos class was the part of the first PROE project.
*
*/

#pragma once
#include"healthcareunit.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Clinic : public HealthCareUnit
{
public:
	///Constructs empty clinic
	Clinic();

	virtual ~Clinic();

	string patientsToStr();
	string infoToStr();
	string classType(){ return "clinic"; }

	void addPatient(string patient);
	void clear();

private:
	vector<string> patients; ///<patients list
};