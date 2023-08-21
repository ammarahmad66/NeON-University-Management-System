#pragma once
#include"Student.h"
#include<iostream>
using namespace std;


class TA;
class Department;
class Student;
class Registration;
class Course
{
private:
	int** attendance;
	int attendancecount;
	char* courseNum;     //5 character courseID
	char* courseName;
	char *grade;
	float** quiz;
	float** assignment;
	int currentquizzes;
	int currentassignment;
	float** Mid;
	float** final;
	int totalweightage;
	int quizweightage;
	int Midweightage;
	int Assignmentweightage;
	int Finalweightage;
	int registeredinthiscourse;
	Student** std_InaSpecificCourse;
	int midcount;   
	int finalcount;  
	int gradecount;

public:
	Course()
	{
		attendance = NULL;
		courseNum = NULL;
		courseName = NULL;
		grade = NULL;
		currentquizzes = 1;
		currentassignment=1;
		totalweightage = 100;
		quizweightage = 15;
		Midweightage= 20;
		Assignmentweightage = 10;
		Finalweightage = 55;
		std_InaSpecificCourse = new Student*[50];
		attendancecount = 1;
		midcount = 1;    //can't be more than 2
		finalcount = 1;     //can't be more than one 2
		gradecount=0;
	}
	Course(char *name, char* ID)
	{
		courseName = new char[strlen(name) + 1];
		for (int i = 0; i < strlen(name); i++)
		{
			courseName[i] = name[i];
		}
		courseName[strlen(name)] = '\0';
		courseNum = new char[strlen(ID) + 1];
		for (int i = 0; i < strlen(ID); i++)
		{
			courseName[i] = ID[i];
		}
		courseName[strlen(ID)] = '\0';
	}
	Course(Course& obj)
	{
		courseName = new char[strlen(obj.courseName)+1];
		for (int i = 0; i < strlen(obj.courseName); i++)
		{
			courseName[i] = obj.courseName[i];
		}
		courseName[strlen(obj.courseName)] = '\0';
		courseNum = new char[strlen(obj.courseNum) + 1];
		for (int i = 0; i < strlen(obj.courseNum); i++)
		{
			courseNum[i] = obj.courseNum[i];
		}
		courseNum[strlen(courseNum)] = '\0';
	}
	void setCourse(Course& obj)
	{
		courseName = new char[strlen(obj.courseName) + 1];
		for (int i = 0; i < strlen(obj.courseName); i++)
		{
			courseName[i] = obj.courseName[i];
		}
		courseName[strlen(obj.courseName)] = '\0';
		courseNum = new char[strlen(obj.courseNum) + 1];
		for (int i = 0; i < strlen(obj.courseNum); i++)
		{
			courseNum[i] = obj.courseNum[i];
		}
		courseNum[strlen(courseNum)] = '\0';
	}
	float* grow(int size, float* arr)
	{
		float* temp = new float[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		delete[]arr;
		arr = temp;
		return arr;
	}
	char* getCourseNum()
	{
		return courseNum;
	}
	char* getCourseName()
	{
		return courseName;
	}
	void setCourseName(char* name)
	{
		courseName = new char[strlen(name) + 1];
		for (int i = 0; i < strlen(name); i++)
		{
			courseName[i] = name[i];
		}
		courseName[strlen(name)] = '\0';
	}
	void setCourseNum(char* num)
	{
		courseNum = new char[strlen(num) + 1];
		for (int i = 0; i < strlen(num); i++)
		{
			courseNum[i] = num[i];
		}
		courseNum[strlen(num)] = '\0';
	}
	void setGrade(int index,char a)
	{
		grade[index] = a;
	}
	void Initializer(float** arr,int size)
	{
		arr = new float* [size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = new float[1];
		}
		for (int j = 0; j < size; j++)
		{
			arr[j][0] = std_InaSpecificCourse[j]->getRollNo();
		}
	}
	void evaluate(float**arr,int index)     //for entering the marks of evluations
	{
		for (int i = 0; i < registeredinthiscourse; i++)
		{
			arr[i]=grow(index, arr[i]);
			cout << "Enter weightage obtained by " << std_InaSpecificCourse[i]->getRollNo() << " :";
			float a;
			cin >> a;
			arr[i][index] = a;
		}
	}
	void ModifyEvaluation(int rollNo,float**arr,int size)    //for modifying evaluation
	{
		for (int i = 0; i < registeredinthiscourse; i++)
		{
			if (arr[i][0] == rollNo)
			{
				if (size > 1)
				{
					for (int j = 1; j < size; j++)
					{
						cout << "Enter " << j << " for modifying " << j << "st evaluation's weightage" << endl;
					}
					int a;
					cin >> a;
					if (a > (size - 1) || a < 0)
					{
						cout << "Invalid Input.Enter again: ";
						cin >> a;
					}
					else {
						cout << "Enter the Modified weightage : "  ;
						cin >> arr[i][a];
					}
				}
				else
				{
					cout << "No evaluation entered yet" << endl;
				}
			}
		}
	}
	void View(float** arr,int size)      //for teacher to view evaluations
	{
		try {
			if (size <= 1)
				throw 0;
			cout << "Following is the performance of students in this evaluation " << endl;
			for (int i = 0; i < registeredinthiscourse; i++)
			{
				cout << "Student " << (i + 1) << " " << std_InaSpecificCourse[i][0].getRollNo() << endl;
				for (int j = 1; j < size; j++)
				{
					cout << "Obtained weightage in "<< j << "st is: " << arr[i][j] << endl;
				}
			}
		}
		catch (int) {
			cout << "No evaluation entered yet" << endl;
		}
	}
	void InitializeAttendance()
	{
		attendance = new int* [registeredinthiscourse];
		for (int i = 0; i < registeredinthiscourse; i++)
		{
			attendance[i] = new int[29];
		}
		for (int i = 0; i < registeredinthiscourse; i++)
		{
			attendance[i][0] = std_InaSpecificCourse[i][0].getRollNo();
		}
	}
	void MarkAttendance()
	{
		cout << "Press 0 for absent and 1 for present" << endl;
		cout << "Mark Attendance " << attendancecount<<" of this course"<<endl;
		for (int i = 0; i < registeredinthiscourse; i++)
		{
			cout << "Attendance of " << std_InaSpecificCourse[i][0].getRollNo() << " ";
			int a;
			cin >> a;
			attendance[i][attendancecount] = a;
		}
		attendancecount++;
	}
	void viewAttendance(int rollNo)
	{
		bool flag = 1;
		for (int i = 0; i < registeredinthiscourse; i++)
		{
			if (attendance[i][0] == rollNo)
			{
				if (attendancecount > 1)
				{
					float c, a = 0;
					c = 1 / attendancecount;
					for (int j = 1; j < attendancecount; j++)
					{
						cout << j << "st lecture attendance : " << attendance[i][j] << endl;
						if (attendance[i][j] == 1)
						{
							a = a + c;
						}
					}
					a = a * 100;
					cout << "Attendance Percentage : " << a << "%" << endl;
				}
				else
				{
					cout << "No attendance recorded yet" << endl;
				}
				i = registeredinthiscourse;
				flag = 1;
			}
			else
			{
				flag = 0;
			}
		}
		if (!flag)
		{
			cout << "Enter a valid Roll Number" << endl;
		}
	}
	void ModifyAttendance(int rollNo)
	{
		bool flag = 0;
		for (int i = 0; i < registeredinthiscourse; i++)
		{
			if (attendance[i][0] == rollNo)
			{
				if (attendancecount > 1)
				{
					for (int j = 1; j < attendancecount; j++)
					{
						cout <<"Press "<<j<< "for modifiying the Attendance of Lecture " << i << " which is : " << attendance[i][j] << endl;
					}
					int d;
					cin >> d;
					cout << "Enter the the attendance of Lecture " << d << endl;
					cin >> attendance[i][d];
				}
				else {
					cout << "No attendance recorded yet" << endl;
				}
				i = registeredinthiscourse;
				flag = 1;
			}
			else {
				flag = 0;
			}
		}
		if (flag)
		{
			cout << "Enter a valid roll number" << endl;
		}
		
	}
	float getMarksofFinal(int rollNo)
	{
		for (int i = 0; i < registeredinthiscourse; i++)
		{
			if (final[i][0] == rollNo)
			{
				return final[i][1];
			}
		}
		
	}
	float getMarksofMid(int rollNo)
	{
		for (int i = 0; i < registeredinthiscourse; i++)
		{
			if (Mid[i][0] == rollNo)
			{
				return Mid[i][1];
			}
		}
	}
	float getMarksOfQuiz(int rollNo,int a)
	{
		for (int i = 0; i < registeredinthiscourse; i++)
		{
			if (quiz[i][0] == rollNo)
			{
				return quiz[i][a];
			}
		}
	}
	float getMarksofAssignment(int rollNo,int a)
	{
		for (int i = 0; i < registeredinthiscourse; i++)
		{
			if (assignment[i][0] == rollNo)
			{
				return assignment[i][a];
			}
		}
	}
	void Grade(int rollNo, char a)     //For student to withdraw a course
	{
		if (gradecount == 0)
		{
			grade = new char[registeredinthiscourse];
			gradecount++;
		}
		for (int i = 0; i < registeredinthiscourse; i++)
		{
			if (i == rollNo)
			{
				i++;
			}
			setGrade(i, 'I');
		}
		for (int i = 0; i < registeredinthiscourse; i++)
		{
			if (std_InaSpecificCourse[i][0].getRollNo() == rollNo)
			{
				setGrade(i, a);
			}
		}
	}
	int getNumberOfCurrentQuiz()
	{
		return (currentquizzes-1);
	}
	int getNumberOfCurrentAssignment()
	{
		return (currentassignment-1);
	}
	void RegistrationOfAStudent(Student* obj)
	{
		std_InaSpecificCourse[registeredinthiscourse] = new Student[1];
		std_InaSpecificCourse[registeredinthiscourse++]=obj;
	}
	int getStudentCountInACoure()
	{
		return registeredinthiscourse;
	}
	float GrandTotal(int rollNo)
	{
		float c=0; 
		for (int i = 0; i < registeredinthiscourse; i++)
		{
			if (quiz[i][0] == rollNo)
			{
				for (int j = 1; j < currentquizzes; j++)
				{
					c = c + quiz[i][j];
				}
				for (int j = 1; j < currentassignment; j++)
				{
					c = c + assignment[i][j];
				}
				if (midcount == 2)
				{
					c = c + Mid[i][1];
					if (finalcount == 2)
					{
						c = c + final[i][1];
					}
				}
				
			}
		}
		return c;
	}
	void IncrementGradeCount()
	{
		gradecount++;
	}
	void AssignGrades()
	{
		if (gradecount == 0)
		{
			grade = new char[registeredinthiscourse];
		}
		for (int i = 0; i < registeredinthiscourse; i++)
		{
			if (grade[i] = 'W')
			{
				i++;
			}
			else
			{
				cout << "Grand Total of " << std_InaSpecificCourse[i][0].getRollNo() << " is :";
				GrandTotal(std_InaSpecificCourse[i][0].getRollNo());
				char a;
				cout << "Enter the letter grade of the student : ";
				cin >> a;
				while (a == 'A' || a == 'B' || a == 'C' || a == 'D' || a == 'F')
				{
					cout << "Invalid grade.Enter again" << endl;
					cin >> a;
				}
				setGrade(i, a);
			}
		}
	}
	void seeGrades()
	{
		if (gradecount > 0)
		{
			for (int i = 0; i < registeredinthiscourse; i++)
			{
				cout << std_InaSpecificCourse[i][0].getRollNo() << "'s grade: " << grade[i];
			}
		}
		else {
			cout << "Grades are not assigned yet" << endl;
		}
	}
	void getGrade(int rollNo)
	{
		if (gradecount > 0)
		{
			for (int i = 0; i < registeredinthiscourse; i++)
			{
				if (std_InaSpecificCourse[i][0].getRollNo() == rollNo)
				{
					cout<< grade[i];
				}
			}
		}
		else
		{
			cout << "Grade is not assigned yet" << endl;
		}
	}
	void Evaluations()
	{
		cout << "1.Mark/View Quizzes" << endl;
		cout << "2.Mark/View Assignments" << endl;
		cout << "3.Mark/View Mid" << endl;
		cout << "4.Mark/View Final" << endl;
		int a;
		cin >> a;
		if(a>4||a<=0){
			cout << "Invalid Input.Enter Again: ";
			cin >> a;
		}
		else if (a == 1)
		{
			cout << "1.Enter Numbers" << endl;
			cout << "2.Modify Numbers" << endl;
			cout << "3.View Numbers" << endl;
			int d;
			cin >> d;
			if (d > 3 || d <= 0)
			{
				cout << "Invalid Input.Enter Again: ";
				cin >> d;
			}
			else if (d == 1)
			{
				Initializer(quiz,registeredinthiscourse);
				cout << "Enter Weightage obtained by students in quiz " << currentquizzes << " of this course" << endl;
				evaluate(quiz, currentquizzes);
				currentquizzes++;
			}
			else if (d == 2)
			{
				cout << "Enter the Roll Number of a student whose quiz marks you want to modify : ";
				int rollNo;
				cin >> rollNo;
				ModifyEvaluation(rollNo,quiz,currentquizzes);
			}
			else if (d == 3)
			{
				View(quiz,currentquizzes);
			}
		}
		else if (a == 2)
		{
			cout << "1.Enter Numbers" << endl;
			cout << "2.Modify Numbers" << endl;
			cout << "3.View Numbers" << endl;
			int d;
			cin >> d;
			if (d > 3 || d < 0)
			{
				cout << "Invalid Input.Enter Again: ";
				cin >> d;
			}
			else if (d == 1)
			{
				Initializer(assignment, registeredinthiscourse);
				cout << "Enter Weightage obtained by students in assignment " << currentassignment << " of this course" << endl;
				evaluate(assignment, currentassignment);
				currentassignment++;
			}
			else if (d == 2)
			{
				cout << "Enter the Roll Number of a student whose asssignment marks you want to modify : ";
				int rollNo;
				cin >> rollNo;
				ModifyEvaluation(rollNo, assignment, currentassignment);
			}
			else if (d == 3)
			{
				View(assignment, currentassignment);
			}
		}
		else if (a == 3)
		{
			cout << "1.Enter Numbers" << endl;
			cout << "2.Modify Numbers" << endl;
			cout << "3.View Numbers" << endl;
			int d;
			cin >> d;
			if (d > 3 || d <= 0)
			{
				cout << "Invalid Input.Enter Again: ";
				cin >> d;
			}
			else if (d == 1)
			{
				try {
					if (midcount >= 2)
						throw 0;
					Initializer(Mid, midcount);
					cout << "Enter the weightage Obtained by students in sessional" << endl;
					evaluate(Mid, midcount);
					midcount++;
				}
				catch (int)
				{
					cout << "You can only modify and view the marks because the numbers are already entered once" << endl;
				}
			}
			else if (d == 2)
			{
				cout << "Enter the Roll Number of a student whose sessional marks you want to modify : ";
				int rollNo;
				cin >> rollNo;
				ModifyEvaluation(rollNo, Mid, midcount);
			}
			else if (d == 3)
			{
				View(Mid, midcount);
			}
		}
		else if (a == 4)
		{
			cout << "1.Enter Numbers" << endl;
			cout << "2.Modify Numbers" << endl;
			cout << "3.View Numbers" << endl;
			int d;
			cin >> d;
			if (d > 3 || d <= 0)
			{
				cout << "Invalid Input.Enter Again: ";
				cin >> d;
			}
			else if (d == 1)
			{
				try {
					if (finalcount >= 2)
						throw 0;
					Initializer(final, finalcount);
					cout << "Enter the weightage Obtained by students in sessional" << endl;
					evaluate(final, finalcount);
					finalcount++;
				}
				catch (int)
				{
					cout << "You can only modify and view the marks because the numbers are already entered once" << endl;
				}
			}
			else if (d == 2)
			{
				cout << "Enter the Roll Number of a student whose final marks you want to modify : ";
				int rollNo;
				cin >> rollNo;
				ModifyEvaluation(rollNo, final, finalcount);
			}
			else if (d == 3)
			{
				View(final, finalcount);
			}
		}
	}
	//~Course()
	//{
	//	for (int i = 0; i < attendancecount; i++)
	//	{
	//		delete[]attendance[i];
	//	}
	//	delete[]attendance;
	//	for (int i = 0; i < midcount; i++)
	//	{
	//		delete[]Mid[i];
	//	}
	//	delete[]Mid;
	//	for (int i = 0; i < finalcount; i++)
	//	{
	//		delete[]final[i];
	//	}
	//	delete[]final;
	//	for (int i = 0; i < currentquizzes; i++)
	//	{
	//		delete[]quiz[i];
	//	}
	//	delete[]quiz;
	//	for (int i = 0; i < currentassignment; i++)
	//	{
	//		delete[]assignment[i];
	//	}
	//	delete[]assignment;
	//	delete[]courseName;
	//	delete[]courseNum;
	//	delete[]grade;
	//}
};