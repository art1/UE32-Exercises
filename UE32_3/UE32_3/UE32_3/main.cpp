//
//  main.cpp
//  UE32_3
//
//  Created by Arthur Scharf on 08/11/2016.
//  Copyright © 2016 RT. All rights reserved.
//

#include "basic.h"
#include "Map.hpp"


int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	
	Map map;
	std::cout << "map created\n";
	
	map.load();
	std::cout << "map loaded\n";
    return 0;
}
