/* Homework : 2
Author: Valery Sokolov Morgenshteyn, ID: 336424221 */
#ifndef _MATCHMAKINGAGENCY_H
#define _MATCHMAKINGAGENCY_H

#include "Client.h"
#include "VIPClient.h"
class MatchmakingAgency
{
private:

	Client** client;
	static int sum;

public:

	MatchmakingAgency();
	void SearchMatch(const MyString& s);
	~MatchmakingAgency();
	friend ostream& operator<<(ostream& os, const MatchmakingAgency& ma);
	void operator+=(Client& c);
	void operator+=(VIPClient& c);
	Client* operator-=(const MyString& s);

};

#endif



