#include <bits/stdc++.h>

using namespace std;

// Базовый класс
struct Fruit {
	int health = 0;
	string type = "fruit";
};

// Выражение отношения наследования
// Наследник Apple наследуется от Fruit
struct Apple : public Fruit {
	Apple() {
		// Мы получили доступ к полям, которые объявлены в нашем базовом классе с помощью публичного наследования.
		health = 10;
		type = "apple";
	}
};

struct Orange : public Fruit {
	Orange() {
		health = 5;
		type = "orrange";
	}
};

struct PineApple : public Fruit {
	PineApple() {
		health = 15;
		type = "pineapple";
	}
};

class Animal {
public:
	Animal(const string& t = "animal") : type(t) {}

	void Eat(const Fruit& f) {
		cout << type << " eats " << f.type << ". " << a.health << "hp." << endl;
	}

// Когда мы пишем ключевое слово protected, все переменные, которые объявлены ниже него, и все методы становятся защищенными, 
// и они не видны снаружи, то есть никто извне не может к ним обратиться
protected:
	// К type могут обращаться только наследники данного класса
	string type = "Animal";
}

// С помощью публичного наследования мы получили доступ к методам и полям класса animal.
class Cat : public Animal {
public:
	Cat() {
		// В тот момент, когда мы входим в конструкторе в фигурные скобки, на самом деле, 
		// наши переменные внутри класса, они уже проинициализированы. 
		// И каждый раз, когда мы в них что-то записываем, внутри этих фигурных скобок, 
		// мы на самом деле не инициализируем их, а делаем присваивания, присваивания нового значения, которое записано поверх старого. 
		// То есть в данной строчке в переменной типа type уже лежит строчка animal. 
		type = "Cat";
	}

	// Добавили дополнительный метод
	void Meow() const {
		cout << "meow!" << endl;
	}
};

// Теперь собака может вызывать метод Eat, хотя этот метод не определен внутри класса Dog, 
// а определен внутри класса, от которого отнаследован класс Dog.
class Dog : public Animal {
public:
	Dog() : Animal("Dog") {
		// // ???
		// type = "Dog";
	}
};

void DoMeal(Animal& a, Fruit& f) {
	a.Eat(f);
	// // Поле не защищено от изменений - нужно защититься от них при помощи protected
	// a.type += "*";
}

int main() {
	Cat c;
	c.Meow();
	
	Apple a;
	c.Eat(a);
	Orange o;
	c.Eat(o);

	Dog d;
	d.Meow();
	
	d.Eat(a);
	d.Eat(o);

	// Избавимся от дублирования
	// Создадим отношения наследования

	return 0;
}