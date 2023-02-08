#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
class Billing {
private:
	std::unordered_map<std::string, std::string> currencyNames;
protected:
	std::unordered_map<std::string, float> currencyValues;
public:
	void printBilling();
	Billing();
	float getCurrentCurrencyValue(const std::string& currencyTag);
	float showConversion(const std::string& currencyTagIn, const std::string& currencyTagOut, float value);
	bool convert(const std::string& currencyTagIn, const std::string& currencyTagOut, float value);
	bool saveMoneyToFile(const std::string& name);
	bool getMoneyFromFile(const std::string& name);
	bool keyExists(const std::string& currKey);
};