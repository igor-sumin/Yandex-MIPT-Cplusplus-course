#include <iostream>
#include <sstream>
#include <iomanip>

#include "phone_number.h"

using namespace std;

string PhoneNumber::GetCountryCode() const {
	return country_code_;
}

string PhoneNumber::GetCityCode() const {
	return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
	return ("+" + country_code_ + "-" + city_code_ + "-" + local_number_);
}

PhoneNumber::PhoneNumberMy(const string &international_number) {
	istringstream ss(international_number);
	bool ok = true;

	char plus;
	ok = ok && (ss >> plus);
	if(plus != '+')
		ok = false;

	int x;
	ok = ok && (ss >> x);
	ok = ok && (ss.peek() == '-');
	ss.ignore(1);
	
	int y;
	ok = ok && (ss >> y);
	ok = ok && (ss.peek() == '-');
	ss.ignore(1);

	string z;
	ok = ok && (ss >> z);
	ok = ok && ss.eof();

	if (!ok) {
		throw invalid_argument("Invalid date format: " + international_number);
	}

	country_code_ = to_string(x);
	city_code_ = to_string(y);
	local_number_ = z;
}

PhoneNumber::PhoneNumber(const string& international_number) {
	istringstream is(international_number);

	char sign = is.get();
	getline(is, country_code_, '-');
	getline(is, city_code_, '-');
	getline(is, local_number_);

	if (sign != '+' || country_code_.empty() || city_code_.empty() || local_number_.empty()) {
		throw invalid_argument("Phone number must begin with '+' symbol and contain 3 parts separated by '-' symbol: " + international_number);
	}
}