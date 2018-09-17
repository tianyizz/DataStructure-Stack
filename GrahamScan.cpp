/*
	Tianyi Zhang
	tianyiz
	Assignment 2
	Oct.19.2017
*/

// partial implementation of GrahamScan
#include <vector>
#include <cmath>
#include<stdlib.h>
#include<iostream>
using namespace std;
#include "GrahamScan.h"

#define PI 3.14159265

// returns bearing of line from Point A to Point B
double angle(Point &A, Point &B)
{
  Point tempA(0,0);
  Point tempB(B.getX()-A.getX(),B.getY()-A.getY());
  double temp=atan((double)tempB.getX()/(double)tempB.getY())/PI*180.0;

  //need to get angle by +180 when it is at the IV.
  if(temp<0)temp+=180;

  //to make it compatible with sort angle function
  return (-1)*temp;

}

// sorts points by angle counterclockwise from list[0] using insertion sort
void sortByAngleFromFirst(vector<Point> &list)
{
   for(unsigned int round=1; round<list.size(); round++) {
      int i=round;
      Point newPoint = list[round];
      double newAngle = angle(list[0], newPoint );
      while( i>1 && ( newAngle < angle(list[0], list[i-1]) ) ) {
	     list[i]=list[i-1];
         i--;
      }
      list[i] = newPoint;
   }
}

// finds leftmost point in list and moves it into position 0
void moveLeftmostFirst( vector<Point> &list )
{
    int count=list.size();
    int leftpoint=0;

    //looking for left bottom most point
    for(int i=1;i<count;i++)
      if(!(list[i].getX()>list[leftpoint].getX())){
        if(list[i].getX()<list[leftpoint].getX())
          leftpoint=i;
        else
          if(list[i].getY()<list[leftpoint].getY())
            leftpoint=i;
      }

    swap(list[0],list[leftpoint]);
}

// returns true if going A to B to C is a left turn
bool isLeftTurn( Point &A, Point &B, Point &C )
{
      return (B.getY()-A.getY())*(C.getX()-B.getX()) <
                    (C.getY()-B.getY())*(B.getX()-A.getX());
}

// prints out contents of list
void debugDump( vector<Point> &list)
{
  for(unsigned int i=0;i<list.size();i++)
    cout<<list[i];
}

// determines convex hull of list using Graham scan
vector<Point> convexHull( vector<Point> &list)
{
      unsigned int i;
      vector<Point> returnValue;
      PointStack convexHullist;
      PointStack stack;

      //sort the list
      moveLeftmostFirst(list);
      sortByAngleFromFirst(list);

      //check if legible for convex hull operation
      if(list.size()<3)return list;

      //fill up a point stack to perform better operation
      for(i=1;!(i>list.size());i++)
    	  stack.push(list[list.size()-i]);

      //this is the value for return
      convexHullist.push(stack.pop());
      convexHullist.push(stack.pop());

      while(!stack.isEmpty()){

    	//if one point makes it turn right, keep popping until the top two points
    	//make it a left turn with the third point from point stack, add the point
    	//at the end of the operation.
        while(!isLeftTurn(convexHullist.peekUnder(),convexHullist.peek(),stack.peek()))
        	convexHullist.pop();

        //keep adding no matter what
        convexHullist.push(stack.pop());
      }

      //refill the list by convexHullist for return type
      while(!convexHullist.isEmpty())
    	  returnValue.push_back(convexHullist.pop());


      return returnValue;
}

// determines convex shells of list by repeated use of convexHull
void shellIt( vector<Point> &list )
{
	unsigned int i;
    vector<Point> newlist=list;

    while(!(newlist.size()<3)){
      //find all the shells until less than 3 points are left
      newlist=convexHull(list);
      debugDump(newlist);
      cout<<endl;

      //take out the found points from the old list
      for(i=0;i<newlist.size();i++){
    	  for(unsigned int a=0;a<list.size();a++)
    		  if(newlist[i]==list[a])
    			  list.erase(list.begin()+a);

      }

    }

}
