#include "Client.h"

bool Client::changePassword(const std::string& password)
{
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
