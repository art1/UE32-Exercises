//
//  Place.cpp
//  UE32_3
//
//  Created by Arthur Scharf on 08/11/2016.
//  Copyright © 2016 RT. All rights reserved.
//

#include "Place.hpp"

Place::Place(){
	_name = "unnamed";
	memset(wayArray, 0, sizeof(wayArray));
	wayCnt = 0;
}

Place::Place(string name){
	_name = name;
	memset(wayArray, 0, sizeof(wayArray));
	wayCnt = 0;
}

string Place::name(){
	return _name;
}


void Place::addWay(Way *w){
	if(wayCnt >= sizeof(wayArray)) wayCnt = 0;
	else wayCnt++;
	wayArray[wayCnt] = w;
}
