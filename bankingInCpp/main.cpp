#include <iostream>
#include <string>
#include "./UI/CaesarCipher.h"
#include "./users/User.h"
#include "./users/Client.h"
#include "./bank/Billing.h"
int main(int argc, char** argv)
{
	std::unique_ptr<User> usr(new Client());
	//std::cout << usr->checkPasswordFromFile(std::string("abcd123"));

	Billing bill = Billing();
}
