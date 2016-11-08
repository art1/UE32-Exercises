//
//  Map.cpp
//  UE32_3
//
//  Created by Arthur Scharf on 08/11/2016.
//  Copyright © 2016 RT. All rights reserved.
//

#include "Map.hpp"

Map::Map(){
	memset(ways, 0, sizeof(ways));
	memset(places, 0, sizeof(places));
	memset(prev, 0, sizeof(prev));
	placesCnt = sizeof(places);
	waysCnt = sizeof(ways);
						   
}

Place & Map::addPlace(string name){
	if(placesCnt >= sizeof(places)){
		placesCnt = 0;
	} else placesCnt++;
	places[placesCnt] = new Place(name);
	return *places[placesCnt];
}

Way Map::addWay(Place p1, Place p2){
	if(waysCnt >= sizeof(ways)){
		waysCnt = 0;
	} else waysCnt++;
	ways[waysCnt] = new Way(p1,p2);
	return *ways[waysCnt];
}

void Map::load(){
	ifstream in;
	in.open("/Users/arthur/Documents/Coding/M2TSI-Stuff/UE32/UE32_1/UE32_3/UE32_3/UE32_3/ups.map");
	while(!in.eof()) {
		string name;
		getline(in, name);
		if(name == "") break;
		// create new place
	} while(!in.eof()) {
		int src, dst;
		float dist, sped, traf;
		in >> src >> dst >> dist >> sped >> traf;
		if(!in.fail()) {
			std::cout << src <<" "<< dst << " "<<endl;
			Place *srcp = places[src];
			Place *dstp = places[dst];
			// create new way
		}
	}
	in.close();
}

Place * Map::getPlace(int place){
	if(place >= sizeof(places) || place < 0) return nullptr;
	return places[place];
}


void Map::shortest(Place *in, Place *fin){
	auto it = std::find(prev.begin(), prev.end(), in);

	
	
}


