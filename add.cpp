#include <iostream>
#include "structs.h"
#include "filePeople.cpp"
#include "structs.h"
#include <string>

using namespace std;

string requestName()
{
    string name;
    cout << "Nombre de la persona: ";
    getline(cin, name);

    if (name.length() <= 0)
    {
        system("cls");
        return requestName();
    }

    return name;
}

long long requestPhone()
{
    long long phone;
    cout << "Telefono de la persona: ";
    cin >> phone;

    if (cin.fail())
    {
        system("cls");
        cin.clear();
        cout << "El telefono no es numerico, intenta de nuevo" << endl;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return requestPhone();
    }
    return phone;
}

string requestFatherName()
{
    string fatherName;
    cout << "Apellido paterno de la persona: ";
    cin >> fatherName;

    if (cin.fail())
    {
        system("cls");
        cin.clear();
        cout << "El apellido paterno no es de tipo texto, intenta de nuevo" << endl;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return requestFatherName();
    }

    return fatherName;
}

string requestMotherName()
{
    string motherName;
    cout << "Apellido materno de la persona: ";
    cin >> motherName;

    if (cin.fail())
    {
        system("cls");
        cin.clear();
        cout << "El apellido materno no es de tipo texto, intenta de nuevo" << endl;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return requestFatherName();
    }

    return motherName;
}

Person requestPersonData()
{
    system("cls");
    Person requestedData;
    requestedData.name = requestName();
    requestedData.phone = requestPhone();
    requestedData.fatherName = requestFatherName();
    requestedData.motherName = requestMotherName();

    return requestedData;
}