/* Homework : 2
Author: Valery Sokolov Morgenshteyn, ID: 336424221 */
#pragma once
#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;

class MyString
{

private:

	char* str;

public:

	MyString(const char* s = NULL);
	MyString(const MyString& s);
	MyString& operator=(const char* s);
	MyString& operator=(const MyString& s);
	bool operator==(const MyString& s)const;
	~MyString();
	friend ostream& operator<<(ostream& os, const MyString& s);

};
#endif
