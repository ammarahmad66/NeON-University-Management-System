#pragma once
#include <iostream>
using namespace std;

class Person
{
private:
	char* firstName;
public:
	Person()
	{
		firstName = 0;

	}
	Person(const char fname[])
	{
		firstName = new char[strlen(fname)+1];
		for (int i = 0; i < strlen(fname); i++)
		{
			firstName[i] = fname[i];
		}
		firstName[strlen(fname)] = '\0';
	
	}
	virtual char* FirstName()
	{
		return firstName;
	}
	virtual void setName(char *name)
	{
		firstName = new char[strlen(name)+1];
		for (int i = 0; i < strlen(name); i++)
		{
			firstName[i] = name[i];
		}
		firstName[strlen(name)] = '\0';
	}
	virtual void printinformation()
	{
		cout << firstName << " ";
	}
	~Person()
	{
		delete[]firstName;
	}
};
