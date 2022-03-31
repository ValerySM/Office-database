/* Homework : 2
Author: Valery Sokolov Morgenshteyn, ID: 336424221 */
#include "VIPClient.h"

VIPClient::VIPClient(MyString Nid, MyString Firstname, int Age, char Gender, char** hobby, int hobbySum, int hobbySumNeed) :Client(Nid, Firstname, Age, Gender, hobby, hobbySum)//transfering data to build regular client part
{
	if (hobbySumNeed >= 1 && hobbySumNeed <= hobbySum)
	{
		this->hobbySumNeed = hobbySumNeed;
	}
	else
	{
		this->hobbySumNeed = 1;
	}
}

bool VIPClient::operator==(Client& c)
{
	if ((getGender() == 'M' && c.getGender() == 'F') || (getGender() == 'F' && c.getGender() == 'M'))
	{
		if ((getAge() - c.getAge() <= 5) || (getAge() - c.getAge() >= -5))
		{
			int counter = 0;
			int sourceHobbySum = gethobbysum();
			int newHobbySum = c.gethobbysum();
			for (int i = 0; i < sourceHobbySum; i++)
			{
				for (int j = 0; j < newHobbySum; j++)
				{
					if (strCheck(getHobby()[i], c.getHobby()[j]) == true)
					{
						++counter;
						break;
					}
				}
			}
			if (counter >= hobbySumNeed)
			{
				return true;
			}
		}
	}
	return false;
}


