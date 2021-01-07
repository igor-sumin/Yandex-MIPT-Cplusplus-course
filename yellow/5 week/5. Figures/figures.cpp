#include <bits/stdc++.h>

using namespace std;

#define PI 3.14

// Абстрактный базовый класс
class Figure {
public:
    Figure(const string& name) : name_(name) {}

    virtual string Name() const = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;

    // Виртуальный деструктор.
    // При отсутствии проблем компиляции данного решения строка не является необходимой и может быть опущена.
    virtual ~Figure() = default;

protected:
    const string name_;
};

class Triangle : public Figure {
public:
    Triangle(const string& name, double a, double b, double c) : Figure(name), A(a), B(b), C(c) {}

    string Name() const {
        return name_;
    }

    double Perimeter() {
        return A + B + C;
    }

    double Area() {
        double P = A + B + C;
        return sqrt((P / 2.0) * (P / 2.0 - A) * (P / 2.0 - B) * (P / 2.0 - C));
    }

protected:    
    double A, B, C;
};

class Rect : public Figure {
public:
    Rect(const string& name, double a, double b) : Figure(name), A(a), B(b) {}

    string Name() const {
        return name_;
    }

    double Perimeter() {
        return (A + B) * 2;
    }   

    double Area() {
        return A * B;
    }

protected:
    double A, B;
};

class Circle : public Figure {
public:
    Circle(const string& name, double r) : Figure(name), radius(r) {}

    string Name() const {
        return name_;
    }

    double Perimeter() {
        return 2 * PI * radius;
    }

    double Area() {
        return PI * radius * radius;
    }

protected:
    double radius;
};

shared_ptr<Figure> CreateFigure(istringstream& is) {
    string name;
    is >> name;

    if(name == "CIRCLE") {
        double r;
        is >> r;

        return make_shared<Circle>(name, r);
    } 

    double a, b;
    is >> a >> b;

    if(name == "RECT") {
        return make_shared<Rect>(name, a, b);
    } 
    
    if(name == "TRIANGLE") {
        double c;
        is >> c;

        return make_shared<Triangle>(name, a, b, c);
    }

    throw std::invalid_argument("invalid figure name was specified");
}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        // добавить фигуру в набор
        if (command == "ADD") {
            figures.push_back(CreateFigure(is));
        } 
        // для каждой фигуры в наборе распечатать название, периметр и площадь
        else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3) 
                << current_figure->Name() << " " 
                << current_figure->Perimeter() << " " 
                << current_figure->Area() << endl;
            }
        }
    }

    return 0;
}

// Input
// ADD RECT 2 3
// ADD TRIANGLE 3 4 5
// ADD RECT 10 20
// ADD CIRCLE 5
// PRINT

// Output
// RECT 10.000 6.000
// TRIANGLE 12.000 6.000
// RECT 60.000 200.000
// CIRCLE 31.400 78.500

// ...

// Input:
// ADD RECT 1 1
// ADD TRIANGLE 1 1 1
// ADD CIRCLE 1
// ADD RECT 1000 1000
// ADD TRIANGLE 1000 1000 1000
// ADD CIRCLE 1000
// PRINT

// Correct output:
// RECT 4.000 1.000
// TRIANGLE 3.000 0.433
// CIRCLE 6.280 3.140
// RECT 4000.000 1000000.000
// TRIANGLE 3000.000 433012.702
// CIRCLE 6280.000 3140000.000