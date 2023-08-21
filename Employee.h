#pragma once
#include<iostream>
using namespace std;
#include"Person.h"
class Employee : virtual public Person
{
private:
	int employeeNo;
public:
	Employee()
	{
		employeeNo = 0;
	}
	Employee( int No,const char fName[]) :Person(fName)
	{
		employeeNo = No;
	}
	void setEmployeeNo(int a)
	{
		employeeNo = a;
	}
	int getEmployeeNo()
	{
		return employeeNo;
	}
	virtual void printinformation()
	{
		Person::printinformation();
		cout << " his/her employee No is " << employeeNo;
	}
};