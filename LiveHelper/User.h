#pragma once
#include "Challange.h"
#include <string>

using std::string;

class User
{
	private:
		string _name;
		string _password;
		vector <Challange> _challagnedatabase;
	public:
		void Display();
		string GetPassword();
		string GetName();
		User(string, string);
		~User();
};

