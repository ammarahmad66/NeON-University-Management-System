#pragma once
#include"Course.h"
#include<iostream>
using namespace std;

class Department;
class Teacher : public Employee
{
private:
	Course* course;
	int coursecount;
	bool HOD;
public:
	Teacher()
	{
		HOD = 0;
		coursecount = 0;
		course = NULL;
	}
	Teacher(int No, const char fName[]) :Employee(No, fName), Person(fName) { 
		course = new Course[1];
		HOD = 0;
		coursecount = 0;
	}
	Teacher(Teacher& obj)
	{
		setName(obj.FirstName());
		setEmployeeNo(obj.getEmployeeNo());
		coursecount=obj.coursecount;
		HOD = obj.HOD;
	}
	void setCourse(Course* obj)
	{
		if (coursecount == 0)
		{
			course[0].setCourseName(obj->getCourseName());
			course[0].setCourseNum(obj->getCourseNum());
			coursecount++;
		}
		else
		{
			cout << "Course is already assigned";
		}
	}
	void makeHOD()
	{
		HOD = 1;
	}
	bool CheckHOD()
	{
		if (HOD)
		{
			return true;
		}
		return false;
	}
	void ManageAttendane()
	{
		course[0].InitializeAttendance();
		cout << "1.Modify Attendance" << endl;
		cout << "2.Mark Attendance" << endl;
		cout << "3.View Attendance" << endl;
		int a;
		cin >> a;
		while (a > 3 || a < 0)
		{
			cout << "Invalid input.Enter again" << endl;
			cin >> a;
		}
		if (a == 1)
		{
			int rollNo;
			cout << "Enter a roll No of a student whose attendance you want to modify" << endl;
			cin >> rollNo;
			course[0].ModifyAttendance(rollNo);
		}
		else if (a == 2)
		{
			course[0].MarkAttendance();
		}
		else if (a == 3)
		{
			int rollNo;
			cout << "Enter a roll No of a student whose attendance you want to view" << endl;
			cin >> rollNo;
			course[0].viewAttendance(rollNo);
		}
	}
	void AssignGradesToStudents()
	{
		course[0].AssignGrades();
		course[0].IncrementGradeCount();
	}
	virtual void ManageEvaluations()
	{
		course[0].Evaluations();
	}
	virtual void viewGrades()
	{
		course[0].seeGrades();
	}
	
};