/*
	Tianyi Zhang
	tianyiz
	Assignment 2
	Oct.19.2017
*/
#include"Point.h"
#include<stdlib.h>
using namespace std;

//constructor
Point::Point(int x, int y):X(x),Y(y){};

//copy constructor
Point::Point( const Point & other){
   this->X=other.getX();
   this->Y=other.getY();
};

//return x and y values
int Point::getX( ) const {return X;};
int Point::getY( ) const {return Y;};

//overide operators for own purposes
bool Point::operator==(const Point & other) const{
   if(X==other.getX() && Y==other.getY())return true;
   else return false;
};
ostream & operator<<(ostream &out, const Point & P ){
    out<<"("<<P.getX()<<", "<<P.getY()<<")";
    return out;
 };
