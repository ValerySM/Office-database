/* Homework : 2
Author: Valery Sokolov Morgenshteyn, ID: 336424221 */
#ifndef _CLIENT_H
#define _CLIENT_H
#include "MyString.h"
class Client
{

private:

	MyString Nid, Firstname;
	int Age, hobbySum;
	char Gender;
	char** hobby;

public:

	Client(MyString Nid = "12345678", MyString Firstname = "User", int Age = 35, char Gender = 'M', char** hobby = NULL, int hobbySum = 0);
	Client(const Client& c);
	~Client();
	MyString& getNId() { return Nid; }
	MyString& getFirstname() { return Firstname; }
	int getAge() { return Age; }
	char getGender() { return Gender; }
	char** getHobby() { return hobby; }
	int gethobbysum() { return hobbySum; }
	bool strCheck(char* s1, char* s2);
	friend ostream& operator<<(ostream& os, const Client& c);
	virtual bool operator==(Client& c);

};
#endif

#pragma once
