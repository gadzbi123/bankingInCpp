#include "Display.h"
void Display::eventLoop(std::unique_ptr<User>& user) {
	bool logged_in = false;
	char x;

	help();
	while (!logged_in) {
		std::cin >> x;
		switch (x) {
		case '1':
			logged_in = login(user);
		case '2':
			logged_in = createAccount(user);
		case '0':
			exit(0);
		default: help();
		}
	}
	user->whoAmI();
}

void Display::help() {
	std::cout << "---BANKING APP---" << std::endl;
	std::cout << "1. Login\n";
	std::cout << "2. Create Account\n";
	std::cout << "0. Exit\n";
}

bool Display::login(std::unique_ptr<User>& user) {
	std::string l, p;
	std::cout << "Login: ";
	std::cin >> l;
	std::cout << "Password: ";
	std::cin >> p;

	user = std::make_unique<User>(l);
	char role = user->checkPasswordFromFile(p);

	std::cout << "role:" << role << "\n";

	if (role == '\0') {
		//throw "User doesn't exist\n";
		std::cout << "User doesn't exist\n";
		user = nullptr;
		return false;
	}

	if (role == 'c')
		user = std::make_unique<Client>(l);

	if (role == 'a')
		user = std::make_unique<Admin>(l);

	return true;

}
bool Display::createAccount(std::unique_ptr<User>&)
{
	return false;
}

void Display::logout(std::unique_ptr<User>& user) {
	user = nullptr;
}
