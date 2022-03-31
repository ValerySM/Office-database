/* Homework : 2
Author: Valery Sokolov Morgenshteyn, ID: 336424221 */
#ifndef __MENU_H__
#define __MENU_H__

#include "MatchmakingAgency.h"

#define MAX_STRING_SIZE 100

class Menu {

public:
    Menu();

private:

    MatchmakingAgency ss;
    void PrintO() const;
    void addClient();
    void remClient();
    void printCl() const;
    void printMat();

};

#endif

