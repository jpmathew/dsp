template <class listType>
LinkedListUnit<listType>::LinkedListUnit(const listType &unitData)
{
	this->unitData = new listType(unitData);
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
	headPointer=0;
	tailPointer=0;
}

template <class listType>
LinkedList<listType>::~LinkedList()
{
	while(seekPointer!=0)
	{
		seekPointer=headPointer;
		headPointer=headPointer->nextUnit;
		delete seekPointer;
	}
}

template <class listType>
void LinkedList<listType>::addUnit(const listType &unitData)
{
	cout<<unitData.x<<endl;
	seekPointer = new LinkedListUnit<listType>(unitData);
	if(tailPointer == 0)
	{
		headPointer = seekPointer;
		tailPointer = seekPointer;
	}
	else
	{
		seekPointer->prevUnit = tailPointer;
		tailPointer->nextUnit = seekPointer;
		tailPointer = seekPointer;
	}
}

template <class listType>
bool LinkedList<listType>::insertUnit(const listType &unitData,int unitPosition)
{
	if(unitPosition<0)									//Out of bounds
	{ 
		return false;
	}
	
	LinkedListUnit<listType> *holdPointer = new LinkedListUnit<listType>(unitData);		
	
	int count=0;
	seekPointer=headPointer;
	while(seekPointer!=0)
	{
		if(count==unitPosition)
		{
			holdPointer->nextUnit = seekPointer;					//Inserting new data
			holdPointer->prevUnit = seekPointer->prevUnit;
			seekPointer->prevUnit = holdPointer;					
			if(count == 0)
			{
				headPointer = holdPointer;
			}
			else
			{
				holdPointer->prevUnit->nextUnit=holdPointer;
			}
			return true;
		}
		else
		{
			count++;
			seekPointer=seekPointer->nextUnit;
		}
	}
	if(count==unitPosition)									//Append
	{
		tailPointer->nextUnit=holdPointer;
		holdPointer->prevUnit=tailPointer;
		holdPointer->nextUnit=0;
		tailPointer=holdPointer;
	}
	return false;
}

template <class listType>
bool LinkedList<listType>::removeUnit(int unitPosition)
{
	if(unitPosition<0)				//Out of bounds
	{ 
		return false;
	}
	
	int count=0;
	seekPointer=headPointer;
	while(seekPointer!=0)
	{
		if(count==unitPosition)
		{
			if(seekPointer==headPointer && seekPointer == tailPointer)		//Single Element [0]
			{
				headPointer=0;
				tailPointer=0;
			}
			else if(seekPointer==headPointer)					//First Element
			{
				headPointer=seekPointer->nextUnit;
				seekPointer->nextUnit->prevUnit=0;
			}
			else if(seekPointer==tailPointer)					//Last Element
			{
				seekPointer->prevUnit->nextUnit=0;
				tailPointer=seekPointer->prevUnit;
			}
			else									//Element in between
			{
				seekPointer->prevUnit->nextUnit=seekPointer->nextUnit;
				seekPointer->nextUnit->prevUnit=seekPointer->prevUnit;
			}
			delete seekPointer;
			return true;
		}
		else
		{
			count++;
			seekPointer=seekPointer->nextUnit;
		}
	}
	return false;										//Out of bounds
}

template <class listType>
bool LinkedList<listType>::replaceUnit(const listType &unitData,int unitPosition)
{
	if(unitPosition<0)				//Out of bounds
	{ 
		return false;
	}
	
	LinkedListUnit<listType> *holdPointer = new LinkedListUnit<listType>(unitData);
	
	int count=0;
	seekPointer=headPointer;
	while(seekPointer!=0)
	{
		if(count==unitPosition)
		{
			holdPointer->nextUnit=seekPointer->nextUnit;
			holdPointer->prevUnit=seekPointer->prevUnit;
			if(seekPointer==headPointer && seekPointer == tailPointer)		//Single Element [0]
			{
				headPointer=holdPointer;
				tailPointer=holdPointer;
			}
			else if(seekPointer==headPointer)					//First Element
			{
				headPointer=holdPointer;
				holdPointer->nextUnit->prevUnit=holdPointer;
			}
			else if(seekPointer==tailPointer)					//Last Element
			{
				holdPointer->prevUnit->nextUnit=holdPointer;
				tailPointer=holdPointer;
			}
			else									//Element in between
			{
				holdPointer->nextUnit->prevUnit=holdPointer;
				holdPointer->prevUnit->nextUnit=holdPointer;
			}
			delete seekPointer;
			return true;
		}
		else
		{
			count++;
			seekPointer=seekPointer->nextUnit;
		}
	}
	return false;										//Out Of Bounds
}

