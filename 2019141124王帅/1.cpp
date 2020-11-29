#include <iostream>

using namespace std;

class Col_Staff
{};

class Student:virtual public Col_Staff
{};

class Tech_Staff: virtual public Col_Staff
{};

class Speci_Student: public Student
{};

class Undergraduate: public Student
{};

class Gradu_Student: public Student
{};

class Teacher: public Tech_Staff
{};

class Admini_Staff: public Tech_Staff
{};

class Other_Staff: public Tech_Staff
{};

class On_Job_Postgraduate: public Gradu_Student, public Teacher
{};


int main(void)
{

    return 0;
}
