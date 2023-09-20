#include <iostream>
#include <vector>
#include "structs.h"

using namespace std;

vector<Person> attemptUpdatePerson(vector<Person> people)
{
    system("cls");

    if(people.size()<=0){
        return people;
    }

    printCsv(people);

    int indexToUpdate = requestIndexOfPerson();

    if (indexToUpdate == 0)
    {
        return people;
    }

    Person newDataPerson = requestPersonData();

    people.at(indexToUpdate-1) = newDataPerson;

    return people;
}