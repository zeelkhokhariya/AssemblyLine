// CLASS: startAssembly.cpp
//
// Author: Zeelkumar Khokhariya, 7880619
//
// REMARKS: Starts Assembling both Part0 and part1 at main Station, Product and Part2 at finishing Station
//-----------------------------------------
#include <iostream>
#include "startAssembly.h"
#include "Simulation.h"
#include "endAssembly.h"

startAssembly::startAssembly(product *p, int time, Simulation *sim1): pp(p), Event(time,sim1) {

}

startAssembly::startAssembly(finishedproduct *p, int time, Simulation *sim1): fp(p), Event(time,sim1) {

}
//------------------------------------------------------
// processEvent
//
// PURPOSE:    cause endAssembly by adding the station finishing time to the current time
// PARAMETERS:
//    none
// Returns: none
//------------------------------------------------------
void startAssembly::processEvent()
{
    if(fp == nullptr)
    {
        sim->setMainStatus(true);
        Event *ee = new endAssembly(pp,(getTime()+sim->getmainAssemblyTime()),sim);
        sim->addEvent(ee);
    }

    if(pp == nullptr)
    {
        sim->setFinishingStatus(true);
        Event *ee = new endAssembly(fp,(getTime()+sim->getfinishingAssemblyTime()),sim);
        sim->addEvent(ee);
        
    }
}

void startAssembly::print()
{
    if(fp == nullptr)
    {
        cout<<"Start Assembly: P0 and P1 at time at main Station "<<getTime()<<endl;
    }

    if(pp == nullptr)
    {
        cout<<"Start Assembly: Partial product and P2 at time at finishing Station "<<getTime()<<endl;
    }
}

startAssembly::~startAssembly() {
delete(pp);
delete(fp);
}
