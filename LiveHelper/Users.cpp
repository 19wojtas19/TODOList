#include "Users.h"
#include "User.h"
#include <cstdlib>
#include <iostream>
#include "md5.h"
#include <fstream>

using namespace std;

Users::Users()
{
	
}

void Users::AddToUserDataBase() 
{
	string name, password;
	bool success = false;
	while (!success)
	{
		system("cls");
		cout << "Podaj Nazwe uzytkownika: ";
		cin >> name;
		cout << endl<< "Podaj swoje haslo: ";
		cin >> password;
		cout << endl;
		if (!IsUserExist(name))
		{
			success = true;
			User new_user(name, md5(password));
			_userdatabase.push_back(new_user);
			cout << "User Added" << endl;
		}
	}
}

void Users::RemoveFromUserDataBase()
{
	string name, password;
	bool success = false;
	cout << "Podaj nazwe konta ktore chcesz usunac: ";
	cin >> name;
	if (IsUserExist(name))
	{
		cout << "Podaj haslo" << endl;
		cin >> password;
		for (int i = 0; i < _userdatabase.size(); i++)
		{
			if (_userdatabase[i].GetName() == name || _userdatabase[i].GetPassword() == md5(password))
			{
				_userdatabase.erase(_userdatabase.begin() + i);
				break;
			}
		}
	}
	
}

bool Users::IsUserExist(string name)
{
	for (int i = 0; i < _userdatabase.size(); i++)
	{
		if (_userdatabase[i].GetName() == name)
		{
			return true;
		}
	}
	return false;
}

void Users::Display()
{
	for (int i = 0; i < _userdatabase.size(); i++)
	{
		_userdatabase[i].Display();
	}
}

bool Users::SaveToFile()
{
	fstream file;
	file.open(_filename, ios::out);

	if (!file)
	{
		cout << "Nie udalo sie otworzyc pliku!";
		return 0;
	}

	for (int i = 0; i < _userdatabase.size(); i++)
	{
		file << _userdatabase[i].GetName() << ";";
		file << _userdatabase[i].GetPassword() << "\n";
		
	}
	file.close();
	file.clear();
	return 1;
}

bool Users::ReadFromFile()
{
	fstream file;
	file.open(_filename, ios::in);
	if (!file)
	{
		cout << "zjebao sie :(";
		return 0;
	}
	string data_sample;
	while (file >> data_sample)
	{
		SaveSample(data_sample);
	}
	return 1;

}

void Users::SaveSample(string data_sample)
{
	string name ="", password = "";
	bool first = true;
	for (int i = 0; i < data_sample.size(); i++)
	{
		if (data_sample[i] == ';')
		{
			first = false;
			continue;
		}
		if (first)
		{
			name += data_sample[i];
		}
		else
		{
			password += data_sample[i];
		}
	}
	User new_user(name, password);
	/*for (int i = 0; i < _userdatabase.size(); i++)
	{
		if (IsUserExist(new_user.GetName()))
		{
			cout << "Istnieje juz uzytkownik o takiej nazwie" << endl;
			return;
		}
	}*/
	_userdatabase.push_back(new_user);
}

Users::~Users()
{
}
