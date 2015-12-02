//
//  registered user.cpp
//  Assignment 4 SE
//
//  Created by Emil Shirima on 11/15/15.
//  Copyright © 2015 Emil Shirima. All rights reserved.
//

#include <iostream>
#include "registereduser.hpp"

RegisteredUser::RegisteredUser()
{
    accountID = -1; // only positive IDs allowed
    userFirstName = empty;
    userLastName = empty;
}

void RegisteredUser::setUser(int personID, std::string firstName, std::string lastName)
{
    accountID = personID;
    userFirstName = firstName;
    userLastName = lastName;
}

int RegisteredUser:: getUserID()
{
    return accountID;
}

std::string RegisteredUser::getUserFirstName()
{
    return userFirstName;
}

std::string RegisteredUser::getUserLastName()
{
    return userLastName;
}

bool RegisteredUser::isValidID(int currentUserID)
{
    if (currentUserID >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void RegisteredUser::uploadFile(int currentUserID, std::string fileName)
{
    if (isValidID(currentUserID) && fileName.length() > 0)
    {
        std::cout << "Uploading file...\n";
        sleep(5);
        
        long position = fileName.find_first_of('.');
        std::string extensionName = fileName.substr(position + 1);
        
        std::cout << "\n\n" << extensionName << " file was successfully uploaded :) \n\n";
    }
    else
    {
        if (currentUserID < 0)
        {
            std::cerr << "Error: Invalid User ID \n\n";
        }
        else
        {
            std::cerr << "Error: A file name is needed to processed. \n\n";
        }
    }
}

// MARK: This requires an actual file to be present in the project

//void RegisteredUser::uploadFile(int currentUserID, std::string fileName)
//{
//    if (currentUserID >= 0 && !fileName.empty())
//    {
//        std::fstream fileStreamer;
//        fileStreamer.open(fileName);
//        
//        if (fileStreamer.is_open())
//        {
//            std::cout << "Uploading file...";
//            sleep(3);
//            
//            long position = fileName.find_first_of('.');
//            std::string extensionName = fileName.substr(position + 1);
//            
//            std::cout << "\n\n" << extensionName << " file was successfully uploaded :) \n\n";
//        }
//        else
//        {
//            std::cerr << "Error: " << std::strerror(errno) << "\n\n"; // prints the description of the thrown fstream error
//        }
//    }
//    else
//    {
//        if (currentUserID < 0)
//        {
//            std::cerr << "Error: Invalid User ID \n\n";
//        }
//        else
//        {
//            std::cerr << "Error: A file name is needed to processed. \n\n";
//        }
//    }
//}