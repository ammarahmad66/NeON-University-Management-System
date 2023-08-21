#pragma once
#include"ITManager.h"
#include"Course.h"
#include"Teacher.h"
#include"Registration.h"
#include"Student.h"
#include"HOD.h"
#include<iostream>
using namespace std;

template<class Type>
Type** Initialize(int size, Type** arr)
{
	arr = new Type * [size];
	return arr;
}
class Department
{
private:
	ITManager* it;
	HOD h;
	Registration *r;
	Course** courselist;
	int currentcourses;
	int totalcourses;
	Student** studentlist;
	int totalstudents;
	int currentstudents;
	Teacher** teacherlist;
	int totalteachers;
	int currentteachers;
	char* departmentname;
public:
	Department()
	{
		courselist=NULL;
		studentlist = NULL;
		teacherlist = NULL;
		currentcourses = 0;
		totalcourses = 0;
		currentstudents = 0;
		totalstudents = 0;
		currentteachers = 0;
		totalteachers = 0;
		departmentname = NULL;
		r = new Registration[1];
		it = new ITManager[1];
	}
	Department(char* name)
	{
		cout << "Department()" << endl;
		departmentname = new char[strlen(name) + 1];
		for (int i = 0; i < strlen(name) + 1;i++)
		{
			departmentname[i] = name[i];
		}
		departmentname[strlen(name)] = '\0';
	}
	void setDepartmentname(char* name)
	{
		departmentname = new char[strlen(name) + 1];
		for (int i = 0; i < strlen(name) + 1; i++)
		{
			departmentname[i] = name[i];
		}
		departmentname[strlen(name)] = '\0';
	}
	char* getName()
	{
		return departmentname;
	}
	void InitializeCourseList(int No)
	{
		totalcourses = No;
		courselist = Initialize(totalcourses, courselist);
		r[0].InitializeCourseslist(No);
	}
	void InitializeTeachersList(int No)
	{
		totalteachers = No;
		teacherlist = new Teacher * [totalteachers];
	}
	void InitializeStudentsList(int No)
	{
		totalstudents = No;
		studentlist = Initialize(totalstudents, studentlist);
		r[0].InitializeStudentslist(No);
	}
	void RegisterTeacher(int employeeNo, char* name)
	{
		Teacher t1(employeeNo, name);
		r[0].registerTeacher(t1, currentteachers, teacherlist,h);
	}
	void RegisterStudent(int rollNo, char* name)
	{
		Student s1(rollNo, name);
		r[0].registerStudent(s1, studentlist);
		currentstudents++;
	}
	void RegisterCourse(char* courseID, char* name) 
	{
		cout << "register course" << endl;
		Course c1(name, courseID);
		r[0].registerCourse(c1, courselist);
		currentcourses++;
	}
	void RegisterITManager(int employeeID, char* name)
	{
		it[0].setEmployeeNo(employeeID);
		it[0].setName(name);
		it[0].AddITManagerAccount(name);
	}
	void MakeAccountsforFacultyAndStudent(int facultynumber, int Studentnumber)
	{
		for (int i = 0; i < facultynumber; i++)
		{
			it[0].addFacultyAccount(teacherlist[i][0].FirstName());
		}
		for (int i = 0; i < Studentnumber; i++)
		{
			it[0].addStudentAccount(studentlist[i][0].FirstName());
		}
	}
	void RegisterCourseForAStudent()       //HOD will call thos function for registering a course for student
	{
		cout << "Enter 5 charachter courseID: ";
		char* ID = new char[5];
		cin.getline(ID, 5);
		cout << "Enter the RollNo of A Student: ";
		int rollNo;
		cin >> rollNo;
		for (int i = 0; i < currentstudents; i++)
		{
			if (studentlist[i][0].getRollNo() == rollNo)
			{
				studentlist[i]->registercourse(ID, r[0]);
			}
		}
	}
	void TA()        //Teacher will call this function for making a TA
	{
		cout << "Enter the Roll No of a student to make him/her TA";
		int rollNo;
		cin >> rollNo;
		r[0].PromoteStudenttoTA(rollNo);
	}
	void assignCourseToATeacher(int employeeID, char* courseID)
	{
		for (int i = 0; i < currentteachers; i++)
		{
			if (teacherlist[i][0].getEmployeeNo() == employeeID)
			{
				for (int j = 0; j < currentcourses; j++)
				{
					if (courselist[j][0].getCourseNum() == courseID)
					{
						teacherlist[i][0].setCourse(courselist[j]);
						cout << "Course is successfully assigned" << endl;
						i = currentteachers;
						j=currentcourses;
					}
				}
			}
		}
	}
	void UnregisterCourseForAStudent()      //HOD will call thos function for unregistering a course for student
	{
		cout << "Enter 5 charachter courseID: ";
		char* ID = new char[5];
		cin.getline(ID, 5);
		char* name = new char[25];
		cout << "Enter the RollNo of A Student: ";
		int rollNo;
		cin >> rollNo;
		for (int i = 0; i < currentstudents; i++)
		{
			if (studentlist[i][0].getRollNo() == rollNo)
			{
				studentlist[i][0].withdrawCourse(ID);
			}
		}
	}
	bool ITManagerMenu()
	{
		bool flag=it[0].Menu();
		if (!flag)
		{
			return false;
		}
	}
	void ChangePasswordOfAccount(int rollNo)       //For student to change password
	{
		for (int i = 0; i < currentstudents; i++)
		{
			if (studentlist[i][0].getRollNo() == rollNo)
			{
				it[0].ChangePasswordOfStudentAccount(studentlist[i][0].FirstName());
			}
		}
	}
	bool AccountExistanceOfStudent(int rollNo)
	{
		for (int i = 0; i < currentstudents; i++)
		{
			if (studentlist[i][0].getRollNo() == rollNo)
			{
				return true;
			}
		}
		return false;
	}
	bool AccountExistanceOfFaculty(int employeeID)
	{
		for (int i = 0; i < currentteachers; i++)
		{
			if (teacherlist[i][0].getEmployeeNo() == employeeID)
			{
				return true;
			}
		}
		return false;
	}
	bool AccountExistanceofITManager(int employeeID)
	{
		if (it[0].getEmployeeNo() == employeeID)
			return true;
		return false;
	}
	void ViewGrades(char* courseID)      //for HOD
	{
		for (int i = 0; i < currentcourses; i++)
		{
			if (courselist[i][0].getCourseNum() == courseID)
			{
				courselist[i][0].seeGrades();
			}
		}
	}
	bool PromoteStuenttoTA(int rollNo)
	{
		for (int i = 0; i < currentstudents; i++)
		{
			if (studentlist[i][0].getRollNo() == rollNo)
			{
				studentlist[i][0].makeTA();
				cout << "Student promoted to TA" << endl;
				return true;
			}
		}
		return false;
	}
	bool StudentMenu(int rollNo)
	{
		bool check=0;
		while (check)
		{
			cout << "1.Register courses " << endl;
			cout << "2.Withdraw a courses" << endl;
			cout << "3.Unregister a course" << endl;
			cout << "4.View marksheet of a specific course" << endl;
			cout << "5.View attendance of a specific course" << endl;
			cout << "6.Change Password" << endl;
			cout << "7.Logout" << endl;
			int a;
			cin >> a;
			while (a > 7 || a <= 0)
			{
				cout << "Invalid Input.Error again: ";
				cin >> a;
			}
			if (a == 1)
			{
				char* ID = new char[5];
				cout << "Enter 5 character courseID: ";
				cin.getline(ID, 5);
				for (int i = 0; i < currentstudents; i++)
				{
					if (studentlist[i][0].getRollNo() == rollNo)
					{
						studentlist[i]->registercourse(ID, r[0]);
						i = currentstudents;
					}
				}
			}
			else if (a == 3)
			{
				char* ID = new char[5];
				cout << "Enter 5 character courseID: ";
				cin.getline(ID, 5);
				for (int i = 0; i < currentstudents; i++)
				{
					if (studentlist[i][0].getRollNo() == rollNo)
					{
						studentlist[i][0].UnregisterACourse(ID);
						i = currentstudents;
					}
				}
			}
			else if (a == 2)
			{
				char* ID = new char[5];
				cout << "Enter 5 character courseID: ";
				cin.getline(ID, 5);
				for (int i = 0; i < currentstudents; i++)
				{
					if (studentlist[i][0].getRollNo() == rollNo)
					{
						studentlist[i][0].withdrawCourse(ID);
						i = currentstudents;
					}
				}
			}
			else if (a == 4)
			{
				for (int i = 0; i < currentstudents; i++)
				{
					if (studentlist[i][0].getRollNo() == rollNo)
					{
						studentlist[i][0].seeEvaluationOfaCourse();
						i = currentstudents;
					}
				}
			}
			else if (a == 5)
			{
				for (int i = 0; i < currentstudents; i++)
				{
					if (studentlist[i][0].getRollNo() == rollNo)
					{
						studentlist[i][0].ViewAttendance();
						i = currentstudents;
					}
				}
			}
			else if (a == 6)
			{
				ChangePasswordOfAccount(rollNo);
			}
			else if (a == 7)
			{
				check = 0;
			}
		}
		return false;
	
	}
	bool TeacherMenu(int employeeID)
	{
		bool check=1;
		while (check)
		{
			cout << "1.Manage attendance of students" << endl;
			cout << "2.Manage/See evaluations of students " << endl;
			cout << "3.Assign Grades to Students" << endl;
			cout << "4.Promote Student to TA" << endl;
			cout << "5.Logout" << endl;
			int a;
			cin >> a;
			while (a > 5 || a <= 0)
			{
				cout << "Invalid Input.Error again: ";
				cin >> a;
			}
			if (a == 1)
			{
				for (int i = 0; i < currentteachers; i++)
				{
					if (teacherlist[i][0].getEmployeeNo() == employeeID)
					{
						teacherlist[i][0].ManageAttendane();
					}
				}
			}
			else if (a == 2)
			{
				for (int i = 0; i < currentteachers; i++)
				{
					if (teacherlist[i][0].getEmployeeNo() == employeeID)
					{

						int d;
						cin >> d;
						cout << "1.View all the Evaluations" << endl;
						cout << "2.View Grades" << endl;
						while (d > 2 || d <= 0)
						{
							cout << "Invalid Input.Enter again: ";
							cin >> d;
						}
						if (d == 1)
						{
							teacherlist[i][0].ManageEvaluations();
						}
						else if (d == 2)
						{
							teacherlist[i][0].viewGrades();
						}
						
					}
				}
			}
			else if (a == 3)
			{
				for (int i = 0; i < currentteachers; i++)
				{
					if (teacherlist[i][0].getEmployeeNo() == employeeID)
					{
						teacherlist[i][0].AssignGradesToStudents();
					}
				}
			}
			else if (a == 4)
			{
				int rollNo;
				cout << "Enter Roll No of a student" << endl;
				cin >> rollNo;
				PromoteStuenttoTA(rollNo);
			}
			else if (a == 5)
			{
				check = 0;
			}
		}
		return false;
	}
	bool HODMenu(int employeeID)
	{
		for (int i = 0; i < currentteachers; i++)
		{
			if (teacherlist[i][0].getEmployeeNo() == employeeID)
			{
				bool check = teacherlist[i]->CheckHOD();
				if (check)
				{
					bool flag=0;
					while (flag)
					{
						cout << "1.Assign courses to teachers" << endl;
						cout << "2.Register a course for a student" << endl;
						cout << "3.Unregister a course for a student" << endl;
						cout << "4.View grades of a specific course" << endl;
						cout << "Logout" << endl;
						int a;
						cin >> a;
						while (a > 5 || a <= 0)
						{
							cout << "Invalid Input.Enter again: ";
							cin >> a;
						}
						if (a == 1)
						{
							cout << "Enter employeeID: ";
							int No;
							cin >> No;
							cout << "Enter 5 character courseID";
							char* courseID = new char[5];
							cin.getline(courseID, 5);
							assignCourseToATeacher(No, courseID);
						}
						else if (a == 2)
						{
							RegisterCourseForAStudent();
						}
						else if (a == 3)
						{
							UnregisterCourseForAStudent();
						}
						else if (a == 4)
						{
							cout << "Enter 5 character courseID";
							char* courseID = new char[5];
							cin.getline(courseID, 5);
							ViewGrades(courseID);
						}
						else if (a == 5)
						{
							flag = 0;
						}
					}
				}
			}
		}
		return false;
	
	}
	bool TAmenu(int rollNo)
	{
		for (int i = 0; i < currentstudents; i++)
		{
			if (studentlist[i][0].getRollNo() == rollNo)
			{
				bool check = studentlist[i][0].checkTA();;
				if (check)
				{
					bool flag=0;
					while (flag)
					{
						cout << "1.Manage Evaluations" << endl;
						cout << "2.Logout" << endl;
						int a;
						cin >> a;
						while (a > 2 || a <= 0)
						{
							cout << "Invalid Input.Error again: ";
							cin >> a;
						}
						if (a == 1)
						{
							char* name=new char[25];
							cout << "Enter the teacher's name whose TA you are"<< endl;
							cin.getline(name,25);
							for (int i = 0; i < currentteachers; i++)
							{
								if (teacherlist[i][0].FirstName() == name)
								{
									teacherlist[i][0].ManageEvaluations();
								}
							}
						}
						else if (a == 2)
						{
							return false;
						}
					}
				}
				else
				{
					cout << "No TA of this username Exist" << endl;
					return false;
				}
			}
		}
	}
	~Department()
	{
		delete[]departmentname;
		for (int i = 0; i < currentcourses; i++)
		{
			delete[]courselist[i];
		}
		delete[]courselist;
		for (int i = 0; i < currentstudents; i++)
		{
			delete[]studentlist[i];
		}
		delete[]studentlist;
		for (int i = 0; i < currentteachers; i++)
		{
			delete[]teacherlist[i];
		}
		delete[]teacherlist;
	}
};
