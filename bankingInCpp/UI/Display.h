#pragma once
#include <iostream>
#include <memory>
#include <conio.h>
#include "../users/User.h"

//TODO delete
#include "../users/Client.h"
#include "../users/Admin.h"

class Display {
	bool login(std::shared_ptr<User>&);
	bool createAccount(std::shared_ptr<User>&);
	bool logout(std::shared_ptr<User>&);
	void helpLoggedOut();
	void helpLoggedIn(const std::shared_ptr<User>&);

	bool loginActions(std::shared_ptr<User>& user);
	bool loggedAsClient(std::shared_ptr<User>& user);
	bool loggedAsAdmin(std::shared_ptr<User>& user);

	bool loggedInActions(std::shared_ptr<User>& user);
public:
	void eventLoop(std::shared_ptr<User>&);

};