#include "Admin.h"
Admin::Admin(std::string n) : User(n) {
	errors.push_back(std::pair<int,std::string>(errorSource::BANK,std::string("error on bank")));
	errors.push_back(std::pair<int,std::string>(errorSource::CLIENT,std::string("error on client")));
	errors.push_back(std::pair<int,std::string>(errorSource::ADMIN,std::string("error on admin")));
	//printErrors();
}

Admin::Admin() : User("adminName")
{
}

void Admin::printErrors()
{
	for (auto x : errors)
		std::cout << x.first << " - " << x.second<<std::endl;
}

bool Admin::clearErrors()
{
	//delete read file...
	errors.clear();
	return true;
}

bool Admin::changePassword(const std::string&)
{
	return false;
}
