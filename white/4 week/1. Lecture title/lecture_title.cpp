#include <iostream>
#include <string>

using namespace std;

struct Specialization {
	string value;
	explicit Specialization(const string& _value) {
		value = _value;
	}
};

struct Course {
	string value;
	explicit Course(const string& _value) {
		value = _value;
	}
};

struct Week {
	string value;
	explicit Week(const string& _value) {
		value = _value;
	}
};

struct LectureTitle {
	string specialization;
	string course;
	string week;

	LectureTitle(const Specialization& _specialization, const Course& _course, const Week& _week) {
		specialization = _specialization.value;
		course = _course.value;
		week = _week.value;
	}
};

void PrintStruct(const LectureTitle& lecture) {
	cout << lecture.specialization << ", " << lecture.course << ", " << lecture.week << endl;
}

int main() {
	LectureTitle title(Specialization("C++"), Course("White belt"), Week("4th"));
	PrintStruct(title);

	return 0;
}