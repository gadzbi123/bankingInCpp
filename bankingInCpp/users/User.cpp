#include "User.h"

bool User::putPasswordToFile(std::string password)
{
	std::ofstream file("../bankingInCpp/passwords.txt", std::ios_base::app);
	if (file.is_open()) {
		file << name << " " << password << "\n";
		file.close();
		return true;
	}

	return false;

}
bool User::savePasswordToFile(std::string password) {
	//check if user exists

	std::fstream file("../bankingInCpp/passwords.txt");
	std::string line, outString;

	while (getline(file, line))
	{
		std::istringstream ss(line);
		std::string someName, pass;

		ss >> someName >> pass;

		if (someName != name)
			outString += line + '\n';
		else
			outString += name + " " + password + '\n';
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

bool User::changePassword(std::string password) {
	// check size
	if (password.length() < 4)
		return false;


	bool hasDigit = false;
	bool hasLetter = false;
	for (int i = 0; i < password.length(); i++) {
		if (isdigit(password[i]))
			hasDigit = true;
		if (isalpha(password[i]))
			hasLetter = true;
	}

	if (!hasDigit || !hasLetter)
		return false;

	// check for presence of forbidden characters
	std::string forbiddenChars = "!@#$%^&*()";
	for (int i = 0; i < forbiddenChars.length(); i++) {
		if (password.find(forbiddenChars[i]) != std::string::npos) {
			return false;
		}
	}

	if (!savePasswordToFile(password))
		return false;

	return true;


}

