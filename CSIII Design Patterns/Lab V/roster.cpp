//
//  roster.cpp
//  Class Roster
//
//  Created by Emil Shirima on 2/19/16.
//  Copyright � 2016 Emil Shirima. All rights reserved.
//
#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <iterator>
#include <map>

using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move; using std::cin;
using std::transform; using std::setw;
using std::istringstream; using std::istream_iterator;
using std::ostream_iterator; using std::to_string;
using std::multimap; using std::pair;
using std::iterator;

const string dropOutFileNamingFormat = "droupouts";
const string fileFormat = "csX";
const size_t dropOutLength = dropOutFileNamingFormat.length();
const size_t fileNameLength = fileFormat.length();

void convertToUpper(string& fileName)
{
    fileName = fileName.substr(0, fileName.find('.'));
    transform(fileName.begin(), fileName.end(), fileName.begin(), toupper); // converts the course name to uppercase
}

// reading a list from a fileName
void readRoster(list<string>& roster, string fileName, multimap<string, list<string>>& studentMap)
{
    ifstream courseName(fileName);
    convertToUpper(fileName);
    
    string firstName, secondName, fullName;
    
    while (courseName >> firstName >> secondName)
    {
        list<string> studentCourses;
        fullName = firstName + ' ' + secondName;
        studentCourses.push_back(fileName);
        //roster.push_back(fullName + ' ' + fileName);
        studentMap.insert(pair<string, list<string>>(fullName, studentCourses));
    }
    
    courseName.close();
}

// reading a list from a fileName
void readRoster(list<string>& roster, string fileName)
{
    ifstream courseName(fileName);
    convertToUpper(fileName);
    
    string firstName, secondName, fullName;
    
    while (courseName >> firstName >> secondName)
    {
        fullName = firstName + ' ' + secondName;
        roster.push_back(fullName);
    }
    
    courseName.close();
}

// Attaches identical keys to a single list
void removeMapDuplicates(multimap<string, list<string>>& allStudents)
{
    multimap<string, list<string>>::iterator mapIterator = allStudents.begin();
    
    // mapIterator should not reach the last element
    for (; mapIterator != std::prev(allStudents.end()); ++mapIterator)
    {
        std::multimap<string, list<string>>::iterator tempIterator = std::next(mapIterator, 1);
        
        while (mapIterator->first == tempIterator->first)
        {
            std::multimap<string, list<string>>::iterator tempHolder = tempIterator;
            mapIterator->second.splice(mapIterator->second.end(), tempIterator->second);
            ++tempIterator;
            allStudents.erase(tempHolder);
        }
    }
}

void removeStudentsFromClass(multimap<string, list<string>>& allStudents, list<string>&dropOuts)
{
    for (auto dropStudent : dropOuts)
    {
        allStudents.erase(allStudents.find(dropStudent));
    }
    
    dropOuts.clear();
}

void printRoster(multimap<string, list<string>> allCurrentStudents)
{
    printf("%-21s%-21s%-7s%\n", "FIRST NAME", "LAST NAME", "COURSES");
    
    for (auto& studentName : allCurrentStudents)
    {
        size_t index = studentName.first.find(' ');
        index = studentName.first.find(' ', index + 1);
        string tempStudent = studentName.first.substr(0, index);
        
        string fName = tempStudent.substr(0, tempStudent.find(' '));
        string lName = tempStudent.substr(tempStudent.find(' '), tempStudent.length());
        
        string enrolledCourse;
        
        for (auto& studentEnrolledCourses : studentName.second)
        {
            enrolledCourse += studentEnrolledCourses + " ";
        }
        
        printf("%-21s%-21s%-7s%\n", fName.c_str(), lName.c_str(), enrolledCourse.c_str());
    }
}

int main(int argc, char* argv[])
{
    
    multimap<string, list<string>> studentEntries;
    
    if (argc <= 1)
    {
    	cout << "Usage: " << argv[0]
    		<< " List of Courses, Dropouts Last" << endl; exit(1);
    }
    
    // vector of courses of students
    vector <list<string>> courseStudents;
    
    
    // reading in rosters per course and printing them out
    for (int i = 1; i < argc - 1; ++i)
    {
        list<string> roster;
        readRoster(roster, argv[i], studentEntries);
        
        courseStudents.push_back(move(roster));
        roster.clear();
    }
    
    removeMapDuplicates(studentEntries);
    
    // reading in dropouts
    list<string> dropouts;
    readRoster(dropouts, argv[argc - 1]);
    
    removeStudentsFromClass(studentEntries, dropouts);
    
    cout << endl << setw(30) << "FULL STUDENT ROSTER" << endl << endl;
    
    printRoster(studentEntries);
    
    return 0;
}
