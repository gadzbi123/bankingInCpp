#pragma once
#include <iostream>
#include <unordered_map>
class Billing {
private:
	std::unordered_map<std::string, std::string> currenciesNames;
protected:
	std::unordered_map<std::string, int> currencies;
public:
	Billing();
	bool exchangeCurrency(const std::string& currencyTag, float value);
	float getCurrentCurrencyValue(const std::string& currencyTag);
	float showConversion(const std::string& currencyTagIn, const std::string& currencyTagOut, float value);
	bool convert(const std::string& currencyTagIn, const std::string& currencyTagOut, float value);
};