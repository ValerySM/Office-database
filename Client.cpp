/* Homework : 2
Author: Valery Sokolov Morgenshteyn, ID: 336424221 */
#define _CRT_SECURE_NO_WARNINGS
#include "Client.h"


Client::Client(MyString Nid, MyString Firstname, int Age, char Gender, char** hobby, int hobbySum)
{
	this->Nid = Nid;
	this->Firstname = Firstname;
	this->Gender = Gender;
	this->Age = Age;

	if (hobby == NULL)
	{
		exit(1);
	}
	else
	{
		this->hobby = new char* [hobbySum];
		for (int i = 0; i < hobbySum; i++)
		{
			this->hobby[i] = new char[strlen(hobby[i]) + 1];
			strcpy(this->hobby[i], hobby[i]);
		}
		this->hobbySum = hobbySum;
	}

}

Client::Client(const Client& c)
{

	this->Nid = c.Nid;
	this->Firstname = c.Firstname;
	this->Gender = c.Gender;
	this->Age = c.Age;
	this->hobbySum = c.hobbySum;
	this->hobby = new char* [hobbySum];
	for (int i = 0; i < hobbySum; i++)
	{
		this->hobby[i] = new char[strlen(c.hobby[i]) + 1];
		strcpy(this->hobby[i], c.hobby[i]);
	}
}

Client::~Client()
{
	Nid.~MyString();
	Firstname.~MyString();
	for (int i = 0; i < hobbySum; i++)
	{
		delete[] hobby[i];
	}
	delete[] hobby;
}

bool Client::operator==(Client& c)
{
	int counter = 0;
	if ((Gender == 'M' && c.Gender == 'F') || (Gender == 'F' && c.Gender == 'M'))
	{
		if ((Age - c.Age <= 5) || (Age - c.Age >= -5))
		{
			for (int i = 0; i < c.hobbySum; i++)
			{
				for (int j = 0; j < hobbySum; j++)
				{
					if (strCheck(c.hobby[i], hobby[j]) == true)
					{
						++counter;
						break;
					}
				}
			}
			if (counter >= 1)
			{
				return true;
			}
		}
	}
	return false;
}
ostream& operator<<(ostream& os, const Client& c)
{
	os << endl << "ID: " << c.Nid << endl << "Name: " << c.Firstname << endl << "Age: " << c.Age << endl << "Gender: " << c.Gender << endl << "Hobbyes: " << endl;
	for (int i = 0; i < c.hobbySum; i++)
	{
		cout << c.hobby[i] << endl;
	}
	return os;
}

bool Client::strCheck(char* s1, char* s2)
{

	int str1 = strlen(s1);
	int str2 = strlen(s2);
	if (str1 == str2)
	{
		int counter = 0;
		for (int i = 0; i < str1; ++s1, ++s2, ++i)
		{
			if (*s1 == *s2)
				++counter;
		}
		if (counter == str1)
		{
			return true;
		}
	}
	return false;
}