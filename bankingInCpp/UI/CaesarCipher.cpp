#include "CaesarCipher.h"

std::string CaesarCipher::encode(std::string& pass)
{
    std::string encoded_pass = std::string();
    encoded_pass.reserve(pass.size()+1);
    int SWITCH_VALUE = 26;
    for (int i = 0; i < pass.size(); i++) {
        char letter = (char)(pass[i] + this->key);
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
    //std::cout << encoded_pass << std::endl;
    return encoded_pass;
}

std::string CaesarCipher::decode(std::string&encoded_pass)
{
    std::string pass = std::string();
    pass.reserve(encoded_pass.size() + 1);
    int SWITCH_VALUE = 26;
    for (int i = 0; i < encoded_pass.size(); i++) {
        char letter = (char)(encoded_pass[i] - this->key);
        if (letter < 'A')
            letter += SWITCH_VALUE;
        if (letter < 'a' && encoded_pass[i] >= 'a')
            letter += SWITCH_VALUE;
        if (letter > 'Z' && encoded_pass[i] <= 'Z')
            letter -= SWITCH_VALUE;
        if (letter > 'z' && encoded_pass[i] <= 'z')
            letter -= SWITCH_VALUE;

        pass += letter;
    }
    //std::cout << pass << std::endl;
    return pass;
}
