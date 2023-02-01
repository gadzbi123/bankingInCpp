#pragma once

#include "User.h"
#include <vector>
class Admin : public User {
	enum errorSource{BANK, CLIENT, ADMIN};
	std::vector<std::pair<int,std::string>> errors;
public:
	virtual void whoAmI() { std::cout << "ADMIN" << name << "\n"; }
	Admin(std::string n);
	Admin();

	void showLastErrorsFromClients();
	void showLastErrorsFromBank();
	void printErrors();
	bool clearErrors();
	bool changePassword(const std::string&);
	bool addAdmin();
	bool removeAdmin();
};