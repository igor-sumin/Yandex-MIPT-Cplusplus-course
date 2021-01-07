#include <bits/stdc++.h>

using namespace std;

struct Log {
	Log(string name) : n(name) {
		cout << "+ " << n << endl;
	}

	~Log() {
		cout << "- " << n << endl;
	}

	string n;
}

struct Fruit {
	const Log l;
	Fruit(const string& t) : l(t + " (Fruit)") {}
};

struct Apple : public Fruit {
	const Log l;
	Apple(const string& t) : Fruit(t), l(t) {}
};

// ...

class AppleTree {
public:
	Apple a1;
	Apple a2;
	Log l = log("AppleTree");

	AppleTree() : a1("a1"), a2("a2") {}
}

int main() {
	Apple a;
	// Вывод:
	// + Fruit
	// + Apple
	// - Apple
	// - Fruit

	// Это говорит о следующем:
	// Если у нас есть некоторая иерархия классов, то при создании объекта, принадлежащего данной иерархии, 
	// всегда будет сначала вызываться конструктор базового класса, затем класса наследника и так далее по цепочке. 
	// При этом, когда объекты данных классов будут удаляться, сначала всегда вызывается объект самого последнего класса наследника 
	// и так далее по цепочке вверх, пока мы не дойдем до деструктора самого базового класса

	Apple a = Apple("a1");
	Apple a2 = Apple("a2");

	AppleTree at;
	// Вывод:
	// + AppleTree
	// + a1 (Fruit)
	// + a1
	// + a2 (Fruit)
	// + a2
	// - a2
	// - a2 (Fruit)
	// - a1
	// - a1 (Fruit)

	return 0;
}