//
//  generate graphs.hpp
//  Assignment 4 SE
//
//  Created by Emil Shirima on 11/15/15.
//  Copyright © 2015 Emil Shirima. All rights reserved.
//

#ifndef generategraphs_hpp
#define generategraphs_hpp

#include "registereduser.h"

#include <iostream>
#include <list>

struct GeneratedGraphs: public RegisteredUser
{
    int accountID = getUserID();
    int graphGeneratorSessionID;
    std::string dataInputFile; // the name of the file consisting of the dataset
};

class GenerateGraphs: public RegisteredUser
{
public:
    
    virtual void viewGraphs(std::string);
    virtual void generateGraphs(std::string);
    
private:
    
    GeneratedGraphs * allGeneratedGraphs; // stores a list of all the graph types supported by the system
    
};

#endif /* generategraphs_hpp */
