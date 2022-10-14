#include "player.h"
#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;

// below is currently member due to permissions later
string player::generateName(string firstNamePath, string lastNamePath)
{
    string firstName, lastName;
    int totalLines = 0;
    ifstream fileAccess;
    fileAccess.open(firstNamePath);
    while (!fileAccess.eof())
    {
        totalLines++;
    }
    if (totalLines == 0)
    {
        return "Error in first name file";
    }

    int randomValue = rand() % totalLines;

    fileAccess.clear();
    fileAccess.seekg(randomValue);
    getline(fileAccess, firstName);
    fileAccess.close();

    fileAccess.open(lastNamePath);
    fileAccess.clear();
    while (!fileAccess.eof())
    {
        totalLines++;
    }
    if (totalLines == 0)
    {
        return "Error in last name file";
    }
    randomValue = rand() % totalLines;

    fileAccess.seekg(randomValue);
    getline(fileAccess, lastName);
    fileAccess.close();

    return firstName + lastName;
}
