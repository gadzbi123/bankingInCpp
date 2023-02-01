#include <iostream>
#include <string>
#include "./UI/CaesarCipher.h"
#include "./users/User.h"
#include "./users/Client.h"
#include "./users/Admin.h"
#include "./bank/Billing.h"


int main(int argc, char** argv)
{
	//std::unique_ptr<User> usr = std::make_unique<Client>();
	//if( argc == 3)
		//usr = std::make_unique<Client>(argv[1],argv[2]);
	std::unique_ptr<User> usr = std::make_unique<Admin>("adaœ");
	usr->whoAmI();

	//Billing bill = Billing();
	//std::cout << bill.getMoneyFromFile("abc123");
}
