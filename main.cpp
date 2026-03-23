#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Student.h"

using namespace std;

// Load data from file
void loadFromFile(vector<Student> &students) {
    ifstream file("students.txt");

    if (!file) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int id, age;
        string name;

        ss >> id >> name >> age;

        Student s;
        s.setData(id, name, age);
        students.push_back(s);
    }

    file.close();
}

// Save data to file
void saveToFile(vector<Student> &students) {
    ofstream file("students.txt");

    for (auto s : students) {
        file << s.toFileString() << endl;
    }

    file.close();
}

int main() {
    vector<Student> students;

    // Load existing data
    loadFromFile(students);

    int choice;

    while (true) {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            s.input();
            students.push_back(s);
            saveToFile(students);
            cout << "Student added successfully!\n";
        }

        else if (choice == 2) {
            if (students.empty()) {
                cout << "No students found.\n";
            } else {
                for (auto s : students) {
                    s.display();
                }
            }
        }

        else if (choice == 3) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;

            bool found = false;
            for (auto s : students) {
                if (s.getId() == id) {
                    s.display();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found.\n";
            }
        }

        else if (choice == 4) {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;

            bool found = false;
            for (auto it = students.begin(); it != students.end(); it++) {
                if (it->getId() == id) {
                    students.erase(it);
                    saveToFile(students);
                    cout << "Student deleted successfully.\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found.\n";
            }
        }

        else if (choice == 5) {
            cout << "Exiting program...\n";
            break;
        }

        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}