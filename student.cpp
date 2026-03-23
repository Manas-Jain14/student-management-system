#include "Student.h"

void Student::input() {
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;
}

void Student::display() {
    cout << "ID: " << id << ", Name: " << name << ", Age: " << age << endl;
}

int Student::getId() {
    return id;
}

void Student::setData(int i, string n, int a) {
    id = i;
    name = n;
    age = a;
}

string Student::toFileString() {
    return to_string(id) + " " + name + " " + to_string(age);
}