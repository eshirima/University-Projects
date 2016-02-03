//
//  main.cpp
//  Lab 3
//
//  Created by Emil Shirima on 2/2/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

#include <iostream>
#include <string>
#include "List.hpp"

int main(int argc, const char * argv[]) {
    
    // manipulating integers
    Collection<int> cone = *new Collection<int>();
    std::cout << "Integer collection: " << "\n";
    cone.addItem(1); cone.addItem(2); cone.addItem(3);
    cone.printCollection();
    
    std::cout << "\n";
    
    cone.removeItem(2);
    cone.printCollection();
    
    std::cout << "\n";
    
    // manipulating strings
    std::string sa[] = {"yellow", "orange", "green", "blue"};
    Collection<std::string> ctwo;
    
    for(auto s : sa)
        ctwo.addItem(s);
    
    std::cout << "String collection: "<< "\n";
    ctwo.printCollection();
    
    // manipulating character collections
    
    // individal collections
    Collection<char> a2g, h2n, o2u;
    for(char c='a'; c <='g'; ++c) a2g.addItem(c);
    for(char c='h'; c <='n'; ++c) h2n.addItem(c);
    for(char c='o'; c <='u'; ++c) o2u.addItem(c);
    
    // collection of collections
    Collection<Collection<char>> cpile;
    
    // adding individual collections
    cpile.addItem(a2g);
    cpile.addItem(h2n);
    cpile.addItem(o2u);
    
    // printing characters from last collection added
    std::cout << "Last added character collection: " << "\n";
    cpile.lastItem().printCollection();
    
    std::cout << "\n";
    
    return 0;
}
