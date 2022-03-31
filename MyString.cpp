/* Homework : 2
Author: Valery Sokolov Morgenshteyn, ID: 336424221 */
#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"

MyString::MyString(const char* s)
{
	if (s == NULL)
	{
		this->str = new char[1];
		this->str[0] = '\0';
	}
	else
	{
		this->str = new char[strlen(s) + 1];
		strcpy(this->str, s);
	}
}

MyString::MyString(const MyString& s)
{
	str = new char[strlen(s.str) + 1];
	strcpy(str, s.str);
}

MyString::~MyString()
{
	delete[] str;
	str = nullptr;
}

MyString& MyString::operator=(const char* s)
{
	if (s == NULL)
	{
		this->str = new char[1];
		this->str[0] = '\0';
	}
	else
	{
		this->str = new char[strlen(s) + 1];
		strcpy(this->str, s);
	}
	return *this;
}

MyString& MyString::operator=(const MyString& s)
{
	str = new char[strlen(s.str) + 1];
	strcpy(str, s.str);
	return *this;
}
ostream& operator<<(ostream& os, const MyString& s)
{
	cout << s.str;
	return os;
}

bool MyString::operator==(const MyString& s) const
{
	int counter = 0;
	for (int i = 0; i < strlen(s.str); i++)
	{
		if (str[i] == s.str[i])
		{
			++counter;
		}
	}
	if (counter == strlen(s.str))
	{
		return true;
	}
	return false;
}



