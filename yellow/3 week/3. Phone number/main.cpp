#include <bits/stdc++.h>
#include "phone_number.h"

using namespace std;

void print(const PhoneNumber& pn) {
	cout << pn.GetCountryCode() << endl;
	cout << pn.GetCityCode() << endl;
	cout << pn.GetLocalNumber() << endl;
	cout << pn.GetInternationalNumber() << endl;
}

int main() {
	try {
		PhoneNumber pn0(PhoneNumber("+7-495-111-22-33"));
		print(pn0);
		PhoneNumber pn1(PhoneNumber("+7-495-1112233"));
		print(pn1);
		PhoneNumber pn2(PhoneNumber("+323-22-460002"));
		print(pn2);
		PhoneNumber pn3(PhoneNumber("+1-2-coursera-cpp"));
		print(pn3);

		PhoneNumber pn4(PhoneNumber("1-2-333"));
		print(pn4);
		PhoneNumber pn5(PhoneNumber("+7-1233"));
		print(pn5);
		
	} catch(const exception& ex) {
		cout << ex.what() << endl;
	}
	
	return 0;
}