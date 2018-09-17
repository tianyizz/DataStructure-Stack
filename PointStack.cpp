/*
	Tianyi Zhang
	tianyiz
	Assignment 2
	Oct.19.2017
*/
#include "PointStack.h"
#include <stdlib.h>
using namespace std;

//nothing point initilization
Point PointStack::NOTHING(0,0);

PointStack::PointStack( ):stackTop(nullptr){};
PointStack::~PointStack( ){
   Node* nextTemp=nullptr;
   for(;stackTop!=nullptr;stackTop=nextTemp){
      nextTemp=stackTop->next;
      delete stackTop;
   }
};

//insert new node at front of the stack
void PointStack::push(const Point & item){
   Node* newNode=new Node(item);

   if(newNode==nullptr) return;
      newNode->data=item;

   if(stackTop!=nullptr)newNode->next=stackTop;
   else newNode->next=nullptr;

   stackTop=newNode;
};

//pop and return the top item on stack
Point PointStack::pop( ){
   if(stackTop==nullptr)return NOTHING;

   Point temp=stackTop->data;
   Node* tempNode=stackTop;

   stackTop=stackTop->next;

   delete tempNode;
   return temp;
 };

//return the first item on stack
Point & PointStack::peek( ) const{
   if(stackTop==nullptr) return NOTHING;
   return stackTop->data;
};

//second item check for turnleft function purposes
Point & PointStack::peekUnder( ) const{
   if(stackTop==nullptr||stackTop->next==nullptr)return NOTHING;
   return stackTop->next->data;
};

//check if head is nullptr
bool PointStack::isEmpty( ) const{
   if(stackTop==nullptr) return true;
   return false;
 };
