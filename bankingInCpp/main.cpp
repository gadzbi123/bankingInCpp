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

    int key = -1;
    std::string pass = "BCDbcd"; //check pass eariler
    std::string encoded_pass = std::string();
    encoded_pass.reserve(4);
    int SWITCH_VALUE = 26;
    for (int i = 0; i < pass.size(); i++) {
        char letter = (char)(pass[i] + key);
        if (letter < 'A')
            letter += SWITCH_VALUE;
        if (letter < 'a' && pass[i] >= 'a')
            letter += SWITCH_VALUE;
        if (letter > 'Z' && pass[i] <= 'Z')
            letter -= SWITCH_VALUE;
        if (letter > 'z' && pass[i] <= 'z')
            letter -= SWITCH_VALUE; 

        encoded_pass += letter;
    }
    std::cout << encoded_pass << std::endl;
}
