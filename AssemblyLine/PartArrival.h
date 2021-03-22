// CLASS: PartArrival.h
//
// Author: Zeelkumar Khokhariya, 7880619
//
// REMARKS:PartArrival.h provides the methods defination to be implemet in partArrival.cpp
//-----------------------------------------
# pragma once

#include "Event.h"
#include "Parts.h"

class PartArrival : public Event
{
private:
    Parts *part;


public:
    PartArrival(Parts* pp, Simulation *sim1);
    void processEvent() override;
    void print() override;
    int getPartNo();
    Parts* getPart();
    ~PartArrival();
};
