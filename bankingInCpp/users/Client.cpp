#include "Client.h"

Client::Client() :User("clientName") {
	if (!Billing::getMoneyFromFile(name)) {
		Billing::saveMoneyToFile(name);
		std::cout << "Loaded default values\n";
	}
}

Client::Client(std::string n) : User(n) {
	if (!Billing::getMoneyFromFile(name)) {
		Billing::saveMoneyToFile(name);
		std::cout << "Loaded default values\n";
	}
}

bool Client::withdraw(const std::string& currencyTag, float value) {
	if (!Billing::keyExists(currencyTag))
		return false;
	if (currencyValues[currencyTag] < value)
		return false;

	currencyValues[currencyTag] -= value;
	return true;
}

bool Client::deposit(const std::string& currencyTag, float value) {
	if (!Billing::keyExists(currencyTag))
		return false;

	currencyValues[currencyTag] += value;
	return true;
}

bool Client::changePassword(const std::string& password) {
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
