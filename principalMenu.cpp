#include <iostream>
#include "add.cpp"
#include "structs.h"
#include "update.cpp"
#include "search.cpp"

using namespace std;

// It's important to return something different to void to re-prompt the menu once an option it's done
int displayProgramOptions()
{
    int choice;

    while (true)
    {
        std::vector<Person> csv = loadPeople();
        std::string search;

        system("cls");
        cout << "Actualmente hay " + to_string(csv.size()) + " persona(s)" << endl;
        cout << endl;
        cout << "0. Listar personas" << endl;
        cout << "1. Buscar por apellido paterno" << endl;
        cout << "2. Buscar por apellido materno" << endl;
        cout << "3. Agregar" << endl;
        cout << "4. Eliminar" << endl;
        cout << "5. Cambios" << endl;
        cout << "6. Salir" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Opcion: ";

        // Get user input
        cin >> choice;

        // Process user's choice
        switch (choice)
        {

        case 0:
            printCsvOnConsole(csv);
            break;

        case 1:
            system("cls");
            cout << "Escribe el apellido paterno: ";
            cin >> search;
            searchBy(search, parentName, csv);
            break;
        case 2:
            system("cls");
            cout << "Escribe el apellido materno: ";
            cin >> search;
            searchBy(search, motherName, csv);
            break;
        case 3:
            addPersonIntoFile(requestPersonData());
            break;

        case 4:
            csv = deleteRecord(csv);
            createCsvWithList(csv);
            break;

        case 5:
            csv = attemptUpdatePerson(csv);
            createCsvWithList(csv);
            break;

        case 6:
            cout << "Saliendo" << endl;
            return 0;

        default:
            cout << "Selecciona una opcion valida" << endl;
        }
    }

    return 0;
}