#include "LinkedList.h"

template <class listType>
LinkedListUnit<listType>::LinkedListUnit()
{
	unitData = new listType();
	prevUnit = 0;
	nextUnit = 0;
}


template <class listType>
LinkedListUnit<listType>::LinkedListUnit(listType* unitData)
{
	this->unitData = unitData;
	prevUnit = 0;
	nextUnit = 0;
}


template <class listType>
LinkedList<listType>::LinkedList()
{
	listPointer=0;
}

template <class listType>
void LinkedList<listType>::addUnit(listType* unitData)
{
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


