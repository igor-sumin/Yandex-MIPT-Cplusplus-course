#include <iostream>

using namespace std;

class Animal {
public:
	Animal(const string& name) : Name(name) {}

protected: 
	string Name;
};


class Dog : public Animal {
public:
    // Конструктор класса Dog должен принимать параметр типа string и инициализировать им поле Name в классе Animal.
	Dog(const string& name) : Animal(name) {}

	// Как я понимаю, теперь у Dog есть свой тд Name	
    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};

int main() {
	Dog d("Dog");
	d.Bark();

	return 0;
}