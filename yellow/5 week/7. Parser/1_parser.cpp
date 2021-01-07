#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include <string>
#include <cstdint>
#include <cassert>

using namespace std;

// Базовый класс
class Node {
public:
	// Вычисляет выражение
	virtual int Evaluate() {
		return 0;
	}
};

class Digit : public Node {
public:
	Digit(int d) : d_(d) {}

	int Evaluate() override {
		return d_;
	}

private:
	const int d_;
};

class Variable : public Node {
public:
	Variable(const int& x) : x_(x) {}

	int Evaluate() override {
		return x_;
	}

private:
	// Каждый раз значение x будет разным, однако менять ее мы не собираемся
	const int& x_;
};

class Operation : public Node {
public:
	Operation(char op, shared_ptr<Node> left, shared_ptr<Node> right) : op_(op), left_(left), right_(right) 
	{	
	}

	int Evaluate() override {
		switch(op_) {
			case '*':
				// Мы можем вызвать функцию Evaluate у наших слагаемых, и так как нам все равно, что на самом деле они из себя представляют — число, 
				// переменная или другая операция, то достаточно воспользоваться просто вызовом метода из базового класса.
				return left_->Evaluate() * right_->Evaluate();
			case '/':
				assert(right_->Evaluate() != 0);
				return left_->Evaluate() / right_->Evaluate();
			case '-':
				return left_->Evaluate() - right_->Evaluate();
			case '+':
				return left_->Evaluate() + right_->Evaluate();
			default:
				throw exception();
		}

		return 0;
	}
	
private:
	const char op_;
	shared_ptr<Node> left_, right_;
};

// x будет при каждой итерации меняться, поэтому он с ссылкой
// Node Parse(const string& tokens, int& x) {
// }

int main() {
	// Пoстановка задачи

	// Входные данные: 
	// - Выражение. Состоит из операций +,-,*, цифр и переменной x
	// - Значение переменной

	// Выходные данные:
	// - Значение выражения при введенном значении переменной

	// Пример:
	// 1 + 2 - 3 * x + x
	// x = 5 -7
	// x = 1 1
	// x = ...
	int x;

	// => Частный случай решения задачи на основе примера:
	// 3 * x
	shared_ptr<Node> var1 = make_shared<Digit>(3);
	shared_ptr<Node> var1_2 = make_shared<Variable>(x);
	shared_ptr<Node> mul3 = make_shared<Operation>('*', var1, var1_2);
	// 1 + 2
	shared_ptr<Node> var2 = make_shared<Digit>(1);
	shared_ptr<Node> var2_2 = make_shared<Digit>(2);
	shared_ptr<Node> plus1 = make_shared<Operation>('+', var2, var2_2);	
	// (1 + 2) - (3 * x)
	shared_ptr<Node> minus2 = make_shared<Operation>('-', plus1, mul3);
	// ((1 + 2) - (3 * x)) + (x)
	shared_ptr<Node> var3 = make_shared<Variable>(x);
	shared_ptr<Node> plus4 = make_shared<Operation>('+', minus2, var3);
	
	// Ответ можно вывести следующим образом:
	cout << "Enter x: ";
	while(cin >> x) {
		// Пусть результат вычисляется методом Evaluate
		cout << plus4->Evaluate() << endl;
		cout << "Enter x: ";
	}


	// ++++++++++++++++++++++

	// string tokens;

	// cout << "Enter expression: ";
	// cin >> tokens;
	// auto expr = Parse(tokens, x);

	// cout << "Enter x: ";
	// while(cin >> x) {
	// 	// Пусть результат вычисляется методом Evaluate
	// 	cout << expr->Evaluate() << endl;
	// 	cout << "Enter x: ";
	// }


	return 0;
}