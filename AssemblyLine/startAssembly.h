// CLASS: startAssembly.cpp
//
// Author: Zeelkumar Khokhariya, 7880619

//-----------------------------------------
#pragma once

#include "Event.h"
#include "product.h"
#include "finishedproduct.h"

class startAssembly : public Event
{
private:
    product* pp= nullptr;
    finishedproduct* fp= nullptr;

public:
    startAssembly(product* p,int time, Simulation* sim1);
    startAssembly(finishedproduct* p,int time, Simulation* sim1);
    void processEvent() override ;
    void print() override ;
    ~startAssembly();
};



