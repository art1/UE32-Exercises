//
//  Way.hpp
//  UE32_3
//
//  Created by Arthur Scharf on 08/11/2016.
//  Copyright © 2016 RT. All rights reserved.
//

#ifndef Way_hpp
#define Way_hpp

#include "basic.h"
#include "Place.hpp"

class Way {
public:
	Way(Place _p1, Place _p2);
	float duration();	
private:
	float dist = 0.0f;
	float speed = 0.0f;
	float traf = 0.0f;
	Place p1;
	Place p2;
};

#endif /* Way_hpp */
