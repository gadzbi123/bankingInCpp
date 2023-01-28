#include <iostream>
#include <string>
#include "./UI/CaesarCipher.h"
#include "./users/User.h"
int main(int argc, char**argv)
{
	User usr = User();
	std::cout<< usr.changePassword(std::string("abcd123"));
	//CaesarCipher cipher = CaesarCipher();
	//std::string code = "BCDbcd";
	//std::cout<< cipher.decode(code);

}
