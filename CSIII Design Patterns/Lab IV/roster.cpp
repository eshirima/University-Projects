//
//  main.cpp
//  Class Roster
//
//  Created by Emil Shirima on 2/19/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
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

using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move; using std::cin;
using std::transform; using std::setw;
using std::istringstream; using std::istream_iterator;
using std::ostream_iterator;

const string dropOutFileNamingFormat = "droupouts.txt";
const string fileFormat = "csX";
const size_t dropOutLength = dropOutFileNamingFormat.length();
const size_t fileNameLength = fileFormat.length();

void convertToUpper(string& fileName)
{
    fileName = fileName.substr(0, fileName.find('.'));
    transform(fileName.begin(), fileName.end(), fileName.begin(), toupper); // converts the course name to uppercase
}

// reading a list from a fileName
void readRoster(list<string>& roster, string fileName)
{
    ifstream courseName(fileName);
    convertToUpper(fileName);
    
    string firstName, secondName;
    
    while (courseName >> firstName >> secondName)
    {
        roster.push_back(firstName + ' ' + secondName + ' ' + fileName);
    }
    
    courseName.close();
}

// MARK: Pain in the ass to get C++11 setw() to work so printf() instead
void printRoster(list<string>& roster)
{
    
    printf("%-21s%-21s%-7s%\n", "FIRST NAME", "LAST NAME", "COURSES");
    
    //TODO: FOR SOME REASON I GET A SEG FAULT WHEN I COMMENT THESE VARIABLES OUT EVEN THOUGH I NEVER USE THEM ANYWHERE :( :( ??!!
    
    string firstNameTitle = "FIRST NAME";
    string lastNameTile = "LAST NAME";
    string coursesTitle = "COURSES";
    
    for (auto& studentName : roster)
    {
        size_t index = studentName.find(' ');
        index = studentName.find(' ', index + 1);
        string tempStudent = studentName.substr(0, index);
        
        string fName = tempStudent.substr(0, tempStudent.find(' '));
        string lName = tempStudent.substr(tempStudent.find(' '), tempStudent.length());
        
        string enrolledCourse = studentName.erase(0, fName.length() + lName.length());
        
        printf("%-21s%-21s%-7s%\n", fName.c_str(), lName.c_str(), enrolledCourse.c_str());
    }
}

// Aside from removing, it also links a student to their multiple registered courses
void removeDuplicates(list<string>& roster)
{
    list<string>::iterator iterateToLastElement = roster.end();
    --iterateToLastElement; // points to the last element in the roster
    
    for (list<string>::iterator it = roster.begin(); it != roster.end(); ++it)
    {
        // makes sure that the iterator doesn't go over the last element
        if (it != iterateToLastElement)
        {
            list<string>::iterator nextIterator = std::next(it, 1);
            string currentString = *it;
            string nextString = *nextIterator;
            
            string originalTextFromNextIterator = nextString;
            
            currentString = currentString.substr(0, currentString.length() - fileNameLength - 1);
            nextString = nextString.substr(0, nextString.length() - fileNameLength - 1);
            
            while (currentString == nextString)
            {
                string fileName = originalTextFromNextIterator.substr(originalTextFromNextIterator.length() - fileNameLength, originalTextFromNextIterator.length()); // gets the fileName
                currentString = *it + ' ' + fileName;
                *it = currentString;
                ++nextIterator;
                roster.remove(originalTextFromNextIterator);
                originalTextFromNextIterator = *nextIterator;
                currentString = nextString;
                nextString = originalTextFromNextIterator.substr(0, originalTextFromNextIterator.length() - fileNameLength - 1);
            }
        }
    }
}

void removeStudentsFromClass(list<string>& allStudents, list<string>dropOuts)
{
    for (auto& dropOutStudent : dropOuts)
    {
        dropOutStudent = dropOutStudent.substr(0, dropOutStudent.length() - dropOutLength);
        
        list<string>::iterator it = allStudents.begin();
        
        while (it != allStudents.end())
        {
            string studentName = *it;
            size_t index = studentName.find(' ');
            index = studentName.find(' ', index + 1);
            studentName = studentName.substr(0, index);
            
            if (studentName == dropOutStudent)
            {
                string temp = *it;
                ++it;
                allStudents.remove(temp);
            }
            else
            {
                ++it;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    
    if (argc <= 1){ cout << "Usage: " << argv[0]
        << " List of courses, Dropouts last" << endl; exit(1);}
    
    // vector of courses of students
    vector <list<string>> courseStudents;
    
    
    // reading in rosters per course and printing them out
    for(int i=1; i < argc-1; ++i)
    {
        list<string> roster;
        readRoster(roster, argv[i]);
        
        courseStudents.push_back(move(roster));
        roster.clear();
    }
    
    // reading in dropouts
    list<string> dropouts;
    readRoster(dropouts, argv[argc - 1]);
    
    list<string> allStudents;  // master list of students
    for (const auto& lst : courseStudents) // inserting individual courses
        allStudents.insert(allStudents.end(), lst.begin(), lst.end());
    
    allStudents.sort(); // sorting master list
    
    removeDuplicates(allStudents);
    
    removeStudentsFromClass(allStudents, dropouts);
    
    cout << endl << setw(30) << "FULL STUDENT ROSTER" << endl << endl;
    
    printRoster(allStudents);
    
    return 0;
}