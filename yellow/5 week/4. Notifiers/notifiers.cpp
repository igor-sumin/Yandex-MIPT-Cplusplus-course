#include <iostream>
#include <string>

using namespace std;

void SendSms(const string& number, const string& message) {
	cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string& email, const string& message) {
	cout << "Send '" << message << "' to e-mail "  << email << endl;
}

// Абстрактный базовый класс
class INotifier {
public:
	virtual void Notify(const string& message) const = 0;
};

class SmsNotifier : public INotifier {
private:
	const string number_;
public:
	SmsNotifier(const string& number) : number_(number) {}
	void Notify(const string& message) const override {
		SendSms(number_, message);
	}
};

class EmailNotifier : public INotifier {
private:
	const string email_;
public:
	EmailNotifier(const string& email) : email_(email) {}
	void Notify(const string& message) const override {
		SendEmail(email_, message);
	}
};

void Notify(INotifier& notifier, const string& message) {
	notifier.Notify(message);
}

int main() {
	SmsNotifier sms{"+7-495-777-77-77"};
	EmailNotifier email{"na-derevnyu@dedushke.ru"};

	Notify(sms, "I have White belt in C++");
	Notify(email, "And want a Yellow one");

	// Send 'I have White belt in C++' to number +7-495-777-77-77
	// Send 'And want a Yellow one' to e-mail na-derevnyu@dedushke.ru

	return 0;
}