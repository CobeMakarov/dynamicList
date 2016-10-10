/*
    Shacobe Johnson
    Computer Science 340
    Section 02
    Lab 5
*/
#include "dynamicList.h"

dynamicList::dynamicList()		
{
    size = defmaxlistsize;
    length = 0;
    element = new int[size];
}
dynamicList::dynamicList(int maxnumber = defmaxlistsize)		
{
    size = maxnumber;
    length = 0;
    element = new int[size];
}

dynamicList::~dynamicList()
{

}

void dynamicList::Print() const
{
    for(int i = 0; i < length; i++) {
        cout << "["<<i<<"] == "<<element[i]<<endl;
    }
}

bool dynamicList::Full() const
{
    return length == size;
}


bool dynamicList::Empty() const
{
    return length == 0;
}

bool dynamicList::Search(int item)
{
    bool found = false;
    
    for(int i = 0; i < length; i++) {
        if(element[i] == item) {
       	    return true;
        }
    }
    return found;
}
bool dynamicList::Search(int item, int &location)
{
   bool found = false;
    
    for(int i = 0; i < length; i++) {
        if(element[i] == item) {
            found = true;
            location = i;
			break;
        }
    }
    return found;
}

bool dynamicList::Insert(int item)
{
    if(Full()) {
        cout<<"The array is full, cannot insert."<<endl;    
        return false;
    }
    
    if(Empty()) {
        element[length] = item;
        length++;
        return true;
    }
    
    for(int i = length; i > 0; i--) {
		element[i] = element[i - 1];
    }

    element[0] = item;
    length++;
    return true;
}

bool dynamicList::Insert(int item, int location)
{
	if(location < 0 || location > size) {
        cout<<"Location out of bounds, cannot insert."<<endl;
        return false;
    }
    
    if(Full()) {
        cout<<"The array is full, cannot insert"<<endl;    
        return false;
    }
    
    if(Empty()) {
        element[location] = item;
        length++;
        return true;
    }
    
	if(location > length && location < size) { //fill in the blanks
		for(int i = length; i <= location; i++) {
			element[i] = -1;
		}
	}
	
    if(element[location] == -1) {
        element[location] = item;
        length++;
        return true;
    }
    
    for(int i = length; i > location; i--) {
		element[i] = element[i - 1];
    }
    
    element[location] = item;
    length++;
    return true;
}

void dynamicList::Remove(int &item, bool &found, int location)
{
    if(location < 0 || location > size) {
        cout<<"Location out of bounds, cannot remove at location: "<<location<<endl;
    } else {
		if(Empty()) {
        	cout<<"Array is empty, nothing to remove."<<endl;
    	} else {
			found = Search(item, location);
			
			if(found) {
				item = element[location];
	       		element[location] = -1;
	       	    for(int i = location; i < length; i++) {
					int temp = element[i];
					element[i] = element[i + 1];
					element[i + 1] = temp;
	        	}
				length--;
			} else {
				cout<<"Element ("<<item<<") not found at location: "<<location<<endl;
			}
		}
	}
}
void dynamicList::Remove(int &item, bool &found)
{
    if(Empty()) {
        cout<<"Array is empty, nothing to remove."<<endl;
    } else {
   	 int location = 0;
    
    	found = Search(item, location);
    
        if(found) {
       		element[location] = -1;
       	    for(int i = location; i < length; i++) {
				int temp = element[i];
				element[i] = element[i + 1];
				element[i + 1] = temp;
        	}
			length--;
    	} else {
    		cout<<"Element "<<item<<" (to remove) not found!"<<endl;
    	}
    }
}

int dynamicList::currentSize() const
{
    return length;
}
void dynamicList::Clear()
{
    element = new int[size];
}

void dynamicList::Getlast(int& item, bool &found)
{
    if(Empty()) {
        cout <<"List is empty, no items to return"<<endl;
        found = false;
        return;
    }
    
    item = element[length - 1];
    found = true;
}

