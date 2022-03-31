/* Homework : 2
Author: Valery Sokolov Morgenshteyn, ID: 336424221 */
#include "MatchmakingAgency.h"
#define _CRT_SECURE_NO_WARNINGS
int MatchmakingAgency::sum = 0;


MatchmakingAgency::MatchmakingAgency()
{
	client = new Client * [1];
	client[0] = NULL;
}

void MatchmakingAgency::SearchMatch(const MyString& s)
{
	Client* target = nullptr;
	int id = 0;
	for (int i = 0; i < sum; i++)
	{
		if (s == client[i]->getNId())
		{
			target = client[i];
			id = i;
			break;
		}
	}
	for (int i = 0; i < id; i++)
	{
		if (*target == *client[i])
		{
			cout << *client[i];
		}
	}
	for (int i = id + 1; i < sum; i++)
	{
		if (*target == *client[i])
		{
			cout << *client[i];
		}
	}
	target = nullptr;
}

MatchmakingAgency::~MatchmakingAgency()
{
	for (int i = 0; i < sum; ++i)
	{
		delete client[i];
	}
	delete[] client;
	client = NULL;
	sum = 0;
}

void MatchmakingAgency::operator+=(VIPClient& c)
{
	sum++;
	Client** clients1 = new Client * [sum];
	for (int i = 0; i < sum - 1; i++)
	{
		clients1[i] = client[i];
	}
	clients1[sum - 1] = new VIPClient(c);
	for (int i = 0; i < sum - 1; i++)
	{
		client[i] = nullptr;
	}
	client = new Client * [sum];
	client = clients1;
	clients1 = nullptr;
}
void MatchmakingAgency::operator+=(Client& c)
{
	sum++;
	Client** client1 = new Client * [sum];
	for (int i = 0; i < sum - 1; i++)
	{
		client1[i] = client[i];
	}
	client1[sum - 1] = new Client(c);
	for (int i = 0; i < sum - 1; i++)
	{
		client[i] = nullptr;
	}
	client = new Client * [sum];
	client = client1;
	client1 = nullptr;
}
Client* MatchmakingAgency::operator-=(const MyString& s)
{
	Client* target = nullptr;
	int idCounter = 0;
	for (int i = 0; i < sum; i++)
	{
		if (s == client[i]->getNId())
		{
			target = client[i];
			idCounter = i;
			break;
		}
	}
	if (target == nullptr)
	{
		return NULL;
	}
	for (int i = idCounter; i < sum; i++)
	{
		if (i == sum - 1)
		{
			client[i] = nullptr;
		}
		else
		{
			client[i] = client[i + 1];
		}
	}
	--sum;
	return target;
}
ostream& operator<<(ostream& os, const MatchmakingAgency& ma)
{
	for (int i = 0; i < ma.sum; i++)
	{
		cout << *(ma.client[i])<< endl;
	}
	return os;
}

