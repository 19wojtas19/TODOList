#include "Users.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include "User.h"
#include "md5.h"
#include <fstream>
Users::Users()
{
}

Users::~Users()
{
}

void Users::addUser()
{
	string name, password;

	bool success = false;
	while (!success)
	{
		system("cls");
		cout << "User Name: ";
		cin >> name;
		cout << "Password: ";
		cin >> password;
		if (!isUserExist(name))
		{
			success = true;
			User new_user(name, md5(password));
			_user_db.push_back(new_user);
			system("cls");
			cout << "User added" << endl;
		}
	}
}

void Users::removeUser()
{
	string password, n;

	if (!isUserExist(n))
	{
		system("cls");
		cout << "User " << n << " doesn't exist" << endl;
		return;
	}

	system("cls");
	cout << "Password: ";
	cin >> password;

	for (int i = 0; i < _user_db.size(); i++)
	{
		if (_user_db[i].getName() == n && _user_db[i].getPass() == md5(password))
			_user_db.erase(_user_db.begin() + i);
	}
}

bool Users::isUserExist(string n)
{
	for (int i = 0; i < _user_db.size(); i++)
	{
		if (n == _user_db[i].getName())
			return true;
	}
	return false;
}

void Users::display()
{
	for (int i = 0; i < _user_db.size(); i++)
	{
		_user_db[i].display();
	}
}

bool Users::saveToFile()
{
	fstream file(_filename, ios::out);

	if (!file)
	{
		cout << "can not open the file" << endl;
		return false;
	}

	for (int i = 0; i < _user_db.size(); i++)
	{
		file << _user_db[i].getName() << ";"
			<< _user_db[i].getPass() << "\n";
	}

	file.close();
	file.clear();
	return true;
}

void Users::saveSample(string sample)
{
	string name = "", pass = "";
	bool first = true;
	for (int i = 0; i < sample.size(); i++)
	{
		if (sample[i] == ';')
		{
			first = false;
			continue;
		}

		if (sample[i] == '\n')
			continue;

		if (first)
			name += sample[i];
		else
			pass += sample[i];
	}

	User user_from_file(name, pass);
	/*for (int i = 0; i < _user_db.size(); i++)
	{
		if (isUserExist(_user_db[i].getName()))
		{
			cout << "name unique error" << endl;
			return;
		}
	}*/
	_user_db.push_back(user_from_file);
}

bool Users::readFromFile()
{
	fstream file(_filename, ios::in);
	if (!file)
	{
		cout << "can not open the file" << endl;
		return false;
	}

	string data_sample;

	while (file >> data_sample)
	{
		saveSample(data_sample);
	}
}
