#pragma once
#include <iostream>
#include "../users/User.h"

//TODO delete
#include "../users/Client.h"
#include "../users/Admin.h"

class Display {
public:
	bool login(std::unique_ptr<User>&);
	bool createAccount(std::unique_ptr<User>&);
	void logout(std::unique_ptr<User>&);
	void options(std::unique_ptr<User>&);
	void help();
	void eventLoop(std::unique_ptr<User>&);

};