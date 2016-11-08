//
//  Path.hpp
//  UE32_3
//
//  Created by Arthur Scharf on 08/11/2016.
//  Copyright © 2016 RT. All rights reserved.
//

#ifndef Path_hpp
#define Path_hpp

#include "basic.h"
#include "Place.hpp"

class Path {
public:
	void add(Place p);
	void print();
	void invert();
private:
	
};

#endif /* Path_hpp */
