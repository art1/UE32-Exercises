//
//  main.cpp
//  UE32_2
//
//  Created by Arthur Scharf on 11/10/16.
//  Copyright © 2016 RT. All rights reserved.
//

#include <iostream>


using namespace std;


/************************* Ugly class definition for Task 1 ****************************/
class Point {
public:
	Point(float x, float y): _x(x), _y(y) {}
	inline float x(void) const {return _x;}
	inline float y(void) const {return _y;}
	void translate(float dx, float dy){
		_x += dx;
		_y += dy;
	}
	void scale(float d){
		_x /= d;
		_y /= d;
	}
	void rotate(float alpha){
		
	}
	
	const float length(Point p){
		return (p.x()-_x)/(p.y()-_y);
	}
	

	static const Point O;

private:
	float _x,_y;
};

const Point Point::O(0,0);

ostream & operator<<(ostream& out, Point p) {
	out << "("<<p.x()<<","<<p.y()<<")"<<endl;
	return out;
}
/************************************* END Task one *************************************/


/************************ Ugly class definition for Task 2 ******************************/
class Triangle{
public:
	
private:
	Point p1, p2, p3;
	Triangle(Point _p1, Point _p2, Point _p3): p1(_p1), p2(_p2), p3(_p3) {}
	
	float perimeter(Point p1, Point p2, Point p3){
		return p1.length(p2) + p2.length(p3) + p3.length(p1);
	}
	
	void translate(float dx, float dy){
		p1.translate(dx, dy);
		p2.translate(dx, dy);
		p3.translate(dx, dy);
	}
	
	const Point center(){
		float A = p1.x()*p1.y() + p2.x()*p2.y() + p2.x()*p3.y() - p3.x()*p2.y() + p3.x()*p1.y() - p1.x()*p3.y();
		A /= 2.0f;
		float centreX = (p1.x()+p2.x()) * (p1.x()*p2.y() - p2.x()*p1.y())
						+ (p2.x() + p3.x()) * (p2.x()*p3.y() - p3.x()-p2.y())
						+ (p2.x() + p1.x()) * (p2.x()*p1.y() - p1.x()*p2.y());
		float centreY = (p1.y()+p2.y()) * (p1.x()*p2.y() - p2.x()*p1.y())
						+ (p2.y() + p3.y()) * (p2.x()*p3.y() - p3.x()-p2.y())
						+ (p2.y() + p1.y()) * (p2.x()*p1.y() - p1.x()*p2.y());
		return Point(centreX/(6*A),centreY/(6*A));
	}
	
	void scale(float s){
		
	}
};



/************************************* END Task two *************************************/

int main(int argc, const char * argv[]) {
	
	// task 1
	Point zero(0,0);
	std::cout <<"x: "<<zero.x()<<" y: "<<zero.y()<<endl;
	
	
    return 0;
}
