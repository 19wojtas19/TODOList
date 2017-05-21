#include "User.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
User::User(string n, string p)
{
	_name = n;
	_password = p;
}


User::~User()
{

}

string User::getName()
{
	return _name;
}

string User::getPass()
{
	return _password;
}

void User::display()
{
	const char separator = ' ';
	const int nameWidth = 30;
	cout << left << setw(nameWidth) << setfill(separator) << getName();
	cout << left << setw(nameWidth) << setfill(separator) << getPass() << endl;
}
