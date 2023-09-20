#include <iostream>
#include <filesystem>
#include <sstream>
#include <fstream>
#include "structs.h"
#include <vector>
#include "texts.cpp"

namespace fs = std::filesystem;

// This is the filename to use on the file operations
std::string fileName = "people_1731168.txt";

bool checkIfFileExists()
{
    if (fs::exists(fileName))
    {
        return true;
    }

    return false;
}

void createCsvFile()
{
    std::ofstream outputFile(fileName);

    if (outputFile.is_open())
    {
        outputFile << "Nombre,Apellido Paterno,Apellido Materno,Telefono"
                   << "\n";
        outputFile.close();
    }
}

void addPersonIntoFile(Person data)
{
    bool isFileOnFolder = checkIfFileExists();

    if (!isFileOnFolder)
        createCsvFile();

    // Open the csv file in "append" mode to avoid overwrite the information
    std::ofstream csvFile(fileName, ios::app);

    if (csvFile.is_open())
    {
        csvFile << data.name + "," + data.fatherName + "," + data.motherName + "," + to_string(data.phone) << "\n";
        csvFile.close();
    }
}

void createCsvWithList(vector<Person> people)
{
    bool isFileOnFolder = checkIfFileExists();

    if (isFileOnFolder)
    {
        const char *fileToDelete = fileName.c_str();
        std::remove(fileToDelete);
    }

    createCsvFile();

    for (int i = 0; i < people.size(); i++)
    {
        addPersonIntoFile(people[i]);
    }
}

std::vector<Person> loadPeople()
{
    std::vector<Person> peopleFromCsv;

    bool isFileOnFolder = checkIfFileExists();

    if (!isFileOnFolder)
        return peopleFromCsv;

    string line;

    std::ifstream csvFile(fileName);

    int index = 0;

    while (std::getline(csvFile, line))
    {

        if (index != 0)
        {
            Person currentRecord;

            std::istringstream iss(line);
            std::string name, parentName, motherName, phone;

            std::getline(iss, name, ',');
            std::getline(iss, parentName, ',');
            std::getline(iss, motherName, ',');
            std::getline(iss, phone, ',');

            currentRecord.name = name;
            currentRecord.fatherName = parentName;
            currentRecord.motherName = motherName;
            currentRecord.phone = stoll(phone);

            peopleFromCsv.push_back(currentRecord);
        }

        index++;
    }

    return peopleFromCsv;
}

vector<Person> deleteRecord(vector<Person> people)
{
    system("cls");

    if(people.size()<=0){
        return people;
    }

    printCsv(people);

    int indexToDelete = requestIndexOfPerson();

    if (indexToDelete == 0)
    {
        return people;
    }

    people.erase(people.begin() + indexToDelete);

    return people;
}

void updateCsv(vector<Person> people)
{
}