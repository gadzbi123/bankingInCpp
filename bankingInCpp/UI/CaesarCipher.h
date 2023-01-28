#ifndef CaesarCipher_H
#define CaesarCipher_H
#include <iostream>
#include <string>
class CaesarCipher {
	short key = 5;
public:
	std::string encode(std::string&);
	std::string decode(std::string&);
};

#endif