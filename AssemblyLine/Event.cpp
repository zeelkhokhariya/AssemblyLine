// CLASS: Event.cpp
//
// Author: Zeelkumar Khokhariya, 7880619
//
// REMARKS: Event class provide the base for four types of events going to implement to base.
//-----------------------------------------
#include "Event.h"

Event::Event(int theTime, Simulation* theSim) :eventTime(theTime),sim (theSim)
{}

Event::~Event() 
{}

int Event::getTime()
{
    return eventTime; 
}

int Event::compareTo(OrderedItem *other)
{
    Event *e;
    e = (Event *) other;
    if(e->getTime() < eventTime)
    {
        return 1;
    }
    
    if(e->getTime() == eventTime)
    {
        return 0;
    }
        
        return -1;
    	 // you must implement this.
}

void Event::print() {}
// compareTo
