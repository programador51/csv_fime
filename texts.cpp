#include <iostream>
#include "structs.h"
#include <vector>

using namespace std;

int requestIndexOfPerson()
{
    int indexToDelete;

    cout << "Escribe el numero de la persona que deseas operar (0 para cancelar): ";
    cin >> indexToDelete;

    return indexToDelete;
}

void printCsv(vector<Person> people)
{
    for (int i = 0; i < people.size(); i++)
    {
        cout << "[" + to_string(i + 1) + "] - " + people[i].name + " " + people[i].fatherName + " " + people[i].motherName + " | Tel: " + to_string(people[i].phone) << endl;
    }
}

void printCsvOnConsole(vector<Person> people)
{
    system("cls");
    cout << "------------------------------------------------" << endl;
    printCsv(people);
    cout << "------------------------------------------------" << endl;

    cout << "Presiona cualquier tecla para continuar...";
    string dummy;
    cin >> dummy;
}