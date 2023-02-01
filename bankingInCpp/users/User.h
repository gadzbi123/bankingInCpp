#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
class User {
protected:
	std::string name;
	bool savePasswordToFile(const std::string&);
	bool putPasswordToFile(const std::string&);

public:
	virtual void whoAmI() { std::cout << "USER\n"; }
	User():name("xdd"){}
	User(std::string n):name(n){
	//if user exists = check pass from file
	//if not exists = put pass to file 
	}
	std::string getName();
	bool setName(std::string&);
	virtual bool changePassword(const std::string&);
	bool checkPasswordFromFile(const std::string&);
};
