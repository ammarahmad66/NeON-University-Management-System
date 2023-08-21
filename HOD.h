#pragma once
#include"Employee.h"
#include"Teacher.h"
//#include"Department.h"
#include<iostream>
using namespace std;
class Department;
class HOD:public Teacher
{
	HOD* h;
public:
	HOD(int ID, char const name[]) :Teacher(ID, name), Person(name){}
	HOD()
	{
		h = 0;
	}
	void makeHOD(Teacher& obj)
	{
		h = (HOD*)&obj;
	}
	~HOD()
	{
		delete[]h;
	}
};
