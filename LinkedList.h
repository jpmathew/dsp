#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;
/*
**Contains the Linked List template - A class meant to be used to store a linked list of arbit class "listType"
**listType class should have a copy constructor and an overloaded assignment operator
*/

//PreDeclaration of LiskedList Class for visiblity in LinkedListUnit Class
//Needed For be-"friending"
template <class listType>
class LinkedList;


//LinkedListUnit Template Class
//Holds Data and and two pointers for the linked list
//All data private and visible to LinkedList via friendship
template <class listType>
class LinkedListUnit
{
	friend class LinkedList<listType>;
	private:
		listType* unitData;
		LinkedListUnit *prevUnit,*nextUnit;
		LinkedListUnit();
		LinkedListUnit(const listType *unitData);
		~LinkedListUnit();
};


//Linked List Main Class
template <class listType>
class LinkedList
{
	private:
		LinkedListUnit<listType> *listPointer;
	public:
		LinkedList();
		void addUnit(const listType *unitData);			//Appends at endof List
		bool insertUnit(listType *unitData,int unitPosition);	//Inserts the unit at the position passed and returns success
		bool removeUnit(int unitPosition);			//Removes the unit at position passed and returns success
		bool replaceUnit(listType *unitData,int unitPosition);	//Replaces the unit at posiiton passed and returns success
		bool moveUnit(int curPosition,int newPosition);		//Moves a unit form current position and returns success
		listType* const getUnit(int unitPosition);			//Returns the unit at passed poition , if out of bounds retuns 0
		~LinkedList();
};


template <class listType>
LinkedListUnit<listType>::LinkedListUnit()
{
	unitData = new listType();
	prevUnit = 0;
	nextUnit = 0;
}


template <class listType>
LinkedListUnit<listType>::LinkedListUnit(const listType *unitData)
{
	this->unitData = new listType();
	*(this->unitData) = *unitData;
	prevUnit = 0;
	nextUnit = 0;
}

template <class listType>
LinkedListUnit<listType>::~LinkedListUnit()
{
	delete unitData;
}


template <class listType>
LinkedList<listType>::LinkedList()
{
	listPointer=0;
}

template <class listType>
LinkedList<listType>::~LinkedList()
{
}

template <class listType>
void LinkedList<listType>::addUnit(const listType *unitData)
{
	cout<<unitData->x<<endl;
	LinkedListUnit<listType> *tempPointer = new LinkedListUnit<listType>(unitData);
	if(listPointer == 0)
	{
		listPointer = tempPointer;
	}
	else
	{
		tempPointer->nextUnit = listPointer;
		listPointer->prevUnit = tempPointer;
		listPointer = tempPointer;
	}
}

template <class listType>
listType* const LinkedList<listType>::getUnit(int unitPosition)
{
	return listPointer->unitData;
}

#endif


