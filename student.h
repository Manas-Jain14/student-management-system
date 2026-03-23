#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student {
private:
    int id;
    string name;
    int age;

public:
    void input();
    void display();
    int getId();

    void setData(int i, string n, int a);
    string toFileString();
};

#endif