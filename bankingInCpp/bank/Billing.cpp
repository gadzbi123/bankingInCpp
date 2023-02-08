#include "Billing.h"

Billing::Billing()
{
	//default billing values
	currencyValues = {
		{"USD",0},
		{"JPY",0},
		{"GBP",0},
		{"CHF",0},
		{"AUD",0},
		{"CAD",0},
		{"CNY",0},
		{"PLN",0},
		{"USD",0}
	};

	//basic currencies
	currencyNames = {
		{"USD","US Dollar"},
		{"JPY","Japanese Yen"},
		{"GBP","British Pound"},
		{"CHF","Swiss Franc"},
		{"AUD","Australian Dollar"},
		{"CAD","Canadian Dollar"},
		{"CNY","Chinese Yuan"},
		{"PLN","Polish Zloty"}
	};
}

bool Billing::saveMoneyToFile(const std::string& name) {
	std::string out;
	for (auto x : currencyValues) {
		out += (x.first + " " + std::to_string(x.second) + '\n');
	}

	std::ofstream file("../bankingInCpp/cash/" + name + ".txt");
	if (file.is_open()) {
		file << out;
		file.close();
		return true;
	}

	return false;
}

bool Billing::getMoneyFromFile(const std::string& name) {
	std::ifstream file("../bankingInCpp/cash/" + name + ".txt");
	std::string line;

	if (!file) {
		std::cout << "File for money doesn't exist\n";
		return false;
	}

	while (getline(file, line))
	{
		std::istringstream ss(line);
		std::string currencyName;
		float value;

		ss >> currencyName >> value;

		currencyValues[currencyName] = value;
	}
	//print();
	return true;
}

bool Billing::keyExists(const std::string& currKey)
{
	if (currencyNames.find(currKey) == currencyNames.end())
		return false;

	return true;
}

void Billing::printBilling() {
	for (auto x : currencyValues) {
		std::cout << x.first << "-" << currencyNames[x.first] << " " << x.second << '\n';
	}
}