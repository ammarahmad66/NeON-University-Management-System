#pragma once
#include"Employee.h"
//#include"Department.h"
#include<iostream>
#include"Account.h"
using namespace std;

template<class Type>
Type** shrink(int index, Type** list, int size)
{
	Type** temp = new Type * [2];
	temp[1] = new Type[size - 1];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0,a=0; j < size; j++,a++)
		{
			if (j == index)
			{
				j++;
			}
			temp[i][a] = list[i][j];
		}
	}
	for (int i = 0; i < size; i++)
	{
		delete[]list[i];
	}
	delete[]list;
	list = temp;
	return list;
}
class Department;
class ITManager :public Employee
{
private:
	Account** list;
	int totalfaculty;
	int totalstudents;
	int currentfaculty;
	int currentstudents;
public:
	ITManager()
	{
		list = NULL;
		totalfaculty = 0;
		totalstudents = 0;
		currentfaculty = 0;
		currentstudents=0;

	}
	ITManager(int No, const char fName[]) :Employee(No, fName), Person(fName)
	{
		list = new Account * [2];
		totalfaculty = 20;
		totalstudents = 100;
		list[0] = new Account[totalstudents];
		list[1] = new Account[totalfaculty];
		currentfaculty = 0;
		currentstudents = 0;
	}
	void AddITManagerAccount(char* name)
	{
		list[1][currentfaculty++].AddAccount(name);
		cout << "Account created" << endl;
	}
	bool addStudentAccount(char* name)
	{
		if (currentstudents < totalstudents)
		{
			list[0][currentstudents++].AddAccount(name);
			cout << "Account created" << endl;
			return true;
		}
		cout << "No space left";
		return false;
	}
	bool addFacultyAccount(char* name)
	{
		if (currentfaculty < totalfaculty)
		{
			list[1][currentfaculty++].AddAccount(name);
			cout << "Account created" << endl;
			return true;
		}
		cout << "No space left";
		return false;
	}
	bool deleteFacultyaccount(char* name)
	{
		char* name1 = new char[strlen(name) + 2];
		for (int i = 0; i < strlen(name); i++)
		{
			if (name[i] == ' ')
			{
				i++;
			}
			name1[i] = name[i];
		}
		name1[strlen(name)] = '1';
		name1[strlen(name)] = '2';
		if (currentfaculty > 0)
		{
			for (int i = 0; i < currentfaculty; i++)
			{
				if (list[1][i].getUsername() == name1)
				{
					list[1][i].DeleteAccount(name);
					shrink(i, list, currentfaculty);
					cout << "Account deleted" << endl;
					currentfaculty--;
					return true;
				}
			}
		}
		cout << "No account of this name is found" << endl;
		return false;
	}
	bool DeleteStudentAccount(char* name)
	{
		char* name1 = new char[strlen(name) + 2];
		for (int i = 0; i < strlen(name); i++)
		{
			if (name[i] == ' ')
			{
				i++;
			}
			name1[i] = name[i];
		}
		name1[strlen(name)] = '1';
		name1[strlen(name)] = '2';
		if (currentstudents > 0)
		{
			for (int i = 0; i < i < currentstudents; i++)
			{
				if (list[0][i].getUsername() == name1)
				{
					list[1][i].DeleteAccount(name);
					shrink(i, list, currentstudents);
					currentstudents--;
					cout << "Account deleted" << endl;
					return true;
				}
			}
		}
		cout << "No account of this name is found" << endl;
		return false;
	}
	bool ChangeUsernameOfFacultyAccount(char* name)
	{
		char* name1 = new char[strlen(name) + 2];
		for (int i = 0; i < strlen(name); i++)
		{
			if (name[i] == ' ')
			{
				i++;
			}
			name1[i] = name[i];
		}
		name1[strlen(name)] = '1';
		name1[strlen(name)] = '2';
		if (currentfaculty > 0)
		{
			for (int i = 0; i < currentfaculty; i++)
			{
				if (list[1][currentfaculty].getUsername() == name1)
				{
					list[1][currentfaculty--].changeUsername();
					cout << "Username successfully changed" << endl;
					return true;
				}
			}
		}
		cout << "No account of this name is found" << endl;
		return false;
	}
	bool ChangeUsernameOfStudentAccount(char* name)
	{
		char* name1 = new char[strlen(name) + 2];
		for (int i = 0; i < strlen(name); i++)
		{
			if (name[i] == ' ')
			{
				i++;
			}
			name1[i] = name[i];
		}
		name1[strlen(name)] = '1';
		name1[strlen(name)] = '2';
		if (currentstudents > 0)
		{
			for (int i = 0; i < i < currentstudents; i++)
			{
				if (list[0][i].getUsername() == name1)
				{
					list[1][currentstudents--].changeUsername();
					cout << "Username Succesfully Changed" << endl;
					return true;
				}
			}
		}
		cout << "No account of this name is found" << endl;
		return false;
	}
	bool ChangePasswordOfStudentAccount(char* name)
	{
		char* name1 = new char[strlen(name) + 2];
		for (int i = 0; i < strlen(name); i++)
		{
			if (name[i] == ' ')
			{
				i++;
			}
			name1[i] = name[i];
		}
		name1[strlen(name)] = '1';
		name1[strlen(name)] = '2';
		if (currentstudents > 0)
		{
			for (int i = 0; i < i < currentstudents; i++)
			{
				if (list[0][i].getUsername() == name1)
				{
					list[1][currentstudents--].changePassword();
					cout << "Password changed successfully" << endl;
					return true;
				}
			}
		}
		cout << "No account of this name is found" << endl;
		return false;
	}
	bool ChangePasswordOfFacultyAccount(char* name)
	{
		char* name1 = new char[strlen(name) + 2];
		for (int i = 0; i < strlen(name); i++)
		{
			if (name[i] == ' ')
			{
				i++;
			}
			name1[i] = name[i];
		}
		name1[strlen(name)] = '1';
		name1[strlen(name)] = '2';
		if (currentfaculty > 0)
		{
			for (int i = 0; i < currentfaculty; i++)
			{
				if (list[1][currentfaculty].getUsername() == name1)
				{
					list[1][currentfaculty--].changePassword();
					cout << "Password successfully changed" << endl;
					return true;
				}
			}
		}
		cout << "No account of this name is found" << endl;
		return false;
	}
	bool Menu()
	{
		bool check=0;
		while (check)
		{
			cout << "1.Create account of faculty members" << endl;
			cout << "2.Delete account of faculty members" << endl;
			cout << "3.Create account of students" << endl;
			cout << "4.Delete accounts of students" << endl;
			cout << "5.Maintain accounts (e.g. change username, password)" << endl;
			cout << "6.Logout" << endl;
			int a;
			cin >> a;
			while (a > 6 || a <= 0)
			{
				cout << "Invalid input.Enter Again" << endl;
				cin >> a;
			}
			if (a == 1)
			{
				char* name = new char[20];
				cout << "Enter name of a faculty member: ";
				cin.getline(name, 20);
				addFacultyAccount(name);
			}
			else if (a == 2)
			{
				char* name = new char[20];
				cout << "Enter name of a faculty member: ";
				cin.getline(name, 20);
				deleteFacultyaccount(name);
			}
			else if (a == 3)
			{
				char* name = new char[20];
				cout << "Enter name of a Student: ";
				cin.getline(name, 20);
				addStudentAccount(name);
			}
			else if (a == 4)
			{
				char* name = new char[20];
				cout << "Enter name of a Student: ";
				cin.getline(name, 20);
				DeleteStudentAccount(name);
			}
			else if (a == 5)
			{
				cout << "Change password of a faculty account" << endl;
				cout << "Change username of a faculty acoount" << endl;
				cout << "Change password of a student account" << endl;
				cout << "Change username of a student account" << endl;
				int d;
				cin >> d;
				while (d > 4 || d < 0)
				{
					cout << "Invalid Input.Enter again" << endl;
					cin >> d;
				}
				if (d == 1)
				{
					char* name = new char[20];
					cout << "Enter name of a faculty member: ";
					cin.getline(name, 20);
					ChangePasswordOfFacultyAccount(name);
				}
				else if (d == 2)
				{
					char* name = new char[20];
					cout << "Enter name of a faculty member: ";
					cin.getline(name, 20);
					ChangeUsernameOfFacultyAccount(name);
				}
				else if (d == 3)
				{
					char* name = new char[20];
					cout << "Enter name of a Student: ";
					cin.getline(name, 20);
					ChangePasswordOfStudentAccount(name);
				}
				else if (d == 4)
				{
					char* name = new char[20];
					cout << "Enter name of a Student: ";
					cin.getline(name, 20);
					ChangeUsernameOfStudentAccount(name);
				}
			}
			else if (a == 6)
			{
				check = 0;
			}
		}
		return false;
	}
	~ITManager()
	{
		for (int i = 0; i < 2; i++)
		{
			delete[]list[i];
		}
		delete[]list;
	}
};