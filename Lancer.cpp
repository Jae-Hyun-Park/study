#include "Lancer.h"



Lancer::Lancer(const char* jobname)
{
	name = new char[1];
	cout << "name = ";
	cin >> name;
	job = new char[strlen(jobname) + 1];
	strcpy(job, jobname);
	hpmax = 45;
	hp = hpmax;
	mpmax = 20;
	mp = mpmax;
	atkback = 17;
	atk = atkback;
	def = 7;
	range = 2;
}


Lancer::~Lancer()
{
	delete(name);
}
