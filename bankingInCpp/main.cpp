#include <iostream>
#include <string>
#include "./UI/CaesarCipher.h"
#include "./users/User.h"
#include "./users/Client.h"
#include "./users/Admin.h"
#include "./bank/Billing.h"
#include "UI/Display.h"
int main(int argc, char** argv)
{
	//std::unique_ptr<User> usr = std::make_unique<Admin>("adas");
	//usr->whoAmI();
	std::unique_ptr<User> user;
	Display dsp;
	dsp.eventLoop(user);

}

