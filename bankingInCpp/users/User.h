#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
class User {
	std::string name;
private:
	bool savePasswordToFile(std::string);
	bool putPasswordToFile(std::string);
public:
	User():name("xdd"){}
	std::string getName();
	bool setName(std::string&);
	bool changePassword(std::string);
};
