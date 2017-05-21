#include "Challanges.h"



Challanges::Challanges()
{
}

void Challange::AddChallange()
{
	string title, description;
	bool success = false;
	cout << "Podaj tytul wyzwania: ";
	cin >> title;
	cout << endl << "Podaj opis: ";
	cin >> description;
	Challange new_challange(title, description);
	_challangedatabase
}

Challanges::~Challanges()
{
}
