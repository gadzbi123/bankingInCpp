#include "Billing.h"

Billing::Billing()
{
	/*
	USD - US Dollar
		EUR - Euro
		JPY - Japanese Yen
		GBP - British Pound
		CHF - Swiss Franc
		AUD - Australian Dollar
		CAD - Canadian Dollar
		HKD - Hong Kong Dollar
		SGD - Singapore Dollar
		CNY - Chinese Yuan
		*/

	//currencies = {
	//	{"USD",{"US Dollar", 5}},
	//	{"JPY",{"Japanese Yen", 55}},
	//	{"GBP",{"British Pound", 15}},
	//	{"CHF",{"Swiss Franc", 52}},
	//	{"AUD",{"Australian Dollar", 75}},
	//	{"CAD",{"Canadian Dollar", 52}},
	//	{"CNY",{"Chinese Yuan", 51}}
	//};



	std::cout << currencies["USD"];
	for (auto x: currencies) {

		std::cout << x.first << " " << x.second.first <<" " << x.second.second << '\n';
	}
}
