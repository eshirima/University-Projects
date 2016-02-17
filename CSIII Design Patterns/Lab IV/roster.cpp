// vector and list algorithms
// Mikhail Nesterenko
// 3/11/2014

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>

using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move;

string dropOut = "droupouts.txt";
string fileNames = "csX.txt";
const int dropOutLength = dropOut.length();
const int fileNameLength = fileNames.length();

// reading a list from a fileName
void readRoster(list<string>& roster, string fileName)
{
    ifstream courseName(fileName);
    
    string firstName, secondName;
    
    while (courseName >> firstName >> secondName)
    {
        roster.push_back(firstName + ' ' + secondName + ' ' + fileName);
    }
    
    courseName.close();
}

// printing a list out
void printRoster(const list<string>& roster)
{
    for (const auto& studentName : roster)
    {
        cout << studentName << endl;
    }
}

void removeDuplicates(list<string>& roster)
{
    for (list<string>::iterator it = roster.begin(); it != roster.end(); ++it)
    {
        if (it != roster.end())
        {
            list<string>::iterator temp = ++it;
            string firstString = *it;
            string secondString = *temp;
            
            if (firstString.substr(0, fileNameLength - 1) == secondString.substr(0, fileNameLength - 1))
            {
                firstString = firstString + ' ' + secondString.substr(secondString.length() - fileNameLength, secondString.length());
                roster.remove(*temp);
            }
        }
        else
        {
            break;
        }
    }
}

int main(int argc, char* argv[]){
    
    if (argc <= 1){ cout << "usage: " << argv[0] << " list of courses, dropouts last" << endl; exit(1);}
    
    vector <list<string>> courseStudents; // vector of courses of students
    
    // reading in rosters per course and printing them out
    for(int i=1; i < argc-1; ++i)
    {
        list<string> roster;
        readRoster(roster, argv[i]);
        cout << "\n\n" << argv[i] << "\n";
        printRoster(roster);
        // std::move places roster into courseStudents without copying
        courseStudents.push_back(move(roster));
        roster.clear();
    }
    
    // reading in dropouts
    list<string> dropouts;
    readRoster(dropouts, argv[argc-1]);
    cout << "\n\n dropouts \n"; printRoster(dropouts);
    
    
    list<string> allStudents;  // master list of students
    for(const auto& lst : courseStudents) // inserting individual courses
        allStudents.insert(allStudents.end(), lst.begin(), lst.end());
    cout << "\n\n all students unsorted \n"; printRoster(allStudents);
    
    allStudents.sort(); // sorting master list
    cout << "\n\n all students sorted \n"; printRoster(allStudents);
    
    removeDuplicates(allStudents);
    cout << "\n\n all student duplicates removed \n"; printRoster(allStudents);
    
    //TODO: Find the duplicates then remove them
//    for (const auto& str : dropouts)  // removing individual dropouts
//        allStudents.remove(str.substr(0, dropOutLength - 1));
//    cout << "\n\n all students, dropouts removed \n"; printRoster(allStudents);
    
//    allStudents.unique(); // eliminating duplicates
//    cout << "\n\n all students, duplicates removed \n"; printRoster(allStudents);
}