/*
	Tianyi Zhang
	tianyiz
	Assignment 2
	Oct.19.2017
*/

#include"Point.h"
#include"PointStack.h"
#include"GrahamScan.h"
#include <iostream>
using namespace std;

int main() {
  int count=0;
  int x=0,y=0;
  vector<Point> stack;

  cout<<"Enter count:";
  cin>>count;

  if(!(count>0)){
    cout<<"Invalid inputs. Program terminated."<<endl;
    return 0;
  }

  cout<<"Enter points (End each pair with enter):";

  for(int i=0;i<count;i++){
    cin>>x>>y;
    stack.push_back(Point(x,y));
  }

  vector<Point>&stackTemp=stack;
  vector<Point>stackResult=convexHull(stackTemp);
  vector<Point>&stackResultTemp=stackResult;

  cout<<"Hull is:"<<endl;
  debugDump(stackResultTemp);
  cout<<endl<<"Shell is:"<<endl;
  shellIt(stackTemp);
  cout<<endl;

  return 0;
}
