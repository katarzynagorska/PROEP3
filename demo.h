
#include "beautystudio.h"
#include"clinic.h"
#include "nailartsaloon.h"
#include<ctime>

Clinic szaserow;
Clinic banacha;
Clinic woloska;

NailArtSaloon pazur;
NailArtSaloon manicureexpress;

BeautyStudio piekna;

void setUpDemos(){
	srand(time(NULL));

	//Names
	szaserow.setName("Szaserow");
	banacha.setName("Banacha");
	woloska.setName("Woloska");

	pazur.setName("Pazur");
	manicureexpress.setName("Manicure Express");

	piekna.setName("Piekna");

	//Images
	szaserow.setImage("C:/Users/Katarzyna/Dropbox/Magisterskie/16L/PROE/ListAndGui/Project3/Project3/Resources/Images/szas.jpg");
	banacha.setImage("C:/Users/Katarzyna/Dropbox/Magisterskie/16L/PROE/ListAndGui/Project3/Project3/Resources/Images/banacha.jpg");
	woloska.setImage("C:/Users/Katarzyna/Dropbox/Magisterskie/16L/PROE/ListAndGui/Project3/Project3/Resources/Images/woloska.jpg");
	pazur.setImage("C:/Users/Katarzyna/Dropbox/Magisterskie/16L/PROE/ListAndGui/Project3/Project3/Resources/Images/nails.jpg");
	manicureexpress.setImage("C:/Users/Katarzyna/Dropbox/Magisterskie/16L/PROE/ListAndGui/Project3/Project3/Resources/Images/pikachunails.jpg");
	piekna.setImage("C:/Users/Katarzyna/Dropbox/Magisterskie/16L/PROE/ListAndGui/Project3/Project3/Resources/Images/emma.jpg");

	//Patients
	vector <string> p = { "Maja", "Kuba", "Maciek" };
	for (string &s : p)
		szaserow.addPatient(s);

	p = { "Zosia", "Janusz", "Hubert", "Marian" };
	for (string &s : p)
		banacha.addPatient(s);

	p = { "Wojtek", "Wanda" };
	for (string &s : p)
		woloska.addPatient(s);

	//Equipment
	p = { "CT", "PET", "SPECT" };
	for (string &s : p)
		szaserow.addEquipment(s);

	p = { "MRI", "RTG" };
	for (string &s : p)
		banacha.addEquipment(s);

	p = { "PET+CT", "fMRI", "Gammakamera" };
	for (string &s : p)
		woloska.addEquipment(s);

	//Workers
	p = { "Asia", "Basia", "Gosia" };
	for (string &s : p)
		pazur.addBeautician(s);

	p = { "Magda", "Ewa" };
	for (string &s : p)
		manicureexpress.addBeautician(s);

	p = { "Krysia", "Gosia", "Andzelika" };
	for (string &s : p)
		piekna.addBeautician(s);

	//Equipment
	p = { "Lampa UV", "Lakiery hybrydowe" };
	for (string &s : p)
		pazur.addEquipment(s);

	p = { "Pilniczki", "Krem do rak", "Nozyczki" };
	for (string &s : p)
		manicureexpress.addEquipment(s);

	p = { "Fotele fryzjerskie", "Lozko do masazu", "Lustra" };
	for (string &s : p)
		piekna.addEquipment(s);

	//Price
	piekna.setPrice(150);

	//Services
	p = { "Manicure hybrydowy", "Manicure naturalny", "French manicure" };
	for (string &s : p)
		pazur.addService(s, 50 + (rand()%5)*10);	
	

	p = { "Water Marble Nails", "Holographic Nails", "Nail Vinyls Design" };
	for (string &s : p)
		manicureexpress.addService(s, (rand() % 4) * 50 + 25);
}