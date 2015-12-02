//
//  generate graphs.cpp
//  Assignment 4 SE
//
//  Created by Emil Shirima on 11/15/15.
//  Copyright © 2015 Emil Shirima. All rights reserved.
//

#include "generategraphs.hpp"

void GenerateGraphs::viewGraphs(std::string fileName)
{
    std::cout << "Virtual View Graph called on the file " << fileName << "\n\n";
}

void GenerateGraphs::generateGraphs(std::string fileName)
{
    std::cout << "The graphs are getting generated...\n\n";
    sleep(5);
    std::cout << "Success, the graph was generated using the Virtual Method :) \n\n";
}

bool GenerateGraphs::isValidFile(std::string fileName)
{
    std::size_t periodSpot = fileName.find('.');
    std::string fileExtension = fileName.substr(periodSpot + 1,fileName.length());
    
    if (fileExtension == "svg" || fileExtension == "xml")
    {
        return true;
    }
    else
    {
        return false;
    }
}