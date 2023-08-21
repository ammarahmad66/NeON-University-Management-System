#pragma once
#include<iostream>
#include"HOD.h"
#include"Student.h"
#include"TA.h"
//#include"Department.h"
using namespace std;
class Department;
class Registration
{
private:
	Course** list;
	int totalcourses;
	Student** slist;
	int courses;
	int totalstudents;
	int currentstudents;
public:
	Registration();
	void InitializeStudentslist(int No);
	void InitializeCourseslist(int No);
	void registerCourse(Course& obj, Course** courselist);
	void registerStudent(Student& obj, Student** std_list);
	void registerTeacher(Teacher& obj, int currentteachers, Teacher** tlist, HOD h);
	bool RegisterCourse(int rollNo, char const courseNum[], Course** courselist, int currentcourses);
	bool unregisterCourse(char* coursenum, char* studentname);
	void PromoteStudenttoTA(int rollNo);
};