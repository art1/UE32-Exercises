//
//  Place.hpp
//  UE32_3
//
//  Created by Arthur Scharf on 08/11/2016.
//  Copyright © 2016 RT. All rights reserved.
//

#ifndef Place_hpp
#define Place_hpp


#include "basic.h"

class Way;

class Place {

public:
	Place();
	Place(string name);
	string name();
	void addWay(Way *w);
	
private:
	string _name;
	Way *wayArray[200];
	int wayCnt;
};

#endif /* Place_hpp */
