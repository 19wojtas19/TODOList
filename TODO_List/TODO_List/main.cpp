#include <iostream>
#include <cstdlib>
#include "Users.h"
using namespace std;

int main()
{
	Users users;
	users.readFromFile();
	users.display();
	//chujcuhjchuj
	system("pause");
	return 0;
}
