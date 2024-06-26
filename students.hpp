#include <iostream>
#include <string>
#include <fstream>
class Student {
	// Define Variables
	std::string name;
	std::string grade;
	int age;

public:
	Student(std::string newName, std::string newGrade, int newAge); // Constructor
	Student() : name(""), grade(0), age(0) {}
	// Get object variable functions
	std::string get_name();
	std::string get_grade();
	int get_age();

	// Overload the stream insertion operator
	friend std::ostream& operator<<(std::ostream& os, const Student& obj) {
		os << obj.name << " " << obj.grade << " " << obj.age << std::endl;
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Student& obj) {
		is >> obj.name >> obj.grade >> obj.age;
		return is;
	}
	void print() const {
		std::cout << "Name: " << name << ", Grade: " << grade << ", Age: " << age << std::endl;
	}
};