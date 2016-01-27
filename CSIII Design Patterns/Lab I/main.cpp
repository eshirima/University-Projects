//
//  main.cpp
//  Lab 1
//
//  Created by Emil Shirima on 1/20/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cerrno> // throws a description of the error thrown by fstream
#include <string>
#include <cstdlib>
#include <cstring>

//TODO: Keep reading even when one file has more contents than the other.

bool isValidNumberOfArguments(int numberOfArguments)
{
    if (numberOfArguments < 3)
    {
        std::cerr << "Invalid number of arguments.\nFormat <objectfile> <textfile> <textfile>\n";
        return false;
    }
    
    return true;
}

bool doesFileExist(std::string fileName)
{
    std::fstream fileStreamer;
    fileStreamer.open(fileName);
    
    if (fileStreamer.is_open())
    {
        return  true;
    }
    else
    {
        std::cerr << "Error: " << std::strerror(errno) << "\n\n"; // prints the error description
        return false;
    }
}

void printCarotSign(std::string first, std::string second, std::string firstLog, std::string secondLog, int lineNumber, int differencePosition)
{
    std::string firstFullLog = firstLog + std::to_string(lineNumber) + ": ";
    std::string secondFullLog = secondLog + std::to_string(lineNumber) + ": ";
    
    std::cout << firstFullLog << first << "\n";
    std::cout << secondFullLog << second << "\n";
    
    std::string tempString;
    unsigned long stringSize = secondFullLog.length() + differencePosition - 1;
    tempString.append(stringSize, ' ');
    
    tempString += "^";
    std::cout << tempString << "\n";
}

unsigned long findMax(unsigned long first, unsigned long second)
{
    if (first > second)
    {
        return first;
    }
    
    return second;
}

// Checks if two strings are equal

bool checkIfUnique(std::string first, std::string second, std::string firstLog, std::string secondLog, int lineCount)
{
    unsigned long size = findMax(first.length(), second.length());
    
    for (int i = 0; i < size; ++i)
    {
        if (first[i] != second[i])
        {
            printCarotSign(first, second, firstLog, secondLog, lineCount, i+1);
            return false;
        }
    }
    return true;
}

// Reads the text files

void spotContentDifferences(std::string firstFile, std::string secondFile)
{
    std::ifstream openFirstFile(firstFile);
    std::ifstream openSecondFile(secondFile);
    
    std::string firstFileLine, secondFileLine;
    std::string firstLog = firstFile + ": ";
    std::string secondLog = secondFile + ": ";
    
    int lineCount = 0;
    
    while (std::getline(openFirstFile, firstFileLine) && std::getline(openSecondFile, secondFileLine))
    {
        ++lineCount;
        checkIfUnique(firstFileLine, secondFileLine, firstLog, secondLog, lineCount);
    }
}

int main(int argc, const char * argv[])
{
    if (isValidNumberOfArguments(argc))
    {
        if (doesFileExist(argv[1]) && doesFileExist(argv[2]))
        {
            spotContentDifferences(argv[1], argv[2]);
        }
    }
    return 0;
}
