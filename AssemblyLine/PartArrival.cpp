// CLASS: PartArrival.cpp
//
// Author: Zeelkumar Khokhariya, 7880619
//
// REMARKS: PartArrival stores the arrive Part into their queue and notified when the new Part Arrive.
//-----------------------------------------
#include <iostream>
#include "PartArrival.h"
#include "Simulation.h"
#include "product.h"
#include "startAssembly.h"

PartArrival::PartArrival(Parts *pp, Simulation *sim1) : part(pp), Event(pp->getarriveTime(),sim1)
{
}


//------------------------------------------------------
// processEvent
//
// PURPOSE:    Process Arrival parts if parts are receive for start assembly then it process start Assembly
// same for finishing station
// PARAMETERS:
//    none
// Returns: none
//------------------------------------------------------
void PartArrival :: processEvent()
{
    sim->addPart(part);

    if(sim->Part0Size()!=0 && sim->Part1Size()!=0)
    {
        if(!sim->isMainBusy())
        {
          sim->setMainStatus(true);
            product *pratial;
            pratial = new product(sim->getFrontPart0(), sim->getFrontPart1());
            Event *ee = new startAssembly(pratial,getTime(),sim);
            sim->addEvent(ee);
        }
    }

    if(sim->Part2Size()!=0 && sim->productSize()!=0)
    {
        if(!sim->isFinishingBusy())
        {
            finishedproduct *fp;
            sim->setFinishingStatus(true);
            fp = new finishedproduct(sim->getFrontProduct(), sim->getFrontPart2());
            Event *ee = new startAssembly(fp,getTime(),sim);
            sim->addEvent(ee);
        }
    }

    sim->getNextArrival();
}

int PartArrival :: getPartNo()
{
    return part->getPartNo();
}

void PartArrival::print()
{
    cout<<"Part Arrival:: Part Number: "<< part->getPartNo()<<" at a time: "<<part->getarriveTime()<<endl;
}

Parts *PartArrival::getPart() {
    return part;
}

PartArrival::~PartArrival() {
    delete(part);
}



