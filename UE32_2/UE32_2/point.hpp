//
//  point.hpp
//  UE32_2
//
//  Created by Arthur Scharf on 11/10/16.
//  Copyright © 2016 RT. All rights reserved.
//

#ifndef point_hpp
#define point_hpp

#include <stdio.h>

class Point {
public:
	Point(float x, float y): _x(x), _y(y) {}
private:
	float _x,_y;
};

#endif /* point_hpp */
