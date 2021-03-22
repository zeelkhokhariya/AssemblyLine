// CLASS: Event.h
//
// Author: Zeelkumar Khokhariya, 7880619
//
// REMARKS: Event.h has a method header for the Event.cpp and providing pure abstract method for other child to implement
//-----------------------------------------
#pragma once
#include "OrderedItem.h"

class Simulation;

/**** Event abstract interface */
class Event: public OrderedItem {
private:
        int eventTime; // time of the event.
protected: 
        Simulation *sim; // simulation event is a part of.
public:
        Event(int theTime, Simulation* sim);
        virtual void print();
        virtual void processEvent() = 0; // polymorphic method for events. 
        virtual ~Event();
        int getTime(); 
        int compareTo(OrderedItem *other); // you must implement this.

};// class Event
