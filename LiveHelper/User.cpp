#include "User.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

User::User(string name, string password)
{
	_name = name;
	_password = password;
}

string User::GetName()
{
	return _name;
}

void User::Display()
{
	const char separator = ' ';
	const int nameWidth = 30;
	cout << left << setw(nameWidth) << setfill(separator) << GetName()
		<< setw(nameWidth) << setfill(separator) << GetPassword() << endl;
}

string User::GetPassword()
{
	return _password;
}

User::~User()
{
}
