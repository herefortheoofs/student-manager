#include "students.hpp"
#include <iostream>
#include <fstream>

using namespace std;

// Constructor
Student::Student(std::string newName, std::string newGrade, int newAge) {

	name = newName;
	grade = newGrade;
	age = newAge;
}

// Returns students name
std::string Student::get_name() {

	return name;
}

// Returns students grade
std::string Student::get_grade() {

	return grade;
}

// Returns students age
int Student::get_age() {

	return age;
}