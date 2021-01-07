#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Абстрактный базовый класс
class Human {
public:
    Human(const string& name, const string& type) : name_(name), type_(type) {}

    virtual void Walk(const string& destination) const {
        cout << type_ << ": " << name_ << " walks to: " << destination << endl;
    }

    const string name_;
    const string type_;
};

class Teacher : public Human {
public:
    Teacher(const string& name, const string& profession) : Human(name, "Teacher"), profession_(profession) {}

    void Teach() const {
        cout << "Teacher: " << name_ << " teaches: " << profession_ << endl;
    }

protected:
    const string profession_;
};

class Student : public Human {
public:
    Student(const string& name, const string& singsong) : Human(name, "Student"), singsong_(singsong) {}

    void Learn() const {
        cout << "Student: " << name_ << " learns" << endl;
    }

    void SingSong() const {
        cout << "Student: " << name_ << " sings a song: " << singsong_ << endl;
    }

    void Walk(const string& destination) const override {
        Human::Walk(destination);
        SingSong();
    }

protected:
    const string singsong_;
};

class Policeman : public Human {
public:
    Policeman(const string& name) : Human(name, "Policeman") {}

    void Check(const Human& h) const {
        cout << "Policeman: " << name_ << " checks "<< h.type_ << ". " << h.type_ << "'s name is: " << h.name_ << endl;;
    }
};

void VisitPlaces(const Human& h, const vector<string>& places) {
    for(const auto& p : places) {
        h.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});

    return 0;
}
