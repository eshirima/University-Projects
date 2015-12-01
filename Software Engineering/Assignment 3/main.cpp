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
#include "registereduser.h"

#include <iostream>
#include <fstream>

int main(int argc, const char * argv[]) {
    
    std::cout << " ************ Start of the program ************ \n\n";
    
    GenerateGraphs objectForGeneratingGraphs;
    
    std::string svgFile = "example.SVG";
    std::string xmlFile = "example.XML";
    
    objectForGeneratingGraphs.generateGraphs(svgFile);
    objectForGeneratingGraphs.viewGraphs(svgFile);
    
    objectForGeneratingGraphs.generateGraphs(xmlFile);
    objectForGeneratingGraphs.viewGraphs(xmlFile);
    
    GenerateGraphs * svgGenerator = new SVGGenerator();
    GenerateGraphs * xmlGenerator = new XMLGraphGenerator();
    
    svgGenerator->generateGraphs(svgFile);
    svgGenerator->viewGraphs(svgFile);
    
    xmlGenerator->generateGraphs(xmlFile);
    xmlGenerator->viewGraphs(xmlFile);
    
    delete svgGenerator;
    delete xmlGenerator;
    
    std::cout << " ************ End of the program ************ \n\n";
    
    return 0;
}
