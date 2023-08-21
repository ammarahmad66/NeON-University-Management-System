#pragma once
#include"Department.h"
#include<iostream>
#include<fstream>
using namespace std;

class University
{
private:
	Department** list;
	int currentdepartment;
	int totaldepartment;
	char* UniversityName;
public:
	University()
	{
		list=NULL;
		currentdepartment=0;
		totaldepartment=0;
		UniversityName=NULL;
	}
	University(char* name,int No)
	{
		UniversityName = new char[strlen(name) + 1];
		for (int i = 0; i < strlen(name); i++)
		{
			UniversityName[i] = name[i];
		}
		UniversityName[strlen(name)] = '\0';
		list = new Department * [No];
		totaldepartment = No;
	}
	void setUniversityName(char* name)
	{
		UniversityName = new char[strlen(name) + 1];
		for (int i = 0; i < strlen(name); i++)
		{
			UniversityName[i] = name[i];
		}
		UniversityName[strlen(name)] = '\0';
	}
	void InitializeDepartment(int No)
	{
		list = new Department * [No];
		totaldepartment = No;
		for (int i = -0; i < No; i++)
		{
			list[i] = new Department[1];
		}
	}
	void ReadData()
	{
		ifstream fin("data.txt");
		while (!fin.eof())
		{	
			char* name = new char[50];
			fin.getline(name, 50);
			int No;
			fin >> No;
			setUniversityName(name);
			InitializeDepartment(No);
			for (int i = 0; i < No; i++)
			{
				fin.ignore(256, '\n');
				char* dname = new char[30];
				fin.getline(dname, 30);
				list[i][0].setDepartmentname(dname);
				int coursecount;
				fin >> coursecount;
				list[i][0].InitializeCourseList(coursecount);
				for (int j = 0; j < coursecount; j++)
				{
					char* courseID = new char[6];
					fin.getline(courseID, 6);
					fin.ignore(6, ',');
					char* coursename = new char[35];
					fin.getline(coursename, 35);
					list[i][0].RegisterCourse(courseID, coursename);
					cout << "done" << endl;
				}
				int teachercount;
				fin >> teachercount;
				cout << teachercount << endl;
				list[i][0].InitializeTeachersList(teachercount);
				for (int j = 0; j < teachercount; j++)
				{
					int employeeID;
					char* tname = new char[25];
					fin >> employeeID;
					fin.ignore(1, ',');
					fin.getline(tname, 25);
					list[i][0].RegisterTeacher(employeeID, tname);
				}
				fin.ignore(256, '\n');
				int itmanagercount;
				fin >> itmanagercount;
				for (int j = 0; j < itmanagercount; j++)
				{
					int employeeID;
					char* itname = new char[25];
					fin >> employeeID;
					fin.ignore(1, ',');
					fin.getline(itname, 25);
					list[i][0].RegisterITManager(employeeID, itname);
				}
				fin.ignore(256, '\n');
				int studentcount;
				fin >> studentcount;
				list[i][0].InitializeStudentsList(studentcount);
				for (int j = 0; j < studentcount; j++)
				{
					int rollNo;
					char* stname = new char[25];
					fin >> rollNo;
					fin.ignore(1, ',');
					fin.getline(stname, 25);
					list[i][0].RegisterStudent(rollNo, stname);
				}
				list[i][0].MakeAccountsforFacultyAndStudent(teachercount, studentcount);
				currentdepartment++;
			}
		}
		cout << "Data reading from fil is successful" << endl;
		fin.close();
	}
	int getDepartmentCount()
	{
		return totaldepartment;
	}
	bool AccountExistanceofFaculty(int employeeID,int index)
	{
		bool check=list[index][0].AccountExistanceOfFaculty(employeeID);
		if (check)
		{
			return true;
		}
		cout << "No account of this username exist" << endl;
		return false;
	}
	bool AccountExistanceofITManager(int employeeID,int index)
	{
		bool check = list[index][0].AccountExistanceofITManager(employeeID);
		if (check)
		{
			return true;
		}
		cout << "No account of this username exist" << endl;
		return false;
	}
	bool AccountExistanceofStudents(int rollNo,int index)
	{
		bool check = list[index][0].AccountExistanceOfStudent(rollNo);
		if (check)
		{
			return true;
		}
		cout << "No account of this username exist" << endl;
		return false;
	}
	bool HODMenu(int employeeID,int index)
	{
		bool check = list[index][0].HODMenu(employeeID);
		if (!check)
		{
			return false;
		}
	}
	bool TeacherMenu(int employeeID, int index)
	{
		bool check = list[index][0].TeacherMenu(employeeID);
		if (!check)
		{
			return false;
		}
	}
	bool StudentMenu(int rollNo, int index)
	{
		bool check = list[index][0].StudentMenu(rollNo);
		if (!check)
		{
			return false;
		}
	}
	bool ITManagerMenu( int index)
	{
		bool check = list[index][0].ITManagerMenu();
		if (!check)
		{
			return false;
		}
	}
	bool TAMenu(int rollNo, int index)
	{
		bool check = list[index][0].TAmenu(rollNo);
		if (!check)
		{
			return false;
		}
	}
	~University()
	{
		for (int i = 0; i < currentdepartment; i++)
		{
			delete[]list[i];
		}
		delete[]list;
		delete[]UniversityName;
	}
};