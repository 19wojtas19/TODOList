#include <iostream>
#include "Users.h"
#include <cstdlib>

using namespace std;



int main()
{
	Users chujec;
	//chujec.AddToUserDataBase();
	//chujec.AddToUserDataBase();
	chujec.ReadFromFile();
	chujec.Display();
	//chujec.SaveToFile();

	system("PAUSE");

	return 0;
}
