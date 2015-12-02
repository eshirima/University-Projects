//
//  SVG generator.cpp
//  Assignment 4 SE
//
//  Created by Emil Shirima on 11/17/15.
//  Copyright © 2015 Emil Shirima. All rights reserved.
//

#include "SVGgenerator.hpp"

void SVGGenerator::viewGraphs(std::string fileName)
{
    diamond(5);
    std::cout << "\n\n";
}

void SVGGenerator::generateGraphs(std::string fileName)
{
    std::cout << "Graph is getting generated from SVG file...\n\n";
    sleep(5);
}

bool SVGGenerator::isValidFile(std::string fileName)
{
    std::size_t periodSpot = fileName.find('.');
    std::string fileExtension = fileName.substr(periodSpot + 1,fileName.length());
    
    if (fileExtension == "svg")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void SVGGenerator::diamond(int size)
{
    int z = 1;
    
    for(int i = 0; i <= size; ++i)
    {
        for(int j = size; j > i; --j)
        {
            std::cout<< " ";
        }
        
        std::cout<< "*";  // printing asterisk here
        
        if(i > 0)
        {
            for(int k = 1; k <= z; ++k)
            {
                std::cout<< " ";
            }
            z+= 2;
            std::cout<< "*";
        }
        std::cout<< std::endl; // end line similar  to \n
    }
    
    z-= 4;
    
    for(int i = 0; i <= size - 1; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            std::cout<< " ";
        }
        
        std::cout<< "*";
        
        for(int k = 1; k <= z; ++k)
        {
            std::cout<< " ";
        }
        
        z-= 2;
        
        if(i != size - 1)
        {
            std::cout<< "*";
        }
        std::cout<< std::endl;
    }
 }