#pragma once
#include<iostream>
using namespace std;

class Account
{
private:
	char* username;
	long password;
public:
	Account()
	{
		username = NULL;
		password = 0;
	}
	void AddAccount(char*name)
	{
		int size = strlen(name) + 2;
		username = new char[size];
		for (int i = 0; i < strlen(name); i++)
		{
			if (name[i] > 122 || name[i]<97)
			{
				if (name[i] == 32)
				{
					i++;
				}
				else
				{
					name[i] = name[i] + 32;
				}
			}
			username[i] = name[i];
		}
		username[size - 3] = '1';
		username[size - 2] = '2';
		username[size - 1] = '\0';
		password = 34566789;
	}
	char* getUsername()
	{
		return username;
	}
	void DeleteAccount(char* name)
	{
		delete[]username;
		password = 0;
	}
	void changeUsername()
	{
		cout << "Enter 15 character username: ";
		username = new char[15];
		/*for (int i = 0; i < 15; i++)
		{
			cin >> username[i];
		}*/
		cin.getline(username, 15);
	}
	void changePassword()
	{
		cout << "Enter your new 8 letters password: ";
		cin >> password;
	}
	~Account()
	{
		delete[]username;
	}
};