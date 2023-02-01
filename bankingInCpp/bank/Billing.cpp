#include "Billing.h"

Billing::Billing()
{
	//currencies = {
	//	{"USD",{"US Dollar", 5}},
	//	{"JPY",{"Japanese Yen", 55}},
	//	{"GBP",{"British Pound", 15}},
	//	{"CHF",{"Swiss Franc", 52}},
	//	{"AUD",{"Australian Dollar", 75}},
	//	{"CAD",{"Canadian Dollar", 52}},
	//	{"CNY",{"Chinese Yuan", 51}}
	//};

	currValues = {
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

	currNames = {
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
	for (auto x : currValues) {
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
		std::cout << "BADFILE\n";
		return false;
	}

	while (getline(file, line))
	{
		std::istringstream ss(line);
		std::string cn;
		float v;

		ss >> cn >> v;

		currValues[cn] = v;
	}
	print();
	return true;
}

bool Billing::keyExists(const std::string& currKey)
{
	if (currNames.find(currKey) == currNames.end())
		return false;

	return true;
}

void Billing::print() {
	for (auto x : currValues) {
		std::cout << x.first << "-" << currNames[x.first] << " " << x.second << '\n';
	}
}