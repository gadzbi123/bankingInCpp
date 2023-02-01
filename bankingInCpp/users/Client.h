#pragma once
#include "User.h"
#include "../bank/Billing.h"
class Client : public User, public Billing {
public:
	virtual void whoAmI() { std::cout << "CLIENT" << name<<"\n"; }
	Client(std::string n);
	Client();

	bool withdraw(const std::string& currencyTag, float value);
	bool deposit(const std::string& currencyTag, float value);
	bool invest(const std::string& currencyTag, float value, int time_days, float procentage);
	bool requestLoan(const std::string& currencyTag, float value, float procentage);
	bool changePassword(const std::string&);
};