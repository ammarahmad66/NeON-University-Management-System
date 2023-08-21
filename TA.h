#pragma once
#include<iostream>
#include"Teacher.h"
#include"Student.h"
//#include"Department.h"
#include"Course.h"

using namespace std;
class Department;
class TA :public Teacher, public Student
{
	Course *course ;
	int coursecount;
public:
	TA()
	{
		coursecount=0;
		course = NULL;
	}
	TA(int rollNo, char const name[],int employeeNo) :Student(rollNo, name),Teacher(employeeNo,name)
	{}
	void makeTA(Student* obj)
	{
		TA* t1 = (TA*)&obj;
	}
	void ManageEvaluations()
	{
		Teacher::ManageEvaluations();
	}
};