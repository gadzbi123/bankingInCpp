#include <iostream>
#include <string>
#include "./UI/CaesarCipher.h"
#include "./users/User.h"
#include "./users/Client.h"
#include "./bank/Billing.h"


int main(int argc, char** argv)
{
	std::unique_ptr<User> usr = std::make_unique<Client>();
	if( argc == 3)
		usr = 
	usr->whoAmI();

	//Billing bill = Billing();
	//std::cout << bill.getMoneyFromFile("abc123");
}
