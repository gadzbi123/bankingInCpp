#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
class User {
	std::string name;
protected:
	bool savePasswordToFile(const std::string&);
	bool putPasswordToFile(const std::string&);
public:
	User():name("xdd"){}
	User(std::string n):name(n){
	//if user exists = check pass in file
	//if not exists = put pass to file 
	}
	std::string getName();
	bool setName(std::string&);
	virtual bool changePassword(const std::string&);
	bool checkPasswordFromFile(const std::string&);
};
