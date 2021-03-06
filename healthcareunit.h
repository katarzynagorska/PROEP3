/**
* \class HealthCareUnit
*
* \brief Class representing abstract Health Care Unit
*
* This class is representation of health care unit It it an abstract class.
*
* \note Thos class is part of the second PROE project.
*
*
*/

#pragma once
#include <string>
#include <vector>
#include <qimage.h>

using namespace std;

class HealthCareUnit
{
public:

	HealthCareUnit();

	virtual ~HealthCareUnit();

	virtual string classType()=0;
	virtual string infoToStr() = 0;
	virtual void clear();

	string equipToStr();


	void addEquipment(string s);

	void removeEquipment(string eq);


	void setName(string s);

	string getName(){ return name; };

	QImage getImage(){ return image; }
	void setImage(string filepath);

protected:
	QImage image;
	string name;				///<Name
	vector <string>equipment;	///<List of equipment
};

