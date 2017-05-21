#pragma once
#include "User.h"
#include <vector>
#include <string>

using std::vector;
class Users
{
private:
	bool IsUserExist(string name);
	vector <User> _userdatabase;
	const char* _filename = "db.dat";
public:
	bool SaveToFile();
	bool ReadFromFile();
	void SaveSample(string);
	void Display();
	void AddToUserDataBase();
	void RemoveFromUserDataBase();
	Users();
	~Users();
};

