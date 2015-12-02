//
//  XML generator.cpp
//  Assignment 4 SE
//
//  Created by Emil Shirima on 11/17/15.
//  Copyright © 2015 Emil Shirima. All rights reserved.
//

#include "XMLgenerator.hpp"

void XMLGraphGenerator::viewGraphs(std::string fileName)
{
    invertedTriangle();
    std::cout << "\n\n";
}

void XMLGraphGenerator::generateGraphs(std::string fileName)
{
    std::cout << "Graph is getting generated from XML file....\n\n";
    sleep(2);
}

bool XMLGraphGenerator::isValidFile(std::string fileName)
{
    std::size_t periodSpot = fileName.find('.');
    std::string fileExtension = fileName.substr(periodSpot + 1,fileName.length());
    
    if (fileExtension == "xml")
    {
        return true;
    }
    else
    {
        return false;
    }
}


void XMLGraphGenerator::invertedTriangle()
{
    int width = 6;
    
    for(int i = 0; i < 9 ; ++i)
    {
        std::cout<< "*";
    }
    std::cout<< std::endl;
    
    for(int i = 1; i <= 3; ++i)
    {
        
        for(int j = 0; j < i; ++j)
        {
            std::cout<< " ";
        }
        std::cout<< "*";
        
        for(int k = 1; k < width; ++k)
        {
            std::cout<< " ";
        }
        std::cout<< "*" << std::endl;
        width-=2;
    }
    
    for(int l = 1; l <= 1; ++l)
    {
        
        for(int m = 4; m >= l; --m)
        {
            std::cout<< " ";
        }
        std::cout<< "*";
    }
}