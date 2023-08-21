#include"Student.h"
#include"Course.h"
#include"Registration.h"
#include<iostream>
using namespace std;

template<class Type>
Type** shrinker(int index, Type** list, int size)
{
	Type** temp = new Type * [2];
	temp[1] = new Type[size - 1];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0, a = 0; j < size; j++, a++)
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

Student::Student()
{
	currentcourses = 0;
	totalcourses = 8;
	list = new Course*[totalcourses];
	rollNo = 0;
	TA = 0;
}
Student::Student(Student& obj)
{
	setName(obj.FirstName());
	rollNo = obj.rollNo;
	totalcourses = obj.totalcourses;
	currentcourses = obj.currentcourses;
	TA = obj.TA;
}
int Student::getCurrentCourses()
{
	return currentcourses;
}
int Student:: getRollNo()
{
	return rollNo;
}
void Student::registercourse(char const courseNum[], Registration a)
{
	if (currentcourses < totalcourses)
	{
		a.RegisterCourse(rollNo, courseNum, list, currentcourses);
	}
	else
	{
		cout << "your credit limit is full" << endl;
	}
}
bool Student::withdrawCourse(char const coursenum[])
{
	if (currentcourses > 0)
	{
		withdraw(coursenum);
	}
	cout << "Course withdawal unsuccessful" << endl;
	return false;
}
void Student::ViewAttendance()
{
	for (int i = 0; i < currentcourses; i++)
	{
		cout << "Press " << i + 1 << " for attendance of " << list[i][0].getCourseName() << endl;
	}
	int a;
	cin >> a;
	if (a >= 0 && a < currentcourses)
	{
		list[a][0].viewAttendance(rollNo);
	}
	else {
		cout << "Invalid Input" << endl;
	}
}
void Student:: makeTA()
{
	TA = 1;
}
void Student::UnregisterACourse(char* coursenum)
{
	for (int i = 0; i < currentcourses; i++)
	{
		if (list[i][0].getCourseNum() == coursenum)
		{
			delete[]list[i];
			shrinker(i, list, currentcourses);
			currentcourses--;
		}
	}
}
void Student:: withdraw(char const coursenum[])
{
	for (int i = 0; i < currentcourses; i++)
	{
		if (list[i][0].getCourseNum() == coursenum)
		{
			cout << "Course withdrawal successful" << endl;
			list[i][0].Grade(rollNo, 'W');
		}
	}
}
void Student::seeEvaluationOfaCourse()
{
	for (int i = 0; i < currentcourses; i++)
	{
		cout << "Press " << i << " to see " << list[i][0].getCourseName() << "'s Evaluations" << endl;
	}
	int a;
	cin >> a;
	if (a > 0 && a < currentcourses)
	{
		cout << "Obtained weightage of final is: " << list[a][0].getMarksofFinal(rollNo) << endl;
		cout << "Obtained weightage of Sessional is: " << list[a][0].getMarksofMid(rollNo) << endl;
		int d = list[a][0].getNumberOfCurrentAssignment();
		for (int i = 0; i < d; i++)
		{
			cout << "The obtained weightage of " << i + 1 << "st assignment is: " << list[a][0].getMarksofAssignment(rollNo, i) << endl;
		}
		int c = list[a][0].getNumberOfCurrentAssignment();
		for (int i = 0; i < c; i++)
		{
			for (int i = 0; i < d; i++)
			{
				cout << "The obtained weightage of " << i + 1 << "st quiz is: " << list[a][0].getMarksOfQuiz(rollNo, i) << endl;
			}
		}
	}
	else
	{
		cout << "press the appropriate course number" << endl;
	}
}
bool Student:: checkTA()
{
	if (TA)
	{
		return true;
	}
	return false;
}