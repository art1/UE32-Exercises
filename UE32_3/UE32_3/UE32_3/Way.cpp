//
//  Way.cpp
//  UE32_3
//
//  Created by Arthur Scharf on 08/11/2016.
//  Copyright © 2016 RT. All rights reserved.
//

#include "Way.hpp"


Way::Way(Place _p1, Place _p2){
	p1 = _p1;
	p2 = _p2;
	_p1.addWay(this);
}


float Way::duration(){
	return dist/speed;
}
