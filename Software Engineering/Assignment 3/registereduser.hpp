//
//  registered user.h
//  Assignment 4 SE
//
//  Created by Emil Shirima on 11/15/15.
//  Copyright © 2015 Emil Shirima. All rights reserved.
//

#ifndef registereduser_h
#define registereduser_h

#include <fstream>
#include <list>
#include <cerrno> // throws a description of the error thrown by fstream
#include <cctype> // for toupper()

const static std::string empty = "NULL";

class RegisteredUser
{
public:
    
    RegisteredUser();
    
    bool isValidID(int);
    
    // a registered user's ID is passed along with their respective file they wish to convert
    void uploadFile(int, std::string); // for CSV or XML file
    
    void saveFile();
    
    
    // MARK: Getters and Setters
    void setUser(int, std::string, std::string);
    
    int getUserID();
    std::string getUserFirstName();
    std::string getUserLastName();
    
private:
    
    std::string userFirstName;
    std::string userLastName;
    
protected: // to allow access to the classes inheriting from this class
    
    int accountID;
};

#endif /* registereduser_h */
