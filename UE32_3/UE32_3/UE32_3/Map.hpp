//
//  Map.hpp
//  UE32_3
//
//  Created by Arthur Scharf on 08/11/2016.
//  Copyright © 2016 RT. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include "basic.h"
#include "Way.hpp"
#include <vector>

class Map {
	
public:
	Map(void);
	Place & addPlace(string name);
	Way addWay(Place p1, Place p2);
	void load();
	Place * getPlace(int place);
	void shortest(Place in, Place fin);
private:
	Place *places[100];
	Way *ways[200];
	int placesCnt;
	int waysCnt;
	
	vector<Place> dura;
	vector<Place> prev;
	vector<Place> done;
};

#endif /* Map_hpp */
