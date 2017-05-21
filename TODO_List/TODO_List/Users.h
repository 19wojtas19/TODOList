#pragma once
#include "User.h"
#include <vector>
#include <string>

using namespace std;
class Users
{
public:
	Users();
	~Users();
	void addUser();
	void removeUser();
	void display();
	bool saveToFile();
	bool readFromFile();
	void saveSample(string);
private:
	const char* _filename = "db.dat";
	vector<User> _user_db;
	bool isUserExist(string);
};

