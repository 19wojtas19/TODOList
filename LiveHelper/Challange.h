#pragma once
#include <iostream>
#include <string>

using namespace std;

class Challange
{
private:
	string _title;
	string _description;
	bool IsDone;

public:
	string GetTitle();
	string GetDescription();
	Challange(string, string);
	~Challange();
};

