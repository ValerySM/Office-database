/* Homework : 2
Author: Valery Sokolov Morgenshteyn, ID: 336424221 */
#ifndef _VIRCLIENT_H
#define _VIPCLIENT_H
#include "Client.h"
class VIPClient :public Client
{

private:

	int hobbySumNeed;

public:

	VIPClient(MyString id, MyString Firstname, int age, char gender, char** hobbyes, int hobbySum, int hobbyesSumNeed);
	bool operator==(Client& c);

};
#endif

