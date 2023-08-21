#include<iostream>
#include"HOD.h"
#include"Student.h"
//#include"TA.h"
#include"Registration.h"
using namespace std;

Registration::Registration()
{
	courses = 0;
	currentstudents = 0;
	totalstudents = 0;
	totalcourses = 0;
	list = new Course * [1];
	slist = new Student * [1];
}

void Registration::InitializeStudentslist(int No)
{
	totalstudents = No;
	slist = new Student * [No];
	currentstudents = 0;
}
void Registration::InitializeCourseslist(int No)
{
	totalcourses = No;
	list = new Course * [No];
	courses = 0;
}
void Registration::registerCourse(Course& obj, Course** courselist)
{
	courselist[courses] = new Course[1];
	courselist[courses] = &obj;
	list[courses] = new Course[1];
	list[courses++] = &obj;
}
void Registration::registerStudent(Student& obj, Student** std_list)
{
	std_list[currentstudents] = new Student[1];
	std_list[currentstudents] = &obj;
	slist[currentstudents] = new Student[1];
	slist[currentstudents++] = &obj;
}
void Registration::registerTeacher(Teacher &obj, int currentteachers, Teacher** tlist, HOD h)
{
	if (currentteachers == 0)
	{
		tlist[currentteachers] = new Teacher[1];
		h.makeHOD(obj);
		tlist[currentstudents][0].makeHOD();
	}
	tlist[currentteachers++] = new Teacher[1];
	tlist[currentteachers++] = &obj;
}
bool Registration::RegisterCourse(int rollNo, char const courseNum[], Course** courselist, int currentcourses)
{
	for (int i = 0; i < courses; i++)
	{
		if (list[i]->getCourseNum() == courseNum)
		{
			courselist[currentcourses][0].setCourseName(list[i][0].getCourseName());
			courselist[currentcourses][0].setCourseNum(list[i][0].getCourseNum());
			currentcourses++;
			for (int i = 0; i < currentstudents; i++)
			{
				if (slist[i][0].getRollNo() == rollNo)
				{

					list[i][0].RegistrationOfAStudent(slist[i]);
				}
			}
			cout << "course registered successfully";

			return true;
		}
	}
	cout << "No course of this number exists" << endl;
	return false;
}
bool Registration::unregisterCourse(char* coursenum, char* studentname)
{
	for (int i = 0; i < currentstudents; i++)
	{
		if (slist[i][0].FirstName() == studentname)
		{
			slist[i][0].UnregisterACourse(coursenum);

			return true;
		}
	}
	cout << "Course withdawal unsuccessful" << endl;
	return false;
}
void Registration::PromoteStudenttoTA(int rollNo)
{
	for (int i = 0; i < currentstudents; i++)
	{
		if (slist[i][0].getRollNo() == rollNo)
		{
			slist[i][0].makeTA();
			TA t1;
			t1.makeTA(slist[i]);
		}
	}
}