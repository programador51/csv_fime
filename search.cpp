#include <iostream>
#include <vector>
#include "structs.h"

enum CriteriaSearch
{
    parentName,
    motherName
};

vector<Person> searchBy(string search, CriteriaSearch criteria, vector<Person> people)
{
    vector<Person> results;

    

    for (int i = 0; i < people.size(); i++)
    {
        // Searched by parent name and results match
        if (criteria == parentName && people[i].fatherName == search)
        {
            results.push_back(people[i]);
        }

        // Searched by mother name and results match
        if (criteria == motherName && people[i].motherName == search)
        {
            results.push_back(people[i]);
        }
    }
    cout << "---------------------------------------" << endl;
    cout << "Busqueda encontrada" << endl;
    printCsv(results);

    cout << "---------------------------------------" << endl;

    cout << "Presiona cualquier tecla para continuar..." << endl;
    string dummyData;
    cin >> dummyData;

    return results;
}