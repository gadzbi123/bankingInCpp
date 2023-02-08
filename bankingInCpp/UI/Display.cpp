#include "Display.h"
void Display::eventLoop(std::shared_ptr<User>& user) {
	bool logged_in = false;

	helpLoggedOut();
	while (!logged_in) {
		logged_in = loginActions(user);
	}

	helpLoggedIn(user);
	while (logged_in) {
		loggedInActions(user);
	}
	//x = _getch();
	//std::cout << "*";
}

void Display::helpLoggedOut() {
	std::cout << "---BANKING APP---" << std::endl;
	std::cout << "1. Login\n";
	std::cout << "2. Create Account\n";
	std::cout << "0. Exit\n";
}

void Display::helpLoggedIn(const std::shared_ptr<User>& u)
{
	u->whoAmI();
	std::shared_ptr<Client> client = std::dynamic_pointer_cast<Client>(u);
	if (client != nullptr) {
		std::cout << "1. Show available currencies\n";
		std::cout << "2. Withdraw\n";
		std::cout << "3. Deposit\n";
		std::cout << "4. Invest\n";
		std::cout << "5. Change password\n";
		std::cout << "9. Logout\n";

	}

	std::shared_ptr<Admin> admin = std::dynamic_pointer_cast<Admin>(u);
	if (admin != nullptr) {
		std::cout << "1. Check Logs\n";
		std::cout << "2. Change Passwords\n";
		std::cout << "9. Logout\n";
	}

}

bool Display::loginActions(std::shared_ptr<User>& user) {
	char x;
	std::cin >> x;

	switch (x) {
	case '1':
		return login(user);
		break;
	case '2':
		return createAccount(user);
		break;
	case '0':
		exit(0);
	default: helpLoggedOut();
	}
}

bool Display::loggedInActions(std::shared_ptr<User>& user) {
	std::shared_ptr<Client> client = std::dynamic_pointer_cast<Client>(user);
	if (client != nullptr) {
		std::string currency;
		float value;
		char x;
		std::cin >> x;
		
		switch (x) {
		case '1':
			client.get()->printBilling();
			break;
		case '2':
			std::cout << "Insert currency and amount you want to withdraw:\n";
			std::cin >> currency >> value;
			client.get()->withdraw(currency, value);
			break;
		case '3':
			std::cout << "Insert currency and amount you want to deposit:\n";
			std::cin >> currency >> value;
			client.get()->deposit(currency, value);
		case '9':
			return logout(user);
			break;
		default: helpLoggedOut();
		}
	}

	std::shared_ptr<Admin> admin = std::dynamic_pointer_cast<Admin>(user);
	if (admin != nullptr) {
		//TODO admin actions
	}
}

bool Display::login(std::shared_ptr<User>& user) {
	std::string l, p;
	std::cout << "Login: ";
	std::cin >> l;
	std::cout << "Password: ";
	std::cin >> p;

	user = std::make_unique<User>(l);
	char role = user->checkPasswordFromFile(p);

	//std::cout << "role:" << role << "\n";

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
bool Display::createAccount(std::shared_ptr<User>&)
{
	return false;
}

bool Display::logout(std::shared_ptr<User>& user) {
	user = nullptr;
	return false;
}
