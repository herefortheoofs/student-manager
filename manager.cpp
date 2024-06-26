#include "students.hpp"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() 
{
	std::vector<Student> studentsID;
	char choice = 'y';

	do {

		// Variables to hold input
		string userName;
		string userGrade;
		int userAge;

		// User input output
		cout << "Enter student's name: ";
		getline(cin, userName); // getline to allow spaces in names
		cout << "Enter student's grade: ";
		cin >> userGrade;
		cout << "Enter student's age: ";
		cin >> userAge;

		// Create object using user inputs

		Student Student(userName, userGrade, userAge);
		studentsID.push_back(Student);
		cout << "Do you want to add another student? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');

	// Save the objects to a text file
	std::ofstream outFile("students_data.txt", std::ios::app);
	if (outFile.is_open()) {
		for (const auto& Student : studentsID) {
			outFile << Student;
		}
		outFile.close();
		cout << "Students have been saved to file.\n";

	}
	else {
		cout << "Unable to open file for writing.\n";
	}
	// Load the objects from a text file
	vector<Student> loadedStudents;
	ifstream inFile("students_data.txt");
	if (inFile.is_open()) {
		Student student;
		while (inFile >> student) {
			loadedStudents.push_back(student);
		}
		inFile.close();
		cout << "Students loaded from file";
	}
	else {
		cout << "Unable to open file for reading.\n";
	}
	for (const auto& student : loadedStudents) {
		student.print();
	}
	return 0;
}