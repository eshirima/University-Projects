//
//  main.cpp
//  Assignment 4 SE
//
//  Created by Emil Shirima on 11/15/15.
//  Copyright © 2015 Emil Shirima. All rights reserved.
//

#include "generategraphs.hpp"
#include "XMLgenerator.hpp"
#include "SVGgenerator.hpp"
#include "registereduser.hpp"

#include <iostream>
#include <fstream>

int main(int argc, const char * argv[]) {
    
    std::cout << " ************ Start of the program ************ \n\n";
    
    int userID = 1;
    std::string userFirstName = "Emil";
    std::string userLastName = "Shirima";
    
    RegisteredUser objectForRegisteredUser;
    GenerateGraphs objectForGeneratingGraphs;
    
    objectForRegisteredUser.setUser(userID, userFirstName, userLastName);
    
    
    std::cout << "Enter data file name (e.g. test.svg or test.xml) \n\n";
    
    std::string userDataFile;
    
    std::cin >> userDataFile;
    
    std::cout << "\n\n";
    
    int userResponse;
    
    if (objectForGeneratingGraphs.isValidFile(userDataFile))
    {
        objectForRegisteredUser.uploadFile(userID, userDataFile);
        
        GenerateGraphs * svgGenerator = new SVGGenerator();
        GenerateGraphs * xmlGenerator = new XMLGraphGenerator();
        
        if (svgGenerator->isValidFile(userDataFile)) // it is a SVG file that was uploaded
        {
            svgGenerator->generateGraphs(userDataFile);
            
            std::cout << "Continue to viewing? (1/0) \n\n";
            std::cin >> userResponse;
            std::cout << "\n";
            
            switch (userResponse)
            {
                case 1:
                    std::cout << "Preparing the graph for viewing...\n\n";
                    sleep(5);
                    svgGenerator->viewGraphs(userDataFile);
                    break;
                case 0:
                    std::cout << "Exiting the program..\n\n";
                    sleep(5);
                    break;
                default:
                    break;
            }
        }
        else // an XML file was uploaded
        {
            xmlGenerator->generateGraphs(userDataFile);
            
            std::cout << "Continue to viewing? (1/0) \n\n";
            std::cin >> userResponse;
            std::cout << "\n";
            
            switch (userResponse)
            {
                case 1:
                    std::cout << "Preparing the graph for viewing...\n\n";
                    sleep(5);
                    xmlGenerator->viewGraphs(userDataFile);
                    break;
                case 0:
                    std::cout << "Exiting the program..\n\n";
                    sleep(5);
                    break;
                default:
                    break;
            }
        }
        
        delete svgGenerator;
        delete xmlGenerator;
        
    }
    else
    {
        std::cerr << "Invalid File Extension. Only SVG and XML files are currently supported :( \n\n";
    }
    
    
    std::cout << " ************ End of the program ************ \n\n";
    
    return 0;
}