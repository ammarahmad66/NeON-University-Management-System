#include<iostream>
#include"University.h"
#include"ITManager.h"
#include"Course.h"
#include"Teacher.h"
#include"Registration.h"
#include"Student.h"
#include"HOD.h"
#include<fstream>
using namespace std;
int main()
{
	
	University u1;
	u1.ReadData();
	int logincount = 0;
	char* username = new char[25];      //Username is your name in small letters with 12
	long password;                      //password is 34566789
	int x;                             //This is either your rollNo or your employeeID
	int filecount = 0;
	int modeinput;
	cout << "Press 0 for loading the save information or 1 for starting a new login Menu" << endl;
	int a;
	cin >> a;
	if (a == 0)
	{
		filecount = 0;
		ifstream fin("output.txt");
		while (!fin.eof())
		{
			fin.getline(username, 25);
			cout << "Username: " << username << endl;
			fin >> password;
			cout << "password: " << password << endl;
			fin >> x;
			cout << "Roll No/Employee ID" << x << endl;
			fin >> modeinput;
		}
		filecount++;
		fin.close();
	}
	if (filecount != 1)
	{
		ofstream fout("output.txt");
		cout << "1.Login as HOD" << endl;
		cout << "2.Login as ITManager" << endl;
		cout << "3.Login as Teacher" << endl;
		cout << "4.Login as Student" << endl;
		cout << "5.Login as TA" << endl;
		cin >> modeinput;
		fout << modeinput;
		cout << "Enter your information" << endl;
		cout << "Username: ";
		cin.getline(username, 25);
		fout << username << endl;
		cout << "Password: ";
		cin >> password;
		fout << password;
		cout << "Roll No/Employee ID: ";
		cin >> x;
		fout << x;
		logincount++;
	}
	int count = u1.getDepartmentCount();
	bool check = 1;
	while (check)
	{
		if (modeinput == 1)
		{
			for (int i = 0; i < count; i++)
			{
				bool flag = u1.AccountExistanceofFaculty(x, i);
				bool a = 1;
				while (check&&a)
				{
					a = u1.HODMenu(x, i);
					i = count;
				}
			}
		}
		else if (modeinput == 2)
		{
			for (int i = 0; i < count; i++)
			{
				bool flag = u1.AccountExistanceofITManager(x, i);
				bool a = 1;
				while (check && a)
				{
					a = u1.ITManagerMenu(i);
					i = count;
				}
			}
		}
		else if (modeinput == 3)
		{
			for (int i = 0; i < count; i++)
			{
				bool flag = u1.AccountExistanceofFaculty(x, i);
				bool a = 1;
				while (check && a)
				{
					a = u1.TeacherMenu(x, i);
					i = count;
				}
			}
		}
		else if (modeinput == 4)
		{
			for (int i = 0; i < count; i++)
			{
				bool flag = u1.AccountExistanceofStudents(x, i);
				bool a = 1;
				while (check && a)
				{
					a = u1.StudentMenu(x, i);
					i = count;
				}
			}
		}
		else if (modeinput == 5)
		{
			for (int i = 0; i < count; i++)
			{
				bool flag = u1.AccountExistanceofStudents(x, i);
				bool a = 1;
				while (check && a)
				{
					a = u1.TAMenu(x, i);
					i = count;
				}
			}
		}
	}

	
	
	return 0;
}