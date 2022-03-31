/* Homework : 2
Author: Valery Sokolov Morgenshteyn, ID: 336424221 */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h" 
#include <windows.h> 
#include <iostream>
using namespace std;

Menu::Menu() {
    bool run = 1;
    int choice;
    while (run) {
        PrintO();
        cin >> choice;
        switch (choice)
        {
        case 1:
            addClient();
            break;
        case 2:
            remClient();
            break;
        case 3:
            printCl();
            break;
        case 4:
            printMat();
            break;
        case 5: run = 0;
            ss.~MatchmakingAgency();
            break;
        default: cout << "Wrong option. Please try again!"<< endl;
        }

    }
}

void Menu::PrintO() const {
    system("cls");
    system("Color A");
    cout << "Choose from the menu:" << endl
        <<  "1. Add a new client." << endl
        <<  "2. Remove an existing client." << endl
        <<  "3. Print all clients." << endl
        <<  "4. Print all matches for a client." << endl
        <<  "5. Quit." << endl;

}

void Menu::addClient()
{

    char* Nid = new char[MAX_STRING_SIZE];
    char* Firstname = new char[MAX_STRING_SIZE];
    int Age = 0, hobbyesSumNeed = 0, hobbySum;
    char Gender, choise;
    char** hobby;

    cout << "Enter ID of a new client: " << endl;
    cin >> Nid;
    cout << "Enter name: " << endl;
    cin >> Firstname;
    system("cls");
    cout << "Enter age: " << endl;
    cin >> Age;
    if (Age < 18 || Age > 120)
    {
        cout << "Your age 25." << endl;
    }
    else
    {
        cout << "Your age: " << Age << endl;
    }

    system("cls");
    cout << "Enter your gender(for male (M) or for female (F)):" << endl;
    cin >> Gender;
    if (Gender == 'M' || Gender == 'F')
    {
        cout << Gender << endl;
    }
    else 
    {
        cout << "Enter right gender." << endl;
        cin >> Gender;



    }
    system("cls");
    cout << "Enter number of hobbyes:" << endl;
    do
    {
        cin >> hobbySum;
        if (hobbySum <= 0)
        {
            cout << "Enter right number." << endl;
            cout << "Enter number of hobbyes:" << endl;
        }
    } while (hobbySum <= 0);
    hobby = new char* [hobbySum];
    if (hobby == NULL)
    {
        exit(1);
    }
    for (int i = 0; i < hobbySum; i++)
    {
        cout << "Enter your " << i + 1 << " hobby:" << endl;
        hobby[i] = new char[MAX_STRING_SIZE];
        cin >> hobby[i];
    }
    system("cls");
    cout << "This is a VIP client? Y or N?" << endl;
    do
    {
        cin >> choise;
        if (choise == 'Y' || choise == 'N')
        {
            break;
        }
        cout << "Pleas enter  right letter." << endl;
    } while (choise != 'Y' && choise != 'N');
    if (choise == 'N')
    {
        Client* newClient = new Client(Nid, Firstname, Age, Gender, hobby, hobbySum);
        ss += *newClient;
    }
    else
    {
        cout << "Enter minimal amount of hobbyes to match:" << endl;
        do
        {
            cin >> hobbyesSumNeed;
            if (hobbyesSumNeed < 0)
            {
                cout << "Enter right number." << endl;
                cout << "Enter minimal amount of hobbyes to match:" << endl;
            }
        } while (hobbyesSumNeed < 0);
        VIPClient* newClient = new VIPClient(Nid, Firstname, Age, Gender, hobby, hobbySum, hobbyesSumNeed);
        ss += *newClient;
    }
}

void Menu::remClient()
{
    cout << "Enter the ID of the client to remove:" << endl;
    char* id = new char[MAX_STRING_SIZE];
    cin >> id;
    Client* result = ss -= id;
    if (result == NULL)
    {
        cout << "You enter wrong ID, no client was removed." << endl;
    }
    else
    {
        cout << "The client was removed." << endl;
        delete result;
    }
    delete[] id;
}

void Menu::printCl() const
{
    cout << "Client: " << ss;
}

void Menu::printMat()
{
    cout << "Enter ID of the client to find matches:" << endl;
    char* id = new char[MAX_STRING_SIZE];
    cin >> id;
    ss.SearchMatch(id);
    delete[] id;
}

