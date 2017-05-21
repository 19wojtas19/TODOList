#pragma once
#include <string>

using std::string;

class User
{
public:
	User(string, string);
	~User();
	string getName();
	string getPass();
	void display();

private:
	string _name;
	string _password;
};

