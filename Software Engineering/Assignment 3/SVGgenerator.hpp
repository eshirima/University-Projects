//
//  SVG generator.hpp
//  Assignment 4 SE
//
//  Created by Emil Shirima on 11/17/15.
//  Copyright © 2015 Emil Shirima. All rights reserved.
//

#ifndef SVGgenerator_hpp
#define SVGgenerator_hpp

#include "generategraphs.hpp"
#include <iostream>

class SVGGenerator: public GenerateGraphs
{
public:
    
    void viewGraphs(std::string);
    void generateGraphs(std::string);
    
private:
    
    int accountID = accountID;
    int userID = userID;
};

#endif /* SVGgenerator_hpp */
