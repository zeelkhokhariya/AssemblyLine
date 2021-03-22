// CLASS: ProductArrival.cpp
//
// Author: Zeelkumar Khokhariya, 7880619
//
// REMARKS: ProductArrival is product arriving at finishing station for part2
//-----------------------------------------
#include "ProductArrival.h"
#include "startAssembly.h"
#include "Simulation.h"
#include <iostream>
ProductArrival::ProductArrival(product *p, int time, Simulation *sim1): pp(p), Event(time, sim1) {}

void ProductArrival::print() {
    std::cout<<"Product Arrival: Partially product arrives at finishing station at time "<<getTime()<<endl;
}


//------------------------------------------------------
// processEvent
//
// PURPOSE:    Product Arrival cause endassemby for the finishing station
// PARAMETERS:
//    none
// Returns: none
//------------------------------------------------------
void ProductArrival::processEvent()
{


    if(sim->Part2Size()!=0 && sim->productSize()!=0)
    {
        if(!sim->isFinishingBusy())
        {
            finishedproduct *fp;

            fp = new finishedproduct(sim->getFrontProduct(), sim->getFrontPart2());
            Event *ee = new startAssembly(fp,getTime(),sim);
            sim->addEvent(ee);
        }
    }
}

ProductArrival::~ProductArrival() {
    delete(pp);
}

