#include "User.h"

char User::checkPasswordFromFile(const std::string& password) {
	std::ifstream file("../bankingInCpp/passwords.txt");
	std::string line;

	while (getline(file, line))
	{
		std::istringstream ss(line);
		std::string n, p;
		char role;

		ss >> role >> n >> p;

		std::cout << (n == name) << " " << (p == password) << "\n";
		
			if (n == name && p == password)
			{
				return role=='a' ? 'a' : 'c';
			}
		
	}
	return '\0';
}

bool User::putPasswordToFile(const char& role,const std::string& password)
{
	std::ofstream file("../bankingInCpp/passwords.txt", std::ios_base::app);
	if (file.is_open()) {
		file <<role << " " << name << " " << password << "\n";
		file.close();
		return true;
	}
	return false;
}

bool User::savePasswordToFile(const std::string& password) {
	//check if user exists

	std::fstream file("../bankingInCpp/passwords.txt");
	std::string line, outString;

	while (getline(file, line))
	{
		std::istringstream ss(line);
		std::string n, p;
		char role;

		ss >>role >> n >> p;

		if (n != name)
			outString += line + '\n';
		else
			outString += role + " " + name + " " + password + '\n';
	}

	//start from the begining
	file.clear();
	file.seekg(0);

	if (file.is_open()) {
		file << outString;
		file.close();
		return true;
	}

	return false;
}


std::string User::getName()
{
	return name;
}

bool User::setName(std::string& n) {
	if (n.size() > 3)
		return false;

	name = n;
	return true;
}

bool User::changePassword(const std::string& password) {
	std::cout << "Use change password on admin or client" << std::endl;
	return false;
}