template <class listType>
bool LinkedList<listType>::moveUnit(int curPosition,int newPosition)
{
	if(newPosition < 0 || curPosition < 0)				//Out of bounds
	{ 
		return false;
	}
	if(newPosition==curPosition)
	{
		return true;
	}
	if(curPosition<newPosition)					//To Account for removal of the data
	{
		newPosition+=1;
	}
	LinkedListUnit<listType> *oldPointer,*newPointer;
	
	int count=0;							//Locate
	seekPointer=headPointer;
	newPointer=0;
	while(seekPointer!=0)
	{
		if(count==curPosition)
		{
			oldPointer=seekPointer;
		}
		if(count==newPosition)
		{
			newPointer=seekPointer;
		}
		count++;
		seekPointer=seekPointer->nextUnit;
	}


	if(newPosition > count || curPosition >= count)					//Out Of Bounds
	{
		return false;
	}
	else
	{
		//detach element
		if(oldPointer==headPointer && oldPointer == tailPointer)			//Single Element [0]
		{
			return true;
			//donothing
		}
		else if(oldPointer==headPointer)					//First Element
		{
			headPointer=oldPointer->nextUnit;
			oldPointer->nextUnit->prevUnit=0;
		}
		else if(oldPointer==tailPointer)					//Last Element
		{
			oldPointer->prevUnit->nextUnit=0;
			tailPointer=oldPointer->prevUnit;
		}
		else									//Element in between
		{
			oldPointer->nextUnit->prevUnit=oldPointer->prevUnit;
			oldPointer->prevUnit->nextUnit=oldPointer->nextUnit;
		}
		//attach element
		if(newPointer==0)
		{
			tailPointer->nextUnit=oldPointer;
			oldPointer->nextUnit=0;
			oldPointer->prevUnit=tailPointer;
			tailPointer=oldPointer;
		}
		else
		{
			oldPointer->nextUnit=newPointer;
			oldPointer->prevUnit=newPointer->prevUnit;
			newPointer->prevUnit=oldPointer;
			if(newPointer==headPointer)					//First Element
			{
				headPointer=oldPointer;
			}
			else									//Element in between
			{
				oldPointer->prevUnit->nextUnit=oldPointer;
			}
		}
	}
	return false;										//Out Of Bounds
}

template <class listType>
bool LinkedList<listType>::getUnit(listType &unitData,int unitPosition)
{
	int count=0;
	seekPointer=headPointer;
	while(seekPointer!=0)
	{
		if(count==unitPosition)
		{
			unitData=*(seekPointer->unitData);
			return true;
		}
		else
		{
			count++;
			seekPointer=seekPointer->nextUnit;
		}
	}
	return false;
}


template <class listType>
listType* LinkedList<listType>::getUnit(int unitPosition)
{
	int count=0;
	seekPointer=headPointer;
	while(seekPointer!=0)
	{
		if(count==unitPosition)
		{
			return seekPointer->unitData;
		}
		else
		{
			count++;
			seekPointer=seekPointer->nextUnit;
		}
	}
	return 0;
}



template <class listType>
void LinkedList<listType>::displayList(int dir)
{
	cout<<dir<<endl;
	if(dir==0)
	{
		seekPointer=headPointer;
		while(seekPointer!=0)
		{
			seekPointer->unitData->print();
			seekPointer=seekPointer->nextUnit;
		}
	}
	else
	{
		seekPointer=tailPointer;
		while(seekPointer!=0)
		{
			seekPointer->unitData->print();
			seekPointer=seekPointer->prevUnit;
		}
	}

}
