#pragma once
#include<iostream>
#include"Person.h"
//#include"Course.h"
//#include"Registration.h"
//#include"Department.h"
using namespace std;

class Registration;
class Department;
class Course;
class Student :public Person
{
private:
	int rollNo;
	Course** list=new Course*[8];
	int totalcourses;
	int currentcourses;
	bool TA;
public:
	Student();
	Student(Student& obj);
	Student(int No, char const fname[]) :Person(fname) { 
		rollNo = No;
	}
	int getCurrentCourses();
	int getRollNo();
	void registercourse(char const courseNum[], Registration a);
	bool withdrawCourse(char const coursenum[]);
	void ViewAttendance();
	void makeTA();
	void UnregisterACourse(char* coursenum);
	void withdraw(char const coursenum[]);
	void seeEvaluationOfaCourse();
	bool checkTA();
};