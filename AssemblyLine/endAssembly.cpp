// CLASS: endAssembly.cpp
//
// Author: Zeelkumar Khokhariya, 7880619
//
// REMARKS: endAssembly class cause ProductArrival event to scheduled for finishing Station.
//  for the finishing station endAssembly calculate the stats of final product
//-----------------------------------------

#include <iostream>
#include "endAssembly.h"
#include "Simulation.h"
#include "startAssembly.h"
#include "ProductArrival.h"

endAssembly::endAssembly(product *p, int time, Simulation *sim1): pp(p), Event(time,sim1) {}

endAssembly::endAssembly(finishedproduct *p, int time, Simulation *sim1):fp(p),Event(time,sim1) {}

void endAssembly::print() {
    if(fp == nullptr)
    {
        cout<<"End Assembly: P0 and P1 into partial product at time at main Station "<<getTime()<<endl;
    }

    if(pp == nullptr)
    {

        cout<<"End Assembly: Partial product and P2 into finish product at time at finishing Station "<<getTime()<<endl;
    }
}


//------------------------------------------------------
// processEvent
//
// PURPOSE:    process the event at finishing station gets final time and for main station cause product arrival at finishing station
// PARAMETERS:
//     None
// Returns: nothing
//------------------------------------------------------

void endAssembly::processEvent()
{
    if(fp == nullptr)
    {

        Event *e1 = new ProductArrival(pp,getTime(),sim);

        sim->addEvent(e1);
        sim->setMainStatus(false);
        sim->dequePart0();
        sim->dequePart1();
        sim->addProduct(pp);
        if(sim->Part0Size()!=0 && sim->Part1Size()!=0)
        {
            if(!sim->isMainBusy())
            {
                product *pratial;
                pratial = new product(sim->getFrontPart0(), sim->getFrontPart1());
                Event *ee = new startAssembly(pratial,getTime(),sim);
                sim->addEvent(ee);
            }
        }





    }

    if(pp == nullptr)
    {
        if(sim->Part2Size() != 0 && sim->productSize() != 0){

            sim->dequePart2();
            product *temp;
            temp = sim->dequeproduct();

            calculateAssemblyTime(temp);
            sim->addtoFinalProduct();
        sim->setFinishingStatus(false);

        if(sim->Part2Size() != 0 && sim->productSize() != 0)
        {
            if(!sim->isFinishingBusy())
            {
                finishedproduct *asd = nullptr;
                asd = new finishedproduct(sim->getFrontProduct(), sim->getFrontPart2());
                Event *ee = new startAssembly(asd,getTime(),sim);
                sim->addEvent(ee);
            }
        }
    }
    }
}

void endAssembly::calculateAssemblyTime(product* temp)
{
    Parts* temp0;
    temp0 = temp->getPartP0();

    Parts* temp1;
    temp1 = temp->getPartP1();

    if(temp0->getarriveTime() < temp1->getarriveTime())
    {
        sim->TimeoffinalProduct(getTime() - temp0->getarriveTime());
    }else
    {
        sim->TimeoffinalProduct(getTime() - temp1->getarriveTime());
    }
}




//destructor
endAssembly::~endAssembly() {}
